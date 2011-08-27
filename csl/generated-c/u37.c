
/* $destdir\u37.c        Machine generated C code */

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


/* Code for dp_neworder */

static Lisp_Object CC_dp_neworder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_neworder");
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
    v14 = v0;
/* end of prologue */
    stack[-4] = v14;
    v14 = stack[-4];
    if (v14 == nil) goto v16;
    v14 = stack[-4];
    v14 = qcar(v14);
    stack[0] = v14;
    v14 = stack[0];
    v14 = qcar(v14);
    fn = elt(env, 3); /* mo_neworder */
    v15 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-5];
    v14 = stack[0];
    v14 = qcdr(v14);
    v14 = cons(v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-5];
    v14 = ncons(v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-5];
    stack[-2] = v14;
    stack[-3] = v14;
    goto v18;

v18:
    v14 = stack[-4];
    v14 = qcdr(v14);
    stack[-4] = v14;
    v14 = stack[-4];
    if (v14 == nil) goto v19;
    stack[-1] = stack[-2];
    v14 = stack[-4];
    v14 = qcar(v14);
    stack[0] = v14;
    v14 = stack[0];
    v14 = qcar(v14);
    fn = elt(env, 3); /* mo_neworder */
    v15 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-5];
    v14 = stack[0];
    v14 = qcdr(v14);
    v14 = cons(v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-5];
    v14 = ncons(v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-5];
    v14 = Lrplacd(nil, stack[-1], v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-5];
    v14 = stack[-2];
    v14 = qcdr(v14);
    stack[-2] = v14;
    goto v18;

v19:
    v14 = stack[-3];
    v15 = v14;
    goto v20;

v20:
    v14 = elt(env, 2); /* dp!=mocompare */
    {
        popv(6);
        fn = elt(env, 4); /* sort */
        return (*qfn2(fn))(qenv(fn), v15, v14);
    }

v16:
    v14 = qvalue(elt(env, 1)); /* nil */
    v15 = v14;
    goto v20;
/* error exit handlers */
v17:
    popv(6);
    return nil;
}



/* Code for test!-bool */

static Lisp_Object CC_testKbool(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for test-bool");
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
    v8 = qcar(v8);
    fn = elt(env, 1); /* boolean!-eval1 */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[0];
    v8 = ncons(v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[0];
    fn = elt(env, 2); /* simp!-prop */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v8);
    }
/* error exit handlers */
v10:
    popv(1);
    return nil;
}



/* Code for can_rep_cell */

static Lisp_Object CC_can_rep_cell(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for can_rep_cell");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v27 = v21;
    v25 = v0;
/* end of prologue */
    v25 = qcdr(v25);
    v26 = qcar(v25);
    v25 = (Lisp_Object)17; /* 1 */
    stack[0] = *(Lisp_Object *)((char *)v26 + (CELL-TAG_VECTOR) + ((int32_t)v25/(16/CELL)));
    v25 = v27;
    v25 = sub1(v25);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v25 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v25/(16/CELL)));
    { popv(1); return onevalue(v25); }
/* error exit handlers */
v28:
    popv(1);
    return nil;
}



/* Code for rl_qe */

static Lisp_Object CC_rl_qe(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_qe");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v22 = v21;
    v29 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_qe!* */
    v22 = list2(v29, v22);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    {
        Lisp_Object v26 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v26, v22);
    }
/* error exit handlers */
v25:
    popv(2);
    return nil;
}



/* Code for checkexp */

static Lisp_Object CC_checkexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v19, v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkexp");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v34 = v21;
    v35 = v0;
/* end of prologue */
    v19 = v34;
    v33 = (Lisp_Object)1; /* 0 */
    if (v19 == v33) goto v20;
    v19 = v34;
    v33 = (Lisp_Object)17; /* 1 */
    if (v19 == v33) { popv(2); return onevalue(v35); }
    stack[-1] = elt(env, 1); /* expt */
    stack[0] = v35;
    v33 = v34;
    fn = elt(env, 2); /* preptayexp */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v36;
    {
        Lisp_Object v37 = stack[-1];
        Lisp_Object v38 = stack[0];
        popv(2);
        return list3(v37, v38, v33);
    }

v20:
    v33 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v33); }
/* error exit handlers */
v36:
    popv(2);
    return nil;
}



/* Code for null!+vec!+p */

static Lisp_Object CC_nullLvecLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for null+vec+p");
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
    v32 = v0;
/* end of prologue */
    fn = elt(env, 2); /* mk!+squared!+norm */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[0];
    fn = elt(env, 3); /* my!+nullsq!+p */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[0];
    if (v32 == nil) goto v20;
    v32 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v32); }

v20:
    v32 = nil;
    { popv(1); return onevalue(v32); }
/* error exit handlers */
v18:
    popv(1);
    return nil;
}



/* Code for mchsarg */

static Lisp_Object MS_CDECL CC_mchsarg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v21,
                         Lisp_Object v39, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mchsarg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchsarg");
#endif
    if (stack >= stacklimit)
    {
        push3(v39,v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v21,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v39;
    stack[-6] = v21;
    stack[-1] = v0;
/* end of prologue */
    v61 = stack[-6];
    fn = elt(env, 4); /* mtp */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    if (v61 == nil) goto v64;
    v62 = stack[-5];
    v61 = elt(env, 1); /* times */
    if (v62 == v61) goto v28;
    v61 = qvalue(elt(env, 2)); /* t */
    goto v65;

v65:
    if (v61 == nil) goto v64;
    v61 = stack[-6];
    fn = elt(env, 5); /* noncomperm */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    stack[-4] = v61;
    v61 = stack[-4];
    if (v61 == nil) goto v33;
    v61 = stack[-4];
    v61 = qcar(v61);
    v62 = v61;
    v61 = stack[-1];
    fn = elt(env, 6); /* pair */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    v61 = ncons(v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    stack[-2] = v61;
    stack[-3] = v61;
    goto v66;

v66:
    v61 = stack[-4];
    v61 = qcdr(v61);
    stack[-4] = v61;
    v61 = stack[-4];
    if (v61 == nil) goto v67;
    stack[0] = stack[-2];
    v61 = stack[-4];
    v61 = qcar(v61);
    v62 = v61;
    v61 = stack[-1];
    fn = elt(env, 6); /* pair */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    v61 = ncons(v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    v61 = Lrplacd(nil, stack[0], v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    v61 = stack[-2];
    v61 = qcdr(v61);
    stack[-2] = v61;
    goto v66;

v67:
    v61 = stack[-3];
    goto v68;

v68:
        popv(9);
        return Lnreverse(nil, v61);

v33:
    v61 = qvalue(elt(env, 3)); /* nil */
    goto v68;

v64:
    v61 = stack[-1];
    fn = elt(env, 5); /* noncomperm */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    stack[-7] = v61;
    goto v69;

v69:
    v61 = stack[-7];
    if (v61 == nil) goto v70;
    v61 = stack[-7];
    v61 = qcar(v61);
    stack[-1] = v61;
    stack[0] = stack[-6];
    v61 = qvalue(elt(env, 3)); /* nil */
    v62 = ncons(v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    v61 = stack[-5];
    fn = elt(env, 7); /* mcharg2 */
    v61 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    stack[-4] = v61;
    v61 = stack[-4];
    fn = elt(env, 8); /* lastpair */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    stack[-3] = v61;
    v61 = stack[-7];
    v61 = qcdr(v61);
    stack[-7] = v61;
    v61 = stack[-3];
    if (!consp(v61)) goto v69;
    else goto v71;

v71:
    v61 = stack[-7];
    if (v61 == nil) goto v72;
    stack[-2] = stack[-3];
    v61 = stack[-7];
    v61 = qcar(v61);
    stack[-1] = v61;
    stack[0] = stack[-6];
    v61 = qvalue(elt(env, 3)); /* nil */
    v62 = ncons(v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    v61 = stack[-5];
    fn = elt(env, 7); /* mcharg2 */
    v61 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    v61 = Lrplacd(nil, stack[-2], v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    v61 = stack[-3];
    fn = elt(env, 8); /* lastpair */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    stack[-3] = v61;
    v61 = stack[-7];
    v61 = qcdr(v61);
    stack[-7] = v61;
    goto v71;

v72:
    v61 = stack[-4];
    goto v68;

v70:
    v61 = qvalue(elt(env, 3)); /* nil */
    goto v68;

v28:
    v61 = stack[-1];
    fn = elt(env, 9); /* noncomfree */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-8];
    goto v65;
/* error exit handlers */
v63:
    popv(9);
    return nil;
}



/* Code for ratpoly_minus */

static Lisp_Object CC_ratpoly_minus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_minus");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    v25 = v0;
/* end of prologue */
    stack[-1] = v25;
    v25 = stack[0];
    v25 = qcar(v25);
    fn = elt(env, 1); /* negf */
    v26 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v25 = stack[0];
    v25 = qcdr(v25);
    v25 = cons(v26, v25);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    {
        Lisp_Object v74 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* addsq */
        return (*qfn2(fn))(qenv(fn), v74, v25);
    }
/* error exit handlers */
v28:
    popv(3);
    return nil;
}



/* Code for matrixml */

static Lisp_Object CC_matrixml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v77;
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
    v35 = stack[0];
    v77 = Llength(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    v35 = (Lisp_Object)17; /* 1 */
    if (v77 == v35) goto v68;
    v35 = elt(env, 1); /* "<matrix>" */
    fn = elt(env, 4); /* printout */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    v77 = qvalue(elt(env, 2)); /* indent */
    v35 = (Lisp_Object)49; /* 3 */
    v35 = plus2(v77, v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    qvalue(elt(env, 2)) = v35; /* indent */
    v35 = stack[0];
    fn = elt(env, 5); /* matrix_rows */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    v77 = qvalue(elt(env, 2)); /* indent */
    v35 = (Lisp_Object)49; /* 3 */
    v35 = difference2(v77, v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    qvalue(elt(env, 2)) = v35; /* indent */
    v35 = elt(env, 3); /* "</matrix>" */
    fn = elt(env, 4); /* printout */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    goto v20;

v20:
    v35 = nil;
    { popv(2); return onevalue(v35); }

v68:
    v35 = stack[0];
    fn = elt(env, 6); /* vectorml */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    goto v20;
/* error exit handlers */
v36:
    popv(2);
    return nil;
}



/* Code for ldf!-dep!-var */

static Lisp_Object CC_ldfKdepKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-dep-var");
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
    v60 = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = v60;
    goto v8;

v8:
    v60 = stack[-1];
    if (v60 == nil) goto v79;
    v60 = stack[-1];
    v60 = qcar(v60);
    stack[0] = v60;
    v60 = stack[0];
    fn = elt(env, 3); /* ldt!-tvar */
    v7 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    v60 = qvalue(elt(env, 2)); /* depl!* */
    v60 = Lassoc(nil, v7, v60);
    if (v60 == nil) goto v73;
    v60 = stack[0];
    fn = elt(env, 3); /* ldt!-tvar */
    v7 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    v60 = qvalue(elt(env, 2)); /* depl!* */
    v60 = Lassoc(nil, v7, v60);
    v7 = qcdr(v60);
    v60 = stack[-2];
    v60 = Lappend(nil, v7, v60);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    stack[-2] = v60;
    goto v73;

v73:
    v60 = stack[-1];
    v60 = qcdr(v60);
    stack[-1] = v60;
    goto v8;

v79:
    v60 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* makeset */
        return (*qfn1(fn))(qenv(fn), v60);
    }
/* error exit handlers */
v80:
    popv(4);
    return nil;
}



/* Code for transmat1 */

static Lisp_Object CC_transmat1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98, v99, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transmat1");
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
    v97 = stack[-6];
    v97 = qcar(v97);
    fn = elt(env, 6); /* aeval */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    v97 = qcdr(v97);
    stack[0] = v97;
    v97 = (Lisp_Object)1; /* 0 */
    stack[-5] = v97;
    v97 = (Lisp_Object)1; /* 0 */
    stack[-4] = v97;
    v97 = stack[-6];
    v97 = qcar(v97);
    fn = elt(env, 6); /* aeval */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    fn = elt(env, 7); /* matlength */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    v97 = qcdr(v97);
    v98 = v97;
    stack[-1] = qcar(v98);
    v98 = elt(env, 1); /* spm */
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    fn = elt(env, 8); /* mkempspmat */
    v97 = (*qfn2(fn))(qenv(fn), stack[-1], v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    stack[-7] = v97;
    v97 = qvalue(elt(env, 2)); /* nil */
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    stack[-2] = v97;
    v97 = stack[0];
    stack[-1] = v97;
    goto v36;

v36:
    v97 = stack[-1];
    if (v97 == nil) goto v102;
    v97 = stack[-1];
    v97 = qcar(v97);
    stack[0] = v97;
    v97 = stack[-5];
    v97 = add1(v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    stack[-5] = v97;
    v97 = stack[0];
    stack[0] = v97;
    goto v103;

v103:
    v97 = stack[0];
    if (v97 == nil) goto v5;
    v97 = stack[0];
    v97 = qcar(v97);
    stack[-3] = v97;
    v97 = stack[-4];
    v97 = add1(v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    stack[-4] = v97;
    v98 = stack[-3];
    v97 = (Lisp_Object)1; /* 0 */
    if (v98 == v97) goto v104;
    v99 = stack[-4];
    v98 = stack[-3];
    v97 = stack[-2];
    v97 = acons(v99, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    stack[-2] = v97;
    goto v104;

v104:
    v97 = stack[0];
    v97 = qcdr(v97);
    stack[0] = v97;
    goto v103;

v5:
    v97 = stack[-2];
    v97 = Lreverse(nil, v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    stack[-2] = v97;
    stack[0] = stack[-2];
    v97 = qvalue(elt(env, 2)); /* nil */
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    if (equal(stack[0], v97)) goto v105;
    v98 = stack[-7];
    v97 = stack[-5];
    v100 = list2(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    v99 = stack[-2];
    v98 = stack[-7];
    v97 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 9); /* letmtr3 */
    v97 = (*qfnn(fn))(qenv(fn), 4, v100, v99, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    goto v105;

v105:
    v97 = (Lisp_Object)1; /* 0 */
    stack[-4] = v97;
    v97 = qvalue(elt(env, 2)); /* nil */
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    stack[-2] = v97;
    v97 = stack[-1];
    v97 = qcdr(v97);
    stack[-1] = v97;
    goto v36;

v102:
    v97 = stack[-6];
    stack[-1] = qcar(v97);
    stack[0] = elt(env, 3); /* avalue */
    v98 = elt(env, 4); /* sparse */
    v97 = stack[-7];
    v97 = list2(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    v97 = Lputprop(nil, 3, stack[-1], stack[0], v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    v97 = stack[-6];
    v99 = qcar(v97);
    v98 = elt(env, 5); /* rtype */
    v97 = elt(env, 4); /* sparse */
    v97 = Lputprop(nil, 3, v99, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v101;
    v97 = nil;
    { popv(9); return onevalue(v97); }
/* error exit handlers */
v101:
    popv(9);
    return nil;
}



/* Code for row_dim */

static Lisp_Object CC_row_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for row_dim");
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
    v106 = qvalue(elt(env, 1)); /* !*fast_la */
    if (v106 == nil) goto v9;
    v106 = qvalue(elt(env, 2)); /* nil */
    goto v10;

v10:
    if (v106 == nil) goto v20;
    v106 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v106 == nil)) goto v26;
    v106 = elt(env, 4); /* "Error in row_dim: input should be a matrix." 
*/
    fn = elt(env, 5); /* lprie */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-1];
    goto v26;

v26:
    v106 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-1];
    goto v20;

v20:
    v106 = stack[0];
    fn = elt(env, 6); /* size_of_matrix */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v106 = qcar(v106);
    { popv(2); return onevalue(v106); }

v9:
    v106 = stack[0];
    fn = elt(env, 7); /* matrixp */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-1];
    v106 = (v106 == nil ? lisp_true : nil);
    goto v10;
/* error exit handlers */
v66:
    popv(2);
    return nil;
}



/* Code for dipcontenti */

static Lisp_Object CC_dipcontenti(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v108, v109, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcontenti");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v0;
/* end of prologue */
    v103 = v6;
    if (v103 == nil) goto v95;
    v103 = v6;
    v103 = qcdr(v103);
    v103 = qcdr(v103);
    v109 = v103;
    v103 = v109;
    if (v103 == nil) goto v73;
    v103 = v6;
    v103 = qcdr(v103);
    v108 = qcar(v103);
    v103 = qvalue(elt(env, 1)); /* !*groebrm */
    if (v103 == nil) goto v80;
    v103 = v6;
    v103 = qcar(v103);
    goto v37;

v37:
    {
        fn = elt(env, 3); /* dipcontenti1 */
        return (*qfnn(fn))(qenv(fn), 3, v108, v103, v109);
    }

v80:
    v103 = qvalue(elt(env, 2)); /* nil */
    goto v37;

v73:
    v103 = v6;
    v103 = qcdr(v103);
    v108 = qcar(v103);
    v103 = qvalue(elt(env, 1)); /* !*groebrm */
    if (v103 == nil) goto v12;
    v103 = v6;
    v103 = qcar(v103);
    goto v27;

v27:
    return cons(v108, v103);

v12:
    v103 = qvalue(elt(env, 2)); /* nil */
    goto v27;

v95:
    v103 = (Lisp_Object)17; /* 1 */
    return onevalue(v103);
}



/* Code for minprec */

static Lisp_Object MS_CDECL CC_minprec(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "minprec");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minprec");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v9 = qvalue(elt(env, 1)); /* !*bftag */
    if (v9 == nil) goto v79;
    v9 = qvalue(elt(env, 2)); /* !:prec!: */
    return onevalue(v9);

v79:
    v9 = qvalue(elt(env, 3)); /* !!nfpd */
    return onevalue(v9);
}



/* Code for rationalizef */

static Lisp_Object CC_rationalizef(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rationalizef");
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
    v136 = stack[-2];
    v135 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 10); /* kernels1 */
    v135 = (*qfn2(fn))(qenv(fn), v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    stack[0] = v135;
    stack[-3] = v135;
    goto v79;

v79:
    v135 = stack[-3];
    if (v135 == nil) goto v22;
    v135 = stack[-3];
    v135 = qcar(v135);
    stack[-1] = v135;
    v136 = stack[-1];
    v135 = elt(env, 2); /* expt */
    if (!consp(v136)) goto v138;
    v136 = qcar(v136);
    if (!(v136 == v135)) goto v138;
    v135 = stack[-1];
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v136 = qcar(v135);
    v135 = elt(env, 3); /* quotient */
    if (!consp(v136)) goto v109;
    v136 = qcar(v136);
    if (!(v136 == v135)) goto v109;
    v136 = stack[0];
    v135 = stack[-1];
    v135 = qcdr(v135);
    fn = elt(env, 11); /* lowertowerp */
    v135 = (*qfn2(fn))(qenv(fn), v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    goto v58;

v58:
    if (!(v135 == nil)) goto v28;
    v136 = stack[-1];
    v135 = elt(env, 4); /* i */
    if (v136 == v135) goto v139;
    v136 = stack[-1];
    v135 = elt(env, 2); /* expt */
    if (!consp(v136)) goto v52;
    v136 = qcar(v136);
    if (!(v136 == v135)) goto v52;
    v135 = stack[-1];
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v136 = qcar(v135);
    v135 = elt(env, 6); /* (quotient 1 2) */
    v135 = (equal(v136, v135) ? lisp_true : nil);
    goto v71;

v71:
    if (v135 == nil) goto v140;
    v135 = qvalue(elt(env, 5)); /* t */
    goto v141;

v141:
    if (v135 == nil) goto v142;
    v136 = stack[-2];
    v135 = stack[-1];
    fn = elt(env, 12); /* mkmain */
    v136 = (*qfn2(fn))(qenv(fn), v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    v135 = stack[-1];
    {
        popv(5);
        fn = elt(env, 13); /* conjquadratic */
        return (*qfn2(fn))(qenv(fn), v136, v135);
    }

v142:
    v136 = stack[-1];
    v135 = elt(env, 2); /* expt */
    if (!consp(v136)) goto v143;
    v136 = qcar(v136);
    if (!(v136 == v135)) goto v143;
    v135 = stack[-1];
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v136 = qcar(v135);
    v135 = elt(env, 8); /* (quotient 1 3) */
    v135 = (equal(v136, v135) ? lisp_true : nil);
    goto v144;

v144:
    if (v135 == nil) goto v145;
    v136 = stack[-2];
    v135 = stack[-1];
    fn = elt(env, 12); /* mkmain */
    v136 = (*qfn2(fn))(qenv(fn), v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    v135 = stack[-1];
    {
        popv(5);
        fn = elt(env, 14); /* conjcubic */
        return (*qfn2(fn))(qenv(fn), v136, v135);
    }

v145:
    v136 = stack[-1];
    v135 = elt(env, 2); /* expt */
    if (!consp(v136)) goto v146;
    v136 = qcar(v136);
    if (!(v136 == v135)) goto v146;
    v135 = stack[-1];
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v136 = qcar(v135);
    v135 = elt(env, 9); /* (quotient 1 4) */
    v135 = (equal(v136, v135) ? lisp_true : nil);
    goto v101;

v101:
    if (v135 == nil) goto v28;
    v136 = stack[-2];
    v135 = stack[-1];
    fn = elt(env, 12); /* mkmain */
    v136 = (*qfn2(fn))(qenv(fn), v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    v135 = stack[-1];
    {
        popv(5);
        fn = elt(env, 15); /* conjquartic */
        return (*qfn2(fn))(qenv(fn), v136, v135);
    }

v28:
    v135 = stack[-3];
    v135 = qcdr(v135);
    stack[-3] = v135;
    goto v79;

v146:
    v135 = qvalue(elt(env, 1)); /* nil */
    goto v101;

v143:
    v135 = qvalue(elt(env, 1)); /* nil */
    goto v144;

v140:
    v136 = stack[-1];
    v135 = elt(env, 7); /* sqrt */
    v135 = Leqcar(nil, v136, v135);
    env = stack[-4];
    goto v141;

v52:
    v135 = qvalue(elt(env, 1)); /* nil */
    goto v71;

v139:
    v135 = qvalue(elt(env, 5)); /* t */
    goto v141;

v109:
    v135 = qvalue(elt(env, 1)); /* nil */
    goto v58;

v138:
    v135 = qvalue(elt(env, 1)); /* nil */
    goto v58;

v22:
    v135 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v135); }
/* error exit handlers */
v137:
    popv(5);
    return nil;
}



/* Code for lf!=zero */

static Lisp_Object CC_lfMzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lf=zero");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */
    v20 = qcdr(v20);
    v20 = (v20 == nil ? lisp_true : nil);
    return onevalue(v20);
}



/* Code for add!-factor */

static Lisp_Object CC_addKfactor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v2, v14;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add-factor");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */
    v138 = stack[0];
    v138 = Lconsp(nil, v138);
    env = stack[-2];
    if (v138 == nil) goto v66;
    v2 = stack[-1];
    v138 = stack[0];
    v138 = qcar(v138);
    v138 = qcar(v138);
    v138 = (Lisp_Object)greaterp2(v2, v138);
    nil = C_nil;
    if (exception_pending()) goto v149;
    v138 = v138 ? lisp_true : nil;
    env = stack[-2];
    if (v138 == nil) goto v74;
    v138 = qvalue(elt(env, 1)); /* nil */
    goto v95;

v95:
    v2 = v138;
    v138 = v2;
    if (v138 == nil) goto v150;
    stack[-1] = v2;
    v138 = v2;
    v138 = qcdr(v138);
    v138 = add1(v138);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    v138 = Lrplacd(nil, stack[-1], v138);
    nil = C_nil;
    if (exception_pending()) goto v149;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v150:
    v14 = stack[-1];
    v2 = (Lisp_Object)17; /* 1 */
    v138 = stack[0];
    popv(3);
    return acons(v14, v2, v138);

v74:
    v2 = stack[-1];
    v138 = stack[0];
    v138 = Lassoc(nil, v2, v138);
    goto v95;

v66:
    v138 = qvalue(elt(env, 1)); /* nil */
    goto v95;
/* error exit handlers */
v149:
    popv(3);
    return nil;
}



/* Code for coeffs!-to!-form1 */

static Lisp_Object MS_CDECL CC_coeffsKtoKform1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v21,
                         Lisp_Object v39, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v108, v109;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeffs-to-form1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeffs-to-form1");
#endif
    if (stack >= stacklimit)
    {
        push3(v39,v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v21,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v39;
    stack[-2] = v21;
    stack[-3] = v0;
/* end of prologue */
    v108 = stack[-1];
    v103 = (Lisp_Object)1; /* 0 */
    v103 = (Lisp_Object)greaterp2(v108, v103);
    nil = C_nil;
    if (exception_pending()) goto v15;
    v103 = v103 ? lisp_true : nil;
    env = stack[-5];
    if (v103 == nil) goto v80;
    v103 = stack[-3];
    stack[-4] = qcdr(v103);
    stack[0] = stack[-2];
    v103 = stack[-1];
    v103 = sub1(v103);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-5];
    v103 = CC_coeffsKtoKform1(env, 3, stack[-4], stack[0], v103);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-5];
    stack[0] = v103;
    v103 = stack[-3];
    v103 = qcar(v103);
    if (v103 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v108 = stack[-2];
    v103 = stack[-1];
    v109 = cons(v108, v103);
    nil = C_nil;
    if (exception_pending()) goto v15;
    v103 = stack[-3];
    v108 = qcar(v103);
    v103 = stack[0];
    popv(6);
    return acons(v109, v108, v103);

v80:
    v103 = stack[-3];
    v103 = qcar(v103);
    { popv(6); return onevalue(v103); }
/* error exit handlers */
v15:
    popv(6);
    return nil;
}



/* Code for rl_pnf */

static Lisp_Object CC_rl_pnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_pnf");
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
    v1 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_pnf!* */
    v1 = ncons(v1);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    {
        Lisp_Object v65 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v65, v1);
    }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for simp0 */

static Lisp_Object CC_simp0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp0");
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
    stack[-6] = qvalue(elt(env, 1)); /* !*factor */
    qvalue(elt(env, 1)) = nil; /* !*factor */
    v159 = stack[-5];
    v158 = elt(env, 2); /* !*sq */
    if (!consp(v159)) goto v107;
    v159 = qcar(v159);
    if (!(v159 == v158)) goto v107;
    v158 = stack[-5];
    v158 = qcdr(v158);
    v158 = qcar(v158);
    fn = elt(env, 10); /* prepsq!* */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-7];
    v158 = CC_simp0(env, v158);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-7];
    goto v79;

v79:
    qvalue(elt(env, 1)) = stack[-6]; /* !*factor */
    { popv(8); return onevalue(v158); }

v107:
    v159 = stack[-5];
    v158 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 11); /* frvarsof */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-7];
    fn = elt(env, 12); /* setkorder */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-7];
    stack[-3] = v158;
    v159 = qvalue(elt(env, 4)); /* subfg!* */
    v158 = qvalue(elt(env, 5)); /* !*sub2 */
    v158 = cons(v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-7];
    stack[-4] = v158;
    v158 = qvalue(elt(env, 3)); /* nil */
    v158 = ncons(v158);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-7];
    qvalue(elt(env, 6)) = v158; /* alglist!* */
    v158 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v158; /* subfg!* */
    v158 = stack[-5];
    if (!consp(v158)) goto v4;
    v158 = stack[-5];
    v158 = qcar(v158);
    if (symbolp(v158)) goto v160;
    v158 = qvalue(elt(env, 3)); /* nil */
    goto v3;

v3:
    if (v158 == nil) goto v161;
    v158 = stack[-5];
    fn = elt(env, 13); /* simp */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-7];
    stack[-2] = v158;
    goto v93;

v93:
    stack[-1] = qvalue(elt(env, 6)); /* alglist!* */
    v158 = qvalue(elt(env, 6)); /* alglist!* */
    v158 = qcar(v158);
    stack[0] = v158;
    v158 = stack[0];
    if (v158 == nil) goto v162;
    v159 = stack[-5];
    v158 = stack[0];
    fn = elt(env, 14); /* remhash */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-7];
    v158 = stack[0];
    goto v132;

v132:
    v158 = Lrplaca(nil, stack[-1], v158);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-7];
    v158 = stack[-4];
    v158 = qcar(v158);
    qvalue(elt(env, 4)) = v158; /* subfg!* */
    v158 = stack[-4];
    v158 = qcdr(v158);
    qvalue(elt(env, 5)) = v158; /* !*sub2 */
    v158 = stack[-3];
    fn = elt(env, 12); /* setkorder */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-7];
    v158 = stack[-2];
    goto v79;

v162:
    v158 = qvalue(elt(env, 3)); /* nil */
    goto v132;

v161:
    v158 = stack[-5];
    fn = elt(env, 15); /* simpiden */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-7];
    stack[-2] = v158;
    goto v93;

v160:
    v158 = stack[-5];
    v159 = qcar(v158);
    v158 = elt(env, 8); /* simp0fn */
    v158 = Lflagp(nil, v159, v158);
    env = stack[-7];
    if (v158 == nil) goto v134;
    v158 = qvalue(elt(env, 7)); /* t */
    goto v3;

v134:
    v158 = stack[-5];
    v159 = qcar(v158);
    v158 = elt(env, 9); /* rtype */
    v158 = get(v159, v158);
    env = stack[-7];
    goto v3;

v4:
    v158 = qvalue(elt(env, 7)); /* t */
    goto v3;
/* error exit handlers */
v40:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*factor */
    popv(8);
    return nil;
}



/* Code for get!-min!-degreelist */

static Lisp_Object CC_getKminKdegreelist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-min-degreelist");
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
    v166 = v0;
/* end of prologue */
    v165 = v166;
    if (v165 == nil) goto v95;
    v165 = v166;
    v165 = qcdr(v165);
    if (v165 == nil) goto v10;
    v165 = v166;
    v165 = qcar(v165);
    stack[0] = qcar(v165);
    v165 = v166;
    v165 = qcdr(v165);
    v165 = CC_getKminKdegreelist(env, v165);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    {
        Lisp_Object v128 = stack[0];
        popv(6);
        fn = elt(env, 2); /* taymindegreel */
        return (*qfn2(fn))(qenv(fn), v128, v165);
    }

v10:
    v165 = v166;
    v165 = qcar(v165);
    v165 = qcar(v165);
    stack[-4] = v165;
    v165 = stack[-4];
    if (v165 == nil) goto v13;
    v165 = stack[-4];
    v165 = qcar(v165);
    stack[0] = v165;
    v165 = (Lisp_Object)1; /* 0 */
    v166 = v165;
    goto v30;

v30:
    v165 = stack[0];
    if (v165 == nil) goto v34;
    v165 = stack[0];
    v165 = qcar(v165);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v165 = (*qfn2(fn))(qenv(fn), v165, v166);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v166 = v165;
    v165 = stack[0];
    v165 = qcdr(v165);
    stack[0] = v165;
    goto v30;

v34:
    v165 = v166;
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    stack[-2] = v165;
    stack[-3] = v165;
    goto v22;

v22:
    v165 = stack[-4];
    v165 = qcdr(v165);
    stack[-4] = v165;
    v165 = stack[-4];
    if (v165 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v165 = stack[-4];
    v165 = qcar(v165);
    stack[0] = v165;
    v165 = (Lisp_Object)1; /* 0 */
    v166 = v165;
    goto v56;

v56:
    v165 = stack[0];
    if (v165 == nil) goto v48;
    v165 = stack[0];
    v165 = qcar(v165);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v165 = (*qfn2(fn))(qenv(fn), v165, v166);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v166 = v165;
    v165 = stack[0];
    v165 = qcdr(v165);
    stack[0] = v165;
    goto v56;

v48:
    v165 = v166;
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v165 = Lrplacd(nil, stack[-1], v165);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v165 = stack[-2];
    v165 = qcdr(v165);
    stack[-2] = v165;
    goto v22;

v13:
    v165 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v165); }

v95:
    v165 = elt(env, 0); /* get!-min!-degreelist */
    {
        popv(6);
        fn = elt(env, 4); /* confusion */
        return (*qfn1(fn))(qenv(fn), v165);
    }
/* error exit handlers */
v127:
    popv(6);
    return nil;
}



/* Code for get!*order */

static Lisp_Object CC_getHorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*order");
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
    v79 = v0;
/* end of prologue */
    fn = elt(env, 1); /* get!*elements */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    errexit();
        return Llength(nil, v79);
}



/* Code for qqe_simplbtat */

static Lisp_Object CC_qqe_simplbtat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplbtat");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v71 = v21;
    stack[-2] = v0;
/* end of prologue */
    v71 = stack[-2];
    fn = elt(env, 6); /* rl_prepat */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[-3] = v71;
    v71 = stack[-2];
    fn = elt(env, 7); /* qqe_op */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[0] = v71;
    v71 = stack[-3];
    fn = elt(env, 8); /* qqe_arg2l */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    fn = elt(env, 9); /* qqe_eta!-in!-term */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[-1] = v71;
    v71 = stack[-3];
    fn = elt(env, 10); /* qqe_arg2r */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    fn = elt(env, 9); /* qqe_eta!-in!-term */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    v161 = v71;
    v71 = stack[-1];
    if (v71 == nil) goto v26;
    v71 = v161;
    if (!(v71 == nil)) goto v26;
    v161 = stack[0];
    v71 = elt(env, 1); /* neq */
    if (v161 == v71) goto v33;
    v71 = elt(env, 2); /* false */
    { popv(5); return onevalue(v71); }

v33:
    v71 = elt(env, 3); /* true */
    { popv(5); return onevalue(v71); }

v26:
    v71 = v161;
    if (v71 == nil) goto v151;
    v71 = stack[-1];
    if (!(v71 == nil)) goto v151;
    v161 = stack[0];
    v71 = elt(env, 1); /* neq */
    if (v161 == v71) goto v5;
    v71 = elt(env, 2); /* false */
    { popv(5); return onevalue(v71); }

v5:
    v71 = elt(env, 3); /* true */
    { popv(5); return onevalue(v71); }

v151:
    v71 = stack[-1];
    if (v71 == nil) goto v42;
    v71 = v161;
    if (v71 == nil) goto v42;
    v71 = stack[-2];
    fn = elt(env, 7); /* qqe_op */
    v161 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    v71 = elt(env, 5); /* equal */
    if (v161 == v71) goto v57;
    v71 = elt(env, 2); /* false */
    { popv(5); return onevalue(v71); }

v57:
    v71 = elt(env, 3); /* true */
    { popv(5); return onevalue(v71); }

v42:
    v71 = stack[-3];
    {
        popv(5);
        fn = elt(env, 11); /* rl_simpat */
        return (*qfn1(fn))(qenv(fn), v71);
    }
/* error exit handlers */
v93:
    popv(5);
    return nil;
}



/* Code for pasf_pnf */

static Lisp_Object CC_pasf_pnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_pnf");
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
    v20 = v0;
/* end of prologue */
    fn = elt(env, 1); /* rl_nnf */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* pasf_pnf1 */
        return (*qfn1(fn))(qenv(fn), v20);
    }
/* error exit handlers */
v68:
    popv(1);
    return nil;
}



/* Code for dvfsf_0mk2 */

static Lisp_Object CC_dvfsf_0mk2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v23, v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_0mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v65 = v21;
    v23 = v0;
/* end of prologue */
    v24 = qvalue(elt(env, 1)); /* nil */
    return list3(v23, v65, v24);
}



/* Code for symbolsrd */

static Lisp_Object MS_CDECL CC_symbolsrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v81, v82;
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
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    v81 = qvalue(elt(env, 2)); /* char */
    v83 = elt(env, 3); /* (b v a r) */
    if (equal(v81, v83)) goto v29;
    v81 = elt(env, 5); /* "<bvar>" */
    v83 = (Lisp_Object)225; /* 14 */
    fn = elt(env, 10); /* errorml */
    v83 = (*qfn2(fn))(qenv(fn), v81, v83);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    goto v14;

v14:
    v81 = qvalue(elt(env, 2)); /* char */
    v83 = elt(env, 6); /* (l o w l i m i t) */
    if (equal(v81, v83)) goto v138;
    v83 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v83;
    goto v94;

v94:
    v81 = qvalue(elt(env, 2)); /* char */
    v83 = elt(env, 7); /* (i n t e r v a l) */
    if (equal(v81, v83)) goto v134;
    v83 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v83;
    goto v132;

v132:
    v81 = qvalue(elt(env, 2)); /* char */
    v83 = elt(env, 8); /* (c o n d i t i o n) */
    if (equal(v81, v83)) goto v91;
    v83 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v83;
    goto v93;

v93:
    fn = elt(env, 11); /* mathml2 */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    stack[-1] = v83;
    fn = elt(env, 9); /* lex */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    v83 = stack[-3];
    if (v83 == nil) goto v50;
    v82 = stack[-4];
    v81 = stack[-3];
    v83 = stack[-1];
    popv(6);
    return list3(v82, v81, v83);

v50:
    v83 = stack[-2];
    if (v83 == nil) goto v159;
    v82 = stack[-4];
    v81 = stack[-2];
    v83 = stack[-1];
    popv(6);
    return list3(v82, v81, v83);

v159:
    v83 = stack[0];
    if (v83 == nil) goto v62;
    v82 = stack[-4];
    v81 = stack[0];
    v83 = stack[-1];
    popv(6);
    return list3(v82, v81, v83);

v62:
    v81 = stack[-4];
    v82 = qvalue(elt(env, 1)); /* nil */
    v83 = stack[-1];
    popv(6);
    return list3(v81, v82, v83);

v91:
    fn = elt(env, 12); /* conditionrd */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    stack[0] = v83;
    fn = elt(env, 9); /* lex */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    goto v93;

v134:
    fn = elt(env, 13); /* intervalrd */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    stack[-2] = v83;
    fn = elt(env, 9); /* lex */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    goto v132;

v138:
    fn = elt(env, 14); /* lowupperlimitrd */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    stack[-3] = v83;
    fn = elt(env, 9); /* lex */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    goto v94;

v29:
    fn = elt(env, 15); /* bvarrd */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    stack[-4] = v83;
    v83 = stack[-4];
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    v81 = qcar(v83);
    v83 = (Lisp_Object)17; /* 1 */
    if (v81 == v83) goto v11;
    v81 = elt(env, 4); /* "" */
    v83 = (Lisp_Object)209; /* 13 */
    fn = elt(env, 10); /* errorml */
    v83 = (*qfn2(fn))(qenv(fn), v81, v83);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    goto v59;

v59:
    fn = elt(env, 9); /* lex */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    goto v14;

v11:
    v83 = stack[-4];
    stack[-4] = v83;
    goto v59;
/* error exit handlers */
v174:
    popv(6);
    return nil;
}



/* Code for search_att */

static Lisp_Object CC_search_att(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for search_att");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v21;
    stack[-2] = v0;
/* end of prologue */
    v184 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v184;
    v184 = (Lisp_Object)1; /* 0 */
    stack[-3] = v184;
    v185 = stack[-2];
    v184 = stack[-1];
    fn = elt(env, 8); /* find */
    v184 = (*qfn2(fn))(qenv(fn), v185, v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    stack[-2] = v184;
    v185 = stack[-2];
    v184 = elt(env, 2); /* (stop) */
    if (!(equal(v185, v184))) goto v31;
    v184 = nil;
    { popv(5); return onevalue(v184); }

v31:
    v184 = stack[-2];
    v185 = qcar(v184);
    v184 = elt(env, 3); /* !  */
    if (v185 == v184) goto v66;
    v184 = stack[-2];
    v185 = qcar(v184);
    v184 = elt(env, 4); /* != */
    if (v185 == v184) goto v3;
    v184 = stack[-1];
    v185 = Lcompress(nil, v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v184 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 9); /* errorml */
    v184 = (*qfn2(fn))(qenv(fn), v185, v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    goto v187;

v187:
    v184 = stack[0];
    v184 = qcar(v184);
    v185 = elt(env, 5); /* !" */
    if (!(v184 == v185)) goto v188;
    v184 = stack[0];
    v184 = qcdr(v184);
    stack[0] = v184;
    goto v188;

v188:
    v184 = stack[0];
        popv(5);
        return Lreverse(nil, v184);

v3:
    v184 = stack[-2];
    v184 = qcdr(v184);
    stack[-2] = v184;
    goto v14;

v14:
    v184 = stack[-2];
    v185 = qcar(v184);
    v184 = elt(env, 3); /* !  */
    if (v185 == v184) goto v147;
    v184 = stack[-2];
    v185 = qcar(v184);
    v184 = elt(env, 5); /* !" */
    if (!(v185 == v184)) goto v44;
    v184 = stack[-2];
    v184 = qcdr(v184);
    stack[-2] = v184;
    goto v132;

v132:
    v185 = stack[-3];
    v184 = (Lisp_Object)1; /* 0 */
    if (!(v185 == v184)) goto v187;
    v184 = stack[-2];
    v185 = qcar(v184);
    v184 = stack[0];
    v184 = cons(v185, v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    stack[0] = v184;
    v184 = stack[-2];
    v184 = qcdr(v184);
    stack[-2] = v184;
    v184 = stack[-2];
    v185 = qcar(v184);
    v184 = elt(env, 3); /* !  */
    if (v185 == v184) goto v127;
    v184 = stack[-2];
    v185 = qcar(v184);
    v184 = elt(env, 7); /* !$ */
    v184 = (v185 == v184 ? lisp_true : nil);
    goto v189;

v189:
    if (v184 == nil) goto v132;
    v184 = (Lisp_Object)17; /* 1 */
    stack[-3] = v184;
    goto v132;

v127:
    v184 = qvalue(elt(env, 6)); /* t */
    goto v189;

v44:
    v185 = stack[-3];
    v184 = (Lisp_Object)1; /* 0 */
    if (!(v185 == v184)) goto v187;
    v184 = stack[-2];
    v185 = qcar(v184);
    v184 = stack[0];
    v184 = cons(v185, v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    stack[0] = v184;
    v184 = stack[-2];
    v184 = qcdr(v184);
    stack[-2] = v184;
    v184 = stack[-2];
    v185 = qcar(v184);
    v184 = elt(env, 3); /* !  */
    if (v185 == v184) goto v120;
    v184 = stack[-2];
    v185 = qcar(v184);
    v184 = elt(env, 7); /* !$ */
    v184 = (v185 == v184 ? lisp_true : nil);
    goto v174;

v174:
    if (v184 == nil) goto v44;
    v184 = (Lisp_Object)17; /* 1 */
    stack[-3] = v184;
    goto v44;

v120:
    v184 = qvalue(elt(env, 6)); /* t */
    goto v174;

v147:
    v184 = stack[-2];
    v184 = qcdr(v184);
    stack[-2] = v184;
    goto v14;

v66:
    v184 = stack[-2];
    v184 = qcdr(v184);
    stack[-2] = v184;
    goto v31;
/* error exit handlers */
v186:
    popv(5);
    return nil;
}



/* Code for !*rd2cr */

static Lisp_Object CC_Hrd2cr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *rd2cr");
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
    v106 = v0;
/* end of prologue */
    v11 = v106;
    v11 = qcdr(v11);
    if (!consp(v11)) goto v20;
    v11 = v106;
    goto v95;

v95:
    fn = elt(env, 3); /* convchk */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[0];
    v106 = v11;
    if (!consp(v11)) goto v13;
    v11 = qvalue(elt(env, 2)); /* bfz!* */
    goto v29;

v29:
    {
        popv(1);
        fn = elt(env, 4); /* mkcr */
        return (*qfn2(fn))(qenv(fn), v106, v11);
    }

v13:
    v11 = elt(env, 1); /* 0.0 */
    goto v29;

v20:
    v11 = v106;
    v11 = qcdr(v11);
    goto v95;
/* error exit handlers */
v157:
    popv(1);
    return nil;
}



/* Code for splitcomplex */

static Lisp_Object CC_splitcomplex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v17;
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v17 = qvalue(elt(env, 1)); /* kord!* */
    v139 = qvalue(elt(env, 2)); /* t */
    stack[-4] = qvalue(elt(env, 1)); /* kord!* */
    qvalue(elt(env, 1)) = v17; /* kord!* */
    stack[-3] = qvalue(elt(env, 3)); /* !*exp */
    qvalue(elt(env, 3)) = v139; /* !*exp */
    v17 = elt(env, 4); /* i */
    v139 = elt(env, 5); /* idvalfn */
    v139 = get(v17, v139);
    env = stack[-5];
    if (v139 == nil) goto v59;
    v139 = stack[0];
    fn = elt(env, 6); /* expand!-imrepart */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    goto v9;

v9:
    stack[-2] = v139;
    v139 = stack[-2];
    v139 = qcar(v139);
    fn = elt(env, 7); /* repartf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v139 = stack[-2];
    stack[0] = qcdr(v139);
    v139 = stack[-2];
    v139 = qcar(v139);
    fn = elt(env, 8); /* impartf */
    v17 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v139 = stack[-2];
    v139 = qcdr(v139);
    v139 = cons(v17, v139);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v139 = acons(stack[-1], stack[0], v139);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[-3]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-4]; /* kord!* */
    { popv(6); return onevalue(v139); }

v59:
    v17 = elt(env, 4); /* i */
    v139 = stack[0];
    v139 = Lsmemq(nil, v17, v139);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    if (v139 == nil) goto v74;
    v17 = elt(env, 4); /* i */
    v139 = qvalue(elt(env, 1)); /* kord!* */
    v139 = cons(v17, v139);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    fn = elt(env, 9); /* setkorder */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v139 = stack[0];
    fn = elt(env, 10); /* reorder */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    stack[0] = v139;
    goto v74;

v74:
    v139 = stack[0];
    fn = elt(env, 6); /* expand!-imrepart */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    fn = elt(env, 11); /* subs2 */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    goto v9;
/* error exit handlers */
v133:
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[-3]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-4]; /* kord!* */
    popv(6);
    return nil;
}



/* Code for nestzerop!: */

static Lisp_Object CC_nestzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nestzerop:");
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
    v29 = v0;
/* end of prologue */
    v22 = v29;
    v22 = integerp(v22);
    if (v22 == nil) goto v9;
    v22 = v29;
    fn = elt(env, 1); /* simp */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    errexit();
    goto v96;

v96:
    v22 = qcar(v22);
    v22 = (v22 == nil ? lisp_true : nil);
    return onevalue(v22);

v9:
    v22 = v29;
    v22 = qcdr(v22);
    v22 = qcdr(v22);
    v22 = qcdr(v22);
    goto v96;
}



/* Code for dipretimes */

static Lisp_Object CC_dipretimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v36, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipretimes");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v36 = v0;
/* end of prologue */

v10:
    v151 = v36;
    v37 = qcar(v151);
    v151 = (Lisp_Object)17; /* 1 */
    if (v37 == v151) goto v79;
    v151 = v36;
    v151 = qcdr(v151);
    if (v151 == nil) goto v76;
    v151 = elt(env, 1); /* times */
    return cons(v151, v36);

v76:
    v151 = v36;
    v151 = qcar(v151);
    return onevalue(v151);

v79:
    v151 = v36;
    v151 = qcdr(v151);
    if (v151 == nil) goto v28;
    v151 = v36;
    v151 = qcdr(v151);
    v36 = v151;
    goto v10;

v28:
    v151 = (Lisp_Object)17; /* 1 */
    return onevalue(v151);
}



/* Code for physoppri */

static Lisp_Object CC_physoppri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v220, v221, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physoppri");
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
    stack[-6] = nil;
    v219 = stack[-8];
    if (symbolp(v219)) goto v1;
    v219 = stack[-8];
    v219 = qcar(v219);
    goto v9;

v9:
    stack[-9] = v219;
    v219 = stack[-8];
    if (symbolp(v219)) goto v25;
    v219 = stack[-8];
    v219 = qcdr(v219);
    goto v73;

v73:
    stack[-7] = v219;
    stack[-5] = elt(env, 0); /* physoppri */
    stack[-4] = elt(env, 2); /* "x= " */
    stack[-3] = stack[-9];
    stack[-2] = elt(env, 3); /* " y= " */
    stack[-1] = stack[-7];
    stack[0] = elt(env, 4); /* "nat= " */
    v221 = elt(env, 5); /* !*nat */
    v220 = elt(env, 6); /* " contract= " */
    v219 = elt(env, 7); /* !*contract */
    v219 = list3(v221, v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = list3star(stack[-2], stack[-1], stack[0], v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = list3star(stack[-5], stack[-4], stack[-3], v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    fn = elt(env, 21); /* trwrite */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = qvalue(elt(env, 5)); /* !*nat */
    if (v219 == nil) goto v134;
    v219 = qvalue(elt(env, 7)); /* !*contract */
    if (!(v219 == nil)) goto v134;
    v219 = stack[-9];
    v219 = Lexplode(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lreverse(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    stack[-9] = v219;
    v219 = stack[-9];
    v220 = Llength(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = (Lisp_Object)33; /* 2 */
    v219 = (Lisp_Object)greaterp2(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    v219 = v219 ? lisp_true : nil;
    env = stack[-10];
    if (v219 == nil) goto v224;
    v219 = stack[-9];
    v219 = qcdr(v219);
    v220 = qcar(v219);
    v219 = elt(env, 14); /* !- */
    if (v220 == v219) goto v225;
    v219 = stack[-9];
    v220 = qcar(v219);
    v219 = elt(env, 16); /* !+ */
    if (v220 == v219) goto v226;
    v219 = stack[-9];
    v219 = Lreverse(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lcompress(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    stack[-9] = v219;
    goto v227;

v227:
    stack[0] = elt(env, 8); /* !" */
    v219 = stack[-9];
    v219 = Lexplode(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    stack[0] = cons(stack[0], v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = elt(env, 8); /* !" */
    v219 = ncons(v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lappend(nil, stack[0], v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lcompress(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    stack[-9] = v219;
    v219 = stack[-7];
    if (v219 == nil) goto v228;
    v220 = stack[-9];
    v219 = stack[-7];
    v219 = cons(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    goto v188;

v188:
    stack[-3] = v219;
    stack[-2] = elt(env, 0); /* physoppri */
    stack[-1] = elt(env, 2); /* "x= " */
    stack[0] = stack[-9];
    v222 = elt(env, 17); /* " z= " */
    v221 = stack[-6];
    v220 = elt(env, 18); /* " x1= " */
    v219 = stack[-3];
    v219 = list4(v222, v221, v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = list3star(stack[-2], stack[-1], stack[0], v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    fn = elt(env, 21); /* trwrite */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = stack[-6];
    if (v219 == nil) goto v229;
    v221 = elt(env, 19); /* expt */
    v220 = stack[-3];
    v219 = stack[-6];
    v221 = list3(v221, v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v220 = elt(env, 19); /* expt */
    v219 = elt(env, 20); /* infix */
    v219 = get(v220, v219);
    env = stack[-10];
    fn = elt(env, 22); /* exptpri */
    v219 = (*qfn2(fn))(qenv(fn), v221, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v229:
    v219 = stack[-9];
    fn = elt(env, 23); /* prin2!* */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = stack[-7];
    if (v219 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v219 = elt(env, 9); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v219; /* obrkp!* */
    v221 = elt(env, 11); /* !*comma!* */
    v220 = (Lisp_Object)1; /* 0 */
    v219 = stack[-7];
    fn = elt(env, 24); /* inprint */
    v219 = (*qfnn(fn))(qenv(fn), 3, v221, v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v219; /* obrkp!* */
    v219 = elt(env, 13); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v228:
    v219 = stack[-9];
    goto v188;

v226:
    v219 = elt(env, 16); /* !+ */
    stack[-6] = v219;
    v220 = stack[-9];
    v219 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 25); /* pnth */
    v219 = (*qfn2(fn))(qenv(fn), v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lreverse(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lcompress(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    stack[-9] = v219;
    goto v227;

v225:
    v220 = elt(env, 14); /* !- */
    v219 = elt(env, 15); /* !1 */
    v219 = list2(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lcompress(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    stack[-6] = v219;
    v220 = stack[-9];
    v219 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 25); /* pnth */
    v219 = (*qfn2(fn))(qenv(fn), v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lreverse(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lcompress(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    stack[-9] = v219;
    goto v227;

v224:
    v219 = stack[-9];
    v219 = Lreverse(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lcompress(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    stack[-9] = v219;
    goto v227;

v134:
    stack[0] = elt(env, 8); /* !" */
    v219 = stack[-9];
    v219 = Lexplode(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    stack[0] = cons(stack[0], v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = elt(env, 8); /* !" */
    v219 = ncons(v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lappend(nil, stack[0], v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = Lcompress(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    stack[-9] = v219;
    v219 = stack[-9];
    fn = elt(env, 23); /* prin2!* */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = stack[-7];
    if (v219 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v219 = elt(env, 9); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v219; /* obrkp!* */
    v221 = elt(env, 11); /* !*comma!* */
    v220 = (Lisp_Object)1; /* 0 */
    v219 = stack[-7];
    fn = elt(env, 24); /* inprint */
    v219 = (*qfnn(fn))(qenv(fn), 3, v221, v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-10];
    v219 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v219; /* obrkp!* */
    v219 = elt(env, 13); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v223;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v25:
    v219 = qvalue(elt(env, 1)); /* nil */
    goto v73;

v1:
    v219 = stack[-8];
    goto v9;
/* error exit handlers */
v223:
    popv(11);
    return nil;
}



/* Code for zeros */

static Lisp_Object CC_zeros(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v11;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zeros");
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
    v59 = v0;
/* end of prologue */

v95:
    v58 = v59;
    if (v58 == nil) goto v79;
    v58 = v59;
    v11 = qcar(v58);
    v58 = (Lisp_Object)1; /* 0 */
    if (v11 == v58) goto v1;
    v58 = v59;
    v58 = qcdr(v58);
    v59 = v58;
    goto v95;

v1:
    v58 = v59;
    v58 = qcdr(v58);
    v58 = CC_zeros(env, v58);
    errexit();
    return add1(v58);

v79:
    v58 = (Lisp_Object)1; /* 0 */
    return onevalue(v58);
}



/* Code for listminimize */

static Lisp_Object CC_listminimize(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v13, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listminimize");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v21;
    v13 = v0;
/* end of prologue */
    v28 = v13;
    if (v28 == nil) goto v20;
    v28 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* cali!=min */
    v27 = (*qfnn(fn))(qenv(fn), 3, v28, v13, v27);
    errexit();
        return Lreverse(nil, v27);

v20:
    v27 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v27);
}



/* Code for general!-modular!-difference */

static Lisp_Object CC_generalKmodularKdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-difference");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v12 = v21;
    v30 = v0;
/* end of prologue */
    v12 = difference2(v30, v12);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    stack[0] = v12;
    v30 = stack[0];
    v12 = (Lisp_Object)1; /* 0 */
    v12 = (Lisp_Object)lessp2(v30, v12);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v12 = v12 ? lisp_true : nil;
    env = stack[-1];
    if (v12 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v30 = stack[0];
    v12 = qvalue(elt(env, 1)); /* current!-modulus */
    v12 = plus2(v30, v12);
    nil = C_nil;
    if (exception_pending()) goto v75;
    stack[0] = v12;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v75:
    popv(2);
    return nil;
}



/* Code for ofsf_qesubqat */

static Lisp_Object MS_CDECL CC_ofsf_qesubqat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v21,
                         Lisp_Object v39, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v145, v224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_qesubqat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_qesubqat");
#endif
    if (stack >= stacklimit)
    {
        push3(v39,v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v21,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v39;
    stack[-1] = v21;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = stack[-1];
    v179 = stack[-2];
    fn = elt(env, 8); /* ofsf_varlat */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v179 = Lmemq(nil, stack[-3], v179);
    if (v179 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v179 = stack[-2];
    v179 = qcdr(v179);
    stack[-3] = qcar(v179);
    v179 = stack[0];
    v179 = qcar(v179);
    if (v179 == nil) goto v35;
    v145 = stack[0];
    v179 = elt(env, 1); /* prepf */
    fn = elt(env, 9); /* sqform */
    v179 = (*qfn2(fn))(qenv(fn), v145, v179);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    goto v31;

v31:
    v179 = cons(stack[-1], v179);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v179 = ncons(v179);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    fn = elt(env, 10); /* subf */
    v179 = (*qfn2(fn))(qenv(fn), stack[-3], v179);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    stack[-1] = v179;
    v179 = stack[-2];
    v179 = qcar(v179);
    stack[0] = v179;
    v179 = qvalue(elt(env, 2)); /* !*rlqelocal */
    if (v179 == nil) goto v55;
    v145 = stack[0];
    v179 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); /* ofsf_qesubqat!-local */
        return (*qfn2(fn))(qenv(fn), v145, v179);
    }

v55:
    v145 = stack[0];
    v179 = elt(env, 3); /* equal */
    if (v145 == v179) goto v156;
    v145 = stack[0];
    v179 = elt(env, 5); /* neq */
    if (v145 == v179) goto v71;
    v224 = elt(env, 6); /* geq */
    v179 = stack[-1];
    v145 = qcdr(v179);
    v179 = qvalue(elt(env, 7)); /* nil */
    v145 = list3(v224, v145, v179);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v179 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 12); /* ofsf_surep */
    v179 = (*qfn2(fn))(qenv(fn), v145, v179);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    goto v104;

v104:
    if (v179 == nil) goto v57;
    v145 = stack[0];
    v179 = stack[-1];
    v179 = qcar(v179);
    v224 = qvalue(elt(env, 7)); /* nil */
    popv(5);
    return list3(v145, v179, v224);

v57:
    v179 = stack[-1];
    v179 = qcdr(v179);
    fn = elt(env, 13); /* sfto_pdecf */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v179 = qcar(v179);
    stack[-2] = v179;
    v224 = elt(env, 6); /* geq */
    v145 = stack[-2];
    v179 = qvalue(elt(env, 7)); /* nil */
    v145 = list3(v224, v145, v179);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v179 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 12); /* ofsf_surep */
    v179 = (*qfn2(fn))(qenv(fn), v145, v179);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    if (v179 == nil) goto v120;
    v145 = stack[0];
    v179 = stack[-1];
    v179 = qcar(v179);
    v224 = qvalue(elt(env, 7)); /* nil */
    popv(5);
    return list3(v145, v179, v224);

v120:
    v179 = stack[-1];
    v145 = qcar(v179);
    v179 = stack[-2];
    fn = elt(env, 14); /* multf */
    v179 = (*qfn2(fn))(qenv(fn), v145, v179);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v145 = qvalue(elt(env, 7)); /* nil */
    {
        Lisp_Object v234 = stack[0];
        popv(5);
        return list3(v234, v179, v145);
    }

v71:
    v179 = qvalue(elt(env, 4)); /* t */
    goto v104;

v156:
    v179 = qvalue(elt(env, 4)); /* t */
    goto v104;

v35:
    v179 = (Lisp_Object)1; /* 0 */
    goto v31;
/* error exit handlers */
v117:
    popv(5);
    return nil;
}



/* Code for pasf_premf */

static Lisp_Object CC_pasf_premf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_premf");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    v22 = v0;
/* end of prologue */
    v29 = v22;
    v22 = stack[0];
    fn = elt(env, 1); /* remf */
    v29 = (*qfn2(fn))(qenv(fn), v29, v22);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v22 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* pasf_premf1 */
        return (*qfn2(fn))(qenv(fn), v29, v22);
    }
/* error exit handlers */
v25:
    popv(2);
    return nil;
}



/* Code for pasf_floor */

static Lisp_Object CC_pasf_floor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v158, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_floor");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */
    v72 = stack[-1];
    if (!consp(v72)) goto v18;
    v72 = stack[-1];
    v72 = qcar(v72);
    v72 = (consp(v72) ? nil : lisp_true);
    goto v32;

v32:
    if (v72 == nil) goto v157;
    v72 = stack[0];
    if (!consp(v72)) goto v13;
    v72 = stack[0];
    v72 = qcar(v72);
    v72 = (consp(v72) ? nil : lisp_true);
    goto v8;

v8:
    if (v72 == nil) goto v239;
    v72 = stack[-1];
    if (v72 == nil) goto v75;
    v158 = stack[-1];
    v72 = stack[0];
    v158 = Cremainder(v158, v72);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    v72 = (Lisp_Object)1; /* 0 */
    if (v158 == v72) goto v109;
    v158 = stack[-1];
    v72 = stack[0];
    v158 = times2(v158, v72);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    v72 = (Lisp_Object)1; /* 0 */
    v72 = (Lisp_Object)greaterp2(v158, v72);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v72 = v72 ? lisp_true : nil;
    env = stack[-2];
    if (v72 == nil) goto v92;
    v158 = stack[-1];
    v72 = stack[0];
    v72 = quot2(v158, v72);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    goto v37;

v37:
    fn = elt(env, 5); /* simp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v72 = qcar(v72);
    { popv(3); return onevalue(v72); }

v92:
    v158 = stack[-1];
    v72 = stack[0];
    v72 = quot2(v158, v72);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    v72 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    goto v37;

v109:
    v158 = stack[-1];
    v72 = stack[0];
    v72 = quot2(v158, v72);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    goto v37;

v75:
    v72 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v72); }

v239:
    v72 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v72 == nil)) goto v217;
    v159 = elt(env, 4); /* "pasf_floor: not a domain valued sf in input" 
*/
    v158 = stack[-1];
    v72 = stack[0];
    v72 = list3(v159, v158, v72);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    fn = elt(env, 6); /* lprie */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    goto v217;

v217:
    v72 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v72 = nil;
    { popv(3); return onevalue(v72); }

v13:
    v72 = qvalue(elt(env, 1)); /* t */
    goto v8;

v157:
    v72 = qvalue(elt(env, 2)); /* nil */
    goto v8;

v18:
    v72 = qvalue(elt(env, 1)); /* t */
    goto v32;
/* error exit handlers */
v90:
    popv(3);
    return nil;
}



/* Code for cd_ordatp */

static Lisp_Object CC_cd_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v141, v139, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cd_ordatp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v139 = v21;
    v17 = v0;
/* end of prologue */
    v57 = v17;
    v141 = qcar(v57);
    v57 = elt(env, 1); /* neq */
    if (v141 == v57) goto v29;
    v57 = qvalue(elt(env, 3)); /* nil */
    goto v8;

v8:
    if (v57 == nil) goto v75;
    v57 = qvalue(elt(env, 4)); /* t */
    return onevalue(v57);

v75:
    v57 = v17;
    v141 = qcar(v57);
    v57 = elt(env, 2); /* equal */
    if (v141 == v57) goto v37;
    v57 = qvalue(elt(env, 3)); /* nil */
    goto v12;

v12:
    if (v57 == nil) goto v103;
    v57 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v57);

v103:
    v57 = v17;
    v57 = qcdr(v57);
    v57 = qcar(v57);
    v141 = v139;
    v141 = qcdr(v141);
    v141 = qcar(v141);
    {
        fn = elt(env, 5); /* ordp */
        return (*qfn2(fn))(qenv(fn), v57, v141);
    }

v37:
    v57 = v139;
    v141 = qcar(v57);
    v57 = elt(env, 1); /* neq */
    v57 = (v141 == v57 ? lisp_true : nil);
    goto v12;

v29:
    v57 = v139;
    v141 = qcar(v57);
    v57 = elt(env, 2); /* equal */
    v57 = (v141 == v57 ? lisp_true : nil);
    goto v8;
}



/* Code for matrixrd */

static Lisp_Object MS_CDECL CC_matrixrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49;
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
    v48 = (Lisp_Object)1; /* 0 */
    stack[-1] = v48;
    v48 = nil;
    stack[0] = v48;
    goto v24;

v24:
    v49 = stack[-1];
    v48 = (Lisp_Object)1; /* 0 */
    if (v49 == v48) goto v18;
    v49 = elt(env, 6); /* mat */
    v48 = stack[0];
    v48 = cons(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* aeval */
        return (*qfn1(fn))(qenv(fn), v48);
    }

v18:
    fn = elt(env, 8); /* lex */
    v48 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-2];
    v49 = qvalue(elt(env, 2)); /* char */
    v48 = elt(env, 3); /* (m a t r i x r o w) */
    if (equal(v49, v48)) goto v107;
    v48 = (Lisp_Object)17; /* 1 */
    stack[-1] = v48;
    goto v24;

v107:
    fn = elt(env, 9); /* matrixrowrd */
    v48 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-2];
    v49 = v48;
    v48 = stack[0];
    if (v48 == nil) goto v4;
    v48 = v49;
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-2];
    v48 = Lappend(nil, stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-2];
    stack[0] = v48;
    goto v67;

v67:
    v49 = qvalue(elt(env, 2)); /* char */
    v48 = elt(env, 4); /* (!/ m a t r i x r o w) */
    if (equal(v49, v48)) goto v24;
    v49 = elt(env, 5); /* "</matrixrow>" */
    v48 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 10); /* errorml */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-2];
    goto v24;

v4:
    v48 = v49;
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-2];
    stack[0] = v48;
    goto v67;
/* error exit handlers */
v155:
    popv(3);
    return nil;
}



/* Code for look_for_rational */

static Lisp_Object MS_CDECL CC_look_for_rational(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v21,
                         Lisp_Object v39, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v225, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "look_for_rational");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for look_for_rational");
#endif
    if (stack >= stacklimit)
    {
        push3(v39,v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v21,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v39;
    stack[-1] = v21;
    stack[-2] = v0;
/* end of prologue */
    v241 = stack[0];
    v225 = qcar(v241);
    v241 = elt(env, 1); /* sqrt */
    if (v225 == v241) goto v73;
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v10;

v10:
    if (v241 == nil) goto v3;
    v142 = stack[-2];
    v225 = stack[-1];
    v241 = (Lisp_Object)33; /* 2 */
    {
        popv(4);
        fn = elt(env, 5); /* look_for_rational1 */
        return (*qfnn(fn))(qenv(fn), 3, v142, v225, v241);
    }

v3:
    v241 = stack[0];
    v225 = qcar(v241);
    v241 = elt(env, 3); /* expt */
    if (v225 == v241) goto v103;
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v38;

v38:
    if (v241 == nil) goto v122;
    v142 = stack[-2];
    v225 = stack[-1];
    v241 = stack[0];
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    {
        popv(4);
        fn = elt(env, 5); /* look_for_rational1 */
        return (*qfnn(fn))(qenv(fn), 3, v142, v225, v241);
    }

v122:
    v241 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v241); }

v103:
    v241 = stack[0];
    v241 = qcdr(v241);
    v225 = qcar(v241);
    v241 = stack[-1];
    if (equal(v225, v241)) goto v238;
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v38;

v238:
    v241 = stack[0];
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    fn = elt(env, 6); /* listp */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    if (v241 == nil) goto v57;
    v241 = stack[0];
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    v225 = qcar(v241);
    v241 = elt(env, 4); /* quotient */
    if (v225 == v241) goto v94;
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v38;

v94:
    v241 = stack[0];
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    if (is_number(v241)) goto v162;
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v38;

v162:
    v241 = stack[0];
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    v241 = (is_number(v241) ? lisp_true : nil);
    goto v38;

v57:
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v38;

v73:
    v241 = stack[0];
    v241 = qcdr(v241);
    v225 = qcar(v241);
    v241 = stack[-1];
    v241 = (equal(v225, v241) ? lisp_true : nil);
    goto v10;
/* error exit handlers */
v46:
    popv(4);
    return nil;
}



/* Code for listeq */

static Lisp_Object CC_listeq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listeq");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */

v20:
    v37 = stack[-1];
    if (!consp(v37)) goto v1;
    v37 = stack[0];
    if (!consp(v37)) goto v29;
    v37 = stack[-1];
    v38 = qcar(v37);
    v37 = stack[0];
    v37 = qcar(v37);
    v37 = CC_listeq(env, v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-2];
    if (v37 == nil) goto v77;
    v37 = stack[-1];
    v37 = qcdr(v37);
    stack[-1] = v37;
    v37 = stack[0];
    v37 = qcdr(v37);
    stack[0] = v37;
    goto v20;

v77:
    v37 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v37); }

v29:
    v37 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v37); }

v1:
    v38 = stack[-1];
    v37 = stack[0];
    v37 = (v38 == v37 ? lisp_true : nil);
    { popv(3); return onevalue(v37); }
/* error exit handlers */
v3:
    popv(3);
    return nil;
}



/* Code for evequal */

static Lisp_Object CC_evequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v67, v238, v5, v103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evequal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v238 = v21;
    v5 = v0;
/* end of prologue */

v20:
    v80 = v5;
    if (v80 == nil) goto v32;
    v80 = qvalue(elt(env, 1)); /* nil */
    goto v1;

v1:
    if (v80 == nil) goto v10;
    v80 = qvalue(elt(env, 2)); /* t */
    return onevalue(v80);

v10:
    v80 = v5;
    if (v80 == nil) goto v25;
    v80 = v238;
    if (v80 == nil) goto v28;
    v103 = (Lisp_Object)1; /* 0 */
    v80 = v5;
    v67 = qcar(v80);
    v80 = v238;
    v80 = qcar(v80);
    v80 = (Lisp_Object)(int32_t)((int32_t)v67 - (int32_t)v80 + TAG_FIXNUM);
    if (v103 == v80) goto v157;
    v80 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v80);

v157:
    v80 = v5;
    v80 = qcdr(v80);
    v5 = v80;
    v80 = v238;
    v80 = qcdr(v80);
    v238 = v80;
    goto v20;

v28:
    v80 = elt(env, 3); /* (0) */
    v238 = v80;
    goto v20;

v25:
    v80 = elt(env, 3); /* (0) */
    v5 = v80;
    goto v20;

v32:
    v80 = v238;
    v80 = (v80 == nil ? lisp_true : nil);
    goto v1;
}



/* Code for color!-strand */

static Lisp_Object MS_CDECL CC_colorKstrand(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v21,
                         Lisp_Object v39, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "color-strand");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for color-strand");
#endif
    if (stack >= stacklimit)
    {
        push3(v39,v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v21,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v39;
    stack[-1] = v21;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v79;

v79:
    v19 = stack[-1];
    if (v19 == nil) goto v9;
    v34 = stack[-2];
    v19 = stack[-1];
    v19 = qcar(v19);
    fn = elt(env, 1); /* color!-roads */
    v35 = (*qfn2(fn))(qenv(fn), v34, v19);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-4];
    v34 = stack[0];
    v19 = stack[-3];
    v19 = acons(v35, v34, v19);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-4];
    stack[-3] = v19;
    v19 = stack[-1];
    v19 = qcdr(v19);
    stack[-1] = v19;
    v19 = stack[0];
    v19 = add1(v19);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-4];
    stack[0] = v19;
    goto v79;

v9:
    v19 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v19);
    }
/* error exit handlers */
v38:
    popv(5);
    return nil;
}



/* Code for quotofd */

static Lisp_Object CC_quotofd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotofd");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v21;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v68;

v68:
    v92 = stack[-2];
    if (v92 == nil) goto v10;
    v92 = stack[-2];
    if (!consp(v92)) goto v22;
    v92 = stack[-2];
    v92 = qcar(v92);
    v92 = (consp(v92) ? nil : lisp_true);
    goto v16;

v16:
    if (v92 == nil) goto v104;
    v92 = stack[-2];
    if (!consp(v92)) goto v157;
    v92 = qvalue(elt(env, 2)); /* nil */
    goto v106;

v106:
    if (v92 == nil) goto v238;
    stack[0] = stack[-3];
    v132 = stack[-2];
    v92 = stack[-1];
    fn = elt(env, 3); /* mkrn */
    v92 = (*qfn2(fn))(qenv(fn), v132, v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    fn = elt(env, 4); /* int!-equiv!-chk */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    {
        Lisp_Object v152 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v152, v92);
    }

v238:
    stack[0] = stack[-3];
    v132 = stack[-2];
    v92 = stack[-1];
    fn = elt(env, 6); /* lowest!-terms */
    v92 = (*qfn2(fn))(qenv(fn), v132, v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    {
        Lisp_Object v239 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v239, v92);
    }

v157:
    v92 = stack[-1];
    v92 = (consp(v92) ? nil : lisp_true);
    goto v106;

v104:
    v92 = stack[-2];
    v92 = qcar(v92);
    stack[0] = qcar(v92);
    v92 = stack[-2];
    v92 = qcar(v92);
    v132 = qcdr(v92);
    v92 = stack[-1];
    v132 = CC_quotofd(env, v132, v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v92 = stack[-3];
    v92 = acons(stack[0], v132, v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    stack[-3] = v92;
    v92 = stack[-2];
    v92 = qcdr(v92);
    stack[-2] = v92;
    goto v68;

v22:
    v92 = qvalue(elt(env, 1)); /* t */
    goto v16;

v10:
    v92 = stack[-3];
    {
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v92);
    }
/* error exit handlers */
v105:
    popv(5);
    return nil;
}



/* Code for subsq */

static Lisp_Object CC_subsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */
    v14 = stack[-1];
    v15 = qcar(v14);
    v14 = stack[0];
    fn = elt(env, 4); /* subf */
    v14 = (*qfn2(fn))(qenv(fn), v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[-2] = v14;
    v14 = stack[-1];
    v15 = qcdr(v14);
    v14 = stack[0];
    fn = elt(env, 4); /* subf */
    v14 = (*qfn2(fn))(qenv(fn), v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[-1] = v14;
    v14 = stack[-1];
    fn = elt(env, 5); /* subs2!* */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v14 = qcar(v14);
    if (!(v14 == nil)) goto v5;
    v14 = stack[-2];
    fn = elt(env, 5); /* subs2!* */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v14 = qcar(v14);
    if (v14 == nil) goto v157;
    v14 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v14 == nil)) goto v60;
    v14 = elt(env, 3); /* "Zero divisor" */
    fn = elt(env, 6); /* lprie */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    goto v60;

v60:
    v14 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    goto v5;

v5:
    stack[0] = stack[-2];
    v14 = stack[-1];
    fn = elt(env, 7); /* invsq */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    {
        Lisp_Object v139 = stack[0];
        popv(4);
        fn = elt(env, 8); /* multsq */
        return (*qfn2(fn))(qenv(fn), v139, v14);
    }

v157:
    v14 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v14 == nil)) goto v34;
    v14 = elt(env, 2); /* "0/0 formed" */
    fn = elt(env, 6); /* lprie */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    goto v34;

v34:
    v14 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    goto v5;
/* error exit handlers */
v141:
    popv(4);
    return nil;
}



/* Code for red!=subst1 */

static Lisp_Object CC_redMsubst1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v180, v179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=subst1");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v21;
    stack[-6] = v0;
/* end of prologue */
    v230 = stack[-6];
    fn = elt(env, 5); /* bas_dpoly */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[0] = v230;
    v230 = stack[0];
    fn = elt(env, 6); /* dp_lc */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[-1] = v230;
    v230 = stack[-6];
    fn = elt(env, 7); /* bas_rep */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[-7] = v230;
    v230 = stack[-5];
    fn = elt(env, 5); /* bas_dpoly */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[-3] = v230;
    v230 = stack[-3];
    fn = elt(env, 6); /* dp_lc */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[-2] = v230;
    v230 = qvalue(elt(env, 1)); /* !*bcsimp */
    if (v230 == nil) goto v141;
    v230 = stack[-2];
    fn = elt(env, 8); /* bc_inv */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[-4] = v230;
    if (v230 == nil) goto v78;
    v180 = stack[-1];
    v230 = stack[-4];
    fn = elt(env, 9); /* bc_prod */
    v230 = (*qfn2(fn))(qenv(fn), v180, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[-1] = v230;
    v230 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* bc_fi */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[-2] = v230;
    goto v141;

v141:
    v230 = stack[0];
    fn = elt(env, 11); /* dp_lmon */
    stack[-4] = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    v230 = stack[-3];
    fn = elt(env, 11); /* dp_lmon */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    fn = elt(env, 12); /* mo_diff */
    v230 = (*qfn2(fn))(qenv(fn), stack[-4], v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[-4] = v230;
    v180 = stack[-2];
    v230 = stack[0];
    fn = elt(env, 13); /* dp_times_bc */
    stack[0] = (*qfn2(fn))(qenv(fn), v180, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    v179 = stack[-1];
    v180 = stack[-4];
    v230 = stack[-3];
    fn = elt(env, 14); /* dp_times_bcmo */
    v230 = (*qfnn(fn))(qenv(fn), 3, v179, v180, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    fn = elt(env, 15); /* dp_diff */
    v230 = (*qfn2(fn))(qenv(fn), stack[0], v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[0] = v230;
    v180 = stack[-2];
    v230 = stack[-7];
    fn = elt(env, 13); /* dp_times_bc */
    stack[-2] = (*qfn2(fn))(qenv(fn), v180, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    v230 = stack[-5];
    fn = elt(env, 7); /* bas_rep */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    fn = elt(env, 14); /* dp_times_bcmo */
    v230 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-4], v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    fn = elt(env, 15); /* dp_diff */
    v230 = (*qfn2(fn))(qenv(fn), stack[-2], v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[-1] = v230;
    fn = elt(env, 16); /* cali_trace */
    v180 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    v230 = (Lisp_Object)1265; /* 79 */
    v230 = (Lisp_Object)greaterp2(v180, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    v230 = v230 ? lisp_true : nil;
    env = stack[-8];
    if (v230 == nil) goto v243;
    v230 = elt(env, 2); /* "---> " */
    v230 = Lprinc(nil, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    v230 = stack[0];
    fn = elt(env, 17); /* dp_print */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    goto v226;

v226:
    fn = elt(env, 16); /* cali_trace */
    v180 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    v230 = (Lisp_Object)1425; /* 89 */
    v230 = (Lisp_Object)greaterp2(v180, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    v230 = v230 ? lisp_true : nil;
    env = stack[-8];
    if (v230 == nil) goto v99;
    v230 = elt(env, 4); /* " uses " */
    v230 = Lprinc(nil, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    v230 = stack[-3];
    fn = elt(env, 17); /* dp_print */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    goto v99;

v99:
    v230 = stack[-6];
    fn = elt(env, 18); /* bas_nr */
    v179 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    v180 = stack[0];
    v230 = stack[-1];
    {
        popv(9);
        fn = elt(env, 19); /* bas_make1 */
        return (*qfnn(fn))(qenv(fn), 3, v179, v180, v230);
    }

v243:
    fn = elt(env, 16); /* cali_trace */
    v180 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    v230 = (Lisp_Object)1; /* 0 */
    v230 = (Lisp_Object)greaterp2(v180, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    v230 = v230 ? lisp_true : nil;
    env = stack[-8];
    if (v230 == nil) goto v226;
    v230 = elt(env, 3); /* "." */
    v230 = Lprinc(nil, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    goto v226;

v78:
    v180 = stack[-2];
    v230 = stack[-1];
    fn = elt(env, 20); /* bc_gcd */
    v230 = (*qfn2(fn))(qenv(fn), v180, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    stack[-4] = v230;
    v180 = stack[-2];
    v230 = stack[-4];
    fn = elt(env, 21); /* bc_divmod */
    v230 = (*qfn2(fn))(qenv(fn), v180, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    v230 = qcar(v230);
    stack[-2] = v230;
    v180 = stack[-1];
    v230 = stack[-4];
    fn = elt(env, 21); /* bc_divmod */
    v230 = (*qfn2(fn))(qenv(fn), v180, v230);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-8];
    v230 = qcar(v230);
    stack[-1] = v230;
    goto v141;
/* error exit handlers */
v242:
    popv(9);
    return nil;
}



/* Code for mkindxlist */

static Lisp_Object CC_mkindxlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkindxlist");
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
    v244 = v0;
/* end of prologue */
    stack[-4] = v244;
    v244 = stack[-4];
    if (v244 == nil) goto v1;
    v244 = stack[-4];
    v244 = qcar(v244);
    v235 = v244;
    v244 = v235;
    v244 = integerp(v244);
    if (v244 == nil) goto v26;
    v244 = v235;
    fn = elt(env, 3); /* !*num2id */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    goto v73;

v73:
    v244 = ncons(v244);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    stack[-2] = v244;
    stack[-3] = v244;
    goto v79;

v79:
    v244 = stack[-4];
    v244 = qcdr(v244);
    stack[-4] = v244;
    v244 = stack[-4];
    if (v244 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v244 = stack[-4];
    v244 = qcar(v244);
    v235 = v244;
    v244 = v235;
    v244 = integerp(v244);
    if (v244 == nil) goto v57;
    v244 = v235;
    fn = elt(env, 3); /* !*num2id */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    goto v160;

v160:
    v244 = ncons(v244);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    v244 = Lrplacd(nil, stack[-1], v244);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    v244 = stack[-2];
    v244 = qcdr(v244);
    stack[-2] = v244;
    goto v79;

v57:
    v244 = v235;
    v244 = Lconsp(nil, v244);
    env = stack[-5];
    if (v244 == nil) goto v91;
    v244 = v235;
    v244 = qcdr(v244);
    v244 = qcar(v244);
    v244 = integerp(v244);
    if (v244 == nil) goto v91;
    stack[0] = elt(env, 2); /* minus */
    v244 = v235;
    v244 = qcdr(v244);
    v244 = qcar(v244);
    fn = elt(env, 3); /* !*num2id */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    v244 = list2(stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    goto v160;

v91:
    v244 = v235;
    goto v160;

v26:
    v244 = v235;
    v244 = Lconsp(nil, v244);
    env = stack[-5];
    if (v244 == nil) goto v78;
    v244 = v235;
    v244 = qcdr(v244);
    v244 = qcar(v244);
    v244 = integerp(v244);
    if (v244 == nil) goto v78;
    stack[0] = elt(env, 2); /* minus */
    v244 = v235;
    v244 = qcdr(v244);
    v244 = qcar(v244);
    fn = elt(env, 3); /* !*num2id */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    v244 = list2(stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-5];
    goto v73;

v78:
    v244 = v235;
    goto v73;

v1:
    v244 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v244); }
/* error exit handlers */
v129:
    popv(6);
    return nil;
}



/* Code for simpsqrt3 */

static Lisp_Object CC_simpsqrt3(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v57, v141;
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
    v57 = stack[0];
    v149 = qvalue(elt(env, 1)); /* listofallsqrts */
    v149 = Lassoc(nil, v57, v149);
    stack[-1] = v149;
    v149 = stack[-1];
    if (v149 == nil) goto v25;
    v149 = stack[-1];
    v149 = qcdr(v149);
    { popv(3); return onevalue(v149); }

v25:
    v57 = qvalue(elt(env, 2)); /* listofnewsqrts */
    v149 = qvalue(elt(env, 3)); /* knowntobeindep */
    v149 = Latsoc(nil, v57, v149);
    stack[-1] = v149;
    v149 = stack[-1];
    if (v149 == nil) goto v20;
    v57 = stack[0];
    v149 = stack[-1];
    v149 = qcdr(v149);
    v149 = Lassoc(nil, v57, v149);
    stack[-1] = v149;
    v149 = stack[-1];
    if (v149 == nil) goto v20;
    v57 = stack[-1];
    v149 = qvalue(elt(env, 1)); /* listofallsqrts */
    v149 = cons(v57, v149);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-2];
    qvalue(elt(env, 1)) = v149; /* listofallsqrts */
    v149 = stack[-1];
    v149 = qcdr(v149);
    { popv(3); return onevalue(v149); }

v20:
    v149 = stack[0];
    fn = elt(env, 4); /* actualsimpsqrt */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-2];
    stack[-1] = v149;
    v141 = stack[0];
    v57 = stack[-1];
    v149 = qvalue(elt(env, 1)); /* listofallsqrts */
    v149 = acons(v141, v57, v149);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-2];
    qvalue(elt(env, 1)) = v149; /* listofallsqrts */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v104:
    popv(3);
    return nil;
}



/* Code for rtrnda */

static Lisp_Object CC_rtrnda(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v150, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rtrnda");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v150 = v21;
    stack[0] = v0;
/* end of prologue */
    v218 = stack[0];
    if (!consp(v218)) goto v10;
    v218 = stack[0];
    v218 = qcdr(v218);
    v80 = qcar(v218);
    v218 = (Lisp_Object)1; /* 0 */
    v218 = (v80 == v218 ? lisp_true : nil);
    goto v8;

v8:
    if (v218 == nil) goto v75;
    v150 = (Lisp_Object)1; /* 0 */
    v218 = (Lisp_Object)1; /* 0 */
    v218 = cons(v150, v218);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-1];
    qvalue(elt(env, 1)) = v218; /* rlval!# */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v75:
    v218 = stack[0];
    fn = elt(env, 2); /* round!:dec1 */
    v218 = (*qfn2(fn))(qenv(fn), v218, v150);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-1];
    v150 = v218;
    qvalue(elt(env, 1)) = v150; /* rlval!# */
    v150 = qcar(v150);
    v218 = qcdr(v218);
    {
        popv(2);
        fn = elt(env, 3); /* decimal2internal */
        return (*qfn2(fn))(qenv(fn), v150, v218);
    }

v10:
    v218 = stack[0];
    v218 = (Lisp_Object)zerop(v218);
    v218 = v218 ? lisp_true : nil;
    env = stack[-1];
    goto v8;
/* error exit handlers */
v238:
    popv(2);
    return nil;
}



/* Code for !*s2i */

static Lisp_Object CC_Hs2i(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *s2i");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v73 = v0;
/* end of prologue */
    v29 = v73;
    v29 = integerp(v29);
    if (!(v29 == nil)) return onevalue(v73);
    v29 = elt(env, 1); /* "integer" */
    {
        fn = elt(env, 2); /* typerr */
        return (*qfn2(fn))(qenv(fn), v73, v29);
    }
}



/* Code for even_action_pow */

static Lisp_Object MS_CDECL CC_even_action_pow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v21,
                         Lisp_Object v39, Lisp_Object v96, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v171, v61, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "even_action_pow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for even_action_pow");
#endif
    if (stack >= stacklimit)
    {
        push4(v96,v39,v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v21,v39,v96);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v96;
    stack[-3] = v39;
    stack[-4] = v21;
    v62 = v0;
/* end of prologue */
    v169 = stack[-4];
    v169 = qcar(v169);
    v61 = v169;
    v169 = stack[-4];
    v169 = qcdr(v169);
    stack[-1] = v169;
    v171 = v61;
    v169 = v62;
    v169 = Lassoc(nil, v171, v169);
    stack[0] = v169;
    if (v169 == nil) goto v71;
    v171 = stack[-1];
    v169 = (Lisp_Object)17; /* 1 */
    if (v171 == v169) goto v34;
    stack[-4] = v61;
    v169 = stack[-1];
    v171 = sub1(v169);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    v169 = stack[-1];
    v61 = acons(stack[-4], v171, v169);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    v171 = qvalue(elt(env, 1)); /* nil */
    v169 = (Lisp_Object)17; /* 1 */
    v169 = acons(v61, v171, v169);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    goto v57;

v57:
    v61 = stack[0];
    v171 = stack[-3];
    fn = elt(env, 2); /* component_action */
    v169 = (*qfnn(fn))(qenv(fn), 3, v61, v171, v169);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    stack[0] = v169;
    v171 = stack[0];
    v169 = stack[-2];
    {
        popv(7);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v171, v169);
    }

v34:
    v171 = (Lisp_Object)17; /* 1 */
    v169 = (Lisp_Object)17; /* 1 */
    v169 = cons(v171, v169);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    goto v57;

v71:
    v171 = v61;
    v61 = v62;
    v169 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* find_active_components */
    v169 = (*qfnn(fn))(qenv(fn), 3, v171, v61, v169);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    stack[-1] = v169;
    v171 = qvalue(elt(env, 1)); /* nil */
    v169 = (Lisp_Object)17; /* 1 */
    v169 = cons(v171, v169);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    stack[0] = v169;
    v169 = stack[-1];
    stack[-5] = v169;
    goto v217;

v217:
    v169 = stack[-5];
    if (v169 == nil) goto v46;
    v169 = stack[-5];
    v169 = qcar(v169);
    stack[-1] = v169;
    v171 = stack[-4];
    v169 = stack[-1];
    v169 = qcar(v169);
    fn = elt(env, 5); /* diffp */
    v169 = (*qfn2(fn))(qenv(fn), v171, v169);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    v61 = stack[-1];
    v171 = stack[-3];
    fn = elt(env, 2); /* component_action */
    v169 = (*qfnn(fn))(qenv(fn), 3, v61, v171, v169);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    fn = elt(env, 6); /* addsq */
    v169 = (*qfn2(fn))(qenv(fn), stack[0], v169);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-6];
    stack[0] = v169;
    v169 = stack[-5];
    v169 = qcdr(v169);
    stack[-5] = v169;
    goto v217;

v46:
    v171 = stack[0];
    v169 = stack[-2];
    {
        popv(7);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v171, v169);
    }
/* error exit handlers */
v168:
    popv(7);
    return nil;
}



setup_type const u37_setup[] =
{
    {"dp_neworder",             CC_dp_neworder, too_many_1,    wrong_no_1},
    {"test-bool",               CC_testKbool,   too_many_1,    wrong_no_1},
    {"can_rep_cell",            too_few_2,      CC_can_rep_cell,wrong_no_2},
    {"rl_qe",                   too_few_2,      CC_rl_qe,      wrong_no_2},
    {"checkexp",                too_few_2,      CC_checkexp,   wrong_no_2},
    {"null+vec+p",              CC_nullLvecLp,  too_many_1,    wrong_no_1},
    {"mchsarg",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchsarg},
    {"ratpoly_minus",           too_few_2,      CC_ratpoly_minus,wrong_no_2},
    {"matrixml",                CC_matrixml,    too_many_1,    wrong_no_1},
    {"ldf-dep-var",             CC_ldfKdepKvar, too_many_1,    wrong_no_1},
    {"transmat1",               CC_transmat1,   too_many_1,    wrong_no_1},
    {"row_dim",                 CC_row_dim,     too_many_1,    wrong_no_1},
    {"dipcontenti",             CC_dipcontenti, too_many_1,    wrong_no_1},
    {"minprec",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_minprec},
    {"rationalizef",            CC_rationalizef,too_many_1,    wrong_no_1},
    {"lf=zero",                 CC_lfMzero,     too_many_1,    wrong_no_1},
    {"add-factor",              too_few_2,      CC_addKfactor, wrong_no_2},
    {"coeffs-to-form1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeffsKtoKform1},
    {"rl_pnf",                  CC_rl_pnf,      too_many_1,    wrong_no_1},
    {"simp0",                   CC_simp0,       too_many_1,    wrong_no_1},
    {"get-min-degreelist",      CC_getKminKdegreelist,too_many_1,wrong_no_1},
    {"get*order",               CC_getHorder,   too_many_1,    wrong_no_1},
    {"qqe_simplbtat",           too_few_2,      CC_qqe_simplbtat,wrong_no_2},
    {"pasf_pnf",                CC_pasf_pnf,    too_many_1,    wrong_no_1},
    {"dvfsf_0mk2",              too_few_2,      CC_dvfsf_0mk2, wrong_no_2},
    {"symbolsrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_symbolsrd},
    {"search_att",              too_few_2,      CC_search_att, wrong_no_2},
    {"*rd2cr",                  CC_Hrd2cr,      too_many_1,    wrong_no_1},
    {"splitcomplex",            CC_splitcomplex,too_many_1,    wrong_no_1},
    {"nestzerop:",              CC_nestzeropT,  too_many_1,    wrong_no_1},
    {"dipretimes",              CC_dipretimes,  too_many_1,    wrong_no_1},
    {"physoppri",               CC_physoppri,   too_many_1,    wrong_no_1},
    {"zeros",                   CC_zeros,       too_many_1,    wrong_no_1},
    {"listminimize",            too_few_2,      CC_listminimize,wrong_no_2},
    {"general-modular-difference",too_few_2,    CC_generalKmodularKdifference,wrong_no_2},
    {"ofsf_qesubqat",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_qesubqat},
    {"pasf_premf",              too_few_2,      CC_pasf_premf, wrong_no_2},
    {"pasf_floor",              too_few_2,      CC_pasf_floor, wrong_no_2},
    {"cd_ordatp",               too_few_2,      CC_cd_ordatp,  wrong_no_2},
    {"matrixrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrd},
    {"look_for_rational",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_rational},
    {"listeq",                  too_few_2,      CC_listeq,     wrong_no_2},
    {"evequal",                 too_few_2,      CC_evequal,    wrong_no_2},
    {"color-strand",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_colorKstrand},
    {"quotofd",                 too_few_2,      CC_quotofd,    wrong_no_2},
    {"subsq",                   too_few_2,      CC_subsq,      wrong_no_2},
    {"red=subst1",              too_few_2,      CC_redMsubst1, wrong_no_2},
    {"mkindxlist",              CC_mkindxlist,  too_many_1,    wrong_no_1},
    {"simpsqrt3",               CC_simpsqrt3,   too_many_1,    wrong_no_1},
    {"rtrnda",                  too_few_2,      CC_rtrnda,     wrong_no_2},
    {"*s2i",                    CC_Hs2i,        too_many_1,    wrong_no_1},
    {"even_action_pow",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_even_action_pow},
    {NULL, (one_args *)"u37", (two_args *)"5697 7415496 1842923", 0}
};

/* end of generated code */
