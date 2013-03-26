
/* $destdir\u48.c        Machine generated C code */

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


/* Code for liendimcom */

static Lisp_Object CC_liendimcom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0270, v0271, v0272, v0273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for liendimcom");
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
    v0270 = (Lisp_Object)1; /* 0 */
    stack[-9] = v0270;
    stack[0] = elt(env, 1); /* lie_dim */
    v0270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* aeval */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0270;
    goto v0275;

v0275:
    stack[0] = elt(env, 2); /* difference */
    v0272 = elt(env, 2); /* difference */
    v0271 = stack[-8];
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-3];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0276;
    v0270 = elt(env, 1); /* lie_dim */
    fn = elt(env, 15); /* aeval */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v0270 = (*qfn2(fn))(qenv(fn), v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0277;
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-5] = v0270;
    goto v0278;

v0278:
    stack[0] = elt(env, 2); /* difference */
    v0272 = elt(env, 2); /* difference */
    v0271 = stack[-8];
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-5];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0279;
    v0270 = elt(env, 1); /* lie_dim */
    fn = elt(env, 15); /* aeval */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 20); /* evalequal */
    v0270 = (*qfn2(fn))(qenv(fn), v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0277;
    stack[0] = elt(env, 10); /* lie_help */
    v0270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* aeval */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-6] = v0270;
    goto v0280;

v0280:
    stack[0] = elt(env, 2); /* difference */
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-6];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0281;
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0270;
    goto v0282;

v0282:
    stack[0] = elt(env, 2); /* difference */
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-1];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0283;
    v0270 = elt(env, 10); /* lie_help */
    fn = elt(env, 15); /* aeval */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* evalequal */
    v0270 = (*qfn2(fn))(qenv(fn), v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0284;
    v0272 = elt(env, 12); /* lientrans */
    v0271 = (Lisp_Object)33; /* 2 */
    v0270 = elt(env, 5); /* lie_p */
    stack[-1] = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0272 = elt(env, 12); /* lientrans */
    v0271 = (Lisp_Object)49; /* 3 */
    v0270 = elt(env, 6); /* lie_q */
    stack[0] = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* aeval */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[-1], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[0] = elt(env, 13); /* lie_kk!* */
    v0270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* aeval */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0270;
    goto v0285;

v0285:
    stack[0] = elt(env, 2); /* difference */
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-1];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (!(v0270 == nil)) goto v0277;
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = elt(env, 5); /* lie_p */
    v0271 = elt(env, 6); /* lie_q */
    v0270 = stack[-1];
    v0270 = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v0270 = (*qfn2(fn))(qenv(fn), v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0286;
    stack[0] = stack[-1];
    v0270 = elt(env, 5); /* lie_p */
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0286;
    stack[0] = stack[-1];
    v0270 = elt(env, 6); /* lie_q */
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0286;
    stack[0] = elt(env, 14); /* lie_tt */
    v0270 = stack[-1];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0272 = elt(env, 7); /* plus */
    v0271 = stack[-8];
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-1] = v0270;
    goto v0286;

v0286:
    v0270 = stack[-1];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-1] = v0270;
    goto v0285;

v0277:
    v0270 = nil;
    { popv(11); return onevalue(v0270); }

v0284:
    v0272 = elt(env, 12); /* lientrans */
    v0271 = (Lisp_Object)33; /* 2 */
    v0270 = elt(env, 11); /* lie_s */
    stack[-7] = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-6] = elt(env, 8); /* quotient */
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = elt(env, 5); /* lie_p */
    v0271 = elt(env, 6); /* lie_q */
    v0270 = stack[-9];
    stack[-5] = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0270;
    v0270 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0270;
    goto v0287;

v0287:
    stack[0] = elt(env, 2); /* difference */
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-4];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0288;
    v0270 = stack[-3];
    v0270 = list3(stack[-6], stack[-5], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 15); /* aeval */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[-7], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0270;
    goto v0289;

v0289:
    stack[0] = elt(env, 2); /* difference */
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-1];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (!(v0270 == nil)) goto v0277;
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = elt(env, 5); /* lie_p */
    v0271 = elt(env, 6); /* lie_q */
    v0270 = stack[-1];
    v0270 = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v0270 = (*qfn2(fn))(qenv(fn), v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0290;
    stack[0] = stack[-1];
    v0270 = elt(env, 11); /* lie_s */
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0290;
    stack[0] = elt(env, 14); /* lie_tt */
    v0270 = stack[-1];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0272 = elt(env, 7); /* plus */
    v0271 = stack[-8];
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-1] = v0270;
    goto v0290;

v0290:
    v0270 = stack[-1];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-1] = v0270;
    goto v0289;

v0288:
    stack[-2] = elt(env, 7); /* plus */
    stack[-1] = elt(env, 9); /* times */
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = elt(env, 5); /* lie_p */
    v0271 = elt(env, 6); /* lie_q */
    v0270 = stack[-4];
    stack[0] = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = stack[-4];
    v0271 = elt(env, 11); /* lie_s */
    v0270 = stack[-9];
    v0270 = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = list3(stack[-1], stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-3];
    v0270 = list3(stack[-2], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-3] = v0270;
    v0270 = stack[-4];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-4] = v0270;
    goto v0287;

v0283:
    v0272 = elt(env, 12); /* lientrans */
    v0271 = (Lisp_Object)17; /* 1 */
    v0270 = stack[-1];
    stack[0] = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = elt(env, 5); /* lie_p */
    v0271 = elt(env, 6); /* lie_q */
    v0270 = stack[-1];
    v0270 = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-1];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-1] = v0270;
    goto v0282;

v0281:
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-5] = v0270;
    goto v0291;

v0291:
    stack[0] = elt(env, 2); /* difference */
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-5];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0292;
    v0270 = stack[-6];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-6] = v0270;
    goto v0280;

v0292:
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0270;
    v0270 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0270;
    goto v0293;

v0293:
    stack[0] = elt(env, 2); /* difference */
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-4];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0294;
    v0270 = stack[-3];
    v0271 = v0270;
    v0270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v0270 = (*qfn2(fn))(qenv(fn), v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0295;
    stack[0] = elt(env, 10); /* lie_help */
    v0270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[0] = elt(env, 11); /* lie_s */
    v0270 = stack[-6];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-5];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-9] = v0270;
    v0272 = elt(env, 7); /* plus */
    v0271 = stack[-8];
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-5] = v0270;
    stack[-6] = v0270;
    goto v0295;

v0295:
    v0270 = stack[-5];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-5] = v0270;
    goto v0291;

v0294:
    stack[-2] = elt(env, 7); /* plus */
    stack[-1] = elt(env, 9); /* times */
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = elt(env, 5); /* lie_p */
    v0271 = elt(env, 6); /* lie_q */
    v0270 = stack[-4];
    stack[0] = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = stack[-4];
    v0271 = stack[-6];
    v0270 = stack[-5];
    v0270 = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = list3(stack[-1], stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-3];
    v0270 = list3(stack[-2], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-3] = v0270;
    v0270 = stack[-4];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-4] = v0270;
    goto v0293;

v0279:
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0270;
    goto v0296;

v0296:
    stack[0] = elt(env, 2); /* difference */
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-4];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0297;
    v0270 = stack[-5];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-5] = v0270;
    goto v0278;

v0297:
    stack[-1] = elt(env, 8); /* quotient */
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = stack[-5];
    v0271 = stack[-4];
    v0270 = stack[-9];
    stack[0] = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = elt(env, 5); /* lie_p */
    v0271 = elt(env, 6); /* lie_q */
    v0270 = stack[-9];
    v0270 = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = list3(stack[-1], stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-6] = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0270;
    goto v0298;

v0298:
    stack[0] = elt(env, 2); /* difference */
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-3];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0299;
    v0270 = stack[-4];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-4] = v0270;
    goto v0296;

v0299:
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = stack[-5];
    v0271 = stack[-4];
    v0270 = stack[-3];
    v0270 = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-1] = elt(env, 9); /* times */
    stack[0] = stack[-6];
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = elt(env, 5); /* lie_p */
    v0271 = elt(env, 6); /* lie_q */
    v0270 = stack[-3];
    v0270 = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = list3(stack[-1], stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v0270 = (*qfn2(fn))(qenv(fn), stack[-2], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0300;
    stack[0] = elt(env, 1); /* lie_dim */
    v0270 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-5] = v0270;
    v0272 = elt(env, 7); /* plus */
    v0271 = stack[-8];
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-4] = v0270;
    v0272 = elt(env, 7); /* plus */
    v0271 = stack[-8];
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-3] = v0270;
    goto v0300;

v0300:
    v0270 = stack[-3];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-3] = v0270;
    goto v0298;

v0276:
    v0270 = stack[-3];
    stack[-2] = v0270;
    goto v0301;

v0301:
    stack[0] = elt(env, 2); /* difference */
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-2];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0302;
    v0270 = stack[-3];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-3] = v0270;
    goto v0275;

v0302:
    v0270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0270;
    goto v0303;

v0303:
    stack[0] = elt(env, 2); /* difference */
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-1];
    v0270 = list3(stack[0], v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0304;
    v0270 = stack[-2];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-2] = v0270;
    goto v0301;

v0304:
    v0273 = elt(env, 4); /* lie_cc */
    v0272 = stack[-3];
    v0271 = stack[-2];
    v0270 = stack[-1];
    v0270 = list4(v0273, v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0271 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v0270 = (*qfn2(fn))(qenv(fn), v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    if (v0270 == nil) goto v0305;
    stack[0] = elt(env, 1); /* lie_dim */
    v0270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[0] = elt(env, 5); /* lie_p */
    v0270 = stack[-3];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[0] = elt(env, 6); /* lie_q */
    v0270 = stack[-2];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v0270 = (*qfn2(fn))(qenv(fn), stack[0], v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    v0270 = stack[-1];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-9] = v0270;
    v0270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-3] = v0270;
    v0272 = elt(env, 7); /* plus */
    v0271 = stack[-8];
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-1] = v0270;
    stack[-2] = v0270;
    goto v0305;

v0305:
    v0270 = stack[-1];
    v0272 = elt(env, 7); /* plus */
    v0271 = v0270;
    v0270 = (Lisp_Object)17; /* 1 */
    v0270 = list3(v0272, v0271, v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v0270 = (*qfn1(fn))(qenv(fn), v0270);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-10];
    stack[-1] = v0270;
    goto v0303;
/* error exit handlers */
v0274:
    popv(11);
    return nil;
}



/* Code for basic!-kern1 */

static Lisp_Object CC_basicKkern1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0259, v0310;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basic-kern1");
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
/* copy arguments values to proper place */
    stack[-3] = v0000;
/* end of prologue */
    v0259 = stack[-3];
    if (!consp(v0259)) goto v0311;
    v0259 = stack[-3];
    v0259 = qcar(v0259);
    fn = elt(env, 2); /* algebraic!-function */
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    if (v0259 == nil) goto v0313;
    v0259 = stack[-3];
    v0259 = qcdr(v0259);
    stack[-4] = v0259;
    v0259 = stack[-4];
    if (v0259 == nil) goto v0314;
    v0259 = stack[-4];
    v0259 = qcar(v0259);
    fn = elt(env, 3); /* simp */
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    v0259 = ncons(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    stack[-1] = v0259;
    stack[-2] = v0259;
    goto v0315;

v0315:
    v0259 = stack[-4];
    v0259 = qcdr(v0259);
    stack[-4] = v0259;
    v0259 = stack[-4];
    if (v0259 == nil) goto v0267;
    stack[0] = stack[-1];
    v0259 = stack[-4];
    v0259 = qcar(v0259);
    fn = elt(env, 3); /* simp */
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    v0259 = ncons(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    v0259 = Lrplacd(nil, stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    env = stack[-5];
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    stack[-1] = v0259;
    goto v0315;

v0267:
    v0259 = stack[-2];
    goto v0316;

v0316:
    fn = elt(env, 4); /* allbkern */
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0312;
    v0310 = v0259;
    if (!(v0259 == nil)) { popv(6); return onevalue(v0310); }

v0313:
    v0259 = stack[-3];
    popv(6);
    return ncons(v0259);

v0314:
    v0259 = qvalue(elt(env, 1)); /* nil */
    goto v0316;

v0311:
    v0259 = stack[-3];
    popv(6);
    return ncons(v0259);
/* error exit handlers */
v0312:
    popv(6);
    return nil;
}



/* Code for setqdeletedescendants */

static Lisp_Object CC_setqdeletedescendants(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0323, v0324;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setqdeletedescendants");
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
    v0323 = qvalue(elt(env, 1)); /* fluidbibasissetq */
    stack[-1] = v0323;
    goto v0325;

v0325:
    v0323 = stack[-1];
    v0323 = qcar(v0323);
    if (v0323 == nil) goto v0311;
    v0323 = stack[-1];
    v0324 = qcar(v0323);
    v0323 = (Lisp_Object)33; /* 2 */
    v0324 = *(Lisp_Object *)((char *)v0324 + (CELL-TAG_VECTOR) + ((int32_t)v0323/(16/CELL)));
    v0323 = stack[0];
    if (equal(v0324, v0323)) goto v0326;
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    stack[-1] = v0323;
    goto v0325;

v0326:
    v0324 = stack[-1];
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0323 = qcar(v0323);
    v0324 = Lrplaca(nil, v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0327;
    env = stack[-2];
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    v0323 = qcdr(v0323);
    v0323 = Lrplacd(nil, v0324, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0327;
    env = stack[-2];
    goto v0325;

v0311:
    v0323 = nil;
    { popv(3); return onevalue(v0323); }
/* error exit handlers */
v0327:
    popv(3);
    return nil;
}



/* Code for preptaylor!*2 */

static Lisp_Object CC_preptaylorH2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0328)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0338, v0305, v0339;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaylor*2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0328);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0328;
    stack[-1] = v0000;
/* end of prologue */
    v0338 = stack[-1];
    v0338 = qcdr(v0338);
    fn = elt(env, 4); /* prepsq!* */
    v0338 = (*qfn1(fn))(qenv(fn), v0338);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-3];
    v0339 = v0338;
    v0305 = (Lisp_Object)1; /* 0 */
    if (v0339 == v0305) goto v0341;
    v0339 = v0338;
    v0305 = elt(env, 2); /* quotient */
    if (!consp(v0339)) goto v0302;
    v0339 = qcar(v0339);
    if (!(v0339 == v0305)) goto v0302;
    v0305 = v0338;
    v0305 = qcdr(v0305);
    v0339 = qcar(v0305);
    v0305 = elt(env, 3); /* minus */
    v0305 = Leqcar(nil, v0339, v0305);
    env = stack[-3];
    goto v0264;

v0264:
    if (v0305 == nil) goto v0303;
    stack[-2] = elt(env, 3); /* minus */
    v0339 = elt(env, 2); /* quotient */
    v0305 = v0338;
    v0305 = qcdr(v0305);
    v0305 = qcar(v0305);
    v0305 = qcdr(v0305);
    v0305 = qcar(v0305);
    v0338 = qcdr(v0338);
    v0338 = qcdr(v0338);
    v0338 = qcar(v0338);
    v0338 = list3(v0339, v0305, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-3];
    v0338 = list2(stack[-2], v0338);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-3];
    stack[-2] = v0338;
    goto v0342;

v0342:
    v0338 = stack[-1];
    v0305 = qcar(v0338);
    v0338 = stack[0];
    fn = elt(env, 5); /* preptaycoeff */
    v0338 = (*qfn2(fn))(qenv(fn), v0305, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-3];
    v0338 = cons(stack[-2], v0338);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    env = stack[-3];
    fn = elt(env, 6); /* retimes */
    v0338 = (*qfn1(fn))(qenv(fn), v0338);
    nil = C_nil;
    if (exception_pending()) goto v0340;
    popv(4);
    return ncons(v0338);

v0303:
    stack[-2] = v0338;
    goto v0342;

v0302:
    v0305 = qvalue(elt(env, 1)); /* nil */
    goto v0264;

v0341:
    v0338 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0338); }
/* error exit handlers */
v0340:
    popv(4);
    return nil;
}



/* Code for evalleq */

static Lisp_Object CC_evalleq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0328)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0344, v0268;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalleq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0328);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0344 = v0328;
    v0268 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* evalgreaterp */
    v0344 = (*qfn2(fn))(qenv(fn), v0268, v0344);
    errexit();
    v0344 = (v0344 == nil ? lisp_true : nil);
    return onevalue(v0344);
}



/* Code for vp1 */

static Lisp_Object MS_CDECL CC_vp1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0328,
                         Lisp_Object v0043, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0323, v0324, v0351;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0043,v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0328,v0043);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0043;
    stack[-1] = v0328;
    stack[-2] = v0000;
/* end of prologue */
    v0351 = nil;
    goto v0311;

v0311:
    v0323 = stack[0];
    if (v0323 == nil) goto v0269;
    v0324 = stack[-2];
    v0323 = stack[0];
    v0323 = qcar(v0323);
    if (equal(v0324, v0323)) goto v0320;
    v0323 = (Lisp_Object)1; /* 0 */
    v0324 = v0351;
    v0323 = cons(v0323, v0324);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0351 = v0323;
    v0323 = stack[0];
    v0323 = qcdr(v0323);
    stack[0] = v0323;
    goto v0311;

v0320:
    stack[-2] = v0351;
    v0323 = stack[0];
    v0323 = qcdr(v0323);
    fn = elt(env, 2); /* vp2 */
    v0323 = (*qfn1(fn))(qenv(fn), v0323);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0323 = cons(stack[-1], v0323);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    {
        Lisp_Object v0259 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0259, v0323);
    }

v0269:
    stack[0] = v0351;
    v0323 = elt(env, 1); /* "Var not in z-list after all" */
    fn = elt(env, 4); /* interr */
    v0323 = (*qfn1(fn))(qenv(fn), v0323);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    {
        Lisp_Object v0310 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0310, v0323);
    }
/* error exit handlers */
v0261:
    popv(4);
    return nil;
}



/* Code for makecoeffpairs1 */

static Lisp_Object MS_CDECL CC_makecoeffpairs1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0328,
                         Lisp_Object v0043, Lisp_Object v0196, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0380, v0297, v0381, v0382;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairs1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makecoeffpairs1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0196,v0043,v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0328,v0043,v0196);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v0196;
    stack[-11] = v0043;
    stack[-12] = v0328;
    stack[-13] = v0000;
/* end of prologue */
    v0380 = stack[-12];
    if (v0380 == nil) goto v0311;
    v0380 = stack[-13];
    v0382 = qcdr(v0380);
    v0380 = stack[-12];
    v0381 = qcdr(v0380);
    v0380 = stack[-11];
    v0297 = qcdr(v0380);
    v0380 = stack[-10];
    v0380 = qcdr(v0380);
    v0380 = CC_makecoeffpairs1(env, 4, v0382, v0381, v0297, v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    stack[-14] = v0380;
    goto v0383;

v0383:
    v0380 = stack[-14];
    if (v0380 == nil) goto v0384;
    v0380 = stack[-14];
    v0380 = qcar(v0380);
    stack[-6] = v0380;
    v0380 = stack[-13];
    stack[-2] = qcar(v0380);
    v0380 = stack[-12];
    stack[-1] = qcar(v0380);
    v0380 = stack[-11];
    stack[0] = qcar(v0380);
    v0380 = stack[-10];
    v0380 = qcar(v0380);
    fn = elt(env, 3); /* tayexp!-minus */
    v0380 = (*qfn1(fn))(qenv(fn), v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    fn = elt(env, 4); /* makecoeffpairshom */
    v0380 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    stack[-5] = v0380;
    v0380 = stack[-5];
    if (v0380 == nil) goto v0385;
    v0380 = stack[-5];
    v0380 = qcar(v0380);
    v0297 = v0380;
    v0380 = v0297;
    stack[-1] = qcar(v0380);
    v0380 = stack[-6];
    stack[0] = qcar(v0380);
    v0380 = v0297;
    v0297 = qcdr(v0380);
    v0380 = stack[-6];
    v0380 = qcdr(v0380);
    v0380 = cons(v0297, v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = acons(stack[-1], stack[0], v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = ncons(v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    stack[-3] = v0380;
    stack[-4] = v0380;
    goto v0386;

v0386:
    v0380 = stack[-5];
    v0380 = qcdr(v0380);
    stack[-5] = v0380;
    v0380 = stack[-5];
    if (v0380 == nil) goto v0387;
    stack[-2] = stack[-3];
    v0380 = stack[-5];
    v0380 = qcar(v0380);
    v0297 = v0380;
    v0380 = v0297;
    stack[-1] = qcar(v0380);
    v0380 = stack[-6];
    stack[0] = qcar(v0380);
    v0380 = v0297;
    v0297 = qcdr(v0380);
    v0380 = stack[-6];
    v0380 = qcdr(v0380);
    v0380 = cons(v0297, v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = acons(stack[-1], stack[0], v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = ncons(v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = Lrplacd(nil, stack[-2], v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = stack[-3];
    v0380 = qcdr(v0380);
    stack[-3] = v0380;
    goto v0386;

v0387:
    v0380 = stack[-4];
    goto v0388;

v0388:
    stack[-9] = v0380;
    v0380 = stack[-9];
    fn = elt(env, 5); /* lastpair */
    v0380 = (*qfn1(fn))(qenv(fn), v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    stack[-8] = v0380;
    v0380 = stack[-14];
    v0380 = qcdr(v0380);
    stack[-14] = v0380;
    v0380 = stack[-8];
    if (!consp(v0380)) goto v0383;
    else goto v0350;

v0350:
    v0380 = stack[-14];
    if (v0380 == nil) { Lisp_Object res = stack[-9]; popv(16); return onevalue(res); }
    stack[-7] = stack[-8];
    v0380 = stack[-14];
    v0380 = qcar(v0380);
    stack[-6] = v0380;
    v0380 = stack[-13];
    stack[-2] = qcar(v0380);
    v0380 = stack[-12];
    stack[-1] = qcar(v0380);
    v0380 = stack[-11];
    stack[0] = qcar(v0380);
    v0380 = stack[-10];
    v0380 = qcar(v0380);
    fn = elt(env, 3); /* tayexp!-minus */
    v0380 = (*qfn1(fn))(qenv(fn), v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    fn = elt(env, 4); /* makecoeffpairshom */
    v0380 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    stack[-5] = v0380;
    v0380 = stack[-5];
    if (v0380 == nil) goto v0389;
    v0380 = stack[-5];
    v0380 = qcar(v0380);
    v0297 = v0380;
    v0380 = v0297;
    stack[-1] = qcar(v0380);
    v0380 = stack[-6];
    stack[0] = qcar(v0380);
    v0380 = v0297;
    v0297 = qcdr(v0380);
    v0380 = stack[-6];
    v0380 = qcdr(v0380);
    v0380 = cons(v0297, v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = acons(stack[-1], stack[0], v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = ncons(v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    stack[-3] = v0380;
    stack[-4] = v0380;
    goto v0237;

v0237:
    v0380 = stack[-5];
    v0380 = qcdr(v0380);
    stack[-5] = v0380;
    v0380 = stack[-5];
    if (v0380 == nil) goto v0390;
    stack[-2] = stack[-3];
    v0380 = stack[-5];
    v0380 = qcar(v0380);
    v0297 = v0380;
    v0380 = v0297;
    stack[-1] = qcar(v0380);
    v0380 = stack[-6];
    stack[0] = qcar(v0380);
    v0380 = v0297;
    v0297 = qcdr(v0380);
    v0380 = stack[-6];
    v0380 = qcdr(v0380);
    v0380 = cons(v0297, v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = acons(stack[-1], stack[0], v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = ncons(v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = Lrplacd(nil, stack[-2], v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = stack[-3];
    v0380 = qcdr(v0380);
    stack[-3] = v0380;
    goto v0237;

v0390:
    v0380 = stack[-4];
    goto v0391;

v0391:
    v0380 = Lrplacd(nil, stack[-7], v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    v0380 = stack[-8];
    fn = elt(env, 5); /* lastpair */
    v0380 = (*qfn1(fn))(qenv(fn), v0380);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-15];
    stack[-8] = v0380;
    v0380 = stack[-14];
    v0380 = qcdr(v0380);
    stack[-14] = v0380;
    goto v0350;

v0389:
    v0380 = qvalue(elt(env, 2)); /* nil */
    goto v0391;

v0385:
    v0380 = qvalue(elt(env, 2)); /* nil */
    goto v0388;

v0384:
    v0380 = qvalue(elt(env, 2)); /* nil */
    { popv(16); return onevalue(v0380); }

v0311:
    v0380 = elt(env, 1); /* ((nil)) */
    { popv(16); return onevalue(v0380); }
/* error exit handlers */
v0213:
    popv(16);
    return nil;
}



/* Code for ofsf_sacatlp */

static Lisp_Object CC_ofsf_sacatlp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0328)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0379, v0348, v0349, v0384;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacatlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0328);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0379 = v0328;
    v0384 = v0000;
/* end of prologue */
    v0379 = qcar(v0379);
    v0349 = v0379;
    v0379 = v0384;
    v0379 = qcdr(v0379);
    v0348 = qcar(v0379);
    v0379 = v0349;
    v0379 = qcdr(v0379);
    v0379 = qcar(v0379);
    if (equal(v0348, v0379)) goto v0320;
    v0379 = v0384;
    v0379 = qcdr(v0379);
    v0379 = qcar(v0379);
    v0348 = v0349;
    v0348 = qcdr(v0348);
    v0348 = qcar(v0348);
    fn = elt(env, 2); /* ordp */
    v0379 = (*qfn2(fn))(qenv(fn), v0379, v0348);
    errexit();
    goto v0311;

v0311:
    v0379 = (v0379 == nil ? lisp_true : nil);
    return onevalue(v0379);

v0320:
    v0379 = qvalue(elt(env, 1)); /* nil */
    goto v0311;
}



/* Code for crnprep1 */

static Lisp_Object CC_crnprep1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0346;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crnprep1");
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
    v0346 = stack[-1];
    v0346 = qcdr(v0346);
    fn = elt(env, 3); /* rnzerop!: */
    v0346 = (*qfn1(fn))(qenv(fn), v0346);
    nil = C_nil;
    if (exception_pending()) goto v0324;
    env = stack[-3];
    if (v0346 == nil) goto v0392;
    v0346 = stack[-1];
    v0346 = qcar(v0346);
    {
        popv(4);
        fn = elt(env, 4); /* rnprep!: */
        return (*qfn1(fn))(qenv(fn), v0346);
    }

v0392:
    v0346 = stack[-1];
    v0346 = qcar(v0346);
    fn = elt(env, 3); /* rnzerop!: */
    v0346 = (*qfn1(fn))(qenv(fn), v0346);
    nil = C_nil;
    if (exception_pending()) goto v0324;
    env = stack[-3];
    if (v0346 == nil) goto v0268;
    v0346 = stack[-1];
    v0346 = qcdr(v0346);
    {
        popv(4);
        fn = elt(env, 5); /* crnprimp */
        return (*qfn1(fn))(qenv(fn), v0346);
    }

v0268:
    v0346 = stack[-1];
    v0346 = qcdr(v0346);
    fn = elt(env, 6); /* rnminusp!: */
    v0346 = (*qfn1(fn))(qenv(fn), v0346);
    nil = C_nil;
    if (exception_pending()) goto v0324;
    env = stack[-3];
    if (v0346 == nil) goto v0267;
    stack[-2] = elt(env, 1); /* difference */
    v0346 = stack[-1];
    v0346 = qcar(v0346);
    fn = elt(env, 4); /* rnprep!: */
    stack[0] = (*qfn1(fn))(qenv(fn), v0346);
    nil = C_nil;
    if (exception_pending()) goto v0324;
    env = stack[-3];
    v0346 = stack[-1];
    v0346 = qcdr(v0346);
    fn = elt(env, 7); /* rnminus!: */
    v0346 = (*qfn1(fn))(qenv(fn), v0346);
    nil = C_nil;
    if (exception_pending()) goto v0324;
    env = stack[-3];
    fn = elt(env, 5); /* crnprimp */
    v0346 = (*qfn1(fn))(qenv(fn), v0346);
    nil = C_nil;
    if (exception_pending()) goto v0324;
    {
        Lisp_Object v0351 = stack[-2];
        Lisp_Object v0313 = stack[0];
        popv(4);
        return list3(v0351, v0313, v0346);
    }

v0267:
    stack[-2] = elt(env, 2); /* plus */
    v0346 = stack[-1];
    v0346 = qcar(v0346);
    fn = elt(env, 4); /* rnprep!: */
    stack[0] = (*qfn1(fn))(qenv(fn), v0346);
    nil = C_nil;
    if (exception_pending()) goto v0324;
    env = stack[-3];
    v0346 = stack[-1];
    v0346 = qcdr(v0346);
    fn = elt(env, 5); /* crnprimp */
    v0346 = (*qfn1(fn))(qenv(fn), v0346);
    nil = C_nil;
    if (exception_pending()) goto v0324;
    {
        Lisp_Object v0327 = stack[-2];
        Lisp_Object v0378 = stack[0];
        popv(4);
        return list3(v0327, v0378, v0346);
    }
/* error exit handlers */
v0324:
    popv(4);
    return nil;
}



/* Code for ldf!-pow!-var */

static Lisp_Object CC_ldfKpowKvar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0342, v0394, v0395;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-pow-var");
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
    v0342 = v0000;
/* end of prologue */
    v0394 = nil;
    stack[-2] = nil;
    stack[-1] = v0342;
    goto v0341;

v0341:
    v0342 = stack[-1];
    if (v0342 == nil) goto v0325;
    v0342 = stack[-1];
    v0342 = qcar(v0342);
    stack[0] = v0394;
    v0342 = qcdr(v0342);
    fn = elt(env, 5); /* kernels */
    v0342 = (*qfn1(fn))(qenv(fn), v0342);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-3];
    v0342 = Lappend(nil, stack[0], v0342);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-3];
    v0394 = v0342;
    v0342 = stack[-1];
    v0342 = qcdr(v0342);
    stack[-1] = v0342;
    goto v0341;

v0325:
    v0342 = v0394;
    fn = elt(env, 6); /* makeset */
    v0342 = (*qfn1(fn))(qenv(fn), v0342);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-3];
    fn = elt(env, 7); /* prlist */
    v0342 = (*qfn1(fn))(qenv(fn), v0342);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-3];
    stack[0] = v0342;
    goto v0262;

v0262:
    v0342 = stack[0];
    if (v0342 == nil) goto v0264;
    v0342 = stack[0];
    v0342 = qcar(v0342);
    v0395 = v0342;
    v0394 = v0395;
    v0342 = elt(env, 2); /* x */
    if (!consp(v0394)) goto v0259;
    v0394 = qcar(v0394);
    if (!(v0394 == v0342)) goto v0259;
    v0342 = qvalue(elt(env, 3)); /* t */
    goto v0318;

v0318:
    if (v0342 == nil) goto v0235;
    v0394 = v0395;
    v0342 = stack[-2];
    v0342 = cons(v0394, v0342);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-3];
    stack[-2] = v0342;
    goto v0235;

v0235:
    v0342 = stack[0];
    v0342 = qcdr(v0342);
    stack[0] = v0342;
    goto v0262;

v0259:
    v0394 = v0395;
    v0342 = elt(env, 4); /* u */
    v0342 = Leqcar(nil, v0394, v0342);
    env = stack[-3];
    goto v0318;

v0264:
    v0342 = stack[-2];
    {
        popv(4);
        fn = elt(env, 6); /* makeset */
        return (*qfn1(fn))(qenv(fn), v0342);
    }
/* error exit handlers */
v0257:
    popv(4);
    return nil;
}



/* Code for dipdivmon */

static Lisp_Object MS_CDECL CC_dipdivmon(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0328,
                         Lisp_Object v0043, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0318, v0307;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipdivmon");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipdivmon");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0043,v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0328,v0043);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0043;
    stack[-1] = v0328;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0311;

v0311:
    v0318 = stack[-2];
    if (v0318 == nil) goto v0343;
    v0318 = stack[-2];
    v0307 = qcar(v0318);
    v0318 = stack[0];
    fn = elt(env, 1); /* evdif */
    v0307 = (*qfn2(fn))(qenv(fn), v0307, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0396;
    env = stack[-4];
    v0318 = stack[-3];
    v0318 = cons(v0307, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0396;
    env = stack[-4];
    stack[-3] = v0318;
    v0318 = stack[-2];
    v0318 = qcdr(v0318);
    v0307 = qcar(v0318);
    v0318 = stack[-1];
    fn = elt(env, 2); /* bcquot */
    v0307 = (*qfn2(fn))(qenv(fn), v0307, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0396;
    env = stack[-4];
    v0318 = stack[-3];
    v0318 = cons(v0307, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0396;
    env = stack[-4];
    stack[-3] = v0318;
    v0318 = stack[-2];
    v0318 = qcdr(v0318);
    v0318 = qcdr(v0318);
    stack[-2] = v0318;
    goto v0311;

v0343:
    v0318 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0318);
    }
/* error exit handlers */
v0396:
    popv(5);
    return nil;
}



/* Code for mkset */

static Lisp_Object CC_mkset(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0332;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkset");
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
    v0332 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* getrlist */
    v0332 = (*qfn1(fn))(qenv(fn), v0332);
    nil = C_nil;
    if (exception_pending()) goto v0311;
    env = stack[0];
    fn = elt(env, 2); /* delete!-dups */
    v0332 = (*qfn1(fn))(qenv(fn), v0332);
    nil = C_nil;
    if (exception_pending()) goto v0311;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* make!-set */
        return (*qfn1(fn))(qenv(fn), v0332);
    }
/* error exit handlers */
v0311:
    popv(1);
    return nil;
}



/* Code for infinityp */

static Lisp_Object CC_infinityp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0306, v0316, v0315;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for infinityp");
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
    v0306 = v0000;
/* end of prologue */
    v0306 = Lexplode(nil, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[0];
    v0306 = qcar(v0306);
    v0315 = v0306;
    v0316 = v0315;
    v0306 = elt(env, 1); /* !- */
    if (v0316 == v0306) goto v0325;
    v0306 = v0315;
    v0306 = Ldigitp(nil, v0306);
    goto v0311;

v0311:
    v0306 = (v0306 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0306); }

v0325:
    v0306 = qvalue(elt(env, 2)); /* t */
    goto v0311;
/* error exit handlers */
v0393:
    popv(1);
    return nil;
}



/* Code for mk!-strand!-vertex */

static Lisp_Object CC_mkKstrandKvertex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0328)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0327, v0378, v0261;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-strand-vertex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0328);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0327 = v0328;
    stack[-2] = v0000;
/* end of prologue */
    v0261 = stack[-2];
    v0378 = v0327;
    v0327 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* incident */
    v0327 = (*qfnn(fn))(qenv(fn), 3, v0261, v0378, v0327);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    v0378 = v0327;
    v0327 = v0378;
    v0327 = qcar(v0327);
    stack[-3] = v0327;
    stack[-1] = stack[-2];
    v0327 = v0378;
    stack[0] = qcdr(v0327);
    v0327 = stack[-3];
    v0327 = qcar(v0327);
    v0327 = qcdr(v0327);
    v0327 = add1(v0327);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    fn = elt(env, 1); /* incident */
    v0327 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0327);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    v0378 = v0327;
    v0327 = v0378;
    if (v0327 == nil) goto v0336;
    v0327 = v0378;
    v0327 = qcar(v0327);
    goto v0302;

v0302:
    v0261 = stack[-2];
    v0378 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* mk!-strand!-vertex2 */
        return (*qfnn(fn))(qenv(fn), 3, v0261, v0378, v0327);
    }

v0336:
    v0378 = stack[-2];
    v0327 = (Lisp_Object)1; /* 0 */
    v0327 = cons(v0378, v0327);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    v0327 = ncons(v0327);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0302;
/* error exit handlers */
v0240:
    popv(5);
    return nil;
}



/* Code for dp_content */

static Lisp_Object CC_dp_content(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0336;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_content");
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
    v0336 = stack[0];
    if (v0336 == nil) goto v0347;
    v0336 = stack[0];
    fn = elt(env, 2); /* dp_lc */
    v0336 = (*qfn1(fn))(qenv(fn), v0336);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-2];
    stack[-1] = v0336;
    v0336 = stack[0];
    v0336 = qcdr(v0336);
    stack[0] = v0336;
    goto v0308;

v0308:
    v0336 = stack[0];
    if (v0336 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0336 = stack[-1];
    fn = elt(env, 3); /* bc_inv */
    v0336 = (*qfn1(fn))(qenv(fn), v0336);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-2];
    if (!(v0336 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0336 = stack[0];
    fn = elt(env, 2); /* dp_lc */
    v0336 = (*qfn1(fn))(qenv(fn), v0336);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-2];
    fn = elt(env, 4); /* bc_gcd */
    v0336 = (*qfn2(fn))(qenv(fn), stack[-1], v0336);
    nil = C_nil;
    if (exception_pending()) goto v0266;
    env = stack[-2];
    stack[-1] = v0336;
    v0336 = stack[0];
    v0336 = qcdr(v0336);
    stack[0] = v0336;
    goto v0308;

v0347:
    v0336 = (Lisp_Object)1; /* 0 */
    {
        popv(3);
        fn = elt(env, 5); /* bc_fi */
        return (*qfn1(fn))(qenv(fn), v0336);
    }
/* error exit handlers */
v0266:
    popv(3);
    return nil;
}



/* Code for setmod */

static Lisp_Object CC_setmod(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0401, v0330;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmod");
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
    stack[-1] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    v0401 = stack[0];
    if (!consp(v0401)) goto v0332;
    v0401 = stack[0];
    v0401 = qcar(v0401);
    stack[0] = v0401;
    goto v0332;

v0332:
    v0401 = stack[0];
    fn = elt(env, 7); /* reval */
    v0401 = (*qfn1(fn))(qenv(fn), v0401);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-2];
    stack[0] = v0401;
    v0401 = stack[0];
    v0401 = integerp(v0401);
    if (v0401 == nil) goto v0324;
    v0330 = stack[0];
    v0401 = (Lisp_Object)1; /* 0 */
    v0401 = (Lisp_Object)greaterp2(v0330, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    v0401 = v0401 ? lisp_true : nil;
    env = stack[-2];
    if (v0401 == nil) goto v0324;
    v0401 = stack[0];
    fn = elt(env, 8); /* primep */
    v0401 = (*qfn1(fn))(qenv(fn), v0401);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-2];
    if (v0401 == nil) goto v0263;
    v0330 = elt(env, 2); /* (!:mod!:) */
    v0401 = elt(env, 3); /* field */
    v0401 = Lflag(nil, v0330, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-2];
    goto v0321;

v0321:
    v0401 = stack[0];
    fn = elt(env, 9); /* set!-general!-modulus */
    v0401 = (*qfn1(fn))(qenv(fn), v0401);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-2];
    goto v0347;

v0347:
    qvalue(elt(env, 1)) = stack[-1]; /* dmode!* */
    { popv(3); return onevalue(v0401); }

v0263:
    v0330 = elt(env, 2); /* (!:mod!:) */
    v0401 = elt(env, 3); /* field */
    v0401 = Lremflag(nil, v0330, v0401);
    env = stack[-2];
    goto v0321;

v0324:
    v0330 = stack[0];
    v0401 = (Lisp_Object)1; /* 0 */
    if (v0330 == v0401) goto v0301;
    v0401 = stack[0];
    v0401 = (v0401 == nil ? lisp_true : nil);
    goto v0396;

v0396:
    if (v0401 == nil) goto v0333;
    v0401 = qvalue(elt(env, 5)); /* current!-modulus */
    goto v0347;

v0333:
    v0330 = stack[0];
    v0401 = elt(env, 6); /* "modulus" */
    fn = elt(env, 10); /* typerr */
    v0401 = (*qfn2(fn))(qenv(fn), v0330, v0401);
    nil = C_nil;
    if (exception_pending()) goto v0395;
    env = stack[-2];
    v0401 = nil;
    goto v0347;

v0301:
    v0401 = qvalue(elt(env, 4)); /* t */
    goto v0396;
/* error exit handlers */
v0395:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* dmode!* */
    popv(3);
    return nil;
}



/* Code for ofsf_smmkatl!-or */

static Lisp_Object MS_CDECL CC_ofsf_smmkatlKor(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0328,
                         Lisp_Object v0043, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0407, v0408, v0409;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_smmkatl-or");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smmkatl-or");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0043,v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0328,v0043);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0043;
    v0407 = v0328;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = v0407;
    goto v0344;

v0344:
    v0407 = stack[-5];
    if (v0407 == nil) goto v0337;
    v0407 = stack[-5];
    v0407 = qcar(v0407);
    v0408 = v0407;
    v0409 = qcar(v0408);
    v0408 = stack[-4];
    v0408 = Latsoc(nil, v0409, v0408);
    v0409 = v0408;
    v0408 = v0409;
    if (v0408 == nil) goto v0349;
    v0408 = v0407;
    v0407 = stack[-3];
    fn = elt(env, 3); /* ofsf_smmkatl!-or1 */
    v0407 = (*qfnn(fn))(qenv(fn), 3, v0409, v0408, v0407);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-6];
    goto v0264;

v0264:
    stack[-2] = v0407;
    v0407 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v0407 = (*qfn1(fn))(qenv(fn), v0407);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-6];
    stack[-1] = v0407;
    v0407 = stack[-5];
    v0407 = qcdr(v0407);
    stack[-5] = v0407;
    v0407 = stack[-1];
    if (!consp(v0407)) goto v0344;
    else goto v0268;

v0268:
    v0407 = stack[-5];
    if (v0407 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0407 = stack[-5];
    v0407 = qcar(v0407);
    v0408 = v0407;
    v0409 = qcar(v0408);
    v0408 = stack[-4];
    v0408 = Latsoc(nil, v0409, v0408);
    v0409 = v0408;
    v0408 = v0409;
    if (v0408 == nil) goto v0411;
    v0408 = v0407;
    v0407 = stack[-3];
    fn = elt(env, 3); /* ofsf_smmkatl!-or1 */
    v0407 = (*qfnn(fn))(qenv(fn), 3, v0409, v0408, v0407);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-6];
    goto v0377;

v0377:
    v0407 = Lrplacd(nil, stack[0], v0407);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-6];
    v0407 = stack[-1];
    fn = elt(env, 4); /* lastpair */
    v0407 = (*qfn1(fn))(qenv(fn), v0407);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-6];
    stack[-1] = v0407;
    v0407 = stack[-5];
    v0407 = qcdr(v0407);
    stack[-5] = v0407;
    goto v0268;

v0411:
    v0409 = elt(env, 2); /* or */
    v0408 = v0407;
    v0407 = stack[-3];
    fn = elt(env, 5); /* ofsf_ir2atl */
    v0407 = (*qfnn(fn))(qenv(fn), 3, v0409, v0408, v0407);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-6];
    goto v0377;

v0349:
    v0408 = elt(env, 2); /* or */
    v0409 = v0407;
    v0407 = stack[-3];
    fn = elt(env, 5); /* ofsf_ir2atl */
    v0407 = (*qfnn(fn))(qenv(fn), 3, v0408, v0409, v0407);
    nil = C_nil;
    if (exception_pending()) goto v0410;
    env = stack[-6];
    goto v0264;

v0337:
    v0407 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0407); }
/* error exit handlers */
v0410:
    popv(7);
    return nil;
}



/* Code for interglue */

static Lisp_Object MS_CDECL CC_interglue(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0328,
                         Lisp_Object v0043, Lisp_Object v0196, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0453, v0454;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "interglue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for interglue");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0196,v0043,v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0328,v0043,v0196);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0196;
    stack[-2] = v0043;
    stack[-3] = v0328;
    stack[-4] = v0000;
/* end of prologue */
    v0453 = stack[-4];
    if (v0453 == nil) goto v0398;
    v0453 = stack[-3];
    if (v0453 == nil) goto v0350;
    v0453 = stack[-4];
    if (!consp(v0453)) goto v0321;
    v0453 = qvalue(elt(env, 1)); /* t */
    goto v0343;

v0343:
    if (v0453 == nil) goto v0379;
    v0453 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0453); }

v0379:
    v0453 = stack[-4];
    if (!symbolp(v0453)) v0453 = nil;
    else { v0453 = qfastgets(v0453);
           if (v0453 != nil) { v0453 = elt(v0453, 7); /* class */
#ifdef RECORD_GET
             if (v0453 != SPID_NOPROP)
                record_get(elt(fastget_names, 7), 1);
             else record_get(elt(fastget_names, 7), 0),
                v0453 = nil; }
           else record_get(elt(fastget_names, 7), 0); }
#else
             if (v0453 == SPID_NOPROP) v0453 = nil; }}
#endif
    stack[0] = v0453;
    v0453 = stack[-3];
    if (!symbolp(v0453)) v0453 = nil;
    else { v0453 = qfastgets(v0453);
           if (v0453 != nil) { v0453 = elt(v0453, 7); /* class */
#ifdef RECORD_GET
             if (v0453 != SPID_NOPROP)
                record_get(elt(fastget_names, 7), 1);
             else record_get(elt(fastget_names, 7), 0),
                v0453 = nil; }
           else record_get(elt(fastget_names, 7), 0); }
#else
             if (v0453 == SPID_NOPROP) v0453 = nil; }}
#endif
    v0454 = stack[0];
    v0453 = get(v0454, v0453);
    env = stack[-6];
    stack[-5] = v0453;
    v0453 = stack[-5];
    if (v0453 == nil) goto v0346;
    v0454 = stack[-4];
    v0453 = elt(env, 3); /* !\co!  */
    if (v0454 == v0453) goto v0385;
    v0454 = stack[-5];
    v0453 = (Lisp_Object)1; /* 0 */
    v0453 = (Lisp_Object)lessp2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    v0453 = v0453 ? lisp_true : nil;
    env = stack[-6];
    if (v0453 == nil) goto v0456;
    v0454 = stack[-2];
    v0453 = (Lisp_Object)1; /* 0 */
    v0453 = (Lisp_Object)greaterp2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    v0453 = v0453 ? lisp_true : nil;
    env = stack[-6];
    if (v0453 == nil) goto v0457;
    v0453 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0453); }

v0457:
    v0453 = stack[-5];
    v0453 = negate(v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    env = stack[-6];
    stack[-5] = v0453;
    goto v0456;

v0456:
    v0454 = stack[-5];
    v0453 = (Lisp_Object)17; /* 1 */
    if (v0454 == v0453) goto v0374;
    v0454 = stack[-5];
    v0453 = (Lisp_Object)33; /* 2 */
    if (v0454 == v0453) goto v0458;
    v0454 = stack[-5];
    v0453 = (Lisp_Object)49; /* 3 */
    if (v0454 == v0453) goto v0459;
    v0453 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0453); }

v0459:
    stack[0] = (Lisp_Object)10485761; /* 655360 */
    v0454 = stack[-1];
    v0453 = (Lisp_Object)161; /* 10 */
    v0454 = times2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    env = stack[-6];
    v0453 = (Lisp_Object)801; /* 50 */
    v0453 = difference2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    {
        Lisp_Object v0460 = stack[0];
        popv(7);
        return list2(v0460, v0453);
    }

v0458:
    v0454 = stack[-4];
    v0453 = elt(env, 4); /* !+ */
    if (v0454 == v0453) goto v0461;
    v0454 = stack[-4];
    v0453 = elt(env, 5); /* !- */
    v0453 = (v0454 == v0453 ? lisp_true : nil);
    goto v0462;

v0462:
    if (v0453 == nil) goto v0463;
    v0453 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0453); }

v0463:
    v0454 = stack[-3];
    v0453 = elt(env, 4); /* !+ */
    if (v0454 == v0453) goto v0232;
    v0454 = stack[-3];
    v0453 = elt(env, 5); /* !- */
    if (v0454 == v0453) goto v0464;
    v0453 = qvalue(elt(env, 2)); /* nil */
    goto v0465;

v0465:
    if (v0453 == nil) goto v0381;
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v0454 = stack[-1];
    v0453 = (Lisp_Object)481; /* 30 */
    v0454 = times2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    env = stack[-6];
    v0453 = (Lisp_Object)3361; /* 210 */
    v0453 = difference2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    {
        Lisp_Object v0466 = stack[0];
        popv(7);
        return list2(v0466, v0453);
    }

v0381:
    v0454 = stack[-4];
    v0453 = elt(env, 8); /* !\cdot!  */
    if (v0454 == v0453) goto v0467;
    v0454 = stack[-3];
    v0453 = elt(env, 8); /* !\cdot!  */
    if (v0454 == v0453) goto v0209;
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v0454 = stack[-1];
    v0453 = (Lisp_Object)161; /* 10 */
    v0453 = times2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    {
        Lisp_Object v0468 = stack[0];
        popv(7);
        return list2(v0468, v0453);
    }

v0209:
    v0453 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0453); }

v0467:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v0454 = stack[-1];
    v0453 = (Lisp_Object)161; /* 10 */
    v0454 = times2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    env = stack[-6];
    v0453 = (Lisp_Object)801; /* 50 */
    v0453 = plus2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    {
        Lisp_Object v0469 = stack[0];
        popv(7);
        return list2(v0469, v0453);
    }

v0464:
    v0454 = stack[0];
    v0453 = elt(env, 6); /* ord */
    if (v0454 == v0453) goto v0470;
    v0454 = stack[0];
    v0453 = elt(env, 7); /* clo */
    v0453 = (v0454 == v0453 ? lisp_true : nil);
    goto v0465;

v0470:
    v0453 = qvalue(elt(env, 1)); /* t */
    goto v0465;

v0232:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v0454 = stack[-1];
    v0453 = (Lisp_Object)481; /* 30 */
    v0454 = times2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    env = stack[-6];
    v0453 = (Lisp_Object)6241; /* 390 */
    v0453 = difference2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    {
        Lisp_Object v0471 = stack[0];
        popv(7);
        return list2(v0471, v0453);
    }

v0461:
    v0453 = qvalue(elt(env, 1)); /* t */
    goto v0462;

v0374:
    stack[0] = (Lisp_Object)1295361; /* 80960 */
    v0454 = stack[-1];
    v0453 = (Lisp_Object)161; /* 10 */
    v0454 = times2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    env = stack[-6];
    v0453 = (Lisp_Object)321; /* 20 */
    v0453 = plus2(v0454, v0453);
    nil = C_nil;
    if (exception_pending()) goto v0455;
    {
        Lisp_Object v0194 = stack[0];
        popv(7);
        return list2(v0194, v0453);
    }

v0385:
    v0454 = (Lisp_Object)1; /* 0 */
    v0453 = (Lisp_Object)-159999; /* -10000 */
    popv(7);
    return list2(v0454, v0453);

v0346:
    v0453 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0453); }

v0321:
    v0453 = stack[-3];
    v0453 = (consp(v0453) ? nil : lisp_true);
    v0453 = (v0453 == nil ? lisp_true : nil);
    goto v0343;

v0350:
    v0453 = qvalue(elt(env, 1)); /* t */
    goto v0343;

v0398:
    v0453 = qvalue(elt(env, 1)); /* t */
    goto v0343;
/* error exit handlers */
v0455:
    popv(7);
    return nil;
}



/* Code for ps!:times!: */

static Lisp_Object CC_psTtimesT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0328)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0269, v0353, v0230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:times:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0269 = v0328;
    v0353 = v0000;
/* end of prologue */
    v0230 = elt(env, 1); /* times */
    {
        fn = elt(env, 2); /* ps!:operator!: */
        return (*qfnn(fn))(qenv(fn), 3, v0230, v0353, v0269);
    }
}



/* Code for gi */

static Lisp_Object CC_gi(Lisp_Object env,
                         Lisp_Object v0328, Lisp_Object v0043)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0235, v0319;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0043,v0328);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0328,v0043);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0043;
    v0235 = v0328;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* gg!* */
    qvalue(elt(env, 1)) = nil; /* gg!* */
    qvalue(elt(env, 1)) = v0235; /* gg!* */
    stack[-2] = nil;
    v0235 = qvalue(elt(env, 1)); /* gg!* */
    stack[-1] = v0235;
    goto v0269;

v0269:
    v0235 = stack[-1];
    if (v0235 == nil) goto v0268;
    v0235 = stack[-1];
    v0235 = qcar(v0235);
    stack[0] = v0235;
    v0235 = stack[0];
    v0235 = qcdr(v0235);
    fn = elt(env, 3); /* class */
    v0319 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0472;
    env = stack[-5];
    v0235 = stack[-3];
    if (!(equal(v0319, v0235))) goto v0393;
    v0319 = stack[0];
    v0235 = stack[-2];
    v0235 = cons(v0319, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0472;
    env = stack[-5];
    stack[-2] = v0235;
    goto v0393;

v0393:
    v0235 = stack[-1];
    v0235 = qcdr(v0235);
    stack[-1] = v0235;
    goto v0269;

v0268:
    v0235 = stack[-2];
    qvalue(elt(env, 1)) = stack[-4]; /* gg!* */
    { popv(6); return onevalue(v0235); }
/* error exit handlers */
v0472:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* gg!* */
    popv(6);
    return nil;
}



/* Code for solvevars */

static Lisp_Object CC_solvevars(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0397, v0379;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvevars");
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
    v0379 = v0000;
/* end of prologue */
    v0397 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0397;
    v0397 = v0379;
    fn = elt(env, 2); /* allbkern */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-3];
    stack[-1] = v0397;
    goto v0311;

v0311:
    v0397 = stack[-1];
    if (v0397 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0397 = stack[-1];
    v0397 = qcar(v0397);
    stack[0] = v0397;
    v0397 = stack[0];
    fn = elt(env, 3); /* constant_exprp */
    v0397 = (*qfn1(fn))(qenv(fn), v0397);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-3];
    if (!(v0397 == nil)) goto v0308;
    v0379 = stack[0];
    v0397 = stack[-2];
    fn = elt(env, 4); /* ordad */
    v0397 = (*qfn2(fn))(qenv(fn), v0379, v0397);
    nil = C_nil;
    if (exception_pending()) goto v0317;
    env = stack[-3];
    stack[-2] = v0397;
    goto v0308;

v0308:
    v0397 = stack[-1];
    v0397 = qcdr(v0397);
    stack[-1] = v0397;
    goto v0311;
/* error exit handlers */
v0317:
    popv(4);
    return nil;
}



/* Code for ofsf_qesubq */

static Lisp_Object MS_CDECL CC_ofsf_qesubq(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0328,
                         Lisp_Object v0043, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0276, v0306, v0316;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_qesubq");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_qesubq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0043,v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0328,v0043);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0276 = v0043;
    v0306 = v0328;
    v0316 = v0000;
/* end of prologue */
    stack[-1] = v0316;
    stack[0] = elt(env, 1); /* ofsf_qesubqat */
    v0276 = list2(v0306, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0275;
    env = stack[-2];
    {
        Lisp_Object v0400 = stack[-1];
        Lisp_Object v0329 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v0400, v0329, v0276);
    }
/* error exit handlers */
v0275:
    popv(3);
    return nil;
}



/* Code for dependsl */

static Lisp_Object CC_dependsl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0328)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0322, v0320;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dependsl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0328);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0328;
    stack[-1] = v0000;
/* end of prologue */

v0473:
    v0322 = stack[0];
    if (v0322 == nil) goto v0392;
    v0320 = stack[-1];
    v0322 = stack[0];
    v0322 = qcar(v0322);
    fn = elt(env, 2); /* depends */
    v0322 = (*qfn2(fn))(qenv(fn), v0320, v0322);
    nil = C_nil;
    if (exception_pending()) goto v0397;
    env = stack[-2];
    if (!(v0322 == nil)) { popv(3); return onevalue(v0322); }
    v0320 = stack[-1];
    v0322 = stack[0];
    v0322 = qcdr(v0322);
    stack[-1] = v0320;
    stack[0] = v0322;
    goto v0473;

v0392:
    v0322 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0322); }
/* error exit handlers */
v0397:
    popv(3);
    return nil;
}



/* Code for simpx1 */

static Lisp_Object MS_CDECL CC_simpx1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0328,
                         Lisp_Object v0043, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0562, v0563, v0564;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpx1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpx1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0043,v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0328,v0043);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0043;
    stack[-1] = v0328;
    stack[-4] = v0000;
/* end of prologue */
    stack[-6] = nil;
    v0563 = stack[-4];
    v0562 = elt(env, 1); /* !*minus!* */
    if (!consp(v0563)) goto v0344;
    v0563 = qcar(v0563);
    if (!(v0563 == v0562)) goto v0344;
    v0563 = stack[-1];
    v0562 = (Lisp_Object)17; /* 1 */
    if (v0563 == v0562) goto v0314;
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0329;

v0329:
    if (!(v0562 == nil)) goto v0444;
    v0563 = stack[-3];
    v0562 = (Lisp_Object)17; /* 1 */
    if (v0563 == v0562) goto v0303;
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0259;

v0259:
    if (!(v0562 == nil)) goto v0444;
    v0563 = stack[-1];
    v0562 = (Lisp_Object)17; /* 1 */
    if (v0563 == v0562) goto v0565;
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0566;

v0566:
    if (v0562 == nil) goto v0344;
    v0562 = stack[-4];
    v0562 = qcdr(v0562);
    stack[0] = qcar(v0562);
    v0564 = elt(env, 3); /* quotient */
    v0563 = stack[-1];
    v0562 = stack[-3];
    v0562 = list3(v0564, v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = list2(stack[0], v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    fn = elt(env, 19); /* simpexpt */
    v0562 = (*qfn1(fn))(qenv(fn), v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 20); /* negsq */
        return (*qfn1(fn))(qenv(fn), v0562);
    }

v0344:
    v0562 = stack[-1];
    if (!(is_number(v0562))) goto v0219;
    v0562 = stack[-3];
    if (!(is_number(v0562))) goto v0219;

v0341:
    v0562 = stack[-1];
    if (is_number(v0562)) goto v0210;
    v0562 = stack[-1];
    if (!consp(v0562)) goto v0568;
    v0562 = stack[-1];
    v0563 = qcar(v0562);
    v0562 = elt(env, 11); /* minus */
    if (v0563 == v0562) goto v0569;
    v0562 = stack[-1];
    v0563 = qcar(v0562);
    v0562 = elt(env, 12); /* plus */
    if (v0563 == v0562) goto v0570;
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0155;

v0155:
    if (v0562 == nil) goto v0571;
    v0563 = (Lisp_Object)17; /* 1 */
    v0562 = (Lisp_Object)17; /* 1 */
    v0562 = cons(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-5] = v0562;
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    stack[-2] = v0562;
    goto v0572;

v0572:
    v0562 = stack[-2];
    if (v0562 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v0562 = stack[-2];
    v0562 = qcar(v0562);
    stack[-1] = stack[-4];
    stack[0] = elt(env, 3); /* quotient */
    v0563 = stack[-6];
    if (v0563 == nil) goto v0573;
    v0563 = elt(env, 11); /* minus */
    v0562 = list2(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0563 = v0562;
    goto v0140;

v0140:
    v0562 = stack[-3];
    v0562 = list3(stack[0], v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = list2(stack[-1], v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    fn = elt(env, 19); /* simpexpt */
    v0563 = (*qfn1(fn))(qenv(fn), v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = stack[-5];
    fn = elt(env, 21); /* multsq */
    v0562 = (*qfn2(fn))(qenv(fn), v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-5] = v0562;
    v0562 = stack[-2];
    v0562 = qcdr(v0562);
    stack[-2] = v0562;
    goto v0572;

v0573:
    v0563 = v0562;
    goto v0140;

v0571:
    v0562 = stack[-1];
    v0563 = qcar(v0562);
    v0562 = elt(env, 14); /* times */
    if (v0563 == v0562) goto v0574;
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0136;

v0136:
    if (v0562 == nil) goto v0575;
    v0562 = stack[-3];
    if (is_number(v0562)) goto v0576;
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0562 = qcar(v0562);
    stack[-5] = v0562;
    goto v0577;

v0577:
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0562 = qcdr(v0562);
    v0562 = qcdr(v0562);
    if (v0562 == nil) goto v0112;
    v0563 = elt(env, 14); /* times */
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0562 = qcdr(v0562);
    v0562 = cons(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    goto v0578;

v0578:
    stack[-1] = v0562;
    goto v0209;

v0209:
    v0562 = stack[-4];
    if (!(symbolp(v0562))) goto v0579;
    v0563 = stack[-4];
    v0562 = elt(env, 15); /* used!* */
    v0562 = Lflagp(nil, v0563, v0562);
    env = stack[-7];
    if (!(v0562 == nil)) goto v0579;
    v0562 = stack[-4];
    v0563 = ncons(v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = elt(env, 15); /* used!* */
    v0562 = Lflag(nil, v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    goto v0579;

v0579:
    v0563 = stack[-4];
    v0562 = elt(env, 16); /* (minus 1) */
    if (equal(v0563, v0562)) goto v0580;
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0581;

v0581:
    if (v0562 == nil) goto v0582;
    v0562 = elt(env, 5); /* i */
    fn = elt(env, 22); /* simp */
    v0562 = (*qfn1(fn))(qenv(fn), v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-4] = v0562;
    v0562 = stack[-6];
    if (v0562 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    v0562 = stack[-4];
    {
        popv(8);
        fn = elt(env, 20); /* negsq */
        return (*qfn1(fn))(qenv(fn), v0562);
    }

v0582:
    stack[0] = elt(env, 4); /* expt */
    stack[-2] = stack[-4];
    v0563 = stack[-3];
    v0562 = (Lisp_Object)17; /* 1 */
    if (v0563 == v0562) goto v0583;
    v0564 = elt(env, 3); /* quotient */
    v0563 = stack[-1];
    v0562 = stack[-3];
    v0562 = list3(v0564, v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    goto v0584;

v0584:
    v0562 = list3(stack[0], stack[-2], v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-4] = v0562;
    stack[0] = stack[-4];
    v0562 = stack[-6];
    if (v0562 == nil) goto v0585;
    v0562 = stack[-5];
    v0562 = negate(v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    goto v0586;

v0586:
    {
        Lisp_Object v0587 = stack[0];
        popv(8);
        fn = elt(env, 23); /* mksq */
        return (*qfn2(fn))(qenv(fn), v0587, v0562);
    }

v0585:
    v0562 = stack[-5];
    goto v0586;

v0583:
    v0562 = stack[-1];
    goto v0584;

v0580:
    v0563 = stack[-3];
    v0562 = (Lisp_Object)17; /* 1 */
    if (v0563 == v0562) goto v0091;
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0581;

v0091:
    v0564 = elt(env, 17); /* difference */
    v0563 = stack[-1];
    v0562 = elt(env, 18); /* (quotient 1 2) */
    v0562 = list3(v0564, v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    fn = elt(env, 22); /* simp */
    v0562 = (*qfn1(fn))(qenv(fn), v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = qcar(v0562);
    v0562 = (v0562 == nil ? lisp_true : nil);
    goto v0581;

v0112:
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0562 = qcdr(v0562);
    v0562 = qcar(v0562);
    goto v0578;

v0576:
    v0563 = stack[-3];
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0562 = qcar(v0562);
    v0562 = Lgcd(nil, v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-5] = v0562;
    v0563 = stack[-3];
    v0562 = stack[-5];
    v0562 = quot2(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-3] = v0562;
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0563 = qcar(v0562);
    v0562 = stack[-5];
    v0562 = quot2(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-5] = v0562;
    goto v0577;

v0575:
    v0562 = stack[-1];
    v0563 = qcar(v0562);
    v0562 = elt(env, 3); /* quotient */
    if (v0563 == v0562) goto v0588;
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0589;

v0589:
    if (v0562 == nil) goto v0590;
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0562 = qcdr(v0562);
    v0562 = qcar(v0562);
    stack[-3] = v0562;
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0562 = qcar(v0562);
    stack[-1] = v0562;
    goto v0341;

v0590:
    v0562 = (Lisp_Object)17; /* 1 */
    stack[-5] = v0562;
    goto v0209;

v0588:
    v0563 = stack[-3];
    v0562 = (Lisp_Object)17; /* 1 */
    if (v0563 == v0562) goto v0591;
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0589;

v0591:
    v0562 = qvalue(elt(env, 13)); /* !*expandexpt */
    goto v0589;

v0574:
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0562 = qcar(v0562);
    v0562 = integerp(v0562);
    goto v0136;

v0570:
    v0562 = qvalue(elt(env, 13)); /* !*expandexpt */
    goto v0155;

v0569:
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0562 = qcar(v0562);
    stack[-1] = v0562;
    goto v0343;

v0343:
    v0562 = qvalue(elt(env, 7)); /* !*mcd */
    if (v0562 == nil) goto v0592;
    v0564 = stack[-4];
    v0563 = stack[-1];
    v0562 = stack[-3];
    v0562 = CC_simpx1(env, 3, v0564, v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 24); /* invsq */
        return (*qfn1(fn))(qenv(fn), v0562);
    }

v0592:
    v0562 = stack[-6];
    v0562 = (v0562 == nil ? lisp_true : nil);
    stack[-6] = v0562;
    goto v0341;

v0568:
    v0562 = (Lisp_Object)17; /* 1 */
    stack[-5] = v0562;
    goto v0209;

v0210:
    v0562 = stack[-1];
    v0562 = Lminusp(nil, v0562);
    env = stack[-7];
    if (v0562 == nil) goto v0424;
    v0562 = stack[-1];
    v0562 = negate(v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-1] = v0562;
    goto v0343;

v0424:
    v0562 = stack[-1];
    v0562 = integerp(v0562);
    if (v0562 == nil) goto v0158;
    v0562 = stack[-3];
    v0562 = integerp(v0562);
    if (v0562 == nil) goto v0593;
    v0562 = stack[-6];
    if (v0562 == nil) goto v0201;
    v0562 = stack[-1];
    v0562 = negate(v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-1] = v0562;
    goto v0201;

v0201:
    v0562 = stack[-1];
    stack[-5] = v0562;
    v0562 = qvalue(elt(env, 7)); /* !*mcd */
    if (v0562 == nil) goto v0594;
    v0562 = stack[-4];
    v0562 = integerp(v0562);
    if (!(v0562 == nil)) goto v0595;
    v0562 = qvalue(elt(env, 8)); /* !*notseparate */
    if (!(v0562 == nil)) goto v0594;

v0595:
    stack[-2] = stack[-5];
    stack[0] = stack[-3];
    v0563 = stack[-1];
    v0562 = stack[-3];
    v0562 = quot2(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-1] = v0562;
    v0562 = times2(stack[0], v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = difference2(stack[-2], v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-5] = v0562;
    v0563 = stack[-5];
    v0562 = (Lisp_Object)1; /* 0 */
    v0562 = (Lisp_Object)lessp2(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    v0562 = v0562 ? lisp_true : nil;
    env = stack[-7];
    if (v0562 == nil) goto v0596;
    v0562 = stack[-1];
    v0562 = sub1(v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-1] = v0562;
    v0563 = stack[-5];
    v0562 = stack[-3];
    v0562 = plus2(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-5] = v0562;
    goto v0596;

v0596:
    v0563 = stack[-4];
    v0562 = stack[-1];
    v0562 = list2(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    fn = elt(env, 19); /* simpexpt */
    v0562 = (*qfn1(fn))(qenv(fn), v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[0] = v0562;
    v0563 = stack[-5];
    v0562 = (Lisp_Object)1; /* 0 */
    if (v0563 == v0562) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v0563 = stack[-3];
    v0562 = (Lisp_Object)33; /* 2 */
    if (v0563 == v0562) goto v0597;
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0177;

v0177:
    if (v0562 == nil) goto v0598;
    stack[-1] = stack[0];
    v0562 = elt(env, 10); /* sqrt */
    if (!symbolp(v0562)) stack[0] = nil;
    else { stack[0] = qfastgets(v0562);
           if (stack[0] != nil) { stack[0] = elt(stack[0], 22); /* simpfn 
*/
#ifdef RECORD_GET
             if (stack[0] != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                stack[0] = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (stack[0] == SPID_NOPROP) stack[0] = nil; }}
#endif
    v0562 = stack[-4];
    v0562 = ncons(v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = Lapply1(nil, stack[0], v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    fn = elt(env, 21); /* multsq */
    v0562 = (*qfn2(fn))(qenv(fn), stack[-1], v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[0] = v0562;
    v0563 = stack[-5];
    v0562 = (Lisp_Object)1; /* 0 */
    v0562 = (Lisp_Object)lessp2(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    v0562 = v0562 ? lisp_true : nil;
    env = stack[-7];
    if (v0562 == nil) goto v0599;
    v0562 = stack[0];
    fn = elt(env, 24); /* invsq */
    v0562 = (*qfn1(fn))(qenv(fn), v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[0] = v0562;
    v0562 = stack[-5];
    v0562 = negate(v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    stack[-5] = v0562;
    goto v0599;

v0599:
    v0563 = stack[0];
    v0562 = stack[-5];
    {
        popv(8);
        fn = elt(env, 25); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v0563, v0562);
    }

v0598:
    v0562 = stack[-4];
    fn = elt(env, 26); /* simp!* */
    v0563 = (*qfn1(fn))(qenv(fn), v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = stack[-3];
    fn = elt(env, 27); /* simprad */
    v0563 = (*qfn2(fn))(qenv(fn), v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = stack[-5];
    fn = elt(env, 25); /* exptsq */
    v0562 = (*qfn2(fn))(qenv(fn), v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    {
        Lisp_Object v0600 = stack[0];
        popv(8);
        fn = elt(env, 21); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0600, v0562);
    }

v0597:
    v0562 = qvalue(elt(env, 9)); /* !*keepsqrts */
    goto v0177;

v0594:
    v0562 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0562;
    goto v0596;

v0593:
    v0562 = stack[-1];
    stack[-5] = v0562;
    v0562 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0562;
    goto v0209;

v0158:
    v0562 = (Lisp_Object)17; /* 1 */
    stack[-5] = v0562;
    goto v0209;

v0219:
    v0563 = qvalue(elt(env, 6)); /* frlis!* */
    v0562 = stack[-1];
    fn = elt(env, 28); /* smemqlp */
    v0562 = (*qfn2(fn))(qenv(fn), v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    if (!(v0562 == nil)) goto v0216;
    v0563 = qvalue(elt(env, 6)); /* frlis!* */
    v0562 = stack[-3];
    fn = elt(env, 28); /* smemqlp */
    v0562 = (*qfn2(fn))(qenv(fn), v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    if (v0562 == nil) goto v0341;
    else goto v0216;

v0216:
    stack[0] = elt(env, 4); /* expt */
    stack[-2] = stack[-4];
    v0563 = stack[-3];
    v0562 = (Lisp_Object)17; /* 1 */
    if (v0563 == v0562) goto v0206;
    v0564 = elt(env, 3); /* quotient */
    v0563 = stack[-1];
    v0562 = stack[-3];
    v0562 = list3(v0564, v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    goto v0381;

v0381:
    v0563 = list3(stack[0], stack[-2], v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 23); /* mksq */
        return (*qfn2(fn))(qenv(fn), v0563, v0562);
    }

v0206:
    v0562 = stack[-1];
    goto v0381;

v0565:
    v0562 = stack[-3];
    v0562 = integerp(v0562);
    goto v0566;

v0444:
    stack[-6] = elt(env, 4); /* expt */
    stack[-5] = elt(env, 5); /* i */
    stack[-2] = elt(env, 3); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v0563 = stack[-3];
    v0562 = (Lisp_Object)33; /* 2 */
    v0562 = quot2(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = list3(stack[-2], stack[0], v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = list3(stack[-6], stack[-5], v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    fn = elt(env, 22); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = stack[-4];
    v0562 = qcdr(v0562);
    stack[-2] = qcar(v0562);
    v0564 = elt(env, 3); /* quotient */
    v0563 = stack[-1];
    v0562 = stack[-3];
    v0562 = list3(v0564, v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = list2(stack[-2], v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    fn = elt(env, 19); /* simpexpt */
    v0562 = (*qfn1(fn))(qenv(fn), v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    {
        Lisp_Object v0601 = stack[0];
        popv(8);
        fn = elt(env, 21); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0601, v0562);
    }

v0303:
    v0563 = stack[-1];
    v0562 = elt(env, 3); /* quotient */
    if (!consp(v0563)) goto v0246;
    v0563 = qcar(v0563);
    if (!(v0563 == v0562)) goto v0246;
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0563 = qcar(v0562);
    v0562 = (Lisp_Object)17; /* 1 */
    if (v0563 == v0562) goto v0449;
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0259;

v0449:
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0562 = qcdr(v0562);
    v0562 = qcar(v0562);
    v0562 = integerp(v0562);
    if (v0562 == nil) goto v0250;
    v0562 = stack[-1];
    v0562 = qcdr(v0562);
    v0562 = qcdr(v0562);
    v0563 = qcar(v0562);
    v0562 = (Lisp_Object)33; /* 2 */
    v0563 = Cremainder(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = (Lisp_Object)1; /* 0 */
    v0562 = (v0563 == v0562 ? lisp_true : nil);
    goto v0259;

v0250:
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0259;

v0246:
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0259;

v0314:
    v0562 = stack[-3];
    v0562 = integerp(v0562);
    if (v0562 == nil) goto v0317;
    v0563 = stack[-3];
    v0562 = (Lisp_Object)33; /* 2 */
    v0563 = Cremainder(v0563, v0562);
    nil = C_nil;
    if (exception_pending()) goto v0567;
    env = stack[-7];
    v0562 = (Lisp_Object)1; /* 0 */
    v0562 = (v0563 == v0562 ? lisp_true : nil);
    goto v0329;

v0317:
    v0562 = qvalue(elt(env, 2)); /* nil */
    goto v0329;
/* error exit handlers */
v0567:
    popv(8);
    return nil;
}



/* Code for deleteq */

static Lisp_Object CC_deleteq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0328)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0266, v0263, v0375;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deleteq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0328);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0328;
    stack[-1] = v0000;
/* end of prologue */
    v0375 = nil;
    goto v0332;

v0332:
    v0266 = stack[-1];
    if (v0266 == nil) goto v0341;
    v0266 = stack[-1];
    v0263 = qcar(v0266);
    v0266 = stack[0];
    if (v0263 == v0266) goto v0315;
    v0266 = stack[-1];
    v0266 = qcar(v0266);
    v0263 = v0375;
    v0266 = cons(v0266, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-2];
    v0375 = v0266;
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    stack[-1] = v0266;
    goto v0332;

v0315:
    v0263 = v0375;
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0263, v0266);
    }

v0341:
    v0266 = v0375;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0266);
    }
/* error exit handlers */
v0388:
    popv(3);
    return nil;
}



/* Code for qqe_simplqequal */

static Lisp_Object CC_qqe_simplqequal(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0328)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0542, v0594, v0622;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplqequal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0328);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0542 = v0328;
    stack[0] = v0000;
/* end of prologue */

v0473:
    v0542 = stack[0];
    fn = elt(env, 7); /* qqe_arg2r */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    stack[-7] = v0542;
    v0542 = stack[0];
    fn = elt(env, 8); /* qqe_arg2l */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    stack[-8] = v0542;
    v0594 = stack[-7];
    v0542 = stack[-8];
    if (equal(v0594, v0542)) goto v0309;
    v0542 = stack[-8];
    fn = elt(env, 9); /* qqe_qprefix!-var */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    stack[-6] = v0542;
    v0542 = stack[-7];
    fn = elt(env, 9); /* qqe_qprefix!-var */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    stack[-5] = v0542;
    v0594 = stack[-6];
    v0542 = stack[-5];
    if (v0594 == v0542) goto v0317;
    v0594 = stack[-6];
    v0542 = elt(env, 3); /* qepsilon */
    if (v0594 == v0542) goto v0302;
    v0594 = stack[-5];
    v0542 = elt(env, 3); /* qepsilon */
    v0542 = (v0594 == v0542 ? lisp_true : nil);
    goto v0384;

v0384:
    if (v0542 == nil) goto v0397;
    v0542 = stack[-7];
    fn = elt(env, 10); /* qqe_number!-of!-adds!-in!-qterm */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    stack[-3] = v0542;
    v0542 = stack[-8];
    fn = elt(env, 10); /* qqe_number!-of!-adds!-in!-qterm */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    stack[-4] = v0542;
    v0542 = stack[-7];
    fn = elt(env, 11); /* qqe_number!-of!-tails!-in!-qterm */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    stack[-1] = v0542;
    v0542 = stack[-8];
    fn = elt(env, 11); /* qqe_number!-of!-tails!-in!-qterm */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    stack[-2] = v0542;
    v0594 = stack[-6];
    v0542 = stack[-5];
    if (v0594 == v0542) goto v0448;
    v0542 = qvalue(elt(env, 4)); /* nil */
    goto v0394;

v0394:
    if (v0542 == nil) goto v0462;
    v0542 = elt(env, 5); /* false */
    { popv(10); return onevalue(v0542); }

v0462:
    v0594 = stack[-7];
    v0542 = elt(env, 3); /* qepsilon */
    if (v0594 == v0542) goto v0239;
    v0542 = qvalue(elt(env, 4)); /* nil */
    goto v0623;

v0623:
    if (v0542 == nil) goto v0624;
    v0542 = elt(env, 5); /* false */
    { popv(10); return onevalue(v0542); }

v0624:
    v0594 = stack[-8];
    v0542 = elt(env, 3); /* qepsilon */
    if (v0594 == v0542) goto v0231;
    v0542 = qvalue(elt(env, 4)); /* nil */
    goto v0234;

v0234:
    if (v0542 == nil) goto v0277;
    v0542 = elt(env, 5); /* false */
    { popv(10); return onevalue(v0542); }

v0277:
    v0594 = stack[-7];
    v0542 = elt(env, 3); /* qepsilon */
    if (v0594 == v0542) goto v0225;
    v0542 = qvalue(elt(env, 4)); /* nil */
    goto v0226;

v0226:
    if (v0542 == nil) goto v0216;
    v0594 = stack[-6];
    v0542 = elt(env, 3); /* qepsilon */
    if (v0594 == v0542) goto v0625;
    v0542 = stack[-8];
    fn = elt(env, 12); /* qqe_simplterm */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    v0594 = elt(env, 6); /* qequal */
    v0622 = v0542;
    v0542 = stack[-7];
    {
        popv(10);
        fn = elt(env, 13); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0594, v0622, v0542);
    }

v0625:
    v0542 = elt(env, 1); /* true */
    { popv(10); return onevalue(v0542); }

v0216:
    v0594 = stack[-8];
    v0542 = elt(env, 3); /* qepsilon */
    if (v0594 == v0542) goto v0206;
    v0542 = qvalue(elt(env, 4)); /* nil */
    goto v0217;

v0217:
    if (v0542 == nil) goto v0397;
    v0594 = stack[-5];
    v0542 = elt(env, 3); /* qepsilon */
    if (v0594 == v0542) goto v0544;
    v0542 = stack[-7];
    fn = elt(env, 12); /* qqe_simplterm */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    stack[0] = v0542;
    v0622 = elt(env, 6); /* qequal */
    v0594 = stack[-8];
    v0542 = stack[0];
    {
        popv(10);
        fn = elt(env, 13); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0622, v0594, v0542);
    }

v0544:
    v0542 = elt(env, 1); /* true */
    { popv(10); return onevalue(v0542); }

v0397:
    v0542 = stack[-7];
    fn = elt(env, 12); /* qqe_simplterm */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    stack[0] = v0542;
    v0542 = stack[-8];
    fn = elt(env, 12); /* qqe_simplterm */
    v0542 = (*qfn1(fn))(qenv(fn), v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    v0622 = stack[-7];
    v0594 = stack[0];
    if (equal(v0622, v0594)) goto v0595;
    v0594 = qvalue(elt(env, 4)); /* nil */
    goto v0419;

v0419:
    if (v0594 == nil) goto v0195;
    v0622 = elt(env, 6); /* qequal */
    v0594 = v0542;
    v0542 = stack[0];
    {
        popv(10);
        fn = elt(env, 13); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0622, v0594, v0542);
    }

v0195:
    v0622 = elt(env, 6); /* qequal */
    v0594 = v0542;
    v0542 = stack[0];
    fn = elt(env, 13); /* qqe_mk2 */
    v0542 = (*qfnn(fn))(qenv(fn), 3, v0622, v0594, v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    stack[0] = v0542;
    goto v0473;

v0595:
    v0622 = stack[-8];
    v0594 = v0542;
    v0594 = (equal(v0622, v0594) ? lisp_true : nil);
    goto v0419;

v0206:
    v0594 = stack[-3];
    v0542 = (Lisp_Object)1; /* 0 */
    if (v0594 == v0542) goto v0426;
    v0542 = qvalue(elt(env, 4)); /* nil */
    goto v0217;

v0426:
    v0594 = stack[-4];
    v0542 = (Lisp_Object)1; /* 0 */
    v0542 = (v0594 == v0542 ? lisp_true : nil);
    goto v0217;

v0225:
    v0594 = stack[-3];
    v0542 = (Lisp_Object)1; /* 0 */
    if (v0594 == v0542) goto v0279;
    v0542 = qvalue(elt(env, 4)); /* nil */
    goto v0226;

v0279:
    v0594 = stack[-4];
    v0542 = (Lisp_Object)1; /* 0 */
    v0542 = (v0594 == v0542 ? lisp_true : nil);
    goto v0226;

v0231:
    v0594 = stack[-3];
    v0542 = stack[-1];
    v0542 = (Lisp_Object)greaterp2(v0594, v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    v0542 = v0542 ? lisp_true : nil;
    env = stack[-9];
    goto v0234;

v0239:
    v0594 = stack[-4];
    v0542 = stack[-2];
    v0542 = (Lisp_Object)greaterp2(v0594, v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    v0542 = v0542 ? lisp_true : nil;
    env = stack[-9];
    goto v0623;

v0448:
    v0594 = stack[-3];
    v0542 = stack[-1];
    v0542 = (Lisp_Object)geq2(v0594, v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    v0542 = v0542 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0542 == nil)) goto v0407;
    v0594 = stack[-4];
    v0542 = stack[-2];
    v0542 = (Lisp_Object)geq2(v0594, v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    v0542 = v0542 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0542 == nil)) goto v0407;
    v0542 = qvalue(elt(env, 4)); /* nil */
    goto v0394;

v0407:
    v0594 = stack[-3];
    v0542 = stack[-1];
    stack[0] = difference2(v0594, v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    v0594 = stack[-4];
    v0542 = stack[-2];
    v0542 = difference2(v0594, v0542);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-9];
    v0542 = (equal(stack[0], v0542) ? lisp_true : nil);
    v0542 = (v0542 == nil ? lisp_true : nil);
    goto v0394;

v0302:
    v0542 = qvalue(elt(env, 2)); /* t */
    goto v0384;

v0317:
    v0542 = qvalue(elt(env, 2)); /* t */
    goto v0384;

v0309:
    v0542 = elt(env, 1); /* true */
    { popv(10); return onevalue(v0542); }
/* error exit handlers */
v0184:
    popv(10);
    return nil;
}



/* Code for rl_b2atl */

static Lisp_Object CC_rl_b2atl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0328)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0383, v0350;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_b2atl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0328);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0383 = v0328;
    v0350 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_b2atl!* */
    v0383 = list2(v0350, v0383);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-1];
    {
        Lisp_Object v0276 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0276, v0383);
    }
/* error exit handlers */
v0309:
    popv(2);
    return nil;
}



/* Code for ev_max!# */

static Lisp_Object CC_ev_maxC(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0328)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0383, v0350, v0308, v0309;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_max#");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0350 = v0328;
    v0308 = v0000;
/* end of prologue */
    v0309 = v0308;
    v0383 = v0350;
    if (((int32_t)(v0309)) > ((int32_t)(v0383))) return onevalue(v0308);
    else return onevalue(v0350);
}



/* Code for expvec2a1 */

static Lisp_Object CC_expvec2a1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0328)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0560, v0333, v0451;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expvec2a1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0328);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0328;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0332;

v0332:
    v0560 = stack[-1];
    if (v0560 == nil) goto v0341;
    v0560 = stack[-1];
    v0333 = qcar(v0560);
    v0560 = (Lisp_Object)1; /* 0 */
    if (v0333 == v0560) goto v0269;
    v0560 = stack[-1];
    v0333 = qcar(v0560);
    v0560 = (Lisp_Object)17; /* 1 */
    if (v0333 == v0560) goto v0349;
    v0451 = elt(env, 1); /* expt */
    v0560 = stack[0];
    v0333 = qcar(v0560);
    v0560 = stack[-1];
    v0560 = qcar(v0560);
    v0333 = list3(v0451, v0333, v0560);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-3];
    v0560 = stack[-2];
    v0560 = cons(v0333, v0560);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-3];
    stack[-2] = v0560;
    v0560 = stack[-1];
    v0560 = qcdr(v0560);
    stack[-1] = v0560;
    v0560 = stack[0];
    v0560 = qcdr(v0560);
    stack[0] = v0560;
    goto v0332;

v0349:
    v0560 = stack[0];
    v0333 = qcar(v0560);
    v0560 = stack[-2];
    v0560 = cons(v0333, v0560);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-3];
    stack[-2] = v0560;
    v0560 = stack[-1];
    v0560 = qcdr(v0560);
    stack[-1] = v0560;
    v0560 = stack[0];
    v0560 = qcdr(v0560);
    stack[0] = v0560;
    goto v0332;

v0269:
    v0560 = stack[-1];
    v0560 = qcdr(v0560);
    stack[-1] = v0560;
    v0560 = stack[0];
    v0560 = qcdr(v0560);
    stack[0] = v0560;
    goto v0332;

v0341:
    v0560 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0560);
    }
/* error exit handlers */
v0303:
    popv(4);
    return nil;
}



/* Code for xreduce1 */

static Lisp_Object MS_CDECL CC_xreduce1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0328,
                         Lisp_Object v0043, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0348, v0349, v0384;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xreduce1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xreduce1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0043,v0328,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0328,v0043);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0043;
    stack[-1] = v0328;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0268;

v0268:
    v0384 = stack[-2];
    v0349 = stack[-1];
    v0348 = stack[0];
    fn = elt(env, 1); /* weak_xreduce1 */
    v0348 = (*qfnn(fn))(qenv(fn), 3, v0384, v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-4];
    stack[-2] = v0348;
    if (v0348 == nil) goto v0264;
    v0348 = stack[-2];
    v0349 = qcar(v0348);
    v0348 = stack[-3];
    v0348 = cons(v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-4];
    stack[-3] = v0348;
    v0348 = stack[-2];
    v0348 = qcdr(v0348);
    stack[-2] = v0348;
    goto v0268;

v0264:
    v0348 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0348);
    }
/* error exit handlers */
v0265:
    popv(5);
    return nil;
}



setup_type const u48_setup[] =
{
    {"liendimcom",              CC_liendimcom,  too_many_1,    wrong_no_1},
    {"basic-kern1",             CC_basicKkern1, too_many_1,    wrong_no_1},
    {"setqdeletedescendants",   CC_setqdeletedescendants,too_many_1,wrong_no_1},
    {"preptaylor*2",            too_few_2,      CC_preptaylorH2,wrong_no_2},
    {"evalleq",                 too_few_2,      CC_evalleq,    wrong_no_2},
    {"vp1",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_vp1},
    {"makecoeffpairs1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairs1},
    {"ofsf_sacatlp",            too_few_2,      CC_ofsf_sacatlp,wrong_no_2},
    {"crnprep1",                CC_crnprep1,    too_many_1,    wrong_no_1},
    {"ldf-pow-var",             CC_ldfKpowKvar, too_many_1,    wrong_no_1},
    {"dipdivmon",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipdivmon},
    {"mkset",                   CC_mkset,       too_many_1,    wrong_no_1},
    {"infinityp",               CC_infinityp,   too_many_1,    wrong_no_1},
    {"mk-strand-vertex",        too_few_2,      CC_mkKstrandKvertex,wrong_no_2},
    {"dp_content",              CC_dp_content,  too_many_1,    wrong_no_1},
    {"setmod",                  CC_setmod,      too_many_1,    wrong_no_1},
    {"ofsf_smmkatl-or",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatlKor},
    {"interglue",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_interglue},
    {"ps:times:",               too_few_2,      CC_psTtimesT,  wrong_no_2},
    {"gi",                      too_few_2,      CC_gi,         wrong_no_2},
    {"solvevars",               CC_solvevars,   too_many_1,    wrong_no_1},
    {"ofsf_qesubq",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_qesubq},
    {"dependsl",                too_few_2,      CC_dependsl,   wrong_no_2},
    {"simpx1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpx1},
    {"deleteq",                 too_few_2,      CC_deleteq,    wrong_no_2},
    {"qqe_simplqequal",         too_few_2,      CC_qqe_simplqequal,wrong_no_2},
    {"rl_b2atl",                too_few_2,      CC_rl_b2atl,   wrong_no_2},
    {"ev_max#",                 too_few_2,      CC_ev_maxC,    wrong_no_2},
    {"expvec2a1",               too_few_2,      CC_expvec2a1,  wrong_no_2},
    {"xreduce1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreduce1},
    {NULL, (one_args *)"u48", (two_args *)"18518 8906151 7498095", 0}
};

/* end of generated code */
