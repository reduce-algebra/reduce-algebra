
/* $destdir\u26.c        Machine generated C code */

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


/* Code for gettype */

static Lisp_Object CC_gettype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gettype");
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
    v13 = stack[0];
    if (is_number(v13)) goto v15;
    v13 = stack[0];
    if (!consp(v13)) goto v16;
    v13 = qvalue(elt(env, 2)); /* t */
    goto v17;

v17:
    if (v13 == nil) goto v18;
    v13 = elt(env, 3); /* form */
    { popv(2); return onevalue(v13); }

v18:
    v14 = stack[0];
    v13 = elt(env, 4); /* simpfn */
    v13 = get(v14, v13);
    env = stack[-1];
    if (v13 == nil) goto v19;
    v13 = elt(env, 5); /* operator */
    { popv(2); return onevalue(v13); }

v19:
    v14 = stack[0];
    v13 = elt(env, 6); /* avalue */
    v13 = get(v14, v13);
    env = stack[-1];
    if (v13 == nil) goto v20;
    v14 = stack[0];
    v13 = elt(env, 6); /* avalue */
    v13 = get(v14, v13);
    v13 = qcar(v13);
    { popv(2); return onevalue(v13); }

v20:
    v13 = stack[0];
    fn = elt(env, 13); /* getd */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-1];
    if (v13 == nil) goto v22;
    v13 = elt(env, 7); /* procedure */
    { popv(2); return onevalue(v13); }

v22:
    v13 = stack[0];
    v13 = Lsymbol_globalp(nil, v13);
    env = stack[-1];
    if (v13 == nil) goto v23;
    v13 = elt(env, 8); /* global */
    { popv(2); return onevalue(v13); }

v23:
    v13 = stack[0];
    v13 = Lsymbol_specialp(nil, v13);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-1];
    if (v13 == nil) goto v24;
    v13 = elt(env, 9); /* fluid */
    { popv(2); return onevalue(v13); }

v24:
    v14 = stack[0];
    v13 = elt(env, 10); /* parm */
    v13 = Lflagp(nil, v14, v13);
    env = stack[-1];
    if (v13 == nil) goto v25;
    v13 = elt(env, 11); /* parameter */
    { popv(2); return onevalue(v13); }

v25:
    v13 = stack[0];
    v14 = elt(env, 12); /* rtype */
    popv(2);
    return get(v13, v14);

v16:
    v13 = stack[0];
    if (v13 == nil) goto v26;
    v13 = stack[0];
    v13 = Lsymbolp(nil, v13);
    env = stack[-1];
    v13 = (v13 == nil ? lisp_true : nil);
    goto v17;

v26:
    v13 = qvalue(elt(env, 2)); /* t */
    goto v17;

v15:
    v13 = elt(env, 1); /* number */
    { popv(2); return onevalue(v13); }
/* error exit handlers */
v21:
    popv(2);
    return nil;
}



/* Code for mo_2a */

static Lisp_Object CC_mo_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_2a");
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
    v28 = v0;
/* end of prologue */
    stack[0] = qcar(v28);
    v28 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 2); /* ring_all_names */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    {
        Lisp_Object v30 = stack[0];
        popv(2);
        fn = elt(env, 3); /* mo!=expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v30, v28);
    }
/* error exit handlers */
v29:
    popv(2);
    return nil;
}



/* Code for ofsf_ignshift */

static Lisp_Object CC_ofsf_ignshift(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ignshift");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v37 = stack[-1];
    v37 = qcdr(v37);
    v38 = qcar(v37);
    v37 = stack[0];
    fn = elt(env, 7); /* sfto_reorder */
    v37 = (*qfn2(fn))(qenv(fn), v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-2];
    v39 = v37;
    v37 = v39;
    if (!consp(v37)) goto v41;
    v37 = v39;
    v37 = qcar(v37);
    v37 = (consp(v37) ? nil : lisp_true);
    goto v42;

v42:
    if (v37 == nil) goto v43;
    v37 = qvalue(elt(env, 2)); /* nil */
    goto v44;

v44:
    if (v37 == nil) goto v45;
    v37 = qvalue(elt(env, 3)); /* !*rlpos */
    if (!(v37 == nil)) goto v46;
    v37 = stack[-1];
    v38 = qcar(v37);
    v37 = elt(env, 4); /* (equal neq) */
    v37 = Lmemq(nil, v38, v37);
    if (!(v37 == nil)) goto v46;
    v37 = v39;
    v37 = qcar(v37);
    v37 = qcar(v37);
    v37 = qcdr(v37);
    v37 = Levenp(nil, v37);
    env = stack[-2];
    if (!(v37 == nil)) goto v46;
    v37 = elt(env, 6); /* odd */
    { popv(3); return onevalue(v37); }

v46:
    v37 = elt(env, 5); /* ignore */
    { popv(3); return onevalue(v37); }

v45:
    v37 = nil;
    { popv(3); return onevalue(v37); }

v43:
    v37 = v39;
    v37 = qcdr(v37);
    if (v37 == nil) goto v47;
    v37 = qvalue(elt(env, 2)); /* nil */
    goto v44;

v47:
    v37 = v39;
    v37 = qcar(v37);
    v37 = qcar(v37);
    v38 = qcar(v37);
    v37 = stack[0];
    v37 = (v38 == v37 ? lisp_true : nil);
    goto v44;

v41:
    v37 = qvalue(elt(env, 1)); /* t */
    goto v42;
/* error exit handlers */
v40:
    popv(3);
    return nil;
}



/* Code for orddf */

static Lisp_Object CC_orddf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for orddf");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */

v51:
    v50 = stack[-1];
    if (v50 == nil) goto v52;
    v50 = stack[0];
    if (v50 == nil) goto v43;
    v50 = stack[-1];
    v46 = qcar(v50);
    v50 = stack[0];
    v50 = qcar(v50);
    fn = elt(env, 6); /* exptcompare */
    v50 = (*qfn2(fn))(qenv(fn), v46, v50);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    if (v50 == nil) goto v54;
    v50 = qvalue(elt(env, 4)); /* t */
    { popv(3); return onevalue(v50); }

v54:
    v50 = stack[0];
    v46 = qcar(v50);
    v50 = stack[-1];
    v50 = qcar(v50);
    fn = elt(env, 6); /* exptcompare */
    v50 = (*qfn2(fn))(qenv(fn), v46, v50);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    if (v50 == nil) goto v55;
    v50 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v50); }

v55:
    v50 = stack[-1];
    v50 = qcdr(v50);
    stack[-1] = v50;
    v50 = stack[0];
    v50 = qcdr(v50);
    stack[0] = v50;
    goto v51;

v43:
    v50 = elt(env, 3); /* "Orddf u longer than v" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v50);
    }

v52:
    v50 = stack[0];
    if (v50 == nil) goto v56;
    v50 = elt(env, 2); /* "Orddf v longer than u" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v50);
    }

v56:
    v50 = elt(env, 1); /* "Orddf = case" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v50);
    }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for my!+nullsq!+p */

static Lisp_Object CC_myLnullsqLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my+nullsq+p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v17 = v0;
/* end of prologue */
    v17 = qcar(v17);
    if (v17 == nil) goto v57;
    v17 = nil;
    return onevalue(v17);

v57:
    v17 = qvalue(elt(env, 1)); /* t */
    return onevalue(v17);
}



/* Code for aex_freeids */

static Lisp_Object CC_aex_freeids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_freeids");
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
    v29 = stack[0];
    fn = elt(env, 1); /* aex_ex */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    fn = elt(env, 2); /* ratpoly_idl */
    stack[-1] = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v29 = stack[0];
    fn = elt(env, 3); /* aex_ctx */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    fn = elt(env, 4); /* ctx_idl */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    {
        Lisp_Object v12 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* lto_setminus */
        return (*qfn2(fn))(qenv(fn), v12, v29);
    }
/* error exit handlers */
v45:
    popv(3);
    return nil;
}



/* Code for containerml */

static Lisp_Object CC_containerml(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for containerml");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v19 = stack[0];
    v54 = elt(env, 1); /* integer_interval */
    if (!(v19 == v54)) goto v57;
    v54 = elt(env, 2); /* interval */
    stack[0] = v54;
    goto v57;

v57:
    v54 = elt(env, 3); /* "<" */
    fn = elt(env, 9); /* printout */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v54 = stack[0];
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v54 = stack[-1];
    v19 = qcar(v54);
    v54 = elt(env, 4); /* "" */
    fn = elt(env, 10); /* attributesml */
    v54 = (*qfn2(fn))(qenv(fn), v19, v54);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v54 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 11); /* indent!* */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v54 = stack[-1];
    v54 = qcdr(v54);
    fn = elt(env, 12); /* multi_elem */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v54 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 11); /* indent!* */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v54 = elt(env, 7); /* "</" */
    fn = elt(env, 9); /* printout */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v54 = stack[0];
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v54 = elt(env, 8); /* ">" */
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v60;
    v54 = nil;
    { popv(3); return onevalue(v54); }
/* error exit handlers */
v60:
    popv(3);
    return nil;
}



/* Code for on!-double1 */

static Lisp_Object CC_onKdouble1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for on-double1");
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

v15:
    v59 = stack[0];
    v59 = Lconsp(nil, v59);
    env = stack[-1];
    if (v59 == nil) goto v41;
    v59 = stack[0];
    v59 = qcar(v59);
    fn = elt(env, 3); /* doublep */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    if (v59 == nil) goto v62;
    v59 = lisp_true;
    qvalue(elt(env, 1)) = v59; /* !*double */
    { popv(2); return onevalue(v59); }

v62:
    v59 = stack[0];
    v59 = qcar(v59);
    v59 = CC_onKdouble1(env, v59);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    v59 = stack[0];
    v59 = qcdr(v59);
    stack[0] = v59;
    goto v15;

v41:
    v59 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v59); }
/* error exit handlers */
v61:
    popv(2);
    return nil;
}



/* Code for evmtest!? */

static Lisp_Object CC_evmtestW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v10, v63, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evmtest?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v31;
    v63 = v0;
/* end of prologue */

v51:
    v9 = v63;
    if (v9 == nil) goto v64;
    v9 = v10;
    if (v9 == nil) goto v64;
    v9 = v63;
    v47 = qcar(v9);
    v9 = v10;
    v9 = qcar(v9);
    if (((int32_t)(v47)) < ((int32_t)(v9))) goto v61;
    v9 = v63;
    v9 = qcdr(v9);
    v63 = v9;
    v9 = v10;
    v9 = qcdr(v9);
    v10 = v9;
    goto v51;

v61:
    v9 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v9);

v64:
    v9 = v10;
    {
        fn = elt(env, 2); /* evzero!? */
        return (*qfn1(fn))(qenv(fn), v9);
    }
}



/* Code for pairxvars */

static Lisp_Object MS_CDECL CC_pairxvars(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v65, Lisp_Object v32, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pairxvars");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pairxvars");
#endif
    if (stack >= stacklimit)
    {
        push4(v32,v65,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v31,v65,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v32;
    stack[-2] = v65;
    stack[-3] = v31;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    goto v27;

v27:
    v85 = stack[-4];
    if (v85 == nil) goto v43;
    v85 = stack[-4];
    v86 = qcar(v85);
    v85 = stack[-3];
    v85 = Latsoc(nil, v86, v85);
    stack[0] = v85;
    if (v85 == nil) goto v88;
    v86 = stack[0];
    v85 = stack[-3];
    v85 = Ldelete(nil, v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-6];
    stack[-3] = v85;
    v85 = stack[0];
    v86 = qcdr(v85);
    v85 = elt(env, 1); /* scalar */
    if (v86 == v85) goto v24;
    v85 = stack[-4];
    v87 = qcar(v85);
    v85 = stack[0];
    v86 = qcdr(v85);
    v85 = stack[-5];
    v85 = acons(v87, v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-6];
    stack[-5] = v85;
    goto v17;

v17:
    v85 = stack[-4];
    v85 = qcdr(v85);
    stack[-4] = v85;
    goto v27;

v24:
    v85 = stack[-4];
    v87 = qcar(v85);
    v86 = stack[-1];
    v85 = stack[-5];
    v85 = acons(v87, v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-6];
    stack[-5] = v85;
    goto v17;

v88:
    v85 = stack[-4];
    v85 = qcar(v85);
    if (symbolp(v85)) goto v90;
    v85 = qvalue(elt(env, 2)); /* t */
    goto v91;

v91:
    if (v85 == nil) goto v92;
    v86 = elt(env, 5); /* "Invalid parameter:" */
    v85 = stack[-4];
    v85 = qcar(v85);
    v86 = list2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-6];
    v85 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 7); /* symerr */
    v85 = (*qfn2(fn))(qenv(fn), v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-6];
    goto v17;

v92:
    v85 = stack[-4];
    v87 = qcar(v85);
    v86 = stack[-1];
    v85 = stack[-5];
    v85 = acons(v87, v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-6];
    stack[-5] = v85;
    goto v17;

v90:
    v85 = stack[-4];
    v86 = qcar(v85);
    v85 = elt(env, 3); /* infix */
    v85 = get(v86, v85);
    env = stack[-6];
    if (!(v85 == nil)) goto v91;
    v85 = stack[-4];
    v86 = qcar(v85);
    v85 = elt(env, 4); /* stat */
    v85 = get(v86, v85);
    env = stack[-6];
    goto v91;

v43:
    v85 = stack[-5];
    v86 = Lnreverse(nil, v85);
    env = stack[-6];
    v85 = stack[-2];
    v86 = Lappend(nil, v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v89;
    v85 = stack[-3];
    popv(7);
    return cons(v86, v85);
/* error exit handlers */
v89:
    popv(7);
    return nil;
}



/* Code for extadd */

static Lisp_Object CC_extadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extadd");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v31;
    stack[-3] = v0;
/* end of prologue */
    v102 = stack[-3];
    if (v102 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v102 = stack[-2];
    if (v102 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v102 = qvalue(elt(env, 1)); /* nil */
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    stack[-1] = v102;
    stack[-4] = v102;
    goto v36;

v36:
    v102 = stack[-3];
    if (v102 == nil) goto v105;
    v102 = stack[-2];
    if (v102 == nil) goto v105;
    v102 = stack[-2];
    v102 = qcar(v102);
    v103 = qcar(v102);
    v102 = stack[-3];
    v102 = qcar(v102);
    v102 = qcar(v102);
    if (equal(v103, v102)) goto v106;
    v102 = stack[-2];
    v102 = qcar(v102);
    v103 = qcar(v102);
    v102 = stack[-3];
    v102 = qcar(v102);
    v102 = qcar(v102);
    fn = elt(env, 2); /* ordexp */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    if (v102 == nil) goto v76;
    stack[0] = stack[-1];
    v102 = stack[-2];
    v102 = qcar(v102);
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v102 = (*qfn2(fn))(qenv(fn), stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v102 = stack[-2];
    v102 = qcdr(v102);
    stack[-2] = v102;
    v102 = stack[-1];
    v102 = qcdr(v102);
    stack[-1] = v102;
    goto v36;

v76:
    stack[0] = stack[-1];
    v102 = stack[-3];
    v102 = qcar(v102);
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v102 = (*qfn2(fn))(qenv(fn), stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v102 = stack[-3];
    v102 = qcdr(v102);
    stack[-3] = v102;
    v102 = stack[-1];
    v102 = qcdr(v102);
    stack[-1] = v102;
    goto v36;

v106:
    v102 = stack[-3];
    v102 = qcar(v102);
    v103 = qcdr(v102);
    v102 = stack[-2];
    v102 = qcar(v102);
    v102 = qcdr(v102);
    fn = elt(env, 4); /* addf */
    v103 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v102 = v103;
    if (v103 == nil) goto v8;
    stack[0] = stack[-1];
    v103 = stack[-3];
    v103 = qcar(v103);
    v103 = qcar(v103);
    v102 = cons(v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v102 = (*qfn2(fn))(qenv(fn), stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v102 = stack[-1];
    v102 = qcdr(v102);
    stack[-1] = v102;
    goto v8;

v8:
    v102 = stack[-3];
    v102 = qcdr(v102);
    stack[-3] = v102;
    v102 = stack[-2];
    v102 = qcdr(v102);
    stack[-2] = v102;
    goto v36;

v105:
    v103 = stack[-1];
    v102 = stack[-3];
    if (v102 == nil) goto v107;
    v102 = stack[-3];
    goto v108;

v108:
    fn = elt(env, 3); /* setcdr */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    v102 = stack[-4];
    v102 = qcdr(v102);
    { popv(6); return onevalue(v102); }

v107:
    v102 = stack[-2];
    goto v108;
/* error exit handlers */
v104:
    popv(6);
    return nil;
}



/* Code for ofsf_smcpknowl */

static Lisp_Object CC_ofsf_smcpknowl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v111;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smcpknowl");
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
    v80 = v0;
/* end of prologue */
    stack[-4] = v80;
    v80 = stack[-4];
    if (v80 == nil) goto v17;
    v80 = stack[-4];
    v80 = qcar(v80);
    v111 = v80;
    v80 = v111;
    stack[0] = qcar(v80);
    v80 = v111;
    v111 = qcdr(v80);
    v80 = qvalue(elt(env, 1)); /* nil */
    v80 = Lappend(nil, v111, v80);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    v80 = cons(stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    stack[-2] = v80;
    stack[-3] = v80;
    goto v112;

v112:
    v80 = stack[-4];
    v80 = qcdr(v80);
    stack[-4] = v80;
    v80 = stack[-4];
    if (v80 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v80 = stack[-4];
    v80 = qcar(v80);
    v111 = v80;
    v80 = v111;
    stack[0] = qcar(v80);
    v80 = v111;
    v111 = qcdr(v80);
    v80 = qvalue(elt(env, 1)); /* nil */
    v80 = Lappend(nil, v111, v80);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    v80 = cons(stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    v80 = Lrplacd(nil, stack[-1], v80);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    v80 = stack[-2];
    v80 = qcdr(v80);
    stack[-2] = v80;
    goto v112;

v17:
    v80 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v80); }
/* error exit handlers */
v98:
    popv(6);
    return nil;
}



/* Code for formboollis */

static Lisp_Object MS_CDECL CC_formboollis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v65, Lisp_Object v32, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v109, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "formboollis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formboollis");
#endif
    if (stack >= stacklimit)
    {
        push4(v32,v65,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v31,v65,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v32;
    stack[-1] = v65;
    stack[-2] = v31;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v52;

v52:
    v22 = stack[-3];
    if (v22 == nil) goto v17;
    v22 = stack[0];
    if (v22 == nil) goto v60;
    v22 = stack[-3];
    v53 = qcar(v22);
    v109 = stack[-2];
    v22 = stack[-1];
    fn = elt(env, 1); /* formbool */
    v109 = (*qfnn(fn))(qenv(fn), 3, v53, v109, v22);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v22 = stack[-4];
    v22 = cons(v109, v22);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-4] = v22;
    goto v11;

v11:
    v22 = stack[-3];
    v22 = qcdr(v22);
    stack[-3] = v22;
    goto v52;

v60:
    v22 = stack[-3];
    v53 = qcar(v22);
    v109 = stack[-2];
    v22 = stack[-1];
    fn = elt(env, 2); /* formc!* */
    v109 = (*qfnn(fn))(qenv(fn), 3, v53, v109, v22);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v22 = stack[-4];
    v22 = cons(v109, v22);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-4] = v22;
    goto v11;

v17:
    v22 = stack[-4];
        popv(6);
        return Lnreverse(nil, v22);
/* error exit handlers */
v117:
    popv(6);
    return nil;
}



/* Code for multdfconst */

static Lisp_Object CC_multdfconst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdfconst");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v31;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v57;

v57:
    v48 = stack[-1];
    if (v48 == nil) goto v56;
    v48 = stack[-2];
    v48 = qcar(v48);
    v48 = (v48 == nil ? lisp_true : nil);
    goto v28;

v28:
    if (v48 == nil) goto v84;
    v48 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v48);
    }

v84:
    v48 = stack[-1];
    v48 = qcar(v48);
    stack[0] = qcar(v48);
    v118 = stack[-2];
    v48 = stack[-1];
    v48 = qcar(v48);
    v48 = qcdr(v48);
    fn = elt(env, 3); /* multsq */
    v48 = (*qfn2(fn))(qenv(fn), v118, v48);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-4];
    fn = elt(env, 4); /* subs2q */
    v118 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-4];
    v48 = stack[-3];
    v48 = acons(stack[0], v118, v48);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-4];
    stack[-3] = v48;
    v48 = stack[-1];
    v48 = qcdr(v48);
    stack[-1] = v48;
    goto v57;

v56:
    v48 = qvalue(elt(env, 1)); /* t */
    goto v28;
/* error exit handlers */
v5:
    popv(5);
    return nil;
}



/* Code for mk!+trace */

static Lisp_Object CC_mkLtrace(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+trace");
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
    v111 = stack[-1];
    fn = elt(env, 6); /* squared!+matrix!+p */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    if (!(v111 == nil)) goto v123;
    v111 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v111 == nil)) goto v30;
    v111 = elt(env, 2); /* "no square matrix in add" */
    fn = elt(env, 7); /* lprie */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    goto v30;

v30:
    v111 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    goto v123;

v123:
    v121 = qvalue(elt(env, 3)); /* nil */
    v111 = (Lisp_Object)17; /* 1 */
    v111 = cons(v121, v111);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    stack[0] = v111;
    v111 = (Lisp_Object)17; /* 1 */
    stack[-2] = v111;
    goto v47;

v47:
    v111 = stack[-1];
    fn = elt(env, 8); /* get!+row!+nr */
    v121 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v111 = stack[-2];
    v111 = difference2(v121, v111);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v111 = Lminusp(nil, v111);
    env = stack[-3];
    if (v111 == nil) goto v6;
    v111 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v111; /* !*sub2 */
    v111 = stack[0];
    fn = elt(env, 9); /* subs2 */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[0] = v111;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v6:
    v122 = stack[-1];
    v121 = stack[-2];
    v111 = stack[-2];
    fn = elt(env, 10); /* get!+mat!+entry */
    v111 = (*qfnn(fn))(qenv(fn), 3, v122, v121, v111);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    fn = elt(env, 11); /* addsq */
    v111 = (*qfn2(fn))(qenv(fn), stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    stack[0] = v111;
    v111 = stack[-2];
    v111 = add1(v111);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    stack[-2] = v111;
    goto v47;
/* error exit handlers */
v99:
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(4);
    return nil;
v98:
    popv(4);
    return nil;
}



/* Code for distribute!.multiplicity */

static Lisp_Object CC_distributeQmultiplicity(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for distribute.multiplicity");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v31;
    v5 = v0;
/* end of prologue */
    stack[-4] = v5;
    v5 = stack[-4];
    if (v5 == nil) goto v28;
    v5 = stack[-4];
    v5 = qcar(v5);
    v6 = v5;
    v5 = stack[-3];
    v5 = cons(v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-5];
    v5 = ncons(v5);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-5];
    stack[-1] = v5;
    stack[-2] = v5;
    goto v52;

v52:
    v5 = stack[-4];
    v5 = qcdr(v5);
    stack[-4] = v5;
    v5 = stack[-4];
    if (v5 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v5 = stack[-4];
    v5 = qcar(v5);
    v6 = v5;
    v5 = stack[-3];
    v5 = cons(v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-5];
    v5 = ncons(v5);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-5];
    v5 = Lrplacd(nil, stack[0], v5);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-5];
    v5 = stack[-1];
    v5 = qcdr(v5);
    stack[-1] = v5;
    goto v52;

v28:
    v5 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v5); }
/* error exit handlers */
v100:
    popv(6);
    return nil;
}



/* Code for ratpoly_quot */

static Lisp_Object CC_ratpoly_quot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_quot");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v28 = v31;
    v56 = v0;
/* end of prologue */
    stack[0] = v56;
    fn = elt(env, 1); /* invsq */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    {
        Lisp_Object v16 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v16, v28);
    }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for cgp_lbc */

static Lisp_Object CC_cgp_lbc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_lbc");
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
    v51 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_lbc */
        return (*qfn1(fn))(qenv(fn), v51);
    }
/* error exit handlers */
v57:
    popv(1);
    return nil;
}



/* Code for i2cr!* */

static Lisp_Object CC_i2crH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2cr*");
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
    v26 = v0;
/* end of prologue */
    fn = elt(env, 3); /* chkint!* */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[0];
    v44 = v26;
    if (!consp(v26)) goto v56;
    v26 = qvalue(elt(env, 2)); /* bfz!* */
    goto v52;

v52:
    {
        popv(1);
        fn = elt(env, 4); /* mkcr */
        return (*qfn2(fn))(qenv(fn), v44, v26);
    }

v56:
    v26 = elt(env, 1); /* 0.0 */
    goto v52;
/* error exit handlers */
v43:
    popv(1);
    return nil;
}



/* Code for lchk */

static Lisp_Object CC_lchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v100;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lchk");
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
    v53 = stack[0];
    if (v53 == nil) goto v28;
    v53 = stack[0];
    v53 = qcar(v53);
    v53 = (consp(v53) ? nil : lisp_true);
    goto v17;

v17:
    if (v53 == nil) goto v112;
    v53 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v53); }

v112:
    v53 = stack[0];
    v53 = qcar(v53);
    v53 = Llength(nil, v53);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-2];
    stack[-1] = v53;
    goto v84;

v84:
    v53 = stack[0];
    v53 = qcdr(v53);
    stack[0] = v53;
    v53 = stack[0];
    if (v53 == nil) goto v49;
    v53 = stack[0];
    v53 = qcar(v53);
    if (!consp(v53)) goto v19;
    v53 = stack[0];
    v53 = qcar(v53);
    v100 = Llength(nil, v53);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-2];
    v53 = stack[-1];
    v53 = Lneq(nil, v100, v53);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-2];
    goto v35;

v35:
    if (v53 == nil) goto v84;
    v53 = stack[0];
    v53 = (v53 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v53); }

v19:
    v53 = qvalue(elt(env, 1)); /* t */
    goto v35;

v49:
    v53 = qvalue(elt(env, 1)); /* t */
    goto v35;

v28:
    v53 = qvalue(elt(env, 1)); /* t */
    goto v17;
/* error exit handlers */
v119:
    popv(3);
    return nil;
}



/* Code for difference!: */

static Lisp_Object CC_differenceT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v85, v86;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difference:");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v31;
    v86 = v0;
/* end of prologue */
    v103 = v86;
    v103 = qcdr(v103);
    v85 = qcar(v103);
    stack[-1] = v85;
    v103 = (Lisp_Object)1; /* 0 */
    if (v85 == v103) goto v36;
    v103 = stack[-2];
    v103 = qcdr(v103);
    v85 = qcar(v103);
    stack[0] = v85;
    v103 = (Lisp_Object)1; /* 0 */
    if (v85 == v103) { popv(6); return onevalue(v86); }
    v103 = v86;
    v103 = qcdr(v103);
    v85 = qcdr(v103);
    stack[-4] = v85;
    v103 = stack[-2];
    v103 = qcdr(v103);
    v103 = qcdr(v103);
    stack[-2] = v103;
    v85 = difference2(v85, v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    stack[-3] = v85;
    v103 = (Lisp_Object)1; /* 0 */
    if (v85 == v103) goto v33;
    v85 = stack[-3];
    v103 = (Lisp_Object)1; /* 0 */
    v103 = (Lisp_Object)greaterp2(v85, v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v103 = v103 ? lisp_true : nil;
    env = stack[-5];
    if (v103 == nil) goto v69;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v85 = stack[-1];
    v103 = stack[-3];
    v85 = Lash1(nil, v85, v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v103 = stack[0];
    v85 = difference2(v85, v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v103 = stack[-2];
    {
        Lisp_Object v136 = stack[-4];
        popv(6);
        return list2star(v136, v85, v103);
    }

v69:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v103 = stack[-3];
    v103 = negate(v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v103 = Lash1(nil, stack[0], v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v85 = difference2(stack[-1], v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v103 = stack[-4];
    {
        Lisp_Object v89 = stack[-2];
        popv(6);
        return list2star(v89, v85, v103);
    }

v33:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v85 = stack[-1];
    v103 = stack[0];
    v85 = difference2(v85, v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v103 = stack[-4];
    {
        Lisp_Object v137 = stack[-2];
        popv(6);
        return list2star(v137, v85, v103);
    }

v36:
    stack[0] = elt(env, 1); /* !:rd!: */
    v103 = stack[-2];
    v103 = qcdr(v103);
    v103 = qcar(v103);
    v85 = negate(v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v103 = stack[-2];
    v103 = qcdr(v103);
    v103 = qcdr(v103);
    {
        Lisp_Object v138 = stack[0];
        popv(6);
        return list2star(v138, v85, v103);
    }
/* error exit handlers */
v135:
    popv(6);
    return nil;
}



/* Code for rd!:difference */

static Lisp_Object CC_rdTdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v160, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:difference");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v31;
    stack[0] = v0;
/* end of prologue */
    v159 = qvalue(elt(env, 1)); /* nil */
    v160 = v159;
    v159 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v159 == nil) goto v17;
    v159 = qvalue(elt(env, 1)); /* nil */
    goto v11;

v11:
    if (v159 == nil) goto v22;
    v159 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v159, v160);

v22:
    v160 = stack[0];
    v159 = stack[-1];
    fn = elt(env, 8); /* convprc2 */
    v159 = (*qfn2(fn))(qenv(fn), v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    stack[-1] = v159;
    v159 = qvalue(elt(env, 4)); /* yy!! */
    stack[-3] = v159;
    v159 = stack[-1];
    if (!consp(v159)) goto v163;
    v160 = stack[-1];
    v159 = stack[-3];
    fn = elt(env, 9); /* difbf */
    v159 = (*qfn2(fn))(qenv(fn), v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v110;

v110:
    stack[0] = v159;
    stack[-2] = stack[0];
    v159 = stack[-3];
    if (!consp(v159)) goto v164;
    stack[0] = elt(env, 3); /* !:rd!: */
    v159 = stack[-3];
    v159 = qcdr(v159);
    v159 = qcar(v159);
    v160 = negate(v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v159 = stack[-3];
    v159 = qcdr(v159);
    v159 = qcdr(v159);
    v159 = list2star(stack[0], v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v165;

v165:
    fn = elt(env, 10); /* rdzchk */
    v159 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v160 = v159;
    v159 = v160;
    if (!(!consp(v159))) { popv(5); return onevalue(v160); }
    v159 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v159, v160);

v164:
    v159 = stack[-3];
    v159 = negate(v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v165;

v163:
    stack[-2] = elt(env, 5); /* difference */
    v159 = stack[-1];
    stack[0] = Lmkquote(nil, v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v159 = stack[-3];
    v159 = Lmkquote(nil, v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v161 = list3(stack[-2], stack[0], v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v160 = qvalue(elt(env, 1)); /* nil */
    v159 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 11); /* errorset */
    v159 = (*qfnn(fn))(qenv(fn), 3, v161, v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v160 = v159;
    v159 = v160;
    if (!consp(v159)) goto v166;
    v159 = v160;
    v159 = qcdr(v159);
    goto v167;

v167:
    if (v159 == nil) goto v168;
    fn = elt(env, 12); /* rndbfon */
    v159 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v159 = stack[-1];
    v159 = Lfloatp(nil, v159);
    env = stack[-4];
    if (v159 == nil) goto v70;
    v159 = stack[-1];
    fn = elt(env, 13); /* fl2bf */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    stack[0] = v159;
    goto v169;

v169:
    stack[-1] = stack[0];
    v159 = stack[-3];
    v159 = Lfloatp(nil, v159);
    env = stack[-4];
    if (v159 == nil) goto v170;
    v159 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v171;

v171:
    stack[-3] = v159;
    fn = elt(env, 9); /* difbf */
    v159 = (*qfn2(fn))(qenv(fn), stack[0], v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v110;

v170:
    v159 = stack[-3];
    if (!consp(v159)) goto v172;
    v159 = stack[-3];
    goto v173;

v173:
    fn = elt(env, 14); /* csl_normbf */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v171;

v172:
    v159 = stack[-3];
    v159 = integerp(v159);
    if (v159 == nil) goto v174;
    v161 = elt(env, 3); /* !:rd!: */
    v160 = stack[-3];
    v159 = (Lisp_Object)1; /* 0 */
    v159 = list2star(v161, v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v173;

v174:
    v159 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v173;

v70:
    v159 = stack[-1];
    if (!consp(v159)) goto v125;
    v159 = stack[-1];
    goto v92;

v92:
    fn = elt(env, 14); /* csl_normbf */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    stack[0] = v159;
    goto v169;

v125:
    v159 = stack[-1];
    v159 = integerp(v159);
    if (v159 == nil) goto v135;
    v161 = elt(env, 3); /* !:rd!: */
    v160 = stack[-1];
    v159 = (Lisp_Object)1; /* 0 */
    v159 = list2star(v161, v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v92;

v135:
    v159 = stack[-1];
    fn = elt(env, 15); /* read!:num */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v92;

v168:
    v159 = v160;
    v159 = qcar(v159);
    goto v110;

v166:
    v159 = qvalue(elt(env, 7)); /* t */
    goto v167;

v17:
    v159 = stack[0];
    v159 = qcdr(v159);
    if (!consp(v159)) goto v16;
    v159 = qvalue(elt(env, 1)); /* nil */
    goto v11;

v16:
    v159 = stack[-1];
    v159 = qcdr(v159);
    if (!consp(v159)) goto v84;
    v159 = qvalue(elt(env, 1)); /* nil */
    goto v11;

v84:
    v159 = stack[0];
    stack[-2] = qcdr(v159);
    v159 = stack[-1];
    v159 = qcdr(v159);
    v159 = negate(v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    fn = elt(env, 16); /* safe!-fp!-plus */
    v159 = (*qfn2(fn))(qenv(fn), stack[-2], v159);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v160 = v159;
    goto v11;
/* error exit handlers */
v162:
    popv(5);
    return nil;
}



/* Code for prop!-simp2 */

static Lisp_Object CC_propKsimp2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v22;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp2");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v31;
    stack[-3] = v0;
/* end of prologue */
    v46 = stack[-2];
    if (!consp(v46)) goto v28;
    v22 = stack[-2];
    v46 = stack[-3];
    v46 = Lmember(nil, v22, v46);
    goto v17;

v17:
    stack[-4] = v46;
    if (v46 == nil) goto v5;
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v46 = stack[-3];
    stack[0] = Llength(nil, v46);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    v46 = stack[-4];
    v46 = Llength(nil, v46);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    v46 = difference2(stack[0], v46);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    stack[0] = Lexpt(nil, stack[-1], v46);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    v22 = stack[-2];
    v46 = stack[-3];
    v46 = Ldelete(nil, v22, v46);
    nil = C_nil;
    if (exception_pending()) goto v119;
    {
        Lisp_Object v175 = stack[0];
        popv(6);
        return cons(v175, v46);
    }

v5:
    v46 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v46); }

v28:
    v46 = qvalue(elt(env, 1)); /* nil */
    goto v17;
/* error exit handlers */
v119:
    popv(6);
    return nil;
}



/* Code for greaterpcdr */

static Lisp_Object CC_greaterpcdr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greaterpcdr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v56 = v31;
    v29 = v0;
/* end of prologue */
    v29 = qcdr(v29);
    v56 = qcdr(v56);
        return Lgreaterp(nil, v29, v56);
}



/* Code for remchkf */

static Lisp_Object MS_CDECL CC_remchkf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v65, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v111, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "remchkf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remchkf");
#endif
    if (stack >= stacklimit)
    {
        push3(v65,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v65);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v65;
    stack[-1] = v31;
    stack[-2] = v0;
/* end of prologue */
    v111 = stack[-2];
    v80 = stack[-1];
    fn = elt(env, 3); /* remchkf1 */
    v80 = (*qfn2(fn))(qenv(fn), v111, v80);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    stack[-3] = v80;
    v80 = stack[-3];
    if (!consp(v80)) goto v123;
    v80 = stack[-3];
    v80 = qcar(v80);
    v80 = (consp(v80) ? nil : lisp_true);
    goto v43;

v43:
    if (v80 == nil) goto v20;
    v80 = qvalue(elt(env, 1)); /* t */
    goto v12;

v12:
    if (!(v80 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v80 = stack[-3];
    stack[-2] = qcar(v80);
    v80 = stack[-3];
    v121 = qcdr(v80);
    v111 = stack[-1];
    v80 = stack[0];
    v80 = CC_remchkf(env, 3, v121, v111, v80);
    nil = C_nil;
    if (exception_pending()) goto v98;
    {
        Lisp_Object v99 = stack[-2];
        popv(5);
        return cons(v99, v80);
    }

v20:
    v111 = stack[-2];
    v80 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* kernels1 */
    v111 = (*qfn2(fn))(qenv(fn), v111, v80);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v80 = stack[0];
    fn = elt(env, 5); /* intersection */
    v80 = (*qfn2(fn))(qenv(fn), v111, v80);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v80 = (v80 == nil ? lisp_true : nil);
    goto v12;

v123:
    v80 = qvalue(elt(env, 1)); /* t */
    goto v43;
/* error exit handlers */
v98:
    popv(5);
    return nil;
}



/* Code for lpos */

static Lisp_Object CC_lpos(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v83, v61;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpos");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v83 = v31;
    v61 = v0;
/* end of prologue */
    v59 = v61;
    v58 = v83;
    v58 = qcar(v58);
    if (v59 == v58) goto v51;
    v58 = v61;
    v59 = v83;
    v59 = qcdr(v59);
    v58 = CC_lpos(env, v58, v59);
    errexit();
    return add1(v58);

v51:
    v58 = (Lisp_Object)17; /* 1 */
    return onevalue(v58);
}



/* Code for lessppair */

static Lisp_Object CC_lessppair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v10, v63, v47;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lessppair");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v31;
    v63 = v0;
/* end of prologue */
    v9 = v63;
    v47 = qcar(v9);
    v9 = v10;
    v9 = qcar(v9);
    if (equal(v47, v9)) goto v45;
    v9 = v63;
    v9 = qcar(v9);
    v10 = qcar(v10);
        return Llessp(nil, v9, v10);

v45:
    v9 = v63;
    v9 = qcdr(v9);
    v10 = qcdr(v10);
        return Llessp(nil, v9, v10);
}



/* Code for giplus!: */

static Lisp_Object CC_giplusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giplus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v31;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = elt(env, 1); /* !:gi!: */
    v49 = stack[-2];
    v49 = qcdr(v49);
    v116 = qcar(v49);
    v49 = stack[-1];
    v49 = qcdr(v49);
    v49 = qcar(v49);
    stack[0] = plus2(v116, v49);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    v49 = stack[-2];
    v49 = qcdr(v49);
    v116 = qcdr(v49);
    v49 = stack[-1];
    v49 = qcdr(v49);
    v49 = qcdr(v49);
    v49 = plus2(v116, v49);
    nil = C_nil;
    if (exception_pending()) goto v20;
    {
        Lisp_Object v54 = stack[-3];
        Lisp_Object v19 = stack[0];
        popv(5);
        return list2star(v54, v19, v49);
    }
/* error exit handlers */
v20:
    popv(5);
    return nil;
}



/* Code for depend!-f */

static Lisp_Object CC_dependKf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-f");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */

v176:
    v5 = stack[-1];
    if (!consp(v5)) goto v27;
    v5 = stack[-1];
    v5 = qcar(v5);
    v5 = (consp(v5) ? nil : lisp_true);
    goto v52;

v52:
    if (v5 == nil) goto v42;
    v5 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v5); }

v42:
    v5 = stack[-1];
    v5 = qcar(v5);
    v5 = qcar(v5);
    v6 = qcar(v5);
    v5 = stack[0];
    fn = elt(env, 3); /* depend!-p */
    v5 = (*qfn2(fn))(qenv(fn), v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    if (!(v5 == nil)) { popv(3); return onevalue(v5); }
    v5 = stack[-1];
    v5 = qcar(v5);
    v6 = qcdr(v5);
    v5 = stack[0];
    v5 = CC_dependKf(env, v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    if (!(v5 == nil)) { popv(3); return onevalue(v5); }
    v5 = stack[-1];
    v6 = qcdr(v5);
    v5 = stack[0];
    stack[-1] = v6;
    stack[0] = v5;
    goto v176;

v27:
    v5 = qvalue(elt(env, 1)); /* t */
    goto v52;
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



/* Code for pasf_subfof */

static Lisp_Object MS_CDECL CC_pasf_subfof(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v65, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v123, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_subfof");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_subfof");
#endif
    if (stack >= stacklimit)
    {
        push3(v65,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v65);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v43 = v65;
    v123 = v31;
    v36 = v0;
/* end of prologue */
    stack[-1] = v43;
    stack[0] = elt(env, 1); /* pasf_subfof1 */
    v43 = v36;
    v43 = list2(v43, v123);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    {
        Lisp_Object v58 = stack[-1];
        Lisp_Object v59 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v58, v59, v43);
    }
/* error exit handlers */
v84:
    popv(3);
    return nil;
}



/* Code for omatpir */

static Lisp_Object MS_CDECL CC_omatpir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v84, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omatpir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omatpir");
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
    fn = elt(env, 3); /* lex */
    v41 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    fn = elt(env, 4); /* omsir */
    v41 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    v41 = qcar(v41);
    stack[-1] = v41;
    fn = elt(env, 3); /* lex */
    v41 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    fn = elt(env, 5); /* omobj */
    v41 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    v41 = qcar(v41);
    stack[0] = v41;
    fn = elt(env, 3); /* lex */
    v41 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    v41 = elt(env, 1); /* (!/ o m a t p) */
    fn = elt(env, 6); /* checktag */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    v58 = stack[-1];
    v84 = stack[0];
    v41 = qvalue(elt(env, 2)); /* nil */
    v41 = list2star(v58, v84, v41);
    nil = C_nil;
    if (exception_pending()) goto v61;
    popv(3);
    return ncons(v41);
/* error exit handlers */
v61:
    popv(3);
    return nil;
}



/* Code for simp_without_resimp */

static Lisp_Object CC_simp_without_resimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp_without_resimp");
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
    v112 = v0;
/* end of prologue */
    v57 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*resimp */
    qvalue(elt(env, 2)) = v57; /* !*resimp */
    v57 = v112;
    fn = elt(env, 3); /* simp */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*resimp */
    { popv(2); return onevalue(v57); }
/* error exit handlers */
v27:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*resimp */
    popv(2);
    return nil;
}



/* Code for f2dip11 */

static Lisp_Object CC_f2dip11(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip11");
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

v176:
    v117 = qvalue(elt(env, 1)); /* !*notestparameters */
    if (!(v117 == nil)) { popv(2); return onevalue(v117); }
    v110 = stack[0];
    v117 = qvalue(elt(env, 2)); /* vdpvars!* */
    v117 = Lmember(nil, v110, v117);
    if (v117 == nil) goto v112;
    v117 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v117 == nil)) goto v44;
    v110 = stack[0];
    v117 = elt(env, 4); /* "occurs in a parameter and is member of the groebner variables." 
*/
    v117 = list2(v110, v117);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    fn = elt(env, 7); /* lprie */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    goto v44;

v44:
    v117 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    goto v112;

v112:
    v117 = stack[0];
    if (!consp(v117)) goto v19;
    v117 = stack[0];
    v117 = qcar(v117);
    v117 = CC_f2dip11(env, v117);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v117 = stack[0];
    v117 = qcdr(v117);
    stack[0] = v117;
    goto v176;

v19:
    v110 = stack[0];
    v117 = elt(env, 5); /* list */
    if (v110 == v117) goto v20;
    v117 = nil;
    { popv(2); return onevalue(v117); }

v20:
    v117 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v117 == nil)) goto v106;
    v117 = elt(env, 6); /* "groebner: LIST not allowed." */
    fn = elt(env, 7); /* lprie */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    goto v106;

v106:
    v117 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v33;
    v117 = nil;
    { popv(2); return onevalue(v117); }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for wedgef */

static Lisp_Object CC_wedgef(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v192, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgef");
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
    v191 = stack[-1];
    fn = elt(env, 8); /* dim!<deg */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    if (v191 == nil) goto v28;
    v191 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v191); }

v28:
    v191 = stack[-1];
    v192 = qcar(v191);
    v191 = elt(env, 2); /* hodge */
    if (!consp(v192)) goto v130;
    v192 = qcar(v192);
    if (!(v192 == v191)) goto v130;
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v191 = qcar(v191);
    fn = elt(env, 9); /* deg!*form */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    stack[-2] = v191;
    stack[0] = stack[-2];
    v191 = stack[-1];
    v191 = qcdr(v191);
    fn = elt(env, 10); /* deg!*farg */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    if (equal(stack[0], v191)) goto v55;
    v191 = stack[-1];
    {
        popv(4);
        fn = elt(env, 11); /* mkwedge */
        return (*qfn1(fn))(qenv(fn), v191);
    }

v55:
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v193 = qcar(v191);
    v192 = (Lisp_Object)17; /* 1 */
    v191 = (Lisp_Object)17; /* 1 */
    v191 = list2star(v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    stack[0] = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    v191 = stack[-1];
    v191 = qcdr(v191);
    v191 = qcdr(v191);
    if (v191 == nil) goto v99;
    v191 = stack[-1];
    v191 = qcdr(v191);
    fn = elt(env, 12); /* mkuniquewedge1 */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    goto v117;

v117:
    fn = elt(env, 13); /* hodgepf */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 14); /* mkunarywedge */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 15); /* wedgepf2 */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    stack[0] = stack[-2];
    v191 = qvalue(elt(env, 3)); /* dimex!* */
    fn = elt(env, 16); /* negf */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 17); /* addf */
    v191 = (*qfn2(fn))(qenv(fn), stack[-2], v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 18); /* multf */
    v191 = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 19); /* mksgnsq */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    {
        Lisp_Object v139 = stack[-1];
        popv(4);
        fn = elt(env, 20); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v139, v191);
    }

v99:
    v191 = stack[-1];
    v191 = qcdr(v191);
    v193 = qcar(v191);
    v192 = (Lisp_Object)17; /* 1 */
    v191 = (Lisp_Object)17; /* 1 */
    v191 = list2star(v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    goto v117;

v130:
    v191 = stack[-1];
    v192 = qcar(v191);
    v191 = elt(env, 4); /* d */
    if (!consp(v192)) goto v194;
    v192 = qcar(v192);
    if (!(v192 == v191)) goto v194;
    v192 = elt(env, 4); /* d */
    v191 = elt(env, 5); /* noxpnd */
    v191 = Lflagp(nil, v192, v191);
    env = stack[-3];
    if (v191 == nil) goto v107;
    v191 = qvalue(elt(env, 6)); /* t */
    goto v195;

v195:
    if (v191 == nil) goto v196;
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v192 = qcar(v191);
    v191 = stack[-1];
    v191 = qcdr(v191);
    v191 = cons(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 21); /* dwedge */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 14); /* mkunarywedge */
    stack[-2] = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v193 = qcar(v191);
    v192 = (Lisp_Object)17; /* 1 */
    v191 = (Lisp_Object)17; /* 1 */
    v191 = list2star(v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    stack[0] = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    v191 = stack[-1];
    v191 = qcdr(v191);
    v191 = qcdr(v191);
    if (v191 == nil) goto v197;
    v191 = stack[-1];
    v191 = qcdr(v191);
    fn = elt(env, 21); /* dwedge */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    goto v198;

v198:
    fn = elt(env, 14); /* mkunarywedge */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 15); /* wedgepf2 */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v191 = qcar(v191);
    fn = elt(env, 9); /* deg!*form */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 19); /* mksgnsq */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    stack[-1] = v191;
    v191 = stack[-1];
    v191 = qcar(v191);
    fn = elt(env, 16); /* negf */
    v192 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    v191 = stack[-1];
    v191 = qcdr(v191);
    v191 = cons(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 20); /* multpfsq */
    v191 = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    {
        Lisp_Object v199 = stack[-2];
        popv(4);
        fn = elt(env, 22); /* addpf */
        return (*qfn2(fn))(qenv(fn), v199, v191);
    }

v197:
    v191 = stack[-1];
    v191 = qcdr(v191);
    v191 = qcar(v191);
    fn = elt(env, 23); /* exdfk */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    goto v198;

v196:
    v191 = stack[-1];
    {
        popv(4);
        fn = elt(env, 11); /* mkwedge */
        return (*qfn1(fn))(qenv(fn), v191);
    }

v107:
    v192 = qvalue(elt(env, 7)); /* lftshft!* */
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v191 = qcar(v191);
    fn = elt(env, 24); /* smemqlp */
    v191 = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    goto v195;

v194:
    v191 = qvalue(elt(env, 1)); /* nil */
    goto v195;
/* error exit handlers */
v140:
    popv(4);
    return nil;
}



/* Code for plubf */

static Lisp_Object CC_plubf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v199, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plubf");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v31;
    stack[-7] = v0;
/* end of prologue */
    v139 = stack[-7];
    v139 = qcdr(v139);
    v199 = qcar(v139);
    stack[-8] = v199;
    v139 = (Lisp_Object)1; /* 0 */
    if (v199 == v139) goto v29;
    v139 = stack[-6];
    v139 = qcdr(v139);
    v199 = qcar(v139);
    stack[-5] = v199;
    v139 = (Lisp_Object)1; /* 0 */
    if (v199 == v139) goto v58;
    v139 = stack[-7];
    v139 = qcdr(v139);
    v199 = qcdr(v139);
    stack[-4] = v199;
    v139 = stack[-6];
    v139 = qcdr(v139);
    v139 = qcdr(v139);
    stack[-3] = v139;
    v199 = difference2(v199, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    stack[-2] = v199;
    v139 = (Lisp_Object)1; /* 0 */
    if (v199 == v139) goto v53;
    stack[-1] = stack[-2];
    v139 = stack[-8];
    v139 = Labsval(nil, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    v139 = stack[-5];
    v139 = Labsval(nil, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    v139 = difference2(stack[0], v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    v139 = plus2(stack[-1], v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    stack[-1] = v139;
    v139 = qvalue(elt(env, 2)); /* !:bprec!: */
    v139 = add1(v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    stack[0] = v139;
    v199 = stack[-1];
    v139 = stack[0];
    v139 = (Lisp_Object)greaterp2(v199, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    v139 = v139 ? lisp_true : nil;
    env = stack[-9];
    if (v139 == nil) goto v131;
    v139 = stack[-7];
    goto v17;

v17:
    stack[-2] = v139;
    v139 = stack[-2];
    v139 = qcdr(v139);
    v139 = qcar(v139);
    v213 = v139;
    v199 = v213;
    v139 = (Lisp_Object)1; /* 0 */
    if (v199 == v139) goto v144;
    v199 = v213;
    v139 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v139 = (*qfn2(fn))(qenv(fn), v199, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    v213 = v139;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v139 = v213;
    stack[0] = qcar(v139);
    v139 = v213;
    v199 = qcdr(v139);
    v139 = stack[-2];
    v139 = qcdr(v139);
    v139 = qcdr(v139);
    v139 = plus2(v199, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    {
        Lisp_Object v215 = stack[-1];
        Lisp_Object v216 = stack[0];
        popv(10);
        return list2star(v215, v216, v139);
    }

v144:
    v213 = elt(env, 1); /* !:rd!: */
    v199 = (Lisp_Object)1; /* 0 */
    v139 = (Lisp_Object)1; /* 0 */
    popv(10);
    return list2star(v213, v199, v139);

v131:
    v139 = stack[0];
    v139 = negate(v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    v139 = (Lisp_Object)lessp2(stack[-1], v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    v139 = v139 ? lisp_true : nil;
    env = stack[-9];
    if (v139 == nil) goto v71;
    v139 = stack[-6];
    goto v17;

v71:
    v199 = stack[-2];
    v139 = (Lisp_Object)1; /* 0 */
    v139 = (Lisp_Object)greaterp2(v199, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    v139 = v139 ? lisp_true : nil;
    env = stack[-9];
    if (v139 == nil) goto v217;
    stack[0] = elt(env, 1); /* !:rd!: */
    v199 = stack[-8];
    v139 = stack[-2];
    v199 = Lash1(nil, v199, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    v139 = stack[-5];
    v199 = plus2(v199, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    v139 = stack[-3];
    v139 = list2star(stack[0], v199, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    goto v17;

v217:
    stack[0] = elt(env, 1); /* !:rd!: */
    stack[-1] = stack[-8];
    stack[-3] = stack[-5];
    v139 = stack[-2];
    v139 = negate(v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    v139 = Lash1(nil, stack[-3], v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    v199 = plus2(stack[-1], v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    v139 = stack[-4];
    v139 = list2star(stack[0], v199, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    goto v17;

v53:
    stack[0] = elt(env, 1); /* !:rd!: */
    v199 = stack[-8];
    v139 = stack[-5];
    v199 = plus2(v199, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    v139 = stack[-4];
    v139 = list2star(stack[0], v199, v139);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-9];
    goto v17;

v58:
    v139 = stack[-7];
    goto v17;

v29:
    v139 = stack[-6];
    goto v17;
/* error exit handlers */
v214:
    popv(10);
    return nil;
}



/* Code for find_triangl_coeff */

static Lisp_Object MS_CDECL CC_find_triangl_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v65, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v62, v26, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "find_triangl_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_triangl_coeff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v12 = v65;
    v62 = v31;
    v26 = v0;
/* end of prologue */
    v44 = v26;
    v26 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* find_triangle_coeff */
        return (*qfnn(fn))(qenv(fn), 4, v44, v26, v62, v12);
    }
}



/* Code for formsetq0 */

static Lisp_Object MS_CDECL CC_formsetq0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v65, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v291, v292, v293, v294;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formsetq0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formsetq0");
#endif
    if (stack >= stacklimit)
    {
        push3(v65,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v65);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v65;
    stack[-4] = v31;
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    v291 = stack[0];
    v291 = qcdr(v291);
    stack[0] = v291;
    v291 = qcar(v291);
    stack[-2] = v291;
    if (!(symbolp(v291))) goto v59;
    v292 = stack[-2];
    v291 = stack[-4];
    v291 = Latsoc(nil, v292, v291);
    stack[-1] = v291;
    goto v59;

v59:
    v291 = stack[0];
    v291 = qcdr(v291);
    v292 = qcar(v291);
    v291 = elt(env, 1); /* quote */
    if (!consp(v292)) goto v8;
    v292 = qcar(v292);
    if (!(v292 == v291)) goto v8;
    v291 = elt(env, 2); /* symbolic */
    stack[-3] = v291;
    goto v8;

v8:
    v291 = stack[0];
    v291 = qcdr(v291);
    v293 = qcar(v291);
    v292 = stack[-4];
    v291 = stack[-3];
    fn = elt(env, 28); /* form1 */
    v294 = (*qfnn(fn))(qenv(fn), 3, v293, v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    v293 = stack[-4];
    v292 = elt(env, 2); /* symbolic */
    v291 = stack[-3];
    fn = elt(env, 29); /* convertmode1 */
    v291 = (*qfnn(fn))(qenv(fn), 4, v294, v293, v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    stack[-5] = v291;
    v291 = stack[-2];
    if (!consp(v291)) goto v175;
    v291 = stack[-2];
    v291 = qcar(v291);
    if (symbolp(v291)) goto v73;
    v292 = stack[-2];
    v291 = elt(env, 3); /* "assignment" */
    {
        popv(7);
        fn = elt(env, 30); /* typerr */
        return (*qfn2(fn))(qenv(fn), v292, v291);
    }

v73:
    v292 = stack[-2];
    v291 = stack[-3];
    fn = elt(env, 31); /* macrochk */
    v291 = (*qfn2(fn))(qenv(fn), v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    stack[-2] = v291;
    if (!consp(v291)) goto v129;
    v291 = stack[-2];
    v292 = qcar(v291);
    v291 = elt(env, 4); /* rtype */
    v292 = get(v292, v291);
    env = stack[-6];
    v291 = elt(env, 5); /* array */
    v291 = (v292 == v291 ? lisp_true : nil);
    goto v39;

v39:
    if (v291 == nil) goto v37;
    stack[0] = elt(env, 7); /* setel */
    v293 = stack[-2];
    v292 = stack[-4];
    v291 = stack[-3];
    fn = elt(env, 32); /* intargfn */
    v292 = (*qfnn(fn))(qenv(fn), 3, v293, v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    v291 = stack[-5];
    {
        Lisp_Object v296 = stack[0];
        popv(7);
        return list3(v296, v292, v291);
    }

v37:
    v291 = stack[-2];
    if (!consp(v291)) goto v152;
    v291 = stack[-2];
    v291 = qcdr(v291);
    if (v291 == nil) goto v297;
    v291 = stack[-2];
    v292 = qcar(v291);
    v291 = elt(env, 4); /* rtype */
    v292 = get(v292, v291);
    env = stack[-6];
    v291 = elt(env, 8); /* vector */
    if (v292 == v291) goto v194;
    v291 = stack[-2];
    v291 = qcdr(v291);
    v291 = qcar(v291);
    v291 = Lsimple_vectorp(nil, v291);
    env = stack[-6];
    if (!(v291 == nil)) goto v124;
    v291 = stack[-2];
    v291 = qcdr(v291);
    v292 = qcar(v291);
    v291 = elt(env, 10); /* vecfn */
    v291 = Lflagpcar(nil, v292, v291);
    env = stack[-6];
    goto v124;

v124:
    if (v291 == nil) goto v165;
    v293 = stack[0];
    v292 = stack[-4];
    v291 = stack[-3];
    {
        popv(7);
        fn = elt(env, 33); /* putvect */
        return (*qfnn(fn))(qenv(fn), 3, v293, v292, v291);
    }

v165:
    v292 = stack[-2];
    v291 = elt(env, 11); /* part */
    if (!consp(v292)) goto v198;
    v292 = qcar(v292);
    if (!(v292 == v291)) goto v198;
    stack[-1] = elt(env, 12); /* list */
    v291 = elt(env, 13); /* setpart!* */
    stack[0] = Lmkquote(nil, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    v291 = stack[-2];
    v293 = qcdr(v291);
    v292 = stack[-4];
    v291 = stack[-3];
    fn = elt(env, 34); /* formlis */
    v291 = (*qfnn(fn))(qenv(fn), 3, v293, v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    stack[0] = list2star(stack[-1], stack[0], v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    v291 = stack[-5];
    v291 = ncons(v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    {
        Lisp_Object v298 = stack[0];
        popv(7);
        return Lnconc(nil, v298, v291);
    }

v198:
    v291 = stack[-2];
    if (!consp(v291)) goto v214;
    v291 = stack[-2];
    v292 = qcar(v291);
    v291 = elt(env, 14); /* setqfn */
    v291 = get(v292, v291);
    env = stack[-6];
    stack[-1] = v291;
    goto v140;

v140:
    if (v291 == nil) goto v299;
    v291 = stack[-2];
    v292 = qcdr(v291);
    v291 = stack[0];
    v291 = qcdr(v291);
    v292 = Lappend(nil, v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    v291 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 35); /* applsmacro */
    v293 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    v292 = stack[-4];
    v291 = stack[-3];
    {
        popv(7);
        fn = elt(env, 28); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v293, v292, v291);
    }

v299:
    v292 = stack[-3];
    v291 = elt(env, 2); /* symbolic */
    if (v292 == v291) goto v300;
    v291 = qvalue(elt(env, 6)); /* nil */
    goto v301;

v301:
    if (v291 == nil) goto v302;
    stack[0] = elt(env, 17); /* rsetf */
    v293 = stack[-2];
    v292 = stack[-4];
    v291 = stack[-3];
    fn = elt(env, 28); /* form1 */
    v292 = (*qfnn(fn))(qenv(fn), 3, v293, v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    v291 = stack[-5];
    {
        Lisp_Object v303 = stack[0];
        popv(7);
        return list3(v303, v292, v291);
    }

v302:
    stack[0] = elt(env, 18); /* setk */
    v293 = stack[-2];
    v292 = stack[-4];
    v291 = elt(env, 19); /* algebraic */
    fn = elt(env, 28); /* form1 */
    v292 = (*qfnn(fn))(qenv(fn), 3, v293, v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    v291 = stack[-5];
    {
        Lisp_Object v304 = stack[0];
        popv(7);
        return list3(v304, v292, v291);
    }

v300:
    v291 = qvalue(elt(env, 15)); /* !*rlisp88 */
    if (!(v291 == nil)) goto v301;
    v292 = stack[-2];
    v291 = elt(env, 16); /* structfetch */
    v291 = Leqcar(nil, v292, v291);
    env = stack[-6];
    goto v301;

v214:
    v291 = qvalue(elt(env, 6)); /* nil */
    goto v140;

v194:
    v291 = qvalue(elt(env, 9)); /* t */
    goto v124;

v297:
    v291 = qvalue(elt(env, 6)); /* nil */
    goto v124;

v152:
    v291 = qvalue(elt(env, 6)); /* nil */
    goto v124;

v129:
    v291 = qvalue(elt(env, 6)); /* nil */
    goto v39;

v175:
    v291 = stack[-2];
    if (symbolp(v291)) goto v305;
    v292 = stack[-2];
    v291 = elt(env, 3); /* "assignment" */
    {
        popv(7);
        fn = elt(env, 30); /* typerr */
        return (*qfn2(fn))(qenv(fn), v292, v291);
    }

v305:
    v292 = stack[-2];
    v291 = elt(env, 20); /* reserved */
    v291 = Lflagp(nil, v292, v291);
    env = stack[-6];
    if (v291 == nil) goto v306;
    v292 = stack[-2];
    v291 = stack[-4];
    v291 = Latsoc(nil, v292, v291);
    v291 = (v291 == nil ? lisp_true : nil);
    goto v307;

v307:
    if (v291 == nil) goto v308;
    v292 = stack[-2];
    v291 = elt(env, 21); /* "is a reserved identifier" */
    v291 = list2(v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    v292 = v291;
    v291 = v292;
    qvalue(elt(env, 22)) = v291; /* errmsg!* */
    v291 = qvalue(elt(env, 23)); /* !*protfg */
    if (!(v291 == nil)) goto v309;
    v291 = v292;
    fn = elt(env, 36); /* lprie */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    goto v309;

v309:
    v291 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v295;
    v291 = nil;
    { popv(7); return onevalue(v291); }

v308:
    v292 = stack[-2];
    v291 = elt(env, 24); /* share */
    v291 = Lflagp(nil, v292, v291);
    env = stack[-6];
    if (v291 == nil) goto v310;
    v292 = stack[-2];
    v291 = stack[-4];
    fn = elt(env, 37); /* symbid */
    stack[0] = (*qfn2(fn))(qenv(fn), v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    v293 = elt(env, 25); /* progn */
    v292 = elt(env, 26); /* (setq alglist!* (cons nil nil)) */
    v291 = stack[-5];
    v291 = list3(v293, v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    {
        Lisp_Object v311 = stack[0];
        popv(7);
        fn = elt(env, 38); /* mksetq */
        return (*qfn2(fn))(qenv(fn), v311, v291);
    }

v310:
    v292 = stack[-3];
    v291 = elt(env, 2); /* symbolic */
    if (v292 == v291) goto v312;
    v291 = stack[-1];
    if (!(v291 == nil)) goto v313;
    v292 = stack[-5];
    v291 = elt(env, 1); /* quote */
    v291 = Leqcar(nil, v292, v291);
    env = stack[-6];
    goto v313;

v313:
    if (v291 == nil) goto v314;
    v292 = stack[-2];
    v291 = stack[-4];
    fn = elt(env, 37); /* symbid */
    v292 = (*qfn2(fn))(qenv(fn), v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-6];
    v291 = stack[-5];
    {
        popv(7);
        fn = elt(env, 38); /* mksetq */
        return (*qfn2(fn))(qenv(fn), v292, v291);
    }

v314:
    v291 = stack[0];
    v291 = qcdr(v291);
    v291 = qcar(v291);
    v291 = Lsimple_vectorp(nil, v291);
    env = stack[-6];
    if (!(v291 == nil)) goto v315;
    v291 = stack[0];
    v291 = qcdr(v291);
    v292 = qcar(v291);
    v291 = elt(env, 10); /* vecfn */
    v291 = Lflagpcar(nil, v292, v291);
    env = stack[-6];
    if (!(v291 == nil)) goto v315;
    stack[0] = elt(env, 18); /* setk */
    v291 = stack[-2];
    v292 = Lmkquote(nil, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    v291 = stack[-5];
    {
        Lisp_Object v316 = stack[0];
        popv(7);
        return list3(v316, v292, v291);
    }

v315:
    stack[-1] = elt(env, 27); /* setv */
    v291 = stack[-2];
    v292 = Lmkquote(nil, v291);
    nil = C_nil;
    if (exception_pending()) goto v295;
    v291 = stack[0];
    v291 = qcdr(v291);
    v291 = qcar(v291);
    {
        Lisp_Object v317 = stack[-1];
        popv(7);
        return list3(v317, v292, v291);
    }

v312:
    v291 = qvalue(elt(env, 9)); /* t */
    goto v313;

v306:
    v291 = qvalue(elt(env, 6)); /* nil */
    goto v307;
/* error exit handlers */
v295:
    popv(7);
    return nil;
}



/* Code for msolve!-polyn */

static Lisp_Object CC_msolveKpolyn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v326, v281, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-polyn");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v31;
    stack[-9] = v0;
/* end of prologue */
    v326 = stack[-8];
    v326 = qcar(v326);
    stack[-10] = v326;
    v326 = stack[-8];
    v326 = qcdr(v326);
    if (v326 == nil) goto v56;
    v326 = (Lisp_Object)1; /* 0 */
    stack[-7] = v326;
    goto v116;

v116:
    v326 = qvalue(elt(env, 1)); /* current!-modulus */
    v281 = sub1(v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = stack[-7];
    v326 = difference2(v281, v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = Lminusp(nil, v326);
    env = stack[-11];
    if (v326 == nil) goto v50;
    v326 = qvalue(elt(env, 2)); /* nil */
    { popv(12); return onevalue(v326); }

v50:
    stack[0] = stack[-9];
    v281 = stack[-10];
    v326 = stack[-7];
    v326 = cons(v281, v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = ncons(v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    fn = elt(env, 3); /* subf */
    v326 = (*qfn2(fn))(qenv(fn), stack[0], v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v281 = qcar(v326);
    v326 = stack[-8];
    v326 = qcdr(v326);
    v326 = CC_msolveKpolyn(env, v281, v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    stack[-3] = v326;
    v326 = stack[-3];
    if (v326 == nil) goto v134;
    v326 = stack[-3];
    v326 = qcar(v326);
    v140 = stack[-10];
    v281 = stack[-7];
    v326 = acons(v140, v281, v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = ncons(v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    stack[-1] = v326;
    stack[-2] = v326;
    goto v48;

v48:
    v326 = stack[-3];
    v326 = qcdr(v326);
    stack[-3] = v326;
    v326 = stack[-3];
    if (v326 == nil) goto v97;
    stack[0] = stack[-1];
    v326 = stack[-3];
    v326 = qcar(v326);
    v140 = stack[-10];
    v281 = stack[-7];
    v326 = acons(v140, v281, v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = ncons(v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = Lrplacd(nil, stack[0], v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = stack[-1];
    v326 = qcdr(v326);
    stack[-1] = v326;
    goto v48;

v97:
    v326 = stack[-2];
    goto v8;

v8:
    stack[-6] = v326;
    v326 = stack[-6];
    fn = elt(env, 4); /* lastpair */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    stack[-5] = v326;
    v326 = stack[-7];
    v326 = add1(v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    stack[-7] = v326;
    v326 = stack[-5];
    if (!consp(v326)) goto v116;
    else goto v288;

v288:
    v326 = qvalue(elt(env, 1)); /* current!-modulus */
    v281 = sub1(v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = stack[-7];
    v326 = difference2(v281, v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = Lminusp(nil, v326);
    env = stack[-11];
    if (!(v326 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    stack[0] = stack[-9];
    v281 = stack[-10];
    v326 = stack[-7];
    v326 = cons(v281, v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = ncons(v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    fn = elt(env, 3); /* subf */
    v326 = (*qfn2(fn))(qenv(fn), stack[0], v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v281 = qcar(v326);
    v326 = stack[-8];
    v326 = qcdr(v326);
    v326 = CC_msolveKpolyn(env, v281, v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    stack[-3] = v326;
    v326 = stack[-3];
    if (v326 == nil) goto v150;
    v326 = stack[-3];
    v326 = qcar(v326);
    v140 = stack[-10];
    v281 = stack[-7];
    v326 = acons(v140, v281, v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = ncons(v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    stack[-1] = v326;
    stack[-2] = v326;
    goto v327;

v327:
    v326 = stack[-3];
    v326 = qcdr(v326);
    stack[-3] = v326;
    v326 = stack[-3];
    if (v326 == nil) goto v197;
    stack[0] = stack[-1];
    v326 = stack[-3];
    v326 = qcar(v326);
    v140 = stack[-10];
    v281 = stack[-7];
    v326 = acons(v140, v281, v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = ncons(v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = Lrplacd(nil, stack[0], v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = stack[-1];
    v326 = qcdr(v326);
    stack[-1] = v326;
    goto v327;

v197:
    v326 = stack[-2];
    goto v104;

v104:
    v326 = Lrplacd(nil, stack[-4], v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    v326 = stack[-5];
    fn = elt(env, 4); /* lastpair */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    stack[-5] = v326;
    v326 = stack[-7];
    v326 = add1(v326);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-11];
    stack[-7] = v326;
    goto v288;

v150:
    v326 = qvalue(elt(env, 2)); /* nil */
    goto v104;

v134:
    v326 = qvalue(elt(env, 2)); /* nil */
    goto v8;

v56:
    v281 = stack[-9];
    v326 = stack[-8];
    v326 = qcar(v326);
    {
        popv(12);
        fn = elt(env, 5); /* msolve!-poly1 */
        return (*qfn2(fn))(qenv(fn), v281, v326);
    }
/* error exit handlers */
v162:
    popv(12);
    return nil;
}



/* Code for basic!-kern */

static Lisp_Object CC_basicKkern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basic-kern");
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
    v61 = v0;
/* end of prologue */
    v83 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v83;
    v83 = v61;
    stack[0] = v83;
    goto v112;

v112:
    v83 = stack[0];
    if (v83 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v83 = stack[0];
    v83 = qcar(v83);
    fn = elt(env, 2); /* basic!-kern1 */
    v61 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v83 = stack[-1];
    fn = elt(env, 3); /* union */
    v83 = (*qfn2(fn))(qenv(fn), v61, v83);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    stack[-1] = v83;
    v83 = stack[0];
    v83 = qcdr(v83);
    stack[0] = v83;
    goto v112;
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for gitimes!: */

static Lisp_Object CC_gitimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v34, v80, v111;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gitimes:");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v33 = v31;
    v34 = v0;
/* end of prologue */
    v80 = v34;
    v80 = qcdr(v80);
    v111 = qcar(v80);
    v34 = qcdr(v34);
    v80 = qcdr(v34);
    v34 = v33;
    v34 = qcdr(v34);
    v34 = qcar(v34);
    v33 = qcdr(v33);
    v33 = qcdr(v33);
    stack[-5] = v111;
    stack[-4] = v80;
    stack[-3] = v34;
    stack[-2] = v33;
    stack[-1] = elt(env, 1); /* !:gi!: */
    v34 = stack[-5];
    v33 = stack[-3];
    stack[0] = times2(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v34 = stack[-4];
    v33 = stack[-2];
    v33 = times2(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    stack[0] = difference2(stack[0], v33);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v34 = stack[-5];
    v33 = stack[-2];
    stack[-2] = times2(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v34 = stack[-3];
    v33 = stack[-4];
    v33 = times2(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v33 = plus2(stack[-2], v33);
    nil = C_nil;
    if (exception_pending()) goto v99;
    {
        Lisp_Object v3 = stack[-1];
        Lisp_Object v4 = stack[0];
        popv(7);
        return list2star(v3, v4, v33);
    }
/* error exit handlers */
v99:
    popv(7);
    return nil;
}



/* Code for pasf_zcong */

static Lisp_Object CC_pasf_zcong(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v331, v283;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_zcong");
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
    v331 = v0;
/* end of prologue */
    v204 = v331;
    v204 = Lconsp(nil, v204);
    env = stack[0];
    if (v204 == nil) { popv(1); return onevalue(v331); }
    v204 = v331;
    v204 = qcar(v204);
    v204 = Lconsp(nil, v204);
    env = stack[0];
    if (v204 == nil) { popv(1); return onevalue(v331); }
    v204 = v331;
    v204 = qcar(v204);
    v283 = qcar(v204);
    v204 = elt(env, 1); /* (cong ncong) */
    v204 = Lmemq(nil, v283, v204);
    if (v204 == nil) { popv(1); return onevalue(v331); }
    v204 = v331;
    v204 = qcar(v204);
    v204 = qcdr(v204);
    if (v204 == nil) goto v5;
    v204 = v331;
    v204 = qcdr(v204);
    v204 = qcar(v204);
    if (v204 == nil) goto v75;
    v204 = qvalue(elt(env, 8)); /* nil */
    goto v74;

v74:
    if (v204 == nil) goto v132;
    v204 = elt(env, 2); /* true */
    { popv(1); return onevalue(v204); }

v132:
    v204 = v331;
    v204 = qcdr(v204);
    v204 = qcar(v204);
    if (v204 == nil) goto v172;
    v204 = qvalue(elt(env, 8)); /* nil */
    goto v153;

v153:
    if (v204 == nil) { popv(1); return onevalue(v331); }
    v204 = elt(env, 4); /* false */
    { popv(1); return onevalue(v204); }

v172:
    v283 = v331;
    v204 = elt(env, 2); /* true */
    if (v283 == v204) goto v173;
    v283 = v331;
    v204 = elt(env, 4); /* false */
    v204 = (v283 == v204 ? lisp_true : nil);
    goto v149;

v149:
    if (v204 == nil) goto v332;
    v204 = v331;
    v283 = v204;
    goto v333;

v333:
    v204 = elt(env, 9); /* ncong */
    v204 = (v283 == v204 ? lisp_true : nil);
    goto v153;

v332:
    v204 = v331;
    v204 = qcar(v204);
    v204 = Lconsp(nil, v204);
    env = stack[0];
    if (v204 == nil) goto v187;
    v204 = v331;
    v204 = qcar(v204);
    v204 = qcar(v204);
    v283 = v204;
    goto v333;

v187:
    v204 = v331;
    v204 = qcar(v204);
    v283 = v204;
    goto v333;

v173:
    v204 = qvalue(elt(env, 3)); /* t */
    goto v149;

v75:
    v283 = v331;
    v204 = elt(env, 2); /* true */
    if (v283 == v204) goto v189;
    v283 = v331;
    v204 = elt(env, 4); /* false */
    v204 = (v283 == v204 ? lisp_true : nil);
    goto v325;

v325:
    if (v204 == nil) goto v129;
    v204 = v331;
    v283 = v204;
    goto v126;

v126:
    v204 = elt(env, 5); /* cong */
    v204 = (v283 == v204 ? lisp_true : nil);
    goto v74;

v129:
    v204 = v331;
    v204 = qcar(v204);
    v204 = Lconsp(nil, v204);
    env = stack[0];
    if (v204 == nil) goto v107;
    v204 = v331;
    v204 = qcar(v204);
    v204 = qcar(v204);
    v283 = v204;
    goto v126;

v107:
    v204 = v331;
    v204 = qcar(v204);
    v283 = v204;
    goto v126;

v189:
    v204 = qvalue(elt(env, 3)); /* t */
    goto v325;

v5:
    v283 = v331;
    v204 = elt(env, 2); /* true */
    if (v283 == v204) goto v115;
    v283 = v331;
    v204 = elt(env, 4); /* false */
    v204 = (v283 == v204 ? lisp_true : nil);
    goto v106;

v106:
    if (v204 == nil) goto v118;
    v204 = v331;
    v283 = v204;
    goto v113;

v113:
    v204 = elt(env, 5); /* cong */
    if (v283 == v204) goto v20;
    v204 = elt(env, 7); /* neq */
    goto v35;

v35:
    v331 = qcdr(v331);
    v331 = qcar(v331);
    v283 = qvalue(elt(env, 8)); /* nil */
    popv(1);
    return list3(v204, v331, v283);

v20:
    v204 = elt(env, 6); /* equal */
    goto v35;

v118:
    v204 = v331;
    v204 = qcar(v204);
    v204 = Lconsp(nil, v204);
    env = stack[0];
    if (v204 == nil) goto v4;
    v204 = v331;
    v204 = qcar(v204);
    v204 = qcar(v204);
    v283 = v204;
    goto v113;

v4:
    v204 = v331;
    v204 = qcar(v204);
    v283 = v204;
    goto v113;

v115:
    v204 = qvalue(elt(env, 3)); /* t */
    goto v106;
}



/* Code for lto_setminus */

static Lisp_Object CC_lto_setminus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v24, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_setminus");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v31;
    v122 = v0;
/* end of prologue */
    stack[-4] = v122;
    goto v52;

v52:
    v122 = stack[-4];
    if (v122 == nil) goto v56;
    v122 = stack[-4];
    v122 = qcar(v122);
    v134 = v122;
    v24 = v134;
    v122 = stack[-3];
    v122 = Lmember(nil, v24, v122);
    if (v122 == nil) goto v43;
    v122 = nil;
    goto v44;

v44:
    stack[-2] = v122;
    v122 = stack[-2];
    fn = elt(env, 2); /* lastpair */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-5];
    stack[-1] = v122;
    v122 = stack[-4];
    v122 = qcdr(v122);
    stack[-4] = v122;
    v122 = stack[-1];
    if (!consp(v122)) goto v52;
    else goto v27;

v27:
    v122 = stack[-4];
    if (v122 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v122 = stack[-4];
    v122 = qcar(v122);
    v134 = v122;
    v24 = v134;
    v122 = stack[-3];
    v122 = Lmember(nil, v24, v122);
    if (v122 == nil) goto v22;
    v122 = nil;
    goto v55;

v55:
    v122 = Lrplacd(nil, stack[0], v122);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-5];
    v122 = stack[-1];
    fn = elt(env, 2); /* lastpair */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-5];
    stack[-1] = v122;
    v122 = stack[-4];
    v122 = qcdr(v122);
    stack[-4] = v122;
    goto v27;

v22:
    v122 = v134;
    v122 = ncons(v122);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-5];
    goto v55;

v43:
    v122 = v134;
    v122 = ncons(v122);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-5];
    goto v44;

v56:
    v122 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v122); }
/* error exit handlers */
v37:
    popv(6);
    return nil;
}



/* Code for fnrd */

static Lisp_Object MS_CDECL CC_fnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnrd");
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
    stack[0] = nil;
    fn = elt(env, 3); /* lex */
    v10 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    v63 = qvalue(elt(env, 1)); /* char */
    v10 = elt(env, 2); /* (c i) */
    if (equal(v63, v10)) goto v42;
    v10 = qvalue(elt(env, 1)); /* char */
    v63 = Lcompress(nil, v10);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    v10 = (Lisp_Object)321; /* 20 */
    fn = elt(env, 4); /* errorml */
    v10 = (*qfn2(fn))(qenv(fn), v63, v10);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    goto v57;

v57:
    v10 = stack[0];
    if (!(!consp(v10))) goto v59;
    v10 = stack[0];
    v10 = ncons(v10);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    fn = elt(env, 5); /* operator */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    fn = elt(env, 6); /* aeval */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    goto v59;

v59:
    fn = elt(env, 3); /* lex */
    v10 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v20;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v42:
    fn = elt(env, 7); /* mathml2 */
    v10 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    stack[0] = v10;
    goto v57;
/* error exit handlers */
v20:
    popv(2);
    return nil;
}



/* Code for simpimpart */

static Lisp_Object CC_simpimpart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpimpart");
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
    v27 = v0;
/* end of prologue */
    v52 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*factor */
    qvalue(elt(env, 2)) = v52; /* !*factor */
    v52 = v27;
    v52 = qcar(v52);
    fn = elt(env, 3); /* simp!* */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    fn = elt(env, 4); /* impartsq */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*factor */
    { popv(2); return onevalue(v52); }
/* error exit handlers */
v17:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*factor */
    popv(2);
    return nil;
}



/* Code for vdp2a */

static Lisp_Object CC_vdp2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v52 = v0;
/* end of prologue */
    v52 = qcdr(v52);
    v52 = qcdr(v52);
    v52 = qcdr(v52);
    v52 = qcar(v52);
    {
        fn = elt(env, 1); /* dip2a */
        return (*qfn1(fn))(qenv(fn), v52);
    }
}



/* Code for inprinla */

static Lisp_Object MS_CDECL CC_inprinla(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v65, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "inprinla");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inprinla");
#endif
    if (stack >= stacklimit)
    {
        push3(v65,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v65);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v65;
    stack[-1] = v31;
    stack[-2] = v0;
/* end of prologue */
    v131 = stack[-2];
    v76 = elt(env, 1); /* alt */
    v76 = get(v131, v76);
    env = stack[-4];
    if (!(v76 == nil)) goto v112;
    v76 = stack[0];
    v131 = qcar(v76);
    v76 = stack[-1];
    fn = elt(env, 5); /* maprintla */
    v76 = (*qfn2(fn))(qenv(fn), v131, v76);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-4];
    goto v57;

v57:
    v76 = stack[0];
    v76 = qcdr(v76);
    stack[0] = v76;
    goto v112;

v112:
    v76 = stack[0];
    if (v76 == nil) goto v18;
    v76 = stack[0];
    v76 = qcar(v76);
    if (!consp(v76)) goto v47;
    stack[-3] = stack[-2];
    v76 = stack[0];
    v76 = qcar(v76);
    v131 = qcar(v76);
    v76 = elt(env, 1); /* alt */
    v76 = Lget(nil, v131, v76);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-4];
    v76 = (stack[-3] == v76 ? lisp_true : nil);
    v76 = (v76 == nil ? lisp_true : nil);
    goto v63;

v63:
    if (v76 == nil) goto v167;
    v76 = stack[-2];
    fn = elt(env, 6); /* oprinla */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-4];
    v76 = stack[0];
    v131 = qcar(v76);
    v76 = elt(env, 4); /* minus */
    if (!consp(v131)) goto v13;
    v131 = qcar(v131);
    if (!(v131 == v76)) goto v13;
    v76 = stack[0];
    v76 = qcar(v76);
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = (is_number(v76) ? lisp_true : nil);
    goto v134;

v134:
    if (v76 == nil) goto v90;
    v76 = stack[0];
    v76 = qcar(v76);
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = negate(v76);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-4];
    v131 = v76;
    goto v81;

v81:
    v76 = stack[-1];
    fn = elt(env, 5); /* maprintla */
    v76 = (*qfn2(fn))(qenv(fn), v131, v76);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-4];
    goto v57;

v90:
    v76 = stack[0];
    v76 = qcar(v76);
    v131 = v76;
    goto v81;

v13:
    v76 = qvalue(elt(env, 2)); /* nil */
    goto v134;

v167:
    v76 = stack[0];
    v131 = qcar(v76);
    v76 = stack[-1];
    fn = elt(env, 5); /* maprintla */
    v76 = (*qfn2(fn))(qenv(fn), v131, v76);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-4];
    goto v57;

v47:
    v76 = qvalue(elt(env, 3)); /* t */
    goto v63;

v18:
    v76 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v76); }
/* error exit handlers */
v95:
    popv(5);
    return nil;
}



/* Code for absf */

static Lisp_Object CC_absf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for absf");
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
    v56 = stack[0];
    fn = elt(env, 1); /* minusf */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    if (v56 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v56 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* negf */
        return (*qfn1(fn))(qenv(fn), v56);
    }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for toolongassignp */

static Lisp_Object CC_toolongassignp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for toolongassignp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v112 = v0;
/* end of prologue */
    v112 = qcdr(v112);
    v112 = qcdr(v112);
    v112 = qcar(v112);
    {
        fn = elt(env, 1); /* toolongexpp */
        return (*qfn1(fn))(qenv(fn), v112);
    }
}



/* Code for collectphysops_reversed */

static Lisp_Object CC_collectphysops_reversed(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectphysops_reversed");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v175 = stack[-1];
    if (!consp(v175)) goto v112;
    v175 = stack[-1];
    fn = elt(env, 2); /* physopp */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    if (v175 == nil) goto v7;
    stack[-2] = stack[-1];
    v175 = stack[-1];
    fn = elt(env, 3); /* collectindices */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    fn = elt(env, 4); /* removeindices */
    v117 = (*qfn2(fn))(qenv(fn), stack[-2], v175);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v175 = stack[0];
    popv(4);
    return cons(v117, v175);

v7:
    v175 = stack[-1];
    if (!consp(v175)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v175 = stack[-1];
    v117 = qcar(v175);
    v175 = stack[0];
    v175 = CC_collectphysops_reversed(env, v117, v175);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    stack[0] = v175;
    v175 = stack[-1];
    v175 = qcdr(v175);
    stack[-1] = v175;
    goto v7;

v112:
    v175 = stack[-1];
    fn = elt(env, 2); /* physopp */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v34;
    if (v175 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v117 = stack[-1];
    v175 = stack[0];
    popv(4);
    return cons(v117, v175);
/* error exit handlers */
v34:
    popv(4);
    return nil;
}



/* Code for nzero */

static Lisp_Object CC_nzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nzero");
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
    goto v11;

v11:
    v88 = stack[0];
    v61 = (Lisp_Object)1; /* 0 */
    if (v88 == v61) goto v52;
    v88 = (Lisp_Object)1; /* 0 */
    v61 = stack[-1];
    v61 = cons(v88, v61);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    stack[-1] = v61;
    v61 = stack[0];
    v61 = sub1(v61);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    stack[0] = v61;
    goto v11;

v52:
    v61 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v61);
    }
/* error exit handlers */
v35:
    popv(3);
    return nil;
}



/* Code for fs!:onep!: */

static Lisp_Object CC_fsTonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:onep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v51 = v0;
/* end of prologue */
    v51 = qcdr(v51);
    {
        fn = elt(env, 1); /* fs!:onep */
        return (*qfn1(fn))(qenv(fn), v51);
    }
}



/* Code for pst_subpst */

static Lisp_Object CC_pst_subpst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_subpst");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v29 = v31;
    v56 = v0;
/* end of prologue */
    stack[0] = qcdr(v56);
    v56 = v29;
    v56 = sub1(v56);
    nil = C_nil;
    if (exception_pending()) goto v16;
    v56 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v56/(16/CELL)));
    { popv(1); return onevalue(v56); }
/* error exit handlers */
v16:
    popv(1);
    return nil;
}



/* Code for diff!-over!-k!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKoverKkKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v65, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v85, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-over-k-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff-over-k-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v65,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v65);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v65;
    stack[-2] = v31;
    stack[-3] = v0;
/* end of prologue */
    v103 = stack[-3];
    if (!consp(v103)) goto v11;
    v103 = stack[-3];
    v103 = qcar(v103);
    v103 = (consp(v103) ? nil : lisp_true);
    goto v27;

v27:
    if (v103 == nil) goto v43;
    v103 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v103); }

v43:
    v103 = stack[-3];
    v103 = qcar(v103);
    v103 = qcar(v103);
    v85 = qcar(v103);
    v103 = stack[-1];
    if (equal(v85, v103)) goto v49;
    v103 = stack[-3];
    v103 = qcar(v103);
    stack[-4] = qcar(v103);
    v103 = stack[-3];
    v103 = qcar(v103);
    v86 = qcdr(v103);
    v85 = stack[-2];
    v103 = stack[-1];
    stack[0] = CC_diffKoverKkKmodKp(env, 3, v86, v85, v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v103 = stack[-3];
    v86 = qcdr(v103);
    v85 = stack[-2];
    v103 = stack[-1];
    v103 = CC_diffKoverKkKmodKp(env, 3, v86, v85, v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    {
        Lisp_Object v136 = stack[-4];
        Lisp_Object v89 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v136, v89, v103);
    }

v49:
    v103 = stack[-3];
    v103 = qcar(v103);
    v103 = qcar(v103);
    v85 = qcdr(v103);
    v103 = (Lisp_Object)17; /* 1 */
    if (v85 == v103) goto v60;
    v103 = stack[-1];
    fn = elt(env, 4); /* fkern */
    v85 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v103 = stack[-3];
    v103 = qcar(v103);
    v103 = qcar(v103);
    v103 = qcdr(v103);
    v103 = (Lisp_Object)((int32_t)(v103) - 0x10);
    fn = elt(env, 5); /* getpower */
    stack[-4] = (*qfn2(fn))(qenv(fn), v85, v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v103 = stack[-3];
    v103 = qcar(v103);
    v103 = qcar(v103);
    v103 = qcdr(v103);
    v85 = Lmodular_number(nil, v103);
    env = stack[-5];
    v103 = stack[-3];
    v103 = qcar(v103);
    v103 = qcdr(v103);
    fn = elt(env, 6); /* times!-mod!-p */
    v85 = (*qfn2(fn))(qenv(fn), v85, v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v103 = stack[-2];
    v103 = Lmodular_number(nil, v103);
    env = stack[-5];
    fn = elt(env, 7); /* quotient!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v85, v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v103 = stack[-3];
    v86 = qcdr(v103);
    v85 = stack[-2];
    v103 = stack[-1];
    v103 = CC_diffKoverKkKmodKp(env, 3, v86, v85, v103);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    {
        Lisp_Object v137 = stack[-4];
        Lisp_Object v138 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v137, v138, v103);
    }

v60:
    v103 = stack[-3];
    v103 = qcar(v103);
    v85 = qcdr(v103);
    v103 = stack[-2];
    v103 = Lmodular_number(nil, v103);
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 7); /* quotient!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v85, v103);
    }

v11:
    v103 = qvalue(elt(env, 1)); /* t */
    goto v27;
/* error exit handlers */
v135:
    popv(6);
    return nil;
}



/* Code for ext_mult */

static Lisp_Object CC_ext_mult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v34, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ext_mult");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v33 = v31;
    v34 = v0;
/* end of prologue */
    v34 = qcdr(v34);
    v33 = qcdr(v33);
    fn = elt(env, 3); /* merge_lists */
    v33 = (*qfn2(fn))(qenv(fn), v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    stack[0] = v33;
    v33 = stack[0];
    if (v33 == nil) goto v26;
    v33 = stack[0];
    v33 = qcdr(v33);
    if (v33 == nil) goto v88;
    v34 = elt(env, 2); /* ext */
    v33 = stack[0];
    v33 = qcdr(v33);
    v33 = cons(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    fn = elt(env, 4); /* !*a2k */
    v80 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    v34 = (Lisp_Object)17; /* 1 */
    v33 = stack[0];
    v33 = qcar(v33);
    v34 = acons(v80, v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    v80 = qvalue(elt(env, 1)); /* nil */
    v33 = (Lisp_Object)17; /* 1 */
    popv(2);
    return acons(v34, v80, v33);

v88:
    v34 = (Lisp_Object)17; /* 1 */
    v33 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v34, v33);

v26:
    v34 = qvalue(elt(env, 1)); /* nil */
    v33 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v34, v33);
/* error exit handlers */
v121:
    popv(2);
    return nil;
}



setup_type const u26_setup[] =
{
    {"gettype",                 CC_gettype,     too_many_1,    wrong_no_1},
    {"mo_2a",                   CC_mo_2a,       too_many_1,    wrong_no_1},
    {"ofsf_ignshift",           too_few_2,      CC_ofsf_ignshift,wrong_no_2},
    {"orddf",                   too_few_2,      CC_orddf,      wrong_no_2},
    {"my+nullsq+p",             CC_myLnullsqLp, too_many_1,    wrong_no_1},
    {"aex_freeids",             CC_aex_freeids, too_many_1,    wrong_no_1},
    {"containerml",             too_few_2,      CC_containerml,wrong_no_2},
    {"on-double1",              CC_onKdouble1,  too_many_1,    wrong_no_1},
    {"evmtest?",                too_few_2,      CC_evmtestW,   wrong_no_2},
    {"pairxvars",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pairxvars},
    {"extadd",                  too_few_2,      CC_extadd,     wrong_no_2},
    {"ofsf_smcpknowl",          CC_ofsf_smcpknowl,too_many_1,  wrong_no_1},
    {"formboollis",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_formboollis},
    {"multdfconst",             too_few_2,      CC_multdfconst,wrong_no_2},
    {"mk+trace",                CC_mkLtrace,    too_many_1,    wrong_no_1},
    {"distribute.multiplicity", too_few_2,      CC_distributeQmultiplicity,wrong_no_2},
    {"ratpoly_quot",            too_few_2,      CC_ratpoly_quot,wrong_no_2},
    {"cgp_lbc",                 CC_cgp_lbc,     too_many_1,    wrong_no_1},
    {"i2cr*",                   CC_i2crH,       too_many_1,    wrong_no_1},
    {"lchk",                    CC_lchk,        too_many_1,    wrong_no_1},
    {"difference:",             too_few_2,      CC_differenceT,wrong_no_2},
    {"rd:difference",           too_few_2,      CC_rdTdifference,wrong_no_2},
    {"prop-simp2",              too_few_2,      CC_propKsimp2, wrong_no_2},
    {"greaterpcdr",             too_few_2,      CC_greaterpcdr,wrong_no_2},
    {"remchkf",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_remchkf},
    {"lpos",                    too_few_2,      CC_lpos,       wrong_no_2},
    {"lessppair",               too_few_2,      CC_lessppair,  wrong_no_2},
    {"giplus:",                 too_few_2,      CC_giplusT,    wrong_no_2},
    {"depend-f",                too_few_2,      CC_dependKf,   wrong_no_2},
    {"pasf_subfof",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_subfof},
    {"omatpir",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_omatpir},
    {"simp_without_resimp",     CC_simp_without_resimp,too_many_1,wrong_no_1},
    {"f2dip11",                 CC_f2dip11,     too_many_1,    wrong_no_1},
    {"wedgef",                  CC_wedgef,      too_many_1,    wrong_no_1},
    {"plubf",                   too_few_2,      CC_plubf,      wrong_no_2},
    {"find_triangl_coeff",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_triangl_coeff},
    {"formsetq0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq0},
    {"msolve-polyn",            too_few_2,      CC_msolveKpolyn,wrong_no_2},
    {"basic-kern",              CC_basicKkern,  too_many_1,    wrong_no_1},
    {"gitimes:",                too_few_2,      CC_gitimesT,   wrong_no_2},
    {"pasf_zcong",              CC_pasf_zcong,  too_many_1,    wrong_no_1},
    {"lto_setminus",            too_few_2,      CC_lto_setminus,wrong_no_2},
    {"fnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnrd},
    {"simpimpart",              CC_simpimpart,  too_many_1,    wrong_no_1},
    {"vdp2a",                   CC_vdp2a,       too_many_1,    wrong_no_1},
    {"inprinla",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_inprinla},
    {"absf",                    CC_absf,        too_many_1,    wrong_no_1},
    {"toolongassignp",          CC_toolongassignp,too_many_1,  wrong_no_1},
    {"collectphysops_reversed", too_few_2,      CC_collectphysops_reversed,wrong_no_2},
    {"nzero",                   CC_nzero,       too_many_1,    wrong_no_1},
    {"fs:onep:",                CC_fsTonepT,    too_many_1,    wrong_no_1},
    {"pst_subpst",              too_few_2,      CC_pst_subpst, wrong_no_2},
    {"diff-over-k-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKoverKkKmodKp},
    {"ext_mult",                too_few_2,      CC_ext_mult,   wrong_no_2},
    {NULL, (one_args *)"u26", (two_args *)"22291 4507109 8921781", 0}
};

/* end of generated code */
