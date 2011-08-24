
/* $destdir\u51.c        Machine generated C code */

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


/* Code for radf */

static Lisp_Object CC_radf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for radf");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v1;
    stack[-8] = v0;
/* end of prologue */
    stack[-6] = nil;
    stack[-2] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    stack[-1] = qvalue(elt(env, 2)); /* !*mcd */
    qvalue(elt(env, 2)) = nil; /* !*mcd */
    v97 = stack[-8];
    if (v97 == nil) goto v100;
    v97 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v97; /* !*mcd */
    qvalue(elt(env, 1)) = v97; /* !*gcd */
    v97 = (Lisp_Object)17; /* 1 */
    stack[-9] = v97;
    v97 = (Lisp_Object)17; /* 1 */
    stack[-3] = v97;
    goto v101;

v101:
    v97 = stack[-8];
    if (!consp(v97)) goto v102;
    v97 = stack[-8];
    v97 = qcar(v97);
    v97 = (consp(v97) ? nil : lisp_true);
    goto v103;

v103:
    if (v97 == nil) goto v104;
    v98 = stack[-8];
    v97 = (Lisp_Object)17; /* 1 */
    if (v98 == v97) goto v105;
    v98 = stack[-8];
    v97 = stack[-7];
    fn = elt(env, 13); /* radd */
    v97 = (*qfn2(fn))(qenv(fn), v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-5] = v97;
    v97 = stack[-5];
    v98 = qcar(v97);
    v97 = stack[-9];
    fn = elt(env, 14); /* multf */
    v97 = (*qfn2(fn))(qenv(fn), v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-9] = v97;
    v97 = stack[-5];
    v98 = qcdr(v97);
    v97 = stack[-6];
    v97 = Lappend(nil, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-6] = v97;
    goto v105;

v105:
    v98 = stack[-3];
    v97 = (Lisp_Object)17; /* 1 */
    if (v98 == v97) goto v107;
    v97 = qvalue(elt(env, 12)); /* !*numval */
    if (v97 == nil) goto v108;
    stack[-5] = elt(env, 8); /* expt */
    stack[-4] = stack[-3];
    stack[0] = (Lisp_Object)17; /* 1 */
    v97 = stack[-7];
    fn = elt(env, 15); /* !:recip */
    v98 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = (Lisp_Object)17; /* 1 */
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = acons(stack[-4], stack[0], v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    fn = elt(env, 16); /* domainvalchk */
    v97 = (*qfn2(fn))(qenv(fn), stack[-5], v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-4] = v97;
    if (v97 == nil) goto v108;
    v97 = stack[-4];
    fn = elt(env, 17); /* !*q2f */
    v98 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = stack[-9];
    fn = elt(env, 18); /* multd */
    v97 = (*qfn2(fn))(qenv(fn), v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-9] = v97;
    goto v107;

v107:
    v98 = stack[-9];
    v97 = stack[-6];
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    goto v109;

v109:
    qvalue(elt(env, 2)) = stack[-1]; /* !*mcd */
    qvalue(elt(env, 1)) = stack[-2]; /* !*gcd */
    { popv(11); return onevalue(v97); }

v108:
    v97 = stack[-3];
    fn = elt(env, 19); /* prepf */
    v98 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = stack[-6];
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-6] = v97;
    goto v107;

v104:
    v97 = stack[-8];
    fn = elt(env, 20); /* comfac */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-4] = v97;
    v97 = stack[-4];
    v97 = qcar(v97);
    if (v97 == nil) goto v110;
    v97 = qvalue(elt(env, 5)); /* !*precise_complex */
    if (v97 == nil) goto v111;
    v98 = (Lisp_Object)1; /* 0 */
    v97 = stack[-4];
    v97 = qcar(v97);
    v97 = qcdr(v97);
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    goto v112;

v112:
    stack[-5] = v97;
    v97 = stack[-5];
    v98 = qcar(v97);
    v97 = (Lisp_Object)1; /* 0 */
    if (v98 == v97) goto v113;
    v97 = stack[-5];
    v97 = qcar(v97);
    v97 = Levenp(nil, v97);
    env = stack[-10];
    if (v97 == nil) goto v114;
    v97 = stack[-8];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v99 = qcar(v97);
    v97 = stack[-5];
    v98 = qcar(v97);
    v97 = (Lisp_Object)17; /* 1 */
    v97 = acons(v99, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v98 = v97;
    goto v115;

v115:
    v97 = stack[-9];
    fn = elt(env, 14); /* multf */
    v97 = (*qfn2(fn))(qenv(fn), v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-9] = v97;
    goto v113;

v113:
    v97 = stack[-5];
    v98 = qcdr(v97);
    v97 = (Lisp_Object)1; /* 0 */
    if (v98 == v97) goto v110;
    v97 = stack[-8];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = qcar(v97);
    if (!consp(v97)) goto v116;
    v97 = stack[-8];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = (consp(v97) ? nil : lisp_true);
    v97 = (v97 == nil ? lisp_true : nil);
    goto v117;

v117:
    if (v97 == nil) goto v118;
    v97 = stack[-8];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = qcar(v97);
    fn = elt(env, 19); /* prepf */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    goto v119;

v119:
    v98 = v97;
    v97 = stack[-5];
    v99 = qcdr(v97);
    v97 = (Lisp_Object)17; /* 1 */
    if (v99 == v97) goto v120;
    v99 = elt(env, 8); /* expt */
    v97 = stack[-5];
    v97 = qcdr(v97);
    v97 = list3(v99, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v98 = v97;
    goto v121;

v121:
    v97 = stack[-6];
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-6] = v97;
    goto v110;

v110:
    stack[0] = stack[-8];
    v97 = stack[-4];
    v97 = qcar(v97);
    if (v97 == nil) goto v122;
    v97 = stack[-4];
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    goto v123;

v123:
    fn = elt(env, 21); /* quotf */
    v97 = (*qfn2(fn))(qenv(fn), stack[0], v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-5] = v97;
    v97 = stack[-4];
    v97 = qcdr(v97);
    stack[-8] = v97;
    v97 = qvalue(elt(env, 9)); /* !*reduced */
    if (v97 == nil) goto v124;
    v97 = stack[-5];
    fn = elt(env, 22); /* minusf */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    if (v97 == nil) goto v124;
    v97 = stack[-5];
    fn = elt(env, 23); /* negf */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-5] = v97;
    v97 = stack[-8];
    fn = elt(env, 23); /* negf */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-8] = v97;
    goto v124;

v124:
    v98 = qvalue(elt(env, 10)); /* dmode!* */
    v97 = elt(env, 11); /* field */
    v97 = Lflagp(nil, v98, v97);
    env = stack[-10];
    if (v97 == nil) goto v125;
    v97 = stack[-5];
    fn = elt(env, 24); /* lnc */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-4] = v97;
    v98 = stack[-4];
    v97 = (Lisp_Object)17; /* 1 */
    if (v98 == v97) goto v125;
    v98 = stack[-5];
    v97 = stack[-4];
    fn = elt(env, 21); /* quotf */
    v97 = (*qfn2(fn))(qenv(fn), v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-5] = v97;
    v98 = stack[-4];
    v97 = stack[-3];
    fn = elt(env, 18); /* multd */
    v97 = (*qfn2(fn))(qenv(fn), v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-3] = v97;
    goto v125;

v125:
    v98 = stack[-5];
    v97 = (Lisp_Object)17; /* 1 */
    if (v98 == v97) goto v101;
    v97 = qvalue(elt(env, 5)); /* !*precise_complex */
    if (v97 == nil) goto v126;
    v98 = stack[-5];
    v97 = (Lisp_Object)17; /* 1 */
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v98 = v97;
    goto v127;

v127:
    v97 = stack[-7];
    fn = elt(env, 25); /* radf1 */
    v97 = (*qfn2(fn))(qenv(fn), v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-5] = v97;
    v97 = stack[-5];
    v97 = qcar(v97);
    stack[-4] = v97;
    v98 = stack[-4];
    v97 = (Lisp_Object)17; /* 1 */
    if (v98 == v97) goto v128;
    v97 = qvalue(elt(env, 6)); /* !*precise */
    if (v97 == nil) goto v129;
    v97 = stack[-7];
    v97 = Levenp(nil, v97);
    env = stack[-10];
    if (v97 == nil) goto v129;
    stack[0] = elt(env, 7); /* abs */
    v97 = stack[-4];
    fn = elt(env, 19); /* prepf */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = list2(stack[0], v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    fn = elt(env, 26); /* fkern */
    v98 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 27); /* getpower */
    v98 = (*qfn2(fn))(qenv(fn), v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = (Lisp_Object)17; /* 1 */
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-4] = v97;
    goto v129;

v129:
    v98 = stack[-4];
    v97 = stack[-9];
    fn = elt(env, 14); /* multf */
    v97 = (*qfn2(fn))(qenv(fn), v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-9] = v97;
    goto v128;

v128:
    v98 = stack[-6];
    v97 = stack[-5];
    v97 = qcdr(v97);
    v97 = Lappend(nil, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[-6] = v97;
    goto v101;

v126:
    v97 = stack[-5];
    fn = elt(env, 28); /* sqfrf */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v98 = v97;
    goto v127;

v122:
    v97 = stack[-4];
    v97 = qcdr(v97);
    goto v123;

v120:
    v97 = v98;
    v98 = v97;
    goto v121;

v118:
    v97 = stack[-8];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = qcar(v97);
    goto v119;

v116:
    v97 = qvalue(elt(env, 4)); /* nil */
    goto v117;

v114:
    v97 = stack[-8];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v99 = qcar(v97);
    v97 = stack[-4];
    v97 = qcar(v97);
    v98 = qcdr(v97);
    v97 = (Lisp_Object)17; /* 1 */
    v97 = acons(v99, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    stack[0] = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = qvalue(elt(env, 6)); /* !*precise */
    if (v97 == nil) goto v130;
    v97 = stack[-7];
    v97 = Levenp(nil, v97);
    env = stack[-10];
    if (v97 == nil) goto v130;
    v98 = elt(env, 7); /* abs */
    v97 = stack[-8];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = list2(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v99 = v97;
    goto v131;

v131:
    v97 = stack[-5];
    v98 = qcar(v97);
    v97 = (Lisp_Object)17; /* 1 */
    v97 = acons(v99, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v98 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v97 = stack[-7];
    fn = elt(env, 29); /* check!-radf!-sign */
    v97 = (*qfnn(fn))(qenv(fn), 3, stack[0], v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    v98 = v97;
    goto v115;

v130:
    v97 = stack[-8];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = qcar(v97);
    v99 = v97;
    goto v131;

v111:
    v97 = stack[-4];
    v97 = qcar(v97);
    v98 = qcdr(v97);
    v97 = stack[-7];
    v97 = Ldivide(nil, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    goto v112;

v102:
    v97 = qvalue(elt(env, 3)); /* t */
    goto v103;

v100:
    v97 = stack[-8];
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-10];
    goto v109;
/* error exit handlers */
v106:
    env = stack[-10];
    qvalue(elt(env, 2)) = stack[-1]; /* !*mcd */
    qvalue(elt(env, 1)) = stack[-2]; /* !*gcd */
    popv(11);
    return nil;
}



/* Code for update_kc_list */

static Lisp_Object MS_CDECL CC_update_kc_list(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v132, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "update_kc_list");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for update_kc_list");
#endif
    if (stack >= stacklimit)
    {
        push3(v132,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v132);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v132;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v145 = stack[-1];
    v144 = stack[-2];
    v144 = qcdr(v144);
    fn = elt(env, 1); /* list_assoc */
    v144 = (*qfn2(fn))(qenv(fn), v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v145 = v144;
    v144 = v145;
    if (v144 == nil) goto v91;
    stack[-3] = v145;
    v144 = v145;
    v144 = qcar(v144);
    stack[-1] = qcar(v144);
    v144 = v145;
    v144 = qcar(v144);
    v145 = qcdr(v144);
    v144 = stack[0];
    fn = elt(env, 2); /* addf */
    v144 = (*qfn2(fn))(qenv(fn), v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v144 = cons(stack[-1], v144);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v144 = Lrplaca(nil, stack[-3], v144);
    nil = C_nil;
    if (exception_pending()) goto v92;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v91:
    v144 = stack[-2];
    stack[-3] = qcar(v144);
    v145 = stack[-1];
    v144 = stack[0];
    v145 = cons(v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v92;
    v144 = stack[-2];
    v144 = qcdr(v144);
    {
        Lisp_Object v93 = stack[-3];
        popv(5);
        return list2star(v93, v145, v144);
    }
/* error exit handlers */
v92:
    popv(5);
    return nil;
}



/* Code for multtaylorsq */

static Lisp_Object CC_multtaylorsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multtaylorsq");
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
    v80 = stack[-6];
    if (v80 == nil) goto v3;
    v80 = stack[-5];
    v80 = qcar(v80);
    v80 = (v80 == nil ? lisp_true : nil);
    goto v2;

v2:
    if (v80 == nil) goto v161;
    v80 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v80); }

v161:
    stack[-7] = elt(env, 3); /* taylor!* */
    v80 = stack[-6];
    v80 = qcdr(v80);
    v80 = qcar(v80);
    stack[-4] = v80;
    v80 = stack[-4];
    if (v80 == nil) goto v140;
    v80 = stack[-4];
    v80 = qcar(v80);
    v160 = v80;
    v80 = v160;
    stack[0] = qcar(v80);
    v80 = v160;
    v160 = qcdr(v80);
    v80 = stack[-5];
    fn = elt(env, 5); /* multsq */
    v80 = (*qfn2(fn))(qenv(fn), v160, v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    fn = elt(env, 6); /* subs2!* */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    fn = elt(env, 7); /* resimp */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    v80 = cons(stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    stack[-2] = v80;
    stack[-3] = v80;
    goto v163;

v163:
    v80 = stack[-4];
    v80 = qcdr(v80);
    stack[-4] = v80;
    v80 = stack[-4];
    if (v80 == nil) goto v92;
    stack[-1] = stack[-2];
    v80 = stack[-4];
    v80 = qcar(v80);
    v160 = v80;
    v80 = v160;
    stack[0] = qcar(v80);
    v80 = v160;
    v160 = qcdr(v80);
    v80 = stack[-5];
    fn = elt(env, 5); /* multsq */
    v80 = (*qfn2(fn))(qenv(fn), v160, v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    fn = elt(env, 6); /* subs2!* */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    fn = elt(env, 7); /* resimp */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    v80 = cons(stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    v80 = Lrplacd(nil, stack[-1], v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    v80 = stack[-2];
    v80 = qcdr(v80);
    stack[-2] = v80;
    goto v163;

v92:
    v80 = stack[-3];
    stack[-1] = v80;
    goto v104;

v104:
    v80 = stack[-6];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    stack[0] = qcar(v80);
    v80 = qvalue(elt(env, 4)); /* !*taylorkeeporiginal */
    if (v80 == nil) goto v75;
    v80 = stack[-6];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcar(v80);
    if (v80 == nil) goto v75;
    v160 = stack[-5];
    v80 = stack[-6];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcar(v80);
    fn = elt(env, 5); /* multsq */
    v80 = (*qfn2(fn))(qenv(fn), v160, v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    v160 = v80;
    goto v164;

v164:
    v80 = stack[-6];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = qcar(v80);
    v80 = list2(v160, v80);
    nil = C_nil;
    if (exception_pending()) goto v162;
    {
        Lisp_Object v165 = stack[-7];
        Lisp_Object v166 = stack[-1];
        Lisp_Object v167 = stack[0];
        popv(9);
        return list3star(v165, v166, v167, v80);
    }

v75:
    v80 = qvalue(elt(env, 2)); /* nil */
    v160 = v80;
    goto v164;

v140:
    v80 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v80;
    goto v104;

v3:
    v80 = qvalue(elt(env, 1)); /* t */
    goto v2;
/* error exit handlers */
v162:
    popv(9);
    return nil;
}



/* Code for same!+dim!+squared!+p */

static Lisp_Object CC_sameLdimLsquaredLp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for same+dim+squared+p");
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
    v168 = stack[-1];
    fn = elt(env, 2); /* squared!+matrix!+p */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    if (v168 == nil) goto v14;
    v168 = stack[0];
    fn = elt(env, 2); /* squared!+matrix!+p */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    if (v168 == nil) goto v14;
    v168 = stack[-1];
    fn = elt(env, 3); /* get!+row!+nr */
    stack[0] = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    v168 = stack[-1];
    fn = elt(env, 3); /* get!+row!+nr */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    if (!(equal(stack[0], v168))) goto v14;
    v168 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v168); }

v14:
    v168 = nil;
    { popv(3); return onevalue(v168); }
/* error exit handlers */
v103:
    popv(3);
    return nil;
}



/* Code for kern!-list */

static Lisp_Object CC_kernKlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kern-list");
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
    v112 = v0;
/* end of prologue */
    stack[-3] = nil;
    v174 = v112;
    v112 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* kernels1 */
    v112 = (*qfn2(fn))(qenv(fn), v174, v112);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-1] = v112;
    goto v3;

v3:
    v112 = stack[-1];
    if (v112 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v112 = stack[-1];
    v112 = qcar(v112);
    stack[0] = v112;
    v174 = stack[0];
    v112 = stack[-2];
    fn = elt(env, 3); /* depend!-p */
    v112 = (*qfn2(fn))(qenv(fn), v174, v112);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    if (v112 == nil) goto v176;
    v174 = stack[0];
    v112 = stack[-3];
    v112 = cons(v174, v112);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-3] = v112;
    goto v176;

v176:
    v112 = stack[-1];
    v112 = qcdr(v112);
    stack[-1] = v112;
    goto v3;
/* error exit handlers */
v175:
    popv(5);
    return nil;
}



/* Code for aex_mvar */

static Lisp_Object CC_aex_mvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mvar");
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
    v177 = v0;
/* end of prologue */
    fn = elt(env, 2); /* aex_freeids */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-1];
    stack[0] = v177;
    if (!(v177 == nil)) goto v14;
    v177 = elt(env, 1); /* "***** aex_mvar: invalid argument" */
    v177 = Lprinc(nil, v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-1];
    v177 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v178;
    goto v14;

v14:
    v177 = stack[0];
    v177 = qcar(v177);
    { popv(2); return onevalue(v177); }
/* error exit handlers */
v178:
    popv(2);
    return nil;
}



/* Code for math_ml_printer */

static Lisp_Object CC_math_ml_printer(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v201, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for math_ml_printer");
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
    v201 = qvalue(elt(env, 1)); /* !*both */
    v200 = qvalue(elt(env, 2)); /* t */
    if (!(equal(v201, v200))) goto v95;
    v200 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = qvalue(elt(env, 4)); /* outputhandler!* */
    qvalue(elt(env, 4)) = v200; /* outputhandler!* */
    v201 = stack[0];
    v200 = qvalue(elt(env, 2)); /* t */
    if (equal(v201, v200)) goto v173;
    v200 = qvalue(elt(env, 4)); /* outputhandler!* */
    if (v200 == nil) goto v158;
    v202 = qvalue(elt(env, 4)); /* outputhandler!* */
    v201 = elt(env, 5); /* maprin */
    v200 = stack[0];
    v200 = Lapply2(nil, 3, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-3];
    goto v173;

v173:
    v200 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 30); /* terpri!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-3];
    qvalue(elt(env, 4)) = stack[-2]; /* outputhandler!* */
    goto v95;

v95:
    v201 = stack[-1];
    v200 = elt(env, 7); /* terpri */
    if (v201 == v200) goto v204;
    v200 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 10)) = v200; /* indent */
    v200 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 11)) = v200; /* consts_compl */
    v200 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 12)) = v200; /* consts_mat_compl */
    v200 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 13)) = v200; /* consts_int */
    v200 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 14)) = v200; /* consts_mat_int */
    v200 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 15)) = v200; /* found_int */
    v200 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 16)) = v200; /* found_compl */
    v200 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 17)) = v200; /* flagg */
    v200 = stack[0];
    v200 = Lconsp(nil, v200);
    env = stack[-3];
    if (v200 == nil) goto v205;
    v201 = qvalue(elt(env, 18)); /* !*web */
    v200 = qvalue(elt(env, 2)); /* t */
    if (!(equal(v201, v200))) goto v206;
    v200 = elt(env, 19); /* "<EMBED TYPE=""text/mathml"" MMLDATA=""" */
    fn = elt(env, 31); /* printout */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v206;

v206:
    v200 = elt(env, 20); /* "<math>" */
    fn = elt(env, 31); /* printout */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v200 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 10)) = v200; /* indent */
    v200 = stack[0];
    v201 = qcar(v200);
    v200 = elt(env, 21); /* setq */
    if (v201 == v200) goto v147;
    v200 = stack[0];
    v201 = qcar(v200);
    v200 = elt(env, 24); /* list */
    if (v201 == v200) goto v116;
    v200 = stack[0];
    v201 = qcar(v200);
    v200 = elt(env, 23); /* mat */
    if (v201 == v200) goto v208;
    v200 = stack[0];
    v201 = qcar(v200);
    v200 = elt(env, 25); /* !*sq */
    if (v201 == v200) goto v209;
    v200 = stack[0];
    fn = elt(env, 32); /* expression */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v210;

v210:
    v201 = qvalue(elt(env, 10)); /* indent */
    v200 = (Lisp_Object)49; /* 3 */
    v200 = difference2(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    qvalue(elt(env, 10)) = v200; /* indent */
    fn = elt(env, 33); /* close_forall */
    v200 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v200 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 10)) = v200; /* indent */
    v200 = elt(env, 26); /* "</math>" */
    fn = elt(env, 31); /* printout */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v201 = qvalue(elt(env, 18)); /* !*web */
    v200 = qvalue(elt(env, 2)); /* t */
    if (!(equal(v201, v200))) goto v211;
    v200 = elt(env, 27); /* """ HEIGHT=300 WIDTH=500>" */
    v200 = Lprinc(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v211;

v211:
    v200 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v153;

v153:
    v200 = qvalue(elt(env, 3)); /* nil */
    { popv(4); return onevalue(v200); }

v209:
    v200 = stack[0];
    v200 = qcdr(v200);
    v200 = qcar(v200);
    v200 = qcar(v200);
    if (v200 == nil) goto v110;
    v200 = stack[0];
    v200 = qcdr(v200);
    v201 = qcar(v200);
    v200 = elt(env, 22); /* prepf */
    fn = elt(env, 34); /* sqform */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v212;

v212:
    fn = elt(env, 35); /* arbitrary_c */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v200 = stack[0];
    v200 = qcdr(v200);
    v200 = qcar(v200);
    v200 = qcar(v200);
    if (v200 == nil) goto v213;
    v200 = stack[0];
    v200 = qcdr(v200);
    v201 = qcar(v200);
    v200 = elt(env, 22); /* prepf */
    fn = elt(env, 34); /* sqform */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v214;

v214:
    fn = elt(env, 32); /* expression */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v210;

v213:
    v200 = (Lisp_Object)1; /* 0 */
    goto v214;

v110:
    v200 = (Lisp_Object)1; /* 0 */
    goto v212;

v208:
    v200 = stack[0];
    fn = elt(env, 35); /* arbitrary_c */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v200 = stack[0];
    v200 = qcdr(v200);
    fn = elt(env, 36); /* matrixml */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v210;

v116:
    v200 = stack[0];
    fn = elt(env, 37); /* !*a2k */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    fn = elt(env, 35); /* arbitrary_c */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v200 = stack[0];
    v200 = qcdr(v200);
    fn = elt(env, 38); /* listml */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v210;

v147:
    v200 = stack[0];
    v200 = qcdr(v200);
    v200 = qcdr(v200);
    v200 = qcar(v200);
    v200 = Lconsp(nil, v200);
    env = stack[-3];
    if (v200 == nil) goto v215;
    v200 = stack[0];
    v200 = qcdr(v200);
    v200 = qcdr(v200);
    v200 = qcar(v200);
    fn = elt(env, 39); /* issq */
    v201 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v200 = (Lisp_Object)17; /* 1 */
    if (v201 == v200) goto v216;
    v200 = stack[0];
    v200 = qcdr(v200);
    v200 = qcdr(v200);
    v200 = qcar(v200);
    v201 = qcar(v200);
    v200 = elt(env, 23); /* mat */
    if (v201 == v200) goto v76;
    v200 = stack[0];
    v200 = qcdr(v200);
    v200 = qcdr(v200);
    v200 = qcar(v200);
    v201 = qcar(v200);
    v200 = elt(env, 24); /* list */
    if (!(v201 == v200)) goto v215;
    v200 = stack[0];
    v200 = qcdr(v200);
    v200 = qcdr(v200);
    v200 = qcar(v200);
    fn = elt(env, 37); /* !*a2k */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    fn = elt(env, 35); /* arbitrary_c */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v215;

v215:
    v200 = stack[0];
    fn = elt(env, 40); /* setqml */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v210;

v76:
    v200 = stack[0];
    v200 = qcdr(v200);
    v200 = qcdr(v200);
    v200 = qcar(v200);
    fn = elt(env, 35); /* arbitrary_c */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v215;

v216:
    v200 = stack[0];
    v200 = qcdr(v200);
    v200 = qcdr(v200);
    v200 = qcar(v200);
    v200 = qcdr(v200);
    v200 = qcar(v200);
    v200 = qcar(v200);
    if (v200 == nil) goto v217;
    v200 = stack[0];
    v200 = qcdr(v200);
    v200 = qcdr(v200);
    v200 = qcar(v200);
    v200 = qcdr(v200);
    v201 = qcar(v200);
    v200 = elt(env, 22); /* prepf */
    fn = elt(env, 34); /* sqform */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v218;

v218:
    fn = elt(env, 35); /* arbitrary_c */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v215;

v217:
    v200 = (Lisp_Object)1; /* 0 */
    goto v218;

v205:
    v200 = stack[0];
    if (!(!consp(v200))) goto v153;
    v201 = qvalue(elt(env, 18)); /* !*web */
    v200 = qvalue(elt(env, 2)); /* t */
    if (!(equal(v201, v200))) goto v219;
    v200 = elt(env, 28); /* "<EMBED TYPE=""text/mathml"" MMLDATA="" " */
    fn = elt(env, 31); /* printout */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v219;

v219:
    v200 = elt(env, 20); /* "<math>" */
    fn = elt(env, 31); /* printout */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v200 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 10)) = v200; /* indent */
    v200 = stack[0];
    fn = elt(env, 32); /* expression */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v200 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 10)) = v200; /* indent */
    v200 = elt(env, 26); /* "</math>" */
    fn = elt(env, 31); /* printout */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v201 = qvalue(elt(env, 18)); /* !*web */
    v200 = qvalue(elt(env, 2)); /* t */
    if (!(equal(v201, v200))) goto v220;
    v200 = elt(env, 29); /* " "" HEIGHT=300 WIDTH=500>" */
    v200 = Lprinc(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v220;

v220:
    v200 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v153;

v204:
    v200 = nil;
    { popv(4); return onevalue(v200); }

v158:
    v200 = qvalue(elt(env, 6)); /* overflowed!* */
    if (!(v200 == nil)) goto v173;
    v201 = stack[0];
    v200 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 41); /* maprint */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-3];
    goto v173;
/* error exit handlers */
v207:
    popv(4);
    return nil;
v203:
    env = stack[-3];
    qvalue(elt(env, 4)) = stack[-2]; /* outputhandler!* */
    popv(4);
    return nil;
}



/* Code for mappend */

static Lisp_Object CC_mappend(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mappend");
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
    v134 = v0;
/* end of prologue */
    stack[-4] = v134;
    v134 = stack[-4];
    if (v134 == nil) goto v143;
    v134 = stack[-4];
    v134 = qcar(v134);
    v133 = stack[-3];
    v134 = Lappend(nil, v133, v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v134 = ncons(v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    stack[-1] = v134;
    stack[-2] = v134;
    goto v2;

v2:
    v134 = stack[-4];
    v134 = qcdr(v134);
    stack[-4] = v134;
    v134 = stack[-4];
    if (v134 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v134 = stack[-4];
    v134 = qcar(v134);
    v133 = stack[-3];
    v134 = Lappend(nil, v133, v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v134 = ncons(v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v134 = Lrplacd(nil, stack[0], v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-5];
    v134 = stack[-1];
    v134 = qcdr(v134);
    stack[-1] = v134;
    goto v2;

v143:
    v134 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v134); }
/* error exit handlers */
v135:
    popv(6);
    return nil;
}



/* Code for gbfmult */

static Lisp_Object CC_gbfmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v135, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gbfmult");
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
    v95 = stack[-1];
    v95 = Lfloatp(nil, v95);
    env = stack[-3];
    if (v95 == nil) goto v109;
    v95 = stack[-1];
    fn = elt(env, 2); /* fl2bf */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    goto v7;

v7:
    stack[-1] = v95;
    v135 = stack[-1];
    v95 = stack[0];
    v95 = qcar(v95);
    fn = elt(env, 3); /* csl_timbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v135, v95);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v135 = stack[-1];
    v95 = stack[0];
    v95 = qcdr(v95);
    fn = elt(env, 3); /* csl_timbf */
    v95 = (*qfn2(fn))(qenv(fn), v135, v95);
    nil = C_nil;
    if (exception_pending()) goto v145;
    {
        Lisp_Object v224 = stack[-2];
        popv(4);
        return cons(v224, v95);
    }

v109:
    v95 = stack[-1];
    if (!consp(v95)) goto v173;
    v95 = stack[-1];
    goto v198;

v198:
    fn = elt(env, 4); /* csl_normbf */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    goto v7;

v173:
    v95 = stack[-1];
    v95 = integerp(v95);
    if (v95 == nil) goto v139;
    v136 = elt(env, 1); /* !:rd!: */
    v135 = stack[-1];
    v95 = (Lisp_Object)1; /* 0 */
    v95 = list2star(v136, v135, v95);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    goto v198;

v139:
    v95 = stack[-1];
    fn = elt(env, 5); /* read!:num */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    goto v198;
/* error exit handlers */
v145:
    popv(4);
    return nil;
}



/* Code for randpoly */

static Lisp_Object CC_randpoly(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v334, v335, v336, v337, v338;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for randpoly");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-14] = v0;
/* end of prologue */
    stack[-15] = nil;
    stack[-12] = nil;
    stack[-7] = nil;
    v334 = elt(env, 1); /* lambda_lqgaw0_11 */
    stack[-13] = v334;
    v334 = (Lisp_Object)81; /* 5 */
    stack[-10] = v334;
    v334 = (Lisp_Object)1; /* 0 */
    stack[-9] = v334;
    v334 = (Lisp_Object)97; /* 6 */
    stack[-11] = v334;
    v334 = elt(env, 2); /* sparse */
    stack[-8] = v334;
    stack[-6] = qvalue(elt(env, 3)); /* wtl!* */
    qvalue(elt(env, 3)) = nil; /* wtl!* */
    v334 = stack[-14];
    fn = elt(env, 17); /* revlis */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    stack[-14] = v334;
    v334 = qcar(v334);
    stack[0] = v334;
    v335 = stack[0];
    v334 = elt(env, 4); /* list */
    if (!consp(v335)) goto v340;
    v335 = qcar(v335);
    if (!(v335 == v334)) goto v340;
    v334 = stack[0];
    v334 = qcdr(v334);
    goto v104;

v104:
    stack[0] = v334;
    v334 = stack[0];
    stack[-5] = v334;
    v334 = stack[-5];
    if (v334 == nil) goto v222;
    v334 = stack[-5];
    v334 = qcar(v334);
    stack[-1] = v334;
    v334 = stack[-1];
    if (!consp(v334)) goto v341;
    v334 = stack[-1];
    v335 = qcar(v334);
    v334 = elt(env, 7); /* equalopr */
    v334 = Lflagp(nil, v335, v334);
    env = stack[-16];
    if (v334 == nil) goto v342;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    if (v334 == nil) goto v156;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = (v334 == nil ? lisp_true : nil);
    goto v145;

v145:
    if (v334 == nil) goto v111;
    v334 = stack[-1];
    fn = elt(env, 18); /* !*eqn2a */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    stack[-1] = v334;
    v334 = (Lisp_Object)17; /* 1 */
    stack[-9] = v334;
    goto v136;

v136:
    v334 = elt(env, 8); /* g */
    v334 = Lgensym1(nil, v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    stack[0] = v334;
    v336 = elt(env, 9); /* equal */
    v335 = stack[0];
    v334 = stack[-1];
    v335 = list3(v336, v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    v334 = stack[-7];
    v334 = cons(v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    stack[-7] = v334;
    v334 = stack[0];
    goto v95;

v95:
    v334 = ncons(v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    stack[-3] = v334;
    stack[-4] = v334;
    goto v91;

v91:
    v334 = stack[-5];
    v334 = qcdr(v334);
    stack[-5] = v334;
    v334 = stack[-5];
    if (v334 == nil) goto v216;
    stack[-2] = stack[-3];
    v334 = stack[-5];
    v334 = qcar(v334);
    stack[-1] = v334;
    v334 = stack[-1];
    if (!consp(v334)) goto v121;
    v334 = stack[-1];
    v335 = qcar(v334);
    v334 = elt(env, 7); /* equalopr */
    v334 = Lflagp(nil, v335, v334);
    env = stack[-16];
    if (v334 == nil) goto v343;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    if (v334 == nil) goto v74;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = (v334 == nil ? lisp_true : nil);
    goto v165;

v165:
    if (v334 == nil) goto v344;
    v334 = stack[-1];
    fn = elt(env, 18); /* !*eqn2a */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    stack[-1] = v334;
    v334 = (Lisp_Object)17; /* 1 */
    stack[-9] = v334;
    goto v345;

v345:
    v334 = elt(env, 8); /* g */
    v334 = Lgensym1(nil, v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    stack[0] = v334;
    v336 = elt(env, 9); /* equal */
    v335 = stack[0];
    v334 = stack[-1];
    v335 = list3(v336, v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    v334 = stack[-7];
    v334 = cons(v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    stack[-7] = v334;
    v334 = stack[0];
    goto v346;

v346:
    v334 = ncons(v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    v334 = Lrplacd(nil, stack[-2], v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    v334 = stack[-3];
    v334 = qcdr(v334);
    stack[-3] = v334;
    goto v91;

v344:
    v334 = stack[-1];
    fn = elt(env, 19); /* simp!* */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    fn = elt(env, 20); /* kernp */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    if (v334 == nil) goto v345;
    v334 = stack[-1];
    goto v346;

v74:
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v165;

v343:
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v165;

v121:
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v165;

v216:
    v334 = stack[-4];
    goto v347;

v347:
    stack[0] = v334;
    v334 = stack[-15];
    if (v334 == nil) goto v178;
    v334 = stack[0];
    v334 = qcar(v334);
    stack[0] = v334;
    goto v178;

v178:
    qvalue(elt(env, 3)) = stack[-6]; /* wtl!* */
    v334 = stack[-14];
    v334 = qcdr(v334);
    stack[-2] = v334;
    goto v348;

v348:
    v334 = stack[-2];
    if (v334 == nil) goto v28;
    v334 = stack[-2];
    v334 = qcar(v334);
    stack[-1] = v334;
    v335 = stack[-1];
    v334 = elt(env, 10); /* dense */
    if (v335 == v334) goto v64;
    v335 = stack[-1];
    v334 = elt(env, 2); /* sparse */
    v334 = (v335 == v334 ? lisp_true : nil);
    goto v188;

v188:
    if (v334 == nil) goto v65;
    v334 = stack[-1];
    stack[-8] = v334;
    goto v349;

v349:
    v334 = stack[-2];
    v334 = qcdr(v334);
    stack[-2] = v334;
    goto v348;

v65:
    v334 = stack[-1];
    if (!consp(v334)) goto v56;
    v334 = stack[-1];
    v335 = qcar(v334);
    v334 = elt(env, 7); /* equalopr */
    v334 = Lflagp(nil, v335, v334);
    env = stack[-16];
    if (v334 == nil) goto v350;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    if (v334 == nil) goto v351;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = (v334 == nil ? lisp_true : nil);
    goto v213;

v213:
    if (v334 == nil) goto v29;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v335 = qcar(v334);
    v334 = elt(env, 11); /* coeffs */
    if (v335 == v334) goto v180;
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v179;

v179:
    if (v334 == nil) goto v220;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcar(v334);
    stack[-13] = v334;
    goto v352;

v352:
    if (!(v334 == nil)) goto v349;

v29:
    v335 = stack[-1];
    v334 = elt(env, 16); /* "optional randpoly argument" */
    fn = elt(env, 21); /* typerr */
    v334 = (*qfn2(fn))(qenv(fn), v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    goto v349;

v220:
    v334 = stack[-1];
    v334 = qcdr(v334);
    v335 = qcar(v334);
    v334 = elt(env, 12); /* expons */
    if (v335 == v334) goto v354;
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v355;

v355:
    if (v334 == nil) goto v207;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcar(v334);
    stack[-12] = v334;
    goto v352;

v207:
    v334 = stack[-1];
    v334 = qcdr(v334);
    v335 = qcar(v334);
    v334 = elt(env, 13); /* (degree deg maxdeg) */
    v334 = Lmemq(nil, v335, v334);
    if (v334 == nil) goto v356;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcar(v334);
    fn = elt(env, 22); /* natnump */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    if (v334 == nil) goto v356;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcar(v334);
    stack[-10] = v334;
    goto v352;

v356:
    v334 = stack[-1];
    v334 = qcdr(v334);
    v335 = qcar(v334);
    v334 = elt(env, 14); /* (ord mindeg) */
    v334 = Lmemq(nil, v335, v334);
    if (v334 == nil) goto v357;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcar(v334);
    fn = elt(env, 22); /* natnump */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    if (v334 == nil) goto v357;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcar(v334);
    stack[-9] = v334;
    goto v352;

v357:
    v334 = stack[-1];
    v334 = qcdr(v334);
    v335 = qcar(v334);
    v334 = elt(env, 15); /* terms */
    if (v335 == v334) goto v358;
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v128;

v128:
    if (v334 == nil) goto v36;
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcar(v334);
    stack[-11] = v334;
    goto v352;

v36:
    v334 = nil;
    goto v352;

v358:
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcar(v334);
    fn = elt(env, 22); /* natnump */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    goto v128;

v354:
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcar(v334);
    fn = elt(env, 23); /* functionp */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    goto v355;

v180:
    v334 = stack[-1];
    v334 = qcdr(v334);
    v334 = qcdr(v334);
    v334 = qcar(v334);
    fn = elt(env, 23); /* functionp */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    goto v179;

v351:
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v213;

v350:
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v213;

v56:
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v213;

v64:
    v334 = qvalue(elt(env, 5)); /* t */
    goto v188;

v28:
    v335 = qvalue(elt(env, 6)); /* nil */
    v334 = (Lisp_Object)17; /* 1 */
    v334 = cons(v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-1] = v334;
    v335 = stack[-9];
    v334 = stack[-10];
    v334 = (Lisp_Object)lesseq2(v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    v334 = v334 ? lisp_true : nil;
    env = stack[-16];
    if (v334 == nil) goto v24;
    v335 = stack[-8];
    v334 = elt(env, 2); /* sparse */
    if (v335 == v334) goto v359;
    v334 = stack[-15];
    if (v334 == nil) goto v360;
    v335 = stack[-13];
    v334 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v334 = (*qfn2(fn))(qenv(fn), v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-1] = v334;
    v335 = stack[-9];
    v334 = (Lisp_Object)1; /* 0 */
    v334 = (Lisp_Object)greaterp2(v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    v334 = v334 ? lisp_true : nil;
    env = stack[-16];
    if (v334 == nil) goto v361;
    v335 = stack[0];
    v334 = stack[-9];
    fn = elt(env, 25); /* mksq */
    v334 = (*qfn2(fn))(qenv(fn), v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v334 = (*qfn2(fn))(qenv(fn), stack[-1], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-1] = v334;
    goto v361;

v361:
    v334 = stack[-9];
    v334 = add1(v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-2] = v334;
    goto v362;

v362:
    v335 = stack[-10];
    v334 = stack[-2];
    v334 = difference2(v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    v334 = Lminusp(nil, v334);
    env = stack[-16];
    if (!(v334 == nil)) goto v24;
    stack[-3] = stack[-1];
    v335 = stack[-13];
    v334 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v334 = (*qfn2(fn))(qenv(fn), v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[-1] = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    v335 = stack[0];
    v334 = stack[-2];
    fn = elt(env, 25); /* mksq */
    v334 = (*qfn2(fn))(qenv(fn), v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v334 = (*qfn2(fn))(qenv(fn), stack[-1], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v334 = (*qfn2(fn))(qenv(fn), stack[-3], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-1] = v334;
    v334 = stack[-2];
    v334 = add1(v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-2] = v334;
    goto v362;

v24:
    v334 = stack[-7];
    if (v334 == nil) { Lisp_Object res = stack[-1]; popv(17); return onevalue(res); }
    stack[0] = stack[-7];
    v334 = stack[-1];
    fn = elt(env, 28); /* mk!*sq */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    v334 = ncons(v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    v334 = Lappend(nil, stack[0], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 29); /* subeval */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    {
        popv(17);
        fn = elt(env, 19); /* simp!* */
        return (*qfn1(fn))(qenv(fn), v334);
    }

v360:
    v336 = stack[0];
    v335 = stack[-10];
    v334 = stack[-9];
    fn = elt(env, 30); /* rand!-mons!-dense */
    v334 = (*qfnn(fn))(qenv(fn), 3, v336, v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-3] = v334;
    goto v363;

v363:
    v334 = stack[-3];
    if (v334 == nil) goto v24;
    v334 = stack[-3];
    v334 = qcar(v334);
    stack[-2] = v334;
    v335 = stack[-13];
    v334 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v334 = (*qfn2(fn))(qenv(fn), v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    v335 = stack[-2];
    v334 = (Lisp_Object)17; /* 1 */
    v334 = cons(v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v334 = (*qfn2(fn))(qenv(fn), stack[0], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v334 = (*qfn2(fn))(qenv(fn), stack[-1], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-1] = v334;
    v334 = stack[-3];
    v334 = qcdr(v334);
    stack[-3] = v334;
    goto v363;

v359:
    v334 = stack[-12];
    if (v334 == nil) goto v364;
    v334 = stack[-15];
    if (v334 == nil) goto v365;
    v334 = (Lisp_Object)17; /* 1 */
    stack[-3] = v334;
    goto v366;

v366:
    v335 = stack[-11];
    v334 = stack[-3];
    v334 = difference2(v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    v334 = Lminusp(nil, v334);
    env = stack[-16];
    if (!(v334 == nil)) goto v24;
    stack[-4] = stack[-1];
    v335 = stack[-13];
    v334 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v334 = (*qfn2(fn))(qenv(fn), v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[-2] = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-1] = stack[0];
    v334 = stack[-12];
    fn = elt(env, 31); /* apply_e */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 32); /* !*kp2q */
    v334 = (*qfn2(fn))(qenv(fn), stack[-1], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v334 = (*qfn2(fn))(qenv(fn), stack[-2], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v334 = (*qfn2(fn))(qenv(fn), stack[-4], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-1] = v334;
    v334 = stack[-3];
    v334 = add1(v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-3] = v334;
    goto v366;

v365:
    v334 = (Lisp_Object)17; /* 1 */
    stack[-4] = v334;
    goto v367;

v367:
    v335 = stack[-11];
    v334 = stack[-4];
    v334 = difference2(v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    v334 = Lminusp(nil, v334);
    env = stack[-16];
    if (!(v334 == nil)) goto v24;
    v335 = stack[-13];
    v334 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v334 = (*qfn2(fn))(qenv(fn), v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    v335 = v334;
    v334 = v335;
    v334 = qcar(v334);
    if (v334 == nil) goto v368;
    stack[-5] = stack[-1];
    v334 = stack[0];
    stack[-3] = v334;
    goto v369;

v369:
    v334 = stack[-3];
    if (v334 == nil) goto v370;
    v334 = stack[-3];
    v334 = qcar(v334);
    stack[-2] = v335;
    stack[-1] = v334;
    v334 = stack[-12];
    fn = elt(env, 31); /* apply_e */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 32); /* !*kp2q */
    v334 = (*qfn2(fn))(qenv(fn), stack[-1], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v334 = (*qfn2(fn))(qenv(fn), stack[-2], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    v335 = v334;
    v334 = stack[-3];
    v334 = qcdr(v334);
    stack[-3] = v334;
    goto v369;

v370:
    v334 = v335;
    fn = elt(env, 27); /* addsq */
    v334 = (*qfn2(fn))(qenv(fn), stack[-5], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-1] = v334;
    goto v368;

v368:
    v334 = stack[-4];
    v334 = add1(v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-4] = v334;
    goto v367;

v364:
    v338 = stack[0];
    v337 = stack[-11];
    v336 = stack[-10];
    v335 = stack[-9];
    v334 = stack[-15];
    fn = elt(env, 33); /* rand!-mons!-sparse */
    v334 = (*qfnn(fn))(qenv(fn), 5, v338, v337, v336, v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-3] = v334;
    goto v371;

v371:
    v334 = stack[-3];
    if (v334 == nil) goto v24;
    v334 = stack[-3];
    v334 = qcar(v334);
    stack[-2] = v334;
    v335 = stack[-13];
    v334 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 24); /* apply */
    v334 = (*qfn2(fn))(qenv(fn), v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 19); /* simp!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    v335 = stack[-2];
    v334 = (Lisp_Object)17; /* 1 */
    v334 = cons(v335, v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 26); /* multsq */
    v334 = (*qfn2(fn))(qenv(fn), stack[0], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    fn = elt(env, 27); /* addsq */
    v334 = (*qfn2(fn))(qenv(fn), stack[-1], v334);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-16];
    stack[-1] = v334;
    v334 = stack[-3];
    v334 = qcdr(v334);
    stack[-3] = v334;
    goto v371;

v111:
    v334 = stack[-1];
    fn = elt(env, 19); /* simp!* */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    fn = elt(env, 20); /* kernp */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    if (v334 == nil) goto v136;
    v334 = stack[-1];
    goto v95;

v156:
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v145;

v342:
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v145;

v341:
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v145;

v222:
    v334 = qvalue(elt(env, 6)); /* nil */
    goto v347;

v340:
    v334 = qvalue(elt(env, 5)); /* t */
    stack[-15] = v334;
    v334 = stack[0];
    v334 = ncons(v334);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-16];
    goto v104;
/* error exit handlers */
v353:
    popv(17);
    return nil;
v339:
    env = stack[-16];
    qvalue(elt(env, 3)) = stack[-6]; /* wtl!* */
    popv(17);
    return nil;
}



/* Code for lambda_lqgaw0_11 */

static Lisp_Object MS_CDECL CC_lambda_lqgaw0_11(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lambda_lqgaw0_11");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqgaw0_11");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* end of prologue */
    v4 = (Lisp_Object)3185; /* 199 */
    fn = elt(env, 1); /* random */
    v109 = (*qfn1(fn))(qenv(fn), v4);
    errexit();
    v4 = (Lisp_Object)1585; /* 99 */
    return difference2(v109, v4);
}



/* Code for positive!-rounded!-float */

static Lisp_Object CC_positiveKroundedKfloat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for positive-rounded-float");
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
    v137 = stack[0];
    fn = elt(env, 1); /* rounded!-float */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-1];
    stack[0] = v137;
    v137 = stack[0];
    if (v137 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v104 = stack[0];
    v137 = (Lisp_Object)1; /* 0 */
    v137 = (Lisp_Object)lessp2(v104, v137);
    nil = C_nil;
    if (exception_pending()) goto v176;
    v137 = v137 ? lisp_true : nil;
    if (v137 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v137 = stack[0];
    popv(2);
    return negate(v137);
/* error exit handlers */
v176:
    popv(2);
    return nil;
}



/* Code for symmetrize!-inds */

static Lisp_Object CC_symmetrizeKinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v391, v350;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symmetrize-inds");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    v391 = (Lisp_Object)1; /* 0 */
    stack[-10] = v391;
    v391 = stack[-9];
    stack[-7] = v391;
    v391 = stack[-7];
    if (v391 == nil) goto v177;
    v391 = stack[-7];
    v391 = qcar(v391);
    v350 = v391;
    if (!consp(v350)) goto v158;
    stack[-3] = v391;
    v391 = stack[-3];
    if (v391 == nil) goto v392;
    v391 = stack[-3];
    v391 = qcar(v391);
    v350 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v391 = (*qfn2(fn))(qenv(fn), v350, v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = qcar(v391);
    v391 = ncons(v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    stack[-1] = v391;
    stack[-2] = v391;
    goto v347;

v347:
    v391 = stack[-3];
    v391 = qcdr(v391);
    stack[-3] = v391;
    v391 = stack[-3];
    if (v391 == nil) goto v332;
    stack[0] = stack[-1];
    v391 = stack[-3];
    v391 = qcar(v391);
    v350 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v391 = (*qfn2(fn))(qenv(fn), v350, v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = qcar(v391);
    v391 = ncons(v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = Lrplacd(nil, stack[0], v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = stack[-1];
    v391 = qcdr(v391);
    stack[-1] = v391;
    goto v347;

v332:
    v391 = stack[-2];
    goto v176;

v176:
    v391 = ncons(v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    stack[-5] = v391;
    stack[-6] = v391;
    goto v198;

v198:
    v391 = stack[-7];
    v391 = qcdr(v391);
    stack[-7] = v391;
    v391 = stack[-7];
    if (v391 == nil) goto v206;
    stack[-4] = stack[-5];
    v391 = stack[-7];
    v391 = qcar(v391);
    v350 = v391;
    if (!consp(v350)) goto v326;
    stack[-3] = v391;
    v391 = stack[-3];
    if (v391 == nil) goto v84;
    v391 = stack[-3];
    v391 = qcar(v391);
    v350 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v391 = (*qfn2(fn))(qenv(fn), v350, v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = qcar(v391);
    v391 = ncons(v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    stack[-1] = v391;
    stack[-2] = v391;
    goto v85;

v85:
    v391 = stack[-3];
    v391 = qcdr(v391);
    stack[-3] = v391;
    v391 = stack[-3];
    if (v391 == nil) goto v165;
    stack[0] = stack[-1];
    v391 = stack[-3];
    v391 = qcar(v391);
    v350 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v391 = (*qfn2(fn))(qenv(fn), v350, v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = qcar(v391);
    v391 = ncons(v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = Lrplacd(nil, stack[0], v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = stack[-1];
    v391 = qcdr(v391);
    stack[-1] = v391;
    goto v85;

v165:
    v391 = stack[-2];
    goto v393;

v393:
    v391 = ncons(v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = Lrplacd(nil, stack[-4], v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = stack[-5];
    v391 = qcdr(v391);
    stack[-5] = v391;
    goto v198;

v84:
    v391 = qvalue(elt(env, 1)); /* nil */
    goto v393;

v326:
    v350 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v391 = (*qfn2(fn))(qenv(fn), v350, v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = qcar(v391);
    goto v393;

v206:
    v391 = stack[-6];
    goto v100;

v100:
    stack[-5] = v391;
    v391 = stack[-5];
    v391 = qcar(v391);
    if (!consp(v391)) goto v71;
    v391 = stack[-5];
    fn = elt(env, 3); /* indordln */
    v391 = (*qfn1(fn))(qenv(fn), v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    fn = elt(env, 4); /* flatindl */
    v391 = (*qfn1(fn))(qenv(fn), v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    goto v193;

v193:
    stack[0] = v391;
    v391 = stack[-9];
    v391 = qcar(v391);
    if (!consp(v391)) goto v394;
    v391 = stack[-9];
    fn = elt(env, 4); /* flatindl */
    v391 = (*qfn1(fn))(qenv(fn), v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    stack[-9] = v391;
    goto v394;

v394:
    v350 = stack[-9];
    v391 = stack[0];
    fn = elt(env, 5); /* pair */
    v391 = (*qfn2(fn))(qenv(fn), v350, v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    stack[-5] = v391;
    stack[-6] = (Lisp_Object)17; /* 1 */
    v391 = stack[-8];
    stack[-7] = v391;
    v391 = stack[-7];
    if (v391 == nil) goto v208;
    v391 = stack[-7];
    v391 = qcar(v391);
    stack[-1] = v391;
    v391 = stack[-5];
    if (v391 == nil) goto v123;
    v391 = stack[-5];
    v391 = qcar(v391);
    stack[0] = qcar(v391);
    v391 = stack[-10];
    v391 = add1(v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    stack[-10] = v391;
    if (!(equal(stack[0], v391))) goto v123;
    v391 = stack[-5];
    v391 = qcar(v391);
    v391 = qcdr(v391);
    v350 = v391;
    v391 = stack[-5];
    v391 = qcdr(v391);
    stack[-5] = v391;
    v391 = v350;
    goto v67;

v67:
    v391 = ncons(v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    stack[-3] = v391;
    stack[-4] = v391;
    goto v395;

v395:
    v391 = stack[-7];
    v391 = qcdr(v391);
    stack[-7] = v391;
    v391 = stack[-7];
    if (v391 == nil) goto v396;
    stack[-2] = stack[-3];
    v391 = stack[-7];
    v391 = qcar(v391);
    stack[-1] = v391;
    v391 = stack[-5];
    if (v391 == nil) goto v397;
    v391 = stack[-5];
    v391 = qcar(v391);
    stack[0] = qcar(v391);
    v391 = stack[-10];
    v391 = add1(v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    stack[-10] = v391;
    if (!(equal(stack[0], v391))) goto v397;
    v391 = stack[-5];
    v391 = qcar(v391);
    v391 = qcdr(v391);
    v350 = v391;
    v391 = stack[-5];
    v391 = qcdr(v391);
    stack[-5] = v391;
    v391 = v350;
    goto v314;

v314:
    v391 = ncons(v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = Lrplacd(nil, stack[-2], v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = stack[-3];
    v391 = qcdr(v391);
    stack[-3] = v391;
    goto v395;

v397:
    v391 = stack[-1];
    goto v314;

v396:
    v391 = stack[-4];
    goto v398;

v398:
    {
        Lisp_Object v180 = stack[-6];
        popv(12);
        return cons(v180, v391);
    }

v123:
    v391 = stack[-1];
    goto v67;

v208:
    v391 = qvalue(elt(env, 1)); /* nil */
    goto v398;

v71:
    v391 = stack[-5];
    fn = elt(env, 6); /* indordn */
    v391 = (*qfn1(fn))(qenv(fn), v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    goto v193;

v392:
    v391 = qvalue(elt(env, 1)); /* nil */
    goto v176;

v158:
    v350 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v391 = (*qfn2(fn))(qenv(fn), v350, v391);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-11];
    v391 = qcar(v391);
    goto v176;

v177:
    v391 = qvalue(elt(env, 1)); /* nil */
    goto v100;
/* error exit handlers */
v179:
    popv(12);
    return nil;
}



/* Code for mod!-dump1 */

static Lisp_Object MS_CDECL CC_modKdump1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v132, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v169, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mod-dump1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod-dump1");
#endif
    if (stack >= stacklimit)
    {
        push3(v132,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v132);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v132;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v11;

v11:
    v141 = stack[-1];
    if (v141 == nil) goto v4;
    v141 = stack[-1];
    v141 = qcar(v141);
    stack[0] = qcar(v141);
    v170 = stack[-3];
    v169 = stack[-2];
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcdr(v141);
    fn = elt(env, 1); /* l!-subst */
    v169 = (*qfnn(fn))(qenv(fn), 3, v170, v169, v141);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-5];
    v141 = stack[-4];
    v141 = acons(stack[0], v169, v141);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-5];
    stack[-4] = v141;
    v141 = stack[-1];
    v141 = qcdr(v141);
    stack[-1] = v141;
    goto v11;

v4:
    v141 = stack[-4];
    {
        popv(6);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v141);
    }
/* error exit handlers */
v392:
    popv(6);
    return nil;
}



/* Code for force!-lc */

static Lisp_Object CC_forceKlc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v372, v177;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for force-lc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v173 = v1;
    v372 = v0;
/* end of prologue */
    v177 = v372;
    v177 = qcar(v177);
    v177 = qcar(v177);
    v372 = qcdr(v372);
    return acons(v177, v173, v372);
}



/* Code for compactf0 */

static Lisp_Object MS_CDECL CC_compactf0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v132, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v321, v148, v80, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "compactf0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactf0");
#endif
    if (stack >= stacklimit)
    {
        push3(v132,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v132);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v132;
    stack[-6] = v1;
    stack[-1] = v0;
/* end of prologue */
    v148 = stack[-1];
    v321 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v321 = (*qfn2(fn))(qenv(fn), v148, v321);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    stack[-7] = v321;
    v148 = stack[-6];
    v321 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v321 = (*qfn2(fn))(qenv(fn), v148, v321);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    stack[0] = v321;
    v148 = elt(env, 2); /* !~ */
    v321 = stack[-6];
    v321 = Lsmemq(nil, v148, v321);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    if (v321 == nil) goto v171;
    v148 = stack[-7];
    v321 = stack[0];
    fn = elt(env, 4); /* compactfmatch */
    v321 = (*qfn2(fn))(qenv(fn), v148, v321);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    stack[-3] = v321;
    goto v223;

v223:
    v321 = stack[-3];
    if (v321 == nil) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v321 = stack[-3];
    v321 = qcar(v321);
    stack[-2] = v321;
    v321 = stack[-2];
    if (v321 == nil) goto v332;
    stack[0] = elt(env, 2); /* !~ */
    v148 = stack[-2];
    v321 = stack[-5];
    v321 = Lsublis(nil, v148, v321);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    stack[-4] = v321;
    v321 = Lsmemq(nil, stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    if (v321 == nil) goto v412;
    v321 = qvalue(elt(env, 1)); /* nil */
    goto v413;

v413:
    if (v321 == nil) goto v332;
    stack[-2] = stack[-1];
    stack[-1] = stack[-4];
    stack[0] = stack[-7];
    v148 = stack[-4];
    v321 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v321 = (*qfn2(fn))(qenv(fn), v148, v321);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    fn = elt(env, 5); /* compactf1 */
    v321 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    stack[-1] = v321;
    goto v332;

v332:
    v321 = stack[-3];
    v321 = qcdr(v321);
    stack[-3] = v321;
    goto v223;

v412:
    v321 = stack[-4];
    fn = elt(env, 6); /* eval */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    if (v321 == nil) goto v414;
    stack[0] = elt(env, 2); /* !~ */
    v148 = stack[-6];
    v321 = stack[-2];
    fn = elt(env, 7); /* subf */
    v321 = (*qfn2(fn))(qenv(fn), v148, v321);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    v321 = qcar(v321);
    stack[-4] = v321;
    v321 = Lsmemq(nil, stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-8];
    v321 = (v321 == nil ? lisp_true : nil);
    goto v413;

v414:
    v321 = qvalue(elt(env, 1)); /* nil */
    goto v413;

v171:
    v160 = stack[-1];
    v80 = stack[-6];
    v148 = stack[-7];
    v321 = stack[0];
    {
        popv(9);
        fn = elt(env, 5); /* compactf1 */
        return (*qfnn(fn))(qenv(fn), 4, v160, v80, v148, v321);
    }
/* error exit handlers */
v162:
    popv(9);
    return nil;
}



/* Code for lf!=tovarlessp */

static Lisp_Object CC_lfMtovarlessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v372, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lf=tovarlessp");
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
/* copy arguments values to proper place */
    v372 = v1;
    v177 = v0;
/* end of prologue */
    fn = elt(env, 1); /* mo_compare */
    v177 = (*qfn2(fn))(qenv(fn), v177, v372);
    errexit();
    v372 = (Lisp_Object)17; /* 1 */
    v372 = (v177 == v372 ? lisp_true : nil);
    return onevalue(v372);
}



/* Code for lexorder */

static Lisp_Object CC_lexorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lexorder");
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
    v204 = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = v204;
    goto v3;

v3:
    v204 = stack[-3];
    if (v204 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v204 = stack[-3];
    v204 = qcar(v204);
    stack[-2] = v204;
    stack[-1] = qvalue(elt(env, 2)); /* gv */
    v204 = stack[-2];
    stack[0] = qcar(v204);
    v95 = qvalue(elt(env, 2)); /* gv */
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = *(Lisp_Object *)((char *)v95 + (CELL-TAG_VECTOR) + ((int32_t)v204/(16/CELL)));
    fn = elt(env, 3); /* !*g2lex */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-5];
    fn = elt(env, 4); /* gcdout */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-5];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v204;
    fn = elt(env, 5); /* ljet */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-5];
    v95 = stack[-2];
    v95 = qcar(v95);
    v95 = cons(v95, v204);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-5];
    v204 = stack[-4];
    fn = elt(env, 6); /* insert */
    v204 = (*qfn2(fn))(qenv(fn), v95, v204);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-5];
    stack[-4] = v204;
    v204 = stack[-3];
    v204 = qcdr(v204);
    stack[-3] = v204;
    goto v3;
/* error exit handlers */
v145:
    popv(6);
    return nil;
}



/* Code for pa_vect2list */

static Lisp_Object CC_pa_vect2list(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v329, v330;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pa_vect2list");
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
    v329 = stack[-6];
    v329 = qcdr(v329);
    fn = elt(env, 2); /* upbve */
    v329 = (*qfn1(fn))(qenv(fn), v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = sub1(v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = Lmkvect(nil, v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    stack[-7] = v329;
    v329 = (Lisp_Object)17; /* 1 */
    stack[-4] = v329;
    goto v137;

v137:
    v329 = stack[-6];
    v329 = qcdr(v329);
    fn = elt(env, 2); /* upbve */
    v330 = (*qfn1(fn))(qenv(fn), v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = stack[-4];
    v329 = difference2(v330, v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = Lminusp(nil, v329);
    env = stack[-8];
    if (v329 == nil) goto v139;
    v329 = stack[-6];
    v329 = qcar(v329);
    stack[-4] = v329;
    v329 = stack[-4];
    if (v329 == nil) goto v150;
    v329 = stack[-4];
    v329 = qcar(v329);
    stack[0] = stack[-7];
    v329 = sub1(v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v329/(16/CELL)));
    fn = elt(env, 3); /* ordn */
    v329 = (*qfn1(fn))(qenv(fn), v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = ncons(v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    stack[-2] = v329;
    stack[-3] = v329;
    goto v404;

v404:
    v329 = stack[-4];
    v329 = qcdr(v329);
    stack[-4] = v329;
    v329 = stack[-4];
    if (v329 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v329 = stack[-4];
    v329 = qcar(v329);
    stack[0] = stack[-7];
    v329 = sub1(v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v329/(16/CELL)));
    fn = elt(env, 3); /* ordn */
    v329 = (*qfn1(fn))(qenv(fn), v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = ncons(v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = Lrplacd(nil, stack[-1], v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = stack[-2];
    v329 = qcdr(v329);
    stack[-2] = v329;
    goto v404;

v150:
    v329 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v329); }

v139:
    v329 = stack[-6];
    stack[0] = qcdr(v329);
    v329 = stack[-4];
    v329 = sub1(v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v329/(16/CELL)));
    stack[-5] = v329;
    stack[-3] = stack[-7];
    v329 = stack[-5];
    stack[-2] = sub1(v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    stack[-1] = stack[-4];
    stack[0] = stack[-7];
    v329 = stack[-5];
    v329 = sub1(v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    v329 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v329/(16/CELL)));
    v329 = cons(stack[-1], v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v329;
    v329 = stack[-4];
    v329 = add1(v329);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-8];
    stack[-4] = v329;
    goto v137;
/* error exit handlers */
v84:
    popv(9);
    return nil;
}



/* Code for repr_ldeg */

static Lisp_Object CC_repr_ldeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v2;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repr_ldeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v2 = qcdr(v2);
    v2 = qcdr(v2);
    v2 = qcdr(v2);
    v2 = qcdr(v2);
    v2 = qcar(v2);
    return onevalue(v2);
}



/* Code for aex_rem */

static Lisp_Object MS_CDECL CC_aex_rem(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v132, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v173, v372;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "aex_rem");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_rem");
#endif
    if (stack >= stacklimit)
    {
        push3(v132,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v132);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v172 = v132;
    v173 = v1;
    v372 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_quotrem */
    v172 = (*qfnn(fn))(qenv(fn), 3, v372, v173, v172);
    errexit();
    v172 = qcdr(v172);
    return onevalue(v172);
}



/* Code for setspmatelem2 */

static Lisp_Object CC_setspmatelem2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v416, v417, v73, v389;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setspmatelem2");
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
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v416 = stack[-3];
    v417 = qcar(v416);
    v416 = elt(env, 1); /* avalue */
    v416 = get(v417, v416);
    env = stack[-5];
    v416 = qcdr(v416);
    v416 = qcar(v416);
    stack[-4] = v416;
    v416 = stack[-4];
    v416 = qcdr(v416);
    v416 = qcdr(v416);
    v416 = qcar(v416);
    v416 = qcdr(v416);
    stack[-1] = v416;
    v416 = stack[-3];
    v416 = qcdr(v416);
    fn = elt(env, 5); /* revlis */
    v416 = (*qfn1(fn))(qenv(fn), v416);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-5];
    stack[0] = v416;
    v416 = stack[-4];
    if (v416 == nil) goto v158;
    v416 = stack[0];
    v417 = qcar(v416);
    v416 = stack[-1];
    v416 = qcar(v416);
    v416 = (Lisp_Object)greaterp2(v417, v416);
    nil = C_nil;
    if (exception_pending()) goto v342;
    v416 = v416 ? lisp_true : nil;
    env = stack[-5];
    if (!(v416 == nil)) goto v144;
    v416 = stack[0];
    v416 = qcdr(v416);
    v417 = qcar(v416);
    v416 = stack[-1];
    v416 = qcdr(v416);
    v416 = qcar(v416);
    v416 = (Lisp_Object)greaterp2(v417, v416);
    nil = C_nil;
    if (exception_pending()) goto v342;
    v416 = v416 ? lisp_true : nil;
    env = stack[-5];
    if (!(v416 == nil)) goto v144;
    v389 = stack[-3];
    v73 = stack[-2];
    v417 = stack[-4];
    v416 = qvalue(elt(env, 4)); /* nil */
    {
        popv(6);
        fn = elt(env, 6); /* letmtr3 */
        return (*qfnn(fn))(qenv(fn), 4, v389, v73, v417, v416);
    }

v144:
    v416 = stack[-3];
    v417 = qcar(v416);
    v416 = elt(env, 3); /* "The dimensions are wrong - matrix unaligned" 
*/
    fn = elt(env, 7); /* typerr */
    v416 = (*qfn2(fn))(qenv(fn), v417, v416);
    nil = C_nil;
    if (exception_pending()) goto v342;
    goto v176;

v176:
    v416 = nil;
    { popv(6); return onevalue(v416); }

v158:
    v416 = stack[-3];
    v417 = qcar(v416);
    v416 = elt(env, 2); /* "matrix" */
    fn = elt(env, 7); /* typerr */
    v416 = (*qfn2(fn))(qenv(fn), v417, v416);
    nil = C_nil;
    if (exception_pending()) goto v342;
    goto v176;
/* error exit handlers */
v342:
    popv(6);
    return nil;
}



/* Code for exptchk0 */

static Lisp_Object MS_CDECL CC_exptchk0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v132, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v384, v325, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "exptchk0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptchk0");
#endif
    if (stack >= stacklimit)
    {
        push3(v132,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v132);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v132;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v384 = stack[-2];
    if (v384 == nil) goto v4;
    v384 = stack[-2];
    if (!consp(v384)) goto v178;
    v384 = stack[-2];
    v384 = qcar(v384);
    v384 = (consp(v384) ? nil : lisp_true);
    goto v422;

v422:
    if (v384 == nil) goto v169;
    v325 = stack[-2];
    v384 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); /* exptunwind */
        return (*qfn2(fn))(qenv(fn), v325, v384);
    }

v169:
    v384 = stack[-2];
    v384 = qcar(v384);
    v384 = qcar(v384);
    v325 = qcar(v384);
    v384 = elt(env, 3); /* expt */
    if (!consp(v325)) goto v408;
    v325 = qcar(v325);
    if (!(v325 == v384)) goto v408;
    v384 = stack[-2];
    v384 = qcar(v384);
    v384 = qcar(v384);
    v384 = qcar(v384);
    v384 = qcdr(v384);
    v325 = qcar(v384);
    v384 = stack[0];
    fn = elt(env, 5); /* expttermp1 */
    v384 = (*qfn2(fn))(qenv(fn), v325, v384);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-4];
    goto v399;

v399:
    if (v384 == nil) goto v84;
    v384 = stack[-2];
    v384 = qcar(v384);
    stack[-3] = qcdr(v384);
    v384 = stack[-2];
    v384 = qcar(v384);
    v325 = qcar(v384);
    v384 = stack[-1];
    v325 = cons(v325, v384);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-4];
    v384 = stack[0];
    stack[-3] = CC_exptchk0(env, 3, stack[-3], v325, v384);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-4];
    v384 = stack[-2];
    v78 = qcdr(v384);
    v325 = stack[-1];
    v384 = stack[0];
    v384 = CC_exptchk0(env, 3, v78, v325, v384);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-4];
    {
        Lisp_Object v383 = stack[-3];
        popv(5);
        fn = elt(env, 6); /* addsq */
        return (*qfn2(fn))(qenv(fn), v383, v384);
    }

v84:
    v384 = stack[-2];
    v384 = qcar(v384);
    v325 = qcar(v384);
    v384 = (Lisp_Object)17; /* 1 */
    v384 = cons(v325, v384);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-4];
    v325 = ncons(v384);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-4];
    v384 = (Lisp_Object)17; /* 1 */
    stack[-3] = cons(v325, v384);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-4];
    v384 = stack[-2];
    v384 = qcar(v384);
    v78 = qcdr(v384);
    v325 = stack[-1];
    v384 = stack[0];
    v384 = CC_exptchk0(env, 3, v78, v325, v384);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-4];
    fn = elt(env, 7); /* multsq */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[-3], v384);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-4];
    v384 = stack[-2];
    v78 = qcdr(v384);
    v325 = stack[-1];
    v384 = stack[0];
    v384 = CC_exptchk0(env, 3, v78, v325, v384);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-4];
    {
        Lisp_Object v423 = stack[-3];
        popv(5);
        fn = elt(env, 6); /* addsq */
        return (*qfn2(fn))(qenv(fn), v423, v384);
    }

v408:
    v384 = stack[-2];
    v384 = qcar(v384);
    v384 = qcar(v384);
    v325 = qcar(v384);
    v384 = stack[0];
    fn = elt(env, 5); /* expttermp1 */
    v384 = (*qfn2(fn))(qenv(fn), v325, v384);
    nil = C_nil;
    if (exception_pending()) goto v382;
    env = stack[-4];
    goto v399;

v178:
    v384 = qvalue(elt(env, 2)); /* t */
    goto v422;

v4:
    v325 = qvalue(elt(env, 1)); /* nil */
    v384 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v325, v384);
/* error exit handlers */
v382:
    popv(5);
    return nil;
}



/* Code for multsm */

static Lisp_Object CC_multsm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v425, v426;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multsm");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-1] = stack[-7];
    v426 = (Lisp_Object)17; /* 1 */
    v425 = (Lisp_Object)17; /* 1 */
    v425 = cons(v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    if (equal(stack[-1], v425)) { Lisp_Object res = stack[0]; popv(10); return onevalue(res); }
    v425 = stack[0];
    stack[-8] = v425;
    v425 = stack[-8];
    if (v425 == nil) goto v158;
    v425 = stack[-8];
    v425 = qcar(v425);
    stack[-3] = v425;
    v425 = stack[-3];
    if (v425 == nil) goto v112;
    v425 = stack[-3];
    v425 = qcar(v425);
    v426 = stack[-7];
    fn = elt(env, 2); /* multsq */
    v425 = (*qfn2(fn))(qenv(fn), v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    v425 = ncons(v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    stack[-1] = v425;
    stack[-2] = v425;
    goto v170;

v170:
    v425 = stack[-3];
    v425 = qcdr(v425);
    stack[-3] = v425;
    v425 = stack[-3];
    if (v425 == nil) goto v224;
    stack[0] = stack[-1];
    v425 = stack[-3];
    v425 = qcar(v425);
    v426 = stack[-7];
    fn = elt(env, 2); /* multsq */
    v425 = (*qfn2(fn))(qenv(fn), v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    v425 = ncons(v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    v425 = Lrplacd(nil, stack[0], v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    v425 = stack[-1];
    v425 = qcdr(v425);
    stack[-1] = v425;
    goto v170;

v224:
    v425 = stack[-2];
    goto v169;

v169:
    v425 = ncons(v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    stack[-5] = v425;
    stack[-6] = v425;
    goto v96;

v96:
    v425 = stack[-8];
    v425 = qcdr(v425);
    stack[-8] = v425;
    v425 = stack[-8];
    if (v425 == nil) { Lisp_Object res = stack[-6]; popv(10); return onevalue(res); }
    stack[-4] = stack[-5];
    v425 = stack[-8];
    v425 = qcar(v425);
    stack[-3] = v425;
    v425 = stack[-3];
    if (v425 == nil) goto v427;
    v425 = stack[-3];
    v425 = qcar(v425);
    v426 = stack[-7];
    fn = elt(env, 2); /* multsq */
    v425 = (*qfn2(fn))(qenv(fn), v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    v425 = ncons(v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    stack[-1] = v425;
    stack[-2] = v425;
    goto v393;

v393:
    v425 = stack[-3];
    v425 = qcdr(v425);
    stack[-3] = v425;
    v425 = stack[-3];
    if (v425 == nil) goto v84;
    stack[0] = stack[-1];
    v425 = stack[-3];
    v425 = qcar(v425);
    v426 = stack[-7];
    fn = elt(env, 2); /* multsq */
    v425 = (*qfn2(fn))(qenv(fn), v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    v425 = ncons(v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    v425 = Lrplacd(nil, stack[0], v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    v425 = stack[-1];
    v425 = qcdr(v425);
    stack[-1] = v425;
    goto v393;

v84:
    v425 = stack[-2];
    goto v378;

v378:
    v425 = ncons(v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    v425 = Lrplacd(nil, stack[-4], v425);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-9];
    v425 = stack[-5];
    v425 = qcdr(v425);
    stack[-5] = v425;
    goto v96;

v427:
    v425 = qvalue(elt(env, 1)); /* nil */
    goto v378;

v112:
    v425 = qvalue(elt(env, 1)); /* nil */
    goto v169;

v158:
    v425 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v425); }
/* error exit handlers */
v79:
    popv(10);
    return nil;
}



/* Code for groeblistadd */

static Lisp_Object CC_groeblistadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v158, v138, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeblistadd");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v138 = v1;
    v139 = v0;
/* end of prologue */
    v158 = qvalue(elt(env, 1)); /* hcount!* */
    v157 = (Lisp_Object)80001; /* 5000 */
    if (((int32_t)(v158)) < ((int32_t)(v157))) goto v198;
    v157 = v139;
    v158 = v138;
    {
        fn = elt(env, 2); /* vdplsortinreplacing */
        return (*qfn2(fn))(qenv(fn), v157, v158);
    }

v198:
    v157 = v139;
    v158 = v138;
    {
        fn = elt(env, 3); /* vdplsortin */
        return (*qfn2(fn))(qenv(fn), v157, v158);
    }
}



/* Code for groebreduceonestepint */

static Lisp_Object MS_CDECL CC_groebreduceonestepint(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v132, Lisp_Object v8,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v432, v81, v433;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "groebreduceonestepint");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebreduceonestepint");
#endif
    if (stack >= stacklimit)
    {
        push5(v7,v8,v132,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v132,v8,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    stack[-4] = v8;
    stack[-3] = v132;
    stack[-6] = v1;
    stack[-2] = v0;
/* end of prologue */
    v432 = stack[-1];
    fn = elt(env, 8); /* vdpred */
    v432 = (*qfn1(fn))(qenv(fn), v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    stack[0] = v432;
    v81 = v432;
    v432 = v81;
    if (v432 == nil) goto v411;
    v432 = v81;
    v432 = qcdr(v432);
    v432 = qcdr(v432);
    v432 = qcdr(v432);
    v432 = qcar(v432);
    v432 = (v432 == nil ? lisp_true : nil);
    goto v161;

v161:
    if (v432 == nil) goto v400;
    v432 = stack[-2];
    fn = elt(env, 8); /* vdpred */
    v432 = (*qfn1(fn))(qenv(fn), v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    stack[-2] = v432;
    v432 = stack[-6];
    qvalue(elt(env, 2)) = v432; /* secondvalue!* */
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v400:
    v81 = stack[-4];
    v432 = stack[-1];
    v432 = qcdr(v432);
    v432 = qcar(v432);
    fn = elt(env, 9); /* vevdif */
    v432 = (*qfn2(fn))(qenv(fn), v81, v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    stack[-7] = v432;
    v432 = stack[-1];
    v432 = qcdr(v432);
    v432 = qcdr(v432);
    v432 = qcar(v432);
    stack[-5] = v432;
    v432 = qvalue(elt(env, 3)); /* !*groebdivide */
    if (v432 == nil) goto v199;
    v81 = stack[-3];
    v432 = stack[-5];
    fn = elt(env, 10); /* vbcgcd */
    v432 = (*qfn2(fn))(qenv(fn), v81, v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    goto v223;

v223:
    stack[-4] = v432;
    v81 = stack[-5];
    v432 = stack[-4];
    fn = elt(env, 11); /* vbcquot */
    v432 = (*qfn2(fn))(qenv(fn), v81, v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    stack[-5] = v432;
    v81 = stack[-3];
    v432 = stack[-4];
    fn = elt(env, 11); /* vbcquot */
    v432 = (*qfn2(fn))(qenv(fn), v81, v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    stack[-4] = v432;
    v432 = stack[-6];
    if (v432 == nil) goto v90;
    v432 = stack[-6];
    if (v432 == nil) goto v389;
    v432 = stack[-6];
    v432 = qcdr(v432);
    v432 = qcdr(v432);
    v432 = qcdr(v432);
    v432 = qcar(v432);
    v432 = (v432 == nil ? lisp_true : nil);
    goto v73;

v73:
    if (!(v432 == nil)) goto v90;
    v81 = stack[-6];
    v432 = stack[-5];
    fn = elt(env, 12); /* vdpvbcprod */
    v432 = (*qfn2(fn))(qenv(fn), v81, v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    stack[-6] = v432;
    goto v90;

v90:
    v432 = qvalue(elt(env, 4)); /* !*groebprot */
    if (v432 == nil) goto v385;
    stack[-3] = stack[-5];
    v432 = stack[-4];
    fn = elt(env, 13); /* vbcneg */
    v433 = (*qfn1(fn))(qenv(fn), v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    v81 = stack[-7];
    v432 = stack[-1];
    fn = elt(env, 14); /* groebreductionprotocol */
    v432 = (*qfnn(fn))(qenv(fn), 4, stack[-3], v433, v81, v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    goto v385;

v385:
    v432 = stack[-2];
    fn = elt(env, 8); /* vdpred */
    stack[-3] = (*qfn1(fn))(qenv(fn), v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    stack[-2] = stack[-5];
    v81 = qvalue(elt(env, 5)); /* vdpvars!* */
    v432 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 15); /* vevmaptozero1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v81, v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    v432 = stack[-4];
    fn = elt(env, 13); /* vbcneg */
    v81 = (*qfn1(fn))(qenv(fn), v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    v432 = stack[-7];
    fn = elt(env, 16); /* vdpilcomb1 */
    v432 = (*qfnn(fn))(qenv(fn), 6, stack[-3], stack[-2], stack[-1], stack[0], v81, v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    stack[-2] = v432;
    v432 = stack[-6];
    qvalue(elt(env, 2)) = v432; /* secondvalue!* */
    v432 = stack[-5];
    qvalue(elt(env, 7)) = v432; /* thirdvalue!* */
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v389:
    v432 = qvalue(elt(env, 1)); /* t */
    goto v73;

v199:
    v432 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* vbcfi */
    v432 = (*qfn1(fn))(qenv(fn), v432);
    nil = C_nil;
    if (exception_pending()) goto v384;
    env = stack[-8];
    goto v223;

v411:
    v432 = qvalue(elt(env, 1)); /* t */
    goto v161;
/* error exit handlers */
v384:
    popv(9);
    return nil;
}



/* Code for find_triangle_coeff */

static Lisp_Object MS_CDECL CC_find_triangle_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v132, Lisp_Object v8, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v408;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "find_triangle_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_triangle_coeff");
#endif
    if (stack >= stacklimit)
    {
        push4(v8,v132,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v132,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v8;
    stack[0] = v132;
    stack[-1] = v1;
    stack[-4] = v0;
/* end of prologue */

v434:
    v224 = stack[-4];
    if (v224 == nil) goto v109;
    v224 = stack[-4];
    v408 = qcar(v224);
    v224 = stack[0];
    fn = elt(env, 1); /* find_triangles1 */
    v224 = (*qfn2(fn))(qenv(fn), v408, v224);
    nil = C_nil;
    if (exception_pending()) goto v431;
    env = stack[-5];
    stack[-2] = v224;
    v224 = stack[-4];
    stack[-4] = qcdr(v224);
    v224 = stack[-2];
    v408 = qcdr(v224);
    v224 = stack[-1];
    stack[-1] = cons(v408, v224);
    nil = C_nil;
    if (exception_pending()) goto v431;
    env = stack[-5];
    v224 = stack[-2];
    v224 = qcar(v224);
    if (v224 == nil) goto v223;
    v224 = stack[-2];
    v408 = qcar(v224);
    v224 = stack[-3];
    v224 = cons(v408, v224);
    nil = C_nil;
    if (exception_pending()) goto v431;
    env = stack[-5];
    goto v171;

v171:
    stack[-3] = v224;
    goto v434;

v223:
    v224 = stack[-3];
    goto v171;

v109:
    v408 = stack[-3];
    v224 = stack[-1];
    popv(6);
    return cons(v408, v224);
/* error exit handlers */
v431:
    popv(6);
    return nil;
}



/* Code for newbasis */

static Lisp_Object CC_newbasis(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v132)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v390, v111, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newbasis");
#endif
    if (stack >= stacklimit)
    {
        push2(v132,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v132);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v132;
    v390 = v1;
/* end of prologue */
    stack[-5] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v390; /* gg */
    stack[-2] = nil;
    v390 = qvalue(elt(env, 1)); /* gg */
    v390 = Lreverse(nil, v390);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[-3] = v390;
    goto v172;

v172:
    v390 = stack[-3];
    if (v390 == nil) goto v198;
    stack[-1] = qvalue(elt(env, 3)); /* gv */
    v390 = stack[-3];
    v390 = qcar(v390);
    stack[0] = qcar(v390);
    v111 = qvalue(elt(env, 3)); /* gv */
    v390 = stack[-3];
    v390 = qcar(v390);
    v390 = qcar(v390);
    v144 = *(Lisp_Object *)((char *)v111 + (CELL-TAG_VECTOR) + ((int32_t)v390/(16/CELL)));
    v111 = stack[-2];
    v390 = stack[-4];
    fn = elt(env, 4); /* nf */
    v390 = (*qfnn(fn))(qenv(fn), 3, v144, v111, v390);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v390;
    v390 = stack[-3];
    v111 = qcar(v390);
    v390 = stack[-2];
    v390 = cons(v111, v390);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[-2] = v390;
    v390 = stack[-3];
    v390 = qcdr(v390);
    stack[-3] = v390;
    goto v172;

v198:
    v390 = nil;
    qvalue(elt(env, 1)) = stack[-5]; /* gg */
    { popv(7); return onevalue(v390); }
/* error exit handlers */
v93:
    env = stack[-6];
    qvalue(elt(env, 1)) = stack[-5]; /* gg */
    popv(7);
    return nil;
}



setup_type const u51_setup[] =
{
    {"radf",                    too_few_2,      CC_radf,       wrong_no_2},
    {"update_kc_list",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_update_kc_list},
    {"multtaylorsq",            too_few_2,      CC_multtaylorsq,wrong_no_2},
    {"same+dim+squared+p",      too_few_2,      CC_sameLdimLsquaredLp,wrong_no_2},
    {"kern-list",               too_few_2,      CC_kernKlist,  wrong_no_2},
    {"aex_mvar",                CC_aex_mvar,    too_many_1,    wrong_no_1},
    {"math_ml_printer",         too_few_2,      CC_math_ml_printer,wrong_no_2},
    {"mappend",                 too_few_2,      CC_mappend,    wrong_no_2},
    {"gbfmult",                 too_few_2,      CC_gbfmult,    wrong_no_2},
    {"randpoly",                CC_randpoly,    too_many_1,    wrong_no_1},
    {"lambda_lqgaw0_11",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_lambda_lqgaw0_11},
    {"positive-rounded-float",  CC_positiveKroundedKfloat,too_many_1,wrong_no_1},
    {"symmetrize-inds",         too_few_2,      CC_symmetrizeKinds,wrong_no_2},
    {"mod-dump1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_modKdump1},
    {"force-lc",                too_few_2,      CC_forceKlc,   wrong_no_2},
    {"compactf0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf0},
    {"lf=tovarlessp",           too_few_2,      CC_lfMtovarlessp,wrong_no_2},
    {"lexorder",                CC_lexorder,    too_many_1,    wrong_no_1},
    {"pa_vect2list",            CC_pa_vect2list,too_many_1,    wrong_no_1},
    {"repr_ldeg",               CC_repr_ldeg,   too_many_1,    wrong_no_1},
    {"aex_rem",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_rem},
    {"setspmatelem2",           too_few_2,      CC_setspmatelem2,wrong_no_2},
    {"exptchk0",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_exptchk0},
    {"multsm",                  too_few_2,      CC_multsm,     wrong_no_2},
    {"groeblistadd",            too_few_2,      CC_groeblistadd,wrong_no_2},
    {"groebreduceonestepint",   wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebreduceonestepint},
    {"find_triangle_coeff",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_triangle_coeff},
    {"newbasis",                too_few_2,      CC_newbasis,   wrong_no_2},
    {NULL, (one_args *)"u51", (two_args *)"16571 9591686 4827289", 0}
};

/* end of generated code */
