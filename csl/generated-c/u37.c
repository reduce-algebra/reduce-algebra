
/* $destdir\u37.c        Machine generated C code */

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


/* Code for simpsqrt3 */

static Lisp_Object CC_simpsqrt3(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsqrt3");
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
    v14 = stack[0];
    v13 = qvalue(elt(env, 1)); /* listofallsqrts */
    v13 = Lassoc(nil, v14, v13);
    stack[-1] = v13;
    v13 = stack[-1];
    if (v13 == nil) goto v16;
    v13 = stack[-1];
    v13 = qcdr(v13);
    { popv(3); return onevalue(v13); }

v16:
    v14 = qvalue(elt(env, 2)); /* listofnewsqrts */
    v13 = qvalue(elt(env, 3)); /* knowntobeindep */
    v13 = Latsoc(nil, v14, v13);
    stack[-1] = v13;
    v13 = stack[-1];
    if (v13 == nil) goto v17;
    v14 = stack[0];
    v13 = stack[-1];
    v13 = qcdr(v13);
    v13 = Lassoc(nil, v14, v13);
    stack[-1] = v13;
    v13 = stack[-1];
    if (v13 == nil) goto v17;
    v14 = stack[-1];
    v13 = qvalue(elt(env, 1)); /* listofallsqrts */
    v13 = cons(v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    qvalue(elt(env, 1)) = v13; /* listofallsqrts */
    v13 = stack[-1];
    v13 = qcdr(v13);
    { popv(3); return onevalue(v13); }

v17:
    v13 = stack[0];
    fn = elt(env, 4); /* actualsimpsqrt */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    stack[-1] = v13;
    v15 = stack[0];
    v14 = stack[-1];
    v13 = qvalue(elt(env, 1)); /* listofallsqrts */
    v13 = acons(v15, v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    qvalue(elt(env, 1)) = v13; /* listofallsqrts */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for rtrnda */

static Lisp_Object CC_rtrnda(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v30, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rtrnda");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v30 = v19;
    stack[0] = v0;
/* end of prologue */
    v29 = stack[0];
    if (!consp(v29)) goto v32;
    v29 = stack[0];
    v29 = qcdr(v29);
    v31 = qcar(v29);
    v29 = (Lisp_Object)1; /* 0 */
    v29 = (v31 == v29 ? lisp_true : nil);
    goto v33;

v33:
    if (v29 == nil) goto v34;
    v30 = (Lisp_Object)1; /* 0 */
    v29 = (Lisp_Object)1; /* 0 */
    v29 = cons(v30, v29);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    qvalue(elt(env, 1)) = v29; /* rlval!# */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v34:
    v29 = stack[0];
    fn = elt(env, 2); /* round!:dec1 */
    v29 = (*qfn2(fn))(qenv(fn), v29, v30);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    v30 = v29;
    qvalue(elt(env, 1)) = v30; /* rlval!# */
    v30 = qcar(v30);
    v29 = qcdr(v29);
    {
        popv(2);
        fn = elt(env, 3); /* decimal2internal */
        return (*qfn2(fn))(qenv(fn), v30, v29);
    }

v32:
    v29 = stack[0];
    v29 = (Lisp_Object)zerop(v29);
    v29 = v29 ? lisp_true : nil;
    env = stack[-1];
    goto v33;
/* error exit handlers */
v35:
    popv(2);
    return nil;
}



/* Code for !*s2i */

static Lisp_Object CC_Hs2i(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *s2i");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v0;
/* end of prologue */
    v38 = v39;
    v38 = integerp(v38);
    if (!(v38 == nil)) return onevalue(v39);
    v38 = elt(env, 1); /* "integer" */
    {
        fn = elt(env, 2); /* typerr */
        return (*qfn2(fn))(qenv(fn), v39, v38);
    }
}



/* Code for even_action_pow */

static Lisp_Object MS_CDECL CC_even_action_pow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v19,
                         Lisp_Object v3, Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v71, v72, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "even_action_pow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for even_action_pow");
#endif
    if (stack >= stacklimit)
    {
        push4(v40,v3,v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v19,v3,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v40;
    stack[-3] = v3;
    stack[-4] = v19;
    v73 = v0;
/* end of prologue */
    v70 = stack[-4];
    v70 = qcar(v70);
    v72 = v70;
    v70 = stack[-4];
    v70 = qcdr(v70);
    stack[-1] = v70;
    v71 = v72;
    v70 = v73;
    v70 = Lassoc(nil, v71, v70);
    stack[0] = v70;
    if (v70 == nil) goto v74;
    v71 = stack[-1];
    v70 = (Lisp_Object)17; /* 1 */
    if (v71 == v70) goto v8;
    stack[-4] = v72;
    v70 = stack[-1];
    v71 = sub1(v70);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-6];
    v70 = stack[-1];
    v72 = acons(stack[-4], v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-6];
    v71 = qvalue(elt(env, 1)); /* nil */
    v70 = (Lisp_Object)17; /* 1 */
    v70 = acons(v72, v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-6];
    goto v14;

v14:
    v72 = stack[0];
    v71 = stack[-3];
    fn = elt(env, 2); /* component_action */
    v70 = (*qfnn(fn))(qenv(fn), 3, v72, v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-6];
    stack[0] = v70;
    v71 = stack[0];
    v70 = stack[-2];
    {
        popv(7);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v71, v70);
    }

v8:
    v71 = (Lisp_Object)17; /* 1 */
    v70 = (Lisp_Object)17; /* 1 */
    v70 = cons(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-6];
    goto v14;

v74:
    v71 = v72;
    v72 = v73;
    v70 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* find_active_components */
    v70 = (*qfnn(fn))(qenv(fn), 3, v71, v72, v70);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-6];
    stack[-1] = v70;
    v71 = qvalue(elt(env, 1)); /* nil */
    v70 = (Lisp_Object)17; /* 1 */
    v70 = cons(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-6];
    stack[0] = v70;
    v70 = stack[-1];
    stack[-5] = v70;
    goto v76;

v76:
    v70 = stack[-5];
    if (v70 == nil) goto v77;
    v70 = stack[-5];
    v70 = qcar(v70);
    stack[-1] = v70;
    v71 = stack[-4];
    v70 = stack[-1];
    v70 = qcar(v70);
    fn = elt(env, 5); /* diffp */
    v70 = (*qfn2(fn))(qenv(fn), v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-6];
    v72 = stack[-1];
    v71 = stack[-3];
    fn = elt(env, 2); /* component_action */
    v70 = (*qfnn(fn))(qenv(fn), 3, v72, v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-6];
    fn = elt(env, 6); /* addsq */
    v70 = (*qfn2(fn))(qenv(fn), stack[0], v70);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-6];
    stack[0] = v70;
    v70 = stack[-5];
    v70 = qcdr(v70);
    stack[-5] = v70;
    goto v76;

v77:
    v71 = stack[0];
    v70 = stack[-2];
    {
        popv(7);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v71, v70);
    }
/* error exit handlers */
v75:
    popv(7);
    return nil;
}



/* Code for gd_gcasesimpl */

static Lisp_Object CC_gd_gcasesimpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v16;
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
    v39 = stack[0];
    stack[-1] = qcar(v39);
    v39 = stack[0];
    v39 = qcdr(v39);
    v39 = qcar(v39);
    fn = elt(env, 1); /* gd_simpl */
    v16 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v39 = stack[0];
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    v39 = qcar(v39);
    {
        Lisp_Object v78 = stack[-1];
        popv(2);
        return list3(v78, v16, v39);
    }
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for taymindegreel */

static Lisp_Object CC_taymindegreel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taymindegreel");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v19;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v67;

v67:
    v84 = stack[-2];
    if (v84 == nil) goto v32;
    v84 = stack[-2];
    v84 = qcar(v84);
    stack[0] = v84;
    v84 = (Lisp_Object)1; /* 0 */
    v85 = v84;
    goto v24;

v24:
    v84 = stack[0];
    if (v84 == nil) goto v34;
    v84 = stack[0];
    v84 = qcar(v84);
    fn = elt(env, 1); /* tayexp!-plus2 */
    v84 = (*qfn2(fn))(qenv(fn), v84, v85);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    v85 = v84;
    v84 = stack[0];
    v84 = qcdr(v84);
    stack[0] = v84;
    goto v24;

v34:
    v84 = v85;
    v85 = v84;
    v84 = stack[-1];
    v84 = qcar(v84);
    fn = elt(env, 2); /* tayexp!-min2 */
    v85 = (*qfn2(fn))(qenv(fn), v85, v84);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    v84 = stack[-3];
    v84 = cons(v85, v84);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    stack[-3] = v84;
    v84 = stack[-2];
    v84 = qcdr(v84);
    stack[-2] = v84;
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v67;

v32:
    v84 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v84);
    }
/* error exit handlers */
v4:
    popv(5);
    return nil;
}



/* Code for pasf_lnegrel */

static Lisp_Object CC_pasf_lnegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v90, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_lnegrel");
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
    v91 = v0;
/* end of prologue */
    v90 = v91;
    v89 = elt(env, 1); /* equal */
    if (v90 == v89) goto v92;
    v90 = v91;
    v89 = elt(env, 2); /* neq */
    if (v90 == v89) goto v93;
    v90 = v91;
    v89 = elt(env, 3); /* leq */
    if (v90 == v89) goto v28;
    v90 = v91;
    v89 = elt(env, 5); /* lessp */
    if (v90 == v89) goto v94;
    v90 = v91;
    v89 = elt(env, 6); /* geq */
    if (v90 == v89) goto v23;
    v90 = v91;
    v89 = elt(env, 4); /* greaterp */
    if (v90 == v89) goto v5;
    v90 = v91;
    v89 = elt(env, 7); /* cong */
    if (v90 == v89) goto v95;
    v90 = v91;
    v89 = elt(env, 8); /* ncong */
    if (v90 == v89) goto v15;
    v89 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v89 == nil)) goto v58;
    v89 = elt(env, 10); /* "pasf_lnegrel: unknown operator" */
    v90 = v91;
    v89 = list2(v89, v90);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[0];
    fn = elt(env, 11); /* lprie */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[0];
    goto v58;

v58:
    v89 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    v89 = nil;
    { popv(1); return onevalue(v89); }

v15:
    v89 = elt(env, 7); /* cong */
    { popv(1); return onevalue(v89); }

v95:
    v89 = elt(env, 8); /* ncong */
    { popv(1); return onevalue(v89); }

v5:
    v89 = elt(env, 3); /* leq */
    { popv(1); return onevalue(v89); }

v23:
    v89 = elt(env, 5); /* lessp */
    { popv(1); return onevalue(v89); }

v94:
    v89 = elt(env, 6); /* geq */
    { popv(1); return onevalue(v89); }

v28:
    v89 = elt(env, 4); /* greaterp */
    { popv(1); return onevalue(v89); }

v93:
    v89 = elt(env, 1); /* equal */
    { popv(1); return onevalue(v89); }

v92:
    v89 = elt(env, 2); /* neq */
    { popv(1); return onevalue(v89); }
/* error exit handlers */
v96:
    popv(1);
    return nil;
}



/* Code for dvfsf_smcpknowl */

static Lisp_Object CC_dvfsf_smcpknowl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_smcpknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v93 = v0;
/* end of prologue */
    v97 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v97 == nil) goto v32;
    v97 = v93;
    {
        fn = elt(env, 2); /* cl_susicpknowl */
        return (*qfn1(fn))(qenv(fn), v97);
    }

v32:
    v97 = v93;
    {
        fn = elt(env, 3); /* cl_smcpknowl */
        return (*qfn1(fn))(qenv(fn), v97);
    }
}



/* Code for symbolsrd */

static Lisp_Object MS_CDECL CC_symbolsrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "symbolsrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbolsrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* end of prologue */
    stack[-4] = nil;
    fn = elt(env, 9); /* lex */
    v108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    v109 = qvalue(elt(env, 2)); /* char */
    v108 = elt(env, 3); /* (b v a r) */
    if (equal(v109, v108)) goto v38;
    v109 = elt(env, 5); /* "<bvar>" */
    v108 = (Lisp_Object)225; /* 14 */
    fn = elt(env, 10); /* errorml */
    v108 = (*qfn2(fn))(qenv(fn), v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v1;

v1:
    v109 = qvalue(elt(env, 2)); /* char */
    v108 = elt(env, 6); /* (l o w l i m i t) */
    if (equal(v109, v108)) goto v65;
    v108 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v108;
    goto v112;

v112:
    v109 = qvalue(elt(env, 2)); /* char */
    v108 = elt(env, 7); /* (i n t e r v a l) */
    if (equal(v109, v108)) goto v113;
    v108 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v108;
    goto v56;

v56:
    v109 = qvalue(elt(env, 2)); /* char */
    v108 = elt(env, 8); /* (c o n d i t i o n) */
    if (equal(v109, v108)) goto v57;
    v108 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v108;
    goto v114;

v114:
    fn = elt(env, 11); /* mathml2 */
    v108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    stack[-1] = v108;
    fn = elt(env, 9); /* lex */
    v108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    v108 = stack[-3];
    if (v108 == nil) goto v115;
    v110 = stack[-4];
    v109 = stack[-3];
    v108 = stack[-1];
    popv(6);
    return list3(v110, v109, v108);

v115:
    v108 = stack[-2];
    if (v108 == nil) goto v50;
    v110 = stack[-4];
    v109 = stack[-2];
    v108 = stack[-1];
    popv(6);
    return list3(v110, v109, v108);

v50:
    v108 = stack[0];
    if (v108 == nil) goto v73;
    v110 = stack[-4];
    v109 = stack[0];
    v108 = stack[-1];
    popv(6);
    return list3(v110, v109, v108);

v73:
    v109 = stack[-4];
    v110 = qvalue(elt(env, 1)); /* nil */
    v108 = stack[-1];
    popv(6);
    return list3(v109, v110, v108);

v57:
    fn = elt(env, 12); /* conditionrd */
    v108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    stack[0] = v108;
    fn = elt(env, 9); /* lex */
    v108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v114;

v113:
    fn = elt(env, 13); /* intervalrd */
    v108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    stack[-2] = v108;
    fn = elt(env, 9); /* lex */
    v108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v56;

v65:
    fn = elt(env, 14); /* lowupperlimitrd */
    v108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    stack[-3] = v108;
    fn = elt(env, 9); /* lex */
    v108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v112;

v38:
    fn = elt(env, 15); /* bvarrd */
    v108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    stack[-4] = v108;
    v108 = stack[-4];
    v108 = qcdr(v108);
    v108 = qcdr(v108);
    v109 = qcar(v108);
    v108 = (Lisp_Object)17; /* 1 */
    if (v109 == v108) goto v88;
    v109 = elt(env, 4); /* "" */
    v108 = (Lisp_Object)209; /* 13 */
    fn = elt(env, 10); /* errorml */
    v108 = (*qfn2(fn))(qenv(fn), v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v80;

v80:
    fn = elt(env, 9); /* lex */
    v108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v1;

v88:
    v108 = stack[-4];
    stack[-4] = v108;
    goto v80;
/* error exit handlers */
v111:
    popv(6);
    return nil;
}



/* Code for transferrow1 */

static Lisp_Object CC_transferrow1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transferrow1");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v6 = qvalue(elt(env, 2)); /* maxvar */
    v5 = stack[0];
    v5 = plus2(v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v6 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v5/(16/CELL)));
    v5 = (Lisp_Object)81; /* 5 */
    v5 = *(Lisp_Object *)((char *)v6 + (CELL-TAG_VECTOR) + ((int32_t)v5/(16/CELL)));
    if (v5 == nil) goto v25;
    v5 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v5); }

v25:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v6 = qvalue(elt(env, 2)); /* maxvar */
    v5 = stack[0];
    v5 = plus2(v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v31;
    v6 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v5/(16/CELL)));
    v5 = (Lisp_Object)49; /* 3 */
    v5 = *(Lisp_Object *)((char *)v6 + (CELL-TAG_VECTOR) + ((int32_t)v5/(16/CELL)));
    v5 = (is_number(v5) ? lisp_true : nil);
    { popv(3); return onevalue(v5); }
/* error exit handlers */
v31:
    popv(3);
    return nil;
}



/* Code for termorder1 */

static Lisp_Object CC_termorder1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v95;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termorder1");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v19;
    stack[-1] = v0;
/* end of prologue */

v17:
    v85 = stack[-1];
    if (v85 == nil) goto v33;
    v85 = stack[-1];
    v85 = (Lisp_Object)zerop(v85);
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (v85 == nil) goto v97;
    v85 = stack[0];
    v85 = (Lisp_Object)zerop(v85);
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (v85 == nil) goto v97;
    v85 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v85); }

v97:
    v85 = stack[-1];
    v85 = (Lisp_Object)zerop(v85);
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (v85 == nil) goto v79;
    v85 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v85); }

v79:
    v85 = stack[0];
    v85 = (Lisp_Object)zerop(v85);
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (v85 == nil) goto v94;
    v85 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v85); }

v94:
    v85 = stack[-1];
    v95 = qcar(v85);
    v85 = stack[0];
    v85 = qcar(v85);
    v85 = (Lisp_Object)lessp2(v95, v85);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (v85 == nil) goto v69;
    v85 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v85); }

v69:
    v85 = stack[-1];
    v95 = qcar(v85);
    v85 = stack[0];
    v85 = qcar(v85);
    v85 = (Lisp_Object)greaterp2(v95, v85);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v85 = v85 ? lisp_true : nil;
    env = stack[-2];
    if (v85 == nil) goto v30;
    v85 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v85); }

v30:
    v85 = stack[-1];
    v85 = qcdr(v85);
    stack[-1] = v85;
    v85 = stack[0];
    v85 = qcdr(v85);
    stack[0] = v85;
    goto v17;

v33:
    v85 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v85); }
/* error exit handlers */
v65:
    popv(3);
    return nil;
}



/* Code for xexptpf */

static Lisp_Object CC_xexptpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xexptpf");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v19;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v93;

v93:
    v120 = stack[0];
    v119 = (Lisp_Object)17; /* 1 */
    if (v120 == v119) goto v33;
    v120 = stack[-1];
    v119 = stack[-2];
    v119 = cons(v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    stack[-2] = v119;
    v119 = stack[0];
    v119 = sub1(v119);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    stack[0] = v119;
    goto v93;

v33:
    v119 = stack[-1];
    v120 = v119;
    goto v32;

v32:
    v119 = stack[-2];
    if (v119 == nil) { popv(4); return onevalue(v120); }
    v119 = stack[-2];
    v119 = qcar(v119);
    fn = elt(env, 1); /* wedgepf */
    v119 = (*qfn2(fn))(qenv(fn), v119, v120);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    v120 = v119;
    v119 = stack[-2];
    v119 = qcdr(v119);
    stack[-2] = v119;
    goto v32;
/* error exit handlers */
v5:
    popv(4);
    return nil;
}



/* Code for adjp */

static Lisp_Object CC_adjp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v56;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adjp");
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
    v56 = stack[-1];
    v55 = elt(env, 1); /* unit */
    if (v56 == v55) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v55 = stack[-1];
    if (!consp(v55)) goto v37;
    v55 = stack[-1];
    v56 = qcar(v55);
    v55 = elt(env, 3); /* comm */
    if (v56 == v55) goto v124;
    v55 = stack[-1];
    v56 = qcar(v55);
    v55 = elt(env, 4); /* anticomm */
    if (v56 == v55) goto v95;
    v55 = stack[-1];
    v56 = qcar(v55);
    v55 = elt(env, 2); /* adjoint */
    v56 = get(v56, v55);
    v55 = stack[-1];
    v55 = qcdr(v55);
    popv(4);
    return cons(v56, v55);

v95:
    stack[-2] = elt(env, 4); /* anticomm */
    v55 = stack[-1];
    v55 = qcdr(v55);
    v55 = qcar(v55);
    stack[0] = CC_adjp(env, v55);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-3];
    v55 = stack[-1];
    v55 = qcdr(v55);
    v55 = qcdr(v55);
    v55 = qcar(v55);
    v55 = CC_adjp(env, v55);
    nil = C_nil;
    if (exception_pending()) goto v91;
    {
        Lisp_Object v96 = stack[-2];
        Lisp_Object v105 = stack[0];
        popv(4);
        return list3(v96, v105, v55);
    }

v124:
    stack[-2] = elt(env, 3); /* comm */
    v55 = stack[-1];
    v55 = qcdr(v55);
    v55 = qcdr(v55);
    v55 = qcar(v55);
    stack[0] = CC_adjp(env, v55);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-3];
    v55 = stack[-1];
    v55 = qcdr(v55);
    v55 = qcar(v55);
    v55 = CC_adjp(env, v55);
    nil = C_nil;
    if (exception_pending()) goto v91;
    {
        Lisp_Object v52 = stack[-2];
        Lisp_Object v53 = stack[0];
        popv(4);
        return list3(v52, v53, v55);
    }

v37:
    v55 = stack[-1];
    v56 = elt(env, 2); /* adjoint */
    popv(4);
    return get(v55, v56);
/* error exit handlers */
v91:
    popv(4);
    return nil;
}



/* Code for mk_parents_prim */

static Lisp_Object CC_mk_parents_prim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_parents_prim");
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
    v34 = stack[0];
    v7 = Llength(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-1];
    v34 = (Lisp_Object)49; /* 3 */
    if (!(v7 == v34)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v34 = stack[0];
    fn = elt(env, 1); /* s_noparents */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-1];
    v7 = v34;
    if (v7 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v7 = stack[0];
    v34 = qcar(v34);
    fn = elt(env, 2); /* mk_edge_parents */
    v34 = (*qfn2(fn))(qenv(fn), v7, v34);
    nil = C_nil;
    if (exception_pending()) goto v8;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v8:
    popv(2);
    return nil;
}



/* Code for simp!-prop */

static Lisp_Object CC_simpKprop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v145, v146;
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
    v144 = stack[-2];
    v144 = qcdr(v144);
    stack[-4] = v144;
    v144 = stack[-4];
    if (v144 == nil) goto v36;
    v144 = stack[-4];
    v144 = qcar(v144);
    fn = elt(env, 14); /* reval */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    stack[-1] = v144;
    stack[-3] = v144;
    goto v12;

v12:
    v144 = stack[-4];
    v144 = qcdr(v144);
    stack[-4] = v144;
    v144 = stack[-4];
    if (v144 == nil) goto v88;
    stack[0] = stack[-1];
    v144 = stack[-4];
    v144 = qcar(v144);
    fn = elt(env, 14); /* reval */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v144 = Lrplacd(nil, stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v144 = stack[-1];
    v144 = qcdr(v144);
    stack[-1] = v144;
    goto v12;

v88:
    v144 = stack[-3];
    goto v11;

v11:
    stack[-5] = v144;
    v145 = elt(env, 3); /* and */
    v144 = stack[-5];
    v144 = Lmember(nil, v145, v144);
    if (v144 == nil) goto v65;
    v144 = elt(env, 4); /* or */
    qvalue(elt(env, 5)) = v144; /* !'and */
    v144 = elt(env, 3); /* and */
    qvalue(elt(env, 6)) = v144; /* !'or */
    v144 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v144; /* !'true */
    v144 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 8)) = v144; /* !'false */
    goto v18;

v18:
    v144 = stack[-2];
    v145 = qcar(v144);
    v144 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 15); /* simp!-prop1 */
    v144 = (*qfn2(fn))(qenv(fn), v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    fn = elt(env, 16); /* prepf */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    fn = elt(env, 14); /* reval */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v146 = v144;
    v145 = v146;
    v144 = (Lisp_Object)1; /* 0 */
    if (v145 == v144) goto v148;
    v144 = qvalue(elt(env, 1)); /* propvars!* */
    stack[-4] = v144;
    goto v56;

v56:
    v144 = stack[-4];
    if (v144 == nil) goto v55;
    v144 = stack[-4];
    v144 = qcar(v144);
    stack[-3] = elt(env, 10); /* times */
    stack[-2] = v146;
    stack[-1] = qvalue(elt(env, 6)); /* !'or */
    stack[0] = v144;
    v145 = elt(env, 11); /* not */
    v144 = list2(v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v145 = list3(stack[-1], stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v144 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 15); /* simp!-prop1 */
    v144 = (*qfn2(fn))(qenv(fn), v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    fn = elt(env, 16); /* prepf */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v144 = list3(stack[-3], stack[-2], v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    fn = elt(env, 14); /* reval */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v146 = v144;
    v144 = stack[-4];
    v144 = qcdr(v144);
    stack[-4] = v144;
    goto v56;

v55:
    v144 = v146;
    fn = elt(env, 17); /* simp!-prop!-dist */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v146 = v144;
    v145 = elt(env, 12); /* full */
    v144 = stack[-5];
    v144 = Lmember(nil, v145, v144);
    if (!(v144 == nil)) goto v77;
    v144 = v146;
    fn = elt(env, 18); /* simp!-prop2 */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v146 = v144;
    goto v77;

v77:
    v144 = v146;
    fn = elt(env, 19); /* simp!-prop!-form */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v146 = v144;
    v144 = v146;
    if (is_number(v144)) goto v109;
    v144 = v146;
    if (!consp(v144)) goto v149;
    v144 = elt(env, 13); /* boolean */
    v145 = v146;
    v144 = list2(v144, v145);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v146 = v144;
    goto v149;

v149:
    v145 = (Lisp_Object)17; /* 1 */
    v144 = (Lisp_Object)17; /* 1 */
    v146 = acons(v146, v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    v145 = qvalue(elt(env, 2)); /* nil */
    v144 = (Lisp_Object)17; /* 1 */
    v144 = acons(v146, v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    goto v67;

v67:
    qvalue(elt(env, 1)) = stack[-6]; /* propvars!* */
    { popv(8); return onevalue(v144); }

v109:
    v145 = v146;
    v144 = (Lisp_Object)17; /* 1 */
    v144 = cons(v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    goto v67;

v148:
    v144 = qvalue(elt(env, 8)); /* !'false */
    fn = elt(env, 20); /* simp */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-7];
    goto v67;

v65:
    v144 = elt(env, 3); /* and */
    qvalue(elt(env, 5)) = v144; /* !'and */
    v144 = elt(env, 4); /* or */
    qvalue(elt(env, 6)) = v144; /* !'or */
    v144 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 7)) = v144; /* !'true */
    v144 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 8)) = v144; /* !'false */
    goto v18;

v36:
    v144 = qvalue(elt(env, 2)); /* nil */
    goto v11;
/* error exit handlers */
v147:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* propvars!* */
    popv(8);
    return nil;
}



/* Code for njets */

static Lisp_Object CC_njets(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for njets");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v38 = v19;
    v39 = v0;
/* end of prologue */
    stack[-1] = v38;
    stack[0] = v38;
    v38 = v39;
    v38 = sub1(v38);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v38 = plus2(stack[0], v38);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    {
        Lisp_Object v28 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* combin */
        return (*qfn2(fn))(qenv(fn), v28, v38);
    }
/* error exit handlers */
v27:
    popv(3);
    return nil;
}



/* Code for mkrootsq */

static Lisp_Object CC_mkrootsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v168, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkrootsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v19;
    stack[-1] = v0;
/* end of prologue */
    v168 = stack[-1];
    v167 = (Lisp_Object)17; /* 1 */
    if (v168 == v167) goto v17;
    v168 = stack[0];
    v167 = (Lisp_Object)33; /* 2 */
    if (v168 == v167) goto v25;
    v167 = qvalue(elt(env, 3)); /* nil */
    goto v38;

v38:
    if (v167 == nil) goto v85;
    v167 = elt(env, 4); /* i */
    {
        popv(4);
        fn = elt(env, 10); /* simp */
        return (*qfn1(fn))(qenv(fn), v167);
    }

v85:
    v168 = stack[-1];
    v167 = elt(env, 5); /* expt */
    if (!consp(v168)) goto v142;
    v168 = qcar(v168);
    if (!(v168 == v167)) goto v142;
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v167 = integerp(v167);
    if (v167 == nil) goto v13;
    v167 = qvalue(elt(env, 6)); /* !*precise_complex */
    v167 = (v167 == nil ? lisp_true : nil);
    goto v143;

v143:
    if (v167 == nil) goto v105;
    v167 = stack[-1];
    v167 = qcdr(v167);
    v168 = qcar(v167);
    v167 = stack[0];
    v168 = CC_mkrootsq(env, v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-3];
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    {
        popv(4);
        fn = elt(env, 11); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v168, v167);
    }

v105:
    stack[-2] = nil;
    v167 = stack[-1];
    v167 = integerp(v167);
    if (v167 == nil) goto v111;
    v167 = stack[-1];
    v167 = Lminusp(nil, v167);
    env = stack[-3];
    if (v167 == nil) goto v137;
    v167 = qvalue(elt(env, 3)); /* nil */
    goto v135;

v135:
    if (v167 == nil) goto v111;
    v168 = stack[-2];
    v167 = stack[0];
    {
        popv(4);
        fn = elt(env, 12); /* mkrootsql */
        return (*qfn2(fn))(qenv(fn), v168, v167);
    }

v111:
    v168 = stack[0];
    v167 = (Lisp_Object)33; /* 2 */
    if (v168 == v167) goto v133;
    stack[-2] = elt(env, 5); /* expt */
    v169 = elt(env, 9); /* quotient */
    v168 = (Lisp_Object)17; /* 1 */
    v167 = stack[0];
    v167 = list3(v169, v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-3];
    v167 = list3(stack[-2], stack[-1], v167);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-3];
    goto v171;

v171:
    stack[-2] = v167;
    v167 = stack[-2];
    fn = elt(env, 13); /* opmtch */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-3];
    v168 = v167;
    if (v167 == nil) goto v172;
    v167 = v168;
    {
        popv(4);
        fn = elt(env, 10); /* simp */
        return (*qfn1(fn))(qenv(fn), v167);
    }

v172:
    v168 = stack[-2];
    v167 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 14); /* mksq */
        return (*qfn2(fn))(qenv(fn), v168, v167);
    }

v133:
    v167 = stack[-1];
    fn = elt(env, 15); /* mksqrt */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-3];
    goto v171;

v137:
    stack[-2] = stack[-1];
    v168 = stack[-1];
    v167 = qvalue(elt(env, 7)); /* factorbound!* */
    v167 = (Lisp_Object)lessp2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v167 = v167 ? lisp_true : nil;
    env = stack[-3];
    if (!(v167 == nil)) goto v173;
    v167 = qvalue(elt(env, 8)); /* !*ifactor */
    goto v173;

v173:
    fn = elt(env, 16); /* zfactor1 */
    v167 = (*qfn2(fn))(qenv(fn), stack[-2], v167);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-3];
    stack[-2] = v167;
    v168 = Llength(nil, v167);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-3];
    v167 = (Lisp_Object)17; /* 1 */
    v167 = (Lisp_Object)greaterp2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v167 = v167 ? lisp_true : nil;
    env = stack[-3];
    if (!(v167 == nil)) goto v135;
    v167 = stack[-2];
    v167 = qcar(v167);
    v168 = qcdr(v167);
    v167 = (Lisp_Object)17; /* 1 */
    v167 = (Lisp_Object)greaterp2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v167 = v167 ? lisp_true : nil;
    env = stack[-3];
    goto v135;

v13:
    v167 = qvalue(elt(env, 3)); /* nil */
    goto v143;

v142:
    v167 = qvalue(elt(env, 3)); /* nil */
    goto v143;

v25:
    v168 = stack[-1];
    v167 = (Lisp_Object)-15; /* -1 */
    if (v168 == v167) goto v88;
    v168 = stack[-1];
    v167 = elt(env, 2); /* (minus 1) */
    v167 = (equal(v168, v167) ? lisp_true : nil);
    goto v38;

v88:
    v167 = qvalue(elt(env, 1)); /* t */
    goto v38;

v17:
    v167 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 17); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v167);
    }
/* error exit handlers */
v170:
    popv(4);
    return nil;
}



/* Code for update_components */

static Lisp_Object MS_CDECL CC_update_components(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v19,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6, v29, v30;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "update_components");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for update_components");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v19,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v29 = v3;
    stack[0] = v19;
    v5 = v0;
/* end of prologue */
    stack[-1] = v5;
    goto v54;

v54:
    v5 = stack[-1];
    if (v5 == nil) { popv(3); return onevalue(v29); }
    v5 = stack[-1];
    v5 = qcar(v5);
    v6 = v5;
    v30 = v6;
    v5 = stack[0];
    v5 = Lassoc(nil, v30, v5);
    v30 = v5;
    if (v5 == nil) goto v79;
    v5 = v29;
    v5 = Lassoc(nil, v6, v5);
    if (!(v5 == nil)) goto v79;
    v5 = v30;
    v6 = v29;
    v5 = cons(v5, v6);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    v29 = v5;
    goto v79;

v79:
    v5 = stack[-1];
    v5 = qcdr(v5);
    stack[-1] = v5;
    goto v54;
/* error exit handlers */
v35:
    popv(3);
    return nil;
}



/* Code for !*multsq */

static Lisp_Object CC_Hmultsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *multsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v19;
    stack[-3] = v0;
/* end of prologue */
    v149 = stack[-3];
    v149 = qcar(v149);
    if (v149 == nil) goto v32;
    v149 = stack[-2];
    v149 = qcar(v149);
    v149 = (v149 == nil ? lisp_true : nil);
    goto v33;

v33:
    if (v149 == nil) goto v25;
    v186 = qvalue(elt(env, 2)); /* nil */
    v149 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v186, v149);

v25:
    v149 = stack[-3];
    v186 = qcdr(v149);
    v149 = (Lisp_Object)17; /* 1 */
    if (v186 == v149) goto v8;
    v149 = qvalue(elt(env, 2)); /* nil */
    goto v80;

v80:
    if (v149 == nil) goto v187;
    v149 = stack[-3];
    v186 = qcar(v149);
    v149 = stack[-2];
    v149 = qcar(v149);
    fn = elt(env, 3); /* !*multf */
    v186 = (*qfn2(fn))(qenv(fn), v186, v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    v149 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v186, v149);

v187:
    v149 = stack[-3];
    v186 = qcar(v149);
    v149 = stack[-2];
    v149 = qcdr(v149);
    fn = elt(env, 4); /* gcdf */
    v149 = (*qfn2(fn))(qenv(fn), v186, v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    stack[-4] = v149;
    v149 = stack[-2];
    v186 = qcar(v149);
    v149 = stack[-3];
    v149 = qcdr(v149);
    fn = elt(env, 4); /* gcdf */
    v149 = (*qfn2(fn))(qenv(fn), v186, v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    stack[-1] = v149;
    v149 = stack[-3];
    v186 = qcar(v149);
    v149 = stack[-4];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v186, v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    v149 = stack[-2];
    v186 = qcar(v149);
    v149 = stack[-1];
    fn = elt(env, 5); /* quotf */
    v149 = (*qfn2(fn))(qenv(fn), v186, v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    fn = elt(env, 3); /* !*multf */
    v149 = (*qfn2(fn))(qenv(fn), stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    stack[0] = v149;
    v149 = stack[-3];
    v186 = qcdr(v149);
    v149 = stack[-1];
    fn = elt(env, 5); /* quotf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v186, v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    v149 = stack[-2];
    v186 = qcdr(v149);
    v149 = stack[-4];
    fn = elt(env, 5); /* quotf */
    v149 = (*qfn2(fn))(qenv(fn), v186, v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    fn = elt(env, 3); /* !*multf */
    v149 = (*qfn2(fn))(qenv(fn), stack[-1], v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    stack[-4] = v149;
    v149 = stack[-4];
    fn = elt(env, 6); /* minusf */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    if (v149 == nil) goto v162;
    v149 = stack[0];
    fn = elt(env, 7); /* negf */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    stack[0] = v149;
    v149 = stack[-4];
    fn = elt(env, 7); /* negf */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    stack[-4] = v149;
    goto v162;

v162:
    v186 = stack[0];
    v149 = stack[-4];
    fn = elt(env, 4); /* gcdf */
    v149 = (*qfn2(fn))(qenv(fn), v186, v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    stack[-1] = v149;
    v186 = stack[-1];
    v149 = (Lisp_Object)17; /* 1 */
    if (v186 == v149) goto v109;
    v186 = stack[0];
    v149 = stack[-1];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v186, v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    v186 = stack[-4];
    v149 = stack[-1];
    fn = elt(env, 5); /* quotf */
    v149 = (*qfn2(fn))(qenv(fn), v186, v149);
    nil = C_nil;
    if (exception_pending()) goto v129;
    {
        Lisp_Object v125 = stack[0];
        popv(6);
        return cons(v125, v149);
    }

v109:
    v186 = stack[0];
    v149 = stack[-4];
    popv(6);
    return cons(v186, v149);

v8:
    v149 = stack[-2];
    v186 = qcdr(v149);
    v149 = (Lisp_Object)17; /* 1 */
    v149 = (v186 == v149 ? lisp_true : nil);
    goto v80;

v32:
    v149 = qvalue(elt(env, 1)); /* t */
    goto v33;
/* error exit handlers */
v129:
    popv(6);
    return nil;
}



/* Code for ratpoly_red */

static Lisp_Object CC_ratpoly_red(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_red");
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
    v97 = stack[0];
    v97 = qcar(v97);
    fn = elt(env, 1); /* numpoly_red */
    v93 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v117;
    v97 = stack[0];
    v97 = qcdr(v97);
    popv(1);
    return cons(v93, v97);
/* error exit handlers */
v117:
    popv(1);
    return nil;
}



/* Code for bc_2a */

static Lisp_Object CC_bc_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v92 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* prepf */
        return (*qfn1(fn))(qenv(fn), v92);
    }
}



/* Code for matrixrd */

static Lisp_Object MS_CDECL CC_matrixrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrd");
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
    v185 = (Lisp_Object)1; /* 0 */
    stack[-1] = v185;
    v185 = nil;
    stack[0] = v185;
    goto v117;

v117:
    v148 = stack[-1];
    v185 = (Lisp_Object)1; /* 0 */
    if (v148 == v185) goto v97;
    v148 = elt(env, 6); /* mat */
    v185 = stack[0];
    v185 = cons(v148, v185);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* aeval */
        return (*qfn1(fn))(qenv(fn), v185);
    }

v97:
    fn = elt(env, 8); /* lex */
    v185 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v148 = qvalue(elt(env, 2)); /* char */
    v185 = elt(env, 3); /* (m a t r i x r o w) */
    if (equal(v148, v185)) goto v10;
    v185 = (Lisp_Object)17; /* 1 */
    stack[-1] = v185;
    goto v117;

v10:
    fn = elt(env, 9); /* matrixrowrd */
    v185 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v148 = v185;
    v185 = stack[0];
    if (v185 == nil) goto v81;
    v185 = v148;
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v185 = Lappend(nil, stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    stack[0] = v185;
    goto v143;

v143:
    v148 = qvalue(elt(env, 2)); /* char */
    v185 = elt(env, 4); /* (!/ m a t r i x r o w) */
    if (equal(v148, v185)) goto v117;
    v148 = elt(env, 5); /* "</matrixrow>" */
    v185 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 10); /* errorml */
    v185 = (*qfn2(fn))(qenv(fn), v148, v185);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    goto v117;

v81:
    v185 = v148;
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    stack[0] = v185;
    goto v143;
/* error exit handlers */
v59:
    popv(3);
    return nil;
}



/* Code for ldf!-sep!-var */

static Lisp_Object CC_ldfKsepKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-sep-var");
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
    v39 = stack[0];
    fn = elt(env, 1); /* ldf!-pow!-var */
    stack[-1] = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v39 = stack[0];
    fn = elt(env, 2); /* ldf!-dep!-var */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    fn = elt(env, 3); /* compl */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v39);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v39 = stack[0];
    fn = elt(env, 4); /* ldf!-spf!-var */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    {
        Lisp_Object v28 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* compl */
        return (*qfn2(fn))(qenv(fn), v28, v39);
    }
/* error exit handlers */
v27:
    popv(3);
    return nil;
}



/* Code for addns */

static Lisp_Object CC_addns(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v105, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addns");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v19;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v67;

v67:
    v96 = stack[0];
    if (v96 == nil) goto v97;
    v96 = stack[-1];
    v105 = qcdr(v96);
    v96 = stack[0];
    v96 = qcar(v96);
    v96 = qcdr(v96);
    if (equal(v105, v96)) goto v8;
    v96 = stack[-1];
    v105 = qcdr(v96);
    v96 = stack[0];
    v96 = qcar(v96);
    v96 = qcdr(v96);
    fn = elt(env, 1); /* ordp */
    v96 = (*qfn2(fn))(qenv(fn), v105, v96);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-3];
    if (v96 == nil) goto v121;
    v105 = stack[-1];
    v96 = stack[0];
    v96 = cons(v105, v96);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-3];
    {
        Lisp_Object v76 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v76, v96);
    }

v121:
    v96 = stack[0];
    v105 = qcar(v96);
    v96 = stack[-2];
    v96 = cons(v105, v96);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-3];
    stack[-2] = v96;
    v96 = stack[0];
    v96 = qcdr(v96);
    stack[0] = v96;
    goto v67;

v8:
    v96 = stack[-1];
    v105 = qcar(v96);
    v96 = stack[0];
    v96 = qcar(v96);
    v96 = qcar(v96);
    fn = elt(env, 3); /* addsq */
    v96 = (*qfn2(fn))(qenv(fn), v105, v96);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-3];
    v52 = v96;
    v96 = stack[-1];
    v105 = qcdr(v96);
    v96 = stack[0];
    v96 = qcdr(v96);
    v96 = acons(v52, v105, v96);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-3];
    {
        Lisp_Object v190 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v190, v96);
    }

v97:
    stack[0] = stack[-2];
    v96 = stack[-1];
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-3];
    {
        Lisp_Object v191 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v191, v96);
    }
/* error exit handlers */
v182:
    popv(4);
    return nil;
}



/* Code for mkprec */

static Lisp_Object MS_CDECL CC_mkprec(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v115, v192;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkprec");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprec");
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
    v115 = qvalue(elt(env, 1)); /* fixedpreclis!* */
    v191 = qvalue(elt(env, 2)); /* preclis!* */
    v191 = Lappend(nil, v115, v191);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    stack[-3] = v191;
    v191 = (Lisp_Object)17; /* 1 */
    stack[-2] = v191;
    goto v67;

v67:
    v191 = stack[-3];
    if (v191 == nil) goto v37;
    v191 = stack[-3];
    v192 = qcar(v191);
    v115 = elt(env, 4); /* infix */
    v191 = stack[-2];
    v191 = Lputprop(nil, 3, v192, v115, v191);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v191 = stack[-3];
    stack[-1] = qcar(v191);
    stack[0] = elt(env, 5); /* op */
    v115 = stack[-2];
    v191 = stack[-2];
    v191 = list2(v115, v191);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v191 = Lputprop(nil, 3, stack[-1], stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v191 = stack[-3];
    v115 = qcar(v191);
    v191 = elt(env, 6); /* unary */
    v191 = get(v115, v191);
    env = stack[-4];
    stack[0] = v191;
    if (v191 == nil) goto v6;
    v192 = stack[0];
    v115 = elt(env, 4); /* infix */
    v191 = stack[-2];
    v191 = Lputprop(nil, 3, v192, v115, v191);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    goto v6;

v6:
    v191 = stack[0];
    if (v191 == nil) goto v193;
    v115 = stack[0];
    v191 = elt(env, 7); /* nary */
    v191 = Lflagp(nil, v115, v191);
    env = stack[-4];
    if (!(v191 == nil)) goto v193;
    stack[-1] = stack[0];
    stack[0] = elt(env, 5); /* op */
    v115 = qvalue(elt(env, 3)); /* nil */
    v191 = stack[-2];
    v191 = list2(v115, v191);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v191 = Lputprop(nil, 3, stack[-1], stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    goto v193;

v193:
    v191 = stack[-3];
    v191 = qcdr(v191);
    stack[-3] = v191;
    v191 = stack[-2];
    v191 = add1(v191);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    stack[-2] = v191;
    goto v67;

v37:
    v191 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v191); }
/* error exit handlers */
v135:
    popv(5);
    return nil;
}



/* Code for xquotient!-mod!-p */

static Lisp_Object MS_CDECL CC_xquotientKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v19,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v149, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xquotient-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xquotient-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v19,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v19;
    stack[-2] = v0;
/* end of prologue */
    v177 = stack[-2];
    if (v177 == nil) goto v67;
    v177 = stack[-2];
    if (!consp(v177)) goto v37;
    v177 = stack[-2];
    v177 = qcar(v177);
    v177 = (consp(v177) ? nil : lisp_true);
    goto v36;

v36:
    if (v177 == nil) goto v94;
    v177 = qvalue(elt(env, 2)); /* t */
    goto v97;

v97:
    if (v177 == nil) goto v95;
    v177 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v177; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v177); }

v95:
    v177 = stack[-2];
    v177 = qcar(v177);
    v177 = qcar(v177);
    v149 = qcdr(v177);
    v177 = stack[-1];
    v177 = qcar(v177);
    v177 = qcar(v177);
    v177 = qcdr(v177);
    if (equal(v149, v177)) goto v60;
    v177 = stack[-2];
    v177 = qcar(v177);
    v177 = qcar(v177);
    v177 = qcar(v177);
    fn = elt(env, 4); /* fkern */
    v186 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    v177 = stack[-2];
    v177 = qcar(v177);
    v177 = qcar(v177);
    v149 = qcdr(v177);
    v177 = stack[-1];
    v177 = qcar(v177);
    v177 = qcar(v177);
    v177 = qcdr(v177);
    v177 = (Lisp_Object)(int32_t)((int32_t)v149 - (int32_t)v177 + TAG_FIXNUM);
    fn = elt(env, 5); /* getpower */
    stack[-3] = (*qfn2(fn))(qenv(fn), v186, v177);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    v177 = stack[-2];
    v177 = qcar(v177);
    v149 = qcdr(v177);
    v177 = stack[-1];
    v177 = qcar(v177);
    v177 = qcdr(v177);
    fn = elt(env, 6); /* quotient!-mod!-p */
    v177 = (*qfn2(fn))(qenv(fn), v149, v177);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    v177 = cons(stack[-3], v177);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    stack[-3] = v177;
    v177 = stack[-2];
    stack[-2] = qcdr(v177);
    v177 = stack[-3];
    fn = elt(env, 7); /* negate!-term */
    v149 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    v177 = stack[-1];
    v177 = qcdr(v177);
    fn = elt(env, 8); /* times!-term!-mod!-p */
    v177 = (*qfn2(fn))(qenv(fn), v149, v177);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    fn = elt(env, 9); /* plus!-mod!-p */
    v177 = (*qfn2(fn))(qenv(fn), stack[-2], v177);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    stack[-2] = v177;
    v186 = stack[-2];
    v149 = stack[-1];
    v177 = stack[0];
    v177 = CC_xquotientKmodKp(env, 3, v186, v149, v177);
    nil = C_nil;
    if (exception_pending()) goto v128;
    {
        Lisp_Object v129 = stack[-3];
        popv(5);
        return cons(v129, v177);
    }

v60:
    v177 = stack[-2];
    v177 = qcar(v177);
    v149 = qcdr(v177);
    v177 = stack[-1];
    v177 = qcar(v177);
    v177 = qcdr(v177);
    fn = elt(env, 6); /* quotient!-mod!-p */
    v177 = (*qfn2(fn))(qenv(fn), v149, v177);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    stack[0] = v177;
    v177 = stack[0];
    if (v177 == nil) goto v114;
    v149 = stack[0];
    v177 = stack[-1];
    fn = elt(env, 10); /* times!-mod!-p */
    v177 = (*qfn2(fn))(qenv(fn), v149, v177);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    fn = elt(env, 11); /* difference!-mod!-p */
    v177 = (*qfn2(fn))(qenv(fn), stack[-2], v177);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    goto v122;

v122:
    if (v177 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v177 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v177; /* exact!-quotient!-flag */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v114:
    v177 = qvalue(elt(env, 2)); /* t */
    goto v122;

v94:
    v177 = stack[-2];
    v177 = qcar(v177);
    v177 = qcar(v177);
    v149 = qcar(v177);
    v177 = stack[0];
    if (equal(v149, v177)) goto v69;
    v177 = qvalue(elt(env, 2)); /* t */
    goto v97;

v69:
    v177 = stack[-2];
    v177 = qcar(v177);
    v177 = qcar(v177);
    v149 = qcdr(v177);
    v177 = stack[-1];
    v177 = qcar(v177);
    v177 = qcar(v177);
    v177 = qcdr(v177);
    v177 = ((intptr_t)v149 < (intptr_t)v177) ? lisp_true : nil;
    goto v97;

v37:
    v177 = qvalue(elt(env, 2)); /* t */
    goto v36;

v67:
    v177 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v177); }
/* error exit handlers */
v128:
    popv(5);
    return nil;
}



/* Code for lto_alunion */

static Lisp_Object CC_lto_alunion(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_alunion");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v54 = v0;
/* end of prologue */
    v11 = v54;
    v54 = elt(env, 1); /* union */
    {
        fn = elt(env, 2); /* lto_almerge */
        return (*qfn2(fn))(qenv(fn), v11, v54);
    }
}



/* Code for texexplode */

static Lisp_Object CC_texexplode(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for texexplode");
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
    v60 = v0;
/* end of prologue */
    v62 = v60;
    if (v62 == nil) goto v33;
    v62 = v60;
    if (!(!consp(v62))) goto v33;
    v61 = v60;
    v62 = elt(env, 1); /* texname */
    v62 = get(v61, v62);
    env = stack[0];
    if (!(v62 == nil)) goto v36;
    v61 = v60;
    v62 = elt(env, 2); /* class */
    v62 = get(v61, v62);
    env = stack[0];
    if (v62 == nil) goto v63;
    v62 = v60;
    goto v36;

v36:
    if (!(v62 == nil)) goto v67;
    v62 = v60;
    if (is_number(v62)) goto v21;
    v62 = v60;
    v62 = Lstringp(nil, v62);
    env = stack[0];
    if (v62 == nil) goto v31;
    v62 = v60;
    v62 = Lexplodec(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[0];
    fn = elt(env, 5); /* strcollect */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[0];
    goto v67;

v67:
    v60 = v62;
    v62 = v60;
    if (v62 == nil) goto v66;
    v62 = v60;
    if (!(!consp(v62))) { popv(1); return onevalue(v60); }
    v62 = v60;
    popv(1);
    return ncons(v62);

v66:
    v62 = elt(env, 4); /* !  */
    popv(1);
    return ncons(v62);

v31:
    v62 = v60;
    v62 = Lexplodec(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[0];
    fn = elt(env, 6); /* texcollect */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[0];
    fn = elt(env, 7); /* texexplist */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[0];
    goto v67;

v21:
    v62 = v60;
    v62 = Lexplode(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[0];
    fn = elt(env, 6); /* texcollect */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[0];
    goto v67;

v63:
    v62 = qvalue(elt(env, 3)); /* nil */
    goto v36;

v33:
    v62 = nil;
    goto v67;
/* error exit handlers */
v113:
    popv(1);
    return nil;
}



/* Code for cl_smsimpl!-junct1 */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v19,
                         Lisp_Object v3, Lisp_Object v40,
                         Lisp_Object v92, Lisp_Object v17,
                         Lisp_Object v67, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v245, v246, v247, v248, v249;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 7, "cl_smsimpl-junct1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_smsimpl-junct1");
#endif
    if (stack >= stacklimit)
    {
        push6(v67,v17,v92,v40,v3,v19);
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v19,v3,v40,v92,v17);
        pop(v67);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v67;
    stack[-4] = v17;
    stack[-5] = v92;
    stack[-6] = v40;
    stack[-7] = v3;
    v244 = v19;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v37;

v37:
    v244 = stack[-7];
    if (v244 == nil) goto v250;
    v244 = stack[-7];
    v244 = qcar(v244);
    stack[-9] = v244;
    v244 = stack[-7];
    v244 = qcdr(v244);
    stack[-7] = v244;
    stack[-10] = stack[-9];
    stack[0] = stack[-5];
    v244 = stack[-4];
    v245 = sub1(v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    v244 = stack[-8];
    fn = elt(env, 17); /* cl_simpl1 */
    v244 = (*qfnn(fn))(qenv(fn), 4, stack[-10], stack[0], v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    stack[-10] = v244;
    v244 = stack[-10];
    if (!consp(v244)) goto v68;
    v244 = stack[-10];
    v244 = qcar(v244);
    goto v21;

v21:
    v246 = v244;
    v245 = v246;
    v244 = stack[-3];
    if (v245 == v244) goto v29;
    v245 = v246;
    v244 = stack[-8];
    if (v245 == v244) goto v65;
    v245 = v246;
    v244 = elt(env, 3); /* true */
    if (v245 == v244) goto v137;
    v245 = v246;
    v244 = elt(env, 5); /* false */
    v244 = (v245 == v244 ? lisp_true : nil);
    goto v252;

v252:
    if (v244 == nil) goto v157;
    v244 = qvalue(elt(env, 4)); /* t */
    goto v253;

v253:
    if (v244 == nil) goto v254;
    stack[0] = v246;
    v244 = stack[-3];
    fn = elt(env, 18); /* cl_flip */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    if (equal(stack[0], v244)) goto v6;
    v245 = stack[-10];
    v244 = stack[-2];
    v244 = cons(v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    stack[-2] = v244;
    goto v6;

v6:
    v244 = stack[-1];
    if (v244 == nil) goto v37;
    v247 = stack[-8];
    v246 = stack[-1];
    v245 = stack[-5];
    v244 = stack[-4];
    fn = elt(env, 19); /* rl_smupdknowl */
    v244 = (*qfnn(fn))(qenv(fn), 4, v247, v246, v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    stack[-5] = v244;
    v245 = stack[-5];
    v244 = elt(env, 5); /* false */
    if (!(v245 == v244)) goto v255;
    v244 = stack[-3];
    stack[-9] = v244;
    v244 = qvalue(elt(env, 1)); /* nil */
    stack[-7] = v244;
    goto v255;

v255:
    v244 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v244;
    goto v37;

v254:
    v244 = qvalue(elt(env, 2)); /* !*rlsiidem */
    if (v244 == nil) goto v256;
    v244 = stack[-2];
    v245 = Lnreverse(nil, v244);
    env = stack[-11];
    v244 = stack[-7];
    v244 = Lnconc(nil, v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    stack[-7] = v244;
    v244 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v244;
    goto v256;

v256:
    v244 = stack[-10];
    v244 = ncons(v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    stack[-1] = v244;
    goto v6;

v157:
    v245 = v246;
    v244 = elt(env, 6); /* or */
    if (v245 == v244) goto v109;
    v245 = v246;
    v244 = elt(env, 7); /* and */
    v244 = (v245 == v244 ? lisp_true : nil);
    goto v108;

v108:
    if (v244 == nil) goto v174;
    v244 = qvalue(elt(env, 4)); /* t */
    goto v257;

v257:
    if (v244 == nil) goto v129;
    v244 = qvalue(elt(env, 4)); /* t */
    goto v160;

v160:
    if (v244 == nil) goto v258;
    v244 = qvalue(elt(env, 4)); /* t */
    goto v253;

v258:
    v245 = v246;
    v244 = elt(env, 12); /* ex */
    if (v245 == v244) goto v259;
    v245 = v246;
    v244 = elt(env, 13); /* all */
    v244 = (v245 == v244 ? lisp_true : nil);
    goto v260;

v260:
    if (v244 == nil) goto v261;
    v244 = qvalue(elt(env, 4)); /* t */
    goto v253;

v261:
    v245 = v246;
    v244 = elt(env, 14); /* bex */
    if (v245 == v244) goto v262;
    v245 = v246;
    v244 = elt(env, 15); /* ball */
    v244 = (v245 == v244 ? lisp_true : nil);
    goto v263;

v263:
    if (v244 == nil) goto v264;
    v244 = qvalue(elt(env, 4)); /* t */
    goto v253;

v264:
    v245 = v246;
    v244 = elt(env, 16); /* rl_external */
    v244 = get(v245, v244);
    env = stack[-11];
    goto v253;

v262:
    v244 = qvalue(elt(env, 4)); /* t */
    goto v263;

v259:
    v244 = qvalue(elt(env, 4)); /* t */
    goto v260;

v129:
    v245 = v246;
    v244 = elt(env, 9); /* impl */
    if (v245 == v244) goto v130;
    v245 = v246;
    v244 = elt(env, 10); /* repl */
    if (v245 == v244) goto v172;
    v245 = v246;
    v244 = elt(env, 11); /* equiv */
    v244 = (v245 == v244 ? lisp_true : nil);
    goto v160;

v172:
    v244 = qvalue(elt(env, 4)); /* t */
    goto v160;

v130:
    v244 = qvalue(elt(env, 4)); /* t */
    goto v160;

v174:
    v245 = v246;
    v244 = elt(env, 8); /* not */
    v244 = (v245 == v244 ? lisp_true : nil);
    goto v257;

v109:
    v244 = qvalue(elt(env, 4)); /* t */
    goto v108;

v137:
    v244 = qvalue(elt(env, 4)); /* t */
    goto v252;

v65:
    v244 = stack[-10];
    v244 = qcdr(v244);
    stack[0] = v244;
    goto v62;

v62:
    v244 = stack[0];
    if (v244 == nil) goto v193;
    v244 = stack[0];
    v244 = qcar(v244);
    fn = elt(env, 20); /* cl_atfp */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    if (v244 == nil) goto v193;
    v244 = stack[0];
    v245 = qcar(v244);
    v244 = stack[-1];
    v244 = cons(v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    stack[-1] = v244;
    v244 = stack[0];
    v244 = qcdr(v244);
    stack[0] = v244;
    goto v62;

v193:
    v244 = qvalue(elt(env, 2)); /* !*rlsiidem */
    if (v244 == nil) goto v265;
    v244 = stack[-1];
    if (v244 == nil) goto v265;
    v244 = stack[-2];
    v245 = Lnreverse(nil, v244);
    env = stack[-11];
    v244 = stack[-7];
    v244 = Lnconc(nil, v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    stack[-7] = v244;
    v244 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v244;
    goto v265;

v265:
    v244 = stack[0];
    v244 = Lreverse(nil, v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    v244 = Lnconc(nil, stack[-2], v244);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-11];
    stack[-2] = v244;
    goto v6;

v29:
    v244 = stack[-3];
    stack[-9] = v244;
    v244 = qvalue(elt(env, 1)); /* nil */
    stack[-7] = v244;
    goto v6;

v68:
    v244 = stack[-10];
    goto v21;

v250:
    v245 = stack[-9];
    v244 = stack[-3];
    if (v245 == v244) goto v266;
    v249 = stack[-8];
    v248 = stack[-2];
    v247 = stack[-6];
    v246 = stack[-5];
    v245 = stack[-4];
    v244 = stack[-3];
    {
        popv(12);
        fn = elt(env, 21); /* cl_smsimpl!-junct2 */
        return (*qfnn(fn))(qenv(fn), 6, v249, v248, v247, v246, v245, v244);
    }

v266:
    v244 = stack[-3];
    popv(12);
    return ncons(v244);
/* error exit handlers */
v251:
    popv(12);
    return nil;
}



/* Code for cnml */

static Lisp_Object MS_CDECL CC_cnml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cnml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cnml");
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
    v157 = qvalue(elt(env, 2)); /* atts */
    v110 = elt(env, 3); /* (t y p e) */
    fn = elt(env, 12); /* search_att */
    v110 = (*qfn2(fn))(qenv(fn), v157, v110);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    stack[-2] = v110;
    fn = elt(env, 13); /* lex */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v110 = qvalue(elt(env, 4)); /* char */
    stack[0] = v110;
    fn = elt(env, 13); /* lex */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v157 = stack[-2];
    v110 = elt(env, 5); /* (c o n s t a n t) */
    if (!(equal(v157, v110))) goto v16;
    v110 = stack[0];
    v110 = Lcompress(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v157 = Lintern(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v110 = qvalue(elt(env, 6)); /* rdci!* */
    v157 = Lassoc(nil, v157, v110);
    v110 = v157;
    if (v157 == nil) goto v16;
    v157 = v110;
    v157 = qcdr(v157);
    v157 = qcar(v157);
    v110 = qcdr(v110);
    v110 = qcdr(v110);
    {
        popv(4);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v157, v110);
    }

v16:
    v110 = stack[0];
    v110 = Lcompress(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    if (!(symbolp(v110))) goto v31;
    v110 = stack[0];
    v157 = Lcompress(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v110 = (Lisp_Object)257; /* 16 */
    fn = elt(env, 15); /* errorml */
    v110 = (*qfn2(fn))(qenv(fn), v157, v110);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    goto v31;

v31:
    v110 = stack[-2];
    if (v110 == nil) goto v15;
    v157 = stack[-2];
    v110 = elt(env, 7); /* ((r e a l) (i n t e g e r)) */
    v110 = Lmember(nil, v157, v110);
    if (v110 == nil) goto v122;
    v110 = stack[0];
        popv(4);
        return Lcompress(nil, v110);

v122:
    v157 = stack[-2];
    v110 = elt(env, 8); /* ((r a t i o n a l) (c o m p l e x !- c a r t e s i a n) (c o m p l e x !- p o l a r)) 
*/
    v110 = Lmember(nil, v157, v110);
    if (v110 == nil) goto v140;
    fn = elt(env, 16); /* seprd */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    stack[-1] = v110;
    v157 = stack[-2];
    v110 = elt(env, 9); /* (r a t i o n a l) */
    if (equal(v157, v110)) goto v52;
    v157 = stack[-2];
    v110 = elt(env, 10); /* (c o m p l e x !- c a r t e s i a n) */
    if (equal(v157, v110)) goto v158;
    v157 = stack[-2];
    v110 = elt(env, 11); /* (c o m p l e x !- p o l a r) */
    if (!(equal(v157, v110))) goto v140;
    v110 = stack[0];
    v157 = Lcompress(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v110 = stack[-1];
    fn = elt(env, 17); /* po2ca */
    v110 = (*qfn2(fn))(qenv(fn), v157, v110);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    stack[-1] = v110;
    fn = elt(env, 13); /* lex */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v110 = stack[-1];
    v157 = qcar(v110);
    v110 = stack[-1];
    v110 = qcdr(v110);
    v110 = qcar(v110);
    {
        popv(4);
        fn = elt(env, 18); /* comp2 */
        return (*qfn2(fn))(qenv(fn), v157, v110);
    }

v140:
    v110 = nil;
    { popv(4); return onevalue(v110); }

v158:
    fn = elt(env, 13); /* lex */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v110 = stack[0];
    v157 = Lcompress(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v110 = stack[-1];
    {
        popv(4);
        fn = elt(env, 18); /* comp2 */
        return (*qfn2(fn))(qenv(fn), v157, v110);
    }

v52:
    fn = elt(env, 13); /* lex */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v110 = stack[0];
    v157 = Lcompress(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v110 = stack[-1];
    {
        popv(4);
        fn = elt(env, 19); /* alg_quotient */
        return (*qfn2(fn))(qenv(fn), v157, v110);
    }

v15:
    v110 = stack[0];
        popv(4);
        return Lcompress(nil, v110);
/* error exit handlers */
v134:
    popv(4);
    return nil;
}



/* Code for sprow_dim */

static Lisp_Object CC_sprow_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sprow_dim");
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
    v189 = qvalue(elt(env, 1)); /* !*fast_la */
    if (v189 == nil) goto v11;
    v189 = qvalue(elt(env, 2)); /* nil */
    goto v54;

v54:
    if (v189 == nil) goto v67;
    v189 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v189 == nil)) goto v27;
    v189 = elt(env, 4); /* "Error in sprow_dim: input should be a matrix." 
*/
    fn = elt(env, 5); /* lprie */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-1];
    goto v27;

v27:
    v189 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-1];
    goto v67;

v67:
    v189 = stack[0];
    fn = elt(env, 6); /* spmatlength */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v202;
    v189 = qcdr(v189);
    v189 = qcar(v189);
    { popv(2); return onevalue(v189); }

v11:
    v189 = stack[0];
    fn = elt(env, 7); /* matrixp */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-1];
    v189 = (v189 == nil ? lisp_true : nil);
    goto v54;
/* error exit handlers */
v202:
    popv(2);
    return nil;
}



/* Code for dipreplus */

static Lisp_Object CC_dipreplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v78;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipreplus");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v78 = v0;
/* end of prologue */
    v28 = v78;
    if (!consp(v28)) return onevalue(v78);
    v28 = v78;
    v28 = qcdr(v28);
    if (v28 == nil) goto v33;
    v28 = elt(env, 1); /* plus */
    return cons(v28, v78);

v33:
    v28 = v78;
    v28 = qcar(v28);
    return onevalue(v28);
}



/* Code for vevzero!?1 */

static Lisp_Object CC_vevzeroW1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevzero?1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v0;
/* end of prologue */

v269:
    v5 = v6;
    if (v5 == nil) goto v92;
    v5 = v6;
    v29 = qcar(v5);
    v5 = (Lisp_Object)1; /* 0 */
    if (v29 == v5) goto v12;
    v5 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v5);

v12:
    v5 = v6;
    v5 = qcdr(v5);
    if (v5 == nil) goto v28;
    v5 = v6;
    v5 = qcdr(v5);
    v29 = qcar(v5);
    v5 = (Lisp_Object)1; /* 0 */
    if (v29 == v5) goto v25;
    v5 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v5);

v25:
    v5 = v6;
    v5 = qcdr(v5);
    v5 = qcdr(v5);
    v6 = v5;
    goto v269;

v28:
    v5 = qvalue(elt(env, 1)); /* t */
    return onevalue(v5);

v92:
    v5 = qvalue(elt(env, 1)); /* t */
    return onevalue(v5);
}



/* Code for ndepends */

static Lisp_Object CC_ndepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ndepends");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v19;
    stack[-1] = v0;
/* end of prologue */
    v108 = stack[-1];
    if (v108 == nil) goto v32;
    v108 = stack[-1];
    v108 = (is_number(v108) ? lisp_true : nil);
    if (!(v108 == nil)) goto v33;
    v108 = stack[0];
    v108 = (is_number(v108) ? lisp_true : nil);
    goto v33;

v33:
    if (v108 == nil) goto v78;
    v108 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v108); }

v78:
    v109 = stack[-1];
    v108 = stack[0];
    if (equal(v109, v108)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v108 = stack[-1];
    if (!consp(v108)) goto v118;
    v108 = qvalue(elt(env, 2)); /* nil */
    goto v124;

v124:
    if (v108 == nil) goto v5;
    v108 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v108); }

v5:
    v109 = stack[-1];
    v108 = qvalue(elt(env, 4)); /* depl!* */
    v108 = Lassoc(nil, v109, v108);
    v109 = v108;
    v108 = v109;
    if (v108 == nil) goto v188;
    v108 = v109;
    v109 = qcdr(v108);
    v108 = stack[0];
    fn = elt(env, 6); /* lndepends */
    v108 = (*qfn2(fn))(qenv(fn), v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    goto v95;

v95:
    if (v108 == nil) goto v20;
    v108 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v108); }

v20:
    v108 = stack[-1];
    if (!consp(v108)) goto v96;
    v108 = stack[-1];
    v108 = qcar(v108);
    if (symbolp(v108)) goto v114;
    v108 = qvalue(elt(env, 2)); /* nil */
    goto v142;

v142:
    if (v108 == nil) goto v61;
    v108 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v108); }

v61:
    v108 = stack[-1];
    fn = elt(env, 7); /* atomf */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    if (v108 == nil) goto v135;
    v108 = qvalue(elt(env, 2)); /* nil */
    goto v76;

v76:
    if (v108 == nil) goto v139;
    v108 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v108); }

v139:
    v108 = stack[0];
    fn = elt(env, 7); /* atomf */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    if (!(v108 == nil)) goto v163;
    v108 = stack[0];
    v108 = qcar(v108);
    if (!(symbolp(v108))) goto v160;
    v108 = stack[0];
    v109 = qcar(v108);
    v108 = elt(env, 5); /* dname */
    v108 = get(v109, v108);
    env = stack[-2];
    if (!(v108 == nil)) goto v163;

v160:
    v109 = stack[-1];
    v108 = stack[0];
    v108 = qcdr(v108);
    {
        popv(3);
        fn = elt(env, 8); /* ndependsl */
        return (*qfn2(fn))(qenv(fn), v109, v108);
    }

v163:
    v108 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v108); }

v135:
    v108 = stack[-1];
    v109 = qcdr(v108);
    v108 = stack[0];
    fn = elt(env, 6); /* lndepends */
    v108 = (*qfn2(fn))(qenv(fn), v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    if (!(v108 == nil)) goto v76;
    v108 = stack[-1];
    v109 = qcar(v108);
    v108 = stack[0];
    v108 = CC_ndepends(env, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    goto v76;

v114:
    v108 = stack[-1];
    v109 = qcar(v108);
    v108 = elt(env, 5); /* dname */
    v108 = get(v109, v108);
    env = stack[-2];
    goto v142;

v96:
    v108 = qvalue(elt(env, 2)); /* nil */
    goto v142;

v188:
    v108 = qvalue(elt(env, 2)); /* nil */
    goto v95;

v118:
    v109 = stack[-1];
    v108 = qvalue(elt(env, 3)); /* frlis!* */
    v108 = Lmemq(nil, v109, v108);
    goto v124;

v32:
    v108 = qvalue(elt(env, 1)); /* t */
    goto v33;
/* error exit handlers */
v152:
    popv(3);
    return nil;
}



/* Code for mkupf */

static Lisp_Object CC_mkupf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v49, v270;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkupf");
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
    v103 = v0;
/* end of prologue */
    v49 = v103;
    v103 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* mksq */
    v103 = (*qfn2(fn))(qenv(fn), v49, v103);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[0];
    v270 = v103;
    v103 = v270;
    v103 = qcar(v103);
    if (v103 == nil) goto v268;
    v103 = v270;
    v103 = qcar(v103);
    if (!consp(v103)) goto v28;
    v103 = v270;
    v103 = qcar(v103);
    v103 = qcar(v103);
    v103 = (consp(v103) ? nil : lisp_true);
    goto v27;

v27:
    if (v103 == nil) goto v120;
    v103 = (Lisp_Object)17; /* 1 */
    v49 = v270;
    v103 = cons(v103, v49);
    nil = C_nil;
    if (exception_pending()) goto v50;
    popv(1);
    return ncons(v103);

v120:
    v103 = v270;
    v49 = qcdr(v103);
    v103 = (Lisp_Object)17; /* 1 */
    if (v49 == v103) goto v84;
    v103 = qvalue(elt(env, 1)); /* nil */
    goto v69;

v69:
    if (v103 == nil) goto v271;
    v103 = v270;
    v103 = qcar(v103);
    v103 = qcar(v103);
    v103 = qcar(v103);
    v270 = qcar(v103);
    v49 = (Lisp_Object)17; /* 1 */
    v103 = (Lisp_Object)17; /* 1 */
    v103 = list2star(v270, v49, v103);
    nil = C_nil;
    if (exception_pending()) goto v50;
    popv(1);
    return ncons(v103);

v271:
    v103 = v270;
    {
        popv(1);
        fn = elt(env, 4); /* partitsq!* */
        return (*qfn1(fn))(qenv(fn), v103);
    }

v84:
    v103 = v270;
    v103 = qcar(v103);
    v103 = qcar(v103);
    v49 = qcdr(v103);
    v103 = (Lisp_Object)17; /* 1 */
    if (v49 == v103) goto v35;
    v103 = qvalue(elt(env, 1)); /* nil */
    goto v69;

v35:
    v103 = v270;
    v103 = qcar(v103);
    v103 = qcdr(v103);
    if (v103 == nil) goto v15;
    v103 = qvalue(elt(env, 1)); /* nil */
    goto v69;

v15:
    v103 = v270;
    v103 = qcar(v103);
    v103 = qcar(v103);
    v103 = qcar(v103);
    v103 = qcar(v103);
    if (!consp(v103)) goto v121;
    v103 = v270;
    v103 = qcar(v103);
    v103 = qcar(v103);
    v103 = qcar(v103);
    v103 = qcar(v103);
    v103 = qcar(v103);
    v103 = (consp(v103) ? nil : lisp_true);
    v103 = (v103 == nil ? lisp_true : nil);
    goto v62;

v62:
    v103 = (v103 == nil ? lisp_true : nil);
    goto v69;

v121:
    v103 = qvalue(elt(env, 1)); /* nil */
    goto v62;

v28:
    v103 = qvalue(elt(env, 2)); /* t */
    goto v27;

v268:
    v103 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v103); }
/* error exit handlers */
v50:
    popv(1);
    return nil;
}



/* Code for gfdiffer */

static Lisp_Object CC_gfdiffer(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfdiffer");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v19;
    stack[-1] = v0;
/* end of prologue */
    v85 = stack[-1];
    v85 = qcar(v85);
    if (!consp(v85)) goto v117;
    v85 = stack[-1];
    v95 = qcar(v85);
    v85 = stack[0];
    v85 = qcar(v85);
    fn = elt(env, 1); /* difbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v95, v85);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    v85 = stack[-1];
    v95 = qcdr(v85);
    v85 = stack[0];
    v85 = qcdr(v85);
    fn = elt(env, 1); /* difbf */
    v85 = (*qfn2(fn))(qenv(fn), v95, v85);
    nil = C_nil;
    if (exception_pending()) goto v4;
    {
        Lisp_Object v1 = stack[-2];
        popv(4);
        return cons(v1, v85);
    }

v117:
    v85 = stack[-1];
    v95 = qcar(v85);
    v85 = stack[0];
    v85 = qcar(v85);
    stack[-2] = difference2(v95, v85);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    v85 = stack[-1];
    v95 = qcdr(v85);
    v85 = stack[0];
    v85 = qcdr(v85);
    v85 = difference2(v95, v85);
    nil = C_nil;
    if (exception_pending()) goto v4;
    {
        Lisp_Object v2 = stack[-2];
        popv(4);
        return cons(v2, v85);
    }
/* error exit handlers */
v4:
    popv(4);
    return nil;
}



/* Code for prepsq!*1 */

static Lisp_Object MS_CDECL CC_prepsqH1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v19,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v367, v368, v369, v370;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prepsq*1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*1");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v19,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v3;
    stack[-5] = v19;
    stack[-6] = v0;
/* end of prologue */
    v367 = stack[-6];
    if (!consp(v367)) goto v38;
    v367 = stack[-6];
    v367 = qcar(v367);
    v367 = (consp(v367) ? nil : lisp_true);
    goto v37;

v37:
    if (v367 == nil) goto v88;
    v367 = qvalue(elt(env, 3)); /* nil */
    goto v93;

v93:
    if (v367 == nil) goto v54;
    v368 = stack[-5];
    v367 = (Lisp_Object)17; /* 1 */
    if (v368 == v367) goto v74;
    v367 = stack[-6];
    v367 = qcar(v367);
    v367 = qcar(v367);
    v367 = qcdr(v367);
    stack[-2] = v367;
    v367 = stack[-5];
    stack[-1] = v367;
    v367 = stack[-6];
    v367 = qcar(v367);
    v367 = qcar(v367);
    v369 = qcar(v367);
    v368 = (Lisp_Object)17; /* 1 */
    v367 = (Lisp_Object)17; /* 1 */
    v367 = acons(v369, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = ncons(v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[0] = v367;
    goto v102;

v102:
    v368 = stack[-1];
    v367 = stack[0];
    fn = elt(env, 14); /* quotfm */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-7] = v367;
    if (v367 == nil) goto v73;
    v367 = stack[-7];
    stack[-1] = v367;
    v367 = stack[-2];
    v367 = sub1(v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-2] = v367;
    goto v102;

v73:
    v367 = stack[-6];
    v367 = qcar(v367);
    v368 = qcdr(v367);
    v367 = stack[-1];
    stack[0] = cons(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v368 = stack[-2];
    v367 = (Lisp_Object)1; /* 0 */
    v367 = (Lisp_Object)greaterp2(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    v367 = v367 ? lisp_true : nil;
    env = stack[-8];
    if (v367 == nil) goto v153;
    v367 = stack[-6];
    v367 = qcar(v367);
    v367 = qcar(v367);
    v369 = qcar(v367);
    v368 = stack[-2];
    v367 = stack[-4];
    v367 = acons(v369, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    goto v70;

v70:
    fn = elt(env, 15); /* prepsq!*0 */
    v367 = (*qfn2(fn))(qenv(fn), stack[0], v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[0] = v367;
    goto v223;

v223:
    v367 = stack[-6];
    v368 = qcdr(v367);
    v367 = stack[-5];
    v368 = cons(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = stack[-4];
    fn = elt(env, 15); /* prepsq!*0 */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    {
        Lisp_Object v372 = stack[0];
        popv(9);
        return Lnconc(nil, v372, v367);
    }

v153:
    v368 = stack[-2];
    v367 = (Lisp_Object)1; /* 0 */
    v367 = (Lisp_Object)lessp2(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    v367 = v367 ? lisp_true : nil;
    env = stack[-8];
    if (v367 == nil) goto v170;
    v369 = elt(env, 4); /* expt */
    v367 = stack[-6];
    v367 = qcar(v367);
    v367 = qcar(v367);
    v368 = qcar(v367);
    v367 = stack[-2];
    v367 = list3(v369, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    fn = elt(env, 16); /* fkern */
    v368 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* getpower */
    v368 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = stack[-4];
    v367 = cons(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    goto v70;

v170:
    v367 = stack[-4];
    goto v70;

v74:
    v367 = stack[-6];
    v367 = qcar(v367);
    v368 = qcdr(v367);
    v367 = stack[-5];
    stack[0] = cons(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = stack[-6];
    v367 = qcar(v367);
    v368 = qcar(v367);
    v367 = stack[-4];
    v367 = cons(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    fn = elt(env, 15); /* prepsq!*0 */
    v367 = (*qfn2(fn))(qenv(fn), stack[0], v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[0] = v367;
    goto v223;

v54:
    v367 = stack[-5];
    if (!consp(v367)) goto v373;
    v367 = stack[-5];
    v367 = qcar(v367);
    v367 = (consp(v367) ? nil : lisp_true);
    goto v236;

v236:
    if (!(v367 == nil)) goto v374;
    v367 = qvalue(elt(env, 5)); /* kord!* */
    stack[-3] = v367;
    goto v375;

v375:
    v367 = stack[-3];
    if (v367 == nil) goto v374;
    v367 = stack[-3];
    v367 = qcar(v367);
    stack[-2] = v367;
    v367 = (Lisp_Object)1; /* 0 */
    stack[-1] = v367;
    v369 = stack[-2];
    v368 = (Lisp_Object)17; /* 1 */
    v367 = (Lisp_Object)17; /* 1 */
    v367 = acons(v369, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = ncons(v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[0] = v367;
    goto v225;

v225:
    v368 = stack[-5];
    v367 = stack[0];
    fn = elt(env, 14); /* quotfm */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-7] = v367;
    if (v367 == nil) goto v376;
    v367 = stack[-1];
    v367 = sub1(v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-1] = v367;
    v367 = stack[-7];
    stack[-5] = v367;
    goto v225;

v376:
    v368 = stack[-1];
    v367 = (Lisp_Object)1; /* 0 */
    v367 = (Lisp_Object)lessp2(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    v367 = v367 ? lisp_true : nil;
    env = stack[-8];
    if (v367 == nil) goto v377;
    v369 = elt(env, 4); /* expt */
    v368 = stack[-2];
    v367 = stack[-1];
    v367 = list3(v369, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    fn = elt(env, 16); /* fkern */
    v368 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* getpower */
    v368 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = stack[-4];
    v367 = cons(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-4] = v367;
    goto v377;

v377:
    v367 = stack[-3];
    v367 = qcdr(v367);
    stack[-3] = v367;
    goto v375;

v374:
    v367 = stack[-6];
    fn = elt(env, 18); /* kernlp */
    v367 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    if (v367 == nil) goto v378;
    v368 = stack[-4];
    v367 = stack[-6];
    fn = elt(env, 19); /* mkkl */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-6] = v367;
    v367 = qvalue(elt(env, 3)); /* nil */
    stack[-4] = v367;
    goto v378;

v378:
    v367 = qvalue(elt(env, 6)); /* dnl!* */
    if (v367 == nil) goto v379;
    v367 = qvalue(elt(env, 7)); /* !*allfac */
    if (v367 == nil) goto v380;
    v367 = stack[-6];
    fn = elt(env, 20); /* ckrn */
    v367 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    goto v381;

v381:
    stack[-1] = v367;
    v368 = stack[-1];
    v367 = qvalue(elt(env, 6)); /* dnl!* */
    fn = elt(env, 21); /* ckrn!* */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-7] = v367;
    v368 = stack[-1];
    v367 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v368 = stack[-6];
    v367 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-6] = v367;
    v368 = stack[-5];
    v367 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-5] = v367;
    goto v379;

v379:
    v367 = qvalue(elt(env, 8)); /* upl!* */
    if (v367 == nil) goto v382;
    v367 = stack[-5];
    fn = elt(env, 20); /* ckrn */
    v367 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[0] = v367;
    v368 = stack[0];
    v367 = qvalue(elt(env, 8)); /* upl!* */
    fn = elt(env, 21); /* ckrn!* */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-7] = v367;
    v368 = stack[0];
    v367 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[0] = v367;
    v368 = stack[-6];
    v367 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-6] = v367;
    v368 = stack[-5];
    v367 = stack[-7];
    fn = elt(env, 22); /* quotof */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-5] = v367;
    goto v383;

v383:
    stack[-1] = stack[-6];
    v368 = stack[-5];
    v367 = stack[0];
    fn = elt(env, 22); /* quotof */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = cons(stack[-1], v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    fn = elt(env, 23); /* canonsq */
    v367 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-6] = v367;
    v367 = stack[-6];
    v368 = qcar(v367);
    v367 = stack[0];
    fn = elt(env, 22); /* quotof */
    v368 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = stack[-6];
    v367 = qcdr(v367);
    v367 = cons(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-6] = v367;
    v367 = qvalue(elt(env, 7)); /* !*allfac */
    if (v367 == nil) goto v384;
    v367 = stack[-6];
    v367 = qcar(v367);
    fn = elt(env, 20); /* ckrn */
    v367 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-1] = v367;
    v367 = stack[-6];
    v367 = qcdr(v367);
    fn = elt(env, 20); /* ckrn */
    v367 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[0] = v367;
    v368 = stack[-1];
    v367 = (Lisp_Object)17; /* 1 */
    if (v368 == v367) goto v385;
    v367 = qvalue(elt(env, 1)); /* t */
    goto v386;

v386:
    if (v367 == nil) goto v387;
    v368 = stack[-1];
    v367 = stack[-6];
    v367 = qcar(v367);
    if (equal(v368, v367)) goto v388;
    v367 = qvalue(elt(env, 1)); /* t */
    goto v389;

v389:
    if (v367 == nil) goto v384;
    v367 = stack[-6];
    v368 = qcdr(v367);
    v367 = stack[0];
    fn = elt(env, 22); /* quotof */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-5] = v367;
    v367 = stack[-6];
    v368 = qcar(v367);
    v367 = stack[-1];
    fn = elt(env, 22); /* quotof */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-6] = v367;
    v368 = stack[-4];
    v367 = stack[-1];
    fn = elt(env, 19); /* mkkl */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    fn = elt(env, 13); /* prepf */
    v367 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-4] = v367;
    v367 = stack[0];
    fn = elt(env, 13); /* prepf */
    v367 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-1] = v367;
    v368 = stack[-4];
    v367 = stack[-6];
    fn = elt(env, 24); /* addfactors */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-6] = v367;
    v368 = stack[-1];
    v367 = stack[-5];
    fn = elt(env, 24); /* addfactors */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[-5] = v367;
    v368 = stack[-5];
    v367 = (Lisp_Object)17; /* 1 */
    if (v368 == v367) goto v390;
    v368 = stack[-6];
    v367 = elt(env, 11); /* minus */
    if (!consp(v368)) goto v391;
    v368 = qcar(v368);
    if (!(v368 == v367)) goto v391;
    stack[0] = elt(env, 11); /* minus */
    v369 = elt(env, 12); /* quotient */
    v367 = stack[-6];
    v367 = qcdr(v367);
    v368 = qcar(v367);
    v367 = stack[-5];
    v367 = list3(v369, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = list2(stack[0], v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    goto v392;

v392:
    popv(9);
    return ncons(v367);

v391:
    v369 = elt(env, 12); /* quotient */
    v368 = stack[-6];
    v367 = stack[-5];
    v367 = list3(v369, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    goto v392;

v390:
    v367 = stack[-6];
    v368 = elt(env, 10); /* plus */
    if (!consp(v367)) goto v393;
    v367 = qcar(v367);
    if (!(v367 == v368)) goto v393;
    v367 = stack[-6];
    v367 = qcdr(v367);
    { popv(9); return onevalue(v367); }

v393:
    v367 = stack[-6];
    popv(9);
    return ncons(v367);

v384:
    v367 = stack[-4];
    if (v367 == nil) goto v394;
    v370 = stack[-4];
    v369 = qvalue(elt(env, 3)); /* nil */
    v368 = qvalue(elt(env, 3)); /* nil */
    v367 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 25); /* exchk1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 4, v370, v369, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = stack[-6];
    v367 = qcar(v367);
    if (v367 == nil) goto v395;
    v368 = stack[-6];
    v367 = elt(env, 13); /* prepf */
    fn = elt(env, 26); /* sqform */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    goto v396;

v396:
    v367 = ncons(v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    v367 = Lnconc(nil, stack[0], v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    fn = elt(env, 27); /* retimes */
    v367 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    popv(9);
    return ncons(v367);

v395:
    v367 = (Lisp_Object)1; /* 0 */
    goto v396;

v394:
    v367 = stack[-6];
    v367 = qcar(v367);
    if (v367 == nil) goto v397;
    v368 = stack[-6];
    v367 = elt(env, 13); /* prepf */
    fn = elt(env, 26); /* sqform */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    goto v398;

v398:
    v368 = v367;
    v367 = v368;
    v369 = elt(env, 10); /* plus */
    if (!consp(v367)) goto v399;
    v367 = qcar(v367);
    if (!(v367 == v369)) goto v399;
    v367 = v368;
    v367 = qcdr(v367);
    { popv(9); return onevalue(v367); }

v399:
    v367 = v368;
    popv(9);
    return ncons(v367);

v397:
    v367 = (Lisp_Object)1; /* 0 */
    goto v398;

v388:
    v368 = stack[0];
    v367 = stack[-6];
    v367 = qcdr(v367);
    v367 = Lneq(nil, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    goto v389;

v387:
    v367 = qvalue(elt(env, 3)); /* nil */
    goto v389;

v385:
    v368 = stack[0];
    v367 = (Lisp_Object)17; /* 1 */
    v367 = Lneq(nil, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    goto v386;

v382:
    v367 = qvalue(elt(env, 9)); /* !*div */
    if (v367 == nil) goto v400;
    v367 = stack[-5];
    fn = elt(env, 20); /* ckrn */
    v367 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v371;
    env = stack[-8];
    stack[0] = v367;
    goto v383;

v400:
    v367 = (Lisp_Object)17; /* 1 */
    stack[0] = v367;
    goto v383;

v380:
    v367 = (Lisp_Object)17; /* 1 */
    goto v381;

v373:
    v367 = qvalue(elt(env, 1)); /* t */
    goto v236;

v88:
    v367 = stack[-6];
    v367 = qcar(v367);
    v367 = qcar(v367);
    v368 = qcar(v367);
    v367 = qvalue(elt(env, 2)); /* factors!* */
    v367 = Lmember(nil, v368, v367);
    if (!(v367 == nil)) goto v93;
    v367 = stack[-6];
    v367 = qcar(v367);
    v367 = qcar(v367);
    v367 = qcar(v367);
    if (!consp(v367)) goto v84;
    v367 = stack[-6];
    v367 = qcar(v367);
    v367 = qcar(v367);
    v367 = qcar(v367);
    v368 = qcar(v367);
    v367 = qvalue(elt(env, 2)); /* factors!* */
    v367 = Lmember(nil, v368, v367);
    goto v93;

v84:
    v367 = qvalue(elt(env, 3)); /* nil */
    goto v93;

v38:
    v367 = qvalue(elt(env, 1)); /* t */
    goto v37;
/* error exit handlers */
v371:
    popv(9);
    return nil;
}



/* Code for equiv!-coeffs */

static Lisp_Object CC_equivKcoeffs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equiv-coeffs");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v19;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v67;

v67:
    v61 = stack[-1];
    if (v61 == nil) goto v97;
    v61 = stack[0];
    if (v61 == nil) goto v79;
    v61 = stack[-1];
    v61 = qcar(v61);
    v113 = qcar(v61);
    v61 = stack[0];
    v61 = qcar(v61);
    v61 = qcar(v61);
    if (equal(v113, v61)) goto v8;
    v61 = stack[-1];
    v61 = qcar(v61);
    v113 = qcar(v61);
    v61 = stack[0];
    v61 = qcar(v61);
    v61 = qcar(v61);
    fn = elt(env, 1); /* mv!-pow!-!> */
    v61 = (*qfn2(fn))(qenv(fn), v113, v61);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    if (v61 == nil) goto v14;
    v61 = stack[-1];
    v61 = qcdr(v61);
    stack[-1] = v61;
    goto v67;

v14:
    v113 = (Lisp_Object)1; /* 0 */
    v61 = stack[-2];
    v61 = cons(v113, v61);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    stack[-2] = v61;
    v61 = stack[0];
    v61 = qcdr(v61);
    stack[0] = v61;
    goto v67;

v8:
    v61 = stack[-1];
    v61 = qcar(v61);
    v113 = qcdr(v61);
    v61 = stack[-2];
    v61 = cons(v113, v61);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    stack[-2] = v61;
    v61 = stack[-1];
    v61 = qcdr(v61);
    stack[-1] = v61;
    v61 = stack[0];
    v61 = qcdr(v61);
    stack[0] = v61;
    goto v67;

v79:
    v61 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v61);
    }

v97:
    stack[-1] = stack[-2];
    v61 = stack[0];
    v61 = Llength(nil, v61);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    fn = elt(env, 3); /* nzeros */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    {
        Lisp_Object v201 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v201, v61);
    }
/* error exit handlers */
v148:
    popv(4);
    return nil;
}



/* Code for hdiff */

static Lisp_Object CC_hdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v19)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for hdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v19,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v19;
    stack[-1] = v0;
/* end of prologue */
    v118 = stack[-1];
    if (v118 == nil) goto v17;
    v8 = stack[-1];
    v118 = (Lisp_Object)49; /* 3 */
    v8 = *(Lisp_Object *)((char *)v8 + (CELL-TAG_VECTOR) + ((int32_t)v118/(16/CELL)));
    v118 = stack[0];
    stack[-2] = CC_hdiff(env, v8, v118);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v8 = stack[-1];
    v118 = stack[0];
    fn = elt(env, 2); /* hdiffterm */
    v118 = (*qfn2(fn))(qenv(fn), v8, v118);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    {
        Lisp_Object v68 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v68, v118);
    }

v17:
    v118 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v118); }
/* error exit handlers */
v21:
    popv(4);
    return nil;
}



setup_type const u37_setup[] =
{
    {"simpsqrt3",               CC_simpsqrt3,   too_many_1,    wrong_no_1},
    {"rtrnda",                  too_few_2,      CC_rtrnda,     wrong_no_2},
    {"*s2i",                    CC_Hs2i,        too_many_1,    wrong_no_1},
    {"even_action_pow",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_even_action_pow},
    {"gd_gcasesimpl",           CC_gd_gcasesimpl,too_many_1,   wrong_no_1},
    {"taymindegreel",           too_few_2,      CC_taymindegreel,wrong_no_2},
    {"pasf_lnegrel",            CC_pasf_lnegrel,too_many_1,    wrong_no_1},
    {"dvfsf_smcpknowl",         CC_dvfsf_smcpknowl,too_many_1, wrong_no_1},
    {"symbolsrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_symbolsrd},
    {"transferrow1",            CC_transferrow1,too_many_1,    wrong_no_1},
    {"termorder1",              too_few_2,      CC_termorder1, wrong_no_2},
    {"xexptpf",                 too_few_2,      CC_xexptpf,    wrong_no_2},
    {"adjp",                    CC_adjp,        too_many_1,    wrong_no_1},
    {"mk_parents_prim",         CC_mk_parents_prim,too_many_1, wrong_no_1},
    {"simp-prop",               CC_simpKprop,   too_many_1,    wrong_no_1},
    {"njets",                   too_few_2,      CC_njets,      wrong_no_2},
    {"mkrootsq",                too_few_2,      CC_mkrootsq,   wrong_no_2},
    {"update_components",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_update_components},
    {"*multsq",                 too_few_2,      CC_Hmultsq,    wrong_no_2},
    {"ratpoly_red",             CC_ratpoly_red, too_many_1,    wrong_no_1},
    {"bc_2a",                   CC_bc_2a,       too_many_1,    wrong_no_1},
    {"matrixrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrd},
    {"ldf-sep-var",             CC_ldfKsepKvar, too_many_1,    wrong_no_1},
    {"addns",                   too_few_2,      CC_addns,      wrong_no_2},
    {"mkprec",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkprec},
    {"xquotient-mod-p",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_xquotientKmodKp},
    {"lto_alunion",             CC_lto_alunion, too_many_1,    wrong_no_1},
    {"texexplode",              CC_texexplode,  too_many_1,    wrong_no_1},
    {"cl_smsimpl-junct1",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct1},
    {"cnml",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cnml},
    {"sprow_dim",               CC_sprow_dim,   too_many_1,    wrong_no_1},
    {"dipreplus",               CC_dipreplus,   too_many_1,    wrong_no_1},
    {"vevzero?1",               CC_vevzeroW1,   too_many_1,    wrong_no_1},
    {"ndepends",                too_few_2,      CC_ndepends,   wrong_no_2},
    {"mkupf",                   CC_mkupf,       too_many_1,    wrong_no_1},
    {"gfdiffer",                too_few_2,      CC_gfdiffer,   wrong_no_2},
    {"prepsq*1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_prepsqH1},
    {"equiv-coeffs",            too_few_2,      CC_equivKcoeffs,wrong_no_2},
    {"hdiff",                   too_few_2,      CC_hdiff,      wrong_no_2},
    {NULL, (one_args *)"u37", (two_args *)"11300 2647379 2118669", 0}
};

/* end of generated code */
