
/* $destdir\u31.c        Machine generated C code */

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


/* Code for specrd!:plus */

static Lisp_Object CC_specrdTplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for specrd:plus");
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
    v33 = (Lisp_Object)1; /* 0 */
    stack[-2] = v33;
    v33 = stack[-1];
    fn = elt(env, 3); /* add_minus */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[-1] = v33;
    v33 = stack[0];
    fn = elt(env, 3); /* add_minus */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[0] = v33;
    v34 = stack[-1];
    v33 = elt(env, 1); /* minus */
    if (!consp(v34)) goto v36;
    v34 = qcar(v34);
    if (!(v34 == v33)) goto v36;
    v33 = stack[-1];
    v33 = qcdr(v33);
    v33 = qcar(v33);
    stack[-1] = v33;
    v33 = (Lisp_Object)17; /* 1 */
    stack[-2] = v33;
    goto v36;

v36:
    v34 = stack[0];
    v33 = elt(env, 1); /* minus */
    if (!consp(v34)) goto v37;
    v34 = qcar(v34);
    if (!(v34 == v33)) goto v37;
    v33 = stack[0];
    v33 = qcdr(v33);
    v33 = qcar(v33);
    stack[0] = v33;
    v34 = stack[-2];
    v33 = (Lisp_Object)33; /* 2 */
    v33 = plus2(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[-2] = v33;
    goto v37;

v37:
    v33 = stack[-1];
    if (!(!consp(v33))) goto v38;
    v33 = stack[-1];
    v33 = Lfloat(nil, v33);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    v34 = v33;
    if (!(!consp(v34))) goto v39;
    v34 = elt(env, 2); /* !:rd!: */
    v33 = cons(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    goto v39;

v39:
    stack[-1] = v33;
    goto v38;

v38:
    v33 = stack[0];
    if (!(!consp(v33))) goto v40;
    v33 = stack[0];
    v33 = Lfloat(nil, v33);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    v34 = v33;
    if (!(!consp(v34))) goto v41;
    v34 = elt(env, 2); /* !:rd!: */
    v33 = cons(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    goto v41;

v41:
    stack[0] = v33;
    goto v40;

v40:
    v34 = stack[-2];
    v33 = (Lisp_Object)1; /* 0 */
    if (v34 == v33) goto v42;
    v34 = stack[-2];
    v33 = (Lisp_Object)49; /* 3 */
    if (v34 == v33) goto v43;
    v34 = stack[-2];
    v33 = (Lisp_Object)33; /* 2 */
    if (v34 == v33) goto v44;
    v34 = stack[0];
    v33 = stack[-1];
    {
        popv(4);
        fn = elt(env, 4); /* rd!:difference */
        return (*qfn2(fn))(qenv(fn), v34, v33);
    }

v44:
    v34 = stack[-1];
    v33 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* rd!:difference */
        return (*qfn2(fn))(qenv(fn), v34, v33);
    }

v43:
    stack[-2] = elt(env, 1); /* minus */
    v34 = stack[-1];
    v33 = stack[0];
    fn = elt(env, 5); /* rd!:plus */
    v33 = (*qfn2(fn))(qenv(fn), v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v35;
    {
        Lisp_Object v45 = stack[-2];
        popv(4);
        return list2(v45, v33);
    }

v42:
    v34 = stack[-1];
    v33 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* rd!:plus */
        return (*qfn2(fn))(qenv(fn), v34, v33);
    }
/* error exit handlers */
v35:
    popv(4);
    return nil;
}



/* Code for dip2a */

static Lisp_Object CC_dip2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip2a");
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
    v47 = v0;
/* end of prologue */
    v46 = v47;
    if (v46 == nil) goto v48;
    v46 = v47;
    fn = elt(env, 1); /* dip2a1 */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dipreplus */
        return (*qfn1(fn))(qenv(fn), v46);
    }

v48:
    v46 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v46); }
/* error exit handlers */
v49:
    popv(1);
    return nil;
}



/* Code for vdpilcomb1 */

static Lisp_Object MS_CDECL CC_vdpilcomb1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v50, Lisp_Object v8,
                         Lisp_Object v48, Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v64, v65, v20, v19, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "vdpilcomb1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpilcomb1");
#endif
    if (stack >= stacklimit)
    {
        push6(v51,v48,v8,v50,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v50,v8,v48,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v51;
    v63 = v48;
    stack[-2] = v8;
    stack[-3] = v50;
    v64 = v1;
    stack[-4] = v0;
/* end of prologue */
    v65 = stack[-4];
    v65 = qcdr(v65);
    v65 = qcdr(v65);
    v65 = qcdr(v65);
    v41 = qcar(v65);
    v19 = v64;
    v20 = stack[-3];
    v64 = stack[-2];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v65 = qcar(v64);
    v64 = v63;
    v63 = stack[-1];
    fn = elt(env, 2); /* dipilcomb1 */
    v63 = (*qfnn(fn))(qenv(fn), 6, v41, v19, v20, v65, v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-6];
    fn = elt(env, 3); /* dip2vdp */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-6];
    stack[-5] = v63;
    v63 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v63 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    stack[0] = stack[-5];
    v63 = stack[-4];
    fn = elt(env, 4); /* gsugar */
    stack[-4] = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-6];
    v63 = stack[-3];
    fn = elt(env, 5); /* vevtdeg */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-6];
    stack[-3] = plus2(stack[-4], v63);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-6];
    v63 = stack[-2];
    fn = elt(env, 4); /* gsugar */
    stack[-2] = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-6];
    v63 = stack[-1];
    fn = elt(env, 5); /* vevtdeg */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-6];
    v63 = plus2(stack[-2], v63);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-6];
    fn = elt(env, 6); /* max */
    v63 = (*qfn2(fn))(qenv(fn), stack[-3], v63);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-6];
    fn = elt(env, 7); /* gsetsugar */
    v63 = (*qfn2(fn))(qenv(fn), stack[0], v63);
    nil = C_nil;
    if (exception_pending()) goto v66;
    { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
/* error exit handlers */
v66:
    popv(7);
    return nil;
}



/* Code for simpwedge */

static Lisp_Object CC_simpwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpwedge");
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
    fn = elt(env, 1); /* partitwedge */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v51);
    }
/* error exit handlers */
v67:
    popv(1);
    return nil;
}



/* Code for rsubla */

static Lisp_Object CC_rsubla(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rsubla");
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
    v54 = stack[-1];
    if (v54 == nil) goto v75;
    v54 = stack[0];
    v54 = (v54 == nil ? lisp_true : nil);
    goto v76;

v76:
    if (!(v54 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v54 = stack[0];
    if (!consp(v54)) goto v62;
    v74 = stack[-1];
    v54 = stack[0];
    v54 = qcar(v54);
    stack[-2] = CC_rsubla(env, v74, v54);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-3];
    v74 = stack[-1];
    v54 = stack[0];
    v54 = qcdr(v54);
    v54 = CC_rsubla(env, v74, v54);
    nil = C_nil;
    if (exception_pending()) goto v77;
    {
        Lisp_Object v55 = stack[-2];
        popv(4);
        return cons(v55, v54);
    }

v62:
    v74 = stack[0];
    v54 = stack[-1];
    fn = elt(env, 2); /* rassoc */
    v54 = (*qfn2(fn))(qenv(fn), v74, v54);
    nil = C_nil;
    if (exception_pending()) goto v77;
    v74 = v54;
    if (v54 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v54 = v74;
    v54 = qcar(v54);
    { popv(4); return onevalue(v54); }

v75:
    v54 = qvalue(elt(env, 1)); /* t */
    goto v76;
/* error exit handlers */
v77:
    popv(4);
    return nil;
}



/* Code for physoptimes */

static Lisp_Object CC_physoptimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physoptimes");
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
    stack[0] = v0;
/* end of prologue */
    stack[-2] = nil;
    v107 = qvalue(elt(env, 1)); /* tstack!* */
    v106 = (Lisp_Object)1; /* 0 */
    if (v107 == v106) goto v108;
    v106 = qvalue(elt(env, 3)); /* nil */
    goto v109;

v109:
    if (v106 == nil) goto v46;
    v106 = qvalue(elt(env, 2)); /* mul!* */
    stack[-2] = v106;
    v106 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v106; /* mul!* */
    goto v46;

v46:
    v106 = qvalue(elt(env, 1)); /* tstack!* */
    v106 = add1(v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    qvalue(elt(env, 1)) = v106; /* tstack!* */
    v106 = stack[0];
    v106 = qcar(v106);
    fn = elt(env, 6); /* physopsim!* */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    stack[-6] = v106;
    v106 = stack[0];
    v106 = qcdr(v106);
    stack[-1] = v106;
    goto v111;

v111:
    v106 = stack[-1];
    if (v106 == nil) goto v73;
    v106 = stack[-1];
    v106 = qcar(v106);
    fn = elt(env, 6); /* physopsim!* */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    stack[-5] = v106;
    v106 = stack[-6];
    fn = elt(env, 7); /* getphystype */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    stack[-4] = v106;
    v106 = stack[-5];
    fn = elt(env, 7); /* getphystype */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    stack[-3] = v106;
    v106 = stack[-4];
    if (v106 == nil) goto v112;
    v106 = stack[-3];
    if (v106 == nil) goto v113;
    v106 = stack[-6];
    fn = elt(env, 8); /* physopaeval */
    stack[0] = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    v106 = stack[-5];
    fn = elt(env, 8); /* physopaeval */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 9); /* physopordchk */
    v106 = (*qfn2(fn))(qenv(fn), stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    if (v106 == nil) goto v114;
    v107 = stack[-4];
    v106 = stack[-3];
    if (equal(v107, v106)) goto v115;
    v106 = qvalue(elt(env, 3)); /* nil */
    goto v3;

v3:
    if (v106 == nil) goto v114;
    v106 = stack[-6];
    fn = elt(env, 10); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    v106 = stack[-5];
    fn = elt(env, 10); /* physop2sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 11); /* multsq */
    v106 = (*qfn2(fn))(qenv(fn), stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    stack[-6] = v106;
    goto v116;

v116:
    v106 = stack[-1];
    v106 = qcdr(v106);
    stack[-1] = v106;
    goto v111;

v114:
    v107 = stack[-6];
    v106 = stack[-5];
    fn = elt(env, 13); /* multopop!* */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    stack[-6] = v106;
    goto v116;

v115:
    v107 = stack[-4];
    v106 = elt(env, 4); /* scalar */
    v106 = (v107 == v106 ? lisp_true : nil);
    goto v3;

v113:
    v106 = stack[-5];
    v106 = (Lisp_Object)zerop(v106);
    v106 = v106 ? lisp_true : nil;
    env = stack[-7];
    if (v106 == nil) goto v117;
    v107 = qvalue(elt(env, 3)); /* nil */
    v106 = (Lisp_Object)17; /* 1 */
    v106 = cons(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    goto v118;

v118:
    stack[-6] = v106;
    goto v116;

v117:
    v106 = stack[-5];
    v106 = Lonep(nil, v106);
    env = stack[-7];
    if (v106 == nil) goto v119;
    v106 = stack[-6];
    fn = elt(env, 10); /* physop2sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    goto v118;

v119:
    v106 = stack[-5];
    fn = elt(env, 10); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    v106 = stack[-6];
    fn = elt(env, 10); /* physop2sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 11); /* multsq */
    v106 = (*qfn2(fn))(qenv(fn), stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    goto v118;

v112:
    v106 = stack[-3];
    if (v106 == nil) goto v77;
    v106 = stack[-6];
    v106 = (Lisp_Object)zerop(v106);
    v106 = v106 ? lisp_true : nil;
    env = stack[-7];
    if (v106 == nil) goto v19;
    v107 = qvalue(elt(env, 3)); /* nil */
    v106 = (Lisp_Object)17; /* 1 */
    v106 = cons(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    stack[-6] = v106;
    goto v116;

v19:
    v106 = stack[-6];
    v106 = Lonep(nil, v106);
    env = stack[-7];
    if (v106 == nil) goto v120;
    v106 = stack[-5];
    fn = elt(env, 10); /* physop2sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    stack[-6] = v106;
    goto v116;

v120:
    v106 = stack[-6];
    fn = elt(env, 10); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    v106 = stack[-5];
    fn = elt(env, 10); /* physop2sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 11); /* multsq */
    v106 = (*qfn2(fn))(qenv(fn), stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    stack[-6] = v106;
    goto v116;

v77:
    v106 = stack[-6];
    fn = elt(env, 10); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    v106 = stack[-5];
    fn = elt(env, 10); /* physop2sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 11); /* multsq */
    v106 = (*qfn2(fn))(qenv(fn), stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    stack[-6] = v106;
    goto v116;

v73:
    v106 = qvalue(elt(env, 2)); /* mul!* */
    if (v106 == nil) goto v121;
    v107 = qvalue(elt(env, 1)); /* tstack!* */
    v106 = (Lisp_Object)17; /* 1 */
    v106 = (Lisp_Object)greaterp2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    v106 = v106 ? lisp_true : nil;
    env = stack[-7];
    goto v122;

v122:
    if (v106 == nil) goto v123;
    v106 = qvalue(elt(env, 1)); /* tstack!* */
    v106 = sub1(v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    qvalue(elt(env, 1)) = v106; /* tstack!* */
    v107 = qvalue(elt(env, 1)); /* tstack!* */
    v106 = (Lisp_Object)1; /* 0 */
    if (!(v107 == v106)) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v106 = stack[-2];
    qvalue(elt(env, 2)) = v106; /* mul!* */
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v123:
    v106 = qvalue(elt(env, 2)); /* mul!* */
    v107 = qcar(v106);
    v106 = stack[-6];
    v106 = Lapply1(nil, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-7];
    stack[-6] = v106;
    v106 = qvalue(elt(env, 2)); /* mul!* */
    v106 = qcdr(v106);
    qvalue(elt(env, 2)) = v106; /* mul!* */
    goto v73;

v121:
    v106 = qvalue(elt(env, 5)); /* t */
    goto v122;

v108:
    v106 = qvalue(elt(env, 2)); /* mul!* */
    goto v109;
/* error exit handlers */
v110:
    popv(8);
    return nil;
}



/* Code for consrecip */

static Lisp_Object CC_consrecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v127, v128;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for consrecip");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v128 = v0;
/* end of prologue */
    v111 = v128;
    v127 = qcar(v111);
    v111 = (Lisp_Object)17; /* 1 */
    if (v127 == v111) goto v129;
    v111 = v128;
    v127 = qcar(v111);
    v111 = (Lisp_Object)-15; /* -1 */
    v111 = (v127 == v111 ? lisp_true : nil);
    goto v53;

v53:
    if (v111 == nil) goto v72;
    v111 = v128;
    v111 = qcar(v111);
    return onevalue(v111);

v72:
    v111 = elt(env, 2); /* recip */
    v127 = v128;
    return cons(v111, v127);

v129:
    v111 = qvalue(elt(env, 1)); /* t */
    goto v53;
}



/* Code for baglistp */

static Lisp_Object CC_baglistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72, v59;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for baglistp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v59 = v0;
/* end of prologue */
    v71 = v59;
    if (!consp(v71)) goto v60;
    v71 = v59;
    v72 = qcar(v71);
    v71 = elt(env, 1); /* list */
    if (v72 == v71) goto v130;
    v71 = v59;
    v71 = qcar(v71);
    v72 = elt(env, 3); /* bag */
        return Lflagp(nil, v71, v72);

v130:
    v71 = qvalue(elt(env, 2)); /* t */
    return onevalue(v71);

v60:
    v71 = qvalue(elt(env, 4)); /* nil */
    return onevalue(v71);
}



/* Code for make!-modular!-symmetric */

static Lisp_Object CC_makeKmodularKsymmetric(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-modular-symmetric");
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
    v56 = stack[-1];
    if (v56 == nil) goto v48;
    v56 = stack[-1];
    if (!consp(v56)) goto v75;
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = (consp(v56) ? nil : lisp_true);
    goto v76;

v76:
    if (v56 == nil) goto v23;
    v131 = stack[-1];
    v56 = qvalue(elt(env, 3)); /* modulus!/2 */
    v56 = (Lisp_Object)greaterp2(v131, v56);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v56 = v56 ? lisp_true : nil;
    env = stack[-3];
    if (v56 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v131 = stack[-1];
    v56 = qvalue(elt(env, 4)); /* current!-modulus */
    v56 = difference2(v131, v56);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    v131 = v56;
    v56 = v131;
    v56 = (Lisp_Object)zerop(v56);
    v56 = v56 ? lisp_true : nil;
    env = stack[-3];
    if (v56 == nil) { popv(4); return onevalue(v131); }
    v56 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v56); }

v23:
    v56 = stack[-1];
    v56 = qcar(v56);
    stack[-2] = qcar(v56);
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = qcdr(v56);
    stack[0] = CC_makeKmodularKsymmetric(env, v56);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    v56 = stack[-1];
    v56 = qcdr(v56);
    v56 = CC_makeKmodularKsymmetric(env, v56);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    {
        Lisp_Object v20 = stack[-2];
        Lisp_Object v19 = stack[0];
        popv(4);
        fn = elt(env, 5); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v20, v19, v56);
    }

v75:
    v56 = qvalue(elt(env, 2)); /* t */
    goto v76;

v48:
    v56 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v56); }
/* error exit handlers */
v65:
    popv(4);
    return nil;
}



/* Code for cl_rename!-vars */

static Lisp_Object CC_cl_renameKvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_rename-vars");
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
    v75 = v0;
/* end of prologue */
    stack[0] = v75;
    fn = elt(env, 1); /* cl_replace!-varl */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    fn = elt(env, 2); /* cl_rename!-vars1 */
    v75 = (*qfn2(fn))(qenv(fn), stack[0], v75);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v75 = qcar(v75);
    { popv(2); return onevalue(v75); }
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for rule */

static Lisp_Object MS_CDECL CC_rule(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v50, Lisp_Object v8, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v157, v80, v81, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rule");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rule");
#endif
    if (stack >= stacklimit)
    {
        push4(v8,v50,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v50,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v8;
    stack[0] = v50;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    v157 = stack[0];
    v156 = stack[-6];
    v156 = Lsubla(nil, v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    stack[-2] = v156;
    v157 = stack[-2];
    v156 = stack[-6];
    if (equal(v157, v156)) goto v23;
    v156 = stack[-2];
    if (!consp(v156)) goto v30;
    v156 = qvalue(elt(env, 4)); /* t */
    stack[-7] = v156;
    v156 = stack[-2];
    stack[-6] = v156;
    goto v23;

v23:
    v157 = stack[0];
    v156 = stack[-5];
    v156 = Lsubla(nil, v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    stack[-2] = v156;
    v157 = stack[-2];
    v156 = stack[-5];
    if (equal(v157, v156)) goto v69;
    v156 = stack[-2];
    stack[-5] = v156;
    v157 = stack[-5];
    v156 = elt(env, 5); /* !*sq!* */
    if (!consp(v157)) goto v69;
    v157 = qcar(v157);
    if (!(v157 == v156)) goto v69;
    v156 = stack[-5];
    v156 = qcdr(v156);
    v156 = qcar(v156);
    fn = elt(env, 11); /* prepsq!* */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    stack[-5] = v156;
    goto v69;

v69:
    v156 = stack[0];
    stack[-3] = v156;
    v156 = stack[-3];
    if (v156 == nil) goto v40;
    v156 = stack[-3];
    v156 = qcar(v156);
    v156 = qcdr(v156);
    v156 = ncons(v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    stack[-1] = v156;
    stack[-2] = v156;
    goto v160;

v160:
    v156 = stack[-3];
    v156 = qcdr(v156);
    stack[-3] = v156;
    v156 = stack[-3];
    if (v156 == nil) goto v16;
    stack[0] = stack[-1];
    v156 = stack[-3];
    v156 = qcar(v156);
    v156 = qcdr(v156);
    v156 = ncons(v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    v156 = Lrplacd(nil, stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    v156 = stack[-1];
    v156 = qcdr(v156);
    stack[-1] = v156;
    goto v160;

v16:
    v156 = stack[-2];
    goto v161;

v161:
    stack[0] = v156;
    v157 = stack[0];
    v156 = qvalue(elt(env, 6)); /* mcond!* */
    fn = elt(env, 12); /* smemql */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    stack[-2] = v156;
    v157 = stack[0];
    v156 = stack[-6];
    fn = elt(env, 12); /* smemql */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    stack[-1] = v156;
    v157 = stack[-2];
    v156 = stack[-1];
    fn = elt(env, 13); /* setdiff */
    v157 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    v156 = v157;
    if (!(v157 == nil)) goto v162;
    v157 = stack[0];
    v156 = stack[-5];
    fn = elt(env, 12); /* smemql */
    v157 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    v156 = stack[-2];
    fn = elt(env, 13); /* setdiff */
    stack[0] = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    v157 = stack[-1];
    v156 = stack[-2];
    fn = elt(env, 13); /* setdiff */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    fn = elt(env, 13); /* setdiff */
    v157 = (*qfn2(fn))(qenv(fn), stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    v156 = v157;
    if (!(v157 == nil)) goto v162;
    v157 = stack[-6];
    v156 = elt(env, 10); /* getel */
    if (!consp(v157)) goto v163;
    v157 = qcar(v157);
    if (!(v157 == v156)) goto v163;
    v156 = stack[-6];
    v156 = qcdr(v156);
    v156 = qcar(v156);
    fn = elt(env, 14); /* eval */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    stack[-6] = v156;
    goto v163;

v163:
    v158 = stack[-6];
    v81 = stack[-5];
    v80 = qvalue(elt(env, 3)); /* nil */
    v157 = stack[-4];
    v156 = stack[-7];
    {
        popv(9);
        fn = elt(env, 15); /* let3 */
        return (*qfnn(fn))(qenv(fn), 5, v158, v81, v80, v157, v156);
    }

v162:
    v157 = elt(env, 7); /* "Unmatched free variable(s)" */
    v156 = cons(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    fn = elt(env, 16); /* lprie */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-8];
    v156 = elt(env, 8); /* hold */
    qvalue(elt(env, 9)) = v156; /* erfg!* */
    v156 = qvalue(elt(env, 3)); /* nil */
    { popv(9); return onevalue(v156); }

v40:
    v156 = qvalue(elt(env, 3)); /* nil */
    goto v161;

v30:
    v158 = elt(env, 1); /* "Substitution for" */
    v81 = stack[-6];
    v80 = elt(env, 2); /* "not allowed" */
    v157 = qvalue(elt(env, 3)); /* nil */
    v156 = qvalue(elt(env, 4)); /* t */
    {
        popv(9);
        fn = elt(env, 17); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v158, v81, v80, v157, v156);
    }
/* error exit handlers */
v159:
    popv(9);
    return nil;
}



/* Code for cl_strict!-gdnf */

static Lisp_Object CC_cl_strictKgdnf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v125, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_strict-gdnf");
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
    v101 = v0;
/* end of prologue */
    v125 = v101;
    v101 = stack[0];
    fn = elt(env, 2); /* cl_strict!-gdnf1 */
    v124 = (*qfn2(fn))(qenv(fn), v125, v101);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-1];
    v125 = qvalue(elt(env, 1)); /* nil */
    v101 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 3); /* rl_simpl */
    v125 = (*qfnn(fn))(qenv(fn), 3, v124, v125, v101);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-1];
    v101 = stack[0];
    fn = elt(env, 4); /* cl_mkstrict */
    v101 = (*qfn2(fn))(qenv(fn), v125, v101);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-1];
    v125 = v101;
    v101 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* rl_bnfsimpl */
        return (*qfn2(fn))(qenv(fn), v125, v101);
    }
/* error exit handlers */
v127:
    popv(2);
    return nil;
}



/* Code for ratpoly_sgn */

static Lisp_Object CC_ratpoly_sgn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_sgn");
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
    v32 = qvalue(elt(env, 1)); /* !*rlanuexdebug */
    if (v32 == nil) goto v109;
    v32 = stack[0];
    fn = elt(env, 3); /* ratpoly_ratp */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-1];
    if (!(v32 == nil)) goto v109;
    v32 = elt(env, 2); /* "***** ratpoly_sgn: not a constant polynomial" 
*/
    stack[0] = v32;
    v32 = stack[0];
    v32 = Lprinc(nil, v32);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-1];
    v32 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v165;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v109:
    v32 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* rat_sgn */
        return (*qfn1(fn))(qenv(fn), v32);
    }
/* error exit handlers */
v165:
    popv(2);
    return nil;
}



/* Code for determinantrd */

static Lisp_Object MS_CDECL CC_determinantrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "determinantrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for determinantrd");
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
    fn = elt(env, 1); /* mathml */
    v73 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    fn = elt(env, 2); /* alg_det */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    stack[0] = v73;
    fn = elt(env, 3); /* lex */
    v73 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v75:
    popv(2);
    return nil;
}



/* Code for partitwedge */

static Lisp_Object CC_partitwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitwedge");
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
    v109 = v0;
/* end of prologue */
    v102 = v109;
    v102 = qcdr(v102);
    if (v102 == nil) goto v48;
    v102 = v109;
    fn = elt(env, 1); /* xpndwedge */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mkuniquewedge */
        return (*qfn1(fn))(qenv(fn), v102);
    }

v48:
    v102 = v109;
    v102 = qcar(v102);
    {
        popv(1);
        fn = elt(env, 3); /* partitop */
        return (*qfn1(fn))(qenv(fn), v102);
    }
/* error exit handlers */
v108:
    popv(1);
    return nil;
}



/* Code for fortassign */

static Lisp_Object CC_fortassign(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortassign");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v49 = v0;
/* end of prologue */
    v102 = v49;
    v102 = qcdr(v102);
    v102 = qcar(v102);
    v49 = qcdr(v49);
    v49 = qcdr(v49);
    v49 = qcar(v49);
    {
        fn = elt(env, 1); /* mkffortassign */
        return (*qfn2(fn))(qenv(fn), v102, v49);
    }
}



/* Code for cvitimes2 */

static Lisp_Object CC_cvitimes2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v68, v58, v69;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cvitimes2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v58 = v1;
    v69 = v0;
/* end of prologue */
    v68 = v69;
    v57 = (Lisp_Object)1; /* 0 */
    if (v68 == v57) goto v130;
    v68 = v58;
    v57 = (Lisp_Object)1; /* 0 */
    v57 = (v68 == v57 ? lisp_true : nil);
    goto v129;

v129:
    if (v57 == nil) goto v36;
    v57 = (Lisp_Object)1; /* 0 */
    return onevalue(v57);

v36:
    v68 = v69;
    v57 = (Lisp_Object)17; /* 1 */
    if (v68 == v57) return onevalue(v58);
    v68 = v58;
    v57 = (Lisp_Object)17; /* 1 */
    if (v68 == v57) return onevalue(v69);
    v57 = elt(env, 2); /* times */
    v68 = v69;
    return list3(v57, v68, v58);

v130:
    v57 = qvalue(elt(env, 1)); /* t */
    goto v129;
}



/* Code for fs!:prin */

static Lisp_Object CC_fsTprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prin");
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
    v30 = stack[0];
    if (!(v30 == nil)) goto v46;
    v30 = elt(env, 1); /* " 0 " */
    {
        popv(2);
        fn = elt(env, 4); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v30);
    }

v46:
    v30 = stack[0];
    if (v30 == nil) goto v102;
    v30 = stack[0];
    fn = elt(env, 5); /* fs!:prin1 */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    v29 = stack[0];
    v30 = (Lisp_Object)49; /* 3 */
    v30 = *(Lisp_Object *)((char *)v29 + (CELL-TAG_VECTOR) + ((int32_t)v30/(16/CELL)));
    stack[0] = v30;
    v30 = stack[0];
    if (v30 == nil) goto v46;
    v30 = elt(env, 3); /* " + " */
    fn = elt(env, 4); /* prin2!* */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    goto v46;

v102:
    v30 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v30); }
/* error exit handlers */
v125:
    popv(2);
    return nil;
}



/* Code for flattens1 */

static Lisp_Object CC_flattens1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flattens1");
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

v48:
    v36 = stack[0];
    if (!consp(v36)) goto v53;
    v36 = stack[0];
    v36 = qcdr(v36);
    if (v36 == nil) goto v37;
    v36 = stack[0];
    v36 = qcar(v36);
    stack[-1] = CC_flattens1(env, v36);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    v36 = stack[0];
    v36 = qcdr(v36);
    v36 = CC_flattens1(env, v36);
    nil = C_nil;
    if (exception_pending()) goto v72;
    {
        Lisp_Object v59 = stack[-1];
        popv(3);
        return Lappend(nil, v59, v36);
    }

v37:
    v36 = stack[0];
    v36 = qcar(v36);
    stack[0] = v36;
    goto v48;

v53:
    v36 = stack[0];
    popv(3);
    return ncons(v36);
/* error exit handlers */
v72:
    popv(3);
    return nil;
}



/* Code for general!-multiply!-by!-constant!-mod!-p */

static Lisp_Object CC_generalKmultiplyKbyKconstantKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-multiply-by-constant-mod-p");
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
    v41 = stack[-2];
    if (v41 == nil) goto v51;
    v168 = stack[-1];
    v41 = (Lisp_Object)17; /* 1 */
    if (v168 == v41) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v41 = stack[-2];
    if (!consp(v41)) goto v165;
    v41 = stack[-2];
    v41 = qcar(v41);
    v41 = (consp(v41) ? nil : lisp_true);
    goto v31;

v31:
    if (v41 == nil) goto v169;
    v168 = stack[-2];
    v41 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-times */
    v41 = (*qfn2(fn))(qenv(fn), v168, v41);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v168 = v41;
    v41 = v168;
    v41 = (Lisp_Object)zerop(v41);
    v41 = v41 ? lisp_true : nil;
    env = stack[-4];
    if (v41 == nil) { popv(5); return onevalue(v168); }
    v41 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v41); }

v169:
    v41 = stack[-2];
    v41 = qcar(v41);
    stack[-3] = qcar(v41);
    v41 = stack[-2];
    v41 = qcar(v41);
    v168 = qcdr(v41);
    v41 = stack[-1];
    stack[0] = CC_generalKmultiplyKbyKconstantKmodKp(env, v168, v41);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v41 = stack[-2];
    v168 = qcdr(v41);
    v41 = stack[-1];
    v41 = CC_generalKmultiplyKbyKconstantKmodKp(env, v168, v41);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    {
        Lisp_Object v66 = stack[-3];
        Lisp_Object v171 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v66, v171, v41);
    }

v165:
    v41 = qvalue(elt(env, 2)); /* t */
    goto v31;

v51:
    v41 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v41); }
/* error exit handlers */
v170:
    popv(5);
    return nil;
}



/* Code for cl_atl1 */

static Lisp_Object CC_cl_atl1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atl1");
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
    v172 = v0;
/* end of prologue */
    fn = elt(env, 2); /* cl_atml1 */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[-3] = v172;
    v172 = stack[-3];
    if (v172 == nil) goto v75;
    v172 = stack[-3];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v172 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[-1] = v172;
    stack[-2] = v172;
    goto v53;

v53:
    v172 = stack[-3];
    v172 = qcdr(v172);
    stack[-3] = v172;
    v172 = stack[-3];
    if (v172 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v172 = stack[-3];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v172 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v172 = Lrplacd(nil, stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v172 = stack[-1];
    v172 = qcdr(v172);
    stack[-1] = v172;
    goto v53;

v75:
    v172 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v172); }
/* error exit handlers */
v52:
    popv(5);
    return nil;
}



/* Code for nlist */

static Lisp_Object CC_nlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nlist");
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
    goto v76;

v76:
    v173 = stack[0];
    v36 = (Lisp_Object)1; /* 0 */
    if (v173 == v36) goto v130;
    v173 = stack[-1];
    v36 = stack[-2];
    v36 = cons(v173, v36);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[-2] = v36;
    v36 = stack[0];
    v36 = sub1(v36);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[0] = v36;
    goto v76;

v130:
    v36 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for depend!-sq */

static Lisp_Object CC_dependKsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-sq");
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
    v174 = stack[-1];
    v103 = qcar(v174);
    v174 = stack[0];
    fn = elt(env, 1); /* depend!-f */
    v174 = (*qfn2(fn))(qenv(fn), v103, v174);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    if (!(v174 == nil)) { popv(3); return onevalue(v174); }
    v174 = stack[-1];
    v103 = qcdr(v174);
    v174 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* depend!-f */
        return (*qfn2(fn))(qenv(fn), v103, v174);
    }
/* error exit handlers */
v37:
    popv(3);
    return nil;
}



/* Code for pasf_ceil */

static Lisp_Object CC_pasf_ceil(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_ceil");
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
    v96 = stack[-1];
    if (!consp(v96)) goto v46;
    v96 = stack[-1];
    v96 = qcar(v96);
    v96 = (consp(v96) ? nil : lisp_true);
    goto v75;

v75:
    if (v96 == nil) goto v173;
    v96 = stack[0];
    if (!consp(v96)) goto v174;
    v96 = stack[0];
    v96 = qcar(v96);
    v96 = (consp(v96) ? nil : lisp_true);
    goto v129;

v129:
    if (v96 == nil) goto v18;
    v96 = stack[-1];
    if (v96 == nil) goto v29;
    v97 = stack[-1];
    v96 = stack[0];
    v97 = Cremainder(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    v96 = (Lisp_Object)1; /* 0 */
    if (v97 == v96) goto v68;
    v97 = stack[-1];
    v96 = stack[0];
    v97 = times2(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    v96 = (Lisp_Object)1; /* 0 */
    v96 = (Lisp_Object)greaterp2(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v179;
    v96 = v96 ? lisp_true : nil;
    env = stack[-2];
    if (v96 == nil) goto v180;
    v97 = stack[-1];
    v96 = stack[0];
    v96 = quot2(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    v96 = add1(v96);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    goto v181;

v181:
    fn = elt(env, 5); /* simp */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v179;
    v96 = qcar(v96);
    { popv(3); return onevalue(v96); }

v180:
    v97 = stack[-1];
    v96 = stack[0];
    v96 = quot2(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    goto v181;

v68:
    v97 = stack[-1];
    v96 = stack[0];
    v96 = quot2(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    goto v181;

v29:
    v96 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v96); }

v18:
    v96 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v96 == nil)) goto v182;
    v10 = elt(env, 4); /* "pasf_ceil: not a domain valued sf in input" 
*/
    v97 = stack[-1];
    v96 = stack[0];
    v96 = list3(v10, v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    fn = elt(env, 6); /* lprie */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    goto v182;

v182:
    v96 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v179;
    v96 = nil;
    { popv(3); return onevalue(v96); }

v174:
    v96 = qvalue(elt(env, 1)); /* t */
    goto v129;

v173:
    v96 = qvalue(elt(env, 2)); /* nil */
    goto v129;

v46:
    v96 = qvalue(elt(env, 1)); /* t */
    goto v75;
/* error exit handlers */
v179:
    popv(3);
    return nil;
}



/* Code for omattrir */

static Lisp_Object MS_CDECL CC_omattrir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v184, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omattrir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omattrir");
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
    fn = elt(env, 6); /* lex */
    v26 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    fn = elt(env, 7); /* omatpir */
    v26 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    stack[-1] = v26;
    fn = elt(env, 6); /* lex */
    v26 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    fn = elt(env, 8); /* omobj */
    v26 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    stack[0] = v26;
    fn = elt(env, 6); /* lex */
    v26 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    v26 = elt(env, 1); /* (!/ o m a t t r) */
    fn = elt(env, 9); /* checktag */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    v26 = stack[-1];
    v26 = Lconsp(nil, v26);
    env = stack[-2];
    if (v26 == nil) goto v46;
    v26 = stack[-1];
    v26 = qcar(v26);
    v26 = qcdr(v26);
    v184 = qcar(v26);
    v26 = elt(env, 2); /* csymbol */
    if (!(v184 == v26)) goto v46;
    v184 = stack[0];
    v26 = qvalue(elt(env, 3)); /* nil */
    v77 = qvalue(elt(env, 3)); /* nil */
    popv(3);
    return list2star(v184, v26, v77);

v46:
    v26 = stack[0];
    if (is_number(v26)) goto v28;
    v77 = elt(env, 5); /* ci */
    v184 = stack[-1];
    v26 = stack[0];
    popv(3);
    return list3(v77, v184, v26);

v28:
    v77 = elt(env, 4); /* cn */
    v184 = stack[-1];
    v26 = stack[0];
    popv(3);
    return list3(v77, v184, v26);
/* error exit handlers */
v56:
    popv(3);
    return nil;
}



/* Code for latexprint */

static Lisp_Object CC_latexprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for latexprint");
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
    fn = elt(env, 1); /* prinlabegin */
    v67 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    v67 = stack[0];
    fn = elt(env, 2); /* latexprin */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* prinlaend */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v129:
    popv(2);
    return nil;
}



/* Code for force!-to!-dm */

static Lisp_Object CC_forceKtoKdm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v188, v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for force-to-dm");
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
    v188 = v0;
/* end of prologue */

v48:
    v187 = v188;
    if (!consp(v187)) goto v76;
    v187 = v188;
    v187 = qcar(v187);
    v187 = (consp(v187) ? nil : lisp_true);
    goto v73;

v73:
    if (v187 == nil) goto v32;
    v187 = v188;
    if (v187 == nil) goto v62;
    v187 = v188;
    if (is_number(v187)) goto v127;
    v187 = v188;
    v187 = Lconsp(nil, v187);
    env = stack[-1];
    if (v187 == nil) goto v54;
    v187 = v188;
    v189 = qcar(v187);
    v187 = qvalue(elt(env, 3)); /* dmode!* */
    if (equal(v189, v187)) { popv(2); return onevalue(v188); }
    else goto v54;

v54:
    v187 = v188;
    v187 = Lconsp(nil, v187);
    env = stack[-1];
    if (v187 == nil) goto v184;
    v187 = v188;
    v189 = qcar(v187);
    v187 = qvalue(elt(env, 3)); /* dmode!* */
    v187 = get(v189, v187);
    env = stack[-1];
    goto v26;

v26:
    v189 = v187;
    v187 = v189;
    if (v187 == nil) goto v40;
    stack[0] = v189;
    v187 = v188;
    v187 = ncons(v187);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    {
        Lisp_Object v149 = stack[0];
        popv(2);
        fn = elt(env, 8); /* apply */
        return (*qfn2(fn))(qenv(fn), v149, v187);
    }

v40:
    v187 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v187 == nil)) goto v17;
    v187 = elt(env, 7); /* "conversion error with " */
    v187 = list2(v187, v188);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    fn = elt(env, 9); /* lprie */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    goto v17;

v17:
    v187 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    v187 = nil;
    { popv(2); return onevalue(v187); }

v184:
    v187 = qvalue(elt(env, 5)); /* nil */
    goto v26;

v127:
    v189 = qvalue(elt(env, 3)); /* dmode!* */
    v187 = elt(env, 4); /* i2d */
    stack[0] = get(v189, v187);
    env = stack[-1];
    v187 = v188;
    v187 = ncons(v187);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    {
        Lisp_Object v43 = stack[0];
        popv(2);
        fn = elt(env, 8); /* apply */
        return (*qfn2(fn))(qenv(fn), v43, v187);
    }

v62:
    v187 = (Lisp_Object)1; /* 0 */
    v188 = v187;
    goto v48;

v32:
    v187 = v188;
    fn = elt(env, 10); /* prepf */
    v188 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    v187 = elt(env, 2); /* "number" */
    {
        popv(2);
        fn = elt(env, 11); /* typerr */
        return (*qfn2(fn))(qenv(fn), v188, v187);
    }

v76:
    v187 = qvalue(elt(env, 1)); /* t */
    goto v73;
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



/* Code for formatfort */

static Lisp_Object CC_formatfort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v137, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formatfort");
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
    stack[-2] = qvalue(elt(env, 1)); /* !*lower */
    qvalue(elt(env, 1)) = nil; /* !*lower */
    v200 = (Lisp_Object)4801; /* 300 */
    v200 = Llinelength(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    stack[-4] = v200;
    v200 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = v200; /* !*posn!* */
    v200 = stack[0];
    stack[-1] = v200;
    goto v46;

v46:
    v200 = stack[-1];
    if (v200 == nil) goto v75;
    v200 = stack[-1];
    v200 = qcar(v200);
    stack[0] = v200;
    v200 = stack[0];
    v200 = Lconsp(nil, v200);
    env = stack[-5];
    if (v200 == nil) goto v36;
    v200 = stack[0];
    fn = elt(env, 12); /* eval */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    goto v103;

v103:
    v200 = stack[-1];
    v200 = qcdr(v200);
    stack[-1] = v200;
    goto v46;

v36:
    v200 = stack[0];
    v200 = integerp(v200);
    if (v200 == nil) goto v72;
    v137 = stack[0];
    v200 = qvalue(elt(env, 4)); /* maxint */
    v200 = (Lisp_Object)greaterp2(v137, v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    v200 = v200 ? lisp_true : nil;
    env = stack[-5];
    if (!(v200 == nil)) goto v59;
    stack[-3] = stack[0];
    v200 = qvalue(elt(env, 4)); /* maxint */
    v200 = negate(v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    v200 = (Lisp_Object)lessp2(stack[-3], v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    v200 = v200 ? lisp_true : nil;
    env = stack[-5];
    if (!(v200 == nil)) goto v59;

v72:
    v200 = stack[0];
    v200 = Lexplodec(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    stack[-3] = v200;
    v200 = stack[0];
    v200 = Lfloatp(nil, v200);
    env = stack[-5];
    if (v200 == nil) goto v201;
    v200 = qvalue(elt(env, 6)); /* !*double */
    if (v200 == nil) goto v95;
    v137 = elt(env, 7); /* e */
    v200 = stack[-3];
    v200 = Lmemq(nil, v137, v200);
    if (v200 == nil) goto v185;
    v136 = elt(env, 8); /* !D */
    v137 = elt(env, 7); /* e */
    v200 = stack[-3];
    v200 = Lsubst(nil, 3, v136, v137, v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    stack[-3] = v200;
    goto v201;

v201:
    stack[0] = qvalue(elt(env, 2)); /* !*posn!* */
    v200 = stack[-3];
    v200 = Llength(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    v137 = plus2(stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    v200 = qvalue(elt(env, 11)); /* fortlinelen!* */
    v200 = (Lisp_Object)greaterp2(v137, v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    v200 = v200 ? lisp_true : nil;
    env = stack[-5];
    if (v200 == nil) goto v202;
    fn = elt(env, 13); /* fortcontline */
    v200 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    goto v202;

v202:
    v200 = stack[-3];
    stack[0] = v200;
    goto v142;

v142:
    v200 = stack[0];
    if (v200 == nil) goto v103;
    v200 = stack[0];
    v200 = qcar(v200);
    fn = elt(env, 14); /* pprin2 */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    v200 = stack[0];
    v200 = qcdr(v200);
    stack[0] = v200;
    goto v142;

v185:
    v137 = elt(env, 9); /* !E */
    v200 = stack[-3];
    v200 = Lmemq(nil, v137, v200);
    if (v200 == nil) goto v146;
    v136 = elt(env, 8); /* !D */
    v137 = elt(env, 9); /* !E */
    v200 = stack[-3];
    v200 = Lsubst(nil, 3, v136, v137, v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    stack[-3] = v200;
    goto v201;

v146:
    v137 = stack[-3];
    v200 = elt(env, 10); /* (d !0) */
    v200 = Lappend(nil, v137, v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    stack[-3] = v200;
    goto v201;

v95:
    v137 = elt(env, 7); /* e */
    v200 = stack[-3];
    v200 = Lmemq(nil, v137, v200);
    if (v200 == nil) goto v201;
    v136 = elt(env, 9); /* !E */
    v137 = elt(env, 7); /* e */
    v200 = stack[-3];
    v200 = Lsubst(nil, 3, v136, v137, v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    stack[-3] = v200;
    goto v201;

v59:
    v200 = stack[0];
    fn = elt(env, 15); /* chkint!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    v137 = v200;
    if (!(!consp(v137))) goto v58;
    v137 = elt(env, 5); /* !:rd!: */
    v200 = cons(v137, v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    goto v58;

v58:
    v200 = qcdr(v200);
    stack[0] = v200;
    goto v72;

v75:
    v200 = stack[-4];
    v200 = Llinelength(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    v200 = nil;
    qvalue(elt(env, 1)) = stack[-2]; /* !*lower */
    { popv(6); return onevalue(v200); }
/* error exit handlers */
v163:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-2]; /* !*lower */
    popv(6);
    return nil;
}



/* Code for find_bubles1 */

static Lisp_Object CC_find_bubles1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v61, v60, v36, v173, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v62 = v1;
    v61 = v0;
/* end of prologue */
    v71 = qvalue(elt(env, 1)); /* nil */
    v60 = v61;
    v173 = qcar(v60);
    v36 = qvalue(elt(env, 1)); /* nil */
    v60 = v61;
    v60 = qcdr(v60);
    v60 = qcar(v60);
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v61 = qcar(v61);
    {
        fn = elt(env, 2); /* select_bubles */
        return (*qfnn(fn))(qenv(fn), 6, v71, v173, v36, v60, v61, v62);
    }
}



/* Code for ratfunpri1 */

static Lisp_Object CC_ratfunpri1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v251, v252, v253;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratfunpri1");
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
    stack[0] = v0;
/* end of prologue */
    v252 = qvalue(elt(env, 1)); /* spare!* */
    v251 = (Lisp_Object)33; /* 2 */
    v251 = plus2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    qvalue(elt(env, 1)) = v251; /* spare!* */
    v251 = stack[0];
    v251 = qcdr(v251);
    v253 = qcar(v251);
    v252 = (Lisp_Object)1; /* 0 */
    v251 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 17); /* layout!-formula */
    v251 = (*qfnn(fn))(qenv(fn), 3, v253, v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[-7] = v251;
    if (v251 == nil) goto v255;
    v251 = stack[0];
    v251 = qcdr(v251);
    v251 = qcdr(v251);
    v253 = qcar(v251);
    v252 = (Lisp_Object)1; /* 0 */
    v251 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 17); /* layout!-formula */
    v251 = (*qfnn(fn))(qenv(fn), 3, v253, v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[-6] = v251;
    if (v251 == nil) goto v255;
    v252 = qvalue(elt(env, 1)); /* spare!* */
    v251 = (Lisp_Object)33; /* 2 */
    v251 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    qvalue(elt(env, 1)) = v251; /* spare!* */
    stack[0] = (Lisp_Object)33; /* 2 */
    v251 = stack[-7];
    v251 = qcar(v251);
    v252 = qcdr(v251);
    v251 = stack[-6];
    v251 = qcar(v251);
    v251 = qcdr(v251);
    fn = elt(env, 18); /* max */
    v251 = (*qfn2(fn))(qenv(fn), v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = plus2(stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[-2] = v251;
    stack[0] = stack[-2];
    v251 = qvalue(elt(env, 2)); /* nil */
    v252 = Llinelength(nil, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = qvalue(elt(env, 1)); /* spare!* */
    v252 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = qvalue(elt(env, 3)); /* posn!* */
    v251 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = (Lisp_Object)greaterp2(stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    v251 = v251 ? lisp_true : nil;
    env = stack[-8];
    if (v251 == nil) goto v185;
    v251 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    goto v185;

v185:
    v251 = stack[-7];
    v251 = qcar(v251);
    v252 = qcdr(v251);
    v251 = stack[-6];
    v251 = qcar(v251);
    v251 = qcdr(v251);
    v251 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[-1] = v251;
    v252 = stack[-1];
    v251 = (Lisp_Object)1; /* 0 */
    v251 = (Lisp_Object)greaterp2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    v251 = v251 ? lisp_true : nil;
    env = stack[-8];
    if (v251 == nil) goto v256;
    v251 = (Lisp_Object)1; /* 0 */
    stack[0] = v251;
    v252 = stack[-1];
    v251 = (Lisp_Object)33; /* 2 */
    v251 = quot2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[-3] = v251;
    goto v257;

v257:
    v251 = stack[-7];
    v251 = qcdr(v251);
    v252 = qcdr(v251);
    v251 = stack[-7];
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v251 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = add1(v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[-5] = v251;
    v251 = stack[-6];
    v251 = qcdr(v251);
    v252 = qcdr(v251);
    v251 = stack[-6];
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v251 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = add1(v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[-4] = v251;
    stack[-1] = stack[0];
    stack[0] = qvalue(elt(env, 3)); /* posn!* */
    v252 = (Lisp_Object)17; /* 1 */
    v251 = qvalue(elt(env, 5)); /* orig!* */
    v251 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = plus2(stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[0] = plus2(stack[-1], v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v252 = (Lisp_Object)17; /* 1 */
    v251 = stack[-7];
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v252 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = qvalue(elt(env, 6)); /* ycoord!* */
    v252 = plus2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = stack[-7];
    v251 = qcar(v251);
    v251 = qcar(v251);
    fn = elt(env, 20); /* update!-pline */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[0], v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[0] = qvalue(elt(env, 3)); /* posn!* */
    v252 = (Lisp_Object)17; /* 1 */
    v251 = qvalue(elt(env, 5)); /* orig!* */
    v251 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = plus2(stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[0] = plus2(stack[-3], v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v252 = qvalue(elt(env, 6)); /* ycoord!* */
    v251 = stack[-6];
    v251 = qcdr(v251);
    v251 = qcdr(v251);
    v251 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v252 = sub1(v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = stack[-6];
    v251 = qcar(v251);
    v251 = qcar(v251);
    fn = elt(env, 20); /* update!-pline */
    v252 = (*qfnn(fn))(qenv(fn), 3, stack[0], v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = qvalue(elt(env, 7)); /* pline!* */
    v251 = Lappend(nil, v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = Lappend(nil, stack[-1], v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    qvalue(elt(env, 7)) = v251; /* pline!* */
    stack[0] = qvalue(elt(env, 8)); /* ymin!* */
    v252 = qvalue(elt(env, 6)); /* ycoord!* */
    v251 = stack[-4];
    v251 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    fn = elt(env, 21); /* min */
    v251 = (*qfn2(fn))(qenv(fn), stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    qvalue(elt(env, 8)) = v251; /* ymin!* */
    stack[0] = qvalue(elt(env, 9)); /* ymax!* */
    v252 = qvalue(elt(env, 6)); /* ycoord!* */
    v251 = stack[-5];
    v251 = plus2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    fn = elt(env, 18); /* max */
    v251 = (*qfn2(fn))(qenv(fn), stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    qvalue(elt(env, 9)) = v251; /* ymax!* */
    v251 = elt(env, 10); /* bar */
    fn = elt(env, 22); /* symbol */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[-1] = v251;
    v251 = (Lisp_Object)17; /* 1 */
    stack[0] = v251;
    goto v258;

v258:
    v252 = stack[-2];
    v251 = stack[0];
    v251 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = Lminusp(nil, v251);
    env = stack[-8];
    if (!(v251 == nil)) goto v61;
    v251 = stack[-1];
    fn = elt(env, 23); /* prin2!* */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = stack[0];
    v251 = add1(v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[0] = v251;
    goto v258;

v61:
    v251 = nil;
    { popv(9); return onevalue(v251); }

v256:
    v251 = stack[-1];
    v252 = negate(v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = (Lisp_Object)33; /* 2 */
    v251 = quot2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    stack[0] = v251;
    v251 = (Lisp_Object)1; /* 0 */
    stack[-3] = v251;
    goto v257;

v255:
    v252 = qvalue(elt(env, 1)); /* spare!* */
    v251 = (Lisp_Object)33; /* 2 */
    v251 = difference2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    qvalue(elt(env, 1)) = v251; /* spare!* */
    v251 = stack[0];
    v251 = qcdr(v251);
    stack[0] = v251;
    v252 = elt(env, 11); /* quotient */
    v251 = elt(env, 12); /* infix */
    v251 = get(v252, v251);
    env = stack[-8];
    stack[-2] = v251;
    v251 = qvalue(elt(env, 13)); /* p!*!* */
    if (v251 == nil) goto v259;
    v252 = qvalue(elt(env, 13)); /* p!*!* */
    v251 = stack[-2];
    v251 = (Lisp_Object)greaterp2(v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    v251 = v251 ? lisp_true : nil;
    env = stack[-8];
    stack[-1] = v251;
    goto v260;

v260:
    v251 = stack[-1];
    if (v251 == nil) goto v261;
    v251 = elt(env, 14); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    goto v261;

v261:
    v251 = stack[0];
    v252 = qcar(v251);
    v251 = stack[-2];
    fn = elt(env, 24); /* maprint */
    v251 = (*qfn2(fn))(qenv(fn), v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = elt(env, 11); /* quotient */
    fn = elt(env, 25); /* oprin */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = stack[0];
    v251 = qcdr(v251);
    v252 = qcar(v251);
    v251 = elt(env, 15); /* minus */
    if (!consp(v252)) goto v262;
    v252 = qcar(v252);
    if (!(v252 == v251)) goto v262;
    v251 = stack[0];
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v251 = (is_number(v251) ? lisp_true : nil);
    goto v263;

v263:
    if (v251 == nil) goto v264;
    v251 = stack[0];
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v251 = negate(v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v252 = v251;
    goto v265;

v265:
    v251 = stack[-2];
    fn = elt(env, 24); /* maprint */
    v251 = (*qfn2(fn))(qenv(fn), v252, v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-8];
    v251 = stack[-1];
    if (v251 == nil) goto v61;
    v251 = elt(env, 16); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v254;
    goto v61;

v264:
    v251 = stack[0];
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v252 = v251;
    goto v265;

v262:
    v251 = qvalue(elt(env, 2)); /* nil */
    goto v263;

v259:
    v251 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v251;
    goto v260;
/* error exit handlers */
v254:
    popv(9);
    return nil;
}



/* Code for dp_from_ei */

static Lisp_Object CC_dp_from_ei(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_from_ei");
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
    v46 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* bc_fi */
    stack[-1] = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-2];
    v46 = stack[0];
    fn = elt(env, 2); /* mo_from_ei */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-2];
    fn = elt(env, 3); /* dp_term */
    v46 = (*qfn2(fn))(qenv(fn), stack[-1], v46);
    nil = C_nil;
    if (exception_pending()) goto v102;
    popv(3);
    return ncons(v46);
/* error exit handlers */
v102:
    popv(3);
    return nil;
}



/* Code for nonmult */

static Lisp_Object CC_nonmult(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonmult");
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
    v31 = qvalue(elt(env, 1)); /* vjets */
    v165 = Lreverse(nil, v31);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v31 = stack[0];
    fn = elt(env, 2); /* pnth */
    v31 = (*qfn2(fn))(qenv(fn), v165, v31);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    stack[0] = qcar(v31);
    v31 = qvalue(elt(env, 1)); /* vjets */
    v31 = Lreverse(nil, v31);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v31 = Lmember(nil, stack[0], v31);
    v31 = qcdr(v31);
        popv(2);
        return Lreverse(nil, v31);
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for janettreenodebuild */

static Lisp_Object MS_CDECL CC_janettreenodebuild(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v50, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "janettreenodebuild");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for janettreenodebuild");
#endif
    if (stack >= stacklimit)
    {
        push3(v50,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v50;
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    v185 = stack[-5];
    v118 = (Lisp_Object)17; /* 1 */
    v118 = *(Lisp_Object *)((char *)v185 + (CELL-TAG_VECTOR) + ((int32_t)v118/(16/CELL)));
    v118 = qcar(v118);
    stack[-3] = v118;
    v185 = stack[-3];
    v118 = stack[-6];
    fn = elt(env, 2); /* monomgetvariabledegree */
    stack[-1] = (*qfn2(fn))(qenv(fn), v185, v118);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v118 = qvalue(elt(env, 1)); /* nil */
    v118 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    v118 = acons(stack[-1], stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    stack[-8] = v118;
    v118 = stack[-8];
    stack[-4] = v118;
    goto v172;

v172:
    stack[0] = stack[-7];
    v185 = stack[-3];
    v118 = stack[-6];
    fn = elt(env, 2); /* monomgetvariabledegree */
    v118 = (*qfn2(fn))(qenv(fn), v185, v118);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    if (((int32_t)(stack[0])) > ((int32_t)(v118))) goto v166;
    v118 = stack[-4];
    v185 = qcar(v118);
    v118 = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v118 = (*qfn2(fn))(qenv(fn), v185, v118);
    nil = C_nil;
    if (exception_pending()) goto v250;
    { Lisp_Object res = stack[-8]; popv(10); return onevalue(res); }

v166:
    stack[0] = stack[-7];
    v185 = stack[-3];
    v118 = stack[-6];
    fn = elt(env, 2); /* monomgetvariabledegree */
    v118 = (*qfn2(fn))(qenv(fn), v185, v118);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    v118 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v118 + TAG_FIXNUM);
    stack[-7] = v118;
    v118 = stack[-6];
    v118 = (Lisp_Object)((int32_t)(v118) + 0x10);
    stack[-6] = v118;
    v118 = stack[-4];
    stack[-2] = qcdr(v118);
    v185 = stack[-3];
    v118 = stack[-6];
    fn = elt(env, 2); /* monomgetvariabledegree */
    stack[-1] = (*qfn2(fn))(qenv(fn), v185, v118);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v118 = qvalue(elt(env, 1)); /* nil */
    v118 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    v118 = acons(stack[-1], stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    fn = elt(env, 3); /* setcdr */
    v118 = (*qfn2(fn))(qenv(fn), stack[-2], v118);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-9];
    v118 = stack[-4];
    v118 = qcdr(v118);
    v118 = qcdr(v118);
    stack[-4] = v118;
    goto v172;
/* error exit handlers */
v250:
    popv(10);
    return nil;
}



/* Code for component_action */

static Lisp_Object MS_CDECL CC_component_action(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v50, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v56, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "component_action");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for component_action");
#endif
    if (stack >= stacklimit)
    {
        push3(v50,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v50;
    stack[-3] = v1;
    stack[0] = v0;
/* end of prologue */
    v56 = qvalue(elt(env, 1)); /* nil */
    v153 = (Lisp_Object)17; /* 1 */
    v153 = cons(v56, v153);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    stack[-4] = v153;
    v153 = stack[0];
    v153 = qcdr(v153);
    stack[-1] = v153;
    goto v108;

v108:
    v153 = stack[-1];
    if (v153 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v153 = stack[-1];
    v153 = qcar(v153);
    stack[0] = v153;
    v153 = stack[0];
    v56 = qcar(v153);
    v153 = stack[-3];
    fn = elt(env, 2); /* ext_mult */
    v56 = (*qfn2(fn))(qenv(fn), v56, v153);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    v153 = stack[0];
    v153 = qcdr(v153);
    v131 = v56;
    v56 = v153;
    v153 = v131;
    v153 = qcar(v153);
    if (v153 == nil) goto v128;
    stack[0] = stack[-4];
    v153 = v131;
    fn = elt(env, 3); /* multsq */
    v56 = (*qfn2(fn))(qenv(fn), v153, v56);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    v153 = stack[-2];
    fn = elt(env, 3); /* multsq */
    v153 = (*qfn2(fn))(qenv(fn), v56, v153);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    fn = elt(env, 4); /* addsq */
    v153 = (*qfn2(fn))(qenv(fn), stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    stack[-4] = v153;
    goto v128;

v128:
    v153 = stack[-1];
    v153 = qcdr(v153);
    stack[-1] = v153;
    goto v108;
/* error exit handlers */
v19:
    popv(6);
    return nil;
}



/* Code for change!+int!+to!+sq */

static Lisp_Object CC_changeLintLtoLsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for change+int+to+sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v75 = v0;
/* end of prologue */
    v46 = v75;
    v75 = (Lisp_Object)17; /* 1 */
    return cons(v46, v75);
}



/* Code for mri_simplat1 */

static Lisp_Object CC_mri_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_simplat1");
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
    v148 = qvalue(elt(env, 1)); /* !*rlsimplfloor */
    if (v148 == nil) goto v129;
    v148 = stack[-2];
    fn = elt(env, 4); /* mri_op */
    stack[-3] = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    v148 = stack[-2];
    fn = elt(env, 5); /* mri_arg2l */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    fn = elt(env, 6); /* mri_simplfloor */
    stack[0] = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    v148 = stack[-2];
    fn = elt(env, 7); /* mri_type */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    fn = elt(env, 8); /* mri_0mk2 */
    v148 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    stack[-2] = v148;
    goto v129;

v129:
    v148 = stack[-2];
    fn = elt(env, 7); /* mri_type */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    if (!(v148 == nil)) goto v37;
    v148 = stack[-2];
    fn = elt(env, 9); /* mri_dettype */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    goto v37;

v37:
    stack[0] = v148;
    v161 = stack[0];
    v148 = elt(env, 2); /* int */
    if (v161 == v148) goto v154;
    v148 = stack[-2];
    fn = elt(env, 10); /* mri_congp */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    if (v148 == nil) goto v153;
    v148 = stack[-2];
    fn = elt(env, 4); /* mri_op */
    stack[-1] = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    v148 = stack[-2];
    fn = elt(env, 5); /* mri_arg2l */
    v161 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    v148 = stack[0];
    {
        Lisp_Object v198 = stack[-1];
        popv(5);
        fn = elt(env, 8); /* mri_0mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v198, v161, v148);
    }

v153:
    v148 = stack[-2];
    fn = elt(env, 11); /* mri_2ofsfat */
    v161 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    v148 = stack[-1];
    fn = elt(env, 12); /* ofsf_simplat1 */
    v161 = (*qfn2(fn))(qenv(fn), v161, v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    v148 = elt(env, 3); /* real */
    {
        popv(5);
        fn = elt(env, 13); /* mri_ofsf2mri */
        return (*qfn2(fn))(qenv(fn), v161, v148);
    }

v154:
    v148 = stack[-2];
    fn = elt(env, 14); /* mri_2pasfat */
    v161 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    v148 = stack[-1];
    fn = elt(env, 15); /* pasf_simplat1 */
    v161 = (*qfn2(fn))(qenv(fn), v161, v148);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    v148 = elt(env, 2); /* int */
    {
        popv(5);
        fn = elt(env, 16); /* mri_pasf2mri */
        return (*qfn2(fn))(qenv(fn), v161, v148);
    }
/* error exit handlers */
v40:
    popv(5);
    return nil;
}



/* Code for pasf_susibinad */

static Lisp_Object CC_pasf_susibinad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v229, v284, v285, v286, v287, v288;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_susibinad");
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
    v231 = stack[-4];
    v229 = qcdr(v231);
    v231 = stack[-3];
    v231 = qcdr(v231);
    fn = elt(env, 7); /* cl_susiminlevel */
    v231 = (*qfn2(fn))(qenv(fn), v229, v231);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    stack[-1] = v231;
    v231 = stack[-4];
    v231 = qcar(v231);
    stack[-4] = v231;
    v231 = stack[-3];
    v231 = qcar(v231);
    stack[-3] = v231;
    v229 = stack[-3];
    v231 = elt(env, 1); /* false */
    if (v229 == v231) goto v62;
    v229 = stack[-3];
    v231 = elt(env, 2); /* true */
    if (v229 == v231) goto v124;
    v231 = stack[-4];
    v231 = qcdr(v231);
    v229 = qcar(v231);
    v231 = stack[-3];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    if (equal(v229, v231)) goto v74;
    v231 = stack[-4];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    fn = elt(env, 8); /* pasf_dec */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    stack[-5] = v231;
    v231 = stack[-3];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    fn = elt(env, 8); /* pasf_dec */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    stack[-2] = v231;
    v231 = stack[-5];
    v229 = qcar(v231);
    v231 = stack[-2];
    v231 = qcar(v231);
    if (equal(v229, v231)) goto v17;
    v231 = stack[-5];
    v229 = qcar(v231);
    v231 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 9); /* kernels1 */
    v231 = (*qfn2(fn))(qenv(fn), v229, v231);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    stack[0] = v231;
    v231 = stack[-2];
    v229 = qcar(v231);
    v231 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 9); /* kernels1 */
    v231 = (*qfn2(fn))(qenv(fn), v229, v231);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    v284 = v231;
    v231 = stack[-4];
    v229 = qcar(v231);
    v231 = elt(env, 5); /* equal */
    if (v229 == v231) goto v115;
    v231 = qvalue(elt(env, 4)); /* nil */
    goto v92;

v92:
    if (v231 == nil) goto v158;
    stack[-2] = stack[-3];
    v231 = stack[0];
    stack[0] = qcar(v231);
    v231 = stack[-5];
    v231 = qcdr(v231);
    fn = elt(env, 10); /* negf */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    fn = elt(env, 11); /* pasf_subfof1 */
    v284 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    v229 = stack[-1];
    v231 = qvalue(elt(env, 6)); /* t */
    {
        popv(7);
        fn = elt(env, 12); /* pasf_susibinad1 */
        return (*qfnn(fn))(qenv(fn), 3, v284, v229, v231);
    }

v158:
    v231 = stack[-3];
    v229 = qcar(v231);
    v231 = elt(env, 5); /* equal */
    if (v229 == v231) goto v80;
    v231 = qvalue(elt(env, 4)); /* nil */
    goto v157;

v157:
    if (v231 == nil) goto v134;
    stack[-3] = stack[-4];
    v231 = v284;
    stack[0] = qcar(v231);
    v231 = stack[-2];
    v231 = qcdr(v231);
    fn = elt(env, 10); /* negf */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    fn = elt(env, 11); /* pasf_subfof1 */
    v284 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-6];
    v229 = stack[-1];
    v231 = qvalue(elt(env, 4)); /* nil */
    {
        popv(7);
        fn = elt(env, 12); /* pasf_susibinad1 */
        return (*qfnn(fn))(qenv(fn), 3, v284, v229, v231);
    }

v134:
    v231 = qvalue(elt(env, 4)); /* nil */
    { popv(7); return onevalue(v231); }

v80:
    v231 = v284;
    v231 = qcdr(v231);
    if (v231 == nil) goto v79;
    v231 = qvalue(elt(env, 4)); /* nil */
    goto v157;

v79:
    v231 = v284;
    v229 = qcar(v231);
    v231 = stack[0];
    v231 = Lmemq(nil, v229, v231);
    goto v157;

v115:
    v231 = stack[0];
    v231 = qcdr(v231);
    if (v231 == nil) goto v142;
    v231 = qvalue(elt(env, 4)); /* nil */
    goto v92;

v142:
    v231 = stack[0];
    v229 = qcar(v231);
    v231 = v284;
    v231 = Lmemq(nil, v229, v231);
    goto v92;

v17:
    v231 = stack[-4];
    v288 = qcar(v231);
    v231 = stack[-5];
    v287 = qcar(v231);
    v231 = stack[-5];
    v231 = qcdr(v231);
    if (v231 == nil) goto v290;
    v231 = stack[-5];
    v231 = qcdr(v231);
    v286 = v231;
    goto v182;

v182:
    v231 = stack[-3];
    v285 = qcar(v231);
    v231 = stack[-2];
    v284 = qcar(v231);
    v231 = stack[-2];
    v231 = qcdr(v231);
    if (v231 == nil) goto v7;
    v231 = stack[-2];
    v231 = qcdr(v231);
    v229 = v231;
    goto v185;

v185:
    v231 = stack[-1];
    {
        popv(7);
        fn = elt(env, 13); /* pasf_susibinord */
        return (*qfnn(fn))(qenv(fn), 7, v288, v287, v286, v285, v284, v229, v231);
    }

v7:
    v231 = (Lisp_Object)1; /* 0 */
    v229 = v231;
    goto v185;

v290:
    v231 = (Lisp_Object)1; /* 0 */
    v286 = v231;
    goto v182;

v74:
    v231 = stack[-4];
    v231 = qcdr(v231);
    v285 = qcar(v231);
    v231 = stack[-4];
    v284 = qcar(v231);
    v231 = stack[-3];
    v229 = qcar(v231);
    v231 = stack[-1];
    {
        popv(7);
        fn = elt(env, 14); /* pasf_susibineq */
        return (*qfnn(fn))(qenv(fn), 4, v285, v284, v229, v231);
    }

v124:
    v231 = elt(env, 3); /* (delete . t) */
    popv(7);
    return ncons(v231);

v62:
    v231 = elt(env, 1); /* false */
    { popv(7); return onevalue(v231); }
/* error exit handlers */
v289:
    popv(7);
    return nil;
}



/* Code for aex_neg */

static Lisp_Object CC_aex_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_neg");
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
    v32 = stack[-2];
    fn = elt(env, 1); /* aex_ex */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    fn = elt(env, 2); /* ratpoly_neg */
    stack[-3] = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    v32 = stack[-2];
    fn = elt(env, 3); /* aex_ctx */
    stack[-1] = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    v32 = stack[-2];
    fn = elt(env, 4); /* aex_lcnttag */
    stack[0] = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    v32 = stack[-2];
    fn = elt(env, 5); /* aex_reducedtag */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    {
        Lisp_Object v126 = stack[-3];
        Lisp_Object v37 = stack[-1];
        Lisp_Object v62 = stack[0];
        popv(5);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v126, v37, v62, v32);
    }
/* error exit handlers */
v104:
    popv(5);
    return nil;
}



/* Code for vdp_make */

static Lisp_Object MS_CDECL CC_vdp_make(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v50, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104, v126;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdp_make");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_make");
#endif
    if (stack >= stacklimit)
    {
        push3(v50,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v103 = v50;
    v104 = v1;
    v126 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = v104;
    stack[0] = v126;
    v104 = v103;
    v103 = qvalue(elt(env, 2)); /* nil */
    v103 = list2(v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v60;
    {
        Lisp_Object v36 = stack[-2];
        Lisp_Object v173 = stack[-1];
        Lisp_Object v71 = stack[0];
        popv(3);
        return list3star(v36, v173, v71, v103);
    }
/* error exit handlers */
v60:
    popv(3);
    return nil;
}



/* Code for vectorrd */

static Lisp_Object MS_CDECL CC_vectorrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vectorrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vectorrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 3); /* matrixrowrd */
    v102 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[0];
    v109 = elt(env, 2); /* mat */
    v102 = list2(v109, v102);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* aeval */
        return (*qfn1(fn))(qenv(fn), v102);
    }
/* error exit handlers */
v108:
    popv(1);
    return nil;
}



/* Code for sparpri */

static Lisp_Object MS_CDECL CC_sparpri(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v50, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sparpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sparpri");
#endif
    if (stack >= stacklimit)
    {
        push3(v50,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v50;
    v64 = v1;
    v65 = v0;
/* end of prologue */
    stack[-5] = v64;
    v64 = v65;
    stack[-3] = v64;
    goto v46;

v46:
    v64 = stack[-3];
    if (v64 == nil) goto v75;
    v64 = stack[-3];
    v64 = qcar(v64);
    stack[-2] = v64;
    stack[-1] = elt(env, 2); /* quote */
    stack[0] = elt(env, 3); /* setq */
    v20 = stack[-4];
    v65 = stack[-5];
    v64 = stack[-2];
    v64 = qcar(v64);
    v65 = list3(v20, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    v64 = stack[-2];
    v64 = qcdr(v64);
    v64 = list3(stack[0], v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    v64 = list2(stack[-1], v64);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    fn = elt(env, 7); /* eval */
    v20 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    v65 = qvalue(elt(env, 1)); /* nil */
    v64 = elt(env, 4); /* first */
    fn = elt(env, 8); /* assgnpri */
    v64 = (*qfnn(fn))(qenv(fn), 3, v20, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    v64 = elt(env, 5); /* (quote !$) */
    fn = elt(env, 7); /* eval */
    v20 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    v65 = qvalue(elt(env, 1)); /* nil */
    v64 = elt(env, 6); /* last */
    fn = elt(env, 8); /* assgnpri */
    v64 = (*qfnn(fn))(qenv(fn), 3, v20, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    v64 = stack[-3];
    v64 = qcdr(v64);
    stack[-3] = v64;
    goto v46;

v75:
    v64 = nil;
    { popv(7); return onevalue(v64); }
/* error exit handlers */
v151:
    popv(7);
    return nil;
}



/* Code for dipsum */

static Lisp_Object CC_dipsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v201, v293;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipsum");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v191 = stack[-6];
    if (v191 == nil) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }
    v191 = stack[-5];
    if (v191 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    stack[-7] = nil;
    stack[-2] = nil;
    stack[0] = nil;
    goto v126;

v126:
    v191 = stack[-7];
    if (!(v191 == nil)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    v191 = stack[-6];
    if (v191 == nil) goto v59;
    v191 = stack[-5];
    if (v191 == nil) goto v124;
    v191 = stack[-6];
    v191 = qcar(v191);
    stack[-4] = v191;
    v191 = stack[-5];
    v191 = qcar(v191);
    stack[-3] = v191;
    v201 = stack[-4];
    v191 = stack[-3];
    fn = elt(env, 3); /* evcomp */
    v191 = (*qfn2(fn))(qenv(fn), v201, v191);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-1] = v191;
    v201 = stack[-1];
    v191 = (Lisp_Object)17; /* 1 */
    v191 = Leqn(nil, v201, v191);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    if (v191 == nil) goto v171;
    v293 = stack[-4];
    v191 = stack[-6];
    v191 = qcdr(v191);
    v201 = qcar(v191);
    v191 = qvalue(elt(env, 1)); /* nil */
    v191 = list2star(v293, v201, v191);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-1] = v191;
    v191 = stack[-6];
    v191 = qcdr(v191);
    v191 = qcdr(v191);
    stack[-6] = v191;
    goto v72;

v72:
    v191 = stack[-1];
    if (v191 == nil) goto v126;
    v191 = stack[0];
    if (v191 == nil) goto v93;
    v191 = stack[-2];
    v201 = qcdr(v191);
    v191 = stack[-1];
    fn = elt(env, 4); /* setcdr */
    v191 = (*qfn2(fn))(qenv(fn), v201, v191);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v191 = stack[-1];
    stack[-2] = v191;
    goto v126;

v93:
    v191 = stack[-1];
    stack[-2] = v191;
    stack[0] = v191;
    goto v126;

v171:
    v201 = stack[-1];
    v191 = (Lisp_Object)-15; /* -1 */
    v191 = Leqn(nil, v201, v191);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    if (v191 == nil) goto v105;
    v293 = stack[-3];
    v191 = stack[-5];
    v191 = qcdr(v191);
    v201 = qcar(v191);
    v191 = qvalue(elt(env, 1)); /* nil */
    v191 = list2star(v293, v201, v191);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-1] = v191;
    v191 = stack[-5];
    v191 = qcdr(v191);
    v191 = qcdr(v191);
    stack[-5] = v191;
    goto v72;

v105:
    v191 = stack[-6];
    v191 = qcdr(v191);
    v201 = qcar(v191);
    v191 = stack[-5];
    v191 = qcdr(v191);
    v191 = qcar(v191);
    fn = elt(env, 5); /* bcsum */
    v191 = (*qfn2(fn))(qenv(fn), v201, v191);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-1] = v191;
    v191 = stack[-1];
    fn = elt(env, 6); /* bczero!? */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    if (v191 == nil) goto v179;
    v191 = qvalue(elt(env, 1)); /* nil */
    goto v250;

v250:
    stack[-1] = v191;
    v191 = stack[-6];
    v191 = qcdr(v191);
    v191 = qcdr(v191);
    stack[-6] = v191;
    v191 = stack[-5];
    v191 = qcdr(v191);
    v191 = qcdr(v191);
    stack[-5] = v191;
    goto v72;

v179:
    v293 = stack[-4];
    v201 = stack[-1];
    v191 = qvalue(elt(env, 1)); /* nil */
    v191 = list2star(v293, v201, v191);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    goto v250;

v124:
    v191 = stack[-6];
    stack[-1] = v191;
    v191 = qvalue(elt(env, 2)); /* t */
    stack[-7] = v191;
    goto v72;

v59:
    v191 = stack[-5];
    stack[-1] = v191;
    v191 = qvalue(elt(env, 2)); /* t */
    stack[-7] = v191;
    goto v72;
/* error exit handlers */
v190:
    popv(9);
    return nil;
}



/* Code for xreadlist */

static Lisp_Object MS_CDECL CC_xreadlist(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "xreadlist");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xreadlist");
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
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    fn = elt(env, 10); /* scan */
    v14 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v13 = elt(env, 1); /* !*rcbkt!* */
    if (!(v14 == v13)) goto v53;
    fn = elt(env, 10); /* scan */
    v13 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v13 = elt(env, 2); /* list */
    popv(5);
    return ncons(v13);

v53:
    v13 = stack[-1];
    if (v13 == nil) goto v37;
    v13 = elt(env, 3); /* group */
    fn = elt(env, 11); /* xread1 */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v13 = ncons(v13);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    fn = elt(env, 12); /* nconc2 */
    v13 = (*qfn2(fn))(qenv(fn), stack[0], v13);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    stack[0] = v13;
    goto v165;

v165:
    v13 = qvalue(elt(env, 4)); /* cursym!* */
    stack[-3] = v13;
    v14 = stack[-3];
    v13 = elt(env, 5); /* !*semicol!* */
    if (v14 == v13) goto v112;
    fn = elt(env, 10); /* scan */
    v14 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v13 = elt(env, 1); /* !*rcbkt!* */
    if (v14 == v13) goto v19;
    v13 = qvalue(elt(env, 7)); /* nil */
    goto v77;

v77:
    if (v13 == nil) goto v120;
    v14 = elt(env, 9); /* "Syntax error: invalid comma in list" */
    v13 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 13); /* symerr */
    v13 = (*qfn2(fn))(qenv(fn), v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v120;

v120:
    v14 = stack[-3];
    v13 = elt(env, 1); /* !*rcbkt!* */
    if (v14 == v13) goto v182;
    v13 = stack[-2];
    if (!(v13 == nil)) goto v53;
    v13 = stack[-3];
    stack[-2] = v13;
    goto v53;

v182:
    v14 = elt(env, 2); /* list */
    v13 = stack[-1];
    popv(5);
    return cons(v14, v13);

v19:
    v14 = stack[-3];
    v13 = elt(env, 8); /* !*comma!* */
    v13 = (v14 == v13 ? lisp_true : nil);
    goto v77;

v112:
    v14 = elt(env, 6); /* "Syntax error: semicolon in list" */
    v13 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 13); /* symerr */
    v13 = (*qfn2(fn))(qenv(fn), v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v120;

v37:
    stack[0] = stack[-1];
    v13 = elt(env, 3); /* group */
    fn = elt(env, 11); /* xread1 */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v13 = ncons(v13);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v13 = Lnconc(nil, stack[0], v13);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    stack[0] = v13;
    stack[-1] = v13;
    goto v165;
/* error exit handlers */
v96:
    popv(5);
    return nil;
}



/* Code for endmodule */

static Lisp_Object MS_CDECL CC_endmodule(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endmodule");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for endmodule");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v104 = qvalue(elt(env, 1)); /* mode!-list!* */
    if (!(v104 == nil)) goto v48;
    v104 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v104 == nil)) goto v76;
    v104 = elt(env, 3); /* "ENDMODULE called outside module" */
    fn = elt(env, 9); /* lprie */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[0];
    goto v76;

v76:
    v104 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[0];
    goto v48;

v48:
    v104 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 5)) = v104; /* exportslist!* */
    v104 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 6)) = v104; /* importslist!* */
    v104 = qvalue(elt(env, 4)); /* nil */
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[0];
    qvalue(elt(env, 7)) = v104; /* alglist!* */
    v104 = qvalue(elt(env, 1)); /* mode!-list!* */
    v104 = qcar(v104);
    qvalue(elt(env, 8)) = v104; /* !*mode */
    v104 = qvalue(elt(env, 1)); /* mode!-list!* */
    v104 = qcdr(v104);
    qvalue(elt(env, 1)) = v104; /* mode!-list!* */
    v104 = nil;
    { popv(1); return onevalue(v104); }
/* error exit handlers */
v126:
    popv(1);
    return nil;
}



/* Code for markedvarp */

static Lisp_Object CC_markedvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v76;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for markedvarp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v73 = v0;
/* end of prologue */
    v76 = elt(env, 1); /* !*marked!* */
        return Lflagp(nil, v73, v76);
}



/* Code for generic_arguments */

static Lisp_Object CC_generic_arguments(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v155, v164;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for generic_arguments");
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
    v108 = v0;
/* end of prologue */
    v164 = elt(env, 1); /* list */
    v155 = qcar(v108);
    v108 = elt(env, 2); /* generic_function */
    v108 = get(v155, v108);
    return cons(v164, v108);
}



/* Code for fs!:minusp!: */

static Lisp_Object CC_fsTminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:minusp:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v51 = v0;
/* end of prologue */
    v51 = qcdr(v51);
    {
        fn = elt(env, 1); /* fs!:minusp */
        return (*qfn1(fn))(qenv(fn), v51);
    }
}



/* Code for ofsf_simplat1 */

static Lisp_Object CC_ofsf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v297, v298, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_simplat1");
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
    v85 = v0;
/* end of prologue */
    v297 = v85;
    v297 = qcar(v297);
    stack[-3] = v297;
    v298 = stack[-3];
    v297 = elt(env, 1); /* (equal neq leq geq lessp greaterp) */
    v297 = Lmemq(nil, v298, v297);
    if (v297 == nil) goto v76;
    v297 = v85;
    v297 = qcdr(v297);
    v297 = qcar(v297);
    stack[-1] = v297;
    v297 = stack[-1];
    if (!consp(v297)) goto v60;
    v297 = stack[-1];
    v297 = qcar(v297);
    v297 = (consp(v297) ? nil : lisp_true);
    goto v61;

v61:
    if (v297 == nil) goto v24;
    v298 = stack[-3];
    v297 = stack[-1];
    fn = elt(env, 13); /* ofsf_evalatp */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    if (v297 == nil) goto v299;
    v297 = elt(env, 4); /* true */
    { popv(5); return onevalue(v297); }

v299:
    v297 = elt(env, 5); /* false */
    { popv(5); return onevalue(v297); }

v24:
    stack[0] = stack[-1];
    v297 = stack[-1];
    fn = elt(env, 14); /* sfto_dcontentf */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    fn = elt(env, 15); /* quotf */
    v297 = (*qfn2(fn))(qenv(fn), stack[0], v297);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    stack[-1] = v297;
    v297 = stack[-1];
    fn = elt(env, 16); /* minusf */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    if (v297 == nil) goto v69;
    v297 = stack[-1];
    fn = elt(env, 17); /* negf */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    stack[-1] = v297;
    v297 = stack[-3];
    fn = elt(env, 18); /* ofsf_anegrel */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    stack[-3] = v297;
    goto v69;

v69:
    v297 = qvalue(elt(env, 6)); /* !*rlsiatadv */
    if (v297 == nil) goto v20;
    v298 = stack[-3];
    v297 = elt(env, 7); /* equal */
    if (v298 == v297) goto v198;
    v298 = stack[-3];
    v297 = elt(env, 8); /* neq */
    if (v298 == v297) goto v188;
    v298 = stack[-3];
    v297 = elt(env, 9); /* leq */
    if (v298 == v297) goto v146;
    v298 = stack[-3];
    v297 = elt(env, 10); /* geq */
    if (v298 == v297) goto v281;
    v298 = stack[-3];
    v297 = elt(env, 11); /* lessp */
    if (v298 == v297) goto v191;
    v298 = stack[-3];
    v297 = elt(env, 12); /* greaterp */
    if (v298 == v297) goto v300;
    v297 = nil;
    { popv(5); return onevalue(v297); }

v300:
    v298 = stack[-1];
    v297 = stack[-2];
    {
        popv(5);
        fn = elt(env, 19); /* ofsf_simplgreaterp */
        return (*qfn2(fn))(qenv(fn), v298, v297);
    }

v191:
    v298 = stack[-1];
    v297 = stack[-2];
    {
        popv(5);
        fn = elt(env, 20); /* ofsf_simpllessp */
        return (*qfn2(fn))(qenv(fn), v298, v297);
    }

v281:
    v298 = stack[-1];
    v297 = stack[-2];
    {
        popv(5);
        fn = elt(env, 21); /* ofsf_simplgeq */
        return (*qfn2(fn))(qenv(fn), v298, v297);
    }

v146:
    v298 = stack[-1];
    v297 = stack[-2];
    {
        popv(5);
        fn = elt(env, 22); /* ofsf_simplleq */
        return (*qfn2(fn))(qenv(fn), v298, v297);
    }

v188:
    v298 = stack[-1];
    v297 = stack[-2];
    {
        popv(5);
        fn = elt(env, 23); /* ofsf_simplneq */
        return (*qfn2(fn))(qenv(fn), v298, v297);
    }

v198:
    v298 = stack[-1];
    v297 = stack[-2];
    {
        popv(5);
        fn = elt(env, 24); /* ofsf_simplequal */
        return (*qfn2(fn))(qenv(fn), v298, v297);
    }

v20:
    v298 = stack[-3];
    v297 = stack[-1];
    v85 = qvalue(elt(env, 2)); /* nil */
    popv(5);
    return list3(v298, v297, v85);

v60:
    v297 = qvalue(elt(env, 3)); /* t */
    goto v61;

v76:
    v297 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v297); }
/* error exit handlers */
v200:
    popv(5);
    return nil;
}



/* Code for replace!-next */

static Lisp_Object CC_replaceKnext(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v154, v299, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace-next");
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
    goto v67;

v67:
    v38 = stack[-1];
    if (v38 == nil) goto v130;
    v38 = stack[-1];
    v38 = qcar(v38);
    v169 = qcar(v38);
    v38 = stack[-1];
    v38 = qcar(v38);
    v38 = qcdr(v38);
    v299 = qcar(v38);
    v38 = stack[-1];
    v38 = qcar(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v154 = qcar(v38);
    v38 = stack[0];
    v38 = qcar(v38);
    v154 = list4(v169, v299, v154, v38);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    v38 = stack[-2];
    v38 = cons(v154, v38);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    stack[-2] = v38;
    v38 = stack[-1];
    v38 = qcdr(v38);
    stack[-1] = v38;
    v38 = stack[0];
    v38 = qcdr(v38);
    stack[0] = v38;
    goto v67;

v130:
    v38 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v38);
    }
/* error exit handlers */
v23:
    popv(4);
    return nil;
}



/* Code for mk!+resimp!+mat */

static Lisp_Object CC_mkLresimpLmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+resimp+mat");
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
    v96 = v0;
/* end of prologue */
    stack[-7] = v96;
    v96 = stack[-7];
    if (v96 == nil) goto v102;
    v96 = stack[-7];
    v96 = qcar(v96);
    stack[-3] = v96;
    v96 = stack[-3];
    if (v96 == nil) goto v173;
    v96 = stack[-3];
    v96 = qcar(v96);
    fn = elt(env, 2); /* resimp */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    stack[-1] = v96;
    stack[-2] = v96;
    goto v62;

v62:
    v96 = stack[-3];
    v96 = qcdr(v96);
    stack[-3] = v96;
    v96 = stack[-3];
    if (v96 == nil) goto v167;
    stack[0] = stack[-1];
    v96 = stack[-3];
    v96 = qcar(v96);
    fn = elt(env, 2); /* resimp */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    v96 = Lrplacd(nil, stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    v96 = stack[-1];
    v96 = qcdr(v96);
    stack[-1] = v96;
    goto v62;

v167:
    v96 = stack[-2];
    goto v37;

v37:
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    stack[-5] = v96;
    stack[-6] = v96;
    goto v75;

v75:
    v96 = stack[-7];
    v96 = qcdr(v96);
    stack[-7] = v96;
    v96 = stack[-7];
    if (v96 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    stack[-4] = stack[-5];
    v96 = stack[-7];
    v96 = qcar(v96);
    stack[-3] = v96;
    v96 = stack[-3];
    if (v96 == nil) goto v22;
    v96 = stack[-3];
    v96 = qcar(v96);
    fn = elt(env, 2); /* resimp */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    stack[-1] = v96;
    stack[-2] = v96;
    goto v66;

v66:
    v96 = stack[-3];
    v96 = qcdr(v96);
    stack[-3] = v96;
    v96 = stack[-3];
    if (v96 == nil) goto v18;
    stack[0] = stack[-1];
    v96 = stack[-3];
    v96 = qcar(v96);
    fn = elt(env, 2); /* resimp */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    v96 = Lrplacd(nil, stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    v96 = stack[-1];
    v96 = qcdr(v96);
    stack[-1] = v96;
    goto v66;

v18:
    v96 = stack[-2];
    goto v170;

v170:
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    v96 = Lrplacd(nil, stack[-4], v96);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-8];
    v96 = stack[-5];
    v96 = qcdr(v96);
    stack[-5] = v96;
    goto v75;

v22:
    v96 = qvalue(elt(env, 1)); /* nil */
    goto v170;

v173:
    v96 = qvalue(elt(env, 1)); /* nil */
    goto v37;

v102:
    v96 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v96); }
/* error exit handlers */
v11:
    popv(9);
    return nil;
}



/* Code for quotf!* */

static Lisp_Object CC_quotfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v54, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotf*");
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
    v69 = stack[-1];
    if (v69 == nil) goto v51;
    v54 = stack[-1];
    v69 = stack[0];
    fn = elt(env, 3); /* quotf */
    v69 = (*qfn2(fn))(qenv(fn), v54, v69);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    v54 = v69;
    v69 = v54;
    if (!(v69 == nil)) { popv(3); return onevalue(v54); }
    v54 = stack[-1];
    v69 = stack[0];
    v69 = cons(v54, v69);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    fn = elt(env, 4); /* rationalizesq */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    v74 = v69;
    v69 = v74;
    v54 = qcdr(v69);
    v69 = (Lisp_Object)17; /* 1 */
    if (v54 == v69) goto v125;
    v74 = elt(env, 2); /* "DIVISION FAILED" */
    v54 = stack[-1];
    v69 = stack[0];
    v69 = list3(v74, v54, v69);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 5); /* errach */
        return (*qfn1(fn))(qenv(fn), v69);
    }

v125:
    v69 = v74;
    v69 = qcar(v69);
    { popv(3); return onevalue(v69); }

v51:
    v69 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v69); }
/* error exit handlers */
v184:
    popv(3);
    return nil;
}



setup_type const u31_setup[] =
{
    {"specrd:plus",             too_few_2,      CC_specrdTplus,wrong_no_2},
    {"dip2a",                   CC_dip2a,       too_many_1,    wrong_no_1},
    {"vdpilcomb1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpilcomb1},
    {"simpwedge",               CC_simpwedge,   too_many_1,    wrong_no_1},
    {"rsubla",                  too_few_2,      CC_rsubla,     wrong_no_2},
    {"physoptimes",             CC_physoptimes, too_many_1,    wrong_no_1},
    {"consrecip",               CC_consrecip,   too_many_1,    wrong_no_1},
    {"baglistp",                CC_baglistp,    too_many_1,    wrong_no_1},
    {"make-modular-symmetric",  CC_makeKmodularKsymmetric,too_many_1,wrong_no_1},
    {"cl_rename-vars",          CC_cl_renameKvars,too_many_1,  wrong_no_1},
    {"rule",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_rule},
    {"cl_strict-gdnf",          too_few_2,      CC_cl_strictKgdnf,wrong_no_2},
    {"ratpoly_sgn",             CC_ratpoly_sgn, too_many_1,    wrong_no_1},
    {"determinantrd",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_determinantrd},
    {"partitwedge",             CC_partitwedge, too_many_1,    wrong_no_1},
    {"fortassign",              CC_fortassign,  too_many_1,    wrong_no_1},
    {"cvitimes2",               too_few_2,      CC_cvitimes2,  wrong_no_2},
    {"fs:prin",                 CC_fsTprin,     too_many_1,    wrong_no_1},
    {"flattens1",               CC_flattens1,   too_many_1,    wrong_no_1},
    {"general-multiply-by-constant-mod-p",too_few_2,CC_generalKmultiplyKbyKconstantKmodKp,wrong_no_2},
    {"cl_atl1",                 CC_cl_atl1,     too_many_1,    wrong_no_1},
    {"nlist",                   too_few_2,      CC_nlist,      wrong_no_2},
    {"depend-sq",               too_few_2,      CC_dependKsq,  wrong_no_2},
    {"pasf_ceil",               too_few_2,      CC_pasf_ceil,  wrong_no_2},
    {"omattrir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_omattrir},
    {"latexprint",              CC_latexprint,  too_many_1,    wrong_no_1},
    {"force-to-dm",             CC_forceKtoKdm, too_many_1,    wrong_no_1},
    {"formatfort",              CC_formatfort,  too_many_1,    wrong_no_1},
    {"find_bubles1",            too_few_2,      CC_find_bubles1,wrong_no_2},
    {"ratfunpri1",              CC_ratfunpri1,  too_many_1,    wrong_no_1},
    {"dp_from_ei",              CC_dp_from_ei,  too_many_1,    wrong_no_1},
    {"nonmult",                 CC_nonmult,     too_many_1,    wrong_no_1},
    {"janettreenodebuild",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_janettreenodebuild},
    {"component_action",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_component_action},
    {"change+int+to+sq",        CC_changeLintLtoLsq,too_many_1,wrong_no_1},
    {"mri_simplat1",            too_few_2,      CC_mri_simplat1,wrong_no_2},
    {"pasf_susibinad",          too_few_2,      CC_pasf_susibinad,wrong_no_2},
    {"aex_neg",                 CC_aex_neg,     too_many_1,    wrong_no_1},
    {"vdp_make",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdp_make},
    {"vectorrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_vectorrd},
    {"sparpri",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_sparpri},
    {"dipsum",                  too_few_2,      CC_dipsum,     wrong_no_2},
    {"xreadlist",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreadlist},
    {"endmodule",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_endmodule},
    {"markedvarp",              CC_markedvarp,  too_many_1,    wrong_no_1},
    {"generic_arguments",       CC_generic_arguments,too_many_1,wrong_no_1},
    {"fs:minusp:",              CC_fsTminuspT,  too_many_1,    wrong_no_1},
    {"ofsf_simplat1",           too_few_2,      CC_ofsf_simplat1,wrong_no_2},
    {"replace-next",            too_few_2,      CC_replaceKnext,wrong_no_2},
    {"mk+resimp+mat",           CC_mkLresimpLmat,too_many_1,   wrong_no_1},
    {"quotf*",                  too_few_2,      CC_quotfH,     wrong_no_2},
    {NULL, (one_args *)"u31", (two_args *)"6858 5329346 9225507", 0}
};

/* end of generated code */
