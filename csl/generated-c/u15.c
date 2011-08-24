
/* $destdir\u15.c        Machine generated C code */

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


/* Code for command */

static Lisp_Object MS_CDECL CC_command(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57, v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "command");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for command");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* errmsg!* */
    qvalue(elt(env, 1)) = nil; /* errmsg!* */
    stack[-2] = qvalue(elt(env, 2)); /* loopdelimslist!* */
    qvalue(elt(env, 2)) = nil; /* loopdelimslist!* */
    v56 = qvalue(elt(env, 3)); /* !*demo */
    if (v56 == nil) goto v60;
    v56 = qvalue(elt(env, 4)); /* ifl!* */
    if (v56 == nil) goto v60;
    fn = elt(env, 32); /* commdemo */
    v56 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    goto v62;

v62:
    qvalue(elt(env, 2)) = stack[-2]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-3]; /* errmsg!* */
    { popv(5); return onevalue(v56); }

v60:
    v56 = qvalue(elt(env, 5)); /* !*slin */
    if (v56 == nil) goto v63;
    v56 = qvalue(elt(env, 7)); /* !*reduce4 */
    goto v64;

v64:
    if (!(v56 == nil)) goto v65;
    v56 = qvalue(elt(env, 4)); /* ifl!* */
    if (v56 == nil) goto v66;
    v56 = qvalue(elt(env, 4)); /* ifl!* */
    v58 = qcar(v56);
    v57 = (Lisp_Object)17; /* 1 */
    v56 = qvalue(elt(env, 9)); /* curline!* */
    v56 = list2star(v58, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    goto v67;

v67:
    qvalue(elt(env, 10)) = v56; /* cloc!* */
    v56 = qvalue(elt(env, 11)); /* lreadfn!* */
    if (v56 == nil) goto v68;
    v57 = qvalue(elt(env, 11)); /* lreadfn!* */
    v56 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 33); /* lispapply */
    v56 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    goto v69;

v69:
    stack[-1] = v56;
    goto v70;

v70:
    v56 = qvalue(elt(env, 7)); /* !*reduce4 */
    if (v56 == nil) goto v71;
    v56 = qvalue(elt(env, 28)); /* !*debug */
    if (v56 == nil) goto v72;
    v56 = elt(env, 29); /* "Parse: " */
    v56 = Lprinc(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[0] = stack[-1];
    v56 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    fn = elt(env, 34); /* superprinm */
    v56 = (*qfn2(fn))(qenv(fn), stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v56 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    goto v72;

v72:
    v57 = qvalue(elt(env, 20)); /* key!* */
    v56 = elt(env, 30); /* !*semicol!* */
    if (v57 == v56) goto v65;
    v56 = qvalue(elt(env, 7)); /* !*reduce4 */
    if (v56 == nil) goto v73;
    v56 = stack[-1];
    fn = elt(env, 35); /* n_form */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-1] = v56;
    goto v74;

v74:
    v56 = qvalue(elt(env, 28)); /* !*debug */
    if (v56 == nil) goto v75;
    v56 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v56 = elt(env, 31); /* "Form: " */
    v56 = Lprinc(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[0] = stack[-1];
    v56 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    fn = elt(env, 34); /* superprinm */
    v56 = (*qfn2(fn))(qenv(fn), stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v56 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    goto v75;

v75:
    v56 = stack[-1];
    goto v62;

v73:
    v56 = stack[-1];
    fn = elt(env, 36); /* form */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-1] = v56;
    goto v74;

v65:
    fn = elt(env, 37); /* readch1 */
    v56 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    qvalue(elt(env, 12)) = v56; /* crchar!* */
    v57 = qvalue(elt(env, 12)); /* crchar!* */
    v56 = qvalue(elt(env, 13)); /* !$eol!$ */
    if (equal(v57, v56)) goto v65;
    fn = elt(env, 38); /* command1 */
    v56 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-1] = v56;
    goto v70;

v71:
    v56 = qvalue(elt(env, 14)); /* !*struct */
    if (v56 == nil) goto v76;
    v56 = stack[-1];
    fn = elt(env, 39); /* structchk */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-1] = v56;
    goto v76;

v76:
    v56 = qvalue(elt(env, 15)); /* !*pret */
    if (v56 == nil) goto v77;
    v56 = stack[-1];
    if (!consp(v56)) goto v78;
    v56 = stack[-1];
    v57 = qcar(v56);
    v56 = elt(env, 16); /* (in out shut) */
    v56 = Lmemq(nil, v57, v56);
    v56 = (v56 == nil ? lisp_true : nil);
    goto v79;

v79:
    if (v56 == nil) goto v77;
    v56 = stack[-1];
    if (v56 == nil) goto v80;
    v56 = qvalue(elt(env, 8)); /* nil */
    goto v81;

v81:
    if (v56 == nil) goto v82;
    v56 = elt(env, 18); /* end */
    fn = elt(env, 40); /* rprint */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    goto v77;

v77:
    v56 = qvalue(elt(env, 5)); /* !*slin */
    if (v56 == nil) goto v83;
    v57 = elt(env, 19); /* symbolic */
    v56 = stack[-1];
    v56 = list2(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    goto v62;

v83:
    v56 = stack[-1];
    fn = elt(env, 36); /* form */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v57 = v56;
    v58 = qvalue(elt(env, 20)); /* key!* */
    v56 = elt(env, 21); /* modefn */
    v56 = Lflagp(nil, v58, v56);
    env = stack[-4];
    if (v56 == nil) goto v84;
    v56 = qvalue(elt(env, 20)); /* key!* */
    goto v85;

v85:
    stack[0] = v56;
    v59 = v57;
    v58 = qvalue(elt(env, 8)); /* nil */
    v57 = elt(env, 19); /* symbolic */
    fn = elt(env, 41); /* convertmode1 */
    v56 = (*qfnn(fn))(qenv(fn), 4, v59, v58, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v56 = list2(stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    goto v62;

v84:
    v56 = v57;
    if (!consp(v56)) goto v86;
    v56 = v57;
    v58 = qcar(v56);
    v56 = elt(env, 22); /* quote */
    if (v58 == v56) goto v87;
    v56 = v57;
    v56 = qcar(v56);
    if (!(symbolp(v56))) goto v88;
    v56 = v57;
    v58 = qcar(v56);
    v56 = elt(env, 23); /* nochange */
    v56 = Lflagp(nil, v58, v56);
    env = stack[-4];
    if (v56 == nil) goto v89;
    v56 = qvalue(elt(env, 6)); /* t */
    goto v90;

v90:
    if (v56 == nil) goto v88;
    v56 = v57;
    v58 = qcar(v56);
    v56 = elt(env, 26); /* (setq setel setf) */
    v56 = Lmemq(nil, v58, v56);
    if (v56 == nil) goto v91;
    v56 = v57;
    v56 = qcdr(v56);
    v56 = qcdr(v56);
    v58 = qcar(v56);
    v56 = elt(env, 22); /* quote */
    v56 = Leqcar(nil, v58, v56);
    env = stack[-4];
    goto v92;

v92:
    if (v56 == nil) goto v93;
    v56 = elt(env, 19); /* symbolic */
    goto v85;

v93:
    v56 = qvalue(elt(env, 27)); /* !*mode */
    goto v85;

v91:
    v56 = qvalue(elt(env, 8)); /* nil */
    goto v92;

v88:
    v56 = qvalue(elt(env, 6)); /* t */
    goto v92;

v89:
    v56 = v57;
    v58 = qcar(v56);
    v56 = elt(env, 24); /* intfn */
    v56 = Lflagp(nil, v58, v56);
    env = stack[-4];
    if (v56 == nil) goto v94;
    v56 = qvalue(elt(env, 6)); /* t */
    goto v90;

v94:
    v56 = v57;
    v58 = qcar(v56);
    v56 = elt(env, 25); /* list */
    v56 = (v58 == v56 ? lisp_true : nil);
    goto v90;

v87:
    v56 = qvalue(elt(env, 8)); /* nil */
    goto v92;

v86:
    v56 = qvalue(elt(env, 8)); /* nil */
    goto v92;

v82:
    v56 = stack[-1];
    fn = elt(env, 40); /* rprint */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v56 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    goto v77;

v80:
    v57 = qvalue(elt(env, 17)); /* cursym!* */
    v56 = elt(env, 18); /* end */
    v56 = (v57 == v56 ? lisp_true : nil);
    goto v81;

v78:
    v56 = qvalue(elt(env, 6)); /* t */
    goto v79;

v68:
    v56 = Lread(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    goto v69;

v66:
    v56 = qvalue(elt(env, 8)); /* nil */
    goto v67;

v63:
    v56 = qvalue(elt(env, 6)); /* t */
    goto v64;
/* error exit handlers */
v61:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-2]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-3]; /* errmsg!* */
    popv(5);
    return nil;
}



/* Code for dp_neg */

static Lisp_Object CC_dp_neg(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_neg");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v49 = v95;
/* end of prologue */
    stack[-4] = v49;
    v49 = stack[-4];
    if (v49 == nil) goto v103;
    v49 = stack[-4];
    v49 = qcar(v49);
    v50 = v49;
    v49 = v50;
    stack[0] = qcar(v49);
    v49 = v50;
    v49 = qcdr(v49);
    fn = elt(env, 2); /* bc_neg */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v49 = cons(stack[0], v49);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    stack[-2] = v49;
    stack[-3] = v49;
    goto v62;

v62:
    v49 = stack[-4];
    v49 = qcdr(v49);
    stack[-4] = v49;
    v49 = stack[-4];
    if (v49 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v49 = stack[-4];
    v49 = qcar(v49);
    v50 = v49;
    v49 = v50;
    stack[0] = qcar(v49);
    v49 = v50;
    v49 = qcdr(v49);
    fn = elt(env, 2); /* bc_neg */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v49 = cons(stack[0], v49);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v49 = Lrplacd(nil, stack[-1], v49);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v49 = stack[-2];
    v49 = qcdr(v49);
    stack[-2] = v49;
    goto v62;

v103:
    v49 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v49); }
/* error exit handlers */
v104:
    popv(6);
    return nil;
}



/* Code for simp!-prop!-order */

static Lisp_Object CC_simpKpropKorder(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97, v108, v109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-order");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v97 = v0;
    v108 = v95;
/* end of prologue */

v3:
    v96 = v108;
    if (v96 == nil) goto v65;
    v96 = v108;
    v96 = qcar(v96);
    v109 = qcar(v96);
    v96 = v97;
    v96 = qcar(v96);
    v96 = qcar(v96);
    if (equal(v109, v96)) goto v110;
    v96 = v108;
    v96 = qcar(v96);
    v97 = qcar(v96);
    v96 = elt(env, 2); /* prop!* */
    if (v97 == v96) goto v111;
    v96 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v96);

v111:
    v96 = qvalue(elt(env, 3)); /* t */
    return onevalue(v96);

v110:
    v96 = v108;
    v96 = qcdr(v96);
    v108 = v96;
    v96 = v97;
    v96 = qcdr(v96);
    v97 = v96;
    goto v3;

v65:
    v96 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v96);
}



/* Code for setqget */

static Lisp_Object MS_CDECL CC_setqget(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v111;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setqget");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setqget");
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
    v113 = qvalue(elt(env, 1)); /* fluidbibasissetq */
    v113 = qcar(v113);
    stack[-1] = v113;
    v113 = qvalue(elt(env, 1)); /* fluidbibasissetq */
    stack[0] = v113;
    v111 = stack[0];
    v113 = stack[0];
    v113 = qcdr(v113);
    v113 = qcar(v113);
    v111 = Lrplaca(nil, v111, v113);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v113 = stack[0];
    v113 = qcdr(v113);
    v113 = qcdr(v113);
    v113 = Lrplacd(nil, v111, v113);
    nil = C_nil;
    if (exception_pending()) goto v67;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v67:
    popv(3);
    return nil;
}



/* Code for mk!+mat!+mult!+mat */

static Lisp_Object CC_mkLmatLmultLmat(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v189, v190, v191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+mat+mult+mat");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
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
    stack[-13] = v0;
    stack[-14] = v95;
/* end of prologue */
    v189 = stack[-14];
    fn = elt(env, 7); /* matrix!+p */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    if (!(v189 == nil)) goto v60;
    v189 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v189 == nil)) goto v55;
    v189 = elt(env, 2); /* "no matrix in mult" */
    fn = elt(env, 8); /* lprie */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    goto v55;

v55:
    v189 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    goto v60;

v60:
    v189 = stack[-13];
    fn = elt(env, 7); /* matrix!+p */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    if (!(v189 == nil)) goto v193;
    v189 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v189 == nil)) goto v105;
    v189 = elt(env, 2); /* "no matrix in mult" */
    fn = elt(env, 8); /* lprie */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    goto v105;

v105:
    v189 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    goto v193;

v193:
    v189 = stack[-14];
    fn = elt(env, 9); /* get!+col!+nr */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-15] = v189;
    v189 = stack[-14];
    fn = elt(env, 10); /* get!+row!+nr */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-12] = v189;
    v189 = stack[-13];
    fn = elt(env, 9); /* get!+col!+nr */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-11] = v189;
    stack[0] = stack[-15];
    v189 = stack[-13];
    fn = elt(env, 10); /* get!+row!+nr */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    if (equal(stack[0], v189)) goto v69;
    v189 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v189 == nil)) goto v194;
    v189 = elt(env, 3); /* "matrices can not be multiplied" */
    fn = elt(env, 8); /* lprie */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    goto v194;

v194:
    v189 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    goto v69;

v69:
    v189 = (Lisp_Object)17; /* 1 */
    stack[-10] = v189;
    v190 = stack[-12];
    v189 = stack[-10];
    v189 = difference2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lminusp(nil, v189);
    env = stack[-16];
    if (v189 == nil) goto v76;
    v189 = qvalue(elt(env, 4)); /* nil */
    { popv(17); return onevalue(v189); }

v76:
    v189 = (Lisp_Object)17; /* 1 */
    stack[-5] = v189;
    v190 = stack[-11];
    v189 = stack[-5];
    v189 = difference2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lminusp(nil, v189);
    env = stack[-16];
    if (v189 == nil) goto v195;
    v189 = qvalue(elt(env, 4)); /* nil */
    goto v78;

v78:
    v189 = ncons(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-8] = v189;
    stack[-9] = v189;
    goto v47;

v47:
    v189 = stack[-10];
    v189 = add1(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-10] = v189;
    v190 = stack[-12];
    v189 = stack[-10];
    v189 = difference2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lminusp(nil, v189);
    env = stack[-16];
    if (!(v189 == nil)) { Lisp_Object res = stack[-9]; popv(17); return onevalue(res); }
    stack[-7] = stack[-8];
    v189 = (Lisp_Object)17; /* 1 */
    stack[-6] = v189;
    v190 = stack[-11];
    v189 = stack[-6];
    v189 = difference2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lminusp(nil, v189);
    env = stack[-16];
    if (v189 == nil) goto v74;
    v189 = qvalue(elt(env, 4)); /* nil */
    goto v196;

v196:
    v189 = ncons(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lrplacd(nil, stack[-7], v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = stack[-8];
    v189 = qcdr(v189);
    stack[-8] = v189;
    goto v47;

v74:
    v190 = qvalue(elt(env, 4)); /* nil */
    v189 = (Lisp_Object)17; /* 1 */
    v189 = cons(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[0] = v189;
    v189 = (Lisp_Object)17; /* 1 */
    stack[-1] = v189;
    goto v197;

v197:
    v190 = stack[-15];
    v189 = stack[-1];
    v189 = difference2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lminusp(nil, v189);
    env = stack[-16];
    if (v189 == nil) goto v198;
    v189 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v189; /* !*sub2 */
    v189 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-16];
    stack[0] = v189;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v189 = stack[0];
    v189 = ncons(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-4] = v189;
    stack[-5] = v189;
    goto v200;

v200:
    v189 = stack[-6];
    v189 = add1(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-6] = v189;
    v190 = stack[-11];
    v189 = stack[-6];
    v189 = difference2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lminusp(nil, v189);
    env = stack[-16];
    if (v189 == nil) goto v201;
    v189 = stack[-5];
    goto v196;

v201:
    stack[-3] = stack[-4];
    v190 = qvalue(elt(env, 4)); /* nil */
    v189 = (Lisp_Object)17; /* 1 */
    v189 = cons(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[0] = v189;
    v189 = (Lisp_Object)17; /* 1 */
    stack[-2] = v189;
    goto v202;

v202:
    v190 = stack[-15];
    v189 = stack[-2];
    v189 = difference2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lminusp(nil, v189);
    env = stack[-16];
    if (v189 == nil) goto v203;
    v189 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v189; /* !*sub2 */
    v189 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-16];
    stack[0] = v189;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v189 = stack[0];
    v189 = ncons(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lrplacd(nil, stack[-3], v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = stack[-4];
    v189 = qcdr(v189);
    stack[-4] = v189;
    goto v200;

v203:
    stack[-1] = stack[0];
    v191 = stack[-14];
    v190 = stack[-10];
    v189 = stack[-2];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v191, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v191 = stack[-13];
    v190 = stack[-2];
    v189 = stack[-6];
    fn = elt(env, 12); /* get!+mat!+entry */
    v189 = (*qfnn(fn))(qenv(fn), 3, v191, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v189 = (*qfn2(fn))(qenv(fn), stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v189 = (*qfn2(fn))(qenv(fn), stack[-1], v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[0] = v189;
    v189 = stack[-2];
    v189 = add1(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-2] = v189;
    goto v202;

v198:
    stack[-2] = stack[0];
    v191 = stack[-14];
    v190 = stack[-10];
    v189 = stack[-1];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v191, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v191 = stack[-13];
    v190 = stack[-1];
    v189 = stack[-6];
    fn = elt(env, 12); /* get!+mat!+entry */
    v189 = (*qfnn(fn))(qenv(fn), 3, v191, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v189 = (*qfn2(fn))(qenv(fn), stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v189 = (*qfn2(fn))(qenv(fn), stack[-2], v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[0] = v189;
    v189 = stack[-1];
    v189 = add1(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-1] = v189;
    goto v197;

v195:
    v190 = qvalue(elt(env, 4)); /* nil */
    v189 = (Lisp_Object)17; /* 1 */
    v189 = cons(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[0] = v189;
    v189 = (Lisp_Object)17; /* 1 */
    stack[-1] = v189;
    goto v205;

v205:
    v190 = stack[-15];
    v189 = stack[-1];
    v189 = difference2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lminusp(nil, v189);
    env = stack[-16];
    if (v189 == nil) goto v206;
    v189 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v189; /* !*sub2 */
    v189 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-16];
    stack[0] = v189;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v189 = stack[0];
    v189 = ncons(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-3] = v189;
    stack[-4] = v189;
    goto v208;

v208:
    v189 = stack[-5];
    v189 = add1(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-5] = v189;
    v190 = stack[-11];
    v189 = stack[-5];
    v189 = difference2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lminusp(nil, v189);
    env = stack[-16];
    if (v189 == nil) goto v209;
    v189 = stack[-4];
    goto v78;

v209:
    stack[-2] = stack[-3];
    v190 = qvalue(elt(env, 4)); /* nil */
    v189 = (Lisp_Object)17; /* 1 */
    v189 = cons(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[0] = v189;
    v189 = (Lisp_Object)17; /* 1 */
    stack[-1] = v189;
    goto v94;

v94:
    v190 = stack[-15];
    v189 = stack[-1];
    v189 = difference2(v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lminusp(nil, v189);
    env = stack[-16];
    if (v189 == nil) goto v210;
    v189 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v189; /* !*sub2 */
    v189 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v189 = (*qfn1(fn))(qenv(fn), v189);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-16];
    stack[0] = v189;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v189 = stack[0];
    v189 = ncons(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = Lrplacd(nil, stack[-2], v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v189 = stack[-3];
    v189 = qcdr(v189);
    stack[-3] = v189;
    goto v208;

v210:
    stack[-6] = stack[0];
    v191 = stack[-14];
    v190 = stack[-10];
    v189 = stack[-1];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v191, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v191 = stack[-13];
    v190 = stack[-1];
    v189 = stack[-5];
    fn = elt(env, 12); /* get!+mat!+entry */
    v189 = (*qfnn(fn))(qenv(fn), 3, v191, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v189 = (*qfn2(fn))(qenv(fn), stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v189 = (*qfn2(fn))(qenv(fn), stack[-6], v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[0] = v189;
    v189 = stack[-1];
    v189 = add1(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-1] = v189;
    goto v94;

v206:
    stack[-2] = stack[0];
    v191 = stack[-14];
    v190 = stack[-10];
    v189 = stack[-1];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v191, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    v191 = stack[-13];
    v190 = stack[-1];
    v189 = stack[-5];
    fn = elt(env, 12); /* get!+mat!+entry */
    v189 = (*qfnn(fn))(qenv(fn), 3, v191, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v189 = (*qfn2(fn))(qenv(fn), stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v189 = (*qfn2(fn))(qenv(fn), stack[-2], v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[0] = v189;
    v189 = stack[-1];
    v189 = add1(v189);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-16];
    stack[-1] = v189;
    goto v205;
/* error exit handlers */
v211:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v207:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v204:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v199:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v192:
    popv(17);
    return nil;
}



/* Code for ratpoly_lc */

static Lisp_Object CC_ratpoly_lc(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_lc");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v95;
/* end of prologue */
    v212 = stack[0];
    v212 = qcar(v212);
    fn = elt(env, 1); /* numpoly_lc */
    v60 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v213;
    v212 = stack[0];
    v212 = qcdr(v212);
    popv(1);
    return cons(v60, v212);
/* error exit handlers */
v213:
    popv(1);
    return nil;
}



/* Code for getsetvars */

static Lisp_Object CC_getsetvars(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getsetvars");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v95;
/* end of prologue */
    stack[-1] = nil;
    goto v3;

v3:
    v217 = stack[0];
    if (!consp(v217)) goto v65;
    v217 = stack[0];
    v104 = qcar(v217);
    v217 = elt(env, 1); /* (setel setk) */
    v217 = Lmemq(nil, v104, v217);
    if (v217 == nil) goto v218;
    v217 = stack[0];
    v217 = qcdr(v217);
    v217 = qcar(v217);
    fn = elt(env, 3); /* getsetvarlis */
    v104 = (*qfn1(fn))(qenv(fn), v217);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-2];
    v217 = stack[-1];
    v217 = cons(v104, v217);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-2];
    stack[-1] = v217;
    v217 = stack[0];
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcar(v217);
    stack[0] = v217;
    goto v3;

v218:
    v217 = stack[0];
    v104 = qcar(v217);
    v217 = elt(env, 2); /* setq */
    if (v104 == v217) goto v53;
    v217 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v217);
    }

v53:
    v217 = stack[0];
    v217 = qcdr(v217);
    v217 = qcar(v217);
    v104 = Lmkquote(nil, v217);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-2];
    v217 = stack[-1];
    v217 = cons(v104, v217);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-2];
    stack[-1] = v217;
    v217 = stack[0];
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcar(v217);
    stack[0] = v217;
    goto v3;

v65:
    v217 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v217);
    }
/* error exit handlers */
v219:
    popv(3);
    return nil;
}



/* Code for merge!-ind!-vars */

static Lisp_Object CC_mergeKindKvars(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for merge-ind-vars");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v95;
/* end of prologue */
    v215 = qvalue(elt(env, 1)); /* !*nocommutedf */
    if (!(v215 == nil)) goto v105;
    v215 = qvalue(elt(env, 2)); /* !*commutedf */
    if (v215 == nil) goto v223;
    v215 = qvalue(elt(env, 3)); /* nil */
    goto v103;

v103:
    if (!(v215 == nil)) goto v105;
    v188 = stack[0];
    v215 = stack[-1];
    v215 = qcdr(v215);
    v215 = qcdr(v215);
    {
        popv(4);
        fn = elt(env, 4); /* derad */
        return (*qfn2(fn))(qenv(fn), v188, v215);
    }

v105:
    v188 = stack[0];
    v215 = stack[-1];
    v215 = qcdr(v215);
    v215 = qcdr(v215);
    {
        popv(4);
        fn = elt(env, 5); /* derad!* */
        return (*qfn2(fn))(qenv(fn), v188, v215);
    }

v223:
    v215 = stack[-1];
    v215 = qcdr(v215);
    stack[-2] = qcar(v215);
    v188 = stack[0];
    v215 = stack[-1];
    v215 = qcdr(v215);
    v215 = qcdr(v215);
    v215 = cons(v188, v215);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-3];
    v215 = Lmemq(nil, stack[-2], v215);
    goto v103;
/* error exit handlers */
v68:
    popv(4);
    return nil;
}



/* Code for vdpsave */

static Lisp_Object CC_vdpsave(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object v16;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpsave");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v95;
/* end of prologue */
    return onevalue(v16);
}



/* Code for prinlatom */

static Lisp_Object CC_prinlatom(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prinlatom");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v95;
/* end of prologue */
    v225 = stack[-1];
    v104 = elt(env, 1); /* font */
    v104 = get(v225, v104);
    env = stack[-3];
    stack[-2] = v104;
    if (v104 == nil) goto v100;
    v104 = stack[-2];
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    goto v100;

v100:
    v225 = stack[-1];
    v104 = elt(env, 2); /* accent */
    v104 = get(v225, v104);
    env = stack[-3];
    stack[0] = v104;
    if (v104 == nil) goto v226;
    v104 = stack[0];
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    goto v226;

v226:
    v225 = stack[-1];
    v104 = elt(env, 3); /* name */
    v104 = get(v225, v104);
    env = stack[-3];
    v225 = v104;
    if (v104 == nil) goto v52;
    v104 = v225;
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    goto v227;

v227:
    v104 = stack[0];
    if (v104 == nil) goto v214;
    v104 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    goto v214;

v214:
    v104 = stack[-2];
    if (v104 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v104 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v157;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v52:
    v104 = stack[-1];
    fn = elt(env, 6); /* testchar1 */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    fn = elt(env, 5); /* prin2la */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    goto v227;
/* error exit handlers */
v157:
    popv(4);
    return nil;
}



/* Code for insertparens */

static Lisp_Object CC_insertparens(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insertparens");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v102 = v95;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !( */
    stack[0] = v102;
    v102 = elt(env, 2); /* !) */
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-2];
    v102 = Lappend(nil, stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v107;
    {
        Lisp_Object v55 = stack[-1];
        popv(3);
        return cons(v55, v102);
    }
/* error exit handlers */
v107:
    popv(3);
    return nil;
}



/* Code for deleteall */

static Lisp_Object CC_deleteall(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v106, v226, v218;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deleteall");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v95;
/* end of prologue */
    v226 = nil;
    goto v62;

v62:
    v105 = stack[0];
    if (v105 == nil) { popv(4); return onevalue(v226); }
    v105 = stack[0];
    v105 = qcar(v105);
    v218 = v105;
    v105 = stack[0];
    v105 = qcdr(v105);
    stack[0] = v105;
    v106 = v218;
    v105 = stack[-1];
    if (equal(v106, v105)) goto v62;
    stack[-2] = v226;
    v105 = v218;
    v105 = ncons(v105);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v105 = Lnconc(nil, stack[-2], v105);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v226 = v105;
    goto v62;
/* error exit handlers */
v97:
    popv(4);
    return nil;
}



/* Code for lesspcdr */

static Lisp_Object CC_lesspcdr(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v60;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lesspcdr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v212 = v0;
    v60 = v95;
/* end of prologue */
    v60 = qcdr(v60);
    v212 = qcdr(v212);
        return Llessp(nil, v60, v212);
}



/* Code for set!-global!-mode */

static Lisp_Object CC_setKglobalKmode(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-global-mode");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v95;
/* end of prologue */
    v100 = qvalue(elt(env, 1)); /* nil */
    v100 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    qvalue(elt(env, 2)) = v100; /* alglist!* */
    v100 = stack[-2];
    qvalue(elt(env, 3)) = v100; /* !*mode */
    stack[-3] = elt(env, 4); /* null */
    stack[-1] = elt(env, 5); /* setq */
    stack[0] = elt(env, 3); /* !*mode */
    v100 = stack[-2];
    v100 = Lmkquote(nil, v100);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v100 = list3(stack[-1], stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v51;
    {
        Lisp_Object v67 = stack[-3];
        popv(5);
        return list2(v67, v100);
    }
/* error exit handlers */
v51:
    popv(5);
    return nil;
}



/* Code for setk */

static Lisp_Object CC_setk(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v237, v238;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setk");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    v237 = v95;
/* end of prologue */
    v236 = v237;
    if (!consp(v236)) goto v43;
    v236 = v237;
    v238 = qcar(v236);
    v236 = elt(env, 1); /* evalargfn */
    v236 = get(v238, v236);
    env = stack[-2];
    v238 = v236;
    v236 = v238;
    if (v236 == nil) goto v214;
    v236 = v237;
    stack[-1] = qcar(v236);
    v236 = v238;
    v237 = qcdr(v237);
    v236 = Lapply1(nil, v236, v237);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-2];
    v237 = cons(stack[-1], v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-2];
    v236 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v237, v236);
    }

v214:
    v236 = v237;
    v238 = qcar(v236);
    v236 = elt(env, 2); /* rtype */
    v238 = get(v238, v236);
    env = stack[-2];
    v236 = elt(env, 3); /* matrix */
    if (v238 == v236) goto v240;
    v236 = v237;
    stack[-1] = qcar(v236);
    v236 = v237;
    v236 = qcdr(v236);
    fn = elt(env, 5); /* revlis */
    v236 = (*qfn1(fn))(qenv(fn), v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-2];
    v237 = cons(stack[-1], v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-2];
    v236 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v237, v236);
    }

v240:
    v236 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v237, v236);
    }

v43:
    v236 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v237, v236);
    }
/* error exit handlers */
v239:
    popv(3);
    return nil;
}



/* Code for sf_member */

static Lisp_Object CC_sf_member(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf_member");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v95;
/* end of prologue */

v243:
    v242 = stack[0];
    if (!consp(v242)) goto v70;
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = (consp(v242) ? nil : lisp_true);
    goto v65;

v65:
    if (v242 == nil) goto v244;
    v242 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v242); }

v244:
    v231 = stack[-1];
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v242 = qcar(v242);
    if (equal(v231, v242)) goto v64;
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v242 = qcar(v242);
    if (!consp(v242)) goto v220;
    v231 = stack[-1];
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v242 = qcar(v242);
    v242 = qcdr(v242);
    fn = elt(env, 3); /* arglist_member */
    v242 = (*qfn2(fn))(qenv(fn), v231, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-2];
    goto v55;

v55:
    if (!(v242 == nil)) { popv(3); return onevalue(v242); }
    v231 = stack[-1];
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = qcdr(v242);
    v242 = CC_sf_member(env, v231, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-2];
    if (!(v242 == nil)) { popv(3); return onevalue(v242); }
    v231 = stack[-1];
    v242 = stack[0];
    v242 = qcdr(v242);
    stack[-1] = v231;
    stack[0] = v242;
    goto v243;

v220:
    v242 = qvalue(elt(env, 2)); /* nil */
    goto v55;

v64:
    v242 = qvalue(elt(env, 1)); /* t */
    goto v55;

v70:
    v242 = qvalue(elt(env, 1)); /* t */
    goto v65;
/* error exit handlers */
v245:
    popv(3);
    return nil;
}



/* Code for dl_get2 */

static Lisp_Object CC_dl_get2(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v96, v97, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dl_get2");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v96 = v0;
    v97 = v95;
/* end of prologue */

v2:
    v221 = v97;
    if (v221 == nil) { popv(2); return onevalue(v96); }
    v221 = v97;
    v108 = qcar(v221);
    v221 = elt(env, 1); /* dummy */
    v221 = get(v108, v221);
    env = stack[-1];
    if (v221 == nil) goto v106;
    v221 = v97;
    v221 = qcdr(v221);
    stack[0] = v221;
    v221 = v97;
    v97 = qcar(v221);
    v221 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 3); /* di_insert */
    v221 = (*qfnn(fn))(qenv(fn), 3, v97, v96, v221);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    v96 = v221;
    v221 = stack[0];
    v97 = v221;
    goto v2;

v106:
    v221 = v97;
    v221 = qcdr(v221);
    v97 = v221;
    goto v2;
/* error exit handlers */
v54:
    popv(2);
    return nil;
}



/* Code for ilcm */

static Lisp_Object CC_ilcm(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v155, v247, v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ilcm");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v247 = v0;
    v46 = v95;
/* end of prologue */
    v155 = v46;
    v157 = (Lisp_Object)1; /* 0 */
    if (v155 == v157) goto v70;
    v155 = v247;
    v157 = (Lisp_Object)1; /* 0 */
    v157 = (v155 == v157 ? lisp_true : nil);
    goto v65;

v65:
    if (v157 == nil) goto v67;
    v157 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v157); }

v67:
    v155 = v46;
    v157 = (Lisp_Object)17; /* 1 */
    if (v155 == v157) { popv(3); return onevalue(v247); }
    v155 = v247;
    v157 = (Lisp_Object)17; /* 1 */
    if (v155 == v157) { popv(3); return onevalue(v46); }
    stack[-1] = v46;
    stack[0] = v247;
    v157 = v46;
    v155 = v247;
    v157 = Lgcd(nil, v157, v155);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-2];
    v157 = quot2(stack[0], v157);
    nil = C_nil;
    if (exception_pending()) goto v230;
    {
        Lisp_Object v76 = stack[-1];
        popv(3);
        return times2(v76, v157);
    }

v70:
    v157 = qvalue(elt(env, 1)); /* t */
    goto v65;
/* error exit handlers */
v230:
    popv(3);
    return nil;
}



/* Code for reverse!-num */

static Lisp_Object CC_reverseKnum(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reverse-num");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v95;
/* end of prologue */
    v53 = stack[0];
    v52 = (Lisp_Object)1; /* 0 */
    if (v53 == v52) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v53 = stack[0];
    v52 = (Lisp_Object)1; /* 0 */
    v52 = (Lisp_Object)lessp2(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v248;
    v52 = v52 ? lisp_true : nil;
    env = stack[-2];
    if (v52 == nil) goto v226;
    v52 = stack[0];
    stack[-1] = negate(v52);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    v52 = stack[0];
    v52 = negate(v52);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    fn = elt(env, 1); /* ilog2 */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    v52 = add1(v52);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    fn = elt(env, 2); /* reverse!-num1 */
    v52 = (*qfn2(fn))(qenv(fn), stack[-1], v52);
    nil = C_nil;
    if (exception_pending()) goto v248;
    popv(3);
    return negate(v52);

v226:
    stack[-1] = stack[0];
    v52 = stack[0];
    fn = elt(env, 1); /* ilog2 */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    v52 = add1(v52);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    {
        Lisp_Object v234 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* reverse!-num1 */
        return (*qfn2(fn))(qenv(fn), v234, v52);
    }
/* error exit handlers */
v248:
    popv(3);
    return nil;
}



/* Code for ibalp_initwl */

static Lisp_Object CC_ibalp_initwl(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v261, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_initwl");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v261 = v95;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = v261;
    goto v222;

v222:
    v261 = stack[-2];
    if (v261 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v261 = stack[-2];
    v261 = qcar(v261);
    stack[-1] = v261;
    v261 = (Lisp_Object)1; /* 0 */
    stack[-5] = v261;
    v261 = stack[-1];
    v261 = qcar(v261);
    stack[-3] = v261;
    goto v227;

v227:
    v21 = stack[-5];
    v261 = (Lisp_Object)33; /* 2 */
    v261 = Leqn(nil, v21, v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    if (v261 == nil) goto v66;
    v261 = qvalue(elt(env, 1)); /* nil */
    goto v67;

v67:
    if (v261 == nil) goto v244;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    stack[0] = qcdr(v261);
    v261 = stack[-3];
    v21 = qcar(v261);
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v261 = cons(v21, v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v261 = (*qfn2(fn))(qenv(fn), stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    v261 = stack[-3];
    v261 = qcar(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    stack[0] = qcdr(v261);
    v21 = stack[-1];
    v261 = stack[-3];
    v261 = qcar(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v261 = cons(v21, v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v261 = (*qfn2(fn))(qenv(fn), stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    v261 = stack[-5];
    v261 = add1(v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    stack[-5] = v261;
    v261 = stack[-3];
    v261 = qcdr(v261);
    stack[-3] = v261;
    goto v227;

v244:
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcar(v261);
    stack[-3] = v261;
    goto v263;

v263:
    v21 = stack[-5];
    v261 = (Lisp_Object)33; /* 2 */
    v261 = Leqn(nil, v21, v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    if (v261 == nil) goto v264;
    v261 = qvalue(elt(env, 1)); /* nil */
    goto v42;

v42:
    if (v261 == nil) goto v265;
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    stack[0] = qcdr(v261);
    v261 = stack[-3];
    v21 = qcar(v261);
    v261 = stack[-1];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v261 = cons(v21, v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v261 = (*qfn2(fn))(qenv(fn), stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    v261 = stack[-3];
    v261 = qcar(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    stack[0] = qcdr(v261);
    v21 = stack[-1];
    v261 = stack[-3];
    v261 = qcar(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v261 = cons(v21, v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v261 = (*qfn2(fn))(qenv(fn), stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    v261 = stack[-5];
    v261 = add1(v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    stack[-5] = v261;
    v261 = stack[-3];
    v261 = qcdr(v261);
    stack[-3] = v261;
    goto v263;

v265:
    v21 = stack[-5];
    v261 = (Lisp_Object)33; /* 2 */
    v261 = (Lisp_Object)lessp2(v21, v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    v261 = v261 ? lisp_true : nil;
    env = stack[-6];
    if (v261 == nil) goto v89;
    v21 = stack[-1];
    v261 = stack[-4];
    v261 = cons(v21, v261);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-6];
    stack[-4] = v261;
    goto v89;

v89:
    v261 = stack[-2];
    v261 = qcdr(v261);
    stack[-2] = v261;
    goto v222;

v264:
    v261 = stack[-3];
    goto v42;

v66:
    v261 = stack[-3];
    goto v67;
/* error exit handlers */
v262:
    popv(7);
    return nil;
}



/* Code for poly!-minusp */

static Lisp_Object CC_polyKminusp(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v67;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v51 = v95;
/* end of prologue */

v17:
    v67 = v51;
    if (v67 == nil) goto v62;
    v67 = v51;
    if (!consp(v67)) goto v223;
    v67 = v51;
    v67 = qcar(v67);
    v67 = (consp(v67) ? nil : lisp_true);
    goto v60;

v60:
    if (v67 == nil) goto v100;
        return Lminusp(nil, v51);

v100:
    v51 = qcar(v51);
    v51 = qcdr(v51);
    goto v17;

v223:
    v67 = qvalue(elt(env, 2)); /* t */
    goto v60;

v62:
    v51 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v51);
}



/* Code for ofsf_sacat */

static Lisp_Object MS_CDECL CC_ofsf_sacat(Lisp_Object env, int nargs,
                         Lisp_Object v95, Lisp_Object v0,
                         Lisp_Object v1, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50, v68, v246;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_sacat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacat");
#endif
    if (stack >= stacklimit)
    {
        push3(v1,v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v95,v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v68 = v1;
    v246 = v0;
    stack[0] = v95;
/* end of prologue */
    v49 = stack[0];
    v49 = qcdr(v49);
    v50 = qcar(v49);
    v49 = v246;
    v49 = qcdr(v49);
    v49 = qcar(v49);
    if (equal(v50, v49)) goto v63;
    v49 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v49); }

v63:
    v49 = stack[0];
    v49 = qcar(v49);
    v50 = v246;
    v50 = qcar(v50);
    fn = elt(env, 3); /* ofsf_sacrel */
    v49 = (*qfnn(fn))(qenv(fn), 3, v49, v50, v68);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-1];
    v68 = v49;
    v50 = v68;
    v49 = elt(env, 2); /* (drop keep keep1 keep2) */
    v49 = Lmemq(nil, v50, v49);
    if (!(v49 == nil)) { popv(2); return onevalue(v68); }
    v50 = v68;
    v49 = stack[0];
    v49 = qcdr(v49);
    v49 = qcar(v49);
    v68 = qvalue(elt(env, 1)); /* nil */
    popv(2);
    return list3(v50, v49, v68);
/* error exit handlers */
v240:
    popv(2);
    return nil;
}



/* Code for ir2om */

static Lisp_Object CC_ir2om(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ir2om");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v95;
/* end of prologue */
    v213 = (Lisp_Object)33; /* 2 */
    qvalue(elt(env, 1)) = v213; /* ind */
    v213 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = v213; /* indent */
    v213 = elt(env, 3); /* "<OMOBJ>" */
    fn = elt(env, 7); /* printout */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v213 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* indent!* */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v213 = stack[0];
    fn = elt(env, 9); /* objectom */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v213 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v213 = elt(env, 6); /* "</OMOBJ>" */
    fn = elt(env, 7); /* printout */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v102;
    v213 = nil;
    { popv(2); return onevalue(v213); }
/* error exit handlers */
v102:
    popv(2);
    return nil;
}



/* Code for cr!:minusp */

static Lisp_Object CC_crTminusp(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v234, v214;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:minusp");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v248 = v95;
/* end of prologue */
    v234 = v248;
    v234 = qcdr(v234);
    v234 = qcar(v234);
    v248 = qcdr(v248);
    v248 = qcdr(v248);
    v214 = v234;
    v234 = v248;
    v248 = v214;
    if (!consp(v248)) goto v110;
    v248 = v234;
    v248 = qcar(v248);
    v248 = (Lisp_Object)zerop(v248);
    v248 = v248 ? lisp_true : nil;
    env = stack[0];
    if (v248 == nil) goto v227;
    v248 = v214;
    v234 = qcar(v248);
    v248 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v234, v248);

v227:
    v248 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v248); }

v110:
    v248 = v234;
    v248 = (Lisp_Object)zerop(v248);
    v248 = v248 ? lisp_true : nil;
    env = stack[0];
    if (v248 == nil) goto v224;
    v234 = v214;
    v248 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v234, v248);

v224:
    v248 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v248); }
}



/* Code for xord_deglex */

static Lisp_Object CC_xord_deglex(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v246, v194, v240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_deglex");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v95;
/* end of prologue */
    v68 = stack[-1];
    v246 = qcar(v68);
    v68 = (Lisp_Object)17; /* 1 */
    if (v246 == v68) goto v3;
    v68 = stack[0];
    v246 = qcar(v68);
    v68 = (Lisp_Object)17; /* 1 */
    if (v246 == v68) goto v213;
    v68 = stack[-1];
    fn = elt(env, 3); /* xdegreemon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    v68 = stack[0];
    fn = elt(env, 3); /* xdegreemon */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-3];
    v240 = stack[-2];
    v194 = v68;
    v246 = v240;
    v68 = v194;
    if (equal(v246, v68)) goto v109;
    v68 = v240;
    v246 = v194;
        popv(4);
        return Lgreaterp(nil, v68, v246);

v109:
    v246 = stack[-1];
    v68 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v246, v68);
    }

v213:
    v68 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v68); }

v3:
    v68 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v68); }
/* error exit handlers */
v233:
    popv(4);
    return nil;
}



/* Code for fortranname */

static Lisp_Object CC_fortranname(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortranname");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v95;
/* end of prologue */
    v104 = stack[0];
    v104 = Lstringp(nil, v104);
    env = stack[-1];
    if (v104 == nil) goto v213;
    v104 = stack[0];
    {
        popv(2);
        fn = elt(env, 9); /* stringtoatom */
        return (*qfn1(fn))(qenv(fn), v104);
    }

v213:
    v225 = stack[0];
    v104 = qvalue(elt(env, 1)); /* !*notfortranfuns!* */
    v104 = Lmemq(nil, v225, v104);
    if (v104 == nil) goto v212;
    v104 = qvalue(elt(env, 2)); /* !*stdout!* */
    v104 = qcdr(v104);
    v104 = Lwrs(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-1];
    v104 = elt(env, 3); /* "*** WARNING: " */
    v104 = Lprinc(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-1];
    v104 = stack[0];
    v104 = Lprin(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-1];
    v104 = elt(env, 4); /* " is not an intrinsic Fortran function" */
    v104 = Lprinc(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-1];
    v104 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-1];
    goto v212;

v212:
    v104 = qvalue(elt(env, 6)); /* !*double */
    if (v104 == nil) goto v187;
    v225 = stack[0];
    v104 = elt(env, 7); /* !*doublename!* */
    v104 = get(v225, v104);
    if (v104 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v104); }

v187:
    v225 = stack[0];
    v104 = elt(env, 8); /* !*fortranname!* */
    v104 = get(v225, v104);
    if (v104 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v104); }
/* error exit handlers */
v219:
    popv(2);
    return nil;
}



/* Code for physop2sq */

static Lisp_Object CC_physop2sq(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v273, v274, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physop2sq");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v95;
/* end of prologue */

v243:
    v273 = stack[0];
    fn = elt(env, 5); /* physopp */
    v273 = (*qfn1(fn))(qenv(fn), v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    if (v273 == nil) goto v65;
    v274 = stack[0];
    v273 = elt(env, 1); /* rvalue */
    v273 = get(v274, v273);
    env = stack[-2];
    stack[-1] = v273;
    if (v273 == nil) goto v60;
    v273 = stack[-1];
    stack[0] = v273;
    goto v243;

v60:
    v273 = stack[0];
    if (symbolp(v273)) goto v227;
    v273 = stack[0];
    v274 = qcar(v273);
    v273 = elt(env, 2); /* psimpfn */
    v273 = get(v274, v273);
    env = stack[-2];
    stack[-1] = v273;
    if (v273 == nil) goto v208;
    v274 = stack[-1];
    v273 = stack[0];
    v273 = Lapply1(nil, v274, v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    stack[-1] = v273;
    fn = elt(env, 5); /* physopp */
    v273 = (*qfn1(fn))(qenv(fn), v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    if (v273 == nil) goto v245;
    v180 = stack[-1];
    v274 = (Lisp_Object)17; /* 1 */
    v273 = (Lisp_Object)17; /* 1 */
    v273 = acons(v180, v274, v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v274 = ncons(v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v273 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v274, v273);

v245:
    v273 = stack[-1];
    fn = elt(env, 6); /* physopsm!* */
    v273 = (*qfn1(fn))(qenv(fn), v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v273 = qcdr(v273);
    v273 = qcar(v273);
    { popv(3); return onevalue(v273); }

v208:
    v273 = stack[0];
    v274 = qcar(v273);
    v273 = elt(env, 3); /* opmtch */
    v273 = get(v274, v273);
    env = stack[-2];
    if (v273 == nil) goto v183;
    v273 = stack[0];
    fn = elt(env, 7); /* opmtch!* */
    v273 = (*qfn1(fn))(qenv(fn), v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    stack[-1] = v273;
    if (v273 == nil) goto v183;
    v273 = stack[-1];
    stack[0] = v273;
    goto v243;

v183:
    v180 = stack[0];
    v274 = (Lisp_Object)17; /* 1 */
    v273 = (Lisp_Object)17; /* 1 */
    v273 = acons(v180, v274, v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v274 = ncons(v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v273 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v274, v273);

v227:
    v180 = stack[0];
    v274 = (Lisp_Object)17; /* 1 */
    v273 = (Lisp_Object)17; /* 1 */
    v273 = acons(v180, v274, v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v274 = ncons(v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v273 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v274, v273);

v65:
    v273 = stack[0];
    if (!consp(v273)) goto v263;
    v273 = stack[0];
    v274 = qcar(v273);
    v273 = elt(env, 4); /* !*sq */
    if (v274 == v273) goto v257;
    v273 = stack[0];
    fn = elt(env, 8); /* getphystype */
    v273 = (*qfn1(fn))(qenv(fn), v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    if (v273 == nil) goto v275;
    v273 = stack[0];
    fn = elt(env, 6); /* physopsm!* */
    v273 = (*qfn1(fn))(qenv(fn), v273);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    stack[0] = v273;
    goto v243;

v275:
    v273 = stack[0];
    {
        popv(3);
        fn = elt(env, 9); /* simp */
        return (*qfn1(fn))(qenv(fn), v273);
    }

v257:
    v273 = stack[0];
    v273 = qcdr(v273);
    v273 = qcar(v273);
    { popv(3); return onevalue(v273); }

v263:
    v273 = stack[0];
    {
        popv(3);
        fn = elt(env, 9); /* simp */
        return (*qfn1(fn))(qenv(fn), v273);
    }
/* error exit handlers */
v37:
    popv(3);
    return nil;
}



/* Code for sf2mv1 */

static Lisp_Object MS_CDECL CC_sf2mv1(Lisp_Object env, int nargs,
                         Lisp_Object v95, Lisp_Object v0,
                         Lisp_Object v1, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v185, v278;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sf2mv1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2mv1");
#endif
    if (stack >= stacklimit)
    {
        push3(v1,v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v95,v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v1;
    stack[-2] = v0;
    stack[-3] = v95;
/* end of prologue */

v2:
    v184 = stack[-3];
    if (v184 == nil) goto v70;
    v184 = stack[-3];
    if (!consp(v184)) goto v224;
    v184 = stack[-3];
    v184 = qcar(v184);
    v184 = (consp(v184) ? nil : lisp_true);
    goto v213;

v213:
    if (v184 == nil) goto v108;
    stack[0] = stack[-2];
    v184 = stack[-1];
    v184 = Llength(nil, v184);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    fn = elt(env, 3); /* nzeros */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    v185 = Lappend(nil, stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    v184 = stack[-3];
    v184 = cons(v185, v184);
    nil = C_nil;
    if (exception_pending()) goto v269;
    popv(6);
    return ncons(v184);

v108:
    v184 = stack[-3];
    v184 = qcar(v184);
    v184 = qcar(v184);
    v185 = qcar(v184);
    v184 = stack[-1];
    v184 = qcar(v184);
    if (equal(v185, v184)) goto v68;
    stack[0] = stack[-2];
    v184 = (Lisp_Object)1; /* 0 */
    v184 = ncons(v184);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    v184 = Lappend(nil, stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    stack[-2] = v184;
    v184 = stack[-1];
    v184 = qcdr(v184);
    stack[-1] = v184;
    goto v2;

v68:
    v184 = stack[-3];
    v184 = qcar(v184);
    stack[-4] = qcdr(v184);
    stack[0] = stack[-2];
    v184 = stack[-3];
    v184 = qcar(v184);
    v184 = qcar(v184);
    v184 = qcdr(v184);
    v184 = ncons(v184);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    v185 = Lappend(nil, stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    v184 = stack[-1];
    v184 = qcdr(v184);
    stack[0] = CC_sf2mv1(env, 3, stack[-4], v185, v184);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    v184 = stack[-3];
    v278 = qcdr(v184);
    v185 = stack[-2];
    v184 = stack[-1];
    v184 = CC_sf2mv1(env, 3, v278, v185, v184);
    nil = C_nil;
    if (exception_pending()) goto v269;
    {
        Lisp_Object v279 = stack[0];
        popv(6);
        return Lappend(nil, v279, v184);
    }

v224:
    v184 = qvalue(elt(env, 2)); /* t */
    goto v213;

v70:
    v184 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v184); }
/* error exit handlers */
v269:
    popv(6);
    return nil;
}



/* Code for rnminusp!: */

static Lisp_Object CC_rnminuspT(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v228, v227, v235;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnminusp:");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v227 = v95;
/* end of prologue */
    v228 = v227;
    v228 = qcdr(v228);
    v228 = qcar(v228);
    v227 = v228;
    if (!consp(v228)) goto v110;
    v228 = v227;
    v235 = qcar(v228);
    v228 = elt(env, 1); /* minusp */
    v228 = get(v235, v228);
        return Lapply1(nil, v228, v227);

v110:
    v228 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v227, v228);
}



/* Code for di_restore */

static Lisp_Object CC_di_restore(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v222, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for di_restore");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v222 = v95;
/* end of prologue */
    v103 = v222;
    v222 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* di_restore1 */
        return (*qfn2(fn))(qenv(fn), v103, v222);
    }
}



/* Code for resimpf */

static Lisp_Object CC_resimpf(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimpf");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v60 = v95;
/* end of prologue */
    v212 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v212; /* varstack!* */
    v212 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* subf1 */
    v212 = (*qfn2(fn))(qenv(fn), v60, v212);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-1];
    v212 = qcar(v212);
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v212); }
/* error exit handlers */
v213:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for numeric!-content */

static Lisp_Object CC_numericKcontent(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v225, v233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numeric-content");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v95;
/* end of prologue */

v17:
    v104 = stack[0];
    if (!consp(v104)) goto v103;
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = (consp(v104) ? nil : lisp_true);
    goto v222;

v222:
    if (v104 == nil) goto v65;
    v104 = stack[0];
    fn = elt(env, 2); /* minusf */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    if (v104 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v104 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* negf */
        return (*qfn1(fn))(qenv(fn), v104);
    }

v65:
    v104 = stack[0];
    v104 = qcdr(v104);
    if (v104 == nil) goto v51;
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = qcdr(v104);
    v104 = CC_numericKcontent(env, v104);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    v233 = v104;
    v225 = v233;
    v104 = (Lisp_Object)17; /* 1 */
    if (v225 == v104) { popv(3); return onevalue(v233); }
    stack[-1] = v233;
    v104 = stack[0];
    v104 = qcdr(v104);
    v104 = CC_numericKcontent(env, v104);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    fn = elt(env, 4); /* gcddd */
    v104 = (*qfn2(fn))(qenv(fn), stack[-1], v104);
    nil = C_nil;
    if (exception_pending()) goto v157;
    v233 = v104;
    { popv(3); return onevalue(v233); }

v51:
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = qcdr(v104);
    stack[0] = v104;
    goto v17;

v103:
    v104 = qvalue(elt(env, 1)); /* t */
    goto v222;
/* error exit handlers */
v157:
    popv(3);
    return nil;
}



/* Code for cl_identifyat */

static Lisp_Object CC_cl_identifyat(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v98;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_identifyat");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v95;
/* end of prologue */
    v98 = stack[0];
    v214 = elt(env, 1); /* true */
    if (v98 == v214) goto v103;
    v98 = stack[0];
    v214 = elt(env, 3); /* false */
    v214 = (v98 == v214 ? lisp_true : nil);
    goto v222;

v222:
    if (!(v214 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v98 = stack[0];
    v214 = qvalue(elt(env, 4)); /* cl_identify!-atl!* */
    v214 = Lmember(nil, v98, v214);
    v98 = v214;
    if (v214 == nil) goto v109;
    v214 = v98;
    v214 = qcar(v214);
    { popv(2); return onevalue(v214); }

v109:
    v98 = stack[0];
    v214 = qvalue(elt(env, 4)); /* cl_identify!-atl!* */
    v214 = cons(v98, v214);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-1];
    qvalue(elt(env, 4)) = v214; /* cl_identify!-atl!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v103:
    v214 = qvalue(elt(env, 2)); /* t */
    goto v222;
/* error exit handlers */
v220:
    popv(2);
    return nil;
}



/* Code for evaluatecoeffts */

static Lisp_Object CC_evaluatecoeffts(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v269, v279, v183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluatecoeffts");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v95;
/* end of prologue */
    v269 = stack[-1];
    if (v269 == nil) goto v70;
    v269 = stack[-1];
    if (!consp(v269)) goto v224;
    v269 = stack[-1];
    v269 = qcar(v269);
    v269 = (consp(v269) ? nil : lisp_true);
    goto v65;

v65:
    if (v269 == nil) goto v53;
    v279 = stack[-1];
    v269 = (Lisp_Object)1; /* 0 */
    if (!(v279 == v269)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v269 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v269); }

v53:
    v269 = stack[-1];
    v269 = qcar(v269);
    v269 = qcar(v269);
    v279 = qcar(v269);
    v269 = qvalue(elt(env, 3)); /* indexlist */
    v269 = Lmember(nil, v279, v269);
    if (v269 == nil) goto v281;
    v269 = stack[-1];
    v269 = qcar(v269);
    v269 = qcar(v269);
    v183 = qcar(v269);
    v279 = stack[0];
    v269 = qvalue(elt(env, 3)); /* indexlist */
    fn = elt(env, 4); /* valuecoefft */
    v269 = (*qfnn(fn))(qenv(fn), 3, v183, v279, v269);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-3];
    goto v272;

v272:
    stack[-2] = v269;
    v269 = stack[-1];
    v269 = qcar(v269);
    v279 = qcdr(v269);
    v269 = stack[0];
    v269 = CC_evaluatecoeffts(env, v279, v269);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-3];
    fn = elt(env, 5); /* !*multf */
    v269 = (*qfn2(fn))(qenv(fn), stack[-2], v269);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-3];
    stack[-2] = v269;
    v269 = stack[-1];
    v279 = qcdr(v269);
    v269 = stack[0];
    v269 = CC_evaluatecoeffts(env, v279, v269);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-3];
    {
        Lisp_Object v283 = stack[-2];
        popv(4);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v283, v269);
    }

v281:
    v269 = stack[-1];
    v269 = qcar(v269);
    v279 = qcar(v269);
    v269 = (Lisp_Object)17; /* 1 */
    v269 = cons(v279, v269);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-3];
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-3];
    goto v272;

v224:
    v269 = qvalue(elt(env, 1)); /* t */
    goto v65;

v70:
    v269 = qvalue(elt(env, 1)); /* t */
    goto v65;
/* error exit handlers */
v282:
    popv(4);
    return nil;
}



/* Code for ibalp_readclause */

static Lisp_Object CC_ibalp_readclause(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v164, v165, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_readclause");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0;
    v166 = v95;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v166 = qcdr(v166);
    stack[-4] = v166;
    stack[-5] = qvalue(elt(env, 1)); /* nil */
    stack[-1] = qvalue(elt(env, 1)); /* nil */
    stack[0] = (Lisp_Object)1; /* 0 */
    v160 = (Lisp_Object)1; /* 0 */
    v165 = qvalue(elt(env, 1)); /* nil */
    v164 = qvalue(elt(env, 1)); /* nil */
    v166 = qvalue(elt(env, 1)); /* nil */
    v166 = list4(v160, v165, v164, v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    v166 = list3star(stack[-5], stack[-1], stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    stack[-5] = v166;
    v166 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v166;
    goto v97;

v97:
    v166 = stack[-1];
    if (v166 == nil) goto v96;
    v166 = stack[-4];
    if (v166 == nil) goto v96;
    v166 = stack[-4];
    v166 = qcar(v166);
    stack[-8] = v166;
    v164 = stack[-8];
    v166 = elt(env, 3); /* true */
    if (v164 == v166) goto v215;
    v166 = stack[-4];
    v166 = qcdr(v166);
    stack[-4] = v166;
    v164 = stack[-8];
    v166 = elt(env, 4); /* false */
    if (v164 == v166) goto v97;
    v166 = stack[-8];
    if (!consp(v166)) goto v163;
    v166 = stack[-8];
    v166 = qcar(v166);
    v164 = v166;
    goto v245;

v245:
    v166 = elt(env, 5); /* not */
    if (v164 == v166) goto v242;
    v166 = stack[-8];
    fn = elt(env, 6); /* ibalp_arg2l */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    stack[-6] = v166;
    v166 = stack[-8];
    fn = elt(env, 7); /* ibalp_arg2r */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    goto v42;

v42:
    v164 = v166;
    v166 = (Lisp_Object)17; /* 1 */
    v166 = Leqn(nil, v164, v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    if (v166 == nil) goto v88;
    v164 = stack[-6];
    v166 = stack[-3];
    v166 = Lmemq(nil, v164, v166);
    if (!(v166 == nil)) goto v97;
    v166 = stack[-5];
    v166 = qcdr(v166);
    stack[0] = qcdr(v166);
    v166 = stack[-5];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    v166 = add1(v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    fn = elt(env, 8); /* setcar */
    v166 = (*qfn2(fn))(qenv(fn), stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    v164 = stack[-6];
    v166 = stack[-3];
    v166 = cons(v164, v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    stack[-3] = v166;
    v160 = stack[-5];
    v165 = stack[-7];
    v164 = stack[-6];
    v166 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 9); /* ibalp_process!-var */
    v166 = (*qfnn(fn))(qenv(fn), 4, v160, v165, v164, v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    stack[-7] = v166;
    goto v97;

v88:
    v164 = stack[-6];
    v166 = stack[-2];
    v166 = Lmemq(nil, v164, v166);
    if (!(v166 == nil)) goto v97;
    v166 = stack[-5];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    stack[0] = qcdr(v166);
    v166 = stack[-5];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    v166 = add1(v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    fn = elt(env, 8); /* setcar */
    v166 = (*qfn2(fn))(qenv(fn), stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    v164 = stack[-6];
    v166 = stack[-2];
    v166 = cons(v164, v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    stack[-2] = v166;
    v160 = stack[-5];
    v165 = stack[-7];
    v164 = stack[-6];
    v166 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 9); /* ibalp_process!-var */
    v166 = (*qfnn(fn))(qenv(fn), 4, v160, v165, v164, v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    stack[-7] = v166;
    goto v97;

v242:
    v166 = stack[-8];
    v166 = qcdr(v166);
    v166 = qcar(v166);
    fn = elt(env, 6); /* ibalp_arg2l */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    stack[-6] = v166;
    stack[0] = (Lisp_Object)17; /* 1 */
    v166 = stack[-8];
    v166 = qcdr(v166);
    v166 = qcar(v166);
    fn = elt(env, 7); /* ibalp_arg2r */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-9];
    v166 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v166 + TAG_FIXNUM);
    goto v42;

v163:
    v166 = stack[-8];
    v164 = v166;
    goto v245;

v215:
    v166 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v166;
    goto v97;

v96:
    v166 = stack[-1];
    if (v166 == nil) goto v91;
    v164 = stack[-5];
    v166 = stack[-7];
    popv(10);
    return cons(v164, v166);

v91:
    v164 = elt(env, 3); /* true */
    v166 = stack[-7];
    popv(10);
    return cons(v164, v166);
/* error exit handlers */
v86:
    popv(10);
    return nil;
}



/* Code for ratpoly_1 */

static Lisp_Object MS_CDECL CC_ratpoly_1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ratpoly_1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_1");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v16 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 1); /* simp */
        return (*qfn1(fn))(qenv(fn), v16);
    }
}



/* Code for mapins */

static Lisp_Object CC_mapins(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v226, v218, v260;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapins");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v95;
/* end of prologue */
    stack[-2] = nil;
    goto v2;

v2:
    v226 = stack[0];
    if (v226 == nil) goto v70;
    v218 = stack[-1];
    v226 = stack[0];
    v226 = qcar(v226);
    v226 = qcar(v226);
    v260 = cons(v218, v226);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    v226 = stack[0];
    v226 = qcar(v226);
    v218 = qcdr(v226);
    v226 = stack[-2];
    v226 = acons(v260, v218, v226);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    stack[-2] = v226;
    v226 = stack[0];
    v226 = qcdr(v226);
    stack[0] = v226;
    goto v2;

v70:
    v226 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v226);
    }
/* error exit handlers */
v108:
    popv(4);
    return nil;
}



/* Code for om2mml */

static Lisp_Object MS_CDECL CC_om2mml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "om2mml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for om2mml");
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
    fn = elt(env, 3); /* om2ir */
    v224 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-1];
    stack[0] = v224;
    v224 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-1];
    v224 = elt(env, 2); /* "Intermediate representation:" */
    v224 = Lprinc(nil, v224);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-1];
    v224 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-1];
    v224 = stack[0];
    v224 = Lprinc(nil, v224);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-1];
    v224 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-1];
    v224 = stack[0];
    fn = elt(env, 5); /* ir2mml */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v280;
    v224 = nil;
    { popv(2); return onevalue(v224); }
/* error exit handlers */
v280:
    popv(2);
    return nil;
}



/* Code for resume */

static Lisp_Object CC_resume(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v226, v218, v260, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resume");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v226 = v0;
    v218 = v95;
/* end of prologue */
    v260 = v226;
    if (v260 == nil) goto v193;
    v260 = v226;
    v260 = qcar(v260);
    v221 = qcar(v260);
    v260 = v226;
    v260 = qcar(v260);
    v260 = qcdr(v260);
    v260 = qcar(v260);
    v226 = qcdr(v226);
    {
        popv(1);
        fn = elt(env, 3); /* amatch */
        return (*qfnn(fn))(qenv(fn), 4, v221, v260, v218, v226);
    }

v193:
    v226 = v218;
    fn = elt(env, 4); /* chk */
    v218 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[0];
    v226 = qvalue(elt(env, 1)); /* t */
    if (v218 == v226) goto v113;
    v226 = nil;
    { popv(1); return onevalue(v226); }

v113:
    v226 = qvalue(elt(env, 2)); /* substitution */
    {
        popv(1);
        fn = elt(env, 5); /* bsubs */
        return (*qfn1(fn))(qenv(fn), v226);
    }
/* error exit handlers */
v96:
    popv(1);
    return nil;
}



/* Code for setmat */

static Lisp_Object MS_CDECL CC_setmat(Lisp_Object env, int nargs,
                         Lisp_Object v95, Lisp_Object v0,
                         Lisp_Object v1, Lisp_Object v16, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v157, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmat");
#endif
    if (stack >= stacklimit)
    {
        push4(v16,v1,v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v95,v0,v1,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v1;
    stack[-2] = v0;
    stack[-3] = v95;
/* end of prologue */
    v131 = qvalue(elt(env, 1)); /* !*modular */
    if (v131 == nil) goto v2;
    v131 = elt(env, 2); /* modular */
    v131 = ncons(v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    fn = elt(env, 6); /* off */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    v131 = elt(env, 3); /* mod_was_on */
    v131 = ncons(v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    fn = elt(env, 7); /* on */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    goto v2;

v2:
    v131 = stack[-2];
    v131 = integerp(v131);
    if (v131 == nil) goto v63;
    v131 = stack[-2];
    goto v102;

v102:
    stack[-2] = v131;
    v131 = stack[-1];
    v131 = integerp(v131);
    if (v131 == nil) goto v228;
    v131 = stack[-1];
    goto v111;

v111:
    stack[-1] = v131;
    v155 = stack[-3];
    v157 = stack[-2];
    v131 = stack[-1];
    v155 = list3(v155, v157, v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    v157 = stack[0];
    v131 = stack[-3];
    fn = elt(env, 8); /* my_letmtr */
    v131 = (*qfnn(fn))(qenv(fn), 3, v155, v157, v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    v131 = qvalue(elt(env, 5)); /* !*mod_was_on */
    if (v131 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v131 = elt(env, 2); /* modular */
    v131 = ncons(v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    fn = elt(env, 7); /* on */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    v131 = elt(env, 3); /* mod_was_on */
    v131 = ncons(v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    fn = elt(env, 6); /* off */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v228:
    v131 = stack[-1];
    fn = elt(env, 9); /* reval */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    goto v111;

v63:
    v131 = stack[-2];
    fn = elt(env, 9); /* reval */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    goto v102;
/* error exit handlers */
v230:
    popv(5);
    return nil;
}



/* Code for rd!:plus */

static Lisp_Object CC_rdTplus(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v307, v308, v287;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:plus");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
    stack[0] = v95;
/* end of prologue */
    v307 = qvalue(elt(env, 1)); /* nil */
    v308 = v307;
    v307 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v307 == nil) goto v103;
    v307 = qvalue(elt(env, 1)); /* nil */
    goto v222;

v222:
    if (v307 == nil) goto v188;
    v307 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v307, v308);

v188:
    v308 = stack[0];
    v307 = stack[-1];
    fn = elt(env, 8); /* convprc2 */
    v307 = (*qfn2(fn))(qenv(fn), v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    stack[-3] = v307;
    v307 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v307;
    v307 = stack[-3];
    if (!consp(v307)) goto v186;
    v308 = stack[-3];
    v307 = stack[-2];
    fn = elt(env, 9); /* plubf */
    v307 = (*qfn2(fn))(qenv(fn), v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    goto v104;

v104:
    stack[0] = v307;
    v287 = stack[0];
    v308 = stack[-3];
    v307 = stack[-2];
    fn = elt(env, 10); /* rdzchk */
    v307 = (*qfnn(fn))(qenv(fn), 3, v287, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v308 = v307;
    v307 = v308;
    if (!(!consp(v307))) { popv(5); return onevalue(v308); }
    v307 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v307, v308);

v186:
    stack[-1] = elt(env, 5); /* plus2 */
    v307 = stack[-3];
    stack[0] = Lmkquote(nil, v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v307 = stack[-2];
    v307 = Lmkquote(nil, v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v287 = list3(stack[-1], stack[0], v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v308 = qvalue(elt(env, 1)); /* nil */
    v307 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 11); /* errorset */
    v307 = (*qfnn(fn))(qenv(fn), 3, v287, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v308 = v307;
    v307 = v308;
    if (!consp(v307)) goto v45;
    v307 = v308;
    v307 = qcdr(v307);
    goto v44;

v44:
    if (v307 == nil) goto v171;
    fn = elt(env, 12); /* rndbfon */
    v307 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v307 = stack[-3];
    v307 = Lfloatp(nil, v307);
    env = stack[-4];
    if (v307 == nil) goto v297;
    v307 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    stack[0] = v307;
    goto v283;

v283:
    stack[-3] = stack[0];
    v307 = stack[-2];
    v307 = Lfloatp(nil, v307);
    env = stack[-4];
    if (v307 == nil) goto v309;
    v307 = stack[-2];
    fn = elt(env, 13); /* fl2bf */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    goto v274;

v274:
    stack[-2] = v307;
    fn = elt(env, 9); /* plubf */
    v307 = (*qfn2(fn))(qenv(fn), stack[0], v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    goto v104;

v309:
    v307 = stack[-2];
    if (!consp(v307)) goto v19;
    v307 = stack[-2];
    goto v310;

v310:
    fn = elt(env, 14); /* csl_normbf */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    goto v274;

v19:
    v307 = stack[-2];
    v307 = integerp(v307);
    if (v307 == nil) goto v311;
    v287 = elt(env, 3); /* !:rd!: */
    v308 = stack[-2];
    v307 = (Lisp_Object)1; /* 0 */
    v307 = list2star(v287, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    goto v310;

v311:
    v307 = stack[-2];
    fn = elt(env, 15); /* read!:num */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    goto v310;

v297:
    v307 = stack[-3];
    if (!consp(v307)) goto v181;
    v307 = stack[-3];
    goto v257;

v257:
    fn = elt(env, 14); /* csl_normbf */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    stack[0] = v307;
    goto v283;

v181:
    v307 = stack[-3];
    v307 = integerp(v307);
    if (v307 == nil) goto v255;
    v287 = elt(env, 3); /* !:rd!: */
    v308 = stack[-3];
    v307 = (Lisp_Object)1; /* 0 */
    v307 = list2star(v287, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    goto v257;

v255:
    v307 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    goto v257;

v171:
    v307 = v308;
    v307 = qcar(v307);
    goto v104;

v45:
    v307 = qvalue(elt(env, 7)); /* t */
    goto v44;

v103:
    v307 = stack[0];
    v307 = qcdr(v307);
    if (!consp(v307)) goto v213;
    v307 = qvalue(elt(env, 1)); /* nil */
    goto v222;

v213:
    v307 = stack[-1];
    v307 = qcdr(v307);
    if (!consp(v307)) goto v101;
    v307 = qvalue(elt(env, 1)); /* nil */
    goto v222;

v101:
    v307 = stack[0];
    v308 = qcdr(v307);
    v307 = stack[-1];
    v307 = qcdr(v307);
    fn = elt(env, 16); /* safe!-fp!-plus */
    v307 = (*qfn2(fn))(qenv(fn), v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v308 = v307;
    goto v222;
/* error exit handlers */
v210:
    popv(5);
    return nil;
}



/* Code for total!-degree!-in!-powers */

static Lisp_Object CC_totalKdegreeKinKpowers(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v278, v312;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for total-degree-in-powers");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v95;
/* end of prologue */

v243:
    v185 = stack[-1];
    if (v185 == nil) goto v70;
    v185 = stack[-1];
    if (!consp(v185)) goto v224;
    v185 = stack[-1];
    v185 = qcar(v185);
    v185 = (consp(v185) ? nil : lisp_true);
    goto v65;

v65:
    if (!(v185 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v185 = stack[-1];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v278 = qcar(v185);
    v185 = stack[0];
    v185 = Latsoc(nil, v278, v185);
    stack[-2] = v185;
    if (v185 == nil) goto v230;
    v185 = stack[-1];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v278 = qcdr(v185);
    v185 = stack[-2];
    v185 = qcdr(v185);
    v185 = (Lisp_Object)greaterp2(v278, v185);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v185 = v185 ? lisp_true : nil;
    env = stack[-3];
    if (v185 == nil) goto v43;
    v278 = stack[-2];
    v185 = stack[-1];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v185 = qcdr(v185);
    v185 = Lrplacd(nil, v278, v185);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    goto v43;

v43:
    v185 = stack[-1];
    stack[-2] = qcdr(v185);
    v185 = stack[-1];
    v185 = qcar(v185);
    v278 = qcdr(v185);
    v185 = stack[0];
    v185 = CC_totalKdegreeKinKpowers(env, v278, v185);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v185;
    goto v243;

v230:
    v185 = stack[-1];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v312 = qcar(v185);
    v185 = stack[-1];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v278 = qcdr(v185);
    v185 = stack[0];
    v185 = acons(v312, v278, v185);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[0] = v185;
    goto v43;

v224:
    v185 = qvalue(elt(env, 1)); /* t */
    goto v65;

v70:
    v185 = qvalue(elt(env, 1)); /* t */
    goto v65;
/* error exit handlers */
v81:
    popv(4);
    return nil;
}



/* Code for begin1 */

static Lisp_Object MS_CDECL CC_begin1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v207, v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "begin1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for begin1");
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
    v204 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    qvalue(elt(env, 1)) = v204; /* otime!* */
    v204 = elt(env, 2); /* gctime */
    fn = elt(env, 57); /* getd */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    if (v204 == nil) goto v112;
    v204 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    qvalue(elt(env, 3)) = v204; /* ogctime!* */
    goto v60;

v60:
    v204 = elt(env, 4); /* !*semicol!* */
    qvalue(elt(env, 5)) = v204; /* cursym!* */
    goto v2;

v2:
    v204 = qvalue(elt(env, 6)); /* !*int */
    if (v204 == nil) goto v244;
    v204 = qvalue(elt(env, 7)); /* ifl!* */
    if (!(v204 == nil)) goto v244;
    v204 = qvalue(elt(env, 8)); /* !*nosave!* */
    if (!(v204 == nil)) goto v66;
    v207 = qvalue(elt(env, 9)); /* statcounter */
    v204 = (Lisp_Object)1; /* 0 */
    if (v207 == v204) goto v66;
    fn = elt(env, 58); /* add2buflis */
    v204 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    goto v66;

v66:
    fn = elt(env, 59); /* update_prompt */
    v204 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    goto v244;

v244:
    v204 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 8)) = v204; /* !*nosave!* */
    v204 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 11)) = v204; /* !*strind */
    v204 = qvalue(elt(env, 10)); /* nil */
    stack[-2] = v204;
    v204 = qvalue(elt(env, 12)); /* !*time */
    if (v204 == nil) goto v214;
    v204 = elt(env, 13); /* (showtime) */
    fn = elt(env, 60); /* eval */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    goto v214;

v214:
    v204 = qvalue(elt(env, 14)); /* !*output */
    if (v204 == nil) goto v49;
    v204 = qvalue(elt(env, 15)); /* ofl!* */
    if (v204 == nil) goto v225;
    v204 = qvalue(elt(env, 10)); /* nil */
    goto v104;

v104:
    if (v204 == nil) goto v49;
    v204 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    goto v49;

v49:
    v204 = qvalue(elt(env, 18)); /* tslin!* */
    if (v204 == nil) goto v78;
    v204 = qvalue(elt(env, 18)); /* tslin!* */
    v204 = qcar(v204);
    qvalue(elt(env, 19)) = v204; /* !*slin */
    v204 = qvalue(elt(env, 18)); /* tslin!* */
    v204 = qcdr(v204);
    qvalue(elt(env, 20)) = v204; /* lreadfn!* */
    v204 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 18)) = v204; /* tslin!* */
    goto v78;

v78:
    v204 = qvalue(elt(env, 21)); /* initl!* */
    stack[-1] = v204;
    goto v62;

v62:
    v204 = stack[-1];
    if (v204 == nil) goto v297;
    v204 = stack[-1];
    stack[0] = qcar(v204);
    v204 = stack[-1];
    v207 = qcar(v204);
    v204 = elt(env, 22); /* initl */
    v204 = get(v207, v204);
    env = stack[-3];
    fn = elt(env, 60); /* eval */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    v204 = Lset(nil, stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    v204 = stack[-1];
    v204 = qcdr(v204);
    stack[-1] = v204;
    goto v62;

v297:
    v207 = qvalue(elt(env, 23)); /* forkeywords!* */
    v204 = elt(env, 24); /* delim */
    v204 = Lremflag(nil, v207, v204);
    env = stack[-3];
    v207 = qvalue(elt(env, 25)); /* repeatkeywords!* */
    v204 = elt(env, 24); /* delim */
    v204 = Lremflag(nil, v207, v204);
    env = stack[-3];
    v207 = qvalue(elt(env, 26)); /* whilekeywords!* */
    v204 = elt(env, 24); /* delim */
    v204 = Lremflag(nil, v207, v204);
    env = stack[-3];
    v204 = qvalue(elt(env, 6)); /* !*int */
    if (v204 == nil) goto v37;
    v204 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 27)) = v204; /* erfg!* */
    goto v37;

v37:
    v207 = qvalue(elt(env, 5)); /* cursym!* */
    v204 = elt(env, 28); /* end */
    if (v207 == v204) goto v179;
    v204 = qvalue(elt(env, 6)); /* !*int */
    if (v204 == nil) goto v289;
    v204 = qvalue(elt(env, 7)); /* ifl!* */
    if (!(v204 == nil)) goto v289;
    v207 = qvalue(elt(env, 29)); /* key!* */
    v204 = elt(env, 30); /* ed */
    if (v207 == v204) goto v289;
    v204 = qvalue(elt(env, 31)); /* promptexp!* */
    fn = elt(env, 61); /* printprompt */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    goto v289;

v289:
    v211 = elt(env, 32); /* (command) */
    v207 = qvalue(elt(env, 33)); /* t */
    v204 = qvalue(elt(env, 34)); /* !*backtrace */
    fn = elt(env, 62); /* errorset */
    v204 = (*qfnn(fn))(qenv(fn), 3, v211, v207, v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    stack[-1] = v204;
    v204 = qvalue(elt(env, 14)); /* !*output */
    if (v204 == nil) goto v337;
    v204 = qvalue(elt(env, 35)); /* !*echo */
    if (v204 == nil) goto v337;
    v204 = qvalue(elt(env, 36)); /* !*extraecho */
    if (v204 == nil) goto v337;
    v204 = qvalue(elt(env, 6)); /* !*int */
    if (v204 == nil) goto v29;
    v204 = qvalue(elt(env, 7)); /* ifl!* */
    goto v28;

v28:
    if (v204 == nil) goto v337;
    v204 = qvalue(elt(env, 16)); /* !*defn */
    if (!(v204 == nil)) goto v337;
    v204 = qvalue(elt(env, 37)); /* !*demo */
    if (!(v204 == nil)) goto v337;
    v204 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    goto v337;

v337:
    v204 = stack[-1];
    if (!consp(v204)) goto v162;
    v204 = stack[-1];
    v204 = qcdr(v204);
    goto v87;

v87:
    if (v204 == nil) goto v338;
    v207 = qvalue(elt(env, 50)); /* program!* */
    v204 = qvalue(elt(env, 51)); /* !$eof!$ */
    if (v207 == v204) goto v339;
    v204 = qvalue(elt(env, 10)); /* nil */
    goto v117;

v117:
    if (!(v204 == nil)) goto v65;
    v207 = qvalue(elt(env, 46)); /* eof!* */
    v204 = (Lisp_Object)1; /* 0 */
    v204 = (Lisp_Object)greaterp2(v207, v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    v204 = v204 ? lisp_true : nil;
    env = stack[-3];
    if (!(v204 == nil)) goto v65;
    v207 = stack[-1];
    v204 = elt(env, 53); /* "BEGIN invalid" */
    if (equal(v207, v204)) goto v2;
    v204 = qvalue(elt(env, 33)); /* t */
    stack[-2] = v204;
    goto v222;

v222:
    v204 = qvalue(elt(env, 19)); /* !*slin */
    if (!(v204 == nil)) goto v103;
    v204 = qvalue(elt(env, 33)); /* t */
    fn = elt(env, 63); /* comm1 */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    goto v103;

v103:
    v204 = qvalue(elt(env, 33)); /* t */
    qvalue(elt(env, 27)) = v204; /* erfg!* */
    v204 = qvalue(elt(env, 6)); /* !*int */
    if (v204 == nil) goto v124;
    v204 = qvalue(elt(env, 10)); /* nil */
    goto v126;

v126:
    if (v204 == nil) goto v340;
    v204 = qvalue(elt(env, 33)); /* t */
    qvalue(elt(env, 16)) = v204; /* !*defn */
    v204 = qvalue(elt(env, 33)); /* t */
    qvalue(elt(env, 35)) = v204; /* !*echo */
    v204 = qvalue(elt(env, 55)); /* cmsg!* */
    if (!(v204 == nil)) goto v341;
    v204 = elt(env, 56); /* "Continuing with parsing only ..." */
    fn = elt(env, 64); /* lprie */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    goto v341;

v341:
    v204 = qvalue(elt(env, 33)); /* t */
    qvalue(elt(env, 55)) = v204; /* cmsg!* */
    goto v2;

v340:
    v204 = qvalue(elt(env, 54)); /* !*errcont */
    if (v204 == nil) goto v342;
    v204 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 27)) = v204; /* erfg!* */
    goto v2;

v342:
    v204 = stack[-2];
    fn = elt(env, 65); /* pause1 */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    v211 = v204;
    v204 = v211;
    if (v204 == nil) goto v343;
    v204 = v211;
    fn = elt(env, 60); /* eval */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    v204 = (v204 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v204); }

v343:
    v204 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 27)) = v204; /* erfg!* */
    goto v2;

v124:
    v204 = qvalue(elt(env, 54)); /* !*errcont */
    v204 = (v204 == nil ? lisp_true : nil);
    goto v126;

v65:
    v204 = qvalue(elt(env, 42)); /* crbuf1!* */
    if (v204 == nil) goto v147;
    v204 = qvalue(elt(env, 43)); /* !*msg */
    if (v204 == nil) goto v344;
    v207 = elt(env, 44); /* "***" */
    v204 = elt(env, 45); /* "Closing object improperly removed. Redo edit." 
*/
    fn = elt(env, 66); /* lpriw */
    v204 = (*qfn2(fn))(qenv(fn), v207, v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    goto v344;

v344:
    v204 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 42)) = v204; /* crbuf1!* */
    v204 = qvalue(elt(env, 10)); /* nil */
    { popv(4); return onevalue(v204); }

v147:
    v207 = qvalue(elt(env, 46)); /* eof!* */
    v204 = (Lisp_Object)65; /* 4 */
    v204 = (Lisp_Object)greaterp2(v207, v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    v204 = v204 ? lisp_true : nil;
    env = stack[-3];
    if (v204 == nil) goto v345;
    v204 = qvalue(elt(env, 43)); /* !*msg */
    if (v204 == nil) goto v346;
    v207 = elt(env, 44); /* "***" */
    v204 = elt(env, 47); /* "End-of-file read" */
    fn = elt(env, 66); /* lpriw */
    v204 = (*qfn2(fn))(qenv(fn), v207, v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    goto v346;

v346:
    v204 = elt(env, 48); /* (bye) */
    {
        popv(4);
        fn = elt(env, 60); /* eval */
        return (*qfn1(fn))(qenv(fn), v204);
    }

v345:
    v204 = qvalue(elt(env, 6)); /* !*int */
    if (v204 == nil) goto v138;
    v204 = qvalue(elt(env, 7)); /* ifl!* */
    if (!(v204 == nil)) goto v138;
    v204 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 49)) = v204; /* crbuf!* */
    v204 = qvalue(elt(env, 33)); /* t */
    qvalue(elt(env, 8)) = v204; /* !*nosave!* */
    goto v2;

v138:
    v204 = qvalue(elt(env, 10)); /* nil */
    { popv(4); return onevalue(v204); }

v339:
    v207 = qvalue(elt(env, 52)); /* ttype!* */
    v204 = (Lisp_Object)49; /* 3 */
    if (v207 == v204) goto v347;
    v204 = qvalue(elt(env, 10)); /* nil */
    goto v117;

v347:
    v204 = qvalue(elt(env, 46)); /* eof!* */
    v204 = add1(v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    qvalue(elt(env, 46)) = v204; /* eof!* */
    goto v117;

v338:
    v204 = stack[-1];
    v204 = qcar(v204);
    stack[-1] = v204;
    v204 = stack[-1];
    v207 = qcar(v204);
    v204 = elt(env, 38); /* symbolic */
    if (v207 == v204) goto v15;
    v204 = qvalue(elt(env, 10)); /* nil */
    goto v10;

v10:
    if (v204 == nil) goto v9;
    v204 = stack[-1];
    v204 = qcdr(v204);
    v204 = qcar(v204);
    fn = elt(env, 60); /* eval */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    fn = elt(env, 67); /* xmodloop */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    v211 = v204;
    goto v348;

v348:
    v204 = v211;
    if (v204 == nil) goto v2;
    v207 = v211;
    v204 = elt(env, 28); /* end */
    if (v207 == v204) goto v349;
    v207 = v211;
    v204 = elt(env, 40); /* err2 */
    if (v207 == v204) goto v222;
    v207 = v211;
    v204 = elt(env, 41); /* err3 */
    if (v207 == v204) goto v103;
    else goto v65;

v349:
    v204 = qvalue(elt(env, 10)); /* nil */
    { popv(4); return onevalue(v204); }

v9:
    v204 = stack[-1];
    fn = elt(env, 68); /* begin11 */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    v211 = v204;
    goto v348;

v15:
    v204 = stack[-1];
    v204 = qcdr(v204);
    v207 = qcar(v204);
    v204 = elt(env, 39); /* xmodule */
    v204 = Leqcar(nil, v207, v204);
    env = stack[-3];
    goto v10;

v162:
    v204 = qvalue(elt(env, 33)); /* t */
    goto v87;

v29:
    v204 = qvalue(elt(env, 33)); /* t */
    goto v28;

v179:
    v204 = elt(env, 28); /* end */
    fn = elt(env, 63); /* comm1 */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-3];
    v204 = qvalue(elt(env, 10)); /* nil */
    { popv(4); return onevalue(v204); }

v225:
    v204 = qvalue(elt(env, 6)); /* !*int */
    if (v204 == nil) goto v155;
    v204 = qvalue(elt(env, 7)); /* ifl!* */
    if (!(v204 == nil)) goto v155;
    v204 = qvalue(elt(env, 16)); /* !*defn */
    if (v204 == nil) goto v242;
    v204 = qvalue(elt(env, 10)); /* nil */
    goto v104;

v242:
    v204 = qvalue(elt(env, 17)); /* !*lessspace */
    v204 = (v204 == nil ? lisp_true : nil);
    goto v104;

v155:
    v204 = qvalue(elt(env, 10)); /* nil */
    goto v104;

v112:
    v204 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v204; /* ogctime!* */
    goto v60;
/* error exit handlers */
v336:
    popv(4);
    return nil;
}



/* Code for red_divtest */

static Lisp_Object CC_red_divtest(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_divtest");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v95;
/* end of prologue */

v3:
    v51 = stack[-1];
    if (v51 == nil) goto v65;
    v51 = stack[-1];
    v51 = qcar(v51);
    fn = elt(env, 2); /* bas_dpoly */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    v67 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    v51 = stack[0];
    fn = elt(env, 4); /* mo_vdivides!? */
    v51 = (*qfn2(fn))(qenv(fn), v67, v51);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-2];
    if (v51 == nil) goto v101;
    v51 = stack[-1];
    v51 = qcar(v51);
    { popv(3); return onevalue(v51); }

v101:
    v51 = stack[-1];
    v51 = qcdr(v51);
    stack[-1] = v51;
    goto v3;

v65:
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v51); }
/* error exit handlers */
v228:
    popv(3);
    return nil;
}



/* Code for il_simp */

static Lisp_Object CC_il_simp(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v222, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for il_simp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v222 = v95;
/* end of prologue */
    v103 = v222;
    v222 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* il_simp1 */
        return (*qfn2(fn))(qenv(fn), v103, v222);
    }
}



/* Code for repeats */

static Lisp_Object CC_repeats(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v226, v218, v260;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repeats");
#endif
    if (stack >= stacklimit)
    {
        push(v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v95;
/* end of prologue */
    v260 = nil;
    goto v3;

v3:
    v226 = stack[0];
    if (v226 == nil) goto v65;
    v226 = stack[0];
    v218 = qcar(v226);
    v226 = stack[0];
    v226 = qcdr(v226);
    v226 = Lmember(nil, v218, v226);
    if (v226 == nil) goto v227;
    v226 = stack[0];
    v226 = qcar(v226);
    v218 = v260;
    v226 = cons(v226, v218);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v260 = v226;
    v226 = stack[0];
    v226 = qcdr(v226);
    stack[0] = v226;
    goto v3;

v227:
    v226 = stack[0];
    v226 = qcdr(v226);
    stack[0] = v226;
    goto v3;

v65:
    v226 = v260;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v226);
    }
/* error exit handlers */
v96:
    popv(2);
    return nil;
}



/* Code for arglist_member */

static Lisp_Object CC_arglist_member(Lisp_Object env,
                         Lisp_Object v95, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v220;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arglist_member");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v95,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v95;
/* end of prologue */

v243:
    v99 = stack[0];
    if (!consp(v99)) goto v234;
    v220 = stack[-1];
    v99 = stack[0];
    v99 = qcar(v99);
    if (equal(v220, v99)) goto v212;
    v99 = stack[0];
    v99 = qcar(v99);
    if (!consp(v99)) goto v260;
    v220 = stack[-1];
    v99 = stack[0];
    v99 = qcar(v99);
    v99 = qcdr(v99);
    v99 = CC_arglist_member(env, v220, v99);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-2];
    goto v110;

v110:
    if (!(v99 == nil)) { popv(3); return onevalue(v99); }
    v220 = stack[-1];
    v99 = stack[0];
    v99 = qcdr(v99);
    stack[-1] = v220;
    stack[0] = v99;
    goto v243;

v260:
    v99 = qvalue(elt(env, 2)); /* nil */
    goto v110;

v212:
    v99 = qvalue(elt(env, 1)); /* t */
    goto v110;

v234:
    v99 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v99); }
/* error exit handlers */
v187:
    popv(3);
    return nil;
}



/* Code for mconv */

static Lisp_Object CC_mconv(Lisp_Object env,
                         Lisp_Object v95)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v100, v101, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mconv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v113 = v95;
/* end of prologue */
    v244 = qvalue(elt(env, 1)); /* dmode!* */
    v101 = v244;
    v244 = v101;
    if (v244 == nil) goto v2;
    v100 = v101;
    v244 = elt(env, 3); /* !:gi!: */
    if (v100 == v244) goto v222;
    v244 = v101;
    goto v3;

v3:
    qvalue(elt(env, 5)) = v244; /* dmd!* */
    v244 = v113;
    {
        fn = elt(env, 6); /* mconv1 */
        return (*qfn1(fn))(qenv(fn), v244);
    }

v222:
    v244 = elt(env, 4); /* !:crn!: */
    goto v3;

v2:
    v244 = elt(env, 2); /* !:rn!: */
    goto v3;
}



/* Code for ofsf_entry2at1 */

static Lisp_Object MS_CDECL CC_ofsf_entry2at1(Lisp_Object env, int nargs,
                         Lisp_Object v95, Lisp_Object v0,
                         Lisp_Object v1, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v226, v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_entry2at1");
#endif
    if (stack >= stacklimit)
    {
        push3(v1,v0,v95);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v95,v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
    v106 = v95;
/* end of prologue */
    v226 = stack[-1];
    v218 = qcar(v226);
    v226 = v106;
    v106 = elt(env, 1); /* and */
    v106 = (v226 == v106 ? lisp_true : nil);
    fn = elt(env, 3); /* ofsf_clnegrel */
    stack[-2] = (*qfn2(fn))(qenv(fn), v218, v106);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v226 = stack[0];
    v106 = stack[-1];
    v106 = qcdr(v106);
    fn = elt(env, 4); /* addsq */
    v106 = (*qfn2(fn))(qenv(fn), v226, v106);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v106 = qcar(v106);
    v226 = qvalue(elt(env, 2)); /* nil */
    {
        Lisp_Object v108 = stack[-2];
        popv(4);
        return list3(v108, v106, v226);
    }
/* error exit handlers */
v97:
    popv(4);
    return nil;
}



setup_type const u15_setup[] =
{
    {"command",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_command},
    {"dp_neg",                  CC_dp_neg,      too_many_1,    wrong_no_1},
    {"simp-prop-order",         too_few_2,      CC_simpKpropKorder,wrong_no_2},
    {"setqget",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_setqget},
    {"mk+mat+mult+mat",         too_few_2,      CC_mkLmatLmultLmat,wrong_no_2},
    {"ratpoly_lc",              CC_ratpoly_lc,  too_many_1,    wrong_no_1},
    {"getsetvars",              CC_getsetvars,  too_many_1,    wrong_no_1},
    {"merge-ind-vars",          too_few_2,      CC_mergeKindKvars,wrong_no_2},
    {"vdpsave",                 CC_vdpsave,     too_many_1,    wrong_no_1},
    {"prinlatom",               CC_prinlatom,   too_many_1,    wrong_no_1},
    {"insertparens",            CC_insertparens,too_many_1,    wrong_no_1},
    {"deleteall",               too_few_2,      CC_deleteall,  wrong_no_2},
    {"lesspcdr",                too_few_2,      CC_lesspcdr,   wrong_no_2},
    {"set-global-mode",         CC_setKglobalKmode,too_many_1, wrong_no_1},
    {"setk",                    too_few_2,      CC_setk,       wrong_no_2},
    {"sf_member",               too_few_2,      CC_sf_member,  wrong_no_2},
    {"dl_get2",                 too_few_2,      CC_dl_get2,    wrong_no_2},
    {"ilcm",                    too_few_2,      CC_ilcm,       wrong_no_2},
    {"reverse-num",             CC_reverseKnum, too_many_1,    wrong_no_1},
    {"ibalp_initwl",            CC_ibalp_initwl,too_many_1,    wrong_no_1},
    {"poly-minusp",             CC_polyKminusp, too_many_1,    wrong_no_1},
    {"ofsf_sacat",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sacat},
    {"ir2om",                   CC_ir2om,       too_many_1,    wrong_no_1},
    {"cr:minusp",               CC_crTminusp,   too_many_1,    wrong_no_1},
    {"xord_deglex",             too_few_2,      CC_xord_deglex,wrong_no_2},
    {"fortranname",             CC_fortranname, too_many_1,    wrong_no_1},
    {"physop2sq",               CC_physop2sq,   too_many_1,    wrong_no_1},
    {"sf2mv1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_sf2mv1},
    {"rnminusp:",               CC_rnminuspT,   too_many_1,    wrong_no_1},
    {"di_restore",              CC_di_restore,  too_many_1,    wrong_no_1},
    {"resimpf",                 CC_resimpf,     too_many_1,    wrong_no_1},
    {"numeric-content",         CC_numericKcontent,too_many_1, wrong_no_1},
    {"cl_identifyat",           CC_cl_identifyat,too_many_1,   wrong_no_1},
    {"evaluatecoeffts",         too_few_2,      CC_evaluatecoeffts,wrong_no_2},
    {"ibalp_readclause",        too_few_2,      CC_ibalp_readclause,wrong_no_2},
    {"ratpoly_1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_1},
    {"mapins",                  too_few_2,      CC_mapins,     wrong_no_2},
    {"om2mml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_om2mml},
    {"resume",                  too_few_2,      CC_resume,     wrong_no_2},
    {"setmat",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setmat},
    {"rd:plus",                 too_few_2,      CC_rdTplus,    wrong_no_2},
    {"total-degree-in-powers",  too_few_2,      CC_totalKdegreeKinKpowers,wrong_no_2},
    {"begin1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_begin1},
    {"red_divtest",             too_few_2,      CC_red_divtest,wrong_no_2},
    {"il_simp",                 CC_il_simp,     too_many_1,    wrong_no_1},
    {"repeats",                 CC_repeats,     too_many_1,    wrong_no_1},
    {"arglist_member",          too_few_2,      CC_arglist_member,wrong_no_2},
    {"mconv",                   CC_mconv,       too_many_1,    wrong_no_1},
    {"ofsf_entry2at1",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at1},
    {NULL, (one_args *)"u15", (two_args *)"3577 3318230 9050101", 0}
};

/* end of generated code */
