
/* $destdir\u09.c        Machine generated C code */

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


/* Code for integerom */

static Lisp_Object CC_integerom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for integerom");
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
    v1 = elt(env, 1); /* "<OMI> " */
    fn = elt(env, 3); /* printout */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-1];
    v1 = stack[0];
    v1 = Lprinc(nil, v1);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-1];
    v1 = elt(env, 2); /* " </OMI>" */
    v1 = Lprinc(nil, v1);
    nil = C_nil;
    if (exception_pending()) goto v2;
    v1 = nil;
    { popv(2); return onevalue(v1); }
/* error exit handlers */
v2:
    popv(2);
    return nil;
}



/* Code for ps!:putv */

static Lisp_Object MS_CDECL CC_psTputv(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v3,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:putv");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:putv");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v3,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v3;
    v18 = v0;
/* end of prologue */
    v17 = v18;
    v16 = elt(env, 1); /* !:ps!: */
    if (!consp(v17)) goto v19;
    v17 = qcar(v17);
    if (!(v17 == v16)) goto v19;
    v16 = v18;
    v16 = qcdr(v16);
    if (symbolp(v16)) goto v20;
    v16 = v18;
    v18 = qcdr(v16);
    v17 = stack[-1];
    v16 = stack[0];
    *(Lisp_Object *)((char *)v18 + (CELL-TAG_VECTOR) + ((int32_t)v17/(16/CELL))) = v16;
    { popv(3); return onevalue(v16); }

v20:
    v16 = v18;
    v16 = qcdr(v16);
    fn = elt(env, 5); /* eval */
    v18 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v21;
    v17 = stack[-1];
    v16 = stack[0];
    *(Lisp_Object *)((char *)v18 + (CELL-TAG_VECTOR) + ((int32_t)v17/(16/CELL))) = v16;
    { popv(3); return onevalue(v16); }

v19:
    v16 = elt(env, 2); /* "PS:PUTV: not a ps" */
    v17 = v18;
    v16 = list2(v16, v17);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    v17 = v16;
    v16 = v17;
    qvalue(elt(env, 3)) = v16; /* errmsg!* */
    v16 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v16 == nil)) goto v22;
    v16 = v17;
    fn = elt(env, 6); /* lprie */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    goto v22;

v22:
    v16 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v21;
    v16 = nil;
    { popv(3); return onevalue(v16); }
/* error exit handlers */
v21:
    popv(3);
    return nil;
}



/* Code for maxtype */

static Lisp_Object CC_maxtype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxtype");
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
    v24 = v0;
/* end of prologue */
    v23 = v24;
    if (!consp(v23)) return onevalue(v24);
    v23 = v24;
    v23 = qcdr(v23);
    v23 = Lconsp(nil, v23);
    if (v23 == nil) goto v25;
    v23 = v24;
    v23 = qcdr(v23);
    v23 = qcar(v23);
    return onevalue(v23);

v25:
    v23 = v24;
    v23 = qcar(v23);
    return onevalue(v23);
}



/* Code for bsubs */

static Lisp_Object CC_bsubs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bsubs");
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
    v30 = stack[0];
    if (v30 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v30 = stack[0];
    if (!consp(v30)) goto v31;
    v30 = stack[0];
    stack[-3] = v30;
    v30 = stack[-3];
    if (v30 == nil) goto v11;
    v30 = stack[-3];
    v30 = qcar(v30);
    v30 = CC_bsubs(env, v30);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    stack[-1] = v30;
    stack[-2] = v30;
    goto v12;

v12:
    v30 = stack[-3];
    v30 = qcdr(v30);
    stack[-3] = v30;
    v30 = stack[-3];
    if (v30 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v30 = stack[-3];
    v30 = qcar(v30);
    v30 = CC_bsubs(env, v30);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    v30 = Lrplacd(nil, stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    v30 = stack[-1];
    v30 = qcdr(v30);
    stack[-1] = v30;
    goto v12;

v11:
    v30 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v30); }

v31:
    v30 = stack[0];
    fn = elt(env, 2); /* bound */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    if (v30 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v30 = stack[0];
    {
        popv(5);
        fn = elt(env, 3); /* binding */
        return (*qfn1(fn))(qenv(fn), v30);
    }
/* error exit handlers */
v18:
    popv(5);
    return nil;
}



/* Code for mksgnsq */

static Lisp_Object CC_mksgnsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksgnsq");
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
    v38 = v0;
/* end of prologue */
    v37 = v38;
    fn = elt(env, 1); /* evenfree */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    v38 = v37;
    if (v37 == nil) goto v40;
    v39 = v38;
    v37 = (Lisp_Object)17; /* 1 */
    if (v39 == v37) goto v28;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v37 = (Lisp_Object)17; /* 1 */
    v37 = cons(v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    fn = elt(env, 2); /* mk!*sq */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    v37 = list2(stack[0], v37);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v37);
    }

v28:
    v38 = (Lisp_Object)-15; /* -1 */
    v37 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v38, v37);

v40:
    v38 = (Lisp_Object)17; /* 1 */
    v37 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v38, v37);
/* error exit handlers */
v7:
    popv(2);
    return nil;
}



/* Code for cut!:ep */

static Lisp_Object CC_cutTep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cut:ep");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v0;
/* end of prologue */
    v55 = stack[-2];
    v54 = elt(env, 1); /* !:rd!: */
    if (!consp(v55)) goto v56;
    v55 = qcar(v55);
    if (!(v55 == v54)) goto v56;
    v54 = stack[-2];
    v54 = qcdr(v54);
    v54 = (consp(v54) ? nil : lisp_true);
    v54 = (v54 == nil ? lisp_true : nil);
    goto v2;

v2:
    if (v54 == nil) goto v13;
    v54 = stack[-1];
    v54 = integerp(v54);
    goto v31;

v31:
    if (v54 == nil) goto v57;
    v55 = stack[-1];
    v54 = stack[-2];
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v55 = difference2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    stack[-1] = v55;
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)lesseq2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    v54 = v54 ? lisp_true : nil;
    env = stack[-4];
    if (!(v54 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v54 = stack[-2];
    v54 = qcdr(v54);
    stack[0] = qcar(v54);
    v54 = stack[-1];
    v54 = negate(v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    v54 = stack[-2];
    v54 = qcdr(v54);
    v55 = qcdr(v54);
    v54 = stack[-1];
    v54 = plus2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    {
        Lisp_Object v59 = stack[-3];
        Lisp_Object v60 = stack[0];
        popv(5);
        return list2star(v59, v60, v54);
    }

v57:
    stack[0] = (Lisp_Object)1; /* 0 */
    v55 = elt(env, 3); /* "Invalid argument to" */
    v54 = elt(env, 0); /* cut!:ep */
    v54 = list2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    {
        Lisp_Object v61 = stack[0];
        popv(5);
        fn = elt(env, 4); /* error */
        return (*qfn2(fn))(qenv(fn), v61, v54);
    }

v13:
    v54 = qvalue(elt(env, 2)); /* nil */
    goto v31;

v56:
    v54 = qvalue(elt(env, 2)); /* nil */
    goto v2;
/* error exit handlers */
v58:
    popv(5);
    return nil;
}



/* Code for tokquote */

static Lisp_Object MS_CDECL CC_tokquote(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "tokquote");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tokquote");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 6); /* readch1 */
    v25 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[0];
    qvalue(elt(env, 1)) = v25; /* crchar!* */
    v62 = elt(env, 2); /* " '" */
    v25 = qvalue(elt(env, 3)); /* outl!* */
    v25 = cons(v62, v25);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[0];
    qvalue(elt(env, 3)) = v25; /* outl!* */
    fn = elt(env, 7); /* rread1 */
    v25 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[0];
    v25 = Lmkquote(nil, v25);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[0];
    qvalue(elt(env, 4)) = v25; /* nxtsym!* */
    v25 = (Lisp_Object)65; /* 4 */
    qvalue(elt(env, 5)) = v25; /* ttype!* */
    v25 = qvalue(elt(env, 4)); /* nxtsym!* */
    { popv(1); return onevalue(v25); }
/* error exit handlers */
v63:
    popv(1);
    return nil;
}



/* Code for mo_diff */

static Lisp_Object CC_mo_diff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_diff");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v2 = v3;
    v64 = v0;
/* end of prologue */
    stack[0] = v64;
    fn = elt(env, 1); /* mo_neg */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    {
        Lisp_Object v25 = stack[0];
        popv(2);
        fn = elt(env, 2); /* mo_sum */
        return (*qfn2(fn))(qenv(fn), v25, v2);
    }
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



/* Code for pdmult */

static Lisp_Object CC_pdmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v3;
    v93 = v0;
/* end of prologue */
    stack[-9] = v93;
    v93 = stack[-9];
    if (v93 == nil) goto v2;
    v93 = stack[-9];
    v93 = qcar(v93);
    stack[-4] = v93;
    v93 = stack[-4];
    v94 = qcar(v93);
    v93 = stack[-8];
    fn = elt(env, 2); /* pair */
    v93 = (*qfn2(fn))(qenv(fn), v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[-3] = v93;
    v93 = stack[-3];
    if (v93 == nil) goto v33;
    v93 = stack[-3];
    v93 = qcar(v93);
    v94 = v93;
    v94 = qcar(v94);
    v93 = qcdr(v93);
    v93 = (Lisp_Object)(int32_t)((int32_t)v94 + (int32_t)v93 - TAG_FIXNUM);
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[-1] = v93;
    stack[-2] = v93;
    goto v35;

v35:
    v93 = stack[-3];
    v93 = qcdr(v93);
    stack[-3] = v93;
    v93 = stack[-3];
    if (v93 == nil) goto v96;
    stack[0] = stack[-1];
    v93 = stack[-3];
    v93 = qcar(v93);
    v94 = v93;
    v94 = qcar(v94);
    v93 = qcdr(v93);
    v93 = (Lisp_Object)(int32_t)((int32_t)v94 + (int32_t)v93 - TAG_FIXNUM);
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v93 = Lrplacd(nil, stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v93 = stack[-1];
    v93 = qcdr(v93);
    stack[-1] = v93;
    goto v35;

v96:
    v93 = stack[-2];
    v94 = v93;
    goto v36;

v36:
    v93 = stack[-4];
    v93 = qcdr(v93);
    v93 = cons(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[-6] = v93;
    stack[-7] = v93;
    goto v31;

v31:
    v93 = stack[-9];
    v93 = qcdr(v93);
    stack[-9] = v93;
    v93 = stack[-9];
    if (v93 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v93 = stack[-9];
    v93 = qcar(v93);
    stack[-4] = v93;
    v93 = stack[-4];
    v94 = qcar(v93);
    v93 = stack[-8];
    fn = elt(env, 2); /* pair */
    v93 = (*qfn2(fn))(qenv(fn), v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[-3] = v93;
    v93 = stack[-3];
    if (v93 == nil) goto v97;
    v93 = stack[-3];
    v93 = qcar(v93);
    v94 = v93;
    v94 = qcar(v94);
    v93 = qcdr(v93);
    v93 = (Lisp_Object)(int32_t)((int32_t)v94 + (int32_t)v93 - TAG_FIXNUM);
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    stack[-1] = v93;
    stack[-2] = v93;
    goto v98;

v98:
    v93 = stack[-3];
    v93 = qcdr(v93);
    stack[-3] = v93;
    v93 = stack[-3];
    if (v93 == nil) goto v99;
    stack[0] = stack[-1];
    v93 = stack[-3];
    v93 = qcar(v93);
    v94 = v93;
    v94 = qcar(v94);
    v93 = qcdr(v93);
    v93 = (Lisp_Object)(int32_t)((int32_t)v94 + (int32_t)v93 - TAG_FIXNUM);
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v93 = Lrplacd(nil, stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v93 = stack[-1];
    v93 = qcdr(v93);
    stack[-1] = v93;
    goto v98;

v99:
    v93 = stack[-2];
    v94 = v93;
    goto v100;

v100:
    v93 = stack[-4];
    v93 = qcdr(v93);
    v93 = cons(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v93 = Lrplacd(nil, stack[-5], v93);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-10];
    v93 = stack[-6];
    v93 = qcdr(v93);
    stack[-6] = v93;
    goto v31;

v97:
    v93 = qvalue(elt(env, 1)); /* nil */
    v94 = v93;
    goto v100;

v33:
    v93 = qvalue(elt(env, 1)); /* nil */
    v94 = v93;
    goto v36;

v2:
    v93 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v93); }
/* error exit handlers */
v95:
    popv(11);
    return nil;
}



/* Code for polynomlistfinddivisor */

static Lisp_Object MS_CDECL CC_polynomlistfinddivisor(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v3,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v57, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "polynomlistfinddivisor");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomlistfinddivisor");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v3,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v4;
    v57 = v3;
    v85 = v0;
/* end of prologue */
    v103 = v57;
    v103 = qcar(v103);
    if (v103 == nil) goto v1;
    v103 = v85;
    v103 = qcar(v103);
    v103 = (v103 == nil ? lisp_true : nil);
    goto v40;

v40:
    if (v103 == nil) goto v24;
    v103 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v103); }

v24:
    stack[0] = nil;
    v103 = v57;
    v103 = qcar(v103);
    stack[-3] = v103;
    v103 = v85;
    stack[-1] = v103;
    goto v11;

v11:
    v103 = stack[-1];
    v103 = qcar(v103);
    if (v103 == nil) goto v13;
    v103 = stack[0];
    if (!(v103 == nil)) goto v13;
    v103 = stack[-2];
    if (v103 == nil) goto v104;
    v57 = stack[-3];
    v103 = stack[-1];
    v103 = qcar(v103);
    v103 = qcar(v103);
    fn = elt(env, 3); /* monomisdivisibleby */
    v103 = (*qfn2(fn))(qenv(fn), v57, v103);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-4];
    if (!(v103 == nil)) goto v8;

v104:
    v103 = stack[-2];
    if (v103 == nil) goto v16;
    v103 = qvalue(elt(env, 2)); /* nil */
    goto v105;

v105:
    if (!(v103 == nil)) goto v8;
    v103 = stack[-1];
    v103 = qcdr(v103);
    stack[-1] = v103;
    goto v11;

v8:
    v103 = qvalue(elt(env, 1)); /* t */
    stack[0] = v103;
    goto v11;

v16:
    v57 = stack[-3];
    v103 = stack[-1];
    v103 = qcar(v103);
    v103 = qcar(v103);
    fn = elt(env, 4); /* monomispommaretdivisibleby */
    v103 = (*qfn2(fn))(qenv(fn), v57, v103);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-4];
    goto v105;

v13:
    v103 = stack[-1];
    v103 = qcar(v103);
    { popv(5); return onevalue(v103); }

v1:
    v103 = qvalue(elt(env, 1)); /* t */
    goto v40;
/* error exit handlers */
v42:
    popv(5);
    return nil;
}



/* Code for cancel */

static Lisp_Object CC_cancel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cancel");
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
    v50 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v50 == nil)) goto v27;
    v50 = stack[0];
    v51 = qcdr(v50);
    v50 = (Lisp_Object)17; /* 1 */
    if (v51 == v50) goto v27;
    v50 = stack[0];
    v51 = qcar(v50);
    v50 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v50 = stack[0];
    v51 = qcdr(v50);
    v50 = (Lisp_Object)17; /* 1 */
    v50 = cons(v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    fn = elt(env, 2); /* mk!*sq */
    v51 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v50 = (Lisp_Object)-15; /* -1 */
    v50 = list2(v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    fn = elt(env, 3); /* simpexpt */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    {
        Lisp_Object v111 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v111, v50);
    }

v27:
    v50 = stack[0];
    v51 = qcar(v50);
    v50 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v51 = (Lisp_Object)17; /* 1 */
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = cons(v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    {
        Lisp_Object v112 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v112, v50);
    }
/* error exit handlers */
v110:
    popv(3);
    return nil;
}



/* Code for sfto_tsqsumf */

static Lisp_Object CC_sfto_tsqsumf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_tsqsumf");
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

v84:
    v101 = stack[0];
    if (!consp(v101)) goto v53;
    v101 = stack[0];
    v101 = qcar(v101);
    v101 = (consp(v101) ? nil : lisp_true);
    goto v1;

v1:
    if (v101 == nil) goto v113;
    v101 = stack[0];
    if (v101 == nil) goto v20;
    v101 = stack[0];
    fn = elt(env, 5); /* minusf */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    if (v101 == nil) goto v28;
    v101 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v101); }

v28:
    v101 = elt(env, 3); /* stsq */
    { popv(2); return onevalue(v101); }

v20:
    v101 = elt(env, 2); /* tsq */
    { popv(2); return onevalue(v101); }

v113:
    v101 = stack[0];
    v101 = qcar(v101);
    v101 = qcar(v101);
    v101 = qcdr(v101);
    v101 = Levenp(nil, v101);
    env = stack[-1];
    if (v101 == nil) goto v26;
    v101 = stack[0];
    v101 = qcar(v101);
    v101 = qcdr(v101);
    v101 = CC_sfto_tsqsumf(env, v101);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    if (v101 == nil) goto v6;
    v101 = stack[0];
    v101 = qcdr(v101);
    stack[0] = v101;
    goto v84;

v6:
    v101 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v101); }

v26:
    v101 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v101); }

v53:
    v101 = qvalue(elt(env, 1)); /* t */
    goto v1;
/* error exit handlers */
v102:
    popv(2);
    return nil;
}



/* Code for revv0 */

static Lisp_Object CC_revv0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revv0");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v0;
/* end of prologue */

v52:
    v17 = stack[-1];
    v17 = qcdr(v17);
    v18 = qcar(v17);
    v17 = stack[0];
    if (v18 == v17) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v17 = stack[-1];
    v17 = qcdr(v17);
    v17 = qcar(v17);
    stack[-2] = v17;
    v17 = stack[-1];
    v18 = qcdr(v17);
    v17 = stack[-1];
    v17 = qcdr(v17);
    v17 = qcdr(v17);
    v17 = qcar(v17);
    v17 = Lrplaca(nil, v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    v17 = stack[-1];
    v17 = qcdr(v17);
    v18 = qcdr(v17);
    v17 = stack[-1];
    v17 = qcdr(v17);
    v17 = qcdr(v17);
    v17 = qcdr(v17);
    v17 = qcar(v17);
    v17 = Lrplaca(nil, v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    v17 = stack[-1];
    v17 = qcdr(v17);
    v17 = qcdr(v17);
    v18 = qcdr(v17);
    v17 = stack[-2];
    v17 = Lrplaca(nil, v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    v18 = stack[-1];
    v17 = stack[0];
    stack[-1] = v18;
    stack[0] = v17;
    goto v52;
/* error exit handlers */
v87:
    popv(4);
    return nil;
}



/* Code for ibalp_vequal */

static Lisp_Object CC_ibalp_vequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_vequal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v64 = v3;
    v15 = v0;
/* end of prologue */
    v15 = qcar(v15);
    v64 = qcar(v64);
    v64 = (v15 == v64 ? lisp_true : nil);
    return onevalue(v64);
}



/* Code for vdp_poly */

static Lisp_Object CC_vdp_poly(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v52;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_poly");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v52 = v0;
/* end of prologue */
    v52 = qcdr(v52);
    v52 = qcdr(v52);
    v52 = qcdr(v52);
    v52 = qcar(v52);
    return onevalue(v52);
}



/* Code for naryrd */

static Lisp_Object MS_CDECL CC_naryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "naryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for naryrd");
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
    v24 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    v20 = v24;
    v24 = v20;
    if (v24 == nil) goto v52;
    stack[0] = v20;
    v24 = CC_naryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v27;
    {
        Lisp_Object v29 = stack[0];
        popv(2);
        return cons(v29, v24);
    }

v52:
    v24 = nil;
    { popv(2); return onevalue(v24); }
/* error exit handlers */
v27:
    popv(2);
    return nil;
}



/* Code for simpexpon1 */

static Lisp_Object CC_simpexpon1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v5;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpon1");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v0;
/* end of prologue */
    v7 = qvalue(elt(env, 1)); /* !*numval */
    if (v7 == nil) goto v92;
    v5 = qvalue(elt(env, 2)); /* dmode!* */
    v7 = elt(env, 3); /* !:rd!: */
    if (v5 == v7) goto v2;
    v5 = qvalue(elt(env, 2)); /* dmode!* */
    v7 = elt(env, 5); /* !:cr!: */
    v7 = (v5 == v7 ? lisp_true : nil);
    goto v53;

v53:
    if (v7 == nil) goto v92;
    v5 = stack[-1];
    v7 = stack[-2];
        popv(5);
        return Lapply1(nil, v5, v7);

v92:
    stack[-3] = qvalue(elt(env, 2)); /* dmode!* */
    qvalue(elt(env, 2)) = nil; /* dmode!* */
    stack[0] = qvalue(elt(env, 6)); /* alglist!* */
    qvalue(elt(env, 6)) = nil; /* alglist!* */
    v7 = qvalue(elt(env, 7)); /* nil */
    v7 = ncons(v7);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-4];
    qvalue(elt(env, 6)) = v7; /* alglist!* */
    v5 = stack[-1];
    v7 = stack[-2];
    v7 = Lapply1(nil, v5, v7);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-4];
    qvalue(elt(env, 6)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 2)) = stack[-3]; /* dmode!* */
    { popv(5); return onevalue(v7); }

v2:
    v7 = qvalue(elt(env, 4)); /* t */
    goto v53;
/* error exit handlers */
v22:
    env = stack[-4];
    qvalue(elt(env, 6)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 2)) = stack[-3]; /* dmode!* */
    popv(5);
    return nil;
}



/* Code for simp */

static Lisp_Object CC_simp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v242, v243, v244, v245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp");
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
    v241 = qvalue(elt(env, 1)); /* varstack!* */
    stack[-6] = qvalue(elt(env, 1)); /* varstack!* */
    qvalue(elt(env, 1)) = v241; /* varstack!* */
    stack[-1] = nil;
    v241 = stack[-5];
    v241 = integerp(v241);
    if (v241 == nil) goto v106;
    v242 = stack[-5];
    v241 = (Lisp_Object)1; /* 0 */
    if (v242 == v241) goto v28;
    v241 = qvalue(elt(env, 3)); /* dmode!* */
    if (!(v241 == nil)) goto v87;
    v242 = stack[-5];
    v241 = (Lisp_Object)17; /* 1 */
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v52:
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    { popv(8); return onevalue(v241); }

v87:
    v242 = stack[-5];
    v241 = qvalue(elt(env, 1)); /* varstack!* */
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    qvalue(elt(env, 1)) = v241; /* varstack!* */
    v242 = qvalue(elt(env, 6)); /* simpcount!* */
    v241 = qvalue(elt(env, 7)); /* simplimit!* */
    v241 = (Lisp_Object)greaterp2(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    v241 = v241 ? lisp_true : nil;
    env = stack[-7];
    if (v241 == nil) goto v61;
    v241 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 6)) = v241; /* simpcount!* */
    v241 = elt(env, 8); /* "Simplification recursion too deep" */
    v242 = v241;
    v241 = v242;
    qvalue(elt(env, 9)) = v241; /* errmsg!* */
    v241 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v241 == nil)) goto v247;
    v241 = v242;
    fn = elt(env, 38); /* lprie */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v247;

v247:
    v241 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v248;

v248:
    v241 = qvalue(elt(env, 6)); /* simpcount!* */
    v241 = add1(v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    qvalue(elt(env, 6)) = v241; /* simpcount!* */
    v241 = stack[-5];
    if (!consp(v241)) goto v249;
    v241 = stack[-5];
    v241 = qcar(v241);
    if (symbolp(v241)) goto v250;
    v241 = qvalue(elt(env, 5)); /* t */
    goto v251;

v251:
    if (v241 == nil) goto v252;
    v241 = stack[-5];
    v241 = qcar(v241);
    if (!consp(v241)) goto v253;
    v241 = stack[-5];
    v241 = qcar(v241);
    v241 = qcar(v241);
    if (!(symbolp(v241))) goto v254;
    v241 = stack[-5];
    v241 = qcar(v241);
    v242 = qcar(v241);
    v241 = elt(env, 17); /* name */
    v241 = get(v242, v241);
    env = stack[-7];
    stack[-1] = v241;
    if (v241 == nil) goto v254;
    v242 = stack[-5];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v254:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 18); /* mat */
    if (!consp(v242)) goto v255;
    v242 = qcar(v242);
    if (!(v242 == v241)) goto v255;
    v241 = stack[-5];
    v241 = qcdr(v241);
    fn = elt(env, 40); /* revlis */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    stack[-1] = v241;
    fn = elt(env, 41); /* numlis */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    if (v241 == nil) goto v256;
    v241 = stack[-1];
    v242 = Llength(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = (Lisp_Object)33; /* 2 */
    v241 = (v242 == v241 ? lisp_true : nil);
    goto v257;

v257:
    if (v241 == nil) goto v258;
    v241 = stack[-5];
    v241 = qcar(v241);
    v242 = qcdr(v241);
    v241 = stack[-1];
    v241 = qcar(v241);
    fn = elt(env, 42); /* pnth */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v242 = qcar(v241);
    v241 = stack[-1];
    v241 = qcdr(v241);
    v241 = qcar(v241);
    fn = elt(env, 42); /* pnth */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = qcar(v241);
    v242 = CC_simp(env, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v258:
    v245 = elt(env, 19); /* "Syntax error:" */
    v244 = stack[-5];
    v243 = elt(env, 20); /* "invalid" */
    v242 = qvalue(elt(env, 2)); /* nil */
    v241 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 43); /* msgpri */
    v241 = (*qfnn(fn))(qenv(fn), 5, v245, v244, v243, v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v259;

v259:
    v241 = nil;
    goto v52;

v256:
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v257;

v255:
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v257;

v253:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 16); /* "operator" */
    fn = elt(env, 44); /* typerr */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v259;

v252:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 21); /* opfn */
    v241 = Lflagp(nil, v242, v241);
    env = stack[-7];
    if (v241 == nil) goto v260;
    v241 = stack[-5];
    fn = elt(env, 45); /* opfneval */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    stack[-1] = v241;
    fn = elt(env, 46); /* getrtype */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v242 = v241;
    if (v241 == nil) goto v261;
    v241 = elt(env, 22); /* yetunknowntype */
    if (v242 == v241) goto v262;
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v263;

v263:
    if (v241 == nil) goto v264;
    v241 = stack[-1];
    v241 = CC_simp(env, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v264:
    v242 = stack[-5];
    v241 = elt(env, 23); /* "scalar" */
    fn = elt(env, 44); /* typerr */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v259;

v262:
    v241 = stack[-1];
    fn = elt(env, 47); /* reval */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    stack[-1] = v241;
    fn = elt(env, 46); /* getrtype */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = (v241 == nil ? lisp_true : nil);
    goto v263;

v261:
    v241 = stack[-1];
    fn = elt(env, 48); /* simp_without_resimp */
    v242 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v260:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 24); /* psopfn */
    v241 = get(v242, v241);
    env = stack[-7];
    stack[-1] = v241;
    if (v241 == nil) goto v265;
    stack[0] = stack[-1];
    v241 = stack[-5];
    fn = elt(env, 49); /* argnochk */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = qcdr(v241);
    v241 = Lapply1(nil, stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    stack[-1] = v241;
    fn = elt(env, 46); /* getrtype */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    if (v241 == nil) goto v266;
    v242 = stack[-5];
    v241 = elt(env, 23); /* "scalar" */
    fn = elt(env, 44); /* typerr */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v259;

v266:
    v242 = stack[-1];
    v241 = stack[-5];
    if (equal(v242, v241)) goto v267;
    v241 = stack[-1];
    fn = elt(env, 48); /* simp_without_resimp */
    v242 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v267:
    v243 = stack[-1];
    v242 = (Lisp_Object)17; /* 1 */
    v241 = (Lisp_Object)17; /* 1 */
    v241 = acons(v243, v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v242 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = (Lisp_Object)17; /* 1 */
    v242 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v265:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 25); /* polyfn */
    v241 = get(v242, v241);
    env = stack[-7];
    stack[-1] = v241;
    if (v241 == nil) goto v268;
    v241 = stack[-5];
    fn = elt(env, 49); /* argnochk */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    stack[-4] = stack[-1];
    v241 = stack[-5];
    v241 = qcdr(v241);
    stack[-3] = v241;
    v241 = stack[-3];
    if (v241 == nil) goto v269;
    v241 = stack[-3];
    v241 = qcar(v241);
    fn = elt(env, 50); /* simp!* */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    fn = elt(env, 51); /* !*q2f */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    stack[-1] = v241;
    stack[-2] = v241;
    goto v270;

v270:
    v241 = stack[-3];
    v241 = qcdr(v241);
    stack[-3] = v241;
    v241 = stack[-3];
    if (v241 == nil) goto v271;
    stack[0] = stack[-1];
    v241 = stack[-3];
    v241 = qcar(v241);
    fn = elt(env, 50); /* simp!* */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    fn = elt(env, 51); /* !*q2f */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = Lrplacd(nil, stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-1];
    v241 = qcdr(v241);
    stack[-1] = v241;
    goto v270;

v271:
    v241 = stack[-2];
    goto v272;

v272:
    fn = elt(env, 52); /* lispapply */
    v242 = (*qfn2(fn))(qenv(fn), stack[-4], v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = (Lisp_Object)17; /* 1 */
    v242 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v269:
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v272;

v268:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 26); /* opmtch */
    v241 = get(v242, v241);
    env = stack[-7];
    if (v241 == nil) goto v273;
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 27); /* simpfn */
    v242 = get(v242, v241);
    env = stack[-7];
    v241 = elt(env, 28); /* simpiden */
    if (v242 == v241) goto v274;
    v241 = stack[-5];
    fn = elt(env, 53); /* opmtchrevop */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    stack[-1] = v241;
    goto v275;

v275:
    if (v241 == nil) goto v273;
    v241 = stack[-1];
    v242 = CC_simp(env, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v273:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 27); /* simpfn */
    v241 = get(v242, v241);
    env = stack[-7];
    stack[-1] = v241;
    if (v241 == nil) goto v276;
    stack[0] = stack[-1];
    v242 = stack[-1];
    v241 = elt(env, 28); /* simpiden */
    if (v242 == v241) goto v277;
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 29); /* full */
    v241 = Lflagp(nil, v242, v241);
    env = stack[-7];
    goto v278;

v278:
    if (v241 == nil) goto v279;
    v241 = stack[-5];
    fn = elt(env, 49); /* argnochk */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v280;

v280:
    v242 = Lapply1(nil, stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v279:
    v241 = stack[-5];
    fn = elt(env, 49); /* argnochk */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = qcdr(v241);
    goto v280;

v277:
    v241 = qvalue(elt(env, 5)); /* t */
    goto v278;

v276:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 30); /* rtype */
    v241 = get(v242, v241);
    env = stack[-7];
    stack[-1] = v241;
    if (v241 == nil) goto v281;
    v242 = stack[-1];
    v241 = elt(env, 31); /* getelemfn */
    v241 = get(v242, v241);
    env = stack[-7];
    stack[-1] = v241;
    if (v241 == nil) goto v281;
    v242 = stack[-1];
    v241 = stack[-5];
    v241 = Lapply1(nil, v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v242 = CC_simp(env, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v281:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 32); /* boolean */
    v241 = Lflagp(nil, v242, v241);
    env = stack[-7];
    if (v241 == nil) goto v282;
    v241 = qvalue(elt(env, 5)); /* t */
    goto v283;

v283:
    if (v241 == nil) goto v284;
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 34); /* prtch */
    v241 = get(v242, v241);
    env = stack[-7];
    stack[-1] = v241;
    if (v241 == nil) goto v285;
    v241 = stack[-1];
    v242 = v241;
    goto v286;

v286:
    v241 = elt(env, 35); /* "algebraic operator" */
    fn = elt(env, 44); /* typerr */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v259;

v285:
    v241 = stack[-5];
    v241 = qcar(v241);
    v242 = v241;
    goto v286;

v284:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 36); /* nochange */
    v241 = Lflagp(nil, v242, v241);
    env = stack[-7];
    if (v241 == nil) goto v287;
    v241 = stack[-5];
    fn = elt(env, 54); /* eval */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v242 = CC_simp(env, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v287:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 24); /* psopfn */
    v241 = get(v242, v241);
    env = stack[-7];
    if (!(v241 == nil)) goto v288;
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 37); /* rtypefn */
    v241 = get(v242, v241);
    env = stack[-7];
    if (!(v241 == nil)) goto v288;
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 16); /* "operator" */
    fn = elt(env, 55); /* redmsg */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    v241 = qcar(v241);
    fn = elt(env, 56); /* mkop */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v242 = stack[-5];
    v241 = qvalue(elt(env, 1)); /* varstack!* */
    v241 = Ldelete(nil, v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    qvalue(elt(env, 1)) = v241; /* varstack!* */
    v241 = stack[-5];
    v242 = CC_simp(env, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v288:
    v242 = stack[-5];
    v241 = elt(env, 23); /* "scalar" */
    fn = elt(env, 44); /* typerr */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v259;

v282:
    v241 = stack[-5];
    v242 = qcar(v241);
    v241 = elt(env, 33); /* infix */
    v241 = get(v242, v241);
    env = stack[-7];
    goto v283;

v274:
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v275;

v250:
    v241 = stack[-5];
    v241 = qcar(v241);
    v241 = (v241 == nil ? lisp_true : nil);
    goto v251;

v249:
    v241 = stack[-5];
    fn = elt(env, 57); /* simpatom */
    v242 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    v241 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v61:
    v242 = stack[-5];
    v241 = elt(env, 11); /* !*sq */
    if (!consp(v242)) goto v289;
    v242 = qcar(v242);
    if (!(v242 == v241)) goto v289;
    v241 = stack[-5];
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    if (v241 == nil) goto v98;
    v241 = qvalue(elt(env, 12)); /* !*resimp */
    v241 = (v241 == nil ? lisp_true : nil);
    goto v290;

v290:
    if (v241 == nil) goto v66;
    v241 = stack[-5];
    v241 = qcdr(v241);
    v241 = qcar(v241);
    goto v52;

v66:
    v241 = qvalue(elt(env, 13)); /* !*uncached */
    if (v241 == nil) goto v291;
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v292;

v292:
    if (v241 == nil) goto v248;
    v241 = stack[-1];
    v241 = qcar(v241);
    if (v241 == nil) goto v293;
    v241 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 15)) = v241; /* !*sub2 */
    goto v293;

v293:
    v241 = stack[-1];
    v241 = qcdr(v241);
    goto v52;

v291:
    v241 = qvalue(elt(env, 14)); /* alglist!* */
    v241 = qcar(v241);
    v242 = v241;
    if (v242 == nil) goto v294;
    v242 = stack[-5];
    fn = elt(env, 58); /* gethash */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v78;

v78:
    stack[-1] = v241;
    goto v292;

v294:
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v78;

v98:
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v290;

v289:
    v241 = qvalue(elt(env, 2)); /* nil */
    goto v290;

v28:
    v242 = qvalue(elt(env, 2)); /* nil */
    v241 = (Lisp_Object)17; /* 1 */
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v52;

v106:
    v242 = stack[-5];
    v241 = qvalue(elt(env, 1)); /* varstack!* */
    v241 = Lmember(nil, v242, v241);
    if (v241 == nil) goto v87;
    v245 = qvalue(elt(env, 2)); /* nil */
    v244 = stack[-5];
    v243 = elt(env, 4); /* "improperly defined in terms of itself" */
    v242 = qvalue(elt(env, 2)); /* nil */
    v241 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 43); /* msgpri */
    v241 = (*qfnn(fn))(qenv(fn), 5, v245, v244, v243, v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-7];
    goto v87;
/* error exit handlers */
v246:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    popv(8);
    return nil;
}



/* Code for zeropp */

static Lisp_Object CC_zeropp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v9, v10;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zeropp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    v33 = v10;
    if (!consp(v33)) goto v84;
    v33 = v10;
    v9 = qcar(v33);
    v33 = elt(env, 1); /* !:rd!: */
    if (v9 == v33) goto v40;
    v33 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v33);

v40:
    v33 = v10;
    v33 = qcdr(v33);
    if (!consp(v33)) goto v24;
    v33 = v10;
    v33 = qcdr(v33);
    v9 = qcar(v33);
    v33 = (Lisp_Object)1; /* 0 */
    v33 = (v9 == v33 ? lisp_true : nil);
    return onevalue(v33);

v24:
    v33 = v10;
    v33 = qcdr(v33);
        return Lzerop(nil, v33);

v84:
    v33 = v10;
        return Lzerop(nil, v33);
}



/* Code for gpexp1p */

static Lisp_Object CC_gpexp1p(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpexp1p");
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

v296:
    v36 = stack[0];
    if (v36 == nil) goto v84;
    v36 = stack[0];
    v36 = qcar(v36);
    fn = elt(env, 3); /* gpexpp */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    if (v36 == nil) goto v2;
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[0] = v36;
    goto v296;

v2:
    v36 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v36); }

v84:
    v36 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v36); }
/* error exit handlers */
v29:
    popv(2);
    return nil;
}



/* Code for chknewnam */

static Lisp_Object CC_chknewnam(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v297, v32, v33, v9;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chknewnam");
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
    v33 = v0;
/* end of prologue */

v15:
    v32 = v33;
    v297 = elt(env, 1); /* newnam */
    v297 = get(v32, v297);
    env = stack[0];
    v9 = v297;
    if (v297 == nil) goto v53;
    v32 = v9;
    v297 = v33;
    v297 = (v32 == v297 ? lisp_true : nil);
    goto v1;

v1:
    if (!(v297 == nil)) { popv(1); return onevalue(v33); }
    v297 = v9;
    if (!(symbolp(v297))) { popv(1); return onevalue(v9); }
    v297 = v9;
    v33 = v297;
    goto v15;

v53:
    v297 = qvalue(elt(env, 2)); /* t */
    goto v1;
}



/* Code for mo!=lexcomp */

static Lisp_Object CC_moMlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v6, v7, v5;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=lexcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v3;
    v7 = v0;
/* end of prologue */

v83:
    v39 = v7;
    if (v39 == nil) goto v31;
    v39 = v6;
    if (v39 == nil) goto v23;
    v39 = v7;
    v5 = qcar(v39);
    v39 = v6;
    v39 = qcar(v39);
    if (equal(v5, v39)) goto v27;
    v39 = v7;
    v39 = qcar(v39);
    v6 = qcar(v6);
    if (((int32_t)(v39)) > ((int32_t)(v6))) goto v91;
    v39 = (Lisp_Object)-15; /* -1 */
    return onevalue(v39);

v91:
    v39 = (Lisp_Object)17; /* 1 */
    return onevalue(v39);

v27:
    v39 = v7;
    v39 = qcdr(v39);
    v7 = v39;
    v39 = v6;
    v39 = qcdr(v39);
    v6 = v39;
    goto v83;

v23:
    v39 = elt(env, 1); /* (0) */
    v6 = v39;
    goto v83;

v31:
    v39 = v6;
    if (v39 == nil) goto v64;
    v39 = elt(env, 1); /* (0) */
    v7 = v39;
    goto v83;

v64:
    v39 = (Lisp_Object)1; /* 0 */
    return onevalue(v39);
}



/* Code for arintequiv!: */

static Lisp_Object CC_arintequivT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v298, v104;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arintequiv:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v104 = v0;
/* end of prologue */
    v8 = v104;
    v8 = qcdr(v8);
    if (is_number(v8)) goto v84;
    v8 = v104;
    v8 = qcdr(v8);
    v298 = qcar(v8);
    v8 = elt(env, 1); /* !:rn!: */
    if (v298 == v8) goto v29;
    v8 = qvalue(elt(env, 2)); /* nil */
    goto v64;

v64:
    if (v8 == nil) goto v33;
    v8 = v104;
    v8 = qcdr(v8);
    v8 = qcdr(v8);
    v8 = qcar(v8);
    return onevalue(v8);

v33:
    v8 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v8);

v29:
    v8 = v104;
    v8 = qcdr(v8);
    v8 = qcdr(v8);
    v298 = qcdr(v8);
    v8 = (Lisp_Object)17; /* 1 */
    v8 = (v298 == v8 ? lisp_true : nil);
    goto v64;

v84:
    v8 = v104;
    v8 = qcdr(v8);
    return onevalue(v8);
}



/* Code for horner!-rule */

static Lisp_Object MS_CDECL CC_hornerKrule(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v3,
                         Lisp_Object v4, Lisp_Object v82, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v312, v313, v314, v315;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "horner-rule");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule");
#endif
    if (stack >= stacklimit)
    {
        push4(v82,v4,v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v3,v4,v82);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v82;
    stack[-2] = v4;
    stack[-3] = v3;
    stack[-4] = v0;
/* end of prologue */

v296:
    v312 = stack[-2];
    if (!consp(v312)) goto v53;
    v312 = stack[-2];
    v312 = qcar(v312);
    v312 = (consp(v312) ? nil : lisp_true);
    goto v1;

v1:
    if (v312 == nil) goto v90;
    v312 = stack[-1];
    v312 = qcar(v312);
    v312 = qcdr(v312);
    v312 = (Lisp_Object)zerop(v312);
    v312 = v312 ? lisp_true : nil;
    env = stack[-6];
    if (v312 == nil) goto v11;
    v312 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v312);
    }

v11:
    v312 = stack[-2];
    fn = elt(env, 2); /* !*d2n */
    stack[0] = (*qfn1(fn))(qenv(fn), v312);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-6];
    stack[-2] = stack[-4];
    v312 = stack[-1];
    v312 = qcar(v312);
    v313 = qcdr(v312);
    v312 = stack[-3];
    v312 = Lexpt(nil, v313, v312);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-6];
    v312 = times2(stack[-2], v312);
    nil = C_nil;
    if (exception_pending()) goto v316;
    {
        Lisp_Object v317 = stack[0];
        popv(7);
        return plus2(v317, v312);
    }

v90:
    v312 = stack[-2];
    v312 = qcar(v312);
    v312 = qcar(v312);
    v313 = qcar(v312);
    v312 = stack[-1];
    v312 = qcar(v312);
    v312 = qcar(v312);
    if (equal(v313, v312)) goto v67;
    v312 = stack[-1];
    v312 = qcar(v312);
    v312 = qcdr(v312);
    v312 = (Lisp_Object)zerop(v312);
    v312 = v312 ? lisp_true : nil;
    env = stack[-6];
    if (v312 == nil) goto v41;
    v313 = stack[-2];
    v312 = stack[-1];
    v312 = qcdr(v312);
    {
        popv(7);
        fn = elt(env, 3); /* evaluate!-in!-order */
        return (*qfn2(fn))(qenv(fn), v313, v312);
    }

v41:
    v313 = stack[-2];
    v312 = stack[-1];
    v312 = qcdr(v312);
    fn = elt(env, 3); /* evaluate!-in!-order */
    stack[0] = (*qfn2(fn))(qenv(fn), v313, v312);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-6];
    stack[-2] = stack[-4];
    v312 = stack[-1];
    v312 = qcar(v312);
    v313 = qcdr(v312);
    v312 = stack[-3];
    v312 = Lexpt(nil, v313, v312);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-6];
    v312 = times2(stack[-2], v312);
    nil = C_nil;
    if (exception_pending()) goto v316;
    {
        Lisp_Object v318 = stack[0];
        popv(7);
        return plus2(v318, v312);
    }

v67:
    v312 = stack[-2];
    v312 = qcar(v312);
    v312 = qcar(v312);
    v312 = qcdr(v312);
    stack[-5] = v312;
    v312 = stack[-1];
    v312 = qcar(v312);
    v312 = qcdr(v312);
    v312 = (Lisp_Object)zerop(v312);
    v312 = v312 ? lisp_true : nil;
    env = stack[-6];
    if (v312 == nil) goto v70;
    v312 = stack[-2];
    v312 = qcar(v312);
    v313 = qcdr(v312);
    v312 = stack[-1];
    v312 = qcdr(v312);
    fn = elt(env, 3); /* evaluate!-in!-order */
    v312 = (*qfn2(fn))(qenv(fn), v313, v312);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-6];
    v315 = v312;
    goto v319;

v319:
    v314 = stack[-5];
    v312 = stack[-2];
    v313 = qcdr(v312);
    v312 = stack[-1];
    stack[-4] = v315;
    stack[-3] = v314;
    stack[-2] = v313;
    stack[-1] = v312;
    goto v296;

v70:
    v312 = stack[-2];
    v312 = qcar(v312);
    v313 = qcdr(v312);
    v312 = stack[-1];
    v312 = qcdr(v312);
    fn = elt(env, 3); /* evaluate!-in!-order */
    stack[0] = (*qfn2(fn))(qenv(fn), v313, v312);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-6];
    v312 = stack[-1];
    v312 = qcar(v312);
    v314 = qcdr(v312);
    v313 = stack[-3];
    v312 = stack[-5];
    v312 = (Lisp_Object)(int32_t)((int32_t)v313 - (int32_t)v312 + TAG_FIXNUM);
    v312 = Lexpt(nil, v314, v312);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-6];
    v312 = times2(stack[-4], v312);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-6];
    v312 = plus2(stack[0], v312);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-6];
    v315 = v312;
    goto v319;

v53:
    v312 = qvalue(elt(env, 1)); /* t */
    goto v1;
/* error exit handlers */
v316:
    popv(7);
    return nil;
}



/* Code for crprcd2 */

static Lisp_Object CC_crprcd2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crprcd2");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v0;
/* end of prologue */
    v31 = stack[-1];
    fn = elt(env, 2); /* crprcd */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    stack[-1] = v31;
    v31 = stack[0];
    fn = elt(env, 2); /* crprcd */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    qvalue(elt(env, 1)) = v31; /* yy!! */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for qqe_arg!-check!-b */

static Lisp_Object CC_qqe_argKcheckKb(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_arg-check-b");
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
    v6 = stack[0];
    fn = elt(env, 3); /* qqe_id!-nyt!-branchb */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    if (v6 == nil) goto v116;
    v6 = stack[0];
    if (!consp(v6)) goto v14;
    v6 = qvalue(elt(env, 1)); /* nil */
    goto v15;

v15:
    if (v6 == nil) goto v2;
    v6 = stack[0];
    fn = elt(env, 4); /* qqe_qtidp */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    if (v6 == nil) goto v56;
    v6 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v6); }

v56:
    v6 = stack[0];
    fn = elt(env, 5); /* qqe_nytidp */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    if (v6 == nil) goto v297;
    v6 = stack[0];
    fn = elt(env, 6); /* qqe_btid */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    v6 = stack[0];
    fn = elt(env, 7); /* qqe_add2rollbackids */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    v6 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v6); }

v297:
    v6 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v6); }

v2:
    v6 = stack[0];
    if (!consp(v6)) goto v37;
    v6 = stack[0];
    fn = elt(env, 8); /* qqe_arg!-check */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    v6 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v6); }

v37:
    v6 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v6); }

v14:
    v6 = stack[0];
    v6 = (is_number(v6) ? lisp_true : nil);
    v6 = (v6 == nil ? lisp_true : nil);
    goto v15;

v116:
    v6 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v6); }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for ibalp_vmember */

static Lisp_Object CC_ibalp_vmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_vmember");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v0;
/* end of prologue */

v296:
    v13 = stack[0];
    if (v13 == nil) goto v83;
    v11 = stack[-1];
    v13 = stack[0];
    v13 = qcar(v13);
    fn = elt(env, 2); /* ibalp_vequal */
    v13 = (*qfn2(fn))(qenv(fn), v11, v13);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-2];
    if (!(v13 == nil)) { popv(3); return onevalue(v13); }
    v11 = stack[-1];
    v13 = stack[0];
    v13 = qcdr(v13);
    stack[-1] = v11;
    stack[0] = v13;
    goto v296;

v83:
    v13 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v13); }
/* error exit handlers */
v115:
    popv(3);
    return nil;
}



/* Code for aex_reducedtag */

static Lisp_Object CC_aex_reducedtag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v31;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_reducedtag");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */
    v31 = qcdr(v31);
    v31 = qcdr(v31);
    v31 = qcdr(v31);
    v31 = qcdr(v31);
    v31 = qcar(v31);
    return onevalue(v31);
}



/* Code for diffp1 */

static Lisp_Object CC_diffp1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffp1");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v37 = v3;
    v39 = v0;
/* end of prologue */
    v38 = v39;
    v38 = qcar(v38);
    if (v38 == v37) goto v63;
    v37 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v37); }

v63:
    v37 = v39;
    v38 = qcdr(v37);
    v37 = (Lisp_Object)17; /* 1 */
    if (v38 == v37) goto v25;
    v37 = v39;
    stack[-1] = qcdr(v37);
    v37 = v39;
    stack[0] = qcar(v37);
    v37 = v39;
    v37 = qcdr(v37);
    v38 = sub1(v37);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    v37 = (Lisp_Object)17; /* 1 */
    v37 = acons(stack[0], v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    v37 = ncons(v37);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    {
        Lisp_Object v26 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* multd */
        return (*qfn2(fn))(qenv(fn), v26, v37);
    }

v25:
    v37 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v37); }
/* error exit handlers */
v5:
    popv(3);
    return nil;
}



/* Code for omiir */

static Lisp_Object MS_CDECL CC_omiir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omiir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omiir");
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
    fn = elt(env, 2); /* lex */
    v40 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v40 = qvalue(elt(env, 1)); /* char */
    v40 = Lcompress(nil, v40);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    stack[0] = v40;
    fn = elt(env, 2); /* lex */
    v40 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v53;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v53:
    popv(2);
    return nil;
}



/* Code for testredh */

static Lisp_Object CC_testredh(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testredh");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v30 = qvalue(elt(env, 2)); /* maxvar */
    v96 = stack[0];
    v96 = plus2(v30, v96);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    v30 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v96/(16/CELL)));
    v96 = (Lisp_Object)1; /* 0 */
    v96 = *(Lisp_Object *)((char *)v30 + (CELL-TAG_VECTOR) + ((int32_t)v96/(16/CELL)));
    if (v96 == nil) goto v83;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v30 = qvalue(elt(env, 2)); /* maxvar */
    v96 = stack[0];
    v96 = plus2(v30, v96);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    v30 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v96/(16/CELL)));
    v96 = (Lisp_Object)17; /* 1 */
    v96 = *(Lisp_Object *)((char *)v30 + (CELL-TAG_VECTOR) + ((int32_t)v96/(16/CELL)));
    v96 = qcar(v96);
    v30 = qcar(v96);
    v96 = (Lisp_Object)33; /* 2 */
    v96 = (Lisp_Object)lessp2(v30, v96);
    nil = C_nil;
    if (exception_pending()) goto v16;
    v96 = v96 ? lisp_true : nil;
    env = stack[-2];
    if (v96 == nil) goto v83;
    v96 = stack[0];
    fn = elt(env, 3); /* rowdel */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    v96 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* testredzz */
        return (*qfn1(fn))(qenv(fn), v96);
    }

v83:
    v96 = nil;
    { popv(3); return onevalue(v96); }
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for getrtype1 */

static Lisp_Object CC_getrtype1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v82;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtype1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v82 = v0;
/* end of prologue */
    v82 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v82);
}



/* Code for mkuwedge */

static Lisp_Object CC_mkuwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkuwedge");
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
    v20 = v0;
/* end of prologue */
    v36 = v20;
    v36 = qcdr(v36);
    if (v36 == nil) goto v63;
    v36 = elt(env, 1); /* wedge */
    v20 = cons(v36, v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[0];
    fn = elt(env, 2); /* fkern */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    v20 = qcar(v20);
    { popv(1); return onevalue(v20); }

v63:
    v20 = qcar(v20);
    { popv(1); return onevalue(v20); }
/* error exit handlers */
v27:
    popv(1);
    return nil;
}



/* Code for smemql */

static Lisp_Object CC_smemql(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v297;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemql");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v116;

v116:
    v92 = stack[-1];
    if (v92 == nil) goto v40;
    v92 = stack[-1];
    v297 = qcar(v92);
    v92 = stack[0];
    v92 = Lsmemq(nil, v297, v92);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    if (v92 == nil) goto v115;
    v92 = stack[-1];
    v297 = qcar(v92);
    v92 = stack[-2];
    v92 = cons(v297, v92);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    stack[-2] = v92;
    v92 = stack[-1];
    v92 = qcdr(v92);
    stack[-1] = v92;
    goto v116;

v115:
    v92 = stack[-1];
    v92 = qcdr(v92);
    stack[-1] = v92;
    goto v116;

v40:
    v92 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v92);
    }
/* error exit handlers */
v10:
    popv(4);
    return nil;
}



/* Code for plus!: */

static Lisp_Object CC_plusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v323, v324, v325, v326;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v325 = v3;
    v326 = v0;
/* end of prologue */
    v323 = v326;
    v323 = qcdr(v323);
    v324 = qcar(v323);
    stack[-1] = v324;
    v323 = (Lisp_Object)1; /* 0 */
    if (v324 == v323) { popv(6); return onevalue(v325); }
    v323 = v325;
    v323 = qcdr(v323);
    v324 = qcar(v323);
    stack[0] = v324;
    v323 = (Lisp_Object)1; /* 0 */
    if (v324 == v323) { popv(6); return onevalue(v326); }
    v323 = v326;
    v323 = qcdr(v323);
    v323 = qcdr(v323);
    stack[-4] = v323;
    v324 = v325;
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    stack[-2] = v324;
    v324 = difference2(v323, v324);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-5];
    stack[-3] = v324;
    v323 = (Lisp_Object)1; /* 0 */
    if (v324 == v323) goto v5;
    v324 = stack[-3];
    v323 = (Lisp_Object)1; /* 0 */
    v323 = (Lisp_Object)greaterp2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v327;
    v323 = v323 ? lisp_true : nil;
    env = stack[-5];
    if (v323 == nil) goto v58;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v324 = stack[-1];
    v323 = stack[-3];
    v324 = Lash1(nil, v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-5];
    v323 = stack[0];
    v324 = plus2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v327;
    v323 = stack[-2];
    {
        Lisp_Object v328 = stack[-4];
        popv(6);
        return list2star(v328, v324, v323);
    }

v58:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v323 = stack[-3];
    v323 = negate(v323);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-5];
    v323 = Lash1(nil, stack[0], v323);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-5];
    v324 = plus2(stack[-1], v323);
    nil = C_nil;
    if (exception_pending()) goto v327;
    v323 = stack[-4];
    {
        Lisp_Object v329 = stack[-2];
        popv(6);
        return list2star(v329, v324, v323);
    }

v5:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v324 = stack[-1];
    v323 = stack[0];
    v324 = plus2(v324, v323);
    nil = C_nil;
    if (exception_pending()) goto v327;
    v323 = stack[-4];
    {
        Lisp_Object v330 = stack[-2];
        popv(6);
        return list2star(v330, v324, v323);
    }
/* error exit handlers */
v327:
    popv(6);
    return nil;
}



/* Code for listsum */

static Lisp_Object CC_listsum(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v9;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listsum");
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
    goto v116;

v116:
    v33 = stack[0];
    if (v33 == nil) goto v52;
    v33 = stack[0];
    v9 = qcar(v33);
    v33 = stack[-1];
    v33 = cons(v9, v33);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-2];
    stack[-1] = v33;
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v116;

v52:
    v33 = (Lisp_Object)1; /* 0 */
    v9 = v33;
    goto v31;

v31:
    v33 = stack[-1];
    if (v33 == nil) { popv(3); return onevalue(v9); }
    v33 = stack[-1];
    v33 = qcar(v33);
    v33 = plus2(v33, v9);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-2];
    v9 = v33;
    v33 = stack[-1];
    v33 = qcdr(v33);
    stack[-1] = v33;
    goto v31;
/* error exit handlers */
v298:
    popv(3);
    return nil;
}



/* Code for scalopp */

static Lisp_Object CC_scalopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v318, v342, v343;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scalopp");
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
    stack[-3] = v0;
/* end of prologue */
    v318 = stack[-3];
    if (symbolp(v318)) goto v86;
    v318 = qvalue(elt(env, 1)); /* nil */
    goto v116;

v116:
    if (!(v318 == nil)) { popv(6); return onevalue(v318); }
    v318 = stack[-3];
    if (!consp(v318)) goto v253;
    v318 = stack[-3];
    v342 = qcar(v318);
    v318 = elt(env, 2); /* phystype */
    v342 = get(v342, v318);
    env = stack[-5];
    v318 = elt(env, 3); /* scalar */
    if (v342 == v318) goto v344;
    v318 = stack[-3];
    v342 = qcar(v318);
    v318 = elt(env, 2); /* phystype */
    v342 = get(v342, v318);
    env = stack[-5];
    v318 = elt(env, 5); /* vector */
    if (v342 == v318) goto v114;
    v318 = qvalue(elt(env, 1)); /* nil */
    goto v90;

v90:
    if (!(v318 == nil)) { popv(6); return onevalue(v318); }
    v318 = stack[-3];
    v342 = qcar(v318);
    v318 = elt(env, 2); /* phystype */
    v342 = get(v342, v318);
    env = stack[-5];
    v318 = elt(env, 6); /* tensor */
    if (v342 == v318) goto v65;
    v318 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v318); }

v65:
    v318 = stack[-3];
    v318 = qcdr(v318);
    v343 = Llength(nil, v318);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-5];
    v318 = stack[-3];
    v342 = qcar(v318);
    v318 = elt(env, 7); /* tensdimen */
    v318 = get(v342, v318);
    env = stack[-5];
    v318 = (Lisp_Object)geq2(v343, v318);
    nil = C_nil;
    if (exception_pending()) goto v345;
    v318 = v318 ? lisp_true : nil;
    env = stack[-5];
    if (v318 == nil) goto v44;
    v318 = (Lisp_Object)17; /* 1 */
    stack[-4] = v318;
    v318 = stack[-3];
    v342 = qcar(v318);
    v318 = elt(env, 7); /* tensdimen */
    v342 = get(v342, v318);
    env = stack[-5];
    v318 = stack[-4];
    v318 = difference2(v342, v318);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-5];
    v318 = Lminusp(nil, v318);
    env = stack[-5];
    if (v318 == nil) goto v346;
    v318 = qvalue(elt(env, 1)); /* nil */
    goto v81;

v81:
    {
        popv(6);
        fn = elt(env, 8); /* areallindices */
        return (*qfn1(fn))(qenv(fn), v318);
    }

v346:
    v318 = stack[-3];
    v342 = qcdr(v318);
    v318 = stack[-4];
    fn = elt(env, 9); /* pnth */
    v318 = (*qfn2(fn))(qenv(fn), v342, v318);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-5];
    v318 = qcar(v318);
    v318 = ncons(v318);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-5];
    stack[-1] = v318;
    stack[-2] = v318;
    goto v319;

v319:
    v318 = stack[-4];
    v318 = add1(v318);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-5];
    stack[-4] = v318;
    v318 = stack[-3];
    v342 = qcar(v318);
    v318 = elt(env, 7); /* tensdimen */
    v342 = get(v342, v318);
    env = stack[-5];
    v318 = stack[-4];
    v318 = difference2(v342, v318);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-5];
    v318 = Lminusp(nil, v318);
    env = stack[-5];
    if (v318 == nil) goto v234;
    v318 = stack[-2];
    goto v81;

v234:
    stack[0] = stack[-1];
    v318 = stack[-3];
    v342 = qcdr(v318);
    v318 = stack[-4];
    fn = elt(env, 9); /* pnth */
    v318 = (*qfn2(fn))(qenv(fn), v342, v318);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-5];
    v318 = qcar(v318);
    v318 = ncons(v318);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-5];
    v318 = Lrplacd(nil, stack[0], v318);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-5];
    v318 = stack[-1];
    v318 = qcdr(v318);
    stack[-1] = v318;
    goto v319;

v44:
    v318 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v318); }

v114:
    v318 = stack[-3];
    v318 = qcdr(v318);
    v318 = qcar(v318);
    fn = elt(env, 10); /* isanindex */
    v318 = (*qfn1(fn))(qenv(fn), v318);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-5];
    goto v90;

v344:
    v318 = qvalue(elt(env, 4)); /* t */
    { popv(6); return onevalue(v318); }

v253:
    v318 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v318); }

v86:
    v342 = stack[-3];
    v318 = elt(env, 2); /* phystype */
    v342 = get(v342, v318);
    env = stack[-5];
    v318 = elt(env, 3); /* scalar */
    v318 = (v342 == v318 ? lisp_true : nil);
    goto v116;
/* error exit handlers */
v345:
    popv(6);
    return nil;
}



/* Code for sqp */

static Lisp_Object CC_sqp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqp");
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
    v27 = stack[0];
    v27 = Lconsp(nil, v27);
    env = stack[-1];
    if (v27 == nil) goto v84;
    v27 = stack[0];
    v27 = qcar(v27);
    fn = elt(env, 2); /* sfpx */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    if (v27 == nil) goto v64;
    v27 = stack[0];
    v27 = qcdr(v27);
    {
        popv(2);
        fn = elt(env, 2); /* sfpx */
        return (*qfn1(fn))(qenv(fn), v27);
    }

v64:
    v27 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v27); }

v84:
    v27 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v27); }
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for mv!-pow!-!+ */

static Lisp_Object CC_mvKpowKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v295, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v116;

v116:
    v295 = stack[-1];
    if (v295 == nil) goto v40;
    v295 = stack[-1];
    v108 = qcar(v295);
    v295 = stack[0];
    v295 = qcar(v295);
    v108 = plus2(v108, v295);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    v295 = stack[-2];
    v295 = cons(v108, v295);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    stack[-2] = v295;
    v295 = stack[-1];
    v295 = qcdr(v295);
    stack[-1] = v295;
    v295 = stack[0];
    v295 = qcdr(v295);
    stack[0] = v295;
    goto v116;

v40:
    v295 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v295);
    }
/* error exit handlers */
v32:
    popv(4);
    return nil;
}



/* Code for subs3f1 */

static Lisp_Object MS_CDECL CC_subs3f1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v3,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v336, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subs3f1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3f1");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v3,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v3;
    stack[-2] = v0;
/* end of prologue */
    v336 = qvalue(elt(env, 1)); /* nil */
    v237 = (Lisp_Object)17; /* 1 */
    v237 = cons(v336, v237);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-4];
    stack[-3] = v237;
    goto v31;

v31:
    v237 = stack[-2];
    if (v237 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v237 = stack[-2];
    if (!consp(v237)) goto v12;
    v237 = stack[-2];
    v237 = qcar(v237);
    v237 = (consp(v237) ? nil : lisp_true);
    goto v89;

v89:
    if (v237 == nil) goto v28;
    stack[0] = stack[-3];
    v336 = stack[-2];
    v237 = (Lisp_Object)17; /* 1 */
    v237 = cons(v336, v237);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-4];
    {
        Lisp_Object v349 = stack[0];
        popv(5);
        fn = elt(env, 7); /* addsq */
        return (*qfn2(fn))(qenv(fn), v349, v237);
    }

v28:
    v237 = stack[0];
    if (v237 == nil) goto v21;
    v237 = stack[-2];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    if (!consp(v237)) goto v114;
    v237 = stack[-2];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    v237 = (consp(v237) ? nil : lisp_true);
    goto v90;

v90:
    if (v237 == nil) goto v21;
    v237 = stack[-2];
    v237 = qcar(v237);
    v336 = ncons(v237);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-4];
    v237 = (Lisp_Object)17; /* 1 */
    v237 = cons(v336, v237);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-4];
    v69 = v237;
    goto v328;

v328:
    v237 = stack[-3];
    v336 = v69;
    fn = elt(env, 7); /* addsq */
    v237 = (*qfn2(fn))(qenv(fn), v237, v336);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-4];
    stack[-3] = v237;
    v237 = stack[-2];
    v237 = qcdr(v237);
    stack[-2] = v237;
    goto v31;

v21:
    v237 = stack[-2];
    v336 = qcar(v237);
    v237 = stack[-1];
    fn = elt(env, 8); /* subs3t */
    v237 = (*qfn2(fn))(qenv(fn), v336, v237);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-4];
    v69 = v237;
    v237 = stack[0];
    if (v237 == nil) goto v49;
    v237 = qvalue(elt(env, 3)); /* mchfg!* */
    v237 = (v237 == nil ? lisp_true : nil);
    goto v48;

v48:
    if (!(v237 == nil)) goto v328;
    v237 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v237; /* mchfg!* */
    v237 = v69;
    v336 = qcar(v237);
    v237 = stack[-2];
    if (equal(v336, v237)) goto v59;
    v237 = qvalue(elt(env, 1)); /* nil */
    goto v306;

v306:
    if (v237 == nil) goto v341;
    v336 = stack[-2];
    v237 = (Lisp_Object)17; /* 1 */
    v237 = cons(v336, v237);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-4];
    v69 = v237;
    goto v328;

v341:
    v237 = qvalue(elt(env, 4)); /* !*resubs */
    if (v237 == nil) goto v328;
    v237 = qvalue(elt(env, 5)); /* !*sub2 */
    if (!(v237 == nil)) goto v97;
    v237 = qvalue(elt(env, 6)); /* powlis1!* */
    if (!(v237 == nil)) goto v97;

v42:
    v237 = v69;
    fn = elt(env, 9); /* subs3q */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-4];
    v69 = v237;
    goto v328;

v97:
    v237 = v69;
    fn = elt(env, 10); /* subs2q */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-4];
    v69 = v237;
    goto v42;

v59:
    v237 = v69;
    v336 = qcdr(v237);
    v237 = (Lisp_Object)17; /* 1 */
    v237 = (v336 == v237 ? lisp_true : nil);
    goto v306;

v49:
    v237 = qvalue(elt(env, 2)); /* t */
    goto v48;

v114:
    v237 = qvalue(elt(env, 2)); /* t */
    goto v90;

v12:
    v237 = qvalue(elt(env, 2)); /* t */
    goto v89;
/* error exit handlers */
v348:
    popv(5);
    return nil;
}



/* Code for gcddd */

static Lisp_Object CC_gcddd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v235, v78, v294;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcddd");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v235 = v3;
    v78 = v0;
/* end of prologue */
    v294 = v78;
    v77 = (Lisp_Object)17; /* 1 */
    if (v294 == v77) goto v40;
    v294 = v235;
    v77 = (Lisp_Object)17; /* 1 */
    v77 = (v294 == v77 ? lisp_true : nil);
    goto v31;

v31:
    if (v77 == nil) goto v116;
    v77 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v77); }

v116:
    v77 = v78;
    if (!consp(v77)) goto v109;
    v77 = v235;
    if (!consp(v77)) goto v48;
    v77 = v78;
    v294 = qcar(v77);
    v77 = elt(env, 2); /* field */
    v77 = Lflagp(nil, v294, v77);
    env = stack[0];
    if (v77 == nil) goto v352;
    v77 = qvalue(elt(env, 1)); /* t */
    goto v58;

v58:
    if (v77 == nil) goto v292;
    v77 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v77); }

v292:
    v77 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v78, v235, v77);
    }

v352:
    v77 = v235;
    v294 = qcar(v77);
    v77 = elt(env, 2); /* field */
    v77 = Lflagp(nil, v294, v77);
    env = stack[0];
    goto v58;

v48:
    v77 = v78;
    v294 = qcar(v77);
    v77 = elt(env, 2); /* field */
    v77 = Lflagp(nil, v294, v77);
    env = stack[0];
    if (v77 == nil) goto v353;
    v77 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v77); }

v353:
    v77 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v78, v235, v77);
    }

v109:
    v77 = v235;
    if (!consp(v77)) goto v91;
    v77 = v235;
    if (!consp(v77)) goto v22;
    v77 = v235;
    v294 = qcar(v77);
    v77 = elt(env, 2); /* field */
    v77 = Lflagp(nil, v294, v77);
    env = stack[0];
    goto v106;

v106:
    if (v77 == nil) goto v107;
    v77 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v77); }

v107:
    v77 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v78, v235, v77);
    }

v22:
    v77 = qvalue(elt(env, 3)); /* nil */
    goto v106;

v91:
    v77 = v78;
        popv(1);
        return Lgcd(nil, v77, v235);

v40:
    v77 = qvalue(elt(env, 1)); /* t */
    goto v31;
}



/* Code for adddummy1a */

static Lisp_Object MS_CDECL CC_adddummy1a(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v3,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "adddummy1a");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adddummy1a");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v3,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    v22 = v3;
    stack[-2] = v0;
/* end of prologue */

v52:
    v102 = v22;
    if (v102 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v102 = v22;
    v102 = qcdr(v102);
    stack[-3] = v102;
    v102 = stack[-1];
    if (v102 == nil) goto v28;
    v102 = stack[-1];
    v102 = qcar(v102);
    stack[0] = v102;
    goto v32;

v32:
    v102 = qcar(v22);
    v22 = stack[-2];
    v22 = qcdr(v22);
    fn = elt(env, 1); /* pappl_pv */
    v102 = (*qfn2(fn))(qenv(fn), v102, v22);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v22 = stack[-1];
    if (v22 == nil) goto v38;
    v22 = stack[-1];
    v22 = qcdr(v22);
    goto v91;

v91:
    fn = elt(env, 2); /* insert_pv */
    v22 = (*qfn2(fn))(qenv(fn), v102, v22);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v22 = cons(stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-1] = v22;
    v22 = stack[-3];
    goto v52;

v38:
    v22 = stack[-1];
    goto v91;

v28:
    v102 = stack[-2];
    v102 = qcar(v102);
    stack[0] = v102;
    goto v32;
/* error exit handlers */
v45:
    popv(5);
    return nil;
}



/* Code for idcons_ordp */

static Lisp_Object CC_idcons_ordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v14, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idcons_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v3;
    v14 = v0;
/* end of prologue */
    v25 = v14;
    v14 = v15;
    v15 = elt(env, 1); /* atom_compare */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v25, v14, v15);
    }
}



/* Code for clear!-column */

static Lisp_Object MS_CDECL CC_clearKcolumn(Lisp_Object env, int nargs,
                         Lisp_Object v3, Lisp_Object v4,
                         Lisp_Object v82, Lisp_Object v84, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v386, v387, v388, v389, v390, v391, v203, v204, v392, v393;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "clear-column");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clear-column");
#endif
    if (stack >= stacklimit)
    {
        push4(v84,v82,v4,v3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v3,v4,v82,v84);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v84;
    stack[-1] = v82;
    v386 = v4;
    stack[-2] = v3;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* null!-space!-basis */
    qvalue(elt(env, 1)) = nil; /* null!-space!-basis */
    qvalue(elt(env, 1)) = v386; /* null!-space!-basis */
    v386 = (Lisp_Object)1; /* 0 */
    goto v113;

v113:
    v388 = stack[-1];
    v387 = v386;
    v388 = *(Lisp_Object *)((char *)v388 + (CELL-TAG_VECTOR) + ((int32_t)v387/(16/CELL)));
    v387 = stack[-2];
    v388 = *(Lisp_Object *)((char *)v388 + (CELL-TAG_VECTOR) + ((int32_t)v387/(16/CELL)));
    v387 = (Lisp_Object)1; /* 0 */
    if (v388 == v387) goto v20;
    v388 = v386;
    v387 = stack[-2];
    if (((int32_t)(v388)) < ((int32_t)(v387))) goto v240;
    v387 = qvalue(elt(env, 3)); /* nil */
    goto v24;

v24:
    if (v387 == nil) goto v55;
    v388 = (Lisp_Object)((int32_t)(v386) + 0x10);
    v386 = v388;
    v387 = stack[0];
    if (!(((int32_t)(v388)) > ((int32_t)(v387)))) goto v113;
    v387 = stack[-2];
    v386 = qvalue(elt(env, 1)); /* null!-space!-basis */
    v386 = cons(v387, v386);
    nil = C_nil;
    if (exception_pending()) goto v394;
    env = stack[-4];
    goto v31;

v31:
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    { popv(5); return onevalue(v386); }

v55:
    v388 = stack[-1];
    v387 = v386;
    v387 = *(Lisp_Object *)((char *)v388 + (CELL-TAG_VECTOR) + ((int32_t)v387/(16/CELL)));
    v393 = v387;
    v389 = stack[-1];
    v388 = v386;
    v387 = stack[-1];
    v386 = stack[-2];
    v386 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    *(Lisp_Object *)((char *)v389 + (CELL-TAG_VECTOR) + ((int32_t)v388/(16/CELL))) = v386;
    v387 = stack[-1];
    v386 = stack[-2];
    v388 = v393;
    *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL))) = v388;
    v387 = stack[-1];
    v386 = stack[-2];
    v387 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v386 = stack[-2];
    v386 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v386 = Lmodular_reciprocal(nil, v386);
    nil = C_nil;
    if (exception_pending()) goto v394;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v386);
        if (w != 0) w = current_modulus - w;
        v386 = fixnum_of_int(w);
    }
    v393 = v386;
    v386 = (Lisp_Object)1; /* 0 */
    v392 = v386;
    goto v69;

v69:
    v387 = stack[0];
    v386 = v392;
    v386 = (Lisp_Object)(int32_t)((int32_t)v387 - (int32_t)v386 + TAG_FIXNUM);
    v386 = ((intptr_t)(v386) < 0 ? lisp_true : nil);
    if (v386 == nil) goto v259;
    v386 = stack[-2];
    v390 = v386;
    goto v395;

v395:
    v387 = stack[0];
    v386 = v390;
    v386 = (Lisp_Object)(int32_t)((int32_t)v387 - (int32_t)v386 + TAG_FIXNUM);
    v386 = ((intptr_t)(v386) < 0 ? lisp_true : nil);
    if (v386 == nil) goto v209;
    v386 = qvalue(elt(env, 1)); /* null!-space!-basis */
    goto v31;

v209:
    v387 = stack[-1];
    v386 = stack[-2];
    v389 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v388 = v390;
    v387 = stack[-1];
    v386 = stack[-2];
    v387 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v386 = v390;
    v387 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v386 = v393;
    v386 = Lmodular_times(nil, v387, v386);
    env = stack[-4];
    *(Lisp_Object *)((char *)v389 + (CELL-TAG_VECTOR) + ((int32_t)v388/(16/CELL))) = v386;
    v386 = v390;
    v386 = (Lisp_Object)((int32_t)(v386) + 0x10);
    v390 = v386;
    goto v395;

v259:
    v387 = v392;
    v386 = stack[-2];
    if (equal(v387, v386)) goto v71;
    v387 = stack[-1];
    v386 = v392;
    v387 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v386 = stack[-2];
    v386 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v204 = v386;
    v387 = v204;
    v386 = (Lisp_Object)1; /* 0 */
    if (v387 == v386) goto v71;
    v387 = v204;
    v386 = v393;
    v386 = Lmodular_times(nil, v387, v386);
    env = stack[-4];
    v204 = v386;
    v386 = stack[-2];
    v203 = v386;
    goto v396;

v396:
    v387 = stack[0];
    v386 = v203;
    v386 = (Lisp_Object)(int32_t)((int32_t)v387 - (int32_t)v386 + TAG_FIXNUM);
    v386 = ((intptr_t)(v386) < 0 ? lisp_true : nil);
    if (!(v386 == nil)) goto v71;
    v387 = stack[-1];
    v386 = v392;
    v391 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v390 = v203;
    v387 = stack[-1];
    v386 = v392;
    v387 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v386 = v203;
    v389 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v388 = v204;
    v387 = stack[-1];
    v386 = stack[-2];
    v387 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v386 = v203;
    v386 = *(Lisp_Object *)((char *)v387 + (CELL-TAG_VECTOR) + ((int32_t)v386/(16/CELL)));
    v386 = Lmodular_times(nil, v388, v386);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v389) + int_of_fixnum(v386);
        if (w >= current_modulus) w -= current_modulus;
        v386 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v391 + (CELL-TAG_VECTOR) + ((int32_t)v390/(16/CELL))) = v386;
    v386 = v203;
    v386 = (Lisp_Object)((int32_t)(v386) + 0x10);
    v203 = v386;
    goto v396;

v71:
    v386 = v392;
    v386 = (Lisp_Object)((int32_t)(v386) + 0x10);
    v392 = v386;
    goto v69;

v240:
    v388 = stack[-1];
    v387 = v386;
    v388 = *(Lisp_Object *)((char *)v388 + (CELL-TAG_VECTOR) + ((int32_t)v387/(16/CELL)));
    v387 = v386;
    v388 = *(Lisp_Object *)((char *)v388 + (CELL-TAG_VECTOR) + ((int32_t)v387/(16/CELL)));
    v387 = (Lisp_Object)1; /* 0 */
    v387 = (v388 == v387 ? lisp_true : nil);
    v387 = (v387 == nil ? lisp_true : nil);
    goto v24;

v20:
    v387 = qvalue(elt(env, 2)); /* t */
    goto v24;
/* error exit handlers */
v394:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    popv(5);
    return nil;
}



/* Code for mkkl */

static Lisp_Object CC_mkkl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v12, v109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkkl");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v89 = v3;
    v12 = v0;
/* end of prologue */

v116:
    v109 = v12;
    if (v109 == nil) { popv(2); return onevalue(v89); }
    v109 = v12;
    v109 = qcdr(v109);
    stack[0] = v109;
    v12 = qcar(v12);
    v89 = cons(v12, v89);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    v89 = ncons(v89);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    v12 = stack[0];
    goto v116;
/* error exit handlers */
v13:
    popv(2);
    return nil;
}



/* Code for split_f */

static Lisp_Object MS_CDECL CC_split_f(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v3,
                         Lisp_Object v4, Lisp_Object v82, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v251, v331, v301, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "split_f");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_f");
#endif
    if (stack >= stacklimit)
    {
        push4(v82,v4,v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v3,v4,v82);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v82;
    stack[-4] = v4;
    stack[-5] = v3;
    stack[-6] = v0;
/* end of prologue */

v31:
    v251 = stack[-6];
    if (v251 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v251 = stack[-6];
    if (!consp(v251)) goto v86;
    v251 = stack[-6];
    v251 = qcar(v251);
    v251 = (consp(v251) ? nil : lisp_true);
    goto v63;

v63:
    if (v251 == nil) goto v25;
    v331 = stack[-4];
    v251 = stack[-6];
    fn = elt(env, 5); /* multf */
    v331 = (*qfn2(fn))(qenv(fn), v331, v251);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-8];
    v251 = stack[-3];
    v251 = qcar(v251);
    fn = elt(env, 6); /* addf */
    v331 = (*qfn2(fn))(qenv(fn), v331, v251);
    nil = C_nil;
    if (exception_pending()) goto v315;
    v251 = stack[-3];
    v251 = qcdr(v251);
    popv(9);
    return cons(v331, v251);

v25:
    v251 = stack[-6];
    v251 = qcar(v251);
    v251 = qcar(v251);
    v251 = qcar(v251);
    if (!consp(v251)) goto v21;
    v251 = stack[-6];
    v251 = qcar(v251);
    v251 = qcar(v251);
    v251 = qcar(v251);
    v331 = qcar(v251);
    v251 = stack[-5];
    v251 = Lmember(nil, v331, v251);
    goto v6;

v6:
    if (v251 == nil) goto v346;
    v251 = stack[-6];
    v251 = qcar(v251);
    v251 = qcar(v251);
    v331 = qcdr(v251);
    v251 = (Lisp_Object)17; /* 1 */
    if (v331 == v251) goto v322;
    v251 = qvalue(elt(env, 1)); /* t */
    goto v112;

v112:
    if (v251 == nil) goto v80;
    stack[0] = elt(env, 3); /* "SPLIT_F: expression not linear w.r.t." 
*/
    v331 = elt(env, 4); /* list */
    v251 = stack[-5];
    v95 = cons(v331, v251);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-8];
    v301 = qvalue(elt(env, 2)); /* nil */
    v331 = qvalue(elt(env, 2)); /* nil */
    v251 = qvalue(elt(env, 1)); /* t */
    {
        Lisp_Object v401 = stack[0];
        popv(9);
        fn = elt(env, 7); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v401, v95, v301, v331, v251);
    }

v80:
    v251 = stack[-6];
    v251 = qcdr(v251);
    stack[-7] = v251;
    stack[-1] = stack[-3];
    v251 = stack[-6];
    v251 = qcar(v251);
    v251 = qcar(v251);
    stack[0] = qcar(v251);
    v331 = stack[-4];
    v251 = stack[-6];
    v251 = qcar(v251);
    v251 = qcdr(v251);
    fn = elt(env, 5); /* multf */
    v251 = (*qfn2(fn))(qenv(fn), v331, v251);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-8];
    fn = elt(env, 8); /* update_kc_list */
    v251 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-8];
    stack[-3] = v251;
    v251 = stack[-7];
    stack[-6] = v251;
    goto v31;

v322:
    v251 = stack[-6];
    v251 = qcar(v251);
    v331 = qcdr(v251);
    v251 = stack[-5];
    fn = elt(env, 9); /* get_first_kernel */
    v251 = (*qfn2(fn))(qenv(fn), v331, v251);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-8];
    goto v112;

v346:
    v251 = stack[-6];
    v251 = qcdr(v251);
    stack[-7] = v251;
    v251 = stack[-6];
    v251 = qcar(v251);
    stack[-2] = qcdr(v251);
    stack[-1] = stack[-5];
    stack[0] = stack[-4];
    v251 = stack[-6];
    v251 = qcar(v251);
    v331 = qcar(v251);
    v251 = (Lisp_Object)17; /* 1 */
    v251 = cons(v331, v251);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-8];
    v251 = ncons(v251);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-8];
    fn = elt(env, 5); /* multf */
    v331 = (*qfn2(fn))(qenv(fn), stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-8];
    v251 = stack[-3];
    v251 = CC_split_f(env, 4, stack[-2], stack[-1], v331, v251);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-8];
    stack[-3] = v251;
    v251 = stack[-7];
    stack[-6] = v251;
    goto v31;

v21:
    v251 = qvalue(elt(env, 2)); /* nil */
    goto v6;

v86:
    v251 = qvalue(elt(env, 1)); /* t */
    goto v63;
/* error exit handlers */
v315:
    popv(9);
    return nil;
}



/* Code for totalcompare */

static Lisp_Object CC_totalcompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v402, v403;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for totalcompare");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v0;
/* end of prologue */

v52:
    v402 = stack[-1];
    v49 = stack[0];
    if (equal(v402, v49)) goto v83;
    v402 = stack[-1];
    v49 = stack[0];
    fn = elt(env, 4); /* wulessp */
    v49 = (*qfn2(fn))(qenv(fn), v402, v49);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    if (v49 == nil) goto v12;
    v49 = elt(env, 2); /* less */
    { popv(3); return onevalue(v49); }

v12:
    v402 = stack[0];
    v49 = stack[-1];
    fn = elt(env, 4); /* wulessp */
    v49 = (*qfn2(fn))(qenv(fn), v402, v49);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    if (v49 == nil) goto v56;
    v49 = elt(env, 3); /* greater */
    { popv(3); return onevalue(v49); }

v56:
    v49 = stack[-1];
    fn = elt(env, 5); /* wuconstantp */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    if (v49 == nil) goto v6;
    v402 = stack[-1];
    v49 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* totalcompareconstants */
        return (*qfn2(fn))(qenv(fn), v402, v49);
    }

v6:
    v49 = stack[-1];
    v49 = qcar(v49);
    v402 = qcdr(v49);
    v49 = stack[0];
    v49 = qcar(v49);
    v49 = qcdr(v49);
    v49 = CC_totalcompare(env, v402, v49);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v403 = v49;
    v402 = v403;
    v49 = elt(env, 1); /* equal */
    if (!(v402 == v49)) { popv(3); return onevalue(v403); }
    v49 = stack[-1];
    v402 = qcdr(v49);
    v49 = stack[0];
    v49 = qcdr(v49);
    stack[-1] = v402;
    stack[0] = v49;
    goto v52;

v83:
    v49 = elt(env, 1); /* equal */
    { popv(3); return onevalue(v49); }
/* error exit handlers */
v85:
    popv(3);
    return nil;
}



/* Code for intexprnp */

static Lisp_Object CC_intexprnp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v351, v47, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intexprnp");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v351 = v3;
    v47 = v0;
/* end of prologue */
    v51 = qvalue(elt(env, 1)); /* !*revalp */
    if (v51 == nil) goto v83;
    v51 = v47;
    if (!consp(v51)) goto v40;
    v51 = v47;
    v51 = qcar(v51);
    if (symbolp(v51)) goto v5;
    v51 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v51); }

v5:
    v51 = v47;
    v110 = qcar(v51);
    v51 = elt(env, 4); /* intfn */
    v51 = Lflagp(nil, v110, v51);
    env = stack[0];
    if (v51 == nil) goto v21;
    v51 = v47;
    v51 = qcdr(v51);
    {
        popv(1);
        fn = elt(env, 5); /* intexprlisp */
        return (*qfn2(fn))(qenv(fn), v51, v351);
    }

v21:
    v51 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v51); }

v40:
    v51 = v47;
    if (is_number(v51)) goto v15;
    v51 = v47;
    v51 = Latsoc(nil, v51, v351);
    v47 = v51;
    if (v51 == nil) goto v108;
    v51 = v47;
    v51 = qcdr(v51);
    v351 = elt(env, 3); /* integer */
    v51 = (v51 == v351 ? lisp_true : nil);
    { popv(1); return onevalue(v51); }

v108:
    v51 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v51); }

v15:
    v51 = v47;
    v51 = integerp(v51);
    { popv(1); return onevalue(v51); }

v83:
    v51 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v51); }
}



/* Code for rl_external */

static Lisp_Object CC_rl_external(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v344, v115;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_external");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v115 = v3;
    v113 = v0;
/* end of prologue */
    v344 = v113;
    v113 = elt(env, 0); /* rl_external */
    v113 = get(v344, v113);
    v344 = v113;
    v113 = v344;
    if (v113 == nil) goto v14;
    v113 = v115;
    v113 = Latsoc(nil, v113, v344);
    v344 = v113;
    v113 = v344;
    if (v113 == nil) goto v14;
    v113 = v344;
    v113 = qcdr(v113);
    return onevalue(v113);

v14:
    v113 = nil;
    return onevalue(v113);
}



/* Code for aex_deg */

static Lisp_Object CC_aex_deg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_deg");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    v2 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v64 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    v2 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_deg */
        return (*qfn2(fn))(qenv(fn), v64, v2);
    }
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



/* Code for omvir */

static Lisp_Object MS_CDECL CC_omvir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omvir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omvir");
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
    v39 = qvalue(elt(env, 1)); /* atts */
    v38 = elt(env, 2); /* name */
    fn = elt(env, 6); /* find */
    v38 = (*qfn2(fn))(qenv(fn), v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    stack[0] = v38;
    v39 = qvalue(elt(env, 1)); /* atts */
    v38 = elt(env, 3); /* hex */
    fn = elt(env, 6); /* find */
    v38 = (*qfn2(fn))(qenv(fn), v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    if (v38 == nil) goto v295;
    v39 = elt(env, 4); /* "wrong att" */
    v38 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 7); /* errorml */
    v38 = (*qfn2(fn))(qenv(fn), v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    goto v295;

v295:
    v39 = qvalue(elt(env, 1)); /* atts */
    v38 = elt(env, 5); /* dec */
    fn = elt(env, 6); /* find */
    v38 = (*qfn2(fn))(qenv(fn), v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    if (v38 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v39 = elt(env, 4); /* "wrong att" */
    v38 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 7); /* errorml */
    v38 = (*qfn2(fn))(qenv(fn), v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v7;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v7:
    popv(2);
    return nil;
}



/* Code for find_sub_df */

static Lisp_Object CC_find_sub_df(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_sub_df");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v0;
/* end of prologue */

v296:
    v13 = stack[0];
    if (v13 == nil) goto v83;
    v11 = stack[-1];
    v13 = stack[0];
    v13 = qcar(v13);
    fn = elt(env, 2); /* is_sub_df */
    v13 = (*qfn2(fn))(qenv(fn), v11, v13);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-2];
    if (!(v13 == nil)) { popv(3); return onevalue(v13); }
    v11 = stack[-1];
    v13 = stack[0];
    v13 = qcdr(v13);
    stack[-1] = v11;
    stack[0] = v13;
    goto v296;

v83:
    v13 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v13); }
/* error exit handlers */
v115:
    popv(3);
    return nil;
}



/* Code for spmultm2 */

static Lisp_Object MS_CDECL CC_spmultm2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v3,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v365, v366, v409, v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "spmultm2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmultm2");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v3,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v365 = v4;
    stack[-10] = v3;
    stack[-11] = v0;
/* end of prologue */
    v366 = v365;
    v366 = qcdr(v366);
    v366 = qcar(v366);
    fn = elt(env, 3); /* mkempspmat */
    v365 = (*qfn2(fn))(qenv(fn), v366, v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    stack[-12] = v365;
    v365 = stack[-11];
    v365 = qcdr(v365);
    v366 = qcar(v365);
    v365 = stack[-11];
    v365 = qcdr(v365);
    v365 = qcdr(v365);
    v365 = qcar(v365);
    v365 = qcdr(v365);
    v365 = qcar(v365);
    fn = elt(env, 4); /* empty */
    v365 = (*qfn2(fn))(qenv(fn), v366, v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    if (v365 == nil) goto v13;
    v365 = stack[-10];
    v365 = qcdr(v365);
    v366 = qcar(v365);
    v365 = stack[-10];
    v365 = qcdr(v365);
    v365 = qcdr(v365);
    v365 = qcar(v365);
    v365 = qcdr(v365);
    v365 = qcar(v365);
    fn = elt(env, 4); /* empty */
    v365 = (*qfn2(fn))(qenv(fn), v366, v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    v365 = (v365 == nil ? lisp_true : nil);
    goto v35;

v35:
    if (!(v365 == nil)) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v365 = stack[-11];
    v365 = qcdr(v365);
    v365 = qcar(v365);
    stack[-9] = v365;
    v365 = stack[-10];
    v365 = qcdr(v365);
    v365 = qcar(v365);
    stack[-8] = v365;
    v365 = (Lisp_Object)17; /* 1 */
    stack[-3] = v365;
    goto v49;

v49:
    v365 = stack[-11];
    v365 = qcdr(v365);
    v365 = qcdr(v365);
    v365 = qcar(v365);
    v365 = qcdr(v365);
    v366 = qcar(v365);
    v365 = stack[-3];
    v365 = difference2(v366, v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    v365 = Lminusp(nil, v365);
    env = stack[-13];
    if (!(v365 == nil)) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v366 = stack[-9];
    v365 = stack[-3];
    fn = elt(env, 5); /* findrow */
    v365 = (*qfn2(fn))(qenv(fn), v366, v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    stack[-7] = v365;
    v365 = stack[-7];
    if (v365 == nil) goto v238;
    v365 = (Lisp_Object)17; /* 1 */
    stack[-2] = v365;
    goto v410;

v410:
    v365 = stack[-10];
    v365 = qcdr(v365);
    v365 = qcdr(v365);
    v365 = qcar(v365);
    v365 = qcdr(v365);
    v366 = qcar(v365);
    v365 = stack[-2];
    v365 = difference2(v366, v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    v365 = Lminusp(nil, v365);
    env = stack[-13];
    if (!(v365 == nil)) goto v238;
    v366 = stack[-8];
    v365 = stack[-2];
    fn = elt(env, 5); /* findrow */
    v365 = (*qfn2(fn))(qenv(fn), v366, v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    stack[-6] = v365;
    v365 = stack[-6];
    if (v365 == nil) goto v328;
    v365 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 6); /* simp */
    v365 = (*qfn1(fn))(qenv(fn), v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    stack[-4] = v365;
    v365 = stack[-7];
    v365 = qcdr(v365);
    stack[-1] = v365;
    goto v337;

v337:
    v365 = stack[-1];
    if (v365 == nil) goto v339;
    v365 = stack[-1];
    v365 = qcar(v365);
    v366 = v365;
    v365 = v366;
    v365 = qcar(v365);
    v366 = qcdr(v366);
    v409 = v366;
    v366 = v365;
    v365 = stack[-6];
    v365 = Latsoc(nil, v366, v365);
    stack[-5] = v365;
    v365 = stack[-5];
    if (v365 == nil) goto v308;
    v365 = stack[-5];
    v365 = qcdr(v365);
    stack[-5] = v365;
    v365 = v409;
    fn = elt(env, 6); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    v365 = stack[-5];
    fn = elt(env, 6); /* simp */
    v365 = (*qfn1(fn))(qenv(fn), v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    fn = elt(env, 7); /* multsq */
    v365 = (*qfn2(fn))(qenv(fn), stack[0], v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    stack[0] = v365;
    v366 = stack[-4];
    v365 = stack[0];
    fn = elt(env, 8); /* addsq */
    v365 = (*qfn2(fn))(qenv(fn), v366, v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    stack[-4] = v365;
    goto v72;

v72:
    v365 = stack[-1];
    v365 = qcdr(v365);
    stack[-1] = v365;
    goto v337;

v308:
    v365 = stack[-4];
    stack[-4] = v365;
    goto v72;

v339:
    v365 = stack[-4];
    fn = elt(env, 9); /* mk!*sq */
    v365 = (*qfn1(fn))(qenv(fn), v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    stack[0] = v365;
    v366 = stack[0];
    v365 = (Lisp_Object)1; /* 0 */
    if (v366 == v365) goto v328;
    v409 = stack[-12];
    v366 = stack[-3];
    v365 = stack[-2];
    v225 = list3(v409, v366, v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    v409 = stack[0];
    v366 = stack[-12];
    v365 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 10); /* letmtr3 */
    v365 = (*qfnn(fn))(qenv(fn), 4, v225, v409, v366, v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    goto v328;

v328:
    v365 = stack[-2];
    v365 = add1(v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    stack[-2] = v365;
    goto v410;

v238:
    v365 = stack[-3];
    v365 = add1(v365);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-13];
    stack[-3] = v365;
    goto v49;

v13:
    v365 = qvalue(elt(env, 1)); /* t */
    goto v35;
/* error exit handlers */
v377:
    popv(14);
    return nil;
}



/* Code for dm!-minus */

static Lisp_Object CC_dmKminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-minus");
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
    v83 = v0;
/* end of prologue */
    fn = elt(env, 1); /* !:minus */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* nil2zero */
        return (*qfn1(fn))(qenv(fn), v83);
    }
/* error exit handlers */
v116:
    popv(1);
    return nil;
}



/* Code for getcomb */

static Lisp_Object CC_getcomb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v297, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getcomb");
#endif
    if (stack >= stacklimit)
    {
        push2(v3,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v297 = v3;
    stack[0] = v0;
/* end of prologue */
    v32 = v297;
    v297 = qvalue(elt(env, 1)); /* i */
    fn = elt(env, 4); /* nextcomb */
    v297 = (*qfn2(fn))(qenv(fn), v32, v297);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    qvalue(elt(env, 2)) = v297; /* comb */
    v297 = qvalue(elt(env, 2)); /* comb */
    v297 = qcar(v297);
    v32 = qvalue(elt(env, 2)); /* comb */
    v32 = qcdr(v32);
    qvalue(elt(env, 2)) = v32; /* comb */
    v32 = v297;
    if (v32 == nil) goto v108;
    stack[-1] = v297;
    v32 = stack[0];
    fn = elt(env, 5); /* setdiff */
    v297 = (*qfn2(fn))(qenv(fn), v32, v297);
    nil = C_nil;
    if (exception_pending()) goto v10;
    {
        Lisp_Object v8 = stack[-1];
        popv(3);
        return cons(v8, v297);
    }

v108:
    v297 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v297); }
/* error exit handlers */
v10:
    popv(3);
    return nil;
}



setup_type const u09_setup[] =
{
    {"integerom",               CC_integerom,   too_many_1,    wrong_no_1},
    {"ps:putv",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTputv},
    {"maxtype",                 CC_maxtype,     too_many_1,    wrong_no_1},
    {"bsubs",                   CC_bsubs,       too_many_1,    wrong_no_1},
    {"mksgnsq",                 CC_mksgnsq,     too_many_1,    wrong_no_1},
    {"cut:ep",                  too_few_2,      CC_cutTep,     wrong_no_2},
    {"tokquote",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_tokquote},
    {"mo_diff",                 too_few_2,      CC_mo_diff,    wrong_no_2},
    {"pdmult",                  too_few_2,      CC_pdmult,     wrong_no_2},
    {"polynomlistfinddivisor",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_polynomlistfinddivisor},
    {"cancel",                  CC_cancel,      too_many_1,    wrong_no_1},
    {"sfto_tsqsumf",            CC_sfto_tsqsumf,too_many_1,    wrong_no_1},
    {"revv0",                   too_few_2,      CC_revv0,      wrong_no_2},
    {"ibalp_vequal",            too_few_2,      CC_ibalp_vequal,wrong_no_2},
    {"vdp_poly",                CC_vdp_poly,    too_many_1,    wrong_no_1},
    {"naryrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_naryrd},
    {"simpexpon1",              too_few_2,      CC_simpexpon1, wrong_no_2},
    {"simp",                    CC_simp,        too_many_1,    wrong_no_1},
    {"zeropp",                  CC_zeropp,      too_many_1,    wrong_no_1},
    {"gpexp1p",                 CC_gpexp1p,     too_many_1,    wrong_no_1},
    {"chknewnam",               CC_chknewnam,   too_many_1,    wrong_no_1},
    {"mo=lexcomp",              too_few_2,      CC_moMlexcomp, wrong_no_2},
    {"arintequiv:",             CC_arintequivT, too_many_1,    wrong_no_1},
    {"horner-rule",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKrule},
    {"crprcd2",                 too_few_2,      CC_crprcd2,    wrong_no_2},
    {"qqe_arg-check-b",         CC_qqe_argKcheckKb,too_many_1, wrong_no_1},
    {"ibalp_vmember",           too_few_2,      CC_ibalp_vmember,wrong_no_2},
    {"aex_reducedtag",          CC_aex_reducedtag,too_many_1,  wrong_no_1},
    {"diffp1",                  too_few_2,      CC_diffp1,     wrong_no_2},
    {"omiir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omiir},
    {"testredh",                CC_testredh,    too_many_1,    wrong_no_1},
    {"getrtype1",               CC_getrtype1,   too_many_1,    wrong_no_1},
    {"mkuwedge",                CC_mkuwedge,    too_many_1,    wrong_no_1},
    {"smemql",                  too_few_2,      CC_smemql,     wrong_no_2},
    {"plus:",                   too_few_2,      CC_plusT,      wrong_no_2},
    {"listsum",                 CC_listsum,     too_many_1,    wrong_no_1},
    {"scalopp",                 CC_scalopp,     too_many_1,    wrong_no_1},
    {"sqp",                     CC_sqp,         too_many_1,    wrong_no_1},
    {"mv-pow-+",                too_few_2,      CC_mvKpowKL,   wrong_no_2},
    {"subs3f1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subs3f1},
    {"gcddd",                   too_few_2,      CC_gcddd,      wrong_no_2},
    {"adddummy1a",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_adddummy1a},
    {"idcons_ordp",             too_few_2,      CC_idcons_ordp,wrong_no_2},
    {"clear-column",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_clearKcolumn},
    {"mkkl",                    too_few_2,      CC_mkkl,       wrong_no_2},
    {"split_f",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_split_f},
    {"totalcompare",            too_few_2,      CC_totalcompare,wrong_no_2},
    {"intexprnp",               too_few_2,      CC_intexprnp,  wrong_no_2},
    {"rl_external",             too_few_2,      CC_rl_external,wrong_no_2},
    {"aex_deg",                 too_few_2,      CC_aex_deg,    wrong_no_2},
    {"omvir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omvir},
    {"find_sub_df",             too_few_2,      CC_find_sub_df,wrong_no_2},
    {"spmultm2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_spmultm2},
    {"dm-minus",                CC_dmKminus,    too_many_1,    wrong_no_1},
    {"getcomb",                 too_few_2,      CC_getcomb,    wrong_no_2},
    {NULL, (one_args *)"u09", (two_args *)"1560 9861094 3949934", 0}
};

/* end of generated code */
