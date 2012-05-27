
/* $destdir\u06.c        Machine generated C code */

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


/* Code for token1 */

static Lisp_Object MS_CDECL CC_token1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "token1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for token1");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* end of prologue */
    stack[-2] = nil;
    v65 = qvalue(elt(env, 1)); /* crchar!* */
    stack[-3] = v65;
    goto v67;

v67:
    v65 = stack[-3];
    v65 = Lwhitespace_char_p(nil, v65);
    env = stack[-4];
    if (v65 == nil) goto v68;
    v66 = stack[-3];
    v65 = qvalue(elt(env, 2)); /* !$eol!$ */
    if (v66 == v65) goto v69;
    v65 = qvalue(elt(env, 4)); /* nil */
    goto v70;

v70:
    if (!(v65 == nil)) goto v68;
    fn = elt(env, 24); /* readch1 */
    v65 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-3] = v65;
    goto v67;

v68:
    v65 = stack[-3];
    v65 = Ldigitp(nil, v65);
    env = stack[-4];
    if (v65 == nil) goto v72;
    v65 = stack[-3];
    {
        popv(5);
        fn = elt(env, 25); /* token!-number */
        return (*qfn1(fn))(qenv(fn), v65);
    }

v72:
    v65 = stack[-3];
    v65 = Lalpha_char_p(nil, v65);
    env = stack[-4];
    if (!(v65 == nil)) goto v73;
    v66 = stack[-3];
    v65 = elt(env, 5); /* tokprop */
    v65 = get(v66, v65);
    env = stack[-4];
    stack[-2] = v65;
    if (v65 == nil) goto v74;
    v66 = stack[-2];
    v65 = qvalue(elt(env, 4)); /* nil */
    {
        popv(5);
        fn = elt(env, 26); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v66, v65);
    }

v74:
    v66 = stack[-3];
    v65 = elt(env, 6); /* !% */
    if (v66 == v65) goto v75;
    v65 = qvalue(elt(env, 4)); /* nil */
    goto v76;

v76:
    if (v65 == nil) goto v77;
    stack[-1] = qvalue(elt(env, 20)); /* !*lower */
    qvalue(elt(env, 20)) = nil; /* !*lower */
    v65 = qvalue(elt(env, 21)); /* !*raise */
    stack[0] = v65;
    v65 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 21)) = v65; /* !*raise */
    goto v78;

v78:
    fn = elt(env, 24); /* readch1 */
    v66 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-4];
    v65 = qvalue(elt(env, 2)); /* !$eol!$ */
    if (!(v66 == v65)) goto v78;
    v65 = stack[0];
    qvalue(elt(env, 21)) = v65; /* !*raise */
    qvalue(elt(env, 20)) = stack[-1]; /* !*lower */
    fn = elt(env, 24); /* readch1 */
    v65 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-3] = v65;
    goto v67;

v77:
    v66 = stack[-3];
    v65 = elt(env, 8); /* !! */
    if (v66 == v65) goto v80;
    v65 = qvalue(elt(env, 4)); /* nil */
    goto v81;

v81:
    if (!(v65 == nil)) goto v82;
    v66 = stack[-3];
    v65 = elt(env, 11); /* !" */
    if (v66 == v65) goto v83;
    v65 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 12)) = v65; /* ttype!* */
    v66 = stack[-3];
    v65 = qvalue(elt(env, 13)); /* !$eof!$ */
    if (!(v66 == v65)) goto v84;
    v65 = elt(env, 14); /* !  */
    qvalue(elt(env, 1)) = v65; /* crchar!* */
    fn = elt(env, 27); /* filenderr */
    v65 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    goto v84;

v84:
    v65 = stack[-3];
    qvalue(elt(env, 15)) = v65; /* nxtsym!* */
    v66 = stack[-3];
    v65 = elt(env, 16); /* delchar */
    v65 = Lflagp(nil, v66, v65);
    env = stack[-4];
    if (v65 == nil) goto v85;
    v65 = elt(env, 14); /* !  */
    qvalue(elt(env, 1)) = v65; /* crchar!* */
    goto v86;

v86:
    v66 = stack[-3];
    v65 = elt(env, 17); /* !- */
    if (v66 == v65) goto v87;
    v65 = qvalue(elt(env, 4)); /* nil */
    goto v88;

v88:
    if (v65 == nil) goto v89;
    v65 = qvalue(elt(env, 1)); /* crchar!* */
    fn = elt(env, 25); /* token!-number */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-3] = v65;
    v65 = stack[-3];
    if (is_number(v65)) goto v90;
    v65 = stack[-3];
    stack[0] = qcdr(v65);
    v66 = elt(env, 19); /* minus */
    v65 = stack[-3];
    v65 = qcdr(v65);
    v65 = qcar(v65);
    v65 = Lapply1(nil, v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v65 = Lrplaca(nil, stack[0], v65);
    nil = C_nil;
    if (exception_pending()) goto v71;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v90:
    v66 = elt(env, 19); /* minus */
    v65 = stack[-3];
        popv(5);
        return Lapply1(nil, v66, v65);

v89:
    v65 = qvalue(elt(env, 15)); /* nxtsym!* */
    { popv(5); return onevalue(v65); }

v87:
    v65 = qvalue(elt(env, 1)); /* crchar!* */
    v65 = Ldigitp(nil, v65);
    env = stack[-4];
    if (v65 == nil) goto v91;
    v65 = qvalue(elt(env, 18)); /* !*minusliter */
    goto v88;

v91:
    v65 = qvalue(elt(env, 4)); /* nil */
    goto v88;

v85:
    fn = elt(env, 24); /* readch1 */
    v65 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    qvalue(elt(env, 1)) = v65; /* crchar!* */
    goto v86;

v83:
    stack[0] = qvalue(elt(env, 20)); /* !*lower */
    qvalue(elt(env, 20)) = nil; /* !*lower */
    v65 = qvalue(elt(env, 21)); /* !*raise */
    stack[-1] = v65;
    v65 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 21)) = v65; /* !*raise */
    goto v92;

v92:
    v66 = stack[-3];
    v65 = stack[-2];
    v65 = cons(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[-2] = v65;
    fn = elt(env, 24); /* readch1 */
    v66 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[-3] = v66;
    v65 = qvalue(elt(env, 13)); /* !$eof!$ */
    if (v66 == v65) goto v94;
    v66 = stack[-3];
    v65 = elt(env, 11); /* !" */
    if (!(v66 == v65)) goto v92;

v95:
    v66 = stack[-3];
    v65 = stack[-2];
    v65 = cons(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[-2] = v65;
    fn = elt(env, 24); /* readch1 */
    v65 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[-3] = v65;
    v66 = stack[-3];
    v65 = elt(env, 11); /* !" */
    if (v66 == v65) goto v92;
    v65 = stack[-2];
    v65 = Lnreverse(nil, v65);
    env = stack[-4];
    v65 = Lcompress(nil, v65);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    qvalue(elt(env, 15)) = v65; /* nxtsym!* */
    v65 = stack[-1];
    qvalue(elt(env, 21)) = v65; /* !*raise */
    qvalue(elt(env, 20)) = stack[0]; /* !*lower */
    v65 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 12)) = v65; /* ttype!* */
    v65 = stack[-3];
    qvalue(elt(env, 1)) = v65; /* crchar!* */
    goto v89;

v94:
    v65 = stack[-1];
    qvalue(elt(env, 21)) = v65; /* !*raise */
    v65 = elt(env, 14); /* !  */
    qvalue(elt(env, 1)) = v65; /* crchar!* */
    v66 = elt(env, 23); /* "***** End-of-file in string" */
    v65 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 28); /* lpriw */
    v65 = (*qfn2(fn))(qenv(fn), v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    fn = elt(env, 27); /* filenderr */
    v65 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    goto v95;

v82:
    stack[0] = qvalue(elt(env, 20)); /* !*lower */
    qvalue(elt(env, 20)) = nil; /* !*lower */
    v65 = qvalue(elt(env, 21)); /* !*raise */
    stack[-1] = v65;
    v65 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 21)) = v65; /* !*raise */
    v66 = stack[-3];
    v65 = stack[-2];
    v65 = cons(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    stack[-2] = v65;
    fn = elt(env, 24); /* readch1 */
    v65 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    stack[-3] = v65;
    v65 = stack[-1];
    qvalue(elt(env, 21)) = v65; /* !*raise */
    qvalue(elt(env, 20)) = stack[0]; /* !*lower */
    goto v73;

v73:
    v65 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v65; /* ttype!* */
    goto v97;

v97:
    v66 = stack[-3];
    v65 = stack[-2];
    v65 = cons(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-2] = v65;
    fn = elt(env, 24); /* readch1 */
    v65 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-3] = v65;
    v65 = Ldigitp(nil, v65);
    env = stack[-4];
    if (!(v65 == nil)) goto v97;
    v65 = stack[-3];
    v65 = Lalpha_char_p(nil, v65);
    env = stack[-4];
    if (!(v65 == nil)) goto v97;
    v66 = stack[-3];
    v65 = elt(env, 8); /* !! */
    if (v66 == v65) goto v82;
    v66 = stack[-3];
    v65 = elt(env, 17); /* !- */
    if (v66 == v65) goto v98;
    v65 = qvalue(elt(env, 4)); /* nil */
    goto v99;

v99:
    if (v65 == nil) goto v100;
    v66 = elt(env, 8); /* !! */
    v65 = stack[-2];
    v65 = cons(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-2] = v65;
    goto v97;

v100:
    v66 = stack[-3];
    v65 = elt(env, 22); /* !_ */
    if (v66 == v65) goto v97;
    v65 = stack[-2];
    v65 = Lnreverse(nil, v65);
    env = stack[-4];
    v65 = Lcompress(nil, v65);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v65 = Lintern(nil, v65);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    qvalue(elt(env, 15)) = v65; /* nxtsym!* */
    v65 = stack[-3];
    qvalue(elt(env, 1)) = v65; /* crchar!* */
    goto v89;

v98:
    v65 = qvalue(elt(env, 18)); /* !*minusliter */
    goto v99;

v80:
    v65 = qvalue(elt(env, 9)); /* !*micro!-version */
    if (v65 == nil) goto v101;
    v65 = qvalue(elt(env, 10)); /* !*defn */
    v65 = (v65 == nil ? lisp_true : nil);
    goto v102;

v102:
    v65 = (v65 == nil ? lisp_true : nil);
    goto v81;

v101:
    v65 = qvalue(elt(env, 4)); /* nil */
    goto v102;

v75:
    v65 = qvalue(elt(env, 7)); /* !*savecomments!* */
    v65 = (v65 == nil ? lisp_true : nil);
    goto v76;

v69:
    v65 = qvalue(elt(env, 3)); /* !*eoldelimp */
    goto v70;
/* error exit handlers */
v96:
    env = stack[-4];
    qvalue(elt(env, 20)) = stack[0]; /* !*lower */
    popv(5);
    return nil;
v93:
    env = stack[-4];
    qvalue(elt(env, 20)) = stack[0]; /* !*lower */
    popv(5);
    return nil;
v79:
    env = stack[-4];
    qvalue(elt(env, 20)) = stack[-1]; /* !*lower */
    popv(5);
    return nil;
v71:
    popv(5);
    return nil;
}



/* Code for dp_diff */

static Lisp_Object CC_dp_diff(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_diff");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v104 = v4;
    v105 = v103;
/* end of prologue */
    stack[0] = v105;
    fn = elt(env, 1); /* dp_neg */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    {
        Lisp_Object v68 = stack[0];
        popv(2);
        fn = elt(env, 2); /* dp_sum */
        return (*qfn2(fn))(qenv(fn), v68, v104);
    }
/* error exit handlers */
v106:
    popv(2);
    return nil;
}



/* Code for dquot */

static Lisp_Object CC_dquot(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v114, v115;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dquot");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v103;
/* end of prologue */
    stack[-2] = nil;
    goto v83;

v83:
    v113 = stack[-1];
    v114 = qcar(v113);
    v113 = stack[0];
    v113 = qcar(v113);
    v113 = difference2(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    v115 = v113;
    v114 = v115;
    v113 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v114)) < ((int32_t)(v113))) goto v62;
    v114 = v115;
    v113 = stack[-2];
    v113 = cons(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    stack[-2] = v113;
    v113 = stack[0];
    v113 = qcdr(v113);
    stack[0] = v113;
    v113 = stack[-1];
    v113 = qcdr(v113);
    stack[-1] = v113;
    v113 = stack[0];
    if (!(v113 == nil)) goto v83;
    v113 = stack[-2];
        popv(4);
        return Lnreverse(nil, v113);

v62:
    v113 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v113); }
/* error exit handlers */
v61:
    popv(4);
    return nil;
}



/* Code for pv_sort1 */

static Lisp_Object CC_pv_sort1(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort1");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v103;
/* end of prologue */

v82:
    v118 = stack[-1];
    if (v118 == nil) goto v89;
    v118 = stack[-1];
    v118 = qcar(v118);
    v60 = qcdr(v118);
    v118 = stack[0];
    v118 = qcar(v118);
    v118 = qcdr(v118);
    v118 = (Lisp_Object)lessp2(v60, v118);
    nil = C_nil;
    if (exception_pending()) goto v119;
    v118 = v118 ? lisp_true : nil;
    env = stack[-3];
    if (v118 == nil) goto v120;
    v118 = stack[-1];
    v118 = qcdr(v118);
    stack[-2] = v118;
    v118 = stack[-1];
    v60 = qcar(v118);
    v118 = stack[0];
    v118 = cons(v60, v118);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    stack[0] = v118;
    v118 = stack[-2];
    stack[-1] = v118;
    goto v82;

v120:
    v118 = stack[-1];
    v118 = qcdr(v118);
    stack[-2] = v118;
    v118 = stack[-1];
    v60 = qcar(v118);
    v118 = stack[0];
    fn = elt(env, 1); /* pv_sort2 */
    v118 = (*qfn2(fn))(qenv(fn), v60, v118);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    stack[0] = v118;
    v118 = stack[-2];
    stack[-1] = v118;
    goto v82;

v89:
    v118 = stack[0];
        popv(4);
        return Lnreverse(nil, v118);
/* error exit handlers */
v119:
    popv(4);
    return nil;
}



/* Code for general!-modular!-reciprocal */

static Lisp_Object CC_generalKmodularKreciprocal(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v60, v61, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-reciprocal");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v103;
/* end of prologue */
    v118 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v118 == nil) goto v126;
    v60 = stack[0];
    v118 = (Lisp_Object)1; /* 0 */
    v118 = (Lisp_Object)lessp2(v60, v118);
    nil = C_nil;
    if (exception_pending()) goto v127;
    v118 = v118 ? lisp_true : nil;
    env = stack[-2];
    if (v118 == nil) goto v126;
    stack[-1] = qvalue(elt(env, 2)); /* current!-modulus */
    v60 = stack[0];
    v118 = qvalue(elt(env, 2)); /* current!-modulus */
    v61 = plus2(v60, v118);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v60 = (Lisp_Object)1; /* 0 */
    v118 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v128 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v128, v61, v60, v118);
    }

v126:
    v125 = qvalue(elt(env, 2)); /* current!-modulus */
    v61 = stack[0];
    v60 = (Lisp_Object)1; /* 0 */
    v118 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v125, v61, v60, v118);
    }
/* error exit handlers */
v127:
    popv(3);
    return nil;
}



/* Code for anform1 */

static Lisp_Object CC_anform1(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for anform1");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v103;
/* end of prologue */
    v140 = stack[-1];
    v140 = qcar(v140);
    stack[-2] = v140;
    v140 = stack[-1];
    v140 = qcdr(v140);
    stack[-1] = v140;
    v140 = stack[-2];
    if (!consp(v140)) goto v142;
    v140 = stack[-2];
    v140 = CC_anform1(env, v140);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    v140 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v140);
    }

v142:
    v140 = stack[-2];
    if (symbolp(v140)) goto v110;
    v140 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v140); }

v110:
    v141 = stack[-2];
    v140 = elt(env, 2); /* dclglb */
    v140 = Lflagp(nil, v141, v140);
    env = stack[-3];
    if (v140 == nil) goto v76;
    v141 = stack[-2];
    v140 = elt(env, 3); /* glb2rf */
    v140 = Lflagp(nil, v141, v140);
    env = stack[-3];
    if (!(v140 == nil)) goto v122;
    v140 = stack[-2];
    v141 = ncons(v140);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    v140 = elt(env, 3); /* glb2rf */
    v140 = Lflag(nil, v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    v141 = stack[-2];
    v140 = qvalue(elt(env, 4)); /* globs!* */
    v140 = cons(v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    qvalue(elt(env, 4)) = v140; /* globs!* */
    goto v122;

v122:
    v140 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v140);
    }

v76:
    v141 = stack[-2];
    v140 = qvalue(elt(env, 5)); /* locls!* */
    v140 = Lassoc(nil, v141, v140);
    if (v140 == nil) goto v143;
    v140 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v140);
    }

v143:
    v140 = stack[-2];
    fn = elt(env, 9); /* add2calls */
    v140 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    stack[0] = stack[-2];
    v140 = stack[-1];
    v140 = Llength(nil, v140);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    fn = elt(env, 10); /* checkargcount */
    v140 = (*qfn2(fn))(qenv(fn), stack[0], v140);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-3];
    v141 = stack[-2];
    v140 = elt(env, 6); /* noanl */
    v140 = Lflagp(nil, v141, v140);
    env = stack[-3];
    if (!(v140 == nil)) goto v144;
    v141 = stack[-2];
    v140 = elt(env, 7); /* anlfn */
    v140 = get(v141, v140);
    env = stack[-3];
    v141 = v140;
    if (v140 == nil) goto v145;
    v140 = stack[-1];
    v140 = Lapply1(nil, v141, v140);
    nil = C_nil;
    if (exception_pending()) goto v48;
    goto v144;

v144:
    v140 = nil;
    { popv(4); return onevalue(v140); }

v145:
    v140 = stack[-1];
    fn = elt(env, 8); /* anforml */
    v140 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v48;
    goto v144;
/* error exit handlers */
v48:
    popv(4);
    return nil;
}



/* Code for lto_catsoc */

static Lisp_Object CC_lto_catsoc(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v143;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_catsoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v147 = v4;
    v143 = v103;
/* end of prologue */
    v147 = Latsoc(nil, v143, v147);
    v143 = v147;
    v147 = v143;
    if (v147 == nil) goto v106;
    v147 = v143;
    v147 = qcdr(v147);
    return onevalue(v147);

v106:
    v147 = nil;
    return onevalue(v147);
}



/* Code for gcdf1 */

static Lisp_Object CC_gcdf1(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-2] = v103;
/* end of prologue */
    v168 = stack[-2];
    if (v168 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v168 = stack[-1];
    if (v168 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v169 = stack[-2];
    v168 = (Lisp_Object)17; /* 1 */
    if (v169 == v168) goto v143;
    v169 = stack[-1];
    v168 = (Lisp_Object)17; /* 1 */
    v168 = (v169 == v168 ? lisp_true : nil);
    goto v147;

v147:
    if (v168 == nil) goto v170;
    v168 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v168); }

v170:
    v168 = stack[-2];
    if (!consp(v168)) goto v137;
    v168 = stack[-2];
    v168 = qcar(v168);
    v168 = (consp(v168) ? nil : lisp_true);
    goto v171;

v171:
    if (v168 == nil) goto v172;
    v169 = qvalue(elt(env, 2)); /* dmode!* */
    v168 = elt(env, 3); /* field */
    v168 = Lflagp(nil, v169, v168);
    env = stack[-4];
    if (v168 == nil) goto v173;
    v168 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v168); }

v173:
    v169 = stack[-2];
    v168 = stack[-1];
    {
        popv(5);
        fn = elt(env, 10); /* gcdfd1 */
        return (*qfn2(fn))(qenv(fn), v169, v168);
    }

v172:
    v168 = stack[-1];
    if (!consp(v168)) goto v174;
    v168 = stack[-1];
    v168 = qcar(v168);
    v168 = (consp(v168) ? nil : lisp_true);
    goto v175;

v175:
    if (v168 == nil) goto v176;
    v169 = qvalue(elt(env, 2)); /* dmode!* */
    v168 = elt(env, 3); /* field */
    v168 = Lflagp(nil, v169, v168);
    env = stack[-4];
    if (v168 == nil) goto v177;
    v168 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v168); }

v177:
    v169 = stack[-1];
    v168 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); /* gcdfd1 */
        return (*qfn2(fn))(qenv(fn), v169, v168);
    }

v176:
    v168 = qvalue(elt(env, 4)); /* !*anygcd */
    if (v168 == nil) goto v49;
    v168 = stack[-2];
    fn = elt(env, 11); /* num!-exponents */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    if (v168 == nil) goto v141;
    v168 = stack[-1];
    fn = elt(env, 11); /* num!-exponents */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v168 = (v168 == nil ? lisp_true : nil);
    goto v179;

v179:
    if (!(v168 == nil)) goto v180;
    v169 = stack[-2];
    v168 = stack[-1];
    fn = elt(env, 12); /* quotf1 */
    v168 = (*qfn2(fn))(qenv(fn), v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    if (!(v168 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v169 = stack[-1];
    v168 = stack[-2];
    fn = elt(env, 12); /* quotf1 */
    v168 = (*qfn2(fn))(qenv(fn), v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    if (!(v168 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v180:
    v169 = stack[-2];
    v168 = stack[-1];
    fn = elt(env, 13); /* gcdf2 */
    v168 = (*qfn2(fn))(qenv(fn), v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    stack[-3] = v168;
    v168 = qvalue(elt(env, 5)); /* !*gcd */
    if (v168 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v169 = qvalue(elt(env, 2)); /* dmode!* */
    v168 = elt(env, 6); /* (!:rd!: !:cr!:) */
    v168 = Lmemq(nil, v169, v168);
    if (v168 == nil) goto v181;
    v168 = qvalue(elt(env, 7)); /* nil */
    goto v182;

v182:
    if (v168 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v168 = qvalue(elt(env, 8)); /* !*ncmp */
    if (v168 == nil) goto v38;
    v168 = stack[-2];
    fn = elt(env, 14); /* noncomfp1 */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    if (!(v168 == nil)) goto v183;

v38:
    v168 = qvalue(elt(env, 8)); /* !*ncmp */
    if (v168 == nil) goto v184;
    v168 = stack[-1];
    fn = elt(env, 14); /* noncomfp1 */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    if (!(v168 == nil)) goto v183;

v184:
    stack[0] = elt(env, 9); /* "gcdf failed" */
    v168 = stack[-2];
    fn = elt(env, 15); /* prepf */
    stack[-2] = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v168 = stack[-1];
    fn = elt(env, 15); /* prepf */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v168 = list3(stack[0], stack[-2], v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    fn = elt(env, 16); /* errach */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v183:
    v168 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v168); }

v181:
    v169 = stack[-2];
    v168 = stack[-3];
    fn = elt(env, 12); /* quotf1 */
    v168 = (*qfn2(fn))(qenv(fn), v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    if (v168 == nil) goto v185;
    v169 = stack[-1];
    v168 = stack[-3];
    fn = elt(env, 12); /* quotf1 */
    v168 = (*qfn2(fn))(qenv(fn), v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v168 = (v168 == nil ? lisp_true : nil);
    goto v182;

v185:
    v168 = qvalue(elt(env, 1)); /* t */
    goto v182;

v141:
    v168 = qvalue(elt(env, 1)); /* t */
    goto v179;

v49:
    v168 = qvalue(elt(env, 1)); /* t */
    goto v179;

v174:
    v168 = qvalue(elt(env, 1)); /* t */
    goto v175;

v137:
    v168 = qvalue(elt(env, 1)); /* t */
    goto v171;

v143:
    v168 = qvalue(elt(env, 1)); /* t */
    goto v147;
/* error exit handlers */
v178:
    popv(5);
    return nil;
}



/* Code for resimp1 */

static Lisp_Object CC_resimp1(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimp1");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v103;
/* end of prologue */
    v64 = stack[0];
    v186 = qcar(v64);
    v64 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v186, v64);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v64 = stack[0];
    v186 = qcdr(v64);
    v64 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    v64 = (*qfn2(fn))(qenv(fn), v186, v64);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    fn = elt(env, 5); /* invsq */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    fn = elt(env, 6); /* multsq */
    v64 = (*qfn2(fn))(qenv(fn), stack[-1], v64);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    stack[0] = v64;
    v64 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 3)) = v64; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v124:
    popv(3);
    return nil;
}



/* Code for rl_susibin */

static Lisp_Object CC_rl_susibin(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_susibin");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v112 = v4;
    v147 = v103;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susibin!* */
    v112 = list2(v147, v112);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    {
        Lisp_Object v70 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v70, v112);
    }
/* error exit handlers */
v62:
    popv(2);
    return nil;
}



/* Code for ibalp_varlat */

static Lisp_Object CC_ibalp_varlat(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlat");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v103;
/* end of prologue */
    v187 = stack[0];
    fn = elt(env, 1); /* ibalp_arg2l */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    stack[-1] = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    v187 = stack[0];
    fn = elt(env, 3); /* ibalp_arg2r */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    {
        Lisp_Object v112 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* union */
        return (*qfn2(fn))(qenv(fn), v112, v187);
    }
/* error exit handlers */
v170:
    popv(3);
    return nil;
}



/* Code for powers2 */

static Lisp_Object MS_CDECL CC_powers2(Lisp_Object env, int nargs,
                         Lisp_Object v103, Lisp_Object v4,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v76, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powers2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers2");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v103,v4,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v4;
    stack[-2] = v103;
/* end of prologue */

v73:
    v55 = stack[-2];
    if (!consp(v55)) goto v187;
    v55 = stack[-2];
    v55 = qcar(v55);
    v55 = (consp(v55) ? nil : lisp_true);
    goto v105;

v105:
    if (v55 == nil) goto v188;
    v55 = stack[-2];
    if (v55 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v76 = stack[0];
    v55 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* powers4 */
        return (*qfn2(fn))(qenv(fn), v76, v55);
    }

v188:
    v55 = stack[-2];
    v55 = qcar(v55);
    v55 = qcdr(v55);
    stack[-3] = v55;
    v55 = stack[-2];
    v75 = qcdr(v55);
    v76 = stack[-1];
    v55 = stack[0];
    v55 = CC_powers2(env, 3, v75, v76, v55);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    stack[-1] = v55;
    v55 = stack[-2];
    v55 = qcar(v55);
    v76 = qcar(v55);
    v55 = stack[0];
    v55 = cons(v76, v55);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    stack[0] = v55;
    v55 = stack[-3];
    stack[-2] = v55;
    goto v73;

v187:
    v55 = qvalue(elt(env, 1)); /* t */
    goto v105;
/* error exit handlers */
v135:
    popv(5);
    return nil;
}



/* Code for rl_sacat */

static Lisp_Object MS_CDECL CC_rl_sacat(Lisp_Object env, int nargs,
                         Lisp_Object v103, Lisp_Object v4,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v69, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rl_sacat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_sacat");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v103,v4,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v70 = v7;
    v69 = v4;
    v116 = v103;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_sacat!* */
    v70 = list3(v116, v69, v70);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-1];
    {
        Lisp_Object v117 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v117, v70);
    }
/* error exit handlers */
v189:
    popv(2);
    return nil;
}



/* Code for retattributes */

static Lisp_Object CC_retattributes(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retattributes");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v103;
/* end of prologue */

v191:
    v59 = stack[0];
    if (v59 == nil) goto v73;
    v166 = stack[-1];
    v59 = stack[0];
    v59 = qcar(v59);
    fn = elt(env, 2); /* find */
    v59 = (*qfn2(fn))(qenv(fn), v166, v59);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    v166 = v59;
    if (v166 == nil) goto v60;
    v166 = stack[0];
    v166 = qcar(v166);
    stack[-2] = list2(v166, v59);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    v166 = stack[-1];
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = CC_retattributes(env, v166, v59);
    nil = C_nil;
    if (exception_pending()) goto v75;
    {
        Lisp_Object v173 = stack[-2];
        popv(4);
        return cons(v173, v59);
    }

v60:
    v166 = stack[-1];
    v59 = stack[0];
    v59 = qcdr(v59);
    stack[-1] = v166;
    stack[0] = v59;
    goto v191;

v73:
    v59 = nil;
    { popv(4); return onevalue(v59); }
/* error exit handlers */
v75:
    popv(4);
    return nil;
}



/* Code for mintype */

static Lisp_Object CC_mintype(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v105;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mintype");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v104 = v103;
/* end of prologue */
    v105 = v104;
    if (!consp(v105)) return onevalue(v104);
    v104 = qcar(v104);
    return onevalue(v104);
}



/* Code for ident */

static Lisp_Object CC_ident(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object v108;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ident");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v108 = v103;
/* end of prologue */
    return onevalue(v108);
}



/* Code for bcsum */

static Lisp_Object CC_bcsum(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v167, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcsum");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v103;
/* end of prologue */
    v172 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v172 == nil) goto v69;
    v167 = stack[-1];
    v172 = stack[0];
    v172 = plus2(v167, v172);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v172);
    }

v69:
    v171 = stack[-1];
    v167 = stack[0];
    v172 = elt(env, 2); /* plus2 */
    fn = elt(env, 4); /* bcint2op */
    v172 = (*qfnn(fn))(qenv(fn), 3, v171, v167, v172);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-2];
    if (!(v172 == nil)) { popv(3); return onevalue(v172); }
    v167 = stack[-1];
    v172 = stack[0];
    fn = elt(env, 5); /* addsq */
    v172 = (*qfn2(fn))(qenv(fn), v167, v172);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v172);
    }
/* error exit handlers */
v192:
    popv(3);
    return nil;
}



/* Code for evtdeg */

static Lisp_Object CC_evtdeg(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v189, v117;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evtdeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v189 = v103;
/* end of prologue */
    v193 = (Lisp_Object)1; /* 0 */
    goto v82;

v82:
    v117 = v189;
    if (v117 == nil) return onevalue(v193);
    v117 = v189;
    v117 = qcar(v117);
    v193 = (Lisp_Object)(int32_t)((int32_t)v117 + (int32_t)v193 - TAG_FIXNUM);
    v189 = qcdr(v189);
    goto v82;
}



/* Code for worderp */

static Lisp_Object CC_worderp(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v153, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for worderp");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v103;
/* end of prologue */

v67:
    v204 = stack[-1];
    if (!consp(v204)) goto v205;
    v204 = stack[-1];
    v153 = qcar(v204);
    v204 = elt(env, 1); /* indexvar */
    v204 = Lflagp(nil, v153, v204);
    env = stack[-2];
    if (v204 == nil) goto v137;
    v204 = stack[0];
    if (!consp(v204)) goto v172;
    v204 = stack[0];
    v153 = qcar(v204);
    v204 = elt(env, 1); /* indexvar */
    v204 = Lflagp(nil, v153, v204);
    env = stack[-2];
    goto v142;

v142:
    if (v204 == nil) goto v89;
    v153 = stack[-1];
    v204 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* indexvarordp */
        return (*qfn2(fn))(qenv(fn), v153, v204);
    }

v89:
    v204 = stack[-1];
    if (!consp(v204)) goto v58;
    v153 = stack[-1];
    v204 = qvalue(elt(env, 4)); /* kord!* */
    v204 = Lmemq(nil, v153, v204);
    goto v136;

v136:
    if (v204 == nil) goto v127;
    v204 = stack[0];
    if (!consp(v204)) goto v206;
    v153 = stack[0];
    v204 = qvalue(elt(env, 4)); /* kord!* */
    v204 = Lmemq(nil, v153, v204);
    goto v207;

v207:
    if (v204 == nil) goto v208;
    v153 = stack[-1];
    v204 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* ordop */
        return (*qfn2(fn))(qenv(fn), v153, v204);
    }

v208:
    v204 = stack[0];
    fn = elt(env, 7); /* peel */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v154 = v204;
    v153 = stack[-1];
    v204 = v154;
    if (v153 == v204) goto v162;
    v204 = stack[-1];
    v153 = v154;
    stack[-1] = v204;
    stack[0] = v153;
    goto v67;

v162:
    v204 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v204); }

v206:
    v204 = qvalue(elt(env, 3)); /* t */
    goto v207;

v127:
    v204 = stack[0];
    if (!consp(v204)) goto v210;
    v153 = stack[0];
    v204 = qvalue(elt(env, 4)); /* kord!* */
    v204 = Lmemq(nil, v153, v204);
    goto v211;

v211:
    if (v204 == nil) goto v212;
    v204 = stack[-1];
    fn = elt(env, 7); /* peel */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v154 = v204;
    v153 = v154;
    v204 = stack[0];
    if (v153 == v204) goto v156;
    v153 = v154;
    v204 = stack[0];
    stack[-1] = v153;
    stack[0] = v204;
    goto v67;

v156:
    v204 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v204); }

v212:
    v204 = stack[-1];
    fn = elt(env, 7); /* peel */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    stack[-1] = v204;
    v204 = stack[0];
    fn = elt(env, 7); /* peel */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    stack[0] = v204;
    goto v67;

v210:
    v204 = qvalue(elt(env, 3)); /* t */
    goto v211;

v58:
    v204 = qvalue(elt(env, 3)); /* t */
    goto v136;

v172:
    v204 = qvalue(elt(env, 2)); /* nil */
    goto v142;

v137:
    v204 = qvalue(elt(env, 2)); /* nil */
    goto v142;

v205:
    v204 = qvalue(elt(env, 2)); /* nil */
    goto v142;
/* error exit handlers */
v209:
    popv(3);
    return nil;
}



/* Code for algid */

static Lisp_Object CC_algid(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v64, v186;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for algid");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v63 = v4;
    v186 = v103;
/* end of prologue */
    v64 = v186;
    v63 = Latsoc(nil, v64, v63);
    if (!(v63 == nil)) return onevalue(v186);
    v64 = v186;
    v63 = elt(env, 1); /* share */
    v63 = Lflagp(nil, v64, v63);
    if (!(v63 == nil)) return onevalue(v186);
    v63 = v186;
        return Lmkquote(nil, v63);
}



/* Code for layout!-formula */

static Lisp_Object MS_CDECL CC_layoutKformula(Lisp_Object env, int nargs,
                         Lisp_Object v103, Lisp_Object v4,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "layout-formula");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for layout-formula");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v103,v4,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v7;
    stack[-7] = v4;
    stack[-8] = v103;
/* end of prologue */
    stack[-9] = qvalue(elt(env, 1)); /* ycoord!* */
    qvalue(elt(env, 1)) = nil; /* ycoord!* */
    stack[-5] = qvalue(elt(env, 2)); /* ymin!* */
    qvalue(elt(env, 2)) = nil; /* ymin!* */
    stack[-4] = qvalue(elt(env, 3)); /* ymax!* */
    qvalue(elt(env, 3)) = nil; /* ymax!* */
    stack[-3] = qvalue(elt(env, 4)); /* posn!* */
    qvalue(elt(env, 4)) = nil; /* posn!* */
    stack[-2] = qvalue(elt(env, 5)); /* pline!* */
    qvalue(elt(env, 5)) = nil; /* pline!* */
    stack[-1] = qvalue(elt(env, 6)); /* testing!-width!* */
    qvalue(elt(env, 6)) = nil; /* testing!-width!* */
    stack[0] = qvalue(elt(env, 7)); /* overflowed!* */
    qvalue(elt(env, 7)) = nil; /* overflowed!* */
    v216 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 7)) = v216; /* overflowed!* */
    qvalue(elt(env, 5)) = v216; /* pline!* */
    v216 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v216; /* ymax!* */
    qvalue(elt(env, 2)) = v216; /* ymin!* */
    qvalue(elt(env, 1)) = v216; /* ycoord!* */
    v216 = qvalue(elt(env, 9)); /* orig!* */
    qvalue(elt(env, 4)) = v216; /* posn!* */
    v216 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 6)) = v216; /* testing!-width!* */
    v216 = stack[-6];
    if (v216 == nil) goto v120;
    v53 = stack[-6];
    v216 = elt(env, 11); /* inbrackets */
    if (v53 == v216) goto v116;
    v216 = stack[-6];
    fn = elt(env, 14); /* oprin */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-10];
    goto v120;

v120:
    v53 = stack[-8];
    v216 = stack[-7];
    fn = elt(env, 15); /* maprint */
    v216 = (*qfn2(fn))(qenv(fn), v53, v216);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-10];
    v53 = stack[-6];
    v216 = elt(env, 11); /* inbrackets */
    if (!(v53 == v216)) goto v205;
    v216 = elt(env, 13); /* ")" */
    fn = elt(env, 16); /* prin2!* */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-10];
    goto v205;

v205:
    v216 = qvalue(elt(env, 7)); /* overflowed!* */
    if (v216 == nil) goto v75;
    v216 = qvalue(elt(env, 8)); /* nil */
    goto v104;

v104:
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    { popv(11); return onevalue(v216); }

v75:
    stack[-7] = qvalue(elt(env, 5)); /* pline!* */
    v53 = qvalue(elt(env, 4)); /* posn!* */
    v216 = qvalue(elt(env, 9)); /* orig!* */
    stack[-6] = difference2(v53, v216);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-10];
    v53 = qvalue(elt(env, 2)); /* ymin!* */
    v216 = qvalue(elt(env, 3)); /* ymax!* */
    v216 = cons(v53, v216);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-10];
    v216 = acons(stack[-7], stack[-6], v216);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-10];
    goto v104;

v116:
    v216 = elt(env, 12); /* "(" */
    fn = elt(env, 16); /* prin2!* */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-10];
    goto v120;
/* error exit handlers */
v208:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    popv(11);
    return nil;
}



/* Code for !*collectphysops */

static Lisp_Object CC_Hcollectphysops(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *collectphysops");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v142 = v103;
/* end of prologue */
    v104 = v142;
    v142 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* !*collectphysops_reversed */
    v142 = (*qfn2(fn))(qenv(fn), v104, v142);
    errexit();
        return Lnreverse(nil, v142);
}



/* Code for contrsp2 */

static Lisp_Object MS_CDECL CC_contrsp2(Lisp_Object env, int nargs,
                         Lisp_Object v103, Lisp_Object v4,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v136;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contrsp2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contrsp2");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v103,v4,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v4;
    stack[-2] = v103;
/* end of prologue */
    stack[-3] = (Lisp_Object)33; /* 2 */
    v128 = stack[-2];
    v128 = Llength(nil, v128);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    if (stack[-3] == v128) goto v143;
    v128 = nil;
    { popv(5); return onevalue(v128); }

v143:
    v136 = stack[0];
    v128 = stack[-2];
    v128 = qcar(v128);
    if (equal(v136, v128)) goto v111;
    v136 = stack[0];
    v128 = stack[-2];
    v128 = qcdr(v128);
    v128 = qcar(v128);
    if (equal(v136, v128)) goto v113;
    v128 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v128); }

v113:
    v128 = stack[-2];
    v136 = qcar(v128);
    v128 = stack[-1];
    popv(5);
    return cons(v136, v128);

v111:
    v128 = stack[-2];
    v128 = qcdr(v128);
    v136 = qcar(v128);
    v128 = stack[-1];
    popv(5);
    return cons(v136, v128);
/* error exit handlers */
v55:
    popv(5);
    return nil;
}



/* Code for form1 */

static Lisp_Object MS_CDECL CC_form1(Lisp_Object env, int nargs,
                         Lisp_Object v103, Lisp_Object v4,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v316, v317, v318, v319;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "form1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for form1");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v103,v4,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    stack[-2] = v4;
    stack[-3] = v103;
/* end of prologue */

v191:
    v316 = stack[-3];
    if (!consp(v316)) goto v83;
    v316 = stack[-3];
    v316 = qcar(v316);
    if (!consp(v316)) goto v55;
    v318 = stack[-3];
    v317 = stack[-2];
    v316 = stack[-1];
    {
        popv(6);
        fn = elt(env, 33); /* form2 */
        return (*qfnn(fn))(qenv(fn), 3, v318, v317, v316);
    }

v55:
    v316 = stack[-3];
    v316 = qcar(v316);
    if (symbolp(v316)) goto v52;
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 4); /* "operator" */
    fn = elt(env, 34); /* typerr */
    v316 = (*qfn2(fn))(qenv(fn), v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    goto v321;

v321:
    v317 = stack[-1];
    v316 = elt(env, 9); /* symbolic */
    if (v317 == v316) goto v322;
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 24); /* opfn */
    v316 = Lflagp(nil, v317, v316);
    env = stack[-5];
    goto v323;

v323:
    if (v316 == nil) goto v324;
    v316 = stack[-3];
    fn = elt(env, 35); /* argnochk */
    v316 = (*qfn1(fn))(qenv(fn), v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    goto v324;

v324:
    v316 = stack[-3];
    v318 = qcdr(v316);
    v317 = stack[-2];
    v316 = stack[-1];
    fn = elt(env, 36); /* formlis */
    v316 = (*qfnn(fn))(qenv(fn), 3, v318, v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    stack[-4] = v316;
    v317 = stack[-4];
    v316 = stack[-3];
    v316 = qcdr(v316);
    if (equal(v317, v316)) goto v325;
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = stack[-4];
    v316 = cons(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    goto v326;

v326:
    stack[0] = v316;
    v317 = stack[-1];
    v316 = elt(env, 9); /* symbolic */
    if (v317 == v316) goto v327;
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 16); /* stat */
    v316 = get(v317, v316);
    env = stack[-5];
    if (!(v316 == nil)) goto v328;
    v316 = stack[-3];
    v316 = qcdr(v316);
    if (v316 == nil) goto v329;
    v316 = stack[-3];
    v316 = qcdr(v316);
    v317 = qcar(v316);
    v316 = elt(env, 25); /* quote */
    if (!consp(v317)) goto v330;
    v317 = qcar(v317);
    if (!(v317 == v316)) goto v330;
    v316 = qvalue(elt(env, 26)); /* !*micro!-version */
    if (v316 == nil) goto v331;
    v316 = qvalue(elt(env, 27)); /* !*defn */
    v316 = (v316 == nil ? lisp_true : nil);
    goto v332;

v332:
    v316 = (v316 == nil ? lisp_true : nil);
    goto v333;

v333:
    if (!(v316 == nil)) goto v328;
    v317 = stack[0];
    v316 = stack[-2];
    fn = elt(env, 37); /* intexprnp */
    v316 = (*qfn2(fn))(qenv(fn), v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    if (v316 == nil) goto v334;
    v316 = qvalue(elt(env, 28)); /* !*composites */
    if (v316 == nil) goto v335;
    v316 = qvalue(elt(env, 10)); /* nil */
    goto v328;

v328:
    if (v316 == nil) goto v336;
    v317 = stack[0];
    v316 = stack[-1];
    {
        popv(6);
        fn = elt(env, 38); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v317, v316);
    }

v336:
    v317 = stack[-1];
    v316 = elt(env, 30); /* algebraic */
    if (v317 == v316) goto v337;
    v318 = stack[0];
    v317 = stack[-2];
    v316 = elt(env, 30); /* algebraic */
    v319 = CC_form1(env, 3, v318, v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    v318 = stack[-2];
    v317 = stack[-1];
    v316 = elt(env, 30); /* algebraic */
    {
        popv(6);
        fn = elt(env, 39); /* convertmode1 */
        return (*qfnn(fn))(qenv(fn), 4, v319, v318, v317, v316);
    }

v337:
    stack[0] = elt(env, 31); /* list */
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = stack[-2];
    v316 = Latsoc(nil, v317, v316);
    if (!(v316 == nil)) goto v338;
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 32); /* share */
    v316 = Lflagp(nil, v317, v316);
    env = stack[-5];
    if (!(v316 == nil)) goto v338;
    v316 = stack[-3];
    v316 = qcar(v316);
    v316 = Lmkquote(nil, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    v317 = v316;
    goto v339;

v339:
    v316 = stack[-4];
    {
        Lisp_Object v340 = stack[0];
        popv(6);
        return list2star(v340, v317, v316);
    }

v338:
    v316 = stack[-3];
    v316 = qcar(v316);
    v317 = v316;
    goto v339;

v335:
    v317 = qvalue(elt(env, 29)); /* current!-modulus */
    v316 = (Lisp_Object)17; /* 1 */
    v316 = (v317 == v316 ? lisp_true : nil);
    goto v328;

v334:
    v316 = qvalue(elt(env, 10)); /* nil */
    goto v328;

v331:
    v316 = qvalue(elt(env, 10)); /* nil */
    goto v332;

v330:
    v316 = qvalue(elt(env, 10)); /* nil */
    goto v333;

v329:
    v316 = qvalue(elt(env, 10)); /* nil */
    goto v333;

v327:
    v316 = qvalue(elt(env, 13)); /* t */
    goto v328;

v325:
    v316 = stack[-3];
    goto v326;

v322:
    v316 = qvalue(elt(env, 13)); /* t */
    goto v323;

v52:
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 5); /* comment */
    if (v317 == v316) goto v208;
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 6); /* noform */
    v316 = Lflagp(nil, v317, v316);
    env = stack[-5];
    if (!(v316 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 7); /* rtype */
    v317 = get(v317, v316);
    env = stack[-5];
    v316 = elt(env, 8); /* array */
    if (v317 == v316) goto v45;
    v316 = qvalue(elt(env, 10)); /* nil */
    goto v341;

v341:
    if (v316 == nil) goto v47;
    stack[0] = elt(env, 11); /* getel */
    v318 = stack[-3];
    v317 = stack[-2];
    v316 = stack[-1];
    fn = elt(env, 40); /* intargfn */
    v316 = (*qfnn(fn))(qenv(fn), 3, v318, v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    {
        Lisp_Object v342 = stack[0];
        popv(6);
        return list2(v342, v316);
    }

v47:
    v316 = stack[-3];
    v316 = qcdr(v316);
    if (v316 == nil) goto v343;
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 7); /* rtype */
    v317 = get(v317, v316);
    env = stack[-5];
    v316 = elt(env, 12); /* vector */
    if (v317 == v316) goto v185;
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v316 = Lsimple_vectorp(nil, v316);
    env = stack[-5];
    if (!(v316 == nil)) goto v209;
    v316 = stack[-3];
    v316 = qcdr(v316);
    v317 = qcar(v316);
    v316 = elt(env, 14); /* vecfn */
    v316 = Lflagpcar(nil, v317, v316);
    env = stack[-5];
    goto v209;

v209:
    if (v316 == nil) goto v343;
    v318 = stack[-3];
    v317 = stack[-2];
    v316 = stack[-1];
    {
        popv(6);
        fn = elt(env, 41); /* getvect */
        return (*qfnn(fn))(qenv(fn), 3, v318, v317, v316);
    }

v343:
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 2); /* modefn */
    v316 = Lflagp(nil, v317, v316);
    env = stack[-5];
    if (v316 == nil) goto v344;
    v316 = stack[-3];
    v316 = qcdr(v316);
    v318 = qcar(v316);
    v317 = stack[-2];
    v316 = stack[-3];
    v316 = qcar(v316);
    v319 = CC_form1(env, 3, v318, v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    v318 = stack[-2];
    v317 = stack[-1];
    v316 = stack[-3];
    v316 = qcar(v316);
    {
        popv(6);
        fn = elt(env, 39); /* convertmode1 */
        return (*qfnn(fn))(qenv(fn), 4, v319, v318, v317, v316);
    }

v344:
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 15); /* formfn */
    v316 = get(v317, v316);
    env = stack[-5];
    stack[-4] = v316;
    if (v316 == nil) goto v345;
    v319 = stack[-4];
    v318 = stack[-3];
    v317 = stack[-2];
    v316 = stack[-1];
    v317 = Lapply3(nil, 4, v319, v318, v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    v316 = stack[-1];
    {
        popv(6);
        fn = elt(env, 38); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v317, v316);
    }

v345:
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 16); /* stat */
    v317 = get(v317, v316);
    env = stack[-5];
    v316 = elt(env, 17); /* rlis */
    if (v317 == v316) goto v346;
    v316 = stack[-3];
    v317 = qcar(v316);
    v316 = elt(env, 18); /* !*comma!* */
    if (!(v317 == v316)) goto v321;
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcar(v316);
    if (!consp(v316)) goto v347;
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcar(v316);
    if (!consp(v316)) goto v348;
    v316 = qvalue(elt(env, 10)); /* nil */
    goto v349;

v349:
    if (v316 == nil) goto v350;
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v317 = qcar(v316);
    v316 = elt(env, 20); /* "invalid except at head of block" */
    v316 = list2(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    v317 = v316;
    v316 = v317;
    qvalue(elt(env, 21)) = v316; /* errmsg!* */
    v316 = qvalue(elt(env, 22)); /* !*protfg */
    if (!(v316 == nil)) goto v96;
    v316 = v317;
    fn = elt(env, 42); /* lprie */
    v316 = (*qfn1(fn))(qenv(fn), v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    goto v96;

v96:
    v316 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    goto v321;

v350:
    v317 = elt(env, 23); /* "Syntax error: , invalid after" */
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v316 = list2(v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    v317 = v316;
    v316 = v317;
    qvalue(elt(env, 21)) = v316; /* errmsg!* */
    v316 = qvalue(elt(env, 22)); /* !*protfg */
    if (!(v316 == nil)) goto v351;
    v316 = v317;
    fn = elt(env, 42); /* lprie */
    v316 = (*qfn1(fn))(qenv(fn), v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    goto v351;

v351:
    v316 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    goto v321;

v348:
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v317 = qcar(v316);
    v316 = elt(env, 19); /* type */
    v316 = Lflagp(nil, v317, v316);
    env = stack[-5];
    goto v349;

v347:
    v316 = qvalue(elt(env, 10)); /* nil */
    goto v349;

v346:
    v318 = stack[-3];
    v317 = stack[-2];
    v316 = stack[-1];
    fn = elt(env, 43); /* formrlis */
    v317 = (*qfnn(fn))(qenv(fn), 3, v318, v317, v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    v316 = stack[-1];
    {
        popv(6);
        fn = elt(env, 38); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v317, v316);
    }

v185:
    v316 = qvalue(elt(env, 13)); /* t */
    goto v209;

v45:
    v317 = stack[-1];
    v316 = elt(env, 9); /* symbolic */
    v316 = (v317 == v316 ? lisp_true : nil);
    goto v341;

v208:
    v316 = stack[-3];
    fn = elt(env, 44); /* lastpair */
    v316 = (*qfn1(fn))(qenv(fn), v316);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-5];
    v318 = qcar(v316);
    v317 = stack[-2];
    v316 = stack[-1];
    stack[-3] = v318;
    stack[-2] = v317;
    stack[-1] = v316;
    goto v191;

v83:
    v316 = stack[-3];
    if (!(symbolp(v316))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v317 = stack[-3];
    v316 = elt(env, 1); /* ed */
    if (v317 == v316) goto v147;
    v317 = stack[-3];
    v316 = elt(env, 2); /* modefn */
    v316 = Lflagp(nil, v317, v316);
    env = stack[-5];
    if (v316 == nil) goto v137;
    v316 = stack[-3];
    {
        popv(6);
        fn = elt(env, 45); /* set!-global!-mode */
        return (*qfn1(fn))(qenv(fn), v316);
    }

v137:
    v317 = stack[-1];
    v316 = elt(env, 3); /* idfn */
    v316 = get(v317, v316);
    stack[-4] = v316;
    if (v316 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v318 = stack[-4];
    v317 = stack[-3];
    v316 = stack[-2];
        popv(6);
        return Lapply2(nil, 3, v318, v317, v316);

v147:
    v316 = stack[-3];
    popv(6);
    return ncons(v316);
/* error exit handlers */
v320:
    popv(6);
    return nil;
}



/* Code for simpdiff */

static Lisp_Object CC_simpdiff(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdiff");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v103;
/* end of prologue */
    v68 = stack[0];
    fn = elt(env, 1); /* ckpreci!# */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    v68 = stack[0];
    v68 = qcar(v68);
    fn = elt(env, 2); /* simp */
    stack[-1] = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    v68 = stack[0];
    v68 = qcdr(v68);
    fn = elt(env, 3); /* simpminus */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    {
        Lisp_Object v143 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v143, v68);
    }
/* error exit handlers */
v147:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-minusp */

static Lisp_Object CC_mvKpowKminusp(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v189;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-minusp");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v103;
/* end of prologue */

v191:
    v193 = stack[0];
    if (v193 == nil) goto v109;
    v193 = stack[0];
    v189 = qcar(v193);
    v193 = (Lisp_Object)1; /* 0 */
    v193 = (Lisp_Object)lessp2(v189, v193);
    nil = C_nil;
    if (exception_pending()) goto v110;
    v193 = v193 ? lisp_true : nil;
    env = stack[-1];
    if (!(v193 == nil)) { popv(2); return onevalue(v193); }
    v193 = stack[0];
    v193 = qcdr(v193);
    stack[0] = v193;
    goto v191;

v109:
    v193 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v193); }
/* error exit handlers */
v110:
    popv(2);
    return nil;
}



/* Code for dp_term */

static Lisp_Object CC_dp_term(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v104;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_term");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v142 = v4;
    v104 = v103;
/* end of prologue */
    return cons(v142, v104);
}



/* Code for pcmult */

static Lisp_Object CC_pcmult(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pcmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v4;
    v165 = v103;
/* end of prologue */
    stack[-5] = v165;
    v165 = stack[-5];
    if (v165 == nil) goto v104;
    v165 = stack[-5];
    v165 = qcar(v165);
    v56 = v165;
    stack[0] = qcar(v56);
    v56 = stack[-4];
    v165 = qcdr(v165);
    fn = elt(env, 2); /* cprod */
    v165 = (*qfn2(fn))(qenv(fn), v56, v165);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v165 = cons(stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    stack[-2] = v165;
    stack[-3] = v165;
    goto v146;

v146:
    v165 = stack[-5];
    v165 = qcdr(v165);
    stack[-5] = v165;
    v165 = stack[-5];
    if (v165 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v165 = stack[-5];
    v165 = qcar(v165);
    v56 = v165;
    stack[0] = qcar(v56);
    v56 = stack[-4];
    v165 = qcdr(v165);
    fn = elt(env, 2); /* cprod */
    v165 = (*qfn2(fn))(qenv(fn), v56, v165);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v165 = cons(stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v165 = Lrplacd(nil, stack[-1], v165);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v165 = stack[-2];
    v165 = qcdr(v165);
    stack[-2] = v165;
    goto v146;

v104:
    v165 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v165); }
/* error exit handlers */
v206:
    popv(7);
    return nil;
}



/* Code for pv_applp */

static Lisp_Object CC_pv_applp(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_applp");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v4;
    v56 = v103;
/* end of prologue */
    stack[-5] = v56;
    v56 = stack[-5];
    if (v56 == nil) goto v105;
    v56 = stack[-5];
    v56 = qcar(v56);
    v57 = v56;
    v56 = v57;
    stack[0] = qcar(v56);
    v56 = v57;
    v57 = qcdr(v56);
    v56 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v56 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-6];
    v56 = cons(stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-6];
    v56 = ncons(v56);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-6];
    stack[-2] = v56;
    stack[-3] = v56;
    goto v89;

v89:
    v56 = stack[-5];
    v56 = qcdr(v56);
    stack[-5] = v56;
    v56 = stack[-5];
    if (v56 == nil) goto v172;
    stack[-1] = stack[-2];
    v56 = stack[-5];
    v56 = qcar(v56);
    v57 = v56;
    v56 = v57;
    stack[0] = qcar(v56);
    v56 = v57;
    v57 = qcdr(v56);
    v56 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v56 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-6];
    v56 = cons(stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-6];
    v56 = ncons(v56);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-6];
    v56 = Lrplacd(nil, stack[-1], v56);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-6];
    v56 = stack[-2];
    v56 = qcdr(v56);
    stack[-2] = v56;
    goto v89;

v172:
    v56 = stack[-3];
    goto v146;

v146:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v56);
    }

v105:
    v56 = qvalue(elt(env, 1)); /* nil */
    goto v146;
/* error exit handlers */
v215:
    popv(7);
    return nil;
}



/* Code for !*id2num */

static Lisp_Object CC_Hid2num(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v143;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *id2num");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v147 = v103;
/* end of prologue */
    v143 = qvalue(elt(env, 1)); /* pair_id_num!* */
    v147 = Lassoc(nil, v147, v143);
    v143 = v147;
    if (v147 == nil) goto v82;
    v147 = v143;
    v147 = qcdr(v147);
    return onevalue(v147);

v82:
    v147 = nil;
    return onevalue(v147);
}



/* Code for aronep!: */

static Lisp_Object CC_aronepT(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v104;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aronep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v142 = v103;
/* end of prologue */
    v104 = qcdr(v142);
    v142 = (Lisp_Object)17; /* 1 */
    v142 = (v104 == v142 ? lisp_true : nil);
    return onevalue(v142);
}



/* Code for exptmod!: */

static Lisp_Object CC_exptmodT(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptmod:");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v105 = v4;
    v187 = v103;
/* end of prologue */
    v187 = qcdr(v187);
    fn = elt(env, 1); /* general!-modular!-expt */
    v105 = (*qfn2(fn))(qenv(fn), v187, v105);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v105);
    }
/* error exit handlers */
v106:
    popv(1);
    return nil;
}



/* Code for minus!-mod!-p */

static Lisp_Object CC_minusKmodKp(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minus-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v103;
/* end of prologue */
    stack[-2] = nil;
    goto v67;

v67:
    v60 = stack[-1];
    if (v60 == nil) goto v146;
    v60 = stack[-1];
    if (!consp(v60)) goto v170;
    v60 = stack[-1];
    v60 = qcar(v60);
    v60 = (consp(v60) ? nil : lisp_true);
    goto v68;

v68:
    if (v60 == nil) goto v72;
    v61 = stack[-2];
    v60 = stack[-1];
    {   int32_t w = int_of_fixnum(v60);
        if (w != 0) w = current_modulus - w;
        v60 = fixnum_of_int(w);
    }
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v61, v60);
    }

v72:
    v60 = stack[-1];
    v60 = qcar(v60);
    stack[0] = qcar(v60);
    v60 = stack[-1];
    v60 = qcar(v60);
    v60 = qcdr(v60);
    v61 = CC_minusKmodKp(env, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    v60 = stack[-2];
    v60 = acons(stack[0], v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    stack[-2] = v60;
    v60 = stack[-1];
    v60 = qcdr(v60);
    stack[-1] = v60;
    goto v67;

v170:
    v60 = qvalue(elt(env, 1)); /* t */
    goto v68;

v146:
    v60 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v60);
    }
/* error exit handlers */
v127:
    popv(4);
    return nil;
}



/* Code for sfto_gcdf */

static Lisp_Object CC_sfto_gcdf(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_gcdf");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v103;
/* end of prologue */
    v61 = qvalue(elt(env, 1)); /* !*rldavgcd */
    if (v61 == nil) goto v89;
    v125 = stack[-1];
    v61 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* sfto_davp */
    v61 = (*qfn2(fn))(qenv(fn), v125, v61);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    if (!(v61 == nil)) goto v68;
    v125 = stack[0];
    v61 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* sfto_davp */
    v61 = (*qfn2(fn))(qenv(fn), v125, v61);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    if (!(v61 == nil)) goto v68;
    v125 = stack[-1];
    v61 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ezgcdf */
        return (*qfn2(fn))(qenv(fn), v125, v61);
    }

v68:
    v61 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* !*ezgcd */
    qvalue(elt(env, 3)) = v61; /* !*ezgcd */
    v125 = stack[-1];
    v61 = stack[0];
    fn = elt(env, 6); /* gcdf */
    v61 = (*qfn2(fn))(qenv(fn), v125, v61);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* !*ezgcd */
    { popv(4); return onevalue(v61); }

v89:
    v125 = stack[-1];
    v61 = stack[0];
    {
        popv(4);
        fn = elt(env, 6); /* gcdf */
        return (*qfn2(fn))(qenv(fn), v125, v61);
    }
/* error exit handlers */
v136:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* !*ezgcd */
    popv(4);
    return nil;
v128:
    popv(4);
    return nil;
}



/* Code for prepsq!*2 */

static Lisp_Object CC_prepsqH2(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v106, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*2");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v187 = v103;
/* end of prologue */
    v68 = v187;
    v106 = (Lisp_Object)17; /* 1 */
    v187 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepsq!*1 */
    v187 = (*qfnn(fn))(qenv(fn), 3, v68, v106, v187);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* replus */
        return (*qfn1(fn))(qenv(fn), v187);
    }
/* error exit handlers */
v170:
    popv(1);
    return nil;
}



/* Code for raddf */

static Lisp_Object CC_raddf(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v356, v306;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for raddf");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-2] = v103;
/* end of prologue */
    stack[-3] = nil;
    goto v82;

v82:
    v356 = stack[-2];
    if (v356 == nil) goto v105;
    v356 = stack[-1];
    if (v356 == nil) goto v116;
    v356 = stack[-2];
    if (!consp(v356)) goto v124;
    v356 = stack[-2];
    v356 = qcar(v356);
    v356 = (consp(v356) ? nil : lisp_true);
    goto v123;

v123:
    if (v356 == nil) goto v186;
    stack[0] = stack[-3];
    v306 = stack[-2];
    v356 = stack[-1];
    fn = elt(env, 2); /* addd */
    v356 = (*qfn2(fn))(qenv(fn), v306, v356);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-4];
    {
        Lisp_Object v91 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v91, v356);
    }

v186:
    v356 = stack[-1];
    if (!consp(v356)) goto v58;
    v356 = stack[-1];
    v356 = qcar(v356);
    v356 = (consp(v356) ? nil : lisp_true);
    goto v136;

v136:
    if (v356 == nil) goto v77;
    stack[0] = stack[-3];
    v306 = stack[-1];
    v356 = stack[-2];
    fn = elt(env, 2); /* addd */
    v356 = (*qfn2(fn))(qenv(fn), v306, v356);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-4];
    {
        Lisp_Object v182 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v182, v356);
    }

v77:
    v356 = stack[-2];
    v356 = qcar(v356);
    v306 = qcar(v356);
    v356 = stack[-1];
    v356 = qcar(v356);
    v356 = qcar(v356);
    if (equal(v306, v356)) goto v163;
    v356 = stack[-2];
    v356 = qcar(v356);
    v306 = qcar(v356);
    v356 = stack[-1];
    v356 = qcar(v356);
    v356 = qcar(v356);
    fn = elt(env, 4); /* ordpp */
    v356 = (*qfn2(fn))(qenv(fn), v306, v356);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-4];
    if (v356 == nil) goto v157;
    v356 = stack[-2];
    v306 = qcar(v356);
    v356 = stack[-3];
    v356 = cons(v306, v356);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-4];
    stack[-3] = v356;
    v356 = stack[-2];
    v356 = qcdr(v356);
    stack[-2] = v356;
    goto v82;

v157:
    v356 = stack[-1];
    v306 = qcar(v356);
    v356 = stack[-3];
    v356 = cons(v306, v356);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-4];
    stack[-3] = v356;
    v356 = stack[-1];
    v356 = qcdr(v356);
    stack[-1] = v356;
    goto v82;

v163:
    v356 = stack[-2];
    v356 = qcar(v356);
    stack[0] = qcar(v356);
    v356 = stack[-2];
    v356 = qcar(v356);
    v306 = qcdr(v356);
    v356 = stack[-1];
    v356 = qcar(v356);
    v356 = qcdr(v356);
    v306 = CC_raddf(env, v306, v356);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-4];
    v356 = stack[-3];
    v356 = acons(stack[0], v306, v356);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-4];
    stack[-3] = v356;
    v356 = stack[-2];
    v356 = qcdr(v356);
    stack[-2] = v356;
    v356 = stack[-1];
    v356 = qcdr(v356);
    stack[-1] = v356;
    goto v82;

v58:
    v356 = qvalue(elt(env, 1)); /* t */
    goto v136;

v124:
    v356 = qvalue(elt(env, 1)); /* t */
    goto v123;

v116:
    v306 = stack[-3];
    v356 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v306, v356);
    }

v105:
    v306 = stack[-3];
    v356 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v306, v356);
    }
/* error exit handlers */
v357:
    popv(5);
    return nil;
}



/* Code for stable!-sortip */

static Lisp_Object CC_stableKsortip(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v364, v299, v300;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stable-sortip");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v4;
    stack[-3] = v103;
/* end of prologue */
    v364 = stack[-3];
    if (v364 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v364 = stack[-3];
    stack[-4] = v364;
    v364 = stack[-3];
    v364 = qcdr(v364);
    stack[-1] = v364;
    v364 = stack[-1];
    if (v364 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v364 = stack[-1];
    v364 = qcdr(v364);
    stack[-3] = v364;
    v364 = stack[-3];
    if (v364 == nil) goto v124;
    v364 = stack[-4];
    stack[-3] = v364;
    goto v173;

v173:
    v364 = stack[-1];
    if (v364 == nil) goto v75;
    v300 = stack[-2];
    v364 = stack[-1];
    v299 = qcar(v364);
    v364 = stack[-3];
    v364 = qcar(v364);
    v364 = Lapply2(nil, 3, v300, v299, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    if (!(v364 == nil)) goto v75;
    v364 = stack[-1];
    stack[-3] = v364;
    v364 = stack[-1];
    v364 = qcdr(v364);
    stack[-1] = v364;
    goto v173;

v75:
    v364 = stack[-1];
    if (v364 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v364 = stack[-4];
    stack[-1] = v364;
    v364 = stack[-1];
    v364 = qcdr(v364);
    v364 = qcdr(v364);
    stack[-3] = v364;
    goto v366;

v366:
    v364 = stack[-3];
    if (v364 == nil) goto v177;
    v364 = stack[-3];
    v364 = qcdr(v364);
    if (v364 == nil) goto v177;
    v364 = stack[-1];
    v364 = qcdr(v364);
    stack[-1] = v364;
    v364 = stack[-3];
    v364 = qcdr(v364);
    v364 = qcdr(v364);
    stack[-3] = v364;
    goto v366;

v177:
    v364 = stack[-1];
    stack[-3] = v364;
    v364 = stack[-1];
    v364 = qcdr(v364);
    stack[-1] = v364;
    v299 = stack[-3];
    v364 = qvalue(elt(env, 1)); /* nil */
    v364 = Lrplacd(nil, v299, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v299 = stack[-4];
    v364 = stack[-2];
    v364 = CC_stableKsortip(env, v299, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-4] = v364;
    v299 = stack[-1];
    v364 = stack[-2];
    v364 = CC_stableKsortip(env, v299, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[-1] = v364;
    v364 = qvalue(elt(env, 1)); /* nil */
    v364 = ncons(v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    stack[0] = v364;
    stack[-3] = v364;
    goto v367;

v367:
    v364 = stack[-4];
    if (v364 == nil) goto v85;
    v364 = stack[-1];
    if (v364 == nil) goto v85;
    v300 = stack[-2];
    v364 = stack[-1];
    v299 = qcar(v364);
    v364 = stack[-4];
    v364 = qcar(v364);
    v364 = Lapply2(nil, 3, v300, v299, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    if (v364 == nil) goto v151;
    v299 = stack[0];
    v364 = stack[-1];
    v364 = Lrplacd(nil, v299, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v364 = stack[-1];
    stack[0] = v364;
    v364 = stack[-1];
    v364 = qcdr(v364);
    stack[-1] = v364;
    goto v367;

v151:
    v299 = stack[0];
    v364 = stack[-4];
    v364 = Lrplacd(nil, v299, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v364 = stack[-4];
    stack[0] = v364;
    v364 = stack[-4];
    v364 = qcdr(v364);
    stack[-4] = v364;
    goto v367;

v85:
    v364 = stack[-4];
    if (v364 == nil) goto v368;
    v364 = stack[-4];
    stack[-1] = v364;
    goto v368;

v368:
    v299 = stack[0];
    v364 = stack[-1];
    v364 = Lrplacd(nil, v299, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    v364 = stack[-3];
    v364 = qcdr(v364);
    { popv(6); return onevalue(v364); }

v124:
    v300 = stack[-2];
    v364 = stack[-1];
    v299 = qcar(v364);
    v364 = stack[-4];
    v364 = qcar(v364);
    v364 = Lapply2(nil, 3, v300, v299, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    if (v364 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v364 = stack[-4];
    v364 = qcar(v364);
    stack[-3] = v364;
    v299 = stack[-4];
    v364 = stack[-1];
    v364 = qcar(v364);
    v364 = Lrplaca(nil, v299, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    env = stack[-5];
    v299 = stack[-1];
    v364 = stack[-3];
    v364 = Lrplaca(nil, v299, v364);
    nil = C_nil;
    if (exception_pending()) goto v365;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v365:
    popv(6);
    return nil;
}



/* Code for mri_2pasfat */

static Lisp_Object CC_mri_2pasfat(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_2pasfat");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v103;
/* end of prologue */
    v106 = stack[0];
    fn = elt(env, 2); /* mri_op */
    stack[-1] = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    v106 = stack[0];
    fn = elt(env, 3); /* mri_arg2l */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    v68 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v143 = stack[-1];
        popv(3);
        return list3(v143, v106, v68);
    }
/* error exit handlers */
v147:
    popv(3);
    return nil;
}



/* Code for qqe_qtidp */

static Lisp_Object CC_qqe_qtidp(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v112;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qtidp");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v170 = v103;
/* end of prologue */
    v112 = v170;
    v170 = elt(env, 1); /* idtype */
    v170 = get(v112, v170);
    env = stack[0];
    v112 = elt(env, 2); /* qt */
    v170 = (v170 == v112 ? lisp_true : nil);
    { popv(1); return onevalue(v170); }
}



/* Code for difff */

static Lisp_Object CC_difff(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v371, v310, v354;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difff");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-2] = v103;
/* end of prologue */
    v371 = stack[-2];
    if (!consp(v371)) goto v89;
    v371 = stack[-2];
    v371 = qcar(v371);
    if (!consp(v371)) goto v62;
    v371 = stack[-2];
    v371 = qcar(v371);
    v310 = qcar(v371);
    v371 = (Lisp_Object)17; /* 1 */
    v371 = cons(v310, v371);
    nil = C_nil;
    if (exception_pending()) goto v372;
    env = stack[-4];
    v310 = ncons(v371);
    nil = C_nil;
    if (exception_pending()) goto v372;
    env = stack[-4];
    v371 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v310, v371);
    nil = C_nil;
    if (exception_pending()) goto v372;
    env = stack[-4];
    v371 = stack[-2];
    v371 = qcar(v371);
    v310 = qcdr(v371);
    v371 = stack[-1];
    v371 = CC_difff(env, v310, v371);
    nil = C_nil;
    if (exception_pending()) goto v372;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[0], v371);
    nil = C_nil;
    if (exception_pending()) goto v372;
    env = stack[-4];
    v371 = stack[-2];
    v371 = qcar(v371);
    v310 = qcar(v371);
    v371 = stack[-1];
    fn = elt(env, 4); /* diffp */
    stack[0] = (*qfn2(fn))(qenv(fn), v310, v371);
    nil = C_nil;
    if (exception_pending()) goto v372;
    env = stack[-4];
    v371 = stack[-2];
    v371 = qcar(v371);
    v310 = qcdr(v371);
    v371 = (Lisp_Object)17; /* 1 */
    v371 = cons(v310, v371);
    nil = C_nil;
    if (exception_pending()) goto v372;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v371 = (*qfn2(fn))(qenv(fn), stack[0], v371);
    nil = C_nil;
    if (exception_pending()) goto v372;
    env = stack[-4];
    fn = elt(env, 5); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v371);
    nil = C_nil;
    if (exception_pending()) goto v372;
    env = stack[-4];
    v371 = stack[-2];
    v310 = qcdr(v371);
    v371 = stack[-1];
    v371 = CC_difff(env, v310, v371);
    nil = C_nil;
    if (exception_pending()) goto v372;
    env = stack[-4];
    {
        Lisp_Object v197 = stack[0];
        popv(5);
        fn = elt(env, 5); /* addsq */
        return (*qfn2(fn))(qenv(fn), v197, v371);
    }

v62:
    v371 = stack[-2];
    v310 = qcar(v371);
    v371 = elt(env, 2); /* domain!-diff!-fn */
    v371 = get(v310, v371);
    env = stack[-4];
    v310 = v371;
    v371 = v310;
    if (v371 == nil) goto v190;
    v354 = v310;
    v310 = stack[-2];
    v371 = stack[-1];
        popv(5);
        return Lapply2(nil, 3, v354, v310, v371);

v190:
    v310 = qvalue(elt(env, 1)); /* nil */
    v371 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v310, v371);

v89:
    v310 = qvalue(elt(env, 1)); /* nil */
    v371 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v310, v371);
/* error exit handlers */
v372:
    popv(5);
    return nil;
}



/* Code for symtabget */

static Lisp_Object CC_symtabget(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v61, v125, v202;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symtabget");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v202 = v4;
    v125 = v103;
/* end of prologue */
    v60 = v202;
    if (v60 == nil) goto v109;
    v60 = v125;
    if (!(v60 == nil)) goto v89;
    v60 = qvalue(elt(env, 1)); /* !*symboltable!* */
    v60 = qcar(v60);
    goto v89;

v89:
    v125 = v60;
    goto v109;

v109:
    v60 = v125;
    if (v60 == nil) goto v68;
    v61 = v202;
    v60 = elt(env, 2); /* (!*type!* !*params!* !*decs!*) */
    v60 = Lmemq(nil, v61, v60);
    if (v60 == nil) goto v120;
    v60 = v125;
    v61 = v202;
    return get(v60, v61);

v120:
    v61 = v202;
    v60 = elt(env, 3); /* !*decs!* */
    v60 = get(v125, v60);
    v60 = Lassoc(nil, v61, v60);
    return onevalue(v60);

v68:
    v60 = qvalue(elt(env, 1)); /* !*symboltable!* */
    return onevalue(v60);
}



/* Code for termordp */

static Lisp_Object CC_termordp(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termordp");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    v105 = v103;
/* end of prologue */
    fn = elt(env, 1); /* wedgefax */
    stack[-1] = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v105 = stack[0];
    fn = elt(env, 1); /* wedgefax */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    {
        Lisp_Object v170 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* monordp */
        return (*qfn2(fn))(qenv(fn), v170, v105);
    }
/* error exit handlers */
v68:
    popv(3);
    return nil;
}



/* Code for putpline */

static Lisp_Object CC_putpline(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v366, v373;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for putpline");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v103;
/* end of prologue */
    v366 = qvalue(elt(env, 1)); /* posn!* */
    v177 = stack[0];
    v177 = qcar(v177);
    v177 = qcdr(v177);
    stack[-1] = (Lisp_Object)(int32_t)((int32_t)v366 + (int32_t)v177 - TAG_FIXNUM);
    v177 = qvalue(elt(env, 2)); /* nil */
    v366 = Llinelength(nil, v177);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v177 = qvalue(elt(env, 3)); /* spare!* */
    v177 = (Lisp_Object)(int32_t)((int32_t)v366 - (int32_t)v177 + TAG_FIXNUM);
    v177 = (Lisp_Object)greaterp2(stack[-1], v177);
    nil = C_nil;
    if (exception_pending()) goto v131;
    v177 = v177 ? lisp_true : nil;
    env = stack[-2];
    if (v177 == nil) goto v190;
    v177 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    goto v190;

v190:
    v366 = qvalue(elt(env, 1)); /* posn!* */
    v177 = qvalue(elt(env, 5)); /* orig!* */
    v373 = (Lisp_Object)(int32_t)((int32_t)v366 - (int32_t)v177 + TAG_FIXNUM);
    v366 = qvalue(elt(env, 6)); /* ycoord!* */
    v177 = stack[0];
    v177 = qcar(v177);
    v177 = qcar(v177);
    fn = elt(env, 11); /* update!-pline */
    v366 = (*qfnn(fn))(qenv(fn), 3, v373, v366, v177);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v177 = qvalue(elt(env, 7)); /* pline!* */
    v177 = Lappend(nil, v366, v177);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    qvalue(elt(env, 7)) = v177; /* pline!* */
    v366 = qvalue(elt(env, 1)); /* posn!* */
    v177 = stack[0];
    v177 = qcar(v177);
    v177 = qcdr(v177);
    v177 = (Lisp_Object)(int32_t)((int32_t)v366 + (int32_t)v177 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v177; /* posn!* */
    v373 = qvalue(elt(env, 8)); /* ymin!* */
    v177 = stack[0];
    v177 = qcdr(v177);
    v366 = qcar(v177);
    v177 = qvalue(elt(env, 6)); /* ycoord!* */
    v177 = (Lisp_Object)(int32_t)((int32_t)v366 + (int32_t)v177 - TAG_FIXNUM);
    fn = elt(env, 12); /* min */
    v177 = (*qfn2(fn))(qenv(fn), v373, v177);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    qvalue(elt(env, 8)) = v177; /* ymin!* */
    v373 = qvalue(elt(env, 9)); /* ymax!* */
    v177 = stack[0];
    v177 = qcdr(v177);
    v366 = qcdr(v177);
    v177 = qvalue(elt(env, 6)); /* ycoord!* */
    v177 = (Lisp_Object)(int32_t)((int32_t)v366 + (int32_t)v177 - TAG_FIXNUM);
    fn = elt(env, 13); /* max */
    v177 = (*qfn2(fn))(qenv(fn), v373, v177);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    qvalue(elt(env, 9)) = v177; /* ymax!* */
    v177 = nil;
    { popv(3); return onevalue(v177); }
/* error exit handlers */
v131:
    popv(3);
    return nil;
}



/* Code for vecopp */

static Lisp_Object CC_vecopp(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecopp");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v59 = v103;
/* end of prologue */
    v58 = v59;
    if (symbolp(v58)) goto v147;
    v58 = qvalue(elt(env, 1)); /* nil */
    goto v82;

v82:
    if (!(v58 == nil)) { popv(1); return onevalue(v58); }
    v58 = v59;
    if (!consp(v58)) goto v127;
    v58 = v59;
    v166 = qcar(v58);
    v58 = elt(env, 2); /* phystype */
    v166 = get(v166, v58);
    env = stack[0];
    v58 = elt(env, 3); /* vector */
    if (v166 == v58) goto v124;
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v58); }

v124:
    v58 = v59;
    v58 = qcdr(v58);
    v58 = qcar(v58);
    fn = elt(env, 4); /* isanindex */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v374;
    v58 = (v58 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v58); }

v127:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v58); }

v147:
    v166 = v59;
    v58 = elt(env, 2); /* phystype */
    v166 = get(v166, v58);
    env = stack[0];
    v58 = elt(env, 3); /* vector */
    v58 = (v166 == v58 ? lisp_true : nil);
    goto v82;
/* error exit handlers */
v374:
    popv(1);
    return nil;
}



/* Code for symbid */

static Lisp_Object CC_symbid(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v203, v341, v362;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbid");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v341 = v4;
    stack[0] = v103;
/* end of prologue */
    v47 = qvalue(elt(env, 1)); /* fname!* */
    if (v47 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v203 = qvalue(elt(env, 2)); /* ftype!* */
    v47 = elt(env, 3); /* (macro smacro) */
    v47 = Lmemq(nil, v203, v47);
    if (v47 == nil) goto v193;
    v47 = qvalue(elt(env, 9)); /* nil */
    goto v142;

v142:
    if (v47 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v47 = qvalue(elt(env, 10)); /* !*msg */
    if (v47 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 11); /* "***" */
    v362 = elt(env, 12); /* "nonlocal use of undeclared variable" */
    v341 = stack[0];
    v203 = elt(env, 13); /* "in procedure" */
    v47 = qvalue(elt(env, 1)); /* fname!* */
    v47 = list4(v362, v341, v203, v47);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    fn = elt(env, 14); /* lpriw */
    v47 = (*qfn2(fn))(qenv(fn), stack[-1], v47);
    nil = C_nil;
    if (exception_pending()) goto v210;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v193:
    v47 = stack[0];
    v203 = v341;
    v47 = Latsoc(nil, v47, v203);
    if (!(v47 == nil)) goto v69;
    v47 = stack[0];
    v47 = Lsymbol_specialp(nil, v47);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    if (!(v47 == nil)) goto v69;
    v47 = stack[0];
    v47 = Lsymbol_globalp(nil, v47);
    env = stack[-2];
    if (!(v47 == nil)) goto v69;
    v47 = stack[0];
    if (v47 == nil) goto v137;
    v203 = stack[0];
    v47 = qvalue(elt(env, 4)); /* t */
    if (v203 == v47) goto v121;
    v203 = stack[0];
    v47 = elt(env, 5); /* share */
    v47 = Lflagp(nil, v203, v47);
    env = stack[-2];
    if (v47 == nil) goto v176;
    v47 = qvalue(elt(env, 4)); /* t */
    goto v69;

v69:
    v47 = (v47 == nil ? lisp_true : nil);
    goto v142;

v176:
    v47 = qvalue(elt(env, 6)); /* !*comp */
    if (!(v47 == nil)) goto v69;
    v47 = qvalue(elt(env, 7)); /* !*cref */
    if (!(v47 == nil)) goto v69;
    v203 = stack[0];
    v47 = elt(env, 8); /* constant!? */
    v47 = get(v203, v47);
    env = stack[-2];
    goto v69;

v121:
    v47 = qvalue(elt(env, 4)); /* t */
    goto v69;

v137:
    v47 = qvalue(elt(env, 4)); /* t */
    goto v69;
/* error exit handlers */
v210:
    popv(3);
    return nil;
}



/* Code for errorset2 */

static Lisp_Object CC_errorset2(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v112, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for errorset2");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v112 = v103;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*protfg */
    qvalue(elt(env, 1)) = nil; /* !*protfg */
    v170 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v170; /* !*protfg */
    v147 = v112;
    v112 = qvalue(elt(env, 3)); /* nil */
    v170 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 4); /* errorset */
    v170 = (*qfnn(fn))(qenv(fn), 3, v147, v112, v170);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    { popv(2); return onevalue(v170); }
/* error exit handlers */
v62:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    popv(2);
    return nil;
}



/* Code for mv!-pow!-mv!-term!-!+ */

static Lisp_Object CC_mvKpowKmvKtermKL(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-mv-term-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    v143 = v103;
/* end of prologue */
    v62 = v143;
    v143 = stack[0];
    v143 = qcar(v143);
    fn = elt(env, 1); /* mv!-pow!-!+ */
    v62 = (*qfn2(fn))(qenv(fn), v62, v143);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v143 = stack[0];
    v143 = qcdr(v143);
    popv(1);
    return cons(v62, v143);
/* error exit handlers */
v69:
    popv(1);
    return nil;
}



/* Code for insert_pv1 */

static Lisp_Object MS_CDECL CC_insert_pv1(Lisp_Object env, int nargs,
                         Lisp_Object v103, Lisp_Object v4,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "insert_pv1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insert_pv1");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v103,v4,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v4;
    stack[-2] = v103;
/* end of prologue */

v73:
    v53 = stack[-1];
    if (v53 == nil) goto v83;
    v53 = stack[-2];
    if (v53 == nil) goto v64;
    v53 = stack[-1];
    v53 = qcar(v53);
    v53 = qcar(v53);
    v54 = qcdr(v53);
    v53 = stack[-2];
    v53 = qcar(v53);
    v53 = qcdr(v53);
    v53 = (Lisp_Object)greaterp2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v133;
    v53 = v53 ? lisp_true : nil;
    env = stack[-4];
    if (v53 == nil) goto v207;
    v53 = stack[-1];
    v53 = qcdr(v53);
    stack[-3] = v53;
    v53 = stack[-1];
    v54 = qcar(v53);
    v53 = stack[-2];
    fn = elt(env, 2); /* reduce_pv */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    fn = elt(env, 3); /* pv_renorm */
    v54 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v53 = stack[0];
    v53 = cons(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    stack[0] = v53;
    v53 = stack[-3];
    stack[-1] = v53;
    goto v73;

v207:
    v53 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v53;
    v54 = stack[-2];
    v53 = stack[0];
    v53 = cons(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    stack[0] = v53;
    v53 = stack[-3];
    stack[-2] = v53;
    goto v73;

v64:
    v53 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v53;
    v53 = stack[-1];
    v53 = qcdr(v53);
    stack[-3] = v53;
    v53 = stack[-1];
    v54 = qcar(v53);
    v53 = stack[0];
    v53 = cons(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    stack[0] = v53;
    v53 = stack[-3];
    stack[-1] = v53;
    goto v73;

v83:
    v53 = stack[-2];
    if (v53 == nil) goto v106;
    v54 = stack[-2];
    v53 = stack[0];
    v53 = cons(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v133;
        popv(5);
        return Lnreverse(nil, v53);

v106:
    v53 = stack[0];
        popv(5);
        return Lnreverse(nil, v53);
/* error exit handlers */
v133:
    popv(5);
    return nil;
}



/* Code for polynomclone */

static Lisp_Object CC_polynomclone(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomclone");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v64 = v103;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v64;
    goto v89;

v89:
    v64 = stack[0];
    if (v64 == nil) goto v146;
    v64 = stack[0];
    v64 = qcar(v64);
    fn = elt(env, 2); /* monomclone */
    v186 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v64 = stack[-1];
    v64 = cons(v186, v64);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    stack[-1] = v64;
    v64 = stack[0];
    v64 = qcdr(v64);
    stack[0] = v64;
    goto v89;

v146:
    v64 = stack[-1];
        popv(3);
        return Lreverse(nil, v64);
/* error exit handlers */
v124:
    popv(3);
    return nil;
}



/* Code for setdiff */

static Lisp_Object CC_setdiff(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    v111 = v103;
/* end of prologue */

v67:
    v63 = stack[0];
    if (v63 == nil) { popv(2); return onevalue(v111); }
    v63 = v111;
    if (v63 == nil) goto v104;
    v63 = stack[0];
    v63 = qcar(v63);
    v111 = Ldelete(nil, v63, v111);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-1];
    v63 = stack[0];
    v63 = qcdr(v63);
    stack[0] = v63;
    goto v67;

v104:
    v111 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v111); }
/* error exit handlers */
v186:
    popv(2);
    return nil;
}



/* Code for pasf_susipost */

static Lisp_Object CC_pasf_susipost(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object v109, v67;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_susipost");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v109 = v4;
    v67 = v103;
/* end of prologue */
    return onevalue(v67);
}



/* Code for ibalp_mk2 */

static Lisp_Object MS_CDECL CC_ibalp_mk2(Lisp_Object env, int nargs,
                         Lisp_Object v103, Lisp_Object v4,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v68, v170;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ibalp_mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v106 = v7;
    v68 = v4;
    v170 = v103;
/* end of prologue */
    return list3(v170, v68, v106);
}



/* Code for omobjs */

static Lisp_Object MS_CDECL CC_omobjs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobjs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omobjs");
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
    v171 = qvalue(elt(env, 1)); /* char */
    v167 = elt(env, 2); /* (!/ o m a) */
    if (equal(v171, v167)) goto v82;
    fn = elt(env, 4); /* omobj */
    v167 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-1];
    stack[0] = v167;
    fn = elt(env, 5); /* lex */
    v167 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-1];
    v167 = CC_omobjs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v138;
    v171 = stack[0];
    if (v171 == nil) goto v193;
    v171 = stack[0];
    popv(2);
    return cons(v171, v167);

v193:
    v171 = stack[0];
        popv(2);
        return Lappend(nil, v171, v167);

v82:
    v167 = nil;
    { popv(2); return onevalue(v167); }
/* error exit handlers */
v138:
    popv(2);
    return nil;
}



/* Code for simp!* */

static Lisp_Object CC_simpH(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v103;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* !*asymp!* */
    qvalue(elt(env, 1)) = nil; /* !*asymp!* */
    v159 = stack[-2];
    v158 = elt(env, 2); /* !*sq */
    if (!consp(v159)) goto v124;
    v159 = qcar(v159);
    if (!(v159 == v158)) goto v124;
    v158 = stack[-2];
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    v158 = qcar(v158);
    if (v158 == nil) goto v116;
    v158 = qvalue(elt(env, 4)); /* !*resimp */
    v158 = (v158 == nil ? lisp_true : nil);
    goto v142;

v142:
    if (v158 == nil) goto v172;
    v158 = stack[-2];
    v158 = qcdr(v158);
    v158 = qcar(v158);
    goto v67;

v67:
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    { popv(5); return onevalue(v158); }

v172:
    v159 = qvalue(elt(env, 5)); /* mul!* */
    v158 = qvalue(elt(env, 6)); /* !*sub2 */
    v158 = cons(v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-1] = v158;
    v158 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 5)) = v158; /* mul!* */
    v158 = stack[-2];
    fn = elt(env, 14); /* simp */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-2] = v158;
    v158 = qvalue(elt(env, 7)); /* !*nospurp */
    if (v158 == nil) goto v121;
    v159 = qvalue(elt(env, 5)); /* mul!* */
    v158 = elt(env, 8); /* (isimpq) */
    fn = elt(env, 15); /* union */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    qvalue(elt(env, 5)) = v158; /* mul!* */
    goto v121;

v121:
    v158 = qvalue(elt(env, 5)); /* mul!* */
    stack[0] = v158;
    goto v76;

v76:
    v158 = stack[0];
    if (v158 == nil) goto v55;
    v158 = stack[0];
    v158 = qcar(v158);
    v159 = v158;
    v158 = stack[-2];
    v158 = Lapply1(nil, v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-2] = v158;
    v158 = stack[0];
    v158 = qcdr(v158);
    stack[0] = v158;
    goto v76;

v55:
    v158 = stack[-1];
    v158 = qcar(v158);
    qvalue(elt(env, 5)) = v158; /* mul!* */
    v158 = stack[-2];
    fn = elt(env, 16); /* subs2 */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-2] = v158;
    v158 = qvalue(elt(env, 9)); /* !*combinelogs */
    if (v158 == nil) goto v373;
    v158 = stack[-2];
    fn = elt(env, 17); /* clogsq!* */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-2] = v158;
    goto v373;

v373:
    v159 = qvalue(elt(env, 10)); /* dmode!* */
    v158 = elt(env, 11); /* !:gi!: */
    if (v159 == v158) goto v177;
    v158 = qvalue(elt(env, 3)); /* nil */
    goto v208;

v208:
    if (v158 == nil) goto v200;
    v158 = stack[-2];
    fn = elt(env, 18); /* girationalize!: */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-2] = v158;
    goto v163;

v163:
    v158 = stack[-1];
    v158 = qcdr(v158);
    qvalue(elt(env, 6)) = v158; /* !*sub2 */
    v158 = qvalue(elt(env, 1)); /* !*asymp!* */
    if (v158 == nil) goto v196;
    v158 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v158 == nil) goto v196;
    v158 = stack[-2];
    fn = elt(env, 19); /* gcdchk */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-2] = v158;
    goto v196;

v196:
    v158 = stack[-2];
    goto v67;

v200:
    v158 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v158 == nil) goto v313;
    v158 = stack[-2];
    fn = elt(env, 20); /* rationalizesq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-2] = v158;
    goto v163;

v313:
    v158 = stack[-2];
    fn = elt(env, 21); /* rationalizei */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-2] = v158;
    goto v163;

v177:
    v158 = qvalue(elt(env, 12)); /* !*norationalgi */
    v158 = (v158 == nil ? lisp_true : nil);
    goto v208;

v116:
    v158 = qvalue(elt(env, 3)); /* nil */
    goto v142;

v124:
    v158 = qvalue(elt(env, 3)); /* nil */
    goto v142;
/* error exit handlers */
v45:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    popv(5);
    return nil;
}



/* Code for gsetsugar */

static Lisp_Object CC_gsetsugar(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gsetsugar");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v186 = v4;
    stack[-1] = v103;
/* end of prologue */
    v64 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v64 == nil) goto v146;
    stack[-2] = stack[-1];
    stack[0] = elt(env, 3); /* sugar */
    v64 = v186;
    if (!(v64 == nil)) goto v143;
    v64 = stack[-1];
    fn = elt(env, 4); /* vdptdeg */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    goto v143;

v143:
    fn = elt(env, 5); /* vdpputprop */
    v64 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v64);
    nil = C_nil;
    if (exception_pending()) goto v122;
    goto v73;

v73:
    if (v64 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else { popv(4); return onevalue(v64); }

v146:
    v64 = qvalue(elt(env, 2)); /* nil */
    goto v73;
/* error exit handlers */
v122:
    popv(4);
    return nil;
}



/* Code for domain!*p */

static Lisp_Object CC_domainHp(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v139;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domain*p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v139 = v103;
/* end of prologue */
    v186 = v139;
    if (v186 == nil) goto v109;
    v186 = v139;
    v186 = (is_number(v186) ? lisp_true : nil);
    if (!(v186 == nil)) return onevalue(v186);
    v186 = v139;
    if (!consp(v186)) goto v111;
    v186 = v139;
    v186 = qcar(v186);
    v139 = qvalue(elt(env, 2)); /* domainlist!* */
    v186 = Lmemq(nil, v186, v139);
    return onevalue(v186);

v111:
    v186 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v186);

v109:
    v186 = qvalue(elt(env, 1)); /* t */
    return onevalue(v186);
}



/* Code for add2resultbuf */

static Lisp_Object CC_add2resultbuf(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v101, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add2resultbuf");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v102 = v4;
    stack[0] = v103;
/* end of prologue */
    v132 = v102;
    v101 = elt(env, 1); /* symbolic */
    if (v132 == v101) goto v142;
    v101 = stack[0];
    if (v101 == nil) goto v111;
    v101 = qvalue(elt(env, 5)); /* nil */
    goto v110;

v110:
    if (v101 == nil) goto v121;
    v101 = qvalue(elt(env, 2)); /* t */
    goto v83;

v83:
    if (v101 == nil) goto v82;
    v102 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v102); }

v82:
    v101 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v101 == nil) goto v134;
    v132 = elt(env, 7); /* ws */
    v101 = stack[0];
    fn = elt(env, 13); /* putobject */
    v102 = (*qfnn(fn))(qenv(fn), 3, v132, v101, v102);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-1];
    goto v202;

v202:
    v102 = qvalue(elt(env, 9)); /* !*int */
    if (v102 == nil) goto v164;
    v102 = qvalue(elt(env, 10)); /* ifl!* */
    if (!(v102 == nil)) goto v164;
    v132 = qvalue(elt(env, 11)); /* statcounter */
    v101 = stack[0];
    v102 = qvalue(elt(env, 12)); /* resultbuflis!* */
    v102 = acons(v132, v101, v102);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-1];
    qvalue(elt(env, 12)) = v102; /* resultbuflis!* */
    goto v164;

v164:
    v102 = nil;
    { popv(2); return onevalue(v102); }

v134:
    v102 = qvalue(elt(env, 5)); /* nil */
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-1];
    qvalue(elt(env, 8)) = v102; /* alglist!* */
    v102 = stack[0];
    qvalue(elt(env, 7)) = v102; /* ws */
    goto v202;

v121:
    v101 = qvalue(elt(env, 6)); /* !*nosave!* */
    goto v83;

v111:
    v101 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v101 == nil) goto v123;
    v132 = v102;
    v101 = elt(env, 4); /* empty_list */
    v101 = (v132 == v101 ? lisp_true : nil);
    v101 = (v101 == nil ? lisp_true : nil);
    goto v110;

v123:
    v101 = qvalue(elt(env, 2)); /* t */
    goto v110;

v142:
    v101 = qvalue(elt(env, 2)); /* t */
    goto v83;
/* error exit handlers */
v163:
    popv(2);
    return nil;
}



/* Code for groeb!=testa */

static Lisp_Object CC_groebMtesta(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testa");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    v117 = v103;
/* end of prologue */
    v110 = v117;
    v117 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* pnth */
    v117 = (*qfn2(fn))(qenv(fn), v110, v117);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    stack[-1] = qcar(v117);
    v110 = stack[0];
    v117 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* pnth */
    v117 = (*qfn2(fn))(qenv(fn), v110, v117);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v117 = qcar(v117);
    {
        Lisp_Object v186 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v186, v117);
    }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for pv_sort2a */

static Lisp_Object CC_pv_sort2a(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v366, v373;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort2a");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v103;
/* end of prologue */

v67:
    v366 = stack[0];
    v366 = qcdr(v366);
    if (v366 == nil) goto v170;
    v366 = stack[-1];
    v373 = qcdr(v366);
    v366 = stack[0];
    v366 = qcar(v366);
    v366 = qcdr(v366);
    v366 = (Lisp_Object)greaterp2(v373, v366);
    nil = C_nil;
    if (exception_pending()) goto v162;
    v366 = v366 ? lisp_true : nil;
    env = stack[-3];
    if (v366 == nil) goto v207;
    v366 = stack[0];
    v366 = qcdr(v366);
    stack[0] = v366;
    goto v67;

v207:
    v366 = stack[0];
    v373 = qcar(v366);
    v366 = stack[0];
    v366 = qcdr(v366);
    v366 = cons(v373, v366);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-3];
    stack[-2] = v366;
    v373 = stack[0];
    v366 = stack[-1];
    v373 = Lrplaca(nil, v373, v366);
    nil = C_nil;
    if (exception_pending()) goto v162;
    v366 = stack[-2];
        popv(4);
        return Lrplacd(nil, v373, v366);

v170:
    v366 = stack[-1];
    v373 = qcdr(v366);
    v366 = stack[0];
    v366 = qcar(v366);
    v366 = qcdr(v366);
    v366 = (Lisp_Object)greaterp2(v373, v366);
    nil = C_nil;
    if (exception_pending()) goto v162;
    v366 = v366 ? lisp_true : nil;
    env = stack[-3];
    if (v366 == nil) goto v188;
    v366 = stack[-1];
    v366 = ncons(v366);
    nil = C_nil;
    if (exception_pending()) goto v162;
    {
        Lisp_Object v375 = stack[0];
        popv(4);
        return Lrplacd(nil, v375, v366);
    }

v188:
    v366 = stack[0];
    v373 = qcar(v366);
    v366 = stack[0];
    v366 = qcdr(v366);
    v366 = cons(v373, v366);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-3];
    stack[-2] = v366;
    v373 = stack[0];
    v366 = stack[-1];
    v373 = Lrplaca(nil, v373, v366);
    nil = C_nil;
    if (exception_pending()) goto v162;
    v366 = stack[-2];
        popv(4);
        return Lrplacd(nil, v373, v366);
/* error exit handlers */
v162:
    popv(4);
    return nil;
}



/* Code for ordn */

static Lisp_Object CC_ordn(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordn");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v103;
/* end of prologue */
    v173 = stack[0];
    if (v173 == nil) goto v109;
    v173 = stack[0];
    v173 = qcdr(v173);
    if (v173 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v173 = stack[0];
    v173 = qcdr(v173);
    v173 = qcdr(v173);
    if (v173 == nil) goto v69;
    v173 = stack[0];
    stack[-1] = qcar(v173);
    v173 = stack[0];
    v173 = qcdr(v173);
    v173 = CC_ordn(env, v173);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    {
        Lisp_Object v165 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* ordad */
        return (*qfn2(fn))(qenv(fn), v165, v173);
    }

v69:
    v173 = stack[0];
    v74 = qcar(v173);
    v173 = stack[0];
    v173 = qcdr(v173);
    v173 = qcar(v173);
    fn = elt(env, 3); /* ordp */
    v173 = (*qfn2(fn))(qenv(fn), v74, v173);
    nil = C_nil;
    if (exception_pending()) goto v135;
    if (v173 == nil) goto v192;
    v173 = stack[0];
    v74 = qcar(v173);
    v173 = stack[0];
    v173 = qcdr(v173);
    v173 = qcar(v173);
    popv(3);
    return list2(v74, v173);

v192:
    v173 = stack[0];
    v173 = qcdr(v173);
    v74 = qcar(v173);
    v173 = stack[0];
    v173 = qcar(v173);
    popv(3);
    return list2(v74, v173);

v109:
    v173 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v173); }
/* error exit handlers */
v135:
    popv(3);
    return nil;
}



/* Code for undefdchk */

static Lisp_Object CC_undefdchk(Lisp_Object env,
                         Lisp_Object v103)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v69, v116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for undefdchk");
#endif
    if (stack >= stacklimit)
    {
        push(v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v69 = v103;
/* end of prologue */
    v116 = v69;
    v70 = elt(env, 1); /* defd */
    v70 = Lflagp(nil, v116, v70);
    env = stack[0];
    if (v70 == nil) goto v170;
    v70 = nil;
    { popv(1); return onevalue(v70); }

v170:
    v70 = qvalue(elt(env, 2)); /* undefns!* */
    v70 = cons(v69, v70);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[0];
    qvalue(elt(env, 2)) = v70; /* undefns!* */
    { popv(1); return onevalue(v70); }
/* error exit handlers */
v193:
    popv(1);
    return nil;
}



/* Code for polynomadd */

static Lisp_Object CC_polynomadd(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v311, v45, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomadd");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v103);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v103,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v45 = v4;
    stack[-2] = v103;
/* end of prologue */
    v311 = stack[-2];
    stack[-3] = v311;
    v311 = v45;
    stack[-1] = v311;
    goto v105;

v105:
    v311 = stack[-3];
    v311 = qcar(v311);
    if (v311 == nil) goto v104;
    v311 = stack[-1];
    v311 = qcar(v311);
    if (v311 == nil) goto v104;
    v311 = stack[-3];
    v45 = qcar(v311);
    v311 = stack[-1];
    v311 = qcar(v311);
    fn = elt(env, 2); /* monomcompare */
    v311 = (*qfn2(fn))(qenv(fn), v45, v311);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v46 = v311;
    v45 = v46;
    v311 = (Lisp_Object)17; /* 1 */
    if (v45 == v311) goto v107;
    v45 = v46;
    v311 = (Lisp_Object)-15; /* -1 */
    if (v45 == v311) goto v166;
    v45 = stack[-3];
    v311 = stack[-3];
    v311 = qcdr(v311);
    v311 = qcar(v311);
    v45 = Lrplaca(nil, v45, v311);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v311 = stack[-3];
    v311 = qcdr(v311);
    v311 = qcdr(v311);
    v311 = Lrplacd(nil, v45, v311);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v311 = stack[-1];
    v311 = qcdr(v311);
    stack[-1] = v311;
    goto v105;

v166:
    stack[0] = stack[-3];
    v311 = stack[-3];
    v45 = qcar(v311);
    v311 = stack[-3];
    v311 = qcdr(v311);
    v311 = cons(v45, v311);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v45 = Lrplacd(nil, stack[0], v311);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v311 = stack[-1];
    v311 = qcar(v311);
    v311 = Lrplaca(nil, v45, v311);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v311 = stack[-3];
    v311 = qcdr(v311);
    stack[-3] = v311;
    v311 = stack[-1];
    v311 = qcdr(v311);
    stack[-1] = v311;
    goto v105;

v107:
    v311 = stack[-3];
    v311 = qcdr(v311);
    stack[-3] = v311;
    goto v105;

v104:
    v311 = stack[-1];
    v311 = qcar(v311);
    if (v311 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v45 = stack[-3];
    v311 = stack[-1];
    v311 = Lrplacd(nil, v45, v311);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    stack[0] = v311;
    v45 = stack[0];
    v311 = stack[0];
    v311 = qcdr(v311);
    v311 = qcar(v311);
    v45 = Lrplaca(nil, v45, v311);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v311 = stack[0];
    v311 = qcdr(v311);
    v311 = qcdr(v311);
    v311 = Lrplacd(nil, v45, v311);
    nil = C_nil;
    if (exception_pending()) goto v157;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
/* error exit handlers */
v157:
    popv(5);
    return nil;
}



/* Code for cl_apply2ats */

static Lisp_Object CC_cl_apply2ats(Lisp_Object env,
                         Lisp_Object v103, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v106, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_apply2ats");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v187 = v4;
    v106 = v103;
/* end of prologue */
    v68 = v106;
    v106 = v187;
    v187 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v68, v106, v187);
    }
}



setup_type const u06_setup[] =
{
    {"token1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_token1},
    {"dp_diff",                 too_few_2,      CC_dp_diff,    wrong_no_2},
    {"dquot",                   too_few_2,      CC_dquot,      wrong_no_2},
    {"pv_sort1",                too_few_2,      CC_pv_sort1,   wrong_no_2},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"anform1",                 CC_anform1,     too_many_1,    wrong_no_1},
    {"lto_catsoc",              too_few_2,      CC_lto_catsoc, wrong_no_2},
    {"gcdf1",                   too_few_2,      CC_gcdf1,      wrong_no_2},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"rl_susibin",              too_few_2,      CC_rl_susibin, wrong_no_2},
    {"ibalp_varlat",            CC_ibalp_varlat,too_many_1,    wrong_no_1},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"rl_sacat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_sacat},
    {"retattributes",           too_few_2,      CC_retattributes,wrong_no_2},
    {"mintype",                 CC_mintype,     too_many_1,    wrong_no_1},
    {"ident",                   CC_ident,       too_many_1,    wrong_no_1},
    {"bcsum",                   too_few_2,      CC_bcsum,      wrong_no_2},
    {"evtdeg",                  CC_evtdeg,      too_many_1,    wrong_no_1},
    {"worderp",                 too_few_2,      CC_worderp,    wrong_no_2},
    {"algid",                   too_few_2,      CC_algid,      wrong_no_2},
    {"layout-formula",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_layoutKformula},
    {"*collectphysops",         CC_Hcollectphysops,too_many_1, wrong_no_1},
    {"contrsp2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_contrsp2},
    {"form1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_form1},
    {"simpdiff",                CC_simpdiff,    too_many_1,    wrong_no_1},
    {"mv-pow-minusp",           CC_mvKpowKminusp,too_many_1,   wrong_no_1},
    {"dp_term",                 too_few_2,      CC_dp_term,    wrong_no_2},
    {"pcmult",                  too_few_2,      CC_pcmult,     wrong_no_2},
    {"pv_applp",                too_few_2,      CC_pv_applp,   wrong_no_2},
    {"*id2num",                 CC_Hid2num,     too_many_1,    wrong_no_1},
    {"aronep:",                 CC_aronepT,     too_many_1,    wrong_no_1},
    {"exptmod:",                too_few_2,      CC_exptmodT,   wrong_no_2},
    {"minus-mod-p",             CC_minusKmodKp, too_many_1,    wrong_no_1},
    {"sfto_gcdf",               too_few_2,      CC_sfto_gcdf,  wrong_no_2},
    {"prepsq*2",                CC_prepsqH2,    too_many_1,    wrong_no_1},
    {"raddf",                   too_few_2,      CC_raddf,      wrong_no_2},
    {"stable-sortip",           too_few_2,      CC_stableKsortip,wrong_no_2},
    {"mri_2pasfat",             CC_mri_2pasfat, too_many_1,    wrong_no_1},
    {"qqe_qtidp",               CC_qqe_qtidp,   too_many_1,    wrong_no_1},
    {"difff",                   too_few_2,      CC_difff,      wrong_no_2},
    {"symtabget",               too_few_2,      CC_symtabget,  wrong_no_2},
    {"termordp",                too_few_2,      CC_termordp,   wrong_no_2},
    {"putpline",                CC_putpline,    too_many_1,    wrong_no_1},
    {"vecopp",                  CC_vecopp,      too_many_1,    wrong_no_1},
    {"symbid",                  too_few_2,      CC_symbid,     wrong_no_2},
    {"errorset2",               CC_errorset2,   too_many_1,    wrong_no_1},
    {"mv-pow-mv-term-+",        too_few_2,      CC_mvKpowKmvKtermKL,wrong_no_2},
    {"insert_pv1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_insert_pv1},
    {"polynomclone",            CC_polynomclone,too_many_1,    wrong_no_1},
    {"setdiff",                 too_few_2,      CC_setdiff,    wrong_no_2},
    {"pasf_susipost",           too_few_2,      CC_pasf_susipost,wrong_no_2},
    {"ibalp_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_mk2},
    {"omobjs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobjs},
    {"simp*",                   CC_simpH,       too_many_1,    wrong_no_1},
    {"gsetsugar",               too_few_2,      CC_gsetsugar,  wrong_no_2},
    {"domain*p",                CC_domainHp,    too_many_1,    wrong_no_1},
    {"add2resultbuf",           too_few_2,      CC_add2resultbuf,wrong_no_2},
    {"groeb=testa",             too_few_2,      CC_groebMtesta,wrong_no_2},
    {"pv_sort2a",               too_few_2,      CC_pv_sort2a,  wrong_no_2},
    {"ordn",                    CC_ordn,        too_many_1,    wrong_no_1},
    {"undefdchk",               CC_undefdchk,   too_many_1,    wrong_no_1},
    {"polynomadd",              too_few_2,      CC_polynomadd, wrong_no_2},
    {"cl_apply2ats",            too_few_2,      CC_cl_apply2ats,wrong_no_2},
    {NULL, (one_args *)"u06", (two_args *)"18587 635472 4644823", 0}
};

/* end of generated code */
