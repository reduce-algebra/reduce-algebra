
/* $destdir\u45.c        Machine generated C code */

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


/* Code for interglue */

static Lisp_Object MS_CDECL CC_interglue(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v84;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "interglue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for interglue");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v83 = stack[-4];
    if (v83 == nil) goto v85;
    v83 = stack[-3];
    if (v83 == nil) goto v86;
    v83 = stack[-4];
    if (!consp(v83)) goto v87;
    v83 = qvalue(elt(env, 1)); /* t */
    goto v88;

v88:
    if (v83 == nil) goto v89;
    v83 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v83); }

v89:
    v84 = stack[-4];
    v83 = elt(env, 3); /* class */
    v83 = get(v84, v83);
    env = stack[-6];
    stack[0] = v83;
    v84 = stack[-3];
    v83 = elt(env, 3); /* class */
    v83 = get(v84, v83);
    env = stack[-6];
    v84 = stack[0];
    v83 = get(v84, v83);
    env = stack[-6];
    stack[-5] = v83;
    v83 = stack[-5];
    if (v83 == nil) goto v90;
    v84 = stack[-4];
    v83 = elt(env, 4); /* !\co!  */
    if (v84 == v83) goto v91;
    v84 = stack[-5];
    v83 = (Lisp_Object)1; /* 0 */
    v83 = (Lisp_Object)lessp2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    v83 = v83 ? lisp_true : nil;
    env = stack[-6];
    if (v83 == nil) goto v93;
    v84 = stack[-2];
    v83 = (Lisp_Object)1; /* 0 */
    v83 = (Lisp_Object)greaterp2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    v83 = v83 ? lisp_true : nil;
    env = stack[-6];
    if (v83 == nil) goto v94;
    v83 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v83); }

v94:
    v83 = stack[-5];
    v83 = negate(v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    stack[-5] = v83;
    goto v93;

v93:
    v84 = stack[-5];
    v83 = (Lisp_Object)17; /* 1 */
    if (v84 == v83) goto v95;
    v84 = stack[-5];
    v83 = (Lisp_Object)33; /* 2 */
    if (v84 == v83) goto v96;
    v84 = stack[-5];
    v83 = (Lisp_Object)49; /* 3 */
    if (v84 == v83) goto v97;
    v83 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v83); }

v97:
    stack[0] = (Lisp_Object)10485761; /* 655360 */
    v84 = stack[-1];
    v83 = (Lisp_Object)161; /* 10 */
    v84 = times2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    v83 = (Lisp_Object)801; /* 50 */
    v83 = difference2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    {
        Lisp_Object v98 = stack[0];
        popv(7);
        return list2(v98, v83);
    }

v96:
    v84 = stack[-4];
    v83 = elt(env, 5); /* !+ */
    if (v84 == v83) goto v99;
    v84 = stack[-4];
    v83 = elt(env, 6); /* !- */
    v83 = (v84 == v83 ? lisp_true : nil);
    goto v100;

v100:
    if (v83 == nil) goto v101;
    v83 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v83); }

v101:
    v84 = stack[-3];
    v83 = elt(env, 5); /* !+ */
    if (v84 == v83) goto v102;
    v84 = stack[-3];
    v83 = elt(env, 6); /* !- */
    if (v84 == v83) goto v103;
    v83 = qvalue(elt(env, 2)); /* nil */
    goto v104;

v104:
    if (v83 == nil) goto v105;
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v84 = stack[-1];
    v83 = (Lisp_Object)481; /* 30 */
    v84 = times2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    v83 = (Lisp_Object)3361; /* 210 */
    v83 = difference2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    {
        Lisp_Object v106 = stack[0];
        popv(7);
        return list2(v106, v83);
    }

v105:
    v84 = stack[-4];
    v83 = elt(env, 9); /* !\cdot!  */
    if (v84 == v83) goto v107;
    v84 = stack[-3];
    v83 = elt(env, 9); /* !\cdot!  */
    if (v84 == v83) goto v108;
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v84 = stack[-1];
    v83 = (Lisp_Object)161; /* 10 */
    v83 = times2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    {
        Lisp_Object v109 = stack[0];
        popv(7);
        return list2(v109, v83);
    }

v108:
    v83 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v83); }

v107:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v84 = stack[-1];
    v83 = (Lisp_Object)161; /* 10 */
    v84 = times2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    v83 = (Lisp_Object)801; /* 50 */
    v83 = plus2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    {
        Lisp_Object v110 = stack[0];
        popv(7);
        return list2(v110, v83);
    }

v103:
    v84 = stack[0];
    v83 = elt(env, 7); /* ord */
    if (v84 == v83) goto v111;
    v84 = stack[0];
    v83 = elt(env, 8); /* clo */
    v83 = (v84 == v83 ? lisp_true : nil);
    goto v104;

v111:
    v83 = qvalue(elt(env, 1)); /* t */
    goto v104;

v102:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v84 = stack[-1];
    v83 = (Lisp_Object)481; /* 30 */
    v84 = times2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    v83 = (Lisp_Object)6241; /* 390 */
    v83 = difference2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    {
        Lisp_Object v112 = stack[0];
        popv(7);
        return list2(v112, v83);
    }

v99:
    v83 = qvalue(elt(env, 1)); /* t */
    goto v100;

v95:
    stack[0] = (Lisp_Object)1295361; /* 80960 */
    v84 = stack[-1];
    v83 = (Lisp_Object)161; /* 10 */
    v84 = times2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-6];
    v83 = (Lisp_Object)321; /* 20 */
    v83 = plus2(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v92;
    {
        Lisp_Object v113 = stack[0];
        popv(7);
        return list2(v113, v83);
    }

v91:
    v84 = (Lisp_Object)1; /* 0 */
    v83 = (Lisp_Object)-159999; /* -10000 */
    popv(7);
    return list2(v84, v83);

v90:
    v83 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v83); }

v87:
    v83 = stack[-3];
    v83 = (consp(v83) ? nil : lisp_true);
    v83 = (v83 == nil ? lisp_true : nil);
    goto v88;

v86:
    v83 = qvalue(elt(env, 1)); /* t */
    goto v88;

v85:
    v83 = qvalue(elt(env, 1)); /* t */
    goto v88;
/* error exit handlers */
v92:
    popv(7);
    return nil;
}



/* Code for get_rep_of_generator */

static Lisp_Object CC_get_rep_of_generator(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_rep_of_generator");
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
    v122 = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-1] = nil;
    v121 = stack[-2];
    v69 = elt(env, 1); /* id */
    if (v121 == v69) goto v88;
    v69 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = v69;
    v69 = v122;
    stack[0] = v69;
    goto v123;

v123:
    v69 = stack[-3];
    if (v69 == nil) goto v37;
    v69 = qvalue(elt(env, 2)); /* nil */
    goto v124;

v124:
    if (v69 == nil) goto v125;
    v69 = stack[0];
    v69 = qcar(v69);
    v121 = qcar(v69);
    v69 = stack[-2];
    if (!(equal(v121, v69))) goto v126;
    v69 = qvalue(elt(env, 3)); /* t */
    stack[-3] = v69;
    v69 = stack[0];
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v69 = qcar(v69);
    stack[-1] = v69;
    goto v126;

v126:
    v69 = stack[0];
    v69 = qcdr(v69);
    stack[0] = v69;
    goto v123;

v125:
    v69 = stack[-3];
    if (!(v69 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v69 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v69 == nil)) goto v127;
    v69 = elt(env, 5); /* " error in get rep of generators" */
    fn = elt(env, 6); /* lprie */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    goto v127;

v127:
    v69 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v128;
    v69 = nil;
    { popv(5); return onevalue(v69); }

v37:
    v69 = stack[0];
    v121 = Llength(nil, v69);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    v69 = (Lisp_Object)1; /* 0 */
    v69 = (Lisp_Object)greaterp2(v121, v69);
    nil = C_nil;
    if (exception_pending()) goto v128;
    v69 = v69 ? lisp_true : nil;
    env = stack[-4];
    goto v124;

v88:
    v69 = v122;
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v69 = qcar(v69);
    fn = elt(env, 7); /* get!+row!+nr */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* mk!+unit!+mat */
        return (*qfn1(fn))(qenv(fn), v69);
    }
/* error exit handlers */
v128:
    popv(5);
    return nil;
}



/* Code for qqe_length!-graph!-neighbor!-edge */

static Lisp_Object CC_qqe_lengthKgraphKneighborKedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v129;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_length-graph-neighbor-edge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v129 = v0;
/* end of prologue */
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v129 = qcar(v129);
    return onevalue(v129);
}



/* Code for ratpoly_toaf */

static Lisp_Object CC_ratpoly_toaf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_toaf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v130 = v0;
/* end of prologue */
    v86 = v130;
    v86 = qcar(v86);
    if (v86 == nil) goto v114;
    v86 = elt(env, 1); /* prepf */
    {
        fn = elt(env, 2); /* sqform */
        return (*qfn2(fn))(qenv(fn), v130, v86);
    }

v114:
    v86 = (Lisp_Object)1; /* 0 */
    return onevalue(v86);
}



/* Code for formopr */

static Lisp_Object MS_CDECL CC_formopr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v139, v140, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formopr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formopr");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v119 = v2;
    v140 = v1;
    v78 = v0;
/* end of prologue */
    v139 = v119;
    v119 = elt(env, 1); /* symbolic */
    if (v139 == v119) goto v141;
    stack[0] = elt(env, 4); /* operator */
    v119 = v78;
    v119 = qcdr(v119);
    v139 = v140;
    fn = elt(env, 5); /* mkarg */
    v119 = (*qfn2(fn))(qenv(fn), v119, v139);
    nil = C_nil;
    if (exception_pending()) goto v126;
    {
        Lisp_Object v142 = stack[0];
        popv(3);
        return list2(v142, v119);
    }

v141:
    stack[-1] = elt(env, 2); /* flag */
    v119 = v78;
    v119 = qcdr(v119);
    stack[0] = Lmkquote(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v119 = elt(env, 3); /* opfn */
    v119 = Lmkquote(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    {
        Lisp_Object v143 = stack[-1];
        Lisp_Object v144 = stack[0];
        popv(3);
        return list3(v143, v144, v119);
    }
/* error exit handlers */
v126:
    popv(3);
    return nil;
}



/* Code for crn!:onep */

static Lisp_Object CC_crnTonep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v146, v87;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:onep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v87 = v0;
/* end of prologue */
    v123 = v87;
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    v146 = qcar(v123);
    v123 = (Lisp_Object)1; /* 0 */
    if (v146 == v123) goto v141;
    v123 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v123);

v141:
    v123 = v87;
    v123 = qcdr(v123);
    v123 = qcar(v123);
    v146 = elt(env, 1); /* (1 . 1) */
    v123 = (equal(v123, v146) ? lisp_true : nil);
    return onevalue(v123);
}



/* Code for poly!-remainder */

static Lisp_Object CC_polyKremainder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v138, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-remainder");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v137 = v0;
/* end of prologue */
    v145 = v137;
    v138 = elt(env, 1); /* remainder */
    v137 = qvalue(elt(env, 2)); /* nil */
    {
        fn = elt(env, 3); /* poly!-divide!* */
        return (*qfnn(fn))(qenv(fn), 3, v145, v138, v137);
    }
}



/* Code for vdpappendmon */

static Lisp_Object MS_CDECL CC_vdpappendmon(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v127, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdpappendmon");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpappendmon");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v72 = stack[-4];
    if (v72 == nil) goto v88;
    v72 = stack[-4];
    v72 = qcdr(v72);
    v72 = qcdr(v72);
    v72 = qcdr(v72);
    v72 = qcar(v72);
    v72 = (v72 == nil ? lisp_true : nil);
    goto v80;

v80:
    if (v72 == nil) goto v155;
    v127 = stack[-3];
    v72 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); /* vdpfmon */
        return (*qfn2(fn))(qenv(fn), v127, v72);
    }

v155:
    v72 = stack[-3];
    fn = elt(env, 5); /* vbczero!? */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    if (!(v72 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-5] = elt(env, 2); /* vdp */
    v72 = stack[-4];
    v72 = qcdr(v72);
    stack[-1] = qcar(v72);
    v72 = stack[-4];
    v72 = qcdr(v72);
    v72 = qcdr(v72);
    stack[0] = qcar(v72);
    v72 = stack[-4];
    v72 = qcdr(v72);
    v72 = qcdr(v72);
    v72 = qcdr(v72);
    stack[-4] = qcar(v72);
    v91 = stack[-2];
    v127 = stack[-3];
    v72 = qvalue(elt(env, 3)); /* nil */
    v72 = list2star(v91, v127, v72);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 6); /* dipsum */
    v127 = (*qfn2(fn))(qenv(fn), stack[-4], v72);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v72 = qvalue(elt(env, 3)); /* nil */
    v72 = list2(v127, v72);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v122 = stack[-5];
        Lisp_Object v156 = stack[-1];
        Lisp_Object v157 = stack[0];
        popv(7);
        return list3star(v122, v156, v157, v72);
    }

v88:
    v72 = qvalue(elt(env, 1)); /* t */
    goto v80;
/* error exit handlers */
v121:
    popv(7);
    return nil;
}



/* Code for mkset */

static Lisp_Object CC_mkset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkset");
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
    v129 = v0;
/* end of prologue */
    fn = elt(env, 1); /* getrlist */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[0];
    fn = elt(env, 2); /* delete!-dups */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* make!-set */
        return (*qfn1(fn))(qenv(fn), v129);
    }
/* error exit handlers */
v155:
    popv(1);
    return nil;
}



/* Code for find_bubles1_coeff */

static Lisp_Object MS_CDECL CC_find_bubles1_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "find_bubles1_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles1_coeff");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v3;
    stack[0] = v2;
    stack[-1] = v1;
    stack[-4] = v0;
/* end of prologue */

v162:
    v90 = stack[-4];
    if (v90 == nil) goto v85;
    v90 = stack[-4];
    v149 = qcar(v90);
    v90 = stack[0];
    fn = elt(env, 1); /* find_bubles1 */
    v90 = (*qfn2(fn))(qenv(fn), v149, v90);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    stack[-2] = v90;
    v90 = stack[-4];
    stack[-4] = qcdr(v90);
    v90 = stack[-2];
    v149 = qcdr(v90);
    v90 = stack[-1];
    stack[-1] = cons(v149, v90);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    v90 = stack[-2];
    v90 = qcar(v90);
    if (v90 == nil) goto v142;
    v90 = stack[-2];
    v149 = qcar(v90);
    v90 = stack[-3];
    v90 = cons(v149, v90);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-5];
    goto v131;

v131:
    stack[-3] = v90;
    goto v162;

v142:
    v90 = stack[-3];
    goto v131;

v85:
    v149 = stack[-3];
    v90 = stack[-1];
    popv(6);
    return cons(v149, v90);
/* error exit handlers */
v163:
    popv(6);
    return nil;
}



/* Code for pst_d1 */

static Lisp_Object MS_CDECL CC_pst_d1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pst_d1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_d1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v2;
    stack[-11] = v1;
    v177 = v0;
/* end of prologue */
    stack[0] = stack[-10];
    v177 = sub1(v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    stack[-12] = v177;
    v177 = stack[-12];
    if (v177 == nil) goto v179;
    v177 = stack[-12];
    v177 = qcar(v177);
    stack[-6] = v177;
    stack[0] = stack[-10];
    v177 = stack[-11];
    v177 = sub1(v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    stack[-5] = v177;
    v177 = stack[-5];
    if (v177 == nil) goto v119;
    v177 = stack[-5];
    v177 = qcar(v177);
    stack[-1] = v177;
    v177 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v177 = (*qfn2(fn))(qenv(fn), stack[0], v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = qcar(v177);
    fn = elt(env, 4); /* ordn */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = ncons(v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    stack[-3] = v177;
    stack[-4] = v177;
    goto v124;

v124:
    v177 = stack[-5];
    v177 = qcdr(v177);
    stack[-5] = v177;
    v177 = stack[-5];
    if (v177 == nil) goto v149;
    stack[-2] = stack[-3];
    v177 = stack[-5];
    v177 = qcar(v177);
    stack[-1] = v177;
    v177 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v177 = (*qfn2(fn))(qenv(fn), stack[0], v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = qcar(v177);
    fn = elt(env, 4); /* ordn */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = ncons(v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = Lrplacd(nil, stack[-2], v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = stack[-3];
    v177 = qcdr(v177);
    stack[-3] = v177;
    goto v124;

v149:
    v177 = stack[-4];
    goto v118;

v118:
    fn = elt(env, 4); /* ordn */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = ncons(v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    stack[-8] = v177;
    stack[-9] = v177;
    goto v80;

v80:
    v177 = stack[-12];
    v177 = qcdr(v177);
    stack[-12] = v177;
    v177 = stack[-12];
    if (v177 == nil) { Lisp_Object res = stack[-9]; popv(14); return onevalue(res); }
    stack[-7] = stack[-8];
    v177 = stack[-12];
    v177 = qcar(v177);
    stack[-6] = v177;
    stack[0] = stack[-10];
    v177 = stack[-11];
    v177 = sub1(v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    stack[-5] = v177;
    v177 = stack[-5];
    if (v177 == nil) goto v180;
    v177 = stack[-5];
    v177 = qcar(v177);
    stack[-1] = v177;
    v177 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v177 = (*qfn2(fn))(qenv(fn), stack[0], v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = qcar(v177);
    fn = elt(env, 4); /* ordn */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = ncons(v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    stack[-3] = v177;
    stack[-4] = v177;
    goto v181;

v181:
    v177 = stack[-5];
    v177 = qcdr(v177);
    stack[-5] = v177;
    v177 = stack[-5];
    if (v177 == nil) goto v182;
    stack[-2] = stack[-3];
    v177 = stack[-5];
    v177 = qcar(v177);
    stack[-1] = v177;
    v177 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v177 = (*qfn2(fn))(qenv(fn), stack[0], v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = qcar(v177);
    fn = elt(env, 4); /* ordn */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = ncons(v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = Lrplacd(nil, stack[-2], v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = stack[-3];
    v177 = qcdr(v177);
    stack[-3] = v177;
    goto v181;

v182:
    v177 = stack[-4];
    goto v183;

v183:
    fn = elt(env, 4); /* ordn */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = ncons(v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = Lrplacd(nil, stack[-7], v177);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-13];
    v177 = stack[-8];
    v177 = qcdr(v177);
    stack[-8] = v177;
    goto v80;

v180:
    v177 = qvalue(elt(env, 1)); /* nil */
    goto v183;

v119:
    v177 = qvalue(elt(env, 1)); /* nil */
    goto v118;

v179:
    v177 = qvalue(elt(env, 1)); /* nil */
    { popv(14); return onevalue(v177); }
/* error exit handlers */
v178:
    popv(14);
    return nil;
}



/* Code for modroots2 */

static Lisp_Object MS_CDECL CC_modroots2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v193, v180, v194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "modroots2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modroots2");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v180 = v2;
    stack[-3] = v1;
    v194 = v0;
/* end of prologue */
    v192 = v194;
    if (!consp(v192)) goto v138;
    v192 = v194;
    v192 = qcar(v192);
    v192 = (consp(v192) ? nil : lisp_true);
    goto v137;

v137:
    if (v192 == nil) goto v134;
    v192 = v194;
    goto v80;

v80:
    if (v192 == nil) goto v155;
    v192 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v192); }

v155:
    v192 = v194;
    if (v192 == nil) goto v12;
    v193 = stack[-3];
    v192 = (Lisp_Object)33; /* 2 */
    if (v193 == v192) goto v65;
    v193 = v194;
    v192 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); /* modroots3 */
        return (*qfn2(fn))(qenv(fn), v193, v192);
    }

v65:
    v193 = v194;
    v192 = qvalue(elt(env, 1)); /* t */
    {
        popv(6);
        fn = elt(env, 5); /* modroots4 */
        return (*qfnn(fn))(qenv(fn), 3, v193, v192, v180);
    }

v12:
    v193 = stack[-3];
    v192 = (Lisp_Object)33; /* 2 */
    if (v193 == v192) goto v132;
    v192 = qvalue(elt(env, 2)); /* nil */
    goto v195;

v195:
    if (v192 == nil) goto v79;
    v192 = elt(env, 3); /* (-1 0 1) */
    { popv(6); return onevalue(v192); }

v79:
    v192 = (Lisp_Object)1; /* 0 */
    stack[-4] = v192;
    v192 = stack[-3];
    v193 = sub1(v192);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    v192 = stack[-4];
    v192 = difference2(v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    v192 = Lminusp(nil, v192);
    env = stack[-5];
    if (v192 == nil) goto v148;
    v192 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v192); }

v148:
    v192 = stack[-4];
    v192 = ncons(v192);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    stack[-1] = v192;
    stack[-2] = v192;
    goto v76;

v76:
    v192 = stack[-4];
    v192 = add1(v192);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    stack[-4] = v192;
    v192 = stack[-3];
    v193 = sub1(v192);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    v192 = stack[-4];
    v192 = difference2(v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    v192 = Lminusp(nil, v192);
    env = stack[-5];
    if (!(v192 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v192 = stack[-4];
    v192 = ncons(v192);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    v192 = Lrplacd(nil, stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    v192 = stack[-1];
    v192 = qcdr(v192);
    stack[-1] = v192;
    goto v76;

v132:
    v192 = v180;
    goto v195;

v134:
    v192 = qvalue(elt(env, 2)); /* nil */
    goto v80;

v138:
    v192 = qvalue(elt(env, 1)); /* t */
    goto v137;
/* error exit handlers */
v173:
    popv(6);
    return nil;
}



/* Code for solvevars */

static Lisp_Object CC_solvevars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvevars");
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
    v132 = v0;
/* end of prologue */
    v195 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v195;
    v195 = v132;
    fn = elt(env, 2); /* allbkern */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[-1] = v195;
    goto v155;

v155:
    v195 = stack[-1];
    if (v195 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v195 = stack[-1];
    v195 = qcar(v195);
    stack[0] = v195;
    v195 = stack[0];
    fn = elt(env, 3); /* constant_exprp */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    if (!(v195 == nil)) goto v130;
    v132 = stack[0];
    v195 = stack[-2];
    fn = elt(env, 4); /* ordad */
    v195 = (*qfn2(fn))(qenv(fn), v132, v195);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[-2] = v195;
    goto v130;

v130:
    v195 = stack[-1];
    v195 = qcdr(v195);
    stack[-1] = v195;
    goto v155;
/* error exit handlers */
v75:
    popv(4);
    return nil;
}



/* Code for rl_trygauss */

static Lisp_Object MS_CDECL CC_rl_trygauss(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v114, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v124, v195, v132, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rl_trygauss");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_trygauss");
#endif
    if (stack >= stacklimit)
    {
        push5(v114,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v114);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v118 = v114;
    v124 = v3;
    v195 = v2;
    v132 = v1;
    v131 = v0;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* rl_trygauss!* */
    stack[-2] = v131;
    stack[-1] = v132;
    stack[0] = v195;
    v118 = list2(v124, v118);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    v118 = list3star(stack[-2], stack[-1], stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    {
        Lisp_Object v191 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v191, v118);
    }
/* error exit handlers */
v197:
    popv(5);
    return nil;
}



/* Code for initmonomials */

static Lisp_Object MS_CDECL CC_initmonomials(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "initmonomials");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initmonomials");
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
    v75 = qvalue(elt(env, 1)); /* fluidbibasisvariables */
    v75 = Llength(nil, v75);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    qvalue(elt(env, 2)) = v75; /* fluidbibasisnumberofvariables */
    v75 = qvalue(elt(env, 2)); /* fluidbibasisnumberofvariables */
    v75 = Lmkvect(nil, v75);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    qvalue(elt(env, 3)) = v75; /* fluidbibasissinglevariablemonomialss 
*/
    v75 = (Lisp_Object)17; /* 1 */
    stack[-2] = v75;
    goto v120;

v120:
    v161 = qvalue(elt(env, 2)); /* fluidbibasisnumberofvariables */
    v75 = stack[-2];
    v75 = difference2(v161, v75);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    v75 = Lminusp(nil, v75);
    env = stack[-3];
    if (v75 == nil) goto v196;
    v75 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v75; /* fluidbibasistripleid */
    v75 = nil;
    { popv(4); return onevalue(v75); }

v196:
    stack[-1] = qvalue(elt(env, 3)); /* fluidbibasissinglevariablemonomialss 
*/
    stack[0] = stack[-2];
    v75 = stack[-2];
    fn = elt(env, 6); /* createsinglevariablemonom */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v75;
    v75 = stack[-2];
    v75 = add1(v75);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    stack[-2] = v75;
    goto v120;
/* error exit handlers */
v133:
    popv(4);
    return nil;
}



/* Code for letscalar */

static Lisp_Object MS_CDECL CC_letscalar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v114, Lisp_Object v117, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v253, v254, v255, v256, v257, v258;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "letscalar");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letscalar");
#endif
    if (stack >= stacklimit)
    {
        push6(v117,v114,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v2,v3,v114,v117);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v117;
    stack[-3] = v114;
    stack[-4] = v3;
    stack[-5] = v2;
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    v253 = stack[-4];
    if (!consp(v253)) goto v147;
    v253 = stack[-4];
    v253 = qcar(v253);
    if (symbolp(v253)) goto v12;
    v257 = elt(env, 1); /* "Syntax error:" */
    v256 = stack[-7];
    v255 = elt(env, 2); /* "invalid" */
    v254 = qvalue(elt(env, 3)); /* nil */
    v253 = elt(env, 4); /* hold */
    {
        popv(10);
        fn = elt(env, 31); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v257, v256, v255, v254, v253);
    }

v12:
    v253 = stack[-4];
    v254 = qcar(v253);
    v253 = elt(env, 5); /* df */
    if (v254 == v253) goto v160;
    v253 = stack[-4];
    v253 = qcar(v253);
    fn = elt(env, 32); /* getrtype */
    v253 = (*qfn1(fn))(qenv(fn), v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    if (v253 == nil) goto v156;
    v253 = stack[-4];
    fn = elt(env, 33); /* reval */
    v256 = (*qfn1(fn))(qenv(fn), v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v255 = stack[-6];
    v254 = stack[-5];
    v253 = stack[-3];
    {
        popv(10);
        fn = elt(env, 34); /* let2 */
        return (*qfnn(fn))(qenv(fn), 4, v256, v255, v254, v253);
    }

v156:
    v253 = stack[-4];
    v254 = qcar(v253);
    v253 = elt(env, 6); /* simpfn */
    v253 = get(v254, v253);
    env = stack[-9];
    if (!(v253 == nil)) goto v260;
    v253 = stack[-4];
    v254 = qcar(v253);
    v253 = elt(env, 7); /* "operator" */
    fn = elt(env, 35); /* redmsg */
    v253 = (*qfn2(fn))(qenv(fn), v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v253 = stack[-4];
    v253 = qcar(v253);
    fn = elt(env, 36); /* mkop */
    v253 = (*qfn1(fn))(qenv(fn), v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v257 = stack[-7];
    v256 = stack[-6];
    v255 = stack[-5];
    v254 = stack[-3];
    v253 = stack[-2];
    {
        popv(10);
        fn = elt(env, 37); /* let3 */
        return (*qfnn(fn))(qenv(fn), 5, v257, v256, v255, v254, v253);
    }

v260:
    v254 = stack[-4];
    v253 = elt(env, 23); /* expt */
    if (!consp(v254)) goto v261;
    v254 = qcar(v254);
    if (!(v254 == v253)) goto v261;
    v253 = stack[-4];
    v253 = qcdr(v253);
    v253 = qcdr(v253);
    v254 = qcar(v253);
    v253 = qvalue(elt(env, 24)); /* frlis!* */
    v253 = Lmemq(nil, v254, v253);
    goto v105;

v105:
    if (v253 == nil) goto v97;
    stack[-8] = stack[-7];
    stack[-1] = stack[-6];
    stack[0] = stack[-5];
    v255 = stack[-4];
    v254 = (Lisp_Object)17; /* 1 */
    v253 = (Lisp_Object)17; /* 1 */
    v253 = acons(v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v254 = ncons(v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v253 = (Lisp_Object)17; /* 1 */
    v255 = cons(v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v254 = stack[-3];
    v253 = stack[-2];
    fn = elt(env, 38); /* letexprn */
    v253 = (*qfnn(fn))(qenv(fn), 6, stack[-8], stack[-1], stack[0], v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    goto v262;

v262:
    v253 = qvalue(elt(env, 21)); /* t */
    stack[0] = qvalue(elt(env, 28)); /* !*precise */
    qvalue(elt(env, 28)) = v253; /* !*precise */
    v253 = stack[-4];
    fn = elt(env, 39); /* simp0 */
    v253 = (*qfn1(fn))(qenv(fn), v253);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    stack[-4] = v253;
    qvalue(elt(env, 28)) = stack[0]; /* !*precise */
    v253 = stack[-4];
    v253 = qcar(v253);
    if (!consp(v253)) goto v264;
    v253 = stack[-4];
    v253 = qcar(v253);
    v253 = qcar(v253);
    v253 = (consp(v253) ? nil : lisp_true);
    goto v265;

v265:
    if (v253 == nil) goto v266;
    v257 = elt(env, 29); /* "Substitution for" */
    v256 = stack[-7];
    v255 = elt(env, 30); /* "not allowed" */
    v254 = qvalue(elt(env, 3)); /* nil */
    v253 = qvalue(elt(env, 21)); /* t */
    {
        popv(10);
        fn = elt(env, 31); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v257, v256, v255, v254, v253);
    }

v266:
    v258 = stack[-7];
    v257 = stack[-6];
    v256 = stack[-5];
    v255 = stack[-4];
    v254 = stack[-3];
    v253 = stack[-2];
    {
        popv(10);
        fn = elt(env, 38); /* letexprn */
        return (*qfnn(fn))(qenv(fn), 6, v258, v257, v256, v255, v254, v253);
    }

v264:
    v253 = qvalue(elt(env, 21)); /* t */
    goto v265;

v97:
    v254 = stack[-4];
    v253 = elt(env, 25); /* sqrt */
    if (!consp(v254)) goto v262;
    v254 = qcar(v254);
    if (!(v254 == v253)) goto v262;
    v253 = qvalue(elt(env, 21)); /* t */
    qvalue(elt(env, 26)) = v253; /* !*sqrtrulep */
    v255 = elt(env, 23); /* expt */
    v253 = stack[-4];
    v253 = qcdr(v253);
    v254 = qcar(v253);
    v253 = elt(env, 27); /* (quotient 1 2) */
    v256 = list3(v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v255 = stack[-6];
    v254 = stack[-5];
    v253 = stack[-3];
    fn = elt(env, 34); /* let2 */
    v253 = (*qfnn(fn))(qenv(fn), 4, v256, v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    goto v262;

v261:
    v253 = qvalue(elt(env, 3)); /* nil */
    goto v105;

v160:
    v257 = stack[-7];
    v256 = stack[-6];
    v255 = stack[-5];
    v254 = stack[-4];
    v253 = stack[-3];
    fn = elt(env, 40); /* letdf */
    v253 = (*qfnn(fn))(qenv(fn), 5, v257, v256, v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    if (v253 == nil) goto v260;
    v253 = qvalue(elt(env, 3)); /* nil */
    { popv(10); return onevalue(v253); }

v147:
    v253 = stack[-3];
    if (v253 == nil) goto v58;
    v253 = qvalue(elt(env, 3)); /* nil */
    goto v194;

v194:
    if (v253 == nil) goto v260;
    v254 = stack[-4];
    v253 = elt(env, 8); /* avalue */
    v253 = Lremprop(nil, v254, v253);
    env = stack[-9];
    v254 = stack[-4];
    v253 = elt(env, 9); /* rtype */
    v253 = Lremprop(nil, v254, v253);
    env = stack[-9];
    v253 = stack[-4];
    v254 = ncons(v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v253 = elt(env, 10); /* antisymmetric */
    v253 = Lremflag(nil, v254, v253);
    env = stack[-9];
    v254 = stack[-4];
    v253 = elt(env, 11); /* infix */
    v253 = Lremprop(nil, v254, v253);
    env = stack[-9];
    v254 = stack[-4];
    v253 = elt(env, 12); /* kvalue */
    v253 = Lremprop(nil, v254, v253);
    env = stack[-9];
    v253 = stack[-4];
    v254 = ncons(v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v253 = elt(env, 13); /* linear */
    v253 = Lremflag(nil, v254, v253);
    env = stack[-9];
    v253 = stack[-4];
    v254 = ncons(v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v253 = elt(env, 14); /* noncom */
    v253 = Lremflag(nil, v254, v253);
    env = stack[-9];
    v254 = stack[-4];
    v253 = elt(env, 15); /* op */
    v253 = Lremprop(nil, v254, v253);
    env = stack[-9];
    v254 = stack[-4];
    v253 = elt(env, 16); /* opmtch */
    v253 = Lremprop(nil, v254, v253);
    env = stack[-9];
    v254 = stack[-4];
    v253 = elt(env, 6); /* simpfn */
    v253 = Lremprop(nil, v254, v253);
    env = stack[-9];
    v253 = stack[-4];
    v254 = ncons(v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v253 = elt(env, 17); /* symmetric */
    v253 = Lremflag(nil, v254, v253);
    env = stack[-9];
    v254 = stack[-4];
    v253 = qvalue(elt(env, 18)); /* wtl!* */
    fn = elt(env, 41); /* delasc */
    v253 = (*qfn2(fn))(qenv(fn), v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    qvalue(elt(env, 18)) = v253; /* wtl!* */
    v254 = stack[-4];
    v253 = elt(env, 19); /* opfn */
    v253 = Lflagp(nil, v254, v253);
    env = stack[-9];
    if (v253 == nil) goto v267;
    v253 = stack[-4];
    v254 = ncons(v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v253 = elt(env, 19); /* opfn */
    v253 = Lremflag(nil, v254, v253);
    env = stack[-9];
    v253 = stack[-4];
    v253 = Lremd(nil, v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    goto v267;

v267:
    v254 = qvalue(elt(env, 20)); /* !*sqvar!* */
    v253 = qvalue(elt(env, 3)); /* nil */
    v253 = Lrplaca(nil, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    v253 = qvalue(elt(env, 21)); /* t */
    v253 = ncons(v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    qvalue(elt(env, 20)) = v253; /* !*sqvar!* */
    v253 = qvalue(elt(env, 3)); /* nil */
    v253 = ncons(v253);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-9];
    qvalue(elt(env, 22)) = v253; /* alglist!* */
    v253 = qvalue(elt(env, 3)); /* nil */
    { popv(10); return onevalue(v253); }

v58:
    v253 = stack[-5];
    v253 = (v253 == nil ? lisp_true : nil);
    goto v194;
/* error exit handlers */
v263:
    env = stack[-9];
    qvalue(elt(env, 28)) = stack[0]; /* !*precise */
    popv(10);
    return nil;
v259:
    popv(10);
    return nil;
}



/* Code for delqip */

static Lisp_Object CC_delqip(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v174, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delqip");
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
    v118 = v0;
/* end of prologue */
    v175 = stack[0];
    if (!consp(v175)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v174 = v118;
    v175 = stack[0];
    v175 = qcar(v175);
    if (v174 == v175) goto v80;
    v174 = v118;
    v175 = stack[0];
    fn = elt(env, 1); /* delqip1 */
    v175 = (*qfn2(fn))(qenv(fn), v174, v175);
    nil = C_nil;
    if (exception_pending()) goto v195;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v80:
    v175 = stack[0];
    v175 = qcdr(v175);
    { popv(1); return onevalue(v175); }
/* error exit handlers */
v195:
    popv(1);
    return nil;
}



/* Code for pm!:gensym */

static Lisp_Object MS_CDECL CC_pmTgensym(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "pm:gensym");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pm:gensym");
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
    stack[-1] = elt(env, 1); /* !? */
    stack[0] = elt(env, 2); /* !_ */
    v145 = qvalue(elt(env, 3)); /* pm!:gensym!-count!* */
    v145 = add1(v145);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    qvalue(elt(env, 3)) = v145; /* pm!:gensym!-count!* */
    v145 = Lexplode(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    v145 = list2star(stack[-1], stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v120;
        popv(3);
        return Lcompress(nil, v145);
/* error exit handlers */
v120:
    popv(3);
    return nil;
}



/* Code for texaeval */

static Lisp_Object CC_texaeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for texaeval");
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
    v136 = v0;
/* end of prologue */
    v196 = qvalue(elt(env, 1)); /* !*lasimp */
    if (v196 == nil) goto v86;
    stack[0] = elt(env, 2); /* tex */
    v196 = v136;
    fn = elt(env, 3); /* aeval */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v123;
    {
        Lisp_Object v146 = stack[0];
        popv(1);
        return list2(v146, v196);
    }

v86:
    v196 = elt(env, 2); /* tex */
    popv(1);
    return list2(v196, v136);
/* error exit handlers */
v123:
    popv(1);
    return nil;
}



/* Code for deflate1 */

static Lisp_Object CC_deflate1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v186, v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deflate1");
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
    stack[-6] = v1;
    v185 = v0;
/* end of prologue */
    stack[-7] = nil;
    fn = elt(env, 3); /* ncoeffs */
    v186 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-8];
    v185 = v186;
    v186 = qcar(v186);
    stack[-5] = v186;
    v185 = qcdr(v185);
    v186 = v185;
    v186 = qcar(v186);
    stack[-4] = v186;
    v185 = qcdr(v185);
    stack[-3] = v185;
    goto v120;

v120:
    v185 = stack[-3];
    if (v185 == nil) goto v270;
    v185 = stack[-3];
    v185 = qcar(v185);
    stack[-2] = v185;
    v185 = stack[-5];
    v185 = sub1(v185);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-8];
    stack[-5] = v185;
    v185 = stack[-4];
    v185 = qcdr(v185);
    v186 = qcar(v185);
    v185 = (Lisp_Object)1; /* 0 */
    if (v186 == v185) goto v271;
    v164 = stack[-5];
    v186 = stack[-4];
    v185 = stack[-7];
    v185 = acons(v164, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-8];
    stack[-7] = v185;
    goto v271;

v271:
    stack[-1] = elt(env, 2); /* !:rd!: */
    v185 = stack[-6];
    v185 = qcdr(v185);
    v186 = qcar(v185);
    v185 = stack[-4];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    stack[0] = times2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-8];
    v185 = stack[-6];
    v185 = qcdr(v185);
    v186 = qcdr(v185);
    v185 = stack[-4];
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    v185 = plus2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-8];
    v185 = list2star(stack[-1], stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-8];
    stack[-4] = v185;
    v185 = stack[-2];
    if (v185 == nil) goto v189;
    v186 = stack[-2];
    v185 = stack[-4];
    fn = elt(env, 4); /* plus!: */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-8];
    stack[-4] = v185;
    goto v189;

v189:
    v185 = stack[-3];
    v185 = qcdr(v185);
    stack[-3] = v185;
    goto v120;

v270:
    v186 = stack[-4];
    v185 = stack[-7];
    popv(9);
    return cons(v186, v185);
/* error exit handlers */
v165:
    popv(9);
    return nil;
}



/* Code for simplog */

static Lisp_Object CC_simplog(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v280, v281, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simplog");
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
    v280 = stack[-1];
    v281 = qcdr(v280);
    v280 = elt(env, 0); /* simplog */
    fn = elt(env, 8); /* carx */
    v280 = (*qfn2(fn))(qenv(fn), v281, v280);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-2] = v280;
    v280 = qvalue(elt(env, 1)); /* !*expandlogs */
    if (v280 == nil) goto v145;
    v280 = qvalue(elt(env, 2)); /* nil */
    stack[0] = qvalue(elt(env, 1)); /* !*expandlogs */
    qvalue(elt(env, 1)) = v280; /* !*expandlogs */
    v167 = stack[-2];
    v280 = stack[-1];
    v281 = qcar(v280);
    v280 = elt(env, 3); /* log10 */
    if (v281 == v280) goto v123;
    v280 = qvalue(elt(env, 2)); /* nil */
    goto v134;

v134:
    fn = elt(env, 9); /* simplogbi */
    v280 = (*qfn2(fn))(qenv(fn), v167, v280);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    fn = elt(env, 10); /* resimp */
    v280 = (*qfn1(fn))(qenv(fn), v280);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* !*expandlogs */
    { popv(4); return onevalue(v280); }

v123:
    v280 = (Lisp_Object)161; /* 10 */
    goto v134;

v145:
    v280 = stack[-2];
    v280 = integerp(v280);
    if (v280 == nil) goto v164;
    v280 = stack[-1];
    v281 = qcar(v280);
    v280 = elt(env, 3); /* log10 */
    if (v281 == v280) goto v79;
    v280 = qvalue(elt(env, 2)); /* nil */
    goto v78;

v78:
    if (v280 == nil) goto v164;
    v281 = stack[-2];
    v280 = stack[-1];
    v167 = qcar(v280);
    v280 = elt(env, 3); /* log10 */
    if (v167 == v280) goto v69;
    v280 = qvalue(elt(env, 2)); /* nil */
    v167 = v280;
    goto v91;

v91:
    v280 = qvalue(elt(env, 5)); /* t */
    {
        popv(4);
        fn = elt(env, 11); /* simplogbn */
        return (*qfnn(fn))(qenv(fn), 3, v281, v167, v280);
    }

v69:
    v280 = (Lisp_Object)161; /* 10 */
    v167 = v280;
    goto v91;

v164:
    v281 = stack[-2];
    v280 = elt(env, 6); /* quotient */
    if (!consp(v281)) goto v282;
    v281 = qcar(v281);
    if (!(v281 == v280)) goto v282;
    v280 = stack[-2];
    v280 = qcdr(v280);
    v281 = qcar(v280);
    v280 = (Lisp_Object)17; /* 1 */
    if (v281 == v280) goto v165;
    v280 = qvalue(elt(env, 2)); /* nil */
    goto v247;

v247:
    if (v280 == nil) goto v54;
    v280 = stack[-1];
    v281 = qcar(v280);
    v280 = stack[-2];
    v280 = qcdr(v280);
    v280 = qcdr(v280);
    v280 = cons(v281, v280);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    fn = elt(env, 12); /* simpiden */
    v280 = (*qfn1(fn))(qenv(fn), v280);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[0] = v280;
    v280 = stack[0];
    v280 = qcar(v280);
    fn = elt(env, 13); /* negf */
    v281 = (*qfn1(fn))(qenv(fn), v280);
    nil = C_nil;
    if (exception_pending()) goto v51;
    v280 = stack[0];
    v280 = qcdr(v280);
    popv(4);
    return cons(v281, v280);

v54:
    v280 = stack[-1];
    {
        popv(4);
        fn = elt(env, 12); /* simpiden */
        return (*qfn1(fn))(qenv(fn), v280);
    }

v165:
    v280 = qvalue(elt(env, 7)); /* !*precise */
    if (v280 == nil) goto v193;
    v280 = stack[-2];
    v280 = qcdr(v280);
    v280 = qcdr(v280);
    v280 = qcar(v280);
    fn = elt(env, 14); /* realvaluedp */
    v280 = (*qfn1(fn))(qenv(fn), v280);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    goto v247;

v193:
    v280 = qvalue(elt(env, 5)); /* t */
    goto v247;

v282:
    v280 = qvalue(elt(env, 2)); /* nil */
    goto v247;

v79:
    v280 = qvalue(elt(env, 4)); /* dmode!* */
    if (v280 == nil) goto v116;
    v281 = elt(env, 3); /* log10 */
    v280 = qvalue(elt(env, 4)); /* dmode!* */
    v280 = get(v281, v280);
    env = stack[-3];
    goto v176;

v176:
    v280 = (v280 == nil ? lisp_true : nil);
    goto v78;

v116:
    v280 = qvalue(elt(env, 2)); /* nil */
    goto v176;
/* error exit handlers */
v52:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* !*expandlogs */
    popv(4);
    return nil;
v51:
    popv(4);
    return nil;
}



/* Code for drop_rl_with */

static Lisp_Object CC_drop_rl_with(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v123, v146;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for drop_rl_with");
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
    v125 = v1;
    v123 = v0;
/* end of prologue */
    stack[-1] = v125;
    stack[0] = elt(env, 1); /* rl_with */
    v146 = v123;
    v123 = v125;
    v125 = elt(env, 1); /* rl_with */
    v125 = get(v123, v125);
    env = stack[-2];
    v125 = Ldelete(nil, v146, v125);
    nil = C_nil;
    if (exception_pending()) goto v174;
    {
        Lisp_Object v118 = stack[-1];
        Lisp_Object v124 = stack[0];
        popv(3);
        return Lputprop(nil, 3, v118, v124, v125);
    }
/* error exit handlers */
v174:
    popv(3);
    return nil;
}



/* Code for reset_opnums */

static Lisp_Object MS_CDECL CC_reset_opnums(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v159, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "reset_opnums");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reset_opnums");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* end of prologue */
    v158 = qvalue(elt(env, 1)); /* oporder!* */
    stack[-4] = v158;
    v158 = (Lisp_Object)17; /* 1 */
    stack[-3] = v158;
    goto v154;

v154:
    v158 = stack[-4];
    if (v158 == nil) goto v137;
    v158 = stack[-4];
    v158 = qcar(v158);
    v159 = v158;
    v158 = stack[-4];
    v158 = qcdr(v158);
    stack[-4] = v158;
    v158 = v159;
    if (symbolp(v158)) goto v135;
    v158 = v159;
    v158 = qcar(v158);
    stack[-2] = v158;
    v158 = v159;
    v158 = qcdr(v158);
    goto v124;

v124:
    stack[-1] = stack[-2];
    stack[0] = elt(env, 3); /* opnum */
    v159 = v158;
    v158 = stack[-3];
    v90 = cons(v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    v159 = stack[-2];
    v158 = elt(env, 3); /* opnum */
    v158 = get(v159, v158);
    env = stack[-5];
    fn = elt(env, 4); /* !*xadd */
    v158 = (*qfn2(fn))(qenv(fn), v90, v158);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    v158 = Lputprop(nil, 3, stack[-1], stack[0], v158);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    v158 = stack[-3];
    v158 = add1(v158);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-5];
    stack[-3] = v158;
    goto v154;

v135:
    v158 = v159;
    stack[-2] = v158;
    v158 = qvalue(elt(env, 2)); /* nil */
    goto v124;

v137:
    v158 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v158); }
/* error exit handlers */
v269:
    popv(6);
    return nil;
}



/* Code for all_defined */

static Lisp_Object CC_all_defined(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined");
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
    v86 = v0;
/* end of prologue */
    stack[-1] = v86;
    fn = elt(env, 1); /* map__edges */
    v130 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    v86 = stack[0];
    fn = elt(env, 2); /* defined_append */
    v86 = (*qfn2(fn))(qenv(fn), v130, v86);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    {
        Lisp_Object v134 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* all_defined_map_ */
        return (*qfn2(fn))(qenv(fn), v134, v86);
    }
/* error exit handlers */
v135:
    popv(3);
    return nil;
}



/* Code for !*sf2ex */

static Lisp_Object CC_Hsf2ex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v127, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *sf2ex");
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
    goto v129;

v129:
    v72 = stack[-1];
    if (v72 == nil) goto v80;
    v72 = stack[-1];
    if (!consp(v72)) goto v283;
    v72 = stack[-1];
    v72 = qcar(v72);
    v72 = (consp(v72) ? nil : lisp_true);
    goto v179;

v179:
    if (v72 == nil) goto v118;
    v72 = qvalue(elt(env, 1)); /* t */
    goto v81;

v81:
    if (v72 == nil) goto v73;
    stack[0] = stack[-2];
    v72 = qvalue(elt(env, 2)); /* nil */
    v127 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    v72 = stack[-1];
    v72 = cons(v127, v72);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    {
        Lisp_Object v70 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v70, v72);
    }

v73:
    v72 = stack[-1];
    v72 = qcar(v72);
    v72 = qcar(v72);
    v72 = qcar(v72);
    v91 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    v72 = stack[-1];
    v72 = qcar(v72);
    v127 = qcdr(v72);
    v72 = stack[-2];
    v72 = acons(v91, v127, v72);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[-2] = v72;
    v72 = stack[-1];
    v72 = qcdr(v72);
    stack[-1] = v72;
    goto v129;

v118:
    v72 = stack[-1];
    v72 = qcar(v72);
    v72 = qcar(v72);
    v127 = qcar(v72);
    v72 = stack[0];
    v72 = Lmemq(nil, v127, v72);
    v72 = (v72 == nil ? lisp_true : nil);
    goto v81;

v283:
    v72 = qvalue(elt(env, 1)); /* t */
    goto v179;

v80:
    v72 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v72);
    }
/* error exit handlers */
v189:
    popv(4);
    return nil;
}



/* Code for i2fourier */

static Lisp_Object CC_i2fourier(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v86, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2fourier");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v130 = v0;
/* end of prologue */
    v86 = qvalue(elt(env, 1)); /* dmode!* */
    v120 = elt(env, 2); /* !:fs!: */
    if (!(v86 == v120)) return onevalue(v130);
    v120 = v130;
    {
        fn = elt(env, 3); /* !*d2fourier */
        return (*qfn1(fn))(qenv(fn), v120);
    }
}



/* Code for lf!=less */

static Lisp_Object CC_lfMless(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v134, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lf=less");
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
    stack[-1] = v1;
    v134 = v0;
/* end of prologue */
    v82 = elt(env, 1); /* cali */
    v135 = elt(env, 2); /* varlessp */
    stack[-2] = get(v82, v135);
    env = stack[-3];
    v135 = v134;
    fn = elt(env, 3); /* lf!=lvar */
    stack[0] = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    v135 = stack[-1];
    fn = elt(env, 3); /* lf!=lvar */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v123;
    {
        Lisp_Object v146 = stack[-2];
        Lisp_Object v87 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v146, v87, v135);
    }
/* error exit handlers */
v123:
    popv(4);
    return nil;
}



/* Code for fix_or_str */

static Lisp_Object CC_fix_or_str(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v88;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fix_or_str");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v80 = v0;
/* end of prologue */
    v88 = v80;
    v88 = integerp(v88);
    if (!(v88 == nil)) return onevalue(v88);
        return Lstringp(nil, v80);
}



/* Code for dependsp */

static Lisp_Object CC_dependsp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dependsp");
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
    v170 = stack[0];
    if (v170 == nil) goto v117;
    v172 = stack[-1];
    v170 = stack[0];
    fn = elt(env, 5); /* depends */
    v170 = (*qfn2(fn))(qenv(fn), v172, v170);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-3];
    if (!(v170 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v170 = stack[-1];
    if (!consp(v170)) goto v136;
    v170 = stack[-1];
    v172 = qcar(v170);
    v170 = elt(env, 3); /* !*sq */
    if (v172 == v170) goto v140;
    v170 = stack[-1];
    fn = elt(env, 6); /* taylorp */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-3];
    if (v170 == nil) goto v250;
    v172 = stack[0];
    v170 = qvalue(elt(env, 4)); /* taylorvariable */
    if (v172 == v170) goto v115;
    v170 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v170); }

v115:
    v170 = qvalue(elt(env, 4)); /* taylorvariable */
    { popv(4); return onevalue(v170); }

v250:
    v172 = stack[-1];
    v170 = stack[0];
    if (equal(v172, v170)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v170 = stack[-1];
    stack[-2] = v170;
    v170 = stack[-1];
    v170 = qcdr(v170);
    stack[-1] = v170;
    goto v152;

v152:
    v170 = stack[-1];
    if (v170 == nil) goto v187;
    v170 = stack[-1];
    v172 = qcar(v170);
    v170 = stack[0];
    v170 = CC_dependsp(env, v172, v170);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-3];
    if (!(v170 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v170 = stack[-1];
    v170 = qcdr(v170);
    stack[-1] = v170;
    goto v152;

v187:
    v170 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v170); }

v140:
    v170 = stack[-1];
    v170 = qcdr(v170);
    v172 = qcar(v170);
    v170 = stack[0];
    {
        popv(4);
        fn = elt(env, 7); /* involvesq */
        return (*qfn2(fn))(qenv(fn), v172, v170);
    }

v136:
    v172 = stack[-1];
    v170 = stack[0];
    if (v172 == v170) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v170 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v170); }

v117:
    v170 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v170); }
/* error exit handlers */
v181:
    popv(4);
    return nil;
}



/* Code for bdstest */

static Lisp_Object CC_bdstest(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bdstest");
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
    v134 = stack[0];
    v134 = qcar(v134);
    fn = elt(env, 1); /* r2bf */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    fn = elt(env, 2); /* rootrnd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    v134 = stack[0];
    v134 = qcdr(v134);
    fn = elt(env, 1); /* r2bf */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    fn = elt(env, 2); /* rootrnd */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    stack[0] = v134;
    fn = elt(env, 3); /* equal!: */
    v134 = (*qfn2(fn))(qenv(fn), stack[-1], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    if (!(v134 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v134 = nil;
    { popv(3); return onevalue(v134); }
/* error exit handlers */
v136:
    popv(3);
    return nil;
}



/* Code for redmsg */

static Lisp_Object CC_redmsg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v151, v152, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redmsg");
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
    v153 = qvalue(elt(env, 1)); /* !*wsm */
    if (!(v153 == nil)) goto v117;
    v153 = qvalue(elt(env, 2)); /* !*msg */
    if (v153 == nil) goto v147;
    v151 = stack[0];
    v153 = elt(env, 4); /* "operator" */
    v153 = Lneq(nil, v151, v153);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    goto v85;

v85:
    if (!(v153 == nil)) goto v117;
    v153 = qvalue(elt(env, 6)); /* !*int */
    if (v153 == nil) goto v160;
    v153 = qvalue(elt(env, 7)); /* ifl!* */
    if (!(v153 == nil)) goto v160;
    v71 = elt(env, 8); /* "Declare" */
    v152 = stack[-1];
    v151 = stack[0];
    v153 = elt(env, 9); /* "?" */
    v153 = list4(v71, v152, v151, v153);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    fn = elt(env, 12); /* yesp */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v250;
    if (!(v153 == nil)) { popv(4); return onevalue(v153); }
        popv(4);
        return Lerror0(nil, 0);

v160:
    v153 = qvalue(elt(env, 2)); /* !*msg */
    if (v153 == nil) goto v144;
    stack[-2] = elt(env, 10); /* "***" */
    v152 = stack[-1];
    v151 = elt(env, 11); /* "declared" */
    v153 = stack[0];
    v153 = list3(v152, v151, v153);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    {
        Lisp_Object v268 = stack[-2];
        popv(4);
        fn = elt(env, 13); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v268, v153);
    }

v144:
    v153 = qvalue(elt(env, 5)); /* nil */
    { popv(4); return onevalue(v153); }

v117:
    v153 = qvalue(elt(env, 5)); /* nil */
    { popv(4); return onevalue(v153); }

v147:
    v153 = qvalue(elt(env, 3)); /* t */
    goto v85;
/* error exit handlers */
v250:
    popv(4);
    return nil;
}



/* Code for ofsf_smeqtable */

static Lisp_Object CC_ofsf_smeqtable(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v161, v197, v191, v89, v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smeqtable");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v191 = v1;
    v89 = v0;
/* end of prologue */
    v75 = elt(env, 1); /* ((equal (equal . equal) (neq . false) (geq . equal) (leq . equal) (greaterp . false) (lessp . false)) (neq (neq . neq) (geq . greaterp) (leq . lessp) (greaterp . greaterp) (l
essp . lessp)) (geq (geq . geq) (leq . equal) (greaterp . greaterp) (lessp . false)) (leq (leq . leq) (greaterp . false) (lessp . lessp)) (greaterp (greaterp . greaterp) (lessp . false)) (lessp (lessp
 . lessp))) */
    v133 = v75;
    v197 = v191;
    v161 = v89;
    v75 = v133;
    v75 = Latsoc(nil, v161, v75);
    v75 = Latsoc(nil, v197, v75);
    if (!(v75 == nil)) goto v154;
    v75 = v89;
    v161 = v191;
    v197 = v133;
    v161 = Latsoc(nil, v161, v197);
    v75 = Latsoc(nil, v75, v161);
    goto v154;

v154:
    v75 = qcdr(v75);
    return onevalue(v75);
}



/* Code for evalleq */

static Lisp_Object CC_evalleq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalleq");
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
    v147 = v1;
    v137 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evalgreaterp */
    v147 = (*qfn2(fn))(qenv(fn), v137, v147);
    errexit();
    v147 = (v147 == nil ? lisp_true : nil);
    return onevalue(v147);
}



/* Code for dependsl */

static Lisp_Object CC_dependsl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dependsl");
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

v162:
    v175 = stack[0];
    if (v175 == nil) goto v117;
    v174 = stack[-1];
    v175 = stack[0];
    v175 = qcar(v175);
    fn = elt(env, 2); /* depends */
    v175 = (*qfn2(fn))(qenv(fn), v174, v175);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    if (!(v175 == nil)) { popv(3); return onevalue(v175); }
    v174 = stack[-1];
    v175 = stack[0];
    v175 = qcdr(v175);
    stack[-1] = v174;
    stack[0] = v175;
    goto v162;

v117:
    v175 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v175); }
/* error exit handlers */
v195:
    popv(3);
    return nil;
}



/* Code for get!*generators */

static Lisp_Object CC_getHgenerators(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v137;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*generators");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v147 = v0;
/* end of prologue */
    v137 = elt(env, 1); /* generators */
    return get(v147, v137);
}



/* Code for mri_irsplit */

static Lisp_Object CC_mri_irsplit(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v190, v286, v278;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_irsplit");
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
    v278 = v0;
/* end of prologue */
    v286 = v278;
    v190 = elt(env, 1); /* floor */
    if (!consp(v286)) goto v283;
    v286 = qcar(v286);
    if (!(v286 == v190)) goto v283;
    v190 = v278;
    v190 = qcdr(v190);
    v190 = qcar(v190);
    fn = elt(env, 2); /* simp */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-2];
    v190 = qcar(v190);
    fn = elt(env, 3); /* mri_simplfloor */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-2];
    fn = elt(env, 4); /* mri_irsplit1 */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-2];
    v286 = v190;
    v190 = v286;
    stack[-1] = qcar(v190);
    v190 = v286;
    v190 = qcdr(v190);
    if (v190 == nil) goto v139;
    stack[0] = elt(env, 1); /* floor */
    v190 = v286;
    v190 = qcdr(v190);
    fn = elt(env, 5); /* prepf */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-2];
    v190 = list2(stack[0], v190);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-2];
    fn = elt(env, 6); /* !*a2k */
    v278 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-2];
    v286 = (Lisp_Object)17; /* 1 */
    v190 = (Lisp_Object)17; /* 1 */
    v190 = acons(v278, v286, v190);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-2];
    v190 = ncons(v190);
    nil = C_nil;
    if (exception_pending()) goto v285;
    goto v75;

v75:
    {
        Lisp_Object v284 = stack[-1];
        popv(3);
        return cons(v284, v190);
    }

v139:
    v190 = nil;
    goto v75;

v283:
    v286 = (Lisp_Object)17; /* 1 */
    v190 = (Lisp_Object)17; /* 1 */
    v190 = acons(v278, v286, v190);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[-2];
    v190 = ncons(v190);
    nil = C_nil;
    if (exception_pending()) goto v285;
    popv(3);
    return ncons(v190);
/* error exit handlers */
v285:
    popv(3);
    return nil;
}



/* Code for qqe_length!-graph!-bterm */

static Lisp_Object CC_qqe_lengthKgraphKbterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_length-graph-bterm");
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
    v159 = stack[-1];
    if (v159 == nil) goto v85;
    v159 = stack[-1];
    v159 = (consp(v159) ? nil : lisp_true);
    goto v88;

v88:
    if (!(v159 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v159 = stack[-1];
    fn = elt(env, 4); /* qqe_op */
    v90 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-2];
    v159 = elt(env, 2); /* (lhead rhead) */
    v159 = Lmemq(nil, v90, v159);
    if (v159 == nil) goto v75;
    v90 = stack[-1];
    v159 = stack[0];
    fn = elt(env, 5); /* qqe_length!-graph!-bterm!-update!-headmin */
    v159 = (*qfn2(fn))(qenv(fn), v90, v159);
    nil = C_nil;
    if (exception_pending()) goto v190;
    stack[0] = v159;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v75:
    v159 = stack[-1];
    v159 = qcdr(v159);
    stack[-1] = v159;
    goto v133;

v133:
    v159 = stack[-1];
    if (v159 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v159 = stack[-1];
    v159 = qcar(v159);
    v90 = v159;
    v159 = stack[0];
    v159 = CC_qqe_lengthKgraphKbterm(env, v90, v159);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-2];
    stack[0] = v159;
    v159 = stack[-1];
    v159 = qcdr(v159);
    stack[-1] = v159;
    goto v133;

v85:
    v159 = qvalue(elt(env, 1)); /* t */
    goto v88;
/* error exit handlers */
v190:
    popv(3);
    return nil;
}



/* Code for unary */

static Lisp_Object CC_unary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unary");
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
    v118 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 6); /* printout */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v118 = elt(env, 2); /* "<" */
    v118 = Lprinc(nil, v118);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v118 = stack[0];
    v118 = Lprinc(nil, v118);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v118 = elt(env, 3); /* "/>" */
    v118 = Lprinc(nil, v118);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v124 = qvalue(elt(env, 4)); /* indent */
    v118 = (Lisp_Object)49; /* 3 */
    v118 = plus2(v124, v118);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    qvalue(elt(env, 4)) = v118; /* indent */
    v118 = stack[-1];
    v118 = qcar(v118);
    fn = elt(env, 7); /* expression */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v124 = qvalue(elt(env, 4)); /* indent */
    v118 = (Lisp_Object)49; /* 3 */
    v118 = difference2(v124, v118);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    qvalue(elt(env, 4)) = v118; /* indent */
    v118 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v131;
    v118 = nil;
    { popv(3); return onevalue(v118); }
/* error exit handlers */
v131:
    popv(3);
    return nil;
}



/* Code for tidysqrt */

static Lisp_Object CC_tidysqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tidysqrt");
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
    v118 = stack[0];
    v118 = qcar(v118);
    fn = elt(env, 2); /* tidysqrtf */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    stack[-1] = v118;
    v118 = stack[-1];
    if (v118 == nil) goto v145;
    v118 = stack[0];
    v118 = qcdr(v118);
    fn = elt(env, 2); /* tidysqrtf */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    stack[0] = stack[-1];
    fn = elt(env, 3); /* invsq */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    {
        Lisp_Object v12 = stack[0];
        popv(3);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v12, v118);
    }

v145:
    v124 = qvalue(elt(env, 1)); /* nil */
    v118 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v124, v118);
/* error exit handlers */
v131:
    popv(3);
    return nil;
}



/* Code for ps!:minus!-erule */

static Lisp_Object CC_psTminusKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:minus-erule");
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
    v82 = v1;
    v196 = v0;
/* end of prologue */
    v196 = qcdr(v196);
    v196 = qcar(v196);
    fn = elt(env, 1); /* ps!:evaluate */
    v82 = (*qfn2(fn))(qenv(fn), v196, v82);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    stack[0] = v82;
    v82 = stack[0];
    v82 = qcar(v82);
    fn = elt(env, 2); /* negf */
    v196 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v125;
    v82 = stack[0];
    v82 = qcdr(v82);
    popv(2);
    return cons(v196, v82);
/* error exit handlers */
v125:
    popv(2);
    return nil;
}



/* Code for dip!-nc!-ev!-prod */

static Lisp_Object MS_CDECL CC_dipKncKevKprod(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v118, v124, v195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "dip-nc-ev-prod");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip-nc-ev-prod");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v174 = v3;
    v118 = v2;
    v124 = v1;
    v195 = v0;
/* end of prologue */
    stack[-2] = v124;
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = v174;
    v174 = v195;
    fn = elt(env, 2); /* bcprod */
    v118 = (*qfn2(fn))(qenv(fn), v174, v118);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v174 = qvalue(elt(env, 1)); /* nil */
    v174 = list2star(stack[0], v118, v174);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    {
        Lisp_Object v75 = stack[-2];
        Lisp_Object v161 = stack[-1];
        popv(4);
        fn = elt(env, 3); /* dip!-nc!-ev!-prod1 */
        return (*qfnn(fn))(qenv(fn), 3, v75, v161, v174);
    }
/* error exit handlers */
v37:
    popv(4);
    return nil;
}



/* Code for mod!-dump */

static Lisp_Object CC_modKdump(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v75, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod-dump");
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
    v37 = stack[-1];
    v37 = qcar(v37);
    fn = elt(env, 1); /* freeind */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    if (v37 == nil) goto v85;
    v37 = stack[-1];
    v161 = qcar(v37);
    v37 = stack[-1];
    v37 = qcdr(v37);
    v75 = qcar(v37);
    v37 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* mod!-dump1 */
        return (*qfnn(fn))(qenv(fn), 3, v161, v75, v37);
    }

v85:
    v37 = stack[-1];
    v37 = qcdr(v37);
    v161 = qcar(v37);
    v37 = stack[-1];
    v75 = qcar(v37);
    v37 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* mod!-dump1 */
        return (*qfnn(fn))(qenv(fn), 3, v161, v75, v37);
    }
/* error exit handlers */
v89:
    popv(3);
    return nil;
}



/* Code for boolean!-eval1 */

static Lisp_Object CC_booleanKeval1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v271, v76, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boolean-eval1");
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
    v77 = nil;
    v76 = stack[0];
    v271 = elt(env, 1); /* sq!* */
    if (!consp(v76)) goto v161;
    v76 = qcar(v76);
    if (!(v76 == v271)) goto v161;
    v271 = stack[0];
    v271 = qcdr(v271);
    v271 = qcdr(v271);
    if (v271 == nil) goto v135;
    v271 = stack[0];
    v271 = qcdr(v271);
    v271 = qcar(v271);
    fn = elt(env, 4); /* prespsq */
    v76 = (*qfn1(fn))(qenv(fn), v271);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    v77 = v76;
    v271 = elt(env, 3); /* boolean */
    v271 = Leqcar(nil, v76, v271);
    env = stack[-1];
    goto v88;

v88:
    if (v271 == nil) goto v140;
    v271 = v77;
    v271 = qcdr(v271);
    v271 = qcar(v271);
    {
        popv(2);
        fn = elt(env, 5); /* boolean!-eval2 */
        return (*qfn1(fn))(qenv(fn), v271);
    }

v140:
    v271 = stack[0];
    v271 = ncons(v271);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    fn = elt(env, 6); /* simp!-prop */
    v271 = (*qfn1(fn))(qenv(fn), v271);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    v271 = qcar(v271);
    fn = elt(env, 7); /* prepf */
    v271 = (*qfn1(fn))(qenv(fn), v271);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 5); /* boolean!-eval2 */
        return (*qfn1(fn))(qenv(fn), v271);
    }

v135:
    v271 = qvalue(elt(env, 2)); /* nil */
    goto v88;

v161:
    v271 = qvalue(elt(env, 2)); /* nil */
    goto v88;
/* error exit handlers */
v148:
    popv(2);
    return nil;
}



/* Code for monic */

static Lisp_Object CC_monic(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v288, v289;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monic");
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
    stack[-4] = nil;
    v288 = stack[-3];
    v288 = Lreverse(nil, v288);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-5];
    stack[-3] = v288;
    v288 = qvalue(elt(env, 1)); /* varlist */
    v288 = Llength(nil, v288);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-5];
    stack[-1] = v288;
    v288 = (Lisp_Object)17; /* 1 */
    stack[0] = v288;
    goto v283;

v283:
    v289 = stack[-1];
    v288 = stack[0];
    v288 = difference2(v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-5];
    v288 = Lminusp(nil, v288);
    env = stack[-5];
    if (v288 == nil) goto v118;
    v288 = qvalue(elt(env, 1)); /* varlist */
    v288 = qcdr(v288);
    stack[-3] = v288;
    v288 = stack[-3];
    if (v288 == nil) goto v278;
    v288 = (Lisp_Object)1; /* 0 */
    v288 = ncons(v288);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-5];
    stack[-1] = v288;
    stack[-2] = v288;
    goto v90;

v90:
    v288 = stack[-3];
    v288 = qcdr(v288);
    stack[-3] = v288;
    v288 = stack[-3];
    if (v288 == nil) goto v268;
    stack[0] = stack[-1];
    v288 = (Lisp_Object)1; /* 0 */
    v288 = ncons(v288);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-5];
    v288 = Lrplacd(nil, stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-5];
    v288 = stack[-1];
    v288 = qcdr(v288);
    stack[-1] = v288;
    goto v90;

v268:
    v288 = stack[-2];
    goto v176;

v176:
    v288 = (equal(stack[-4], v288) ? lisp_true : nil);
    { popv(6); return onevalue(v288); }

v278:
    v288 = qvalue(elt(env, 2)); /* nil */
    goto v176;

v118:
    v289 = stack[0];
    v288 = stack[-2];
    if (equal(v289, v288)) goto v87;
    v289 = stack[-3];
    v288 = stack[0];
    fn = elt(env, 3); /* pnth */
    v288 = (*qfn2(fn))(qenv(fn), v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-5];
    v289 = qcar(v288);
    v288 = stack[-4];
    v288 = cons(v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-5];
    stack[-4] = v288;
    goto v87;

v87:
    v288 = stack[0];
    v288 = add1(v288);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-5];
    stack[0] = v288;
    goto v283;
/* error exit handlers */
v164:
    popv(6);
    return nil;
}



/* Code for setmod */

static Lisp_Object CC_setmod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmod");
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
    stack[-1] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    v127 = stack[0];
    if (!consp(v127)) goto v129;
    v127 = stack[0];
    v127 = qcar(v127);
    stack[0] = v127;
    goto v129;

v129:
    v127 = stack[0];
    fn = elt(env, 7); /* reval */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-2];
    stack[0] = v127;
    v127 = stack[0];
    v127 = integerp(v127);
    if (v127 == nil) goto v176;
    v91 = stack[0];
    v127 = (Lisp_Object)1; /* 0 */
    v127 = (Lisp_Object)greaterp2(v91, v127);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v127 = v127 ? lisp_true : nil;
    env = stack[-2];
    if (v127 == nil) goto v176;
    v127 = stack[0];
    fn = elt(env, 8); /* primep */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-2];
    if (v127 == nil) goto v119;
    v91 = elt(env, 2); /* (!:mod!:) */
    v127 = elt(env, 3); /* field */
    v127 = Lflag(nil, v91, v127);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-2];
    goto v87;

v87:
    v127 = stack[0];
    fn = elt(env, 9); /* set!-general!-modulus */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-2];
    goto v114;

v114:
    qvalue(elt(env, 1)) = stack[-1]; /* dmode!* */
    { popv(3); return onevalue(v127); }

v119:
    v91 = elt(env, 2); /* (!:mod!:) */
    v127 = elt(env, 3); /* field */
    v127 = Lremflag(nil, v91, v127);
    env = stack[-2];
    goto v87;

v176:
    v91 = stack[0];
    v127 = (Lisp_Object)1; /* 0 */
    if (v91 == v127) goto v279;
    v127 = stack[0];
    v127 = (v127 == nil ? lisp_true : nil);
    goto v77;

v77:
    if (v127 == nil) goto v285;
    v127 = qvalue(elt(env, 5)); /* current!-modulus */
    goto v114;

v285:
    v91 = stack[0];
    v127 = elt(env, 6); /* "modulus" */
    fn = elt(env, 10); /* typerr */
    v127 = (*qfn2(fn))(qenv(fn), v91, v127);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-2];
    v127 = nil;
    goto v114;

v279:
    v127 = qvalue(elt(env, 4)); /* t */
    goto v77;
/* error exit handlers */
v251:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* dmode!* */
    popv(3);
    return nil;
}



/* Code for spreadvar */

static Lisp_Object MS_CDECL CC_spreadvar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v250, v268;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "spreadvar");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spreadvar");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v250 = v2;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v155:
    v91 = stack[-1];
    if (!consp(v91)) goto v138;
    v91 = stack[-1];
    v91 = qcar(v91);
    v91 = (consp(v91) ? nil : lisp_true);
    goto v137;

v137:
    if (!(v91 == nil)) { popv(4); return onevalue(v250); }
    v91 = stack[-1];
    v91 = qcar(v91);
    v91 = qcar(v91);
    v268 = qcar(v91);
    v91 = stack[0];
    if (equal(v268, v91)) goto v191;
    v91 = qvalue(elt(env, 2)); /* nil */
    goto v87;

v87:
    if (v91 == nil) goto v136;
    v91 = stack[-1];
    v91 = qcar(v91);
    v91 = qcar(v91);
    v91 = qcdr(v91);
    v91 = cons(v91, v250);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v250 = v91;
    goto v136;

v136:
    v91 = stack[-1];
    v91 = qcdr(v91);
    stack[-2] = v91;
    v91 = stack[-1];
    v91 = qcar(v91);
    v268 = qcdr(v91);
    v91 = stack[0];
    v91 = CC_spreadvar(env, 3, v268, v91, v250);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v250 = v91;
    v91 = stack[-2];
    stack[-1] = v91;
    goto v155;

v191:
    v91 = stack[-1];
    v91 = qcar(v91);
    v91 = qcar(v91);
    v268 = qcdr(v91);
    v91 = v250;
    v91 = Lmember(nil, v268, v91);
    v91 = (v91 == nil ? lisp_true : nil);
    goto v87;

v138:
    v91 = qvalue(elt(env, 1)); /* t */
    goto v137;
/* error exit handlers */
v69:
    popv(4);
    return nil;
}



/* Code for preptaylor!*2 */

static Lisp_Object CC_preptaylorH2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v157, v290;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaylor*2");
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
    v156 = stack[-1];
    v156 = qcdr(v156);
    fn = elt(env, 4); /* prepsq!* */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v290 = v156;
    v157 = (Lisp_Object)1; /* 0 */
    if (v290 == v157) goto v80;
    v290 = v156;
    v157 = elt(env, 2); /* quotient */
    if (!consp(v290)) goto v143;
    v290 = qcar(v290);
    if (!(v290 == v157)) goto v143;
    v157 = v156;
    v157 = qcdr(v157);
    v290 = qcar(v157);
    v157 = elt(env, 3); /* minus */
    v157 = Leqcar(nil, v290, v157);
    env = stack[-3];
    goto v118;

v118:
    if (v157 == nil) goto v71;
    stack[-2] = elt(env, 3); /* minus */
    v290 = elt(env, 2); /* quotient */
    v157 = v156;
    v157 = qcdr(v157);
    v157 = qcar(v157);
    v157 = qcdr(v157);
    v157 = qcar(v157);
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v156 = qcar(v156);
    v156 = list3(v290, v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v156 = list2(stack[-2], v156);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    stack[-2] = v156;
    goto v250;

v250:
    v156 = stack[-1];
    v157 = qcar(v156);
    v156 = stack[0];
    fn = elt(env, 5); /* preptaycoeff */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v156 = cons(stack[-2], v156);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    fn = elt(env, 6); /* retimes */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v188;
    popv(4);
    return ncons(v156);

v71:
    stack[-2] = v156;
    goto v250;

v143:
    v157 = qvalue(elt(env, 1)); /* nil */
    goto v118;

v80:
    v156 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v156); }
/* error exit handlers */
v188:
    popv(4);
    return nil;
}



/* Code for collectpolyvarsaux */

static Lisp_Object CC_collectpolyvarsaux(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v252;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectpolyvarsaux");
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
    v252 = v1;
    stack[-1] = v0;
/* end of prologue */
    v115 = stack[-1];
    if (!consp(v115)) goto v80;
    v115 = stack[-1];
    v115 = qcar(v115);
    v115 = (consp(v115) ? nil : lisp_true);
    goto v154;

v154:
    if (!(v115 == nil)) { popv(4); return onevalue(v252); }
    stack[0] = v252;
    v115 = stack[-1];
    v115 = qcar(v115);
    v115 = qcar(v115);
    v115 = qcar(v115);
    v115 = ncons(v115);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    fn = elt(env, 3); /* union */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[0], v115);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    v115 = stack[-1];
    v115 = qcar(v115);
    v252 = qcdr(v115);
    v115 = qvalue(elt(env, 2)); /* nil */
    stack[0] = CC_collectpolyvarsaux(env, v252, v115);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    v115 = stack[-1];
    v252 = qcdr(v115);
    v115 = qvalue(elt(env, 2)); /* nil */
    v115 = CC_collectpolyvarsaux(env, v252, v115);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    fn = elt(env, 3); /* union */
    v115 = (*qfn2(fn))(qenv(fn), stack[0], v115);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    {
        Lisp_Object v90 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* union */
        return (*qfn2(fn))(qenv(fn), v90, v115);
    }

v80:
    v115 = qvalue(elt(env, 1)); /* t */
    goto v154;
/* error exit handlers */
v159:
    popv(4);
    return nil;
}



/* Code for !*addsq */

static Lisp_Object CC_Haddsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *addsq");
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
    v49 = stack[-3];
    v49 = qcar(v49);
    if (v49 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v49 = stack[-2];
    v49 = qcar(v49);
    if (v49 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v49 = stack[-3];
    v48 = qcdr(v49);
    v49 = (Lisp_Object)17; /* 1 */
    if (v48 == v49) goto v123;
    v49 = qvalue(elt(env, 1)); /* nil */
    goto v120;

v120:
    if (v49 == nil) goto v158;
    v49 = stack[-3];
    v48 = qcar(v49);
    v49 = stack[-2];
    v49 = qcar(v49);
    fn = elt(env, 2); /* addf */
    v48 = (*qfn2(fn))(qenv(fn), v48, v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    v49 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v48, v49);

v158:
    v49 = stack[-3];
    v48 = qcdr(v49);
    stack[-4] = v48;
    v49 = stack[-2];
    v49 = qcdr(v49);
    stack[-1] = v49;
    fn = elt(env, 3); /* gcdf */
    v49 = (*qfn2(fn))(qenv(fn), v48, v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    stack[0] = v49;
    v48 = stack[-4];
    v49 = stack[0];
    fn = elt(env, 4); /* quotf */
    v49 = (*qfn2(fn))(qenv(fn), v48, v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    stack[-4] = v49;
    v48 = stack[-1];
    v49 = stack[0];
    fn = elt(env, 4); /* quotf */
    v49 = (*qfn2(fn))(qenv(fn), v48, v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    stack[-1] = v49;
    v48 = stack[-1];
    v49 = stack[-3];
    v49 = qcar(v49);
    fn = elt(env, 5); /* !*multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v48, v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    v48 = stack[-4];
    v49 = stack[-2];
    v49 = qcar(v49);
    fn = elt(env, 5); /* !*multf */
    v49 = (*qfn2(fn))(qenv(fn), v48, v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    fn = elt(env, 2); /* addf */
    v49 = (*qfn2(fn))(qenv(fn), stack[0], v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    stack[-2] = v49;
    v49 = stack[-2];
    if (v49 == nil) goto v165;
    v49 = stack[-3];
    v48 = qcdr(v49);
    v49 = stack[-1];
    fn = elt(env, 5); /* !*multf */
    v49 = (*qfn2(fn))(qenv(fn), v48, v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    stack[-1] = v49;
    v49 = stack[-1];
    fn = elt(env, 6); /* minusf */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    if (v49 == nil) goto v282;
    v49 = stack[-2];
    fn = elt(env, 7); /* negf */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    stack[-2] = v49;
    v49 = stack[-1];
    fn = elt(env, 7); /* negf */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    stack[-1] = v49;
    goto v282;

v282:
    v48 = stack[-2];
    v49 = stack[-1];
    fn = elt(env, 3); /* gcdf */
    v49 = (*qfn2(fn))(qenv(fn), v48, v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    stack[0] = v49;
    v48 = stack[0];
    v49 = (Lisp_Object)17; /* 1 */
    if (v48 == v49) goto v100;
    v48 = stack[-2];
    v49 = stack[0];
    fn = elt(env, 4); /* quotf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v48, v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-5];
    v48 = stack[-1];
    v49 = stack[0];
    fn = elt(env, 4); /* quotf */
    v49 = (*qfn2(fn))(qenv(fn), v48, v49);
    nil = C_nil;
    if (exception_pending()) goto v301;
    {
        Lisp_Object v43 = stack[-2];
        popv(6);
        return cons(v43, v49);
    }

v100:
    v48 = stack[-2];
    v49 = stack[-1];
    popv(6);
    return cons(v48, v49);

v165:
    v48 = qvalue(elt(env, 1)); /* nil */
    v49 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v48, v49);

v123:
    v49 = stack[-2];
    v48 = qcdr(v49);
    v49 = (Lisp_Object)17; /* 1 */
    v49 = (v48 == v49 ? lisp_true : nil);
    goto v120;
/* error exit handlers */
v301:
    popv(6);
    return nil;
}



/* Code for cl_susimkatl */

static Lisp_Object MS_CDECL CC_cl_susimkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v312, v313, v314;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susimkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susimkatl");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v3;
    v312 = v2;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = v312;
    goto v137;

v137:
    v312 = stack[-6];
    if (v312 == nil) goto v120;
    v312 = stack[-6];
    v312 = qcar(v312);
    v314 = v312;
    v312 = v314;
    v313 = qcdr(v312);
    v312 = stack[-3];
    if (equal(v313, v312)) goto v136;
    v312 = nil;
    goto v196;

v196:
    stack[-2] = v312;
    v312 = stack[-2];
    fn = elt(env, 8); /* lastpair */
    v312 = (*qfn1(fn))(qenv(fn), v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    stack[-1] = v312;
    v312 = stack[-6];
    v312 = qcdr(v312);
    stack[-6] = v312;
    v312 = stack[-1];
    if (!consp(v312)) goto v137;
    else goto v138;

v138:
    v312 = stack[-6];
    if (v312 == nil) goto v79;
    stack[0] = stack[-1];
    v312 = stack[-6];
    v312 = qcar(v312);
    v314 = v312;
    v312 = v314;
    v313 = qcdr(v312);
    v312 = stack[-3];
    if (equal(v313, v312)) goto v74;
    v312 = nil;
    goto v77;

v77:
    v312 = Lrplacd(nil, stack[0], v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    v312 = stack[-1];
    fn = elt(env, 8); /* lastpair */
    v312 = (*qfn1(fn))(qenv(fn), v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    stack[-1] = v312;
    v312 = stack[-6];
    v312 = qcdr(v312);
    stack[-6] = v312;
    goto v138;

v74:
    v312 = v314;
    v312 = qcar(v312);
    v312 = ncons(v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    goto v77;

v79:
    v312 = stack[-2];
    goto v147;

v147:
    v314 = v312;
    v312 = v314;
    if (v312 == nil) goto v91;
    v313 = v314;
    v312 = stack[-4];
    fn = elt(env, 9); /* rl_susipost */
    v312 = (*qfn2(fn))(qenv(fn), v313, v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    v314 = v312;
    v313 = v314;
    v312 = elt(env, 2); /* true */
    if (v313 == v312) goto v68;
    v313 = v314;
    v312 = elt(env, 4); /* false */
    v312 = (v313 == v312 ? lisp_true : nil);
    goto v67;

v67:
    if (v312 == nil) goto v173;
    v313 = stack[-5];
    v312 = elt(env, 5); /* and */
    v312 = (v313 == v312 ? lisp_true : nil);
    fn = elt(env, 10); /* cl_cflip */
    v312 = (*qfn2(fn))(qenv(fn), v314, v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    popv(8);
    return ncons(v312);

v173:
    v313 = v314;
    v312 = elt(env, 6); /* inctheo */
    if (v313 == v312) goto v61;
    v313 = stack[-5];
    v312 = elt(env, 7); /* or */
    if (!(v313 == v312)) goto v298;
    v312 = v314;
    stack[-3] = v312;
    v312 = stack[-3];
    if (v312 == nil) goto v241;
    v312 = stack[-3];
    v312 = qcar(v312);
    fn = elt(env, 11); /* rl_negateat */
    v312 = (*qfn1(fn))(qenv(fn), v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    v312 = ncons(v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    stack[-1] = v312;
    stack[-2] = v312;
    goto v281;

v281:
    v312 = stack[-3];
    v312 = qcdr(v312);
    stack[-3] = v312;
    v312 = stack[-3];
    if (v312 == nil) goto v49;
    stack[0] = stack[-1];
    v312 = stack[-3];
    v312 = qcar(v312);
    fn = elt(env, 11); /* rl_negateat */
    v312 = (*qfn1(fn))(qenv(fn), v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    v312 = ncons(v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    v312 = Lrplacd(nil, stack[0], v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    v312 = stack[-1];
    v312 = qcdr(v312);
    stack[-1] = v312;
    goto v281;

v49:
    v312 = stack[-2];
    goto v280;

v280:
    v314 = v312;
    goto v298;

v298:
    v312 = v314;
    stack[-3] = v312;
    v312 = stack[-3];
    if (v312 == nil) goto v33;
    v312 = stack[-3];
    v312 = qcar(v312);
    v313 = v312;
    v312 = stack[-4];
    fn = elt(env, 12); /* rl_susitf */
    v312 = (*qfn2(fn))(qenv(fn), v313, v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    v312 = ncons(v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    stack[-1] = v312;
    stack[-2] = v312;
    goto v315;

v315:
    v312 = stack[-3];
    v312 = qcdr(v312);
    stack[-3] = v312;
    v312 = stack[-3];
    if (v312 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    stack[0] = stack[-1];
    v312 = stack[-3];
    v312 = qcar(v312);
    v313 = v312;
    v312 = stack[-4];
    fn = elt(env, 12); /* rl_susitf */
    v312 = (*qfn2(fn))(qenv(fn), v313, v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    v312 = ncons(v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    v312 = Lrplacd(nil, stack[0], v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    v312 = stack[-1];
    v312 = qcdr(v312);
    stack[-1] = v312;
    goto v315;

v33:
    v312 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v312); }

v241:
    v312 = qvalue(elt(env, 1)); /* nil */
    goto v280;

v61:
    v314 = elt(env, 4); /* false */
    v313 = stack[-5];
    v312 = elt(env, 5); /* and */
    v312 = (v313 == v312 ? lisp_true : nil);
    {
        popv(8);
        fn = elt(env, 10); /* cl_cflip */
        return (*qfn2(fn))(qenv(fn), v314, v312);
    }

v68:
    v312 = qvalue(elt(env, 3)); /* t */
    goto v67;

v91:
    v312 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v312); }

v136:
    v312 = v314;
    v312 = qcar(v312);
    v312 = ncons(v312);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-7];
    goto v196;

v120:
    v312 = qvalue(elt(env, 1)); /* nil */
    goto v147;
/* error exit handlers */
v32:
    popv(8);
    return nil;
}



/* Code for ldf!-pow!-var */

static Lisp_Object CC_ldfKpowKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-pow-var");
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
    v121 = v0;
/* end of prologue */
    v122 = nil;
    stack[-2] = nil;
    stack[-1] = v121;
    goto v80;

v80:
    v121 = stack[-1];
    if (v121 == nil) goto v154;
    v121 = stack[-1];
    v121 = qcar(v121);
    stack[0] = v122;
    v122 = qcdr(v121);
    v121 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 5); /* kernels1 */
    v121 = (*qfn2(fn))(qenv(fn), v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    v121 = Lappend(nil, stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    v122 = v121;
    v121 = stack[-1];
    v121 = qcdr(v121);
    stack[-1] = v121;
    goto v80;

v154:
    v121 = v122;
    fn = elt(env, 6); /* makeset */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    fn = elt(env, 7); /* prlist */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    stack[0] = v121;
    goto v75;

v75:
    v121 = stack[0];
    if (v121 == nil) goto v37;
    v121 = stack[0];
    v121 = qcar(v121);
    v156 = v121;
    v122 = v156;
    v121 = elt(env, 2); /* x */
    if (!consp(v122)) goto v286;
    v122 = qcar(v122);
    if (!(v122 == v121)) goto v286;
    v121 = qvalue(elt(env, 3)); /* t */
    goto v77;

v77:
    if (v121 == nil) goto v143;
    v122 = v156;
    v121 = stack[-2];
    v121 = cons(v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    stack[-2] = v121;
    goto v143;

v143:
    v121 = stack[0];
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v75;

v286:
    v122 = v156;
    v121 = elt(env, 4); /* u */
    v121 = Leqcar(nil, v122, v121);
    env = stack[-3];
    goto v77;

v37:
    v121 = stack[-2];
    {
        popv(4);
        fn = elt(env, 6); /* makeset */
        return (*qfn1(fn))(qenv(fn), v121);
    }
/* error exit handlers */
v128:
    popv(4);
    return nil;
}



/* Code for impartsq */

static Lisp_Object CC_impartsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v91, v250, v268;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for impartsq");
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
    v127 = stack[0];
    v127 = qcar(v127);
    fn = elt(env, 1); /* splitcomplex */
    stack[-1] = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    v127 = stack[0];
    v127 = qcdr(v127);
    fn = elt(env, 1); /* splitcomplex */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    v91 = stack[-1];
    v250 = v91;
    v268 = qcar(v250);
    v250 = qcdr(v91);
    v91 = v127;
    v91 = qcar(v91);
    v127 = qcdr(v127);
    stack[0] = v268;
    stack[-3] = v91;
    stack[-2] = v127;
    v91 = v250;
    v127 = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v91, v127);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    v91 = stack[0];
    v127 = stack[-2];
    fn = elt(env, 2); /* multsq */
    v127 = (*qfn2(fn))(qenv(fn), v91, v127);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    stack[0] = v127;
    v127 = stack[0];
    v127 = qcar(v127);
    fn = elt(env, 3); /* negf */
    v91 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    v127 = stack[0];
    v127 = qcdr(v127);
    v127 = cons(v91, v127);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-1], v127);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    v91 = stack[-3];
    v127 = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v91, v127);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    v91 = stack[-2];
    v127 = stack[-2];
    fn = elt(env, 2); /* multsq */
    v127 = (*qfn2(fn))(qenv(fn), v91, v127);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    v127 = (*qfn2(fn))(qenv(fn), stack[-1], v127);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    fn = elt(env, 5); /* invsq */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    {
        Lisp_Object v122 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v122, v127);
    }
/* error exit handlers */
v121:
    popv(5);
    return nil;
}



/* Code for groebcplistsort */

static Lisp_Object CC_groebcplistsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistsort");
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
    v123 = v0;
/* end of prologue */
    v146 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v123;
    goto v155;

v155:
    v123 = stack[0];
    if (v123 == nil) { popv(2); return onevalue(v146); }
    v123 = stack[0];
    v123 = qcar(v123);
    fn = elt(env, 2); /* groebcplistsortin */
    v123 = (*qfn2(fn))(qenv(fn), v123, v146);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-1];
    v146 = v123;
    v123 = stack[0];
    v123 = qcdr(v123);
    stack[0] = v123;
    goto v155;
/* error exit handlers */
v175:
    popv(2);
    return nil;
}



/* Code for declared!-as!-float */

static Lisp_Object CC_declaredKasKfloat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for declared-as-float");
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
    v146 = v0;
/* end of prologue */
    v87 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* symtabget */
    v146 = (*qfn2(fn))(qenv(fn), v87, v146);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[0];
    v87 = v146;
    if (v146 == nil) goto v155;
    v146 = v87;
    v146 = qcdr(v146);
    v146 = qcar(v146);
    v87 = elt(env, 2); /* (real real!*8 real!*16 double! precision double float) 
*/
    v146 = Lmemq(nil, v146, v87);
    { popv(1); return onevalue(v146); }

v155:
    v146 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v146); }
/* error exit handlers */
v175:
    popv(1);
    return nil;
}



setup_type const u45_setup[] =
{
    {"interglue",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_interglue},
    {"get_rep_of_generator",    too_few_2,      CC_get_rep_of_generator,wrong_no_2},
    {"qqe_length-graph-neighbor-edge",CC_qqe_lengthKgraphKneighborKedge,too_many_1,wrong_no_1},
    {"ratpoly_toaf",            CC_ratpoly_toaf,too_many_1,    wrong_no_1},
    {"formopr",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_formopr},
    {"crn:onep",                CC_crnTonep,    too_many_1,    wrong_no_1},
    {"poly-remainder",          CC_polyKremainder,too_many_1,  wrong_no_1},
    {"vdpappendmon",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpappendmon},
    {"mkset",                   CC_mkset,       too_many_1,    wrong_no_1},
    {"find_bubles1_coeff",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_bubles1_coeff},
    {"pst_d1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_pst_d1},
    {"modroots2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_modroots2},
    {"solvevars",               CC_solvevars,   too_many_1,    wrong_no_1},
    {"rl_trygauss",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_trygauss},
    {"initmonomials",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_initmonomials},
    {"letscalar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_letscalar},
    {"delqip",                  too_few_2,      CC_delqip,     wrong_no_2},
    {"pm:gensym",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pmTgensym},
    {"texaeval",                CC_texaeval,    too_many_1,    wrong_no_1},
    {"deflate1",                too_few_2,      CC_deflate1,   wrong_no_2},
    {"simplog",                 CC_simplog,     too_many_1,    wrong_no_1},
    {"drop_rl_with",            too_few_2,      CC_drop_rl_with,wrong_no_2},
    {"reset_opnums",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_reset_opnums},
    {"all_defined",             too_few_2,      CC_all_defined,wrong_no_2},
    {"*sf2ex",                  too_few_2,      CC_Hsf2ex,     wrong_no_2},
    {"i2fourier",               CC_i2fourier,   too_many_1,    wrong_no_1},
    {"lf=less",                 too_few_2,      CC_lfMless,    wrong_no_2},
    {"fix_or_str",              CC_fix_or_str,  too_many_1,    wrong_no_1},
    {"dependsp",                too_few_2,      CC_dependsp,   wrong_no_2},
    {"bdstest",                 CC_bdstest,     too_many_1,    wrong_no_1},
    {"redmsg",                  too_few_2,      CC_redmsg,     wrong_no_2},
    {"ofsf_smeqtable",          too_few_2,      CC_ofsf_smeqtable,wrong_no_2},
    {"evalleq",                 too_few_2,      CC_evalleq,    wrong_no_2},
    {"dependsl",                too_few_2,      CC_dependsl,   wrong_no_2},
    {"get*generators",          CC_getHgenerators,too_many_1,  wrong_no_1},
    {"mri_irsplit",             CC_mri_irsplit, too_many_1,    wrong_no_1},
    {"qqe_length-graph-bterm",  too_few_2,      CC_qqe_lengthKgraphKbterm,wrong_no_2},
    {"unary",                   too_few_2,      CC_unary,      wrong_no_2},
    {"tidysqrt",                CC_tidysqrt,    too_many_1,    wrong_no_1},
    {"ps:minus-erule",          too_few_2,      CC_psTminusKerule,wrong_no_2},
    {"dip-nc-ev-prod",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipKncKevKprod},
    {"mod-dump",                too_few_2,      CC_modKdump,   wrong_no_2},
    {"boolean-eval1",           CC_booleanKeval1,too_many_1,   wrong_no_1},
    {"monic",                   too_few_2,      CC_monic,      wrong_no_2},
    {"setmod",                  CC_setmod,      too_many_1,    wrong_no_1},
    {"spreadvar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_spreadvar},
    {"preptaylor*2",            too_few_2,      CC_preptaylorH2,wrong_no_2},
    {"collectpolyvarsaux",      too_few_2,      CC_collectpolyvarsaux,wrong_no_2},
    {"*addsq",                  too_few_2,      CC_Haddsq,     wrong_no_2},
    {"cl_susimkatl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susimkatl},
    {"ldf-pow-var",             CC_ldfKpowKvar, too_many_1,    wrong_no_1},
    {"impartsq",                CC_impartsq,    too_many_1,    wrong_no_1},
    {"groebcplistsort",         CC_groebcplistsort,too_many_1, wrong_no_1},
    {"declared-as-float",       CC_declaredKasKfloat,too_many_1,wrong_no_1},
    {NULL, (one_args *)"u45", (two_args *)"11733 2921098 9670018", 0}
};

/* end of generated code */
