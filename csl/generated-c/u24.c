
/* $destdir\u24.c        Machine generated C code */

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


/* Code for add!-degrees */

static Lisp_Object CC_addKdegrees(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add-degrees");
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
    goto v14;

v14:
    v12 = stack[-4];
    if (v12 == nil) goto v15;
    v12 = stack[-4];
    v12 = qcar(v12);
    stack[-2] = v12;
    v12 = stack[-3];
    v12 = qcar(v12);
    stack[-1] = v12;
    v12 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v12;
    goto v16;

v16:
    v12 = stack[-2];
    if (v12 == nil) goto v17;
    v12 = stack[-2];
    v13 = qcar(v12);
    v12 = stack[-1];
    v12 = qcar(v12);
    fn = elt(env, 2); /* tayexp!-plus2 */
    v13 = (*qfn2(fn))(qenv(fn), v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-6];
    v12 = stack[0];
    v12 = cons(v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-6];
    stack[0] = v12;
    v12 = stack[-2];
    v12 = qcdr(v12);
    stack[-2] = v12;
    v12 = stack[-1];
    v12 = qcdr(v12);
    stack[-1] = v12;
    goto v16;

v17:
    v12 = stack[0];
    v13 = Lnreverse(nil, v12);
    env = stack[-6];
    v12 = stack[-5];
    v12 = cons(v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-6];
    stack[-5] = v12;
    v12 = stack[-4];
    v12 = qcdr(v12);
    stack[-4] = v12;
    v12 = stack[-3];
    v12 = qcdr(v12);
    stack[-3] = v12;
    goto v14;

v15:
    v12 = stack[-5];
        popv(7);
        return Lnreverse(nil, v12);
/* error exit handlers */
v18:
    popv(7);
    return nil;
}



/* Code for mk!+squared!+norm */

static Lisp_Object CC_mkLsquaredLnorm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+squared+norm");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v19 = v0;
/* end of prologue */
    v20 = v19;
    {
        fn = elt(env, 1); /* mk!+inner!+product */
        return (*qfn2(fn))(qenv(fn), v20, v19);
    }
}



/* Code for expnd */

static Lisp_Object CC_expnd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v6, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expnd");
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
    v24 = qvalue(elt(env, 1)); /* !*really_off_exp */
    if (!(v24 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v24 = stack[0];
    fn = elt(env, 3); /* expnd1 */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    stack[0] = v24;
    v24 = qvalue(elt(env, 2)); /* !*sub2 */
    if (v24 == nil) goto v27;
    v24 = stack[0];
    fn = elt(env, 4); /* subs2f */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v25 = v24;
    v6 = qcdr(v24);
    v24 = (Lisp_Object)17; /* 1 */
    if (!(v6 == v24)) goto v27;
    v24 = v25;
    v24 = qcar(v24);
    goto v20;

v20:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    { popv(3); return onevalue(v24); }

v27:
    v24 = stack[0];
    goto v20;
/* error exit handlers */
v26:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    popv(3);
    return nil;
}



/* Code for rl_bnfsimpl */

static Lisp_Object CC_rl_bnfsimpl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_bnfsimpl");
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
    v30 = v1;
    v31 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bnfsimpl!* */
    v30 = list2(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    {
        Lisp_Object v33 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v33, v30);
    }
/* error exit handlers */
v32:
    popv(2);
    return nil;
}



/* Code for dip_fmon */

static Lisp_Object CC_dip_fmon(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35, v21;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_fmon");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v1;
    v34 = v0;
/* end of prologue */
    v21 = qvalue(elt(env, 1)); /* nil */
    return list2star(v35, v34, v21);
}



/* Code for evaluate!-horner */

static Lisp_Object CC_evaluateKhorner(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-horner");
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
    v45 = stack[-1];
    v44 = qvalue(elt(env, 1)); /* horner!-cache!* */
    v44 = Lassoc(nil, v45, v44);
    stack[-2] = v44;
    v44 = stack[-2];
    if (v44 == nil) goto v30;
    v44 = stack[-2];
    v44 = qcdr(v44);
    { popv(4); return onevalue(v44); }

v30:
    v44 = stack[-1];
    fn = elt(env, 3); /* simp!* */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    stack[-2] = v44;
    v44 = stack[-2];
    v44 = qcar(v44);
    fn = elt(env, 4); /* hornerf */
    stack[0] = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v44 = stack[-2];
    v44 = qcdr(v44);
    fn = elt(env, 4); /* hornerf */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v44 = cons(stack[0], v44);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v45 = v44;
    v44 = v45;
    v44 = qcar(v44);
    if (v44 == nil) goto v24;
    v44 = elt(env, 2); /* prepf */
    fn = elt(env, 5); /* sqform */
    v44 = (*qfn2(fn))(qenv(fn), v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    goto v48;

v48:
    stack[-2] = v44;
    v46 = stack[-1];
    v45 = stack[-2];
    v44 = qvalue(elt(env, 1)); /* horner!-cache!* */
    v44 = acons(v46, v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    qvalue(elt(env, 1)) = v44; /* horner!-cache!* */
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v24:
    v44 = (Lisp_Object)1; /* 0 */
    goto v48;
/* error exit handlers */
v47:
    popv(4);
    return nil;
}



/* Code for toolongexpp */

static Lisp_Object CC_toolongexpp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for toolongexpp");
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
    v14 = v0;
/* end of prologue */
    fn = elt(env, 2); /* numprintlen */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[0];
    v19 = qvalue(elt(env, 1)); /* maxexpprintlen!* */
        popv(1);
        return Lgreaterp(nil, v14, v19);
/* error exit handlers */
v20:
    popv(1);
    return nil;
}



/* Code for find_bubles_coeff */

static Lisp_Object MS_CDECL CC_find_bubles_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v49, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31, v50, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "find_bubles_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles_coeff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v49;
    v31 = v1;
    v50 = v0;
/* end of prologue */
    v32 = v50;
    v50 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* find_bubles1_coeff */
        return (*qfnn(fn))(qenv(fn), 4, v32, v50, v31, v30);
    }
}



/* Code for !*!*a2i */

static Lisp_Object CC_HHa2i(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for **a2i");
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
    v52 = v1;
    stack[0] = v0;
/* end of prologue */
    v53 = stack[0];
    fn = elt(env, 2); /* intexprnp */
    v52 = (*qfn2(fn))(qenv(fn), v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    if (!(v52 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v53 = elt(env, 1); /* ieval */
    v52 = stack[0];
    popv(2);
    return list2(v53, v52);
/* error exit handlers */
v54:
    popv(2);
    return nil;
}



/* Code for mo_zero */

static Lisp_Object MS_CDECL CC_mo_zero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mo_zero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_zero");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v15 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* mo!=deglist */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    {
        Lisp_Object v20 = stack[0];
        popv(1);
        return cons(v20, v15);
    }
/* error exit handlers */
v19:
    popv(1);
    return nil;
}



/* Code for insert */

static Lisp_Object CC_insert(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v49)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insert");
#endif
    if (stack >= stacklimit)
    {
        push2(v49,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v49);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v37 = v49;
    stack[-1] = v1;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v37; /* gg */
    stack[0] = nil;
    goto v20;

v20:
    v37 = qvalue(elt(env, 1)); /* gg */
    if (v37 == nil) goto v8;
    v37 = stack[-1];
    v3 = qcdr(v37);
    v37 = qvalue(elt(env, 1)); /* gg */
    v37 = qcar(v37);
    v37 = qcdr(v37);
    fn = elt(env, 3); /* dless */
    v37 = (*qfn2(fn))(qenv(fn), v3, v37);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    if (v37 == nil) goto v8;
    v37 = qvalue(elt(env, 1)); /* gg */
    v3 = qcar(v37);
    v37 = stack[0];
    v37 = cons(v3, v37);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    stack[0] = v37;
    v37 = qvalue(elt(env, 1)); /* gg */
    v37 = qcdr(v37);
    qvalue(elt(env, 1)) = v37; /* gg */
    goto v20;

v8:
    v37 = stack[0];
    stack[0] = Lnreverse(nil, v37);
    env = stack[-3];
    v3 = stack[-1];
    v37 = qvalue(elt(env, 1)); /* gg */
    v37 = cons(v3, v37);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    v37 = Lappend(nil, stack[0], v37);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* gg */
    { popv(4); return onevalue(v37); }
/* error exit handlers */
v45:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* gg */
    popv(4);
    return nil;
}



/* Code for formproc */

static Lisp_Object MS_CDECL CC_formproc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v49, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v156, v157, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formproc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formproc");
#endif
    if (stack >= stacklimit)
    {
        push3(v49,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v49);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v49;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* fname!* */
    qvalue(elt(env, 1)) = nil; /* fname!* */
    stack[-2] = nil;
    v155 = stack[-1];
    v155 = qcdr(v155);
    stack[-1] = v155;
    v155 = stack[-1];
    v155 = qcar(v155);
    qvalue(elt(env, 1)) = v155; /* fname!* */
    stack[-5] = v155;
    v155 = stack[-1];
    v155 = qcdr(v155);
    v155 = qcar(v155);
    if (v155 == nil) goto v32;
    v155 = stack[-1];
    v155 = qcdr(v155);
    v155 = qcar(v155);
    stack[-7] = v155;
    goto v32;

v32:
    v155 = stack[-1];
    v155 = qcdr(v155);
    v155 = qcdr(v155);
    stack[-1] = v155;
    v155 = stack[-1];
    v155 = qcar(v155);
    qvalue(elt(env, 2)) = v155; /* ftype!* */
    stack[-4] = v155;
    v155 = stack[-5];
    if (!symbolp(v155)) v155 = nil;
    else { v155 = qfastgets(v155);
           if (v155 != nil) { v155 = elt(v155, 1); /* lose */
#ifdef RECORD_GET
             if (v155 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v155 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v155 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v155 == SPID_NOPROP) v155 = nil; else v155 = lisp_true; }}
#endif
    if (v155 == nil) goto v40;
    v155 = qvalue(elt(env, 3)); /* !*lose */
    if (!(v155 == nil)) goto v57;
    v155 = qvalue(elt(env, 4)); /* !*defn */
    v155 = (v155 == nil ? lisp_true : nil);
    goto v57;

v57:
    if (v155 == nil) goto v6;
    v155 = qvalue(elt(env, 6)); /* !*msg */
    if (v155 == nil) goto v159;
    stack[0] = elt(env, 7); /* "***" */
    v156 = stack[-5];
    v155 = elt(env, 8); /* "not defined (LOSE flag)" */
    v155 = list2(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    fn = elt(env, 38); /* lpriw */
    v155 = (*qfn2(fn))(qenv(fn), stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    goto v159;

v159:
    v155 = elt(env, 9); /* (quote nil) */
    goto v20;

v20:
    qvalue(elt(env, 1)) = stack[-6]; /* fname!* */
    { popv(10); return onevalue(v155); }

v6:
    v155 = qvalue(elt(env, 10)); /* !*redeflg!* */
    if (v155 == nil) goto v48;
    v155 = stack[-5];
    fn = elt(env, 39); /* getd */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    if (v155 == nil) goto v48;
    v155 = qvalue(elt(env, 6)); /* !*msg */
    if (v155 == nil) goto v48;
    stack[-3] = elt(env, 7); /* "***" */
    v156 = stack[-5];
    v155 = elt(env, 11); /* "redefined" */
    v155 = list2(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    fn = elt(env, 38); /* lpriw */
    v155 = (*qfn2(fn))(qenv(fn), stack[-3], v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    goto v48;

v48:
    v155 = stack[-1];
    v155 = qcdr(v155);
    v155 = qcar(v155);
    stack[-3] = v155;
    goto v34;

v34:
    v155 = stack[-3];
    if (v155 == nil) goto v35;
    v155 = stack[-3];
    v155 = qcar(v155);
    v155 = Lsymbol_specialp(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    if (!(v155 == nil)) goto v161;
    v155 = stack[-3];
    v155 = qcar(v155);
    v155 = Lsymbol_globalp(nil, v155);
    env = stack[-9];
    if (!(v155 == nil)) goto v161;

v162:
    v155 = stack[-3];
    v155 = qcdr(v155);
    stack[-3] = v155;
    goto v34;

v161:
    v155 = stack[-3];
    v156 = qcar(v155);
    v155 = stack[-2];
    v155 = cons(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[-2] = v155;
    goto v162;

v35:
    v155 = stack[-1];
    v155 = qcdr(v155);
    v155 = qcar(v155);
    stack[-3] = v155;
    v155 = stack[-1];
    v155 = qcdr(v155);
    v155 = qcdr(v155);
    v155 = qcar(v155);
    stack[-8] = v155;
    v156 = stack[-8];
    v155 = elt(env, 12); /* rblock */
    if (!consp(v156)) goto v163;
    v156 = qcar(v156);
    if (!(v156 == v155)) goto v163;
    v155 = stack[-8];
    v155 = qcdr(v155);
    v155 = qcar(v155);
    goto v164;

v164:
    stack[-1] = v155;
    v158 = stack[-3];
    v157 = stack[-1];
    v156 = stack[0];
    v155 = stack[-7];
    fn = elt(env, 40); /* pairxvars */
    v155 = (*qfnn(fn))(qenv(fn), 4, v158, v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[0] = v155;
    v155 = stack[-1];
    if (v155 == nil) goto v165;
    v155 = stack[-8];
    stack[-1] = qcar(v155);
    v155 = stack[-8];
    v156 = qcdr(v155);
    v155 = stack[0];
    v155 = qcdr(v155);
    v155 = Lrplaca(nil, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v155 = cons(stack[-1], v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[-8] = v155;
    goto v165;

v165:
    v157 = stack[-8];
    v155 = stack[0];
    v156 = qcar(v155);
    v155 = stack[-7];
    fn = elt(env, 41); /* form1 */
    v155 = (*qfnn(fn))(qenv(fn), 3, v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[-8] = v155;
    v155 = stack[-2];
    if (v155 == nil) goto v166;
    v156 = stack[-4];
    v155 = elt(env, 13); /* (expr fexpr macro) */
    v155 = Lmemq(nil, v156, v155);
    if (v155 == nil) goto v166;
    stack[-1] = elt(env, 14); /* progn */
    stack[0] = elt(env, 15); /* declare */
    v156 = elt(env, 16); /* special */
    v155 = stack[-2];
    v155 = cons(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v156 = list2(stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v155 = stack[-8];
    v155 = list3(stack[-1], v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[-8] = v155;
    goto v166;

v166:
    v155 = qvalue(elt(env, 17)); /* !*nosmacros */
    if (v155 == nil) goto v167;
    v156 = stack[-4];
    v155 = elt(env, 18); /* smacro */
    if (!(v156 == v155)) goto v167;
    v155 = elt(env, 19); /* expr */
    stack[-4] = v155;
    goto v167;

v167:
    v156 = stack[-4];
    v155 = elt(env, 18); /* smacro */
    if (v156 == v155) goto v168;
    v156 = stack[-5];
    v155 = elt(env, 18); /* smacro */
    v155 = get(v156, v155);
    env = stack[-9];
    goto v169;

v169:
    if (v155 == nil) goto v170;
    v155 = qvalue(elt(env, 6)); /* !*msg */
    if (v155 == nil) goto v170;
    stack[0] = elt(env, 7); /* "***" */
    v157 = elt(env, 20); /* "SMACRO" */
    v156 = stack[-5];
    v155 = elt(env, 11); /* "redefined" */
    v155 = list3(v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    fn = elt(env, 38); /* lpriw */
    v155 = (*qfn2(fn))(qenv(fn), stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    goto v170;

v170:
    v157 = stack[-3];
    v156 = stack[-8];
    v155 = stack[-7];
    fn = elt(env, 42); /* symbvarlst */
    v155 = (*qfnn(fn))(qenv(fn), 3, v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v156 = stack[-4];
    v155 = elt(env, 19); /* expr */
    if (v156 == v155) goto v171;
    v156 = stack[-4];
    v155 = elt(env, 22); /* fexpr */
    if (v156 == v155) goto v172;
    v156 = stack[-4];
    v155 = elt(env, 24); /* macro */
    if (v156 == v155) goto v173;
    v156 = stack[-4];
    v155 = elt(env, 26); /* procfn */
    v155 = get(v156, v155);
    env = stack[-9];
    stack[-1] = v155;
    if (v155 == nil) goto v174;
    v158 = stack[-1];
    v157 = stack[-5];
    v156 = stack[-3];
    v155 = stack[-8];
    v155 = Lapply3(nil, 4, v158, v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    goto v20;

v174:
    stack[-2] = elt(env, 27); /* putc */
    v155 = stack[-5];
    stack[-1] = Lmkquote(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v155 = stack[-4];
    stack[0] = Lmkquote(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v157 = elt(env, 28); /* lambda */
    v156 = stack[-3];
    v155 = stack[-8];
    v155 = list3(v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v155 = Lmkquote(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v155 = list4(stack[-2], stack[-1], stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[-8] = v155;
    goto v175;

v175:
    v156 = stack[-7];
    v155 = elt(env, 29); /* symbolic */
    if (v156 == v155) goto v176;
    stack[-1] = elt(env, 30); /* flag */
    v155 = stack[-5];
    v155 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[0] = Lmkquote(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v155 = elt(env, 31); /* opfn */
    v155 = Lmkquote(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v156 = list3(stack[-1], stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v155 = stack[-8];
    fn = elt(env, 43); /* mkprogn */
    v155 = (*qfn2(fn))(qenv(fn), v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[-8] = v155;
    goto v176;

v176:
    v155 = qvalue(elt(env, 32)); /* !*argnochk */
    if (v155 == nil) goto v177;
    v156 = stack[-4];
    v155 = elt(env, 33); /* (expr smacro) */
    v155 = Lmemq(nil, v156, v155);
    if (v155 == nil) goto v177;
    stack[-1] = elt(env, 34); /* put */
    v155 = stack[-5];
    stack[-2] = Lmkquote(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v155 = elt(env, 35); /* number!-of!-args */
    stack[0] = Lmkquote(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v155 = stack[-3];
    v155 = Llength(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v156 = list4(stack[-1], stack[-2], stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    v155 = stack[-8];
    fn = elt(env, 43); /* mkprogn */
    v155 = (*qfn2(fn))(qenv(fn), v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[-8] = v155;
    goto v177;

v177:
    v155 = qvalue(elt(env, 4)); /* !*defn */
    if (v155 == nil) goto v178;
    v156 = stack[-4];
    v155 = elt(env, 36); /* (fexpr macro smacro) */
    v155 = Lmemq(nil, v156, v155);
    if (v155 == nil) goto v178;
    v155 = stack[-8];
    fn = elt(env, 44); /* eval */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    goto v178;

v178:
    v155 = qvalue(elt(env, 37)); /* !*micro!-version */
    if (v155 == nil) goto v179;
    v156 = stack[-4];
    v155 = elt(env, 36); /* (fexpr macro smacro) */
    v155 = Lmemq(nil, v156, v155);
    if (v155 == nil) goto v179;
    v155 = qvalue(elt(env, 5)); /* nil */
    goto v20;

v179:
    v155 = stack[-8];
    goto v20;

v173:
    v158 = elt(env, 25); /* dm */
    v157 = stack[-5];
    v156 = stack[-3];
    v155 = stack[-8];
    v155 = list4(v158, v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[-8] = v155;
    goto v175;

v172:
    v158 = elt(env, 23); /* df */
    v157 = stack[-5];
    v156 = stack[-3];
    v155 = stack[-8];
    v155 = list4(v158, v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[-8] = v155;
    goto v175;

v171:
    v158 = elt(env, 21); /* de */
    v157 = stack[-5];
    v156 = stack[-3];
    v155 = stack[-8];
    v155 = list4(v158, v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-9];
    stack[-8] = v155;
    goto v175;

v168:
    v155 = qvalue(elt(env, 5)); /* nil */
    goto v169;

v163:
    v155 = qvalue(elt(env, 5)); /* nil */
    goto v164;

v40:
    v155 = qvalue(elt(env, 5)); /* nil */
    goto v57;
/* error exit handlers */
v160:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-6]; /* fname!* */
    popv(10);
    return nil;
}



/* Code for sfto_ucontentf1 */

static Lisp_Object CC_sfto_ucontentf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_ucontentf1");
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
    goto v42;

v42:
    v180 = stack[-1];
    if (!consp(v180)) goto v50;
    v180 = stack[-1];
    v180 = qcar(v180);
    v180 = (consp(v180) ? nil : lisp_true);
    goto v31;

v31:
    if (v180 == nil) goto v182;
    v180 = qvalue(elt(env, 1)); /* t */
    goto v35;

v35:
    if (v180 == nil) goto v183;
    v180 = stack[-1];
    v181 = v180;
    goto v28;

v28:
    v180 = stack[-2];
    if (v180 == nil) { popv(4); return onevalue(v181); }
    v180 = stack[-2];
    v180 = qcar(v180);
    fn = elt(env, 2); /* sfto_gcdf!* */
    v180 = (*qfn2(fn))(qenv(fn), v180, v181);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    v181 = v180;
    v180 = stack[-2];
    v180 = qcdr(v180);
    stack[-2] = v180;
    goto v28;

v183:
    v180 = stack[-1];
    v180 = qcar(v180);
    v181 = qcdr(v180);
    v180 = stack[-2];
    v180 = cons(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    stack[-2] = v180;
    v180 = stack[-1];
    v180 = qcdr(v180);
    stack[-1] = v180;
    goto v42;

v182:
    v180 = stack[-1];
    v180 = qcar(v180);
    v180 = qcar(v180);
    v181 = qcar(v180);
    v180 = stack[0];
    v180 = Lneq(nil, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    goto v35;

v50:
    v180 = qvalue(elt(env, 1)); /* t */
    goto v31;
/* error exit handlers */
v184:
    popv(4);
    return nil;
}



/* Code for vp2 */

static Lisp_Object CC_vp2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vp2");
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
    v52 = nil;
    goto v10;

v10:
    v16 = stack[0];
    if (v16 == nil) goto v43;
    v16 = (Lisp_Object)1; /* 0 */
    v16 = cons(v16, v52);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    v52 = v16;
    v16 = stack[0];
    v16 = qcdr(v16);
    stack[0] = v16;
    goto v10;

v43:
    v16 = v52;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v16);
    }
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for get!*inverse */

static Lisp_Object CC_getHinverse(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v27, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*inverse");
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
    v27 = v1;
    v182 = v0;
/* end of prologue */
    v38 = v182;
    v182 = elt(env, 1); /* inverse */
    v182 = get(v38, v182);
    env = stack[-1];
    v38 = v182;
    v182 = v38;
    v182 = qcdr(v182);
    stack[0] = qcar(v182);
    v182 = v27;
    v27 = v38;
    v27 = qcar(v27);
    fn = elt(env, 2); /* give!*position */
    v182 = (*qfn2(fn))(qenv(fn), v182, v27);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    fn = elt(env, 3); /* pnth */
    v182 = (*qfn2(fn))(qenv(fn), stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v182 = qcar(v182);
    { popv(2); return onevalue(v182); }
/* error exit handlers */
v24:
    popv(2);
    return nil;
}



/* Code for ev_revgradlexcomp */

static Lisp_Object CC_ev_revgradlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_revgradlexcomp");
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

v187:
    v181 = stack[-2];
    if (v181 == nil) goto v28;
    v181 = stack[-2];
    v154 = qcar(v181);
    v181 = stack[-1];
    v181 = qcar(v181);
    v181 = Leqn(nil, v154, v181);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    if (v181 == nil) goto v34;
    v181 = stack[-2];
    v154 = qcdr(v181);
    v181 = stack[-1];
    v181 = qcdr(v181);
    stack[-2] = v154;
    stack[-1] = v181;
    goto v187;

v34:
    v181 = stack[-2];
    fn = elt(env, 1); /* ev_tdeg */
    v181 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-3] = v181;
    v181 = stack[-1];
    fn = elt(env, 1); /* ev_tdeg */
    v181 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[0] = v181;
    v154 = stack[-3];
    v181 = stack[0];
    v181 = Leqn(nil, v154, v181);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    if (v181 == nil) goto v45;
    v154 = stack[-2];
    v181 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* ev_invlexcomp */
        return (*qfn2(fn))(qenv(fn), v154, v181);
    }

v45:
    v154 = stack[-3];
    v181 = stack[0];
    if (((int32_t)(v154)) > ((int32_t)(v181))) goto v189;
    v181 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v181); }

v189:
    v181 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v181); }

v28:
    v181 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v181); }
/* error exit handlers */
v188:
    popv(5);
    return nil;
}



/* Code for omfir */

static Lisp_Object MS_CDECL CC_omfir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omfir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omfir");
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
    v27 = qvalue(elt(env, 1)); /* atts */
    v182 = elt(env, 2); /* dec */
    fn = elt(env, 5); /* find */
    v182 = (*qfn2(fn))(qenv(fn), v27, v182);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-1];
    stack[0] = v182;
    v27 = qvalue(elt(env, 1)); /* atts */
    v182 = elt(env, 3); /* name */
    fn = elt(env, 5); /* find */
    v182 = (*qfn2(fn))(qenv(fn), v27, v182);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-1];
    if (v182 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v27 = elt(env, 4); /* "wrong att" */
    v182 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v182 = (*qfn2(fn))(qenv(fn), v27, v182);
    nil = C_nil;
    if (exception_pending()) goto v48;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v48:
    popv(2);
    return nil;
}



/* Code for mkempspmat */

static Lisp_Object CC_mkempspmat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v50;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkempspmat");
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
    v31 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* sparsemat */
    v50 = Lmkvect(nil, v31);
    nil = C_nil;
    if (exception_pending()) goto v185;
    v31 = stack[0];
    {
        Lisp_Object v51 = stack[-1];
        popv(2);
        return list3(v51, v50, v31);
    }
/* error exit handlers */
v185:
    popv(2);
    return nil;
}



/* Code for formc!* */

static Lisp_Object MS_CDECL CC_formcH(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v49, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v50, v32, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formc*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formc*");
#endif
    if (stack >= stacklimit)
    {
        push3(v49,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v49);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v50 = v49;
    v32 = v1;
    v33 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*!*a2sfn */
    qvalue(elt(env, 1)) = nil; /* !*!*a2sfn */
    v31 = elt(env, 2); /* revalx */
    qvalue(elt(env, 1)) = v31; /* !*!*a2sfn */
    v31 = v33;
    fn = elt(env, 3); /* formc */
    v31 = (*qfnn(fn))(qenv(fn), 3, v31, v32, v50);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*!*a2sfn */
    { popv(2); return onevalue(v31); }
/* error exit handlers */
v51:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*!*a2sfn */
    popv(2);
    return nil;
}



/* Code for !*xadd */

static Lisp_Object CC_Hxadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v17, v159, v192;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *xadd");
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
    v192 = v1;
    stack[0] = v0;
/* end of prologue */
    v191 = v192;
    v159 = v191;
    goto v28;

v28:
    v191 = v159;
    if (v191 == nil) goto v43;
    v191 = stack[0];
    v17 = qcar(v191);
    v191 = v159;
    v191 = qcar(v191);
    v191 = qcar(v191);
    if (equal(v17, v191)) goto v43;
    v191 = v159;
    v191 = qcdr(v191);
    v159 = v191;
    goto v28;

v43:
    v191 = v159;
    if (v191 == nil) goto v8;
    v191 = v159;
    v191 = qcar(v191);
    v17 = v192;
    v191 = Ldelete(nil, v191, v17);
    nil = C_nil;
    if (exception_pending()) goto v56;
    v192 = v191;
    goto v8;

v8:
    v191 = stack[0];
    v17 = v192;
    popv(1);
    return cons(v191, v17);
/* error exit handlers */
v56:
    popv(1);
    return nil;
}



/* Code for contract!-strand */

static Lisp_Object CC_contractKstrand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contract-strand");
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
    v19 = v1;
    v20 = v0;
/* end of prologue */
    stack[0] = v20;
    fn = elt(env, 1); /* zero!-roads */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    {
        Lisp_Object v21 = stack[0];
        popv(2);
        fn = elt(env, 2); /* contr!-strand */
        return (*qfn2(fn))(qenv(fn), v21, v19);
    }
/* error exit handlers */
v35:
    popv(2);
    return nil;
}



/* Code for quotpri */

static Lisp_Object CC_quotpri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v56, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotpri");
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
    v56 = v0;
/* end of prologue */
    stack[0] = nil;
    v193 = qvalue(elt(env, 1)); /* !*ratpri */
    if (v193 == nil) goto v14;
    v193 = qvalue(elt(env, 3)); /* !*nat */
    if (v193 == nil) goto v31;
    v193 = qvalue(elt(env, 4)); /* !*fort */
    if (!(v193 == nil)) goto v15;
    v193 = qvalue(elt(env, 5)); /* !*list */
    if (!(v193 == nil)) goto v15;
    v193 = qvalue(elt(env, 6)); /* !*mcd */
    v193 = (v193 == nil ? lisp_true : nil);
    goto v15;

v15:
    if (v193 == nil) goto v25;
    v193 = elt(env, 7); /* failed */
    { popv(2); return onevalue(v193); }

v25:
    v2 = qvalue(elt(env, 8)); /* dmode!* */
    v193 = elt(env, 9); /* ratmode */
    v193 = Lflagp(nil, v2, v193);
    env = stack[-1];
    if (v193 == nil) goto v5;
    v193 = qvalue(elt(env, 8)); /* dmode!* */
    stack[0] = v193;
    v193 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 8)) = v193; /* dmode!* */
    goto v5;

v5:
    v193 = v56;
    fn = elt(env, 11); /* ratfunpri1 */
    v193 = (*qfn1(fn))(qenv(fn), v193);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-1];
    v56 = v193;
    v193 = stack[0];
    if (v193 == nil) { popv(2); return onevalue(v56); }
    v193 = stack[0];
    qvalue(elt(env, 8)) = v193; /* dmode!* */
    { popv(2); return onevalue(v56); }

v31:
    v193 = qvalue(elt(env, 2)); /* t */
    goto v15;

v14:
    v193 = qvalue(elt(env, 2)); /* t */
    goto v15;
/* error exit handlers */
v3:
    popv(2);
    return nil;
}



/* Code for red!=hidelt */

static Lisp_Object CC_redMhidelt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=hidelt");
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
    v54 = stack[-2];
    fn = elt(env, 1); /* bas_dpoly */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-4];
    stack[-3] = v54;
    v54 = stack[-2];
    fn = elt(env, 2); /* bas_nr */
    stack[-1] = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-4];
    v54 = stack[-3];
    stack[0] = qcdr(v54);
    v54 = stack[-2];
    fn = elt(env, 3); /* bas_rep */
    stack[-2] = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-4];
    v54 = stack[-3];
    v54 = qcar(v54);
    v54 = ncons(v54);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-4];
    fn = elt(env, 4); /* red!=hide */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-4];
    fn = elt(env, 5); /* dp_sum */
    v54 = (*qfn2(fn))(qenv(fn), stack[-2], v54);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-4];
    {
        Lisp_Object v38 = stack[-1];
        Lisp_Object v48 = stack[0];
        popv(5);
        fn = elt(env, 6); /* bas_make1 */
        return (*qfnn(fn))(qenv(fn), 3, v38, v48, v54);
    }
/* error exit handlers */
v27:
    popv(5);
    return nil;
}



/* Code for simp!-prop1 */

static Lisp_Object CC_simpKprop1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v261, v70, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop1");
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

v187:
    v261 = stack[-4];
    if (!consp(v261)) goto v262;
    v261 = stack[-4];
    v70 = qcar(v261);
    v261 = qvalue(elt(env, 1)); /* !'and */
    if (equal(v70, v261)) goto v50;
    v261 = qvalue(elt(env, 2)); /* nil */
    goto v31;

v31:
    if (!(v261 == nil)) goto v35;
    v261 = stack[-4];
    v70 = qcar(v261);
    v261 = qvalue(elt(env, 3)); /* !'or */
    if (equal(v70, v261)) goto v24;
    v261 = qvalue(elt(env, 2)); /* nil */
    goto v48;

v48:
    if (!(v261 == nil)) goto v35;
    v261 = stack[-4];
    v70 = qcar(v261);
    v261 = qvalue(elt(env, 3)); /* !'or */
    if (equal(v70, v261)) goto v263;
    v261 = qvalue(elt(env, 2)); /* nil */
    goto v264;

v264:
    if (!(v261 == nil)) goto v265;
    v261 = stack[-4];
    v70 = qcar(v261);
    v261 = qvalue(elt(env, 1)); /* !'and */
    if (equal(v70, v261)) goto v153;
    v261 = qvalue(elt(env, 2)); /* nil */
    goto v152;

v152:
    if (!(v261 == nil)) goto v265;
    v261 = stack[-4];
    v70 = qcar(v261);
    v261 = elt(env, 4); /* not */
    if (v70 == v261) goto v266;
    v261 = stack[-4];
    v70 = qcar(v261);
    v261 = elt(env, 5); /* implies */
    if (v70 == v261) goto v141;
    v261 = stack[-4];
    v70 = qcar(v261);
    v261 = elt(env, 8); /* equiv */
    if (!(v70 == v261)) goto v42;
    stack[-5] = elt(env, 6); /* or */
    v71 = elt(env, 9); /* and */
    v261 = stack[-4];
    v261 = qcdr(v261);
    v70 = qcar(v261);
    v261 = stack[-4];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    stack[-2] = list3(v71, v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    stack[-1] = elt(env, 9); /* and */
    v70 = elt(env, 4); /* not */
    v261 = stack[-4];
    v261 = qcdr(v261);
    v261 = qcar(v261);
    stack[0] = list2(v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    v70 = elt(env, 4); /* not */
    v261 = stack[-4];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v261 = list2(v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    v261 = list3(stack[-1], stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    v70 = list3(stack[-5], stack[-2], v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    v261 = stack[-3];
    v261 = CC_simpKprop1(env, v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    stack[0] = v261;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v42:
    v261 = stack[-4];
    fn = elt(env, 18); /* reval */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    stack[-4] = v261;
    v70 = stack[-4];
    v261 = elt(env, 14); /* boolean */
    if (!consp(v70)) goto v268;
    v70 = qcar(v70);
    if (!(v70 == v261)) goto v268;
    v261 = stack[-4];
    v261 = qcdr(v261);
    v70 = qcar(v261);
    v261 = stack[-3];
    stack[-4] = v70;
    stack[-3] = v261;
    goto v187;

v268:
    v261 = stack[-3];
    if (v261 == nil) goto v72;
    v261 = elt(env, 15); /* prop!* */
    v70 = v261;
    goto v269;

v269:
    v261 = stack[-4];
    v261 = list2(v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    fn = elt(env, 19); /* simp */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    v261 = qcar(v261);
    stack[0] = v261;
    v70 = stack[-4];
    v261 = qvalue(elt(env, 17)); /* propvars!* */
    v261 = Lmember(nil, v70, v261);
    if (!(v261 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v70 = stack[-4];
    v261 = qvalue(elt(env, 17)); /* propvars!* */
    v261 = cons(v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    qvalue(elt(env, 17)) = v261; /* propvars!* */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v72:
    v261 = elt(env, 16); /* not_prop!* */
    v70 = v261;
    goto v269;

v141:
    v261 = stack[-3];
    if (v261 == nil) goto v270;
    stack[0] = elt(env, 6); /* or */
    v70 = elt(env, 4); /* not */
    v261 = stack[-4];
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v70 = list2(v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    v261 = stack[-4];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v70 = list3(stack[0], v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    v261 = qvalue(elt(env, 7)); /* t */
    v261 = CC_simpKprop1(env, v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    stack[0] = v261;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v270:
    stack[0] = elt(env, 6); /* or */
    v70 = elt(env, 4); /* not */
    v261 = stack[-4];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v70 = list2(v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    v261 = stack[-4];
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v70 = list3(stack[0], v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    v261 = qvalue(elt(env, 7)); /* t */
    v261 = CC_simpKprop1(env, v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    stack[0] = v261;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v266:
    v261 = stack[-4];
    v261 = qcdr(v261);
    v70 = qcar(v261);
    v261 = stack[-3];
    v261 = (v261 == nil ? lisp_true : nil);
    v261 = CC_simpKprop1(env, v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    stack[0] = v261;
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v265:
    v261 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v261;
    v261 = stack[-4];
    v261 = qcdr(v261);
    stack[-1] = v261;
    goto v271;

v271:
    v261 = stack[-1];
    if (v261 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v261 = stack[-1];
    v261 = qcar(v261);
    v70 = v261;
    v261 = stack[-3];
    v261 = CC_simpKprop1(env, v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    fn = elt(env, 20); /* addf */
    v261 = (*qfn2(fn))(qenv(fn), stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    stack[0] = v261;
    v261 = stack[-1];
    v261 = qcdr(v261);
    stack[-1] = v261;
    goto v271;

v153:
    v261 = stack[-3];
    v261 = (v261 == nil ? lisp_true : nil);
    goto v152;

v263:
    v261 = stack[-3];
    goto v264;

v35:
    v261 = (Lisp_Object)17; /* 1 */
    stack[0] = v261;
    v261 = stack[-4];
    v261 = qcdr(v261);
    stack[-1] = v261;
    goto v192;

v192:
    v261 = stack[-1];
    if (v261 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v261 = stack[-1];
    v261 = qcar(v261);
    v70 = v261;
    v261 = stack[-3];
    v261 = CC_simpKprop1(env, v70, v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    fn = elt(env, 21); /* multf */
    v261 = (*qfn2(fn))(qenv(fn), stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-6];
    stack[0] = v261;
    v261 = stack[-1];
    v261 = qcdr(v261);
    stack[-1] = v261;
    goto v192;

v24:
    v261 = stack[-3];
    v261 = (v261 == nil ? lisp_true : nil);
    goto v48;

v50:
    v261 = stack[-3];
    goto v31;

v262:
    v70 = stack[-4];
    v261 = (Lisp_Object)17; /* 1 */
    if (v70 == v261) goto v272;
    v70 = stack[-4];
    v261 = qvalue(elt(env, 7)); /* t */
    if (equal(v70, v261)) goto v273;
    v70 = stack[-4];
    v261 = elt(env, 10); /* true */
    v261 = (v70 == v261 ? lisp_true : nil);
    goto v274;

v274:
    if (v261 == nil) goto v100;
    v261 = stack[-3];
    stack[-4] = v261;
    goto v275;

v275:
    v70 = stack[-4];
    v261 = qvalue(elt(env, 7)); /* t */
    if (equal(v70, v261)) goto v276;
    v261 = stack[-4];
    if (!(v261 == nil)) goto v42;
    v70 = elt(env, 13); /* (and !*true (not !*true)) */
    v261 = qvalue(elt(env, 7)); /* t */
    stack[-4] = v70;
    stack[-3] = v261;
    goto v187;

v276:
    v70 = elt(env, 12); /* (or !*true (not !*true)) */
    v261 = qvalue(elt(env, 7)); /* t */
    stack[-4] = v70;
    stack[-3] = v261;
    goto v187;

v100:
    v70 = stack[-4];
    v261 = (Lisp_Object)1; /* 0 */
    if (v70 == v261) goto v277;
    v261 = stack[-4];
    if (v261 == nil) goto v97;
    v70 = stack[-4];
    v261 = elt(env, 11); /* false */
    v261 = (v70 == v261 ? lisp_true : nil);
    goto v278;

v278:
    if (v261 == nil) goto v275;
    v261 = stack[-3];
    v261 = (v261 == nil ? lisp_true : nil);
    stack[-4] = v261;
    goto v275;

v97:
    v261 = qvalue(elt(env, 7)); /* t */
    goto v278;

v277:
    v261 = qvalue(elt(env, 7)); /* t */
    goto v278;

v273:
    v261 = qvalue(elt(env, 7)); /* t */
    goto v274;

v272:
    v261 = qvalue(elt(env, 7)); /* t */
    goto v274;
/* error exit handlers */
v267:
    popv(7);
    return nil;
}



/* Code for skp_ordp */

static Lisp_Object CC_skp_ordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v29, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for skp_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v1;
    v29 = v0;
/* end of prologue */
    v30 = qcar(v29);
    v29 = qcar(v21);
    v21 = elt(env, 1); /* atom_compare */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v30, v29, v21);
    }
}



/* Code for cl_flip */

static Lisp_Object CC_cl_flip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v282, v283, v246;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_flip");
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
    v246 = v0;
/* end of prologue */
    v283 = v246;
    v282 = elt(env, 1); /* and */
    if (v283 == v282) goto v11;
    v283 = v246;
    v282 = elt(env, 2); /* or */
    if (v283 == v282) goto v34;
    v283 = v246;
    v282 = elt(env, 3); /* all */
    if (v283 == v282) goto v51;
    v283 = v246;
    v282 = elt(env, 4); /* ex */
    if (v283 == v282) goto v27;
    v283 = v246;
    v282 = elt(env, 5); /* ball */
    if (v283 == v282) goto v183;
    v283 = v246;
    v282 = elt(env, 6); /* bex */
    if (v283 == v282) goto v17;
    v283 = v246;
    v282 = elt(env, 7); /* true */
    if (v283 == v282) goto v44;
    v283 = v246;
    v282 = elt(env, 8); /* false */
    if (v283 == v282) goto v181;
    v282 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v282 == nil)) goto v264;
    v282 = elt(env, 10); /* "cl_flip(): don't know" */
    v283 = v246;
    v282 = list2(v282, v283);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[0];
    fn = elt(env, 11); /* lprie */
    v282 = (*qfn1(fn))(qenv(fn), v282);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[0];
    goto v264;

v264:
    v282 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v152;
    v282 = nil;
    { popv(1); return onevalue(v282); }

v181:
    v282 = elt(env, 7); /* true */
    { popv(1); return onevalue(v282); }

v44:
    v282 = elt(env, 8); /* false */
    { popv(1); return onevalue(v282); }

v17:
    v282 = elt(env, 5); /* ball */
    { popv(1); return onevalue(v282); }

v183:
    v282 = elt(env, 6); /* bex */
    { popv(1); return onevalue(v282); }

v27:
    v282 = elt(env, 3); /* all */
    { popv(1); return onevalue(v282); }

v51:
    v282 = elt(env, 4); /* ex */
    { popv(1); return onevalue(v282); }

v34:
    v282 = elt(env, 1); /* and */
    { popv(1); return onevalue(v282); }

v11:
    v282 = elt(env, 2); /* or */
    { popv(1); return onevalue(v282); }
/* error exit handlers */
v152:
    popv(1);
    return nil;
}



/* Code for prepreform1 */

static Lisp_Object CC_prepreform1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v298, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepreform1");
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

v187:
    v298 = stack[0];
    if (!consp(v298)) goto v28;
    v298 = stack[0];
    v134 = qcar(v298);
    v298 = elt(env, 2); /* dname */
    v298 = get(v134, v298);
    env = stack[-7];
    goto v43;

v43:
    if (!(v298 == nil)) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    stack[-6] = nil;
    v298 = stack[-5];
    stack[-1] = v298;
    goto v27;

v27:
    v298 = stack[-6];
    if (v298 == nil) goto v58;
    v298 = qvalue(elt(env, 3)); /* nil */
    goto v57;

v57:
    if (v298 == nil) goto v182;
    v298 = stack[-1];
    v134 = qcar(v298);
    v298 = stack[0];
    v298 = qcdr(v298);
    v298 = Lsmemq(nil, v134, v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    if (v298 == nil) goto v44;
    v298 = qvalue(elt(env, 1)); /* t */
    stack[-6] = v298;
    goto v27;

v44:
    v298 = stack[-1];
    v298 = qcdr(v298);
    stack[-1] = v298;
    goto v27;

v182:
    v298 = stack[-6];
    if (v298 == nil) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v298 = stack[0];
    v134 = qcar(v298);
    v298 = elt(env, 4); /* (plus difference minus times quotient) */
    v298 = Lmemq(nil, v134, v298);
    if (!(v298 == nil)) goto v18;
    v298 = stack[0];
    v134 = qcar(v298);
    v298 = elt(env, 5); /* simpfn */
    v298 = get(v134, v298);
    env = stack[-7];
    if (!(v298 == nil)) goto v282;

v18:
    v298 = qvalue(elt(env, 3)); /* nil */
    stack[-6] = v298;
    goto v282;

v282:
    v298 = stack[0];
    v134 = qcar(v298);
    v298 = elt(env, 6); /* !*sq */
    if (v134 == v298) goto v299;
    v298 = stack[0];
    stack[-4] = qcar(v298);
    v298 = stack[0];
    v298 = qcdr(v298);
    stack[-3] = v298;
    v298 = stack[-3];
    if (v298 == nil) goto v300;
    v298 = stack[-3];
    v298 = qcar(v298);
    v134 = v298;
    v298 = stack[-6];
    if (v298 == nil) goto v266;
    v298 = v134;
    fn = elt(env, 7); /* simp!* */
    v298 = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    fn = elt(env, 8); /* sqhorner!* */
    v298 = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    fn = elt(env, 9); /* prepsq!* */
    v298 = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    v134 = v298;
    goto v301;

v301:
    v298 = stack[-5];
    v298 = CC_prepreform1(env, v134, v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    v298 = ncons(v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    stack[-1] = v298;
    stack[-2] = v298;
    goto v302;

v302:
    v298 = stack[-3];
    v298 = qcdr(v298);
    stack[-3] = v298;
    v298 = stack[-3];
    if (v298 == nil) goto v144;
    stack[0] = stack[-1];
    v298 = stack[-3];
    v298 = qcar(v298);
    v134 = v298;
    v298 = stack[-6];
    if (v298 == nil) goto v303;
    v298 = v134;
    fn = elt(env, 7); /* simp!* */
    v298 = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    fn = elt(env, 8); /* sqhorner!* */
    v298 = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    fn = elt(env, 9); /* prepsq!* */
    v298 = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    v134 = v298;
    goto v304;

v304:
    v298 = stack[-5];
    v298 = CC_prepreform1(env, v134, v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    v298 = ncons(v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    v298 = Lrplacd(nil, stack[0], v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    v298 = stack[-1];
    v298 = qcdr(v298);
    stack[-1] = v298;
    goto v302;

v303:
    v298 = v134;
    v134 = v298;
    goto v304;

v144:
    v298 = stack[-2];
    goto v161;

v161:
    {
        Lisp_Object v230 = stack[-4];
        popv(8);
        return cons(v230, v298);
    }

v266:
    v298 = v134;
    v134 = v298;
    goto v301;

v300:
    v298 = qvalue(elt(env, 3)); /* nil */
    goto v161;

v299:
    v298 = stack[0];
    v298 = qcdr(v298);
    v298 = qcar(v298);
    fn = elt(env, 8); /* sqhorner!* */
    v298 = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    fn = elt(env, 9); /* prepsq!* */
    v134 = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-7];
    v298 = stack[-5];
    stack[0] = v134;
    stack[-5] = v298;
    goto v187;

v58:
    v298 = stack[-1];
    goto v57;

v28:
    v298 = qvalue(elt(env, 1)); /* t */
    goto v43;
/* error exit handlers */
v232:
    popv(8);
    return nil;
}



/* Code for texstrlen */

static Lisp_Object CC_texstrlen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v191, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for texstrlen");
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
    v55 = v0;
/* end of prologue */
    v191 = (Lisp_Object)1; /* 0 */
    v17 = v191;
    v191 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v55;
    goto v19;

v19:
    v55 = stack[0];
    if (v55 == nil) { popv(2); return onevalue(v17); }
    v55 = stack[0];
    v55 = qcar(v55);
    if (v191 == nil) goto v281;
    v55 = qvalue(elt(env, 1)); /* nil */
    goto v41;

v41:
    if (v55 == nil) goto v183;
    v55 = qvalue(elt(env, 3)); /* t */
    v191 = v55;
    goto v51;

v51:
    v55 = stack[0];
    v55 = qcdr(v55);
    stack[0] = v55;
    goto v19;

v183:
    v55 = v17;
    v55 = add1(v55);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-1];
    v17 = v55;
    v55 = qvalue(elt(env, 1)); /* nil */
    v191 = v55;
    goto v51;

v281:
    v191 = v55;
    v55 = elt(env, 2); /* !! */
    v55 = (v191 == v55 ? lisp_true : nil);
    goto v41;
/* error exit handlers */
v192:
    popv(2);
    return nil;
}



/* Code for multfnc */

static Lisp_Object CC_multfnc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v234, v321;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multfnc");
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
    v166 = stack[-2];
    v166 = qcar(v166);
    stack[0] = qcdr(v166);
    v166 = stack[-1];
    v166 = qcar(v166);
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    fn = elt(env, 5); /* multf */
    v166 = (*qfn2(fn))(qenv(fn), stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    stack[-3] = v166;
    v166 = stack[-3];
    if (v166 == nil) goto v285;
    v166 = stack[-3];
    if (!consp(v166)) goto v182;
    v166 = stack[-3];
    v166 = qcar(v166);
    v166 = (consp(v166) ? nil : lisp_true);
    goto v281;

v281:
    if (v166 == nil) goto v26;
    v166 = qvalue(elt(env, 1)); /* nil */
    goto v41;

v41:
    if (v166 == nil) goto v52;
    v166 = stack[-2];
    v166 = qcar(v166);
    v166 = qcar(v166);
    stack[0] = qcar(v166);
    v166 = stack[-2];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v234 = qcdr(v166);
    v166 = stack[-3];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v166 = qcdr(v166);
    v166 = plus2(v234, v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    fn = elt(env, 6); /* mkspm */
    v166 = (*qfn2(fn))(qenv(fn), stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    v321 = v166;
    if (v166 == nil) goto v253;
    v234 = v321;
    v166 = (Lisp_Object)17; /* 1 */
    if (v234 == v166) goto v323;
    v234 = v321;
    v166 = stack[-3];
    v166 = qcar(v166);
    v166 = qcdr(v166);
    v166 = cons(v234, v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    stack[0] = v166;
    goto v324;

v324:
    v166 = stack[-2];
    v166 = qcar(v166);
    v234 = qcar(v166);
    v166 = (Lisp_Object)17; /* 1 */
    v166 = cons(v234, v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    v234 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    v166 = stack[-3];
    v166 = qcdr(v166);
    fn = elt(env, 5); /* multf */
    v166 = (*qfn2(fn))(qenv(fn), v234, v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    fn = elt(env, 7); /* addf */
    v166 = (*qfn2(fn))(qenv(fn), stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    stack[-3] = v166;
    goto v285;

v285:
    v166 = stack[-2];
    v234 = qcdr(v166);
    v166 = stack[-1];
    fn = elt(env, 5); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v234, v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    v166 = stack[-2];
    v166 = qcar(v166);
    v234 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    v166 = stack[-1];
    v166 = qcdr(v166);
    fn = elt(env, 5); /* multf */
    v166 = (*qfn2(fn))(qenv(fn), v234, v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    fn = elt(env, 7); /* addf */
    v166 = (*qfn2(fn))(qenv(fn), stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    {
        Lisp_Object v325 = stack[-3];
        popv(5);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v325, v166);
    }

v323:
    v166 = stack[-3];
    v166 = qcar(v166);
    v166 = qcdr(v166);
    stack[0] = v166;
    goto v324;

v253:
    v166 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v166;
    goto v324;

v52:
    v166 = qvalue(elt(env, 3)); /* !*ncmp */
    if (v166 == nil) goto v326;
    v166 = stack[-2];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v166 = qcar(v166);
    fn = elt(env, 8); /* noncomp1 */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    if (v166 == nil) goto v326;
    v166 = stack[-2];
    v166 = qcar(v166);
    v234 = qcar(v166);
    v166 = stack[-3];
    v166 = cons(v234, v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-4];
    stack[-3] = v166;
    goto v285;

v326:
    v166 = qvalue(elt(env, 2)); /* t */
    stack[0] = qvalue(elt(env, 4)); /* !*!*processed */
    qvalue(elt(env, 4)) = v166; /* !*!*processed */
    v166 = stack[-2];
    v166 = qcar(v166);
    v234 = qcar(v166);
    v166 = (Lisp_Object)17; /* 1 */
    v166 = cons(v234, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-4];
    v234 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-4];
    v166 = stack[-3];
    fn = elt(env, 5); /* multf */
    v166 = (*qfn2(fn))(qenv(fn), v234, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-4];
    stack[-3] = v166;
    qvalue(elt(env, 4)) = stack[0]; /* !*!*processed */
    goto v285;

v26:
    v166 = stack[-3];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v234 = qcar(v166);
    v166 = stack[-2];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v166 = qcar(v166);
    v166 = (v234 == v166 ? lisp_true : nil);
    goto v41;

v182:
    v166 = qvalue(elt(env, 2)); /* t */
    goto v281;
/* error exit handlers */
v327:
    env = stack[-4];
    qvalue(elt(env, 4)) = stack[0]; /* !*!*processed */
    popv(5);
    return nil;
v322:
    popv(5);
    return nil;
}



/* Code for offexpchk */

static Lisp_Object CC_offexpchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for offexpchk");
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
    v38 = qvalue(elt(env, 1)); /* !*really_off_exp */
    if (!(v38 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v38 = qvalue(elt(env, 2)); /* frlis!* */
    if (v38 == nil) goto v28;
    v38 = stack[0];
    v38 = qcar(v38);
    fn = elt(env, 3); /* freevarinexptchk */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-2];
    if (!(v38 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v28:
    v38 = stack[0];
    v38 = qcdr(v38);
    fn = elt(env, 3); /* freevarinexptchk */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-2];
    if (!(v38 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v38 = stack[0];
    v38 = qcar(v38);
    fn = elt(env, 4); /* mkprod */
    stack[-1] = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-2];
    v38 = stack[0];
    v38 = qcdr(v38);
    fn = elt(env, 4); /* mkprod */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-2];
    {
        Lisp_Object v25 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* canprod */
        return (*qfn2(fn))(qenv(fn), v25, v38);
    }
/* error exit handlers */
v6:
    popv(3);
    return nil;
}



/* Code for tmsf */

static Lisp_Object CC_tmsf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v241, v145;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tmsf");
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
    v240 = (Lisp_Object)1; /* 0 */
    v145 = v240;
    goto v28;

v28:
    v240 = stack[-1];
    if (!consp(v240)) goto v21;
    v240 = stack[-1];
    v240 = qcar(v240);
    v240 = (consp(v240) ? nil : lisp_true);
    goto v35;

v35:
    if (v240 == nil) goto v53;
    v240 = stack[-1];
    if (v240 == nil) { popv(4); return onevalue(v145); }
    v240 = v145;
    popv(4);
    return add1(v240);

v53:
    stack[-2] = v145;
    v240 = stack[-1];
    v240 = qcar(v240);
    v240 = qcar(v240);
    v240 = qcar(v240);
    v145 = v240;
    v241 = v240;
    v240 = v241;
    if (!consp(v240)) goto v193;
    v240 = v241;
    v240 = qcar(v240);
    v240 = (consp(v240) ? nil : lisp_true);
    v240 = (v240 == nil ? lisp_true : nil);
    goto v331;

v331:
    if (v240 == nil) goto v36;
    v240 = v145;
    v240 = CC_tmsf(env, v240);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-3];
    stack[0] = v240;
    goto v48;

v48:
    v240 = stack[-1];
    v240 = qcar(v240);
    v240 = qcdr(v240);
    if (!(is_number(v240))) goto v296;
    v240 = stack[-1];
    v240 = qcar(v240);
    v240 = qcdr(v240);
    v240 = Ltruncate(nil, v240);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-3];
    v241 = Labsval(nil, v240);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-3];
    v240 = (Lisp_Object)17; /* 1 */
    if (!(v241 == v240)) goto v296;
    v240 = (Lisp_Object)1; /* 0 */
    goto v24;

v24:
    v240 = plus2(stack[0], v240);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-3];
    v240 = plus2(stack[-2], v240);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-3];
    v145 = v240;
    v240 = stack[-1];
    v240 = qcar(v240);
    v240 = qcar(v240);
    v241 = qcdr(v240);
    v240 = (Lisp_Object)17; /* 1 */
    if (v241 == v240) goto v332;
    v240 = stack[-1];
    v240 = qcar(v240);
    v240 = qcar(v240);
    v241 = qcdr(v240);
    v240 = (Lisp_Object)33; /* 2 */
    if (v241 == v240) goto v333;
    v241 = v145;
    v240 = (Lisp_Object)33; /* 2 */
    v240 = plus2(v241, v240);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-3];
    v145 = v240;
    goto v332;

v332:
    v240 = stack[-1];
    v240 = qcdr(v240);
    stack[-1] = v240;
    goto v28;

v333:
    v240 = v145;
    v240 = add1(v240);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-3];
    v145 = v240;
    goto v332;

v296:
    v240 = stack[-1];
    v240 = qcar(v240);
    v240 = qcdr(v240);
    v240 = CC_tmsf(env, v240);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-3];
    goto v24;

v36:
    v240 = (Lisp_Object)17; /* 1 */
    stack[0] = v240;
    goto v48;

v193:
    v240 = qvalue(elt(env, 2)); /* nil */
    goto v331;

v21:
    v240 = qvalue(elt(env, 1)); /* t */
    goto v35;
/* error exit handlers */
v291:
    popv(4);
    return nil;
}



/* Code for pasf_pdp */

static Lisp_Object CC_pasf_pdp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v322, v325, v327;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_pdp");
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
    v322 = stack[0];
    if (!consp(v322)) goto v19;
    v322 = stack[0];
    v322 = qcar(v322);
    v322 = (consp(v322) ? nil : lisp_true);
    goto v14;

v14:
    if (v322 == nil) goto v42;
    v322 = stack[0];
    if (v322 == nil) goto v185;
    v325 = stack[0];
    v322 = (Lisp_Object)1; /* 0 */
    v322 = (Lisp_Object)lessp2(v325, v322);
    nil = C_nil;
    if (exception_pending()) goto v133;
    v322 = v322 ? lisp_true : nil;
    env = stack[-2];
    if (v322 == nil) goto v58;
    v322 = elt(env, 3); /* ndef */
    { popv(3); return onevalue(v322); }

v58:
    v325 = stack[0];
    v322 = (Lisp_Object)1; /* 0 */
    v322 = (Lisp_Object)greaterp2(v325, v322);
    nil = C_nil;
    if (exception_pending()) goto v133;
    v322 = v322 ? lisp_true : nil;
    env = stack[-2];
    if (v322 == nil) goto v331;
    v322 = elt(env, 4); /* pdef */
    { popv(3); return onevalue(v322); }

v331:
    v322 = elt(env, 2); /* indef */
    { popv(3); return onevalue(v322); }

v185:
    v322 = elt(env, 2); /* indef */
    { popv(3); return onevalue(v322); }

v42:
    v322 = stack[0];
    v322 = qcar(v322);
    v322 = qcar(v322);
    v322 = qcdr(v322);
    v322 = Levenp(nil, v322);
    env = stack[-2];
    if (v322 == nil) goto v191;
    v322 = stack[0];
    v322 = qcar(v322);
    v322 = qcdr(v322);
    v322 = CC_pasf_pdp(env, v322);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-2];
    stack[-1] = v322;
    v322 = stack[0];
    v322 = qcdr(v322);
    v322 = CC_pasf_pdp(env, v322);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-2];
    v327 = v322;
    v322 = v327;
    if (v322 == nil) goto v251;
    v322 = qvalue(elt(env, 6)); /* nil */
    goto v180;

v180:
    if (v322 == nil) goto v13;
    v322 = elt(env, 5); /* psdef */
    { popv(3); return onevalue(v322); }

v13:
    v322 = v327;
    if (v322 == nil) goto v248;
    v322 = qvalue(elt(env, 6)); /* nil */
    goto v333;

v333:
    if (v322 == nil) goto v145;
    v322 = elt(env, 7); /* nsdef */
    { popv(3); return onevalue(v322); }

v145:
    v325 = v327;
    v322 = elt(env, 4); /* pdef */
    if (v325 == v322) goto v146;
    v322 = qvalue(elt(env, 6)); /* nil */
    goto v300;

v300:
    if (v322 == nil) goto v305;
    v322 = elt(env, 4); /* pdef */
    { popv(3); return onevalue(v322); }

v305:
    v325 = v327;
    v322 = elt(env, 3); /* ndef */
    if (v325 == v322) goto v139;
    v322 = qvalue(elt(env, 6)); /* nil */
    goto v235;

v235:
    if (v322 == nil) goto v191;
    v322 = elt(env, 3); /* ndef */
    { popv(3); return onevalue(v322); }

v191:
    v322 = elt(env, 2); /* indef */
    { popv(3); return onevalue(v322); }

v139:
    v325 = stack[-1];
    v322 = elt(env, 7); /* nsdef */
    if (v325 == v322) goto v342;
    v325 = stack[-1];
    v322 = elt(env, 3); /* ndef */
    v322 = (v325 == v322 ? lisp_true : nil);
    goto v235;

v342:
    v322 = qvalue(elt(env, 1)); /* t */
    goto v235;

v146:
    v325 = stack[-1];
    v322 = elt(env, 5); /* psdef */
    if (v325 == v322) goto v343;
    v325 = stack[-1];
    v322 = elt(env, 4); /* pdef */
    v322 = (v325 == v322 ? lisp_true : nil);
    goto v300;

v343:
    v322 = qvalue(elt(env, 1)); /* t */
    goto v300;

v248:
    v325 = stack[-1];
    v322 = elt(env, 7); /* nsdef */
    if (v325 == v322) goto v344;
    v325 = stack[-1];
    v322 = elt(env, 3); /* ndef */
    v322 = (v325 == v322 ? lisp_true : nil);
    goto v333;

v344:
    v322 = qvalue(elt(env, 1)); /* t */
    goto v333;

v251:
    v325 = stack[-1];
    v322 = elt(env, 5); /* psdef */
    if (v325 == v322) goto v319;
    v325 = stack[-1];
    v322 = elt(env, 4); /* pdef */
    v322 = (v325 == v322 ? lisp_true : nil);
    goto v180;

v319:
    v322 = qvalue(elt(env, 1)); /* t */
    goto v180;

v19:
    v322 = qvalue(elt(env, 1)); /* t */
    goto v14;
/* error exit handlers */
v133:
    popv(3);
    return nil;
}



/* Code for opfneval */

static Lisp_Object CC_opfneval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v354, v355;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opfneval");
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
    stack[-2] = v0;
/* end of prologue */
    v129 = stack[-2];
    v354 = qcar(v129);
    v129 = elt(env, 1); /* remember */
    v129 = Lflagp(nil, v354, v129);
    env = stack[-5];
    if (v129 == nil) goto v141;
    v129 = stack[-2];
    v354 = qcar(v129);
    v129 = elt(env, 2); /* noval */
    v129 = Lflagp(nil, v354, v129);
    env = stack[-5];
    if (v129 == nil) goto v58;
    v129 = stack[-2];
    v129 = qcdr(v129);
    goto v53;

v53:
    stack[-4] = v129;
    v129 = stack[-4];
    if (v129 == nil) goto v7;
    v129 = stack[-4];
    v129 = qcar(v129);
    v354 = v129;
    v129 = v354;
    v129 = integerp(v129);
    if (v129 == nil) goto v189;
    v129 = v354;
    goto v193;

v193:
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    stack[-1] = v129;
    stack[-3] = v129;
    goto v16;

v16:
    v129 = stack[-4];
    v129 = qcdr(v129);
    stack[-4] = v129;
    v129 = stack[-4];
    if (v129 == nil) goto v186;
    stack[0] = stack[-1];
    v129 = stack[-4];
    v129 = qcar(v129);
    v354 = v129;
    v129 = v354;
    v129 = integerp(v129);
    if (v129 == nil) goto v332;
    v129 = v354;
    goto v341;

v341:
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v129 = Lrplacd(nil, stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v16;

v332:
    v129 = v354;
    v129 = Lmkquote(nil, v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    goto v341;

v186:
    v129 = stack[-3];
    goto v51;

v51:
    stack[-4] = v129;
    v129 = stack[-2];
    v354 = qcar(v129);
    v129 = stack[-4];
    v355 = cons(v354, v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v129 = stack[-2];
    v354 = qcar(v129);
    v129 = elt(env, 4); /* kvalue */
    v129 = get(v354, v129);
    env = stack[-5];
    v129 = Lassoc(nil, v355, v129);
    v354 = v129;
    if (v129 == nil) goto v284;
    v129 = v354;
    v129 = qcdr(v129);
    v129 = qcar(v129);
    { popv(6); return onevalue(v129); }

v284:
    v129 = stack[-2];
    v354 = qcar(v129);
    v129 = stack[-4];
    v129 = cons(v354, v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    fn = elt(env, 5); /* eval */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    stack[-3] = v129;
    v129 = stack[-2];
    stack[-1] = qcar(v129);
    v129 = stack[-2];
    v354 = qcar(v129);
    v129 = elt(env, 4); /* kvalue */
    stack[0] = get(v354, v129);
    env = stack[-5];
    v129 = stack[-2];
    v354 = qcar(v129);
    v129 = stack[-4];
    v354 = cons(v354, v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v129 = stack[-3];
    fn = elt(env, 6); /* put!-kvalue */
    v129 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v354, v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v189:
    v129 = v354;
    v129 = Lmkquote(nil, v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    goto v193;

v7:
    v129 = qvalue(elt(env, 3)); /* nil */
    goto v51;

v58:
    v129 = stack[-2];
    v129 = qcdr(v129);
    fn = elt(env, 7); /* revlis */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    goto v53;

v141:
    v129 = stack[-2];
    stack[-4] = qcar(v129);
    v129 = stack[-2];
    v354 = qcar(v129);
    v129 = elt(env, 2); /* noval */
    v129 = Lflagp(nil, v354, v129);
    env = stack[-5];
    if (v129 == nil) goto v303;
    v129 = stack[-2];
    v129 = qcdr(v129);
    goto v137;

v137:
    stack[-3] = v129;
    v129 = stack[-3];
    if (v129 == nil) goto v134;
    v129 = stack[-3];
    v129 = qcar(v129);
    v129 = Lmkquote(nil, v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    stack[-1] = v129;
    stack[-2] = v129;
    goto v287;

v287:
    v129 = stack[-3];
    v129 = qcdr(v129);
    stack[-3] = v129;
    v129 = stack[-3];
    if (v129 == nil) goto v132;
    stack[0] = stack[-1];
    v129 = stack[-3];
    v129 = qcar(v129);
    v129 = Lmkquote(nil, v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v129 = Lrplacd(nil, stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v287;

v132:
    v129 = stack[-2];
    goto v313;

v313:
    v129 = cons(stack[-4], v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 5); /* eval */
        return (*qfn1(fn))(qenv(fn), v129);
    }

v134:
    v129 = qvalue(elt(env, 3)); /* nil */
    goto v313;

v303:
    v129 = stack[-2];
    v129 = qcdr(v129);
    fn = elt(env, 7); /* revlis */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    goto v137;
/* error exit handlers */
v126:
    popv(6);
    return nil;
}



/* Code for ps!:evaluate!-next */

static Lisp_Object CC_psTevaluateKnext(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v49)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:evaluate-next");
#endif
    if (stack >= stacklimit)
    {
        push2(v49,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v49);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v49;
    v192 = v1;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v192; /* ps */
    v193 = qvalue(elt(env, 1)); /* ps */
    v192 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 3); /* ps!:getv */
    v192 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-4];
    v193 = qcar(v192);
    v192 = elt(env, 2); /* ps!:erule */
    stack[0] = get(v193, v192);
    env = stack[-4];
    v192 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:expression */
    v193 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-4];
    v192 = stack[-2];
    v192 = list2(v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-4];
    fn = elt(env, 5); /* apply */
    v192 = (*qfn2(fn))(qenv(fn), stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-4];
    stack[-1] = v192;
    stack[0] = qvalue(elt(env, 1)); /* ps */
    v192 = stack[-1];
    fn = elt(env, 6); /* prepsqxx */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-4];
    fn = elt(env, 7); /* simp!* */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-4];
    stack[-1] = v192;
    fn = elt(env, 8); /* ps!:set!-term */
    v192 = (*qfnn(fn))(qenv(fn), 3, stack[0], stack[-2], v192);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-4];
    v192 = stack[-1];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v192); }
/* error exit handlers */
v36:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for derad */

static Lisp_Object CC_derad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v357, v358, v336;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for derad");
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
    goto v5;

v5:
    v357 = stack[0];
    if (v357 == nil) goto v20;
    v357 = stack[0];
    v357 = qcar(v357);
    if (is_number(v357)) goto v52;
    v358 = stack[-1];
    v357 = stack[0];
    v357 = qcar(v357);
    if (equal(v358, v357)) goto v48;
    v358 = stack[-1];
    v357 = stack[0];
    v357 = qcar(v357);
    fn = elt(env, 1); /* ordp */
    v357 = (*qfn2(fn))(qenv(fn), v358, v357);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    if (v357 == nil) goto v328;
    v358 = stack[-1];
    v357 = stack[0];
    v357 = cons(v358, v357);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    {
        Lisp_Object v164 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v164, v357);
    }

v328:
    v357 = stack[0];
    v358 = qcar(v357);
    v357 = stack[-2];
    v357 = cons(v358, v357);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[-2] = v357;
    v357 = stack[0];
    v357 = qcdr(v357);
    stack[0] = v357;
    goto v5;

v48:
    v357 = stack[0];
    v357 = qcdr(v357);
    if (v357 == nil) goto v263;
    v357 = stack[0];
    v357 = qcdr(v357);
    v357 = qcar(v357);
    if (!(is_number(v357))) goto v263;
    v357 = stack[0];
    v357 = qcdr(v357);
    v357 = qcar(v357);
    v358 = add1(v357);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v357 = stack[0];
    v357 = qcdr(v357);
    v357 = qcdr(v357);
    v357 = list2star(stack[-1], v358, v357);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    {
        Lisp_Object v359 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v359, v357);
    }

v263:
    v336 = stack[-1];
    v358 = (Lisp_Object)33; /* 2 */
    v357 = stack[0];
    v357 = qcdr(v357);
    v357 = list2star(v336, v358, v357);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    {
        Lisp_Object v360 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v360, v357);
    }

v52:
    v357 = stack[0];
    v358 = qcar(v357);
    v357 = stack[-2];
    v357 = cons(v358, v357);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[-2] = v357;
    v357 = stack[0];
    v357 = qcdr(v357);
    stack[0] = v357;
    goto v5;

v20:
    stack[0] = stack[-2];
    v357 = stack[-1];
    v357 = ncons(v357);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    {
        Lisp_Object v291 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v291, v357);
    }
/* error exit handlers */
v145:
    popv(4);
    return nil;
}



/* Code for make!-unique!-freevars */

static Lisp_Object CC_makeKuniqueKfreevars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v299, v361, v344;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-unique-freevars");
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
    v361 = v0;
/* end of prologue */
    v299 = v361;
    if (!consp(v299)) goto v19;
    v299 = v361;
    stack[-3] = v299;
    v299 = stack[-3];
    if (v299 == nil) goto v319;
    v299 = stack[-3];
    v299 = qcar(v299);
    v299 = CC_makeKuniqueKfreevars(env, v299);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-4];
    v299 = ncons(v299);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-4];
    stack[-1] = v299;
    stack[-2] = v299;
    goto v154;

v154:
    v299 = stack[-3];
    v299 = qcdr(v299);
    stack[-3] = v299;
    v299 = stack[-3];
    if (v299 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v299 = stack[-3];
    v299 = qcar(v299);
    v299 = CC_makeKuniqueKfreevars(env, v299);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-4];
    v299 = ncons(v299);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-4];
    v299 = Lrplacd(nil, stack[0], v299);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-4];
    v299 = stack[-1];
    v299 = qcdr(v299);
    stack[-1] = v299;
    goto v154;

v319:
    v299 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v299); }

v19:
    v344 = v361;
    v299 = elt(env, 1); /* gen */
    v299 = get(v344, v299);
    env = stack[-4];
    if (v299 == nil) { popv(5); return onevalue(v361); }
    v344 = v361;
    v299 = qvalue(elt(env, 2)); /* freevarlist!* */
    v299 = Latsoc(nil, v344, v299);
    stack[0] = v299;
    v299 = stack[0];
    if (!(v299 == nil)) goto v23;
    stack[0] = v361;
    fn = elt(env, 5); /* pm!:gensym */
    v299 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-4];
    v299 = cons(stack[0], v299);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-4];
    stack[0] = v299;
    v299 = stack[0];
    v344 = qcdr(v299);
    v361 = elt(env, 1); /* gen */
    v299 = qvalue(elt(env, 3)); /* t */
    v299 = Lputprop(nil, 3, v344, v361, v299);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-4];
    v361 = stack[0];
    v299 = qvalue(elt(env, 2)); /* freevarlist!* */
    v299 = cons(v361, v299);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-4];
    qvalue(elt(env, 2)) = v299; /* freevarlist!* */
    goto v23;

v23:
    v299 = stack[0];
    v299 = qcdr(v299);
    { popv(5); return onevalue(v299); }
/* error exit handlers */
v315:
    popv(5);
    return nil;
}



/* Code for vdpequal */

static Lisp_Object CC_vdpequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v186, v280;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpequal");
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
    v186 = stack[-1];
    v47 = stack[0];
    if (v186 == v47) goto v10;
    v186 = stack[-1];
    v47 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    stack[-2] = (*qfn2(fn))(qenv(fn), v186, v47);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-3];
    v186 = stack[0];
    v47 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    v47 = (*qfn2(fn))(qenv(fn), v186, v47);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-3];
    v280 = stack[-2];
    v186 = v47;
    v47 = v280;
    if (v47 == nil) goto v57;
    v47 = v280;
    v47 = (equal(v47, v186) ? lisp_true : nil);
    goto v25;

v25:
    if (!(v47 == nil)) { popv(4); return onevalue(v47); }
    v47 = stack[-1];
    v47 = qcdr(v47);
    v47 = qcdr(v47);
    v47 = qcdr(v47);
    v186 = qcar(v47);
    v47 = stack[0];
    v47 = qcdr(v47);
    v47 = qcdr(v47);
    v47 = qcdr(v47);
    v47 = qcar(v47);
    {
        popv(4);
        fn = elt(env, 5); /* dipequal */
        return (*qfn2(fn))(qenv(fn), v186, v47);
    }

v57:
    v47 = qvalue(elt(env, 3)); /* nil */
    goto v25;

v10:
    v47 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v47); }
/* error exit handlers */
v18:
    popv(4);
    return nil;
}



/* Code for my_letmtr */

static Lisp_Object MS_CDECL CC_my_letmtr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v49, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v364, v350, v290, v349, v365;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "my_letmtr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my_letmtr");
#endif
    if (stack >= stacklimit)
    {
        push3(v49,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v49);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v49;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[0] = nil;
    v350 = stack[-3];
    v364 = elt(env, 1); /* mat */
    if (!consp(v350)) goto v50;
    v350 = qcar(v350);
    if (!(v350 == v364)) goto v50;
    v364 = stack[-5];
    v364 = qcdr(v364);
    stack[-6] = v364;
    v364 = stack[-6];
    if (v364 == nil) goto v37;
    v364 = stack[-6];
    v364 = qcar(v364);
    v350 = v364;
    v364 = v350;
    v364 = integerp(v364);
    if (v364 == nil) goto v154;
    v364 = v350;
    goto v13;

v13:
    v364 = ncons(v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    stack[-1] = v364;
    stack[-2] = v364;
    goto v159;

v159:
    v364 = stack[-6];
    v364 = qcdr(v364);
    stack[-6] = v364;
    v364 = stack[-6];
    if (v364 == nil) goto v366;
    stack[0] = stack[-1];
    v364 = stack[-6];
    v364 = qcar(v364);
    v350 = v364;
    v364 = v350;
    v364 = integerp(v364);
    if (v364 == nil) goto v246;
    v364 = v350;
    goto v150;

v150:
    v364 = ncons(v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    v364 = Lrplacd(nil, stack[0], v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    v364 = stack[-1];
    v364 = qcdr(v364);
    stack[-1] = v364;
    goto v159;

v246:
    v364 = v350;
    fn = elt(env, 11); /* reval */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    goto v150;

v366:
    v364 = stack[-2];
    goto v17;

v17:
    stack[0] = v364;
    fn = elt(env, 12); /* numlis */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    if (v364 == nil) goto v9;
    v364 = stack[0];
    v350 = Llength(nil, v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    v364 = (Lisp_Object)33; /* 2 */
    v364 = Lneq(nil, v350, v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    goto v254;

v254:
    if (v364 == nil) goto v337;
    v365 = elt(env, 8); /* "Syntax error:" */
    v349 = stack[-5];
    v290 = elt(env, 9); /* "invalid" */
    v350 = qvalue(elt(env, 6)); /* nil */
    v364 = elt(env, 10); /* hold */
    {
        popv(8);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v365, v349, v290, v350, v364);
    }

v337:
    v364 = stack[-3];
    v350 = qcdr(v364);
    v364 = stack[0];
    v364 = qcar(v364);
    fn = elt(env, 14); /* pnth */
    v364 = (*qfn2(fn))(qenv(fn), v350, v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    v350 = qcar(v364);
    v364 = stack[0];
    v364 = qcdr(v364);
    v364 = qcar(v364);
    fn = elt(env, 14); /* pnth */
    v350 = (*qfn2(fn))(qenv(fn), v350, v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    v364 = stack[-4];
    v364 = Lrplaca(nil, v350, v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    v364 = nil;
    { popv(8); return onevalue(v364); }

v9:
    v364 = qvalue(elt(env, 7)); /* t */
    goto v254;

v154:
    v364 = v350;
    fn = elt(env, 11); /* reval */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    goto v13;

v37:
    v364 = qvalue(elt(env, 6)); /* nil */
    goto v17;

v50:
    v290 = elt(env, 2); /* "Matrix" */
    v364 = stack[-5];
    v350 = qcar(v364);
    v364 = elt(env, 3); /* "not set" */
    v364 = list3(v290, v350, v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    v350 = v364;
    v364 = v350;
    qvalue(elt(env, 4)) = v364; /* errmsg!* */
    v364 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v364 == nil)) goto v48;
    v364 = v350;
    fn = elt(env, 15); /* lprie */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    goto v48;

v48:
    v364 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-7];
    goto v337;
/* error exit handlers */
v313:
    popv(8);
    return nil;
}



/* Code for dip2vdp */

static Lisp_Object CC_dip2vdp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v253;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip2vdp");
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
    v253 = v0;
/* end of prologue */
    v46 = qvalue(elt(env, 1)); /* !*groebsubs */
    if (v46 == nil) goto v28;
    v46 = v253;
    fn = elt(env, 4); /* dipsubs2 */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-3];
    goto v4;

v4:
    v253 = v46;
    v46 = v253;
    if (v46 == nil) goto v31;
    stack[-2] = elt(env, 2); /* vdp */
    v46 = v253;
    stack[-1] = qcar(v46);
    v46 = v253;
    v46 = qcdr(v46);
    stack[0] = qcar(v46);
    v46 = qvalue(elt(env, 3)); /* nil */
    v46 = list2(v253, v46);
    nil = C_nil;
    if (exception_pending()) goto v186;
    {
        Lisp_Object v280 = stack[-2];
        Lisp_Object v180 = stack[-1];
        Lisp_Object v181 = stack[0];
        popv(4);
        return list3star(v280, v180, v181, v46);
    }

v31:
    stack[-2] = elt(env, 2); /* vdp */
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    v46 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 5); /* a2bc */
    stack[0] = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-3];
    v253 = qvalue(elt(env, 3)); /* nil */
    v46 = qvalue(elt(env, 3)); /* nil */
    v46 = list2(v253, v46);
    nil = C_nil;
    if (exception_pending()) goto v186;
    {
        Lisp_Object v154 = stack[-2];
        Lisp_Object v18 = stack[-1];
        Lisp_Object v340 = stack[0];
        popv(4);
        return list3star(v154, v18, v340, v46);
    }

v28:
    v46 = v253;
    goto v4;
/* error exit handlers */
v186:
    popv(4);
    return nil;
}



/* Code for convprc2 */

static Lisp_Object CC_convprc2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v292, v293, v356;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convprc2");
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
    v292 = stack[-1];
    v292 = qcdr(v292);
    if (!consp(v292)) goto v5;
    v292 = stack[-1];
    goto v10;

v10:
    fn = elt(env, 4); /* convchk */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-2];
    stack[-1] = v292;
    v292 = stack[0];
    v292 = qcdr(v292);
    if (!consp(v292)) goto v30;
    v292 = stack[0];
    goto v29;

v29:
    fn = elt(env, 4); /* convchk */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-2];
    qvalue(elt(env, 1)) = v292; /* yy!! */
    v292 = qvalue(elt(env, 2)); /* !*roundbf */
    if (v292 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v292 = qvalue(elt(env, 1)); /* yy!! */
    v293 = v292;
    v293 = Lfloatp(nil, v293);
    env = stack[-2];
    if (v293 == nil) goto v26;
    fn = elt(env, 5); /* fl2bf */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-2];
    goto v38;

v38:
    qvalue(elt(env, 1)) = v292; /* yy!! */
    v292 = stack[-1];
    v292 = Lfloatp(nil, v292);
    env = stack[-2];
    if (v292 == nil) goto v184;
    v292 = stack[-1];
    {
        popv(3);
        fn = elt(env, 5); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v292);
    }

v184:
    v292 = stack[-1];
    if (!consp(v292)) goto v330;
    v292 = stack[-1];
    goto v252;

v252:
    {
        popv(3);
        fn = elt(env, 6); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v292);
    }

v330:
    v292 = stack[-1];
    v292 = integerp(v292);
    if (v292 == nil) goto v318;
    v356 = elt(env, 3); /* !:rd!: */
    v293 = stack[-1];
    v292 = (Lisp_Object)1; /* 0 */
    v292 = list2star(v356, v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-2];
    goto v252;

v318:
    v292 = stack[-1];
    fn = elt(env, 7); /* read!:num */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-2];
    goto v252;

v26:
    v293 = v292;
    if (!(!consp(v293))) goto v254;
    v293 = v292;
    v293 = integerp(v293);
    if (v293 == nil) goto v46;
    v356 = elt(env, 3); /* !:rd!: */
    v293 = v292;
    v292 = (Lisp_Object)1; /* 0 */
    v292 = list2star(v356, v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-2];
    goto v254;

v254:
    fn = elt(env, 6); /* csl_normbf */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-2];
    goto v38;

v46:
    fn = elt(env, 7); /* read!:num */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-2];
    goto v254;

v30:
    v292 = stack[0];
    v292 = qcdr(v292);
    goto v29;

v5:
    v292 = stack[-1];
    v292 = qcdr(v292);
    goto v10;
/* error exit handlers */
v344:
    popv(3);
    return nil;
}



setup_type const u24_setup[] =
{
    {"add-degrees",             too_few_2,      CC_addKdegrees,wrong_no_2},
    {"mk+squared+norm",         CC_mkLsquaredLnorm,too_many_1, wrong_no_1},
    {"expnd",                   CC_expnd,       too_many_1,    wrong_no_1},
    {"rl_bnfsimpl",             too_few_2,      CC_rl_bnfsimpl,wrong_no_2},
    {"dip_fmon",                too_few_2,      CC_dip_fmon,   wrong_no_2},
    {"evaluate-horner",         CC_evaluateKhorner,too_many_1, wrong_no_1},
    {"toolongexpp",             CC_toolongexpp, too_many_1,    wrong_no_1},
    {"find_bubles_coeff",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_bubles_coeff},
    {"**a2i",                   too_few_2,      CC_HHa2i,      wrong_no_2},
    {"mo_zero",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mo_zero},
    {"insert",                  too_few_2,      CC_insert,     wrong_no_2},
    {"formproc",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formproc},
    {"sfto_ucontentf1",         too_few_2,      CC_sfto_ucontentf1,wrong_no_2},
    {"vp2",                     CC_vp2,         too_many_1,    wrong_no_1},
    {"get*inverse",             too_few_2,      CC_getHinverse,wrong_no_2},
    {"ev_revgradlexcomp",       too_few_2,      CC_ev_revgradlexcomp,wrong_no_2},
    {"omfir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omfir},
    {"mkempspmat",              too_few_2,      CC_mkempspmat, wrong_no_2},
    {"formc*",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcH},
    {"*xadd",                   too_few_2,      CC_Hxadd,      wrong_no_2},
    {"contract-strand",         too_few_2,      CC_contractKstrand,wrong_no_2},
    {"quotpri",                 CC_quotpri,     too_many_1,    wrong_no_1},
    {"red=hidelt",              CC_redMhidelt,  too_many_1,    wrong_no_1},
    {"simp-prop1",              too_few_2,      CC_simpKprop1, wrong_no_2},
    {"skp_ordp",                too_few_2,      CC_skp_ordp,   wrong_no_2},
    {"cl_flip",                 CC_cl_flip,     too_many_1,    wrong_no_1},
    {"prepreform1",             too_few_2,      CC_prepreform1,wrong_no_2},
    {"texstrlen",               CC_texstrlen,   too_many_1,    wrong_no_1},
    {"multfnc",                 too_few_2,      CC_multfnc,    wrong_no_2},
    {"offexpchk",               CC_offexpchk,   too_many_1,    wrong_no_1},
    {"tmsf",                    CC_tmsf,        too_many_1,    wrong_no_1},
    {"pasf_pdp",                CC_pasf_pdp,    too_many_1,    wrong_no_1},
    {"opfneval",                CC_opfneval,    too_many_1,    wrong_no_1},
    {"ps:evaluate-next",        too_few_2,      CC_psTevaluateKnext,wrong_no_2},
    {"derad",                   too_few_2,      CC_derad,      wrong_no_2},
    {"make-unique-freevars",    CC_makeKuniqueKfreevars,too_many_1,wrong_no_1},
    {"vdpequal",                too_few_2,      CC_vdpequal,   wrong_no_2},
    {"my_letmtr",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_my_letmtr},
    {"dip2vdp",                 CC_dip2vdp,     too_many_1,    wrong_no_1},
    {"convprc2",                too_few_2,      CC_convprc2,   wrong_no_2},
    {NULL, (one_args *)"u24", (two_args *)"9698 7651968 5337957", 0}
};

/* end of generated code */
