
/* $destdir\u25.c        Machine generated C code */

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


/* Code for cl_smsimpl!-junct */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40, v41, v42, v43, v44, v45;
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
    v39 = qvalue(elt(env, 1)); /* !*rlsism */
    if (v39 == nil) goto v46;
    v39 = stack[-6];
    fn = elt(env, 5); /* rl_smcpknowl */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-9];
    stack[-2] = v39;
    v41 = elt(env, 3); /* false */
    v40 = stack[-7];
    v39 = elt(env, 4); /* and */
    v39 = (v40 == v39 ? lisp_true : nil);
    fn = elt(env, 6); /* cl_cflip */
    v39 = (*qfn2(fn))(qenv(fn), v41, v39);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-9];
    stack[-8] = v39;
    v39 = stack[0];
    stack[-1] = v39;
    goto v48;

v48:
    v39 = stack[-1];
    if (v39 == nil) goto v49;
    v39 = stack[-1];
    v39 = qcar(v39);
    stack[0] = v39;
    v39 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-9];
    if (v39 == nil) goto v50;
    v40 = stack[0];
    v39 = stack[-7];
    fn = elt(env, 8); /* cl_simplat */
    v39 = (*qfn2(fn))(qenv(fn), v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-9];
    goto v51;

v51:
    stack[0] = v39;
    v39 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-9];
    if (v39 == nil) goto v52;
    v40 = stack[0];
    v39 = stack[-4];
    v39 = cons(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-9];
    stack[-4] = v39;
    goto v53;

v53:
    v39 = stack[-1];
    v39 = qcdr(v39);
    stack[-1] = v39;
    goto v48;

v52:
    v40 = stack[0];
    v39 = stack[-3];
    v39 = cons(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-9];
    stack[-3] = v39;
    goto v53;

v50:
    v39 = stack[0];
    goto v51;

v49:
    v42 = stack[-7];
    v41 = stack[-4];
    v40 = stack[-2];
    v39 = stack[-5];
    fn = elt(env, 9); /* rl_smupdknowl */
    v39 = (*qfnn(fn))(qenv(fn), 4, v42, v41, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-9];
    stack[-2] = v39;
    v40 = stack[-2];
    v39 = elt(env, 3); /* false */
    if (v40 == v39) goto v54;
    v45 = stack[-7];
    v44 = stack[-4];
    v39 = stack[-3];
    v43 = Lnreverse(nil, v39);
    env = stack[-9];
    v42 = stack[-6];
    v41 = stack[-2];
    v40 = stack[-5];
    v39 = stack[-8];
    {
        popv(10);
        fn = elt(env, 10); /* cl_smsimpl!-junct1 */
        return (*qfnn(fn))(qenv(fn), 7, v45, v44, v43, v42, v41, v40, v39);
    }

v54:
    v39 = stack[-8];
    popv(10);
    return ncons(v39);

v46:
    v42 = stack[0];
    v41 = stack[-5];
    v40 = stack[-7];
    v39 = qvalue(elt(env, 2)); /* nil */
    {
        popv(10);
        fn = elt(env, 11); /* cl_gand!-col */
        return (*qfnn(fn))(qenv(fn), 4, v42, v41, v40, v39);
    }
/* error exit handlers */
v47:
    popv(10);
    return nil;
}



/* Code for embed!-null!-fn */

static Lisp_Object CC_embedKnullKfn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v64, v65;
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
    v64 = v0;
/* end of prologue */
    v49 = v64;
    if (!consp(v49)) { popv(5); return onevalue(v64); }
    v49 = v64;
    stack[-3] = v49;
    goto v66;

v66:
    v49 = stack[-3];
    if (v49 == nil) goto v67;
    v49 = stack[-3];
    v49 = qcar(v49);
    v65 = v49;
    v49 = v65;
    if (!consp(v49)) goto v37;
    v49 = v65;
    v64 = qcar(v49);
    v49 = elt(env, 2); /* null!-fn */
    if (v64 == v49) goto v68;
    v49 = v65;
    v49 = CC_embedKnullKfn(env, v49);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    goto v36;

v36:
    stack[-2] = v49;
    v49 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-1] = v49;
    v49 = stack[-3];
    v49 = qcdr(v49);
    stack[-3] = v49;
    v49 = stack[-1];
    if (!consp(v49)) goto v66;
    else goto v70;

v70:
    v49 = stack[-3];
    if (v49 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v49 = stack[-3];
    v49 = qcar(v49);
    v65 = v49;
    v49 = v65;
    if (!consp(v49)) goto v71;
    v49 = v65;
    v64 = qcar(v49);
    v49 = elt(env, 2); /* null!-fn */
    if (v64 == v49) goto v72;
    v49 = v65;
    v49 = CC_embedKnullKfn(env, v49);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    goto v73;

v73:
    v49 = Lrplacd(nil, stack[0], v49);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v49 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-1] = v49;
    v49 = stack[-3];
    v49 = qcdr(v49);
    stack[-3] = v49;
    goto v70;

v72:
    v49 = v65;
    v49 = qcdr(v49);
    v49 = CC_embedKnullKfn(env, v49);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    goto v73;

v71:
    v49 = v65;
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    goto v73;

v68:
    v49 = v65;
    v49 = qcdr(v49);
    v49 = CC_embedKnullKfn(env, v49);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    goto v36;

v37:
    v49 = v65;
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    goto v36;

v67:
    v49 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v49); }
/* error exit handlers */
v69:
    popv(5);
    return nil;
}



/* Code for xlcm */

static Lisp_Object CC_xlcm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v85;
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
    goto v23;

v23:
    v84 = stack[-1];
    if (v84 == nil) goto v86;
    v84 = stack[-1];
    v85 = qcar(v84);
    v84 = (Lisp_Object)17; /* 1 */
    v84 = (v85 == v84 ? lisp_true : nil);
    goto v57;

v57:
    if (v84 == nil) goto v59;
    v85 = stack[-2];
    v84 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v85, v84);
    }

v59:
    v84 = stack[0];
    if (v84 == nil) goto v87;
    v84 = stack[0];
    v85 = qcar(v84);
    v84 = (Lisp_Object)17; /* 1 */
    v84 = (v85 == v84 ? lisp_true : nil);
    goto v31;

v31:
    if (v84 == nil) goto v88;
    v85 = stack[-2];
    v84 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v85, v84);
    }

v88:
    v84 = stack[-1];
    v85 = qcar(v84);
    v84 = stack[0];
    v84 = qcar(v84);
    if (v85 == v84) goto v29;
    v84 = stack[-1];
    v85 = qcar(v84);
    v84 = stack[0];
    v84 = qcar(v84);
    fn = elt(env, 3); /* factorordp */
    v84 = (*qfn2(fn))(qenv(fn), v85, v84);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    if (v84 == nil) goto v69;
    v84 = stack[-1];
    v85 = qcar(v84);
    v84 = stack[-2];
    v84 = cons(v85, v84);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    stack[-2] = v84;
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v23;

v69:
    v84 = stack[0];
    v85 = qcar(v84);
    v84 = stack[-2];
    v84 = cons(v85, v84);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    stack[-2] = v84;
    v84 = stack[0];
    v84 = qcdr(v84);
    stack[0] = v84;
    goto v23;

v29:
    v84 = stack[-1];
    v85 = qcar(v84);
    v84 = stack[-2];
    v84 = cons(v85, v84);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    stack[-2] = v84;
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    v84 = stack[0];
    v84 = qcdr(v84);
    stack[0] = v84;
    goto v23;

v87:
    v84 = qvalue(elt(env, 1)); /* t */
    goto v31;

v86:
    v84 = qvalue(elt(env, 1)); /* t */
    goto v57;
/* error exit handlers */
v15:
    popv(4);
    return nil;
}



/* Code for aceq */

static Lisp_Object CC_aceq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v33, v34, v32;
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
    v33 = v1;
    v34 = v0;
/* end of prologue */

v23:
    v89 = v34;
    if (v89 == nil) goto v12;
    v89 = v33;
    if (v89 == nil) goto v90;
    v89 = v34;
    v32 = qcar(v89);
    v89 = v33;
    v89 = Lmember(nil, v32, v89);
    if (v89 == nil) goto v91;
    v89 = v34;
    v89 = qcdr(v89);
    stack[0] = v89;
    v89 = v34;
    v89 = qcar(v89);
    v89 = Ldelete(nil, v89, v33);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-1];
    v33 = v89;
    v89 = stack[0];
    v34 = v89;
    goto v23;

v91:
    v89 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v89); }

v90:
    v89 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v89); }

v12:
    v89 = v33;
    v89 = (v89 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v89); }
/* error exit handlers */
v92:
    popv(2);
    return nil;
}



/* Code for flatindl */

static Lisp_Object CC_flatindl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v89;
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
    goto v23;

v23:
    v63 = stack[0];
    if (v63 == nil) goto v14;
    v63 = stack[0];
    v89 = qcar(v63);
    v63 = stack[-1];
    v63 = cons(v89, v63);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    stack[-1] = v63;
    v63 = stack[0];
    v63 = qcdr(v63);
    stack[0] = v63;
    goto v23;

v14:
    v63 = qvalue(elt(env, 1)); /* nil */
    v89 = v63;
    goto v13;

v13:
    v63 = stack[-1];
    if (v63 == nil) { popv(3); return onevalue(v89); }
    v63 = stack[-1];
    v63 = qcar(v63);
    v63 = Lappend(nil, v63, v89);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v89 = v63;
    v63 = stack[-1];
    v63 = qcdr(v63);
    stack[-1] = v63;
    goto v13;
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for formbool */

static Lisp_Object MS_CDECL CC_formbool(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v141, v142, v143, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formbool");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formbool");
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
    v141 = stack[-2];
    v140 = elt(env, 1); /* symbolic */
    if (v141 == v140) goto v70;
    v140 = stack[-4];
    if (!consp(v140)) goto v145;
    v140 = stack[-4];
    v141 = qcdr(v140);
    v140 = stack[-3];
    fn = elt(env, 11); /* intexprlisp */
    v140 = (*qfn2(fn))(qenv(fn), v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-6];
    if (v140 == nil) goto v147;
    v140 = stack[-4];
    v141 = qcar(v140);
    v140 = elt(env, 4); /* boolfn */
    v140 = get(v141, v140);
    env = stack[-6];
    if (!(v140 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }

v147:
    v140 = stack[-4];
    v140 = qcar(v140);
    if (!(symbolp(v140))) goto v148;
    v140 = stack[-4];
    v141 = qcar(v140);
    v140 = elt(env, 4); /* boolfn */
    v140 = get(v141, v140);
    env = stack[-6];
    if (v140 == nil) goto v148;
    v140 = stack[-4];
    v141 = qcar(v140);
    v140 = elt(env, 4); /* boolfn */
    stack[0] = get(v141, v140);
    env = stack[-6];
    v140 = stack[-4];
    v142 = qcdr(v140);
    v141 = stack[-3];
    v140 = stack[-2];
    fn = elt(env, 12); /* formclis */
    v140 = (*qfnn(fn))(qenv(fn), 3, v142, v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v146;
    {
        Lisp_Object v149 = stack[0];
        popv(7);
        return cons(v149, v140);
    }

v148:
    v140 = stack[-4];
    v140 = qcar(v140);
    if (!(symbolp(v140))) goto v150;
    v140 = stack[-4];
    v141 = qcar(v140);
    v140 = elt(env, 5); /* boolean */
    v140 = Lflagp(nil, v141, v140);
    env = stack[-6];
    if (v140 == nil) goto v150;
    v140 = stack[-4];
    stack[0] = qcar(v140);
    v140 = stack[-4];
    v144 = qcdr(v140);
    v143 = stack[-3];
    v142 = stack[-2];
    v140 = stack[-4];
    v141 = qcar(v140);
    v140 = elt(env, 6); /* boolargs */
    v140 = Lflagp(nil, v141, v140);
    env = stack[-6];
    fn = elt(env, 13); /* formboollis */
    v140 = (*qfnn(fn))(qenv(fn), 4, v144, v143, v142, v140);
    nil = C_nil;
    if (exception_pending()) goto v146;
    {
        Lisp_Object v151 = stack[0];
        popv(7);
        return cons(v151, v140);
    }

v150:
    v140 = stack[-4];
    v141 = qcar(v140);
    v140 = elt(env, 3); /* boolvalue!* */
    if (v141 == v140) goto v152;
    v140 = stack[-4];
    v141 = qcar(v140);
    v140 = elt(env, 9); /* where */
    if (v141 == v140) goto v153;
    stack[0] = elt(env, 3); /* boolvalue!* */
    v142 = stack[-4];
    v141 = stack[-3];
    v140 = stack[-2];
    fn = elt(env, 14); /* formc!* */
    v140 = (*qfnn(fn))(qenv(fn), 3, v142, v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v146;
    {
        Lisp_Object v154 = stack[0];
        popv(7);
        return list2(v154, v140);
    }

v153:
    stack[-5] = elt(env, 3); /* boolvalue!* */
    stack[-1] = elt(env, 9); /* where */
    stack[0] = elt(env, 10); /* bool!-eval */
    v140 = stack[-4];
    v140 = qcdr(v140);
    v142 = qcar(v140);
    v141 = stack[-3];
    v140 = stack[-2];
    v140 = CC_formbool(env, 3, v142, v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-6];
    v140 = list2(stack[0], v140);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-6];
    v141 = Lmkquote(nil, v140);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-6];
    v140 = stack[-4];
    v140 = qcdr(v140);
    v140 = qcdr(v140);
    v140 = qcar(v140);
    v142 = list3(stack[-1], v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-6];
    v141 = stack[-3];
    v140 = stack[-2];
    fn = elt(env, 14); /* formc!* */
    v140 = (*qfnn(fn))(qenv(fn), 3, v142, v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v146;
    {
        Lisp_Object v155 = stack[-5];
        popv(7);
        return list2(v155, v140);
    }

v152:
    v140 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v140 == nil)) goto v156;
    v140 = elt(env, 8); /* "Too many formbools" */
    fn = elt(env, 15); /* lprie */
    v140 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-6];
    goto v156;

v156:
    v140 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v146;
    v140 = nil;
    { popv(7); return onevalue(v140); }

v145:
    v141 = stack[-4];
    v140 = lisp_true;
    if (v141 == v140) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v140 = stack[-4];
    if (symbolp(v140)) goto v48;
    v140 = qvalue(elt(env, 2)); /* t */
    goto v89;

v89:
    if (v140 == nil) goto v157;
    v141 = elt(env, 3); /* boolvalue!* */
    v140 = stack[-4];
    popv(7);
    return list2(v141, v140);

v157:
    stack[0] = elt(env, 3); /* boolvalue!* */
    v142 = stack[-4];
    v141 = stack[-3];
    v140 = stack[-2];
    fn = elt(env, 14); /* formc!* */
    v140 = (*qfnn(fn))(qenv(fn), 3, v142, v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v146;
    {
        Lisp_Object v158 = stack[0];
        popv(7);
        return list2(v158, v140);
    }

v48:
    v141 = stack[-4];
    v140 = stack[-3];
    v140 = Latsoc(nil, v141, v140);
    goto v89;

v70:
    v142 = stack[-4];
    v141 = stack[-3];
    v140 = stack[-2];
    {
        popv(7);
        fn = elt(env, 16); /* formc */
        return (*qfnn(fn))(qenv(fn), 3, v142, v141, v140);
    }
/* error exit handlers */
v146:
    popv(7);
    return nil;
}



/* Code for subcare */

static Lisp_Object MS_CDECL CC_subcare(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v165, v72;
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
    goto v14;

v14:
    v78 = stack[0];
    if (v78 == nil) goto v59;
    v165 = stack[-2];
    v78 = stack[0];
    if (equal(v165, v78)) goto v83;
    v78 = stack[0];
    if (!consp(v78)) goto v166;
    v78 = stack[0];
    v165 = qcar(v78);
    v78 = elt(env, 2); /* subfunc */
    v78 = get(v165, v78);
    env = stack[-4];
    goto v82;

v82:
    if (v78 == nil) goto v167;
    v165 = stack[-3];
    v78 = stack[0];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v165, v78);
    }

v167:
    v72 = stack[-2];
    v165 = stack[-1];
    v78 = stack[0];
    v78 = qcar(v78);
    v165 = CC_subcare(env, 3, v72, v165, v78);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-4];
    v78 = stack[-3];
    v78 = cons(v165, v78);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-4];
    stack[-3] = v78;
    v78 = stack[0];
    v78 = qcdr(v78);
    stack[0] = v78;
    goto v14;

v166:
    v78 = qvalue(elt(env, 1)); /* t */
    goto v82;

v83:
    v165 = stack[-3];
    v78 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v165, v78);
    }

v59:
    v78 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v78);
    }
/* error exit handlers */
v168:
    popv(5);
    return nil;
}



/* Code for red_topredbe */

static Lisp_Object CC_red_topredbe(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v161;
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
    v56 = stack[-1];
    fn = elt(env, 4); /* bas_dpoly */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    if (v56 == nil) goto v12;
    v56 = stack[-2];
    v56 = (v56 == nil ? lisp_true : nil);
    goto v13;

v13:
    if (!(v56 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    fn = elt(env, 5); /* cali_trace */
    v161 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    v56 = (Lisp_Object)1265; /* 79 */
    v56 = (Lisp_Object)greaterp2(v161, v56);
    nil = C_nil;
    if (exception_pending()) goto v165;
    v56 = v56 ? lisp_true : nil;
    env = stack[-4];
    if (v56 == nil) goto v33;
    v56 = elt(env, 2); /* " reduce " */
    v56 = Lprinc(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    v56 = stack[-1];
    fn = elt(env, 4); /* bas_dpoly */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    fn = elt(env, 6); /* dp_print */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    goto v33;

v33:
    v56 = stack[-1];
    fn = elt(env, 4); /* bas_dpoly */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    v161 = v56;
    if (v56 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    stack[-3] = stack[-2];
    v56 = v161;
    fn = elt(env, 7); /* dp_lmon */
    stack[0] = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    v56 = stack[-1];
    fn = elt(env, 8); /* bas_dpecart */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    fn = elt(env, 9); /* red_divtestbe */
    v161 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    v56 = v161;
    if (v161 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v161 = stack[-1];
    fn = elt(env, 10); /* red_subst */
    v56 = (*qfn2(fn))(qenv(fn), v161, v56);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    stack[-1] = v56;
    goto v33;

v12:
    v56 = qvalue(elt(env, 1)); /* t */
    goto v13;
/* error exit handlers */
v165:
    popv(5);
    return nil;
}



/* Code for simp!-prop2 */

static Lisp_Object CC_simpKprop2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6, v129;
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
    v5 = qvalue(elt(env, 1)); /* propvars!* */
    stack[-1] = v5;
    goto v90;

v90:
    v5 = stack[-1];
    if (v5 == nil) goto v86;
    v5 = stack[-1];
    v5 = qcar(v5);
    stack[0] = v5;
    v5 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v5;
    goto v36;

v36:
    v5 = stack[-5];
    if (v5 == nil) goto v35;
    v5 = stack[-5];
    v5 = qcar(v5);
    stack[-3] = v5;
    v5 = stack[-5];
    v5 = qcdr(v5);
    stack[-5] = v5;
    v6 = elt(env, 3); /* prop!* */
    v5 = stack[0];
    v5 = list2(v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-7];
    stack[-4] = v5;
    v6 = elt(env, 4); /* not_prop!* */
    v5 = stack[0];
    v5 = list2(v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-7];
    v129 = v5;
    v6 = stack[-4];
    v5 = stack[-3];
    v5 = Lmember(nil, v6, v5);
    if (!(v5 == nil)) goto v55;
    v5 = v129;
    v6 = stack[-4];
    v129 = v6;
    stack[-4] = v5;
    goto v55;

v55:
    v6 = stack[-4];
    v5 = stack[-3];
    v5 = Lsubst(nil, 3, v129, v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-7];
    stack[-6] = v5;
    v6 = stack[-3];
    v5 = stack[-2];
    v5 = cons(v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-7];
    stack[-2] = v5;
    v6 = stack[-6];
    v5 = stack[-5];
    v5 = Lmember(nil, v6, v5);
    stack[-6] = v5;
    if (v5 == nil) goto v36;
    v5 = stack[-6];
    if (v5 == nil) goto v176;
    v5 = stack[-6];
    v6 = qcar(v5);
    v5 = stack[-5];
    v5 = Ldelete(nil, v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-7];
    stack[-5] = v5;
    v5 = stack[-6];
    v6 = qcar(v5);
    v5 = stack[-2];
    v5 = cons(v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-7];
    stack[-2] = v5;
    goto v176;

v176:
    v6 = stack[-4];
    v5 = stack[-3];
    v5 = Ldelete(nil, v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-7];
    stack[-3] = v5;
    v5 = stack[-3];
    v6 = ncons(v5);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-7];
    v5 = stack[-2];
    fn = elt(env, 5); /* union */
    v5 = (*qfn2(fn))(qenv(fn), v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-7];
    stack[-2] = v5;
    goto v36;

v35:
    v5 = stack[-2];
    stack[-5] = v5;
    v5 = stack[-1];
    v5 = qcdr(v5);
    stack[-1] = v5;
    goto v90;

v86:
    v5 = stack[-5];
    {
        popv(8);
        fn = elt(env, 6); /* simp!-prop!-condense */
        return (*qfn1(fn))(qenv(fn), v5);
    }
/* error exit handlers */
v42:
    popv(8);
    return nil;
}



/* Code for !*di2q */

static Lisp_Object CC_Hdi2q(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v53, v77;
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
    v71 = v2;
    v53 = v1;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v71; /* varlist */
    v71 = v53;
    stack[-3] = v71;
    v71 = stack[-3];
    if (v71 == nil) goto v138;
    v71 = stack[-3];
    v71 = qcar(v71);
    v53 = v71;
    v77 = qcar(v53);
    v53 = qcdr(v71);
    v71 = (Lisp_Object)17; /* 1 */
    v71 = list2star(v77, v53, v71);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    v71 = ncons(v71);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    stack[-1] = v71;
    stack[-2] = v71;
    goto v180;

v180:
    v71 = stack[-3];
    v71 = qcdr(v71);
    stack[-3] = v71;
    v71 = stack[-3];
    if (v71 == nil) goto v30;
    stack[0] = stack[-1];
    v71 = stack[-3];
    v71 = qcar(v71);
    v53 = v71;
    v77 = qcar(v53);
    v53 = qcdr(v71);
    v71 = (Lisp_Object)17; /* 1 */
    v71 = list2star(v77, v53, v71);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    v71 = ncons(v71);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    v71 = Lrplacd(nil, stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    v71 = stack[-1];
    v71 = qcdr(v71);
    stack[-1] = v71;
    goto v180;

v30:
    v71 = stack[-2];
    v53 = v71;
    goto v60;

v60:
    v71 = qvalue(elt(env, 1)); /* varlist */
    fn = elt(env, 3); /* !*di2q0 */
    v71 = (*qfn2(fn))(qenv(fn), v53, v71);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    { popv(6); return onevalue(v71); }

v138:
    v71 = qvalue(elt(env, 2)); /* nil */
    v53 = v71;
    goto v60;
/* error exit handlers */
v173:
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
    Lisp_Object v171, v19;
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

v184:
    v171 = stack[-1];
    if (!consp(v171)) goto v12;
    v171 = stack[-1];
    v171 = qcar(v171);
    v171 = (consp(v171) ? nil : lisp_true);
    goto v13;

v13:
    if (v171 == nil) goto v93;
    v171 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v171); }

v93:
    v171 = stack[-1];
    v171 = qcar(v171);
    v171 = qcar(v171);
    v19 = qcar(v171);
    v171 = stack[0];
    v171 = Lmember(nil, v19, v171);
    if (v171 == nil) goto v71;
    v171 = stack[-1];
    v171 = qcar(v171);
    v171 = qcar(v171);
    v19 = qcdr(v171);
    v171 = (Lisp_Object)17; /* 1 */
    v171 = (Lisp_Object)greaterp2(v19, v171);
    nil = C_nil;
    if (exception_pending()) goto v18;
    v171 = v171 ? lisp_true : nil;
    env = stack[-2];
    if (!(v171 == nil)) { popv(3); return onevalue(v171); }
    v171 = stack[-1];
    v171 = qcar(v171);
    v19 = qcdr(v171);
    v171 = stack[0];
    fn = elt(env, 3); /* freeofl */
    v171 = (*qfn2(fn))(qenv(fn), v19, v171);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    if (v171 == nil) goto v30;
    v171 = stack[-1];
    v19 = qcdr(v171);
    v171 = stack[0];
    stack[-1] = v19;
    stack[0] = v171;
    goto v184;

v30:
    v171 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v171); }

v71:
    v171 = stack[-1];
    v171 = qcar(v171);
    v171 = qcar(v171);
    v19 = qcar(v171);
    v171 = stack[0];
    fn = elt(env, 3); /* freeofl */
    v171 = (*qfn2(fn))(qenv(fn), v19, v171);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    if (v171 == nil) goto v50;
    v171 = stack[-1];
    v171 = qcar(v171);
    v19 = qcdr(v171);
    v171 = stack[0];
    v171 = CC_nonlnr(env, v19, v171);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    if (!(v171 == nil)) { popv(3); return onevalue(v171); }
    v171 = stack[-1];
    v19 = qcdr(v171);
    v171 = stack[0];
    stack[-1] = v19;
    stack[0] = v171;
    goto v184;

v50:
    v171 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v171); }

v12:
    v171 = qvalue(elt(env, 1)); /* t */
    goto v13;
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for tayexp!-max2 */

static Lisp_Object CC_tayexpKmax2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v67;
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
    v67 = stack[-1];
    v180 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v180 = (*qfn2(fn))(qenv(fn), v67, v180);
    nil = C_nil;
    if (exception_pending()) goto v138;
    if (v180 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v138:
    popv(2);
    return nil;
}



/* Code for cl_bnfsimpl */

static Lisp_Object CC_cl_bnfsimpl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v67, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_bnfsimpl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v67 = v1;
    v93 = v0;
/* end of prologue */
    v180 = qvalue(elt(env, 1)); /* !*rlbnfsac */
    if (v180 == nil) return onevalue(v93);
    v180 = v93;
    {
        fn = elt(env, 2); /* cl_sac */
        return (*qfn2(fn))(qenv(fn), v180, v67);
    }
}



/* Code for gb_buch!-ev_divides!? */

static Lisp_Object CC_gb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gb_buch-ev_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v1;
    v60 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v57, v60);
    }
}



/* Code for bc_fd */

static Lisp_Object CC_bc_fd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v60;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_fd");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v59 = v0;
/* end of prologue */
    v60 = v59;
    v59 = (Lisp_Object)17; /* 1 */
    return cons(v60, v59);
}



/* Code for matrix_rows */

static Lisp_Object CC_matrix_rows(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v185;
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
    v166 = stack[0];
    if (v166 == nil) goto v11;
    v166 = elt(env, 1); /* "<matrixrow>" */
    fn = elt(env, 5); /* printout */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    v185 = qvalue(elt(env, 2)); /* indent */
    v166 = (Lisp_Object)49; /* 3 */
    v166 = plus2(v185, v166);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    qvalue(elt(env, 2)) = v166; /* indent */
    v166 = stack[0];
    v166 = qcar(v166);
    fn = elt(env, 6); /* row */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    v185 = qvalue(elt(env, 2)); /* indent */
    v166 = (Lisp_Object)49; /* 3 */
    v166 = difference2(v185, v166);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    qvalue(elt(env, 2)) = v166; /* indent */
    v166 = elt(env, 3); /* "</matrixrow>" */
    fn = elt(env, 5); /* printout */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    v166 = stack[0];
    v166 = qcdr(v166);
    v166 = CC_matrix_rows(env, v166);
    nil = C_nil;
    if (exception_pending()) goto v31;
    goto v11;

v11:
    v166 = nil;
    { popv(2); return onevalue(v166); }
/* error exit handlers */
v31:
    popv(2);
    return nil;
}



/* Code for degreef */

static Lisp_Object CC_degreef(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v51;
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
    v26 = stack[-1];
    if (!consp(v26)) goto v12;
    v26 = stack[-1];
    v26 = qcar(v26);
    v26 = (consp(v26) ? nil : lisp_true);
    goto v13;

v13:
    if (v26 == nil) goto v93;
    v26 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v26); }

v93:
    v26 = stack[-1];
    v26 = qcar(v26);
    v26 = qcar(v26);
    v51 = qcar(v26);
    v26 = stack[0];
    if (v51 == v26) goto v180;
    v26 = stack[-1];
    v26 = qcar(v26);
    v51 = qcdr(v26);
    v26 = stack[0];
    stack[-2] = CC_degreef(env, v51, v26);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    v26 = stack[-1];
    v51 = qcdr(v26);
    v26 = stack[0];
    v26 = CC_degreef(env, v51, v26);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    {
        Lisp_Object v167 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* max */
        return (*qfn2(fn))(qenv(fn), v167, v26);
    }

v180:
    v26 = stack[-1];
    v26 = qcar(v26);
    v26 = qcar(v26);
    v26 = qcdr(v26);
    { popv(4); return onevalue(v26); }

v12:
    v26 = qvalue(elt(env, 1)); /* t */
    goto v13;
/* error exit handlers */
v159:
    popv(4);
    return nil;
}



/* Code for delyzz */

static Lisp_Object CC_delyzz(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63, v89;
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
    v89 = nil;
    goto v60;

v60:
    v63 = stack[-1];
    v62 = stack[0];
    v62 = qcar(v62);
    v62 = qcar(v62);
    if (equal(v63, v62)) goto v93;
    v62 = stack[0];
    v62 = qcar(v62);
    v63 = v89;
    v62 = cons(v62, v63);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v89 = v62;
    v62 = stack[0];
    v62 = qcdr(v62);
    stack[0] = v62;
    goto v60;

v93:
    v63 = v89;
    v62 = stack[0];
    v62 = qcdr(v62);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v63, v62);
    }
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for evgradlexcomp */

static Lisp_Object CC_evgradlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v165;
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

v11:
    v78 = stack[-2];
    if (v78 == nil) goto v13;
    v78 = stack[-1];
    if (v78 == nil) goto v57;
    v78 = stack[-2];
    v165 = qcar(v78);
    v78 = stack[-1];
    v78 = qcar(v78);
    v78 = Leqn(nil, v165, v78);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-4];
    if (v78 == nil) goto v187;
    v78 = stack[-2];
    v78 = qcdr(v78);
    stack[-2] = v78;
    v78 = stack[-1];
    v78 = qcdr(v78);
    stack[-1] = v78;
    goto v11;

v187:
    v78 = stack[-2];
    fn = elt(env, 2); /* evtdeg */
    stack[0] = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-4];
    v78 = stack[-1];
    fn = elt(env, 2); /* evtdeg */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v78;
    v165 = stack[-3];
    v78 = stack[0];
    v78 = Leqn(nil, v165, v78);
    nil = C_nil;
    if (exception_pending()) goto v147;
    if (v78 == nil) goto v73;
    v78 = stack[-2];
    v165 = qcar(v78);
    v78 = stack[-1];
    v78 = qcar(v78);
    if (((int32_t)(v165)) > ((int32_t)(v78))) goto v175;
    v78 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v78); }

v175:
    v78 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v78); }

v73:
    v165 = stack[-3];
    v78 = stack[0];
    if (((int32_t)(v165)) > ((int32_t)(v78))) goto v188;
    v78 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v78); }

v188:
    v78 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v78); }

v57:
    v78 = elt(env, 1); /* (0) */
    stack[-1] = v78;
    goto v11;

v13:
    v78 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v78); }
/* error exit handlers */
v147:
    popv(5);
    return nil;
}



/* Code for xriterion_1 */

static Lisp_Object MS_CDECL CC_xriterion_1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v122, v121;
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

v184:
    v197 = stack[-1];
    if (v197 == nil) goto v23;
    v197 = stack[-2];
    v197 = qcdr(v197);
    v122 = qcar(v197);
    v197 = elt(env, 2); /* spoly_pair */
    if (v122 == v197) goto v94;
    v197 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v197); }

v94:
    v197 = stack[-1];
    v197 = qcar(v197);
    stack[-3] = v197;
    v122 = stack[-3];
    v197 = stack[-2];
    v197 = qcdr(v197);
    v197 = qcdr(v197);
    v197 = qcar(v197);
    if (equal(v122, v197)) goto v198;
    v122 = stack[-3];
    v197 = stack[-2];
    v197 = qcdr(v197);
    v197 = qcdr(v197);
    v197 = qcdr(v197);
    v197 = qcar(v197);
    if (equal(v122, v197)) goto v199;
    v197 = stack[-3];
    fn = elt(env, 7); /* xval */
    v122 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    v197 = stack[-2];
    v197 = qcar(v197);
    fn = elt(env, 8); /* xdiv */
    v197 = (*qfn2(fn))(qenv(fn), v122, v197);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    if (v197 == nil) goto v27;
    v122 = stack[-3];
    v197 = stack[-2];
    v197 = qcdr(v197);
    v197 = qcdr(v197);
    v197 = qcar(v197);
    fn = elt(env, 9); /* make_spoly_pair */
    v197 = (*qfn2(fn))(qenv(fn), v122, v197);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    v122 = v197;
    v197 = v122;
    if (v197 == nil) goto v201;
    v197 = stack[0];
    fn = elt(env, 10); /* find_item */
    v197 = (*qfn2(fn))(qenv(fn), v122, v197);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    v197 = (v197 == nil ? lisp_true : nil);
    goto v58;

v58:
    if (v197 == nil) goto v161;
    v122 = stack[-3];
    v197 = stack[-2];
    v197 = qcdr(v197);
    v197 = qcdr(v197);
    v197 = qcdr(v197);
    v197 = qcar(v197);
    fn = elt(env, 9); /* make_spoly_pair */
    v197 = (*qfn2(fn))(qenv(fn), v122, v197);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    v122 = v197;
    v197 = v122;
    if (v197 == nil) goto v128;
    v197 = stack[0];
    fn = elt(env, 10); /* find_item */
    v197 = (*qfn2(fn))(qenv(fn), v122, v197);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    v197 = (v197 == nil ? lisp_true : nil);
    goto v169;

v169:
    if (v197 == nil) goto v171;
    v197 = qvalue(elt(env, 4)); /* !*trxideal */
    if (v197 == nil) goto v6;
    v197 = elt(env, 5); /* "criterion 1 hit" */
    fn = elt(env, 11); /* eval */
    v121 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    v122 = qvalue(elt(env, 1)); /* nil */
    v197 = elt(env, 6); /* last */
    fn = elt(env, 12); /* assgnpri */
    v197 = (*qfnn(fn))(qenv(fn), 3, v121, v122, v197);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    goto v6;

v6:
    v197 = qvalue(elt(env, 3)); /* t */
    goto v164;

v164:
    if (!(v197 == nil)) { popv(5); return onevalue(v197); }
    v121 = stack[-2];
    v197 = stack[-1];
    v122 = qcdr(v197);
    v197 = stack[0];
    stack[-2] = v121;
    stack[-1] = v122;
    stack[0] = v197;
    goto v184;

v171:
    v197 = qvalue(elt(env, 1)); /* nil */
    goto v164;

v128:
    v197 = qvalue(elt(env, 3)); /* t */
    goto v169;

v161:
    v197 = qvalue(elt(env, 1)); /* nil */
    goto v164;

v201:
    v197 = qvalue(elt(env, 3)); /* t */
    goto v58;

v27:
    v197 = qvalue(elt(env, 1)); /* nil */
    goto v164;

v199:
    v197 = qvalue(elt(env, 1)); /* nil */
    goto v164;

v198:
    v197 = qvalue(elt(env, 1)); /* nil */
    goto v164;

v23:
    v197 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v197); }
/* error exit handlers */
v200:
    popv(5);
    return nil;
}



/* Code for fl2bf */

static Lisp_Object CC_fl2bf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v32;
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
    v34 = v0;
/* end of prologue */
    fn = elt(env, 3); /* frexp */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    stack[-2] = v34;
    v34 = stack[-2];
    v34 = qcdr(v34);
    v32 = stack[-2];
    v32 = qcar(v32);
    stack[-2] = v32;
    stack[0] = v34;
    v32 = (Lisp_Object)33; /* 2 */
    v34 = qvalue(elt(env, 1)); /* !!nbfpd */
    v34 = Lexpt(nil, v32, v34);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    v34 = times2(stack[0], v34);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    v34 = Ltruncate(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    stack[-1] = elt(env, 2); /* !:rd!: */
    stack[0] = v34;
    v32 = stack[-2];
    v34 = qvalue(elt(env, 1)); /* !!nbfpd */
    v34 = difference2(v32, v34);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    v34 = list2star(stack[-1], stack[0], v34);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v34);
    }
/* error exit handlers */
v48:
    popv(4);
    return nil;
}



/* Code for apply_e */

static Lisp_Object CC_apply_e(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v37;
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
    v36 = v0;
/* end of prologue */
    v37 = v36;
    v36 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* apply */
    v37 = (*qfn2(fn))(qenv(fn), v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[0];
    v36 = v37;
    v37 = integerp(v37);
    if (!(v37 == nil)) { popv(1); return onevalue(v36); }
    v36 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v36 == nil)) goto v93;
    v36 = elt(env, 3); /* "randpoly expons function must return an integer" 
*/
    fn = elt(env, 5); /* lprie */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[0];
    goto v93;

v93:
    v36 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v38;
    v36 = nil;
    { popv(1); return onevalue(v36); }
/* error exit handlers */
v38:
    popv(1);
    return nil;
}



/* Code for gpargp */

static Lisp_Object CC_gpargp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90;
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
    v90 = stack[0];
    v90 = Lstringp(nil, v90);
    env = stack[-1];
    if (!(v90 == nil)) { popv(2); return onevalue(v90); }
    v90 = stack[0];
    fn = elt(env, 1); /* gpexpp */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    if (!(v90 == nil)) { popv(2); return onevalue(v90); }
    v90 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* gplogexpp */
        return (*qfn1(fn))(qenv(fn), v90);
    }
/* error exit handlers */
v70:
    popv(2);
    return nil;
}



/* Code for getphystypeall */

static Lisp_Object CC_getphystypeall(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63;
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
    v63 = (Lisp_Object)1; /* 0 */
    v62 = stack[0];
    fn = elt(env, 3); /* deleteall */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-2];
    fn = elt(env, 4); /* collectphystype */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-2];
    v63 = v62;
    if (v62 == nil) goto v14;
    v62 = v63;
    v62 = qcdr(v62);
    if (v62 == nil) goto v79;
    stack[-1] = elt(env, 0); /* getphystypeall */
    v63 = elt(env, 2); /* "PHYSOP type mismatch in" */
    v62 = stack[0];
    v62 = list2(v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-2];
    fn = elt(env, 5); /* rederr2 */
    v62 = (*qfn2(fn))(qenv(fn), stack[-1], v62);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v62 = nil;
    { popv(3); return onevalue(v62); }

v79:
    v62 = v63;
    v62 = qcar(v62);
    { popv(3); return onevalue(v62); }

v14:
    v62 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v62); }
/* error exit handlers */
v34:
    popv(3);
    return nil;
}



/* Code for gvarlis1 */

static Lisp_Object CC_gvarlis1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v80;
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
    goto v14;

v14:
    v48 = stack[-1];
    if (v48 == nil) goto v13;
    v48 = stack[-1];
    v80 = qcar(v48);
    v48 = stack[0];
    fn = elt(env, 1); /* gvar1 */
    v80 = (*qfn2(fn))(qenv(fn), v80, v48);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    v48 = stack[-2];
    v48 = cons(v80, v48);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    stack[-2] = v48;
    v48 = stack[-1];
    v48 = qcdr(v48);
    stack[-1] = v48;
    goto v14;

v13:
    v48 = stack[0];
    v80 = v48;
    goto v12;

v12:
    v48 = stack[-2];
    if (v48 == nil) { popv(4); return onevalue(v80); }
    v48 = stack[-2];
    v48 = qcar(v48);
    fn = elt(env, 2); /* union */
    v48 = (*qfn2(fn))(qenv(fn), v48, v80);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    v80 = v48;
    v48 = stack[-2];
    v48 = qcdr(v48);
    stack[-2] = v48;
    goto v12;
/* error exit handlers */
v136:
    popv(4);
    return nil;
}



/* Code for general!-horner!-rule!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKhornerKruleKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v160, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40, v41, v42, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "general-horner-rule-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-horner-rule-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push5(v160,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v160);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v160;
    stack[-3] = v3;
    stack[-4] = v2;
    v41 = v1;
    v42 = v0;
/* end of prologue */

v184:
    v39 = stack[-4];
    if (!consp(v39)) goto v70;
    v39 = stack[-4];
    v39 = qcar(v39);
    v39 = (consp(v39) ? nil : lisp_true);
    goto v66;

v66:
    if (v39 == nil) goto v36;
    v39 = qvalue(elt(env, 1)); /* t */
    goto v60;

v60:
    if (v39 == nil) goto v53;
    v39 = stack[-3];
    if (v39 == nil) goto v34;
    v39 = stack[-3];
    v39 = (Lisp_Object)zerop(v39);
    v39 = v39 ? lisp_true : nil;
    env = stack[-6];
    goto v33;

v33:
    if (!(v39 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[0] = v42;
    v39 = stack[-3];
    v40 = v41;
    fn = elt(env, 2); /* general!-expt!-mod!-p */
    v39 = (*qfn2(fn))(qenv(fn), v39, v40);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-6];
    fn = elt(env, 3); /* general!-times!-mod!-p */
    v39 = (*qfn2(fn))(qenv(fn), stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-6];
    v42 = v39;
    v39 = stack[-4];
    v40 = v42;
    {
        popv(7);
        fn = elt(env, 4); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v39, v40);
    }

v34:
    v39 = qvalue(elt(env, 1)); /* t */
    goto v33;

v53:
    v39 = stack[-4];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v39 = qcdr(v39);
    stack[-5] = v39;
    v39 = stack[-3];
    if (v39 == nil) goto v64;
    v39 = stack[-3];
    v39 = (Lisp_Object)zerop(v39);
    v39 = v39 ? lisp_true : nil;
    env = stack[-6];
    goto v49;

v49:
    if (v39 == nil) goto v54;
    v39 = stack[-4];
    v39 = qcar(v39);
    v39 = qcdr(v39);
    v42 = v39;
    goto v25;

v25:
    v41 = stack[-5];
    v39 = stack[-4];
    v43 = qcdr(v39);
    v40 = stack[-3];
    v39 = stack[-2];
    stack[-4] = v43;
    stack[-3] = v40;
    stack[-2] = v39;
    goto v184;

v54:
    v39 = stack[-4];
    v39 = qcar(v39);
    stack[-1] = qcdr(v39);
    stack[0] = v42;
    v40 = stack[-3];
    v39 = stack[-5];
    v39 = (Lisp_Object)(int32_t)((int32_t)v41 - (int32_t)v39 + TAG_FIXNUM);
    fn = elt(env, 2); /* general!-expt!-mod!-p */
    v39 = (*qfn2(fn))(qenv(fn), v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-6];
    fn = elt(env, 3); /* general!-times!-mod!-p */
    v39 = (*qfn2(fn))(qenv(fn), stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-6];
    fn = elt(env, 4); /* general!-plus!-mod!-p */
    v39 = (*qfn2(fn))(qenv(fn), stack[-1], v39);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-6];
    v42 = v39;
    goto v25;

v64:
    v39 = qvalue(elt(env, 1)); /* t */
    goto v49;

v36:
    v39 = stack[-4];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v40 = qcar(v39);
    v39 = stack[-2];
    v39 = (equal(v40, v39) ? lisp_true : nil);
    v39 = (v39 == nil ? lisp_true : nil);
    goto v60;

v70:
    v39 = qvalue(elt(env, 1)); /* t */
    goto v66;
/* error exit handlers */
v199:
    popv(7);
    return nil;
}



/* Code for reduce!-eival!-powers */

static Lisp_Object CC_reduceKeivalKpowers(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v88, v135, v159;
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
    v135 = v1;
    v159 = v0;
/* end of prologue */
    v174 = v135;
    if (!consp(v174)) goto v86;
    v174 = v135;
    v174 = qcar(v174);
    v174 = (consp(v174) ? nil : lisp_true);
    goto v57;

v57:
    if (v174 == nil) goto v83;
    v174 = qvalue(elt(env, 1)); /* t */
    goto v13;

v13:
    if (v174 == nil) goto v163;
    v88 = v135;
    v174 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v88, v174);

v163:
    stack[0] = v159;
    v88 = v135;
    v174 = (Lisp_Object)17; /* 1 */
    v174 = cons(v88, v174);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-1];
    {
        Lisp_Object v157 = stack[0];
        popv(2);
        fn = elt(env, 2); /* reduce!-eival!-powers1 */
        return (*qfn2(fn))(qenv(fn), v157, v174);
    }

v83:
    v174 = v135;
    v174 = qcar(v174);
    v174 = qcar(v174);
    v88 = qcar(v174);
    v174 = v159;
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = (v88 == v174 ? lisp_true : nil);
    v174 = (v174 == nil ? lisp_true : nil);
    goto v13;

v86:
    v174 = qvalue(elt(env, 1)); /* t */
    goto v57;
/* error exit handlers */
v188:
    popv(2);
    return nil;
}



/* Code for sfto_pdecf */

static Lisp_Object CC_sfto_pdecf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v157;
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
    v188 = stack[0];
    if (!consp(v188)) goto v86;
    v188 = stack[0];
    v188 = qcar(v188);
    v188 = (consp(v188) ? nil : lisp_true);
    goto v57;

v57:
    if (v188 == nil) goto v13;
    v157 = (Lisp_Object)17; /* 1 */
    v188 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v157, v188);

v13:
    v188 = stack[0];
    fn = elt(env, 2); /* sfto_ucontentf */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    stack[-1] = v188;
    v188 = stack[-1];
    v188 = CC_sfto_pdecf(env, v188);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    stack[-2] = v188;
    v157 = stack[0];
    v188 = stack[-1];
    fn = elt(env, 3); /* quotf */
    v188 = (*qfn2(fn))(qenv(fn), v157, v188);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    fn = elt(env, 4); /* sfto_updecf */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    stack[-1] = v188;
    v188 = stack[-2];
    v157 = qcar(v188);
    v188 = stack[-1];
    v188 = qcar(v188);
    fn = elt(env, 5); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v157, v188);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    v188 = stack[-2];
    v157 = qcdr(v188);
    v188 = stack[-1];
    v188 = qcdr(v188);
    fn = elt(env, 5); /* multf */
    v188 = (*qfn2(fn))(qenv(fn), v157, v188);
    nil = C_nil;
    if (exception_pending()) goto v28;
    {
        Lisp_Object v29 = stack[0];
        popv(4);
        return cons(v29, v188);
    }

v86:
    v188 = qvalue(elt(env, 1)); /* t */
    goto v57;
/* error exit handlers */
v28:
    popv(4);
    return nil;
}



/* Code for valuecoefft */

static Lisp_Object MS_CDECL CC_valuecoefft(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v30, v92, v163, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "valuecoefft");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for valuecoefft");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v92 = v2;
    v163 = v1;
    v48 = v0;
/* end of prologue */

v23:
    v32 = v92;
    if (v32 == nil) goto v12;
    v30 = v48;
    v32 = v92;
    v32 = qcar(v32);
    if (v30 == v32) goto v36;
    v32 = v163;
    v32 = qcdr(v32);
    v163 = v32;
    v32 = v92;
    v32 = qcdr(v32);
    v92 = v32;
    goto v23;

v36:
    v32 = v163;
    v30 = qcar(v32);
    v32 = (Lisp_Object)1; /* 0 */
    if (v30 == v32) goto v61;
    v32 = v163;
    v32 = qcar(v32);
    return onevalue(v32);

v61:
    v32 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v32);

v12:
    v32 = elt(env, 1); /* "Valuecoefft - no value" */
    {
        fn = elt(env, 3); /* interr */
        return (*qfn1(fn))(qenv(fn), v32);
    }
}



/* Code for get_char_value */

static Lisp_Object CC_get_char_value(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v56;
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
    v56 = v0;
/* end of prologue */
    stack[-1] = nil;
    v50 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v50;
    v50 = v56;
    v50 = qcdr(v50);
    stack[0] = v50;
    goto v86;

v86:
    v50 = stack[-3];
    if (v50 == nil) goto v139;
    v50 = qvalue(elt(env, 1)); /* nil */
    goto v180;

v180:
    if (v50 == nil) goto v57;
    v50 = stack[0];
    v50 = qcar(v50);
    v56 = qcar(v50);
    v50 = stack[-2];
    if (!(equal(v56, v50))) goto v185;
    v50 = stack[0];
    v50 = qcar(v50);
    v50 = qcdr(v50);
    v50 = qcar(v50);
    stack[-1] = v50;
    v50 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v50;
    goto v185;

v185:
    v50 = stack[0];
    v50 = qcdr(v50);
    stack[0] = v50;
    goto v86;

v57:
    v50 = stack[-3];
    if (!(v50 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v50 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v50 == nil)) goto v188;
    v50 = elt(env, 4); /* "error in get character element" */
    fn = elt(env, 5); /* lprie */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    goto v188;

v188:
    v50 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v50 = nil;
    { popv(5); return onevalue(v50); }

v139:
    v50 = stack[0];
    v56 = Llength(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v50 = (Lisp_Object)1; /* 0 */
    v50 = (Lisp_Object)greaterp2(v56, v50);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v50 = v50 ? lisp_true : nil;
    env = stack[-4];
    goto v180;
/* error exit handlers */
v78:
    popv(5);
    return nil;
}



/* Code for multiminus */

static Lisp_Object CC_multiminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v139;
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
    v138 = stack[0];
    v138 = qcar(v138);
    fn = elt(env, 1); /* expression */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    v138 = stack[0];
    v139 = Llength(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    v138 = (Lisp_Object)33; /* 2 */
    if (!(v139 == v138)) goto v13;
    v138 = stack[0];
    v138 = qcdr(v138);
    v138 = qcar(v138);
    fn = elt(env, 1); /* expression */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v61;
    goto v13;

v13:
    v138 = nil;
    { popv(2); return onevalue(v138); }
/* error exit handlers */
v61:
    popv(2);
    return nil;
}



/* Code for groebbuchcrit4t */

static Lisp_Object CC_groebbuchcrit4t(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v206;
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

v11:
    v175 = stack[-1];
    if (v175 == nil) goto v57;
    v175 = stack[0];
    v175 = (v175 == nil ? lisp_true : nil);
    goto v60;

v60:
    if (v175 == nil) goto v35;
    v175 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v175); }

v35:
    v175 = stack[-1];
    v206 = qcar(v175);
    v175 = (Lisp_Object)1; /* 0 */
    if (v206 == v175) goto v89;
    v175 = stack[0];
    v206 = qcar(v175);
    v175 = (Lisp_Object)1; /* 0 */
    v175 = Lneq(nil, v206, v175);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    goto v139;

v139:
    if (v175 == nil) goto v30;
    v175 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v175); }

v30:
    v175 = stack[-1];
    v175 = qcdr(v175);
    stack[-1] = v175;
    v175 = stack[0];
    v175 = qcdr(v175);
    stack[0] = v175;
    goto v11;

v89:
    v175 = qvalue(elt(env, 2)); /* nil */
    goto v139;

v57:
    v175 = qvalue(elt(env, 1)); /* t */
    goto v60;
/* error exit handlers */
v162:
    popv(3);
    return nil;
}



/* Code for indxsymp */

static Lisp_Object CC_indxsymp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v185;
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

v184:
    v166 = stack[0];
    if (v166 == nil) goto v11;
    v166 = stack[0];
    v185 = qcar(v166);
    v166 = stack[-1];
    v166 = Lapply1(nil, v185, v166);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    if (v166 == nil) goto v86;
    v185 = stack[-1];
    v166 = stack[0];
    v166 = qcdr(v166);
    stack[-1] = v185;
    stack[0] = v166;
    goto v184;

v86:
    v166 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v166); }

v11:
    v166 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v166); }
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for calc_coeff */

static Lisp_Object CC_calc_coeff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v175, v206;
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
    v81 = stack[-1];
    if (v81 == nil) goto v11;
    v81 = stack[-1];
    v175 = qcar(v81);
    v81 = stack[0];
    fn = elt(env, 1); /* calc_world */
    v81 = (*qfn2(fn))(qenv(fn), v175, v81);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    v206 = v81;
    v175 = v206;
    v81 = (Lisp_Object)1; /* 0 */
    if (v175 == v81) goto v139;
    stack[-2] = v206;
    v81 = stack[-1];
    v175 = qcdr(v81);
    v81 = stack[0];
    v81 = CC_calc_coeff(env, v175, v81);
    nil = C_nil;
    if (exception_pending()) goto v178;
    {
        Lisp_Object v186 = stack[-2];
        popv(4);
        return cons(v186, v81);
    }

v139:
    v81 = (Lisp_Object)1; /* 0 */
    popv(4);
    return ncons(v81);

v11:
    v81 = (Lisp_Object)17; /* 1 */
    popv(4);
    return ncons(v81);
/* error exit handlers */
v178:
    popv(4);
    return nil;
}



/* Code for symbvarlst */

static Lisp_Object MS_CDECL CC_symbvarlst(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "symbvarlst");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbvarlst");
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
    v74 = v2;
    stack[-4] = v1;
    v54 = v0;
/* end of prologue */
    v75 = v74;
    v74 = elt(env, 1); /* symbolic */
    if (v75 == v74) goto v59;
    v74 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v74); }

v59:
    v74 = v54;
    stack[-5] = v74;
    goto v13;

v13:
    v74 = stack[-5];
    if (v74 == nil) goto v139;
    v74 = stack[-5];
    v74 = qcar(v74);
    v74 = Lconsp(nil, v74);
    env = stack[-6];
    if (v74 == nil) goto v79;
    v74 = stack[-5];
    v74 = qcar(v74);
    v74 = qcar(v74);
    goto v37;

v37:
    stack[0] = v74;
    v74 = stack[0];
    v74 = Lsymbol_specialp(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-6];
    if (v74 == nil) goto v30;
    v74 = qvalue(elt(env, 2)); /* nil */
    goto v32;

v32:
    if (v74 == nil) goto v63;
    v74 = qvalue(elt(env, 4)); /* !*msg */
    if (v74 == nil) goto v63;
    stack[-3] = elt(env, 5); /* "***" */
    stack[-2] = elt(env, 6); /* "local variable" */
    stack[-1] = stack[0];
    stack[0] = elt(env, 7); /* "in procedure" */
    v75 = qvalue(elt(env, 8)); /* fname!* */
    v74 = elt(env, 9); /* "not used" */
    v74 = list2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-6];
    v74 = list3star(stack[-2], stack[-1], stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-6];
    fn = elt(env, 10); /* lpriw */
    v74 = (*qfn2(fn))(qenv(fn), stack[-3], v74);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-6];
    goto v63;

v63:
    v74 = stack[-5];
    v74 = qcdr(v74);
    stack[-5] = v74;
    goto v13;

v30:
    v74 = stack[0];
    v74 = Lsymbol_globalp(nil, v74);
    env = stack[-6];
    if (v74 == nil) goto v51;
    v74 = qvalue(elt(env, 2)); /* nil */
    goto v32;

v51:
    v75 = stack[0];
    v74 = stack[-4];
    v74 = Lsmemq(nil, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-6];
    if (v74 == nil) goto v186;
    v74 = qvalue(elt(env, 2)); /* nil */
    goto v32;

v186:
    v74 = qvalue(elt(env, 3)); /* !*novarmsg */
    v74 = (v74 == nil ? lisp_true : nil);
    goto v32;

v79:
    v74 = stack[-5];
    v74 = qcar(v74);
    goto v37;

v139:
    v74 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v74); }
/* error exit handlers */
v15:
    popv(7);
    return nil;
}



/* Code for innprodpex */

static Lisp_Object CC_innprodpex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v55;
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

v184:
    v179 = stack[-1];
    if (v179 == nil) goto v11;
    v55 = stack[-2];
    v179 = stack[-1];
    v179 = qcar(v179);
    v179 = qcar(v179);
    fn = elt(env, 2); /* innprodp2 */
    v179 = (*qfn2(fn))(qenv(fn), v55, v179);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    v55 = v179;
    v179 = v55;
    if (v179 == nil) goto v174;
    v179 = v55;
    stack[-3] = qcdr(v179);
    v179 = v55;
    v179 = qcar(v179);
    if (v179 == nil) goto v32;
    v179 = stack[-1];
    v179 = qcar(v179);
    v179 = qcdr(v179);
    fn = elt(env, 3); /* negf */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    stack[0] = v179;
    goto v81;

v81:
    v55 = stack[-2];
    v179 = stack[-1];
    v179 = qcdr(v179);
    v179 = CC_innprodpex(env, v55, v179);
    nil = C_nil;
    if (exception_pending()) goto v161;
    {
        Lisp_Object v71 = stack[-3];
        Lisp_Object v53 = stack[0];
        popv(5);
        return acons(v71, v53, v179);
    }

v32:
    v179 = stack[-1];
    v179 = qcar(v179);
    v179 = qcdr(v179);
    stack[0] = v179;
    goto v81;

v174:
    v55 = stack[-2];
    v179 = stack[-1];
    v179 = qcdr(v179);
    stack[-2] = v55;
    stack[-1] = v179;
    goto v184;

v11:
    v179 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v179); }
/* error exit handlers */
v161:
    popv(5);
    return nil;
}



/* Code for simp!-prop!-condense */

static Lisp_Object CC_simpKpropKcondense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v29;
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
    v29 = stack[-3];
    v28 = elt(env, 1); /* lambda_lqgavy_6 */
    fn = elt(env, 3); /* sort */
    v28 = (*qfn2(fn))(qenv(fn), v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-3] = v28;
    goto v70;

v70:
    v28 = stack[-3];
    if (v28 == nil) goto v66;
    v28 = stack[-3];
    v28 = qcar(v28);
    stack[-4] = v28;
    v28 = stack[-3];
    v28 = qcdr(v28);
    stack[-3] = v28;
    v29 = stack[-4];
    v28 = stack[-2];
    v28 = cons(v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-2] = v28;
    v28 = stack[-3];
    stack[-1] = v28;
    goto v79;

v79:
    v28 = stack[-1];
    if (v28 == nil) goto v70;
    v28 = stack[-1];
    v28 = qcar(v28);
    stack[0] = v28;
    v29 = stack[-4];
    v28 = stack[0];
    fn = elt(env, 4); /* subsetp */
    v28 = (*qfn2(fn))(qenv(fn), v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    if (v28 == nil) goto v163;
    v29 = stack[0];
    v28 = stack[-3];
    v28 = Ldelete(nil, v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-3] = v28;
    goto v163;

v163:
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v79;

v66:
    v28 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* ordn */
        return (*qfn1(fn))(qenv(fn), v28);
    }
/* error exit handlers */
v77:
    popv(6);
    return nil;
}



/* Code for lambda_lqgavy_6 */

static Lisp_Object CC_lambda_lqgavy_6(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqgavy_6");
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
    stack[-1] = Llength(nil, v86);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    v86 = stack[0];
    v86 = Llength(nil, v86);
    nil = C_nil;
    if (exception_pending()) goto v70;
    {
        Lisp_Object v177 = stack[-1];
        popv(3);
        return Llessp(nil, v177, v86);
    }
/* error exit handlers */
v70:
    popv(3);
    return nil;
}



/* Code for pcdiv */

static Lisp_Object CC_pcdiv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v50;
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
    v29 = v0;
/* end of prologue */
    stack[-5] = v29;
    v29 = stack[-5];
    if (v29 == nil) goto v57;
    v29 = stack[-5];
    v29 = qcar(v29);
    v50 = v29;
    v29 = v50;
    stack[0] = qcar(v29);
    v29 = v50;
    v50 = qcdr(v29);
    v29 = stack[-4];
    fn = elt(env, 2); /* cdiv */
    v29 = (*qfn2(fn))(qenv(fn), v50, v29);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v29 = cons(stack[0], v29);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v29 = ncons(v29);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    stack[-2] = v29;
    stack[-3] = v29;
    goto v13;

v13:
    v29 = stack[-5];
    v29 = qcdr(v29);
    stack[-5] = v29;
    v29 = stack[-5];
    if (v29 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v29 = stack[-5];
    v29 = qcar(v29);
    v50 = v29;
    v29 = v50;
    stack[0] = qcar(v29);
    v29 = v50;
    v50 = qcdr(v29);
    v29 = stack[-4];
    fn = elt(env, 2); /* cdiv */
    v29 = (*qfn2(fn))(qenv(fn), v50, v29);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v29 = cons(stack[0], v29);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v29 = ncons(v29);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v29 = Lrplacd(nil, stack[-1], v29);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v29 = stack[-2];
    v29 = qcdr(v29);
    stack[-2] = v29;
    goto v13;

v57:
    v29 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v29); }
/* error exit handlers */
v165:
    popv(7);
    return nil;
}



/* Code for subf */

static Lisp_Object CC_subf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v217;
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
    v216 = qvalue(elt(env, 2)); /* nil */
    v216 = ncons(v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    qvalue(elt(env, 1)) = v216; /* alglist!* */
    v216 = stack[-7];
    if (!consp(v216)) goto v177;
    v216 = stack[-7];
    v216 = qcar(v216);
    v216 = (consp(v216) ? nil : lisp_true);
    goto v70;

v70:
    if (v216 == nil) goto v90;
    v216 = stack[-7];
    fn = elt(env, 8); /* !*d2q */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    goto v13;

v13:
    qvalue(elt(env, 1)) = stack[-8]; /* alglist!* */
    { popv(10); return onevalue(v216); }

v90:
    v216 = qvalue(elt(env, 4)); /* ncmp!* */
    if (v216 == nil) goto v33;
    v216 = stack[-7];
    fn = elt(env, 9); /* noncomexpf */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    if (v216 == nil) goto v33;
    v217 = stack[-7];
    v216 = stack[-6];
    fn = elt(env, 10); /* subf1 */
    v216 = (*qfn2(fn))(qenv(fn), v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    goto v13;

v33:
    v216 = stack[-6];
    stack[-3] = v216;
    v216 = stack[-3];
    if (v216 == nil) goto v178;
    v216 = stack[-3];
    v216 = qcar(v216);
    v216 = qcar(v216);
    v216 = ncons(v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    stack[-1] = v216;
    stack[-2] = v216;
    goto v206;

v206:
    v216 = stack[-3];
    v216 = qcdr(v216);
    stack[-3] = v216;
    v216 = stack[-3];
    if (v216 == nil) goto v55;
    stack[0] = stack[-1];
    v216 = stack[-3];
    v216 = qcar(v216);
    v216 = qcar(v216);
    v216 = ncons(v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    v216 = Lrplacd(nil, stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    v216 = stack[-1];
    v216 = qcdr(v216);
    stack[-1] = v216;
    goto v206;

v55:
    v216 = stack[-2];
    stack[0] = v216;
    goto v58;

v58:
    v217 = stack[-7];
    v216 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 11); /* kernord */
    v216 = (*qfn2(fn))(qenv(fn), v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    fn = elt(env, 12); /* intersection */
    v216 = (*qfn2(fn))(qenv(fn), stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    v216 = Lreverse(nil, v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    stack[0] = v216;
    v216 = stack[0];
    fn = elt(env, 13); /* setkorder */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    stack[0] = v216;
    v216 = stack[-7];
    fn = elt(env, 14); /* reorder */
    v217 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    v216 = stack[-6];
    fn = elt(env, 10); /* subf1 */
    v216 = (*qfn2(fn))(qenv(fn), v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    stack[-7] = v216;
    goto v170;

v170:
    v217 = stack[-7];
    v216 = stack[-4];
    v216 = Lmember(nil, v217, v216);
    if (v216 == nil) goto v202;
    v216 = qvalue(elt(env, 2)); /* nil */
    goto v74;

v74:
    if (v216 == nil) goto v183;
    v217 = stack[-7];
    v216 = stack[-4];
    v216 = cons(v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    stack[-4] = v216;
    v216 = stack[-5];
    fn = elt(env, 15); /* simp */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    stack[-7] = v216;
    goto v170;

v183:
    v216 = stack[0];
    fn = elt(env, 13); /* setkorder */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    v216 = stack[-7];
    v216 = qcar(v216);
    fn = elt(env, 14); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    v216 = stack[-7];
    v216 = qcdr(v216);
    fn = elt(env, 14); /* reorder */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    v216 = cons(stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    goto v13;

v202:
    stack[-1] = elt(env, 5); /* expt */
    v216 = stack[-7];
    v217 = qcar(v216);
    v216 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 16); /* kernels1 */
    v216 = (*qfn2(fn))(qenv(fn), v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    v216 = Latsoc(nil, stack[-1], v216);
    if (!(v216 == nil)) goto v218;
    stack[-1] = elt(env, 5); /* expt */
    v216 = stack[-7];
    v217 = qcdr(v216);
    v216 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 16); /* kernels1 */
    v216 = (*qfn2(fn))(qenv(fn), v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    v216 = Latsoc(nil, stack[-1], v216);
    if (!(v216 == nil)) goto v218;
    v216 = qvalue(elt(env, 2)); /* nil */
    goto v74;

v218:
    v216 = stack[-7];
    v216 = qcar(v216);
    if (v216 == nil) goto v219;
    v217 = stack[-7];
    v216 = elt(env, 6); /* prepf */
    fn = elt(env, 17); /* sqform */
    v216 = (*qfn2(fn))(qenv(fn), v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-9];
    v217 = v216;
    goto v220;

v220:
    stack[-5] = v217;
    v216 = qvalue(elt(env, 7)); /* varstack!* */
    v216 = Lmember(nil, v217, v216);
    v216 = (v216 == nil ? lisp_true : nil);
    goto v74;

v219:
    v216 = (Lisp_Object)1; /* 0 */
    v217 = v216;
    goto v220;

v178:
    v216 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v216;
    goto v58;

v177:
    v216 = qvalue(elt(env, 3)); /* t */
    goto v70;
/* error exit handlers */
v100:
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
    Lisp_Object v36;
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
    v36 = stack[0];
    if (v36 == nil) goto v160;
    v36 = stack[0];
    if (is_number(v36)) goto v13;
    v36 = stack[0];
    v36 = qcar(v36);
    v36 = qcdr(v36);
    stack[-1] = CC_getKheight(env, v36);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-2];
    v36 = stack[0];
    v36 = qcdr(v36);
    v36 = CC_getKheight(env, v36);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-2];
    {
        Lisp_Object v187 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* max */
        return (*qfn2(fn))(qenv(fn), v187, v36);
    }

v13:
    v36 = stack[0];
        popv(3);
        return Labsval(nil, v36);

v160:
    v36 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v36); }
/* error exit handlers */
v164:
    popv(3);
    return nil;
}



/* Code for normalform */

static Lisp_Object CC_normalform(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v51, v174;
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
    v174 = v0;
/* end of prologue */
    v51 = qvalue(elt(env, 1)); /* !*mode */
    v26 = elt(env, 2); /* algebraic */
    if (v51 == v26) goto v46;
    v51 = v174;
    v26 = stack[0];
    {
        popv(5);
        fn = elt(env, 4); /* normalform!* */
        return (*qfn2(fn))(qenv(fn), v51, v26);
    }

v46:
    v26 = v174;
    fn = elt(env, 5); /* reval */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    fn = elt(env, 6); /* dpmat_from_a */
    stack[-1] = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v26 = stack[0];
    fn = elt(env, 5); /* reval */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    fn = elt(env, 6); /* dpmat_from_a */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    fn = elt(env, 4); /* normalform!* */
    v26 = (*qfn2(fn))(qenv(fn), stack[-1], v26);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-3] = v26;
    stack[-2] = elt(env, 3); /* list */
    v26 = stack[-3];
    v26 = qcar(v26);
    fn = elt(env, 7); /* dpmat_2a */
    stack[-1] = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v26 = stack[-3];
    v26 = qcdr(v26);
    v26 = qcar(v26);
    fn = elt(env, 7); /* dpmat_2a */
    stack[0] = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v26 = stack[-3];
    v26 = qcdr(v26);
    v26 = qcdr(v26);
    v26 = qcar(v26);
    fn = elt(env, 7); /* dpmat_2a */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v188;
    {
        Lisp_Object v157 = stack[-2];
        Lisp_Object v73 = stack[-1];
        Lisp_Object v179 = stack[0];
        popv(5);
        return list4(v157, v73, v179, v26);
    }
/* error exit handlers */
v188:
    popv(5);
    return nil;
}



/* Code for mk!+outer!+list */

static Lisp_Object CC_mkLouterLlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v90;
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
    v86 = elt(env, 1); /* list */
    v90 = ncons(v86);
    nil = C_nil;
    if (exception_pending()) goto v70;
    v86 = stack[0];
        popv(1);
        return Lappend(nil, v90, v86);
/* error exit handlers */
v70:
    popv(1);
    return nil;
}



/* Code for qqe_eta!-in!-term1 */

static Lisp_Object CC_qqe_etaKinKterm1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v68;
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
    v145 = stack[0];
    v145 = qcdr(v145);
    v145 = qcar(v145);
    fn = elt(env, 4); /* qqe_simplterm */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    stack[-1] = v145;
    v145 = stack[0];
    fn = elt(env, 5); /* qqe_op */
    v68 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    v145 = stack[-1];
    v145 = cons(v68, v145);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-2];
    v68 = stack[-1];
    v145 = elt(env, 1); /* qepsilon */
    if (v68 == v145) goto v67;
    v145 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v145); }

v67:
    v145 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v145); }
/* error exit handlers */
v185:
    popv(3);
    return nil;
}



/* Code for minusml */

static Lisp_Object CC_minusml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v35;
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
    v61 = elt(env, 1); /* "<apply><minus/>" */
    fn = elt(env, 4); /* printout */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = qvalue(elt(env, 2)); /* indent */
    v61 = (Lisp_Object)49; /* 3 */
    v61 = plus2(v35, v61);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    qvalue(elt(env, 2)) = v61; /* indent */
    v61 = stack[0];
    fn = elt(env, 5); /* multiminus */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = qvalue(elt(env, 2)); /* indent */
    v61 = (Lisp_Object)49; /* 3 */
    v61 = difference2(v35, v61);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    qvalue(elt(env, 2)) = v61; /* indent */
    v61 = elt(env, 3); /* "</apply>" */
    fn = elt(env, 4); /* printout */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v61 = nil;
    { popv(2); return onevalue(v61); }
/* error exit handlers */
v37:
    popv(2);
    return nil;
}



/* Code for reval3 */

static Lisp_Object CC_reval3(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
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
    v14 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v13:
    popv(1);
    return nil;
}



/* Code for find_buble */

static Lisp_Object CC_find_buble(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v145;
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

v184:
    v187 = stack[0];
    if (v187 == nil) goto v11;
    v145 = stack[-1];
    v187 = stack[0];
    v187 = qcar(v187);
    fn = elt(env, 2); /* is_buble */
    v187 = (*qfn2(fn))(qenv(fn), v145, v187);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-2];
    if (!(v187 == nil)) { popv(3); return onevalue(v187); }
    v145 = stack[-1];
    v187 = stack[0];
    v187 = qcdr(v187);
    stack[-1] = v145;
    stack[0] = v187;
    goto v184;

v11:
    v187 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v187); }
/* error exit handlers */
v166:
    popv(3);
    return nil;
}



/* Code for innprodp2 */

static Lisp_Object CC_innprodp2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v34, v32, v30;
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
    v32 = v1;
    stack[0] = v0;
/* end of prologue */
    v33 = qvalue(elt(env, 1)); /* nil */
    v34 = v32;
    v33 = cons(v33, v34);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-1];
    v32 = v33;
    goto v66;

v66:
    v33 = stack[0];
    if (v33 == nil) { popv(2); return onevalue(v32); }
    v33 = v32;
    if (v33 == nil) { popv(2); return onevalue(v32); }
    v30 = qvalue(elt(env, 1)); /* nil */
    v33 = stack[0];
    v34 = qcar(v33);
    v33 = v32;
    v33 = qcdr(v33);
    v32 = qcar(v32);
    fn = elt(env, 2); /* innprodkp */
    v33 = (*qfnn(fn))(qenv(fn), 4, v30, v34, v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-1];
    v32 = v33;
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v66;
/* error exit handlers */
v163:
    popv(2);
    return nil;
}



/* Code for matop_pseudomod */

static Lisp_Object CC_matop_pseudomod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v86;
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
    v57 = v1;
    v86 = v0;
/* end of prologue */
    fn = elt(env, 1); /* mod!* */
    v57 = (*qfn2(fn))(qenv(fn), v86, v57);
    errexit();
    v57 = qcar(v57);
    return onevalue(v57);
}



/* Code for nf */

static Lisp_Object MS_CDECL CC_nf(Lisp_Object env, int nargs,
                         Lisp_Object v1, Lisp_Object v2,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v237, v238;
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
    v236 = v2;
    v237 = v1;
/* end of prologue */
    stack[-10] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v236; /* gg */
    v236 = qvalue(elt(env, 1)); /* gg */
    if (v236 == nil) goto v60;
    stack[-3] = nil;
    v236 = (Lisp_Object)1; /* 0 */
    stack[0] = v236;
    v236 = v237;
    stack[-8] = v236;
    v236 = qvalue(elt(env, 1)); /* gg */
    stack[-2] = v236;
    goto v38;

v38:
    v236 = stack[-8];
    if (v236 == nil) goto v239;
    v236 = stack[-8];
    v236 = qcar(v236);
    v236 = qcar(v236);
    stack[-7] = v236;
    goto v33;

v33:
    v236 = stack[-2];
    if (v236 == nil) goto v88;
    v237 = stack[-7];
    v236 = stack[-2];
    v236 = qcar(v236);
    v236 = qcdr(v236);
    fn = elt(env, 13); /* dless */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    goto v48;

v48:
    if (v236 == nil) goto v89;
    v236 = stack[-2];
    v236 = qcdr(v236);
    stack[-2] = v236;
    goto v33;

v89:
    v236 = stack[-2];
    if (v236 == nil) goto v239;
    v236 = stack[-2];
    stack[-1] = v236;
    goto v71;

v71:
    v236 = stack[-1];
    if (v236 == nil) goto v161;
    v236 = stack[-1];
    v236 = qcar(v236);
    v237 = qcdr(v236);
    v236 = stack[-7];
    fn = elt(env, 14); /* dd */
    stack[-4] = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v237 = stack[-9];
    v236 = (Lisp_Object)33; /* 2 */
    v236 = plus2(v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    if (!(((int32_t)(stack[-4])) < ((int32_t)(v236)))) goto v161;
    v236 = stack[-1];
    v236 = qcdr(v236);
    stack[-1] = v236;
    goto v71;

v161:
    v236 = stack[-1];
    if (v236 == nil) goto v19;
    v237 = qvalue(elt(env, 4)); /* gv */
    v236 = stack[-1];
    v236 = qcar(v236);
    v236 = qcar(v236);
    v236 = *(Lisp_Object *)((char *)v237 + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL)));
    stack[-6] = v236;
    v236 = stack[-8];
    v236 = qcar(v236);
    v237 = qcdr(v236);
    v236 = stack[-6];
    v236 = qcar(v236);
    v236 = qcdr(v236);
    fn = elt(env, 15); /* gcdf!* */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-4] = v236;
    v236 = stack[-8];
    v236 = qcar(v236);
    v237 = qcdr(v236);
    v236 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-5] = v236;
    v236 = stack[-6];
    v236 = qcar(v236);
    v237 = qcdr(v236);
    v236 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-4] = v236;
    v237 = stack[-8];
    v236 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-8] = v236;
    v237 = stack[-3];
    v236 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-3] = v236;
    v237 = stack[-6];
    v236 = stack[-5];
    fn = elt(env, 17); /* pcmult */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-6] = v236;
    v236 = stack[-6];
    stack[-4] = qcdr(v236);
    v237 = stack[-7];
    v236 = stack[-1];
    v236 = qcar(v236);
    v236 = qcdr(v236);
    fn = elt(env, 18); /* dquot */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    fn = elt(env, 19); /* pdmult */
    v236 = (*qfn2(fn))(qenv(fn), stack[-4], v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-4] = v236;
    v236 = qvalue(elt(env, 5)); /* tred */
    if (v236 == nil) goto v114;
    v236 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v236 = elt(env, 6); /* "r e d u c t i o n :  " */
    v236 = Lprinc(nil, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v236 = stack[-7];
    v236 = Lprinc(nil, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v236 = elt(env, 7); /* "/" */
    v236 = Lprinc(nil, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v236 = stack[-1];
    v236 = qcar(v236);
    v236 = qcdr(v236);
    v236 = Lprinc(nil, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    v236 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    goto v114;

v114:
    v236 = qvalue(elt(env, 8)); /* stars */
    if (v236 == nil) goto v241;
    v236 = elt(env, 9); /* "*" */
    v236 = Lprinc(nil, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    goto v241;

v241:
    v236 = stack[0];
    v236 = (Lisp_Object)((int32_t)(v236) + 0x10);
    stack[0] = v236;
    v236 = stack[-8];
    v237 = qcdr(v236);
    v236 = stack[-4];
    fn = elt(env, 20); /* pdif */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-8] = v236;
    goto v38;

v19:
    v236 = qvalue(elt(env, 3)); /* redtails */
    if (v236 == nil) goto v239;
    v238 = stack[-7];
    v236 = stack[-8];
    v236 = qcar(v236);
    v237 = qcdr(v236);
    v236 = stack[-3];
    v236 = acons(v238, v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-3] = v236;
    v236 = stack[-8];
    v236 = qcdr(v236);
    stack[-8] = v236;
    goto v38;

v239:
    v237 = qvalue(elt(env, 10)); /* reductions */
    v236 = stack[0];
    v236 = (Lisp_Object)(int32_t)((int32_t)v237 + (int32_t)v236 - TAG_FIXNUM);
    qvalue(elt(env, 10)) = v236; /* reductions */
    v236 = qvalue(elt(env, 11)); /* nforms */
    v236 = (Lisp_Object)((int32_t)(v236) + 0x10);
    qvalue(elt(env, 11)) = v236; /* nforms */
    v236 = stack[-3];
    v237 = Lnreverse(nil, v236);
    env = stack[-11];
    v236 = stack[-8];
    v236 = Lappend(nil, v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    fn = elt(env, 21); /* gcdout */
    v236 = (*qfn1(fn))(qenv(fn), v236);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-11];
    stack[-4] = v236;
    v236 = stack[-4];
    if (!(v236 == nil)) goto v242;
    v236 = qvalue(elt(env, 12)); /* zeros */
    v236 = (Lisp_Object)((int32_t)(v236) + 0x10);
    qvalue(elt(env, 12)) = v236; /* zeros */
    goto v242;

v242:
    v236 = stack[-4];
    goto v14;

v14:
    qvalue(elt(env, 1)) = stack[-10]; /* gg */
    { popv(12); return onevalue(v236); }

v88:
    v236 = qvalue(elt(env, 2)); /* nil */
    goto v48;

v60:
    v236 = v237;
    goto v14;
/* error exit handlers */
v240:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-10]; /* gg */
    popv(12);
    return nil;
}



/* Code for ad_splitname */

static Lisp_Object CC_ad_splitname(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ad_splitname");
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
    v88 = v0;
/* end of prologue */
    v174 = v88;
    if (symbolp(v174)) goto v160;
    v174 = nil;
    { popv(3); return onevalue(v174); }

v160:
    stack[0] = nil;
    v174 = v88;
    v174 = Lexplode(nil, v174);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v174 = Lreverse(nil, v174);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    stack[-1] = v174;
    goto v70;

v70:
    v174 = stack[-1];
    if (v174 == nil) goto v66;
    v174 = stack[-1];
    v174 = qcar(v174);
    fn = elt(env, 2); /* charnump!: */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    if (v174 == nil) goto v66;
    v174 = stack[-1];
    v88 = qcar(v174);
    v174 = stack[0];
    v174 = cons(v88, v174);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    stack[0] = v174;
    v174 = stack[-1];
    v174 = qcdr(v174);
    stack[-1] = v174;
    goto v70;

v66:
    v174 = stack[-1];
    if (v174 == nil) goto v91;
    v174 = stack[-1];
    v174 = Lreverse(nil, v174);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v174 = Lcompress(nil, v174);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v174 = Lintern(nil, v174);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    stack[-1] = v174;
    goto v91;

v91:
    v174 = stack[0];
    if (v174 == nil) goto v137;
    v174 = stack[0];
    v174 = Lcompress(nil, v174);
    nil = C_nil;
    if (exception_pending()) goto v167;
    stack[0] = v174;
    goto v137;

v137:
    v88 = stack[-1];
    v174 = stack[0];
    popv(3);
    return cons(v88, v174);
/* error exit handlers */
v167:
    popv(3);
    return nil;
}



/* Code for bfrsq */

static Lisp_Object CC_bfrsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfrsq");
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
    v186 = v0;
/* end of prologue */
    v178 = v186;
    v178 = qcar(v178);
    v186 = qcdr(v186);
    stack[-1] = v186;
    v186 = v178;
    if (!consp(v186)) goto v67;
    v186 = v178;
    fn = elt(env, 1); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v186, v178);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v186 = stack[-1];
    v178 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    v178 = (*qfn2(fn))(qenv(fn), v186, v178);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    {
        Lisp_Object v174 = stack[0];
        popv(3);
        fn = elt(env, 2); /* plubf */
        return (*qfn2(fn))(qenv(fn), v174, v178);
    }

v67:
    v186 = v178;
    stack[0] = times2(v186, v178);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v186 = stack[-1];
    v178 = stack[-1];
    v178 = times2(v186, v178);
    nil = C_nil;
    if (exception_pending()) goto v51;
    {
        Lisp_Object v88 = stack[0];
        popv(3);
        return plus2(v88, v178);
    }
/* error exit handlers */
v51:
    popv(3);
    return nil;
}



/* Code for mri_prepat */

static Lisp_Object CC_mri_prepat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_prepat");
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
    v11 = v0;
/* end of prologue */
    fn = elt(env, 1); /* mri_2pasfat */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* pasf_prepat */
        return (*qfn1(fn))(qenv(fn), v11);
    }
/* error exit handlers */
v23:
    popv(1);
    return nil;
}



/* Code for aex_boundids */

static Lisp_Object CC_aex_boundids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_boundids");
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
    v86 = stack[0];
    fn = elt(env, 1); /* aex_ids */
    stack[-1] = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    v86 = stack[0];
    fn = elt(env, 2); /* aex_ctx */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    fn = elt(env, 3); /* ctx_idl */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    {
        Lisp_Object v177 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* intersection */
        return (*qfn2(fn))(qenv(fn), v177, v86);
    }
/* error exit handlers */
v70:
    popv(3);
    return nil;
}



/* Code for crn!:prep */

static Lisp_Object CC_crnTprep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:prep");
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
    v83 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !:rn!: */
    v61 = v83;
    v61 = qcdr(v61);
    stack[0] = qcar(v61);
    v61 = elt(env, 1); /* !:rn!: */
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    v83 = cons(v61, v83);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v83 = acons(stack[-1], stack[0], v83);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 2); /* crnprep1 */
        return (*qfn1(fn))(qenv(fn), v83);
    }
/* error exit handlers */
v37:
    popv(3);
    return nil;
}



/* Code for look_for_substitute */

static Lisp_Object MS_CDECL CC_look_for_substitute(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v73, v179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "look_for_substitute");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for look_for_substitute");
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
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v184:
    v157 = stack[0];
    if (!consp(v157)) goto v12;
    v179 = stack[-2];
    v73 = stack[-1];
    v157 = stack[0];
    fn = elt(env, 2); /* look_for_rational */
    v157 = (*qfnn(fn))(qenv(fn), 3, v179, v73, v157);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    v73 = v157;
    if (!(v157 == nil)) { popv(4); return onevalue(v73); }
    v179 = stack[-2];
    v73 = stack[-1];
    v157 = stack[0];
    fn = elt(env, 3); /* look_for_quad */
    v157 = (*qfnn(fn))(qenv(fn), 3, v179, v73, v157);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    v73 = v157;
    if (!(v157 == nil)) { popv(4); return onevalue(v73); }
    v179 = stack[-2];
    v73 = stack[-1];
    v157 = stack[0];
    v157 = qcar(v157);
    v157 = CC_look_for_substitute(env, 3, v179, v73, v157);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    v73 = v157;
    if (!(v157 == nil)) { popv(4); return onevalue(v73); }
    v179 = stack[-2];
    v73 = stack[-1];
    v157 = stack[0];
    v157 = qcdr(v157);
    stack[-2] = v179;
    stack[-1] = v73;
    stack[0] = v157;
    goto v184;

v12:
    v157 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v157); }
/* error exit handlers */
v50:
    popv(4);
    return nil;
}



/* Code for band_matrix */

static Lisp_Object CC_band_matrix(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v259;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for band_matrix");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    stack[-10] = nil;
    v239 = stack[-8];
    v239 = integerp(v239);
    if (!(v239 == nil)) goto v66;
    v239 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v239 == nil)) goto v138;
    v239 = elt(env, 2); /* "Error in band_matrix(second argument): should be an integer." 
*/
    fn = elt(env, 9); /* lprie */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    goto v138;

v138:
    v239 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    goto v66;

v66:
    v239 = stack[-9];
    if (!consp(v239)) goto v187;
    v239 = stack[-9];
    v259 = qcar(v239);
    v239 = elt(env, 3); /* list */
    if (v259 == v239) goto v185;
    v239 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v239 == nil)) goto v175;
    v239 = elt(env, 4); /* "Error in band_matrix(first argument): should be single value or list." 
*/
    fn = elt(env, 9); /* lprie */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    goto v175;

v175:
    v239 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    goto v164;

v164:
    v239 = stack[-9];
    v239 = Llength(nil, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    stack[-7] = v239;
    v239 = stack[-7];
    v239 = Levenp(nil, v239);
    env = stack[-11];
    if (v239 == nil) goto v77;
    v239 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v239 == nil)) goto v179;
    v239 = elt(env, 5); /* "Error in band matrix(first argument): number of elements must be odd." 
*/
    fn = elt(env, 9); /* lprie */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    goto v179;

v179:
    v239 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    goto v77;

v77:
    stack[0] = elt(env, 6); /* quotient */
    v239 = stack[-7];
    v259 = add1(v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    v239 = (Lisp_Object)33; /* 2 */
    v239 = list3(stack[0], v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    fn = elt(env, 10); /* reval */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    stack[-6] = v239;
    v239 = stack[-6];
    v239 = integerp(v239);
    if (v239 == nil) goto v208;
    v239 = stack[-6];
    v259 = v239;
    goto v172;

v172:
    v239 = stack[-8];
    v239 = (Lisp_Object)greaterp2(v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v239 = v239 ? lisp_true : nil;
    env = stack[-11];
    if (v239 == nil) goto v192;
    v239 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v239 == nil)) goto v17;
    v239 = elt(env, 7); /* "Error in band_matrix: too many elements. Band matrix is overflowing." 
*/
    fn = elt(env, 9); /* lprie */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    goto v17;

v17:
    v239 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    goto v58;

v58:
    v239 = (Lisp_Object)17; /* 1 */
    stack[-5] = v239;
    goto v260;

v260:
    v259 = stack[-8];
    v239 = stack[-5];
    v239 = difference2(v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    v239 = Lminusp(nil, v239);
    env = stack[-11];
    if (!(v239 == nil)) { Lisp_Object res = stack[-10]; popv(12); return onevalue(res); }
    v239 = (Lisp_Object)17; /* 1 */
    stack[-4] = v239;
    goto v189;

v189:
    v259 = stack[-8];
    v239 = stack[-4];
    v239 = difference2(v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    v239 = Lminusp(nil, v239);
    env = stack[-11];
    if (v239 == nil) goto v229;
    v239 = stack[-5];
    v239 = add1(v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    stack[-5] = v239;
    goto v260;

v229:
    v259 = stack[-6];
    v239 = stack[-5];
    v259 = difference2(v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    v239 = stack[-4];
    v259 = plus2(v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    v239 = (Lisp_Object)1; /* 0 */
    v239 = (Lisp_Object)greaterp2(v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v239 = v239 ? lisp_true : nil;
    env = stack[-11];
    if (v239 == nil) goto v231;
    v259 = stack[-6];
    v239 = stack[-5];
    v259 = difference2(v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    v239 = stack[-4];
    v259 = plus2(v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    v239 = stack[-7];
    v239 = (Lisp_Object)lesseq2(v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v239 = v239 ? lisp_true : nil;
    env = stack[-11];
    if (v239 == nil) goto v231;
    stack[-3] = stack[-10];
    stack[-2] = stack[-5];
    stack[-1] = stack[-4];
    stack[0] = stack[-9];
    v259 = stack[-6];
    v239 = stack[-5];
    v259 = difference2(v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    v239 = stack[-4];
    v239 = plus2(v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    fn = elt(env, 11); /* pnth */
    v239 = (*qfn2(fn))(qenv(fn), stack[0], v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    v239 = qcar(v239);
    fn = elt(env, 12); /* setmat */
    v239 = (*qfnn(fn))(qenv(fn), 4, stack[-3], stack[-2], stack[-1], v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    goto v231;

v231:
    v239 = stack[-4];
    v239 = add1(v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    stack[-4] = v239;
    goto v189;

v192:
    v259 = stack[-8];
    v239 = stack[-8];
    fn = elt(env, 13); /* mkmatrix */
    v239 = (*qfn2(fn))(qenv(fn), v259, v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    stack[-10] = v239;
    goto v58;

v208:
    v239 = stack[-6];
    fn = elt(env, 10); /* reval */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    v259 = v239;
    goto v172;

v185:
    v239 = stack[-9];
    v239 = qcdr(v239);
    stack[-9] = v239;
    goto v164;

v187:
    v239 = stack[-9];
    v239 = ncons(v239);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-11];
    stack[-9] = v239;
    goto v164;
/* error exit handlers */
v103:
    popv(12);
    return nil;
}



/* Code for genexp */

static Lisp_Object CC_genexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for genexp");
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

v184:
    v67 = stack[0];
    if (!consp(v67)) goto v160;
    v67 = stack[0];
    v67 = qcar(v67);
    v67 = CC_genexp(env, v67);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    if (!(v67 == nil)) { popv(2); return onevalue(v67); }
    v67 = stack[0];
    v67 = qcdr(v67);
    stack[0] = v67;
    goto v184;

v160:
    v67 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* genp */
        return (*qfn1(fn))(qenv(fn), v67);
    }
/* error exit handlers */
v94:
    popv(2);
    return nil;
}



/* Code for vdpcondense */

static Lisp_Object CC_vdpcondense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpcondense");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v13 = v0;
/* end of prologue */
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcar(v13);
    {
        fn = elt(env, 1); /* dipcondense */
        return (*qfn1(fn))(qenv(fn), v13);
    }
}



/* Code for r2speclist1 */

static Lisp_Object CC_r2speclist1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v89, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2speclist1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v63 = v0;
/* end of prologue */
    v33 = v63;
    v89 = elt(env, 1); /* times */
    if (!consp(v33)) goto v166;
    v33 = qcar(v33);
    if (!(v33 == v89)) goto v166;
    v89 = v63;
    v89 = qcdr(v89);
    v33 = qcar(v89);
    v89 = v63;
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcar(v89);
    v63 = qcdr(v63);
    v63 = qcdr(v63);
    v63 = qcdr(v63);
    {
        fn = elt(env, 2); /* r2speclist2 */
        return (*qfnn(fn))(qenv(fn), 3, v33, v89, v63);
    }

v166:
    v89 = (Lisp_Object)17; /* 1 */
    return cons(v89, v63);
}



/* Code for !*pf2sq */

static Lisp_Object CC_Hpf2sq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v201, v207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *pf2sq");
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
    v201 = qvalue(elt(env, 1)); /* nil */
    v58 = (Lisp_Object)17; /* 1 */
    v58 = cons(v201, v58);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    stack[-1] = v58;
    v58 = stack[0];
    if (v58 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v58 = stack[0];
    stack[0] = v58;
    goto v94;

v94:
    v58 = stack[0];
    if (v58 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v58 = stack[0];
    v58 = qcar(v58);
    v201 = qcar(v58);
    v58 = (Lisp_Object)17; /* 1 */
    if (v201 == v58) goto v136;
    v58 = stack[0];
    v58 = qcar(v58);
    v207 = qcar(v58);
    v201 = (Lisp_Object)17; /* 1 */
    v58 = (Lisp_Object)17; /* 1 */
    v58 = acons(v207, v201, v58);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v201 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v58 = (Lisp_Object)17; /* 1 */
    v58 = cons(v201, v58);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v201 = v58;
    goto v31;

v31:
    v58 = stack[0];
    v58 = qcar(v58);
    v58 = qcdr(v58);
    fn = elt(env, 2); /* multsq */
    v201 = (*qfn2(fn))(qenv(fn), v201, v58);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v58 = stack[-1];
    fn = elt(env, 3); /* addsq */
    v58 = (*qfn2(fn))(qenv(fn), v201, v58);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    stack[-1] = v58;
    v58 = stack[0];
    v58 = qcdr(v58);
    stack[0] = v58;
    goto v94;

v136:
    v201 = (Lisp_Object)17; /* 1 */
    v58 = (Lisp_Object)17; /* 1 */
    v58 = cons(v201, v58);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v201 = v58;
    goto v31;
/* error exit handlers */
v76:
    popv(3);
    return nil;
}



/* Code for incident */

static Lisp_Object MS_CDECL CC_incident(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v206, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "incident");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for incident");
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
    stack[-1] = v2;
    stack[0] = v1;
    stack[-2] = v0;
/* end of prologue */

v184:
    v175 = stack[0];
    if (v175 == nil) goto v23;
    v136 = stack[-2];
    v175 = stack[0];
    v206 = qcar(v175);
    v175 = stack[-1];
    fn = elt(env, 2); /* incident1 */
    v175 = (*qfnn(fn))(qenv(fn), 3, v136, v206, v175);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-3];
    v206 = v175;
    v175 = v206;
    if (v175 == nil) goto v89;
    v175 = stack[0];
    v175 = qcdr(v175);
    popv(4);
    return cons(v206, v175);

v89:
    v175 = stack[0];
    stack[0] = qcdr(v175);
    v175 = stack[-1];
    v175 = add1(v175);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-3];
    stack[-1] = v175;
    goto v184;

v23:
    v175 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v175); }
/* error exit handlers */
v186:
    popv(4);
    return nil;
}



setup_type const u25_setup[] =
{
    {"cl_smsimpl-junct",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct},
    {"embed-null-fn",           CC_embedKnullKfn,too_many_1,   wrong_no_1},
    {"xlcm",                    too_few_2,      CC_xlcm,       wrong_no_2},
    {"aceq",                    too_few_2,      CC_aceq,       wrong_no_2},
    {"flatindl",                CC_flatindl,    too_many_1,    wrong_no_1},
    {"formbool",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formbool},
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
    {"symbvarlst",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_symbvarlst},
    {"innprodpex",              too_few_2,      CC_innprodpex, wrong_no_2},
    {"simp-prop-condense",      CC_simpKpropKcondense,too_many_1,wrong_no_1},
    {"lambda_lqgavy_6",         too_few_2,      CC_lambda_lqgavy_6,wrong_no_2},
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
    {"ad_splitname",            CC_ad_splitname,too_many_1,    wrong_no_1},
    {"bfrsq",                   CC_bfrsq,       too_many_1,    wrong_no_1},
    {"mri_prepat",              CC_mri_prepat,  too_many_1,    wrong_no_1},
    {"aex_boundids",            CC_aex_boundids,too_many_1,    wrong_no_1},
    {"crn:prep",                CC_crnTprep,    too_many_1,    wrong_no_1},
    {"look_for_substitute",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_substitute},
    {"band_matrix",             too_few_2,      CC_band_matrix,wrong_no_2},
    {"genexp",                  CC_genexp,      too_many_1,    wrong_no_1},
    {"vdpcondense",             CC_vdpcondense, too_many_1,    wrong_no_1},
    {"r2speclist1",             CC_r2speclist1, too_many_1,    wrong_no_1},
    {"*pf2sq",                  CC_Hpf2sq,      too_many_1,    wrong_no_1},
    {"incident",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_incident},
    {NULL, (one_args *)"u25", (two_args *)"3465 9677330 4279509", 0}
};

/* end of generated code */
