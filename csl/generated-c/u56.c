
/* $destdir\u56.c        Machine generated C code */

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


/* Code for intargfn */

static Lisp_Object MS_CDECL CC_intargfn(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "intargfn");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intargfn");
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
    v20 = stack[-3];
    v20 = qcdr(v20);
    stack[0] = v20;
    goto v24;

v24:
    v20 = stack[0];
    if (v20 == nil) goto v25;
    v20 = stack[0];
    v22 = qcar(v20);
    v21 = stack[-2];
    v20 = stack[-1];
    fn = elt(env, 4); /* form1 */
    v23 = (*qfnn(fn))(qenv(fn), 3, v22, v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    v22 = stack[-2];
    v21 = elt(env, 1); /* integer */
    v20 = stack[-1];
    fn = elt(env, 5); /* convertmode1 */
    v21 = (*qfnn(fn))(qenv(fn), 4, v23, v22, v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    v20 = stack[-4];
    v20 = cons(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    stack[-4] = v20;
    v20 = stack[0];
    v20 = qcdr(v20);
    stack[0] = v20;
    goto v24;

v25:
    stack[0] = elt(env, 2); /* list */
    v20 = stack[-3];
    v22 = qcar(v20);
    v21 = stack[-2];
    v20 = elt(env, 3); /* algebraic */
    fn = elt(env, 4); /* form1 */
    v21 = (*qfnn(fn))(qenv(fn), 3, v22, v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    v20 = stack[-4];
    v20 = Lnreverse(nil, v20);
    {
        Lisp_Object v27 = stack[0];
        popv(6);
        return list2star(v27, v21, v20);
    }
/* error exit handlers */
v26:
    popv(6);
    return nil;
}



/* Code for simpfourier1 */

static Lisp_Object CC_simpfourier1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpfourier1");
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
    v39 = stack[0];
    if (!consp(v39)) goto v41;
    v40 = stack[0];
    v39 = elt(env, 5); /* !:fs!: */
    if (!consp(v40)) goto v42;
    v40 = qcar(v40);
    if (v40 == v39) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else goto v42;

v42:
    v39 = stack[0];
    v40 = qcar(v39);
    v39 = elt(env, 6); /* simpfour */
    v39 = get(v40, v39);
    env = stack[-1];
    v40 = v39;
    if (v39 == nil) goto v21;
    v39 = stack[0];
    v39 = qcdr(v39);
        popv(2);
        return Lapply1(nil, v40, v39);

v21:
    v40 = elt(env, 7); /* "Unknown function" */
    v39 = stack[0];
    v39 = qcar(v39);
    v39 = cons(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    v40 = v39;
    v39 = v40;
    qvalue(elt(env, 2)) = v39; /* errmsg!* */
    v39 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v39 == nil)) goto v44;
    v39 = v40;
    fn = elt(env, 8); /* lprie */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    goto v44;

v44:
    v39 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    v39 = stack[0];
    fn = elt(env, 9); /* !*sq2fourier */
    v40 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v39 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v40, v39);

v41:
    v39 = stack[0];
    fn = elt(env, 10); /* harmonicp */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    if (v39 == nil) goto v45;
    v39 = elt(env, 1); /* "Secular angle not allowed" */
    v40 = v39;
    v39 = v40;
    qvalue(elt(env, 2)) = v39; /* errmsg!* */
    v39 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v39 == nil)) goto v10;
    v39 = v40;
    fn = elt(env, 8); /* lprie */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    goto v10;

v10:
    v39 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    goto v45;

v45:
    v39 = stack[0];
    fn = elt(env, 11); /* simp */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    fn = elt(env, 9); /* !*sq2fourier */
    v40 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v39 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v40, v39);
/* error exit handlers */
v43:
    popv(2);
    return nil;
}



/* Code for dp_from_a */

static Lisp_Object CC_dp_from_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_from_a");
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
    stack[0] = v0;
/* end of prologue */
    v65 = stack[0];
    v64 = elt(env, 1); /* list */
    if (!consp(v65)) goto v10;
    v65 = qcar(v65);
    if (!(v65 == v64)) goto v10;
    v64 = qvalue(elt(env, 2)); /* t */
    goto v41;

v41:
    if (v64 == nil) goto v19;
    v65 = stack[0];
    v64 = elt(env, 4); /* "dpoly" */
    {
        popv(6);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v65, v64);
    }

v19:
    v64 = stack[0];
    if (!consp(v64)) goto v67;
    v64 = stack[0];
    v64 = qcar(v64);
    if (!consp(v64)) goto v25;
    v64 = qvalue(elt(env, 2)); /* t */
    goto v12;

v12:
    if (v64 == nil) goto v7;
    v64 = stack[0];
    v65 = qcar(v64);
    v64 = elt(env, 5); /* "dpoly operator" */
    {
        popv(6);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v65, v64);
    }

v7:
    v64 = stack[0];
    v65 = qcar(v64);
    v64 = elt(env, 6); /* dp!=fn */
    v64 = get(v65, v64);
    env = stack[-5];
    v66 = v64;
    v65 = v66;
    v64 = elt(env, 7); /* dp!=fnpow */
    if (v65 == v64) goto v68;
    v64 = v66;
    if (v64 == nil) goto v69;
    stack[-4] = v66;
    v64 = stack[0];
    v64 = qcdr(v64);
    stack[-3] = v64;
    v64 = stack[-3];
    if (v64 == nil) goto v70;
    v64 = stack[-3];
    v64 = qcar(v64);
    v64 = CC_dp_from_a(env, v64);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v64 = ncons(v64);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    stack[-1] = v64;
    stack[-2] = v64;
    goto v72;

v72:
    v64 = stack[-3];
    v64 = qcdr(v64);
    stack[-3] = v64;
    v64 = stack[-3];
    if (v64 == nil) goto v73;
    stack[0] = stack[-1];
    v64 = stack[-3];
    v64 = qcar(v64);
    v64 = CC_dp_from_a(env, v64);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v64 = ncons(v64);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v64 = Lrplacd(nil, stack[0], v64);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v64 = stack[-1];
    v64 = qcdr(v64);
    stack[-1] = v64;
    goto v72;

v73:
    v64 = stack[-2];
    goto v74;

v74:
    v64 = ncons(v64);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    {
        Lisp_Object v75 = stack[-4];
        popv(6);
        fn = elt(env, 10); /* apply */
        return (*qfn2(fn))(qenv(fn), v75, v64);
    }

v70:
    v64 = qvalue(elt(env, 8)); /* nil */
    goto v74;

v69:
    v64 = stack[0];
    {
        popv(6);
        fn = elt(env, 11); /* dp!=a2dpatom */
        return (*qfn1(fn))(qenv(fn), v64);
    }

v68:
    v64 = stack[0];
    v64 = qcdr(v64);
    v64 = qcar(v64);
    v65 = CC_dp_from_a(env, v64);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v64 = stack[0];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v64 = qcar(v64);
    {
        popv(6);
        fn = elt(env, 7); /* dp!=fnpow */
        return (*qfn2(fn))(qenv(fn), v65, v64);
    }

v25:
    v64 = stack[0];
    v64 = qcar(v64);
    v64 = Lsymbolp(nil, v64);
    env = stack[-5];
    v64 = (v64 == nil ? lisp_true : nil);
    goto v12;

v67:
    v64 = stack[0];
    {
        popv(6);
        fn = elt(env, 11); /* dp!=a2dpatom */
        return (*qfn1(fn))(qenv(fn), v64);
    }

v10:
    v65 = stack[0];
    v64 = elt(env, 3); /* mat */
    v64 = Leqcar(nil, v65, v64);
    env = stack[-5];
    goto v41;
/* error exit handlers */
v71:
    popv(6);
    return nil;
}



/* Code for invbase */

static Lisp_Object CC_invbase(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v150, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for invbase");
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
    stack[0] = v0;
/* end of prologue */
    v149 = stack[0];
    v149 = qcar(v149);
    fn = elt(env, 12); /* reval */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    stack[0] = v149;
    v150 = stack[0];
    v149 = elt(env, 1); /* list */
    if (!consp(v150)) goto v153;
    v150 = qcar(v150);
    if (!(v150 == v149)) goto v153;

v154:
    v149 = stack[0];
    v149 = qcdr(v149);
    stack[-3] = v149;
    v149 = stack[-3];
    if (v149 == nil) goto v16;
    v149 = stack[-3];
    v149 = qcar(v149);
    fn = elt(env, 12); /* reval */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v151 = v149;
    v150 = elt(env, 5); /* equal */
    if (!consp(v151)) goto v155;
    v151 = qcar(v151);
    if (!(v151 == v150)) goto v155;
    v151 = elt(env, 6); /* difference */
    v150 = v149;
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v149 = qcdr(v149);
    v149 = qcdr(v149);
    v149 = qcar(v149);
    v149 = list3(v151, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    fn = elt(env, 12); /* reval */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    goto v155;

v155:
    v149 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    stack[-1] = v149;
    stack[-2] = v149;
    goto v67;

v67:
    v149 = stack[-3];
    v149 = qcdr(v149);
    stack[-3] = v149;
    v149 = stack[-3];
    if (v149 == nil) goto v156;
    stack[0] = stack[-1];
    v149 = stack[-3];
    v149 = qcar(v149);
    fn = elt(env, 12); /* reval */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v151 = v149;
    v150 = elt(env, 5); /* equal */
    if (!consp(v151)) goto v39;
    v151 = qcar(v151);
    if (!(v151 == v150)) goto v39;
    v151 = elt(env, 6); /* difference */
    v150 = v149;
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v149 = qcdr(v149);
    v149 = qcdr(v149);
    v149 = qcar(v149);
    v149 = list3(v151, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    fn = elt(env, 12); /* reval */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    goto v39;

v39:
    v149 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = Lrplacd(nil, stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = stack[-1];
    v149 = qcdr(v149);
    stack[-1] = v149;
    goto v67;

v156:
    v149 = stack[-2];
    goto v59;

v59:
    stack[0] = v149;
    v149 = qvalue(elt(env, 7)); /* invsysvars!* */
    if (!(v149 == nil)) goto v157;
    v149 = stack[0];
    fn = elt(env, 13); /* gvarlis */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    goto v157;

v157:
    stack[-9] = v149;
    v150 = elt(env, 1); /* list */
    v149 = stack[0];
    stack[0] = cons(v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v150 = elt(env, 1); /* list */
    v149 = stack[-9];
    v149 = cons(v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    fn = elt(env, 14); /* readsys */
    v149 = (*qfn2(fn))(qenv(fn), stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    fn = elt(env, 15); /* invbase!* */
    v149 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = qvalue(elt(env, 8)); /* gg */
    stack[-8] = v149;
    v149 = stack[-8];
    if (v149 == nil) goto v158;
    v149 = stack[-8];
    v149 = qcar(v149);
    stack[-4] = elt(env, 9); /* plus */
    v150 = qvalue(elt(env, 10)); /* gv */
    v149 = qcar(v149);
    v149 = *(Lisp_Object *)((char *)v150 + (CELL-TAG_VECTOR) + ((int32_t)v149/(16/CELL)));
    stack[-3] = v149;
    v149 = stack[-3];
    if (v149 == nil) goto v159;
    v149 = stack[-3];
    v149 = qcar(v149);
    v150 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = stack[-9];
    fn = elt(env, 16); /* !*di2q */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v150 = v149;
    v149 = v150;
    v149 = qcar(v149);
    if (v149 == nil) goto v160;
    v149 = elt(env, 11); /* prepf */
    fn = elt(env, 17); /* sqform */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    goto v161;

v161:
    v149 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    stack[-1] = v149;
    stack[-2] = v149;
    goto v162;

v162:
    v149 = stack[-3];
    v149 = qcdr(v149);
    stack[-3] = v149;
    v149 = stack[-3];
    if (v149 == nil) goto v163;
    stack[0] = stack[-1];
    v149 = stack[-3];
    v149 = qcar(v149);
    v150 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = stack[-9];
    fn = elt(env, 16); /* !*di2q */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v150 = v149;
    v149 = v150;
    v149 = qcar(v149);
    if (v149 == nil) goto v164;
    v149 = elt(env, 11); /* prepf */
    fn = elt(env, 17); /* sqform */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    goto v165;

v165:
    v149 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = Lrplacd(nil, stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = stack[-1];
    v149 = qcdr(v149);
    stack[-1] = v149;
    goto v162;

v164:
    v149 = (Lisp_Object)1; /* 0 */
    goto v165;

v163:
    v149 = stack[-2];
    goto v166;

v166:
    v149 = cons(stack[-4], v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    stack[-6] = v149;
    stack[-7] = v149;
    goto v71;

v71:
    v149 = stack[-8];
    v149 = qcdr(v149);
    stack[-8] = v149;
    v149 = stack[-8];
    if (v149 == nil) goto v167;
    stack[-5] = stack[-6];
    v149 = stack[-8];
    v149 = qcar(v149);
    stack[-4] = elt(env, 9); /* plus */
    v150 = qvalue(elt(env, 10)); /* gv */
    v149 = qcar(v149);
    v149 = *(Lisp_Object *)((char *)v150 + (CELL-TAG_VECTOR) + ((int32_t)v149/(16/CELL)));
    stack[-3] = v149;
    v149 = stack[-3];
    if (v149 == nil) goto v168;
    v149 = stack[-3];
    v149 = qcar(v149);
    v150 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = stack[-9];
    fn = elt(env, 16); /* !*di2q */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v150 = v149;
    v149 = v150;
    v149 = qcar(v149);
    if (v149 == nil) goto v169;
    v149 = elt(env, 11); /* prepf */
    fn = elt(env, 17); /* sqform */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    goto v170;

v170:
    v149 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    stack[-1] = v149;
    stack[-2] = v149;
    goto v171;

v171:
    v149 = stack[-3];
    v149 = qcdr(v149);
    stack[-3] = v149;
    v149 = stack[-3];
    if (v149 == nil) goto v172;
    stack[0] = stack[-1];
    v149 = stack[-3];
    v149 = qcar(v149);
    v150 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = stack[-9];
    fn = elt(env, 16); /* !*di2q */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v150 = v149;
    v149 = v150;
    v149 = qcar(v149);
    if (v149 == nil) goto v173;
    v149 = elt(env, 11); /* prepf */
    fn = elt(env, 17); /* sqform */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    goto v174;

v174:
    v149 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = Lrplacd(nil, stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = stack[-1];
    v149 = qcdr(v149);
    stack[-1] = v149;
    goto v171;

v173:
    v149 = (Lisp_Object)1; /* 0 */
    goto v174;

v172:
    v149 = stack[-2];
    goto v175;

v175:
    v149 = cons(stack[-4], v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = Lrplacd(nil, stack[-5], v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    v149 = stack[-6];
    v149 = qcdr(v149);
    stack[-6] = v149;
    goto v71;

v169:
    v149 = (Lisp_Object)1; /* 0 */
    goto v170;

v168:
    v149 = qvalue(elt(env, 4)); /* nil */
    goto v175;

v167:
    v149 = stack[-7];
    goto v176;

v176:
    v150 = elt(env, 1); /* list */
    popv(11);
    return cons(v150, v149);

v160:
    v149 = (Lisp_Object)1; /* 0 */
    goto v161;

v159:
    v149 = qvalue(elt(env, 4)); /* nil */
    goto v166;

v158:
    v149 = qvalue(elt(env, 4)); /* nil */
    goto v176;

v16:
    v149 = qvalue(elt(env, 4)); /* nil */
    goto v59;

v153:
    v149 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v149 == nil)) goto v177;
    v149 = elt(env, 3); /* "Argument to invbase not a list" */
    fn = elt(env, 18); /* lprie */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    goto v177;

v177:
    v149 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-10];
    goto v154;
/* error exit handlers */
v152:
    popv(11);
    return nil;
}



/* Code for ggvars2 */

static Lisp_Object CC_ggvars2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v39, v40, v183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ggvars2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v40 = v1;
    v183 = v0;
/* end of prologue */
    v182 = v183;
    if (v182 == nil) goto v184;
    v182 = v183;
    v182 = (is_number(v182) ? lisp_true : nil);
    if (!(v182 == nil)) goto v24;
    v39 = v183;
    v182 = elt(env, 2); /* i */
    if (v39 == v182) goto v10;
    v182 = qvalue(elt(env, 4)); /* nil */
    goto v24;

v24:
    if (!(v182 == nil)) return onevalue(v40);
    v182 = v183;
    if (!consp(v182)) goto v17;
    v182 = v183;
    v39 = qcar(v182);
    v182 = elt(env, 5); /* (plus times expt difference minus quotient) 
*/
    v182 = Lmemq(nil, v39, v182);
    if (v182 == nil) goto v185;
    v182 = v183;
    v182 = qcdr(v182);
    v39 = v40;
    {
        fn = elt(env, 6); /* ggvars3 */
        return (*qfn2(fn))(qenv(fn), v182, v39);
    }

v185:
    v39 = v183;
    v182 = v40;
    v182 = Lmember(nil, v39, v182);
    if (!(v182 == nil)) return onevalue(v40);
    v182 = v183;
    v39 = v40;
    return cons(v182, v39);

v17:
    v39 = v183;
    v182 = v40;
    v182 = Lmember(nil, v39, v182);
    if (!(v182 == nil)) return onevalue(v40);
    v182 = v183;
    v39 = v40;
    return cons(v182, v39);

v10:
    v182 = qvalue(elt(env, 3)); /* !*complex */
    goto v24;

v184:
    v182 = qvalue(elt(env, 1)); /* t */
    goto v24;
}



/* Code for nrootnn */

static Lisp_Object CC_nrootnn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v222, v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nrootnn");
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
    stack[-5] = nil;
    v222 = (Lisp_Object)17; /* 1 */
    stack[0] = v222;
    v222 = (Lisp_Object)17; /* 1 */
    stack[-2] = v222;
    v223 = stack[-7];
    v222 = (Lisp_Object)1; /* 0 */
    v222 = (Lisp_Object)lessp2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    v222 = v222 ? lisp_true : nil;
    env = stack[-9];
    if (v222 == nil) goto v10;
    v222 = stack[-7];
    v222 = negate(v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[-7] = v222;
    v222 = stack[-6];
    v222 = Levenp(nil, v222);
    env = stack[-9];
    if (v222 == nil) goto v16;
    v222 = qvalue(elt(env, 1)); /* t */
    stack[-5] = v222;
    goto v10;

v10:
    v222 = qvalue(elt(env, 2)); /* !*primelist!* */
    stack[-8] = v222;
    goto v225;

v225:
    v222 = stack[-8];
    v222 = qcar(v222);
    stack[-1] = v222;
    v222 = stack[-8];
    v222 = qcdr(v222);
    stack[-8] = v222;
    v222 = (Lisp_Object)1; /* 0 */
    stack[-3] = v222;
    goto v57;

v57:
    v223 = stack[-7];
    v222 = stack[-1];
    v222 = Ldivide(nil, v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[-4] = v222;
    v223 = qcdr(v222);
    v222 = (Lisp_Object)1; /* 0 */
    if (v223 == v222) goto v226;
    v223 = stack[-3];
    v222 = stack[-6];
    if (((int32_t)(v223)) < ((int32_t)(v222))) goto v227;
    v223 = stack[-3];
    v222 = stack[-6];
    v222 = Ldivide(nil, v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[-3] = v222;
    v223 = stack[-1];
    v222 = stack[-3];
    v222 = qcar(v222);
    v222 = Lexpt(nil, v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    v222 = times2(stack[0], v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[0] = v222;
    v222 = stack[-3];
    v222 = qcdr(v222);
    stack[-3] = v222;
    goto v227;

v227:
    v223 = stack[-3];
    v222 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v223)) > ((int32_t)(v222))) goto v141;
    v222 = stack[-4];
    v223 = qcar(v222);
    v222 = stack[-1];
    v222 = (Lisp_Object)lessp2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    v222 = v222 ? lisp_true : nil;
    env = stack[-9];
    if (v222 == nil) goto v228;
    v223 = stack[-7];
    v222 = stack[-2];
    v222 = times2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[-2] = v222;
    goto v229;

v229:
    v222 = stack[-5];
    if (v222 == nil) goto v93;
    v222 = stack[-2];
    v222 = negate(v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    stack[-2] = v222;
    goto v93;

v93:
    v223 = stack[0];
    v222 = stack[-2];
    popv(10);
    return cons(v223, v222);

v228:
    v222 = stack[-8];
    if (!(v222 == nil)) goto v225;
    v223 = (Lisp_Object)161; /* 10 */
    v222 = (Lisp_Object)321; /* 20 */
    v223 = Lexpt(nil, v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    v222 = stack[-7];
    v222 = (Lisp_Object)greaterp2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    v222 = v222 ? lisp_true : nil;
    env = stack[-9];
    if (v222 == nil) goto v230;
    v223 = stack[-7];
    v222 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 4); /* mcfactor!* */
    v222 = (*qfn2(fn))(qenv(fn), v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[-3] = v222;
    v222 = stack[-3];
    stack[-4] = v222;
    goto v231;

v231:
    v222 = stack[-4];
    if (v222 == nil) goto v229;
    v222 = stack[-4];
    v222 = qcar(v222);
    stack[-1] = v222;
    v222 = stack[-1];
    v223 = qcdr(v222);
    v222 = stack[-6];
    v222 = Ldivide(nil, v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[-3] = v222;
    v222 = stack[-1];
    v223 = qcar(v222);
    v222 = stack[-3];
    v222 = qcar(v222);
    v223 = Lexpt(nil, v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    v222 = stack[0];
    v222 = times2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[0] = v222;
    v222 = stack[-1];
    v223 = qcar(v222);
    v222 = stack[-3];
    v222 = qcdr(v222);
    v223 = Lexpt(nil, v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    v222 = stack[-2];
    v222 = times2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[-2] = v222;
    v222 = stack[-4];
    v222 = qcdr(v222);
    stack[-4] = v222;
    goto v231;

v230:
    v223 = stack[-7];
    v222 = stack[-6];
    fn = elt(env, 5); /* irootn */
    v222 = (*qfn2(fn))(qenv(fn), v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[-1] = v222;
    v223 = stack[-1];
    v222 = stack[-6];
    v223 = Lexpt(nil, v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    v222 = stack[-7];
    if (equal(v223, v222)) goto v116;
    v222 = qvalue(elt(env, 3)); /* nil */
    goto v232;

v232:
    stack[-3] = v222;
    if (v222 == nil) goto v233;
    v223 = stack[0];
    v222 = stack[-3];
    v222 = times2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[0] = v222;
    goto v229;

v233:
    v223 = stack[-7];
    v222 = stack[-2];
    v222 = times2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[-2] = v222;
    goto v229;

v116:
    v222 = stack[-1];
    goto v232;

v141:
    v223 = stack[-2];
    v222 = stack[-1];
    v222 = times2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-9];
    stack[-2] = v222;
    v222 = stack[-3];
    v222 = (Lisp_Object)((int32_t)(v222) - 0x10);
    stack[-3] = v222;
    goto v227;

v226:
    v222 = stack[-4];
    v222 = qcar(v222);
    stack[-7] = v222;
    v222 = stack[-3];
    v222 = (Lisp_Object)((int32_t)(v222) + 0x10);
    stack[-3] = v222;
    goto v57;

v16:
    v222 = (Lisp_Object)-15; /* -1 */
    stack[0] = v222;
    goto v10;
/* error exit handlers */
v224:
    popv(10);
    return nil;
}



/* Code for evaluate!-in!-vector */

static Lisp_Object MS_CDECL CC_evaluateKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v42, v226, v236, v237, v4;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-in-vector");
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
/* copy arguments values to proper place */
    v236 = v2;
    v226 = v1;
    v237 = v0;
/* end of prologue */
    v42 = v237;
    v155 = v226;
    v155 = *(Lisp_Object *)((char *)v42 + (CELL-TAG_VECTOR) + ((int32_t)v155/(16/CELL)));
    v42 = v155;
    v155 = v226;
    v155 = (Lisp_Object)((int32_t)(v155) - 0x10);
    v4 = v155;
    goto v238;

v238:
    v155 = v4;
    v155 = ((intptr_t)(v155) < 0 ? lisp_true : nil);
    if (!(v155 == nil)) { popv(1); return onevalue(v42); }
    v226 = v237;
    v155 = v4;
    v226 = *(Lisp_Object *)((char *)v226 + (CELL-TAG_VECTOR) + ((int32_t)v155/(16/CELL)));
    v155 = v236;
    v155 = Lmodular_times(nil, v42, v155);
    env = stack[0];
    {   int32_t w = int_of_fixnum(v226) + int_of_fixnum(v155);
        if (w >= current_modulus) w -= current_modulus;
        v155 = fixnum_of_int(w);
    }
    v42 = v155;
    v155 = v4;
    v155 = (Lisp_Object)((int32_t)(v155) - 0x10);
    v4 = v155;
    goto v238;
}



/* Code for repr_atfnew */

static Lisp_Object MS_CDECL CC_repr_atfnew(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v136, v134, v247;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "repr_atfnew");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repr_atfnew");
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
    stack[-5] = v2;
    v135 = v1;
    stack[0] = v0;
/* end of prologue */
    v136 = stack[0];
    v136 = qcar(v136);
    stack[-6] = v136;
    v136 = stack[0];
    v136 = qcdr(v136);
    v136 = qcar(v136);
    fn = elt(env, 3); /* pasf_coeflst */
    v135 = (*qfn2(fn))(qenv(fn), v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    stack[-1] = v135;
    v135 = stack[-1];
    v135 = qcar(v135);
    v135 = qcar(v135);
    fn = elt(env, 4); /* minusf */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    if (v135 == nil) goto v248;
    v135 = stack[0];
    v135 = Lconsp(nil, v135);
    env = stack[-7];
    if (v135 == nil) goto v146;
    v135 = stack[0];
    v135 = qcar(v135);
    v135 = Lconsp(nil, v135);
    env = stack[-7];
    if (v135 == nil) goto v146;
    v135 = stack[0];
    v135 = qcar(v135);
    v136 = qcar(v135);
    v135 = elt(env, 1); /* (cong ncong) */
    v135 = Lmemq(nil, v136, v135);
    if (v135 == nil) goto v146;
    v135 = stack[-6];
    v135 = qcar(v135);
    fn = elt(env, 5); /* pasf_anegrel */
    v136 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    v135 = stack[-6];
    v135 = qcdr(v135);
    v135 = cons(v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    goto v181;

v181:
    stack[-6] = v135;
    v135 = stack[-1];
    stack[-4] = v135;
    v135 = stack[-4];
    if (v135 == nil) goto v22;
    v135 = stack[-4];
    v135 = qcar(v135);
    stack[0] = v135;
    v135 = stack[0];
    v136 = qcar(v135);
    v135 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 6); /* multf */
    v136 = (*qfn2(fn))(qenv(fn), v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    v135 = stack[0];
    v135 = qcdr(v135);
    v135 = cons(v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    v135 = ncons(v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    stack[-2] = v135;
    stack[-3] = v135;
    goto v5;

v5:
    v135 = stack[-4];
    v135 = qcdr(v135);
    stack[-4] = v135;
    v135 = stack[-4];
    if (v135 == nil) goto v39;
    stack[-1] = stack[-2];
    v135 = stack[-4];
    v135 = qcar(v135);
    stack[0] = v135;
    v135 = stack[0];
    v136 = qcar(v135);
    v135 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 6); /* multf */
    v136 = (*qfn2(fn))(qenv(fn), v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    v135 = stack[0];
    v135 = qcdr(v135);
    v135 = cons(v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    v135 = ncons(v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    v135 = Lrplacd(nil, stack[-1], v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    v135 = stack[-2];
    v135 = qcdr(v135);
    stack[-2] = v135;
    goto v5;

v39:
    v135 = stack[-3];
    goto v8;

v8:
    stack[-1] = v135;
    goto v248;

v248:
    v247 = stack[-5];
    v134 = stack[-6];
    v136 = stack[-1];
    v135 = qvalue(elt(env, 2)); /* nil */
    {
        popv(8);
        fn = elt(env, 7); /* repr_new */
        return (*qfnn(fn))(qenv(fn), 4, v247, v134, v136, v135);
    }

v22:
    v135 = qvalue(elt(env, 2)); /* nil */
    goto v8;

v146:
    v135 = stack[-6];
    fn = elt(env, 5); /* pasf_anegrel */
    v135 = (*qfn1(fn))(qenv(fn), v135);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-7];
    goto v181;
/* error exit handlers */
v106:
    popv(8);
    return nil;
}



/* Code for aex_1 */

static Lisp_Object MS_CDECL CC_aex_1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "aex_1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_1");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 1); /* ratpoly_1 */
    v91 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* aex_fromrp */
        return (*qfn1(fn))(qenv(fn), v91);
    }
/* error exit handlers */
v6:
    popv(1);
    return nil;
}



/* Code for partialdiff */

static Lisp_Object CC_partialdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v252, v248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partialdiff");
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

v253:
    v252 = stack[-2];
    if (!consp(v252)) goto v184;
    v252 = stack[-2];
    v252 = qcar(v252);
    v252 = (consp(v252) ? nil : lisp_true);
    goto v24;

v24:
    if (v252 == nil) goto v147;
    v252 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v252); }

v147:
    v248 = stack[-1];
    v252 = stack[-2];
    v252 = qcar(v252);
    v252 = qcar(v252);
    v252 = qcar(v252);
    if (equal(v248, v252)) goto v246;
    v252 = stack[-2];
    v252 = qcar(v252);
    v248 = qcdr(v252);
    v252 = stack[-1];
    v252 = CC_partialdiff(env, v248, v252);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-4];
    v248 = v252;
    v252 = v248;
    if (v252 == nil) goto v255;
    v252 = stack[-2];
    v252 = qcar(v252);
    stack[-3] = qcar(v252);
    stack[0] = v248;
    v252 = stack[-2];
    v248 = qcdr(v252);
    v252 = stack[-1];
    v252 = CC_partialdiff(env, v248, v252);
    nil = C_nil;
    if (exception_pending()) goto v254;
    {
        Lisp_Object v256 = stack[-3];
        Lisp_Object v133 = stack[0];
        popv(5);
        return acons(v256, v133, v252);
    }

v255:
    v252 = stack[-2];
    v248 = qcdr(v252);
    v252 = stack[-1];
    stack[-2] = v248;
    stack[-1] = v252;
    goto v253;

v246:
    v252 = stack[-2];
    v252 = qcar(v252);
    v252 = qcar(v252);
    v252 = qcdr(v252);
    stack[0] = v252;
    v248 = stack[0];
    v252 = (Lisp_Object)17; /* 1 */
    if (v248 == v252) goto v36;
    v252 = stack[-1];
    fn = elt(env, 3); /* fkern */
    stack[-3] = (*qfn1(fn))(qenv(fn), v252);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-4];
    v252 = stack[0];
    v252 = sub1(v252);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-4];
    fn = elt(env, 4); /* getpower */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[-3], v252);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-4];
    v248 = stack[0];
    v252 = stack[-2];
    v252 = qcar(v252);
    v252 = qcdr(v252);
    fn = elt(env, 5); /* multd */
    stack[0] = (*qfn2(fn))(qenv(fn), v248, v252);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-4];
    v252 = stack[-2];
    v248 = qcdr(v252);
    v252 = stack[-1];
    v252 = CC_partialdiff(env, v248, v252);
    nil = C_nil;
    if (exception_pending()) goto v254;
    {
        Lisp_Object v49 = stack[-3];
        Lisp_Object v50 = stack[0];
        popv(5);
        return acons(v49, v50, v252);
    }

v36:
    v252 = stack[-2];
    v252 = qcar(v252);
    v252 = qcdr(v252);
    { popv(5); return onevalue(v252); }

v184:
    v252 = qvalue(elt(env, 1)); /* t */
    goto v24;
/* error exit handlers */
v254:
    popv(5);
    return nil;
}



/* Code for transferrow */

static Lisp_Object CC_transferrow(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transferrow");
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
    stack[-2] = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v51 = qvalue(elt(env, 2)); /* maxvar */
    v47 = stack[-2];
    v47 = plus2(v51, v47);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v51 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v47/(16/CELL)));
    v47 = (Lisp_Object)33; /* 2 */
    v51 = *(Lisp_Object *)((char *)v51 + (CELL-TAG_VECTOR) + ((int32_t)v47/(16/CELL)));
    v47 = elt(env, 3); /* plus */
    if (v51 == v47) goto v19;
    v47 = stack[-2];
    fn = elt(env, 6); /* transferrow1 */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    if (v47 == nil) goto v263;
    v51 = stack[-2];
    v47 = stack[0];
    {
        popv(5);
        fn = elt(env, 7); /* transferrow2 */
        return (*qfn2(fn))(qenv(fn), v51, v47);
    }

v263:
    v47 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v47); }

v19:
    v47 = stack[-2];
    fn = elt(env, 6); /* transferrow1 */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    if (v47 == nil) goto v67;
    stack[-3] = qvalue(elt(env, 1)); /* codmat */
    stack[-1] = qvalue(elt(env, 2)); /* maxvar */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v51 = qvalue(elt(env, 2)); /* maxvar */
    v47 = stack[-2];
    v47 = plus2(v51, v47);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v51 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v47/(16/CELL)));
    v47 = (Lisp_Object)49; /* 3 */
    v47 = *(Lisp_Object *)((char *)v51 + (CELL-TAG_VECTOR) + ((int32_t)v47/(16/CELL)));
    v47 = plus2(stack[-1], v47);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v51 = *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)v47/(16/CELL)));
    v47 = (Lisp_Object)33; /* 2 */
    v47 = *(Lisp_Object *)((char *)v51 + (CELL-TAG_VECTOR) + ((int32_t)v47/(16/CELL)));
    v51 = elt(env, 5); /* times */
    v47 = (v47 == v51 ? lisp_true : nil);
    { popv(5); return onevalue(v47); }

v67:
    v47 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v47); }
/* error exit handlers */
v72:
    popv(5);
    return nil;
}



/* Code for xregister_spoly_pair */

static Lisp_Object MS_CDECL CC_xregister_spoly_pair(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v2;
    argcheck(nargs, 0, "xregister_spoly_pair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xregister_spoly_pair");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v2 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v2);
}



/* Code for evalsetbool */

static Lisp_Object MS_CDECL CC_evalsetbool(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v202, v273, v274;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evalsetbool");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalsetbool");
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
    stack[-8] = nil;
    stack[-4] = nil;
    v202 = stack[-6];
    v159 = stack[-5];
    v159 = list2(v202, v159);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-9];
    stack[-3] = v159;
    v159 = stack[-3];
    if (v159 == nil) goto v177;
    v159 = stack[-3];
    v159 = qcar(v159);
    v273 = v159;
    v202 = v273;
    v159 = elt(env, 2); /* list */
    if (!consp(v202)) goto v59;
    v202 = qcar(v202);
    if (!(v202 == v159)) goto v59;
    v159 = qvalue(elt(env, 3)); /* t */
    stack[-8] = v159;
    v159 = v273;
    v159 = qcdr(v159);
    goto v142;

v142:
    v159 = ncons(v159);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-9];
    stack[-1] = v159;
    stack[-2] = v159;
    goto v229;

v229:
    v159 = stack[-3];
    v159 = qcdr(v159);
    stack[-3] = v159;
    v159 = stack[-3];
    if (v159 == nil) goto v27;
    stack[0] = stack[-1];
    v159 = stack[-3];
    v159 = qcar(v159);
    v273 = v159;
    v202 = v273;
    v159 = elt(env, 2); /* list */
    if (!consp(v202)) goto v178;
    v202 = qcar(v202);
    if (!(v202 == v159)) goto v178;
    v159 = qvalue(elt(env, 3)); /* t */
    stack[-8] = v159;
    v159 = v273;
    v159 = qcdr(v159);
    goto v245;

v245:
    v159 = ncons(v159);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-9];
    v159 = Lrplacd(nil, stack[0], v159);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-9];
    v159 = stack[-1];
    v159 = qcdr(v159);
    stack[-1] = v159;
    goto v229;

v178:
    v159 = v273;
    fn = elt(env, 9); /* reval */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-9];
    v273 = v159;
    if (symbolp(v159)) goto v47;
    v159 = v273;
    v159 = Lconsp(nil, v159);
    env = stack[-9];
    if (v159 == nil) goto v217;
    v159 = v273;
    v202 = qcar(v159);
    v159 = elt(env, 4); /* setvalued */
    v159 = Lflagp(nil, v202, v159);
    env = stack[-9];
    if (!(v159 == nil)) goto v47;

v217:
    v202 = v273;
    v159 = elt(env, 5); /* "set" */
    fn = elt(env, 10); /* typerr */
    v159 = (*qfn2(fn))(qenv(fn), v202, v159);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-9];
    goto v245;

v47:
    v159 = qvalue(elt(env, 3)); /* t */
    stack[-4] = v159;
    v159 = v273;
    goto v245;

v27:
    v159 = stack[-2];
    goto v225;

v225:
    v273 = v159;
    v159 = stack[-8];
    if (v159 == nil) { popv(10); return onevalue(v273); }
    v159 = stack[-4];
    if (v159 == nil) goto v276;
    stack[0] = elt(env, 6); /* "Cannot evaluate" */
    stack[-1] = stack[-7];
    v159 = stack[-6];
    fn = elt(env, 9); /* reval */
    stack[-2] = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-9];
    v159 = stack[-5];
    fn = elt(env, 9); /* reval */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-9];
    v274 = list3(stack[-1], stack[-2], v159);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-9];
    v273 = elt(env, 7); /* "as Boolean-valued set expression" */
    v202 = qvalue(elt(env, 1)); /* nil */
    v159 = qvalue(elt(env, 3)); /* t */
    {
        Lisp_Object v127 = stack[0];
        popv(10);
        fn = elt(env, 11); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v127, v274, v273, v202, v159);
    }

v276:
    v202 = stack[-7];
    v159 = elt(env, 8); /* setboolfn */
    v159 = get(v202, v159);
    env = stack[-9];
    v202 = v273;
    {
        popv(10);
        fn = elt(env, 12); /* apply */
        return (*qfn2(fn))(qenv(fn), v159, v202);
    }

v59:
    v159 = v273;
    fn = elt(env, 9); /* reval */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-9];
    v273 = v159;
    if (symbolp(v159)) goto v35;
    v159 = v273;
    v159 = Lconsp(nil, v159);
    env = stack[-9];
    if (v159 == nil) goto v220;
    v159 = v273;
    v202 = qcar(v159);
    v159 = elt(env, 4); /* setvalued */
    v159 = Lflagp(nil, v202, v159);
    env = stack[-9];
    if (!(v159 == nil)) goto v35;

v220:
    v202 = v273;
    v159 = elt(env, 5); /* "set" */
    fn = elt(env, 10); /* typerr */
    v159 = (*qfn2(fn))(qenv(fn), v202, v159);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-9];
    goto v142;

v35:
    v159 = qvalue(elt(env, 3)); /* t */
    stack[-4] = v159;
    v159 = v273;
    goto v142;

v177:
    v159 = qvalue(elt(env, 1)); /* nil */
    goto v225;
/* error exit handlers */
v275:
    popv(10);
    return nil;
}



/* Code for gcdlist1 */

static Lisp_Object CC_gcdlist1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v285, v189, v190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdlist1");
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
    stack[-6] = qvalue(elt(env, 1)); /* reduction!-count */
    qvalue(elt(env, 1)) = nil; /* reduction!-count */
    v285 = stack[0];
    v285 = qcar(v285);
    v285 = qcdr(v285);
    stack[-4] = v285;
    stack[-2] = v285;
    v285 = stack[0];
    v285 = qcdr(v285);
    stack[-3] = v285;
    goto v63;

v63:
    v285 = stack[-3];
    if (v285 == nil) goto v180;
    v285 = stack[-3];
    v285 = qcar(v285);
    stack[-1] = v285;
    v189 = stack[-2];
    v285 = stack[-1];
    v285 = qcdr(v285);
    fn = elt(env, 4); /* vunion */
    v285 = (*qfn2(fn))(qenv(fn), v189, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    stack[-2] = v285;
    v189 = stack[-4];
    v285 = stack[-1];
    v285 = qcdr(v285);
    fn = elt(env, 5); /* vintersection */
    v285 = (*qfn2(fn))(qenv(fn), v189, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    stack[-4] = v285;
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    goto v63;

v180:
    v285 = stack[-4];
    if (v285 == nil) goto v286;
    v285 = stack[-4];
    stack[-1] = v285;
    goto v237;

v237:
    v285 = stack[-1];
    if (v285 == nil) goto v30;
    v285 = stack[-1];
    v285 = qcar(v285);
    v189 = v285;
    v285 = stack[-2];
    fn = elt(env, 6); /* vdelete */
    v285 = (*qfn2(fn))(qenv(fn), v189, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    stack[-2] = v285;
    v285 = stack[-1];
    v285 = qcdr(v285);
    stack[-1] = v285;
    goto v237;

v30:
    v189 = stack[-4];
    v285 = elt(env, 3); /* lesspcdr */
    fn = elt(env, 7); /* sort */
    v285 = (*qfn2(fn))(qenv(fn), v189, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    stack[-4] = v285;
    v285 = stack[-4];
    v285 = qcar(v285);
    v189 = qcdr(v285);
    v285 = (Lisp_Object)17; /* 1 */
    if (v189 == v285) goto v178;
    v285 = stack[-2];
    if (v285 == nil) goto v287;
    v189 = stack[-2];
    v285 = stack[-4];
    v285 = Lappend(nil, v189, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    fn = elt(env, 8); /* mapcarcar */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    fn = elt(env, 9); /* setkorder */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    stack[-5] = v285;
    v285 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v285;
    v285 = stack[0];
    stack[-1] = v285;
    goto v162;

v162:
    v285 = stack[-1];
    if (v285 == nil) goto v208;
    v285 = stack[-1];
    v285 = qcar(v285);
    v285 = qcar(v285);
    fn = elt(env, 10); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = stack[-2];
    fn = elt(env, 8); /* mapcarcar */
    v189 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = stack[-4];
    fn = elt(env, 11); /* split!-wrt!-variables */
    v285 = (*qfnn(fn))(qenv(fn), 3, stack[0], v189, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    stack[-4] = v285;
    v285 = stack[-1];
    v285 = qcdr(v285);
    stack[-1] = v285;
    goto v162;

v208:
    v285 = stack[-5];
    fn = elt(env, 9); /* setkorder */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = stack[-4];
    stack[-5] = v285;
    v285 = stack[-5];
    if (v285 == nil) goto v203;
    v285 = stack[-5];
    v285 = qcar(v285);
    stack[-1] = v285;
    v285 = stack[-1];
    fn = elt(env, 10); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v189 = stack[-1];
    v285 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 12); /* total!-degree!-in!-powers */
    v285 = (*qfn2(fn))(qenv(fn), v189, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = cons(stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = ncons(v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    stack[-3] = v285;
    stack[-4] = v285;
    goto v288;

v288:
    v285 = stack[-5];
    v285 = qcdr(v285);
    stack[-5] = v285;
    v285 = stack[-5];
    if (v285 == nil) goto v289;
    stack[-2] = stack[-3];
    v285 = stack[-5];
    v285 = qcar(v285);
    stack[-1] = v285;
    v285 = stack[-1];
    fn = elt(env, 10); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v189 = stack[-1];
    v285 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 12); /* total!-degree!-in!-powers */
    v285 = (*qfn2(fn))(qenv(fn), v189, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = cons(stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = ncons(v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = Lrplacd(nil, stack[-2], v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    goto v288;

v289:
    v285 = stack[-4];
    goto v290;

v290:
    v285 = CC_gcdlist1(env, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    goto v184;

v184:
    qvalue(elt(env, 1)) = stack[-6]; /* reduction!-count */
    { popv(8); return onevalue(v285); }

v203:
    v285 = qvalue(elt(env, 2)); /* nil */
    goto v290;

v287:
    v189 = stack[0];
    v285 = stack[-4];
    fn = elt(env, 13); /* gcdlist2 */
    v285 = (*qfn2(fn))(qenv(fn), v189, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    goto v184;

v178:
    v189 = stack[-4];
    v285 = stack[-2];
    v285 = Lappend(nil, v189, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    fn = elt(env, 8); /* mapcarcar */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    stack[-5] = v285;
    v285 = stack[-5];
    fn = elt(env, 9); /* setkorder */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    stack[-4] = v285;
    v285 = stack[0];
    stack[-3] = v285;
    v285 = stack[-3];
    if (v285 == nil) goto v140;
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = qcar(v285);
    fn = elt(env, 10); /* reorder */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = ncons(v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    stack[-1] = v285;
    stack[-2] = v285;
    goto v291;

v291:
    v285 = stack[-3];
    v285 = qcdr(v285);
    stack[-3] = v285;
    v285 = stack[-3];
    if (v285 == nil) goto v270;
    stack[0] = stack[-1];
    v285 = stack[-3];
    v285 = qcar(v285);
    v285 = qcar(v285);
    fn = elt(env, 10); /* reorder */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = ncons(v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = Lrplacd(nil, stack[0], v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = stack[-1];
    v285 = qcdr(v285);
    stack[-1] = v285;
    goto v291;

v270:
    v285 = stack[-2];
    v190 = v285;
    goto v47;

v47:
    v189 = qvalue(elt(env, 2)); /* nil */
    v285 = stack[-5];
    fn = elt(env, 14); /* gcdlist3 */
    v285 = (*qfnn(fn))(qenv(fn), 3, v190, v189, v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    stack[0] = v285;
    v285 = stack[-4];
    fn = elt(env, 9); /* setkorder */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    v285 = stack[0];
    fn = elt(env, 10); /* reorder */
    v285 = (*qfn1(fn))(qenv(fn), v285);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-7];
    goto v184;

v140:
    v285 = qvalue(elt(env, 2)); /* nil */
    v190 = v285;
    goto v47;

v286:
    v285 = (Lisp_Object)17; /* 1 */
    goto v184;
/* error exit handlers */
v80:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* reduction!-count */
    popv(8);
    return nil;
}



/* Code for drop_dec_with */

static Lisp_Object MS_CDECL CC_drop_dec_with(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v255, v272;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "drop_dec_with");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for drop_dec_with");
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
    stack[-5] = nil;
    v43 = stack[-2];
    if (v43 == nil) goto v177;
    v255 = stack[-3];
    v43 = elt(env, 1); /* dec_with_rl */
    v43 = get(v255, v43);
    env = stack[-6];
    goto v191;

v191:
    stack[-1] = v43;
    goto v37;

v37:
    v43 = stack[-1];
    if (v43 == nil) goto v142;
    v43 = stack[-1];
    v43 = qcar(v43);
    stack[0] = v43;
    v255 = stack[-4];
    v43 = stack[0];
    v43 = Ldelete(nil, v255, v43);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[0] = v43;
    v43 = stack[0];
    v255 = Llength(nil, v43);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    v43 = (Lisp_Object)17; /* 1 */
    v43 = (Lisp_Object)greaterp2(v255, v43);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v43 = v43 ? lisp_true : nil;
    env = stack[-6];
    if (v43 == nil) goto v226;
    v255 = stack[0];
    v43 = stack[-5];
    v43 = cons(v255, v43);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-6];
    stack[-5] = v43;
    goto v226;

v226:
    v43 = stack[-1];
    v43 = qcdr(v43);
    stack[-1] = v43;
    goto v37;

v142:
    v43 = stack[-2];
    if (v43 == nil) goto v139;
    v272 = stack[-3];
    v255 = elt(env, 1); /* dec_with_rl */
    v43 = stack[-5];
    v43 = Lputprop(nil, 3, v272, v255, v43);
    nil = C_nil;
    if (exception_pending()) goto v52;
    goto v30;

v30:
    v43 = nil;
    { popv(7); return onevalue(v43); }

v139:
    v272 = stack[-3];
    v255 = elt(env, 2); /* dec_with */
    v43 = stack[-5];
    v43 = Lputprop(nil, 3, v272, v255, v43);
    nil = C_nil;
    if (exception_pending()) goto v52;
    goto v30;

v177:
    v255 = stack[-3];
    v43 = elt(env, 2); /* dec_with */
    v43 = get(v255, v43);
    env = stack[-6];
    goto v191;
/* error exit handlers */
v52:
    popv(7);
    return nil;
}



/* Code for stp */

static Lisp_Object CC_stp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stp");
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
    v229 = v0;
/* end of prologue */
    v180 = v229;
    v180 = Lconsp(nil, v180);
    env = stack[0];
    if (v180 == nil) goto v6;
    v229 = qcar(v229);
    {
        popv(1);
        fn = elt(env, 2); /* spp */
        return (*qfn1(fn))(qenv(fn), v229);
    }

v6:
    v229 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v229); }
}



/* Code for rappend */

static Lisp_Object CC_rappend(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v260;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rappend");
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
    v260 = elt(env, 1); /* append */
    v54 = stack[0];
    v54 = cons(v260, v54);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    fn = elt(env, 4); /* argnochk */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    v54 = stack[0];
    v54 = qcar(v54);
    fn = elt(env, 5); /* reval */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    stack[-2] = v54;
    fn = elt(env, 6); /* getrtype */
    v260 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    v54 = elt(env, 2); /* list */
    if (v260 == v54) goto v235;
    v260 = stack[-2];
    v54 = elt(env, 3); /* "list" */
    fn = elt(env, 7); /* typerr */
    v54 = (*qfn2(fn))(qenv(fn), v260, v54);
    nil = C_nil;
    if (exception_pending()) goto v26;
    goto v63;

v63:
    v54 = nil;
    { popv(4); return onevalue(v54); }

v235:
    v54 = stack[0];
    v54 = qcdr(v54);
    v54 = qcar(v54);
    fn = elt(env, 5); /* reval */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    stack[-1] = v54;
    fn = elt(env, 6); /* getrtype */
    v260 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    v54 = elt(env, 2); /* list */
    if (v260 == v54) goto v33;
    v260 = stack[-1];
    v54 = elt(env, 3); /* "list" */
    fn = elt(env, 7); /* typerr */
    v54 = (*qfn2(fn))(qenv(fn), v260, v54);
    nil = C_nil;
    if (exception_pending()) goto v26;
    goto v63;

v33:
    stack[0] = elt(env, 2); /* list */
    v54 = stack[-2];
    v260 = qcdr(v54);
    v54 = stack[-1];
    v54 = qcdr(v54);
    v54 = Lappend(nil, v260, v54);
    nil = C_nil;
    if (exception_pending()) goto v26;
    {
        Lisp_Object v27 = stack[0];
        popv(4);
        return cons(v27, v54);
    }
/* error exit handlers */
v26:
    popv(4);
    return nil;
}



/* Code for polineqcheck */

static Lisp_Object CC_polineqcheck(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polineqcheck");
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

v253:
    v36 = stack[-1];
    if (v36 == nil) goto v19;
    v36 = stack[-1];
    v235 = qcar(v36);
    v36 = stack[0];
    fn = elt(env, 3); /* subsq */
    v36 = (*qfn2(fn))(qenv(fn), v235, v36);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    v36 = qcar(v36);
    fn = elt(env, 4); /* minusf */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    if (v36 == nil) goto v61;
    v36 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v36); }

v61:
    v36 = stack[-1];
    v235 = qcdr(v36);
    v36 = stack[0];
    stack[-1] = v235;
    stack[0] = v36;
    goto v253;

v19:
    v36 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v36); }
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for reduce!-mod!-eig */

static Lisp_Object CC_reduceKmodKeig(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v78, v265;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-eig");
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
    v107 = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[0] = v107;
    goto v191;

v191:
    v107 = stack[0];
    if (v107 == nil) goto v184;
    v78 = stack[-1];
    v107 = stack[0];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    fn = elt(env, 2); /* reduce!-mod!-eigf */
    v107 = (*qfn2(fn))(qenv(fn), v78, v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    stack[-6] = v107;
    v107 = qcar(v107);
    if (v107 == nil) goto v246;
    v107 = stack[0];
    v107 = qcar(v107);
    v265 = qcar(v107);
    v78 = stack[-6];
    v107 = stack[-2];
    v107 = acons(v265, v78, v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    stack[-2] = v107;
    goto v246;

v246:
    v107 = stack[0];
    v107 = qcdr(v107);
    stack[0] = v107;
    goto v191;

v184:
    v107 = (Lisp_Object)17; /* 1 */
    stack[-6] = v107;
    v107 = stack[-2];
    stack[0] = v107;
    goto v292;

v292:
    v107 = stack[0];
    if (v107 == nil) goto v25;
    v78 = stack[-6];
    v107 = stack[0];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    fn = elt(env, 3); /* lcm */
    v107 = (*qfn2(fn))(qenv(fn), v78, v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    stack[-6] = v107;
    v107 = stack[0];
    v107 = qcdr(v107);
    stack[0] = v107;
    goto v292;

v25:
    v107 = stack[-2];
    v107 = Lreverse(nil, v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    stack[-5] = v107;
    v107 = stack[-5];
    if (v107 == nil) goto v27;
    v107 = stack[-5];
    v107 = qcar(v107);
    stack[-1] = qcar(v107);
    v107 = stack[-5];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    stack[0] = qcar(v107);
    v78 = stack[-6];
    v107 = stack[-5];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    fn = elt(env, 4); /* quotf */
    v107 = (*qfn2(fn))(qenv(fn), v78, v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    fn = elt(env, 5); /* multf */
    v107 = (*qfn2(fn))(qenv(fn), stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    v107 = cons(stack[-1], v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    stack[-3] = v107;
    stack[-4] = v107;
    goto v260;

v260:
    v107 = stack[-5];
    v107 = qcdr(v107);
    stack[-5] = v107;
    v107 = stack[-5];
    if (v107 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    stack[-2] = stack[-3];
    v107 = stack[-5];
    v107 = qcar(v107);
    stack[-1] = qcar(v107);
    v107 = stack[-5];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    stack[0] = qcar(v107);
    v78 = stack[-6];
    v107 = stack[-5];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    fn = elt(env, 4); /* quotf */
    v107 = (*qfn2(fn))(qenv(fn), v78, v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    fn = elt(env, 5); /* multf */
    v107 = (*qfn2(fn))(qenv(fn), stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    v107 = cons(stack[-1], v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    v107 = Lrplacd(nil, stack[-2], v107);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-7];
    v107 = stack[-3];
    v107 = qcdr(v107);
    stack[-3] = v107;
    goto v260;

v27:
    v107 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v107); }
/* error exit handlers */
v209:
    popv(8);
    return nil;
}



/* Code for evalwhereexp */

static Lisp_Object CC_evalwhereexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalwhereexp");
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
    v17 = v0;
/* end of prologue */
    v16 = v17;
    v16 = qcar(v16);
    stack[-2] = qcdr(v16);
    stack[-1] = elt(env, 1); /* aeval */
    stack[0] = elt(env, 1); /* aeval */
    v16 = v17;
    v17 = qcdr(v16);
    v16 = elt(env, 2); /* where */
    fn = elt(env, 4); /* carx */
    v16 = (*qfn2(fn))(qenv(fn), v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    v16 = list2(stack[0], v16);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    v16 = Lmkquote(nil, v16);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    v16 = list2(stack[-1], v16);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    v17 = list2(stack[-2], v16);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    v16 = qvalue(elt(env, 3)); /* nil */
    {
        popv(4);
        fn = elt(env, 5); /* evalletsub */
        return (*qfn2(fn))(qenv(fn), v17, v16);
    }
/* error exit handlers */
v11:
    popv(4);
    return nil;
}



/* Code for sqfrf */

static Lisp_Object CC_sqfrf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v326, v327, v328, v329;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqfrf");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    stack[-7] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-5] = qvalue(elt(env, 2)); /* !*msg */
    qvalue(elt(env, 2)) = nil; /* !*msg */
    v326 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v326; /* !*gcd */
    v326 = qvalue(elt(env, 4)); /* !*rounded */
    stack[-1] = v326;
    if (v326 == nil) goto v38;
    v326 = elt(env, 5); /* rational */
    v326 = ncons(v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    fn = elt(env, 13); /* on */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v327 = stack[-9];
    v326 = (Lisp_Object)17; /* 1 */
    v326 = cons(v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    fn = elt(env, 14); /* resimp */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v326 = qcar(v326);
    stack[-9] = v326;
    goto v38;

v38:
    v326 = (Lisp_Object)17; /* 1 */
    stack[-10] = v326;
    v326 = stack[-9];
    v326 = qcar(v326);
    v326 = qcar(v326);
    v326 = qcar(v326);
    stack[-4] = v326;
    v326 = qvalue(elt(env, 3)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*ezgcd */
    qvalue(elt(env, 6)) = v326; /* !*ezgcd */
    stack[-6] = stack[-9];
    v327 = stack[-9];
    v326 = stack[-4];
    fn = elt(env, 15); /* diff */
    v326 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v331;
    env = stack[-11];
    fn = elt(env, 16); /* gcdf */
    v326 = (*qfn2(fn))(qenv(fn), stack[-6], v326);
    nil = C_nil;
    if (exception_pending()) goto v331;
    env = stack[-11];
    stack[-6] = v326;
    qvalue(elt(env, 6)) = stack[0]; /* !*ezgcd */
    v327 = stack[-9];
    v326 = stack[-6];
    fn = elt(env, 17); /* quotf */
    v326 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[-9] = v326;
    v327 = qvalue(elt(env, 7)); /* dmode!* */
    v326 = elt(env, 8); /* field */
    v326 = Lflagp(nil, v327, v326);
    env = stack[-11];
    if (v326 == nil) goto v179;
    v326 = stack[-9];
    fn = elt(env, 18); /* lnc */
    v327 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[-3] = v327;
    v326 = (Lisp_Object)17; /* 1 */
    v326 = Lneq(nil, v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    goto v7;

v7:
    if (v326 == nil) goto v291;
    v326 = stack[-3];
    fn = elt(env, 19); /* !:recip */
    v327 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v326 = stack[-9];
    fn = elt(env, 20); /* multd */
    v326 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[-9] = v326;
    v327 = stack[-3];
    v326 = stack[-6];
    fn = elt(env, 20); /* multd */
    v326 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[-6] = v326;
    goto v291;

v291:
    v327 = stack[-6];
    v326 = stack[-4];
    fn = elt(env, 21); /* degr */
    v327 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v326 = (Lisp_Object)1; /* 0 */
    v326 = (Lisp_Object)greaterp2(v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    v326 = v326 ? lisp_true : nil;
    env = stack[-11];
    if (v326 == nil) goto v219;
    v327 = stack[-6];
    v326 = stack[-9];
    fn = elt(env, 16); /* gcdf */
    v326 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[0] = v326;
    v327 = stack[-9];
    v326 = stack[0];
    if (equal(v327, v326)) goto v75;
    v327 = stack[-9];
    v326 = stack[0];
    fn = elt(env, 17); /* quotf */
    v328 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v327 = stack[-10];
    v326 = stack[-2];
    v326 = acons(v328, v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[-2] = v326;
    goto v75;

v75:
    v327 = stack[-6];
    v326 = stack[0];
    fn = elt(env, 17); /* quotf */
    v326 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[-6] = v326;
    v326 = stack[0];
    stack[-9] = v326;
    v326 = stack[-10];
    v326 = add1(v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[-10] = v326;
    goto v291;

v219:
    v326 = stack[-1];
    if (v326 == nil) goto v197;
    v326 = elt(env, 10); /* rounded */
    v326 = ncons(v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    fn = elt(env, 13); /* on */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v327 = stack[-9];
    v326 = (Lisp_Object)17; /* 1 */
    v326 = cons(v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    fn = elt(env, 14); /* resimp */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v326 = qcar(v326);
    stack[-9] = v326;
    v326 = stack[-2];
    stack[-4] = v326;
    v326 = stack[-4];
    if (v326 == nil) goto v273;
    v326 = stack[-4];
    v326 = qcar(v326);
    stack[0] = v326;
    v326 = stack[0];
    v327 = qcar(v326);
    v326 = (Lisp_Object)17; /* 1 */
    v326 = cons(v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    fn = elt(env, 14); /* resimp */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v327 = qcar(v326);
    v326 = stack[0];
    v326 = qcdr(v326);
    v326 = cons(v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v326 = ncons(v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[-2] = v326;
    stack[-3] = v326;
    goto v282;

v282:
    v326 = stack[-4];
    v326 = qcdr(v326);
    stack[-4] = v326;
    v326 = stack[-4];
    if (v326 == nil) goto v124;
    stack[-1] = stack[-2];
    v326 = stack[-4];
    v326 = qcar(v326);
    stack[0] = v326;
    v326 = stack[0];
    v327 = qcar(v326);
    v326 = (Lisp_Object)17; /* 1 */
    v326 = cons(v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    fn = elt(env, 14); /* resimp */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v327 = qcar(v326);
    v326 = stack[0];
    v326 = qcdr(v326);
    v326 = cons(v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v326 = ncons(v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v326 = Lrplacd(nil, stack[-1], v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v326 = stack[-2];
    v326 = qcdr(v326);
    stack[-2] = v326;
    goto v282;

v124:
    v326 = stack[-3];
    goto v332;

v332:
    stack[-2] = v326;
    goto v197;

v197:
    v327 = stack[-6];
    v326 = (Lisp_Object)17; /* 1 */
    if (v327 == v326) goto v333;
    v327 = stack[-6];
    v326 = stack[-7];
    v326 = Lassoc(nil, v327, v326);
    goto v334;

v334:
    if (v326 == nil) goto v188;
    v326 = (Lisp_Object)17; /* 1 */
    stack[-6] = v326;
    goto v188;

v188:
    v327 = stack[-6];
    v326 = (Lisp_Object)17; /* 1 */
    if (v327 == v326) goto v152;
    v327 = stack[-10];
    v326 = (Lisp_Object)17; /* 1 */
    if (v327 == v326) goto v335;
    v327 = (Lisp_Object)17; /* 1 */
    v326 = stack[-2];
    fn = elt(env, 22); /* rassoc */
    v326 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[0] = v326;
    if (v326 == nil) goto v224;
    stack[-1] = stack[0];
    v327 = stack[-6];
    v326 = stack[0];
    v326 = qcar(v326);
    fn = elt(env, 23); /* multf */
    v326 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v326 = Lrplaca(nil, stack[-1], v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    goto v152;

v152:
    v328 = stack[-9];
    v327 = stack[-10];
    v326 = stack[-2];
    v326 = acons(v328, v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    qvalue(elt(env, 2)) = stack[-5]; /* !*msg */
    qvalue(elt(env, 1)) = stack[-8]; /* !*gcd */
    { popv(12); return onevalue(v326); }

v224:
    v326 = stack[-2];
    if (v326 == nil) goto v336;
    v326 = qvalue(elt(env, 9)); /* nil */
    goto v337;

v337:
    if (v326 == nil) goto v338;
    v327 = stack[0];
    v326 = stack[-9];
    fn = elt(env, 23); /* multf */
    v326 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[-9] = v326;
    goto v152;

v338:
    v326 = stack[-6];
    if (!consp(v326)) goto v88;
    v326 = stack[-6];
    v326 = qcar(v326);
    v326 = (consp(v326) ? nil : lisp_true);
    goto v90;

v90:
    if (v326 == nil) goto v339;
    v329 = elt(env, 12); /* "sqfrf failure" */
    v328 = stack[-9];
    v327 = stack[-10];
    v326 = stack[-2];
    v326 = list4(v329, v328, v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    fn = elt(env, 24); /* errach */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    goto v152;

v339:
    stack[0] = stack[-2];
    v327 = stack[-6];
    v326 = (Lisp_Object)17; /* 1 */
    v326 = cons(v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v326 = ncons(v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    v326 = Lnconc(nil, stack[0], v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[-2] = v326;
    goto v152;

v88:
    v326 = qvalue(elt(env, 3)); /* t */
    goto v90;

v336:
    v327 = stack[-6];
    v326 = stack[-10];
    fn = elt(env, 25); /* rootxf */
    v327 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[0] = v327;
    v326 = elt(env, 11); /* failed */
    v326 = Lneq(nil, v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    goto v337;

v335:
    v327 = stack[-6];
    v326 = stack[-9];
    fn = elt(env, 23); /* multf */
    v326 = (*qfn2(fn))(qenv(fn), v327, v326);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-11];
    stack[-9] = v326;
    goto v152;

v333:
    v326 = qvalue(elt(env, 9)); /* nil */
    goto v334;

v273:
    v326 = qvalue(elt(env, 9)); /* nil */
    goto v332;

v179:
    v326 = qvalue(elt(env, 9)); /* nil */
    goto v7;
/* error exit handlers */
v331:
    env = stack[-11];
    qvalue(elt(env, 6)) = stack[0]; /* !*ezgcd */
    qvalue(elt(env, 2)) = stack[-5]; /* !*msg */
    qvalue(elt(env, 1)) = stack[-8]; /* !*gcd */
    popv(12);
    return nil;
v330:
    env = stack[-11];
    qvalue(elt(env, 2)) = stack[-5]; /* !*msg */
    qvalue(elt(env, 1)) = stack[-8]; /* !*gcd */
    popv(12);
    return nil;
}



/* Code for sfto_dprpartksf */

static Lisp_Object CC_sfto_dprpartksf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_dprpartksf");
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
    v154 = v0;
/* end of prologue */
    stack[0] = v154;
    fn = elt(env, 1); /* sfto_dcontentf */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-1];
    {
        Lisp_Object v229 = stack[0];
        popv(2);
        fn = elt(env, 2); /* quotf */
        return (*qfn2(fn))(qenv(fn), v229, v154);
    }
/* error exit handlers */
v225:
    popv(2);
    return nil;
}



/* Code for bc_sum */

static Lisp_Object CC_bc_sum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_sum");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v154 = v1;
    v153 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* addf */
        return (*qfn2(fn))(qenv(fn), v153, v154);
    }
}



/* Code for ps!:plus!-erule */

static Lisp_Object CC_psTplusKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:plus-erule");
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
    stack[0] = v0;
/* end of prologue */
    v35 = qvalue(elt(env, 1)); /* nil */
    v11 = (Lisp_Object)17; /* 1 */
    v11 = cons(v35, v11);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-3];
    v35 = v11;
    v11 = stack[0];
    v11 = qcdr(v11);
    stack[-2] = v11;
    goto v38;

v38:
    v11 = stack[-2];
    if (v11 == nil) { popv(4); return onevalue(v35); }
    v11 = stack[-2];
    v11 = qcar(v11);
    stack[0] = v35;
    v35 = v11;
    v11 = stack[-1];
    fn = elt(env, 2); /* ps!:evaluate */
    v11 = (*qfn2(fn))(qenv(fn), v35, v11);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-3];
    fn = elt(env, 3); /* addsq */
    v11 = (*qfn2(fn))(qenv(fn), stack[0], v11);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-3];
    v35 = v11;
    v11 = stack[-2];
    v11 = qcdr(v11);
    stack[-2] = v11;
    goto v38;
/* error exit handlers */
v292:
    popv(4);
    return nil;
}



/* Code for tchscheme */

static Lisp_Object MS_CDECL CC_tchscheme(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v340;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "tchscheme");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tchscheme");
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
    stack[-3] = nil;
    stack[-2] = nil;
    v240 = (Lisp_Object)1; /* 0 */
    stack[-1] = v240;
    goto v63;

v63:
    v340 = qvalue(elt(env, 1)); /* rowmax */
    v240 = stack[-1];
    v240 = difference2(v340, v240);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    v240 = Lminusp(nil, v240);
    env = stack[-4];
    if (!(v240 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v340 = qvalue(elt(env, 4)); /* maxvar */
    v240 = stack[-1];
    v240 = plus2(v340, v240);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    v340 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v240/(16/CELL)));
    v240 = (Lisp_Object)49; /* 3 */
    v340 = *(Lisp_Object *)((char *)v340 + (CELL-TAG_VECTOR) + ((int32_t)v240/(16/CELL)));
    v240 = (Lisp_Object)-15; /* -1 */
    if (v340 == v240) goto v272;
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v340 = qvalue(elt(env, 4)); /* maxvar */
    v240 = stack[-1];
    v240 = plus2(v340, v240);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    v340 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v240/(16/CELL)));
    v240 = (Lisp_Object)65; /* 4 */
    v240 = *(Lisp_Object *)((char *)v340 + (CELL-TAG_VECTOR) + ((int32_t)v240/(16/CELL)));
    stack[-3] = v240;
    if (v240 == nil) goto v146;
    v240 = stack[-3];
    v240 = qcdr(v240);
    if (v240 == nil) goto v138;
    v240 = qvalue(elt(env, 2)); /* nil */
    goto v181;

v181:
    if (v240 == nil) goto v177;
    v340 = stack[-1];
    v240 = stack[-3];
    v240 = qcar(v240);
    fn = elt(env, 6); /* chscheme */
    v240 = (*qfn2(fn))(qenv(fn), v340, v240);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    v240 = qvalue(elt(env, 5)); /* t */
    stack[-2] = v240;
    goto v177;

v177:
    v240 = stack[-1];
    v240 = add1(v240);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    stack[-1] = v240;
    goto v63;

v138:
    v340 = stack[-1];
    v240 = stack[-3];
    v240 = qcar(v240);
    v240 = qcdr(v240);
    v240 = qcar(v240);
    fn = elt(env, 7); /* transferrow */
    v240 = (*qfn2(fn))(qenv(fn), v340, v240);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    goto v181;

v146:
    v240 = qvalue(elt(env, 2)); /* nil */
    goto v181;

v272:
    v240 = qvalue(elt(env, 2)); /* nil */
    goto v181;
/* error exit handlers */
v141:
    popv(5);
    return nil;
}



/* Code for xnp */

static Lisp_Object CC_xnp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v143, v142, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xnp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v143 = v1;
    v142 = v0;
/* end of prologue */

v253:
    v15 = v142;
    if (v15 == nil) goto v19;
    v15 = v142;
    v37 = qcar(v15);
    v15 = v143;
    v15 = Lmemq(nil, v37, v15);
    if (!(v15 == nil)) return onevalue(v15);
    v15 = v142;
    v142 = qcdr(v15);
    v15 = v143;
    v143 = v15;
    goto v253;

v19:
    v15 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v15);
}



/* Code for rungekuttastep */

static Lisp_Object MS_CDECL CC_rungekuttastep(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v91,
                         Lisp_Object v6, Lisp_Object v19, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "rungekuttastep");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rungekuttastep");
#endif
    if (stack >= stacklimit)
    {
        push6(v19,v6,v91,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v2,v91,v6,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v19;
    stack[-6] = v6;
    stack[-7] = v91;
    stack[-8] = v2;
    stack[-9] = v1;
    stack[-10] = v0;
/* end of prologue */
    stack[-1] = stack[-10];
    stack[0] = stack[-9];
    v273 = stack[-8];
    v202 = stack[-7];
    v202 = cons(v273, v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    fn = elt(env, 1); /* list!-evaluate */
    v202 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    stack[-11] = v202;
    stack[-3] = stack[-10];
    stack[-2] = stack[-9];
    v273 = stack[-8];
    v202 = stack[-5];
    fn = elt(env, 2); /* !:plus */
    stack[-1] = (*qfn2(fn))(qenv(fn), v273, v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    stack[0] = stack[-7];
    v273 = stack[-5];
    v202 = stack[-11];
    fn = elt(env, 3); /* scal!*list */
    v202 = (*qfn2(fn))(qenv(fn), v273, v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    fn = elt(env, 4); /* list!+list */
    v202 = (*qfn2(fn))(qenv(fn), stack[0], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    v202 = cons(stack[-1], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    fn = elt(env, 1); /* list!-evaluate */
    v202 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-2], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    stack[-4] = v202;
    stack[-3] = stack[-10];
    stack[-2] = stack[-9];
    v273 = stack[-8];
    v202 = stack[-5];
    fn = elt(env, 2); /* !:plus */
    stack[-1] = (*qfn2(fn))(qenv(fn), v273, v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    stack[0] = stack[-7];
    v273 = stack[-5];
    v202 = stack[-4];
    fn = elt(env, 3); /* scal!*list */
    v202 = (*qfn2(fn))(qenv(fn), v273, v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    fn = elt(env, 4); /* list!+list */
    v202 = (*qfn2(fn))(qenv(fn), stack[0], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    v202 = cons(stack[-1], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    fn = elt(env, 1); /* list!-evaluate */
    v202 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-2], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    stack[-1] = v202;
    stack[-2] = stack[-10];
    stack[-3] = stack[-9];
    v273 = stack[-8];
    v202 = stack[-6];
    fn = elt(env, 2); /* !:plus */
    stack[-5] = (*qfn2(fn))(qenv(fn), v273, v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    stack[0] = stack[-7];
    v273 = stack[-6];
    v202 = stack[-1];
    fn = elt(env, 3); /* scal!*list */
    v202 = (*qfn2(fn))(qenv(fn), v273, v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    fn = elt(env, 4); /* list!+list */
    v202 = (*qfn2(fn))(qenv(fn), stack[0], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    v202 = cons(stack[-5], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    fn = elt(env, 1); /* list!-evaluate */
    v202 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-3], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    stack[0] = v202;
    stack[-2] = stack[-7];
    v273 = stack[-6];
    v202 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 5); /* !:!:quotient */
    stack[-3] = (*qfn2(fn))(qenv(fn), v273, v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    stack[-5] = stack[-11];
    v273 = (Lisp_Object)33; /* 2 */
    v202 = stack[-4];
    fn = elt(env, 3); /* scal!*list */
    stack[-4] = (*qfn2(fn))(qenv(fn), v273, v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    v273 = (Lisp_Object)33; /* 2 */
    v202 = stack[-1];
    fn = elt(env, 3); /* scal!*list */
    v273 = (*qfn2(fn))(qenv(fn), v273, v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    v202 = stack[0];
    fn = elt(env, 4); /* list!+list */
    v202 = (*qfn2(fn))(qenv(fn), v273, v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    fn = elt(env, 4); /* list!+list */
    v202 = (*qfn2(fn))(qenv(fn), stack[-4], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    fn = elt(env, 4); /* list!+list */
    v202 = (*qfn2(fn))(qenv(fn), stack[-5], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    fn = elt(env, 3); /* scal!*list */
    v202 = (*qfn2(fn))(qenv(fn), stack[-3], v202);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-12];
    {
        Lisp_Object v128 = stack[-2];
        popv(13);
        fn = elt(env, 4); /* list!+list */
        return (*qfn2(fn))(qenv(fn), v128, v202);
    }
/* error exit handlers */
v342:
    popv(13);
    return nil;
}



/* Code for compconj */

static Lisp_Object CC_compconj(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v185, v261;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compconj");
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
    v27 = stack[0];
    if (v27 == nil) goto v154;
    v27 = stack[0];
    v27 = (is_number(v27) ? lisp_true : nil);
    goto v191;

v191:
    if (!(v27 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v27 = stack[0];
    if (!(symbolp(v27))) goto v21;
    v185 = stack[0];
    v27 = elt(env, 2); /* rvalue */
    v27 = get(v185, v27);
    env = stack[-2];
    stack[-1] = v27;
    if (v27 == nil) goto v21;
    v185 = elt(env, 3); /* minus */
    v27 = elt(env, 4); /* i */
    v261 = list2(v185, v27);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    v185 = elt(env, 4); /* i */
    v27 = stack[-1];
    v27 = Lsubst(nil, 3, v261, v185, v27);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    stack[-1] = v27;
    v261 = stack[0];
    v185 = elt(env, 2); /* rvalue */
    v27 = stack[-1];
    v27 = Lputprop(nil, 3, v261, v185, v27);
    nil = C_nil;
    if (exception_pending()) goto v56;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v21:
    v185 = elt(env, 3); /* minus */
    v27 = elt(env, 4); /* i */
    v185 = list2(v185, v27);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    v261 = elt(env, 4); /* i */
    v27 = stack[0];
        popv(3);
        return Lsubst(nil, 3, v185, v261, v27);

v154:
    v27 = qvalue(elt(env, 1)); /* t */
    goto v191;
/* error exit handlers */
v56:
    popv(3);
    return nil;
}



/* Code for dvertex!-to!-projector */

static Lisp_Object MS_CDECL CC_dvertexKtoKprojector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v259, v258, v268;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dvertex-to-projector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvertex-to-projector");
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
    v259 = stack[-2];
    v259 = qcdr(v259);
    v268 = qcar(v259);
    v258 = stack[-1];
    v259 = stack[0];
    fn = elt(env, 1); /* mktails */
    v259 = (*qfnn(fn))(qenv(fn), 3, v268, v258, v259);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    stack[-3] = v259;
    v259 = stack[-3];
    v259 = qcar(v259);
    fn = elt(env, 2); /* repeatsp */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    if (v259 == nil) goto v15;
    v259 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v259); }

v15:
    v259 = stack[-2];
    v259 = qcdr(v259);
    v259 = qcdr(v259);
    v268 = qcar(v259);
    v258 = stack[-1];
    v259 = stack[-3];
    v259 = qcdr(v259);
    fn = elt(env, 1); /* mktails */
    v259 = (*qfnn(fn))(qenv(fn), 3, v268, v258, v259);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    stack[-1] = v259;
    v259 = stack[-1];
    v259 = qcar(v259);
    fn = elt(env, 2); /* repeatsp */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    if (v259 == nil) goto v11;
    v259 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v259); }

v11:
    v259 = stack[-1];
    v259 = qcdr(v259);
    stack[0] = v259;
    v259 = stack[-3];
    stack[-2] = qcar(v259);
    v259 = stack[-1];
    v259 = qcar(v259);
    v259 = Lreverse(nil, v259);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    fn = elt(env, 3); /* prop!-simp */
    v259 = (*qfn2(fn))(qenv(fn), stack[-2], v259);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    stack[-2] = v259;
    v259 = stack[-2];
    fn = elt(env, 4); /* mk!-contract!-coeff */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-4];
    stack[-1] = v259;
    v259 = stack[-2];
    v259 = qcdr(v259);
    v268 = qcar(v259);
    v259 = stack[-2];
    v259 = qcdr(v259);
    v258 = qcdr(v259);
    v259 = stack[0];
    fn = elt(env, 5); /* dpropagator */
    v259 = (*qfnn(fn))(qenv(fn), 3, v268, v258, v259);
    nil = C_nil;
    if (exception_pending()) goto v263;
    {
        Lisp_Object v245 = stack[-1];
        popv(5);
        return cons(v245, v259);
    }
/* error exit handlers */
v263:
    popv(5);
    return nil;
}



/* Code for dp!=prod */

static Lisp_Object CC_dpMprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=prod");
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
    v33 = v0;
/* end of prologue */
    v32 = v33;
    if (v32 == nil) goto v184;
    v32 = stack[-1];
    v32 = (v32 == nil ? lisp_true : nil);
    goto v24;

v24:
    if (v32 == nil) goto v238;
    v32 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v32); }

v238:
    stack[-2] = nil;
    v32 = v33;
    stack[0] = v32;
    goto v251;

v251:
    v32 = stack[0];
    if (v32 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v32 = stack[0];
    v32 = qcar(v32);
    v33 = v32;
    v146 = qcdr(v33);
    v33 = qcar(v32);
    v32 = stack[-1];
    fn = elt(env, 3); /* dp_times_bcmo */
    v33 = (*qfnn(fn))(qenv(fn), 3, v146, v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-3];
    v32 = stack[-2];
    fn = elt(env, 4); /* dp_sum */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-3];
    stack[-2] = v32;
    v32 = stack[0];
    v32 = qcdr(v32);
    stack[0] = v32;
    goto v251;

v184:
    v32 = qvalue(elt(env, 1)); /* t */
    goto v24;
/* error exit handlers */
v243:
    popv(4);
    return nil;
}



/* Code for algint!-subsublis */

static Lisp_Object CC_algintKsubsublis(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v157, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for algint-subsublis");
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
    stack[0] = v1;
    stack[-3] = v0;
/* end of prologue */
    v157 = stack[0];
    v137 = stack[-3];
    v137 = Lassoc(nil, v157, v137);
    v157 = v137;
    if (v137 == nil) goto v184;
    v137 = v157;
    v137 = qcdr(v137);
    { popv(6); return onevalue(v137); }

v184:
    v137 = stack[0];
    if (!consp(v137)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v137 = stack[0];
    v157 = qcar(v137);
    v137 = elt(env, 1); /* !*sq */
    if (v157 == v137) goto v37;
    v137 = stack[0];
    v157 = qcar(v137);
    v137 = elt(env, 2); /* subfunc */
    v137 = get(v157, v137);
    env = stack[-5];
    v157 = v137;
    if (v137 == nil) goto v30;
    v217 = v157;
    v157 = stack[-3];
    v137 = stack[0];
        popv(6);
        return Lapply2(nil, 3, v217, v157, v137);

v30:
    v137 = stack[0];
    stack[-4] = v137;
    v137 = stack[-4];
    if (v137 == nil) goto v68;
    v137 = stack[-4];
    v137 = qcar(v137);
    v157 = stack[-3];
    v137 = CC_algintKsubsublis(env, v157, v137);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    v137 = ncons(v137);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    stack[-1] = v137;
    stack[-2] = v137;
    goto v156;

v156:
    v137 = stack[-4];
    v137 = qcdr(v137);
    stack[-4] = v137;
    v137 = stack[-4];
    if (v137 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v137 = stack[-4];
    v137 = qcar(v137);
    v157 = stack[-3];
    v137 = CC_algintKsubsublis(env, v157, v137);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    v137 = ncons(v137);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    v137 = Lrplacd(nil, stack[0], v137);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    v137 = stack[-1];
    v137 = qcdr(v137);
    stack[-1] = v137;
    goto v156;

v68:
    v137 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v137); }

v37:
    stack[-1] = elt(env, 1); /* !*sq */
    v137 = stack[0];
    v137 = qcdr(v137);
    v157 = qcar(v137);
    v137 = stack[-3];
    fn = elt(env, 4); /* algint!-subsq */
    v157 = (*qfn2(fn))(qenv(fn), v157, v137);
    nil = C_nil;
    if (exception_pending()) goto v271;
    v137 = stack[0];
    v137 = qcdr(v137);
    v137 = qcdr(v137);
    v137 = qcar(v137);
    {
        Lisp_Object v343 = stack[-1];
        popv(6);
        return list3(v343, v157, v137);
    }
/* error exit handlers */
v271:
    popv(6);
    return nil;
}



/* Code for gcdchk */

static Lisp_Object CC_gcdchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v292;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdchk");
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
    v25 = stack[-1];
    v292 = qcar(v25);
    v25 = stack[-1];
    v25 = qcdr(v25);
    fn = elt(env, 1); /* gcdf */
    v25 = (*qfn2(fn))(qenv(fn), v292, v25);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-3];
    stack[-2] = v25;
    v292 = stack[-2];
    v25 = (Lisp_Object)17; /* 1 */
    if (v292 == v25) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v25 = stack[-1];
    v292 = qcar(v25);
    v25 = stack[-2];
    fn = elt(env, 2); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v292, v25);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-3];
    v25 = stack[-1];
    v292 = qcdr(v25);
    v25 = stack[-2];
    fn = elt(env, 2); /* quotf */
    v25 = (*qfn2(fn))(qenv(fn), v292, v25);
    nil = C_nil;
    if (exception_pending()) goto v236;
    {
        Lisp_Object v237 = stack[0];
        popv(4);
        return cons(v237, v25);
    }
/* error exit handlers */
v236:
    popv(4);
    return nil;
}



/* Code for preptaylor!* */

static Lisp_Object CC_preptaylorH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v238, v246, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaylor*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v238 = v0;
/* end of prologue */
    v246 = v238;
    v246 = qcdr(v246);
    v148 = qcar(v246);
    v238 = qcdr(v238);
    v238 = qcdr(v238);
    v246 = qcar(v238);
    v238 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* preptaylor!*1 */
        return (*qfnn(fn))(qenv(fn), 3, v148, v246, v238);
    }
}



/* Code for get_dim_irred_reps */

static Lisp_Object CC_get_dim_irred_reps(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v15, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_dim_irred_reps");
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
    v15 = v1;
    v143 = v0;
/* end of prologue */
    v221 = qvalue(elt(env, 1)); /* !*complex */
    if (v221 == nil) goto v10;
    v221 = v143;
    fn = elt(env, 2); /* get!*complex!*irreducible!*rep */
    v221 = (*qfn2(fn))(qenv(fn), v221, v15);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[0];
    goto v41;

v41:
    {
        popv(1);
        fn = elt(env, 3); /* get_dimension_in */
        return (*qfn1(fn))(qenv(fn), v221);
    }

v10:
    v221 = v143;
    fn = elt(env, 4); /* get!*real!*irreducible!*rep */
    v221 = (*qfn2(fn))(qenv(fn), v221, v15);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[0];
    goto v41;
/* error exit handlers */
v142:
    popv(1);
    return nil;
}



setup_type const u56_setup[] =
{
    {"intargfn",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_intargfn},
    {"simpfourier1",            CC_simpfourier1,too_many_1,    wrong_no_1},
    {"dp_from_a",               CC_dp_from_a,   too_many_1,    wrong_no_1},
    {"invbase",                 CC_invbase,     too_many_1,    wrong_no_1},
    {"ggvars2",                 too_few_2,      CC_ggvars2,    wrong_no_2},
    {"nrootnn",                 too_few_2,      CC_nrootnn,    wrong_no_2},
    {"evaluate-in-vector",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluateKinKvector},
    {"repr_atfnew",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_repr_atfnew},
    {"aex_1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_1},
    {"partialdiff",             too_few_2,      CC_partialdiff,wrong_no_2},
    {"transferrow",             too_few_2,      CC_transferrow,wrong_no_2},
    {"xregister_spoly_pair",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_xregister_spoly_pair},
    {"evalsetbool",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_evalsetbool},
    {"gcdlist1",                CC_gcdlist1,    too_many_1,    wrong_no_1},
    {"drop_dec_with",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_drop_dec_with},
    {"stp",                     CC_stp,         too_many_1,    wrong_no_1},
    {"rappend",                 CC_rappend,     too_many_1,    wrong_no_1},
    {"polineqcheck",            too_few_2,      CC_polineqcheck,wrong_no_2},
    {"reduce-mod-eig",          too_few_2,      CC_reduceKmodKeig,wrong_no_2},
    {"evalwhereexp",            CC_evalwhereexp,too_many_1,    wrong_no_1},
    {"sqfrf",                   CC_sqfrf,       too_many_1,    wrong_no_1},
    {"sfto_dprpartksf",         CC_sfto_dprpartksf,too_many_1, wrong_no_1},
    {"bc_sum",                  too_few_2,      CC_bc_sum,     wrong_no_2},
    {"ps:plus-erule",           too_few_2,      CC_psTplusKerule,wrong_no_2},
    {"tchscheme",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_tchscheme},
    {"xnp",                     too_few_2,      CC_xnp,        wrong_no_2},
    {"rungekuttastep",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_rungekuttastep},
    {"compconj",                CC_compconj,    too_many_1,    wrong_no_1},
    {"dvertex-to-projector",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvertexKtoKprojector},
    {"dp=prod",                 too_few_2,      CC_dpMprod,    wrong_no_2},
    {"algint-subsublis",        too_few_2,      CC_algintKsubsublis,wrong_no_2},
    {"gcdchk",                  CC_gcdchk,      too_many_1,    wrong_no_1},
    {"preptaylor*",             CC_preptaylorH, too_many_1,    wrong_no_1},
    {"get_dim_irred_reps",      too_few_2,      CC_get_dim_irred_reps,wrong_no_2},
    {NULL, (one_args *)"u56", (two_args *)"11938 7674189 3694909", 0}
};

/* end of generated code */
