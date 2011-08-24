
/* $destdir\u13.c        Machine generated C code */

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


/* Code for revalind */

static Lisp_Object CC_revalind(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revalind");
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
    stack[0] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v11 = qvalue(elt(env, 2)); /* nil */
    v11 = ncons(v11);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    qvalue(elt(env, 1)) = v11; /* alglist!* */
    v11 = qvalue(elt(env, 3)); /* subfg!* */
    stack[-2] = v11;
    v11 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v11; /* subfg!* */
    v13 = elt(env, 4); /* !0 */
    v12 = (Lisp_Object)1; /* 0 */
    v11 = stack[-1];
    v11 = Lsubst(nil, 3, v13, v12, v11);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    stack[-1] = v11;
    v11 = stack[-1];
    fn = elt(env, 6); /* simp */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    v12 = v11;
    v11 = v12;
    v11 = qcar(v11);
    if (v11 == nil) goto v15;
    v11 = elt(env, 5); /* prepf */
    fn = elt(env, 7); /* sqform */
    v11 = (*qfn2(fn))(qenv(fn), v12, v11);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    goto v16;

v16:
    v12 = v11;
    v11 = stack[-2];
    qvalue(elt(env, 3)) = v11; /* subfg!* */
    v11 = v12;
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    { popv(4); return onevalue(v11); }

v15:
    v11 = (Lisp_Object)1; /* 0 */
    goto v16;
/* error exit handlers */
v14:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for all_defined_vertex */

static Lisp_Object CC_all_defined_vertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23, v10, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined_vertex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v17;
    v23 = v0;
/* end of prologue */
    v8 = v23;
    v10 = qvalue(elt(env, 1)); /* nil */
    v23 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* al1_defined_vertex */
        return (*qfnn(fn))(qenv(fn), 4, v8, v10, v23, v22);
    }
}



/* Code for getmatelem */

static Lisp_Object CC_getmatelem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v55, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getmatelem");
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

v57:
    v54 = stack[-1];
    v55 = Llength(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    v54 = (Lisp_Object)49; /* 3 */
    if (v55 == v54) goto v15;
    v55 = stack[-1];
    v54 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 12); /* typerr */
    v54 = (*qfn2(fn))(qenv(fn), v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    goto v15;

v15:
    v54 = stack[-1];
    v55 = qcar(v54);
    v54 = elt(env, 2); /* avalue */
    v54 = get(v55, v54);
    env = stack[-3];
    stack[-2] = v54;
    v54 = stack[-2];
    if (v54 == nil) goto v6;
    v54 = stack[-2];
    v55 = qcar(v54);
    v54 = elt(env, 4); /* matrix */
    v54 = (v55 == v54 ? lisp_true : nil);
    v54 = (v54 == nil ? lisp_true : nil);
    goto v5;

v5:
    if (v54 == nil) goto v59;
    v54 = stack[-1];
    v55 = qcar(v54);
    v54 = elt(env, 5); /* "matrix" */
    fn = elt(env, 12); /* typerr */
    v54 = (*qfn2(fn))(qenv(fn), v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    goto v60;

v60:
    v54 = stack[-1];
    v54 = qcdr(v54);
    v54 = qcar(v54);
    fn = elt(env, 13); /* reval_without_mod */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[0] = v54;
    v54 = stack[0];
    v54 = integerp(v54);
    if (v54 == nil) goto v61;
    v55 = stack[0];
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)lesseq2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    v54 = v54 ? lisp_true : nil;
    env = stack[-3];
    goto v62;

v62:
    if (v54 == nil) goto v63;
    v55 = stack[0];
    v54 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v54 = (*qfn2(fn))(qenv(fn), v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    goto v63;

v63:
    v54 = stack[-2];
    v55 = qcdr(v54);
    v54 = stack[0];
    fn = elt(env, 14); /* pnth */
    v54 = (*qfn2(fn))(qenv(fn), v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    v54 = qcar(v54);
    stack[-2] = v54;
    v54 = stack[-1];
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcar(v54);
    fn = elt(env, 13); /* reval_without_mod */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[0] = v54;
    v54 = stack[0];
    v54 = integerp(v54);
    if (v54 == nil) goto v64;
    v55 = stack[0];
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)lesseq2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    v54 = v54 ? lisp_true : nil;
    env = stack[-3];
    goto v65;

v65:
    if (v54 == nil) goto v66;
    v55 = stack[0];
    v54 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v54 = (*qfn2(fn))(qenv(fn), v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    goto v66;

v66:
    v55 = stack[-2];
    v54 = stack[0];
    fn = elt(env, 14); /* pnth */
    v54 = (*qfn2(fn))(qenv(fn), v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    v54 = qcar(v54);
    { popv(4); return onevalue(v54); }

v64:
    v54 = qvalue(elt(env, 3)); /* t */
    goto v65;

v61:
    v54 = qvalue(elt(env, 3)); /* t */
    goto v62;

v59:
    v54 = stack[-2];
    v54 = qcdr(v54);
    v55 = qcar(v54);
    stack[-2] = v55;
    v54 = elt(env, 6); /* mat */
    if (!consp(v55)) goto v67;
    v55 = qcar(v55);
    if (v55 == v54) goto v60;
    else goto v67;

v67:
    v54 = stack[-2];
    if (symbolp(v54)) goto v68;
    v56 = elt(env, 7); /* "Matrix" */
    v54 = stack[-1];
    v55 = qcar(v54);
    v54 = elt(env, 8); /* "not set" */
    v54 = list3(v56, v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    v55 = v54;
    v54 = v55;
    qvalue(elt(env, 9)) = v54; /* errmsg!* */
    v54 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v54 == nil)) goto v69;
    v54 = v55;
    fn = elt(env, 15); /* lprie */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    goto v69;

v69:
    v54 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    goto v60;

v68:
    v55 = stack[-2];
    v54 = stack[-1];
    v54 = qcdr(v54);
    v54 = cons(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[-1] = v54;
    goto v57;

v6:
    v54 = qvalue(elt(env, 3)); /* t */
    goto v5;
/* error exit handlers */
v58:
    popv(4);
    return nil;
}



/* Code for b!:extadd */

static Lisp_Object CC_bTextadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v90, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:extadd");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v17;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v92;

v92:
    v89 = stack[-2];
    if (v89 == nil) goto v18;
    v89 = stack[-1];
    if (v89 == nil) goto v7;
    v89 = stack[-2];
    v89 = qcar(v89);
    v90 = qcar(v89);
    v89 = stack[-1];
    v89 = qcar(v89);
    v89 = qcar(v89);
    if (equal(v90, v89)) goto v12;
    v89 = stack[-2];
    v89 = qcar(v89);
    v90 = qcar(v89);
    v89 = stack[-1];
    v89 = qcar(v89);
    v89 = qcar(v89);
    fn = elt(env, 1); /* b!:ordexp */
    v89 = (*qfn2(fn))(qenv(fn), v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    if (v89 == nil) goto v94;
    v89 = stack[-2];
    v90 = qcar(v89);
    v89 = stack[0];
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[0] = v89;
    v89 = stack[-2];
    v89 = qcdr(v89);
    stack[-2] = v89;
    goto v92;

v94:
    v89 = stack[-1];
    v90 = qcar(v89);
    v89 = stack[0];
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[0] = v89;
    v89 = stack[-1];
    v89 = qcdr(v89);
    stack[-1] = v89;
    goto v92;

v12:
    stack[-3] = stack[0];
    v89 = stack[-2];
    v89 = qcar(v89);
    v90 = qcdr(v89);
    v89 = stack[-1];
    v89 = qcar(v89);
    v89 = qcdr(v89);
    fn = elt(env, 2); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    v89 = stack[-2];
    v90 = qcdr(v89);
    v89 = stack[-1];
    v89 = qcdr(v89);
    v89 = CC_bTextadd(env, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    v90 = stack[0];
    v91 = v90;
    if (v91 == nil) goto v95;
    v91 = stack[-2];
    v91 = qcar(v91);
    v91 = qcar(v91);
    v89 = acons(v91, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    goto v95;

v95:
    {
        Lisp_Object v37 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v37, v89);
    }

v7:
    v90 = stack[0];
    v89 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v90, v89);
    }

v18:
    v90 = stack[0];
    v89 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v90, v89);
    }
/* error exit handlers */
v93:
    popv(5);
    return nil;
}



/* Code for negate!-term */

static Lisp_Object CC_negateKterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negate-term");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v19 = v0;
/* end of prologue */
    v18 = v19;
    stack[0] = qcar(v18);
    v18 = v19;
    v18 = qcdr(v18);
    fn = elt(env, 1); /* minus!-mod!-p */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v21;
    {
        Lisp_Object v22 = stack[0];
        popv(1);
        return cons(v22, v18);
    }
/* error exit handlers */
v21:
    popv(1);
    return nil;
}



/* Code for ofsf_smmkatl */

static Lisp_Object MS_CDECL CC_ofsf_smmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v3, Lisp_Object v26, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6, v99, v86, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smmkatl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v99 = v26;
    v86 = v3;
    v11 = v17;
    v5 = v0;
/* end of prologue */
    v6 = v5;
    v5 = elt(env, 1); /* and */
    if (v6 == v5) goto v22;
    v5 = v11;
    v6 = v86;
    {
        fn = elt(env, 2); /* ofsf_smmkatl!-or */
        return (*qfnn(fn))(qenv(fn), 3, v5, v6, v99);
    }

v22:
    v5 = v11;
    v6 = v86;
    {
        fn = elt(env, 3); /* ofsf_smmkatl!-and */
        return (*qfnn(fn))(qenv(fn), 3, v5, v6, v99);
    }
}



/* Code for qqe_simplat1 */

static Lisp_Object CC_qqe_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v51, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplat1");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v0;
/* end of prologue */
    v50 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-2];
    v101 = v50;
    v51 = v101;
    v50 = elt(env, 1); /* (qequal qneq) */
    v50 = Lmemq(nil, v51, v50);
    if (v50 == nil) goto v10;
    v51 = v101;
    v50 = elt(env, 2); /* qequal */
    if (v51 == v50) goto v60;
    v51 = stack[-1];
    v50 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* qqe_simplqneq */
        return (*qfn2(fn))(qenv(fn), v51, v50);
    }

v60:
    v51 = stack[-1];
    v50 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* qqe_simplqequal */
        return (*qfn2(fn))(qenv(fn), v51, v50);
    }

v10:
    v51 = stack[-1];
    v50 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* qqe_simplbtat */
        return (*qfn2(fn))(qenv(fn), v51, v50);
    }
/* error exit handlers */
v102:
    popv(3);
    return nil;
}



/* Code for ibalp_hassimple */

static Lisp_Object CC_ibalp_hassimple(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_hassimple");
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
    v6 = v0;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v6;
    goto v96;

v96:
    v6 = stack[0];
    if (v6 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v6 = stack[-1];
    if (!(v6 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v6 = stack[0];
    v6 = qcar(v6);
    v99 = qcar(v6);
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = qcdr(v6);
    v6 = qcar(v6);
    fn = elt(env, 2); /* ibalp_commonlenisone */
    v6 = (*qfn2(fn))(qenv(fn), v99, v6);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-2];
    if (v6 == nil) goto v8;
    v6 = stack[0];
    v6 = qcar(v6);
    stack[-1] = v6;
    goto v8;

v8:
    v6 = stack[0];
    v6 = qcdr(v6);
    stack[0] = v6;
    goto v96;
/* error exit handlers */
v12:
    popv(3);
    return nil;
}



/* Code for constsml */

static Lisp_Object CC_constsml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constsml");
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
    v107 = stack[0];
    if (!(is_number(v107))) goto v1;
    v107 = elt(env, 1); /* "<cn" */
    fn = elt(env, 13); /* printout */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v107 = stack[0];
    v107 = Lfloatp(nil, v107);
    env = stack[-1];
    if (v107 == nil) goto v19;
    v107 = elt(env, 2); /* " type=""real""> " */
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    goto v109;

v109:
    v107 = stack[0];
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v107 = elt(env, 5); /* " </cn>" */
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    goto v1;

v1:
    v107 = stack[0];
    if (!(symbolp(v107))) goto v53;
    v107 = stack[0];
    v68 = Lintern(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v107 = qvalue(elt(env, 6)); /* constants!* */
    v107 = Lmember(nil, v68, v107);
    if (v107 == nil) goto v110;
    v107 = elt(env, 7); /* "<cn type=""constant""> " */
    fn = elt(env, 13); /* printout */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v107 = stack[0];
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v107 = elt(env, 5); /* " </cn>" */
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    goto v53;

v53:
    v107 = nil;
    { popv(2); return onevalue(v107); }

v110:
    v107 = elt(env, 8); /* "<ci" */
    fn = elt(env, 13); /* printout */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v107 = stack[0];
    fn = elt(env, 14); /* listp */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    if (v107 == nil) goto v47;
    v107 = elt(env, 9); /* " type=""list""> " */
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    goto v85;

v85:
    v107 = stack[0];
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v107 = elt(env, 11); /* " </ci>" */
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    goto v53;

v47:
    v107 = stack[0];
    v107 = Lsimple_vectorp(nil, v107);
    env = stack[-1];
    if (v107 == nil) goto v75;
    v107 = elt(env, 10); /* " type=""vector""> " */
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    goto v85;

v75:
    v107 = elt(env, 4); /* "> " */
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    goto v85;

v19:
    v107 = stack[0];
    v107 = integerp(v107);
    if (v107 == nil) goto v4;
    v107 = elt(env, 3); /* " type=""integer""> " */
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    goto v109;

v4:
    v107 = elt(env, 4); /* "> " */
    v107 = Lprinc(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    goto v109;
/* error exit handlers */
v108:
    popv(2);
    return nil;
}



/* Code for simprecip */

static Lisp_Object CC_simprecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simprecip");
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
    v60 = v0;
/* end of prologue */
    v104 = qvalue(elt(env, 1)); /* !*mcd */
    if (v104 == nil) goto v22;
    v104 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v104 = (*qfn2(fn))(qenv(fn), v60, v104);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[0];
    fn = elt(env, 4); /* simp */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* invsq */
        return (*qfn1(fn))(qenv(fn), v104);
    }

v22:
    v104 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v60 = (*qfn2(fn))(qenv(fn), v60, v104);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[0];
    v104 = (Lisp_Object)-15; /* -1 */
    v104 = list2(v60, v104);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v104);
    }
/* error exit handlers */
v97:
    popv(1);
    return nil;
}



/* Code for list!-mgen */

static Lisp_Object CC_listKmgen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list-mgen");
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
    v5 = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = nil; /* i */
    v49 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v49; /* i */
    v49 = v5;
    stack[0] = v49;
    goto v96;

v96:
    v49 = stack[0];
    if (v49 == nil) goto v112;
    v49 = stack[0];
    v49 = qcar(v49);
    v5 = v49;
    v49 = v5;
    if (!consp(v49)) goto v16;
    v49 = qvalue(elt(env, 2)); /* nil */
    goto v4;

v4:
    if (v49 == nil) goto v9;
    v49 = qvalue(elt(env, 1)); /* i */
    v49 = add1(v49);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    qvalue(elt(env, 1)) = v49; /* i */
    goto v9;

v9:
    v49 = stack[0];
    v49 = qcdr(v49);
    stack[0] = v49;
    goto v96;

v16:
    v49 = v5;
    fn = elt(env, 3); /* mgenp */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    goto v4;

v112:
    v49 = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    { popv(3); return onevalue(v49); }
/* error exit handlers */
v86:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    popv(3);
    return nil;
}



/* Code for vbcgcd */

static Lisp_Object CC_vbcgcd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vbcgcd");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v0;
/* end of prologue */
    v122 = stack[-1];
    v121 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v121 = (*qfn2(fn))(qenv(fn), v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    if (v121 == nil) goto v109;
    v122 = stack[0];
    v121 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v121 = (*qfn2(fn))(qenv(fn), v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    v121 = (v121 == nil ? lisp_true : nil);
    goto v124;

v124:
    if (v121 == nil) goto v86;
    v121 = elt(env, 2); /* (1 . 1) */
    { popv(3); return onevalue(v121); }

v86:
    v121 = stack[-1];
    v122 = qcdr(v121);
    v121 = (Lisp_Object)17; /* 1 */
    if (v122 == v121) goto v83;
    v121 = qvalue(elt(env, 3)); /* nil */
    goto v5;

v5:
    if (v121 == nil) goto v125;
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = integerp(v121);
    if (v121 == nil) goto v126;
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = integerp(v121);
    if (v121 == nil) goto v126;
    v121 = stack[-1];
    v122 = qcar(v121);
    v121 = stack[0];
    v121 = qcar(v121);
    v122 = Lgcd(nil, v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    v121 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v122, v121);

v126:
    v121 = stack[-1];
    v122 = qcar(v121);
    v121 = stack[0];
    v121 = qcar(v121);
    fn = elt(env, 5); /* gcdf!* */
    v122 = (*qfn2(fn))(qenv(fn), v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    v121 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v122, v121);

v125:
    v122 = (Lisp_Object)17; /* 1 */
    v121 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v122, v121);

v83:
    v121 = stack[0];
    v122 = qcdr(v121);
    v121 = (Lisp_Object)17; /* 1 */
    v121 = (v122 == v121 ? lisp_true : nil);
    goto v5;

v109:
    v121 = qvalue(elt(env, 1)); /* t */
    goto v124;
/* error exit handlers */
v123:
    popv(3);
    return nil;
}



/* Code for groebcplistsortin */

static Lisp_Object CC_groebcplistsortin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistsortin");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    v111 = v0;
/* end of prologue */
    v9 = stack[0];
    if (v9 == nil) goto v1;
    v9 = stack[0];
    fn = elt(env, 1); /* groebcplistsortin1 */
    v9 = (*qfn2(fn))(qenv(fn), v111, v9);
    nil = C_nil;
    if (exception_pending()) goto v7;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v1:
    v9 = v111;
    popv(1);
    return ncons(v9);
/* error exit handlers */
v7:
    popv(1);
    return nil;
}



/* Code for termordp!! */

static Lisp_Object CC_termordpB(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v127, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termordp!");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    v87 = v0;
/* end of prologue */
    v127 = v87;
    v15 = stack[0];
    if (equal(v127, v15)) goto v7;
    v15 = v87;
    fn = elt(env, 2); /* guesspftype */
    stack[-1] = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    v15 = stack[0];
    fn = elt(env, 2); /* guesspftype */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    {
        Lisp_Object v52 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* termordp */
        return (*qfn2(fn))(qenv(fn), v52, v15);
    }

v7:
    v15 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v15); }
/* error exit handlers */
v120:
    popv(3);
    return nil;
}



/* Code for putd */

static Lisp_Object MS_CDECL CC_putd(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v139, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "putd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for putd");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v17;
    stack[-2] = v0;
/* end of prologue */
    v139 = stack[0];
    v138 = elt(env, 1); /* funarg */
    if (!consp(v139)) goto v1;
    v139 = qcar(v139);
    if (!(v139 == v138)) goto v1;
    v139 = elt(env, 2); /* lambda */
    v138 = stack[0];
    v138 = qcdr(v138);
    v138 = qcdr(v138);
    v138 = cons(v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[0] = v138;
    goto v1;

v1:
    v138 = stack[-2];
    if (!symbolp(v138)) v138 = nil;
    else { v138 = qfastgets(v138);
           if (v138 != nil) { v138 = elt(v138, 1); /* lose */
#ifdef RECORD_GET
             if (v138 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v138 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v138 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v138 == SPID_NOPROP) v138 = nil; else v138 = lisp_true; }}
#endif
    if (v138 == nil) goto v5;
    v138 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v138 = elt(env, 3); /* "+++ " */
    v138 = Lprinc(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v138 = stack[-2];
    v138 = Lprin(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v138 = elt(env, 4); /* " not defined (LOSE flag)" */
    v138 = Lprintc(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v138 = qvalue(elt(env, 5)); /* nil */
    { popv(4); return onevalue(v138); }

v5:
    v138 = qvalue(elt(env, 6)); /* !*redefmsg */
    if (v138 == nil) goto v85;
    v138 = stack[-2];
    fn = elt(env, 15); /* getd */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    if (v138 == nil) goto v85;
    v138 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v138 = elt(env, 3); /* "+++ " */
    v138 = Lprinc(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v138 = stack[-2];
    v138 = Lprin(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v138 = elt(env, 7); /* " redefined" */
    v138 = Lprintc(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    goto v85;

v85:
    v139 = stack[-1];
    v138 = elt(env, 8); /* expr */
    if (v139 == v138) goto v81;
    v139 = stack[-1];
    v138 = elt(env, 9); /* subr */
    if (v139 == v138) goto v108;
    v139 = stack[-1];
    v138 = elt(env, 10); /* macro */
    if (v139 == v138) goto v142;
    v138 = qvalue(elt(env, 5)); /* nil */
    goto v143;

v143:
    if (v138 == nil) goto v144;
    v140 = elt(env, 11); /* dm */
    v139 = stack[-2];
    v138 = stack[0];
    v138 = qcdr(v138);
    v138 = list2star(v140, v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v144:
    v139 = stack[-1];
    v138 = elt(env, 12); /* fexpr */
    if (v139 == v138) goto v145;
    v138 = qvalue(elt(env, 5)); /* nil */
    goto v89;

v89:
    if (v138 == nil) goto v29;
    v140 = elt(env, 13); /* df */
    v139 = stack[-2];
    v138 = stack[0];
    v138 = qcdr(v138);
    v138 = list2star(v140, v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v29:
    v139 = elt(env, 14); /* "Bad type ~S in putd" */
    v138 = stack[-1];
    fn = elt(env, 17); /* error */
    v138 = (*qfn2(fn))(qenv(fn), v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v145:
    v139 = stack[0];
    v138 = elt(env, 2); /* lambda */
    v138 = Leqcar(nil, v139, v138);
    env = stack[-3];
    goto v89;

v142:
    v139 = stack[0];
    v138 = elt(env, 2); /* lambda */
    v138 = Leqcar(nil, v139, v138);
    env = stack[-3];
    goto v143;

v108:
    v139 = stack[-2];
    v138 = stack[0];
    v138 = Lsymbol_set_definition(nil, v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v81:
    v139 = stack[-2];
    v138 = stack[0];
    v138 = Lsymbol_set_definition(nil, v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v141:
    popv(4);
    return nil;
}



/* Code for setel */

static Lisp_Object CC_setel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v137, v59, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setel");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v17;
    stack[-2] = v0;
/* end of prologue */
    v136 = stack[-2];
    v137 = qcar(v136);
    v136 = elt(env, 1); /* dimension */
    v136 = get(v137, v136);
    env = stack[-4];
    stack[-3] = v136;
    v136 = stack[-3];
    stack[0] = Llength(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v136 = stack[-2];
    v136 = qcdr(v136);
    v136 = Llength(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    if (equal(stack[0], v136)) goto v50;
    v136 = elt(env, 2); /* "Incorrect array reference" */
    v137 = v136;
    v136 = v137;
    qvalue(elt(env, 3)) = v136; /* errmsg!* */
    v136 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v136 == nil)) goto v52;
    v136 = v137;
    fn = elt(env, 6); /* lprie */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    goto v52;

v52:
    v136 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v136 = nil;
    { popv(5); return onevalue(v136); }

v50:
    v136 = stack[-2];
    v137 = qcar(v136);
    v136 = elt(env, 5); /* avalue */
    v136 = get(v137, v136);
    env = stack[-4];
    v136 = qcdr(v136);
    v81 = qcar(v136);
    v136 = stack[-2];
    v59 = qcdr(v136);
    v137 = stack[-1];
    v136 = stack[-3];
    {
        popv(5);
        fn = elt(env, 7); /* setel1 */
        return (*qfnn(fn))(qenv(fn), 4, v81, v59, v137, v136);
    }
/* error exit handlers */
v75:
    popv(5);
    return nil;
}



/* Code for mv2sf1 */

static Lisp_Object MS_CDECL CC_mv2sf1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v147, v110, v102, v84;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mv2sf1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv2sf1");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v110 = v3;
    v84 = v17;
    v102 = v0;
/* end of prologue */

v92:
    v101 = v102;
    if (v101 == nil) { popv(3); return onevalue(v84); }
    v101 = v102;
    v147 = qcar(v101);
    v101 = (Lisp_Object)1; /* 0 */
    if (v147 == v101) goto v18;
    v101 = v110;
    stack[-1] = qcar(v101);
    v101 = v102;
    stack[0] = qcar(v101);
    v101 = v102;
    v101 = qcdr(v101);
    v147 = v84;
    v110 = qcdr(v110);
    v101 = CC_mv2sf1(env, 3, v101, v147, v110);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v101 = acons(stack[-1], stack[0], v101);
    nil = C_nil;
    if (exception_pending()) goto v85;
    popv(3);
    return ncons(v101);

v18:
    v101 = v102;
    v101 = qcdr(v101);
    v102 = v101;
    v101 = v110;
    v101 = qcdr(v101);
    v110 = v101;
    goto v92;
/* error exit handlers */
v85:
    popv(3);
    return nil;
}



/* Code for make!-term */

static Lisp_Object MS_CDECL CC_makeKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v162, v163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "make-term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-term");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v3;
    stack[-4] = v17;
    stack[-5] = v0;
/* end of prologue */
    v161 = (Lisp_Object)1; /* 0 */
    stack[-2] = v161;
    v161 = (Lisp_Object)1; /* 0 */
    stack[0] = v161;
    goto v111;

v111:
    v162 = stack[-4];
    v161 = stack[0];
    v162 = *(Lisp_Object *)((char *)v162 + (CELL-TAG_VECTOR) + ((int32_t)v161/(16/CELL)));
    v161 = (Lisp_Object)1; /* 0 */
    v161 = (Lisp_Object)lessp2(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    v161 = v161 ? lisp_true : nil;
    env = stack[-7];
    if (v161 == nil) goto v5;
    v161 = (Lisp_Object)-15; /* -1 */
    stack[-2] = v161;
    goto v18;

v18:
    v161 = (Lisp_Object)49; /* 3 */
    v161 = Lmkvect(nil, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    stack[-6] = v161;
    v162 = stack[-2];
    v161 = (Lisp_Object)17; /* 1 */
    if (v162 == v161) goto v165;
    v162 = stack[-5];
    v161 = elt(env, 4); /* cos */
    v161 = (v162 == v161 ? lisp_true : nil);
    goto v166;

v166:
    if (v161 == nil) goto v167;
    v163 = stack[-6];
    v162 = (Lisp_Object)1; /* 0 */
    v161 = stack[-3];
    *(Lisp_Object *)((char *)v163 + (CELL-TAG_VECTOR) + ((int32_t)v162/(16/CELL))) = v161;
    goto v168;

v168:
    v163 = stack[-6];
    v162 = (Lisp_Object)17; /* 1 */
    v161 = stack[-5];
    *(Lisp_Object *)((char *)v163 + (CELL-TAG_VECTOR) + ((int32_t)v162/(16/CELL))) = v161;
    v162 = stack[-2];
    v161 = (Lisp_Object)-15; /* -1 */
    if (!(v162 == v161)) goto v28;
    v161 = (Lisp_Object)113; /* 7 */
    v161 = Lmkvect(nil, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    stack[-2] = v161;
    v161 = (Lisp_Object)1; /* 0 */
    stack[-3] = v161;
    goto v169;

v169:
    v162 = (Lisp_Object)113; /* 7 */
    v161 = stack[-3];
    v161 = difference2(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    v161 = Lminusp(nil, v161);
    env = stack[-7];
    if (v161 == nil) goto v170;
    v161 = stack[-2];
    stack[-4] = v161;
    goto v28;

v28:
    v163 = stack[-6];
    v162 = (Lisp_Object)33; /* 2 */
    v161 = stack[-4];
    *(Lisp_Object *)((char *)v163 + (CELL-TAG_VECTOR) + ((int32_t)v162/(16/CELL))) = v161;
    v162 = stack[-6];
    v161 = (Lisp_Object)49; /* 3 */
    v163 = qvalue(elt(env, 2)); /* nil */
    *(Lisp_Object *)((char *)v162 + (CELL-TAG_VECTOR) + ((int32_t)v161/(16/CELL))) = v163;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v170:
    stack[-1] = stack[-2];
    stack[0] = stack[-3];
    v162 = stack[-4];
    v161 = stack[-3];
    v161 = *(Lisp_Object *)((char *)v162 + (CELL-TAG_VECTOR) + ((int32_t)v161/(16/CELL)));
    v161 = negate(v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v161;
    v161 = stack[-3];
    v161 = add1(v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    stack[-3] = v161;
    goto v169;

v167:
    stack[-1] = stack[-6];
    stack[0] = (Lisp_Object)1; /* 0 */
    v162 = elt(env, 5); /* (-1 . 1) */
    v161 = stack[-3];
    fn = elt(env, 6); /* multsq */
    v161 = (*qfn2(fn))(qenv(fn), v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v161;
    goto v168;

v165:
    v161 = qvalue(elt(env, 3)); /* t */
    goto v166;

v5:
    v162 = stack[-4];
    v161 = stack[0];
    v162 = *(Lisp_Object *)((char *)v162 + (CELL-TAG_VECTOR) + ((int32_t)v161/(16/CELL)));
    v161 = (Lisp_Object)1; /* 0 */
    v161 = (Lisp_Object)greaterp2(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    v161 = v161 ? lisp_true : nil;
    env = stack[-7];
    if (v161 == nil) goto v100;
    v161 = (Lisp_Object)17; /* 1 */
    stack[-2] = v161;
    goto v18;

v100:
    v162 = stack[0];
    v161 = (Lisp_Object)113; /* 7 */
    if (v162 == v161) goto v171;
    v161 = stack[0];
    v161 = (Lisp_Object)((int32_t)(v161) + 0x10);
    stack[0] = v161;
    goto v111;

v171:
    v162 = stack[-5];
    v161 = elt(env, 1); /* sin */
    if (!(v162 == v161)) goto v18;
    v161 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v161); }
/* error exit handlers */
v164:
    popv(8);
    return nil;
}



/* Code for bc_inv */

static Lisp_Object CC_bc_inv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v51, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_inv");
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
    v101 = v0;
/* end of prologue */
    v51 = v101;
    v50 = (Lisp_Object)17; /* 1 */
    if (v51 == v50) goto v112;
    v51 = v101;
    v50 = (Lisp_Object)-15; /* -1 */
    v50 = (v51 == v50 ? lisp_true : nil);
    goto v172;

v172:
    if (!(v50 == nil)) { popv(1); return onevalue(v101); }
    v50 = (Lisp_Object)17; /* 1 */
    v51 = v101;
    fn = elt(env, 3); /* qremf */
    v50 = (*qfn2(fn))(qenv(fn), v50, v51);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[0];
    v51 = v50;
    v50 = v51;
    v50 = qcdr(v50);
    if (v50 == nil) goto v106;
    v50 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v50); }

v106:
    v50 = v51;
    v50 = qcar(v50);
    { popv(1); return onevalue(v50); }

v112:
    v50 = qvalue(elt(env, 1)); /* t */
    goto v172;
/* error exit handlers */
v147:
    popv(1);
    return nil;
}



/* Code for class */

static Lisp_Object CC_class(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for class");
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
    v60 = stack[0];
    fn = elt(env, 3); /* ord */
    v97 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-1];
    v60 = (Lisp_Object)1; /* 0 */
    if (v97 == v60) goto v2;
    v97 = qvalue(elt(env, 1)); /* ordering */
    v60 = elt(env, 2); /* lex */
    if (v97 == v60) goto v9;
    v60 = stack[0];
    v60 = qcdr(v60);
    goto v8;

v8:
    v60 = Lreverse(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-1];
    fn = elt(env, 4); /* leftzeros */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v49;
    v60 = (Lisp_Object)((int32_t)(v60) + 0x10);
    { popv(2); return onevalue(v60); }

v9:
    v60 = stack[0];
    goto v8;

v2:
    v60 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v60); }
/* error exit handlers */
v49:
    popv(2);
    return nil;
}



/* Code for pv_times2 */

static Lisp_Object MS_CDECL CC_pv_times2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pv_times2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_times2");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    v60 = v17;
    stack[-1] = v0;
/* end of prologue */

v172:
    v97 = v60;
    if (v97 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v97 = v60;
    v97 = qcdr(v97);
    stack[-2] = v97;
    v97 = stack[-1];
    v60 = qcar(v60);
    fn = elt(env, 1); /* pv_times3 */
    v60 = (*qfn2(fn))(qenv(fn), v97, v60);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v97 = ncons(v60);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v60 = stack[0];
    fn = elt(env, 2); /* pv_add */
    v60 = (*qfn2(fn))(qenv(fn), v97, v60);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    stack[0] = v60;
    v60 = stack[-2];
    goto v172;
/* error exit handlers */
v6:
    popv(4);
    return nil;
}



/* Code for b!:ordexn */

static Lisp_Object CC_bTordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v78;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:ordexn");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v17;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    stack[-3] = nil;
    goto v172;

v172:
    v44 = stack[-1];
    if (v44 == nil) goto v111;
    v78 = stack[-2];
    v44 = stack[-1];
    v44 = qcar(v44);
    if (equal(v78, v44)) goto v87;
    v44 = stack[-2];
    if (v44 == nil) goto v175;
    v78 = stack[-2];
    v44 = stack[-1];
    v44 = qcar(v44);
    v44 = (Lisp_Object)greaterp2(v78, v44);
    nil = C_nil;
    if (exception_pending()) goto v176;
    v44 = v44 ? lisp_true : nil;
    env = stack[-4];
    if (v44 == nil) goto v175;
    v78 = stack[-2];
    v44 = stack[-3];
    v44 = cons(v78, v44);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    v78 = Lreverse(nil, v44);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    v44 = stack[-1];
    v44 = Lappend(nil, v78, v44);
    nil = C_nil;
    if (exception_pending()) goto v176;
    {
        Lisp_Object v177 = stack[0];
        popv(5);
        return cons(v177, v44);
    }

v175:
    v44 = stack[-1];
    v78 = qcar(v44);
    v44 = stack[-3];
    v44 = cons(v78, v44);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    stack[-3] = v44;
    v44 = stack[-1];
    v44 = qcdr(v44);
    stack[-1] = v44;
    v44 = stack[0];
    v44 = (v44 == nil ? lisp_true : nil);
    stack[0] = v44;
    goto v172;

v87:
    v44 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v44); }

v111:
    v78 = stack[-2];
    v44 = stack[-3];
    v44 = cons(v78, v44);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    v44 = Lreverse(nil, v44);
    nil = C_nil;
    if (exception_pending()) goto v176;
    {
        Lisp_Object v116 = stack[0];
        popv(5);
        return cons(v116, v44);
    }
/* error exit handlers */
v176:
    popv(5);
    return nil;
}



/* Code for split_ext */

static Lisp_Object CC_split_ext(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v125, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_ext");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v125 = v17;
    v167 = v0;
/* end of prologue */
    v135 = v167;
    v135 = qcdr(v135);
    stack[-7] = v135;
    v135 = v167;
    v135 = qcar(v135);
    fn = elt(env, 3); /* split_form */
    v135 = (*qfn2(fn))(qenv(fn), v135, v125);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    stack[0] = v135;
    v135 = elt(env, 1); /* ext */
    stack[-6] = ncons(v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    v135 = stack[0];
    v125 = qcar(v135);
    v135 = stack[-7];
    v135 = cons(v125, v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    stack[-5] = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    v135 = stack[0];
    v135 = qcdr(v135);
    stack[-4] = v135;
    v135 = stack[-4];
    if (v135 == nil) goto v95;
    v135 = stack[-4];
    v135 = qcar(v135);
    v125 = v135;
    v135 = v125;
    stack[0] = qcar(v135);
    v135 = v125;
    v125 = qcdr(v135);
    v135 = stack[-7];
    v135 = cons(v125, v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    v135 = cons(stack[0], v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    v135 = ncons(v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    stack[-2] = v135;
    stack[-3] = v135;
    goto v86;

v86:
    v135 = stack[-4];
    v135 = qcdr(v135);
    stack[-4] = v135;
    v135 = stack[-4];
    if (v135 == nil) goto v179;
    stack[-1] = stack[-2];
    v135 = stack[-4];
    v135 = qcar(v135);
    v125 = v135;
    v135 = v125;
    stack[0] = qcar(v135);
    v135 = v125;
    v125 = qcdr(v135);
    v135 = stack[-7];
    v135 = cons(v125, v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    v135 = cons(stack[0], v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    v135 = ncons(v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    v135 = Lrplacd(nil, stack[-1], v135);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-8];
    v135 = stack[-2];
    v135 = qcdr(v135);
    stack[-2] = v135;
    goto v86;

v179:
    v135 = stack[-3];
    goto v7;

v7:
    {
        Lisp_Object v180 = stack[-6];
        Lisp_Object v123 = stack[-5];
        popv(9);
        return acons(v180, v123, v135);
    }

v95:
    v135 = qvalue(elt(env, 2)); /* nil */
    goto v7;
/* error exit handlers */
v94:
    popv(9);
    return nil;
}



/* Code for rl_prepfof */

static Lisp_Object CC_rl_prepfof(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_prepfof");
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
    v1 = v0;
/* end of prologue */
    fn = elt(env, 1); /* rl_csimpl */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* rl_prepfof1 */
        return (*qfn1(fn))(qenv(fn), v1);
    }
/* error exit handlers */
v92:
    popv(1);
    return nil;
}



/* Code for wureducedpolysp */

static Lisp_Object CC_wureducedpolysp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wureducedpolysp");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v0;
/* end of prologue */

v182:
    v60 = stack[0];
    if (v60 == nil) goto v1;
    v97 = stack[-1];
    v60 = stack[0];
    v60 = qcar(v60);
    fn = elt(env, 3); /* wureducedp */
    v60 = (*qfn2(fn))(qenv(fn), v97, v60);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    if (v60 == nil) goto v18;
    v97 = stack[-1];
    v60 = stack[0];
    v60 = qcdr(v60);
    stack[-1] = v97;
    stack[0] = v60;
    goto v182;

v18:
    v60 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v60); }

v1:
    v60 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v60); }
/* error exit handlers */
v5:
    popv(3);
    return nil;
}



/* Code for get_rep_matrix_in */

static Lisp_Object CC_get_rep_matrix_in(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_rep_matrix_in");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v45 = v17;
    stack[-2] = v0;
/* end of prologue */
    stack[-1] = nil;
    v46 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v46;
    v46 = v45;
    v46 = qcdr(v46);
    stack[0] = v46;
    goto v18;

v18:
    v46 = stack[-3];
    if (v46 == nil) goto v7;
    v46 = qvalue(elt(env, 1)); /* nil */
    goto v10;

v10:
    if (v46 == nil) goto v109;
    v46 = stack[0];
    v46 = qcar(v46);
    v45 = qcar(v46);
    v46 = stack[-2];
    if (!(equal(v45, v46))) goto v97;
    v46 = stack[0];
    v46 = qcar(v46);
    v46 = qcdr(v46);
    v46 = qcar(v46);
    stack[-1] = v46;
    v46 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v46;
    goto v97;

v97:
    v46 = stack[0];
    v46 = qcdr(v46);
    stack[0] = v46;
    goto v18;

v109:
    v46 = stack[-3];
    if (!(v46 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v46 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v46 == nil)) goto v59;
    v46 = elt(env, 4); /* "error in get representation matrix" */
    fn = elt(env, 5); /* lprie */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    goto v59;

v59:
    v46 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v166;
    v46 = nil;
    { popv(5); return onevalue(v46); }

v7:
    v46 = stack[0];
    v45 = Llength(nil, v46);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    v46 = (Lisp_Object)1; /* 0 */
    v46 = (Lisp_Object)greaterp2(v45, v46);
    nil = C_nil;
    if (exception_pending()) goto v166;
    v46 = v46 ? lisp_true : nil;
    env = stack[-4];
    goto v10;
/* error exit handlers */
v166:
    popv(5);
    return nil;
}



/* Code for qqe_number!-of!-adds!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKaddsKinKqterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_number-of-adds-in-qterm");
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

v2:
    v88 = stack[0];
    if (!consp(v88)) goto v172;
    v88 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v103 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v88 = elt(env, 1); /* (ladd radd) */
    v88 = Lmemq(nil, v103, v88);
    if (v88 == nil) goto v16;
    v88 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v88 = CC_qqe_numberKofKaddsKinKqterm(env, v88);
    nil = C_nil;
    if (exception_pending()) goto v52;
    popv(2);
    return add1(v88);

v16:
    v88 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    stack[0] = v88;
    goto v2;

v172:
    v88 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v88); }
/* error exit handlers */
v52:
    popv(2);
    return nil;
}



/* Code for cgb_buch!-ev_divides!? */

static Lisp_Object CC_cgb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgb_buch-ev_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v109 = v17;
    v124 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v109, v124);
    }
}



/* Code for stats_getargs */

static Lisp_Object MS_CDECL CC_stats_getargs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "stats_getargs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stats_getargs");
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
    v10 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-1];
    v8 = v10;
    v10 = v8;
    if (v10 == nil) goto v172;
    stack[0] = v8;
    v10 = CC_stats_getargs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    {
        Lisp_Object v181 = stack[0];
        popv(2);
        return cons(v181, v10);
    }

v172:
    v10 = nil;
    { popv(2); return onevalue(v10); }
/* error exit handlers */
v111:
    popv(2);
    return nil;
}



/* Code for matsm!*1 */

static Lisp_Object CC_matsmH1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm*1");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v153 = v0;
/* end of prologue */
    stack[-8] = elt(env, 1); /* mat */
    stack[-7] = v153;
    v153 = stack[-7];
    if (v153 == nil) goto v8;
    v153 = stack[-7];
    v153 = qcar(v153);
    stack[-3] = v153;
    v153 = stack[-3];
    if (v153 == nil) goto v97;
    v153 = stack[-3];
    v153 = qcar(v153);
    fn = elt(env, 5); /* subs2!* */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    v185 = v153;
    v153 = qvalue(elt(env, 3)); /* !*nosq */
    if (v153 == nil) goto v14;
    v153 = v185;
    fn = elt(env, 6); /* prepsqxx */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    goto v106;

v106:
    v153 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    stack[-1] = v153;
    stack[-2] = v153;
    goto v52;

v52:
    v153 = stack[-3];
    v153 = qcdr(v153);
    stack[-3] = v153;
    v153 = stack[-3];
    if (v153 == nil) goto v171;
    stack[0] = stack[-1];
    v153 = stack[-3];
    v153 = qcar(v153);
    fn = elt(env, 5); /* subs2!* */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    v185 = v153;
    v153 = qvalue(elt(env, 3)); /* !*nosq */
    if (v153 == nil) goto v165;
    v153 = v185;
    fn = elt(env, 6); /* prepsqxx */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    goto v166;

v166:
    v153 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    v153 = Lrplacd(nil, stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    v153 = stack[-1];
    v153 = qcdr(v153);
    stack[-1] = v153;
    goto v52;

v165:
    v153 = v185;
    fn = elt(env, 7); /* mk!*sq */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    goto v166;

v171:
    v153 = stack[-2];
    goto v120;

v120:
    v153 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    stack[-5] = v153;
    stack[-6] = v153;
    goto v21;

v21:
    v153 = stack[-7];
    v153 = qcdr(v153);
    stack[-7] = v153;
    v153 = stack[-7];
    if (v153 == nil) goto v176;
    stack[-4] = stack[-5];
    v153 = stack[-7];
    v153 = qcar(v153);
    stack[-3] = v153;
    v153 = stack[-3];
    if (v153 == nil) goto v121;
    v153 = stack[-3];
    v153 = qcar(v153);
    fn = elt(env, 5); /* subs2!* */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    v185 = v153;
    v153 = qvalue(elt(env, 3)); /* !*nosq */
    if (v153 == nil) goto v90;
    v153 = v185;
    fn = elt(env, 6); /* prepsqxx */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    goto v89;

v89:
    v153 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    stack[-1] = v153;
    stack[-2] = v153;
    goto v73;

v73:
    v153 = stack[-3];
    v153 = qcdr(v153);
    stack[-3] = v153;
    v153 = stack[-3];
    if (v153 == nil) goto v186;
    stack[0] = stack[-1];
    v153 = stack[-3];
    v153 = qcar(v153);
    fn = elt(env, 5); /* subs2!* */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    v185 = v153;
    v153 = qvalue(elt(env, 3)); /* !*nosq */
    if (v153 == nil) goto v187;
    v153 = v185;
    fn = elt(env, 6); /* prepsqxx */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    goto v131;

v131:
    v153 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    v153 = Lrplacd(nil, stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    v153 = stack[-1];
    v153 = qcdr(v153);
    stack[-1] = v153;
    goto v73;

v187:
    v153 = v185;
    fn = elt(env, 7); /* mk!*sq */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    goto v131;

v186:
    v153 = stack[-2];
    goto v72;

v72:
    v153 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    v153 = Lrplacd(nil, stack[-4], v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    v153 = stack[-5];
    v153 = qcdr(v153);
    stack[-5] = v153;
    goto v21;

v90:
    v153 = v185;
    fn = elt(env, 7); /* mk!*sq */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    goto v89;

v121:
    v153 = qvalue(elt(env, 2)); /* nil */
    goto v72;

v176:
    v153 = stack[-6];
    goto v112;

v112:
    v153 = cons(stack[-8], v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    v185 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 4)) = v185; /* !*sub2 */
    { popv(10); return onevalue(v153); }

v14:
    v153 = v185;
    fn = elt(env, 7); /* mk!*sq */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-9];
    goto v106;

v97:
    v153 = qvalue(elt(env, 2)); /* nil */
    goto v120;

v8:
    v153 = qvalue(elt(env, 2)); /* nil */
    goto v112;
/* error exit handlers */
v27:
    popv(10);
    return nil;
}



/* Code for chk */

static Lisp_Object CC_chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v166, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chk");
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

v182:
    v118 = stack[0];
    if (v118 == nil) goto v2;
    v166 = stack[0];
    v118 = qvalue(elt(env, 1)); /* t */
    if (v166 == v118) goto v109;
    v118 = stack[0];
    v118 = qcar(v118);
    fn = elt(env, 3); /* bsubs */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-2];
    stack[-1] = v118;
    v118 = stack[-1];
    fn = elt(env, 4); /* freexp */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-2];
    if (v118 == nil) goto v136;
    v118 = stack[0];
    v118 = qcdr(v118);
    v118 = CC_chk(env, v118);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-2];
    v166 = v118;
    v118 = v166;
    if (v118 == nil) goto v5;
    v118 = v166;
    v165 = qvalue(elt(env, 1)); /* t */
    if (v118 == v165) goto v11;
    v118 = stack[-1];
    popv(3);
    return cons(v118, v166);

v11:
    v118 = stack[-1];
    popv(3);
    return ncons(v118);

v5:
    v118 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v118); }

v136:
    v118 = stack[-1];
    fn = elt(env, 5); /* reval */
    v166 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-2];
    v118 = qvalue(elt(env, 1)); /* t */
    if (v166 == v118) goto v48;
    v118 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v118); }

v48:
    v118 = stack[0];
    v118 = qcdr(v118);
    stack[0] = v118;
    goto v182;

v109:
    v118 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v118); }

v2:
    v118 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v118); }
/* error exit handlers */
v173:
    popv(3);
    return nil;
}



/* Code for add_minus */

static Lisp_Object CC_add_minus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v141;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_minus");
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
    v185 = stack[-1];
    if (!consp(v185)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v185 = stack[-1];
    v141 = qcar(v185);
    v185 = elt(env, 1); /* !:rd!: */
    if (v141 == v185) goto v4;
    v185 = qvalue(elt(env, 2)); /* nil */
    goto v18;

v18:
    if (!(v185 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v185 = stack[-1];
    v141 = qcar(v185);
    v185 = elt(env, 1); /* !:rd!: */
    if (v141 == v185) goto v100;
    v185 = qvalue(elt(env, 2)); /* nil */
    goto v5;

v5:
    if (v185 == nil) goto v173;
    stack[-2] = elt(env, 3); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v185 = stack[-1];
    v185 = qcdr(v185);
    v185 = Labsval(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v185 = cons(stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v155;
    {
        Lisp_Object v156 = stack[-2];
        popv(4);
        return list2(v156, v185);
    }

v173:
    v185 = stack[-1];
    v141 = qcar(v185);
    v185 = elt(env, 3); /* minus */
    if (v141 == v185) goto v107;
    v185 = qvalue(elt(env, 2)); /* nil */
    goto v165;

v165:
    if (!(v185 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v185 = stack[-1];
    v141 = qcar(v185);
    v185 = elt(env, 3); /* minus */
    if (v141 == v185) goto v72;
    v185 = qvalue(elt(env, 2)); /* nil */
    goto v40;

v40:
    if (v185 == nil) goto v193;
    stack[0] = elt(env, 1); /* !:rd!: */
    v185 = stack[-1];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v185 = qcdr(v185);
    v185 = Labsval(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v155;
    {
        Lisp_Object v194 = stack[0];
        popv(4);
        return cons(v194, v185);
    }

v193:
    v185 = stack[-1];
    v141 = qcar(v185);
    v185 = elt(env, 3); /* minus */
    if (v141 == v185) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v185 = stack[-1];
    v141 = qcdr(v185);
    v185 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)lessp2(v141, v185);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v185 = v185 ? lisp_true : nil;
    env = stack[-3];
    if (v185 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = elt(env, 3); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v185 = stack[-1];
    v185 = qcdr(v185);
    v185 = Labsval(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v185 = cons(stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v155;
    {
        Lisp_Object v195 = stack[-2];
        popv(4);
        return list2(v195, v185);
    }

v72:
    v185 = stack[-1];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v141 = qcdr(v185);
    v185 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)lessp2(v141, v185);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v185 = v185 ? lisp_true : nil;
    env = stack[-3];
    goto v40;

v107:
    v185 = stack[-1];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v185 = (is_number(v185) ? lisp_true : nil);
    goto v165;

v100:
    v185 = stack[-1];
    v141 = qcdr(v185);
    v185 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)lessp2(v141, v185);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v185 = v185 ? lisp_true : nil;
    env = stack[-3];
    goto v5;

v4:
    v185 = stack[-1];
    v141 = qcdr(v185);
    v185 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)geq2(v141, v185);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v185 = v185 ? lisp_true : nil;
    env = stack[-3];
    goto v18;
/* error exit handlers */
v155:
    popv(4);
    return nil;
}



/* Code for fctlength */

static Lisp_Object CC_fctlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctlength");
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
    v1 = v0;
/* end of prologue */
    fn = elt(env, 1); /* fctargs */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    errexit();
        return Llength(nil, v1);
}



/* Code for trwrite */

static Lisp_Object CC_trwrite(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v95;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for trwrite");
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
    v105 = stack[0];
    v95 = qcar(v105);
    v105 = elt(env, 1); /* tracing */
    v105 = Lflagp(nil, v95, v105);
    env = stack[-1];
    if (v105 == nil) goto v172;
    v105 = elt(env, 3); /* "**in procedure: " */
    v105 = Lprinc(nil, v105);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    v105 = stack[0];
    v105 = qcar(v105);
    v105 = Lprinc(nil, v105);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    v105 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    v105 = stack[0];
    v105 = qcdr(v105);
    stack[0] = v105;
    goto v87;

v87:
    v105 = stack[0];
    if (v105 == nil) goto v127;
    v105 = stack[0];
    v105 = qcar(v105);
    v105 = Lprinc(nil, v105);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    v105 = stack[0];
    v105 = qcdr(v105);
    stack[0] = v105;
    goto v87;

v127:
    v105 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    v105 = nil;
    { popv(2); return onevalue(v105); }

v172:
    v105 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v105); }
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



/* Code for endstat */

static Lisp_Object MS_CDECL CC_endstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for endstat");
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
    v96 = qvalue(elt(env, 1)); /* cursym!* */
    stack[0] = v96;
    v96 = elt(env, 2); /* end */
    fn = elt(env, 3); /* comm1 */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v96 = stack[0];
    popv(1);
    return ncons(v96);
/* error exit handlers */
v124:
    popv(1);
    return nil;
}



/* Code for evalequal */

static Lisp_Object CC_evalequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v101, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalequal");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v17;
    stack[-2] = v0;
/* end of prologue */
    v51 = stack[-2];
    fn = elt(env, 3); /* getrtype */
    stack[0] = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[-3] = stack[0];
    v51 = stack[-1];
    fn = elt(env, 3); /* getrtype */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    if (equal(stack[0], v51)) goto v96;
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v51); }

v96:
    v51 = stack[-3];
    if (v51 == nil) goto v87;
    v101 = stack[-2];
    v51 = stack[-1];
    v51 = (equal(v101, v51) ? lisp_true : nil);
    { popv(5); return onevalue(v51); }

v87:
    v147 = elt(env, 2); /* difference */
    v101 = stack[-2];
    v51 = stack[-1];
    v51 = list3(v147, v101, v51);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    fn = elt(env, 4); /* reval */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[-3] = v51;
    if (is_number(v51)) goto v5;
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v51); }

v5:
    v51 = stack[-3];
        popv(5);
        return Lzerop(nil, v51);
/* error exit handlers */
v174:
    popv(5);
    return nil;
}



/* Code for listtest */

static Lisp_Object MS_CDECL CC_listtest(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v86, v11;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "listtest");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listtest");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v17;
    stack[-2] = v0;
/* end of prologue */

v92:
    v99 = stack[-2];
    if (v99 == nil) goto v96;
    v11 = stack[0];
    v99 = stack[-2];
    v86 = qcar(v99);
    v99 = stack[-1];
    v99 = Lapply2(nil, 3, v11, v86, v99);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    if (v99 == nil) goto v98;
    v99 = stack[-2];
    v99 = qcar(v99);
    if (v99 == nil) goto v87;
    v99 = stack[-2];
    v99 = qcar(v99);
    { popv(4); return onevalue(v99); }

v87:
    v99 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v99); }

v98:
    v99 = stack[-2];
    v99 = qcdr(v99);
    stack[-2] = v99;
    goto v92;

v96:
    v99 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v99); }
/* error exit handlers */
v95:
    popv(4);
    return nil;
}



/* Code for ad_numsort */

static Lisp_Object CC_ad_numsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ad_numsort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v0;
/* end of prologue */
    v124 = v57;
    v57 = elt(env, 1); /* lambda_lqgavx_3 */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v124, v57);
    }
}



/* Code for lambda_lqgavx_3 */

static Lisp_Object CC_lambda_lqgavx_3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqgavx_3");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v124 = v17;
    v109 = v0;
/* end of prologue */
        return Lleq(nil, v109, v124);
}



/* Code for moduntag */

static Lisp_Object CC_moduntag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for moduntag");
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
    goto v124;

v124:
    v50 = stack[0];
    v100 = elt(env, 1); /* !:mod!: */
    if (!consp(v50)) goto v96;
    v50 = qcar(v50);
    if (!(v50 == v100)) goto v96;
    v50 = stack[-1];
    v100 = stack[0];
    v100 = qcdr(v100);
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v50, v100);
    }

v96:
    v100 = stack[0];
    if (!consp(v100)) goto v103;
    v100 = stack[0];
    v100 = qcar(v100);
    v50 = CC_moduntag(env, v100);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    v100 = stack[-1];
    v100 = cons(v50, v100);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    stack[-1] = v100;
    v100 = stack[0];
    v100 = qcdr(v100);
    stack[0] = v100;
    goto v124;

v103:
    v50 = stack[-1];
    v100 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v50, v100);
    }
/* error exit handlers */
v147:
    popv(3);
    return nil;
}



/* Code for image!-of!-power */

static Lisp_Object CC_imageKofKpower(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for image-of-power");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v0;
/* end of prologue */
    v12 = stack[-1];
    v11 = qvalue(elt(env, 1)); /* image!-set */
    v11 = Lassoc(nil, v12, v11);
    stack[-2] = v11;
    v11 = stack[-2];
    if (v11 == nil) goto v21;
    v11 = stack[-2];
    v11 = qcdr(v11);
    stack[-2] = v11;
    goto v97;

v97:
    v12 = stack[-2];
    v11 = stack[0];
        popv(4);
        return Lmodular_expt(nil, v12, v11);

v21:
    fn = elt(env, 2); /* next!-random!-number */
    v11 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    v11 = Lmodular_number(nil, v11);
    env = stack[-3];
    stack[-2] = v11;
    v13 = stack[-1];
    v12 = stack[-2];
    v11 = qvalue(elt(env, 1)); /* image!-set */
    v11 = acons(v13, v12, v11);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    qvalue(elt(env, 1)) = v11; /* image!-set */
    goto v97;
/* error exit handlers */
v14:
    popv(4);
    return nil;
}



/* Code for ofsf_ordatp */

static Lisp_Object CC_ofsf_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v86, v11, v12, v13, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ordatp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v13 = v17;
    v105 = v0;
/* end of prologue */
    v99 = v105;
    v99 = qcdr(v99);
    v99 = qcar(v99);
    v12 = v99;
    v99 = v13;
    v99 = qcdr(v99);
    v99 = qcar(v99);
    v11 = v99;
    v86 = v12;
    v99 = v11;
    if (equal(v86, v99)) goto v52;
    v99 = v12;
    v86 = v11;
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v99, v86);
    }

v52:
    v99 = v105;
    v99 = qcar(v99);
    v86 = v13;
    v86 = qcar(v86);
    {
        fn = elt(env, 2); /* ofsf_ordrelp */
        return (*qfn2(fn))(qenv(fn), v99, v86);
    }
}



/* Code for polynomheadreduceby */

static Lisp_Object CC_polynomheadreduceby(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomheadreduceby");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v17;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v96;

v96:
    v136 = stack[-2];
    v136 = qcar(v136);
    if (v136 == nil) goto v112;
    v136 = stack[-3];
    if (!(v136 == nil)) goto v112;
    v136 = stack[-2];
    v137 = qcar(v136);
    v136 = stack[-1];
    v136 = qcar(v136);
    fn = elt(env, 4); /* monomisdivisibleby */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    if (v136 == nil) goto v146;
    v136 = stack[-2];
    v137 = qcar(v136);
    v136 = stack[-1];
    v136 = qcar(v136);
    fn = elt(env, 5); /* monomdivide */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    stack[0] = stack[-2];
    v137 = stack[-1];
    fn = elt(env, 6); /* polynommultiplybymonom */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    fn = elt(env, 7); /* polynomadd */
    v136 = (*qfn2(fn))(qenv(fn), stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    goto v96;

v146:
    v136 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v136;
    goto v96;

v112:
    v136 = qvalue(elt(env, 3)); /* fluidbibasisreductionsmade */
    v136 = (Lisp_Object)((int32_t)(v136) + 0x10);
    qvalue(elt(env, 3)) = v136; /* fluidbibasisreductionsmade */
    v136 = nil;
    { popv(5); return onevalue(v136); }
/* error exit handlers */
v80:
    popv(5);
    return nil;
}



/* Code for simpg3 */

static Lisp_Object CC_simpg3(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpg3");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v0;
/* end of prologue */
    v124 = v57;
    v57 = elt(env, 1); /* g3 */
    {
        fn = elt(env, 2); /* simpcv */
        return (*qfn2(fn))(qenv(fn), v124, v57);
    }
}



/* Code for remove!-free!-vars!* */

static Lisp_Object CC_removeKfreeKvarsH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove-free-vars*");
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
    v172 = v0;
/* end of prologue */
    v92 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*!*noremove!*!* */
    qvalue(elt(env, 2)) = v92; /* !*!*noremove!*!* */
    v92 = v172;
    fn = elt(env, 3); /* remove!-free!-vars */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*!*noremove!*!* */
    { popv(2); return onevalue(v92); }
/* error exit handlers */
v96:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*!*noremove!*!* */
    popv(2);
    return nil;
}



/* Code for cl_susiupdknowl1 */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v3, Lisp_Object v26, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v147, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiupdknowl1");
#endif
    if (stack >= stacklimit)
    {
        push4(v26,v3,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v17,v3,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v26;
    stack[-1] = v3;
    v110 = v17;
    v101 = v0;
/* end of prologue */
    v147 = v101;
    v101 = elt(env, 1); /* and */
    if (v147 == v101) goto v4;
    v101 = v110;
    fn = elt(env, 2); /* rl_negateat */
    v147 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    v101 = stack[0];
    v110 = cons(v147, v101);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    v147 = stack[-1];
    v101 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* cl_susiupdknowl2 */
        return (*qfnn(fn))(qenv(fn), 3, v110, v147, v101);
    }

v4:
    v147 = v110;
    v101 = stack[0];
    v110 = cons(v147, v101);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    v147 = stack[-1];
    v101 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* cl_susiupdknowl2 */
        return (*qfnn(fn))(qenv(fn), 3, v110, v147, v101);
    }
/* error exit handlers */
v146:
    popv(3);
    return nil;
}



/* Code for rl_simp1 */

static Lisp_Object CC_rl_simp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213, v214, v215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simp1");
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

v182:
    v212 = qvalue(elt(env, 1)); /* rl_cid!* */
    if (!(v212 == nil)) goto v92;
    v212 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v212 == nil)) goto v18;
    v212 = elt(env, 3); /* "select a context" */
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    fn = elt(env, 13); /* lprie */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    goto v18;

v18:
    v212 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    goto v92;

v92:
    v212 = stack[0];
    if (!consp(v212)) goto v181;
    v212 = stack[0];
    fn = elt(env, 14); /* argnochk */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v212 = stack[0];
    v213 = qcar(v212);
    v212 = elt(env, 4); /* rl_simpfn */
    v212 = get(v213, v212);
    env = stack[-5];
    v214 = v212;
    if (v212 == nil) goto v118;
    v213 = v214;
    v212 = elt(env, 5); /* full */
    v212 = Lflagp(nil, v213, v212);
    env = stack[-5];
    if (v212 == nil) goto v136;
    stack[-1] = v214;
    v212 = stack[0];
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    {
        Lisp_Object v217 = stack[-1];
        popv(6);
        fn = elt(env, 15); /* apply */
        return (*qfn2(fn))(qenv(fn), v217, v212);
    }

v136:
    stack[-1] = v214;
    v212 = stack[0];
    v212 = qcdr(v212);
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    {
        Lisp_Object v218 = stack[-1];
        popv(6);
        fn = elt(env, 15); /* apply */
        return (*qfn2(fn))(qenv(fn), v218, v212);
    }

v118:
    v212 = stack[0];
    v214 = qcar(v212);
    v212 = qvalue(elt(env, 1)); /* rl_cid!* */
    v213 = qcar(v212);
    v212 = elt(env, 6); /* simpfnname */
    v212 = get(v213, v212);
    env = stack[-5];
    v212 = get(v214, v212);
    env = stack[-5];
    v214 = v212;
    if (v212 == nil) goto v90;
    v213 = v214;
    v212 = elt(env, 5); /* full */
    v212 = Lflagp(nil, v213, v212);
    env = stack[-5];
    if (v212 == nil) goto v219;
    stack[-1] = v214;
    v212 = stack[0];
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    {
        Lisp_Object v220 = stack[-1];
        popv(6);
        fn = elt(env, 15); /* apply */
        return (*qfn2(fn))(qenv(fn), v220, v212);
    }

v219:
    stack[-1] = v214;
    v212 = stack[0];
    v212 = qcdr(v212);
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    {
        Lisp_Object v221 = stack[-1];
        popv(6);
        fn = elt(env, 15); /* apply */
        return (*qfn2(fn))(qenv(fn), v221, v212);
    }

v90:
    v212 = stack[0];
    v213 = qcar(v212);
    v212 = elt(env, 7); /* psopfn */
    v212 = get(v213, v212);
    env = stack[-5];
    v214 = v212;
    if (v212 == nil) goto v184;
    v213 = v214;
    v212 = stack[0];
    v212 = qcdr(v212);
    v212 = Lapply1(nil, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    stack[0] = v212;
    goto v182;

v184:
    v212 = stack[0];
    v213 = qcar(v212);
    v212 = elt(env, 8); /* opfn */
    v212 = Lflagp(nil, v213, v212);
    env = stack[-5];
    if (v212 == nil) goto v222;
    v212 = stack[0];
    stack[-4] = qcar(v212);
    v212 = stack[0];
    v212 = qcdr(v212);
    stack[-3] = v212;
    v212 = stack[-3];
    if (v212 == nil) goto v141;
    v212 = stack[-3];
    v212 = qcar(v212);
    fn = elt(env, 16); /* reval */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    stack[-1] = v212;
    stack[-2] = v212;
    goto v139;

v139:
    v212 = stack[-3];
    v212 = qcdr(v212);
    stack[-3] = v212;
    v212 = stack[-3];
    if (v212 == nil) goto v223;
    stack[0] = stack[-1];
    v212 = stack[-3];
    v212 = qcar(v212);
    fn = elt(env, 16); /* reval */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v212 = Lrplacd(nil, stack[0], v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v212 = stack[-1];
    v212 = qcdr(v212);
    stack[-1] = v212;
    goto v139;

v223:
    v212 = stack[-2];
    goto v29;

v29:
    fn = elt(env, 15); /* apply */
    v212 = (*qfn2(fn))(qenv(fn), stack[-4], v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    stack[0] = v212;
    goto v182;

v141:
    v212 = qvalue(elt(env, 9)); /* nil */
    goto v29;

v222:
    v212 = stack[0];
    v213 = qcar(v212);
    v212 = elt(env, 10); /* prepfn2 */
    v212 = get(v213, v212);
    env = stack[-5];
    v214 = v212;
    if (v212 == nil) goto v224;
    stack[-1] = v214;
    v212 = stack[0];
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    fn = elt(env, 15); /* apply */
    v212 = (*qfn2(fn))(qenv(fn), stack[-1], v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    stack[0] = v212;
    goto v182;

v224:
    v212 = stack[0];
    v213 = qcar(v212);
    v212 = elt(env, 11); /* "predicate" */
    fn = elt(env, 17); /* rl_redmsg */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v212 = stack[0];
    v215 = qcar(v212);
    v212 = qvalue(elt(env, 1)); /* rl_cid!* */
    v213 = qcar(v212);
    v212 = elt(env, 6); /* simpfnname */
    v214 = get(v213, v212);
    env = stack[-5];
    v212 = qvalue(elt(env, 1)); /* rl_cid!* */
    v213 = qcar(v212);
    v212 = elt(env, 12); /* simpdefault */
    v212 = get(v213, v212);
    env = stack[-5];
    v212 = Lputprop(nil, 3, v215, v214, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-5];
    v212 = stack[0];
    stack[0] = v212;
    goto v182;

v181:
    v212 = stack[0];
    {
        popv(6);
        fn = elt(env, 18); /* rl_simpatom */
        return (*qfn1(fn))(qenv(fn), v212);
    }
/* error exit handlers */
v216:
    popv(6);
    return nil;
}



/* Code for nary */

static Lisp_Object CC_nary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nary");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v0;
/* end of prologue */
    v136 = stack[-1];
    v137 = qcar(v136);
    v136 = elt(env, 1); /* e */
    if (v137 == v136) goto v9;
    v136 = qvalue(elt(env, 3)); /* nil */
    goto v57;

v57:
    if (v136 == nil) goto v6;
    v136 = stack[-1];
    v137 = qcdr(v136);
    v136 = elt(env, 4); /* exp */
    fn = elt(env, 10); /* unary */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    goto v92;

v92:
    v136 = nil;
    { popv(3); return onevalue(v136); }

v6:
    v136 = elt(env, 5); /* "<apply>" */
    fn = elt(env, 11); /* printout */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    v136 = elt(env, 6); /* "<" */
    v136 = Lprinc(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    v136 = stack[0];
    v136 = Lprinc(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    v136 = stack[-1];
    v137 = qcar(v136);
    v136 = elt(env, 7); /* "/" */
    fn = elt(env, 12); /* attributesml */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    v136 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 13); /* indent!* */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    v136 = stack[-1];
    v136 = qcdr(v136);
    fn = elt(env, 14); /* multi_elem */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    v136 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    v136 = elt(env, 9); /* "</apply>" */
    fn = elt(env, 11); /* printout */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    goto v92;

v9:
    v137 = stack[0];
    v136 = elt(env, 2); /* power */
    v136 = (v137 == v136 ? lisp_true : nil);
    goto v57;
/* error exit handlers */
v225:
    popv(3);
    return nil;
}



/* Code for opmtch */

static Lisp_Object CC_opmtch(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v148, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opmtch");
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
    stack[-7] = nil;
    v58 = stack[-6];
    v148 = qcar(v58);
    v58 = elt(env, 0); /* opmtch */
    v58 = get(v148, v58);
    env = stack[-8];
    stack[-5] = v58;
    if (v58 == nil) goto v18;
    v58 = qvalue(elt(env, 2)); /* subfg!* */
    if (v58 == nil) goto v4;
    v58 = qvalue(elt(env, 3)); /* !*uncached */
    if (v58 == nil) goto v60;
    v58 = qvalue(elt(env, 1)); /* nil */
    goto v120;

v120:
    if (v58 == nil) goto v109;
    v58 = stack[-7];
    v58 = qcdr(v58);
    { popv(9); return onevalue(v58); }

v109:
    v58 = stack[-6];
    v58 = qcdr(v58);
    stack[-4] = v58;
    v58 = stack[-4];
    if (v58 == nil) goto v146;
    v58 = stack[-4];
    v58 = qcar(v58);
    stack[0] = v58;
    v58 = stack[0];
    if (!consp(v58)) goto v81;
    v58 = stack[0];
    v58 = CC_opmtch(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-8];
    v148 = v58;
    v58 = v148;
    if (v58 == nil) goto v68;
    v58 = v148;
    goto v59;

v59:
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-8];
    stack[-2] = v58;
    stack[-3] = v58;
    goto v101;

v101:
    v58 = stack[-4];
    v58 = qcdr(v58);
    stack[-4] = v58;
    v58 = stack[-4];
    if (v58 == nil) goto v44;
    stack[-1] = stack[-2];
    v58 = stack[-4];
    v58 = qcar(v58);
    stack[0] = v58;
    v58 = stack[0];
    if (!consp(v58)) goto v74;
    v58 = stack[0];
    v58 = CC_opmtch(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-8];
    v148 = v58;
    v58 = v148;
    if (v58 == nil) goto v94;
    v58 = v148;
    goto v142;

v142:
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-8];
    v58 = Lrplacd(nil, stack[-1], v58);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-8];
    v58 = stack[-2];
    v58 = qcdr(v58);
    stack[-2] = v58;
    goto v101;

v94:
    v58 = stack[0];
    goto v142;

v74:
    v58 = stack[0];
    goto v142;

v44:
    v58 = stack[-3];
    goto v51;

v51:
    stack[0] = v58;
    goto v112;

v112:
    v58 = stack[-5];
    if (v58 == nil) goto v57;
    v150 = stack[0];
    v58 = stack[-5];
    v58 = qcar(v58);
    v148 = qcar(v58);
    v58 = stack[-6];
    v58 = qcar(v58);
    fn = elt(env, 5); /* mcharg */
    v58 = (*qfnn(fn))(qenv(fn), 3, v150, v148, v58);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-8];
    stack[-1] = v58;
    goto v96;

v96:
    v58 = stack[-1];
    if (v58 == nil) goto v34;
    v58 = stack[-1];
    v148 = qcar(v58);
    v58 = stack[-5];
    v58 = qcar(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v58 = qcdr(v58);
    v58 = Lsubla(nil, v148, v58);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-8];
    fn = elt(env, 6); /* eval */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-8];
    if (v58 == nil) goto v231;
    v58 = stack[-1];
    v148 = qcar(v58);
    v58 = stack[-5];
    v58 = qcar(v58);
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v58 = Lsubla(nil, v148, v58);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-8];
    stack[-7] = v58;
    goto v57;

v57:
    v58 = qvalue(elt(env, 3)); /* !*uncached */
    if (!(v58 == nil)) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    stack[0] = qvalue(elt(env, 4)); /* alglist!* */
    v150 = stack[-6];
    v148 = stack[-7];
    v58 = qvalue(elt(env, 4)); /* alglist!* */
    v58 = qcdr(v58);
    v58 = acons(v150, v148, v58);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-8];
    v58 = Lrplacd(nil, stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v230;
    { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }

v231:
    v58 = stack[-1];
    v58 = qcdr(v58);
    stack[-1] = v58;
    goto v96;

v34:
    v58 = stack[-5];
    v58 = qcdr(v58);
    stack[-5] = v58;
    goto v112;

v68:
    v58 = stack[0];
    goto v59;

v81:
    v58 = stack[0];
    goto v59;

v146:
    v58 = qvalue(elt(env, 1)); /* nil */
    goto v51;

v60:
    v148 = stack[-6];
    v58 = qvalue(elt(env, 4)); /* alglist!* */
    v58 = qcdr(v58);
    v58 = Lassoc(nil, v148, v58);
    stack[-7] = v58;
    goto v120;

v4:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v58); }

v18:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v58); }
/* error exit handlers */
v230:
    popv(9);
    return nil;
}



/* Code for unchecked_getmatelem */

static Lisp_Object CC_unchecked_getmatelem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v137, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unchecked_getmatelem");
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
    v136 = stack[0];
    v137 = qcar(v136);
    v59 = v137;
    v136 = elt(env, 1); /* mat */
    if (!consp(v137)) goto v10;
    v137 = qcar(v137);
    if (!(v137 == v136)) goto v10;
    v136 = v59;
    v137 = qcdr(v136);
    v136 = stack[0];
    v136 = qcdr(v136);
    v136 = qcar(v136);
    fn = elt(env, 6); /* pnth */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-1];
    v137 = qcar(v136);
    v136 = stack[0];
    v136 = qcdr(v136);
    v136 = qcdr(v136);
    v136 = qcar(v136);
    fn = elt(env, 6); /* pnth */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    v136 = qcar(v136);
    { popv(2); return onevalue(v136); }

v10:
    v59 = elt(env, 2); /* "Matrix" */
    v136 = stack[0];
    v137 = qcar(v136);
    v136 = elt(env, 3); /* "not set" */
    v136 = list3(v59, v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-1];
    v137 = v136;
    v136 = v137;
    qvalue(elt(env, 4)) = v136; /* errmsg!* */
    v136 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v136 == nil)) goto v104;
    v136 = v137;
    fn = elt(env, 7); /* lprie */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-1];
    goto v104;

v104:
    v136 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v225;
    v136 = nil;
    { popv(2); return onevalue(v136); }
/* error exit handlers */
v225:
    popv(2);
    return nil;
}



/* Code for evaluate1 */

static Lisp_Object CC_evaluate1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v17)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v231, v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate1");
#endif
    if (stack >= stacklimit)
    {
        push2(v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v231 = v17;
    v34 = v0;
/* end of prologue */
    v186 = v34;
    if (is_number(v186)) goto v1;
    v186 = v34;
    if (v186 == nil) goto v1;
    v186 = v34;
    v186 = Lconsp(nil, v186);
    env = stack[0];
    if (v186 == nil) goto v103;
    v186 = v34;
    v35 = qcar(v186);
    v186 = elt(env, 1); /* dname */
    v186 = get(v35, v186);
    env = stack[0];
    if (!(v186 == nil)) { popv(1); return onevalue(v34); }

v103:
    v35 = v34;
    v186 = v231;
    v186 = Lassoc(nil, v35, v186);
    v35 = v186;
    v186 = v35;
    if (v186 == nil) goto v86;
    v186 = v35;
    v186 = qcdr(v186);
    { popv(1); return onevalue(v186); }

v86:
    v186 = v34;
    if (!consp(v186)) goto v51;
    v186 = v34;
    v186 = qcar(v186);
    v34 = qcdr(v34);
    {
        popv(1);
        fn = elt(env, 13); /* evaluate2 */
        return (*qfnn(fn))(qenv(fn), 3, v186, v34, v231);
    }

v51:
    v231 = v34;
    v186 = elt(env, 2); /* i */
    if (v231 == v186) goto v67;
    v231 = v34;
    v186 = elt(env, 8); /* e */
    if (v231 == v186) goto v176;
    v231 = v34;
    v186 = elt(env, 10); /* pi */
    v186 = (v231 == v186 ? lisp_true : nil);
    goto v143;

v143:
    if (v186 == nil) goto v121;
    v186 = v34;
    fn = elt(env, 14); /* simp */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[0];
    v186 = qcar(v186);
    {
        popv(1);
        fn = elt(env, 15); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v186);
    }

v121:
    v186 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 11)) = v186; /* !*evaluateerror */
    v231 = v34;
    v186 = elt(env, 12); /* "number" */
    {
        popv(1);
        fn = elt(env, 16); /* typerr */
        return (*qfn2(fn))(qenv(fn), v231, v186);
    }

v176:
    v186 = qvalue(elt(env, 9)); /* t */
    goto v143;

v67:
    v231 = qvalue(elt(env, 3)); /* dmode!* */
    v186 = elt(env, 4); /* ivalue */
    v186 = get(v231, v186);
    env = stack[0];
    v34 = v186;
    if (v186 == nil) goto v166;
    v231 = v34;
    v186 = elt(env, 5); /* (nil) */
    fn = elt(env, 17); /* apply */
    v186 = (*qfn2(fn))(qenv(fn), v231, v186);
    nil = C_nil;
    if (exception_pending()) goto v157;
    v186 = qcar(v186);
    { popv(1); return onevalue(v186); }

v166:
    v186 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v186 == nil)) goto v108;
    v186 = elt(env, 7); /* "i used as indeterminate value" */
    fn = elt(env, 18); /* lprie */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[0];
    goto v108;

v108:
    v186 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v157;
    v186 = nil;
    { popv(1); return onevalue(v186); }

v1:
    v186 = v34;
    {
        popv(1);
        fn = elt(env, 15); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v186);
    }
/* error exit handlers */
v157:
    popv(1);
    return nil;
}



/* Code for lispassignp */

static Lisp_Object CC_lispassignp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispassignp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v0;
/* end of prologue */
    v124 = elt(env, 1); /* setq */
        return Leqcar(nil, v57, v124);
}



/* Code for assert_uninstall1 */

static Lisp_Object CC_assert_uninstall1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v67, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_uninstall1");
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
    v67 = stack[0];
    v48 = elt(env, 1); /* assert_installed */
    v48 = get(v67, v48);
    env = stack[-2];
    if (v48 == nil) goto v2;
    v136 = stack[0];
    v67 = stack[0];
    v48 = elt(env, 6); /* assert_noassertfn */
    v48 = get(v67, v48);
    env = stack[-2];
    fn = elt(env, 7); /* copyd */
    v48 = (*qfn2(fn))(qenv(fn), v136, v48);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-2];
    v67 = stack[0];
    v48 = elt(env, 1); /* assert_installed */
    v136 = qvalue(elt(env, 3)); /* nil */
        popv(3);
        return Lputprop(nil, 3, v67, v48, v136);

v2:
    v48 = qvalue(elt(env, 2)); /* !*msg */
    if (v48 == nil) goto v21;
    stack[-1] = elt(env, 4); /* "***" */
    v67 = elt(env, 5); /* "assert not installed for" */
    v48 = stack[0];
    v48 = list2(v67, v48);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-2];
    {
        Lisp_Object v225 = stack[-1];
        popv(3);
        fn = elt(env, 8); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v225, v48);
    }

v21:
    v48 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v48); }
/* error exit handlers */
v81:
    popv(3);
    return nil;
}



/* Code for dp_times_bcmo */

static Lisp_Object MS_CDECL CC_dp_times_bcmo(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dp_times_bcmo");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_times_bcmo");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v43 = v3;
    stack[-5] = v17;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = v43;
    v43 = stack[-7];
    if (v43 == nil) goto v18;
    v43 = stack[-7];
    v43 = qcar(v43);
    stack[-1] = v43;
    v117 = stack[-5];
    v43 = stack[-1];
    v43 = qcar(v43);
    fn = elt(env, 2); /* mo_sum */
    stack[0] = (*qfn2(fn))(qenv(fn), v117, v43);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-8];
    v117 = stack[-6];
    v43 = stack[-1];
    v43 = qcdr(v43);
    fn = elt(env, 3); /* bc_prod */
    v43 = (*qfn2(fn))(qenv(fn), v117, v43);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-8];
    v43 = cons(stack[0], v43);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-8];
    v43 = ncons(v43);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-8];
    stack[-3] = v43;
    stack[-4] = v43;
    goto v96;

v96:
    v43 = stack[-7];
    v43 = qcdr(v43);
    stack[-7] = v43;
    v43 = stack[-7];
    if (v43 == nil) { Lisp_Object res = stack[-4]; popv(9); return onevalue(res); }
    stack[-2] = stack[-3];
    v43 = stack[-7];
    v43 = qcar(v43);
    stack[-1] = v43;
    v117 = stack[-5];
    v43 = stack[-1];
    v43 = qcar(v43);
    fn = elt(env, 2); /* mo_sum */
    stack[0] = (*qfn2(fn))(qenv(fn), v117, v43);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-8];
    v117 = stack[-6];
    v43 = stack[-1];
    v43 = qcdr(v43);
    fn = elt(env, 3); /* bc_prod */
    v43 = (*qfn2(fn))(qenv(fn), v117, v43);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-8];
    v43 = cons(stack[0], v43);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-8];
    v43 = ncons(v43);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-8];
    v43 = Lrplacd(nil, stack[-2], v43);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-8];
    v43 = stack[-3];
    v43 = qcdr(v43);
    stack[-3] = v43;
    goto v96;

v18:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v43); }
/* error exit handlers */
v116:
    popv(9);
    return nil;
}



/* Code for addgt */

static Lisp_Object CC_addgt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addgt");
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
    v52 = qvalue(elt(env, 1)); /* ordering */
    v120 = elt(env, 2); /* lex */
    if (v52 == v120) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v52 = elt(env, 3); /* plus */
    v120 = stack[0];
    v120 = cons(v52, v120);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    fn = elt(env, 4); /* eval */
    v52 = (*qfn1(fn))(qenv(fn), v120);
    nil = C_nil;
    if (exception_pending()) goto v104;
    v120 = stack[0];
    popv(2);
    return cons(v52, v120);
/* error exit handlers */
v104:
    popv(2);
    return nil;
}



/* Code for wi_new */

static Lisp_Object CC_wi_new(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wi_new");
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
    v87 = qvalue(elt(env, 1)); /* wi_number */
    v87 = add1(v87);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    qvalue(elt(env, 1)) = v87; /* wi_number */
    v88 = elt(env, 2); /* !: */
    v87 = qvalue(elt(env, 1)); /* wi_number */
    fn = elt(env, 4); /* mkid */
    v87 = (*qfn2(fn))(qenv(fn), v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    v87 = Lintern(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    stack[-3] = v87;
    stack[-1] = stack[-3];
    stack[0] = elt(env, 3); /* windex */
    v87 = stack[-2];
    v87 = ncons(v87);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    v87 = Lputprop(nil, 3, stack[-1], stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v104;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v104:
    popv(5);
    return nil;
}



/* Code for tensorp */

static Lisp_Object CC_tensorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tensorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v10 = v8;
    if (!consp(v10)) goto v21;
    v10 = v8;
    v10 = qcar(v10);
    v8 = elt(env, 1); /* tensor */
        return Lflagp(nil, v10, v8);

v21:
    v10 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v10);
}



/* Code for ofsf_entry2at */

static Lisp_Object MS_CDECL CC_ofsf_entry2at(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v17,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v104, v60, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_entry2at");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v17,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v17,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v104 = v3;
    v60 = v17;
    v97 = v0;
/* end of prologue */
    v53 = qvalue(elt(env, 1)); /* !*rlidentify */
    if (v53 == nil) goto v7;
    v53 = v97;
    fn = elt(env, 2); /* ofsf_entry2at1 */
    v53 = (*qfnn(fn))(qenv(fn), 3, v53, v60, v104);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cl_identifyat */
        return (*qfn1(fn))(qenv(fn), v53);
    }

v7:
    v53 = v97;
    {
        popv(1);
        fn = elt(env, 2); /* ofsf_entry2at1 */
        return (*qfnn(fn))(qenv(fn), 3, v53, v60, v104);
    }
/* error exit handlers */
v98:
    popv(1);
    return nil;
}



/* Code for squared!+matrix!+p */

static Lisp_Object CC_squaredLmatrixLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for squared+matrix+p");
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
    v111 = stack[0];
    fn = elt(env, 2); /* matrix!+p */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    if (v111 == nil) goto v1;
    v111 = stack[0];
    fn = elt(env, 3); /* get!+row!+nr */
    stack[-1] = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    v111 = stack[0];
    fn = elt(env, 4); /* get!+col!+nr */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    if (!(equal(stack[-1], v111))) goto v1;
    v111 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v111); }

v1:
    v111 = nil;
    { popv(3); return onevalue(v111); }
/* error exit handlers */
v4:
    popv(3);
    return nil;
}



/* Code for mri_realvarp */

static Lisp_Object CC_mri_realvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_realvarp");
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
    v16 = v0;
/* end of prologue */
    v4 = v16;
    if (symbolp(v4)) goto v23;
    v4 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v4); }

v23:
    v4 = elt(env, 2); /* mri_type */
    v4 = get(v16, v4);
    env = stack[0];
    v16 = elt(env, 3); /* real */
    v4 = (v4 == v16 ? lisp_true : nil);
    { popv(1); return onevalue(v4); }
}



/* Code for searchpl */

static Lisp_Object CC_searchpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for searchpl");
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
    goto v92;

v92:
    v68 = stack[-1];
    if (!consp(v68)) goto v20;
    v68 = stack[-1];
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    goto v19;

v19:
    if (v68 == nil) goto v4;
    v68 = qvalue(elt(env, 2)); /* nil */
    v173 = v68;
    goto v112;

v112:
    v68 = stack[-2];
    if (v68 == nil) { popv(4); return onevalue(v173); }
    v68 = stack[-2];
    v68 = qcar(v68);
    fn = elt(env, 3); /* setunion */
    v68 = (*qfn2(fn))(qenv(fn), v68, v173);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-3];
    v173 = v68;
    v68 = stack[-2];
    v68 = qcdr(v68);
    stack[-2] = v68;
    goto v112;

v4:
    v68 = stack[-1];
    v68 = qcar(v68);
    if (!consp(v68)) goto v60;
    v68 = stack[-1];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    goto v104;

v104:
    if (v68 == nil) goto v83;
    v68 = qvalue(elt(env, 2)); /* nil */
    v173 = v68;
    goto v15;

v15:
    v68 = stack[-2];
    v68 = cons(v173, v68);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-3];
    stack[-2] = v68;
    v68 = stack[-1];
    v68 = qcdr(v68);
    stack[-1] = v68;
    goto v92;

v83:
    v68 = stack[-1];
    v68 = qcar(v68);
    v68 = qcar(v68);
    stack[0] = qcar(v68);
    v68 = stack[-1];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    v68 = CC_searchpl(env, v68);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-3];
    v68 = cons(stack[0], v68);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-3];
    v173 = v68;
    goto v15;

v60:
    v68 = qvalue(elt(env, 1)); /* t */
    goto v104;

v20:
    v68 = qvalue(elt(env, 1)); /* t */
    goto v19;
/* error exit handlers */
v43:
    popv(4);
    return nil;
}



setup_type const u13_setup[] =
{
    {"revalind",                CC_revalind,    too_many_1,    wrong_no_1},
    {"all_defined_vertex",      too_few_2,      CC_all_defined_vertex,wrong_no_2},
    {"getmatelem",              CC_getmatelem,  too_many_1,    wrong_no_1},
    {"b:extadd",                too_few_2,      CC_bTextadd,   wrong_no_2},
    {"negate-term",             CC_negateKterm, too_many_1,    wrong_no_1},
    {"ofsf_smmkatl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatl},
    {"qqe_simplat1",            too_few_2,      CC_qqe_simplat1,wrong_no_2},
    {"ibalp_hassimple",         CC_ibalp_hassimple,too_many_1, wrong_no_1},
    {"constsml",                CC_constsml,    too_many_1,    wrong_no_1},
    {"simprecip",               CC_simprecip,   too_many_1,    wrong_no_1},
    {"list-mgen",               CC_listKmgen,   too_many_1,    wrong_no_1},
    {"vbcgcd",                  too_few_2,      CC_vbcgcd,     wrong_no_2},
    {"groebcplistsortin",       too_few_2,      CC_groebcplistsortin,wrong_no_2},
    {"termordp!",               too_few_2,      CC_termordpB,  wrong_no_2},
    {"putd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_putd},
    {"setel",                   too_few_2,      CC_setel,      wrong_no_2},
    {"mv2sf1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mv2sf1},
    {"make-term",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKterm},
    {"bc_inv",                  CC_bc_inv,      too_many_1,    wrong_no_1},
    {"class",                   CC_class,       too_many_1,    wrong_no_1},
    {"pv_times2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pv_times2},
    {"b:ordexn",                too_few_2,      CC_bTordexn,   wrong_no_2},
    {"split_ext",               too_few_2,      CC_split_ext,  wrong_no_2},
    {"rl_prepfof",              CC_rl_prepfof,  too_many_1,    wrong_no_1},
    {"wureducedpolysp",         too_few_2,      CC_wureducedpolysp,wrong_no_2},
    {"get_rep_matrix_in",       too_few_2,      CC_get_rep_matrix_in,wrong_no_2},
    {"qqe_number-of-adds-in-qterm",CC_qqe_numberKofKaddsKinKqterm,too_many_1,wrong_no_1},
    {"cgb_buch-ev_divides?",    too_few_2,      CC_cgb_buchKev_dividesW,wrong_no_2},
    {"stats_getargs",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_stats_getargs},
    {"matsm*1",                 CC_matsmH1,     too_many_1,    wrong_no_1},
    {"chk",                     CC_chk,         too_many_1,    wrong_no_1},
    {"add_minus",               CC_add_minus,   too_many_1,    wrong_no_1},
    {"fctlength",               CC_fctlength,   too_many_1,    wrong_no_1},
    {"trwrite",                 CC_trwrite,     too_many_1,    wrong_no_1},
    {"endstat",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_endstat},
    {"evalequal",               too_few_2,      CC_evalequal,  wrong_no_2},
    {"listtest",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_listtest},
    {"ad_numsort",              CC_ad_numsort,  too_many_1,    wrong_no_1},
    {"lambda_lqgavx_3",         too_few_2,      CC_lambda_lqgavx_3,wrong_no_2},
    {"moduntag",                CC_moduntag,    too_many_1,    wrong_no_1},
    {"image-of-power",          too_few_2,      CC_imageKofKpower,wrong_no_2},
    {"ofsf_ordatp",             too_few_2,      CC_ofsf_ordatp,wrong_no_2},
    {"polynomheadreduceby",     too_few_2,      CC_polynomheadreduceby,wrong_no_2},
    {"simpg3",                  CC_simpg3,      too_many_1,    wrong_no_1},
    {"remove-free-vars*",       CC_removeKfreeKvarsH,too_many_1,wrong_no_1},
    {"cl_susiupdknowl1",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl1},
    {"rl_simp1",                CC_rl_simp1,    too_many_1,    wrong_no_1},
    {"nary",                    too_few_2,      CC_nary,       wrong_no_2},
    {"opmtch",                  CC_opmtch,      too_many_1,    wrong_no_1},
    {"unchecked_getmatelem",    CC_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"evaluate1",               too_few_2,      CC_evaluate1,  wrong_no_2},
    {"lispassignp",             CC_lispassignp, too_many_1,    wrong_no_1},
    {"assert_uninstall1",       CC_assert_uninstall1,too_many_1,wrong_no_1},
    {"dp_times_bcmo",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_dp_times_bcmo},
    {"addgt",                   CC_addgt,       too_many_1,    wrong_no_1},
    {"wi_new",                  CC_wi_new,      too_many_1,    wrong_no_1},
    {"tensorp",                 CC_tensorp,     too_many_1,    wrong_no_1},
    {"ofsf_entry2at",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at},
    {"squared+matrix+p",        CC_squaredLmatrixLp,too_many_1,wrong_no_1},
    {"mri_realvarp",            CC_mri_realvarp,too_many_1,    wrong_no_1},
    {"searchpl",                CC_searchpl,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u13", (two_args *)"21677 2236031 2907285", 0}
};

/* end of generated code */
