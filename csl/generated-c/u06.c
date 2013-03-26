
/* $destdir\u06.c        Machine generated C code */

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


/* Code for deg!*form */

static Lisp_Object CC_degHform(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0027, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg*form");
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

v0029:
    v0026 = stack[0];
    if (!consp(v0026)) goto v0030;
    v0026 = stack[0];
    v0026 = qcar(v0026);
    v0028 = v0026;
    v0026 = v0028;
    if (!symbolp(v0026)) v0026 = nil;
    else { v0026 = qfastgets(v0026);
           if (v0026 != nil) { v0026 = elt(v0026, 16); /* indexvar */
#ifdef RECORD_GET
             if (v0026 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0026 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0026 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0026 == SPID_NOPROP) v0026 = nil; else v0026 = lisp_true; }}
#endif
    if (v0026 == nil) goto v0031;
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    v0027 = Llength(nil, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    v0026 = stack[0];
    v0026 = qcar(v0026);
    if (!symbolp(v0026)) v0026 = nil;
    else { v0026 = qfastgets(v0026);
           if (v0026 != nil) { v0026 = elt(v0026, 25); /* ifdegree */
#ifdef RECORD_GET
             if (v0026 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v0026 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v0026 == SPID_NOPROP) v0026 = nil; }}
#endif
    v0026 = Lassoc(nil, v0027, v0026);
    v0027 = v0026;
    v0026 = v0027;
    if (v0026 == nil) goto v0033;
    v0026 = v0027;
    v0026 = qcdr(v0026);
    { popv(3); return onevalue(v0026); }

v0033:
    v0026 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0026); }

v0031:
    v0027 = v0028;
    v0026 = elt(env, 2); /* wedge */
    if (v0027 == v0026) goto v0034;
    v0027 = v0028;
    v0026 = elt(env, 3); /* d */
    if (v0027 == v0026) goto v0035;
    v0027 = v0028;
    v0026 = elt(env, 4); /* hodge */
    if (v0027 == v0026) goto v0036;
    v0027 = v0028;
    v0026 = elt(env, 6); /* partdf */
    if (v0027 == v0026) goto v0037;
    v0027 = v0028;
    v0026 = elt(env, 7); /* liedf */
    if (v0027 == v0026) goto v0038;
    v0027 = v0028;
    v0026 = elt(env, 8); /* innerprod */
    if (v0027 == v0026) goto v0039;
    v0027 = v0028;
    v0026 = elt(env, 9); /* (plus minus difference quotient) */
    v0026 = Lmemq(nil, v0027, v0026);
    if (v0026 == nil) goto v0040;
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    stack[0] = v0026;
    goto v0029;

v0040:
    v0027 = v0028;
    v0026 = elt(env, 10); /* times */
    if (v0027 == v0026) goto v0041;
    v0026 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0026); }

v0041:
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    {
        popv(3);
        fn = elt(env, 11); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v0026);
    }

v0039:
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    v0026 = CC_degHform(env, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    {
        Lisp_Object v0042 = stack[-1];
        popv(3);
        fn = elt(env, 12); /* addd */
        return (*qfn2(fn))(qenv(fn), v0042, v0026);
    }

v0038:
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    stack[0] = v0026;
    goto v0029;

v0037:
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    v0026 = qcdr(v0026);
    if (v0026 == nil) goto v0043;
    v0026 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0026); }

v0043:
    v0026 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v0026); }

v0036:
    stack[-1] = qvalue(elt(env, 5)); /* dimex!* */
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    v0026 = CC_degHform(env, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    fn = elt(env, 13); /* negf */
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    {
        Lisp_Object v0044 = stack[-1];
        popv(3);
        fn = elt(env, 14); /* addf */
        return (*qfn2(fn))(qenv(fn), v0044, v0026);
    }

v0035:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    v0026 = CC_degHform(env, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    {
        Lisp_Object v0045 = stack[-1];
        popv(3);
        fn = elt(env, 12); /* addd */
        return (*qfn2(fn))(qenv(fn), v0045, v0026);
    }

v0034:
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    {
        popv(3);
        fn = elt(env, 11); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v0026);
    }

v0030:
    v0026 = stack[0];
    if (!symbolp(v0026)) v0026 = nil;
    else { v0026 = qfastgets(v0026);
           if (v0026 != nil) { v0026 = elt(v0026, 29); /* fdegree */
#ifdef RECORD_GET
             if (v0026 != SPID_NOPROP)
                record_get(elt(fastget_names, 29), 1);
             else record_get(elt(fastget_names, 29), 0),
                v0026 = nil; }
           else record_get(elt(fastget_names, 29), 0); }
#else
             if (v0026 == SPID_NOPROP) v0026 = nil; }}
#endif
    v0027 = v0026;
    v0026 = v0027;
    if (v0026 == nil) goto v0046;
    v0026 = v0027;
    v0026 = qcar(v0026);
    { popv(3); return onevalue(v0026); }

v0046:
    v0026 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0026); }
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for lessp!: */

static Lisp_Object CC_lesspT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lessp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0051 = v0047;
    v0050 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* greaterp!: */
        return (*qfn2(fn))(qenv(fn), v0051, v0050);
    }
}



/* Code for eofcheck */

static Lisp_Object MS_CDECL CC_eofcheck(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0055;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "eofcheck");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eofcheck");
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
/* end of prologue */
    v0055 = qvalue(elt(env, 1)); /* program!* */
    v0054 = qvalue(elt(env, 2)); /* !$eof!$ */
    if (v0055 == v0054) goto v0056;
    v0054 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0054); }

v0056:
    v0055 = qvalue(elt(env, 3)); /* ttype!* */
    v0054 = (Lisp_Object)49; /* 3 */
    if (v0055 == v0054) goto v0057;
    v0054 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0054); }

v0057:
    v0054 = qvalue(elt(env, 4)); /* eof!* */
    v0054 = add1(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[0];
    qvalue(elt(env, 4)) = v0054; /* eof!* */
    { popv(1); return onevalue(v0054); }
/* error exit handlers */
v0058:
    popv(1);
    return nil;
}



/* Code for !*ssave */

static Lisp_Object CC_Hssave(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0072, v0036, v0073;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *ssave");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0047;
    stack[-3] = v0000;
/* end of prologue */
    v0072 = qvalue(elt(env, 1)); /* !*uncached */
    if (!(v0072 == nil)) goto v0074;
    stack[-4] = qvalue(elt(env, 2)); /* alglist!* */
    v0036 = qvalue(elt(env, 3)); /* !*sub2 */
    v0072 = stack[-3];
    v0036 = cons(v0036, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    v0072 = qvalue(elt(env, 2)); /* alglist!* */
    v0072 = qcar(v0072);
    stack[-1] = v0036;
    stack[0] = v0072;
    v0072 = stack[0];
    if (v0072 == nil) goto v0076;
    v0036 = qvalue(elt(env, 5)); /* alglist_count!* */
    v0072 = qvalue(elt(env, 6)); /* alglist_limit!* */
    v0072 = (Lisp_Object)greaterp2(v0036, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    v0072 = v0072 ? lisp_true : nil;
    env = stack[-5];
    goto v0077;

v0077:
    if (v0072 == nil) goto v0078;
    v0072 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v0072; /* alglist_count!* */
    v0073 = (Lisp_Object)161; /* 10 */
    v0036 = (Lisp_Object)49; /* 3 */
    v0072 = elt(env, 7); /* 2.0 */
    fn = elt(env, 9); /* mkhash */
    v0072 = (*qfnn(fn))(qenv(fn), 3, v0073, v0036, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    stack[0] = v0072;
    v0073 = stack[-2];
    v0036 = stack[0];
    v0072 = stack[-1];
    fn = elt(env, 10); /* puthash */
    v0072 = (*qfnn(fn))(qenv(fn), 3, v0073, v0036, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    v0072 = stack[0];
    goto v0057;

v0057:
    v0072 = Lrplaca(nil, stack[-4], v0072);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    goto v0074;

v0074:
    v0072 = qvalue(elt(env, 8)); /* simpcount!* */
    v0072 = sub1(v0072);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    qvalue(elt(env, 8)) = v0072; /* simpcount!* */
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v0078:
    v0073 = stack[-2];
    v0036 = stack[0];
    v0072 = stack[-1];
    fn = elt(env, 10); /* puthash */
    v0072 = (*qfnn(fn))(qenv(fn), 3, v0073, v0036, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    v0072 = qvalue(elt(env, 5)); /* alglist_count!* */
    v0072 = add1(v0072);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-5];
    qvalue(elt(env, 5)) = v0072; /* alglist_count!* */
    v0072 = stack[0];
    goto v0057;

v0076:
    v0072 = qvalue(elt(env, 4)); /* t */
    goto v0077;
/* error exit handlers */
v0075:
    popv(6);
    return nil;
}



/* Code for red!-weight */

static Lisp_Object CC_redKweight(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0080 = stack[-1];
    fn = elt(env, 1); /* nonzero!-length */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-3];
    v0081 = stack[-1];
    v0080 = stack[0];
    fn = elt(env, 2); /* red!-weight1 */
    v0080 = (*qfn2(fn))(qenv(fn), v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    {
        Lisp_Object v0082 = stack[-2];
        popv(4);
        return cons(v0082, v0080);
    }
/* error exit handlers */
v0003:
    popv(4);
    return nil;
}



/* Code for resimp1 */

static Lisp_Object CC_resimp1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimp1");
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
    v0084 = stack[0];
    v0054 = qcar(v0084);
    v0084 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0054, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-2];
    v0084 = stack[0];
    v0054 = qcdr(v0084);
    v0084 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    v0084 = (*qfn2(fn))(qenv(fn), v0054, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-2];
    fn = elt(env, 5); /* quotsq */
    v0084 = (*qfn2(fn))(qenv(fn), stack[-1], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-2];
    stack[0] = v0084;
    v0084 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 3)) = v0084; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v0077:
    popv(3);
    return nil;
}



/* Code for gperm */

static Lisp_Object CC_gperm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0089;

v0089:
    v0088 = stack[0];
    v0021 = (Lisp_Object)1; /* 0 */
    v0021 = (Lisp_Object)greaterp2(v0088, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0021 = v0021 ? lisp_true : nil;
    env = stack[-4];
    if (v0021 == nil) goto v0074;
    v0088 = stack[0];
    v0021 = stack[-1];
    v0021 = cons(v0088, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    stack[-1] = v0021;
    v0021 = stack[0];
    v0021 = sub1(v0021);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    stack[0] = v0021;
    goto v0089;

v0074:
    v0021 = stack[-1];
    fn = elt(env, 2); /* gperm0 */
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    stack[-3] = v0021;
    v0021 = stack[-3];
    if (v0021 == nil) goto v0091;
    v0021 = stack[-3];
    v0021 = qcar(v0021);
    fn = elt(env, 3); /* pkp */
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    v0021 = ncons(v0021);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    stack[-1] = v0021;
    stack[-2] = v0021;
    goto v0024;

v0024:
    v0021 = stack[-3];
    v0021 = qcdr(v0021);
    stack[-3] = v0021;
    v0021 = stack[-3];
    if (v0021 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0021 = stack[-3];
    v0021 = qcar(v0021);
    fn = elt(env, 3); /* pkp */
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    v0021 = ncons(v0021);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    v0021 = Lrplacd(nil, stack[0], v0021);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    v0021 = stack[-1];
    v0021 = qcdr(v0021);
    stack[-1] = v0021;
    goto v0024;

v0091:
    v0021 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0021); }
/* error exit handlers */
v0090:
    popv(5);
    return nil;
}



/* Code for general!-modular!-reciprocal */

static Lisp_Object CC_generalKmodularKreciprocal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0096, v0031, v0097;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-reciprocal");
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
    v0034 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v0034 == nil) goto v0091;
    v0096 = stack[0];
    v0034 = (Lisp_Object)1; /* 0 */
    v0034 = (Lisp_Object)lessp2(v0096, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    v0034 = v0034 ? lisp_true : nil;
    env = stack[-2];
    if (v0034 == nil) goto v0091;
    stack[-1] = qvalue(elt(env, 2)); /* current!-modulus */
    v0096 = stack[0];
    v0034 = qvalue(elt(env, 2)); /* current!-modulus */
    v0031 = plus2(v0096, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    v0096 = (Lisp_Object)1; /* 0 */
    v0034 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v0022 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v0022, v0031, v0096, v0034);
    }

v0091:
    v0097 = qvalue(elt(env, 2)); /* current!-modulus */
    v0031 = stack[0];
    v0096 = (Lisp_Object)1; /* 0 */
    v0034 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v0097, v0031, v0096, v0034);
    }
/* error exit handlers */
v0098:
    popv(3);
    return nil;
}



/* Code for gizerop!: */

static Lisp_Object CC_gizeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0059, v0084;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gizerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0084 = v0000;
/* end of prologue */
    v0063 = v0084;
    v0063 = qcdr(v0063);
    v0059 = qcar(v0063);
    v0063 = (Lisp_Object)1; /* 0 */
    if (v0059 == v0063) goto v0095;
    v0063 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0063);

v0095:
    v0063 = v0084;
    v0063 = qcdr(v0063);
    v0059 = qcdr(v0063);
    v0063 = (Lisp_Object)1; /* 0 */
    v0063 = (v0059 == v0063 ? lisp_true : nil);
    return onevalue(v0063);
}



/* Code for sfto_gcdf!* */

static Lisp_Object CC_sfto_gcdfH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0057, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_gcdf*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0057 = v0047;
    v0095 = v0000;
/* end of prologue */
    v0089 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*gcd */
    qvalue(elt(env, 2)) = v0089; /* !*gcd */
    v0089 = v0095;
    fn = elt(env, 3); /* sfto_gcdf */
    v0089 = (*qfn2(fn))(qenv(fn), v0089, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v0089); }
/* error exit handlers */
v0046:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for gcdf1 */

static Lisp_Object CC_gcdf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0047;
    stack[-2] = v0000;
/* end of prologue */
    v0116 = stack[-2];
    if (v0116 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0116 = stack[-1];
    if (v0116 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0117 = stack[-2];
    v0116 = (Lisp_Object)17; /* 1 */
    if (v0117 == v0116) goto v0081;
    v0117 = stack[-1];
    v0116 = (Lisp_Object)17; /* 1 */
    v0116 = (v0117 == v0116 ? lisp_true : nil);
    goto v0080;

v0080:
    if (v0116 == nil) goto v0046;
    v0116 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0116); }

v0046:
    v0116 = stack[-2];
    if (!consp(v0116)) goto v0118;
    v0116 = stack[-2];
    v0116 = qcar(v0116);
    v0116 = (consp(v0116) ? nil : lisp_true);
    goto v0119;

v0119:
    if (v0116 == nil) goto v0120;
    v0117 = stack[-2];
    v0116 = stack[-1];
    {
        popv(5);
        fn = elt(env, 8); /* gcdfd */
        return (*qfn2(fn))(qenv(fn), v0117, v0116);
    }

v0120:
    v0116 = stack[-1];
    if (!consp(v0116)) goto v0086;
    v0116 = stack[-1];
    v0116 = qcar(v0116);
    v0116 = (consp(v0116) ? nil : lisp_true);
    goto v0085;

v0085:
    if (v0116 == nil) goto v0068;
    v0117 = stack[-1];
    v0116 = stack[-2];
    {
        popv(5);
        fn = elt(env, 8); /* gcdfd */
        return (*qfn2(fn))(qenv(fn), v0117, v0116);
    }

v0068:
    v0116 = qvalue(elt(env, 2)); /* !*anygcd */
    if (v0116 == nil) goto v0060;
    v0116 = stack[-2];
    fn = elt(env, 9); /* num!-exponents */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    if (v0116 == nil) goto v0072;
    v0116 = stack[-1];
    fn = elt(env, 9); /* num!-exponents */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0116 = (v0116 == nil ? lisp_true : nil);
    goto v0062;

v0062:
    if (v0116 == nil) goto v0122;
    v0116 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0116); }

v0122:
    v0117 = stack[-2];
    v0116 = stack[-1];
    fn = elt(env, 10); /* quotf1 */
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    if (!(v0116 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0117 = stack[-1];
    v0116 = stack[-2];
    fn = elt(env, 10); /* quotf1 */
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    if (!(v0116 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0117 = stack[-2];
    v0116 = stack[-1];
    fn = elt(env, 11); /* gcdf2 */
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    stack[-3] = v0116;
    v0116 = qvalue(elt(env, 3)); /* !*gcd */
    if (v0116 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0117 = qvalue(elt(env, 4)); /* dmode!* */
    v0116 = elt(env, 5); /* (!:rd!: !:cr!:) */
    v0116 = Lmemq(nil, v0117, v0116);
    if (v0116 == nil) goto v0123;
    v0116 = qvalue(elt(env, 6)); /* nil */
    goto v0124;

v0124:
    if (v0116 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0116 = stack[-2];
    fn = elt(env, 12); /* noncomfp */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    if (!(v0116 == nil)) goto v0002;
    v0116 = stack[-1];
    fn = elt(env, 12); /* noncomfp */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    if (!(v0116 == nil)) goto v0002;
    stack[0] = elt(env, 7); /* "gcdf failed" */
    v0116 = stack[-2];
    fn = elt(env, 13); /* prepf */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0116 = stack[-1];
    fn = elt(env, 13); /* prepf */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0116 = list3(stack[0], stack[-2], v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    fn = elt(env, 14); /* errach */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v0002:
    v0116 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0116); }

v0123:
    v0117 = stack[-2];
    v0116 = stack[-3];
    fn = elt(env, 10); /* quotf1 */
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    if (v0116 == nil) goto v0007;
    v0117 = stack[-1];
    v0116 = stack[-3];
    fn = elt(env, 10); /* quotf1 */
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0116 = (v0116 == nil ? lisp_true : nil);
    goto v0124;

v0007:
    v0116 = qvalue(elt(env, 1)); /* t */
    goto v0124;

v0072:
    v0116 = qvalue(elt(env, 1)); /* t */
    goto v0062;

v0060:
    v0116 = qvalue(elt(env, 1)); /* t */
    goto v0062;

v0086:
    v0116 = qvalue(elt(env, 1)); /* t */
    goto v0085;

v0118:
    v0116 = qvalue(elt(env, 1)); /* t */
    goto v0119;

v0081:
    v0116 = qvalue(elt(env, 1)); /* t */
    goto v0080;
/* error exit handlers */
v0121:
    popv(5);
    return nil;
}



/* Code for subs3q */

static Lisp_Object CC_subs3q(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3q");
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
    v0052 = qvalue(elt(env, 1)); /* mchfg!* */
    stack[-2] = v0052;
    v0052 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v0052; /* mchfg!* */
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    fn = elt(env, 3); /* subs3f */
    stack[0] = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-3];
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    fn = elt(env, 3); /* subs3f */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-3];
    fn = elt(env, 4); /* quotsq */
    v0052 = (*qfn2(fn))(qenv(fn), stack[0], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-3];
    stack[-1] = v0052;
    v0052 = stack[-2];
    qvalue(elt(env, 1)) = v0052; /* mchfg!* */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v0082:
    popv(4);
    return nil;
}



/* Code for subs2f1 */

static Lisp_Object CC_subs2f1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0204, v0205, v0206, v0207, v0208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2f1");
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
/* copy arguments values to proper place */
    stack[-8] = v0000;
/* end of prologue */
    v0204 = stack[-8];
    if (!consp(v0204)) goto v0209;
    v0204 = stack[-8];
    v0204 = qcar(v0204);
    v0204 = (consp(v0204) ? nil : lisp_true);
    goto v0210;

v0210:
    if (v0204 == nil) goto v0080;
    v0204 = stack[-8];
    {
        popv(11);
        fn = elt(env, 12); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v0204);
    }

v0080:
    stack[-2] = nil;
    goto v0084;

v0084:
    v0204 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0204;
    v0204 = stack[-8];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    stack[-9] = v0204;
    v0205 = qvalue(elt(env, 2)); /* nil */
    v0204 = (Lisp_Object)17; /* 1 */
    v0204 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-3] = v0204;
    goto v0054;

v0054:
    v0204 = stack[-8];
    if (v0204 == nil) goto v0022;
    v0205 = stack[-8];
    v0204 = stack[-9];
    fn = elt(env, 13); /* degr */
    v0205 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = (Lisp_Object)1; /* 0 */
    v0204 = (v0205 == v0204 ? lisp_true : nil);
    goto v0098;

v0098:
    if (!(v0204 == nil)) goto v0055;
    v0204 = stack[-8];
    v0205 = qcar(v0204);
    v0204 = stack[-4];
    v0204 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-4] = v0204;
    v0204 = stack[-8];
    v0204 = qcdr(v0204);
    stack[-8] = v0204;
    goto v0054;

v0055:
    v0204 = qvalue(elt(env, 3)); /* powlis!* */
    stack[-5] = v0204;
    goto v0058;

v0058:
    v0204 = stack[-5];
    if (v0204 == nil) goto v0077;
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    v0205 = qcar(v0204);
    v0204 = stack[-5];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    if (equal(v0205, v0204)) goto v0012;
    v0205 = stack[-9];
    v0204 = elt(env, 4); /* expt */
    if (!consp(v0205)) goto v0117;
    v0205 = qcar(v0205);
    if (!(v0205 == v0204)) goto v0117;
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    v0205 = qcar(v0204);
    v0204 = stack[-5];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    if (equal(v0205, v0204)) goto v0212;
    v0204 = qvalue(elt(env, 2)); /* nil */
    goto v0213;

v0213:
    if (v0204 == nil) goto v0072;
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    v0205 = qcdr(v0204);
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    v0204 = Ldivide(nil, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-7] = v0204;
    v0204 = stack[-7];
    v0205 = qcar(v0204);
    v0204 = (Lisp_Object)1; /* 0 */
    if (v0205 == v0204) goto v0214;
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    fn = elt(env, 14); /* simp */
    v0205 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = stack[-7];
    v0204 = qcar(v0204);
    fn = elt(env, 15); /* exptsq */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-6] = v0204;
    goto v0215;

v0215:
    v0204 = stack[-7];
    v0205 = qcdr(v0204);
    v0204 = (Lisp_Object)1; /* 0 */
    if (v0205 == v0204) goto v0216;
    stack[-1] = qvalue(elt(env, 6)); /* alglist!* */
    qvalue(elt(env, 6)) = nil; /* alglist!* */
    stack[0] = qvalue(elt(env, 7)); /* dmode!* */
    qvalue(elt(env, 7)) = nil; /* dmode!* */
    v0204 = qvalue(elt(env, 2)); /* nil */
    v0204 = ncons(v0204);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-10];
    qvalue(elt(env, 6)) = v0204; /* alglist!* */
    v0204 = stack[-7];
    v0205 = qcdr(v0204);
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    v0204 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-10];
    fn = elt(env, 16); /* cancel */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-10];
    stack[-7] = v0204;
    qvalue(elt(env, 7)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 6)) = stack[-1]; /* alglist!* */
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    v0205 = qcar(v0204);
    v0204 = stack[-7];
    v0204 = qcar(v0204);
    v0206 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = stack[-5];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0205 = qcar(v0204);
    v0204 = stack[-5];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    fn = elt(env, 17); /* subs2p */
    v0205 = (*qfnn(fn))(qenv(fn), 3, v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = stack[-7];
    v0204 = qcdr(v0204);
    fn = elt(env, 18); /* raddsq */
    v0205 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = stack[-6];
    fn = elt(env, 19); /* multsq */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-6] = v0204;
    goto v0216;

v0216:
    stack[0] = stack[-6];
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = CC_subs2f1(env, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    fn = elt(env, 19); /* multsq */
    v0205 = (*qfn2(fn))(qenv(fn), stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = stack[-3];
    fn = elt(env, 20); /* addsq */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-3] = v0204;
    goto v0094;

v0094:
    v0204 = stack[-4];
    v0204 = qcdr(v0204);
    stack[-4] = v0204;
    v0204 = stack[-4];
    if (!(v0204 == nil)) goto v0055;

v0115:
    v0204 = stack[-8];
    if (!consp(v0204)) goto v0218;
    v0204 = stack[-8];
    v0204 = qcar(v0204);
    v0204 = (consp(v0204) ? nil : lisp_true);
    goto v0219;

v0219:
    if (v0204 == nil) goto v0220;
    v0204 = stack[-8];
    fn = elt(env, 12); /* !*d2q */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-4] = v0204;
    goto v0025;

v0025:
    v0204 = qvalue(elt(env, 10)); /* !*exp */
    if (!(v0204 == nil)) goto v0221;
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    fn = elt(env, 21); /* mkprod */
    stack[0] = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = stack[-4];
    v0204 = qcdr(v0204);
    fn = elt(env, 21); /* mkprod */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = cons(stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-4] = v0204;
    goto v0221;

v0221:
    v0205 = stack[-3];
    v0204 = stack[-4];
    fn = elt(env, 20); /* addsq */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-4] = v0204;
    v0204 = stack[-2];
    if (v0204 == nil) { Lisp_Object res = stack[-4]; popv(11); return onevalue(res); }
    v0204 = stack[-2];
    v0204 = qcar(v0204);
    stack[-3] = v0204;
    v0204 = stack[-2];
    v0204 = qcdr(v0204);
    stack[-2] = v0204;
    goto v0025;

v0220:
    v0205 = stack[-3];
    v0204 = stack[-2];
    v0204 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-2] = v0204;
    goto v0084;

v0218:
    v0204 = qvalue(elt(env, 1)); /* t */
    goto v0219;

v0214:
    v0205 = (Lisp_Object)17; /* 1 */
    v0204 = (Lisp_Object)17; /* 1 */
    v0204 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-6] = v0204;
    goto v0215;

v0072:
    v0204 = stack[-5];
    v0204 = qcdr(v0204);
    stack[-5] = v0204;
    goto v0058;

v0212:
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0205 = qcar(v0204);
    v0204 = elt(env, 5); /* quotient */
    if (!consp(v0205)) goto v0099;
    v0205 = qcar(v0205);
    if (!(v0205 == v0204)) goto v0099;
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0205 = qcar(v0204);
    v0204 = (Lisp_Object)17; /* 1 */
    if (v0205 == v0204) goto v0222;
    v0204 = qvalue(elt(env, 2)); /* nil */
    goto v0213;

v0222:
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    v0204 = (is_number(v0204) ? lisp_true : nil);
    goto v0213;

v0099:
    v0204 = qvalue(elt(env, 2)); /* nil */
    goto v0213;

v0117:
    v0204 = qvalue(elt(env, 2)); /* nil */
    goto v0213;

v0012:
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0206 = qcar(v0204);
    v0204 = stack[-5];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0205 = qcar(v0204);
    v0204 = stack[-5];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    fn = elt(env, 17); /* subs2p */
    v0204 = (*qfnn(fn))(qenv(fn), 3, v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-6] = v0204;
    goto v0216;

v0077:
    v0204 = qvalue(elt(env, 8)); /* powlis1!* */
    stack[-5] = v0204;
    goto v0076;

v0076:
    v0204 = stack[-5];
    if (v0204 == nil) goto v0223;
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0208 = qcar(v0204);
    v0204 = stack[-5];
    v0204 = qcar(v0204);
    v0207 = qcar(v0204);
    v0204 = stack[-5];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0206 = qcar(v0204);
    v0204 = stack[-5];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    v0205 = qcar(v0204);
    v0204 = stack[-5];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    fn = elt(env, 22); /* mtchp */
    v0204 = (*qfnn(fn))(qenv(fn), 5, v0208, v0207, v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-6] = v0204;
    if (!(v0204 == nil)) goto v0216;
    v0204 = stack[-5];
    v0204 = qcdr(v0204);
    stack[-5] = v0204;
    goto v0076;

v0223:
    v0205 = stack[-9];
    v0204 = elt(env, 4); /* expt */
    if (!consp(v0205)) goto v0224;
    v0205 = qcar(v0205);
    if (!(v0205 == v0204)) goto v0224;
    v0204 = qvalue(elt(env, 9)); /* !*structure */
    v0204 = (v0204 == nil ? lisp_true : nil);
    goto v0225;

v0225:
    if (!(v0204 == nil)) goto v0226;
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0205 = qcar(v0204);
    v0204 = (Lisp_Object)17; /* 1 */
    v0204 = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0205 = ncons(v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = CC_subs2f1(env, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    fn = elt(env, 19); /* multsq */
    v0205 = (*qfn2(fn))(qenv(fn), stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = stack[-3];
    fn = elt(env, 20); /* addsq */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-3] = v0204;
    goto v0094;

v0226:
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    v0205 = qcdr(v0204);
    v0204 = (Lisp_Object)17; /* 1 */
    if (v0205 == v0204) goto v0227;
    v0204 = qvalue(elt(env, 2)); /* nil */
    goto v0228;

v0228:
    if (v0204 == nil) goto v0229;
    v0205 = stack[-9];
    v0204 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 23); /* mksq */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-6] = v0204;
    goto v0230;

v0230:
    stack[0] = stack[-6];
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = CC_subs2f1(env, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    fn = elt(env, 19); /* multsq */
    v0205 = (*qfn2(fn))(qenv(fn), stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = stack[-3];
    fn = elt(env, 20); /* addsq */
    v0204 = (*qfn2(fn))(qenv(fn), v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-3] = v0204;
    v0204 = stack[-4];
    v0204 = qcdr(v0204);
    stack[-4] = v0204;
    v0204 = stack[-4];
    if (v0204 == nil) goto v0115;
    else goto v0226;

v0229:
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    stack[0] = qcar(v0204);
    v0206 = elt(env, 11); /* times */
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0205 = qcar(v0204);
    v0204 = stack[-4];
    v0204 = qcar(v0204);
    v0204 = qcar(v0204);
    v0204 = qcdr(v0204);
    v0204 = list3(v0206, v0205, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    v0204 = list2(stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    fn = elt(env, 24); /* simpexpt */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-10];
    stack[-6] = v0204;
    goto v0230;

v0227:
    v0204 = stack[-9];
    v0204 = qcdr(v0204);
    v0205 = qcar(v0204);
    v0204 = elt(env, 4); /* expt */
    v0204 = Leqcar(nil, v0205, v0204);
    env = stack[-10];
    v0204 = (v0204 == nil ? lisp_true : nil);
    goto v0228;

v0224:
    v0204 = qvalue(elt(env, 2)); /* nil */
    goto v0225;

v0022:
    v0204 = qvalue(elt(env, 1)); /* t */
    goto v0098;

v0209:
    v0204 = qvalue(elt(env, 1)); /* t */
    goto v0210;
/* error exit handlers */
v0217:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 6)) = stack[-1]; /* alglist!* */
    popv(11);
    return nil;
v0211:
    popv(11);
    return nil;
}



/* Code for xxsort */

static Lisp_Object CC_xxsort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xxsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0049 = v0000;
/* end of prologue */
    v0050 = v0049;
    v0049 = elt(env, 1); /* lambda_mka0p2_1 */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v0050, v0049);
    }
}



/* Code for lambda_mka0p2_1 */

static Lisp_Object CC_lambda_mka0p2_1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_mka0p2_1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0081 = v0047;
    v0052 = v0000;
/* end of prologue */
    v0052 = qcar(v0052);
    v0081 = qcar(v0081);
    fn = elt(env, 1); /* termorder */
    v0052 = (*qfn2(fn))(qenv(fn), v0052, v0081);
    errexit();
    v0081 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0052, v0081);
}



/* Code for ibalp_commonlenisone */

static Lisp_Object CC_ibalp_commonlenisone(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_commonlenisone");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0083 = stack[-1];
    if (v0083 == nil) goto v0209;
    v0083 = qvalue(elt(env, 1)); /* nil */
    goto v0210;

v0210:
    if (!(v0083 == nil)) { popv(3); return onevalue(v0083); }
    v0083 = stack[0];
    if (v0083 == nil) goto v0079;
    v0083 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0083); }

v0079:
    v0083 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* ibalp_lenisone */
        return (*qfn1(fn))(qenv(fn), v0083);
    }

v0209:
    v0083 = stack[0];
    fn = elt(env, 2); /* ibalp_lenisone */
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    goto v0210;
/* error exit handlers */
v0059:
    popv(3);
    return nil;
}



/* Code for powers2 */

static Lisp_Object MS_CDECL CC_powers2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0047,
                         Lisp_Object v0087, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0231, v0232, v0233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powers2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0087,v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0047,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0087;
    stack[-1] = v0047;
    stack[-2] = v0000;
/* end of prologue */

v0210:
    v0231 = stack[-2];
    if (!consp(v0231)) goto v0057;
    v0231 = stack[-2];
    v0231 = qcar(v0231);
    v0231 = (consp(v0231) ? nil : lisp_true);
    goto v0089;

v0089:
    if (v0231 == nil) goto v0025;
    v0231 = stack[-2];
    if (v0231 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0232 = stack[0];
    v0231 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* powers4 */
        return (*qfn2(fn))(qenv(fn), v0232, v0231);
    }

v0025:
    v0231 = stack[-2];
    v0231 = qcar(v0231);
    v0231 = qcdr(v0231);
    stack[-3] = v0231;
    v0231 = stack[-2];
    v0233 = qcdr(v0231);
    v0232 = stack[-1];
    v0231 = stack[0];
    v0231 = CC_powers2(env, 3, v0233, v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    stack[-1] = v0231;
    v0231 = stack[-2];
    v0231 = qcar(v0231);
    v0232 = qcar(v0231);
    v0231 = stack[0];
    v0231 = cons(v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    stack[0] = v0231;
    v0231 = stack[-3];
    stack[-2] = v0231;
    goto v0210;

v0057:
    v0231 = qvalue(elt(env, 1)); /* t */
    goto v0089;
/* error exit handlers */
v0021:
    popv(5);
    return nil;
}



/* Code for retattributes */

static Lisp_Object CC_retattributes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retattributes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */

v0029:
    v0113 = stack[0];
    if (v0113 == nil) goto v0210;
    v0085 = stack[-1];
    v0113 = stack[0];
    v0113 = qcar(v0113);
    fn = elt(env, 2); /* find */
    v0113 = (*qfn2(fn))(qenv(fn), v0085, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-3];
    v0085 = v0113;
    if (v0085 == nil) goto v0096;
    v0085 = stack[0];
    v0085 = qcar(v0085);
    stack[-2] = list2(v0085, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-3];
    v0085 = stack[-1];
    v0113 = stack[0];
    v0113 = qcdr(v0113);
    v0113 = CC_retattributes(env, v0085, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    {
        Lisp_Object v0234 = stack[-2];
        popv(4);
        return cons(v0234, v0113);
    }

v0096:
    v0085 = stack[-1];
    v0113 = stack[0];
    v0113 = qcdr(v0113);
    stack[-1] = v0085;
    stack[0] = v0113;
    goto v0029;

v0210:
    v0113 = nil;
    { popv(4); return onevalue(v0113); }
/* error exit handlers */
v0233:
    popv(4);
    return nil;
}



/* Code for isarb_compl */

static Lisp_Object CC_isarb_compl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0084, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isarb_compl");
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
    v0084 = v0000;
/* end of prologue */
    v0059 = v0084;
    v0059 = Lconsp(nil, v0059);
    env = stack[0];
    if (v0059 == nil) goto v0235;
    v0059 = v0084;
    v0054 = qcar(v0059);
    v0059 = elt(env, 1); /* arbcomplex */
    if (v0054 == v0059) goto v0051;
    v0059 = v0084;
    v0059 = qcdr(v0059);
    fn = elt(env, 4); /* multi_isarb_compl */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    goto v0235;

v0235:
    v0059 = nil;
    { popv(1); return onevalue(v0059); }

v0051:
    v0059 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0059; /* found_compl */
    goto v0235;
/* error exit handlers */
v0055:
    popv(1);
    return nil;
}



/* Code for gsetsugar */

static Lisp_Object CC_gsetsugar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gsetsugar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0055 = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0054 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0054 == nil) goto v0209;
    stack[-2] = stack[-1];
    stack[0] = elt(env, 3); /* sugar */
    v0054 = v0055;
    if (!(v0054 == nil)) goto v0081;
    v0054 = stack[-1];
    fn = elt(env, 4); /* vdptdeg */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    goto v0081;

v0081:
    fn = elt(env, 5); /* vdpputprop */
    v0054 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    goto v0210;

v0210:
    if (v0054 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else { popv(4); return onevalue(v0054); }

v0209:
    v0054 = qvalue(elt(env, 2)); /* nil */
    goto v0210;
/* error exit handlers */
v0024:
    popv(4);
    return nil;
}



/* Code for make!-set */

static Lisp_Object CC_makeKset(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-set");
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
    v0050 = v0000;
/* end of prologue */
    v0051 = v0050;
    v0050 = elt(env, 1); /* set!-ordp */
    fn = elt(env, 2); /* sort */
    v0050 = (*qfn2(fn))(qenv(fn), v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* makelist */
        return (*qfn1(fn))(qenv(fn), v0050);
    }
/* error exit handlers */
v0089:
    popv(1);
    return nil;
}



/* Code for setcloc!* */

static Lisp_Object MS_CDECL CC_setclocH(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0053, v0071;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setcloc*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setcloc*");
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
/* end of prologue */
    v0052 = qvalue(elt(env, 1)); /* ifl!* */
    if (v0052 == nil) goto v0101;
    v0052 = qvalue(elt(env, 1)); /* ifl!* */
    v0071 = qcar(v0052);
    v0053 = (Lisp_Object)17; /* 1 */
    v0052 = qvalue(elt(env, 3)); /* curline!* */
    v0052 = list2star(v0071, v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[0];
    goto v0087;

v0087:
    qvalue(elt(env, 4)) = v0052; /* cloc!* */
    { popv(1); return onevalue(v0052); }

v0101:
    v0052 = qvalue(elt(env, 2)); /* nil */
    goto v0087;
/* error exit handlers */
v0003:
    popv(1);
    return nil;
}



/* Code for dp_ecart */

static Lisp_Object CC_dp_ecart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_ecart");
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
    v0052 = stack[0];
    if (v0052 == nil) goto v0030;
    v0052 = stack[0];
    fn = elt(env, 1); /* dp!=ecart */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    v0052 = stack[0];
    fn = elt(env, 2); /* dp_lmon */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    fn = elt(env, 3); /* mo_ecart */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    {
        Lisp_Object v0082 = stack[-1];
        popv(3);
        return difference2(v0082, v0052);
    }

v0030:
    v0052 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0052); }
/* error exit handlers */
v0003:
    popv(3);
    return nil;
}



/* Code for pcmult */

static Lisp_Object CC_pcmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pcmult");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0047;
    v0088 = v0000;
/* end of prologue */
    stack[-5] = v0088;
    v0088 = stack[-5];
    if (v0088 == nil) goto v0051;
    v0088 = stack[-5];
    v0088 = qcar(v0088);
    v0035 = v0088;
    stack[0] = qcar(v0035);
    v0035 = stack[-4];
    v0088 = qcdr(v0088);
    fn = elt(env, 2); /* cprod */
    v0088 = (*qfn2(fn))(qenv(fn), v0035, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-6];
    v0088 = cons(stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-6];
    v0088 = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-6];
    stack[-2] = v0088;
    stack[-3] = v0088;
    goto v0209;

v0209:
    v0088 = stack[-5];
    v0088 = qcdr(v0088);
    stack[-5] = v0088;
    v0088 = stack[-5];
    if (v0088 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0088 = stack[-5];
    v0088 = qcar(v0088);
    v0035 = v0088;
    stack[0] = qcar(v0035);
    v0035 = stack[-4];
    v0088 = qcdr(v0088);
    fn = elt(env, 2); /* cprod */
    v0088 = (*qfn2(fn))(qenv(fn), v0035, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-6];
    v0088 = cons(stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-6];
    v0088 = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-6];
    v0088 = Lrplacd(nil, stack[-1], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-6];
    v0088 = stack[-2];
    v0088 = qcdr(v0088);
    stack[-2] = v0088;
    goto v0209;

v0051:
    v0088 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0088); }
/* error exit handlers */
v0236:
    popv(7);
    return nil;
}



/* Code for round!:last */

static Lisp_Object CC_roundTlast(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0237, v0066, v0020;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for round:last");
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
    v0066 = v0000;
/* end of prologue */
    v0237 = v0066;
    v0237 = qcdr(v0237);
    stack[0] = qcar(v0237);
    v0237 = v0066;
    v0237 = qcdr(v0237);
    v0237 = qcdr(v0237);
    v0066 = add1(v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-3];
    v0237 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = stack[0];
    stack[-1] = v0066;
    stack[0] = v0237;
    v0066 = stack[-2];
    v0237 = (Lisp_Object)1; /* 0 */
    v0237 = (Lisp_Object)lessp2(v0066, v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    v0237 = v0237 ? lisp_true : nil;
    env = stack[-3];
    if (v0237 == nil) goto v0057;
    v0237 = stack[-2];
    v0237 = negate(v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-3];
    stack[-2] = v0237;
    v0237 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0237;
    goto v0057;

v0057:
    v0237 = stack[-2];
    v0237 = Levenp(nil, v0237);
    env = stack[-3];
    if (v0237 == nil) goto v0024;
    v0066 = stack[-2];
    v0237 = (Lisp_Object)-15; /* -1 */
    v0237 = ash(v0066, v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-3];
    goto v0059;

v0059:
    stack[-2] = v0237;
    v0237 = stack[0];
    if (v0237 == nil) goto v0022;
    v0237 = stack[-2];
    v0237 = negate(v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-3];
    stack[-2] = v0237;
    goto v0022;

v0022:
    v0020 = elt(env, 3); /* !:rd!: */
    v0066 = stack[-2];
    v0237 = stack[-1];
    popv(4);
    return list2star(v0020, v0066, v0237);

v0024:
    v0066 = stack[-2];
    v0237 = (Lisp_Object)-15; /* -1 */
    v0237 = ash(v0066, v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-3];
    v0237 = add1(v0237);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-3];
    goto v0059;
/* error exit handlers */
v0238:
    popv(4);
    return nil;
}



/* Code for !*!*s2a */

static Lisp_Object CC_HHs2a(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object v0030, v0235;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for **s2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0030 = v0047;
    v0235 = v0000;
/* end of prologue */
    return onevalue(v0235);
}



/* Code for qqe_qtidp */

static Lisp_Object CC_qqe_qtidp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0051;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qtidp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0000;
/* end of prologue */
    if (!symbolp(v0050)) v0050 = nil;
    else { v0050 = qfastgets(v0050);
           if (v0050 != nil) { v0050 = elt(v0050, 10); /* idtype */
#ifdef RECORD_GET
             if (v0050 != SPID_NOPROP)
                record_get(elt(fastget_names, 10), 1);
             else record_get(elt(fastget_names, 10), 0),
                v0050 = nil; }
           else record_get(elt(fastget_names, 10), 0); }
#else
             if (v0050 == SPID_NOPROP) v0050 = nil; }}
#endif
    v0051 = elt(env, 1); /* qt */
    v0050 = (v0050 == v0051 ? lisp_true : nil);
    return onevalue(v0050);
}



/* Code for isarb_int */

static Lisp_Object CC_isarb_int(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0084, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isarb_int");
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
    v0084 = v0000;
/* end of prologue */
    v0059 = v0084;
    v0059 = Lconsp(nil, v0059);
    env = stack[0];
    if (v0059 == nil) goto v0235;
    v0059 = v0084;
    v0054 = qcar(v0059);
    v0059 = elt(env, 1); /* arbint */
    if (v0054 == v0059) goto v0051;
    v0059 = v0084;
    v0059 = qcdr(v0059);
    fn = elt(env, 4); /* multi_isarb_int */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    goto v0235;

v0235:
    v0059 = nil;
    { popv(1); return onevalue(v0059); }

v0051:
    v0059 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0059; /* found_int */
    goto v0235;
/* error exit handlers */
v0055:
    popv(1);
    return nil;
}



/* Code for ps!:evaluate */

static Lisp_Object CC_psTevaluate(Lisp_Object env,
                         Lisp_Object v0047, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:evaluate");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0047);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0047,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0087;
    v0097 = v0047;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v0097; /* ps */
    v0239 = qvalue(elt(env, 1)); /* ps */
    v0097 = stack[-2];
    fn = elt(env, 3); /* ps!:get!-term */
    v0097 = (*qfn2(fn))(qenv(fn), v0239, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-4];
    stack[-1] = v0097;
    v0097 = stack[-1];
    if (v0097 == nil) goto v0081;
    v0097 = stack[-1];
    goto v0074;

v0074:
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v0097); }

v0081:
    v0097 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:last!-term */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-4];
    v0097 = add1(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-4];
    stack[0] = v0097;
    goto v0115;

v0115:
    v0239 = stack[-2];
    v0097 = stack[0];
    v0097 = difference2(v0239, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-4];
    v0097 = Lminusp(nil, v0097);
    env = stack[-4];
    if (v0097 == nil) goto v0069;
    v0097 = stack[-1];
    goto v0074;

v0069:
    v0239 = qvalue(elt(env, 1)); /* ps */
    v0097 = stack[0];
    fn = elt(env, 5); /* ps!:evaluate!-next */
    v0097 = (*qfn2(fn))(qenv(fn), v0239, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-4];
    stack[-1] = v0097;
    v0097 = stack[0];
    v0097 = add1(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-4];
    stack[0] = v0097;
    goto v0115;
/* error exit handlers */
v0068:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for vevtdeg */

static Lisp_Object CC_vevtdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0119, v0118;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevtdeg");
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
    v0119 = nil;
    goto v0074;

v0074:
    v0114 = stack[0];
    if (v0114 == nil) goto v0210;
    v0114 = stack[0];
    v0114 = qcar(v0114);
    v0114 = cons(v0114, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    v0119 = v0114;
    v0114 = stack[0];
    v0114 = qcdr(v0114);
    stack[0] = v0114;
    goto v0074;

v0210:
    v0114 = (Lisp_Object)1; /* 0 */
    goto v0209;

v0209:
    v0118 = v0119;
    if (v0118 == nil) { popv(2); return onevalue(v0114); }
    v0118 = v0119;
    v0118 = qcar(v0118);
    v0114 = (Lisp_Object)(int32_t)((int32_t)v0118 + (int32_t)v0114 - TAG_FIXNUM);
    v0119 = qcdr(v0119);
    goto v0209;
/* error exit handlers */
v0069:
    popv(2);
    return nil;
}



/* Code for convchk */

static Lisp_Object CC_convchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0202, v0098, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convchk");
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
    v0202 = v0000;
/* end of prologue */
    v0098 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v0098 == nil) goto v0235;
    v0098 = v0202;
    if (!(!consp(v0098))) { popv(1); return onevalue(v0202); }
    v0098 = v0202;
    v0098 = Lfloatp(nil, v0098);
    env = stack[0];
    if (v0098 == nil) goto v0081;
    {
        popv(1);
        fn = elt(env, 3); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v0202);
    }

v0081:
    v0098 = v0202;
    if (!(!consp(v0098))) goto v0003;
    v0098 = v0202;
    v0098 = integerp(v0098);
    if (v0098 == nil) goto v0119;
    v0022 = elt(env, 2); /* !:rd!: */
    v0098 = v0202;
    v0202 = (Lisp_Object)1; /* 0 */
    v0202 = list2star(v0022, v0098, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[0];
    goto v0003;

v0003:
    {
        popv(1);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v0202);
    }

v0119:
    fn = elt(env, 5); /* read!:num */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[0];
    goto v0003;

v0235:
    v0098 = v0202;
    if (!consp(v0098)) { popv(1); return onevalue(v0202); }
    {
        popv(1);
        fn = elt(env, 6); /* bf2flck */
        return (*qfn1(fn))(qenv(fn), v0202);
    }
/* error exit handlers */
v0023:
    popv(1);
    return nil;
}



/* Code for domain!*p */

static Lisp_Object CC_domainHp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0058;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domain*p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0058 = v0000;
/* end of prologue */
    v0055 = v0058;
    if (v0055 == nil) goto v0030;
    v0055 = v0058;
    v0055 = (is_number(v0055) ? lisp_true : nil);
    if (!(v0055 == nil)) return onevalue(v0055);
    v0055 = v0058;
    if (!consp(v0055)) goto v0059;
    v0055 = v0058;
    v0055 = qcar(v0055);
    v0058 = qvalue(elt(env, 2)); /* domainlist!* */
    v0055 = Lmemq(nil, v0055, v0058);
    return onevalue(v0055);

v0059:
    v0055 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0055);

v0030:
    v0055 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0055);
}



/* Code for add2inputbuf */

static Lisp_Object CC_add2inputbuf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0115, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add2inputbuf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    fn = elt(env, 6); /* terminalp */
    v0094 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    if (v0094 == nil) goto v0050;
    v0094 = qvalue(elt(env, 2)); /* !*nosave!* */
    goto v0049;

v0049:
    if (v0094 == nil) goto v0083;
    v0094 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0094); }

v0083:
    v0025 = qvalue(elt(env, 4)); /* statcounter */
    v0115 = stack[0];
    v0094 = stack[-1];
    v0115 = list3(v0025, v0115, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0094 = qvalue(elt(env, 5)); /* inputbuflis!* */
    v0094 = cons(v0115, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    qvalue(elt(env, 5)) = v0094; /* inputbuflis!* */
    v0094 = nil;
    { popv(3); return onevalue(v0094); }

v0050:
    v0094 = qvalue(elt(env, 1)); /* t */
    goto v0049;
/* error exit handlers */
v0120:
    popv(3);
    return nil;
}



/* Code for exptmod!: */

static Lisp_Object CC_exptmodT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptmod:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0089 = v0047;
    v0057 = v0000;
/* end of prologue */
    v0057 = qcdr(v0057);
    fn = elt(env, 1); /* general!-modular!-expt */
    v0089 = (*qfn2(fn))(qenv(fn), v0057, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0089);
    }
/* error exit handlers */
v0095:
    popv(1);
    return nil;
}



/* Code for ofsf_vareqnp */

static Lisp_Object CC_ofsf_vareqnp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0210, v0209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_vareqnp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0210 = v0047;
    v0209 = v0000;
/* end of prologue */
    v0210 = qcdr(v0210);
    v0210 = qcar(v0210);
    {
        fn = elt(env, 1); /* sfto_varisnump */
        return (*qfn1(fn))(qenv(fn), v0210);
    }
}



/* Code for frvarsof */

static Lisp_Object CC_frvarsof(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0023, v0068, v0113;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for frvarsof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0023 = v0047;
    v0068 = v0000;
/* end of prologue */

v0050:
    v0113 = v0068;
    v0022 = qvalue(elt(env, 1)); /* frlis!* */
    v0022 = Lmemq(nil, v0113, v0022);
    if (v0022 == nil) goto v0049;
    v0113 = v0068;
    v0022 = v0023;
    v0022 = Lmemq(nil, v0113, v0022);
    if (!(v0022 == nil)) { popv(2); return onevalue(v0023); }
    stack[0] = v0023;
    v0022 = v0068;
    v0022 = ncons(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    {
        Lisp_Object v0231 = stack[0];
        popv(2);
        return Lappend(nil, v0231, v0022);
    }

v0049:
    v0022 = v0068;
    if (!consp(v0022)) { popv(2); return onevalue(v0023); }
    v0022 = v0068;
    v0022 = qcdr(v0022);
    stack[0] = v0022;
    v0022 = v0068;
    v0022 = qcar(v0022);
    v0022 = CC_frvarsof(env, v0022, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    v0023 = v0022;
    v0022 = stack[0];
    v0068 = v0022;
    goto v0050;
/* error exit handlers */
v0086:
    popv(2);
    return nil;
}



/* Code for mri_0mk2 */

static Lisp_Object MS_CDECL CC_mri_0mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0047,
                         Lisp_Object v0087, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0080, v0081, v0052;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mri_0mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0081 = v0087;
    v0079 = v0047;
    v0080 = v0000;
/* end of prologue */
    v0052 = qvalue(elt(env, 1)); /* nil */
    return list4(v0080, v0079, v0052, v0081);
}



/* Code for ibalp_calcmom */

static Lisp_Object CC_ibalp_calcmom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0034;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_calcmom");
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
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0034 = qcar(v0093);
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcar(v0093);
    v0034 = plus2(v0034, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-2];
    v0093 = (Lisp_Object)513; /* 32 */
    stack[-1] = times2(v0034, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-2];
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0034 = qcar(v0093);
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcar(v0093);
    v0093 = times2(v0034, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    {
        Lisp_Object v0239 = stack[-1];
        popv(3);
        return plus2(v0239, v0093);
    }
/* error exit handlers */
v0097:
    popv(3);
    return nil;
}



/* Code for omobjs */

static Lisp_Object MS_CDECL CC_omobjs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobjs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omobjs");
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
    v0119 = qvalue(elt(env, 1)); /* char */
    v0114 = elt(env, 2); /* (!/ o m a) */
    if (equal(v0119, v0114)) goto v0074;
    fn = elt(env, 4); /* omobj */
    v0114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-1];
    stack[0] = v0114;
    fn = elt(env, 5); /* lex */
    v0114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-1];
    v0114 = CC_omobjs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    v0119 = stack[0];
    if (v0119 == nil) goto v0082;
    v0119 = stack[0];
    popv(2);
    return cons(v0119, v0114);

v0082:
    v0119 = stack[0];
        popv(2);
        return Lappend(nil, v0119, v0114);

v0074:
    v0114 = nil;
    { popv(2); return onevalue(v0114); }
/* error exit handlers */
v0241:
    popv(2);
    return nil;
}



/* Code for groebsearchinlist */

static Lisp_Object CC_groebsearchinlist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsearchinlist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */

v0235:
    v0054 = stack[0];
    if (v0054 == nil) goto v0209;
    v0054 = stack[0];
    v0054 = qcar(v0054);
    v0054 = qcdr(v0054);
    v0055 = qcar(v0054);
    v0054 = stack[-1];
    fn = elt(env, 2); /* buchvevdivides!? */
    v0054 = (*qfn2(fn))(qenv(fn), v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    if (v0054 == nil) goto v0064;
    v0054 = stack[0];
    v0054 = qcar(v0054);
    { popv(3); return onevalue(v0054); }

v0064:
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[0] = v0054;
    goto v0235;

v0209:
    v0054 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0054); }
/* error exit handlers */
v0076:
    popv(3);
    return nil;
}



/* Code for !:difference */

static Lisp_Object CC_Tdifference(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0239, v0202, v0098;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0202 = v0047;
    v0098 = v0000;
/* end of prologue */
    v0097 = v0098;
    if (v0097 == nil) goto v0235;
    v0097 = v0202;
    if (v0097 == nil) return onevalue(v0098);
    v0239 = v0098;
    v0097 = v0202;
    if (equal(v0239, v0097)) goto v0057;
    v0097 = v0098;
    if (!consp(v0097)) goto v0063;
    v0097 = qvalue(elt(env, 1)); /* nil */
    goto v0064;

v0064:
    if (v0097 == nil) goto v0069;
    v0097 = v0098;
    v0239 = v0202;
    return difference2(v0097, v0239);

v0069:
    v0239 = v0098;
    v0097 = elt(env, 2); /* difference */
    {
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0239, v0202, v0097);
    }

v0063:
    v0097 = v0202;
    v0097 = (consp(v0097) ? nil : lisp_true);
    goto v0064;

v0057:
    v0097 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0097);

v0235:
    v0097 = v0202;
    {
        fn = elt(env, 4); /* !:minus */
        return (*qfn1(fn))(qenv(fn), v0097);
    }
}



/* Code for optype */

static Lisp_Object CC_optype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0050;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for optype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0049 = v0000;
/* end of prologue */
    v0050 = elt(env, 1); /* !*optype!* */
    return get(v0049, v0050);
}



/* Code for getphystype */

static Lisp_Object CC_getphystype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0244, v0245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystype");
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
    v0244 = stack[0];
    fn = elt(env, 8); /* physopp */
    v0244 = (*qfn1(fn))(qenv(fn), v0244);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-2];
    if (v0244 == nil) goto v0209;
    v0244 = stack[0];
    fn = elt(env, 9); /* scalopp */
    v0244 = (*qfn1(fn))(qenv(fn), v0244);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-2];
    if (v0244 == nil) goto v0057;
    v0244 = elt(env, 1); /* scalar */
    { popv(3); return onevalue(v0244); }

v0057:
    v0244 = stack[0];
    fn = elt(env, 10); /* vecopp */
    v0244 = (*qfn1(fn))(qenv(fn), v0244);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-2];
    if (v0244 == nil) goto v0080;
    v0244 = elt(env, 2); /* vector */
    { popv(3); return onevalue(v0244); }

v0080:
    v0244 = stack[0];
    fn = elt(env, 11); /* tensopp */
    v0244 = (*qfn1(fn))(qenv(fn), v0244);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-2];
    if (v0244 == nil) goto v0003;
    v0244 = elt(env, 3); /* tensor */
    { popv(3); return onevalue(v0244); }

v0003:
    v0244 = stack[0];
    fn = elt(env, 12); /* statep */
    v0244 = (*qfn1(fn))(qenv(fn), v0244);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-2];
    if (v0244 == nil) goto v0058;
    v0244 = elt(env, 4); /* state */
    { popv(3); return onevalue(v0244); }

v0058:
    v0244 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0244); }

v0209:
    v0244 = stack[0];
    if (!consp(v0244)) goto v0024;
    v0244 = stack[0];
    v0244 = qcar(v0244);
    if (!symbolp(v0244)) v0245 = nil;
    else { v0245 = qfastgets(v0244);
           if (v0245 != nil) { v0245 = elt(v0245, 18); /* phystype */
#ifdef RECORD_GET
             if (v0245 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0245 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0245 == SPID_NOPROP) v0245 = nil; }}
#endif
    v0244 = v0245;
    if (!(v0245 == nil)) { popv(3); return onevalue(v0244); }
    v0244 = stack[0];
    v0245 = qcar(v0244);
    v0244 = elt(env, 6); /* phystypefn */
    v0245 = get(v0245, v0244);
    env = stack[-2];
    v0244 = v0245;
    if (v0245 == nil) goto v0069;
    v0245 = v0244;
    v0244 = stack[0];
    v0244 = qcdr(v0244);
        popv(3);
        return Lapply1(nil, v0245, v0244);

v0069:
    v0244 = stack[0];
    fn = elt(env, 13); /* collectphystype */
    v0245 = (*qfn1(fn))(qenv(fn), v0244);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-2];
    v0244 = v0245;
    if (v0245 == nil) goto v0086;
    v0245 = v0244;
    v0245 = qcdr(v0245);
    if (v0245 == nil) goto v0237;
    v0245 = elt(env, 4); /* state */
    v0244 = Lmember(nil, v0245, v0244);
    if (v0244 == nil) goto v0246;
    v0244 = elt(env, 4); /* state */
    { popv(3); return onevalue(v0244); }

v0246:
    stack[-1] = elt(env, 0); /* getphystype */
    v0245 = elt(env, 7); /* "PHYSOP type conflict in" */
    v0244 = stack[0];
    v0244 = list2(v0245, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-2];
    {
        Lisp_Object v0247 = stack[-1];
        popv(3);
        fn = elt(env, 14); /* rederr2 */
        return (*qfn2(fn))(qenv(fn), v0247, v0244);
    }

v0237:
    v0244 = qcar(v0244);
    { popv(3); return onevalue(v0244); }

v0086:
    v0244 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0244); }

v0024:
    v0244 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0244); }
/* error exit handlers */
v0122:
    popv(3);
    return nil;
}



/* Code for contrsp2 */

static Lisp_Object MS_CDECL CC_contrsp2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0047,
                         Lisp_Object v0087, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0023;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contrsp2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contrsp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0087,v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0047,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0087;
    stack[-1] = v0047;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = (Lisp_Object)33; /* 2 */
    v0022 = stack[-2];
    v0022 = Llength(nil, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-4];
    if (stack[-3] == v0022) goto v0081;
    v0022 = nil;
    { popv(5); return onevalue(v0022); }

v0081:
    v0023 = stack[0];
    v0022 = stack[-2];
    v0022 = qcar(v0022);
    if (equal(v0023, v0022)) goto v0059;
    v0023 = stack[0];
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    v0022 = qcar(v0022);
    if (equal(v0023, v0022)) goto v0065;
    v0022 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0022); }

v0065:
    v0022 = stack[-2];
    v0023 = qcar(v0022);
    v0022 = stack[-1];
    popv(5);
    return cons(v0023, v0022);

v0059:
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    v0023 = qcar(v0022);
    v0022 = stack[-1];
    popv(5);
    return cons(v0023, v0022);
/* error exit handlers */
v0231:
    popv(5);
    return nil;
}



/* Code for formc */

static Lisp_Object MS_CDECL CC_formc(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0047,
                         Lisp_Object v0087, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0078, v0090, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0087,v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0047,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0087;
    stack[-1] = v0047;
    stack[-2] = v0000;
/* end of prologue */
    v0203 = qvalue(elt(env, 1)); /* !*rlisp88 */
    if (v0203 == nil) goto v0114;
    v0078 = stack[-2];
    v0203 = elt(env, 2); /* modefn */
    v0203 = Lflagpcar(nil, v0078, v0203);
    env = stack[-3];
    if (v0203 == nil) goto v0114;
    v0203 = stack[-2];
    v0078 = qcar(v0203);
    v0203 = elt(env, 3); /* symbolic */
    if (v0078 == v0203) goto v0114;
    v0078 = elt(env, 4); /* "algebraic expression" */
    v0203 = elt(env, 5); /* "Rlisp88 form" */
    {
        popv(4);
        fn = elt(env, 8); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0078, v0203);
    }

v0114:
    v0078 = stack[0];
    v0203 = elt(env, 6); /* algebraic */
    if (v0078 == v0203) goto v0033;
    v0203 = qvalue(elt(env, 7)); /* nil */
    goto v0240;

v0240:
    if (!(v0203 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0018 = stack[-2];
    v0090 = stack[-1];
    v0078 = elt(env, 3); /* symbolic */
    v0203 = stack[0];
    {
        popv(4);
        fn = elt(env, 9); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v0018, v0090, v0078, v0203);
    }

v0033:
    v0078 = stack[-2];
    v0203 = stack[-1];
    fn = elt(env, 10); /* intexprnp */
    v0203 = (*qfn2(fn))(qenv(fn), v0078, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-3];
    goto v0240;
/* error exit handlers */
v0112:
    popv(4);
    return nil;
}



/* Code for ckpreci!# */

static Lisp_Object CC_ckpreciC(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0239, v0202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ckpreci#");
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
    v0097 = stack[0];
    v0097 = qcar(v0097);
    fn = elt(env, 3); /* timesip */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    v0097 = qcar(v0097);
    fn = elt(env, 3); /* timesip */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    v0202 = stack[-1];
    v0239 = v0097;
    v0097 = qvalue(elt(env, 1)); /* !*complex */
    if (v0097 == nil) goto v0089;
    v0097 = v0202;
    if (v0097 == nil) goto v0053;
    v0097 = v0239;
    if (!(v0097 == nil)) goto v0053;
    v0097 = stack[0];
    v0097 = qcar(v0097);
    v0239 = qcdr(v0097);
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    v0097 = qcar(v0097);
    {
        popv(3);
        fn = elt(env, 4); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v0239, v0097);
    }

v0053:
    v0097 = v0239;
    if (v0097 == nil) goto v0240;
    v0097 = v0202;
    if (!(v0097 == nil)) goto v0240;
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    v0097 = qcar(v0097);
    v0239 = qcdr(v0097);
    v0097 = stack[0];
    v0097 = qcar(v0097);
    {
        popv(3);
        fn = elt(env, 4); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v0239, v0097);
    }

v0240:
    v0097 = nil;
    { popv(3); return onevalue(v0097); }

v0089:
    v0097 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0097); }
/* error exit handlers */
v0023:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-minusp */

static Lisp_Object CC_mvKpowKminusp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0083;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-minusp");
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

v0029:
    v0082 = stack[0];
    if (v0082 == nil) goto v0030;
    v0082 = stack[0];
    v0083 = qcar(v0082);
    v0082 = (Lisp_Object)1; /* 0 */
    v0082 = (Lisp_Object)lessp2(v0083, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    v0082 = v0082 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0082 == nil)) { popv(2); return onevalue(v0082); }
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    stack[0] = v0082;
    goto v0029;

v0030:
    v0082 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0082); }
/* error exit handlers */
v0063:
    popv(2);
    return nil;
}



/* Code for divd */

static Lisp_Object CC_divd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0013, v0250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0047;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0074;

v0074:
    v0012 = stack[-1];
    if (v0012 == nil) goto v0048;
    v0012 = stack[-2];
    if (v0012 == nil) goto v0096;
    v0012 = stack[-2];
    if (!consp(v0012)) goto v0113;
    v0012 = stack[-2];
    v0012 = qcar(v0012);
    v0012 = (consp(v0012) ? nil : lisp_true);
    goto v0068;

v0068:
    if (v0012 == nil) goto v0246;
    stack[0] = stack[-3];
    v0013 = stack[-2];
    v0012 = stack[-1];
    fn = elt(env, 5); /* divdm */
    v0012 = (*qfn2(fn))(qenv(fn), v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    {
        Lisp_Object v0252 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0252, v0012);
    }

v0246:
    v0012 = stack[-2];
    v0012 = qcar(v0012);
    stack[0] = qcar(v0012);
    v0012 = stack[-2];
    v0012 = qcar(v0012);
    v0013 = qcdr(v0012);
    v0012 = stack[-1];
    v0013 = CC_divd(env, v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    v0012 = stack[-3];
    v0012 = acons(stack[0], v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    stack[-3] = v0012;
    v0012 = stack[-2];
    v0012 = qcdr(v0012);
    stack[-2] = v0012;
    goto v0074;

v0113:
    v0012 = qvalue(elt(env, 4)); /* t */
    goto v0068;

v0096:
    v0012 = stack[-3];
    {
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0012);
    }

v0048:
    v0012 = stack[-2];
    if (v0012 == nil) goto v0079;
    stack[0] = stack[-3];
    v0250 = elt(env, 1); /* poly */
    v0013 = (Lisp_Object)33; /* 2 */
    v0012 = elt(env, 3); /* "Zero divisor" */
    fn = elt(env, 7); /* rerror */
    v0012 = (*qfnn(fn))(qenv(fn), 3, v0250, v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    {
        Lisp_Object v0198 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0198, v0012);
    }

v0079:
    stack[0] = stack[-3];
    v0250 = elt(env, 1); /* poly */
    v0013 = (Lisp_Object)17; /* 1 */
    v0012 = elt(env, 2); /* "0/0 formed" */
    fn = elt(env, 7); /* rerror */
    v0012 = (*qfnn(fn))(qenv(fn), 3, v0250, v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    {
        Lisp_Object v0043 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0043, v0012);
    }
/* error exit handlers */
v0251:
    popv(5);
    return nil;
}



/* Code for dp!=ecart */

static Lisp_Object CC_dpMecart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119, v0118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=ecart");
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
    stack[-1] = nil;
    goto v0074;

v0074:
    v0119 = stack[0];
    if (v0119 == nil) goto v0210;
    v0119 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-2];
    fn = elt(env, 2); /* mo_ecart */
    v0118 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-2];
    v0119 = stack[-1];
    v0119 = cons(v0118, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-2];
    stack[-1] = v0119;
    v0119 = stack[0];
    v0119 = qcdr(v0119);
    stack[0] = v0119;
    goto v0074;

v0210:
    v0119 = (Lisp_Object)1; /* 0 */
    v0118 = v0119;
    goto v0209;

v0209:
    v0119 = stack[-1];
    if (v0119 == nil) { popv(3); return onevalue(v0118); }
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = Lmax2(nil, v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-2];
    v0118 = v0119;
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    stack[-1] = v0119;
    goto v0209;
/* error exit handlers */
v0070:
    popv(3);
    return nil;
}



/* Code for pappl_pv */

static Lisp_Object CC_pappl_pv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0238;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappl_pv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0035 = v0047;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = v0035;
    v0035 = stack[-5];
    if (v0035 == nil) goto v0089;
    v0035 = stack[-5];
    v0035 = qcar(v0035);
    v0238 = v0035;
    stack[0] = qcar(v0238);
    v0238 = stack[-4];
    v0035 = qcdr(v0035);
    fn = elt(env, 2); /* pappl0 */
    v0035 = (*qfn2(fn))(qenv(fn), v0238, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-6];
    v0035 = cons(stack[0], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-6];
    v0035 = ncons(v0035);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-6];
    stack[-2] = v0035;
    stack[-3] = v0035;
    goto v0048;

v0048:
    v0035 = stack[-5];
    v0035 = qcdr(v0035);
    stack[-5] = v0035;
    v0035 = stack[-5];
    if (v0035 == nil) goto v0120;
    stack[-1] = stack[-2];
    v0035 = stack[-5];
    v0035 = qcar(v0035);
    v0238 = v0035;
    stack[0] = qcar(v0238);
    v0238 = stack[-4];
    v0035 = qcdr(v0035);
    fn = elt(env, 2); /* pappl0 */
    v0035 = (*qfn2(fn))(qenv(fn), v0238, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-6];
    v0035 = cons(stack[0], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-6];
    v0035 = ncons(v0035);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-6];
    v0035 = Lrplacd(nil, stack[-1], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-6];
    v0035 = stack[-2];
    v0035 = qcdr(v0035);
    stack[-2] = v0035;
    goto v0048;

v0120:
    v0035 = stack[-3];
    goto v0209;

v0209:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v0035);
    }

v0089:
    v0035 = qvalue(elt(env, 1)); /* nil */
    goto v0209;
/* error exit handlers */
v0243:
    popv(7);
    return nil;
}



/* Code for general!-modular!-minus */

static Lisp_Object CC_generalKmodularKminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0082, v0083;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-minus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0083 = v0000;
/* end of prologue */
    v0082 = v0083;
    v0003 = (Lisp_Object)1; /* 0 */
    if (v0082 == v0003) return onevalue(v0083);
    v0003 = qvalue(elt(env, 1)); /* current!-modulus */
    v0082 = v0083;
    return difference2(v0003, v0082);
}



/* Code for lto_insert */

static Lisp_Object CC_lto_insert(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0064, v0063, v0059;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_insert");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0064 = v0047;
    v0063 = v0000;
/* end of prologue */
    v0059 = v0063;
    v0083 = v0064;
    v0083 = Lmember(nil, v0059, v0083);
    if (!(v0083 == nil)) return onevalue(v0064);
    v0083 = v0063;
    return cons(v0083, v0064);
}



/* Code for cl_simplat */

static Lisp_Object CC_cl_simplat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0077, v0076;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_simplat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0077 = v0047;
    v0076 = v0000;
/* end of prologue */
    v0058 = qvalue(elt(env, 1)); /* !*rlidentify */
    if (v0058 == nil) goto v0048;
    v0058 = v0076;
    fn = elt(env, 3); /* rl_simplat1 */
    v0077 = (*qfn2(fn))(qenv(fn), v0058, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[0];
    v0058 = elt(env, 2); /* cl_identifyat */
    {
        popv(1);
        fn = elt(env, 4); /* cl_apply2ats */
        return (*qfn2(fn))(qenv(fn), v0077, v0058);
    }

v0048:
    v0058 = v0076;
    {
        popv(1);
        fn = elt(env, 3); /* rl_simplat1 */
        return (*qfn2(fn))(qenv(fn), v0058, v0077);
    }
/* error exit handlers */
v0024:
    popv(1);
    return nil;
}



/* Code for ibalp_varlat */

static Lisp_Object CC_ibalp_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlat");
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
    v0057 = stack[0];
    fn = elt(env, 1); /* ibalp_arg2l */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0057 = stack[0];
    fn = elt(env, 3); /* ibalp_arg2r */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    {
        Lisp_Object v0079 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* union */
        return (*qfn2(fn))(qenv(fn), v0079, v0057);
    }
/* error exit handlers */
v0046:
    popv(3);
    return nil;
}



/* Code for reval1 */

static Lisp_Object CC_reval1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0303, v0304, v0305;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0047;
    stack[-2] = v0000;
/* end of prologue */
    v0303 = qvalue(elt(env, 1)); /* !*revalp */
    if (v0303 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0303 = qvalue(elt(env, 2)); /* varstack!* */
    stack[-3] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0303; /* varstack!* */
    v0303 = stack[-2];
    if (v0303 == nil) goto v0080;
    v0303 = stack[-2];
    v0303 = Lstringp(nil, v0303);
    env = stack[-4];
    if (v0303 == nil) goto v0003;
    v0303 = stack[-2];
    goto v0056;

v0056:
    qvalue(elt(env, 2)) = stack[-3]; /* varstack!* */
    { popv(5); return onevalue(v0303); }

v0003:
    v0303 = stack[-2];
    v0303 = integerp(v0303);
    if (v0303 == nil) goto v0059;
    v0303 = qvalue(elt(env, 4)); /* dmode!* */
    if (!symbolp(v0303)) v0303 = nil;
    else { v0303 = qfastgets(v0303);
           if (v0303 != nil) { v0303 = elt(v0303, 5); /* convert */
#ifdef RECORD_GET
             if (v0303 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0303 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0303 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0303 == SPID_NOPROP) v0303 = nil; else v0303 = lisp_true; }}
#endif
    if (v0303 == nil) goto v0241;
    v0304 = stack[-2];
    v0303 = stack[-1];
    fn = elt(env, 20); /* reval2 */
    v0303 = (*qfn2(fn))(qenv(fn), v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0241:
    v0303 = stack[-2];
    goto v0056;

v0059:
    v0303 = stack[-2];
    if (!consp(v0303)) goto v0067;
    v0303 = stack[-2];
    v0303 = qcar(v0303);
    if (symbolp(v0303)) goto v0307;
    v0304 = stack[-2];
    v0303 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 21); /* errpri2 */
    v0303 = (*qfn2(fn))(qenv(fn), v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0079;

v0079:
    v0303 = stack[-2];
    fn = elt(env, 22); /* getrtype */
    v0303 = (*qfn1(fn))(qenv(fn), v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    stack[0] = v0303;
    if (v0303 == nil) goto v0308;
    v0304 = stack[0];
    v0303 = elt(env, 6); /* evfn */
    v0303 = get(v0304, v0303);
    env = stack[-4];
    v0305 = v0303;
    if (v0303 == nil) goto v0309;
    v0304 = stack[-2];
    v0303 = stack[-1];
    v0303 = Lapply2(nil, 3, v0305, v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0309:
    stack[-2] = elt(env, 11); /* alg */
    stack[-1] = (Lisp_Object)1617; /* 101 */
    v0304 = elt(env, 12); /* "Missing evaluation for type" */
    v0303 = stack[0];
    v0303 = list2(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    fn = elt(env, 23); /* rerror */
    v0303 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0308:
    v0303 = stack[-2];
    if (!consp(v0303)) goto v0310;
    v0303 = stack[-2];
    v0303 = qcdr(v0303);
    if (!consp(v0303)) goto v0157;
    v0303 = stack[-2];
    v0303 = qcdr(v0303);
    v0303 = qcar(v0303);
    fn = elt(env, 22); /* getrtype */
    v0303 = (*qfn1(fn))(qenv(fn), v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    v0305 = v0303;
    if (v0303 == nil) goto v0311;
    v0304 = v0305;
    v0303 = elt(env, 13); /* list */
    if (v0304 == v0303) goto v0171;
    v0303 = qvalue(elt(env, 3)); /* nil */
    goto v0312;

v0312:
    if (v0303 == nil) goto v0313;
    v0303 = qvalue(elt(env, 3)); /* nil */
    goto v0314;

v0314:
    if (v0303 == nil) goto v0315;
    v0305 = stack[0];
    v0304 = stack[-2];
    v0303 = stack[-1];
    v0303 = Lapply2(nil, 3, v0305, v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0315:
    v0304 = stack[-2];
    v0303 = stack[-1];
    fn = elt(env, 20); /* reval2 */
    v0303 = (*qfn2(fn))(qenv(fn), v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0313:
    v0304 = v0305;
    v0303 = elt(env, 14); /* aggregatefn */
    v0303 = get(v0304, v0303);
    env = stack[-4];
    stack[0] = v0303;
    if (v0303 == nil) goto v0316;
    v0304 = stack[0];
    v0303 = elt(env, 15); /* matrixmap */
    if (v0304 == v0303) goto v0317;
    v0303 = qvalue(elt(env, 7)); /* t */
    goto v0318;

v0318:
    if (v0303 == nil) goto v0319;
    v0303 = stack[-2];
    v0304 = qcar(v0303);
    v0303 = elt(env, 17); /* boolean */
    v0303 = Lflagp(nil, v0304, v0303);
    env = stack[-4];
    if (v0303 == nil) goto v0320;
    v0303 = qvalue(elt(env, 3)); /* nil */
    goto v0314;

v0320:
    v0303 = qvalue(elt(env, 18)); /* !*listargs */
    if (v0303 == nil) goto v0321;
    v0303 = qvalue(elt(env, 3)); /* nil */
    goto v0314;

v0321:
    v0303 = stack[-2];
    v0304 = qcar(v0303);
    v0303 = elt(env, 19); /* listargp */
    v0303 = Lflagp(nil, v0304, v0303);
    env = stack[-4];
    v0303 = (v0303 == nil ? lisp_true : nil);
    goto v0314;

v0319:
    v0303 = qvalue(elt(env, 3)); /* nil */
    goto v0314;

v0317:
    v0303 = stack[-2];
    v0304 = qcar(v0303);
    v0303 = elt(env, 16); /* matmapfn */
    v0303 = Lflagp(nil, v0304, v0303);
    env = stack[-4];
    goto v0318;

v0316:
    v0303 = qvalue(elt(env, 3)); /* nil */
    goto v0314;

v0171:
    v0303 = stack[-2];
    v0303 = qcdr(v0303);
    v0303 = qcdr(v0303);
    goto v0312;

v0311:
    v0303 = qvalue(elt(env, 3)); /* nil */
    goto v0314;

v0157:
    v0303 = qvalue(elt(env, 3)); /* nil */
    goto v0314;

v0310:
    v0303 = qvalue(elt(env, 3)); /* nil */
    goto v0314;

v0307:
    v0303 = stack[-2];
    v0304 = qcar(v0303);
    v0303 = elt(env, 8); /* !*sq */
    if (v0304 == v0303) goto v0322;
    v0303 = stack[-2];
    v0303 = qcar(v0303);
    if (!symbolp(v0303)) v0303 = nil;
    else { v0303 = qfastgets(v0303);
           if (v0303 != nil) { v0303 = elt(v0303, 39); /* remember */
#ifdef RECORD_GET
             if (v0303 == SPID_NOPROP)
                record_get(elt(fastget_names, 39), 0),
                v0303 = nil;
             else record_get(elt(fastget_names, 39), 1),
                v0303 = lisp_true; }
           else record_get(elt(fastget_names, 39), 0); }
#else
             if (v0303 == SPID_NOPROP) v0303 = nil; else v0303 = lisp_true; }}
#endif
    if (v0303 == nil) goto v0002;
    v0304 = stack[-2];
    v0303 = stack[-1];
    fn = elt(env, 24); /* rmmbreval */
    v0303 = (*qfn2(fn))(qenv(fn), v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0002:
    v0303 = stack[-2];
    v0303 = qcar(v0303);
    if (!symbolp(v0303)) v0303 = nil;
    else { v0303 = qfastgets(v0303);
           if (v0303 != nil) { v0303 = elt(v0303, 59); /* opfn */
#ifdef RECORD_GET
             if (v0303 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0303 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0303 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0303 == SPID_NOPROP) v0303 = nil; else v0303 = lisp_true; }}
#endif
    if (v0303 == nil) goto v0042;
    v0303 = stack[-2];
    fn = elt(env, 25); /* opfneval */
    v0304 = (*qfn1(fn))(qenv(fn), v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    v0303 = stack[-1];
    v0303 = CC_reval1(env, v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0042:
    v0303 = stack[-2];
    v0303 = qcar(v0303);
    if (!symbolp(v0303)) v0303 = nil;
    else { v0303 = qfastgets(v0303);
           if (v0303 != nil) { v0303 = elt(v0303, 45); /* psopfn */
#ifdef RECORD_GET
             if (v0303 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0303 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0303 == SPID_NOPROP) v0303 = nil; }}
#endif
    stack[0] = v0303;
    if (v0303 == nil) goto v0117;
    v0304 = stack[0];
    v0303 = stack[-2];
    v0303 = qcdr(v0303);
    v0303 = Lapply1(nil, v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    stack[-2] = v0303;
    v0304 = stack[0];
    v0303 = elt(env, 10); /* cleanupfn */
    v0303 = get(v0304, v0303);
    env = stack[-4];
    stack[0] = v0303;
    if (v0303 == nil) goto v0323;
    v0305 = stack[0];
    v0304 = stack[-2];
    v0303 = stack[-1];
    v0303 = Lapply2(nil, 3, v0305, v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    stack[-2] = v0303;
    goto v0323;

v0323:
    v0303 = stack[-2];
    goto v0056;

v0117:
    v0303 = stack[-2];
    v0303 = qcar(v0303);
    fn = elt(env, 26); /* arrayp */
    v0303 = (*qfn1(fn))(qenv(fn), v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    if (v0303 == nil) goto v0079;
    v0303 = stack[-2];
    fn = elt(env, 27); /* getelv */
    v0304 = (*qfn1(fn))(qenv(fn), v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    v0303 = stack[-1];
    v0303 = CC_reval1(env, v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0322:
    v0303 = stack[-2];
    v0303 = qcdr(v0303);
    v0303 = qcdr(v0303);
    v0303 = qcar(v0303);
    if (v0303 == nil) goto v0041;
    v0303 = qvalue(elt(env, 9)); /* !*resimp */
    if (!(v0303 == nil)) goto v0041;
    v0303 = stack[-1];
    if (v0303 == nil) goto v0192;
    v0303 = stack[-2];
    v0303 = qcdr(v0303);
    v0303 = qcar(v0303);
    fn = elt(env, 28); /* prepsqxx */
    v0303 = (*qfn1(fn))(qenv(fn), v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0192:
    v0303 = stack[-2];
    goto v0056;

v0041:
    v0304 = stack[-2];
    v0303 = stack[-1];
    fn = elt(env, 20); /* reval2 */
    v0303 = (*qfn2(fn))(qenv(fn), v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0067:
    v0303 = qvalue(elt(env, 5)); /* subfg!* */
    if (v0303 == nil) goto v0034;
    v0303 = stack[-2];
    if (!(symbolp(v0303))) goto v0079;
    v0303 = stack[-2];
    if (!symbolp(v0303)) v0303 = nil;
    else { v0303 = qfastgets(v0303);
           if (v0303 != nil) { v0303 = elt(v0303, 4); /* avalue */
#ifdef RECORD_GET
             if (v0303 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0303 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0303 == SPID_NOPROP) v0303 = nil; }}
#endif
    stack[0] = v0303;
    if (v0303 == nil) goto v0079;
    v0304 = stack[-2];
    v0303 = qvalue(elt(env, 2)); /* varstack!* */
    v0303 = Lmemq(nil, v0304, v0303);
    if (v0303 == nil) goto v0019;
    v0303 = stack[-2];
    fn = elt(env, 29); /* recursiveerror */
    v0303 = (*qfn1(fn))(qenv(fn), v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0079;

v0019:
    v0304 = stack[-2];
    v0303 = qvalue(elt(env, 2)); /* varstack!* */
    v0303 = cons(v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0303; /* varstack!* */
    v0303 = stack[0];
    v0304 = qcar(v0303);
    v0303 = elt(env, 6); /* evfn */
    v0303 = get(v0304, v0303);
    env = stack[-4];
    v0305 = v0303;
    if (v0303 == nil) goto v0250;
    v0304 = stack[-2];
    v0303 = stack[-1];
    v0303 = Lapply2(nil, 3, v0305, v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0250:
    v0303 = stack[0];
    v0303 = qcdr(v0303);
    v0304 = qcar(v0303);
    v0303 = stack[-1];
    v0303 = CC_reval1(env, v0304, v0303);
    nil = C_nil;
    if (exception_pending()) goto v0306;
    env = stack[-4];
    goto v0056;

v0034:
    v0303 = stack[-2];
    goto v0056;

v0080:
    v0303 = qvalue(elt(env, 3)); /* nil */
    goto v0056;
/* error exit handlers */
v0306:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* varstack!* */
    popv(5);
    return nil;
}



/* Code for evaluate0 */

static Lisp_Object CC_evaluate0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0089;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    v0051 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* evaluate!-horner */
    v0089 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-1];
    v0051 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* evaluate1 */
        return (*qfn2(fn))(qenv(fn), v0089, v0051);
    }
/* error exit handlers */
v0095:
    popv(2);
    return nil;
}



/* Code for simpplus */

static Lisp_Object CC_simpplus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpplus");
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
    v0118 = stack[0];
    v0241 = Llength(nil, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-2];
    v0118 = (Lisp_Object)33; /* 2 */
    if (!(v0241 == v0118)) goto v0052;
    v0118 = stack[0];
    fn = elt(env, 2); /* ckpreci!# */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-2];
    goto v0052;

v0052:
    v0241 = qvalue(elt(env, 1)); /* nil */
    v0118 = (Lisp_Object)17; /* 1 */
    v0118 = cons(v0241, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-2];
    stack[-1] = v0118;
    goto v0235;

v0235:
    v0118 = stack[0];
    if (v0118 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0118 = stack[0];
    fn = elt(env, 3); /* simpcar */
    v0241 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-2];
    v0118 = stack[-1];
    fn = elt(env, 4); /* addsq */
    v0118 = (*qfn2(fn))(qenv(fn), v0241, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-2];
    stack[-1] = v0118;
    v0118 = stack[0];
    v0118 = qcdr(v0118);
    stack[0] = v0118;
    goto v0235;
/* error exit handlers */
v0067:
    popv(3);
    return nil;
}



/* Code for rnplus!: */

static Lisp_Object CC_rnplusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnplus:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0033 = stack[-1];
    v0033 = qcdr(v0033);
    v0092 = qcar(v0033);
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    v0033 = qcdr(v0033);
    stack[-2] = times2(v0092, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    v0033 = stack[-1];
    v0033 = qcdr(v0033);
    v0092 = qcdr(v0033);
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    v0033 = qcar(v0033);
    v0033 = times2(v0092, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    stack[-2] = plus2(stack[-2], v0033);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    v0033 = stack[-1];
    v0033 = qcdr(v0033);
    v0092 = qcdr(v0033);
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    v0033 = qcdr(v0033);
    v0033 = times2(v0092, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    {
        Lisp_Object v0097 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0097, v0033);
    }
/* error exit handlers */
v0031:
    popv(4);
    return nil;
}



/* Code for dp_sum */

static Lisp_Object CC_dp_sum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0301, v0302, v0322;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_sum");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */

v0029:
    v0301 = stack[-1];
    if (v0301 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0301 = stack[0];
    if (v0301 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0301 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-3];
    v0301 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-3];
    fn = elt(env, 2); /* mo_compare */
    v0301 = (*qfn2(fn))(qenv(fn), stack[-2], v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-3];
    v0322 = v0301;
    v0302 = v0322;
    v0301 = (Lisp_Object)17; /* 1 */
    if (v0302 == v0301) goto v0091;
    v0302 = v0322;
    v0301 = (Lisp_Object)-15; /* -1 */
    if (v0302 == v0301) goto v0233;
    v0301 = stack[-1];
    fn = elt(env, 3); /* dp_lc */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-3];
    v0301 = stack[0];
    fn = elt(env, 3); /* dp_lc */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-3];
    fn = elt(env, 4); /* bc_sum */
    v0301 = (*qfn2(fn))(qenv(fn), stack[-2], v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-3];
    stack[-2] = v0301;
    v0301 = stack[-2];
    fn = elt(env, 5); /* bc_zero!? */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-3];
    if (v0301 == nil) goto v0252;
    v0301 = stack[-1];
    v0302 = qcdr(v0301);
    v0301 = stack[0];
    v0301 = qcdr(v0301);
    stack[-1] = v0302;
    stack[0] = v0301;
    goto v0029;

v0252:
    v0301 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    v0301 = (*qfn1(fn))(qenv(fn), v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-3];
    fn = elt(env, 6); /* dp_term */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[-2], v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-3];
    v0301 = stack[-1];
    v0302 = qcdr(v0301);
    v0301 = stack[0];
    v0301 = qcdr(v0301);
    v0301 = CC_dp_sum(env, v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    {
        Lisp_Object v0327 = stack[-2];
        popv(4);
        return cons(v0327, v0301);
    }

v0233:
    v0301 = stack[0];
    stack[-2] = qcar(v0301);
    v0302 = stack[-1];
    v0301 = stack[0];
    v0301 = qcdr(v0301);
    v0301 = CC_dp_sum(env, v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    {
        Lisp_Object v0196 = stack[-2];
        popv(4);
        return cons(v0196, v0301);
    }

v0091:
    v0301 = stack[-1];
    stack[-2] = qcar(v0301);
    v0301 = stack[-1];
    v0302 = qcdr(v0301);
    v0301 = stack[0];
    v0301 = CC_dp_sum(env, v0302, v0301);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    {
        Lisp_Object v0195 = stack[-2];
        popv(4);
        return cons(v0195, v0301);
    }
/* error exit handlers */
v0124:
    popv(4);
    return nil;
}



/* Code for dv_skelhead */

static Lisp_Object CC_dv_skelhead(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skelhead");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0235 = v0000;
/* end of prologue */
    v0235 = qcar(v0235);
    {
        fn = elt(env, 1); /* dv_cambhead */
        return (*qfn1(fn))(qenv(fn), v0235);
    }
}



/* Code for !*i2ar */

static Lisp_Object CC_Hi2ar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0050;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2ar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0049 = v0000;
/* end of prologue */
    v0050 = elt(env, 1); /* !:ar!: */
    return cons(v0050, v0049);
}



/* Code for anforml */

static Lisp_Object CC_anforml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for anforml");
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

v0074:
    v0016 = stack[0];
    if (!consp(v0016)) goto v0235;
    v0016 = stack[0];
    v0016 = qcar(v0016);
    fn = elt(env, 6); /* anform */
    v0016 = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-1];
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    stack[0] = v0016;
    goto v0074;

v0235:
    v0016 = stack[0];
    if (v0016 == nil) goto v0080;
    v0016 = qvalue(elt(env, 2)); /* !*globals */
    if (v0016 == nil) goto v0080;
    v0016 = stack[0];
    if (v0016 == nil) goto v0080;
    v0017 = stack[0];
    v0016 = lisp_true;
    if (v0017 == v0016) goto v0022;
    v0016 = stack[0];
    if (symbolp(v0016)) goto v0092;
    v0016 = qvalue(elt(env, 1)); /* nil */
    goto v0077;

v0077:
    if (v0016 == nil) goto v0080;
    v0017 = stack[0];
    v0016 = elt(env, 4); /* glb2rf */
    v0016 = Lflagp(nil, v0017, v0016);
    env = stack[-1];
    if (!(v0016 == nil)) goto v0080;
    v0016 = stack[0];
    v0017 = ncons(v0016);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-1];
    v0016 = elt(env, 4); /* glb2rf */
    v0016 = Lflag(nil, v0017, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-1];
    v0017 = stack[0];
    v0016 = qvalue(elt(env, 5)); /* globs!* */
    v0016 = cons(v0017, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-1];
    qvalue(elt(env, 5)) = v0016; /* globs!* */
    goto v0080;

v0080:
    v0016 = nil;
    { popv(2); return onevalue(v0016); }

v0092:
    v0017 = stack[0];
    v0016 = qvalue(elt(env, 3)); /* locls!* */
    v0016 = Lassoc(nil, v0017, v0016);
    v0016 = (v0016 == nil ? lisp_true : nil);
    goto v0077;

v0022:
    v0016 = qvalue(elt(env, 1)); /* nil */
    goto v0077;
/* error exit handlers */
v0036:
    popv(2);
    return nil;
}



/* Code for wulessp */

static Lisp_Object CC_wulessp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0326;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wulessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0047;
    stack[-1] = v0000;
/* end of prologue */
    v0326 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v0326 = (*qfn1(fn))(qenv(fn), v0326);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    if (v0326 == nil) goto v0080;
    v0326 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0326;
    goto v0048;

v0048:
    v0326 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v0326 = (*qfn1(fn))(qenv(fn), v0326);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    if (v0326 == nil) goto v0055;
    v0326 = qvalue(elt(env, 1)); /* nil */
    goto v0049;

v0049:
    fn = elt(env, 3); /* symbollessp */
    v0326 = (*qfn2(fn))(qenv(fn), stack[-2], v0326);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    if (!(v0326 == nil)) { popv(4); return onevalue(v0326); }
    v0326 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v0326 = (*qfn1(fn))(qenv(fn), v0326);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    if (v0326 == nil) goto v0034;
    v0326 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0326;
    goto v0119;

v0119:
    v0326 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v0326 = (*qfn1(fn))(qenv(fn), v0326);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    if (v0326 == nil) goto v0231;
    v0326 = qvalue(elt(env, 1)); /* nil */
    goto v0118;

v0118:
    if (equal(stack[-2], v0326)) goto v0021;
    v0326 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0326); }

v0021:
    v0326 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v0326 = (*qfn1(fn))(qenv(fn), v0326);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-3];
    if (v0326 == nil) goto v0062;
    v0326 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0326;
    goto v0035;

v0035:
    v0326 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v0326 = (*qfn1(fn))(qenv(fn), v0326);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    if (v0326 == nil) goto v0329;
    v0326 = (Lisp_Object)1; /* 0 */
    goto v0238;

v0238:
    {
        Lisp_Object v0330 = stack[-1];
        popv(4);
        return Llessp(nil, v0330, v0326);
    }

v0329:
    v0326 = stack[0];
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    v0326 = qcdr(v0326);
    goto v0238;

v0062:
    v0326 = stack[-1];
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    v0326 = qcdr(v0326);
    stack[-1] = v0326;
    goto v0035;

v0231:
    v0326 = stack[0];
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    goto v0118;

v0034:
    v0326 = stack[-1];
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    stack[-2] = v0326;
    goto v0119;

v0055:
    v0326 = stack[0];
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    goto v0049;

v0080:
    v0326 = stack[-1];
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    v0326 = qcar(v0326);
    stack[-2] = v0326;
    goto v0048;
/* error exit handlers */
v0199:
    popv(4);
    return nil;
}



/* Code for stable!-sortip */

static Lisp_Object CC_stableKsortip(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0047)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0293, v0339, v0189;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stable-sortip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0047,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0047);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0047;
    stack[-3] = v0000;
/* end of prologue */
    v0293 = stack[-3];
    if (v0293 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0293 = stack[-3];
    stack[-4] = v0293;
    v0293 = stack[-3];
    v0293 = qcdr(v0293);
    stack[-1] = v0293;
    v0293 = stack[-1];
    if (v0293 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0293 = stack[-1];
    v0293 = qcdr(v0293);
    stack[-3] = v0293;
    v0293 = stack[-3];
    if (v0293 == nil) goto v0076;
    v0293 = stack[-4];
    stack[-3] = v0293;
    goto v0234;

v0234:
    v0293 = stack[-1];
    if (v0293 == nil) goto v0233;
    v0189 = stack[-2];
    v0293 = stack[-1];
    v0339 = qcar(v0293);
    v0293 = stack[-3];
    v0293 = qcar(v0293);
    v0293 = Lapply2(nil, 3, v0189, v0339, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    if (!(v0293 == nil)) goto v0233;
    v0293 = stack[-1];
    stack[-3] = v0293;
    v0293 = stack[-1];
    v0293 = qcdr(v0293);
    stack[-1] = v0293;
    goto v0234;

v0233:
    v0293 = stack[-1];
    if (v0293 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0293 = stack[-4];
    stack[-1] = v0293;
    v0293 = stack[-1];
    v0293 = qcdr(v0293);
    v0293 = qcdr(v0293);
    stack[-3] = v0293;
    goto v0037;

v0037:
    v0293 = stack[-3];
    if (v0293 == nil) goto v0245;
    v0293 = stack[-3];
    v0293 = qcdr(v0293);
    if (v0293 == nil) goto v0245;
    v0293 = stack[-1];
    v0293 = qcdr(v0293);
    stack[-1] = v0293;
    v0293 = stack[-3];
    v0293 = qcdr(v0293);
    v0293 = qcdr(v0293);
    stack[-3] = v0293;
    goto v0037;

v0245:
    v0293 = stack[-1];
    stack[-3] = v0293;
    v0293 = stack[-1];
    v0293 = qcdr(v0293);
    stack[-1] = v0293;
    v0339 = stack[-3];
    v0293 = qvalue(elt(env, 1)); /* nil */
    v0293 = Lrplacd(nil, v0339, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0339 = stack[-4];
    v0293 = stack[-2];
    v0293 = CC_stableKsortip(env, v0339, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    stack[-4] = v0293;
    v0339 = stack[-1];
    v0293 = stack[-2];
    v0293 = CC_stableKsortip(env, v0339, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    stack[-1] = v0293;
    v0293 = qvalue(elt(env, 1)); /* nil */
    v0293 = ncons(v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    stack[0] = v0293;
    stack[-3] = v0293;
    goto v0341;

v0341:
    v0293 = stack[-4];
    if (v0293 == nil) goto v0109;
    v0293 = stack[-1];
    if (v0293 == nil) goto v0109;
    v0189 = stack[-2];
    v0293 = stack[-1];
    v0339 = qcar(v0293);
    v0293 = stack[-4];
    v0293 = qcar(v0293);
    v0293 = Lapply2(nil, 3, v0189, v0339, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    if (v0293 == nil) goto v0296;
    v0339 = stack[0];
    v0293 = stack[-1];
    v0293 = Lrplacd(nil, v0339, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0293 = stack[-1];
    stack[0] = v0293;
    v0293 = stack[-1];
    v0293 = qcdr(v0293);
    stack[-1] = v0293;
    goto v0341;

v0296:
    v0339 = stack[0];
    v0293 = stack[-4];
    v0293 = Lrplacd(nil, v0339, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0293 = stack[-4];
    stack[0] = v0293;
    v0293 = stack[-4];
    v0293 = qcdr(v0293);
    stack[-4] = v0293;
    goto v0341;

v0109:
    v0293 = stack[-4];
    if (v0293 == nil) goto v0342;
    v0293 = stack[-4];
    stack[-1] = v0293;
    goto v0342;

v0342:
    v0339 = stack[0];
    v0293 = stack[-1];
    v0293 = Lrplacd(nil, v0339, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    v0293 = stack[-3];
    v0293 = qcdr(v0293);
    { popv(6); return onevalue(v0293); }

v0076:
    v0189 = stack[-2];
    v0293 = stack[-1];
    v0339 = qcar(v0293);
    v0293 = stack[-4];
    v0293 = qcar(v0293);
    v0293 = Lapply2(nil, 3, v0189, v0339, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    if (v0293 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0293 = stack[-4];
    v0293 = qcar(v0293);
    stack[-3] = v0293;
    v0339 = stack[-4];
    v0293 = stack[-1];
    v0293 = qcar(v0293);
    v0293 = Lrplaca(nil, v0339, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-5];
    v0339 = stack[-1];
    v0293 = stack[-3];
    v0293 = Lrplaca(nil, v0339, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v0340:
    popv(6);
    return nil;
}



/* Code for ratpoly_idl */

static Lisp_Object CC_ratpoly_idl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_idl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0235 = v0000;
/* end of prologue */
    v0235 = qcar(v0235);
    {
        fn = elt(env, 1); /* sf_idl */
        return (*qfn1(fn))(qenv(fn), v0235);
    }
}



/* Code for checktag */

static Lisp_Object CC_checktag(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checktag");
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
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0071 = v0000;
/* end of prologue */
    v0003 = qvalue(elt(env, 1)); /* char */
    if (equal(v0003, v0071)) goto v0235;
    v0003 = elt(env, 2); /* "Problem" */
    v0071 = elt(env, 3); /* "problem" */
    fn = elt(env, 4); /* errorml */
    v0071 = (*qfn2(fn))(qenv(fn), v0003, v0071);
    errexit();
    goto v0235;

v0235:
    v0071 = nil;
    return onevalue(v0071);
}



/* Code for simp!* */

static Lisp_Object CC_simpH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0327;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* !*asymp!* */
    qvalue(elt(env, 1)) = nil; /* !*asymp!* */
    v0327 = stack[-2];
    v0124 = elt(env, 2); /* !*sq */
    if (!consp(v0327)) goto v0076;
    v0327 = qcar(v0327);
    if (!(v0327 == v0124)) goto v0076;
    v0124 = stack[-2];
    v0124 = qcdr(v0124);
    v0124 = qcdr(v0124);
    v0124 = qcar(v0124);
    if (v0124 == nil) goto v0003;
    v0124 = qvalue(elt(env, 4)); /* !*resimp */
    v0124 = (v0124 == nil ? lisp_true : nil);
    goto v0050;

v0050:
    if (v0124 == nil) goto v0120;
    v0124 = stack[-2];
    v0124 = qcdr(v0124);
    v0124 = qcar(v0124);
    goto v0235;

v0235:
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    { popv(5); return onevalue(v0124); }

v0120:
    v0327 = qvalue(elt(env, 5)); /* mul!* */
    v0124 = qvalue(elt(env, 6)); /* !*sub2 */
    v0124 = cons(v0327, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-4];
    stack[-1] = v0124;
    v0124 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 5)) = v0124; /* mul!* */
    v0124 = stack[-2];
    fn = elt(env, 14); /* simp */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-4];
    stack[-2] = v0124;
    v0124 = qvalue(elt(env, 7)); /* !*nospurp */
    if (v0124 == nil) goto v0093;
    v0327 = qvalue(elt(env, 5)); /* mul!* */
    v0124 = elt(env, 8); /* (isimpq) */
    fn = elt(env, 15); /* union */
    v0124 = (*qfn2(fn))(qenv(fn), v0327, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-4];
    qvalue(elt(env, 5)) = v0124; /* mul!* */
    goto v0093;

v0093:
    v0124 = qvalue(elt(env, 5)); /* mul!* */
    stack[0] = v0124;
    goto v0232;

v0232:
    v0124 = stack[0];
    if (v0124 == nil) goto v0231;
    v0124 = stack[0];
    v0124 = qcar(v0124);
    v0327 = v0124;
    v0124 = stack[-2];
    v0124 = Lapply1(nil, v0327, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-4];
    stack[-2] = v0124;
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    stack[0] = v0124;
    goto v0232;

v0231:
    v0124 = stack[-1];
    v0124 = qcar(v0124);
    qvalue(elt(env, 5)) = v0124; /* mul!* */
    v0124 = stack[-2];
    fn = elt(env, 16); /* subs2 */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-4];
    stack[-2] = v0124;
    v0124 = qvalue(elt(env, 9)); /* !*combinelogs */
    if (v0124 == nil) goto v0326;
    v0124 = stack[-2];
    fn = elt(env, 17); /* clogsq!* */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-4];
    stack[-2] = v0124;
    goto v0326;

v0326:
    v0327 = qvalue(elt(env, 10)); /* dmode!* */
    v0124 = elt(env, 11); /* !:gi!: */
    if (v0327 == v0124) goto v0245;
    v0124 = qvalue(elt(env, 3)); /* nil */
    goto v0244;

v0244:
    if (v0124 == nil) goto v0075;
    v0124 = stack[-2];
    fn = elt(env, 18); /* girationalize!: */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-4];
    stack[-2] = v0124;
    goto v0014;

v0014:
    v0124 = stack[-1];
    v0124 = qcdr(v0124);
    qvalue(elt(env, 6)) = v0124; /* !*sub2 */
    v0124 = qvalue(elt(env, 1)); /* !*asymp!* */
    if (v0124 == nil) goto v0010;
    v0124 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v0124 == nil) goto v0010;
    v0124 = stack[-2];
    fn = elt(env, 19); /* gcdchk */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-4];
    stack[-2] = v0124;
    goto v0010;

v0010:
    v0124 = stack[-2];
    goto v0235;

v0075:
    v0124 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v0124 == nil) goto v0038;
    v0124 = stack[-2];
    fn = elt(env, 20); /* rationalizesq */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-4];
    stack[-2] = v0124;
    goto v0014;

v0038:
    v0124 = stack[-2];
    fn = elt(env, 21); /* rationalizei */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-4];
    stack[-2] = v0124;
    goto v0014;

v0245:
    v0124 = qvalue(elt(env, 12)); /* !*norationalgi */
    v0124 = (v0124 == nil ? lisp_true : nil);
    goto v0244;

v0003:
    v0124 = qvalue(elt(env, 3)); /* nil */
    goto v0050;

v0076:
    v0124 = qvalue(elt(env, 3)); /* nil */
    goto v0050;
/* error exit handlers */
v0297:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    popv(5);
    return nil;
}



setup_type const u06_setup[] =
{
    {"deg*form",                CC_degHform,    too_many_1,    wrong_no_1},
    {"lessp:",                  too_few_2,      CC_lesspT,     wrong_no_2},
    {"eofcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eofcheck},
    {"*ssave",                  too_few_2,      CC_Hssave,     wrong_no_2},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"gperm",                   CC_gperm,       too_many_1,    wrong_no_1},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"gizerop:",                CC_gizeropT,    too_many_1,    wrong_no_1},
    {"sfto_gcdf*",              too_few_2,      CC_sfto_gcdfH, wrong_no_2},
    {"gcdf1",                   too_few_2,      CC_gcdf1,      wrong_no_2},
    {"subs3q",                  CC_subs3q,      too_many_1,    wrong_no_1},
    {"subs2f1",                 CC_subs2f1,     too_many_1,    wrong_no_1},
    {"xxsort",                  CC_xxsort,      too_many_1,    wrong_no_1},
    {"lambda_mka0p2_1",         too_few_2,      CC_lambda_mka0p2_1,wrong_no_2},
    {"ibalp_commonlenisone",    too_few_2,      CC_ibalp_commonlenisone,wrong_no_2},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"retattributes",           too_few_2,      CC_retattributes,wrong_no_2},
    {"isarb_compl",             CC_isarb_compl, too_many_1,    wrong_no_1},
    {"gsetsugar",               too_few_2,      CC_gsetsugar,  wrong_no_2},
    {"make-set",                CC_makeKset,    too_many_1,    wrong_no_1},
    {"setcloc*",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_setclocH},
    {"dp_ecart",                CC_dp_ecart,    too_many_1,    wrong_no_1},
    {"pcmult",                  too_few_2,      CC_pcmult,     wrong_no_2},
    {"round:last",              CC_roundTlast,  too_many_1,    wrong_no_1},
    {"**s2a",                   too_few_2,      CC_HHs2a,      wrong_no_2},
    {"qqe_qtidp",               CC_qqe_qtidp,   too_many_1,    wrong_no_1},
    {"isarb_int",               CC_isarb_int,   too_many_1,    wrong_no_1},
    {"ps:evaluate",             too_few_2,      CC_psTevaluate,wrong_no_2},
    {"vevtdeg",                 CC_vevtdeg,     too_many_1,    wrong_no_1},
    {"convchk",                 CC_convchk,     too_many_1,    wrong_no_1},
    {"domain*p",                CC_domainHp,    too_many_1,    wrong_no_1},
    {"add2inputbuf",            too_few_2,      CC_add2inputbuf,wrong_no_2},
    {"exptmod:",                too_few_2,      CC_exptmodT,   wrong_no_2},
    {"ofsf_vareqnp",            too_few_2,      CC_ofsf_vareqnp,wrong_no_2},
    {"frvarsof",                too_few_2,      CC_frvarsof,   wrong_no_2},
    {"mri_0mk2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mri_0mk2},
    {"ibalp_calcmom",           CC_ibalp_calcmom,too_many_1,   wrong_no_1},
    {"omobjs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobjs},
    {"groebsearchinlist",       too_few_2,      CC_groebsearchinlist,wrong_no_2},
    {":difference",             too_few_2,      CC_Tdifference,wrong_no_2},
    {"optype",                  CC_optype,      too_many_1,    wrong_no_1},
    {"getphystype",             CC_getphystype, too_many_1,    wrong_no_1},
    {"contrsp2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_contrsp2},
    {"formc",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_formc},
    {"ckpreci#",                CC_ckpreciC,    too_many_1,    wrong_no_1},
    {"mv-pow-minusp",           CC_mvKpowKminusp,too_many_1,   wrong_no_1},
    {"divd",                    too_few_2,      CC_divd,       wrong_no_2},
    {"dp=ecart",                CC_dpMecart,    too_many_1,    wrong_no_1},
    {"pappl_pv",                too_few_2,      CC_pappl_pv,   wrong_no_2},
    {"general-modular-minus",   CC_generalKmodularKminus,too_many_1,wrong_no_1},
    {"lto_insert",              too_few_2,      CC_lto_insert, wrong_no_2},
    {"cl_simplat",              too_few_2,      CC_cl_simplat, wrong_no_2},
    {"ibalp_varlat",            CC_ibalp_varlat,too_many_1,    wrong_no_1},
    {"reval1",                  too_few_2,      CC_reval1,     wrong_no_2},
    {"evaluate0",               too_few_2,      CC_evaluate0,  wrong_no_2},
    {"simpplus",                CC_simpplus,    too_many_1,    wrong_no_1},
    {"rnplus:",                 too_few_2,      CC_rnplusT,    wrong_no_2},
    {"dp_sum",                  too_few_2,      CC_dp_sum,     wrong_no_2},
    {"dv_skelhead",             CC_dv_skelhead, too_many_1,    wrong_no_1},
    {"*i2ar",                   CC_Hi2ar,       too_many_1,    wrong_no_1},
    {"anforml",                 CC_anforml,     too_many_1,    wrong_no_1},
    {"wulessp",                 too_few_2,      CC_wulessp,    wrong_no_2},
    {"stable-sortip",           too_few_2,      CC_stableKsortip,wrong_no_2},
    {"ratpoly_idl",             CC_ratpoly_idl, too_many_1,    wrong_no_1},
    {"checktag",                CC_checktag,    too_many_1,    wrong_no_1},
    {"simp*",                   CC_simpH,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u06", (two_args *)"21272 7431417 4216192", 0}
};

/* end of generated code */
