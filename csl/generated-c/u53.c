
/* $destdir\u53.c        Machine generated C code */

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


/* Code for cos!: */

static Lisp_Object CC_cosT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v189, v190, v191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cos:");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-11] = v1;
    stack[-2] = v0;
/* end of prologue */

v192:
    v189 = stack[-11];
    v189 = integerp(v189);
    if (v189 == nil) goto v193;
    v190 = stack[-11];
    v189 = (Lisp_Object)1; /* 0 */
    v189 = (Lisp_Object)lesseq2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v194;
    v189 = v189 ? lisp_true : nil;
    env = stack[-14];
    goto v195;

v195:
    if (v189 == nil) goto v196;
    stack[0] = (Lisp_Object)1; /* 0 */
    v190 = elt(env, 2); /* "Invalid argument to" */
    v189 = elt(env, 0); /* cos!: */
    v189 = list2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-14];
    {
        Lisp_Object v197 = stack[0];
        popv(15);
        fn = elt(env, 8); /* error */
        return (*qfn2(fn))(qenv(fn), v197, v189);
    }

v196:
    v189 = stack[-2];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = (Lisp_Object)1; /* 0 */
    if (v190 == v189) goto v198;
    v190 = stack[-2];
    v189 = elt(env, 4); /* !:rd!: */
    if (!consp(v190)) goto v199;
    v190 = qcar(v190);
    if (!(v190 == v189)) goto v199;
    v189 = stack[-2];
    v189 = qcdr(v189);
    v189 = (consp(v189) ? nil : lisp_true);
    v189 = (v189 == nil ? lisp_true : nil);
    goto v200;

v200:
    if (v189 == nil) goto v201;
    v189 = stack[-2];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = (Lisp_Object)1; /* 0 */
    v189 = (Lisp_Object)lessp2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v194;
    v189 = v189 ? lisp_true : nil;
    env = stack[-14];
    goto v202;

v202:
    if (v189 == nil) goto v203;
    stack[0] = elt(env, 4); /* !:rd!: */
    v189 = stack[-2];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    v190 = negate(v189);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-14];
    v189 = stack[-2];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = list2star(stack[0], v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-14];
    stack[-2] = v189;
    goto v192;

v203:
    stack[-6] = qvalue(elt(env, 6)); /* !!sclc */
    qvalue(elt(env, 6)) = nil; /* !!sclc */
    v190 = stack[-11];
    v189 = (Lisp_Object)113; /* 7 */
    v189 = plus2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-12] = v189;
    v189 = stack[-2];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    v189 = Labsval(nil, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    fn = elt(env, 9); /* msd */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-10] = v189;
    v190 = stack[-12];
    v189 = stack[-10];
    v189 = plus2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    fn = elt(env, 10); /* !:pi */
    v190 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = qvalue(elt(env, 7)); /* !:bf!-0!.25 */
    stack[-4] = v190;
    stack[-3] = v189;
    stack[-1] = elt(env, 4); /* !:rd!: */
    v189 = stack[-4];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = stack[-3];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    stack[0] = times2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-4];
    v189 = qcdr(v189);
    v190 = qcdr(v189);
    v189 = stack[-3];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = plus2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = list2star(stack[-1], stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-3] = v189;
    v190 = stack[-3];
    v189 = stack[-2];
    fn = elt(env, 11); /* greaterp!: */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    if (v189 == nil) goto v205;
    v189 = (Lisp_Object)1; /* 0 */
    stack[-10] = v189;
    v189 = stack[-2];
    stack[-8] = v189;
    goto v206;

v206:
    v189 = qvalue(elt(env, 3)); /* bfone!* */
    stack[-9] = v189;
    v190 = stack[-10];
    v189 = (Lisp_Object)129; /* 8 */
    v189 = (Lisp_Object)geq2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    v189 = v189 ? lisp_true : nil;
    env = stack[-14];
    if (v189 == nil) goto v207;
    v190 = stack[-10];
    v189 = (Lisp_Object)129; /* 8 */
    v189 = Cremainder(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-10] = v189;
    goto v207;

v207:
    v190 = stack[-10];
    v189 = (Lisp_Object)65; /* 4 */
    v189 = (Lisp_Object)geq2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    v189 = v189 ? lisp_true : nil;
    env = stack[-14];
    if (v189 == nil) goto v208;
    stack[0] = elt(env, 4); /* !:rd!: */
    v189 = stack[-9];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    v190 = negate(v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-9];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = list2star(stack[0], v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-9] = v189;
    v190 = stack[-10];
    v189 = (Lisp_Object)65; /* 4 */
    v189 = difference2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-10] = v189;
    goto v208;

v208:
    v190 = stack[-10];
    v189 = (Lisp_Object)33; /* 2 */
    v189 = (Lisp_Object)geq2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    v189 = v189 ? lisp_true : nil;
    env = stack[-14];
    if (v189 == nil) goto v209;
    stack[0] = elt(env, 4); /* !:rd!: */
    v189 = stack[-9];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    v190 = negate(v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-9];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = list2star(stack[0], v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-9] = v189;
    goto v209;

v209:
    v190 = stack[-10];
    v189 = (Lisp_Object)1; /* 0 */
    if (v190 == v189) goto v210;
    v190 = stack[-10];
    v189 = (Lisp_Object)17; /* 1 */
    if (v190 == v189) goto v211;
    v190 = stack[-10];
    v189 = (Lisp_Object)33; /* 2 */
    if (v190 == v189) goto v212;
    v190 = stack[-3];
    v189 = stack[-8];
    fn = elt(env, 12); /* difference!: */
    v190 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-12];
    fn = elt(env, 13); /* cut!:mt */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-8] = v189;
    goto v210;

v210:
    stack[-1] = elt(env, 4); /* !:rd!: */
    stack[0] = (Lisp_Object)33; /* 2 */
    v189 = stack[-12];
    v189 = negate(v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = list2star(stack[-1], stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-4] = v189;
    v189 = qvalue(elt(env, 3)); /* bfone!* */
    stack[-1] = v189;
    stack[-2] = v189;
    stack[-7] = v189;
    stack[-3] = elt(env, 4); /* !:rd!: */
    v189 = stack[-8];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = stack[-8];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    stack[0] = times2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-8];
    v189 = qcdr(v189);
    v190 = qcdr(v189);
    v189 = stack[-8];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = plus2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[0] = list2star(stack[-3], stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-12];
    v189 = negate(v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    fn = elt(env, 14); /* cut!:ep */
    v189 = (*qfn2(fn))(qenv(fn), stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-3] = v189;
    stack[0] = elt(env, 4); /* !:rd!: */
    v189 = stack[-3];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    v190 = negate(v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-3];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = list2star(stack[0], v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-8] = v189;
    v189 = (Lisp_Object)17; /* 1 */
    stack[-10] = v189;
    v189 = (Lisp_Object)1; /* 0 */
    stack[-5] = v189;
    goto v213;

v213:
    v189 = stack[-1];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = (Lisp_Object)1; /* 0 */
    v189 = (Lisp_Object)greaterp2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    v189 = v189 ? lisp_true : nil;
    env = stack[-14];
    if (v189 == nil) goto v214;
    v189 = stack[-1];
    v190 = v189;
    goto v215;

v215:
    v189 = stack[-4];
    fn = elt(env, 11); /* greaterp!: */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    if (v189 == nil) goto v216;
    v190 = stack[-5];
    v189 = (Lisp_Object)33; /* 2 */
    v189 = plus2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-5] = v189;
    stack[-1] = elt(env, 4); /* !:rd!: */
    stack[-3] = stack[-10];
    stack[0] = stack[-5];
    v189 = stack[-5];
    v189 = sub1(v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = times2(stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v190 = times2(stack[-3], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-10] = v190;
    v189 = (Lisp_Object)1; /* 0 */
    v189 = list2star(stack[-1], v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-3] = v189;
    stack[-1] = elt(env, 4); /* !:rd!: */
    v189 = stack[-2];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = stack[-8];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    stack[0] = times2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-2];
    v189 = qcdr(v189);
    v190 = qcdr(v189);
    v189 = stack[-8];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = plus2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[0] = list2star(stack[-1], stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-12];
    v189 = negate(v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    fn = elt(env, 14); /* cut!:ep */
    v189 = (*qfn2(fn))(qenv(fn), stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-2] = v189;
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[-13] = stack[-12];
    v189 = stack[-3];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = (Lisp_Object)1; /* 0 */
    if (v190 == v189) goto v217;
    v189 = stack[-3];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    v189 = Labsval(nil, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    fn = elt(env, 9); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-3];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = sub1(v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = plus2(stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    goto v218;

v218:
    stack[-13] = difference2(stack[-13], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-2];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = (Lisp_Object)1; /* 0 */
    if (v190 == v189) goto v219;
    v189 = stack[-2];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    v189 = Labsval(nil, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    fn = elt(env, 9); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-2];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = sub1(v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = plus2(stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    goto v220;

v220:
    v189 = plus2(stack[-13], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    fn = elt(env, 15); /* max */
    v189 = (*qfn2(fn))(qenv(fn), stack[-1], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v191 = stack[-2];
    v190 = stack[-3];
    fn = elt(env, 16); /* divide!: */
    v189 = (*qfnn(fn))(qenv(fn), 3, v191, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-1] = v189;
    v190 = stack[-7];
    v189 = stack[-1];
    fn = elt(env, 17); /* plus!: */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-7] = v189;
    v190 = stack[-5];
    v189 = (Lisp_Object)321; /* 20 */
    v189 = Cremainder(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = (Lisp_Object)zerop(v189);
    v189 = v189 ? lisp_true : nil;
    env = stack[-14];
    if (v189 == nil) goto v213;
    stack[0] = stack[-7];
    v189 = stack[-12];
    v189 = negate(v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    fn = elt(env, 14); /* cut!:ep */
    v189 = (*qfn2(fn))(qenv(fn), stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-7] = v189;
    goto v213;

v219:
    v189 = (Lisp_Object)1; /* 0 */
    goto v220;

v217:
    v189 = (Lisp_Object)1; /* 0 */
    goto v218;

v216:
    stack[-1] = elt(env, 4); /* !:rd!: */
    v189 = stack[-9];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = stack[-7];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    stack[0] = times2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-9];
    v189 = qcdr(v189);
    v190 = qcdr(v189);
    v189 = stack[-7];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = plus2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v190 = list2star(stack[-1], stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-11];
    fn = elt(env, 18); /* round!:mt */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    goto v221;

v221:
    qvalue(elt(env, 6)) = stack[-6]; /* !!sclc */
    { popv(15); return onevalue(v189); }

v214:
    stack[0] = elt(env, 4); /* !:rd!: */
    v189 = stack[-1];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    v190 = negate(v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-1];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = list2star(stack[0], v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v190 = v189;
    goto v215;

v212:
    v190 = stack[-8];
    v189 = stack[-12];
    fn = elt(env, 13); /* cut!:mt */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-8] = v189;
    v189 = stack[-2];
    qvalue(elt(env, 6)) = v189; /* !!sclc */
    v190 = stack[-8];
    v189 = stack[-11];
    fn = elt(env, 19); /* sin!: */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-2] = v189;
    stack[-1] = elt(env, 4); /* !:rd!: */
    v189 = stack[-9];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = stack[-2];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    stack[0] = times2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-9];
    v189 = qcdr(v189);
    v190 = qcdr(v189);
    v189 = stack[-2];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = plus2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = list2star(stack[-1], stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    goto v221;

v211:
    v190 = stack[-3];
    v189 = stack[-8];
    fn = elt(env, 12); /* difference!: */
    v190 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-12];
    fn = elt(env, 13); /* cut!:mt */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-8] = v189;
    v189 = stack[-2];
    qvalue(elt(env, 6)) = v189; /* !!sclc */
    v190 = stack[-8];
    v189 = stack[-11];
    fn = elt(env, 19); /* sin!: */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-2] = v189;
    stack[-1] = elt(env, 4); /* !:rd!: */
    v189 = stack[-9];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = stack[-2];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    stack[0] = times2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-9];
    v189 = qcdr(v189);
    v190 = qcdr(v189);
    v189 = stack[-2];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = plus2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = list2star(stack[-1], stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    goto v221;

v205:
    v190 = stack[-2];
    v189 = stack[-3];
    fn = elt(env, 20); /* quotient!: */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-5] = v189;
    v190 = v189;
    v190 = qcdr(v190);
    v190 = qcar(v190);
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = Lash1(nil, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-10] = v189;
    stack[-4] = stack[-2];
    stack[-1] = elt(env, 4); /* !:rd!: */
    v189 = stack[-5];
    v189 = qcdr(v189);
    v190 = qcar(v189);
    v189 = stack[-3];
    v189 = qcdr(v189);
    v189 = qcar(v189);
    stack[0] = times2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = stack[-5];
    v189 = qcdr(v189);
    v190 = qcdr(v189);
    v189 = stack[-3];
    v189 = qcdr(v189);
    v189 = qcdr(v189);
    v189 = plus2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    v189 = list2star(stack[-1], stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    fn = elt(env, 12); /* difference!: */
    v189 = (*qfn2(fn))(qenv(fn), stack[-4], v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-14];
    stack[-8] = v189;
    goto v206;

v201:
    v189 = qvalue(elt(env, 5)); /* nil */
    goto v202;

v199:
    v189 = qvalue(elt(env, 5)); /* nil */
    goto v200;

v198:
    v189 = qvalue(elt(env, 3)); /* bfone!* */
    { popv(15); return onevalue(v189); }

v193:
    v189 = qvalue(elt(env, 1)); /* t */
    goto v195;
/* error exit handlers */
v204:
    env = stack[-14];
    qvalue(elt(env, 6)) = stack[-6]; /* !!sclc */
    popv(15);
    return nil;
v194:
    popv(15);
    return nil;
}



/* Code for clear */

static Lisp_Object CC_clear(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v226, v227;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clear");
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
    v226 = qvalue(elt(env, 1)); /* !*sqvar!* */
    v202 = qvalue(elt(env, 2)); /* nil */
    v202 = Lrplaca(nil, v226, v202);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    v202 = qvalue(elt(env, 3)); /* t */
    v202 = ncons(v202);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    qvalue(elt(env, 1)) = v202; /* !*sqvar!* */
    v202 = qvalue(elt(env, 2)); /* nil */
    v202 = ncons(v202);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    qvalue(elt(env, 4)) = v202; /* alglist!* */
    stack[-1] = elt(env, 5); /* clear1 */
    v202 = stack[0];
    v202 = Lmkquote(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    v227 = list2(stack[-1], v202);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    v226 = qvalue(elt(env, 3)); /* t */
    v202 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 9); /* errorset */
    v202 = (*qfnn(fn))(qenv(fn), 3, v227, v226, v202);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    stack[0] = v202;
    v202 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 7)) = v202; /* frasc!* */
    qvalue(elt(env, 8)) = v202; /* mcond!* */
    v202 = stack[0];
    if (!consp(v202)) goto v196;
    v202 = stack[0];
    v202 = qcdr(v202);
    goto v229;

v229:
    if (v202 == nil) goto v230;
    v202 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v228;
    v202 = nil;
    { popv(3); return onevalue(v202); }

v230:
    v202 = stack[0];
    v202 = qcar(v202);
    { popv(3); return onevalue(v202); }

v196:
    v202 = qvalue(elt(env, 3)); /* t */
    goto v229;
/* error exit handlers */
v228:
    popv(3);
    return nil;
}



/* Code for nbglp */

static Lisp_Object CC_nbglp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nbglp");
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
    stack[0] = v0;
/* end of prologue */
    v233 = stack[-1];
    v232 = (Lisp_Object)1; /* 0 */
    if (v233 == v232) goto v192;
    v232 = stack[0];
    if (!consp(v232)) goto v234;
    v232 = stack[0];
    v232 = qcar(v232);
    fn = elt(env, 3); /* bglp!:!: */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-3];
    v232 = (v232 == nil ? lisp_true : nil);
    goto v236;

v236:
    if (v232 == nil) goto v224;
    v232 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v232); }

v224:
    v232 = stack[0];
    stack[-2] = v232;
    goto v237;

v237:
    v232 = stack[-2];
    v232 = qcdr(v232);
    stack[-2] = v232;
    v232 = stack[-2];
    if (v232 == nil) goto v229;
    v232 = stack[-2];
    stack[0] = qcar(v232);
    v232 = stack[-1];
    v232 = sub1(v232);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-3];
    v232 = CC_nbglp(env, stack[0], v232);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-3];
    if (!(v232 == nil)) goto v237;
    v232 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v232); }

v229:
    v232 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v232); }

v234:
    v232 = qvalue(elt(env, 1)); /* t */
    goto v236;

v192:
    v232 = stack[0];
    fn = elt(env, 4); /* baglistp */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v235;
    v232 = (v232 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v232); }
/* error exit handlers */
v235:
    popv(4);
    return nil;
}



/* Code for r2bf */

static Lisp_Object CC_r2bf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v166, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2bf");
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

v256:
    v255 = stack[0];
    if (!consp(v255)) goto v257;
    v166 = stack[0];
    v255 = elt(env, 1); /* !:rd!: */
    if (!consp(v166)) goto v232;
    v166 = qcar(v166);
    if (!(v166 == v255)) goto v232;
    v255 = stack[0];
    v255 = qcdr(v255);
    v255 = (consp(v255) ? nil : lisp_true);
    v255 = (v255 == nil ? lisp_true : nil);
    goto v258;

v258:
    if (!(v255 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v255 = stack[0];
    v255 = qcar(v255);
    if (is_number(v255)) goto v259;
    v166 = stack[0];
    v255 = elt(env, 4); /* quotient */
    if (!consp(v166)) goto v260;
    v166 = qcar(v166);
    if (!(v166 == v255)) goto v260;
    v159 = elt(env, 1); /* !:rd!: */
    v255 = stack[0];
    v255 = qcdr(v255);
    v166 = qcar(v255);
    v255 = (Lisp_Object)1; /* 0 */
    stack[-1] = list2star(v159, v166, v255);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v159 = elt(env, 1); /* !:rd!: */
    v255 = stack[0];
    v255 = qcdr(v255);
    v255 = qcdr(v255);
    v166 = qcar(v255);
    v255 = (Lisp_Object)1; /* 0 */
    v166 = list2star(v159, v166, v255);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v255 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 6); /* divide!: */
    v255 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v166, v255);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v255);
    }

v260:
    v166 = stack[0];
    v255 = elt(env, 5); /* !:rn!: */
    if (!consp(v166)) goto v262;
    v166 = qcar(v166);
    if (!(v166 == v255)) goto v262;
    v255 = stack[0];
    v255 = qcdr(v255);
    stack[0] = v255;
    goto v256;

v262:
    v255 = stack[0];
    v255 = qcdr(v255);
    v255 = qcar(v255);
    stack[0] = v255;
    goto v256;

v259:
    v159 = elt(env, 1); /* !:rd!: */
    v255 = stack[0];
    v166 = qcar(v255);
    v255 = (Lisp_Object)1; /* 0 */
    stack[-1] = list2star(v159, v166, v255);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v159 = elt(env, 1); /* !:rd!: */
    v255 = stack[0];
    v166 = qcdr(v255);
    v255 = (Lisp_Object)1; /* 0 */
    v166 = list2star(v159, v166, v255);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v255 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 6); /* divide!: */
    v255 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v166, v255);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v255);
    }

v232:
    v255 = qvalue(elt(env, 2)); /* nil */
    goto v258;

v257:
    v255 = stack[0];
    v255 = Lfloatp(nil, v255);
    env = stack[-2];
    if (v255 == nil) goto v263;
    v255 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v255);
    }

v263:
    v255 = stack[0];
    if (!consp(v255)) goto v264;
    v255 = stack[0];
    goto v265;

v265:
    {
        popv(3);
        fn = elt(env, 7); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v255);
    }

v264:
    v255 = stack[0];
    v255 = integerp(v255);
    if (v255 == nil) goto v198;
    v159 = elt(env, 1); /* !:rd!: */
    v166 = stack[0];
    v255 = (Lisp_Object)1; /* 0 */
    v255 = list2star(v159, v166, v255);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    goto v265;

v198:
    v255 = stack[0];
    fn = elt(env, 9); /* read!:num */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    goto v265;
/* error exit handlers */
v261:
    popv(3);
    return nil;
}



/* Code for simprad */

static Lisp_Object CC_simprad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v306;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simprad");
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
    stack[0] = v0;
/* end of prologue */
    v129 = qvalue(elt(env, 1)); /* !*reduced */
    if (v129 == nil) goto v182;
    v129 = stack[0];
    v306 = qcar(v129);
    v129 = stack[-3];
    fn = elt(env, 8); /* radfa */
    stack[-1] = (*qfn2(fn))(qenv(fn), v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v129 = stack[0];
    v306 = qcdr(v129);
    v129 = stack[-3];
    fn = elt(env, 8); /* radfa */
    v129 = (*qfn2(fn))(qenv(fn), v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    fn = elt(env, 9); /* invsq */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    {
        Lisp_Object v127 = stack[-1];
        popv(7);
        fn = elt(env, 10); /* multsq */
        return (*qfn2(fn))(qenv(fn), v127, v129);
    }

v182:
    stack[-4] = nil;
    v129 = qvalue(elt(env, 2)); /* !*rationalize */
    if (v129 == nil) goto v308;
    v129 = stack[0];
    v306 = qcdr(v129);
    v129 = (Lisp_Object)17; /* 1 */
    v129 = list2(v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-1] = v129;
    v129 = stack[0];
    stack[-2] = qcar(v129);
    v129 = stack[0];
    stack[0] = qcdr(v129);
    v129 = stack[-3];
    v129 = sub1(v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    fn = elt(env, 11); /* exptf */
    v129 = (*qfn2(fn))(qenv(fn), stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    fn = elt(env, 12); /* multf */
    v306 = (*qfn2(fn))(qenv(fn), stack[-2], v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v129 = (Lisp_Object)17; /* 1 */
    v129 = cons(v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[0] = v129;
    goto v309;

v309:
    v306 = stack[-3];
    v129 = (Lisp_Object)33; /* 2 */
    if (v306 == v129) goto v310;
    v129 = qvalue(elt(env, 3)); /* nil */
    goto v311;

v311:
    if (v129 == nil) goto v312;
    v129 = qvalue(elt(env, 4)); /* t */
    stack[-4] = v129;
    v129 = stack[0];
    v129 = qcar(v129);
    fn = elt(env, 13); /* negf */
    v306 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v129 = stack[-3];
    fn = elt(env, 14); /* radf */
    v129 = (*qfn2(fn))(qenv(fn), v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-2] = v129;
    goto v244;

v244:
    stack[-5] = elt(env, 5); /* quotient */
    v129 = stack[-2];
    v129 = qcdr(v129);
    fn = elt(env, 15); /* retimes */
    stack[0] = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v129 = stack[-1];
    v129 = qcdr(v129);
    fn = elt(env, 15); /* retimes */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v129 = list3(stack[-5], stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    fn = elt(env, 16); /* simp */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-5] = v129;
    v129 = stack[-5];
    v129 = qcar(v129);
    if (!consp(v129)) goto v158;
    v129 = stack[-5];
    v129 = qcar(v129);
    v129 = qcar(v129);
    v129 = (consp(v129) ? nil : lisp_true);
    goto v160;

v160:
    if (v129 == nil) goto v313;
    v129 = stack[-5];
    v129 = qcdr(v129);
    if (!consp(v129)) goto v314;
    v129 = stack[-5];
    v129 = qcdr(v129);
    v129 = qcar(v129);
    v129 = (consp(v129) ? nil : lisp_true);
    goto v315;

v315:
    if (v129 == nil) goto v316;
    v129 = stack[-5];
    v129 = qcar(v129);
    fn = elt(env, 6); /* prepf */
    v306 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v129 = stack[-3];
    fn = elt(env, 17); /* mkrootsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v129 = stack[-5];
    v129 = qcdr(v129);
    fn = elt(env, 6); /* prepf */
    v306 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v129 = stack[-3];
    fn = elt(env, 17); /* mkrootsq */
    v129 = (*qfn2(fn))(qenv(fn), v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    fn = elt(env, 9); /* invsq */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    fn = elt(env, 10); /* multsq */
    v129 = (*qfn2(fn))(qenv(fn), stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-5] = v129;
    goto v317;

v317:
    v129 = qvalue(elt(env, 7)); /* !*precise */
    if (v129 == nil) goto v318;
    v129 = stack[-3];
    v129 = Levenp(nil, v129);
    env = stack[-6];
    if (v129 == nil) goto v318;
    v129 = stack[-2];
    v306 = qcar(v129);
    v129 = (Lisp_Object)17; /* 1 */
    v129 = cons(v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[0] = v129;
    goto v319;

v319:
    v306 = (Lisp_Object)17; /* 1 */
    v129 = stack[-1];
    v129 = qcar(v129);
    v129 = cons(v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    fn = elt(env, 10); /* multsq */
    v306 = (*qfn2(fn))(qenv(fn), stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v129 = stack[-5];
    fn = elt(env, 10); /* multsq */
    v129 = (*qfn2(fn))(qenv(fn), v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-5] = v129;
    v129 = stack[-4];
    if (v129 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    stack[0] = stack[-5];
    v306 = (Lisp_Object)-15; /* -1 */
    v129 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 17); /* mkrootsq */
    v129 = (*qfn2(fn))(qenv(fn), v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    fn = elt(env, 10); /* multsq */
    v129 = (*qfn2(fn))(qenv(fn), stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    stack[-5] = v129;
    { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }

v318:
    v129 = stack[-2];
    v306 = qcar(v129);
    v129 = (Lisp_Object)17; /* 1 */
    v129 = cons(v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[0] = v129;
    goto v319;

v316:
    v129 = stack[-4];
    if (v129 == nil) goto v320;
    v129 = qvalue(elt(env, 3)); /* nil */
    stack[-4] = v129;
    v129 = stack[-5];
    v129 = qcar(v129);
    fn = elt(env, 13); /* negf */
    v306 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v129 = stack[-5];
    v129 = qcdr(v129);
    v129 = cons(v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-5] = v129;
    goto v320;

v320:
    v129 = stack[-5];
    v129 = qcar(v129);
    if (v129 == nil) goto v321;
    v306 = stack[-5];
    v129 = elt(env, 6); /* prepf */
    fn = elt(env, 18); /* sqform */
    v129 = (*qfn2(fn))(qenv(fn), v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v306 = v129;
    goto v145;

v145:
    v129 = stack[-3];
    fn = elt(env, 17); /* mkrootsq */
    v129 = (*qfn2(fn))(qenv(fn), v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-5] = v129;
    goto v317;

v321:
    v129 = (Lisp_Object)1; /* 0 */
    v306 = v129;
    goto v145;

v314:
    v129 = qvalue(elt(env, 4)); /* t */
    goto v315;

v313:
    v129 = qvalue(elt(env, 3)); /* nil */
    goto v315;

v158:
    v129 = qvalue(elt(env, 4)); /* t */
    goto v160;

v312:
    v129 = stack[0];
    v306 = qcar(v129);
    v129 = stack[-3];
    fn = elt(env, 14); /* radf */
    v129 = (*qfn2(fn))(qenv(fn), v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-2] = v129;
    goto v244;

v310:
    v129 = stack[0];
    v129 = qcar(v129);
    fn = elt(env, 19); /* minusf */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    goto v311;

v308:
    v129 = stack[0];
    v306 = qcdr(v129);
    v129 = stack[-3];
    fn = elt(env, 14); /* radf */
    v129 = (*qfn2(fn))(qenv(fn), v306, v129);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-1] = v129;
    goto v309;
/* error exit handlers */
v307:
    popv(7);
    return nil;
}



/* Code for get!-new!-prime */

static Lisp_Object CC_getKnewKprime(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v259, v308;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-new-prime");
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
    v259 = qvalue(elt(env, 1)); /* !*force!-prime */
    if (v259 == nil) goto v327;
    v259 = qvalue(elt(env, 1)); /* !*force!-prime */
    { popv(5); return onevalue(v259); }

v327:
    stack[-3] = nil;
    v259 = stack[-2];
    stack[-1] = v259;
    goto v263;

v263:
    v259 = stack[-1];
    if (v259 == nil) goto v303;
    v259 = stack[-1];
    v259 = qcar(v259);
    stack[0] = v259;
    v308 = stack[0];
    v259 = (Lisp_Object)513; /* 32 */
    v259 = (Lisp_Object)lessp2(v308, v259);
    nil = C_nil;
    if (exception_pending()) goto v176;
    v259 = v259 ? lisp_true : nil;
    env = stack[-4];
    if (v259 == nil) goto v328;
    v308 = stack[0];
    v259 = stack[-3];
    v259 = cons(v308, v259);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    stack[-3] = v259;
    goto v328;

v328:
    v259 = stack[-1];
    v259 = qcdr(v259);
    stack[-1] = v259;
    goto v263;

v303:
    v259 = stack[-3];
    fn = elt(env, 4); /* random!-teeny!-prime */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    stack[0] = v259;
    if (v259 == nil) goto v230;
    v308 = stack[0];
    v259 = stack[-3];
    v259 = cons(v308, v259);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    stack[-3] = v259;
    goto v329;

v329:
    v308 = stack[0];
    v259 = stack[-2];
    v259 = Lmember(nil, v308, v259);
    if (v259 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    else goto v303;

v230:
    fn = elt(env, 5); /* random!-small!-prime */
    v259 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    stack[0] = v259;
    v259 = elt(env, 3); /* all */
    stack[-3] = v259;
    goto v329;
/* error exit handlers */
v176:
    popv(5);
    return nil;
}



/* Code for pseudo!-remainder */

static Lisp_Object CC_pseudoKremainder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225, v303, v326;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pseudo-remainder");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v225 = v0;
/* end of prologue */
    v326 = v225;
    v303 = elt(env, 1); /* remainder */
    v225 = qvalue(elt(env, 2)); /* t */
    {
        fn = elt(env, 3); /* poly!-divide!* */
        return (*qfnn(fn))(qenv(fn), 3, v326, v303, v225);
    }
}



/* Code for ofsf_decdeg2 */

static Lisp_Object CC_ofsf_decdeg2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v289, v316, v341;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_decdeg2");
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
    stack[-3] = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    stack[-1] = nil;
    v289 = (Lisp_Object)1; /* 0 */
    stack[0] = v289;
    v289 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v289; /* !*gcd */
    v289 = qvalue(elt(env, 3)); /* !*rlbrkcxk */
    if (v289 == nil) goto v303;
    v316 = stack[-3];
    v289 = stack[-4];
    fn = elt(env, 6); /* ofsf_cxkdgcd */
    v289 = (*qfn2(fn))(qenv(fn), v316, v289);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-6];
    stack[0] = v289;
    goto v303;

v303:
    v289 = stack[-3];
    fn = elt(env, 7); /* cl_atl1 */
    v289 = (*qfn1(fn))(qenv(fn), v289);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-6];
    stack[-3] = v289;
    goto v328;

v328:
    v289 = stack[-3];
    if (v289 == nil) goto v343;
    v316 = stack[0];
    v289 = (Lisp_Object)17; /* 1 */
    v289 = Leqn(nil, v316, v289);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-6];
    if (!(v289 == nil)) goto v343;
    v289 = stack[-3];
    v289 = qcar(v289);
    v316 = v289;
    v289 = stack[-3];
    v289 = qcdr(v289);
    stack[-3] = v289;
    v289 = v316;
    stack[-5] = v289;
    v316 = stack[-5];
    v289 = stack[-4];
    fn = elt(env, 8); /* ofsf_ignshift */
    v289 = (*qfn2(fn))(qenv(fn), v316, v289);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-6];
    v341 = v289;
    v316 = v341;
    v289 = elt(env, 5); /* odd */
    if (v316 == v289) goto v235;
    v289 = qvalue(elt(env, 4)); /* nil */
    goto v300;

v300:
    if (v289 == nil) goto v344;
    v289 = elt(env, 5); /* odd */
    stack[-1] = v289;
    goto v345;

v345:
    v316 = stack[0];
    v289 = (Lisp_Object)1; /* 0 */
    v289 = (Lisp_Object)greaterp2(v316, v289);
    nil = C_nil;
    if (exception_pending()) goto v342;
    v289 = v289 ? lisp_true : nil;
    env = stack[-6];
    if (v289 == nil) goto v328;
    v316 = stack[-1];
    v289 = elt(env, 5); /* odd */
    if (!(v316 == v289)) goto v328;
    v289 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v289;
    goto v346;

v346:
    v316 = stack[0];
    v289 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 9); /* quotf */
    v289 = (*qfn2(fn))(qenv(fn), v316, v289);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-6];
    v341 = v289;
    if (v289 == nil) goto v328;
    v289 = v341;
    stack[0] = v289;
    goto v346;

v344:
    v289 = v341;
    if (!(v289 == nil)) goto v345;
    v289 = stack[-5];
    v289 = qcdr(v289);
    v316 = qcar(v289);
    v289 = stack[-4];
    fn = elt(env, 10); /* sfto_reorder */
    v289 = (*qfn2(fn))(qenv(fn), v316, v289);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-6];
    stack[-5] = v289;
    goto v309;

v309:
    v289 = stack[-5];
    if (!consp(v289)) goto v17;
    v289 = stack[-5];
    v289 = qcar(v289);
    v289 = (consp(v289) ? nil : lisp_true);
    goto v347;

v347:
    if (v289 == nil) goto v348;
    v289 = qvalue(elt(env, 4)); /* nil */
    goto v247;

v247:
    if (v289 == nil) goto v345;
    v316 = stack[0];
    v289 = stack[-5];
    v289 = qcar(v289);
    v289 = qcar(v289);
    v289 = qcdr(v289);
    fn = elt(env, 11); /* gcdf */
    v289 = (*qfn2(fn))(qenv(fn), v316, v289);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-6];
    stack[0] = v289;
    v289 = stack[-5];
    v289 = qcdr(v289);
    stack[-5] = v289;
    goto v309;

v348:
    v289 = stack[-5];
    v289 = qcar(v289);
    v289 = qcar(v289);
    v316 = qcar(v289);
    v289 = stack[-4];
    if (v316 == v289) goto v349;
    v289 = qvalue(elt(env, 4)); /* nil */
    goto v247;

v349:
    v316 = stack[0];
    v289 = (Lisp_Object)17; /* 1 */
    v289 = Lneq(nil, v316, v289);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-6];
    goto v247;

v17:
    v289 = qvalue(elt(env, 2)); /* t */
    goto v347;

v235:
    v289 = stack[-1];
    v289 = (v289 == nil ? lisp_true : nil);
    goto v300;

v343:
    v316 = stack[0];
    v289 = (Lisp_Object)1; /* 0 */
    if (v316 == v289) goto v291;
    v289 = stack[0];
    goto v186;

v186:
    qvalue(elt(env, 1)) = stack[-2]; /* !*gcd */
    { popv(7); return onevalue(v289); }

v291:
    v289 = (Lisp_Object)17; /* 1 */
    goto v186;
/* error exit handlers */
v342:
    env = stack[-6];
    qvalue(elt(env, 1)) = stack[-2]; /* !*gcd */
    popv(7);
    return nil;
}



/* Code for tildepri */

static Lisp_Object CC_tildepri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v327;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tildepri");
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
    v327 = elt(env, 1); /* "~" */
    fn = elt(env, 2); /* prin2!* */
    v327 = (*qfn1(fn))(qenv(fn), v327);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-1];
    v327 = stack[0];
    v327 = qcdr(v327);
    v327 = qcar(v327);
    {
        popv(2);
        fn = elt(env, 2); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v327);
    }
/* error exit handlers */
v186:
    popv(2);
    return nil;
}



/* Code for evalletsub2 */

static Lisp_Object CC_evalletsub2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v222, v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalletsub2");
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
    v183 = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* newrule!* */
    qvalue(elt(env, 1)) = nil; /* newrule!* */
    stack[-2] = qvalue(elt(env, 2)); /* oldrules!* */
    qvalue(elt(env, 2)) = nil; /* oldrules!* */
    stack[-1] = qvalue(elt(env, 3)); /* props!* */
    qvalue(elt(env, 3)) = nil; /* props!* */
    v222 = stack[-3];
    v222 = qcar(v222);
    fn = elt(env, 6); /* set_rules */
    v183 = (*qfn2(fn))(qenv(fn), v222, v183);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[0] = v183;
    v183 = stack[-3];
    v183 = qcdr(v183);
    v223 = qcar(v183);
    v222 = qvalue(elt(env, 4)); /* nil */
    v183 = qvalue(elt(env, 5)); /* !*backtrace */
    fn = elt(env, 7); /* errorset */
    v183 = (*qfnn(fn))(qenv(fn), 3, v223, v222, v183);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[-3] = v183;
    v183 = stack[0];
    fn = elt(env, 8); /* restore_rules */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v183 = stack[-3];
    qvalue(elt(env, 3)) = stack[-1]; /* props!* */
    qvalue(elt(env, 2)) = stack[-2]; /* oldrules!* */
    qvalue(elt(env, 1)) = stack[-4]; /* newrule!* */
    { popv(6); return onevalue(v183); }
/* error exit handlers */
v198:
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[-1]; /* props!* */
    qvalue(elt(env, 2)) = stack[-2]; /* oldrules!* */
    qvalue(elt(env, 1)) = stack[-4]; /* newrule!* */
    popv(6);
    return nil;
}



/* Code for qqe_simplqequal */

static Lisp_Object CC_qqe_simplqequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v384, v385, v386;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplqequal");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v384 = v1;
    stack[0] = v0;
/* end of prologue */

v387:
    v384 = stack[0];
    fn = elt(env, 7); /* qqe_arg2r */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    stack[-7] = v384;
    v384 = stack[0];
    fn = elt(env, 8); /* qqe_arg2l */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    stack[-8] = v384;
    v385 = stack[-7];
    v384 = stack[-8];
    if (equal(v385, v384)) goto v234;
    v384 = stack[-8];
    fn = elt(env, 9); /* qqe_qprefix!-var */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    stack[-6] = v384;
    v384 = stack[-7];
    fn = elt(env, 9); /* qqe_qprefix!-var */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    stack[-5] = v384;
    v385 = stack[-6];
    v384 = stack[-5];
    if (v385 == v384) goto v185;
    v385 = stack[-6];
    v384 = elt(env, 3); /* qepsilon */
    if (v385 == v384) goto v389;
    v385 = stack[-5];
    v384 = elt(env, 3); /* qepsilon */
    v384 = (v385 == v384 ? lisp_true : nil);
    goto v184;

v184:
    if (v384 == nil) goto v223;
    v384 = stack[-7];
    fn = elt(env, 10); /* qqe_number!-of!-adds!-in!-qterm */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    stack[-3] = v384;
    v384 = stack[-8];
    fn = elt(env, 10); /* qqe_number!-of!-adds!-in!-qterm */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    stack[-4] = v384;
    v384 = stack[-7];
    fn = elt(env, 11); /* qqe_number!-of!-tails!-in!-qterm */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    stack[-1] = v384;
    v384 = stack[-8];
    fn = elt(env, 11); /* qqe_number!-of!-tails!-in!-qterm */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    stack[-2] = v384;
    v385 = stack[-6];
    v384 = stack[-5];
    if (v385 == v384) goto v250;
    v384 = qvalue(elt(env, 4)); /* nil */
    goto v176;

v176:
    if (v384 == nil) goto v390;
    v384 = elt(env, 5); /* false */
    { popv(10); return onevalue(v384); }

v390:
    v385 = stack[-7];
    v384 = elt(env, 3); /* qepsilon */
    if (v385 == v384) goto v262;
    v384 = qvalue(elt(env, 4)); /* nil */
    goto v292;

v292:
    if (v384 == nil) goto v391;
    v384 = elt(env, 5); /* false */
    { popv(10); return onevalue(v384); }

v391:
    v385 = stack[-8];
    v384 = elt(env, 3); /* qepsilon */
    if (v385 == v384) goto v392;
    v384 = qvalue(elt(env, 4)); /* nil */
    goto v393;

v393:
    if (v384 == nil) goto v155;
    v384 = elt(env, 5); /* false */
    { popv(10); return onevalue(v384); }

v155:
    v385 = stack[-7];
    v384 = elt(env, 3); /* qepsilon */
    if (v385 == v384) goto v394;
    v384 = qvalue(elt(env, 4)); /* nil */
    goto v343;

v343:
    if (v384 == nil) goto v140;
    v385 = stack[-6];
    v384 = elt(env, 3); /* qepsilon */
    if (v385 == v384) goto v321;
    v384 = stack[-8];
    fn = elt(env, 12); /* qqe_simplterm */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    v385 = elt(env, 6); /* qequal */
    v386 = v384;
    v384 = stack[-7];
    {
        popv(10);
        fn = elt(env, 13); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v385, v386, v384);
    }

v321:
    v384 = elt(env, 1); /* true */
    { popv(10); return onevalue(v384); }

v140:
    v385 = stack[-8];
    v384 = elt(env, 3); /* qepsilon */
    if (v385 == v384) goto v395;
    v384 = qvalue(elt(env, 4)); /* nil */
    goto v396;

v396:
    if (v384 == nil) goto v223;
    v385 = stack[-5];
    v384 = elt(env, 3); /* qepsilon */
    if (v385 == v384) goto v272;
    v384 = stack[-7];
    fn = elt(env, 12); /* qqe_simplterm */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    stack[0] = v384;
    v386 = elt(env, 6); /* qequal */
    v385 = stack[-8];
    v384 = stack[0];
    {
        popv(10);
        fn = elt(env, 13); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v386, v385, v384);
    }

v272:
    v384 = elt(env, 1); /* true */
    { popv(10); return onevalue(v384); }

v223:
    v384 = stack[-7];
    fn = elt(env, 12); /* qqe_simplterm */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    stack[0] = v384;
    v384 = stack[-8];
    fn = elt(env, 12); /* qqe_simplterm */
    v384 = (*qfn1(fn))(qenv(fn), v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    v386 = stack[-7];
    v385 = stack[0];
    if (equal(v386, v385)) goto v397;
    v385 = qvalue(elt(env, 4)); /* nil */
    goto v398;

v398:
    if (v385 == nil) goto v115;
    v386 = elt(env, 6); /* qequal */
    v385 = v384;
    v384 = stack[0];
    {
        popv(10);
        fn = elt(env, 13); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v386, v385, v384);
    }

v115:
    v386 = elt(env, 6); /* qequal */
    v385 = v384;
    v384 = stack[0];
    fn = elt(env, 13); /* qqe_mk2 */
    v384 = (*qfnn(fn))(qenv(fn), 3, v386, v385, v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    stack[0] = v384;
    goto v387;

v397:
    v386 = stack[-8];
    v385 = v384;
    v385 = (equal(v386, v385) ? lisp_true : nil);
    goto v398;

v395:
    v385 = stack[-3];
    v384 = (Lisp_Object)1; /* 0 */
    if (v385 == v384) goto v399;
    v384 = qvalue(elt(env, 4)); /* nil */
    goto v396;

v399:
    v385 = stack[-4];
    v384 = (Lisp_Object)1; /* 0 */
    v384 = (v385 == v384 ? lisp_true : nil);
    goto v396;

v394:
    v385 = stack[-3];
    v384 = (Lisp_Object)1; /* 0 */
    if (v385 == v384) goto v400;
    v384 = qvalue(elt(env, 4)); /* nil */
    goto v343;

v400:
    v385 = stack[-4];
    v384 = (Lisp_Object)1; /* 0 */
    v384 = (v385 == v384 ? lisp_true : nil);
    goto v343;

v392:
    v385 = stack[-3];
    v384 = stack[-1];
    v384 = (Lisp_Object)greaterp2(v385, v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    v384 = v384 ? lisp_true : nil;
    env = stack[-9];
    goto v393;

v262:
    v385 = stack[-4];
    v384 = stack[-2];
    v384 = (Lisp_Object)greaterp2(v385, v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    v384 = v384 ? lisp_true : nil;
    env = stack[-9];
    goto v292;

v250:
    v385 = stack[-3];
    v384 = stack[-1];
    v384 = (Lisp_Object)geq2(v385, v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    v384 = v384 ? lisp_true : nil;
    env = stack[-9];
    if (!(v384 == nil)) goto v401;
    v385 = stack[-4];
    v384 = stack[-2];
    v384 = (Lisp_Object)geq2(v385, v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    v384 = v384 ? lisp_true : nil;
    env = stack[-9];
    if (!(v384 == nil)) goto v401;
    v384 = qvalue(elt(env, 4)); /* nil */
    goto v176;

v401:
    v385 = stack[-3];
    v384 = stack[-1];
    stack[0] = difference2(v385, v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    v385 = stack[-4];
    v384 = stack[-2];
    v384 = difference2(v385, v384);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[-9];
    v384 = (equal(stack[0], v384) ? lisp_true : nil);
    v384 = (v384 == nil ? lisp_true : nil);
    goto v176;

v389:
    v384 = qvalue(elt(env, 2)); /* t */
    goto v184;

v185:
    v384 = qvalue(elt(env, 2)); /* t */
    goto v184;

v234:
    v384 = elt(env, 1); /* true */
    { popv(10); return onevalue(v384); }
/* error exit handlers */
v388:
    popv(10);
    return nil;
}



/* Code for pasf_leqp */

static Lisp_Object CC_pasf_leqp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v402, v175, v176, v201;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_leqp");
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
    v175 = v1;
    v176 = v0;
/* end of prologue */
    v402 = v176;
    if (!(v402 == nil)) goto v331;
    v402 = (Lisp_Object)1; /* 0 */
    v176 = v402;
    goto v331;

v331:
    v402 = v175;
    if (!(v402 == nil)) goto v187;
    v402 = (Lisp_Object)1; /* 0 */
    v175 = v402;
    goto v187;

v187:
    v201 = v176;
    v402 = elt(env, 1); /* minf */
    if (v201 == v402) goto v304;
    v201 = v175;
    v402 = elt(env, 3); /* pinf */
    if (v201 == v402) goto v237;
    v201 = v176;
    v402 = elt(env, 3); /* pinf */
    if (v201 == v402) goto v259;
    v201 = v175;
    v402 = elt(env, 1); /* minf */
    if (v201 == v402) goto v299;
    v402 = v176;
    v402 = (Lisp_Object)lesseq2(v402, v175);
    nil = C_nil;
    if (exception_pending()) goto v298;
    v402 = v402 ? lisp_true : nil;
    env = stack[0];
    goto v265;

v265:
    if (v402 == nil) goto v236;
    v402 = qvalue(elt(env, 2)); /* t */
    { popv(1); return onevalue(v402); }

v236:
    v402 = nil;
    { popv(1); return onevalue(v402); }

v299:
    v402 = qvalue(elt(env, 4)); /* nil */
    goto v265;

v259:
    v402 = qvalue(elt(env, 4)); /* nil */
    goto v265;

v237:
    v402 = qvalue(elt(env, 2)); /* t */
    goto v265;

v304:
    v402 = qvalue(elt(env, 2)); /* t */
    goto v265;
/* error exit handlers */
v298:
    popv(1);
    return nil;
}



/* Code for infinp */

static Lisp_Object CC_infinp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v195;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for infinp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v186 = v0;
/* end of prologue */
    v195 = elt(env, 1); /* (infinity (minus infinity)) */
    v186 = Lmember(nil, v186, v195);
    return onevalue(v186);
}



/* Code for prload */

static Lisp_Object MS_CDECL CC_prload(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v403;
    argcheck(nargs, 0, "prload");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prload");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v403 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v403);
}



/* Code for fnewsym */

static Lisp_Object MS_CDECL CC_fnewsym(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fnewsym");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnewsym");
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
    v184 = elt(env, 1); /* newsym */
    fn = elt(env, 3); /* getd */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    if (v184 == nil) goto v195;
    fn = elt(env, 1); /* newsym */
    v184 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    stack[-1] = v184;
    goto v192;

v192:
    v184 = stack[-1];
    v184 = Lintern(nil, v184);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    stack[-1] = v184;
    v184 = stack[-1];
    v185 = ncons(v184);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    v184 = elt(env, 1); /* newsym */
    v184 = Lflag(nil, v185, v184);
    nil = C_nil;
    if (exception_pending()) goto v196;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v195:
    v184 = elt(env, 2); /* g */
    v184 = Lgensym1(nil, v184);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    stack[-1] = v184;
    v184 = stack[-1];
    fn = elt(env, 4); /* letterpart */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    stack[0] = Lexplode(nil, v184);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    v184 = stack[-1];
    fn = elt(env, 5); /* digitpart */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    v184 = Lexplode(nil, v184);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    v184 = Lappend(nil, stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    v184 = Lcompress(nil, v184);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    stack[-1] = v184;
    goto v192;
/* error exit handlers */
v196:
    popv(3);
    return nil;
}



/* Code for nesttimes!: */

static Lisp_Object CC_nesttimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v303, v326, v351;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nesttimes:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v303 = v1;
    v326 = v0;
/* end of prologue */
    v351 = v326;
    v326 = v303;
    v303 = elt(env, 1); /* multsq */
    {
        fn = elt(env, 2); /* nest2op!: */
        return (*qfnn(fn))(qenv(fn), 3, v351, v326, v303);
    }
}



/* Code for evalsymsubset */

static Lisp_Object CC_evalsymsubset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v407, v408, v296, v348;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalsymsubset");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v407 = v0;
/* end of prologue */
    v408 = v407;
    v408 = qcar(v408);
    v407 = qcdr(v407);
    v407 = qcar(v407);
    v348 = v408;
    v296 = v407;
    v408 = v296;
    v407 = elt(env, 1); /* union */
    if (!consp(v408)) goto v182;
    v408 = qcar(v408);
    if (!(v408 == v407)) goto v182;
    v408 = v348;
    v407 = v296;
    v407 = qcdr(v407);
    v407 = Lmember(nil, v408, v407);
    goto v225;

v225:
    if (!(v407 == nil)) return onevalue(v407);
    v408 = v348;
    v407 = elt(env, 3); /* intersection */
    if (!consp(v408)) goto v177;
    v408 = qcar(v408);
    if (!(v408 == v407)) goto v177;
    v408 = v296;
    v407 = v348;
    v407 = qcdr(v407);
    v407 = Lmember(nil, v408, v407);
    goto v184;

v184:
    if (!(v407 == nil)) return onevalue(v407);
    v408 = v348;
    v407 = elt(env, 4); /* setdiff */
    if (!consp(v408)) goto v3;
    v408 = qcar(v408);
    if (!(v408 == v407)) goto v3;
    v407 = v348;
    v407 = qcdr(v407);
    v408 = qcar(v407);
    v407 = v296;
    if (equal(v408, v407)) goto v301;
    v408 = v296;
    v407 = elt(env, 1); /* union */
    if (!consp(v408)) goto v148;
    v408 = qcar(v408);
    if (!(v408 == v407)) goto v148;
    v407 = v348;
    v407 = qcdr(v407);
    v407 = qcar(v407);
    v408 = v296;
    v408 = qcdr(v408);
    v407 = Lmember(nil, v407, v408);
    return onevalue(v407);

v148:
    v407 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v407);

v301:
    v407 = qvalue(elt(env, 5)); /* t */
    return onevalue(v407);

v3:
    v407 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v407);

v177:
    v407 = qvalue(elt(env, 2)); /* nil */
    goto v184;

v182:
    v407 = qvalue(elt(env, 2)); /* nil */
    goto v225;
}



/* Code for mo!=expvec2a1 */

static Lisp_Object CC_moMexpvec2a1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v301, v322, v299;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=expvec2a1");
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
    goto v331;

v331:
    v301 = stack[-1];
    if (v301 == nil) goto v330;
    v301 = stack[-1];
    v322 = qcar(v301);
    v301 = (Lisp_Object)1; /* 0 */
    if (v322 == v301) goto v303;
    v301 = stack[-1];
    v322 = qcar(v301);
    v301 = (Lisp_Object)17; /* 1 */
    if (v322 == v301) goto v254;
    v299 = elt(env, 1); /* expt */
    v301 = stack[0];
    v322 = qcar(v301);
    v301 = stack[-1];
    v301 = qcar(v301);
    v322 = list3(v299, v322, v301);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-3];
    v301 = stack[-2];
    v301 = cons(v322, v301);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-3];
    stack[-2] = v301;
    v301 = stack[-1];
    v301 = qcdr(v301);
    stack[-1] = v301;
    v301 = stack[0];
    v301 = qcdr(v301);
    stack[0] = v301;
    goto v331;

v254:
    v301 = stack[0];
    v322 = qcar(v301);
    v301 = stack[-2];
    v301 = cons(v322, v301);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-3];
    stack[-2] = v301;
    v301 = stack[-1];
    v301 = qcdr(v301);
    stack[-1] = v301;
    v301 = stack[0];
    v301 = qcdr(v301);
    stack[0] = v301;
    goto v331;

v303:
    v301 = stack[-1];
    v301 = qcdr(v301);
    stack[-1] = v301;
    v301 = stack[0];
    v301 = qcdr(v301);
    stack[0] = v301;
    goto v331;

v330:
    v301 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v301);
    }
/* error exit handlers */
v308:
    popv(4);
    return nil;
}



/* Code for monicmember */

static Lisp_Object CC_monicmember(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v403)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v222, v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monicmember");
#endif
    if (stack >= stacklimit)
    {
        push2(v403,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v403);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v403;
    v222 = v1;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v222; /* gg */
    goto v195;

v195:
    v222 = qvalue(elt(env, 1)); /* gg */
    if (v222 == nil) goto v303;
    v222 = qvalue(elt(env, 1)); /* gg */
    v222 = qcar(v222);
    v223 = qcdr(v222);
    v222 = stack[0];
    fn = elt(env, 4); /* monic */
    v222 = (*qfn2(fn))(qenv(fn), v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-2];
    if (v222 == nil) goto v231;
    v222 = qvalue(elt(env, 3)); /* t */
    goto v331;

v331:
    qvalue(elt(env, 1)) = stack[-1]; /* gg */
    { popv(3); return onevalue(v222); }

v231:
    v222 = qvalue(elt(env, 1)); /* gg */
    v222 = qcdr(v222);
    qvalue(elt(env, 1)) = v222; /* gg */
    goto v195;

v303:
    v222 = qvalue(elt(env, 2)); /* nil */
    goto v331;
/* error exit handlers */
v254:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* gg */
    popv(3);
    return nil;
}



/* Code for idcompare */

static Lisp_Object CC_idcompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idcompare");
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
    v225 = v0;
/* end of prologue */
    stack[-1] = Lexplodec(nil, v225);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-2];
    v225 = stack[0];
    v225 = Lexplodec(nil, v225);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-2];
    {
        Lisp_Object v352 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* idcomp1 */
        return (*qfn2(fn))(qenv(fn), v352, v225);
    }
/* error exit handlers */
v351:
    popv(3);
    return nil;
}



/* Code for make!-image!-lc!-list1 */

static Lisp_Object MS_CDECL CC_makeKimageKlcKlist1(Lisp_Object env, int nargs,
                         Lisp_Object v1, Lisp_Object v403,
                         Lisp_Object v336, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v245, v240, v337, v338;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "make-image-lc-list1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-image-lc-list1");
#endif
    if (stack >= stacklimit)
    {
        push3(v336,v403,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v1,v403,v336);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v245 = v336;
    stack[-1] = v403;
    v244 = v1;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v245; /* varlist */
    goto v195;

v195:
    v245 = stack[-1];
    if (v245 == nil) goto v303;
    v245 = v244;
    if (!consp(v245)) goto v265;
    v245 = v244;
    v245 = qcar(v245);
    v245 = (consp(v245) ? nil : lisp_true);
    goto v234;

v234:
    if (v245 == nil) goto v196;
    fn = elt(env, 5); /* !*d2n */
    v245 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-3];
    v244 = qvalue(elt(env, 1)); /* varlist */
    v244 = qcdr(v244);
    v244 = cons(v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-3];
    v244 = ncons(v244);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-3];
    goto v257;

v257:
    qvalue(elt(env, 1)) = stack[-2]; /* varlist */
    { popv(4); return onevalue(v244); }

v196:
    v245 = v244;
    v245 = qcar(v245);
    v245 = qcar(v245);
    v240 = qcar(v245);
    v245 = stack[-1];
    v245 = qcar(v245);
    v245 = qcar(v245);
    if (equal(v240, v245)) goto v344;
    v245 = stack[-1];
    v245 = qcdr(v245);
    stack[-1] = v245;
    v245 = qvalue(elt(env, 1)); /* varlist */
    v245 = qcdr(v245);
    qvalue(elt(env, 1)) = v245; /* varlist */
    goto v195;

v344:
    v338 = v244;
    v245 = stack[-1];
    v245 = qcar(v245);
    v337 = qcar(v245);
    v245 = stack[-1];
    v245 = qcar(v245);
    v240 = qcdr(v245);
    v245 = qvalue(elt(env, 4)); /* polyzero */
    v244 = qcar(v244);
    v244 = qcar(v244);
    v244 = qcdr(v244);
    fn = elt(env, 6); /* horner!-rule!-for!-one!-var */
    v245 = (*qfnn(fn))(qenv(fn), 5, v338, v337, v240, v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-3];
    v244 = qvalue(elt(env, 1)); /* varlist */
    v244 = qcdr(v244);
    v244 = cons(v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-3];
    v245 = v244;
    v245 = qcar(v245);
    if (v245 == nil) goto v309;
    stack[0] = v244;
    v240 = qcar(v244);
    v244 = stack[-1];
    v245 = qcdr(v244);
    v244 = qvalue(elt(env, 1)); /* varlist */
    v244 = qcdr(v244);
    v244 = CC_makeKimageKlcKlist1(env, 3, v240, v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-3];
    v244 = cons(stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-3];
    goto v257;

v309:
    v245 = (Lisp_Object)1; /* 0 */
    v244 = qcdr(v244);
    v244 = cons(v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-3];
    v244 = ncons(v244);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-3];
    goto v257;

v265:
    v245 = qvalue(elt(env, 3)); /* t */
    goto v234;

v303:
    v244 = qvalue(elt(env, 2)); /* nil */
    goto v257;
/* error exit handlers */
v294:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* varlist */
    popv(4);
    return nil;
}



/* Code for cl_get */

static Lisp_Object CC_cl_get(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225, v303;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_get");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v303 = v0;
/* end of prologue */
    v225 = qvalue(elt(env, 1)); /* !*rlqedfs */
    if (v225 == nil) goto v330;
    v225 = v303;
    {
        fn = elt(env, 2); /* cl_pop */
        return (*qfn1(fn))(qenv(fn), v225);
    }

v330:
    v225 = v303;
    {
        fn = elt(env, 3); /* cl_dequeue */
        return (*qfn1(fn))(qenv(fn), v225);
    }
}



/* Code for get_recursive_kernels */

static Lisp_Object CC_get_recursive_kernels(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v303, v326, v351;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_recursive_kernels");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v303 = v1;
    v326 = v0;
/* end of prologue */
    v351 = v326;
    v326 = v303;
    v303 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* grk */
        return (*qfnn(fn))(qenv(fn), 3, v351, v326, v303);
    }
}



/* Code for lrootchk */

static Lisp_Object CC_lrootchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lrootchk");
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

v387:
    v224 = stack[-1];
    if (v224 == nil) goto v192;
    v224 = stack[-1];
    v182 = qcar(v224);
    v224 = stack[0];
    fn = elt(env, 2); /* krootchk */
    v224 = (*qfn2(fn))(qenv(fn), v182, v224);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-2];
    if (!(v224 == nil)) { popv(3); return onevalue(v224); }
    v224 = stack[-1];
    v182 = qcdr(v224);
    v224 = stack[0];
    stack[-1] = v182;
    stack[0] = v224;
    goto v387;

v192:
    v224 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v224); }
/* error exit handlers */
v223:
    popv(3);
    return nil;
}



/* Code for addto!-all!-taytpelorders */

static Lisp_Object CC_addtoKallKtaytpelorders(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v381;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addto-all-taytpelorders");
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
    stack[-5] = nil;
    goto v331;

v331:
    v178 = stack[-4];
    if (v178 == nil) goto v330;
    v178 = stack[-4];
    v178 = qcar(v178);
    stack[-2] = qcar(v178);
    v178 = stack[-4];
    v178 = qcar(v178);
    v178 = qcdr(v178);
    stack[-1] = qcar(v178);
    v178 = stack[-4];
    v178 = qcar(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v381 = qcar(v178);
    v178 = stack[-3];
    v178 = qcar(v178);
    fn = elt(env, 1); /* tayexp!-plus2 */
    stack[0] = (*qfn2(fn))(qenv(fn), v381, v178);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-6];
    v178 = stack[-4];
    v178 = qcar(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v178 = qcdr(v178);
    v381 = qcar(v178);
    v178 = stack[-3];
    v178 = qcar(v178);
    fn = elt(env, 1); /* tayexp!-plus2 */
    v178 = (*qfn2(fn))(qenv(fn), v381, v178);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-6];
    v381 = list4(stack[-2], stack[-1], stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-6];
    v178 = stack[-5];
    v178 = cons(v381, v178);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-6];
    stack[-5] = v178;
    v178 = stack[-4];
    v178 = qcdr(v178);
    stack[-4] = v178;
    v178 = stack[-3];
    v178 = qcdr(v178);
    stack[-3] = v178;
    goto v331;

v330:
    v178 = stack[-5];
    {
        popv(7);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v178);
    }
/* error exit handlers */
v299:
    popv(7);
    return nil;
}



/* Code for qqe_length!-graph!-remove!-mark */

static Lisp_Object CC_qqe_lengthKgraphKremoveKmark(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v325, v350, v328, v305;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_length-graph-remove-mark");
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
    v328 = v1;
    v325 = v0;
/* end of prologue */
    v305 = v325;
    goto v331;

v331:
    v325 = v305;
    if (v325 == nil) goto v186;
    v325 = v305;
    v325 = qcar(v325);
    v350 = v325;
    v325 = v328;
    v325 = Lremprop(nil, v350, v325);
    env = stack[0];
    v325 = v305;
    v325 = qcdr(v325);
    v305 = v325;
    goto v331;

v186:
    v325 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v325); }
}



/* Code for cl_applysac2 */

static Lisp_Object MS_CDECL CC_cl_applysac2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v403, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v293, v160, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_applysac2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_applysac2");
#endif
    if (stack >= stacklimit)
    {
        push3(v403,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v403);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v403;
    v160 = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    v293 = v160;
    if (v293 == nil) goto v326;
    v293 = v160;
    stack[0] = v293;
    goto v187;

v187:
    v293 = stack[0];
    if (v293 == nil) goto v264;
    v158 = stack[-2];
    v293 = stack[0];
    v160 = qcar(v293);
    v293 = stack[-1];
    fn = elt(env, 7); /* cl_subandcut */
    v160 = (*qfnn(fn))(qenv(fn), 3, v158, v160, v293);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    stack[-3] = v160;
    v293 = elt(env, 2); /* keep1 */
    if (!(v160 == v293)) goto v264;
    v293 = stack[0];
    v293 = qcdr(v293);
    stack[0] = v293;
    goto v187;

v264:
    v293 = stack[-3];
    if (v293 == nil) goto v174;
    v293 = stack[0];
    if (v293 == nil) goto v323;
    v160 = stack[-3];
    v293 = elt(env, 5); /* keep2 */
    if (v160 == v293) goto v402;
    v160 = stack[-3];
    v293 = elt(env, 6); /* failed */
    if (v160 == v293) goto v3;
    v158 = qvalue(elt(env, 3)); /* nil */
    v160 = stack[-3];
    v293 = stack[0];
    v293 = qcdr(v293);
    popv(5);
    return acons(v158, v160, v293);

v3:
    v158 = stack[-2];
    v293 = stack[0];
    v160 = qcdr(v293);
    v293 = stack[-1];
    v293 = CC_cl_applysac2(env, 3, v158, v160, v293);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    stack[-3] = v293;
    v160 = stack[-3];
    v293 = elt(env, 4); /* break */
    if (v160 == v293) goto v416;
    v160 = stack[0];
    v293 = stack[-3];
    v293 = qcdr(v293);
    fn = elt(env, 8); /* setcdr */
    v293 = (*qfn2(fn))(qenv(fn), v160, v293);
    nil = C_nil;
    if (exception_pending()) goto v262;
    v293 = stack[-3];
    v160 = qcar(v293);
    v293 = stack[0];
    popv(5);
    return cons(v160, v293);

v416:
    v293 = elt(env, 4); /* break */
    { popv(5); return onevalue(v293); }

v402:
    v160 = qvalue(elt(env, 3)); /* nil */
    v293 = stack[0];
    popv(5);
    return cons(v160, v293);

v323:
    v160 = qvalue(elt(env, 1)); /* t */
    v293 = stack[-2];
    v293 = cons(v160, v293);
    nil = C_nil;
    if (exception_pending()) goto v262;
    popv(5);
    return ncons(v293);

v174:
    v293 = elt(env, 4); /* break */
    { popv(5); return onevalue(v293); }

v326:
    v160 = qvalue(elt(env, 1)); /* t */
    v293 = stack[-2];
    v293 = cons(v160, v293);
    nil = C_nil;
    if (exception_pending()) goto v262;
    popv(5);
    return ncons(v293);
/* error exit handlers */
v262:
    popv(5);
    return nil;
}



/* Code for cgp_f2cgp */

static Lisp_Object CC_cgp_f2cgp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v234, v265, v304;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_f2cgp");
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
    v236 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* dip_f2dip */
    v304 = (*qfn1(fn))(qenv(fn), v236);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-1];
    v265 = qvalue(elt(env, 1)); /* nil */
    v234 = qvalue(elt(env, 1)); /* nil */
    v236 = elt(env, 2); /* unknown */
    {
        Lisp_Object v188 = stack[0];
        popv(2);
        fn = elt(env, 4); /* cgp_mk */
        return (*qfnn(fn))(qenv(fn), 5, v188, v304, v265, v234, v236);
    }
/* error exit handlers */
v187:
    popv(2);
    return nil;
}



/* Code for sfto_dprpartf */

static Lisp_Object CC_sfto_dprpartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_dprpartf");
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
    v195 = v0;
/* end of prologue */
    stack[0] = v195;
    fn = elt(env, 1); /* sfto_dcontentf */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-1];
    {
        Lisp_Object v303 = stack[0];
        popv(2);
        fn = elt(env, 2); /* sfto_dprpartf1 */
        return (*qfn2(fn))(qenv(fn), v303, v195);
    }
/* error exit handlers */
v225:
    popv(2);
    return nil;
}



/* Code for find!-expts */

static Lisp_Object CC_findKexpts(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v417, v261, v418;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find-expts");
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
    v417 = stack[-2];
    if (!consp(v417)) goto v193;
    v417 = stack[-2];
    v417 = qcar(v417);
    v417 = (consp(v417) ? nil : lisp_true);
    goto v195;

v195:
    if (!(v417 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v417 = stack[-2];
    v417 = qcar(v417);
    stack[0] = qcdr(v417);
    v417 = stack[-2];
    v261 = qcdr(v417);
    v417 = stack[-1];
    v417 = CC_findKexpts(env, v261, v417);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v417 = CC_findKexpts(env, stack[0], v417);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    stack[-1] = v417;
    v417 = stack[-2];
    v417 = qcar(v417);
    v417 = qcar(v417);
    v417 = qcar(v417);
    stack[-2] = v417;
    v261 = stack[-2];
    v417 = elt(env, 2); /* sqrt */
    if (!consp(v261)) goto v199;
    v261 = qcar(v261);
    if (!(v261 == v417)) goto v199;
    v418 = elt(env, 3); /* expt */
    v417 = stack[-2];
    v417 = qcdr(v417);
    v261 = qcar(v417);
    v417 = elt(env, 4); /* (quotient 1 2) */
    v417 = list3(v418, v261, v417);
    nil = C_nil;
    if (exception_pending()) goto v335;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v199:
    v261 = stack[-2];
    v417 = elt(env, 3); /* expt */
    if (!consp(v261)) goto v347;
    v261 = qcar(v261);
    if (!(v261 == v417)) goto v347;
    v417 = stack[-2];
    v417 = qcdr(v417);
    v417 = qcdr(v417);
    v261 = qcar(v417);
    v417 = elt(env, 5); /* quotient */
    if (!consp(v261)) goto v411;
    v261 = qcar(v261);
    if (!(v261 == v417)) goto v411;
    v417 = stack[-2];
    v417 = qcdr(v417);
    v417 = qcdr(v417);
    v417 = qcar(v417);
    v417 = qcdr(v417);
    v417 = qcdr(v417);
    v417 = qcar(v417);
    v417 = (is_number(v417) ? lisp_true : nil);
    goto v381;

v381:
    if (v417 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v417 = stack[-2];
    v417 = qcdr(v417);
    v261 = qcar(v417);
    v417 = stack[-1];
    v417 = Lassoc(nil, v261, v417);
    stack[-3] = v417;
    v417 = stack[-3];
    if (!(v417 == nil)) goto v163;
    v417 = stack[-2];
    v417 = qcdr(v417);
    stack[0] = qcar(v417);
    v417 = elt(env, 7); /* g */
    v261 = Lgensym1(nil, v417);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v417 = (Lisp_Object)17; /* 1 */
    v417 = list2star(stack[0], v261, v417);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    stack[-3] = v417;
    v261 = stack[-3];
    v417 = stack[-1];
    v417 = cons(v261, v417);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    stack[-1] = v417;
    goto v163;

v163:
    v417 = stack[-3];
    stack[0] = qcdr(v417);
    v417 = stack[-3];
    v417 = qcdr(v417);
    v261 = qcdr(v417);
    v417 = stack[-2];
    v417 = qcdr(v417);
    v417 = qcdr(v417);
    v417 = qcar(v417);
    v417 = qcdr(v417);
    v417 = qcdr(v417);
    v417 = qcar(v417);
    fn = elt(env, 8); /* lcm */
    v417 = (*qfn2(fn))(qenv(fn), v261, v417);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v417 = Lrplacd(nil, stack[0], v417);
    nil = C_nil;
    if (exception_pending()) goto v335;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v411:
    v417 = qvalue(elt(env, 6)); /* nil */
    goto v381;

v347:
    v417 = qvalue(elt(env, 6)); /* nil */
    goto v381;

v193:
    v417 = qvalue(elt(env, 1)); /* t */
    goto v195;
/* error exit handlers */
v335:
    popv(5);
    return nil;
}



/* Code for setprev */

static Lisp_Object CC_setprev(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v347;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setprev");
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
    stack[-3] = v0;
/* end of prologue */

v326:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v347 = qvalue(elt(env, 2)); /* maxvar */
    v203 = stack[-3];
    v203 = plus2(v347, v203);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    v347 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    v203 = (Lisp_Object)49; /* 3 */
    v203 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    if (is_number(v203)) goto v237;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v347 = qvalue(elt(env, 2)); /* maxvar */
    v203 = stack[-3];
    v203 = plus2(v347, v203);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    stack[-4] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    stack[-2] = (Lisp_Object)129; /* 8 */
    stack[-1] = stack[0];
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v347 = qvalue(elt(env, 2)); /* maxvar */
    v203 = stack[-3];
    v203 = plus2(v347, v203);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    v347 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    v203 = (Lisp_Object)129; /* 8 */
    v203 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    v203 = cons(stack[-1], v203);
    nil = C_nil;
    if (exception_pending()) goto v51;
    *(Lisp_Object *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v203;
    { popv(6); return onevalue(v203); }

v237:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v347 = qvalue(elt(env, 2)); /* maxvar */
    v203 = stack[-3];
    v203 = plus2(v347, v203);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    v347 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    v203 = (Lisp_Object)49; /* 3 */
    v203 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    stack[-3] = v203;
    goto v326;
/* error exit handlers */
v51:
    popv(6);
    return nil;
}



/* Code for grpbf */

static Lisp_Object CC_grpbf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v432, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for grpbf");
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
    v432 = stack[-4];
    v432 = qcdr(v432);
    v139 = qcar(v432);
    v432 = stack[-3];
    v432 = qcdr(v432);
    v432 = qcar(v432);
    stack[-5] = v139;
    stack[-2] = v432;
    v139 = stack[-5];
    v432 = (Lisp_Object)1; /* 0 */
    if (v139 == v432) goto v304;
    v139 = stack[-2];
    v432 = (Lisp_Object)1; /* 0 */
    if (v139 == v432) goto v184;
    v139 = stack[-5];
    v432 = (Lisp_Object)1; /* 0 */
    v432 = (Lisp_Object)greaterp2(v139, v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    v432 = v432 ? lisp_true : nil;
    env = stack[-6];
    if (v432 == nil) goto v381;
    v139 = stack[-2];
    v432 = (Lisp_Object)1; /* 0 */
    v432 = (Lisp_Object)lessp2(v139, v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    v432 = v432 ? lisp_true : nil;
    env = stack[-6];
    if (v432 == nil) goto v381;
    v432 = qvalue(elt(env, 1)); /* t */
    { popv(7); return onevalue(v432); }

v381:
    v139 = stack[-5];
    v432 = (Lisp_Object)1; /* 0 */
    v432 = (Lisp_Object)lessp2(v139, v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    v432 = v432 ? lisp_true : nil;
    env = stack[-6];
    if (v432 == nil) goto v171;
    v139 = stack[-2];
    v432 = (Lisp_Object)1; /* 0 */
    v432 = (Lisp_Object)greaterp2(v139, v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    v432 = v432 ? lisp_true : nil;
    env = stack[-6];
    if (v432 == nil) goto v171;
    v432 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v432); }

v171:
    v432 = stack[-4];
    v432 = qcdr(v432);
    v139 = qcar(v432);
    v432 = (Lisp_Object)1; /* 0 */
    if (v139 == v432) goto v309;
    v432 = stack[-4];
    v432 = qcdr(v432);
    v432 = qcar(v432);
    v432 = Labsval(nil, v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-6];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-6];
    v432 = stack[-4];
    v432 = qcdr(v432);
    v432 = qcdr(v432);
    v432 = sub1(v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-6];
    v432 = plus2(stack[0], v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-6];
    stack[-1] = v432;
    goto v169;

v169:
    v432 = stack[-3];
    v432 = qcdr(v432);
    v139 = qcar(v432);
    v432 = (Lisp_Object)1; /* 0 */
    if (v139 == v432) goto v416;
    v432 = stack[-3];
    v432 = qcdr(v432);
    v432 = qcar(v432);
    v432 = Labsval(nil, v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-6];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-6];
    v432 = stack[-3];
    v432 = qcdr(v432);
    v432 = qcdr(v432);
    v432 = sub1(v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-6];
    v432 = plus2(stack[0], v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-6];
    goto v297;

v297:
    stack[0] = difference2(stack[-1], v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-6];
    v432 = stack[-4];
    v432 = qcdr(v432);
    v139 = qcdr(v432);
    v432 = stack[-3];
    v432 = qcdr(v432);
    v432 = qcdr(v432);
    v432 = difference2(v139, v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-6];
    stack[-1] = stack[0];
    stack[0] = v432;
    v139 = stack[-1];
    v432 = (Lisp_Object)1; /* 0 */
    v432 = (Lisp_Object)greaterp2(v139, v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    v432 = v432 ? lisp_true : nil;
    env = stack[-6];
    if (v432 == nil) goto v333;
    v139 = stack[-5];
    v432 = (Lisp_Object)1; /* 0 */
        popv(7);
        return Lgreaterp(nil, v139, v432);

v333:
    v139 = stack[-1];
    v432 = (Lisp_Object)1; /* 0 */
    v432 = (Lisp_Object)lessp2(v139, v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    v432 = v432 ? lisp_true : nil;
    env = stack[-6];
    if (v432 == nil) goto v289;
    v139 = stack[-5];
    v432 = (Lisp_Object)1; /* 0 */
        popv(7);
        return Llessp(nil, v139, v432);

v289:
    v139 = stack[0];
    v432 = (Lisp_Object)1; /* 0 */
    if (v139 == v432) goto v433;
    v139 = stack[0];
    v432 = (Lisp_Object)1; /* 0 */
    v432 = (Lisp_Object)greaterp2(v139, v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    v432 = v432 ? lisp_true : nil;
    env = stack[-6];
    if (v432 == nil) goto v282;
    v139 = stack[-5];
    v432 = stack[0];
    v139 = Lash1(nil, v139, v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    v432 = stack[-2];
        popv(7);
        return Lgreaterp(nil, v139, v432);

v282:
    stack[-1] = stack[-5];
    v432 = stack[0];
    v432 = negate(v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-6];
    v432 = Lash1(nil, stack[-2], v432);
    nil = C_nil;
    if (exception_pending()) goto v365;
    {
        Lisp_Object v137 = stack[-1];
        popv(7);
        return Lgreaterp(nil, v137, v432);
    }

v433:
    v139 = stack[-5];
    v432 = stack[-2];
        popv(7);
        return Lgreaterp(nil, v139, v432);

v416:
    v432 = (Lisp_Object)1; /* 0 */
    goto v297;

v309:
    v432 = (Lisp_Object)1; /* 0 */
    stack[-1] = v432;
    goto v169;

v184:
    v139 = stack[-5];
    v432 = (Lisp_Object)1; /* 0 */
        popv(7);
        return Lgreaterp(nil, v139, v432);

v304:
    v139 = stack[-2];
    v432 = (Lisp_Object)1; /* 0 */
        popv(7);
        return Llessp(nil, v139, v432);
/* error exit handlers */
v365:
    popv(7);
    return nil;
}



/* Code for lispforp */

static Lisp_Object CC_lispforp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v195;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispforp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v186 = v0;
/* end of prologue */
    v195 = qvalue(elt(env, 1)); /* !*for!* */
        return Leqcar(nil, v186, v195);
}



/* Code for dfrel2 */

static Lisp_Object MS_CDECL CC_dfrel2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v403, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v405, v420, v199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dfrel2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfrel2");
#endif
    if (stack >= stacklimit)
    {
        push3(v403,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v403);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v403;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v387:
    v405 = stack[-1];
    if (v405 == nil) goto v331;
    v405 = stack[-3];
    v420 = qcar(v405);
    v405 = stack[-1];
    v405 = qcar(v405);
    fn = elt(env, 3); /* dfdeg */
    v405 = (*qfn2(fn))(qenv(fn), v420, v405);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    stack[-4] = v405;
    v405 = stack[-2];
    v420 = qcar(v405);
    v405 = stack[-1];
    v405 = qcar(v405);
    fn = elt(env, 3); /* dfdeg */
    v405 = (*qfn2(fn))(qenv(fn), v420, v405);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    stack[0] = v405;
    v420 = stack[-4];
    v405 = stack[0];
    v405 = (Lisp_Object)lessp2(v420, v405);
    nil = C_nil;
    if (exception_pending()) goto v259;
    v405 = v405 ? lisp_true : nil;
    env = stack[-5];
    if (v405 == nil) goto v181;
    v405 = qvalue(elt(env, 1)); /* t */
    { popv(6); return onevalue(v405); }

v181:
    v420 = stack[0];
    v405 = stack[-4];
    v405 = (Lisp_Object)lessp2(v420, v405);
    nil = C_nil;
    if (exception_pending()) goto v259;
    v405 = v405 ? lisp_true : nil;
    env = stack[-5];
    if (v405 == nil) goto v382;
    v405 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v405); }

v382:
    v199 = stack[-3];
    v420 = stack[-2];
    v405 = stack[-1];
    v405 = qcdr(v405);
    stack[-3] = v199;
    stack[-2] = v420;
    stack[-1] = v405;
    goto v387;

v331:
    v405 = (Lisp_Object)1; /* 0 */
    { popv(6); return onevalue(v405); }
/* error exit handlers */
v259:
    popv(6);
    return nil;
}



/* Code for clearrules */

static Lisp_Object CC_clearrules(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clearrules");
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
    v225 = v0;
/* end of prologue */
    v193 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*sqrtrulep */
    qvalue(elt(env, 2)) = v193; /* !*sqrtrulep */
    v193 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* rule!-list */
    v193 = (*qfn2(fn))(qenv(fn), v225, v193);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*sqrtrulep */
    { popv(2); return onevalue(v193); }
/* error exit handlers */
v326:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*sqrtrulep */
    popv(2);
    return nil;
}



/* Code for replace_edge2 */

static Lisp_Object CC_replace_edge2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v265;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace_edge2");
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
    v265 = stack[-1];
    v234 = stack[0];
    v234 = qcar(v234);
    v234 = Lrplaca(nil, v265, v234);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v265 = stack[-1];
    v234 = stack[0];
    v234 = qcdr(v234);
        popv(2);
        return Lrplacd(nil, v265, v234);
/* error exit handlers */
v187:
    popv(2);
    return nil;
}



/* Code for multivariatep */

static Lisp_Object CC_multivariatep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v230;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multivariatep");
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

v192:
    v181 = stack[-1];
    if (!consp(v181)) goto v193;
    v181 = stack[-1];
    v181 = qcar(v181);
    v181 = (consp(v181) ? nil : lisp_true);
    goto v195;

v195:
    if (v181 == nil) goto v264;
    v181 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v181); }

v264:
    v181 = stack[-1];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v230 = qcar(v181);
    v181 = stack[0];
    if (v230 == v181) goto v270;
    v181 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v181); }

v270:
    v181 = stack[-1];
    v181 = qcar(v181);
    v230 = qcdr(v181);
    v181 = stack[0];
    v181 = CC_multivariatep(env, v230, v181);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-2];
    if (v181 == nil) goto v253;
    v181 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v181); }

v253:
    v181 = stack[-1];
    v181 = qcdr(v181);
    stack[-1] = v181;
    goto v192;

v193:
    v181 = qvalue(elt(env, 1)); /* t */
    goto v195;
/* error exit handlers */
v174:
    popv(3);
    return nil;
}



/* Code for ggvars3 */

static Lisp_Object CC_ggvars3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v421, v325, v350;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ggvars3");
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
    v421 = v1;
    v325 = v0;
/* end of prologue */

v331:
    v350 = v325;
    if (v350 == nil) { popv(2); return onevalue(v421); }
    v350 = v325;
    v350 = qcdr(v350);
    stack[0] = v350;
    v325 = qcar(v325);
    fn = elt(env, 1); /* ggvars2 */
    v421 = (*qfn2(fn))(qenv(fn), v325, v421);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-1];
    v325 = stack[0];
    goto v331;
/* error exit handlers */
v305:
    popv(2);
    return nil;
}



/* Code for cl_save */

static Lisp_Object CC_cl_save(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v421, v325;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_save");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v421 = v1;
    v325 = v0;
/* end of prologue */
    v188 = qvalue(elt(env, 1)); /* !*rlqedfs */
    if (v188 == nil) goto v231;
    v188 = v325;
    {
        fn = elt(env, 2); /* cl_push */
        return (*qfn2(fn))(qenv(fn), v188, v421);
    }

v231:
    v188 = v325;
    {
        fn = elt(env, 3); /* cl_enqueue */
        return (*qfn2(fn))(qenv(fn), v188, v421);
    }
}



/* Code for qqe_update!-headmin */

static Lisp_Object CC_qqe_updateKheadmin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v264, v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_update-headmin");
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
    v264 = stack[-1];
    fn = elt(env, 1); /* qqe_arg2l */
    v187 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-2];
    v264 = stack[0];
    fn = elt(env, 2); /* qqe_length!-graph!-bterm */
    v264 = (*qfn2(fn))(qenv(fn), v187, v264);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-2];
    stack[0] = v264;
    v264 = stack[-1];
    fn = elt(env, 3); /* qqe_arg2r */
    v187 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-2];
    v264 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* qqe_length!-graph!-bterm */
        return (*qfn2(fn))(qenv(fn), v187, v264);
    }
/* error exit handlers */
v325:
    popv(3);
    return nil;
}



/* Code for pasf_coeflst */

static Lisp_Object CC_pasf_coeflst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v308, v412, v419;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_coeflst");
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
    v308 = stack[-1];
    v308 = ncons(v308);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-4];
    fn = elt(env, 3); /* setkorder */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-4];
    stack[-3] = v308;
    v308 = stack[-2];
    fn = elt(env, 4); /* reorder */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-4];
    stack[-2] = v308;
    goto v326;

v326:
    v308 = stack[-2];
    if (!consp(v308)) goto v188;
    v308 = stack[-2];
    v308 = qcar(v308);
    v308 = (consp(v308) ? nil : lisp_true);
    goto v187;

v187:
    if (v308 == nil) goto v222;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v234;

v234:
    if (v308 == nil) goto v303;
    v308 = stack[-2];
    v308 = qcar(v308);
    v419 = qcdr(v308);
    v308 = stack[-2];
    v308 = qcar(v308);
    v308 = qcar(v308);
    v412 = qcdr(v308);
    v308 = stack[0];
    v308 = acons(v419, v412, v308);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-4];
    stack[0] = v308;
    v308 = stack[-2];
    v308 = qcdr(v308);
    stack[-2] = v308;
    goto v326;

v303:
    v308 = stack[-3];
    fn = elt(env, 3); /* setkorder */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-4];
    v308 = stack[-2];
    fn = elt(env, 5); /* negf */
    v419 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-4];
    v412 = (Lisp_Object)1; /* 0 */
    v308 = stack[0];
    v308 = acons(v419, v412, v308);
    nil = C_nil;
    if (exception_pending()) goto v298;
        popv(5);
        return Lnreverse(nil, v308);

v222:
    v308 = stack[-2];
    v308 = qcar(v308);
    v308 = qcar(v308);
    v412 = qcar(v308);
    v308 = stack[-1];
    v308 = (v412 == v308 ? lisp_true : nil);
    goto v234;

v188:
    v308 = qvalue(elt(env, 1)); /* t */
    goto v187;
/* error exit handlers */
v298:
    popv(5);
    return nil;
}



/* Code for ldt!-dfvar */

static Lisp_Object CC_ldtKdfvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v188, v421;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldt-dfvar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v187 = v0;
/* end of prologue */
    v187 = qcar(v187);
    v187 = qcar(v187);
    v421 = v187;
    v188 = v421;
    v187 = elt(env, 1); /* df */
    if (!consp(v188)) goto v265;
    v188 = qcar(v188);
    if (!(v188 == v187)) goto v265;
    v187 = v421;
    v187 = qcdr(v187);
    v187 = qcdr(v187);
    {
        fn = elt(env, 3); /* vlist */
        return (*qfn1(fn))(qenv(fn), v187);
    }

v265:
    v187 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v187);
}



/* Code for vbcabs */

static Lisp_Object CC_vbcabs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vbcabs");
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
    v225 = stack[0];
    fn = elt(env, 1); /* vbcminus!? */
    v225 = (*qfn1(fn))(qenv(fn), v225);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-1];
    if (v225 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v225 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* bcneg */
        return (*qfn1(fn))(qenv(fn), v225);
    }
/* error exit handlers */
v326:
    popv(2);
    return nil;
}



/* Code for idqsimpcont */

static Lisp_Object CC_idqsimpcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225, v303;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idqsimpcont");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v303 = v0;
/* end of prologue */
    v225 = qvalue(elt(env, 1)); /* !*vdpinteger */
    if (v225 == nil) goto v330;
    v225 = v303;
    {
        fn = elt(env, 2); /* idqsimpconti */
        return (*qfn1(fn))(qenv(fn), v225);
    }

v330:
    v225 = v303;
    {
        fn = elt(env, 3); /* idqsimpcontr */
        return (*qfn1(fn))(qenv(fn), v225);
    }
}



/* Code for lisprepeatp */

static Lisp_Object CC_lisprepeatp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v195;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lisprepeatp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v186 = v0;
/* end of prologue */
    v195 = elt(env, 1); /* repeat */
        return Leqcar(nil, v186, v195);
}



/* Code for partdfsq */

static Lisp_Object CC_partdfsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v406, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partdfsq");
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
    v406 = stack[-2];
    v180 = qcar(v406);
    v406 = stack[-1];
    fn = elt(env, 1); /* partdff */
    stack[-3] = (*qfn2(fn))(qenv(fn), v180, v406);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[0] = stack[-2];
    v406 = stack[-2];
    v406 = qcdr(v406);
    fn = elt(env, 2); /* negf */
    v180 = (*qfn1(fn))(qenv(fn), v406);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    v406 = stack[-1];
    fn = elt(env, 1); /* partdff */
    v406 = (*qfn2(fn))(qenv(fn), v180, v406);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v406 = (*qfn2(fn))(qenv(fn), stack[0], v406);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v406);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    v180 = (Lisp_Object)17; /* 1 */
    v406 = stack[-2];
    v406 = qcdr(v406);
    v406 = cons(v180, v406);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    {
        Lisp_Object v202 = stack[0];
        popv(5);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v202, v406);
    }
/* error exit handlers */
v174:
    popv(5);
    return nil;
}



/* Code for which_first */

static Lisp_Object MS_CDECL CC_which_first(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v403, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v254, v184, v185, v198, v229;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "which_first");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for which_first");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v185 = v403;
    v198 = v1;
    v229 = v0;
/* end of prologue */

v331:
    v254 = v185;
    if (v254 == nil) goto v330;
    v184 = v229;
    v254 = v185;
    v254 = qcar(v254);
    if (equal(v184, v254)) return onevalue(v229);
    v184 = v198;
    v254 = v185;
    v254 = qcar(v254);
    if (equal(v184, v254)) return onevalue(v198);
    v254 = v185;
    v254 = qcdr(v254);
    v185 = v254;
    goto v331;

v330:
    v254 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v254);
}



/* Code for dfmax */

static Lisp_Object MS_CDECL CC_dfmax(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v403, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v304, v264, v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dfmax");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfmax");
#endif
    if (stack >= stacklimit)
    {
        push3(v403,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v403);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v304 = v403;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v187 = stack[-1];
    v264 = stack[0];
    fn = elt(env, 1); /* dfrel */
    v304 = (*qfnn(fn))(qenv(fn), 3, v187, v264, v304);
    nil = C_nil;
    if (exception_pending()) goto v325;
    if (v304 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v325:
    popv(2);
    return nil;
}



/* Code for rep_parents */

static Lisp_Object CC_rep_parents(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v225;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rep_parents");
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
    v193 = v1;
    stack[0] = v0;
/* end of prologue */
    v225 = stack[0];
    v193 = Lrplacd(nil, v225, v193);
    nil = C_nil;
    if (exception_pending()) goto v326;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v326:
    popv(1);
    return nil;
}



/* Code for clogf */

static Lisp_Object CC_clogf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v413, v248, v259;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clogf");
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
    stack[-1] = nil;
    v248 = stack[-2];
    v413 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v413 = (*qfn2(fn))(qenv(fn), v248, v413);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-3] = v413;
    v413 = stack[-3];
    stack[0] = v413;
    goto v352;

v352:
    v413 = stack[0];
    if (v413 == nil) goto v351;
    v413 = stack[0];
    v413 = qcar(v413);
    v259 = v413;
    v248 = v259;
    v413 = elt(env, 2); /* log */
    if (!consp(v248)) goto v350;
    v248 = qcar(v248);
    if (!(v248 == v413)) goto v350;
    v248 = v259;
    v413 = stack[-1];
    v413 = cons(v248, v413);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-1] = v413;
    goto v350;

v350:
    v413 = stack[0];
    v413 = qcdr(v413);
    stack[0] = v413;
    goto v352;

v351:
    v413 = stack[-1];
    if (v413 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v248 = stack[-3];
    v413 = stack[-1];
    fn = elt(env, 4); /* setdiff */
    v413 = (*qfn2(fn))(qenv(fn), v248, v413);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-3] = v413;
    v248 = stack[-3];
    v413 = stack[-1];
    v413 = Lnconc(nil, v248, v413);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    fn = elt(env, 5); /* setkorder */
    v413 = (*qfn1(fn))(qenv(fn), v413);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-3] = v413;
    v413 = stack[-2];
    fn = elt(env, 6); /* reorder */
    v413 = (*qfn1(fn))(qenv(fn), v413);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    fn = elt(env, 7); /* clogf1 */
    v413 = (*qfn1(fn))(qenv(fn), v413);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-2] = v413;
    v413 = stack[-3];
    fn = elt(env, 5); /* setkorder */
    v413 = (*qfn1(fn))(qenv(fn), v413);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v413 = stack[-2];
    {
        popv(5);
        fn = elt(env, 6); /* reorder */
        return (*qfn1(fn))(qenv(fn), v413);
    }
/* error exit handlers */
v175:
    popv(5);
    return nil;
}



/* Code for num_ids_range */

static Lisp_Object CC_num_ids_range(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v245, v240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for num_ids_range");
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
    v245 = v0;
/* end of prologue */
    v244 = qvalue(elt(env, 1)); /* !*onespace */
    if (v244 == nil) goto v331;
    v240 = v245;
    v245 = qvalue(elt(env, 2)); /* dimex!* */
    v244 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 10); /* out_of_range */
    v244 = (*qfnn(fn))(qenv(fn), 3, v240, v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-3];
    if (v244 == nil) goto v223;
    v244 = elt(env, 4); /* "numeric indices out of range" */
    v245 = v244;
    v244 = v245;
    qvalue(elt(env, 5)) = v244; /* errmsg!* */
    v244 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v244 == nil)) goto v350;
    v244 = v245;
    fn = elt(env, 11); /* lprie */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-3];
    goto v350;

v350:
    v244 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v379;
    v244 = nil;
    { popv(4); return onevalue(v244); }

v223:
    v244 = qvalue(elt(env, 3)); /* nil */
    { popv(4); return onevalue(v244); }

v331:
    v244 = qvalue(elt(env, 7)); /* numindxl!* */
    if (v244 == nil) goto v324;
    v244 = v245;
    fn = elt(env, 12); /* flattens1 */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-3];
    fn = elt(env, 13); /* extract_numid */
    stack[0] = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-3];
    v240 = qvalue(elt(env, 7)); /* numindxl!* */
    v245 = stack[-1];
    v244 = elt(env, 8); /* belong_to_space */
    v244 = get(v245, v244);
    env = stack[-3];
    v244 = Lsubla(nil, v240, v244);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-3];
    v245 = stack[0];
    fn = elt(env, 14); /* lst_belong_interval */
    v244 = (*qfn2(fn))(qenv(fn), v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-3];
    if (v244 == nil) goto v12;
    v244 = nil;
    { popv(4); return onevalue(v244); }

v12:
    v244 = elt(env, 9); /* "numeric indices do not belong to (sub)-space" 
*/
    v245 = v244;
    v244 = v245;
    qvalue(elt(env, 5)) = v244; /* errmsg!* */
    v244 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v244 == nil)) goto v401;
    v244 = v245;
    fn = elt(env, 11); /* lprie */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-3];
    goto v401;

v401:
    v244 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v379;
    v244 = nil;
    { popv(4); return onevalue(v244); }

v324:
    stack[-2] = v245;
    v245 = stack[-1];
    v244 = elt(env, 8); /* belong_to_space */
    v244 = get(v245, v244);
    env = stack[-3];
    fn = elt(env, 15); /* get_dim_space */
    stack[0] = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-3];
    v245 = stack[-1];
    v244 = elt(env, 8); /* belong_to_space */
    v244 = get(v245, v244);
    env = stack[-3];
    fn = elt(env, 16); /* get_sign_space */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-3];
    fn = elt(env, 10); /* out_of_range */
    v244 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-3];
    if (v244 == nil) goto v402;
    v244 = elt(env, 4); /* "numeric indices out of range" */
    v245 = v244;
    v244 = v245;
    qvalue(elt(env, 5)) = v244; /* errmsg!* */
    v244 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v244 == nil)) goto v299;
    v244 = v245;
    fn = elt(env, 11); /* lprie */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-3];
    goto v299;

v299:
    v244 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v379;
    v244 = nil;
    { popv(4); return onevalue(v244); }

v402:
    v244 = qvalue(elt(env, 3)); /* nil */
    { popv(4); return onevalue(v244); }
/* error exit handlers */
v379:
    popv(4);
    return nil;
}



/* Code for cdr_sort */

static Lisp_Object CC_cdr_sort(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v407;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cdr_sort");
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
    v221 = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[-4] = v221;
    goto v195;

v195:
    v221 = stack[-4];
    if (v221 == nil) goto v186;
    v221 = stack[-2];
    if (v221 == nil) goto v264;
    stack[0] = stack[-3];
    v221 = stack[-2];
    v221 = qcar(v221);
    v407 = qcdr(v221);
    v221 = stack[-4];
    v221 = qcar(v221);
    v221 = qcdr(v221);
    v221 = list2(v407, v221);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    fn = elt(env, 3); /* apply */
    v221 = (*qfn2(fn))(qenv(fn), stack[0], v221);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    goto v304;

v304:
    if (v221 == nil) goto v200;
    v221 = stack[-4];
    v407 = qcar(v221);
    v221 = stack[-2];
    v221 = cons(v407, v221);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[-2] = v221;
    v221 = stack[-4];
    v221 = qcdr(v221);
    stack[-4] = v221;
    goto v195;

v200:
    v221 = stack[-2];
    stack[-1] = v221;
    goto v344;

v344:
    v221 = stack[-1];
    v221 = qcdr(v221);
    if (v221 == nil) goto v309;
    stack[0] = stack[-3];
    v221 = stack[-1];
    v221 = qcdr(v221);
    v221 = qcar(v221);
    v407 = qcdr(v221);
    v221 = stack[-4];
    v221 = qcar(v221);
    v221 = qcdr(v221);
    v221 = list2(v407, v221);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    fn = elt(env, 3); /* apply */
    v221 = (*qfn2(fn))(qenv(fn), stack[0], v221);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    if (!(v221 == nil)) goto v309;
    v221 = stack[-1];
    v221 = qcdr(v221);
    stack[-1] = v221;
    goto v344;

v309:
    stack[0] = stack[-1];
    v221 = stack[-4];
    v407 = qcar(v221);
    v221 = stack[-1];
    v221 = qcdr(v221);
    v221 = cons(v407, v221);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v221 = Lrplacd(nil, stack[0], v221);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v221 = stack[-4];
    v221 = qcdr(v221);
    stack[-4] = v221;
    goto v195;

v264:
    v221 = qvalue(elt(env, 2)); /* t */
    goto v304;

v186:
    v221 = stack[-2];
        popv(6);
        return Lreverse(nil, v221);
/* error exit handlers */
v312:
    popv(6);
    return nil;
}



setup_type const u53_setup[] =
{
    {"cos:",                    too_few_2,      CC_cosT,       wrong_no_2},
    {"clear",                   CC_clear,       too_many_1,    wrong_no_1},
    {"nbglp",                   too_few_2,      CC_nbglp,      wrong_no_2},
    {"r2bf",                    CC_r2bf,        too_many_1,    wrong_no_1},
    {"simprad",                 too_few_2,      CC_simprad,    wrong_no_2},
    {"get-new-prime",           CC_getKnewKprime,too_many_1,   wrong_no_1},
    {"pseudo-remainder",        CC_pseudoKremainder,too_many_1,wrong_no_1},
    {"ofsf_decdeg2",            too_few_2,      CC_ofsf_decdeg2,wrong_no_2},
    {"tildepri",                CC_tildepri,    too_many_1,    wrong_no_1},
    {"evalletsub2",             too_few_2,      CC_evalletsub2,wrong_no_2},
    {"qqe_simplqequal",         too_few_2,      CC_qqe_simplqequal,wrong_no_2},
    {"pasf_leqp",               too_few_2,      CC_pasf_leqp,  wrong_no_2},
    {"infinp",                  CC_infinp,      too_many_1,    wrong_no_1},
    {"prload",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_prload},
    {"fnewsym",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnewsym},
    {"nesttimes:",              too_few_2,      CC_nesttimesT, wrong_no_2},
    {"evalsymsubset",           CC_evalsymsubset,too_many_1,   wrong_no_1},
    {"mo=expvec2a1",            too_few_2,      CC_moMexpvec2a1,wrong_no_2},
    {"monicmember",             too_few_2,      CC_monicmember,wrong_no_2},
    {"idcompare",               too_few_2,      CC_idcompare,  wrong_no_2},
    {"make-image-lc-list1",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKimageKlcKlist1},
    {"cl_get",                  CC_cl_get,      too_many_1,    wrong_no_1},
    {"get_recursive_kernels",   too_few_2,      CC_get_recursive_kernels,wrong_no_2},
    {"lrootchk",                too_few_2,      CC_lrootchk,   wrong_no_2},
    {"addto-all-taytpelorders", too_few_2,      CC_addtoKallKtaytpelorders,wrong_no_2},
    {"qqe_length-graph-remove-mark",too_few_2,  CC_qqe_lengthKgraphKremoveKmark,wrong_no_2},
    {"cl_applysac2",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_applysac2},
    {"cgp_f2cgp",               CC_cgp_f2cgp,   too_many_1,    wrong_no_1},
    {"sfto_dprpartf",           CC_sfto_dprpartf,too_many_1,   wrong_no_1},
    {"find-expts",              too_few_2,      CC_findKexpts, wrong_no_2},
    {"setprev",                 too_few_2,      CC_setprev,    wrong_no_2},
    {"grpbf",                   too_few_2,      CC_grpbf,      wrong_no_2},
    {"lispforp",                CC_lispforp,    too_many_1,    wrong_no_1},
    {"dfrel2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_dfrel2},
    {"clearrules",              CC_clearrules,  too_many_1,    wrong_no_1},
    {"replace_edge2",           too_few_2,      CC_replace_edge2,wrong_no_2},
    {"multivariatep",           too_few_2,      CC_multivariatep,wrong_no_2},
    {"ggvars3",                 too_few_2,      CC_ggvars3,    wrong_no_2},
    {"cl_save",                 too_few_2,      CC_cl_save,    wrong_no_2},
    {"qqe_update-headmin",      too_few_2,      CC_qqe_updateKheadmin,wrong_no_2},
    {"pasf_coeflst",            too_few_2,      CC_pasf_coeflst,wrong_no_2},
    {"ldt-dfvar",               CC_ldtKdfvar,   too_many_1,    wrong_no_1},
    {"vbcabs",                  CC_vbcabs,      too_many_1,    wrong_no_1},
    {"idqsimpcont",             CC_idqsimpcont, too_many_1,    wrong_no_1},
    {"lisprepeatp",             CC_lisprepeatp, too_many_1,    wrong_no_1},
    {"partdfsq",                too_few_2,      CC_partdfsq,   wrong_no_2},
    {"which_first",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_which_first},
    {"dfmax",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_dfmax},
    {"rep_parents",             too_few_2,      CC_rep_parents,wrong_no_2},
    {"clogf",                   CC_clogf,       too_many_1,    wrong_no_1},
    {"num_ids_range",           too_few_2,      CC_num_ids_range,wrong_no_2},
    {"cdr_sort",                too_few_2,      CC_cdr_sort,   wrong_no_2},
    {NULL, (one_args *)"u53", (two_args *)"3874 8676255 3770074", 0}
};

/* end of generated code */
