
/* $destdir\u35.c        Machine generated C code */

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


/* Code for mv!-compact */

static Lisp_Object MS_CDECL CC_mvKcompact(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v37, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mv-compact");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-compact");
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
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v39:
    v36 = stack[-3];
    if (v36 == nil) goto v40;
    v37 = stack[-3];
    v36 = stack[-2];
    fn = elt(env, 2); /* mv!-pow!-chk */
    v36 = (*qfn2(fn))(qenv(fn), v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    stack[-4] = v36;
    if (v36 == nil) goto v42;
    stack[0] = stack[-3];
    v37 = stack[-4];
    v36 = stack[-2];
    fn = elt(env, 3); /* mv!-pow!-mv!-!+ */
    v36 = (*qfn2(fn))(qenv(fn), v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    fn = elt(env, 4); /* mv!-compact2 */
    v36 = (*qfn2(fn))(qenv(fn), stack[0], v36);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    stack[0] = v36;
    if (v36 == nil) goto v42;
    v38 = stack[0];
    v37 = stack[-2];
    v36 = stack[-1];
    stack[-3] = v38;
    stack[-2] = v37;
    stack[-1] = v36;
    goto v39;

v42:
    v37 = stack[-3];
    v36 = stack[-2];
    v36 = qcdr(v36);
    fn = elt(env, 2); /* mv!-pow!-chk */
    v36 = (*qfn2(fn))(qenv(fn), v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    stack[-4] = v36;
    if (v36 == nil) goto v43;
    v37 = stack[-4];
    v36 = stack[-2];
    v36 = qcar(v36);
    v36 = qcar(v36);
    fn = elt(env, 5); /* mv!-pow!-!+ */
    v37 = (*qfn2(fn))(qenv(fn), v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    stack[0] = v37;
    v36 = stack[-1];
    fn = elt(env, 6); /* mv!-pow!-assoc */
    v36 = (*qfn2(fn))(qenv(fn), v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    if (v36 == nil) goto v44;
    v36 = qvalue(elt(env, 1)); /* nil */
    goto v45;

v45:
    if (v36 == nil) goto v43;
    v38 = stack[0];
    v37 = stack[-2];
    v36 = stack[-1];
    stack[-3] = v38;
    stack[-2] = v37;
    stack[-1] = v36;
    goto v39;

v43:
    v36 = stack[-3];
    stack[0] = qcdr(v36);
    v36 = stack[-3];
    v37 = qcar(v36);
    v36 = stack[-1];
    v36 = cons(v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    stack[-3] = stack[0];
    stack[-1] = v36;
    goto v39;

v44:
    v38 = stack[0];
    v37 = (Lisp_Object)1; /* 0 */
    v36 = stack[-3];
    stack[0] = acons(v38, v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    v37 = stack[-4];
    v36 = stack[-2];
    fn = elt(env, 3); /* mv!-pow!-mv!-!+ */
    v36 = (*qfn2(fn))(qenv(fn), v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    fn = elt(env, 4); /* mv!-compact2 */
    v36 = (*qfn2(fn))(qenv(fn), stack[0], v36);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    stack[0] = v36;
    goto v45;

v40:
    v36 = stack[-1];
    {
        popv(6);
        fn = elt(env, 7); /* mv!-reverse */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v41:
    popv(6);
    return nil;
}



/* Code for redall */

static Lisp_Object MS_CDECL CC_redall(Lisp_Object env, int nargs,
                         Lisp_Object v1, Lisp_Object v2,
                         Lisp_Object v46, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "redall");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redall");
#endif
    if (stack >= stacklimit)
    {
        push3(v46,v2,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v1,v2,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v46;
    v88 = v2;
    v87 = v1;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v87; /* gg */
    v87 = v88;
    stack[-6] = v87;
    v87 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v87; /* shortway */
    qvalue(elt(env, 4)) = v87; /* thirdway */
    v87 = qvalue(elt(env, 5)); /* t */
    stack[-1] = v87;
    goto v90;

v90:
    v87 = stack[-6];
    if (v87 == nil) goto v91;
    v87 = stack[-6];
    v87 = Lreverse(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    v87 = qcar(v87);
    stack[-5] = v87;
    v88 = stack[-5];
    v87 = stack[-6];
    v87 = Ldelete(nil, v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    stack[-6] = v87;
    v87 = stack[-5];
    v87 = qcar(v87);
    stack[-2] = v87;
    v88 = qvalue(elt(env, 6)); /* gv */
    v87 = stack[-2];
    v87 = *(Lisp_Object *)((char *)v88 + (CELL-TAG_VECTOR) + ((int32_t)v87/(16/CELL)));
    stack[-4] = v87;
    v87 = qvalue(elt(env, 7)); /* path */
    if (v87 == nil) goto v93;
    v87 = stack[-1];
    if (v87 == nil) goto v20;
    v87 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    v87 = Lprinc(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    v87 = elt(env, 8); /* " ==> " */
    v87 = Lprinc(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    goto v93;

v93:
    stack[-3] = qvalue(elt(env, 6)); /* gv */
    stack[0] = stack[-2];
    v89 = stack[-4];
    v88 = qvalue(elt(env, 1)); /* gg */
    v87 = stack[-7];
    fn = elt(env, 13); /* nf */
    v87 = (*qfnn(fn))(qenv(fn), 3, v89, v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v87;
    stack[-5] = v87;
    v87 = stack[-5];
    if (v87 == nil) goto v94;
    v87 = stack[-5];
    fn = elt(env, 12); /* ljet */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    goto v44;

v44:
    stack[-3] = v87;
    v87 = qvalue(elt(env, 7)); /* path */
    if (v87 == nil) goto v7;
    v87 = stack[-3];
    v87 = Lprinc(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    v87 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    goto v7;

v7:
    v87 = stack[-5];
    if (v87 == nil) goto v90;
    v87 = stack[-3];
    fn = elt(env, 14); /* ord */
    v88 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    v87 = (Lisp_Object)1; /* 0 */
    if (v88 == v87) goto v43;
    v87 = stack[-5];
    fn = elt(env, 12); /* ljet */
    stack[0] = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    v87 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    if (equal(stack[0], v87)) goto v29;
    v87 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 3)) = v87; /* shortway */
    goto v29;

v29:
    v87 = stack[-1];
    if (v87 == nil) goto v95;
    v87 = qvalue(elt(env, 2)); /* nil */
    goto v96;

v96:
    if (v87 == nil) goto v97;
    v87 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 4)) = v87; /* thirdway */
    goto v97;

v97:
    v87 = qvalue(elt(env, 1)); /* gg */
    stack[-4] = v87;
    goto v98;

v98:
    v87 = stack[-4];
    if (v87 == nil) goto v99;
    v87 = stack[-4];
    v87 = qcar(v87);
    stack[-1] = v87;
    v88 = stack[-3];
    v87 = stack[-1];
    v87 = qcdr(v87);
    fn = elt(env, 15); /* dd */
    stack[0] = (*qfn2(fn))(qenv(fn), v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    v88 = stack[-7];
    v87 = (Lisp_Object)33; /* 2 */
    v87 = plus2(v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    v87 = (Lisp_Object)geq2(stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    v87 = v87 ? lisp_true : nil;
    env = stack[-9];
    if (v87 == nil) goto v100;
    v88 = stack[-1];
    v87 = qvalue(elt(env, 1)); /* gg */
    v87 = Ldelete(nil, v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    qvalue(elt(env, 1)) = v87; /* gg */
    v88 = stack[-1];
    v87 = stack[-6];
    fn = elt(env, 16); /* insert */
    v87 = (*qfn2(fn))(qenv(fn), v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    stack[-6] = v87;
    v89 = qvalue(elt(env, 11)); /* bv */
    v87 = stack[-1];
    v88 = qcar(v87);
    v87 = qvalue(elt(env, 5)); /* t */
    *(Lisp_Object *)((char *)v89 + (CELL-TAG_VECTOR) + ((int32_t)v88/(16/CELL))) = v87;
    goto v100;

v100:
    v87 = stack[-4];
    v87 = qcdr(v87);
    stack[-4] = v87;
    goto v98;

v99:
    v88 = stack[-2];
    v87 = stack[-3];
    v88 = cons(v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    v87 = qvalue(elt(env, 1)); /* gg */
    fn = elt(env, 16); /* insert */
    v87 = (*qfn2(fn))(qenv(fn), v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    qvalue(elt(env, 1)) = v87; /* gg */
    v87 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v87;
    goto v90;

v95:
    v88 = stack[-5];
    v87 = stack[-4];
    v87 = Lneq(nil, v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    goto v96;

v43:
    v88 = stack[-5];
    v87 = qvalue(elt(env, 10)); /* conds */
    v87 = cons(v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    qvalue(elt(env, 10)) = v87; /* conds */
    goto v90;

v94:
    v87 = (Lisp_Object)1; /* 0 */
    goto v44;

v20:
    v87 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    v87 = Lprinc(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    v87 = elt(env, 9); /* " --> " */
    v87 = Lprinc(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-9];
    goto v93;

v91:
    v87 = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = stack[-8]; /* gg */
    { popv(10); return onevalue(v87); }
/* error exit handlers */
v92:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-8]; /* gg */
    popv(10);
    return nil;
}



/* Code for tidysqrtf */

static Lisp_Object CC_tidysqrtf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tidysqrtf");
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
    v128 = stack[-1];
    if (!consp(v128)) goto v131;
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = (consp(v128) ? nil : lisp_true);
    goto v132;

v132:
    if (v128 == nil) goto v133;
    v129 = stack[-1];
    v128 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v129, v128);

v133:
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = qcar(v128);
    stack[-2] = v128;
    v128 = stack[-2];
    v129 = qcar(v128);
    v128 = elt(env, 2); /* i */
    if (!(v129 == v128)) goto v134;
    v128 = elt(env, 3); /* (sqrt -1) */
    fn = elt(env, 6); /* fkern */
    v129 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v128 = stack[-2];
    v128 = qcdr(v128);
    fn = elt(env, 7); /* getpower */
    v128 = (*qfn2(fn))(qenv(fn), v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    stack[-2] = v128;
    goto v134;

v134:
    v128 = stack[-2];
    v129 = qcar(v128);
    v128 = elt(env, 4); /* sqrt */
    if (!consp(v129)) goto v136;
    v129 = qcar(v129);
    if (!(v129 == v128)) goto v136;
    v128 = stack[-2];
    v128 = qcdr(v128);
    v128 = Lonep(nil, v128);
    env = stack[-3];
    v128 = (v128 == nil ? lisp_true : nil);
    goto v137;

v137:
    if (v128 == nil) goto v95;
    v128 = stack[-2];
    v129 = qcdr(v128);
    v128 = (Lisp_Object)33; /* 2 */
    v128 = Ldivide(nil, v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    stack[0] = v128;
    v128 = stack[-2];
    v128 = qcar(v128);
    v128 = qcdr(v128);
    v128 = qcar(v128);
    fn = elt(env, 8); /* simp */
    v129 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v128 = stack[0];
    v128 = qcar(v128);
    fn = elt(env, 9); /* exptsq */
    v128 = (*qfn2(fn))(qenv(fn), v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v130 = v128;
    v128 = stack[0];
    v129 = qcdr(v128);
    v128 = (Lisp_Object)1; /* 0 */
    if (v129 == v128) goto v7;
    stack[0] = v130;
    v128 = stack[-2];
    v128 = qcar(v128);
    fn = elt(env, 6); /* fkern */
    v129 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v128 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 7); /* getpower */
    v129 = (*qfn2(fn))(qenv(fn), v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v128 = (Lisp_Object)17; /* 1 */
    v130 = cons(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v129 = qvalue(elt(env, 5)); /* nil */
    v128 = (Lisp_Object)17; /* 1 */
    v128 = acons(v130, v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    fn = elt(env, 10); /* multsq */
    v128 = (*qfn2(fn))(qenv(fn), stack[0], v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v130 = v128;
    goto v7;

v7:
    v128 = v130;
    fn = elt(env, 11); /* tidysqrt */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v130 = v128;
    goto v138;

v138:
    stack[0] = v130;
    v128 = stack[-1];
    v128 = qcar(v128);
    v128 = qcdr(v128);
    v128 = CC_tidysqrtf(env, v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    fn = elt(env, 10); /* multsq */
    v128 = (*qfn2(fn))(qenv(fn), stack[0], v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    stack[-2] = v128;
    stack[0] = stack[-2];
    v128 = stack[-1];
    v128 = qcdr(v128);
    v128 = CC_tidysqrtf(env, v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    {
        Lisp_Object v139 = stack[0];
        popv(4);
        fn = elt(env, 12); /* addsq */
        return (*qfn2(fn))(qenv(fn), v139, v128);
    }

v95:
    v129 = stack[-2];
    v128 = (Lisp_Object)17; /* 1 */
    v130 = cons(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v129 = qvalue(elt(env, 5)); /* nil */
    v128 = (Lisp_Object)17; /* 1 */
    v128 = acons(v130, v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v130 = v128;
    goto v138;

v136:
    v128 = qvalue(elt(env, 5)); /* nil */
    goto v137;

v131:
    v128 = qvalue(elt(env, 1)); /* t */
    goto v132;
/* error exit handlers */
v135:
    popv(4);
    return nil;
}



/* Code for rd!:prin */

static Lisp_Object CC_rdTprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:prin");
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
    v142 = v0;
/* end of prologue */
    v141 = v142;
    v141 = qcdr(v141);
    if (!consp(v141)) goto v53;
    v141 = v142;
    stack[0] = v141;
    goto v127;

v127:
    v142 = qvalue(elt(env, 1)); /* !:bprec!: */
    v141 = (Lisp_Object)49; /* 3 */
    v141 = difference2(v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    fn = elt(env, 2); /* round!:mt */
    v141 = (*qfn2(fn))(qenv(fn), stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    fn = elt(env, 3); /* csl_normbf */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 4); /* bfprin0 */
        return (*qfn1(fn))(qenv(fn), v141);
    }

v53:
    v141 = v142;
    v141 = qcdr(v141);
    fn = elt(env, 5); /* fl2bf */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    stack[0] = v141;
    goto v127;
/* error exit handlers */
v143:
    popv(2);
    return nil;
}



/* Code for processpartitie1list1 */

static Lisp_Object CC_processpartitie1list1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for processpartitie1list1");
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
    v145 = v0;
/* end of prologue */

v47:
    v85 = v145;
    if (v85 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v85 = v145;
    v85 = qcdr(v85);
    stack[-4] = v85;
    stack[-2] = qcar(v145);
    stack[-1] = (Lisp_Object)1; /* 0 */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v145 = qvalue(elt(env, 1)); /* nil */
    v85 = ncons(v145);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v145 = stack[-3];
    fn = elt(env, 2); /* processpartitie1 */
    v145 = (*qfnn(fn))(qenv(fn), 5, stack[-2], stack[-1], stack[0], v85, v145);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-3] = v145;
    v145 = stack[-4];
    goto v47;
/* error exit handlers */
v124:
    popv(6);
    return nil;
}



/* Code for ofsf_smwrmknowl */

static Lisp_Object CC_ofsf_smwrmknowl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwrmknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v26 = v1;
    v104 = v0;
/* end of prologue */
    v25 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v25 == nil) goto v146;
    v25 = v104;
    {
        fn = elt(env, 2); /* ofsf_susirmknowl */
        return (*qfn2(fn))(qenv(fn), v25, v26);
    }

v146:
    v25 = v104;
    {
        fn = elt(env, 3); /* ofsf_smrmknowl */
        return (*qfn2(fn))(qenv(fn), v25, v26);
    }
}



/* Code for mk!+mat!+plus!+mat */

static Lisp_Object CC_mkLmatLplusLmat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v192, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+mat+plus+mat");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v1;
    stack[-11] = v0;
/* end of prologue */
    v191 = stack[-11];
    fn = elt(env, 7); /* matrix!+p */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    if (!(v191 == nil)) goto v53;
    v191 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v191 == nil)) goto v195;
    v191 = elt(env, 2); /* "no matrix in add" */
    fn = elt(env, 8); /* lprie */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    goto v195;

v195:
    v191 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    goto v53;

v53:
    v191 = stack[-10];
    fn = elt(env, 7); /* matrix!+p */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    if (!(v191 == nil)) goto v104;
    v191 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v191 == nil)) goto v22;
    v191 = elt(env, 2); /* "no matrix in add" */
    fn = elt(env, 8); /* lprie */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    goto v22;

v22:
    v191 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    goto v104;

v104:
    v191 = stack[-11];
    fn = elt(env, 9); /* get!+col!+nr */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    stack[-12] = v191;
    v191 = stack[-11];
    fn = elt(env, 10); /* get!+row!+nr */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    stack[-9] = v191;
    stack[0] = stack[-12];
    v191 = stack[-10];
    fn = elt(env, 9); /* get!+col!+nr */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    if (equal(stack[0], v191)) goto v196;
    v191 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v191 == nil)) goto v197;
    v191 = elt(env, 3); /* "wrong dimensions in add" */
    fn = elt(env, 8); /* lprie */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    goto v197;

v197:
    v191 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    goto v196;

v196:
    stack[0] = stack[-9];
    v191 = stack[-10];
    fn = elt(env, 10); /* get!+row!+nr */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    if (equal(stack[0], v191)) goto v198;
    v191 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v191 == nil)) goto v17;
    v191 = elt(env, 3); /* "wrong dimensions in add" */
    fn = elt(env, 8); /* lprie */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    goto v17;

v17:
    v191 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    goto v198;

v198:
    v191 = (Lisp_Object)17; /* 1 */
    stack[-8] = v191;
    v192 = stack[-9];
    v191 = stack[-8];
    v191 = difference2(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = Lminusp(nil, v191);
    env = stack[-13];
    if (v191 == nil) goto v199;
    v191 = qvalue(elt(env, 4)); /* nil */
    { popv(14); return onevalue(v191); }

v199:
    v191 = (Lisp_Object)17; /* 1 */
    stack[-4] = v191;
    v192 = stack[-12];
    v191 = stack[-4];
    v191 = difference2(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = Lminusp(nil, v191);
    env = stack[-13];
    if (v191 == nil) goto v200;
    v191 = qvalue(elt(env, 4)); /* nil */
    goto v201;

v201:
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    stack[-6] = v191;
    stack[-7] = v191;
    goto v44;

v44:
    v191 = stack[-8];
    v191 = add1(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    stack[-8] = v191;
    v192 = stack[-9];
    v191 = stack[-8];
    v191 = difference2(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = Lminusp(nil, v191);
    env = stack[-13];
    if (!(v191 == nil)) { Lisp_Object res = stack[-7]; popv(14); return onevalue(res); }
    stack[-5] = stack[-6];
    v191 = (Lisp_Object)17; /* 1 */
    stack[-4] = v191;
    v192 = stack[-12];
    v191 = stack[-4];
    v191 = difference2(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = Lminusp(nil, v191);
    env = stack[-13];
    if (v191 == nil) goto v202;
    v191 = qvalue(elt(env, 4)); /* nil */
    goto v203;

v203:
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = Lrplacd(nil, stack[-5], v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = stack[-6];
    v191 = qcdr(v191);
    stack[-6] = v191;
    goto v44;

v202:
    v193 = stack[-11];
    v192 = stack[-8];
    v191 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v193 = stack[-10];
    v192 = stack[-8];
    v191 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v191 = (*qfnn(fn))(qenv(fn), 3, v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v191 = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v192 = v191;
    v191 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v191; /* !*sub2 */
    v191 = v192;
    fn = elt(env, 13); /* subs2 */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v192 = v191;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v191 = v192;
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    stack[-2] = v191;
    stack[-3] = v191;
    goto v205;

v205:
    v191 = stack[-4];
    v191 = add1(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    stack[-4] = v191;
    v192 = stack[-12];
    v191 = stack[-4];
    v191 = difference2(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = Lminusp(nil, v191);
    env = stack[-13];
    if (v191 == nil) goto v206;
    v191 = stack[-3];
    goto v203;

v206:
    stack[-1] = stack[-2];
    v193 = stack[-11];
    v192 = stack[-8];
    v191 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v193 = stack[-10];
    v192 = stack[-8];
    v191 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v191 = (*qfnn(fn))(qenv(fn), 3, v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v191 = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v192 = v191;
    v191 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v191; /* !*sub2 */
    v191 = v192;
    fn = elt(env, 13); /* subs2 */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-13];
    v192 = v191;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v191 = v192;
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = Lrplacd(nil, stack[-1], v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = stack[-2];
    v191 = qcdr(v191);
    stack[-2] = v191;
    goto v205;

v200:
    v193 = stack[-11];
    v192 = stack[-8];
    v191 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v193 = stack[-10];
    v192 = stack[-8];
    v191 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v191 = (*qfnn(fn))(qenv(fn), 3, v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v191 = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v192 = v191;
    v191 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v191; /* !*sub2 */
    v191 = v192;
    fn = elt(env, 13); /* subs2 */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-13];
    v192 = v191;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v191 = v192;
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    stack[-2] = v191;
    stack[-3] = v191;
    goto v209;

v209:
    v191 = stack[-4];
    v191 = add1(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    stack[-4] = v191;
    v192 = stack[-12];
    v191 = stack[-4];
    v191 = difference2(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = Lminusp(nil, v191);
    env = stack[-13];
    if (v191 == nil) goto v210;
    v191 = stack[-3];
    goto v201;

v210:
    stack[-1] = stack[-2];
    v193 = stack[-11];
    v192 = stack[-8];
    v191 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v193 = stack[-10];
    v192 = stack[-8];
    v191 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v191 = (*qfnn(fn))(qenv(fn), 3, v193, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v191 = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v192 = v191;
    v191 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v191; /* !*sub2 */
    v191 = v192;
    fn = elt(env, 13); /* subs2 */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-13];
    v192 = v191;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v191 = v192;
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = Lrplacd(nil, stack[-1], v191);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-13];
    v191 = stack[-2];
    v191 = qcdr(v191);
    stack[-2] = v191;
    goto v209;
/* error exit handlers */
v211:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v208:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v207:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v204:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v194:
    popv(14);
    return nil;
}



/* Code for mri_congp */

static Lisp_Object CC_mri_congp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_congp");
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
    v73 = v0;
/* end of prologue */
    fn = elt(env, 2); /* mri_opn */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[0];
    v53 = elt(env, 1); /* (cong ncong) */
    v73 = Lmemq(nil, v73, v53);
    { popv(1); return onevalue(v73); }
/* error exit handlers */
v54:
    popv(1);
    return nil;
}



/* Code for diffrd */

static Lisp_Object MS_CDECL CC_diffrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v125, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "diffrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffrd");
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
    fn = elt(env, 4); /* lex */
    v124 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    v125 = qvalue(elt(env, 1)); /* char */
    v124 = elt(env, 2); /* (b v a r) */
    if (equal(v125, v124)) goto v40;
    v124 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v124;
    v124 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = v124;
    goto v61;

v61:
    fn = elt(env, 5); /* mathml2 */
    v124 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    stack[0] = v124;
    fn = elt(env, 4); /* lex */
    v124 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    v216 = stack[0];
    v125 = stack[-2];
    v124 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* alg_df */
        return (*qfnn(fn))(qenv(fn), 3, v216, v125, v124);
    }

v40:
    fn = elt(env, 7); /* bvarrd */
    v124 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    stack[-2] = v124;
    v124 = stack[-2];
    v124 = qcdr(v124);
    v124 = qcar(v124);
    stack[-1] = v124;
    v124 = stack[-2];
    v124 = qcar(v124);
    stack[-2] = v124;
    fn = elt(env, 4); /* lex */
    v124 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    goto v61;
/* error exit handlers */
v217:
    popv(4);
    return nil;
}



/* Code for ps!:set!-term */

static Lisp_Object MS_CDECL CC_psTsetKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v238, v239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:set-term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:set-term");
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
    v237 = stack[-4];
    fn = elt(env, 9); /* ps!:order */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    stack[-5] = v237;
    v238 = stack[-3];
    v237 = stack[-5];
    v237 = (Lisp_Object)lessp2(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    v237 = v237 ? lisp_true : nil;
    env = stack[-6];
    if (v237 == nil) goto v84;
    v239 = stack[-3];
    v238 = elt(env, 1); /* "less than the order of " */
    v237 = stack[-4];
    v237 = list3(v239, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    v238 = v237;
    v237 = v238;
    qvalue(elt(env, 2)) = v237; /* errmsg!* */
    v237 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v237 == nil)) goto v85;
    v237 = v238;
    fn = elt(env, 10); /* lprie */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    goto v85;

v85:
    v237 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    goto v73;

v73:
    v237 = stack[-4];
    if (!consp(v237)) goto v240;
    v237 = stack[-4];
    v238 = qcar(v237);
    v237 = elt(env, 6); /* !:ps!: */
    if (v238 == v237) goto v8;
    v237 = stack[-4];
    v238 = qcar(v237);
    v237 = elt(env, 7); /* dname */
    v237 = get(v238, v237);
    env = stack[-6];
    goto v17;

v17:
    if (v237 == nil) goto v241;
    v239 = (Lisp_Object)1; /* 0 */
    v238 = stack[-4];
    v237 = (Lisp_Object)17; /* 1 */
    v237 = list2star(v239, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    v237 = ncons(v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    goto v116;

v116:
    stack[0] = v237;
    v237 = stack[-2];
    if (!consp(v237)) goto v242;
    v237 = stack[-2];
    v238 = qcar(v237);
    v237 = qvalue(elt(env, 8)); /* nil */
    v237 = Lneq(nil, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    goto v200;

v200:
    if (v237 == nil) goto v243;
    v237 = stack[0];
    if (v237 == nil) goto v244;
    v238 = stack[-3];
    v237 = stack[-5];
    v238 = difference2(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    v237 = stack[-2];
    v237 = cons(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    v237 = ncons(v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    v237 = Lnconc(nil, stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    goto v245;

v245:
    v239 = stack[-4];
    v238 = (Lisp_Object)17; /* 1 */
    v237 = stack[-3];
    fn = elt(env, 11); /* ps!:putv */
    v237 = (*qfnn(fn))(qenv(fn), 3, v239, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    v237 = nil;
    { popv(7); return onevalue(v237); }

v244:
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)81; /* 5 */
    v238 = stack[-3];
    v237 = stack[-5];
    v238 = difference2(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    v237 = stack[-2];
    v237 = cons(v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    v237 = ncons(v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    fn = elt(env, 11); /* ps!:putv */
    v237 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    goto v245;

v243:
    v238 = stack[-3];
    v237 = stack[-5];
    if (!(equal(v238, v237))) goto v245;
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)1; /* 0 */
    v237 = stack[-3];
    v237 = add1(v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    fn = elt(env, 11); /* ps!:putv */
    v237 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    goto v245;

v242:
    v237 = qvalue(elt(env, 5)); /* t */
    goto v200;

v241:
    v238 = stack[-4];
    v237 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 12); /* ps!:getv */
    v237 = (*qfn2(fn))(qenv(fn), v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    goto v116;

v8:
    v237 = qvalue(elt(env, 8)); /* nil */
    goto v17;

v240:
    v237 = qvalue(elt(env, 5)); /* t */
    goto v17;

v84:
    stack[0] = stack[-3];
    v237 = stack[-4];
    fn = elt(env, 13); /* ps!:last!-term */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    v237 = (Lisp_Object)lesseq2(stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    v237 = v237 ? lisp_true : nil;
    env = stack[-6];
    if (v237 == nil) goto v73;
    v239 = stack[-3];
    v238 = elt(env, 4); /* "less than power of last term of " */
    v237 = stack[-4];
    v237 = list3(v239, v238, v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    v238 = v237;
    v237 = v238;
    qvalue(elt(env, 2)) = v237; /* errmsg!* */
    v237 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v237 == nil)) goto v121;
    v237 = v238;
    fn = elt(env, 10); /* lprie */
    v237 = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    goto v121;

v121:
    v237 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-6];
    goto v73;
/* error exit handlers */
v203:
    popv(7);
    return nil;
}



/* Code for simpu */

static Lisp_Object CC_simpu(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpu");
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
    v213 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* u */
    v212 = v213;
    stack[0] = qcar(v212);
    v212 = v213;
    v212 = qcdr(v212);
    fn = elt(env, 2); /* ordn */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v212 = Lreverse(nil, v212);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v212 = list2star(stack[-1], stack[0], v212);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    fn = elt(env, 3); /* fkern */
    v213 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v212 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* getpower */
    v213 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v212 = (Lisp_Object)17; /* 1 */
    v212 = cons(v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v213 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v212 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v213, v212);
/* error exit handlers */
v124:
    popv(3);
    return nil;
}



/* Code for subs2pf */

static Lisp_Object CC_subs2pf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2pf");
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

v39:
    v85 = stack[0];
    if (v85 == nil) goto v14;
    v85 = stack[0];
    v85 = qcar(v85);
    v85 = qcdr(v85);
    fn = elt(env, 1); /* resimp */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    fn = elt(env, 2); /* subs2 */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v86 = v85;
    v86 = qcar(v86);
    if (v86 == nil) goto v143;
    v86 = stack[0];
    v86 = qcar(v86);
    v212 = qcar(v86);
    v86 = v85;
    v85 = stack[0];
    v85 = qcdr(v85);
    popv(2);
    return acons(v212, v86, v85);

v143:
    v85 = stack[0];
    v85 = qcdr(v85);
    stack[0] = v85;
    goto v39;

v14:
    v85 = nil;
    { popv(2); return onevalue(v85); }
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for divide!-by!-power!-of!-ten */

static Lisp_Object CC_divideKbyKpowerKofKten(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v248, v249;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divide-by-power-of-ten");
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
    v248 = stack[-2];
    v209 = (Lisp_Object)1; /* 0 */
    v209 = (Lisp_Object)lessp2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v209 = v209 ? lisp_true : nil;
    env = stack[-5];
    if (v209 == nil) goto v141;
    stack[0] = (Lisp_Object)1; /* 0 */
    v248 = elt(env, 1); /* "Invalid argument to" */
    v209 = elt(env, 0); /* divide!-by!-power!-of!-ten */
    v209 = list2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    {
        Lisp_Object v32 = stack[0];
        popv(6);
        fn = elt(env, 6); /* error */
        return (*qfn2(fn))(qenv(fn), v32, v209);
    }

v141:
    v209 = qvalue(elt(env, 2)); /* bften!* */
    stack[-4] = v209;
    goto v23;

v23:
    v248 = stack[-2];
    v209 = (Lisp_Object)1; /* 0 */
    v209 = (Lisp_Object)greaterp2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v209 = v209 ? lisp_true : nil;
    env = stack[-5];
    if (v209 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v209 = stack[-2];
    v209 = Levenp(nil, v209);
    env = stack[-5];
    if (!(v209 == nil)) goto v45;
    v249 = stack[-3];
    v248 = stack[-4];
    v209 = qvalue(elt(env, 4)); /* !:bprec!: */
    fn = elt(env, 7); /* divide!: */
    v209 = (*qfnn(fn))(qenv(fn), 3, v249, v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    fn = elt(env, 8); /* csl_normbf */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    stack[-3] = v209;
    goto v45;

v45:
    v248 = stack[-2];
    v209 = (Lisp_Object)-15; /* -1 */
    v209 = ash(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    stack[-2] = v209;
    stack[-1] = elt(env, 5); /* !:rd!: */
    v209 = stack[-4];
    v209 = qcdr(v209);
    v248 = qcar(v209);
    v209 = stack[-4];
    v209 = qcdr(v209);
    v209 = qcar(v209);
    stack[0] = times2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    v209 = stack[-4];
    v209 = qcdr(v209);
    v248 = qcdr(v209);
    v209 = stack[-4];
    v209 = qcdr(v209);
    v209 = qcdr(v209);
    v209 = plus2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    v248 = list2star(stack[-1], stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    v209 = qvalue(elt(env, 4)); /* !:bprec!: */
    fn = elt(env, 9); /* cut!:mt */
    v209 = (*qfn2(fn))(qenv(fn), v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    fn = elt(env, 8); /* csl_normbf */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    stack[-4] = v209;
    goto v23;
/* error exit handlers */
v30:
    popv(6);
    return nil;
}



/* Code for subfindices */

static Lisp_Object CC_subfindices(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v258, v245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subfindices");
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
    stack[-3] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v258 = qvalue(elt(env, 2)); /* nil */
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    qvalue(elt(env, 1)) = v258; /* alglist!* */
    v258 = stack[-2];
    if (!consp(v258)) goto v74;
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = (consp(v258) ? nil : lisp_true);
    goto v54;

v54:
    if (v258 == nil) goto v212;
    v245 = stack[-2];
    v258 = (Lisp_Object)17; /* 1 */
    v258 = cons(v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    goto v14;

v14:
    qvalue(elt(env, 1)) = stack[-3]; /* alglist!* */
    { popv(5); return onevalue(v258); }

v212:
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcar(v258);
    if (!consp(v258)) goto v137;
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcar(v258);
    if (!consp(v258)) goto v16;
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = (consp(v258) ? nil : lisp_true);
    v258 = (v258 == nil ? lisp_true : nil);
    goto v247;

v247:
    if (v258 == nil) goto v114;
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v245 = qcar(v258);
    v258 = stack[-1];
    v245 = CC_subfindices(env, v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcdr(v258);
    fn = elt(env, 6); /* exptsq */
    v258 = (*qfn2(fn))(qenv(fn), v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    stack[0] = v258;
    goto v178;

v178:
    v258 = stack[-2];
    v258 = qcar(v258);
    v245 = qcdr(v258);
    v258 = stack[-1];
    v258 = CC_subfindices(env, v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    fn = elt(env, 7); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v258 = stack[-2];
    v245 = qcdr(v258);
    v258 = stack[-1];
    v258 = CC_subfindices(env, v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    fn = elt(env, 8); /* addsq */
    v258 = (*qfn2(fn))(qenv(fn), stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    goto v14;

v114:
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcar(v258);
    v245 = qcar(v258);
    v258 = elt(env, 4); /* indexvar */
    v258 = Lflagp(nil, v245, v258);
    env = stack[-4];
    if (v258 == nil) goto v184;
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcar(v258);
    stack[0] = qcar(v258);
    v245 = stack[-1];
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcdr(v258);
    v258 = Lsubla(nil, v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v258 = cons(stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    fn = elt(env, 9); /* simpindexvar */
    v245 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcdr(v258);
    fn = elt(env, 6); /* exptsq */
    v258 = (*qfn2(fn))(qenv(fn), v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    stack[0] = v258;
    goto v178;

v184:
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcar(v258);
    v245 = qcar(v258);
    v258 = elt(env, 5); /* (wedge d partdf innerprod liedf hodge vardf) 
*/
    v258 = Lmemq(nil, v245, v258);
    if (v258 == nil) goto v179;
    v245 = stack[-1];
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcar(v258);
    fn = elt(env, 10); /* subindk */
    v258 = (*qfn2(fn))(qenv(fn), v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    fn = elt(env, 11); /* simp */
    v245 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v258 = stack[-2];
    v258 = qcar(v258);
    v258 = qcar(v258);
    v258 = qcdr(v258);
    fn = elt(env, 6); /* exptsq */
    v258 = (*qfn2(fn))(qenv(fn), v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    stack[0] = v258;
    goto v178;

v179:
    v258 = stack[-2];
    v258 = qcar(v258);
    v245 = qcar(v258);
    v258 = (Lisp_Object)17; /* 1 */
    v258 = cons(v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v245 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v258 = (Lisp_Object)17; /* 1 */
    v258 = cons(v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    stack[0] = v258;
    goto v178;

v16:
    v258 = qvalue(elt(env, 2)); /* nil */
    goto v247;

v137:
    v258 = stack[-2];
    v258 = qcar(v258);
    v245 = qcar(v258);
    v258 = (Lisp_Object)17; /* 1 */
    v258 = cons(v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v245 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v258 = (Lisp_Object)17; /* 1 */
    v258 = cons(v245, v258);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    stack[0] = v258;
    goto v178;

v74:
    v258 = qvalue(elt(env, 3)); /* t */
    goto v54;
/* error exit handlers */
v57:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* alglist!* */
    popv(5);
    return nil;
}



/* Code for dfdeg */

static Lisp_Object CC_dfdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfdeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v86 = v1;
    v85 = v0;
/* end of prologue */
    v86 = Lmember(nil, v86, v85);
    v85 = v86;
    if (v86 == nil) goto v14;
    v86 = v85;
    v86 = qcdr(v86);
    if (v86 == nil) goto v195;
    v86 = v85;
    v86 = qcdr(v86);
    v86 = qcar(v86);
    v86 = integerp(v86);
    v86 = (v86 == nil ? lisp_true : nil);
    goto v146;

v146:
    if (v86 == nil) goto v143;
    v85 = (Lisp_Object)17; /* 1 */
    return onevalue(v85);

v143:
    v85 = qcdr(v85);
    v85 = qcar(v85);
    return onevalue(v85);

v195:
    v86 = qvalue(elt(env, 1)); /* t */
    goto v146;

v14:
    v85 = (Lisp_Object)1; /* 0 */
    return onevalue(v85);
}



/* Code for find_triangles1 */

static Lisp_Object CC_find_triangles1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v141, v142, v144, v143, v259;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_triangles1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v140 = v1;
    v141 = v0;
/* end of prologue */
    v259 = qvalue(elt(env, 1)); /* nil */
    v142 = v141;
    v143 = qcar(v142);
    v144 = qvalue(elt(env, 1)); /* nil */
    v142 = v141;
    v142 = qcdr(v142);
    v142 = qcar(v142);
    v141 = qcdr(v141);
    v141 = qcdr(v141);
    v141 = qcar(v141);
    {
        fn = elt(env, 2); /* select_triangles */
        return (*qfnn(fn))(qenv(fn), 6, v259, v143, v144, v142, v141, v140);
    }
}



/* Code for fs!:zerop!: */

static Lisp_Object CC_fsTzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v134, v20;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:zerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */
    v19 = v20;
    if (v19 == nil) goto v10;
    v19 = v20;
    if (is_number(v19)) goto v90;
    v19 = v20;
    v19 = qcdr(v19);
    v19 = (v19 == nil ? lisp_true : nil);
    goto v48;

v48:
    if (v19 == nil) goto v144;
    v19 = qvalue(elt(env, 1)); /* t */
    return onevalue(v19);

v144:
    v19 = v20;
    v134 = qcdr(v19);
    v19 = (Lisp_Object)49; /* 3 */
    v19 = *(Lisp_Object *)((char *)v134 + (CELL-TAG_VECTOR) + ((int32_t)v19/(16/CELL)));
    if (v19 == nil) goto v213;
    v19 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v19);

v213:
    v19 = v20;
    v134 = qcdr(v19);
    v19 = (Lisp_Object)1; /* 0 */
    v19 = *(Lisp_Object *)((char *)v134 + (CELL-TAG_VECTOR) + ((int32_t)v19/(16/CELL)));
    v134 = v19;
    v19 = v134;
    if (is_number(v19)) goto v189;
    v19 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v19);

v189:
    v19 = v134;
        return Lzerop(nil, v19);

v90:
    v19 = qvalue(elt(env, 2)); /* nil */
    goto v48;

v10:
    v19 = qvalue(elt(env, 1)); /* t */
    return onevalue(v19);
}



/* Code for !*g2lex */

static Lisp_Object CC_Hg2lex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *g2lex");
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
    v213 = v0;
/* end of prologue */
    v23 = nil;
    stack[-1] = v213;
    goto v131;

v131:
    v213 = stack[-1];
    if (v213 == nil) { popv(3); return onevalue(v23); }
    v213 = stack[-1];
    v213 = qcar(v213);
    stack[0] = v23;
    v23 = v213;
    v23 = qcar(v23);
    v23 = qcdr(v23);
    v213 = qcdr(v213);
    v213 = cons(v23, v213);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    v213 = ncons(v213);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    fn = elt(env, 2); /* psum */
    v213 = (*qfn2(fn))(qenv(fn), stack[0], v213);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    v23 = v213;
    v213 = stack[-1];
    v213 = qcdr(v213);
    stack[-1] = v213;
    goto v131;
/* error exit handlers */
v125:
    popv(3);
    return nil;
}



/* Code for r2flbf */

static Lisp_Object CC_r2flbf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2flbf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v74 = v0;
/* end of prologue */
    v54 = qvalue(elt(env, 1)); /* !*bftag */
    if (v54 == nil) goto v61;
    v54 = v74;
    {
        fn = elt(env, 2); /* r2bf */
        return (*qfn1(fn))(qenv(fn), v54);
    }

v61:
    v54 = v74;
    {
        fn = elt(env, 3); /* r2fl */
        return (*qfn1(fn))(qenv(fn), v54);
    }
}



/* Code for bfprin0x */

static Lisp_Object CC_bfprin0x(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v145, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfprin0x");
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
/* copy arguments values to proper place */
    v145 = v1;
    v22 = v0;
/* end of prologue */
    fn = elt(env, 1); /* bfexplode0x */
    v22 = (*qfn2(fn))(qenv(fn), v22, v145);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[0];
    v145 = v22;
    v145 = qcdr(v145);
    v145 = qcar(v145);
    v85 = v22;
    v85 = qcdr(v85);
    v85 = qcdr(v85);
    v85 = qcar(v85);
    v22 = qcar(v22);
    {
        popv(1);
        fn = elt(env, 2); /* bfprin!:lst */
        return (*qfnn(fn))(qenv(fn), 3, v22, v145, v85);
    }
/* error exit handlers */
v86:
    popv(1);
    return nil;
}



/* Code for nextu */

static Lisp_Object CC_nextu(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v15, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nextu");
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
    v15 = v1;
    stack[0] = v0;
/* end of prologue */
    v136 = stack[0];
    if (v136 == nil) goto v14;
    v188 = v15;
    v136 = stack[0];
    v15 = qcar(v136);
    v136 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* subtractinds */
    v136 = (*qfnn(fn))(qenv(fn), 3, v188, v15, v136);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    stack[-1] = v136;
    v136 = stack[-1];
    if (v136 == nil) goto v140;
    v136 = stack[0];
    v136 = qcdr(v136);
    v15 = qcar(v136);
    v136 = stack[-1];
    fn = elt(env, 4); /* evaluatecoeffts */
    v136 = (*qfn2(fn))(qenv(fn), v15, v136);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    v188 = v136;
    v136 = v188;
    if (v136 == nil) goto v261;
    v15 = v188;
    v136 = (Lisp_Object)1; /* 0 */
    v136 = (v15 == v136 ? lisp_true : nil);
    goto v84;

v84:
    if (v136 == nil) goto v134;
    v136 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v136); }

v134:
    v15 = stack[-1];
    v136 = stack[0];
    v136 = qcdr(v136);
    v136 = qcdr(v136);
    popv(3);
    return list2star(v15, v188, v136);

v261:
    v136 = qvalue(elt(env, 2)); /* t */
    goto v84;

v140:
    v136 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v136); }

v14:
    v136 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v136); }
/* error exit handlers */
v78:
    popv(3);
    return nil;
}



/* Code for repr_a */

static Lisp_Object CC_repr_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repr_a");
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
    v195 = stack[0];
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    v195 = qcar(v195);
    v195 = Lreverse(nil, v195);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-1];
    v195 = qcar(v195);
    v91 = qcar(v195);
    v195 = stack[0];
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    v195 = qcar(v195);
    {
        popv(2);
        fn = elt(env, 1); /* addf */
        return (*qfn2(fn))(qenv(fn), v91, v195);
    }
/* error exit handlers */
v127:
    popv(2);
    return nil;
}



/* Code for prsubsetrd */

static Lisp_Object CC_prsubsetrd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prsubsetrd");
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
    stack[-3] = nil;
    v81 = qvalue(elt(env, 1)); /* t */
    stack[-1] = v81;
    goto v48;

v48:
    v81 = stack[-3];
    v6 = Llength(nil, v81);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    v81 = (Lisp_Object)17; /* 1 */
    v81 = (Lisp_Object)greaterp2(v6, v81);
    nil = C_nil;
    if (exception_pending()) goto v246;
    v81 = v81 ? lisp_true : nil;
    env = stack[-4];
    if (v81 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v81 = stack[-3];
    stack[0] = qcar(v81);
    v81 = stack[-3];
    v81 = qcar(v81);
    fn = elt(env, 4); /* reval */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    if (equal(stack[0], v81)) goto v141;
    v81 = stack[-3];
    v81 = qcdr(v81);
    stack[0] = qcar(v81);
    v81 = stack[-3];
    v81 = qcdr(v81);
    v81 = qcar(v81);
    fn = elt(env, 4); /* reval */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    v81 = (equal(stack[0], v81) ? lisp_true : nil);
    goto v140;

v140:
    if (v81 == nil) goto v5;
    v81 = nil;
    stack[-3] = v81;
    stack[0] = elt(env, 3); /* prsubset */
    v81 = stack[-2];
    fn = elt(env, 5); /* eval_list_sets */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    v81 = cons(stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    stack[-1] = v81;
    goto v48;

v5:
    v81 = stack[-1];
    if (v81 == nil) goto v121;
    v81 = stack[-3];
    v81 = qcar(v81);
    fn = elt(env, 4); /* reval */
    stack[0] = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    v81 = stack[-3];
    v81 = qcdr(v81);
    v81 = qcar(v81);
    fn = elt(env, 4); /* reval */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    fn = elt(env, 6); /* alg_prsubset */
    v81 = (*qfn2(fn))(qenv(fn), stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    goto v122;

v122:
    stack[-1] = v81;
    v81 = stack[-3];
    v81 = qcdr(v81);
    stack[-3] = v81;
    goto v48;

v121:
    v81 = qvalue(elt(env, 2)); /* nil */
    goto v122;

v141:
    v81 = qvalue(elt(env, 1)); /* t */
    goto v140;
/* error exit handlers */
v246:
    popv(5);
    return nil;
}



/* Code for i2ps */

static Lisp_Object CC_i2ps(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v46;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2ps");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v46 = v0;
/* end of prologue */
    return onevalue(v46);
}



/* Code for groebcplistmerge */

static Lisp_Object CC_groebcplistmerge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistmerge");
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
    v122 = stack[-2];
    if (v122 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v122 = stack[-1];
    if (v122 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v122 = stack[-2];
    v122 = qcar(v122);
    stack[-3] = v122;
    v122 = stack[-1];
    v122 = qcar(v122);
    stack[0] = v122;
    v121 = stack[-3];
    v122 = stack[0];
    fn = elt(env, 1); /* groebcpcompless!? */
    v122 = (*qfn2(fn))(qenv(fn), v121, v122);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    if (v122 == nil) goto v263;
    stack[0] = stack[-3];
    v122 = stack[-2];
    v121 = qcdr(v122);
    v122 = stack[-1];
    v122 = CC_groebcplistmerge(env, v121, v122);
    nil = C_nil;
    if (exception_pending()) goto v136;
    {
        Lisp_Object v15 = stack[0];
        popv(5);
        return cons(v15, v122);
    }

v263:
    v121 = stack[-2];
    v122 = stack[-1];
    v122 = qcdr(v122);
    v122 = CC_groebcplistmerge(env, v121, v122);
    nil = C_nil;
    if (exception_pending()) goto v136;
    {
        Lisp_Object v188 = stack[0];
        popv(5);
        return cons(v188, v122);
    }
/* error exit handlers */
v136:
    popv(5);
    return nil;
}



/* Code for multsqpf */

static Lisp_Object CC_multsqpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v262;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multsqpf");
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
    stack[-3] = nil;
    goto v47;

v47:
    v217 = stack[-1];
    if (v217 == nil) goto v54;
    v217 = stack[-2];
    v217 = qcar(v217);
    v217 = (v217 == nil ? lisp_true : nil);
    goto v53;

v53:
    if (v217 == nil) goto v26;
    v217 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v217);
    }

v26:
    v217 = stack[-1];
    v217 = qcar(v217);
    stack[0] = qcar(v217);
    v262 = stack[-2];
    v217 = stack[-1];
    v217 = qcar(v217);
    v217 = qcdr(v217);
    fn = elt(env, 3); /* multsq */
    v262 = (*qfn2(fn))(qenv(fn), v262, v217);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    v217 = stack[-3];
    v217 = acons(stack[0], v262, v217);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    stack[-3] = v217;
    v217 = stack[-1];
    v217 = qcdr(v217);
    stack[-1] = v217;
    goto v47;

v54:
    v217 = qvalue(elt(env, 1)); /* t */
    goto v53;
/* error exit handlers */
v190:
    popv(5);
    return nil;
}



/* Code for !*kp2q */

static Lisp_Object CC_Hkp2q(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *kp2q");
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
    v198 = stack[0];
    v45 = (Lisp_Object)1; /* 0 */
    v45 = (Lisp_Object)greaterp2(v198, v45);
    nil = C_nil;
    if (exception_pending()) goto v196;
    v45 = v45 ? lisp_true : nil;
    env = stack[-2];
    if (v45 == nil) goto v47;
    v198 = stack[-1];
    v45 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* mksq */
        return (*qfn2(fn))(qenv(fn), v198, v45);
    }

v47:
    v45 = stack[0];
    v45 = (Lisp_Object)zerop(v45);
    v45 = v45 ? lisp_true : nil;
    env = stack[-2];
    if (v45 == nil) goto v212;
    v198 = (Lisp_Object)17; /* 1 */
    v45 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v198, v45);

v212:
    v45 = stack[0];
    v45 = negate(v45);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    fn = elt(env, 3); /* mksq */
    v45 = (*qfn2(fn))(qenv(fn), stack[-1], v45);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    stack[-1] = v45;
    v45 = qcar(v45);
    if (v45 == nil) goto v21;
    v45 = stack[-1];
    v198 = qcdr(v45);
    v45 = stack[-1];
    v45 = qcar(v45);
    popv(3);
    return cons(v198, v45);

v21:
    v45 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v45 == nil)) goto v217;
    v45 = elt(env, 2); /* "Zero divisor" */
    fn = elt(env, 4); /* lprie */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    goto v217;

v217:
    v45 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v196;
    v45 = nil;
    { popv(3); return onevalue(v45); }
/* error exit handlers */
v196:
    popv(3);
    return nil;
}



/* Code for gcdld */

static Lisp_Object CC_gcdld(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v120, v137, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdld");
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
    v120 = v1;
    v137 = v0;
/* end of prologue */

v48:
    v197 = v120;
    v42 = (Lisp_Object)17; /* 1 */
    if (v197 == v42) goto v54;
    v197 = v120;
    v42 = (Lisp_Object)-15; /* -1 */
    v42 = (v197 == v42 ? lisp_true : nil);
    goto v53;

v53:
    if (v42 == nil) goto v40;
    v42 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v42); }

v40:
    v42 = v137;
    if (v42 == nil) goto v259;
    v42 = v137;
    v42 = qcar(v42);
    if (v42 == nil) goto v86;
    v42 = v137;
    v42 = qcdr(v42);
    stack[0] = v42;
    v42 = v120;
    v120 = v137;
    v120 = qcar(v120);
    fn = elt(env, 2); /* gcd!-with!-number */
    v42 = (*qfn2(fn))(qenv(fn), v42, v120);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v120 = v42;
    v42 = stack[0];
    v137 = v42;
    goto v48;

v86:
    v42 = v137;
    v42 = qcdr(v42);
    v137 = v42;
    goto v48;

v259:
    v42 = v120;
        popv(2);
        return Labsval(nil, v42);

v54:
    v42 = qvalue(elt(env, 1)); /* t */
    goto v53;
/* error exit handlers */
v19:
    popv(2);
    return nil;
}



/* Code for dfp!-rule!-found */

static Lisp_Object CC_dfpKruleKfound(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v140, v141, v142;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfp-rule-found");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v141 = v1;
    v142 = v0;
/* end of prologue */
    v140 = v142;
    v104 = elt(env, 1); /* dfp */
    if (!consp(v140)) goto v14;
    v140 = qcar(v140);
    if (!(v140 == v104)) goto v14;
    v104 = v142;
    v104 = qcdr(v104);
    v104 = qcar(v104);
    v140 = v141;
        return Lneq(nil, v104, v140);

v14:
    v104 = qvalue(elt(env, 2)); /* t */
    return onevalue(v104);
}



/* Code for fs!:minusp */

static Lisp_Object CC_fsTminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v23, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v23 = v0;
/* end of prologue */

v10:
    v213 = v23;
    if (v213 == nil) goto v132;
    v24 = v23;
    v213 = (Lisp_Object)49; /* 3 */
    v213 = *(Lisp_Object *)((char *)v24 + (CELL-TAG_VECTOR) + ((int32_t)v213/(16/CELL)));
    if (v213 == nil) goto v126;
    v213 = (Lisp_Object)49; /* 3 */
    v213 = *(Lisp_Object *)((char *)v23 + (CELL-TAG_VECTOR) + ((int32_t)v213/(16/CELL)));
    v23 = v213;
    goto v10;

v126:
    v213 = (Lisp_Object)1; /* 0 */
    v213 = *(Lisp_Object *)((char *)v23 + (CELL-TAG_VECTOR) + ((int32_t)v213/(16/CELL)));
    v213 = qcar(v213);
    {
        fn = elt(env, 2); /* minusf */
        return (*qfn1(fn))(qenv(fn), v213);
    }

v132:
    v213 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v213);
}



/* Code for mo_zero!? */

static Lisp_Object CC_mo_zeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_zero?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v14 = v0;
/* end of prologue */
    v14 = qcar(v14);
    {
        fn = elt(env, 1); /* mo!=zero */
        return (*qfn1(fn))(qenv(fn), v14);
    }
}



/* Code for quotfail!-in!-vector */

static Lisp_Object MS_CDECL CC_quotfailKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v46, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v273, v274, v163, v202, v275, v276, v277, v278;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "quotfail-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push4(v46,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v46;
    stack[-2] = v2;
    v163 = v1;
    stack[-3] = v0;
/* end of prologue */
    v274 = v163;
    v273 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v274)) < ((int32_t)(v273))) { popv(6); return onevalue(v163); }
    v274 = stack[-1];
    v273 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v274)) < ((int32_t)(v273))) goto v214;
    v274 = v163;
    v273 = stack[-1];
    if (((int32_t)(v274)) < ((int32_t)(v273))) goto v104;
    v274 = v163;
    v273 = stack[-1];
    v273 = (Lisp_Object)(int32_t)((int32_t)v274 - (int32_t)v273 + TAG_FIXNUM);
    stack[-4] = v273;
    v273 = stack[-4];
    stack[0] = v273;
    goto v123;

v123:
    v273 = stack[0];
    v273 = ((intptr_t)(v273) < 0 ? lisp_true : nil);
    if (v273 == nil) goto v196;
    v273 = (Lisp_Object)1; /* 0 */
    stack[0] = v273;
    goto v174;

v174:
    v273 = stack[-1];
    v274 = (Lisp_Object)((int32_t)(v273) - 0x10);
    v273 = stack[0];
    v273 = (Lisp_Object)(int32_t)((int32_t)v274 - (int32_t)v273 + TAG_FIXNUM);
    v273 = ((intptr_t)(v273) < 0 ? lisp_true : nil);
    if (v273 == nil) goto v176;
    v273 = (Lisp_Object)1; /* 0 */
    v276 = v273;
    goto v173;

v173:
    v274 = stack[-4];
    v273 = v276;
    v273 = (Lisp_Object)(int32_t)((int32_t)v274 - (int32_t)v273 + TAG_FIXNUM);
    v273 = ((intptr_t)(v273) < 0 ? lisp_true : nil);
    if (!(v273 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v275 = stack[-3];
    v202 = v276;
    v163 = stack[-3];
    v274 = stack[-1];
    v273 = v276;
    v273 = (Lisp_Object)(int32_t)((int32_t)v274 + (int32_t)v273 - TAG_FIXNUM);
    v273 = *(Lisp_Object *)((char *)v163 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL)));
    *(Lisp_Object *)((char *)v275 + (CELL-TAG_VECTOR) + ((int32_t)v202/(16/CELL))) = v273;
    v273 = v276;
    v273 = (Lisp_Object)((int32_t)(v273) + 0x10);
    v276 = v273;
    goto v173;

v176:
    v274 = stack[-3];
    v273 = stack[0];
    v274 = *(Lisp_Object *)((char *)v274 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL)));
    v273 = (Lisp_Object)1; /* 0 */
    if (v274 == v273) goto v279;
    v273 = elt(env, 4); /* "Quotient not exact in QUOTFAIL!-IN!-VECTOR" 
*/
    fn = elt(env, 5); /* errorf */
    v273 = (*qfn1(fn))(qenv(fn), v273);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-5];
    goto v279;

v279:
    v273 = stack[0];
    v273 = (Lisp_Object)((int32_t)(v273) + 0x10);
    stack[0] = v273;
    goto v174;

v196:
    v163 = stack[-3];
    v274 = stack[-1];
    v273 = stack[0];
    v273 = (Lisp_Object)(int32_t)((int32_t)v274 + (int32_t)v273 - TAG_FIXNUM);
    v163 = *(Lisp_Object *)((char *)v163 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL)));
    v274 = stack[-2];
    v273 = stack[-1];
    v273 = *(Lisp_Object *)((char *)v274 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL)));
    v273 = Lmodular_quotient(nil, v163, v273);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-5];
    v278 = v273;
    v273 = (Lisp_Object)1; /* 0 */
    v277 = v273;
    goto v12;

v12:
    v273 = stack[-1];
    v274 = (Lisp_Object)((int32_t)(v273) - 0x10);
    v273 = v277;
    v273 = (Lisp_Object)(int32_t)((int32_t)v274 - (int32_t)v273 + TAG_FIXNUM);
    v273 = ((intptr_t)(v273) < 0 ? lisp_true : nil);
    if (v273 == nil) goto v115;
    v163 = stack[-3];
    v274 = stack[-1];
    v273 = stack[0];
    v273 = (Lisp_Object)(int32_t)((int32_t)v274 + (int32_t)v273 - TAG_FIXNUM);
    v274 = v278;
    *(Lisp_Object *)((char *)v163 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL))) = v274;
    v273 = stack[0];
    v273 = (Lisp_Object)((int32_t)(v273) - 0x10);
    stack[0] = v273;
    goto v123;

v115:
    v276 = stack[-3];
    v274 = stack[0];
    v273 = v277;
    v275 = (Lisp_Object)(int32_t)((int32_t)v274 + (int32_t)v273 - TAG_FIXNUM);
    v163 = stack[-3];
    v274 = stack[0];
    v273 = v277;
    v273 = (Lisp_Object)(int32_t)((int32_t)v274 + (int32_t)v273 - TAG_FIXNUM);
    v202 = *(Lisp_Object *)((char *)v163 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL)));
    v163 = v278;
    v274 = stack[-2];
    v273 = v277;
    v273 = *(Lisp_Object *)((char *)v274 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL)));
    v273 = Lmodular_times(nil, v163, v273);
    env = stack[-5];
    {   int32_t w = int_of_fixnum(v202) - int_of_fixnum(v273);
        if (w < 0) w += current_modulus;
        v273 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v276 + (CELL-TAG_VECTOR) + ((int32_t)v275/(16/CELL))) = v273;
    v273 = v277;
    v273 = (Lisp_Object)((int32_t)(v273) + 0x10);
    v277 = v273;
    goto v12;

v104:
    v273 = elt(env, 2); /* "Bad degrees in QUOTFAIL-IN-VECTOR" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v273);
    }

v214:
    v273 = elt(env, 1); /* "Attempt to divide by zero" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v273);
    }
/* error exit handlers */
v164:
    popv(6);
    return nil;
}



/* Code for !*n2a */

static Lisp_Object CC_Hn2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *n2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v127 = v0;
/* end of prologue */
    v90 = v127;
    v90 = integerp(v90);
    if (!(v90 == nil)) return onevalue(v127);
    v90 = qvalue(elt(env, 1)); /* !*nosq */
    if (v90 == nil) goto v54;
    v90 = v127;
    {
        fn = elt(env, 2); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v90);
    }

v54:
    v90 = v127;
    {
        fn = elt(env, 3); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v90);
    }
}



/* Code for sgn1 */

static Lisp_Object CC_sgn1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v248;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sgn1");
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
    v248 = v1;
    stack[-4] = v0;
/* end of prologue */
    v209 = stack[-4];
    if (!consp(v209)) goto v54;
    v209 = v248;
    v209 = qcar(v209);
    stack[-2] = v209;
    v209 = v248;
    v209 = qcdr(v209);
    stack[-1] = v209;
    v209 = (Lisp_Object)1; /* 0 */
    stack[-3] = v209;
    v209 = (Lisp_Object)17; /* 1 */
    stack[-5] = v209;
    v209 = stack[-4];
    v209 = qcdr(v209);
    stack[-4] = v209;
    goto v137;

v137:
    v248 = stack[-5];
    v209 = stack[-4];
    v209 = qcar(v209);
    stack[0] = times2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-6];
    v248 = stack[-2];
    v209 = stack[-3];
    v209 = times2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-6];
    v209 = plus2(stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-6];
    stack[-3] = v209;
    v248 = stack[-5];
    v209 = stack[-1];
    v209 = times2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-6];
    stack[-5] = v209;
    v209 = stack[-4];
    v209 = qcdr(v209);
    stack[-4] = v209;
    if (!(v209 == nil)) goto v137;
    v248 = stack[-3];
    v209 = (Lisp_Object)1; /* 0 */
    v209 = (Lisp_Object)greaterp2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v209 = v209 ? lisp_true : nil;
    env = stack[-6];
    if (v209 == nil) goto v257;
    v209 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v209); }

v257:
    v248 = stack[-3];
    v209 = (Lisp_Object)1; /* 0 */
    v209 = (Lisp_Object)lessp2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v209 = v209 ? lisp_true : nil;
    if (v209 == nil) goto v114;
    v209 = (Lisp_Object)-15; /* -1 */
    { popv(7); return onevalue(v209); }

v114:
    v209 = (Lisp_Object)1; /* 0 */
    { popv(7); return onevalue(v209); }

v54:
    v248 = stack[-4];
    v209 = (Lisp_Object)1; /* 0 */
    v209 = (Lisp_Object)greaterp2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v209 = v209 ? lisp_true : nil;
    env = stack[-6];
    if (v209 == nil) goto v126;
    v209 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v209); }

v126:
    v248 = stack[-4];
    v209 = (Lisp_Object)1; /* 0 */
    v209 = (Lisp_Object)lessp2(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v209 = v209 ? lisp_true : nil;
    if (v209 == nil) goto v144;
    v209 = (Lisp_Object)-15; /* -1 */
    { popv(7); return onevalue(v209); }

v144:
    v209 = (Lisp_Object)1; /* 0 */
    { popv(7); return onevalue(v209); }
/* error exit handlers */
v30:
    popv(7);
    return nil;
}



/* Code for ofsf_lnegrel */

static Lisp_Object CC_ofsf_lnegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v17, v240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_lnegrel");
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
    v240 = v0;
/* end of prologue */
    v17 = v240;
    v79 = elt(env, 1); /* equal */
    if (v17 == v79) goto v10;
    v17 = v240;
    v79 = elt(env, 2); /* neq */
    if (v17 == v79) goto v74;
    v17 = v240;
    v79 = elt(env, 3); /* leq */
    if (v17 == v79) goto v126;
    v17 = v240;
    v79 = elt(env, 5); /* lessp */
    if (v17 == v79) goto v259;
    v17 = v240;
    v79 = elt(env, 6); /* geq */
    if (v17 == v79) goto v124;
    v17 = v240;
    v79 = elt(env, 4); /* greaterp */
    if (v17 == v79) goto v35;
    v79 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v79 == nil)) goto v45;
    v79 = elt(env, 8); /* "ofsf_lnegrel: unknown operator " */
    v17 = v240;
    v79 = list2(v79, v17);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[0];
    fn = elt(env, 9); /* lprie */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[0];
    goto v45;

v45:
    v79 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v272;
    v79 = nil;
    { popv(1); return onevalue(v79); }

v35:
    v79 = elt(env, 3); /* leq */
    { popv(1); return onevalue(v79); }

v124:
    v79 = elt(env, 5); /* lessp */
    { popv(1); return onevalue(v79); }

v259:
    v79 = elt(env, 6); /* geq */
    { popv(1); return onevalue(v79); }

v126:
    v79 = elt(env, 4); /* greaterp */
    { popv(1); return onevalue(v79); }

v74:
    v79 = elt(env, 1); /* equal */
    { popv(1); return onevalue(v79); }

v10:
    v79 = elt(env, 2); /* neq */
    { popv(1); return onevalue(v79); }
/* error exit handlers */
v272:
    popv(1);
    return nil;
}



/* Code for pickbasicset */

static Lisp_Object CC_pickbasicset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pickbasicset");
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
    stack[-3] = nil;
    v209 = qvalue(elt(env, 1)); /* wuvarlist!* */
    stack[-1] = v209;
    goto v131;

v131:
    v209 = stack[-1];
    if (v209 == nil) goto v132;
    v209 = stack[-1];
    v209 = qcar(v209);
    stack[0] = v209;
    goto v91;

v91:
    v209 = stack[-2];
    if (v209 == nil) goto v216;
    v209 = stack[-2];
    v209 = qcar(v209);
    v209 = qcar(v209);
    v209 = qcar(v209);
    v248 = qcar(v209);
    v209 = stack[0];
    fn = elt(env, 3); /* symbollessp */
    v209 = (*qfn2(fn))(qenv(fn), v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-4];
    if (v209 == nil) goto v216;
    v209 = stack[-2];
    v209 = qcdr(v209);
    stack[-2] = v209;
    goto v91;

v216:
    v209 = stack[-2];
    if (v209 == nil) goto v125;
    v248 = stack[0];
    v209 = stack[-2];
    v209 = qcar(v209);
    v209 = qcar(v209);
    v209 = qcar(v209);
    v209 = qcar(v209);
    if (equal(v248, v209)) goto v198;
    v209 = qvalue(elt(env, 2)); /* nil */
    goto v123;

v123:
    if (v209 == nil) goto v125;
    v209 = stack[-2];
    v209 = qcdr(v209);
    stack[-2] = v209;
    goto v216;

v125:
    v209 = stack[-2];
    if (v209 == nil) goto v272;
    v248 = stack[0];
    v209 = stack[-2];
    v209 = qcar(v209);
    v209 = qcar(v209);
    v209 = qcar(v209);
    v209 = qcar(v209);
    if (!(equal(v248, v209))) goto v272;
    v209 = stack[-2];
    v248 = qcar(v209);
    v209 = stack[-3];
    v209 = cons(v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-4];
    stack[-3] = v209;
    v209 = stack[-2];
    v209 = qcdr(v209);
    stack[-2] = v209;
    goto v272;

v272:
    v209 = stack[-1];
    v209 = qcdr(v209);
    stack[-1] = v209;
    goto v131;

v198:
    v209 = stack[-2];
    v248 = qcar(v209);
    v209 = stack[-3];
    fn = elt(env, 4); /* wureducedpolysp */
    v209 = (*qfn2(fn))(qenv(fn), v248, v209);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-4];
    v209 = (v209 == nil ? lisp_true : nil);
    goto v123;

v132:
    v209 = stack[-3];
        popv(5);
        return Lnreverse(nil, v209);
/* error exit handlers */
v109:
    popv(5);
    return nil;
}



/* Code for pasf_smordtable2 */

static Lisp_Object CC_pasf_smordtable2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v126, v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smordtable2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v127 = v1;
    v126 = v0;
/* end of prologue */
    v133 = elt(env, 1); /* ((lessp (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong nil)) (leq (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil)
 (ncong nil)) (equal (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)) (neq (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong 
nil)) (geq (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)) (greaterp (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong
 nil))) */
    v126 = Latsoc(nil, v126, v133);
    v127 = Latsoc(nil, v127, v126);
    v127 = qcdr(v127);
    return onevalue(v127);
}



/* Code for cols2rows2 */

static Lisp_Object CC_cols2rows2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cols2rows2");
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
    v212 = stack[0];
    v86 = (Lisp_Object)1; /* 0 */
    if (v212 == v86) goto v47;
    v212 = stack[-1];
    v86 = stack[0];
    fn = elt(env, 1); /* ithlistelem */
    stack[-2] = (*qfn2(fn))(qenv(fn), v212, v86);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    v86 = stack[0];
    v86 = sub1(v86);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    v86 = CC_cols2rows2(env, stack[-1], v86);
    nil = C_nil;
    if (exception_pending()) goto v124;
    {
        Lisp_Object v125 = stack[-2];
        popv(4);
        return cons(v125, v86);
    }

v47:
    v86 = nil;
    { popv(4); return onevalue(v86); }
/* error exit handlers */
v124:
    popv(4);
    return nil;
}



/* Code for ps!:arg!-values */

static Lisp_Object CC_psTargKvalues(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v95, v271;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:arg-values");
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
    v95 = v0;
/* end of prologue */
    v107 = v95;
    stack[-4] = qcar(v107);
    v107 = v95;
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) goto v195;
    v107 = stack[-3];
    v107 = qcar(v107);
    v271 = v107;
    v107 = v271;
    if (!consp(v107)) goto v259;
    v107 = v271;
    v95 = qcar(v107);
    v107 = elt(env, 3); /* !:ps!: */
    if (v95 == v107) goto v137;
    v107 = v271;
    v95 = qcar(v107);
    v107 = elt(env, 4); /* dname */
    v107 = get(v95, v107);
    env = stack[-5];
    goto v143;

v143:
    if (v107 == nil) goto v142;
    v107 = v271;
    goto v140;

v140:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    stack[-1] = v107;
    stack[-2] = v107;
    goto v48;

v48:
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    v107 = stack[-3];
    if (v107 == nil) goto v284;
    stack[0] = stack[-1];
    v107 = stack[-3];
    v107 = qcar(v107);
    v271 = v107;
    v107 = v271;
    if (!consp(v107)) goto v187;
    v107 = v271;
    v95 = qcar(v107);
    v107 = elt(env, 3); /* !:ps!: */
    if (v95 == v107) goto v76;
    v107 = v271;
    v95 = qcar(v107);
    v107 = elt(env, 4); /* dname */
    v107 = get(v95, v107);
    env = stack[-5];
    goto v186;

v186:
    if (v107 == nil) goto v257;
    v107 = v271;
    goto v12;

v12:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-1] = v107;
    goto v48;

v257:
    v107 = v271;
    v107 = Lconsp(nil, v107);
    env = stack[-5];
    if (v107 == nil) goto v232;
    v107 = v271;
    v95 = qcar(v107);
    v107 = elt(env, 3); /* !:ps!: */
    if (!(v95 == v107)) goto v232;
    v107 = v271;
    fn = elt(env, 5); /* ps!:value */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v12;

v232:
    v107 = v271;
    v107 = CC_psTargKvalues(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v12;

v76:
    v107 = qvalue(elt(env, 1)); /* nil */
    goto v186;

v187:
    v107 = qvalue(elt(env, 2)); /* t */
    goto v186;

v284:
    v107 = stack[-2];
    goto v47;

v47:
    {
        Lisp_Object v106 = stack[-4];
        popv(6);
        return cons(v106, v107);
    }

v142:
    v107 = v271;
    v107 = Lconsp(nil, v107);
    env = stack[-5];
    if (v107 == nil) goto v280;
    v107 = v271;
    v95 = qcar(v107);
    v107 = elt(env, 3); /* !:ps!: */
    if (!(v95 == v107)) goto v280;
    v107 = v271;
    fn = elt(env, 5); /* ps!:value */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v140;

v280:
    v107 = v271;
    v107 = CC_psTargKvalues(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v140;

v137:
    v107 = qvalue(elt(env, 1)); /* nil */
    goto v143;

v259:
    v107 = qvalue(elt(env, 2)); /* t */
    goto v143;

v195:
    v107 = qvalue(elt(env, 1)); /* nil */
    goto v47;
/* error exit handlers */
v105:
    popv(6);
    return nil;
}



/* Code for letmtr */

static Lisp_Object MS_CDECL CC_letmtr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v187, v234, v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "letmtr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letmtr");
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
    v187 = stack[0];
    v186 = elt(env, 1); /* mat */
    if (!consp(v187)) goto v195;
    v187 = qcar(v187);
    if (!(v187 == v186)) goto v195;
    v186 = stack[-2];
    v186 = qcdr(v186);
    fn = elt(env, 11); /* revlis */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    stack[-3] = v186;
    fn = elt(env, 12); /* numlis */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    if (v186 == nil) goto v83;
    v186 = stack[-3];
    v187 = Llength(nil, v186);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v186 = (Lisp_Object)33; /* 2 */
    v186 = Lneq(nil, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    goto v216;

v216:
    if (v186 == nil) goto v6;
    v9 = elt(env, 7); /* "Syntax error:" */
    v8 = stack[-2];
    v234 = elt(env, 8); /* "invalid" */
    v187 = qvalue(elt(env, 9)); /* nil */
    v186 = elt(env, 10); /* hold */
    {
        popv(5);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v9, v8, v234, v187, v186);
    }

v6:
    v186 = stack[0];
    v187 = qcdr(v186);
    v186 = stack[-3];
    v186 = qcar(v186);
    fn = elt(env, 14); /* pnth */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v187 = qcar(v186);
    v186 = stack[-3];
    v186 = qcdr(v186);
    v186 = qcar(v186);
    fn = elt(env, 14); /* pnth */
    v187 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v186 = stack[-1];
    v186 = Lrplaca(nil, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v209;
    v186 = nil;
    { popv(5); return onevalue(v186); }

v83:
    v186 = qvalue(elt(env, 6)); /* t */
    goto v216;

v195:
    v234 = elt(env, 2); /* "Matrix" */
    v186 = stack[-2];
    v187 = qcar(v186);
    v186 = elt(env, 3); /* "not set" */
    v186 = list3(v234, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v187 = v186;
    v186 = v187;
    qvalue(elt(env, 4)) = v186; /* errmsg!* */
    v186 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v186 == nil)) goto v22;
    v186 = v187;
    fn = elt(env, 15); /* lprie */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    goto v22;

v22:
    v186 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    goto v6;
/* error exit handlers */
v209:
    popv(5);
    return nil;
}



/* Code for chksymmetries!&sub1 */

static Lisp_Object MS_CDECL CC_chksymmetriesGsub1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v46, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v23, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "chksymmetries&sub1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chksymmetries&sub1");
#endif
    if (stack >= stacklimit)
    {
        push4(v46,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    v213 = v2;
    v23 = v1;
    v24 = v0;
/* end of prologue */
    v213 = Lsubst(nil, 3, v24, v23, v213);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-2];
    stack[-1] = v213;
    v213 = stack[0];
    if (v213 == nil) goto v127;
    v23 = stack[-1];
    v213 = stack[0];
    fn = elt(env, 3); /* indxsymp */
    v213 = (*qfn2(fn))(qenv(fn), v23, v213);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-2];
    goto v90;

v90:
    if (!(v213 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v213 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v213); }

v127:
    v213 = qvalue(elt(env, 1)); /* t */
    goto v90;
/* error exit handlers */
v216:
    popv(3);
    return nil;
}



/* Code for coeff_calc */

static Lisp_Object MS_CDECL CC_coeff_calc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v126, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff_calc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeff_calc");
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
    push(nil);
/* copy arguments values to proper place */
    v127 = v2;
    v126 = v1;
    v133 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* plus */
    fn = elt(env, 2); /* coeff1_calc */
    v127 = (*qfnn(fn))(qenv(fn), 3, v133, v126, v127);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    v127 = cons(stack[0], v127);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* reval */
        return (*qfn1(fn))(qenv(fn), v127);
    }
/* error exit handlers */
v26:
    popv(2);
    return nil;
}



/* Code for xremf */

static Lisp_Object MS_CDECL CC_xremf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v304, v305, v306;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xremf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xremf");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v2;
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-1] = nil;
    v304 = (Lisp_Object)1; /* 0 */
    stack[-8] = v304;
    v304 = stack[-6];
    if (!consp(v304)) goto v90;
    v304 = stack[-6];
    v304 = qcar(v304);
    v304 = (consp(v304) ? nil : lisp_true);
    goto v91;

v91:
    if (v304 == nil) goto v214;
    v305 = stack[-7];
    v304 = stack[-6];
    fn = elt(env, 3); /* qremd */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    v304 = qcdr(v304);
    popv(10);
    return ncons(v304);

v214:
    v304 = stack[-7];
    fn = elt(env, 4); /* termsf */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[0] = v304;
    goto v84;

v84:
    v305 = stack[-5];
    v304 = (Lisp_Object)1; /* 0 */
    v304 = (Lisp_Object)lesseq2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    v304 = v304 ? lisp_true : nil;
    env = stack[-9];
    if (v304 == nil) goto v216;
    v304 = qvalue(elt(env, 2)); /* nil */
    { popv(10); return onevalue(v304); }

v216:
    v304 = stack[-7];
    if (!consp(v304)) goto v120;
    v304 = stack[-7];
    v304 = qcar(v304);
    v304 = (consp(v304) ? nil : lisp_true);
    goto v42;

v42:
    if (v304 == nil) goto v116;
    v305 = stack[-1];
    v304 = stack[-7];
    fn = elt(env, 5); /* addf */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    popv(10);
    return ncons(v304);

v116:
    v304 = stack[-7];
    v304 = qcar(v304);
    v304 = qcar(v304);
    v305 = qcar(v304);
    v304 = stack[-6];
    v304 = qcar(v304);
    v304 = qcar(v304);
    v304 = qcar(v304);
    if (v305 == v304) goto v11;
    v304 = stack[-7];
    v304 = qcar(v304);
    v304 = qcar(v304);
    v305 = qcar(v304);
    v304 = stack[-6];
    v304 = qcar(v304);
    v304 = qcar(v304);
    v304 = qcar(v304);
    fn = elt(env, 6); /* ordop */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    if (v304 == nil) goto v308;
    v305 = stack[-5];
    v304 = stack[-8];
    v304 = plus2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-5] = v304;
    v304 = stack[-7];
    v304 = qcar(v304);
    v306 = qcdr(v304);
    v305 = stack[-6];
    v304 = stack[-5];
    v304 = CC_xremf(env, 3, v306, v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-3] = v304;
    v304 = stack[-3];
    if (v304 == nil) goto v309;
    v304 = stack[-7];
    v304 = qcar(v304);
    v305 = qcar(v304);
    v304 = (Lisp_Object)17; /* 1 */
    v304 = cons(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    v305 = ncons(v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    v304 = stack[-3];
    v304 = qcar(v304);
    fn = elt(env, 7); /* multf */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    v304 = (*qfn2(fn))(qenv(fn), stack[-1], v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-1] = v304;
    v304 = stack[-1];
    fn = elt(env, 4); /* termsf */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-8] = v304;
    v305 = stack[-5];
    v304 = stack[-8];
    v304 = difference2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-5] = v304;
    v304 = stack[-7];
    v304 = qcdr(v304);
    stack[-7] = v304;
    goto v84;

v309:
    v304 = qvalue(elt(env, 2)); /* nil */
    { popv(10); return onevalue(v304); }

v308:
    v305 = stack[-1];
    v304 = stack[-7];
    fn = elt(env, 5); /* addf */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    popv(10);
    return ncons(v304);

v11:
    v304 = stack[-7];
    v304 = qcar(v304);
    v304 = qcar(v304);
    v305 = qcdr(v304);
    v304 = stack[-6];
    v304 = qcar(v304);
    v304 = qcar(v304);
    v304 = qcdr(v304);
    v305 = difference2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-4] = v305;
    v304 = (Lisp_Object)1; /* 0 */
    v304 = (Lisp_Object)lessp2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    v304 = v304 ? lisp_true : nil;
    env = stack[-9];
    if (v304 == nil) goto v241;
    v305 = stack[-1];
    v304 = stack[-7];
    fn = elt(env, 5); /* addf */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    popv(10);
    return ncons(v304);

v241:
    v304 = stack[-7];
    v304 = qcar(v304);
    v305 = qcdr(v304);
    v304 = stack[-6];
    v304 = qcar(v304);
    v304 = qcdr(v304);
    fn = elt(env, 8); /* qremf */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-3] = v304;
    v304 = stack[-7];
    v304 = qcar(v304);
    v305 = qcar(v304);
    v304 = (Lisp_Object)17; /* 1 */
    v304 = cons(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    v305 = ncons(v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    v304 = stack[-3];
    v304 = qcdr(v304);
    fn = elt(env, 7); /* multf */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-2] = v304;
    v305 = stack[-5];
    v304 = stack[-8];
    v304 = plus2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-5] = v304;
    v305 = stack[-1];
    v304 = stack[-2];
    fn = elt(env, 5); /* addf */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-1] = v304;
    v304 = stack[-1];
    fn = elt(env, 4); /* termsf */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-8] = v304;
    v305 = stack[-5];
    v304 = stack[-8];
    v305 = difference2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    v304 = stack[0];
    v304 = plus2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-5] = v304;
    v304 = stack[-3];
    v304 = qcar(v304);
    if (v304 == nil) goto v129;
    stack[0] = stack[-7];
    v305 = stack[-4];
    v304 = (Lisp_Object)1; /* 0 */
    if (v305 == v304) goto v252;
    v304 = stack[-7];
    v304 = qcar(v304);
    v304 = qcar(v304);
    v306 = qcar(v304);
    v305 = stack[-4];
    v304 = (Lisp_Object)17; /* 1 */
    v304 = acons(v306, v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    v305 = ncons(v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    v304 = stack[-6];
    fn = elt(env, 7); /* multf */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-4] = v304;
    goto v177;

v177:
    v304 = stack[-3];
    v304 = qcar(v304);
    fn = elt(env, 9); /* negf */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    fn = elt(env, 7); /* multf */
    v304 = (*qfn2(fn))(qenv(fn), stack[-4], v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    v304 = stack[-2];
    fn = elt(env, 9); /* negf */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    v304 = (*qfn2(fn))(qenv(fn), stack[0], v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    goto v128;

v128:
    stack[-7] = v304;
    v304 = stack[-7];
    fn = elt(env, 4); /* termsf */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[0] = v304;
    v305 = stack[-5];
    v304 = stack[0];
    v304 = difference2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-9];
    stack[-5] = v304;
    goto v84;

v252:
    v304 = stack[-6];
    stack[-4] = v304;
    goto v177;

v129:
    v304 = stack[-7];
    v304 = qcdr(v304);
    goto v128;

v120:
    v304 = qvalue(elt(env, 1)); /* t */
    goto v42;

v90:
    v304 = qvalue(elt(env, 1)); /* t */
    goto v91;
/* error exit handlers */
v307:
    popv(10);
    return nil;
}



/* Code for extract_numid */

static Lisp_Object CC_extract_numid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v259, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extract_numid");
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

v39:
    v259 = stack[0];
    if (v259 == nil) goto v10;
    v259 = stack[0];
    v259 = qcar(v259);
    fn = elt(env, 2); /* !*id2num */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v21 = v259;
    v259 = v21;
    if (v259 == nil) goto v140;
    stack[-1] = v21;
    v259 = stack[0];
    v259 = qcdr(v259);
    v259 = CC_extract_numid(env, v259);
    nil = C_nil;
    if (exception_pending()) goto v85;
    {
        Lisp_Object v86 = stack[-1];
        popv(3);
        return cons(v86, v259);
    }

v140:
    v259 = stack[0];
    v259 = qcdr(v259);
    stack[0] = v259;
    goto v39;

v10:
    v259 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v259); }
/* error exit handlers */
v85:
    popv(3);
    return nil;
}



/* Code for st_flatten */

static Lisp_Object CC_st_flatten(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_flatten");
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
    v236 = v0;
/* end of prologue */
    v20 = v236;
    v20 = qcdr(v20);
    v20 = qcar(v20);
    if (is_number(v20)) goto v10;
    v20 = v236;
    v20 = qcdr(v20);
    stack[-3] = v20;
    goto v215;

v215:
    v20 = stack[-3];
    if (v20 == nil) goto v126;
    v20 = stack[-3];
    v20 = qcar(v20);
    v20 = CC_st_flatten(env, v20);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    fn = elt(env, 2); /* copy */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    stack[-2] = v20;
    v20 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    stack[-1] = v20;
    v20 = stack[-3];
    v20 = qcdr(v20);
    stack[-3] = v20;
    v20 = stack[-1];
    if (!consp(v20)) goto v215;
    else goto v146;

v146:
    v20 = stack[-3];
    if (v20 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v20 = stack[-3];
    v20 = qcar(v20);
    v20 = CC_st_flatten(env, v20);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    fn = elt(env, 2); /* copy */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    v20 = Lrplacd(nil, stack[0], v20);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    v20 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    stack[-1] = v20;
    v20 = stack[-3];
    v20 = qcdr(v20);
    stack[-3] = v20;
    goto v146;

v126:
    v20 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v20); }

v10:
    v20 = v236;
    v20 = qcdr(v20);
    { popv(5); return onevalue(v20); }
/* error exit handlers */
v121:
    popv(5);
    return nil;
}



/* Code for diff!-k!-times!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKkKtimesKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v107, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-k-times-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff-k-times-mod-p");
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
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v184 = stack[-3];
    if (!consp(v184)) goto v40;
    v184 = stack[-3];
    v184 = qcar(v184);
    v184 = (consp(v184) ? nil : lisp_true);
    goto v61;

v61:
    if (v184 == nil) goto v90;
    v184 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v184); }

v90:
    v184 = stack[-3];
    v184 = qcar(v184);
    v184 = qcar(v184);
    v107 = qcar(v184);
    v184 = stack[-1];
    if (equal(v107, v184)) goto v145;
    v184 = stack[-3];
    v184 = qcar(v184);
    stack[-4] = qcar(v184);
    v184 = stack[-3];
    v184 = qcar(v184);
    v95 = qcdr(v184);
    v107 = stack[-2];
    v184 = stack[-1];
    stack[0] = CC_diffKkKtimesKmodKp(env, 3, v95, v107, v184);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v184 = stack[-3];
    v95 = qcdr(v184);
    v107 = stack[-2];
    v184 = stack[-1];
    v184 = CC_diffKkKtimesKmodKp(env, 3, v95, v107, v184);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    {
        Lisp_Object v105 = stack[-4];
        Lisp_Object v106 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v105, v106, v184);
    }

v145:
    v184 = stack[-3];
    v184 = qcar(v184);
    v184 = qcar(v184);
    v107 = qcdr(v184);
    v184 = stack[-2];
    v184 = (Lisp_Object)lessp2(v107, v184);
    nil = C_nil;
    if (exception_pending()) goto v72;
    v184 = v184 ? lisp_true : nil;
    env = stack[-5];
    if (v184 == nil) goto v217;
    v184 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v184); }

v217:
    v184 = stack[-3];
    v184 = qcar(v184);
    v184 = qcar(v184);
    v107 = qcdr(v184);
    v184 = stack[-2];
    if (equal(v107, v184)) goto v84;
    v184 = stack[-1];
    fn = elt(env, 4); /* fkern */
    stack[0] = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v184 = stack[-3];
    v184 = qcar(v184);
    v184 = qcar(v184);
    v107 = qcdr(v184);
    v184 = stack[-2];
    v184 = difference2(v107, v184);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    fn = elt(env, 5); /* getpower */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v184 = stack[-3];
    v184 = qcar(v184);
    v184 = qcar(v184);
    v107 = qcdr(v184);
    v184 = stack[-2];
    fn = elt(env, 6); /* binomial!-coefft!-mod!-p */
    v107 = (*qfn2(fn))(qenv(fn), v107, v184);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v184 = stack[-3];
    v184 = qcar(v184);
    v184 = qcdr(v184);
    fn = elt(env, 7); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v107, v184);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v184 = stack[-3];
    v95 = qcdr(v184);
    v107 = stack[-2];
    v184 = stack[-1];
    v184 = CC_diffKkKtimesKmodKp(env, 3, v95, v107, v184);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    {
        Lisp_Object v312 = stack[-4];
        Lisp_Object v138 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v312, v138, v184);
    }

v84:
    v184 = stack[-3];
    v184 = qcar(v184);
    v184 = qcdr(v184);
    { popv(6); return onevalue(v184); }

v40:
    v184 = qvalue(elt(env, 1)); /* t */
    goto v61;
/* error exit handlers */
v72:
    popv(6);
    return nil;
}



/* Code for dvfsf_v */

static Lisp_Object CC_dvfsf_v(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_v");
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
    v126 = v0;
/* end of prologue */
    v133 = v126;
    v126 = qvalue(elt(env, 1)); /* dvfsf_p!* */
    fn = elt(env, 2); /* qremf */
    v126 = (*qfn2(fn))(qenv(fn), v133, v126);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[0];
    v133 = v126;
    v126 = v133;
    v126 = qcdr(v126);
    if (v126 == nil) goto v54;
    v126 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v126); }

v54:
    v126 = v133;
    v126 = qcar(v126);
    v126 = CC_dvfsf_v(env, v126);
    nil = C_nil;
    if (exception_pending()) goto v25;
    popv(1);
    return add1(v126);
/* error exit handlers */
v25:
    popv(1);
    return nil;
}



/* Code for iv_cutcongs1 */

static Lisp_Object CC_iv_cutcongs1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for iv_cutcongs1");
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

v14:
    v144 = stack[0];
    if (v144 == nil) goto v140;
    v143 = stack[-1];
    v144 = stack[0];
    v144 = qcar(v144);
    fn = elt(env, 3); /* iv_cutcongs2 */
    v144 = (*qfn2(fn))(qenv(fn), v143, v144);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    if (v144 == nil) goto v25;
    v144 = stack[0];
    v144 = qcdr(v144);
    stack[0] = v144;
    goto v14;

v25:
    v144 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v144); }

v140:
    v144 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v144); }
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



setup_type const u35_setup[] =
{
    {"mv-compact",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_mvKcompact},
    {"redall",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_redall},
    {"tidysqrtf",               CC_tidysqrtf,   too_many_1,    wrong_no_1},
    {"rd:prin",                 CC_rdTprin,     too_many_1,    wrong_no_1},
    {"processpartitie1list1",   too_few_2,      CC_processpartitie1list1,wrong_no_2},
    {"ofsf_smwrmknowl",         too_few_2,      CC_ofsf_smwrmknowl,wrong_no_2},
    {"mk+mat+plus+mat",         too_few_2,      CC_mkLmatLplusLmat,wrong_no_2},
    {"mri_congp",               CC_mri_congp,   too_many_1,    wrong_no_1},
    {"diffrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffrd},
    {"ps:set-term",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTsetKterm},
    {"simpu",                   CC_simpu,       too_many_1,    wrong_no_1},
    {"subs2pf",                 CC_subs2pf,     too_many_1,    wrong_no_1},
    {"divide-by-power-of-ten",  too_few_2,      CC_divideKbyKpowerKofKten,wrong_no_2},
    {"subfindices",             too_few_2,      CC_subfindices,wrong_no_2},
    {"dfdeg",                   too_few_2,      CC_dfdeg,      wrong_no_2},
    {"find_triangles1",         too_few_2,      CC_find_triangles1,wrong_no_2},
    {"fs:zerop:",               CC_fsTzeropT,   too_many_1,    wrong_no_1},
    {"*g2lex",                  CC_Hg2lex,      too_many_1,    wrong_no_1},
    {"r2flbf",                  CC_r2flbf,      too_many_1,    wrong_no_1},
    {"bfprin0x",                too_few_2,      CC_bfprin0x,   wrong_no_2},
    {"nextu",                   too_few_2,      CC_nextu,      wrong_no_2},
    {"repr_a",                  CC_repr_a,      too_many_1,    wrong_no_1},
    {"prsubsetrd",              CC_prsubsetrd,  too_many_1,    wrong_no_1},
    {"i2ps",                    CC_i2ps,        too_many_1,    wrong_no_1},
    {"groebcplistmerge",        too_few_2,      CC_groebcplistmerge,wrong_no_2},
    {"multsqpf",                too_few_2,      CC_multsqpf,   wrong_no_2},
    {"*kp2q",                   too_few_2,      CC_Hkp2q,      wrong_no_2},
    {"gcdld",                   too_few_2,      CC_gcdld,      wrong_no_2},
    {"dfp-rule-found",          too_few_2,      CC_dfpKruleKfound,wrong_no_2},
    {"fs:minusp",               CC_fsTminusp,   too_many_1,    wrong_no_1},
    {"mo_zero?",                CC_mo_zeroW,    too_many_1,    wrong_no_1},
    {"quotfail-in-vector",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_quotfailKinKvector},
    {"*n2a",                    CC_Hn2a,        too_many_1,    wrong_no_1},
    {"sgn1",                    too_few_2,      CC_sgn1,       wrong_no_2},
    {"ofsf_lnegrel",            CC_ofsf_lnegrel,too_many_1,    wrong_no_1},
    {"pickbasicset",            CC_pickbasicset,too_many_1,    wrong_no_1},
    {"pasf_smordtable2",        too_few_2,      CC_pasf_smordtable2,wrong_no_2},
    {"cols2rows2",              too_few_2,      CC_cols2rows2, wrong_no_2},
    {"ps:arg-values",           CC_psTargKvalues,too_many_1,   wrong_no_1},
    {"letmtr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr},
    {"chksymmetries&sub1",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_chksymmetriesGsub1},
    {"coeff_calc",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff_calc},
    {"xremf",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_xremf},
    {"extract_numid",           CC_extract_numid,too_many_1,   wrong_no_1},
    {"st_flatten",              CC_st_flatten,  too_many_1,    wrong_no_1},
    {"diff-k-times-mod-p",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKkKtimesKmodKp},
    {"dvfsf_v",                 CC_dvfsf_v,     too_many_1,    wrong_no_1},
    {"iv_cutcongs1",            too_few_2,      CC_iv_cutcongs1,wrong_no_2},
    {NULL, (one_args *)"u35", (two_args *)"3744 7391017 325154", 0}
};

/* end of generated code */
