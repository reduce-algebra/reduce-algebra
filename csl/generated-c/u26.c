
/* $destdir\u26.c        Machine generated C code */

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


/* Code for even_action_sf */

static Lisp_Object MS_CDECL CC_even_action_sf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15, v16, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "even_action_sf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for even_action_sf");
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
    stack[0] = v3;
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v15 = qvalue(elt(env, 1)); /* nil */
    v14 = (Lisp_Object)17; /* 1 */
    v14 = cons(v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-5];
    v15 = v14;
    goto v19;

v19:
    v14 = stack[-2];
    if (!consp(v14)) goto v20;
    v14 = stack[-2];
    v14 = qcar(v14);
    v14 = (consp(v14) ? nil : lisp_true);
    goto v21;

v21:
    if (!(v14 == nil)) { popv(6); return onevalue(v15); }
    stack[-4] = v15;
    v17 = stack[-3];
    v14 = stack[-2];
    v16 = qcar(v14);
    v15 = stack[-1];
    v14 = stack[0];
    fn = elt(env, 3); /* even_action_term */
    v14 = (*qfnn(fn))(qenv(fn), 4, v17, v16, v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-5];
    fn = elt(env, 4); /* addsq */
    v14 = (*qfn2(fn))(qenv(fn), stack[-4], v14);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-5];
    v15 = v14;
    v14 = stack[-2];
    v14 = qcdr(v14);
    stack[-2] = v14;
    goto v19;

v20:
    v14 = qvalue(elt(env, 2)); /* t */
    goto v21;
/* error exit handlers */
v18:
    popv(6);
    return nil;
}



/* Code for deginvar */

static Lisp_Object CC_deginvar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deginvar");
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
    v7 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    if (v7 == nil) goto v30;
    v7 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v7); }

v30:
    v7 = stack[-1];
    v7 = qcar(v7);
    v7 = qcar(v7);
    v29 = qcar(v7);
    v7 = stack[0];
    if (equal(v29, v7)) goto v31;
    stack[-2] = qvalue(elt(env, 1)); /* kord!* */
    qvalue(elt(env, 1)) = nil; /* kord!* */
    v7 = stack[0];
    v7 = ncons(v7);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    qvalue(elt(env, 1)) = v7; /* kord!* */
    v7 = stack[-1];
    fn = elt(env, 3); /* reorder */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    stack[-1] = v7;
    v7 = stack[-1];
    v7 = qcar(v7);
    v7 = qcar(v7);
    v29 = qcar(v7);
    v7 = stack[0];
    if (equal(v29, v7)) goto v32;
    v7 = (Lisp_Object)1; /* 0 */
    goto v33;

v33:
    qvalue(elt(env, 1)) = stack[-2]; /* kord!* */
    { popv(4); return onevalue(v7); }

v32:
    v7 = stack[-1];
    v7 = qcar(v7);
    v7 = qcar(v7);
    v7 = qcdr(v7);
    goto v33;

v31:
    v7 = stack[-1];
    v7 = qcar(v7);
    v7 = qcar(v7);
    v7 = qcdr(v7);
    { popv(4); return onevalue(v7); }
/* error exit handlers */
v16:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* kord!* */
    popv(4);
    return nil;
v15:
    popv(4);
    return nil;
}



/* Code for cgp_mk */

static Lisp_Object MS_CDECL CC_cgp_mk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v39, v40, v41, v42;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "cgp_mk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_mk");
#endif
    if (stack >= stacklimit)
    {
        push5(v34,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v33 = v34;
    v39 = v3;
    v40 = v2;
    v41 = v1;
    v42 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* cgp */
    stack[-1] = v42;
    stack[0] = v41;
    v33 = list3(v40, v39, v33);
    nil = C_nil;
    if (exception_pending()) goto v43;
    {
        Lisp_Object v44 = stack[-2];
        Lisp_Object v45 = stack[-1];
        Lisp_Object v4 = stack[0];
        popv(3);
        return list3star(v44, v45, v4, v33);
    }
/* error exit handlers */
v43:
    popv(3);
    return nil;
}



/* Code for relnrd */

static Lisp_Object MS_CDECL CC_relnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "relnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for relnrd");
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
    stack[0] = nil;
    fn = elt(env, 5); /* lex */
    v15 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    v15 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 6); /* compress!* */
    v16 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    v15 = qvalue(elt(env, 2)); /* rdreln!* */
    v16 = Lassoc(nil, v16, v15);
    v15 = v16;
    if (v16 == nil) goto v42;
    v16 = v15;
    v16 = qcdr(v16);
    v16 = qcar(v16);
    v15 = qcdr(v15);
    v15 = qcdr(v15);
    fn = elt(env, 7); /* apply */
    v15 = (*qfn2(fn))(qenv(fn), v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    stack[0] = v15;
    goto v48;

v48:
    v16 = stack[0];
    v15 = qvalue(elt(env, 3)); /* t */
    if (equal(v16, v15)) goto v49;
    v15 = stack[0];
    if (!(v15 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v15 = elt(env, 4); /* false */
    { popv(2); return onevalue(v15); }

v49:
    v15 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v15); }

v42:
    v15 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 6); /* compress!* */
    v16 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    v15 = (Lisp_Object)289; /* 18 */
    fn = elt(env, 8); /* errorml */
    v15 = (*qfn2(fn))(qenv(fn), v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    goto v48;
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for s!-nextarg */

static Lisp_Object CC_sKnextarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v81, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for s-nextarg");
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
    v80 = qvalue(elt(env, 1)); /* !*udebug */
    if (v80 == nil) goto v83;
    v80 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 13); /* uprint */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    goto v83;

v83:
    v80 = qvalue(elt(env, 3)); /* comb */
    if (!(v80 == nil)) goto v38;
    v80 = qvalue(elt(env, 4)); /* i */
    v80 = add1(v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    qvalue(elt(env, 4)) = v80; /* i */
    v80 = stack[0];
    fn = elt(env, 14); /* initcomb */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    qvalue(elt(env, 3)) = v80; /* comb */
    goto v38;

v38:
    v81 = stack[0];
    v80 = qvalue(elt(env, 3)); /* comb */
    fn = elt(env, 15); /* getcomb */
    v80 = (*qfn2(fn))(qenv(fn), v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    stack[-1] = v80;
    if (v80 == nil) goto v85;
    v81 = qvalue(elt(env, 4)); /* i */
    v80 = (Lisp_Object)17; /* 1 */
    if (v81 == v80) goto v86;
    v80 = qvalue(elt(env, 2)); /* nil */
    goto v44;

v44:
    if (v80 == nil) goto v87;
    v80 = stack[-1];
    v80 = qcar(v80);
    v81 = qcar(v80);
    v80 = stack[-1];
    v80 = qcdr(v80);
    popv(3);
    return cons(v81, v80);

v87:
    v81 = qvalue(elt(env, 4)); /* i */
    v80 = (Lisp_Object)1; /* 0 */
    if (v81 == v80) goto v88;
    v80 = qvalue(elt(env, 2)); /* nil */
    goto v89;

v89:
    if (v80 == nil) goto v90;
    v81 = elt(env, 6); /* (null!-fn) */
    v80 = stack[0];
    popv(3);
    return cons(v81, v80);

v90:
    v80 = qvalue(elt(env, 7)); /* acontract */
    if (v80 == nil) goto v91;
    v81 = qvalue(elt(env, 4)); /* i */
    v80 = qvalue(elt(env, 5)); /* upb */
    v80 = (Lisp_Object)lesseq2(v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    v80 = v80 ? lisp_true : nil;
    env = stack[-2];
    if (v80 == nil) goto v91;
    v82 = qvalue(elt(env, 8)); /* op */
    v80 = stack[-1];
    v81 = qcar(v80);
    v80 = stack[-1];
    v80 = qcdr(v80);
    v80 = acons(v82, v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 16); /* mval */
        return (*qfn1(fn))(qenv(fn), v80);
    }

v91:
    v80 = qvalue(elt(env, 9)); /* mcontract */
    if (v80 == nil) goto v92;
    v81 = qvalue(elt(env, 4)); /* i */
    v80 = qvalue(elt(env, 5)); /* upb */
    v80 = (Lisp_Object)lesseq2(v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    v80 = v80 ? lisp_true : nil;
    env = stack[-2];
    if (v80 == nil) goto v92;
    v82 = elt(env, 10); /* null!-fn */
    v80 = stack[-1];
    v81 = qcar(v80);
    v80 = stack[-1];
    v80 = qcdr(v80);
    popv(3);
    return acons(v82, v81, v80);

v92:
    v80 = qvalue(elt(env, 11)); /* expand */
    if (v80 == nil) goto v93;
    v80 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 11)) = v80; /* expand */
    v81 = qvalue(elt(env, 12)); /* identity */
    v80 = stack[0];
    popv(3);
    return cons(v81, v80);

v93:
    v80 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v80); }

v88:
    v81 = qvalue(elt(env, 4)); /* i */
    v80 = qvalue(elt(env, 5)); /* upb */
    v80 = (Lisp_Object)lesseq2(v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    v80 = v80 ? lisp_true : nil;
    env = stack[-2];
    goto v89;

v86:
    v81 = qvalue(elt(env, 4)); /* i */
    v80 = qvalue(elt(env, 5)); /* upb */
    v80 = (Lisp_Object)lesseq2(v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    v80 = v80 ? lisp_true : nil;
    env = stack[-2];
    goto v44;

v85:
    v81 = qvalue(elt(env, 4)); /* i */
    v80 = (Lisp_Object)1; /* 0 */
    if (v81 == v80) goto v94;
    v80 = qvalue(elt(env, 2)); /* nil */
    goto v95;

v95:
    if (v80 == nil) goto v96;
    v81 = elt(env, 6); /* (null!-fn) */
    v80 = stack[0];
    popv(3);
    return cons(v81, v80);

v96:
    v80 = qvalue(elt(env, 11)); /* expand */
    if (v80 == nil) goto v97;
    v80 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 11)) = v80; /* expand */
    v81 = qvalue(elt(env, 12)); /* identity */
    v80 = stack[0];
    popv(3);
    return cons(v81, v80);

v97:
    v80 = nil;
    { popv(3); return onevalue(v80); }

v94:
    v81 = qvalue(elt(env, 4)); /* i */
    v80 = qvalue(elt(env, 5)); /* upb */
    v80 = (Lisp_Object)lesseq2(v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    v80 = v80 ? lisp_true : nil;
    env = stack[-2];
    goto v95;
/* error exit handlers */
v84:
    popv(3);
    return nil;
}



/* Code for dipequal */

static Lisp_Object CC_dipequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipequal");
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

v10:
    v14 = stack[-1];
    if (v14 == nil) goto v99;
    v14 = stack[0];
    if (v14 == nil) goto v100;
    v14 = stack[-1];
    v14 = qcdr(v14);
    v15 = qcar(v14);
    v14 = stack[0];
    v14 = qcdr(v14);
    v14 = qcar(v14);
    if (equal(v15, v14)) goto v44;
    v14 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v14); }

v44:
    v14 = stack[-1];
    v15 = qcar(v14);
    v14 = stack[0];
    v14 = qcar(v14);
    fn = elt(env, 2); /* evequal */
    v14 = (*qfn2(fn))(qenv(fn), v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    if (v14 == nil) goto v8;
    v14 = stack[-1];
    v14 = qcdr(v14);
    v14 = qcdr(v14);
    stack[-1] = v14;
    v14 = stack[0];
    v14 = qcdr(v14);
    v14 = qcdr(v14);
    stack[0] = v14;
    goto v10;

v8:
    v14 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v14); }

v100:
    v14 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v14); }

v99:
    v14 = stack[0];
    v14 = (v14 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v14); }
/* error exit handlers */
v47:
    popv(3);
    return nil;
}



/* Code for gfplusn */

static Lisp_Object CC_gfplusn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfplusn");
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
    v17 = stack[-1];
    v17 = qcar(v17);
    if (!consp(v17)) goto v36;
    v17 = stack[-1];
    v47 = qcar(v17);
    v17 = stack[0];
    v17 = qcar(v17);
    fn = elt(env, 1); /* plus!: */
    stack[-2] = (*qfn2(fn))(qenv(fn), v47, v17);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v17 = stack[-1];
    v47 = qcdr(v17);
    v17 = stack[0];
    v17 = qcdr(v17);
    fn = elt(env, 1); /* plus!: */
    v17 = (*qfn2(fn))(qenv(fn), v47, v17);
    nil = C_nil;
    if (exception_pending()) goto v79;
    {
        Lisp_Object v18 = stack[-2];
        popv(4);
        return cons(v18, v17);
    }

v36:
    v17 = stack[-1];
    v47 = qcar(v17);
    v17 = stack[0];
    v17 = qcar(v17);
    stack[-2] = plus2(v47, v17);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v17 = stack[-1];
    v47 = qcdr(v17);
    v17 = stack[0];
    v17 = qcdr(v17);
    v17 = plus2(v47, v17);
    nil = C_nil;
    if (exception_pending()) goto v79;
    {
        Lisp_Object v78 = stack[-2];
        popv(4);
        return cons(v78, v17);
    }
/* error exit handlers */
v79:
    popv(4);
    return nil;
}



/* Code for harmonicp */

static Lisp_Object CC_harmonicp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v105;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for harmonicp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */
    v105 = elt(env, 1); /* fourier!-angle */
    return get(v31, v105);
}



/* Code for mo_lcm */

static Lisp_Object CC_mo_lcm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_lcm");
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
    v76 = v1;
    v108 = v0;
/* end of prologue */
    stack[-2] = nil;
    v108 = qcar(v108);
    stack[-1] = v108;
    v108 = v76;
    v108 = qcar(v108);
    stack[0] = v108;
    goto v12;

v12:
    v108 = stack[-1];
    if (v108 == nil) goto v6;
    v108 = stack[0];
    if (v108 == nil) goto v6;
    v108 = stack[-1];
    v76 = qcar(v108);
    v108 = stack[0];
    v108 = qcar(v108);
    if (((int32_t)(v76)) > ((int32_t)(v108))) goto v40;
    v108 = stack[0];
    v108 = qcar(v108);
    v76 = v108;
    goto v38;

v38:
    v108 = stack[-2];
    v108 = cons(v76, v108);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    stack[-2] = v108;
    v108 = stack[-1];
    v108 = qcdr(v108);
    stack[-1] = v108;
    v108 = stack[0];
    v108 = qcdr(v108);
    stack[0] = v108;
    goto v12;

v40:
    v108 = stack[-1];
    v108 = qcar(v108);
    v76 = v108;
    goto v38;

v6:
    v108 = stack[-2];
    v76 = Lnreverse(nil, v108);
    env = stack[-3];
    v108 = stack[-1];
    if (v108 == nil) goto v79;
    v108 = stack[-1];
    goto v110;

v110:
    v108 = Lappend(nil, v76, v108);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    stack[-2] = v108;
    v108 = stack[-2];
    fn = elt(env, 2); /* mo!=shorten */
    stack[0] = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    v108 = stack[-2];
    fn = elt(env, 3); /* mo!=deglist */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v109;
    {
        Lisp_Object v111 = stack[0];
        popv(4);
        return cons(v111, v108);
    }

v79:
    v108 = stack[0];
    goto v110;
/* error exit handlers */
v109:
    popv(4);
    return nil;
}



/* Code for !*a2f */

static Lisp_Object CC_Ha2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *a2f");
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
    fn = elt(env, 1); /* simp!* */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*q2f */
        return (*qfn1(fn))(qenv(fn), v10);
    }
/* error exit handlers */
v112:
    popv(1);
    return nil;
}



/* Code for termorder */

static Lisp_Object CC_termorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v78, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termorder");
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
    v18 = stack[-1];
    if (v18 == nil) goto v99;
    v18 = stack[-1];
    v18 = (Lisp_Object)zerop(v18);
    v18 = v18 ? lisp_true : nil;
    env = stack[-3];
    if (v18 == nil) goto v12;
    v18 = stack[0];
    v18 = (Lisp_Object)zerop(v18);
    v18 = v18 ? lisp_true : nil;
    env = stack[-3];
    if (!(v18 == nil)) goto v99;

v12:
    v18 = stack[-1];
    v18 = (Lisp_Object)zerop(v18);
    v18 = v18 ? lisp_true : nil;
    env = stack[-3];
    if (!(v18 == nil)) goto v99;
    v18 = stack[0];
    v18 = (Lisp_Object)zerop(v18);
    v18 = v18 ? lisp_true : nil;
    env = stack[-3];
    if (!(v18 == nil)) goto v99;

v99:
    v18 = stack[-1];
    fn = elt(env, 1); /* listsum */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-3];
    stack[-2] = v18;
    v18 = stack[0];
    fn = elt(env, 1); /* listsum */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-3];
    v113 = v18;
    v78 = stack[-2];
    v18 = v113;
    if (equal(v78, v18)) goto v26;
    v18 = stack[-2];
    v78 = v113;
    v18 = (Lisp_Object)lessp2(v18, v78);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v18 = v18 ? lisp_true : nil;
    if (v18 == nil) goto v115;
    v18 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v18); }

v115:
    v18 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v18); }

v26:
    v78 = stack[-1];
    v18 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* termorder1 */
        return (*qfn2(fn))(qenv(fn), v78, v18);
    }
/* error exit handlers */
v114:
    popv(4);
    return nil;
}



/* Code for triplesetprolongedby */

static Lisp_Object CC_triplesetprolongedby(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v118;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for triplesetprolongedby");
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
    v106 = v0;
/* end of prologue */
    v118 = v106;
    v106 = (Lisp_Object)49; /* 3 */
    v106 = *(Lisp_Object *)((char *)v118 + (CELL-TAG_VECTOR) + ((int32_t)v106/(16/CELL)));
    stack[-2] = v106;
    goto v36;

v36:
    v106 = stack[-2];
    v106 = qcar(v106);
    if (v106 == nil) goto v13;
    v106 = stack[-2];
    v118 = qcar(v106);
    v106 = stack[-1];
    v106 = (Lisp_Object)greaterp2(v118, v106);
    nil = C_nil;
    if (exception_pending()) goto v119;
    v106 = v106 ? lisp_true : nil;
    env = stack[-3];
    if (v106 == nil) goto v13;
    v106 = stack[-2];
    v106 = qcdr(v106);
    stack[-2] = v106;
    goto v36;

v13:
    v106 = stack[-2];
    v106 = qcar(v106);
    if (v106 == nil) goto v15;
    v106 = stack[-2];
    v118 = qcar(v106);
    v106 = stack[-1];
    if (!(equal(v118, v106))) goto v15;

v44:
    v106 = nil;
    { popv(4); return onevalue(v106); }

v15:
    stack[0] = stack[-2];
    v106 = stack[-2];
    v118 = qcar(v106);
    v106 = stack[-2];
    v106 = qcdr(v106);
    v106 = cons(v118, v106);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    v118 = Lrplacd(nil, stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    v106 = stack[-1];
    v106 = Lrplaca(nil, v118, v106);
    nil = C_nil;
    if (exception_pending()) goto v119;
    goto v44;
/* error exit handlers */
v119:
    popv(4);
    return nil;
}



/* Code for wupseudodivide */

static Lisp_Object MS_CDECL CC_wupseudodivide(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "wupseudodivide");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wupseudodivide");
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
    stack[-1] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v141 = stack[-4];
    stack[0] = v141;
    v141 = stack[-1];
    v141 = ncons(v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    fn = elt(env, 2); /* setkorder */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    stack[-5] = v141;
    v141 = stack[-4];
    fn = elt(env, 3); /* reorder */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    stack[-4] = v141;
    v141 = stack[-4];
    fn = elt(env, 4); /* wuconstantp */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    if (!(v141 == nil)) goto v28;
    v141 = stack[-4];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v142 = qcar(v141);
    v141 = stack[-1];
    if (!(equal(v142, v141))) goto v28;
    v141 = stack[-3];
    fn = elt(env, 3); /* reorder */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    stack[-3] = v141;
    v141 = stack[-3];
    fn = elt(env, 4); /* wuconstantp */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    if (!(v141 == nil)) goto v79;
    v141 = stack[-3];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v142 = qcar(v141);
    v141 = stack[-1];
    if (!(equal(v142, v141))) goto v79;
    v141 = stack[-4];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v141 = qcdr(v141);
    stack[-2] = v141;
    v141 = stack[-3];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v141 = qcdr(v141);
    stack[-1] = v141;
    v142 = stack[-2];
    v141 = stack[-1];
    v141 = difference2(v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v142 = add1(v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v141 = (Lisp_Object)1; /* 0 */
    v141 = (Lisp_Object)lessp2(v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    v141 = v141 ? lisp_true : nil;
    env = stack[-6];
    if (v141 == nil) goto v144;
    v141 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v142 = qvalue(elt(env, 1)); /* nil */
    v141 = stack[0];
    popv(7);
    return cons(v142, v141);

v144:
    v141 = stack[-3];
    v141 = qcar(v141);
    v141 = qcdr(v141);
    stack[0] = v141;
    v142 = stack[-2];
    v141 = stack[-1];
    v141 = difference2(v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v141 = add1(v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    fn = elt(env, 5); /* exptf */
    v141 = (*qfn2(fn))(qenv(fn), stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    stack[0] = v141;
    v142 = stack[0];
    v141 = stack[-4];
    fn = elt(env, 6); /* multf */
    v142 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v141 = stack[-3];
    fn = elt(env, 7); /* qremf */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    stack[-1] = v141;
    v142 = stack[0];
    v141 = stack[-1];
    v141 = qcdr(v141);
    fn = elt(env, 8); /* gcdf!* */
    v142 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v141 = stack[-1];
    v141 = qcar(v141);
    fn = elt(env, 8); /* gcdf!* */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    stack[-2] = v141;
    v141 = stack[-1];
    v142 = qcar(v141);
    v141 = stack[-2];
    fn = elt(env, 9); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v141 = stack[-1];
    v142 = qcdr(v141);
    v141 = stack[-2];
    fn = elt(env, 9); /* quotf */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v141 = cons(stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    stack[-1] = v141;
    v141 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v141 = stack[-1];
    v141 = qcar(v141);
    fn = elt(env, 3); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v141 = stack[-1];
    v141 = qcdr(v141);
    fn = elt(env, 3); /* reorder */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    {
        Lisp_Object v145 = stack[0];
        popv(7);
        return cons(v145, v141);
    }

v79:
    stack[-1] = stack[-4];
    stack[0] = stack[-3];
    v141 = stack[-4];
    v141 = qcar(v141);
    v142 = qcdr(v141);
    v141 = stack[-3];
    fn = elt(env, 8); /* gcdf!* */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    fn = elt(env, 9); /* quotf */
    v141 = (*qfn2(fn))(qenv(fn), stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    fn = elt(env, 6); /* multf */
    v141 = (*qfn2(fn))(qenv(fn), stack[-1], v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    stack[-4] = v141;
    v141 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v141 = stack[-4];
    fn = elt(env, 3); /* reorder */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    popv(7);
    return ncons(v141);

v28:
    v141 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v142 = qvalue(elt(env, 1)); /* nil */
    v141 = stack[0];
    popv(7);
    return cons(v142, v141);
/* error exit handlers */
v143:
    popv(7);
    return nil;
}



/* Code for qqe_arg!-check!-lb!-rb */

static Lisp_Object CC_qqe_argKcheckKlbKrb(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_arg-check-lb-rb");
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
    v98 = stack[0];
    v98 = qcdr(v98);
    v98 = qcar(v98);
    v48 = v98;
    v98 = stack[0];
    v98 = qcdr(v98);
    v98 = qcdr(v98);
    v98 = qcar(v98);
    stack[-1] = v98;
    v98 = v48;
    fn = elt(env, 3); /* qqe_arg!-check!-b */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-2];
    if (!(v98 == nil)) goto v12;
    fn = elt(env, 4); /* qqe_arg!-check!-marked!-ids!-rollback */
    v98 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-2];
    v48 = stack[0];
    v98 = elt(env, 1); /* "type conflict: arguments don't fit
             binary op with basic type args" */
    fn = elt(env, 5); /* typerr */
    v98 = (*qfn2(fn))(qenv(fn), v48, v98);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-2];
    goto v12;

v12:
    v98 = stack[-1];
    fn = elt(env, 3); /* qqe_arg!-check!-b */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-2];
    if (!(v98 == nil)) goto v33;
    fn = elt(env, 4); /* qqe_arg!-check!-marked!-ids!-rollback */
    v98 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-2];
    v48 = stack[0];
    v98 = elt(env, 1); /* "type conflict: arguments don't fit
             binary op with basic type args" */
    fn = elt(env, 5); /* typerr */
    v98 = (*qfn2(fn))(qenv(fn), v48, v98);
    nil = C_nil;
    if (exception_pending()) goto v107;
    goto v33;

v33:
    v98 = nil;
    { popv(3); return onevalue(v98); }
/* error exit handlers */
v107:
    popv(3);
    return nil;
}



/* Code for cl_smsimpl!-junct */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v157, v158, v128, v159, v160, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_smsimpl-junct");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_smsimpl-junct");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v3;
    stack[-6] = v2;
    stack[0] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    v156 = qvalue(elt(env, 1)); /* !*rlsism */
    if (v156 == nil) goto v19;
    v156 = stack[-6];
    fn = elt(env, 5); /* rl_smcpknowl */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-9];
    stack[-2] = v156;
    v158 = elt(env, 3); /* false */
    v157 = stack[-7];
    v156 = elt(env, 4); /* and */
    v156 = (v157 == v156 ? lisp_true : nil);
    fn = elt(env, 6); /* cl_cflip */
    v156 = (*qfn2(fn))(qenv(fn), v158, v156);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-9];
    stack[-8] = v156;
    v156 = stack[0];
    stack[-1] = v156;
    goto v46;

v46:
    v156 = stack[-1];
    if (v156 == nil) goto v162;
    v156 = stack[-1];
    v156 = qcar(v156);
    stack[0] = v156;
    v156 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-9];
    if (v156 == nil) goto v117;
    v157 = stack[0];
    v156 = stack[-7];
    fn = elt(env, 8); /* cl_simplat */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-9];
    goto v17;

v17:
    stack[0] = v156;
    v156 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-9];
    if (v156 == nil) goto v163;
    v157 = stack[0];
    v156 = stack[-4];
    v156 = cons(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-9];
    stack[-4] = v156;
    goto v118;

v118:
    v156 = stack[-1];
    v156 = qcdr(v156);
    stack[-1] = v156;
    goto v46;

v163:
    v157 = stack[0];
    v156 = stack[-3];
    v156 = cons(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-9];
    stack[-3] = v156;
    goto v118;

v117:
    v156 = stack[0];
    goto v17;

v162:
    v128 = stack[-7];
    v158 = stack[-4];
    v157 = stack[-2];
    v156 = stack[-5];
    fn = elt(env, 9); /* rl_smupdknowl */
    v156 = (*qfnn(fn))(qenv(fn), 4, v128, v158, v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-9];
    stack[-2] = v156;
    v157 = stack[-2];
    v156 = elt(env, 3); /* false */
    if (v157 == v156) goto v136;
    v161 = stack[-7];
    v160 = stack[-4];
    v156 = stack[-3];
    v159 = Lnreverse(nil, v156);
    env = stack[-9];
    v128 = stack[-6];
    v158 = stack[-2];
    v157 = stack[-5];
    v156 = stack[-8];
    {
        popv(10);
        fn = elt(env, 10); /* cl_smsimpl!-junct1 */
        return (*qfnn(fn))(qenv(fn), 7, v161, v160, v159, v128, v158, v157, v156);
    }

v136:
    v156 = stack[-8];
    popv(10);
    return ncons(v156);

v19:
    v128 = stack[0];
    v158 = stack[-5];
    v157 = stack[-7];
    v156 = qvalue(elt(env, 2)); /* nil */
    {
        popv(10);
        fn = elt(env, 11); /* cl_gand!-col */
        return (*qfnn(fn))(qenv(fn), 4, v128, v158, v157, v156);
    }
/* error exit handlers */
v96:
    popv(10);
    return nil;
}



/* Code for embed!-null!-fn */

static Lisp_Object CC_embedKnullKfn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v165, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for embed-null-fn");
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
    v165 = v0;
/* end of prologue */
    v162 = v165;
    if (!consp(v162)) { popv(5); return onevalue(v165); }
    v162 = v165;
    stack[-3] = v162;
    goto v13;

v13:
    v162 = stack[-3];
    if (v162 == nil) goto v27;
    v162 = stack[-3];
    v162 = qcar(v162);
    v166 = v162;
    v162 = v166;
    if (!consp(v162)) goto v22;
    v162 = v166;
    v165 = qcar(v162);
    v162 = elt(env, 2); /* null!-fn */
    if (v165 == v162) goto v42;
    v162 = v166;
    v162 = CC_embedKnullKfn(env, v162);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    goto v23;

v23:
    stack[-2] = v162;
    v162 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v162 = (*qfn1(fn))(qenv(fn), v162);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    stack[-1] = v162;
    v162 = stack[-3];
    v162 = qcdr(v162);
    stack[-3] = v162;
    v162 = stack[-1];
    if (!consp(v162)) goto v13;
    else goto v36;

v36:
    v162 = stack[-3];
    if (v162 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v162 = stack[-3];
    v162 = qcar(v162);
    v166 = v162;
    v162 = v166;
    if (!consp(v162)) goto v106;
    v162 = v166;
    v165 = qcar(v162);
    v162 = elt(env, 2); /* null!-fn */
    if (v165 == v162) goto v119;
    v162 = v166;
    v162 = CC_embedKnullKfn(env, v162);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    goto v113;

v113:
    v162 = Lrplacd(nil, stack[0], v162);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    v162 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v162 = (*qfn1(fn))(qenv(fn), v162);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    stack[-1] = v162;
    v162 = stack[-3];
    v162 = qcdr(v162);
    stack[-3] = v162;
    goto v36;

v119:
    v162 = v166;
    v162 = qcdr(v162);
    v162 = CC_embedKnullKfn(env, v162);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    goto v113;

v106:
    v162 = v166;
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    goto v113;

v42:
    v162 = v166;
    v162 = qcdr(v162);
    v162 = CC_embedKnullKfn(env, v162);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    goto v23;

v22:
    v162 = v166;
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    goto v23;

v27:
    v162 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v162); }
/* error exit handlers */
v167:
    popv(5);
    return nil;
}



/* Code for xlcm */

static Lisp_Object CC_xlcm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xlcm");
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
    goto v112;

v112:
    v135 = stack[-1];
    if (v135 == nil) goto v100;
    v135 = stack[-1];
    v171 = qcar(v135);
    v135 = (Lisp_Object)17; /* 1 */
    v135 = (v171 == v135 ? lisp_true : nil);
    goto v30;

v30:
    if (v135 == nil) goto v31;
    v171 = stack[-2];
    v135 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v171, v135);
    }

v31:
    v135 = stack[0];
    if (v135 == nil) goto v45;
    v135 = stack[0];
    v171 = qcar(v135);
    v135 = (Lisp_Object)17; /* 1 */
    v135 = (v171 == v135 ? lisp_true : nil);
    goto v44;

v44:
    if (v135 == nil) goto v139;
    v171 = stack[-2];
    v135 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v171, v135);
    }

v139:
    v135 = stack[-1];
    v171 = qcar(v135);
    v135 = stack[0];
    v135 = qcar(v135);
    if (v171 == v135) goto v114;
    v135 = stack[-1];
    v171 = qcar(v135);
    v135 = stack[0];
    v135 = qcar(v135);
    fn = elt(env, 3); /* factorordp */
    v135 = (*qfn2(fn))(qenv(fn), v171, v135);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    if (v135 == nil) goto v167;
    v135 = stack[-1];
    v171 = qcar(v135);
    v135 = stack[-2];
    v135 = cons(v171, v135);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    stack[-2] = v135;
    v135 = stack[-1];
    v135 = qcdr(v135);
    stack[-1] = v135;
    goto v112;

v167:
    v135 = stack[0];
    v171 = qcar(v135);
    v135 = stack[-2];
    v135 = cons(v171, v135);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    stack[-2] = v135;
    v135 = stack[0];
    v135 = qcdr(v135);
    stack[0] = v135;
    goto v112;

v114:
    v135 = stack[-1];
    v171 = qcar(v135);
    v135 = stack[-2];
    v135 = cons(v171, v135);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    stack[-2] = v135;
    v135 = stack[-1];
    v135 = qcdr(v135);
    stack[-1] = v135;
    v135 = stack[0];
    v135 = qcdr(v135);
    stack[0] = v135;
    goto v112;

v45:
    v135 = qvalue(elt(env, 1)); /* t */
    goto v44;

v100:
    v135 = qvalue(elt(env, 1)); /* t */
    goto v30;
/* error exit handlers */
v151:
    popv(4);
    return nil;
}



/* Code for aceq */

static Lisp_Object CC_aceq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v98, v48, v25;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aceq");
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
    v98 = v1;
    v48 = v0;
/* end of prologue */

v112:
    v49 = v48;
    if (v49 == nil) goto v104;
    v49 = v98;
    if (v49 == nil) goto v12;
    v49 = v48;
    v25 = qcar(v49);
    v49 = v98;
    v49 = Lmember(nil, v25, v49);
    if (v49 == nil) goto v4;
    v49 = v48;
    v49 = qcdr(v49);
    stack[0] = v49;
    v49 = v48;
    v49 = qcar(v49);
    v49 = Ldelete(nil, v49, v98);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v98 = v49;
    v49 = stack[0];
    v48 = v49;
    goto v112;

v4:
    v49 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v49); }

v12:
    v49 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v49); }

v104:
    v49 = v98;
    v49 = (v49 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v49); }
/* error exit handlers */
v107:
    popv(2);
    return nil;
}



/* Code for flatindl */

static Lisp_Object CC_flatindl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v49;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flatindl");
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
    goto v112;

v112:
    v102 = stack[0];
    if (v102 == nil) goto v83;
    v102 = stack[0];
    v49 = qcar(v102);
    v102 = stack[-1];
    v102 = cons(v49, v102);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-2];
    stack[-1] = v102;
    v102 = stack[0];
    v102 = qcdr(v102);
    stack[0] = v102;
    goto v112;

v83:
    v102 = qvalue(elt(env, 1)); /* nil */
    v49 = v102;
    goto v99;

v99:
    v102 = stack[-1];
    if (v102 == nil) { popv(3); return onevalue(v49); }
    v102 = stack[-1];
    v102 = qcar(v102);
    v102 = Lappend(nil, v102, v49);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-2];
    v49 = v102;
    v102 = stack[-1];
    v102 = qcdr(v102);
    stack[-1] = v102;
    goto v99;
/* error exit handlers */
v25:
    popv(3);
    return nil;
}



/* Code for subcare */

static Lisp_Object MS_CDECL CC_subcare(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v77, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subcare");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subcare");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v83;

v83:
    v76 = stack[0];
    if (v76 == nil) goto v31;
    v77 = stack[-2];
    v76 = stack[0];
    if (equal(v77, v76)) goto v20;
    v76 = stack[0];
    if (!consp(v76)) goto v140;
    v76 = stack[0];
    v77 = qcar(v76);
    v76 = elt(env, 2); /* subfunc */
    v76 = get(v77, v76);
    env = stack[-4];
    goto v24;

v24:
    if (v76 == nil) goto v79;
    v77 = stack[-3];
    v76 = stack[0];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v77, v76);
    }

v79:
    v119 = stack[-2];
    v77 = stack[-1];
    v76 = stack[0];
    v76 = qcar(v76);
    v77 = CC_subcare(env, 3, v119, v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    v76 = stack[-3];
    v76 = cons(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    stack[-3] = v76;
    v76 = stack[0];
    v76 = qcdr(v76);
    stack[0] = v76;
    goto v83;

v140:
    v76 = qvalue(elt(env, 1)); /* t */
    goto v24;

v20:
    v77 = stack[-3];
    v76 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v77, v76);
    }

v31:
    v76 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v76);
    }
/* error exit handlers */
v138:
    popv(5);
    return nil;
}



/* Code for red_topredbe */

static Lisp_Object CC_red_topredbe(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_topredbe");
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
    v87 = stack[-1];
    fn = elt(env, 4); /* bas_dpoly */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    if (v87 == nil) goto v104;
    v87 = stack[-2];
    v87 = (v87 == nil ? lisp_true : nil);
    goto v99;

v99:
    if (!(v87 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    fn = elt(env, 5); /* cali_trace */
    v172 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v87 = (Lisp_Object)1265; /* 79 */
    v87 = (Lisp_Object)greaterp2(v172, v87);
    nil = C_nil;
    if (exception_pending()) goto v77;
    v87 = v87 ? lisp_true : nil;
    env = stack[-4];
    if (v87 == nil) goto v98;
    v87 = elt(env, 2); /* " reduce " */
    v87 = Lprinc(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v87 = stack[-1];
    fn = elt(env, 4); /* bas_dpoly */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    fn = elt(env, 6); /* dp_print */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    goto v98;

v98:
    v87 = stack[-1];
    fn = elt(env, 4); /* bas_dpoly */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v172 = v87;
    if (v87 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    stack[-3] = stack[-2];
    v87 = v172;
    fn = elt(env, 7); /* dp_lmon */
    stack[0] = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v87 = stack[-1];
    fn = elt(env, 8); /* bas_dpecart */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    fn = elt(env, 9); /* red_divtestbe */
    v172 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v87 = v172;
    if (v172 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v172 = stack[-1];
    fn = elt(env, 10); /* red_subst */
    v87 = (*qfn2(fn))(qenv(fn), v172, v87);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    stack[-1] = v87;
    goto v98;

v104:
    v87 = qvalue(elt(env, 1)); /* t */
    goto v99;
/* error exit handlers */
v77:
    popv(5);
    return nil;
}



/* Code for simp!-prop2 */

static Lisp_Object CC_simpKprop2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop2");
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
    v148 = qvalue(elt(env, 1)); /* propvars!* */
    stack[-1] = v148;
    goto v12;

v12:
    v148 = stack[-1];
    if (v148 == nil) goto v100;
    v148 = stack[-1];
    v148 = qcar(v148);
    stack[0] = v148;
    v148 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v148;
    goto v23;

v23:
    v148 = stack[-5];
    if (v148 == nil) goto v38;
    v148 = stack[-5];
    v148 = qcar(v148);
    stack[-3] = v148;
    v148 = stack[-5];
    v148 = qcdr(v148);
    stack[-5] = v148;
    v149 = elt(env, 3); /* prop!* */
    v148 = stack[0];
    v148 = list2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-4] = v148;
    v149 = elt(env, 4); /* not_prop!* */
    v148 = stack[0];
    v148 = list2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    v62 = v148;
    v149 = stack[-4];
    v148 = stack[-3];
    v148 = Lmember(nil, v149, v148);
    if (!(v148 == nil)) goto v73;
    v148 = v62;
    v149 = stack[-4];
    v62 = v149;
    stack[-4] = v148;
    goto v73;

v73:
    v149 = stack[-4];
    v148 = stack[-3];
    v148 = Lsubst(nil, 3, v62, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-6] = v148;
    v149 = stack[-3];
    v148 = stack[-2];
    v148 = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-2] = v148;
    v149 = stack[-6];
    v148 = stack[-5];
    v148 = Lmember(nil, v149, v148);
    stack[-6] = v148;
    if (v148 == nil) goto v23;
    v148 = stack[-6];
    if (v148 == nil) goto v68;
    v148 = stack[-6];
    v149 = qcar(v148);
    v148 = stack[-5];
    v148 = Ldelete(nil, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-5] = v148;
    v148 = stack[-6];
    v149 = qcar(v148);
    v148 = stack[-2];
    v148 = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-2] = v148;
    goto v68;

v68:
    v149 = stack[-4];
    v148 = stack[-3];
    v148 = Ldelete(nil, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-3] = v148;
    v148 = stack[-3];
    v149 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    v148 = stack[-2];
    fn = elt(env, 5); /* union */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-2] = v148;
    goto v23;

v38:
    v148 = stack[-2];
    stack[-5] = v148;
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    goto v12;

v100:
    v148 = stack[-5];
    {
        popv(8);
        fn = elt(env, 6); /* simp!-prop!-condense */
        return (*qfn1(fn))(qenv(fn), v148);
    }
/* error exit handlers */
v128:
    popv(8);
    return nil;
}



/* Code for !*di2q */

static Lisp_Object CC_Hdi2q(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v118, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *di2q");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v106 = v2;
    v118 = v1;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v106; /* varlist */
    v106 = v118;
    stack[-3] = v106;
    v106 = stack[-3];
    if (v106 == nil) goto v11;
    v106 = stack[-3];
    v106 = qcar(v106);
    v118 = v106;
    v108 = qcar(v118);
    v118 = qcdr(v106);
    v106 = (Lisp_Object)17; /* 1 */
    v106 = list2star(v108, v118, v106);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    v106 = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    stack[-1] = v106;
    stack[-2] = v106;
    goto v37;

v37:
    v106 = stack[-3];
    v106 = qcdr(v106);
    stack[-3] = v106;
    v106 = stack[-3];
    if (v106 == nil) goto v26;
    stack[0] = stack[-1];
    v106 = stack[-3];
    v106 = qcar(v106);
    v118 = v106;
    v108 = qcar(v118);
    v118 = qcdr(v106);
    v106 = (Lisp_Object)17; /* 1 */
    v106 = list2star(v108, v118, v106);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    v106 = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    v106 = Lrplacd(nil, stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    v106 = stack[-1];
    v106 = qcdr(v106);
    stack[-1] = v106;
    goto v37;

v26:
    v106 = stack[-2];
    v118 = v106;
    goto v105;

v105:
    v106 = qvalue(elt(env, 1)); /* varlist */
    fn = elt(env, 3); /* !*di2q0 */
    v106 = (*qfn2(fn))(qenv(fn), v118, v106);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    { popv(6); return onevalue(v106); }

v11:
    v106 = qvalue(elt(env, 2)); /* nil */
    v118 = v106;
    goto v105;
/* error exit handlers */
v111:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    popv(6);
    return nil;
}



/* Code for nonlnr */

static Lisp_Object CC_nonlnr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonlnr");
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

v181:
    v69 = stack[-1];
    if (!consp(v69)) goto v104;
    v69 = stack[-1];
    v69 = qcar(v69);
    v69 = (consp(v69) ? nil : lisp_true);
    goto v99;

v99:
    if (v69 == nil) goto v28;
    v69 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v69); }

v28:
    v69 = stack[-1];
    v69 = qcar(v69);
    v69 = qcar(v69);
    v70 = qcar(v69);
    v69 = stack[0];
    v69 = Lmember(nil, v70, v69);
    if (v69 == nil) goto v106;
    v69 = stack[-1];
    v69 = qcar(v69);
    v69 = qcar(v69);
    v70 = qcdr(v69);
    v69 = (Lisp_Object)17; /* 1 */
    v69 = (Lisp_Object)greaterp2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v69 = v69 ? lisp_true : nil;
    env = stack[-2];
    if (!(v69 == nil)) { popv(3); return onevalue(v69); }
    v69 = stack[-1];
    v69 = qcar(v69);
    v70 = qcdr(v69);
    v69 = stack[0];
    fn = elt(env, 3); /* freeofl */
    v69 = (*qfn2(fn))(qenv(fn), v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    if (v69 == nil) goto v26;
    v69 = stack[-1];
    v70 = qcdr(v69);
    v69 = stack[0];
    stack[-1] = v70;
    stack[0] = v69;
    goto v181;

v26:
    v69 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v69); }

v106:
    v69 = stack[-1];
    v69 = qcar(v69);
    v69 = qcar(v69);
    v70 = qcar(v69);
    v69 = stack[0];
    fn = elt(env, 3); /* freeofl */
    v69 = (*qfn2(fn))(qenv(fn), v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    if (v69 == nil) goto v117;
    v69 = stack[-1];
    v69 = qcar(v69);
    v70 = qcdr(v69);
    v69 = stack[0];
    v69 = CC_nonlnr(env, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    if (!(v69 == nil)) { popv(3); return onevalue(v69); }
    v69 = stack[-1];
    v70 = qcdr(v69);
    v69 = stack[0];
    stack[-1] = v70;
    stack[0] = v69;
    goto v181;

v117:
    v69 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v69); }

v104:
    v69 = qvalue(elt(env, 1)); /* t */
    goto v99;
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for tayexp!-max2 */

static Lisp_Object CC_tayexpKmax2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-max2");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v27 = stack[-1];
    v37 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v37 = (*qfn2(fn))(qenv(fn), v27, v37);
    nil = C_nil;
    if (exception_pending()) goto v11;
    if (v37 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v11:
    popv(2);
    return nil;
}



/* Code for cl_bnfsimpl */

static Lisp_Object CC_cl_bnfsimpl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_bnfsimpl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v1;
    v28 = v0;
/* end of prologue */
    v37 = qvalue(elt(env, 1)); /* !*rlbnfsac */
    if (v37 == nil) return onevalue(v28);
    v37 = v28;
    {
        fn = elt(env, 2); /* cl_sac */
        return (*qfn2(fn))(qenv(fn), v37, v27);
    }
}



/* Code for gb_buch!-ev_divides!? */

static Lisp_Object CC_gb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gb_buch-ev_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v1;
    v105 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v30, v105);
    }
}



/* Code for bc_fd */

static Lisp_Object CC_bc_fd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v105;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_fd");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */
    v105 = v31;
    v31 = (Lisp_Object)17; /* 1 */
    return cons(v105, v31);
}



/* Code for matrix_rows */

static Lisp_Object CC_matrix_rows(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrix_rows");
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
    v140 = stack[0];
    if (v140 == nil) goto v10;
    v140 = elt(env, 1); /* "<matrixrow>" */
    fn = elt(env, 5); /* printout */
    v140 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    v32 = qvalue(elt(env, 2)); /* indent */
    v140 = (Lisp_Object)49; /* 3 */
    v140 = plus2(v32, v140);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    qvalue(elt(env, 2)) = v140; /* indent */
    v140 = stack[0];
    v140 = qcar(v140);
    fn = elt(env, 6); /* row */
    v140 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    v32 = qvalue(elt(env, 2)); /* indent */
    v140 = (Lisp_Object)49; /* 3 */
    v140 = difference2(v32, v140);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    qvalue(elt(env, 2)) = v140; /* indent */
    v140 = elt(env, 3); /* "</matrixrow>" */
    fn = elt(env, 5); /* printout */
    v140 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    v140 = stack[0];
    v140 = qcdr(v140);
    v140 = CC_matrix_rows(env, v140);
    nil = C_nil;
    if (exception_pending()) goto v44;
    goto v10;

v10:
    v140 = nil;
    { popv(2); return onevalue(v140); }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for degreef */

static Lisp_Object CC_degreef(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degreef");
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
    v16 = stack[-1];
    if (!consp(v16)) goto v104;
    v16 = stack[-1];
    v16 = qcar(v16);
    v16 = (consp(v16) ? nil : lisp_true);
    goto v99;

v99:
    if (v16 == nil) goto v28;
    v16 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v16); }

v28:
    v16 = stack[-1];
    v16 = qcar(v16);
    v16 = qcar(v16);
    v17 = qcar(v16);
    v16 = stack[0];
    if (v17 == v16) goto v37;
    v16 = stack[-1];
    v16 = qcar(v16);
    v17 = qcdr(v16);
    v16 = stack[0];
    stack[-2] = CC_degreef(env, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v16 = stack[-1];
    v17 = qcdr(v16);
    v16 = stack[0];
    v16 = CC_degreef(env, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    {
        Lisp_Object v79 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* max */
        return (*qfn2(fn))(qenv(fn), v79, v16);
    }

v37:
    v16 = stack[-1];
    v16 = qcar(v16);
    v16 = qcar(v16);
    v16 = qcdr(v16);
    { popv(4); return onevalue(v16); }

v104:
    v16 = qvalue(elt(env, 1)); /* t */
    goto v99;
/* error exit handlers */
v116:
    popv(4);
    return nil;
}



/* Code for delyzz */

static Lisp_Object CC_delyzz(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v102, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delyzz");
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
    v49 = nil;
    goto v105;

v105:
    v102 = stack[-1];
    v5 = stack[0];
    v5 = qcar(v5);
    v5 = qcar(v5);
    if (equal(v102, v5)) goto v28;
    v5 = stack[0];
    v5 = qcar(v5);
    v102 = v49;
    v5 = cons(v5, v102);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-2];
    v49 = v5;
    v5 = stack[0];
    v5 = qcdr(v5);
    stack[0] = v5;
    goto v105;

v28:
    v102 = v49;
    v5 = stack[0];
    v5 = qcdr(v5);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v102, v5);
    }
/* error exit handlers */
v25:
    popv(3);
    return nil;
}



/* Code for evgradlexcomp */

static Lisp_Object CC_evgradlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evgradlexcomp");
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

v10:
    v76 = stack[-2];
    if (v76 == nil) goto v99;
    v76 = stack[-1];
    if (v76 == nil) goto v30;
    v76 = stack[-2];
    v77 = qcar(v76);
    v76 = stack[-1];
    v76 = qcar(v76);
    v76 = Leqn(nil, v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-4];
    if (v76 == nil) goto v40;
    v76 = stack[-2];
    v76 = qcdr(v76);
    stack[-2] = v76;
    v76 = stack[-1];
    v76 = qcdr(v76);
    stack[-1] = v76;
    goto v10;

v40:
    v76 = stack[-2];
    fn = elt(env, 2); /* evtdeg */
    stack[0] = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-4];
    v76 = stack[-1];
    fn = elt(env, 2); /* evtdeg */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v76;
    v77 = stack[-3];
    v76 = stack[0];
    v76 = Leqn(nil, v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v177;
    if (v76 == nil) goto v113;
    v76 = stack[-2];
    v77 = qcar(v76);
    v76 = stack[-1];
    v76 = qcar(v76);
    if (((int32_t)(v77)) > ((int32_t)(v76))) goto v8;
    v76 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v76); }

v8:
    v76 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v76); }

v113:
    v77 = stack[-3];
    v76 = stack[0];
    if (((int32_t)(v77)) > ((int32_t)(v76))) goto v18;
    v76 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v76); }

v18:
    v76 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v76); }

v30:
    v76 = elt(env, 1); /* (0) */
    stack[-1] = v76;
    goto v10;

v99:
    v76 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v76); }
/* error exit handlers */
v177:
    popv(5);
    return nil;
}



/* Code for xriterion_1 */

static Lisp_Object MS_CDECL CC_xriterion_1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v184, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xriterion_1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xriterion_1");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v181:
    v94 = stack[-1];
    if (v94 == nil) goto v112;
    v94 = stack[-2];
    v94 = qcdr(v94);
    v184 = qcar(v94);
    v94 = elt(env, 2); /* spoly_pair */
    if (v184 == v94) goto v103;
    v94 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v94); }

v103:
    v94 = stack[-1];
    v94 = qcar(v94);
    stack[-3] = v94;
    v184 = stack[-3];
    v94 = stack[-2];
    v94 = qcdr(v94);
    v94 = qcdr(v94);
    v94 = qcar(v94);
    if (equal(v184, v94)) goto v186;
    v184 = stack[-3];
    v94 = stack[-2];
    v94 = qcdr(v94);
    v94 = qcdr(v94);
    v94 = qcdr(v94);
    v94 = qcar(v94);
    if (equal(v184, v94)) goto v59;
    v94 = stack[-3];
    fn = elt(env, 7); /* xval */
    v184 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v94 = stack[-2];
    v94 = qcar(v94);
    fn = elt(env, 8); /* xdiv */
    v94 = (*qfn2(fn))(qenv(fn), v184, v94);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    if (v94 == nil) goto v15;
    v184 = stack[-3];
    v94 = stack[-2];
    v94 = qcdr(v94);
    v94 = qcdr(v94);
    v94 = qcar(v94);
    fn = elt(env, 9); /* make_spoly_pair */
    v94 = (*qfn2(fn))(qenv(fn), v184, v94);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v184 = v94;
    v94 = v184;
    if (v94 == nil) goto v188;
    v94 = stack[0];
    fn = elt(env, 10); /* find_item */
    v94 = (*qfn2(fn))(qenv(fn), v184, v94);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v94 = (v94 == nil ? lisp_true : nil);
    goto v164;

v164:
    if (v94 == nil) goto v172;
    v184 = stack[-3];
    v94 = stack[-2];
    v94 = qcdr(v94);
    v94 = qcdr(v94);
    v94 = qcdr(v94);
    v94 = qcar(v94);
    fn = elt(env, 9); /* make_spoly_pair */
    v94 = (*qfn2(fn))(qenv(fn), v184, v94);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v184 = v94;
    v94 = v184;
    if (v94 == nil) goto v92;
    v94 = stack[0];
    fn = elt(env, 10); /* find_item */
    v94 = (*qfn2(fn))(qenv(fn), v184, v94);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v94 = (v94 == nil ? lisp_true : nil);
    goto v175;

v175:
    if (v94 == nil) goto v69;
    v94 = qvalue(elt(env, 4)); /* !*trxideal */
    if (v94 == nil) goto v149;
    v94 = elt(env, 5); /* "criterion 1 hit" */
    fn = elt(env, 11); /* eval */
    v185 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v184 = qvalue(elt(env, 1)); /* nil */
    v94 = elt(env, 6); /* last */
    fn = elt(env, 12); /* assgnpri */
    v94 = (*qfnn(fn))(qenv(fn), 3, v185, v184, v94);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    goto v149;

v149:
    v94 = qvalue(elt(env, 3)); /* t */
    goto v39;

v39:
    if (!(v94 == nil)) { popv(5); return onevalue(v94); }
    v185 = stack[-2];
    v94 = stack[-1];
    v184 = qcdr(v94);
    v94 = stack[0];
    stack[-2] = v185;
    stack[-1] = v184;
    stack[0] = v94;
    goto v181;

v69:
    v94 = qvalue(elt(env, 1)); /* nil */
    goto v39;

v92:
    v94 = qvalue(elt(env, 3)); /* t */
    goto v175;

v172:
    v94 = qvalue(elt(env, 1)); /* nil */
    goto v39;

v188:
    v94 = qvalue(elt(env, 3)); /* t */
    goto v164;

v15:
    v94 = qvalue(elt(env, 1)); /* nil */
    goto v39;

v59:
    v94 = qvalue(elt(env, 1)); /* nil */
    goto v39;

v186:
    v94 = qvalue(elt(env, 1)); /* nil */
    goto v39;

v112:
    v94 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v94); }
/* error exit handlers */
v187:
    popv(5);
    return nil;
}



/* Code for fl2bf */

static Lisp_Object CC_fl2bf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fl2bf");
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
    v48 = v0;
/* end of prologue */
    fn = elt(env, 3); /* frexp */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    stack[-2] = v48;
    v48 = stack[-2];
    v48 = qcdr(v48);
    v25 = stack[-2];
    v25 = qcar(v25);
    stack[-2] = v25;
    stack[0] = v48;
    v25 = (Lisp_Object)33; /* 2 */
    v48 = qvalue(elt(env, 1)); /* !!nbfpd */
    v48 = Lexpt(nil, v25, v48);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v48 = times2(stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v48 = Ltruncate(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    stack[-1] = elt(env, 2); /* !:rd!: */
    stack[0] = v48;
    v25 = stack[-2];
    v48 = qvalue(elt(env, 1)); /* !!nbfpd */
    v48 = difference2(v25, v48);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v48 = list2star(stack[-1], stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v48);
    }
/* error exit handlers */
v46:
    popv(4);
    return nil;
}



/* Code for apply_e */

static Lisp_Object CC_apply_e(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for apply_e");
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
    v22 = v23;
    v23 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* apply */
    v22 = (*qfn2(fn))(qenv(fn), v22, v23);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[0];
    v23 = v22;
    v22 = integerp(v22);
    if (!(v22 == nil)) { popv(1); return onevalue(v23); }
    v23 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v23 == nil)) goto v28;
    v23 = elt(env, 3); /* "randpoly expons function must return an integer" 
*/
    fn = elt(env, 5); /* lprie */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[0];
    goto v28;

v28:
    v23 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v33;
    v23 = nil;
    { popv(1); return onevalue(v23); }
/* error exit handlers */
v33:
    popv(1);
    return nil;
}



/* Code for gpargp */

static Lisp_Object CC_gpargp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpargp");
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
    v12 = stack[0];
    v12 = Lstringp(nil, v12);
    env = stack[-1];
    if (!(v12 == nil)) { popv(2); return onevalue(v12); }
    v12 = stack[0];
    fn = elt(env, 1); /* gpexpp */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    if (!(v12 == nil)) { popv(2); return onevalue(v12); }
    v12 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* gplogexpp */
        return (*qfn1(fn))(qenv(fn), v12);
    }
/* error exit handlers */
v36:
    popv(2);
    return nil;
}



/* Code for getphystypeall */

static Lisp_Object CC_getphystypeall(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypeall");
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
    v102 = (Lisp_Object)1; /* 0 */
    v5 = stack[0];
    fn = elt(env, 3); /* deleteall */
    v5 = (*qfn2(fn))(qenv(fn), v102, v5);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    fn = elt(env, 4); /* collectphystype */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    v102 = v5;
    if (v5 == nil) goto v83;
    v5 = v102;
    v5 = qcdr(v5);
    if (v5 == nil) goto v43;
    stack[-1] = elt(env, 0); /* getphystypeall */
    v102 = elt(env, 2); /* "PHYSOP type mismatch in" */
    v5 = stack[0];
    v5 = list2(v102, v5);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    fn = elt(env, 5); /* rederr2 */
    v5 = (*qfn2(fn))(qenv(fn), stack[-1], v5);
    nil = C_nil;
    if (exception_pending()) goto v48;
    v5 = nil;
    { popv(3); return onevalue(v5); }

v43:
    v5 = v102;
    v5 = qcar(v5);
    { popv(3); return onevalue(v5); }

v83:
    v5 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v5); }
/* error exit handlers */
v48:
    popv(3);
    return nil;
}



/* Code for gvarlis1 */

static Lisp_Object CC_gvarlis1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gvarlis1");
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
    goto v83;

v83:
    v46 = stack[-1];
    if (v46 == nil) goto v99;
    v46 = stack[-1];
    v9 = qcar(v46);
    v46 = stack[0];
    fn = elt(env, 1); /* gvar1 */
    v9 = (*qfn2(fn))(qenv(fn), v9, v46);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-3];
    v46 = stack[-2];
    v46 = cons(v9, v46);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-3];
    stack[-2] = v46;
    v46 = stack[-1];
    v46 = qcdr(v46);
    stack[-1] = v46;
    goto v83;

v99:
    v46 = stack[0];
    v9 = v46;
    goto v104;

v104:
    v46 = stack[-2];
    if (v46 == nil) { popv(4); return onevalue(v9); }
    v46 = stack[-2];
    v46 = qcar(v46);
    fn = elt(env, 2); /* union */
    v46 = (*qfn2(fn))(qenv(fn), v46, v9);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-3];
    v9 = v46;
    v46 = stack[-2];
    v46 = qcdr(v46);
    stack[-2] = v46;
    goto v104;
/* error exit handlers */
v7:
    popv(4);
    return nil;
}



/* Code for general!-horner!-rule!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKhornerKruleKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v157, v158, v128, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "general-horner-rule-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-horner-rule-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push5(v34,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v34;
    stack[-3] = v3;
    stack[-4] = v2;
    v158 = v1;
    v128 = v0;
/* end of prologue */

v181:
    v156 = stack[-4];
    if (!consp(v156)) goto v36;
    v156 = stack[-4];
    v156 = qcar(v156);
    v156 = (consp(v156) ? nil : lisp_true);
    goto v13;

v13:
    if (v156 == nil) goto v23;
    v156 = qvalue(elt(env, 1)); /* t */
    goto v105;

v105:
    if (v156 == nil) goto v118;
    v156 = stack[-3];
    if (v156 == nil) goto v48;
    v156 = stack[-3];
    v156 = (Lisp_Object)zerop(v156);
    v156 = v156 ? lisp_true : nil;
    env = stack[-6];
    goto v98;

v98:
    if (!(v156 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[0] = v128;
    v156 = stack[-3];
    v157 = v158;
    fn = elt(env, 2); /* general!-expt!-mod!-p */
    v156 = (*qfn2(fn))(qenv(fn), v156, v157);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    fn = elt(env, 3); /* general!-times!-mod!-p */
    v156 = (*qfn2(fn))(qenv(fn), stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v128 = v156;
    v156 = stack[-4];
    v157 = v128;
    {
        popv(7);
        fn = elt(env, 4); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v156, v157);
    }

v48:
    v156 = qvalue(elt(env, 1)); /* t */
    goto v98;

v118:
    v156 = stack[-4];
    v156 = qcar(v156);
    v156 = qcar(v156);
    v156 = qcdr(v156);
    stack[-5] = v156;
    v156 = stack[-3];
    if (v156 == nil) goto v165;
    v156 = stack[-3];
    v156 = (Lisp_Object)zerop(v156);
    v156 = v156 ? lisp_true : nil;
    env = stack[-6];
    goto v162;

v162:
    if (v156 == nil) goto v136;
    v156 = stack[-4];
    v156 = qcar(v156);
    v156 = qcdr(v156);
    v128 = v156;
    goto v155;

v155:
    v158 = stack[-5];
    v156 = stack[-4];
    v159 = qcdr(v156);
    v157 = stack[-3];
    v156 = stack[-2];
    stack[-4] = v159;
    stack[-3] = v157;
    stack[-2] = v156;
    goto v181;

v136:
    v156 = stack[-4];
    v156 = qcar(v156);
    stack[-1] = qcdr(v156);
    stack[0] = v128;
    v157 = stack[-3];
    v156 = stack[-5];
    v156 = (Lisp_Object)(int32_t)((int32_t)v158 - (int32_t)v156 + TAG_FIXNUM);
    fn = elt(env, 2); /* general!-expt!-mod!-p */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    fn = elt(env, 3); /* general!-times!-mod!-p */
    v156 = (*qfn2(fn))(qenv(fn), stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    fn = elt(env, 4); /* general!-plus!-mod!-p */
    v156 = (*qfn2(fn))(qenv(fn), stack[-1], v156);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v128 = v156;
    goto v155;

v165:
    v156 = qvalue(elt(env, 1)); /* t */
    goto v162;

v23:
    v156 = stack[-4];
    v156 = qcar(v156);
    v156 = qcar(v156);
    v157 = qcar(v156);
    v156 = stack[-2];
    v156 = (equal(v157, v156) ? lisp_true : nil);
    v156 = (v156 == nil ? lisp_true : nil);
    goto v105;

v36:
    v156 = qvalue(elt(env, 1)); /* t */
    goto v13;
/* error exit handlers */
v59:
    popv(7);
    return nil;
}



/* Code for reduce!-eival!-powers */

static Lisp_Object CC_reduceKeivalKpowers(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v139, v115, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-eival-powers");
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
    v115 = v1;
    v116 = v0;
/* end of prologue */
    v47 = v115;
    if (!consp(v47)) goto v100;
    v47 = v115;
    v47 = qcar(v47);
    v47 = (consp(v47) ? nil : lisp_true);
    goto v30;

v30:
    if (v47 == nil) goto v20;
    v47 = qvalue(elt(env, 1)); /* t */
    goto v99;

v99:
    if (v47 == nil) goto v86;
    v139 = v115;
    v47 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v139, v47);

v86:
    stack[0] = v116;
    v139 = v115;
    v47 = (Lisp_Object)17; /* 1 */
    v47 = cons(v139, v47);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    {
        Lisp_Object v78 = stack[0];
        popv(2);
        fn = elt(env, 2); /* reduce!-eival!-powers1 */
        return (*qfn2(fn))(qenv(fn), v78, v47);
    }

v20:
    v47 = v115;
    v47 = qcar(v47);
    v47 = qcar(v47);
    v139 = qcar(v47);
    v47 = v116;
    v47 = qcar(v47);
    v47 = qcar(v47);
    v47 = (v139 == v47 ? lisp_true : nil);
    v47 = (v47 == nil ? lisp_true : nil);
    goto v99;

v100:
    v47 = qvalue(elt(env, 1)); /* t */
    goto v30;
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for sfto_pdecf */

static Lisp_Object CC_sfto_pdecf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_pdecf");
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
    stack[0] = v0;
/* end of prologue */
    v18 = stack[0];
    if (!consp(v18)) goto v100;
    v18 = stack[0];
    v18 = qcar(v18);
    v18 = (consp(v18) ? nil : lisp_true);
    goto v30;

v30:
    if (v18 == nil) goto v99;
    v78 = (Lisp_Object)17; /* 1 */
    v18 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v78, v18);

v99:
    v18 = stack[0];
    fn = elt(env, 2); /* sfto_ucontentf */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    stack[-1] = v18;
    v18 = stack[-1];
    v18 = CC_sfto_pdecf(env, v18);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    stack[-2] = v18;
    v78 = stack[0];
    v18 = stack[-1];
    fn = elt(env, 3); /* quotf */
    v18 = (*qfn2(fn))(qenv(fn), v78, v18);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    fn = elt(env, 4); /* sfto_updecf */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    stack[-1] = v18;
    v18 = stack[-2];
    v78 = qcar(v18);
    v18 = stack[-1];
    v18 = qcar(v18);
    fn = elt(env, 5); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v78, v18);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    v18 = stack[-2];
    v78 = qcdr(v18);
    v18 = stack[-1];
    v18 = qcdr(v18);
    fn = elt(env, 5); /* multf */
    v18 = (*qfn2(fn))(qenv(fn), v78, v18);
    nil = C_nil;
    if (exception_pending()) goto v89;
    {
        Lisp_Object v114 = stack[0];
        popv(4);
        return cons(v114, v18);
    }

v100:
    v18 = qvalue(elt(env, 1)); /* t */
    goto v30;
/* error exit handlers */
v89:
    popv(4);
    return nil;
}



/* Code for valuecoefft */

static Lisp_Object MS_CDECL CC_valuecoefft(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26, v107, v86, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "valuecoefft");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for valuecoefft");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v107 = v2;
    v86 = v1;
    v46 = v0;
/* end of prologue */

v112:
    v25 = v107;
    if (v25 == nil) goto v104;
    v26 = v46;
    v25 = v107;
    v25 = qcar(v25);
    if (v26 == v25) goto v23;
    v25 = v86;
    v25 = qcdr(v25);
    v86 = v25;
    v25 = v107;
    v25 = qcdr(v25);
    v107 = v25;
    goto v112;

v23:
    v25 = v86;
    v26 = qcar(v25);
    v25 = (Lisp_Object)1; /* 0 */
    if (v26 == v25) goto v146;
    v25 = v86;
    v25 = qcar(v25);
    return onevalue(v25);

v146:
    v25 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v25);

v104:
    v25 = elt(env, 1); /* "Valuecoefft - no value" */
    {
        fn = elt(env, 3); /* interr */
        return (*qfn1(fn))(qenv(fn), v25);
    }
}



/* Code for get_char_value */

static Lisp_Object CC_get_char_value(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_char_value");
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
    v87 = v0;
/* end of prologue */
    stack[-1] = nil;
    v117 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v117;
    v117 = v87;
    v117 = qcdr(v117);
    stack[0] = v117;
    goto v100;

v100:
    v117 = stack[-3];
    if (v117 == nil) goto v21;
    v117 = qvalue(elt(env, 1)); /* nil */
    goto v37;

v37:
    if (v117 == nil) goto v30;
    v117 = stack[0];
    v117 = qcar(v117);
    v87 = qcar(v117);
    v117 = stack[-2];
    if (!(equal(v87, v117))) goto v32;
    v117 = stack[0];
    v117 = qcar(v117);
    v117 = qcdr(v117);
    v117 = qcar(v117);
    stack[-1] = v117;
    v117 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v117;
    goto v32;

v32:
    v117 = stack[0];
    v117 = qcdr(v117);
    stack[0] = v117;
    goto v100;

v30:
    v117 = stack[-3];
    if (!(v117 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v117 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v117 == nil)) goto v18;
    v117 = elt(env, 4); /* "error in get character element" */
    fn = elt(env, 5); /* lprie */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-4];
    goto v18;

v18:
    v117 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v76;
    v117 = nil;
    { popv(5); return onevalue(v117); }

v21:
    v117 = stack[0];
    v87 = Llength(nil, v117);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-4];
    v117 = (Lisp_Object)1; /* 0 */
    v117 = (Lisp_Object)greaterp2(v87, v117);
    nil = C_nil;
    if (exception_pending()) goto v76;
    v117 = v117 ? lisp_true : nil;
    env = stack[-4];
    goto v37;
/* error exit handlers */
v76:
    popv(5);
    return nil;
}



/* Code for multiminus */

static Lisp_Object CC_multiminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiminus");
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
    v11 = stack[0];
    v11 = qcar(v11);
    fn = elt(env, 1); /* expression */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    v11 = stack[0];
    v21 = Llength(nil, v11);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    v11 = (Lisp_Object)33; /* 2 */
    if (!(v21 == v11)) goto v99;
    v11 = stack[0];
    v11 = qcdr(v11);
    v11 = qcar(v11);
    fn = elt(env, 1); /* expression */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v146;
    goto v99;

v99:
    v11 = nil;
    { popv(2); return onevalue(v11); }
/* error exit handlers */
v146:
    popv(2);
    return nil;
}



/* Code for groebbuchcrit4t */

static Lisp_Object CC_groebbuchcrit4t(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebbuchcrit4t");
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

v10:
    v8 = stack[-1];
    if (v8 == nil) goto v30;
    v8 = stack[0];
    v8 = (v8 == nil ? lisp_true : nil);
    goto v105;

v105:
    if (v8 == nil) goto v38;
    v8 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v8); }

v38:
    v8 = stack[-1];
    v6 = qcar(v8);
    v8 = (Lisp_Object)1; /* 0 */
    if (v6 == v8) goto v49;
    v8 = stack[0];
    v6 = qcar(v8);
    v8 = (Lisp_Object)1; /* 0 */
    v8 = Lneq(nil, v6, v8);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    goto v21;

v21:
    if (v8 == nil) goto v26;
    v8 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v8); }

v26:
    v8 = stack[-1];
    v8 = qcdr(v8);
    stack[-1] = v8;
    v8 = stack[0];
    v8 = qcdr(v8);
    stack[0] = v8;
    goto v10;

v49:
    v8 = qvalue(elt(env, 2)); /* nil */
    goto v21;

v30:
    v8 = qvalue(elt(env, 1)); /* t */
    goto v105;
/* error exit handlers */
v110:
    popv(3);
    return nil;
}



/* Code for indxsymp */

static Lisp_Object CC_indxsymp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indxsymp");
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

v181:
    v140 = stack[0];
    if (v140 == nil) goto v10;
    v140 = stack[0];
    v32 = qcar(v140);
    v140 = stack[-1];
    v140 = Lapply1(nil, v32, v140);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    if (v140 == nil) goto v100;
    v32 = stack[-1];
    v140 = stack[0];
    v140 = qcdr(v140);
    stack[-1] = v32;
    stack[0] = v140;
    goto v181;

v100:
    v140 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v140); }

v10:
    v140 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v140); }
/* error exit handlers */
v45:
    popv(3);
    return nil;
}



/* Code for calc_coeff */

static Lisp_Object CC_calc_coeff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v8, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_coeff");
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
    v101 = stack[-1];
    if (v101 == nil) goto v10;
    v101 = stack[-1];
    v8 = qcar(v101);
    v101 = stack[0];
    fn = elt(env, 1); /* calc_world */
    v101 = (*qfn2(fn))(qenv(fn), v8, v101);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    v6 = v101;
    v8 = v6;
    v101 = (Lisp_Object)1; /* 0 */
    if (v8 == v101) goto v21;
    stack[-2] = v6;
    v101 = stack[-1];
    v8 = qcdr(v101);
    v101 = stack[0];
    v101 = CC_calc_coeff(env, v8, v101);
    nil = C_nil;
    if (exception_pending()) goto v178;
    {
        Lisp_Object v14 = stack[-2];
        popv(4);
        return cons(v14, v101);
    }

v21:
    v101 = (Lisp_Object)1; /* 0 */
    popv(4);
    return ncons(v101);

v10:
    v101 = (Lisp_Object)17; /* 1 */
    popv(4);
    return ncons(v101);
/* error exit handlers */
v178:
    popv(4);
    return nil;
}



/* Code for innprodpex */

static Lisp_Object CC_innprodpex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for innprodpex");
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

v181:
    v90 = stack[-1];
    if (v90 == nil) goto v10;
    v73 = stack[-2];
    v90 = stack[-1];
    v90 = qcar(v90);
    v90 = qcar(v90);
    fn = elt(env, 2); /* innprodp2 */
    v90 = (*qfn2(fn))(qenv(fn), v73, v90);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    v73 = v90;
    v90 = v73;
    if (v90 == nil) goto v47;
    v90 = v73;
    stack[-3] = qcdr(v90);
    v90 = v73;
    v90 = qcar(v90);
    if (v90 == nil) goto v25;
    v90 = stack[-1];
    v90 = qcar(v90);
    v90 = qcdr(v90);
    fn = elt(env, 3); /* negf */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    stack[0] = v90;
    goto v101;

v101:
    v73 = stack[-2];
    v90 = stack[-1];
    v90 = qcdr(v90);
    v90 = CC_innprodpex(env, v73, v90);
    nil = C_nil;
    if (exception_pending()) goto v172;
    {
        Lisp_Object v106 = stack[-3];
        Lisp_Object v118 = stack[0];
        popv(5);
        return acons(v106, v118, v90);
    }

v25:
    v90 = stack[-1];
    v90 = qcar(v90);
    v90 = qcdr(v90);
    stack[0] = v90;
    goto v101;

v47:
    v73 = stack[-2];
    v90 = stack[-1];
    v90 = qcdr(v90);
    stack[-2] = v73;
    stack[-1] = v90;
    goto v181;

v10:
    v90 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v90); }
/* error exit handlers */
v172:
    popv(5);
    return nil;
}



/* Code for simp!-prop!-condense */

static Lisp_Object CC_simpKpropKcondense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-condense");
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
    stack[-2] = nil;
    v114 = stack[-3];
    v89 = elt(env, 1); /* lambda_lqlbvd_6 */
    fn = elt(env, 3); /* sort */
    v89 = (*qfn2(fn))(qenv(fn), v114, v89);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    stack[-3] = v89;
    goto v36;

v36:
    v89 = stack[-3];
    if (v89 == nil) goto v13;
    v89 = stack[-3];
    v89 = qcar(v89);
    stack[-4] = v89;
    v89 = stack[-3];
    v89 = qcdr(v89);
    stack[-3] = v89;
    v114 = stack[-4];
    v89 = stack[-2];
    v89 = cons(v114, v89);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    stack[-2] = v89;
    v89 = stack[-3];
    stack[-1] = v89;
    goto v43;

v43:
    v89 = stack[-1];
    if (v89 == nil) goto v36;
    v89 = stack[-1];
    v89 = qcar(v89);
    stack[0] = v89;
    v114 = stack[-4];
    v89 = stack[0];
    fn = elt(env, 4); /* subsetp */
    v89 = (*qfn2(fn))(qenv(fn), v114, v89);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    if (v89 == nil) goto v86;
    v114 = stack[0];
    v89 = stack[-3];
    v89 = Ldelete(nil, v114, v89);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-5];
    stack[-3] = v89;
    goto v86;

v86:
    v89 = stack[-1];
    v89 = qcdr(v89);
    stack[-1] = v89;
    goto v43;

v13:
    v89 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* ordn */
        return (*qfn1(fn))(qenv(fn), v89);
    }
/* error exit handlers */
v108:
    popv(6);
    return nil;
}



/* Code for lambda_lqlbvd_6 */

static Lisp_Object CC_lambda_lqlbvd_6(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqlbvd_6");
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
    v100 = v0;
/* end of prologue */
    stack[-1] = Llength(nil, v100);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v100 = stack[0];
    v100 = Llength(nil, v100);
    nil = C_nil;
    if (exception_pending()) goto v36;
    {
        Lisp_Object v35 = stack[-1];
        popv(3);
        return Llessp(nil, v35, v100);
    }
/* error exit handlers */
v36:
    popv(3);
    return nil;
}



/* Code for pcdiv */

static Lisp_Object CC_pcdiv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pcdiv");
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
    v114 = v0;
/* end of prologue */
    stack[-5] = v114;
    v114 = stack[-5];
    if (v114 == nil) goto v30;
    v114 = stack[-5];
    v114 = qcar(v114);
    v117 = v114;
    v114 = v117;
    stack[0] = qcar(v114);
    v114 = v117;
    v117 = qcdr(v114);
    v114 = stack[-4];
    fn = elt(env, 2); /* cdiv */
    v114 = (*qfn2(fn))(qenv(fn), v117, v114);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v114 = cons(stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v114 = ncons(v114);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    stack[-2] = v114;
    stack[-3] = v114;
    goto v99;

v99:
    v114 = stack[-5];
    v114 = qcdr(v114);
    stack[-5] = v114;
    v114 = stack[-5];
    if (v114 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v114 = stack[-5];
    v114 = qcar(v114);
    v117 = v114;
    v114 = v117;
    stack[0] = qcar(v114);
    v114 = v117;
    v117 = qcdr(v114);
    v114 = stack[-4];
    fn = elt(env, 2); /* cdiv */
    v114 = (*qfn2(fn))(qenv(fn), v117, v114);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v114 = cons(stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v114 = ncons(v114);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v114 = Lrplacd(nil, stack[-1], v114);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v114 = stack[-2];
    v114 = qcdr(v114);
    stack[-2] = v114;
    goto v99;

v30:
    v114 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v114); }
/* error exit handlers */
v77:
    popv(7);
    return nil;
}



/* Code for subf */

static Lisp_Object CC_subf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subf");
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
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    stack[-5] = nil;
    stack[-4] = nil;
    v142 = qvalue(elt(env, 2)); /* nil */
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    qvalue(elt(env, 1)) = v142; /* alglist!* */
    v142 = stack[-7];
    if (!consp(v142)) goto v35;
    v142 = stack[-7];
    v142 = qcar(v142);
    v142 = (consp(v142) ? nil : lisp_true);
    goto v36;

v36:
    if (v142 == nil) goto v12;
    v142 = stack[-7];
    fn = elt(env, 8); /* !*d2q */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    goto v99;

v99:
    qvalue(elt(env, 1)) = stack[-8]; /* alglist!* */
    { popv(10); return onevalue(v142); }

v12:
    v142 = qvalue(elt(env, 4)); /* ncmp!* */
    if (v142 == nil) goto v98;
    v142 = stack[-7];
    fn = elt(env, 9); /* noncomexpf */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    if (v142 == nil) goto v98;
    v195 = stack[-7];
    v142 = stack[-6];
    fn = elt(env, 10); /* subf1 */
    v142 = (*qfn2(fn))(qenv(fn), v195, v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    goto v99;

v98:
    v142 = stack[-6];
    stack[-3] = v142;
    v142 = stack[-3];
    if (v142 == nil) goto v178;
    v142 = stack[-3];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    stack[-1] = v142;
    stack[-2] = v142;
    goto v6;

v6:
    v142 = stack[-3];
    v142 = qcdr(v142);
    stack[-3] = v142;
    v142 = stack[-3];
    if (v142 == nil) goto v73;
    stack[0] = stack[-1];
    v142 = stack[-3];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    v142 = Lrplacd(nil, stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    v142 = stack[-1];
    v142 = qcdr(v142);
    stack[-1] = v142;
    goto v6;

v73:
    v142 = stack[-2];
    stack[0] = v142;
    goto v164;

v164:
    v195 = stack[-7];
    v142 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 11); /* kernord */
    v142 = (*qfn2(fn))(qenv(fn), v195, v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    fn = elt(env, 12); /* intersection */
    v142 = (*qfn2(fn))(qenv(fn), stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    v142 = Lreverse(nil, v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    stack[0] = v142;
    v142 = stack[0];
    fn = elt(env, 13); /* setkorder */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    stack[0] = v142;
    v142 = stack[-7];
    fn = elt(env, 14); /* reorder */
    v195 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    v142 = stack[-6];
    fn = elt(env, 10); /* subf1 */
    v142 = (*qfn2(fn))(qenv(fn), v195, v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    stack[-7] = v142;
    goto v137;

v137:
    v195 = stack[-7];
    v142 = stack[-4];
    v142 = Lmember(nil, v195, v142);
    if (v142 == nil) goto v189;
    v142 = qvalue(elt(env, 2)); /* nil */
    goto v168;

v168:
    if (v142 == nil) goto v180;
    v195 = stack[-7];
    v142 = stack[-4];
    v142 = cons(v195, v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    stack[-4] = v142;
    v142 = stack[-5];
    fn = elt(env, 15); /* simp */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    stack[-7] = v142;
    goto v137;

v180:
    v142 = stack[0];
    fn = elt(env, 13); /* setkorder */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    v142 = stack[-7];
    v142 = qcar(v142);
    fn = elt(env, 14); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    v142 = stack[-7];
    v142 = qcdr(v142);
    fn = elt(env, 14); /* reorder */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    v142 = cons(stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    goto v99;

v189:
    stack[-1] = elt(env, 5); /* expt */
    v142 = stack[-7];
    v195 = qcar(v142);
    v142 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 16); /* kernels1 */
    v142 = (*qfn2(fn))(qenv(fn), v195, v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    v142 = Latsoc(nil, stack[-1], v142);
    if (!(v142 == nil)) goto v197;
    stack[-1] = elt(env, 5); /* expt */
    v142 = stack[-7];
    v195 = qcdr(v142);
    v142 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 16); /* kernels1 */
    v142 = (*qfn2(fn))(qenv(fn), v195, v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    v142 = Latsoc(nil, stack[-1], v142);
    if (!(v142 == nil)) goto v197;
    v142 = qvalue(elt(env, 2)); /* nil */
    goto v168;

v197:
    v142 = stack[-7];
    v142 = qcar(v142);
    if (v142 == nil) goto v198;
    v195 = stack[-7];
    v142 = elt(env, 6); /* prepf */
    fn = elt(env, 17); /* sqform */
    v142 = (*qfn2(fn))(qenv(fn), v195, v142);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-9];
    v195 = v142;
    goto v85;

v85:
    stack[-5] = v195;
    v142 = qvalue(elt(env, 7)); /* varstack!* */
    v142 = Lmember(nil, v195, v142);
    v142 = (v142 == nil ? lisp_true : nil);
    goto v168;

v198:
    v142 = (Lisp_Object)1; /* 0 */
    v195 = v142;
    goto v85;

v178:
    v142 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v142;
    goto v164;

v35:
    v142 = qvalue(elt(env, 3)); /* t */
    goto v36;
/* error exit handlers */
v196:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-8]; /* alglist!* */
    popv(10);
    return nil;
}



/* Code for get!-height */

static Lisp_Object CC_getKheight(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-height");
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
    v23 = stack[0];
    if (v23 == nil) goto v34;
    v23 = stack[0];
    if (is_number(v23)) goto v99;
    v23 = stack[0];
    v23 = qcar(v23);
    v23 = qcdr(v23);
    stack[-1] = CC_getKheight(env, v23);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v23 = stack[0];
    v23 = qcdr(v23);
    v23 = CC_getKheight(env, v23);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    {
        Lisp_Object v40 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* max */
        return (*qfn2(fn))(qenv(fn), v40, v23);
    }

v99:
    v23 = stack[0];
        popv(3);
        return Labsval(nil, v23);

v34:
    v23 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v23); }
/* error exit handlers */
v39:
    popv(3);
    return nil;
}



/* Code for normalform */

static Lisp_Object CC_normalform(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for normalform");
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
    stack[0] = v1;
    v47 = v0;
/* end of prologue */
    v17 = qvalue(elt(env, 1)); /* !*mode */
    v16 = elt(env, 2); /* algebraic */
    if (v17 == v16) goto v19;
    v17 = v47;
    v16 = stack[0];
    {
        popv(5);
        fn = elt(env, 4); /* normalform!* */
        return (*qfn2(fn))(qenv(fn), v17, v16);
    }

v19:
    v16 = v47;
    fn = elt(env, 5); /* reval */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    fn = elt(env, 6); /* dpmat_from_a */
    stack[-1] = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    v16 = stack[0];
    fn = elt(env, 5); /* reval */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    fn = elt(env, 6); /* dpmat_from_a */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    fn = elt(env, 4); /* normalform!* */
    v16 = (*qfn2(fn))(qenv(fn), stack[-1], v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    stack[-3] = v16;
    stack[-2] = elt(env, 3); /* list */
    v16 = stack[-3];
    v16 = qcar(v16);
    fn = elt(env, 7); /* dpmat_2a */
    stack[-1] = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    v16 = stack[-3];
    v16 = qcdr(v16);
    v16 = qcar(v16);
    fn = elt(env, 7); /* dpmat_2a */
    stack[0] = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    v16 = stack[-3];
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    v16 = qcar(v16);
    fn = elt(env, 7); /* dpmat_2a */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    {
        Lisp_Object v78 = stack[-2];
        Lisp_Object v113 = stack[-1];
        Lisp_Object v90 = stack[0];
        popv(5);
        return list4(v78, v113, v90, v16);
    }
/* error exit handlers */
v18:
    popv(5);
    return nil;
}



/* Code for mk!+outer!+list */

static Lisp_Object CC_mkLouterLlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v12;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+outer+list");
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
    stack[0] = v0;
/* end of prologue */
    v100 = elt(env, 1); /* list */
    v12 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v36;
    v100 = stack[0];
        popv(1);
        return Lappend(nil, v12, v100);
/* error exit handlers */
v36:
    popv(1);
    return nil;
}



/* Code for qqe_eta!-in!-term1 */

static Lisp_Object CC_qqe_etaKinKterm1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_eta-in-term1");
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
    v41 = stack[0];
    v41 = qcdr(v41);
    v41 = qcar(v41);
    fn = elt(env, 4); /* qqe_simplterm */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    stack[-1] = v41;
    v41 = stack[0];
    fn = elt(env, 5); /* qqe_op */
    v42 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v41 = stack[-1];
    v41 = cons(v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v42 = stack[-1];
    v41 = elt(env, 1); /* qepsilon */
    if (v42 == v41) goto v27;
    v41 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v41); }

v27:
    v41 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v41); }
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for minusml */

static Lisp_Object CC_minusml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusml");
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
    v146 = elt(env, 1); /* "<apply><minus/>" */
    fn = elt(env, 4); /* printout */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v38 = qvalue(elt(env, 2)); /* indent */
    v146 = (Lisp_Object)49; /* 3 */
    v146 = plus2(v38, v146);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    qvalue(elt(env, 2)) = v146; /* indent */
    v146 = stack[0];
    fn = elt(env, 5); /* multiminus */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v38 = qvalue(elt(env, 2)); /* indent */
    v146 = (Lisp_Object)49; /* 3 */
    v146 = difference2(v38, v146);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    qvalue(elt(env, 2)) = v146; /* indent */
    v146 = elt(env, 3); /* "</apply>" */
    fn = elt(env, 4); /* printout */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v146 = nil;
    { popv(2); return onevalue(v146); }
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for reval3 */

static Lisp_Object CC_reval3(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval3");
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
    fn = elt(env, 1); /* simp */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v83);
    }
/* error exit handlers */
v99:
    popv(1);
    return nil;
}



/* Code for find_buble */

static Lisp_Object CC_find_buble(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_buble");
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

v181:
    v40 = stack[0];
    if (v40 == nil) goto v10;
    v41 = stack[-1];
    v40 = stack[0];
    v40 = qcar(v40);
    fn = elt(env, 2); /* is_buble */
    v40 = (*qfn2(fn))(qenv(fn), v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    if (!(v40 == nil)) { popv(3); return onevalue(v40); }
    v41 = stack[-1];
    v40 = stack[0];
    v40 = qcdr(v40);
    stack[-1] = v41;
    stack[0] = v40;
    goto v181;

v10:
    v40 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v40); }
/* error exit handlers */
v140:
    popv(3);
    return nil;
}



/* Code for innprodp2 */

static Lisp_Object CC_innprodp2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v48, v25, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for innprodp2");
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
    v25 = v1;
    stack[0] = v0;
/* end of prologue */
    v98 = qvalue(elt(env, 1)); /* nil */
    v48 = v25;
    v98 = cons(v98, v48);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-1];
    v25 = v98;
    goto v13;

v13:
    v98 = stack[0];
    if (v98 == nil) { popv(2); return onevalue(v25); }
    v98 = v25;
    if (v98 == nil) { popv(2); return onevalue(v25); }
    v26 = qvalue(elt(env, 1)); /* nil */
    v98 = stack[0];
    v48 = qcar(v98);
    v98 = v25;
    v98 = qcdr(v98);
    v25 = qcar(v25);
    fn = elt(env, 2); /* innprodkp */
    v98 = (*qfnn(fn))(qenv(fn), 4, v26, v48, v98, v25);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-1];
    v25 = v98;
    v98 = stack[0];
    v98 = qcdr(v98);
    stack[0] = v98;
    goto v13;
/* error exit handlers */
v86:
    popv(2);
    return nil;
}



/* Code for matop_pseudomod */

static Lisp_Object CC_matop_pseudomod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matop_pseudomod");
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
    v30 = v1;
    v100 = v0;
/* end of prologue */
    fn = elt(env, 1); /* mod!* */
    v30 = (*qfn2(fn))(qenv(fn), v100, v30);
    errexit();
    v30 = qcar(v30);
    return onevalue(v30);
}



/* Code for nf */

static Lisp_Object MS_CDECL CC_nf(Lisp_Object env, int nargs,
                         Lisp_Object v1, Lisp_Object v2,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213, v214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "nf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nf");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v2,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v3;
    v212 = v2;
    v213 = v1;
/* end of prologue */
    stack[-10] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v212; /* gg */
    v212 = qvalue(elt(env, 1)); /* gg */
    if (v212 == nil) goto v105;
    stack[-3] = nil;
    v212 = (Lisp_Object)1; /* 0 */
    stack[0] = v212;
    v212 = v213;
    stack[-8] = v212;
    v212 = qvalue(elt(env, 1)); /* gg */
    stack[-2] = v212;
    goto v33;

v33:
    v212 = stack[-8];
    if (v212 == nil) goto v215;
    v212 = stack[-8];
    v212 = qcar(v212);
    v212 = qcar(v212);
    stack[-7] = v212;
    goto v98;

v98:
    v212 = stack[-2];
    if (v212 == nil) goto v139;
    v213 = stack[-7];
    v212 = stack[-2];
    v212 = qcar(v212);
    v212 = qcdr(v212);
    fn = elt(env, 13); /* dless */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    goto v46;

v46:
    if (v212 == nil) goto v49;
    v212 = stack[-2];
    v212 = qcdr(v212);
    stack[-2] = v212;
    goto v98;

v49:
    v212 = stack[-2];
    if (v212 == nil) goto v215;
    v212 = stack[-2];
    stack[-1] = v212;
    goto v106;

v106:
    v212 = stack[-1];
    if (v212 == nil) goto v172;
    v212 = stack[-1];
    v212 = qcar(v212);
    v213 = qcdr(v212);
    v212 = stack[-7];
    fn = elt(env, 14); /* dd */
    stack[-4] = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    v213 = stack[-9];
    v212 = (Lisp_Object)33; /* 2 */
    v212 = plus2(v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    if (!(((int32_t)(stack[-4])) < ((int32_t)(v212)))) goto v172;
    v212 = stack[-1];
    v212 = qcdr(v212);
    stack[-1] = v212;
    goto v106;

v172:
    v212 = stack[-1];
    if (v212 == nil) goto v70;
    v213 = qvalue(elt(env, 4)); /* gv */
    v212 = stack[-1];
    v212 = qcar(v212);
    v212 = qcar(v212);
    v212 = *(Lisp_Object *)((char *)v213 + (CELL-TAG_VECTOR) + ((int32_t)v212/(16/CELL)));
    stack[-6] = v212;
    v212 = stack[-8];
    v212 = qcar(v212);
    v213 = qcdr(v212);
    v212 = stack[-6];
    v212 = qcar(v212);
    v212 = qcdr(v212);
    fn = elt(env, 15); /* gcdf!* */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    stack[-4] = v212;
    v212 = stack[-8];
    v212 = qcar(v212);
    v213 = qcdr(v212);
    v212 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    stack[-5] = v212;
    v212 = stack[-6];
    v212 = qcar(v212);
    v213 = qcdr(v212);
    v212 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    stack[-4] = v212;
    v213 = stack[-8];
    v212 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    stack[-8] = v212;
    v213 = stack[-3];
    v212 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    stack[-3] = v212;
    v213 = stack[-6];
    v212 = stack[-5];
    fn = elt(env, 17); /* pcmult */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    stack[-6] = v212;
    v212 = stack[-6];
    stack[-4] = qcdr(v212);
    v213 = stack[-7];
    v212 = stack[-1];
    v212 = qcar(v212);
    v212 = qcdr(v212);
    fn = elt(env, 18); /* dquot */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    fn = elt(env, 19); /* pdmult */
    v212 = (*qfn2(fn))(qenv(fn), stack[-4], v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    stack[-4] = v212;
    v212 = qvalue(elt(env, 5)); /* tred */
    if (v212 == nil) goto v217;
    v212 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    v212 = elt(env, 6); /* "r e d u c t i o n :  " */
    v212 = Lprinc(nil, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    v212 = stack[-7];
    v212 = Lprinc(nil, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    v212 = elt(env, 7); /* "/" */
    v212 = Lprinc(nil, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    v212 = stack[-1];
    v212 = qcar(v212);
    v212 = qcdr(v212);
    v212 = Lprinc(nil, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    v212 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    goto v217;

v217:
    v212 = qvalue(elt(env, 8)); /* stars */
    if (v212 == nil) goto v218;
    v212 = elt(env, 9); /* "*" */
    v212 = Lprinc(nil, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    goto v218;

v218:
    v212 = stack[0];
    v212 = (Lisp_Object)((int32_t)(v212) + 0x10);
    stack[0] = v212;
    v212 = stack[-8];
    v213 = qcdr(v212);
    v212 = stack[-4];
    fn = elt(env, 20); /* pdif */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    stack[-8] = v212;
    goto v33;

v70:
    v212 = qvalue(elt(env, 3)); /* redtails */
    if (v212 == nil) goto v215;
    v214 = stack[-7];
    v212 = stack[-8];
    v212 = qcar(v212);
    v213 = qcdr(v212);
    v212 = stack[-3];
    v212 = acons(v214, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    stack[-3] = v212;
    v212 = stack[-8];
    v212 = qcdr(v212);
    stack[-8] = v212;
    goto v33;

v215:
    v213 = qvalue(elt(env, 10)); /* reductions */
    v212 = stack[0];
    v212 = (Lisp_Object)(int32_t)((int32_t)v213 + (int32_t)v212 - TAG_FIXNUM);
    qvalue(elt(env, 10)) = v212; /* reductions */
    v212 = qvalue(elt(env, 11)); /* nforms */
    v212 = (Lisp_Object)((int32_t)(v212) + 0x10);
    qvalue(elt(env, 11)) = v212; /* nforms */
    v212 = stack[-3];
    v213 = Lnreverse(nil, v212);
    env = stack[-11];
    v212 = stack[-8];
    v212 = Lappend(nil, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    fn = elt(env, 21); /* gcdout */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-11];
    stack[-4] = v212;
    v212 = stack[-4];
    if (!(v212 == nil)) goto v219;
    v212 = qvalue(elt(env, 12)); /* zeros */
    v212 = (Lisp_Object)((int32_t)(v212) + 0x10);
    qvalue(elt(env, 12)) = v212; /* zeros */
    goto v219;

v219:
    v212 = stack[-4];
    goto v83;

v83:
    qvalue(elt(env, 1)) = stack[-10]; /* gg */
    { popv(12); return onevalue(v212); }

v139:
    v212 = qvalue(elt(env, 2)); /* nil */
    goto v46;

v105:
    v212 = v213;
    goto v83;
/* error exit handlers */
v216:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-10]; /* gg */
    popv(12);
    return nil;
}



setup_type const u26_setup[] =
{
    {"even_action_sf",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_even_action_sf},
    {"deginvar",                too_few_2,      CC_deginvar,   wrong_no_2},
    {"cgp_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_cgp_mk},
    {"relnrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_relnrd},
    {"s-nextarg",               CC_sKnextarg,   too_many_1,    wrong_no_1},
    {"dipequal",                too_few_2,      CC_dipequal,   wrong_no_2},
    {"gfplusn",                 too_few_2,      CC_gfplusn,    wrong_no_2},
    {"harmonicp",               CC_harmonicp,   too_many_1,    wrong_no_1},
    {"mo_lcm",                  too_few_2,      CC_mo_lcm,     wrong_no_2},
    {"*a2f",                    CC_Ha2f,        too_many_1,    wrong_no_1},
    {"termorder",               too_few_2,      CC_termorder,  wrong_no_2},
    {"triplesetprolongedby",    too_few_2,      CC_triplesetprolongedby,wrong_no_2},
    {"wupseudodivide",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_wupseudodivide},
    {"qqe_arg-check-lb-rb",     CC_qqe_argKcheckKlbKrb,too_many_1,wrong_no_1},
    {"cl_smsimpl-junct",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct},
    {"embed-null-fn",           CC_embedKnullKfn,too_many_1,   wrong_no_1},
    {"xlcm",                    too_few_2,      CC_xlcm,       wrong_no_2},
    {"aceq",                    too_few_2,      CC_aceq,       wrong_no_2},
    {"flatindl",                CC_flatindl,    too_many_1,    wrong_no_1},
    {"subcare",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subcare},
    {"red_topredbe",            too_few_2,      CC_red_topredbe,wrong_no_2},
    {"simp-prop2",              CC_simpKprop2,  too_many_1,    wrong_no_1},
    {"*di2q",                   too_few_2,      CC_Hdi2q,      wrong_no_2},
    {"nonlnr",                  too_few_2,      CC_nonlnr,     wrong_no_2},
    {"tayexp-max2",             too_few_2,      CC_tayexpKmax2,wrong_no_2},
    {"cl_bnfsimpl",             too_few_2,      CC_cl_bnfsimpl,wrong_no_2},
    {"gb_buch-ev_divides?",     too_few_2,      CC_gb_buchKev_dividesW,wrong_no_2},
    {"bc_fd",                   CC_bc_fd,       too_many_1,    wrong_no_1},
    {"matrix_rows",             CC_matrix_rows, too_many_1,    wrong_no_1},
    {"degreef",                 too_few_2,      CC_degreef,    wrong_no_2},
    {"delyzz",                  too_few_2,      CC_delyzz,     wrong_no_2},
    {"evgradlexcomp",           too_few_2,      CC_evgradlexcomp,wrong_no_2},
    {"xriterion_1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_xriterion_1},
    {"fl2bf",                   CC_fl2bf,       too_many_1,    wrong_no_1},
    {"apply_e",                 CC_apply_e,     too_many_1,    wrong_no_1},
    {"gpargp",                  CC_gpargp,      too_many_1,    wrong_no_1},
    {"getphystypeall",          CC_getphystypeall,too_many_1,  wrong_no_1},
    {"gvarlis1",                too_few_2,      CC_gvarlis1,   wrong_no_2},
    {"general-horner-rule-mod-p",wrong_no_na,   wrong_no_nb,   (n_args *)CC_generalKhornerKruleKmodKp},
    {"reduce-eival-powers",     too_few_2,      CC_reduceKeivalKpowers,wrong_no_2},
    {"sfto_pdecf",              CC_sfto_pdecf,  too_many_1,    wrong_no_1},
    {"valuecoefft",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_valuecoefft},
    {"get_char_value",          too_few_2,      CC_get_char_value,wrong_no_2},
    {"multiminus",              CC_multiminus,  too_many_1,    wrong_no_1},
    {"groebbuchcrit4t",         too_few_2,      CC_groebbuchcrit4t,wrong_no_2},
    {"indxsymp",                too_few_2,      CC_indxsymp,   wrong_no_2},
    {"calc_coeff",              too_few_2,      CC_calc_coeff, wrong_no_2},
    {"innprodpex",              too_few_2,      CC_innprodpex, wrong_no_2},
    {"simp-prop-condense",      CC_simpKpropKcondense,too_many_1,wrong_no_1},
    {"lambda_lqlbvd_6",         too_few_2,      CC_lambda_lqlbvd_6,wrong_no_2},
    {"pcdiv",                   too_few_2,      CC_pcdiv,      wrong_no_2},
    {"subf",                    too_few_2,      CC_subf,       wrong_no_2},
    {"get-height",              CC_getKheight,  too_many_1,    wrong_no_1},
    {"normalform",              too_few_2,      CC_normalform, wrong_no_2},
    {"mk+outer+list",           CC_mkLouterLlist,too_many_1,   wrong_no_1},
    {"qqe_eta-in-term1",        CC_qqe_etaKinKterm1,too_many_1,wrong_no_1},
    {"minusml",                 CC_minusml,     too_many_1,    wrong_no_1},
    {"reval3",                  CC_reval3,      too_many_1,    wrong_no_1},
    {"find_buble",              too_few_2,      CC_find_buble, wrong_no_2},
    {"innprodp2",               too_few_2,      CC_innprodp2,  wrong_no_2},
    {"matop_pseudomod",         too_few_2,      CC_matop_pseudomod,wrong_no_2},
    {"nf",                      wrong_no_na,    wrong_no_nb,   (n_args *)CC_nf},
    {NULL, (one_args *)"u26", (two_args *)"19719 7347039 459492", 0}
};

/* end of generated code */
