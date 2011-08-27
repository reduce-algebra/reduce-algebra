
/* $destdir\u53.c        Machine generated C code */

/* Signature: 00000000 27-Aug-2011 */

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


/* Code for st_ad_numsorttree1 */

static Lisp_Object CC_st_ad_numsorttree1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_ad_numsorttree1");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0;
/* end of prologue */
    stack[-5] = nil;
    v98 = stack[-6];
    if (is_number(v98)) goto v101;
    v98 = (Lisp_Object)17; /* 1 */
    stack[-4] = v98;
    v98 = stack[-6];
    v99 = qcar(v98);
    v98 = elt(env, 1); /* !* */
    if (v99 == v98) goto v102;
    v98 = stack[-6];
    v98 = qcdr(v98);
    stack[-3] = v98;
    v98 = stack[-3];
    if (v98 == nil) goto v103;
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = CC_st_ad_numsorttree1(env, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-7] = v98;
    v99 = stack[-4];
    v98 = stack[-7];
    v98 = qcar(v98);
    v98 = times2(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-4] = v98;
    v98 = stack[-7];
    v98 = qcdr(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-1] = v98;
    stack[-2] = v98;
    goto v105;

v105:
    v98 = stack[-3];
    v98 = qcdr(v98);
    stack[-3] = v98;
    v98 = stack[-3];
    if (v98 == nil) goto v106;
    stack[0] = stack[-1];
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = CC_st_ad_numsorttree1(env, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-7] = v98;
    v99 = stack[-4];
    v98 = stack[-7];
    v98 = qcar(v98);
    v98 = times2(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-4] = v98;
    v98 = stack[-7];
    v98 = qcdr(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    v98 = Lrplacd(nil, stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-1] = v98;
    goto v105;

v106:
    v98 = stack[-2];
    goto v107;

v107:
    stack[-1] = v98;
    v98 = stack[-6];
    v99 = qcar(v98);
    v98 = elt(env, 3); /* !+ */
    if (v99 == v98) goto v108;
    v98 = stack[-6];
    v99 = qcar(v98);
    v98 = elt(env, 5); /* !- */
    if (v99 == v98) goto v109;
    v98 = nil;
    { popv(9); return onevalue(v98); }

v109:
    v99 = stack[-1];
    v98 = elt(env, 4); /* numlist_ordp */
    fn = elt(env, 6); /* cdr_signsort */
    v98 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-1] = v98;
    v98 = stack[-1];
    v98 = qcar(v98);
    stack[-4] = v98;
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-6] = v98;
    v98 = stack[-6];
    if (v98 == nil) goto v110;
    v98 = stack[-6];
    v98 = qcar(v98);
    stack[0] = v98;
    v98 = stack[0];
    v99 = qcdr(v98);
    v98 = stack[-5];
    v98 = cons(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-5] = v98;
    v98 = stack[0];
    v98 = qcar(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-2] = v98;
    stack[-3] = v98;
    goto v111;

v111:
    v98 = stack[-6];
    v98 = qcdr(v98);
    stack[-6] = v98;
    v98 = stack[-6];
    if (v98 == nil) goto v112;
    stack[-1] = stack[-2];
    v98 = stack[-6];
    v98 = qcar(v98);
    stack[0] = v98;
    v98 = stack[0];
    v99 = qcdr(v98);
    v98 = stack[-5];
    v98 = cons(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-5] = v98;
    v98 = stack[0];
    v98 = qcar(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    v98 = Lrplacd(nil, stack[-1], v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    v98 = stack[-2];
    v98 = qcdr(v98);
    stack[-2] = v98;
    goto v111;

v112:
    v98 = stack[-3];
    goto v113;

v113:
    stack[-1] = v98;
    v98 = stack[-5];
    v98 = Lreverse(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-3] = v98;
    goto v114;

v114:
    v98 = stack[-3];
    if (v98 == nil) goto v115;
    v98 = stack[-3];
    v98 = qcar(v98);
    stack[-2] = v98;
    v98 = stack[-2];
    fn = elt(env, 7); /* lastpair */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[0] = v98;
    v98 = stack[-3];
    v98 = qcdr(v98);
    stack[-3] = v98;
    v98 = stack[0];
    if (!consp(v98)) goto v114;
    else goto v116;

v116:
    v98 = stack[-3];
    if (v98 == nil) goto v117;
    v99 = stack[0];
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = Lrplacd(nil, v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    v98 = stack[0];
    fn = elt(env, 7); /* lastpair */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[0] = v98;
    v98 = stack[-3];
    v98 = qcdr(v98);
    stack[-3] = v98;
    goto v116;

v117:
    v98 = stack[-2];
    goto v118;

v118:
    fn = elt(env, 8); /* ad_numsort */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-5] = v98;
    stack[0] = stack[-4];
    v99 = elt(env, 5); /* !- */
    v98 = stack[-1];
    v99 = cons(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    v98 = stack[-5];
    {
        Lisp_Object v119 = stack[0];
        popv(9);
        return list2star(v119, v99, v98);
    }

v115:
    v98 = qvalue(elt(env, 2)); /* nil */
    goto v118;

v110:
    v98 = qvalue(elt(env, 2)); /* nil */
    goto v113;

v108:
    v99 = stack[-1];
    v98 = elt(env, 4); /* numlist_ordp */
    fn = elt(env, 9); /* cdr_sort */
    v98 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-1] = v98;
    v98 = stack[-1];
    stack[-6] = v98;
    v98 = stack[-6];
    if (v98 == nil) goto v120;
    v98 = stack[-6];
    v98 = qcar(v98);
    stack[0] = v98;
    v98 = stack[0];
    v99 = qcdr(v98);
    v98 = stack[-5];
    v98 = cons(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-5] = v98;
    v98 = stack[0];
    v98 = qcar(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-2] = v98;
    stack[-3] = v98;
    goto v121;

v121:
    v98 = stack[-6];
    v98 = qcdr(v98);
    stack[-6] = v98;
    v98 = stack[-6];
    if (v98 == nil) goto v122;
    stack[-1] = stack[-2];
    v98 = stack[-6];
    v98 = qcar(v98);
    stack[0] = v98;
    v98 = stack[0];
    v99 = qcdr(v98);
    v98 = stack[-5];
    v98 = cons(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-5] = v98;
    v98 = stack[0];
    v98 = qcar(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    v98 = Lrplacd(nil, stack[-1], v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    v98 = stack[-2];
    v98 = qcdr(v98);
    stack[-2] = v98;
    goto v121;

v122:
    v98 = stack[-3];
    goto v123;

v123:
    stack[-1] = v98;
    v98 = stack[-5];
    v98 = Lreverse(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-3] = v98;
    goto v124;

v124:
    v98 = stack[-3];
    if (v98 == nil) goto v125;
    v98 = stack[-3];
    v98 = qcar(v98);
    stack[-2] = v98;
    v98 = stack[-2];
    fn = elt(env, 7); /* lastpair */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[0] = v98;
    v98 = stack[-3];
    v98 = qcdr(v98);
    stack[-3] = v98;
    v98 = stack[0];
    if (!consp(v98)) goto v124;
    else goto v126;

v126:
    v98 = stack[-3];
    if (v98 == nil) goto v127;
    v99 = stack[0];
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = Lrplacd(nil, v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    v98 = stack[0];
    fn = elt(env, 7); /* lastpair */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[0] = v98;
    v98 = stack[-3];
    v98 = qcdr(v98);
    stack[-3] = v98;
    goto v126;

v127:
    v98 = stack[-2];
    goto v128;

v128:
    fn = elt(env, 8); /* ad_numsort */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-5] = v98;
    stack[0] = stack[-4];
    v99 = elt(env, 3); /* !+ */
    v98 = stack[-1];
    v99 = cons(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    v98 = stack[-5];
    {
        Lisp_Object v129 = stack[0];
        popv(9);
        return list2star(v129, v99, v98);
    }

v125:
    v98 = qvalue(elt(env, 2)); /* nil */
    goto v128;

v120:
    v98 = qvalue(elt(env, 2)); /* nil */
    goto v123;

v103:
    v98 = qvalue(elt(env, 2)); /* nil */
    goto v107;

v102:
    stack[-3] = elt(env, 1); /* !* */
    v98 = stack[-6];
    v98 = qcdr(v98);
    stack[-6] = v98;
    v98 = stack[-6];
    if (v98 == nil) goto v130;
    v98 = stack[-6];
    v98 = qcar(v98);
    v98 = CC_st_ad_numsorttree1(env, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-7] = v98;
    v99 = stack[-4];
    v98 = stack[-7];
    v98 = qcar(v98);
    v98 = times2(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-4] = v98;
    v98 = stack[-7];
    v98 = qcdr(v98);
    v99 = qcdr(v98);
    v98 = stack[-5];
    v98 = cons(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-5] = v98;
    v98 = stack[-7];
    v98 = qcdr(v98);
    v98 = qcar(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-1] = v98;
    stack[-2] = v98;
    goto v131;

v131:
    v98 = stack[-6];
    v98 = qcdr(v98);
    stack[-6] = v98;
    v98 = stack[-6];
    if (v98 == nil) goto v132;
    stack[0] = stack[-1];
    v98 = stack[-6];
    v98 = qcar(v98);
    v98 = CC_st_ad_numsorttree1(env, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-7] = v98;
    v99 = stack[-4];
    v98 = stack[-7];
    v98 = qcar(v98);
    v98 = times2(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-4] = v98;
    v98 = stack[-7];
    v98 = qcdr(v98);
    v99 = qcdr(v98);
    v98 = stack[-5];
    v98 = cons(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-5] = v98;
    v98 = stack[-7];
    v98 = qcdr(v98);
    v98 = qcar(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    v98 = Lrplacd(nil, stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-1] = v98;
    goto v131;

v132:
    v98 = stack[-2];
    goto v133;

v133:
    v98 = cons(stack[-3], v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[-6] = v98;
    v98 = stack[-5];
    stack[-2] = v98;
    goto v134;

v134:
    v98 = stack[-2];
    if (v98 == nil) goto v135;
    v98 = stack[-2];
    v98 = qcar(v98);
    stack[-1] = v98;
    v98 = stack[-1];
    fn = elt(env, 7); /* lastpair */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[0] = v98;
    v98 = stack[-2];
    v98 = qcdr(v98);
    stack[-2] = v98;
    v98 = stack[0];
    if (!consp(v98)) goto v134;
    else goto v136;

v136:
    v98 = stack[-2];
    if (v98 == nil) goto v137;
    v99 = stack[0];
    v98 = stack[-2];
    v98 = qcar(v98);
    v98 = Lrplacd(nil, v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    v98 = stack[0];
    fn = elt(env, 7); /* lastpair */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-8];
    stack[0] = v98;
    v98 = stack[-2];
    v98 = qcdr(v98);
    stack[-2] = v98;
    goto v136;

v137:
    v98 = stack[-1];
    goto v138;

v138:
    fn = elt(env, 8); /* ad_numsort */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v104;
    stack[-5] = v98;
    v100 = stack[-4];
    v99 = stack[-6];
    v98 = stack[-5];
    popv(9);
    return list2star(v100, v99, v98);

v135:
    v98 = qvalue(elt(env, 2)); /* nil */
    goto v138;

v130:
    v98 = qvalue(elt(env, 2)); /* nil */
    goto v133;

v101:
    v100 = (Lisp_Object)17; /* 1 */
    v99 = stack[-6];
    v98 = stack[-6];
    popv(9);
    return list3(v100, v99, v98);
/* error exit handlers */
v104:
    popv(9);
    return nil;
}



/* Code for ofsf_transform */

static Lisp_Object CC_ofsf_transform(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v157, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_transform");
#endif
    if (stack >= stacklimit)
    {
        push2(v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v139;
    stack[-4] = v0;
/* end of prologue */
    v157 = stack[-4];
    v156 = stack[-3];
    fn = elt(env, 8); /* ofsf_decdeg2 */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-6];
    stack[-5] = v156;
    v157 = stack[-5];
    v156 = (Lisp_Object)17; /* 1 */
    if (v157 == v156) goto v160;
    v156 = qvalue(elt(env, 1)); /* !*rlverbose */
    if (v156 == nil) goto v130;
    stack[-2] = elt(env, 2); /* "(" */
    stack[-1] = stack[-3];
    stack[0] = elt(env, 3); /* "^" */
    v157 = stack[-5];
    v156 = elt(env, 4); /* ")" */
    v156 = list2(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-6];
    v156 = list3star(stack[-2], stack[-1], stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-6];
    fn = elt(env, 9); /* ioto_prin2 */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-6];
    goto v130;

v130:
    v158 = stack[-4];
    v157 = stack[-3];
    v156 = stack[-5];
    fn = elt(env, 10); /* ofsf_decdeg3 */
    v156 = (*qfnn(fn))(qenv(fn), 3, v158, v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-6];
    stack[-4] = v156;
    v156 = stack[-5];
    v156 = Levenp(nil, v156);
    env = stack[-6];
    if (v156 == nil) goto v161;
    stack[-1] = elt(env, 5); /* and */
    stack[0] = elt(env, 6); /* geq */
    v156 = stack[-3];
    fn = elt(env, 11); /* simp */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-6];
    v157 = qcar(v156);
    v156 = qvalue(elt(env, 7)); /* nil */
    stack[0] = list3(stack[0], v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-6];
    v156 = stack[-4];
    v156 = ncons(v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-6];
    v156 = list2star(stack[-1], stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    stack[-4] = v156;
    goto v161;

v161:
    v158 = stack[-4];
    v157 = stack[-3];
    v156 = stack[-5];
    popv(7);
    return list2star(v158, v157, v156);

v160:
    v156 = stack[-4];
    popv(7);
    return ncons(v156);
/* error exit handlers */
v159:
    popv(7);
    return nil;
}



/* Code for typelet */

static Lisp_Object MS_CDECL CC_typelet(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v139,
                         Lisp_Object v63, Lisp_Object v4,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v214, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "typelet");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for typelet");
#endif
    if (stack >= stacklimit)
    {
        push5(v7,v4,v63,v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v139,v63,v4,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-3] = v4;
    stack[-1] = v63;
    stack[-4] = v139;
    stack[-5] = v0;
/* end of prologue */
    stack[-2] = nil;
    v30 = stack[0];
    if (!(v30 == nil)) goto v96;
    v30 = elt(env, 1); /* scalar */
    stack[0] = v30;
    goto v96;

v96:
    v214 = stack[-1];
    v30 = stack[0];
    if (v214 == v30) goto v215;
    v30 = stack[-3];
    if (v30 == nil) goto v216;
    v30 = stack[-1];
    if (v30 == nil) goto v217;
    v214 = stack[-1];
    v30 = elt(env, 2); /* list */
    if (v214 == v30) goto v131;
    v30 = qvalue(elt(env, 3)); /* nil */
    goto v218;

v218:
    if (v30 == nil) goto v91;
    v30 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v30;
    goto v219;

v219:
    v109 = stack[-5];
    v214 = elt(env, 5); /* rtype */
    v30 = stack[0];
    v30 = Lputprop(nil, 3, v109, v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    v30 = stack[0];
    stack[-1] = v30;
    goto v215;

v215:
    v30 = stack[-3];
    if (v30 == nil) goto v216;
    v30 = stack[-5];
    if (!consp(v30)) goto v221;
    v30 = qvalue(elt(env, 4)); /* t */
    goto v136;

v136:
    if (v30 == nil) goto v216;
    v214 = qvalue(elt(env, 8)); /* !*sqvar!* */
    v30 = qvalue(elt(env, 3)); /* nil */
    v30 = Lrplaca(nil, v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    v30 = qvalue(elt(env, 4)); /* t */
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    qvalue(elt(env, 8)) = v30; /* !*sqvar!* */
    v30 = qvalue(elt(env, 3)); /* nil */
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    qvalue(elt(env, 9)) = v30; /* alglist!* */
    goto v216;

v216:
    v30 = stack[-5];
    if (!consp(v30)) goto v222;
    v30 = stack[-5];
    v214 = qcar(v30);
    v30 = elt(env, 5); /* rtype */
    v214 = get(v214, v30);
    env = stack[-7];
    v30 = elt(env, 6); /* array */
    if (v214 == v30) goto v64;
    v30 = stack[-5];
    stack[-6] = qcar(v30);
    stack[-2] = elt(env, 10); /* opmtch */
    v30 = stack[-5];
    stack[-1] = qcdr(v30);
    v214 = qvalue(elt(env, 3)); /* nil */
    v30 = qvalue(elt(env, 11)); /* mcond!* */
    if (v30 == nil) goto v223;
    v30 = qvalue(elt(env, 11)); /* mcond!* */
    goto v224;

v224:
    stack[0] = cons(v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    v214 = stack[-4];
    v30 = qvalue(elt(env, 3)); /* nil */
    v30 = list2(v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    v214 = list2star(stack[-1], stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    v30 = stack[-5];
    v109 = qcar(v30);
    v30 = elt(env, 10); /* opmtch */
    v109 = get(v109, v30);
    env = stack[-7];
    v30 = stack[-3];
    fn = elt(env, 15); /* xadd!* */
    v30 = (*qfnn(fn))(qenv(fn), 3, v214, v109, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    v30 = Lputprop(nil, 3, stack[-6], stack[-2], v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    goto v225;

v225:
    v30 = nil;
    { popv(8); return onevalue(v30); }

v223:
    v30 = qvalue(elt(env, 4)); /* t */
    goto v224;

v64:
    v214 = stack[-5];
    v30 = stack[-3];
    if (v30 == nil) goto v226;
    v30 = stack[-4];
    goto v58;

v58:
    fn = elt(env, 16); /* setelv */
    v30 = (*qfn2(fn))(qenv(fn), v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    goto v225;

v226:
    v30 = qvalue(elt(env, 3)); /* nil */
    goto v58;

v222:
    v30 = stack[-3];
    if (v30 == nil) goto v55;
    v30 = stack[-2];
    if (v30 == nil) goto v41;
    v214 = stack[-5];
    v30 = elt(env, 5); /* rtype */
    v30 = Lremprop(nil, v214, v30);
    env = stack[-7];
    v109 = stack[-5];
    v214 = stack[0];
    v30 = stack[-4];
    fn = elt(env, 17); /* put!-avalue */
    v30 = (*qfnn(fn))(qenv(fn), 3, v109, v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    goto v225;

v41:
    v214 = stack[-5];
    v30 = elt(env, 12); /* avalue */
    v30 = get(v214, v30);
    env = stack[-7];
    stack[-3] = v30;
    if (v30 == nil) goto v227;
    v214 = stack[0];
    v30 = stack[-3];
    v30 = qcar(v30);
    if (v214 == v30) goto v228;
    v30 = stack[-3];
    v214 = qcar(v30);
    v30 = elt(env, 14); /* (scalar list) */
    stack[-2] = v30;
    v30 = Lmemq(nil, v214, v30);
    if (v30 == nil) goto v229;
    v214 = stack[0];
    v30 = stack[-2];
    v30 = Lmemq(nil, v214, v30);
    v30 = (v30 == nil ? lisp_true : nil);
    goto v230;

v230:
    if (v30 == nil) goto v227;
    v30 = stack[-3];
    v214 = qcar(v30);
    v30 = stack[-5];
    v214 = list2(v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    v30 = stack[0];
    fn = elt(env, 18); /* typerr */
    v30 = (*qfn2(fn))(qenv(fn), v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    goto v227;

v227:
    v109 = stack[-5];
    v214 = stack[0];
    v30 = stack[-4];
    fn = elt(env, 17); /* put!-avalue */
    v30 = (*qfnn(fn))(qenv(fn), 3, v109, v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    goto v225;

v229:
    v30 = qvalue(elt(env, 4)); /* t */
    goto v230;

v228:
    v30 = qvalue(elt(env, 3)); /* nil */
    goto v230;

v55:
    v214 = stack[-5];
    v30 = elt(env, 12); /* avalue */
    v30 = Lremprop(nil, v214, v30);
    env = stack[-7];
    v214 = stack[-5];
    v30 = elt(env, 5); /* rtype */
    v30 = Lremprop(nil, v214, v30);
    env = stack[-7];
    v214 = stack[-1];
    v30 = elt(env, 6); /* array */
    if (!(v214 == v30)) goto v225;
    v214 = stack[-5];
    v30 = elt(env, 13); /* dimension */
    v30 = Lremprop(nil, v214, v30);
    goto v225;

v221:
    v214 = stack[-5];
    v30 = elt(env, 7); /* used!* */
    v30 = Lflagp(nil, v214, v30);
    env = stack[-7];
    goto v136;

v91:
    v214 = stack[-1];
    v30 = stack[-5];
    v214 = list2(v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    v30 = stack[0];
    fn = elt(env, 18); /* typerr */
    v30 = (*qfn2(fn))(qenv(fn), v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    goto v231;

v231:
    v214 = stack[-5];
    v30 = stack[0];
    fn = elt(env, 19); /* redmsg */
    v30 = (*qfn2(fn))(qenv(fn), v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    goto v219;

v131:
    v214 = stack[0];
    v30 = elt(env, 1); /* scalar */
    v30 = (v214 == v30 ? lisp_true : nil);
    goto v218;

v217:
    v30 = stack[-5];
    if (!consp(v30)) goto v231;
    v30 = stack[-5];
    v214 = qcar(v30);
    v30 = elt(env, 5); /* rtype */
    v214 = get(v214, v30);
    env = stack[-7];
    v30 = elt(env, 6); /* array */
    if (v214 == v30) goto v215;
    v214 = stack[-5];
    v30 = stack[0];
    fn = elt(env, 18); /* typerr */
    v30 = (*qfn2(fn))(qenv(fn), v214, v30);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-7];
    goto v231;
/* error exit handlers */
v220:
    popv(8);
    return nil;
}



/* Code for find!-non!-zero */

static Lisp_Object CC_findKnonKzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v210, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find-non-zero");
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
    v130 = (Lisp_Object)17; /* 1 */
    stack[0] = v130;
    goto v236;

v236:
    v130 = (Lisp_Object)17; /* 1 */
    v235 = v130;
    v130 = stack[-1];
    v130 = qcar(v130);
    stack[-2] = v130;
    goto v237;

v237:
    v130 = stack[-2];
    v210 = qcar(v130);
    v130 = (Lisp_Object)1; /* 0 */
    if (v210 == v130) goto v160;
    v130 = stack[0];
    v210 = v235;
    popv(4);
    return cons(v130, v210);

v160:
    v130 = stack[-2];
    v130 = qcdr(v130);
    stack[-2] = v130;
    v130 = v235;
    v130 = add1(v130);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-3];
    v235 = v130;
    v130 = stack[-2];
    if (!(v130 == nil)) goto v237;
    v130 = stack[-1];
    v130 = qcdr(v130);
    stack[-1] = v130;
    v130 = stack[0];
    v130 = add1(v130);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-3];
    stack[0] = v130;
    v130 = stack[-1];
    if (!(v130 == nil)) goto v236;
    v130 = elt(env, 0); /* find!-non!-zero */
    fn = elt(env, 1); /* confusion */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-3];
    goto v236;
/* error exit handlers */
v238:
    popv(4);
    return nil;
}



/* Code for get!*real!*comp!*chartype!*p */

static Lisp_Object CC_getHrealHcompHchartypeHp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*real*comp*chartype*p");
#endif
    if (stack >= stacklimit)
    {
        push2(v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v242 = v139;
    v217 = v0;
/* end of prologue */
    stack[0] = v217;
    v217 = elt(env, 1); /* realrep */
    fn = elt(env, 4); /* mkid */
    v242 = (*qfn2(fn))(qenv(fn), v217, v242);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-1];
    v217 = get(stack[0], v242);
    env = stack[-1];
    v242 = elt(env, 2); /* complextype */
    if (!consp(v217)) goto v169;
    v217 = qcar(v217);
    if (!(v217 == v242)) goto v169;
    v242 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v242); }

v169:
    v242 = nil;
    { popv(2); return onevalue(v242); }
/* error exit handlers */
v243:
    popv(2);
    return nil;
}



/* Code for cgp_normalize */

static Lisp_Object CC_cgp_normalize(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v241, v239, v245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_normalize");
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
    stack[-2] = qvalue(elt(env, 1)); /* nil */
    v213 = stack[-1];
    fn = elt(env, 3); /* cgp_hp */
    stack[0] = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-3];
    v213 = stack[-1];
    fn = elt(env, 4); /* cgp_rp */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-3];
    fn = elt(env, 5); /* dip_append */
    v245 = (*qfn2(fn))(qenv(fn), stack[0], v213);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-3];
    v239 = qvalue(elt(env, 1)); /* nil */
    v241 = qvalue(elt(env, 1)); /* nil */
    v213 = elt(env, 2); /* unknown */
    {
        Lisp_Object v93 = stack[-2];
        popv(4);
        fn = elt(env, 6); /* cgp_mk */
        return (*qfnn(fn))(qenv(fn), 5, v93, v245, v239, v241, v213);
    }
/* error exit handlers */
v243:
    popv(4);
    return nil;
}



/* Code for ps!:quotient!-erule */

static Lisp_Object CC_psTquotientKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:quotient-erule");
#endif
    if (stack >= stacklimit)
    {
        push2(v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v139;
    v257 = v0;
/* end of prologue */
    v221 = v257;
    v221 = qcdr(v221);
    v221 = qcar(v221);
    stack[-8] = v221;
    v221 = v257;
    v221 = qcdr(v221);
    v221 = qcdr(v221);
    v221 = qcar(v221);
    stack[-6] = v221;
    v257 = qvalue(elt(env, 1)); /* nil */
    v221 = (Lisp_Object)17; /* 1 */
    v221 = cons(v257, v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    stack[0] = v221;
    v221 = stack[-6];
    fn = elt(env, 3); /* ps!:order */
    v221 = (*qfn1(fn))(qenv(fn), v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    stack[-4] = v221;
    v221 = qvalue(elt(env, 2)); /* ps */
    fn = elt(env, 3); /* ps!:order */
    v221 = (*qfn1(fn))(qenv(fn), v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    stack[-5] = v221;
    v221 = (Lisp_Object)17; /* 1 */
    stack[-3] = v221;
    goto v88;

v88:
    v257 = stack[-7];
    v221 = stack[-5];
    v257 = difference2(v257, v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    v221 = stack[-3];
    v221 = difference2(v257, v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    v221 = Lminusp(nil, v221);
    env = stack[-9];
    if (v221 == nil) goto v210;
    stack[-1] = stack[-8];
    v257 = stack[-7];
    v221 = stack[-4];
    v221 = plus2(v257, v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    fn = elt(env, 4); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    v221 = stack[0];
    v221 = qcar(v221);
    fn = elt(env, 5); /* negf */
    v257 = (*qfn1(fn))(qenv(fn), v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    v221 = stack[0];
    v221 = qcdr(v221);
    v221 = cons(v257, v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    fn = elt(env, 6); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-1], v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    v257 = stack[-6];
    v221 = stack[-4];
    fn = elt(env, 4); /* ps!:evaluate */
    v221 = (*qfn2(fn))(qenv(fn), v257, v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    fn = elt(env, 7); /* invsq */
    v221 = (*qfn1(fn))(qenv(fn), v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    {
        Lisp_Object v259 = stack[0];
        popv(10);
        fn = elt(env, 8); /* multsq */
        return (*qfn2(fn))(qenv(fn), v259, v221);
    }

v210:
    stack[-2] = stack[0];
    stack[0] = stack[-6];
    v257 = stack[-3];
    v221 = stack[-4];
    v221 = plus2(v257, v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    fn = elt(env, 4); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    stack[0] = qvalue(elt(env, 2)); /* ps */
    v257 = stack[-7];
    v221 = stack[-3];
    v221 = difference2(v257, v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    fn = elt(env, 4); /* ps!:evaluate */
    v221 = (*qfn2(fn))(qenv(fn), stack[0], v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    fn = elt(env, 8); /* multsq */
    v221 = (*qfn2(fn))(qenv(fn), stack[-1], v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    fn = elt(env, 6); /* addsq */
    v221 = (*qfn2(fn))(qenv(fn), stack[-2], v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    stack[0] = v221;
    v221 = stack[-3];
    v221 = add1(v221);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-9];
    stack[-3] = v221;
    goto v88;
/* error exit handlers */
v258:
    popv(10);
    return nil;
}



/* Code for sparsematp */

static Lisp_Object CC_sparsematp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v260, v237;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sparsematp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v260 = v0;
/* end of prologue */
    v237 = v260;
    v260 = elt(env, 1); /* sparsemat */
    if (!consp(v237)) goto v7;
    v237 = qcar(v237);
    if (!(v237 == v260)) goto v7;
    v260 = qvalue(elt(env, 3)); /* t */
    return onevalue(v260);

v7:
    v260 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v260);
}



/* Code for vdpvbcprod */

static Lisp_Object CC_vdpvbcprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpvbcprod");
#endif
    if (stack >= stacklimit)
    {
        push2(v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v232 = v139;
    stack[0] = v0;
/* end of prologue */
    v243 = stack[0];
    v243 = qcdr(v243);
    v243 = qcdr(v243);
    v243 = qcdr(v243);
    v243 = qcar(v243);
    fn = elt(env, 2); /* dipbcprod */
    v232 = (*qfn2(fn))(qenv(fn), v243, v232);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    fn = elt(env, 3); /* dip2vdp */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    v243 = v232;
    v232 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v232 == nil) { popv(3); return onevalue(v243); }
    stack[-1] = v243;
    v232 = stack[0];
    fn = elt(env, 4); /* gsugar */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-2];
    {
        Lisp_Object v102 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* gsetsugar */
        return (*qfn2(fn))(qenv(fn), v102, v232);
    }
/* error exit handlers */
v261:
    popv(3);
    return nil;
}



/* Code for exdfpf */

static Lisp_Object CC_exdfpf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v156, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exdfpf");
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
    stack[-3] = nil;
    goto v169;

v169:
    v142 = stack[-2];
    if (v142 == nil) goto v236;
    v142 = stack[-2];
    v142 = qcar(v142);
    v156 = qcar(v142);
    v142 = (Lisp_Object)17; /* 1 */
    if (v156 == v142) goto v96;
    v142 = stack[-2];
    v142 = qcar(v142);
    v142 = qcar(v142);
    fn = elt(env, 2); /* exdfk */
    v156 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v142 = stack[-2];
    v142 = qcar(v142);
    v142 = qcdr(v142);
    fn = elt(env, 3); /* multpfsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v156, v142);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v142 = stack[-2];
    v142 = qcar(v142);
    v142 = qcdr(v142);
    fn = elt(env, 4); /* exdf0 */
    stack[0] = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v142 = stack[-2];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v157 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v156 = (Lisp_Object)17; /* 1 */
    v142 = (Lisp_Object)17; /* 1 */
    v142 = list2star(v157, v156, v142);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    fn = elt(env, 5); /* wedgepf2 */
    v142 = (*qfn2(fn))(qenv(fn), stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    fn = elt(env, 6); /* mkuniquewedge */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    fn = elt(env, 7); /* addpf */
    v142 = (*qfn2(fn))(qenv(fn), stack[-1], v142);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v156 = v142;
    goto v267;

v267:
    v142 = stack[-3];
    v142 = cons(v156, v142);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    stack[-3] = v142;
    v142 = stack[-2];
    v142 = qcdr(v142);
    stack[-2] = v142;
    goto v169;

v96:
    v142 = stack[-2];
    v142 = qcar(v142);
    v142 = qcdr(v142);
    fn = elt(env, 4); /* exdf0 */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v156 = v142;
    goto v267;

v236:
    v142 = qvalue(elt(env, 1)); /* nil */
    v156 = v142;
    goto v268;

v268:
    v142 = stack[-3];
    if (v142 == nil) { popv(5); return onevalue(v156); }
    v142 = stack[-3];
    v142 = qcar(v142);
    fn = elt(env, 7); /* addpf */
    v142 = (*qfn2(fn))(qenv(fn), v142, v156);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-4];
    v156 = v142;
    v142 = stack[-3];
    v142 = qcdr(v142);
    stack[-3] = v142;
    goto v268;
/* error exit handlers */
v231:
    popv(5);
    return nil;
}



/* Code for setmatpri */

static Lisp_Object CC_setmatpri(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmatpri");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v155 = v139;
    v154 = v0;
/* end of prologue */
    v155 = qcdr(v155);
    {
        fn = elt(env, 1); /* matpri1 */
        return (*qfn2(fn))(qenv(fn), v155, v154);
    }
}



/* Code for redstmtp */

static Lisp_Object CC_redstmtp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v269, v133, v151;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redstmtp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v151 = v0;
/* end of prologue */
    v269 = v151;
    if (!consp(v269)) goto v7;
    v269 = v151;
    v133 = qcar(v269);
    v269 = qvalue(elt(env, 2)); /* !*redstmtops!* */
    v269 = Lmemq(nil, v133, v269);
    if (!(v269 == nil)) return onevalue(v269);
    v269 = v151;
    v269 = qcar(v269);
    if (!consp(v269)) goto v213;
    v269 = qvalue(elt(env, 4)); /* nil */
    return onevalue(v269);

v213:
    v269 = v151;
    v269 = qcar(v269);
    v133 = qvalue(elt(env, 3)); /* !*redreswds!* */
    v269 = Lmemq(nil, v269, v133);
    v269 = (v269 == nil ? lisp_true : nil);
    return onevalue(v269);

v7:
    v269 = qvalue(elt(env, 1)); /* t */
    return onevalue(v269);
}



/* Code for listofvarnames */

static Lisp_Object CC_listofvarnames(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v276, v277;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listofvarnames");
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
    stack[0] = v0;
/* end of prologue */
    v276 = stack[0];
    fn = elt(env, 5); /* listp */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    if (v276 == nil) goto v7;
    v276 = stack[0];
    stack[-4] = v276;
    v276 = stack[-4];
    if (v276 == nil) goto v241;
    v276 = stack[-4];
    v276 = qcar(v276);
    stack[0] = v276;
    v276 = stack[0];
    fn = elt(env, 6); /* domain!*p */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    if (v276 == nil) goto v218;
    v277 = qvalue(elt(env, 3)); /* nil */
    v276 = elt(env, 4); /* free */
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v261;

v261:
    v276 = ncons(v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    stack[-2] = v276;
    stack[-3] = v276;
    goto v233;

v233:
    v276 = stack[-4];
    v276 = qcdr(v276);
    stack[-4] = v276;
    v276 = stack[-4];
    if (v276 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v276 = stack[-4];
    v276 = qcar(v276);
    stack[0] = v276;
    v276 = stack[0];
    fn = elt(env, 6); /* domain!*p */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    if (v276 == nil) goto v231;
    v277 = qvalue(elt(env, 3)); /* nil */
    v276 = elt(env, 4); /* free */
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v202;

v202:
    v276 = ncons(v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v276 = Lrplacd(nil, stack[-1], v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v276 = stack[-2];
    v276 = qcdr(v276);
    stack[-2] = v276;
    goto v233;

v231:
    v276 = stack[0];
    if (!consp(v276)) goto v198;
    v276 = stack[0];
    v276 = qcar(v276);
    if (symbolp(v276)) goto v136;
    v276 = stack[0];
    v276 = qcar(v276);
    v276 = qcar(v276);
    if (symbolp(v276)) goto v195;
    v276 = nil;
    goto v202;

v195:
    v276 = stack[0];
    v276 = qcar(v276);
    v277 = qcar(v276);
    v276 = elt(env, 4); /* free */
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v202;

v136:
    v276 = stack[0];
    v277 = qcar(v276);
    v276 = elt(env, 4); /* free */
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v202;

v198:
    v277 = qvalue(elt(env, 3)); /* nil */
    v276 = elt(env, 4); /* free */
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v202;

v218:
    v276 = stack[0];
    if (!consp(v276)) goto v130;
    v276 = stack[0];
    v276 = qcar(v276);
    if (symbolp(v276)) goto v278;
    v276 = stack[0];
    v276 = qcar(v276);
    v276 = qcar(v276);
    if (symbolp(v276)) goto v255;
    v276 = nil;
    goto v261;

v255:
    v276 = stack[0];
    v276 = qcar(v276);
    v277 = qcar(v276);
    v276 = elt(env, 4); /* free */
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v261;

v278:
    v276 = stack[0];
    v277 = qcar(v276);
    v276 = elt(env, 4); /* free */
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v261;

v130:
    v277 = qvalue(elt(env, 3)); /* nil */
    v276 = elt(env, 4); /* free */
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v261;

v241:
    v276 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v276); }

v7:
    v276 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v276 == nil)) goto v216;
    v276 = elt(env, 2); /* "invalid argument to listofvarnames" */
    fn = elt(env, 7); /* lprie */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v216;

v216:
    v276 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v222;
    v276 = nil;
    { popv(6); return onevalue(v276); }
/* error exit handlers */
v222:
    popv(6);
    return nil;
}



/* Code for mk_old_edge */

static Lisp_Object CC_mk_old_edge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v209, v207;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_old_edge");
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
    v207 = v0;
/* end of prologue */
    v209 = v207;
    v208 = qvalue(elt(env, 1)); /* old_edge_list */
    v208 = Lassoc(nil, v209, v208);
    stack[0] = v208;
    v208 = stack[0];
    if (!(v208 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    stack[0] = v207;
    v209 = v207;
    v208 = qvalue(elt(env, 2)); /* gamma5!* */
    v208 = qcar(v208);
    v208 = Lmemq(nil, v209, v208);
    if (v208 == nil) goto v133;
    v209 = qvalue(elt(env, 3)); /* ndim!* */
    v208 = qvalue(elt(env, 3)); /* ndim!* */
    v208 = cons(v209, v208);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    v209 = v208;
    goto v238;

v238:
    v208 = qvalue(elt(env, 4)); /* t */
    v208 = list3(stack[0], v209, v208);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    stack[0] = v208;
    v209 = stack[0];
    v208 = qvalue(elt(env, 1)); /* old_edge_list */
    v208 = cons(v209, v208);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    qvalue(elt(env, 1)) = v208; /* old_edge_list */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v133:
    v209 = (Lisp_Object)17; /* 1 */
    v208 = (Lisp_Object)17; /* 1 */
    v208 = cons(v209, v208);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    v209 = v208;
    goto v238;
/* error exit handlers */
v143:
    popv(2);
    return nil;
}



/* Code for mo_dlexcomp */

static Lisp_Object CC_mo_dlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v262, v240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_dlexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v262 = v139;
    v240 = v0;
/* end of prologue */
    v240 = qcar(v240);
    v262 = qcar(v262);
    fn = elt(env, 1); /* mo!=lexcomp */
    v240 = (*qfn2(fn))(qenv(fn), v240, v262);
    errexit();
    v262 = (Lisp_Object)17; /* 1 */
    v262 = (v240 == v262 ? lisp_true : nil);
    return onevalue(v262);
}



/* Code for janettreedelete */

static Lisp_Object CC_janettreedelete(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v282, v283, v284;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for janettreedelete");
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
    v282 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    if (v282 == nil) goto v8;
    stack[-2] = nil;
    stack[-1] = nil;
    v282 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    stack[-6] = v282;
    v282 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    stack[-4] = v282;
    v282 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = v282;
    v282 = (Lisp_Object)17; /* 1 */
    stack[0] = v282;
    goto v234;

v234:
    v282 = stack[-2];
    if (v282 == nil) goto v232;
    v282 = stack[-1];
    if (v282 == nil) goto v285;
    v283 = stack[-4];
    v282 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    if (v283 == v282) goto v286;
    v282 = stack[-3];
    v283 = qcdr(v282);
    v282 = stack[-4];
    v282 = qcdr(v282);
    v282 = qcar(v282);
    fn = elt(env, 4); /* setcdr */
    v282 = (*qfn2(fn))(qenv(fn), v283, v282);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    goto v287;

v287:
    v282 = stack[-4];
    v282 = qcdr(v282);
    v282 = qcar(v282);
    if (!(v282 == nil)) goto v105;
    v282 = stack[-4];
    v282 = qcdr(v282);
    v282 = qcdr(v282);
    if (!(v282 == nil)) goto v105;
    v282 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v282; /* fluidbibasisjanettreerootnode */
    goto v105;

v105:
    v282 = nil;
    { popv(8); return onevalue(v282); }

v286:
    v282 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    v282 = qcdr(v282);
    v282 = qcar(v282);
    qvalue(elt(env, 1)) = v282; /* fluidbibasisjanettreerootnode */
    goto v287;

v285:
    v282 = stack[-4];
    v283 = qcdr(v282);
    v282 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 5); /* setcar */
    v282 = (*qfn2(fn))(qenv(fn), v283, v282);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    goto v287;

v232:
    v283 = stack[-5];
    v282 = stack[0];
    fn = elt(env, 6); /* monomgetvariabledegree */
    v282 = (*qfn2(fn))(qenv(fn), v283, v282);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    v283 = v282;
    goto v151;

v151:
    v282 = stack[-6];
    if (v282 == nil) goto v133;
    v282 = stack[-6];
    v282 = qcar(v282);
    v284 = qcar(v282);
    v282 = v283;
    if (!(((int32_t)(v284)) < ((int32_t)(v282)))) goto v133;
    v284 = stack[-4];
    v282 = stack[-6];
    if (!(v284 == v282)) goto v150;
    v282 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v282;
    goto v150;

v150:
    v282 = stack[-6];
    v284 = v282;
    v282 = stack[-6];
    v282 = qcdr(v282);
    v282 = qcar(v282);
    stack[-6] = v282;
    v282 = stack[-6];
    if (v282 == nil) goto v151;
    v282 = stack[-6];
    v282 = qcdr(v282);
    v282 = qcar(v282);
    if (v282 == nil) goto v151;
    v282 = stack[-6];
    v282 = qcdr(v282);
    v282 = qcdr(v282);
    if (v282 == nil) goto v151;
    v282 = stack[-6];
    stack[-4] = v282;
    v282 = v284;
    stack[-3] = v282;
    goto v151;

v133:
    v282 = stack[-6];
    if (v282 == nil) goto v246;
    v282 = stack[-6];
    v282 = qcdr(v282);
    v282 = qcdr(v282);
    if (v282 == nil) goto v246;
    v282 = stack[0];
    v282 = (Lisp_Object)((int32_t)(v282) + 0x10);
    stack[0] = v282;
    v283 = stack[-4];
    v282 = stack[-6];
    if (!(v283 == v282)) goto v202;
    v282 = qvalue(elt(env, 3)); /* t */
    stack[-1] = v282;
    goto v202;

v202:
    v282 = stack[-6];
    v284 = v282;
    v282 = stack[-6];
    v282 = qcdr(v282);
    v282 = qcdr(v282);
    stack[-6] = v282;
    v282 = stack[-6];
    if (v282 == nil) goto v234;
    v282 = stack[-6];
    v282 = qcdr(v282);
    v282 = qcar(v282);
    if (v282 == nil) goto v234;
    v282 = stack[-6];
    v282 = qcdr(v282);
    v282 = qcdr(v282);
    if (v282 == nil) goto v234;
    v282 = stack[-6];
    stack[-4] = v282;
    v282 = v284;
    stack[-3] = v282;
    goto v234;

v246:
    v282 = qvalue(elt(env, 3)); /* t */
    stack[-2] = v282;
    goto v234;

v8:
    v282 = nil;
    { popv(8); return onevalue(v282); }
/* error exit handlers */
v68:
    popv(8);
    return nil;
}



/* Code for partities1 */

static Lisp_Object MS_CDECL CC_partities1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v139,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v245, v242, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "partities1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partities1");
#endif
    if (stack >= stacklimit)
    {
        push3(v63,v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v139,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v245 = v63;
    v242 = v139;
    v217 = v0;
/* end of prologue */
    stack[-2] = v217;
    stack[-1] = v242;
    stack[0] = v245;
    v245 = v217;
    v217 = quot2(v245, v242);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-3];
    v242 = qvalue(elt(env, 1)); /* nil */
    v245 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v261 = stack[-2];
        Lisp_Object v102 = stack[-1];
        Lisp_Object v218 = stack[0];
        popv(4);
        fn = elt(env, 2); /* mkpartitions1 */
        return (*qfnn(fn))(qenv(fn), 6, v261, v102, v218, v217, v242, v245);
    }
/* error exit handlers */
v94:
    popv(4);
    return nil;
}



/* Code for ofsf_chsimpat1 */

static Lisp_Object CC_ofsf_chsimpat1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v250, v251;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_chsimpat1");
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
    stack[0] = nil;
    stack[-3] = nil;
    v147 = stack[-2];
    v147 = qcdr(v147);
    v147 = qcar(v147);
    stack[-1] = v147;
    v147 = stack[-1];
    v147 = Lconsp(nil, v147);
    env = stack[-4];
    if (v147 == nil) goto v154;
    v147 = stack[-1];
    v250 = qcar(v147);
    v147 = elt(env, 1); /* (lessp leq equal neq geq greaterp) */
    v147 = Lmemq(nil, v250, v147);
    if (v147 == nil) goto v154;
    v147 = stack[-1];
    v147 = CC_ofsf_chsimpat1(env, v147);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-4];
    stack[0] = v147;
    v147 = stack[0];
    fn = elt(env, 2); /* lastcar */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-4];
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v147 = qcar(v147);
    stack[-1] = v147;
    goto v154;

v154:
    v147 = stack[-2];
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v147 = qcar(v147);
    v250 = v147;
    v250 = Lconsp(nil, v250);
    env = stack[-4];
    if (v250 == nil) goto v208;
    v250 = v147;
    v251 = qcar(v250);
    v250 = elt(env, 1); /* (lessp leq equal neq geq greaterp) */
    v250 = Lmemq(nil, v251, v250);
    if (v250 == nil) goto v208;
    v147 = CC_ofsf_chsimpat1(env, v147);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-4];
    stack[-3] = v147;
    v147 = stack[-3];
    v147 = qcar(v147);
    v147 = qcdr(v147);
    v147 = qcar(v147);
    goto v208;

v208:
    v250 = stack[-2];
    v251 = qcar(v250);
    v250 = stack[-1];
    v250 = list3(v251, v250, v147);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-4];
    v147 = stack[-3];
    v147 = cons(v250, v147);
    nil = C_nil;
    if (exception_pending()) goto v292;
    {
        Lisp_Object v161 = stack[0];
        popv(5);
        return Lnconc(nil, v161, v147);
    }
/* error exit handlers */
v292:
    popv(5);
    return nil;
}



/* Code for preptaycoeff */

static Lisp_Object CC_preptaycoeff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v274, v295, v296;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaycoeff");
#endif
    if (stack >= stacklimit)
    {
        push2(v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v139;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = nil;
    goto v268;

v268:
    v274 = stack[-4];
    if (v274 == nil) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v274 = stack[-5];
    v274 = qcar(v274);
    stack[-3] = v274;
    v274 = stack[-4];
    v274 = qcar(v274);
    v274 = qcar(v274);
    stack[-2] = v274;
    goto v95;

v95:
    v274 = stack[-2];
    if (v274 == nil) goto v96;
    v274 = stack[-2];
    v274 = qcar(v274);
    v296 = v274;
    v274 = stack[-4];
    v274 = qcar(v274);
    v274 = qcdr(v274);
    v295 = qcar(v274);
    v274 = elt(env, 2); /* infinity */
    if (v295 == v274) goto v275;
    stack[0] = v296;
    v274 = stack[-4];
    v274 = qcar(v274);
    v274 = qcdr(v274);
    v274 = qcar(v274);
    fn = elt(env, 4); /* reval */
    v274 = (*qfn1(fn))(qenv(fn), v274);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-7];
    fn = elt(env, 5); /* checkdifference */
    v295 = (*qfn2(fn))(qenv(fn), stack[0], v274);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-7];
    v274 = stack[-3];
    v274 = qcar(v274);
    fn = elt(env, 6); /* checkexp */
    v274 = (*qfn2(fn))(qenv(fn), v295, v274);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-7];
    v295 = v274;
    goto v102;

v102:
    v274 = stack[-6];
    v274 = cons(v295, v274);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-7];
    stack[-6] = v274;
    v274 = stack[-3];
    v274 = qcdr(v274);
    stack[-3] = v274;
    v274 = stack[-2];
    v274 = qcdr(v274);
    stack[-2] = v274;
    goto v95;

v275:
    v274 = stack[-3];
    v295 = qcar(v274);
    v274 = (Lisp_Object)1; /* 0 */
    if (v295 == v274) goto v264;
    stack[-1] = elt(env, 3); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v295 = v296;
    v274 = stack[-3];
    v274 = qcar(v274);
    fn = elt(env, 6); /* checkexp */
    v274 = (*qfn2(fn))(qenv(fn), v295, v274);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-7];
    v274 = list3(stack[-1], stack[0], v274);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-7];
    goto v235;

v235:
    v295 = v274;
    goto v102;

v264:
    v274 = (Lisp_Object)17; /* 1 */
    goto v235;

v96:
    v274 = stack[-5];
    v274 = qcdr(v274);
    stack[-5] = v274;
    v274 = stack[-4];
    v274 = qcdr(v274);
    stack[-4] = v274;
    goto v268;
/* error exit handlers */
v272:
    popv(8);
    return nil;
}



/* Code for negdf */

static Lisp_Object CC_negdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negdf");
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
    goto v8;

v8:
    v78 = stack[-1];
    if (v78 == nil) goto v268;
    v78 = stack[-1];
    v78 = qcar(v78);
    stack[0] = qcar(v78);
    v78 = stack[-1];
    v78 = qcar(v78);
    v78 = qcdr(v78);
    v78 = qcar(v78);
    fn = elt(env, 1); /* negf */
    v86 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-3];
    v78 = stack[-1];
    v78 = qcar(v78);
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    v86 = cons(v86, v78);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-3];
    v78 = stack[-2];
    v78 = acons(stack[0], v86, v78);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-3];
    stack[-2] = v78;
    v78 = stack[-1];
    v78 = qcdr(v78);
    stack[-1] = v78;
    goto v8;

v268:
    v78 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v78);
    }
/* error exit handlers */
v211:
    popv(4);
    return nil;
}



/* Code for bra_ordp */

static Lisp_Object CC_bra_ordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bra_ordp");
#endif
    if (stack >= stacklimit)
    {
        push2(v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v139;
    v155 = v0;
/* end of prologue */
    fn = elt(env, 1); /* bra_cd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-2];
    v155 = stack[0];
    fn = elt(env, 1); /* bra_cd */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-2];
    {
        Lisp_Object v267 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* cd_ordp */
        return (*qfn2(fn))(qenv(fn), v267, v155);
    }
/* error exit handlers */
v160:
    popv(3);
    return nil;
}



/* Code for mkop */

static Lisp_Object CC_mkop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v289, v290, v288;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkop");
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
    v289 = stack[0];
    if (v289 == nil) goto v216;
    v289 = stack[0];
    fn = elt(env, 11); /* gettype */
    v290 = (*qfn1(fn))(qenv(fn), v289);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-2];
    v288 = v290;
    v289 = elt(env, 3); /* operator */
    if (v290 == v289) goto v260;
    v289 = v288;
    if (v289 == nil) goto v254;
    v290 = v288;
    v289 = elt(env, 8); /* (fluid global procedure scalar) */
    v289 = Lmemq(nil, v290, v289);
    if (!(v289 == nil)) goto v254;
    v290 = stack[0];
    v289 = elt(env, 3); /* operator */
    fn = elt(env, 12); /* typerr */
    v289 = (*qfn2(fn))(qenv(fn), v290, v289);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v169;

v169:
    v289 = nil;
    { popv(3); return onevalue(v289); }

v254:
    v288 = stack[0];
    v290 = elt(env, 9); /* simpfn */
    v289 = elt(env, 10); /* simpiden */
    v289 = Lputprop(nil, 3, v288, v290, v289);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v169;

v260:
    v289 = qvalue(elt(env, 4)); /* !*msg */
    if (v289 == nil) goto v169;
    stack[-1] = elt(env, 6); /* "***" */
    v290 = stack[0];
    v289 = elt(env, 7); /* "already defined as operator" */
    v289 = list2(v290, v289);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-2];
    fn = elt(env, 13); /* lpriw */
    v289 = (*qfn2(fn))(qenv(fn), stack[-1], v289);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v169;

v216:
    v290 = elt(env, 1); /* "Local variable" */
    v289 = elt(env, 2); /* "operator" */
    fn = elt(env, 12); /* typerr */
    v289 = (*qfn2(fn))(qenv(fn), v290, v289);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v169;
/* error exit handlers */
v251:
    popv(3);
    return nil;
}



/* Code for ps!:expt!-erule */

static Lisp_Object CC_psTexptKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v319, v320;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expt-erule");
#endif
    if (stack >= stacklimit)
    {
        push2(v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v139;
    v319 = v0;
/* end of prologue */
    v182 = v319;
    v182 = qcdr(v182);
    v182 = qcar(v182);
    stack[-10] = v182;
    v182 = v319;
    v182 = qcdr(v182);
    v182 = qcdr(v182);
    v182 = qcar(v182);
    stack[-6] = v182;
    v182 = v319;
    v182 = qcdr(v182);
    v182 = qcdr(v182);
    v182 = qcdr(v182);
    v182 = qcar(v182);
    stack[-5] = v182;
    v182 = stack[-10];
    fn = elt(env, 4); /* ps!:order */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    stack[-8] = v182;
    v182 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:order */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    stack[-7] = v182;
    v319 = stack[-9];
    v182 = stack[-7];
    if (equal(v319, v182)) goto v133;
    v319 = qvalue(elt(env, 3)); /* nil */
    v182 = (Lisp_Object)17; /* 1 */
    v182 = cons(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    stack[0] = v182;
    v182 = (Lisp_Object)17; /* 1 */
    stack[-4] = v182;
    goto v157;

v157:
    v319 = stack[-9];
    v182 = stack[-7];
    v319 = difference2(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    v182 = stack[-4];
    v182 = difference2(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    v182 = Lminusp(nil, v182);
    env = stack[-11];
    if (v182 == nil) goto v199;
    v319 = stack[-9];
    v182 = stack[-7];
    v319 = difference2(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    v182 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    v319 = stack[-10];
    v182 = stack[-8];
    fn = elt(env, 5); /* ps!:evaluate */
    v182 = (*qfn2(fn))(qenv(fn), v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    fn = elt(env, 6); /* multsq */
    v182 = (*qfn2(fn))(qenv(fn), stack[-1], v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    fn = elt(env, 7); /* invsq */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    {
        Lisp_Object v48 = stack[0];
        popv(12);
        fn = elt(env, 6); /* multsq */
        return (*qfn2(fn))(qenv(fn), v48, v182);
    }

v199:
    stack[-3] = stack[0];
    v319 = stack[-4];
    v182 = stack[-6];
    stack[-1] = times2(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    stack[0] = stack[-5];
    v319 = stack[-4];
    v182 = stack[-9];
    v319 = difference2(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    v182 = stack[-7];
    v182 = plus2(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    v182 = times2(stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    v182 = plus2(stack[-1], v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    v320 = v182;
    v319 = v320;
    v182 = (Lisp_Object)1; /* 0 */
    if (v319 == v182) goto v321;
    v182 = v320;
    v319 = v182;
    goto v272;

v272:
    v182 = stack[-5];
    stack[-2] = cons(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    stack[0] = stack[-10];
    v319 = stack[-4];
    v182 = stack[-8];
    v182 = plus2(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    fn = elt(env, 5); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    stack[0] = qvalue(elt(env, 1)); /* ps */
    v319 = stack[-9];
    v182 = stack[-4];
    v182 = difference2(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    fn = elt(env, 5); /* ps!:evaluate */
    v182 = (*qfn2(fn))(qenv(fn), stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    fn = elt(env, 6); /* multsq */
    v182 = (*qfn2(fn))(qenv(fn), stack[-1], v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    fn = elt(env, 6); /* multsq */
    v182 = (*qfn2(fn))(qenv(fn), stack[-2], v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    fn = elt(env, 8); /* addsq */
    v182 = (*qfn2(fn))(qenv(fn), stack[-3], v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    stack[0] = v182;
    v182 = stack[-4];
    v182 = add1(v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    stack[-4] = v182;
    goto v157;

v321:
    v182 = qvalue(elt(env, 3)); /* nil */
    v319 = v182;
    goto v272;

v133:
    v319 = stack[-5];
    v182 = (Lisp_Object)17; /* 1 */
    if (v319 == v182) goto v218;
    v320 = elt(env, 2); /* quotient */
    v319 = stack[-6];
    v182 = stack[-5];
    v182 = list3(v320, v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    stack[0] = v182;
    goto v322;

v322:
    v319 = stack[-10];
    v182 = stack[-8];
    fn = elt(env, 5); /* ps!:evaluate */
    v182 = (*qfn2(fn))(qenv(fn), v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    fn = elt(env, 9); /* prepsqxx */
    v319 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    v182 = stack[0];
    v182 = list2(v319, v182);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-11];
    {
        popv(12);
        fn = elt(env, 10); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v182);
    }

v218:
    v182 = stack[-6];
    stack[0] = v182;
    goto v322;
/* error exit handlers */
v55:
    popv(12);
    return nil;
}



/* Code for mx */

static Lisp_Object CC_mx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mx");
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
    v101 = stack[0];
    v101 = qcar(v101);
    fn = elt(env, 1); /* reval */
    stack[-1] = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    v101 = stack[0];
    v101 = qcdr(v101);
    v101 = qcar(v101);
    fn = elt(env, 1); /* reval */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    {
        Lisp_Object v237 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* pm_m1 */
        return (*qfn2(fn))(qenv(fn), v237, v101);
    }
/* error exit handlers */
v260:
    popv(3);
    return nil;
}



/* Code for bccheckz */

static Lisp_Object CC_bccheckz(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v235, v264;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bccheckz");
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
    v210 = v0;
/* end of prologue */
    v235 = v210;
    v235 = qcar(v235);
    if (v235 == nil) { popv(3); return onevalue(v210); }
    v235 = qvalue(elt(env, 1)); /* !*bcsubs2 */
    if (v235 == nil) goto v244;
    {
        popv(3);
        fn = elt(env, 4); /* subs2 */
        return (*qfn1(fn))(qenv(fn), v210);
    }

v244:
    v264 = qvalue(elt(env, 2)); /* bczerodivl!* */
    v235 = v210;
    v235 = qcar(v235);
    v210 = qcdr(v210);
    stack[-1] = v264;
    stack[0] = v210;
    goto v234;

v234:
    v210 = stack[-1];
    if (v210 == nil) goto v256;
    v210 = v235;
    if (v210 == nil) goto v256;
    v210 = stack[-1];
    v210 = qcar(v210);
    fn = elt(env, 5); /* qremf */
    v210 = (*qfn2(fn))(qenv(fn), v235, v210);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-2];
    v210 = qcdr(v210);
    v235 = v210;
    v210 = stack[-1];
    v210 = qcdr(v210);
    stack[-1] = v210;
    goto v234;

v256:
    v210 = stack[0];
    popv(3);
    return cons(v235, v210);
/* error exit handlers */
v238:
    popv(3);
    return nil;
}



/* Code for groebfasttest */

static Lisp_Object MS_CDECL CC_groebfasttest(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v139,
                         Lisp_Object v63, Lisp_Object v4, ...)
{
    Lisp_Object v236, v268, v280, v215;
    argcheck(nargs, 4, "groebfasttest");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebfasttest");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v236 = v4;
    v268 = v63;
    v280 = v139;
    v215 = v0;
/* end of prologue */
    v236 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v236);
}



/* Code for simpexdf */

static Lisp_Object CC_simpexdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexdf");
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
    v8 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitexdf */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v8);
    }
/* error exit handlers */
v169:
    popv(1);
    return nil;
}



/* Code for gfrlmult */

static Lisp_Object CC_gfrlmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v145, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfrlmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v139;
    stack[-1] = v0;
/* end of prologue */
    v207 = stack[0];
    v207 = qcar(v207);
    if (!consp(v207)) goto v160;
    v207 = stack[-1];
    v207 = Lfloatp(nil, v207);
    env = stack[-3];
    if (v207 == nil) goto v211;
    v207 = stack[-1];
    fn = elt(env, 2); /* fl2bf */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-3];
    v145 = v207;
    goto v261;

v261:
    v207 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* gbfmult */
        return (*qfn2(fn))(qenv(fn), v145, v207);
    }

v211:
    v207 = stack[-1];
    if (!consp(v207)) goto v130;
    v207 = stack[-1];
    goto v153;

v153:
    fn = elt(env, 4); /* csl_normbf */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-3];
    v145 = v207;
    goto v261;

v130:
    v207 = stack[-1];
    v207 = integerp(v207);
    if (v207 == nil) goto v92;
    v143 = elt(env, 1); /* !:rd!: */
    v145 = stack[-1];
    v207 = (Lisp_Object)1; /* 0 */
    v207 = list2star(v143, v145, v207);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-3];
    goto v153;

v92:
    v207 = stack[-1];
    fn = elt(env, 5); /* read!:num */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-3];
    goto v153;

v160:
    v145 = stack[-1];
    v207 = stack[0];
    v207 = qcar(v207);
    stack[-2] = times2(v145, v207);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-3];
    v145 = stack[-1];
    v207 = stack[0];
    v207 = qcdr(v207);
    v207 = times2(v145, v207);
    nil = C_nil;
    if (exception_pending()) goto v263;
    {
        Lisp_Object v289 = stack[-2];
        popv(4);
        return cons(v289, v207);
    }
/* error exit handlers */
v263:
    popv(4);
    return nil;
}



/* Code for partitinnerprod */

static Lisp_Object CC_partitinnerprod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitinnerprod");
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
    v101 = stack[0];
    v101 = qcar(v101);
    fn = elt(env, 1); /* partitop */
    stack[-1] = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    v101 = stack[0];
    v101 = qcdr(v101);
    v101 = qcar(v101);
    fn = elt(env, 1); /* partitop */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    {
        Lisp_Object v237 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* innerprodpf */
        return (*qfn2(fn))(qenv(fn), v237, v101);
    }
/* error exit handlers */
v260:
    popv(3);
    return nil;
}



/* Code for dpropagator */

static Lisp_Object MS_CDECL CC_dpropagator(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v139,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v205, v203, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dpropagator");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dpropagator");
#endif
    if (stack >= stacklimit)
    {
        push3(v63,v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v139,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v63;
    v205 = v139;
    v203 = v0;
/* end of prologue */
    fn = elt(env, 2); /* propagator */
    v205 = (*qfn2(fn))(qenv(fn), v203, v205);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v80 = v205;
    v203 = v80;
    v205 = (Lisp_Object)1; /* 0 */
    if (v203 == v205) { popv(6); return onevalue(v80); }
    v203 = v80;
    v205 = (Lisp_Object)17; /* 1 */
    if (v203 == v205) goto v243;
    v205 = v80;
    v205 = qcdr(v205);
    stack[-4] = v205;
    v205 = stack[-4];
    if (v205 == nil) goto v291;
    v205 = stack[-4];
    v205 = qcar(v205);
    v203 = v205;
    v205 = stack[-3];
    fn = elt(env, 3); /* mod!-index */
    v205 = (*qfn2(fn))(qenv(fn), v203, v205);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v205 = ncons(v205);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    stack[-1] = v205;
    stack[-2] = v205;
    goto v211;

v211:
    v205 = stack[-4];
    v205 = qcdr(v205);
    stack[-4] = v205;
    v205 = stack[-4];
    if (v205 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v205 = stack[-4];
    v205 = qcar(v205);
    v203 = v205;
    v205 = stack[-3];
    fn = elt(env, 3); /* mod!-index */
    v205 = (*qfn2(fn))(qenv(fn), v203, v205);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v205 = ncons(v205);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v205 = Lrplacd(nil, stack[0], v205);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v205 = stack[-1];
    v205 = qcdr(v205);
    stack[-1] = v205;
    goto v211;

v291:
    v205 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v205); }

v243:
    v203 = qvalue(elt(env, 1)); /* nil */
    v205 = stack[-3];
    popv(6);
    return cons(v203, v205);
/* error exit handlers */
v157:
    popv(6);
    return nil;
}



/* Code for bibasis */

static Lisp_Object MS_CDECL CC_bibasis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v139,
                         Lisp_Object v63, Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28, v346;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "bibasis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bibasis");
#endif
    if (stack >= stacklimit)
    {
        push4(v4,v63,v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v139,v63,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v63;
    stack[-2] = v139;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v27 = stack[-3];
    if (v27 == nil) goto v215;
    v27 = stack[-3];
    v28 = qcar(v27);
    v27 = elt(env, 1); /* list */
    if (v28 == v27) goto v215;
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 21); /* terpri!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 3)); /* outputhandler!* */
    if (v27 == nil) goto v241;
    v346 = qvalue(elt(env, 3)); /* outputhandler!* */
    v28 = elt(env, 4); /* maprin */
    v27 = stack[-3];
    v27 = Lapply2(nil, 3, v346, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v212;

v212:
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 21); /* terpri!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v27 == nil)) goto v264;
    v27 = elt(env, 7); /* "is not a polynomial list" */
    fn = elt(env, 22); /* lprie */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v264;

v264:
    v27 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v215;

v215:
    v27 = stack[-3];
    v27 = qcdr(v27);
    if (!(v27 == nil)) goto v278;
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 21); /* terpri!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 3)); /* outputhandler!* */
    if (v27 == nil) goto v209;
    v346 = qvalue(elt(env, 3)); /* outputhandler!* */
    v28 = elt(env, 4); /* maprin */
    v27 = stack[-3];
    v27 = Lapply2(nil, 3, v346, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v254;

v254:
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 21); /* terpri!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v27 == nil)) goto v156;
    v27 = elt(env, 9); /* "polynomial list is empty" */
    fn = elt(env, 22); /* lprie */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v156;

v156:
    v27 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v278;

v278:
    v27 = stack[-2];
    if (v27 == nil) goto v159;
    v27 = stack[-2];
    v28 = qcar(v27);
    v27 = elt(env, 1); /* list */
    if (v28 == v27) goto v159;
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 21); /* terpri!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 3)); /* outputhandler!* */
    if (v27 == nil) goto v77;
    v346 = qvalue(elt(env, 3)); /* outputhandler!* */
    v28 = elt(env, 4); /* maprin */
    v27 = stack[-2];
    v27 = Lapply2(nil, 3, v346, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v272;

v272:
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 21); /* terpri!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v27 == nil)) goto v193;
    v27 = elt(env, 10); /* "is not a variable list" */
    fn = elt(env, 22); /* lprie */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v193;

v193:
    v27 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v159;

v159:
    v27 = stack[-2];
    v27 = qcdr(v27);
    if (!(v27 == nil)) goto v347;
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 21); /* terpri!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 3)); /* outputhandler!* */
    if (v27 == nil) goto v192;
    v346 = qvalue(elt(env, 3)); /* outputhandler!* */
    v28 = elt(env, 4); /* maprin */
    v27 = stack[-2];
    v27 = Lapply2(nil, 3, v346, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v348;

v348:
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 21); /* terpri!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v27 == nil)) goto v282;
    v27 = elt(env, 11); /* "variable list is empty" */
    fn = elt(env, 22); /* lprie */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v282;

v282:
    v27 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v347;

v347:
    v28 = stack[-1];
    v27 = elt(env, 12); /* lex */
    if (v28 == v27) goto v349;
    v28 = stack[-1];
    v27 = elt(env, 13); /* deglex */
    if (v28 == v27) goto v62;
    v28 = stack[-1];
    v27 = elt(env, 14); /* degrevlex */
    v27 = Lneq(nil, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v350;

v350:
    if (v27 == nil) goto v181;
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 21); /* terpri!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 3)); /* outputhandler!* */
    if (v27 == nil) goto v319;
    v346 = qvalue(elt(env, 3)); /* outputhandler!* */
    v28 = elt(env, 4); /* maprin */
    v27 = stack[-1];
    v27 = Lapply2(nil, 3, v346, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v188;

v188:
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 21); /* terpri!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v27 == nil)) goto v351;
    v27 = elt(env, 15); /* " is unsupported monomial ordering" */
    fn = elt(env, 22); /* lprie */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v351;

v351:
    v27 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v181;

v181:
    v27 = stack[-2];
    v27 = qcdr(v27);
    qvalue(elt(env, 16)) = v27; /* fluidbibasisvariables */
    v27 = stack[-1];
    qvalue(elt(env, 17)) = v27; /* fluidbibasismonomialorder */
    fn = elt(env, 23); /* init */
    v27 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 8)); /* nil */
    v27 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    stack[-2] = v27;
    v27 = stack[-3];
    if (v27 == nil) goto v352;
    v27 = stack[-3];
    v27 = qcdr(v27);
    stack[-3] = v27;
    goto v353;

v353:
    v27 = stack[-3];
    if (v27 == nil) goto v352;
    v27 = stack[-3];
    v27 = qcar(v27);
    stack[-1] = stack[-2];
    fn = elt(env, 24); /* reval */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    fn = elt(env, 25); /* simp */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qcar(v27);
    fn = elt(env, 26); /* polynomread */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    fn = elt(env, 27); /* sortedpolynomlistinsert */
    v27 = (*qfn2(fn))(qenv(fn), stack[-1], v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = stack[-3];
    v27 = qcdr(v27);
    stack[-3] = v27;
    goto v353;

v352:
    v27 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    qvalue(elt(env, 18)) = v27; /* fluidbibasisrunningtime */
    v27 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    qvalue(elt(env, 19)) = v27; /* fluidbibasisgctime */
    v28 = stack[-2];
    v27 = stack[0];
    fn = elt(env, 28); /* constructinvolutivebasis */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    stack[-2] = v27;
    v28 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 19)); /* fluidbibasisgctime */
    v27 = difference2(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    qvalue(elt(env, 19)) = v27; /* fluidbibasisgctime */
    v28 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 18)); /* fluidbibasisrunningtime */
    v28 = difference2(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 19)); /* fluidbibasisgctime */
    v27 = difference2(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    qvalue(elt(env, 18)) = v27; /* fluidbibasisrunningtime */
    goto v354;

v354:
    v27 = stack[-2];
    v27 = qcar(v27);
    if (v27 == nil) goto v29;
    stack[0] = elt(env, 20); /* !*sq */
    v27 = stack[-2];
    v27 = qcar(v27);
    fn = elt(env, 29); /* polynomwrite */
    v28 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = (Lisp_Object)17; /* 1 */
    v28 = cons(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = qvalue(elt(env, 2)); /* t */
    v28 = list3(stack[0], v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    v27 = stack[-4];
    v27 = cons(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    stack[-4] = v27;
    v27 = stack[-2];
    v27 = qcdr(v27);
    stack[-2] = v27;
    goto v354;

v29:
    stack[0] = elt(env, 1); /* list */
    v27 = stack[-4];
    v27 = Lreverse(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    {
        Lisp_Object v111 = stack[0];
        popv(6);
        return cons(v111, v27);
    }

v319:
    v27 = qvalue(elt(env, 5)); /* overflowed!* */
    if (!(v27 == nil)) goto v188;
    v28 = stack[-1];
    v27 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 30); /* maprint */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v188;

v62:
    v27 = qvalue(elt(env, 8)); /* nil */
    goto v350;

v349:
    v27 = qvalue(elt(env, 8)); /* nil */
    goto v350;

v192:
    v27 = qvalue(elt(env, 5)); /* overflowed!* */
    if (!(v27 == nil)) goto v348;
    v28 = stack[-2];
    v27 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 30); /* maprint */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v348;

v77:
    v27 = qvalue(elt(env, 5)); /* overflowed!* */
    if (!(v27 == nil)) goto v272;
    v28 = stack[-2];
    v27 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 30); /* maprint */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v272;

v209:
    v27 = qvalue(elt(env, 5)); /* overflowed!* */
    if (!(v27 == nil)) goto v254;
    v28 = stack[-3];
    v27 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 30); /* maprint */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v254;

v241:
    v27 = qvalue(elt(env, 5)); /* overflowed!* */
    if (!(v27 == nil)) goto v212;
    v28 = stack[-3];
    v27 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 30); /* maprint */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-5];
    goto v212;
/* error exit handlers */
v113:
    popv(6);
    return nil;
}



/* Code for cl_qeatal */

static Lisp_Object MS_CDECL CC_cl_qeatal(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v139,
                         Lisp_Object v63, Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v95, v97, v233, v234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_qeatal");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_qeatal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v96 = v4;
    v95 = v63;
    v97 = v139;
    v233 = v0;
/* end of prologue */
    v234 = v233;
    v233 = v97;
    v97 = v95;
    v95 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* cl_qeatal1 */
        return (*qfnn(fn))(qenv(fn), 5, v234, v233, v97, v95, v96);
    }
}



/* Code for tayminpowerlist */

static Lisp_Object CC_tayminpowerlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayminpowerlist");
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
    v95 = v0;
/* end of prologue */
    v96 = v95;
    if (v96 == nil) goto v7;
    stack[0] = v95;
    v96 = v95;
    v96 = qcar(v96);
    v96 = qcar(v96);
    v96 = Llength(nil, v96);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-1];
    {
        Lisp_Object v234 = stack[0];
        popv(2);
        fn = elt(env, 1); /* tayminpowerlist1 */
        return (*qfn2(fn))(qenv(fn), v234, v96);
    }

v7:
    v96 = elt(env, 0); /* tayminpowerlist */
    {
        popv(2);
        fn = elt(env, 2); /* confusion */
        return (*qfn1(fn))(qenv(fn), v96);
    }
/* error exit handlers */
v233:
    popv(2);
    return nil;
}



/* Code for mk!+internal!+mat */

static Lisp_Object CC_mkLinternalLmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+internal+mat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v169 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* mk!+transpose!+matrix */
        return (*qfn1(fn))(qenv(fn), v169);
    }
}



/* Code for pasf_evalatp */

static Lisp_Object CC_pasf_evalatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v139)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v209, v207, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_evalatp");
#endif
    if (stack >= stacklimit)
    {
        push2(v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v139);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v209 = v139;
    v207 = v0;
/* end of prologue */
    v208 = v207;
    v208 = Lconsp(nil, v208);
    env = stack[0];
    if (v208 == nil) goto v206;
    v208 = v207;
    v145 = qcar(v208);
    v208 = elt(env, 1); /* (cong ncong) */
    v208 = Lmemq(nil, v145, v208);
    if (v208 == nil) goto v206;
    v208 = v207;
    v208 = qcdr(v208);
    if (!consp(v208)) goto v234;
    v208 = v207;
    v208 = qcdr(v208);
    v208 = qcar(v208);
    v208 = (consp(v208) ? nil : lisp_true);
    goto v233;

v233:
    if (v208 == nil) goto v131;
    v208 = v207;
    v208 = qcar(v208);
    v207 = qcdr(v207);
    {
        popv(1);
        fn = elt(env, 6); /* pasf_evalatpm */
        return (*qfnn(fn))(qenv(fn), 3, v208, v209, v207);
    }

v131:
    v208 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v208 == nil)) goto v130;
    v208 = elt(env, 4); /* "pasf_evalatp : parametric modulus in input" 
*/
    v208 = ncons(v208);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[0];
    fn = elt(env, 7); /* lprie */
    v208 = (*qfn1(fn))(qenv(fn), v208);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[0];
    goto v130;

v130:
    v208 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v143;
    v208 = nil;
    { popv(1); return onevalue(v208); }

v234:
    v208 = qvalue(elt(env, 2)); /* t */
    goto v233;

v206:
    v208 = qvalue(elt(env, 5)); /* nil */
    {
        popv(1);
        fn = elt(env, 6); /* pasf_evalatpm */
        return (*qfnn(fn))(qenv(fn), 3, v207, v209, v208);
    }
/* error exit handlers */
v143:
    popv(1);
    return nil;
}



/* Code for dipdivmon */

static Lisp_Object MS_CDECL CC_dipdivmon(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v139,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v291;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipdivmon");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipdivmon");
#endif
    if (stack >= stacklimit)
    {
        push3(v63,v139,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v139,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v63;
    stack[-1] = v139;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v236;

v236:
    v153 = stack[-2];
    if (v153 == nil) goto v215;
    v153 = stack[-2];
    v291 = qcar(v153);
    v153 = stack[0];
    fn = elt(env, 1); /* evdif */
    v291 = (*qfn2(fn))(qenv(fn), v291, v153);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v153 = stack[-3];
    v153 = cons(v291, v153);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    stack[-3] = v153;
    v153 = stack[-2];
    v153 = qcdr(v153);
    v291 = qcar(v153);
    v153 = stack[-1];
    fn = elt(env, 2); /* bcquot */
    v291 = (*qfn2(fn))(qenv(fn), v291, v153);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    v153 = stack[-3];
    v153 = cons(v291, v153);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-4];
    stack[-3] = v153;
    v153 = stack[-2];
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    stack[-2] = v153;
    goto v236;

v215:
    v153 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v153);
    }
/* error exit handlers */
v279:
    popv(5);
    return nil;
}



setup_type const u53_setup[] =
{
    {"st_ad_numsorttree1",      CC_st_ad_numsorttree1,too_many_1,wrong_no_1},
    {"ofsf_transform",          too_few_2,      CC_ofsf_transform,wrong_no_2},
    {"typelet",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_typelet},
    {"find-non-zero",           CC_findKnonKzero,too_many_1,   wrong_no_1},
    {"get*real*comp*chartype*p",too_few_2,      CC_getHrealHcompHchartypeHp,wrong_no_2},
    {"cgp_normalize",           CC_cgp_normalize,too_many_1,   wrong_no_1},
    {"ps:quotient-erule",       too_few_2,      CC_psTquotientKerule,wrong_no_2},
    {"sparsematp",              CC_sparsematp,  too_many_1,    wrong_no_1},
    {"vdpvbcprod",              too_few_2,      CC_vdpvbcprod, wrong_no_2},
    {"exdfpf",                  CC_exdfpf,      too_many_1,    wrong_no_1},
    {"setmatpri",               too_few_2,      CC_setmatpri,  wrong_no_2},
    {"redstmtp",                CC_redstmtp,    too_many_1,    wrong_no_1},
    {"listofvarnames",          CC_listofvarnames,too_many_1,  wrong_no_1},
    {"mk_old_edge",             CC_mk_old_edge, too_many_1,    wrong_no_1},
    {"mo_dlexcomp",             too_few_2,      CC_mo_dlexcomp,wrong_no_2},
    {"janettreedelete",         CC_janettreedelete,too_many_1, wrong_no_1},
    {"partities1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_partities1},
    {"ofsf_chsimpat1",          CC_ofsf_chsimpat1,too_many_1,  wrong_no_1},
    {"preptaycoeff",            too_few_2,      CC_preptaycoeff,wrong_no_2},
    {"negdf",                   CC_negdf,       too_many_1,    wrong_no_1},
    {"bra_ordp",                too_few_2,      CC_bra_ordp,   wrong_no_2},
    {"mkop",                    CC_mkop,        too_many_1,    wrong_no_1},
    {"ps:expt-erule",           too_few_2,      CC_psTexptKerule,wrong_no_2},
    {"mx",                      CC_mx,          too_many_1,    wrong_no_1},
    {"bccheckz",                CC_bccheckz,    too_many_1,    wrong_no_1},
    {"groebfasttest",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebfasttest},
    {"simpexdf",                CC_simpexdf,    too_many_1,    wrong_no_1},
    {"gfrlmult",                too_few_2,      CC_gfrlmult,   wrong_no_2},
    {"partitinnerprod",         CC_partitinnerprod,too_many_1, wrong_no_1},
    {"dpropagator",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_dpropagator},
    {"bibasis",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_bibasis},
    {"cl_qeatal",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_qeatal},
    {"tayminpowerlist",         CC_tayminpowerlist,too_many_1, wrong_no_1},
    {"mk+internal+mat",         CC_mkLinternalLmat,too_many_1, wrong_no_1},
    {"pasf_evalatp",            too_few_2,      CC_pasf_evalatp,wrong_no_2},
    {"dipdivmon",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipdivmon},
    {NULL, (one_args *)"u53", (two_args *)"7697 4303368 381270", 0}
};

/* end of generated code */
