
/* $destdir\u13.c        Machine generated C code */

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


/* Code for ibalp_redclause */

static Lisp_Object CC_ibalp_redclause(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_redclause");
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
    stack[0] = nil;
    v5 = stack[-1];
    v5 = qcar(v5);
    stack[-2] = v5;
    goto v7;

v7:
    v5 = stack[-2];
    if (v5 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v5 = stack[0];
    if (!(v5 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v5 = stack[-2];
    v6 = qcar(v5);
    v5 = stack[-1];
    v5 = qcdr(v5);
    v5 = qcar(v5);
    fn = elt(env, 3); /* ibalp_vmember */
    v5 = (*qfn2(fn))(qenv(fn), v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-3];
    if (v5 == nil) goto v9;
    v5 = qvalue(elt(env, 2)); /* t */
    stack[0] = v5;
    goto v9;

v9:
    v5 = stack[-2];
    v5 = qcdr(v5);
    stack[-2] = v5;
    goto v7;
/* error exit handlers */
v8:
    popv(4);
    return nil;
}



/* Code for aex_simplenullp */

static Lisp_Object CC_aex_simplenullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_simplenullp");
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
    v10 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_nullp */
        return (*qfn1(fn))(qenv(fn), v10);
    }
/* error exit handlers */
v11:
    popv(1);
    return nil;
}



/* Code for variablesir */

static Lisp_Object MS_CDECL CC_variablesir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "variablesir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variablesir");
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
    v8 = qvalue(elt(env, 1)); /* char */
    v17 = elt(env, 2); /* (!/ o m b v a r) */
    if (equal(v8, v17)) goto v11;
    fn = elt(env, 4); /* omvir */
    v17 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    stack[0] = v17;
    fn = elt(env, 5); /* lex */
    v17 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v17 = CC_variablesir(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v18;
    v8 = stack[0];
    if (v8 == nil) goto v19;
    v8 = stack[0];
    popv(2);
    return cons(v8, v17);

v19:
    v8 = stack[0];
        popv(2);
        return Lappend(nil, v8, v17);

v11:
    v17 = nil;
    { popv(2); return onevalue(v17); }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for lid */

static Lisp_Object CC_lid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lid");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */
    v21 = v20;
    if (!consp(v21)) return onevalue(v20);
    v20 = qcar(v20);
    return onevalue(v20);
}



/* Code for invp */

static Lisp_Object CC_invp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for invp");
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
    v33 = v0;
/* end of prologue */
    v32 = v33;
    v31 = elt(env, 1); /* unit */
    if (v32 == v31) return onevalue(v33);
    v31 = v33;
    if (!consp(v31)) goto v34;
    v31 = v33;
    v32 = qcar(v31);
    v31 = elt(env, 3); /* (comm anticomm) */
    v31 = Lmember(nil, v32, v31);
    if (v31 == nil) goto v35;
    v32 = elt(env, 4); /* quotient */
    v31 = (Lisp_Object)17; /* 1 */
    return list3(v32, v31, v33);

v35:
    v31 = v33;
    v32 = qcar(v31);
    v31 = elt(env, 2); /* inverse */
    v31 = get(v32, v31);
    v32 = v33;
    v32 = qcdr(v32);
    return cons(v31, v32);

v34:
    v31 = v33;
    v32 = elt(env, 2); /* inverse */
    return get(v31, v32);
}



/* Code for formcond1 */

static Lisp_Object MS_CDECL CC_formcond1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v13,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formcond1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formcond1");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v13,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v13;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v44;

v44:
    v41 = stack[-3];
    if (v41 == nil) goto v7;
    v41 = stack[-3];
    v41 = qcar(v41);
    v43 = qcar(v41);
    v42 = stack[-2];
    v41 = stack[-1];
    fn = elt(env, 1); /* formbool */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v43, v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    v41 = stack[-3];
    v41 = qcar(v41);
    v41 = qcdr(v41);
    v43 = qcar(v41);
    v42 = stack[-2];
    v41 = stack[-1];
    fn = elt(env, 2); /* formc */
    v41 = (*qfnn(fn))(qenv(fn), 3, v43, v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    v42 = list2(stack[0], v41);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    v41 = stack[-4];
    v41 = cons(v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    stack[-4] = v41;
    v41 = stack[-3];
    v41 = qcdr(v41);
    stack[-3] = v41;
    goto v44;

v7:
    v41 = stack[-4];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v41);
    }
/* error exit handlers */
v32:
    popv(6);
    return nil;
}



/* Code for mkarray1 */

static Lisp_Object CC_mkarray1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v53;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkarray1");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v13;
    stack[-5] = v0;
/* end of prologue */
    v52 = stack[-5];
    if (v52 == nil) goto v20;
    v52 = stack[-5];
    v52 = qcar(v52);
    v52 = sub1(v52);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-7];
    stack[-6] = v52;
    v52 = stack[-6];
    v52 = Lmkvect(nil, v52);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-7];
    stack[-3] = v52;
    v52 = (Lisp_Object)1; /* 0 */
    stack[-2] = v52;
    goto v18;

v18:
    v53 = stack[-6];
    v52 = stack[-2];
    v52 = difference2(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-7];
    v52 = Lminusp(nil, v52);
    env = stack[-7];
    if (!(v52 == nil)) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-3];
    stack[0] = stack[-2];
    v52 = stack[-5];
    v53 = qcdr(v52);
    v52 = stack[-4];
    v52 = CC_mkarray1(env, v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v52;
    v52 = stack[-2];
    v52 = add1(v52);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-7];
    stack[-2] = v52;
    goto v18;

v20:
    v53 = stack[-4];
    v52 = elt(env, 1); /* symbolic */
    if (v53 == v52) goto v7;
    v52 = (Lisp_Object)1; /* 0 */
    { popv(8); return onevalue(v52); }

v7:
    v52 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v52); }
/* error exit handlers */
v54:
    popv(8);
    return nil;
}



/* Code for !:divide */

static Lisp_Object CC_Tdivide(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :divide");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v42 = v13;
    v43 = v0;
/* end of prologue */
    v41 = v43;
    if (v41 == nil) goto v10;
    v41 = v42;
    if (v41 == nil) goto v7;
    v41 = v43;
    if (!consp(v41)) goto v14;
    v41 = qvalue(elt(env, 1)); /* nil */
    goto v37;

v37:
    if (v41 == nil) goto v40;
    v41 = v43;
    {
        popv(1);
        fn = elt(env, 6); /* dividef */
        return (*qfn2(fn))(qenv(fn), v41, v42);
    }

v40:
    v41 = elt(env, 5); /* divide */
    {
        popv(1);
        fn = elt(env, 7); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v43, v42, v41);
    }

v14:
    v41 = v42;
    v41 = (consp(v41) ? nil : lisp_true);
    goto v37;

v7:
    v41 = elt(env, 2); /* "zero divisor" */
    v42 = v41;
    v41 = v42;
    qvalue(elt(env, 3)) = v41; /* errmsg!* */
    v41 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v41 == nil)) goto v58;
    v41 = v42;
    fn = elt(env, 8); /* lprie */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[0];
    goto v58;

v58:
    v41 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v41 = nil;
    { popv(1); return onevalue(v41); }

v10:
    v41 = qvalue(elt(env, 1)); /* nil */
    popv(1);
    return ncons(v41);
/* error exit handlers */
v24:
    popv(1);
    return nil;
}



/* Code for gperm0 */

static Lisp_Object CC_gperm0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm0");
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
    v29 = v0;
/* end of prologue */
    v59 = v29;
    if (v59 == nil) goto v36;
    v59 = v29;
    stack[0] = qcdr(v59);
    v59 = v29;
    v59 = qcar(v59);
    v59 = ncons(v59);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v59 = ncons(v59);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    {
        Lisp_Object v48 = stack[0];
        popv(2);
        fn = elt(env, 2); /* gperm3 */
        return (*qfn2(fn))(qenv(fn), v48, v59);
    }

v36:
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v59); }
/* error exit handlers */
v19:
    popv(2);
    return nil;
}



/* Code for freeofl */

static Lisp_Object CC_freeofl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v23, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeofl");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v13;
    stack[-1] = v0;
/* end of prologue */

v64:
    v39 = stack[0];
    if (v39 == nil) goto v10;
    v39 = stack[0];
    v23 = qcar(v39);
    v39 = stack[-1];
    fn = elt(env, 4); /* smember */
    v39 = (*qfn2(fn))(qenv(fn), v23, v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    if (!(v39 == nil)) goto v49;
    v39 = stack[0];
    v35 = qcar(v39);
    v23 = stack[-1];
    v39 = qvalue(elt(env, 2)); /* depl!* */
    v39 = Lassoc(nil, v23, v39);
    v39 = Lmember(nil, v35, v39);
    if (!(v39 == nil)) goto v49;
    v23 = stack[-1];
    v39 = stack[0];
    v39 = qcdr(v39);
    stack[-1] = v23;
    stack[0] = v39;
    goto v64;

v49:
    v39 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v39); }

v10:
    v39 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v39); }
/* error exit handlers */
v41:
    popv(3);
    return nil;
}



/* Code for xread1 */

static Lisp_Object CC_xread1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v308, v309, v310;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xread1");
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
    stack[-7] = v0;
/* end of prologue */
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v308 = qvalue(elt(env, 1)); /* commentlist!* */
    if (v308 == nil) goto v20;
    v308 = qvalue(elt(env, 1)); /* commentlist!* */
    stack[-1] = v308;
    v308 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v308; /* commentlist!* */
    goto v20;

v20:
    v308 = qvalue(elt(env, 3)); /* cursym!* */
    stack[-3] = v308;
    goto v21;

v21:
    v308 = stack[-3];
    if (!(symbolp(v308))) goto v15;
    v309 = stack[-3];
    v308 = elt(env, 4); /* !*lpar!* */
    if (v309 == v308) goto v51;
    v309 = stack[-3];
    v308 = elt(env, 5); /* !*rpar!* */
    if (v309 == v308) goto v58;
    v309 = stack[-3];
    v308 = elt(env, 6); /* infix */
    v308 = get(v309, v308);
    env = stack[-9];
    stack[-4] = v308;
    if (!(v308 == nil)) goto v311;
    v309 = stack[-3];
    v308 = elt(env, 7); /* delim */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    if (v308 == nil) goto v312;
    v309 = qvalue(elt(env, 3)); /* cursym!* */
    v308 = elt(env, 30); /* !*semicol!* */
    if (v309 == v308) goto v313;
    fn = elt(env, 57); /* eolcheck */
    v308 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v313;

v313:
    v309 = stack[-3];
    v308 = elt(env, 50); /* !*colon!* */
    if (v309 == v308) goto v315;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v316;

v316:
    if (!(v308 == nil)) goto v317;
    v309 = stack[-3];
    v308 = elt(env, 53); /* nodel */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    if (v308 == nil) goto v318;
    v308 = stack[-7];
    if (v308 == nil) goto v319;
    v309 = stack[-7];
    v308 = elt(env, 28); /* group */
    if (v309 == v308) goto v320;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v321;

v321:
    if (!(v308 == nil)) goto v317;
    v308 = stack[-7];
    if (!(symbolp(v308))) goto v60;
    v309 = stack[-7];
    v308 = elt(env, 24); /* paren */
    if (v309 == v308) goto v322;
    v309 = stack[-7];
    v308 = elt(env, 23); /* struct */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    goto v323;

v323:
    if (v308 == nil) goto v60;
    v309 = elt(env, 55); /* "Too few right parentheses" */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v60;

v60:
    v308 = stack[-4];
    if (v308 == nil) goto v324;
    v309 = elt(env, 27); /* "Improper delimiter" */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v325;

v325:
    v308 = (Lisp_Object)1; /* 0 */
    stack[-4] = v308;
    goto v28;

v28:
    v308 = stack[-6];
    if (!(v308 == nil)) goto v326;
    v309 = elt(env, 27); /* "Improper delimiter" */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v326;

v326:
    v308 = stack[-6];
    v308 = qcar(v308);
    stack[0] = v308;
    goto v19;

v19:
    v308 = stack[-6];
    v308 = qcdr(v308);
    stack[-6] = v308;
    v308 = stack[-6];
    if (v308 == nil) goto v327;
    v308 = stack[-6];
    v308 = qcar(v308);
    if (!consp(v308)) goto v328;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v329;

v329:
    if (v308 == nil) goto v330;
    v309 = elt(env, 34); /* "Missing operator" */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v330;

v330:
    v308 = stack[-6];
    v309 = qcar(v308);
    v308 = stack[0];
    v308 = list2(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[0] = v308;
    goto v19;

v328:
    v308 = stack[-6];
    v308 = qcar(v308);
    v308 = Lsymbolp(nil, v308);
    env = stack[-9];
    v308 = (v308 == nil ? lisp_true : nil);
    goto v329;

v327:
    v309 = stack[0];
    v308 = stack[-8];
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-8] = v308;
    goto v331;

v331:
    v308 = stack[-5];
    if (v308 == nil) goto v332;
    v309 = stack[-4];
    v308 = stack[-5];
    v308 = qcar(v308);
    v308 = qcar(v308);
    v308 = (Lisp_Object)lessp2(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    v308 = v308 ? lisp_true : nil;
    env = stack[-9];
    if (!(v308 == nil)) goto v333;
    v309 = stack[-4];
    v308 = stack[-5];
    v308 = qcar(v308);
    v308 = qcar(v308);
    if (equal(v309, v308)) goto v334;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v335;

v335:
    if (!(v308 == nil)) goto v333;

v336:
    v310 = stack[-4];
    v309 = stack[-3];
    v308 = stack[-5];
    v308 = acons(v310, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-5] = v308;
    v309 = stack[-3];
    v308 = elt(env, 25); /* !*comma!* */
    if (!(v309 == v308)) goto v29;
    v308 = stack[-5];
    v308 = qcdr(v308);
    if (!(v308 == nil)) goto v337;
    v308 = stack[-7];
    if (v308 == nil) goto v338;
    v309 = stack[-7];
    v308 = elt(env, 38); /* (lambda paren) */
    v308 = Lmemq(nil, v309, v308);
    if (!(v308 == nil)) goto v339;
    v309 = stack[-7];
    v308 = elt(env, 23); /* struct */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    goto v339;

v339:
    if (!(v308 == nil)) goto v337;

v27:
    v308 = stack[-8];
    v308 = qcdr(v308);
    if (v308 == nil) goto v340;
    v308 = elt(env, 56); /* "Please send hearn@rand.org your program!!" 
*/
    v308 = Lprint(nil, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    v309 = elt(env, 27); /* "Improper delimiter" */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    v308 = nil;
    { popv(10); return onevalue(v308); }

v340:
    v308 = stack[-8];
    v309 = qcar(v308);
    v308 = stack[-1];
    {
        popv(10);
        fn = elt(env, 59); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v309, v308);
    }

v337:
    fn = elt(env, 60); /* scan */
    v308 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-3] = v308;
    goto v21;

v338:
    v308 = qvalue(elt(env, 13)); /* t */
    goto v339;

v29:
    v308 = stack[-2];
    stack[-3] = v308;
    goto v21;

v333:
    v308 = stack[-8];
    v308 = qcdr(v308);
    v309 = qcar(v308);
    v308 = elt(env, 39); /* not */
    if (!consp(v309)) goto v341;
    v309 = qcar(v309);
    if (!(v309 == v308)) goto v341;
    v308 = stack[-5];
    v308 = qcar(v308);
    v310 = qcar(v308);
    v309 = elt(env, 40); /* member */
    v308 = elt(env, 6); /* infix */
    v308 = get(v309, v308);
    env = stack[-9];
    v308 = (Lisp_Object)geq2(v310, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    v308 = v308 ? lisp_true : nil;
    env = stack[-9];
    goto v342;

v342:
    if (v308 == nil) goto v343;
    v309 = elt(env, 41); /* "NOT" */
    v308 = elt(env, 42); /* "infix operator" */
    fn = elt(env, 61); /* typerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v343;

v343:
    v308 = stack[-8];
    v308 = qcdr(v308);
    v309 = qcar(v308);
    v308 = elt(env, 33); /* !*!*un!*!* */
    if (v309 == v308) goto v344;
    v308 = stack[-5];
    v308 = qcar(v308);
    stack[0] = qcdr(v308);
    v308 = stack[-8];
    v309 = qcar(v308);
    v308 = stack[-5];
    v308 = qcar(v308);
    v308 = qcdr(v308);
    if (!consp(v309)) goto v345;
    v309 = qcar(v309);
    if (!(v309 == v308)) goto v345;
    v308 = stack[-5];
    v308 = qcar(v308);
    v309 = qcdr(v308);
    v308 = elt(env, 35); /* nary */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    goto v346;

v346:
    if (v308 == nil) goto v347;
    v308 = stack[-8];
    v308 = qcdr(v308);
    v309 = qcar(v308);
    v308 = stack[-8];
    v308 = qcar(v308);
    v308 = qcdr(v308);
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v348;

v348:
    v308 = cons(stack[0], v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[0] = v308;
    goto v349;

v349:
    v308 = stack[-5];
    v308 = qcdr(v308);
    stack[-5] = v308;
    v309 = stack[0];
    v308 = stack[-8];
    v308 = qcdr(v308);
    v308 = qcdr(v308);
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-8] = v308;
    goto v331;

v347:
    v308 = stack[-8];
    v308 = qcdr(v308);
    v309 = qcar(v308);
    v308 = stack[-8];
    v308 = qcar(v308);
    v308 = list2(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v348;

v345:
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v346;

v344:
    v308 = stack[-8];
    v309 = qcar(v308);
    v308 = elt(env, 33); /* !*!*un!*!* */
    if (v309 == v308) goto v336;
    v308 = stack[-5];
    v308 = qcar(v308);
    v309 = qcdr(v308);
    v308 = stack[-8];
    v308 = qcar(v308);
    v308 = list2(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[0] = v308;
    goto v349;

v341:
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v342;

v334:
    v309 = stack[-3];
    v308 = stack[-5];
    v308 = qcar(v308);
    v308 = qcdr(v308);
    if (v309 == v308) goto v350;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v351;

v351:
    if (v308 == nil) goto v352;
    v308 = qvalue(elt(env, 13)); /* t */
    goto v335;

v352:
    v308 = stack[-5];
    v308 = qcar(v308);
    v309 = qcdr(v308);
    v308 = elt(env, 37); /* alt */
    v308 = get(v309, v308);
    env = stack[-9];
    goto v335;

v350:
    v309 = stack[-3];
    v308 = elt(env, 35); /* nary */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    if (v308 == nil) goto v353;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v351;

v353:
    v309 = stack[-3];
    v308 = elt(env, 36); /* right */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    v308 = (v308 == nil ? lisp_true : nil);
    goto v351;

v332:
    v309 = stack[-4];
    v308 = (Lisp_Object)1; /* 0 */
    if (v309 == v308) goto v27;
    else goto v336;

v324:
    v308 = stack[-8];
    if (v308 == nil) goto v354;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v355;

v355:
    if (v308 == nil) goto v325;
    v309 = qvalue(elt(env, 2)); /* nil */
    v308 = stack[-1];
    {
        popv(10);
        fn = elt(env, 59); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v309, v308);
    }

v354:
    v308 = stack[-6];
    if (v308 == nil) goto v356;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v355;

v356:
    v308 = stack[-5];
    v308 = (v308 == nil ? lisp_true : nil);
    goto v355;

v322:
    v308 = qvalue(elt(env, 13)); /* t */
    goto v323;

v317:
    v309 = elt(env, 27); /* "Improper delimiter" */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v60;

v320:
    v309 = stack[-3];
    v308 = elt(env, 54); /* (!*rsqbkt!* !*rcbkt!* !*rsqb!*) */
    v308 = Lmemq(nil, v309, v308);
    v308 = (v308 == nil ? lisp_true : nil);
    goto v321;

v319:
    v308 = qvalue(elt(env, 13)); /* t */
    goto v321;

v318:
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v321;

v315:
    v309 = stack[-7];
    v308 = elt(env, 51); /* for */
    if (v309 == v308) goto v357;
    v308 = qvalue(elt(env, 52)); /* !*blockp */
    if (v308 == nil) goto v358;
    v308 = stack[-6];
    if (v308 == nil) goto v359;
    v308 = stack[-6];
    v308 = qcar(v308);
    if (!consp(v308)) goto v360;
    v308 = qvalue(elt(env, 13)); /* t */
    goto v316;

v360:
    v308 = stack[-6];
    v308 = qcdr(v308);
    goto v316;

v359:
    v308 = qvalue(elt(env, 13)); /* t */
    goto v316;

v358:
    v308 = qvalue(elt(env, 13)); /* t */
    goto v316;

v357:
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v316;

v312:
    v309 = stack[-3];
    v308 = elt(env, 8); /* stat */
    v308 = get(v309, v308);
    env = stack[-9];
    stack[-4] = v308;
    if (v308 == nil) goto v361;
    v309 = stack[-4];
    v308 = elt(env, 43); /* endstat */
    if (v309 == v308) goto v362;
    fn = elt(env, 57); /* eolcheck */
    v308 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v362;

v362:
    v309 = stack[-3];
    v308 = elt(env, 44); /* go */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    if (v308 == nil) goto v363;
    v308 = qvalue(elt(env, 13)); /* t */
    goto v364;

v364:
    if (v308 == nil) goto v15;
    v309 = stack[-3];
    v308 = elt(env, 48); /* procedure */
    if (v309 == v308) goto v365;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v366;

v366:
    if (v308 == nil) goto v367;
    v308 = stack[-6];
    if (v308 == nil) goto v368;
    v308 = stack[-6];
    v308 = qcdr(v308);
    if (!(v308 == nil)) goto v369;
    v308 = qvalue(elt(env, 9)); /* !*reduce4 */
    if (!(v308 == nil)) goto v369;
    v308 = stack[-6];
    v308 = qcar(v308);
    fn = elt(env, 62); /* procstat1 */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    v308 = ncons(v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-6] = v308;
    goto v370;

v370:
    v308 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v308;
    goto v20;

v369:
    v309 = elt(env, 49); /* "proc form" */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v370;

v368:
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 62); /* procstat1 */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    v308 = ncons(v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-6] = v308;
    goto v370;

v367:
    v309 = stack[-4];
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 63); /* lispapply */
    v309 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    v308 = stack[-6];
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-6] = v308;
    goto v370;

v365:
    v308 = qvalue(elt(env, 9)); /* !*reduce4 */
    goto v366;

v15:
    v308 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v308;
    goto v371;

v371:
    v309 = stack[-3];
    v308 = stack[-6];
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-6] = v308;
    v308 = stack[-3];
    if (is_number(v308)) goto v372;
    v309 = stack[-3];
    v308 = elt(env, 12); /* !:dn!: */
    if (!consp(v309)) goto v373;
    v309 = qcar(v309);
    if (!(v309 == v308)) goto v373;
    v308 = qvalue(elt(env, 13)); /* t */
    goto v374;

v374:
    if (!(v308 == nil)) goto v372;

v375:
    v309 = stack[-7];
    v308 = elt(env, 21); /* proc */
    if (v309 == v308) goto v376;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v377;

v377:
    if (v308 == nil) goto v337;
    v309 = elt(env, 22); /* "Syntax error in procedure header" */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v337;

v376:
    v308 = stack[-6];
    v309 = Llength(nil, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    v308 = (Lisp_Object)33; /* 2 */
    v308 = (Lisp_Object)greaterp2(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    v308 = v308 ? lisp_true : nil;
    env = stack[-9];
    goto v377;

v372:
    v309 = stack[-2];
    v308 = qvalue(elt(env, 15)); /* !$eol!$ */
    if (v309 == v308) goto v378;
    v308 = qvalue(elt(env, 16)); /* nxtsym!* */
    fn = elt(env, 64); /* chknewnam */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-2] = v308;
    if (symbolp(v308)) goto v379;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v380;

v380:
    if (v308 == nil) goto v375;
    v308 = elt(env, 20); /* times */
    qvalue(elt(env, 3)) = v308; /* cursym!* */
    goto v20;

v379:
    v309 = stack[-2];
    v308 = elt(env, 7); /* delim */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    if (v308 == nil) goto v381;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v380;

v381:
    v309 = stack[-2];
    v308 = elt(env, 17); /* switch!* */
    v308 = get(v309, v308);
    env = stack[-9];
    if (v308 == nil) goto v382;
    v309 = stack[-2];
    v308 = elt(env, 18); /* !( */
    if (v309 == v308) goto v382;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v380;

v382:
    v309 = stack[-2];
    v308 = elt(env, 6); /* infix */
    v308 = get(v309, v308);
    env = stack[-9];
    if (v308 == nil) goto v383;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v380;

v383:
    v308 = qvalue(elt(env, 19)); /* !*eoldelimp */
    if (v308 == nil) goto v384;
    v309 = stack[-2];
    v308 = qvalue(elt(env, 15)); /* !$eol!$ */
    v308 = (v309 == v308 ? lisp_true : nil);
    goto v385;

v385:
    v308 = (v308 == nil ? lisp_true : nil);
    goto v380;

v384:
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v385;

v378:
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v380;

v373:
    v309 = stack[-3];
    v308 = elt(env, 14); /* !:int!: */
    v308 = Leqcar(nil, v309, v308);
    env = stack[-9];
    goto v374;

v363:
    v309 = stack[-7];
    v308 = elt(env, 21); /* proc */
    if (v309 == v308) goto v386;
    v309 = stack[-4];
    v308 = elt(env, 45); /* endstatfn */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    if (v308 == nil) goto v387;
    v308 = qvalue(elt(env, 13)); /* t */
    goto v364;

v387:
    v309 = qvalue(elt(env, 16)); /* nxtsym!* */
    v308 = elt(env, 46); /* delchar */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    if (v308 == nil) goto v388;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v364;

v388:
    v309 = qvalue(elt(env, 16)); /* nxtsym!* */
    v308 = elt(env, 47); /* !, */
    v308 = (v309 == v308 ? lisp_true : nil);
    v308 = (v308 == nil ? lisp_true : nil);
    goto v364;

v386:
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v364;

v361:
    v308 = qvalue(elt(env, 9)); /* !*reduce4 */
    if (v308 == nil) goto v389;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v390;

v390:
    if (v308 == nil) goto v15;
    v309 = elt(env, 11); /* decstat */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 63); /* lispapply */
    v309 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    v308 = stack[-6];
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-6] = v308;
    goto v20;

v389:
    v309 = stack[-3];
    v308 = elt(env, 10); /* type */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    goto v390;

v311:
    fn = elt(env, 57); /* eolcheck */
    v308 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    v309 = stack[-3];
    v308 = elt(env, 25); /* !*comma!* */
    if (v309 == v308) goto v391;
    fn = elt(env, 60); /* scan */
    v308 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-2] = v308;
    if (!consp(v308)) goto v392;
    v308 = qvalue(elt(env, 13)); /* t */
    goto v393;

v393:
    if (!(v308 == nil)) goto v9;
    v309 = stack[-2];
    v308 = elt(env, 5); /* !*rpar!* */
    if (v309 == v308) goto v394;
    v309 = stack[-2];
    v308 = elt(env, 25); /* !*comma!* */
    if (v309 == v308) goto v395;
    v309 = stack[-2];
    v308 = elt(env, 7); /* delim */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    goto v396;

v396:
    if (v308 == nil) goto v397;
    v308 = stack[-4];
    if (v308 == nil) goto v398;
    v308 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v308;
    goto v398;

v398:
    v309 = stack[-3];
    v308 = stack[-6];
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-6] = v308;
    goto v29;

v397:
    v309 = stack[-2];
    v308 = elt(env, 4); /* !*lpar!* */
    if (v309 == v308) goto v399;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v400;

v400:
    if (!(v308 == nil)) goto v21;

v9:
    v308 = stack[-6];
    if (!(v308 == nil)) goto v28;
    v309 = stack[-3];
    v308 = elt(env, 31); /* unary */
    v308 = get(v309, v308);
    env = stack[-9];
    stack[-3] = v308;
    if (!(v308 == nil)) goto v401;
    v309 = elt(env, 32); /* "Redundant operator" */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v401;

v401:
    v309 = elt(env, 33); /* !*!*un!*!* */
    v308 = stack[-8];
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-8] = v308;
    goto v336;

v399:
    fn = elt(env, 57); /* eolcheck */
    v308 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    if (v308 == nil) goto v402;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v400;

v402:
    fn = elt(env, 60); /* scan */
    v308 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    v308 = qvalue(elt(env, 19)); /* !*eoldelimp */
    if (v308 == nil) goto v403;
    v309 = qvalue(elt(env, 3)); /* cursym!* */
    v308 = elt(env, 30); /* !*semicol!* */
    if (v309 == v308) goto v402;
    else goto v403;

v403:
    v308 = elt(env, 24); /* paren */
    v308 = CC_xread1(env, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-2] = v308;
    if (!consp(v308)) goto v404;
    v308 = stack[-2];
    v309 = qcar(v308);
    v308 = elt(env, 25); /* !*comma!* */
    if (v309 == v308) goto v405;
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v400;

v405:
    v309 = stack[-3];
    v308 = stack[-2];
    v308 = qcdr(v308);
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-3] = v308;
    goto v400;

v404:
    v308 = qvalue(elt(env, 2)); /* nil */
    goto v400;

v395:
    v308 = qvalue(elt(env, 13)); /* t */
    goto v396;

v394:
    v308 = qvalue(elt(env, 13)); /* t */
    goto v396;

v392:
    v308 = stack[-2];
    v308 = (is_number(v308) ? lisp_true : nil);
    if (!(v308 == nil)) goto v393;
    v309 = stack[-2];
    v308 = elt(env, 12); /* !:dn!: */
    if (!consp(v309)) goto v406;
    v309 = qcar(v309);
    if (!(v309 == v308)) goto v406;
    v308 = qvalue(elt(env, 13)); /* t */
    goto v393;

v406:
    v309 = stack[-2];
    v308 = elt(env, 14); /* !:int!: */
    v308 = Leqcar(nil, v309, v308);
    env = stack[-9];
    goto v393;

v391:
    v308 = qvalue(elt(env, 13)); /* t */
    goto v393;

v58:
    v308 = stack[-7];
    if (v308 == nil) goto v407;
    v309 = stack[-7];
    v308 = elt(env, 28); /* group */
    if (v309 == v308) goto v408;
    v309 = stack[-7];
    v308 = elt(env, 21); /* proc */
    v308 = (v309 == v308 ? lisp_true : nil);
    goto v409;

v409:
    if (v308 == nil) goto v60;
    v309 = elt(env, 29); /* "Too many right parentheses" */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v311;

v408:
    v308 = qvalue(elt(env, 13)); /* t */
    goto v409;

v407:
    v308 = qvalue(elt(env, 13)); /* t */
    goto v409;

v51:
    fn = elt(env, 57); /* eolcheck */
    v308 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    v308 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v308;
    fn = elt(env, 60); /* scan */
    v309 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    v308 = elt(env, 5); /* !*rpar!* */
    if (v309 == v308) goto v34;
    v309 = stack[-6];
    v308 = elt(env, 23); /* struct */
    v308 = Lflagpcar(nil, v309, v308);
    env = stack[-9];
    if (v308 == nil) goto v410;
    v308 = stack[-6];
    v308 = qcar(v308);
    v308 = CC_xread1(env, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-3] = v308;
    goto v411;

v411:
    v309 = stack[-7];
    v308 = elt(env, 23); /* struct */
    v308 = Lflagp(nil, v309, v308);
    env = stack[-9];
    if (v308 == nil) goto v412;
    v309 = stack[-3];
    v308 = elt(env, 25); /* !*comma!* */
    if (!consp(v309)) goto v413;
    v309 = qcar(v309);
    if (!(v309 == v308)) goto v413;
    v308 = stack[-3];
    v308 = qcdr(v308);
    goto v414;

v414:
    stack[-3] = v308;
    goto v371;

v413:
    v308 = stack[-3];
    v308 = ncons(v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v414;

v412:
    v309 = stack[-3];
    v308 = elt(env, 25); /* !*comma!* */
    if (!consp(v309)) goto v371;
    v309 = qcar(v309);
    if (!(v309 == v308)) goto v371;
    v308 = stack[-6];
    if (v308 == nil) goto v415;
    v308 = stack[-6];
    v310 = qcar(v308);
    v308 = stack[-3];
    v309 = qcdr(v308);
    v308 = stack[-6];
    v308 = qcdr(v308);
    v308 = acons(v310, v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-6] = v308;
    goto v337;

v415:
    v309 = stack[-7];
    v308 = elt(env, 26); /* lambda */
    if (v309 == v308) goto v371;
    v309 = elt(env, 27); /* "Improper delimiter" */
    v308 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v308 = (*qfn2(fn))(qenv(fn), v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    goto v337;

v410:
    v308 = elt(env, 24); /* paren */
    v308 = CC_xread1(env, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-3] = v308;
    goto v411;

v34:
    v308 = stack[-6];
    if (v308 == nil) goto v337;
    v308 = stack[-6];
    v308 = qcar(v308);
    v309 = ncons(v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    v308 = stack[-6];
    v308 = qcdr(v308);
    v308 = cons(v309, v308);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-9];
    stack[-6] = v308;
    goto v337;
/* error exit handlers */
v314:
    popv(10);
    return nil;
}



/* Code for cl_atfp */

static Lisp_Object CC_cl_atfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v434, v435, v436;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atfp");
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
    v435 = v0;
/* end of prologue */
    v434 = v435;
    if (!consp(v434)) goto v36;
    v434 = v435;
    v434 = qcar(v434);
    goto v4;

v4:
    v436 = v434;
    v435 = v436;
    v434 = elt(env, 1); /* true */
    if (v435 == v434) goto v58;
    v435 = v436;
    v434 = elt(env, 3); /* false */
    v434 = (v435 == v434 ? lisp_true : nil);
    goto v34;

v34:
    if (v434 == nil) goto v56;
    v434 = qvalue(elt(env, 2)); /* t */
    goto v15;

v15:
    v434 = (v434 == nil ? lisp_true : nil);
    return onevalue(v434);

v56:
    v435 = v436;
    v434 = elt(env, 4); /* or */
    if (v435 == v434) goto v35;
    v435 = v436;
    v434 = elt(env, 5); /* and */
    v434 = (v435 == v434 ? lisp_true : nil);
    goto v23;

v23:
    if (v434 == nil) goto v437;
    v434 = qvalue(elt(env, 2)); /* t */
    goto v49;

v49:
    if (v434 == nil) goto v302;
    v434 = qvalue(elt(env, 2)); /* t */
    goto v438;

v438:
    if (v434 == nil) goto v294;
    v434 = qvalue(elt(env, 2)); /* t */
    goto v15;

v294:
    v435 = v436;
    v434 = elt(env, 10); /* ex */
    if (v435 == v434) goto v439;
    v435 = v436;
    v434 = elt(env, 11); /* all */
    v434 = (v435 == v434 ? lisp_true : nil);
    goto v440;

v440:
    if (v434 == nil) goto v441;
    v434 = qvalue(elt(env, 2)); /* t */
    goto v15;

v441:
    v435 = v436;
    v434 = elt(env, 12); /* bex */
    if (v435 == v434) goto v442;
    v435 = v436;
    v434 = elt(env, 13); /* ball */
    v434 = (v435 == v434 ? lisp_true : nil);
    goto v443;

v443:
    if (v434 == nil) goto v444;
    v434 = qvalue(elt(env, 2)); /* t */
    goto v15;

v444:
    v435 = v436;
    v434 = elt(env, 14); /* rl_external */
    v434 = get(v435, v434);
    goto v15;

v442:
    v434 = qvalue(elt(env, 2)); /* t */
    goto v443;

v439:
    v434 = qvalue(elt(env, 2)); /* t */
    goto v440;

v302:
    v435 = v436;
    v434 = elt(env, 7); /* impl */
    if (v435 == v434) goto v445;
    v435 = v436;
    v434 = elt(env, 8); /* repl */
    if (v435 == v434) goto v446;
    v435 = v436;
    v434 = elt(env, 9); /* equiv */
    v434 = (v435 == v434 ? lisp_true : nil);
    goto v438;

v446:
    v434 = qvalue(elt(env, 2)); /* t */
    goto v438;

v445:
    v434 = qvalue(elt(env, 2)); /* t */
    goto v438;

v437:
    v435 = v436;
    v434 = elt(env, 6); /* not */
    v434 = (v435 == v434 ? lisp_true : nil);
    goto v49;

v35:
    v434 = qvalue(elt(env, 2)); /* t */
    goto v23;

v58:
    v434 = qvalue(elt(env, 2)); /* t */
    goto v34;

v36:
    v434 = v435;
    goto v4;
}



/* Code for ibalp_lenisone */

static Lisp_Object CC_ibalp_lenisone(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_lenisone");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v21 = v15;
    if (v21 == nil) goto v36;
    v21 = v15;
    v21 = qcdr(v21);
    v21 = (v21 == nil ? lisp_true : nil);
    return onevalue(v21);

v36:
    v21 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v21);
}



/* Code for numpoly_nullp */

static Lisp_Object CC_numpoly_nullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v58;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_nullp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v58 = v0;
/* end of prologue */
    v34 = v58;
    if (v34 == nil) goto v36;
    v34 = (Lisp_Object)1; /* 0 */
    v34 = (v58 == v34 ? lisp_true : nil);
    return onevalue(v34);

v36:
    v34 = qvalue(elt(env, 1)); /* t */
    return onevalue(v34);
}



/* Code for inshisto */

static Lisp_Object CC_inshisto(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v442, v459, v441;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inshisto");
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
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v459 = qvalue(elt(env, 2)); /* maxvar */
    v442 = stack[-3];
    v442 = plus2(v459, v442);
    nil = C_nil;
    if (exception_pending()) goto v419;
    env = stack[-5];
    v459 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v442/(16/CELL)));
    v442 = (Lisp_Object)1; /* 0 */
    v442 = *(Lisp_Object *)((char *)v459 + (CELL-TAG_VECTOR) + ((int32_t)v442/(16/CELL)));
    if (v442 == nil) goto v10;
    v459 = stack[-3];
    v442 = (Lisp_Object)1; /* 0 */
    v442 = (Lisp_Object)geq2(v459, v442);
    nil = C_nil;
    if (exception_pending()) goto v419;
    v442 = v442 ? lisp_true : nil;
    env = stack[-5];
    if (v442 == nil) goto v10;
    stack[0] = qvalue(elt(env, 3)); /* codhisto */
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v459 = qvalue(elt(env, 2)); /* maxvar */
    v442 = stack[-3];
    v442 = plus2(v459, v442);
    nil = C_nil;
    if (exception_pending()) goto v419;
    env = stack[-5];
    v459 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v442/(16/CELL)));
    v442 = (Lisp_Object)17; /* 1 */
    v442 = *(Lisp_Object *)((char *)v459 + (CELL-TAG_VECTOR) + ((int32_t)v442/(16/CELL)));
    v459 = qcdr(v442);
    v442 = (Lisp_Object)3201; /* 200 */
    fn = elt(env, 6); /* min */
    v442 = (*qfn2(fn))(qenv(fn), v459, v442);
    nil = C_nil;
    if (exception_pending()) goto v419;
    env = stack[-5];
    stack[-2] = v442;
    v442 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v442/(16/CELL)));
    stack[-4] = v442;
    if (v442 == nil) goto v460;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v459 = qvalue(elt(env, 2)); /* maxvar */
    v442 = stack[-4];
    v442 = plus2(v459, v442);
    nil = C_nil;
    if (exception_pending()) goto v419;
    env = stack[-5];
    v459 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v442/(16/CELL)));
    v442 = (Lisp_Object)113; /* 7 */
    v459 = *(Lisp_Object *)((char *)v459 + (CELL-TAG_VECTOR) + ((int32_t)v442/(16/CELL)));
    v442 = stack[-3];
    v442 = Lrplaca(nil, v459, v442);
    nil = C_nil;
    if (exception_pending()) goto v419;
    env = stack[-5];
    goto v461;

v461:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v459 = qvalue(elt(env, 2)); /* maxvar */
    v442 = stack[-3];
    v442 = plus2(v459, v442);
    nil = C_nil;
    if (exception_pending()) goto v419;
    env = stack[-5];
    stack[-1] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v442/(16/CELL)));
    stack[0] = (Lisp_Object)113; /* 7 */
    v459 = qvalue(elt(env, 5)); /* nil */
    v442 = stack[-4];
    v442 = cons(v459, v442);
    nil = C_nil;
    if (exception_pending()) goto v419;
    env = stack[-5];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v442;
    v441 = qvalue(elt(env, 3)); /* codhisto */
    v459 = stack[-2];
    v442 = stack[-3];
    *(Lisp_Object *)((char *)v441 + (CELL-TAG_VECTOR) + ((int32_t)v459/(16/CELL))) = v442;
    v442 = nil;
    { popv(6); return onevalue(v442); }

v460:
    v459 = stack[-2];
    v442 = qvalue(elt(env, 4)); /* headhisto */
    v442 = (Lisp_Object)greaterp2(v459, v442);
    nil = C_nil;
    if (exception_pending()) goto v419;
    v442 = v442 ? lisp_true : nil;
    env = stack[-5];
    if (v442 == nil) goto v461;
    v442 = stack[-2];
    qvalue(elt(env, 4)) = v442; /* headhisto */
    goto v461;

v10:
    v442 = nil;
    { popv(6); return onevalue(v442); }
/* error exit handlers */
v419:
    popv(6);
    return nil;
}



/* Code for evenfree */

static Lisp_Object CC_evenfree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evenfree");
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
    v31 = stack[0];
    if (v31 == nil) goto v36;
    v31 = stack[0];
    if (is_number(v31)) goto v20;
    v31 = stack[0];
    v31 = qcar(v31);
    v32 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v31 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v31 = (*qfn2(fn))(qenv(fn), v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v31 = qcdr(v31);
    stack[-1] = v31;
    v31 = stack[-1];
    fn = elt(env, 3); /* minusf */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    if (v31 == nil) goto v42;
    v31 = stack[-1];
    fn = elt(env, 4); /* negf */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    stack[-1] = v31;
    goto v433;

v433:
    v31 = stack[0];
    v31 = qcdr(v31);
    v31 = CC_evenfree(env, v31);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    {
        Lisp_Object v47 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* addf */
        return (*qfn2(fn))(qenv(fn), v47, v31);
    }

v42:
    v31 = stack[-1];
    stack[-1] = v31;
    goto v433;

v20:
    v32 = stack[0];
    v31 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v31 = (*qfn2(fn))(qenv(fn), v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v31 = qcdr(v31);
    stack[0] = v31;
    v31 = stack[0];
    fn = elt(env, 3); /* minusf */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    if (v31 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v31 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* negf */
        return (*qfn1(fn))(qenv(fn), v31);
    }

v36:
    v31 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v31); }
/* error exit handlers */
v46:
    popv(3);
    return nil;
}



/* Code for revalind */

static Lisp_Object CC_revalind(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v26, v18;
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
    v8 = qvalue(elt(env, 2)); /* nil */
    v8 = ncons(v8);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    qvalue(elt(env, 1)) = v8; /* alglist!* */
    v8 = qvalue(elt(env, 3)); /* subfg!* */
    stack[-2] = v8;
    v8 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v8; /* subfg!* */
    v18 = elt(env, 4); /* !0 */
    v26 = (Lisp_Object)1; /* 0 */
    v8 = stack[-1];
    v8 = Lsubst(nil, 3, v18, v26, v8);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    stack[-1] = v8;
    v8 = stack[-1];
    fn = elt(env, 6); /* simp */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v26 = v8;
    v8 = v26;
    v8 = qcar(v8);
    if (v8 == nil) goto v331;
    v8 = elt(env, 5); /* prepf */
    fn = elt(env, 7); /* sqform */
    v8 = (*qfn2(fn))(qenv(fn), v26, v8);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    goto v48;

v48:
    v26 = v8;
    v8 = stack[-2];
    qvalue(elt(env, 3)) = v8; /* subfg!* */
    v8 = v26;
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    { popv(4); return onevalue(v8); }

v331:
    v8 = (Lisp_Object)1; /* 0 */
    goto v48;
/* error exit handlers */
v62:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for all_defined_vertex */

static Lisp_Object CC_all_defined_vertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v34, v58, v311;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined_vertex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v51 = v13;
    v34 = v0;
/* end of prologue */
    v311 = v34;
    v58 = qvalue(elt(env, 1)); /* nil */
    v34 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* al1_defined_vertex */
        return (*qfnn(fn))(qenv(fn), 4, v311, v58, v34, v51);
    }
}



/* Code for getmatelem */

static Lisp_Object CC_getmatelem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v472, v473, v474;
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

v7:
    v472 = stack[-1];
    v473 = Llength(nil, v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    v472 = (Lisp_Object)49; /* 3 */
    if (v473 == v472) goto v331;
    v473 = stack[-1];
    v472 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 12); /* typerr */
    v472 = (*qfn2(fn))(qenv(fn), v473, v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    goto v331;

v331:
    v472 = stack[-1];
    v473 = qcar(v472);
    v472 = elt(env, 2); /* avalue */
    v472 = get(v473, v472);
    env = stack[-3];
    stack[-2] = v472;
    v472 = stack[-2];
    if (v472 == nil) goto v12;
    v472 = stack[-2];
    v473 = qcar(v472);
    v472 = elt(env, 4); /* matrix */
    v472 = (v473 == v472 ? lisp_true : nil);
    v472 = (v472 == nil ? lisp_true : nil);
    goto v6;

v6:
    if (v472 == nil) goto v458;
    v472 = stack[-1];
    v473 = qcar(v472);
    v472 = elt(env, 5); /* "matrix" */
    fn = elt(env, 12); /* typerr */
    v472 = (*qfn2(fn))(qenv(fn), v473, v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    goto v432;

v432:
    v472 = stack[-1];
    v472 = qcdr(v472);
    v472 = qcar(v472);
    fn = elt(env, 13); /* reval_without_mod */
    v472 = (*qfn1(fn))(qenv(fn), v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    stack[0] = v472;
    v472 = stack[0];
    v472 = integerp(v472);
    if (v472 == nil) goto v476;
    v473 = stack[0];
    v472 = (Lisp_Object)1; /* 0 */
    v472 = (Lisp_Object)lesseq2(v473, v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    v472 = v472 ? lisp_true : nil;
    env = stack[-3];
    goto v296;

v296:
    if (v472 == nil) goto v422;
    v473 = stack[0];
    v472 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v472 = (*qfn2(fn))(qenv(fn), v473, v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    goto v422;

v422:
    v472 = stack[-2];
    v473 = qcdr(v472);
    v472 = stack[0];
    fn = elt(env, 14); /* pnth */
    v472 = (*qfn2(fn))(qenv(fn), v473, v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    v472 = qcar(v472);
    stack[-2] = v472;
    v472 = stack[-1];
    v472 = qcdr(v472);
    v472 = qcdr(v472);
    v472 = qcar(v472);
    fn = elt(env, 13); /* reval_without_mod */
    v472 = (*qfn1(fn))(qenv(fn), v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    stack[0] = v472;
    v472 = stack[0];
    v472 = integerp(v472);
    if (v472 == nil) goto v477;
    v473 = stack[0];
    v472 = (Lisp_Object)1; /* 0 */
    v472 = (Lisp_Object)lesseq2(v473, v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    v472 = v472 ? lisp_true : nil;
    env = stack[-3];
    goto v419;

v419:
    if (v472 == nil) goto v435;
    v473 = stack[0];
    v472 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v472 = (*qfn2(fn))(qenv(fn), v473, v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    goto v435;

v435:
    v473 = stack[-2];
    v472 = stack[0];
    fn = elt(env, 14); /* pnth */
    v472 = (*qfn2(fn))(qenv(fn), v473, v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    v472 = qcar(v472);
    { popv(4); return onevalue(v472); }

v477:
    v472 = qvalue(elt(env, 3)); /* t */
    goto v419;

v476:
    v472 = qvalue(elt(env, 3)); /* t */
    goto v296;

v458:
    v472 = stack[-2];
    v472 = qcdr(v472);
    v473 = qcar(v472);
    stack[-2] = v473;
    v472 = elt(env, 6); /* mat */
    if (!consp(v473)) goto v31;
    v473 = qcar(v473);
    if (v473 == v472) goto v432;
    else goto v31;

v31:
    v472 = stack[-2];
    if (symbolp(v472)) goto v304;
    v474 = elt(env, 7); /* "Matrix" */
    v472 = stack[-1];
    v473 = qcar(v472);
    v472 = elt(env, 8); /* "not set" */
    v472 = list3(v474, v473, v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    v473 = v472;
    v472 = v473;
    qvalue(elt(env, 9)) = v472; /* errmsg!* */
    v472 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v472 == nil)) goto v478;
    v472 = v473;
    fn = elt(env, 15); /* lprie */
    v472 = (*qfn1(fn))(qenv(fn), v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    goto v478;

v478:
    v472 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    goto v432;

v304:
    v473 = stack[-2];
    v472 = stack[-1];
    v472 = qcdr(v472);
    v472 = cons(v473, v472);
    nil = C_nil;
    if (exception_pending()) goto v475;
    env = stack[-3];
    stack[-1] = v472;
    goto v7;

v12:
    v472 = qvalue(elt(env, 3)); /* t */
    goto v6;
/* error exit handlers */
v475:
    popv(4);
    return nil;
}



/* Code for b!:extadd */

static Lisp_Object CC_bTextadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v440, v439, v293;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:extadd");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v13;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v11;

v11:
    v440 = stack[-2];
    if (v440 == nil) goto v21;
    v440 = stack[-1];
    if (v440 == nil) goto v28;
    v440 = stack[-2];
    v440 = qcar(v440);
    v439 = qcar(v440);
    v440 = stack[-1];
    v440 = qcar(v440);
    v440 = qcar(v440);
    if (equal(v439, v440)) goto v26;
    v440 = stack[-2];
    v440 = qcar(v440);
    v439 = qcar(v440);
    v440 = stack[-1];
    v440 = qcar(v440);
    v440 = qcar(v440);
    fn = elt(env, 1); /* b!:ordexp */
    v440 = (*qfn2(fn))(qenv(fn), v439, v440);
    nil = C_nil;
    if (exception_pending()) goto v483;
    env = stack[-4];
    if (v440 == nil) goto v427;
    v440 = stack[-2];
    v439 = qcar(v440);
    v440 = stack[0];
    v440 = cons(v439, v440);
    nil = C_nil;
    if (exception_pending()) goto v483;
    env = stack[-4];
    stack[0] = v440;
    v440 = stack[-2];
    v440 = qcdr(v440);
    stack[-2] = v440;
    goto v11;

v427:
    v440 = stack[-1];
    v439 = qcar(v440);
    v440 = stack[0];
    v440 = cons(v439, v440);
    nil = C_nil;
    if (exception_pending()) goto v483;
    env = stack[-4];
    stack[0] = v440;
    v440 = stack[-1];
    v440 = qcdr(v440);
    stack[-1] = v440;
    goto v11;

v26:
    stack[-3] = stack[0];
    v440 = stack[-2];
    v440 = qcar(v440);
    v439 = qcdr(v440);
    v440 = stack[-1];
    v440 = qcar(v440);
    v440 = qcdr(v440);
    fn = elt(env, 2); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v439, v440);
    nil = C_nil;
    if (exception_pending()) goto v483;
    env = stack[-4];
    v440 = stack[-2];
    v439 = qcdr(v440);
    v440 = stack[-1];
    v440 = qcdr(v440);
    v440 = CC_bTextadd(env, v439, v440);
    nil = C_nil;
    if (exception_pending()) goto v483;
    env = stack[-4];
    v439 = stack[0];
    v293 = v439;
    if (v293 == nil) goto v63;
    v293 = stack[-2];
    v293 = qcar(v293);
    v293 = qcar(v293);
    v440 = acons(v293, v439, v440);
    nil = C_nil;
    if (exception_pending()) goto v483;
    env = stack[-4];
    goto v63;

v63:
    {
        Lisp_Object v424 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v424, v440);
    }

v28:
    v439 = stack[0];
    v440 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v439, v440);
    }

v21:
    v439 = stack[0];
    v440 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v439, v440);
    }
/* error exit handlers */
v483:
    popv(5);
    return nil;
}



/* Code for negate!-term */

static Lisp_Object CC_negateKterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v15;
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
    v15 = v0;
/* end of prologue */
    v21 = v15;
    stack[0] = qcar(v21);
    v21 = v15;
    v21 = qcdr(v21);
    fn = elt(env, 1); /* minus!-mod!-p */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v337;
    {
        Lisp_Object v51 = stack[0];
        popv(1);
        return cons(v51, v21);
    }
/* error exit handlers */
v337:
    popv(1);
    return nil;
}



/* Code for defineargs */

static Lisp_Object CC_defineargs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v305, v52, v53, v456;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for defineargs");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v13;
    stack[-1] = v0;
/* end of prologue */
    v52 = stack[-1];
    v305 = elt(env, 1); /* number!-of!-args */
    v305 = get(v52, v305);
    env = stack[-2];
    v52 = v305;
    v305 = v52;
    if (v305 == nil) goto v9;
    v53 = stack[0];
    v305 = v52;
    if (equal(v53, v305)) goto v14;
    v53 = stack[-1];
    v305 = elt(env, 3); /* calledby */
    v53 = get(v53, v305);
    env = stack[-2];
    v305 = v53;
    if (v53 == nil) goto v32;
    v456 = stack[-1];
    v53 = stack[0];
    fn = elt(env, 4); /* instdof */
    v305 = (*qfnn(fn))(qenv(fn), 4, v456, v53, v52, v305);
    nil = C_nil;
    if (exception_pending()) goto v454;
    env = stack[-2];
    goto v32;

v32:
    v52 = stack[-1];
    v305 = stack[0];
    fn = elt(env, 5); /* hasarg */
    v305 = (*qfn2(fn))(qenv(fn), v52, v305);
    nil = C_nil;
    if (exception_pending()) goto v454;
    v305 = nil;
    { popv(3); return onevalue(v305); }

v14:
    v305 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v305); }

v9:
    v52 = stack[-1];
    v305 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* hasarg */
        return (*qfn2(fn))(qenv(fn), v52, v305);
    }
/* error exit handlers */
v454:
    popv(3);
    return nil;
}



/* Code for ofsf_smmkatl */

static Lisp_Object MS_CDECL CC_ofsf_smmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v13,
                         Lisp_Object v3, Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v12, v38, v17, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smmkatl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v4;
    v17 = v3;
    v8 = v13;
    v6 = v0;
/* end of prologue */
    v12 = v6;
    v6 = elt(env, 1); /* and */
    if (v12 == v6) goto v51;
    v6 = v8;
    v12 = v17;
    {
        fn = elt(env, 2); /* ofsf_smmkatl!-or */
        return (*qfnn(fn))(qenv(fn), 3, v6, v12, v38);
    }

v51:
    v6 = v8;
    v12 = v17;
    {
        fn = elt(env, 3); /* ofsf_smmkatl!-and */
        return (*qfnn(fn))(qenv(fn), 3, v6, v12, v38);
    }
}



/* Code for qqe_simplat1 */

static Lisp_Object CC_qqe_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v39, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplat1");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v13;
    stack[-1] = v0;
/* end of prologue */
    v40 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    v23 = v40;
    v39 = v23;
    v40 = elt(env, 1); /* (qequal qneq) */
    v40 = Lmemq(nil, v39, v40);
    if (v40 == nil) goto v58;
    v39 = v23;
    v40 = elt(env, 2); /* qequal */
    if (v39 == v40) goto v432;
    v39 = stack[-1];
    v40 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* qqe_simplqneq */
        return (*qfn2(fn))(qenv(fn), v39, v40);
    }

v432:
    v39 = stack[-1];
    v40 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* qqe_simplqequal */
        return (*qfn2(fn))(qenv(fn), v39, v40);
    }

v58:
    v39 = stack[-1];
    v40 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* qqe_simplbtat */
        return (*qfn2(fn))(qenv(fn), v39, v40);
    }
/* error exit handlers */
v56:
    popv(3);
    return nil;
}



/* Code for ibalp_hassimple */

static Lisp_Object CC_ibalp_hassimple(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v38;
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
    v12 = v0;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v12;
    goto v69;

v69:
    v12 = stack[0];
    if (v12 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v12 = stack[-1];
    if (!(v12 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v12 = stack[0];
    v12 = qcar(v12);
    v38 = qcar(v12);
    v12 = stack[0];
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v12 = qcar(v12);
    fn = elt(env, 2); /* ibalp_commonlenisone */
    v12 = (*qfn2(fn))(qenv(fn), v38, v12);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    if (v12 == nil) goto v311;
    v12 = stack[0];
    v12 = qcar(v12);
    stack[-1] = v12;
    goto v311;

v311:
    v12 = stack[0];
    v12 = qcdr(v12);
    stack[0] = v12;
    goto v69;
/* error exit handlers */
v26:
    popv(3);
    return nil;
}



/* Code for constsml */

static Lisp_Object CC_constsml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v304;
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
    v54 = stack[0];
    if (!(is_number(v54))) goto v10;
    v54 = elt(env, 1); /* "<cn" */
    fn = elt(env, 13); /* printout */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    v54 = stack[0];
    v54 = Lfloatp(nil, v54);
    env = stack[-1];
    if (v54 == nil) goto v15;
    v54 = elt(env, 2); /* " type=""real""> " */
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    goto v20;

v20:
    v54 = stack[0];
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    v54 = elt(env, 5); /* " </cn>" */
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    goto v10;

v10:
    v54 = stack[0];
    if (!(symbolp(v54))) goto v2;
    v54 = stack[0];
    v304 = Lintern(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    v54 = qvalue(elt(env, 6)); /* constants!* */
    v54 = Lmember(nil, v304, v54);
    if (v54 == nil) goto v55;
    v54 = elt(env, 7); /* "<cn type=""constant""> " */
    fn = elt(env, 13); /* printout */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    v54 = stack[0];
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    v54 = elt(env, 5); /* " </cn>" */
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    goto v2;

v2:
    v54 = nil;
    { popv(2); return onevalue(v54); }

v55:
    v54 = elt(env, 8); /* "<ci" */
    fn = elt(env, 13); /* printout */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    v54 = stack[0];
    fn = elt(env, 14); /* listp */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    if (v54 == nil) goto v306;
    v54 = elt(env, 9); /* " type=""list""> " */
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    goto v24;

v24:
    v54 = stack[0];
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    v54 = elt(env, 11); /* " </ci>" */
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    goto v2;

v306:
    v54 = stack[0];
    v54 = Lsimple_vectorp(nil, v54);
    env = stack[-1];
    if (v54 == nil) goto v52;
    v54 = elt(env, 10); /* " type=""vector""> " */
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    goto v24;

v52:
    v54 = elt(env, 4); /* "> " */
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    goto v24;

v15:
    v54 = stack[0];
    v54 = integerp(v54);
    if (v54 == nil) goto v19;
    v54 = elt(env, 3); /* " type=""integer""> " */
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    goto v20;

v19:
    v54 = elt(env, 4); /* "> " */
    v54 = Lprinc(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-1];
    goto v20;
/* error exit handlers */
v361:
    popv(2);
    return nil;
}



/* Code for simprecip */

static Lisp_Object CC_simprecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v432;
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
    v432 = v0;
/* end of prologue */
    v45 = qvalue(elt(env, 1)); /* !*mcd */
    if (v45 == nil) goto v51;
    v45 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v45 = (*qfn2(fn))(qenv(fn), v432, v45);
    nil = C_nil;
    if (exception_pending()) goto v433;
    env = stack[0];
    fn = elt(env, 4); /* simp */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v433;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* invsq */
        return (*qfn1(fn))(qenv(fn), v45);
    }

v51:
    v45 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v432 = (*qfn2(fn))(qenv(fn), v432, v45);
    nil = C_nil;
    if (exception_pending()) goto v433;
    env = stack[0];
    v45 = (Lisp_Object)-15; /* -1 */
    v45 = list2(v432, v45);
    nil = C_nil;
    if (exception_pending()) goto v433;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v45);
    }
/* error exit handlers */
v433:
    popv(1);
    return nil;
}



/* Code for list!-mgen */

static Lisp_Object CC_listKmgen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6;
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
    v6 = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = nil; /* i */
    v5 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v5; /* i */
    v5 = v6;
    stack[0] = v5;
    goto v69;

v69:
    v5 = stack[0];
    if (v5 == nil) goto v132;
    v5 = stack[0];
    v5 = qcar(v5);
    v6 = v5;
    v5 = v6;
    if (!consp(v5)) goto v48;
    v5 = qvalue(elt(env, 2)); /* nil */
    goto v19;

v19:
    if (v5 == nil) goto v9;
    v5 = qvalue(elt(env, 1)); /* i */
    v5 = add1(v5);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    qvalue(elt(env, 1)) = v5; /* i */
    goto v9;

v9:
    v5 = stack[0];
    v5 = qcdr(v5);
    stack[0] = v5;
    goto v69;

v48:
    v5 = v6;
    fn = elt(env, 3); /* mgenp */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    goto v19;

v132:
    v5 = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    { popv(3); return onevalue(v5); }
/* error exit handlers */
v17:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    popv(3);
    return nil;
}



/* Code for vbcgcd */

static Lisp_Object CC_vbcgcd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v487, v426;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vbcgcd");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v13;
    stack[-1] = v0;
/* end of prologue */
    v426 = stack[-1];
    v487 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v487 = (*qfn2(fn))(qenv(fn), v426, v487);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-2];
    if (v487 == nil) goto v20;
    v426 = stack[0];
    v487 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v487 = (*qfn2(fn))(qenv(fn), v426, v487);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-2];
    v487 = (v487 == nil ? lisp_true : nil);
    goto v30;

v30:
    if (v487 == nil) goto v17;
    v487 = elt(env, 2); /* (1 . 1) */
    { popv(3); return onevalue(v487); }

v17:
    v487 = stack[-1];
    v426 = qcdr(v487);
    v487 = (Lisp_Object)17; /* 1 */
    if (v426 == v487) goto v49;
    v487 = qvalue(elt(env, 3)); /* nil */
    goto v6;

v6:
    if (v487 == nil) goto v428;
    v487 = stack[-1];
    v487 = qcar(v487);
    v487 = integerp(v487);
    if (v487 == nil) goto v488;
    v487 = stack[0];
    v487 = qcar(v487);
    v487 = integerp(v487);
    if (v487 == nil) goto v488;
    v487 = stack[-1];
    v426 = qcar(v487);
    v487 = stack[0];
    v487 = qcar(v487);
    v426 = Lgcd(nil, v426, v487);
    nil = C_nil;
    if (exception_pending()) goto v297;
    v487 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v426, v487);

v488:
    v487 = stack[-1];
    v426 = qcar(v487);
    v487 = stack[0];
    v487 = qcar(v487);
    fn = elt(env, 5); /* gcdf!* */
    v426 = (*qfn2(fn))(qenv(fn), v426, v487);
    nil = C_nil;
    if (exception_pending()) goto v297;
    v487 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v426, v487);

v428:
    v426 = (Lisp_Object)17; /* 1 */
    v487 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v426, v487);

v49:
    v487 = stack[0];
    v426 = qcdr(v487);
    v487 = (Lisp_Object)17; /* 1 */
    v487 = (v426 == v487 ? lisp_true : nil);
    goto v6;

v20:
    v487 = qvalue(elt(env, 1)); /* t */
    goto v30;
/* error exit handlers */
v297:
    popv(3);
    return nil;
}



/* Code for groebcplistsortin */

static Lisp_Object CC_groebcplistsortin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistsortin");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v13;
    v59 = v0;
/* end of prologue */
    v9 = stack[0];
    if (v9 == nil) goto v10;
    v9 = stack[0];
    fn = elt(env, 1); /* groebcplistsortin1 */
    v9 = (*qfn2(fn))(qenv(fn), v59, v9);
    nil = C_nil;
    if (exception_pending()) goto v28;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v10:
    v9 = v59;
    popv(1);
    return ncons(v9);
/* error exit handlers */
v28:
    popv(1);
    return nil;
}



/* Code for termordp!! */

static Lisp_Object CC_termordpB(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v331, v57, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termordp!");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v13;
    v37 = v0;
/* end of prologue */
    v57 = v37;
    v331 = stack[0];
    if (equal(v57, v331)) goto v28;
    v331 = v37;
    fn = elt(env, 2); /* guesspftype */
    stack[-1] = (*qfn1(fn))(qenv(fn), v331);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v331 = stack[0];
    fn = elt(env, 2); /* guesspftype */
    v331 = (*qfn1(fn))(qenv(fn), v331);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    {
        Lisp_Object v27 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* termordp */
        return (*qfn2(fn))(qenv(fn), v27, v331);
    }

v28:
    v331 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v331); }
/* error exit handlers */
v60:
    popv(3);
    return nil;
}



/* Code for putd */

static Lisp_Object MS_CDECL CC_putd(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v13,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v286, v287, v271;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "putd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for putd");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v13,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v13;
    stack[-2] = v0;
/* end of prologue */
    v287 = stack[0];
    v286 = elt(env, 1); /* funarg */
    if (!consp(v287)) goto v10;
    v287 = qcar(v287);
    if (!(v287 == v286)) goto v10;
    v287 = elt(env, 2); /* lambda */
    v286 = stack[0];
    v286 = qcdr(v286);
    v286 = qcdr(v286);
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    stack[0] = v286;
    goto v10;

v10:
    v286 = stack[-2];
    if (!symbolp(v286)) v286 = nil;
    else { v286 = qfastgets(v286);
           if (v286 != nil) { v286 = elt(v286, 1); /* lose */
#ifdef RECORD_GET
             if (v286 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v286 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v286 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v286 == SPID_NOPROP) v286 = nil; else v286 = lisp_true; }}
#endif
    if (v286 == nil) goto v6;
    v286 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    v286 = elt(env, 3); /* "+++ " */
    v286 = Lprinc(nil, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    v286 = stack[-2];
    v286 = Lprin(nil, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    v286 = elt(env, 4); /* " not defined (LOSE flag)" */
    v286 = Lprintc(nil, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    v286 = qvalue(elt(env, 5)); /* nil */
    { popv(4); return onevalue(v286); }

v6:
    v286 = qvalue(elt(env, 6)); /* !*redefmsg */
    if (v286 == nil) goto v24;
    v286 = stack[-2];
    fn = elt(env, 15); /* getd */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    if (v286 == nil) goto v24;
    v286 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    v286 = elt(env, 3); /* "+++ " */
    v286 = Lprinc(nil, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    v286 = stack[-2];
    v286 = Lprin(nil, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    v286 = elt(env, 7); /* " redefined" */
    v286 = Lprintc(nil, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    goto v24;

v24:
    v287 = stack[-1];
    v286 = elt(env, 8); /* expr */
    if (v287 == v286) goto v46;
    v287 = stack[-1];
    v286 = elt(env, 9); /* subr */
    if (v287 == v286) goto v361;
    v287 = stack[-1];
    v286 = elt(env, 10); /* macro */
    if (v287 == v286) goto v452;
    v286 = qvalue(elt(env, 5)); /* nil */
    goto v493;

v493:
    if (v286 == nil) goto v294;
    v271 = elt(env, 11); /* dm */
    v287 = stack[-2];
    v286 = stack[0];
    v286 = qcdr(v286);
    v286 = list2star(v271, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v294:
    v287 = stack[-1];
    v286 = elt(env, 12); /* fexpr */
    if (v287 == v286) goto v449;
    v286 = qvalue(elt(env, 5)); /* nil */
    goto v440;

v440:
    if (v286 == nil) goto v380;
    v271 = elt(env, 13); /* df */
    v287 = stack[-2];
    v286 = stack[0];
    v286 = qcdr(v286);
    v286 = list2star(v271, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v380:
    v287 = elt(env, 14); /* "Bad type ~S in putd" */
    v286 = stack[-1];
    fn = elt(env, 17); /* error */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v449:
    v287 = stack[0];
    v286 = elt(env, 2); /* lambda */
    v286 = Leqcar(nil, v287, v286);
    env = stack[-3];
    goto v440;

v452:
    v287 = stack[0];
    v286 = elt(env, 2); /* lambda */
    v286 = Leqcar(nil, v287, v286);
    env = stack[-3];
    goto v493;

v361:
    v287 = stack[-2];
    v286 = stack[0];
    v286 = Lsymbol_set_definition(nil, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v46:
    v287 = stack[-2];
    v286 = stack[0];
    v286 = Lsymbol_set_definition(nil, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v492;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v492:
    popv(4);
    return nil;
}



/* Code for setel */

static Lisp_Object CC_setel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33, v458, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setel");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v13;
    stack[-2] = v0;
/* end of prologue */
    v32 = stack[-2];
    v33 = qcar(v32);
    v32 = elt(env, 1); /* dimension */
    v32 = get(v33, v32);
    env = stack[-4];
    stack[-3] = v32;
    v32 = stack[-3];
    stack[0] = Llength(nil, v32);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v32 = stack[-2];
    v32 = qcdr(v32);
    v32 = Llength(nil, v32);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    if (equal(stack[0], v32)) goto v40;
    v32 = elt(env, 2); /* "Incorrect array reference" */
    v33 = v32;
    v32 = v33;
    qvalue(elt(env, 3)) = v32; /* errmsg!* */
    v32 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v32 == nil)) goto v27;
    v32 = v33;
    fn = elt(env, 6); /* lprie */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    goto v27;

v27:
    v32 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v32 = nil;
    { popv(5); return onevalue(v32); }

v40:
    v32 = stack[-2];
    v33 = qcar(v32);
    v32 = elt(env, 5); /* avalue */
    v32 = get(v33, v32);
    env = stack[-4];
    v32 = qcdr(v32);
    v46 = qcar(v32);
    v32 = stack[-2];
    v458 = qcdr(v32);
    v33 = stack[-1];
    v32 = stack[-3];
    {
        popv(5);
        fn = elt(env, 7); /* setel1 */
        return (*qfnn(fn))(qenv(fn), 4, v46, v458, v33, v32);
    }
/* error exit handlers */
v52:
    popv(5);
    return nil;
}



/* Code for mv2sf1 */

static Lisp_Object MS_CDECL CC_mv2sf1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v13,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v35, v55, v56, v41;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mv2sf1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv2sf1");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v13,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v55 = v3;
    v41 = v13;
    v56 = v0;
/* end of prologue */

v11:
    v23 = v56;
    if (v23 == nil) { popv(3); return onevalue(v41); }
    v23 = v56;
    v35 = qcar(v23);
    v23 = (Lisp_Object)1; /* 0 */
    if (v35 == v23) goto v21;
    v23 = v55;
    stack[-1] = qcar(v23);
    v23 = v56;
    stack[0] = qcar(v23);
    v23 = v56;
    v23 = qcdr(v23);
    v35 = v41;
    v55 = qcdr(v55);
    v23 = CC_mv2sf1(env, 3, v23, v35, v55);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    v23 = acons(stack[-1], stack[0], v23);
    nil = C_nil;
    if (exception_pending()) goto v24;
    popv(3);
    return ncons(v23);

v21:
    v23 = v56;
    v23 = qcdr(v23);
    v56 = v23;
    v23 = v55;
    v23 = qcdr(v23);
    v55 = v23;
    goto v11;
/* error exit handlers */
v24:
    popv(3);
    return nil;
}



/* Code for make!-term */

static Lisp_Object MS_CDECL CC_makeKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v13,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v501, v502, v503;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "make-term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-term");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v13,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v3;
    stack[-4] = v13;
    stack[-5] = v0;
/* end of prologue */
    v501 = (Lisp_Object)1; /* 0 */
    stack[-2] = v501;
    v501 = (Lisp_Object)1; /* 0 */
    stack[0] = v501;
    goto v59;

v59:
    v502 = stack[-4];
    v501 = stack[0];
    v502 = *(Lisp_Object *)((char *)v502 + (CELL-TAG_VECTOR) + ((int32_t)v501/(16/CELL)));
    v501 = (Lisp_Object)1; /* 0 */
    v501 = (Lisp_Object)lessp2(v502, v501);
    nil = C_nil;
    if (exception_pending()) goto v504;
    v501 = v501 ? lisp_true : nil;
    env = stack[-7];
    if (v501 == nil) goto v6;
    v501 = (Lisp_Object)-15; /* -1 */
    stack[-2] = v501;
    goto v21;

v21:
    v501 = (Lisp_Object)49; /* 3 */
    v501 = Lmkvect(nil, v501);
    nil = C_nil;
    if (exception_pending()) goto v504;
    env = stack[-7];
    stack[-6] = v501;
    v502 = stack[-2];
    v501 = (Lisp_Object)17; /* 1 */
    if (v502 == v501) goto v505;
    v502 = stack[-5];
    v501 = elt(env, 4); /* cos */
    v501 = (v502 == v501 ? lisp_true : nil);
    goto v506;

v506:
    if (v501 == nil) goto v460;
    v503 = stack[-6];
    v502 = (Lisp_Object)1; /* 0 */
    v501 = stack[-3];
    *(Lisp_Object *)((char *)v503 + (CELL-TAG_VECTOR) + ((int32_t)v502/(16/CELL))) = v501;
    goto v507;

v507:
    v503 = stack[-6];
    v502 = (Lisp_Object)17; /* 1 */
    v501 = stack[-5];
    *(Lisp_Object *)((char *)v503 + (CELL-TAG_VECTOR) + ((int32_t)v502/(16/CELL))) = v501;
    v502 = stack[-2];
    v501 = (Lisp_Object)-15; /* -1 */
    if (!(v502 == v501)) goto v379;
    v501 = (Lisp_Object)113; /* 7 */
    v501 = Lmkvect(nil, v501);
    nil = C_nil;
    if (exception_pending()) goto v504;
    env = stack[-7];
    stack[-2] = v501;
    v501 = (Lisp_Object)1; /* 0 */
    stack[-3] = v501;
    goto v441;

v441:
    v502 = (Lisp_Object)113; /* 7 */
    v501 = stack[-3];
    v501 = difference2(v502, v501);
    nil = C_nil;
    if (exception_pending()) goto v504;
    env = stack[-7];
    v501 = Lminusp(nil, v501);
    env = stack[-7];
    if (v501 == nil) goto v372;
    v501 = stack[-2];
    stack[-4] = v501;
    goto v379;

v379:
    v503 = stack[-6];
    v502 = (Lisp_Object)33; /* 2 */
    v501 = stack[-4];
    *(Lisp_Object *)((char *)v503 + (CELL-TAG_VECTOR) + ((int32_t)v502/(16/CELL))) = v501;
    v502 = stack[-6];
    v501 = (Lisp_Object)49; /* 3 */
    v503 = qvalue(elt(env, 2)); /* nil */
    *(Lisp_Object *)((char *)v502 + (CELL-TAG_VECTOR) + ((int32_t)v501/(16/CELL))) = v503;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v372:
    stack[-1] = stack[-2];
    stack[0] = stack[-3];
    v502 = stack[-4];
    v501 = stack[-3];
    v501 = *(Lisp_Object *)((char *)v502 + (CELL-TAG_VECTOR) + ((int32_t)v501/(16/CELL)));
    v501 = negate(v501);
    nil = C_nil;
    if (exception_pending()) goto v504;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v501;
    v501 = stack[-3];
    v501 = add1(v501);
    nil = C_nil;
    if (exception_pending()) goto v504;
    env = stack[-7];
    stack[-3] = v501;
    goto v441;

v460:
    stack[-1] = stack[-6];
    stack[0] = (Lisp_Object)1; /* 0 */
    v502 = elt(env, 5); /* (-1 . 1) */
    v501 = stack[-3];
    fn = elt(env, 6); /* multsq */
    v501 = (*qfn2(fn))(qenv(fn), v502, v501);
    nil = C_nil;
    if (exception_pending()) goto v504;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v501;
    goto v507;

v505:
    v501 = qvalue(elt(env, 3)); /* t */
    goto v506;

v6:
    v502 = stack[-4];
    v501 = stack[0];
    v502 = *(Lisp_Object *)((char *)v502 + (CELL-TAG_VECTOR) + ((int32_t)v501/(16/CELL)));
    v501 = (Lisp_Object)1; /* 0 */
    v501 = (Lisp_Object)greaterp2(v502, v501);
    nil = C_nil;
    if (exception_pending()) goto v504;
    v501 = v501 ? lisp_true : nil;
    env = stack[-7];
    if (v501 == nil) goto v50;
    v501 = (Lisp_Object)17; /* 1 */
    stack[-2] = v501;
    goto v21;

v50:
    v502 = stack[0];
    v501 = (Lisp_Object)113; /* 7 */
    if (v502 == v501) goto v25;
    v501 = stack[0];
    v501 = (Lisp_Object)((int32_t)(v501) + 0x10);
    stack[0] = v501;
    goto v59;

v25:
    v502 = stack[-5];
    v501 = elt(env, 1); /* sin */
    if (!(v502 == v501)) goto v21;
    v501 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v501); }
/* error exit handlers */
v504:
    popv(8);
    return nil;
}



/* Code for bc_inv */

static Lisp_Object CC_bc_inv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v39, v23;
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
    v23 = v0;
/* end of prologue */
    v39 = v23;
    v40 = (Lisp_Object)17; /* 1 */
    if (v39 == v40) goto v132;
    v39 = v23;
    v40 = (Lisp_Object)-15; /* -1 */
    v40 = (v39 == v40 ? lisp_true : nil);
    goto v44;

v44:
    if (!(v40 == nil)) { popv(1); return onevalue(v23); }
    v40 = (Lisp_Object)17; /* 1 */
    v39 = v23;
    fn = elt(env, 3); /* qremf */
    v40 = (*qfn2(fn))(qenv(fn), v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[0];
    v39 = v40;
    v40 = v39;
    v40 = qcdr(v40);
    if (v40 == nil) goto v462;
    v40 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v40); }

v462:
    v40 = v39;
    v40 = qcar(v40);
    { popv(1); return onevalue(v40); }

v132:
    v40 = qvalue(elt(env, 1)); /* t */
    goto v44;
/* error exit handlers */
v35:
    popv(1);
    return nil;
}



/* Code for class */

static Lisp_Object CC_class(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v432, v433;
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
    v432 = stack[0];
    fn = elt(env, 3); /* ord */
    v433 = (*qfn1(fn))(qenv(fn), v432);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    v432 = (Lisp_Object)1; /* 0 */
    if (v433 == v432) goto v36;
    v433 = qvalue(elt(env, 1)); /* ordering */
    v432 = elt(env, 2); /* lex */
    if (v433 == v432) goto v9;
    v432 = stack[0];
    v432 = qcdr(v432);
    goto v311;

v311:
    v432 = Lreverse(nil, v432);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    fn = elt(env, 4); /* leftzeros */
    v432 = (*qfn1(fn))(qenv(fn), v432);
    nil = C_nil;
    if (exception_pending()) goto v5;
    v432 = (Lisp_Object)((int32_t)(v432) + 0x10);
    { popv(2); return onevalue(v432); }

v9:
    v432 = stack[0];
    goto v311;

v36:
    v432 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v432); }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for pv_times2 */

static Lisp_Object MS_CDECL CC_pv_times2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v13,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v432, v433;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pv_times2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_times2");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v13,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    v432 = v13;
    stack[-1] = v0;
/* end of prologue */

v44:
    v433 = v432;
    if (v433 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v433 = v432;
    v433 = qcdr(v433);
    stack[-2] = v433;
    v433 = stack[-1];
    v432 = qcar(v432);
    fn = elt(env, 1); /* pv_times3 */
    v432 = (*qfn2(fn))(qenv(fn), v433, v432);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-3];
    v433 = ncons(v432);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-3];
    v432 = stack[0];
    fn = elt(env, 2); /* pv_add */
    v432 = (*qfn2(fn))(qenv(fn), v433, v432);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-3];
    stack[0] = v432;
    v432 = stack[-2];
    goto v44;
/* error exit handlers */
v12:
    popv(4);
    return nil;
}



/* Code for b!:ordexn */

static Lisp_Object CC_bTordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v445, v481;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:ordexn");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v13;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    stack[-3] = nil;
    goto v44;

v44:
    v445 = stack[-1];
    if (v445 == nil) goto v59;
    v481 = stack[-2];
    v445 = stack[-1];
    v445 = qcar(v445);
    if (equal(v481, v445)) goto v37;
    v445 = stack[-2];
    if (v445 == nil) goto v454;
    v481 = stack[-2];
    v445 = stack[-1];
    v445 = qcar(v445);
    v445 = (Lisp_Object)greaterp2(v481, v445);
    nil = C_nil;
    if (exception_pending()) goto v299;
    v445 = v445 ? lisp_true : nil;
    env = stack[-4];
    if (v445 == nil) goto v454;
    v481 = stack[-2];
    v445 = stack[-3];
    v445 = cons(v481, v445);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-4];
    v481 = Lreverse(nil, v445);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-4];
    v445 = stack[-1];
    v445 = Lappend(nil, v481, v445);
    nil = C_nil;
    if (exception_pending()) goto v299;
    {
        Lisp_Object v390 = stack[0];
        popv(5);
        return cons(v390, v445);
    }

v454:
    v445 = stack[-1];
    v481 = qcar(v445);
    v445 = stack[-3];
    v445 = cons(v481, v445);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-4];
    stack[-3] = v445;
    v445 = stack[-1];
    v445 = qcdr(v445);
    stack[-1] = v445;
    v445 = stack[0];
    v445 = (v445 == nil ? lisp_true : nil);
    stack[0] = v445;
    goto v44;

v37:
    v445 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v445); }

v59:
    v481 = stack[-2];
    v445 = stack[-3];
    v445 = cons(v481, v445);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-4];
    v445 = Lreverse(nil, v445);
    nil = C_nil;
    if (exception_pending()) goto v299;
    {
        Lisp_Object v430 = stack[0];
        popv(5);
        return cons(v430, v445);
    }
/* error exit handlers */
v299:
    popv(5);
    return nil;
}



/* Code for split_ext */

static Lisp_Object CC_split_ext(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v429, v428, v460;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_ext");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v428 = v13;
    v460 = v0;
/* end of prologue */
    v429 = v460;
    v429 = qcdr(v429);
    stack[-7] = v429;
    v429 = v460;
    v429 = qcar(v429);
    fn = elt(env, 3); /* split_form */
    v429 = (*qfn2(fn))(qenv(fn), v429, v428);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    stack[0] = v429;
    v429 = elt(env, 1); /* ext */
    stack[-6] = ncons(v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    v429 = stack[0];
    v428 = qcar(v429);
    v429 = stack[-7];
    v429 = cons(v428, v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    stack[-5] = (*qfn1(fn))(qenv(fn), v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    v429 = stack[0];
    v429 = qcdr(v429);
    stack[-4] = v429;
    v429 = stack[-4];
    if (v429 == nil) goto v63;
    v429 = stack[-4];
    v429 = qcar(v429);
    v428 = v429;
    v429 = v428;
    stack[0] = qcar(v429);
    v429 = v428;
    v428 = qcdr(v429);
    v429 = stack[-7];
    v429 = cons(v428, v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    v429 = (*qfn1(fn))(qenv(fn), v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    v429 = cons(stack[0], v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    v429 = ncons(v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    stack[-2] = v429;
    stack[-3] = v429;
    goto v17;

v17:
    v429 = stack[-4];
    v429 = qcdr(v429);
    stack[-4] = v429;
    v429 = stack[-4];
    if (v429 == nil) goto v457;
    stack[-1] = stack[-2];
    v429 = stack[-4];
    v429 = qcar(v429);
    v428 = v429;
    v429 = v428;
    stack[0] = qcar(v429);
    v429 = v428;
    v428 = qcdr(v429);
    v429 = stack[-7];
    v429 = cons(v428, v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    v429 = (*qfn1(fn))(qenv(fn), v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    v429 = cons(stack[0], v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    v429 = ncons(v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    v429 = Lrplacd(nil, stack[-1], v429);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-8];
    v429 = stack[-2];
    v429 = qcdr(v429);
    stack[-2] = v429;
    goto v17;

v457:
    v429 = stack[-3];
    goto v28;

v28:
    {
        Lisp_Object v509 = stack[-6];
        Lisp_Object v297 = stack[-5];
        popv(9);
        return acons(v509, v297, v429);
    }

v63:
    v429 = qvalue(elt(env, 2)); /* nil */
    goto v28;
/* error exit handlers */
v427:
    popv(9);
    return nil;
}



/* Code for rl_prepfof */

static Lisp_Object CC_rl_prepfof(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
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
    v10 = v0;
/* end of prologue */
    fn = elt(env, 1); /* rl_csimpl */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* rl_prepfof1 */
        return (*qfn1(fn))(qenv(fn), v10);
    }
/* error exit handlers */
v11:
    popv(1);
    return nil;
}



/* Code for wureducedpolysp */

static Lisp_Object CC_wureducedpolysp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v432, v433;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wureducedpolysp");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v13;
    stack[-1] = v0;
/* end of prologue */

v64:
    v432 = stack[0];
    if (v432 == nil) goto v10;
    v433 = stack[-1];
    v432 = stack[0];
    v432 = qcar(v432);
    fn = elt(env, 3); /* wureducedp */
    v432 = (*qfn2(fn))(qenv(fn), v433, v432);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-2];
    if (v432 == nil) goto v21;
    v433 = stack[-1];
    v432 = stack[0];
    v432 = qcdr(v432);
    stack[-1] = v433;
    stack[0] = v432;
    goto v64;

v21:
    v432 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v432); }

v10:
    v432 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v432); }
/* error exit handlers */
v6:
    popv(3);
    return nil;
}



/* Code for get_rep_matrix_in */

static Lisp_Object CC_get_rep_matrix_in(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v456;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_rep_matrix_in");
#endif
    if (stack >= stacklimit)
    {
        push2(v13,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v456 = v13;
    stack[-2] = v0;
/* end of prologue */
    stack[-1] = nil;
    v53 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v53;
    v53 = v456;
    v53 = qcdr(v53);
    stack[0] = v53;
    goto v21;

v21:
    v53 = stack[-3];
    if (v53 == nil) goto v28;
    v53 = qvalue(elt(env, 1)); /* nil */
    goto v58;

v58:
    if (v53 == nil) goto v20;
    v53 = stack[0];
    v53 = qcar(v53);
    v456 = qcar(v53);
    v53 = stack[-2];
    if (!(equal(v456, v53))) goto v433;
    v53 = stack[0];
    v53 = qcar(v53);
    v53 = qcdr(v53);
    v53 = qcar(v53);
    stack[-1] = v53;
    v53 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v53;
    goto v433;

v433:
    v53 = stack[0];
    v53 = qcdr(v53);
    stack[0] = v53;
    goto v21;

v20:
    v53 = stack[-3];
    if (!(v53 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v53 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v53 == nil)) goto v458;
    v53 = elt(env, 4); /* "error in get representation matrix" */
    fn = elt(env, 5); /* lprie */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v506;
    env = stack[-4];
    goto v458;

v458:
    v53 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v506;
    v53 = nil;
    { popv(5); return onevalue(v53); }

v28:
    v53 = stack[0];
    v456 = Llength(nil, v53);
    nil = C_nil;
    if (exception_pending()) goto v506;
    env = stack[-4];
    v53 = (Lisp_Object)1; /* 0 */
    v53 = (Lisp_Object)greaterp2(v456, v53);
    nil = C_nil;
    if (exception_pending()) goto v506;
    v53 = v53 ? lisp_true : nil;
    env = stack[-4];
    goto v58;
/* error exit handlers */
v506:
    popv(5);
    return nil;
}



/* Code for qqe_number!-of!-adds!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKaddsKinKqterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v1;
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

v36:
    v14 = stack[0];
    if (!consp(v14)) goto v44;
    v14 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v1 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    v14 = elt(env, 1); /* (ladd radd) */
    v14 = Lmemq(nil, v1, v14);
    if (v14 == nil) goto v48;
    v14 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    v14 = CC_qqe_numberKofKaddsKinKqterm(env, v14);
    nil = C_nil;
    if (exception_pending()) goto v27;
    popv(2);
    return add1(v14);

v48:
    v14 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    stack[0] = v14;
    goto v36;

v44:
    v14 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v14); }
/* error exit handlers */
v27:
    popv(2);
    return nil;
}



/* Code for cgb_buch!-ev_divides!? */

static Lisp_Object CC_cgb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v13)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgb_buch-ev_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v13;
    v30 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v20, v30);
    }
}



/* Code for stats_getargs */

static Lisp_Object MS_CDECL CC_stats_getargs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v311;
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
    v58 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    v311 = v58;
    v58 = v311;
    if (v58 == nil) goto v44;
    stack[0] = v311;
    v58 = CC_stats_getargs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    {
        Lisp_Object v29 = stack[0];
        popv(2);
        return cons(v29, v58);
    }

v44:
    v58 = nil;
    { popv(2); return onevalue(v58); }
/* error exit handlers */
v59:
    popv(2);
    return nil;
}



setup_type const u13_setup[] =
{
    {"ibalp_redclause",         CC_ibalp_redclause,too_many_1, wrong_no_1},
    {"aex_simplenullp",         CC_aex_simplenullp,too_many_1, wrong_no_1},
    {"variablesir",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_variablesir},
    {"lid",                     CC_lid,         too_many_1,    wrong_no_1},
    {"invp",                    CC_invp,        too_many_1,    wrong_no_1},
    {"formcond1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcond1},
    {"mkarray1",                too_few_2,      CC_mkarray1,   wrong_no_2},
    {":divide",                 too_few_2,      CC_Tdivide,    wrong_no_2},
    {"gperm0",                  CC_gperm0,      too_many_1,    wrong_no_1},
    {"freeofl",                 too_few_2,      CC_freeofl,    wrong_no_2},
    {"xread1",                  CC_xread1,      too_many_1,    wrong_no_1},
    {"cl_atfp",                 CC_cl_atfp,     too_many_1,    wrong_no_1},
    {"ibalp_lenisone",          CC_ibalp_lenisone,too_many_1,  wrong_no_1},
    {"numpoly_nullp",           CC_numpoly_nullp,too_many_1,   wrong_no_1},
    {"inshisto",                CC_inshisto,    too_many_1,    wrong_no_1},
    {"evenfree",                CC_evenfree,    too_many_1,    wrong_no_1},
    {"revalind",                CC_revalind,    too_many_1,    wrong_no_1},
    {"all_defined_vertex",      too_few_2,      CC_all_defined_vertex,wrong_no_2},
    {"getmatelem",              CC_getmatelem,  too_many_1,    wrong_no_1},
    {"b:extadd",                too_few_2,      CC_bTextadd,   wrong_no_2},
    {"negate-term",             CC_negateKterm, too_many_1,    wrong_no_1},
    {"defineargs",              too_few_2,      CC_defineargs, wrong_no_2},
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
    {NULL, (one_args *)"u13", (two_args *)"7713 5437721 9977764", 0}
};

/* end of generated code */
