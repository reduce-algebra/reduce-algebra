
/* $destdir\u50.c        Machine generated C code */

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


/* Code for liendimcom */

static Lisp_Object CC_liendimcom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v270, v271, v272, v273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for liendimcom");
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
    v270 = (Lisp_Object)1; /* 0 */
    stack[-9] = v270;
    stack[0] = elt(env, 1); /* lie_dim */
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* aeval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    stack[-3] = v270;
    goto v275;

v275:
    stack[0] = elt(env, 2); /* difference */
    v272 = elt(env, 2); /* difference */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-3];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v276;
    v270 = elt(env, 1); /* lie_dim */
    fn = elt(env, 15); /* aeval */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v277;
    v270 = (Lisp_Object)17; /* 1 */
    stack[-5] = v270;
    goto v278;

v278:
    stack[0] = elt(env, 2); /* difference */
    v272 = elt(env, 2); /* difference */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-5];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v279;
    v270 = elt(env, 1); /* lie_dim */
    fn = elt(env, 15); /* aeval */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 20); /* evalequal */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v277;
    stack[0] = elt(env, 10); /* lie_help */
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* aeval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    stack[-6] = v270;
    goto v280;

v280:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-6];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v281;
    v270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v270;
    goto v282;

v282:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v283;
    v270 = elt(env, 10); /* lie_help */
    fn = elt(env, 15); /* aeval */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* evalequal */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v284;
    v272 = elt(env, 12); /* lientrans */
    v271 = (Lisp_Object)33; /* 2 */
    v270 = elt(env, 5); /* lie_p */
    stack[-1] = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v272 = elt(env, 12); /* lientrans */
    v271 = (Lisp_Object)49; /* 3 */
    v270 = elt(env, 6); /* lie_q */
    stack[0] = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* aeval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[-1], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[0] = elt(env, 13); /* lie_kk!* */
    v270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* aeval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v270;
    goto v285;

v285:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (!(v270 == nil)) goto v277;
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-1];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v286;
    stack[0] = stack[-1];
    v270 = elt(env, 5); /* lie_p */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v286;
    stack[0] = stack[-1];
    v270 = elt(env, 6); /* lie_q */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v286;
    stack[0] = elt(env, 14); /* lie_tt */
    v270 = stack[-1];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v286;

v286:
    v270 = stack[-1];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v285;

v277:
    v270 = nil;
    { popv(11); return onevalue(v270); }

v284:
    v272 = elt(env, 12); /* lientrans */
    v271 = (Lisp_Object)33; /* 2 */
    v270 = elt(env, 11); /* lie_s */
    stack[-7] = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-6] = elt(env, 8); /* quotient */
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-9];
    stack[-5] = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    stack[-4] = v270;
    v270 = (Lisp_Object)1; /* 0 */
    stack[-3] = v270;
    goto v287;

v287:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-4];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v288;
    v270 = stack[-3];
    v270 = list3(stack[-6], stack[-5], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 15); /* aeval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[-7], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v270;
    goto v289;

v289:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (!(v270 == nil)) goto v277;
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-1];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v290;
    stack[0] = stack[-1];
    v270 = elt(env, 11); /* lie_s */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v290;
    stack[0] = elt(env, 14); /* lie_tt */
    v270 = stack[-1];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v290;

v290:
    v270 = stack[-1];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v289;

v288:
    stack[-2] = elt(env, 7); /* plus */
    stack[-1] = elt(env, 9); /* times */
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-4];
    stack[0] = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v273 = elt(env, 4); /* lie_cc */
    v272 = stack[-4];
    v271 = elt(env, 11); /* lie_s */
    v270 = stack[-9];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = list3(stack[-1], stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-3];
    v270 = list3(stack[-2], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    v270 = stack[-4];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-4] = v270;
    goto v287;

v283:
    v272 = elt(env, 12); /* lientrans */
    v271 = (Lisp_Object)17; /* 1 */
    v270 = stack[-1];
    stack[0] = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-1];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v282;

v281:
    v270 = (Lisp_Object)17; /* 1 */
    stack[-5] = v270;
    goto v291;

v291:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-5];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v292;
    v270 = stack[-6];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-6] = v270;
    goto v280;

v292:
    v270 = (Lisp_Object)17; /* 1 */
    stack[-4] = v270;
    v270 = (Lisp_Object)1; /* 0 */
    stack[-3] = v270;
    goto v293;

v293:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-4];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v294;
    v270 = stack[-3];
    v271 = v270;
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v295;
    stack[0] = elt(env, 10); /* lie_help */
    v270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[0] = elt(env, 11); /* lie_s */
    v270 = stack[-6];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-5];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-9] = v270;
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-5] = v270;
    stack[-6] = v270;
    goto v295;

v295:
    v270 = stack[-5];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-5] = v270;
    goto v291;

v294:
    stack[-2] = elt(env, 7); /* plus */
    stack[-1] = elt(env, 9); /* times */
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-4];
    stack[0] = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v273 = elt(env, 4); /* lie_cc */
    v272 = stack[-4];
    v271 = stack[-6];
    v270 = stack[-5];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = list3(stack[-1], stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-3];
    v270 = list3(stack[-2], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    v270 = stack[-4];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-4] = v270;
    goto v293;

v279:
    v270 = (Lisp_Object)17; /* 1 */
    stack[-4] = v270;
    goto v296;

v296:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-4];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v297;
    v270 = stack[-5];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-5] = v270;
    goto v278;

v297:
    stack[-1] = elt(env, 8); /* quotient */
    v273 = elt(env, 4); /* lie_cc */
    v272 = stack[-5];
    v271 = stack[-4];
    v270 = stack[-9];
    stack[0] = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-9];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = list3(stack[-1], stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-6] = v270;
    v270 = (Lisp_Object)17; /* 1 */
    stack[-3] = v270;
    goto v298;

v298:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-3];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v299;
    v270 = stack[-4];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-4] = v270;
    goto v296;

v299:
    v273 = elt(env, 4); /* lie_cc */
    v272 = stack[-5];
    v271 = stack[-4];
    v270 = stack[-3];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    stack[-2] = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = elt(env, 9); /* times */
    stack[0] = stack[-6];
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-3];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = list3(stack[-1], stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), stack[-2], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v300;
    stack[0] = elt(env, 1); /* lie_dim */
    v270 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-5] = v270;
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-4] = v270;
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    goto v300;

v300:
    v270 = stack[-3];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    goto v298;

v276:
    v270 = stack[-3];
    stack[-2] = v270;
    goto v301;

v301:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-2];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v302;
    v270 = stack[-3];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    goto v275;

v302:
    v270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v270;
    goto v303;

v303:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v304;
    v270 = stack[-2];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-2] = v270;
    goto v301;

v304:
    v273 = elt(env, 4); /* lie_cc */
    v272 = stack[-3];
    v271 = stack[-2];
    v270 = stack[-1];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v305;
    stack[0] = elt(env, 1); /* lie_dim */
    v270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[0] = elt(env, 5); /* lie_p */
    v270 = stack[-3];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[0] = elt(env, 6); /* lie_q */
    v270 = stack[-2];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-9] = v270;
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    stack[-2] = v270;
    goto v305;

v305:
    v270 = stack[-1];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v303;
/* error exit handlers */
v274:
    popv(11);
    return nil;
}



/* Code for sc_create */

static Lisp_Object CC_sc_create(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v263, v311;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sc_create");
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
    v263 = stack[-1];
    stack[0] = v263;
    goto v312;

v312:
    v263 = stack[0];
    v263 = sub1(v263);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-3];
    v263 = Lminusp(nil, v263);
    env = stack[-3];
    if (v263 == nil) goto v314;
    v311 = stack[-2];
    v263 = elt(env, 2); /* symbolic */
    fn = elt(env, 3); /* list2vect!* */
    stack[0] = (*qfn2(fn))(qenv(fn), v311, v263);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-3];
    v263 = stack[-1];
    v263 = sub1(v263);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-3];
    v263 = Lmkvect(nil, v263);
    nil = C_nil;
    if (exception_pending()) goto v313;
    {
        Lisp_Object v315 = stack[0];
        popv(4);
        return cons(v315, v263);
    }

v314:
    v311 = stack[0];
    v263 = stack[-2];
    v263 = cons(v311, v263);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-3];
    stack[-2] = v263;
    v263 = stack[0];
    v263 = sub1(v263);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-3];
    stack[0] = v263;
    goto v312;
/* error exit handlers */
v313:
    popv(4);
    return nil;
}



/* Code for modroots1 */

static Lisp_Object CC_modroots1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v358, v359, v360;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modroots1");
#endif
    if (stack >= stacklimit)
    {
        push2(v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v316);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v316;
    stack[-10] = v0;
/* end of prologue */
    v358 = stack[-1];
    v358 = qcdr(v358);
    if (v358 == nil) goto v312;
    stack[-7] = nil;
    v358 = stack[-1];
    v358 = qcar(v358);
    stack[-11] = v358;
    v358 = stack[-1];
    v358 = qcdr(v358);
    stack[-1] = v358;
    v359 = stack[-10];
    v358 = stack[-1];
    v358 = CC_modroots1(env, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    stack[0] = v358;
    v358 = stack[0];
    if (v358 == nil) goto v263;
    v358 = stack[-10];
    v358 = qcar(v358);
    v358 = qcar(v358);
    v358 = qcar(v358);
    stack[-6] = v358;
    v358 = elt(env, 2); /* g */
    v358 = Lgensym1(nil, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    stack[-5] = v358;
    v358 = stack[-1];
    stack[-1] = v358;
    v358 = (Lisp_Object)17; /* 1 */
    v359 = v358;
    goto v362;

v362:
    v358 = stack[-1];
    if (v358 == nil) goto v363;
    v358 = stack[-1];
    v358 = qcar(v358);
    v358 = times2(v358, v359);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    v359 = v358;
    v358 = stack[-1];
    v358 = qcdr(v358);
    stack[-1] = v358;
    goto v362;

v363:
    v358 = v359;
    stack[-9] = v358;
    v359 = stack[-11];
    v358 = stack[-9];
    v358 = times2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    stack[-8] = v358;
    v358 = stack[0];
    stack[-4] = v358;
    goto v364;

v364:
    v358 = stack[-4];
    if (v358 == nil) { Lisp_Object res = stack[-7]; popv(13); return onevalue(res); }
    v358 = stack[-4];
    v358 = qcar(v358);
    stack[-3] = v358;
    stack[-2] = stack[-10];
    stack[-1] = stack[-6];
    stack[0] = elt(env, 3); /* plus */
    v360 = elt(env, 4); /* times */
    v359 = stack[-5];
    v358 = stack[-9];
    v359 = list3(v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    v358 = stack[-3];
    v358 = list2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    v358 = list2star(stack[-1], stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    fn = elt(env, 6); /* subf */
    v358 = (*qfn2(fn))(qenv(fn), stack[-2], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    v358 = qcar(v358);
    v359 = v358;
    v358 = stack[-11];
    fn = elt(env, 7); /* reduce!-mod!-p!* */
    v360 = (*qfn2(fn))(qenv(fn), v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    v359 = stack[-11];
    v358 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 8); /* modroots2 */
    v358 = (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    stack[-2] = v358;
    goto v244;

v244:
    v358 = stack[-2];
    if (v358 == nil) goto v365;
    v358 = stack[-2];
    v358 = qcar(v358);
    stack[-1] = v358;
    v359 = stack[-1];
    v358 = stack[-9];
    v359 = times2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    v358 = stack[-3];
    v359 = plus2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    v358 = stack[-8];
    fn = elt(env, 9); /* modp */
    v358 = (*qfn2(fn))(qenv(fn), v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    stack[-1] = v358;
    stack[0] = stack[-10];
    v359 = stack[-6];
    v358 = stack[-1];
    v358 = cons(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    fn = elt(env, 6); /* subf */
    v358 = (*qfn2(fn))(qenv(fn), stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    v359 = qcar(v358);
    v358 = stack[-8];
    fn = elt(env, 7); /* reduce!-mod!-p!* */
    v358 = (*qfn2(fn))(qenv(fn), v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    if (v358 == nil) goto v366;
    v358 = qvalue(elt(env, 1)); /* nil */
    goto v367;

v367:
    if (v358 == nil) goto v368;
    v359 = stack[-1];
    v358 = stack[-7];
    v358 = cons(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-12];
    stack[-7] = v358;
    goto v368;

v368:
    v358 = stack[-2];
    v358 = qcdr(v358);
    stack[-2] = v358;
    goto v244;

v366:
    v359 = stack[-1];
    v358 = stack[-7];
    v358 = Lmember(nil, v359, v358);
    v358 = (v358 == nil ? lisp_true : nil);
    goto v367;

v365:
    v358 = stack[-4];
    v358 = qcdr(v358);
    stack[-4] = v358;
    goto v364;

v263:
    v358 = qvalue(elt(env, 1)); /* nil */
    { popv(13); return onevalue(v358); }

v312:
    v360 = stack[-10];
    v358 = stack[-1];
    v359 = qcar(v358);
    v358 = qvalue(elt(env, 1)); /* nil */
    {
        popv(13);
        fn = elt(env, 8); /* modroots2 */
        return (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    }
/* error exit handlers */
v361:
    popv(13);
    return nil;
}



/* Code for quotfail!-mod!-p */

static Lisp_Object CC_quotfailKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v333, v309, v275;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v316);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v309 = v316;
    v275 = v0;
/* end of prologue */
    v333 = qvalue(elt(env, 1)); /* t */
    qvalue(elt(env, 2)) = v333; /* exact!-quotient!-flag */
    v333 = v275;
    fn = elt(env, 4); /* quotient!-mod!-p */
    v333 = (*qfn2(fn))(qenv(fn), v333, v309);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[0];
    v309 = v333;
    v333 = qvalue(elt(env, 2)); /* exact!-quotient!-flag */
    if (!(v333 == nil)) { popv(1); return onevalue(v309); }
    v333 = elt(env, 3); /* "QUOTIENT NOT EXACT (MOD P)" */
    fn = elt(env, 5); /* errorf */
    v333 = (*qfn1(fn))(qenv(fn), v333);
    nil = C_nil;
    if (exception_pending()) goto v319;
    v333 = nil;
    { popv(1); return onevalue(v333); }
/* error exit handlers */
v319:
    popv(1);
    return nil;
}



/* Code for setqdeletedescendants */

static Lisp_Object CC_setqdeletedescendants(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v362, v374;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setqdeletedescendants");
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
    v362 = qvalue(elt(env, 1)); /* fluidbibasissetq */
    stack[-1] = v362;
    goto v375;

v375:
    v362 = stack[-1];
    v362 = qcar(v362);
    if (v362 == nil) goto v310;
    v362 = stack[-1];
    v374 = qcar(v362);
    v362 = (Lisp_Object)33; /* 2 */
    v374 = *(Lisp_Object *)((char *)v374 + (CELL-TAG_VECTOR) + ((int32_t)v362/(16/CELL)));
    v362 = stack[0];
    if (equal(v374, v362)) goto v307;
    v362 = stack[-1];
    v362 = qcdr(v362);
    stack[-1] = v362;
    goto v375;

v307:
    v374 = stack[-1];
    v362 = stack[-1];
    v362 = qcdr(v362);
    v362 = qcar(v362);
    v374 = Lrplaca(nil, v374, v362);
    nil = C_nil;
    if (exception_pending()) goto v376;
    env = stack[-2];
    v362 = stack[-1];
    v362 = qcdr(v362);
    v362 = qcdr(v362);
    v362 = Lrplacd(nil, v374, v362);
    nil = C_nil;
    if (exception_pending()) goto v376;
    env = stack[-2];
    goto v375;

v310:
    v362 = nil;
    { popv(3); return onevalue(v362); }
/* error exit handlers */
v376:
    popv(3);
    return nil;
}



/* Code for rl_ex */

static Lisp_Object CC_rl_ex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v378, v356;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_ex");
#endif
    if (stack >= stacklimit)
    {
        push2(v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v316);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v378 = v316;
    v356 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_ex!* */
    v378 = list2(v356, v378);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-1];
    {
        Lisp_Object v276 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v276, v378);
    }
/* error exit handlers */
v314:
    popv(2);
    return nil;
}



/* Code for ofsf_smdbgetrel */

static Lisp_Object CC_ofsf_smdbgetrel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v371, v264, v262, v306;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smdbgetrel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v262 = v316;
    v306 = v0;
/* end of prologue */

v312:
    v264 = v306;
    v371 = v262;
    v371 = qcar(v371);
    v371 = qcdr(v371);
    v371 = qcdr(v371);
    if (equal(v264, v371)) goto v375;
    v371 = v262;
    v371 = qcdr(v371);
    if (v371 == nil) goto v348;
    v371 = v262;
    v371 = qcdr(v371);
    v262 = v371;
    goto v312;

v348:
    v371 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v371);

v375:
    v371 = v262;
    v371 = qcar(v371);
    v371 = qcdr(v371);
    v371 = qcar(v371);
    return onevalue(v371);
}



/* Code for addcoeffs */

static Lisp_Object MS_CDECL CC_addcoeffs(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v316,
                         Lisp_Object v43, Lisp_Object v196, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v389, v248, v249, v344;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "addcoeffs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addcoeffs");
#endif
    if (stack >= stacklimit)
    {
        push4(v196,v43,v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v316,v43,v196);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v196;
    stack[-2] = v43;
    stack[-3] = v316;
    stack[-4] = v0;
/* end of prologue */
    v248 = qvalue(elt(env, 1)); /* nil */
    v389 = (Lisp_Object)17; /* 1 */
    v389 = cons(v248, v389);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    stack[0] = v389;
    v389 = stack[-4];
    fn = elt(env, 2); /* smallest!-increment */
    stack[-5] = (*qfn1(fn))(qenv(fn), v389);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    v389 = stack[-3];
    fn = elt(env, 2); /* smallest!-increment */
    v389 = (*qfn1(fn))(qenv(fn), v389);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    fn = elt(env, 3); /* common!-increment */
    v389 = (*qfn2(fn))(qenv(fn), stack[-5], v389);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    v344 = stack[-2];
    v249 = stack[-1];
    v248 = stack[-3];
    v248 = qcar(v248);
    v248 = qcar(v248);
    fn = elt(env, 4); /* makecoeffpairs */
    v389 = (*qfnn(fn))(qenv(fn), 4, v344, v249, v248, v389);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    stack[-5] = v389;
    goto v348;

v348:
    v389 = stack[-5];
    if (v389 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v389 = stack[-5];
    v389 = qcar(v389);
    stack[-2] = v389;
    stack[-1] = stack[0];
    v389 = stack[-2];
    v248 = qcar(v389);
    v389 = stack[-4];
    v389 = Lassoc(nil, v248, v389);
    v248 = v389;
    v389 = v248;
    if (v389 == nil) goto v390;
    v389 = v248;
    v389 = qcdr(v389);
    stack[0] = v389;
    goto v305;

v305:
    v389 = stack[-2];
    v248 = qcdr(v389);
    v389 = stack[-3];
    v389 = Lassoc(nil, v248, v389);
    v248 = v389;
    v389 = v248;
    if (v389 == nil) goto v340;
    v389 = v248;
    v389 = qcdr(v389);
    goto v261;

v261:
    fn = elt(env, 5); /* multsq */
    v389 = (*qfn2(fn))(qenv(fn), stack[0], v389);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    fn = elt(env, 6); /* addsq */
    v389 = (*qfn2(fn))(qenv(fn), stack[-1], v389);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    stack[0] = v389;
    v389 = stack[-5];
    v389 = qcdr(v389);
    stack[-5] = v389;
    goto v348;

v340:
    v248 = qvalue(elt(env, 1)); /* nil */
    v389 = (Lisp_Object)17; /* 1 */
    v389 = cons(v248, v389);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    goto v261;

v390:
    v248 = qvalue(elt(env, 1)); /* nil */
    v389 = (Lisp_Object)17; /* 1 */
    v389 = cons(v248, v389);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    stack[0] = v389;
    goto v305;
/* error exit handlers */
v246:
    popv(7);
    return nil;
}



/* Code for mk_resimp_rep */

static Lisp_Object CC_mk_resimp_rep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v349, v258;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_resimp_rep");
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
    v349 = stack[-5];
    fn = elt(env, 2); /* get_group_in */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-7];
    stack[-6] = v349;
    v349 = stack[-6];
    fn = elt(env, 3); /* get!*elements */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-7];
    stack[-4] = v349;
    v349 = stack[-4];
    if (v349 == nil) goto v356;
    v349 = stack[-4];
    v349 = qcar(v349);
    stack[0] = v349;
    v258 = v349;
    v349 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v349 = (*qfn2(fn))(qenv(fn), v258, v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+resimp!+mat */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-7];
    v349 = list2(stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-7];
    v349 = ncons(v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-7];
    stack[-2] = v349;
    stack[-3] = v349;
    goto v269;

v269:
    v349 = stack[-4];
    v349 = qcdr(v349);
    stack[-4] = v349;
    v349 = stack[-4];
    if (v349 == nil) goto v263;
    stack[-1] = stack[-2];
    v349 = stack[-4];
    v349 = qcar(v349);
    stack[0] = v349;
    v258 = v349;
    v349 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v349 = (*qfn2(fn))(qenv(fn), v258, v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+resimp!+mat */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-7];
    v349 = list2(stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-7];
    v349 = ncons(v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-7];
    v349 = Lrplacd(nil, stack[-1], v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-7];
    v349 = stack[-2];
    v349 = qcdr(v349);
    stack[-2] = v349;
    goto v269;

v263:
    v349 = stack[-3];
    goto v268;

v268:
    stack[0] = v349;
    v349 = stack[-6];
    v258 = ncons(v349);
    nil = C_nil;
    if (exception_pending()) goto v398;
    v349 = stack[0];
        popv(8);
        return Lappend(nil, v258, v349);

v356:
    v349 = qvalue(elt(env, 1)); /* nil */
    goto v268;
/* error exit handlers */
v398:
    popv(8);
    return nil;
}



/* Code for subst!-cn */

static Lisp_Object MS_CDECL CC_substKcn(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v316,
                         Lisp_Object v43, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v403, v391;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subst-cn");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subst-cn");
#endif
    if (stack >= stacklimit)
    {
        push3(v43,v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v316,v43);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v43;
    stack[-1] = v316;
    stack[-2] = v0;
/* end of prologue */
    v403 = stack[-1];
    v403 = ncons(v403);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    fn = elt(env, 3); /* setkorder */
    v403 = (*qfn1(fn))(qenv(fn), v403);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    stack[-3] = v403;
    v403 = stack[-2];
    fn = elt(env, 4); /* reorder */
    v403 = (*qfn1(fn))(qenv(fn), v403);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    stack[-2] = v403;
    v403 = stack[-2];
    if (!consp(v403)) goto v276;
    v403 = stack[-2];
    v403 = qcar(v403);
    v403 = (consp(v403) ? nil : lisp_true);
    goto v314;

v314:
    if (v403 == nil) goto v372;
    v403 = qvalue(elt(env, 2)); /* nil */
    goto v355;

v355:
    if (v403 == nil) goto v268;
    v403 = stack[0];
    if (v403 == nil) goto v351;
    v403 = stack[-2];
    v403 = qcar(v403);
    stack[-1] = qcdr(v403);
    v403 = stack[0];
    v403 = qcar(v403);
    fn = elt(env, 4); /* reorder */
    v403 = (*qfn1(fn))(qenv(fn), v403);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    fn = elt(env, 5); /* multf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v403);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    v403 = stack[-2];
    stack[-2] = qcdr(v403);
    v403 = stack[0];
    v403 = qcdr(v403);
    fn = elt(env, 4); /* reorder */
    v403 = (*qfn1(fn))(qenv(fn), v403);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    fn = elt(env, 5); /* multf */
    v403 = (*qfn2(fn))(qenv(fn), stack[-2], v403);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    fn = elt(env, 6); /* addf */
    v403 = (*qfn2(fn))(qenv(fn), stack[-1], v403);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    stack[-2] = v403;
    goto v268;

v268:
    v403 = stack[-3];
    fn = elt(env, 3); /* setkorder */
    v403 = (*qfn1(fn))(qenv(fn), v403);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    v403 = stack[-2];
    {
        popv(5);
        fn = elt(env, 4); /* reorder */
        return (*qfn1(fn))(qenv(fn), v403);
    }

v351:
    v403 = stack[-2];
    v403 = qcdr(v403);
    stack[-2] = v403;
    goto v268;

v372:
    v403 = stack[-2];
    v403 = qcar(v403);
    v403 = qcar(v403);
    v391 = qcar(v403);
    v403 = stack[-1];
    v403 = (v391 == v403 ? lisp_true : nil);
    goto v355;

v276:
    v403 = qvalue(elt(env, 1)); /* t */
    goto v314;
/* error exit handlers */
v257:
    popv(5);
    return nil;
}



/* Code for qqe_qadd!-inside!-at */

static Lisp_Object CC_qqe_qaddKinsideKat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v275;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qadd-inside-at");
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
    v275 = v0;
/* end of prologue */
    fn = elt(env, 3); /* rl_prepat */
    v275 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-2];
    stack[0] = v275;
    v275 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v275 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-2];
    stack[-1] = v275;
    v275 = stack[0];
    fn = elt(env, 5); /* qqe_arg2r */
    v275 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-2];
    stack[0] = v275;
    v275 = stack[-1];
    fn = elt(env, 6); /* qqe_qadd!-inside */
    v275 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-2];
    if (!(v275 == nil)) goto v379;
    v275 = stack[0];
    fn = elt(env, 6); /* qqe_qadd!-inside */
    v275 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-2];
    if (!(v275 == nil)) goto v379;
    v275 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v275); }

v379:
    v275 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v275); }
/* error exit handlers */
v348:
    popv(3);
    return nil;
}



/* Code for ratpoly_pp */

static Lisp_Object CC_ratpoly_pp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v268, v269;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_pp");
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
    v268 = stack[0];
    v268 = qcar(v268);
    fn = elt(env, 1); /* sfto_dprpartksf */
    v269 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v230;
    v268 = stack[0];
    v268 = qcdr(v268);
    popv(1);
    return cons(v269, v268);
/* error exit handlers */
v230:
    popv(1);
    return nil;
}



/* Code for ps!:find!-order1 */

static Lisp_Object CC_psTfindKorder1(Lisp_Object env,
                         Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v414, v238, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:find-order1");
#endif
    if (stack >= stacklimit)
    {
        push(v316);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v316);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v414 = v316;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v414; /* ps */
    v414 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 10); /* ps!:order */
    v414 = (*qfn1(fn))(qenv(fn), v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    stack[-2] = v414;
    v414 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 11); /* ps!:last!-term */
    v414 = (*qfn1(fn))(qenv(fn), v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    v238 = stack[-2];
    v414 = (Lisp_Object)lesseq2(v238, v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    v414 = v414 ? lisp_true : nil;
    env = stack[-4];
    if (v414 == nil) goto v348;
    v414 = stack[-2];
    goto v387;

v387:
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v414); }

v348:
    v238 = qvalue(elt(env, 1)); /* ps */
    v414 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 12); /* ps!:getv */
    v414 = (*qfn2(fn))(qenv(fn), v238, v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    v414 = qcar(v414);
    v238 = v414;
    v414 = elt(env, 2); /* ps!:order!-fn */
    stack[0] = get(v238, v414);
    env = stack[-4];
    v414 = qvalue(elt(env, 1)); /* ps */
    v414 = ncons(v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    fn = elt(env, 13); /* apply */
    v414 = (*qfn2(fn))(qenv(fn), stack[0], v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    stack[-2] = v414;
    v236 = qvalue(elt(env, 1)); /* ps */
    v238 = (Lisp_Object)1; /* 0 */
    v414 = stack[-2];
    fn = elt(env, 14); /* ps!:putv */
    v414 = (*qfnn(fn))(qenv(fn), 3, v236, v238, v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    stack[-1] = qvalue(elt(env, 1)); /* ps */
    stack[0] = (Lisp_Object)17; /* 1 */
    v414 = stack[-2];
    v414 = sub1(v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    fn = elt(env, 14); /* ps!:putv */
    v414 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    v414 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 15); /* ps!:value */
    v238 = (*qfn1(fn))(qenv(fn), v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    v414 = (Lisp_Object)1; /* 0 */
    if (!(v238 == v414)) goto v254;
    v414 = (Lisp_Object)1; /* 0 */
    stack[-2] = v414;
    v236 = qvalue(elt(env, 1)); /* ps */
    v238 = (Lisp_Object)17; /* 1 */
    v414 = qvalue(elt(env, 3)); /* ps!:max!-order */
    fn = elt(env, 14); /* ps!:putv */
    v414 = (*qfnn(fn))(qenv(fn), 3, v236, v238, v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    goto v384;

v384:
    v414 = stack[-2];
    goto v387;

v254:
    v238 = qvalue(elt(env, 1)); /* ps */
    v414 = stack[-2];
    fn = elt(env, 16); /* ps!:evaluate!-next */
    stack[0] = (*qfn2(fn))(qenv(fn), v238, v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    v238 = qvalue(elt(env, 4)); /* nil */
    v414 = (Lisp_Object)17; /* 1 */
    v414 = cons(v238, v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    if (!(equal(stack[0], v414))) goto v384;
    v414 = stack[-2];
    v414 = add1(v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    stack[-2] = v414;
    v238 = stack[-2];
    v414 = qvalue(elt(env, 5)); /* ps!:order!-limit */
    v414 = (Lisp_Object)greaterp2(v238, v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    v414 = v414 ? lisp_true : nil;
    env = stack[-4];
    if (v414 == nil) goto v254;
    stack[0] = elt(env, 6); /* "Expression " */
    v414 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 15); /* ps!:value */
    v236 = (*qfn1(fn))(qenv(fn), v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    v238 = elt(env, 7); /* " has zero expansion to order " */
    v414 = stack[-2];
    v414 = list4(stack[0], v236, v238, v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    v238 = v414;
    v414 = v238;
    qvalue(elt(env, 8)) = v414; /* errmsg!* */
    v414 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v414 == nil)) goto v416;
    v414 = v238;
    fn = elt(env, 17); /* lprie */
    v414 = (*qfn1(fn))(qenv(fn), v414);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    goto v416;

v416:
    v414 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v415;
    env = stack[-4];
    goto v254;
/* error exit handlers */
v415:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for specrd!:sqrt */

static Lisp_Object CC_specrdTsqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v312, v397;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for specrd:sqrt");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v312 = v0;
/* end of prologue */
    v397 = v312;
    v312 = elt(env, 1); /* 0.5 */
    {
        fn = elt(env, 2); /* specrd!:expt */
        return (*qfn2(fn))(qenv(fn), v397, v312);
    }
}



/* Code for weak_xreduce */

static Lisp_Object CC_weak_xreduce(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v303, v419, v390;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for weak_xreduce");
#endif
    if (stack >= stacklimit)
    {
        push2(v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v316);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v316;
    stack[-1] = v0;
/* end of prologue */
    v303 = qvalue(elt(env, 1)); /* nil */
    v303 = ncons(v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    stack[-2] = v303;
    v303 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v303 == nil) goto v369;
    v303 = stack[-1];
    fn = elt(env, 7); /* preppf */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    v303 = Lmkquote(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    fn = elt(env, 8); /* eval */
    v390 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    v419 = qvalue(elt(env, 1)); /* nil */
    v303 = nil;
    fn = elt(env, 9); /* assgnpri */
    v303 = (*qfnn(fn))(qenv(fn), 3, v390, v419, v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    v303 = elt(env, 3); /* " =" */
    fn = elt(env, 8); /* eval */
    v390 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    v419 = qvalue(elt(env, 1)); /* nil */
    v303 = elt(env, 4); /* last */
    fn = elt(env, 9); /* assgnpri */
    v303 = (*qfnn(fn))(qenv(fn), 3, v390, v419, v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    goto v369;

v369:
    v390 = stack[-1];
    v419 = stack[0];
    v303 = stack[-2];
    fn = elt(env, 10); /* weak_xreduce1 */
    v303 = (*qfnn(fn))(qenv(fn), 3, v390, v419, v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    stack[0] = v303;
    v303 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v303 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v303 = elt(env, 5); /* "   " */
    fn = elt(env, 8); /* eval */
    v390 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    v419 = qvalue(elt(env, 1)); /* nil */
    v303 = elt(env, 6); /* first */
    fn = elt(env, 9); /* assgnpri */
    v303 = (*qfnn(fn))(qenv(fn), 3, v390, v419, v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    v303 = stack[0];
    fn = elt(env, 7); /* preppf */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    v303 = Lmkquote(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    fn = elt(env, 8); /* eval */
    v390 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    env = stack[-3];
    v419 = qvalue(elt(env, 1)); /* nil */
    v303 = elt(env, 4); /* last */
    fn = elt(env, 9); /* assgnpri */
    v303 = (*qfnn(fn))(qenv(fn), 3, v390, v419, v303);
    nil = C_nil;
    if (exception_pending()) goto v349;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v349:
    popv(4);
    return nil;
}



/* Code for !:dm2fix */

static Lisp_Object CC_Tdm2fix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v302;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dm2fix");
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
    v302 = stack[-2];
    v302 = integerp(v302);
    if (!(v302 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v302 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = qvalue(elt(env, 2)); /* !*noequiv */
    qvalue(elt(env, 2)) = v302; /* !*noequiv */
    v302 = stack[-2];
    fn = elt(env, 4); /* int!-equiv!-chk */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-4];
    stack[-2] = v302;
    v302 = integerp(v302);
    if (v302 == nil) goto v230;
    v302 = stack[-2];
    goto v269;

v269:
    qvalue(elt(env, 2)) = stack[-3]; /* !*noequiv */
    { popv(5); return onevalue(v302); }

v230:
    v302 = stack[-2];
    if (v302 == nil) goto v314;
    v302 = stack[-2];
    v302 = qcdr(v302);
    v302 = Lfloatp(nil, v302);
    env = stack[-4];
    if (v302 == nil) goto v313;
    stack[-1] = elt(env, 3); /* 0.0 */
    v302 = stack[-2];
    stack[0] = qcdr(v302);
    v302 = stack[-2];
    v302 = qcdr(v302);
    v302 = Ltruncate(nil, v302);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-4];
    v302 = difference2(stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-4];
    if (!(equal(stack[-1], v302))) goto v313;
    v302 = stack[-2];
    v302 = qcdr(v302);
    v302 = Ltruncate(nil, v302);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-4];
    goto v269;

v313:
    v302 = stack[-2];
    goto v269;

v314:
    v302 = (Lisp_Object)1; /* 0 */
    goto v269;
/* error exit handlers */
v301:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* !*noequiv */
    popv(5);
    return nil;
}



/* Code for delength */

static Lisp_Object CC_delength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v253, v251, v343;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delength");
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
    v251 = v0;
/* end of prologue */
    v253 = v251;
    v253 = Lconsp(nil, v253);
    env = stack[-2];
    if (v253 == nil) goto v393;
    v253 = v251;
    v343 = qcar(v253);
    v253 = elt(env, 1); /* plus */
    if (v343 == v253) goto v314;
    v253 = v251;
    v343 = qcar(v253);
    v253 = elt(env, 3); /* times */
    if (v343 == v253) goto v306;
    v253 = v251;
    v343 = qcar(v253);
    v253 = elt(env, 4); /* quotient */
    if (v343 == v253) goto v413;
    v253 = v251;
    v343 = qcar(v253);
    v253 = elt(env, 5); /* minus */
    if (v343 == v253) goto v363;
    v253 = v251;
    v343 = qcar(v253);
    v253 = elt(env, 6); /* equal */
    v253 = (v343 == v253 ? lisp_true : nil);
    goto v357;

v357:
    if (v253 == nil) goto v254;
    v253 = v251;
    v253 = qcdr(v253);
    stack[-1] = v253;
    v253 = (Lisp_Object)1; /* 0 */
    stack[0] = v253;
    goto v422;

v422:
    v253 = stack[-1];
    if (v253 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v253 = stack[-1];
    v253 = qcar(v253);
    v251 = CC_delength(env, v253);
    nil = C_nil;
    if (exception_pending()) goto v423;
    env = stack[-2];
    v253 = stack[0];
    v253 = plus2(v251, v253);
    nil = C_nil;
    if (exception_pending()) goto v423;
    env = stack[-2];
    stack[0] = v253;
    v253 = stack[-1];
    v253 = qcdr(v253);
    stack[-1] = v253;
    goto v422;

v254:
    v253 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v253); }

v363:
    v253 = qvalue(elt(env, 2)); /* t */
    goto v357;

v413:
    v253 = qvalue(elt(env, 2)); /* t */
    goto v357;

v306:
    v253 = qvalue(elt(env, 2)); /* t */
    goto v357;

v314:
    v253 = qvalue(elt(env, 2)); /* t */
    goto v357;

v393:
    v253 = v251;
    if (v253 == nil) goto v269;
    v253 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v253); }

v269:
    v253 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v253); }
/* error exit handlers */
v423:
    popv(3);
    return nil;
}



/* Code for calc_map_2d */

static Lisp_Object MS_CDECL CC_calc_map_2d(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v316,
                         Lisp_Object v43, Lisp_Object v196, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v370, v413;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "calc_map_2d");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_map_2d");
#endif
    if (stack >= stacklimit)
    {
        push4(v196,v43,v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v316,v43,v196);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v196;
    stack[-2] = v43;
    stack[-3] = v316;
    stack[-4] = v0;
/* end of prologue */
    v370 = stack[-4];
    v370 = qcar(v370);
    v370 = qcar(v370);
    fn = elt(env, 1); /* mk_names_map_2 */
    stack[-5] = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-6];
    v370 = stack[-4];
    v370 = qcar(v370);
    stack[0] = qcdr(v370);
    v370 = stack[-4];
    v370 = qcdr(v370);
    v413 = qcar(v370);
    v370 = stack[-3];
    v370 = cons(v413, v370);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-6];
    stack[0] = list2star(stack[-5], stack[0], v370);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-6];
    v370 = stack[-4];
    v370 = qcdr(v370);
    v370 = qcdr(v370);
    v413 = qcar(v370);
    v370 = stack[-1];
    fn = elt(env, 2); /* mk_binding */
    v370 = (*qfn2(fn))(qenv(fn), v413, v370);
    nil = C_nil;
    if (exception_pending()) goto v353;
    env = stack[-6];
    {
        Lisp_Object v350 = stack[0];
        Lisp_Object v301 = stack[-2];
        popv(7);
        fn = elt(env, 3); /* coeff_calc */
        return (*qfnn(fn))(qenv(fn), 3, v350, v301, v370);
    }
/* error exit handlers */
v353:
    popv(7);
    return nil;
}



/* Code for dp_content */

static Lisp_Object CC_dp_content(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v308;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_content");
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
    v308 = stack[0];
    if (v308 == nil) goto v393;
    v308 = stack[0];
    fn = elt(env, 2); /* dp_lc */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    stack[-1] = v308;
    v308 = stack[0];
    v308 = qcdr(v308);
    stack[0] = v308;
    goto v357;

v357:
    v308 = stack[0];
    if (v308 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v308 = stack[-1];
    fn = elt(env, 3); /* bc_inv */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    if (!(v308 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v308 = stack[0];
    fn = elt(env, 2); /* dp_lc */
    v308 = (*qfn1(fn))(qenv(fn), v308);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    fn = elt(env, 4); /* bc_gcd */
    v308 = (*qfn2(fn))(qenv(fn), stack[-1], v308);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    stack[-1] = v308;
    v308 = stack[0];
    v308 = qcdr(v308);
    stack[0] = v308;
    goto v357;

v393:
    v308 = (Lisp_Object)1; /* 0 */
    {
        popv(3);
        fn = elt(env, 5); /* bc_fi */
        return (*qfn1(fn))(qenv(fn), v308);
    }
/* error exit handlers */
v266:
    popv(3);
    return nil;
}



/* Code for cdr_signsort */

static Lisp_Object CC_cdr_signsort(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v329, v428;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cdr_signsort");
#endif
    if (stack >= stacklimit)
    {
        push2(v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v316);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v316;
    v329 = v0;
/* end of prologue */
    fn = elt(env, 3); /* copy */
    v329 = (*qfn1(fn))(qenv(fn), v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    stack[-6] = v329;
    v329 = (Lisp_Object)17; /* 1 */
    stack[-1] = v329;
    v329 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v329;
    goto v355;

v355:
    v329 = stack[-6];
    if (v329 == nil) goto v429;
    v329 = stack[-4];
    if (v329 == nil) goto v348;
    v329 = stack[-6];
    v329 = qcar(v329);
    v428 = qcdr(v329);
    v329 = stack[-4];
    v329 = qcar(v329);
    v329 = qcdr(v329);
    if (equal(v428, v329)) goto v369;
    stack[0] = stack[-5];
    v329 = stack[-4];
    v329 = qcar(v329);
    v428 = qcdr(v329);
    v329 = stack[-6];
    v329 = qcar(v329);
    v329 = qcdr(v329);
    v329 = list2(v428, v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    fn = elt(env, 4); /* apply */
    v329 = (*qfn2(fn))(qenv(fn), stack[0], v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    if (v329 == nil) goto v258;
    v329 = stack[-6];
    v428 = qcar(v329);
    v329 = stack[-4];
    v329 = cons(v428, v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    stack[-4] = v329;
    v329 = stack[-6];
    v329 = qcdr(v329);
    stack[-6] = v329;
    goto v355;

v258:
    v329 = stack[-1];
    v329 = negate(v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    stack[-1] = v329;
    v329 = stack[-4];
    stack[-3] = v329;
    v329 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v329;
    goto v398;

v398:
    v329 = stack[-2];
    if (v329 == nil) goto v430;
    v329 = stack[-3];
    v329 = qcdr(v329);
    if (v329 == nil) goto v304;
    v329 = stack[-3];
    v329 = qcdr(v329);
    v329 = qcar(v329);
    v428 = qcdr(v329);
    v329 = stack[-6];
    v329 = qcar(v329);
    v329 = qcdr(v329);
    if (equal(v428, v329)) goto v340;
    stack[0] = stack[-5];
    v329 = stack[-3];
    v329 = qcdr(v329);
    v329 = qcar(v329);
    v428 = qcdr(v329);
    v329 = stack[-6];
    v329 = qcar(v329);
    v329 = qcdr(v329);
    v329 = list2(v428, v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    fn = elt(env, 4); /* apply */
    v329 = (*qfn2(fn))(qenv(fn), stack[0], v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    if (v329 == nil) goto v408;
    v329 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v329;
    goto v398;

v408:
    v329 = stack[-3];
    v329 = qcdr(v329);
    stack[-3] = v329;
    v329 = stack[-1];
    v329 = negate(v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    stack[-1] = v329;
    goto v398;

v340:
    v329 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v329;
    v329 = (Lisp_Object)1; /* 0 */
    stack[-1] = v329;
    v329 = qvalue(elt(env, 1)); /* nil */
    stack[-6] = v329;
    stack[-4] = v329;
    goto v398;

v304:
    v329 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v329;
    goto v398;

v430:
    v329 = stack[-6];
    if (v329 == nil) goto v355;
    stack[0] = stack[-3];
    v329 = stack[-6];
    v428 = qcar(v329);
    v329 = stack[-3];
    v329 = qcdr(v329);
    v329 = cons(v428, v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    v329 = Lrplacd(nil, stack[0], v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    v329 = stack[-6];
    v329 = qcdr(v329);
    stack[-6] = v329;
    goto v355;

v369:
    v329 = (Lisp_Object)1; /* 0 */
    stack[-1] = v329;
    v329 = qvalue(elt(env, 1)); /* nil */
    stack[-6] = v329;
    stack[-4] = v329;
    goto v355;

v348:
    v329 = stack[-6];
    v428 = qcar(v329);
    v329 = stack[-4];
    v329 = cons(v428, v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    stack[-4] = v329;
    v329 = stack[-6];
    v329 = qcdr(v329);
    stack[-6] = v329;
    goto v355;

v429:
    stack[0] = stack[-1];
    v329 = stack[-4];
    v329 = Lreverse(nil, v329);
    nil = C_nil;
    if (exception_pending()) goto v228;
    {
        Lisp_Object v226 = stack[0];
        popv(8);
        return cons(v226, v329);
    }
/* error exit handlers */
v228:
    popv(8);
    return nil;
}



/* Code for gcd!-in!-vector */

static Lisp_Object MS_CDECL CC_gcdKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v316,
                         Lisp_Object v43, Lisp_Object v196, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v297, v448, v449, v450, v451, v452;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gcd-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcd-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push4(v196,v43,v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v316,v43,v196);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v196;
    stack[-1] = v43;
    stack[-2] = v316;
    stack[-3] = v0;
/* end of prologue */
    v448 = stack[-2];
    v297 = (Lisp_Object)1; /* 0 */
    if (v448 == v297) goto v379;
    v448 = stack[0];
    v297 = (Lisp_Object)1; /* 0 */
    v297 = (v448 == v297 ? lisp_true : nil);
    goto v269;

v269:
    if (v297 == nil) goto v235;
    v449 = stack[-3];
    v448 = (Lisp_Object)1; /* 0 */
    v297 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v449 + (CELL-TAG_VECTOR) + ((int32_t)v448/(16/CELL))) = v297;
    v297 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v297); }

v235:
    v448 = stack[-2];
    v297 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v448)) < ((int32_t)(v297))) goto v266;
    v448 = stack[0];
    v297 = (Lisp_Object)1; /* 0 */
    if (!(((int32_t)(v448)) < ((int32_t)(v297)))) goto v261;

v266:
    v297 = elt(env, 2); /* "GCD WITH ZERO NOT ALLOWED" */
    fn = elt(env, 4); /* errorf */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v453;
    env = stack[-4];
    goto v261;

v261:
    v450 = stack[-3];
    v449 = stack[-2];
    v448 = stack[-1];
    v297 = stack[0];
    fn = elt(env, 5); /* remainder!-in!-vector */
    v297 = (*qfnn(fn))(qenv(fn), 4, v450, v449, v448, v297);
    nil = C_nil;
    if (exception_pending()) goto v453;
    env = stack[-4];
    stack[-2] = v297;
    v448 = stack[-2];
    v297 = (Lisp_Object)1; /* 0 */
    if (v448 == v297) goto v256;
    v448 = stack[-2];
    v297 = (Lisp_Object)-15; /* -1 */
    if (v448 == v297) goto v340;
    v450 = stack[-1];
    v449 = stack[0];
    v448 = stack[-3];
    v297 = stack[-2];
    fn = elt(env, 5); /* remainder!-in!-vector */
    v297 = (*qfnn(fn))(qenv(fn), 4, v450, v449, v448, v297);
    nil = C_nil;
    if (exception_pending()) goto v453;
    env = stack[-4];
    stack[0] = v297;
    v448 = stack[0];
    v297 = (Lisp_Object)1; /* 0 */
    if (v448 == v297) goto v232;
    v448 = stack[0];
    v297 = (Lisp_Object)-15; /* -1 */
    if (!(v448 == v297)) goto v261;
    v448 = stack[-3];
    v297 = stack[-2];
    v297 = *(Lisp_Object *)((char *)v448 + (CELL-TAG_VECTOR) + ((int32_t)v297/(16/CELL)));
    v297 = Lmodular_reciprocal(nil, v297);
    nil = C_nil;
    if (exception_pending()) goto v453;
    env = stack[-4];
    v452 = v297;
    v448 = v452;
    v297 = (Lisp_Object)17; /* 1 */
    if (v448 == v297) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v297 = (Lisp_Object)1; /* 0 */
    v451 = v297;
    goto v454;

v454:
    v448 = stack[-2];
    v297 = v451;
    v297 = (Lisp_Object)(int32_t)((int32_t)v448 - (int32_t)v297 + TAG_FIXNUM);
    v297 = ((intptr_t)(v297) < 0 ? lisp_true : nil);
    if (!(v297 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v450 = stack[-3];
    v449 = v451;
    v448 = stack[-3];
    v297 = v451;
    v448 = *(Lisp_Object *)((char *)v448 + (CELL-TAG_VECTOR) + ((int32_t)v297/(16/CELL)));
    v297 = v452;
    v297 = Lmodular_times(nil, v448, v297);
    env = stack[-4];
    *(Lisp_Object *)((char *)v450 + (CELL-TAG_VECTOR) + ((int32_t)v449/(16/CELL))) = v297;
    v297 = v451;
    v297 = (Lisp_Object)((int32_t)(v297) + 0x10);
    v451 = v297;
    goto v454;

v232:
    v449 = stack[-3];
    v448 = (Lisp_Object)1; /* 0 */
    v297 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v449 + (CELL-TAG_VECTOR) + ((int32_t)v448/(16/CELL))) = v297;
    v297 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v297); }

v340:
    v448 = stack[-1];
    v297 = stack[0];
    v297 = *(Lisp_Object *)((char *)v448 + (CELL-TAG_VECTOR) + ((int32_t)v297/(16/CELL)));
    v297 = Lmodular_reciprocal(nil, v297);
    nil = C_nil;
    if (exception_pending()) goto v453;
    env = stack[-4];
    v452 = v297;
    v297 = (Lisp_Object)1; /* 0 */
    v451 = v297;
    goto v344;

v344:
    v448 = stack[0];
    v297 = v451;
    v297 = (Lisp_Object)(int32_t)((int32_t)v448 - (int32_t)v297 + TAG_FIXNUM);
    v297 = ((intptr_t)(v297) < 0 ? lisp_true : nil);
    if (!(v297 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v450 = stack[-3];
    v449 = v451;
    v448 = stack[-1];
    v297 = v451;
    v448 = *(Lisp_Object *)((char *)v448 + (CELL-TAG_VECTOR) + ((int32_t)v297/(16/CELL)));
    v297 = v452;
    v297 = Lmodular_times(nil, v448, v297);
    env = stack[-4];
    *(Lisp_Object *)((char *)v450 + (CELL-TAG_VECTOR) + ((int32_t)v449/(16/CELL))) = v297;
    v297 = v451;
    v297 = (Lisp_Object)((int32_t)(v297) + 0x10);
    v451 = v297;
    goto v344;

v256:
    v449 = stack[-3];
    v448 = (Lisp_Object)1; /* 0 */
    v297 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v449 + (CELL-TAG_VECTOR) + ((int32_t)v448/(16/CELL))) = v297;
    v297 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v297); }

v379:
    v297 = qvalue(elt(env, 1)); /* t */
    goto v269;
/* error exit handlers */
v453:
    popv(5);
    return nil;
}



/* Code for cl_ex */

static Lisp_Object CC_cl_ex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v269, v379, v230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_ex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v269 = v316;
    v379 = v0;
/* end of prologue */
    v230 = elt(env, 1); /* ex */
    {
        fn = elt(env, 2); /* cl_closure */
        return (*qfnn(fn))(qenv(fn), 3, v230, v379, v269);
    }
}



/* Code for chrstrem */

static Lisp_Object CC_chrstrem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v470;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chrstrem");
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
    v172 = qvalue(elt(env, 1)); /* !*trwu */
    if (!(v172 == nil)) goto v312;
    v172 = qvalue(elt(env, 2)); /* !*trchrstrem */
    if (!(v172 == nil)) goto v312;

v338:
    v172 = stack[-3];
    fn = elt(env, 15); /* wusort */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    stack[-3] = v172;
    v172 = qvalue(elt(env, 1)); /* !*trwu */
    if (!(v172 == nil)) goto v319;
    v172 = qvalue(elt(env, 2)); /* !*trchrstrem */
    if (!(v172 == nil)) goto v319;

v275:
    v172 = stack[-3];
    v172 = qcar(v172);
    fn = elt(env, 16); /* wuconstantp */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    if (v172 == nil) goto v403;
    v172 = qvalue(elt(env, 1)); /* !*trwu */
    if (v172 == nil) goto v396;
    v172 = elt(env, 7); /* "which is trivially trivial" */
    fn = elt(env, 17); /* prin2t!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v396;

v396:
    v172 = elt(env, 8); /* inconsistent */
    stack[-2] = v172;
    v172 = (Lisp_Object)17; /* 1 */
    v172 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    stack[-4] = v172;
    goto v260;

v260:
    v172 = qvalue(elt(env, 1)); /* !*trwu */
    if (v172 == nil) goto v347;
    v172 = stack[-2];
    if (!(v172 == nil)) goto v347;
    v172 = elt(env, 9); /* "A basic set is" */
    fn = elt(env, 17); /* prin2t!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = stack[-4];
    v172 = Lreverse(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    stack[0] = v172;
    goto v304;

v304:
    v172 = stack[0];
    if (v172 == nil) goto v381;
    v172 = stack[0];
    v172 = qcar(v172);
    v470 = v172;
    v172 = v470;
    if (v172 == nil) goto v343;
    v172 = v470;
    fn = elt(env, 18); /* xprinf2 */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v251;

v251:
    v172 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 19); /* terpri!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = stack[0];
    v172 = qcdr(v172);
    stack[0] = v172;
    goto v304;

v343:
    v172 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* prin2!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v251;

v381:
    v172 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v347;

v347:
    v470 = stack[-3];
    v172 = stack[-4];
    fn = elt(env, 21); /* setdiff */
    v172 = (*qfn2(fn))(qenv(fn), v470, v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    stack[-1] = v172;
    goto v472;

v472:
    v172 = stack[-1];
    if (v172 == nil) goto v425;
    v172 = stack[-1];
    v172 = qcar(v172);
    stack[0] = v172;
    v470 = stack[-2];
    v172 = elt(env, 8); /* inconsistent */
    if (v470 == v172) goto v243;
    v172 = qvalue(elt(env, 1)); /* !*trwu */
    if (v172 == nil) goto v428;
    v172 = elt(env, 10); /* "The remainder of " */
    fn = elt(env, 20); /* prin2!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = stack[0];
    if (v172 == nil) goto v473;
    v172 = stack[0];
    fn = elt(env, 18); /* xprinf2 */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v234;

v234:
    v172 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 19); /* terpri!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = elt(env, 11); /* "wrt the basic set is " */
    fn = elt(env, 20); /* prin2!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v428;

v428:
    v470 = stack[0];
    v172 = stack[-4];
    fn = elt(env, 22); /* findremainder */
    v172 = (*qfn2(fn))(qenv(fn), v470, v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    stack[0] = v172;
    v172 = qvalue(elt(env, 1)); /* !*trwu */
    if (v172 == nil) goto v228;
    v172 = stack[0];
    if (v172 == nil) goto v438;
    v172 = stack[0];
    fn = elt(env, 18); /* xprinf2 */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v474;

v474:
    v172 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 19); /* terpri!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v228;

v228:
    v172 = stack[0];
    if (v172 == nil) goto v243;
    v172 = stack[0];
    fn = elt(env, 16); /* wuconstantp */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    if (v172 == nil) goto v359;
    v172 = elt(env, 8); /* inconsistent */
    stack[-2] = v172;
    v172 = qvalue(elt(env, 1)); /* !*trwu */
    if (v172 == nil) goto v243;
    v172 = elt(env, 12); /* "which is a non-zero constant, and so" */
    v172 = Lprinc(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = elt(env, 13); /* "the equations are inconsistent." */
    v172 = Lprinc(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v243;

v243:
    v172 = stack[-1];
    v172 = qcdr(v172);
    stack[-1] = v172;
    goto v472;

v359:
    v172 = stack[0];
    fn = elt(env, 23); /* minusf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    if (v172 == nil) goto v361;
    v172 = stack[0];
    fn = elt(env, 24); /* negf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v475;

v475:
    v470 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = stack[-2];
    fn = elt(env, 25); /* union */
    v172 = (*qfn2(fn))(qenv(fn), v470, v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    stack[-2] = v172;
    goto v243;

v361:
    v172 = stack[0];
    goto v475;

v438:
    v172 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* prin2!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v474;

v473:
    v172 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* prin2!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v234;

v425:
    v172 = stack[-2];
    if (v172 == nil) goto v476;
    v470 = stack[-2];
    v172 = elt(env, 8); /* inconsistent */
    if (v470 == v172) goto v476;
    v470 = stack[-3];
    v172 = stack[-2];
    v172 = Lappend(nil, v470, v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    stack[-3] = v172;
    goto v476;

v476:
    v172 = stack[-2];
    if (v172 == nil) goto v477;
    v470 = stack[-2];
    v172 = elt(env, 8); /* inconsistent */
    v172 = (v470 == v172 ? lisp_true : nil);
    goto v478;

v478:
    if (v172 == nil) goto v338;
    v470 = stack[-2];
    v172 = elt(env, 8); /* inconsistent */
    if (!(v470 == v172)) goto v479;
    v172 = (Lisp_Object)17; /* 1 */
    v172 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    stack[-4] = v172;
    goto v479;

v479:
    v172 = qvalue(elt(env, 1)); /* !*trwu */
    if (!(v172 == nil)) goto v201;
    v172 = qvalue(elt(env, 2)); /* !*trchrstrem */
    if (!(v172 == nil)) goto v201;

v203:
    v172 = stack[-4];
    stack[-4] = v172;
    v172 = stack[-4];
    if (v172 == nil) goto v193;
    v172 = stack[-4];
    v172 = qcar(v172);
    stack[0] = v172;
    v172 = stack[0];
    fn = elt(env, 23); /* minusf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    if (v172 == nil) goto v480;
    v172 = stack[0];
    fn = elt(env, 24); /* negf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v481;

v481:
    v172 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    stack[-2] = v172;
    stack[-3] = v172;
    goto v482;

v482:
    v172 = stack[-4];
    v172 = qcdr(v172);
    stack[-4] = v172;
    v172 = stack[-4];
    if (v172 == nil) goto v183;
    stack[-1] = stack[-2];
    v172 = stack[-4];
    v172 = qcar(v172);
    stack[0] = v172;
    v172 = stack[0];
    fn = elt(env, 23); /* minusf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    if (v172 == nil) goto v483;
    v172 = stack[0];
    fn = elt(env, 24); /* negf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v484;

v484:
    v172 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = Lrplacd(nil, stack[-1], v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = stack[-2];
    v172 = qcdr(v172);
    stack[-2] = v172;
    goto v482;

v483:
    v172 = stack[0];
    goto v484;

v183:
    v172 = stack[-3];
    goto v485;

v485:
        popv(6);
        return Lnreverse(nil, v172);

v480:
    v172 = stack[0];
    goto v481;

v193:
    v172 = qvalue(elt(env, 5)); /* nil */
    goto v485;

v201:
    v172 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = elt(env, 14); /* "The final characteristic set is:" */
    fn = elt(env, 17); /* prin2t!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = stack[-4];
    v172 = Lreverse(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    stack[0] = v172;
    goto v486;

v486:
    v172 = stack[0];
    if (v172 == nil) goto v203;
    v172 = stack[0];
    v172 = qcar(v172);
    v470 = v172;
    v172 = v470;
    if (v172 == nil) goto v188;
    v172 = v470;
    fn = elt(env, 18); /* xprinf2 */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v198;

v198:
    v172 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 19); /* terpri!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = stack[0];
    v172 = qcdr(v172);
    stack[0] = v172;
    goto v486;

v188:
    v172 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* prin2!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v198;

v477:
    v172 = qvalue(elt(env, 3)); /* t */
    goto v478;

v403:
    v172 = qvalue(elt(env, 5)); /* nil */
    stack[-2] = v172;
    v172 = stack[-3];
    fn = elt(env, 26); /* pickbasicset */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = Lnreverse(nil, v172);
    env = stack[-5];
    stack[-4] = v172;
    goto v260;

v319:
    v172 = elt(env, 6); /* "The new pol-set in ascending order is" */
    fn = elt(env, 17); /* prin2t!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = stack[-3];
    stack[0] = v172;
    goto v401;

v401:
    v172 = stack[0];
    if (v172 == nil) goto v418;
    v172 = stack[0];
    v172 = qcar(v172);
    v470 = v172;
    v172 = v470;
    if (v172 == nil) goto v313;
    v172 = v470;
    fn = elt(env, 18); /* xprinf2 */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v413;

v413:
    v172 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 19); /* terpri!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = stack[0];
    v172 = qcdr(v172);
    stack[0] = v172;
    goto v401;

v313:
    v172 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* prin2!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v413;

v418:
    v172 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v275;

v312:
    v172 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    v172 = elt(env, 4); /* "--------------------------------------------------------" 
*/
    fn = elt(env, 17); /* prin2t!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v471;
    env = stack[-5];
    goto v338;
/* error exit handlers */
v471:
    popv(6);
    return nil;
}



/* Code for mkbin */

static Lisp_Object CC_mkbin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v402, v369, v307;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkbin");
#endif
    if (stack >= stacklimit)
    {
        push2(v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v316);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v369 = v316;
    v307 = v0;
/* end of prologue */
    v402 = v369;
    v402 = qcdr(v402);
    v402 = qcdr(v402);
    if (v402 == nil) goto v397;
    stack[-1] = v307;
    v402 = v369;
    stack[0] = qcar(v402);
    v402 = v307;
    v369 = qcdr(v369);
    v402 = CC_mkbin(env, v402, v369);
    nil = C_nil;
    if (exception_pending()) goto v265;
    {
        Lisp_Object v266 = stack[-1];
        Lisp_Object v263 = stack[0];
        popv(2);
        return list3(v266, v263, v402);
    }

v397:
    v402 = v307;
    popv(2);
    return cons(v402, v369);
/* error exit handlers */
v265:
    popv(2);
    return nil;
}



/* Code for termlst1 */

static Lisp_Object MS_CDECL CC_termlst1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v316,
                         Lisp_Object v43, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v441, v234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "termlst1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termlst1");
#endif
    if (stack >= stacklimit)
    {
        push3(v43,v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v316,v43);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v43;
    stack[-4] = v316;
    stack[-5] = v0;
/* end of prologue */
    v237 = stack[-5];
    if (v237 == nil) goto v312;
    v237 = stack[-5];
    if (!consp(v237)) goto v378;
    v237 = stack[-5];
    v237 = qcar(v237);
    v237 = (consp(v237) ? nil : lisp_true);
    goto v355;

v355:
    if (v237 == nil) goto v377;
    v441 = stack[-5];
    v237 = stack[-4];
    fn = elt(env, 5); /* multf */
    v441 = (*qfn2(fn))(qenv(fn), v441, v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    env = stack[-7];
    v237 = stack[-3];
    v237 = cons(v441, v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    popv(8);
    return ncons(v237);

v377:
    v237 = stack[-5];
    v237 = qcar(v237);
    v237 = qcar(v237);
    v237 = qcar(v237);
    v234 = v237;
    v237 = v234;
    if (!consp(v237)) goto v315;
    v237 = v234;
    v441 = qcar(v237);
    v237 = elt(env, 3); /* expt */
    if (v441 == v237) goto v411;
    v237 = qvalue(elt(env, 2)); /* t */
    goto v313;

v313:
    if (v237 == nil) goto v252;
    v237 = stack[-5];
    v237 = qcar(v237);
    stack[0] = qcdr(v237);
    v237 = stack[-5];
    v237 = qcar(v237);
    v441 = qcar(v237);
    v237 = (Lisp_Object)17; /* 1 */
    v237 = cons(v441, v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    env = stack[-7];
    v441 = ncons(v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    env = stack[-7];
    v237 = stack[-4];
    fn = elt(env, 5); /* multf */
    v441 = (*qfn2(fn))(qenv(fn), v441, v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    env = stack[-7];
    v237 = stack[-3];
    v237 = CC_termlst1(env, 3, stack[0], v441, v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    env = stack[-7];
    goto v404;

v404:
    stack[0] = v237;
    v237 = stack[-5];
    v234 = qcdr(v237);
    v441 = stack[-4];
    v237 = stack[-3];
    v237 = CC_termlst1(env, 3, v234, v441, v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    {
        Lisp_Object v492 = stack[0];
        popv(8);
        return Lnconc(nil, v492, v237);
    }

v252:
    v237 = stack[-5];
    v237 = qcar(v237);
    stack[-6] = qcdr(v237);
    stack[-2] = stack[-4];
    stack[-1] = stack[-3];
    v237 = v234;
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    v237 = qcar(v237);
    fn = elt(env, 6); /* simp!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    env = stack[-7];
    v237 = stack[-5];
    v237 = qcar(v237);
    v237 = qcar(v237);
    v441 = qcdr(v237);
    v237 = (Lisp_Object)17; /* 1 */
    v237 = cons(v441, v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    env = stack[-7];
    fn = elt(env, 7); /* multsq */
    v237 = (*qfn2(fn))(qenv(fn), stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    env = stack[-7];
    fn = elt(env, 8); /* addsq */
    v237 = (*qfn2(fn))(qenv(fn), stack[-1], v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    env = stack[-7];
    v237 = CC_termlst1(env, 3, stack[-6], stack[-2], v237);
    nil = C_nil;
    if (exception_pending()) goto v491;
    env = stack[-7];
    goto v404;

v411:
    v237 = v234;
    v237 = qcdr(v237);
    v441 = qcar(v237);
    v237 = elt(env, 4); /* e */
    v237 = (v441 == v237 ? lisp_true : nil);
    v237 = (v237 == nil ? lisp_true : nil);
    goto v313;

v315:
    v237 = qvalue(elt(env, 2)); /* t */
    goto v313;

v378:
    v237 = qvalue(elt(env, 2)); /* t */
    goto v355;

v312:
    v237 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v237); }
/* error exit handlers */
v491:
    popv(8);
    return nil;
}



/* Code for repr_new */

static Lisp_Object MS_CDECL CC_repr_new(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v316,
                         Lisp_Object v43, Lisp_Object v196, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v266, v263, v311, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "repr_new");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repr_new");
#endif
    if (stack >= stacklimit)
    {
        push4(v196,v43,v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v316,v43,v196);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v266 = v196;
    v263 = v43;
    v311 = v316;
    v235 = v0;
/* end of prologue */
    stack[-3] = v235;
    stack[-2] = v311;
    stack[-1] = v263;
    stack[0] = v266;
    v266 = v263;
    if (v266 == nil) goto v275;
    v266 = v263;
    v266 = qcar(v266);
    v266 = qcdr(v266);
    goto v276;

v276:
    v266 = list2(stack[0], v266);
    nil = C_nil;
    if (exception_pending()) goto v447;
    {
        Lisp_Object v302 = stack[-3];
        Lisp_Object v399 = stack[-2];
        Lisp_Object v354 = stack[-1];
        popv(5);
        return list3star(v302, v399, v354, v266);
    }

v275:
    v266 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v266 == nil)) goto v371;
    v266 = elt(env, 2); /* "repr_new : invalid coefficient list" */
    v266 = ncons(v266);
    nil = C_nil;
    if (exception_pending()) goto v447;
    env = stack[-4];
    fn = elt(env, 3); /* lprie */
    v266 = (*qfn1(fn))(qenv(fn), v266);
    nil = C_nil;
    if (exception_pending()) goto v447;
    env = stack[-4];
    goto v371;

v371:
    v266 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v447;
    env = stack[-4];
    v266 = nil;
    goto v276;
/* error exit handlers */
v447:
    popv(5);
    return nil;
}



/* Code for ev_max!# */

static Lisp_Object CC_ev_maxC(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v378, v356, v357, v314;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_max#");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v356 = v316;
    v357 = v0;
/* end of prologue */
    v314 = v357;
    v378 = v356;
    if (((int32_t)(v314)) > ((int32_t)(v378))) return onevalue(v357);
    else return onevalue(v356);
}



/* Code for product!-set2 */

static Lisp_Object CC_productKset2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v447, v302;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for product-set2");
#endif
    if (stack >= stacklimit)
    {
        push2(v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v316);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v316;
    v447 = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = v447;
    goto v377;

v377:
    v447 = stack[-2];
    if (v447 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v447 = stack[-2];
    v447 = qcar(v447);
    stack[-1] = v447;
    v447 = stack[-3];
    stack[0] = v447;
    goto v338;

v338:
    v447 = stack[0];
    if (v447 == nil) goto v276;
    v447 = stack[0];
    v447 = qcar(v447);
    v302 = stack[-1];
    v302 = list2(v302, v447);
    nil = C_nil;
    if (exception_pending()) goto v362;
    env = stack[-5];
    v447 = stack[-4];
    v447 = cons(v302, v447);
    nil = C_nil;
    if (exception_pending()) goto v362;
    env = stack[-5];
    stack[-4] = v447;
    v447 = stack[0];
    v447 = qcdr(v447);
    stack[0] = v447;
    goto v338;

v276:
    v447 = stack[-2];
    v447 = qcdr(v447);
    stack[-2] = v447;
    goto v377;
/* error exit handlers */
v362:
    popv(6);
    return nil;
}



/* Code for third_eq_indexp */

static Lisp_Object CC_third_eq_indexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v301, v362, v374;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for third_eq_indexp");
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
    v374 = v0;
/* end of prologue */
    v362 = v374;
    v301 = qvalue(elt(env, 1)); /* dindices!* */
    v301 = Lassoc(nil, v362, v301);
    stack[-2] = v301;
    if (v301 == nil) goto v357;
    v301 = stack[-2];
    v301 = qcdr(v301);
    if (!(v301 == nil)) goto v388;
    stack[-1] = v374;
    stack[0] = qvalue(elt(env, 3)); /* t */
    v362 = stack[-2];
    v301 = qvalue(elt(env, 1)); /* dindices!* */
    v301 = Ldelete(nil, v362, v301);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-3];
    v301 = acons(stack[-1], stack[0], v301);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-3];
    qvalue(elt(env, 1)) = v301; /* dindices!* */
    goto v388;

v388:
    v301 = stack[-2];
    if (v301 == nil) goto v354;
    v301 = stack[-2];
    v301 = qcdr(v301);
    { popv(4); return onevalue(v301); }

v354:
    v301 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v301); }

v357:
    v362 = qvalue(elt(env, 2)); /* nil */
    v301 = qvalue(elt(env, 1)); /* dindices!* */
    v301 = acons(v374, v362, v301);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-3];
    qvalue(elt(env, 1)) = v301; /* dindices!* */
    goto v388;
/* error exit handlers */
v363:
    popv(4);
    return nil;
}



/* Code for pst_isolate */

static Lisp_Object CC_pst_isolate(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v316)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v264, v262;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_isolate");
#endif
    if (stack >= stacklimit)
    {
        push2(v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v316);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v316;
    v264 = v0;
/* end of prologue */
    v262 = v264;
    v264 = stack[-1];
    v264 = qcdr(v264);
    fn = elt(env, 1); /* pst_isolate1 */
    v264 = (*qfn2(fn))(qenv(fn), v262, v264);
    nil = C_nil;
    if (exception_pending()) goto v401;
    env = stack[-3];
    fn = elt(env, 2); /* pst_reduce */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v401;
    env = stack[-3];
    stack[-2] = v264;
    stack[0] = stack[-2];
    v264 = stack[-1];
    v262 = qcar(v264);
    v264 = stack[-2];
    v264 = qcar(v264);
    v264 = Lappend(nil, v262, v264);
    nil = C_nil;
    if (exception_pending()) goto v401;
    env = stack[-3];
    v264 = Lrplaca(nil, stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v401;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v401:
    popv(4);
    return nil;
}



/* Code for r2flbf2r */

static Lisp_Object CC_r2flbf2r(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v387;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2flbf2r");
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
    v387 = v0;
/* end of prologue */
    fn = elt(env, 1); /* r2flbf */
    v387 = (*qfn1(fn))(qenv(fn), v387);
    nil = C_nil;
    if (exception_pending()) goto v388;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* realrat */
        return (*qfn1(fn))(qenv(fn), v387);
    }
/* error exit handlers */
v388:
    popv(1);
    return nil;
}



/* Code for glsoleig */

static Lisp_Object MS_CDECL CC_glsoleig(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v316,
                         Lisp_Object v43, Lisp_Object v196, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v331, v250, v381;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "glsoleig");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for glsoleig");
#endif
    if (stack >= stacklimit)
    {
        push4(v196,v43,v316,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v316,v43,v196);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v196;
    stack[-2] = v43;
    stack[-3] = v316;
    stack[-4] = v0;
/* end of prologue */
    v381 = nil;
    stack[0] = nil;
    v331 = stack[-2];
    v331 = qcar(v331);
    v331 = qcar(v331);
    stack[-5] = v331;
    goto v312;

v312:
    v331 = stack[-5];
    if (v331 == nil) goto v230;
    v331 = stack[-5];
    v250 = qcar(v331);
    v331 = stack[-4];
    if (equal(v250, v331)) goto v374;
    v331 = stack[-5];
    v250 = qcar(v331);
    v331 = stack[-3];
    v331 = Lmember(nil, v250, v331);
    if (v331 == nil) goto v411;
    v331 = stack[-5];
    v331 = qcdr(v331);
    stack[-5] = v331;
    v331 = v381;
    if (v331 == nil) goto v312;
    v331 = stack[0];
    v331 = (v331 == nil ? lisp_true : nil);
    stack[0] = v331;
    goto v312;

v411:
    v331 = v381;
    if (v331 == nil) goto v430;
    v331 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v331); }

v430:
    v331 = stack[-5];
    v331 = qcar(v331);
    v331 = ncons(v331);
    nil = C_nil;
    if (exception_pending()) goto v421;
    env = stack[-6];
    v381 = v331;
    v331 = stack[-5];
    v331 = qcdr(v331);
    stack[-5] = v331;
    goto v312;

v374:
    v331 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v331); }

v230:
    v331 = v381;
    v331 = qcar(v331);
    if (v331 == nil) goto v314;
    v331 = v381;
    v250 = qcar(v331);
    v331 = stack[-1];
    v331 = Lassoc(nil, v250, v331);
    stack[-1] = qcdr(v331);
    v331 = stack[0];
    if (v331 == nil) goto v302;
    v331 = stack[-2];
    v331 = qcar(v331);
    v331 = qcdr(v331);
    fn = elt(env, 2); /* negf */
    v331 = (*qfn1(fn))(qenv(fn), v331);
    nil = C_nil;
    if (exception_pending()) goto v421;
    env = stack[-6];
    goto v264;

v264:
    {
        Lisp_Object v488 = stack[-1];
        popv(7);
        fn = elt(env, 3); /* multf */
        return (*qfn2(fn))(qenv(fn), v488, v331);
    }

v302:
    v331 = stack[-2];
    v331 = qcar(v331);
    v331 = qcdr(v331);
    goto v264;

v314:
    v331 = stack[-2];
    v331 = qcar(v331);
    v331 = qcdr(v331);
    { popv(7); return onevalue(v331); }
/* error exit handlers */
v421:
    popv(7);
    return nil;
}



setup_type const u50_setup[] =
{
    {"liendimcom",              CC_liendimcom,  too_many_1,    wrong_no_1},
    {"sc_create",               CC_sc_create,   too_many_1,    wrong_no_1},
    {"modroots1",               too_few_2,      CC_modroots1,  wrong_no_2},
    {"quotfail-mod-p",          too_few_2,      CC_quotfailKmodKp,wrong_no_2},
    {"setqdeletedescendants",   CC_setqdeletedescendants,too_many_1,wrong_no_1},
    {"rl_ex",                   too_few_2,      CC_rl_ex,      wrong_no_2},
    {"ofsf_smdbgetrel",         too_few_2,      CC_ofsf_smdbgetrel,wrong_no_2},
    {"addcoeffs",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_addcoeffs},
    {"mk_resimp_rep",           CC_mk_resimp_rep,too_many_1,   wrong_no_1},
    {"subst-cn",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_substKcn},
    {"qqe_qadd-inside-at",      CC_qqe_qaddKinsideKat,too_many_1,wrong_no_1},
    {"ratpoly_pp",              CC_ratpoly_pp,  too_many_1,    wrong_no_1},
    {"ps:find-order1",          CC_psTfindKorder1,too_many_1,  wrong_no_1},
    {"specrd:sqrt",             CC_specrdTsqrt, too_many_1,    wrong_no_1},
    {"weak_xreduce",            too_few_2,      CC_weak_xreduce,wrong_no_2},
    {":dm2fix",                 CC_Tdm2fix,     too_many_1,    wrong_no_1},
    {"delength",                CC_delength,    too_many_1,    wrong_no_1},
    {"calc_map_2d",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_calc_map_2d},
    {"dp_content",              CC_dp_content,  too_many_1,    wrong_no_1},
    {"cdr_signsort",            too_few_2,      CC_cdr_signsort,wrong_no_2},
    {"gcd-in-vector",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_gcdKinKvector},
    {"cl_ex",                   too_few_2,      CC_cl_ex,      wrong_no_2},
    {"chrstrem",                CC_chrstrem,    too_many_1,    wrong_no_1},
    {"mkbin",                   too_few_2,      CC_mkbin,      wrong_no_2},
    {"termlst1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_termlst1},
    {"repr_new",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_repr_new},
    {"ev_max#",                 too_few_2,      CC_ev_maxC,    wrong_no_2},
    {"product-set2",            too_few_2,      CC_productKset2,wrong_no_2},
    {"third_eq_indexp",         CC_third_eq_indexp,too_many_1, wrong_no_1},
    {"pst_isolate",             too_few_2,      CC_pst_isolate,wrong_no_2},
    {"r2flbf2r",                CC_r2flbf2r,    too_many_1,    wrong_no_1},
    {"glsoleig",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_glsoleig},
    {NULL, (one_args *)"u50", (two_args *)"22279 8653451 4205558", 0}
};

/* end of generated code */
