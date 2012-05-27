
/* $destdir\u42.c        Machine generated C code */

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


/* Code for find_active_components */

static Lisp_Object MS_CDECL CC_find_active_components(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "find_active_components");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_active_components");
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
    v18 = stack[-2];
    v17 = stack[-2];
    v16 = qvalue(elt(env, 1)); /* depl!* */
    v16 = Lassoc(nil, v17, v16);
    v17 = v16;
    v16 = v17;
    if (v16 == nil) goto v19;
    v16 = v17;
    v16 = qcdr(v16);
    goto v20;

v20:
    v18 = cons(v18, v16);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v17 = stack[-1];
    v16 = stack[0];
    fn = elt(env, 3); /* update_components */
    v16 = (*qfnn(fn))(qenv(fn), 3, v18, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    stack[0] = v16;
    v16 = stack[-2];
    if (!consp(v16)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v16 = stack[-2];
    stack[-2] = v16;
    goto v22;

v22:
    v16 = stack[-2];
    if (v16 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v16 = stack[-2];
    v16 = qcar(v16);
    v18 = v16;
    v17 = stack[-1];
    v16 = stack[0];
    v16 = CC_find_active_components(env, 3, v18, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    stack[0] = v16;
    v16 = stack[-2];
    v16 = qcdr(v16);
    stack[-2] = v16;
    goto v22;

v19:
    v16 = nil;
    goto v20;
/* error exit handlers */
v21:
    popv(4);
    return nil;
}



/* Code for ofsf_irl2atl */

static Lisp_Object MS_CDECL CC_ofsf_irl2atl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_irl2atl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_irl2atl");
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
    stack[-3] = v2;
    v16 = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v16;
    goto v30;

v30:
    v16 = stack[-5];
    if (v16 == nil) goto v10;
    v16 = stack[-5];
    v16 = qcar(v16);
    v18 = stack[-4];
    v17 = v16;
    v16 = stack[-3];
    fn = elt(env, 2); /* ofsf_ir2atl */
    v16 = (*qfnn(fn))(qenv(fn), 3, v18, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-6];
    stack[-2] = v16;
    v16 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-6];
    stack[-1] = v16;
    v16 = stack[-5];
    v16 = qcdr(v16);
    stack[-5] = v16;
    v16 = stack[-1];
    if (!consp(v16)) goto v30;
    else goto v32;

v32:
    v16 = stack[-5];
    if (v16 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v16 = stack[-5];
    v16 = qcar(v16);
    v18 = stack[-4];
    v17 = v16;
    v16 = stack[-3];
    fn = elt(env, 2); /* ofsf_ir2atl */
    v16 = (*qfnn(fn))(qenv(fn), 3, v18, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-6];
    v16 = Lrplacd(nil, stack[0], v16);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-6];
    v16 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-6];
    stack[-1] = v16;
    v16 = stack[-5];
    v16 = qcdr(v16);
    stack[-5] = v16;
    goto v32;

v10:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v16); }
/* error exit handlers */
v31:
    popv(7);
    return nil;
}



/* Code for freeof!-dfl */

static Lisp_Object CC_freeofKdfl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof-dfl");
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

v28:
    v34 = stack[-1];
    if (v34 == nil) goto v35;
    v34 = stack[-1];
    v19 = qcar(v34);
    v34 = stack[0];
    fn = elt(env, 3); /* freeof!-df */
    v34 = (*qfn2(fn))(qenv(fn), v19, v34);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    if (v34 == nil) goto v13;
    v34 = stack[-1];
    v34 = qcdr(v34);
    stack[-1] = v34;
    goto v28;

v13:
    v34 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v34); }

v35:
    v34 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v34); }
/* error exit handlers */
v36:
    popv(3);
    return nil;
}



/* Code for mri_varlat */

static Lisp_Object CC_mri_varlat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_varlat");
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
    v28 = v0;
/* end of prologue */
    fn = elt(env, 1); /* mri_2pasfat */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* pasf_varlat */
        return (*qfn1(fn))(qenv(fn), v28);
    }
/* error exit handlers */
v24:
    popv(1);
    return nil;
}



/* Code for qqe_simplqneq */

static Lisp_Object CC_qqe_simplqneq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v45, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplqneq");
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
    v45 = v1;
    v18 = v0;
/* end of prologue */
    v45 = v18;
    v45 = qcdr(v45);
    v45 = qcar(v45);
    v18 = qcdr(v18);
    v18 = qcdr(v18);
    v18 = qcar(v18);
    v46 = elt(env, 1); /* qequal */
    fn = elt(env, 6); /* qqe_mk2 */
    v45 = (*qfnn(fn))(qenv(fn), 3, v46, v45, v18);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v18 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 7); /* qqe_simplqequal */
    v18 = (*qfn2(fn))(qenv(fn), v45, v18);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    stack[-2] = v18;
    v45 = stack[-2];
    v18 = elt(env, 3); /* true */
    if (v45 == v18) goto v9;
    v45 = stack[-2];
    v18 = elt(env, 4); /* false */
    if (v45 == v18) goto v48;
    stack[-1] = elt(env, 5); /* qneq */
    v18 = stack[-2];
    fn = elt(env, 8); /* qqe_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v18 = stack[-2];
    fn = elt(env, 9); /* qqe_arg2r */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    fn = elt(env, 6); /* qqe_mk2 */
    v18 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v18);
    nil = C_nil;
    if (exception_pending()) goto v47;
    { popv(4); return onevalue(v18); }

v48:
    v18 = elt(env, 3); /* true */
    { popv(4); return onevalue(v18); }

v9:
    v18 = elt(env, 4); /* false */
    { popv(4); return onevalue(v18); }
/* error exit handlers */
v47:
    popv(4);
    return nil;
}



/* Code for cl_dnf */

static Lisp_Object CC_cl_dnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v52, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_dnf");
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
    v52 = v11;
    v11 = elt(env, 1); /* or */
    fn = elt(env, 3); /* cl_gdnf0 */
    v53 = (*qfn2(fn))(qenv(fn), v52, v11);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[0];
    v52 = qvalue(elt(env, 2)); /* nil */
    v11 = (Lisp_Object)-15; /* -1 */
    {
        popv(1);
        fn = elt(env, 4); /* rl_simpl */
        return (*qfnn(fn))(qenv(fn), 3, v53, v52, v11);
    }
/* error exit handlers */
v54:
    popv(1);
    return nil;
}



/* Code for ps!:onep!: */

static Lisp_Object CC_psTonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:onep:");
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
    v28 = v0;
/* end of prologue */
    fn = elt(env, 1); /* ps!:value */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    errexit();
        return Lonep(nil, v28);
}



/* Code for init */

static Lisp_Object CC_init(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110, v111, v112;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for init");
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
    v109 = qvalue(elt(env, 1)); /* rowmin */
    stack[-2] = v109;
    goto v50;

v50:
    v110 = qvalue(elt(env, 2)); /* rowmax */
    v109 = stack[-2];
    v109 = difference2(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v109 = Lminusp(nil, v109);
    env = stack[-3];
    if (v109 == nil) goto v13;
    v110 = qvalue(elt(env, 5)); /* maxvar */
    v109 = stack[-1];
    if (equal(v110, v109)) goto v114;
    v110 = (Lisp_Object)33; /* 2 */
    v109 = stack[-1];
    v109 = times2(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v109 = Lmkvect(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    qvalue(elt(env, 4)) = v109; /* codmat */
    goto v115;

v115:
    v109 = qvalue(elt(env, 14)); /* kvarlst */
    if (v109 == nil) goto v116;
    v109 = qvalue(elt(env, 14)); /* kvarlst */
    v112 = v109;
    goto v117;

v117:
    v109 = v112;
    if (v109 == nil) goto v116;
    v109 = v112;
    v109 = qcar(v109);
    v111 = v109;
    v109 = v111;
    v109 = qcdr(v109);
    v110 = qcar(v109);
    v109 = elt(env, 14); /* kvarlst */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v109 = v111;
    v109 = qcdr(v109);
    v110 = qcar(v109);
    v109 = elt(env, 11); /* nex */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v109 = v112;
    v109 = qcdr(v109);
    v112 = v109;
    goto v117;

v116:
    v109 = elt(env, 19); /* (plus minus difference times expt sqrt) */
    v111 = v109;
    goto v118;

v118:
    v109 = v111;
    if (v109 == nil) goto v119;
    v109 = v111;
    v109 = qcar(v109);
    v110 = v109;
    v109 = elt(env, 14); /* kvarlst */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v109 = v111;
    v109 = qcdr(v109);
    v111 = v109;
    goto v118;

v119:
    v109 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 20)) = v109; /* avarlst */
    qvalue(elt(env, 21)) = v109; /* codbexl!* */
    qvalue(elt(env, 14)) = v109; /* kvarlst */
    qvalue(elt(env, 22)) = v109; /* prevlst */
    qvalue(elt(env, 8)) = v109; /* varlst!+ */
    qvalue(elt(env, 9)) = v109; /* varlst!* */
    v109 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 23)) = v109; /* preprefixlist */
    qvalue(elt(env, 24)) = v109; /* malst */
    v109 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 25)) = v109; /* prefixlist */
    v109 = (Lisp_Object)-15; /* -1 */
    qvalue(elt(env, 2)) = v109; /* rowmax */
    v109 = stack[-1];
    qvalue(elt(env, 5)) = v109; /* maxvar */
    v109 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v109; /* rowmin */
    v112 = (Lisp_Object)1; /* 0 */
    v111 = (Lisp_Object)1; /* 0 */
    v110 = (Lisp_Object)1; /* 0 */
    v109 = (Lisp_Object)1; /* 0 */
    v109 = list4(v112, v111, v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    qvalue(elt(env, 26)) = v109; /* ops */
    v109 = nil;
    { popv(4); return onevalue(v109); }

v114:
    v109 = (Lisp_Object)1; /* 0 */
    stack[0] = v109;
    goto v120;

v120:
    v110 = (Lisp_Object)33; /* 2 */
    v109 = stack[-1];
    v110 = times2(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v109 = stack[0];
    v109 = difference2(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v109 = Lminusp(nil, v109);
    env = stack[-3];
    if (!(v109 == nil)) goto v115;
    v111 = qvalue(elt(env, 4)); /* codmat */
    v110 = stack[0];
    v109 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v111 + (CELL-TAG_VECTOR) + ((int32_t)v110/(16/CELL))) = v109;
    v109 = stack[0];
    v109 = add1(v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    stack[0] = v109;
    goto v120;

v13:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v110 = qvalue(elt(env, 5)); /* maxvar */
    v109 = stack[-2];
    v109 = plus2(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v109 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v109/(16/CELL)));
    if (v109 == nil) goto v33;
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v110 = qvalue(elt(env, 5)); /* maxvar */
    v109 = stack[-2];
    v109 = plus2(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v110 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v109/(16/CELL)));
    v109 = (Lisp_Object)49; /* 3 */
    v109 = *(Lisp_Object *)((char *)v110 + (CELL-TAG_VECTOR) + ((int32_t)v109/(16/CELL)));
    v111 = v109;
    if (is_number(v109)) goto v33;
    v110 = v111;
    v109 = elt(env, 6); /* npcdvar */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 7); /* nvarlst */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 8); /* varlst!+ */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 9); /* varlst!* */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 10); /* rowindex */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 11); /* nex */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 12); /* inlhs */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 13); /* rowocc */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 14); /* kvarlst */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 15); /* alias */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 16); /* finalalias */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 17); /* aliaslist */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    v110 = v111;
    v109 = elt(env, 18); /* inalias */
    v109 = Lremprop(nil, v110, v109);
    env = stack[-3];
    goto v33;

v33:
    v109 = stack[-2];
    v109 = add1(v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    stack[-2] = v109;
    goto v50;
/* error exit handlers */
v113:
    popv(4);
    return nil;
}



/* Code for expttermp1 */

static Lisp_Object CC_expttermp1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v122, v38, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expttermp1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v122 = v1;
    v38 = v0;
/* end of prologue */

v123:
    v37 = v122;
    if (v37 == nil) goto v28;
    v16 = v38;
    v37 = v122;
    v37 = qcar(v37);
    if (equal(v16, v37)) goto v124;
    v37 = v122;
    v16 = qcar(v37);
    v37 = elt(env, 3); /* expt */
    if (!consp(v16)) goto v125;
    v16 = qcar(v16);
    if (!(v16 == v37)) goto v125;
    v16 = v38;
    v37 = v122;
    v37 = qcar(v37);
    v37 = qcdr(v37);
    v37 = qcar(v37);
    v37 = (equal(v16, v37) ? lisp_true : nil);
    goto v29;

v29:
    if (v37 == nil) goto v106;
    v37 = qvalue(elt(env, 2)); /* t */
    return onevalue(v37);

v106:
    v37 = v122;
    v37 = qcdr(v37);
    v122 = v37;
    goto v123;

v125:
    v37 = qvalue(elt(env, 1)); /* nil */
    goto v29;

v124:
    v37 = qvalue(elt(env, 2)); /* t */
    return onevalue(v37);

v28:
    v37 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v37);
}



/* Code for dipcontenti1 */

static Lisp_Object MS_CDECL CC_dipcontenti1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipcontenti1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcontenti1");
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
    v17 = v0;
/* end of prologue */

v123:
    v16 = stack[0];
    if (v16 == nil) goto v128;
    v16 = stack[0];
    v16 = qcdr(v16);
    v16 = qcar(v16);
    fn = elt(env, 1); /* vbcgcd */
    v16 = (*qfn2(fn))(qenv(fn), v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    stack[-2] = v16;
    v16 = stack[-1];
    if (v16 == nil) goto v19;
    v16 = stack[0];
    v17 = qcar(v16);
    v16 = stack[-1];
    fn = elt(env, 2); /* dipcontevmin */
    v16 = (*qfn2(fn))(qenv(fn), v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    stack[-1] = v16;
    goto v19;

v19:
    v16 = stack[-2];
    fn = elt(env, 3); /* bcone!? */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    if (v16 == nil) goto v129;
    v16 = stack[-1];
    if (!(v16 == nil)) goto v129;
    v16 = stack[-2];
    popv(4);
    return ncons(v16);

v129:
    v17 = stack[-2];
    v18 = stack[-1];
    v16 = stack[0];
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    stack[-1] = v18;
    stack[0] = v16;
    goto v123;

v128:
    v16 = stack[-1];
    popv(4);
    return cons(v17, v16);
/* error exit handlers */
v21:
    popv(4);
    return nil;
}



/* Code for matcheq */

static Lisp_Object CC_matcheq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matcheq");
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
    v145 = stack[-2];
    if (v145 == nil) goto v30;
    v145 = stack[-1];
    v145 = (v145 == nil ? lisp_true : nil);
    goto v35;

v35:
    if (v145 == nil) goto v24;
    v145 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v145); }

v24:
    v145 = stack[-2];
    if (is_number(v145)) goto v33;
    v145 = stack[-2];
    if (!consp(v145)) goto v23;
    v145 = stack[-1];
    if (!consp(v145)) goto v147;
    v145 = stack[-2];
    v145 = qcar(v145);
    if (!consp(v145)) goto v92;
    v145 = qvalue(elt(env, 2)); /* nil */
    goto v148;

v148:
    if (v145 == nil) goto v149;
    v145 = stack[-2];
    v146 = qcar(v145);
    v145 = elt(env, 0); /* matcheq */
    stack[0] = get(v146, v145);
    env = stack[-4];
    v145 = stack[-2];
    v145 = qcdr(v145);
    stack[-2] = Lmkquote(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v145 = stack[-1];
    v145 = qcdr(v145);
    v145 = Lmkquote(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v145 = list3(stack[0], stack[-2], v145);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 6); /* eval */
        return (*qfn1(fn))(qenv(fn), v145);
    }

v149:
    v145 = qvalue(elt(env, 3)); /* !*exp */
    if (v145 == nil) goto v150;
    v145 = qvalue(elt(env, 2)); /* nil */
    goto v82;

v82:
    if (v145 == nil) goto v151;
    v146 = stack[-2];
    v145 = stack[-1];
    {
        popv(5);
        fn = elt(env, 7); /* matchlinear */
        return (*qfn2(fn))(qenv(fn), v146, v145);
    }

v151:
    v145 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v145); }

v150:
    v145 = stack[-1];
    v146 = qcar(v145);
    v145 = elt(env, 4); /* (plus difference) */
    v145 = Lmemq(nil, v146, v145);
    if (v145 == nil) goto v114;
    v145 = stack[-2];
    v146 = qcar(v145);
    v145 = elt(env, 5); /* diff */
    v145 = (v146 == v145 ? lisp_true : nil);
    goto v82;

v114:
    v145 = qvalue(elt(env, 2)); /* nil */
    goto v82;

v92:
    v145 = stack[-2];
    v146 = qcar(v145);
    v145 = stack[-1];
    v145 = qcar(v145);
    v145 = (v146 == v145 ? lisp_true : nil);
    goto v148;

v147:
    v145 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v145); }

v23:
    v146 = stack[-2];
    v145 = elt(env, 0); /* matcheq */
    stack[-3] = get(v146, v145);
    env = stack[-4];
    v145 = stack[-2];
    stack[0] = Lmkquote(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v145 = stack[-1];
    if (!consp(v145)) goto v25;
    v145 = stack[-1];
    goto v104;

v104:
    v145 = Lmkquote(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v145 = list3(stack[-3], stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    fn = elt(env, 6); /* eval */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v146 = v145;
    v145 = v146;
    if (!(v145 == nil)) { popv(5); return onevalue(v146); }
    v145 = qvalue(elt(env, 3)); /* !*exp */
    if (v145 == nil) goto v152;
    v145 = qvalue(elt(env, 2)); /* nil */
    goto v103;

v103:
    if (v145 == nil) goto v153;
    v146 = stack[-2];
    v145 = stack[-1];
    {
        popv(5);
        fn = elt(env, 7); /* matchlinear */
        return (*qfn2(fn))(qenv(fn), v146, v145);
    }

v153:
    v145 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v145); }

v152:
    v145 = stack[-1];
    v145 = Lconsp(nil, v145);
    env = stack[-4];
    if (v145 == nil) goto v154;
    v145 = stack[-1];
    v146 = qcar(v145);
    v145 = elt(env, 4); /* (plus difference) */
    v145 = Lmemq(nil, v146, v145);
    goto v103;

v154:
    v145 = qvalue(elt(env, 2)); /* nil */
    goto v103;

v25:
    v145 = stack[-1];
    v145 = ncons(v145);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    goto v104;

v33:
    v146 = stack[-2];
    v145 = stack[-1];
    if (equal(v146, v145)) goto v54;
    v145 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v145); }

v54:
    v145 = qvalue(elt(env, 1)); /* t */
    popv(5);
    return ncons(v145);

v30:
    v145 = qvalue(elt(env, 1)); /* t */
    goto v35;
/* error exit handlers */
v74:
    popv(5);
    return nil;
}



/* Code for denlist */

static Lisp_Object CC_denlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for denlist");
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
    goto v24;

v24:
    v106 = stack[-1];
    if (v106 == nil) goto v30;
    v106 = stack[-1];
    v106 = qcar(v106);
    v104 = Llength(nil, v106);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    v106 = (Lisp_Object)33; /* 2 */
    if (v104 == v106) goto v34;
    v106 = stack[-1];
    v104 = qcar(v106);
    v106 = stack[0];
    fn = elt(env, 1); /* ev!-denom3 */
    v104 = (*qfn2(fn))(qenv(fn), v104, v106);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    v106 = stack[-2];
    v106 = cons(v104, v106);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    stack[-2] = v106;
    v106 = stack[-1];
    v106 = qcdr(v106);
    stack[-1] = v106;
    goto v24;

v34:
    v106 = stack[-1];
    v104 = qcar(v106);
    v106 = stack[0];
    fn = elt(env, 2); /* ev!-denom2 */
    v104 = (*qfn2(fn))(qenv(fn), v104, v106);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    v106 = stack[-2];
    v106 = cons(v104, v106);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    stack[-2] = v106;
    v106 = stack[-1];
    v106 = qcdr(v106);
    stack[-1] = v106;
    goto v24;

v30:
    v106 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v106);
    }
/* error exit handlers */
v4:
    popv(4);
    return nil;
}



/* Code for degree!-order */

static Lisp_Object CC_degreeKorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v160, v155;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degree-order");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v160 = v1;
    v155 = v0;
/* end of prologue */
    v159 = v155;
    if (!consp(v159)) goto v30;
    v159 = v155;
    v159 = qcar(v159);
    v159 = (consp(v159) ? nil : lisp_true);
    goto v35;

v35:
    if (v159 == nil) goto v24;
    v159 = qvalue(elt(env, 1)); /* t */
    return onevalue(v159);

v24:
    v159 = v160;
    if (!consp(v159)) goto v54;
    v159 = v160;
    v159 = qcar(v159);
    v159 = (consp(v159) ? nil : lisp_true);
    goto v53;

v53:
    if (v159 == nil) goto v36;
    v159 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v159);

v36:
    v159 = v155;
    v159 = qcar(v159);
    v159 = qcar(v159);
    v159 = qcdr(v159);
    v160 = qcar(v160);
    v160 = qcar(v160);
    v160 = qcdr(v160);
        return Llessp(nil, v159, v160);

v54:
    v159 = qvalue(elt(env, 1)); /* t */
    goto v53;

v30:
    v159 = qvalue(elt(env, 1)); /* t */
    goto v35;
}



/* Code for actual_arguments */

static Lisp_Object CC_actual_arguments(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v42, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for actual_arguments");
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
    v42 = v0;
/* end of prologue */
    v33 = elt(env, 1); /* list */
    v54 = v42;
    v54 = qcdr(v54);
    if (!(v54 == nil)) goto v24;
    v54 = v42;
    v42 = qcar(v54);
    v54 = elt(env, 2); /* generic_function */
    v54 = get(v42, v54);
    goto v24;

v24:
    return cons(v33, v54);
}



/* Code for dp_2a */

static Lisp_Object CC_dp_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_2a");
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
    v124 = v10;
    if (v124 == nil) goto v27;
    v124 = v10;
    fn = elt(env, 1); /* dp!=2a */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dp!=replus */
        return (*qfn1(fn))(qenv(fn), v124);
    }

v27:
    v124 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v124); }
/* error exit handlers */
v127:
    popv(1);
    return nil;
}



/* Code for sub01 */

static Lisp_Object CC_sub01(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v108, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sub01");
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
    v161 = nil;
    goto v24;

v24:
    v107 = stack[0];
    if (v107 == nil) goto v8;
    v107 = stack[0];
    v108 = qcar(v107);
    v107 = stack[-1];
    if (equal(v108, v107)) goto v11;
    v107 = (Lisp_Object)1; /* 0 */
    goto v127;

v127:
    v108 = v161;
    v107 = cons(v107, v108);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-2];
    v161 = v107;
    v107 = stack[0];
    v107 = qcdr(v107);
    stack[0] = v107;
    goto v24;

v11:
    v107 = (Lisp_Object)17; /* 1 */
    goto v127;

v8:
    v107 = v161;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v107);
    }
/* error exit handlers */
v40:
    popv(3);
    return nil;
}



/* Code for rl_nnfnot */

static Lisp_Object CC_rl_nnfnot(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_nnfnot");
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
    v162 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_nnfnot!* */
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    {
        Lisp_Object v10 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v10, v162);
    }
/* error exit handlers */
v124:
    popv(2);
    return nil;
}



/* Code for uterm */

static Lisp_Object CC_uterm(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for uterm");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v102 = v2;
    stack[-1] = v1;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* rhs!* */
    qvalue(elt(env, 1)) = nil; /* rhs!* */
    qvalue(elt(env, 1)) = v102; /* rhs!* */
    v102 = qvalue(elt(env, 1)); /* rhs!* */
    if (v102 == nil) goto v32;
    v166 = stack[-1];
    v102 = qvalue(elt(env, 1)); /* rhs!* */
    v102 = qcar(v102);
    v102 = qcar(v102);
    fn = elt(env, 3); /* addinds */
    v102 = (*qfn2(fn))(qenv(fn), v166, v102);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    stack[0] = v102;
    v102 = qvalue(elt(env, 1)); /* rhs!* */
    v102 = qcar(v102);
    v102 = qcdr(v102);
    v166 = qcar(v102);
    v102 = stack[-1];
    fn = elt(env, 4); /* evaluatecoeffts */
    v102 = (*qfn2(fn))(qenv(fn), v166, v102);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v166 = v102;
    if (v166 == nil) goto v22;
    v166 = v102;
    v102 = qvalue(elt(env, 1)); /* rhs!* */
    v102 = qcar(v102);
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    v102 = cons(v166, v102);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v166 = stack[0];
    v102 = cons(v166, v102);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    stack[0] = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v166 = stack[-1];
    v102 = qvalue(elt(env, 1)); /* rhs!* */
    v102 = qcdr(v102);
    v102 = CC_uterm(env, v166, v102);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    fn = elt(env, 5); /* plusdf */
    v102 = (*qfn2(fn))(qenv(fn), stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    goto v24;

v24:
    qvalue(elt(env, 1)) = stack[-2]; /* rhs!* */
    { popv(4); return onevalue(v102); }

v22:
    v166 = stack[-1];
    v102 = qvalue(elt(env, 1)); /* rhs!* */
    v102 = qcdr(v102);
    v102 = CC_uterm(env, v166, v102);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    goto v24;

v32:
    v102 = qvalue(elt(env, 2)); /* nil */
    goto v24;
/* error exit handlers */
v167:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* rhs!* */
    popv(4);
    return nil;
}



/* Code for gigcd!: */

static Lisp_Object CC_gigcdT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v121, v23, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gigcd:");
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
    v121 = v1;
    v23 = v0;
/* end of prologue */

v127:
    v155 = v121;
    v155 = qcdr(v155);
    v125 = qcar(v155);
    v155 = (Lisp_Object)1; /* 0 */
    if (v125 == v155) goto v42;
    v155 = qvalue(elt(env, 1)); /* nil */
    goto v128;

v128:
    if (v155 == nil) goto v158;
    v155 = v23;
    {
        popv(2);
        fn = elt(env, 2); /* fqa */
        return (*qfn1(fn))(qenv(fn), v155);
    }

v158:
    v155 = v121;
    stack[0] = v155;
    v155 = v23;
    fn = elt(env, 3); /* giremainder */
    v155 = (*qfn2(fn))(qenv(fn), v155, v121);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    v121 = v155;
    v155 = stack[0];
    v23 = v155;
    goto v127;

v42:
    v155 = v121;
    v155 = qcdr(v155);
    v125 = qcdr(v155);
    v155 = (Lisp_Object)1; /* 0 */
    v155 = (v125 == v155 ? lisp_true : nil);
    goto v128;
/* error exit handlers */
v26:
    popv(2);
    return nil;
}



/* Code for pasf_uprap */

static Lisp_Object CC_pasf_uprap(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_uprap");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */
    v162 = v32;
    v32 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* pasf_uprap1 */
        return (*qfn2(fn))(qenv(fn), v162, v32);
    }
}



/* Code for bc_neg */

static Lisp_Object CC_bc_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_neg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* negf */
        return (*qfn1(fn))(qenv(fn), v27);
    }
}



/* Code for !:mod!:units */

static Lisp_Object MS_CDECL CC_TmodTunits(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v156, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v97;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, ":mod:units");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :mod:units");
#endif
    if (stack >= stacklimit)
    {
        push4(v156,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v156);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v156;
    stack[-3] = v2;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */

v30:
    v97 = stack[-4];
    v170 = (Lisp_Object)1; /* 0 */
    if (v97 == v170) goto v144;
    v97 = stack[-4];
    v170 = (Lisp_Object)17; /* 1 */
    if (v97 == v170) goto v29;
    v97 = stack[-5];
    v170 = stack[-4];
    v170 = quot2(v97, v170);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-7];
    stack[-6] = v170;
    stack[-1] = stack[-4];
    stack[0] = stack[-5];
    v97 = stack[-4];
    v170 = stack[-6];
    v170 = times2(v97, v170);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-7];
    stack[-4] = difference2(stack[0], v170);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-7];
    stack[0] = stack[-2];
    v97 = stack[-2];
    v170 = stack[-6];
    v170 = times2(v97, v170);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-7];
    v170 = difference2(stack[-3], v170);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-7];
    stack[-5] = stack[-1];
    stack[-3] = stack[0];
    stack[-2] = v170;
    goto v30;

v29:
    v97 = stack[-2];
    v170 = (Lisp_Object)1; /* 0 */
    v170 = (Lisp_Object)lessp2(v97, v170);
    nil = C_nil;
    if (exception_pending()) goto v95;
    v170 = v170 ? lisp_true : nil;
    env = stack[-7];
    if (v170 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v170 = stack[-2];
    v97 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(8);
    return plus2(v170, v97);

v144:
    v170 = (Lisp_Object)1; /* 0 */
    { popv(8); return onevalue(v170); }
/* error exit handlers */
v95:
    popv(8);
    return nil;
}



/* Code for weak_xreduce1 */

static Lisp_Object MS_CDECL CC_weak_xreduce1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v187, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "weak_xreduce1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for weak_xreduce1");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v2;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v186 = stack[-4];
    stack[0] = v186;
    goto v10;

v10:
    v186 = stack[-5];
    if (v186 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v186 = stack[0];
    if (v186 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v186 = stack[0];
    v186 = qcar(v186);
    stack[-6] = v186;
    v186 = stack[0];
    v186 = qcdr(v186);
    stack[0] = v186;
    v186 = stack[-6];
    fn = elt(env, 8); /* xval */
    stack[-1] = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v186 = stack[-5];
    fn = elt(env, 8); /* xval */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    fn = elt(env, 9); /* xdiv */
    v186 = (*qfn2(fn))(qenv(fn), stack[-1], v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[-1] = v186;
    if (v186 == nil) goto v10;
    v186 = stack[-1];
    fn = elt(env, 10); /* mknwedge */
    v188 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v187 = (Lisp_Object)17; /* 1 */
    v186 = (Lisp_Object)17; /* 1 */
    v186 = list2star(v188, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[-1] = v186;
    v187 = stack[-1];
    v186 = stack[-6];
    fn = elt(env, 11); /* wedgepf */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[0] = v186;
    v186 = stack[-5];
    v186 = qcar(v186);
    stack[-2] = qcdr(v186);
    v186 = stack[0];
    v186 = qcar(v186);
    v186 = qcdr(v186);
    fn = elt(env, 12); /* invsq */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    fn = elt(env, 13); /* multsq */
    v186 = (*qfn2(fn))(qenv(fn), stack[-2], v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[-2] = v186;
    v186 = stack[-2];
    v186 = qcar(v186);
    fn = elt(env, 14); /* negf */
    v187 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v186 = stack[-2];
    v186 = qcdr(v186);
    v186 = cons(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    fn = elt(env, 15); /* multpfsq */
    v186 = (*qfn2(fn))(qenv(fn), stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    fn = elt(env, 16); /* addpf */
    v186 = (*qfn2(fn))(qenv(fn), stack[-5], v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    fn = elt(env, 17); /* subs2pf */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[-5] = v186;
    v186 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v186 == nil) goto v189;
    stack[0] = stack[-3];
    v187 = stack[-1];
    v186 = stack[-2];
    fn = elt(env, 15); /* multpfsq */
    v187 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v186 = stack[-6];
    v186 = list2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v186 = Lnconc(nil, stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[-3] = v186;
    goto v189;

v189:
    v186 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v186 == nil) goto v190;
    v186 = elt(env, 3); /* "   " */
    fn = elt(env, 18); /* eval */
    v188 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v187 = qvalue(elt(env, 1)); /* nil */
    v186 = elt(env, 4); /* first */
    fn = elt(env, 19); /* assgnpri */
    v186 = (*qfnn(fn))(qenv(fn), 3, v188, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    stack[0] = elt(env, 5); /* wedge */
    v187 = stack[-1];
    v186 = stack[-2];
    fn = elt(env, 15); /* multpfsq */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    fn = elt(env, 20); /* preppf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v186 = stack[-6];
    fn = elt(env, 20); /* preppf */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v186 = list3(stack[0], stack[-1], v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v186 = Lmkquote(nil, v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    fn = elt(env, 18); /* eval */
    v188 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v187 = qvalue(elt(env, 1)); /* nil */
    v186 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 19); /* assgnpri */
    v186 = (*qfnn(fn))(qenv(fn), 3, v188, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v186 = elt(env, 6); /* " +" */
    fn = elt(env, 18); /* eval */
    v188 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    v187 = qvalue(elt(env, 1)); /* nil */
    v186 = elt(env, 7); /* last */
    fn = elt(env, 19); /* assgnpri */
    v186 = (*qfnn(fn))(qenv(fn), 3, v188, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-7];
    goto v190;

v190:
    v186 = stack[-4];
    stack[0] = v186;
    goto v10;
/* error exit handlers */
v78:
    popv(8);
    return nil;
}



/* Code for tot!-asym!-indp */

static Lisp_Object CC_totKasymKindp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tot-asym-indp");
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

v123:
    v101 = stack[0];
    if (v101 == nil) goto v27;
    v101 = stack[0];
    v101 = qcdr(v101);
    if (v101 == nil) goto v128;
    v101 = stack[0];
    v102 = qcar(v101);
    v101 = stack[0];
    v101 = qcdr(v101);
    v101 = qcar(v101);
    if (equal(v102, v101)) goto v47;
    v101 = stack[0];
    v101 = qcar(v101);
    if (!consp(v101)) goto v7;
    v101 = stack[0];
    v101 = qcar(v101);
    fn = elt(env, 3); /* indxchk */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    if (!(v101 == nil)) goto v42;
    v101 = stack[0];
    v101 = qcdr(v101);
    v101 = qcar(v101);
    fn = elt(env, 3); /* indxchk */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    if (!(v101 == nil)) goto v42;
    v101 = stack[0];
    v102 = qcar(v101);
    v101 = stack[0];
    v101 = qcdr(v101);
    v101 = qcar(v101);
    fn = elt(env, 4); /* indordlp */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    goto v42;

v42:
    if (v101 == nil) goto v52;
    v101 = stack[0];
    v101 = qcdr(v101);
    stack[0] = v101;
    goto v123;

v52:
    v101 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v101); }

v7:
    v101 = stack[0];
    v102 = qcar(v101);
    v101 = stack[0];
    v101 = qcdr(v101);
    v101 = qcar(v101);
    fn = elt(env, 5); /* indordp */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    goto v42;

v47:
    v101 = qvalue(elt(env, 2)); /* nil */
    goto v42;

v128:
    v101 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v101); }

v27:
    v101 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v101); }
/* error exit handlers */
v191:
    popv(2);
    return nil;
}



/* Code for fctinsert */

static Lisp_Object CC_fctinsert(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v48, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctinsert");
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
    v48 = stack[-1];
    v22 = stack[0];
    fn = elt(env, 2); /* smember */
    v22 = (*qfn2(fn))(qenv(fn), v48, v22);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    if (!(v22 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v159 = stack[-1];
    v48 = stack[0];
    v22 = qvalue(elt(env, 1)); /* depl!* */
    v22 = Lassoc(nil, v48, v22);
    v22 = Lmember(nil, v159, v22);
    if (!(v22 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    stack[-2] = stack[-1];
    v22 = stack[-1];
    fn = elt(env, 3); /* fctlength */
    v48 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    v22 = stack[0];
    {
        Lisp_Object v125 = stack[-2];
        popv(4);
        fn = elt(env, 4); /* fctins */
        return (*qfnn(fn))(qenv(fn), 3, v125, v48, v22);
    }
/* error exit handlers */
v23:
    popv(4);
    return nil;
}



/* Code for coeff_sortl */

static Lisp_Object MS_CDECL CC_coeff_sortl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff_sortl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeff_sortl");
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
    stack[0] = v2;
    stack[-1] = v1;
    v53 = v0;
/* end of prologue */
    v54 = v53;
    v53 = stack[0];
    fn = elt(env, 1); /* coeff_ordn */
    v42 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-2];
    v54 = stack[-1];
    v53 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* coeff_sortl1 */
        return (*qfnn(fn))(qenv(fn), 3, v42, v54, v53);
    }
/* error exit handlers */
v15:
    popv(3);
    return nil;
}



/* Code for vdelete */

static Lisp_Object CC_vdelete(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v159, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdelete");
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
    v160 = nil;
    goto v24;

v24:
    v48 = stack[0];
    if (v48 == nil) goto v30;
    v48 = stack[-1];
    v159 = qcar(v48);
    v48 = stack[0];
    v48 = qcar(v48);
    v48 = qcar(v48);
    if (equal(v159, v48)) goto v15;
    v48 = stack[0];
    v48 = qcar(v48);
    v159 = v160;
    v48 = cons(v48, v159);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v160 = v48;
    v48 = stack[0];
    v48 = qcdr(v48);
    stack[0] = v48;
    goto v24;

v15:
    v159 = v160;
    v48 = stack[0];
    v48 = qcdr(v48);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v159, v48);
    }

v30:
    v48 = v160;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v48);
    }
/* error exit handlers */
v23:
    popv(3);
    return nil;
}



/* Code for quotfexf!*1 */

static Lisp_Object CC_quotfexfH1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v152, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfexf*1");
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
    v103 = stack[-1];
    if (v103 == nil) goto v28;
    v152 = stack[-1];
    v103 = stack[0];
    fn = elt(env, 7); /* quotf */
    v103 = (*qfn2(fn))(qenv(fn), v152, v103);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    v152 = v103;
    v103 = v152;
    if (!(v103 == nil)) { popv(3); return onevalue(v152); }
    v152 = stack[-1];
    v103 = stack[0];
    v103 = cons(v152, v103);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    fn = elt(env, 8); /* rationalizesq */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    v192 = v103;
    v103 = v192;
    v152 = qcdr(v103);
    v103 = (Lisp_Object)17; /* 1 */
    if (v152 == v103) goto v157;
    v103 = qvalue(elt(env, 2)); /* t */
    stack[0] = qvalue(elt(env, 3)); /* !*rationalize */
    qvalue(elt(env, 3)) = v103; /* !*rationalize */
    v103 = v192;
    fn = elt(env, 8); /* rationalizesq */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    qvalue(elt(env, 3)) = stack[0]; /* !*rationalize */
    v192 = v103;
    v152 = qcdr(v103);
    v103 = (Lisp_Object)17; /* 1 */
    if (v152 == v103) goto v121;
    v103 = elt(env, 4); /* "Catastrophic division failure" */
    v152 = v103;
    v103 = v152;
    qvalue(elt(env, 5)) = v103; /* errmsg!* */
    v103 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v103 == nil)) goto v45;
    v103 = v152;
    fn = elt(env, 9); /* lprie */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    goto v45;

v45:
    v103 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v163;
    v103 = nil;
    { popv(3); return onevalue(v103); }

v121:
    v103 = v192;
    v103 = qcar(v103);
    { popv(3); return onevalue(v103); }

v157:
    v103 = v192;
    v103 = qcar(v103);
    { popv(3); return onevalue(v103); }

v28:
    v103 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v103); }
/* error exit handlers */
v154:
    env = stack[-2];
    qvalue(elt(env, 3)) = stack[0]; /* !*rationalize */
    popv(3);
    return nil;
v163:
    popv(3);
    return nil;
}



/* Code for formclear */

static Lisp_Object MS_CDECL CC_formclear(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v42, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclear");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formclear");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v54 = v2;
    v42 = v1;
    v33 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* clear */
    v33 = qcdr(v33);
    fn = elt(env, 2); /* formclear1 */
    v54 = (*qfnn(fn))(qenv(fn), 3, v33, v42, v54);
    nil = C_nil;
    if (exception_pending()) goto v15;
    {
        Lisp_Object v126 = stack[0];
        popv(1);
        return list2(v126, v54);
    }
/* error exit handlers */
v15:
    popv(1);
    return nil;
}



/* Code for distri_pol */

static Lisp_Object CC_distri_pol(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for distri_pol");
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
    v93 = stack[-1];
    if (v93 == nil) goto v27;
    v93 = stack[-1];
    if (!consp(v93)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v93 = stack[-1];
    v93 = qcdr(v93);
    if (v93 == nil) goto v13;
    v93 = stack[-1];
    v93 = qcar(v93);
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    stack[0] = CC_distri_pol(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    v93 = stack[-1];
    v93 = qcdr(v93);
    v93 = CC_distri_pol(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    {
        Lisp_Object v195 = stack[0];
        popv(4);
        fn = elt(env, 2); /* addfd */
        return (*qfn2(fn))(qenv(fn), v195, v93);
    }

v13:
    v93 = (Lisp_Object)17; /* 1 */
    stack[0] = v93;
    v93 = stack[-1];
    stack[-2] = v93;
    goto v158;

v158:
    v93 = stack[-2];
    if (!consp(v93)) goto v121;
    v93 = stack[-2];
    v93 = qcdr(v93);
    v93 = (v93 == nil ? lisp_true : nil);
    goto v41;

v41:
    if (v93 == nil) goto v9;
    v93 = stack[-2];
    v93 = qcar(v93);
    v94 = qcar(v93);
    v93 = (Lisp_Object)17; /* 1 */
    v93 = cons(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    fn = elt(env, 3); /* multf */
    v93 = (*qfn2(fn))(qenv(fn), stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    stack[0] = v93;
    v93 = stack[-2];
    v93 = qcar(v93);
    v93 = qcdr(v93);
    stack[-2] = v93;
    goto v158;

v9:
    v93 = stack[-2];
    if (!consp(v93)) goto v152;
    stack[-1] = stack[0];
    v93 = stack[-2];
    v93 = qcar(v93);
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    v93 = CC_distri_pol(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    fn = elt(env, 3); /* multf */
    v93 = (*qfn2(fn))(qenv(fn), stack[-1], v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    stack[-1] = CC_distri_pol(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    v93 = stack[-2];
    v93 = qcdr(v93);
    v93 = CC_distri_pol(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    fn = elt(env, 3); /* multf */
    v93 = (*qfn2(fn))(qenv(fn), stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    v93 = CC_distri_pol(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    {
        Lisp_Object v196 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* addfd */
        return (*qfn2(fn))(qenv(fn), v196, v93);
    }

v152:
    v94 = stack[0];
    v93 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* multf */
        return (*qfn2(fn))(qenv(fn), v94, v93);
    }

v121:
    v93 = qvalue(elt(env, 1)); /* nil */
    goto v41;

v27:
    v93 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v93); }
/* error exit handlers */
v194:
    popv(4);
    return nil;
}



/* Code for ratleqp */

static Lisp_Object CC_ratleqp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratleqp");
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
    v49 = v1;
    v11 = v0;
/* end of prologue */
    fn = elt(env, 1); /* ratdif */
    v49 = (*qfn2(fn))(qenv(fn), v11, v49);
    errexit();
    v11 = qcar(v49);
    v49 = (Lisp_Object)1; /* 0 */
        return Lleq(nil, v11, v49);
}



/* Code for quotfail */

static Lisp_Object CC_quotfail(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v161, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail");
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
    v108 = stack[-1];
    if (v108 == nil) goto v28;
    v161 = stack[-1];
    v108 = stack[0];
    fn = elt(env, 3); /* quotf */
    v108 = (*qfn2(fn))(qenv(fn), v161, v108);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    v161 = v108;
    v108 = v161;
    if (!(v108 == nil)) { popv(3); return onevalue(v161); }
    v7 = elt(env, 2); /* "UNEXPECTED DIVISION FAILURE" */
    v161 = stack[-1];
    v108 = stack[0];
    v108 = list3(v7, v161, v108);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    fn = elt(env, 4); /* errorf */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v108 = nil;
    { popv(3); return onevalue(v108); }

v28:
    v108 = qvalue(elt(env, 1)); /* polyzero */
    { popv(3); return onevalue(v108); }
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



/* Code for cl_comember */

static Lisp_Object CC_cl_comember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v43, v36, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_comember");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v43 = v1;
    v36 = v0;
/* end of prologue */

v123:
    v44 = v43;
    if (v44 == nil) goto v24;
    v44 = v36;
    v8 = qcar(v44);
    v44 = v43;
    v44 = qcar(v44);
    v44 = qcar(v44);
    if (equal(v8, v44)) goto v32;
    v44 = v43;
    v44 = qcdr(v44);
    v43 = v44;
    goto v123;

v32:
    v44 = qvalue(elt(env, 1)); /* t */
    return onevalue(v44);

v24:
    v44 = nil;
    return onevalue(v44);
}



/* Code for vp2df */

static Lisp_Object MS_CDECL CC_vp2df(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v45, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vp2df");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vp2df");
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
    v45 = stack[-2];
    v18 = elt(env, 1); /* sqrt */
    if (!consp(v45)) goto v126;
    v45 = qcar(v45);
    if (!(v45 == v18)) goto v126;
    v45 = stack[-1];
    v18 = (Lisp_Object)17; /* 1 */
    v18 = (Lisp_Object)greaterp2(v45, v18);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v18 = v18 ? lisp_true : nil;
    env = stack[-3];
    goto v30;

v30:
    if (v18 == nil) goto v105;
    v46 = stack[-2];
    v45 = stack[-1];
    v18 = stack[0];
    fn = elt(env, 3); /* vp1 */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v46, v45, v18);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v18 = stack[0];
    fn = elt(env, 4); /* vp2 */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    {
        Lisp_Object v31 = stack[-1];
        popv(4);
        fn = elt(env, 5); /* mulpower */
        return (*qfn2(fn))(qenv(fn), v31, v18);
    }

v105:
    v46 = stack[-2];
    v45 = stack[-1];
    v18 = stack[0];
    fn = elt(env, 3); /* vp1 */
    v46 = (*qfnn(fn))(qenv(fn), 3, v46, v45, v18);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v45 = (Lisp_Object)17; /* 1 */
    v18 = (Lisp_Object)17; /* 1 */
    v18 = list2star(v46, v45, v18);
    nil = C_nil;
    if (exception_pending()) goto v47;
    popv(4);
    return ncons(v18);

v126:
    v18 = qvalue(elt(env, 2)); /* nil */
    goto v30;
/* error exit handlers */
v47:
    popv(4);
    return nil;
}



/* Code for quotelog */

static Lisp_Object CC_quotelog(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v156;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotelog");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v156 = v0;
/* end of prologue */
    v156 = elt(env, 1); /* logical */
    return onevalue(v156);
}



/* Code for pasf_negateat */

static Lisp_Object CC_pasf_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v145, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_negateat");
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
    v145 = stack[0];
    v206 = elt(env, 1); /* true */
    if (v145 == v206) goto v35;
    v145 = stack[0];
    v206 = elt(env, 3); /* false */
    v206 = (v145 == v206 ? lisp_true : nil);
    goto v144;

v144:
    if (v206 == nil) goto v142;
    v145 = stack[0];
    v206 = elt(env, 3); /* false */
    if (v145 == v206) goto v12;
    v206 = elt(env, 3); /* false */
    { popv(2); return onevalue(v206); }

v12:
    v206 = elt(env, 1); /* true */
    { popv(2); return onevalue(v206); }

v142:
    v145 = stack[0];
    v206 = elt(env, 1); /* true */
    if (v145 == v206) goto v26;
    v145 = stack[0];
    v206 = elt(env, 3); /* false */
    v206 = (v145 == v206 ? lisp_true : nil);
    goto v39;

v39:
    if (v206 == nil) goto v23;
    v206 = stack[0];
    v145 = v206;
    goto v22;

v22:
    v206 = elt(env, 4); /* (cong ncong) */
    v206 = Lmemq(nil, v145, v206);
    if (v206 == nil) goto v130;
    v145 = stack[0];
    v206 = elt(env, 1); /* true */
    if (v145 == v206) goto v207;
    v145 = stack[0];
    v206 = elt(env, 3); /* false */
    v206 = (v145 == v206 ? lisp_true : nil);
    goto v208;

v208:
    if (v206 == nil) goto v209;
    v206 = stack[0];
    goto v189;

v189:
    fn = elt(env, 5); /* pasf_lnegrel */
    v145 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-1];
    v206 = stack[0];
    v206 = qcar(v206);
    v206 = qcdr(v206);
    fn = elt(env, 6); /* pasf_mkop */
    v146 = (*qfn2(fn))(qenv(fn), v145, v206);
    nil = C_nil;
    if (exception_pending()) goto v210;
    v206 = stack[0];
    v206 = qcdr(v206);
    v145 = qcar(v206);
    v206 = stack[0];
    v206 = qcdr(v206);
    v206 = qcdr(v206);
    v206 = qcar(v206);
    popv(2);
    return list3(v146, v145, v206);

v209:
    v206 = stack[0];
    v206 = qcar(v206);
    v206 = Lconsp(nil, v206);
    env = stack[-1];
    if (v206 == nil) goto v211;
    v206 = stack[0];
    v206 = qcar(v206);
    v206 = qcar(v206);
    goto v189;

v211:
    v206 = stack[0];
    v206 = qcar(v206);
    goto v189;

v207:
    v206 = qvalue(elt(env, 2)); /* t */
    goto v208;

v130:
    v145 = stack[0];
    v206 = elt(env, 1); /* true */
    if (v145 == v206) goto v212;
    v145 = stack[0];
    v206 = elt(env, 3); /* false */
    v206 = (v145 == v206 ? lisp_true : nil);
    goto v213;

v213:
    if (v206 == nil) goto v81;
    v206 = stack[0];
    goto v214;

v214:
    fn = elt(env, 5); /* pasf_lnegrel */
    v146 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v210;
    v206 = stack[0];
    v206 = qcdr(v206);
    v145 = qcar(v206);
    v206 = stack[0];
    v206 = qcdr(v206);
    v206 = qcdr(v206);
    v206 = qcar(v206);
    popv(2);
    return list3(v146, v145, v206);

v81:
    v206 = stack[0];
    v206 = qcar(v206);
    v206 = Lconsp(nil, v206);
    env = stack[-1];
    if (v206 == nil) goto v75;
    v206 = stack[0];
    v206 = qcar(v206);
    v206 = qcar(v206);
    goto v214;

v75:
    v206 = stack[0];
    v206 = qcar(v206);
    goto v214;

v212:
    v206 = qvalue(elt(env, 2)); /* t */
    goto v213;

v23:
    v206 = stack[0];
    v206 = qcar(v206);
    v206 = Lconsp(nil, v206);
    env = stack[-1];
    if (v206 == nil) goto v215;
    v206 = stack[0];
    v206 = qcar(v206);
    v206 = qcar(v206);
    v145 = v206;
    goto v22;

v215:
    v206 = stack[0];
    v206 = qcar(v206);
    v145 = v206;
    goto v22;

v26:
    v206 = qvalue(elt(env, 2)); /* t */
    goto v39;

v35:
    v206 = qvalue(elt(env, 2)); /* t */
    goto v144;
/* error exit handlers */
v210:
    popv(2);
    return nil;
}



/* Code for xpwrlcmp */

static Lisp_Object CC_xpwrlcmp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpwrlcmp");
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
    v163 = stack[-1];
    if (!consp(v163)) goto v28;
    v154 = stack[-1];
    v163 = elt(env, 1); /* expt */
    if (!consp(v154)) goto v19;
    v154 = qcar(v154);
    if (!(v154 == v163)) goto v19;
    v163 = stack[-1];
    v163 = qcdr(v163);
    v154 = qcar(v163);
    v163 = stack[0];
    v163 = (equal(v154, v163) ? lisp_true : nil);
    goto v128;

v128:
    if (v163 == nil) goto v7;
    v163 = stack[-1];
    v163 = qcdr(v163);
    v163 = qcdr(v163);
    v163 = qcar(v163);
    {
        popv(4);
        fn = elt(env, 4); /* getdenom */
        return (*qfn1(fn))(qenv(fn), v163);
    }

v7:
    v154 = stack[-1];
    v163 = elt(env, 3); /* sqrt */
    if (!consp(v154)) goto v122;
    v154 = qcar(v154);
    if (!(v154 == v163)) goto v122;
    v163 = stack[-1];
    v163 = qcdr(v163);
    v154 = qcar(v163);
    v163 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* getdenomx */
        return (*qfn2(fn))(qenv(fn), v154, v163);
    }

v122:
    v163 = stack[-1];
    v154 = qcar(v163);
    v163 = stack[0];
    stack[-2] = CC_xpwrlcmp(env, v154, v163);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-3];
    v163 = stack[-1];
    v154 = qcdr(v163);
    v163 = stack[0];
    v163 = CC_xpwrlcmp(env, v154, v163);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-3];
    {
        Lisp_Object v217 = stack[-2];
        popv(4);
        fn = elt(env, 6); /* lcm */
        return (*qfn2(fn))(qenv(fn), v217, v163);
    }

v19:
    v163 = qvalue(elt(env, 2)); /* nil */
    goto v128;

v28:
    v163 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v163); }
/* error exit handlers */
v191:
    popv(4);
    return nil;
}



/* Code for spinnerprod */

static Lisp_Object MS_CDECL CC_spinnerprod(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v156,
                         Lisp_Object v27, Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v89, v90, v220;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "spinnerprod");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spinnerprod");
#endif
    if (stack >= stacklimit)
    {
        push6(v28,v27,v156,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v2,v156,v27,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v28;
    v138 = v27;
    v89 = v156;
    stack[-5] = v2;
    v90 = v1;
    v220 = v0;
/* end of prologue */
    stack[-6] = v89;
    v89 = stack[-6];
    stack[-3] = v89;
    v138 = qcdr(v138);
    stack[-1] = v138;
    goto v49;

v49:
    v138 = stack[-1];
    if (v138 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v138 = stack[-1];
    v138 = qcar(v138);
    v89 = v138;
    v138 = v89;
    v138 = qcar(v138);
    stack[-7] = v138;
    v138 = stack[-7];
    if (!(v138 == nil)) goto v44;
    v138 = (Lisp_Object)1; /* 0 */
    stack[-7] = v138;
    goto v44;

v44:
    v138 = v89;
    v138 = qcdr(v138);
    stack[-2] = v138;
    v138 = stack[-2];
    if (v138 == nil) goto v22;
    stack[0] = stack[-2];
    v138 = qvalue(elt(env, 1)); /* nil */
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-8];
    v138 = (equal(stack[0], v138) ? lisp_true : nil);
    goto v40;

v40:
    if (v138 == nil) goto v4;
    v138 = (Lisp_Object)1; /* 0 */
    stack[-2] = v138;
    goto v4;

v4:
    v89 = stack[-7];
    v138 = stack[-5];
    v138 = (Lisp_Object)lesseq2(v89, v138);
    nil = C_nil;
    if (exception_pending()) goto v221;
    v138 = v138 ? lisp_true : nil;
    env = stack[-8];
    if (v138 == nil) goto v104;
    v89 = stack[-7];
    v138 = stack[-4];
    v138 = Latsoc(nil, v89, v138);
    stack[-7] = v138;
    v138 = stack[-7];
    if (v138 == nil) goto v101;
    stack[0] = stack[-7];
    v138 = qvalue(elt(env, 1)); /* nil */
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-8];
    v138 = (equal(stack[0], v138) ? lisp_true : nil);
    goto v154;

v154:
    if (!(v138 == nil)) goto v104;
    stack[0] = elt(env, 3); /* plus */
    stack[-3] = stack[-6];
    v90 = elt(env, 4); /* times */
    v89 = stack[-2];
    v138 = stack[-7];
    v138 = qcdr(v138);
    v138 = list3(v90, v89, v138);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-8];
    v138 = list3(stack[0], stack[-3], v138);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-8];
    stack[-6] = v138;
    v138 = stack[-6];
    stack[-3] = v138;
    goto v104;

v104:
    v138 = stack[-1];
    v138 = qcdr(v138);
    stack[-1] = v138;
    goto v49;

v101:
    v138 = qvalue(elt(env, 2)); /* t */
    goto v154;

v22:
    v138 = qvalue(elt(env, 2)); /* t */
    goto v40;
/* error exit handlers */
v221:
    popv(9);
    return nil;
}



/* Code for vdplsortin */

static Lisp_Object CC_vdplsortin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v33, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdplsortin");
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
    v33 = v0;
/* end of prologue */
    v42 = stack[0];
    if (v42 == nil) goto v28;
    v14 = v33;
    v33 = stack[0];
    v42 = stack[0];
    fn = elt(env, 1); /* vdplsortin1 */
    v42 = (*qfnn(fn))(qenv(fn), 3, v14, v33, v42);
    nil = C_nil;
    if (exception_pending()) goto v126;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v28:
    v42 = v33;
    popv(1);
    return ncons(v42);
/* error exit handlers */
v126:
    popv(1);
    return nil;
}



/* Code for mkuniquewedge1 */

static Lisp_Object CC_mkuniquewedge1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkuniquewedge1");
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
    v9 = stack[0];
    v9 = qcdr(v9);
    if (v9 == nil) goto v27;
    v9 = qvalue(elt(env, 1)); /* wedgemtch!* */
    if (v9 == nil) goto v29;
    v9 = stack[0];
    fn = elt(env, 3); /* wedgemtch */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v158 = v9;
    if (v9 == nil) goto v29;
    v9 = v158;
    {
        popv(2);
        fn = elt(env, 4); /* partitop */
        return (*qfn1(fn))(qenv(fn), v9);
    }

v29:
    v158 = elt(env, 2); /* wedge */
    v9 = stack[0];
    v9 = cons(v158, v9);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 5); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v9);
    }

v27:
    v9 = stack[0];
    v9 = qcar(v9);
    {
        popv(2);
        fn = elt(env, 5); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v9);
    }
/* error exit handlers */
v107:
    popv(2);
    return nil;
}



/* Code for preproc1 */

static Lisp_Object CC_preproc1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v302, v303, v304;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preproc1");
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
    stack[-1] = v0;
/* end of prologue */

v27:
    v302 = stack[-1];
    if (!consp(v302)) goto v144;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 1); /* !:rd!: */
    if (v303 == v302) goto v128;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 2); /* !:dn!: */
    if (v303 == v302) goto v139;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 3); /* !*sq */
    if (v303 == v302) goto v99;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 5); /* procedure */
    if (v303 == v302) goto v220;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 11); /* declare */
    if (v303 == v302) goto v305;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 14); /* setq */
    if (v303 == v302) goto v306;
    v302 = qvalue(elt(env, 9)); /* nil */
    goto v307;

v307:
    if (v302 == nil) goto v308;
    v302 = stack[-1];
    {
        popv(6);
        fn = elt(env, 21); /* migrate!-setqs */
        return (*qfn1(fn))(qenv(fn), v302);
    }

v308:
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 16); /* (plus times difference quotient minus) */
    v302 = Lmemq(nil, v303, v302);
    if (v302 == nil) goto v309;
    v302 = stack[-1];
    fn = elt(env, 22); /* simp!* */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v304 = v302;
    v302 = qcar(v302);
    v302 = Lconsp(nil, v302);
    env = stack[-5];
    if (v302 == nil) goto v311;
    v302 = v304;
    v302 = qcar(v302);
    v303 = qcar(v302);
    v302 = elt(env, 17); /* (!:cr!: !:crn!: !:gi!:) */
    v302 = Lmemq(nil, v303, v302);
    if (v302 == nil) goto v311;
    v302 = v304;
    v302 = qcdr(v302);
    v302 = Lonep(nil, v302);
    env = stack[-5];
    if (v302 == nil) goto v312;
    v302 = v304;
    v302 = qcar(v302);
    popv(6);
    return ncons(v302);

v312:
    stack[-1] = elt(env, 18); /* quotient */
    v302 = v304;
    stack[0] = qcar(v302);
    v302 = v304;
    v303 = qcdr(v302);
    v302 = (Lisp_Object)17; /* 1 */
    v302 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v303 = v302;
    v302 = v303;
    v302 = qcar(v302);
    if (v302 == nil) goto v313;
    v302 = elt(env, 4); /* prepf */
    fn = elt(env, 23); /* sqform */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    goto v314;

v314:
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = qcar(v302);
    v302 = list3(stack[-1], stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    popv(6);
    return ncons(v302);

v313:
    v302 = (Lisp_Object)1; /* 0 */
    goto v314;

v311:
    v302 = stack[-1];
    stack[-3] = v302;
    goto v315;

v315:
    v302 = stack[-3];
    if (v302 == nil) goto v316;
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-2] = v302;
    v302 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    v302 = stack[-1];
    if (!consp(v302)) goto v315;
    else goto v317;

v317:
    v302 = stack[-3];
    if (v302 == nil) goto v318;
    stack[0] = stack[-1];
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = Lrplacd(nil, stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    goto v317;

v318:
    v302 = stack[-2];
    goto v319;

v319:
    popv(6);
    return ncons(v302);

v316:
    v302 = qvalue(elt(env, 9)); /* nil */
    goto v319;

v309:
    v302 = qvalue(elt(env, 7)); /* !*getdecs */
    if (v302 == nil) goto v320;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 19); /* (!~for for) */
    v302 = Lmemq(nil, v303, v302);
    if (v302 == nil) goto v320;
    v304 = qvalue(elt(env, 9)); /* nil */
    v302 = stack[-1];
    v302 = qcdr(v302);
    v303 = qcar(v302);
    v302 = elt(env, 20); /* (integer) */
    fn = elt(env, 25); /* symtabput */
    v302 = (*qfnn(fn))(qenv(fn), 3, v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    goto v320;

v320:
    v302 = stack[-1];
    stack[-3] = v302;
    goto v321;

v321:
    v302 = stack[-3];
    if (v302 == nil) goto v322;
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-2] = v302;
    v302 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    v302 = stack[-1];
    if (!consp(v302)) goto v321;
    else goto v323;

v323:
    v302 = stack[-3];
    if (v302 == nil) goto v324;
    stack[0] = stack[-1];
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = Lrplacd(nil, stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    goto v323;

v324:
    v302 = stack[-2];
    goto v325;

v325:
    popv(6);
    return ncons(v302);

v322:
    v302 = qvalue(elt(env, 9)); /* nil */
    goto v325;

v306:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v302 = Lconsp(nil, v302);
    env = stack[-5];
    if (v302 == nil) goto v326;
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v303 = qcar(v302);
    v302 = elt(env, 15); /* (cond progn) */
    v302 = Lmemq(nil, v303, v302);
    goto v307;

v326:
    v302 = qvalue(elt(env, 9)); /* nil */
    goto v307;

v305:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = qcar(v302);
    stack[-1] = v302;
    v302 = stack[-1];
    fn = elt(env, 26); /* preprocdec */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    v302 = stack[-1];
    stack[-4] = v302;
    goto v327;

v327:
    v302 = stack[-4];
    if (v302 == nil) goto v328;
    v302 = stack[-4];
    v302 = qcar(v302);
    stack[-3] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-2] = v302;
    goto v329;

v329:
    v302 = stack[-2];
    if (v302 == nil) goto v330;
    v302 = stack[-2];
    v302 = qcar(v302);
    v304 = v302;
    v302 = stack[-3];
    v303 = qcar(v302);
    v302 = elt(env, 12); /* (subroutine function) */
    v302 = Lmemq(nil, v303, v302);
    if (v302 == nil) goto v331;
    v303 = elt(env, 13); /* !*type!* */
    v302 = stack[-3];
    v302 = qcar(v302);
    fn = elt(env, 25); /* symtabput */
    v302 = (*qfnn(fn))(qenv(fn), 3, v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    goto v332;

v332:
    v302 = stack[-2];
    v302 = qcdr(v302);
    stack[-2] = v302;
    goto v329;

v331:
    stack[-1] = qvalue(elt(env, 9)); /* nil */
    v302 = v304;
    if (!consp(v302)) goto v333;
    v302 = v304;
    v302 = qcar(v302);
    stack[0] = v302;
    goto v334;

v334:
    v302 = v304;
    if (!consp(v302)) goto v335;
    v302 = stack[-3];
    v302 = qcar(v302);
    v303 = v304;
    v303 = qcdr(v303);
    v302 = cons(v302, v303);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    goto v336;

v336:
    fn = elt(env, 25); /* symtabput */
    v302 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    goto v332;

v335:
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = ncons(v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    goto v336;

v333:
    v302 = v304;
    stack[0] = v302;
    goto v334;

v330:
    v302 = stack[-4];
    v302 = qcdr(v302);
    stack[-4] = v302;
    goto v327;

v328:
    v302 = qvalue(elt(env, 9)); /* nil */
    { popv(6); return onevalue(v302); }

v220:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v304 = qcar(v302);
    v303 = elt(env, 6); /* !*params!* */
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    fn = elt(env, 25); /* symtabput */
    v302 = (*qfnn(fn))(qenv(fn), 3, v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = qvalue(elt(env, 7)); /* !*getdecs */
    if (v302 == nil) goto v337;
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v303 = qcar(v302);
    v302 = elt(env, 8); /* (real integer) */
    v302 = Lmemq(nil, v303, v302);
    if (v302 == nil) goto v338;
    v302 = stack[-1];
    v302 = qcdr(v302);
    stack[-2] = qcar(v302);
    v302 = stack[-1];
    v302 = qcdr(v302);
    stack[0] = qcar(v302);
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v302 = ncons(v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    fn = elt(env, 25); /* symtabput */
    v302 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    stack[-3] = v302;
    goto v186;

v186:
    v302 = stack[-3];
    if (v302 == nil) goto v339;
    v302 = stack[-3];
    v302 = qcar(v302);
    v303 = v302;
    v302 = stack[-1];
    v302 = qcdr(v302);
    stack[-2] = qcar(v302);
    stack[0] = v303;
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v302 = ncons(v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    fn = elt(env, 25); /* symtabput */
    v302 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    goto v186;

v339:
    v304 = elt(env, 5); /* procedure */
    v302 = stack[-1];
    v302 = qcdr(v302);
    v303 = qcar(v302);
    v302 = nil;
    stack[-4] = list3(v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    stack[-3] = v302;
    goto v340;

v340:
    v302 = stack[-3];
    if (v302 == nil) goto v341;
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-2] = v302;
    v302 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    v302 = stack[-1];
    if (!consp(v302)) goto v340;
    else goto v342;

v342:
    v302 = stack[-3];
    if (v302 == nil) goto v343;
    stack[0] = stack[-1];
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = Lrplacd(nil, stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    goto v342;

v343:
    v302 = stack[-2];
    goto v344;

v344:
    v302 = Lnconc(nil, stack[-4], v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    popv(6);
    return ncons(v302);

v341:
    v302 = qvalue(elt(env, 9)); /* nil */
    goto v344;

v338:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    stack[-3] = v302;
    goto v345;

v345:
    v302 = stack[-3];
    if (v302 == nil) goto v346;
    v302 = stack[-3];
    v302 = qcar(v302);
    v303 = v302;
    v302 = stack[-1];
    v302 = qcdr(v302);
    stack[-2] = qcar(v302);
    stack[0] = v303;
    v302 = qvalue(elt(env, 10)); /* deftype!* */
    v302 = ncons(v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    fn = elt(env, 25); /* symtabput */
    v302 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    goto v345;

v346:
    v302 = stack[-1];
    stack[-3] = v302;
    goto v347;

v347:
    v302 = stack[-3];
    if (v302 == nil) goto v348;
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-2] = v302;
    v302 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    v302 = stack[-1];
    if (!consp(v302)) goto v347;
    else goto v349;

v349:
    v302 = stack[-3];
    if (v302 == nil) goto v350;
    stack[0] = stack[-1];
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = Lrplacd(nil, stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    goto v349;

v350:
    v302 = stack[-2];
    goto v351;

v351:
    popv(6);
    return ncons(v302);

v348:
    v302 = qvalue(elt(env, 9)); /* nil */
    goto v351;

v337:
    v302 = stack[-1];
    stack[-3] = v302;
    goto v352;

v352:
    v302 = stack[-3];
    if (v302 == nil) goto v353;
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-2] = v302;
    v302 = stack[-2];
    fn = elt(env, 24); /* lastpair */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    v302 = stack[-1];
    if (!consp(v302)) goto v352;
    else goto v354;

v354:
    v302 = stack[-3];
    if (v302 == nil) goto v355;
    stack[0] = stack[-1];
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = CC_preproc1(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = Lrplacd(nil, stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    v302 = stack[-1];
    fn = elt(env, 24); /* lastpair */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    goto v354;

v355:
    v302 = stack[-2];
    goto v356;

v356:
    popv(6);
    return ncons(v302);

v353:
    v302 = qvalue(elt(env, 9)); /* nil */
    goto v356;

v99:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v302 = qcar(v302);
    if (v302 == nil) goto v209;
    v302 = stack[-1];
    v302 = qcdr(v302);
    v303 = qcar(v302);
    v302 = elt(env, 4); /* prepf */
    fn = elt(env, 23); /* sqform */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    goto v357;

v357:
    stack[-1] = v302;
    goto v27;

v209:
    v302 = (Lisp_Object)1; /* 0 */
    goto v357;

v139:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v303 = qcar(v302);
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    fn = elt(env, 27); /* decimal2internal */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    stack[-1] = v302;
    goto v27;

v128:
    v302 = stack[-1];
    v302 = qcdr(v302);
    if (!consp(v302)) goto v33;
    v302 = stack[-1];
    goto v42;

v42:
    popv(6);
    return ncons(v302);

v33:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = Lfloatp(nil, v302);
    env = stack[-5];
    if (v302 == nil) goto v158;
    v302 = stack[-1];
    v302 = qcdr(v302);
    fn = elt(env, 28); /* fl2bf */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    goto v42;

v158:
    v302 = stack[-1];
    v302 = qcdr(v302);
    if (!consp(v302)) goto v41;
    v302 = stack[-1];
    v302 = qcdr(v302);
    goto v161;

v161:
    fn = elt(env, 29); /* csl_normbf */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    goto v42;

v41:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = integerp(v302);
    if (v302 == nil) goto v3;
    v304 = elt(env, 1); /* !:rd!: */
    v302 = stack[-1];
    v303 = qcdr(v302);
    v302 = (Lisp_Object)1; /* 0 */
    v302 = list2star(v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    goto v161;

v3:
    v302 = stack[-1];
    v302 = qcdr(v302);
    fn = elt(env, 30); /* read!:num */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-5];
    goto v161;

v144:
    v302 = stack[-1];
    popv(6);
    return ncons(v302);
/* error exit handlers */
v310:
    popv(6);
    return nil;
}



/* Code for mk_simpl_map_ */

static Lisp_Object CC_mk_simpl_map_(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_simpl_map_");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */
    v162 = v32;
    v32 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* mk_simpl_map_1 */
        return (*qfn2(fn))(qenv(fn), v162, v32);
    }
}



/* Code for red_prepare */

static Lisp_Object CC_red_prepare(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_prepare");
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
    v42 = stack[-1];
    fn = elt(env, 1); /* bas_nr */
    stack[-2] = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    v42 = stack[-1];
    fn = elt(env, 2); /* bas_dpoly */
    stack[0] = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    v42 = stack[-1];
    fn = elt(env, 3); /* bas_rep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    v42 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 4); /* dp_from_ei */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    fn = elt(env, 5); /* dp_sum */
    v42 = (*qfn2(fn))(qenv(fn), stack[-1], v42);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    {
        Lisp_Object v13 = stack[-2];
        Lisp_Object v12 = stack[0];
        popv(4);
        fn = elt(env, 6); /* bas_make1 */
        return (*qfnn(fn))(qenv(fn), 3, v13, v12, v42);
    }
/* error exit handlers */
v126:
    popv(4);
    return nil;
}



/* Code for dv_skel2factor */

static Lisp_Object CC_dv_skel2factor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skel2factor");
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
    v154 = v1;
    stack[-4] = v0;
/* end of prologue */
    v163 = stack[-4];
    v163 = qcdr(v163);
    if (v163 == nil) goto v30;
    v163 = stack[-4];
    v163 = qcdr(v163);
    v163 = Lsublis(nil, v154, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-6];
    stack[-5] = v163;
    v163 = stack[-5];
    fn = elt(env, 2); /* st_ad_numsorttree */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-6];
    stack[-5] = v163;
    v163 = stack[-5];
    v163 = qcdr(v163);
    fn = elt(env, 3); /* st_flatten */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-6];
    stack[-3] = v163;
    v163 = stack[-3];
    if (v163 == nil) goto v8;
    v163 = stack[-3];
    v163 = qcar(v163);
    fn = elt(env, 4); /* dv_ind2var */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-6];
    v163 = ncons(v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-6];
    stack[-1] = v163;
    stack[-2] = v163;
    goto v29;

v29:
    v163 = stack[-3];
    v163 = qcdr(v163);
    stack[-3] = v163;
    v163 = stack[-3];
    if (v163 == nil) goto v155;
    stack[0] = stack[-1];
    v163 = stack[-3];
    v163 = qcar(v163);
    fn = elt(env, 4); /* dv_ind2var */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-6];
    v163 = ncons(v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-6];
    v163 = Lrplacd(nil, stack[0], v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-6];
    v163 = stack[-1];
    v163 = qcdr(v163);
    stack[-1] = v163;
    goto v29;

v155:
    v163 = stack[-2];
    goto v38;

v38:
    v154 = stack[-5];
    stack[0] = qcar(v154);
    v154 = stack[-4];
    v154 = qcar(v154);
    fn = elt(env, 5); /* dv_skel2factor1 */
    v163 = (*qfn2(fn))(qenv(fn), v154, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    {
        Lisp_Object v168 = stack[0];
        popv(7);
        return cons(v168, v163);
    }

v8:
    v163 = qvalue(elt(env, 1)); /* nil */
    goto v38;

v30:
    v163 = stack[-4];
    v163 = qcar(v163);
    { popv(7); return onevalue(v163); }
/* error exit handlers */
v167:
    popv(7);
    return nil;
}



/* Code for derivative!-mod!-p */

static Lisp_Object CC_derivativeKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v22, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for derivative-mod-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v48 = v0;
/* end of prologue */
    v40 = v48;
    if (!consp(v40)) goto v35;
    v40 = v48;
    v40 = qcar(v40);
    v40 = (consp(v40) ? nil : lisp_true);
    goto v144;

v144:
    if (v40 == nil) goto v11;
    v40 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v40);

v11:
    v40 = v48;
    v40 = qcar(v40);
    v40 = qcar(v40);
    v22 = qcdr(v40);
    v40 = (Lisp_Object)17; /* 1 */
    if (v22 == v40) goto v20;
    v40 = v48;
    v22 = v48;
    v22 = qcar(v22);
    v22 = qcar(v22);
    v22 = qcar(v22);
    {
        fn = elt(env, 3); /* derivative!-mod!-p!-1 */
        return (*qfn2(fn))(qenv(fn), v40, v22);
    }

v20:
    v40 = v48;
    v40 = qcar(v40);
    v40 = qcdr(v40);
    return onevalue(v40);

v35:
    v40 = qvalue(elt(env, 1)); /* t */
    goto v144;
}



/* Code for linineqevaltest */

static Lisp_Object CC_linineqevaltest(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v21, v164, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for linineqevaltest");
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
    v21 = v1;
    v164 = v0;
/* end of prologue */

v24:
    v216 = v164;
    if (!consp(v216)) goto v124;
    v216 = v164;
    v216 = qcar(v216);
    v216 = (consp(v216) ? nil : lisp_true);
    goto v128;

v128:
    if (!(v216 == nil)) { popv(2); return onevalue(v21); }
    v216 = v164;
    v216 = qcar(v216);
    v216 = qcar(v216);
    v47 = qcdr(v216);
    v216 = (Lisp_Object)17; /* 1 */
    if (v47 == v216) goto v48;
    v216 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v216; /* !*ineqerr */
    v216 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v216 == nil)) goto v158;
    v216 = elt(env, 4); /* "unable to process nonlinear system" */
    fn = elt(env, 5); /* lprie */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    goto v158;

v158:
    v216 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v216 = nil;
    { popv(2); return onevalue(v216); }

v48:
    v216 = v164;
    v216 = qcar(v216);
    v216 = qcar(v216);
    v47 = qcar(v216);
    v216 = v21;
    v216 = Lmember(nil, v47, v216);
    if (v216 == nil) goto v165;
    v216 = v164;
    v216 = qcdr(v216);
    v164 = v216;
    goto v24;

v165:
    v216 = v164;
    v216 = qcdr(v216);
    stack[0] = v216;
    v216 = v164;
    v216 = qcar(v216);
    v216 = qcar(v216);
    v216 = qcar(v216);
    v216 = cons(v216, v21);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v21 = v216;
    v216 = stack[0];
    v164 = v216;
    goto v24;

v124:
    v216 = qvalue(elt(env, 1)); /* t */
    goto v128;
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for ordered!-gcd!-mod!-p */

static Lisp_Object CC_orderedKgcdKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordered-gcd-mod-p");
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
    v47 = (Lisp_Object)1; /* 0 */
    stack[-2] = v47;
    goto v30;

v30:
    v31 = stack[-1];
    v47 = stack[0];
    fn = elt(env, 3); /* reduce!-degree!-mod!-p */
    v47 = (*qfn2(fn))(qenv(fn), v31, v47);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-3];
    stack[-1] = v47;
    v47 = stack[-1];
    if (v47 == nil) goto v20;
    v47 = stack[-2];
    v47 = add1(v47);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-3];
    stack[-2] = v47;
    v47 = stack[-1];
    if (!consp(v47)) goto v29;
    v47 = stack[-1];
    v47 = qcar(v47);
    v47 = (consp(v47) ? nil : lisp_true);
    goto v12;

v12:
    if (v47 == nil) goto v121;
    v31 = qvalue(elt(env, 2)); /* reduction!-count */
    v47 = stack[-2];
    v47 = plus2(v31, v47);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-3];
    qvalue(elt(env, 2)) = v47; /* reduction!-count */
    v47 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v47); }

v121:
    v47 = stack[-1];
    v47 = qcar(v47);
    v47 = qcar(v47);
    v31 = qcdr(v47);
    v47 = stack[0];
    v47 = qcar(v47);
    v47 = qcar(v47);
    v47 = qcdr(v47);
    v47 = (Lisp_Object)lessp2(v31, v47);
    nil = C_nil;
    if (exception_pending()) goto v215;
    v47 = v47 ? lisp_true : nil;
    env = stack[-3];
    if (v47 == nil) goto v30;
    v31 = qvalue(elt(env, 2)); /* reduction!-count */
    v47 = stack[-2];
    v47 = plus2(v31, v47);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-3];
    qvalue(elt(env, 2)) = v47; /* reduction!-count */
    v47 = (Lisp_Object)1; /* 0 */
    stack[-2] = v47;
    v47 = stack[-1];
    v31 = v47;
    v47 = stack[0];
    stack[-1] = v47;
    v47 = v31;
    stack[0] = v47;
    goto v30;

v29:
    v47 = qvalue(elt(env, 1)); /* t */
    goto v12;

v20:
    v47 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* monic!-mod!-p */
        return (*qfn1(fn))(qenv(fn), v47);
    }
/* error exit handlers */
v215:
    popv(4);
    return nil;
}



/* Code for polynomreduceby */

static Lisp_Object CC_polynomreduceby(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomreduceby");
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
    goto v32;

v32:
    v103 = stack[-3];
    if (v103 == nil) goto v128;
    v103 = qvalue(elt(env, 3)); /* fluidbibasisreductionsmade */
    v103 = (Lisp_Object)((int32_t)(v103) + 0x10);
    qvalue(elt(env, 3)) = v103; /* fluidbibasisreductionsmade */
    v103 = nil;
    { popv(5); return onevalue(v103); }

v128:
    v103 = stack[-2];
    stack[0] = v103;
    goto v11;

v11:
    v103 = stack[0];
    v103 = qcar(v103);
    if (v103 == nil) goto v49;
    v103 = stack[0];
    v152 = qcar(v103);
    v103 = stack[-1];
    v103 = qcar(v103);
    fn = elt(env, 4); /* monomisdivisibleby */
    v103 = (*qfn2(fn))(qenv(fn), v152, v103);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    if (!(v103 == nil)) goto v49;
    v103 = stack[0];
    v103 = qcdr(v103);
    stack[0] = v103;
    goto v11;

v49:
    v103 = stack[0];
    v103 = qcar(v103);
    if (v103 == nil) goto v41;
    v103 = stack[0];
    v152 = qcar(v103);
    v103 = stack[-1];
    v103 = qcar(v103);
    fn = elt(env, 5); /* monomdivide */
    v103 = (*qfn2(fn))(qenv(fn), v152, v103);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    stack[0] = stack[-2];
    v152 = stack[-1];
    fn = elt(env, 6); /* polynommultiplybymonom */
    v103 = (*qfn2(fn))(qenv(fn), v152, v103);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    fn = elt(env, 7); /* polynomadd */
    v103 = (*qfn2(fn))(qenv(fn), stack[0], v103);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    goto v32;

v41:
    v103 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v103;
    goto v32;
/* error exit handlers */
v154:
    popv(5);
    return nil;
}



/* Code for qqe_dfs */

static Lisp_Object CC_qqe_dfs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_dfs");
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
    v103 = v0;
/* end of prologue */
    v31 = qvalue(elt(env, 1)); /* t */
    stack[0] = v31;
    v31 = v103;
    if (!consp(v31)) goto v49;
    v31 = v103;
    stack[-2] = v31;
    goto v34;

v34:
    v31 = stack[-2];
    if (v31 == nil) goto v29;
    v31 = stack[0];
    if (v31 == nil) goto v29;
    v31 = stack[-2];
    v103 = qcar(v31);
    v31 = stack[-1];
    if (!(v103 == v31)) goto v129;
    v31 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v31;
    goto v129;

v129:
    v31 = stack[-2];
    v103 = qcar(v31);
    v31 = stack[-1];
    v31 = CC_qqe_dfs(env, v103, v31);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    if (v31 == nil) goto v26;
    v31 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v31;
    goto v26;

v26:
    v31 = stack[-2];
    v31 = qcdr(v31);
    stack[-2] = v31;
    goto v34;

v29:
    v31 = stack[0];
    if (v31 == nil) goto v21;
    v31 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v31); }

v21:
    v31 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v31); }

v49:
    v31 = stack[-1];
    if (v103 == v31) goto v127;
    v31 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v31); }

v127:
    v31 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v31); }
/* error exit handlers */
v139:
    popv(4);
    return nil;
}



setup_type const u42_setup[] =
{
    {"find_active_components",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_active_components},
    {"ofsf_irl2atl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_irl2atl},
    {"freeof-dfl",              too_few_2,      CC_freeofKdfl, wrong_no_2},
    {"mri_varlat",              CC_mri_varlat,  too_many_1,    wrong_no_1},
    {"qqe_simplqneq",           too_few_2,      CC_qqe_simplqneq,wrong_no_2},
    {"cl_dnf",                  CC_cl_dnf,      too_many_1,    wrong_no_1},
    {"ps:onep:",                CC_psTonepT,    too_many_1,    wrong_no_1},
    {"init",                    CC_init,        too_many_1,    wrong_no_1},
    {"expttermp1",              too_few_2,      CC_expttermp1, wrong_no_2},
    {"dipcontenti1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipcontenti1},
    {"matcheq",                 too_few_2,      CC_matcheq,    wrong_no_2},
    {"denlist",                 too_few_2,      CC_denlist,    wrong_no_2},
    {"degree-order",            too_few_2,      CC_degreeKorder,wrong_no_2},
    {"actual_arguments",        CC_actual_arguments,too_many_1,wrong_no_1},
    {"dp_2a",                   CC_dp_2a,       too_many_1,    wrong_no_1},
    {"sub01",                   too_few_2,      CC_sub01,      wrong_no_2},
    {"rl_nnfnot",               CC_rl_nnfnot,   too_many_1,    wrong_no_1},
    {"uterm",                   too_few_2,      CC_uterm,      wrong_no_2},
    {"gigcd:",                  too_few_2,      CC_gigcdT,     wrong_no_2},
    {"pasf_uprap",              CC_pasf_uprap,  too_many_1,    wrong_no_1},
    {"bc_neg",                  CC_bc_neg,      too_many_1,    wrong_no_1},
    {":mod:units",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_TmodTunits},
    {"weak_xreduce1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_weak_xreduce1},
    {"tot-asym-indp",           CC_totKasymKindp,too_many_1,   wrong_no_1},
    {"fctinsert",               too_few_2,      CC_fctinsert,  wrong_no_2},
    {"coeff_sortl",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff_sortl},
    {"vdelete",                 too_few_2,      CC_vdelete,    wrong_no_2},
    {"quotfexf*1",              too_few_2,      CC_quotfexfH1, wrong_no_2},
    {"formclear",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclear},
    {"distri_pol",              CC_distri_pol,  too_many_1,    wrong_no_1},
    {"ratleqp",                 too_few_2,      CC_ratleqp,    wrong_no_2},
    {"quotfail",                too_few_2,      CC_quotfail,   wrong_no_2},
    {"cl_comember",             too_few_2,      CC_cl_comember,wrong_no_2},
    {"vp2df",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_vp2df},
    {"quotelog",                CC_quotelog,    too_many_1,    wrong_no_1},
    {"pasf_negateat",           CC_pasf_negateat,too_many_1,   wrong_no_1},
    {"xpwrlcmp",                too_few_2,      CC_xpwrlcmp,   wrong_no_2},
    {"spinnerprod",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_spinnerprod},
    {"vdplsortin",              too_few_2,      CC_vdplsortin, wrong_no_2},
    {"mkuniquewedge1",          CC_mkuniquewedge1,too_many_1,  wrong_no_1},
    {"preproc1",                CC_preproc1,    too_many_1,    wrong_no_1},
    {"mk_simpl_map_",           CC_mk_simpl_map_,too_many_1,   wrong_no_1},
    {"red_prepare",             CC_red_prepare, too_many_1,    wrong_no_1},
    {"dv_skel2factor",          too_few_2,      CC_dv_skel2factor,wrong_no_2},
    {"derivative-mod-p",        CC_derivativeKmodKp,too_many_1,wrong_no_1},
    {"linineqevaltest",         too_few_2,      CC_linineqevaltest,wrong_no_2},
    {"ordered-gcd-mod-p",       too_few_2,      CC_orderedKgcdKmodKp,wrong_no_2},
    {"polynomreduceby",         too_few_2,      CC_polynomreduceby,wrong_no_2},
    {"qqe_dfs",                 too_few_2,      CC_qqe_dfs,    wrong_no_2},
    {NULL, (one_args *)"u42", (two_args *)"16113 1142929 9720855", 0}
};

/* end of generated code */
