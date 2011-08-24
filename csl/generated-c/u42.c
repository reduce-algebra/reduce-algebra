
/* $destdir\u42.c        Machine generated C code */

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


/* Code for preproc1 */

static Lisp_Object CC_preproc1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v108, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preproc1");
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

v110:
    v107 = stack[-1];
    if (!consp(v107)) goto v111;
    v107 = stack[-1];
    v108 = qcar(v107);
    v107 = elt(env, 1); /* !:rd!: */
    if (v108 == v107) goto v112;
    v107 = stack[-1];
    v108 = qcar(v107);
    v107 = elt(env, 2); /* !:dn!: */
    if (v108 == v107) goto v113;
    v107 = stack[-1];
    v108 = qcar(v107);
    v107 = elt(env, 3); /* !*sq */
    if (v108 == v107) goto v114;
    v107 = stack[-1];
    v108 = qcar(v107);
    v107 = elt(env, 5); /* procedure */
    if (v108 == v107) goto v115;
    v107 = stack[-1];
    v108 = qcar(v107);
    v107 = elt(env, 11); /* declare */
    if (v108 == v107) goto v116;
    v107 = stack[-1];
    v108 = qcar(v107);
    v107 = elt(env, 14); /* setq */
    if (v108 == v107) goto v117;
    v107 = qvalue(elt(env, 9)); /* nil */
    goto v118;

v118:
    if (v107 == nil) goto v119;
    v107 = stack[-1];
    {
        popv(6);
        fn = elt(env, 21); /* migrate!-setqs */
        return (*qfn1(fn))(qenv(fn), v107);
    }

v119:
    v107 = stack[-1];
    v108 = qcar(v107);
    v107 = elt(env, 16); /* (plus times difference quotient minus) */
    v107 = Lmemq(nil, v108, v107);
    if (v107 == nil) goto v120;
    v107 = stack[-1];
    fn = elt(env, 22); /* simp!* */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v109 = v107;
    v107 = qcar(v107);
    v107 = Lconsp(nil, v107);
    env = stack[-5];
    if (v107 == nil) goto v122;
    v107 = v109;
    v107 = qcar(v107);
    v108 = qcar(v107);
    v107 = elt(env, 17); /* (!:cr!: !:crn!: !:gi!:) */
    v107 = Lmemq(nil, v108, v107);
    if (v107 == nil) goto v122;
    v107 = v109;
    v107 = qcdr(v107);
    v107 = Lonep(nil, v107);
    env = stack[-5];
    if (v107 == nil) goto v123;
    v107 = v109;
    v107 = qcar(v107);
    popv(6);
    return ncons(v107);

v123:
    stack[-1] = elt(env, 18); /* quotient */
    v107 = v109;
    stack[0] = qcar(v107);
    v107 = v109;
    v108 = qcdr(v107);
    v107 = (Lisp_Object)17; /* 1 */
    v107 = cons(v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v108 = v107;
    v107 = v108;
    v107 = qcar(v107);
    if (v107 == nil) goto v124;
    v107 = elt(env, 4); /* prepf */
    fn = elt(env, 23); /* sqform */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    goto v125;

v125:
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = qcar(v107);
    v107 = list3(stack[-1], stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    popv(6);
    return ncons(v107);

v124:
    v107 = (Lisp_Object)1; /* 0 */
    goto v125;

v122:
    v107 = stack[-1];
    stack[-3] = v107;
    goto v126;

v126:
    v107 = stack[-3];
    if (v107 == nil) goto v127;
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-2] = v107;
    v107 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-1];
    if (!consp(v107)) goto v126;
    else goto v128;

v128:
    v107 = stack[-3];
    if (v107 == nil) goto v129;
    stack[0] = stack[-1];
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    goto v128;

v129:
    v107 = stack[-2];
    goto v130;

v130:
    popv(6);
    return ncons(v107);

v127:
    v107 = qvalue(elt(env, 9)); /* nil */
    goto v130;

v120:
    v107 = qvalue(elt(env, 7)); /* !*getdecs */
    if (v107 == nil) goto v131;
    v107 = stack[-1];
    v108 = qcar(v107);
    v107 = elt(env, 19); /* (!~for for) */
    v107 = Lmemq(nil, v108, v107);
    if (v107 == nil) goto v131;
    v109 = qvalue(elt(env, 9)); /* nil */
    v107 = stack[-1];
    v107 = qcdr(v107);
    v108 = qcar(v107);
    v107 = elt(env, 20); /* (integer) */
    fn = elt(env, 25); /* symtabput */
    v107 = (*qfnn(fn))(qenv(fn), 3, v109, v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    goto v131;

v131:
    v107 = stack[-1];
    stack[-3] = v107;
    goto v132;

v132:
    v107 = stack[-3];
    if (v107 == nil) goto v133;
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-2] = v107;
    v107 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-1];
    if (!consp(v107)) goto v132;
    else goto v134;

v134:
    v107 = stack[-3];
    if (v107 == nil) goto v135;
    stack[0] = stack[-1];
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    goto v134;

v135:
    v107 = stack[-2];
    goto v136;

v136:
    popv(6);
    return ncons(v107);

v133:
    v107 = qvalue(elt(env, 9)); /* nil */
    goto v136;

v117:
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    v107 = Lconsp(nil, v107);
    env = stack[-5];
    if (v107 == nil) goto v137;
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    v108 = qcar(v107);
    v107 = elt(env, 15); /* (cond progn) */
    v107 = Lmemq(nil, v108, v107);
    goto v118;

v137:
    v107 = qvalue(elt(env, 9)); /* nil */
    goto v118;

v116:
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = qcar(v107);
    stack[-1] = v107;
    v107 = stack[-1];
    fn = elt(env, 26); /* preprocdec */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    v107 = stack[-1];
    stack[-4] = v107;
    goto v138;

v138:
    v107 = stack[-4];
    if (v107 == nil) goto v139;
    v107 = stack[-4];
    v107 = qcar(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-2] = v107;
    goto v140;

v140:
    v107 = stack[-2];
    if (v107 == nil) goto v141;
    v107 = stack[-2];
    v107 = qcar(v107);
    v109 = v107;
    v107 = stack[-3];
    v108 = qcar(v107);
    v107 = elt(env, 12); /* (subroutine function) */
    v107 = Lmemq(nil, v108, v107);
    if (v107 == nil) goto v142;
    v108 = elt(env, 13); /* !*type!* */
    v107 = stack[-3];
    v107 = qcar(v107);
    fn = elt(env, 25); /* symtabput */
    v107 = (*qfnn(fn))(qenv(fn), 3, v109, v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    goto v143;

v143:
    v107 = stack[-2];
    v107 = qcdr(v107);
    stack[-2] = v107;
    goto v140;

v142:
    stack[-1] = qvalue(elt(env, 9)); /* nil */
    v107 = v109;
    if (!consp(v107)) goto v144;
    v107 = v109;
    v107 = qcar(v107);
    stack[0] = v107;
    goto v145;

v145:
    v107 = v109;
    if (!consp(v107)) goto v146;
    v107 = stack[-3];
    v107 = qcar(v107);
    v108 = v109;
    v108 = qcdr(v108);
    v107 = cons(v107, v108);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    goto v147;

v147:
    fn = elt(env, 25); /* symtabput */
    v107 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    goto v143;

v146:
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    goto v147;

v144:
    v107 = v109;
    stack[0] = v107;
    goto v145;

v141:
    v107 = stack[-4];
    v107 = qcdr(v107);
    stack[-4] = v107;
    goto v138;

v139:
    v107 = qvalue(elt(env, 9)); /* nil */
    { popv(6); return onevalue(v107); }

v115:
    v107 = stack[-1];
    v107 = qcdr(v107);
    v109 = qcar(v107);
    v108 = elt(env, 6); /* !*params!* */
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    fn = elt(env, 25); /* symtabput */
    v107 = (*qfnn(fn))(qenv(fn), 3, v109, v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = qvalue(elt(env, 7)); /* !*getdecs */
    if (v107 == nil) goto v148;
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v108 = qcar(v107);
    v107 = elt(env, 8); /* (real integer) */
    v107 = Lmemq(nil, v108, v107);
    if (v107 == nil) goto v149;
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-2] = qcar(v107);
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[0] = qcar(v107);
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    fn = elt(env, 25); /* symtabput */
    v107 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    stack[-3] = v107;
    goto v150;

v150:
    v107 = stack[-3];
    if (v107 == nil) goto v151;
    v107 = stack[-3];
    v107 = qcar(v107);
    v108 = v107;
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-2] = qcar(v107);
    stack[0] = v108;
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    fn = elt(env, 25); /* symtabput */
    v107 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    goto v150;

v151:
    v109 = elt(env, 5); /* procedure */
    v107 = stack[-1];
    v107 = qcdr(v107);
    v108 = qcar(v107);
    v107 = nil;
    stack[-4] = list3(v109, v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    stack[-3] = v107;
    goto v152;

v152:
    v107 = stack[-3];
    if (v107 == nil) goto v153;
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-2] = v107;
    v107 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-1];
    if (!consp(v107)) goto v152;
    else goto v154;

v154:
    v107 = stack[-3];
    if (v107 == nil) goto v155;
    stack[0] = stack[-1];
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    goto v154;

v155:
    v107 = stack[-2];
    goto v156;

v156:
    v107 = Lnconc(nil, stack[-4], v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    popv(6);
    return ncons(v107);

v153:
    v107 = qvalue(elt(env, 9)); /* nil */
    goto v156;

v149:
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    stack[-3] = v107;
    goto v157;

v157:
    v107 = stack[-3];
    if (v107 == nil) goto v158;
    v107 = stack[-3];
    v107 = qcar(v107);
    v108 = v107;
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-2] = qcar(v107);
    stack[0] = v108;
    v107 = qvalue(elt(env, 10)); /* deftype!* */
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    fn = elt(env, 25); /* symtabput */
    v107 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    goto v157;

v158:
    v107 = stack[-1];
    stack[-3] = v107;
    goto v159;

v159:
    v107 = stack[-3];
    if (v107 == nil) goto v160;
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-2] = v107;
    v107 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-1];
    if (!consp(v107)) goto v159;
    else goto v161;

v161:
    v107 = stack[-3];
    if (v107 == nil) goto v162;
    stack[0] = stack[-1];
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    goto v161;

v162:
    v107 = stack[-2];
    goto v163;

v163:
    popv(6);
    return ncons(v107);

v160:
    v107 = qvalue(elt(env, 9)); /* nil */
    goto v163;

v148:
    v107 = stack[-1];
    stack[-3] = v107;
    goto v164;

v164:
    v107 = stack[-3];
    if (v107 == nil) goto v165;
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-2] = v107;
    v107 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-1];
    if (!consp(v107)) goto v164;
    else goto v166;

v166:
    v107 = stack[-3];
    if (v107 == nil) goto v167;
    stack[0] = stack[-1];
    v107 = stack[-3];
    v107 = qcar(v107);
    v107 = CC_preproc1(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    v107 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    goto v166;

v167:
    v107 = stack[-2];
    goto v168;

v168:
    popv(6);
    return ncons(v107);

v165:
    v107 = qvalue(elt(env, 9)); /* nil */
    goto v168;

v114:
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcar(v107);
    v107 = qcar(v107);
    if (v107 == nil) goto v169;
    v107 = stack[-1];
    v107 = qcdr(v107);
    v108 = qcar(v107);
    v107 = elt(env, 4); /* prepf */
    fn = elt(env, 23); /* sqform */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    goto v170;

v170:
    stack[-1] = v107;
    goto v110;

v169:
    v107 = (Lisp_Object)1; /* 0 */
    goto v170;

v113:
    v107 = stack[-1];
    v107 = qcdr(v107);
    v108 = qcar(v107);
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    fn = elt(env, 27); /* decimal2internal */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-1] = v107;
    goto v110;

v112:
    v107 = stack[-1];
    v107 = qcdr(v107);
    if (!consp(v107)) goto v171;
    v107 = stack[-1];
    goto v172;

v172:
    popv(6);
    return ncons(v107);

v171:
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = Lfloatp(nil, v107);
    env = stack[-5];
    if (v107 == nil) goto v173;
    v107 = stack[-1];
    v107 = qcdr(v107);
    fn = elt(env, 28); /* fl2bf */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    goto v172;

v173:
    v107 = stack[-1];
    v107 = qcdr(v107);
    if (!consp(v107)) goto v174;
    v107 = stack[-1];
    v107 = qcdr(v107);
    goto v175;

v175:
    fn = elt(env, 29); /* csl_normbf */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    goto v172;

v174:
    v107 = stack[-1];
    v107 = qcdr(v107);
    v107 = integerp(v107);
    if (v107 == nil) goto v176;
    v109 = elt(env, 1); /* !:rd!: */
    v107 = stack[-1];
    v108 = qcdr(v107);
    v107 = (Lisp_Object)1; /* 0 */
    v107 = list2star(v109, v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    goto v175;

v176:
    v107 = stack[-1];
    v107 = qcdr(v107);
    fn = elt(env, 30); /* read!:num */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    goto v175;

v111:
    v107 = stack[-1];
    popv(6);
    return ncons(v107);
/* error exit handlers */
v121:
    popv(6);
    return nil;
}



/* Code for mk_simpl_map_ */

static Lisp_Object CC_mk_simpl_map_(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_simpl_map_");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v179 = v0;
/* end of prologue */
    v180 = v179;
    v179 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* mk_simpl_map_1 */
        return (*qfn2(fn))(qenv(fn), v180, v179);
    }
}



/* Code for red_prepare */

static Lisp_Object CC_red_prepare(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_prepare");
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
    v172 = stack[-1];
    fn = elt(env, 1); /* bas_nr */
    stack[-2] = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v172 = stack[-1];
    fn = elt(env, 2); /* bas_dpoly */
    stack[0] = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v172 = stack[-1];
    fn = elt(env, 3); /* bas_rep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v172 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 4); /* dp_from_ei */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    fn = elt(env, 5); /* dp_sum */
    v172 = (*qfn2(fn))(qenv(fn), stack[-1], v172);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    {
        Lisp_Object v184 = stack[-2];
        Lisp_Object v185 = stack[0];
        popv(4);
        fn = elt(env, 6); /* bas_make1 */
        return (*qfnn(fn))(qenv(fn), 3, v184, v185, v172);
    }
/* error exit handlers */
v183:
    popv(4);
    return nil;
}



/* Code for dv_skel2factor */

static Lisp_Object CC_dv_skel2factor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skel2factor");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v197 = v186;
    stack[-4] = v0;
/* end of prologue */
    v196 = stack[-4];
    v196 = qcdr(v196);
    if (v196 == nil) goto v178;
    v196 = stack[-4];
    v196 = qcdr(v196);
    v196 = Lsublis(nil, v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-6];
    stack[-5] = v196;
    v196 = stack[-5];
    fn = elt(env, 2); /* st_ad_numsorttree */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-6];
    stack[-5] = v196;
    v196 = stack[-5];
    v196 = qcdr(v196);
    fn = elt(env, 3); /* st_flatten */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-6];
    stack[-3] = v196;
    v196 = stack[-3];
    if (v196 == nil) goto v199;
    v196 = stack[-3];
    v196 = qcar(v196);
    fn = elt(env, 4); /* dv_ind2var */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-6];
    v196 = ncons(v196);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-6];
    stack[-1] = v196;
    stack[-2] = v196;
    goto v200;

v200:
    v196 = stack[-3];
    v196 = qcdr(v196);
    stack[-3] = v196;
    v196 = stack[-3];
    if (v196 == nil) goto v201;
    stack[0] = stack[-1];
    v196 = stack[-3];
    v196 = qcar(v196);
    fn = elt(env, 4); /* dv_ind2var */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-6];
    v196 = ncons(v196);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-6];
    v196 = Lrplacd(nil, stack[0], v196);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-6];
    v196 = stack[-1];
    v196 = qcdr(v196);
    stack[-1] = v196;
    goto v200;

v201:
    v196 = stack[-2];
    goto v202;

v202:
    v197 = stack[-5];
    stack[0] = qcar(v197);
    v197 = stack[-4];
    v197 = qcar(v197);
    fn = elt(env, 5); /* dv_skel2factor1 */
    v196 = (*qfn2(fn))(qenv(fn), v197, v196);
    nil = C_nil;
    if (exception_pending()) goto v198;
    {
        Lisp_Object v97 = stack[0];
        popv(7);
        return cons(v97, v196);
    }

v199:
    v196 = qvalue(elt(env, 1)); /* nil */
    goto v202;

v178:
    v196 = stack[-4];
    v196 = qcar(v196);
    { popv(7); return onevalue(v196); }
/* error exit handlers */
v198:
    popv(7);
    return nil;
}



/* Code for derivative!-mod!-p */

static Lisp_Object CC_derivativeKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v205, v206, v207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for derivative-mod-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v207 = v0;
/* end of prologue */
    v205 = v207;
    if (!consp(v205)) goto v177;
    v205 = v207;
    v205 = qcar(v205);
    v205 = (consp(v205) ? nil : lisp_true);
    goto v111;

v111:
    if (v205 == nil) goto v105;
    v205 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v205);

v105:
    v205 = v207;
    v205 = qcar(v205);
    v205 = qcar(v205);
    v206 = qcdr(v205);
    v205 = (Lisp_Object)17; /* 1 */
    if (v206 == v205) goto v208;
    v205 = v207;
    v206 = v207;
    v206 = qcar(v206);
    v206 = qcar(v206);
    v206 = qcar(v206);
    {
        fn = elt(env, 3); /* derivative!-mod!-p!-1 */
        return (*qfn2(fn))(qenv(fn), v205, v206);
    }

v208:
    v205 = v207;
    v205 = qcar(v205);
    v205 = qcdr(v205);
    return onevalue(v205);

v177:
    v205 = qvalue(elt(env, 1)); /* t */
    goto v111;
}



/* Code for linineqevaltest */

static Lisp_Object CC_linineqevaltest(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v187, v215, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for linineqevaltest");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v187 = v186;
    v215 = v0;
/* end of prologue */

v204:
    v188 = v215;
    if (!consp(v188)) goto v217;
    v188 = v215;
    v188 = qcar(v188);
    v188 = (consp(v188) ? nil : lisp_true);
    goto v112;

v112:
    if (!(v188 == nil)) { popv(2); return onevalue(v187); }
    v188 = v215;
    v188 = qcar(v188);
    v188 = qcar(v188);
    v216 = qcdr(v188);
    v188 = (Lisp_Object)17; /* 1 */
    if (v216 == v188) goto v207;
    v188 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v188; /* !*ineqerr */
    v188 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v188 == nil)) goto v173;
    v188 = elt(env, 4); /* "unable to process nonlinear system" */
    fn = elt(env, 5); /* lprie */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-1];
    goto v173;

v173:
    v188 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v218;
    v188 = nil;
    { popv(2); return onevalue(v188); }

v207:
    v188 = v215;
    v188 = qcar(v188);
    v188 = qcar(v188);
    v216 = qcar(v188);
    v188 = v187;
    v188 = Lmember(nil, v216, v188);
    if (v188 == nil) goto v191;
    v188 = v215;
    v188 = qcdr(v188);
    v215 = v188;
    goto v204;

v191:
    v188 = v215;
    v188 = qcdr(v188);
    stack[0] = v188;
    v188 = v215;
    v188 = qcar(v188);
    v188 = qcar(v188);
    v188 = qcar(v188);
    v188 = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-1];
    v187 = v188;
    v188 = stack[0];
    v215 = v188;
    goto v204;

v217:
    v188 = qvalue(elt(env, 1)); /* t */
    goto v112;
/* error exit handlers */
v218:
    popv(2);
    return nil;
}



/* Code for ordered!-gcd!-mod!-p */

static Lisp_Object CC_orderedKgcdKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordered-gcd-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v186;
    stack[-1] = v0;
/* end of prologue */
    v216 = (Lisp_Object)1; /* 0 */
    stack[-2] = v216;
    goto v178;

v178:
    v222 = stack[-1];
    v216 = stack[0];
    fn = elt(env, 3); /* reduce!-degree!-mod!-p */
    v216 = (*qfn2(fn))(qenv(fn), v222, v216);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[-1] = v216;
    v216 = stack[-1];
    if (v216 == nil) goto v208;
    v216 = stack[-2];
    v216 = add1(v216);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[-2] = v216;
    v216 = stack[-1];
    if (!consp(v216)) goto v200;
    v216 = stack[-1];
    v216 = qcar(v216);
    v216 = (consp(v216) ? nil : lisp_true);
    goto v185;

v185:
    if (v216 == nil) goto v223;
    v222 = qvalue(elt(env, 2)); /* reduction!-count */
    v216 = stack[-2];
    v216 = plus2(v222, v216);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    qvalue(elt(env, 2)) = v216; /* reduction!-count */
    v216 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v216); }

v223:
    v216 = stack[-1];
    v216 = qcar(v216);
    v216 = qcar(v216);
    v222 = qcdr(v216);
    v216 = stack[0];
    v216 = qcar(v216);
    v216 = qcar(v216);
    v216 = qcdr(v216);
    v216 = (Lisp_Object)lessp2(v222, v216);
    nil = C_nil;
    if (exception_pending()) goto v189;
    v216 = v216 ? lisp_true : nil;
    env = stack[-3];
    if (v216 == nil) goto v178;
    v222 = qvalue(elt(env, 2)); /* reduction!-count */
    v216 = stack[-2];
    v216 = plus2(v222, v216);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    qvalue(elt(env, 2)) = v216; /* reduction!-count */
    v216 = (Lisp_Object)1; /* 0 */
    stack[-2] = v216;
    v216 = stack[-1];
    v222 = v216;
    v216 = stack[0];
    stack[-1] = v216;
    v216 = v222;
    stack[0] = v216;
    goto v178;

v200:
    v216 = qvalue(elt(env, 1)); /* t */
    goto v185;

v208:
    v216 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* monic!-mod!-p */
        return (*qfn1(fn))(qenv(fn), v216);
    }
/* error exit handlers */
v189:
    popv(4);
    return nil;
}



/* Code for polynomreduceby */

static Lisp_Object CC_polynomreduceby(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomreduceby");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v186;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v179;

v179:
    v218 = stack[-3];
    if (v218 == nil) goto v112;
    v218 = qvalue(elt(env, 3)); /* fluidbibasisreductionsmade */
    v218 = (Lisp_Object)((int32_t)(v218) + 0x10);
    qvalue(elt(env, 3)) = v218; /* fluidbibasisreductionsmade */
    v218 = nil;
    { popv(5); return onevalue(v218); }

v112:
    v218 = stack[-2];
    stack[0] = v218;
    goto v105;

v105:
    v218 = stack[0];
    v218 = qcar(v218);
    if (v218 == nil) goto v230;
    v218 = stack[0];
    v99 = qcar(v218);
    v218 = stack[-1];
    v218 = qcar(v218);
    fn = elt(env, 4); /* monomisdivisibleby */
    v218 = (*qfn2(fn))(qenv(fn), v99, v218);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    if (!(v218 == nil)) goto v230;
    v218 = stack[0];
    v218 = qcdr(v218);
    stack[0] = v218;
    goto v105;

v230:
    v218 = stack[0];
    v218 = qcar(v218);
    if (v218 == nil) goto v174;
    v218 = stack[0];
    v99 = qcar(v218);
    v218 = stack[-1];
    v218 = qcar(v218);
    fn = elt(env, 5); /* monomdivide */
    v218 = (*qfn2(fn))(qenv(fn), v99, v218);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[0] = stack[-2];
    v99 = stack[-1];
    fn = elt(env, 6); /* polynommultiplybymonom */
    v218 = (*qfn2(fn))(qenv(fn), v99, v218);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    fn = elt(env, 7); /* polynomadd */
    v218 = (*qfn2(fn))(qenv(fn), stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    goto v179;

v174:
    v218 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v218;
    goto v179;
/* error exit handlers */
v197:
    popv(5);
    return nil;
}



/* Code for qqe_dfs */

static Lisp_Object CC_qqe_dfs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v222, v218;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_dfs");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v186;
    v218 = v0;
/* end of prologue */
    v222 = qvalue(elt(env, 1)); /* t */
    stack[0] = v222;
    v222 = v218;
    if (!consp(v222)) goto v230;
    v222 = v218;
    stack[-2] = v222;
    goto v232;

v232:
    v222 = stack[-2];
    if (v222 == nil) goto v200;
    v222 = stack[0];
    if (v222 == nil) goto v200;
    v222 = stack[-2];
    v218 = qcar(v222);
    v222 = stack[-1];
    if (!(v218 == v222)) goto v219;
    v222 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v222;
    goto v219;

v219:
    v222 = stack[-2];
    v218 = qcar(v222);
    v222 = stack[-1];
    v222 = CC_qqe_dfs(env, v218, v222);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    if (v222 == nil) goto v211;
    v222 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v222;
    goto v211;

v211:
    v222 = stack[-2];
    v222 = qcdr(v222);
    stack[-2] = v222;
    goto v232;

v200:
    v222 = stack[0];
    if (v222 == nil) goto v187;
    v222 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v222); }

v187:
    v222 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v222); }

v230:
    v222 = stack[-1];
    if (v218 == v222) goto v221;
    v222 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v222); }

v221:
    v222 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v222); }
/* error exit handlers */
v113:
    popv(4);
    return nil;
}



/* Code for factor!-prim!-f */

static Lisp_Object CC_factorKprimKf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v258, v156, v259;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factor-prim-f");
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
    stack[-1] = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v258 = qvalue(elt(env, 1)); /* ncmp!* */
    if (v258 == nil) goto v178;
    stack[0] = (Lisp_Object)17; /* 1 */
    v156 = stack[-1];
    v258 = (Lisp_Object)17; /* 1 */
    v258 = cons(v156, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    {
        Lisp_Object v261 = stack[0];
        popv(5);
        return list2(v261, v258);
    }

v178:
    v258 = qvalue(elt(env, 2)); /* dmode!* */
    if (v258 == nil) goto v216;
    v156 = qvalue(elt(env, 2)); /* dmode!* */
    v258 = elt(env, 3); /* sqfrfactorfn */
    v258 = get(v156, v258);
    env = stack[-4];
    stack[-2] = v258;
    if (v258 == nil) goto v216;
    v258 = qvalue(elt(env, 4)); /* !*factor */
    if (v258 == nil) goto v262;
    v156 = stack[-2];
    v258 = stack[-1];
    v258 = Lapply1(nil, v156, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[0] = v258;
    goto v184;

v184:
    v258 = stack[-2];
    if (v258 == nil) goto v263;
    v259 = stack[-2];
    v156 = qvalue(elt(env, 2)); /* dmode!* */
    v258 = elt(env, 8); /* factorfn */
    v258 = get(v156, v258);
    env = stack[-4];
    if (v259 == v258) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    else goto v263;

v263:
    v258 = stack[0];
    v258 = qcar(v258);
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[-3] = v258;
    v258 = stack[0];
    v258 = qcdr(v258);
    stack[-2] = v258;
    goto v264;

v264:
    v258 = stack[-2];
    if (v258 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v258 = stack[-2];
    v258 = qcar(v258);
    fn = elt(env, 9); /* factor!-prim!-sqfree!-f */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[-1] = v258;
    v258 = stack[-1];
    v156 = qcar(v258);
    v258 = stack[-3];
    v258 = qcar(v258);
    fn = elt(env, 10); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v156, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v258 = stack[-1];
    v156 = qcdr(v258);
    v258 = stack[-3];
    v258 = qcdr(v258);
    v258 = Lappend(nil, v156, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v258 = cons(stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[-3] = v258;
    v258 = stack[-2];
    v258 = qcdr(v258);
    stack[-2] = v258;
    goto v264;

v262:
    stack[0] = (Lisp_Object)17; /* 1 */
    v156 = stack[-1];
    v258 = (Lisp_Object)17; /* 1 */
    v258 = cons(v156, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v258 = list2(stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[0] = v258;
    goto v184;

v216:
    v156 = qvalue(elt(env, 2)); /* dmode!* */
    v258 = elt(env, 5); /* field */
    v258 = Lflagp(nil, v156, v258);
    env = stack[-4];
    if (v258 == nil) goto v97;
    v258 = stack[-1];
    fn = elt(env, 11); /* lnc */
    v156 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[-3] = v156;
    v258 = (Lisp_Object)17; /* 1 */
    v258 = Lneq(nil, v156, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    goto v226;

v226:
    if (v258 == nil) goto v265;
    stack[0] = stack[-3];
    v258 = stack[-3];
    fn = elt(env, 12); /* !:recip */
    v156 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v258 = stack[-1];
    fn = elt(env, 13); /* multd */
    v258 = (*qfn2(fn))(qenv(fn), v156, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    fn = elt(env, 14); /* sqfrf */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v258 = cons(stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[0] = v258;
    goto v184;

v265:
    v156 = qvalue(elt(env, 2)); /* dmode!* */
    v258 = elt(env, 7); /* units */
    v258 = get(v156, v258);
    env = stack[-4];
    stack[-3] = v258;
    if (v258 == nil) goto v266;
    v258 = stack[-1];
    fn = elt(env, 11); /* lnc */
    v156 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v259 = v156;
    v258 = stack[-3];
    v258 = Lassoc(nil, v156, v258);
    stack[-3] = v258;
    if (v258 == nil) goto v266;
    stack[0] = v259;
    v258 = stack[-3];
    v156 = qcdr(v258);
    v258 = stack[-1];
    fn = elt(env, 13); /* multd */
    v258 = (*qfn2(fn))(qenv(fn), v156, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    fn = elt(env, 14); /* sqfrf */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v258 = cons(stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[0] = v258;
    goto v184;

v266:
    stack[0] = (Lisp_Object)17; /* 1 */
    v258 = stack[-1];
    fn = elt(env, 14); /* sqfrf */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    v258 = cons(stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-4];
    stack[0] = v258;
    goto v184;

v97:
    v258 = qvalue(elt(env, 6)); /* nil */
    goto v226;
/* error exit handlers */
v260:
    popv(5);
    return nil;
}



/* Code for vdplsort */

static Lisp_Object CC_vdplsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdplsort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v179 = v0;
/* end of prologue */
    v180 = v179;
    v179 = elt(env, 1); /* vdpvevlcomp */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v180, v179);
    }
}



/* Code for xpartitsq */

static Lisp_Object CC_xpartitsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v284, v81, v285;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpartitsq");
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
    v285 = v0;
/* end of prologue */
    v284 = v285;
    v81 = qcar(v284);
    v284 = v285;
    v284 = qcdr(v284);
    stack[-2] = v81;
    stack[-1] = v284;
    v284 = stack[-2];
    if (v284 == nil) goto v179;
    v284 = stack[-2];
    if (!consp(v284)) goto v208;
    v284 = stack[-2];
    v284 = qcar(v284);
    v284 = (consp(v284) ? nil : lisp_true);
    goto v286;

v286:
    if (v284 == nil) goto v173;
    v284 = (Lisp_Object)17; /* 1 */
    v81 = v285;
    v284 = cons(v284, v81);
    nil = C_nil;
    if (exception_pending()) goto v287;
    popv(4);
    return ncons(v284);

v173:
    v284 = stack[-2];
    v284 = qcar(v284);
    v284 = qcar(v284);
    v284 = qcar(v284);
    if (!consp(v284)) goto v103;
    v284 = stack[-2];
    v284 = qcar(v284);
    v284 = qcar(v284);
    v284 = qcar(v284);
    v284 = qcar(v284);
    v284 = (consp(v284) ? nil : lisp_true);
    v284 = (v284 == nil ? lisp_true : nil);
    goto v288;

v288:
    if (v284 == nil) goto v206;
    v284 = stack[-2];
    v284 = qcar(v284);
    v284 = qcar(v284);
    v81 = qcar(v284);
    v284 = (Lisp_Object)17; /* 1 */
    v284 = cons(v81, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    v81 = CC_xpartitsq(env, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    v284 = stack[-2];
    v284 = qcar(v284);
    v284 = qcar(v284);
    v284 = qcdr(v284);
    fn = elt(env, 3); /* xexptpf */
    stack[0] = (*qfn2(fn))(qenv(fn), v81, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    v284 = stack[-2];
    v284 = qcar(v284);
    v81 = qcdr(v284);
    v284 = stack[-1];
    v284 = cons(v81, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    fn = elt(env, 4); /* cancel */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    v284 = CC_xpartitsq(env, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    fn = elt(env, 5); /* wedgepf */
    v284 = (*qfn2(fn))(qenv(fn), stack[0], v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    stack[0] = v284;
    goto v84;

v84:
    v284 = stack[-2];
    v81 = qcdr(v284);
    v284 = stack[-1];
    v284 = cons(v81, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    v284 = CC_xpartitsq(env, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    {
        Lisp_Object v289 = stack[0];
        popv(4);
        fn = elt(env, 6); /* addpf */
        return (*qfn2(fn))(qenv(fn), v289, v284);
    }

v206:
    v284 = stack[-2];
    v284 = qcar(v284);
    v284 = qcar(v284);
    v284 = qcar(v284);
    fn = elt(env, 7); /* xvarp */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    if (v284 == nil) goto v266;
    v284 = stack[-2];
    v284 = qcar(v284);
    v284 = qcar(v284);
    v284 = qcar(v284);
    fn = elt(env, 8); /* xpartitk */
    v81 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    v284 = stack[-2];
    v284 = qcar(v284);
    v284 = qcar(v284);
    v284 = qcdr(v284);
    fn = elt(env, 3); /* xexptpf */
    stack[0] = (*qfn2(fn))(qenv(fn), v81, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    v284 = stack[-2];
    v284 = qcar(v284);
    v81 = qcdr(v284);
    v284 = stack[-1];
    v284 = cons(v81, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    fn = elt(env, 4); /* cancel */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    v284 = CC_xpartitsq(env, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    fn = elt(env, 5); /* wedgepf */
    v284 = (*qfn2(fn))(qenv(fn), stack[0], v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    stack[0] = v284;
    goto v84;

v266:
    v284 = stack[-2];
    v284 = qcar(v284);
    v81 = qcdr(v284);
    v284 = stack[-1];
    v284 = cons(v81, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    fn = elt(env, 4); /* cancel */
    v284 = (*qfn1(fn))(qenv(fn), v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    stack[0] = CC_xpartitsq(env, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    v284 = stack[-2];
    v284 = qcar(v284);
    v81 = qcar(v284);
    v284 = (Lisp_Object)17; /* 1 */
    v284 = cons(v81, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    v81 = ncons(v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    v284 = (Lisp_Object)17; /* 1 */
    v284 = cons(v81, v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    fn = elt(env, 9); /* multpfsq */
    v284 = (*qfn2(fn))(qenv(fn), stack[0], v284);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-3];
    stack[0] = v284;
    goto v84;

v103:
    v284 = qvalue(elt(env, 1)); /* nil */
    goto v288;

v208:
    v284 = qvalue(elt(env, 2)); /* t */
    goto v286;

v179:
    v284 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v284); }
/* error exit handlers */
v287:
    popv(4);
    return nil;
}



/* Code for latexprin */

static Lisp_Object CC_latexprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v282, v228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for latexprin");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v228 = v0;
/* end of prologue */
    v282 = v228;
    v214 = elt(env, 1); /* tex */
    if (!consp(v282)) goto v194;
    v282 = qcar(v282);
    if (!(v282 == v214)) goto v194;
    v214 = v228;
    v214 = qcdr(v214);
    v282 = qcar(v214);
    v214 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 2); /* maprintla */
        return (*qfn2(fn))(qenv(fn), v282, v214);
    }

v194:
    v282 = v228;
    v214 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 2); /* maprintla */
        return (*qfn2(fn))(qenv(fn), v282, v214);
    }
}



/* Code for chksymmetries!&subst */

static Lisp_Object MS_CDECL CC_chksymmetriesGsubst(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v186,
                         Lisp_Object v239, Lisp_Object v190, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v292, v209, v210, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "chksymmetries&subst");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chksymmetries&subst");
#endif
    if (stack >= stacklimit)
    {
        push4(v190,v239,v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v186,v239,v190);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v190;
    stack[-1] = v239;
    stack[-2] = v186;
    stack[-3] = v0;
/* end of prologue */

v293:
    v292 = stack[-1];
    if (v292 == nil) goto v111;
    v226 = stack[-3];
    v210 = stack[-2];
    v292 = stack[-1];
    v209 = qcar(v292);
    v292 = stack[0];
    fn = elt(env, 2); /* chksymmetries!&sub1 */
    v292 = (*qfnn(fn))(qenv(fn), 4, v226, v210, v209, v292);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-5];
    v209 = v292;
    v292 = v209;
    if (v292 == nil) goto v262;
    stack[-4] = v209;
    v226 = stack[-3];
    v210 = stack[-2];
    v292 = stack[-1];
    v209 = qcdr(v292);
    v292 = stack[0];
    v292 = CC_chksymmetriesGsubst(env, 4, v226, v210, v209, v292);
    nil = C_nil;
    if (exception_pending()) goto v218;
    {
        Lisp_Object v99 = stack[-4];
        popv(6);
        return cons(v99, v292);
    }

v262:
    v226 = stack[-3];
    v210 = stack[-2];
    v292 = stack[-1];
    v209 = qcdr(v292);
    v292 = stack[0];
    stack[-3] = v226;
    stack[-2] = v210;
    stack[-1] = v209;
    stack[0] = v292;
    goto v293;

v111:
    v292 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v292); }
/* error exit handlers */
v218:
    popv(6);
    return nil;
}



/* Code for mk_world1 */

static Lisp_Object MS_CDECL CC_mk_world1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v186,
                         Lisp_Object v239, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v283, v286, v208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk_world1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_world1");
#endif
    if (stack >= stacklimit)
    {
        push3(v239,v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v186,v239);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v239;
    stack[-1] = v186;
    v283 = v0;
/* end of prologue */
    fn = elt(env, 1); /* map_2_from_map_1 */
    v208 = (*qfn1(fn))(qenv(fn), v283);
    nil = C_nil;
    if (exception_pending()) goto v104;
    v286 = stack[-1];
    v283 = stack[0];
    popv(2);
    return list3(v208, v286, v283);
/* error exit handlers */
v104:
    popv(2);
    return nil;
}



/* Code for bc_power */

static Lisp_Object CC_bc_power(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_power");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v112 = v186;
    v217 = v0;
/* end of prologue */
    fn = elt(env, 1); /* exptf */
    v112 = (*qfn2(fn))(qenv(fn), v217, v112);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v112);
    }
/* error exit handlers */
v181:
    popv(1);
    return nil;
}



/* Code for gd_simpl */

static Lisp_Object CC_gd_simpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v182, v195, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gd_simpl");
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
    v172 = v0;
/* end of prologue */
    v195 = qvalue(elt(env, 1)); /* nil */
    v182 = qvalue(elt(env, 2)); /* t */
    v104 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* !*guardian */
    qvalue(elt(env, 3)) = v195; /* !*guardian */
    stack[-1] = qvalue(elt(env, 4)); /* !*rlnzden */
    qvalue(elt(env, 4)) = v182; /* !*rlnzden */
    stack[0] = qvalue(elt(env, 5)); /* !*rladdcond */
    qvalue(elt(env, 5)) = v104; /* !*rladdcond */
    v104 = v172;
    fn = elt(env, 6); /* rl_simp */
    v195 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v182 = qvalue(elt(env, 1)); /* nil */
    v104 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 7); /* rl_simpl */
    v104 = (*qfnn(fn))(qenv(fn), 3, v195, v182, v104);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    fn = elt(env, 8); /* rl_prepfof */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; /* !*rladdcond */
    qvalue(elt(env, 4)) = stack[-1]; /* !*rlnzden */
    qvalue(elt(env, 3)) = stack[-2]; /* !*guardian */
    { popv(4); return onevalue(v104); }
/* error exit handlers */
v183:
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; /* !*rladdcond */
    qvalue(elt(env, 4)) = stack[-1]; /* !*rlnzden */
    qvalue(elt(env, 3)) = stack[-2]; /* !*guardian */
    popv(4);
    return nil;
}



/* Code for !*ff2a */

static Lisp_Object CC_Hff2a(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v290;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *ff2a");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v173 = v186;
    v290 = v0;
/* end of prologue */
    v173 = cons(v290, v173);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[0];
    fn = elt(env, 3); /* cancel */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[0];
    v290 = v173;
    v173 = qvalue(elt(env, 1)); /* wtl!* */
    if (v173 == nil) goto v282;
    v173 = v290;
    v173 = qcar(v173);
    if (v173 == nil) goto v105;
    v173 = elt(env, 2); /* prepf */
    {
        popv(1);
        fn = elt(env, 4); /* sqform */
        return (*qfn2(fn))(qenv(fn), v290, v173);
    }

v105:
    v173 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v173); }

v282:
    v173 = v290;
    {
        popv(1);
        fn = elt(env, 5); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v173);
    }
/* error exit handlers */
v203:
    popv(1);
    return nil;
}



/* Code for cl_applysac */

static Lisp_Object CC_cl_applysac(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v225, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_applysac");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v186;
    v225 = v0;
/* end of prologue */
    v224 = nil;
    stack[-1] = v225;
    goto v180;

v180:
    v225 = stack[-1];
    if (v225 == nil) { popv(3); return onevalue(v224); }
    v225 = stack[-1];
    v202 = qcar(v225);
    v225 = v224;
    v224 = stack[0];
    fn = elt(env, 3); /* cl_applysac1 */
    v224 = (*qfnn(fn))(qenv(fn), 3, v202, v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v202 = v224;
    v225 = v202;
    v224 = elt(env, 2); /* break */
    if (v225 == v224) goto v232;
    v224 = stack[-1];
    v224 = qcdr(v224);
    stack[-1] = v224;
    v224 = v202;
    v224 = qcar(v224);
    if (v224 == nil) goto v220;
    v224 = v202;
    v224 = qcar(v224);
    v224 = qcdr(v224);
    v225 = v202;
    v225 = qcdr(v225);
    v224 = cons(v224, v225);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    goto v180;

v220:
    v224 = v202;
    v224 = qcdr(v224);
    goto v180;

v232:
    v224 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v224;
    v224 = elt(env, 2); /* break */
    goto v180;
/* error exit handlers */
v209:
    popv(3);
    return nil;
}



/* Code for xpdiff */

static Lisp_Object CC_xpdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v186;
    stack[-1] = v0;
/* end of prologue */
    v216 = stack[-1];
    if (v216 == nil) goto v227;
    v216 = stack[0];
    if (v216 == nil) goto v208;
    v216 = stack[0];
    v222 = qcar(v216);
    v216 = stack[-1];
    v216 = qcar(v216);
    v216 = (Lisp_Object)greaterp2(v222, v216);
    nil = C_nil;
    if (exception_pending()) goto v189;
    v216 = v216 ? lisp_true : nil;
    env = stack[-3];
    if (v216 == nil) goto v173;
    v216 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v216); }

v173:
    v216 = stack[-1];
    v222 = qcdr(v216);
    v216 = stack[0];
    v216 = qcdr(v216);
    v216 = CC_xpdiff(env, v222, v216);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[-2] = v216;
    v222 = stack[-2];
    v216 = elt(env, 4); /* failed */
    if (v222 == v216) goto v201;
    v216 = stack[-1];
    v222 = qcar(v216);
    v216 = stack[0];
    v216 = qcar(v216);
    v222 = difference2(v222, v216);
    nil = C_nil;
    if (exception_pending()) goto v189;
    v216 = stack[-2];
    popv(4);
    return cons(v222, v216);

v201:
    v216 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v216); }

v208:
    v216 = elt(env, 3); /* "A too long in xpdiff" */
    {
        popv(4);
        fn = elt(env, 5); /* interr */
        return (*qfn1(fn))(qenv(fn), v216);
    }

v227:
    v216 = stack[0];
    if (v216 == nil) goto v179;
    v216 = elt(env, 2); /* "B too long in xpdiff" */
    {
        popv(4);
        fn = elt(env, 5); /* interr */
        return (*qfn1(fn))(qenv(fn), v216);
    }

v179:
    v216 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v216); }
/* error exit handlers */
v189:
    popv(4);
    return nil;
}



/* Code for ps!:constmult!-erule */

static Lisp_Object CC_psTconstmultKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v172, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:constmult-erule");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v172 = v186;
    v171 = v0;
/* end of prologue */
    v195 = v171;
    v195 = qcdr(v195);
    stack[0] = qcar(v195);
    v195 = v171;
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    v195 = qcar(v195);
    fn = elt(env, 1); /* ps!:evaluate */
    v195 = (*qfn2(fn))(qenv(fn), v195, v172);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-1];
    {
        Lisp_Object v183 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v183, v195);
    }
/* error exit handlers */
v194:
    popv(2);
    return nil;
}



/* Code for ldf!-deg */

static Lisp_Object CC_ldfKdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-deg");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v186;
    v219 = v0;
/* end of prologue */
    stack[-4] = v219;
    v219 = stack[-4];
    if (v219 == nil) goto v217;
    v219 = stack[-4];
    v219 = qcar(v219);
    v191 = qcdr(v219);
    v219 = stack[-3];
    fn = elt(env, 2); /* degreef */
    v219 = (*qfn2(fn))(qenv(fn), v191, v219);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-5];
    v219 = ncons(v219);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-5];
    stack[-1] = v219;
    stack[-2] = v219;
    goto v178;

v178:
    v219 = stack[-4];
    v219 = qcdr(v219);
    stack[-4] = v219;
    v219 = stack[-4];
    if (v219 == nil) goto v214;
    stack[0] = stack[-1];
    v219 = stack[-4];
    v219 = qcar(v219);
    v191 = qcdr(v219);
    v219 = stack[-3];
    fn = elt(env, 2); /* degreef */
    v219 = (*qfn2(fn))(qenv(fn), v191, v219);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-5];
    v219 = ncons(v219);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-5];
    v219 = Lrplacd(nil, stack[0], v219);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-5];
    v219 = stack[-1];
    v219 = qcdr(v219);
    stack[-1] = v219;
    goto v178;

v214:
    v219 = stack[-2];
    goto v177;

v177:
    {
        popv(6);
        fn = elt(env, 3); /* maxl */
        return (*qfn1(fn))(qenv(fn), v219);
    }

v217:
    v219 = qvalue(elt(env, 1)); /* nil */
    goto v177;
/* error exit handlers */
v176:
    popv(6);
    return nil;
}



/* Code for groebinvokecritm */

static Lisp_Object CC_groebinvokecritm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v267, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebinvokecritm");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v186;
    stack[-2] = v0;
/* end of prologue */
    v267 = stack[-1];
    stack[-3] = v267;
    goto v204;

v204:
    v267 = stack[-3];
    if (v267 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v267 = stack[-3];
    v267 = qcar(v267);
    stack[0] = v267;
    v267 = stack[-2];
    v174 = qcar(v267);
    v267 = stack[0];
    v267 = qcar(v267);
    fn = elt(env, 3); /* buchvevdivides!? */
    v267 = (*qfn2(fn))(qenv(fn), v174, v267);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-4];
    if (v267 == nil) goto v208;
    v267 = qvalue(elt(env, 2)); /* mcount!* */
    v267 = add1(v267);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-4];
    qvalue(elt(env, 2)) = v267; /* mcount!* */
    v174 = stack[0];
    v267 = stack[-1];
    fn = elt(env, 4); /* groedeletip */
    v267 = (*qfn2(fn))(qenv(fn), v174, v267);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-4];
    stack[-1] = v267;
    goto v208;

v208:
    v267 = stack[-3];
    v267 = qcdr(v267);
    stack[-3] = v267;
    goto v204;
/* error exit handlers */
v295:
    popv(5);
    return nil;
}



/* Code for wedgewedge */

static Lisp_Object CC_wedgewedge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v281, v296;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgewedge");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v186;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v111;

v111:
    v197 = stack[-1];
    v197 = qcdr(v197);
    if (v197 == nil) goto v207;
    v197 = stack[-1];
    v296 = qcar(v197);
    v281 = (Lisp_Object)17; /* 1 */
    v197 = (Lisp_Object)17; /* 1 */
    v296 = list2star(v296, v281, v197);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    v281 = qvalue(elt(env, 1)); /* nil */
    v197 = stack[-2];
    v197 = acons(v296, v281, v197);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    stack[-2] = v197;
    v197 = stack[-1];
    v197 = qcdr(v197);
    stack[-1] = v197;
    goto v111;

v207:
    v197 = stack[-1];
    v296 = qcar(v197);
    v281 = (Lisp_Object)17; /* 1 */
    v197 = (Lisp_Object)17; /* 1 */
    v197 = list2star(v296, v281, v197);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    stack[-1] = ncons(v197);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    v296 = stack[0];
    v281 = (Lisp_Object)17; /* 1 */
    v197 = (Lisp_Object)17; /* 1 */
    v197 = list2star(v296, v281, v197);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    v197 = ncons(v197);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    fn = elt(env, 2); /* wedgepf2 */
    v197 = (*qfn2(fn))(qenv(fn), stack[-1], v197);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    v281 = v197;
    goto v178;

v178:
    v197 = stack[-2];
    if (v197 == nil) { popv(4); return onevalue(v281); }
    v197 = stack[-2];
    v197 = qcar(v197);
    fn = elt(env, 2); /* wedgepf2 */
    v197 = (*qfn2(fn))(qenv(fn), v197, v281);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    v281 = v197;
    v197 = stack[-2];
    v197 = qcdr(v197);
    stack[-2] = v197;
    goto v178;
/* error exit handlers */
v279:
    popv(4);
    return nil;
}



/* Code for listnoeval */

static Lisp_Object CC_listnoeval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v171;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listnoeval");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v171 = v186;
    v172 = v0;
/* end of prologue */

v227:
    v171 = v172;
    if (!(!consp(v171))) { popv(1); return onevalue(v172); }
    v171 = v172;
    v172 = elt(env, 1); /* avalue */
    v172 = get(v171, v172);
    env = stack[0];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    goto v227;
}



/* Code for delete_edge */

static Lisp_Object CC_delete_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v288, v295;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delete_edge");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v186;
    stack[-1] = v0;
/* end of prologue */
    v295 = nil;
    goto v204;

v204:
    v207 = stack[0];
    if (v207 == nil) goto v178;
    v207 = stack[-1];
    v288 = qcar(v207);
    v207 = stack[0];
    v207 = qcar(v207);
    v207 = qcar(v207);
    if (v288 == v207) goto v194;
    v207 = stack[0];
    v207 = qcar(v207);
    v288 = v295;
    v207 = cons(v207, v288);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    v295 = v207;
    v207 = stack[0];
    v207 = qcdr(v207);
    stack[0] = v207;
    goto v204;

v194:
    v288 = v295;
    v207 = stack[0];
    v207 = qcdr(v207);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v288, v207);
    }

v178:
    v207 = v295;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v207);
    }
/* error exit handlers */
v231:
    popv(3);
    return nil;
}



/* Code for reduce!-columns */

static Lisp_Object MS_CDECL CC_reduceKcolumns(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v186,
                         Lisp_Object v239, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce-columns");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-columns");
#endif
    if (stack >= stacklimit)
    {
        push3(v239,v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v186,v239);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v239;
    stack[-5] = v186;
    stack[-6] = v0;
/* end of prologue */
    v89 = stack[-6];
    stack[-3] = v89;
    v89 = stack[-5];
    stack[-2] = v89;
    stack[0] = stack[-6];
    v87 = stack[-6];
    v89 = stack[-4];
    fn = elt(env, 3); /* red!-weight */
    v89 = (*qfn2(fn))(qenv(fn), v87, v89);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-8];
    v89 = cons(stack[0], v89);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-8];
    stack[-7] = v89;
    goto v180;

v180:
    v89 = stack[-3];
    if (v89 == nil) goto v200;
    v89 = stack[-3];
    v87 = qcar(v89);
    v89 = (Lisp_Object)1; /* 0 */
    if (v87 == v89) goto v290;
    v89 = stack[-2];
    v87 = qcar(v89);
    v89 = (Lisp_Object)1; /* 0 */
    v89 = (v87 == v89 ? lisp_true : nil);
    goto v173;

v173:
    if (!(v89 == nil)) goto v185;
    v89 = stack[-3];
    v87 = qcar(v89);
    v89 = stack[-2];
    v89 = qcar(v89);
    v89 = Ldivide(nil, v87, v89);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-8];
    stack[-1] = v89;
    v87 = qcdr(v89);
    v89 = (Lisp_Object)1; /* 0 */
    if (!(v87 == v89)) goto v185;
    stack[0] = stack[-6];
    v89 = stack[-1];
    v87 = qcar(v89);
    v89 = stack[-5];
    fn = elt(env, 4); /* mv!-domainlist!-!* */
    v89 = (*qfn2(fn))(qenv(fn), v87, v89);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-8];
    fn = elt(env, 5); /* mv!-domainlist!-!- */
    v89 = (*qfn2(fn))(qenv(fn), stack[0], v89);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-8];
    stack[-1] = v89;
    v87 = stack[-1];
    v89 = stack[-4];
    fn = elt(env, 3); /* red!-weight */
    v89 = (*qfn2(fn))(qenv(fn), v87, v89);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-8];
    stack[0] = v89;
    v87 = stack[0];
    v89 = stack[-7];
    v89 = qcdr(v89);
    fn = elt(env, 6); /* red!-weight!-less!-p */
    v89 = (*qfn2(fn))(qenv(fn), v87, v89);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-8];
    if (v89 == nil) goto v185;
    v87 = stack[-1];
    v89 = stack[0];
    v87 = cons(v87, v89);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-8];
    v89 = stack[-7];
    fn = elt(env, 7); /* more!-apartp */
    v89 = (*qfn2(fn))(qenv(fn), v87, v89);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-8];
    if (!(v89 == nil)) goto v185;
    v87 = stack[-1];
    v89 = stack[0];
    v89 = cons(v87, v89);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-8];
    stack[-7] = v89;
    goto v185;

v185:
    v89 = stack[-3];
    v89 = qcdr(v89);
    stack[-3] = v89;
    v89 = stack[-2];
    v89 = qcdr(v89);
    stack[-2] = v89;
    goto v180;

v290:
    v89 = qvalue(elt(env, 1)); /* t */
    goto v173;

v200:
    v89 = stack[-7];
    v89 = qcar(v89);
    { popv(9); return onevalue(v89); }
/* error exit handlers */
v299:
    popv(9);
    return nil;
}



/* Code for dp_prod */

static Lisp_Object CC_dp_prod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v282, v228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_prod");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v186;
    stack[-1] = v0;
/* end of prologue */
    v282 = stack[-1];
    stack[-2] = Llength(nil, v282);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    v282 = stack[0];
    v282 = Llength(nil, v282);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-3];
    v282 = (Lisp_Object)lesseq2(stack[-2], v282);
    nil = C_nil;
    if (exception_pending()) goto v290;
    v282 = v282 ? lisp_true : nil;
    env = stack[-3];
    if (v282 == nil) goto v183;
    v228 = stack[-1];
    v282 = stack[0];
    {
        popv(4);
        fn = elt(env, 1); /* dp!=prod */
        return (*qfn2(fn))(qenv(fn), v228, v282);
    }

v183:
    v228 = stack[0];
    v282 = stack[-1];
    {
        popv(4);
        fn = elt(env, 1); /* dp!=prod */
        return (*qfn2(fn))(qenv(fn), v228, v282);
    }
/* error exit handlers */
v290:
    popv(4);
    return nil;
}



/* Code for partsym_zerop */

static Lisp_Object CC_partsym_zerop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v288, v295;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partsym_zerop");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v186;
    stack[-1] = v0;
/* end of prologue */

v293:
    v207 = stack[-1];
    if (v207 == nil) goto v227;
    v207 = stack[-1];
    v207 = qcar(v207);
    fn = elt(env, 3); /* repeats */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    v295 = v207;
    v207 = stack[0];
    v288 = qcar(v207);
    v207 = elt(env, 2); /* !- */
    if (v288 == v207) goto v104;
    v207 = qvalue(elt(env, 1)); /* nil */
    goto v105;

v105:
    if (!(v207 == nil)) { popv(3); return onevalue(v295); }
    v207 = stack[-1];
    v288 = qcdr(v207);
    v207 = stack[0];
    v207 = qcdr(v207);
    stack[-1] = v288;
    stack[0] = v207;
    goto v293;

v104:
    v207 = v295;
    goto v105;

v227:
    v207 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v207); }
/* error exit handlers */
v231:
    popv(3);
    return nil;
}



/* Code for general!-minus!-mod!-p */

static Lisp_Object CC_generalKminusKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-minus-mod-p");
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
    goto v227;

v227:
    v218 = stack[-1];
    if (v218 == nil) goto v177;
    v218 = stack[-1];
    if (!consp(v218)) goto v286;
    v218 = stack[-1];
    v218 = qcar(v218);
    v218 = (consp(v218) ? nil : lisp_true);
    goto v283;

v283:
    if (v218 == nil) goto v101;
    v99 = stack[-1];
    v218 = (Lisp_Object)1; /* 0 */
    if (v99 == v218) goto v229;
    stack[0] = stack[-2];
    v99 = qvalue(elt(env, 2)); /* current!-modulus */
    v218 = stack[-1];
    v218 = difference2(v99, v218);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    {
        Lisp_Object v197 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v197, v218);
    }

v229:
    v99 = stack[-2];
    v218 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v99, v218);
    }

v101:
    v218 = stack[-1];
    v218 = qcar(v218);
    stack[0] = qcar(v218);
    v218 = stack[-1];
    v218 = qcar(v218);
    v218 = qcdr(v218);
    v99 = CC_generalKminusKmodKp(env, v218);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v218 = stack[-2];
    v218 = acons(stack[0], v99, v218);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    stack[-2] = v218;
    v218 = stack[-1];
    v218 = qcdr(v218);
    stack[-1] = v218;
    goto v227;

v286:
    v218 = qvalue(elt(env, 1)); /* t */
    goto v283;

v177:
    v218 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v218);
    }
/* error exit handlers */
v196:
    popv(4);
    return nil;
}



/* Code for ofsf_qesubiord */

static Lisp_Object MS_CDECL CC_ofsf_qesubiord(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v186,
                         Lisp_Object v239, Lisp_Object v190, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v194, v183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_qesubiord");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_qesubiord");
#endif
    if (stack >= stacklimit)
    {
        push4(v190,v239,v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v186,v239,v190);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v190;
    stack[-1] = v239;
    v193 = v186;
    v194 = v0;
/* end of prologue */
    stack[-2] = v194;
    v194 = v193;
    v193 = stack[-1];
    fn = elt(env, 1); /* sfto_reorder */
    v183 = (*qfn2(fn))(qenv(fn), v194, v193);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-3];
    v194 = stack[-1];
    v193 = stack[0];
    {
        Lisp_Object v213 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* ofsf_qesubiord1 */
        return (*qfnn(fn))(qenv(fn), 4, v213, v183, v194, v193);
    }
/* error exit handlers */
v232:
    popv(4);
    return nil;
}



/* Code for get!*real!*irreducible!*rep */

static Lisp_Object CC_getHrealHirreducibleHrep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*real*irreducible*rep");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v186;
    stack[-1] = v0;
/* end of prologue */
    v185 = stack[-1];
    stack[-2] = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-3];
    v200 = elt(env, 1); /* realrep */
    v185 = stack[0];
    fn = elt(env, 2); /* mkid */
    v185 = (*qfn2(fn))(qenv(fn), v200, v185);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-3];
    v185 = get(stack[-1], v185);
    env = stack[-3];
    v185 = qcdr(v185);
    v185 = Lappend(nil, stack[-2], v185);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 3); /* mk_resimp_rep */
        return (*qfn1(fn))(qenv(fn), v185);
    }
/* error exit handlers */
v282:
    popv(4);
    return nil;
}



/* Code for ps!:times!: */

static Lisp_Object CC_psTtimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v221, v283;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:times:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v181 = v186;
    v221 = v0;
/* end of prologue */
    v283 = elt(env, 1); /* times */
    {
        fn = elt(env, 2); /* ps!:operator!: */
        return (*qfnn(fn))(qenv(fn), 3, v283, v221, v181);
    }
}



/* Code for vdpfmon */

static Lisp_Object CC_vdpfmon(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpfmon");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v186;
    v206 = v0;
/* end of prologue */
    stack[-5] = elt(env, 1); /* vdp */
    stack[-3] = stack[-4];
    stack[-2] = v206;
    stack[-1] = stack[-4];
    stack[0] = ncons(v206);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v206 = qvalue(elt(env, 2)); /* nil */
    v206 = ncons(v206);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v206 = acons(stack[-1], stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v206 = list3star(stack[-5], stack[-3], stack[-2], v206);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    stack[-1] = v206;
    v206 = qvalue(elt(env, 3)); /* !*gsugar */
    if (v206 == nil) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v206 = stack[-4];
    fn = elt(env, 4); /* vevtdeg */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    fn = elt(env, 5); /* gsetsugar */
    v206 = (*qfn2(fn))(qenv(fn), stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v256;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
/* error exit handlers */
v256:
    popv(7);
    return nil;
}



/* Code for xvarp */

static Lisp_Object CC_xvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v197, v281;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xvarp");
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
    v197 = qvalue(elt(env, 1)); /* xvars!* */
    v196 = qvalue(elt(env, 2)); /* t */
    if (equal(v197, v196)) goto v227;
    v196 = stack[0];
    fn = elt(env, 7); /* xdegree */
    v197 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-1];
    v196 = (Lisp_Object)1; /* 0 */
    if (v197 == v196) goto v183;
    v196 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v196); }

v183:
    v196 = stack[0];
    v197 = qvalue(elt(env, 1)); /* xvars!* */
    v196 = Lmemq(nil, v196, v197);
    { popv(2); return onevalue(v196); }

v227:
    v196 = stack[0];
    if (!consp(v196)) goto v290;
    v196 = stack[0];
    v197 = qcar(v196);
    v196 = elt(env, 4); /* indexvar */
    v196 = Lflagp(nil, v197, v196);
    env = stack[-1];
    if (v196 == nil) goto v187;
    v196 = stack[0];
    v196 = qcdr(v196);
    v281 = Llength(nil, v196);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-1];
    v196 = stack[0];
    v197 = qcar(v196);
    v196 = elt(env, 5); /* ifdegree */
    v196 = get(v197, v196);
    v196 = Lassoc(nil, v281, v196);
    { popv(2); return onevalue(v196); }

v187:
    v196 = stack[0];
    v196 = qcar(v196);
    v197 = elt(env, 6); /* (wedge d partdf hodge innerprod liedf) */
    v196 = Lmemq(nil, v196, v197);
    { popv(2); return onevalue(v196); }

v290:
    v196 = stack[0];
    v197 = elt(env, 3); /* fdegree */
    popv(2);
    return get(v196, v197);
/* error exit handlers */
v300:
    popv(2);
    return nil;
}



/* Code for functionp */

static Lisp_Object CC_functionp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v283;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for functionp");
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
    v221 = stack[0];
    fn = elt(env, 2); /* getd */
    v221 = (*qfn1(fn))(qenv(fn), v221);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-1];
    if (!(v221 == nil)) { popv(2); return onevalue(v221); }
    v221 = stack[0];
    v283 = elt(env, 1); /* lambda */
        popv(2);
        return Leqcar(nil, v221, v283);
/* error exit handlers */
v208:
    popv(2);
    return nil;
}



/* Code for rdzchk */

static Lisp_Object MS_CDECL CC_rdzchk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v186,
                         Lisp_Object v239, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v323, v324;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rdzchk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rdzchk");
#endif
    if (stack >= stacklimit)
    {
        push3(v239,v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v186,v239);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v239;
    stack[-1] = v186;
    stack[-3] = v0;
/* end of prologue */
    v323 = stack[-3];
    if (!consp(v323)) goto v286;
    v323 = stack[-3];
    v323 = qcdr(v323);
    v324 = qcar(v323);
    v323 = (Lisp_Object)1; /* 0 */
    if (v324 == v323) goto v280;
    v323 = stack[-1];
    v323 = qcdr(v323);
    v324 = qcar(v323);
    v323 = (Lisp_Object)1; /* 0 */
    v323 = (Lisp_Object)greaterp2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    if (v323 == nil) goto v326;
    v323 = stack[0];
    v323 = qcdr(v323);
    v324 = qcar(v323);
    v323 = (Lisp_Object)1; /* 0 */
    v323 = (Lisp_Object)greaterp2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    goto v327;

v327:
    if (!(v323 == nil)) goto v328;
    v323 = stack[-1];
    v323 = qcdr(v323);
    v324 = qcar(v323);
    v323 = (Lisp_Object)1; /* 0 */
    v323 = (Lisp_Object)lessp2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    if (v323 == nil) goto v329;
    v323 = stack[0];
    v323 = qcdr(v323);
    v324 = qcar(v323);
    v323 = (Lisp_Object)1; /* 0 */
    v323 = (Lisp_Object)lessp2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    goto v328;

v328:
    if (!(v323 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v323 = stack[-1];
    v323 = qcdr(v323);
    v324 = qcar(v323);
    v323 = (Lisp_Object)1; /* 0 */
    v323 = (Lisp_Object)greaterp2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    if (v323 == nil) goto v330;
    v323 = stack[-1];
    v324 = v323;
    goto v243;

v243:
    v323 = qvalue(elt(env, 6)); /* rd!-tolerance!* */
    stack[-4] = v324;
    stack[-2] = v323;
    stack[-1] = elt(env, 5); /* !:rd!: */
    v323 = stack[-4];
    v323 = qcdr(v323);
    v324 = qcar(v323);
    v323 = stack[-2];
    v323 = qcdr(v323);
    v323 = qcar(v323);
    stack[0] = times2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-5];
    v323 = stack[-4];
    v323 = qcdr(v323);
    v324 = qcdr(v323);
    v323 = stack[-2];
    v323 = qcdr(v323);
    v323 = qcdr(v323);
    v323 = plus2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-5];
    stack[-1] = list2star(stack[-1], stack[0], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-5];
    v323 = stack[-3];
    v323 = qcdr(v323);
    v324 = qcar(v323);
    v323 = (Lisp_Object)1; /* 0 */
    v323 = (Lisp_Object)greaterp2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    if (v323 == nil) goto v331;
    v323 = stack[-3];
    goto v273;

v273:
    fn = elt(env, 8); /* greaterp!: */
    v323 = (*qfn2(fn))(qenv(fn), stack[-1], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-5];
    if (v323 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v323 = qvalue(elt(env, 7)); /* bfz!* */
    { popv(6); return onevalue(v323); }

v331:
    stack[0] = elt(env, 5); /* !:rd!: */
    v323 = stack[-3];
    v323 = qcdr(v323);
    v323 = qcar(v323);
    v324 = negate(v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-5];
    v323 = stack[-3];
    v323 = qcdr(v323);
    v323 = qcdr(v323);
    v323 = list2star(stack[0], v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-5];
    goto v273;

v330:
    stack[0] = elt(env, 5); /* !:rd!: */
    v323 = stack[-1];
    v323 = qcdr(v323);
    v323 = qcar(v323);
    v324 = negate(v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-5];
    v323 = stack[-1];
    v323 = qcdr(v323);
    v323 = qcdr(v323);
    v323 = list2star(stack[0], v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-5];
    v324 = v323;
    goto v243;

v329:
    v323 = qvalue(elt(env, 3)); /* nil */
    goto v328;

v326:
    v323 = qvalue(elt(env, 3)); /* nil */
    goto v327;

v280:
    v323 = qvalue(elt(env, 2)); /* t */
    goto v328;

v286:
    v324 = stack[-3];
    v323 = elt(env, 1); /* 0.0 */
    if (equal(v324, v323)) goto v221;
    v324 = stack[-1];
    v323 = elt(env, 1); /* 0.0 */
    v323 = (Lisp_Object)greaterp2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    if (v323 == nil) goto v232;
    v324 = stack[0];
    v323 = elt(env, 1); /* 0.0 */
    v323 = (Lisp_Object)greaterp2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    goto v200;

v200:
    if (!(v323 == nil)) goto v181;
    v324 = stack[-1];
    v323 = elt(env, 1); /* 0.0 */
    v323 = (Lisp_Object)lessp2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    if (v323 == nil) goto v257;
    v324 = stack[0];
    v323 = elt(env, 1); /* 0.0 */
    v323 = (Lisp_Object)lessp2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    goto v181;

v181:
    if (!(v323 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v323 = stack[-3];
    stack[0] = Labsval(nil, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-5];
    v323 = stack[-1];
    v324 = Labsval(nil, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-5];
    v323 = qvalue(elt(env, 4)); /* !!fleps1 */
    v323 = times2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-5];
    v323 = (Lisp_Object)lessp2(stack[0], v323);
    nil = C_nil;
    if (exception_pending()) goto v325;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    if (v323 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v323 = elt(env, 1); /* 0.0 */
    { popv(6); return onevalue(v323); }

v257:
    v323 = qvalue(elt(env, 3)); /* nil */
    goto v181;

v232:
    v323 = qvalue(elt(env, 3)); /* nil */
    goto v200;

v221:
    v323 = qvalue(elt(env, 2)); /* t */
    goto v181;
/* error exit handlers */
v325:
    popv(6);
    return nil;
}



/* Code for fctins */

static Lisp_Object MS_CDECL CC_fctins(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v186,
                         Lisp_Object v239, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v295, v201;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fctins");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctins");
#endif
    if (stack >= stacklimit)
    {
        push3(v239,v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v186,v239);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v239;
    stack[-1] = v186;
    stack[-2] = v0;
/* end of prologue */
    v295 = stack[0];
    if (v295 == nil) goto v204;
    v295 = stack[0];
    v295 = qcar(v295);
    fn = elt(env, 1); /* fctlength */
    v201 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    v295 = stack[-1];
    v295 = (Lisp_Object)lessp2(v201, v295);
    nil = C_nil;
    if (exception_pending()) goto v257;
    v295 = v295 ? lisp_true : nil;
    env = stack[-3];
    if (v295 == nil) goto v214;
    v201 = stack[-2];
    v295 = stack[0];
    popv(4);
    return cons(v201, v295);

v214:
    v295 = stack[0];
    stack[-1] = qcar(v295);
    v201 = stack[-2];
    v295 = stack[0];
    v295 = qcdr(v295);
    fn = elt(env, 2); /* fctinsert */
    v295 = (*qfn2(fn))(qenv(fn), v201, v295);
    nil = C_nil;
    if (exception_pending()) goto v257;
    {
        Lisp_Object v211 = stack[-1];
        popv(4);
        return cons(v211, v295);
    }

v204:
    v295 = stack[-2];
    popv(4);
    return ncons(v295);
/* error exit handlers */
v257:
    popv(4);
    return nil;
}



/* Code for ev!-tades */

static Lisp_Object CC_evKtades(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v288, v295, v201;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-tades");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v186;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v204;

v204:
    v288 = stack[-1];
    if (v288 == nil) goto v217;
    v201 = qvalue(elt(env, 1)); /* ndim!* */
    v288 = stack[-1];
    v295 = qcar(v288);
    v288 = stack[0];
    v288 = Lassoc(nil, v295, v288);
    v288 = qcdr(v288);
    fn = elt(env, 2); /* binc */
    v295 = (*qfn2(fn))(qenv(fn), v201, v288);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    v288 = stack[-2];
    v288 = cons(v295, v288);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    stack[-2] = v288;
    v288 = stack[-1];
    v288 = qcdr(v288);
    stack[-1] = v288;
    goto v204;

v217:
    stack[0] = stack[-2];
    v288 = (Lisp_Object)17; /* 1 */
    v288 = ncons(v288);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    {
        Lisp_Object v211 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v211, v288);
    }
/* error exit handlers */
v257:
    popv(4);
    return nil;
}



/* Code for compactf3 */

static Lisp_Object MS_CDECL CC_compactf3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v186,
                         Lisp_Object v239, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v214, v282;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "compactf3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactf3");
#endif
    if (stack >= stacklimit)
    {
        push3(v239,v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v186,v239);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v239;
    stack[-1] = v186;
    v214 = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* mv!-vars!* */
    qvalue(elt(env, 1)) = nil; /* mv!-vars!* */
    v213 = stack[0];
    qvalue(elt(env, 1)) = v213; /* mv!-vars!* */
    v213 = stack[0];
    fn = elt(env, 3); /* sf2mv */
    v282 = (*qfn2(fn))(qenv(fn), v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-3];
    v214 = stack[-1];
    v213 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* mv!-compact */
    v214 = (*qfnn(fn))(qenv(fn), 3, v282, v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-3];
    v213 = stack[0];
    fn = elt(env, 5); /* mv2sf */
    v213 = (*qfn2(fn))(qenv(fn), v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* mv!-vars!* */
    { popv(4); return onevalue(v213); }
/* error exit handlers */
v173:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* mv!-vars!* */
    popv(4);
    return nil;
}



/* Code for affinep */

static Lisp_Object CC_affinep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for affinep");
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
    v105 = v0;
/* end of prologue */
    v104 = qcar(v105);
    v105 = elt(env, 1); /* belong_to_space */
    v105 = get(v104, v105);
    env = stack[0];
    v104 = v105;
    v105 = v104;
    if (v105 == nil) goto v221;
    v105 = v104;
    fn = elt(env, 2); /* get_sign_space */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v182;
    v105 = (v105 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v105); }

v221:
    v105 = nil;
    { popv(1); return onevalue(v105); }
/* error exit handlers */
v182:
    popv(1);
    return nil;
}



/* Code for x!*!*p!-w */

static Lisp_Object MS_CDECL CC_xHHpKw(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v186,
                         Lisp_Object v239, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v172, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "x**p-w");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for x**p-w");
#endif
    if (stack >= stacklimit)
    {
        push3(v239,v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v186,v239);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v239;
    v195 = v186;
    v172 = v0;
/* end of prologue */
    v171 = v172;
    v172 = v195;
    v195 = (Lisp_Object)17; /* 1 */
    v195 = acons(v171, v172, v195);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-1];
    v172 = ncons(v195);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-1];
    v195 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* general!-difference!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v172, v195);
    }
/* error exit handlers */
v194:
    popv(2);
    return nil;
}



/* Code for radd */

static Lisp_Object CC_radd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v186)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93, v334;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for radd");
#endif
    if (stack >= stacklimit)
    {
        push2(v186,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v186);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v186;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    v92 = stack[-1];
    if (!consp(v92)) goto v183;
    stack[0] = (Lisp_Object)17; /* 1 */
    v92 = stack[-1];
    fn = elt(env, 4); /* prepf */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v335;
    {
        Lisp_Object v250 = stack[0];
        popv(4);
        return list2(v250, v92);
    }

v183:
    v93 = stack[-1];
    v92 = (Lisp_Object)1; /* 0 */
    v92 = (Lisp_Object)lessp2(v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v335;
    v92 = v92 ? lisp_true : nil;
    env = stack[-3];
    if (v92 == nil) goto v100;
    v92 = stack[0];
    v92 = Levenp(nil, v92);
    env = stack[-3];
    if (v92 == nil) goto v100;
    v92 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v92;
    v92 = stack[-1];
    v92 = negate(v92);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-3];
    stack[-1] = v92;
    goto v100;

v100:
    v93 = stack[-1];
    v92 = stack[0];
    fn = elt(env, 5); /* nrootnn */
    v92 = (*qfn2(fn))(qenv(fn), v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-3];
    stack[-1] = v92;
    v92 = stack[-2];
    if (v92 == nil) goto v114;
    v92 = qvalue(elt(env, 2)); /* !*reduced */
    if (v92 == nil) goto v296;
    v93 = stack[0];
    v92 = (Lisp_Object)33; /* 2 */
    if (!(v93 == v92)) goto v296;
    v92 = stack[-1];
    stack[0] = qcar(v92);
    v334 = elt(env, 3); /* i */
    v93 = (Lisp_Object)17; /* 1 */
    v92 = (Lisp_Object)17; /* 1 */
    v92 = acons(v334, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-3];
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-3];
    fn = elt(env, 6); /* multd */
    v92 = (*qfn2(fn))(qenv(fn), stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v335;
    stack[0] = v92;
    v92 = stack[-1];
    v92 = qcdr(v92);
    stack[-1] = v92;
    goto v106;

v106:
    v93 = stack[-1];
    v92 = (Lisp_Object)17; /* 1 */
    if (v93 == v92) goto v95;
    v93 = stack[0];
    v92 = stack[-1];
    popv(4);
    return list2(v93, v92);

v95:
    v92 = stack[0];
    popv(4);
    return ncons(v92);

v296:
    v92 = stack[-1];
    v92 = qcar(v92);
    stack[0] = v92;
    v92 = stack[-1];
    v92 = qcdr(v92);
    v92 = negate(v92);
    nil = C_nil;
    if (exception_pending()) goto v335;
    stack[-1] = v92;
    goto v106;

v114:
    v92 = stack[-1];
    v92 = qcar(v92);
    stack[0] = v92;
    v92 = stack[-1];
    v92 = qcdr(v92);
    stack[-1] = v92;
    goto v106;
/* error exit handlers */
v335:
    popv(4);
    return nil;
}



/* Code for random!-teeny!-prime */

static Lisp_Object CC_randomKteenyKprime(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v176, v291;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for random-teeny-prime");
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
    v176 = stack[0];
    v102 = elt(env, 1); /* all */
    if (v176 == v102) goto v177;
    v102 = stack[0];
    v176 = Llength(nil, v102);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-2];
    v102 = (Lisp_Object)161; /* 10 */
    v102 = (v176 == v102 ? lisp_true : nil);
    goto v111;

v111:
    if (v102 == nil) goto v229;
    v102 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v102); }

v229:
    stack[-1] = qvalue(elt(env, 4)); /* teeny!-primes */
    fn = elt(env, 5); /* next!-random!-number */
    v176 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-2];
    v102 = (Lisp_Object)161; /* 10 */
    v102 = Cremainder(v176, v102);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-2];
    v102 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v102/(16/CELL)));
    v291 = v102;
    v176 = v291;
    v102 = stack[0];
    v102 = Lmember(nil, v176, v102);
    if (v102 == nil) { popv(3); return onevalue(v291); }
    else goto v229;

v177:
    v102 = qvalue(elt(env, 2)); /* t */
    goto v111;
/* error exit handlers */
v202:
    popv(3);
    return nil;
}



/* Code for bfprin0 */

static Lisp_Object CC_bfprin0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v267, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfprin0");
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
    v267 = v0;
/* end of prologue */
    stack[0] = v267;
    v267 = qvalue(elt(env, 1)); /* !:print!-prec!: */
    if (v267 == nil) goto v171;
    v267 = qvalue(elt(env, 1)); /* !:print!-prec!: */
    goto v217;

v217:
    fn = elt(env, 3); /* round!:dec1 */
    v267 = (*qfn2(fn))(qenv(fn), stack[0], v267);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-1];
    v174 = v267;
    v174 = qcar(v174);
    v267 = qcdr(v267);
    fn = elt(env, 4); /* bfprin0x */
    v267 = (*qfn2(fn))(qenv(fn), v174, v267);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v267 = nil;
    { popv(2); return onevalue(v267); }

v171:
    v174 = qvalue(elt(env, 2)); /* !:prec!: */
    v267 = (Lisp_Object)33; /* 2 */
    v267 = difference2(v174, v267);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-1];
    goto v217;
/* error exit handlers */
v206:
    popv(2);
    return nil;
}



/* Code for opfchk!! */

static Lisp_Object CC_opfchkB(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v347, v348, v349;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opfchk!");
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
    stack[-3] = nil;
    stack[-2] = nil;
    v347 = stack[-5];
    v347 = qcar(v347);
    stack[0] = v347;
    stack[-6] = v347;
    v347 = stack[-5];
    v347 = qcdr(v347);
    stack[-5] = v347;
    v348 = stack[0];
    v347 = elt(env, 1); /* integer */
    v347 = Lflagp(nil, v348, v347);
    env = stack[-7];
    if (v347 == nil) goto v104;
    v347 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v347;
    v348 = stack[0];
    v347 = elt(env, 3); /* !:rn!: */
    v347 = get(v348, v347);
    env = stack[-7];
    goto v230;

v230:
    stack[0] = v347;
    v347 = stack[0];
    if (v347 == nil) goto v192;
    v347 = stack[-3];
    if (v347 == nil) goto v210;
    v347 = elt(env, 9); /* simprn */
    goto v176;

v176:
    stack[-4] = v347;
    v347 = stack[-3];
    if (!(v347 == nil)) goto v312;
    v347 = qvalue(elt(env, 12)); /* !*complex */
    if (v347 == nil) goto v312;
    v347 = stack[-5];
    v348 = qcar(v347);
    v347 = elt(env, 13); /* list */
    if (!consp(v348)) goto v198;
    v348 = qcar(v348);
    if (!(v348 == v347)) goto v198;
    v347 = stack[-5];
    v347 = qcar(v347);
    v347 = qcdr(v347);
    fn = elt(env, 22); /* revlis */
    v347 = (*qfn1(fn))(qenv(fn), v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    fn = elt(env, 23); /* simpcr */
    v347 = (*qfn1(fn))(qenv(fn), v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    v348 = v347;
    if (v347 == nil) goto v312;
    v347 = qvalue(elt(env, 8)); /* nil */
    if (!consp(v348)) goto v312;
    v348 = qcar(v348);
    if (!(v348 == v347)) goto v312;

v268:
    v348 = stack[-6];
    v347 = elt(env, 16); /* "is not defined as complex function" */
    v347 = list2(v348, v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    v348 = v347;
    v347 = v348;
    qvalue(elt(env, 17)) = v347; /* errmsg!* */
    v347 = qvalue(elt(env, 18)); /* !*protfg */
    if (!(v347 == nil)) goto v351;
    v347 = v348;
    fn = elt(env, 24); /* lprie */
    v347 = (*qfn1(fn))(qenv(fn), v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    goto v351;

v351:
    v347 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    goto v312;

v312:
    stack[-1] = stack[-4];
    v347 = stack[-5];
    fn = elt(env, 22); /* revlis */
    v347 = (*qfn1(fn))(qenv(fn), v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    v347 = Lapply1(nil, stack[-1], v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    stack[-5] = v347;
    if (!(v347 == nil)) goto v352;
    v347 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v347); }

v352:
    stack[-1] = elt(env, 19); /* apply */
    v347 = stack[0];
    stack[0] = Lmkquote(nil, v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    v347 = stack[-5];
    v347 = Lmkquote(nil, v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    v349 = list3(stack[-1], stack[0], v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    v348 = qvalue(elt(env, 8)); /* nil */
    v347 = qvalue(elt(env, 20)); /* !*backtrace */
    fn = elt(env, 25); /* errorset */
    v347 = (*qfnn(fn))(qenv(fn), 3, v349, v348, v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    stack[-5] = v347;
    v347 = stack[-5];
    if (!consp(v347)) goto v73;
    v347 = stack[-5];
    v347 = qcdr(v347);
    goto v72;

v72:
    if (v347 == nil) goto v353;
    v347 = stack[-2];
    if (v347 == nil) goto v354;
    v347 = stack[-2];
    stack[-5] = v347;
    v347 = qvalue(elt(env, 8)); /* nil */
    stack[-2] = v347;
    goto v242;

v242:
    v348 = stack[-6];
    v347 = elt(env, 15); /* !:cr!: */
    v347 = get(v348, v347);
    env = stack[-7];
    stack[0] = v347;
    if (v347 == nil) goto v268;
    else goto v352;

v354:
    v347 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v347); }

v353:
    v347 = stack[-3];
    if (v347 == nil) goto v355;
    v347 = qvalue(elt(env, 5)); /* dmode!* */
    if (v347 == nil) goto v303;
    v348 = qvalue(elt(env, 5)); /* dmode!* */
    v347 = elt(env, 6); /* (!:rd!: !:cr!:) */
    v347 = Lmemq(nil, v348, v347);
    goto v356;

v356:
    if (v347 == nil) goto v158;
    v347 = stack[-5];
    v347 = qcar(v347);
    { popv(8); return onevalue(v347); }

v158:
    v348 = qvalue(elt(env, 5)); /* dmode!* */
    v347 = elt(env, 21); /* i2d */
    v348 = get(v348, v347);
    v347 = stack[-5];
    v347 = qcar(v347);
        popv(8);
        return Lapply1(nil, v348, v347);

v303:
    v347 = qvalue(elt(env, 2)); /* t */
    goto v356;

v355:
    v347 = stack[-5];
    v347 = qcar(v347);
    { popv(8); return onevalue(v347); }

v73:
    v347 = qvalue(elt(env, 2)); /* t */
    goto v72;

v198:
    v347 = stack[-5];
    fn = elt(env, 22); /* revlis */
    v347 = (*qfn1(fn))(qenv(fn), v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    fn = elt(env, 23); /* simpcr */
    v347 = (*qfn1(fn))(qenv(fn), v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    stack[-5] = v347;
    if (v347 == nil) goto v357;
    v348 = stack[-5];
    v347 = qvalue(elt(env, 8)); /* nil */
    if (!consp(v348)) goto v266;
    v348 = qcar(v348);
    if (!(v348 == v347)) goto v266;
    v347 = qvalue(elt(env, 2)); /* t */
    goto v115;

v115:
    if (v347 == nil) goto v85;
    v347 = stack[-5];
    v347 = qcdr(v347);
    stack[-5] = v347;
    goto v242;

v85:
    v347 = stack[-5];
    v347 = qcdr(v347);
    stack[-2] = v347;
    v347 = stack[-5];
    v347 = qcar(v347);
    stack[-5] = v347;
    goto v312;

v266:
    v348 = stack[-6];
    v347 = elt(env, 14); /* expt */
    if (v348 == v347) goto v88;
    v347 = qvalue(elt(env, 8)); /* nil */
    goto v115;

v88:
    v347 = stack[-5];
    v347 = qcar(v347);
    v347 = qcar(v347);
    fn = elt(env, 26); /* rd!:minusp */
    v347 = (*qfn1(fn))(qenv(fn), v347);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-7];
    goto v115;

v357:
    v347 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v347); }

v210:
    v348 = stack[0];
    v347 = elt(env, 10); /* simparg */
    v347 = get(v348, v347);
    env = stack[-7];
    stack[-4] = v347;
    if (v347 == nil) goto v99;
    v347 = stack[-4];
    goto v176;

v99:
    v347 = elt(env, 11); /* simprd */
    goto v176;

v192:
    v347 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v347); }

v104:
    v347 = qvalue(elt(env, 4)); /* !*numval */
    if (v347 == nil) goto v290;
    v348 = qvalue(elt(env, 5)); /* dmode!* */
    v347 = elt(env, 6); /* (!:rd!: !:cr!:) */
    v347 = Lmemq(nil, v348, v347);
    if (v347 == nil) goto v290;
    v348 = stack[0];
    v347 = elt(env, 7); /* !:rd!: */
    v347 = get(v348, v347);
    env = stack[-7];
    goto v230;

v290:
    v347 = nil;
    goto v230;
/* error exit handlers */
v350:
    popv(8);
    return nil;
}



/* Code for conjsq */

static Lisp_Object CC_conjsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v267;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conjsq");
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
    v175 = stack[0];
    fn = elt(env, 2); /* impartsq */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-2];
    stack[-1] = v175;
    v175 = stack[-1];
    v175 = qcar(v175);
    if (v175 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v175 = stack[0];
    fn = elt(env, 3); /* repartsq */
    stack[0] = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-2];
    v175 = elt(env, 1); /* i */
    fn = elt(env, 4); /* simp */
    v267 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-2];
    v175 = stack[-1];
    fn = elt(env, 5); /* multsq */
    v175 = (*qfn2(fn))(qenv(fn), v267, v175);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-2];
    stack[-1] = v175;
    v175 = stack[-1];
    v175 = qcar(v175);
    fn = elt(env, 6); /* negf */
    v267 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-2];
    v175 = stack[-1];
    v175 = qcdr(v175);
    v175 = cons(v267, v175);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-2];
    {
        Lisp_Object v207 = stack[0];
        popv(3);
        fn = elt(env, 7); /* addsq */
        return (*qfn2(fn))(qenv(fn), v207, v175);
    }
/* error exit handlers */
v206:
    popv(3);
    return nil;
}



/* Code for repr_n */

static Lisp_Object CC_repr_n(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v267, v174, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repr_n");
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
    v205 = v0;
/* end of prologue */
    v267 = v205;
    v267 = qcdr(v267);
    v267 = qcdr(v267);
    v267 = qcar(v267);
    if (v267 == nil) goto v110;
    v267 = v205;
    v267 = qcdr(v267);
    v267 = qcdr(v267);
    v267 = qcdr(v267);
    v267 = qcdr(v267);
    v174 = qcar(v267);
    v267 = (Lisp_Object)1; /* 0 */
    if (v174 == v267) goto v104;
    v267 = v205;
    v267 = qcdr(v267);
    v267 = qcdr(v267);
    v267 = qcar(v267);
    v267 = qcar(v267);
    v267 = qcar(v267);
    { popv(1); return onevalue(v267); }

v104:
    v267 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v267); }

v110:
    v267 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v267 == nil)) goto v217;
    v267 = elt(env, 2); /* "repr_n : invalid REPR structure" */
    v267 = ncons(v267);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[0];
    fn = elt(env, 4); /* lprie */
    v267 = (*qfn1(fn))(qenv(fn), v267);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[0];
    goto v217;

v217:
    v267 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v267 = nil;
    { popv(1); return onevalue(v267); }
/* error exit handlers */
v206:
    popv(1);
    return nil;
}



/* Code for ratpoly_univarp */

static Lisp_Object CC_ratpoly_univarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v227;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_univarp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v227 = v0;
/* end of prologue */
    v227 = qcar(v227);
    {
        fn = elt(env, 1); /* sf_univarp */
        return (*qfn1(fn))(qenv(fn), v227);
    }
}



setup_type const u42_setup[] =
{
    {"preproc1",                CC_preproc1,    too_many_1,    wrong_no_1},
    {"mk_simpl_map_",           CC_mk_simpl_map_,too_many_1,   wrong_no_1},
    {"red_prepare",             CC_red_prepare, too_many_1,    wrong_no_1},
    {"dv_skel2factor",          too_few_2,      CC_dv_skel2factor,wrong_no_2},
    {"derivative-mod-p",        CC_derivativeKmodKp,too_many_1,wrong_no_1},
    {"linineqevaltest",         too_few_2,      CC_linineqevaltest,wrong_no_2},
    {"ordered-gcd-mod-p",       too_few_2,      CC_orderedKgcdKmodKp,wrong_no_2},
    {"polynomreduceby",         too_few_2,      CC_polynomreduceby,wrong_no_2},
    {"qqe_dfs",                 too_few_2,      CC_qqe_dfs,    wrong_no_2},
    {"factor-prim-f",           CC_factorKprimKf,too_many_1,   wrong_no_1},
    {"vdplsort",                CC_vdplsort,    too_many_1,    wrong_no_1},
    {"xpartitsq",               CC_xpartitsq,   too_many_1,    wrong_no_1},
    {"latexprin",               CC_latexprin,   too_many_1,    wrong_no_1},
    {"chksymmetries&subst",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_chksymmetriesGsubst},
    {"mk_world1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_mk_world1},
    {"bc_power",                too_few_2,      CC_bc_power,   wrong_no_2},
    {"gd_simpl",                CC_gd_simpl,    too_many_1,    wrong_no_1},
    {"*ff2a",                   too_few_2,      CC_Hff2a,      wrong_no_2},
    {"cl_applysac",             too_few_2,      CC_cl_applysac,wrong_no_2},
    {"xpdiff",                  too_few_2,      CC_xpdiff,     wrong_no_2},
    {"ps:constmult-erule",      too_few_2,      CC_psTconstmultKerule,wrong_no_2},
    {"ldf-deg",                 too_few_2,      CC_ldfKdeg,    wrong_no_2},
    {"groebinvokecritm",        too_few_2,      CC_groebinvokecritm,wrong_no_2},
    {"wedgewedge",              too_few_2,      CC_wedgewedge, wrong_no_2},
    {"listnoeval",              too_few_2,      CC_listnoeval, wrong_no_2},
    {"delete_edge",             too_few_2,      CC_delete_edge,wrong_no_2},
    {"reduce-columns",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduceKcolumns},
    {"dp_prod",                 too_few_2,      CC_dp_prod,    wrong_no_2},
    {"partsym_zerop",           too_few_2,      CC_partsym_zerop,wrong_no_2},
    {"general-minus-mod-p",     CC_generalKminusKmodKp,too_many_1,wrong_no_1},
    {"ofsf_qesubiord",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_qesubiord},
    {"get*real*irreducible*rep",too_few_2,      CC_getHrealHirreducibleHrep,wrong_no_2},
    {"ps:times:",               too_few_2,      CC_psTtimesT,  wrong_no_2},
    {"vdpfmon",                 too_few_2,      CC_vdpfmon,    wrong_no_2},
    {"xvarp",                   CC_xvarp,       too_many_1,    wrong_no_1},
    {"functionp",               CC_functionp,   too_many_1,    wrong_no_1},
    {"rdzchk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rdzchk},
    {"fctins",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_fctins},
    {"ev-tades",                too_few_2,      CC_evKtades,   wrong_no_2},
    {"compactf3",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf3},
    {"affinep",                 CC_affinep,     too_many_1,    wrong_no_1},
    {"x**p-w",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_xHHpKw},
    {"radd",                    too_few_2,      CC_radd,       wrong_no_2},
    {"random-teeny-prime",      CC_randomKteenyKprime,too_many_1,wrong_no_1},
    {"bfprin0",                 CC_bfprin0,     too_many_1,    wrong_no_1},
    {"opfchk!",                 CC_opfchkB,     too_many_1,    wrong_no_1},
    {"conjsq",                  CC_conjsq,      too_many_1,    wrong_no_1},
    {"repr_n",                  CC_repr_n,      too_many_1,    wrong_no_1},
    {"ratpoly_univarp",         CC_ratpoly_univarp,too_many_1, wrong_no_1},
    {NULL, (one_args *)"u42", (two_args *)"9472 9899542 3733922", 0}
};

/* end of generated code */
