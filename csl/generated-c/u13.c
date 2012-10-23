
/* $destdir\u13.c        Machine generated C code */

/* Signature: 00000000 23-Oct-2012 */

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
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
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
extern intptr_t modulus_is_large;
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
extern Lisp_Object declare_symbol, special_symbol, large_modulus;
extern Lisp_Object used_space, avail_space;
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
#define modulus_is_large      BASE[32]
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
#define large_modulus         BASE[184]
#define used_space            BASE[185]
#define avail_space           BASE[186]
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


/* Code for cird */

static Lisp_Object MS_CDECL CC_cird(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0011, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cird");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cird");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    v0011 = qvalue(elt(env, 2)); /* atts */
    v0010 = elt(env, 3); /* (type) */
    fn = elt(env, 6); /* retattributes */
    v0010 = (*qfn2(fn))(qenv(fn), v0011, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    stack[0] = v0010;
    fn = elt(env, 7); /* lex */
    v0010 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0010 = qvalue(elt(env, 4)); /* char */
    stack[-1] = v0010;
    fn = elt(env, 7); /* lex */
    v0010 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0010 = stack[-1];
    v0010 = Lcompress(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0011 = v0010;
    v0010 = v0011;
    if (!(is_number(v0010))) goto v0014;
    v0010 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 8); /* errorml */
    v0010 = (*qfn2(fn))(qenv(fn), v0011, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    goto v0014;

v0014:
    v0010 = stack[-1];
    fn = elt(env, 9); /* compress!* */
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0011 = v0010;
    v0010 = stack[0];
    if (v0010 == nil) { popv(3); return onevalue(v0011); }
    v0012 = elt(env, 5); /* ci */
    v0010 = stack[0];
    popv(3);
    return list3(v0012, v0010, v0011);
/* error exit handlers */
v0013:
    popv(3);
    return nil;
}



/* Code for floatprop */

static Lisp_Object CC_floatprop(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0019;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for floatprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0018 = v0015;
/* end of prologue */
    v0019 = v0018;
    v0019 = Lfloatp(nil, v0019);
    env = stack[0];
    if (!(v0019 == nil)) { popv(1); return onevalue(v0019); }
    v0019 = elt(env, 1); /* !:rd!: */
        popv(1);
        return Leqcar(nil, v0018, v0019);
}



/* Code for bcplus!? */

static Lisp_Object CC_bcplusW(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0023;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcplus?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0022 = v0015;
/* end of prologue */
    v0022 = qcar(v0022);
    v0023 = v0022;
    v0022 = v0023;
    if (is_number(v0022)) goto v0019;
    v0022 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0022);

v0019:
    v0022 = (Lisp_Object)1; /* 0 */
        return Lgreaterp(nil, v0023, v0022);
}



/* Code for one!-entry!-listp */

static Lisp_Object CC_oneKentryKlistp(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for one-entry-listp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0015;
/* end of prologue */

v0027:
    v0007 = stack[-1];
    if (v0007 == nil) goto v0004;
    v0007 = stack[-1];
    v0026 = qcar(v0007);
    v0007 = stack[0];
    fn = elt(env, 3); /* one!-entryp */
    v0007 = (*qfn2(fn))(qenv(fn), v0026, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    if (v0007 == nil) goto v0017;
    v0007 = stack[-1];
    v0026 = qcdr(v0007);
    v0007 = stack[0];
    stack[-1] = v0026;
    stack[0] = v0007;
    goto v0027;

v0017:
    v0007 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0007); }

v0004:
    v0007 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0007); }
/* error exit handlers */
v0028:
    popv(3);
    return nil;
}



/* Code for eqdummy */

static Lisp_Object CC_eqdummy(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007, v0026;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eqdummy");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0006 = v0003;
    v0026 = v0015;
/* end of prologue */
    v0007 = v0026;
    if (v0007 == nil) goto v0004;
    v0007 = elt(env, 2); /* dummy */
    v0007 = get(v0026, v0007);
    env = stack[0];
    v0026 = qcar(v0007);
    v0007 = v0006;
    v0006 = elt(env, 2); /* dummy */
    v0006 = get(v0007, v0006);
    v0006 = qcar(v0006);
    v0006 = (v0026 == v0006 ? lisp_true : nil);
    { popv(1); return onevalue(v0006); }

v0004:
    v0006 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0006); }
}



/* Code for numlist_ordp */

static Lisp_Object CC_numlist_ordp(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0018, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numlist_ordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0016 = v0003;
    v0018 = v0015;
/* end of prologue */
    v0019 = v0018;
    v0018 = v0016;
    v0016 = elt(env, 1); /* lambda_mcd3pw_2 */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v0019, v0018, v0016);
    }
}



/* Code for lambda_mcd3pw_2 */

static Lisp_Object CC_lambda_mcd3pw_2(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0034;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_mcd3pw_2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0033 = v0003;
    v0034 = v0015;
/* end of prologue */
        return Lleq(nil, v0034, v0033);
}



/* Code for degree!-in!-variable */

static Lisp_Object CC_degreeKinKvariable(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degree-in-variable");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0015;
/* end of prologue */
    v0047 = stack[-1];
    if (!consp(v0047)) goto v0036;
    v0047 = stack[-1];
    v0047 = qcar(v0047);
    v0047 = (consp(v0047) ? nil : lisp_true);
    goto v0049;

v0049:
    if (v0047 == nil) goto v0022;
    v0047 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v0047); }

v0022:
    v0047 = stack[-1];
    v0047 = qcar(v0047);
    v0048 = qcdr(v0047);
    v0047 = (Lisp_Object)1; /* 0 */
    if (v0048 == v0047) goto v0021;
    v0048 = stack[0];
    v0047 = stack[-1];
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    if (equal(v0048, v0047)) goto v0032;
    v0047 = stack[-1];
    v0047 = qcar(v0047);
    v0048 = qcdr(v0047);
    v0047 = stack[0];
    stack[-2] = CC_degreeKinKvariable(env, v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    v0047 = stack[-1];
    v0048 = qcdr(v0047);
    v0047 = stack[0];
    v0047 = CC_degreeKinKvariable(env, v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-3];
    {
        Lisp_Object v0051 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* max */
        return (*qfn2(fn))(qenv(fn), v0051, v0047);
    }

v0032:
    v0047 = stack[-1];
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    v0047 = qcdr(v0047);
    { popv(4); return onevalue(v0047); }

v0021:
    v0047 = elt(env, 2); /* "Polynomial with a zero coefficient found" 
*/
    {
        popv(4);
        fn = elt(env, 4); /* errorf */
        return (*qfn1(fn))(qenv(fn), v0047);
    }

v0036:
    v0047 = qvalue(elt(env, 1)); /* t */
    goto v0049;
/* error exit handlers */
v0050:
    popv(4);
    return nil;
}



/* Code for setunion */

static Lisp_Object CC_setunion(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0028, v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setunion");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    v0028 = v0015;
/* end of prologue */

v0004:
    v0042 = stack[0];
    if (v0042 == nil) { popv(3); return onevalue(v0028); }
    v0042 = stack[0];
    v0052 = qcar(v0042);
    v0042 = v0028;
    v0042 = Lmember(nil, v0052, v0042);
    if (v0042 == nil) goto v0044;
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    stack[0] = v0042;
    goto v0004;

v0044:
    stack[-1] = v0028;
    v0042 = stack[0];
    v0042 = qcar(v0042);
    v0042 = ncons(v0042);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    v0042 = Lappend(nil, stack[-1], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    v0028 = v0042;
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    stack[0] = v0042;
    goto v0004;
/* error exit handlers */
v0053:
    popv(3);
    return nil;
}



/* Code for ofsf_subf */

static Lisp_Object MS_CDECL CC_ofsf_subf(Lisp_Object env, int nargs,
                         Lisp_Object v0015, Lisp_Object v0003,
                         Lisp_Object v0054, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0072, v0073;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_subf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_subf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0054,v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0015,v0003,v0054);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0054;
    stack[-1] = v0003;
    stack[-2] = v0015;
/* end of prologue */
    v0071 = stack[-2];
    if (!consp(v0071)) goto v0017;
    v0071 = stack[-2];
    v0071 = qcar(v0071);
    v0071 = (consp(v0071) ? nil : lisp_true);
    goto v0034;

v0034:
    if (v0071 == nil) goto v0031;
    v0072 = stack[-2];
    v0071 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0072, v0071);

v0031:
    v0071 = stack[-2];
    v0073 = qcdr(v0071);
    v0072 = stack[-1];
    v0071 = stack[0];
    v0071 = CC_ofsf_subf(env, 3, v0073, v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    stack[-3] = v0071;
    v0071 = stack[-2];
    v0071 = qcar(v0071);
    v0071 = qcar(v0071);
    v0072 = qcar(v0071);
    v0071 = stack[-1];
    if (v0072 == v0071) goto v0075;
    v0071 = stack[-2];
    v0071 = qcar(v0071);
    v0073 = qcdr(v0071);
    v0072 = stack[-1];
    v0071 = stack[0];
    stack[0] = CC_ofsf_subf(env, 3, v0073, v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    v0071 = stack[-2];
    v0071 = qcar(v0071);
    v0071 = qcar(v0071);
    v0072 = qcar(v0071);
    v0071 = stack[-2];
    v0071 = qcar(v0071);
    v0071 = qcar(v0071);
    v0071 = qcdr(v0071);
    fn = elt(env, 2); /* ofsf_pow2q */
    v0071 = (*qfn2(fn))(qenv(fn), v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v0072 = (*qfn2(fn))(qenv(fn), stack[0], v0071);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    v0071 = stack[-3];
    {
        popv(5);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0072, v0071);
    }

v0075:
    v0071 = stack[-2];
    v0071 = qcar(v0071);
    v0072 = qcdr(v0071);
    v0071 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    v0072 = stack[0];
    v0071 = stack[-2];
    v0071 = qcar(v0071);
    v0071 = qcar(v0071);
    v0071 = qcdr(v0071);
    fn = elt(env, 5); /* exptsq */
    v0071 = (*qfn2(fn))(qenv(fn), v0072, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v0072 = (*qfn2(fn))(qenv(fn), stack[-1], v0071);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    v0071 = stack[-3];
    {
        popv(5);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0072, v0071);
    }

v0017:
    v0071 = qvalue(elt(env, 1)); /* t */
    goto v0034;
/* error exit handlers */
v0074:
    popv(5);
    return nil;
}



/* Code for get_group_in */

static Lisp_Object CC_get_group_in(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object v0076;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_group_in");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0076 = v0015;
/* end of prologue */
    v0076 = qcar(v0076);
    return onevalue(v0076);
}



/* Code for qqe_number!-of!-adds!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKaddsKinKqterm(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_number-of-adds-in-qterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
/* end of prologue */

v0005:
    v0077 = stack[0];
    if (!consp(v0077)) goto v0046;
    v0077 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v0031 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-1];
    v0077 = elt(env, 1); /* (ladd radd) */
    v0077 = Lmemq(nil, v0031, v0077);
    if (v0077 == nil) goto v0078;
    v0077 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-1];
    v0077 = CC_qqe_numberKofKaddsKinKqterm(env, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    popv(2);
    return add1(v0077);

v0078:
    v0077 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-1];
    stack[0] = v0077;
    goto v0005;

v0046:
    v0077 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0077); }
/* error exit handlers */
v0029:
    popv(2);
    return nil;
}



/* Code for ibalp_lenisone */

static Lisp_Object CC_ibalp_lenisone(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0016;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_lenisone");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0016 = v0015;
/* end of prologue */
    v0017 = v0016;
    if (v0017 == nil) goto v0005;
    v0017 = v0016;
    v0017 = qcdr(v0017);
    v0017 = (v0017 == nil ? lisp_true : nil);
    return onevalue(v0017);

v0005:
    v0017 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0017);
}



/* Code for terpri!* */

static Lisp_Object CC_terpriH(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0082, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for terpri*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
/* end of prologue */
    v0081 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v0081 == nil) goto v0036;
    v0082 = qvalue(elt(env, 1)); /* outputhandler!* */
    v0083 = elt(env, 2); /* terpri */
    v0081 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v0082, v0083, v0081);

v0036:
    v0081 = qvalue(elt(env, 3)); /* testing!-width!* */
    if (v0081 == nil) goto v0024;
    v0081 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 5)) = v0081; /* overflowed!* */
    { popv(3); return onevalue(v0081); }

v0024:
    v0081 = qvalue(elt(env, 6)); /* !*fort */
    if (v0081 == nil) goto v0084;
    v0082 = qvalue(elt(env, 7)); /* posn!* */
    v0081 = (Lisp_Object)1; /* 0 */
    if (v0082 == v0081) goto v0085;
    v0081 = stack[0];
    goto v0025;

v0025:
    if (v0081 == nil) goto v0077;
    v0081 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    goto v0077;

v0077:
    v0081 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v0081; /* posn!* */
    { popv(3); return onevalue(v0081); }

v0085:
    v0081 = qvalue(elt(env, 8)); /* nil */
    goto v0025;

v0084:
    v0081 = qvalue(elt(env, 9)); /* !*nat */
    if (v0081 == nil) goto v0046;
    v0081 = qvalue(elt(env, 10)); /* pline!* */
    if (v0081 == nil) goto v0046;
    v0081 = qvalue(elt(env, 10)); /* pline!* */
    v0081 = Lreverse(nil, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    qvalue(elt(env, 10)) = v0081; /* pline!* */
    v0081 = qvalue(elt(env, 11)); /* ymax!* */
    stack[-1] = v0081;
    goto v0075;

v0075:
    v0082 = stack[-1];
    v0081 = qvalue(elt(env, 12)); /* ymin!* */
    v0081 = difference2(v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0081 = Lminusp(nil, v0081);
    env = stack[-2];
    if (v0081 == nil) goto v0067;
    v0081 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 10)) = v0081; /* pline!* */
    goto v0046;

v0046:
    v0081 = stack[0];
    if (v0081 == nil) goto v0086;
    v0081 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    goto v0086;

v0086:
    v0081 = qvalue(elt(env, 13)); /* orig!* */
    qvalue(elt(env, 7)) = v0081; /* posn!* */
    v0081 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v0081; /* ymin!* */
    qvalue(elt(env, 11)) = v0081; /* ymax!* */
    qvalue(elt(env, 14)) = v0081; /* ycoord!* */
    v0081 = nil;
    { popv(3); return onevalue(v0081); }

v0067:
    v0082 = qvalue(elt(env, 10)); /* pline!* */
    v0081 = stack[-1];
    fn = elt(env, 15); /* scprint */
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0081 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0081 = stack[-1];
    v0081 = sub1(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    stack[-1] = v0081;
    goto v0075;
/* error exit handlers */
v0057:
    popv(3);
    return nil;
}



/* Code for cr!:prep */

static Lisp_Object CC_crTprep(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:prep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
/* end of prologue */
    v0032 = elt(env, 1); /* !:rd!: */
    v0031 = stack[0];
    v0031 = qcdr(v0031);
    v0031 = qcar(v0031);
    v0031 = cons(v0032, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    v0032 = elt(env, 1); /* !:rd!: */
    v0031 = stack[0];
    v0031 = qcdr(v0031);
    v0031 = qcdr(v0031);
    v0031 = cons(v0032, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    v0031 = cons(stack[-1], v0031);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* crprep1 */
        return (*qfn1(fn))(qenv(fn), v0031);
    }
/* error exit handlers */
v0006:
    popv(3);
    return nil;
}



/* Code for initwght */

static Lisp_Object CC_initwght(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0103, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initwght");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0015;
/* end of prologue */
    v0102 = (Lisp_Object)1; /* 0 */
    stack[-5] = v0102;
    stack[0] = v0102;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0103 = qvalue(elt(env, 2)); /* maxvar */
    v0102 = stack[-3];
    v0102 = plus2(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    v0103 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    v0102 = (Lisp_Object)65; /* 4 */
    v0102 = *(Lisp_Object *)((char *)v0103 + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    stack[-4] = v0102;
    goto v0035;

v0035:
    v0102 = stack[-4];
    if (v0102 == nil) goto v0106;
    v0102 = stack[-4];
    v0102 = qcar(v0102);
    stack[-2] = v0102;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0103 = qvalue(elt(env, 2)); /* maxvar */
    v0102 = stack[-2];
    v0102 = qcar(v0102);
    v0102 = plus2(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    v0103 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    v0102 = (Lisp_Object)1; /* 0 */
    v0102 = *(Lisp_Object *)((char *)v0103 + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    if (v0102 == nil) goto v0043;
    v0102 = stack[-2];
    v0102 = qcdr(v0102);
    v0102 = qcar(v0102);
    fn = elt(env, 5); /* dm!-abs */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    v0104 = v0102;
    v0102 = v0104;
    if (!consp(v0102)) goto v0050;
    v0102 = v0104;
    v0103 = qcar(v0102);
    v0102 = elt(env, 4); /* onep */
    v0102 = get(v0103, v0102);
    env = stack[-6];
    v0103 = v0104;
    v0102 = Lapply1(nil, v0102, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    goto v0107;

v0107:
    if (!(v0102 == nil)) goto v0108;
    v0102 = stack[-5];
    v0102 = add1(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    stack[-5] = v0102;
    goto v0108;

v0108:
    v0102 = stack[0];
    v0102 = add1(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    stack[0] = v0102;
    goto v0043;

v0043:
    v0102 = stack[-4];
    v0102 = qcdr(v0102);
    stack[-4] = v0102;
    goto v0035;

v0050:
    v0102 = v0104;
    v0102 = Lonep(nil, v0102);
    env = stack[-6];
    goto v0107;

v0106:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0103 = qvalue(elt(env, 2)); /* maxvar */
    v0102 = stack[-3];
    v0102 = plus2(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    stack[-4] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[-2] = stack[0];
    stack[-1] = stack[-5];
    v0103 = (Lisp_Object)49; /* 3 */
    v0102 = stack[-5];
    v0102 = times2(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    v0102 = plus2(stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-6];
    v0102 = acons(stack[-2], stack[-1], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    *(Lisp_Object *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v0102;
    v0102 = nil;
    { popv(7); return onevalue(v0102); }
/* error exit handlers */
v0105:
    popv(7);
    return nil;
}



/* Code for vevmaptozero1 */

static Lisp_Object CC_vevmaptozero1(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevmaptozero1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0030 = v0003;
    stack[0] = v0015;
/* end of prologue */

v0004:
    v0014 = stack[0];
    if (v0014 == nil) { popv(2); return onevalue(v0030); }
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    stack[0] = v0014;
    v0014 = (Lisp_Object)1; /* 0 */
    v0030 = cons(v0014, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    goto v0004;
/* error exit handlers */
v0084:
    popv(2);
    return nil;
}



/* Code for lid */

static Lisp_Object CC_lid(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0017;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lid");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0034 = v0015;
/* end of prologue */
    v0017 = v0034;
    if (!consp(v0017)) return onevalue(v0034);
    v0034 = qcar(v0034);
    return onevalue(v0034);
}



/* Code for physopaeval */

static Lisp_Object CC_physopaeval(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073, v0113, v0114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopaeval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
/* end of prologue */
    v0073 = stack[0];
    fn = elt(env, 7); /* physopp */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    if (v0073 == nil) goto v0049;
    v0113 = stack[0];
    v0073 = elt(env, 1); /* rvalue */
    v0073 = get(v0113, v0073);
    env = stack[-1];
    v0114 = v0073;
    if (v0073 == nil) goto v0016;
    v0073 = v0114;
    v0113 = qcar(v0073);
    v0073 = elt(env, 2); /* !*sq */
    if (!(v0113 == v0073)) { popv(2); return onevalue(v0114); }
    v0073 = qvalue(elt(env, 3)); /* !*nosq */
    if (v0073 == nil) goto v0026;
    v0073 = v0114;
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    {
        popv(2);
        fn = elt(env, 8); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v0073);
    }

v0026:
    v0073 = v0114;
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    {
        popv(2);
        fn = elt(env, 9); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0073);
    }

v0016:
    v0073 = stack[0];
    if (!consp(v0073)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0073 = stack[0];
    v0113 = qcar(v0073);
    v0073 = elt(env, 4); /* psimpfn */
    v0073 = get(v0113, v0073);
    env = stack[-1];
    v0114 = v0073;
    if (v0073 == nil) goto v0050;
    v0113 = v0114;
    v0073 = stack[0];
        popv(2);
        return Lapply1(nil, v0113, v0073);

v0050:
    v0073 = stack[0];
    v0113 = qcar(v0073);
    v0073 = elt(env, 5); /* opmtch */
    v0073 = get(v0113, v0073);
    env = stack[-1];
    if (v0073 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0073 = stack[0];
    fn = elt(env, 10); /* opmtch!* */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    v0114 = v0073;
    if (v0073 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0114); }

v0049:
    v0073 = stack[0];
    if (!consp(v0073)) goto v0116;
    v0073 = stack[0];
    v0113 = qcar(v0073);
    v0073 = elt(env, 2); /* !*sq */
    v0073 = (v0113 == v0073 ? lisp_true : nil);
    goto v0082;

v0082:
    if (v0073 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0073 = qvalue(elt(env, 3)); /* !*nosq */
    if (v0073 == nil) goto v0106;
    v0073 = stack[0];
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    {
        popv(2);
        fn = elt(env, 8); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v0073);
    }

v0106:
    v0073 = stack[0];
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    {
        popv(2);
        fn = elt(env, 9); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0073);
    }

v0116:
    v0073 = qvalue(elt(env, 6)); /* nil */
    goto v0082;
/* error exit handlers */
v0115:
    popv(2);
    return nil;
}



/* Code for all_defined_vertex */

static Lisp_Object CC_all_defined_vertex(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0009, v0021, v0020;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined_vertex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0008 = v0003;
    v0009 = v0015;
/* end of prologue */
    v0020 = v0009;
    v0021 = qvalue(elt(env, 1)); /* nil */
    v0009 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* al1_defined_vertex */
        return (*qfnn(fn))(qenv(fn), 4, v0020, v0021, v0009, v0008);
    }
}



/* Code for assert_uninstall_all */

static Lisp_Object MS_CDECL CC_assert_uninstall_all(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_uninstall_all");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_uninstall_all");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0049 = qvalue(elt(env, 1)); /* !*assert */
    if (v0049 == nil) goto v0005;
    v0049 = qvalue(elt(env, 2)); /* assert_functionl!* */
    {
        fn = elt(env, 3); /* assert_uninstall */
        return (*qfn1(fn))(qenv(fn), v0049);
    }

v0005:
    v0049 = nil;
    return onevalue(v0049);
}



/* Code for mo!=revlexcomp */

static Lisp_Object CC_moMrevlexcomp(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=revlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0015;
/* end of prologue */
    v0080 = stack[-1];
    stack[-2] = Llength(nil, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0080 = stack[0];
    v0080 = Llength(nil, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v0080))) goto v0004;
    v0080 = stack[0];
    stack[-2] = Llength(nil, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0080 = stack[-1];
    v0080 = Llength(nil, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v0080))) goto v0008;
    v0080 = stack[-1];
    stack[-1] = Lreverse(nil, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0080 = stack[0];
    v0080 = Lreverse(nil, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    fn = elt(env, 1); /* mo!=degcomp */
    v0080 = (*qfn2(fn))(qenv(fn), stack[-1], v0080);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    popv(4);
    return negate(v0080);

v0008:
    v0080 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0080); }

v0004:
    v0080 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v0080); }
/* error exit handlers */
v0118:
    popv(4);
    return nil;
}



/* Code for dv_cambhead */

static Lisp_Object CC_dv_cambhead(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_cambhead");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
/* end of prologue */

v0027:
    v0043 = stack[0];
    fn = elt(env, 4); /* listp */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    if (v0043 == nil) goto v0004;
    v0043 = stack[0];
    stack[-1] = qcar(v0043);
    v0053 = elt(env, 1); /* expt */
    v0043 = elt(env, 2); /* minus */
    v0043 = list2(v0053, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    v0043 = Lmember(nil, stack[-1], v0043);
    if (v0043 == nil) goto v0033;
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    v0043 = qcar(v0043);
    stack[0] = v0043;
    goto v0027;

v0033:
    v0043 = stack[0];
    fn = elt(env, 4); /* listp */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    if (v0043 == nil) goto v0004;
    v0043 = stack[0];
    v0043 = qcar(v0043);
    { popv(3); return onevalue(v0043); }

v0004:
    v0043 = nil;
    { popv(3); return onevalue(v0043); }
/* error exit handlers */
v0119:
    popv(3);
    return nil;
}



/* Code for expt!-mod!-p */

static Lisp_Object CC_exptKmodKp(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0067, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expt-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0107 = v0003;
    stack[0] = v0015;
/* end of prologue */
    v0067 = v0107;
    v0070 = (Lisp_Object)1; /* 0 */
    if (v0067 == v0070) goto v0004;
    v0067 = v0107;
    v0070 = (Lisp_Object)17; /* 1 */
    if (v0067 == v0070) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0067 = v0107;
    v0070 = (Lisp_Object)33; /* 2 */
    v0070 = Ldivide(nil, v0067, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    stack[-1] = v0070;
    v0067 = stack[0];
    v0070 = stack[-1];
    v0070 = qcar(v0070);
    v0070 = CC_exptKmodKp(env, v0067, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0107 = v0070;
    v0070 = v0107;
    v0067 = v0107;
    fn = elt(env, 1); /* times!-mod!-p */
    v0070 = (*qfn2(fn))(qenv(fn), v0070, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    v0107 = v0070;
    v0070 = stack[-1];
    v0067 = qcdr(v0070);
    v0070 = (Lisp_Object)1; /* 0 */
    if (v0067 == v0070) { popv(3); return onevalue(v0107); }
    v0067 = v0107;
    v0070 = stack[0];
    fn = elt(env, 1); /* times!-mod!-p */
    v0070 = (*qfn2(fn))(qenv(fn), v0067, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    v0107 = v0070;
    { popv(3); return onevalue(v0107); }

v0004:
    v0070 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0070); }
/* error exit handlers */
v0120:
    popv(3);
    return nil;
}



/* Code for freeofl */

static Lisp_Object CC_freeofl(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0000, v0002, v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeofl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0015;
/* end of prologue */

v0027:
    v0000 = stack[0];
    if (v0000 == nil) goto v0004;
    v0000 = stack[0];
    v0002 = qcar(v0000);
    v0000 = stack[-1];
    fn = elt(env, 4); /* smember */
    v0000 = (*qfn2(fn))(qenv(fn), v0002, v0000);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-2];
    if (!(v0000 == nil)) goto v0124;
    v0000 = stack[0];
    v0010 = qcar(v0000);
    v0002 = stack[-1];
    v0000 = qvalue(elt(env, 2)); /* depl!* */
    v0000 = Lassoc(nil, v0002, v0000);
    v0000 = Lmember(nil, v0010, v0000);
    if (!(v0000 == nil)) goto v0124;
    v0002 = stack[-1];
    v0000 = stack[0];
    v0000 = qcdr(v0000);
    stack[-1] = v0002;
    stack[0] = v0000;
    goto v0027;

v0124:
    v0000 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0000); }

v0004:
    v0000 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0000); }
/* error exit handlers */
v0123:
    popv(3);
    return nil;
}



/* Code for mapins */

static Lisp_Object CC_mapins(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0052, v0080;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapins");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0015;
/* end of prologue */
    stack[-2] = nil;
    goto v0076;

v0076:
    v0028 = stack[0];
    if (v0028 == nil) goto v0036;
    v0052 = stack[-1];
    v0028 = stack[0];
    v0028 = qcar(v0028);
    v0028 = qcar(v0028);
    v0080 = cons(v0052, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0028 = stack[0];
    v0028 = qcar(v0028);
    v0052 = qcdr(v0028);
    v0028 = stack[-2];
    v0028 = acons(v0080, v0052, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    stack[-2] = v0028;
    v0028 = stack[0];
    v0028 = qcdr(v0028);
    stack[0] = v0028;
    goto v0076;

v0036:
    v0028 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0028);
    }
/* error exit handlers */
v0118:
    popv(4);
    return nil;
}



/* Code for qqe_simplat1 */

static Lisp_Object CC_qqe_simplat1(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001, v0000, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0015;
/* end of prologue */
    v0001 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v0001 = (*qfn1(fn))(qenv(fn), v0001);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    v0002 = v0001;
    v0000 = v0002;
    v0001 = elt(env, 1); /* (qequal qneq) */
    v0001 = Lmemq(nil, v0000, v0001);
    if (v0001 == nil) goto v0021;
    v0000 = v0002;
    v0001 = elt(env, 2); /* qequal */
    if (v0000 == v0001) goto v0007;
    v0000 = stack[-1];
    v0001 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* qqe_simplqneq */
        return (*qfn2(fn))(qenv(fn), v0000, v0001);
    }

v0007:
    v0000 = stack[-1];
    v0001 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* qqe_simplqequal */
        return (*qfn2(fn))(qenv(fn), v0000, v0001);
    }

v0021:
    v0000 = stack[-1];
    v0001 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* qqe_simplbtat */
        return (*qfn2(fn))(qenv(fn), v0000, v0001);
    }
/* error exit handlers */
v0012:
    popv(3);
    return nil;
}



/* Code for rl_negateat */

static Lisp_Object CC_rl_negateat(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_negateat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0033 = v0015;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_negateat!* */
    v0033 = ncons(v0033);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    {
        Lisp_Object v0016 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0016, v0033);
    }
/* error exit handlers */
v0017:
    popv(2);
    return nil;
}



/* Code for ibalp_hassimple */

static Lisp_Object CC_ibalp_hassimple(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0080;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_hassimple");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0052 = v0015;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v0052;
    goto v0036;

v0036:
    v0052 = stack[0];
    if (v0052 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0052 = stack[-1];
    if (!(v0052 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0052 = stack[0];
    v0052 = qcar(v0052);
    v0080 = qcar(v0052);
    v0052 = stack[0];
    v0052 = qcar(v0052);
    v0052 = qcdr(v0052);
    v0052 = qcar(v0052);
    fn = elt(env, 2); /* ibalp_commonlenisone */
    v0052 = (*qfn2(fn))(qenv(fn), v0080, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    if (v0052 == nil) goto v0020;
    v0052 = stack[0];
    v0052 = qcar(v0052);
    stack[-1] = v0052;
    goto v0020;

v0020:
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    stack[0] = v0052;
    goto v0036;
/* error exit handlers */
v0085:
    popv(3);
    return nil;
}



/* Code for aex_simplenullp */

static Lisp_Object CC_aex_simplenullp(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_simplenullp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0004 = v0015;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_nullp */
        return (*qfn1(fn))(qenv(fn), v0004);
    }
/* error exit handlers */
v0076:
    popv(1);
    return nil;
}



/* Code for variablesir */

static Lisp_Object MS_CDECL CC_variablesir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "variablesir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variablesir");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    v0053 = qvalue(elt(env, 1)); /* char */
    v0043 = elt(env, 2); /* (!/ o m b v a r) */
    if (equal(v0053, v0043)) goto v0076;
    fn = elt(env, 4); /* omvir */
    v0043 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-1];
    stack[0] = v0043;
    fn = elt(env, 5); /* lex */
    v0043 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-1];
    v0043 = CC_variablesir(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    v0053 = stack[0];
    if (v0053 == nil) goto v0014;
    v0053 = stack[0];
    popv(2);
    return cons(v0053, v0043);

v0014:
    v0053 = stack[0];
        popv(2);
        return Lappend(nil, v0053, v0043);

v0076:
    v0043 = nil;
    { popv(2); return onevalue(v0043); }
/* error exit handlers */
v0118:
    popv(2);
    return nil;
}



/* Code for evenfree */

static Lisp_Object CC_evenfree(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evenfree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
/* end of prologue */
    v0037 = stack[0];
    if (v0037 == nil) goto v0005;
    v0037 = stack[0];
    if (is_number(v0037)) goto v0034;
    v0037 = stack[0];
    v0037 = qcar(v0037);
    v0100 = ncons(v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    v0037 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v0037 = (*qfn2(fn))(qenv(fn), v0100, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    v0037 = qcdr(v0037);
    stack[-1] = v0037;
    v0037 = stack[-1];
    fn = elt(env, 3); /* minusf */
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    if (v0037 == nil) goto v0127;
    v0037 = stack[-1];
    fn = elt(env, 4); /* negf */
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    stack[-1] = v0037;
    goto v0026;

v0026:
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    v0037 = CC_evenfree(env, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    {
        Lisp_Object v0128 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* addf */
        return (*qfn2(fn))(qenv(fn), v0128, v0037);
    }

v0127:
    v0037 = stack[-1];
    stack[-1] = v0037;
    goto v0026;

v0034:
    v0100 = stack[0];
    v0037 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v0037 = (*qfn2(fn))(qenv(fn), v0100, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    v0037 = qcdr(v0037);
    stack[0] = v0037;
    v0037 = stack[0];
    fn = elt(env, 3); /* minusf */
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    if (v0037 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0037 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* negf */
        return (*qfn1(fn))(qenv(fn), v0037);
    }

v0005:
    v0037 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0037); }
/* error exit handlers */
v0108:
    popv(3);
    return nil;
}



/* Code for invp */

static Lisp_Object CC_invp(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0100, v0066;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for invp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0066 = v0015;
/* end of prologue */
    v0100 = v0066;
    v0037 = elt(env, 1); /* unit */
    if (v0100 == v0037) return onevalue(v0066);
    v0037 = v0066;
    if (!consp(v0037)) goto v0009;
    v0037 = v0066;
    v0100 = qcar(v0037);
    v0037 = elt(env, 3); /* (comm anticomm) */
    v0037 = Lmember(nil, v0100, v0037);
    if (v0037 == nil) goto v0010;
    v0100 = elt(env, 4); /* quotient */
    v0037 = (Lisp_Object)17; /* 1 */
    return list3(v0100, v0037, v0066);

v0010:
    v0037 = v0066;
    v0100 = qcar(v0037);
    v0037 = elt(env, 2); /* inverse */
    v0037 = get(v0100, v0037);
    v0100 = v0066;
    v0100 = qcdr(v0100);
    return cons(v0037, v0100);

v0009:
    v0037 = v0066;
    v0100 = elt(env, 2); /* inverse */
    return get(v0037, v0100);
}



/* Code for mkarray1 */

static Lisp_Object CC_mkarray1(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0048;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkarray1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0003;
    stack[-5] = v0015;
/* end of prologue */
    v0047 = stack[-5];
    if (v0047 == nil) goto v0034;
    v0047 = stack[-5];
    v0047 = qcar(v0047);
    v0047 = sub1(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-7];
    stack[-6] = v0047;
    v0047 = stack[-6];
    v0047 = Lmkvect(nil, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-7];
    stack[-3] = v0047;
    v0047 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0047;
    goto v0118;

v0118:
    v0048 = stack[-6];
    v0047 = stack[-2];
    v0047 = difference2(v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-7];
    v0047 = Lminusp(nil, v0047);
    env = stack[-7];
    if (!(v0047 == nil)) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-3];
    stack[0] = stack[-2];
    v0047 = stack[-5];
    v0048 = qcdr(v0047);
    v0047 = stack[-4];
    v0047 = CC_mkarray1(env, v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0047;
    v0047 = stack[-2];
    v0047 = add1(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-7];
    stack[-2] = v0047;
    goto v0118;

v0034:
    v0048 = stack[-4];
    v0047 = elt(env, 1); /* symbolic */
    if (v0048 == v0047) goto v0035;
    v0047 = (Lisp_Object)1; /* 0 */
    { popv(8); return onevalue(v0047); }

v0035:
    v0047 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v0047); }
/* error exit handlers */
v0068:
    popv(8);
    return nil;
}



/* Code for !:divide */

static Lisp_Object CC_Tdivide(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0127, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :divide");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0127 = v0003;
    v0013 = v0015;
/* end of prologue */
    v0123 = v0013;
    if (v0123 == nil) goto v0004;
    v0123 = v0127;
    if (v0123 == nil) goto v0035;
    v0123 = v0013;
    if (!consp(v0123)) goto v0077;
    v0123 = qvalue(elt(env, 1)); /* nil */
    goto v0045;

v0045:
    if (v0123 == nil) goto v0001;
    v0123 = v0013;
    {
        popv(1);
        fn = elt(env, 6); /* dividef */
        return (*qfn2(fn))(qenv(fn), v0123, v0127);
    }

v0001:
    v0123 = elt(env, 5); /* divide */
    {
        popv(1);
        fn = elt(env, 7); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0013, v0127, v0123);
    }

v0077:
    v0123 = v0127;
    v0123 = (consp(v0123) ? nil : lisp_true);
    goto v0045;

v0035:
    v0123 = elt(env, 2); /* "zero divisor" */
    v0127 = v0123;
    v0123 = v0127;
    qvalue(elt(env, 3)) = v0123; /* errmsg!* */
    v0123 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0123 == nil)) goto v0021;
    v0123 = v0127;
    fn = elt(env, 8); /* lprie */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[0];
    goto v0021;

v0021:
    v0123 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    v0123 = nil;
    { popv(1); return onevalue(v0123); }

v0004:
    v0123 = qvalue(elt(env, 1)); /* nil */
    popv(1);
    return ncons(v0123);
/* error exit handlers */
v0064:
    popv(1);
    return nil;
}



/* Code for gperm0 */

static Lisp_Object CC_gperm0(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0024 = v0015;
/* end of prologue */
    v0023 = v0024;
    if (v0023 == nil) goto v0005;
    v0023 = v0024;
    stack[0] = qcdr(v0023);
    v0023 = v0024;
    v0023 = qcar(v0023);
    v0023 = ncons(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-1];
    v0023 = ncons(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-1];
    {
        Lisp_Object v0078 = stack[0];
        popv(2);
        fn = elt(env, 2); /* gperm3 */
        return (*qfn2(fn))(qenv(fn), v0078, v0023);
    }

v0005:
    v0023 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0023); }
/* error exit handlers */
v0014:
    popv(2);
    return nil;
}



/* Code for primep */

static Lisp_Object CC_primep(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for primep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
/* end of prologue */

v0005:
    v0130 = stack[0];
    v0130 = integerp(v0130);
    if (v0130 == nil) goto v0034;
    v0131 = stack[0];
    v0130 = (Lisp_Object)1; /* 0 */
    v0130 = (Lisp_Object)lessp2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    v0130 = v0130 ? lisp_true : nil;
    env = stack[-2];
    if (v0130 == nil) goto v0029;
    v0130 = stack[0];
    v0130 = negate(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-2];
    stack[0] = v0130;
    goto v0005;

v0029:
    v0131 = stack[0];
    v0130 = (Lisp_Object)17; /* 1 */
    if (v0131 == v0130) goto v0031;
    v0131 = stack[0];
    v0130 = qvalue(elt(env, 3)); /* !*last!-prime!-in!-list!* */
    v0130 = (Lisp_Object)lesseq2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    v0130 = v0130 ? lisp_true : nil;
    env = stack[-2];
    if (v0130 == nil) goto v0064;
    v0130 = stack[0];
    v0131 = qvalue(elt(env, 4)); /* !*primelist!* */
    v0130 = Lmember(nil, v0130, v0131);
    { popv(3); return onevalue(v0130); }

v0064:
    v0131 = stack[0];
    v0130 = qvalue(elt(env, 5)); /* !*last!-prime!-squared!* */
    v0130 = (Lisp_Object)lesseq2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    v0130 = v0130 ? lisp_true : nil;
    env = stack[-2];
    if (v0130 == nil) goto v0133;
    v0130 = qvalue(elt(env, 4)); /* !*primelist!* */
    stack[-1] = v0130;
    goto v0047;

v0047:
    v0130 = stack[-1];
    if (v0130 == nil) goto v0039;
    v0131 = stack[0];
    v0130 = stack[-1];
    v0130 = qcar(v0130);
    v0131 = Cremainder(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-2];
    v0130 = (Lisp_Object)1; /* 0 */
    if (v0131 == v0130) goto v0039;
    v0130 = stack[-1];
    v0130 = qcdr(v0130);
    stack[-1] = v0130;
    goto v0047;

v0039:
    v0130 = stack[-1];
    v0130 = (v0130 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0130); }

v0133:
    v0131 = stack[0];
    v0130 = qvalue(elt(env, 6)); /* largest!-small!-modulus */
    v0130 = (Lisp_Object)greaterp2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    v0130 = v0130 ? lisp_true : nil;
    env = stack[-2];
    if (v0130 == nil) goto v0058;
    v0130 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* general!-primep */
        return (*qfn1(fn))(qenv(fn), v0130);
    }

v0058:
    v0130 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* small!-primep */
        return (*qfn1(fn))(qenv(fn), v0130);
    }

v0031:
    v0130 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0130); }

v0034:
    v0131 = stack[0];
    v0130 = elt(env, 1); /* "integer" */
    {
        popv(3);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0131, v0130);
    }
/* error exit handlers */
v0132:
    popv(3);
    return nil;
}



/* Code for xread1 */

static Lisp_Object CC_xread1(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0364, v0365, v0366;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xread1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0015;
/* end of prologue */
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v0364 = qvalue(elt(env, 1)); /* commentlist!* */
    if (v0364 == nil) goto v0034;
    v0364 = qvalue(elt(env, 1)); /* commentlist!* */
    stack[-1] = v0364;
    v0364 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v0364; /* commentlist!* */
    goto v0034;

v0034:
    v0364 = qvalue(elt(env, 3)); /* cursym!* */
    stack[-3] = v0364;
    goto v0017;

v0017:
    v0364 = stack[-3];
    if (!(symbolp(v0364))) goto v0016;
    v0365 = stack[-3];
    v0364 = elt(env, 4); /* !*lpar!* */
    if (v0365 == v0364) goto v0008;
    v0365 = stack[-3];
    v0364 = elt(env, 5); /* !*rpar!* */
    if (v0365 == v0364) goto v0021;
    v0365 = stack[-3];
    v0364 = elt(env, 6); /* infix */
    v0364 = get(v0365, v0364);
    env = stack[-9];
    stack[-4] = v0364;
    if (!(v0364 == nil)) goto v0020;
    v0365 = stack[-3];
    v0364 = elt(env, 7); /* delim */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    if (v0364 == nil) goto v0065;
    v0365 = qvalue(elt(env, 3)); /* cursym!* */
    v0364 = elt(env, 30); /* !*semicol!* */
    if (v0365 == v0364) goto v0367;
    fn = elt(env, 57); /* eolcheck */
    v0364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0367;

v0367:
    v0365 = stack[-3];
    v0364 = elt(env, 50); /* !*colon!* */
    if (v0365 == v0364) goto v0369;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0370;

v0370:
    if (!(v0364 == nil)) goto v0371;
    v0365 = stack[-3];
    v0364 = elt(env, 53); /* nodel */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    if (v0364 == nil) goto v0372;
    v0364 = stack[-7];
    if (v0364 == nil) goto v0373;
    v0365 = stack[-7];
    v0364 = elt(env, 28); /* group */
    if (v0365 == v0364) goto v0374;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0375;

v0375:
    if (!(v0364 == nil)) goto v0371;
    v0364 = stack[-7];
    if (!(symbolp(v0364))) goto v0032;
    v0365 = stack[-7];
    v0364 = elt(env, 24); /* paren */
    if (v0365 == v0364) goto v0376;
    v0365 = stack[-7];
    v0364 = elt(env, 23); /* struct */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    goto v0377;

v0377:
    if (v0364 == nil) goto v0032;
    v0365 = elt(env, 55); /* "Too few right parentheses" */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0032;

v0032:
    v0364 = stack[-4];
    if (v0364 == nil) goto v0378;
    v0365 = elt(env, 27); /* "Improper delimiter" */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0379;

v0379:
    v0364 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0364;
    goto v0030;

v0030:
    v0364 = stack[-6];
    if (!(v0364 == nil)) goto v0380;
    v0365 = elt(env, 27); /* "Improper delimiter" */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0380;

v0380:
    v0364 = stack[-6];
    v0364 = qcar(v0364);
    stack[0] = v0364;
    goto v0014;

v0014:
    v0364 = stack[-6];
    v0364 = qcdr(v0364);
    stack[-6] = v0364;
    v0364 = stack[-6];
    if (v0364 == nil) goto v0381;
    v0364 = stack[-6];
    v0364 = qcar(v0364);
    if (!consp(v0364)) goto v0382;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0383;

v0383:
    if (v0364 == nil) goto v0384;
    v0365 = elt(env, 34); /* "Missing operator" */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0384;

v0384:
    v0364 = stack[-6];
    v0365 = qcar(v0364);
    v0364 = stack[0];
    v0364 = list2(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[0] = v0364;
    goto v0014;

v0382:
    v0364 = stack[-6];
    v0364 = qcar(v0364);
    v0364 = Lsymbolp(nil, v0364);
    env = stack[-9];
    v0364 = (v0364 == nil ? lisp_true : nil);
    goto v0383;

v0381:
    v0365 = stack[0];
    v0364 = stack[-8];
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-8] = v0364;
    goto v0084;

v0084:
    v0364 = stack[-5];
    if (v0364 == nil) goto v0385;
    v0365 = stack[-4];
    v0364 = stack[-5];
    v0364 = qcar(v0364);
    v0364 = qcar(v0364);
    v0364 = (Lisp_Object)lessp2(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    v0364 = v0364 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0364 == nil)) goto v0386;
    v0365 = stack[-4];
    v0364 = stack[-5];
    v0364 = qcar(v0364);
    v0364 = qcar(v0364);
    if (equal(v0365, v0364)) goto v0387;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0388;

v0388:
    if (!(v0364 == nil)) goto v0386;

v0389:
    v0366 = stack[-4];
    v0365 = stack[-3];
    v0364 = stack[-5];
    v0364 = acons(v0366, v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-5] = v0364;
    v0365 = stack[-3];
    v0364 = elt(env, 25); /* !*comma!* */
    if (!(v0365 == v0364)) goto v0024;
    v0364 = stack[-5];
    v0364 = qcdr(v0364);
    if (!(v0364 == nil)) goto v0019;
    v0364 = stack[-7];
    if (v0364 == nil) goto v0390;
    v0365 = stack[-7];
    v0364 = elt(env, 38); /* (lambda paren) */
    v0364 = Lmemq(nil, v0365, v0364);
    if (!(v0364 == nil)) goto v0391;
    v0365 = stack[-7];
    v0364 = elt(env, 23); /* struct */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    goto v0391;

v0391:
    if (!(v0364 == nil)) goto v0019;

v0029:
    v0364 = stack[-8];
    v0364 = qcdr(v0364);
    if (v0364 == nil) goto v0392;
    v0364 = elt(env, 56); /* "Please send hearn@rand.org your program!!" 
*/
    v0364 = Lprint(nil, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    v0365 = elt(env, 27); /* "Improper delimiter" */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    v0364 = nil;
    { popv(10); return onevalue(v0364); }

v0392:
    v0364 = stack[-8];
    v0365 = qcar(v0364);
    v0364 = stack[-1];
    {
        popv(10);
        fn = elt(env, 59); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v0365, v0364);
    }

v0019:
    fn = elt(env, 60); /* scan */
    v0364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-3] = v0364;
    goto v0017;

v0390:
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0391;

v0024:
    v0364 = stack[-2];
    stack[-3] = v0364;
    goto v0017;

v0386:
    v0364 = stack[-8];
    v0364 = qcdr(v0364);
    v0365 = qcar(v0364);
    v0364 = elt(env, 39); /* not */
    if (!consp(v0365)) goto v0393;
    v0365 = qcar(v0365);
    if (!(v0365 == v0364)) goto v0393;
    v0364 = stack[-5];
    v0364 = qcar(v0364);
    v0366 = qcar(v0364);
    v0365 = elt(env, 40); /* member */
    v0364 = elt(env, 6); /* infix */
    v0364 = get(v0365, v0364);
    env = stack[-9];
    v0364 = (Lisp_Object)geq2(v0366, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    v0364 = v0364 ? lisp_true : nil;
    env = stack[-9];
    goto v0394;

v0394:
    if (v0364 == nil) goto v0395;
    v0365 = elt(env, 41); /* "NOT" */
    v0364 = elt(env, 42); /* "infix operator" */
    fn = elt(env, 61); /* typerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0395;

v0395:
    v0364 = stack[-8];
    v0364 = qcdr(v0364);
    v0365 = qcar(v0364);
    v0364 = elt(env, 33); /* !*!*un!*!* */
    if (v0365 == v0364) goto v0396;
    v0364 = stack[-5];
    v0364 = qcar(v0364);
    stack[0] = qcdr(v0364);
    v0364 = stack[-8];
    v0365 = qcar(v0364);
    v0364 = stack[-5];
    v0364 = qcar(v0364);
    v0364 = qcdr(v0364);
    if (!consp(v0365)) goto v0397;
    v0365 = qcar(v0365);
    if (!(v0365 == v0364)) goto v0397;
    v0364 = stack[-5];
    v0364 = qcar(v0364);
    v0365 = qcdr(v0364);
    v0364 = elt(env, 35); /* nary */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    goto v0398;

v0398:
    if (v0364 == nil) goto v0399;
    v0364 = stack[-8];
    v0364 = qcdr(v0364);
    v0365 = qcar(v0364);
    v0364 = stack[-8];
    v0364 = qcar(v0364);
    v0364 = qcdr(v0364);
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0400;

v0400:
    v0364 = cons(stack[0], v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[0] = v0364;
    goto v0401;

v0401:
    v0364 = stack[-5];
    v0364 = qcdr(v0364);
    stack[-5] = v0364;
    v0365 = stack[0];
    v0364 = stack[-8];
    v0364 = qcdr(v0364);
    v0364 = qcdr(v0364);
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-8] = v0364;
    goto v0084;

v0399:
    v0364 = stack[-8];
    v0364 = qcdr(v0364);
    v0365 = qcar(v0364);
    v0364 = stack[-8];
    v0364 = qcar(v0364);
    v0364 = list2(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0400;

v0397:
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0398;

v0396:
    v0364 = stack[-8];
    v0365 = qcar(v0364);
    v0364 = elt(env, 33); /* !*!*un!*!* */
    if (v0365 == v0364) goto v0389;
    v0364 = stack[-5];
    v0364 = qcar(v0364);
    v0365 = qcdr(v0364);
    v0364 = stack[-8];
    v0364 = qcar(v0364);
    v0364 = list2(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[0] = v0364;
    goto v0401;

v0393:
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0394;

v0387:
    v0365 = stack[-3];
    v0364 = stack[-5];
    v0364 = qcar(v0364);
    v0364 = qcdr(v0364);
    if (v0365 == v0364) goto v0402;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0403;

v0403:
    if (v0364 == nil) goto v0404;
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0388;

v0404:
    v0364 = stack[-5];
    v0364 = qcar(v0364);
    v0365 = qcdr(v0364);
    v0364 = elt(env, 37); /* alt */
    v0364 = get(v0365, v0364);
    env = stack[-9];
    goto v0388;

v0402:
    v0365 = stack[-3];
    v0364 = elt(env, 35); /* nary */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    if (v0364 == nil) goto v0405;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0403;

v0405:
    v0365 = stack[-3];
    v0364 = elt(env, 36); /* right */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    v0364 = (v0364 == nil ? lisp_true : nil);
    goto v0403;

v0385:
    v0365 = stack[-4];
    v0364 = (Lisp_Object)1; /* 0 */
    if (v0365 == v0364) goto v0029;
    else goto v0389;

v0378:
    v0364 = stack[-8];
    if (v0364 == nil) goto v0406;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0407;

v0407:
    if (v0364 == nil) goto v0379;
    v0365 = qvalue(elt(env, 2)); /* nil */
    v0364 = stack[-1];
    {
        popv(10);
        fn = elt(env, 59); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v0365, v0364);
    }

v0406:
    v0364 = stack[-6];
    if (v0364 == nil) goto v0408;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0407;

v0408:
    v0364 = stack[-5];
    v0364 = (v0364 == nil ? lisp_true : nil);
    goto v0407;

v0376:
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0377;

v0371:
    v0365 = elt(env, 27); /* "Improper delimiter" */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0032;

v0374:
    v0365 = stack[-3];
    v0364 = elt(env, 54); /* (!*rsqbkt!* !*rcbkt!* !*rsqb!*) */
    v0364 = Lmemq(nil, v0365, v0364);
    v0364 = (v0364 == nil ? lisp_true : nil);
    goto v0375;

v0373:
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0375;

v0372:
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0375;

v0369:
    v0365 = stack[-7];
    v0364 = elt(env, 51); /* for */
    if (v0365 == v0364) goto v0409;
    v0364 = qvalue(elt(env, 52)); /* !*blockp */
    if (v0364 == nil) goto v0410;
    v0364 = stack[-6];
    if (v0364 == nil) goto v0411;
    v0364 = stack[-6];
    v0364 = qcar(v0364);
    if (!consp(v0364)) goto v0412;
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0370;

v0412:
    v0364 = stack[-6];
    v0364 = qcdr(v0364);
    goto v0370;

v0411:
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0370;

v0410:
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0370;

v0409:
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0370;

v0065:
    v0365 = stack[-3];
    v0364 = elt(env, 8); /* stat */
    v0364 = get(v0365, v0364);
    env = stack[-9];
    stack[-4] = v0364;
    if (v0364 == nil) goto v0112;
    v0365 = stack[-4];
    v0364 = elt(env, 43); /* endstat */
    if (v0365 == v0364) goto v0413;
    fn = elt(env, 57); /* eolcheck */
    v0364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0413;

v0413:
    v0365 = stack[-3];
    v0364 = elt(env, 44); /* go */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    if (v0364 == nil) goto v0414;
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0415;

v0415:
    if (v0364 == nil) goto v0016;
    v0365 = stack[-3];
    v0364 = elt(env, 48); /* procedure */
    if (v0365 == v0364) goto v0416;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0417;

v0417:
    if (v0364 == nil) goto v0418;
    v0364 = stack[-6];
    if (v0364 == nil) goto v0419;
    v0364 = stack[-6];
    v0364 = qcdr(v0364);
    if (!(v0364 == nil)) goto v0420;
    v0364 = qvalue(elt(env, 9)); /* !*reduce4 */
    if (!(v0364 == nil)) goto v0420;
    v0364 = stack[-6];
    v0364 = qcar(v0364);
    fn = elt(env, 62); /* procstat1 */
    v0364 = (*qfn1(fn))(qenv(fn), v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    v0364 = ncons(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-6] = v0364;
    goto v0421;

v0421:
    v0364 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0364;
    goto v0034;

v0420:
    v0365 = elt(env, 49); /* "proc form" */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0421;

v0419:
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 62); /* procstat1 */
    v0364 = (*qfn1(fn))(qenv(fn), v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    v0364 = ncons(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-6] = v0364;
    goto v0421;

v0418:
    v0365 = stack[-4];
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 63); /* lispapply */
    v0365 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    v0364 = stack[-6];
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-6] = v0364;
    goto v0421;

v0416:
    v0364 = qvalue(elt(env, 9)); /* !*reduce4 */
    goto v0417;

v0016:
    v0364 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0364;
    goto v0072;

v0072:
    v0365 = stack[-3];
    v0364 = stack[-6];
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-6] = v0364;
    v0364 = stack[-3];
    if (is_number(v0364)) goto v0422;
    v0365 = stack[-3];
    v0364 = elt(env, 12); /* !:dn!: */
    if (!consp(v0365)) goto v0423;
    v0365 = qcar(v0365);
    if (!(v0365 == v0364)) goto v0423;
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0424;

v0424:
    if (!(v0364 == nil)) goto v0422;

v0425:
    v0365 = stack[-7];
    v0364 = elt(env, 21); /* proc */
    if (v0365 == v0364) goto v0426;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0427;

v0427:
    if (v0364 == nil) goto v0019;
    v0365 = elt(env, 22); /* "Syntax error in procedure header" */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0019;

v0426:
    v0364 = stack[-6];
    v0365 = Llength(nil, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    v0364 = (Lisp_Object)33; /* 2 */
    v0364 = (Lisp_Object)greaterp2(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    v0364 = v0364 ? lisp_true : nil;
    env = stack[-9];
    goto v0427;

v0422:
    v0365 = stack[-2];
    v0364 = qvalue(elt(env, 15)); /* !$eol!$ */
    if (v0365 == v0364) goto v0428;
    v0364 = qvalue(elt(env, 16)); /* nxtsym!* */
    fn = elt(env, 64); /* chknewnam */
    v0364 = (*qfn1(fn))(qenv(fn), v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-2] = v0364;
    if (symbolp(v0364)) goto v0429;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0430;

v0430:
    if (v0364 == nil) goto v0425;
    v0364 = elt(env, 20); /* times */
    qvalue(elt(env, 3)) = v0364; /* cursym!* */
    goto v0034;

v0429:
    v0365 = stack[-2];
    v0364 = elt(env, 7); /* delim */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    if (v0364 == nil) goto v0431;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0430;

v0431:
    v0365 = stack[-2];
    v0364 = elt(env, 17); /* switch!* */
    v0364 = get(v0365, v0364);
    env = stack[-9];
    if (v0364 == nil) goto v0432;
    v0365 = stack[-2];
    v0364 = elt(env, 18); /* !( */
    if (v0365 == v0364) goto v0432;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0430;

v0432:
    v0365 = stack[-2];
    v0364 = elt(env, 6); /* infix */
    v0364 = get(v0365, v0364);
    env = stack[-9];
    if (v0364 == nil) goto v0433;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0430;

v0433:
    v0364 = qvalue(elt(env, 19)); /* !*eoldelimp */
    if (v0364 == nil) goto v0434;
    v0365 = stack[-2];
    v0364 = qvalue(elt(env, 15)); /* !$eol!$ */
    v0364 = (v0365 == v0364 ? lisp_true : nil);
    goto v0435;

v0435:
    v0364 = (v0364 == nil ? lisp_true : nil);
    goto v0430;

v0434:
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0435;

v0428:
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0430;

v0423:
    v0365 = stack[-3];
    v0364 = elt(env, 14); /* !:int!: */
    v0364 = Leqcar(nil, v0365, v0364);
    env = stack[-9];
    goto v0424;

v0414:
    v0365 = stack[-7];
    v0364 = elt(env, 21); /* proc */
    if (v0365 == v0364) goto v0436;
    v0365 = stack[-4];
    v0364 = elt(env, 45); /* endstatfn */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    if (v0364 == nil) goto v0437;
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0415;

v0437:
    v0365 = qvalue(elt(env, 16)); /* nxtsym!* */
    v0364 = elt(env, 46); /* delchar */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    if (v0364 == nil) goto v0438;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0415;

v0438:
    v0365 = qvalue(elt(env, 16)); /* nxtsym!* */
    v0364 = elt(env, 47); /* !, */
    v0364 = (v0365 == v0364 ? lisp_true : nil);
    v0364 = (v0364 == nil ? lisp_true : nil);
    goto v0415;

v0436:
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0415;

v0112:
    v0364 = qvalue(elt(env, 9)); /* !*reduce4 */
    if (v0364 == nil) goto v0439;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0083;

v0083:
    if (v0364 == nil) goto v0016;
    v0365 = elt(env, 11); /* decstat */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 63); /* lispapply */
    v0365 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    v0364 = stack[-6];
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-6] = v0364;
    goto v0034;

v0439:
    v0365 = stack[-3];
    v0364 = elt(env, 10); /* type */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    goto v0083;

v0020:
    fn = elt(env, 57); /* eolcheck */
    v0364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    v0365 = stack[-3];
    v0364 = elt(env, 25); /* !*comma!* */
    if (v0365 == v0364) goto v0440;
    fn = elt(env, 60); /* scan */
    v0364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-2] = v0364;
    if (!consp(v0364)) goto v0441;
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0442;

v0442:
    if (!(v0364 == nil)) goto v0022;
    v0365 = stack[-2];
    v0364 = elt(env, 5); /* !*rpar!* */
    if (v0365 == v0364) goto v0443;
    v0365 = stack[-2];
    v0364 = elt(env, 25); /* !*comma!* */
    if (v0365 == v0364) goto v0444;
    v0365 = stack[-2];
    v0364 = elt(env, 7); /* delim */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    goto v0445;

v0445:
    if (v0364 == nil) goto v0446;
    v0364 = stack[-4];
    if (v0364 == nil) goto v0447;
    v0364 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0364;
    goto v0447;

v0447:
    v0365 = stack[-3];
    v0364 = stack[-6];
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-6] = v0364;
    goto v0024;

v0446:
    v0365 = stack[-2];
    v0364 = elt(env, 4); /* !*lpar!* */
    if (v0365 == v0364) goto v0448;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0449;

v0449:
    if (!(v0364 == nil)) goto v0017;

v0022:
    v0364 = stack[-6];
    if (!(v0364 == nil)) goto v0030;
    v0365 = stack[-3];
    v0364 = elt(env, 31); /* unary */
    v0364 = get(v0365, v0364);
    env = stack[-9];
    stack[-3] = v0364;
    if (!(v0364 == nil)) goto v0450;
    v0365 = elt(env, 32); /* "Redundant operator" */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0450;

v0450:
    v0365 = elt(env, 33); /* !*!*un!*!* */
    v0364 = stack[-8];
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-8] = v0364;
    goto v0389;

v0448:
    fn = elt(env, 57); /* eolcheck */
    v0364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    if (v0364 == nil) goto v0451;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0449;

v0451:
    fn = elt(env, 60); /* scan */
    v0364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    v0364 = qvalue(elt(env, 19)); /* !*eoldelimp */
    if (v0364 == nil) goto v0452;
    v0365 = qvalue(elt(env, 3)); /* cursym!* */
    v0364 = elt(env, 30); /* !*semicol!* */
    if (v0365 == v0364) goto v0451;
    else goto v0452;

v0452:
    v0364 = elt(env, 24); /* paren */
    v0364 = CC_xread1(env, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-2] = v0364;
    if (!consp(v0364)) goto v0453;
    v0364 = stack[-2];
    v0365 = qcar(v0364);
    v0364 = elt(env, 25); /* !*comma!* */
    if (v0365 == v0364) goto v0454;
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0449;

v0454:
    v0365 = stack[-3];
    v0364 = stack[-2];
    v0364 = qcdr(v0364);
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-3] = v0364;
    goto v0449;

v0453:
    v0364 = qvalue(elt(env, 2)); /* nil */
    goto v0449;

v0444:
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0445;

v0443:
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0445;

v0441:
    v0364 = stack[-2];
    v0364 = (is_number(v0364) ? lisp_true : nil);
    if (!(v0364 == nil)) goto v0442;
    v0365 = stack[-2];
    v0364 = elt(env, 12); /* !:dn!: */
    if (!consp(v0365)) goto v0455;
    v0365 = qcar(v0365);
    if (!(v0365 == v0364)) goto v0455;
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0442;

v0455:
    v0365 = stack[-2];
    v0364 = elt(env, 14); /* !:int!: */
    v0364 = Leqcar(nil, v0365, v0364);
    env = stack[-9];
    goto v0442;

v0440:
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0442;

v0021:
    v0364 = stack[-7];
    if (v0364 == nil) goto v0456;
    v0365 = stack[-7];
    v0364 = elt(env, 28); /* group */
    if (v0365 == v0364) goto v0457;
    v0365 = stack[-7];
    v0364 = elt(env, 21); /* proc */
    v0364 = (v0365 == v0364 ? lisp_true : nil);
    goto v0458;

v0458:
    if (v0364 == nil) goto v0032;
    v0365 = elt(env, 29); /* "Too many right parentheses" */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0020;

v0457:
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0458;

v0456:
    v0364 = qvalue(elt(env, 13)); /* t */
    goto v0458;

v0008:
    fn = elt(env, 57); /* eolcheck */
    v0364 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    v0364 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0364;
    fn = elt(env, 60); /* scan */
    v0365 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    v0364 = elt(env, 5); /* !*rpar!* */
    if (v0365 == v0364) goto v0009;
    v0365 = stack[-6];
    v0364 = elt(env, 23); /* struct */
    v0364 = Lflagpcar(nil, v0365, v0364);
    env = stack[-9];
    if (v0364 == nil) goto v0459;
    v0364 = stack[-6];
    v0364 = qcar(v0364);
    v0364 = CC_xread1(env, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-3] = v0364;
    goto v0460;

v0460:
    v0365 = stack[-7];
    v0364 = elt(env, 23); /* struct */
    v0364 = Lflagp(nil, v0365, v0364);
    env = stack[-9];
    if (v0364 == nil) goto v0461;
    v0365 = stack[-3];
    v0364 = elt(env, 25); /* !*comma!* */
    if (!consp(v0365)) goto v0462;
    v0365 = qcar(v0365);
    if (!(v0365 == v0364)) goto v0462;
    v0364 = stack[-3];
    v0364 = qcdr(v0364);
    goto v0463;

v0463:
    stack[-3] = v0364;
    goto v0072;

v0462:
    v0364 = stack[-3];
    v0364 = ncons(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0463;

v0461:
    v0365 = stack[-3];
    v0364 = elt(env, 25); /* !*comma!* */
    if (!consp(v0365)) goto v0072;
    v0365 = qcar(v0365);
    if (!(v0365 == v0364)) goto v0072;
    v0364 = stack[-6];
    if (v0364 == nil) goto v0464;
    v0364 = stack[-6];
    v0366 = qcar(v0364);
    v0364 = stack[-3];
    v0365 = qcdr(v0364);
    v0364 = stack[-6];
    v0364 = qcdr(v0364);
    v0364 = acons(v0366, v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-6] = v0364;
    goto v0019;

v0464:
    v0365 = stack[-7];
    v0364 = elt(env, 26); /* lambda */
    if (v0365 == v0364) goto v0072;
    v0365 = elt(env, 27); /* "Improper delimiter" */
    v0364 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0364 = (*qfn2(fn))(qenv(fn), v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    goto v0019;

v0459:
    v0364 = elt(env, 24); /* paren */
    v0364 = CC_xread1(env, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-3] = v0364;
    goto v0460;

v0009:
    v0364 = stack[-6];
    if (v0364 == nil) goto v0019;
    v0364 = stack[-6];
    v0364 = qcar(v0364);
    v0365 = ncons(v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    v0364 = stack[-6];
    v0364 = qcdr(v0364);
    v0364 = cons(v0365, v0364);
    nil = C_nil;
    if (exception_pending()) goto v0368;
    env = stack[-9];
    stack[-6] = v0364;
    goto v0019;
/* error exit handlers */
v0368:
    popv(10);
    return nil;
}



/* Code for cl_fvarl1 */

static Lisp_Object CC_cl_fvarl1(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_fvarl1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0015;
/* end of prologue */
    fn = elt(env, 1); /* cl_varl1 */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    errexit();
    v0004 = qcar(v0004);
    return onevalue(v0004);
}



/* Code for numpoly_nullp */

static Lisp_Object CC_numpoly_nullp(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0021;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_nullp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0021 = v0015;
/* end of prologue */
    v0009 = v0021;
    if (v0009 == nil) goto v0005;
    v0009 = (Lisp_Object)1; /* 0 */
    v0009 = (v0021 == v0009 ? lisp_true : nil);
    return onevalue(v0009);

v0005:
    v0009 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0009);
}



/* Code for add_minus */

static Lisp_Object CC_add_minus(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0472, v0473;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_minus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0015;
/* end of prologue */
    v0472 = stack[-1];
    if (!consp(v0472)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0472 = stack[-1];
    v0473 = qcar(v0472);
    v0472 = elt(env, 1); /* !:rd!: */
    if (v0473 == v0472) goto v0014;
    v0472 = qvalue(elt(env, 2)); /* nil */
    goto v0017;

v0017:
    if (!(v0472 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0472 = stack[-1];
    v0473 = qcar(v0472);
    v0472 = elt(env, 1); /* !:rd!: */
    if (v0473 == v0472) goto v0125;
    v0472 = qvalue(elt(env, 2)); /* nil */
    goto v0028;

v0028:
    if (v0472 == nil) goto v0111;
    stack[-2] = elt(env, 3); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v0472 = stack[-1];
    v0472 = qcdr(v0472);
    v0472 = Labsval(nil, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-3];
    v0472 = cons(stack[0], v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    {
        Lisp_Object v0339 = stack[-2];
        popv(4);
        return list2(v0339, v0472);
    }

v0111:
    v0472 = stack[-1];
    v0473 = qcar(v0472);
    v0472 = elt(env, 3); /* minus */
    if (v0473 == v0472) goto v0068;
    v0472 = qvalue(elt(env, 2)); /* nil */
    goto v0079;

v0079:
    if (!(v0472 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0472 = stack[-1];
    v0473 = qcar(v0472);
    v0472 = elt(env, 3); /* minus */
    if (v0473 == v0472) goto v0475;
    v0472 = qvalue(elt(env, 2)); /* nil */
    goto v0476;

v0476:
    if (v0472 == nil) goto v0477;
    stack[0] = elt(env, 1); /* !:rd!: */
    v0472 = stack[-1];
    v0472 = qcdr(v0472);
    v0472 = qcar(v0472);
    v0472 = qcdr(v0472);
    v0472 = Labsval(nil, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    {
        Lisp_Object v0478 = stack[0];
        popv(4);
        return cons(v0478, v0472);
    }

v0477:
    v0472 = stack[-1];
    v0473 = qcar(v0472);
    v0472 = elt(env, 3); /* minus */
    if (v0473 == v0472) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0472 = stack[-1];
    v0473 = qcdr(v0472);
    v0472 = (Lisp_Object)1; /* 0 */
    v0472 = (Lisp_Object)lessp2(v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    v0472 = v0472 ? lisp_true : nil;
    env = stack[-3];
    if (v0472 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = elt(env, 3); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v0472 = stack[-1];
    v0472 = qcdr(v0472);
    v0472 = Labsval(nil, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    env = stack[-3];
    v0472 = cons(stack[0], v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    {
        Lisp_Object v0479 = stack[-2];
        popv(4);
        return list2(v0479, v0472);
    }

v0475:
    v0472 = stack[-1];
    v0472 = qcdr(v0472);
    v0472 = qcar(v0472);
    v0473 = qcdr(v0472);
    v0472 = (Lisp_Object)1; /* 0 */
    v0472 = (Lisp_Object)lessp2(v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    v0472 = v0472 ? lisp_true : nil;
    env = stack[-3];
    goto v0476;

v0068:
    v0472 = stack[-1];
    v0472 = qcdr(v0472);
    v0472 = qcar(v0472);
    v0472 = (is_number(v0472) ? lisp_true : nil);
    goto v0079;

v0125:
    v0472 = stack[-1];
    v0473 = qcdr(v0472);
    v0472 = (Lisp_Object)1; /* 0 */
    v0472 = (Lisp_Object)lessp2(v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    v0472 = v0472 ? lisp_true : nil;
    env = stack[-3];
    goto v0028;

v0014:
    v0472 = stack[-1];
    v0473 = qcdr(v0472);
    v0472 = (Lisp_Object)1; /* 0 */
    v0472 = (Lisp_Object)geq2(v0473, v0472);
    nil = C_nil;
    if (exception_pending()) goto v0474;
    v0472 = v0472 ? lisp_true : nil;
    env = stack[-3];
    goto v0017;
/* error exit handlers */
v0474:
    popv(4);
    return nil;
}



/* Code for termordp!! */

static Lisp_Object CC_termordpB(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0044, v0045;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termordp!");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    v0045 = v0015;
/* end of prologue */
    v0044 = v0045;
    v0084 = stack[0];
    if (equal(v0044, v0084)) goto v0030;
    v0084 = v0045;
    fn = elt(env, 2); /* guesspftype */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    v0084 = stack[0];
    fn = elt(env, 2); /* guesspftype */
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    {
        Lisp_Object v0029 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* termordp */
        return (*qfn2(fn))(qenv(fn), v0029, v0084);
    }

v0030:
    v0084 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0084); }
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for revalind */

static Lisp_Object CC_revalind(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0085, v0118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revalind");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0015;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v0053 = qvalue(elt(env, 2)); /* nil */
    v0053 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0053; /* alglist!* */
    v0053 = qvalue(elt(env, 3)); /* subfg!* */
    stack[-2] = v0053;
    v0053 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v0053; /* subfg!* */
    v0118 = elt(env, 4); /* !0 */
    v0085 = (Lisp_Object)1; /* 0 */
    v0053 = stack[-1];
    v0053 = Lsubst(nil, 3, v0118, v0085, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    stack[-1] = v0053;
    v0053 = stack[-1];
    fn = elt(env, 6); /* simp */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    v0085 = v0053;
    v0053 = v0085;
    v0053 = qcar(v0053);
    if (v0053 == nil) goto v0084;
    v0053 = elt(env, 5); /* prepf */
    fn = elt(env, 7); /* sqform */
    v0053 = (*qfn2(fn))(qenv(fn), v0085, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    goto v0078;

v0078:
    v0085 = v0053;
    v0053 = stack[-2];
    qvalue(elt(env, 3)) = v0053; /* subfg!* */
    v0053 = v0085;
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    { popv(4); return onevalue(v0053); }

v0084:
    v0053 = (Lisp_Object)1; /* 0 */
    goto v0078;
/* error exit handlers */
v0121:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for assert_install */

static Lisp_Object CC_assert_install(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_install");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0078 = v0015;
/* end of prologue */
    v0014 = qvalue(elt(env, 1)); /* !*assert */
    if (v0014 == nil) goto v0004;
    v0014 = v0078;
    stack[0] = v0014;
    goto v0035;

v0035:
    v0014 = stack[0];
    if (v0014 == nil) goto v0016;
    v0014 = stack[0];
    v0014 = qcar(v0014);
    fn = elt(env, 3); /* assert_install1 */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    stack[0] = v0014;
    goto v0035;

v0016:
    v0014 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0014); }

v0004:
    v0014 = nil;
    { popv(2); return onevalue(v0014); }
/* error exit handlers */
v0044:
    popv(2);
    return nil;
}



/* Code for getmatelem */

static Lisp_Object CC_getmatelem(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0488, v0489, v0490;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getmatelem");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0015;
/* end of prologue */

v0035:
    v0488 = stack[-1];
    v0489 = Llength(nil, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    v0488 = (Lisp_Object)49; /* 3 */
    if (v0489 == v0488) goto v0084;
    v0489 = stack[-1];
    v0488 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 12); /* typerr */
    v0488 = (*qfn2(fn))(qenv(fn), v0489, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    goto v0084;

v0084:
    v0488 = stack[-1];
    v0489 = qcar(v0488);
    v0488 = elt(env, 2); /* avalue */
    v0488 = get(v0489, v0488);
    env = stack[-3];
    stack[-2] = v0488;
    v0488 = stack[-2];
    if (v0488 == nil) goto v0052;
    v0488 = stack[-2];
    v0489 = qcar(v0488);
    v0488 = elt(env, 4); /* matrix */
    v0488 = (v0489 == v0488 ? lisp_true : nil);
    v0488 = (v0488 == nil ? lisp_true : nil);
    goto v0028;

v0028:
    if (v0488 == nil) goto v0075;
    v0488 = stack[-1];
    v0489 = qcar(v0488);
    v0488 = elt(env, 5); /* "matrix" */
    fn = elt(env, 12); /* typerr */
    v0488 = (*qfn2(fn))(qenv(fn), v0489, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    goto v0007;

v0007:
    v0488 = stack[-1];
    v0488 = qcdr(v0488);
    v0488 = qcar(v0488);
    fn = elt(env, 13); /* reval_without_mod */
    v0488 = (*qfn1(fn))(qenv(fn), v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    stack[0] = v0488;
    v0488 = stack[0];
    v0488 = integerp(v0488);
    if (v0488 == nil) goto v0056;
    v0489 = stack[0];
    v0488 = (Lisp_Object)1; /* 0 */
    v0488 = (Lisp_Object)lesseq2(v0489, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    v0488 = v0488 ? lisp_true : nil;
    env = stack[-3];
    goto v0060;

v0060:
    if (v0488 == nil) goto v0492;
    v0489 = stack[0];
    v0488 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v0488 = (*qfn2(fn))(qenv(fn), v0489, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    goto v0492;

v0492:
    v0488 = stack[-2];
    v0489 = qcdr(v0488);
    v0488 = stack[0];
    fn = elt(env, 14); /* pnth */
    v0488 = (*qfn2(fn))(qenv(fn), v0489, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    v0488 = qcar(v0488);
    stack[-2] = v0488;
    v0488 = stack[-1];
    v0488 = qcdr(v0488);
    v0488 = qcdr(v0488);
    v0488 = qcar(v0488);
    fn = elt(env, 13); /* reval_without_mod */
    v0488 = (*qfn1(fn))(qenv(fn), v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    stack[0] = v0488;
    v0488 = stack[0];
    v0488 = integerp(v0488);
    if (v0488 == nil) goto v0493;
    v0489 = stack[0];
    v0488 = (Lisp_Object)1; /* 0 */
    v0488 = (Lisp_Object)lesseq2(v0489, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    v0488 = v0488 ? lisp_true : nil;
    env = stack[-3];
    goto v0494;

v0494:
    if (v0488 == nil) goto v0495;
    v0489 = stack[0];
    v0488 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v0488 = (*qfn2(fn))(qenv(fn), v0489, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    goto v0495;

v0495:
    v0489 = stack[-2];
    v0488 = stack[0];
    fn = elt(env, 14); /* pnth */
    v0488 = (*qfn2(fn))(qenv(fn), v0489, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    v0488 = qcar(v0488);
    { popv(4); return onevalue(v0488); }

v0493:
    v0488 = qvalue(elt(env, 3)); /* t */
    goto v0494;

v0056:
    v0488 = qvalue(elt(env, 3)); /* t */
    goto v0060;

v0075:
    v0488 = stack[-2];
    v0488 = qcdr(v0488);
    v0489 = qcar(v0488);
    stack[-2] = v0489;
    v0488 = elt(env, 6); /* mat */
    if (!consp(v0489)) goto v0037;
    v0489 = qcar(v0489);
    if (v0489 == v0488) goto v0007;
    else goto v0037;

v0037:
    v0488 = stack[-2];
    if (symbolp(v0488)) goto v0362;
    v0490 = elt(env, 7); /* "Matrix" */
    v0488 = stack[-1];
    v0489 = qcar(v0488);
    v0488 = elt(env, 8); /* "not set" */
    v0488 = list3(v0490, v0489, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    v0489 = v0488;
    v0488 = v0489;
    qvalue(elt(env, 9)) = v0488; /* errmsg!* */
    v0488 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v0488 == nil)) goto v0063;
    v0488 = v0489;
    fn = elt(env, 15); /* lprie */
    v0488 = (*qfn1(fn))(qenv(fn), v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    goto v0063;

v0063:
    v0488 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    goto v0007;

v0362:
    v0489 = stack[-2];
    v0488 = stack[-1];
    v0488 = qcdr(v0488);
    v0488 = cons(v0489, v0488);
    nil = C_nil;
    if (exception_pending()) goto v0491;
    env = stack[-3];
    stack[-1] = v0488;
    goto v0035;

v0052:
    v0488 = qvalue(elt(env, 3)); /* t */
    goto v0028;
/* error exit handlers */
v0491:
    popv(4);
    return nil;
}



/* Code for b!:extadd */

static Lisp_Object CC_bTextadd(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0498, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:extadd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
    stack[-2] = v0015;
/* end of prologue */
    stack[0] = nil;
    goto v0076;

v0076:
    v0114 = stack[-2];
    if (v0114 == nil) goto v0017;
    v0114 = stack[-1];
    if (v0114 == nil) goto v0030;
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0498 = qcar(v0114);
    v0114 = stack[-1];
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    if (equal(v0498, v0114)) goto v0085;
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0498 = qcar(v0114);
    v0114 = stack[-1];
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    fn = elt(env, 1); /* b!:ordexp */
    v0114 = (*qfn2(fn))(qenv(fn), v0498, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-4];
    if (v0114 == nil) goto v0059;
    v0114 = stack[-2];
    v0498 = qcar(v0114);
    v0114 = stack[0];
    v0114 = cons(v0498, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-4];
    stack[0] = v0114;
    v0114 = stack[-2];
    v0114 = qcdr(v0114);
    stack[-2] = v0114;
    goto v0076;

v0059:
    v0114 = stack[-1];
    v0498 = qcar(v0114);
    v0114 = stack[0];
    v0114 = cons(v0498, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-4];
    stack[0] = v0114;
    v0114 = stack[-1];
    v0114 = qcdr(v0114);
    stack[-1] = v0114;
    goto v0076;

v0085:
    stack[-3] = stack[0];
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0498 = qcdr(v0114);
    v0114 = stack[-1];
    v0114 = qcar(v0114);
    v0114 = qcdr(v0114);
    fn = elt(env, 2); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0498, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-4];
    v0114 = stack[-2];
    v0498 = qcdr(v0114);
    v0114 = stack[-1];
    v0114 = qcdr(v0114);
    v0114 = CC_bTextadd(env, v0498, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-4];
    v0498 = stack[0];
    v0115 = v0498;
    if (v0115 == nil) goto v0122;
    v0115 = stack[-2];
    v0115 = qcar(v0115);
    v0115 = qcar(v0115);
    v0114 = acons(v0115, v0498, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-4];
    goto v0122;

v0122:
    {
        Lisp_Object v0088 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0088, v0114);
    }

v0030:
    v0498 = stack[0];
    v0114 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0498, v0114);
    }

v0017:
    v0498 = stack[0];
    v0114 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0498, v0114);
    }
/* error exit handlers */
v0087:
    popv(5);
    return nil;
}



/* Code for defineargs */

static Lisp_Object CC_defineargs(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0047, v0048, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for defineargs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0015;
/* end of prologue */
    v0047 = stack[-1];
    v0039 = elt(env, 1); /* number!-of!-args */
    v0039 = get(v0047, v0039);
    env = stack[-2];
    v0047 = v0039;
    v0039 = v0047;
    if (v0039 == nil) goto v0022;
    v0048 = stack[0];
    v0039 = v0047;
    if (equal(v0048, v0039)) goto v0077;
    v0048 = stack[-1];
    v0039 = elt(env, 3); /* calledby */
    v0048 = get(v0048, v0039);
    env = stack[-2];
    v0039 = v0048;
    if (v0048 == nil) goto v0100;
    v0070 = stack[-1];
    v0048 = stack[0];
    fn = elt(env, 4); /* instdof */
    v0039 = (*qfnn(fn))(qenv(fn), 4, v0070, v0048, v0047, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    goto v0100;

v0100:
    v0047 = stack[-1];
    v0039 = stack[0];
    fn = elt(env, 5); /* hasarg */
    v0039 = (*qfn2(fn))(qenv(fn), v0047, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    v0039 = nil;
    { popv(3); return onevalue(v0039); }

v0077:
    v0039 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0039); }

v0022:
    v0047 = stack[-1];
    v0039 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* hasarg */
        return (*qfn2(fn))(qenv(fn), v0047, v0039);
    }
/* error exit handlers */
v0050:
    popv(3);
    return nil;
}



/* Code for split_ext */

static Lisp_Object CC_split_ext(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0062, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_ext");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0062 = v0003;
    v0058 = v0015;
/* end of prologue */
    v0061 = v0058;
    v0061 = qcdr(v0061);
    stack[-7] = v0061;
    v0061 = v0058;
    v0061 = qcar(v0061);
    fn = elt(env, 3); /* split_form */
    v0061 = (*qfn2(fn))(qenv(fn), v0061, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    stack[0] = v0061;
    v0061 = elt(env, 1); /* ext */
    stack[-6] = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    v0061 = stack[0];
    v0062 = qcar(v0061);
    v0061 = stack[-7];
    v0061 = cons(v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    stack[-5] = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    v0061 = stack[0];
    v0061 = qcdr(v0061);
    stack[-4] = v0061;
    v0061 = stack[-4];
    if (v0061 == nil) goto v0122;
    v0061 = stack[-4];
    v0061 = qcar(v0061);
    v0062 = v0061;
    v0061 = v0062;
    stack[0] = qcar(v0061);
    v0061 = v0062;
    v0062 = qcdr(v0061);
    v0061 = stack[-7];
    v0061 = cons(v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    v0061 = cons(stack[0], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    stack[-2] = v0061;
    stack[-3] = v0061;
    goto v0043;

v0043:
    v0061 = stack[-4];
    v0061 = qcdr(v0061);
    stack[-4] = v0061;
    v0061 = stack[-4];
    if (v0061 == nil) goto v0067;
    stack[-1] = stack[-2];
    v0061 = stack[-4];
    v0061 = qcar(v0061);
    v0062 = v0061;
    v0061 = v0062;
    stack[0] = qcar(v0061);
    v0061 = v0062;
    v0062 = qcdr(v0061);
    v0061 = stack[-7];
    v0061 = cons(v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    v0061 = cons(stack[0], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    v0061 = Lrplacd(nil, stack[-1], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-8];
    v0061 = stack[-2];
    v0061 = qcdr(v0061);
    stack[-2] = v0061;
    goto v0043;

v0067:
    v0061 = stack[-3];
    goto v0030;

v0030:
    {
        Lisp_Object v0470 = stack[-6];
        Lisp_Object v0358 = stack[-5];
        popv(9);
        return acons(v0470, v0358, v0061);
    }

v0122:
    v0061 = qvalue(elt(env, 2)); /* nil */
    goto v0030;
/* error exit handlers */
v0059:
    popv(9);
    return nil;
}



/* Code for rl_prepfof */

static Lisp_Object CC_rl_prepfof(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_prepfof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0004 = v0015;
/* end of prologue */
    fn = elt(env, 1); /* rl_csimpl */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* rl_prepfof1 */
        return (*qfn1(fn))(qenv(fn), v0004);
    }
/* error exit handlers */
v0076:
    popv(1);
    return nil;
}



/* Code for get_rep_matrix_in */

static Lisp_Object CC_get_rep_matrix_in(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_rep_matrix_in");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0015,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0070 = v0003;
    stack[-2] = v0015;
/* end of prologue */
    stack[-1] = nil;
    v0048 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0048;
    v0048 = v0070;
    v0048 = qcdr(v0048);
    stack[0] = v0048;
    goto v0017;

v0017:
    v0048 = stack[-3];
    if (v0048 == nil) goto v0030;
    v0048 = qvalue(elt(env, 1)); /* nil */
    goto v0021;

v0021:
    if (v0048 == nil) goto v0034;
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0070 = qcar(v0048);
    v0048 = stack[-2];
    if (!(equal(v0070, v0048))) goto v0026;
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0048 = qcdr(v0048);
    v0048 = qcar(v0048);
    stack[-1] = v0048;
    v0048 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v0048;
    goto v0026;

v0026:
    v0048 = stack[0];
    v0048 = qcdr(v0048);
    stack[0] = v0048;
    goto v0017;

v0034:
    v0048 = stack[-3];
    if (!(v0048 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0048 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0048 == nil)) goto v0075;
    v0048 = elt(env, 4); /* "error in get representation matrix" */
    fn = elt(env, 5); /* lprie */
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-4];
    goto v0075;

v0075:
    v0048 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    v0048 = nil;
    { popv(5); return onevalue(v0048); }

v0030:
    v0048 = stack[0];
    v0070 = Llength(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-4];
    v0048 = (Lisp_Object)1; /* 0 */
    v0048 = (Lisp_Object)greaterp2(v0070, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    v0048 = v0048 ? lisp_true : nil;
    env = stack[-4];
    goto v0021;
/* error exit handlers */
v0120:
    popv(5);
    return nil;
}



/* Code for cgb_buch!-ev_divides!? */

static Lisp_Object CC_cgb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0015, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgb_buch-ev_divides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0034 = v0003;
    v0033 = v0015;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v0034, v0033);
    }
}



/* Code for constsml */

static Lisp_Object CC_constsml(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0362;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constsml");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
/* end of prologue */
    v0068 = stack[0];
    if (!(is_number(v0068))) goto v0004;
    v0068 = elt(env, 1); /* "<cn" */
    fn = elt(env, 13); /* printout */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    v0068 = stack[0];
    v0068 = Lfloatp(nil, v0068);
    env = stack[-1];
    if (v0068 == nil) goto v0016;
    v0068 = elt(env, 2); /* " type=""real""> " */
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    goto v0034;

v0034:
    v0068 = stack[0];
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    v0068 = elt(env, 5); /* " </cn>" */
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    goto v0004;

v0004:
    v0068 = stack[0];
    if (!(symbolp(v0068))) goto v0025;
    v0068 = stack[0];
    v0362 = Lintern(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    v0068 = qvalue(elt(env, 6)); /* constants!* */
    v0068 = Lmember(nil, v0362, v0068);
    if (v0068 == nil) goto v0011;
    v0068 = elt(env, 7); /* "<cn type=""constant""> " */
    fn = elt(env, 13); /* printout */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    v0068 = stack[0];
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    v0068 = elt(env, 5); /* " </cn>" */
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    goto v0025;

v0025:
    v0068 = nil;
    { popv(2); return onevalue(v0068); }

v0011:
    v0068 = elt(env, 8); /* "<ci" */
    fn = elt(env, 13); /* printout */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    v0068 = stack[0];
    fn = elt(env, 14); /* listp */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    if (v0068 == nil) goto v0040;
    v0068 = elt(env, 9); /* " type=""list""> " */
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    goto v0064;

v0064:
    v0068 = stack[0];
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    v0068 = elt(env, 11); /* " </ci>" */
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    goto v0025;

v0040:
    v0068 = stack[0];
    v0068 = Lsimple_vectorp(nil, v0068);
    env = stack[-1];
    if (v0068 == nil) goto v0047;
    v0068 = elt(env, 10); /* " type=""vector""> " */
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    goto v0064;

v0047:
    v0068 = elt(env, 4); /* "> " */
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    goto v0064;

v0016:
    v0068 = stack[0];
    v0068 = integerp(v0068);
    if (v0068 == nil) goto v0014;
    v0068 = elt(env, 3); /* " type=""integer""> " */
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    goto v0034;

v0014:
    v0068 = elt(env, 4); /* "> " */
    v0068 = Lprinc(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    goto v0034;
/* error exit handlers */
v0112:
    popv(2);
    return nil;
}



/* Code for simprecip */

static Lisp_Object CC_simprecip(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simprecip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0007 = v0015;
/* end of prologue */
    v0006 = qvalue(elt(env, 1)); /* !*mcd */
    if (v0006 == nil) goto v0008;
    v0006 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v0006 = (*qfn2(fn))(qenv(fn), v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[0];
    fn = elt(env, 4); /* simp */
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* invsq */
        return (*qfn1(fn))(qenv(fn), v0006);
    }

v0008:
    v0006 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v0007 = (*qfn2(fn))(qenv(fn), v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[0];
    v0006 = (Lisp_Object)-15; /* -1 */
    v0006 = list2(v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v0006);
    }
/* error exit handlers */
v0026:
    popv(1);
    return nil;
}



/* Code for inshisto */

static Lisp_Object CC_inshisto(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0502, v0503, v0105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inshisto");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0015;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0503 = qvalue(elt(env, 2)); /* maxvar */
    v0502 = stack[-3];
    v0502 = plus2(v0503, v0502);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-5];
    v0503 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0502/(16/CELL)));
    v0502 = (Lisp_Object)1; /* 0 */
    v0502 = *(Lisp_Object *)((char *)v0503 + (CELL-TAG_VECTOR) + ((int32_t)v0502/(16/CELL)));
    if (v0502 == nil) goto v0004;
    v0503 = stack[-3];
    v0502 = (Lisp_Object)1; /* 0 */
    v0502 = (Lisp_Object)geq2(v0503, v0502);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    v0502 = v0502 ? lisp_true : nil;
    env = stack[-5];
    if (v0502 == nil) goto v0004;
    stack[0] = qvalue(elt(env, 3)); /* codhisto */
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0503 = qvalue(elt(env, 2)); /* maxvar */
    v0502 = stack[-3];
    v0502 = plus2(v0503, v0502);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-5];
    v0503 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0502/(16/CELL)));
    v0502 = (Lisp_Object)17; /* 1 */
    v0502 = *(Lisp_Object *)((char *)v0503 + (CELL-TAG_VECTOR) + ((int32_t)v0502/(16/CELL)));
    v0503 = qcdr(v0502);
    v0502 = (Lisp_Object)3201; /* 200 */
    fn = elt(env, 6); /* min */
    v0502 = (*qfn2(fn))(qenv(fn), v0503, v0502);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-5];
    stack[-2] = v0502;
    v0502 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0502/(16/CELL)));
    stack[-4] = v0502;
    if (v0502 == nil) goto v0058;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0503 = qvalue(elt(env, 2)); /* maxvar */
    v0502 = stack[-4];
    v0502 = plus2(v0503, v0502);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-5];
    v0503 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0502/(16/CELL)));
    v0502 = (Lisp_Object)113; /* 7 */
    v0503 = *(Lisp_Object *)((char *)v0503 + (CELL-TAG_VECTOR) + ((int32_t)v0502/(16/CELL)));
    v0502 = stack[-3];
    v0502 = Lrplaca(nil, v0503, v0502);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-5];
    goto v0071;

v0071:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0503 = qvalue(elt(env, 2)); /* maxvar */
    v0502 = stack[-3];
    v0502 = plus2(v0503, v0502);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-5];
    stack[-1] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0502/(16/CELL)));
    stack[0] = (Lisp_Object)113; /* 7 */
    v0503 = qvalue(elt(env, 5)); /* nil */
    v0502 = stack[-4];
    v0502 = cons(v0503, v0502);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-5];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0502;
    v0105 = qvalue(elt(env, 3)); /* codhisto */
    v0503 = stack[-2];
    v0502 = stack[-3];
    *(Lisp_Object *)((char *)v0105 + (CELL-TAG_VECTOR) + ((int32_t)v0503/(16/CELL))) = v0502;
    v0502 = nil;
    { popv(6); return onevalue(v0502); }

v0058:
    v0503 = stack[-2];
    v0502 = qvalue(elt(env, 4)); /* headhisto */
    v0502 = (Lisp_Object)greaterp2(v0503, v0502);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    v0502 = v0502 ? lisp_true : nil;
    env = stack[-5];
    if (v0502 == nil) goto v0071;
    v0502 = stack[-2];
    qvalue(elt(env, 4)) = v0502; /* headhisto */
    goto v0071;

v0004:
    v0502 = nil;
    { popv(6); return onevalue(v0502); }
/* error exit handlers */
v0494:
    popv(6);
    return nil;
}



/* Code for list!-mgen */

static Lisp_Object CC_listKmgen(Lisp_Object env,
                         Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list-mgen");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0015);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0028 = v0015;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = nil; /* i */
    v0042 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0042; /* i */
    v0042 = v0028;
    stack[0] = v0042;
    goto v0036;

v0036:
    v0042 = stack[0];
    if (v0042 == nil) goto v0049;
    v0042 = stack[0];
    v0042 = qcar(v0042);
    v0028 = v0042;
    v0042 = v0028;
    if (!consp(v0042)) goto v0078;
    v0042 = qvalue(elt(env, 2)); /* nil */
    goto v0014;

v0014:
    if (v0042 == nil) goto v0022;
    v0042 = qvalue(elt(env, 1)); /* i */
    v0042 = add1(v0042);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0042; /* i */
    goto v0022;

v0022:
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    stack[0] = v0042;
    goto v0036;

v0078:
    v0042 = v0028;
    fn = elt(env, 3); /* mgenp */
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    goto v0014;

v0049:
    v0042 = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    { popv(3); return onevalue(v0042); }
/* error exit handlers */
v0043:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    popv(3);
    return nil;
}



setup_type const u13_setup[] =
{
    {"cird",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cird},
    {"floatprop",               CC_floatprop,   too_many_1,    wrong_no_1},
    {"bcplus?",                 CC_bcplusW,     too_many_1,    wrong_no_1},
    {"one-entry-listp",         too_few_2,      CC_oneKentryKlistp,wrong_no_2},
    {"eqdummy",                 too_few_2,      CC_eqdummy,    wrong_no_2},
    {"numlist_ordp",            too_few_2,      CC_numlist_ordp,wrong_no_2},
    {"lambda_mcd3pw_2",         too_few_2,      CC_lambda_mcd3pw_2,wrong_no_2},
    {"degree-in-variable",      too_few_2,      CC_degreeKinKvariable,wrong_no_2},
    {"setunion",                too_few_2,      CC_setunion,   wrong_no_2},
    {"ofsf_subf",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_subf},
    {"get_group_in",            CC_get_group_in,too_many_1,    wrong_no_1},
    {"qqe_number-of-adds-in-qterm",CC_qqe_numberKofKaddsKinKqterm,too_many_1,wrong_no_1},
    {"ibalp_lenisone",          CC_ibalp_lenisone,too_many_1,  wrong_no_1},
    {"terpri*",                 CC_terpriH,     too_many_1,    wrong_no_1},
    {"cr:prep",                 CC_crTprep,     too_many_1,    wrong_no_1},
    {"initwght",                CC_initwght,    too_many_1,    wrong_no_1},
    {"vevmaptozero1",           too_few_2,      CC_vevmaptozero1,wrong_no_2},
    {"lid",                     CC_lid,         too_many_1,    wrong_no_1},
    {"physopaeval",             CC_physopaeval, too_many_1,    wrong_no_1},
    {"all_defined_vertex",      too_few_2,      CC_all_defined_vertex,wrong_no_2},
    {"assert_uninstall_all",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_uninstall_all},
    {"mo=revlexcomp",           too_few_2,      CC_moMrevlexcomp,wrong_no_2},
    {"dv_cambhead",             CC_dv_cambhead, too_many_1,    wrong_no_1},
    {"expt-mod-p",              too_few_2,      CC_exptKmodKp, wrong_no_2},
    {"freeofl",                 too_few_2,      CC_freeofl,    wrong_no_2},
    {"mapins",                  too_few_2,      CC_mapins,     wrong_no_2},
    {"qqe_simplat1",            too_few_2,      CC_qqe_simplat1,wrong_no_2},
    {"rl_negateat",             CC_rl_negateat, too_many_1,    wrong_no_1},
    {"ibalp_hassimple",         CC_ibalp_hassimple,too_many_1, wrong_no_1},
    {"aex_simplenullp",         CC_aex_simplenullp,too_many_1, wrong_no_1},
    {"variablesir",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_variablesir},
    {"evenfree",                CC_evenfree,    too_many_1,    wrong_no_1},
    {"invp",                    CC_invp,        too_many_1,    wrong_no_1},
    {"mkarray1",                too_few_2,      CC_mkarray1,   wrong_no_2},
    {":divide",                 too_few_2,      CC_Tdivide,    wrong_no_2},
    {"gperm0",                  CC_gperm0,      too_many_1,    wrong_no_1},
    {"primep",                  CC_primep,      too_many_1,    wrong_no_1},
    {"xread1",                  CC_xread1,      too_many_1,    wrong_no_1},
    {"cl_fvarl1",               CC_cl_fvarl1,   too_many_1,    wrong_no_1},
    {"numpoly_nullp",           CC_numpoly_nullp,too_many_1,   wrong_no_1},
    {"add_minus",               CC_add_minus,   too_many_1,    wrong_no_1},
    {"termordp!",               too_few_2,      CC_termordpB,  wrong_no_2},
    {"revalind",                CC_revalind,    too_many_1,    wrong_no_1},
    {"assert_install",          CC_assert_install,too_many_1,  wrong_no_1},
    {"getmatelem",              CC_getmatelem,  too_many_1,    wrong_no_1},
    {"b:extadd",                too_few_2,      CC_bTextadd,   wrong_no_2},
    {"defineargs",              too_few_2,      CC_defineargs, wrong_no_2},
    {"split_ext",               too_few_2,      CC_split_ext,  wrong_no_2},
    {"rl_prepfof",              CC_rl_prepfof,  too_many_1,    wrong_no_1},
    {"get_rep_matrix_in",       too_few_2,      CC_get_rep_matrix_in,wrong_no_2},
    {"cgb_buch-ev_divides?",    too_few_2,      CC_cgb_buchKev_dividesW,wrong_no_2},
    {"constsml",                CC_constsml,    too_many_1,    wrong_no_1},
    {"simprecip",               CC_simprecip,   too_many_1,    wrong_no_1},
    {"inshisto",                CC_inshisto,    too_many_1,    wrong_no_1},
    {"list-mgen",               CC_listKmgen,   too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u13", (two_args *)"20125 7832188 4515201", 0}
};

/* end of generated code */
