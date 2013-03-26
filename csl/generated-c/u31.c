
/* $destdir\u31.c        Machine generated C code */

/* Signature: 00000000 26-Mar-2013 */

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
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
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
extern intptr_t modulus_is_large;
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
extern Lisp_Object declare_symbol, special_symbol, large_modulus;
extern Lisp_Object used_space, avail_space;
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
#define modulus_is_large      BASE[32]
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
#define large_modulus         BASE[184]
#define used_space            BASE[185]
#define avail_space           BASE[186]
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
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
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
extern Lisp_Object bytecounts1(Lisp_Object env, Lisp_Object a);
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


/* Code for numprintlen */

static Lisp_Object CC_numprintlen(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numprintlen");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */

v0034:
    v0032 = stack[-1];
    if (!consp(v0032)) goto v0035;
    v0032 = stack[-1];
    v0032 = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = Lonep(nil, v0032);
    env = stack[-6];
    if (v0032 == nil) goto v0037;
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    stack[-1] = v0032;
    goto v0034;

v0037:
    v0032 = stack[-1];
    v0033 = qcar(v0032);
    v0032 = elt(env, 1); /* !:rd!: */
    if (v0033 == v0032) goto v0038;
    v0032 = stack[-1];
    v0033 = qcar(v0032);
    v0032 = elt(env, 2); /* (!:cr!: !:crn!: !:gi!:) */
    v0032 = Lmemq(nil, v0033, v0032);
    if (v0032 == nil) goto v0039;
    v0033 = elt(env, 1); /* !:rd!: */
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    v0032 = cons(v0033, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    fn = elt(env, 5); /* rd!:explode */
    stack[0] = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0033 = elt(env, 1); /* !:rd!: */
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = cons(v0033, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    fn = elt(env, 5); /* rd!:explode */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = cons(stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    stack[-1] = v0032;
    stack[-4] = (Lisp_Object)193; /* 12 */
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    v0032 = qcar(v0032);
    stack[-3] = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    v0032 = qcdr(v0032);
    v0032 = Lexplode(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    stack[-2] = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    stack[0] = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = Lexplode(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = plus2(stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = plus2(stack[-2], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = plus2(stack[-3], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    {
        Lisp_Object v0040 = stack[-4];
        popv(7);
        return plus2(v0040, v0032);
    }

v0039:
    v0032 = stack[-1];
    stack[-5] = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    stack[-4] = elt(env, 3); /* plus */
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    stack[-3] = v0032;
    v0032 = stack[-3];
    if (v0032 == nil) goto v0041;
    v0032 = stack[-3];
    v0032 = qcar(v0032);
    v0032 = CC_numprintlen(env, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = ncons(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    stack[-1] = v0032;
    stack[-2] = v0032;
    goto v0042;

v0042:
    v0032 = stack[-3];
    v0032 = qcdr(v0032);
    stack[-3] = v0032;
    v0032 = stack[-3];
    if (v0032 == nil) goto v0043;
    stack[0] = stack[-1];
    v0032 = stack[-3];
    v0032 = qcar(v0032);
    v0032 = CC_numprintlen(env, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = ncons(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = Lrplacd(nil, stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    stack[-1] = v0032;
    goto v0042;

v0043:
    v0032 = stack[-2];
    goto v0044;

v0044:
    v0032 = cons(stack[-4], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    fn = elt(env, 6); /* lispeval */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    {
        Lisp_Object v0045 = stack[-5];
        popv(7);
        return plus2(v0045, v0032);
    }

v0041:
    v0032 = qvalue(elt(env, 4)); /* nil */
    goto v0044;

v0038:
    v0032 = stack[-1];
    fn = elt(env, 5); /* rd!:explode */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    stack[-1] = v0032;
    stack[-2] = (Lisp_Object)33; /* 2 */
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    stack[0] = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    v0032 = Lexplode(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-6];
    v0032 = plus2(stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    {
        Lisp_Object v0046 = stack[-2];
        popv(7);
        return plus2(v0046, v0032);
    }

v0035:
    v0032 = stack[-1];
    v0032 = Lexplode(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0036;
        popv(7);
        return Llength(nil, v0032);
/* error exit handlers */
v0036:
    popv(7);
    return nil;
}



/* Code for consrecip */

static Lisp_Object CC_consrecip(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054, v0055;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for consrecip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0055 = v0000;
/* end of prologue */
    v0053 = v0055;
    v0054 = qcar(v0053);
    v0053 = (Lisp_Object)17; /* 1 */
    if (v0054 == v0053) goto v0056;
    v0053 = v0055;
    v0054 = qcar(v0053);
    v0053 = (Lisp_Object)-15; /* -1 */
    v0053 = (v0054 == v0053 ? lisp_true : nil);
    goto v0035;

v0035:
    if (v0053 == nil) goto v0057;
    v0053 = v0055;
    v0053 = qcar(v0053);
    return onevalue(v0053);

v0057:
    v0053 = elt(env, 2); /* recip */
    v0054 = v0055;
    return cons(v0053, v0054);

v0056:
    v0053 = qvalue(elt(env, 1)); /* t */
    goto v0035;
}



/* Code for arglength */

static Lisp_Object CC_arglength(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arglength");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0050 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*intstr */
    qvalue(elt(env, 1)) = nil; /* !*intstr */
    v0061 = v0050;
    if (v0061 == nil) goto v0056;
    v0061 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0061; /* !*intstr */
    v0061 = v0050;
    fn = elt(env, 3); /* reval */
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0050 = v0061;
    v0061 = v0050;
    if (!consp(v0061)) goto v0051;
    v0061 = v0050;
    v0061 = qcdr(v0061);
    v0061 = Llength(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    goto v0062;

v0062:
    qvalue(elt(env, 1)) = stack[0]; /* !*intstr */
    { popv(2); return onevalue(v0061); }

v0051:
    v0061 = (Lisp_Object)-15; /* -1 */
    goto v0062;

v0056:
    v0061 = (Lisp_Object)1; /* 0 */
    goto v0062;
/* error exit handlers */
v0030:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*intstr */
    popv(2);
    return nil;
}



/* Code for general!-multiply!-by!-constant!-mod!-p */

static Lisp_Object CC_generalKmultiplyKbyKconstantKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-multiply-by-constant-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0063;
    stack[-2] = v0000;
/* end of prologue */
    v0071 = stack[-2];
    if (v0071 == nil) goto v0062;
    v0072 = stack[-1];
    v0071 = (Lisp_Object)17; /* 1 */
    if (v0072 == v0071) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0071 = stack[-2];
    if (!consp(v0071)) goto v0073;
    v0071 = stack[-2];
    v0071 = qcar(v0071);
    v0071 = (consp(v0071) ? nil : lisp_true);
    goto v0037;

v0037:
    if (v0071 == nil) goto v0055;
    v0072 = stack[-2];
    v0071 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-times */
    v0071 = (*qfn2(fn))(qenv(fn), v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 4); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0071);
    }

v0055:
    v0071 = stack[-2];
    v0071 = qcar(v0071);
    stack[-3] = qcar(v0071);
    v0071 = stack[-2];
    v0071 = qcar(v0071);
    v0072 = qcdr(v0071);
    v0071 = stack[-1];
    stack[0] = CC_generalKmultiplyKbyKconstantKmodKp(env, v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    v0071 = stack[-2];
    v0072 = qcdr(v0071);
    v0071 = stack[-1];
    v0071 = CC_generalKmultiplyKbyKconstantKmodKp(env, v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    {
        Lisp_Object v0023 = stack[-3];
        Lisp_Object v0019 = stack[0];
        popv(5);
        fn = elt(env, 5); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0023, v0019, v0071);
    }

v0073:
    v0071 = qvalue(elt(env, 2)); /* t */
    goto v0037;

v0062:
    v0071 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0071); }
/* error exit handlers */
v0074:
    popv(5);
    return nil;
}



/* Code for algmodep */

static Lisp_Object CC_algmodep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0038;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for algmodep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0038 = v0000;
/* end of prologue */
    v0077 = v0038;
    if (!consp(v0077)) goto v0052;
    v0077 = v0038;
    v0077 = qcar(v0077);
    v0038 = elt(env, 1); /* (aeval aeval!*) */
    v0077 = Lmemq(nil, v0077, v0038);
    return onevalue(v0077);

v0052:
    v0077 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0077);
}



/* Code for createmonomunit */

static Lisp_Object MS_CDECL CC_createmonomunit(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0030, v0080;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "createmonomunit");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for createmonomunit");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    v0031 = (Lisp_Object)17; /* 1 */
    v0031 = Lmkvect(nil, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-3];
    stack[-2] = v0031;
    v0080 = stack[-2];
    v0030 = (Lisp_Object)1; /* 0 */
    v0031 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0080 + (CELL-TAG_VECTOR) + ((int32_t)v0030/(16/CELL))) = v0031;
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)17; /* 1 */
    v0031 = qvalue(elt(env, 1)); /* nil */
    v0031 = ncons(v0031);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0031;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v0081:
    popv(4);
    return nil;
}



/* Code for rtypepart */

static Lisp_Object CC_rtypepart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rtypepart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0082 = v0000;
/* end of prologue */
    fn = elt(env, 3); /* getrtypecar */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[0];
    if (v0082 == nil) goto v0083;
    v0082 = elt(env, 1); /* yetunknowntype */
    { popv(1); return onevalue(v0082); }

v0083:
    v0082 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0082); }
/* error exit handlers */
v0076:
    popv(1);
    return nil;
}



/* Code for pasf_ceil */

static Lisp_Object CC_pasf_ceil(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0096, v0097;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_ceil");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0063;
    stack[-1] = v0000;
/* end of prologue */
    v0095 = stack[-1];
    if (!consp(v0095)) goto v0076;
    v0095 = stack[-1];
    v0095 = qcar(v0095);
    v0095 = (consp(v0095) ? nil : lisp_true);
    goto v0082;

v0082:
    if (v0095 == nil) goto v0098;
    v0095 = stack[0];
    if (!consp(v0095)) goto v0078;
    v0095 = stack[0];
    v0095 = qcar(v0095);
    v0095 = (consp(v0095) ? nil : lisp_true);
    goto v0056;

v0056:
    if (v0095 == nil) goto v0099;
    v0095 = stack[-1];
    if (v0095 == nil) goto v0027;
    v0096 = stack[-1];
    v0095 = stack[0];
    v0096 = Cremainder(v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0095 = (Lisp_Object)1; /* 0 */
    if (v0096 == v0095) goto v0066;
    v0096 = stack[-1];
    v0095 = stack[0];
    v0096 = times2(v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0095 = (Lisp_Object)1; /* 0 */
    v0095 = (Lisp_Object)greaterp2(v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    v0095 = v0095 ? lisp_true : nil;
    env = stack[-2];
    if (v0095 == nil) goto v0101;
    v0096 = stack[-1];
    v0095 = stack[0];
    v0095 = quot2(v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0095 = add1(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    goto v0102;

v0102:
    fn = elt(env, 4); /* simp */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    v0095 = qcar(v0095);
    { popv(3); return onevalue(v0095); }

v0101:
    v0096 = stack[-1];
    v0095 = stack[0];
    v0095 = quot2(v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    goto v0102;

v0066:
    v0096 = stack[-1];
    v0095 = stack[0];
    v0095 = quot2(v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    goto v0102;

v0027:
    v0095 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0095); }

v0099:
    v0097 = elt(env, 3); /* "pasf_ceil: not a domain valued sf in input" 
*/
    v0096 = stack[-1];
    v0095 = stack[0];
    v0095 = list3(v0097, v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 5); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0095);
    }

v0078:
    v0095 = qvalue(elt(env, 1)); /* t */
    goto v0056;

v0098:
    v0095 = qvalue(elt(env, 2)); /* nil */
    goto v0056;

v0076:
    v0095 = qvalue(elt(env, 1)); /* t */
    goto v0082;
/* error exit handlers */
v0100:
    popv(3);
    return nil;
}



/* Code for aex_red */

static Lisp_Object CC_aex_red(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0104, v0105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_red");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0057 = v0063;
    stack[0] = v0000;
/* end of prologue */
    v0104 = stack[0];
    fn = elt(env, 2); /* aex_mvaroccurtest */
    v0057 = (*qfn2(fn))(qenv(fn), v0104, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    if (v0057 == nil) goto v0106;
    v0057 = stack[0];
    fn = elt(env, 3); /* aex_ex */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_red */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    v0057 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v0105 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    v0104 = qvalue(elt(env, 1)); /* nil */
    v0057 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0047 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v0047, v0105, v0104, v0057);
    }

v0106:
    {
        popv(3);
        fn = elt(env, 7); /* aex_0 */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0048:
    popv(3);
    return nil;
}



/* Code for rl_updcache */

static Lisp_Object MS_CDECL CC_rl_updcache(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0114;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rl_updcache");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_updcache");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    v0113 = qvalue(elt(env, 1)); /* rl_bbl!* */
    stack[0] = v0113;
    goto v0034;

v0034:
    v0113 = stack[0];
    if (v0113 == nil) goto v0080;
    v0113 = stack[0];
    v0113 = qcar(v0113);
    v0114 = v0113;
    v0113 = qvalue(elt(env, 2)); /* nil */
    v0113 = Lset(nil, v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    v0113 = stack[0];
    v0113 = qcdr(v0113);
    stack[0] = v0113;
    goto v0034;

v0080:
    v0113 = qvalue(elt(env, 3)); /* rl_cid!* */
    v0114 = qcar(v0113);
    v0113 = elt(env, 4); /* rl_params */
    v0113 = get(v0114, v0113);
    env = stack[-1];
    stack[0] = v0113;
    goto v0031;

v0031:
    v0113 = stack[0];
    if (v0113 == nil) goto v0050;
    v0113 = stack[0];
    v0113 = qcar(v0113);
    v0114 = v0113;
    v0114 = qcar(v0114);
    v0113 = qcdr(v0113);
    v0113 = Lset(nil, v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    v0113 = stack[0];
    v0113 = qcdr(v0113);
    stack[0] = v0113;
    goto v0031;

v0050:
    v0113 = qvalue(elt(env, 5)); /* rl_servl!* */
    stack[0] = v0113;
    goto v0025;

v0025:
    v0113 = stack[0];
    if (v0113 == nil) goto v0020;
    v0113 = stack[0];
    v0113 = qcar(v0113);
    v0114 = v0113;
    v0113 = qvalue(elt(env, 2)); /* nil */
    v0113 = Lset(nil, v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    v0113 = stack[0];
    v0113 = qcdr(v0113);
    stack[0] = v0113;
    goto v0025;

v0020:
    v0113 = qvalue(elt(env, 3)); /* rl_cid!* */
    v0114 = qcar(v0113);
    v0113 = elt(env, 6); /* rl_services */
    v0113 = get(v0114, v0113);
    env = stack[-1];
    stack[0] = v0113;
    goto v0091;

v0091:
    v0113 = stack[0];
    if (v0113 == nil) goto v0011;
    v0113 = stack[0];
    v0113 = qcar(v0113);
    v0114 = v0113;
    v0114 = qcar(v0114);
    v0113 = qcdr(v0113);
    v0113 = Lset(nil, v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    v0113 = stack[0];
    v0113 = qcdr(v0113);
    stack[0] = v0113;
    goto v0091;

v0011:
    v0113 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0113); }
/* error exit handlers */
v0015:
    popv(2);
    return nil;
}



/* Code for intervalrd */

static Lisp_Object MS_CDECL CC_intervalrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "intervalrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intervalrd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    fn = elt(env, 4); /* mathml */
    v0105 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    stack[-1] = v0105;
    fn = elt(env, 4); /* mathml */
    v0105 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    stack[0] = v0105;
    fn = elt(env, 5); /* lex */
    v0105 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    v0027 = qvalue(elt(env, 1)); /* char */
    v0105 = elt(env, 2); /* (!/ i n t e r v a l) */
    if (equal(v0027, v0105)) goto v0038;
    v0027 = elt(env, 3); /* "</interval>" */
    v0105 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v0105 = (*qfn2(fn))(qenv(fn), v0027, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    v0105 = nil;
    { popv(3); return onevalue(v0105); }

v0038:
    v0027 = stack[-1];
    v0105 = stack[0];
    popv(3);
    return list2(v0027, v0105);
/* error exit handlers */
v0047:
    popv(3);
    return nil;
}



/* Code for d2int */

static Lisp_Object CC_d2int(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0090, v0091;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for d2int");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0090 = v0000;
/* end of prologue */
    v0121 = v0090;
    v0091 = qcdr(v0121);
    v0121 = (Lisp_Object)17; /* 1 */
    if (v0091 == v0121) goto v0062;
    v0121 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0121); }

v0062:
    v0121 = v0090;
    v0121 = qcar(v0121);
    v0090 = v0121;
    if (is_number(v0121)) { popv(3); return onevalue(v0090); }
    v0121 = v0090;
    if (!consp(v0121)) goto v0031;
    v0121 = v0090;
    v0121 = qcar(v0121);
    v0121 = (consp(v0121) ? nil : lisp_true);
    goto v0050;

v0050:
    if (v0121 == nil) goto v0078;
    v0121 = v0090;
    v0091 = qcar(v0121);
    v0121 = elt(env, 3); /* !:rd!: */
    v0121 = (v0091 == v0121 ? lisp_true : nil);
    v0121 = (v0121 == nil ? lisp_true : nil);
    goto v0073;

v0073:
    if (v0121 == nil) goto v0122;
    v0121 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0121); }

v0122:
    v0121 = v0090;
    v0121 = qcdr(v0121);
    stack[-1] = v0121;
    v0121 = stack[-1];
    v0121 = Ltruncate(nil, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    stack[0] = v0121;
    v0121 = stack[0];
    v0090 = Lfloat(nil, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    v0121 = stack[-1];
    v0121 = difference2(v0090, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    v0090 = Labsval(nil, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    v0121 = qvalue(elt(env, 4)); /* !!fleps1 */
    v0121 = (Lisp_Object)lessp2(v0090, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    v0121 = v0121 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0121 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0121 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0121); }

v0078:
    v0121 = qvalue(elt(env, 2)); /* t */
    goto v0073;

v0031:
    v0121 = qvalue(elt(env, 2)); /* t */
    goto v0050;
/* error exit handlers */
v0123:
    popv(3);
    return nil;
}



/* Code for simpimpart */

static Lisp_Object CC_simpimpart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpimpart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0083 = v0000;
/* end of prologue */
    v0056 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*factor */
    qvalue(elt(env, 2)) = v0056; /* !*factor */
    v0056 = v0083;
    v0056 = qcar(v0056);
    fn = elt(env, 3); /* simp!* */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-1];
    fn = elt(env, 4); /* impartsq */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*factor */
    { popv(2); return onevalue(v0056); }
/* error exit handlers */
v0094:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*factor */
    popv(2);
    return nil;
}



/* Code for indexvp */

static Lisp_Object CC_indexvp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0075;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexvp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0075 = v0000;
/* end of prologue */
    v0076 = v0075;
    if (!consp(v0076)) goto v0124;
    v0076 = v0075;
    v0076 = qcar(v0076);
    if (!symbolp(v0076)) v0076 = nil;
    else { v0076 = qfastgets(v0076);
           if (v0076 != nil) { v0076 = elt(v0076, 16); /* indexvar */
#ifdef RECORD_GET
             if (v0076 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0076 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0076 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0076 == SPID_NOPROP) v0076 = nil; else v0076 = lisp_true; }}
#endif
    return onevalue(v0076);

v0124:
    v0076 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0076);
}



/* Code for cvitimes2 */

static Lisp_Object CC_cvitimes2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069, v0066, v0125, v0126;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cvitimes2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0125 = v0063;
    v0126 = v0000;
/* end of prologue */
    v0066 = v0126;
    v0069 = (Lisp_Object)1; /* 0 */
    if (v0066 == v0069) goto v0083;
    v0066 = v0125;
    v0069 = (Lisp_Object)1; /* 0 */
    v0069 = (v0066 == v0069 ? lisp_true : nil);
    goto v0056;

v0056:
    if (v0069 == nil) goto v0106;
    v0069 = (Lisp_Object)1; /* 0 */
    return onevalue(v0069);

v0106:
    v0066 = v0126;
    v0069 = (Lisp_Object)17; /* 1 */
    if (v0066 == v0069) return onevalue(v0125);
    v0066 = v0125;
    v0069 = (Lisp_Object)17; /* 1 */
    if (v0066 == v0069) return onevalue(v0126);
    v0069 = elt(env, 2); /* times */
    v0066 = v0126;
    return list3(v0069, v0066, v0125);

v0083:
    v0069 = qvalue(elt(env, 1)); /* t */
    goto v0056;
}



/* Code for mod_eval_uni_poly */

static Lisp_Object CC_mod_eval_uni_poly(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0084, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod_eval_uni_poly");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0063;
    stack[-2] = v0000;
/* end of prologue */
    v0015 = stack[-2];
    if (!consp(v0015)) goto v0062;
    v0015 = stack[-2];
    v0015 = qcar(v0015);
    v0015 = qcdr(v0015);
    fn = elt(env, 3); /* mod!# */
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0095 = v0015;
    v0015 = stack[-2];
    v0015 = qcar(v0015);
    v0015 = qcar(v0015);
    v0015 = qcdr(v0015);
    v0084 = v0015;
    v0015 = stack[-2];
    v0015 = qcdr(v0015);
    stack[-2] = v0015;
    goto v0031;

v0031:
    v0015 = stack[-2];
    if (!consp(v0015)) goto v0131;
    stack[-3] = v0095;
    stack[0] = stack[-1];
    v0015 = stack[-2];
    v0015 = qcar(v0015);
    v0015 = qcar(v0015);
    v0015 = qcdr(v0015);
    v0015 = difference2(v0084, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    fn = elt(env, 4); /* general!-modular!-expt */
    v0015 = (*qfn2(fn))(qenv(fn), stack[0], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0084 = times2(stack[-3], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0015 = qvalue(elt(env, 2)); /* current!-modulus */
    stack[0] = Cremainder(v0084, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0015 = stack[-2];
    v0015 = qcar(v0015);
    v0015 = qcdr(v0015);
    fn = elt(env, 3); /* mod!# */
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    fn = elt(env, 5); /* general!-modular!-plus */
    v0015 = (*qfn2(fn))(qenv(fn), stack[0], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0095 = v0015;
    v0015 = stack[-2];
    v0015 = qcar(v0015);
    v0015 = qcar(v0015);
    v0015 = qcdr(v0015);
    v0084 = v0015;
    v0015 = stack[-2];
    v0015 = qcdr(v0015);
    stack[-2] = v0015;
    goto v0031;

v0131:
    stack[0] = v0095;
    v0015 = stack[-1];
    fn = elt(env, 4); /* general!-modular!-expt */
    v0015 = (*qfn2(fn))(qenv(fn), v0015, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0084 = times2(stack[0], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0015 = qvalue(elt(env, 2)); /* current!-modulus */
    v0015 = Cremainder(v0084, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    v0095 = v0015;
    v0015 = stack[-2];
    if (v0015 == nil) { popv(5); return onevalue(v0095); }
    stack[0] = v0095;
    v0015 = stack[-2];
    fn = elt(env, 3); /* mod!# */
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-4];
    fn = elt(env, 5); /* general!-modular!-plus */
    v0015 = (*qfn2(fn))(qenv(fn), stack[0], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    v0095 = v0015;
    { popv(5); return onevalue(v0095); }

v0062:
    v0015 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* mod!# */
        return (*qfn1(fn))(qenv(fn), v0015);
    }
/* error exit handlers */
v0100:
    popv(5);
    return nil;
}



/* Code for precision */

static Lisp_Object CC_precision(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0053, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for precision");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0047 = stack[0];
    if (is_number(v0047)) goto v0059;
    v0047 = qvalue(elt(env, 1)); /* t */
    goto v0035;

v0035:
    if (v0047 == nil) goto v0081;
    v0054 = elt(env, 2); /* arith */
    v0053 = (Lisp_Object)97; /* 6 */
    v0047 = elt(env, 3); /* "positive number required" */
    fn = elt(env, 4); /* rerror */
    v0047 = (*qfnn(fn))(qenv(fn), 3, v0054, v0053, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-1];
    goto v0081;

v0081:
    v0053 = stack[0];
    v0047 = qvalue(elt(env, 1)); /* t */
    {
        popv(2);
        fn = elt(env, 5); /* precision1 */
        return (*qfn2(fn))(qenv(fn), v0053, v0047);
    }

v0059:
    v0053 = stack[0];
    v0047 = (Lisp_Object)1; /* 0 */
    v0047 = (Lisp_Object)lessp2(v0053, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    v0047 = v0047 ? lisp_true : nil;
    env = stack[-1];
    goto v0035;
/* error exit handlers */
v0028:
    popv(2);
    return nil;
}



/* Code for use!-berlekamp */

static Lisp_Object MS_CDECL CC_useKberlekamp(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0063,
                         Lisp_Object v0058, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0185, v0186, v0187, v0188, v0189, v0190, v0191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "use-berlekamp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for use-berlekamp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0063,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0058;
    stack[-5] = v0063;
    stack[-6] = v0000;
/* end of prologue */
    v0185 = qvalue(elt(env, 1)); /* dpoly */
    v0185 = (Lisp_Object)((int32_t)(v0185) - 0x10);
    stack[-3] = v0185;
    v0185 = stack[-3];
    v0185 = Lmkvect(nil, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-8];
    stack[-7] = v0185;
    v0185 = (Lisp_Object)1; /* 0 */
    stack[0] = v0185;
    goto v0078;

v0078:
    v0186 = stack[-3];
    v0185 = stack[0];
    v0185 = (Lisp_Object)(int32_t)((int32_t)v0186 - (int32_t)v0185 + TAG_FIXNUM);
    v0185 = ((intptr_t)(v0185) < 0 ? lisp_true : nil);
    if (v0185 == nil) goto v0070;
    v0188 = stack[-6];
    v0187 = stack[-5];
    v0186 = qvalue(elt(env, 3)); /* poly!-vector */
    v0185 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v0185 = (*qfnn(fn))(qenv(fn), 4, v0188, v0187, v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-8];
    stack[-5] = v0185;
    v0185 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0185;
    v0185 = stack[-3];
    v0185 = Lmkvect(nil, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-8];
    stack[-1] = v0185;
    v0187 = stack[-1];
    v0186 = (Lisp_Object)1; /* 0 */
    v0185 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v0187 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL))) = v0185;
    v0185 = (Lisp_Object)17; /* 1 */
    stack[0] = v0185;
    goto v0014;

v0014:
    v0186 = stack[-3];
    v0185 = stack[0];
    v0185 = (Lisp_Object)(int32_t)((int32_t)v0186 - (int32_t)v0185 + TAG_FIXNUM);
    v0185 = ((intptr_t)(v0185) < 0 ? lisp_true : nil);
    if (v0185 == nil) goto v0193;
    v0186 = stack[-7];
    v0185 = stack[-3];
    {
        popv(9);
        fn = elt(env, 6); /* find!-null!-space */
        return (*qfn2(fn))(qenv(fn), v0186, v0185);
    }

v0193:
    v0186 = qvalue(elt(env, 4)); /* current!-modulus */
    v0185 = qvalue(elt(env, 1)); /* dpoly */
    if (((int32_t)(v0186)) > ((int32_t)(v0185))) goto v0194;
    v0185 = (Lisp_Object)1; /* 0 */
    v0188 = v0185;
    goto v0195;

v0195:
    v0185 = qvalue(elt(env, 4)); /* current!-modulus */
    v0186 = (Lisp_Object)((int32_t)(v0185) - 0x10);
    v0185 = v0188;
    v0185 = (Lisp_Object)(int32_t)((int32_t)v0186 - (int32_t)v0185 + TAG_FIXNUM);
    v0185 = ((intptr_t)(v0185) < 0 ? lisp_true : nil);
    if (v0185 == nil) goto v0196;
    v0185 = (Lisp_Object)1; /* 0 */
    v0189 = v0185;
    goto v0032;

v0032:
    v0186 = stack[-2];
    v0185 = v0189;
    v0185 = (Lisp_Object)(int32_t)((int32_t)v0186 - (int32_t)v0185 + TAG_FIXNUM);
    v0185 = ((intptr_t)(v0185) < 0 ? lisp_true : nil);
    if (v0185 == nil) goto v0045;
    v0186 = stack[-2];
    v0185 = qvalue(elt(env, 4)); /* current!-modulus */
    v0185 = (Lisp_Object)(int32_t)((int32_t)v0186 + (int32_t)v0185 - TAG_FIXNUM);
    stack[-2] = v0185;
    goto v0197;

v0197:
    v0188 = stack[-4];
    v0187 = stack[-2];
    v0186 = qvalue(elt(env, 3)); /* poly!-vector */
    v0185 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v0185 = (*qfnn(fn))(qenv(fn), 4, v0188, v0187, v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-8];
    stack[-2] = v0185;
    v0185 = (Lisp_Object)1; /* 0 */
    v0191 = v0185;
    goto v0198;

v0198:
    v0186 = stack[-2];
    v0185 = v0191;
    v0185 = (Lisp_Object)(int32_t)((int32_t)v0186 - (int32_t)v0185 + TAG_FIXNUM);
    v0185 = ((intptr_t)(v0185) < 0 ? lisp_true : nil);
    if (v0185 == nil) goto v0199;
    v0186 = stack[-7];
    v0185 = stack[0];
    v0188 = *(Lisp_Object *)((char *)v0186 + (CELL-TAG_VECTOR) + ((int32_t)v0185/(16/CELL)));
    v0187 = stack[0];
    v0186 = stack[-7];
    v0185 = stack[0];
    v0186 = *(Lisp_Object *)((char *)v0186 + (CELL-TAG_VECTOR) + ((int32_t)v0185/(16/CELL)));
    v0185 = stack[0];
    v0186 = *(Lisp_Object *)((char *)v0186 + (CELL-TAG_VECTOR) + ((int32_t)v0185/(16/CELL)));
    v0185 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v0186) - int_of_fixnum(v0185);
        if (w < 0) w += current_modulus;
        v0185 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0188 + (CELL-TAG_VECTOR) + ((int32_t)v0187/(16/CELL))) = v0185;
    v0185 = stack[0];
    v0185 = (Lisp_Object)((int32_t)(v0185) + 0x10);
    stack[0] = v0185;
    goto v0014;

v0199:
    v0186 = stack[-7];
    v0185 = v0191;
    v0190 = *(Lisp_Object *)((char *)v0186 + (CELL-TAG_VECTOR) + ((int32_t)v0185/(16/CELL)));
    v0189 = stack[0];
    v0188 = stack[-1];
    v0187 = v0191;
    v0186 = stack[-4];
    v0185 = v0191;
    v0185 = *(Lisp_Object *)((char *)v0186 + (CELL-TAG_VECTOR) + ((int32_t)v0185/(16/CELL)));
    *(Lisp_Object *)((char *)v0188 + (CELL-TAG_VECTOR) + ((int32_t)v0187/(16/CELL))) = v0185;
    *(Lisp_Object *)((char *)v0190 + (CELL-TAG_VECTOR) + ((int32_t)v0189/(16/CELL))) = v0185;
    v0185 = v0191;
    v0185 = (Lisp_Object)((int32_t)(v0185) + 0x10);
    v0191 = v0185;
    goto v0198;

v0045:
    v0188 = stack[-4];
    v0186 = qvalue(elt(env, 4)); /* current!-modulus */
    v0185 = v0189;
    v0187 = (Lisp_Object)(int32_t)((int32_t)v0186 + (int32_t)v0185 - TAG_FIXNUM);
    v0186 = stack[-1];
    v0185 = v0189;
    v0185 = *(Lisp_Object *)((char *)v0186 + (CELL-TAG_VECTOR) + ((int32_t)v0185/(16/CELL)));
    *(Lisp_Object *)((char *)v0188 + (CELL-TAG_VECTOR) + ((int32_t)v0187/(16/CELL))) = v0185;
    v0185 = v0189;
    v0185 = (Lisp_Object)((int32_t)(v0185) + 0x10);
    v0189 = v0185;
    goto v0032;

v0196:
    v0187 = stack[-4];
    v0186 = v0188;
    v0185 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0187 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL))) = v0185;
    v0185 = v0188;
    v0185 = (Lisp_Object)((int32_t)(v0185) + 0x10);
    v0188 = v0185;
    goto v0195;

v0194:
    v0189 = stack[-1];
    v0188 = stack[-2];
    v0187 = stack[-6];
    v0186 = stack[-5];
    v0185 = stack[-4];
    fn = elt(env, 7); /* times!-in!-vector */
    v0185 = (*qfnn(fn))(qenv(fn), 5, v0189, v0188, v0187, v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-8];
    stack[-2] = v0185;
    goto v0197;

v0070:
    v0185 = stack[-3];
    v0185 = Lmkvect(nil, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-8];
    v0189 = v0185;
    v0185 = (Lisp_Object)1; /* 0 */
    v0188 = v0185;
    goto v0028;

v0028:
    v0186 = stack[-3];
    v0185 = v0188;
    v0185 = (Lisp_Object)(int32_t)((int32_t)v0186 - (int32_t)v0185 + TAG_FIXNUM);
    v0185 = ((intptr_t)(v0185) < 0 ? lisp_true : nil);
    if (v0185 == nil) goto v0119;
    v0186 = stack[-7];
    v0185 = stack[0];
    v0187 = v0189;
    *(Lisp_Object *)((char *)v0186 + (CELL-TAG_VECTOR) + ((int32_t)v0185/(16/CELL))) = v0187;
    v0185 = stack[0];
    v0185 = (Lisp_Object)((int32_t)(v0185) + 0x10);
    stack[0] = v0185;
    goto v0078;

v0119:
    v0187 = v0189;
    v0186 = v0188;
    v0185 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0187 + (CELL-TAG_VECTOR) + ((int32_t)v0186/(16/CELL))) = v0185;
    v0185 = v0188;
    v0185 = (Lisp_Object)((int32_t)(v0185) + 0x10);
    v0188 = v0185;
    goto v0028;
/* error exit handlers */
v0192:
    popv(9);
    return nil;
}



/* Code for co_new */

static Lisp_Object MS_CDECL CC_co_new(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "co_new");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for co_new");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0060 = qvalue(elt(env, 1)); /* nil */
    return ncons(v0060);
}



/* Code for tayfkern */

static Lisp_Object CC_tayfkern(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069, v0066, v0125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayfkern");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0125 = v0000;
/* end of prologue */
    v0069 = qvalue(elt(env, 1)); /* !*tayinternal!* */
    if (!(v0069 == nil)) { popv(3); return onevalue(v0125); }
    v0069 = elt(env, 2); /* taylor!* */
    if (!symbolp(v0069)) v0069 = nil;
    else { v0069 = qfastgets(v0069);
           if (v0069 != nil) { v0069 = elt(v0069, 24); /* klist */
#ifdef RECORD_GET
             if (v0069 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v0069 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v0069 == SPID_NOPROP) v0069 = nil; }}
#endif
    stack[0] = v0069;
    v0066 = v0125;
    v0069 = stack[0];
    v0069 = Lassoc(nil, v0066, v0069);
    stack[-1] = v0069;
    v0069 = stack[-1];
    if (!(v0069 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0066 = v0125;
    v0069 = qvalue(elt(env, 3)); /* nil */
    v0069 = list2(v0066, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-2];
    stack[-1] = v0069;
    v0066 = stack[-1];
    v0069 = stack[0];
    fn = elt(env, 7); /* ordad */
    v0069 = (*qfn2(fn))(qenv(fn), v0066, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-2];
    stack[0] = v0069;
    v0066 = elt(env, 4); /* (taylor!*) */
    v0069 = qvalue(elt(env, 5)); /* kprops!* */
    fn = elt(env, 8); /* union */
    v0069 = (*qfn2(fn))(qenv(fn), v0066, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-2];
    qvalue(elt(env, 5)) = v0069; /* kprops!* */
    v0125 = elt(env, 2); /* taylor!* */
    v0066 = elt(env, 6); /* klist */
    v0069 = stack[0];
    v0069 = Lputprop(nil, 3, v0125, v0066, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0201:
    popv(3);
    return nil;
}



/* Code for mk!+real!+inner!+product */

static Lisp_Object CC_mkLrealLinnerLproduct(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0089;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+real+inner+product");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0063;
    stack[-3] = v0000;
/* end of prologue */
    v0091 = stack[-3];
    fn = elt(env, 5); /* get!+vec!+dim */
    stack[0] = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    v0091 = stack[-2];
    fn = elt(env, 5); /* get!+vec!+dim */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    if (equal(stack[0], v0091)) goto v0073;
    v0091 = elt(env, 1); /* "wrong dimensions in innerproduct" */
    fn = elt(env, 6); /* rederr */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    goto v0073;

v0073:
    v0089 = qvalue(elt(env, 2)); /* nil */
    v0091 = (Lisp_Object)17; /* 1 */
    v0091 = cons(v0089, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    stack[0] = v0091;
    v0091 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0091;
    goto v0047;

v0047:
    v0091 = stack[-3];
    fn = elt(env, 5); /* get!+vec!+dim */
    v0089 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    v0091 = stack[-4];
    v0091 = difference2(v0089, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    v0091 = Lminusp(nil, v0091);
    env = stack[-5];
    if (v0091 == nil) goto v0122;
    v0091 = qvalue(elt(env, 3)); /* t */
    stack[-1] = qvalue(elt(env, 4)); /* !*sub2 */
    qvalue(elt(env, 4)) = v0091; /* !*sub2 */
    v0091 = stack[0];
    fn = elt(env, 7); /* subs2 */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-5];
    stack[0] = v0091;
    qvalue(elt(env, 4)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0122:
    stack[-1] = stack[0];
    v0089 = stack[-3];
    v0091 = stack[-4];
    fn = elt(env, 8); /* get!+vec!+entry */
    stack[0] = (*qfn2(fn))(qenv(fn), v0089, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    v0089 = stack[-2];
    v0091 = stack[-4];
    fn = elt(env, 8); /* get!+vec!+entry */
    v0091 = (*qfn2(fn))(qenv(fn), v0089, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    fn = elt(env, 9); /* multsq */
    v0091 = (*qfn2(fn))(qenv(fn), stack[0], v0091);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    fn = elt(env, 10); /* addsq */
    v0091 = (*qfn2(fn))(qenv(fn), stack[-1], v0091);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    stack[0] = v0091;
    v0091 = stack[-4];
    v0091 = add1(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    stack[-4] = v0091;
    goto v0047;
/* error exit handlers */
v0110:
    env = stack[-5];
    qvalue(elt(env, 4)) = stack[-1]; /* !*sub2 */
    popv(6);
    return nil;
v0203:
    popv(6);
    return nil;
}



/* Code for mri_ofsf2mriat */

static Lisp_Object CC_mri_ofsf2mriat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0115, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_ofsf2mriat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0051 = v0063;
    v0115 = v0000;
/* end of prologue */
    v0077 = v0115;
    v0077 = qcar(v0077);
    v0115 = qcdr(v0115);
    v0115 = qcar(v0115);
    {
        fn = elt(env, 1); /* mri_0mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0077, v0115, v0051);
    }
}



/* Code for rl_surep */

static Lisp_Object CC_rl_surep(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_surep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0115 = v0063;
    v0077 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_surep!* */
    v0115 = list2(v0077, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    {
        Lisp_Object v0037 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0037, v0115);
    }
/* error exit handlers */
v0070:
    popv(2);
    return nil;
}



/* Code for transposerd */

static Lisp_Object MS_CDECL CC_transposerd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "transposerd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transposerd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    fn = elt(env, 2); /* mathml */
    v0051 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-1];
    v0115 = elt(env, 1); /* tp */
    v0051 = list2(v0115, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-1];
    fn = elt(env, 3); /* aeval */
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-1];
    stack[0] = v0051;
    fn = elt(env, 4); /* lex */
    v0051 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0038:
    popv(2);
    return nil;
}



/* Code for inszzz */

static Lisp_Object CC_inszzz(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inszzz");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0063;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0049;

v0049:
    v0015 = stack[-1];
    if (v0015 == nil) goto v0076;
    v0015 = stack[-1];
    v0015 = qcar(v0015);
    v0084 = qcar(v0015);
    v0015 = stack[-2];
    v0015 = qcar(v0015);
    v0015 = (Lisp_Object)lessp2(v0084, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    v0015 = v0015 ? lisp_true : nil;
    env = stack[-4];
    goto v0082;

v0082:
    if (v0015 == nil) goto v0120;
    stack[0] = stack[-3];
    v0084 = stack[-2];
    v0015 = stack[-1];
    v0015 = cons(v0084, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    {
        Lisp_Object v0100 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0100, v0015);
    }

v0120:
    v0015 = stack[-1];
    v0015 = qcar(v0015);
    v0084 = qcar(v0015);
    v0015 = stack[-2];
    v0015 = qcar(v0015);
    if (equal(v0084, v0015)) goto v0116;
    v0015 = stack[-1];
    v0084 = qcar(v0015);
    v0015 = stack[-3];
    v0015 = cons(v0084, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    stack[-3] = v0015;
    v0015 = stack[-1];
    v0015 = qcdr(v0015);
    stack[-1] = v0015;
    goto v0049;

v0116:
    v0015 = stack[-1];
    v0015 = qcar(v0015);
    stack[0] = qcdr(v0015);
    v0015 = stack[-1];
    v0015 = qcar(v0015);
    v0015 = qcdr(v0015);
    v0084 = qcar(v0015);
    v0015 = stack[-2];
    v0015 = qcdr(v0015);
    v0015 = qcar(v0015);
    fn = elt(env, 3); /* dm!-plus */
    v0015 = (*qfn2(fn))(qenv(fn), v0084, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0015 = Lrplaca(nil, stack[0], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0015 = stack[-1];
    v0015 = qcar(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcar(v0015);
    fn = elt(env, 4); /* zeropp */
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    if (v0015 == nil) goto v0101;
    v0084 = stack[-3];
    v0015 = stack[-1];
    v0015 = qcdr(v0015);
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0084, v0015);
    }

v0101:
    v0084 = stack[-3];
    v0015 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0084, v0015);
    }

v0076:
    v0015 = qvalue(elt(env, 1)); /* t */
    goto v0082;
/* error exit handlers */
v0016:
    popv(5);
    return nil;
}



/* Code for vdpilcomb1 */

static Lisp_Object MS_CDECL CC_vdpilcomb1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0063,
                         Lisp_Object v0058, Lisp_Object v0060,
                         Lisp_Object v0034, Lisp_Object v0062, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0074, v0023, v0019, v0204, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "vdpilcomb1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpilcomb1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0062,v0034,v0060,v0058,v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0063,v0058,v0060,v0034,v0062);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0062;
    v0118 = v0034;
    stack[-2] = v0060;
    stack[-3] = v0058;
    v0074 = v0063;
    stack[-4] = v0000;
/* end of prologue */
    v0023 = stack[-4];
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0109 = qcar(v0023);
    v0204 = v0074;
    v0019 = stack[-3];
    v0074 = stack[-2];
    v0074 = qcdr(v0074);
    v0074 = qcdr(v0074);
    v0074 = qcdr(v0074);
    v0023 = qcar(v0074);
    v0074 = v0118;
    v0118 = stack[-1];
    fn = elt(env, 2); /* dipilcomb1 */
    v0118 = (*qfnn(fn))(qenv(fn), 6, v0109, v0204, v0019, v0023, v0074, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-6];
    fn = elt(env, 3); /* dip2vdp */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-6];
    stack[-5] = v0118;
    v0118 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0118 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    stack[0] = stack[-5];
    v0118 = stack[-4];
    fn = elt(env, 4); /* gsugar */
    stack[-4] = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-6];
    v0118 = stack[-3];
    fn = elt(env, 5); /* vevtdeg */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-6];
    stack[-3] = plus2(stack[-4], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-6];
    v0118 = stack[-2];
    fn = elt(env, 4); /* gsugar */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-6];
    v0118 = stack[-1];
    fn = elt(env, 5); /* vevtdeg */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-6];
    v0118 = plus2(stack[-2], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-6];
    fn = elt(env, 6); /* max */
    v0118 = (*qfn2(fn))(qenv(fn), stack[-3], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-6];
    fn = elt(env, 7); /* gsetsugar */
    v0118 = (*qfn2(fn))(qenv(fn), stack[0], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
/* error exit handlers */
v0131:
    popv(7);
    return nil;
}



/* Code for fl2bf */

static Lisp_Object CC_fl2bf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fl2bf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0102 = v0000;
/* end of prologue */
    fn = elt(env, 3); /* frexp */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    stack[-2] = v0102;
    v0102 = stack[-2];
    v0102 = qcdr(v0102);
    v0120 = stack[-2];
    v0120 = qcar(v0120);
    stack[-2] = v0120;
    stack[0] = v0102;
    v0120 = (Lisp_Object)33; /* 2 */
    v0102 = qvalue(elt(env, 1)); /* !!nbfpd */
    v0102 = Lexpt(nil, v0120, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    v0102 = times2(stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    v0102 = Ltruncate(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    stack[-1] = elt(env, 2); /* !:rd!: */
    stack[0] = v0102;
    v0120 = stack[-2];
    v0102 = qvalue(elt(env, 1)); /* !!nbfpd */
    v0102 = difference2(v0120, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    v0102 = list2star(stack[-1], stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v0102);
    }
/* error exit handlers */
v0122:
    popv(4);
    return nil;
}



/* Code for find_bubles1 */

static Lisp_Object CC_find_bubles1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0080, v0103, v0106, v0098, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0030 = v0063;
    v0080 = v0000;
/* end of prologue */
    v0081 = qvalue(elt(env, 1)); /* nil */
    v0103 = v0080;
    v0098 = qcar(v0103);
    v0106 = qvalue(elt(env, 1)); /* nil */
    v0103 = v0080;
    v0103 = qcdr(v0103);
    v0103 = qcar(v0103);
    v0080 = qcdr(v0080);
    v0080 = qcdr(v0080);
    v0080 = qcar(v0080);
    {
        fn = elt(env, 2); /* select_bubles */
        return (*qfnn(fn))(qenv(fn), 6, v0081, v0098, v0106, v0103, v0080, v0030);
    }
}



/* Code for simpquot */

static Lisp_Object CC_simpquot(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0208, v0209, v0210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpquot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0208 = stack[-1];
    fn = elt(env, 9); /* simpcar */
    stack[0] = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    v0208 = stack[-1];
    v0208 = qcdr(v0208);
    v0208 = qcar(v0208);
    fn = elt(env, 10); /* simp */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[0] = v0208;
    v0208 = stack[0];
    v0208 = qcar(v0208);
    if (v0208 == nil) goto v0082;
    v0209 = qvalue(elt(env, 4)); /* dmode!* */
    v0208 = elt(env, 5); /* (!:rd!: !:cr!:) */
    v0208 = Lmemq(nil, v0209, v0208);
    if (v0208 == nil) goto v0211;
    v0208 = stack[0];
    v0208 = qcar(v0208);
    if (!consp(v0208)) goto v0066;
    v0208 = stack[0];
    v0208 = qcar(v0208);
    v0208 = qcar(v0208);
    v0208 = (consp(v0208) ? nil : lisp_true);
    goto v0069;

v0069:
    if (v0208 == nil) goto v0212;
    v0208 = stack[0];
    v0208 = qcdr(v0208);
    if (!consp(v0208)) goto v0019;
    v0208 = stack[0];
    v0208 = qcdr(v0208);
    v0208 = qcar(v0208);
    v0208 = (consp(v0208) ? nil : lisp_true);
    goto v0023;

v0023:
    if (v0208 == nil) goto v0213;
    v0208 = stack[-2];
    v0208 = qcdr(v0208);
    if (!consp(v0208)) goto v0011;
    v0208 = stack[-2];
    v0208 = qcdr(v0208);
    v0208 = qcar(v0208);
    v0208 = (consp(v0208) ? nil : lisp_true);
    goto v0214;

v0214:
    if (v0208 == nil) goto v0095;
    v0208 = stack[0];
    v0208 = qcdr(v0208);
    fn = elt(env, 11); /* !:onep */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    if (v0208 == nil) goto v0215;
    v0208 = stack[-2];
    v0208 = qcdr(v0208);
    fn = elt(env, 11); /* !:onep */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    goto v0111;

v0111:
    if (v0208 == nil) goto v0211;
    v0208 = stack[-2];
    v0208 = qcar(v0208);
    if (v0208 == nil) goto v0216;
    v0208 = stack[-2];
    v0209 = qcar(v0208);
    v0208 = stack[0];
    v0208 = qcar(v0208);
    fn = elt(env, 12); /* divd */
    v0208 = (*qfn2(fn))(qenv(fn), v0209, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    v0209 = v0208;
    goto v0180;

v0180:
    v0208 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v0209, v0208);

v0216:
    v0208 = qvalue(elt(env, 7)); /* nil */
    v0209 = v0208;
    goto v0180;

v0211:
    stack[0] = stack[-2];
    v0208 = stack[-1];
    v0208 = qcdr(v0208);
    fn = elt(env, 13); /* simprecip */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    fn = elt(env, 14); /* multsq */
    v0208 = (*qfn2(fn))(qenv(fn), stack[0], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    stack[-1] = v0208;
    v0208 = qvalue(elt(env, 8)); /* !*modular */
    if (v0208 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0208 = stack[-1];
    v0208 = qcdr(v0208);
    if (!(v0208 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0210 = elt(env, 1); /* alg */
    v0209 = (Lisp_Object)3217; /* 201 */
    v0208 = elt(env, 3); /* "Zero divisor" */
    fn = elt(env, 15); /* rerror */
    v0208 = (*qfnn(fn))(qenv(fn), 3, v0210, v0209, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0215:
    v0208 = qvalue(elt(env, 7)); /* nil */
    goto v0111;

v0095:
    v0208 = qvalue(elt(env, 7)); /* nil */
    goto v0111;

v0011:
    v0208 = qvalue(elt(env, 6)); /* t */
    goto v0214;

v0213:
    v0208 = qvalue(elt(env, 7)); /* nil */
    goto v0111;

v0019:
    v0208 = qvalue(elt(env, 6)); /* t */
    goto v0023;

v0212:
    v0208 = qvalue(elt(env, 7)); /* nil */
    goto v0111;

v0066:
    v0208 = qvalue(elt(env, 6)); /* t */
    goto v0069;

v0082:
    v0208 = stack[-2];
    v0208 = qcar(v0208);
    if (v0208 == nil) goto v0073;
    v0210 = elt(env, 1); /* alg */
    v0209 = (Lisp_Object)321; /* 20 */
    v0208 = elt(env, 3); /* "Zero divisor" */
    {
        popv(4);
        fn = elt(env, 15); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0210, v0209, v0208);
    }

v0073:
    v0210 = elt(env, 1); /* alg */
    v0209 = (Lisp_Object)305; /* 19 */
    v0208 = elt(env, 2); /* "0/0 formed" */
    {
        popv(4);
        fn = elt(env, 15); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0210, v0209, v0208);
    }
/* error exit handlers */
v0032:
    popv(4);
    return nil;
}



/* Code for cl_atnum */

static Lisp_Object CC_cl_atnum(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0160, v0157, v0158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atnum");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0231:
    v0160 = stack[0];
    if (!consp(v0160)) goto v0056;
    v0160 = stack[0];
    v0160 = qcar(v0160);
    goto v0035;

v0035:
    v0158 = v0160;
    v0157 = v0158;
    v0160 = elt(env, 1); /* or */
    if (v0157 == v0160) goto v0080;
    v0157 = v0158;
    v0160 = elt(env, 3); /* and */
    v0160 = (v0157 == v0160 ? lisp_true : nil);
    goto v0030;

v0030:
    if (v0160 == nil) goto v0064;
    v0160 = qvalue(elt(env, 2)); /* t */
    goto v0079;

v0079:
    if (v0160 == nil) goto v0201;
    v0160 = qvalue(elt(env, 2)); /* t */
    goto v0070;

v0070:
    if (v0160 == nil) goto v0232;
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    stack[-1] = v0160;
    v0160 = (Lisp_Object)1; /* 0 */
    stack[0] = v0160;
    goto v0108;

v0108:
    v0160 = stack[-1];
    if (v0160 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0160 = stack[-1];
    v0160 = qcar(v0160);
    v0157 = CC_cl_atnum(env, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-2];
    v0160 = stack[0];
    v0160 = plus2(v0157, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-2];
    stack[0] = v0160;
    v0160 = stack[-1];
    v0160 = qcdr(v0160);
    stack[-1] = v0160;
    goto v0108;

v0232:
    v0157 = v0158;
    v0160 = elt(env, 8); /* ex */
    if (v0157 == v0160) goto v0180;
    v0157 = v0158;
    v0160 = elt(env, 9); /* all */
    v0160 = (v0157 == v0160 ? lisp_true : nil);
    goto v0234;

v0234:
    if (v0160 == nil) goto v0235;
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    v0160 = qcdr(v0160);
    v0160 = qcar(v0160);
    stack[0] = v0160;
    goto v0231;

v0235:
    v0157 = v0158;
    v0160 = elt(env, 10); /* bex */
    if (v0157 == v0160) goto v0206;
    v0157 = v0158;
    v0160 = elt(env, 11); /* ball */
    v0160 = (v0157 == v0160 ? lisp_true : nil);
    goto v0195;

v0195:
    if (v0160 == nil) goto v0236;
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    v0160 = qcdr(v0160);
    v0160 = qcar(v0160);
    stack[-1] = CC_cl_atnum(env, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-2];
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    v0160 = qcdr(v0160);
    v0160 = qcdr(v0160);
    v0160 = qcar(v0160);
    v0160 = CC_cl_atnum(env, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    {
        Lisp_Object v0237 = stack[-1];
        popv(3);
        return plus2(v0237, v0160);
    }

v0236:
    v0157 = v0158;
    v0160 = elt(env, 12); /* true */
    if (v0157 == v0160) goto v0238;
    v0157 = v0158;
    v0160 = elt(env, 13); /* false */
    v0160 = (v0157 == v0160 ? lisp_true : nil);
    goto v0046;

v0046:
    if (v0160 == nil) goto v0239;
    v0160 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0160); }

v0239:
    v0157 = v0158;
    v0160 = elt(env, 0); /* cl_atnum */
    fn = elt(env, 14); /* rl_external */
    v0160 = (*qfn2(fn))(qenv(fn), v0157, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-2];
    v0157 = v0160;
    if (v0160 == nil) goto v0240;
    stack[-1] = v0157;
    v0160 = stack[0];
    v0160 = ncons(v0160);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-2];
    {
        Lisp_Object v0241 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* apply */
        return (*qfn2(fn))(qenv(fn), v0241, v0160);
    }

v0240:
    v0160 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0160); }

v0238:
    v0160 = qvalue(elt(env, 2)); /* t */
    goto v0046;

v0206:
    v0160 = qvalue(elt(env, 2)); /* t */
    goto v0195;

v0180:
    v0160 = qvalue(elt(env, 2)); /* t */
    goto v0234;

v0201:
    v0157 = v0158;
    v0160 = elt(env, 5); /* impl */
    if (v0157 == v0160) goto v0126;
    v0157 = v0158;
    v0160 = elt(env, 6); /* repl */
    if (v0157 == v0160) goto v0023;
    v0157 = v0158;
    v0160 = elt(env, 7); /* equiv */
    v0160 = (v0157 == v0160 ? lisp_true : nil);
    goto v0070;

v0023:
    v0160 = qvalue(elt(env, 2)); /* t */
    goto v0070;

v0126:
    v0160 = qvalue(elt(env, 2)); /* t */
    goto v0070;

v0064:
    v0157 = v0158;
    v0160 = elt(env, 4); /* not */
    v0160 = (v0157 == v0160 ? lisp_true : nil);
    goto v0079;

v0080:
    v0160 = qvalue(elt(env, 2)); /* t */
    goto v0030;

v0056:
    v0160 = stack[0];
    goto v0035;
/* error exit handlers */
v0233:
    popv(3);
    return nil;
}



/* Code for evalgreaterp */

static Lisp_Object CC_evalgreaterp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0118, v0074;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalgreaterp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0118 = v0063;
    v0022 = v0000;
/* end of prologue */
    v0074 = elt(env, 1); /* difference */
    v0022 = list3(v0074, v0118, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    fn = elt(env, 5); /* simp!* */
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    stack[0] = v0022;
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    if (!consp(v0022)) goto v0050;
    v0022 = qvalue(elt(env, 2)); /* t */
    goto v0070;

v0070:
    if (v0022 == nil) goto v0069;
    v0022 = stack[0];
    v0022 = qcar(v0022);
    fn = elt(env, 6); /* minusf */
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    if (v0022 == nil) goto v0111;
    v0022 = stack[0];
    fn = elt(env, 7); /* negsq */
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    goto v0122;

v0122:
    fn = elt(env, 8); /* mk!*sq */
    v0118 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    v0022 = elt(env, 3); /* "number" */
    {
        popv(2);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0118, v0022);
    }

v0111:
    v0022 = stack[0];
    goto v0122;

v0069:
    v0022 = stack[0];
    v0022 = qcar(v0022);
    if (v0022 == nil) goto v0130;
    v0022 = stack[0];
    v0022 = qcar(v0022);
    {
        popv(2);
        fn = elt(env, 10); /* !:minusp */
        return (*qfn1(fn))(qenv(fn), v0022);
    }

v0130:
    v0022 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v0022); }

v0050:
    v0022 = stack[0];
    v0022 = qcar(v0022);
    if (!consp(v0022)) goto v0103;
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0022 = qcar(v0022);
    v0022 = (consp(v0022) ? nil : lisp_true);
    goto v0080;

v0080:
    v0022 = (v0022 == nil ? lisp_true : nil);
    goto v0070;

v0103:
    v0022 = qvalue(elt(env, 2)); /* t */
    goto v0080;
/* error exit handlers */
v0019:
    popv(2);
    return nil;
}



/* Code for simpexpt1 */

static Lisp_Object MS_CDECL CC_simpexpt1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0063,
                         Lisp_Object v0058, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0301, v0302, v0303;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0063,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0058;
    stack[-5] = v0063;
    stack[-6] = v0000;
/* end of prologue */
    stack[-7] = qvalue(elt(env, 1)); /* !*allfac */
    qvalue(elt(env, 1)) = nil; /* !*allfac */
    stack[-3] = qvalue(elt(env, 2)); /* !*div */
    qvalue(elt(env, 2)) = nil; /* !*div */
    v0301 = stack[-6];
    v0301 = Lonep(nil, v0301);
    env = stack[-8];
    if (v0301 == nil) goto v0082;
    v0302 = (Lisp_Object)17; /* 1 */
    v0301 = (Lisp_Object)17; /* 1 */
    v0301 = cons(v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0124:
    qvalue(elt(env, 2)) = stack[-3]; /* !*div */
    qvalue(elt(env, 1)) = stack[-7]; /* !*allfac */
    { popv(9); return onevalue(v0301); }

v0082:
    v0301 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v0301; /* !*allfac */
    v0301 = stack[-5];
    v0301 = qcar(v0301);
    stack[-2] = v0301;
    v0302 = stack[-2];
    v0301 = (Lisp_Object)17; /* 1 */
    if (v0302 == v0301) goto v0054;
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0098;

v0098:
    if (v0301 == nil) goto v0125;
    v0301 = stack[-6];
    fn = elt(env, 12); /* simp */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0125:
    v0302 = stack[-6];
    v0301 = elt(env, 5); /* e */
    if (v0302 == v0301) goto v0069;
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0025;

v0025:
    if (v0301 == nil) goto v0116;
    v0301 = stack[-2];
    v0301 = qcar(v0301);
    v0301 = qcar(v0301);
    v0301 = qcar(v0301);
    v0301 = qcdr(v0301);
    v0301 = qcar(v0301);
    fn = elt(env, 13); /* simp!* */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    fn = elt(env, 14); /* prepsq!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    v0301 = stack[-2];
    v0301 = qcar(v0301);
    v0302 = qcdr(v0301);
    v0301 = stack[-5];
    v0301 = qcdr(v0301);
    v0302 = cons(v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    v0301 = qvalue(elt(env, 4)); /* nil */
    v0301 = CC_simpexpt1(env, 3, stack[0], v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0116:
    v0301 = stack[-2];
    if (!consp(v0301)) goto v0006;
    v0301 = stack[-2];
    v0301 = qcar(v0301);
    v0301 = (consp(v0301) ? nil : lisp_true);
    goto v0005;

v0005:
    if (v0301 == nil) goto v0172;
    v0301 = stack[-5];
    v0301 = qcdr(v0301);
    if (!consp(v0301)) goto v0171;
    v0301 = stack[-5];
    v0301 = qcdr(v0301);
    v0301 = qcar(v0301);
    v0301 = (consp(v0301) ? nil : lisp_true);
    goto v0170;

v0170:
    v0301 = (v0301 == nil ? lisp_true : nil);
    goto v0174;

v0174:
    if (v0301 == nil) goto v0305;
    v0303 = stack[-6];
    v0302 = stack[-5];
    v0301 = stack[-4];
    fn = elt(env, 15); /* simpexpt11 */
    v0301 = (*qfnn(fn))(qenv(fn), 3, v0303, v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0305:
    v0301 = stack[-6];
    fn = elt(env, 12); /* simp */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    stack[-1] = v0301;
    v0301 = stack[-2];
    if (v0301 == nil) goto v0163;
    v0301 = stack[-1];
    v0301 = qcar(v0301);
    if (v0301 == nil) goto v0306;
    v0301 = stack[-2];
    if (!consp(v0301)) goto v0144;
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0307;

v0307:
    if (v0301 == nil) goto v0308;
    v0301 = stack[-1];
    v0301 = qcar(v0301);
    if (!consp(v0301)) goto v0309;
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0310;

v0310:
    if (v0301 == nil) goto v0311;
    v0301 = stack[-1];
    v0302 = qcar(v0301);
    v0301 = stack[-2];
    v0301 = Lexpt(nil, v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    fn = elt(env, 16); /* !*d2q */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0311:
    v0301 = stack[-1];
    v0302 = qcar(v0301);
    v0301 = stack[-2];
    fn = elt(env, 17); /* !:expt */
    v0302 = (*qfn2(fn))(qenv(fn), v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    v0301 = (Lisp_Object)17; /* 1 */
    v0301 = cons(v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    stack[-1] = v0301;
    v0301 = qvalue(elt(env, 10)); /* !*mcd */
    if (v0301 == nil) goto v0312;
    v0301 = stack[-1];
    fn = elt(env, 18); /* resimp */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0312:
    v0301 = stack[-1];
    goto v0124;

v0309:
    v0302 = stack[-2];
    v0301 = (Lisp_Object)1; /* 0 */
    v0301 = (Lisp_Object)greaterp2(v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    v0301 = v0301 ? lisp_true : nil;
    env = stack[-8];
    goto v0310;

v0308:
    stack[0] = elt(env, 11); /* expt */
    v0302 = stack[-1];
    v0301 = stack[-5];
    v0301 = list2(v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    fn = elt(env, 19); /* domainvalchk */
    v0301 = (*qfn2(fn))(qenv(fn), stack[0], v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    v0302 = v0301;
    if (v0301 == nil) goto v0313;
    v0301 = v0302;
    goto v0124;

v0313:
    v0301 = stack[-2];
    if (!consp(v0301)) goto v0314;
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0315;

v0315:
    if (v0301 == nil) goto v0316;
    v0302 = stack[-2];
    v0301 = (Lisp_Object)1; /* 0 */
    v0301 = (Lisp_Object)lessp2(v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    v0301 = v0301 ? lisp_true : nil;
    env = stack[-8];
    if (v0301 == nil) goto v0317;
    v0301 = qvalue(elt(env, 10)); /* !*mcd */
    if (v0301 == nil) goto v0318;
    stack[0] = stack[-1];
    v0301 = stack[-2];
    v0301 = negate(v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    fn = elt(env, 20); /* exptsq */
    v0301 = (*qfn2(fn))(qenv(fn), stack[0], v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    fn = elt(env, 21); /* invsq */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0318:
    v0301 = stack[-1];
    v0302 = qcar(v0301);
    v0301 = stack[-2];
    fn = elt(env, 22); /* expf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    v0301 = stack[-1];
    stack[-1] = qcdr(v0301);
    v0301 = stack[-2];
    v0301 = negate(v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    fn = elt(env, 23); /* mksfpf */
    v0301 = (*qfn2(fn))(qenv(fn), stack[-1], v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    fn = elt(env, 24); /* multf */
    v0302 = (*qfn2(fn))(qenv(fn), stack[0], v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    v0301 = (Lisp_Object)17; /* 1 */
    v0301 = cons(v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0317:
    v0302 = stack[-1];
    v0301 = stack[-2];
    fn = elt(env, 20); /* exptsq */
    v0301 = (*qfn2(fn))(qenv(fn), v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0316:
    v0301 = stack[-4];
    if (v0301 == nil) goto v0319;
    v0301 = stack[-6];
    v0303 = v0301;
    goto v0320;

v0320:
    v0302 = stack[-5];
    v0301 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 15); /* simpexpt11 */
    v0301 = (*qfnn(fn))(qenv(fn), 3, v0303, v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0319:
    v0301 = stack[-1];
    fn = elt(env, 25); /* subs2!* */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    fn = elt(env, 14); /* prepsq!* */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    v0303 = v0301;
    goto v0320;

v0314:
    v0301 = stack[-5];
    v0302 = qcdr(v0301);
    v0301 = (Lisp_Object)17; /* 1 */
    v0301 = (v0302 == v0301 ? lisp_true : nil);
    goto v0315;

v0144:
    v0301 = stack[-5];
    v0302 = qcdr(v0301);
    v0301 = (Lisp_Object)17; /* 1 */
    if (v0302 == v0301) goto v0321;
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0307;

v0321:
    v0301 = stack[-1];
    v0301 = qcar(v0301);
    if (!consp(v0301)) goto v0322;
    v0301 = stack[-1];
    v0301 = qcar(v0301);
    v0301 = qcar(v0301);
    v0301 = (consp(v0301) ? nil : lisp_true);
    goto v0323;

v0323:
    if (v0301 == nil) goto v0133;
    v0301 = stack[-1];
    v0302 = qcdr(v0301);
    v0301 = (Lisp_Object)17; /* 1 */
    v0301 = (v0302 == v0301 ? lisp_true : nil);
    goto v0307;

v0133:
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0307;

v0322:
    v0301 = qvalue(elt(env, 3)); /* t */
    goto v0323;

v0306:
    v0301 = stack[-2];
    if (!consp(v0301)) goto v0324;
    v0301 = stack[-2];
    v0301 = qcar(v0301);
    v0301 = (consp(v0301) ? nil : lisp_true);
    goto v0325;

v0325:
    if (v0301 == nil) goto v0154;
    v0301 = stack[-2];
    fn = elt(env, 26); /* minusf */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0326;

v0326:
    if (v0301 == nil) goto v0150;
    v0303 = elt(env, 7); /* alg */
    v0302 = (Lisp_Object)241; /* 15 */
    v0301 = elt(env, 9); /* "Zero divisor" */
    fn = elt(env, 27); /* rerror */
    v0301 = (*qfnn(fn))(qenv(fn), 3, v0303, v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0150:
    v0302 = qvalue(elt(env, 4)); /* nil */
    v0301 = (Lisp_Object)17; /* 1 */
    v0301 = cons(v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0154:
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0326;

v0324:
    v0301 = qvalue(elt(env, 3)); /* t */
    goto v0325;

v0163:
    v0301 = stack[-1];
    v0301 = qcar(v0301);
    if (v0301 == nil) goto v0219;
    v0302 = (Lisp_Object)17; /* 1 */
    v0301 = (Lisp_Object)17; /* 1 */
    v0301 = cons(v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0219:
    v0303 = elt(env, 7); /* alg */
    v0302 = (Lisp_Object)225; /* 14 */
    v0301 = elt(env, 8); /* "0**0 formed" */
    fn = elt(env, 27); /* rerror */
    v0301 = (*qfnn(fn))(qenv(fn), 3, v0303, v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-8];
    goto v0124;

v0171:
    v0301 = qvalue(elt(env, 3)); /* t */
    goto v0170;

v0172:
    v0301 = qvalue(elt(env, 3)); /* t */
    goto v0174;

v0006:
    v0301 = qvalue(elt(env, 3)); /* t */
    goto v0005;

v0069:
    v0301 = stack[-5];
    v0301 = qcdr(v0301);
    if (!consp(v0301)) goto v0118;
    v0301 = stack[-5];
    v0301 = qcdr(v0301);
    v0301 = qcar(v0301);
    v0301 = (consp(v0301) ? nil : lisp_true);
    goto v0022;

v0022:
    if (v0301 == nil) goto v0327;
    v0301 = stack[-2];
    if (!consp(v0301)) goto v0087;
    v0301 = stack[-2];
    v0301 = qcar(v0301);
    v0301 = (consp(v0301) ? nil : lisp_true);
    goto v0110;

v0110:
    if (v0301 == nil) goto v0328;
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0025;

v0328:
    v0301 = stack[-2];
    v0301 = qcar(v0301);
    v0301 = qcar(v0301);
    v0302 = qcdr(v0301);
    v0301 = (Lisp_Object)17; /* 1 */
    if (v0302 == v0301) goto v0086;
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0025;

v0086:
    v0301 = stack[-2];
    v0301 = qcdr(v0301);
    if (v0301 == nil) goto v0213;
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0025;

v0213:
    v0301 = stack[-2];
    v0301 = qcar(v0301);
    v0301 = qcar(v0301);
    v0302 = qcar(v0301);
    v0301 = elt(env, 6); /* log */
    v0301 = Leqcar(nil, v0302, v0301);
    env = stack[-8];
    goto v0025;

v0087:
    v0301 = qvalue(elt(env, 3)); /* t */
    goto v0110;

v0327:
    v0301 = qvalue(elt(env, 4)); /* nil */
    goto v0025;

v0118:
    v0301 = qvalue(elt(env, 3)); /* t */
    goto v0022;

v0054:
    v0301 = stack[-5];
    v0302 = qcdr(v0301);
    v0301 = (Lisp_Object)17; /* 1 */
    v0301 = (v0302 == v0301 ? lisp_true : nil);
    goto v0098;
/* error exit handlers */
v0304:
    env = stack[-8];
    qvalue(elt(env, 2)) = stack[-3]; /* !*div */
    qvalue(elt(env, 1)) = stack[-7]; /* !*allfac */
    popv(9);
    return nil;
}



/* Code for gen!+can!+bas */

static Lisp_Object CC_genLcanLbas(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0240, v0336;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gen+can+bas");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0000;
/* end of prologue */
    v0336 = (Lisp_Object)17; /* 1 */
    v0240 = (Lisp_Object)17; /* 1 */
    v0240 = cons(v0336, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    stack[-10] = v0240;
    v0336 = qvalue(elt(env, 1)); /* nil */
    v0240 = (Lisp_Object)17; /* 1 */
    v0240 = cons(v0336, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    stack[-8] = v0240;
    v0240 = (Lisp_Object)17; /* 1 */
    stack[-7] = v0240;
    v0336 = stack[-9];
    v0240 = stack[-7];
    v0240 = difference2(v0336, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = Lminusp(nil, v0240);
    env = stack[-11];
    if (v0240 == nil) goto v0098;
    v0240 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v0240); }

v0098:
    v0240 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0240;
    v0336 = stack[-9];
    v0240 = stack[-3];
    v0240 = difference2(v0336, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = Lminusp(nil, v0240);
    env = stack[-11];
    if (v0240 == nil) goto v0071;
    v0240 = qvalue(elt(env, 1)); /* nil */
    goto v0122;

v0122:
    v0240 = ncons(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    stack[-5] = v0240;
    stack[-6] = v0240;
    goto v0080;

v0080:
    v0240 = stack[-7];
    v0240 = add1(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    stack[-7] = v0240;
    v0336 = stack[-9];
    v0240 = stack[-7];
    v0240 = difference2(v0336, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = Lminusp(nil, v0240);
    env = stack[-11];
    if (!(v0240 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    v0240 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0240;
    v0336 = stack[-9];
    v0240 = stack[-3];
    v0240 = difference2(v0336, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = Lminusp(nil, v0240);
    env = stack[-11];
    if (v0240 == nil) goto v0196;
    v0240 = qvalue(elt(env, 1)); /* nil */
    goto v0007;

v0007:
    v0240 = ncons(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = Lrplacd(nil, stack[-4], v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = stack[-5];
    v0240 = qcdr(v0240);
    stack[-5] = v0240;
    goto v0080;

v0196:
    v0336 = stack[-7];
    v0240 = stack[-3];
    if (equal(v0336, v0240)) goto v0226;
    v0240 = stack[-8];
    goto v0225;

v0225:
    v0240 = ncons(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    stack[-1] = v0240;
    stack[-2] = v0240;
    goto v0009;

v0009:
    v0240 = stack[-3];
    v0240 = add1(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    stack[-3] = v0240;
    v0336 = stack[-9];
    v0240 = stack[-3];
    v0240 = difference2(v0336, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = Lminusp(nil, v0240);
    env = stack[-11];
    if (v0240 == nil) goto v0338;
    v0240 = stack[-2];
    goto v0007;

v0338:
    stack[0] = stack[-1];
    v0336 = stack[-7];
    v0240 = stack[-3];
    if (equal(v0336, v0240)) goto v0339;
    v0240 = stack[-8];
    goto v0340;

v0340:
    v0240 = ncons(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = Lrplacd(nil, stack[0], v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    stack[-1] = v0240;
    goto v0009;

v0339:
    v0240 = stack[-10];
    goto v0340;

v0226:
    v0240 = stack[-10];
    goto v0225;

v0071:
    v0336 = stack[-7];
    v0240 = stack[-3];
    if (equal(v0336, v0240)) goto v0067;
    v0240 = stack[-8];
    goto v0018;

v0018:
    v0240 = ncons(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    stack[-1] = v0240;
    stack[-2] = v0240;
    goto v0341;

v0341:
    v0240 = stack[-3];
    v0240 = add1(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    stack[-3] = v0240;
    v0336 = stack[-9];
    v0240 = stack[-3];
    v0240 = difference2(v0336, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = Lminusp(nil, v0240);
    env = stack[-11];
    if (v0240 == nil) goto v0230;
    v0240 = stack[-2];
    goto v0122;

v0230:
    stack[0] = stack[-1];
    v0336 = stack[-7];
    v0240 = stack[-3];
    if (equal(v0336, v0240)) goto v0342;
    v0240 = stack[-8];
    goto v0013;

v0013:
    v0240 = ncons(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = Lrplacd(nil, stack[0], v0240);
    nil = C_nil;
    if (exception_pending()) goto v0337;
    env = stack[-11];
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    stack[-1] = v0240;
    goto v0341;

v0342:
    v0240 = stack[-10];
    goto v0013;

v0067:
    v0240 = stack[-10];
    goto v0018;
/* error exit handlers */
v0337:
    popv(12);
    return nil;
}



/* Code for rl_bnfsimpl */

static Lisp_Object CC_rl_bnfsimpl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_bnfsimpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0115 = v0063;
    v0077 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bnfsimpl!* */
    v0115 = list2(v0077, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    {
        Lisp_Object v0037 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0037, v0115);
    }
/* error exit handlers */
v0070:
    popv(2);
    return nil;
}



/* Code for diffrd */

static Lisp_Object MS_CDECL CC_diffrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0028, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "diffrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffrd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    fn = elt(env, 4); /* lex */
    v0055 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    v0028 = qvalue(elt(env, 1)); /* char */
    v0055 = elt(env, 2); /* (b v a r) */
    if (equal(v0028, v0055)) goto v0124;
    v0055 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v0055;
    v0055 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = v0055;
    goto v0083;

v0083:
    fn = elt(env, 5); /* mathml2 */
    v0055 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    stack[0] = v0055;
    fn = elt(env, 4); /* lex */
    v0055 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    v0102 = stack[0];
    v0028 = stack[-2];
    v0055 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* alg_df */
        return (*qfnn(fn))(qenv(fn), 3, v0102, v0028, v0055);
    }

v0124:
    fn = elt(env, 7); /* bvarrd */
    v0055 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    stack[-2] = v0055;
    v0055 = stack[-2];
    v0055 = qcdr(v0055);
    v0055 = qcar(v0055);
    stack[-1] = v0055;
    v0055 = stack[-2];
    v0055 = qcar(v0055);
    stack[-2] = v0055;
    fn = elt(env, 4); /* lex */
    v0055 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    goto v0083;
/* error exit handlers */
v0184:
    popv(4);
    return nil;
}



/* Code for scar */

static Lisp_Object CC_scar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0055;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0063;
    stack[-1] = v0000;
/* end of prologue */

v0231:
    v0054 = stack[0];
    if (!consp(v0054)) goto v0062;
    v0055 = stack[-1];
    v0054 = stack[0];
    v0054 = qcar(v0054);
    if (equal(v0055, v0054)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0055 = stack[-1];
    v0054 = stack[0];
    v0054 = qcar(v0054);
    v0054 = CC_scar(env, v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    if (!(v0054 == nil)) { popv(3); return onevalue(v0054); }
    v0055 = stack[-1];
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[-1] = v0055;
    stack[0] = v0054;
    goto v0231;

v0062:
    v0054 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0054); }
/* error exit handlers */
v0120:
    popv(3);
    return nil;
}



/* Code for size_of_matrix */

static Lisp_Object CC_size_of_matrix(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0080;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for size_of_matrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v0030 = stack[0];
    v0030 = Llength(nil, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    v0030 = plus2(stack[-1], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    stack[-1] = v0030;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    v0030 = qcar(v0030);
    v0030 = Llength(nil, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    v0080 = stack[-1];
    popv(3);
    return list2(v0080, v0030);
/* error exit handlers */
v0098:
    popv(3);
    return nil;
}



/* Code for simpunion */

static Lisp_Object CC_simpunion(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0183, v0117, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpunion");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0183 = v0000;
/* end of prologue */
    v0117 = elt(env, 1); /* union */
    fn = elt(env, 3); /* applysetop */
    v0183 = (*qfn2(fn))(qenv(fn), v0117, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0022 = v0183;
    v0183 = v0022;
    v0117 = qcar(v0183);
    v0183 = elt(env, 1); /* union */
    if (v0117 == v0183) goto v0120;
    v0183 = v0022;
    v0117 = v0183;
    goto v0050;

v0050:
    v0183 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* mksp */
    v0117 = (*qfn2(fn))(qenv(fn), v0117, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0183 = (Lisp_Object)17; /* 1 */
    v0183 = cons(v0117, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0117 = ncons(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    v0183 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0117, v0183);

v0120:
    v0183 = qvalue(elt(env, 2)); /* empty_set */
    v0117 = v0022;
    v0117 = qcdr(v0117);
    v0183 = Ldelete(nil, v0183, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0022 = v0183;
    v0183 = qcdr(v0183);
    if (v0183 == nil) goto v0125;
    stack[0] = elt(env, 1); /* union */
    v0183 = v0022;
    fn = elt(env, 5); /* ordn */
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0183 = cons(stack[0], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    goto v0054;

v0054:
    v0117 = v0183;
    goto v0050;

v0125:
    v0183 = v0022;
    v0183 = qcar(v0183);
    goto v0054;
/* error exit handlers */
v0074:
    popv(2);
    return nil;
}



/* Code for list!-evaluate */

static Lisp_Object MS_CDECL CC_listKevaluate(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0063,
                         Lisp_Object v0058, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0125, v0126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "list-evaluate");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list-evaluate");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0063,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0058;
    stack[-4] = v0063;
    v0066 = v0000;
/* end of prologue */
    stack[-5] = v0066;
    v0066 = stack[-5];
    if (v0066 == nil) goto v0076;
    v0066 = stack[-5];
    v0066 = qcar(v0066);
    v0126 = v0066;
    v0125 = stack[-4];
    v0066 = stack[-3];
    fn = elt(env, 2); /* evaluate */
    v0066 = (*qfnn(fn))(qenv(fn), 3, v0126, v0125, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    stack[-1] = v0066;
    stack[-2] = v0066;
    goto v0083;

v0083:
    v0066 = stack[-5];
    v0066 = qcdr(v0066);
    stack[-5] = v0066;
    v0066 = stack[-5];
    if (v0066 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0066 = stack[-5];
    v0066 = qcar(v0066);
    v0126 = v0066;
    v0125 = stack[-4];
    v0066 = stack[-3];
    fn = elt(env, 2); /* evaluate */
    v0066 = (*qfnn(fn))(qenv(fn), 3, v0126, v0125, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    v0066 = Lrplacd(nil, stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    v0066 = stack[-1];
    v0066 = qcdr(v0066);
    stack[-1] = v0066;
    goto v0083;

v0076:
    v0066 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0066); }
/* error exit handlers */
v0071:
    popv(7);
    return nil;
}



/* Code for applsmacro */

static Lisp_Object MS_CDECL CC_applsmacro(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0063,
                         Lisp_Object v0058, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0270, v0311, v0354;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "applsmacro");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applsmacro");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0063,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0058;
    stack[-7] = v0063;
    v0311 = v0000;
/* end of prologue */
    stack[-6] = nil;
    stack[-5] = qvalue(elt(env, 1)); /* inlineinfo */
    qvalue(elt(env, 1)) = nil; /* inlineinfo */
    v0270 = v0311;
    v0270 = qcdr(v0270);
    v0270 = qcar(v0270);
    stack[-3] = v0270;
    v0270 = v0311;
    v0270 = qcdr(v0270);
    v0270 = qcdr(v0270);
    v0270 = qcar(v0270);
    stack[-8] = v0270;
    v0354 = stack[-2];
    v0311 = stack[-3];
    v0270 = stack[-8];
    v0270 = list3(v0354, v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0270; /* inlineinfo */
    v0270 = stack[-3];
    stack[0] = Llength(nil, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = stack[-7];
    v0270 = Llength(nil, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    if (equal(stack[0], v0270)) goto v0080;
    stack[-1] = elt(env, 2); /* rlisp */
    stack[0] = (Lisp_Object)241; /* 15 */
    v0311 = elt(env, 3); /* "Argument mismatch for SMACRO" */
    v0270 = stack[-2];
    v0270 = list2(v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    fn = elt(env, 8); /* rerror */
    v0270 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    goto v0080;

v0080:
    v0270 = qvalue(elt(env, 4)); /* !*loginlines */
    if (v0270 == nil) goto v0024;
    v0354 = stack[-3];
    v0311 = stack[-8];
    v0270 = stack[-7];
    fn = elt(env, 9); /* log_inlines */
    v0270 = (*qfnn(fn))(qenv(fn), 3, v0354, v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    goto v0024;

v0024:
    v0270 = stack[-7];
    fn = elt(env, 10); /* no!-side!-effect!-listp */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    if (!(v0270 == nil)) goto v0010;
    v0311 = stack[-3];
    v0270 = stack[-8];
    fn = elt(env, 11); /* one!-entry!-listp */
    v0270 = (*qfn2(fn))(qenv(fn), v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    if (!(v0270 == nil)) goto v0010;
    v0270 = stack[-3];
    v0311 = Llength(nil, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = (Lisp_Object)greaterp2(v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    v0270 = v0270 ? lisp_true : nil;
    env = stack[-9];
    if (v0270 == nil) goto v0022;
    v0270 = stack[-3];
    stack[-4] = v0270;
    v0270 = stack[-4];
    if (v0270 == nil) goto v0100;
    v0270 = stack[-4];
    v0270 = qcar(v0270);
    stack[0] = v0270;
    v0270 = elt(env, 6); /* g */
    v0270 = Lgensym1(nil, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = cons(stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = ncons(v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    stack[-2] = v0270;
    stack[-3] = v0270;
    goto v0096;

v0096:
    v0270 = stack[-4];
    v0270 = qcdr(v0270);
    stack[-4] = v0270;
    v0270 = stack[-4];
    if (v0270 == nil) goto v0179;
    stack[-1] = stack[-2];
    v0270 = stack[-4];
    v0270 = qcar(v0270);
    stack[0] = v0270;
    v0270 = elt(env, 6); /* g */
    v0270 = Lgensym1(nil, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = cons(stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = ncons(v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = Lrplacd(nil, stack[-1], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = stack[-2];
    v0270 = qcdr(v0270);
    stack[-2] = v0270;
    goto v0096;

v0179:
    v0270 = stack[-3];
    goto v0095;

v0095:
    stack[0] = v0270;
    v0311 = stack[0];
    v0270 = stack[-8];
    fn = elt(env, 12); /* subla!-q */
    v0270 = (*qfn2(fn))(qenv(fn), v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    stack[-8] = v0270;
    v0270 = stack[0];
    stack[-3] = v0270;
    v0270 = stack[-3];
    if (v0270 == nil) goto v0209;
    v0270 = stack[-3];
    v0270 = qcar(v0270);
    v0270 = qcdr(v0270);
    v0270 = ncons(v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    stack[-1] = v0270;
    stack[-2] = v0270;
    goto v0005;

v0005:
    v0270 = stack[-3];
    v0270 = qcdr(v0270);
    stack[-3] = v0270;
    v0270 = stack[-3];
    if (v0270 == nil) goto v0040;
    stack[0] = stack[-1];
    v0270 = stack[-3];
    v0270 = qcar(v0270);
    v0270 = qcdr(v0270);
    v0270 = ncons(v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = Lrplacd(nil, stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = stack[-1];
    v0270 = qcdr(v0270);
    stack[-1] = v0270;
    goto v0005;

v0040:
    v0270 = stack[-2];
    goto v0205;

v0205:
    stack[-3] = v0270;
    goto v0022;

v0022:
    v0270 = stack[-7];
    stack[-1] = v0270;
    goto v0166;

v0166:
    v0270 = stack[-1];
    if (v0270 == nil) goto v0222;
    v0270 = stack[-1];
    v0270 = qcar(v0270);
    stack[0] = v0270;
    v0270 = stack[0];
    fn = elt(env, 13); /* no!-side!-effectp */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    if (!(v0270 == nil)) goto v0198;
    v0270 = stack[-3];
    v0311 = qcar(v0270);
    v0270 = stack[-8];
    fn = elt(env, 14); /* one!-entryp */
    v0270 = (*qfn2(fn))(qenv(fn), v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    if (!(v0270 == nil)) goto v0198;
    stack[-2] = stack[-6];
    v0270 = stack[-3];
    v0311 = qcar(v0270);
    v0270 = stack[0];
    v0270 = cons(v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    fn = elt(env, 15); /* aconc */
    v0270 = (*qfn2(fn))(qenv(fn), stack[-2], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    stack[-6] = v0270;
    goto v0219;

v0219:
    v0270 = stack[-3];
    v0270 = qcdr(v0270);
    stack[-3] = v0270;
    v0270 = stack[-1];
    v0270 = qcdr(v0270);
    stack[-1] = v0270;
    goto v0166;

v0198:
    v0270 = stack[-3];
    v0311 = qcar(v0270);
    v0270 = stack[0];
    v0270 = cons(v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0311 = ncons(v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = stack[-8];
    fn = elt(env, 12); /* subla!-q */
    v0270 = (*qfn2(fn))(qenv(fn), v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    stack[-8] = v0270;
    goto v0219;

v0222:
    v0270 = stack[-6];
    if (v0270 == nil) goto v0148;
    stack[-4] = elt(env, 7); /* lambda */
    v0270 = stack[-6];
    stack[-3] = v0270;
    v0270 = stack[-3];
    if (v0270 == nil) goto v0356;
    v0270 = stack[-3];
    v0270 = qcar(v0270);
    v0270 = qcar(v0270);
    v0270 = ncons(v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    stack[-1] = v0270;
    stack[-2] = v0270;
    goto v0135;

v0135:
    v0270 = stack[-3];
    v0270 = qcdr(v0270);
    stack[-3] = v0270;
    v0270 = stack[-3];
    if (v0270 == nil) goto v0142;
    stack[0] = stack[-1];
    v0270 = stack[-3];
    v0270 = qcar(v0270);
    v0270 = qcar(v0270);
    v0270 = ncons(v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = Lrplacd(nil, stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = stack[-1];
    v0270 = qcdr(v0270);
    stack[-1] = v0270;
    goto v0135;

v0142:
    v0270 = stack[-2];
    v0311 = v0270;
    goto v0307;

v0307:
    v0270 = stack[-8];
    stack[-3] = list3(stack[-4], v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = stack[-6];
    stack[-4] = v0270;
    v0270 = stack[-4];
    if (v0270 == nil) goto v0310;
    v0270 = stack[-4];
    v0270 = qcar(v0270);
    v0270 = qcdr(v0270);
    v0270 = ncons(v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    stack[-1] = v0270;
    stack[-2] = v0270;
    goto v0357;

v0357:
    v0270 = stack[-4];
    v0270 = qcdr(v0270);
    stack[-4] = v0270;
    v0270 = stack[-4];
    if (v0270 == nil) goto v0358;
    stack[0] = stack[-1];
    v0270 = stack[-4];
    v0270 = qcar(v0270);
    v0270 = qcdr(v0270);
    v0270 = ncons(v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = Lrplacd(nil, stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = stack[-1];
    v0270 = qcdr(v0270);
    stack[-1] = v0270;
    goto v0357;

v0358:
    v0270 = stack[-2];
    goto v0359;

v0359:
    v0270 = cons(stack[-3], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    stack[0] = v0270;
    v0270 = stack[0];
    goto v0124;

v0124:
    qvalue(elt(env, 1)) = stack[-5]; /* inlineinfo */
    { popv(10); return onevalue(v0270); }

v0310:
    v0270 = qvalue(elt(env, 5)); /* nil */
    goto v0359;

v0356:
    v0270 = qvalue(elt(env, 5)); /* nil */
    v0311 = v0270;
    goto v0307;

v0148:
    v0270 = stack[-8];
    goto v0124;

v0209:
    v0270 = qvalue(elt(env, 5)); /* nil */
    goto v0205;

v0100:
    v0270 = qvalue(elt(env, 5)); /* nil */
    goto v0095;

v0010:
    v0311 = stack[-3];
    v0270 = stack[-7];
    fn = elt(env, 16); /* pair */
    v0311 = (*qfn2(fn))(qenv(fn), v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    v0270 = stack[-8];
    fn = elt(env, 12); /* subla!-q */
    v0270 = (*qfn2(fn))(qenv(fn), v0311, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-9];
    goto v0124;
/* error exit handlers */
v0355:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-5]; /* inlineinfo */
    popv(10);
    return nil;
}



/* Code for mv!-compact2 */

static Lisp_Object CC_mvKcompact2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0063)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0069, v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-compact2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0063);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0063;
    stack[-1] = v0000;
/* end of prologue */
    v0069 = stack[-1];
    v0025 = stack[0];
    fn = elt(env, 2); /* equiv!-coeffs */
    v0025 = (*qfn2(fn))(qenv(fn), v0069, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    stack[-2] = v0025;
    v0025 = stack[0];
    fn = elt(env, 3); /* mv!-domainlist */
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    v0069 = stack[-2];
    fn = elt(env, 4); /* reduce */
    v0025 = (*qfn2(fn))(qenv(fn), v0069, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    v0066 = v0025;
    v0069 = v0066;
    v0025 = stack[-2];
    if (equal(v0069, v0025)) goto v0031;
    v0069 = v0066;
    v0025 = stack[-2];
    fn = elt(env, 5); /* mv!-domainlist!-!- */
    v0025 = (*qfn2(fn))(qenv(fn), v0069, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    fn = elt(env, 6); /* mv!-coeff!-replace */
    v0069 = (*qfn2(fn))(qenv(fn), stack[0], v0025);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    v0025 = stack[-1];
    {
        popv(4);
        fn = elt(env, 7); /* mv!-!+ */
        return (*qfn2(fn))(qenv(fn), v0069, v0025);
    }

v0031:
    v0025 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0025); }
/* error exit handlers */
v0201:
    popv(4);
    return nil;
}



/* Code for subs2p */

static Lisp_Object MS_CDECL CC_subs2p(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0063,
                         Lisp_Object v0058, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0342, v0215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subs2p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0058,v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0063,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0058;
    stack[-1] = v0063;
    stack[-2] = v0000;
/* end of prologue */
    v0342 = stack[-2];
    v0342 = qcdr(v0342);
    v0342 = integerp(v0342);
    if (v0342 == nil) goto v0082;
    v0342 = stack[-2];
    v0215 = qcdr(v0342);
    v0342 = stack[-1];
    v0342 = Ldivide(nil, v0215, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    stack[-1] = v0342;
    v0215 = qcar(v0342);
    v0342 = (Lisp_Object)1; /* 0 */
    v0342 = (v0215 == v0342 ? lisp_true : nil);
    goto v0094;

v0094:
    if (v0342 == nil) goto v0065;
    v0215 = stack[-2];
    v0342 = (Lisp_Object)17; /* 1 */
    v0342 = cons(v0215, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0215 = ncons(v0342);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    v0342 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v0215, v0342);

v0065:
    v0342 = stack[0];
    fn = elt(env, 2); /* simp */
    v0215 = (*qfn1(fn))(qenv(fn), v0342);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0342 = stack[-1];
    v0342 = qcar(v0342);
    fn = elt(env, 3); /* exptsq */
    v0342 = (*qfn2(fn))(qenv(fn), v0215, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    stack[0] = v0342;
    v0342 = stack[-1];
    v0215 = qcdr(v0342);
    v0342 = (Lisp_Object)1; /* 0 */
    if (v0215 == v0342) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0342 = stack[-2];
    v0215 = qcar(v0342);
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    fn = elt(env, 4); /* to */
    v0215 = (*qfn2(fn))(qenv(fn), v0215, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0342 = (Lisp_Object)17; /* 1 */
    v0342 = cons(v0215, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0215 = ncons(v0342);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0342 = (Lisp_Object)17; /* 1 */
    v0215 = cons(v0215, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0342 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0215, v0342);
    }

v0082:
    v0342 = qvalue(elt(env, 1)); /* t */
    goto v0094;
/* error exit handlers */
v0014:
    popv(4);
    return nil;
}



/* Code for fs!:make!-nullangle */

static Lisp_Object MS_CDECL CC_fsTmakeKnullangle(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0026, v0048;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fs:make-nullangle");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:make-nullangle");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    v0027 = (Lisp_Object)113; /* 7 */
    v0027 = Lmkvect(nil, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    stack[-1] = v0027;
    v0027 = (Lisp_Object)1; /* 0 */
    stack[0] = v0027;
    goto v0051;

v0051:
    v0026 = (Lisp_Object)113; /* 7 */
    v0027 = stack[0];
    v0027 = difference2(v0026, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0027 = Lminusp(nil, v0027);
    env = stack[-2];
    if (!(v0027 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0048 = stack[-1];
    v0026 = stack[0];
    v0027 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0048 + (CELL-TAG_VECTOR) + ((int32_t)v0026/(16/CELL))) = v0027;
    v0027 = stack[0];
    v0027 = add1(v0027);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    stack[0] = v0027;
    goto v0051;
/* error exit handlers */
v0054:
    popv(3);
    return nil;
}



/* Code for groeb!=crita */

static Lisp_Object CC_groebMcrita(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=crita");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0124 = v0000;
/* end of prologue */
    v0094 = v0124;
    v0124 = elt(env, 1); /* groeb!=testa */
    {
        fn = elt(env, 2); /* listminimize */
        return (*qfn2(fn))(qenv(fn), v0094, v0124);
    }
}



/* Code for makeqn!-maybe */

static Lisp_Object MS_CDECL CC_makeqnKmaybe(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0063,
                         Lisp_Object v0058, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073, v0078, v0079;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "makeqn-maybe");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeqn-maybe");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0073 = v0058;
    v0078 = v0063;
    v0079 = v0000;
/* end of prologue */
    if (!(v0073 == nil)) return onevalue(v0078);
    v0073 = elt(env, 1); /* equal */
    return list3(v0073, v0079, v0078);
}



/* Code for cl_trygaussvar */

static Lisp_Object MS_CDECL CC_cl_trygaussvar(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0063,
                         Lisp_Object v0058, Lisp_Object v0060,
                         Lisp_Object v0034, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0012, v0086, v0335, v0328;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "cl_trygaussvar");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_trygaussvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0034,v0060,v0058,v0063,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0063,v0058,v0060,v0034);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0034;
    stack[-1] = v0060;
    stack[-2] = v0058;
    stack[-3] = v0063;
    stack[-4] = v0000;
/* end of prologue */
    v0108 = stack[-4];
    fn = elt(env, 4); /* cl_atfp */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-5];
    if (v0108 == nil) goto v0103;
    v0328 = stack[-4];
    v0335 = stack[-3];
    v0086 = stack[-2];
    v0012 = stack[-1];
    v0108 = stack[0];
    {
        popv(6);
        fn = elt(env, 5); /* rl_qefsolset */
        return (*qfnn(fn))(qenv(fn), 5, v0328, v0335, v0086, v0012, v0108);
    }

v0103:
    v0108 = stack[-4];
    if (!consp(v0108)) goto v0027;
    v0108 = stack[-4];
    v0108 = qcar(v0108);
    v0012 = v0108;
    goto v0098;

v0098:
    v0108 = elt(env, 1); /* and */
    if (v0012 == v0108) goto v0029;
    v0108 = stack[-4];
    if (!consp(v0108)) goto v0072;
    v0108 = stack[-4];
    v0108 = qcar(v0108);
    v0012 = v0108;
    goto v0092;

v0092:
    v0108 = elt(env, 2); /* or */
    if (v0012 == v0108) goto v0121;
    v0108 = elt(env, 3); /* (failed) */
    { popv(6); return onevalue(v0108); }

v0121:
    v0108 = stack[-4];
    v0328 = qcdr(v0108);
    v0335 = stack[-3];
    v0086 = stack[-2];
    v0012 = stack[-1];
    v0108 = stack[0];
    {
        popv(6);
        fn = elt(env, 6); /* cl_gaussor */
        return (*qfnn(fn))(qenv(fn), 5, v0328, v0335, v0086, v0012, v0108);
    }

v0072:
    v0108 = stack[-4];
    v0012 = v0108;
    goto v0092;

v0029:
    v0108 = stack[-4];
    v0328 = qcdr(v0108);
    v0335 = stack[-3];
    v0086 = stack[-2];
    v0012 = stack[-1];
    v0108 = stack[0];
    {
        popv(6);
        fn = elt(env, 7); /* cl_gaussand */
        return (*qfnn(fn))(qenv(fn), 5, v0328, v0335, v0086, v0012, v0108);
    }

v0027:
    v0108 = stack[-4];
    v0012 = v0108;
    goto v0098;
/* error exit handlers */
v0107:
    popv(6);
    return nil;
}



setup_type const u31_setup[] =
{
    {"numprintlen",             CC_numprintlen, too_many_1,    wrong_no_1},
    {"consrecip",               CC_consrecip,   too_many_1,    wrong_no_1},
    {"arglength",               CC_arglength,   too_many_1,    wrong_no_1},
    {"general-multiply-by-constant-mod-p",too_few_2,CC_generalKmultiplyKbyKconstantKmodKp,wrong_no_2},
    {"algmodep",                CC_algmodep,    too_many_1,    wrong_no_1},
    {"createmonomunit",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_createmonomunit},
    {"rtypepart",               CC_rtypepart,   too_many_1,    wrong_no_1},
    {"pasf_ceil",               too_few_2,      CC_pasf_ceil,  wrong_no_2},
    {"aex_red",                 too_few_2,      CC_aex_red,    wrong_no_2},
    {"rl_updcache",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_updcache},
    {"intervalrd",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_intervalrd},
    {"d2int",                   CC_d2int,       too_many_1,    wrong_no_1},
    {"simpimpart",              CC_simpimpart,  too_many_1,    wrong_no_1},
    {"indexvp",                 CC_indexvp,     too_many_1,    wrong_no_1},
    {"cvitimes2",               too_few_2,      CC_cvitimes2,  wrong_no_2},
    {"mod_eval_uni_poly",       too_few_2,      CC_mod_eval_uni_poly,wrong_no_2},
    {"precision",               CC_precision,   too_many_1,    wrong_no_1},
    {"use-berlekamp",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_useKberlekamp},
    {"co_new",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_co_new},
    {"tayfkern",                CC_tayfkern,    too_many_1,    wrong_no_1},
    {"mk+real+inner+product",   too_few_2,      CC_mkLrealLinnerLproduct,wrong_no_2},
    {"mri_ofsf2mriat",          too_few_2,      CC_mri_ofsf2mriat,wrong_no_2},
    {"rl_surep",                too_few_2,      CC_rl_surep,   wrong_no_2},
    {"transposerd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_transposerd},
    {"inszzz",                  too_few_2,      CC_inszzz,     wrong_no_2},
    {"vdpilcomb1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpilcomb1},
    {"fl2bf",                   CC_fl2bf,       too_many_1,    wrong_no_1},
    {"find_bubles1",            too_few_2,      CC_find_bubles1,wrong_no_2},
    {"simpquot",                CC_simpquot,    too_many_1,    wrong_no_1},
    {"cl_atnum",                CC_cl_atnum,    too_many_1,    wrong_no_1},
    {"evalgreaterp",            too_few_2,      CC_evalgreaterp,wrong_no_2},
    {"simpexpt1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt1},
    {"gen+can+bas",             CC_genLcanLbas, too_many_1,    wrong_no_1},
    {"rl_bnfsimpl",             too_few_2,      CC_rl_bnfsimpl,wrong_no_2},
    {"diffrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffrd},
    {"scar",                    too_few_2,      CC_scar,       wrong_no_2},
    {"size_of_matrix",          CC_size_of_matrix,too_many_1,  wrong_no_1},
    {"simpunion",               CC_simpunion,   too_many_1,    wrong_no_1},
    {"list-evaluate",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_listKevaluate},
    {"applsmacro",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_applsmacro},
    {"mv-compact2",             too_few_2,      CC_mvKcompact2,wrong_no_2},
    {"subs2p",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_subs2p},
    {"fs:make-nullangle",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTmakeKnullangle},
    {"groeb=crita",             CC_groebMcrita, too_many_1,    wrong_no_1},
    {"makeqn-maybe",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeqnKmaybe},
    {"cl_trygaussvar",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_trygaussvar},
    {NULL, (one_args *)"u31", (two_args *)"21152 8551574 7422061", 0}
};

/* end of generated code */
