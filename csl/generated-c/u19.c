
/* $destdir\u19.c        Machine generated C code */

/* Signature: 00000000 26-Mar-2013 */

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
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
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
extern intptr_t modulus_is_large;
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
extern Lisp_Object declare_symbol, special_symbol, large_modulus;
extern Lisp_Object used_space, avail_space;
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
#define modulus_is_large      BASE[32]
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
#define large_modulus         BASE[184]
#define used_space            BASE[185]
#define avail_space           BASE[186]
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
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
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
extern Lisp_Object bytecounts1(Lisp_Object env, Lisp_Object a);
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


/* Code for vintersection */

static Lisp_Object CC_vintersection(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0026;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vintersection");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0027:
    v0025 = stack[-1];
    if (v0025 == nil) goto v0028;
    v0025 = stack[-1];
    v0025 = qcar(v0025);
    v0026 = qcar(v0025);
    v0025 = stack[0];
    v0025 = Lassoc(nil, v0026, v0025);
    stack[-2] = v0025;
    if (v0025 == nil) goto v0029;
    v0025 = stack[-1];
    v0025 = qcar(v0025);
    v0026 = qcdr(v0025);
    v0025 = stack[-2];
    v0025 = qcdr(v0025);
    v0025 = (Lisp_Object)greaterp2(v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    v0025 = v0025 ? lisp_true : nil;
    env = stack[-3];
    if (v0025 == nil) goto v0031;
    v0025 = stack[-2];
    v0026 = qcdr(v0025);
    v0025 = (Lisp_Object)1; /* 0 */
    if (v0026 == v0025) goto v0032;
    v0025 = stack[-1];
    v0026 = qcdr(v0025);
    v0025 = stack[0];
    v0025 = CC_vintersection(env, v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    {
        Lisp_Object v0033 = stack[-2];
        popv(4);
        return cons(v0033, v0025);
    }

v0032:
    v0025 = stack[-1];
    v0026 = qcdr(v0025);
    v0025 = stack[0];
    stack[-1] = v0026;
    stack[0] = v0025;
    goto v0027;

v0031:
    v0025 = stack[-1];
    v0025 = qcar(v0025);
    v0026 = qcdr(v0025);
    v0025 = (Lisp_Object)1; /* 0 */
    if (v0026 == v0025) goto v0034;
    v0025 = stack[-1];
    stack[-2] = qcar(v0025);
    v0025 = stack[-1];
    v0026 = qcdr(v0025);
    v0025 = stack[0];
    v0025 = CC_vintersection(env, v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    {
        Lisp_Object v0035 = stack[-2];
        popv(4);
        return cons(v0035, v0025);
    }

v0034:
    v0025 = stack[-1];
    v0026 = qcdr(v0025);
    v0025 = stack[0];
    stack[-1] = v0026;
    stack[0] = v0025;
    goto v0027;

v0029:
    v0025 = stack[-1];
    v0026 = qcdr(v0025);
    v0025 = stack[0];
    stack[-1] = v0026;
    stack[0] = v0025;
    goto v0027;

v0028:
    v0025 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0025); }
/* error exit handlers */
v0030:
    popv(4);
    return nil;
}



/* Code for vdp_poly */

static Lisp_Object CC_vdp_poly(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0036;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_poly");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0036 = v0000;
/* end of prologue */
    v0036 = qcdr(v0036);
    v0036 = qcdr(v0036);
    v0036 = qcdr(v0036);
    v0036 = qcar(v0036);
    return onevalue(v0036);
}



/* Code for binaryrd */

static Lisp_Object MS_CDECL CC_binaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "binaryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for binaryrd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    fn = elt(env, 2); /* mathml */
    v0041 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    stack[-1] = v0041;
    fn = elt(env, 2); /* mathml */
    v0041 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    stack[0] = v0041;
    fn = elt(env, 3); /* lex */
    v0041 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    v0042 = stack[-1];
    v0041 = stack[0];
    v0017 = qvalue(elt(env, 1)); /* nil */
    popv(3);
    return list2star(v0042, v0041, v0017);
/* error exit handlers */
v0043:
    popv(3);
    return nil;
}



/* Code for wedgek2 */

static Lisp_Object MS_CDECL CC_wedgek2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0040, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0082, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "wedgek2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgek2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0040,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0040;
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */

v0084:
    v0082 = stack[-4];
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    if (v0082 == v0081) goto v0043;
    v0081 = qvalue(elt(env, 2)); /* nil */
    goto v0085;

v0085:
    if (v0081 == nil) goto v0008;
    v0081 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0082 = v0081;
    v0081 = v0082;
    v0081 = integerp(v0081);
    if (v0081 == nil) goto v0087;
    v0081 = v0082;
    v0081 = Loddp(nil, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    goto v0015;

v0015:
    if (v0081 == nil) goto v0088;
    v0081 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0081); }

v0088:
    v0082 = stack[-4];
    v0081 = stack[-3];
    v0081 = cons(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0081 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    {
        Lisp_Object v0089 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0089, v0081);
    }

v0087:
    v0081 = qvalue(elt(env, 2)); /* nil */
    goto v0015;

v0008:
    v0081 = stack[-3];
    v0082 = qcar(v0081);
    v0081 = elt(env, 1); /* wedge */
    if (!consp(v0082)) goto v0090;
    v0082 = qcar(v0082);
    if (!(v0082 == v0081)) goto v0090;
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    stack[-3] = v0081;
    goto v0084;

v0090:
    v0082 = stack[-4];
    v0081 = elt(env, 1); /* wedge */
    if (!consp(v0082)) goto v0091;
    v0082 = qcar(v0082);
    if (!(v0082 == v0081)) goto v0091;
    v0081 = stack[-4];
    v0082 = qcdr(v0081);
    v0081 = stack[-3];
    fn = elt(env, 7); /* wedgewedge */
    stack[0] = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0081 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    {
        Lisp_Object v0092 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0092, v0081);
    }

v0091:
    v0082 = stack[-4];
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    fn = elt(env, 8); /* worderp */
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    if (v0081 == nil) goto v0002;
    v0082 = stack[-4];
    v0081 = stack[-3];
    v0081 = cons(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0081 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    {
        Lisp_Object v0093 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0093, v0081);
    }

v0002:
    v0081 = stack[-3];
    v0081 = qcdr(v0081);
    if (v0081 == nil) goto v0094;
    v0081 = stack[-3];
    v0083 = qcar(v0081);
    v0082 = (Lisp_Object)17; /* 1 */
    v0081 = (Lisp_Object)17; /* 1 */
    v0081 = list2star(v0083, v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    stack[-5] = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    stack[-1] = stack[-4];
    v0081 = stack[-3];
    stack[0] = qcdr(v0081);
    v0081 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    stack[-4] = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    fn = elt(env, 3); /* deg!*form */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v0081 = (*qfn2(fn))(qenv(fn), stack[-4], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v0081 = (*qfn2(fn))(qenv(fn), stack[-2], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0081 = CC_wedgek2(env, 3, stack[-1], stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    {
        Lisp_Object v0095 = stack[-5];
        popv(7);
        fn = elt(env, 11); /* wedgepf2 */
        return (*qfn2(fn))(qenv(fn), v0095, v0081);
    }

v0094:
    v0081 = stack[-3];
    v0082 = qcar(v0081);
    v0081 = stack[-4];
    v0081 = list2(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    stack[-1] = stack[-2];
    v0081 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0081 = stack[-3];
    v0081 = qcar(v0081);
    fn = elt(env, 3); /* deg!*form */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v0081 = (*qfn2(fn))(qenv(fn), stack[-2], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v0081 = (*qfn2(fn))(qenv(fn), stack[-1], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    fn = elt(env, 5); /* mksgnsq */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    {
        Lisp_Object v0096 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0096, v0081);
    }

v0043:
    v0082 = stack[-4];
    v0081 = elt(env, 1); /* wedge */
    v0081 = Leqcar(nil, v0082, v0081);
    env = stack[-6];
    v0081 = (v0081 == nil ? lisp_true : nil);
    goto v0085;
/* error exit handlers */
v0086:
    popv(7);
    return nil;
}



/* Code for rd!:plus */

static Lisp_Object CC_rdTplus(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0120, v0121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:plus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0094 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v0094;
    v0094 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v0094 == nil) goto v0078;
    v0094 = qvalue(elt(env, 1)); /* nil */
    goto v0122;

v0122:
    if (v0094 == nil) goto v0123;
    v0120 = elt(env, 3); /* !:rd!: */
    v0094 = stack[-1];
    popv(5);
    return cons(v0120, v0094);

v0123:
    v0120 = stack[0];
    v0094 = stack[-2];
    fn = elt(env, 6); /* convprc2 */
    v0094 = (*qfn2(fn))(qenv(fn), v0120, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-3] = v0094;
    v0094 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v0094;
    v0094 = stack[-3];
    if (!consp(v0094)) goto v0090;
    v0120 = stack[-3];
    v0094 = stack[-2];
    fn = elt(env, 7); /* plubf */
    v0094 = (*qfn2(fn))(qenv(fn), v0120, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    goto v0074;

v0074:
    stack[0] = v0094;
    v0121 = stack[0];
    v0120 = stack[-3];
    v0094 = stack[-2];
    fn = elt(env, 8); /* rdzchk */
    v0094 = (*qfnn(fn))(qenv(fn), 3, v0121, v0120, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 9); /* mkround */
        return (*qfn1(fn))(qenv(fn), v0094);
    }

v0090:
    stack[-1] = elt(env, 5); /* plus2 */
    v0094 = stack[-3];
    stack[0] = Lmkquote(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    v0094 = stack[-2];
    v0094 = Lmkquote(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    v0120 = list3(stack[-1], stack[0], v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    v0094 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 10); /* errorset!* */
    v0094 = (*qfn2(fn))(qenv(fn), v0120, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-1] = v0094;
    v0094 = stack[-1];
    fn = elt(env, 11); /* errorp */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    if (v0094 == nil) goto v0124;
    fn = elt(env, 12); /* rndbfon */
    v0094 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    v0094 = stack[-3];
    v0094 = Lfloatp(nil, v0094);
    env = stack[-4];
    if (v0094 == nil) goto v0025;
    v0094 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[0] = v0094;
    goto v0091;

v0091:
    stack[-3] = stack[0];
    v0094 = stack[-2];
    v0094 = Lfloatp(nil, v0094);
    env = stack[-4];
    if (v0094 == nil) goto v0125;
    v0094 = stack[-2];
    fn = elt(env, 13); /* fl2bf */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    goto v0126;

v0126:
    stack[-2] = v0094;
    fn = elt(env, 7); /* plubf */
    v0094 = (*qfn2(fn))(qenv(fn), stack[0], v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    goto v0074;

v0125:
    v0094 = stack[-2];
    if (!consp(v0094)) goto v0127;
    v0094 = stack[-2];
    goto v0062;

v0062:
    fn = elt(env, 14); /* csl_normbf */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    goto v0126;

v0127:
    v0094 = stack[-2];
    v0094 = integerp(v0094);
    if (v0094 == nil) goto v0128;
    v0121 = elt(env, 3); /* !:rd!: */
    v0120 = stack[-2];
    v0094 = (Lisp_Object)1; /* 0 */
    v0094 = list2star(v0121, v0120, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    goto v0062;

v0128:
    v0094 = stack[-2];
    fn = elt(env, 15); /* read!:num */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    goto v0062;

v0025:
    v0094 = stack[-3];
    if (!consp(v0094)) goto v0033;
    v0094 = stack[-3];
    goto v0129;

v0129:
    fn = elt(env, 14); /* csl_normbf */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[0] = v0094;
    goto v0091;

v0033:
    v0094 = stack[-3];
    v0094 = integerp(v0094);
    if (v0094 == nil) goto v0130;
    v0121 = elt(env, 3); /* !:rd!: */
    v0120 = stack[-3];
    v0094 = (Lisp_Object)1; /* 0 */
    v0094 = list2star(v0121, v0120, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    goto v0129;

v0130:
    v0094 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    goto v0129;

v0124:
    v0094 = stack[-1];
    v0094 = qcar(v0094);
    goto v0074;

v0078:
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    if (!consp(v0094)) goto v0038;
    v0094 = qvalue(elt(env, 1)); /* nil */
    goto v0122;

v0038:
    v0094 = stack[-2];
    v0094 = qcdr(v0094);
    if (!consp(v0094)) goto v0131;
    v0094 = qvalue(elt(env, 1)); /* nil */
    goto v0122;

v0131:
    v0094 = stack[0];
    v0120 = qcdr(v0094);
    v0094 = stack[-2];
    v0094 = qcdr(v0094);
    fn = elt(env, 16); /* safe!-fp!-plus */
    v0094 = (*qfn2(fn))(qenv(fn), v0120, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-1] = v0094;
    goto v0122;
/* error exit handlers */
v0051:
    popv(5);
    return nil;
}



/* Code for opmtchrevop */

static Lisp_Object CC_opmtchrevop(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0134, v0135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opmtchrevop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0134 = qvalue(elt(env, 1)); /* !*val */
    if (v0134 == nil) goto v0028;
    v0135 = elt(env, 3); /* cons */
    v0134 = stack[0];
    v0134 = Lsmemq(nil, v0135, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    goto v0036;

v0036:
    if (v0134 == nil) goto v0136;
    v0134 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v0134);
    }

v0136:
    v0134 = stack[0];
    stack[-1] = qcar(v0134);
    v0134 = stack[0];
    v0134 = qcdr(v0134);
    fn = elt(env, 5); /* revlis */
    v0134 = (*qfn1(fn))(qenv(fn), v0134);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    v0134 = cons(stack[-1], v0134);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v0134);
    }

v0028:
    v0134 = qvalue(elt(env, 2)); /* t */
    goto v0036;
/* error exit handlers */
v0076:
    popv(3);
    return nil;
}



/* Code for contr */

static Lisp_Object CC_contr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0133;

v0133:
    v0132 = stack[0];
    if (v0132 == nil) goto v0116;
    v0119 = stack[-1];
    v0132 = stack[0];
    v0132 = qcar(v0132);
    fn = elt(env, 1); /* split!-road */
    v0119 = (*qfn2(fn))(qenv(fn), v0119, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-3];
    v0132 = stack[-2];
    v0132 = cons(v0119, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-3];
    stack[-2] = v0132;
    v0132 = stack[0];
    v0132 = qcdr(v0132);
    stack[0] = v0132;
    goto v0133;

v0116:
    v0132 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0132);
    }
/* error exit handlers */
v0135:
    popv(4);
    return nil;
}



/* Code for no!-side!-effect!-listp */

static Lisp_Object CC_noKsideKeffectKlistp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for no-side-effect-listp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0027:
    v0137 = stack[0];
    if (v0137 == nil) goto v0101;
    v0137 = stack[0];
    v0137 = qcar(v0137);
    fn = elt(env, 3); /* no!-side!-effectp */
    v0137 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-1];
    if (v0137 == nil) goto v0085;
    v0137 = stack[0];
    v0137 = qcdr(v0137);
    stack[0] = v0137;
    goto v0027;

v0085:
    v0137 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0137); }

v0101:
    v0137 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0137); }
/* error exit handlers */
v0029:
    popv(2);
    return nil;
}



/* Code for setelv */

static Lisp_Object CC_setelv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0138, v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setelv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0001;
    v0072 = v0000;
/* end of prologue */
    v0138 = v0072;
    stack[-5] = qcar(v0138);
    v0138 = v0072;
    v0138 = qcdr(v0138);
    stack[-3] = v0138;
    v0138 = stack[-3];
    if (v0138 == nil) goto v0131;
    v0138 = stack[-3];
    v0138 = qcar(v0138);
    fn = elt(env, 2); /* reval_without_mod */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-6];
    v0138 = ncons(v0138);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-6];
    stack[-1] = v0138;
    stack[-2] = v0138;
    goto v0018;

v0018:
    v0138 = stack[-3];
    v0138 = qcdr(v0138);
    stack[-3] = v0138;
    v0138 = stack[-3];
    if (v0138 == nil) goto v0077;
    stack[0] = stack[-1];
    v0138 = stack[-3];
    v0138 = qcar(v0138);
    fn = elt(env, 2); /* reval_without_mod */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-6];
    v0138 = ncons(v0138);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-6];
    v0138 = Lrplacd(nil, stack[0], v0138);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-6];
    v0138 = stack[-1];
    v0138 = qcdr(v0138);
    stack[-1] = v0138;
    goto v0018;

v0077:
    v0138 = stack[-2];
    goto v0139;

v0139:
    v0072 = cons(stack[-5], v0138);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-6];
    v0138 = stack[-4];
    {
        popv(7);
        fn = elt(env, 3); /* setel */
        return (*qfn2(fn))(qenv(fn), v0072, v0138);
    }

v0131:
    v0138 = qvalue(elt(env, 1)); /* nil */
    goto v0139;
/* error exit handlers */
v0074:
    popv(7);
    return nil;
}



/* Code for mo_equal!? */

static Lisp_Object CC_mo_equalW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_equal?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0084 = v0000;
/* end of prologue */
    v0084 = qcar(v0084);
    fn = elt(env, 1); /* mo!=shorten */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-2];
    v0084 = stack[0];
    v0084 = qcar(v0084);
    fn = elt(env, 1); /* mo!=shorten */
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    v0084 = (equal(stack[-1], v0084) ? lisp_true : nil);
    { popv(3); return onevalue(v0084); }
/* error exit handlers */
v0039:
    popv(3);
    return nil;
}



/* Code for b!:ordexp */

static Lisp_Object CC_bTordexp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0087;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:ordexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0140:
    v0015 = stack[-1];
    if (v0015 == nil) goto v0028;
    v0015 = stack[-1];
    v0087 = qcar(v0015);
    v0015 = stack[0];
    v0015 = qcar(v0015);
    v0015 = (Lisp_Object)greaterp2(v0087, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    v0015 = v0015 ? lisp_true : nil;
    env = stack[-2];
    if (v0015 == nil) goto v0131;
    v0015 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0015); }

v0131:
    v0015 = stack[-1];
    v0087 = qcar(v0015);
    v0015 = stack[0];
    v0015 = qcar(v0015);
    if (equal(v0087, v0015)) goto v0029;
    v0015 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0015); }

v0029:
    v0015 = stack[-1];
    v0015 = qcdr(v0015);
    stack[-1] = v0015;
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    stack[0] = v0015;
    goto v0140;

v0028:
    v0015 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0015); }
/* error exit handlers */
v0141:
    popv(3);
    return nil;
}



/* Code for resimpf */

static Lisp_Object CC_resimpf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0139, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0117 = v0000;
/* end of prologue */
    v0139 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0139; /* varstack!* */
    v0139 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* subf1 */
    v0139 = (*qfn2(fn))(qenv(fn), v0117, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-1];
    v0139 = qcar(v0139);
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v0139); }
/* error exit handlers */
v0038:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for innprodkp */

static Lisp_Object MS_CDECL CC_innprodkp(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0040, Lisp_Object v0012, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0013, v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "innprodkp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for innprodkp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0012,v0040,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0040,v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0012;
    stack[-1] = v0040;
    stack[-2] = v0001;
    v0013 = v0000;
/* end of prologue */

v0036:
    v0099 = stack[-1];
    if (v0099 == nil) goto v0122;
    v0014 = stack[-2];
    v0099 = stack[-1];
    v0099 = qcar(v0099);
    if (equal(v0014, v0099)) goto v0132;
    v0099 = stack[-1];
    v0099 = qcar(v0099);
    v0099 = cons(v0099, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-3];
    v0013 = v0099;
    v0099 = stack[-1];
    v0099 = qcdr(v0099);
    stack[-1] = v0099;
    v0099 = stack[0];
    v0099 = (v0099 == nil ? lisp_true : nil);
    stack[0] = v0099;
    goto v0036;

v0132:
    v0099 = stack[-1];
    v0099 = qcdr(v0099);
    fn = elt(env, 2); /* reversip2 */
    v0099 = (*qfn2(fn))(qenv(fn), v0013, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    {
        Lisp_Object v0072 = stack[0];
        popv(4);
        return cons(v0072, v0099);
    }

v0122:
    v0099 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0099); }
/* error exit handlers */
v0138:
    popv(4);
    return nil;
}



/* Code for outref */

static Lisp_Object MS_CDECL CC_outref(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0040, Lisp_Object v0012, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0003, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "outref");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for outref");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0012,v0040,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0040,v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0012;
    stack[-6] = v0040;
    stack[-7] = v0001;
    stack[-8] = v0000;
/* end of prologue */
    stack[-9] = qvalue(elt(env, 1)); /* curfun!* */
    qvalue(elt(env, 1)) = nil; /* curfun!* */
    stack[-4] = qvalue(elt(env, 2)); /* calls!* */
    qvalue(elt(env, 2)) = nil; /* calls!* */
    stack[-3] = qvalue(elt(env, 3)); /* globs!* */
    qvalue(elt(env, 3)) = nil; /* globs!* */
    stack[-2] = qvalue(elt(env, 4)); /* locls!* */
    qvalue(elt(env, 4)) = nil; /* locls!* */
    stack[-1] = qvalue(elt(env, 5)); /* toplv!* */
    qvalue(elt(env, 5)) = nil; /* toplv!* */
    v0003 = stack[-7];
    v0151 = elt(env, 6); /* (anp!!atom anp!!idb anp!!eq anp!!unknown) */
    v0151 = Lmemq(nil, v0003, v0151);
    if (v0151 == nil) goto v0152;
    v0151 = qvalue(elt(env, 7)); /* nil */
    goto v0117;

v0117:
    stack[0] = v0151;
    v0002 = stack[-8];
    v0003 = stack[-5];
    v0151 = stack[0];
    if (v0151 == nil) goto v0153;
    v0151 = stack[0];
    goto v0154;

v0154:
    fn = elt(env, 12); /* outrdefun */
    v0151 = (*qfnn(fn))(qenv(fn), 3, v0002, v0003, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-10];
    stack[-8] = v0151;
    v0151 = stack[0];
    if (v0151 == nil) goto v0156;
    v0151 = stack[-7];
    fn = elt(env, 13); /* add2locs */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-10];
    v0151 = stack[-6];
    fn = elt(env, 14); /* anform */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-10];
    v0151 = stack[-7];
    fn = elt(env, 15); /* remlocs */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-10];
    goto v0115;

v0115:
    v0151 = stack[-8];
    fn = elt(env, 16); /* outrefend */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-10];
    v0151 = nil;
    qvalue(elt(env, 5)) = stack[-1]; /* toplv!* */
    qvalue(elt(env, 4)) = stack[-2]; /* locls!* */
    qvalue(elt(env, 3)) = stack[-3]; /* globs!* */
    qvalue(elt(env, 2)) = stack[-4]; /* calls!* */
    qvalue(elt(env, 1)) = stack[-9]; /* curfun!* */
    { popv(11); return onevalue(v0151); }

v0156:
    v0151 = stack[-6];
    if (v0151 == nil) goto v0022;
    v0151 = stack[-6];
    v0151 = Lsymbolp(nil, v0151);
    env = stack[-10];
    v0151 = (v0151 == nil ? lisp_true : nil);
    goto v0088;

v0088:
    if (!(v0151 == nil)) goto v0115;
    v0003 = stack[-7];
    v0151 = elt(env, 9); /* anp!!eq */
    if (v0003 == v0151) goto v0157;
    v0151 = stack[-6];
    fn = elt(env, 17); /* add2calls */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-10];
    goto v0115;

v0157:
    stack[-5] = stack[-8];
    stack[0] = elt(env, 10); /* sameas */
    v0151 = stack[-6];
    v0151 = ncons(v0151);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-10];
    v0151 = Lputprop(nil, 3, stack[-5], stack[0], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-10];
    v0002 = stack[-6];
    v0003 = elt(env, 11); /* alsois */
    v0151 = stack[-8];
    fn = elt(env, 18); /* traput */
    v0151 = (*qfnn(fn))(qenv(fn), 3, v0002, v0003, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-10];
    goto v0115;

v0022:
    v0151 = qvalue(elt(env, 8)); /* t */
    goto v0088;

v0153:
    v0151 = stack[-6];
    if (!symbolp(v0151)) v0151 = nil;
    else { v0151 = qfastgets(v0151);
           if (v0151 != nil) { v0151 = elt(v0151, 42); /* number!-of!-args 
*/
#ifdef RECORD_GET
             if (v0151 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v0151 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v0151 == SPID_NOPROP) v0151 = nil; }}
#endif
    goto v0154;

v0152:
    v0151 = stack[-7];
    v0151 = Llength(nil, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-10];
    goto v0117;
/* error exit handlers */
v0155:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[-1]; /* toplv!* */
    qvalue(elt(env, 4)) = stack[-2]; /* locls!* */
    qvalue(elt(env, 3)) = stack[-3]; /* globs!* */
    qvalue(elt(env, 2)) = stack[-4]; /* calls!* */
    qvalue(elt(env, 1)) = stack[-9]; /* curfun!* */
    popv(11);
    return nil;
}



/* Code for ofsf_sippsubst */

static Lisp_Object CC_ofsf_sippsubst(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sippsubst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0042 = v0001;
    v0017 = v0000;
/* end of prologue */
    v0041 = v0042;
    if (v0041 == nil) return onevalue(v0017);
    v0041 = v0017;
    {
        fn = elt(env, 1); /* ofsf_sippsubst1 */
        return (*qfn2(fn))(qenv(fn), v0041, v0042);
    }
}



/* Code for triplesetprolongset */

static Lisp_Object CC_triplesetprolongset(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0134, v0135;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for triplesetprolongset");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0135 = nil;
    goto v0028;

v0028:
    v0134 = stack[0];
    if (v0134 == nil) goto v0079;
    v0134 = stack[0];
    v0134 = qcar(v0134);
    v0134 = cons(v0134, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    v0135 = v0134;
    v0134 = stack[0];
    v0134 = qcdr(v0134);
    stack[0] = v0134;
    goto v0028;

v0079:
    stack[0] = (Lisp_Object)49; /* 3 */
    v0134 = v0135;
    v0134 = Lreverse(nil, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0134;
    v0134 = nil;
    { popv(3); return onevalue(v0134); }
/* error exit handlers */
v0076:
    popv(3);
    return nil;
}



/* Code for kernord!-split */

static Lisp_Object CC_kernordKsplit(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0102, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernord-split");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-1] = nil;
    v0002 = stack[-3];
    fn = elt(env, 2); /* powers */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-5];
    stack[-3] = v0002;
    v0002 = stack[-2];
    fn = elt(env, 2); /* powers */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-5];
    stack[-2] = v0002;
    v0002 = stack[-3];
    stack[0] = v0002;
    goto v0117;

v0117:
    v0002 = stack[0];
    if (v0002 == nil) goto v0139;
    v0002 = stack[0];
    v0002 = qcar(v0002);
    v0091 = v0002;
    v0002 = v0091;
    v0102 = qcar(v0002);
    v0002 = stack[-2];
    v0002 = Lassoc(nil, v0102, v0002);
    if (v0002 == nil) goto v0142;
    v0102 = v0091;
    v0002 = stack[-1];
    v0002 = cons(v0102, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-5];
    stack[-1] = v0002;
    goto v0152;

v0152:
    v0002 = stack[0];
    v0002 = qcdr(v0002);
    stack[0] = v0002;
    goto v0117;

v0142:
    v0102 = v0091;
    v0002 = stack[-4];
    v0002 = cons(v0102, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-5];
    stack[-4] = v0002;
    goto v0152;

v0139:
    v0002 = stack[-2];
    stack[0] = v0002;
    goto v0138;

v0138:
    v0002 = stack[0];
    if (v0002 == nil) goto v0146;
    v0002 = stack[0];
    v0002 = qcar(v0002);
    v0091 = v0002;
    v0002 = v0091;
    v0102 = qcar(v0002);
    v0002 = stack[-3];
    v0002 = Lassoc(nil, v0102, v0002);
    if (v0002 == nil) goto v0070;
    v0102 = v0091;
    v0002 = stack[-1];
    v0002 = cons(v0102, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-5];
    stack[-1] = v0002;
    goto v0162;

v0162:
    v0002 = stack[0];
    v0002 = qcdr(v0002);
    stack[0] = v0002;
    goto v0138;

v0070:
    v0102 = v0091;
    v0002 = stack[-4];
    v0002 = cons(v0102, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-5];
    stack[-4] = v0002;
    goto v0162;

v0146:
    v0002 = stack[-4];
    v0102 = Lnreverse(nil, v0002);
    env = stack[-5];
    v0002 = stack[-1];
    v0002 = Lnreverse(nil, v0002);
    popv(6);
    return cons(v0102, v0002);
/* error exit handlers */
v0005:
    popv(6);
    return nil;
}



/* Code for mk!+unit!+mat */

static Lisp_Object CC_mkLunitLmat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+unit+mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0133 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* gen!+can!+bas */
        return (*qfn1(fn))(qenv(fn), v0133);
    }
}



/* Code for lx2xx */

static Lisp_Object CC_lx2xx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0164, v0165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lx2xx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    v0164 = stack[-2];
    if (!consp(v0164)) goto v0038;
    v0164 = stack[-2];
    v0164 = qcar(v0164);
    v0164 = (consp(v0164) ? nil : lisp_true);
    goto v0084;

v0084:
    if (v0164 == nil) goto v0152;
    v0164 = qvalue(elt(env, 1)); /* t */
    goto v0078;

v0078:
    if (!(v0164 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0164 = stack[-2];
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    stack[-3] = v0164;
    v0164 = stack[-3];
    fn = elt(env, 2); /* lastnondomain */
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    v0164 = qcdr(v0164);
    stack[-1] = v0164;
    v0164 = stack[-2];
    stack[0] = qcar(v0164);
    v0165 = stack[-1];
    v0164 = stack[-3];
    fn = elt(env, 3); /* delet */
    v0164 = (*qfn2(fn))(qenv(fn), v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    fn = elt(env, 4); /* xxsort */
    v0165 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-4];
    v0164 = stack[-1];
    v0165 = Lappend(nil, v0165, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    v0164 = stack[-2];
    v0164 = qcdr(v0164);
    v0164 = qcdr(v0164);
    {
        Lisp_Object v0011 = stack[0];
        popv(5);
        return list2star(v0011, v0165, v0164);
    }

v0152:
    v0164 = stack[-2];
    v0164 = qcar(v0164);
    if (!consp(v0164)) goto v0080;
    v0164 = stack[-2];
    v0164 = qcar(v0164);
    v0164 = qcar(v0164);
    v0164 = (consp(v0164) ? nil : lisp_true);
    goto v0078;

v0080:
    v0164 = qvalue(elt(env, 1)); /* t */
    goto v0078;

v0038:
    v0164 = qvalue(elt(env, 1)); /* t */
    goto v0084;
/* error exit handlers */
v0010:
    popv(5);
    return nil;
}



/* Code for unaryir */

static Lisp_Object CC_unaryir(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unaryir");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0150 = qvalue(elt(env, 1)); /* atts */
    v0135 = elt(env, 2); /* name */
    fn = elt(env, 4); /* find */
    v0135 = (*qfn2(fn))(qenv(fn), v0150, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-3];
    v0135 = Lintern(nil, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-3];
    stack[-2] = v0135;
    v0150 = qvalue(elt(env, 1)); /* atts */
    v0135 = elt(env, 3); /* cd */
    fn = elt(env, 4); /* find */
    v0135 = (*qfn2(fn))(qenv(fn), v0150, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-3];
    v0135 = Lintern(nil, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-3];
    v0150 = v0135;
    v0135 = stack[-1];
    if (equal(v0150, v0135)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0135 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* encodeir */
        return (*qfn1(fn))(qenv(fn), v0135);
    }
/* error exit handlers */
v0087:
    popv(4);
    return nil;
}



/* Code for prinlatom */

static Lisp_Object CC_prinlatom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prinlatom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0075 = stack[-1];
    v0074 = elt(env, 1); /* font */
    v0074 = get(v0075, v0074);
    env = stack[-3];
    stack[-2] = v0074;
    if (v0074 == nil) goto v0152;
    v0074 = stack[-2];
    fn = elt(env, 5); /* prin2la */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    goto v0152;

v0152:
    v0075 = stack[-1];
    v0074 = elt(env, 2); /* accent */
    v0074 = get(v0075, v0074);
    env = stack[-3];
    stack[0] = v0074;
    if (v0074 == nil) goto v0150;
    v0074 = stack[0];
    fn = elt(env, 5); /* prin2la */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    goto v0150;

v0150:
    v0075 = stack[-1];
    v0074 = elt(env, 3); /* name */
    v0074 = get(v0075, v0074);
    env = stack[-3];
    v0075 = v0074;
    if (v0074 == nil) goto v0142;
    v0074 = v0075;
    fn = elt(env, 5); /* prin2la */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    goto v0154;

v0154:
    v0074 = stack[0];
    if (v0074 == nil) goto v0099;
    v0074 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    goto v0099;

v0099:
    v0074 = stack[-2];
    if (v0074 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0074 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0142:
    v0074 = stack[-1];
    fn = elt(env, 6); /* testchar1 */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    fn = elt(env, 5); /* prin2la */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    goto v0154;
/* error exit handlers */
v0166:
    popv(4);
    return nil;
}



/* Code for physopordchk */

static Lisp_Object CC_physopordchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0160, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopordchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0014 = v0000;
/* end of prologue */
    fn = elt(env, 4); /* !*collectphysops */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    stack[-1] = v0014;
    v0014 = stack[0];
    fn = elt(env, 4); /* !*collectphysops */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    v0032 = v0014;
    v0014 = stack[-1];
    if (v0014 == nil) goto v0039;
    v0014 = v0032;
    if (v0014 == nil) goto v0018;
    v0160 = elt(env, 3); /* unit */
    v0014 = stack[-1];
    v0014 = Lmember(nil, v0160, v0014);
    if (!(v0014 == nil)) goto v0152;
    v0160 = elt(env, 3); /* unit */
    v0014 = v0032;
    v0014 = Lmember(nil, v0160, v0014);
    if (!(v0014 == nil)) goto v0152;
    v0014 = stack[-1];
    v0160 = v0032;
    {
        popv(3);
        fn = elt(env, 6); /* physopordchk!* */
        return (*qfn2(fn))(qenv(fn), v0014, v0160);
    }

v0152:
    v0014 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0014); }

v0018:
    v0014 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0014); }

v0039:
    v0014 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0014); }
/* error exit handlers */
v0072:
    popv(3);
    return nil;
}



/* Code for red_totalred */

static Lisp_Object CC_red_totalred(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_totalred");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0039 = v0001;
    v0041 = v0000;
/* end of prologue */
    stack[0] = v0041;
    fn = elt(env, 1); /* red_topred */
    v0039 = (*qfn2(fn))(qenv(fn), v0041, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    {
        Lisp_Object v0018 = stack[0];
        popv(2);
        fn = elt(env, 2); /* red_tailred */
        return (*qfn2(fn))(qenv(fn), v0018, v0039);
    }
/* error exit handlers */
v0017:
    popv(2);
    return nil;
}



/* Code for repeats */

static Lisp_Object CC_repeats(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0150, v0077, v0076;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repeats");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0076 = nil;
    goto v0140;

v0140:
    v0150 = stack[0];
    if (v0150 == nil) goto v0028;
    v0150 = stack[0];
    v0077 = qcar(v0150);
    v0150 = stack[0];
    v0150 = qcdr(v0150);
    v0150 = Lmember(nil, v0077, v0150);
    if (v0150 == nil) goto v0154;
    v0150 = stack[0];
    v0150 = qcar(v0150);
    v0077 = v0076;
    v0150 = cons(v0150, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-1];
    v0076 = v0150;
    v0150 = stack[0];
    v0150 = qcdr(v0150);
    stack[0] = v0150;
    goto v0140;

v0154:
    v0150 = stack[0];
    v0150 = qcdr(v0150);
    stack[0] = v0150;
    goto v0140;

v0028:
    v0150 = v0076;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0150);
    }
/* error exit handlers */
v0087:
    popv(2);
    return nil;
}



/* Code for subf1 */

static Lisp_Object CC_subf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0266, v0267, v0268;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-9] = v0001;
    stack[-10] = v0000;
/* end of prologue */
    v0266 = stack[-10];
    if (v0266 == nil) goto v0116;
    v0266 = stack[-10];
    if (!consp(v0266)) goto v0042;
    v0266 = stack[-10];
    v0266 = qcar(v0266);
    v0266 = (consp(v0266) ? nil : lisp_true);
    goto v0041;

v0041:
    if (v0266 == nil) goto v0011;
    v0266 = stack[-10];
    if (!consp(v0266)) goto v0024;
    v0267 = qvalue(elt(env, 3)); /* dmode!* */
    v0266 = stack[-10];
    v0266 = qcar(v0266);
    if (v0267 == v0266) goto v0021;
    v0266 = qvalue(elt(env, 1)); /* nil */
    goto v0161;

v0161:
    if (v0266 == nil) goto v0112;
    v0266 = stack[-10];
    {
        popv(14);
        fn = elt(env, 13); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v0266);
    }

v0112:
    v0266 = stack[-10];
    fn = elt(env, 14); /* prepf */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-13];
    {
        popv(14);
        fn = elt(env, 15); /* simp */
        return (*qfn1(fn))(qenv(fn), v0266);
    }

v0021:
    v0267 = qvalue(elt(env, 3)); /* dmode!* */
    v0266 = elt(env, 4); /* resimplify */
    v0266 = Lflagp(nil, v0267, v0266);
    env = stack[-13];
    v0266 = (v0266 == nil ? lisp_true : nil);
    goto v0161;

v0024:
    v0266 = qvalue(elt(env, 3)); /* dmode!* */
    if (v0266 == nil) goto v0150;
    v0266 = stack[-10];
    {
        popv(14);
        fn = elt(env, 16); /* simpatom */
        return (*qfn1(fn))(qenv(fn), v0266);
    }

v0150:
    v0267 = stack[-10];
    v0266 = (Lisp_Object)17; /* 1 */
    popv(14);
    return cons(v0267, v0266);

v0011:
    stack[-7] = qvalue(elt(env, 5)); /* varstack!* */
    qvalue(elt(env, 5)) = nil; /* varstack!* */
    stack[-1] = nil;
    stack[-4] = nil;
    v0266 = (Lisp_Object)1; /* 0 */
    stack[-11] = v0266;
    v0267 = qvalue(elt(env, 1)); /* nil */
    v0266 = (Lisp_Object)17; /* 1 */
    v0266 = cons(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-3] = v0266;
    goto v0158;

v0158:
    v0266 = stack[-10];
    v0266 = qcar(v0266);
    v0266 = qcar(v0266);
    v0266 = qcar(v0266);
    stack[-12] = v0266;
    v0266 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0266;
    v0267 = stack[-12];
    v0266 = stack[-9];
    v0266 = Lassoc(nil, v0267, v0266);
    if (v0266 == nil) goto v0052;
    v0267 = stack[-12];
    v0266 = qvalue(elt(env, 6)); /* wtl!* */
    v0266 = Lassoc(nil, v0267, v0266);
    stack[0] = v0266;
    if (v0266 == nil) goto v0052;
    v0266 = stack[0];
    v0266 = qcdr(v0266);
    stack[0] = v0266;
    goto v0052;

v0052:
    v0267 = stack[-12];
    v0266 = qvalue(elt(env, 7)); /* asymplis!* */
    v0266 = Lassoc(nil, v0267, v0266);
    stack[-8] = v0266;
    if (v0266 == nil) goto v0109;
    v0266 = stack[-8];
    v0266 = qcdr(v0266);
    stack[-8] = v0266;
    goto v0109;

v0109:
    v0266 = stack[-10];
    if (v0266 == nil) goto v0271;
    v0267 = stack[-10];
    v0266 = stack[-12];
    fn = elt(env, 17); /* degr */
    v0267 = (*qfn2(fn))(qenv(fn), v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-11] = v0267;
    v0266 = (Lisp_Object)1; /* 0 */
    v0266 = (v0267 == v0266 ? lisp_true : nil);
    goto v0272;

v0272:
    if (v0266 == nil) goto v0053;
    v0266 = qvalue(elt(env, 1)); /* nil */
    v0268 = v0266;
    goto v0049;

v0049:
    v0266 = stack[-9];
    if (v0266 == nil) goto v0273;
    v0266 = stack[-9];
    v0266 = qcar(v0266);
    v0267 = qcar(v0266);
    v0266 = stack[-9];
    v0266 = qcar(v0266);
    v0266 = qcdr(v0266);
    if (equal(v0267, v0266)) goto v0274;
    v0266 = stack[-9];
    v0266 = qcar(v0266);
    v0267 = v0268;
    v0266 = cons(v0266, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0268 = v0266;
    goto v0274;

v0274:
    v0266 = stack[-9];
    v0266 = qcdr(v0266);
    stack[-9] = v0266;
    goto v0049;

v0273:
    v0266 = v0268;
    v0266 = Lnreverse(nil, v0266);
    env = stack[-13];
    stack[-9] = v0266;
    v0266 = stack[-12];
    if (!consp(v0266)) goto v0275;
    v0266 = stack[-12];
    v0266 = qcar(v0266);
    v0266 = (consp(v0266) ? nil : lisp_true);
    v0266 = (v0266 == nil ? lisp_true : nil);
    goto v0276;

v0276:
    if (v0266 == nil) goto v0277;
    v0266 = stack[-12];
    fn = elt(env, 14); /* prepf */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-12] = v0266;
    goto v0277;

v0277:
    v0266 = stack[-9];
    if (v0266 == nil) goto v0278;
    v0267 = stack[-9];
    v0266 = stack[-12];
    fn = elt(env, 18); /* subsublis */
    v0267 = (*qfn2(fn))(qenv(fn), v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-2] = v0267;
    v0266 = stack[-12];
    if (equal(v0267, v0266)) goto v0279;
    v0266 = qvalue(elt(env, 1)); /* nil */
    goto v0280;

v0280:
    if (!(v0266 == nil)) goto v0146;

v0281:
    v0267 = (Lisp_Object)17; /* 1 */
    v0266 = (Lisp_Object)17; /* 1 */
    v0266 = cons(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-6] = v0266;
    v0266 = (Lisp_Object)1; /* 0 */
    stack[-11] = v0266;
    v0266 = stack[-1];
    if (v0266 == nil) goto v0282;
    v0266 = stack[-1];
    v0266 = qcar(v0266);
    v0266 = qcar(v0266);
    v0266 = qcdr(v0266);
    v0266 = Lminusp(nil, v0266);
    env = stack[-13];
    if (v0266 == nil) goto v0282;
    v0266 = stack[-2];
    v0266 = ncons(v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    fn = elt(env, 19); /* simprecip */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-5] = v0266;
    goto v0283;

v0283:
    v0266 = stack[-1];
    v0267 = qcar(v0266);
    v0266 = stack[-4];
    v0266 = cons(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-4] = v0266;
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    stack[-1] = v0266;
    v0266 = stack[-1];
    if (v0266 == nil) goto v0284;
    v0266 = stack[-1];
    v0266 = qcar(v0266);
    v0266 = qcar(v0266);
    v0267 = qcdr(v0266);
    v0266 = (Lisp_Object)1; /* 0 */
    v0266 = (Lisp_Object)lessp2(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    v0266 = v0266 ? lisp_true : nil;
    env = stack[-13];
    if (!(v0266 == nil)) goto v0283;

v0284:
    v0266 = stack[-4];
    v0266 = qcar(v0266);
    v0266 = qcar(v0266);
    v0266 = qcdr(v0266);
    v0266 = negate(v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-8] = v0266;
    stack[0] = stack[-5];
    v0267 = stack[-8];
    v0266 = stack[-11];
    v0266 = difference2(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    fn = elt(env, 20); /* exptsq */
    v0266 = (*qfn2(fn))(qenv(fn), stack[0], v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    fn = elt(env, 21); /* subs2 */
    v0267 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = stack[-6];
    fn = elt(env, 22); /* multsq */
    v0266 = (*qfn2(fn))(qenv(fn), v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-6] = v0266;
    v0266 = stack[-8];
    stack[-11] = v0266;
    stack[0] = stack[-6];
    v0266 = stack[-4];
    v0266 = qcar(v0266);
    v0267 = qcdr(v0266);
    v0266 = stack[-9];
    v0266 = CC_subf1(env, v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    fn = elt(env, 22); /* multsq */
    v0267 = (*qfn2(fn))(qenv(fn), stack[0], v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = stack[-3];
    fn = elt(env, 23); /* addsq */
    v0266 = (*qfn2(fn))(qenv(fn), v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-3] = v0266;
    v0266 = stack[-4];
    v0266 = qcdr(v0266);
    stack[-4] = v0266;
    v0266 = stack[-4];
    if (!(v0266 == nil)) goto v0284;
    v0266 = stack[-1];
    if (!(v0266 == nil)) goto v0281;

v0145:
    v0266 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v0266;
    v0266 = stack[-10];
    if (v0266 == nil) goto v0285;
    v0266 = stack[-10];
    if (!consp(v0266)) goto v0286;
    v0266 = stack[-10];
    v0266 = qcar(v0266);
    v0266 = (consp(v0266) ? nil : lisp_true);
    goto v0287;

v0287:
    if (v0266 == nil) goto v0158;
    v0267 = stack[-10];
    v0266 = stack[-9];
    v0267 = CC_subf1(env, v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = stack[-3];
    fn = elt(env, 23); /* addsq */
    v0266 = (*qfn2(fn))(qenv(fn), v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    goto v0111;

v0111:
    qvalue(elt(env, 5)) = stack[-7]; /* varstack!* */
    { popv(14); return onevalue(v0266); }

v0286:
    v0266 = qvalue(elt(env, 2)); /* t */
    goto v0287;

v0285:
    v0266 = stack[-3];
    goto v0111;

v0282:
    v0266 = stack[-2];
    fn = elt(env, 24); /* getrtype */
    v0267 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-5] = v0267;
    v0266 = elt(env, 9); /* yetunknowntype */
    if (!(v0267 == v0266)) goto v0288;
    v0267 = stack[-2];
    v0266 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 25); /* eval!-yetunknowntypeexpr */
    v0266 = (*qfn2(fn))(qenv(fn), v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-2] = v0266;
    fn = elt(env, 24); /* getrtype */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-5] = v0266;
    goto v0288;

v0288:
    v0266 = stack[-5];
    if (v0266 == nil) goto v0289;
    v0267 = stack[-5];
    v0266 = elt(env, 10); /* list */
    if (v0267 == v0266) goto v0289;
    v0267 = stack[-5];
    v0266 = stack[-2];
    v0267 = list2(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = elt(env, 11); /* "substituted expression" */
    fn = elt(env, 26); /* typerr */
    v0266 = (*qfn2(fn))(qenv(fn), v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    goto v0289;

v0289:
    v0266 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 27); /* setkorder */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[0] = v0266;
    v0266 = stack[-2];
    fn = elt(env, 15); /* simp */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-5] = v0266;
    v0266 = stack[0];
    fn = elt(env, 27); /* setkorder */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = stack[-5];
    fn = elt(env, 28); /* reordsq */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-5] = v0266;
    v0266 = stack[-9];
    if (v0266 == nil) goto v0290;
    v0266 = qvalue(elt(env, 1)); /* nil */
    goto v0291;

v0291:
    if (!(v0266 == nil)) goto v0146;
    v0266 = stack[-5];
    v0266 = qcar(v0266);
    if (v0266 == nil) goto v0145;
    v0266 = stack[-5];
    stack[-12] = v0266;
    v0266 = stack[-1];
    stack[-2] = v0266;
    goto v0292;

v0292:
    v0266 = stack[-2];
    if (v0266 == nil) goto v0145;
    v0266 = stack[-2];
    v0266 = qcar(v0266);
    stack[-1] = v0266;
    v0266 = stack[-1];
    v0266 = qcar(v0266);
    v0266 = qcdr(v0266);
    stack[-8] = v0266;
    v0267 = stack[-8];
    v0266 = qvalue(elt(env, 12)); /* frlis!* */
    v0266 = Lmemq(nil, v0267, v0266);
    if (v0266 == nil) goto v0293;
    v0266 = stack[-12];
    fn = elt(env, 29); /* prepsq */
    v0267 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = stack[-8];
    v0266 = list2(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    fn = elt(env, 30); /* simpexpt */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-5] = v0266;
    v0266 = (Lisp_Object)17; /* 1 */
    stack[-8] = v0266;
    goto v0293;

v0293:
    stack[0] = stack[-5];
    v0267 = stack[-8];
    v0266 = stack[-11];
    v0266 = difference2(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    fn = elt(env, 20); /* exptsq */
    v0266 = (*qfn2(fn))(qenv(fn), stack[0], v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    fn = elt(env, 21); /* subs2 */
    v0267 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = stack[-6];
    fn = elt(env, 22); /* multsq */
    v0266 = (*qfn2(fn))(qenv(fn), v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-6] = v0266;
    v0266 = stack[-8];
    stack[-11] = v0266;
    stack[0] = stack[-6];
    v0266 = stack[-1];
    v0267 = qcdr(v0266);
    v0266 = stack[-9];
    v0266 = CC_subf1(env, v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    fn = elt(env, 22); /* multsq */
    v0267 = (*qfn2(fn))(qenv(fn), stack[0], v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = stack[-3];
    fn = elt(env, 23); /* addsq */
    v0266 = (*qfn2(fn))(qenv(fn), v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-3] = v0266;
    v0266 = stack[-2];
    v0266 = qcdr(v0266);
    stack[-2] = v0266;
    goto v0292;

v0146:
    v0266 = stack[-12];
    fn = elt(env, 31); /* sub2chk */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = stack[-1];
    stack[-2] = v0266;
    goto v0294;

v0294:
    v0266 = stack[-2];
    if (v0266 == nil) goto v0145;
    v0266 = stack[-2];
    v0266 = qcar(v0266);
    stack[-1] = v0266;
    v0266 = stack[-1];
    v0267 = qcar(v0266);
    v0266 = (Lisp_Object)17; /* 1 */
    v0266 = cons(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0267 = ncons(v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = stack[-1];
    v0267 = qcdr(v0266);
    v0266 = stack[-9];
    v0266 = CC_subf1(env, v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    fn = elt(env, 22); /* multsq */
    v0267 = (*qfn2(fn))(qenv(fn), stack[0], v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = stack[-3];
    fn = elt(env, 23); /* addsq */
    v0266 = (*qfn2(fn))(qenv(fn), v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-3] = v0266;
    v0266 = stack[-2];
    v0266 = qcdr(v0266);
    stack[-2] = v0266;
    goto v0294;

v0290:
    v0266 = stack[-5];
    fn = elt(env, 32); /* kernp */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    if (v0266 == nil) goto v0295;
    v0266 = stack[-5];
    v0266 = qcar(v0266);
    v0266 = qcar(v0266);
    v0266 = qcar(v0266);
    v0267 = qcar(v0266);
    v0266 = stack[-12];
    v0266 = (v0267 == v0266 ? lisp_true : nil);
    goto v0291;

v0295:
    v0266 = qvalue(elt(env, 1)); /* nil */
    goto v0291;

v0279:
    v0267 = stack[-12];
    v0266 = qvalue(elt(env, 7)); /* asymplis!* */
    v0266 = Lassoc(nil, v0267, v0266);
    v0266 = (v0266 == nil ? lisp_true : nil);
    goto v0280;

v0278:
    v0267 = stack[-12];
    v0266 = elt(env, 8); /* k!* */
    if (v0267 == v0266) goto v0296;
    v0266 = stack[-12];
    goto v0297;

v0297:
    stack[-2] = v0266;
    goto v0281;

v0296:
    v0266 = (Lisp_Object)17; /* 1 */
    goto v0297;

v0275:
    v0266 = qvalue(elt(env, 1)); /* nil */
    goto v0276;

v0053:
    v0266 = stack[-8];
    if (v0266 == nil) goto v0298;
    v0267 = stack[-11];
    v0266 = stack[-8];
    v0266 = (Lisp_Object)lessp2(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    v0266 = v0266 ? lisp_true : nil;
    env = stack[-13];
    goto v0299;

v0299:
    if (v0266 == nil) goto v0061;
    v0266 = stack[-10];
    v0267 = qcar(v0266);
    v0266 = stack[0];
    fn = elt(env, 33); /* wtchk */
    v0267 = (*qfn2(fn))(qenv(fn), v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    v0266 = stack[-1];
    v0266 = cons(v0267, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0270;
    env = stack[-13];
    stack[-1] = v0266;
    goto v0061;

v0061:
    v0266 = stack[-10];
    v0266 = qcdr(v0266);
    stack[-10] = v0266;
    goto v0109;

v0298:
    v0266 = qvalue(elt(env, 2)); /* t */
    goto v0299;

v0271:
    v0266 = qvalue(elt(env, 2)); /* t */
    goto v0272;

v0042:
    v0266 = qvalue(elt(env, 2)); /* t */
    goto v0041;

v0116:
    v0267 = qvalue(elt(env, 1)); /* nil */
    v0266 = (Lisp_Object)17; /* 1 */
    popv(14);
    return cons(v0267, v0266);
/* error exit handlers */
v0270:
    env = stack[-13];
    qvalue(elt(env, 5)) = stack[-7]; /* varstack!* */
    popv(14);
    return nil;
v0269:
    popv(14);
    return nil;
}



/* Code for hasarg */

static Lisp_Object CC_hasarg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0123, v0138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for hasarg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0123 = stack[-1];
    v0032 = qvalue(elt(env, 1)); /* haveargs!* */
    v0032 = cons(v0123, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0032; /* haveargs!* */
    v0123 = stack[0];
    v0032 = qvalue(elt(env, 2)); /* maxarg!* */
    v0032 = (Lisp_Object)greaterp2(v0123, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    v0032 = v0032 ? lisp_true : nil;
    env = stack[-2];
    if (v0032 == nil) goto v0077;
    v0032 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 8); /* qerline */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0032 = elt(env, 3); /* "**** " */
    v0032 = Lprinc(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0032 = stack[-1];
    v0032 = Lprin(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0032 = elt(env, 4); /* " has " */
    v0032 = Lprinc(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0032 = stack[0];
    v0032 = Lprinc(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0032 = elt(env, 5); /* " arguments" */
    v0032 = Lprinc(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0032 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 9); /* newline */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    goto v0077;

v0077:
    v0123 = stack[-1];
    v0032 = elt(env, 6); /* bldmsg */
    if (v0123 == v0032) goto v0150;
    v0123 = stack[-1];
    v0138 = elt(env, 7); /* number!-of!-args */
    v0032 = stack[0];
        popv(3);
        return Lputprop(nil, 3, v0123, v0138, v0032);

v0150:
    v0032 = nil;
    { popv(3); return onevalue(v0032); }
/* error exit handlers */
v0088:
    popv(3);
    return nil;
}



/* Code for mkpartitions1 */

static Lisp_Object MS_CDECL CC_mkpartitions1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0040, Lisp_Object v0012,
                         Lisp_Object v0101, Lisp_Object v0140, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0030, v0033, v0035;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "mkpartitions1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkpartitions1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0140,v0101,v0012,v0040,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0040,v0012,v0101,v0140);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0140;
    stack[-4] = v0101;
    stack[-5] = v0012;
    stack[-6] = v0040;
    stack[-7] = v0001;
    stack[-8] = v0000;
/* end of prologue */

v0039:
    v0030 = stack[-7];
    v0129 = (Lisp_Object)17; /* 1 */
    if (v0030 == v0129) goto v0080;
    v0030 = stack[-6];
    v0129 = stack[-5];
    v0129 = (Lisp_Object)greaterp2(v0030, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    v0129 = v0129 ? lisp_true : nil;
    env = stack[-10];
    if (!(v0129 == nil)) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v0030 = stack[-8];
    v0129 = stack[-6];
    v0129 = difference2(v0030, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-10];
    stack[-9] = v0129;
    v0129 = stack[-7];
    v0129 = sub1(v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-10];
    stack[-2] = v0129;
    v0030 = stack[-8];
    v0129 = stack[-6];
    stack[0] = difference2(v0030, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-10];
    v0129 = stack[-7];
    v0129 = sub1(v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-10];
    v0129 = quot2(stack[0], v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-10];
    stack[-1] = v0129;
    v0030 = stack[-6];
    v0129 = stack[-4];
    v0129 = cons(v0030, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-10];
    stack[0] = v0129;
    v0129 = stack[-6];
    v0035 = add1(v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-10];
    v0033 = stack[-5];
    v0030 = stack[-4];
    v0129 = stack[-3];
    v0129 = CC_mkpartitions1(env, 6, stack[-8], stack[-7], v0035, v0033, v0030, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-10];
    stack[-3] = v0129;
    v0129 = stack[0];
    stack[-4] = v0129;
    v0129 = stack[-1];
    stack[-5] = v0129;
    v0129 = stack[-2];
    stack[-7] = v0129;
    v0129 = stack[-9];
    stack[-8] = v0129;
    goto v0039;

v0080:
    v0030 = stack[-8];
    v0129 = stack[-6];
    v0129 = (Lisp_Object)geq2(v0030, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    v0129 = v0129 ? lisp_true : nil;
    env = stack[-10];
    if (v0129 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v0030 = stack[-8];
    v0129 = stack[-4];
    v0129 = cons(v0030, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-10];
    v0030 = Lreverse(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    v0129 = stack[-3];
    popv(11);
    return cons(v0030, v0129);
/* error exit handlers */
v0302:
    popv(11);
    return nil;
}



/* Code for simpcv */

static Lisp_Object CC_simpcv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpcv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0008 = stack[-1];
    v0164 = Llength(nil, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-2];
    v0008 = (Lisp_Object)49; /* 3 */
    if (v0164 == v0008) goto v0080;
    v0164 = elt(env, 1); /* "Invalid number of edges in vertex" */
    v0008 = stack[-1];
    v0008 = list2(v0164, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* cerror */
        return (*qfn1(fn))(qenv(fn), v0008);
    }

v0080:
    v0164 = elt(env, 2); /* simpcgraph */
    v0008 = qvalue(elt(env, 3)); /* mul!* */
    v0008 = Lmemq(nil, v0164, v0008);
    if (!(v0008 == nil)) goto v0021;
    v0164 = qvalue(elt(env, 3)); /* mul!* */
    v0008 = elt(env, 2); /* simpcgraph */
    fn = elt(env, 5); /* aconc!* */
    v0008 = (*qfn2(fn))(qenv(fn), v0164, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-2];
    qvalue(elt(env, 3)) = v0008; /* mul!* */
    goto v0021;

v0021:
    v0164 = stack[0];
    v0008 = stack[-1];
    v0164 = cons(v0164, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-2];
    v0008 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 6); /* to */
    v0164 = (*qfn2(fn))(qenv(fn), v0164, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-2];
    v0008 = (Lisp_Object)17; /* 1 */
    v0008 = cons(v0164, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-2];
    v0164 = ncons(v0008);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    v0008 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0164, v0008);
/* error exit handlers */
v0113:
    popv(3);
    return nil;
}



/* Code for aex_fromrp */

static Lisp_Object CC_aex_fromrp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_fromrp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0137 = v0000;
/* end of prologue */
    stack[-2] = elt(env, 1); /* aex */
    stack[-1] = v0137;
    fn = elt(env, 3); /* ctx_new */
    stack[0] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-3];
    v0043 = qvalue(elt(env, 2)); /* t */
    v0137 = qvalue(elt(env, 2)); /* t */
    v0137 = list2(v0043, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    {
        Lisp_Object v0079 = stack[-2];
        Lisp_Object v0080 = stack[-1];
        Lisp_Object v0024 = stack[0];
        popv(4);
        return list3star(v0079, v0080, v0024, v0137);
    }
/* error exit handlers */
v0136:
    popv(4);
    return nil;
}



/* Code for simpdf!* */

static Lisp_Object CC_simpdfH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0152, v0131, v0136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdf*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0152 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* simpdf */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-1];
    stack[0] = v0152;
    v0152 = stack[0];
    fn = elt(env, 2); /* rootextractsq */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-1];
    v0136 = v0152;
    v0131 = v0136;
    v0152 = stack[0];
    if (equal(v0131, v0152)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0152 = v0136;
    {
        popv(2);
        fn = elt(env, 3); /* resimp */
        return (*qfn1(fn))(qenv(fn), v0152);
    }
/* error exit handlers */
v0080:
    popv(2);
    return nil;
}



/* Code for onoff */

static Lisp_Object CC_onoff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0030, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for onoff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0129 = stack[0];
    if (symbolp(v0129)) goto v0122;
    v0030 = stack[0];
    v0129 = elt(env, 1); /* "switch" */
    fn = elt(env, 10); /* typerr */
    v0129 = (*qfn2(fn))(qenv(fn), v0030, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    goto v0016;

v0016:
    v0129 = elt(env, 4); /* !* */
    stack[-1] = Lexplode(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    v0129 = stack[0];
    v0129 = Lexplode(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    v0129 = Lappend(nil, stack[-1], v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    v0129 = Lcompress(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    v0129 = Lintern(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    stack[-3] = v0129;
    v0129 = qvalue(elt(env, 5)); /* !*switchcheck */
    if (v0129 == nil) goto v0163;
    v0129 = stack[-3];
    fn = elt(env, 11); /* lispeval */
    v0030 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    v0129 = stack[-2];
    if (!(v0030 == v0129)) goto v0163;
    v0129 = qvalue(elt(env, 6)); /* nil */
    { popv(5); return onevalue(v0129); }

v0163:
    v0033 = stack[-2];
    v0030 = stack[0];
    v0129 = elt(env, 7); /* simpfg */
    v0129 = get(v0030, v0129);
    env = stack[-4];
    v0129 = Latsoc(nil, v0033, v0129);
    v0030 = v0129;
    if (v0129 == nil) goto v0099;
    stack[-1] = elt(env, 8); /* progn */
    v0129 = v0030;
    stack[0] = qcdr(v0129);
    v0129 = qvalue(elt(env, 6)); /* nil */
    v0129 = ncons(v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    v0129 = Lappend(nil, stack[0], v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    v0129 = cons(stack[-1], v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    fn = elt(env, 11); /* lispeval */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    goto v0099;

v0099:
    v0129 = stack[-2];
    if (v0129 == nil) goto v0300;
    v0030 = stack[-3];
    v0129 = elt(env, 9); /* !*raise */
    if (!(v0030 == v0129)) goto v0300;
    v0129 = elt(env, 9); /* !*raise */
    stack[-3] = v0129;
    goto v0300;

v0300:
    v0030 = stack[-3];
    v0129 = stack[-2];
    v0129 = Lset(nil, v0030, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    v0129 = nil;
    { popv(5); return onevalue(v0129); }

v0122:
    v0129 = stack[0];
    if (!symbolp(v0129)) v0129 = nil;
    else { v0129 = qfastgets(v0129);
           if (v0129 != nil) { v0129 = elt(v0129, 51); /* switch */
#ifdef RECORD_GET
             if (v0129 == SPID_NOPROP)
                record_get(elt(fastget_names, 51), 0),
                v0129 = nil;
             else record_get(elt(fastget_names, 51), 1),
                v0129 = lisp_true; }
           else record_get(elt(fastget_names, 51), 0); }
#else
             if (v0129 == SPID_NOPROP) v0129 = nil; else v0129 = lisp_true; }}
#endif
    if (!(v0129 == nil)) goto v0016;
    stack[-3] = elt(env, 2); /* rlisp */
    stack[-1] = (Lisp_Object)401; /* 25 */
    v0030 = stack[0];
    v0129 = elt(env, 3); /* "not defined as switch" */
    v0129 = list2(v0030, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    fn = elt(env, 12); /* rerror */
    v0129 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-1], v0129);
    nil = C_nil;
    if (exception_pending()) goto v0264;
    env = stack[-4];
    goto v0016;
/* error exit handlers */
v0264:
    popv(5);
    return nil;
}



/* Code for vdpvevlcomp */

static Lisp_Object CC_vdpvevlcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpvevlcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0041 = v0001;
    v0042 = v0000;
/* end of prologue */
    v0042 = qcdr(v0042);
    v0042 = qcdr(v0042);
    v0042 = qcdr(v0042);
    v0042 = qcar(v0042);
    v0041 = qcdr(v0041);
    v0041 = qcdr(v0041);
    v0041 = qcdr(v0041);
    v0041 = qcar(v0041);
    {
        fn = elt(env, 1); /* dipevlcomp */
        return (*qfn2(fn))(qenv(fn), v0042, v0041);
    }
}



/* Code for inttovec!-solve */

static Lisp_Object CC_inttovecKsolve(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0109, v0020;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec-solve");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0020 = stack[-2];
    v0109 = (Lisp_Object)1; /* 0 */
    if (v0020 == v0109) goto v0116;
    v0020 = stack[-3];
    v0109 = (Lisp_Object)17; /* 1 */
    v0109 = (v0020 == v0109 ? lisp_true : nil);
    goto v0028;

v0028:
    if (v0109 == nil) goto v0144;
    v0020 = stack[-2];
    v0109 = (Lisp_Object)1; /* 0 */
    popv(6);
    return cons(v0020, v0109);

v0144:
    v0109 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0109;
    v0109 = (Lisp_Object)17; /* 1 */
    stack[0] = v0109;
    goto v0303;

v0303:
    v0109 = stack[0];
    stack[-1] = v0109;
    v0109 = stack[-4];
    v0109 = add1(v0109);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-5];
    stack[-4] = v0109;
    v0020 = stack[-3];
    v0109 = stack[-4];
    v0020 = plus2(v0020, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-5];
    v0109 = stack[-1];
    v0020 = times2(v0020, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-5];
    v0109 = stack[-4];
    v0109 = quot2(v0020, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-5];
    stack[0] = v0109;
    v0020 = stack[0];
    v0109 = stack[-2];
    v0109 = (Lisp_Object)greaterp2(v0020, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    v0109 = v0109 ? lisp_true : nil;
    env = stack[-5];
    if (v0109 == nil) goto v0303;
    stack[0] = stack[-4];
    v0020 = stack[-2];
    v0109 = stack[-1];
    v0109 = difference2(v0020, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    {
        Lisp_Object v0068 = stack[0];
        popv(6);
        return cons(v0068, v0109);
    }

v0116:
    v0109 = qvalue(elt(env, 1)); /* t */
    goto v0028;
/* error exit handlers */
v0284:
    popv(6);
    return nil;
}



/* Code for fortexp */

static Lisp_Object CC_fortexp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0122 = v0000;
/* end of prologue */
    v0078 = v0122;
    v0122 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* fortexp1 */
        return (*qfn2(fn))(qenv(fn), v0078, v0122);
    }
}



/* Code for assert_error */

static Lisp_Object MS_CDECL CC_assert_error(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0040, Lisp_Object v0012,
                         Lisp_Object v0101, Lisp_Object v0140, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0129, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "assert_error");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_error");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0140,v0101,v0012,v0040,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0040,v0012,v0101,v0140);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0140;
    v0104 = v0101;
    stack[-2] = v0012;
    stack[-3] = v0040;
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*lower */
    qvalue(elt(env, 1)) = nil; /* !*lower */
    v0104 = qvalue(elt(env, 2)); /* !*assertstatistics */
    if (v0104 == nil) goto v0016;
    v0129 = stack[-5];
    v0104 = qvalue(elt(env, 3)); /* assertstatistics!* */
    v0104 = Latsoc(nil, v0129, v0104);
    v0104 = qcdr(v0104);
    v0129 = v0104;
    v0104 = v0129;
    v0104 = qcdr(v0104);
    stack[0] = qcdr(v0104);
    v0104 = v0129;
    v0104 = qcdr(v0104);
    v0104 = qcdr(v0104);
    v0104 = qcar(v0104);
    v0104 = add1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0305;
    env = stack[-7];
    fn = elt(env, 9); /* setcar */
    v0104 = (*qfn2(fn))(qenv(fn), stack[0], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0305;
    env = stack[-7];
    goto v0016;

v0016:
    v0129 = stack[-2];
    v0104 = (Lisp_Object)1; /* 0 */
    v0104 = Leqn(nil, v0129, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0305;
    env = stack[-7];
    if (v0104 == nil) goto v0112;
    stack[0] = elt(env, 4); /* "declaration" */
    v0030 = stack[-5];
    v0129 = stack[-4];
    v0104 = stack[-3];
    fn = elt(env, 10); /* assert_format */
    v0030 = (*qfnn(fn))(qenv(fn), 3, v0030, v0129, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0305;
    env = stack[-7];
    v0129 = elt(env, 5); /* "violated by result" */
    v0104 = stack[-1];
    v0104 = list4(stack[0], v0030, v0129, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0305;
    env = stack[-7];
    goto v0077;

v0077:
    v0129 = v0104;
    v0104 = qvalue(elt(env, 8)); /* !*assertbreak */
    if (v0104 == nil) goto v0005;
    v0104 = v0129;
    fn = elt(env, 11); /* rederr */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0305;
    env = stack[-7];
    goto v0091;

v0091:
    v0104 = nil;
    qvalue(elt(env, 1)) = stack[-6]; /* !*lower */
    { popv(8); return onevalue(v0104); }

v0005:
    v0104 = v0129;
    fn = elt(env, 12); /* lprim */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0305;
    env = stack[-7];
    goto v0091;

v0112:
    stack[0] = elt(env, 4); /* "declaration" */
    v0030 = stack[-5];
    v0129 = stack[-4];
    v0104 = stack[-3];
    fn = elt(env, 10); /* assert_format */
    stack[-4] = (*qfnn(fn))(qenv(fn), 3, v0030, v0129, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0305;
    env = stack[-7];
    stack[-3] = elt(env, 6); /* "violated by" */
    v0129 = elt(env, 7); /* arg */
    v0104 = stack[-2];
    fn = elt(env, 13); /* mkid */
    v0129 = (*qfn2(fn))(qenv(fn), v0129, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0305;
    env = stack[-7];
    v0104 = stack[-1];
    v0104 = list2(v0129, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0305;
    env = stack[-7];
    v0104 = list3star(stack[0], stack[-4], stack[-3], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0305;
    env = stack[-7];
    goto v0077;
/* error exit handlers */
v0305:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*lower */
    popv(8);
    return nil;
}



/* Code for fieldconv */

static Lisp_Object CC_fieldconv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0318, v0274, v0319;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fieldconv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0318 = stack[-1];
    v0318 = qcar(v0318);
    stack[-3] = v0318;
    v0318 = stack[-1];
    v0318 = qcdr(v0318);
    stack[0] = v0318;
    v0318 = qvalue(elt(env, 1)); /* dmode!* */
    if (v0318 == nil) goto v0018;
    v0318 = stack[0];
    if (!consp(v0318)) goto v0256;
    v0318 = stack[0];
    v0318 = qcar(v0318);
    v0318 = (consp(v0318) ? nil : lisp_true);
    goto v0258;

v0258:
    if (v0318 == nil) goto v0047;
    v0274 = stack[-3];
    v0318 = stack[0];
    fn = elt(env, 6); /* divd */
    v0274 = (*qfn2(fn))(qenv(fn), v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    v0318 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0274, v0318);

v0047:
    v0274 = stack[-3];
    v0318 = stack[-2];
    fn = elt(env, 6); /* divd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0274 = stack[0];
    v0318 = stack[-2];
    fn = elt(env, 6); /* divd */
    v0318 = (*qfn2(fn))(qenv(fn), v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    {
        Lisp_Object v0093 = stack[-1];
        popv(5);
        return cons(v0093, v0318);
    }

v0256:
    v0318 = qvalue(elt(env, 5)); /* t */
    goto v0258;

v0018:
    v0274 = stack[-2];
    v0318 = elt(env, 2); /* !:rn!: */
    if (!consp(v0274)) goto v0119;
    v0274 = qcar(v0274);
    if (!(v0274 == v0318)) goto v0119;

v0069:
    v0318 = stack[-2];
    v0319 = qcar(v0318);
    v0318 = stack[-2];
    v0318 = qcdr(v0318);
    v0274 = qcdr(v0318);
    v0318 = stack[-2];
    v0318 = qcdr(v0318);
    v0318 = qcar(v0318);
    v0318 = list2star(v0319, v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    stack[-2] = v0318;
    v0318 = stack[0];
    if (!consp(v0318)) goto v0320;
    v0318 = stack[0];
    v0318 = qcar(v0318);
    v0318 = (consp(v0318) ? nil : lisp_true);
    goto v0321;

v0321:
    if (v0318 == nil) goto v0127;
    v0274 = stack[-2];
    v0318 = stack[-3];
    fn = elt(env, 7); /* multd */
    v0274 = (*qfn2(fn))(qenv(fn), v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0318 = (Lisp_Object)17; /* 1 */
    v0318 = cons(v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    goto v0129;

v0129:
    {
        popv(5);
        fn = elt(env, 8); /* simpgd */
        return (*qfn1(fn))(qenv(fn), v0318);
    }

v0127:
    v0274 = stack[-2];
    v0318 = stack[-3];
    fn = elt(env, 7); /* multd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0274 = stack[-2];
    v0318 = stack[0];
    fn = elt(env, 7); /* multd */
    v0318 = (*qfn2(fn))(qenv(fn), v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0318 = cons(stack[-1], v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    goto v0129;

v0320:
    v0318 = qvalue(elt(env, 5)); /* t */
    goto v0321;

v0119:
    v0318 = stack[-2];
    v0274 = qcar(v0318);
    v0318 = elt(env, 2); /* !:rn!: */
    v0318 = get(v0274, v0318);
    env = stack[-4];
    v0274 = v0318;
    if (v0318 == nil) goto v0013;
    v0318 = v0274;
    if (!(!consp(v0318))) goto v0013;
    v0318 = stack[-2];
    v0318 = Lapply1(nil, v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    stack[-2] = v0318;
    goto v0069;

v0013:
    v0318 = stack[-2];
    v0274 = qcar(v0318);
    v0318 = elt(env, 3); /* quotient */
    v0318 = get(v0274, v0318);
    env = stack[-4];
    if (v0318 == nil) goto v0020;
    v0319 = (Lisp_Object)17; /* 1 */
    v0274 = stack[-2];
    v0318 = elt(env, 3); /* quotient */
    fn = elt(env, 9); /* dcombine */
    v0318 = (*qfnn(fn))(qenv(fn), 3, v0319, v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    stack[-2] = v0318;
    v0274 = stack[-2];
    v0318 = stack[-1];
    v0318 = qcar(v0318);
    fn = elt(env, 7); /* multd */
    stack[0] = (*qfn2(fn))(qenv(fn), v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0274 = stack[-2];
    v0318 = stack[-1];
    v0318 = qcdr(v0318);
    fn = elt(env, 7); /* multd */
    v0318 = (*qfn2(fn))(qenv(fn), v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    {
        Lisp_Object v0095 = stack[0];
        popv(5);
        return cons(v0095, v0318);
    }

v0020:
    v0274 = elt(env, 4); /* "field conversion" */
    v0318 = stack[-2];
    v0318 = list2(v0274, v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    fn = elt(env, 10); /* errach */
    v0318 = (*qfn1(fn))(qenv(fn), v0318);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    goto v0069;
/* error exit handlers */
v0092:
    popv(5);
    return nil;
}



/* Code for red_tailred */

static Lisp_Object CC_red_tailred(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0118, v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_tailred");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0023 = v0001;
    v0132 = v0000;
/* end of prologue */
    v0118 = qvalue(elt(env, 1)); /* !*noetherian */
    if (v0118 == nil) goto v0043;
    v0118 = v0023;
    v0023 = elt(env, 2); /* red_topred */
    {
        fn = elt(env, 4); /* red_tailreddriver */
        return (*qfnn(fn))(qenv(fn), 3, v0132, v0118, v0023);
    }

v0043:
    v0118 = v0023;
    v0023 = elt(env, 3); /* red_topredbe */
    {
        fn = elt(env, 4); /* red_tailreddriver */
        return (*qfnn(fn))(qenv(fn), 3, v0132, v0118, v0023);
    }
}



/* Code for exptsq */

static Lisp_Object CC_exptsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0246, v0276, v0331;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0276 = stack[-1];
    v0246 = (Lisp_Object)17; /* 1 */
    if (v0276 == v0246) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0276 = stack[-1];
    v0246 = (Lisp_Object)1; /* 0 */
    if (v0276 == v0246) goto v0039;
    v0246 = stack[-2];
    v0246 = qcar(v0246);
    if (v0246 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0276 = stack[-1];
    v0246 = (Lisp_Object)1; /* 0 */
    v0246 = (Lisp_Object)lessp2(v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    v0246 = v0246 ? lisp_true : nil;
    env = stack[-4];
    if (v0246 == nil) goto v0123;
    v0246 = stack[-2];
    fn = elt(env, 7); /* mk!*sq */
    v0276 = (*qfn1(fn))(qenv(fn), v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    v0246 = stack[-1];
    v0246 = list2(v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v0246);
    }

v0123:
    v0246 = qvalue(elt(env, 3)); /* !*exp */
    if (v0246 == nil) goto v0108;
    v0246 = stack[-2];
    fn = elt(env, 9); /* kernp */
    v0246 = (*qfn1(fn))(qenv(fn), v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    if (v0246 == nil) goto v0025;
    v0246 = stack[-2];
    v0246 = qcar(v0246);
    v0246 = qcar(v0246);
    v0246 = qcar(v0246);
    v0276 = qcar(v0246);
    v0246 = stack[-1];
    {
        popv(5);
        fn = elt(env, 10); /* mksq */
        return (*qfn2(fn))(qenv(fn), v0276, v0246);
    }

v0025:
    v0246 = stack[-2];
    v0276 = qcdr(v0246);
    v0246 = (Lisp_Object)17; /* 1 */
    if (v0276 == v0246) goto v0066;
    v0246 = stack[-2];
    v0246 = qcar(v0246);
    if (!consp(v0246)) goto v0052;
    v0246 = stack[-2];
    v0246 = qcar(v0246);
    v0246 = qcar(v0246);
    v0246 = (consp(v0246) ? nil : lisp_true);
    goto v0333;

v0333:
    if (v0246 == nil) goto v0098;
    v0246 = stack[-2];
    v0276 = qcar(v0246);
    v0246 = stack[-1];
    fn = elt(env, 11); /* !:expt */
    v0276 = (*qfn2(fn))(qenv(fn), v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    v0246 = (Lisp_Object)17; /* 1 */
    stack[-3] = cons(v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    stack[0] = (Lisp_Object)17; /* 1 */
    v0246 = stack[-2];
    v0276 = qcdr(v0246);
    v0246 = stack[-1];
    fn = elt(env, 12); /* exptf */
    v0246 = (*qfn2(fn))(qenv(fn), v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    v0246 = cons(stack[0], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    fn = elt(env, 13); /* multsq */
    v0246 = (*qfn2(fn))(qenv(fn), stack[-3], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    stack[-3] = v0246;
    goto v0036;

v0036:
    v0246 = stack[-3];
    v0246 = qcdr(v0246);
    if (!(v0246 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0331 = elt(env, 1); /* poly */
    v0276 = (Lisp_Object)1617; /* 101 */
    v0246 = elt(env, 6); /* "Zero divisor" */
    fn = elt(env, 14); /* rerror */
    v0246 = (*qfnn(fn))(qenv(fn), 3, v0331, v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v0098:
    v0246 = stack[-2];
    stack[-3] = v0246;
    goto v0045;

v0045:
    v0246 = stack[-1];
    v0276 = sub1(v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    stack[-1] = v0276;
    v0246 = (Lisp_Object)1; /* 0 */
    v0246 = (Lisp_Object)greaterp2(v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    v0246 = v0246 ? lisp_true : nil;
    env = stack[-4];
    if (v0246 == nil) goto v0120;
    v0246 = stack[-2];
    v0276 = qcar(v0246);
    v0246 = stack[-3];
    v0246 = qcar(v0246);
    fn = elt(env, 15); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    v0246 = stack[-2];
    v0276 = qcdr(v0246);
    v0246 = stack[-3];
    v0246 = qcdr(v0246);
    fn = elt(env, 15); /* multf */
    v0246 = (*qfn2(fn))(qenv(fn), v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    v0246 = cons(stack[0], v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    stack[-3] = v0246;
    goto v0045;

v0120:
    v0246 = stack[-3];
    fn = elt(env, 16); /* canonsq */
    v0246 = (*qfn1(fn))(qenv(fn), v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    stack[-3] = v0246;
    goto v0036;

v0052:
    v0246 = qvalue(elt(env, 4)); /* t */
    goto v0333;

v0066:
    v0246 = stack[-2];
    v0276 = qcar(v0246);
    v0246 = stack[-1];
    fn = elt(env, 12); /* exptf */
    v0276 = (*qfn2(fn))(qenv(fn), v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    v0246 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0276, v0246);

v0108:
    v0246 = stack[-2];
    v0276 = qcar(v0246);
    v0246 = stack[-1];
    fn = elt(env, 17); /* mksfpf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    env = stack[-4];
    v0246 = stack[-2];
    v0276 = qcdr(v0246);
    v0246 = stack[-1];
    fn = elt(env, 17); /* mksfpf */
    v0246 = (*qfn2(fn))(qenv(fn), v0276, v0246);
    nil = C_nil;
    if (exception_pending()) goto v0332;
    {
        Lisp_Object v0334 = stack[0];
        popv(5);
        return cons(v0334, v0246);
    }

v0039:
    v0246 = stack[-2];
    v0246 = qcar(v0246);
    if (v0246 == nil) goto v0132;
    v0276 = (Lisp_Object)17; /* 1 */
    v0246 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0276, v0246);

v0132:
    v0331 = elt(env, 1); /* poly */
    v0276 = (Lisp_Object)65; /* 4 */
    v0246 = elt(env, 2); /* " 0**0 formed" */
    {
        popv(5);
        fn = elt(env, 14); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0331, v0276, v0246);
    }
/* error exit handlers */
v0332:
    popv(5);
    return nil;
}



/* Code for tripleisprolongedby */

static Lisp_Object CC_tripleisprolongedby(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0138;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tripleisprolongedby");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0123 = v0000;
/* end of prologue */
    v0138 = v0123;
    v0123 = (Lisp_Object)49; /* 3 */
    v0123 = *(Lisp_Object *)((char *)v0138 + (CELL-TAG_VECTOR) + ((int32_t)v0123/(16/CELL)));
    stack[-1] = v0123;
    goto v0038;

v0038:
    v0123 = stack[-1];
    v0123 = qcar(v0123);
    if (v0123 == nil) goto v0084;
    v0123 = stack[-1];
    v0138 = qcar(v0123);
    v0123 = stack[0];
    v0123 = (Lisp_Object)greaterp2(v0138, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    v0123 = v0123 ? lisp_true : nil;
    env = stack[-2];
    if (v0123 == nil) goto v0084;
    v0123 = stack[-1];
    v0123 = qcdr(v0123);
    stack[-1] = v0123;
    goto v0038;

v0084:
    v0123 = stack[-1];
    v0123 = qcar(v0123);
    if (v0123 == nil) goto v0013;
    v0123 = stack[-1];
    v0138 = qcar(v0123);
    v0123 = stack[0];
    if (!(equal(v0138, v0123))) goto v0013;
    v0123 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v0123); }

v0013:
    v0123 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0123); }
/* error exit handlers */
v0088:
    popv(3);
    return nil;
}



/* Code for mksq */

static Lisp_Object CC_mksq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0348, v0349;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v0348 = qvalue(elt(env, 1)); /* subfg!* */
    if (v0348 == nil) goto v0116;
    v0349 = stack[-4];
    v0348 = qvalue(elt(env, 2)); /* wtl!* */
    v0348 = Lassoc(nil, v0349, v0348);
    stack[-2] = v0348;
    if (v0348 == nil) goto v0039;
    stack[0] = elt(env, 3); /* k!* */
    v0349 = stack[-3];
    v0348 = stack[-2];
    v0348 = qcdr(v0348);
    v0348 = times2(v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    v0348 = CC_mksq(env, stack[0], v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    stack[-2] = v0348;
    v0348 = qcar(v0348);
    if (v0348 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    else goto v0039;

v0039:
    v0348 = stack[-4];
    if (!consp(v0348)) goto v0303;
    v0348 = qvalue(elt(env, 4)); /* !*nosubs */
    if (v0348 == nil) goto v0319;
    v0348 = qvalue(elt(env, 5)); /* nil */
    goto v0274;

v0274:
    if (!(v0348 == nil)) goto v0078;
    stack[0] = elt(env, 6); /* used!* */
    v0348 = stack[-4];
    fn = elt(env, 14); /* fkern */
    v0348 = (*qfn1(fn))(qenv(fn), v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    stack[-5] = v0348;
    v0348 = qcdr(v0348);
    v0348 = qcdr(v0348);
    v0348 = Lmemq(nil, stack[0], v0348);
    if (!(v0348 == nil)) goto v0028;
    v0349 = stack[-5];
    v0348 = elt(env, 6); /* used!* */
    fn = elt(env, 15); /* aconc */
    v0348 = (*qfn2(fn))(qenv(fn), v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    goto v0028;

v0028:
    v0348 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v0348 == nil)) goto v0116;
    v0349 = stack[-3];
    v0348 = (Lisp_Object)17; /* 1 */
    if (v0349 == v0348) goto v0116;
    v0349 = stack[-4];
    v0348 = qvalue(elt(env, 7)); /* asymplis!* */
    v0348 = Lassoc(nil, v0349, v0348);
    stack[-1] = v0348;
    if (v0348 == nil) goto v0005;
    v0348 = stack[-1];
    v0349 = qcdr(v0348);
    v0348 = stack[-3];
    v0348 = (Lisp_Object)lesseq2(v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    v0348 = v0348 ? lisp_true : nil;
    env = stack[-6];
    if (v0348 == nil) goto v0005;
    v0349 = qvalue(elt(env, 5)); /* nil */
    v0348 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v0349, v0348);

v0005:
    v0349 = stack[-4];
    v0348 = qvalue(elt(env, 8)); /* powlis!* */
    v0348 = Lassoc(nil, v0349, v0348);
    stack[-1] = v0348;
    if (!(v0348 == nil)) goto v0351;
    v0348 = stack[-4];
    if (!consp(v0348)) goto v0061;
    v0348 = stack[-4];
    v0349 = qcar(v0348);
    v0348 = elt(env, 9); /* (expt sqrt) */
    v0348 = Lmemq(nil, v0349, v0348);
    if (v0348 == nil) goto v0066;
    v0348 = stack[-4];
    v0348 = qcdr(v0348);
    v0349 = qcar(v0348);
    v0348 = qvalue(elt(env, 8)); /* powlis!* */
    v0348 = Lassoc(nil, v0349, v0348);
    stack[-1] = v0348;
    goto v0320;

v0320:
    if (!(v0348 == nil)) goto v0351;

v0116:
    v0348 = stack[-5];
    if (!(v0348 == nil)) goto v0121;
    v0348 = stack[-4];
    fn = elt(env, 14); /* fkern */
    v0348 = (*qfn1(fn))(qenv(fn), v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    stack[-5] = v0348;
    goto v0121;

v0121:
    v0349 = stack[-5];
    v0348 = stack[-3];
    fn = elt(env, 16); /* getpower */
    v0349 = (*qfn2(fn))(qenv(fn), v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    v0348 = (Lisp_Object)17; /* 1 */
    v0348 = cons(v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    v0349 = ncons(v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    v0348 = (Lisp_Object)17; /* 1 */
    v0348 = cons(v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    stack[-5] = v0348;
    v0348 = stack[-2];
    if (v0348 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v0349 = stack[-2];
    v0348 = stack[-5];
    {
        popv(7);
        fn = elt(env, 17); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0349, v0348);
    }

v0351:
    v0349 = stack[-3];
    v0348 = stack[-1];
    v0348 = qcdr(v0348);
    v0348 = qcar(v0348);
    v0349 = times2(v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    v0348 = (Lisp_Object)1; /* 0 */
    v0348 = (Lisp_Object)lessp2(v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    v0348 = v0348 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0348 == nil)) goto v0116;
    v0348 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 11)) = v0348; /* !*sub2 */
    goto v0116;

v0066:
    v0348 = qvalue(elt(env, 5)); /* nil */
    goto v0320;

v0061:
    v0348 = qvalue(elt(env, 5)); /* nil */
    goto v0320;

v0078:
    v0348 = stack[-1];
    v0348 = qcdr(v0348);
    stack[-1] = v0348;
    v0348 = qvalue(elt(env, 13)); /* !*resubs */
    if (!(v0348 == nil)) goto v0352;
    v0348 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 4)) = v0348; /* !*nosubs */
    goto v0352;

v0352:
    v0348 = stack[-1];
    fn = elt(env, 18); /* simpcar */
    v0348 = (*qfn1(fn))(qenv(fn), v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    stack[-5] = v0348;
    v0348 = qvalue(elt(env, 5)); /* nil */
    qvalue(elt(env, 4)) = v0348; /* !*nosubs */
    v0349 = stack[-5];
    v0348 = stack[-3];
    {
        popv(7);
        fn = elt(env, 19); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v0349, v0348);
    }

v0319:
    v0348 = stack[-4];
    v0348 = qcar(v0348);
    if (!consp(v0348)) goto v0353;
    v0348 = qvalue(elt(env, 5)); /* nil */
    goto v0274;

v0353:
    v0348 = stack[-4];
    v0349 = qcar(v0348);
    v0348 = elt(env, 12); /* mksqsubfn */
    v0348 = get(v0349, v0348);
    env = stack[-6];
    stack[-1] = v0348;
    if (v0348 == nil) goto v0354;
    v0349 = stack[-1];
    v0348 = stack[-4];
    v0348 = Lapply1(nil, v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    stack[-1] = v0348;
    goto v0355;

v0355:
    if (!(v0348 == nil)) goto v0274;
    v0349 = stack[-4];
    v0348 = stack[-4];
    v0348 = qcar(v0348);
    if (!symbolp(v0348)) v0348 = nil;
    else { v0348 = qfastgets(v0348);
           if (v0348 != nil) { v0348 = elt(v0348, 50); /* kvalue */
#ifdef RECORD_GET
             if (v0348 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v0348 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v0348 == SPID_NOPROP) v0348 = nil; }}
#endif
    v0348 = Lassoc(nil, v0349, v0348);
    stack[-1] = v0348;
    goto v0274;

v0354:
    v0348 = qvalue(elt(env, 5)); /* nil */
    goto v0355;

v0303:
    v0348 = qvalue(elt(env, 4)); /* !*nosubs */
    if (v0348 == nil) goto v0161;
    v0348 = qvalue(elt(env, 5)); /* nil */
    goto v0156;

v0156:
    if (!(v0348 == nil)) goto v0078;
    v0348 = stack[-4];
    if (!(symbolp(v0348))) goto v0028;
    v0348 = stack[-4];
    v0349 = ncons(v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    v0348 = elt(env, 6); /* used!* */
    v0348 = Lflag(nil, v0349, v0348);
    nil = C_nil;
    if (exception_pending()) goto v0350;
    env = stack[-6];
    goto v0028;

v0161:
    v0348 = stack[-4];
    if (!symbolp(v0348)) v0348 = nil;
    else { v0348 = qfastgets(v0348);
           if (v0348 != nil) { v0348 = elt(v0348, 4); /* avalue */
#ifdef RECORD_GET
             if (v0348 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0348 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0348 == SPID_NOPROP) v0348 = nil; }}
#endif
    stack[-1] = v0348;
    goto v0156;
/* error exit handlers */
v0350:
    popv(7);
    return nil;
}



/* Code for powers4 */

static Lisp_Object CC_powers4(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0238, v0335, v0348;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0133;

v0133:
    v0238 = stack[-1];
    if (v0238 == nil) goto v0139;
    v0238 = stack[0];
    if (v0238 == nil) goto v0108;
    v0238 = stack[-1];
    v0238 = qcar(v0238);
    v0335 = qcar(v0238);
    v0238 = stack[0];
    v0238 = qcar(v0238);
    v0238 = qcar(v0238);
    if (equal(v0335, v0238)) goto v0369;
    v0238 = stack[-1];
    v0238 = qcar(v0238);
    v0335 = qcar(v0238);
    v0238 = stack[0];
    v0238 = qcar(v0238);
    v0238 = qcar(v0238);
    fn = elt(env, 2); /* ordop */
    v0238 = (*qfn2(fn))(qenv(fn), v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    if (v0238 == nil) goto v0280;
    v0238 = stack[0];
    v0238 = qcar(v0238);
    v0335 = qcdr(v0238);
    v0238 = (Lisp_Object)1; /* 0 */
    v0238 = Lrplacd(nil, v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    stack[-2] = stack[0];
    v0335 = stack[-1];
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    v0238 = CC_powers4(env, v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    v0238 = Lrplacd(nil, stack[-2], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    {
        Lisp_Object v0371 = stack[-3];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0371, v0238);
    }

v0280:
    v0238 = stack[-1];
    v0238 = qcar(v0238);
    stack[-2] = qcar(v0238);
    v0238 = stack[-1];
    v0238 = qcar(v0238);
    v0335 = qcdr(v0238);
    v0238 = (Lisp_Object)1; /* 0 */
    v0335 = cons(v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    v0238 = stack[-3];
    v0238 = acons(stack[-2], v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    stack[-3] = v0238;
    v0238 = stack[-1];
    v0238 = qcdr(v0238);
    stack[-1] = v0238;
    goto v0133;

v0369:
    v0238 = stack[-1];
    v0238 = qcar(v0238);
    v0335 = qcdr(v0238);
    v0238 = stack[0];
    v0238 = qcar(v0238);
    v0238 = qcdr(v0238);
    v0238 = qcar(v0238);
    v0238 = (Lisp_Object)greaterp2(v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    v0238 = v0238 ? lisp_true : nil;
    env = stack[-5];
    if (v0238 == nil) goto v0121;
    v0238 = stack[0];
    v0238 = qcar(v0238);
    v0335 = qcdr(v0238);
    v0238 = stack[-1];
    v0238 = qcar(v0238);
    v0238 = qcdr(v0238);
    v0238 = Lrplaca(nil, v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    goto v0121;

v0121:
    v0238 = stack[-1];
    v0238 = qcar(v0238);
    v0335 = qcdr(v0238);
    v0238 = stack[0];
    v0238 = qcar(v0238);
    v0238 = qcdr(v0238);
    v0238 = qcdr(v0238);
    v0238 = (Lisp_Object)lessp2(v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    v0238 = v0238 ? lisp_true : nil;
    env = stack[-5];
    if (v0238 == nil) goto v0372;
    v0238 = stack[0];
    v0238 = qcar(v0238);
    v0335 = qcdr(v0238);
    v0238 = stack[-1];
    v0238 = qcar(v0238);
    v0238 = qcdr(v0238);
    v0238 = Lrplacd(nil, v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    goto v0372;

v0372:
    stack[-2] = stack[0];
    v0238 = stack[-1];
    v0335 = qcdr(v0238);
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    v0238 = CC_powers4(env, v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    v0238 = Lrplacd(nil, stack[-2], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    {
        Lisp_Object v0350 = stack[-3];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0350, v0238);
    }

v0108:
    stack[-4] = stack[-3];
    v0238 = stack[-1];
    stack[-3] = v0238;
    v0238 = stack[-3];
    if (v0238 == nil) goto v0019;
    v0238 = stack[-3];
    v0238 = qcar(v0238);
    v0335 = v0238;
    v0348 = qcar(v0335);
    v0335 = qcdr(v0238);
    v0238 = (Lisp_Object)1; /* 0 */
    v0238 = list2star(v0348, v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    v0238 = ncons(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    stack[-1] = v0238;
    stack[-2] = v0238;
    goto v0111;

v0111:
    v0238 = stack[-3];
    v0238 = qcdr(v0238);
    stack[-3] = v0238;
    v0238 = stack[-3];
    if (v0238 == nil) goto v0030;
    stack[0] = stack[-1];
    v0238 = stack[-3];
    v0238 = qcar(v0238);
    v0335 = v0238;
    v0348 = qcar(v0335);
    v0335 = qcdr(v0238);
    v0238 = (Lisp_Object)1; /* 0 */
    v0238 = list2star(v0348, v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    v0238 = ncons(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    v0238 = Lrplacd(nil, stack[0], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    v0238 = stack[-1];
    v0238 = qcdr(v0238);
    stack[-1] = v0238;
    goto v0111;

v0030:
    v0238 = stack[-2];
    goto v0148;

v0148:
    {
        Lisp_Object v0373 = stack[-4];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0373, v0238);
    }

v0019:
    v0238 = qvalue(elt(env, 1)); /* nil */
    goto v0148;

v0139:
    stack[-4] = stack[-3];
    v0238 = stack[0];
    stack[-3] = v0238;
    v0238 = stack[-3];
    if (v0238 == nil) goto v0136;
    v0238 = stack[-3];
    v0238 = qcar(v0238);
    v0335 = v0238;
    v0348 = qcar(v0335);
    v0238 = qcdr(v0238);
    v0335 = qcar(v0238);
    v0238 = (Lisp_Object)1; /* 0 */
    v0238 = list2star(v0348, v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    v0238 = ncons(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    stack[-1] = v0238;
    stack[-2] = v0238;
    goto v0043;

v0043:
    v0238 = stack[-3];
    v0238 = qcdr(v0238);
    stack[-3] = v0238;
    v0238 = stack[-3];
    if (v0238 == nil) goto v0161;
    stack[0] = stack[-1];
    v0238 = stack[-3];
    v0238 = qcar(v0238);
    v0335 = v0238;
    v0348 = qcar(v0335);
    v0238 = qcdr(v0238);
    v0335 = qcar(v0238);
    v0238 = (Lisp_Object)1; /* 0 */
    v0238 = list2star(v0348, v0335, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    v0238 = ncons(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    v0238 = Lrplacd(nil, stack[0], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0370;
    env = stack[-5];
    v0238 = stack[-1];
    v0238 = qcdr(v0238);
    stack[-1] = v0238;
    goto v0043;

v0161:
    v0238 = stack[-2];
    goto v0038;

v0038:
    {
        Lisp_Object v0234 = stack[-4];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0234, v0238);
    }

v0136:
    v0238 = qvalue(elt(env, 1)); /* nil */
    goto v0038;
/* error exit handlers */
v0370:
    popv(6);
    return nil;
}



/* Code for mml2ir */

static Lisp_Object MS_CDECL CC_mml2ir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0021;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mml2ir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mml2ir");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    v0022 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0022;
    v0022 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v0022; /* mmlatts */
    v0021 = elt(env, 3); /* !! */
    v0022 = (Lisp_Object)513; /* 32 */
    v0022 = list2(v0021, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    v0022 = Lcompress(nil, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    qvalue(elt(env, 4)) = v0022; /* space */
    v0022 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v0022; /* count */
    v0022 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    qvalue(elt(env, 6)) = v0022; /* ch */
    v0022 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 7)) = v0022; /* temp2 */
    fn = elt(env, 13); /* lex */
    v0022 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    v0021 = qvalue(elt(env, 8)); /* char */
    v0022 = elt(env, 9); /* (m a t h) */
    if (equal(v0021, v0022)) goto v0017;
    v0021 = elt(env, 10); /* "<math>" */
    v0022 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 14); /* errorml */
    v0022 = (*qfn2(fn))(qenv(fn), v0021, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    goto v0042;

v0042:
    fn = elt(env, 13); /* lex */
    v0022 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    v0021 = qvalue(elt(env, 8)); /* char */
    v0022 = elt(env, 11); /* (!/ m a t h) */
    if (equal(v0021, v0022)) goto v0087;
    v0021 = elt(env, 12); /* "</math>" */
    v0022 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 14); /* errorml */
    v0022 = (*qfn2(fn))(qenv(fn), v0021, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0087:
    v0022 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0017:
    fn = elt(env, 15); /* mathml */
    v0022 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    stack[0] = v0022;
    goto v0042;
/* error exit handlers */
v0100:
    popv(2);
    return nil;
}



setup_type const u19_setup[] =
{
    {"vintersection",           too_few_2,      CC_vintersection,wrong_no_2},
    {"vdp_poly",                CC_vdp_poly,    too_many_1,    wrong_no_1},
    {"binaryrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_binaryrd},
    {"wedgek2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_wedgek2},
    {"rd:plus",                 too_few_2,      CC_rdTplus,    wrong_no_2},
    {"opmtchrevop",             CC_opmtchrevop, too_many_1,    wrong_no_1},
    {"contr",                   too_few_2,      CC_contr,      wrong_no_2},
    {"no-side-effect-listp",    CC_noKsideKeffectKlistp,too_many_1,wrong_no_1},
    {"setelv",                  too_few_2,      CC_setelv,     wrong_no_2},
    {"mo_equal?",               too_few_2,      CC_mo_equalW,  wrong_no_2},
    {"b:ordexp",                too_few_2,      CC_bTordexp,   wrong_no_2},
    {"resimpf",                 CC_resimpf,     too_many_1,    wrong_no_1},
    {"innprodkp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_innprodkp},
    {"outref",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_outref},
    {"ofsf_sippsubst",          too_few_2,      CC_ofsf_sippsubst,wrong_no_2},
    {"triplesetprolongset",     too_few_2,      CC_triplesetprolongset,wrong_no_2},
    {"kernord-split",           too_few_2,      CC_kernordKsplit,wrong_no_2},
    {"mk+unit+mat",             CC_mkLunitLmat, too_many_1,    wrong_no_1},
    {"lx2xx",                   CC_lx2xx,       too_many_1,    wrong_no_1},
    {"unaryir",                 too_few_2,      CC_unaryir,    wrong_no_2},
    {"prinlatom",               CC_prinlatom,   too_many_1,    wrong_no_1},
    {"physopordchk",            too_few_2,      CC_physopordchk,wrong_no_2},
    {"red_totalred",            too_few_2,      CC_red_totalred,wrong_no_2},
    {"repeats",                 CC_repeats,     too_many_1,    wrong_no_1},
    {"subf1",                   too_few_2,      CC_subf1,      wrong_no_2},
    {"hasarg",                  too_few_2,      CC_hasarg,     wrong_no_2},
    {"mkpartitions1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkpartitions1},
    {"simpcv",                  too_few_2,      CC_simpcv,     wrong_no_2},
    {"aex_fromrp",              CC_aex_fromrp,  too_many_1,    wrong_no_1},
    {"simpdf*",                 CC_simpdfH,     too_many_1,    wrong_no_1},
    {"onoff",                   too_few_2,      CC_onoff,      wrong_no_2},
    {"vdpvevlcomp",             too_few_2,      CC_vdpvevlcomp,wrong_no_2},
    {"inttovec-solve",          too_few_2,      CC_inttovecKsolve,wrong_no_2},
    {"fortexp",                 CC_fortexp,     too_many_1,    wrong_no_1},
    {"assert_error",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_error},
    {"fieldconv",               too_few_2,      CC_fieldconv,  wrong_no_2},
    {"red_tailred",             too_few_2,      CC_red_tailred,wrong_no_2},
    {"exptsq",                  too_few_2,      CC_exptsq,     wrong_no_2},
    {"tripleisprolongedby",     too_few_2,      CC_tripleisprolongedby,wrong_no_2},
    {"mksq",                    too_few_2,      CC_mksq,       wrong_no_2},
    {"powers4",                 too_few_2,      CC_powers4,    wrong_no_2},
    {"mml2ir",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mml2ir},
    {NULL, (one_args *)"u19", (two_args *)"9825 3917299 765832", 0}
};

/* end of generated code */
