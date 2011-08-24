
/* $destdir\u44.c        Machine generated C code */

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


/* Code for quotfx1 */

static Lisp_Object CC_quotfx1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfx1");
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
/* copy arguments values to proper place */
    stack[-7] = v1;
    stack[-8] = v0;
/* end of prologue */
    v74 = stack[-8];
    if (v74 == nil) goto v77;
    v75 = stack[-8];
    v74 = stack[-7];
    if (equal(v75, v74)) goto v78;
    v75 = stack[-7];
    v74 = (Lisp_Object)17; /* 1 */
    if (v75 == v74) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v74 = stack[-7];
    if (!consp(v74)) goto v79;
    v74 = stack[-7];
    v74 = qcar(v74);
    v74 = (consp(v74) ? nil : lisp_true);
    goto v80;

v80:
    if (v74 == nil) goto v81;
    v75 = stack[-8];
    v74 = stack[-7];
    {
        popv(11);
        fn = elt(env, 4); /* quotfdx */
        return (*qfn2(fn))(qenv(fn), v75, v74);
    }

v81:
    v74 = stack[-8];
    if (!consp(v74)) goto v82;
    v74 = stack[-8];
    v74 = qcar(v74);
    v74 = (consp(v74) ? nil : lisp_true);
    goto v83;

v83:
    if (v74 == nil) goto v84;
    v74 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v74 == nil)) goto v85;
    v74 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 5); /* lprie */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    goto v85;

v85:
    v74 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v74 = nil;
    { popv(11); return onevalue(v74); }

v84:
    v74 = stack[-8];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v75 = qcar(v74);
    v74 = stack[-7];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcar(v74);
    if (v75 == v74) goto v87;
    v74 = stack[-8];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v75 = qcar(v74);
    v74 = stack[-7];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcar(v74);
    fn = elt(env, 6); /* ordop */
    v74 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    if (v74 == nil) goto v88;
    v75 = stack[-8];
    v74 = stack[-7];
    {
        popv(11);
        fn = elt(env, 7); /* quotkx */
        return (*qfn2(fn))(qenv(fn), v75, v74);
    }

v88:
    v74 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v74 == nil)) goto v89;
    v74 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 5); /* lprie */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    goto v89;

v89:
    v74 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v74 = nil;
    { popv(11); return onevalue(v74); }

v87:
    stack[-9] = nil;
    stack[-1] = nil;
    v74 = stack[-7];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcdr(v74);
    stack[-5] = v74;
    goto v90;

v90:
    v74 = stack[-8];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v75 = qcdr(v74);
    stack[-6] = v75;
    v74 = stack[-5];
    v74 = (Lisp_Object)lessp2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v74 = v74 ? lisp_true : nil;
    env = stack[-10];
    if (v74 == nil) goto v91;
    v74 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v74 == nil)) goto v92;
    v74 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 5); /* lprie */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    goto v92;

v92:
    v74 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v74 = nil;
    { popv(11); return onevalue(v74); }

v91:
    v74 = stack[-8];
    fn = elt(env, 8); /* lt!* */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    stack[0] = v74;
    v74 = stack[-7];
    fn = elt(env, 8); /* lt!* */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    v75 = stack[-7];
    v75 = qcar(v75);
    v75 = qcar(v75);
    v75 = qcar(v75);
    stack[-4] = v75;
    v75 = stack[0];
    v75 = qcdr(v75);
    v74 = qcdr(v74);
    v74 = CC_quotfx1(env, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    stack[-3] = v74;
    v75 = stack[-6];
    v74 = stack[-5];
    v74 = (Lisp_Object)(int32_t)((int32_t)v75 - (int32_t)v74 + TAG_FIXNUM);
    stack[0] = v74;
    v75 = stack[0];
    v74 = (Lisp_Object)1; /* 0 */
    if (v75 == v74) goto v93;
    v75 = stack[-4];
    v74 = stack[0];
    v74 = cons(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    stack[-2] = v74;
    v74 = stack[-9];
    if (!(v74 == nil)) goto v94;
    v75 = stack[-6];
    v74 = stack[0];
    v74 = (Lisp_Object)(int32_t)((int32_t)v75 - (int32_t)v74 + TAG_FIXNUM);
    v74 = (Lisp_Object)((int32_t)(v74) - 0x10);
    v76 = v74;
    v75 = (Lisp_Object)17; /* 1 */
    if (((int32_t)(v76)) < ((int32_t)(v75))) goto v95;
    v76 = stack[-8];
    v75 = stack[-4];
    fn = elt(env, 9); /* cutf1 */
    v74 = (*qfnn(fn))(qenv(fn), 3, v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    goto v96;

v96:
    stack[-8] = v74;
    goto v94;

v94:
    v74 = qvalue(elt(env, 3)); /* t */
    stack[-9] = v74;
    v75 = stack[-5];
    v74 = stack[0];
    v74 = (Lisp_Object)(int32_t)((int32_t)v75 - (int32_t)v74 + TAG_FIXNUM);
    v74 = (Lisp_Object)((int32_t)(v74) - 0x10);
    v76 = v74;
    v75 = (Lisp_Object)17; /* 1 */
    if (((int32_t)(v76)) < ((int32_t)(v75))) goto v97;
    v76 = stack[-7];
    v75 = stack[-4];
    fn = elt(env, 9); /* cutf1 */
    v74 = (*qfnn(fn))(qenv(fn), 3, v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    goto v98;

v98:
    stack[-7] = v74;
    stack[-6] = stack[-8];
    v75 = stack[0];
    v74 = (Lisp_Object)1; /* 0 */
    if (v75 == v74) goto v99;
    v75 = stack[-2];
    v74 = (Lisp_Object)17; /* 1 */
    v74 = cons(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    v75 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    v74 = stack[-7];
    fn = elt(env, 10); /* multf */
    v74 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    stack[0] = v74;
    goto v100;

v100:
    v74 = stack[-3];
    fn = elt(env, 11); /* negf */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    fn = elt(env, 10); /* multf */
    v74 = (*qfn2(fn))(qenv(fn), stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    fn = elt(env, 12); /* addf */
    v74 = (*qfn2(fn))(qenv(fn), stack[-6], v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    stack[-8] = v74;
    v74 = stack[-8];
    if (v74 == nil) goto v101;
    v74 = stack[-8];
    if (!consp(v74)) goto v102;
    v74 = stack[-8];
    v74 = qcar(v74);
    v74 = (consp(v74) ? nil : lisp_true);
    goto v103;

v103:
    if (v74 == nil) goto v104;
    v74 = qvalue(elt(env, 3)); /* t */
    goto v105;

v105:
    if (v74 == nil) goto v101;
    v74 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v74 == nil)) goto v106;
    v74 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 5); /* lprie */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    goto v106;

v106:
    v74 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v74 = nil;
    { popv(11); return onevalue(v74); }

v101:
    stack[0] = stack[-1];
    v75 = stack[-2];
    v74 = stack[-3];
    v74 = cons(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    v74 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    v74 = Lnconc(nil, stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    stack[-1] = v74;
    v74 = stack[-8];
    if (v74 == nil) { Lisp_Object res = stack[-1]; popv(11); return onevalue(res); }
    else goto v90;

v104:
    v74 = stack[-8];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v75 = qcar(v74);
    v74 = stack[-4];
    v74 = (v75 == v74 ? lisp_true : nil);
    v74 = (v74 == nil ? lisp_true : nil);
    goto v105;

v102:
    v74 = qvalue(elt(env, 3)); /* t */
    goto v103;

v99:
    v74 = stack[-7];
    stack[0] = v74;
    goto v100;

v97:
    v74 = stack[-7];
    goto v98;

v95:
    v74 = stack[-8];
    goto v96;

v93:
    v75 = stack[-1];
    v74 = stack[-3];
    {
        popv(11);
        fn = elt(env, 13); /* rnconc */
        return (*qfn2(fn))(qenv(fn), v75, v74);
    }

v82:
    v74 = qvalue(elt(env, 3)); /* t */
    goto v83;

v79:
    v74 = qvalue(elt(env, 3)); /* t */
    goto v80;

v78:
    v74 = (Lisp_Object)17; /* 1 */
    { popv(11); return onevalue(v74); }

v77:
    v74 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v74 == nil)) goto v107;
    v74 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 5); /* lprie */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-10];
    goto v107;

v107:
    v74 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v74 = nil;
    { popv(11); return onevalue(v74); }
/* error exit handlers */
v86:
    popv(11);
    return nil;
}



/* Code for fac!-part */

static Lisp_Object CC_facKpart(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v85;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fac-part");
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
    v85 = stack[-1];
    v122 = stack[0];
    if (equal(v85, v122)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = stack[-1];
    v122 = stack[0];
    v122 = sub1(v122);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    if (equal(stack[-2], v122)) goto v73;
    v85 = stack[-1];
    v122 = stack[0];
    v85 = plus2(v85, v122);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    v122 = (Lisp_Object)33; /* 2 */
    v122 = quot2(v85, v122);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    stack[-2] = v122;
    v85 = stack[-1];
    v122 = stack[-2];
    stack[-1] = CC_facKpart(env, v85, v122);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    v122 = stack[-2];
    v85 = add1(v122);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    v122 = stack[0];
    v122 = CC_facKpart(env, v85, v122);
    nil = C_nil;
    if (exception_pending()) goto v123;
    {
        Lisp_Object v124 = stack[-1];
        popv(4);
        return times2(v124, v122);
    }

v73:
    v85 = stack[-1];
    v122 = stack[0];
    popv(4);
    return times2(v85, v122);
/* error exit handlers */
v123:
    popv(4);
    return nil;
}



/* Code for evalset_eq */

static Lisp_Object CC_evalset_eq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v116, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalset_eq");
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
    v117 = v1;
    v116 = v0;
/* end of prologue */
    v128 = elt(env, 1); /* set_eq */
    fn = elt(env, 3); /* evalsetbool */
    v117 = (*qfnn(fn))(qenv(fn), 3, v128, v116, v117);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[0];
    v116 = v117;
    if (!consp(v116)) { popv(1); return onevalue(v117); }
    v116 = elt(env, 2); /* equal */
    {
        popv(1);
        fn = elt(env, 4); /* apply */
        return (*qfn2(fn))(qenv(fn), v116, v117);
    }
/* error exit handlers */
v129:
    popv(1);
    return nil;
}



/* Code for rand!-mons!-sparse */

static Lisp_Object MS_CDECL CC_randKmonsKsparse(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v130, Lisp_Object v131,
                         Lisp_Object v132, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rand-mons-sparse");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rand-mons-sparse");
#endif
    if (stack >= stacklimit)
    {
        push5(v132,v131,v130,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v130,v131,v132);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v132;
    stack[-1] = v131;
    stack[-2] = v130;
    stack[-3] = v1;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    stack[-7] = nil;
    v186 = stack[0];
    if (v186 == nil) goto v128;
    v187 = (Lisp_Object)17; /* 1 */
    v186 = stack[-1];
    v186 = difference2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = plus2(stack[-2], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    goto v189;

v189:
    stack[-2] = v186;
    v187 = v186;
    v186 = stack[-3];
    fn = elt(env, 2); /* min */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    fn = elt(env, 3); /* rand!-comb */
    v186 = (*qfn2(fn))(qenv(fn), stack[-2], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v187 = v186;
    v186 = stack[0];
    if (v186 == nil) goto v190;
    v186 = v187;
    stack[-5] = v186;
    v186 = stack[-5];
    if (v186 == nil) goto v191;
    v186 = stack[-5];
    v186 = qcar(v186);
    stack[0] = stack[-8];
    v187 = v186;
    v186 = stack[-1];
    v186 = plus2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    fn = elt(env, 4); /* !*kp2f */
    v186 = (*qfn2(fn))(qenv(fn), stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    stack[-3] = v186;
    stack[-4] = v186;
    goto v192;

v192:
    v186 = stack[-5];
    v186 = qcdr(v186);
    stack[-5] = v186;
    v186 = stack[-5];
    if (v186 == nil) { Lisp_Object res = stack[-4]; popv(11); return onevalue(res); }
    stack[-2] = stack[-3];
    v186 = stack[-5];
    v186 = qcar(v186);
    stack[0] = stack[-8];
    v187 = v186;
    v186 = stack[-1];
    v186 = plus2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    fn = elt(env, 4); /* !*kp2f */
    v186 = (*qfn2(fn))(qenv(fn), stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = Lrplacd(nil, stack[-2], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = stack[-3];
    v186 = qcdr(v186);
    stack[-3] = v186;
    goto v192;

v191:
    v186 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v186); }

v190:
    v186 = v187;
    stack[-6] = v186;
    v186 = stack[-6];
    if (v186 == nil) goto v193;
    v186 = stack[-6];
    v186 = qcar(v186);
    stack[-2] = v186;
    v186 = (Lisp_Object)17; /* 1 */
    stack[-1] = v186;
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v187 = stack[-2];
    v186 = stack[-7];
    v187 = plus2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = stack[-9];
    fn = elt(env, 5); /* inttovec */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = cons(stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    stack[-2] = v186;
    v186 = stack[-8];
    stack[0] = v186;
    goto v45;

v45:
    v186 = stack[0];
    if (v186 == nil) goto v44;
    v186 = stack[0];
    v186 = qcar(v186);
    v187 = v186;
    v186 = stack[-2];
    v186 = qcdr(v186);
    stack[-2] = v186;
    v186 = qcar(v186);
    fn = elt(env, 4); /* !*kp2f */
    v187 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = stack[-1];
    fn = elt(env, 6); /* multf */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    stack[-1] = v186;
    v186 = stack[0];
    v186 = qcdr(v186);
    stack[0] = v186;
    goto v45;

v44:
    v186 = stack[-1];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    stack[-4] = v186;
    stack[-5] = v186;
    goto v194;

v194:
    v186 = stack[-6];
    v186 = qcdr(v186);
    stack[-6] = v186;
    v186 = stack[-6];
    if (v186 == nil) { Lisp_Object res = stack[-5]; popv(11); return onevalue(res); }
    stack[-3] = stack[-4];
    v186 = stack[-6];
    v186 = qcar(v186);
    stack[-2] = v186;
    v186 = (Lisp_Object)17; /* 1 */
    stack[-1] = v186;
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v187 = stack[-2];
    v186 = stack[-7];
    v187 = plus2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = stack[-9];
    fn = elt(env, 5); /* inttovec */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = cons(stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    stack[-2] = v186;
    v186 = stack[-8];
    stack[0] = v186;
    goto v195;

v195:
    v186 = stack[0];
    if (v186 == nil) goto v196;
    v186 = stack[0];
    v186 = qcar(v186);
    v187 = v186;
    v186 = stack[-2];
    v186 = qcdr(v186);
    stack[-2] = v186;
    v186 = qcar(v186);
    fn = elt(env, 4); /* !*kp2f */
    v187 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = stack[-1];
    fn = elt(env, 6); /* multf */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    stack[-1] = v186;
    v186 = stack[0];
    v186 = qcdr(v186);
    stack[0] = v186;
    goto v195;

v196:
    v186 = stack[-1];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = Lrplacd(nil, stack[-3], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = stack[-4];
    v186 = qcdr(v186);
    stack[-4] = v186;
    goto v194;

v193:
    v186 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v186); }

v128:
    v186 = stack[-8];
    v186 = Llength(nil, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    stack[-9] = v186;
    v186 = stack[-1];
    v186 = (Lisp_Object)zerop(v186);
    v186 = v186 ? lisp_true : nil;
    env = stack[-10];
    if (v186 == nil) goto v197;
    v186 = (Lisp_Object)1; /* 0 */
    goto v69;

v69:
    stack[-7] = v186;
    v187 = stack[-9];
    v186 = stack[-2];
    v187 = plus2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = stack[-9];
    fn = elt(env, 7); /* binomial */
    v187 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = stack[-7];
    v186 = difference2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    goto v189;

v197:
    stack[-4] = stack[-9];
    v186 = stack[-1];
    v186 = sub1(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v187 = plus2(stack[-4], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    v186 = stack[-9];
    fn = elt(env, 7); /* binomial */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-10];
    goto v69;
/* error exit handlers */
v188:
    popv(11);
    return nil;
}



/* Code for partitpartdf */

static Lisp_Object CC_partitpartdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitpartdf");
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
    v72 = v0;
/* end of prologue */
    v185 = v72;
    v185 = qcdr(v185);
    if (v185 == nil) goto v132;
    stack[0] = (Lisp_Object)17; /* 1 */
    v185 = v72;
    fn = elt(env, 1); /* simppartdf0 */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-1];
    v185 = cons(stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v199;
    popv(2);
    return ncons(v185);

v132:
    v185 = v72;
    v185 = qcar(v185);
    fn = elt(env, 2); /* !*a2k */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* mknatvec */
        return (*qfn1(fn))(qenv(fn), v185);
    }
/* error exit handlers */
v199:
    popv(2);
    return nil;
}



/* Code for cali!=min */

static Lisp_Object MS_CDECL CC_caliMmin(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v130, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cali=min");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cali=min");
#endif
    if (stack >= stacklimit)
    {
        push3(v130,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v130);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v130;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v145:
    v67 = stack[-1];
    if (v67 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v202 = stack[-2];
    v67 = stack[-1];
    v68 = qcar(v67);
    v67 = stack[0];
    fn = elt(env, 1); /* listtest */
    v67 = (*qfnn(fn))(qenv(fn), 3, v202, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    if (!(v67 == nil)) goto v121;
    v67 = stack[-1];
    v202 = qcdr(v67);
    v67 = stack[-1];
    v68 = qcar(v67);
    v67 = stack[0];
    fn = elt(env, 1); /* listtest */
    v67 = (*qfnn(fn))(qenv(fn), 3, v202, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    if (!(v67 == nil)) goto v121;
    v67 = stack[-1];
    v68 = qcar(v67);
    v67 = stack[-2];
    v67 = cons(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    stack[-2] = v67;
    v67 = stack[-1];
    v67 = qcdr(v67);
    stack[-1] = v67;
    goto v145;

v121:
    v67 = stack[-1];
    v67 = qcdr(v67);
    stack[-1] = v67;
    goto v145;
/* error exit handlers */
v82:
    popv(4);
    return nil;
}



/* Code for pst_d */

static Lisp_Object MS_CDECL CC_pst_d(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v130, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v238, v239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pst_d");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_d");
#endif
    if (stack >= stacklimit)
    {
        push3(v130,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v130);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v130;
    stack[-9] = v1;
    stack[-2] = v0;
/* end of prologue */
    v136 = stack[-2];
    fn = elt(env, 2); /* listp */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    if (v136 == nil) goto v241;
    v136 = stack[-9];
    fn = elt(env, 2); /* listp */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    if (v136 == nil) goto v149;
    v136 = stack[-2];
    stack[-10] = v136;
    v136 = stack[-10];
    if (v136 == nil) goto v73;
    v136 = stack[-10];
    v136 = qcar(v136);
    stack[-4] = v136;
    v136 = stack[-9];
    stack[-3] = v136;
    v136 = stack[-3];
    if (v136 == nil) goto v242;
    v136 = stack[-3];
    v136 = qcar(v136);
    v239 = stack[-4];
    v238 = v136;
    v136 = stack[-8];
    v136 = CC_pst_d(env, 3, v239, v238, v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-1] = v136;
    stack[-2] = v136;
    goto v69;

v69:
    v136 = stack[-3];
    v136 = qcdr(v136);
    stack[-3] = v136;
    v136 = stack[-3];
    if (v136 == nil) goto v243;
    stack[0] = stack[-1];
    v136 = stack[-3];
    v136 = qcar(v136);
    v239 = stack[-4];
    v238 = v136;
    v136 = stack[-8];
    v136 = CC_pst_d(env, 3, v239, v238, v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = Lrplacd(nil, stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = stack[-1];
    v136 = qcdr(v136);
    stack[-1] = v136;
    goto v69;

v243:
    v136 = stack[-2];
    goto v81;

v81:
    fn = elt(env, 3); /* ordn */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-6] = v136;
    stack[-7] = v136;
    goto v118;

v118:
    v136 = stack[-10];
    v136 = qcdr(v136);
    stack[-10] = v136;
    v136 = stack[-10];
    if (v136 == nil) goto v38;
    stack[-5] = stack[-6];
    v136 = stack[-10];
    v136 = qcar(v136);
    stack[-4] = v136;
    v136 = stack[-9];
    stack[-3] = v136;
    v136 = stack[-3];
    if (v136 == nil) goto v90;
    v136 = stack[-3];
    v136 = qcar(v136);
    v239 = stack[-4];
    v238 = v136;
    v136 = stack[-8];
    v136 = CC_pst_d(env, 3, v239, v238, v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-1] = v136;
    stack[-2] = v136;
    goto v91;

v91:
    v136 = stack[-3];
    v136 = qcdr(v136);
    stack[-3] = v136;
    v136 = stack[-3];
    if (v136 == nil) goto v244;
    stack[0] = stack[-1];
    v136 = stack[-3];
    v136 = qcar(v136);
    v239 = stack[-4];
    v238 = v136;
    v136 = stack[-8];
    v136 = CC_pst_d(env, 3, v239, v238, v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = Lrplacd(nil, stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = stack[-1];
    v136 = qcdr(v136);
    stack[-1] = v136;
    goto v91;

v244:
    v136 = stack[-2];
    goto v245;

v245:
    fn = elt(env, 3); /* ordn */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = Lrplacd(nil, stack[-5], v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = stack[-6];
    v136 = qcdr(v136);
    stack[-6] = v136;
    goto v118;

v90:
    v136 = qvalue(elt(env, 1)); /* nil */
    goto v245;

v38:
    v136 = stack[-7];
    goto v198;

v198:
    {
        popv(12);
        fn = elt(env, 3); /* ordn */
        return (*qfn1(fn))(qenv(fn), v136);
    }

v242:
    v136 = qvalue(elt(env, 1)); /* nil */
    goto v81;

v73:
    v136 = qvalue(elt(env, 1)); /* nil */
    goto v198;

v149:
    v136 = stack[-2];
    stack[-3] = v136;
    v136 = stack[-3];
    if (v136 == nil) goto v246;
    v136 = stack[-3];
    v136 = qcar(v136);
    v239 = v136;
    v238 = stack[-9];
    v136 = stack[-8];
    v136 = CC_pst_d(env, 3, v239, v238, v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-1] = v136;
    stack[-2] = v136;
    goto v193;

v193:
    v136 = stack[-3];
    v136 = qcdr(v136);
    stack[-3] = v136;
    v136 = stack[-3];
    if (v136 == nil) goto v39;
    stack[0] = stack[-1];
    v136 = stack[-3];
    v136 = qcar(v136);
    v239 = v136;
    v238 = stack[-9];
    v136 = stack[-8];
    v136 = CC_pst_d(env, 3, v239, v238, v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = Lrplacd(nil, stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = stack[-1];
    v136 = qcdr(v136);
    stack[-1] = v136;
    goto v193;

v39:
    v136 = stack[-2];
    goto v247;

v247:
    {
        popv(12);
        fn = elt(env, 3); /* ordn */
        return (*qfn1(fn))(qenv(fn), v136);
    }

v246:
    v136 = qvalue(elt(env, 1)); /* nil */
    goto v247;

v241:
    v136 = stack[-9];
    fn = elt(env, 2); /* listp */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    if (v136 == nil) goto v248;
    v136 = stack[-9];
    stack[-4] = v136;
    v136 = stack[-4];
    if (v136 == nil) goto v249;
    v136 = stack[-4];
    v136 = qcar(v136);
    v239 = stack[-2];
    v238 = v136;
    v136 = stack[-8];
    v136 = CC_pst_d(env, 3, v239, v238, v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-1] = v136;
    stack[-3] = v136;
    goto v97;

v97:
    v136 = stack[-4];
    v136 = qcdr(v136);
    stack[-4] = v136;
    v136 = stack[-4];
    if (v136 == nil) goto v250;
    stack[0] = stack[-1];
    v136 = stack[-4];
    v136 = qcar(v136);
    v239 = stack[-2];
    v238 = v136;
    v136 = stack[-8];
    v136 = CC_pst_d(env, 3, v239, v238, v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = Lrplacd(nil, stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v136 = stack[-1];
    v136 = qcdr(v136);
    stack[-1] = v136;
    goto v97;

v250:
    v136 = stack[-3];
    goto v98;

v98:
    {
        popv(12);
        fn = elt(env, 3); /* ordn */
        return (*qfn1(fn))(qenv(fn), v136);
    }

v249:
    v136 = qvalue(elt(env, 1)); /* nil */
    goto v98;

v248:
    v239 = stack[-2];
    v238 = stack[-9];
    v136 = stack[-8];
    {
        popv(12);
        fn = elt(env, 4); /* pst_d1 */
        return (*qfnn(fn))(qenv(fn), 3, v239, v238, v136);
    }
/* error exit handlers */
v240:
    popv(12);
    return nil;
}



/* Code for !?a2bf */

static Lisp_Object CC_Wa2bf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v201, v81;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ?a2bf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v201 = v0;
/* end of prologue */
    v236 = v201;
    if (!consp(v236)) goto v132;
    v236 = v201;
    v81 = elt(env, 3); /* !:dn!: */
    if (!consp(v236)) goto v199;
    v236 = qcar(v236);
    if (v236 == v81) return onevalue(v201);
    else goto v199;

v199:
    v236 = nil;
    return onevalue(v236);

v132:
    v236 = v201;
    if (is_number(v236)) goto v121;
    v236 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v236);

v121:
    v81 = elt(env, 1); /* !:rd!: */
    v236 = (Lisp_Object)1; /* 0 */
    return list2star(v81, v201, v236);
}



/* Code for giminusp!: */

static Lisp_Object CC_giminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v73, v199;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giminusp:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v73 = v0;
/* end of prologue */
    v72 = v73;
    v72 = qcdr(v72);
    v199 = qcar(v72);
    v72 = (Lisp_Object)1; /* 0 */
    if (v199 == v72) goto v132;
    v72 = v73;
    v72 = qcdr(v72);
    v72 = qcar(v72);
        return Lminusp(nil, v72);

v132:
    v72 = v73;
    v72 = qcdr(v72);
    v72 = qcdr(v72);
        return Lminusp(nil, v72);
}



/* Code for canprod */

static Lisp_Object CC_canprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v286, v287, v288, v289;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for canprod");
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
    stack[0] = nil;
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v286 = stack[-3];
    if (!consp(v286)) goto v215;
    v286 = stack[-3];
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    goto v230;

v230:
    if (v286 == nil) goto v126;
    v286 = qvalue(elt(env, 1)); /* t */
    goto v290;

v290:
    if (v286 == nil) goto v291;
    v287 = stack[-4];
    v286 = stack[-3];
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 3); /* cancel */
        return (*qfn1(fn))(qenv(fn), v286);
    }

v291:
    v286 = stack[-4];
    if (!consp(v286)) goto v123;
    v286 = stack[-4];
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    goto v232;

v232:
    if (v286 == nil) goto v85;
    v286 = stack[-3];
    if (!consp(v286)) goto v177;
    v286 = stack[-3];
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    goto v64;

v64:
    v286 = (v286 == nil ? lisp_true : nil);
    goto v122;

v122:
    if (v286 == nil) goto v293;
    v286 = stack[-4];
    fn = elt(env, 4); /* sfpf */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    if (v286 == nil) goto v172;
    v286 = stack[-4];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v289 = qcar(v286);
    v286 = stack[-4];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v288 = qcdr(v286);
    v287 = stack[0];
    v286 = stack[-5];
    fn = elt(env, 5); /* cprod1 */
    v286 = (*qfnn(fn))(qenv(fn), 4, v289, v288, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    v287 = v286;
    v286 = v287;
    v286 = qcar(v286);
    stack[0] = v286;
    v286 = v287;
    v286 = qcdr(v286);
    stack[-5] = v286;
    v286 = stack[-4];
    v286 = qcar(v286);
    v286 = qcdr(v286);
    stack[-4] = v286;
    goto v291;

v172:
    v286 = stack[-3];
    fn = elt(env, 4); /* sfpf */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    if (v286 == nil) goto v294;
    v286 = stack[-3];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v289 = qcar(v286);
    v286 = stack[-3];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v288 = qcdr(v286);
    v287 = stack[-5];
    v286 = stack[0];
    fn = elt(env, 5); /* cprod1 */
    v286 = (*qfnn(fn))(qenv(fn), 4, v289, v288, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    v287 = v286;
    v286 = v287;
    v286 = qcar(v286);
    stack[-5] = v286;
    v286 = v287;
    v286 = qcdr(v286);
    stack[0] = v286;
    v286 = stack[-3];
    v286 = qcar(v286);
    v286 = qcdr(v286);
    stack[-3] = v286;
    goto v291;

v294:
    v286 = stack[-4];
    if (!consp(v286)) goto v221;
    v286 = stack[-4];
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    goto v169;

v169:
    if (v286 == nil) goto v295;
    v286 = stack[-3];
    v286 = qcar(v286);
    v287 = qcar(v286);
    v286 = stack[-1];
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    stack[-1] = v286;
    v286 = stack[-3];
    v286 = qcar(v286);
    v286 = qcdr(v286);
    stack[-3] = v286;
    goto v291;

v295:
    v286 = stack[-3];
    if (!consp(v286)) goto v94;
    v286 = stack[-3];
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    goto v296;

v296:
    if (v286 == nil) goto v210;
    v286 = stack[-4];
    v286 = qcar(v286);
    v287 = qcar(v286);
    v286 = stack[-2];
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    stack[-2] = v286;
    v286 = stack[-4];
    v286 = qcar(v286);
    v286 = qcdr(v286);
    stack[-4] = v286;
    goto v291;

v210:
    v286 = stack[-4];
    v286 = qcar(v286);
    v287 = qcar(v286);
    v286 = stack[-2];
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    stack[-2] = v286;
    v286 = stack[-3];
    v286 = qcar(v286);
    v287 = qcar(v286);
    v286 = stack[-1];
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    stack[-1] = v286;
    v286 = stack[-4];
    v286 = qcar(v286);
    v286 = qcdr(v286);
    stack[-4] = v286;
    v286 = stack[-3];
    v286 = qcar(v286);
    v286 = qcdr(v286);
    stack[-3] = v286;
    goto v291;

v94:
    v286 = qvalue(elt(env, 1)); /* t */
    goto v296;

v221:
    v286 = qvalue(elt(env, 1)); /* t */
    goto v169;

v293:
    v287 = stack[-2];
    v286 = stack[-4];
    fn = elt(env, 6); /* reprod */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    fn = elt(env, 6); /* reprod */
    v286 = (*qfn2(fn))(qenv(fn), stack[0], v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    stack[0] = v286;
    stack[-4] = stack[-5];
    v287 = stack[-1];
    v286 = stack[-3];
    fn = elt(env, 6); /* reprod */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    fn = elt(env, 6); /* reprod */
    v286 = (*qfn2(fn))(qenv(fn), stack[-4], v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    stack[-5] = v286;
    v286 = stack[-5];
    fn = elt(env, 7); /* minusf */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    if (v286 == nil) goto v297;
    v286 = stack[0];
    fn = elt(env, 8); /* negf */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    stack[0] = v286;
    v286 = stack[-5];
    fn = elt(env, 8); /* negf */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    stack[-5] = v286;
    goto v297;

v297:
    v287 = stack[0];
    v286 = stack[-5];
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    fn = elt(env, 3); /* cancel */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    stack[-5] = v286;
    v286 = stack[-5];
    v286 = qcar(v286);
    stack[0] = v286;
    v286 = stack[0];
    if (!consp(v286)) goto v298;
    v286 = stack[0];
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    goto v248;

v248:
    if (v286 == nil) goto v299;
    v286 = qvalue(elt(env, 2)); /* nil */
    goto v300;

v300:
    if (v286 == nil) goto v196;
    v286 = stack[-2];
    stack[0] = v286;
    goto v196;

v196:
    v286 = stack[-5];
    v286 = qcdr(v286);
    stack[-5] = v286;
    v286 = stack[-5];
    if (!consp(v286)) goto v301;
    v286 = stack[-5];
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    goto v302;

v302:
    if (v286 == nil) goto v303;
    v286 = qvalue(elt(env, 2)); /* nil */
    goto v304;

v304:
    if (v286 == nil) goto v305;
    v286 = stack[-2];
    stack[-5] = v286;
    goto v305;

v305:
    v287 = stack[0];
    v286 = stack[-5];
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 9); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v286);
    }

v303:
    v286 = stack[-5];
    v286 = qcdr(v286);
    if (v286 == nil) goto v306;
    v286 = qvalue(elt(env, 2)); /* nil */
    goto v304;

v306:
    v286 = stack[-5];
    v286 = qcar(v286);
    v287 = qcdr(v286);
    v286 = (Lisp_Object)17; /* 1 */
    if (v287 == v286) goto v76;
    v286 = qvalue(elt(env, 2)); /* nil */
    goto v304;

v76:
    v286 = stack[-5];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v287 = qcdr(v286);
    v286 = (Lisp_Object)17; /* 1 */
    if (v287 == v286) goto v74;
    v286 = qvalue(elt(env, 2)); /* nil */
    goto v304;

v74:
    v286 = stack[-5];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v286 = qcar(v286);
    stack[-2] = v286;
    v287 = v286;
    v286 = v287;
    if (!consp(v286)) goto v307;
    v286 = v287;
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    v286 = (v286 == nil ? lisp_true : nil);
    goto v304;

v307:
    v286 = qvalue(elt(env, 2)); /* nil */
    goto v304;

v301:
    v286 = qvalue(elt(env, 1)); /* t */
    goto v302;

v299:
    v286 = stack[0];
    v286 = qcdr(v286);
    if (v286 == nil) goto v137;
    v286 = qvalue(elt(env, 2)); /* nil */
    goto v300;

v137:
    v286 = stack[0];
    v286 = qcar(v286);
    v287 = qcdr(v286);
    v286 = (Lisp_Object)17; /* 1 */
    if (v287 == v286) goto v308;
    v286 = qvalue(elt(env, 2)); /* nil */
    goto v300;

v308:
    v286 = stack[0];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v287 = qcdr(v286);
    v286 = (Lisp_Object)17; /* 1 */
    if (v287 == v286) goto v309;
    v286 = qvalue(elt(env, 2)); /* nil */
    goto v300;

v309:
    v286 = stack[0];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v286 = qcar(v286);
    stack[-2] = v286;
    v287 = v286;
    v286 = v287;
    if (!consp(v286)) goto v310;
    v286 = v287;
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    v286 = (v286 == nil ? lisp_true : nil);
    goto v300;

v310:
    v286 = qvalue(elt(env, 2)); /* nil */
    goto v300;

v298:
    v286 = qvalue(elt(env, 1)); /* t */
    goto v248;

v177:
    v286 = qvalue(elt(env, 1)); /* t */
    goto v64;

v85:
    v286 = qvalue(elt(env, 1)); /* t */
    goto v122;

v123:
    v286 = qvalue(elt(env, 1)); /* t */
    goto v232;

v126:
    v286 = stack[-3];
    v286 = qcdr(v286);
    if (!(v286 == nil)) goto v290;
    v286 = stack[-4];
    if (!consp(v286)) goto v311;
    v286 = stack[-4];
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    goto v79;

v79:
    if (v286 == nil) goto v81;
    v286 = qvalue(elt(env, 2)); /* nil */
    goto v290;

v81:
    v286 = stack[-4];
    v286 = qcdr(v286);
    goto v290;

v311:
    v286 = qvalue(elt(env, 1)); /* t */
    goto v79;

v215:
    v286 = qvalue(elt(env, 1)); /* t */
    goto v230;
/* error exit handlers */
v292:
    popv(7);
    return nil;
}



/* Code for ofsf_multsurep */

static Lisp_Object CC_ofsf_multsurep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129, v70, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_multsurep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v1;
    v71 = v0;
/* end of prologue */
    v128 = v71;
    v129 = qcar(v128);
    v128 = elt(env, 1); /* equal */
    if (v129 == v128) goto v312;
    v128 = v71;
    v129 = v70;
    {
        fn = elt(env, 2); /* ofsf_multsurep!-neq */
        return (*qfn2(fn))(qenv(fn), v128, v129);
    }

v312:
    v128 = v71;
    v129 = v70;
    {
        fn = elt(env, 3); /* ofsf_multsurep!-equal */
        return (*qfn2(fn))(qenv(fn), v128, v129);
    }
}



/* Code for ldt!-dep */

static Lisp_Object CC_ldtKdep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldt-dep");
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
    v118 = v0;
/* end of prologue */
    fn = elt(env, 3); /* ldt!-tvar */
    v119 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[0];
    v118 = qvalue(elt(env, 1)); /* depl!* */
    v118 = Lassoc(nil, v119, v118);
    v119 = v118;
    v118 = v119;
    if (v118 == nil) goto v230;
    v118 = v119;
    v118 = qcdr(v118);
    { popv(1); return onevalue(v118); }

v230:
    v118 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v118); }
/* error exit handlers */
v185:
    popv(1);
    return nil;
}



/* Code for findhc */

static Lisp_Object CC_findhc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v316;
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
    v90 = v0;
/* end of prologue */
    stack[-4] = nil;
    v316 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v316; /* njsi */
    stack[-2] = v316;
    v316 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v316; /* jsi */
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v316 = qvalue(elt(env, 5)); /* maxvar */
    v90 = plus2(v316, v90);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    v316 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v90/(16/CELL)));
    v90 = (Lisp_Object)65; /* 4 */
    v90 = *(Lisp_Object *)((char *)v316 + (CELL-TAG_VECTOR) + ((int32_t)v90/(16/CELL)));
    stack[-1] = v90;
    goto v121;

v121:
    v90 = stack[-1];
    if (v90 == nil) goto v120;
    v90 = stack[-1];
    v90 = qcar(v90);
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v316 = qvalue(elt(env, 5)); /* maxvar */
    v90 = qcar(v90);
    stack[-3] = v90;
    v90 = plus2(v316, v90);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    v316 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v90/(16/CELL)));
    v90 = (Lisp_Object)1; /* 0 */
    v90 = *(Lisp_Object *)((char *)v316 + (CELL-TAG_VECTOR) + ((int32_t)v90/(16/CELL)));
    if (v90 == nil) goto v317;
    v316 = stack[-3];
    v90 = qvalue(elt(env, 3)); /* jsi */
    v90 = cons(v316, v90);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    qvalue(elt(env, 3)) = v90; /* jsi */
    v90 = qvalue(elt(env, 1)); /* njsi */
    v90 = add1(v90);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    qvalue(elt(env, 1)) = v90; /* njsi */
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v316 = qvalue(elt(env, 5)); /* maxvar */
    v90 = stack[-3];
    v90 = plus2(v316, v90);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    v316 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v90/(16/CELL)));
    v90 = (Lisp_Object)17; /* 1 */
    v90 = *(Lisp_Object *)((char *)v316 + (CELL-TAG_VECTOR) + ((int32_t)v90/(16/CELL)));
    v90 = qcar(v90);
    v316 = qcar(v90);
    stack[0] = v316;
    v90 = stack[-2];
    v90 = (Lisp_Object)greaterp2(v316, v90);
    nil = C_nil;
    if (exception_pending()) goto v228;
    v90 = v90 ? lisp_true : nil;
    env = stack[-5];
    if (v90 == nil) goto v317;
    v90 = stack[0];
    stack[-2] = v90;
    v90 = stack[-3];
    stack[-4] = v90;
    goto v317;

v317:
    v90 = stack[-1];
    v90 = qcdr(v90);
    stack[-1] = v90;
    goto v121;

v120:
    v90 = qvalue(elt(env, 3)); /* jsi */
    v90 = Lreverse(nil, v90);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    qvalue(elt(env, 3)) = v90; /* jsi */
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v228:
    popv(6);
    return nil;
}



/* Code for gvarlis */

static Lisp_Object CC_gvarlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gvarlis");
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
    v229 = v0;
/* end of prologue */
    v78 = v229;
    v229 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* gvarlis1 */
    v78 = (*qfn2(fn))(qenv(fn), v78, v229);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[0];
    v229 = elt(env, 2); /* ordop */
    {
        popv(1);
        fn = elt(env, 4); /* sort */
        return (*qfn2(fn))(qenv(fn), v78, v229);
    }
/* error exit handlers */
v230:
    popv(1);
    return nil;
}



/* Code for expt!-separate */

static Lisp_Object CC_exptKseparate(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v243, v291, v314;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expt-separate");
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
    v291 = stack[-1];
    v243 = elt(env, 1); /* expt */
    if (!consp(v291)) goto v146;
    v291 = qcar(v291);
    if (!(v291 == v243)) goto v146;
    v243 = stack[-1];
    v243 = qcdr(v243);
    v291 = qcar(v243);
    v243 = stack[0];
    fn = elt(env, 5); /* depends */
    v243 = (*qfn2(fn))(qenv(fn), v291, v243);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    if (!(v243 == nil)) goto v178;
    v243 = stack[-1];
    v243 = qcdr(v243);
    v243 = qcdr(v243);
    v291 = qcar(v243);
    v243 = elt(env, 3); /* plus */
    v243 = Leqcar(nil, v291, v243);
    env = stack[-2];
    v243 = (v243 == nil ? lisp_true : nil);
    goto v178;

v178:
    if (v243 == nil) goto v237;
    v243 = qvalue(elt(env, 4)); /* nil */
    { popv(3); return onevalue(v243); }

v237:
    v243 = stack[-1];
    v243 = qcdr(v243);
    v243 = qcdr(v243);
    v243 = qcar(v243);
    v314 = qcdr(v243);
    v243 = stack[-1];
    v243 = qcdr(v243);
    v291 = qcar(v243);
    v243 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* expt!-separate1 */
        return (*qfnn(fn))(qenv(fn), 3, v314, v291, v243);
    }

v146:
    v243 = qvalue(elt(env, 2)); /* t */
    goto v178;
/* error exit handlers */
v319:
    popv(3);
    return nil;
}



/* Code for atlas_edges */

static Lisp_Object CC_atlas_edges(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for atlas_edges");
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
    v73 = stack[0];
    v73 = qcar(v73);
    fn = elt(env, 1); /* map__edges */
    stack[-1] = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    v73 = stack[0];
    v73 = qcdr(v73);
    v73 = qcdr(v73);
    v73 = qcar(v73);
    fn = elt(env, 2); /* den__edges */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    fn = elt(env, 3); /* union_edges */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v73);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    v73 = stack[0];
    v73 = qcdr(v73);
    v73 = qcar(v73);
    fn = elt(env, 4); /* coeff_edges */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    {
        Lisp_Object v126 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* union_edges */
        return (*qfn2(fn))(qenv(fn), v126, v73);
    }
/* error exit handlers */
v125:
    popv(3);
    return nil;
}



/* Code for subeval1 */

static Lisp_Object CC_subeval1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v16, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subeval1");
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

v146:
    v60 = stack[-1];
    if (v60 == nil) goto v178;
    v60 = stack[-1];
    v60 = qcar(v60);
    v16 = qcar(v60);
    v60 = stack[-1];
    v60 = qcar(v60);
    v60 = qcdr(v60);
    if (!(equal(v16, v60))) goto v178;
    v60 = stack[-1];
    v60 = qcdr(v60);
    stack[-1] = v60;
    goto v146;

v178:
    v60 = stack[-1];
    if (v60 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v60 = stack[0];
    fn = elt(env, 8); /* getrtype */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v10 = v60;
    if (v60 == nil) goto v189;
    v16 = v10;
    v60 = elt(env, 2); /* subfn */
    v60 = get(v16, v60);
    env = stack[-2];
    v16 = v60;
    if (v60 == nil) goto v243;
    v10 = v16;
    v16 = stack[-1];
    v60 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v10, v16, v60);

v243:
    v60 = elt(env, 3); /* "No substitution defined for type" */
    v16 = v10;
    v60 = list2(v60, v16);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v16 = v60;
    v60 = v16;
    qvalue(elt(env, 4)) = v60; /* errmsg!* */
    v60 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v60 == nil)) goto v123;
    v60 = v16;
    fn = elt(env, 9); /* lprie */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    goto v123;

v123:
    v60 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    goto v189;

v189:
    v60 = stack[0];
    fn = elt(env, 10); /* simp */
    v16 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v60 = stack[-1];
    fn = elt(env, 11); /* subsq */
    v60 = (*qfn2(fn))(qenv(fn), v16, v60);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    stack[-1] = v60;
    v60 = qvalue(elt(env, 6)); /* t */
    stack[0] = qvalue(elt(env, 7)); /* !*sub2 */
    qvalue(elt(env, 7)) = v60; /* !*sub2 */
    v60 = stack[-1];
    fn = elt(env, 12); /* subs2 */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-2];
    stack[-1] = v60;
    qvalue(elt(env, 7)) = stack[0]; /* !*sub2 */
    v60 = stack[-1];
    {
        popv(3);
        fn = elt(env, 13); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v60);
    }
/* error exit handlers */
v172:
    env = stack[-2];
    qvalue(elt(env, 7)) = stack[0]; /* !*sub2 */
    popv(3);
    return nil;
v28:
    popv(3);
    return nil;
}



/* Code for mv2sf */

static Lisp_Object CC_mv2sf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv2sf");
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
    goto v241;

v241:
    v67 = stack[-1];
    if (v67 == nil) goto v178;
    v67 = stack[-1];
    v67 = qcar(v67);
    v202 = qcar(v67);
    v67 = stack[-1];
    v67 = qcar(v67);
    v68 = qcdr(v67);
    v67 = stack[0];
    fn = elt(env, 2); /* mv2sf1 */
    v68 = (*qfnn(fn))(qenv(fn), 3, v202, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    v67 = stack[-2];
    v67 = cons(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    stack[-2] = v67;
    v67 = stack[-1];
    v67 = qcdr(v67);
    stack[-1] = v67;
    goto v241;

v178:
    v67 = qvalue(elt(env, 1)); /* nil */
    v68 = v67;
    goto v146;

v146:
    v67 = stack[-2];
    if (v67 == nil) { popv(4); return onevalue(v68); }
    v67 = stack[-2];
    v67 = qcar(v67);
    fn = elt(env, 3); /* addf */
    v67 = (*qfn2(fn))(qenv(fn), v67, v68);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    v68 = v67;
    v67 = stack[-2];
    v67 = qcdr(v67);
    stack[-2] = v67;
    goto v146;
/* error exit handlers */
v82:
    popv(4);
    return nil;
}



/* Code for tensor_has_dummy_idx */

static Lisp_Object CC_tensor_has_dummy_idx(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v322, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tensor_has_dummy_idx");
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

v77:
    v322 = stack[-1];
    if (v322 == nil) goto v178;
    v322 = stack[-1];
    v125 = qcar(v322);
    v322 = stack[0];
    fn = elt(env, 3); /* smember */
    v322 = (*qfn2(fn))(qenv(fn), v125, v322);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    if (v322 == nil) goto v185;
    v322 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v322); }

v185:
    v322 = stack[-1];
    v322 = qcdr(v322);
    stack[-1] = v322;
    goto v77;

v178:
    v322 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v322); }
/* error exit handlers */
v116:
    popv(3);
    return nil;
}



/* Code for lowestdeg */

static Lisp_Object MS_CDECL CC_lowestdeg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v130, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v323;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "lowestdeg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lowestdeg");
#endif
    if (stack >= stacklimit)
    {
        push3(v130,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v130);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v197 = v130;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v241:
    v323 = stack[-1];
    if (v323 == nil) { popv(3); return onevalue(v197); }
    v197 = stack[-1];
    if (!consp(v197)) goto v118;
    v197 = stack[-1];
    v197 = qcar(v197);
    v197 = (consp(v197) ? nil : lisp_true);
    goto v198;

v198:
    if (v197 == nil) goto v70;
    v197 = qvalue(elt(env, 1)); /* t */
    goto v229;

v229:
    if (v197 == nil) goto v317;
    v197 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v197); }

v317:
    v197 = stack[-1];
    v197 = qcdr(v197);
    v323 = v197;
    v197 = stack[-1];
    v197 = qcar(v197);
    v197 = qcar(v197);
    v197 = qcdr(v197);
    stack[-1] = v323;
    goto v241;

v70:
    v197 = stack[-1];
    v197 = qcar(v197);
    v197 = qcar(v197);
    v323 = qcar(v197);
    v197 = stack[0];
    v197 = Lneq(nil, v323, v197);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-2];
    goto v229;

v118:
    v197 = qvalue(elt(env, 1)); /* t */
    goto v198;
/* error exit handlers */
v202:
    popv(3);
    return nil;
}



/* Code for vp1 */

static Lisp_Object MS_CDECL CC_vp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v130, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v83, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vp1");
#endif
    if (stack >= stacklimit)
    {
        push3(v130,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v130);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v130;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v82 = nil;
    goto v241;

v241:
    v66 = stack[0];
    if (v66 == nil) goto v127;
    v83 = stack[-2];
    v66 = stack[0];
    v66 = qcar(v66);
    if (equal(v83, v66)) goto v128;
    v66 = (Lisp_Object)1; /* 0 */
    v83 = v82;
    v66 = cons(v66, v83);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-3];
    v82 = v66;
    v66 = stack[0];
    v66 = qcdr(v66);
    stack[0] = v66;
    goto v241;

v128:
    stack[-2] = v82;
    v66 = stack[0];
    v66 = qcdr(v66);
    fn = elt(env, 2); /* vp2 */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-3];
    v66 = cons(stack[-1], v66);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-3];
    {
        Lisp_Object v291 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v291, v66);
    }

v127:
    stack[0] = v82;
    v66 = elt(env, 1); /* "Var not in z-list after all" */
    fn = elt(env, 4); /* interr */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-3];
    {
        Lisp_Object v314 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v314, v66);
    }
/* error exit handlers */
v243:
    popv(4);
    return nil;
}



/* Code for available!*p */

static Lisp_Object CC_availableHp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v322;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for available*p");
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
    v199 = stack[0];
    if (symbolp(v199)) goto v215;
    v199 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v199 == nil)) goto v120;
    v199 = elt(env, 2); /* "this is no group identifier" */
    fn = elt(env, 4); /* lprie */
    v199 = (*qfn1(fn))(qenv(fn), v199);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-1];
    goto v120;

v120:
    v199 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-1];
    goto v215;

v215:
    v199 = stack[0];
    v322 = elt(env, 3); /* available */
        popv(2);
        return Lflagp(nil, v199, v322);
/* error exit handlers */
v126:
    popv(2);
    return nil;
}



/* Code for pasf_mkop */

static Lisp_Object CC_pasf_mkop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v318, v317, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_mkop");
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
    v317 = v1;
    v114 = v0;
/* end of prologue */
    v318 = v114;
    v242 = elt(env, 1); /* (cong ncong) */
    v242 = Lmemq(nil, v318, v242);
    if (v242 == nil) { popv(2); return onevalue(v114); }
    stack[0] = v114;
    v242 = v317;
    if (v242 == nil) goto v185;
    v242 = v317;
    goto v230;

v230:
    {
        Lisp_Object v113 = stack[0];
        popv(2);
        return cons(v113, v242);
    }

v185:
    v242 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v242 == nil)) goto v126;
    v242 = elt(env, 3); /* "Modulo 0 congruence created" */
    v242 = ncons(v242);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-1];
    fn = elt(env, 4); /* lprie */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-1];
    goto v126;

v126:
    v242 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    v242 = nil;
    goto v230;
/* error exit handlers */
v111:
    popv(2);
    return nil;
}



/* Code for cgp_cp */

static Lisp_Object CC_cgp_cp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_cp");
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
    v185 = stack[-3];
    fn = elt(env, 1); /* cgp_hp */
    stack[-4] = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v185 = stack[-3];
    fn = elt(env, 2); /* cgp_rp */
    stack[-2] = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v185 = stack[-3];
    fn = elt(env, 3); /* cgp_sugar */
    stack[-1] = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v185 = stack[-3];
    fn = elt(env, 4); /* cgp_number */
    stack[0] = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v185 = stack[-3];
    fn = elt(env, 5); /* cgp_ci */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    {
        Lisp_Object v117 = stack[-4];
        Lisp_Object v116 = stack[-2];
        Lisp_Object v128 = stack[-1];
        Lisp_Object v129 = stack[0];
        popv(6);
        fn = elt(env, 6); /* cgp_mk */
        return (*qfnn(fn))(qenv(fn), 5, v117, v116, v128, v129, v185);
    }
/* error exit handlers */
v126:
    popv(6);
    return nil;
}



/* Code for search4facf */

static Lisp_Object MS_CDECL CC_search4facf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v130, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "search4facf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for search4facf");
#endif
    if (stack >= stacklimit)
    {
        push3(v130,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v130);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v130;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v184 = stack[-3];
    if (v184 == nil) goto v163;
    v184 = stack[-3];
    v184 = qcar(v184);
    stack[-5] = v184;
    goto v119;

v119:
    v184 = stack[-5];
    if (v184 == nil) goto v322;
    stack[-1] = stack[-4];
    v184 = stack[-3];
    stack[0] = qcdr(v184);
    v184 = stack[-5];
    v66 = qcar(v184);
    v184 = stack[-2];
    v184 = cons(v66, v184);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-6];
    v184 = CC_search4facf(env, 3, stack[-1], stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-6];
    v66 = v184;
    v184 = v66;
    if (!(v184 == nil)) { popv(7); return onevalue(v66); }
    v184 = stack[-5];
    v184 = qcdr(v184);
    stack[-5] = v184;
    goto v119;

v322:
    v184 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v184); }

v163:
    v66 = stack[-4];
    v184 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* tryfactorf */
        return (*qfn2(fn))(qenv(fn), v66, v184);
    }
/* error exit handlers */
v291:
    popv(7);
    return nil;
}



/* Code for powmtch */

static Lisp_Object MS_CDECL CC_powmtch(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v130, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v232, v123, v124, v235;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powmtch");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powmtch");
#endif
    if (stack >= stacklimit)
    {
        push3(v130,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v130);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v231 = v130;
    v232 = v1;
    v123 = v0;
/* end of prologue */

v324:
    v124 = v232;
    if (v124 == nil) goto v145;
    v235 = v123;
    v124 = v232;
    v124 = qcar(v124);
    v124 = Latsoc(nil, v235, v124);
    v235 = v124;
    v124 = v235;
    if (v124 == nil) goto v322;
    v124 = v235;
    v235 = qcdr(v124);
    v124 = v231;
    v124 = (equal(v235, v124) ? lisp_true : nil);
    goto v199;

v199:
    if (v124 == nil) goto v291;
    v124 = v232;
    stack[0] = qcar(v124);
    v232 = qcdr(v232);
    v231 = CC_powmtch(env, 3, v123, v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v182;
    {
        Lisp_Object v84 = stack[0];
        popv(1);
        return cons(v84, v231);
    }

v291:
    v232 = qcdr(v232);
    goto v324;

v322:
    v124 = qvalue(elt(env, 2)); /* t */
    goto v199;

v145:
    v231 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v231); }
/* error exit handlers */
v182:
    popv(1);
    return nil;
}



/* Code for simp!:ps!: */

static Lisp_Object CC_simpTpsT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp:ps:");
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
    v107 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!:ps1 */
    v120 = (*qfn1(fn))(qenv(fn), v107);
    errexit();
    v107 = (Lisp_Object)17; /* 1 */
    return cons(v120, v107);
}



/* Code for dipcontevmin */

static Lisp_Object CC_dipcontevmin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v319, v110;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcontevmin");
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
    v110 = nil;
    goto v178;

v178:
    v109 = stack[-1];
    if (v109 == nil) goto v111;
    v109 = stack[0];
    if (v109 == nil) goto v111;
    v109 = stack[-1];
    v319 = qcar(v109);
    v109 = stack[0];
    v109 = qcar(v109);
    if (((int32_t)(v319)) < ((int32_t)(v109))) goto v73;
    v109 = stack[0];
    v109 = qcar(v109);
    goto v198;

v198:
    v319 = v110;
    v109 = cons(v109, v319);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-2];
    v110 = v109;
    v109 = stack[-1];
    v109 = qcdr(v109);
    stack[-1] = v109;
    v109 = stack[0];
    v109 = qcdr(v109);
    stack[0] = v109;
    goto v178;

v73:
    v109 = stack[-1];
    v109 = qcar(v109);
    goto v198;

v111:
    v109 = v110;
    if (v109 == nil) goto v113;
    v319 = (Lisp_Object)1; /* 0 */
    v109 = v110;
    v109 = qcar(v109);
    if (!(v319 == v109)) goto v113;
    v109 = v110;
    v109 = qcdr(v109);
    v110 = v109;
    goto v111;

v113:
    v109 = v110;
        popv(3);
        return Lnreverse(nil, v109);
/* error exit handlers */
v181:
    popv(3);
    return nil;
}



/* Code for groebsimpcontnormalform */

static Lisp_Object CC_groebsimpcontnormalform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsimpcontnormalform");
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
    v123 = stack[-2];
    if (v123 == nil) goto v178;
    v123 = stack[-2];
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    v123 = qcar(v123);
    v123 = (v123 == nil ? lisp_true : nil);
    goto v241;

v241:
    if (!(v123 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v123 = stack[-2];
    fn = elt(env, 4); /* gsugar */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    stack[0] = v123;
    v123 = stack[-2];
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    v123 = qcar(v123);
    stack[-3] = v123;
    v123 = stack[-2];
    fn = elt(env, 5); /* vdpsimpcont */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    stack[-2] = v123;
    v124 = stack[-2];
    v123 = stack[0];
    fn = elt(env, 6); /* gsetsugar */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v123 = qvalue(elt(env, 2)); /* !*groebprot */
    if (v123 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v124 = stack[-3];
    v123 = stack[-2];
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    v123 = qcar(v123);
    if (equal(v124, v123)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-1] = elt(env, 3); /* quotient */
    v123 = stack[-2];
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    v123 = qcar(v123);
    fn = elt(env, 7); /* vbc2a */
    stack[0] = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v123 = stack[-3];
    fn = elt(env, 7); /* vbc2a */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v123 = list3(stack[-1], stack[0], v123);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    fn = elt(env, 8); /* reval */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    fn = elt(env, 9); /* groebreductionprotocol2 */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v180;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v178:
    v123 = qvalue(elt(env, 1)); /* t */
    goto v241;
/* error exit handlers */
v180:
    popv(5);
    return nil;
}



/* Code for let3 */

static Lisp_Object MS_CDECL CC_let3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v130, Lisp_Object v131,
                         Lisp_Object v132, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v334, v36, v37, v153, v207, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "let3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for let3");
#endif
    if (stack >= stacklimit)
    {
        push5(v132,v131,v130,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v130,v131,v132);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v132;
    stack[-2] = v131;
    stack[-3] = v130;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v334 = stack[-5];
    stack[-6] = v334;
    v334 = stack[-6];
    if (v334 == nil) goto v290;
    v334 = stack[-6];
    if (is_number(v334)) goto v69;
    v334 = stack[-4];
    fn = elt(env, 9); /* getrtype */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    stack[0] = v334;
    v334 = stack[-2];
    if (v334 == nil) goto v202;
    v334 = stack[-6];
    if (!(symbolp(v334))) goto v202;
    v36 = stack[-6];
    v334 = elt(env, 5); /* rtype */
    v334 = Lremprop(nil, v36, v334);
    env = stack[-7];
    v36 = stack[-6];
    v334 = elt(env, 6); /* avalue */
    v334 = Lremprop(nil, v36, v334);
    env = stack[-7];
    goto v202;

v202:
    v334 = stack[-6];
    fn = elt(env, 9); /* getrtype */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v37 = v334;
    if (v334 == nil) goto v180;
    v36 = v37;
    v334 = elt(env, 7); /* typeletfn */
    v334 = get(v36, v334);
    env = stack[-7];
    v36 = v334;
    if (v334 == nil) goto v62;
    stack[-3] = v36;
    stack[-5] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v37;
    v334 = stack[-4];
    fn = elt(env, 9); /* getrtype */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v334 = list2(stack[-2], v334);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v334 = list3star(stack[-5], stack[-1], stack[0], v334);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    {
        Lisp_Object v293 = stack[-3];
        popv(8);
        fn = elt(env, 10); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v293, v334);
    }

v62:
    stack[-3] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v37;
    v334 = stack[-4];
    fn = elt(env, 9); /* getrtype */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    {
        Lisp_Object v34 = stack[-3];
        Lisp_Object v35 = stack[-1];
        Lisp_Object v335 = stack[0];
        Lisp_Object v336 = stack[-2];
        popv(8);
        fn = elt(env, 11); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v34, v35, v335, v336, v334);
    }

v180:
    v334 = stack[0];
    if (v334 == nil) goto v210;
    v36 = stack[0];
    v334 = elt(env, 8); /* yetunknowntype */
    if (v36 == v334) goto v210;
    v36 = stack[0];
    v334 = elt(env, 7); /* typeletfn */
    v334 = get(v36, v334);
    env = stack[-7];
    v36 = v334;
    if (v334 == nil) goto v158;
    stack[-3] = v36;
    stack[-5] = stack[-6];
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    v36 = stack[-2];
    v334 = stack[0];
    v334 = list2(v36, v334);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    v334 = list3star(stack[-5], stack[-4], stack[-1], v334);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-7];
    {
        Lisp_Object v208 = stack[-3];
        popv(8);
        fn = elt(env, 10); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v208, v334);
    }

v158:
    v207 = stack[-6];
    v153 = stack[-4];
    v37 = qvalue(elt(env, 3)); /* nil */
    v36 = stack[-2];
    v334 = stack[0];
    {
        popv(8);
        fn = elt(env, 11); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v207, v153, v37, v36, v334);
    }

v210:
    v33 = stack[-5];
    v207 = stack[-4];
    v153 = stack[-3];
    v37 = stack[-6];
    v36 = stack[-2];
    v334 = stack[-1];
    fn = elt(env, 12); /* letscalar */
    v334 = (*qfnn(fn))(qenv(fn), 6, v33, v207, v153, v37, v36, v334);
    nil = C_nil;
    if (exception_pending()) goto v273;
    v334 = nil;
    { popv(8); return onevalue(v334); }

v69:
    v207 = elt(env, 1); /* "Substitution for" */
    v153 = stack[-5];
    v37 = elt(env, 2); /* "not allowed" */
    v36 = qvalue(elt(env, 3)); /* nil */
    v334 = qvalue(elt(env, 4)); /* t */
    {
        popv(8);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v207, v153, v37, v36, v334);
    }

v290:
    v334 = (Lisp_Object)1; /* 0 */
    stack[-5] = v334;
    v207 = elt(env, 1); /* "Substitution for" */
    v153 = stack[-5];
    v37 = elt(env, 2); /* "not allowed" */
    v36 = qvalue(elt(env, 3)); /* nil */
    v334 = qvalue(elt(env, 4)); /* t */
    {
        popv(8);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v207, v153, v37, v36, v334);
    }
/* error exit handlers */
v273:
    popv(8);
    return nil;
}



/* Code for exptbf */

static Lisp_Object MS_CDECL CC_exptbf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v130, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "exptbf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptbf");
#endif
    if (stack >= stacklimit)
    {
        push3(v130,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v130);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v130;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v145:
    v113 = stack[-1];
    v113 = Levenp(nil, v113);
    env = stack[-3];
    if (!(v113 == nil)) goto v118;
    v111 = stack[0];
    v113 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v113 = (*qfn2(fn))(qenv(fn), v111, v113);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    stack[0] = v113;
    goto v118;

v118:
    v111 = stack[-1];
    v113 = (Lisp_Object)-15; /* -1 */
    v113 = ash(v111, v113);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    stack[-1] = v113;
    v111 = stack[-1];
    v113 = (Lisp_Object)1; /* 0 */
    if (v111 == v113) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v111 = stack[-2];
    v113 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v113 = (*qfn2(fn))(qenv(fn), v111, v113);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    stack[-2] = v113;
    goto v145;
/* error exit handlers */
v183:
    popv(4);
    return nil;
}



/* Code for rlval */

static Lisp_Object CC_rlval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v98, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rlval");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v1;
    v98 = v0;
/* end of prologue */
    v29 = v98;
    if (!consp(v29)) goto v146;
    v29 = v98;
    v29 = qcar(v29);
    v29 = (consp(v29) ? nil : lisp_true);
    goto v178;

v178:
    if (!(v29 == nil)) { popv(8); return onevalue(v98); }
    v29 = stack[-5];
    if (!consp(v29)) goto v119;
    v29 = stack[-5];
    v29 = qcdr(v29);
    v97 = qcar(v29);
    v29 = (Lisp_Object)1; /* 0 */
    v29 = (v97 == v29 ? lisp_true : nil);
    goto v118;

v118:
    if (v29 == nil) goto v109;
    v29 = v98;
    v29 = qcar(v29);
    v97 = qcar(v29);
    v29 = (Lisp_Object)1; /* 0 */
    if (v97 == v29) goto v79;
    v29 = (Lisp_Object)1; /* 0 */
    {
        popv(8);
        fn = elt(env, 5); /* r2flbf */
        return (*qfn1(fn))(qenv(fn), v29);
    }

v79:
    v29 = v98;
    v29 = qcar(v29);
    v29 = qcdr(v29);
    { popv(8); return onevalue(v29); }

v109:
    v97 = stack[-5];
    v29 = elt(env, 2); /* !:rd!: */
    if (!consp(v97)) goto v87;
    v97 = qcar(v97);
    if (!(v97 == v29)) goto v87;
    v29 = stack[-5];
    v29 = qcdr(v29);
    v29 = (consp(v29) ? nil : lisp_true);
    v29 = (v29 == nil ? lisp_true : nil);
    goto v243;

v243:
    stack[-4] = v29;
    v29 = v98;
    fn = elt(env, 6); /* ncoeffs */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-7];
    v29 = qcdr(v29);
    v98 = v29;
    v29 = qcar(v29);
    stack[-6] = v29;
    v29 = v98;
    v29 = qcdr(v29);
    stack[-3] = v29;
    goto v64;

v64:
    v29 = stack[-3];
    if (v29 == nil) goto v233;
    v29 = stack[-3];
    v29 = qcar(v29);
    stack[-2] = v29;
    v29 = stack[-4];
    if (v29 == nil) goto v331;
    stack[-1] = elt(env, 2); /* !:rd!: */
    v29 = stack[-5];
    v29 = qcdr(v29);
    v98 = qcar(v29);
    v29 = stack[-6];
    v29 = qcdr(v29);
    v29 = qcar(v29);
    stack[0] = times2(v98, v29);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-7];
    v29 = stack[-5];
    v29 = qcdr(v29);
    v98 = qcdr(v29);
    v29 = stack[-6];
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = plus2(v98, v29);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-7];
    v29 = list2star(stack[-1], stack[0], v29);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-7];
    goto v12;

v12:
    stack[-6] = v29;
    v29 = stack[-2];
    if (v29 == nil) goto v165;
    v29 = stack[-4];
    if (v29 == nil) goto v342;
    v98 = stack[-2];
    v29 = stack[-6];
    fn = elt(env, 7); /* plus!: */
    v29 = (*qfn2(fn))(qenv(fn), v98, v29);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-7];
    goto v220;

v220:
    stack[-6] = v29;
    goto v165;

v165:
    v29 = stack[-3];
    v29 = qcdr(v29);
    stack[-3] = v29;
    goto v64;

v342:
    v98 = stack[-6];
    v29 = stack[-2];
    v29 = plus2(v98, v29);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-7];
    goto v220;

v331:
    v98 = stack[-5];
    v29 = stack[-6];
    v29 = times2(v98, v29);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-7];
    goto v12;

v233:
    v29 = stack[-4];
    if (v29 == nil) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v29 = stack[-6];
    v29 = qcdr(v29);
    v29 = qcar(v29);
    v97 = v29;
    v98 = v97;
    v29 = (Lisp_Object)1; /* 0 */
    if (v98 == v29) goto v214;
    v98 = v97;
    v29 = qvalue(elt(env, 4)); /* !:bprec!: */
    fn = elt(env, 8); /* inorm */
    v29 = (*qfn2(fn))(qenv(fn), v98, v29);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-7];
    v97 = v29;
    stack[-1] = elt(env, 2); /* !:rd!: */
    v29 = v97;
    stack[0] = qcar(v29);
    v29 = v97;
    v98 = qcdr(v29);
    v29 = stack[-6];
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = plus2(v98, v29);
    nil = C_nil;
    if (exception_pending()) goto v35;
    {
        Lisp_Object v335 = stack[-1];
        Lisp_Object v336 = stack[0];
        popv(8);
        return list2star(v335, v336, v29);
    }

v214:
    v97 = elt(env, 2); /* !:rd!: */
    v98 = (Lisp_Object)1; /* 0 */
    v29 = (Lisp_Object)1; /* 0 */
    popv(8);
    return list2star(v97, v98, v29);

v87:
    v29 = qvalue(elt(env, 3)); /* nil */
    goto v243;

v119:
    v29 = stack[-5];
    v29 = (Lisp_Object)zerop(v29);
    v29 = v29 ? lisp_true : nil;
    env = stack[-7];
    goto v118;

v146:
    v29 = qvalue(elt(env, 1)); /* t */
    goto v178;
/* error exit handlers */
v35:
    popv(8);
    return nil;
}



/* Code for deg */

static Lisp_Object CC_deg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg");
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
    v185 = qvalue(elt(env, 1)); /* gdmode!* */
    stack[-2] = qvalue(elt(env, 2)); /* dmode!* */
    qvalue(elt(env, 2)) = v185; /* dmode!* */
    v185 = stack[-1];
    fn = elt(env, 3); /* simp!* */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    stack[-1] = v185;
    v72 = stack[-1];
    v185 = stack[0];
    fn = elt(env, 4); /* tstpolyarg2 */
    v185 = (*qfn2(fn))(qenv(fn), v72, v185);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v185 = stack[-1];
    v72 = qcar(v185);
    v185 = stack[0];
    fn = elt(env, 5); /* numrdeg */
    v185 = (*qfn2(fn))(qenv(fn), v72, v185);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v185); }
/* error exit handlers */
v125:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for constructinvolutivebasis */

static Lisp_Object CC_constructinvolutivebasis(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v346, v347, v348;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constructinvolutivebasis");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v1;
    stack[0] = v0;
/* end of prologue */
    v347 = stack[0];
    v346 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 6); /* polynomlistautoreduce */
    v346 = (*qfn2(fn))(qenv(fn), v347, v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[0] = v346;
    goto v198;

v198:
    v346 = stack[0];
    v346 = qcar(v346);
    if (v346 == nil) goto v242;
    stack[-1] = qvalue(elt(env, 3)); /* fluidbibasissetq */
    v346 = stack[0];
    v346 = qcar(v346);
    fn = elt(env, 7); /* createtriple */
    v346 = (*qfn1(fn))(qenv(fn), v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    fn = elt(env, 8); /* sortedtriplelistinsert */
    v346 = (*qfn2(fn))(qenv(fn), stack[-1], v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v346 = stack[0];
    v346 = qcdr(v346);
    stack[0] = v346;
    goto v198;

v242:
    v346 = qvalue(elt(env, 3)); /* fluidbibasissetq */
    v346 = qcar(v346);
    if (v346 == nil) goto v311;
    fn = elt(env, 9); /* setqget */
    v346 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[-6] = v346;
    v347 = stack[-6];
    v346 = (Lisp_Object)17; /* 1 */
    v346 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v346/(16/CELL)));
    v346 = qcar(v346);
    stack[-4] = v346;
    v347 = stack[-6];
    v346 = (Lisp_Object)17; /* 1 */
    v346 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v346/(16/CELL)));
    fn = elt(env, 10); /* normalform */
    v346 = (*qfn1(fn))(qenv(fn), v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[-3] = v346;
    v346 = stack[-3];
    v346 = qcar(v346);
    stack[-2] = v346;
    v346 = stack[-2];
    if (v346 == nil) goto v242;
    v346 = qvalue(elt(env, 4)); /* fluidbibasisnonzeronormalforms */
    v346 = (Lisp_Object)((int32_t)(v346) + 0x10);
    qvalue(elt(env, 4)) = v346; /* fluidbibasisnonzeronormalforms */
    v346 = qvalue(elt(env, 2)); /* nil */
    v346 = ncons(v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[0] = v346;
    v346 = qvalue(elt(env, 5)); /* fluidbibasissett */
    stack[-1] = v346;
    goto v180;

v180:
    v346 = stack[-1];
    v346 = qcar(v346);
    if (v346 == nil) goto v190;
    v346 = stack[-1];
    v347 = qcar(v346);
    v346 = (Lisp_Object)17; /* 1 */
    v346 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v346/(16/CELL)));
    v347 = qcar(v346);
    v346 = stack[-2];
    fn = elt(env, 11); /* monomisdivisibleby */
    v346 = (*qfn2(fn))(qenv(fn), v347, v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    if (v346 == nil) goto v167;
    v346 = stack[-1];
    v347 = qcar(v346);
    v346 = (Lisp_Object)1; /* 0 */
    v346 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v346/(16/CELL)));
    fn = elt(env, 12); /* setqdeletedescendants */
    v346 = (*qfn1(fn))(qenv(fn), v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v347 = stack[0];
    v346 = stack[-1];
    v346 = qcar(v346);
    fn = elt(env, 8); /* sortedtriplelistinsert */
    v346 = (*qfn2(fn))(qenv(fn), v347, v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v346 = stack[-1];
    v347 = qcar(v346);
    v346 = (Lisp_Object)17; /* 1 */
    v346 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v346/(16/CELL)));
    v346 = qcar(v346);
    fn = elt(env, 13); /* janettreedelete */
    v346 = (*qfn1(fn))(qenv(fn), v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v347 = stack[-1];
    v346 = stack[-1];
    v346 = qcdr(v346);
    v346 = qcar(v346);
    v347 = Lrplaca(nil, v347, v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v346 = stack[-1];
    v346 = qcdr(v346);
    v346 = qcdr(v346);
    v346 = Lrplacd(nil, v347, v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    goto v180;

v167:
    v346 = stack[-1];
    v346 = qcdr(v346);
    stack[-1] = v346;
    goto v180;

v190:
    v347 = stack[-4];
    v346 = stack[-2];
    if (v347 == v346) goto v209;
    v346 = stack[-3];
    fn = elt(env, 7); /* createtriple */
    v346 = (*qfn1(fn))(qenv(fn), v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    fn = elt(env, 14); /* settinsert */
    v346 = (*qfn1(fn))(qenv(fn), v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    goto v169;

v169:
    v346 = stack[0];
    fn = elt(env, 15); /* settcollectnonmultiprolongations */
    v346 = (*qfn1(fn))(qenv(fn), v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v347 = stack[-2];
    v346 = (Lisp_Object)1; /* 0 */
    v347 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v346/(16/CELL)));
    v346 = (Lisp_Object)1; /* 0 */
    v346 = Leqn(nil, v347, v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    if (v346 == nil) goto v37;
    v346 = qvalue(elt(env, 2)); /* nil */
    v346 = ncons(v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    qvalue(elt(env, 3)) = v346; /* fluidbibasissetq */
    goto v242;

v37:
    v346 = stack[0];
    fn = elt(env, 16); /* setqinsertlist */
    v346 = (*qfn1(fn))(qenv(fn), v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    goto v242;

v209:
    v348 = stack[-3];
    v347 = stack[-6];
    v346 = (Lisp_Object)33; /* 2 */
    v346 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v346/(16/CELL)));
    fn = elt(env, 17); /* createtriplewithancestor */
    v346 = (*qfn2(fn))(qenv(fn), v348, v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    fn = elt(env, 14); /* settinsert */
    v346 = (*qfn1(fn))(qenv(fn), v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v346 = qvalue(elt(env, 5)); /* fluidbibasissett */
    v348 = qcar(v346);
    v347 = stack[-6];
    v346 = (Lisp_Object)49; /* 3 */
    v346 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v346/(16/CELL)));
    fn = elt(env, 18); /* triplesetprolongset */
    v346 = (*qfn2(fn))(qenv(fn), v348, v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    goto v169;

v311:
    v346 = qvalue(elt(env, 2)); /* nil */
    v346 = ncons(v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[0] = v346;
    v346 = qvalue(elt(env, 5)); /* fluidbibasissett */
    stack[-1] = v346;
    goto v293;

v293:
    v346 = stack[-1];
    v346 = qcar(v346);
    if (v346 == nil) goto v349;
    v348 = stack[0];
    v346 = stack[-1];
    v347 = qcar(v346);
    v346 = (Lisp_Object)17; /* 1 */
    v346 = *(Lisp_Object *)((char *)v347 + (CELL-TAG_VECTOR) + ((int32_t)v346/(16/CELL)));
    fn = elt(env, 19); /* sortedpolynomlistinsert */
    v346 = (*qfn2(fn))(qenv(fn), v348, v346);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v346 = stack[-1];
    v346 = qcdr(v346);
    stack[-1] = v346;
    goto v293;

v349:
    v347 = stack[0];
    v346 = stack[-5];
    {
        popv(8);
        fn = elt(env, 6); /* polynomlistautoreduce */
        return (*qfn2(fn))(qenv(fn), v347, v346);
    }
/* error exit handlers */
v205:
    popv(8);
    return nil;
}



/* Code for cl_pnf1 */

static Lisp_Object CC_cl_pnf1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pnf1");
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
    v81 = v0;
/* end of prologue */
    fn = elt(env, 2); /* cl_rename!-vars */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    fn = elt(env, 3); /* cl_pnf2 */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    stack[-1] = v81;
    v81 = stack[-1];
    v81 = qcdr(v81);
    if (v81 == nil) goto v120;
    v81 = stack[-1];
    v81 = qcar(v81);
    fn = elt(env, 4); /* cl_qb */
    stack[0] = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    v81 = stack[-1];
    v81 = qcdr(v81);
    v81 = qcar(v81);
    fn = elt(env, 4); /* cl_qb */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    v81 = (Lisp_Object)lessp2(stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v79;
    v81 = v81 ? lisp_true : nil;
    goto v107;

v107:
    if (v81 == nil) goto v129;
    v81 = stack[-1];
    v81 = qcar(v81);
    { popv(3); return onevalue(v81); }

v129:
    v81 = stack[-1];
    v81 = qcdr(v81);
    v81 = qcar(v81);
    { popv(3); return onevalue(v81); }

v120:
    v81 = qvalue(elt(env, 1)); /* t */
    goto v107;
/* error exit handlers */
v79:
    popv(3);
    return nil;
}



/* Code for ofsf_anegrel */

static Lisp_Object CC_ofsf_anegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v116, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_anegrel");
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
    v128 = v0;
/* end of prologue */
    v116 = v128;
    v117 = elt(env, 1); /* ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp)) 
*/
    v117 = Latsoc(nil, v116, v117);
    v117 = qcdr(v117);
    if (!(v117 == nil)) { popv(1); return onevalue(v117); }
    v117 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v117 == nil)) goto v229;
    v117 = elt(env, 3); /* "ofsf_anegrel: unknown operator " */
    v116 = v128;
    v117 = list2(v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[0];
    fn = elt(env, 4); /* lprie */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[0];
    goto v229;

v229:
    v117 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v129;
    v117 = nil;
    { popv(1); return onevalue(v117); }
/* error exit handlers */
v129:
    popv(1);
    return nil;
}



/* Code for gcdk */

static Lisp_Object CC_gcdk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v306, v361, v362;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdk");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-10] = nil;
    stack[-8] = nil;
    v361 = stack[0];
    v306 = stack[-9];
    if (equal(v361, v306)) { Lisp_Object res = stack[0]; popv(12); return onevalue(res); }
    v306 = stack[0];
    if (!consp(v306)) goto v126;
    v306 = stack[0];
    v306 = qcar(v306);
    v306 = (consp(v306) ? nil : lisp_true);
    goto v125;

v125:
    if (v306 == nil) goto v115;
    v306 = qvalue(elt(env, 1)); /* t */
    goto v72;

v72:
    if (v306 == nil) goto v112;
    v306 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v306); }

v112:
    v306 = stack[0];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v361 = qcdr(v306);
    v306 = stack[-9];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = qcdr(v306);
    v306 = (Lisp_Object)lessp2(v361, v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    v306 = v306 ? lisp_true : nil;
    env = stack[-11];
    if (v306 == nil) goto v180;
    v306 = stack[0];
    stack[-7] = v306;
    v306 = stack[-9];
    stack[0] = v306;
    v306 = stack[-7];
    stack[-9] = v306;
    goto v180;

v180:
    v361 = stack[0];
    v306 = stack[-9];
    fn = elt(env, 9); /* quotf1 */
    v306 = (*qfn2(fn))(qenv(fn), v361, v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    if (!(v306 == nil)) { Lisp_Object res = stack[-9]; popv(12); return onevalue(res); }
    v306 = qvalue(elt(env, 2)); /* !*heugcd */
    if (v306 == nil) goto v222;
    v361 = stack[0];
    v306 = stack[-9];
    fn = elt(env, 10); /* heu!-gcd */
    v306 = (*qfn2(fn))(qenv(fn), v361, v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    v361 = v306;
    if (!(v306 == nil)) { popv(12); return onevalue(v361); }

v222:
    v306 = stack[-9];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v361 = qcdr(v306);
    v306 = (Lisp_Object)17; /* 1 */
    if (v361 == v306) goto v192;
    v306 = elt(env, 3); /* modular!-multicheck */
    fn = elt(env, 11); /* getd */
    v306 = (*qfn1(fn))(qenv(fn), v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    if (v306 == nil) goto v228;
    v362 = stack[0];
    v361 = stack[-9];
    v306 = stack[-8];
    fn = elt(env, 3); /* modular!-multicheck */
    v306 = (*qfnn(fn))(qenv(fn), 3, v362, v361, v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    goto v174;

v174:
    if (!(v306 == nil)) goto v217;
    v306 = qvalue(elt(env, 5)); /* !*mcd */
    v306 = (v306 == nil ? lisp_true : nil);
    goto v217;

v217:
    if (v306 == nil) goto v165;
    v306 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v306); }

v165:
    v361 = stack[0];
    v306 = stack[-9];
    fn = elt(env, 12); /* remk */
    v306 = (*qfn2(fn))(qenv(fn), v361, v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    stack[-7] = v306;
    v306 = stack[-7];
    if (v306 == nil) { Lisp_Object res = stack[-9]; popv(12); return onevalue(res); }
    v361 = stack[-7];
    v306 = stack[-8];
    fn = elt(env, 13); /* degr */
    v361 = (*qfn2(fn))(qenv(fn), v361, v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    v306 = (Lisp_Object)1; /* 0 */
    if (v361 == v306) goto v364;
    v361 = stack[-9];
    v306 = stack[-10];
    fn = elt(env, 14); /* addlc */
    v306 = (*qfn2(fn))(qenv(fn), v361, v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    stack[-10] = v306;
    v361 = stack[-7];
    v306 = stack[-7];
    v306 = qcar(v306);
    v306 = qcdr(v306);
    fn = elt(env, 9); /* quotf1 */
    v306 = (*qfn2(fn))(qenv(fn), v361, v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    v361 = v306;
    if (v306 == nil) goto v213;
    v306 = v361;
    stack[-7] = v306;
    goto v154;

v154:
    v306 = stack[-9];
    stack[0] = v306;
    stack[-1] = stack[-7];
    v306 = stack[-7];
    fn = elt(env, 15); /* comfac */
    v306 = (*qfn1(fn))(qenv(fn), v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    v361 = v306;
    v306 = v361;
    v306 = qcar(v306);
    if (v306 == nil) goto v365;
    v306 = v361;
    v306 = ncons(v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    goto v366;

v366:
    fn = elt(env, 9); /* quotf1 */
    v306 = (*qfn2(fn))(qenv(fn), stack[-1], v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    stack[-9] = v306;
    v361 = stack[-9];
    v306 = stack[-8];
    fn = elt(env, 13); /* degr */
    v361 = (*qfn2(fn))(qenv(fn), v361, v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    v306 = (Lisp_Object)1; /* 0 */
    if (!(v361 == v306)) goto v165;
    v306 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v306); }

v365:
    v306 = v361;
    v306 = qcdr(v306);
    goto v366;

v213:
    v306 = stack[-10];
    stack[-6] = v306;
    goto v43;

v43:
    v306 = stack[-6];
    if (v306 == nil) goto v154;
    v306 = stack[-6];
    v306 = qcar(v306);
    stack[-5] = v306;
    v306 = stack[-5];
    if (!consp(v306)) goto v41;
    v306 = qvalue(elt(env, 4)); /* nil */
    goto v278;

v278:
    if (v306 == nil) goto v29;
    v306 = qvalue(elt(env, 1)); /* t */
    goto v367;

v367:
    if (!(v306 == nil)) goto v368;

v210:
    v306 = stack[-6];
    v306 = qcdr(v306);
    stack[-6] = v306;
    goto v43;

v368:
    v361 = stack[-7];
    v306 = stack[-5];
    fn = elt(env, 9); /* quotf1 */
    v306 = (*qfn2(fn))(qenv(fn), v361, v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    v361 = v306;
    if (v306 == nil) goto v210;
    v306 = v361;
    stack[-7] = v306;
    goto v368;

v29:
    v306 = stack[-5];
    if (!consp(v306)) goto v293;
    v306 = stack[-5];
    v306 = qcar(v306);
    v306 = (consp(v306) ? nil : lisp_true);
    goto v273;

v273:
    if (v306 == nil) goto v369;
    v361 = qvalue(elt(env, 6)); /* dmode!* */
    v306 = elt(env, 7); /* field */
    v306 = Lflagp(nil, v361, v306);
    env = stack[-11];
    if (v306 == nil) goto v370;
    v306 = qvalue(elt(env, 1)); /* t */
    goto v371;

v371:
    v306 = (v306 == nil ? lisp_true : nil);
    goto v367;

v370:
    v306 = stack[-5];
    v361 = qcar(v306);
    v306 = elt(env, 8); /* units */
    v306 = get(v361, v306);
    env = stack[-11];
    v361 = v306;
    if (v306 == nil) goto v142;
    stack[-4] = stack[-5];
    v306 = v361;
    stack[-3] = v306;
    v306 = stack[-3];
    if (v306 == nil) goto v140;
    v306 = stack[-3];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = ncons(v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    stack[-1] = v306;
    stack[-2] = v306;
    goto v270;

v270:
    v306 = stack[-3];
    v306 = qcdr(v306);
    stack[-3] = v306;
    v306 = stack[-3];
    if (v306 == nil) goto v13;
    stack[0] = stack[-1];
    v306 = stack[-3];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = ncons(v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    v306 = Lrplacd(nil, stack[0], v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    v306 = stack[-1];
    v306 = qcdr(v306);
    stack[-1] = v306;
    goto v270;

v13:
    v306 = stack[-2];
    goto v372;

v372:
    v306 = Lmember(nil, stack[-4], v306);
    goto v371;

v140:
    v306 = qvalue(elt(env, 4)); /* nil */
    goto v372;

v142:
    v306 = qvalue(elt(env, 4)); /* nil */
    goto v371;

v369:
    v306 = qvalue(elt(env, 4)); /* nil */
    goto v371;

v293:
    v306 = qvalue(elt(env, 1)); /* t */
    goto v273;

v41:
    v361 = qvalue(elt(env, 6)); /* dmode!* */
    v306 = elt(env, 7); /* field */
    v306 = Lflagp(nil, v361, v306);
    env = stack[-11];
    v306 = (v306 == nil ? lisp_true : nil);
    goto v278;

v364:
    v306 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v306); }

v228:
    v306 = qvalue(elt(env, 4)); /* nil */
    goto v174;

v192:
    v306 = qvalue(elt(env, 1)); /* t */
    goto v217;

v115:
    v361 = stack[-9];
    v306 = stack[0];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = qcar(v306);
    stack[-8] = v306;
    fn = elt(env, 13); /* degr */
    v361 = (*qfn2(fn))(qenv(fn), v361, v306);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-11];
    v306 = (Lisp_Object)1; /* 0 */
    v306 = (v361 == v306 ? lisp_true : nil);
    goto v72;

v126:
    v306 = qvalue(elt(env, 1)); /* t */
    goto v125;
/* error exit handlers */
v363:
    popv(12);
    return nil;
}



setup_type const u44_setup[] =
{
    {"quotfx1",                 too_few_2,      CC_quotfx1,    wrong_no_2},
    {"fac-part",                too_few_2,      CC_facKpart,   wrong_no_2},
    {"evalset_eq",              too_few_2,      CC_evalset_eq, wrong_no_2},
    {"rand-mons-sparse",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_randKmonsKsparse},
    {"partitpartdf",            CC_partitpartdf,too_many_1,    wrong_no_1},
    {"cali=min",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_caliMmin},
    {"pst_d",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_pst_d},
    {"?a2bf",                   CC_Wa2bf,       too_many_1,    wrong_no_1},
    {"giminusp:",               CC_giminuspT,   too_many_1,    wrong_no_1},
    {"canprod",                 too_few_2,      CC_canprod,    wrong_no_2},
    {"ofsf_multsurep",          too_few_2,      CC_ofsf_multsurep,wrong_no_2},
    {"ldt-dep",                 CC_ldtKdep,     too_many_1,    wrong_no_1},
    {"findhc",                  CC_findhc,      too_many_1,    wrong_no_1},
    {"gvarlis",                 CC_gvarlis,     too_many_1,    wrong_no_1},
    {"expt-separate",           too_few_2,      CC_exptKseparate,wrong_no_2},
    {"atlas_edges",             CC_atlas_edges, too_many_1,    wrong_no_1},
    {"subeval1",                too_few_2,      CC_subeval1,   wrong_no_2},
    {"mv2sf",                   too_few_2,      CC_mv2sf,      wrong_no_2},
    {"tensor_has_dummy_idx",    too_few_2,      CC_tensor_has_dummy_idx,wrong_no_2},
    {"lowestdeg",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_lowestdeg},
    {"vp1",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_vp1},
    {"available*p",             CC_availableHp, too_many_1,    wrong_no_1},
    {"pasf_mkop",               too_few_2,      CC_pasf_mkop,  wrong_no_2},
    {"cgp_cp",                  CC_cgp_cp,      too_many_1,    wrong_no_1},
    {"search4facf",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_search4facf},
    {"powmtch",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powmtch},
    {"simp:ps:",                CC_simpTpsT,    too_many_1,    wrong_no_1},
    {"dipcontevmin",            too_few_2,      CC_dipcontevmin,wrong_no_2},
    {"groebsimpcontnormalform", CC_groebsimpcontnormalform,too_many_1,wrong_no_1},
    {"let3",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_let3},
    {"exptbf",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_exptbf},
    {"rlval",                   too_few_2,      CC_rlval,      wrong_no_2},
    {"deg",                     too_few_2,      CC_deg,        wrong_no_2},
    {"constructinvolutivebasis",too_few_2,      CC_constructinvolutivebasis,wrong_no_2},
    {"cl_pnf1",                 CC_cl_pnf1,     too_many_1,    wrong_no_1},
    {"ofsf_anegrel",            CC_ofsf_anegrel,too_many_1,    wrong_no_1},
    {"gcdk",                    too_few_2,      CC_gcdk,       wrong_no_2},
    {NULL, (one_args *)"u44", (two_args *)"18395 7564267 9660657", 0}
};

/* end of generated code */
