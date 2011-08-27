
/* $destdir\u41.c        Machine generated C code */

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


/* Code for make_wedge_pair */

static Lisp_Object CC_make_wedge_pair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make_wedge_pair");
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
    v19 = stack[-2];
    v18 = stack[-2];
    stack[0] = list2(v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v18 = stack[-1];
    fn = elt(env, 5); /* xval */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    fn = elt(env, 6); /* xlcm */
    v18 = (*qfn2(fn))(qenv(fn), stack[0], v18);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    stack[-3] = v18;
    v18 = qvalue(elt(env, 1)); /* !*twosided */
    if (v18 == nil) goto v22;
    v18 = qvalue(elt(env, 2)); /* xtruncate!* */
    if (!(v18 == nil)) goto v22;

v23:
    v19 = stack[-2];
    v18 = stack[-1];
    fn = elt(env, 7); /* overall_factor */
    v18 = (*qfn2(fn))(qenv(fn), v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    if (v18 == nil) goto v24;
    v18 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v18); }

v24:
    v18 = stack[-3];
    fn = elt(env, 8); /* mknwedge */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    fn = elt(env, 9); /* xdegreecheck */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    if (v18 == nil) goto v25;
    v18 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v18); }

v25:
    stack[0] = elt(env, 4); /* wedge_pair */
    v20 = stack[-2];
    v19 = (Lisp_Object)17; /* 1 */
    v18 = (Lisp_Object)17; /* 1 */
    v18 = list2star(v20, v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v19 = ncons(v18);
    nil = C_nil;
    if (exception_pending()) goto v21;
    v18 = stack[-1];
    {
        Lisp_Object v26 = stack[-3];
        Lisp_Object v27 = stack[0];
        popv(5);
        return list4(v26, v27, v19, v18);
    }

v22:
    stack[0] = stack[-2];
    v18 = stack[-1];
    fn = elt(env, 5); /* xval */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v18 = Lmemq(nil, stack[0], v18);
    if (!(v18 == nil)) goto v23;
    v18 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v18); }
/* error exit handlers */
v21:
    popv(5);
    return nil;
}



/* Code for !:dmexpt */

static Lisp_Object CC_Tdmexpt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmexpt");
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
    v33 = stack[0];
    fn = elt(env, 2); /* !:dm2fix */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    v34 = v33;
    v34 = integerp(v34);
    if (v34 == nil) goto v35;
    v34 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v34, v33);
    }

v35:
    v33 = stack[-1];
    fn = elt(env, 4); /* force!-to!-dm */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    stack[-1] = v33;
    v33 = stack[0];
    fn = elt(env, 4); /* force!-to!-dm */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    stack[0] = v33;
    v33 = qvalue(elt(env, 1)); /* !*complex */
    if (v33 == nil) goto v36;
    v34 = stack[-1];
    v33 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* crexpt!* */
        return (*qfn2(fn))(qenv(fn), v34, v33);
    }

v36:
    v34 = stack[-1];
    v33 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* rdexpt!* */
        return (*qfn2(fn))(qenv(fn), v34, v33);
    }
/* error exit handlers */
v11:
    popv(3);
    return nil;
}



/* Code for deletez1 */

static Lisp_Object CC_deletez1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v33, v34, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deletez1");
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
    v42 = nil;
    goto v43;

v43:
    v28 = stack[-1];
    if (v28 == nil) goto v14;
    v34 = (Lisp_Object)1; /* 0 */
    v28 = stack[-1];
    v28 = qcar(v28);
    v33 = qcar(v28);
    v28 = stack[0];
    v28 = Lassoc(nil, v33, v28);
    v28 = qcdr(v28);
    if (v34 == v28) goto v44;
    v28 = stack[-1];
    v28 = qcar(v28);
    v33 = v42;
    v28 = cons(v28, v33);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v42 = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v43;

v44:
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v43;

v14:
    v28 = v42;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v28);
    }
/* error exit handlers */
v45:
    popv(3);
    return nil;
}



/* Code for mapcarcar */

static Lisp_Object CC_mapcarcar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapcarcar");
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
    v24 = v0;
/* end of prologue */
    stack[-3] = v24;
    v24 = stack[-3];
    if (v24 == nil) goto v48;
    v24 = stack[-3];
    v24 = qcar(v24);
    v24 = qcar(v24);
    v24 = ncons(v24);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-4];
    stack[-1] = v24;
    stack[-2] = v24;
    goto v49;

v49:
    v24 = stack[-3];
    v24 = qcdr(v24);
    stack[-3] = v24;
    v24 = stack[-3];
    if (v24 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v24 = stack[-3];
    v24 = qcar(v24);
    v24 = qcar(v24);
    v24 = ncons(v24);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-4];
    v24 = Lrplacd(nil, stack[0], v24);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-4];
    v24 = stack[-1];
    v24 = qcdr(v24);
    stack[-1] = v24;
    goto v49;

v48:
    v24 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v24); }
/* error exit handlers */
v33:
    popv(5);
    return nil;
}



/* Code for simp!-prop!-form */

static Lisp_Object CC_simpKpropKform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-form");
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
    v93 = v0;
/* end of prologue */
    v94 = v93;
    v92 = elt(env, 1); /* (nil) */
    if (equal(v94, v92)) goto v47;
    v92 = v93;
    stack[-7] = v92;
    v92 = stack[-7];
    if (v92 == nil) goto v95;
    v92 = stack[-7];
    v92 = qcar(v92);
    stack[-3] = v92;
    v92 = stack[-3];
    if (v92 == nil) goto v36;
    v92 = stack[-3];
    v92 = qcar(v92);
    v94 = v92;
    v93 = v94;
    v92 = elt(env, 4); /* not_prop!* */
    if (!consp(v93)) goto v2;
    v93 = qcar(v93);
    if (!(v93 == v92)) goto v2;
    v92 = elt(env, 5); /* not */
    v93 = v94;
    v93 = qcdr(v93);
    v93 = qcar(v93);
    v92 = list2(v92, v93);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    goto v42;

v42:
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    stack[-1] = v92;
    stack[-2] = v92;
    goto v30;

v30:
    v92 = stack[-3];
    v92 = qcdr(v92);
    stack[-3] = v92;
    v92 = stack[-3];
    if (v92 == nil) goto v97;
    stack[0] = stack[-1];
    v92 = stack[-3];
    v92 = qcar(v92);
    v94 = v92;
    v93 = v94;
    v92 = elt(env, 4); /* not_prop!* */
    if (!consp(v93)) goto v98;
    v93 = qcar(v93);
    if (!(v93 == v92)) goto v98;
    v92 = elt(env, 5); /* not */
    v93 = v94;
    v93 = qcdr(v93);
    v93 = qcar(v93);
    v92 = list2(v92, v93);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    goto v99;

v99:
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    v92 = Lrplacd(nil, stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    v92 = stack[-1];
    v92 = qcdr(v92);
    stack[-1] = v92;
    goto v30;

v98:
    v92 = v94;
    v92 = qcdr(v92);
    v92 = qcar(v92);
    goto v99;

v97:
    v92 = stack[-2];
    goto v29;

v29:
    v93 = v92;
    v93 = qcdr(v93);
    if (v93 == nil) goto v100;
    v93 = qvalue(elt(env, 6)); /* !'and */
    v92 = cons(v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    goto v101;

v101:
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    stack[-5] = v92;
    stack[-6] = v92;
    goto v39;

v39:
    v92 = stack[-7];
    v92 = qcdr(v92);
    stack[-7] = v92;
    v92 = stack[-7];
    if (v92 == nil) goto v102;
    stack[-4] = stack[-5];
    v92 = stack[-7];
    v92 = qcar(v92);
    stack[-3] = v92;
    v92 = stack[-3];
    if (v92 == nil) goto v103;
    v92 = stack[-3];
    v92 = qcar(v92);
    v94 = v92;
    v93 = v94;
    v92 = elt(env, 4); /* not_prop!* */
    if (!consp(v93)) goto v104;
    v93 = qcar(v93);
    if (!(v93 == v92)) goto v104;
    v92 = elt(env, 5); /* not */
    v93 = v94;
    v93 = qcdr(v93);
    v93 = qcar(v93);
    v92 = list2(v92, v93);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    goto v105;

v105:
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    stack[-1] = v92;
    stack[-2] = v92;
    goto v106;

v106:
    v92 = stack[-3];
    v92 = qcdr(v92);
    stack[-3] = v92;
    v92 = stack[-3];
    if (v92 == nil) goto v107;
    stack[0] = stack[-1];
    v92 = stack[-3];
    v92 = qcar(v92);
    v94 = v92;
    v93 = v94;
    v92 = elt(env, 4); /* not_prop!* */
    if (!consp(v93)) goto v108;
    v93 = qcar(v93);
    if (!(v93 == v92)) goto v108;
    v92 = elt(env, 5); /* not */
    v93 = v94;
    v93 = qcdr(v93);
    v93 = qcar(v93);
    v92 = list2(v92, v93);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    goto v109;

v109:
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    v92 = Lrplacd(nil, stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    v92 = stack[-1];
    v92 = qcdr(v92);
    stack[-1] = v92;
    goto v106;

v108:
    v92 = v94;
    v92 = qcdr(v92);
    v92 = qcar(v92);
    goto v109;

v107:
    v92 = stack[-2];
    goto v110;

v110:
    v93 = v92;
    v93 = qcdr(v93);
    if (v93 == nil) goto v111;
    v93 = qvalue(elt(env, 6)); /* !'and */
    v92 = cons(v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    goto v112;

v112:
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    v92 = Lrplacd(nil, stack[-4], v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-8];
    v92 = stack[-5];
    v92 = qcdr(v92);
    stack[-5] = v92;
    goto v39;

v111:
    v92 = qcar(v92);
    goto v112;

v104:
    v92 = v94;
    v92 = qcdr(v92);
    v92 = qcar(v92);
    goto v105;

v103:
    v92 = qvalue(elt(env, 3)); /* nil */
    goto v110;

v102:
    v92 = stack[-6];
    goto v35;

v35:
    v93 = v92;
    v92 = v93;
    v92 = qcdr(v92);
    if (v92 == nil) goto v113;
    v92 = qvalue(elt(env, 7)); /* !'or */
    popv(9);
    return cons(v92, v93);

v113:
    v92 = v93;
    v92 = qcar(v92);
    { popv(9); return onevalue(v92); }

v100:
    v92 = qcar(v92);
    goto v101;

v2:
    v92 = v94;
    v92 = qcdr(v92);
    v92 = qcar(v92);
    goto v42;

v36:
    v92 = qvalue(elt(env, 3)); /* nil */
    goto v29;

v95:
    v92 = qvalue(elt(env, 3)); /* nil */
    goto v35;

v47:
    v92 = qvalue(elt(env, 2)); /* !'true */
    { popv(9); return onevalue(v92); }
/* error exit handlers */
v96:
    popv(9);
    return nil;
}



/* Code for monomcomparelex */

static Lisp_Object CC_monomcomparelex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129, v130;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomcomparelex");
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
    v128 = v0;
/* end of prologue */
    v130 = qvalue(elt(env, 1)); /* nil */
    v129 = v128;
    v128 = (Lisp_Object)17; /* 1 */
    v128 = *(Lisp_Object *)((char *)v129 + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    v128 = cons(v130, v128);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    v128 = Lreverse(nil, v128);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    v128 = qcdr(v128);
    stack[-2] = v128;
    v130 = qvalue(elt(env, 1)); /* nil */
    v129 = stack[0];
    v128 = (Lisp_Object)17; /* 1 */
    v128 = *(Lisp_Object *)((char *)v129 + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    v128 = cons(v130, v128);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    v128 = Lreverse(nil, v128);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    v128 = qcdr(v128);
    stack[-1] = v128;
    v128 = (Lisp_Object)1; /* 0 */
    stack[0] = v128;
    goto v132;

v132:
    v128 = stack[-2];
    v128 = qcar(v128);
    if (v128 == nil) goto v84;
    v128 = stack[-1];
    v128 = qcar(v128);
    if (v128 == nil) goto v84;
    v128 = stack[-2];
    v129 = qcar(v128);
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = (Lisp_Object)lessp2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v131;
    v128 = v128 ? lisp_true : nil;
    env = stack[-3];
    if (v128 == nil) goto v133;
    v128 = (Lisp_Object)17; /* 1 */
    stack[0] = v128;
    v128 = qvalue(elt(env, 1)); /* nil */
    v128 = ncons(v128);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    stack[-2] = v128;
    goto v132;

v133:
    v128 = stack[-2];
    v129 = qcar(v128);
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = (Lisp_Object)greaterp2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v131;
    v128 = v128 ? lisp_true : nil;
    env = stack[-3];
    if (v128 == nil) goto v18;
    v128 = (Lisp_Object)-15; /* -1 */
    stack[0] = v128;
    v128 = qvalue(elt(env, 1)); /* nil */
    v128 = ncons(v128);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    stack[-2] = v128;
    goto v132;

v18:
    v128 = stack[-2];
    v128 = qcdr(v128);
    stack[-2] = v128;
    v128 = stack[-1];
    v128 = qcdr(v128);
    stack[-1] = v128;
    goto v132;

v84:
    v129 = stack[0];
    v128 = (Lisp_Object)1; /* 0 */
    if (v129 == v128) goto v134;
    v128 = qvalue(elt(env, 1)); /* nil */
    goto v135;

v135:
    if (v128 == nil) goto v136;
    v128 = (Lisp_Object)17; /* 1 */
    stack[0] = v128;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v136:
    v129 = stack[0];
    v128 = (Lisp_Object)1; /* 0 */
    if (v129 == v128) goto v76;
    v128 = qvalue(elt(env, 1)); /* nil */
    goto v137;

v137:
    if (v128 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v128 = (Lisp_Object)-15; /* -1 */
    stack[0] = v128;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v76:
    v128 = stack[-1];
    v128 = qcar(v128);
    goto v137;

v134:
    v128 = stack[-2];
    v128 = qcar(v128);
    goto v135;
/* error exit handlers */
v131:
    popv(4);
    return nil;
}



/* Code for impartf */

static Lisp_Object CC_impartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for impartf");
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
    stack[0] = v0;
/* end of prologue */
    v78 = elt(env, 1); /* i */
    v77 = qvalue(elt(env, 2)); /* kord!* */
    v77 = cons(v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v77; /* kord!* */
    v77 = stack[0];
    fn = elt(env, 7); /* reorder */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    stack[-2] = v77;
    v77 = stack[-2];
    if (!consp(v77)) goto v35;
    v77 = stack[-2];
    v77 = qcar(v77);
    v77 = (consp(v77) ? nil : lisp_true);
    goto v9;

v9:
    if (v77 == nil) goto v6;
    v77 = stack[-2];
    if (!consp(v77)) goto v153;
    v77 = stack[-2];
    v78 = qcar(v77);
    v77 = elt(env, 5); /* cmpxfn */
    v77 = get(v78, v77);
    env = stack[-4];
    if (v77 == nil) goto v154;
    v77 = stack[-2];
    stack[-1] = qcar(v77);
    v77 = stack[-2];
    v77 = qcdr(v77);
    stack[0] = qcdr(v77);
    v77 = stack[-2];
    v78 = qcar(v77);
    v77 = elt(env, 6); /* i2d */
    v78 = get(v78, v77);
    env = stack[-4];
    v77 = (Lisp_Object)1; /* 0 */
    v77 = Lapply1(nil, v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    v77 = qcdr(v77);
    v77 = qcar(v77);
    v77 = list2star(stack[-1], stack[0], v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    fn = elt(env, 8); /* int!-equiv!-chk */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    goto v16;

v16:
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v77); }

v154:
    v77 = qvalue(elt(env, 4)); /* nil */
    goto v16;

v153:
    v77 = qvalue(elt(env, 4)); /* nil */
    goto v16;

v6:
    v77 = stack[-2];
    v77 = qcar(v77);
    v77 = qcar(v77);
    v78 = qcar(v77);
    v77 = elt(env, 1); /* i */
    if (v78 == v77) goto v20;
    v77 = stack[-2];
    v77 = qcar(v77);
    v78 = qcar(v77);
    v77 = (Lisp_Object)17; /* 1 */
    v77 = cons(v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    stack[0] = ncons(v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    v77 = stack[-2];
    v77 = qcar(v77);
    v77 = qcdr(v77);
    v77 = CC_impartf(env, v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    fn = elt(env, 9); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    v77 = stack[-2];
    v77 = qcdr(v77);
    v77 = CC_impartf(env, v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    fn = elt(env, 10); /* addf */
    v77 = (*qfn2(fn))(qenv(fn), stack[0], v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    goto v16;

v20:
    v77 = stack[-2];
    v77 = qcar(v77);
    stack[0] = qcdr(v77);
    v77 = stack[-2];
    v77 = qcdr(v77);
    v77 = CC_impartf(env, v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    fn = elt(env, 10); /* addf */
    v77 = (*qfn2(fn))(qenv(fn), stack[0], v77);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    goto v16;

v35:
    v77 = qvalue(elt(env, 3)); /* t */
    goto v9;
/* error exit handlers */
v130:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
v129:
    popv(5);
    return nil;
}



/* Code for nonpolyp */

static Lisp_Object CC_nonpolyp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonpolyp");
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

v156:
    v151 = stack[-1];
    if (!consp(v151)) goto v14;
    v151 = stack[-1];
    v151 = qcar(v151);
    v151 = (consp(v151) ? nil : lisp_true);
    goto v152;

v152:
    if (v151 == nil) goto v157;
    v151 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v151); }

v157:
    v151 = stack[-1];
    v151 = qcar(v151);
    v151 = qcar(v151);
    v150 = qcar(v151);
    v151 = stack[0];
    if (v150 == v151) goto v33;
    v151 = stack[-1];
    v151 = qcar(v151);
    v151 = qcar(v151);
    v150 = qcar(v151);
    v151 = stack[0];
    fn = elt(env, 3); /* depend!-p */
    v151 = (*qfn2(fn))(qenv(fn), v150, v151);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    goto v95;

v95:
    if (!(v151 == nil)) { popv(3); return onevalue(v151); }
    v151 = stack[-1];
    v151 = qcar(v151);
    v150 = qcdr(v151);
    v151 = stack[0];
    v151 = CC_nonpolyp(env, v150, v151);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    if (!(v151 == nil)) { popv(3); return onevalue(v151); }
    v151 = stack[-1];
    v150 = qcdr(v151);
    v151 = stack[0];
    stack[-1] = v150;
    stack[0] = v151;
    goto v156;

v33:
    v151 = qvalue(elt(env, 2)); /* nil */
    goto v95;

v14:
    v151 = qvalue(elt(env, 1)); /* t */
    goto v152;
/* error exit handlers */
v154:
    popv(3);
    return nil;
}



/* Code for ratpoly_sub */

static Lisp_Object MS_CDECL CC_ratpoly_sub(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v46, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v39, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ratpoly_sub");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_sub");
#endif
    if (stack >= stacklimit)
    {
        push3(v46,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v35 = v46;
    v39 = v1;
    v126 = v0;
/* end of prologue */
    stack[0] = v126;
    v35 = cons(v39, v35);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    {
        Lisp_Object v95 = stack[0];
        popv(2);
        fn = elt(env, 1); /* subsq */
        return (*qfn2(fn))(qenv(fn), v95, v35);
    }
/* error exit handlers */
v125:
    popv(2);
    return nil;
}



/* Code for lowlimitrd */

static Lisp_Object MS_CDECL CC_lowlimitrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lowlimitrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lowlimitrd");
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
    fn = elt(env, 4); /* mathml */
    v157 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-1];
    stack[0] = v157;
    fn = elt(env, 5); /* lex */
    v157 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-1];
    v41 = qvalue(elt(env, 1)); /* char */
    v157 = elt(env, 2); /* (!/ l o w l i m i t) */
    if (equal(v41, v157)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v41 = elt(env, 3); /* "</lowlimit>" */
    v157 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v157 = (*qfn2(fn))(qenv(fn), v41, v157);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v157 = nil;
    { popv(2); return onevalue(v157); }
/* error exit handlers */
v153:
    popv(2);
    return nil;
}



/* Code for ps!:find!-order */

static Lisp_Object CC_psTfindKorder(Lisp_Object env,
                         Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v135, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:find-order");
#endif
    if (stack >= stacklimit)
    {
        push(v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v117 = v1;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v117; /* ps */
    v117 = qvalue(elt(env, 1)); /* ps */
    if (v117 == nil) goto v14;
    v117 = qvalue(elt(env, 1)); /* ps */
    if (symbolp(v117)) goto v140;
    v117 = qvalue(elt(env, 1)); /* ps */
    v134 = v117;
    v117 = v134;
    v117 = (is_number(v117) ? lisp_true : nil);
    if (!(v117 == nil)) goto v126;
    v117 = v134;
    v117 = Lconsp(nil, v117);
    env = stack[-1];
    if (v117 == nil) goto v157;
    v117 = v134;
    v135 = qcar(v117);
    v117 = elt(env, 3); /* !:ps!: */
    if (v135 == v117) goto v148;
    v117 = v134;
    v135 = qcar(v117);
    v117 = elt(env, 4); /* dname */
    v117 = get(v135, v117);
    env = stack[-1];
    goto v126;

v126:
    if (v117 == nil) goto v155;
    v117 = (Lisp_Object)1; /* 0 */
    goto v32;

v32:
    qvalue(elt(env, 1)) = stack[0]; /* ps */
    { popv(2); return onevalue(v117); }

v155:
    v135 = qvalue(elt(env, 1)); /* ps */
    v117 = elt(env, 3); /* !:ps!: */
    if (!consp(v135)) goto v162;
    v135 = qcar(v135);
    if (!(v135 == v117)) goto v162;
    v117 = qvalue(elt(env, 1)); /* ps */
    v117 = qcdr(v117);
    if (symbolp(v117)) goto v2;
    v117 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 8); /* ps!:expression */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    if (!consp(v117)) goto v154;
    v117 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 9); /* ps!:find!-order1 */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    goto v32;

v154:
    v117 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 10); /* ps!:order */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    goto v32;

v2:
    v117 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 11); /* ps!:unknown!-order */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    goto v32;

v162:
    v117 = elt(env, 5); /* "Unexpected form in ps!:find!-order" */
    v135 = v117;
    v117 = v135;
    qvalue(elt(env, 6)) = v117; /* errmsg!* */
    v117 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v117 == nil)) goto v80;
    v117 = v135;
    fn = elt(env, 12); /* lprie */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    goto v80;

v80:
    v117 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    v117 = nil;
    goto v32;

v148:
    v117 = qvalue(elt(env, 2)); /* nil */
    goto v126;

v157:
    v117 = qvalue(elt(env, 2)); /* nil */
    goto v126;

v140:
    v117 = qvalue(elt(env, 1)); /* ps */
    goto v32;

v14:
    v117 = (Lisp_Object)1; /* 0 */
    goto v32;
/* error exit handlers */
v84:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* ps */
    popv(2);
    return nil;
}



/* Code for extbrsea */

static Lisp_Object MS_CDECL CC_extbrsea(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v199, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "extbrsea");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extbrsea");
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
    v198 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v198;
    goto v16;

v16:
    v199 = qvalue(elt(env, 2)); /* rowmax */
    v198 = stack[-1];
    v198 = difference2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    v198 = Lminusp(nil, v198);
    env = stack[-2];
    if (v198 == nil) goto v122;
    fn = elt(env, 8); /* initbrsea */
    v198 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    fn = elt(env, 9); /* extbrsea1 */
    v198 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    goto v102;

v102:
    fn = elt(env, 10); /* expandprod */
    v198 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    v198 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v198;
    goto v202;

v202:
    v199 = qvalue(elt(env, 2)); /* rowmax */
    v198 = stack[-1];
    v198 = difference2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    v198 = Lminusp(nil, v198);
    env = stack[-2];
    if (v198 == nil) goto v203;
    fn = elt(env, 8); /* initbrsea */
    v198 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    fn = elt(env, 9); /* extbrsea1 */
    v198 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    fn = elt(env, 11); /* shrinkprod */
    v198 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    if (!(v198 == nil)) goto v102;
    v198 = nil;
    { popv(3); return onevalue(v198); }

v203:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v199 = qvalue(elt(env, 5)); /* maxvar */
    v198 = stack[-1];
    v198 = plus2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    v199 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v198 = (Lisp_Object)49; /* 3 */
    v199 = *(Lisp_Object *)((char *)v199 + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v198 = (Lisp_Object)-15; /* -1 */
    if (v199 == v198) goto v204;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v199 = qvalue(elt(env, 5)); /* maxvar */
    v198 = stack[-1];
    v198 = plus2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    v199 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v198 = (Lisp_Object)33; /* 2 */
    v199 = *(Lisp_Object *)((char *)v199 + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v198 = elt(env, 7); /* times */
    v198 = (v199 == v198 ? lisp_true : nil);
    goto v205;

v205:
    if (v198 == nil) goto v206;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v199 = qvalue(elt(env, 5)); /* maxvar */
    v198 = stack[-1];
    v198 = plus2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    v200 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v199 = (Lisp_Object)1; /* 0 */
    v198 = qvalue(elt(env, 6)); /* t */
    *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v199/(16/CELL))) = v198;
    goto v207;

v207:
    v198 = stack[-1];
    v198 = add1(v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    stack[-1] = v198;
    goto v202;

v206:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v199 = qvalue(elt(env, 5)); /* maxvar */
    v198 = stack[-1];
    v198 = plus2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    v200 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v199 = (Lisp_Object)1; /* 0 */
    v198 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v199/(16/CELL))) = v198;
    goto v207;

v204:
    v198 = qvalue(elt(env, 3)); /* nil */
    goto v205;

v122:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v199 = qvalue(elt(env, 5)); /* maxvar */
    v198 = stack[-1];
    v198 = plus2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    v199 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v198 = (Lisp_Object)49; /* 3 */
    v199 = *(Lisp_Object *)((char *)v199 + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v198 = (Lisp_Object)-15; /* -1 */
    if (v199 == v198) goto v41;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v199 = qvalue(elt(env, 5)); /* maxvar */
    v198 = stack[-1];
    v198 = plus2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    v199 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v198 = (Lisp_Object)49; /* 3 */
    v199 = *(Lisp_Object *)((char *)v199 + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v198 = (Lisp_Object)-31; /* -2 */
    v198 = (v199 == v198 ? lisp_true : nil);
    goto v157;

v157:
    if (v198 == nil) goto v137;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v199 = qvalue(elt(env, 5)); /* maxvar */
    v198 = stack[-1];
    v198 = plus2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    v200 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v199 = (Lisp_Object)1; /* 0 */
    v198 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v199/(16/CELL))) = v198;
    goto v125;

v125:
    v198 = stack[-1];
    v198 = add1(v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    stack[-1] = v198;
    goto v16;

v137:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v199 = qvalue(elt(env, 5)); /* maxvar */
    v198 = stack[-1];
    v198 = plus2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-2];
    v200 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    v199 = (Lisp_Object)1; /* 0 */
    v198 = qvalue(elt(env, 6)); /* t */
    *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v199/(16/CELL))) = v198;
    goto v125;

v41:
    v198 = qvalue(elt(env, 6)); /* t */
    goto v157;
/* error exit handlers */
v201:
    popv(3);
    return nil;
}



/* Code for !*a2kwoweight */

static Lisp_Object CC_Ha2kwoweight(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *a2kwoweight");
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
    v153 = qvalue(elt(env, 1)); /* t */
    v22 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = qvalue(elt(env, 3)); /* !*uncached */
    qvalue(elt(env, 3)) = v153; /* !*uncached */
    stack[-1] = qvalue(elt(env, 4)); /* wtl!* */
    qvalue(elt(env, 4)) = v22; /* wtl!* */
    v22 = stack[-2];
    fn = elt(env, 6); /* simp!* */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-4];
    stack[0] = v22;
    v22 = stack[0];
    fn = elt(env, 7); /* kernp */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-4];
    if (v22 == nil) goto v127;
    v22 = stack[0];
    v22 = qcar(v22);
    v22 = qcar(v22);
    v22 = qcar(v22);
    v22 = qcar(v22);
    goto v138;

v138:
    qvalue(elt(env, 4)) = stack[-1]; /* wtl!* */
    qvalue(elt(env, 3)) = stack[-3]; /* !*uncached */
    { popv(5); return onevalue(v22); }

v127:
    v153 = stack[-2];
    v22 = elt(env, 5); /* kernel */
    fn = elt(env, 8); /* typerr */
    v22 = (*qfn2(fn))(qenv(fn), v153, v22);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-4];
    goto v138;
/* error exit handlers */
v13:
    env = stack[-4];
    qvalue(elt(env, 4)) = stack[-1]; /* wtl!* */
    qvalue(elt(env, 3)) = stack[-3]; /* !*uncached */
    popv(5);
    return nil;
}



/* Code for vdpmember */

static Lisp_Object CC_vdpmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpmember");
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

v32:
    v157 = stack[0];
    if (v157 == nil) goto v152;
    v41 = stack[-1];
    v157 = stack[0];
    v157 = qcar(v157);
    fn = elt(env, 2); /* vdpequal */
    v157 = (*qfn2(fn))(qenv(fn), v41, v157);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-2];
    if (!(v157 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v157 = stack[0];
    v157 = qcdr(v157);
    stack[0] = v157;
    goto v32;

v152:
    v157 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v157); }
/* error exit handlers */
v40:
    popv(3);
    return nil;
}



/* Code for remove_critical_pairs */

static Lisp_Object CC_remove_critical_pairs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove_critical_pairs");
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
    stack[0] = v1;
    v15 = v0;
/* end of prologue */
    v31 = v15;
    if (v31 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v31 = stack[0];
    fn = elt(env, 1); /* remove_items */
    v15 = (*qfn2(fn))(qenv(fn), v31, v15);
    nil = C_nil;
    if (exception_pending()) goto v35;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v35:
    popv(1);
    return nil;
}



/* Code for gf2bf */

static Lisp_Object CC_gf2bf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v82, v208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gf2bf");
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
    goto v32;

v32:
    v119 = stack[0];
    if (v119 == nil) goto v209;
    v119 = stack[0];
    if (!consp(v119)) goto v140;
    v82 = stack[0];
    v119 = elt(env, 1); /* !:rd!: */
    if (!consp(v82)) goto v7;
    v82 = qcar(v82);
    if (!(v82 == v119)) goto v7;
    v119 = stack[0];
    v119 = qcdr(v119);
    v119 = (consp(v119) ? nil : lisp_true);
    v119 = (v119 == nil ? lisp_true : nil);
    goto v121;

v121:
    if (v119 == nil) goto v210;
    v82 = stack[-1];
    v119 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v82, v119);
    }

v210:
    v119 = stack[0];
    v119 = qcar(v119);
    v82 = CC_gf2bf(env, v119);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    v119 = stack[-1];
    v119 = cons(v82, v119);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    stack[-1] = v119;
    v119 = stack[0];
    v119 = qcdr(v119);
    stack[0] = v119;
    goto v32;

v7:
    v119 = qvalue(elt(env, 2)); /* nil */
    goto v121;

v140:
    v119 = stack[0];
    v119 = Lfloatp(nil, v119);
    env = stack[-2];
    if (v119 == nil) goto v13;
    v119 = stack[0];
    fn = elt(env, 4); /* fl2bf */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    {
        Lisp_Object v141 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v141, v119);
    }

v13:
    v119 = stack[0];
    if (!consp(v119)) goto v24;
    v119 = stack[0];
    goto v36;

v36:
    fn = elt(env, 5); /* csl_normbf */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    {
        Lisp_Object v211 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v211, v119);
    }

v24:
    v119 = stack[0];
    v119 = integerp(v119);
    if (v119 == nil) goto v212;
    v208 = elt(env, 1); /* !:rd!: */
    v82 = stack[0];
    v119 = (Lisp_Object)1; /* 0 */
    v119 = list2star(v208, v82, v119);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    goto v36;

v212:
    v119 = stack[0];
    fn = elt(env, 6); /* read!:num */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    goto v36;

v209:
    v119 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v119);
    }
/* error exit handlers */
v98:
    popv(3);
    return nil;
}



/* Code for !:quotient */

static Lisp_Object CC_Tquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v76, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :quotient");
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
    v76 = v1;
    stack[0] = v0;
/* end of prologue */
    v137 = stack[0];
    if (v137 == nil) goto v14;
    v101 = stack[0];
    v137 = (Lisp_Object)1; /* 0 */
    v137 = (v101 == v137 ? lisp_true : nil);
    goto v152;

v152:
    if (v137 == nil) goto v43;
    v137 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v137); }

v43:
    v137 = v76;
    if (v137 == nil) goto v157;
    v101 = v76;
    v137 = (Lisp_Object)1; /* 0 */
    v137 = (v101 == v137 ? lisp_true : nil);
    goto v159;

v159:
    if (v137 == nil) goto v95;
    v137 = elt(env, 3); /* "Zero divisor" */
    v76 = v137;
    v137 = v76;
    qvalue(elt(env, 4)) = v137; /* errmsg!* */
    v137 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v137 == nil)) goto v28;
    v137 = v76;
    fn = elt(env, 9); /* lprie */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    goto v28;

v28:
    v137 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v143;
    v137 = nil;
    { popv(2); return onevalue(v137); }

v95:
    v137 = stack[0];
    if (!consp(v137)) goto v146;
    v137 = qvalue(elt(env, 2)); /* nil */
    goto v196;

v196:
    if (v137 == nil) goto v82;
    v137 = qvalue(elt(env, 6)); /* dmode!* */
    if (v137 == nil) goto v5;
    v137 = v76;
    fn = elt(env, 10); /* !:recip */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    v76 = v137;
    if (!consp(v76)) goto v79;
    v101 = stack[0];
    v76 = v137;
    v137 = elt(env, 7); /* times */
    {
        popv(2);
        fn = elt(env, 11); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v101, v76, v137);
    }

v79:
    v76 = stack[0];
    popv(2);
    return times2(v76, v137);

v5:
    v137 = stack[0];
    popv(2);
    return quot2(v137, v76);

v82:
    v101 = stack[0];
    v137 = elt(env, 8); /* quotient */
    {
        popv(2);
        fn = elt(env, 11); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v101, v76, v137);
    }

v146:
    v137 = v76;
    v137 = (consp(v137) ? nil : lisp_true);
    goto v196;

v157:
    v137 = qvalue(elt(env, 1)); /* t */
    goto v159;

v14:
    v137 = qvalue(elt(env, 1)); /* t */
    goto v152;
/* error exit handlers */
v143:
    popv(2);
    return nil;
}



/* Code for propagator */

static Lisp_Object CC_propagator(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for propagator");
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
    v123 = stack[-1];
    if (v123 == nil) goto v32;
    v123 = stack[-1];
    fn = elt(env, 2); /* repeatsp */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    if (!(v123 == nil)) goto v14;
    v123 = stack[0];
    fn = elt(env, 2); /* repeatsp */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    if (!(v123 == nil)) goto v14;
    stack[-2] = elt(env, 1); /* plus */
    v123 = stack[0];
    fn = elt(env, 3); /* permutations */
    v124 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    v123 = stack[0];
    fn = elt(env, 4); /* propag */
    v123 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v24;
    {
        Lisp_Object v37 = stack[-2];
        popv(4);
        return cons(v37, v123);
    }

v14:
    v123 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v123); }

v32:
    v123 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v123); }
/* error exit handlers */
v24:
    popv(4);
    return nil;
}



/* Code for lieninstruc */

static Lisp_Object CC_lieninstruc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v227, v228, v229;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lieninstruc");
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
    v184 = (Lisp_Object)17; /* 1 */
    stack[-5] = v184;
    goto v16;

v16:
    stack[0] = elt(env, 1); /* difference */
    v228 = elt(env, 1); /* difference */
    v227 = stack[-4];
    v184 = (Lisp_Object)17; /* 1 */
    v184 = list3(v228, v227, v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v227 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    v184 = stack[-5];
    v184 = list3(stack[0], v227, v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    if (v184 == nil) goto v138;
    v184 = nil;
    { popv(7); return onevalue(v184); }

v138:
    v184 = stack[-5];
    v184 = add1(v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    stack[-3] = v184;
    goto v33;

v33:
    stack[0] = elt(env, 1); /* difference */
    v184 = stack[-4];
    fn = elt(env, 7); /* aeval!* */
    v227 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    v184 = stack[-3];
    v184 = list3(stack[0], v227, v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    if (v184 == nil) goto v24;
    v184 = stack[-5];
    v228 = elt(env, 6); /* plus */
    v227 = v184;
    v184 = (Lisp_Object)17; /* 1 */
    v184 = list3(v228, v227, v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    stack[-5] = v184;
    goto v16;

v24:
    v184 = (Lisp_Object)17; /* 1 */
    stack[-2] = v184;
    goto v2;

v2:
    stack[0] = elt(env, 1); /* difference */
    v184 = stack[-4];
    fn = elt(env, 7); /* aeval!* */
    v227 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    v184 = stack[-2];
    v184 = list3(stack[0], v227, v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    if (v184 == nil) goto v79;
    v184 = stack[-3];
    v228 = elt(env, 6); /* plus */
    v227 = v184;
    v184 = (Lisp_Object)17; /* 1 */
    v184 = list3(v228, v227, v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    stack[-3] = v184;
    goto v33;

v79:
    v229 = elt(env, 3); /* lie_cc */
    v228 = stack[-5];
    v227 = stack[-3];
    v184 = stack[-2];
    stack[0] = list4(v229, v228, v227, v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    v229 = elt(env, 4); /* lienstrucin */
    v228 = stack[-5];
    v227 = stack[-3];
    v184 = stack[-2];
    v184 = list4(v229, v228, v227, v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    fn = elt(env, 9); /* setk */
    v184 = (*qfn2(fn))(qenv(fn), stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    v229 = elt(env, 3); /* lie_cc */
    v228 = stack[-3];
    v227 = stack[-5];
    v184 = stack[-2];
    stack[-1] = list4(v229, v228, v227, v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    stack[0] = elt(env, 5); /* minus */
    v229 = elt(env, 4); /* lienstrucin */
    v228 = stack[-5];
    v227 = stack[-3];
    v184 = stack[-2];
    v184 = list4(v229, v228, v227, v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    v184 = list2(stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    fn = elt(env, 9); /* setk */
    v184 = (*qfn2(fn))(qenv(fn), stack[-1], v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    v184 = stack[-2];
    v228 = elt(env, 6); /* plus */
    v227 = v184;
    v184 = (Lisp_Object)17; /* 1 */
    v184 = list3(v228, v227, v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-6];
    stack[-2] = v184;
    goto v2;
/* error exit handlers */
v230:
    popv(7);
    return nil;
}



/* Code for get_rep_matrix_entry */

static Lisp_Object MS_CDECL CC_get_rep_matrix_entry(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v46, Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v158, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "get_rep_matrix_entry");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_rep_matrix_entry");
#endif
    if (stack >= stacklimit)
    {
        push4(v38,v46,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v46,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v46;
    v158 = v1;
    v95 = v0;
/* end of prologue */
    fn = elt(env, 1); /* get_rep_matrix_in */
    v159 = (*qfn2(fn))(qenv(fn), v158, v95);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    v158 = stack[-1];
    v95 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* get!+mat!+entry */
        return (*qfnn(fn))(qenv(fn), 3, v159, v158, v95);
    }
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



/* Code for mri_simplfloor1 */

static Lisp_Object CC_mri_simplfloor1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_simplfloor1");
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
    v121 = stack[-1];
    if (!consp(v121)) goto v140;
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = (consp(v121) ? nil : lisp_true);
    goto v91;

v91:
    if (!(v121 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    fn = elt(env, 2); /* mri_simplfloor */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    stack[0] = v121;
    v121 = stack[-1];
    v121 = qcdr(v121);
    fn = elt(env, 2); /* mri_simplfloor */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    stack[-2] = v121;
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v121 = qcar(v121);
    fn = elt(env, 3); /* mri_irsplit */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v160 = v121;
    v160 = qcar(v160);
    v121 = qcdr(v121);
    fn = elt(env, 4); /* addf */
    v160 = (*qfn2(fn))(qenv(fn), v160, v121);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = qcar(v121);
    v121 = qcdr(v121);
    fn = elt(env, 5); /* exptf */
    v121 = (*qfn2(fn))(qenv(fn), v160, v121);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    fn = elt(env, 6); /* multf */
    v160 = (*qfn2(fn))(qenv(fn), stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v121 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v160, v121);
    }

v140:
    v121 = qvalue(elt(env, 1)); /* t */
    goto v91;
/* error exit handlers */
v151:
    popv(4);
    return nil;
}



/* Code for iv_cutcongs2 */

static Lisp_Object CC_iv_cutcongs2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v160, v3;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for iv_cutcongs2");
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
    stack[0] = v1;
    v3 = v0;
/* end of prologue */
    v121 = stack[0];
    v121 = qcar(v121);
    v160 = qcar(v121);
    v121 = elt(env, 1); /* cong */
    if (v160 == v121) goto v157;
    v121 = stack[0];
    v121 = qcdr(v121);
    v160 = v3;
    v160 = difference2(v121, v160);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    v160 = Cremainder(v160, v121);
    nil = C_nil;
    if (exception_pending()) goto v5;
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (v160 == v121 ? lisp_true : nil);
    v121 = (v121 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v121); }

v157:
    v121 = stack[0];
    v121 = qcdr(v121);
    v160 = v3;
    v160 = difference2(v121, v160);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    v160 = Cremainder(v160, v121);
    nil = C_nil;
    if (exception_pending()) goto v5;
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (v160 == v121 ? lisp_true : nil);
    { popv(2); return onevalue(v121); }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for applyml */

static Lisp_Object MS_CDECL CC_applyml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "applyml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applyml");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 8); /* lex */
    v233 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[0];
    v233 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 9); /* compress!* */
    v147 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[0];
    v233 = qvalue(elt(env, 2)); /* rdlist!* */
    v147 = Lassoc(nil, v147, v233);
    v233 = v147;
    if (v147 == nil) goto v13;
    v147 = v233;
    v147 = qcdr(v147);
    v147 = qcar(v147);
    v233 = qcdr(v233);
    v233 = qcdr(v233);
    {
        popv(1);
        fn = elt(env, 10); /* apply */
        return (*qfn2(fn))(qenv(fn), v147, v233);
    }

v13:
    v147 = qvalue(elt(env, 1)); /* char */
    v233 = elt(env, 3); /* (i d e n t !/) */
    if (equal(v147, v233)) goto v87;
    v147 = qvalue(elt(env, 1)); /* char */
    v233 = elt(env, 5); /* (c o m p o s e !/) */
    v233 = (equal(v147, v233) ? lisp_true : nil);
    goto v86;

v86:
    if (v233 == nil) goto v197;
    v233 = qvalue(elt(env, 6)); /* nil */
    { popv(1); return onevalue(v233); }

v197:
    v147 = qvalue(elt(env, 1)); /* char */
    v233 = elt(env, 7); /* (i n v e r s e !/) */
    if (equal(v147, v233)) goto v161;
    v233 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 9); /* compress!* */
    v147 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[0];
    v233 = (Lisp_Object)273; /* 17 */
    fn = elt(env, 11); /* errorml */
    v233 = (*qfn2(fn))(qenv(fn), v147, v233);
    nil = C_nil;
    if (exception_pending()) goto v154;
    v233 = nil;
    { popv(1); return onevalue(v233); }

v161:
    v233 = qvalue(elt(env, 4)); /* t */
    { popv(1); return onevalue(v233); }

v87:
    v233 = qvalue(elt(env, 4)); /* t */
    goto v86;
/* error exit handlers */
v154:
    popv(1);
    return nil;
}



/* Code for splitrec */

static Lisp_Object MS_CDECL CC_splitrec(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v46, Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v240, v203, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "splitrec");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for splitrec");
#endif
    if (stack >= stacklimit)
    {
        push4(v38,v46,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v46,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v38;
    stack[-3] = v46;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v239 = stack[-5];
    if (!consp(v239)) goto v48;
    v239 = stack[-5];
    v239 = qcar(v239);
    v239 = (consp(v239) ? nil : lisp_true);
    goto v138;

v138:
    if (v239 == nil) goto v4;
    v240 = stack[-5];
    v239 = stack[-3];
    fn = elt(env, 4); /* multf */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    stack[-3] = v239;
    v240 = stack[-2];
    v239 = qvalue(elt(env, 2)); /* list!-pq */
    v239 = Lassoc(nil, v240, v239);
    v240 = v239;
    if (v239 == nil) goto v212;
    stack[0] = v240;
    v239 = v240;
    v240 = qcdr(v239);
    v239 = stack[-3];
    fn = elt(env, 5); /* addf */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    v239 = Lrplacd(nil, stack[0], v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    goto v40;

v40:
    v239 = nil;
    { popv(8); return onevalue(v239); }

v212:
    v203 = stack[-2];
    v240 = stack[-3];
    v239 = qvalue(elt(env, 2)); /* list!-pq */
    v239 = acons(v203, v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    qvalue(elt(env, 2)) = v239; /* list!-pq */
    goto v40;

v4:
    v239 = stack[-5];
    v239 = qcar(v239);
    v239 = qcar(v239);
    v240 = qcar(v239);
    v239 = stack[-4];
    if (!consp(v240)) goto v84;
    v240 = qcar(v240);
    if (!(v240 == v239)) goto v84;
    v239 = stack[-5];
    v239 = qcar(v239);
    v239 = qcar(v239);
    v239 = qcar(v239);
    v240 = Llength(nil, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    v239 = (Lisp_Object)33; /* 2 */
    v239 = (Lisp_Object)greaterp2(v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    v239 = v239 ? lisp_true : nil;
    env = stack[-7];
    goto v97;

v97:
    if (v239 == nil) goto v78;
    v239 = stack[-5];
    v239 = qcar(v239);
    stack[-6] = qcdr(v239);
    stack[-1] = stack[-4];
    stack[0] = stack[-3];
    v239 = stack[-5];
    v239 = qcar(v239);
    v240 = qcar(v239);
    v239 = stack[-2];
    v239 = cons(v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    v239 = CC_splitrec(env, 4, stack[-6], stack[-1], stack[0], v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    goto v147;

v147:
    v239 = stack[-5];
    v239 = qcdr(v239);
    if (v239 == nil) goto v68;
    v239 = stack[-5];
    v217 = qcdr(v239);
    v203 = stack[-4];
    v240 = stack[-3];
    v239 = stack[-2];
    v239 = CC_splitrec(env, 4, v217, v203, v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    goto v68;

v68:
    v239 = nil;
    { popv(8); return onevalue(v239); }

v78:
    v239 = stack[-5];
    v239 = qcar(v239);
    stack[-1] = qcdr(v239);
    stack[0] = stack[-4];
    v239 = stack[-5];
    v239 = qcar(v239);
    v240 = qcar(v239);
    v239 = stack[-3];
    v239 = cons(v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    v240 = ncons(v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    v239 = stack[-2];
    v239 = CC_splitrec(env, 4, stack[-1], stack[0], v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    goto v147;

v84:
    v239 = qvalue(elt(env, 3)); /* nil */
    goto v97;

v48:
    v239 = qvalue(elt(env, 1)); /* t */
    goto v138;
/* error exit handlers */
v241:
    popv(8);
    return nil;
}



/* Code for get_num_part */

static Lisp_Object CC_get_num_part(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_num_part");
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
    goto v138;

v138:
    v105 = stack[0];
    v70 = (Lisp_Object)1; /* 0 */
    if (v105 == v70) goto v31;
    v70 = stack[0];
    if (is_number(v70)) goto v153;
    v70 = stack[0];
    if (!consp(v70)) goto v122;
    v105 = stack[0];
    v70 = elt(env, 1); /* !:rd!: */
    if (!consp(v105)) goto v120;
    v105 = qcar(v105);
    if (!(v105 == v70)) goto v120;
    v70 = stack[0];
    v70 = qcdr(v70);
    if (!consp(v70)) goto v232;
    v70 = stack[0];
    fn = elt(env, 5); /* bf2flr */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    {
        Lisp_Object v239 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v239, v70);
    }

v232:
    v105 = stack[-1];
    v70 = stack[0];
    v70 = qcdr(v70);
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v105, v70);
    }

v120:
    v105 = stack[0];
    v70 = elt(env, 2); /* !:dn!: */
    if (!consp(v105)) goto v84;
    v105 = qcar(v105);
    if (!(v105 == v70)) goto v84;
    v70 = stack[0];
    v70 = qcdr(v70);
    fn = elt(env, 7); /* rdwrap2 */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    {
        Lisp_Object v240 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v240, v70);
    }

v84:
    v105 = stack[0];
    v70 = elt(env, 3); /* minus */
    if (!consp(v105)) goto v163;
    v105 = qcar(v105);
    if (!(v105 == v70)) goto v163;
    v70 = stack[0];
    v70 = qcdr(v70);
    v70 = qcar(v70);
    v70 = CC_get_num_part(env, v70);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    v105 = v70;
    if (is_number(v105)) goto v142;
    v105 = elt(env, 3); /* minus */
    v70 = list2(v105, v70);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    goto v98;

v98:
    {
        Lisp_Object v203 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v203, v70);
    }

v142:
    v70 = Lfloat(nil, v70);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    v70 = negate(v70);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    goto v98;

v163:
    v105 = stack[0];
    v70 = elt(env, 4); /* expt */
    if (!consp(v105)) goto v245;
    v105 = qcar(v105);
    if (!(v105 == v70)) goto v245;
    v70 = stack[0];
    fn = elt(env, 8); /* rdwrap!-expt */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    {
        Lisp_Object v217 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v217, v70);
    }

v245:
    v70 = stack[0];
    v70 = qcar(v70);
    v105 = CC_get_num_part(env, v70);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    v70 = stack[-1];
    v70 = cons(v105, v70);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    stack[-1] = v70;
    v70 = stack[0];
    v70 = qcdr(v70);
    stack[0] = v70;
    goto v138;

v122:
    v105 = stack[-1];
    v70 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v105, v70);
    }

v153:
    v70 = stack[0];
    v70 = Lfloat(nil, v70);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    {
        Lisp_Object v218 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v218, v70);
    }

v31:
    v105 = stack[-1];
    v70 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v105, v70);
    }
/* error exit handlers */
v235:
    popv(3);
    return nil;
}



/* Code for let2 */

static Lisp_Object MS_CDECL CC_let2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v46, Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v260, v261, v262, v263, v264;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "let2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for let2");
#endif
    if (stack >= stacklimit)
    {
        push4(v38,v46,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v46,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v38;
    stack[-4] = v46;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    v260 = stack[-6];
    fn = elt(env, 16); /* getrtype */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    stack[-1] = v260;
    if (v260 == nil) goto v44;
    v261 = stack[-1];
    v260 = elt(env, 1); /* typeletfn */
    v260 = get(v261, v260);
    env = stack[-8];
    v262 = v260;
    if (v260 == nil) goto v44;
    v261 = v262;
    v260 = elt(env, 2); /* direct */
    v260 = Lflagp(nil, v261, v260);
    env = stack[-8];
    if (v260 == nil) goto v44;
    stack[-2] = v262;
    stack[-4] = stack[-6];
    stack[0] = stack[-5];
    v260 = stack[-5];
    fn = elt(env, 16); /* getrtype */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    v260 = list2(stack[-3], v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    v260 = list3star(stack[-4], stack[0], stack[-1], v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    {
        Lisp_Object v266 = stack[-2];
        popv(9);
        fn = elt(env, 17); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v266, v260);
    }

v44:
    v260 = stack[-5];
    fn = elt(env, 16); /* getrtype */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    stack[-1] = v260;
    if (v260 == nil) goto v141;
    v261 = stack[-1];
    v260 = elt(env, 1); /* typeletfn */
    v260 = get(v261, v260);
    env = stack[-8];
    v262 = v260;
    if (v260 == nil) goto v141;
    v261 = v262;
    v260 = elt(env, 2); /* direct */
    v260 = Lflagp(nil, v261, v260);
    env = stack[-8];
    if (v260 == nil) goto v141;
    stack[-2] = v262;
    stack[-4] = stack[-6];
    stack[0] = qvalue(elt(env, 3)); /* nil */
    v261 = stack[-3];
    v260 = stack[-1];
    v260 = list2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    v260 = list3star(stack[-4], stack[-5], stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    {
        Lisp_Object v267 = stack[-2];
        popv(9);
        fn = elt(env, 17); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v267, v260);
    }

v141:
    v261 = qvalue(elt(env, 4)); /* frasc!* */
    v260 = stack[-6];
    v260 = Lsubla(nil, v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    stack[-2] = v260;
    v261 = stack[-2];
    v260 = stack[-6];
    if (equal(v261, v260)) goto v68;
    v260 = stack[-2];
    if (!consp(v260)) goto v129;
    v260 = qvalue(elt(env, 7)); /* t */
    stack[-7] = v260;
    v260 = stack[-2];
    stack[-6] = v260;
    goto v68;

v68:
    v261 = qvalue(elt(env, 4)); /* frasc!* */
    v260 = stack[-5];
    v260 = Lsubla(nil, v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    stack[-2] = v260;
    v261 = stack[-2];
    v260 = stack[-5];
    if (equal(v261, v260)) goto v73;
    v260 = stack[-2];
    stack[-5] = v260;
    v261 = stack[-5];
    v260 = elt(env, 8); /* !*sq!* */
    if (!consp(v261)) goto v73;
    v261 = qcar(v261);
    if (!(v261 == v260)) goto v73;
    v260 = stack[-5];
    v260 = qcdr(v260);
    v260 = qcar(v260);
    fn = elt(env, 18); /* prepsq!* */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    stack[-5] = v260;
    goto v73;

v73:
    v261 = qvalue(elt(env, 9)); /* frlis!* */
    v260 = qvalue(elt(env, 10)); /* mcond!* */
    fn = elt(env, 19); /* smemql */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    stack[-2] = v260;
    v261 = qvalue(elt(env, 9)); /* frlis!* */
    v260 = stack[-6];
    fn = elt(env, 19); /* smemql */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    stack[-1] = v260;
    v261 = stack[-2];
    v260 = stack[-1];
    fn = elt(env, 20); /* setdiff */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    v262 = v260;
    if (!(v260 == nil)) goto v268;
    v261 = qvalue(elt(env, 9)); /* frlis!* */
    v260 = stack[-5];
    fn = elt(env, 19); /* smemql */
    v261 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    v260 = stack[-2];
    fn = elt(env, 20); /* setdiff */
    stack[0] = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    v261 = stack[-1];
    v260 = stack[-2];
    fn = elt(env, 20); /* setdiff */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    fn = elt(env, 20); /* setdiff */
    v260 = (*qfn2(fn))(qenv(fn), stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    v262 = v260;
    if (!(v260 == nil)) goto v268;
    v260 = stack[-6];
    if (!consp(v260)) goto v269;
    v260 = stack[-6];
    v261 = qcar(v260);
    v260 = elt(env, 14); /* getel */
    if (v261 == v260) goto v270;
    v260 = stack[-6];
    v261 = qcar(v260);
    v260 = elt(env, 15); /* immediate */
    v260 = Lflagp(nil, v261, v260);
    env = stack[-8];
    if (v260 == nil) goto v269;
    v260 = stack[-6];
    fn = elt(env, 21); /* reval */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    stack[-6] = v260;
    goto v269;

v269:
    v264 = stack[-6];
    v263 = stack[-5];
    v262 = stack[-4];
    v261 = stack[-3];
    v260 = stack[-7];
    {
        popv(9);
        fn = elt(env, 22); /* let3 */
        return (*qfnn(fn))(qenv(fn), 5, v264, v263, v262, v261, v260);
    }

v270:
    v260 = stack[-6];
    v260 = qcdr(v260);
    v260 = qcar(v260);
    fn = elt(env, 23); /* eval */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    stack[-6] = v260;
    goto v269;

v268:
    v260 = elt(env, 11); /* "Unmatched free variable(s)" */
    v261 = v262;
    v260 = cons(v260, v261);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    fn = elt(env, 24); /* lprie */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-8];
    v260 = elt(env, 12); /* hold */
    qvalue(elt(env, 13)) = v260; /* erfg!* */
    v260 = qvalue(elt(env, 3)); /* nil */
    { popv(9); return onevalue(v260); }

v129:
    v264 = elt(env, 5); /* "Substitution for" */
    v263 = stack[-6];
    v262 = elt(env, 6); /* "not allowed" */
    v261 = qvalue(elt(env, 3)); /* nil */
    v260 = qvalue(elt(env, 7)); /* t */
    {
        popv(9);
        fn = elt(env, 25); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v264, v263, v262, v261, v260);
    }
/* error exit handlers */
v265:
    popv(9);
    return nil;
}



/* Code for r2oreaction */

static Lisp_Object MS_CDECL CC_r2oreaction(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v46, Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v68, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "r2oreaction");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2oreaction");
#endif
    if (stack >= stacklimit)
    {
        push4(v38,v46,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v46,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v38;
    v69 = v46;
    stack[-5] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-6] = v69;
    v69 = stack[-1];
    stack[-2] = v69;
    goto v140;

v140:
    v69 = stack[-2];
    if (v69 == nil) goto v91;
    v69 = stack[-2];
    v69 = qcar(v69);
    stack[0] = elt(env, 2); /* times */
    stack[-3] = stack[-6];
    v58 = elt(env, 3); /* expt */
    v68 = v69;
    v68 = qcdr(v68);
    v69 = qcar(v69);
    v69 = list3(v58, v68, v69);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v69 = list3(stack[0], stack[-3], v69);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    fn = elt(env, 6); /* aeval */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[-6] = v69;
    v69 = stack[-2];
    v69 = qcdr(v69);
    stack[-2] = v69;
    goto v140;

v91:
    v69 = stack[-1];
    stack[-3] = v69;
    goto v11;

v11:
    v69 = stack[-3];
    if (v69 == nil) goto v10;
    v69 = stack[-3];
    v69 = qcar(v69);
    v68 = v69;
    v58 = qcdr(v68);
    v68 = stack[-4];
    v68 = Lassoc(nil, v58, v68);
    stack[-2] = v68;
    stack[-1] = elt(env, 4); /* difference */
    stack[0] = qcdr(v68);
    v58 = elt(env, 2); /* times */
    v68 = stack[-6];
    v69 = qcar(v69);
    v69 = list3(v58, v68, v69);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v69 = list3(stack[-1], stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    fn = elt(env, 7); /* reval */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v69 = Lrplacd(nil, stack[-2], v69);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v69 = stack[-3];
    v69 = qcdr(v69);
    stack[-3] = v69;
    goto v11;

v10:
    v69 = stack[-5];
    stack[-3] = v69;
    goto v209;

v209:
    v69 = stack[-3];
    if (v69 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    v69 = stack[-3];
    v69 = qcar(v69);
    v68 = v69;
    v58 = qcdr(v68);
    v68 = stack[-4];
    v68 = Lassoc(nil, v58, v68);
    stack[-2] = v68;
    stack[-1] = elt(env, 5); /* plus */
    stack[0] = qcdr(v68);
    v58 = elt(env, 2); /* times */
    v68 = stack[-6];
    v69 = qcar(v69);
    v69 = list3(v58, v68, v69);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v69 = list3(stack[-1], stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    fn = elt(env, 7); /* reval */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v69 = Lrplacd(nil, stack[-2], v69);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v69 = stack[-3];
    v69 = qcdr(v69);
    stack[-3] = v69;
    goto v209;
/* error exit handlers */
v205:
    popv(8);
    return nil;
}



/* Code for color!-roads */

static Lisp_Object CC_colorKroads(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v142, v271;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for color-roads");
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
    stack[-4] = v1;
    v271 = v0;
/* end of prologue */
    v144 = stack[-4];
    v144 = qcar(v144);
    v142 = qcar(v144);
    v144 = v271;
    v144 = Lassoc(nil, v142, v144);
    v144 = qcdr(v144);
    stack[-1] = v144;
    v144 = stack[-4];
    v144 = qcdr(v144);
    v144 = qcar(v144);
    v142 = qcar(v144);
    v144 = v271;
    v144 = Lassoc(nil, v142, v144);
    v144 = qcdr(v144);
    stack[0] = v144;
    v144 = stack[-4];
    v144 = qcdr(v144);
    v144 = qcdr(v144);
    v144 = qcar(v144);
    v144 = qcar(v144);
    v142 = v271;
    v144 = Lassoc(nil, v144, v142);
    v144 = qcdr(v144);
    stack[-5] = v144;
    stack[-2] = stack[-1];
    v142 = stack[0];
    v144 = stack[-5];
    v144 = plus2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    v142 = plus2(stack[-2], v144);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    v144 = (Lisp_Object)33; /* 2 */
    v144 = quot2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    stack[-2] = v144;
    v142 = stack[-2];
    v144 = stack[-1];
    v144 = difference2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    stack[-1] = v144;
    v142 = stack[-2];
    v144 = stack[0];
    v144 = difference2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    stack[0] = v144;
    v142 = stack[-2];
    v144 = stack[-5];
    v144 = difference2(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    stack[-5] = v144;
    v144 = stack[-4];
    v144 = qcar(v144);
    stack[-3] = qcar(v144);
    stack[-2] = stack[-1];
    v144 = stack[-4];
    v144 = qcdr(v144);
    v144 = qcar(v144);
    stack[-1] = qcar(v144);
    v144 = stack[-4];
    v144 = qcdr(v144);
    v144 = qcdr(v144);
    v144 = qcar(v144);
    v142 = qcar(v144);
    v144 = stack[-5];
    v144 = cons(v142, v144);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    v144 = acons(stack[-1], stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v78;
    {
        Lisp_Object v100 = stack[-3];
        Lisp_Object v190 = stack[-2];
        popv(7);
        return acons(v100, v190, v144);
    }
/* error exit handlers */
v78:
    popv(7);
    return nil;
}



/* Code for prsum */

static Lisp_Object CC_prsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v33, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prsum");
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
    goto v43;

v43:
    v28 = stack[-1];
    if (v28 == nil) goto v14;
    v28 = stack[0];
    v28 = qcar(v28);
    if (v28 == nil) goto v44;
    v28 = stack[-1];
    v33 = qcar(v28);
    v28 = (Lisp_Object)17; /* 1 */
    v34 = cons(v33, v28);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    v28 = stack[0];
    v33 = qcar(v28);
    v28 = stack[-2];
    v28 = acons(v34, v33, v28);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    stack[-2] = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    goto v43;

v44:
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    goto v43;

v14:
    v28 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v28);
    }
/* error exit handlers */
v45:
    popv(4);
    return nil;
}



/* Code for red_redpol */

static Lisp_Object CC_red_redpol(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_redpol");
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
    v40 = v1;
    stack[0] = v0;
/* end of prologue */
    fn = elt(env, 2); /* red_prepare */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v86 = qvalue(elt(env, 1)); /* !*red_total */
    if (v86 == nil) goto v95;
    v86 = stack[0];
    fn = elt(env, 3); /* red_totalred */
    v40 = (*qfn2(fn))(qenv(fn), v86, v40);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    goto v138;

v138:
    {
        popv(2);
        fn = elt(env, 4); /* red_extract */
        return (*qfn1(fn))(qenv(fn), v40);
    }

v95:
    v86 = stack[0];
    fn = elt(env, 5); /* red_topred */
    v40 = (*qfn2(fn))(qenv(fn), v86, v40);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    goto v138;
/* error exit handlers */
v12:
    popv(2);
    return nil;
}



/* Code for out_of_range */

static Lisp_Object MS_CDECL CC_out_of_range(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v46, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "out_of_range");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for out_of_range");
#endif
    if (stack >= stacklimit)
    {
        push3(v46,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    stack[-1] = v1;
    v120 = v0;
/* end of prologue */
    v195 = stack[-1];
    v195 = integerp(v195);
    if (v195 == nil) goto v49;
    v195 = v120;
    fn = elt(env, 4); /* flattens1 */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    fn = elt(env, 5); /* extract_numid */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    stack[-2] = v195;
    v195 = stack[0];
    if (v195 == nil) goto v9;
    v195 = stack[0];
    goto v31;

v31:
    stack[0] = v195;
    goto v157;

v157:
    v195 = stack[-2];
    if (v195 == nil) goto v159;
    v120 = stack[0];
    v195 = (Lisp_Object)17; /* 1 */
    if (v120 == v195) goto v28;
    v120 = stack[0];
    v195 = (Lisp_Object)1; /* 0 */
    if (v120 == v195) goto v149;
    v195 = nil;
    goto v29;

v29:
    if (v195 == nil) goto v159;
    v195 = stack[-2];
    v195 = qcdr(v195);
    stack[-2] = v195;
    goto v157;

v159:
    v195 = stack[-2];
    if (v195 == nil) goto v6;
    v195 = qvalue(elt(env, 3)); /* t */
    { popv(4); return onevalue(v195); }

v6:
    v195 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v195); }

v149:
    v195 = stack[-2];
    v120 = qcar(v195);
    v195 = stack[-1];
    v195 = (Lisp_Object)lesseq2(v120, v195);
    nil = C_nil;
    if (exception_pending()) goto v79;
    v195 = v195 ? lisp_true : nil;
    env = stack[-3];
    goto v29;

v28:
    v195 = stack[-2];
    v120 = qcar(v195);
    v195 = stack[-1];
    v195 = (Lisp_Object)lessp2(v120, v195);
    nil = C_nil;
    if (exception_pending()) goto v79;
    v195 = v195 ? lisp_true : nil;
    env = stack[-3];
    goto v29;

v9:
    v195 = qvalue(elt(env, 1)); /* signat!* */
    goto v31;

v49:
    v195 = nil;
    { popv(4); return onevalue(v195); }
/* error exit handlers */
v79:
    popv(4);
    return nil;
}



/* Code for makeupsf */

static Lisp_Object MS_CDECL CC_makeupsf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v46, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v203, v217, v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "makeupsf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeupsf");
#endif
    if (stack >= stacklimit)
    {
        push3(v46,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    stack[-1] = v1;
    v218 = v0;
/* end of prologue */
    v240 = v218;
    v240 = qcar(v240);
    if (!consp(v240)) goto v138;
    v240 = v218;
    v203 = qcdr(v240);
    v240 = (Lisp_Object)17; /* 1 */
    v240 = (v203 == v240 ? lisp_true : nil);
    goto v14;

v14:
    if (v240 == nil) goto v42;
    v203 = v218;
    v240 = (Lisp_Object)17; /* 1 */
    v240 = cons(v203, v240);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    v203 = ncons(v240);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    v240 = stack[-1];
    fn = elt(env, 6); /* multf */
    v203 = (*qfn2(fn))(qenv(fn), v203, v240);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    v240 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v203, v240);
    }

v42:
    v240 = v218;
    v240 = qcar(v240);
    v203 = qcar(v240);
    v240 = elt(env, 2); /* sqrt */
    if (v203 == v240) goto v231;
    v240 = v218;
    v240 = qcar(v240);
    v217 = v240;
    v240 = v217;
    v203 = qcar(v240);
    v240 = elt(env, 3); /* expt */
    if (v203 == v240) goto v162;
    v240 = qvalue(elt(env, 4)); /* nil */
    goto v7;

v7:
    if (v240 == nil) goto v219;
    v240 = v218;
    v203 = qcar(v240);
    v240 = stack[-1];
    v217 = v218;
    v217 = qcdr(v217);
    fn = elt(env, 8); /* !*multfexpt */
    v203 = (*qfnn(fn))(qenv(fn), 3, v203, v240, v217);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    v240 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v203, v240);
    }

v219:
    v203 = v218;
    v240 = (Lisp_Object)17; /* 1 */
    v240 = cons(v203, v240);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    v203 = ncons(v240);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    v240 = stack[-1];
    fn = elt(env, 6); /* multf */
    v203 = (*qfn2(fn))(qenv(fn), v203, v240);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    v240 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v203, v240);
    }

v162:
    v240 = v217;
    v240 = qcdr(v240);
    v240 = qcdr(v240);
    v240 = qcar(v240);
    v217 = v240;
    v240 = v217;
    if (!consp(v240)) goto v85;
    v240 = v217;
    v203 = qcar(v240);
    v240 = elt(env, 5); /* quotient */
    if (v203 == v240) goto v118;
    v240 = qvalue(elt(env, 4)); /* nil */
    goto v7;

v118:
    v240 = v217;
    v240 = qcdr(v240);
    v240 = qcar(v240);
    if (is_number(v240)) goto v142;
    v240 = qvalue(elt(env, 4)); /* nil */
    goto v7;

v142:
    v240 = v217;
    v240 = qcdr(v240);
    v240 = qcdr(v240);
    v240 = qcar(v240);
    v240 = (is_number(v240) ? lisp_true : nil);
    goto v7;

v85:
    v240 = qvalue(elt(env, 4)); /* nil */
    goto v7;

v231:
    v240 = v218;
    v203 = qcar(v240);
    v240 = stack[-1];
    v217 = v218;
    v217 = qcdr(v217);
    fn = elt(env, 9); /* !*multfsqrt */
    v203 = (*qfnn(fn))(qenv(fn), 3, v203, v240, v217);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    v240 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v203, v240);
    }

v138:
    v240 = qvalue(elt(env, 1)); /* t */
    goto v14;
/* error exit handlers */
v186:
    popv(3);
    return nil;
}



/* Code for coeffs!-to!-form */

static Lisp_Object CC_coeffsKtoKform(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v95, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeffs-to-form");
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
    v95 = v1;
    v158 = v0;
/* end of prologue */
    v125 = v158;
    if (v125 == nil) goto v32;
    stack[-1] = v158;
    stack[0] = v95;
    v125 = v158;
    v125 = Llength(nil, v125);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v125 = sub1(v125);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    {
        Lisp_Object v22 = stack[-1];
        Lisp_Object v153 = stack[0];
        popv(3);
        fn = elt(env, 2); /* coeffs!-to!-form1 */
        return (*qfnn(fn))(qenv(fn), 3, v22, v153, v125);
    }

v32:
    v125 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v125); }
/* error exit handlers */
v41:
    popv(3);
    return nil;
}



/* Code for polynomlistautoreduce */

static Lisp_Object CC_polynomlistautoreduce(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v272, v273, v230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomlistautoreduce");
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
    v272 = qvalue(elt(env, 1)); /* nil */
    v272 = ncons(v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-5] = v272;
    goto v140;

v140:
    v272 = stack[-4];
    v272 = qcar(v272);
    if (v272 == nil) goto v91;
    v230 = stack[-5];
    v272 = stack[-4];
    v273 = qcar(v272);
    v272 = stack[-3];
    fn = elt(env, 2); /* polynomlistreduce */
    v272 = (*qfnn(fn))(qenv(fn), 3, v230, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-2] = v272;
    v273 = stack[-4];
    v272 = stack[-4];
    v272 = qcdr(v272);
    v272 = qcar(v272);
    v273 = Lrplaca(nil, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v272 = stack[-4];
    v272 = qcdr(v272);
    v272 = qcdr(v272);
    v272 = Lrplacd(nil, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v272 = stack[-2];
    v272 = qcar(v272);
    if (v272 == nil) goto v140;
    v272 = stack[-2];
    v272 = qcar(v272);
    stack[-1] = v272;
    v272 = stack[-5];
    stack[0] = v272;
    goto v155;

v155:
    v272 = stack[0];
    v272 = qcar(v272);
    if (v272 == nil) goto v213;
    v272 = stack[0];
    v272 = qcar(v272);
    v273 = qcar(v272);
    v272 = stack[-1];
    fn = elt(env, 3); /* monomisdivisibleby */
    v272 = (*qfn2(fn))(qenv(fn), v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    if (v272 == nil) goto v82;
    v273 = stack[-4];
    v272 = stack[0];
    v272 = qcar(v272);
    fn = elt(env, 4); /* pushback */
    v272 = (*qfn2(fn))(qenv(fn), v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v273 = stack[0];
    v272 = stack[0];
    v272 = qcdr(v272);
    v272 = qcar(v272);
    v273 = Lrplaca(nil, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v272 = stack[0];
    v272 = qcdr(v272);
    v272 = qcdr(v272);
    v272 = Lrplacd(nil, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    goto v155;

v82:
    v272 = stack[0];
    v272 = qcdr(v272);
    stack[0] = v272;
    goto v155;

v213:
    v273 = stack[-5];
    v272 = stack[-2];
    fn = elt(env, 4); /* pushback */
    v272 = (*qfn2(fn))(qenv(fn), v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    goto v140;

v91:
    v272 = stack[-5];
    stack[0] = v272;
    goto v116;

v116:
    v272 = stack[0];
    v272 = qcar(v272);
    if (v272 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v272 = stack[0];
    v272 = qcar(v272);
    stack[-2] = v272;
    v273 = stack[0];
    v272 = stack[0];
    v272 = qcdr(v272);
    v272 = qcar(v272);
    v273 = Lrplaca(nil, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v272 = stack[0];
    v272 = qcdr(v272);
    v272 = qcdr(v272);
    v272 = Lrplacd(nil, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v230 = stack[-5];
    v273 = stack[-2];
    v272 = stack[-3];
    fn = elt(env, 2); /* polynomlistreduce */
    v272 = (*qfnn(fn))(qenv(fn), 3, v230, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-2] = v272;
    v272 = stack[-2];
    if (v272 == nil) goto v116;
    v272 = stack[-2];
    v272 = qcar(v272);
    if (v272 == nil) goto v116;
    stack[-1] = stack[0];
    v272 = stack[0];
    v273 = qcar(v272);
    v272 = stack[0];
    v272 = qcdr(v272);
    v272 = cons(v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v273 = Lrplacd(nil, stack[-1], v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v272 = stack[-2];
    v272 = Lrplaca(nil, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v272 = stack[0];
    v272 = qcdr(v272);
    stack[0] = v272;
    goto v116;
/* error exit handlers */
v59:
    popv(7);
    return nil;
}



/* Code for eval!-yetunknowntypeexpr */

static Lisp_Object CC_evalKyetunknowntypeexpr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v274, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eval-yetunknowntypeexpr");
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
    stack[-4] = v1;
    stack[0] = v0;
/* end of prologue */

v156:
    v274 = stack[0];
    if (!consp(v274)) goto v14;
    v274 = stack[0];
    v219 = qcar(v274);
    v274 = elt(env, 2); /* !*sq */
    if (v219 == v274) goto v123;
    v274 = stack[0];
    v219 = qcar(v274);
    v274 = elt(env, 4); /* dname */
    v274 = get(v219, v274);
    env = stack[-6];
    if (!(v274 == nil)) goto v30;
    v274 = stack[0];
    v219 = qcar(v274);
    v274 = elt(env, 5); /* !:dn!: */
    v274 = (v219 == v274 ? lisp_true : nil);
    goto v30;

v30:
    if (!(v274 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v274 = stack[0];
    v219 = qcar(v274);
    v274 = elt(env, 6); /* psopfn */
    v274 = get(v219, v274);
    env = stack[-6];
    stack[-1] = v274;
    v274 = stack[-1];
    if (v274 == nil) goto v119;
    v274 = stack[0];
    fn = elt(env, 9); /* getrtype */
    v219 = (*qfn1(fn))(qenv(fn), v274);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v274 = elt(env, 7); /* yetunknowntype */
    if (!(v219 == v274)) goto v119;
    v219 = stack[-1];
    v274 = stack[0];
    v274 = qcdr(v274);
        popv(7);
        return Lapply1(nil, v219, v274);

v119:
    v274 = stack[0];
    stack[-5] = qcar(v274);
    v274 = stack[0];
    v274 = qcdr(v274);
    stack[-3] = v274;
    v274 = stack[-3];
    if (v274 == nil) goto v142;
    v274 = stack[-3];
    v274 = qcar(v274);
    v219 = v274;
    v274 = stack[-4];
    v274 = CC_evalKyetunknowntypeexpr(env, v219, v274);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v274 = ncons(v274);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[-1] = v274;
    stack[-2] = v274;
    goto v76;

v76:
    v274 = stack[-3];
    v274 = qcdr(v274);
    stack[-3] = v274;
    v274 = stack[-3];
    if (v274 == nil) goto v238;
    stack[0] = stack[-1];
    v274 = stack[-3];
    v274 = qcar(v274);
    v219 = v274;
    v274 = stack[-4];
    v274 = CC_evalKyetunknowntypeexpr(env, v219, v274);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v274 = ncons(v274);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v274 = Lrplacd(nil, stack[0], v274);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v274 = stack[-1];
    v274 = qcdr(v274);
    stack[-1] = v274;
    goto v76;

v238:
    v274 = stack[-2];
    goto v225;

v225:
    {
        Lisp_Object v239 = stack[-5];
        popv(7);
        return cons(v239, v274);
    }

v142:
    v274 = qvalue(elt(env, 8)); /* nil */
    goto v225;

v123:
    v274 = qvalue(elt(env, 3)); /* t */
    goto v30;

v14:
    v219 = stack[0];
    v274 = elt(env, 1); /* avalue */
    v274 = get(v219, v274);
    env = stack[-6];
    v219 = v274;
    v274 = v219;
    if (v274 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v274 = v219;
    v274 = qcdr(v274);
    v219 = qcar(v274);
    v274 = stack[-4];
    stack[0] = v219;
    stack[-4] = v274;
    goto v156;
/* error exit handlers */
v235:
    popv(7);
    return nil;
}



/* Code for addinds */

static Lisp_Object CC_addinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addinds");
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
    goto v43;

v43:
    v149 = stack[-1];
    if (v149 == nil) goto v14;
    v149 = stack[0];
    if (v149 == nil) goto v87;
    v149 = stack[-1];
    v231 = qcar(v149);
    v149 = stack[0];
    v149 = qcar(v149);
    v149 = qcar(v149);
    v231 = plus2(v231, v149);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    v149 = stack[-2];
    v149 = cons(v231, v149);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    stack[-2] = v149;
    v149 = stack[-1];
    v149 = qcdr(v149);
    stack[-1] = v149;
    v149 = stack[0];
    v149 = qcdr(v149);
    stack[0] = v149;
    goto v43;

v87:
    stack[0] = stack[-2];
    v149 = elt(env, 2); /* "Powu too long" */
    fn = elt(env, 3); /* interr */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    {
        Lisp_Object v2 = stack[0];
        popv(4);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v2, v149);
    }

v14:
    v149 = stack[0];
    if (v149 == nil) goto v44;
    stack[0] = stack[-2];
    v149 = elt(env, 1); /* "Powrhs too long" */
    fn = elt(env, 3); /* interr */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    {
        Lisp_Object v5 = stack[0];
        popv(4);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v5, v149);
    }

v44:
    v149 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v149);
    }
/* error exit handlers */
v3:
    popv(4);
    return nil;
}



/* Code for preptaylor!*!* */

static Lisp_Object CC_preptaylorHH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaylor**");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v140 = v0;
/* end of prologue */
    v91 = qvalue(elt(env, 1)); /* convert!-taylor!* */
    if (v91 == nil) return onevalue(v140);
    v91 = v140;
    {
        fn = elt(env, 2); /* preptaylor!* */
        return (*qfn1(fn))(qenv(fn), v91);
    }
}



/* Code for mri_2ofsfat */

static Lisp_Object CC_mri_2ofsfat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_2ofsfat");
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
    v16 = stack[0];
    fn = elt(env, 2); /* mri_op */
    stack[-1] = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    v16 = stack[0];
    fn = elt(env, 3); /* mri_arg2l */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    v17 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v35 = stack[-1];
        popv(3);
        return list3(v35, v16, v17);
    }
/* error exit handlers */
v9:
    popv(3);
    return nil;
}



/* Code for bc_quot */

static Lisp_Object CC_bc_quot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_quot");
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
    stack[0] = v1;
    v153 = v0;
/* end of prologue */
    v40 = v153;
    v153 = stack[0];
    fn = elt(env, 2); /* qremf */
    v153 = (*qfn2(fn))(qenv(fn), v40, v153);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    v40 = v153;
    v153 = v40;
    v153 = qcdr(v153);
    if (v153 == nil) goto v44;
    v40 = stack[0];
    v153 = elt(env, 1); /* "denominator" */
    {
        popv(2);
        fn = elt(env, 3); /* typerr */
        return (*qfn2(fn))(qenv(fn), v40, v153);
    }

v44:
    v153 = v40;
    v153 = qcar(v153);
    {
        popv(2);
        fn = elt(env, 4); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v153);
    }
/* error exit handlers */
v87:
    popv(2);
    return nil;
}



/* Code for vdp_sugar */

static Lisp_Object CC_vdp_sugar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_sugar");
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
    v158 = stack[0];
    fn = elt(env, 3); /* vdp_zero!? */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    if (!(v158 == nil)) goto v47;
    v158 = qvalue(elt(env, 1)); /* !*cgbsugar */
    if (v158 == nil) goto v47;
    v159 = stack[0];
    v158 = elt(env, 2); /* sugar */
    fn = elt(env, 4); /* vdp_getprop */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v41;
    if (!(v158 == nil)) { popv(2); return onevalue(v158); }
    v158 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v158); }

v47:
    v158 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v158); }
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for crnprep1 */

static Lisp_Object CC_crnprep1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crnprep1");
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
    v194 = stack[-2];
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v224 = qcar(v194);
    v194 = (Lisp_Object)1; /* 0 */
    if (v224 == v194) goto v47;
    v194 = stack[-2];
    v194 = qcar(v194);
    v194 = qcdr(v194);
    v224 = qcar(v194);
    v194 = (Lisp_Object)1; /* 0 */
    if (v224 == v194) goto v9;
    v194 = stack[-2];
    v194 = qcdr(v194);
    fn = elt(env, 3); /* rnminusp!: */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-4];
    if (v194 == nil) goto v150;
    stack[-3] = elt(env, 1); /* difference */
    v194 = stack[-2];
    v194 = qcar(v194);
    fn = elt(env, 4); /* rnprep!: */
    stack[-1] = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-4];
    v194 = stack[-2];
    v194 = qcdr(v194);
    stack[0] = qcar(v194);
    v194 = stack[-2];
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = qcar(v194);
    fn = elt(env, 5); /* !:minus */
    v224 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-4];
    v194 = stack[-2];
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = list2star(stack[0], v224, v194);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-4];
    fn = elt(env, 6); /* crnprimp */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v81;
    {
        Lisp_Object v80 = stack[-3];
        Lisp_Object v99 = stack[-1];
        popv(5);
        return list3(v80, v99, v194);
    }

v150:
    stack[-1] = elt(env, 2); /* plus */
    v194 = stack[-2];
    v194 = qcar(v194);
    fn = elt(env, 4); /* rnprep!: */
    stack[0] = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-4];
    v194 = stack[-2];
    v194 = qcdr(v194);
    fn = elt(env, 6); /* crnprimp */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v81;
    {
        Lisp_Object v210 = stack[-1];
        Lisp_Object v21 = stack[0];
        popv(5);
        return list3(v210, v21, v194);
    }

v9:
    v194 = stack[-2];
    v194 = qcdr(v194);
    {
        popv(5);
        fn = elt(env, 6); /* crnprimp */
        return (*qfn1(fn))(qenv(fn), v194);
    }

v47:
    v194 = stack[-2];
    v194 = qcar(v194);
    {
        popv(5);
        fn = elt(env, 4); /* rnprep!: */
        return (*qfn1(fn))(qenv(fn), v194);
    }
/* error exit handlers */
v81:
    popv(5);
    return nil;
}



/* Code for numberofoccs */

static Lisp_Object CC_numberofoccs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numberofoccs");
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
    v154 = stack[0];
    if (!consp(v154)) goto v91;
    v154 = stack[0];
    v154 = qcdr(v154);
    if (v154 == nil) goto v132;
    v133 = stack[-1];
    v154 = stack[0];
    v154 = qcdr(v154);
    v154 = CC_numberofoccs(env, v133, v154);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    stack[-2] = v154;
    goto v11;

v11:
    v133 = stack[-1];
    v154 = stack[0];
    v154 = qcar(v154);
    if (equal(v133, v154)) goto v42;
    v154 = stack[0];
    v154 = qcar(v154);
    if (!consp(v154)) goto v150;
    v133 = stack[-1];
    v154 = stack[0];
    v154 = qcar(v154);
    v154 = CC_numberofoccs(env, v133, v154);
    nil = C_nil;
    if (exception_pending()) goto v6;
    goto v41;

v41:
    {
        Lisp_Object v7 = stack[-2];
        popv(4);
        return plus2(v7, v154);
    }

v150:
    v154 = (Lisp_Object)1; /* 0 */
    goto v41;

v42:
    v154 = (Lisp_Object)17; /* 1 */
    goto v41;

v132:
    v154 = (Lisp_Object)1; /* 0 */
    stack[-2] = v154;
    goto v11;

v91:
    v133 = stack[-1];
    v154 = stack[0];
    if (equal(v133, v154)) goto v138;
    v154 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v154); }

v138:
    v154 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v154); }
/* error exit handlers */
v6:
    popv(4);
    return nil;
}



/* Code for matrix_input_test */

static Lisp_Object CC_matrix_input_test(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrix_input_test");
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
    v124 = v0;
/* end of prologue */
    v122 = v124;
    v123 = elt(env, 1); /* mat */
    if (!consp(v122)) goto v43;
    v122 = qcar(v122);
    if (v122 == v123) { popv(1); return onevalue(v124); }
    else goto v43;

v43:
    v123 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v123 == nil)) goto v9;
    v122 = elt(env, 3); /* "ERROR: `" */
    v123 = elt(env, 4); /* "' is non matrix input." */
    v123 = list3(v122, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[0];
    fn = elt(env, 5); /* lprie */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[0];
    goto v9;

v9:
    v123 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v36;
    v123 = nil;
    { popv(1); return onevalue(v123); }
/* error exit handlers */
v36:
    popv(1);
    return nil;
}



/* Code for evzero */

static Lisp_Object MS_CDECL CC_evzero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v13;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "evzero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evzero");
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
    stack[-1] = nil;
    v12 = (Lisp_Object)17; /* 1 */
    stack[0] = v12;
    goto v16;

v16:
    v12 = qvalue(elt(env, 1)); /* dipvars!* */
    v13 = Llength(nil, v12);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    v12 = stack[0];
    v12 = difference2(v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    v12 = Lminusp(nil, v12);
    env = stack[-2];
    if (!(v12 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v13 = (Lisp_Object)1; /* 0 */
    v12 = stack[-1];
    v12 = cons(v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    stack[-1] = v12;
    v12 = stack[0];
    v12 = add1(v12);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    stack[0] = v12;
    goto v16;
/* error exit handlers */
v123:
    popv(3);
    return nil;
}



/* Code for !*s2arg */

static Lisp_Object CC_Hs2arg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v193, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *s2arg");
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
/* copy arguments values to proper place */
    stack[-3] = v1;
    v193 = v0;
/* end of prologue */
    v192 = v193;
    if (!consp(v192)) goto v14;
    v192 = v193;
    v118 = qcar(v192);
    v192 = elt(env, 2); /* quote */
    v192 = (v118 == v192 ? lisp_true : nil);
    goto v152;

v152:
    if (!(v192 == nil)) { popv(6); return onevalue(v193); }
    v192 = v193;
    v192 = qcar(v192);
    if (symbolp(v192)) goto v29;
    v192 = qvalue(elt(env, 1)); /* t */
    goto v157;

v157:
    if (v192 == nil) goto v134;
    v192 = v193;
    stack[-4] = v192;
    v192 = stack[-4];
    if (v192 == nil) goto v161;
    v192 = stack[-4];
    v192 = qcar(v192);
    v193 = v192;
    v192 = stack[-3];
    v192 = CC_Hs2arg(env, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    v192 = ncons(v192);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    stack[-1] = v192;
    stack[-2] = v192;
    goto v42;

v42:
    v192 = stack[-4];
    v192 = qcdr(v192);
    stack[-4] = v192;
    v192 = stack[-4];
    if (v192 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v192 = stack[-4];
    v192 = qcar(v192);
    v193 = v192;
    v192 = stack[-3];
    v192 = CC_Hs2arg(env, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    v192 = ncons(v192);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    v192 = Lrplacd(nil, stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    v192 = stack[-1];
    v192 = qcdr(v192);
    stack[-1] = v192;
    goto v42;

v161:
    v192 = qvalue(elt(env, 4)); /* nil */
    { popv(6); return onevalue(v192); }

v134:
    v192 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); /* mkarg */
        return (*qfn2(fn))(qenv(fn), v193, v192);
    }

v29:
    v192 = v193;
    v118 = qcar(v192);
    v192 = elt(env, 3); /* nochange */
    v192 = Lflagp(nil, v118, v192);
    env = stack[-5];
    v192 = (v192 == nil ? lisp_true : nil);
    goto v157;

v14:
    v192 = qvalue(elt(env, 1)); /* t */
    goto v152;
/* error exit handlers */
v98:
    popv(6);
    return nil;
}



/* Code for make!-image!-mod!-p */

static Lisp_Object CC_makeKimageKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-image-mod-p");
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
    v216 = stack[-1];
    v36 = stack[0];
    fn = elt(env, 3); /* degree!-in!-variable */
    v36 = (*qfn2(fn))(qenv(fn), v216, v36);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    stack[-2] = v36;
    v216 = stack[-1];
    v36 = stack[0];
    fn = elt(env, 4); /* make!-univariate!-image!-mod!-p */
    v36 = (*qfn2(fn))(qenv(fn), v216, v36);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    stack[-1] = v36;
    v216 = stack[-1];
    v36 = stack[0];
    fn = elt(env, 3); /* degree!-in!-variable */
    v216 = (*qfn2(fn))(qenv(fn), v216, v36);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    v36 = stack[-2];
    if (equal(v216, v36)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v36 = qvalue(elt(env, 1)); /* t */
    qvalue(elt(env, 2)) = v36; /* unlucky!-case */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v23:
    popv(4);
    return nil;
}



/* Code for mo_deletecomp */

static Lisp_Object CC_mo_deletecomp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_deletecomp");
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
    v37 = v0;
/* end of prologue */
    v132 = v37;
    v132 = qcar(v132);
    if (v132 == nil) { popv(2); return onevalue(v37); }
    v132 = v37;
    v132 = qcar(v132);
    v132 = qcdr(v132);
    if (v132 == nil) goto v16;
    v132 = (Lisp_Object)1; /* 0 */
    v37 = qcar(v37);
    v37 = qcdr(v37);
    v37 = cons(v132, v37);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    stack[0] = v37;
    fn = elt(env, 2); /* mo!=deglist */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v28;
    {
        Lisp_Object v33 = stack[0];
        popv(2);
        return cons(v33, v37);
    }

v16:
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v37 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* mo!=deglist */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v28;
    {
        Lisp_Object v34 = stack[0];
        popv(2);
        return cons(v34, v37);
    }
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for general!-negate!-term */

static Lisp_Object CC_generalKnegateKterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-negate-term");
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
    v44 = v0;
/* end of prologue */
    v140 = v44;
    stack[0] = qcar(v140);
    v140 = v44;
    v140 = qcdr(v140);
    fn = elt(env, 1); /* general!-minus!-mod!-p */
    v140 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v17;
    {
        Lisp_Object v15 = stack[0];
        popv(1);
        return cons(v15, v140);
    }
/* error exit handlers */
v17:
    popv(1);
    return nil;
}



setup_type const u41_setup[] =
{
    {"make_wedge_pair",         too_few_2,      CC_make_wedge_pair,wrong_no_2},
    {":dmexpt",                 too_few_2,      CC_Tdmexpt,    wrong_no_2},
    {"deletez1",                too_few_2,      CC_deletez1,   wrong_no_2},
    {"mapcarcar",               CC_mapcarcar,   too_many_1,    wrong_no_1},
    {"simp-prop-form",          CC_simpKpropKform,too_many_1,  wrong_no_1},
    {"monomcomparelex",         too_few_2,      CC_monomcomparelex,wrong_no_2},
    {"impartf",                 CC_impartf,     too_many_1,    wrong_no_1},
    {"nonpolyp",                too_few_2,      CC_nonpolyp,   wrong_no_2},
    {"ratpoly_sub",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_sub},
    {"lowlimitrd",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_lowlimitrd},
    {"ps:find-order",           CC_psTfindKorder,too_many_1,   wrong_no_1},
    {"extbrsea",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_extbrsea},
    {"*a2kwoweight",            CC_Ha2kwoweight,too_many_1,    wrong_no_1},
    {"vdpmember",               too_few_2,      CC_vdpmember,  wrong_no_2},
    {"remove_critical_pairs",   too_few_2,      CC_remove_critical_pairs,wrong_no_2},
    {"gf2bf",                   CC_gf2bf,       too_many_1,    wrong_no_1},
    {":quotient",               too_few_2,      CC_Tquotient,  wrong_no_2},
    {"propagator",              too_few_2,      CC_propagator, wrong_no_2},
    {"lieninstruc",             CC_lieninstruc, too_many_1,    wrong_no_1},
    {"get_rep_matrix_entry",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_rep_matrix_entry},
    {"mri_simplfloor1",         CC_mri_simplfloor1,too_many_1, wrong_no_1},
    {"iv_cutcongs2",            too_few_2,      CC_iv_cutcongs2,wrong_no_2},
    {"applyml",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_applyml},
    {"splitrec",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitrec},
    {"get_num_part",            CC_get_num_part,too_many_1,    wrong_no_1},
    {"let2",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_let2},
    {"r2oreaction",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_r2oreaction},
    {"color-roads",             too_few_2,      CC_colorKroads,wrong_no_2},
    {"prsum",                   too_few_2,      CC_prsum,      wrong_no_2},
    {"red_redpol",              too_few_2,      CC_red_redpol, wrong_no_2},
    {"out_of_range",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_out_of_range},
    {"makeupsf",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeupsf},
    {"coeffs-to-form",          too_few_2,      CC_coeffsKtoKform,wrong_no_2},
    {"polynomlistautoreduce",   too_few_2,      CC_polynomlistautoreduce,wrong_no_2},
    {"eval-yetunknowntypeexpr", too_few_2,      CC_evalKyetunknowntypeexpr,wrong_no_2},
    {"addinds",                 too_few_2,      CC_addinds,    wrong_no_2},
    {"preptaylor**",            CC_preptaylorHH,too_many_1,    wrong_no_1},
    {"mri_2ofsfat",             CC_mri_2ofsfat, too_many_1,    wrong_no_1},
    {"bc_quot",                 too_few_2,      CC_bc_quot,    wrong_no_2},
    {"vdp_sugar",               CC_vdp_sugar,   too_many_1,    wrong_no_1},
    {"crnprep1",                CC_crnprep1,    too_many_1,    wrong_no_1},
    {"numberofoccs",            too_few_2,      CC_numberofoccs,wrong_no_2},
    {"matrix_input_test",       CC_matrix_input_test,too_many_1,wrong_no_1},
    {"evzero",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_evzero},
    {"*s2arg",                  too_few_2,      CC_Hs2arg,     wrong_no_2},
    {"make-image-mod-p",        too_few_2,      CC_makeKimageKmodKp,wrong_no_2},
    {"mo_deletecomp",           CC_mo_deletecomp,too_many_1,   wrong_no_1},
    {"general-negate-term",     CC_generalKnegateKterm,too_many_1,wrong_no_1},
    {NULL, (one_args *)"u41", (two_args *)"14174 8649865 4778782", 0}
};

/* end of generated code */
