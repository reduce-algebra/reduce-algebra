
/* $destdir\u29.c        Machine generated C code */

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


/* Code for makecoeffpairshom */

static Lisp_Object MS_CDECL CC_makecoeffpairshom(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v81, v82, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairshom");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makecoeffpairshom");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-11] = v3;
    stack[-12] = v2;
    stack[-13] = v1;
    stack[-14] = v0;
/* end of prologue */
    v80 = stack[-12];
    if (v80 == nil) goto v84;
    v80 = stack[-13];
    v80 = qcar(v80);
    stack[-15] = v80;
    goto v85;

v85:
    stack[0] = stack[-11];
    v80 = stack[-14];
    v81 = qcar(v80);
    v80 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v80 = (*qfn2(fn))(qenv(fn), v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    fn = elt(env, 4); /* tayexp!-times2 */
    v80 = (*qfn2(fn))(qenv(fn), stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    fn = elt(env, 5); /* tayexp!-minusp */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    if (v80 == nil) goto v87;
    v80 = qvalue(elt(env, 2)); /* nil */
    { popv(17); return onevalue(v80); }

v87:
    v80 = stack[-14];
    v83 = qcdr(v80);
    v80 = stack[-13];
    v82 = qcdr(v80);
    v80 = stack[-12];
    v81 = qcdr(v80);
    v80 = stack[-11];
    v80 = CC_makecoeffpairshom(env, 4, v83, v82, v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    stack[-7] = v80;
    v80 = stack[-7];
    if (v80 == nil) goto v88;
    v80 = stack[-7];
    v80 = qcar(v80);
    stack[-3] = v80;
    stack[-2] = stack[-15];
    v80 = stack[-3];
    stack[-1] = qcar(v80);
    v80 = stack[-13];
    stack[0] = qcar(v80);
    v80 = stack[-12];
    v81 = qcar(v80);
    v80 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v80 = (*qfn2(fn))(qenv(fn), v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v81 = (*qfn2(fn))(qenv(fn), stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = stack[-3];
    v80 = qcdr(v80);
    v80 = cons(v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = acons(stack[-2], stack[-1], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    stack[-5] = v80;
    stack[-6] = v80;
    goto v89;

v89:
    v80 = stack[-7];
    v80 = qcdr(v80);
    stack[-7] = v80;
    v80 = stack[-7];
    if (v80 == nil) goto v90;
    stack[-4] = stack[-5];
    v80 = stack[-7];
    v80 = qcar(v80);
    stack[-3] = v80;
    stack[-2] = stack[-15];
    v80 = stack[-3];
    stack[-1] = qcar(v80);
    v80 = stack[-13];
    stack[0] = qcar(v80);
    v80 = stack[-12];
    v81 = qcar(v80);
    v80 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v80 = (*qfn2(fn))(qenv(fn), v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v81 = (*qfn2(fn))(qenv(fn), stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = stack[-3];
    v80 = qcdr(v80);
    v80 = cons(v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = acons(stack[-2], stack[-1], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = Lrplacd(nil, stack[-4], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = stack[-5];
    v80 = qcdr(v80);
    stack[-5] = v80;
    goto v89;

v90:
    v80 = stack[-6];
    goto v91;

v91:
    stack[-10] = v80;
    v80 = stack[-10];
    fn = elt(env, 7); /* lastpair */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    stack[-9] = v80;
    v81 = stack[-15];
    v80 = stack[-11];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v80 = (*qfn2(fn))(qenv(fn), v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    stack[-15] = v80;
    v80 = stack[-9];
    if (!consp(v80)) goto v85;
    else goto v92;

v92:
    stack[0] = stack[-11];
    v80 = stack[-14];
    v81 = qcar(v80);
    v80 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v80 = (*qfn2(fn))(qenv(fn), v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    fn = elt(env, 4); /* tayexp!-times2 */
    v80 = (*qfn2(fn))(qenv(fn), stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    fn = elt(env, 5); /* tayexp!-minusp */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    if (!(v80 == nil)) { Lisp_Object res = stack[-10]; popv(17); return onevalue(res); }
    stack[-8] = stack[-9];
    v80 = stack[-14];
    v83 = qcdr(v80);
    v80 = stack[-13];
    v82 = qcdr(v80);
    v80 = stack[-12];
    v81 = qcdr(v80);
    v80 = stack[-11];
    v80 = CC_makecoeffpairshom(env, 4, v83, v82, v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    stack[-7] = v80;
    v80 = stack[-7];
    if (v80 == nil) goto v93;
    v80 = stack[-7];
    v80 = qcar(v80);
    stack[-3] = v80;
    stack[-2] = stack[-15];
    v80 = stack[-3];
    stack[-1] = qcar(v80);
    v80 = stack[-13];
    stack[0] = qcar(v80);
    v80 = stack[-12];
    v81 = qcar(v80);
    v80 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v80 = (*qfn2(fn))(qenv(fn), v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v81 = (*qfn2(fn))(qenv(fn), stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = stack[-3];
    v80 = qcdr(v80);
    v80 = cons(v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = acons(stack[-2], stack[-1], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    stack[-5] = v80;
    stack[-6] = v80;
    goto v94;

v94:
    v80 = stack[-7];
    v80 = qcdr(v80);
    stack[-7] = v80;
    v80 = stack[-7];
    if (v80 == nil) goto v95;
    stack[-4] = stack[-5];
    v80 = stack[-7];
    v80 = qcar(v80);
    stack[-3] = v80;
    stack[-2] = stack[-15];
    v80 = stack[-3];
    stack[-1] = qcar(v80);
    v80 = stack[-13];
    stack[0] = qcar(v80);
    v80 = stack[-12];
    v81 = qcar(v80);
    v80 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v80 = (*qfn2(fn))(qenv(fn), v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v81 = (*qfn2(fn))(qenv(fn), stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = stack[-3];
    v80 = qcdr(v80);
    v80 = cons(v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = acons(stack[-2], stack[-1], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = Lrplacd(nil, stack[-4], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = stack[-5];
    v80 = qcdr(v80);
    stack[-5] = v80;
    goto v94;

v95:
    v80 = stack[-6];
    goto v96;

v96:
    v80 = Lrplacd(nil, stack[-8], v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    v80 = stack[-9];
    fn = elt(env, 7); /* lastpair */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    stack[-9] = v80;
    v81 = stack[-15];
    v80 = stack[-11];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v80 = (*qfn2(fn))(qenv(fn), v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-16];
    stack[-15] = v80;
    goto v92;

v93:
    v80 = qvalue(elt(env, 2)); /* nil */
    goto v96;

v88:
    v80 = qvalue(elt(env, 2)); /* nil */
    goto v91;

v84:
    v80 = elt(env, 1); /* ((nil)) */
    { popv(17); return onevalue(v80); }
/* error exit handlers */
v86:
    popv(17);
    return nil;
}



/* Code for ithlistelem */

static Lisp_Object CC_ithlistelem(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ithlistelem");
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
    v101 = stack[-1];
    if (v101 == nil) goto v103;
    v101 = stack[-1];
    v102 = qcar(v101);
    v101 = stack[0];
    fn = elt(env, 1); /* pnth */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    stack[-2] = qcar(v101);
    v101 = stack[-1];
    v102 = qcdr(v101);
    v101 = stack[0];
    v101 = CC_ithlistelem(env, v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v104;
    {
        Lisp_Object v78 = stack[-2];
        popv(4);
        return cons(v78, v101);
    }

v103:
    v101 = nil;
    { popv(4); return onevalue(v101); }
/* error exit handlers */
v104:
    popv(4);
    return nil;
}



/* Code for testpr */

static Lisp_Object MS_CDECL CC_testpr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v55, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "testpr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testpr");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v3;
    stack[-6] = v2;
    stack[0] = v1;
    v128 = v0;
/* end of prologue */
    stack[-3] = nil;
    v55 = qvalue(elt(env, 1)); /* jsi */
    stack[-2] = v55;
    stack[-1] = qvalue(elt(env, 2)); /* codmat */
    v55 = qvalue(elt(env, 3)); /* maxvar */
    v128 = plus2(v55, v128);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-8];
    v55 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    v128 = (Lisp_Object)65; /* 4 */
    v128 = *(Lisp_Object *)((char *)v55 + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    stack[-7] = v128;
    stack[-1] = qvalue(elt(env, 2)); /* codmat */
    v55 = qvalue(elt(env, 3)); /* maxvar */
    v128 = stack[0];
    v128 = plus2(v55, v128);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-8];
    v55 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    v128 = (Lisp_Object)65; /* 4 */
    v128 = *(Lisp_Object *)((char *)v55 + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    stack[-4] = v128;
    goto v74;

v74:
    v128 = stack[-2];
    if (v128 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v128 = stack[-7];
    if (v128 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v128 = stack[-2];
    v55 = qcar(v128);
    stack[-1] = v55;
    v128 = stack[-7];
    v128 = qcar(v128);
    v128 = qcar(v128);
    v56 = v128;
    if (equal(v55, v128)) goto v130;
    v128 = stack[-1];
    v55 = v56;
    v128 = (Lisp_Object)greaterp2(v128, v55);
    nil = C_nil;
    if (exception_pending()) goto v129;
    v128 = v128 ? lisp_true : nil;
    env = stack[-8];
    if (v128 == nil) goto v131;
    v128 = stack[-7];
    v128 = qcdr(v128);
    stack[-7] = v128;
    goto v74;

v131:
    v128 = stack[-2];
    v128 = qcdr(v128);
    stack[-2] = v128;
    goto v74;

v130:
    v55 = stack[-1];
    v128 = stack[-4];
    fn = elt(env, 5); /* pnthxzz */
    v128 = (*qfn2(fn))(qenv(fn), v55, v128);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-8];
    stack[-4] = v128;
    v128 = stack[-7];
    v128 = qcar(v128);
    v128 = qcdr(v128);
    v55 = qcar(v128);
    v128 = stack[-5];
    fn = elt(env, 6); /* dm!-times */
    stack[0] = (*qfn2(fn))(qenv(fn), v55, v128);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-8];
    v128 = stack[-4];
    v128 = qcar(v128);
    v128 = qcdr(v128);
    v55 = qcar(v128);
    v128 = stack[-6];
    fn = elt(env, 6); /* dm!-times */
    v128 = (*qfn2(fn))(qenv(fn), v55, v128);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-8];
    fn = elt(env, 7); /* dm!-difference */
    v128 = (*qfn2(fn))(qenv(fn), stack[0], v128);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-8];
    fn = elt(env, 8); /* zeropp */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-8];
    if (v128 == nil) goto v65;
    v55 = stack[-1];
    v128 = stack[-3];
    v128 = cons(v55, v128);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-8];
    stack[-3] = v128;
    goto v65;

v65:
    v128 = stack[-2];
    v128 = qcdr(v128);
    stack[-2] = v128;
    v128 = stack[-7];
    v128 = qcdr(v128);
    stack[-7] = v128;
    goto v74;
/* error exit handlers */
v129:
    popv(9);
    return nil;
}



/* Code for dipcondense */

static Lisp_Object CC_dipcondense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcondense");
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
    v118 = qvalue(elt(env, 1)); /* dipevlist!* */
    stack[-3] = v118;
    goto v110;

v110:
    v118 = stack[-2];
    if (v118 == nil) goto v136;
    v118 = stack[-2];
    v118 = qcar(v118);
    stack[-1] = v118;
    goto v137;

v137:
    v118 = stack[-3];
    v118 = qcdr(v118);
    if (v118 == nil) goto v138;
    v118 = stack[-2];
    v119 = qcar(v118);
    v118 = stack[-3];
    v118 = qcdr(v118);
    v118 = qcar(v118);
    fn = elt(env, 3); /* evcompless!? */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    if (v118 == nil) goto v138;
    v118 = stack[-3];
    v118 = qcdr(v118);
    stack[-3] = v118;
    goto v137;

v138:
    v118 = stack[-3];
    v118 = qcdr(v118);
    if (v118 == nil) goto v140;
    v119 = stack[-1];
    v118 = stack[-3];
    v118 = qcdr(v118);
    v118 = qcar(v118);
    if (!(equal(v119, v118))) goto v140;
    v119 = stack[-2];
    v118 = stack[-3];
    v118 = qcdr(v118);
    v118 = qcar(v118);
    fn = elt(env, 4); /* setcar */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    goto v59;

v59:
    v118 = stack[-2];
    v118 = qcdr(v118);
    v118 = qcdr(v118);
    stack[-2] = v118;
    goto v110;

v140:
    stack[0] = stack[-3];
    v119 = stack[-1];
    v118 = stack[-3];
    v118 = qcdr(v118);
    v118 = cons(v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    fn = elt(env, 5); /* setcdr */
    v118 = (*qfn2(fn))(qenv(fn), stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    goto v59;

v136:
    v118 = nil;
    { popv(5); return onevalue(v118); }
/* error exit handlers */
v139:
    popv(5);
    return nil;
}



/* Code for size_of_matrix */

static Lisp_Object CC_size_of_matrix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v143;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for size_of_matrix");
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
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v142 = stack[0];
    v142 = Llength(nil, v142);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v142 = plus2(stack[-1], v142);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    stack[-1] = v142;
    v142 = stack[0];
    v142 = qcdr(v142);
    v142 = qcar(v142);
    v142 = Llength(nil, v142);
    nil = C_nil;
    if (exception_pending()) goto v76;
    v143 = stack[-1];
    popv(3);
    return list2(v143, v142);
/* error exit handlers */
v76:
    popv(3);
    return nil;
}



/* Code for f2dip1 */

static Lisp_Object MS_CDECL CC_f2dip1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v150, v151, v139, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "f2dip1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v65 = stack[-2];
    if (v65 == nil) goto v103;
    v65 = stack[-2];
    if (!consp(v65)) goto v41;
    v65 = stack[-2];
    v65 = qcar(v65);
    v65 = (consp(v65) ? nil : lisp_true);
    goto v6;

v6:
    if (v65 == nil) goto v153;
    v65 = stack[0];
    v65 = (is_number(v65) ? lisp_true : nil);
    if (!(v65 == nil)) goto v79;
    v65 = stack[0];
    fn = elt(env, 3); /* f2dip11 */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    goto v79;

v79:
    v65 = stack[-2];
    fn = elt(env, 4); /* bcfd */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    fn = elt(env, 5); /* bcprod */
    v65 = (*qfn2(fn))(qenv(fn), stack[0], v65);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    v150 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v111 = stack[-1];
        popv(5);
        return list2star(v111, v65, v150);
    }

v153:
    v65 = stack[-2];
    v65 = qcar(v65);
    v65 = qcar(v65);
    v152 = qcar(v65);
    v65 = stack[-2];
    v65 = qcar(v65);
    v65 = qcar(v65);
    v139 = qcdr(v65);
    v65 = stack[-2];
    v65 = qcar(v65);
    v151 = qcdr(v65);
    v150 = stack[-1];
    v65 = stack[0];
    fn = elt(env, 6); /* f2dip2 */
    stack[-3] = (*qfnn(fn))(qenv(fn), 5, v152, v139, v151, v150, v65);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    v65 = stack[-2];
    v151 = qcdr(v65);
    v150 = stack[-1];
    v65 = stack[0];
    v65 = CC_f2dip1(env, 3, v151, v150, v65);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    {
        Lisp_Object v155 = stack[-3];
        popv(5);
        fn = elt(env, 7); /* dipsum */
        return (*qfn2(fn))(qenv(fn), v155, v65);
    }

v41:
    v65 = qvalue(elt(env, 2)); /* t */
    goto v6;

v103:
    v65 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v65); }
/* error exit handlers */
v154:
    popv(5);
    return nil;
}



/* Code for get!:const */

static Lisp_Object CC_getTconst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get:const");
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
    v155 = stack[-1];
    if (!consp(v155)) goto v110;
    v155 = qvalue(elt(env, 1)); /* nil */
    goto v136;

v136:
    if (v155 == nil) goto v118;
    v158 = stack[-1];
    v155 = elt(env, 2); /* save!:c */
    v155 = get(v158, v155);
    env = stack[-2];
    stack[-1] = v155;
    v155 = stack[-1];
    if (v155 == nil) goto v89;
    v155 = stack[-1];
    v158 = qcar(v155);
    v155 = stack[0];
    v155 = (Lisp_Object)lessp2(v158, v155);
    nil = C_nil;
    if (exception_pending()) goto v70;
    v155 = v155 ? lisp_true : nil;
    env = stack[-2];
    goto v91;

v91:
    if (v155 == nil) goto v159;
    v155 = elt(env, 4); /* not_found */
    { popv(3); return onevalue(v155); }

v159:
    v155 = stack[-1];
    v158 = qcar(v155);
    v155 = stack[0];
    if (equal(v158, v155)) goto v72;
    v155 = stack[-1];
    v158 = qcdr(v155);
    v155 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v158, v155);
    }

v72:
    v155 = stack[-1];
    v155 = qcdr(v155);
    { popv(3); return onevalue(v155); }

v89:
    v155 = qvalue(elt(env, 3)); /* t */
    goto v91;

v118:
    stack[0] = (Lisp_Object)1; /* 0 */
    v158 = elt(env, 5); /* "Invalid argument to" */
    v155 = elt(env, 0); /* get!:const */
    v155 = list2(v158, v155);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    {
        Lisp_Object v71 = stack[0];
        popv(3);
        fn = elt(env, 7); /* error */
        return (*qfn2(fn))(qenv(fn), v71, v155);
    }

v110:
    v155 = stack[0];
    v155 = integerp(v155);
    if (v155 == nil) goto v41;
    v158 = stack[0];
    v155 = (Lisp_Object)1; /* 0 */
    v155 = (Lisp_Object)greaterp2(v158, v155);
    nil = C_nil;
    if (exception_pending()) goto v70;
    v155 = v155 ? lisp_true : nil;
    env = stack[-2];
    goto v136;

v41:
    v155 = qvalue(elt(env, 1)); /* nil */
    goto v136;
/* error exit handlers */
v70:
    popv(3);
    return nil;
}



/* Code for r2findindex1 */

static Lisp_Object MS_CDECL CC_r2findindex1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v104, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "r2findindex1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2findindex1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v104 = v2;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v103:
    v135 = stack[0];
    if (v135 == nil) goto v110;
    v78 = stack[-1];
    v135 = stack[0];
    v135 = qcar(v135);
    if (equal(v78, v135)) { popv(3); return onevalue(v104); }
    v135 = stack[0];
    v135 = qcdr(v135);
    stack[0] = v135;
    v135 = v104;
    v135 = add1(v135);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v104 = v135;
    goto v103;

v110:
    v135 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v135 == nil)) goto v9;
    v135 = elt(env, 2); /* "index not found" */
    fn = elt(env, 3); /* lprie */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    goto v9;

v9:
    v135 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    v135 = nil;
    { popv(3); return onevalue(v135); }
/* error exit handlers */
v59:
    popv(3);
    return nil;
}



/* Code for list!-evaluate */

static Lisp_Object MS_CDECL CC_listKevaluate(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v72, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "list-evaluate");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list-evaluate");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v2;
    stack[-4] = v1;
    v164 = v0;
/* end of prologue */
    stack[-5] = v164;
    v164 = stack[-5];
    if (v164 == nil) goto v6;
    v164 = stack[-5];
    v164 = qcar(v164);
    v73 = v164;
    v72 = stack[-4];
    v164 = stack[-3];
    fn = elt(env, 2); /* evaluate */
    v164 = (*qfnn(fn))(qenv(fn), 3, v73, v72, v164);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-6];
    v164 = ncons(v164);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-6];
    stack[-1] = v164;
    stack[-2] = v164;
    goto v110;

v110:
    v164 = stack[-5];
    v164 = qcdr(v164);
    stack[-5] = v164;
    v164 = stack[-5];
    if (v164 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v164 = stack[-5];
    v164 = qcar(v164);
    v73 = v164;
    v72 = stack[-4];
    v164 = stack[-3];
    fn = elt(env, 2); /* evaluate */
    v164 = (*qfnn(fn))(qenv(fn), 3, v73, v72, v164);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-6];
    v164 = ncons(v164);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-6];
    v164 = Lrplacd(nil, stack[0], v164);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-6];
    v164 = stack[-1];
    v164 = qcdr(v164);
    stack[-1] = v164;
    goto v110;

v6:
    v164 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v164); }
/* error exit handlers */
v140:
    popv(7);
    return nil;
}



/* Code for getupper */

static Lisp_Object CC_getupper(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v149;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getupper");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v107 = v0;
/* end of prologue */
    v149 = qvalue(elt(env, 1)); /* metricu!* */
    v107 = Latsoc(nil, v107, v149);
    v107 = qcdr(v107);
    return onevalue(v107);
}



/* Code for z!-roads */

static Lisp_Object CC_zKroads(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v132, v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for z-roads");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v133 = v0;
/* end of prologue */
    v132 = (Lisp_Object)1; /* 0 */
    v166 = v133;
    v166 = qcar(v166);
    v166 = qcar(v166);
    v166 = qcdr(v166);
    if (v132 == v166) goto v163;
    v132 = (Lisp_Object)1; /* 0 */
    v166 = v133;
    v166 = qcar(v166);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    v166 = qcdr(v166);
    if (v132 == v166) goto v138;
    v132 = (Lisp_Object)1; /* 0 */
    v166 = v133;
    v166 = qcar(v166);
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    v166 = qcdr(v166);
    if (v132 == v166) goto v102;
    v166 = qvalue(elt(env, 1)); /* nil */
    goto v3;

v3:
    v132 = v166;
    v166 = v132;
    if (v166 == nil) goto v74;
    v166 = v132;
    v166 = qcar(v166);
    v132 = v133;
    v132 = qcdr(v132);
    return cons(v166, v132);

v74:
    v166 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v166);

v102:
    v166 = v133;
    v166 = qcar(v166);
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    goto v3;

v138:
    v166 = v133;
    v166 = qcar(v166);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    goto v3;

v163:
    v166 = v133;
    v166 = qcar(v166);
    v166 = qcar(v166);
    goto v3;
}



/* Code for split_cov_cont_ids */

static Lisp_Object CC_split_cov_cont_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v75, v164;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_cov_cont_ids");
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
    stack[0] = nil;
    goto v136;

v136:
    v157 = stack[-1];
    if (v157 == nil) goto v168;
    v157 = stack[-1];
    v157 = qcar(v157);
    v164 = v157;
    v75 = v164;
    v157 = elt(env, 2); /* minus */
    if (!consp(v75)) goto v165;
    v75 = qcar(v75);
    if (!(v75 == v157)) goto v165;
    v157 = v164;
    v157 = qcdr(v157);
    v75 = qcar(v157);
    v157 = stack[-2];
    v157 = cons(v75, v157);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[-2] = v157;
    goto v138;

v138:
    v157 = stack[-1];
    v157 = qcdr(v157);
    stack[-1] = v157;
    goto v136;

v165:
    v75 = v164;
    v157 = stack[0];
    v157 = cons(v75, v157);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[0] = v157;
    goto v138;

v168:
    v157 = stack[-2];
    v75 = Lnreverse(nil, v157);
    env = stack[-3];
    v157 = stack[0];
    v157 = Lnreverse(nil, v157);
    popv(4);
    return list2(v75, v157);
/* error exit handlers */
v169:
    popv(4);
    return nil;
}



/* Code for polynomwrite */

static Lisp_Object CC_polynomwrite(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomwrite");
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
    goto v117;

v117:
    v168 = stack[0];
    v168 = qcar(v168);
    if (v168 == nil) goto v136;
    v168 = stack[0];
    v125 = qcar(v168);
    v168 = (Lisp_Object)1; /* 0 */
    v125 = *(Lisp_Object *)((char *)v125 + (CELL-TAG_VECTOR) + ((int32_t)v168/(16/CELL)));
    v168 = (Lisp_Object)1; /* 0 */
    if (v125 == v168) goto v127;
    v168 = stack[0];
    v168 = qcar(v168);
    fn = elt(env, 1); /* monomwrite */
    v125 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v168 = stack[-1];
    v168 = cons(v125, v168);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    stack[-1] = v168;
    v168 = stack[0];
    v168 = qcdr(v168);
    stack[0] = v168;
    goto v117;

v127:
    v125 = stack[-1];
    v168 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v125, v168);
    }

v136:
    v168 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v168);
    }
/* error exit handlers */
v124:
    popv(3);
    return nil;
}



/* Code for pasf_subfof1 */

static Lisp_Object MS_CDECL CC_pasf_subfof1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v178;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_subfof1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_subfof1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v45 = stack[-3];
    v45 = Lconsp(nil, v45);
    env = stack[-5];
    if (v45 == nil) goto v70;
    v45 = stack[-3];
    v45 = qcar(v45);
    v45 = Lconsp(nil, v45);
    env = stack[-5];
    if (v45 == nil) goto v70;
    v45 = stack[-3];
    v45 = qcar(v45);
    v178 = qcar(v45);
    v45 = elt(env, 1); /* (cong ncong) */
    v45 = Lmemq(nil, v178, v45);
    if (v45 == nil) goto v70;
    v178 = stack[-3];
    v45 = elt(env, 2); /* true */
    if (v178 == v45) goto v46;
    v178 = stack[-3];
    v45 = elt(env, 4); /* false */
    v45 = (v178 == v45 ? lisp_true : nil);
    goto v60;

v60:
    if (v45 == nil) goto v59;
    v45 = stack[-3];
    stack[-4] = v45;
    goto v120;

v120:
    v45 = stack[-3];
    v45 = qcar(v45);
    stack[0] = qcdr(v45);
    v178 = stack[-2];
    v45 = stack[-1];
    v45 = cons(v178, v45);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-5];
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-5];
    fn = elt(env, 5); /* subf */
    v45 = (*qfn2(fn))(qenv(fn), stack[0], v45);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-5];
    v45 = qcar(v45);
    v45 = cons(stack[-4], v45);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-5];
    stack[-4] = v45;
    goto v180;

v180:
    v45 = stack[-3];
    v45 = qcdr(v45);
    stack[0] = qcar(v45);
    v178 = stack[-2];
    v45 = stack[-1];
    v45 = cons(v178, v45);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-5];
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-5];
    fn = elt(env, 5); /* subf */
    v45 = (*qfn2(fn))(qenv(fn), stack[0], v45);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-5];
    stack[0] = qcar(v45);
    v45 = stack[-3];
    v45 = qcdr(v45);
    v45 = qcdr(v45);
    stack[-3] = qcar(v45);
    v178 = stack[-2];
    v45 = stack[-1];
    v45 = cons(v178, v45);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-5];
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-5];
    fn = elt(env, 5); /* subf */
    v45 = (*qfn2(fn))(qenv(fn), stack[-3], v45);
    nil = C_nil;
    if (exception_pending()) goto v179;
    v45 = qcar(v45);
    {
        Lisp_Object v181 = stack[-4];
        Lisp_Object v182 = stack[0];
        popv(6);
        return list3(v181, v182, v45);
    }

v59:
    v45 = stack[-3];
    v45 = qcar(v45);
    v45 = Lconsp(nil, v45);
    env = stack[-5];
    if (v45 == nil) goto v67;
    v45 = stack[-3];
    v45 = qcar(v45);
    v45 = qcar(v45);
    stack[-4] = v45;
    goto v120;

v67:
    v45 = stack[-3];
    v45 = qcar(v45);
    stack[-4] = v45;
    goto v120;

v46:
    v45 = qvalue(elt(env, 3)); /* t */
    goto v60;

v70:
    v178 = stack[-3];
    v45 = elt(env, 2); /* true */
    if (v178 == v45) goto v183;
    v178 = stack[-3];
    v45 = elt(env, 4); /* false */
    v45 = (v178 == v45 ? lisp_true : nil);
    goto v158;

v158:
    if (v45 == nil) goto v111;
    v45 = stack[-3];
    goto v69;

v69:
    stack[-4] = v45;
    goto v180;

v111:
    v45 = stack[-3];
    v45 = qcar(v45);
    v45 = Lconsp(nil, v45);
    env = stack[-5];
    if (v45 == nil) goto v184;
    v45 = stack[-3];
    v45 = qcar(v45);
    v45 = qcar(v45);
    goto v69;

v184:
    v45 = stack[-3];
    v45 = qcar(v45);
    goto v69;

v183:
    v45 = qvalue(elt(env, 3)); /* t */
    goto v158;
/* error exit handlers */
v179:
    popv(6);
    return nil;
}



/* Code for listrd */

static Lisp_Object MS_CDECL CC_listrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v119, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "listrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listrd");
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
    v119 = qvalue(elt(env, 1)); /* atts */
    v118 = elt(env, 2); /* (o r d e r) */
    fn = elt(env, 11); /* search_att */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    stack[-1] = v118;
    v118 = elt(env, 3); /* (t y p e != l i s t !$) */
    qvalue(elt(env, 1)) = v118; /* atts */
    stack[0] = elt(env, 4); /* list */
    fn = elt(env, 12); /* stats_getargs */
    v118 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v118 = cons(stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v119 = v118;
    stack[0] = v119;
    v145 = stack[-1];
    v119 = elt(env, 5); /* (l e x i c o g r a p h i c) */
    if (!(equal(v145, v119))) goto v87;
    v119 = elt(env, 6); /* sortlist */
    v145 = v118;
    v118 = elt(env, 7); /* lexog */
    v118 = list3(v119, v145, v118);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    goto v87;

v87:
    v145 = stack[-1];
    v119 = elt(env, 8); /* (n u m e r i c) */
    if (equal(v145, v119)) goto v161;
    v145 = elt(env, 6); /* sortlist */
    v119 = v118;
    v118 = elt(env, 10); /* pred */
    v118 = list3(v145, v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v151;
    goto v91;

v91:
    v119 = v118;
    if (!(v119 == nil)) { popv(3); return onevalue(v118); }
    v118 = stack[0];
    { popv(3); return onevalue(v118); }

v161:
    v145 = elt(env, 6); /* sortlist */
    v119 = v118;
    v118 = elt(env, 9); /* numer */
    v118 = list3(v145, v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v151;
    goto v91;
/* error exit handlers */
v151:
    popv(3);
    return nil;
}



/* Code for compl */

static Lisp_Object CC_compl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compl");
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
    v79 = nil;
    goto v103;

v103:
    v104 = stack[-1];
    if (v104 == nil) goto v110;
    v104 = stack[-1];
    v78 = qcar(v104);
    v104 = stack[0];
    v104 = Lmember(nil, v78, v104);
    if (v104 == nil) goto v143;
    v104 = stack[-1];
    v104 = qcdr(v104);
    stack[-1] = v104;
    goto v103;

v143:
    v104 = stack[-1];
    v104 = qcar(v104);
    v78 = v79;
    v104 = cons(v104, v78);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    v79 = v104;
    v104 = stack[-1];
    v104 = qcdr(v104);
    stack[-1] = v104;
    goto v103;

v110:
    v104 = v79;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v104);
    }
/* error exit handlers */
v61:
    popv(3);
    return nil;
}



/* Code for spcol_dim */

static Lisp_Object CC_spcol_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spcol_dim");
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
    v102 = qvalue(elt(env, 1)); /* !*fast_la */
    if (v102 == nil) goto v107;
    v102 = qvalue(elt(env, 2)); /* nil */
    goto v122;

v122:
    if (v102 == nil) goto v103;
    v102 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v102 == nil)) goto v99;
    v102 = elt(env, 4); /* "Error in spcol_dim: input should be a matrix." 
*/
    fn = elt(env, 5); /* lprie */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    goto v99;

v99:
    v102 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    goto v103;

v103:
    v102 = stack[0];
    fn = elt(env, 6); /* spmatlength */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v148;
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    v102 = qcar(v102);
    { popv(2); return onevalue(v102); }

v107:
    v102 = stack[0];
    fn = elt(env, 7); /* matrixp */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    v102 = (v102 == nil ? lisp_true : nil);
    goto v122;
/* error exit handlers */
v148:
    popv(2);
    return nil;
}



/* Code for dm!-gt */

static Lisp_Object CC_dmKgt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v148, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-gt");
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
    v148 = v1;
    v170 = v0;
/* end of prologue */
    fn = elt(env, 2); /* dm!-difference */
    v170 = (*qfn2(fn))(qenv(fn), v148, v170);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[0];
    v135 = v170;
    v170 = v135;
    if (!consp(v170)) goto v41;
    v170 = v135;
    v148 = qcar(v170);
    v170 = elt(env, 1); /* minusp */
    v170 = get(v148, v170);
    v148 = v135;
        popv(1);
        return Lapply1(nil, v170, v148);

v41:
    v170 = v135;
        popv(1);
        return Lminusp(nil, v170);
/* error exit handlers */
v104:
    popv(1);
    return nil;
}



/* Code for groebspolynom3 */

static Lisp_Object CC_groebspolynom3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebspolynom3");
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
    v167 = v1;
    v188 = v0;
/* end of prologue */
    fn = elt(env, 1); /* groebspolynom4 */
    v167 = (*qfn2(fn))(qenv(fn), v188, v167);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-1];
    stack[0] = v167;
    v167 = stack[0];
    fn = elt(env, 2); /* groebsavelterm */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v137;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v137:
    popv(2);
    return nil;
}



/* Code for mkexdf */

static Lisp_Object CC_mkexdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkexdf");
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
    v98 = v0;
/* end of prologue */
    v97 = elt(env, 1); /* d */
    v98 = list2(v97, v98);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-1];
    stack[0] = v98;
    fn = elt(env, 2); /* opmtch */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-1];
    v97 = v98;
    if (v98 == nil) goto v186;
    v98 = v97;
    {
        popv(2);
        fn = elt(env, 3); /* partitop */
        return (*qfn1(fn))(qenv(fn), v98);
    }

v186:
    v98 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v98);
    }
/* error exit handlers */
v85:
    popv(2);
    return nil;
}



/* Code for r2oaddspecies */

static Lisp_Object CC_r2oaddspecies(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v78;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2oaddspecies");
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
    v78 = stack[-1];
    v104 = stack[0];
    v104 = Lassoc(nil, v78, v104);
    if (!(v104 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v104 = elt(env, 1); /* "new species: " */
    v104 = Lprinc(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v104 = stack[-1];
    v104 = Lprinc(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v104 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v78 = stack[-1];
    v104 = (Lisp_Object)1; /* 0 */
    v104 = cons(v78, v104);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v59;
    {
        Lisp_Object v61 = stack[0];
        popv(3);
        return Lappend(nil, v61, v104);
    }
/* error exit handlers */
v59:
    popv(3);
    return nil;
}



/* Code for mkassign */

static Lisp_Object CC_mkassign(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v9, v189;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkassign");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v1;
    v9 = v0;
/* end of prologue */
    v189 = elt(env, 1); /* setq */
    return list3(v189, v9, v41);
}



/* Code for vunion */

static Lisp_Object CC_vunion(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v111;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vunion");
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
    v154 = stack[-2];
    if (v154 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v154 = stack[-2];
    v154 = qcar(v154);
    v111 = qcar(v154);
    v154 = stack[-1];
    v154 = Lassoc(nil, v111, v154);
    stack[-3] = v154;
    if (v154 == nil) goto v98;
    v154 = stack[-2];
    v154 = qcar(v154);
    v111 = qcdr(v154);
    v154 = stack[-3];
    v154 = qcdr(v154);
    v154 = (Lisp_Object)greaterp2(v111, v154);
    nil = C_nil;
    if (exception_pending()) goto v70;
    v154 = v154 ? lisp_true : nil;
    env = stack[-4];
    if (v154 == nil) goto v120;
    v154 = stack[-2];
    stack[0] = qcar(v154);
    v154 = stack[-2];
    stack[-2] = qcdr(v154);
    v111 = stack[-3];
    v154 = stack[-1];
    v154 = Ldelete(nil, v111, v154);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    v154 = CC_vunion(env, stack[-2], v154);
    nil = C_nil;
    if (exception_pending()) goto v70;
    {
        Lisp_Object v71 = stack[0];
        popv(5);
        return cons(v71, v154);
    }

v120:
    stack[0] = stack[-3];
    v154 = stack[-2];
    stack[-2] = qcdr(v154);
    v111 = stack[-3];
    v154 = stack[-1];
    v154 = Ldelete(nil, v111, v154);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    v154 = CC_vunion(env, stack[-2], v154);
    nil = C_nil;
    if (exception_pending()) goto v70;
    {
        Lisp_Object v191 = stack[0];
        popv(5);
        return cons(v191, v154);
    }

v98:
    v154 = stack[-2];
    stack[0] = qcar(v154);
    v154 = stack[-2];
    v111 = qcdr(v154);
    v154 = stack[-1];
    v154 = CC_vunion(env, v111, v154);
    nil = C_nil;
    if (exception_pending()) goto v70;
    {
        Lisp_Object v66 = stack[0];
        popv(5);
        return cons(v66, v154);
    }
/* error exit handlers */
v70:
    popv(5);
    return nil;
}



/* Code for subs2p */

static Lisp_Object MS_CDECL CC_subs2p(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v183, v195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subs2p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2p");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v158 = stack[-2];
    v158 = qcdr(v158);
    v158 = integerp(v158);
    if (v158 == nil) goto v149;
    v158 = stack[-2];
    v183 = qcdr(v158);
    v158 = stack[-1];
    v158 = Ldivide(nil, v183, v158);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    stack[-1] = v158;
    v183 = qcar(v158);
    v158 = (Lisp_Object)1; /* 0 */
    v158 = (v183 == v158 ? lisp_true : nil);
    goto v107;

v107:
    if (v158 == nil) goto v125;
    v183 = stack[-2];
    v158 = (Lisp_Object)17; /* 1 */
    v158 = cons(v183, v158);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v183 = ncons(v158);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v158 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v183, v158);

v125:
    v158 = stack[0];
    fn = elt(env, 2); /* simp */
    v183 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v158 = stack[-1];
    v158 = qcar(v158);
    fn = elt(env, 3); /* exptsq */
    v158 = (*qfn2(fn))(qenv(fn), v183, v158);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    stack[0] = v158;
    v158 = stack[-1];
    v183 = qcdr(v158);
    v158 = (Lisp_Object)1; /* 0 */
    if (v183 == v158) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v158 = stack[-2];
    v195 = qcar(v158);
    v158 = stack[-1];
    v183 = qcdr(v158);
    v158 = (Lisp_Object)17; /* 1 */
    v158 = acons(v195, v183, v158);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v183 = ncons(v158);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v158 = (Lisp_Object)17; /* 1 */
    v183 = cons(v183, v158);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v158 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v183, v158);
    }

v149:
    v158 = qvalue(elt(env, 1)); /* t */
    goto v107;
/* error exit handlers */
v66:
    popv(4);
    return nil;
}



/* Code for mod_eval_uni_poly */

static Lisp_Object CC_mod_eval_uni_poly(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v199, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod_eval_uni_poly");
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
    v198 = stack[-2];
    if (!consp(v198)) goto v117;
    v198 = stack[-2];
    v198 = qcar(v198);
    v198 = qcdr(v198);
    fn = elt(env, 3); /* mod!# */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v200 = v198;
    v198 = stack[-2];
    v198 = qcar(v198);
    v198 = qcar(v198);
    v198 = qcdr(v198);
    v199 = v198;
    v198 = stack[-2];
    v198 = qcdr(v198);
    stack[-2] = v198;
    goto v85;

v85:
    v198 = stack[-2];
    if (!consp(v198)) goto v192;
    stack[-3] = v200;
    stack[0] = stack[-1];
    v198 = stack[-2];
    v198 = qcar(v198);
    v198 = qcar(v198);
    v198 = qcdr(v198);
    v198 = difference2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    fn = elt(env, 4); /* general!-modular!-expt */
    v198 = (*qfn2(fn))(qenv(fn), stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v199 = times2(stack[-3], v198);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v198 = qvalue(elt(env, 2)); /* current!-modulus */
    stack[0] = Cremainder(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v198 = stack[-2];
    v198 = qcar(v198);
    v198 = qcdr(v198);
    fn = elt(env, 3); /* mod!# */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    fn = elt(env, 5); /* general!-modular!-plus */
    v198 = (*qfn2(fn))(qenv(fn), stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v200 = v198;
    v198 = stack[-2];
    v198 = qcar(v198);
    v198 = qcar(v198);
    v198 = qcdr(v198);
    v199 = v198;
    v198 = stack[-2];
    v198 = qcdr(v198);
    stack[-2] = v198;
    goto v85;

v192:
    stack[0] = v200;
    v198 = stack[-1];
    fn = elt(env, 4); /* general!-modular!-expt */
    v198 = (*qfn2(fn))(qenv(fn), v198, v199);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v199 = times2(stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v198 = qvalue(elt(env, 2)); /* current!-modulus */
    v198 = Cremainder(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v200 = v198;
    v198 = stack[-2];
    if (v198 == nil) { popv(5); return onevalue(v200); }
    stack[0] = v200;
    v198 = stack[-2];
    fn = elt(env, 3); /* mod!# */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    fn = elt(env, 5); /* general!-modular!-plus */
    v198 = (*qfn2(fn))(qenv(fn), stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v200 = v198;
    { popv(5); return onevalue(v200); }

v117:
    v198 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* mod!# */
        return (*qfn1(fn))(qenv(fn), v198);
    }
/* error exit handlers */
v47:
    popv(5);
    return nil;
}



/* Code for preptayexp */

static Lisp_Object CC_preptayexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptayexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v0;
/* end of prologue */
    v149 = v6;
    if (!consp(v149)) return onevalue(v6);
    v149 = v6;
    {
        fn = elt(env, 1); /* rnprep!: */
        return (*qfn1(fn))(qenv(fn), v149);
    }
}



/* Code for domainvalchk */

static Lisp_Object CC_domainvalchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v190, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domainvalchk");
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
    v190 = qvalue(elt(env, 1)); /* dmode!* */
    v88 = elt(env, 0); /* domainvalchk */
    v88 = get(v190, v88);
    env = stack[-3];
    stack[-2] = v88;
    if (v88 == nil) goto v136;
    v197 = stack[-2];
    v190 = stack[-1];
    v88 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v197, v190, v88);

v136:
    v88 = stack[0];
    v88 = Lreverse(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-3];
    stack[0] = v88;
    goto v103;

v103:
    v88 = stack[0];
    if (v88 == nil) goto v148;
    v88 = stack[0];
    v88 = qcar(v88);
    v190 = qcdr(v88);
    v88 = (Lisp_Object)17; /* 1 */
    if (v190 == v88) goto v153;
    v88 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v88); }

v153:
    v88 = stack[0];
    v88 = qcar(v88);
    fn = elt(env, 3); /* mk!*sq */
    v190 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-3];
    v88 = stack[-2];
    v88 = cons(v190, v88);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-3];
    stack[-2] = v88;
    v88 = stack[0];
    v88 = qcdr(v88);
    stack[0] = v88;
    goto v103;

v148:
    v190 = stack[-1];
    v88 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* valuechk */
        return (*qfn2(fn))(qenv(fn), v190, v88);
    }
/* error exit handlers */
v201:
    popv(4);
    return nil;
}



/* Code for enter!-sorted */

static Lisp_Object CC_enterKsorted(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for enter-sorted");
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
    goto v103;

v103:
    v157 = stack[0];
    if (v157 == nil) goto v6;
    v157 = stack[-1];
    v75 = qcar(v157);
    v157 = stack[0];
    v157 = qcar(v157);
    v157 = qcar(v157);
    fn = elt(env, 1); /* taydegree!< */
    v157 = (*qfn2(fn))(qenv(fn), v75, v157);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    if (v157 == nil) goto v194;
    v75 = stack[-1];
    v157 = stack[0];
    v157 = cons(v75, v157);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    {
        Lisp_Object v169 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v169, v157);
    }

v194:
    v157 = stack[0];
    v75 = qcar(v157);
    v157 = stack[-2];
    v157 = cons(v75, v157);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    stack[-2] = v157;
    v157 = stack[0];
    v157 = qcdr(v157);
    stack[0] = v157;
    goto v103;

v6:
    stack[0] = stack[-2];
    v157 = stack[-1];
    v157 = ncons(v157);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    {
        Lisp_Object v88 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v88, v157);
    }
/* error exit handlers */
v159:
    popv(4);
    return nil;
}



/* Code for matrixom */

static Lisp_Object CC_matrixom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixom");
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
    v137 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 6); /* printout */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-1];
    v137 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 7); /* indent!* */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-1];
    v137 = elt(env, 3); /* "<OMS cd=""linalg1"" name=""matrix""/>" */
    fn = elt(env, 6); /* printout */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-1];
    v137 = stack[0];
    v137 = qcdr(v137);
    v137 = qcdr(v137);
    v137 = qcdr(v137);
    v137 = qcar(v137);
    fn = elt(env, 8); /* matrixrowom */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-1];
    v137 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 7); /* indent!* */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-1];
    v137 = elt(env, 5); /* "</OMA>" */
    fn = elt(env, 6); /* printout */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v137 = nil;
    { popv(2); return onevalue(v137); }
/* error exit handlers */
v187:
    popv(2);
    return nil;
}



/* Code for countof */

static Lisp_Object CC_countof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v60;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for countof");
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
    v60 = stack[-1];
    v61 = stack[0];
    if (equal(v60, v61)) goto v117;
    v61 = stack[0];
    if (!consp(v61)) goto v9;
    v60 = stack[-1];
    v61 = stack[0];
    v61 = qcar(v61);
    stack[-2] = CC_countof(env, v60, v61);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-3];
    v60 = stack[-1];
    v61 = stack[0];
    v61 = qcdr(v61);
    v61 = CC_countof(env, v60, v61);
    nil = C_nil;
    if (exception_pending()) goto v162;
    {
        Lisp_Object v87 = stack[-2];
        popv(4);
        return plus2(v87, v61);
    }

v9:
    v61 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v61); }

v117:
    v61 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v61); }
/* error exit handlers */
v162:
    popv(4);
    return nil;
}



/* Code for remdiff */

static Lisp_Object CC_remdiff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remdiff");
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
    stack[-1] = v0;
/* end of prologue */
    v111 = stack[-1];
    if (symbolp(v111)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v111 = stack[-1];
    fn = elt(env, 5); /* constp */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-5];
    if (!(v111 == nil)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v111 = stack[-1];
    v155 = qcar(v111);
    v111 = elt(env, 1); /* difference */
    if (v155 == v111) goto v141;
    v111 = stack[-1];
    stack[-4] = qcar(v111);
    v111 = stack[-1];
    v111 = qcdr(v111);
    stack[-3] = v111;
    v111 = stack[-3];
    if (v111 == nil) goto v197;
    v111 = stack[-3];
    v111 = qcar(v111);
    v111 = CC_remdiff(env, v111);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-5];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-5];
    stack[-1] = v111;
    stack[-2] = v111;
    goto v73;

v73:
    v111 = stack[-3];
    v111 = qcdr(v111);
    stack[-3] = v111;
    v111 = stack[-3];
    if (v111 == nil) goto v64;
    stack[0] = stack[-1];
    v111 = stack[-3];
    v111 = qcar(v111);
    v111 = CC_remdiff(env, v111);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-5];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-5];
    v111 = Lrplacd(nil, stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-5];
    v111 = stack[-1];
    v111 = qcdr(v111);
    stack[-1] = v111;
    goto v73;

v64:
    v111 = stack[-2];
    goto v124;

v124:
    {
        Lisp_Object v66 = stack[-4];
        popv(6);
        return cons(v66, v111);
    }

v197:
    v111 = qvalue(elt(env, 4)); /* nil */
    goto v124;

v141:
    stack[-3] = elt(env, 2); /* plus */
    v111 = stack[-1];
    v111 = qcdr(v111);
    v111 = qcar(v111);
    stack[-2] = CC_remdiff(env, v111);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-5];
    stack[0] = elt(env, 3); /* minus */
    v111 = stack[-1];
    v111 = qcdr(v111);
    v111 = qcdr(v111);
    v111 = qcar(v111);
    v111 = CC_remdiff(env, v111);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-5];
    v111 = list2(stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-5];
    v111 = list3(stack[-3], stack[-2], v111);
    nil = C_nil;
    if (exception_pending()) goto v191;
    { popv(6); return onevalue(v111); }
/* error exit handlers */
v191:
    popv(6);
    return nil;
}



/* Code for !:!:quotient */

static Lisp_Object CC_TTquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ::quotient");
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
    v135 = v1;
    v148 = v0;
/* end of prologue */
    stack[0] = v148;
    v148 = v135;
    v148 = integerp(v148);
    if (v148 == nil) goto v101;
    v148 = v135;
    fn = elt(env, 2); /* chkint!* */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-1];
    v135 = v148;
    if (!(!consp(v135))) goto v84;
    v135 = elt(env, 1); /* !:rd!: */
    v148 = cons(v135, v148);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-1];
    goto v84;

v84:
    {
        Lisp_Object v79 = stack[0];
        popv(2);
        fn = elt(env, 3); /* !:quotient */
        return (*qfn2(fn))(qenv(fn), v79, v148);
    }

v101:
    v148 = v135;
    goto v84;
/* error exit handlers */
v78:
    popv(2);
    return nil;
}



/* Code for mktails */

static Lisp_Object MS_CDECL CC_mktails(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v169, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktails");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mktails");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v169 = v2;
    stack[-2] = v1;
    v88 = v0;
/* end of prologue */
    stack[0] = nil;
    v159 = v88;
    if (v159 == nil) goto v189;
    v159 = v88;
    stack[-3] = v159;
    v159 = v169;
    stack[-1] = v159;
    goto v141;

v141:
    v159 = stack[-3];
    if (v159 == nil) goto v161;
    v159 = stack[-3];
    v88 = qcar(v159);
    v169 = stack[-2];
    v159 = stack[-1];
    fn = elt(env, 2); /* mktails1 */
    v159 = (*qfnn(fn))(qenv(fn), 3, v88, v169, v159);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v169 = v159;
    v159 = v169;
    v159 = qcdr(v159);
    stack[-1] = v159;
    v159 = v169;
    v169 = qcar(v159);
    v159 = stack[0];
    v159 = Lappend(nil, v169, v159);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    stack[0] = v159;
    v159 = stack[-3];
    v159 = qcdr(v159);
    stack[-3] = v159;
    goto v141;

v161:
    v169 = stack[0];
    v159 = stack[-1];
    popv(5);
    return cons(v169, v159);

v189:
    v159 = qvalue(elt(env, 1)); /* nil */
    popv(5);
    return cons(v159, v169);
/* error exit handlers */
v156:
    popv(5);
    return nil;
}



/* Code for mv!-compact2 */

static Lisp_Object CC_mvKcompact2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v75, v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-compact2");
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
    v75 = stack[-1];
    v157 = stack[0];
    fn = elt(env, 2); /* equiv!-coeffs */
    v157 = (*qfn2(fn))(qenv(fn), v75, v157);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[-2] = v157;
    v157 = stack[0];
    fn = elt(env, 3); /* mv!-domainlist */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v75 = stack[-2];
    fn = elt(env, 4); /* reduce */
    v157 = (*qfn2(fn))(qenv(fn), v75, v157);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v164 = v157;
    v75 = v164;
    v157 = stack[-2];
    if (equal(v75, v157)) goto v85;
    v75 = v164;
    v157 = stack[-2];
    fn = elt(env, 5); /* mv!-domainlist!-!- */
    v157 = (*qfn2(fn))(qenv(fn), v75, v157);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    fn = elt(env, 6); /* mv!-coeff!-replace */
    v75 = (*qfn2(fn))(qenv(fn), stack[0], v157);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v157 = stack[-1];
    {
        popv(4);
        fn = elt(env, 7); /* mv!-!+ */
        return (*qfn2(fn))(qenv(fn), v75, v157);
    }

v85:
    v157 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v157); }
/* error exit handlers */
v169:
    popv(4);
    return nil;
}



/* Code for msolve!-poly1 */

static Lisp_Object CC_msolveKpoly1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223, v224, v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-poly1");
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
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v223 = stack[-5];
    if (!consp(v223)) goto v9;
    v223 = stack[-5];
    v223 = qcar(v223);
    v223 = (consp(v223) ? nil : lisp_true);
    goto v41;

v41:
    if (!(v223 == nil)) goto v63;
    v223 = stack[-5];
    v223 = qcar(v223);
    v223 = qcar(v223);
    v224 = qcdr(v223);
    v223 = (Lisp_Object)17; /* 1 */
    if (!(v224 == v223)) goto v63;
    v223 = stack[-5];
    v223 = qcar(v223);
    v223 = qcdr(v223);
    fn = elt(env, 6); /* safe!-modrecip */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[0] = v223;
    v223 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v223; /* erfg!* */
    v223 = stack[0];
    if (v223 == nil) goto v63;
    v223 = stack[-5];
    v223 = qcdr(v223);
    fn = elt(env, 7); /* negf */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    fn = elt(env, 8); /* multf */
    v223 = (*qfn2(fn))(qenv(fn), stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    fn = elt(env, 9); /* moduntag */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[0] = v223;
    v223 = stack[0];
    if (v223 == nil) goto v134;
    v224 = stack[0];
    v223 = (Lisp_Object)1; /* 0 */
    v223 = (Lisp_Object)lessp2(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    v223 = v223 ? lisp_true : nil;
    env = stack[-7];
    if (!(v223 == nil)) goto v161;
    v224 = stack[0];
    v223 = qvalue(elt(env, 4)); /* current!-modulus */
    v223 = (Lisp_Object)greaterp2(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    v223 = v223 ? lisp_true : nil;
    env = stack[-7];
    if (!(v223 == nil)) goto v161;

v134:
    v223 = stack[0];
    v223 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[0] = v223;
    goto v136;

v136:
    v223 = stack[0];
    stack[-5] = v223;
    v223 = stack[-5];
    if (v223 == nil) goto v27;
    v223 = stack[-5];
    v223 = qcar(v223);
    stack[0] = stack[-4];
    fn = elt(env, 10); /* prepf */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = cons(stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[-2] = v223;
    stack[-3] = v223;
    goto v227;

v227:
    v223 = stack[-5];
    v223 = qcdr(v223);
    stack[-5] = v223;
    v223 = stack[-5];
    if (v223 == nil) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-2];
    v223 = stack[-5];
    v223 = qcar(v223);
    stack[0] = stack[-4];
    fn = elt(env, 10); /* prepf */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = cons(stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = Lrplacd(nil, stack[-1], v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = stack[-2];
    v223 = qcdr(v223);
    stack[-2] = v223;
    goto v227;

v27:
    v223 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v223); }

v161:
    v223 = stack[0];
    fn = elt(env, 11); /* general!-modular!-number */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[0] = v223;
    goto v134;

v63:
    v225 = stack[-5];
    v224 = stack[-4];
    v223 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 12); /* lowestdeg */
    v223 = (*qfnn(fn))(qenv(fn), 3, v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[-6] = v223;
    v224 = stack[-6];
    v223 = (Lisp_Object)1; /* 0 */
    v223 = (Lisp_Object)greaterp2(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    v223 = v223 ? lisp_true : nil;
    env = stack[-7];
    if (v223 == nil) goto v228;
    stack[0] = stack[-5];
    v225 = elt(env, 5); /* expt */
    v224 = stack[-4];
    v223 = stack[-6];
    v223 = list3(v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    fn = elt(env, 13); /* simp */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = qcar(v223);
    fn = elt(env, 14); /* quotf */
    v223 = (*qfn2(fn))(qenv(fn), stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[-5] = v223;
    goto v228;

v228:
    v223 = stack[-5];
    fn = elt(env, 9); /* moduntag */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    fn = elt(env, 15); /* general!-reduce!-mod!-p */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[-5] = v223;
    v223 = (Lisp_Object)17; /* 1 */
    stack[-3] = v223;
    goto v106;

v106:
    v223 = qvalue(elt(env, 4)); /* current!-modulus */
    v224 = sub1(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = stack[-3];
    v223 = difference2(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = Lminusp(nil, v223);
    env = stack[-7];
    if (v223 == nil) goto v229;
    v223 = qvalue(elt(env, 2)); /* nil */
    goto v230;

v230:
    stack[0] = v223;
    v224 = stack[-6];
    v223 = (Lisp_Object)1; /* 0 */
    v223 = (Lisp_Object)greaterp2(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    v223 = v223 ? lisp_true : nil;
    env = stack[-7];
    if (v223 == nil) goto v136;
    v223 = qvalue(elt(env, 2)); /* nil */
    v223 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = Lappend(nil, stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[0] = v223;
    goto v136;

v229:
    v225 = stack[-5];
    v224 = stack[-4];
    v223 = stack[-3];
    fn = elt(env, 16); /* general!-evaluate!-mod!-p */
    v223 = (*qfnn(fn))(qenv(fn), 3, v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    if (v223 == nil) goto v171;
    v223 = nil;
    goto v56;

v56:
    stack[-2] = v223;
    v223 = stack[-2];
    fn = elt(env, 17); /* lastpair */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[-1] = v223;
    v223 = stack[-3];
    v223 = add1(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[-3] = v223;
    v223 = stack[-1];
    if (!consp(v223)) goto v106;
    else goto v182;

v182:
    v223 = qvalue(elt(env, 4)); /* current!-modulus */
    v224 = sub1(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = stack[-3];
    v223 = difference2(v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = Lminusp(nil, v223);
    env = stack[-7];
    if (v223 == nil) goto v231;
    v223 = stack[-2];
    goto v230;

v231:
    stack[0] = stack[-1];
    v225 = stack[-5];
    v224 = stack[-4];
    v223 = stack[-3];
    fn = elt(env, 16); /* general!-evaluate!-mod!-p */
    v223 = (*qfnn(fn))(qenv(fn), 3, v225, v224, v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    if (v223 == nil) goto v232;
    v223 = nil;
    goto v233;

v233:
    v223 = Lrplacd(nil, stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    v223 = stack[-1];
    fn = elt(env, 17); /* lastpair */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[-1] = v223;
    v223 = stack[-3];
    v223 = add1(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    stack[-3] = v223;
    goto v182;

v232:
    v223 = stack[-3];
    v223 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    goto v233;

v171:
    v223 = stack[-3];
    v223 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-7];
    goto v56;

v9:
    v223 = qvalue(elt(env, 1)); /* t */
    goto v41;
/* error exit handlers */
v226:
    popv(8);
    return nil;
}



/* Code for reduce!-mod!-eigf */

static Lisp_Object CC_reduceKmodKeigf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-eigf");
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
    stack[-2] = v1;
    v60 = v0;
/* end of prologue */
    v46 = qvalue(elt(env, 1)); /* !*sub2 */
    stack[-3] = qvalue(elt(env, 1)); /* !*sub2 */
    qvalue(elt(env, 1)) = v46; /* !*sub2 */
    v46 = v60;
    v46 = qcar(v46);
    stack[-1] = qcar(v46);
    v46 = v60;
    v46 = qcdr(v46);
    v60 = qcar(v60);
    v60 = qcdr(v60);
    v60 = cons(v46, v60);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    fn = elt(env, 2); /* cancel */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    stack[0] = v60;
    v60 = stack[0];
    v60 = qcar(v60);
    fn = elt(env, 3); /* negf */
    v46 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = cons(v46, v60);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    v46 = cons(stack[-1], v60);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    v60 = stack[-2];
    fn = elt(env, 4); /* reduce!-eival!-powers */
    v60 = (*qfn2(fn))(qenv(fn), v46, v60);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    fn = elt(env, 5); /* subs2 */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*sub2 */
    { popv(5); return onevalue(v60); }
/* error exit handlers */
v194:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*sub2 */
    popv(5);
    return nil;
}



/* Code for cl_apply2ats1 */

static Lisp_Object MS_CDECL CC_cl_apply2ats1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v254, v255, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_apply2ats1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_apply2ats1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v2;
    stack[-5] = v1;
    stack[-1] = v0;
/* end of prologue */
    v254 = stack[-1];
    if (!consp(v254)) goto v110;
    v254 = stack[-1];
    v254 = qcar(v254);
    goto v136;

v136:
    v20 = v254;
    v255 = v20;
    v254 = elt(env, 1); /* true */
    if (v255 == v254) goto v99;
    v255 = v20;
    v254 = elt(env, 3); /* false */
    v254 = (v255 == v254 ? lisp_true : nil);
    goto v187;

v187:
    if (!(v254 == nil)) { Lisp_Object res = stack[-1]; popv(8); return onevalue(res); }
    v255 = v20;
    v254 = elt(env, 4); /* ex */
    if (v255 == v254) goto v162;
    v255 = v20;
    v254 = elt(env, 5); /* all */
    v254 = (v255 == v254 ? lisp_true : nil);
    goto v89;

v89:
    if (v254 == nil) goto v111;
    stack[-2] = v20;
    v254 = stack[-1];
    v254 = qcdr(v254);
    stack[0] = qcar(v254);
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v20 = qcar(v254);
    v255 = stack[-5];
    v254 = stack[-4];
    v254 = CC_cl_apply2ats1(env, 3, v20, v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    {
        Lisp_Object v257 = stack[-2];
        Lisp_Object v258 = stack[0];
        popv(8);
        return list3(v257, v258, v254);
    }

v111:
    v255 = v20;
    v254 = elt(env, 6); /* bex */
    if (v255 == v254) goto v69;
    v255 = v20;
    v254 = elt(env, 7); /* ball */
    v254 = (v255 == v254 ? lisp_true : nil);
    goto v68;

v68:
    if (v254 == nil) goto v259;
    stack[-3] = v20;
    v254 = stack[-1];
    v254 = qcdr(v254);
    stack[-2] = qcar(v254);
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v20 = qcar(v254);
    v255 = stack[-5];
    v254 = stack[-4];
    stack[0] = CC_cl_apply2ats1(env, 3, v20, v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-7];
    v254 = stack[-1];
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v254 = qcdr(v254);
    v20 = qcar(v254);
    v255 = stack[-5];
    v254 = stack[-4];
    v254 = CC_cl_apply2ats1(env, 3, v20, v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    {
        Lisp_Object v260 = stack[-3];
        Lisp_Object v261 = stack[-2];
        Lisp_Object v262 = stack[0];
        popv(8);
        return list4(v260, v261, v262, v254);
    }

v259:
    v255 = v20;
    v254 = elt(env, 8); /* or */
    if (v255 == v254) goto v45;
    v255 = v20;
    v254 = elt(env, 9); /* and */
    v254 = (v255 == v254 ? lisp_true : nil);
    goto v44;

v44:
    if (v254 == nil) goto v263;
    v254 = qvalue(elt(env, 2)); /* t */
    goto v264;

v264:
    if (v254 == nil) goto v8;
    v254 = qvalue(elt(env, 2)); /* t */
    goto v218;

v218:
    if (v254 == nil) goto v265;
    stack[-6] = v20;
    v254 = stack[-1];
    v254 = qcdr(v254);
    stack[-3] = v254;
    v254 = stack[-3];
    if (v254 == nil) goto v266;
    v254 = stack[-3];
    v254 = qcar(v254);
    v20 = v254;
    v255 = stack[-5];
    v254 = stack[-4];
    v254 = CC_cl_apply2ats1(env, 3, v20, v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-7];
    v254 = ncons(v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-7];
    stack[-1] = v254;
    stack[-2] = v254;
    goto v267;

v267:
    v254 = stack[-3];
    v254 = qcdr(v254);
    stack[-3] = v254;
    v254 = stack[-3];
    if (v254 == nil) goto v268;
    stack[0] = stack[-1];
    v254 = stack[-3];
    v254 = qcar(v254);
    v20 = v254;
    v255 = stack[-5];
    v254 = stack[-4];
    v254 = CC_cl_apply2ats1(env, 3, v20, v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-7];
    v254 = ncons(v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-7];
    v254 = Lrplacd(nil, stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-7];
    v254 = stack[-1];
    v254 = qcdr(v254);
    stack[-1] = v254;
    goto v267;

v268:
    v254 = stack[-2];
    goto v269;

v269:
    {
        Lisp_Object v4 = stack[-6];
        popv(8);
        return cons(v4, v254);
    }

v266:
    v254 = qvalue(elt(env, 14)); /* nil */
    goto v269;

v265:
    stack[0] = stack[-5];
    v255 = stack[-1];
    v254 = stack[-4];
    v254 = cons(v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-7];
    {
        Lisp_Object v5 = stack[0];
        popv(8);
        fn = elt(env, 15); /* apply */
        return (*qfn2(fn))(qenv(fn), v5, v254);
    }

v8:
    v255 = v20;
    v254 = elt(env, 11); /* impl */
    if (v255 == v254) goto v24;
    v255 = v20;
    v254 = elt(env, 12); /* repl */
    if (v255 == v254) goto v270;
    v255 = v20;
    v254 = elt(env, 13); /* equiv */
    v254 = (v255 == v254 ? lisp_true : nil);
    goto v218;

v270:
    v254 = qvalue(elt(env, 2)); /* t */
    goto v218;

v24:
    v254 = qvalue(elt(env, 2)); /* t */
    goto v218;

v263:
    v255 = v20;
    v254 = elt(env, 10); /* not */
    v254 = (v255 == v254 ? lisp_true : nil);
    goto v264;

v45:
    v254 = qvalue(elt(env, 2)); /* t */
    goto v44;

v69:
    v254 = qvalue(elt(env, 2)); /* t */
    goto v68;

v162:
    v254 = qvalue(elt(env, 2)); /* t */
    goto v89;

v99:
    v254 = qvalue(elt(env, 2)); /* t */
    goto v187;

v110:
    v254 = stack[-1];
    goto v136;
/* error exit handlers */
v256:
    popv(8);
    return nil;
}



/* Code for checkdifference */

static Lisp_Object CC_checkdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v142, v143, v160;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkdifference");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v143 = v1;
    v160 = v0;
/* end of prologue */
    v142 = v143;
    v85 = (Lisp_Object)1; /* 0 */
    if (v142 == v85) return onevalue(v160);
    v85 = elt(env, 1); /* difference */
    v142 = v160;
    return list3(v85, v142, v143);
}



/* Code for rtypepart */

static Lisp_Object CC_rtypepart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rtypepart");
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
    v6 = v0;
/* end of prologue */
    v6 = qcar(v6);
    fn = elt(env, 3); /* getrtype */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[0];
    if (v6 == nil) goto v122;
    v6 = elt(env, 1); /* yetunknowntype */
    { popv(1); return onevalue(v6); }

v122:
    v6 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v6); }
/* error exit handlers */
v41:
    popv(1);
    return nil;
}



/* Code for testord */

static Lisp_Object CC_testord(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v127;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testord");
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

v117:
    v160 = stack[-1];
    if (v160 == nil) goto v136;
    v160 = stack[-1];
    v127 = qcar(v160);
    v160 = stack[0];
    v160 = qcar(v160);
    v160 = (Lisp_Object)lesseq2(v127, v160);
    nil = C_nil;
    if (exception_pending()) goto v101;
    v160 = v160 ? lisp_true : nil;
    env = stack[-2];
    if (v160 == nil) goto v85;
    v160 = stack[-1];
    v160 = qcdr(v160);
    stack[-1] = v160;
    v160 = stack[0];
    v160 = qcdr(v160);
    stack[0] = v160;
    goto v117;

v85:
    v160 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v160); }

v136:
    v160 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v160); }
/* error exit handlers */
v101:
    popv(3);
    return nil;
}



/* Code for gen!+can!+bas */

static Lisp_Object CC_genLcanLbas(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v281, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gen+can+bas");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0;
/* end of prologue */
    v37 = (Lisp_Object)17; /* 1 */
    v281 = (Lisp_Object)17; /* 1 */
    v281 = cons(v37, v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    stack[-10] = v281;
    v37 = qvalue(elt(env, 1)); /* nil */
    v281 = (Lisp_Object)17; /* 1 */
    v281 = cons(v37, v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    stack[-8] = v281;
    v281 = (Lisp_Object)17; /* 1 */
    stack[-7] = v281;
    v37 = stack[-9];
    v281 = stack[-7];
    v281 = difference2(v37, v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = Lminusp(nil, v281);
    env = stack[-11];
    if (v281 == nil) goto v76;
    v281 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v281); }

v76:
    v281 = (Lisp_Object)17; /* 1 */
    stack[-3] = v281;
    v37 = stack[-9];
    v281 = stack[-3];
    v281 = difference2(v37, v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = Lminusp(nil, v281);
    env = stack[-11];
    if (v281 == nil) goto v140;
    v281 = qvalue(elt(env, 1)); /* nil */
    goto v87;

v87:
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    stack[-5] = v281;
    stack[-6] = v281;
    goto v143;

v143:
    v281 = stack[-7];
    v281 = add1(v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    stack[-7] = v281;
    v37 = stack[-9];
    v281 = stack[-7];
    v281 = difference2(v37, v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = Lminusp(nil, v281);
    env = stack[-11];
    if (!(v281 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    v281 = (Lisp_Object)17; /* 1 */
    stack[-3] = v281;
    v37 = stack[-9];
    v281 = stack[-3];
    v281 = difference2(v37, v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = Lminusp(nil, v281);
    env = stack[-11];
    if (v281 == nil) goto v282;
    v281 = qvalue(elt(env, 1)); /* nil */
    goto v283;

v283:
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = Lrplacd(nil, stack[-4], v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = stack[-5];
    v281 = qcdr(v281);
    stack[-5] = v281;
    goto v143;

v282:
    v37 = stack[-7];
    v281 = stack[-3];
    if (equal(v37, v281)) goto v248;
    v281 = stack[-8];
    goto v284;

v284:
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    stack[-1] = v281;
    stack[-2] = v281;
    goto v220;

v220:
    v281 = stack[-3];
    v281 = add1(v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    stack[-3] = v281;
    v37 = stack[-9];
    v281 = stack[-3];
    v281 = difference2(v37, v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = Lminusp(nil, v281);
    env = stack[-11];
    if (v281 == nil) goto v212;
    v281 = stack[-2];
    goto v283;

v212:
    stack[0] = stack[-1];
    v37 = stack[-7];
    v281 = stack[-3];
    if (equal(v37, v281)) goto v285;
    v281 = stack[-8];
    goto v96;

v96:
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = Lrplacd(nil, stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = stack[-1];
    v281 = qcdr(v281);
    stack[-1] = v281;
    goto v220;

v285:
    v281 = stack[-10];
    goto v96;

v248:
    v281 = stack[-10];
    goto v284;

v140:
    v37 = stack[-7];
    v281 = stack[-3];
    if (equal(v37, v281)) goto v197;
    v281 = stack[-8];
    goto v190;

v190:
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    stack[-1] = v281;
    stack[-2] = v281;
    goto v194;

v194:
    v281 = stack[-3];
    v281 = add1(v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    stack[-3] = v281;
    v37 = stack[-9];
    v281 = stack[-3];
    v281 = difference2(v37, v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = Lminusp(nil, v281);
    env = stack[-11];
    if (v281 == nil) goto v68;
    v281 = stack[-2];
    goto v87;

v68:
    stack[0] = stack[-1];
    v37 = stack[-7];
    v281 = stack[-3];
    if (equal(v37, v281)) goto v71;
    v281 = stack[-8];
    goto v70;

v70:
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = Lrplacd(nil, stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-11];
    v281 = stack[-1];
    v281 = qcdr(v281);
    stack[-1] = v281;
    goto v194;

v71:
    v281 = stack[-10];
    goto v70;

v197:
    v281 = stack[-10];
    goto v190;
/* error exit handlers */
v210:
    popv(12);
    return nil;
}



/* Code for cl_susiinter */

static Lisp_Object MS_CDECL CC_cl_susiinter(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v114, v222, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_susiinter");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiinter");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v2;
    stack[-4] = v1;
    v113 = v0;
/* end of prologue */
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = v113;
    goto v149;

v149:
    v113 = stack[0];
    if (v113 == nil) goto v191;
    v113 = stack[0];
    v113 = qcar(v113);
    v222 = v113;
    v113 = v222;
    v114 = qcar(v113);
    v113 = elt(env, 2); /* ignore */
    if (v114 == v113) goto v98;
    v113 = v222;
    v114 = qcar(v113);
    v113 = elt(env, 4); /* delete */
    if (v114 == v113) goto v157;
    v113 = v222;
    v114 = qcar(v113);
    v113 = elt(env, 5); /* add */
    if (!(v114 == v113)) goto v100;
    v113 = v222;
    v114 = qcdr(v113);
    v113 = stack[-5];
    v113 = cons(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-6];
    stack[-5] = v113;
    goto v100;

v100:
    v113 = stack[0];
    v113 = qcdr(v113);
    stack[0] = v113;
    goto v149;

v157:
    v113 = v222;
    v113 = qcdr(v113);
    if (v113 == nil) goto v144;
    v113 = qvalue(elt(env, 3)); /* t */
    stack[-1] = v113;
    goto v100;

v144:
    v114 = stack[-3];
    v113 = stack[-4];
    fn = elt(env, 6); /* delqip */
    v113 = (*qfn2(fn))(qenv(fn), v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-6];
    stack[-4] = v113;
    goto v100;

v98:
    v113 = v222;
    v113 = qcdr(v113);
    if (v113 == nil) goto v126;
    v113 = qvalue(elt(env, 3)); /* t */
    stack[-2] = v113;
    v113 = v222;
    v114 = qcdr(v113);
    v113 = stack[-5];
    v113 = cons(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-6];
    stack[-5] = v113;
    goto v100;

v126:
    v114 = stack[-3];
    v113 = elt(env, 2); /* ignore */
    fn = elt(env, 7); /* setcdr */
    v113 = (*qfn2(fn))(qenv(fn), v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-6];
    goto v100;

v191:
    v47 = stack[-4];
    v222 = stack[-5];
    v114 = stack[-2];
    v113 = stack[-1];
    popv(7);
    return list4(v47, v222, v114, v113);
/* error exit handlers */
v215:
    popv(7);
    return nil;
}



/* Code for rl_updcache */

static Lisp_Object MS_CDECL CC_rl_updcache(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v280;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rl_updcache");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_updcache");
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
    v90 = qvalue(elt(env, 1)); /* rl_bbl!* */
    stack[0] = v90;
    goto v163;

v163:
    v90 = stack[0];
    if (v90 == nil) goto v143;
    v90 = stack[0];
    v90 = qcar(v90);
    v280 = v90;
    v90 = qvalue(elt(env, 2)); /* nil */
    v90 = Lset(nil, v280, v90);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-1];
    v90 = stack[0];
    v90 = qcdr(v90);
    stack[0] = v90;
    goto v163;

v143:
    v90 = qvalue(elt(env, 3)); /* rl_cid!* */
    v280 = qcar(v90);
    v90 = elt(env, 4); /* rl_params */
    v90 = get(v280, v90);
    env = stack[-1];
    stack[0] = v90;
    goto v85;

v85:
    v90 = stack[0];
    if (v90 == nil) goto v141;
    v90 = stack[0];
    v90 = qcar(v90);
    v280 = v90;
    v280 = qcar(v280);
    v90 = qcdr(v90);
    v90 = Lset(nil, v280, v90);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-1];
    v90 = stack[0];
    v90 = qcdr(v90);
    stack[0] = v90;
    goto v85;

v141:
    v90 = qvalue(elt(env, 5)); /* rl_servl!* */
    stack[0] = v90;
    goto v157;

v157:
    v90 = stack[0];
    if (v90 == nil) goto v63;
    v90 = stack[0];
    v90 = qcar(v90);
    v280 = v90;
    v90 = qvalue(elt(env, 2)); /* nil */
    v90 = Lset(nil, v280, v90);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-1];
    v90 = stack[0];
    v90 = qcdr(v90);
    stack[0] = v90;
    goto v157;

v63:
    v90 = qvalue(elt(env, 3)); /* rl_cid!* */
    v280 = qcar(v90);
    v90 = elt(env, 6); /* rl_services */
    v90 = get(v280, v90);
    env = stack[-1];
    stack[0] = v90;
    goto v130;

v130:
    v90 = stack[0];
    if (v90 == nil) goto v152;
    v90 = stack[0];
    v90 = qcar(v90);
    v280 = v90;
    v280 = qcar(v280);
    v90 = qcdr(v90);
    v90 = Lset(nil, v280, v90);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-1];
    v90 = stack[0];
    v90 = qcdr(v90);
    stack[0] = v90;
    goto v130;

v152:
    v90 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v90); }
/* error exit handlers */
v198:
    popv(2);
    return nil;
}



/* Code for semanticml */

static Lisp_Object CC_semanticml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for semanticml");
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
    v121 = stack[0];
    v64 = Llength(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = (Lisp_Object)17; /* 1 */
    v121 = (Lisp_Object)greaterp2(v64, v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v121 = v121 ? lisp_true : nil;
    env = stack[-1];
    if (v121 == nil) goto v117;
    v121 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 15); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = elt(env, 3); /* "<fn>" */
    fn = elt(env, 15); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    goto v117;

v117:
    v121 = elt(env, 5); /* "<semantic>" */
    fn = elt(env, 15); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = elt(env, 6); /* "<ci><mo>" */
    fn = elt(env, 15); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v121 = Lprinc(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = elt(env, 7); /* "</mo></ci>" */
    v121 = Lprinc(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = elt(env, 8); /* "<annotation-xml encoding=""OpenMath"">" */
    fn = elt(env, 15); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = elt(env, 9); /* "<" */
    fn = elt(env, 15); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    v121 = qcar(v121);
    fn = elt(env, 17); /* list2string */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = elt(env, 10); /* ">" */
    v121 = Lprinc(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = elt(env, 11); /* "</annotation-xml>" */
    fn = elt(env, 15); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = elt(env, 12); /* "</semantic>" */
    fn = elt(env, 15); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = stack[0];
    v64 = Llength(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = (Lisp_Object)17; /* 1 */
    v121 = (Lisp_Object)greaterp2(v64, v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v121 = v121 ? lisp_true : nil;
    env = stack[-1];
    if (v121 == nil) goto v161;
    v121 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = elt(env, 13); /* "</fn>" */
    fn = elt(env, 15); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = stack[0];
    v121 = qcdr(v121);
    fn = elt(env, 18); /* multi_elem */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v121 = elt(env, 14); /* "</apply>" */
    fn = elt(env, 15); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v62;
    goto v161;

v161:
    v121 = nil;
    { popv(2); return onevalue(v121); }
/* error exit handlers */
v62:
    popv(2);
    return nil;
}



/* Code for boolvalue!* */

static Lisp_Object CC_boolvalueH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v137;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boolvalue*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v137 = v0;
/* end of prologue */
    v138 = v137;
    if (v138 == nil) goto v163;
    v138 = (Lisp_Object)1; /* 0 */
    v138 = (v137 == v138 ? lisp_true : nil);
    v138 = (v138 == nil ? lisp_true : nil);
    return onevalue(v138);

v163:
    v138 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v138);
}



/* Code for ldf!-simp */

static Lisp_Object CC_ldfKsimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201, v67, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-simp");
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
    v67 = v0;
/* end of prologue */
    v201 = v67;
    if (v201 == nil) goto v163;
    v201 = v67;
    v201 = qcdr(v201);
    if (v201 == nil) goto v189;
    v201 = v67;
    fn = elt(env, 3); /* prepf */
    v201 = (*qfn1(fn))(qenv(fn), v201);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    fn = elt(env, 4); /* simp */
    v201 = (*qfn1(fn))(qenv(fn), v201);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    v201 = qcar(v201);
    stack[-1] = v201;
    v201 = stack[-1];
    if (!consp(v201)) goto v61;
    v201 = stack[-1];
    v201 = qcar(v201);
    v201 = (consp(v201) ? nil : lisp_true);
    goto v59;

v59:
    if (!(v201 == nil)) goto v104;
    stack[0] = stack[-1];
    v201 = stack[-1];
    fn = elt(env, 5); /* comfac */
    v201 = (*qfn1(fn))(qenv(fn), v201);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    v201 = qcdr(v201);
    fn = elt(env, 6); /* quotf */
    v201 = (*qfn2(fn))(qenv(fn), stack[0], v201);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    stack[-1] = v201;
    goto v104;

v104:
    v201 = stack[-1];
    fn = elt(env, 7); /* minusf */
    v201 = (*qfn1(fn))(qenv(fn), v201);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    if (v201 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v201 = stack[-1];
    {
        popv(3);
        fn = elt(env, 8); /* negf */
        return (*qfn1(fn))(qenv(fn), v201);
    }

v61:
    v201 = qvalue(elt(env, 2)); /* t */
    goto v59;

v189:
    v201 = v67;
    v201 = qcar(v201);
    v201 = qcar(v201);
    v166 = qcar(v201);
    v67 = (Lisp_Object)17; /* 1 */
    v201 = (Lisp_Object)17; /* 1 */
    v201 = acons(v166, v67, v201);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    v201 = ncons(v201);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    fn = elt(env, 3); /* prepf */
    v201 = (*qfn1(fn))(qenv(fn), v201);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    fn = elt(env, 4); /* simp */
    v201 = (*qfn1(fn))(qenv(fn), v201);
    nil = C_nil;
    if (exception_pending()) goto v146;
    v201 = qcar(v201);
    { popv(3); return onevalue(v201); }

v163:
    v201 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v201); }
/* error exit handlers */
v146:
    popv(3);
    return nil;
}



/* Code for initarg */

static Lisp_Object CC_initarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v289;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initarg");
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
    v289 = qvalue(elt(env, 1)); /* op */
    v244 = elt(env, 2); /* symmetric */
    v244 = Lflagp(nil, v289, v244);
    env = stack[-6];
    qvalue(elt(env, 3)) = v244; /* symm */
    v244 = qvalue(elt(env, 4)); /* p */
    stack[0] = Llength(nil, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v244 = qvalue(elt(env, 5)); /* r */
    v244 = Llength(nil, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v244 = difference2(stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v244 = add1(v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-1] = v244;
    v244 = qvalue(elt(env, 1)); /* op */
    fn = elt(env, 16); /* ident */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    qvalue(elt(env, 6)) = v244; /* identity */
    v244 = qvalue(elt(env, 5)); /* r */
    v244 = qcar(v244);
    fn = elt(env, 17); /* mgenp */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-3] = v244;
    v244 = qvalue(elt(env, 5)); /* r */
    v244 = qcdr(v244);
    fn = elt(env, 18); /* list!-mgen */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[0] = v244;
    v289 = qvalue(elt(env, 1)); /* op */
    v244 = elt(env, 7); /* assoc */
    v244 = Lflagp(nil, v289, v244);
    env = stack[-6];
    if (v244 == nil) goto v166;
    v244 = qvalue(elt(env, 3)); /* symm */
    if (v244 == nil) goto v168;
    v289 = stack[0];
    v244 = (Lisp_Object)1; /* 0 */
    v244 = (Lisp_Object)greaterp2(v289, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v244 = v244 ? lisp_true : nil;
    env = stack[-6];
    if (v244 == nil) goto v74;
    v244 = qvalue(elt(env, 9)); /* !*sym!-assoc */
    v244 = (v244 == nil ? lisp_true : nil);
    goto v194;

v194:
    v244 = (v244 == nil ? lisp_true : nil);
    goto v104;

v104:
    stack[-5] = v244;
    v244 = qvalue(elt(env, 5)); /* r */
    v289 = Llength(nil, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v244 = (Lisp_Object)17; /* 1 */
    v244 = (Lisp_Object)greaterp2(v289, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v244 = v244 ? lisp_true : nil;
    env = stack[-6];
    if (v244 == nil) goto v144;
    v244 = stack[-5];
    if (!(v244 == nil)) goto v120;
    v244 = stack[0];
    goto v120;

v120:
    stack[-2] = v244;
    v289 = stack[-1];
    v244 = (Lisp_Object)17; /* 1 */
    v244 = (Lisp_Object)greaterp2(v289, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v244 = v244 ? lisp_true : nil;
    env = stack[-6];
    if (!(v244 == nil)) goto v69;
    v244 = qvalue(elt(env, 6)); /* identity */
    if (v244 == nil) goto v116;
    v244 = qvalue(elt(env, 4)); /* p */
    v289 = Llength(nil, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v244 = (Lisp_Object)1; /* 0 */
    v244 = (Lisp_Object)greaterp2(v289, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v244 = v244 ? lisp_true : nil;
    env = stack[-6];
    goto v69;

v69:
    v289 = v244;
    v244 = stack[-3];
    if (v244 == nil) goto v54;
    v244 = v289;
    goto v290;

v290:
    qvalue(elt(env, 10)) = v244; /* mcontract */
    v244 = stack[-5];
    if (v244 == nil) goto v51;
    v244 = v289;
    if (v244 == nil) goto v176;
    v244 = stack[-3];
    v244 = (v244 == nil ? lisp_true : nil);
    goto v279;

v279:
    qvalue(elt(env, 11)) = v244; /* acontract */
    v244 = qvalue(elt(env, 6)); /* identity */
    if (v244 == nil) goto v171;
    v289 = stack[-1];
    v244 = (Lisp_Object)17; /* 1 */
    v244 = (Lisp_Object)lessp2(v289, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v244 = v244 ? lisp_true : nil;
    env = stack[-6];
    if (!(v244 == nil)) goto v56;
    v244 = stack[-2];
    goto v56;

v56:
    qvalue(elt(env, 12)) = v244; /* expand */
    v244 = stack[-2];
    if (!(v244 == nil)) goto v44;
    v289 = stack[-1];
    v244 = (Lisp_Object)17; /* 1 */
    v244 = (Lisp_Object)lessp2(v289, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v244 = v244 ? lisp_true : nil;
    env = stack[-6];
    if (!(v244 == nil)) goto v44;
    v244 = stack[-1];
    goto v175;

v175:
    qvalue(elt(env, 13)) = v244; /* i */
    v244 = qvalue(elt(env, 6)); /* identity */
    if (v244 == nil) goto v7;
    v244 = qvalue(elt(env, 4)); /* p */
    v244 = Llength(nil, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    goto v42;

v42:
    qvalue(elt(env, 14)) = v244; /* upb */
    v244 = qvalue(elt(env, 3)); /* symm */
    if (v244 == nil) goto v291;
    v244 = stack[-4];
    fn = elt(env, 19); /* initcomb */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    qvalue(elt(env, 15)) = v244; /* comb */
    goto v291;

v291:
    v244 = nil;
    { popv(7); return onevalue(v244); }

v7:
    v289 = stack[-1];
    v244 = stack[0];
    v244 = plus2(v289, v244);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    goto v42;

v44:
    v244 = stack[-3];
    if (v244 == nil) goto v40;
    v244 = (Lisp_Object)1; /* 0 */
    goto v175;

v40:
    v244 = (Lisp_Object)17; /* 1 */
    goto v175;

v171:
    v244 = qvalue(elt(env, 8)); /* nil */
    goto v56;

v176:
    v244 = qvalue(elt(env, 8)); /* nil */
    goto v279;

v51:
    v244 = qvalue(elt(env, 8)); /* nil */
    goto v279;

v54:
    v244 = qvalue(elt(env, 8)); /* nil */
    goto v290;

v116:
    v244 = qvalue(elt(env, 8)); /* nil */
    goto v69;

v144:
    v244 = qvalue(elt(env, 8)); /* nil */
    goto v120;

v74:
    v244 = qvalue(elt(env, 8)); /* nil */
    goto v194;

v168:
    v244 = qvalue(elt(env, 8)); /* nil */
    goto v194;

v166:
    v244 = qvalue(elt(env, 8)); /* nil */
    goto v104;
/* error exit handlers */
v35:
    popv(7);
    return nil;
}



/* Code for gfstorval */

static Lisp_Object CC_gfstorval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v9, v189;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfstorval");
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
    v41 = v1;
    v9 = v0;
/* end of prologue */
    v189 = v9;
    v9 = v41;
    v41 = qvalue(elt(env, 1)); /* !*xnlist */
    v41 = acons(v189, v9, v41);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[0];
    qvalue(elt(env, 1)) = v41; /* !*xnlist */
    { popv(1); return onevalue(v41); }
/* error exit handlers */
v167:
    popv(1);
    return nil;
}



setup_type const u29_setup[] =
{
    {"makecoeffpairshom",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairshom},
    {"ithlistelem",             too_few_2,      CC_ithlistelem,wrong_no_2},
    {"testpr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_testpr},
    {"dipcondense",             CC_dipcondense, too_many_1,    wrong_no_1},
    {"size_of_matrix",          CC_size_of_matrix,too_many_1,  wrong_no_1},
    {"f2dip1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_f2dip1},
    {"get:const",               too_few_2,      CC_getTconst,  wrong_no_2},
    {"r2findindex1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_r2findindex1},
    {"list-evaluate",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_listKevaluate},
    {"getupper",                CC_getupper,    too_many_1,    wrong_no_1},
    {"z-roads",                 CC_zKroads,     too_many_1,    wrong_no_1},
    {"split_cov_cont_ids",      CC_split_cov_cont_ids,too_many_1,wrong_no_1},
    {"polynomwrite",            CC_polynomwrite,too_many_1,    wrong_no_1},
    {"pasf_subfof1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_subfof1},
    {"listrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_listrd},
    {"compl",                   too_few_2,      CC_compl,      wrong_no_2},
    {"spcol_dim",               CC_spcol_dim,   too_many_1,    wrong_no_1},
    {"dm-gt",                   too_few_2,      CC_dmKgt,      wrong_no_2},
    {"groebspolynom3",          too_few_2,      CC_groebspolynom3,wrong_no_2},
    {"mkexdf",                  CC_mkexdf,      too_many_1,    wrong_no_1},
    {"r2oaddspecies",           too_few_2,      CC_r2oaddspecies,wrong_no_2},
    {"mkassign",                too_few_2,      CC_mkassign,   wrong_no_2},
    {"vunion",                  too_few_2,      CC_vunion,     wrong_no_2},
    {"subs2p",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_subs2p},
    {"mod_eval_uni_poly",       too_few_2,      CC_mod_eval_uni_poly,wrong_no_2},
    {"preptayexp",              CC_preptayexp,  too_many_1,    wrong_no_1},
    {"domainvalchk",            too_few_2,      CC_domainvalchk,wrong_no_2},
    {"enter-sorted",            too_few_2,      CC_enterKsorted,wrong_no_2},
    {"matrixom",                CC_matrixom,    too_many_1,    wrong_no_1},
    {"countof",                 too_few_2,      CC_countof,    wrong_no_2},
    {"remdiff",                 CC_remdiff,     too_many_1,    wrong_no_1},
    {"::quotient",              too_few_2,      CC_TTquotient, wrong_no_2},
    {"mktails",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails},
    {"mv-compact2",             too_few_2,      CC_mvKcompact2,wrong_no_2},
    {"msolve-poly1",            too_few_2,      CC_msolveKpoly1,wrong_no_2},
    {"reduce-mod-eigf",         too_few_2,      CC_reduceKmodKeigf,wrong_no_2},
    {"cl_apply2ats1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_apply2ats1},
    {"checkdifference",         too_few_2,      CC_checkdifference,wrong_no_2},
    {"rtypepart",               CC_rtypepart,   too_many_1,    wrong_no_1},
    {"testord",                 too_few_2,      CC_testord,    wrong_no_2},
    {"gen+can+bas",             CC_genLcanLbas, too_many_1,    wrong_no_1},
    {"cl_susiinter",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiinter},
    {"rl_updcache",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_updcache},
    {"semanticml",              CC_semanticml,  too_many_1,    wrong_no_1},
    {"boolvalue*",              CC_boolvalueH,  too_many_1,    wrong_no_1},
    {"ldf-simp",                CC_ldfKsimp,    too_many_1,    wrong_no_1},
    {"initarg",                 CC_initarg,     too_many_1,    wrong_no_1},
    {"gfstorval",               too_few_2,      CC_gfstorval,  wrong_no_2},
    {NULL, (one_args *)"u29", (two_args *)"21189 8863721 5016807", 0}
};

/* end of generated code */
