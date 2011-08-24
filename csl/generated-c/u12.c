
/* $destdir\u12.c        Machine generated C code */

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


/* Code for cl_varl2 */

static Lisp_Object MS_CDECL CC_cl_varl2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v84, v85, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_varl2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_varl2");
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
    stack[-2] = v3;
    stack[0] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v87:
    v83 = stack[-4];
    if (!consp(v83)) goto v88;
    v83 = stack[-4];
    v83 = qcar(v83);
    goto v89;

v89:
    v85 = v83;
    v84 = v85;
    v83 = elt(env, 1); /* true */
    if (v84 == v83) goto v90;
    v84 = v85;
    v83 = elt(env, 3); /* false */
    v83 = (v84 == v83 ? lisp_true : nil);
    goto v91;

v91:
    if (v83 == nil) goto v92;
    v84 = stack[-3];
    v83 = stack[-2];
    popv(6);
    return cons(v84, v83);

v92:
    v84 = v85;
    v83 = elt(env, 4); /* or */
    if (v84 == v83) goto v93;
    v84 = v85;
    v83 = elt(env, 5); /* and */
    v83 = (v84 == v83 ? lisp_true : nil);
    goto v94;

v94:
    if (v83 == nil) goto v95;
    v83 = qvalue(elt(env, 2)); /* t */
    goto v96;

v96:
    if (v83 == nil) goto v97;
    v83 = qvalue(elt(env, 2)); /* t */
    goto v98;

v98:
    if (v83 == nil) goto v99;
    v83 = stack[-4];
    v83 = qcdr(v83);
    stack[-1] = v83;
    goto v100;

v100:
    v83 = stack[-1];
    if (v83 == nil) goto v101;
    v83 = stack[-1];
    v83 = qcar(v83);
    v86 = v83;
    v85 = stack[-3];
    v84 = stack[0];
    v83 = stack[-2];
    v83 = CC_cl_varl2(env, 4, v86, v85, v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    v84 = v83;
    v83 = v84;
    v83 = qcar(v83);
    stack[-3] = v83;
    v83 = v84;
    v83 = qcdr(v83);
    stack[-2] = v83;
    v83 = stack[-1];
    v83 = qcdr(v83);
    stack[-1] = v83;
    goto v100;

v101:
    v84 = stack[-3];
    v83 = stack[-2];
    popv(6);
    return cons(v84, v83);

v99:
    v84 = v85;
    v83 = elt(env, 11); /* ex */
    if (v84 == v83) goto v103;
    v84 = v85;
    v83 = elt(env, 12); /* all */
    v83 = (v84 == v83 ? lisp_true : nil);
    goto v104;

v104:
    if (v83 == nil) goto v105;
    v83 = stack[-4];
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    stack[-1] = qcar(v83);
    v83 = stack[-4];
    v83 = qcdr(v83);
    v84 = qcar(v83);
    v83 = stack[0];
    fn = elt(env, 15); /* lto_insertq */
    stack[0] = (*qfn2(fn))(qenv(fn), v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    v83 = stack[-4];
    v83 = qcdr(v83);
    v84 = qcar(v83);
    v83 = stack[-2];
    v83 = cons(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    stack[-4] = stack[-1];
    stack[-2] = v83;
    goto v87;

v105:
    v84 = v85;
    v83 = elt(env, 13); /* bex */
    if (v84 == v83) goto v106;
    v84 = v85;
    v83 = elt(env, 14); /* ball */
    v83 = (v84 == v83 ? lisp_true : nil);
    goto v107;

v107:
    if (v83 == nil) goto v108;
    v83 = stack[-4];
    v83 = qcdr(v83);
    stack[-1] = qcar(v83);
    v83 = stack[-4];
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    v86 = qcar(v83);
    v85 = stack[-3];
    v84 = qvalue(elt(env, 10)); /* nil */
    v83 = qvalue(elt(env, 10)); /* nil */
    v83 = CC_cl_varl2(env, 4, v86, v85, v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    v83 = qcar(v83);
    fn = elt(env, 16); /* delq */
    v83 = (*qfn2(fn))(qenv(fn), stack[-1], v83);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    stack[-1] = v83;
    v83 = stack[-4];
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    stack[-3] = qcar(v83);
    v83 = stack[-4];
    v83 = qcdr(v83);
    v84 = qcar(v83);
    v83 = stack[0];
    fn = elt(env, 15); /* lto_insertq */
    stack[0] = (*qfn2(fn))(qenv(fn), v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    v83 = stack[-4];
    v83 = qcdr(v83);
    v84 = qcar(v83);
    v83 = stack[-2];
    v83 = cons(v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    v83 = CC_cl_varl2(env, 4, stack[-3], stack[-1], stack[0], v83);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    stack[-1] = v83;
    v83 = stack[-4];
    v83 = qcdr(v83);
    v84 = qcar(v83);
    v83 = stack[-1];
    v83 = qcar(v83);
    fn = elt(env, 16); /* delq */
    v84 = (*qfn2(fn))(qenv(fn), v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v102;
    v83 = stack[-1];
    v83 = qcdr(v83);
    popv(6);
    return cons(v84, v83);

v108:
    v83 = stack[-4];
    fn = elt(env, 17); /* rl_varlat */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    stack[-1] = v83;
    goto v109;

v109:
    v83 = stack[-1];
    if (v83 == nil) goto v110;
    v83 = stack[-1];
    v83 = qcar(v83);
    v85 = v83;
    v84 = v85;
    v83 = stack[0];
    v83 = Lmemq(nil, v84, v83);
    if (!(v83 == nil)) goto v111;
    v84 = v85;
    v83 = stack[-3];
    fn = elt(env, 15); /* lto_insertq */
    v83 = (*qfn2(fn))(qenv(fn), v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    stack[-3] = v83;
    goto v111;

v111:
    v83 = stack[-1];
    v83 = qcdr(v83);
    stack[-1] = v83;
    goto v109;

v110:
    v84 = stack[-3];
    v83 = stack[-2];
    popv(6);
    return cons(v84, v83);

v106:
    v83 = qvalue(elt(env, 2)); /* t */
    goto v107;

v103:
    v83 = qvalue(elt(env, 2)); /* t */
    goto v104;

v97:
    v84 = v85;
    v83 = elt(env, 7); /* impl */
    if (v84 == v83) goto v112;
    v84 = v85;
    v83 = elt(env, 8); /* repl */
    if (v84 == v83) goto v113;
    v84 = v85;
    v83 = elt(env, 9); /* equiv */
    v83 = (v84 == v83 ? lisp_true : nil);
    goto v98;

v113:
    v83 = qvalue(elt(env, 2)); /* t */
    goto v98;

v112:
    v83 = qvalue(elt(env, 2)); /* t */
    goto v98;

v95:
    v84 = v85;
    v83 = elt(env, 6); /* not */
    v83 = (v84 == v83 ? lisp_true : nil);
    goto v96;

v93:
    v83 = qvalue(elt(env, 2)); /* t */
    goto v94;

v90:
    v83 = qvalue(elt(env, 2)); /* t */
    goto v91;

v88:
    v83 = stack[-4];
    goto v89;
/* error exit handlers */
v102:
    popv(6);
    return nil;
}



/* Code for ldt!-tvar */

static Lisp_Object CC_ldtKtvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v90, v116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldt-tvar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v91 = v0;
/* end of prologue */
    v91 = qcar(v91);
    v91 = qcar(v91);
    v90 = v91;
    v91 = v90;
    v116 = elt(env, 1); /* df */
    if (!consp(v91)) return onevalue(v90);
    v91 = qcar(v91);
    if (!(v91 == v116)) return onevalue(v90);
    v91 = v90;
    v91 = qcdr(v91);
    v91 = qcar(v91);
    return onevalue(v91);
}



/* Code for simpindexvar */

static Lisp_Object CC_simpindexvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpindexvar");
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
    v34 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitindexvar */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v34);
    }
/* error exit handlers */
v14:
    popv(1);
    return nil;
}



/* Code for mksetq */

static Lisp_Object CC_mksetq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v125, v126, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksetq");
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
    v125 = v1;
    v126 = v0;
/* end of prologue */
    v98 = v126;
    if (!consp(v98)) goto v78;
    v98 = v126;
    v63 = qcar(v98);
    v98 = elt(env, 2); /* setfn */
    v98 = get(v63, v98);
    env = stack[0];
    v63 = v98;
    if (v98 == nil) goto v72;
    v98 = v63;
        popv(1);
        return Lapply2(nil, 3, v98, v126, v125);

v72:
    v125 = v126;
    v98 = elt(env, 3); /* "assignment argument" */
    fn = elt(env, 4); /* typerr */
    v98 = (*qfn2(fn))(qenv(fn), v125, v98);
    nil = C_nil;
    if (exception_pending()) goto v96;
    v98 = nil;
    { popv(1); return onevalue(v98); }

v78:
    v98 = elt(env, 1); /* setq */
    popv(1);
    return list3(v98, v126, v125);
/* error exit handlers */
v96:
    popv(1);
    return nil;
}



/* Code for evalneq */

static Lisp_Object CC_evalneq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalneq");
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
    v127 = v1;
    v128 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evalequal */
    v127 = (*qfn2(fn))(qenv(fn), v128, v127);
    errexit();
    v127 = (v127 == nil ? lisp_true : nil);
    return onevalue(v127);
}



/* Code for mv!-pow!-!- */

static Lisp_Object CC_mvKpowKK(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow--");
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
    goto v14;

v14:
    v132 = stack[-1];
    if (v132 == nil) goto v78;
    v132 = stack[-1];
    v133 = qcar(v132);
    v132 = stack[0];
    v132 = qcar(v132);
    v133 = difference2(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    v132 = stack[-2];
    v132 = cons(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    stack[-2] = v132;
    v132 = stack[-1];
    v132 = qcdr(v132);
    stack[-1] = v132;
    v132 = stack[0];
    v132 = qcdr(v132);
    stack[0] = v132;
    goto v14;

v78:
    v132 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v132);
    }
/* error exit handlers */
v74:
    popv(4);
    return nil;
}



/* Code for bc_fi */

static Lisp_Object CC_bc_fi(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v124, v134;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_fi");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v134 = v0;
/* end of prologue */
    v124 = v134;
    v114 = (Lisp_Object)1; /* 0 */
    if (!(v124 == v114)) return onevalue(v134);
    v114 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v114);
}



/* Code for pv_times3 */

static Lisp_Object CC_pv_times3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_times3");
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
    v130 = stack[-1];
    v136 = qcar(v130);
    v130 = stack[0];
    v130 = qcar(v130);
    stack[-2] = times2(v136, v130);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-3];
    v130 = stack[-1];
    v136 = qcdr(v130);
    v130 = stack[0];
    v130 = qcdr(v130);
    fn = elt(env, 1); /* pappend */
    v130 = (*qfn2(fn))(qenv(fn), v136, v130);
    nil = C_nil;
    if (exception_pending()) goto v137;
    {
        Lisp_Object v122 = stack[-2];
        popv(4);
        return cons(v122, v130);
    }
/* error exit handlers */
v137:
    popv(4);
    return nil;
}



/* Code for dv_skel2factor1 */

static Lisp_Object CC_dv_skel2factor1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skel2factor1");
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
    v143 = stack[-1];
    if (v143 == nil) goto v78;
    v143 = stack[-1];
    fn = elt(env, 3); /* listp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    if (v143 == nil) goto v118;
    v143 = stack[-1];
    v144 = qcar(v143);
    v143 = stack[0];
    v143 = CC_dv_skel2factor1(env, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[-2] = v143;
    v143 = stack[-1];
    v144 = qcdr(v143);
    v143 = stack[0];
    v143 = CC_dv_skel2factor1(env, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v143 = cons(stack[-2], v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    { popv(4); return onevalue(v143); }

v118:
    v144 = stack[-1];
    v143 = elt(env, 2); /* !~dv */
    if (!(v144 == v143)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v143 = stack[0];
    v143 = qcar(v143);
    stack[-1] = v143;
    v143 = stack[0];
    v143 = qcdr(v143);
    if (v143 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v144 = stack[0];
    v143 = stack[0];
    v143 = qcdr(v143);
    v143 = qcar(v143);
    v143 = Lrplaca(nil, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v144 = stack[0];
    v143 = stack[0];
    v143 = qcdr(v143);
    v143 = qcdr(v143);
    v143 = Lrplacd(nil, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v78:
    v143 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v143); }
/* error exit handlers */
v145:
    popv(4);
    return nil;
}



/* Code for copy!-vector */

static Lisp_Object MS_CDECL CC_copyKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v147, v119, v118, v120, v148, v149, v150;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "copy-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copy-vector");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v120 = v2;
    v148 = v1;
    v149 = v0;
/* end of prologue */
    v75 = (Lisp_Object)1; /* 0 */
    v150 = v75;
    goto v128;

v128:
    v147 = v148;
    v75 = v150;
    v75 = (Lisp_Object)(int32_t)((int32_t)v147 - (int32_t)v75 + TAG_FIXNUM);
    v75 = ((intptr_t)(v75) < 0 ? lisp_true : nil);
    if (!(v75 == nil)) return onevalue(v148);
    v118 = v120;
    v119 = v150;
    v147 = v149;
    v75 = v150;
    v75 = *(Lisp_Object *)((char *)v147 + (CELL-TAG_VECTOR) + ((int32_t)v75/(16/CELL)));
    *(Lisp_Object *)((char *)v118 + (CELL-TAG_VECTOR) + ((int32_t)v119/(16/CELL))) = v75;
    v75 = v150;
    v75 = (Lisp_Object)((int32_t)(v75) + 0x10);
    v150 = v75;
    goto v128;
}



/* Code for difference!-mod!-p */

static Lisp_Object CC_differenceKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difference-mod-p");
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
    v127 = v1;
    v128 = v0;
/* end of prologue */
    stack[0] = v128;
    fn = elt(env, 1); /* minus!-mod!-p */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-1];
    {
        Lisp_Object v115 = stack[0];
        popv(2);
        fn = elt(env, 2); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v115, v127);
    }
/* error exit handlers */
v151:
    popv(2);
    return nil;
}



/* Code for sfto_ucontentf */

static Lisp_Object CC_sfto_ucontentf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_ucontentf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v131 = v0;
/* end of prologue */
    v77 = v131;
    if (!consp(v77)) goto v152;
    v77 = v131;
    v77 = qcar(v77);
    v77 = (consp(v77) ? nil : lisp_true);
    goto v153;

v153:
    if (!(v77 == nil)) return onevalue(v131);
    v77 = v131;
    v131 = qcar(v131);
    v131 = qcar(v131);
    v131 = qcar(v131);
    {
        fn = elt(env, 2); /* sfto_ucontentf1 */
        return (*qfn2(fn))(qenv(fn), v77, v131);
    }

v152:
    v77 = qvalue(elt(env, 1)); /* t */
    goto v153;
}



/* Code for ofsf_prepat */

static Lisp_Object CC_ofsf_prepat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_prepat");
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
    v121 = stack[-1];
    stack[-2] = qcar(v121);
    v121 = stack[-1];
    v121 = qcdr(v121);
    v121 = qcar(v121);
    fn = elt(env, 1); /* prepf */
    stack[0] = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    v121 = stack[-1];
    v121 = qcdr(v121);
    v121 = qcdr(v121);
    v121 = qcar(v121);
    fn = elt(env, 1); /* prepf */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v90;
    {
        Lisp_Object v116 = stack[-2];
        Lisp_Object v142 = stack[0];
        popv(4);
        return list3(v116, v142, v121);
    }
/* error exit handlers */
v90:
    popv(4);
    return nil;
}



/* Code for attributesml */

static Lisp_Object CC_attributesml(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for attributesml");
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
    v139 = stack[-1];
    if (v139 == nil) goto v153;
    v139 = elt(env, 2); /* " " */
    v139 = Lprinc(nil, v139);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v139 = stack[-1];
    v139 = qcar(v139);
    v139 = qcar(v139);
    v139 = Lprinc(nil, v139);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v139 = elt(env, 3); /* "=""" */
    v139 = Lprinc(nil, v139);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v139 = stack[-1];
    v139 = qcar(v139);
    v155 = qcar(v139);
    v139 = elt(env, 4); /* definitionurl */
    if (v155 == v139) goto v63;
    v139 = stack[-1];
    v139 = qcar(v139);
    v139 = qcdr(v139);
    v155 = qcar(v139);
    v139 = elt(env, 5); /* vectorml */
    if (v155 == v139) goto v146;
    v139 = stack[-1];
    v139 = qcar(v139);
    v139 = qcdr(v139);
    v139 = qcar(v139);
    v139 = Lprinc(nil, v139);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    goto v90;

v90:
    v139 = elt(env, 8); /* """" */
    v139 = Lprinc(nil, v139);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v139 = stack[-1];
    v155 = qcdr(v139);
    v139 = stack[0];
    v139 = CC_attributesml(env, v155, v139);
    nil = C_nil;
    if (exception_pending()) goto v67;
    goto v14;

v14:
    v139 = nil;
    { popv(3); return onevalue(v139); }

v146:
    v139 = elt(env, 6); /* "vector" */
    v139 = Lprinc(nil, v139);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    goto v90;

v63:
    v139 = stack[-1];
    v139 = qcar(v139);
    v139 = qcdr(v139);
    v139 = qcar(v139);
    fn = elt(env, 9); /* list2string */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    goto v90;

v153:
    v139 = stack[0];
    v139 = Lprinc(nil, v139);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v139 = elt(env, 1); /* ">" */
    v139 = Lprinc(nil, v139);
    nil = C_nil;
    if (exception_pending()) goto v67;
    goto v14;
/* error exit handlers */
v67:
    popv(3);
    return nil;
}



/* Code for groebnormalform */

static Lisp_Object MS_CDECL CC_groebnormalform(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v134, v157, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groebnormalform");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebnormalform");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v124 = v2;
    v134 = v1;
    v157 = v0;
/* end of prologue */
    v121 = v157;
    v157 = v134;
    v134 = v124;
    v124 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* groebnormalform0 */
        return (*qfnn(fn))(qenv(fn), 4, v121, v157, v134, v124);
    }
}



/* Code for prop!-simp */

static Lisp_Object CC_propKsimp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v121, v129, v73, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v157 = v1;
    v121 = v0;
/* end of prologue */
    v91 = v121;
    v73 = v157;
    v129 = qvalue(elt(env, 1)); /* nil */
    v121 = (Lisp_Object)1; /* 0 */
    v157 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 2); /* prop!-simp1 */
        return (*qfnn(fn))(qenv(fn), 5, v91, v73, v129, v121, v157);
    }
}



/* Code for assert_format */

static Lisp_Object MS_CDECL CC_assert_format(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v171, v172;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "assert_format");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_format");
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
    push(nil);
/* copy arguments values to proper place */
    v170 = v2;
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    v170 = Lexplode(nil, v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    stack[-10] = v170;
    stack[-7] = elt(env, 1); /* !! */
    stack[-6] = elt(env, 2); /* !) */
    stack[-5] = elt(env, 1); /* !! */
    stack[-4] = elt(env, 3); /* !  */
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 4); /* !- */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 5); /* !> */
    v172 = elt(env, 1); /* !! */
    v171 = elt(env, 3); /* !  */
    v170 = stack[-10];
    v170 = list2star(v172, v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    v170 = list2star(stack[-1], stack[0], v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    v170 = list2star(stack[-3], stack[-2], v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    v170 = list2star(stack[-5], stack[-4], v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    v170 = list2star(stack[-7], stack[-6], v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    stack[-10] = v170;
    v170 = stack[-8];
    v170 = Lreverse(nil, v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    stack[-2] = v170;
    goto v174;

v174:
    v170 = stack[-2];
    if (v170 == nil) goto v96;
    v170 = stack[-2];
    v170 = qcar(v170);
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 7); /* !, */
    v171 = Lexplode(nil, v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    v170 = stack[-10];
    v170 = Lnconc(nil, v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    v170 = list2star(stack[-1], stack[0], v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    stack[-10] = v170;
    v170 = stack[-2];
    v170 = qcdr(v170);
    stack[-2] = v170;
    goto v174;

v96:
    v170 = stack[-10];
    v170 = qcdr(v170);
    v170 = qcdr(v170);
    stack[-10] = v170;
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 8); /* !: */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 3); /* !  */
    v172 = elt(env, 1); /* !! */
    v171 = elt(env, 9); /* !( */
    v170 = stack[-10];
    v170 = list2star(v172, v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    v170 = list2star(stack[-1], stack[0], v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    v170 = list2star(stack[-3], stack[-2], v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    stack[-10] = v170;
    v170 = stack[-9];
    v171 = Lexplode(nil, v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-11];
    v170 = stack[-10];
    v170 = Lnconc(nil, v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v173;
    stack[-10] = v170;
    v170 = stack[-10];
        popv(12);
        return Lcompress(nil, v170);
/* error exit handlers */
v173:
    popv(12);
    return nil;
}



/* Code for aminusp!:1 */

static Lisp_Object CC_aminuspT1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v180, v181, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aminusp:1");
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
    v179 = stack[-1];
    fn = elt(env, 6); /* aeval!* */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    stack[-1] = v179;
    v179 = stack[-1];
    stack[-2] = v179;
    v179 = stack[-2];
    v179 = integerp(v179);
    if (v179 == nil) goto v134;
    v179 = stack[-2];
        popv(4);
        return Lminusp(nil, v179);

v134:
    v180 = stack[-2];
    v179 = elt(env, 1); /* !*sq */
    if (!consp(v180)) goto v142;
    v180 = qcar(v180);
    if (!(v180 == v179)) goto v142;

v78:
    v179 = stack[-2];
    v179 = qcdr(v179);
    v179 = qcar(v179);
    stack[-2] = v179;
    v179 = stack[-2];
    v179 = qcar(v179);
    v179 = integerp(v179);
    if (v179 == nil) goto v183;
    v179 = stack[-2];
    v179 = qcdr(v179);
    v179 = integerp(v179);
    if (v179 == nil) goto v183;
    v179 = stack[-2];
    v179 = qcar(v179);
        popv(4);
        return Lminusp(nil, v179);

v183:
    v179 = stack[-2];
    v180 = qcdr(v179);
    v179 = (Lisp_Object)17; /* 1 */
    if (v180 == v179) goto v138;
    v179 = qvalue(elt(env, 4)); /* t */
    goto v66;

v66:
    if (v179 == nil) goto v184;
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v179 = stack[-1];
    fn = elt(env, 7); /* reval */
    v182 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v181 = elt(env, 3); /* "invalid in FOR statement" */
    v180 = qvalue(elt(env, 2)); /* nil */
    v179 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v179 = (*qfnn(fn))(qenv(fn), 5, stack[0], v182, v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v167;
    v179 = nil;
    { popv(4); return onevalue(v179); }

v184:
    v180 = elt(env, 5); /* !:minusp */
    v179 = stack[-2];
        popv(4);
        return Lapply1(nil, v180, v179);

v138:
    v179 = stack[-2];
    v179 = qcar(v179);
    stack[-2] = v179;
    if (!consp(v179)) goto v155;
    v179 = stack[-2];
    v179 = qcar(v179);
    v179 = (consp(v179) ? nil : lisp_true);
    goto v139;

v139:
    v179 = (v179 == nil ? lisp_true : nil);
    goto v66;

v155:
    v179 = qvalue(elt(env, 4)); /* t */
    goto v139;

v142:
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v179 = stack[-1];
    fn = elt(env, 7); /* reval */
    v182 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v181 = elt(env, 3); /* "invalid in FOR statement" */
    v180 = qvalue(elt(env, 2)); /* nil */
    v179 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v179 = (*qfnn(fn))(qenv(fn), 5, stack[0], v182, v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    goto v78;
/* error exit handlers */
v167:
    popv(4);
    return nil;
}



/* Code for nzeros */

static Lisp_Object CC_nzeros(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nzeros");
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
    goto v89;

v89:
    v77 = stack[0];
    v131 = (Lisp_Object)1; /* 0 */
    if (v77 == v131) goto v152;
    v77 = (Lisp_Object)1; /* 0 */
    v131 = stack[-1];
    v131 = cons(v77, v131);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    stack[-1] = v131;
    v131 = stack[0];
    v131 = sub1(v131);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    stack[0] = v131;
    goto v89;

v152:
    v131 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v131);
    }
/* error exit handlers */
v122:
    popv(3);
    return nil;
}



/* Code for dividef */

static Lisp_Object CC_dividef(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v185, v186, v187;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dividef");
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
    v71 = v1;
    v185 = v0;
/* end of prologue */
    v71 = Ldivide(nil, v185, v71);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[0];
    v187 = v71;
    v71 = v187;
    v185 = qcar(v71);
    v71 = (Lisp_Object)1; /* 0 */
    if (v185 == v71) goto v157;
    v71 = v187;
    v71 = qcar(v71);
    v186 = v71;
    goto v146;

v146:
    v71 = v187;
    v185 = qcdr(v71);
    v71 = (Lisp_Object)1; /* 0 */
    if (v185 == v71) goto v132;
    v71 = v187;
    v71 = qcdr(v71);
    goto v115;

v115:
    popv(1);
    return cons(v186, v71);

v132:
    v71 = qvalue(elt(env, 1)); /* nil */
    goto v115;

v157:
    v71 = qvalue(elt(env, 1)); /* nil */
    v186 = v71;
    goto v146;
/* error exit handlers */
v117:
    popv(1);
    return nil;
}



/* Code for terpri!* */

static Lisp_Object CC_terpriH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v189, v190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for terpri*");
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
    v188 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v188 == nil) goto v78;
    v189 = qvalue(elt(env, 1)); /* outputhandler!* */
    v190 = elt(env, 2); /* terpri */
    v188 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v189, v190, v188);

v78:
    v188 = qvalue(elt(env, 3)); /* testing!-width!* */
    if (v188 == nil) goto v73;
    v188 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 5)) = v188; /* overflowed!* */
    { popv(3); return onevalue(v188); }

v73:
    v188 = qvalue(elt(env, 6)); /* !*fort */
    if (v188 == nil) goto v142;
    v189 = qvalue(elt(env, 7)); /* posn!* */
    v188 = (Lisp_Object)1; /* 0 */
    if (v189 == v188) goto v119;
    v188 = stack[0];
    goto v137;

v137:
    if (v188 == nil) goto v136;
    v188 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    goto v136;

v136:
    v188 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v188; /* posn!* */
    { popv(3); return onevalue(v188); }

v119:
    v188 = qvalue(elt(env, 8)); /* nil */
    goto v137;

v142:
    v188 = qvalue(elt(env, 9)); /* !*nat */
    if (v188 == nil) goto v153;
    v188 = qvalue(elt(env, 10)); /* pline!* */
    if (v188 == nil) goto v153;
    v188 = qvalue(elt(env, 10)); /* pline!* */
    v188 = Lreverse(nil, v188);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    qvalue(elt(env, 10)) = v188; /* pline!* */
    v188 = qvalue(elt(env, 11)); /* ymax!* */
    stack[-1] = v188;
    goto v92;

v92:
    v189 = stack[-1];
    v188 = qvalue(elt(env, 12)); /* ymin!* */
    v188 = difference2(v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    v188 = Lminusp(nil, v188);
    env = stack[-2];
    if (v188 == nil) goto v154;
    v188 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 10)) = v188; /* pline!* */
    goto v153;

v153:
    v188 = stack[0];
    if (v188 == nil) goto v95;
    v188 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    goto v95;

v95:
    v188 = qvalue(elt(env, 13)); /* orig!* */
    qvalue(elt(env, 7)) = v188; /* posn!* */
    v188 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v188; /* ymin!* */
    qvalue(elt(env, 11)) = v188; /* ymax!* */
    qvalue(elt(env, 14)) = v188; /* ycoord!* */
    v188 = nil;
    { popv(3); return onevalue(v188); }

v154:
    v189 = qvalue(elt(env, 10)); /* pline!* */
    v188 = stack[-1];
    fn = elt(env, 15); /* scprint */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    v188 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    v188 = stack[-1];
    v188 = sub1(v188);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    stack[-1] = v188;
    goto v92;
/* error exit handlers */
v191:
    popv(3);
    return nil;
}



/* Code for noncomperm */

static Lisp_Object CC_noncomperm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v181, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomperm");
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
    stack[-4] = v0;
/* end of prologue */
    v180 = stack[-4];
    if (v180 == nil) goto v141;
    v180 = stack[-4];
    stack[-5] = v180;
    goto v115;

v115:
    v180 = stack[-5];
    if (v180 == nil) goto v121;
    v180 = stack[-5];
    v180 = qcar(v180);
    stack[0] = v180;
    v181 = stack[0];
    v180 = stack[-4];
    fn = elt(env, 3); /* noncomdel */
    v180 = (*qfn2(fn))(qenv(fn), v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-6];
    v182 = v180;
    v181 = v182;
    v180 = elt(env, 2); /* failed */
    if (v181 == v180) goto v146;
    v180 = v182;
    v181 = CC_noncomperm(env, v180);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-6];
    v180 = stack[0];
    fn = elt(env, 4); /* mapcons */
    v180 = (*qfn2(fn))(qenv(fn), v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-6];
    goto v133;

v133:
    stack[-3] = v180;
    v180 = stack[-3];
    fn = elt(env, 5); /* lastpair */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-6];
    stack[-2] = v180;
    v180 = stack[-5];
    v180 = qcdr(v180);
    stack[-5] = v180;
    v180 = stack[-2];
    if (!consp(v180)) goto v115;
    else goto v114;

v114:
    v180 = stack[-5];
    if (v180 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v180 = stack[-5];
    v180 = qcar(v180);
    stack[0] = v180;
    v181 = stack[0];
    v180 = stack[-4];
    fn = elt(env, 3); /* noncomdel */
    v180 = (*qfn2(fn))(qenv(fn), v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-6];
    v182 = v180;
    v181 = v182;
    v180 = elt(env, 2); /* failed */
    if (v181 == v180) goto v65;
    v180 = v182;
    v181 = CC_noncomperm(env, v180);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-6];
    v180 = stack[0];
    fn = elt(env, 4); /* mapcons */
    v180 = (*qfn2(fn))(qenv(fn), v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-6];
    goto v177;

v177:
    v180 = Lrplacd(nil, stack[-1], v180);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-6];
    v180 = stack[-2];
    fn = elt(env, 5); /* lastpair */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-6];
    stack[-2] = v180;
    v180 = stack[-5];
    v180 = qcdr(v180);
    stack[-5] = v180;
    goto v114;

v65:
    v180 = qvalue(elt(env, 1)); /* nil */
    goto v177;

v146:
    v180 = qvalue(elt(env, 1)); /* nil */
    goto v133;

v121:
    v180 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v180); }

v141:
    v180 = stack[-4];
    popv(7);
    return ncons(v180);
/* error exit handlers */
v196:
    popv(7);
    return nil;
}



/* Code for rl_csimpl */

static Lisp_Object CC_rl_csimpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v116, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_csimpl");
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
    v90 = qvalue(elt(env, 1)); /* !*rlsimpl */
    if (v90 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v90 = elt(env, 2); /* rl_simpl */
    fn = elt(env, 4); /* getd */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    if (v90 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v142 = stack[0];
    v116 = qvalue(elt(env, 3)); /* nil */
    v90 = (Lisp_Object)-15; /* -1 */
    {
        popv(2);
        fn = elt(env, 2); /* rl_simpl */
        return (*qfnn(fn))(qenv(fn), 3, v142, v116, v90);
    }
/* error exit handlers */
v130:
    popv(2);
    return nil;
}



/* Code for ibalp_getvar!-zmom */

static Lisp_Object CC_ibalp_getvarKzmom(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getvar-zmom");
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
    v60 = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = nil;
    fn = elt(env, 2); /* ibalp_minclnr */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-6];
    stack[-5] = v60;
    v60 = (Lisp_Object)-15; /* -1 */
    stack[-3] = v60;
    v60 = stack[0];
    stack[-1] = v60;
    goto v115;

v115:
    v60 = stack[-1];
    if (v60 == nil) goto v143;
    v60 = stack[-1];
    v60 = qcar(v60);
    stack[0] = v60;
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcar(v60);
    if (v60 == nil) goto v199;
    v60 = qvalue(elt(env, 1)); /* nil */
    goto v77;

v77:
    if (v60 == nil) goto v135;
    v60 = stack[0];
    v59 = qcdr(v60);
    v60 = stack[-5];
    fn = elt(env, 3); /* ibalp_isinminclause */
    v60 = (*qfn2(fn))(qenv(fn), v59, v60);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-6];
    if (v60 == nil) goto v135;
    v60 = stack[0];
    v60 = qcdr(v60);
    stack[-4] = v60;
    v60 = stack[-2];
    stack[-3] = v60;
    goto v135;

v135:
    v60 = stack[-1];
    v60 = qcdr(v60);
    stack[-1] = v60;
    goto v115;

v199:
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v59 = qcar(v60);
    stack[-2] = v59;
    v60 = stack[-3];
    v60 = (Lisp_Object)greaterp2(v59, v60);
    nil = C_nil;
    if (exception_pending()) goto v198;
    v60 = v60 ? lisp_true : nil;
    env = stack[-6];
    goto v77;

v143:
    v60 = stack[-4];
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v59 = qcar(v60);
    v60 = stack[-4];
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcar(v60);
    v60 = (Lisp_Object)greaterp2(v59, v60);
    nil = C_nil;
    if (exception_pending()) goto v198;
    v60 = v60 ? lisp_true : nil;
    if (v60 == nil) goto v184;
    v60 = (Lisp_Object)17; /* 1 */
    goto v113;

v113:
    v59 = stack[-4];
    popv(7);
    return cons(v59, v60);

v184:
    v60 = (Lisp_Object)1; /* 0 */
    goto v113;
/* error exit handlers */
v198:
    popv(7);
    return nil;
}



/* Code for ratpoly_ratp */

static Lisp_Object CC_ratpoly_ratp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v127;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_ratp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v88 = v0;
/* end of prologue */
    v127 = v88;
    v127 = qcar(v127);
    v127 = (is_number(v127) ? lisp_true : nil);
    if (!(v127 == nil)) return onevalue(v127);
    v88 = qcar(v88);
    v88 = (v88 == nil ? lisp_true : nil);
    return onevalue(v88);
}



/* Code for matrixrowrd */

static Lisp_Object MS_CDECL CC_matrixrowrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixrowrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrowrd");
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
    v129 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    v73 = v129;
    v129 = v73;
    if (v129 == nil) goto v152;
    stack[0] = v73;
    v129 = CC_matrixrowrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v90;
    {
        Lisp_Object v116 = stack[0];
        popv(2);
        return cons(v116, v129);
    }

v152:
    v129 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v129); }
/* error exit handlers */
v90:
    popv(2);
    return nil;
}



/* Code for floatprop */

static Lisp_Object CC_floatprop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v115;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for floatprop");
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
    v151 = v0;
/* end of prologue */
    v115 = v151;
    v115 = Lfloatp(nil, v115);
    env = stack[0];
    if (!(v115 == nil)) { popv(1); return onevalue(v115); }
    v115 = elt(env, 1); /* !:rd!: */
        popv(1);
        return Leqcar(nil, v151, v115);
}



/* Code for noncommuting */

static Lisp_Object CC_noncommuting(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v154, v177, v139;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncommuting");
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
    v154 = v1;
    v177 = v0;
/* end of prologue */
    v139 = nil;
    v138 = v177;
    if (!consp(v138)) goto v78;
    v138 = v177;
    v138 = qcar(v138);
    goto v152;

v152:
    v177 = v138;
    v138 = v154;
    if (!consp(v138)) goto v134;
    v138 = v154;
    v138 = qcar(v138);
    goto v124;

v124:
    v154 = v138;
    v138 = v177;
    if (!consp(v138)) goto v137;
    v138 = v177;
    v138 = qcar(v138);
    if (!symbolp(v138)) v138 = nil;
    else { v138 = qfastgets(v138);
           if (v138 != nil) { v138 = elt(v138, 0); /* noncom */
#ifdef RECORD_GET
             if (v138 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v138 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v138 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v138 == SPID_NOPROP) v138 = nil; else v138 = lisp_true; }}
#endif
    goto v76;

v76:
    if (v138 == nil) return onevalue(v139);
    v138 = v154;
    if (!consp(v138)) goto v120;
    v138 = v154;
    v138 = qcar(v138);
    if (!symbolp(v138)) v138 = nil;
    else { v138 = qfastgets(v138);
           if (v138 != nil) { v138 = elt(v138, 0); /* noncom */
#ifdef RECORD_GET
             if (v138 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v138 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v138 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v138 == SPID_NOPROP) v138 = nil; else v138 = lisp_true; }}
#endif
    goto v118;

v118:
    if (v138 == nil) return onevalue(v139);
    v138 = elt(env, 2); /* noncommutes */
    v138 = get(v177, v138);
    v138 = Lmember(nil, v154, v138);
    v139 = v138;
    return onevalue(v139);

v120:
    v138 = v154;
    if (!symbolp(v138)) v138 = nil;
    else { v138 = qfastgets(v138);
           if (v138 != nil) { v138 = elt(v138, 0); /* noncom */
#ifdef RECORD_GET
             if (v138 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v138 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v138 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v138 == SPID_NOPROP) v138 = nil; else v138 = lisp_true; }}
#endif
    goto v118;

v137:
    v138 = v177;
    if (!symbolp(v138)) v138 = nil;
    else { v138 = qfastgets(v138);
           if (v138 != nil) { v138 = elt(v138, 0); /* noncom */
#ifdef RECORD_GET
             if (v138 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v138 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v138 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v138 == SPID_NOPROP) v138 = nil; else v138 = lisp_true; }}
#endif
    goto v76;

v134:
    v138 = v154;
    goto v124;

v78:
    v138 = v177;
    goto v152;
}



/* Code for one!-entry!-listp */

static Lisp_Object CC_oneKentryKlistp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for one-entry-listp");
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

v87:
    v123 = stack[-1];
    if (v123 == nil) goto v34;
    v123 = stack[-1];
    v132 = qcar(v123);
    v123 = stack[0];
    fn = elt(env, 3); /* one!-entryp */
    v123 = (*qfn2(fn))(qenv(fn), v132, v123);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-2];
    if (v123 == nil) goto v128;
    v123 = stack[-1];
    v132 = qcdr(v123);
    v123 = stack[0];
    stack[-1] = v132;
    stack[0] = v123;
    goto v87;

v128:
    v123 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v123); }

v34:
    v123 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v123); }
/* error exit handlers */
v199:
    popv(3);
    return nil;
}



/* Code for dp!=mocompare */

static Lisp_Object CC_dpMmocompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=mocompare");
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
    v157 = v1;
    v121 = v0;
/* end of prologue */
    v121 = qcar(v121);
    v157 = qcar(v157);
    fn = elt(env, 1); /* mo_compare */
    v121 = (*qfn2(fn))(qenv(fn), v121, v157);
    errexit();
    v157 = (Lisp_Object)17; /* 1 */
        return Leqn(nil, v121, v157);
}



/* Code for pv_intequiv */

static Lisp_Object CC_pv_intequiv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v156;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_intequiv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v156 = v0;
/* end of prologue */
    v128 = v156;
    v128 = qcdr(v128);
    if (!consp(v128)) goto v141;
    v128 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v128);

v141:
    v128 = v156;
    v128 = qcdr(v128);
    return onevalue(v128);
}



/* Code for st_sorttree */

static Lisp_Object MS_CDECL CC_st_sorttree(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v114, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_sorttree");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v115 = v2;
    v114 = v1;
    v124 = v0;
/* end of prologue */
    fn = elt(env, 1); /* st_sorttree1 */
    v115 = (*qfnn(fn))(qenv(fn), 3, v124, v114, v115);
    errexit();
    v115 = qcdr(v115);
    return onevalue(v115);
}



/* Code for degree!-in!-variable */

static Lisp_Object CC_degreeKinKvariable(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v201;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degree-in-variable");
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
    v69 = stack[-1];
    if (!consp(v69)) goto v78;
    v69 = stack[-1];
    v69 = qcar(v69);
    v69 = (consp(v69) ? nil : lisp_true);
    goto v152;

v152:
    if (v69 == nil) goto v121;
    v69 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v69); }

v121:
    v69 = stack[-1];
    v69 = qcar(v69);
    v201 = qcdr(v69);
    v69 = (Lisp_Object)1; /* 0 */
    if (v201 == v69) goto v134;
    v201 = stack[0];
    v69 = stack[-1];
    v69 = qcar(v69);
    v69 = qcar(v69);
    v69 = qcar(v69);
    if (equal(v201, v69)) goto v77;
    v69 = stack[-1];
    v69 = qcar(v69);
    v201 = qcdr(v69);
    v69 = stack[0];
    stack[-2] = CC_degreeKinKvariable(env, v201, v69);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v69 = stack[-1];
    v201 = qcdr(v69);
    v69 = stack[0];
    v69 = CC_degreeKinKvariable(env, v201, v69);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    {
        Lisp_Object v155 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* max */
        return (*qfn2(fn))(qenv(fn), v155, v69);
    }

v77:
    v69 = stack[-1];
    v69 = qcar(v69);
    v69 = qcar(v69);
    v69 = qcdr(v69);
    { popv(4); return onevalue(v69); }

v134:
    v69 = elt(env, 2); /* "Polynomial with a zero coefficient found" */
    {
        popv(4);
        fn = elt(env, 4); /* errorf */
        return (*qfn1(fn))(qenv(fn), v69);
    }

v78:
    v69 = qvalue(elt(env, 1)); /* t */
    goto v152;
/* error exit handlers */
v139:
    popv(4);
    return nil;
}



/* Code for lto_almerge */

static Lisp_Object CC_lto_almerge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v181, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_almerge");
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
    v180 = v0;
/* end of prologue */

v87:
    v181 = v180;
    if (v181 == nil) goto v78;
    v181 = v180;
    v181 = qcdr(v181);
    if (v181 == nil) goto v151;
    v181 = v180;
    v181 = qcdr(v181);
    v181 = qcdr(v181);
    if (v181 == nil) goto v73;
    v181 = v180;
    stack[0] = qcar(v181);
    v181 = qcdr(v180);
    v180 = stack[-3];
    v180 = CC_lto_almerge(env, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    v180 = list2(stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    v181 = stack[-3];
    stack[-3] = v181;
    goto v87;

v73:
    v181 = v180;
    v181 = qcdr(v181);
    v181 = qcar(v181);
    stack[-4] = v181;
    v180 = qcar(v180);
    stack[-2] = v180;
    goto v137;

v137:
    v180 = stack[-2];
    if (v180 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v180 = stack[-2];
    v180 = qcar(v180);
    v181 = v180;
    v180 = v181;
    v182 = qcar(v180);
    v180 = stack[-4];
    v180 = Lassoc(nil, v182, v180);
    v182 = v180;
    v180 = v182;
    if (v180 == nil) goto v202;
    stack[-1] = v182;
    stack[0] = stack[-3];
    v180 = v181;
    v180 = qcdr(v180);
    v181 = v182;
    v181 = qcdr(v181);
    v180 = list2(v180, v181);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    fn = elt(env, 2); /* apply */
    v180 = (*qfn2(fn))(qenv(fn), stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v180 = (*qfn2(fn))(qenv(fn), stack[-1], v180);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    goto v117;

v117:
    v180 = stack[-2];
    v180 = qcdr(v180);
    stack[-2] = v180;
    goto v137;

v202:
    v180 = stack[-4];
    v180 = cons(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    stack[-4] = v180;
    goto v117;

v151:
    v180 = qcar(v180);
    { popv(6); return onevalue(v180); }

v78:
    v180 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v180); }
/* error exit handlers */
v166:
    popv(6);
    return nil;
}



/* Code for updtemplate */

static Lisp_Object MS_CDECL CC_updtemplate(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v59, v204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "updtemplate");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for updtemplate");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v2;
    v60 = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-4] = v60;
    v60 = stack[-4];
    if (v60 == nil) goto v114;
    v60 = stack[-4];
    v60 = qcar(v60);
    stack[0] = v60;
    v59 = stack[-6];
    v60 = stack[0];
    v59 = Lsubla(nil, v59, v60);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-8];
    stack[-7] = v59;
    v60 = stack[0];
    if (equal(v59, v60)) goto v142;
    v59 = stack[-7];
    v60 = stack[-5];
    fn = elt(env, 2); /* reval!-without */
    v59 = (*qfn2(fn))(qenv(fn), v59, v60);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-8];
    v204 = v59;
    v60 = stack[-7];
    if (equal(v59, v60)) goto v63;
    v60 = v204;
    goto v116;

v116:
    v60 = ncons(v60);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-8];
    stack[-2] = v60;
    stack[-3] = v60;
    goto v128;

v128:
    v60 = stack[-4];
    v60 = qcdr(v60);
    stack[-4] = v60;
    v60 = stack[-4];
    if (v60 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v60 = stack[-4];
    v60 = qcar(v60);
    stack[0] = v60;
    v59 = stack[-6];
    v60 = stack[0];
    v59 = Lsubla(nil, v59, v60);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-8];
    stack[-7] = v59;
    v60 = stack[0];
    if (equal(v59, v60)) goto v68;
    v59 = stack[-7];
    v60 = stack[-5];
    fn = elt(env, 2); /* reval!-without */
    v59 = (*qfn2(fn))(qenv(fn), v59, v60);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-8];
    v204 = v59;
    v60 = stack[-7];
    if (equal(v59, v60)) goto v164;
    v60 = v204;
    goto v67;

v67:
    v60 = ncons(v60);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-8];
    v60 = Lrplacd(nil, stack[-1], v60);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-8];
    v60 = stack[-2];
    v60 = qcdr(v60);
    stack[-2] = v60;
    goto v128;

v164:
    v60 = stack[-7];
    goto v67;

v68:
    v60 = stack[0];
    goto v67;

v63:
    v60 = stack[-7];
    goto v116;

v142:
    v60 = stack[0];
    goto v116;

v114:
    v60 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v60); }
/* error exit handlers */
v58:
    popv(9);
    return nil;
}



/* Code for qqe_ofsf_chsimpterm */

static Lisp_Object CC_qqe_ofsf_chsimpterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_chsimpterm");
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
    v192 = v0;
/* end of prologue */
    v169 = v192;
    if (!consp(v169)) { popv(3); return onevalue(v192); }
    v169 = v192;
    v169 = qcdr(v169);
    stack[-1] = v169;
    goto v114;

v114:
    v169 = stack[-1];
    if (v169 == nil) goto v14;
    v169 = stack[-1];
    v169 = qcar(v169);
    v169 = Lconsp(nil, v169);
    env = stack[-2];
    if (v169 == nil) goto v142;
    v169 = stack[-1];
    v169 = qcar(v169);
    fn = elt(env, 4); /* qqe_op */
    v192 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-2];
    v169 = elt(env, 2); /* expt */
    if (v192 == v169) goto v122;
    v169 = qvalue(elt(env, 1)); /* nil */
    goto v137;

v137:
    if (v169 == nil) goto v142;
    stack[0] = stack[-1];
    v169 = stack[-1];
    v169 = qcar(v169);
    fn = elt(env, 5); /* qqe_chsimpterm */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-2];
    fn = elt(env, 6); /* setcar */
    v169 = (*qfn2(fn))(qenv(fn), stack[0], v169);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-2];
    goto v90;

v90:
    v169 = stack[-1];
    v169 = qcdr(v169);
    stack[-1] = v169;
    goto v114;

v142:
    v169 = stack[-1];
    v169 = qcar(v169);
    v169 = Lconsp(nil, v169);
    env = stack[-2];
    if (v169 == nil) goto v90;
    v169 = stack[-1];
    v169 = qcar(v169);
    v169 = CC_qqe_ofsf_chsimpterm(env, v169);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-2];
    goto v90;

v122:
    v169 = stack[-1];
    v169 = qcar(v169);
    fn = elt(env, 7); /* qqe_arg2l */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-2];
    v169 = Lconsp(nil, v169);
    env = stack[-2];
    if (v169 == nil) goto v148;
    v169 = stack[-1];
    v169 = qcar(v169);
    fn = elt(env, 7); /* qqe_arg2l */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-2];
    fn = elt(env, 4); /* qqe_op */
    v192 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-2];
    v169 = elt(env, 3); /* (ltail rtail) */
    v169 = Lmemq(nil, v192, v169);
    goto v137;

v148:
    v169 = qvalue(elt(env, 1)); /* nil */
    goto v137;

v14:
    v169 = nil;
    { popv(3); return onevalue(v169); }
/* error exit handlers */
v188:
    popv(3);
    return nil;
}



/* Code for pasf_smwmkatl */

static Lisp_Object MS_CDECL CC_pasf_smwmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v178, v74, v75, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smwmkatl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v178 = v3;
    v74 = v2;
    v75 = v1;
    v147 = v0;
/* end of prologue */
    v199 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v199 == nil) goto v142;
    v199 = v147;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v199, v75, v74, v178);
    }

v142:
    v199 = v147;
    {
        fn = elt(env, 3); /* cl_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v199, v75, v74, v178);
    }
}



/* Code for rl_simpbop */

static Lisp_Object CC_rl_simpbop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpbop");
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
    v186 = v0;
/* end of prologue */
    v185 = v186;
    stack[-4] = qcar(v185);
    v185 = v186;
    v185 = qcdr(v185);
    stack[-3] = v185;
    v185 = stack[-3];
    if (v185 == nil) goto v157;
    v185 = stack[-3];
    v185 = qcar(v185);
    fn = elt(env, 2); /* rl_simp1 */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    stack[-1] = v185;
    stack[-2] = v185;
    goto v151;

v151:
    v185 = stack[-3];
    v185 = qcdr(v185);
    stack[-3] = v185;
    v185 = stack[-3];
    if (v185 == nil) goto v137;
    stack[0] = stack[-1];
    v185 = stack[-3];
    v185 = qcar(v185);
    fn = elt(env, 2); /* rl_simp1 */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v185 = Lrplacd(nil, stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v185 = stack[-1];
    v185 = qcdr(v185);
    stack[-1] = v185;
    goto v151;

v137:
    v185 = stack[-2];
    goto v14;

v14:
    {
        Lisp_Object v63 = stack[-4];
        popv(6);
        return cons(v63, v185);
    }

v157:
    v185 = qvalue(elt(env, 1)); /* nil */
    goto v14;
/* error exit handlers */
v126:
    popv(6);
    return nil;
}



/* Code for cird */

static Lisp_Object MS_CDECL CC_cird(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v54, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cird");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cird");
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
    v54 = qvalue(elt(env, 2)); /* atts */
    v117 = elt(env, 3); /* (type) */
    fn = elt(env, 6); /* retattributes */
    v117 = (*qfn2(fn))(qenv(fn), v54, v117);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    stack[0] = v117;
    fn = elt(env, 7); /* lex */
    v117 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    v117 = qvalue(elt(env, 4)); /* char */
    stack[-1] = v117;
    fn = elt(env, 7); /* lex */
    v117 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    v117 = stack[-1];
    v117 = Lcompress(nil, v117);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    v54 = v117;
    v117 = v54;
    if (!(is_number(v117))) goto v90;
    v117 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 8); /* errorml */
    v117 = (*qfn2(fn))(qenv(fn), v54, v117);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    goto v90;

v90:
    v117 = stack[-1];
    fn = elt(env, 9); /* compress!* */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    v54 = v117;
    v117 = stack[0];
    if (v117 == nil) { popv(3); return onevalue(v54); }
    v98 = elt(env, 5); /* ci */
    v117 = stack[0];
    popv(3);
    return list3(v98, v117, v54);
/* error exit handlers */
v63:
    popv(3);
    return nil;
}



/* Code for guesspftype */

static Lisp_Object CC_guesspftype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v72, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for guesspftype");
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
    v150 = stack[0];
    if (!consp(v150)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v150 = stack[0];
    v72 = qcar(v150);
    v150 = elt(env, 1); /* (wedge d partdf hodge innerprod liedf) */
    v150 = Lmemq(nil, v72, v150);
    if (!(v150 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v150 = stack[0];
    v150 = qcdr(v150);
    v71 = Llength(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-1];
    v150 = stack[0];
    v72 = qcar(v150);
    v150 = elt(env, 2); /* ifdegree */
    v150 = get(v72, v150);
    env = stack[-1];
    v150 = Lassoc(nil, v71, v150);
    if (v150 == nil) goto v118;
    v150 = stack[0];
    v150 = qcdr(v150);
    fn = elt(env, 3); /* xvarlistp */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-1];
    if (v150 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else goto v118;

v118:
    v150 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* mknwedge */
        return (*qfn1(fn))(qenv(fn), v150);
    }
/* error exit handlers */
v186:
    popv(2);
    return nil;
}



/* Code for equalreplaceby */

static Lisp_Object CC_equalreplaceby(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v88;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equalreplaceby");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v89 = v0;
/* end of prologue */
    v88 = elt(env, 1); /* replaceby */
    return cons(v88, v89);
}



/* Code for inttovec */

static Lisp_Object CC_inttovec(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec");
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
    v134 = v1;
    v124 = v0;
/* end of prologue */
    stack[0] = v134;
    fn = elt(env, 1); /* inttovec!-solve */
    v124 = (*qfn2(fn))(qenv(fn), v134, v124);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    {
        Lisp_Object v129 = stack[0];
        popv(2);
        fn = elt(env, 2); /* inttovec1 */
        return (*qfn2(fn))(qenv(fn), v129, v124);
    }
/* error exit handlers */
v121:
    popv(2);
    return nil;
}



/* Code for assert_uninstall_all */

static Lisp_Object MS_CDECL CC_assert_uninstall_all(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_uninstall_all");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_uninstall_all");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v152 = qvalue(elt(env, 1)); /* !*assert */
    if (v152 == nil) goto v141;
    v152 = qvalue(elt(env, 2)); /* assert_functionl!* */
    {
        fn = elt(env, 3); /* assert_uninstall */
        return (*qfn1(fn))(qenv(fn), v152);
    }

v141:
    v152 = nil;
    return onevalue(v152);
}



/* Code for eqdummy */

static Lisp_Object CC_eqdummy(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v123, v132;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eqdummy");
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
    v122 = v1;
    v132 = v0;
/* end of prologue */
    v123 = v132;
    if (v123 == nil) goto v34;
    v123 = elt(env, 2); /* dummy */
    v123 = get(v132, v123);
    env = stack[0];
    v132 = qcar(v123);
    v123 = v122;
    v122 = elt(env, 2); /* dummy */
    v122 = get(v123, v122);
    v122 = qcar(v122);
    v122 = (v132 == v122 ? lisp_true : nil);
    { popv(1); return onevalue(v122); }

v34:
    v122 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v122); }
}



/* Code for numlist_ordp */

static Lisp_Object CC_numlist_ordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v151, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numlist_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v156 = v1;
    v151 = v0;
/* end of prologue */
    v115 = v151;
    v151 = v156;
    v156 = elt(env, 1); /* lambda_lqgavx_2 */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v115, v151, v156);
    }
}



/* Code for lambda_lqgavx_2 */

static Lisp_Object CC_lambda_lqgavx_2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v127;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqgavx_2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v88 = v1;
    v127 = v0;
/* end of prologue */
        return Lleq(nil, v127, v88);
}



/* Code for extmult */

static Lisp_Object CC_extmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extmult");
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
    v158 = stack[-3];
    if (v158 == nil) goto v78;
    v158 = stack[-2];
    v158 = (v158 == nil ? lisp_true : nil);
    goto v152;

v152:
    if (v158 == nil) goto v121;
    v158 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v158); }

v121:
    v158 = stack[-3];
    v158 = qcar(v158);
    v158 = qcar(v158);
    v53 = qcar(v158);
    v158 = stack[-2];
    v158 = qcar(v158);
    v158 = qcar(v158);
    fn = elt(env, 3); /* ordexn */
    v158 = (*qfn2(fn))(qenv(fn), v53, v158);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    v53 = v158;
    v158 = v53;
    if (v158 == nil) goto v113;
    v158 = v53;
    stack[-4] = qcdr(v158);
    v158 = v53;
    v158 = qcar(v158);
    if (v158 == nil) goto v208;
    v158 = stack[-3];
    v158 = qcar(v158);
    v53 = qcdr(v158);
    v158 = stack[-2];
    v158 = qcar(v158);
    v158 = qcdr(v158);
    fn = elt(env, 4); /* c!:subs2multf */
    v158 = (*qfn2(fn))(qenv(fn), v53, v158);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    fn = elt(env, 5); /* negf */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    stack[-1] = v158;
    goto v202;

v202:
    v158 = stack[-3];
    v158 = qcar(v158);
    v53 = ncons(v158);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    v158 = stack[-2];
    v158 = qcdr(v158);
    stack[0] = CC_extmult(env, v53, v158);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    v158 = stack[-3];
    v53 = qcdr(v158);
    v158 = stack[-2];
    v158 = CC_extmult(env, v53, v158);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    fn = elt(env, 6); /* extadd */
    v158 = (*qfn2(fn))(qenv(fn), stack[0], v158);
    nil = C_nil;
    if (exception_pending()) goto v172;
    {
        Lisp_Object v209 = stack[-4];
        Lisp_Object v210 = stack[-1];
        popv(6);
        return acons(v209, v210, v158);
    }

v208:
    v158 = stack[-3];
    v158 = qcar(v158);
    v53 = qcdr(v158);
    v158 = stack[-2];
    v158 = qcar(v158);
    v158 = qcdr(v158);
    fn = elt(env, 4); /* c!:subs2multf */
    v158 = (*qfn2(fn))(qenv(fn), v53, v158);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    stack[-1] = v158;
    goto v202;

v113:
    v158 = stack[-3];
    v53 = qcdr(v158);
    v158 = stack[-2];
    stack[0] = CC_extmult(env, v53, v158);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    v158 = stack[-3];
    v158 = qcar(v158);
    v53 = ncons(v158);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    v158 = stack[-2];
    v158 = qcdr(v158);
    v158 = CC_extmult(env, v53, v158);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-5];
    {
        Lisp_Object v211 = stack[0];
        popv(6);
        fn = elt(env, 6); /* extadd */
        return (*qfn2(fn))(qenv(fn), v211, v158);
    }

v78:
    v158 = qvalue(elt(env, 1)); /* t */
    goto v152;
/* error exit handlers */
v172:
    popv(6);
    return nil;
}



/* Code for simp!*sq */

static Lisp_Object CC_simpHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v157 = v0;
/* end of prologue */
    v134 = v157;
    v134 = qcdr(v134);
    v134 = qcar(v134);
    if (v134 == nil) goto v156;
    v134 = qvalue(elt(env, 1)); /* !*resimp */
    if (!(v134 == nil)) goto v156;
    v134 = v157;
    v134 = qcar(v134);
    return onevalue(v134);

v156:
    v134 = v157;
    v134 = qcar(v134);
    {
        fn = elt(env, 2); /* resimp1 */
        return (*qfn1(fn))(qenv(fn), v134);
    }
}



/* Code for mkzl */

static Lisp_Object CC_mkzl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkzl");
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
    goto v89;

v89:
    v77 = stack[0];
    v131 = (Lisp_Object)17; /* 1 */
    if (v77 == v131) goto v152;
    v77 = (Lisp_Object)1; /* 0 */
    v131 = stack[-1];
    v131 = cons(v77, v131);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    stack[-1] = v131;
    v131 = stack[0];
    v131 = sub1(v131);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    stack[0] = v131;
    goto v89;

v152:
    v131 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v131);
    }
/* error exit handlers */
v122:
    popv(3);
    return nil;
}



/* Code for ibalp_clausep */

static Lisp_Object CC_ibalp_clausep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clausep");
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
    v76 = stack[0];
    fn = elt(env, 3); /* ibalp_litp */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-1];
    if (!(v76 == nil)) { popv(2); return onevalue(v76); }
    v76 = stack[0];
    if (!consp(v76)) goto v124;
    v76 = stack[0];
    v76 = qcar(v76);
    v137 = v76;
    goto v128;

v128:
    v76 = elt(env, 1); /* or */
    if (v137 == v76) goto v78;
    v76 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v76); }

v78:
    v76 = stack[0];
    v76 = qcdr(v76);
    {
        popv(2);
        fn = elt(env, 4); /* ibalp_litlp */
        return (*qfn1(fn))(qenv(fn), v76);
    }

v124:
    v76 = stack[0];
    v137 = v76;
    goto v128;
/* error exit handlers */
v123:
    popv(2);
    return nil;
}



/* Code for aex_mvaroccurtest */

static Lisp_Object CC_aex_mvaroccurtest(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mvaroccurtest");
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
    stack[0] = v1;
    v127 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v128 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-1];
    v127 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_mvartest */
        return (*qfn2(fn))(qenv(fn), v128, v127);
    }
/* error exit handlers */
v151:
    popv(2);
    return nil;
}



/* Code for ofsf_sacatlp */

static Lisp_Object CC_ofsf_sacatlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v133, v146, v199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacatlp");
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
    v132 = v1;
    v199 = v0;
/* end of prologue */
    v132 = qcar(v132);
    v146 = v132;
    v132 = v199;
    v132 = qcdr(v132);
    v133 = qcar(v132);
    v132 = v146;
    v132 = qcdr(v132);
    v132 = qcar(v132);
    if (equal(v133, v132)) goto v76;
    v132 = v199;
    v132 = qcdr(v132);
    v132 = qcar(v132);
    v133 = v146;
    v133 = qcdr(v133);
    v133 = qcar(v133);
    fn = elt(env, 2); /* ordp */
    v132 = (*qfn2(fn))(qenv(fn), v132, v133);
    errexit();
    goto v153;

v153:
    v132 = (v132 == nil ? lisp_true : nil);
    return onevalue(v132);

v76:
    v132 = qvalue(elt(env, 1)); /* nil */
    goto v153;
}



/* Code for cr!:prep */

static Lisp_Object CC_crTprep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:prep");
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
    v77 = elt(env, 1); /* !:rd!: */
    v131 = stack[0];
    v131 = qcdr(v131);
    v131 = qcar(v131);
    v131 = cons(v77, v131);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v77 = elt(env, 1); /* !:rd!: */
    v131 = stack[0];
    v131 = qcdr(v131);
    v131 = qcdr(v131);
    v131 = cons(v77, v131);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v131 = cons(stack[-1], v131);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* crprep1 */
        return (*qfn1(fn))(qenv(fn), v131);
    }
/* error exit handlers */
v122:
    popv(3);
    return nil;
}



/* Code for initwght */

static Lisp_Object CC_initwght(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v216, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initwght");
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
    stack[-3] = v0;
/* end of prologue */
    v215 = (Lisp_Object)1; /* 0 */
    stack[-5] = v215;
    stack[0] = v215;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v216 = qvalue(elt(env, 2)); /* maxvar */
    v215 = stack[-3];
    v215 = plus2(v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-6];
    v216 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v215/(16/CELL)));
    v215 = (Lisp_Object)65; /* 4 */
    v215 = *(Lisp_Object *)((char *)v216 + (CELL-TAG_VECTOR) + ((int32_t)v215/(16/CELL)));
    stack[-4] = v215;
    goto v89;

v89:
    v215 = stack[-4];
    if (v215 == nil) goto v194;
    v215 = stack[-4];
    v215 = qcar(v215);
    stack[-2] = v215;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v216 = qvalue(elt(env, 2)); /* maxvar */
    v215 = stack[-2];
    v215 = qcar(v215);
    v215 = plus2(v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-6];
    v216 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v215/(16/CELL)));
    v215 = (Lisp_Object)1; /* 0 */
    v215 = *(Lisp_Object *)((char *)v216 + (CELL-TAG_VECTOR) + ((int32_t)v215/(16/CELL)));
    if (v215 == nil) goto v75;
    v215 = stack[-2];
    v215 = qcdr(v215);
    v215 = qcar(v215);
    fn = elt(env, 5); /* dm!-abs */
    v215 = (*qfn1(fn))(qenv(fn), v215);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-6];
    v217 = v215;
    v215 = v217;
    if (!consp(v215)) goto v139;
    v215 = v217;
    v216 = qcar(v215);
    v215 = elt(env, 4); /* onep */
    v215 = get(v216, v215);
    env = stack[-6];
    v216 = v217;
    v215 = Lapply1(nil, v215, v216);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-6];
    goto v177;

v177:
    if (!(v215 == nil)) goto v140;
    v215 = stack[-5];
    v215 = add1(v215);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-6];
    stack[-5] = v215;
    goto v140;

v140:
    v215 = stack[0];
    v215 = add1(v215);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-6];
    stack[0] = v215;
    goto v75;

v75:
    v215 = stack[-4];
    v215 = qcdr(v215);
    stack[-4] = v215;
    goto v89;

v139:
    v215 = v217;
    v215 = Lonep(nil, v215);
    env = stack[-6];
    goto v177;

v194:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v216 = qvalue(elt(env, 2)); /* maxvar */
    v215 = stack[-3];
    v215 = plus2(v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-6];
    stack[-4] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v215/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[-2] = stack[0];
    stack[-1] = stack[-5];
    v216 = (Lisp_Object)49; /* 3 */
    v215 = stack[-5];
    v215 = times2(v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-6];
    v215 = plus2(stack[0], v215);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-6];
    v215 = acons(stack[-2], stack[-1], v215);
    nil = C_nil;
    if (exception_pending()) goto v218;
    *(Lisp_Object *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v215;
    v215 = nil;
    { popv(7); return onevalue(v215); }
/* error exit handlers */
v218:
    popv(7);
    return nil;
}



/* Code for bcplus!? */

static Lisp_Object CC_bcplusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v129;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcplus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v121 = v0;
/* end of prologue */
    v121 = qcar(v121);
    v129 = v121;
    v121 = v129;
    if (is_number(v121)) goto v115;
    v121 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v121);

v115:
    v121 = (Lisp_Object)1; /* 0 */
        return Lgreaterp(nil, v129, v121);
}



/* Code for vevmaptozero1 */

static Lisp_Object CC_vevmaptozero1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v90;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevmaptozero1");
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
    v91 = v1;
    stack[0] = v0;
/* end of prologue */

v34:
    v90 = stack[0];
    if (v90 == nil) { popv(2); return onevalue(v91); }
    v90 = stack[0];
    v90 = qcdr(v90);
    stack[0] = v90;
    v90 = (Lisp_Object)1; /* 0 */
    v91 = cons(v90, v91);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    goto v34;
/* error exit handlers */
v142:
    popv(2);
    return nil;
}



/* Code for physopaeval */

static Lisp_Object CC_physopaeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v219, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopaeval");
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
    v198 = stack[0];
    fn = elt(env, 7); /* physopp */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-1];
    if (v198 == nil) goto v152;
    v219 = stack[0];
    v198 = elt(env, 1); /* rvalue */
    v198 = get(v219, v198);
    env = stack[-1];
    v57 = v198;
    if (v198 == nil) goto v156;
    v198 = v57;
    v219 = qcar(v198);
    v198 = elt(env, 2); /* !*sq */
    if (!(v219 == v198)) { popv(2); return onevalue(v57); }
    v198 = qvalue(elt(env, 3)); /* !*nosq */
    if (v198 == nil) goto v132;
    v198 = v57;
    v198 = qcdr(v198);
    v198 = qcar(v198);
    {
        popv(2);
        fn = elt(env, 8); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v198);
    }

v132:
    v198 = v57;
    v198 = qcdr(v198);
    v198 = qcar(v198);
    {
        popv(2);
        fn = elt(env, 9); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v198);
    }

v156:
    v198 = stack[0];
    if (!consp(v198)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v198 = stack[0];
    v219 = qcar(v198);
    v198 = elt(env, 4); /* psimpfn */
    v198 = get(v219, v198);
    env = stack[-1];
    v57 = v198;
    if (v198 == nil) goto v139;
    v219 = v57;
    v198 = stack[0];
        popv(2);
        return Lapply1(nil, v219, v198);

v139:
    v198 = stack[0];
    v219 = qcar(v198);
    v198 = elt(env, 5); /* opmtch */
    v198 = get(v219, v198);
    env = stack[-1];
    if (v198 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v198 = stack[0];
    fn = elt(env, 10); /* opmtch!* */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v158;
    v57 = v198;
    if (v198 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v57); }

v152:
    v198 = stack[0];
    if (!consp(v198)) goto v61;
    v198 = stack[0];
    v219 = qcar(v198);
    v198 = elt(env, 2); /* !*sq */
    v198 = (v219 == v198 ? lisp_true : nil);
    goto v189;

v189:
    if (v198 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v198 = qvalue(elt(env, 3)); /* !*nosq */
    if (v198 == nil) goto v194;
    v198 = stack[0];
    v198 = qcdr(v198);
    v198 = qcar(v198);
    {
        popv(2);
        fn = elt(env, 8); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v198);
    }

v194:
    v198 = stack[0];
    v198 = qcdr(v198);
    v198 = qcar(v198);
    {
        popv(2);
        fn = elt(env, 9); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v198);
    }

v61:
    v198 = qvalue(elt(env, 6)); /* nil */
    goto v189;
/* error exit handlers */
v158:
    popv(2);
    return nil;
}



/* Code for zero!-roads */

static Lisp_Object CC_zeroKroads(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zero-roads");
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

v87:
    v137 = stack[0];
    if (v137 == nil) goto v141;
    v137 = stack[0];
    v137 = qcar(v137);
    fn = elt(env, 2); /* z!-roads */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-2];
    v122 = v137;
    v137 = v122;
    if (v137 == nil) goto v130;
    stack[-1] = v122;
    v137 = stack[0];
    v137 = qcdr(v137);
    v137 = CC_zeroKroads(env, v137);
    nil = C_nil;
    if (exception_pending()) goto v133;
    {
        Lisp_Object v146 = stack[-1];
        popv(3);
        return cons(v146, v137);
    }

v130:
    v137 = stack[0];
    v137 = qcdr(v137);
    stack[0] = v137;
    goto v87;

v141:
    v137 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v137); }
/* error exit handlers */
v133:
    popv(3);
    return nil;
}



/* Code for assert_install */

static Lisp_Object CC_assert_install(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_install");
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
    v116 = v0;
/* end of prologue */
    v90 = qvalue(elt(env, 1)); /* !*assert */
    if (v90 == nil) goto v34;
    v90 = v116;
    stack[0] = v90;
    goto v89;

v89:
    v90 = stack[0];
    if (v90 == nil) goto v156;
    v90 = stack[0];
    v90 = qcar(v90);
    fn = elt(env, 3); /* assert_install1 */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-1];
    v90 = stack[0];
    v90 = qcdr(v90);
    stack[0] = v90;
    goto v89;

v156:
    v90 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v90); }

v34:
    v90 = nil;
    { popv(2); return onevalue(v90); }
/* error exit handlers */
v135:
    popv(2);
    return nil;
}



/* Code for mo!=revlexcomp */

static Lisp_Object CC_moMrevlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=revlexcomp");
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
    stack[-2] = Llength(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    v74 = stack[0];
    v74 = Llength(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v74))) goto v34;
    v74 = stack[0];
    stack[-2] = Llength(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    v74 = stack[-1];
    v74 = Llength(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v74))) goto v114;
    v74 = stack[-1];
    stack[-1] = Lreverse(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    v74 = stack[0];
    v74 = Lreverse(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    fn = elt(env, 1); /* mo!=degcomp */
    v74 = (*qfn2(fn))(qenv(fn), stack[-1], v74);
    nil = C_nil;
    if (exception_pending()) goto v118;
    popv(4);
    return negate(v74);

v114:
    v74 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v74); }

v34:
    v74 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v74); }
/* error exit handlers */
v118:
    popv(4);
    return nil;
}



/* Code for dv_cambhead */

static Lisp_Object CC_dv_cambhead(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_cambhead");
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

v87:
    v75 = stack[0];
    fn = elt(env, 4); /* listp */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    if (v75 == nil) goto v34;
    v75 = stack[0];
    stack[-1] = qcar(v75);
    v147 = elt(env, 1); /* expt */
    v75 = elt(env, 2); /* minus */
    v75 = list2(v147, v75);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    v75 = Lmember(nil, stack[-1], v75);
    if (v75 == nil) goto v88;
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = qcar(v75);
    stack[0] = v75;
    goto v87;

v88:
    v75 = stack[0];
    fn = elt(env, 4); /* listp */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v120;
    if (v75 == nil) goto v34;
    v75 = stack[0];
    v75 = qcar(v75);
    { popv(3); return onevalue(v75); }

v34:
    v75 = nil;
    { popv(3); return onevalue(v75); }
/* error exit handlers */
v120:
    popv(3);
    return nil;
}



/* Code for expt!-mod!-p */

static Lisp_Object CC_exptKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v154, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expt-mod-p");
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
    v177 = v1;
    stack[0] = v0;
/* end of prologue */
    v154 = v177;
    v138 = (Lisp_Object)1; /* 0 */
    if (v154 == v138) goto v34;
    v154 = v177;
    v138 = (Lisp_Object)17; /* 1 */
    if (v154 == v138) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v154 = v177;
    v138 = (Lisp_Object)33; /* 2 */
    v138 = Ldivide(nil, v154, v138);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    stack[-1] = v138;
    v154 = stack[0];
    v138 = stack[-1];
    v138 = qcar(v138);
    v138 = CC_exptKmodKp(env, v154, v138);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    v177 = v138;
    v138 = v177;
    v154 = v177;
    fn = elt(env, 1); /* times!-mod!-p */
    v138 = (*qfn2(fn))(qenv(fn), v138, v154);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    v177 = v138;
    v138 = stack[-1];
    v154 = qcdr(v138);
    v138 = (Lisp_Object)1; /* 0 */
    if (v154 == v138) { popv(3); return onevalue(v177); }
    v154 = v177;
    v138 = stack[0];
    fn = elt(env, 1); /* times!-mod!-p */
    v138 = (*qfn2(fn))(qenv(fn), v154, v138);
    nil = C_nil;
    if (exception_pending()) goto v203;
    v177 = v138;
    { popv(3); return onevalue(v177); }

v34:
    v138 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v138); }
/* error exit handlers */
v203:
    popv(3);
    return nil;
}



/* Code for get_group_in */

static Lisp_Object CC_get_group_in(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v14;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_group_in");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v14 = v0;
/* end of prologue */
    v14 = qcar(v14);
    return onevalue(v14);
}



/* Code for qqe_ofsf_simplat1 */

static Lisp_Object CC_qqe_ofsf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v178;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_simplat1");
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
    v178 = stack[-1];
    v199 = stack[0];
    fn = elt(env, 2); /* qqe_simplat1 */
    v199 = (*qfn2(fn))(qenv(fn), v178, v199);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    stack[-2] = v199;
    v178 = stack[-2];
    v199 = elt(env, 1); /* (true false) */
    v199 = Lmemq(nil, v178, v199);
    if (!(v199 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v199 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v199 = (*qfn1(fn))(qenv(fn), v199);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    fn = elt(env, 4); /* qqe_rqopp */
    v199 = (*qfn1(fn))(qenv(fn), v199);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    if (!(v199 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v178 = stack[-2];
    v199 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ofsf_simplat1 */
        return (*qfn2(fn))(qenv(fn), v178, v199);
    }
/* error exit handlers */
v119:
    popv(4);
    return nil;
}



/* Code for rl_negateat */

static Lisp_Object CC_rl_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_negateat");
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
    v88 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_negateat!* */
    v88 = ncons(v88);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-1];
    {
        Lisp_Object v156 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v156, v88);
    }
/* error exit handlers */
v128:
    popv(2);
    return nil;
}



/* Code for ibalp_redclause */

static Lisp_Object CC_ibalp_redclause(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v199;
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
    v146 = stack[-1];
    v146 = qcar(v146);
    stack[-2] = v146;
    goto v89;

v89:
    v146 = stack[-2];
    if (v146 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v146 = stack[0];
    if (!(v146 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v146 = stack[-2];
    v199 = qcar(v146);
    v146 = stack[-1];
    v146 = qcdr(v146);
    v146 = qcar(v146);
    fn = elt(env, 3); /* ibalp_vmember */
    v146 = (*qfn2(fn))(qenv(fn), v199, v146);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    if (v146 == nil) goto v121;
    v146 = qvalue(elt(env, 2)); /* t */
    stack[0] = v146;
    goto v121;

v121:
    v146 = stack[-2];
    v146 = qcdr(v146);
    stack[-2] = v146;
    goto v89;
/* error exit handlers */
v147:
    popv(4);
    return nil;
}



/* Code for aex_simplenullp */

static Lisp_Object CC_aex_simplenullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34;
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
    v34 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_nullp */
        return (*qfn1(fn))(qenv(fn), v34);
    }
/* error exit handlers */
v14:
    popv(1);
    return nil;
}



/* Code for variablesir */

static Lisp_Object MS_CDECL CC_variablesir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v147;
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
    v147 = qvalue(elt(env, 1)); /* char */
    v75 = elt(env, 2); /* (!/ o m b v a r) */
    if (equal(v147, v75)) goto v14;
    fn = elt(env, 4); /* omvir */
    v75 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    stack[0] = v75;
    fn = elt(env, 5); /* lex */
    v75 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v75 = CC_variablesir(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v147 = stack[0];
    if (v147 == nil) goto v90;
    v147 = stack[0];
    popv(2);
    return cons(v147, v75);

v90:
    v147 = stack[0];
        popv(2);
        return Lappend(nil, v147, v75);

v14:
    v75 = nil;
    { popv(2); return onevalue(v75); }
/* error exit handlers */
v118:
    popv(2);
    return nil;
}



/* Code for lid */

static Lisp_Object CC_lid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v128;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lid");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v127 = v0;
/* end of prologue */
    v128 = v127;
    if (!consp(v128)) return onevalue(v127);
    v127 = qcar(v127);
    return onevalue(v127);
}



/* Code for invp */

static Lisp_Object CC_invp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v93, v183;
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
    v183 = v0;
/* end of prologue */
    v93 = v183;
    v94 = elt(env, 1); /* unit */
    if (v93 == v94) return onevalue(v183);
    v94 = v183;
    if (!consp(v94)) goto v124;
    v94 = v183;
    v93 = qcar(v94);
    v94 = elt(env, 3); /* (comm anticomm) */
    v94 = Lmember(nil, v93, v94);
    if (v94 == nil) goto v117;
    v93 = elt(env, 4); /* quotient */
    v94 = (Lisp_Object)17; /* 1 */
    return list3(v93, v94, v183);

v117:
    v94 = v183;
    v93 = qcar(v94);
    v94 = elt(env, 2); /* inverse */
    v94 = get(v93, v94);
    v93 = v183;
    v93 = qcdr(v93);
    return cons(v94, v93);

v124:
    v94 = v183;
    v93 = elt(env, 2); /* inverse */
    return get(v94, v93);
}



/* Code for formcond1 */

static Lisp_Object MS_CDECL CC_formcond1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v126, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formcond1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formcond1");
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
    stack[-4] = nil;
    goto v153;

v153:
    v125 = stack[-3];
    if (v125 == nil) goto v89;
    v125 = stack[-3];
    v125 = qcar(v125);
    v63 = qcar(v125);
    v126 = stack[-2];
    v125 = stack[-1];
    fn = elt(env, 1); /* formbool */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v63, v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    v125 = stack[-3];
    v125 = qcar(v125);
    v125 = qcdr(v125);
    v63 = qcar(v125);
    v126 = stack[-2];
    v125 = stack[-1];
    fn = elt(env, 2); /* formc */
    v125 = (*qfnn(fn))(qenv(fn), 3, v63, v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    v126 = list2(stack[0], v125);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    v125 = stack[-4];
    v125 = cons(v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    stack[-4] = v125;
    v125 = stack[-3];
    v125 = qcdr(v125);
    stack[-3] = v125;
    goto v153;

v89:
    v125 = stack[-4];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v125);
    }
/* error exit handlers */
v93:
    popv(6);
    return nil;
}



/* Code for mkarray1 */

static Lisp_Object CC_mkarray1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v201;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkarray1");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v69 = stack[-5];
    if (v69 == nil) goto v127;
    v69 = stack[-5];
    v69 = qcar(v69);
    v69 = sub1(v69);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-7];
    stack[-6] = v69;
    v69 = stack[-6];
    v69 = Lmkvect(nil, v69);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-7];
    stack[-3] = v69;
    v69 = (Lisp_Object)1; /* 0 */
    stack[-2] = v69;
    goto v118;

v118:
    v201 = stack[-6];
    v69 = stack[-2];
    v69 = difference2(v201, v69);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-7];
    v69 = Lminusp(nil, v69);
    env = stack[-7];
    if (!(v69 == nil)) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-3];
    stack[0] = stack[-2];
    v69 = stack[-5];
    v201 = qcdr(v69);
    v69 = stack[-4];
    v69 = CC_mkarray1(env, v201, v69);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v69;
    v69 = stack[-2];
    v69 = add1(v69);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-7];
    stack[-2] = v69;
    goto v118;

v127:
    v201 = stack[-4];
    v69 = elt(env, 1); /* symbolic */
    if (v201 == v69) goto v89;
    v69 = (Lisp_Object)1; /* 0 */
    { popv(8); return onevalue(v69); }

v89:
    v69 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v69); }
/* error exit handlers */
v67:
    popv(8);
    return nil;
}



/* Code for !:divide */

static Lisp_Object CC_Tdivide(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v126, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :divide");
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
    v126 = v1;
    v63 = v0;
/* end of prologue */
    v125 = v63;
    if (v125 == nil) goto v34;
    v125 = v126;
    if (v125 == nil) goto v89;
    v125 = v63;
    if (!consp(v125)) goto v136;
    v125 = qvalue(elt(env, 1)); /* nil */
    goto v130;

v130:
    if (v125 == nil) goto v185;
    v125 = v63;
    {
        popv(1);
        fn = elt(env, 6); /* dividef */
        return (*qfn2(fn))(qenv(fn), v125, v126);
    }

v185:
    v125 = elt(env, 5); /* divide */
    {
        popv(1);
        fn = elt(env, 7); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v63, v126, v125);
    }

v136:
    v125 = v126;
    v125 = (consp(v125) ? nil : lisp_true);
    goto v130;

v89:
    v125 = elt(env, 2); /* "zero divisor" */
    v126 = v125;
    v125 = v126;
    qvalue(elt(env, 3)) = v125; /* errmsg!* */
    v125 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v125 == nil)) goto v134;
    v125 = v126;
    fn = elt(env, 8); /* lprie */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[0];
    goto v134;

v134:
    v125 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    v125 = nil;
    { popv(1); return onevalue(v125); }

v34:
    v125 = qvalue(elt(env, 1)); /* nil */
    popv(1);
    return ncons(v125);
/* error exit handlers */
v96:
    popv(1);
    return nil;
}



/* Code for gperm0 */

static Lisp_Object CC_gperm0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v73;
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
    v73 = v0;
/* end of prologue */
    v129 = v73;
    if (v129 == nil) goto v141;
    v129 = v73;
    stack[0] = qcdr(v129);
    v129 = v73;
    v129 = qcar(v129);
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    {
        Lisp_Object v116 = stack[0];
        popv(2);
        fn = elt(env, 2); /* gperm3 */
        return (*qfn2(fn))(qenv(fn), v116, v129);
    }

v141:
    v129 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v129); }
/* error exit handlers */
v90:
    popv(2);
    return nil;
}



/* Code for freeofl */

static Lisp_Object CC_freeofl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v187, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeofl");
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

v87:
    v186 = stack[0];
    if (v186 == nil) goto v34;
    v186 = stack[0];
    v187 = qcar(v186);
    v186 = stack[-1];
    fn = elt(env, 4); /* smember */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    if (!(v186 == nil)) goto v72;
    v186 = stack[0];
    v117 = qcar(v186);
    v187 = stack[-1];
    v186 = qvalue(elt(env, 2)); /* depl!* */
    v186 = Lassoc(nil, v187, v186);
    v186 = Lmember(nil, v117, v186);
    if (!(v186 == nil)) goto v72;
    v187 = stack[-1];
    v186 = stack[0];
    v186 = qcdr(v186);
    stack[-1] = v187;
    stack[0] = v186;
    goto v87;

v72:
    v186 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v186); }

v34:
    v186 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v186); }
/* error exit handlers */
v125:
    popv(3);
    return nil;
}



/* Code for cl_atfp */

static Lisp_Object CC_cl_atfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v227, v228, v229;
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
    v228 = v0;
/* end of prologue */
    v227 = v228;
    if (!consp(v227)) goto v141;
    v227 = v228;
    v227 = qcar(v227);
    goto v3;

v3:
    v229 = v227;
    v228 = v229;
    v227 = elt(env, 1); /* true */
    if (v228 == v227) goto v134;
    v228 = v229;
    v227 = elt(env, 3); /* false */
    v227 = (v228 == v227 ? lisp_true : nil);
    goto v124;

v124:
    if (v227 == nil) goto v98;
    v227 = qvalue(elt(env, 2)); /* t */
    goto v156;

v156:
    v227 = (v227 == nil ? lisp_true : nil);
    return onevalue(v227);

v98:
    v228 = v229;
    v227 = elt(env, 4); /* or */
    if (v228 == v227) goto v117;
    v228 = v229;
    v227 = elt(env, 5); /* and */
    v227 = (v228 == v227 ? lisp_true : nil);
    goto v187;

v187:
    if (v227 == nil) goto v177;
    v227 = qvalue(elt(env, 2)); /* t */
    goto v72;

v72:
    if (v227 == nil) goto v192;
    v227 = qvalue(elt(env, 2)); /* t */
    goto v120;

v120:
    if (v227 == nil) goto v53;
    v227 = qvalue(elt(env, 2)); /* t */
    goto v156;

v53:
    v228 = v229;
    v227 = elt(env, 10); /* ex */
    if (v228 == v227) goto v58;
    v228 = v229;
    v227 = elt(env, 11); /* all */
    v227 = (v228 == v227 ? lisp_true : nil);
    goto v57;

v57:
    if (v227 == nil) goto v218;
    v227 = qvalue(elt(env, 2)); /* t */
    goto v156;

v218:
    v228 = v229;
    v227 = elt(env, 12); /* bex */
    if (v228 == v227) goto v48;
    v228 = v229;
    v227 = elt(env, 13); /* ball */
    v227 = (v228 == v227 ? lisp_true : nil);
    goto v51;

v51:
    if (v227 == nil) goto v230;
    v227 = qvalue(elt(env, 2)); /* t */
    goto v156;

v230:
    v228 = v229;
    v227 = elt(env, 14); /* rl_external */
    v227 = get(v228, v227);
    goto v156;

v48:
    v227 = qvalue(elt(env, 2)); /* t */
    goto v51;

v58:
    v227 = qvalue(elt(env, 2)); /* t */
    goto v57;

v192:
    v228 = v229;
    v227 = elt(env, 7); /* impl */
    if (v228 == v227) goto v195;
    v228 = v229;
    v227 = elt(env, 8); /* repl */
    if (v228 == v227) goto v207;
    v228 = v229;
    v227 = elt(env, 9); /* equiv */
    v227 = (v228 == v227 ? lisp_true : nil);
    goto v120;

v207:
    v227 = qvalue(elt(env, 2)); /* t */
    goto v120;

v195:
    v227 = qvalue(elt(env, 2)); /* t */
    goto v120;

v177:
    v228 = v229;
    v227 = elt(env, 6); /* not */
    v227 = (v228 == v227 ? lisp_true : nil);
    goto v72;

v117:
    v227 = qvalue(elt(env, 2)); /* t */
    goto v187;

v134:
    v227 = qvalue(elt(env, 2)); /* t */
    goto v124;

v141:
    v227 = v228;
    goto v3;
}



/* Code for ibalp_lenisone */

static Lisp_Object CC_ibalp_lenisone(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v156;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_lenisone");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v156 = v0;
/* end of prologue */
    v128 = v156;
    if (v128 == nil) goto v141;
    v128 = v156;
    v128 = qcdr(v128);
    v128 = (v128 == nil ? lisp_true : nil);
    return onevalue(v128);

v141:
    v128 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v128);
}



/* Code for numpoly_nullp */

static Lisp_Object CC_numpoly_nullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v134;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_nullp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v134 = v0;
/* end of prologue */
    v124 = v134;
    if (v124 == nil) goto v141;
    v124 = (Lisp_Object)1; /* 0 */
    v124 = (v134 == v124 ? lisp_true : nil);
    return onevalue(v124);

v141:
    v124 = qvalue(elt(env, 1)); /* t */
    return onevalue(v124);
}



/* Code for inshisto */

static Lisp_Object CC_inshisto(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49, v218;
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
    v49 = qvalue(elt(env, 2)); /* maxvar */
    v48 = stack[-3];
    v48 = plus2(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-5];
    v49 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v48 = (Lisp_Object)1; /* 0 */
    v48 = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    if (v48 == nil) goto v34;
    v49 = stack[-3];
    v48 = (Lisp_Object)1; /* 0 */
    v48 = (Lisp_Object)geq2(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v223;
    v48 = v48 ? lisp_true : nil;
    env = stack[-5];
    if (v48 == nil) goto v34;
    stack[0] = qvalue(elt(env, 3)); /* codhisto */
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v49 = qvalue(elt(env, 2)); /* maxvar */
    v48 = stack[-3];
    v48 = plus2(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-5];
    v49 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v48 = (Lisp_Object)17; /* 1 */
    v48 = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v49 = qcdr(v48);
    v48 = (Lisp_Object)3201; /* 200 */
    fn = elt(env, 6); /* min */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-5];
    stack[-2] = v48;
    v48 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    stack[-4] = v48;
    if (v48 == nil) goto v56;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v49 = qvalue(elt(env, 2)); /* maxvar */
    v48 = stack[-4];
    v48 = plus2(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-5];
    v49 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v48 = (Lisp_Object)113; /* 7 */
    v49 = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v48 = stack[-3];
    v48 = Lrplaca(nil, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-5];
    goto v196;

v196:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v49 = qvalue(elt(env, 2)); /* maxvar */
    v48 = stack[-3];
    v48 = plus2(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-5];
    stack[-1] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    stack[0] = (Lisp_Object)113; /* 7 */
    v49 = qvalue(elt(env, 5)); /* nil */
    v48 = stack[-4];
    v48 = cons(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-5];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v48;
    v218 = qvalue(elt(env, 3)); /* codhisto */
    v49 = stack[-2];
    v48 = stack[-3];
    *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v49/(16/CELL))) = v48;
    v48 = nil;
    { popv(6); return onevalue(v48); }

v56:
    v49 = stack[-2];
    v48 = qvalue(elt(env, 4)); /* headhisto */
    v48 = (Lisp_Object)greaterp2(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v223;
    v48 = v48 ? lisp_true : nil;
    env = stack[-5];
    if (v48 == nil) goto v196;
    v48 = stack[-2];
    qvalue(elt(env, 4)) = v48; /* headhisto */
    goto v196;

v34:
    v48 = nil;
    { popv(6); return onevalue(v48); }
/* error exit handlers */
v223:
    popv(6);
    return nil;
}



/* Code for evenfree */

static Lisp_Object CC_evenfree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v93;
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
    v94 = stack[0];
    if (v94 == nil) goto v141;
    v94 = stack[0];
    if (is_number(v94)) goto v127;
    v94 = stack[0];
    v94 = qcar(v94);
    v93 = ncons(v94);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v94 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v94 = (*qfn2(fn))(qenv(fn), v93, v94);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v94 = qcdr(v94);
    stack[-1] = v94;
    v94 = stack[-1];
    fn = elt(env, 3); /* minusf */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    if (v94 == nil) goto v126;
    v94 = stack[-1];
    fn = elt(env, 4); /* negf */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    stack[-1] = v94;
    goto v132;

v132:
    v94 = stack[0];
    v94 = qcdr(v94);
    v94 = CC_evenfree(env, v94);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    {
        Lisp_Object v208 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* addf */
        return (*qfn2(fn))(qenv(fn), v208, v94);
    }

v126:
    v94 = stack[-1];
    stack[-1] = v94;
    goto v132;

v127:
    v93 = stack[0];
    v94 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v94 = (*qfn2(fn))(qenv(fn), v93, v94);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v94 = qcdr(v94);
    stack[0] = v94;
    v94 = stack[0];
    fn = elt(env, 3); /* minusf */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    if (v94 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v94 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* negf */
        return (*qfn1(fn))(qenv(fn), v94);
    }

v141:
    v94 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v94); }
/* error exit handlers */
v140:
    popv(3);
    return nil;
}



setup_type const u12_setup[] =
{
    {"cl_varl2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_varl2},
    {"ldt-tvar",                CC_ldtKtvar,    too_many_1,    wrong_no_1},
    {"simpindexvar",            CC_simpindexvar,too_many_1,    wrong_no_1},
    {"mksetq",                  too_few_2,      CC_mksetq,     wrong_no_2},
    {"evalneq",                 too_few_2,      CC_evalneq,    wrong_no_2},
    {"mv-pow--",                too_few_2,      CC_mvKpowKK,   wrong_no_2},
    {"bc_fi",                   CC_bc_fi,       too_many_1,    wrong_no_1},
    {"pv_times3",               too_few_2,      CC_pv_times3,  wrong_no_2},
    {"dv_skel2factor1",         too_few_2,      CC_dv_skel2factor1,wrong_no_2},
    {"copy-vector",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_copyKvector},
    {"difference-mod-p",        too_few_2,      CC_differenceKmodKp,wrong_no_2},
    {"sfto_ucontentf",          CC_sfto_ucontentf,too_many_1,  wrong_no_1},
    {"ofsf_prepat",             CC_ofsf_prepat, too_many_1,    wrong_no_1},
    {"attributesml",            too_few_2,      CC_attributesml,wrong_no_2},
    {"groebnormalform",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebnormalform},
    {"prop-simp",               too_few_2,      CC_propKsimp,  wrong_no_2},
    {"assert_format",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_format},
    {"aminusp:1",               CC_aminuspT1,   too_many_1,    wrong_no_1},
    {"nzeros",                  CC_nzeros,      too_many_1,    wrong_no_1},
    {"dividef",                 too_few_2,      CC_dividef,    wrong_no_2},
    {"terpri*",                 CC_terpriH,     too_many_1,    wrong_no_1},
    {"noncomperm",              CC_noncomperm,  too_many_1,    wrong_no_1},
    {"rl_csimpl",               CC_rl_csimpl,   too_many_1,    wrong_no_1},
    {"ibalp_getvar-zmom",       too_few_2,      CC_ibalp_getvarKzmom,wrong_no_2},
    {"ratpoly_ratp",            CC_ratpoly_ratp,too_many_1,    wrong_no_1},
    {"matrixrowrd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrowrd},
    {"floatprop",               CC_floatprop,   too_many_1,    wrong_no_1},
    {"noncommuting",            too_few_2,      CC_noncommuting,wrong_no_2},
    {"one-entry-listp",         too_few_2,      CC_oneKentryKlistp,wrong_no_2},
    {"dp=mocompare",            too_few_2,      CC_dpMmocompare,wrong_no_2},
    {"pv_intequiv",             CC_pv_intequiv, too_many_1,    wrong_no_1},
    {"st_sorttree",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree},
    {"degree-in-variable",      too_few_2,      CC_degreeKinKvariable,wrong_no_2},
    {"lto_almerge",             too_few_2,      CC_lto_almerge,wrong_no_2},
    {"updtemplate",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_updtemplate},
    {"qqe_ofsf_chsimpterm",     CC_qqe_ofsf_chsimpterm,too_many_1,wrong_no_1},
    {"pasf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwmkatl},
    {"rl_simpbop",              CC_rl_simpbop,  too_many_1,    wrong_no_1},
    {"cird",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cird},
    {"guesspftype",             CC_guesspftype, too_many_1,    wrong_no_1},
    {"equalreplaceby",          CC_equalreplaceby,too_many_1,  wrong_no_1},
    {"inttovec",                too_few_2,      CC_inttovec,   wrong_no_2},
    {"assert_uninstall_all",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_uninstall_all},
    {"eqdummy",                 too_few_2,      CC_eqdummy,    wrong_no_2},
    {"numlist_ordp",            too_few_2,      CC_numlist_ordp,wrong_no_2},
    {"lambda_lqgavx_2",         too_few_2,      CC_lambda_lqgavx_2,wrong_no_2},
    {"extmult",                 too_few_2,      CC_extmult,    wrong_no_2},
    {"simp*sq",                 CC_simpHsq,     too_many_1,    wrong_no_1},
    {"mkzl",                    CC_mkzl,        too_many_1,    wrong_no_1},
    {"ibalp_clausep",           CC_ibalp_clausep,too_many_1,   wrong_no_1},
    {"aex_mvaroccurtest",       too_few_2,      CC_aex_mvaroccurtest,wrong_no_2},
    {"ofsf_sacatlp",            too_few_2,      CC_ofsf_sacatlp,wrong_no_2},
    {"cr:prep",                 CC_crTprep,     too_many_1,    wrong_no_1},
    {"initwght",                CC_initwght,    too_many_1,    wrong_no_1},
    {"bcplus?",                 CC_bcplusW,     too_many_1,    wrong_no_1},
    {"vevmaptozero1",           too_few_2,      CC_vevmaptozero1,wrong_no_2},
    {"physopaeval",             CC_physopaeval, too_many_1,    wrong_no_1},
    {"zero-roads",              CC_zeroKroads,  too_many_1,    wrong_no_1},
    {"assert_install",          CC_assert_install,too_many_1,  wrong_no_1},
    {"mo=revlexcomp",           too_few_2,      CC_moMrevlexcomp,wrong_no_2},
    {"dv_cambhead",             CC_dv_cambhead, too_many_1,    wrong_no_1},
    {"expt-mod-p",              too_few_2,      CC_exptKmodKp, wrong_no_2},
    {"get_group_in",            CC_get_group_in,too_many_1,    wrong_no_1},
    {"qqe_ofsf_simplat1",       too_few_2,      CC_qqe_ofsf_simplat1,wrong_no_2},
    {"rl_negateat",             CC_rl_negateat, too_many_1,    wrong_no_1},
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
    {"cl_atfp",                 CC_cl_atfp,     too_many_1,    wrong_no_1},
    {"ibalp_lenisone",          CC_ibalp_lenisone,too_many_1,  wrong_no_1},
    {"numpoly_nullp",           CC_numpoly_nullp,too_many_1,   wrong_no_1},
    {"inshisto",                CC_inshisto,    too_many_1,    wrong_no_1},
    {"evenfree",                CC_evenfree,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u12", (two_args *)"8866 127711 6736972", 0}
};

/* end of generated code */
