
/* $destdir\u11.c        Machine generated C code */

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


/* Code for variables */

static Lisp_Object CC_variables(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variables");
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
    v23 = (Lisp_Object)1; /* 0 */
    stack[-4] = v23;
    v23 = stack[-5];
    if (v23 == nil) goto v25;
    v23 = qvalue(elt(env, 2)); /* dipvars!* */
    v23 = Llength(nil, v23);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-7];
    stack[-6] = v23;
    v23 = (Lisp_Object)17; /* 1 */
    stack[-3] = v23;
    v24 = stack[-6];
    v23 = stack[-3];
    v23 = difference2(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-7];
    v23 = Lminusp(nil, v23);
    env = stack[-7];
    if (v23 == nil) goto v27;
    v23 = qvalue(elt(env, 1)); /* nil */
    goto v28;

v28:
    stack[0] = v23;
    goto v29;

v29:
    v23 = stack[-5];
    v23 = qcar(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcar(v23);
    stack[-2] = v23;
    goto v30;

v30:
    v23 = stack[-2];
    v23 = qcar(v23);
    stack[-3] = v23;
    v23 = stack[0];
    stack[-1] = v23;
    goto v31;

v31:
    v23 = stack[-3];
    v24 = qcar(v23);
    v23 = (Lisp_Object)1; /* 0 */
    if (!(((int32_t)(v24)) > ((int32_t)(v23)))) goto v32;
    v23 = stack[-1];
    v23 = qcar(v23);
    if (!(v23 == nil)) goto v32;
    v24 = stack[-1];
    v23 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 4); /* setcar */
    v23 = (*qfn2(fn))(qenv(fn), v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-7];
    v23 = stack[-4];
    v23 = (Lisp_Object)((int32_t)(v23) + 0x10);
    stack[-4] = v23;
    goto v32;

v32:
    v24 = stack[-4];
    v23 = stack[-6];
    if (v24 == v23) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v23 = stack[-3];
    v23 = qcdr(v23);
    stack[-3] = v23;
    v23 = stack[-3];
    if (v23 == nil) goto v33;
    v23 = stack[-1];
    v23 = qcdr(v23);
    stack[-1] = v23;
    goto v31;

v33:
    v23 = stack[-2];
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    stack[-2] = v23;
    v23 = stack[-2];
    if (!(v23 == nil)) goto v30;
    v23 = stack[-5];
    v23 = qcdr(v23);
    stack[-5] = v23;
    v23 = stack[-5];
    if (v23 == nil) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    else goto v29;

v27:
    v23 = qvalue(elt(env, 1)); /* nil */
    v23 = ncons(v23);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-7];
    stack[-1] = v23;
    stack[-2] = v23;
    goto v34;

v34:
    v23 = stack[-3];
    v23 = add1(v23);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-7];
    stack[-3] = v23;
    v24 = stack[-6];
    v23 = stack[-3];
    v23 = difference2(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-7];
    v23 = Lminusp(nil, v23);
    env = stack[-7];
    if (v23 == nil) goto v35;
    v23 = stack[-2];
    goto v28;

v35:
    stack[0] = stack[-1];
    v23 = qvalue(elt(env, 1)); /* nil */
    v23 = ncons(v23);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-7];
    v23 = Lrplacd(nil, stack[0], v23);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-7];
    v23 = stack[-1];
    v23 = qcdr(v23);
    stack[-1] = v23;
    goto v34;

v25:
    v23 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v23); }
/* error exit handlers */
v26:
    popv(8);
    return nil;
}



/* Code for flatindxl */

static Lisp_Object CC_flatindxl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v31, v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flatindxl");
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
    v45 = v0;
/* end of prologue */
    stack[-3] = v45;
    v45 = stack[-3];
    if (v45 == nil) goto v30;
    v45 = stack[-3];
    v45 = qcar(v45);
    v46 = v45;
    v45 = v46;
    if (!consp(v45)) goto v47;
    v31 = v46;
    v45 = elt(env, 2); /* minus */
    if (!consp(v31)) goto v48;
    v31 = qcar(v31);
    if (!(v31 == v45)) goto v48;
    v45 = v46;
    v45 = qcdr(v45);
    v45 = qcar(v45);
    goto v49;

v49:
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    stack[-1] = v45;
    stack[-2] = v45;
    goto v1;

v1:
    v45 = stack[-3];
    v45 = qcdr(v45);
    stack[-3] = v45;
    v45 = stack[-3];
    if (v45 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v45 = stack[-3];
    v45 = qcar(v45);
    v46 = v45;
    v45 = v46;
    if (!consp(v45)) goto v35;
    v31 = v46;
    v45 = elt(env, 2); /* minus */
    if (!consp(v31)) goto v50;
    v31 = qcar(v31);
    if (!(v31 == v45)) goto v50;
    v45 = v46;
    v45 = qcdr(v45);
    v45 = qcar(v45);
    goto v51;

v51:
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v45 = Lrplacd(nil, stack[0], v45);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v45 = stack[-1];
    v45 = qcdr(v45);
    stack[-1] = v45;
    goto v1;

v50:
    v45 = v46;
    v45 = qcdr(v45);
    goto v51;

v35:
    v45 = v46;
    goto v51;

v48:
    v45 = v46;
    v45 = qcdr(v45);
    goto v49;

v47:
    v45 = v46;
    goto v49;

v30:
    v45 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v45); }
/* error exit handlers */
v11:
    popv(5);
    return nil;
}



/* Code for list!+list */

static Lisp_Object CC_listLlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list+list");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v52;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v10;

v10:
    v56 = stack[-1];
    if (v56 == nil) goto v57;
    v56 = stack[-1];
    v48 = qcar(v56);
    v56 = stack[0];
    v56 = qcar(v56);
    fn = elt(env, 1); /* !:plus */
    v48 = (*qfn2(fn))(qenv(fn), v48, v56);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v56 = stack[-2];
    v56 = cons(v48, v56);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    stack[-2] = v56;
    v56 = stack[-1];
    v56 = qcdr(v56);
    stack[-1] = v56;
    v56 = stack[0];
    v56 = qcdr(v56);
    stack[0] = v56;
    goto v10;

v57:
    v56 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v56);
    }
/* error exit handlers */
v22:
    popv(4);
    return nil;
}



/* Code for nth */

static Lisp_Object CC_nth(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nth");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v58 = v52;
    v59 = v0;
/* end of prologue */
    fn = elt(env, 1); /* pnth */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    errexit();
    v58 = qcar(v58);
    return onevalue(v58);
}



/* Code for split!-road */

static Lisp_Object CC_splitKroad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split-road");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v52;
    stack[-2] = v0;
/* end of prologue */
    v62 = stack[-1];
    stack[-3] = qcar(v62);
    v62 = stack[-2];
    v64 = qcar(v62);
    v62 = stack[-2];
    v63 = qcdr(v62);
    v62 = stack[-1];
    v62 = qcdr(v62);
    v62 = qcar(v62);
    fn = elt(env, 1); /* sroad */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v64, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-4];
    v62 = stack[-2];
    v64 = qcar(v62);
    v62 = stack[-2];
    v63 = qcdr(v62);
    v62 = stack[-1];
    v62 = qcdr(v62);
    v62 = qcdr(v62);
    v62 = qcar(v62);
    fn = elt(env, 1); /* sroad */
    v62 = (*qfnn(fn))(qenv(fn), 3, v64, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v65;
    {
        Lisp_Object v66 = stack[-3];
        Lisp_Object v67 = stack[0];
        popv(5);
        return list3(v66, v67, v62);
    }
/* error exit handlers */
v65:
    popv(5);
    return nil;
}



/* Code for aminusp!: */

static Lisp_Object CC_aminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aminusp:");
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
    v14 = qvalue(elt(env, 1)); /* !*modular */
    if (v14 == nil) goto v47;
    v15 = elt(env, 2); /* modular */
    v14 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 7); /* setdmode */
    v14 = (*qfn2(fn))(qenv(fn), v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    stack[-2] = v14;
    goto v47;

v47:
    stack[0] = elt(env, 4); /* aminusp!:1 */
    v14 = stack[-1];
    v14 = Lmkquote(nil, v14);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v14 = list2(stack[0], v14);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    fn = elt(env, 8); /* errorset2 */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    stack[0] = v14;
    v14 = stack[-2];
    if (v14 == nil) goto v70;
    v15 = elt(env, 2); /* modular */
    v14 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 7); /* setdmode */
    v14 = (*qfn2(fn))(qenv(fn), v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    goto v70;

v70:
    v14 = stack[0];
    if (!consp(v14)) goto v71;
    v14 = stack[0];
    v14 = qcdr(v14);
    goto v72;

v72:
    if (v14 == nil) goto v73;
    v15 = stack[-1];
    v14 = elt(env, 6); /* "arithmetic expression" */
    fn = elt(env, 9); /* typerr */
    v14 = (*qfn2(fn))(qenv(fn), v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v14 = nil;
    { popv(4); return onevalue(v14); }

v73:
    v14 = stack[0];
    v14 = qcar(v14);
    { popv(4); return onevalue(v14); }

v71:
    v14 = qvalue(elt(env, 5)); /* t */
    goto v72;
/* error exit handlers */
v69:
    popv(4);
    return nil;
}



/* Code for mv!-pow!-chk */

static Lisp_Object CC_mvKpowKchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-chk");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v70 = v52;
    stack[0] = v0;
/* end of prologue */
    v27 = v70;
    if (v27 == nil) goto v28;
    v27 = stack[0];
    v27 = qcar(v27);
    v27 = qcar(v27);
    v70 = qcar(v70);
    v70 = qcar(v70);
    fn = elt(env, 2); /* mv!-pow!-!- */
    v70 = (*qfn2(fn))(qenv(fn), v27, v70);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    stack[0] = v70;
    if (v70 == nil) goto v28;
    v70 = stack[0];
    fn = elt(env, 3); /* mv!-pow!-minusp */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    if (v70 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else goto v28;

v28:
    v70 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v70); }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for dd */

static Lisp_Object CC_dd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v83, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dd");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v52;
    stack[-2] = v0;
/* end of prologue */
    v83 = stack[0];
    v82 = stack[-2];
    fn = elt(env, 6); /* dquot */
    v82 = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    v84 = v82;
    v82 = v84;
    if (v82 == nil) goto v16;
    v83 = qvalue(elt(env, 1)); /* ordering */
    v82 = elt(env, 2); /* lex */
    if (v83 == v82) goto v56;
    v82 = v84;
    v82 = qcdr(v82);
    v84 = v82;
    goto v56;

v56:
    v82 = v84;
    fn = elt(env, 7); /* leftzeros */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[-3] = v82;
    v82 = qvalue(elt(env, 3)); /* nc */
    if (v82 == nil) goto v19;
    v82 = qvalue(elt(env, 5)); /* nil */
    goto v36;

v36:
    if (v82 == nil) goto v86;
    v82 = (Lisp_Object)49; /* 3 */
    { popv(5); return onevalue(v82); }

v86:
    v82 = qvalue(elt(env, 3)); /* nc */
    if (v82 == nil) goto v87;
    stack[0] = stack[-3];
    v82 = qvalue(elt(env, 4)); /* varlist */
    v82 = Llength(nil, v82);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    v83 = qvalue(elt(env, 3)); /* nc */
    v82 = (Lisp_Object)(int32_t)((int32_t)v82 - (int32_t)v83 + TAG_FIXNUM);
    if (((int32_t)(stack[0])) < ((int32_t)(v82))) goto v87;
    v82 = (Lisp_Object)65; /* 4 */
    { popv(5); return onevalue(v82); }

v87:
    v82 = (Lisp_Object)33; /* 2 */
    { popv(5); return onevalue(v82); }

v19:
    stack[-1] = stack[-3];
    v82 = qvalue(elt(env, 4)); /* varlist */
    stack[0] = Llength(nil, v82);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    v82 = stack[-2];
    fn = elt(env, 8); /* class */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    v82 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v82 + TAG_FIXNUM);
    v82 = ((intptr_t)stack[-1] < (intptr_t)v82) ? lisp_true : nil;
    v82 = (v82 == nil ? lisp_true : nil);
    goto v36;

v16:
    v83 = stack[-2];
    v82 = stack[0];
    fn = elt(env, 9); /* dless */
    v82 = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v85;
    if (v82 == nil) goto v44;
    v82 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v82); }

v44:
    v82 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v82); }
/* error exit handlers */
v85:
    popv(5);
    return nil;
}



/* Code for make!-univariate!-image!-mod!-p */

static Lisp_Object CC_makeKunivariateKimageKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-univariate-image-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v52;
    stack[-2] = v0;
/* end of prologue */
    v99 = stack[-2];
    if (!consp(v99)) goto v57;
    v99 = stack[-2];
    v99 = qcar(v99);
    v99 = (consp(v99) ? nil : lisp_true);
    goto v101;

v101:
    if (v99 == nil) goto v21;
    v99 = stack[-2];
    if (v99 == nil) goto v49;
    v99 = stack[-2];
    v99 = Lmodular_number(nil, v99);
    env = stack[-4];
    v100 = v99;
    v99 = v100;
    v99 = (Lisp_Object)zerop(v99);
    v99 = v99 ? lisp_true : nil;
    env = stack[-4];
    if (v99 == nil) { popv(5); return onevalue(v100); }
    v99 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v99); }

v49:
    v99 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v99); }

v21:
    v99 = stack[-2];
    v99 = qcar(v99);
    v99 = qcar(v99);
    v100 = qcar(v99);
    v99 = stack[-1];
    if (equal(v100, v99)) goto v66;
    v99 = stack[-2];
    v99 = qcar(v99);
    v99 = qcar(v99);
    v100 = qcar(v99);
    v99 = stack[-2];
    v99 = qcar(v99);
    v99 = qcar(v99);
    v99 = qcdr(v99);
    fn = elt(env, 3); /* image!-of!-power */
    stack[0] = (*qfn2(fn))(qenv(fn), v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v99 = stack[-2];
    v99 = qcar(v99);
    v100 = qcdr(v99);
    v99 = stack[-1];
    v99 = CC_makeKunivariateKimageKmodKp(env, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    fn = elt(env, 4); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v99 = stack[-2];
    v100 = qcdr(v99);
    v99 = stack[-1];
    v99 = CC_makeKunivariateKimageKmodKp(env, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    {
        Lisp_Object v103 = stack[0];
        popv(5);
        fn = elt(env, 5); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v103, v99);
    }

v66:
    v99 = stack[-2];
    v99 = qcar(v99);
    stack[-3] = qcar(v99);
    v99 = stack[-2];
    v99 = qcar(v99);
    v100 = qcdr(v99);
    v99 = stack[-1];
    stack[0] = CC_makeKunivariateKimageKmodKp(env, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v99 = stack[-2];
    v100 = qcdr(v99);
    v99 = stack[-1];
    v99 = CC_makeKunivariateKimageKmodKp(env, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    {
        Lisp_Object v104 = stack[-3];
        Lisp_Object v105 = stack[0];
        popv(5);
        fn = elt(env, 6); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v104, v105, v99);
    }

v57:
    v99 = qvalue(elt(env, 1)); /* t */
    goto v101;
/* error exit handlers */
v102:
    popv(5);
    return nil;
}



/* Code for qqe_id!-nyt!-branchq */

static Lisp_Object CC_qqe_idKnytKbranchq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_id-nyt-branchq");
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
    v16 = stack[0];
    if (!consp(v16)) goto v3;
    v16 = stack[0];
    v16 = qcar(v16);
    fn = elt(env, 1); /* qqe_qopaddp */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    if (!(v16 == nil)) { popv(2); return onevalue(v16); }
    v16 = stack[0];
    v16 = qcar(v16);
    {
        popv(2);
        fn = elt(env, 2); /* qqe_qoptailp */
        return (*qfn1(fn))(qenv(fn), v16);
    }

v3:
    v16 = stack[0];
    fn = elt(env, 3); /* qqe_qtidp */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    if (!(v16 == nil)) { popv(2); return onevalue(v16); }
    v16 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* qqe_nytidp */
        return (*qfn1(fn))(qenv(fn), v16);
    }
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for ibalp_getnewwl */

static Lisp_Object CC_ibalp_getnewwl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v93, v107, v108, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getnewwl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */
    v107 = nil;
    v84 = v32;
    v84 = qcar(v84);
    v108 = v84;
    goto v29;

v29:
    v84 = v108;
    if (v84 == nil) goto v57;
    v84 = v107;
    if (!(v84 == nil)) goto v57;
    v84 = v108;
    v84 = qcar(v84);
    v84 = qcdr(v84);
    v84 = qcar(v84);
    if (v84 == nil) goto v54;
    v84 = qvalue(elt(env, 1)); /* nil */
    goto v16;

v16:
    if (v84 == nil) goto v47;
    v84 = v108;
    v84 = qcar(v84);
    v107 = v84;
    goto v47;

v47:
    v84 = v108;
    v84 = qcdr(v84);
    v108 = v84;
    goto v29;

v54:
    v84 = v108;
    v93 = qcar(v84);
    v84 = v32;
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    v84 = qcar(v84);
    v84 = Lmemq(nil, v93, v84);
    v84 = (v84 == nil ? lisp_true : nil);
    goto v16;

v57:
    v84 = v32;
    v84 = qcdr(v84);
    v84 = qcar(v84);
    v108 = v84;
    goto v38;

v38:
    v84 = v108;
    if (v84 == nil) return onevalue(v107);
    v84 = v107;
    if (!(v84 == nil)) return onevalue(v107);
    v84 = v108;
    v84 = qcar(v84);
    v84 = qcdr(v84);
    v84 = qcar(v84);
    if (v84 == nil) goto v109;
    v84 = qvalue(elt(env, 1)); /* nil */
    goto v39;

v39:
    if (v84 == nil) goto v94;
    v84 = v108;
    v84 = qcar(v84);
    v107 = v84;
    goto v94;

v94:
    v84 = v108;
    v84 = qcdr(v84);
    v108 = v84;
    goto v38;

v109:
    v84 = v108;
    v93 = qcar(v84);
    v84 = v32;
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    v84 = qcdr(v84);
    v84 = qcar(v84);
    v84 = Lmemq(nil, v93, v84);
    v84 = (v84 == nil ? lisp_true : nil);
    goto v39;
}



/* Code for sacar */

static Lisp_Object CC_sacar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sacar");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v52;
    stack[-1] = v0;
/* end of prologue */
    v36 = stack[0];
    if (!consp(v36)) goto v2;
    v37 = stack[-1];
    v36 = stack[0];
    v36 = qcar(v36);
    if (v37 == v36) goto v59;
    v36 = qvalue(elt(env, 1)); /* nil */
    goto v58;

v58:
    if (v36 == nil) goto v60;
    v36 = stack[0];
    popv(4);
    return ncons(v36);

v60:
    v37 = stack[-1];
    v36 = stack[0];
    v36 = qcar(v36);
    stack[-2] = CC_sacar(env, v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-3];
    v37 = stack[-1];
    v36 = stack[0];
    v36 = qcdr(v36);
    v36 = CC_sacar(env, v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v38;
    {
        Lisp_Object v51 = stack[-2];
        popv(4);
        return Lappend(nil, v51, v36);
    }

v59:
    v36 = stack[0];
    v36 = qcdr(v36);
    goto v58;

v2:
    v36 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v36); }
/* error exit handlers */
v38:
    popv(4);
    return nil;
}



/* Code for initbrsea */

static Lisp_Object MS_CDECL CC_initbrsea(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v112, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "initbrsea");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initbrsea");
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
    v89 = (Lisp_Object)3201; /* 200 */
    stack[-2] = v89;
    v89 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v89;
    goto v114;

v114:
    v112 = qvalue(elt(env, 2)); /* rowmax */
    v89 = stack[-1];
    v89 = difference2(v112, v89);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    v89 = Lminusp(nil, v89);
    env = stack[-3];
    if (v89 == nil) goto v44;
    fn = elt(env, 8); /* redcodmat */
    v89 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    v89 = qvalue(elt(env, 6)); /* codhisto */
    if (v89 == nil) goto v116;
    v89 = (Lisp_Object)1; /* 0 */
    stack[0] = v89;
    goto v80;

v80:
    v112 = (Lisp_Object)3201; /* 200 */
    v89 = stack[0];
    v89 = difference2(v112, v89);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    v89 = Lminusp(nil, v89);
    env = stack[-3];
    if (!(v89 == nil)) goto v36;
    v113 = qvalue(elt(env, 6)); /* codhisto */
    v112 = stack[0];
    v89 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v113 + (CELL-TAG_VECTOR) + ((int32_t)v112/(16/CELL))) = v89;
    v89 = stack[0];
    v89 = add1(v89);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    stack[0] = v89;
    goto v80;

v36:
    v89 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v89; /* headhisto */
    v89 = (Lisp_Object)1; /* 0 */
    stack[0] = v89;
    goto v83;

v83:
    v112 = qvalue(elt(env, 2)); /* rowmax */
    v89 = stack[0];
    v89 = difference2(v112, v89);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    v89 = Lminusp(nil, v89);
    env = stack[-3];
    if (v89 == nil) goto v117;
    v89 = nil;
    { popv(4); return onevalue(v89); }

v117:
    v89 = stack[0];
    fn = elt(env, 9); /* inshisto */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    v89 = stack[0];
    v89 = add1(v89);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    stack[0] = v89;
    goto v83;

v116:
    v89 = stack[-2];
    v89 = Lmkvect(nil, v89);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    qvalue(elt(env, 6)) = v89; /* codhisto */
    goto v36;

v44:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v112 = qvalue(elt(env, 5)); /* maxvar */
    v89 = stack[-1];
    v89 = plus2(v112, v89);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    v112 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v89/(16/CELL)));
    v89 = (Lisp_Object)1; /* 0 */
    v89 = *(Lisp_Object *)((char *)v112 + (CELL-TAG_VECTOR) + ((int32_t)v89/(16/CELL)));
    if (v89 == nil) goto v16;
    v89 = stack[-1];
    fn = elt(env, 10); /* initwght */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    goto v16;

v16:
    v89 = stack[-1];
    v89 = add1(v89);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    stack[-1] = v89;
    goto v114;
/* error exit handlers */
v115:
    popv(4);
    return nil;
}



/* Code for scalprod */

static Lisp_Object CC_scalprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scalprod");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v52;
    stack[-1] = v0;
/* end of prologue */
    v120 = stack[-1];
    if (v120 == nil) goto v57;
    v120 = qvalue(elt(env, 1)); /* nil */
    goto v101;

v101:
    if (v120 == nil) goto v10;
    v95 = qvalue(elt(env, 1)); /* nil */
    v120 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v95, v120);

v10:
    v120 = stack[-1];
    if (v120 == nil) goto v55;
    v120 = stack[0];
    v120 = (v120 == nil ? lisp_true : nil);
    goto v34;

v34:
    if (v120 == nil) goto v18;
    v120 = elt(env, 3); /* "Matrix mismatch" */
    v95 = v120;
    v120 = v95;
    qvalue(elt(env, 4)) = v120; /* errmsg!* */
    v120 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v120 == nil)) goto v61;
    v120 = v95;
    fn = elt(env, 6); /* lprie */
    v120 = (*qfn1(fn))(qenv(fn), v120);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    goto v61;

v61:
    v120 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v109;
    v120 = nil;
    { popv(4); return onevalue(v120); }

v18:
    v120 = stack[-1];
    v95 = qcar(v120);
    v120 = stack[0];
    v120 = qcar(v120);
    fn = elt(env, 7); /* multsq */
    stack[-2] = (*qfn2(fn))(qenv(fn), v95, v120);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    v120 = stack[-1];
    v95 = qcdr(v120);
    v120 = stack[0];
    v120 = qcdr(v120);
    v120 = CC_scalprod(env, v95, v120);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    {
        Lisp_Object v121 = stack[-2];
        popv(4);
        fn = elt(env, 8); /* addsq */
        return (*qfn2(fn))(qenv(fn), v121, v120);
    }

v55:
    v120 = qvalue(elt(env, 2)); /* t */
    goto v34;

v57:
    v120 = stack[0];
    v120 = (v120 == nil ? lisp_true : nil);
    goto v101;
/* error exit handlers */
v109:
    popv(4);
    return nil;
}



/* Code for gsugar */

static Lisp_Object CC_gsugar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gsugar");
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
    v51 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v51 == nil) goto v2;
    v51 = stack[0];
    if (v51 == nil) goto v59;
    v51 = stack[0];
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcar(v51);
    v51 = (v51 == nil ? lisp_true : nil);
    goto v58;

v58:
    if (v51 == nil) goto v55;
    v51 = (Lisp_Object)1; /* 0 */
    goto v101;

v101:
    stack[-1] = v51;
    v51 = stack[-1];
    if (!(v51 == nil)) { popv(3); return onevalue(v51); }
    v35 = elt(env, 4); /* "*** missing sugar" */
    v51 = stack[0];
    v51 = list2(v35, v51);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v51 = Lprint(nil, v51);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    fn = elt(env, 5); /* backtrace */
    v51 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v51 = stack[0];
    fn = elt(env, 6); /* vdptdeg */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    stack[-1] = v51;
    v35 = stack[0];
    v51 = stack[-1];
    fn = elt(env, 7); /* gsetsugar */
    v51 = (*qfn2(fn))(qenv(fn), v35, v51);
    nil = C_nil;
    if (exception_pending()) goto v124;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v55:
    v35 = stack[0];
    v51 = elt(env, 3); /* sugar */
    fn = elt(env, 8); /* vdpgetprop */
    v51 = (*qfn2(fn))(qenv(fn), v35, v51);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    goto v101;

v59:
    v51 = qvalue(elt(env, 2)); /* t */
    goto v58;

v2:
    v51 = nil;
    { popv(3); return onevalue(v51); }
/* error exit handlers */
v124:
    popv(3);
    return nil;
}



/* Code for xord_lex */

static Lisp_Object CC_xord_lex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v39, v111, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_lex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v52;
    v111 = v0;
/* end of prologue */

v2:
    v40 = v111;
    if (v40 == nil) goto v58;
    v40 = v111;
    v120 = qcar(v40);
    v40 = (Lisp_Object)17; /* 1 */
    v40 = (v120 == v40 ? lisp_true : nil);
    goto v30;

v30:
    if (v40 == nil) goto v57;
    v40 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v40);

v57:
    v40 = v39;
    if (v40 == nil) goto v54;
    v40 = v39;
    v120 = qcar(v40);
    v40 = (Lisp_Object)17; /* 1 */
    v40 = (v120 == v40 ? lisp_true : nil);
    goto v27;

v27:
    if (v40 == nil) goto v98;
    v40 = qvalue(elt(env, 1)); /* t */
    return onevalue(v40);

v98:
    v40 = v111;
    v120 = qcar(v40);
    v40 = v39;
    v40 = qcar(v40);
    if (v120 == v40) goto v71;
    v40 = v111;
    v40 = qcar(v40);
    v39 = qcar(v39);
    {
        fn = elt(env, 3); /* factorordp */
        return (*qfn2(fn))(qenv(fn), v40, v39);
    }

v71:
    v40 = v111;
    v40 = qcdr(v40);
    v111 = v40;
    v40 = v39;
    v40 = qcdr(v40);
    v39 = v40;
    goto v2;

v54:
    v40 = qvalue(elt(env, 1)); /* t */
    goto v27;

v58:
    v40 = qvalue(elt(env, 1)); /* t */
    goto v30;
}



/* Code for mkinds */

static Lisp_Object CC_mkinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkinds");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v52;
    stack[-1] = v0;
/* end of prologue */
    v63 = stack[0];
    v62 = (Lisp_Object)1; /* 0 */
    if (v63 == v62) goto v2;
    v63 = stack[-1];
    v62 = stack[0];
    v62 = cons(v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    stack[-2] = v62;
    v62 = stack[0];
    v62 = sub1(v62);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v62 = CC_mkinds(env, stack[-1], v62);
    nil = C_nil;
    if (exception_pending()) goto v97;
    {
        Lisp_Object v98 = stack[-2];
        popv(4);
        return cons(v98, v62);
    }

v2:
    v62 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v62); }
/* error exit handlers */
v97:
    popv(4);
    return nil;
}



/* Code for bc_zero!? */

static Lisp_Object CC_bc_zeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v68, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_zero?");
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
    v68 = v0;
/* end of prologue */
    v60 = v68;
    if (v60 == nil) goto v101;
    v21 = v68;
    v60 = (Lisp_Object)1; /* 0 */
    v60 = (v21 == v60 ? lisp_true : nil);
    goto v1;

v1:
    if (v60 == nil) goto v2;
    v60 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v60); }

v2:
    v60 = qvalue(elt(env, 2)); /* !*hardzerotest */
    if (v60 == nil) goto v122;
    v60 = v68;
    v60 = Lconsp(nil, v60);
    env = stack[0];
    if (v60 == nil) goto v122;
    v60 = v68;
    fn = elt(env, 4); /* prepf */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[0];
    fn = elt(env, 5); /* simp */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[0];
    v60 = qcar(v60);
    fn = elt(env, 6); /* bc!=simp */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v60 = (v60 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v60); }

v122:
    v60 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v60); }

v101:
    v60 = qvalue(elt(env, 1)); /* t */
    goto v1;
/* error exit handlers */
v22:
    popv(1);
    return nil;
}



/* Code for psum */

static Lisp_Object CC_psum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v134, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for psum");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v52;
    stack[-6] = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v133 = stack[-6];
    if (v133 == nil) goto v81;
    v133 = stack[-5];
    if (!(v133 == nil)) goto v13;
    v133 = stack[-6];
    stack[-2] = v133;
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v13:
    v133 = stack[-5];
    if (v133 == nil) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    v133 = stack[-1];
    if (!(v133 == nil)) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    v133 = stack[-5];
    v133 = qcar(v133);
    stack[0] = v133;
    v133 = stack[0];
    v133 = qcar(v133);
    stack[-7] = v133;
    goto v22;

v22:
    v133 = stack[-6];
    if (v133 == nil) goto v21;
    v134 = stack[-7];
    v133 = stack[-6];
    v133 = qcar(v133);
    v133 = qcar(v133);
    fn = elt(env, 3); /* dless */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-8];
    if (v133 == nil) goto v21;
    v133 = stack[-6];
    v134 = qcar(v133);
    v133 = stack[-3];
    v133 = cons(v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-8];
    stack[-3] = v133;
    v133 = stack[-6];
    v133 = qcdr(v133);
    stack[-6] = v133;
    goto v22;

v21:
    v133 = stack[-6];
    if (v133 == nil) goto v120;
    v133 = stack[-6];
    v133 = qcar(v133);
    v135 = v133;
    v134 = stack[-7];
    v133 = v135;
    v133 = qcar(v133);
    if (equal(v134, v133)) goto v8;
    v134 = stack[0];
    v133 = stack[-3];
    v133 = cons(v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-8];
    stack[-3] = v133;
    goto v75;

v75:
    v133 = stack[-5];
    v133 = qcdr(v133);
    stack[-5] = v133;
    v133 = stack[-5];
    if (!(v133 == nil)) goto v13;
    v133 = stack[-3];
    v134 = Lreverse(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-8];
    v133 = stack[-6];
    v133 = Lappend(nil, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-8];
    stack[-2] = v133;
    goto v13;

v8:
    v133 = v135;
    v134 = qcdr(v133);
    v133 = stack[0];
    v133 = qcdr(v133);
    fn = elt(env, 4); /* csum */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-8];
    stack[-4] = v133;
    stack[0] = stack[-4];
    fn = elt(env, 5); /* c_zero */
    v133 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-8];
    if (equal(stack[0], v133)) goto v137;
    v135 = stack[-7];
    v134 = stack[-4];
    v133 = stack[-3];
    v133 = acons(v135, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-8];
    stack[-3] = v133;
    goto v137;

v137:
    v133 = stack[-6];
    v133 = qcdr(v133);
    stack[-6] = v133;
    v133 = stack[-6];
    if (v133 == nil) goto v75;
    else goto v75;

v120:
    v133 = stack[-3];
    v134 = Lreverse(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-8];
    v133 = stack[-5];
    v133 = Lappend(nil, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-8];
    stack[-2] = v133;
    v133 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v133;
    goto v13;

v81:
    v133 = stack[-5];
    stack[-2] = v133;
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
/* error exit handlers */
v136:
    popv(9);
    return nil;
}



/* Code for general!-reciprocal!-by!-gcd */

static Lisp_Object MS_CDECL CC_generalKreciprocalKbyKgcd(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v52,
                         Lisp_Object v6, Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "general-reciprocal-by-gcd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-reciprocal-by-gcd");
#endif
    if (stack >= stacklimit)
    {
        push4(v7,v6,v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v52,v6,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v7;
    stack[-3] = v6;
    stack[-4] = v52;
    stack[-5] = v0;
/* end of prologue */

v57:
    v4 = stack[-4];
    v141 = (Lisp_Object)1; /* 0 */
    if (v4 == v141) goto v1;
    v4 = stack[-4];
    v141 = (Lisp_Object)17; /* 1 */
    if (v4 == v141) goto v61;
    v4 = stack[-5];
    v141 = stack[-4];
    v141 = quot2(v4, v141);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    stack[-6] = v141;
    stack[-1] = stack[-4];
    stack[0] = stack[-5];
    v4 = stack[-4];
    v141 = stack[-6];
    v141 = times2(v4, v141);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    stack[-4] = difference2(stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    stack[0] = stack[-2];
    v4 = stack[-2];
    v141 = stack[-6];
    v141 = times2(v4, v141);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    v141 = difference2(stack[-3], v141);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    stack[-5] = stack[-1];
    stack[-3] = stack[0];
    stack[-2] = v141;
    goto v57;

v61:
    v4 = stack[-2];
    v141 = (Lisp_Object)1; /* 0 */
    v141 = (Lisp_Object)lessp2(v4, v141);
    nil = C_nil;
    if (exception_pending()) goto v115;
    v141 = v141 ? lisp_true : nil;
    env = stack[-7];
    if (v141 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v141 = stack[-2];
    v4 = qvalue(elt(env, 4)); /* current!-modulus */
    popv(8);
    return plus2(v141, v4);

v1:
    v141 = elt(env, 1); /* "Invalid modular division" */
    v4 = v141;
    v141 = v4;
    qvalue(elt(env, 2)) = v141; /* errmsg!* */
    v141 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v141 == nil)) goto v53;
    v141 = v4;
    fn = elt(env, 5); /* lprie */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    goto v53;

v53:
    v141 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v115;
    v141 = nil;
    { popv(8); return onevalue(v141); }
/* error exit handlers */
v115:
    popv(8);
    return nil;
}



/* Code for replus */

static Lisp_Object CC_replus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replus");
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
    v70 = v0;
/* end of prologue */
    v55 = v70;
    if (v55 == nil) goto v3;
    v55 = v70;
    if (!consp(v55)) { popv(1); return onevalue(v70); }
    v55 = v70;
    v55 = qcdr(v55);
    if (v55 == nil) goto v58;
    stack[0] = elt(env, 1); /* plus */
    v55 = v70;
    fn = elt(env, 2); /* unplus */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v54;
    {
        Lisp_Object v44 = stack[0];
        popv(1);
        return cons(v44, v55);
    }

v58:
    v55 = v70;
    v55 = qcar(v55);
    { popv(1); return onevalue(v55); }

v3:
    v55 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v55); }
/* error exit handlers */
v54:
    popv(1);
    return nil;
}



/* Code for gcdf2 */

static Lisp_Object CC_gcdf2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v174, v175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf2");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v52;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* asymplis!* */
    qvalue(elt(env, 1)) = nil; /* asymplis!* */
    v173 = qvalue(elt(env, 2)); /* !*anygcd */
    if (v173 == nil) goto v81;
    v173 = stack[-5];
    fn = elt(env, 7); /* num!-exponents */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    if (v173 == nil) goto v53;
    v173 = stack[-4];
    fn = elt(env, 7); /* num!-exponents */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    v173 = (v173 == nil ? lisp_true : nil);
    goto v59;

v59:
    if (v173 == nil) goto v57;
    v173 = (Lisp_Object)17; /* 1 */
    goto v1;

v1:
    qvalue(elt(env, 1)) = stack[-6]; /* asymplis!* */
    { popv(8); return onevalue(v173); }

v57:
    v173 = qvalue(elt(env, 4)); /* !*gcd */
    if (v173 == nil) goto v35;
    v174 = stack[-5];
    v173 = stack[-4];
    fn = elt(env, 8); /* kernord */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-3] = v173;
    v174 = Llength(nil, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    v173 = (Lisp_Object)17; /* 1 */
    v173 = (Lisp_Object)greaterp2(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    v173 = v173 ? lisp_true : nil;
    env = stack[-7];
    if (v173 == nil) goto v35;
    v173 = stack[-3];
    fn = elt(env, 9); /* setkorder */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    v173 = ncons(v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-3] = v173;
    v173 = stack[-5];
    fn = elt(env, 10); /* reorder */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-5] = v173;
    v173 = stack[-4];
    fn = elt(env, 10); /* reorder */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-4] = v173;
    goto v96;

v96:
    v173 = stack[-5];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v174 = qcar(v173);
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcar(v173);
    if (v174 == v173) goto v14;
    v173 = qvalue(elt(env, 6)); /* !*ncmp */
    if (v173 == nil) goto v177;
    v173 = stack[-5];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcar(v173);
    fn = elt(env, 11); /* noncomp1 */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    if (v173 == nil) goto v177;
    v173 = qvalue(elt(env, 6)); /* !*ncmp */
    if (v173 == nil) goto v177;
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcar(v173);
    fn = elt(env, 11); /* noncomp1 */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    if (v173 == nil) goto v177;
    v175 = stack[-5];
    v174 = stack[-4];
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcar(v173);
    fn = elt(env, 12); /* gcdfnc */
    v173 = (*qfnn(fn))(qenv(fn), 3, v175, v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-2] = v173;
    goto v119;

v119:
    v173 = stack[-3];
    if (v173 == nil) goto v178;
    v173 = stack[-3];
    v173 = qcar(v173);
    fn = elt(env, 9); /* setkorder */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    v173 = stack[-2];
    fn = elt(env, 10); /* reorder */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-2] = v173;
    goto v178;

v178:
    v173 = stack[-2];
    goto v1;

v177:
    v173 = stack[-5];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v174 = qcar(v173);
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcar(v173);
    fn = elt(env, 13); /* ordop */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    if (v173 == nil) goto v179;
    v173 = stack[-5];
    fn = elt(env, 14); /* comfac */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    v174 = qcdr(v173);
    v173 = stack[-4];
    fn = elt(env, 15); /* gcdf1 */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-2] = v173;
    goto v119;

v179:
    v173 = stack[-4];
    fn = elt(env, 14); /* comfac */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    v174 = qcdr(v173);
    v173 = stack[-5];
    fn = elt(env, 15); /* gcdf1 */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-2] = v173;
    goto v119;

v14:
    v173 = stack[-5];
    fn = elt(env, 14); /* comfac */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-1] = v173;
    v173 = stack[-4];
    fn = elt(env, 14); /* comfac */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[0] = v173;
    v173 = stack[-1];
    v174 = qcdr(v173);
    v173 = stack[0];
    v173 = qcdr(v173);
    fn = elt(env, 15); /* gcdf1 */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-2] = v173;
    v173 = stack[-1];
    v173 = qcar(v173);
    if (v173 == nil) goto v107;
    v173 = stack[-1];
    v173 = ncons(v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    goto v9;

v9:
    fn = elt(env, 16); /* quotf1 */
    v173 = (*qfn2(fn))(qenv(fn), stack[-5], v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-5] = v173;
    v173 = stack[0];
    v173 = qcar(v173);
    if (v173 == nil) goto v100;
    v173 = stack[0];
    v173 = ncons(v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    goto v180;

v180:
    fn = elt(env, 16); /* quotf1 */
    v173 = (*qfn2(fn))(qenv(fn), stack[-4], v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-4] = v173;
    v173 = qvalue(elt(env, 4)); /* !*gcd */
    if (v173 == nil) goto v181;
    v174 = stack[-5];
    v173 = stack[-4];
    fn = elt(env, 17); /* gcdk */
    v174 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    v173 = stack[-2];
    fn = elt(env, 18); /* multf */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-2] = v173;
    goto v182;

v182:
    v173 = stack[-1];
    v173 = qcar(v173);
    if (v173 == nil) goto v119;
    v173 = stack[0];
    v173 = qcar(v173);
    if (v173 == nil) goto v119;
    v173 = stack[-1];
    v173 = qcar(v173);
    v174 = qcdr(v173);
    v173 = stack[0];
    v173 = qcar(v173);
    v173 = qcdr(v173);
    v173 = (Lisp_Object)greaterp2(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    v173 = v173 ? lisp_true : nil;
    env = stack[-7];
    if (v173 == nil) goto v183;
    v173 = stack[0];
    v174 = qcar(v173);
    v173 = (Lisp_Object)17; /* 1 */
    v173 = cons(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    v174 = ncons(v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    v173 = stack[-2];
    fn = elt(env, 18); /* multf */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-2] = v173;
    goto v119;

v183:
    v173 = stack[-1];
    v174 = qcar(v173);
    v173 = (Lisp_Object)17; /* 1 */
    v173 = cons(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    v174 = ncons(v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    v173 = stack[-2];
    fn = elt(env, 18); /* multf */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-2] = v173;
    goto v119;

v181:
    v173 = stack[-4];
    if (v173 == nil) goto v184;
    v174 = stack[-5];
    v173 = stack[-4];
    fn = elt(env, 16); /* quotf1 */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    if (v173 == nil) goto v184;
    v174 = stack[-4];
    v173 = stack[-2];
    fn = elt(env, 18); /* multf */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-2] = v173;
    goto v182;

v184:
    v173 = stack[-5];
    if (v173 == nil) goto v182;
    v174 = stack[-4];
    v173 = stack[-5];
    fn = elt(env, 16); /* quotf1 */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    if (v173 == nil) goto v182;
    v174 = stack[-5];
    v173 = stack[-2];
    fn = elt(env, 18); /* multf */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-7];
    stack[-2] = v173;
    goto v182;

v100:
    v173 = stack[0];
    v173 = qcdr(v173);
    goto v180;

v107:
    v173 = stack[-1];
    v173 = qcdr(v173);
    goto v9;

v35:
    v173 = qvalue(elt(env, 5)); /* nil */
    stack[-3] = v173;
    goto v96;

v53:
    v173 = qvalue(elt(env, 3)); /* t */
    goto v59;

v81:
    v173 = qvalue(elt(env, 3)); /* t */
    goto v59;
/* error exit handlers */
v176:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* asymplis!* */
    popv(8);
    return nil;
}



/* Code for matrix!+p */

static Lisp_Object CC_matrixLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrix+p");
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
    v36 = stack[0];
    v37 = Llength(nil, v36);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v36 = (Lisp_Object)17; /* 1 */
    v36 = (Lisp_Object)lessp2(v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v51;
    v36 = v36 ? lisp_true : nil;
    env = stack[-4];
    if (v36 == nil) goto v101;
    v36 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v36); }

v101:
    v36 = stack[0];
    v36 = qcar(v36);
    v36 = Llength(nil, v36);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    stack[-3] = v36;
    v36 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v36;
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[-1] = v36;
    goto v34;

v34:
    v36 = stack[-1];
    if (v36 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v36 = stack[-1];
    v36 = qcar(v36);
    stack[0] = stack[-3];
    v36 = Llength(nil, v36);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    if (equal(stack[0], v36)) goto v21;
    v36 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v36;
    goto v21;

v21:
    v36 = stack[-1];
    v36 = qcdr(v36);
    stack[-1] = v36;
    goto v34;
/* error exit handlers */
v51:
    popv(5);
    return nil;
}



/* Code for freevarinexptchk */

static Lisp_Object CC_freevarinexptchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freevarinexptchk");
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

v185:
    v21 = stack[0];
    if (!consp(v21)) goto v101;
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = (consp(v21) ? nil : lisp_true);
    goto v1;

v1:
    if (v21 == nil) goto v3;
    v21 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v21); }

v3:
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = qcar(v21);
    v21 = qcdr(v21);
    if (is_number(v21)) goto v13;
    v21 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v21); }

v13:
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v21 = CC_freevarinexptchk(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    if (!(v21 == nil)) { popv(2); return onevalue(v21); }
    v21 = stack[0];
    v21 = qcdr(v21);
    stack[0] = v21;
    goto v185;

v101:
    v21 = qvalue(elt(env, 1)); /* t */
    goto v1;
/* error exit handlers */
v61:
    popv(2);
    return nil;
}



/* Code for qqe_qprefix!-var */

static Lisp_Object CC_qqe_qprefixKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qprefix-var");
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

v10:
    v56 = stack[0];
    if (v56 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v56 = stack[0];
    if (!consp(v56)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v56 = stack[0];
    fn = elt(env, 3); /* qqe_op */
    v48 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    v56 = elt(env, 2); /* (ltail rtail lhead rhead) */
    v56 = Lmemq(nil, v48, v56);
    if (v56 == nil) goto v27;
    v56 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    stack[0] = v56;
    goto v10;

v27:
    v56 = stack[0];
    fn = elt(env, 5); /* qqe_arg2r */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    stack[0] = v56;
    goto v10;
/* error exit handlers */
v68:
    popv(2);
    return nil;
}



/* Code for pasf_smwcpknowl */

static Lisp_Object CC_pasf_smwcpknowl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smwcpknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v0;
/* end of prologue */
    v59 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v59 == nil) goto v57;
    v59 = v81;
    {
        fn = elt(env, 2); /* cl_susicpknowl */
        return (*qfn1(fn))(qenv(fn), v59);
    }

v57:
    v59 = v81;
    {
        fn = elt(env, 3); /* cl_smcpknowl */
        return (*qfn1(fn))(qenv(fn), v59);
    }
}



/* Code for ibalp_simpterm */

static Lisp_Object CC_ibalp_simpterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_simpterm");
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

v185:
    v12 = stack[0];
    if (!consp(v12)) goto v1;
    v12 = stack[0];
    v12 = qcar(v12);
    stack[-1] = v12;
    v12 = stack[-1];
    fn = elt(env, 3); /* ibalp_boolfp */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    if (v12 == nil) goto v140;
    stack[-4] = stack[-1];
    v12 = stack[0];
    v12 = qcdr(v12);
    stack[-3] = v12;
    v12 = stack[-3];
    if (v12 == nil) goto v56;
    v12 = stack[-3];
    v12 = qcar(v12);
    v12 = CC_ibalp_simpterm(env, v12);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    stack[-1] = v12;
    stack[-2] = v12;
    goto v54;

v54:
    v12 = stack[-3];
    v12 = qcdr(v12);
    stack[-3] = v12;
    v12 = stack[-3];
    if (v12 == nil) goto v65;
    stack[0] = stack[-1];
    v12 = stack[-3];
    v12 = qcar(v12);
    v12 = CC_ibalp_simpterm(env, v12);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    v12 = Lrplacd(nil, stack[0], v12);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    v12 = stack[-1];
    v12 = qcdr(v12);
    stack[-1] = v12;
    goto v54;

v65:
    v12 = stack[-2];
    goto v17;

v17:
    {
        Lisp_Object v117 = stack[-4];
        popv(6);
        return cons(v117, v12);
    }

v56:
    v12 = qvalue(elt(env, 1)); /* nil */
    goto v17;

v140:
    v12 = stack[0];
    fn = elt(env, 4); /* reval */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    stack[0] = v12;
    v92 = stack[0];
    v12 = stack[-1];
    if (!consp(v92)) goto v69;
    v92 = qcar(v92);
    if (!(v92 == v12)) goto v69;
    v92 = stack[-1];
    v12 = elt(env, 2); /* "Boolean function" */
    fn = elt(env, 5); /* typerr */
    v12 = (*qfn2(fn))(qenv(fn), v92, v12);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    goto v69;

v69:
    v12 = stack[0];
    stack[0] = v12;
    goto v185;

v1:
    v12 = stack[0];
    {
        popv(6);
        fn = elt(env, 6); /* ibalp_simpatom */
        return (*qfn1(fn))(qenv(fn), v12);
    }
/* error exit handlers */
v74:
    popv(6);
    return nil;
}



/* Code for exchk1 */

static Lisp_Object MS_CDECL CC_exchk1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v52,
                         Lisp_Object v6, Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v205, v206, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "exchk1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exchk1");
#endif
    if (stack >= stacklimit)
    {
        push4(v7,v6,v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v52,v6,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    stack[-2] = v6;
    stack[-3] = v52;
    stack[-4] = v0;
/* end of prologue */

v101:
    v204 = stack[-4];
    if (v204 == nil) goto v47;
    v204 = stack[-4];
    v204 = qcar(v204);
    v205 = qcar(v204);
    v204 = elt(env, 1); /* expt */
    if (!consp(v205)) goto v207;
    v205 = qcar(v205);
    if (!(v205 == v204)) goto v207;
    v206 = elt(env, 2); /* times */
    v204 = stack[-4];
    v204 = qcar(v204);
    v205 = qcdr(v204);
    v204 = stack[-4];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    v205 = list3(v206, v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    v204 = elt(env, 3); /* simp!* */
    fn = elt(env, 4); /* simpexpon1 */
    v204 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    stack[-5] = v204;
    v204 = stack[-4];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    if (is_number(v204)) goto v50;
    v204 = stack[-4];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcdr(v204);
    v205 = qcar(v204);
    v204 = stack[-2];
    v204 = Lassoc(nil, v205, v204);
    v205 = v204;
    if (v205 == nil) goto v209;
    stack[0] = v204;
    v205 = stack[-5];
    v204 = qcdr(v204);
    fn = elt(env, 5); /* addsq */
    v204 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    v204 = Lrplacd(nil, stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    goto v210;

v210:
    v204 = stack[-4];
    v151 = qcdr(v204);
    v206 = stack[-3];
    v205 = stack[-2];
    v204 = stack[-1];
    stack[-4] = v151;
    stack[-3] = v206;
    stack[-2] = v205;
    stack[-1] = v204;
    goto v101;

v209:
    v204 = stack[-4];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcdr(v204);
    v206 = qcar(v204);
    v205 = stack[-5];
    v204 = stack[-2];
    v204 = acons(v206, v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    stack[-2] = v204;
    goto v210;

v50:
    v205 = stack[-5];
    v204 = stack[-1];
    fn = elt(env, 6); /* assoc2 */
    v204 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    v205 = v204;
    if (v205 == nil) goto v138;
    stack[0] = v204;
    v205 = qcar(v204);
    v204 = stack[-4];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    v204 = times2(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    v204 = Lrplaca(nil, stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    goto v210;

v138:
    v204 = stack[-4];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcdr(v204);
    v206 = qcar(v204);
    v205 = stack[-5];
    v204 = stack[-1];
    v204 = acons(v206, v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    stack[-1] = v204;
    goto v210;

v207:
    v204 = stack[-4];
    v204 = qcar(v204);
    v205 = qcdr(v204);
    v204 = (Lisp_Object)17; /* 1 */
    if (v205 == v204) goto v211;
    v204 = stack[-4];
    v204 = qcdr(v204);
    stack[-5] = v204;
    stack[0] = elt(env, 1); /* expt */
    v204 = stack[-4];
    v204 = qcar(v204);
    v204 = qcar(v204);
    fn = elt(env, 7); /* sqchk */
    v205 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    v204 = stack[-4];
    v204 = qcar(v204);
    v204 = qcdr(v204);
    v205 = list3(stack[0], v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    v204 = stack[-3];
    v204 = cons(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    stack[-3] = v204;
    v204 = stack[-5];
    stack[-4] = v204;
    goto v101;

v211:
    v204 = stack[-4];
    v204 = qcdr(v204);
    stack[-5] = v204;
    v204 = stack[-4];
    v204 = qcar(v204);
    v204 = qcar(v204);
    fn = elt(env, 7); /* sqchk */
    v205 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    v204 = stack[-3];
    v204 = cons(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    stack[-3] = v204;
    v204 = stack[-5];
    stack[-4] = v204;
    goto v101;

v47:
    v205 = stack[-1];
    v204 = stack[-2];
    v205 = Lappend(nil, v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-6];
    v204 = stack[-3];
    {
        popv(7);
        fn = elt(env, 8); /* exchk2 */
        return (*qfn2(fn))(qenv(fn), v205, v204);
    }
/* error exit handlers */
v208:
    popv(7);
    return nil;
}



/* Code for dm!-eq */

static Lisp_Object CC_dmKeq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-eq");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v58 = v52;
    v59 = v0;
/* end of prologue */
    fn = elt(env, 1); /* dm!-difference */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !:zerop */
        return (*qfn1(fn))(qenv(fn), v58);
    }
/* error exit handlers */
v81:
    popv(1);
    return nil;
}



/* Code for powers1 */

static Lisp_Object CC_powers1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers1");
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
    v49 = v0;
/* end of prologue */
    stack[0] = v49;
    v47 = v49;
    v49 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* powers3 */
    v47 = (*qfn2(fn))(qenv(fn), v47, v49);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    v49 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v17 = stack[0];
        popv(2);
        fn = elt(env, 3); /* powers2 */
        return (*qfnn(fn))(qenv(fn), 3, v17, v47, v49);
    }
/* error exit handlers */
v20:
    popv(2);
    return nil;
}



/* Code for simptimes */

static Lisp_Object CC_simptimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simptimes");
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
    v89 = stack[-1];
    if (v89 == nil) goto v114;
    v112 = qvalue(elt(env, 1)); /* tstack!* */
    v89 = (Lisp_Object)1; /* 0 */
    if (v112 == v89) goto v60;
    v89 = qvalue(elt(env, 2)); /* t */
    goto v34;

v34:
    if (!(v89 == nil)) goto v10;
    v89 = qvalue(elt(env, 3)); /* mul!* */
    stack[-2] = v89;
    v89 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 3)) = v89; /* mul!* */
    goto v10;

v10:
    v89 = qvalue(elt(env, 1)); /* tstack!* */
    v89 = add1(v89);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    qvalue(elt(env, 1)) = v89; /* tstack!* */
    v89 = stack[-1];
    v89 = qcar(v89);
    fn = elt(env, 6); /* simp */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    stack[0] = v89;
    goto v1;

v1:
    v89 = stack[-1];
    v89 = qcdr(v89);
    stack[-1] = v89;
    v89 = stack[0];
    v89 = qcar(v89);
    if (v89 == nil) goto v57;
    v89 = stack[-1];
    if (v89 == nil) goto v101;
    v89 = stack[-1];
    v89 = qcar(v89);
    fn = elt(env, 6); /* simp */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    fn = elt(env, 7); /* multsq */
    v89 = (*qfn2(fn))(qenv(fn), stack[0], v89);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    stack[0] = v89;
    goto v1;

v101:
    v89 = qvalue(elt(env, 3)); /* mul!* */
    if (v89 == nil) goto v111;
    v112 = qvalue(elt(env, 1)); /* tstack!* */
    v89 = (Lisp_Object)17; /* 1 */
    v89 = (Lisp_Object)greaterp2(v112, v89);
    nil = C_nil;
    if (exception_pending()) goto v180;
    v89 = v89 ? lisp_true : nil;
    env = stack[-3];
    goto v39;

v39:
    if (!(v89 == nil)) goto v57;
    v89 = qvalue(elt(env, 3)); /* mul!* */
    v112 = qcar(v89);
    v89 = stack[0];
    v89 = Lapply1(nil, v112, v89);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    stack[0] = v89;
    v89 = qvalue(elt(env, 4)); /* nil */
    v89 = ncons(v89);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    qvalue(elt(env, 5)) = v89; /* alglist!* */
    v89 = qvalue(elt(env, 3)); /* mul!* */
    v89 = qcdr(v89);
    qvalue(elt(env, 3)) = v89; /* mul!* */
    goto v101;

v57:
    v89 = qvalue(elt(env, 1)); /* tstack!* */
    v89 = sub1(v89);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    qvalue(elt(env, 1)) = v89; /* tstack!* */
    v112 = qvalue(elt(env, 1)); /* tstack!* */
    v89 = (Lisp_Object)1; /* 0 */
    if (!(v112 == v89)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v89 = stack[-2];
    qvalue(elt(env, 3)) = v89; /* mul!* */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v111:
    v89 = qvalue(elt(env, 2)); /* t */
    goto v39;

v60:
    v89 = qvalue(elt(env, 3)); /* mul!* */
    v89 = (v89 == nil ? lisp_true : nil);
    goto v34;

v114:
    v112 = (Lisp_Object)17; /* 1 */
    v89 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v112, v89);
/* error exit handlers */
v180:
    popv(4);
    return nil;
}



/* Code for mo!=deglist */

static Lisp_Object CC_moMdeglist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=deglist");
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
    v102 = stack[-4];
    if (v102 == nil) goto v3;
    v102 = stack[-4];
    v103 = qcar(v102);
    v102 = qvalue(elt(env, 3)); /* cali!=degrees */
    v102 = Lassoc(nil, v103, v102);
    stack[-5] = v102;
    v102 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_degrees */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    stack[-3] = v102;
    v102 = stack[-3];
    if (v102 == nil) goto v39;
    v102 = stack[-3];
    v102 = qcar(v102);
    v103 = stack[-4];
    v103 = qcdr(v103);
    fn = elt(env, 5); /* mo!=sprod */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    stack[-1] = v102;
    stack[-2] = v102;
    goto v80;

v80:
    v102 = stack[-3];
    v102 = qcdr(v102);
    stack[-3] = v102;
    v102 = stack[-3];
    if (v102 == nil) goto v106;
    stack[0] = stack[-1];
    v102 = stack[-3];
    v102 = qcar(v102);
    v103 = stack[-4];
    v103 = qcdr(v103);
    fn = elt(env, 5); /* mo!=sprod */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v102 = Lrplacd(nil, stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v102 = stack[-1];
    v102 = qcdr(v102);
    stack[-1] = v102;
    goto v80;

v106:
    v102 = stack[-2];
    v103 = v102;
    goto v35;

v35:
    v102 = stack[-5];
    if (v102 == nil) goto v212;
    v102 = stack[-5];
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    goto v73;

v73:
    {
        popv(7);
        fn = elt(env, 6); /* mo!=sum */
        return (*qfn2(fn))(qenv(fn), v103, v102);
    }

v212:
    v102 = qvalue(elt(env, 2)); /* nil */
    goto v73;

v39:
    v102 = qvalue(elt(env, 2)); /* nil */
    v103 = v102;
    goto v35;

v3:
    v102 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_degrees */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    stack[-3] = v102;
    v102 = stack[-3];
    if (v102 == nil) goto v25;
    v102 = (Lisp_Object)1; /* 0 */
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    stack[-1] = v102;
    stack[-2] = v102;
    goto v58;

v58:
    v102 = stack[-3];
    v102 = qcdr(v102);
    stack[-3] = v102;
    v102 = stack[-3];
    if (v102 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v102 = (Lisp_Object)1; /* 0 */
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v102 = Lrplacd(nil, stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v102 = stack[-1];
    v102 = qcdr(v102);
    stack[-1] = v102;
    goto v58;

v25:
    v102 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v102); }
/* error exit handlers */
v181:
    popv(7);
    return nil;
}



/* Code for modquotient!: */

static Lisp_Object CC_modquotientT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modquotient:");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v114 = v52;
    v140 = v0;
/* end of prologue */
    stack[0] = qcdr(v140);
    v140 = v114;
    v140 = qcdr(v140);
    fn = elt(env, 1); /* general!-modular!-reciprocal */
    v140 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    fn = elt(env, 2); /* general!-modular!-times */
    v140 = (*qfn2(fn))(qenv(fn), stack[0], v140);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v140);
    }
/* error exit handlers */
v42:
    popv(2);
    return nil;
}



/* Code for qcputx */

static Lisp_Object CC_qcputx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63, v64;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qcputx");
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
    v63 = v0;
/* end of prologue */
    v64 = v63;
    v62 = elt(env, 1); /* quote */
    if (!consp(v64)) goto v21;
    v64 = qcar(v64);
    if (!(v64 == v62)) goto v21;
    v62 = v63;
    v62 = qcdr(v62);
    v64 = qcar(v62);
    v62 = elt(env, 2); /* cref */
    v62 = Lflagp(nil, v64, v62);
    env = stack[0];
    if (v62 == nil) goto v54;
    v62 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v62); }

v54:
    v62 = v63;
    v62 = qcdr(v62);
    v62 = qcar(v62);
    v63 = elt(env, 4); /* compile */
        popv(1);
        return Lflagp(nil, v62, v63);

v21:
    v62 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v62); }
}



/* Code for janettreefind */

static Lisp_Object CC_janettreefind(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for janettreefind");
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
    v102 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    if (v102 == nil) goto v3;
    stack[-5] = nil;
    v102 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    stack[-3] = v102;
    v103 = stack[-4];
    v102 = (Lisp_Object)1; /* 0 */
    v102 = *(Lisp_Object *)((char *)v103 + (CELL-TAG_VECTOR) + ((int32_t)v102/(16/CELL)));
    stack[-2] = v102;
    v102 = (Lisp_Object)17; /* 1 */
    stack[-1] = v102;
    goto v123;

v123:
    v103 = stack[-2];
    v102 = (Lisp_Object)1; /* 0 */
    if (!(((int32_t)(v103)) > ((int32_t)(v102)))) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }

v66:
    v102 = stack[-3];
    v102 = qcar(v102);
    stack[0] = qcar(v102);
    v103 = stack[-4];
    v102 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v102 = (Lisp_Object)lessp2(stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    v102 = v102 ? lisp_true : nil;
    env = stack[-6];
    if (v102 == nil) goto v213;
    v102 = stack[-3];
    v102 = qcdr(v102);
    v102 = qcar(v102);
    if (v102 == nil) goto v213;
    v102 = stack[-3];
    v102 = qcdr(v102);
    v102 = qcar(v102);
    stack[-3] = v102;
    goto v66;

v213:
    v102 = stack[-3];
    v102 = qcar(v102);
    stack[0] = qcar(v102);
    v103 = stack[-4];
    v102 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    if (equal(stack[0], v102)) goto v50;
    v102 = (Lisp_Object)1; /* 0 */
    stack[-2] = v102;
    goto v123;

v50:
    v102 = stack[-3];
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    if (v102 == nil) goto v115;
    stack[0] = stack[-2];
    v103 = stack[-4];
    v102 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v102 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v102 + TAG_FIXNUM);
    stack[-2] = v102;
    v102 = stack[-1];
    v102 = (Lisp_Object)((int32_t)(v102) + 0x10);
    stack[-1] = v102;
    v102 = stack[-3];
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    stack[-3] = v102;
    goto v123;

v115:
    v102 = (Lisp_Object)1; /* 0 */
    stack[-2] = v102;
    v102 = stack[-3];
    v102 = qcar(v102);
    v102 = qcdr(v102);
    stack[-5] = v102;
    goto v123;

v3:
    v102 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v102); }
/* error exit handlers */
v181:
    popv(7);
    return nil;
}



/* Code for exptcompare */

static Lisp_Object CC_exptcompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v21, v22;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptcompare");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v52;
    v22 = v0;
/* end of prologue */
    v68 = v22;
    if (!consp(v68)) goto v2;
    v68 = v21;
    if (!consp(v68)) goto v17;
    v68 = v22;
    v68 = qcar(v68);
    v21 = qcar(v21);
        return Lgreaterp(nil, v68, v21);

v17:
    v68 = qvalue(elt(env, 2)); /* t */
    return onevalue(v68);

v2:
    v68 = v21;
    if (!consp(v68)) goto v81;
    v68 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v68);

v81:
    v68 = v22;
        return Lgreaterp(nil, v68, v21);
}



/* Code for qsort */

static Lisp_Object CC_qsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qsort");
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
    v120 = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = nil;
    v111 = v120;
    if (v111 == nil) goto v58;
    v111 = v120;
    v111 = qcar(v111);
    stack[-3] = v111;
    v111 = v120;
    v111 = qcdr(v111);
    stack[0] = v111;
    goto v101;

v101:
    v111 = stack[0];
    if (v111 == nil) goto v38;
    v120 = stack[-3];
    v111 = stack[0];
    v111 = qcar(v111);
    fn = elt(env, 2); /* ordop */
    v111 = (*qfn2(fn))(qenv(fn), v120, v111);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-4];
    if (v111 == nil) goto v98;
    v111 = stack[0];
    v120 = qcar(v111);
    v111 = stack[-1];
    v111 = cons(v120, v111);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-4];
    stack[-1] = v111;
    goto v13;

v13:
    v111 = stack[0];
    v111 = qcdr(v111);
    stack[0] = v111;
    goto v101;

v98:
    v111 = stack[0];
    v120 = qcar(v111);
    v111 = stack[-2];
    v111 = cons(v120, v111);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-4];
    stack[-2] = v111;
    goto v13;

v38:
    v111 = stack[-2];
    stack[0] = CC_qsort(env, v111);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-4];
    stack[-2] = stack[-3];
    v111 = stack[-1];
    v111 = CC_qsort(env, v111);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-4];
    v111 = cons(stack[-2], v111);
    nil = C_nil;
    if (exception_pending()) goto v109;
    {
        Lisp_Object v121 = stack[0];
        popv(5);
        return Lappend(nil, v121, v111);
    }

v58:
    v111 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v111); }
/* error exit handlers */
v109:
    popv(5);
    return nil;
}



/* Code for ibalp_clauselp */

static Lisp_Object CC_ibalp_clauselp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clauselp");
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

v185:
    v20 = stack[0];
    if (v20 == nil) goto v3;
    v20 = stack[0];
    v20 = qcar(v20);
    fn = elt(env, 3); /* ibalp_clausep */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    if (v20 == nil) goto v58;
    v20 = stack[0];
    v20 = qcdr(v20);
    stack[0] = v20;
    goto v185;

v58:
    v20 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v20); }

v3:
    v20 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v20); }
/* error exit handlers */
v16:
    popv(2);
    return nil;
}



/* Code for modminusp!: */

static Lisp_Object CC_modminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v28;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modminusp:");
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
    v13 = v0;
/* end of prologue */
    v28 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v28 == nil) goto v20;
    v28 = (Lisp_Object)33; /* 2 */
    v13 = qcdr(v13);
    v13 = times2(v28, v13);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[0];
    v28 = qvalue(elt(env, 2)); /* current!-modulus */
        popv(1);
        return Lgreaterp(nil, v13, v28);

v20:
    v13 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v13); }
/* error exit handlers */
v34:
    popv(1);
    return nil;
}



/* Code for vdpzero */

static Lisp_Object MS_CDECL CC_vdpzero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vdpzero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpzero");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v7 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* a2vdp */
        return (*qfn1(fn))(qenv(fn), v7);
    }
}



/* Code for scal!*list */

static Lisp_Object CC_scalHlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scal*list");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v52;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v10;

v10:
    v43 = stack[0];
    if (v43 == nil) goto v57;
    v123 = stack[-1];
    v43 = stack[0];
    v43 = qcar(v43);
    fn = elt(env, 1); /* !:times */
    v123 = (*qfn2(fn))(qenv(fn), v123, v43);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-3];
    v43 = stack[-2];
    v43 = cons(v123, v43);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-3];
    stack[-2] = v43;
    v43 = stack[0];
    v43 = qcdr(v43);
    stack[0] = v43;
    goto v10;

v57:
    v43 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v43);
    }
/* error exit handlers */
v60:
    popv(4);
    return nil;
}



/* Code for freeofdepl */

static Lisp_Object MS_CDECL CC_freeofdepl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v52,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "freeofdepl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeofdepl");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v52,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v52;
    stack[-2] = v0;
/* end of prologue */

v10:
    v22 = stack[-2];
    if (v22 == nil) goto v57;
    v61 = stack[0];
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcdr(v22);
    fn = elt(env, 3); /* smember */
    v22 = (*qfn2(fn))(qenv(fn), v61, v22);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-3];
    if (v22 == nil) goto v48;
    v22 = stack[-2];
    v22 = qcar(v22);
    v61 = qcar(v22);
    v22 = stack[-1];
    fn = elt(env, 3); /* smember */
    v22 = (*qfn2(fn))(qenv(fn), v61, v22);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-3];
    if (v22 == nil) goto v48;
    v22 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v22); }

v48:
    v22 = stack[-2];
    v22 = qcdr(v22);
    stack[-2] = v22;
    goto v10;

v57:
    v22 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v22); }
/* error exit handlers */
v72:
    popv(4);
    return nil;
}



/* Code for quotdd */

static Lisp_Object CC_quotdd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v139, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotdd");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v52;
    stack[-1] = v0;
/* end of prologue */
    v76 = stack[-1];
    if (!(!consp(v76))) goto v46;
    v76 = stack[0];
    if (!consp(v76)) goto v25;
    v76 = stack[0];
    v139 = qcar(v76);
    v76 = elt(env, 2); /* i2d */
    v76 = get(v139, v76);
    env = stack[-2];
    v77 = v76;
    if (v76 == nil) goto v22;
    v139 = v77;
    v76 = stack[-1];
    v76 = Lapply1(nil, v139, v76);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    stack[-1] = v76;
    goto v46;

v46:
    v77 = stack[-1];
    v139 = stack[0];
    v76 = elt(env, 3); /* quotient */
    {
        popv(3);
        fn = elt(env, 4); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v77, v139, v76);
    }

v22:
    v76 = stack[0];
    if (!consp(v76)) goto v14;
    v76 = qvalue(elt(env, 1)); /* nil */
    goto v35;

v35:
    if (v76 == nil) goto v46;
    v139 = v77;
    v76 = stack[0];
    v76 = Lapply1(nil, v139, v76);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    stack[0] = v76;
    goto v46;

v14:
    v76 = stack[-1];
    v139 = qcar(v76);
    v76 = elt(env, 2); /* i2d */
    v76 = get(v139, v76);
    env = stack[-2];
    v77 = v76;
    goto v35;

v25:
    v139 = stack[-1];
    v76 = stack[0];
    v76 = Ldivide(nil, v139, v76);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v77 = v76;
    v76 = v77;
    v139 = qcdr(v76);
    v76 = (Lisp_Object)1; /* 0 */
    if (v139 == v76) goto v13;
    v76 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v76); }

v13:
    v76 = v77;
    v76 = qcar(v76);
    { popv(3); return onevalue(v76); }
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for formclis */

static Lisp_Object MS_CDECL CC_formclis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v52,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v56, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formclis");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v52,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v52;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v1;

v1:
    v122 = stack[-2];
    if (v122 == nil) goto v29;
    v122 = stack[-2];
    v48 = qcar(v122);
    v56 = stack[-1];
    v122 = stack[0];
    fn = elt(env, 1); /* formc */
    v56 = (*qfnn(fn))(qenv(fn), 3, v48, v56, v122);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v122 = stack[-3];
    v122 = cons(v56, v122);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-3] = v122;
    v122 = stack[-2];
    v122 = qcdr(v122);
    stack[-2] = v122;
    goto v1;

v29:
    v122 = stack[-3];
        popv(5);
        return Lnreverse(nil, v122);
/* error exit handlers */
v61:
    popv(5);
    return nil;
}



/* Code for formop */

static Lisp_Object CC_formop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formop");
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
    goto v10;

v10:
    v73 = stack[-1];
    if (!consp(v73)) goto v140;
    v73 = stack[-1];
    v73 = qcar(v73);
    v73 = (consp(v73) ? nil : lisp_true);
    goto v81;

v81:
    if (v73 == nil) goto v27;
    v73 = stack[-1];
    v79 = v73;
    goto v101;

v101:
    v73 = stack[-2];
    if (v73 == nil) { popv(4); return onevalue(v79); }
    v73 = stack[-2];
    v73 = qcar(v73);
    fn = elt(env, 2); /* raddf */
    v73 = (*qfn2(fn))(qenv(fn), v73, v79);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    v79 = v73;
    v73 = stack[-2];
    v73 = qcdr(v73);
    stack[-2] = v73;
    goto v101;

v27:
    v73 = stack[-1];
    v73 = qcar(v73);
    stack[0] = qcar(v73);
    v73 = stack[-1];
    v73 = qcar(v73);
    v73 = qcdr(v73);
    v73 = CC_formop(env, v73);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    fn = elt(env, 3); /* multop */
    v79 = (*qfn2(fn))(qenv(fn), stack[0], v73);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    v73 = stack[-2];
    v73 = cons(v79, v73);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    stack[-2] = v73;
    v73 = stack[-1];
    v73 = qcdr(v73);
    stack[-1] = v73;
    goto v10;

v140:
    v73 = qvalue(elt(env, 1)); /* t */
    goto v81;
/* error exit handlers */
v15:
    popv(4);
    return nil;
}



/* Code for dp_times_bc */

static Lisp_Object CC_dp_times_bc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_times_bc");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v40 = v52;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v40;
    v40 = stack[-5];
    if (v40 == nil) goto v58;
    v40 = stack[-5];
    v40 = qcar(v40);
    v39 = v40;
    stack[0] = qcar(v39);
    v39 = stack[-4];
    v40 = qcdr(v40);
    fn = elt(env, 2); /* bc_prod */
    v40 = (*qfn2(fn))(qenv(fn), v39, v40);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v40 = cons(stack[0], v40);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v40 = ncons(v40);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    stack[-2] = v40;
    stack[-3] = v40;
    goto v101;

v101:
    v40 = stack[-5];
    v40 = qcdr(v40);
    stack[-5] = v40;
    v40 = stack[-5];
    if (v40 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v40 = stack[-5];
    v40 = qcar(v40);
    v39 = v40;
    stack[0] = qcar(v39);
    v39 = stack[-4];
    v40 = qcdr(v40);
    fn = elt(env, 2); /* bc_prod */
    v40 = (*qfn2(fn))(qenv(fn), v39, v40);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v40 = cons(stack[0], v40);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v40 = ncons(v40);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v40 = Lrplacd(nil, stack[-1], v40);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v40 = stack[-2];
    v40 = qcdr(v40);
    stack[-2] = v40;
    goto v101;

v58:
    v40 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v40); }
/* error exit handlers */
v109:
    popv(7);
    return nil;
}



/* Code for pv_neg */

static Lisp_Object CC_pv_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v122, v56;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_neg");
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
    goto v1;

v1:
    v123 = stack[0];
    if (v123 == nil) goto v10;
    v123 = stack[0];
    v123 = qcar(v123);
    v123 = qcar(v123);
    v56 = negate(v123);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v123 = stack[0];
    v123 = qcar(v123);
    v122 = qcdr(v123);
    v123 = stack[-1];
    v123 = acons(v56, v122, v123);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    stack[-1] = v123;
    v123 = stack[0];
    v123 = qcdr(v123);
    stack[0] = v123;
    goto v1;

v10:
    v123 = stack[-1];
        popv(3);
        return Lnreverse(nil, v123);
/* error exit handlers */
v68:
    popv(3);
    return nil;
}



/* Code for pst_termnodep */

static Lisp_Object CC_pst_termnodep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v81;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_termnodep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v59 = v0;
/* end of prologue */
    v81 = qcdr(v59);
    v59 = (Lisp_Object)1; /* 0 */
    v59 = *(Lisp_Object *)((char *)v81 + (CELL-TAG_VECTOR) + ((int32_t)v59/(16/CELL)));
    v59 = qcdr(v59);
    v59 = (v59 == nil ? lisp_true : nil);
    return onevalue(v59);
}



/* Code for artimes!: */

static Lisp_Object CC_artimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v28, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for artimes:");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v28 = v52;
    v34 = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = nil; /* !*exp */
    v13 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v13; /* !*exp */
    stack[0] = elt(env, 4); /* !:ar!: */
    v13 = v34;
    v13 = qcdr(v13);
    v28 = qcdr(v28);
    fn = elt(env, 5); /* multf */
    v13 = (*qfn2(fn))(qenv(fn), v13, v28);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    fn = elt(env, 6); /* reducepowers */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    v13 = cons(stack[0], v13);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v13); }
/* error exit handlers */
v54:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for conv!:mt */

static Lisp_Object CC_convTmt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conv:mt");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v52;
    stack[-2] = v0;
/* end of prologue */
    v220 = stack[-2];
    v126 = elt(env, 1); /* !:rd!: */
    if (!consp(v220)) goto v28;
    v220 = qcar(v220);
    if (!(v220 == v126)) goto v28;
    v126 = stack[-2];
    v126 = qcdr(v126);
    v126 = (consp(v126) ? nil : lisp_true);
    v126 = (v126 == nil ? lisp_true : nil);
    goto v58;

v58:
    if (v126 == nil) goto v72;
    v126 = stack[0];
    v126 = integerp(v126);
    if (v126 == nil) goto v54;
    v220 = stack[0];
    v126 = (Lisp_Object)1; /* 0 */
    v126 = (Lisp_Object)greaterp2(v220, v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v126 = v126 ? lisp_true : nil;
    env = stack[-4];
    goto v101;

v101:
    if (v126 == nil) goto v26;
    v126 = stack[-2];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    v126 = Labsval(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    fn = elt(env, 4); /* msd */
    v220 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v126 = stack[0];
    v220 = difference2(v220, v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    stack[0] = v220;
    v126 = (Lisp_Object)1; /* 0 */
    if (v220 == v126) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v220 = stack[0];
    v126 = (Lisp_Object)1; /* 0 */
    v126 = (Lisp_Object)lessp2(v220, v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v126 = v126 ? lisp_true : nil;
    env = stack[-4];
    if (v126 == nil) goto v138;
    v126 = stack[0];
    v126 = negate(v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    stack[-3] = v126;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v126 = stack[-2];
    v126 = qcdr(v126);
    v220 = qcar(v126);
    v126 = stack[-3];
    stack[0] = Lash1(nil, v220, v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v126 = stack[-2];
    v126 = qcdr(v126);
    v220 = qcdr(v126);
    v126 = stack[-3];
    v126 = difference2(v220, v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    {
        Lisp_Object v221 = stack[-1];
        Lisp_Object v222 = stack[0];
        popv(5);
        return list2star(v221, v222, v126);
    }

v138:
    v126 = stack[0];
    v126 = sub1(v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    stack[-3] = v126;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v126 = stack[-2];
    v126 = qcdr(v126);
    stack[0] = qcar(v126);
    v126 = stack[-3];
    v126 = negate(v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v126 = stack[-2];
    v126 = qcdr(v126);
    v220 = qcdr(v126);
    v126 = stack[-3];
    v126 = plus2(v220, v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v126 = list2star(stack[-1], stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 5); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v126);
    }

v26:
    stack[0] = (Lisp_Object)1; /* 0 */
    v220 = elt(env, 3); /* "Invalid argument to" */
    v126 = elt(env, 0); /* conv!:mt */
    v126 = list2(v220, v126);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    {
        Lisp_Object v223 = stack[0];
        popv(5);
        fn = elt(env, 6); /* error */
        return (*qfn2(fn))(qenv(fn), v223, v126);
    }

v54:
    v126 = qvalue(elt(env, 2)); /* nil */
    goto v101;

v72:
    v126 = qvalue(elt(env, 2)); /* nil */
    goto v101;

v28:
    v126 = qvalue(elt(env, 2)); /* nil */
    goto v58;
/* error exit handlers */
v135:
    popv(5);
    return nil;
}



/* Code for diff */

static Lisp_Object CC_diff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v52)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff");
#endif
    if (stack >= stacklimit)
    {
        push2(v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v52;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v1;

v1:
    v8 = stack[-3];
    if (!consp(v8)) goto v114;
    v8 = stack[-3];
    v8 = qcar(v8);
    v8 = (consp(v8) ? nil : lisp_true);
    goto v140;

v140:
    if (v8 == nil) goto v63;
    v8 = qvalue(elt(env, 2)); /* nil */
    v9 = v8;
    goto v57;

v57:
    v8 = stack[-4];
    if (v8 == nil) { popv(6); return onevalue(v9); }
    v8 = stack[-4];
    v8 = qcar(v8);
    fn = elt(env, 3); /* addf */
    v8 = (*qfn2(fn))(qenv(fn), v8, v9);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    v9 = v8;
    v8 = stack[-4];
    v8 = qcdr(v8);
    stack[-4] = v8;
    goto v57;

v63:
    v8 = stack[-3];
    v8 = qcar(v8);
    v9 = qcar(v8);
    v8 = (Lisp_Object)17; /* 1 */
    v8 = cons(v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    stack[0] = ncons(v8);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    v8 = stack[-3];
    v8 = qcar(v8);
    v9 = qcdr(v8);
    v8 = stack[-2];
    v8 = CC_diff(env, v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    fn = elt(env, 4); /* multf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v8);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    v8 = stack[-3];
    v8 = qcar(v8);
    stack[0] = qcdr(v8);
    v8 = stack[-3];
    v8 = qcar(v8);
    v9 = qcar(v8);
    v8 = stack[-2];
    fn = elt(env, 5); /* diffp1 */
    v8 = (*qfn2(fn))(qenv(fn), v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    fn = elt(env, 4); /* multf */
    v8 = (*qfn2(fn))(qenv(fn), stack[0], v8);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    fn = elt(env, 3); /* addf */
    v9 = (*qfn2(fn))(qenv(fn), stack[-1], v8);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    v8 = stack[-4];
    v8 = cons(v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    stack[-4] = v8;
    v8 = stack[-3];
    v8 = qcdr(v8);
    stack[-3] = v8;
    goto v1;

v114:
    v8 = qvalue(elt(env, 1)); /* t */
    goto v140;
/* error exit handlers */
v108:
    popv(6);
    return nil;
}



/* Code for removeg1 */

static Lisp_Object MS_CDECL CC_removeg1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v52,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v264, v265, v266, v267;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "removeg1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeg1");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v52,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v52,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v6;
    stack[-4] = v52;
    stack[-5] = v0;
/* end of prologue */
    v265 = stack[-5];
    v264 = stack[-4];
    fn = elt(env, 9); /* removev */
    v264 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v265 = stack[-5];
    v264 = stack[-3];
    fn = elt(env, 9); /* removev */
    v264 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = stack[-4];
    v264 = qcdr(v264);
    v265 = qcar(v264);
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v264 = qcar(v264);
    if (v265 == v264) goto v64;
    v264 = qvalue(elt(env, 1)); /* nil */
    goto v27;

v27:
    if (v264 == nil) goto v213;
    v265 = qvalue(elt(env, 2)); /* n!*!*2!-1 */
    v264 = stack[-5];
    v264 = qcar(v264);
    fn = elt(env, 10); /* multsq */
    v265 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = stack[-5];
    v264 = qcdr(v264);
    v264 = cons(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    popv(8);
    return ncons(v264);

v213:
    v264 = stack[-5];
    v265 = qcdr(v264);
    v264 = stack[-4];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v264 = qcar(v264);
    fn = elt(env, 11); /* finde */
    v264 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    stack[-6] = v264;
    v264 = stack[-4];
    v264 = qcdr(v264);
    v265 = qcar(v264);
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v264 = qcar(v264);
    if (v265 == v264) goto v12;
    v264 = stack[-5];
    v265 = qcdr(v264);
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v264 = qcar(v264);
    fn = elt(env, 11); /* finde */
    v264 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    stack[-2] = v264;
    v264 = stack[-4];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v265 = qcar(v264);
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    if (v265 == v264) goto v269;
    v264 = stack[-6];
    if (v264 == nil) goto v270;
    v264 = stack[-2];
    v264 = (v264 == nil ? lisp_true : nil);
    goto v271;

v271:
    if (v264 == nil) goto v272;
    stack[0] = elt(env, 7); /* "Invalid structure of c-graph" */
    v264 = stack[-5];
    if (v264 == nil) goto v273;
    v264 = stack[-5];
    v264 = qcdr(v264);
    if (v264 == nil) goto v148;
    v265 = elt(env, 8); /* times */
    v264 = stack[-5];
    v264 = cons(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    goto v274;

v274:
    v264 = list2(stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    fn = elt(env, 12); /* cerror */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    goto v272;

v272:
    v264 = stack[-6];
    v264 = qcar(v264);
    stack[-6] = v264;
    v264 = stack[-2];
    v264 = qcar(v264);
    stack[-2] = v264;
    v264 = stack[-6];
    v265 = qcdr(v264);
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    v264 = Lrplaca(nil, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = stack[-2];
    v265 = qcdr(v264);
    v264 = stack[-4];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    v264 = Lrplaca(nil, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = stack[-5];
    stack[0] = qcar(v264);
    v264 = stack[-5];
    v264 = qcdr(v264);
    fn = elt(env, 13); /* mkcopy */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = cons(stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    stack[-1] = v264;
    v264 = stack[-1];
    v264 = qcdr(v264);
    stack[0] = v264;
    v265 = stack[-6];
    v264 = stack[0];
    v264 = Lmember(nil, v265, v264);
    v264 = qcar(v264);
    stack[-6] = v264;
    v265 = stack[-2];
    v264 = stack[0];
    v264 = Lmember(nil, v265, v264);
    v264 = qcar(v264);
    stack[-2] = v264;
    v264 = stack[-6];
    v265 = qcdr(v264);
    v264 = stack[-4];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    v264 = Lrplaca(nil, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = stack[-2];
    v265 = qcdr(v264);
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    v264 = Lrplaca(nil, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    stack[-3] = stack[-5];
    v265 = (Lisp_Object)-15; /* -1 */
    v264 = (Lisp_Object)17; /* 1 */
    stack[-2] = cons(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = qvalue(elt(env, 5)); /* su_order */
    fn = elt(env, 14); /* invsq */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v265 = (*qfn2(fn))(qenv(fn), stack[-2], v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = stack[-1];
    v264 = qcar(v264);
    fn = elt(env, 10); /* multsq */
    v265 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    v264 = stack[0];
    {
        Lisp_Object v275 = stack[-3];
        popv(8);
        return list2star(v275, v265, v264);
    }

v148:
    v264 = stack[-5];
    v264 = qcar(v264);
    goto v274;

v273:
    v264 = qvalue(elt(env, 1)); /* nil */
    goto v274;

v270:
    v264 = qvalue(elt(env, 6)); /* t */
    goto v271;

v269:
    v264 = stack[-2];
    if (v264 == nil) goto v276;
    v264 = stack[-2];
    v264 = qcar(v264);
    v265 = qcdr(v264);
    v264 = stack[-4];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    v264 = Lrplaca(nil, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    goto v206;

v206:
    stack[0] = qvalue(elt(env, 2)); /* n!*!*2!-1 */
    v264 = qvalue(elt(env, 5)); /* su_order */
    fn = elt(env, 14); /* invsq */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v265 = (*qfn2(fn))(qenv(fn), stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = stack[-5];
    v264 = qcar(v264);
    fn = elt(env, 10); /* multsq */
    v265 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = stack[-5];
    v264 = qcdr(v264);
    v264 = cons(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    popv(8);
    return ncons(v264);

v276:
    v267 = elt(env, 3); /* "Free edge" */
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v266 = qcar(v264);
    v265 = elt(env, 4); /* "in vertex" */
    v264 = stack[-3];
    v264 = list4(v267, v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    fn = elt(env, 12); /* cerror */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    goto v206;

v12:
    v264 = stack[-6];
    if (v264 == nil) goto v100;
    v264 = stack[-6];
    v264 = qcar(v264);
    v265 = qcdr(v264);
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    v264 = Lrplaca(nil, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    goto v214;

v214:
    stack[0] = qvalue(elt(env, 2)); /* n!*!*2!-1 */
    v264 = qvalue(elt(env, 5)); /* su_order */
    fn = elt(env, 14); /* invsq */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v265 = (*qfn2(fn))(qenv(fn), stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = stack[-5];
    v264 = qcar(v264);
    fn = elt(env, 10); /* multsq */
    v265 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    v264 = stack[-5];
    v264 = qcdr(v264);
    v264 = cons(v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    popv(8);
    return ncons(v264);

v100:
    v267 = elt(env, 3); /* "Free edge" */
    v264 = stack[-4];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v266 = qcar(v264);
    v265 = elt(env, 4); /* "in vertex" */
    v264 = stack[-4];
    v264 = list4(v267, v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    fn = elt(env, 12); /* cerror */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-7];
    goto v214;

v64:
    v264 = stack[-4];
    v264 = qcdr(v264);
    v264 = qcdr(v264);
    v265 = qcar(v264);
    v264 = stack[-3];
    v264 = qcdr(v264);
    v264 = qcar(v264);
    v264 = (v265 == v264 ? lisp_true : nil);
    goto v27;
/* error exit handlers */
v268:
    popv(8);
    return nil;
}



/* Code for lastnondomain */

static Lisp_Object CC_lastnondomain(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lastnondomain");
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
    v97 = v0;
/* end of prologue */

v3:
    v98 = v97;
    if (!consp(v98)) goto v30;
    v98 = v97;
    v98 = qcar(v98);
    v98 = (consp(v98) ? nil : lisp_true);
    goto v29;

v29:
    if (v98 == nil) goto v101;
    v98 = elt(env, 2); /* "non-domain" */
    v97 = list2(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* errach */
        return (*qfn1(fn))(qenv(fn), v97);
    }

v101:
    v98 = v97;
    v98 = qcdr(v98);
    if (!consp(v98)) goto v44;
    v98 = v97;
    v98 = qcdr(v98);
    v98 = qcar(v98);
    v98 = (consp(v98) ? nil : lisp_true);
    goto v54;

v54:
    if (!(v98 == nil)) { popv(1); return onevalue(v97); }
    v97 = qcdr(v97);
    goto v3;

v44:
    v98 = qvalue(elt(env, 1)); /* t */
    goto v54;

v30:
    v98 = qvalue(elt(env, 1)); /* t */
    goto v29;
/* error exit handlers */
v65:
    popv(1);
    return nil;
}



setup_type const u11_setup[] =
{
    {"variables",               CC_variables,   too_many_1,    wrong_no_1},
    {"flatindxl",               CC_flatindxl,   too_many_1,    wrong_no_1},
    {"list+list",               too_few_2,      CC_listLlist,  wrong_no_2},
    {"nth",                     too_few_2,      CC_nth,        wrong_no_2},
    {"split-road",              too_few_2,      CC_splitKroad, wrong_no_2},
    {"aminusp:",                CC_aminuspT,    too_many_1,    wrong_no_1},
    {"mv-pow-chk",              too_few_2,      CC_mvKpowKchk, wrong_no_2},
    {"dd",                      too_few_2,      CC_dd,         wrong_no_2},
    {"make-univariate-image-mod-p",too_few_2,   CC_makeKunivariateKimageKmodKp,wrong_no_2},
    {"qqe_id-nyt-branchq",      CC_qqe_idKnytKbranchq,too_many_1,wrong_no_1},
    {"ibalp_getnewwl",          CC_ibalp_getnewwl,too_many_1,  wrong_no_1},
    {"sacar",                   too_few_2,      CC_sacar,      wrong_no_2},
    {"initbrsea",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_initbrsea},
    {"scalprod",                too_few_2,      CC_scalprod,   wrong_no_2},
    {"gsugar",                  CC_gsugar,      too_many_1,    wrong_no_1},
    {"xord_lex",                too_few_2,      CC_xord_lex,   wrong_no_2},
    {"mkinds",                  too_few_2,      CC_mkinds,     wrong_no_2},
    {"bc_zero?",                CC_bc_zeroW,    too_many_1,    wrong_no_1},
    {"psum",                    too_few_2,      CC_psum,       wrong_no_2},
    {"general-reciprocal-by-gcd",wrong_no_na,   wrong_no_nb,   (n_args *)CC_generalKreciprocalKbyKgcd},
    {"replus",                  CC_replus,      too_many_1,    wrong_no_1},
    {"gcdf2",                   too_few_2,      CC_gcdf2,      wrong_no_2},
    {"matrix+p",                CC_matrixLp,    too_many_1,    wrong_no_1},
    {"freevarinexptchk",        CC_freevarinexptchk,too_many_1,wrong_no_1},
    {"qqe_qprefix-var",         CC_qqe_qprefixKvar,too_many_1, wrong_no_1},
    {"pasf_smwcpknowl",         CC_pasf_smwcpknowl,too_many_1, wrong_no_1},
    {"ibalp_simpterm",          CC_ibalp_simpterm,too_many_1,  wrong_no_1},
    {"exchk1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_exchk1},
    {"dm-eq",                   too_few_2,      CC_dmKeq,      wrong_no_2},
    {"powers1",                 CC_powers1,     too_many_1,    wrong_no_1},
    {"simptimes",               CC_simptimes,   too_many_1,    wrong_no_1},
    {"mo=deglist",              CC_moMdeglist,  too_many_1,    wrong_no_1},
    {"modquotient:",            too_few_2,      CC_modquotientT,wrong_no_2},
    {"qcputx",                  CC_qcputx,      too_many_1,    wrong_no_1},
    {"janettreefind",           CC_janettreefind,too_many_1,   wrong_no_1},
    {"exptcompare",             too_few_2,      CC_exptcompare,wrong_no_2},
    {"qsort",                   CC_qsort,       too_many_1,    wrong_no_1},
    {"ibalp_clauselp",          CC_ibalp_clauselp,too_many_1,  wrong_no_1},
    {"modminusp:",              CC_modminuspT,  too_many_1,    wrong_no_1},
    {"vdpzero",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpzero},
    {"scal*list",               too_few_2,      CC_scalHlist,  wrong_no_2},
    {"freeofdepl",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_freeofdepl},
    {"quotdd",                  too_few_2,      CC_quotdd,     wrong_no_2},
    {"formclis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclis},
    {"formop",                  CC_formop,      too_many_1,    wrong_no_1},
    {"dp_times_bc",             too_few_2,      CC_dp_times_bc,wrong_no_2},
    {"pv_neg",                  CC_pv_neg,      too_many_1,    wrong_no_1},
    {"pst_termnodep",           CC_pst_termnodep,too_many_1,   wrong_no_1},
    {"artimes:",                too_few_2,      CC_artimesT,   wrong_no_2},
    {"conv:mt",                 too_few_2,      CC_convTmt,    wrong_no_2},
    {"diff",                    too_few_2,      CC_diff,       wrong_no_2},
    {"removeg1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_removeg1},
    {"lastnondomain",           CC_lastnondomain,too_many_1,   wrong_no_1},
    {NULL, (one_args *)"u11", (two_args *)"3623 4508784 9998587", 0}
};

/* end of generated code */
