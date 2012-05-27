
/* $destdir\u31.c        Machine generated C code */

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


/* Code for reduce */

static Lisp_Object CC_reduce(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v13, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce");
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
    v12 = v0;
/* end of prologue */
    stack[0] = v12;
    v12 = qvalue(elt(env, 1)); /* !*yyy */
    if (v12 == nil) goto v15;
    v13 = stack[0];
    v12 = stack[-1];
    fn = elt(env, 3); /* reduce!-ratios */
    v12 = (*qfn2(fn))(qenv(fn), v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    stack[0] = v12;
    goto v15;

v15:
    v12 = stack[-1];
    fn = elt(env, 4); /* set!-weights */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    stack[-2] = v12;
    v12 = qvalue(elt(env, 2)); /* !*xxx */
    if (v12 == nil) goto v17;
    v14 = stack[0];
    v13 = stack[-1];
    v12 = stack[-2];
    fn = elt(env, 5); /* reduce!-columns */
    v12 = (*qfnn(fn))(qenv(fn), 3, v14, v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    stack[0] = v12;
    goto v17;

v17:
    v12 = qvalue(elt(env, 2)); /* !*xxx */
    if (v12 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v14 = stack[0];
    v13 = stack[-1];
    v12 = stack[-2];
    fn = elt(env, 6); /* reduce!-weights */
    v12 = (*qfnn(fn))(qenv(fn), 3, v14, v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v16;
    stack[0] = v12;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v16:
    popv(4);
    return nil;
}



/* Code for fs!:make!-nullangle */

static Lisp_Object MS_CDECL CC_fsTmakeKnullangle(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v24, v25;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fs:make-nullangle");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:make-nullangle");
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
    v8 = (Lisp_Object)113; /* 7 */
    v8 = Lmkvect(nil, v8);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    stack[-1] = v8;
    v8 = (Lisp_Object)1; /* 0 */
    stack[0] = v8;
    goto v27;

v27:
    v24 = (Lisp_Object)113; /* 7 */
    v8 = stack[0];
    v8 = difference2(v24, v8);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v8 = Lminusp(nil, v8);
    env = stack[-2];
    if (!(v8 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v25 = stack[-1];
    v24 = stack[0];
    v8 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v25 + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL))) = v8;
    v8 = stack[0];
    v8 = add1(v8);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    stack[0] = v8;
    goto v27;
/* error exit handlers */
v26:
    popv(3);
    return nil;
}



/* Code for red!=hide */

static Lisp_Object CC_redMhide(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=hide");
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
    v37 = v0;
/* end of prologue */
    stack[-5] = v37;
    v37 = stack[-5];
    if (v37 == nil) goto v39;
    v37 = stack[-5];
    v37 = qcar(v37);
    stack[-1] = v37;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v37 = stack[-1];
    v37 = qcar(v37);
    fn = elt(env, 2); /* mo_neg */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v38 = (*qfn2(fn))(qenv(fn), stack[0], v37);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v37 = stack[-1];
    v37 = qcdr(v37);
    v37 = cons(v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v37 = ncons(v37);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    stack[-3] = v37;
    stack[-4] = v37;
    goto v41;

v41:
    v37 = stack[-5];
    v37 = qcdr(v37);
    stack[-5] = v37;
    v37 = stack[-5];
    if (v37 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-2] = stack[-3];
    v37 = stack[-5];
    v37 = qcar(v37);
    stack[-1] = v37;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v37 = stack[-1];
    v37 = qcar(v37);
    fn = elt(env, 2); /* mo_neg */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v38 = (*qfn2(fn))(qenv(fn), stack[0], v37);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v37 = stack[-1];
    v37 = qcdr(v37);
    v37 = cons(v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v37 = ncons(v37);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v37 = Lrplacd(nil, stack[-2], v37);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v37 = stack[-3];
    v37 = qcdr(v37);
    stack[-3] = v37;
    goto v41;

v39:
    v37 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v37); }
/* error exit handlers */
v40:
    popv(7);
    return nil;
}



/* Code for taylorp */

static Lisp_Object CC_taylorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taylorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v0;
/* end of prologue */
    v43 = v44;
    if (!consp(v43)) goto v45;
    v43 = v44;
    v43 = qcar(v43);
    if (!consp(v43)) goto v23;
    v43 = v44;
    v43 = qcar(v43);
    v43 = qcar(v43);
    v44 = elt(env, 1); /* taylor */
        return Lflagp(nil, v43, v44);

v23:
    v43 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v43);

v45:
    v43 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v43);
}



/* Code for ofsf_at2ir */

static Lisp_Object CC_ofsf_at2ir(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_at2ir");
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
    v60 = v0;
/* end of prologue */
    v59 = v60;
    v59 = qcar(v59);
    stack[-4] = v59;
    v59 = v60;
    v59 = qcdr(v59);
    v59 = qcar(v59);
    stack[-2] = v59;
    stack[0] = v59;
    goto v62;

v62:
    v59 = stack[0];
    if (!consp(v59)) goto v23;
    v59 = stack[0];
    v59 = qcar(v59);
    v59 = (consp(v59) ? nil : lisp_true);
    goto v22;

v22:
    if (v59 == nil) goto v35;
    stack[-1] = stack[-2];
    v59 = stack[0];
    fn = elt(env, 3); /* negf */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    fn = elt(env, 4); /* addf */
    v59 = (*qfn2(fn))(qenv(fn), stack[-1], v59);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[-2] = v59;
    v59 = stack[-2];
    fn = elt(env, 5); /* sfto_dcontentf */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[-1] = v59;
    v60 = stack[-2];
    v59 = stack[-1];
    fn = elt(env, 6); /* quotf */
    v59 = (*qfn2(fn))(qenv(fn), v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[-2] = v59;
    v60 = stack[0];
    v59 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v60 = stack[-1];
    v59 = (Lisp_Object)17; /* 1 */
    v59 = cons(v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    fn = elt(env, 7); /* invsq */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    fn = elt(env, 8); /* multsq */
    v59 = (*qfn2(fn))(qenv(fn), stack[0], v59);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[0] = v59;
    stack[-1] = stack[-2];
    v61 = stack[-3];
    v60 = stack[-4];
    v59 = stack[0];
    v59 = list2star(v61, v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v60 = qvalue(elt(env, 2)); /* nil */
    {
        Lisp_Object v64 = stack[-1];
        popv(6);
        return list2star(v64, v59, v60);
    }

v35:
    v59 = stack[0];
    v59 = qcdr(v59);
    stack[0] = v59;
    goto v62;

v23:
    v59 = qvalue(elt(env, 1)); /* t */
    goto v22;
/* error exit handlers */
v63:
    popv(6);
    return nil;
}



/* Code for createsinglevariablemonom */

static Lisp_Object CC_createsinglevariablemonom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v24, v25;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for createsinglevariablemonom");
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
    v8 = (Lisp_Object)17; /* 1 */
    v8 = Lmkvect(nil, v8);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    stack[-3] = v8;
    v25 = stack[-3];
    v24 = (Lisp_Object)1; /* 0 */
    v8 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v25 + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL))) = v8;
    stack[-1] = stack[-3];
    stack[0] = (Lisp_Object)17; /* 1 */
    v25 = stack[-2];
    v24 = qvalue(elt(env, 1)); /* nil */
    v8 = qvalue(elt(env, 1)); /* nil */
    v8 = list2star(v25, v24, v8);
    nil = C_nil;
    if (exception_pending()) goto v68;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v8;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v68:
    popv(5);
    return nil;
}



/* Code for gigcdsq */

static Lisp_Object CC_gigcdsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gigcdsq");
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
    v74 = stack[-1];
    if (v74 == nil) goto v56;
    v54 = stack[0];
    v74 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 2); /* giintgcd */
    v74 = (*qfn2(fn))(qenv(fn), v54, v74);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[-2] = v74;
    v54 = stack[-2];
    v74 = (Lisp_Object)17; /* 1 */
    if (v54 == v74) goto v76;
    v54 = stack[-1];
    v74 = stack[-2];
    fn = elt(env, 2); /* giintgcd */
    v54 = (*qfn2(fn))(qenv(fn), v54, v74);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[-2] = v54;
    v74 = (Lisp_Object)17; /* 1 */
    v74 = Lneq(nil, v54, v74);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    goto v22;

v22:
    if (v74 == nil) goto v56;
    v54 = stack[-1];
    v74 = stack[-2];
    fn = elt(env, 3); /* quotf */
    v74 = (*qfn2(fn))(qenv(fn), v54, v74);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[-1] = v74;
    v54 = stack[0];
    v74 = stack[-2];
    fn = elt(env, 3); /* quotf */
    v74 = (*qfn2(fn))(qenv(fn), v54, v74);
    nil = C_nil;
    if (exception_pending()) goto v75;
    stack[0] = v74;
    goto v56;

v56:
    v54 = stack[-1];
    v74 = stack[0];
    popv(4);
    return cons(v54, v74);

v76:
    v74 = qvalue(elt(env, 1)); /* nil */
    goto v22;
/* error exit handlers */
v75:
    popv(4);
    return nil;
}



/* Code for pasf_dt */

static Lisp_Object CC_pasf_dt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v134, v135, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_dt");
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
    v134 = stack[0];
    v133 = elt(env, 1); /* true */
    if (v134 == v133) goto v137;
    v134 = stack[0];
    v133 = elt(env, 3); /* false */
    v133 = (v134 == v133 ? lisp_true : nil);
    goto v39;

v39:
    if (!(v133 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v133 = stack[0];
    v133 = qcdr(v133);
    v133 = qcar(v133);
    fn = elt(env, 18); /* pasf_pdp */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-1];
    v136 = v133;
    v134 = stack[0];
    v133 = elt(env, 1); /* true */
    if (v134 == v133) goto v26;
    v134 = stack[0];
    v133 = elt(env, 3); /* false */
    v133 = (v134 == v133 ? lisp_true : nil);
    goto v58;

v58:
    if (v133 == nil) goto v25;
    v133 = stack[0];
    goto v8;

v8:
    v135 = v133;
    v134 = v136;
    v133 = elt(env, 4); /* pdef */
    if (v134 == v133) goto v139;
    v133 = qvalue(elt(env, 6)); /* nil */
    goto v140;

v140:
    if (v133 == nil) goto v141;
    v133 = elt(env, 3); /* false */
    { popv(2); return onevalue(v133); }

v141:
    v134 = v136;
    v133 = elt(env, 7); /* ndef */
    if (v134 == v133) goto v142;
    v133 = qvalue(elt(env, 6)); /* nil */
    goto v143;

v143:
    if (v133 == nil) goto v144;
    v133 = elt(env, 3); /* false */
    { popv(2); return onevalue(v133); }

v144:
    v134 = v136;
    v133 = elt(env, 4); /* pdef */
    if (v134 == v133) goto v145;
    v133 = qvalue(elt(env, 6)); /* nil */
    goto v146;

v146:
    if (v133 == nil) goto v147;
    v133 = elt(env, 1); /* true */
    { popv(2); return onevalue(v133); }

v147:
    v134 = v136;
    v133 = elt(env, 7); /* ndef */
    if (v134 == v133) goto v148;
    v133 = qvalue(elt(env, 6)); /* nil */
    goto v149;

v149:
    if (v133 == nil) goto v150;
    v133 = elt(env, 1); /* true */
    { popv(2); return onevalue(v133); }

v150:
    v134 = v136;
    v133 = elt(env, 11); /* psdef */
    if (v134 == v133) goto v151;
    v133 = qvalue(elt(env, 6)); /* nil */
    goto v152;

v152:
    if (v133 == nil) goto v153;
    v133 = elt(env, 3); /* false */
    { popv(2); return onevalue(v133); }

v153:
    v134 = v136;
    v133 = elt(env, 13); /* nsdef */
    if (v134 == v133) goto v154;
    v133 = qvalue(elt(env, 6)); /* nil */
    goto v155;

v155:
    if (v133 == nil) goto v156;
    v133 = elt(env, 3); /* false */
    { popv(2); return onevalue(v133); }

v156:
    v134 = v136;
    v133 = elt(env, 11); /* psdef */
    if (v134 == v133) goto v157;
    v133 = qvalue(elt(env, 6)); /* nil */
    goto v158;

v158:
    if (v133 == nil) goto v159;
    v133 = elt(env, 1); /* true */
    { popv(2); return onevalue(v133); }

v159:
    v134 = v136;
    v133 = elt(env, 13); /* nsdef */
    if (v134 == v133) goto v160;
    v133 = qvalue(elt(env, 6)); /* nil */
    goto v161;

v161:
    if (v133 == nil) goto v162;
    v133 = elt(env, 1); /* true */
    { popv(2); return onevalue(v133); }

v162:
    v134 = v136;
    v133 = elt(env, 11); /* psdef */
    if (v134 == v133) goto v163;
    v133 = qvalue(elt(env, 6)); /* nil */
    goto v164;

v164:
    if (v133 == nil) goto v165;
    v134 = elt(env, 14); /* greaterp */
    v133 = stack[0];
    v133 = qcdr(v133);
    v133 = qcar(v133);
    v135 = qvalue(elt(env, 6)); /* nil */
    popv(2);
    return list3(v134, v133, v135);

v165:
    v134 = v136;
    v133 = elt(env, 13); /* nsdef */
    if (v134 == v133) goto v166;
    v133 = qvalue(elt(env, 6)); /* nil */
    goto v167;

v167:
    if (v133 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v134 = elt(env, 12); /* lessp */
    v133 = stack[0];
    v133 = qcdr(v133);
    v133 = qcar(v133);
    v135 = qvalue(elt(env, 6)); /* nil */
    popv(2);
    return list3(v134, v133, v135);

v166:
    v134 = v135;
    v133 = elt(env, 17); /* neq */
    v133 = (v134 == v133 ? lisp_true : nil);
    goto v167;

v163:
    v134 = v135;
    v133 = elt(env, 17); /* neq */
    v133 = (v134 == v133 ? lisp_true : nil);
    goto v164;

v160:
    v134 = v135;
    v133 = elt(env, 16); /* leq */
    v133 = (v134 == v133 ? lisp_true : nil);
    goto v161;

v157:
    v134 = v135;
    v133 = elt(env, 15); /* geq */
    v133 = (v134 == v133 ? lisp_true : nil);
    goto v158;

v154:
    v134 = v135;
    v133 = elt(env, 14); /* greaterp */
    v133 = (v134 == v133 ? lisp_true : nil);
    goto v155;

v151:
    v134 = v135;
    v133 = elt(env, 12); /* lessp */
    v133 = (v134 == v133 ? lisp_true : nil);
    goto v152;

v148:
    v134 = v135;
    v133 = elt(env, 10); /* (neq lessp leq) */
    v133 = Lmemq(nil, v134, v133);
    goto v149;

v145:
    v134 = v135;
    v133 = elt(env, 9); /* (neq greaterp geq) */
    v133 = Lmemq(nil, v134, v133);
    goto v146;

v142:
    v134 = v135;
    v133 = elt(env, 8); /* (equal greaterp geq) */
    v133 = Lmemq(nil, v134, v133);
    goto v143;

v139:
    v134 = v135;
    v133 = elt(env, 5); /* (equal lessp leq) */
    v133 = Lmemq(nil, v134, v133);
    goto v140;

v25:
    v133 = stack[0];
    v133 = qcar(v133);
    v133 = Lconsp(nil, v133);
    env = stack[-1];
    if (v133 == nil) goto v69;
    v133 = stack[0];
    v133 = qcar(v133);
    v133 = qcar(v133);
    goto v8;

v69:
    v133 = stack[0];
    v133 = qcar(v133);
    goto v8;

v26:
    v133 = qvalue(elt(env, 2)); /* t */
    goto v58;

v137:
    v133 = qvalue(elt(env, 2)); /* t */
    goto v39;
/* error exit handlers */
v138:
    popv(2);
    return nil;
}



/* Code for rl_surep */

static Lisp_Object CC_rl_surep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_surep");
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
    v35 = v1;
    v10 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_surep!* */
    v35 = list2(v10, v35);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    {
        Lisp_Object v22 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v22, v35);
    }
/* error exit handlers */
v42:
    popv(2);
    return nil;
}



/* Code for setrd */

static Lisp_Object MS_CDECL CC_setrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setrd");
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
    v34 = elt(env, 1); /* (t y p e != s e t !$) */
    qvalue(elt(env, 2)) = v34; /* atts */
    stack[0] = elt(env, 3); /* list */
    fn = elt(env, 4); /* stats_getargs */
    v34 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-1];
    v34 = cons(stack[0], v34);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-1];
    v45 = v34;
    v34 = v45;
    stack[0] = qcar(v34);
    v34 = v45;
    v34 = qcdr(v34);
    fn = elt(env, 5); /* norepeat */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v168;
    {
        Lisp_Object v43 = stack[0];
        popv(2);
        return cons(v43, v34);
    }
/* error exit handlers */
v168:
    popv(2);
    return nil;
}



/* Code for ps!:zerop!: */

static Lisp_Object CC_psTzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:zerop:");
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
    v67 = v0;
/* end of prologue */
    fn = elt(env, 2); /* ps!:value */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[0];
    v62 = v67;
    v67 = v62;
    if (is_number(v67)) goto v39;
    v67 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v67); }

v39:
    v67 = v62;
        popv(1);
        return Lzerop(nil, v67);
/* error exit handlers */
v27:
    popv(1);
    return nil;
}



/* Code for maxl */

static Lisp_Object CC_maxl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxl");
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
    goto v18;

v18:
    v26 = stack[0];
    if (v26 == nil) goto v41;
    v26 = stack[0];
    v73 = qcar(v26);
    v26 = stack[-1];
    v26 = cons(v73, v26);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    stack[-1] = v26;
    v26 = stack[0];
    v26 = qcdr(v26);
    stack[0] = v26;
    goto v18;

v41:
    v26 = (Lisp_Object)-159999; /* -10000 */
    v73 = v26;
    goto v169;

v169:
    v26 = stack[-1];
    if (v26 == nil) { popv(3); return onevalue(v73); }
    v26 = stack[-1];
    v26 = qcar(v26);
    fn = elt(env, 1); /* max */
    v26 = (*qfn2(fn))(qenv(fn), v26, v73);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v73 = v26;
    v26 = stack[-1];
    v26 = qcdr(v26);
    stack[-1] = v26;
    goto v169;
/* error exit handlers */
v76:
    popv(3);
    return nil;
}



/* Code for assgnpri */

static Lisp_Object MS_CDECL CC_assgnpri(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v33, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v199, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "assgnpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assgnpri");
#endif
    if (stack >= stacklimit)
    {
        push3(v33,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v33;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v198 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v198; /* overflowed!* */
    qvalue(elt(env, 3)) = v198; /* testing!-width!* */
    v198 = stack[-2];
    if (!(v198 == nil)) goto v15;
    v198 = (Lisp_Object)1; /* 0 */
    stack[-2] = v198;
    goto v15;

v15:
    v198 = qvalue(elt(env, 4)); /* !*nero */
    if (v198 == nil) goto v67;
    v199 = stack[-2];
    v198 = (Lisp_Object)1; /* 0 */
    if (!(v199 == v198)) goto v67;
    v198 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v198); }

v67:
    v198 = qvalue(elt(env, 5)); /* !*tex */
    if (v198 == nil) goto v19;
    v159 = stack[-2];
    v199 = stack[-1];
    v198 = stack[0];
    {
        popv(5);
        fn = elt(env, 20); /* texpri */
        return (*qfnn(fn))(qenv(fn), 3, v159, v199, v198);
    }

v19:
    v198 = elt(env, 6); /* vecp */
    fn = elt(env, 21); /* getd */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    if (v198 == nil) goto v44;
    v198 = stack[-2];
    fn = elt(env, 6); /* vecp */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    if (v198 == nil) goto v44;
    v199 = stack[-2];
    v198 = elt(env, 7); /* mat */
    {
        popv(5);
        fn = elt(env, 22); /* vecpri */
        return (*qfn2(fn))(qenv(fn), v199, v198);
    }

v44:
    v198 = stack[-2];
    fn = elt(env, 23); /* getrtype */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v159 = v198;
    if (v198 == nil) goto v200;
    v199 = v159;
    v198 = elt(env, 8); /* sprifn */
    v198 = Lflagp(nil, v199, v198);
    env = stack[-4];
    if (v198 == nil) goto v201;
    v198 = qvalue(elt(env, 9)); /* outputhandler!* */
    v198 = (v198 == nil ? lisp_true : nil);
    goto v202;

v202:
    if (v198 == nil) goto v200;
    v198 = stack[-1];
    if (v198 == nil) goto v203;
    v159 = elt(env, 12); /* setq */
    v198 = stack[-1];
    v199 = qcar(v198);
    v198 = stack[-2];
    v198 = list3(v159, v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v199 = qvalue(elt(env, 9)); /* outputhandler!* */
    if (v199 == nil) goto v204;
    v159 = qvalue(elt(env, 9)); /* outputhandler!* */
    v199 = elt(env, 13); /* maprin */
    v198 = Lapply2(nil, 3, v159, v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v205;

v205:
    v198 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v198); }

v204:
    v199 = qvalue(elt(env, 2)); /* overflowed!* */
    if (!(v199 == nil)) goto v205;
    v199 = v198;
    v198 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 24); /* maprint */
    v198 = (*qfn2(fn))(qenv(fn), v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v205;

v203:
    v199 = v159;
    v198 = elt(env, 10); /* tag */
    v199 = get(v199, v198);
    env = stack[-4];
    v198 = elt(env, 11); /* prifn */
    v199 = get(v199, v198);
    env = stack[-4];
    v198 = stack[-2];
    v198 = Lapply1(nil, v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v205;

v200:
    v199 = stack[0];
    v198 = elt(env, 14); /* (first only) */
    v198 = Lmemq(nil, v199, v198);
    if (v198 == nil) goto v206;
    v198 = qvalue(elt(env, 15)); /* t */
    fn = elt(env, 25); /* terpri!* */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v206;

v206:
    v198 = stack[-1];
    fn = elt(env, 26); /* evalvars */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    stack[-1] = v198;
    v198 = qvalue(elt(env, 16)); /* !*fort */
    if (v198 == nil) goto v207;
    v159 = stack[-2];
    v199 = stack[-1];
    v198 = stack[0];
    fn = elt(env, 27); /* fvarpri */
    v198 = (*qfnn(fn))(qenv(fn), 3, v159, v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v198 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v198); }

v207:
    v198 = stack[-1];
    if (v198 == nil) goto v208;
    stack[-3] = elt(env, 12); /* setq */
    v198 = stack[-2];
    v198 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v198 = Lnconc(nil, stack[-1], v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v198 = cons(stack[-3], v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v209;

v209:
    v199 = qvalue(elt(env, 9)); /* outputhandler!* */
    if (v199 == nil) goto v210;
    v159 = qvalue(elt(env, 9)); /* outputhandler!* */
    v199 = elt(env, 13); /* maprin */
    v198 = Lapply2(nil, 3, v159, v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v103;

v103:
    v198 = stack[0];
    if (v198 == nil) goto v211;
    v199 = stack[0];
    v198 = elt(env, 17); /* first */
    v198 = (v199 == v198 ? lisp_true : nil);
    goto v156;

v156:
    if (v198 == nil) goto v212;
    v198 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v198); }

v212:
    v198 = qvalue(elt(env, 18)); /* !*nat */
    if (!(v198 == nil)) goto v98;
    v198 = elt(env, 19); /* "$" */
    fn = elt(env, 28); /* prin2!* */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v98;

v98:
    v198 = qvalue(elt(env, 18)); /* !*nat */
    v198 = (v198 == nil ? lisp_true : nil);
    fn = elt(env, 25); /* terpri!* */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v198 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v198); }

v211:
    v198 = qvalue(elt(env, 15)); /* t */
    goto v156;

v210:
    v199 = qvalue(elt(env, 2)); /* overflowed!* */
    if (!(v199 == nil)) goto v103;
    v199 = v198;
    v198 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 24); /* maprint */
    v198 = (*qfn2(fn))(qenv(fn), v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v103;

v208:
    v198 = stack[-2];
    goto v209;

v201:
    v198 = qvalue(elt(env, 1)); /* nil */
    goto v202;
/* error exit handlers */
v96:
    popv(5);
    return nil;
}



/* Code for decimal2internal */

static Lisp_Object CC_decimal2internal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v16, v215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for decimal2internal");
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
    v16 = stack[0];
    v130 = (Lisp_Object)1; /* 0 */
    v130 = (Lisp_Object)geq2(v16, v130);
    nil = C_nil;
    if (exception_pending()) goto v56;
    v130 = v130 ? lisp_true : nil;
    env = stack[-3];
    if (v130 == nil) goto v216;
    stack[-2] = elt(env, 1); /* !:rd!: */
    v16 = (Lisp_Object)161; /* 10 */
    v130 = stack[0];
    v130 = Lexpt(nil, v16, v130);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v16 = times2(stack[-1], v130);
    nil = C_nil;
    if (exception_pending()) goto v56;
    v130 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v31 = stack[-2];
        popv(4);
        return list2star(v31, v16, v130);
    }

v216:
    v215 = elt(env, 1); /* !:rd!: */
    v16 = stack[-1];
    v130 = (Lisp_Object)1; /* 0 */
    stack[-1] = list2star(v215, v16, v130);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v130 = stack[0];
    v130 = negate(v130);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    {
        Lisp_Object v32 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* divide!-by!-power!-of!-ten */
        return (*qfn2(fn))(qenv(fn), v32, v130);
    }
/* error exit handlers */
v56:
    popv(4);
    return nil;
}



/* Code for indexvp */

static Lisp_Object CC_indexvp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexvp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v0;
/* end of prologue */
    v10 = v11;
    if (!consp(v10)) goto v62;
    v10 = v11;
    v10 = qcar(v10);
    v11 = elt(env, 1); /* indexvar */
        return Lflagp(nil, v10, v11);

v62:
    v10 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v10);
}



/* Code for !*f2di */

static Lisp_Object CC_Hf2di(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v33)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *f2di");
#endif
    if (stack >= stacklimit)
    {
        push2(v33,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v232 = v33;
    stack[-5] = v1;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v232; /* varlist */
    v232 = stack[-5];
    if (v232 == nil) goto v132;
    v232 = stack[-5];
    if (!consp(v232)) goto v35;
    v232 = stack[-5];
    v232 = qcar(v232);
    v232 = (consp(v232) ? nil : lisp_true);
    goto v27;

v27:
    if (v232 == nil) goto v234;
    v232 = qvalue(elt(env, 1)); /* varlist */
    stack[-3] = v232;
    v232 = stack[-3];
    if (v232 == nil) goto v73;
    v232 = (Lisp_Object)1; /* 0 */
    v232 = ncons(v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-1] = v232;
    stack[-2] = v232;
    goto v25;

v25:
    v232 = stack[-3];
    v232 = qcdr(v232);
    stack[-3] = v232;
    v232 = stack[-3];
    if (v232 == nil) goto v13;
    stack[0] = stack[-1];
    v232 = (Lisp_Object)1; /* 0 */
    v232 = ncons(v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v232 = Lrplacd(nil, stack[0], v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v232 = stack[-1];
    v232 = qcdr(v232);
    stack[-1] = v232;
    goto v25;

v13:
    v232 = stack[-2];
    goto v24;

v24:
    fn = elt(env, 4); /* addgt */
    v233 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v232 = stack[-5];
    v232 = cons(v233, v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v232 = ncons(v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    goto v18;

v18:
    qvalue(elt(env, 1)) = stack[-6]; /* varlist */
    { popv(8); return onevalue(v232); }

v73:
    v232 = qvalue(elt(env, 2)); /* nil */
    goto v24;

v234:
    v232 = stack[-5];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v233 = qcar(v232);
    v232 = qvalue(elt(env, 1)); /* varlist */
    v232 = Lmember(nil, v233, v232);
    if (v232 == nil) goto v110;
    v232 = stack[-5];
    v232 = qcar(v232);
    v233 = qcdr(v232);
    v232 = qvalue(elt(env, 1)); /* varlist */
    stack[-4] = CC_Hf2di(env, v233, v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v232 = qvalue(elt(env, 1)); /* varlist */
    stack[-3] = v232;
    v232 = stack[-3];
    if (v232 == nil) goto v190;
    v232 = stack[-3];
    v232 = qcar(v232);
    v233 = v232;
    v232 = stack[-5];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = qcar(v232);
    if (equal(v233, v232)) goto v146;
    v232 = (Lisp_Object)1; /* 0 */
    goto v118;

v118:
    v232 = ncons(v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-1] = v232;
    stack[-2] = v232;
    goto v235;

v235:
    v232 = stack[-3];
    v232 = qcdr(v232);
    stack[-3] = v232;
    v232 = stack[-3];
    if (v232 == nil) goto v236;
    stack[0] = stack[-1];
    v232 = stack[-3];
    v232 = qcar(v232);
    v233 = v232;
    v232 = stack[-5];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = qcar(v232);
    if (equal(v233, v232)) goto v237;
    v232 = (Lisp_Object)1; /* 0 */
    goto v238;

v238:
    v232 = ncons(v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v232 = Lrplacd(nil, stack[0], v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v232 = stack[-1];
    v232 = qcdr(v232);
    stack[-1] = v232;
    goto v235;

v237:
    v232 = stack[-5];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = qcdr(v232);
    goto v238;

v236:
    v232 = stack[-2];
    goto v239;

v239:
    fn = elt(env, 4); /* addgt */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    fn = elt(env, 5); /* pdmult */
    v232 = (*qfn2(fn))(qenv(fn), stack[-4], v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[0] = v232;
    goto v154;

v154:
    v232 = stack[-5];
    v233 = qcdr(v232);
    v232 = qvalue(elt(env, 1)); /* varlist */
    v232 = CC_Hf2di(env, v233, v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    fn = elt(env, 6); /* psum */
    v232 = (*qfn2(fn))(qenv(fn), stack[0], v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    goto v18;

v146:
    v232 = stack[-5];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = qcdr(v232);
    goto v118;

v190:
    v232 = qvalue(elt(env, 2)); /* nil */
    goto v239;

v110:
    v232 = stack[-5];
    v232 = qcar(v232);
    v233 = qcdr(v232);
    v232 = qvalue(elt(env, 1)); /* varlist */
    stack[0] = CC_Hf2di(env, v233, v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v232 = stack[-5];
    v232 = qcar(v232);
    v233 = qcar(v232);
    v232 = (Lisp_Object)17; /* 1 */
    v232 = cons(v233, v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v232 = ncons(v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    fn = elt(env, 7); /* pcmult */
    v232 = (*qfn2(fn))(qenv(fn), stack[0], v232);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[0] = v232;
    goto v154;

v35:
    v232 = qvalue(elt(env, 3)); /* t */
    goto v27;

v132:
    v232 = qvalue(elt(env, 2)); /* nil */
    goto v18;
/* error exit handlers */
v158:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* varlist */
    popv(8);
    return nil;
}



/* Code for nodum_varp */

static Lisp_Object CC_nodum_varp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nodum_varp");
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
    v130 = stack[0];
    fn = elt(env, 7); /* listp */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    if (v130 == nil) goto v62;
    v130 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v130); }

v62:
    v16 = stack[0];
    v130 = elt(env, 2); /* dummy */
    v130 = Lflagp(nil, v16, v130);
    env = stack[-1];
    if (v130 == nil) goto v44;
    v130 = qvalue(elt(env, 1)); /* t */
    goto v137;

v137:
    if (v130 == nil) goto v14;
    v130 = qvalue(elt(env, 6)); /* nil */
    { popv(2); return onevalue(v130); }

v14:
    v130 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v130); }

v44:
    v130 = stack[0];
    fn = elt(env, 8); /* ad_splitname */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v16 = qcar(v130);
    v130 = qvalue(elt(env, 3)); /* g_dvbase */
    if (equal(v16, v130)) goto v168;
    v16 = elt(env, 4); /* !~dv */
    v130 = elt(env, 5); /* !~dva */
    v130 = list2(v16, v130);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v130 = Lmember(nil, stack[0], v130);
    goto v137;

v168:
    v130 = qvalue(elt(env, 1)); /* t */
    goto v137;
/* error exit handlers */
v70:
    popv(2);
    return nil;
}



/* Code for balance_mod */

static Lisp_Object CC_balance_mod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v20;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for balance_mod");
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
    v20 = stack[-1];
    v21 = stack[-1];
    v20 = plus2(v20, v21);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-2];
    v21 = stack[0];
    v21 = (Lisp_Object)greaterp2(v20, v21);
    nil = C_nil;
    if (exception_pending()) goto v7;
    v21 = v21 ? lisp_true : nil;
    if (v21 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v20 = stack[-1];
    v21 = stack[0];
    popv(3);
    return difference2(v20, v21);
/* error exit handlers */
v7:
    popv(3);
    return nil;
}



/* Code for use!-berlekamp */

static Lisp_Object MS_CDECL CC_useKberlekamp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v33, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v269, v270, v271, v272, v273, v274, v275;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "use-berlekamp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for use-berlekamp");
#endif
    if (stack >= stacklimit)
    {
        push3(v33,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v33);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v33;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v269 = qvalue(elt(env, 1)); /* dpoly */
    v269 = (Lisp_Object)((int32_t)(v269) - 0x10);
    stack[-3] = v269;
    v269 = stack[-3];
    v269 = Lmkvect(nil, v269);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    stack[-7] = v269;
    v269 = (Lisp_Object)1; /* 0 */
    stack[0] = v269;
    goto v17;

v17:
    v270 = stack[-3];
    v269 = stack[0];
    v269 = (Lisp_Object)(int32_t)((int32_t)v270 - (int32_t)v269 + TAG_FIXNUM);
    v269 = ((intptr_t)(v269) < 0 ? lisp_true : nil);
    if (v269 == nil) goto v42;
    v272 = stack[-6];
    v271 = stack[-5];
    v270 = qvalue(elt(env, 3)); /* poly!-vector */
    v269 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v269 = (*qfnn(fn))(qenv(fn), 4, v272, v271, v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    stack[-5] = v269;
    v269 = (Lisp_Object)1; /* 0 */
    stack[-2] = v269;
    v269 = stack[-3];
    v269 = Lmkvect(nil, v269);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    stack[-1] = v269;
    v271 = stack[-1];
    v270 = (Lisp_Object)1; /* 0 */
    v269 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v271 + (CELL-TAG_VECTOR) + ((int32_t)v270/(16/CELL))) = v269;
    v269 = (Lisp_Object)17; /* 1 */
    stack[0] = v269;
    goto v222;

v222:
    v270 = stack[-3];
    v269 = stack[0];
    v269 = (Lisp_Object)(int32_t)((int32_t)v270 - (int32_t)v269 + TAG_FIXNUM);
    v269 = ((intptr_t)(v269) < 0 ? lisp_true : nil);
    if (v269 == nil) goto v276;
    v270 = stack[-7];
    v269 = stack[-3];
    {
        popv(9);
        fn = elt(env, 6); /* find!-null!-space */
        return (*qfn2(fn))(qenv(fn), v270, v269);
    }

v276:
    v270 = qvalue(elt(env, 4)); /* current!-modulus */
    v269 = qvalue(elt(env, 1)); /* dpoly */
    if (((int32_t)(v270)) > ((int32_t)(v269))) goto v277;
    v269 = (Lisp_Object)1; /* 0 */
    v272 = v269;
    goto v278;

v278:
    v269 = qvalue(elt(env, 4)); /* current!-modulus */
    v270 = (Lisp_Object)((int32_t)(v269) - 0x10);
    v269 = v272;
    v269 = (Lisp_Object)(int32_t)((int32_t)v270 - (int32_t)v269 + TAG_FIXNUM);
    v269 = ((intptr_t)(v269) < 0 ? lisp_true : nil);
    if (v269 == nil) goto v237;
    v269 = (Lisp_Object)1; /* 0 */
    v273 = v269;
    goto v279;

v279:
    v270 = stack[-2];
    v269 = v273;
    v269 = (Lisp_Object)(int32_t)((int32_t)v270 - (int32_t)v269 + TAG_FIXNUM);
    v269 = ((intptr_t)(v269) < 0 ? lisp_true : nil);
    if (v269 == nil) goto v280;
    v270 = stack[-2];
    v269 = qvalue(elt(env, 4)); /* current!-modulus */
    v269 = (Lisp_Object)(int32_t)((int32_t)v270 + (int32_t)v269 - TAG_FIXNUM);
    stack[-2] = v269;
    goto v281;

v281:
    v272 = stack[-4];
    v271 = stack[-2];
    v270 = qvalue(elt(env, 3)); /* poly!-vector */
    v269 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v269 = (*qfnn(fn))(qenv(fn), 4, v272, v271, v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    stack[-2] = v269;
    v269 = (Lisp_Object)1; /* 0 */
    v275 = v269;
    goto v282;

v282:
    v270 = stack[-2];
    v269 = v275;
    v269 = (Lisp_Object)(int32_t)((int32_t)v270 - (int32_t)v269 + TAG_FIXNUM);
    v269 = ((intptr_t)(v269) < 0 ? lisp_true : nil);
    if (v269 == nil) goto v160;
    v270 = stack[-7];
    v269 = stack[0];
    v272 = *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v269/(16/CELL)));
    v271 = stack[0];
    v270 = stack[-7];
    v269 = stack[0];
    v270 = *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v269/(16/CELL)));
    v269 = stack[0];
    v270 = *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v269/(16/CELL)));
    v269 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v270) - int_of_fixnum(v269);
        if (w < 0) w += current_modulus;
        v269 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v272 + (CELL-TAG_VECTOR) + ((int32_t)v271/(16/CELL))) = v269;
    v269 = stack[0];
    v269 = (Lisp_Object)((int32_t)(v269) + 0x10);
    stack[0] = v269;
    goto v222;

v160:
    v270 = stack[-7];
    v269 = v275;
    v274 = *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v269/(16/CELL)));
    v273 = stack[0];
    v272 = stack[-1];
    v271 = v275;
    v270 = stack[-4];
    v269 = v275;
    v269 = *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v269/(16/CELL)));
    *(Lisp_Object *)((char *)v272 + (CELL-TAG_VECTOR) + ((int32_t)v271/(16/CELL))) = v269;
    *(Lisp_Object *)((char *)v274 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL))) = v269;
    v269 = v275;
    v269 = (Lisp_Object)((int32_t)(v269) + 0x10);
    v275 = v269;
    goto v282;

v280:
    v272 = stack[-4];
    v270 = qvalue(elt(env, 4)); /* current!-modulus */
    v269 = v273;
    v271 = (Lisp_Object)(int32_t)((int32_t)v270 + (int32_t)v269 - TAG_FIXNUM);
    v270 = stack[-1];
    v269 = v273;
    v269 = *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v269/(16/CELL)));
    *(Lisp_Object *)((char *)v272 + (CELL-TAG_VECTOR) + ((int32_t)v271/(16/CELL))) = v269;
    v269 = v273;
    v269 = (Lisp_Object)((int32_t)(v269) + 0x10);
    v273 = v269;
    goto v279;

v237:
    v271 = stack[-4];
    v270 = v272;
    v269 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v271 + (CELL-TAG_VECTOR) + ((int32_t)v270/(16/CELL))) = v269;
    v269 = v272;
    v269 = (Lisp_Object)((int32_t)(v269) + 0x10);
    v272 = v269;
    goto v278;

v277:
    v273 = stack[-1];
    v272 = stack[-2];
    v271 = stack[-6];
    v270 = stack[-5];
    v269 = stack[-4];
    fn = elt(env, 7); /* times!-in!-vector */
    v269 = (*qfnn(fn))(qenv(fn), 5, v273, v272, v271, v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    stack[-2] = v269;
    goto v281;

v42:
    v269 = stack[-3];
    v269 = Lmkvect(nil, v269);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v273 = v269;
    v269 = (Lisp_Object)1; /* 0 */
    v272 = v269;
    goto v68;

v68:
    v270 = stack[-3];
    v269 = v272;
    v269 = (Lisp_Object)(int32_t)((int32_t)v270 - (int32_t)v269 + TAG_FIXNUM);
    v269 = ((intptr_t)(v269) < 0 ? lisp_true : nil);
    if (v269 == nil) goto v30;
    v270 = stack[-7];
    v269 = stack[0];
    v271 = v273;
    *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v269/(16/CELL))) = v271;
    v269 = stack[0];
    v269 = (Lisp_Object)((int32_t)(v269) + 0x10);
    stack[0] = v269;
    goto v17;

v30:
    v271 = v273;
    v270 = v272;
    v269 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v271 + (CELL-TAG_VECTOR) + ((int32_t)v270/(16/CELL))) = v269;
    v269 = v272;
    v269 = (Lisp_Object)((int32_t)(v269) + 0x10);
    v272 = v269;
    goto v68;
/* error exit handlers */
v134:
    popv(9);
    return nil;
}



/* Code for rl_smrmknowl */

static Lisp_Object CC_rl_smrmknowl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smrmknowl");
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
    v35 = v1;
    v10 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smrmknowl!* */
    v35 = list2(v10, v35);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    {
        Lisp_Object v22 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v22, v35);
    }
/* error exit handlers */
v42:
    popv(2);
    return nil;
}



/* Code for give!*position */

static Lisp_Object CC_giveHposition(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for give*position");
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
    v54 = (Lisp_Object)17; /* 1 */
    stack[-4] = v54;
    v54 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v54;
    goto v39;

v39:
    v54 = stack[-1];
    if (v54 == nil) goto v22;
    v54 = qvalue(elt(env, 1)); /* nil */
    goto v27;

v27:
    if (v54 == nil) goto v132;
    v37 = stack[-2];
    v54 = stack[-4];
    fn = elt(env, 5); /* pnth */
    v54 = (*qfn2(fn))(qenv(fn), v37, v54);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-5];
    v37 = qcar(v54);
    v54 = stack[-3];
    if (equal(v37, v54)) goto v9;
    v54 = stack[-4];
    v54 = add1(v54);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-5];
    stack[-4] = v54;
    goto v39;

v9:
    v54 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v54;
    goto v39;

v132:
    v54 = stack[-1];
    if (!(v54 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v54 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v54 == nil)) goto v56;
    v54 = elt(env, 4); /* "error in give position" */
    fn = elt(env, 6); /* lprie */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-5];
    goto v56;

v56:
    v54 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v283;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v22:
    stack[0] = stack[-4];
    v54 = stack[-2];
    v54 = Llength(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-5];
    v54 = (Lisp_Object)lesseq2(stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v283;
    v54 = v54 ? lisp_true : nil;
    env = stack[-5];
    goto v27;
/* error exit handlers */
v283:
    popv(6);
    return nil;
}



/* Code for pasf_smordtable */

static Lisp_Object MS_CDECL CC_pasf_smordtable(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v33, Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smordtable");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smordtable");
#endif
    if (stack >= stacklimit)
    {
        push4(v5,v33,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v33,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v5;
    stack[-1] = v33;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v13 = stack[-1];
    v12 = stack[0];
    v12 = (Lisp_Object)lessp2(v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v16;
    v12 = v12 ? lisp_true : nil;
    env = stack[-4];
    if (v12 == nil) goto v168;
    v13 = stack[-3];
    v12 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* pasf_smordtable2 */
        return (*qfn2(fn))(qenv(fn), v13, v12);
    }

v168:
    v13 = stack[-1];
    v12 = stack[0];
    v12 = (Lisp_Object)greaterp2(v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v16;
    v12 = v12 ? lisp_true : nil;
    env = stack[-4];
    if (v12 == nil) goto v26;
    v13 = stack[-3];
    v12 = stack[-2];
    {
        popv(5);
        fn = elt(env, 4); /* pasf_smordtable1 */
        return (*qfn2(fn))(qenv(fn), v13, v12);
    }

v26:
    v12 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v12 == nil)) goto v213;
    v12 = elt(env, 2); /* "abused smordtable" */
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-4];
    fn = elt(env, 5); /* lprie */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-4];
    goto v213;

v213:
    v12 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v16;
    v12 = nil;
    { popv(5); return onevalue(v12); }
/* error exit handlers */
v16:
    popv(5);
    return nil;
}



/* Code for dvfsf_simplat1 */

static Lisp_Object CC_dvfsf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v215, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_simplat1");
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
    v16 = stack[-2];
    fn = elt(env, 4); /* dvfsf_op */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    v70 = v16;
    v215 = v70;
    v16 = elt(env, 1); /* equal */
    if (v215 == v16) goto v66;
    v215 = v70;
    v16 = elt(env, 3); /* neq */
    v16 = (v215 == v16 ? lisp_true : nil);
    goto v214;

v214:
    if (v16 == nil) goto v76;
    stack[0] = v70;
    v16 = stack[-2];
    fn = elt(env, 5); /* dvfsf_arg2l */
    v215 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    v16 = stack[-1];
    {
        Lisp_Object v202 = stack[0];
        popv(5);
        fn = elt(env, 6); /* dvfsf_safield */
        return (*qfnn(fn))(qenv(fn), 3, v202, v215, v16);
    }

v76:
    stack[-3] = v70;
    v16 = stack[-2];
    fn = elt(env, 5); /* dvfsf_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    v16 = stack[-2];
    fn = elt(env, 7); /* dvfsf_arg2r */
    v215 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    v16 = stack[-1];
    {
        Lisp_Object v284 = stack[-3];
        Lisp_Object v69 = stack[0];
        popv(5);
        fn = elt(env, 8); /* dvfsf_saval */
        return (*qfnn(fn))(qenv(fn), 4, v284, v69, v215, v16);
    }

v66:
    v16 = qvalue(elt(env, 2)); /* t */
    goto v214;
/* error exit handlers */
v32:
    popv(5);
    return nil;
}



/* Code for minusrd */

static Lisp_Object MS_CDECL CC_minusrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "minusrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusrd");
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
    v45 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    stack[0] = v45;
    fn = elt(env, 1); /* mathml */
    v45 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    v197 = v45;
    if (v197 == nil) goto v15;
    v197 = stack[0];
    fn = elt(env, 2); /* alg_difference */
    v45 = (*qfn2(fn))(qenv(fn), v197, v45);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    stack[0] = v45;
    fn = elt(env, 3); /* lex */
    v45 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v43;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v15:
    v45 = stack[0];
    fn = elt(env, 4); /* alg_minus */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v43;
    stack[0] = v45;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v43:
    popv(2);
    return nil;
}



/* Code for freeof */

static Lisp_Object CC_freeof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v36, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof");
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
    v36 = stack[0];
    v44 = stack[-1];
    fn = elt(env, 2); /* smember */
    v44 = (*qfn2(fn))(qenv(fn), v36, v44);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    if (!(v44 == nil)) goto v6;
    v36 = stack[0];
    v44 = stack[-1];
    v19 = qvalue(elt(env, 1)); /* depl!* */
    v44 = Lassoc(nil, v44, v19);
    v44 = Lmember(nil, v36, v44);
    goto v6;

v6:
    v44 = (v44 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v44); }
/* error exit handlers */
v65:
    popv(3);
    return nil;
}



/* Code for matsm1 */

static Lisp_Object CC_matsm1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v354, v355, v356;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm1");
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
/* copy arguments values to proper place */
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    goto v169;

v169:
    v354 = stack[-8];
    if (v354 == nil) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v354 = stack[-8];
    v355 = qcar(v354);
    v354 = elt(env, 1); /* !*div */
    if (!consp(v355)) goto v17;
    v355 = qcar(v355);
    if (!(v355 == v354)) goto v17;
    v354 = stack[-8];
    v354 = qcar(v354);
    v354 = qcdr(v354);
    v354 = qcar(v354);
    fn = elt(env, 19); /* matsm */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-2] = v354;
    v354 = stack[-2];
    v354 = qcar(v354);
    stack[0] = Llength(nil, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-1] = stack[0];
    v354 = stack[-2];
    v354 = Llength(nil, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    if (equal(stack[0], v354)) goto v77;
    v354 = elt(env, 10); /* "Non square matrix" */
    v355 = v354;
    v354 = v355;
    qvalue(elt(env, 7)) = v354; /* errmsg!* */
    v354 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v354 == nil)) goto v358;
    v354 = v355;
    fn = elt(env, 20); /* lprie */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v358;

v358:
    v354 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v359;

v359:
    v354 = qvalue(elt(env, 11)); /* subfg!* */
    stack[0] = v354;
    v354 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 11)) = v354; /* subfg!* */
    v354 = stack[-9];
    if (v354 == nil) goto v360;
    v355 = elt(env, 2); /* mat */
    v354 = elt(env, 13); /* lnrsolvefn */
    v354 = get(v355, v354);
    env = stack[-10];
    stack[0] = v354;
    if (v354 == nil) goto v361;
    v355 = elt(env, 2); /* mat */
    v354 = elt(env, 13); /* lnrsolvefn */
    v356 = get(v355, v354);
    env = stack[-10];
    v355 = stack[-2];
    v354 = stack[-9];
    v354 = Lapply2(nil, 3, v356, v355, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-9] = v354;
    goto v362;

v362:
    v354 = stack[0];
    qvalue(elt(env, 11)) = v354; /* subfg!* */
    v354 = stack[-9];
    stack[-7] = v354;
    v354 = stack[-7];
    if (v354 == nil) goto v363;
    v354 = stack[-7];
    v354 = qcar(v354);
    stack[-3] = v354;
    v354 = stack[-3];
    if (v354 == nil) goto v364;
    v354 = stack[-3];
    v354 = qcar(v354);
    v355 = v354;
    v354 = qvalue(elt(env, 14)); /* t */
    qvalue(elt(env, 15)) = v354; /* !*sub2 */
    v354 = v355;
    fn = elt(env, 21); /* subs2 */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-1] = v354;
    stack[-2] = v354;
    goto v365;

v365:
    v354 = stack[-3];
    v354 = qcdr(v354);
    stack[-3] = v354;
    v354 = stack[-3];
    if (v354 == nil) goto v366;
    stack[0] = stack[-1];
    v354 = stack[-3];
    v354 = qcar(v354);
    v355 = v354;
    v354 = qvalue(elt(env, 14)); /* t */
    qvalue(elt(env, 15)) = v354; /* !*sub2 */
    v354 = v355;
    fn = elt(env, 21); /* subs2 */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = Lrplacd(nil, stack[0], v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = stack[-1];
    v354 = qcdr(v354);
    stack[-1] = v354;
    goto v365;

v366:
    v354 = stack[-2];
    goto v367;

v367:
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-5] = v354;
    stack[-6] = v354;
    goto v368;

v368:
    v354 = stack[-7];
    v354 = qcdr(v354);
    stack[-7] = v354;
    v354 = stack[-7];
    if (v354 == nil) goto v369;
    stack[-4] = stack[-5];
    v354 = stack[-7];
    v354 = qcar(v354);
    stack[-3] = v354;
    v354 = stack[-3];
    if (v354 == nil) goto v370;
    v354 = stack[-3];
    v354 = qcar(v354);
    v355 = v354;
    v354 = qvalue(elt(env, 14)); /* t */
    qvalue(elt(env, 15)) = v354; /* !*sub2 */
    v354 = v355;
    fn = elt(env, 21); /* subs2 */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-1] = v354;
    stack[-2] = v354;
    goto v371;

v371:
    v354 = stack[-3];
    v354 = qcdr(v354);
    stack[-3] = v354;
    v354 = stack[-3];
    if (v354 == nil) goto v372;
    stack[0] = stack[-1];
    v354 = stack[-3];
    v354 = qcar(v354);
    v355 = v354;
    v354 = qvalue(elt(env, 14)); /* t */
    qvalue(elt(env, 15)) = v354; /* !*sub2 */
    v354 = v355;
    fn = elt(env, 21); /* subs2 */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = Lrplacd(nil, stack[0], v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = stack[-1];
    v354 = qcdr(v354);
    stack[-1] = v354;
    goto v371;

v372:
    v354 = stack[-2];
    goto v373;

v373:
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = Lrplacd(nil, stack[-4], v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = stack[-5];
    v354 = qcdr(v354);
    stack[-5] = v354;
    goto v368;

v370:
    v354 = qvalue(elt(env, 4)); /* nil */
    goto v373;

v369:
    v354 = stack[-6];
    goto v374;

v374:
    stack[-9] = v354;
    goto v132;

v132:
    v354 = stack[-8];
    v354 = qcdr(v354);
    stack[-8] = v354;
    goto v169;

v364:
    v354 = qvalue(elt(env, 4)); /* nil */
    goto v367;

v363:
    v354 = qvalue(elt(env, 4)); /* nil */
    goto v374;

v361:
    v355 = elt(env, 2); /* mat */
    v354 = elt(env, 12); /* inversefn */
    v355 = get(v355, v354);
    env = stack[-10];
    v354 = stack[-2];
    v355 = Lapply1(nil, v355, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = stack[-9];
    fn = elt(env, 22); /* multm */
    v354 = (*qfn2(fn))(qenv(fn), v355, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-9] = v354;
    goto v362;

v360:
    v355 = elt(env, 2); /* mat */
    v354 = elt(env, 12); /* inversefn */
    v355 = get(v355, v354);
    env = stack[-10];
    v354 = stack[-2];
    v354 = Lapply1(nil, v355, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-9] = v354;
    goto v362;

v77:
    v354 = stack[-9];
    if (v354 == nil) goto v375;
    stack[0] = stack[-1];
    v354 = stack[-9];
    v354 = Llength(nil, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    if (equal(stack[0], v354)) goto v375;
    v354 = elt(env, 6); /* "Matrix mismatch" */
    v355 = v354;
    v354 = v355;
    qvalue(elt(env, 7)) = v354; /* errmsg!* */
    v354 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v354 == nil)) goto v376;
    v354 = v355;
    fn = elt(env, 20); /* lprie */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v376;

v376:
    v354 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v359;

v375:
    v354 = stack[-8];
    v354 = qcar(v354);
    v354 = qcdr(v354);
    v354 = qcdr(v354);
    if (v354 == nil) goto v377;
    v354 = stack[-9];
    if (!(v354 == nil)) goto v132;
    v354 = stack[-1];
    fn = elt(env, 23); /* generateident */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-9] = v354;
    goto v132;

v377:
    v354 = stack[-2];
    v354 = qcdr(v354);
    if (v354 == nil) goto v378;
    v354 = qvalue(elt(env, 4)); /* nil */
    goto v379;

v379:
    if (v354 == nil) goto v359;
    v354 = stack[-2];
    v354 = qcar(v354);
    v354 = qcar(v354);
    v354 = qcar(v354);
    if (!(v354 == nil)) goto v380;
    v354 = elt(env, 16); /* "Zero divisor" */
    v355 = v354;
    v354 = v355;
    qvalue(elt(env, 7)) = v354; /* errmsg!* */
    v354 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v354 == nil)) goto v381;
    v354 = v355;
    fn = elt(env, 20); /* lprie */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v381;

v381:
    v354 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v380;

v380:
    v354 = stack[-2];
    v354 = qcar(v354);
    v354 = qcar(v354);
    v355 = qcdr(v354);
    v354 = stack[-2];
    v354 = qcar(v354);
    v354 = qcar(v354);
    v354 = qcar(v354);
    v354 = cons(v355, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-2] = v354;
    v354 = stack[-9];
    if (v354 == nil) goto v382;
    v355 = stack[-2];
    v354 = stack[-9];
    fn = elt(env, 24); /* multsm */
    v354 = (*qfn2(fn))(qenv(fn), v355, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v383;

v383:
    stack[-9] = v354;
    goto v132;

v382:
    v354 = stack[-2];
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v383;

v378:
    v354 = stack[-2];
    v354 = qcar(v354);
    v354 = qcdr(v354);
    v354 = (v354 == nil ? lisp_true : nil);
    goto v379;

v17:
    v354 = stack[-8];
    v354 = qcar(v354);
    if (!consp(v354)) goto v384;
    v354 = stack[-8];
    v354 = qcar(v354);
    v355 = qcar(v354);
    v354 = elt(env, 2); /* mat */
    if (v355 == v354) goto v39;
    v354 = stack[-8];
    v354 = qcar(v354);
    v355 = qcar(v354);
    v354 = elt(env, 3); /* matmapfn */
    v354 = Lflagp(nil, v355, v354);
    env = stack[-10];
    if (v354 == nil) goto v205;
    v354 = stack[-8];
    v354 = qcar(v354);
    v354 = qcdr(v354);
    if (v354 == nil) goto v56;
    v354 = stack[-8];
    v354 = qcar(v354);
    v354 = qcdr(v354);
    v354 = qcar(v354);
    fn = elt(env, 25); /* getrtype */
    v355 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = elt(env, 5); /* matrix */
    v354 = (v355 == v354 ? lisp_true : nil);
    goto v4;

v4:
    if (v354 == nil) goto v193;
    v354 = stack[-8];
    v355 = qcar(v354);
    v354 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 26); /* matrixmap */
    v354 = (*qfn2(fn))(qenv(fn), v355, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    fn = elt(env, 19); /* matsm */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[0] = v354;
    goto v15;

v15:
    v354 = stack[-9];
    if (v354 == nil) goto v385;
    v354 = stack[-9];
    v354 = qcdr(v354);
    if (v354 == nil) goto v144;
    v354 = qvalue(elt(env, 4)); /* nil */
    goto v277;

v277:
    if (v354 == nil) goto v149;
    v354 = stack[-9];
    v354 = qcar(v354);
    v355 = qcar(v354);
    v354 = stack[0];
    fn = elt(env, 24); /* multsm */
    v354 = (*qfn2(fn))(qenv(fn), v355, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v276;

v276:
    stack[-9] = v354;
    goto v132;

v149:
    v355 = stack[0];
    v354 = stack[-9];
    fn = elt(env, 22); /* multm */
    v354 = (*qfn2(fn))(qenv(fn), v355, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v276;

v144:
    v354 = stack[-9];
    v354 = qcar(v354);
    v354 = qcdr(v354);
    v354 = (v354 == nil ? lisp_true : nil);
    goto v277;

v385:
    v354 = stack[0];
    goto v276;

v193:
    v354 = stack[-8];
    v354 = qcar(v354);
    v355 = qcar(v354);
    v354 = stack[-8];
    v354 = qcar(v354);
    v354 = qcdr(v354);
    fn = elt(env, 27); /* lispapply */
    v354 = (*qfn2(fn))(qenv(fn), v355, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[0] = v354;
    v355 = stack[0];
    v354 = elt(env, 2); /* mat */
    if (!consp(v355)) goto v15;
    v355 = qcar(v355);
    if (!(v355 == v354)) goto v15;
    v354 = stack[0];
    fn = elt(env, 19); /* matsm */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[0] = v354;
    goto v15;

v56:
    v354 = qvalue(elt(env, 4)); /* nil */
    goto v4;

v205:
    v354 = qvalue(elt(env, 4)); /* nil */
    goto v4;

v39:
    v354 = stack[-8];
    v354 = qcar(v354);
    v354 = qcdr(v354);
    fn = elt(env, 28); /* lchk */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    if (!(v354 == nil)) goto v148;
    v354 = elt(env, 6); /* "Matrix mismatch" */
    v355 = v354;
    v354 = v355;
    qvalue(elt(env, 7)) = v354; /* errmsg!* */
    v354 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v354 == nil)) goto v183;
    v354 = v355;
    fn = elt(env, 20); /* lprie */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v183;

v183:
    v354 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v148;

v148:
    v354 = stack[-8];
    v354 = qcar(v354);
    v354 = qcdr(v354);
    stack[-7] = v354;
    v354 = stack[-7];
    if (v354 == nil) goto v386;
    v354 = stack[-7];
    v354 = qcar(v354);
    stack[-3] = v354;
    v354 = stack[-3];
    if (v354 == nil) goto v260;
    v354 = stack[-3];
    v354 = qcar(v354);
    fn = elt(env, 29); /* simp!* */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v355 = v354;
    v354 = qvalue(elt(env, 9)); /* !*exp */
    if (v354 == nil) goto v257;
    v354 = v355;
    goto v105;

v105:
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-1] = v354;
    stack[-2] = v354;
    goto v155;

v155:
    v354 = stack[-3];
    v354 = qcdr(v354);
    stack[-3] = v354;
    v354 = stack[-3];
    if (v354 == nil) goto v170;
    stack[0] = stack[-1];
    v354 = stack[-3];
    v354 = qcar(v354);
    fn = elt(env, 29); /* simp!* */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v355 = v354;
    v354 = qvalue(elt(env, 9)); /* !*exp */
    if (v354 == nil) goto v93;
    v354 = v355;
    goto v387;

v387:
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = Lrplacd(nil, stack[0], v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = stack[-1];
    v354 = qcdr(v354);
    stack[-1] = v354;
    goto v155;

v93:
    v354 = v355;
    fn = elt(env, 30); /* offexpchk */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v387;

v170:
    v354 = stack[-2];
    goto v103;

v103:
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-5] = v354;
    stack[-6] = v354;
    goto v111;

v111:
    v354 = stack[-7];
    v354 = qcdr(v354);
    stack[-7] = v354;
    v354 = stack[-7];
    if (v354 == nil) goto v97;
    stack[-4] = stack[-5];
    v354 = stack[-7];
    v354 = qcar(v354);
    stack[-3] = v354;
    v354 = stack[-3];
    if (v354 == nil) goto v252;
    v354 = stack[-3];
    v354 = qcar(v354);
    fn = elt(env, 29); /* simp!* */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v355 = v354;
    v354 = qvalue(elt(env, 9)); /* !*exp */
    if (v354 == nil) goto v248;
    v354 = v355;
    goto v388;

v388:
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    stack[-1] = v354;
    stack[-2] = v354;
    goto v389;

v389:
    v354 = stack[-3];
    v354 = qcdr(v354);
    stack[-3] = v354;
    v354 = stack[-3];
    if (v354 == nil) goto v390;
    stack[0] = stack[-1];
    v354 = stack[-3];
    v354 = qcar(v354);
    fn = elt(env, 29); /* simp!* */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v355 = v354;
    v354 = qvalue(elt(env, 9)); /* !*exp */
    if (v354 == nil) goto v82;
    v354 = v355;
    goto v391;

v391:
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = Lrplacd(nil, stack[0], v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = stack[-1];
    v354 = qcdr(v354);
    stack[-1] = v354;
    goto v389;

v82:
    v354 = v355;
    fn = elt(env, 30); /* offexpchk */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v391;

v390:
    v354 = stack[-2];
    goto v392;

v392:
    v354 = ncons(v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = Lrplacd(nil, stack[-4], v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v354 = stack[-5];
    v354 = qcdr(v354);
    stack[-5] = v354;
    goto v111;

v248:
    v354 = v355;
    fn = elt(env, 30); /* offexpchk */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v388;

v252:
    v354 = qvalue(elt(env, 4)); /* nil */
    goto v392;

v97:
    v354 = stack[-6];
    goto v279;

v279:
    stack[0] = v354;
    goto v15;

v257:
    v354 = v355;
    fn = elt(env, 30); /* offexpchk */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v105;

v260:
    v354 = qvalue(elt(env, 4)); /* nil */
    goto v103;

v386:
    v354 = qvalue(elt(env, 4)); /* nil */
    goto v279;

v384:
    v356 = elt(env, 17); /* "Matrix" */
    v354 = stack[-8];
    v355 = qcar(v354);
    v354 = elt(env, 18); /* "not set" */
    v354 = list3(v356, v355, v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    v355 = v354;
    v354 = v355;
    qvalue(elt(env, 7)) = v354; /* errmsg!* */
    v354 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v354 == nil)) goto v393;
    v354 = v355;
    fn = elt(env, 20); /* lprie */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-10];
    goto v393;

v393:
    v354 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v357;
    v354 = nil;
    { popv(11); return onevalue(v354); }
/* error exit handlers */
v357:
    popv(11);
    return nil;
}



/* Code for newsym1 */

static Lisp_Object MS_CDECL CC_newsym1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v35;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "newsym1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newsym1");
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
    v27 = qvalue(elt(env, 1)); /* cindex!* */
    v27 = Lexplode(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-1];
    stack[0] = v27;
    v27 = qvalue(elt(env, 1)); /* cindex!* */
    v27 = add1(v27);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-1];
    qvalue(elt(env, 1)) = v27; /* cindex!* */
    v35 = qvalue(elt(env, 2)); /* cname!* */
    v27 = stack[0];
    v27 = Lappend(nil, v35, v27);
    nil = C_nil;
    if (exception_pending()) goto v11;
        popv(2);
        return Lcompress(nil, v27);
/* error exit handlers */
v11:
    popv(2);
    return nil;
}



/* Code for den */

static Lisp_Object CC_den(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for den");
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
    v214 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[0];
    v66 = qcdr(v214);
    v214 = (Lisp_Object)17; /* 1 */
    v214 = cons(v66, v214);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v214);
    }
/* error exit handlers */
v67:
    popv(1);
    return nil;
}



/* Code for matsm */

static Lisp_Object CC_matsm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm");
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
    v13 = v0;
/* end of prologue */
    stack[-2] = nil;
    v14 = v13;
    v13 = elt(env, 1); /* matrix */
    fn = elt(env, 3); /* nssimp */
    v13 = (*qfn2(fn))(qenv(fn), v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    stack[-1] = v13;
    goto v15;

v15:
    v13 = stack[-1];
    if (v13 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v13 = stack[-1];
    v13 = qcar(v13);
    v14 = v13;
    v13 = v14;
    stack[0] = qcar(v13);
    v13 = v14;
    v13 = qcdr(v13);
    fn = elt(env, 4); /* matsm1 */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    fn = elt(env, 5); /* multsm */
    v13 = (*qfn2(fn))(qenv(fn), stack[0], v13);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    v14 = stack[-2];
    if (v14 == nil) goto v24;
    v14 = stack[-2];
    fn = elt(env, 6); /* addm */
    v13 = (*qfn2(fn))(qenv(fn), v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    goto v24;

v24:
    stack[-2] = v13;
    v13 = stack[-1];
    v13 = qcdr(v13);
    stack[-1] = v13;
    goto v15;
/* error exit handlers */
v16:
    popv(4);
    return nil;
}



/* Code for simpsetdiff */

static Lisp_Object CC_simpsetdiff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v394, v395, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsetdiff");
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
    v394 = v0;
/* end of prologue */
    v395 = elt(env, 1); /* setdiff */
    fn = elt(env, 4); /* applysetop */
    v394 = (*qfn2(fn))(qenv(fn), v395, v394);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[0];
    v193 = v394;
    v394 = v193;
    v395 = qcar(v394);
    v394 = elt(env, 1); /* setdiff */
    if (v395 == v394) goto v28;
    v394 = v193;
    goto v19;

v19:
    fn = elt(env, 5); /* fkern */
    v395 = (*qfn1(fn))(qenv(fn), v394);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[0];
    v394 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 6); /* getpower */
    v395 = (*qfn2(fn))(qenv(fn), v395, v394);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[0];
    v394 = (Lisp_Object)17; /* 1 */
    v394 = cons(v395, v394);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[0];
    v395 = ncons(v394);
    nil = C_nil;
    if (exception_pending()) goto v203;
    v394 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v395, v394);

v28:
    v394 = v193;
    v394 = qcdr(v394);
    v395 = qcar(v394);
    v394 = v193;
    v394 = qcdr(v394);
    v394 = qcdr(v394);
    v394 = qcar(v394);
    if (equal(v395, v394)) goto v216;
    v394 = v193;
    v394 = qcdr(v394);
    v395 = qcar(v394);
    v394 = qvalue(elt(env, 3)); /* empty_set */
    v394 = (equal(v395, v394) ? lisp_true : nil);
    goto v213;

v213:
    if (v394 == nil) goto v75;
    v394 = qvalue(elt(env, 3)); /* empty_set */
    goto v19;

v75:
    v394 = v193;
    v394 = qcdr(v394);
    v394 = qcdr(v394);
    v395 = qcar(v394);
    v394 = qvalue(elt(env, 3)); /* empty_set */
    if (equal(v395, v394)) goto v38;
    v394 = v193;
    goto v19;

v38:
    v394 = v193;
    v394 = qcdr(v394);
    v394 = qcar(v394);
    goto v19;

v216:
    v394 = qvalue(elt(env, 2)); /* t */
    goto v213;
/* error exit handlers */
v203:
    popv(1);
    return nil;
}



/* Code for natnump */

static Lisp_Object CC_natnump(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for natnump");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v0;
/* end of prologue */
    v10 = v11;
    v10 = integerp(v10);
    if (v10 == nil) goto v6;
    v10 = (Lisp_Object)1; /* 0 */
        return Lgeq(nil, v11, v10);

v6:
    v10 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v10);
}



/* Code for mkforttab */

static Lisp_Object MS_CDECL CC_mkforttab(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v27;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkforttab");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkforttab");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    stack[0] = elt(env, 1); /* forttab */
    v27 = qvalue(elt(env, 2)); /* fortcurrind!* */
    v62 = (Lisp_Object)97; /* 6 */
    v62 = plus2(v27, v62);
    nil = C_nil;
    if (exception_pending()) goto v10;
    {
        Lisp_Object v11 = stack[0];
        popv(1);
        return list2(v11, v62);
    }
/* error exit handlers */
v10:
    popv(1);
    return nil;
}



/* Code for ev!-poles */

static Lisp_Object CC_evKpoles(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v9, v7, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-poles");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v1;
    v7 = v0;
/* end of prologue */

v52:
    v65 = v7;
    if (v65 == nil) goto v169;
    v65 = v7;
    v9 = qcar(v65);
    v65 = v8;
    v65 = Lassoc(nil, v9, v65);
    v9 = qcdr(v65);
    v65 = (Lisp_Object)1; /* 0 */
    if (!(v9 == v65)) return onevalue(v7);
    v65 = v7;
    v65 = qcdr(v65);
    v7 = v65;
    goto v52;

v169:
    v65 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v65);
}



/* Code for extract_vars */

static Lisp_Object CC_extract_vars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extract_vars");
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
    goto v52;

v52:
    v25 = stack[0];
    if (v25 == nil) goto v169;
    v25 = stack[0];
    v25 = qcar(v25);
    fn = elt(env, 2); /* raiseind!: */
    v57 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    v25 = elt(env, 1); /* variable */
    v25 = Lflagp(nil, v57, v25);
    env = stack[-2];
    if (v25 == nil) goto v9;
    v25 = stack[0];
    v57 = qcar(v25);
    v25 = stack[-1];
    v25 = cons(v57, v25);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    stack[-1] = v25;
    v25 = stack[0];
    v25 = qcdr(v25);
    stack[0] = v25;
    goto v52;

v9:
    v25 = stack[0];
    v25 = qcdr(v25);
    stack[0] = v25;
    goto v52;

v169:
    v25 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v25);
    }
/* error exit handlers */
v73:
    popv(3);
    return nil;
}



/* Code for f2df */

static Lisp_Object CC_f2df(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v126, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2df");
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
    v125 = stack[0];
    if (!consp(v125)) goto v169;
    v125 = stack[0];
    v125 = qcar(v125);
    v125 = (consp(v125) ? nil : lisp_true);
    goto v41;

v41:
    if (v125 == nil) goto v168;
    v126 = stack[0];
    v125 = (Lisp_Object)17; /* 1 */
    v125 = cons(v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* dfconst */
        return (*qfn1(fn))(qenv(fn), v125);
    }

v168:
    v125 = stack[0];
    v125 = qcar(v125);
    v125 = qcar(v125);
    v126 = qcar(v125);
    v125 = qvalue(elt(env, 2)); /* zlist */
    v125 = Lmember(nil, v126, v125);
    if (v125 == nil) goto v59;
    v125 = stack[0];
    v125 = qcar(v125);
    v125 = qcar(v125);
    v142 = qcar(v125);
    v125 = stack[0];
    v125 = qcar(v125);
    v125 = qcar(v125);
    v126 = qcdr(v125);
    v125 = qvalue(elt(env, 2)); /* zlist */
    fn = elt(env, 5); /* vp2df */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v142, v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    v125 = stack[0];
    v125 = qcar(v125);
    v125 = qcdr(v125);
    v125 = CC_f2df(env, v125);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    fn = elt(env, 6); /* multdf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v125);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    v125 = stack[0];
    v125 = qcdr(v125);
    v125 = CC_f2df(env, v125);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    {
        Lisp_Object v396 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v396, v125);
    }

v59:
    v125 = stack[0];
    v125 = qcar(v125);
    v126 = qcar(v125);
    v125 = (Lisp_Object)17; /* 1 */
    v142 = cons(v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    v126 = qvalue(elt(env, 3)); /* nil */
    v125 = (Lisp_Object)17; /* 1 */
    stack[-1] = acons(v142, v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    v125 = stack[0];
    v125 = qcar(v125);
    v125 = qcdr(v125);
    v125 = CC_f2df(env, v125);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    fn = elt(env, 8); /* multdfconst */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v125);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    v125 = stack[0];
    v125 = qcdr(v125);
    v125 = CC_f2df(env, v125);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-2];
    {
        Lisp_Object v123 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v123, v125);
    }

v169:
    v125 = qvalue(elt(env, 1)); /* t */
    goto v41;
/* error exit handlers */
v235:
    popv(3);
    return nil;
}



/* Code for specrd!:plus */

static Lisp_Object CC_specrdTplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v225;
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
    v224 = (Lisp_Object)1; /* 0 */
    stack[-2] = v224;
    v224 = stack[-1];
    fn = elt(env, 3); /* add_minus */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    stack[-1] = v224;
    v224 = stack[0];
    fn = elt(env, 3); /* add_minus */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    stack[0] = v224;
    v225 = stack[-1];
    v224 = elt(env, 1); /* minus */
    if (!consp(v225)) goto v19;
    v225 = qcar(v225);
    if (!(v225 == v224)) goto v19;
    v224 = stack[-1];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    stack[-1] = v224;
    v224 = (Lisp_Object)17; /* 1 */
    stack[-2] = v224;
    goto v19;

v19:
    v225 = stack[0];
    v224 = elt(env, 1); /* minus */
    if (!consp(v225)) goto v168;
    v225 = qcar(v225);
    if (!(v225 == v224)) goto v168;
    v224 = stack[0];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    stack[0] = v224;
    v225 = stack[-2];
    v224 = (Lisp_Object)33; /* 2 */
    v224 = plus2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    stack[-2] = v224;
    goto v168;

v168:
    v224 = stack[-1];
    if (!(!consp(v224))) goto v28;
    v224 = stack[-1];
    v224 = Lfloat(nil, v224);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v225 = v224;
    if (!(!consp(v225))) goto v196;
    v225 = elt(env, 2); /* !:rd!: */
    v224 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v196;

v196:
    stack[-1] = v224;
    goto v28;

v28:
    v224 = stack[0];
    if (!(!consp(v224))) goto v395;
    v224 = stack[0];
    v224 = Lfloat(nil, v224);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v225 = v224;
    if (!(!consp(v225))) goto v201;
    v225 = elt(env, 2); /* !:rd!: */
    v224 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    goto v201;

v201:
    stack[0] = v224;
    goto v395;

v395:
    v225 = stack[-2];
    v224 = (Lisp_Object)1; /* 0 */
    if (v225 == v224) goto v195;
    v225 = stack[-2];
    v224 = (Lisp_Object)49; /* 3 */
    if (v225 == v224) goto v187;
    v225 = stack[-2];
    v224 = (Lisp_Object)33; /* 2 */
    if (v225 == v224) goto v120;
    v225 = stack[0];
    v224 = stack[-1];
    {
        popv(4);
        fn = elt(env, 4); /* rd!:difference */
        return (*qfn2(fn))(qenv(fn), v225, v224);
    }

v120:
    v225 = stack[-1];
    v224 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* rd!:difference */
        return (*qfn2(fn))(qenv(fn), v225, v224);
    }

v187:
    stack[-2] = elt(env, 1); /* minus */
    v225 = stack[-1];
    v224 = stack[0];
    fn = elt(env, 5); /* rd!:plus */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v207;
    {
        Lisp_Object v238 = stack[-2];
        popv(4);
        return list2(v238, v224);
    }

v195:
    v225 = stack[-1];
    v224 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* rd!:plus */
        return (*qfn2(fn))(qenv(fn), v225, v224);
    }
/* error exit handlers */
v207:
    popv(4);
    return nil;
}



/* Code for dip2a */

static Lisp_Object CC_dip2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v66;
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
    v66 = v0;
/* end of prologue */
    v214 = v66;
    if (v214 == nil) goto v6;
    v214 = v66;
    fn = elt(env, 1); /* dip2a1 */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dipreplus */
        return (*qfn1(fn))(qenv(fn), v214);
    }

v6:
    v214 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v214); }
/* error exit handlers */
v67:
    popv(1);
    return nil;
}



/* Code for vdpilcomb1 */

static Lisp_Object MS_CDECL CC_vdpilcomb1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v33, Lisp_Object v5,
                         Lisp_Object v6, Lisp_Object v52, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v401, v75, v127, v140, v283, v201;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "vdpilcomb1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpilcomb1");
#endif
    if (stack >= stacklimit)
    {
        push6(v52,v6,v5,v33,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v33,v5,v6,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v52;
    v401 = v6;
    stack[-2] = v5;
    stack[-3] = v33;
    v75 = v1;
    stack[-4] = v0;
/* end of prologue */
    v127 = stack[-4];
    v127 = qcdr(v127);
    v127 = qcdr(v127);
    v127 = qcdr(v127);
    v201 = qcar(v127);
    v283 = v75;
    v140 = stack[-3];
    v75 = stack[-2];
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    v127 = qcar(v75);
    v75 = v401;
    v401 = stack[-1];
    fn = elt(env, 2); /* dipilcomb1 */
    v401 = (*qfnn(fn))(qenv(fn), 6, v201, v283, v140, v127, v75, v401);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-6];
    fn = elt(env, 3); /* dip2vdp */
    v401 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-6];
    stack[-5] = v401;
    v401 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v401 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    stack[0] = stack[-5];
    v401 = stack[-4];
    fn = elt(env, 4); /* gsugar */
    stack[-4] = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-6];
    v401 = stack[-3];
    fn = elt(env, 5); /* vevtdeg */
    v401 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-6];
    stack[-3] = plus2(stack[-4], v401);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-6];
    v401 = stack[-2];
    fn = elt(env, 4); /* gsugar */
    stack[-2] = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-6];
    v401 = stack[-1];
    fn = elt(env, 5); /* vevtdeg */
    v401 = (*qfn1(fn))(qenv(fn), v401);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-6];
    v401 = plus2(stack[-2], v401);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-6];
    fn = elt(env, 6); /* max */
    v401 = (*qfn2(fn))(qenv(fn), stack[-3], v401);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-6];
    fn = elt(env, 7); /* gsetsugar */
    v401 = (*qfn2(fn))(qenv(fn), stack[0], v401);
    nil = C_nil;
    if (exception_pending()) goto v129;
    { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
/* error exit handlers */
v129:
    popv(7);
    return nil;
}



/* Code for simpwedge */

static Lisp_Object CC_simpwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52;
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
    v52 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitwedge */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v52);
    }
/* error exit handlers */
v18:
    popv(1);
    return nil;
}



/* Code for rsubla */

static Lisp_Object CC_rsubla(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v31;
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
    v56 = stack[-1];
    if (v56 == nil) goto v137;
    v56 = stack[0];
    v56 = (v56 == nil ? lisp_true : nil);
    goto v39;

v39:
    if (!(v56 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v56 = stack[0];
    if (!consp(v56)) goto v43;
    v31 = stack[-1];
    v56 = stack[0];
    v56 = qcar(v56);
    stack[-2] = CC_rsubla(env, v31, v56);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v31 = stack[-1];
    v56 = stack[0];
    v56 = qcdr(v56);
    v56 = CC_rsubla(env, v31, v56);
    nil = C_nil;
    if (exception_pending()) goto v69;
    {
        Lisp_Object v29 = stack[-2];
        popv(4);
        return cons(v29, v56);
    }

v43:
    v31 = stack[0];
    v56 = stack[-1];
    fn = elt(env, 2); /* rassoc */
    v56 = (*qfn2(fn))(qenv(fn), v31, v56);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v31 = v56;
    if (v56 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v56 = v31;
    v56 = qcar(v56);
    { popv(4); return onevalue(v56); }

v137:
    v56 = qvalue(elt(env, 1)); /* t */
    goto v39;
/* error exit handlers */
v69:
    popv(4);
    return nil;
}



/* Code for physoptimes */

static Lisp_Object CC_physoptimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v404, v99;
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
    v99 = qvalue(elt(env, 1)); /* tstack!* */
    v404 = (Lisp_Object)1; /* 0 */
    if (v99 == v404) goto v35;
    v404 = qvalue(elt(env, 3)); /* nil */
    goto v27;

v27:
    if (v404 == nil) goto v214;
    v404 = qvalue(elt(env, 2)); /* mul!* */
    stack[-2] = v404;
    v404 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v404; /* mul!* */
    goto v214;

v214:
    v404 = qvalue(elt(env, 1)); /* tstack!* */
    v404 = add1(v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    qvalue(elt(env, 1)) = v404; /* tstack!* */
    v404 = stack[0];
    v404 = qcar(v404);
    fn = elt(env, 6); /* physopsim!* */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-6] = v404;
    v404 = stack[0];
    v404 = qcdr(v404);
    stack[-1] = v404;
    goto v58;

v58:
    v404 = stack[-1];
    if (v404 == nil) goto v132;
    v404 = stack[-1];
    v404 = qcar(v404);
    fn = elt(env, 6); /* physopsim!* */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-5] = v404;
    v404 = stack[-6];
    fn = elt(env, 7); /* getphystype */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-4] = v404;
    v404 = stack[-5];
    fn = elt(env, 7); /* getphystype */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-3] = v404;
    v404 = stack[-4];
    if (v404 == nil) goto v16;
    v404 = stack[-3];
    if (v404 == nil) goto v231;
    v404 = stack[-6];
    fn = elt(env, 8); /* physopaeval */
    stack[0] = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v404 = stack[-5];
    fn = elt(env, 8); /* physopaeval */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 9); /* physopordchk */
    v404 = (*qfn2(fn))(qenv(fn), stack[0], v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    if (v404 == nil) goto v261;
    v99 = stack[-4];
    v404 = stack[-3];
    if (equal(v99, v404)) goto v114;
    v404 = qvalue(elt(env, 3)); /* nil */
    goto v346;

v346:
    if (v404 == nil) goto v261;
    v404 = stack[-6];
    fn = elt(env, 10); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v404 = stack[-5];
    fn = elt(env, 10); /* physop2sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 11); /* multsq */
    v404 = (*qfn2(fn))(qenv(fn), stack[0], v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-6] = v404;
    goto v130;

v130:
    v404 = stack[-1];
    v404 = qcdr(v404);
    stack[-1] = v404;
    goto v58;

v261:
    v99 = stack[-6];
    v404 = stack[-5];
    fn = elt(env, 13); /* multopop!* */
    v404 = (*qfn2(fn))(qenv(fn), v99, v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-6] = v404;
    goto v130;

v114:
    v99 = stack[-4];
    v404 = elt(env, 4); /* scalar */
    v404 = (v99 == v404 ? lisp_true : nil);
    goto v346;

v231:
    v404 = stack[-5];
    v404 = (Lisp_Object)zerop(v404);
    v404 = v404 ? lisp_true : nil;
    env = stack[-7];
    if (v404 == nil) goto v239;
    v99 = qvalue(elt(env, 3)); /* nil */
    v404 = (Lisp_Object)17; /* 1 */
    v404 = cons(v99, v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    goto v142;

v142:
    stack[-6] = v404;
    goto v130;

v239:
    v404 = stack[-5];
    v404 = Lonep(nil, v404);
    env = stack[-7];
    if (v404 == nil) goto v121;
    v404 = stack[-6];
    fn = elt(env, 10); /* physop2sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    goto v142;

v121:
    v404 = stack[-5];
    fn = elt(env, 10); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v404 = stack[-6];
    fn = elt(env, 10); /* physop2sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 11); /* multsq */
    v404 = (*qfn2(fn))(qenv(fn), stack[0], v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    goto v142;

v16:
    v404 = stack[-3];
    if (v404 == nil) goto v69;
    v404 = stack[-6];
    v404 = (Lisp_Object)zerop(v404);
    v404 = v404 ? lisp_true : nil;
    env = stack[-7];
    if (v404 == nil) goto v283;
    v99 = qvalue(elt(env, 3)); /* nil */
    v404 = (Lisp_Object)17; /* 1 */
    v404 = cons(v99, v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-6] = v404;
    goto v130;

v283:
    v404 = stack[-6];
    v404 = Lonep(nil, v404);
    env = stack[-7];
    if (v404 == nil) goto v221;
    v404 = stack[-5];
    fn = elt(env, 10); /* physop2sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-6] = v404;
    goto v130;

v221:
    v404 = stack[-6];
    fn = elt(env, 10); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v404 = stack[-5];
    fn = elt(env, 10); /* physop2sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 11); /* multsq */
    v404 = (*qfn2(fn))(qenv(fn), stack[0], v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-6] = v404;
    goto v130;

v69:
    v404 = stack[-6];
    fn = elt(env, 10); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    v404 = stack[-5];
    fn = elt(env, 10); /* physop2sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 11); /* multsq */
    v404 = (*qfn2(fn))(qenv(fn), stack[0], v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    fn = elt(env, 12); /* mk!*sq */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-6] = v404;
    goto v130;

v132:
    v404 = qvalue(elt(env, 2)); /* mul!* */
    if (v404 == nil) goto v210;
    v99 = qvalue(elt(env, 1)); /* tstack!* */
    v404 = (Lisp_Object)17; /* 1 */
    v404 = (Lisp_Object)greaterp2(v99, v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    v404 = v404 ? lisp_true : nil;
    env = stack[-7];
    goto v155;

v155:
    if (v404 == nil) goto v105;
    v404 = qvalue(elt(env, 1)); /* tstack!* */
    v404 = sub1(v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    qvalue(elt(env, 1)) = v404; /* tstack!* */
    v99 = qvalue(elt(env, 1)); /* tstack!* */
    v404 = (Lisp_Object)1; /* 0 */
    if (!(v99 == v404)) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v404 = stack[-2];
    qvalue(elt(env, 2)) = v404; /* mul!* */
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v105:
    v404 = qvalue(elt(env, 2)); /* mul!* */
    v99 = qcar(v404);
    v404 = stack[-6];
    v404 = Lapply1(nil, v99, v404);
    nil = C_nil;
    if (exception_pending()) goto v405;
    env = stack[-7];
    stack[-6] = v404;
    v404 = qvalue(elt(env, 2)); /* mul!* */
    v404 = qcdr(v404);
    qvalue(elt(env, 2)) = v404; /* mul!* */
    goto v132;

v210:
    v404 = qvalue(elt(env, 5)); /* t */
    goto v155;

v35:
    v404 = qvalue(elt(env, 2)); /* mul!* */
    goto v27;
/* error exit handlers */
v405:
    popv(8);
    return nil;
}



/* Code for consrecip */

static Lisp_Object CC_consrecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v26, v73;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for consrecip");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v73 = v0;
/* end of prologue */
    v58 = v73;
    v26 = qcar(v58);
    v58 = (Lisp_Object)17; /* 1 */
    if (v26 == v58) goto v169;
    v58 = v73;
    v26 = qcar(v58);
    v58 = (Lisp_Object)-15; /* -1 */
    v58 = (v26 == v58 ? lisp_true : nil);
    goto v41;

v41:
    if (v58 == nil) goto v65;
    v58 = v73;
    v58 = qcar(v58);
    return onevalue(v58);

v65:
    v58 = elt(env, 2); /* recip */
    v26 = v73;
    return cons(v58, v26);

v169:
    v58 = qvalue(elt(env, 1)); /* t */
    goto v41;
}



/* Code for baglistp */

static Lisp_Object CC_baglistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v65, v9;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for baglistp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    v20 = v9;
    if (!consp(v20)) goto v36;
    v20 = v9;
    v65 = qcar(v20);
    v20 = elt(env, 1); /* list */
    if (v65 == v20) goto v15;
    v20 = v9;
    v20 = qcar(v20);
    v65 = elt(env, 3); /* bag */
        return Lflagp(nil, v20, v65);

v15:
    v20 = qvalue(elt(env, 2)); /* t */
    return onevalue(v20);

v36:
    v20 = qvalue(elt(env, 4)); /* nil */
    return onevalue(v20);
}



/* Code for make!-modular!-symmetric */

static Lisp_Object CC_makeKmodularKsymmetric(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v37;
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
    v54 = stack[-1];
    if (v54 == nil) goto v6;
    v54 = stack[-1];
    if (!consp(v54)) goto v137;
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = (consp(v54) ? nil : lisp_true);
    goto v39;

v39:
    if (v54 == nil) goto v14;
    v37 = stack[-1];
    v54 = qvalue(elt(env, 3)); /* modulus!/2 */
    v54 = (Lisp_Object)greaterp2(v37, v54);
    nil = C_nil;
    if (exception_pending()) goto v127;
    v54 = v54 ? lisp_true : nil;
    env = stack[-3];
    if (v54 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v37 = stack[-1];
    v54 = qvalue(elt(env, 4)); /* current!-modulus */
    v54 = difference2(v37, v54);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    v37 = v54;
    v54 = v37;
    v54 = (Lisp_Object)zerop(v54);
    v54 = v54 ? lisp_true : nil;
    env = stack[-3];
    if (v54 == nil) { popv(4); return onevalue(v37); }
    v54 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v54); }

v14:
    v54 = stack[-1];
    v54 = qcar(v54);
    stack[-2] = qcar(v54);
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcdr(v54);
    stack[0] = CC_makeKmodularKsymmetric(env, v54);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    v54 = stack[-1];
    v54 = qcdr(v54);
    v54 = CC_makeKmodularKsymmetric(env, v54);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    {
        Lisp_Object v140 = stack[-2];
        Lisp_Object v283 = stack[0];
        popv(4);
        fn = elt(env, 5); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v140, v283, v54);
    }

v137:
    v54 = qvalue(elt(env, 2)); /* t */
    goto v39;

v6:
    v54 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v54); }
/* error exit handlers */
v127:
    popv(4);
    return nil;
}



/* Code for cl_rename!-vars */

static Lisp_Object CC_cl_renameKvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137;
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
    v137 = v0;
/* end of prologue */
    stack[0] = v137;
    fn = elt(env, 1); /* cl_replace!-varl */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-1];
    fn = elt(env, 2); /* cl_rename!-vars1 */
    v137 = (*qfn2(fn))(qenv(fn), stack[0], v137);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v137 = qcar(v137);
    { popv(2); return onevalue(v137); }
/* error exit handlers */
v66:
    popv(2);
    return nil;
}



setup_type const u31_setup[] =
{
    {"reduce",                  too_few_2,      CC_reduce,     wrong_no_2},
    {"fs:make-nullangle",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTmakeKnullangle},
    {"red=hide",                CC_redMhide,    too_many_1,    wrong_no_1},
    {"taylorp",                 CC_taylorp,     too_many_1,    wrong_no_1},
    {"ofsf_at2ir",              too_few_2,      CC_ofsf_at2ir, wrong_no_2},
    {"createsinglevariablemonom",CC_createsinglevariablemonom,too_many_1,wrong_no_1},
    {"gigcdsq",                 too_few_2,      CC_gigcdsq,    wrong_no_2},
    {"pasf_dt",                 CC_pasf_dt,     too_many_1,    wrong_no_1},
    {"rl_surep",                too_few_2,      CC_rl_surep,   wrong_no_2},
    {"setrd",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_setrd},
    {"ps:zerop:",               CC_psTzeropT,   too_many_1,    wrong_no_1},
    {"maxl",                    CC_maxl,        too_many_1,    wrong_no_1},
    {"assgnpri",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_assgnpri},
    {"decimal2internal",        too_few_2,      CC_decimal2internal,wrong_no_2},
    {"indexvp",                 CC_indexvp,     too_many_1,    wrong_no_1},
    {"*f2di",                   too_few_2,      CC_Hf2di,      wrong_no_2},
    {"nodum_varp",              CC_nodum_varp,  too_many_1,    wrong_no_1},
    {"balance_mod",             too_few_2,      CC_balance_mod,wrong_no_2},
    {"use-berlekamp",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_useKberlekamp},
    {"rl_smrmknowl",            too_few_2,      CC_rl_smrmknowl,wrong_no_2},
    {"give*position",           too_few_2,      CC_giveHposition,wrong_no_2},
    {"pasf_smordtable",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smordtable},
    {"dvfsf_simplat1",          too_few_2,      CC_dvfsf_simplat1,wrong_no_2},
    {"minusrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_minusrd},
    {"freeof",                  too_few_2,      CC_freeof,     wrong_no_2},
    {"matsm1",                  CC_matsm1,      too_many_1,    wrong_no_1},
    {"newsym1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_newsym1},
    {"den",                     CC_den,         too_many_1,    wrong_no_1},
    {"matsm",                   CC_matsm,       too_many_1,    wrong_no_1},
    {"simpsetdiff",             CC_simpsetdiff, too_many_1,    wrong_no_1},
    {"natnump",                 CC_natnump,     too_many_1,    wrong_no_1},
    {"mkforttab",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkforttab},
    {"ev-poles",                too_few_2,      CC_evKpoles,   wrong_no_2},
    {"extract_vars",            CC_extract_vars,too_many_1,    wrong_no_1},
    {"f2df",                    CC_f2df,        too_many_1,    wrong_no_1},
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
    {NULL, (one_args *)"u31", (two_args *)"8687 6823433 524310", 0}
};

/* end of generated code */
