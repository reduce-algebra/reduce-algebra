
/* $destdir\u20.c        Machine generated C code */

/* Signature: 00000000 22-Jan-2014 */

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
#define TYPE_FOREIGN        TYPE_SPARE 
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
#ifdef DEBUG
#define SHOW_FNAME  (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_ARGS) != 0)
#else
#define SHOW_FNAME  ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   ((exit_reason & UNWIND_ARGS) != 0)
#endif
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
extern Lisp_Object multiplication_buffer;
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
extern Lisp_Object gchook, resources, callstack, procstack, procmem, trap_time;
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
#define trap_time             BASE[158]
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
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
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
extern void *extract_pointer(Lisp_Object a);
extern Lisp_Object Lencapsulatedp(Lisp_Object nil, Lisp_Object a);
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
#define _pi       ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi  ((12868.0 - 0.036490896206895257)/8192.0)
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
extern Lisp_Object make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_lisp_integer32(int32_t n);
extern Lisp_Object make_lisp_integer64(int64_t n);
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
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG    LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG    void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);
#endif
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
             kara_sem2a, kara_sem2b, kara_sem2c;
extern int karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
#  define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
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
extern Lisp_Object bytecounts1(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object Lthrow_nil(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object Lthrow_one_value(Lisp_Object env, Lisp_Object a, Lisp_Object b);
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


/* Code for lalr_set_grammar */

static Lisp_Object CC_lalr_set_grammar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0103, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_set_grammar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0102 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v0102; /* symbols */
    qvalue(elt(env, 3)) = v0102; /* non_terminals */
    qvalue(elt(env, 4)) = v0102; /* terminals */
    stack[-1] = elt(env, 5); /* s!' */
    v0102 = stack[0];
    v0102 = qcar(v0102);
    v0102 = qcar(v0102);
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0103 = list2(stack[-1], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = stack[0];
    v0102 = cons(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    stack[0] = v0102;
    v0102 = stack[0];
    stack[-3] = v0102;
    goto v0106;

v0106:
    v0102 = stack[-3];
    if (v0102 == nil) goto v0107;
    v0102 = stack[-3];
    v0102 = qcar(v0102);
    stack[0] = v0102;
    v0102 = stack[0];
    v0102 = qcar(v0102);
    stack[-6] = v0102;
    v0102 = stack[0];
    v0102 = qcdr(v0102);
    stack[-5] = v0102;
    v0103 = stack[-6];
    v0102 = qvalue(elt(env, 3)); /* non_terminals */
    v0102 = Lmember(nil, v0103, v0102);
    if (v0102 == nil) goto v0108;
    v0104 = stack[-5];
    v0103 = stack[-6];
    v0102 = elt(env, 6); /* produces */
    v0102 = get(v0103, v0102);
    env = stack[-8];
    v0102 = Lappend(nil, v0104, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    stack[-5] = v0102;
    goto v0109;

v0109:
    v0102 = stack[0];
    v0102 = qcdr(v0102);
    stack[-2] = v0102;
    goto v0110;

v0110:
    v0102 = stack[-2];
    if (v0102 == nil) goto v0111;
    v0102 = stack[-2];
    v0102 = qcar(v0102);
    v0102 = qcar(v0102);
    stack[-1] = v0102;
    goto v0112;

v0112:
    v0102 = stack[-1];
    if (v0102 == nil) goto v0113;
    v0102 = stack[-1];
    v0102 = qcar(v0102);
    stack[0] = v0102;
    v0102 = stack[0];
    v0102 = Lstringp(nil, v0102);
    env = stack[-8];
    if (v0102 == nil) goto v0114;
    v0102 = stack[0];
    fn = elt(env, 22); /* explodecn */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    stack[-4] = v0102;
    v0102 = qcdr(v0102);
    if (v0102 == nil) goto v0115;
    v0102 = stack[0];
    v0102 = Lintern(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    stack[0] = v0102;
    goto v0114;

v0114:
    v0103 = stack[0];
    v0102 = qvalue(elt(env, 2)); /* symbols */
    v0102 = Lmember(nil, v0103, v0102);
    if (!(v0102 == nil)) goto v0116;
    v0103 = stack[0];
    v0102 = qvalue(elt(env, 2)); /* symbols */
    v0102 = cons(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    qvalue(elt(env, 2)) = v0102; /* symbols */
    goto v0116;

v0116:
    v0102 = stack[-1];
    v0102 = qcdr(v0102);
    stack[-1] = v0102;
    goto v0112;

v0115:
    v0104 = elt(env, 7); /* !! */
    v0103 = elt(env, 8); /* !: */
    v0102 = stack[-4];
    v0102 = list2star(v0104, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = Lcompress(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = Lintern(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    stack[0] = v0102;
    v0102 = elt(env, 9); /* "One-character string found <" */
    v0102 = Lprinc(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = stack[0];
    v0102 = Lprinc(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = elt(env, 10); /* "> with code " */
    v0102 = Lprinc(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = stack[-4];
    v0102 = qcar(v0102);
    v0102 = Lprintc(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0104 = stack[0];
    v0103 = elt(env, 11); /* lex_code */
    v0102 = stack[-4];
    v0102 = qcar(v0102);
    v0102 = Lputprop(nil, 3, v0104, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    goto v0114;

v0113:
    v0102 = stack[-2];
    v0102 = qcdr(v0102);
    stack[-2] = v0102;
    goto v0110;

v0111:
    v0104 = stack[-6];
    v0103 = elt(env, 6); /* produces */
    v0102 = stack[-5];
    v0102 = Lputprop(nil, 3, v0104, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = stack[-3];
    v0102 = qcdr(v0102);
    stack[-3] = v0102;
    goto v0106;

v0108:
    v0103 = stack[-6];
    v0102 = qvalue(elt(env, 3)); /* non_terminals */
    v0102 = cons(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    qvalue(elt(env, 3)) = v0102; /* non_terminals */
    goto v0109;

v0107:
    v0102 = qvalue(elt(env, 3)); /* non_terminals */
    stack[0] = v0102;
    goto v0117;

v0117:
    v0102 = stack[0];
    if (v0102 == nil) goto v0118;
    v0102 = stack[0];
    v0102 = qcar(v0102);
    v0103 = v0102;
    v0102 = qvalue(elt(env, 2)); /* symbols */
    v0102 = Ldelete(nil, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    qvalue(elt(env, 2)) = v0102; /* symbols */
    v0102 = stack[0];
    v0102 = qcdr(v0102);
    stack[0] = v0102;
    goto v0117;

v0118:
    v0102 = qvalue(elt(env, 2)); /* symbols */
    stack[-1] = v0102;
    goto v0119;

v0119:
    v0102 = stack[-1];
    if (v0102 == nil) goto v0120;
    v0102 = stack[-1];
    v0102 = qcar(v0102);
    stack[0] = v0102;
    v0103 = stack[0];
    v0102 = elt(env, 11); /* lex_code */
    v0102 = get(v0103, v0102);
    env = stack[-8];
    if (!(v0102 == nil)) goto v0121;
    v0104 = stack[0];
    v0103 = elt(env, 11); /* lex_code */
    v0102 = qvalue(elt(env, 12)); /* next_lex_code */
    v0102 = Lputprop(nil, 3, v0104, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = qvalue(elt(env, 12)); /* next_lex_code */
    v0102 = add1(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    qvalue(elt(env, 12)) = v0102; /* next_lex_code */
    goto v0121;

v0121:
    v0103 = stack[0];
    v0104 = stack[0];
    v0102 = elt(env, 11); /* lex_code */
    v0104 = get(v0104, v0102);
    env = stack[-8];
    v0102 = qvalue(elt(env, 4)); /* terminals */
    v0102 = acons(v0103, v0104, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    qvalue(elt(env, 4)) = v0102; /* terminals */
    v0102 = stack[-1];
    v0102 = qcdr(v0102);
    stack[-1] = v0102;
    goto v0119;

v0120:
    v0102 = qvalue(elt(env, 3)); /* non_terminals */
    v0102 = Lnreverse(nil, v0102);
    env = stack[-8];
    qvalue(elt(env, 3)) = v0102; /* non_terminals */
    v0102 = (Lisp_Object)-15; /* -1 */
    stack[-4] = v0102;
    v0102 = qvalue(elt(env, 3)); /* non_terminals */
    stack[-2] = v0102;
    goto v0122;

v0122:
    v0102 = stack[-2];
    if (v0102 == nil) goto v0123;
    v0102 = stack[-2];
    v0102 = qcar(v0102);
    stack[-1] = v0102;
    stack[0] = elt(env, 13); /* non_terminal_code */
    v0102 = stack[-4];
    v0102 = add1(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    stack[-4] = v0102;
    v0102 = Lputprop(nil, 3, stack[-1], stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = stack[-2];
    v0102 = qcdr(v0102);
    stack[-2] = v0102;
    goto v0122;

v0123:
    stack[-4] = qvalue(elt(env, 3)); /* non_terminals */
    v0102 = qvalue(elt(env, 4)); /* terminals */
    stack[-3] = v0102;
    v0102 = stack[-3];
    if (v0102 == nil) goto v0124;
    v0102 = stack[-3];
    v0102 = qcar(v0102);
    v0102 = qcdr(v0102);
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    stack[-1] = v0102;
    stack[-2] = v0102;
    goto v0125;

v0125:
    v0102 = stack[-3];
    v0102 = qcdr(v0102);
    stack[-3] = v0102;
    v0102 = stack[-3];
    if (v0102 == nil) goto v0126;
    stack[0] = stack[-1];
    v0102 = stack[-3];
    v0102 = qcar(v0102);
    v0102 = qcdr(v0102);
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = Lrplacd(nil, stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = stack[-1];
    v0102 = qcdr(v0102);
    stack[-1] = v0102;
    goto v0125;

v0126:
    v0102 = stack[-2];
    goto v0127;

v0127:
    v0102 = Lappend(nil, stack[-4], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    qvalue(elt(env, 2)) = v0102; /* symbols */
    v0102 = qvalue(elt(env, 3)); /* non_terminals */
    v0104 = Llength(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0103 = (Lisp_Object)17; /* 1 */
    v0102 = elt(env, 14); /* 1.5 */
    fn = elt(env, 23); /* mkhash */
    v0102 = (*qfnn(fn))(qenv(fn), 3, v0104, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    qvalue(elt(env, 15)) = v0102; /* goto_cache */
    v0102 = qvalue(elt(env, 16)); /* !*lalr_verbose */
    if (v0102 == nil) goto v0128;
    fn = elt(env, 24); /* lalr_display_symbols */
    v0102 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    goto v0128;

v0128:
    v0102 = qvalue(elt(env, 3)); /* non_terminals */
    stack[-7] = v0102;
    goto v0129;

v0129:
    v0102 = stack[-7];
    if (v0102 == nil) goto v0130;
    v0102 = stack[-7];
    v0102 = qcar(v0102);
    stack[-6] = v0102;
    stack[-5] = elt(env, 6); /* produces */
    v0103 = v0102;
    v0102 = elt(env, 6); /* produces */
    v0102 = get(v0103, v0102);
    env = stack[-8];
    stack[-4] = v0102;
    v0102 = stack[-4];
    if (v0102 == nil) goto v0131;
    v0102 = stack[-4];
    v0102 = qcar(v0102);
    stack[0] = v0102;
    v0103 = qvalue(elt(env, 4)); /* terminals */
    v0102 = stack[0];
    v0102 = qcar(v0102);
    v0103 = Lsublis(nil, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = stack[0];
    v0102 = qcdr(v0102);
    v0102 = cons(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    stack[-2] = v0102;
    stack[-3] = v0102;
    goto v0132;

v0132:
    v0102 = stack[-4];
    v0102 = qcdr(v0102);
    stack[-4] = v0102;
    v0102 = stack[-4];
    if (v0102 == nil) goto v0133;
    stack[-1] = stack[-2];
    v0102 = stack[-4];
    v0102 = qcar(v0102);
    stack[0] = v0102;
    v0103 = qvalue(elt(env, 4)); /* terminals */
    v0102 = stack[0];
    v0102 = qcar(v0102);
    v0103 = Lsublis(nil, v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = stack[0];
    v0102 = qcdr(v0102);
    v0102 = cons(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = Lrplacd(nil, stack[-1], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = stack[-2];
    v0102 = qcdr(v0102);
    stack[-2] = v0102;
    goto v0132;

v0133:
    v0102 = stack[-3];
    goto v0134;

v0134:
    v0102 = Lputprop(nil, 3, stack[-6], stack[-5], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = stack[-7];
    v0102 = qcdr(v0102);
    stack[-7] = v0102;
    goto v0129;

v0131:
    v0102 = qvalue(elt(env, 1)); /* nil */
    goto v0134;

v0130:
    v0102 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 17)) = v0102; /* action_map */
    v0102 = (Lisp_Object)-15; /* -1 */
    stack[-4] = v0102;
    v0102 = qvalue(elt(env, 3)); /* non_terminals */
    stack[-2] = v0102;
    goto v0135;

v0135:
    v0102 = stack[-2];
    if (v0102 == nil) goto v0136;
    v0102 = stack[-2];
    v0102 = qcar(v0102);
    v0103 = v0102;
    v0102 = elt(env, 6); /* produces */
    v0102 = get(v0103, v0102);
    env = stack[-8];
    stack[-1] = v0102;
    goto v0137;

v0137:
    v0102 = stack[-1];
    if (v0102 == nil) goto v0138;
    v0102 = stack[-1];
    v0102 = qcar(v0102);
    stack[0] = v0102;
    v0102 = stack[0];
    v0103 = qcdr(v0102);
    v0102 = qvalue(elt(env, 17)); /* action_map */
    v0102 = Lassoc(nil, v0103, v0102);
    stack[-3] = v0102;
    v0102 = stack[-3];
    if (!(v0102 == nil)) goto v0139;
    v0102 = stack[0];
    stack[-3] = qcdr(v0102);
    v0102 = stack[-4];
    v0102 = add1(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    stack[-4] = v0102;
    v0102 = cons(stack[-3], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    stack[-3] = v0102;
    v0103 = stack[-3];
    v0102 = qvalue(elt(env, 17)); /* action_map */
    v0102 = cons(v0103, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    qvalue(elt(env, 17)) = v0102; /* action_map */
    goto v0139;

v0139:
    v0102 = stack[-3];
    v0102 = qcdr(v0102);
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = Lrplacd(nil, stack[0], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    v0102 = stack[-1];
    v0102 = qcdr(v0102);
    stack[-1] = v0102;
    goto v0137;

v0138:
    v0102 = stack[-2];
    v0102 = qcdr(v0102);
    stack[-2] = v0102;
    goto v0135;

v0136:
    v0102 = qvalue(elt(env, 17)); /* action_map */
    v0102 = Lnreverse(nil, v0102);
    env = stack[-8];
    qvalue(elt(env, 17)) = v0102; /* action_map */
    v0102 = stack[-4];
    v0102 = Lmkvect(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    qvalue(elt(env, 18)) = v0102; /* action_fn */
    v0102 = stack[-4];
    fn = elt(env, 25); /* mkvect8 */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    qvalue(elt(env, 19)) = v0102; /* action_n */
    v0102 = stack[-4];
    fn = elt(env, 26); /* mkvect16 */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    qvalue(elt(env, 20)) = v0102; /* action_a */
    v0102 = stack[-4];
    qvalue(elt(env, 21)) = v0102; /* action_first_error */
    v0102 = qvalue(elt(env, 16)); /* !*lalr_verbose */
    if (v0102 == nil) goto v0140;
    fn = elt(env, 27); /* lalr_print_action_map */
    v0102 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-8];
    goto v0140;

v0140:
    v0102 = qvalue(elt(env, 3)); /* non_terminals */
    fn = elt(env, 28); /* lalr_calculate_first */
    v0102 = (*qfn1(fn))(qenv(fn), v0102);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    v0102 = nil;
    { popv(9); return onevalue(v0102); }

v0124:
    v0102 = qvalue(elt(env, 1)); /* nil */
    goto v0127;
/* error exit handlers */
v0105:
    popv(9);
    return nil;
}



/* Code for formcond1 */

static Lisp_Object MS_CDECL CC_formcond1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0150, v0151;
    Lisp_Object fn;
    Lisp_Object v0074, v0146, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formcond1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0146 = va_arg(aa, Lisp_Object);
    v0074 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formcond1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0074,v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0146,v0074);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0074;
    stack[-2] = v0146;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    goto v0152;

v0152:
    v0149 = stack[-3];
    if (v0149 == nil) goto v0153;
    v0149 = stack[-3];
    v0149 = qcar(v0149);
    v0151 = qcar(v0149);
    v0150 = stack[-2];
    v0149 = stack[-1];
    fn = elt(env, 1); /* formbool */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0151, v0150, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    v0149 = stack[-3];
    v0149 = qcar(v0149);
    v0149 = qcdr(v0149);
    v0151 = qcar(v0149);
    v0150 = stack[-2];
    v0149 = stack[-1];
    fn = elt(env, 2); /* formc */
    v0149 = (*qfnn(fn))(qenv(fn), 3, v0151, v0150, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    v0150 = list2(stack[0], v0149);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    v0149 = stack[-4];
    v0149 = cons(v0150, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-5];
    stack[-4] = v0149;
    v0149 = stack[-3];
    v0149 = qcdr(v0149);
    stack[-3] = v0149;
    goto v0152;

v0153:
    v0149 = stack[-4];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0149);
    }
/* error exit handlers */
v0154:
    popv(6);
    return nil;
}



/* Code for delete_from_alglist */

static Lisp_Object CC_delete_from_alglist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0146)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0157, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delete_from_alglist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0146);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0146;
    v0100 = v0000;
/* end of prologue */
    v0157 = stack[0];
    if (v0157 == nil) goto v0004;
    v0157 = stack[0];
    fn = elt(env, 2); /* remhash */
    v0157 = (*qfn2(fn))(qenv(fn), v0100, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v0004:
    v0157 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0157); }
/* error exit handlers */
v0141:
    popv(1);
    return nil;
}



/* Code for lx2xx */

static Lisp_Object CC_lx2xx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0162, v0163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lx2xx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    v0162 = stack[-2];
    if (!consp(v0162)) goto v0164;
    v0162 = stack[-2];
    v0162 = qcar(v0162);
    v0162 = (consp(v0162) ? nil : lisp_true);
    goto v0098;

v0098:
    if (v0162 == nil) goto v0165;
    v0162 = qvalue(elt(env, 1)); /* t */
    goto v0166;

v0166:
    if (!(v0162 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0162 = stack[-2];
    v0162 = qcdr(v0162);
    v0162 = qcar(v0162);
    stack[-3] = v0162;
    v0162 = stack[-3];
    fn = elt(env, 2); /* lastnondomain */
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-4];
    v0162 = qcdr(v0162);
    stack[-1] = v0162;
    v0162 = stack[-2];
    stack[0] = qcar(v0162);
    v0163 = stack[-1];
    v0162 = stack[-3];
    fn = elt(env, 3); /* delet */
    v0162 = (*qfn2(fn))(qenv(fn), v0163, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-4];
    fn = elt(env, 4); /* xxsort */
    v0163 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-4];
    v0162 = stack[-1];
    v0163 = Lappend(nil, v0163, v0162);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    v0162 = stack[-2];
    v0162 = qcdr(v0162);
    v0162 = qcdr(v0162);
    {
        Lisp_Object v0167 = stack[0];
        popv(5);
        return list2star(v0167, v0163, v0162);
    }

v0165:
    v0162 = stack[-2];
    v0162 = qcar(v0162);
    if (!consp(v0162)) goto v0107;
    v0162 = stack[-2];
    v0162 = qcar(v0162);
    v0162 = qcar(v0162);
    v0162 = (consp(v0162) ? nil : lisp_true);
    goto v0166;

v0107:
    v0162 = qvalue(elt(env, 1)); /* t */
    goto v0166;

v0164:
    v0162 = qvalue(elt(env, 1)); /* t */
    goto v0098;
/* error exit handlers */
v0087:
    popv(5);
    return nil;
}



/* Code for ev_revgradlexcomp */

static Lisp_Object CC_ev_revgradlexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0146)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0174, v0175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_revgradlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0146);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0146;
    stack[-2] = v0000;
/* end of prologue */

v0176:
    v0174 = stack[-2];
    if (v0174 == nil) goto v0177;
    v0174 = stack[-2];
    v0175 = qcar(v0174);
    v0174 = stack[-1];
    v0174 = qcar(v0174);
    fn = elt(env, 1); /* iequal */
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    if (v0174 == nil) goto v0161;
    v0174 = stack[-2];
    v0175 = qcdr(v0174);
    v0174 = stack[-1];
    v0174 = qcdr(v0174);
    stack[-2] = v0175;
    stack[-1] = v0174;
    goto v0176;

v0161:
    v0174 = stack[-2];
    fn = elt(env, 2); /* ev_tdeg */
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    stack[-3] = v0174;
    v0174 = stack[-1];
    fn = elt(env, 2); /* ev_tdeg */
    v0174 = (*qfn1(fn))(qenv(fn), v0174);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    stack[0] = v0174;
    v0175 = stack[-3];
    v0174 = stack[0];
    fn = elt(env, 1); /* iequal */
    v0174 = (*qfn2(fn))(qenv(fn), v0175, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    if (v0174 == nil) goto v0092;
    v0175 = stack[-2];
    v0174 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* ev_invlexcomp */
        return (*qfn2(fn))(qenv(fn), v0175, v0174);
    }

v0092:
    v0175 = stack[-3];
    v0174 = stack[0];
    if (((int32_t)(v0175)) > ((int32_t)(v0174))) goto v0179;
    v0174 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0174); }

v0179:
    v0174 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0174); }

v0177:
    v0174 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v0174); }
/* error exit handlers */
v0178:
    popv(5);
    return nil;
}



/* Code for unaryrd */

static Lisp_Object MS_CDECL CC_unaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "unaryrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unaryrd");
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
    fn = elt(env, 1); /* mathml */
    v0180 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-1];
    stack[0] = v0180;
    fn = elt(env, 2); /* lex */
    v0180 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    v0180 = stack[0];
    popv(2);
    return ncons(v0180);
/* error exit handlers */
v0153:
    popv(2);
    return nil;
}



/* Code for cr!:prep */

static Lisp_Object CC_crTprep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0106, v0182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cr:prep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0182 = elt(env, 1); /* !:rd!: */
    v0106 = stack[0];
    v0106 = qcdr(v0106);
    v0106 = qcar(v0106);
    v0106 = cons(v0182, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0106);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    v0182 = elt(env, 1); /* !:rd!: */
    v0106 = stack[0];
    v0106 = qcdr(v0106);
    v0106 = qcdr(v0106);
    v0106 = cons(v0182, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    v0106 = (*qfn1(fn))(qenv(fn), v0106);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    v0106 = cons(stack[-1], v0106);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* crprep1 */
        return (*qfn1(fn))(qenv(fn), v0106);
    }
/* error exit handlers */
v0183:
    popv(3);
    return nil;
}



/* Code for take!-impart */

static Lisp_Object CC_takeKimpart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0185, v0161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for take-impart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0185 = stack[0];
    v0185 = qcar(v0185);
    fn = elt(env, 1); /* impartf */
    v0161 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    v0185 = stack[0];
    v0185 = qcdr(v0185);
    popv(1);
    return cons(v0161, v0185);
/* error exit handlers */
v0164:
    popv(1);
    return nil;
}



/* Code for oprinla */

static Lisp_Object CC_oprinla(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0187, v0188, v0189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for oprinla");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0188 = v0000;
/* end of prologue */
    v0189 = v0188;
    v0187 = elt(env, 1); /* lapr */
    v0187 = get(v0189, v0187);
    env = stack[0];
    v0189 = v0187;
    if (v0187 == nil) goto v0180;
    v0187 = v0189;
    fn = elt(env, 4); /* prin2la */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    goto v0191;

v0191:
    v0187 = nil;
    { popv(1); return onevalue(v0187); }

v0180:
    v0187 = v0188;
    if (!symbolp(v0187)) v0187 = nil;
    else { v0187 = qfastgets(v0187);
           if (v0187 != nil) { v0187 = elt(v0187, 37); /* prtch */
#ifdef RECORD_GET
             if (v0187 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0187 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0187 == SPID_NOPROP) v0187 = nil; }}
#endif
    v0189 = v0187;
    if (v0187 == nil) goto v0097;
    v0187 = v0189;
    fn = elt(env, 4); /* prin2la */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    goto v0191;

v0097:
    v0189 = v0188;
    v0187 = elt(env, 2); /* lapop */
    v0187 = get(v0189, v0187);
    env = stack[0];
    v0189 = v0187;
    if (v0187 == nil) goto v0148;
    v0187 = v0189;
    fn = elt(env, 4); /* prin2la */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[0];
    v0187 = elt(env, 3); /* !  */
    fn = elt(env, 4); /* prin2la */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    goto v0191;

v0148:
    v0187 = v0188;
    fn = elt(env, 5); /* prinlatom */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    goto v0191;
/* error exit handlers */
v0190:
    popv(1);
    return nil;
}



/* Code for setel1 */

static Lisp_Object MS_CDECL CC_setel1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0193, v0194, v0195;
    Lisp_Object fn;
    Lisp_Object v0073, v0074, v0146, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setel1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0146 = va_arg(aa, Lisp_Object);
    v0074 = va_arg(aa, Lisp_Object);
    v0073 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setel1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0073,v0074,v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0146,v0074,v0073);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0073;
    stack[-1] = v0074;
    stack[-2] = v0146;
    stack[-3] = v0000;
/* end of prologue */

v0152:
    v0193 = stack[-2];
    v0193 = qcar(v0193);
    v0193 = integerp(v0193);
    if (v0193 == nil) goto v0164;
    v0193 = stack[-2];
    v0194 = qcar(v0193);
    v0193 = stack[0];
    v0193 = qcar(v0193);
    v0193 = (Lisp_Object)geq2(v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    v0193 = v0193 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0193 == nil)) goto v0197;
    v0193 = stack[-2];
    v0194 = qcar(v0193);
    v0193 = (Lisp_Object)1; /* 0 */
    v0193 = (Lisp_Object)lessp2(v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    v0193 = v0193 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0193 == nil)) goto v0197;
    v0193 = stack[-2];
    v0193 = qcdr(v0193);
    if (v0193 == nil) goto v0198;
    v0194 = stack[-3];
    v0193 = stack[-2];
    v0193 = qcar(v0193);
    v0193 = *(Lisp_Object *)((char *)v0194 + (CELL-TAG_VECTOR) + ((int32_t)v0193/(16/CELL)));
    stack[-3] = v0193;
    v0193 = stack[-2];
    v0193 = qcdr(v0193);
    stack[-2] = v0193;
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    stack[0] = v0193;
    goto v0152;

v0198:
    v0195 = stack[-3];
    v0193 = stack[-2];
    v0194 = qcar(v0193);
    v0193 = stack[-1];
    *(Lisp_Object *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL))) = v0193;
    { popv(5); return onevalue(v0193); }

v0197:
    v0195 = elt(env, 2); /* rlisp */
    v0194 = (Lisp_Object)369; /* 23 */
    v0193 = elt(env, 3); /* "Array out of bounds" */
    {
        popv(5);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0195, v0194, v0193);
    }

v0164:
    v0193 = stack[-2];
    v0194 = qcar(v0193);
    v0193 = elt(env, 1); /* "array index" */
    {
        popv(5);
        fn = elt(env, 5); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0194, v0193);
    }
/* error exit handlers */
v0196:
    popv(5);
    return nil;
}



/* Code for reduce!-degree!-mod!-p */

static Lisp_Object CC_reduceKdegreeKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0146)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0202, v0113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-degree-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0146);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0146;
    stack[-1] = v0000;
/* end of prologue */
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0086 = qcdr(v0086);
    {   int32_t w = int_of_fixnum(v0086);
        if (w != 0) w = current_modulus - w;
        v0202 = fixnum_of_int(w);
    }
    v0086 = stack[0];
    v0086 = qcar(v0086);
    v0086 = qcdr(v0086);
    v0086 = Lmodular_quotient(nil, v0202, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    stack[-2] = v0086;
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0086 = qcar(v0086);
    v0202 = qcdr(v0086);
    v0086 = stack[0];
    v0086 = qcar(v0086);
    v0086 = qcar(v0086);
    v0086 = qcdr(v0086);
    v0086 = (Lisp_Object)(int32_t)((int32_t)v0202 - (int32_t)v0086 + TAG_FIXNUM);
    v0113 = v0086;
    v0202 = v0113;
    v0086 = (Lisp_Object)1; /* 0 */
    if (v0202 == v0086) goto v0190;
    v0086 = stack[-1];
    stack[-1] = qcdr(v0086);
    v0086 = stack[0];
    v0086 = qcar(v0086);
    v0086 = qcar(v0086);
    v0086 = qcar(v0086);
    v0202 = v0113;
    fn = elt(env, 1); /* mksp */
    v0202 = (*qfn2(fn))(qenv(fn), v0086, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    v0086 = stack[-2];
    v0202 = cons(v0202, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    fn = elt(env, 2); /* times!-term!-mod!-p */
    v0086 = (*qfn2(fn))(qenv(fn), v0202, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    {
        Lisp_Object v0204 = stack[-1];
        popv(4);
        fn = elt(env, 3); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0204, v0086);
    }

v0190:
    v0086 = stack[-1];
    stack[-1] = qcdr(v0086);
    v0086 = stack[0];
    v0202 = qcdr(v0086);
    v0086 = stack[-2];
    fn = elt(env, 4); /* multiply!-by!-constant!-mod!-p */
    v0086 = (*qfn2(fn))(qenv(fn), v0202, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    {
        Lisp_Object v0205 = stack[-1];
        popv(4);
        fn = elt(env, 3); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0205, v0086);
    }
/* error exit handlers */
v0203:
    popv(4);
    return nil;
}



/* Code for mkfil!* */

static Lisp_Object CC_mkfilH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkfil*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0187 = nil;
    v0143 = stack[0];
    v0143 = Lstringp(nil, v0143);
    env = stack[-1];
    if (!(v0143 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0143 = stack[0];
    if (symbolp(v0143)) goto v0185;
    v0187 = stack[0];
    v0143 = elt(env, 1); /* "file name" */
    {
        popv(2);
        fn = elt(env, 3); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0187, v0143);
    }

v0185:
    v0143 = stack[0];
    if (!symbolp(v0143)) v0143 = nil;
    else { v0143 = qfastgets(v0143);
           if (v0143 != nil) { v0143 = elt(v0143, 17); /* share */
#ifdef RECORD_GET
             if (v0143 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0143 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0143 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0143 == SPID_NOPROP) v0143 = nil; else v0143 = lisp_true; }}
#endif
    if (v0143 == nil) goto v0173;
    v0143 = stack[0];
    fn = elt(env, 4); /* eval */
    v0143 = (*qfn1(fn))(qenv(fn), v0143);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-1];
    v0187 = v0143;
    v0143 = Lstringp(nil, v0143);
    env = stack[-1];
    goto v0165;

v0165:
    if (!(v0143 == nil)) { popv(2); return onevalue(v0187); }
    v0143 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* string!-downcase */
        return (*qfn1(fn))(qenv(fn), v0143);
    }

v0173:
    v0143 = qvalue(elt(env, 2)); /* nil */
    goto v0165;
/* error exit handlers */
v0189:
    popv(2);
    return nil;
}



/* Code for qremf */

static Lisp_Object CC_qremf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0146)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0251, v0252;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qremf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0146);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0146;
    stack[-6] = v0000;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    v0251 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0251; /* !*exp */
    v0251 = stack[-5];
    if (!consp(v0251)) goto v0181;
    v0251 = stack[-5];
    v0251 = qcar(v0251);
    v0251 = (consp(v0251) ? nil : lisp_true);
    goto v0156;

v0156:
    if (v0251 == nil) goto v0161;
    v0252 = stack[-6];
    v0251 = stack[-5];
    fn = elt(env, 4); /* qremd */
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    goto v0177;

v0177:
    qvalue(elt(env, 1)) = stack[-4]; /* !*exp */
    { popv(9); return onevalue(v0251); }

v0161:
    v0251 = qvalue(elt(env, 3)); /* nil */
    v0251 = ncons(v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    stack[-1] = v0251;
    goto v0153;

v0153:
    v0251 = stack[-6];
    if (!consp(v0251)) goto v0188;
    v0251 = stack[-6];
    v0251 = qcar(v0251);
    v0251 = (consp(v0251) ? nil : lisp_true);
    goto v0187;

v0187:
    if (v0251 == nil) goto v0168;
    stack[0] = stack[-1];
    v0252 = qvalue(elt(env, 3)); /* nil */
    v0251 = stack[-6];
    v0251 = cons(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    fn = elt(env, 5); /* praddf */
    v0251 = (*qfn2(fn))(qenv(fn), stack[0], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    goto v0177;

v0168:
    v0251 = stack[-6];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    v0252 = qcar(v0251);
    v0251 = stack[-5];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    if (v0252 == v0251) goto v0201;
    v0251 = stack[-6];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    v0252 = qcar(v0251);
    v0251 = stack[-5];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    fn = elt(env, 6); /* ordop */
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    if (v0251 == nil) goto v0254;
    v0251 = stack[-6];
    v0251 = qcar(v0251);
    v0252 = qcdr(v0251);
    v0251 = stack[-5];
    v0251 = CC_qremf(env, v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    stack[-3] = v0251;
    v0251 = stack[-6];
    v0251 = qcar(v0251);
    v0252 = qcar(v0251);
    v0251 = (Lisp_Object)17; /* 1 */
    v0251 = cons(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0252 = ncons(v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0251 = stack[-3];
    v0251 = qcar(v0251);
    fn = elt(env, 7); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0251 = stack[-6];
    v0251 = qcar(v0251);
    v0252 = qcar(v0251);
    v0251 = (Lisp_Object)17; /* 1 */
    v0251 = cons(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0252 = ncons(v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0251 = stack[-3];
    v0251 = qcdr(v0251);
    fn = elt(env, 7); /* multf */
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0251 = cons(stack[0], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    fn = elt(env, 5); /* praddf */
    v0251 = (*qfn2(fn))(qenv(fn), stack[-1], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    stack[-1] = v0251;
    v0251 = stack[-6];
    v0251 = qcdr(v0251);
    stack[-6] = v0251;
    goto v0153;

v0254:
    stack[0] = stack[-1];
    v0252 = qvalue(elt(env, 3)); /* nil */
    v0251 = stack[-6];
    v0251 = cons(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    fn = elt(env, 5); /* praddf */
    v0251 = (*qfn2(fn))(qenv(fn), stack[0], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    goto v0177;

v0201:
    v0251 = stack[-6];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    v0252 = qcdr(v0251);
    v0251 = stack[-5];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    v0251 = qcdr(v0251);
    v0252 = difference2(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    stack[-7] = v0252;
    v0251 = (Lisp_Object)1; /* 0 */
    v0251 = (Lisp_Object)lessp2(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    v0251 = v0251 ? lisp_true : nil;
    env = stack[-8];
    if (v0251 == nil) goto v0255;
    stack[0] = stack[-1];
    v0252 = qvalue(elt(env, 3)); /* nil */
    v0251 = stack[-6];
    v0251 = cons(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    fn = elt(env, 5); /* praddf */
    v0251 = (*qfn2(fn))(qenv(fn), stack[0], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    goto v0177;

v0255:
    v0251 = stack[-6];
    v0251 = qcar(v0251);
    v0252 = qcdr(v0251);
    v0251 = stack[-5];
    v0251 = qcar(v0251);
    v0251 = qcdr(v0251);
    v0251 = CC_qremf(env, v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    stack[-3] = v0251;
    v0251 = stack[-6];
    v0251 = qcar(v0251);
    v0252 = qcar(v0251);
    v0251 = (Lisp_Object)17; /* 1 */
    v0251 = cons(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0252 = ncons(v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0251 = stack[-3];
    v0251 = qcdr(v0251);
    fn = elt(env, 7); /* multf */
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    stack[-2] = v0251;
    stack[0] = stack[-1];
    v0252 = stack[-7];
    v0251 = (Lisp_Object)1; /* 0 */
    if (v0252 == v0251) goto v0256;
    v0251 = stack[-6];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    v0252 = qcar(v0251);
    v0251 = stack[-7];
    fn = elt(env, 8); /* to */
    v0252 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0251 = (Lisp_Object)17; /* 1 */
    v0251 = cons(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0252 = ncons(v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0251 = stack[-3];
    v0251 = qcar(v0251);
    fn = elt(env, 7); /* multf */
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0252 = v0251;
    goto v0257;

v0257:
    v0251 = stack[-2];
    v0251 = cons(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    fn = elt(env, 5); /* praddf */
    v0251 = (*qfn2(fn))(qenv(fn), stack[0], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    stack[-1] = v0251;
    v0251 = stack[-3];
    v0251 = qcar(v0251);
    if (v0251 == nil) goto v0068;
    stack[0] = stack[-6];
    v0252 = stack[-7];
    v0251 = (Lisp_Object)1; /* 0 */
    if (v0252 == v0251) goto v0258;
    v0251 = stack[-6];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    v0252 = qcar(v0251);
    v0251 = stack[-7];
    fn = elt(env, 8); /* to */
    v0252 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0251 = (Lisp_Object)17; /* 1 */
    v0251 = cons(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0252 = ncons(v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0251 = stack[-5];
    fn = elt(env, 7); /* multf */
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    stack[-6] = v0251;
    goto v0059;

v0059:
    v0251 = stack[-3];
    v0251 = qcar(v0251);
    fn = elt(env, 9); /* negf */
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    fn = elt(env, 7); /* multf */
    v0251 = (*qfn2(fn))(qenv(fn), stack[-6], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    fn = elt(env, 10); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    v0251 = stack[-2];
    fn = elt(env, 9); /* negf */
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    fn = elt(env, 10); /* addf */
    v0251 = (*qfn2(fn))(qenv(fn), stack[0], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-8];
    goto v0259;

v0259:
    stack[-6] = v0251;
    goto v0153;

v0258:
    v0251 = stack[-5];
    stack[-6] = v0251;
    goto v0059;

v0068:
    v0251 = stack[-6];
    v0251 = qcdr(v0251);
    goto v0259;

v0256:
    v0251 = stack[-3];
    v0251 = qcar(v0251);
    v0252 = v0251;
    goto v0257;

v0188:
    v0251 = qvalue(elt(env, 2)); /* t */
    goto v0187;

v0181:
    v0251 = qvalue(elt(env, 2)); /* t */
    goto v0156;
/* error exit handlers */
v0253:
    env = stack[-8];
    qvalue(elt(env, 1)) = stack[-4]; /* !*exp */
    popv(9);
    return nil;
}



/* Code for pasf_smwmkatl */

static Lisp_Object MS_CDECL CC_pasf_smwmkatl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0147, v0088, v0143, v0187, v0188;
    Lisp_Object fn;
    Lisp_Object v0073, v0074, v0146, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwmkatl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0146 = va_arg(aa, Lisp_Object);
    v0074 = va_arg(aa, Lisp_Object);
    v0073 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smwmkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0088 = v0073;
    v0143 = v0074;
    v0187 = v0146;
    v0188 = v0000;
/* end of prologue */
    v0147 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0147 == nil) goto v0099;
    v0147 = v0188;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0147, v0187, v0143, v0088);
    }

v0099:
    v0147 = v0188;
    {
        fn = elt(env, 3); /* cl_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0147, v0187, v0143, v0088);
    }
}



/* Code for row */

static Lisp_Object CC_row(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for row");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0164 = stack[0];
    if (v0164 == nil) goto v0004;
    v0164 = stack[0];
    v0164 = qcar(v0164);
    fn = elt(env, 2); /* expression */
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-1];
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    v0164 = CC_row(env, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    goto v0004;

v0004:
    v0164 = nil;
    { popv(2); return onevalue(v0164); }
/* error exit handlers */
v0156:
    popv(2);
    return nil;
}



/* Code for spband_matrix */

static Lisp_Object CC_spband_matrix(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0146)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0225, v0057, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spband_matrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0146);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0146;
    stack[-8] = v0000;
/* end of prologue */
    stack[0] = stack[-7];
    v0058 = elt(env, 1); /* spm */
    v0057 = stack[-7];
    v0225 = stack[-7];
    v0225 = list3(v0058, v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    fn = elt(env, 9); /* mkempspmat */
    v0225 = (*qfn2(fn))(qenv(fn), stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    stack[-9] = v0225;
    v0225 = stack[-7];
    v0225 = integerp(v0225);
    if (!(v0225 == nil)) goto v0183;
    v0225 = elt(env, 2); /* "Error in spband_matrix(second argument): should be an integer." 
*/
    fn = elt(env, 10); /* rederr */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    goto v0183;

v0183:
    v0225 = stack[-8];
    if (!consp(v0225)) goto v0188;
    v0225 = stack[-8];
    v0057 = qcar(v0225);
    v0225 = elt(env, 3); /* list */
    if (v0057 == v0225) goto v0290;
    v0225 = elt(env, 4); /* "Error in spband_matrix(first argument): should be single value or list." 
*/
    fn = elt(env, 10); /* rederr */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    goto v0187;

v0187:
    v0225 = stack[-8];
    v0225 = Llength(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    stack[-4] = v0225;
    v0225 = stack[-4];
    v0225 = Levenp(nil, v0225);
    env = stack[-10];
    if (v0225 == nil) goto v0162;
    v0225 = elt(env, 5); /* "Error in spband matrix(first argument): number of elements must be odd." 
*/
    fn = elt(env, 10); /* rederr */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    goto v0162;

v0162:
    stack[0] = elt(env, 6); /* quotient */
    v0225 = stack[-4];
    v0057 = add1(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    v0225 = (Lisp_Object)33; /* 2 */
    v0225 = list3(stack[0], v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    fn = elt(env, 11); /* reval */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    stack[-3] = v0225;
    v0225 = stack[-3];
    v0225 = integerp(v0225);
    if (v0225 == nil) goto v0204;
    v0225 = stack[-3];
    v0057 = v0225;
    goto v0196;

v0196:
    v0225 = stack[-7];
    v0225 = (Lisp_Object)greaterp2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0225 = v0225 ? lisp_true : nil;
    env = stack[-10];
    if (v0225 == nil) goto v0194;
    v0225 = elt(env, 7); /* "Error in spband_matrix: too many elements. Band matrix is overflowing." 
*/
    fn = elt(env, 10); /* rederr */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    goto v0194;

v0194:
    v0225 = (Lisp_Object)33; /* 2 */
    stack[-5] = v0225;
    v0225 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0225;
    goto v0291;

v0291:
    v0057 = stack[-7];
    v0225 = stack[-2];
    v0225 = difference2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    v0225 = Lminusp(nil, v0225);
    env = stack[-10];
    if (!(v0225 == nil)) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v0057 = stack[-2];
    v0225 = stack[-3];
    v0225 = (Lisp_Object)lesseq2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0225 = v0225 ? lisp_true : nil;
    env = stack[-10];
    if (v0225 == nil) goto v0292;
    v0225 = (Lisp_Object)17; /* 1 */
    stack[-6] = v0225;
    goto v0229;

v0229:
    v0057 = stack[-3];
    v0225 = stack[-2];
    v0057 = difference2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    v0225 = stack[-6];
    v0057 = plus2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    v0225 = (Lisp_Object)1; /* 0 */
    v0225 = (Lisp_Object)greaterp2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0225 = v0225 ? lisp_true : nil;
    env = stack[-10];
    if (v0225 == nil) goto v0121;
    v0057 = stack[-6];
    v0225 = stack[-7];
    v0225 = (Lisp_Object)lesseq2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0225 = v0225 ? lisp_true : nil;
    env = stack[-10];
    if (v0225 == nil) goto v0121;
    v0057 = stack[-3];
    v0225 = stack[-2];
    v0057 = difference2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    v0225 = stack[-6];
    v0057 = plus2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    v0225 = stack[-4];
    v0225 = (Lisp_Object)lesseq2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0225 = v0225 ? lisp_true : nil;
    env = stack[-10];
    if (v0225 == nil) goto v0121;
    v0058 = stack[-9];
    v0057 = stack[-2];
    v0225 = stack[-6];
    stack[-1] = list3(v0058, v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    stack[0] = stack[-8];
    v0057 = stack[-3];
    v0225 = stack[-2];
    v0057 = difference2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    v0225 = stack[-6];
    v0225 = plus2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    fn = elt(env, 12); /* nth */
    v0058 = (*qfn2(fn))(qenv(fn), stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    v0057 = stack[-9];
    v0225 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 13); /* letmtr3 */
    v0225 = (*qfnn(fn))(qenv(fn), 4, stack[-1], v0058, v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    v0225 = stack[-6];
    v0225 = add1(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    stack[-6] = v0225;
    goto v0229;

v0121:
    v0057 = stack[-2];
    v0225 = stack[-3];
    v0225 = (Lisp_Object)greaterp2(v0057, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0225 = v0225 ? lisp_true : nil;
    env = stack[-10];
    if (v0225 == nil) goto v0061;
    v0225 = stack[-5];
    v0225 = add1(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    stack[-5] = v0225;
    goto v0061;

v0061:
    v0225 = stack[-2];
    v0225 = add1(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    stack[-2] = v0225;
    goto v0291;

v0292:
    v0225 = stack[-5];
    stack[-6] = v0225;
    goto v0229;

v0204:
    v0225 = stack[-3];
    fn = elt(env, 11); /* reval */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    v0057 = v0225;
    goto v0196;

v0290:
    v0225 = stack[-8];
    v0225 = qcdr(v0225);
    stack[-8] = v0225;
    goto v0187;

v0188:
    v0225 = stack[-8];
    v0225 = ncons(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-10];
    stack[-8] = v0225;
    goto v0187;
/* error exit handlers */
v0289:
    popv(11);
    return nil;
}



/* Code for xdegreecheck */

static Lisp_Object CC_xdegreecheck(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0181, v0157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xdegreecheck");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0157 = v0000;
/* end of prologue */
    v0181 = qvalue(elt(env, 1)); /* xtruncate!* */
    if (v0181 == nil) goto v0001;
    v0181 = v0157;
    fn = elt(env, 3); /* xdegree */
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[0];
    v0157 = qvalue(elt(env, 1)); /* xtruncate!* */
        popv(1);
        return Lgreaterp(nil, v0181, v0157);

v0001:
    v0181 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0181); }
/* error exit handlers */
v0100:
    popv(1);
    return nil;
}



/* Code for begin1a */

static Lisp_Object CC_begin1a(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0306, v0307, v0308;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for begin1a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0306 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0306; /* otime!* */
    v0306 = elt(env, 2); /* gctime */
    fn = elt(env, 54); /* getd */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    if (v0306 == nil) goto v0100;
    v0306 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    qvalue(elt(env, 3)) = v0306; /* ogctime!* */
    goto v0098;

v0098:
    v0306 = qvalue(elt(env, 1)); /* otime!* */
    qvalue(elt(env, 4)) = v0306; /* otime3!* */
    qvalue(elt(env, 5)) = v0306; /* otime2!* */
    qvalue(elt(env, 6)) = v0306; /* otime1!* */
    v0306 = qvalue(elt(env, 3)); /* ogctime!* */
    qvalue(elt(env, 7)) = v0306; /* ogctime3!* */
    qvalue(elt(env, 8)) = v0306; /* ogctime2!* */
    qvalue(elt(env, 9)) = v0306; /* ogctime1!* */
    v0306 = stack[0];
    qvalue(elt(env, 10)) = v0306; /* peekchar!* */
    v0306 = elt(env, 11); /* !*semicol!* */
    qvalue(elt(env, 12)) = v0306; /* cursym!* */
    goto v0152;

v0152:
    fn = elt(env, 55); /* terminalp */
    v0306 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    if (v0306 == nil) goto v0142;
    v0306 = qvalue(elt(env, 13)); /* !*nosave!* */
    if (!(v0306 == nil)) goto v0173;
    v0307 = qvalue(elt(env, 14)); /* statcounter */
    v0306 = (Lisp_Object)1; /* 0 */
    if (v0307 == v0306) goto v0173;
    fn = elt(env, 56); /* add2buflis */
    v0306 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    goto v0173;

v0173:
    fn = elt(env, 57); /* update_prompt */
    v0306 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    goto v0142;

v0142:
    v0306 = qvalue(elt(env, 15)); /* nil */
    qvalue(elt(env, 13)) = v0306; /* !*nosave!* */
    v0306 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 16)) = v0306; /* !*strind */
    v0306 = qvalue(elt(env, 15)); /* nil */
    stack[-1] = v0306;
    v0306 = qvalue(elt(env, 17)); /* !*time */
    if (v0306 == nil) goto v0096;
    v0306 = elt(env, 18); /* (showtime) */
    fn = elt(env, 58); /* lispeval */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    goto v0096;

v0096:
    v0306 = qvalue(elt(env, 19)); /* !*output */
    if (v0306 == nil) goto v0179;
    v0306 = qvalue(elt(env, 20)); /* ofl!* */
    if (v0306 == nil) goto v0093;
    v0306 = qvalue(elt(env, 15)); /* nil */
    goto v0168;

v0168:
    if (v0306 == nil) goto v0179;
    v0306 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    goto v0179;

v0179:
    v0306 = qvalue(elt(env, 23)); /* tslin!* */
    if (v0306 == nil) goto v0199;
    v0306 = qvalue(elt(env, 23)); /* tslin!* */
    v0306 = qcar(v0306);
    qvalue(elt(env, 24)) = v0306; /* !*slin */
    v0306 = qvalue(elt(env, 23)); /* tslin!* */
    v0306 = qcdr(v0306);
    qvalue(elt(env, 25)) = v0306; /* lreadfn!* */
    v0306 = qvalue(elt(env, 15)); /* nil */
    qvalue(elt(env, 23)) = v0306; /* tslin!* */
    goto v0199;

v0199:
    v0306 = qvalue(elt(env, 26)); /* initl!* */
    stack[0] = v0306;
    goto v0180;

v0180:
    v0306 = stack[0];
    if (v0306 == nil) goto v0310;
    v0306 = stack[0];
    v0306 = qcar(v0306);
    fn = elt(env, 59); /* sinitl */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    v0306 = stack[0];
    v0306 = qcdr(v0306);
    stack[0] = v0306;
    goto v0180;

v0310:
    v0307 = qvalue(elt(env, 27)); /* forkeywords!* */
    v0306 = elt(env, 28); /* delim */
    v0306 = Lremflag(nil, v0307, v0306);
    env = stack[-2];
    v0307 = qvalue(elt(env, 29)); /* repeatkeywords!* */
    v0306 = elt(env, 28); /* delim */
    v0306 = Lremflag(nil, v0307, v0306);
    env = stack[-2];
    v0307 = qvalue(elt(env, 30)); /* whilekeywords!* */
    v0306 = elt(env, 28); /* delim */
    v0306 = Lremflag(nil, v0307, v0306);
    env = stack[-2];
    v0306 = qvalue(elt(env, 31)); /* !*int */
    if (v0306 == nil) goto v0311;
    v0306 = qvalue(elt(env, 15)); /* nil */
    qvalue(elt(env, 32)) = v0306; /* erfg!* */
    goto v0311;

v0311:
    v0307 = qvalue(elt(env, 12)); /* cursym!* */
    v0306 = elt(env, 33); /* end */
    if (v0307 == v0306) goto v0312;
    fn = elt(env, 55); /* terminalp */
    v0306 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    if (v0306 == nil) goto v0282;
    v0307 = qvalue(elt(env, 34)); /* key!* */
    v0306 = elt(env, 35); /* ed */
    if (v0307 == v0306) goto v0282;
    v0306 = qvalue(elt(env, 36)); /* promptexp!* */
    fn = elt(env, 60); /* printprompt */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    goto v0282;

v0282:
    v0307 = elt(env, 37); /* (command) */
    v0306 = qvalue(elt(env, 38)); /* t */
    fn = elt(env, 61); /* errorset!* */
    v0306 = (*qfn2(fn))(qenv(fn), v0307, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    stack[0] = v0306;
    fn = elt(env, 62); /* condterpri */
    v0306 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    v0306 = stack[0];
    fn = elt(env, 63); /* errorp */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    if (v0306 == nil) goto v0313;
    fn = elt(env, 64); /* eofcheck */
    v0306 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    if (!(v0306 == nil)) goto v0177;
    v0307 = qvalue(elt(env, 45)); /* eof!* */
    v0306 = (Lisp_Object)1; /* 0 */
    v0306 = (Lisp_Object)greaterp2(v0307, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    v0306 = v0306 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0306 == nil)) goto v0177;
    v0307 = stack[0];
    v0306 = elt(env, 49); /* "BEGIN invalid" */
    if (equal(v0307, v0306)) goto v0152;
    v0306 = qvalue(elt(env, 38)); /* t */
    stack[-1] = v0306;
    goto v0166;

v0166:
    fn = elt(env, 65); /* resetparser */
    v0306 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    goto v0184;

v0184:
    v0306 = qvalue(elt(env, 38)); /* t */
    qvalue(elt(env, 32)) = v0306; /* erfg!* */
    v0306 = qvalue(elt(env, 31)); /* !*int */
    if (v0306 == nil) goto v0125;
    v0306 = qvalue(elt(env, 15)); /* nil */
    goto v0214;

v0214:
    if (v0306 == nil) goto v0047;
    v0306 = qvalue(elt(env, 38)); /* t */
    qvalue(elt(env, 21)) = v0306; /* !*defn */
    v0306 = qvalue(elt(env, 38)); /* t */
    qvalue(elt(env, 51)) = v0306; /* !*echo */
    v0306 = qvalue(elt(env, 52)); /* cmsg!* */
    if (!(v0306 == nil)) goto v0314;
    v0306 = elt(env, 53); /* "Continuing with parsing only ..." */
    fn = elt(env, 66); /* lprie */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    goto v0314;

v0314:
    v0306 = qvalue(elt(env, 38)); /* t */
    qvalue(elt(env, 52)) = v0306; /* cmsg!* */
    goto v0152;

v0047:
    v0306 = qvalue(elt(env, 50)); /* !*errcont */
    if (v0306 == nil) goto v0126;
    v0306 = qvalue(elt(env, 15)); /* nil */
    qvalue(elt(env, 32)) = v0306; /* erfg!* */
    goto v0152;

v0126:
    v0306 = stack[-1];
    fn = elt(env, 67); /* pause1 */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    v0308 = v0306;
    v0306 = v0308;
    if (v0306 == nil) goto v0315;
    v0306 = v0308;
    fn = elt(env, 58); /* lispeval */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    v0306 = (v0306 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0306); }

v0315:
    v0306 = qvalue(elt(env, 15)); /* nil */
    qvalue(elt(env, 32)) = v0306; /* erfg!* */
    goto v0152;

v0125:
    v0306 = qvalue(elt(env, 50)); /* !*errcont */
    v0306 = (v0306 == nil ? lisp_true : nil);
    goto v0214;

v0177:
    v0306 = qvalue(elt(env, 43)); /* crbuf1!* */
    if (v0306 == nil) goto v0316;
    v0306 = elt(env, 44); /* "Closing object improperly removed. Redo edit." 
*/
    fn = elt(env, 68); /* lprim */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    v0306 = qvalue(elt(env, 15)); /* nil */
    qvalue(elt(env, 43)) = v0306; /* crbuf1!* */
    v0306 = qvalue(elt(env, 15)); /* nil */
    { popv(3); return onevalue(v0306); }

v0316:
    v0307 = qvalue(elt(env, 45)); /* eof!* */
    v0306 = (Lisp_Object)65; /* 4 */
    v0306 = (Lisp_Object)greaterp2(v0307, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    v0306 = v0306 ? lisp_true : nil;
    env = stack[-2];
    if (v0306 == nil) goto v0054;
    v0306 = elt(env, 46); /* "End-of-file read" */
    fn = elt(env, 68); /* lprim */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    v0306 = elt(env, 47); /* (bye) */
    {
        popv(3);
        fn = elt(env, 58); /* lispeval */
        return (*qfn1(fn))(qenv(fn), v0306);
    }

v0054:
    fn = elt(env, 55); /* terminalp */
    v0306 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    if (v0306 == nil) goto v0289;
    v0306 = qvalue(elt(env, 15)); /* nil */
    qvalue(elt(env, 48)) = v0306; /* crbuf!* */
    v0306 = qvalue(elt(env, 38)); /* t */
    qvalue(elt(env, 13)) = v0306; /* !*nosave!* */
    goto v0152;

v0289:
    v0306 = qvalue(elt(env, 15)); /* nil */
    { popv(3); return onevalue(v0306); }

v0313:
    v0306 = stack[0];
    v0306 = qcar(v0306);
    stack[0] = v0306;
    v0306 = stack[0];
    v0307 = qcar(v0306);
    v0306 = elt(env, 39); /* symbolic */
    if (v0307 == v0306) goto v0278;
    v0306 = qvalue(elt(env, 15)); /* nil */
    goto v0070;

v0070:
    if (v0306 == nil) goto v0317;
    v0306 = stack[0];
    v0306 = qcdr(v0306);
    v0306 = qcar(v0306);
    fn = elt(env, 69); /* eval */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    fn = elt(env, 70); /* xmodloop */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    v0308 = v0306;
    goto v0318;

v0318:
    v0306 = v0308;
    if (v0306 == nil) goto v0152;
    v0307 = v0308;
    v0306 = elt(env, 33); /* end */
    if (v0307 == v0306) goto v0221;
    v0307 = v0308;
    v0306 = elt(env, 41); /* err2 */
    if (v0307 == v0306) goto v0166;
    v0307 = v0308;
    v0306 = elt(env, 42); /* err3 */
    if (v0307 == v0306) goto v0184;
    else goto v0177;

v0221:
    v0306 = qvalue(elt(env, 15)); /* nil */
    { popv(3); return onevalue(v0306); }

v0317:
    v0306 = stack[0];
    fn = elt(env, 71); /* begin11 */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    v0308 = v0306;
    goto v0318;

v0278:
    v0306 = stack[0];
    v0306 = qcdr(v0306);
    v0307 = qcar(v0306);
    v0306 = elt(env, 40); /* xmodule */
    v0306 = Leqcar(nil, v0307, v0306);
    env = stack[-2];
    goto v0070;

v0312:
    v0306 = elt(env, 33); /* end */
    fn = elt(env, 72); /* comm1 */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    v0306 = qvalue(elt(env, 15)); /* nil */
    { popv(3); return onevalue(v0306); }

v0093:
    fn = elt(env, 55); /* terminalp */
    v0306 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-2];
    if (v0306 == nil) goto v0108;
    v0306 = qvalue(elt(env, 21)); /* !*defn */
    if (v0306 == nil) goto v0167;
    v0306 = qvalue(elt(env, 15)); /* nil */
    goto v0168;

v0167:
    v0306 = qvalue(elt(env, 22)); /* !*lessspace */
    v0306 = (v0306 == nil ? lisp_true : nil);
    goto v0168;

v0108:
    v0306 = qvalue(elt(env, 15)); /* nil */
    goto v0168;

v0100:
    v0306 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v0306; /* ogctime!* */
    goto v0098;
/* error exit handlers */
v0309:
    popv(3);
    return nil;
}



/* Code for lienjactest */

static Lisp_Object CC_lienjactest(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0356, v0357, v0358, v0359;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lienjactest");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-11] = v0000;
/* end of prologue */
    stack[0] = elt(env, 1); /* lie_jtest */
    v0356 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 7); /* aeval */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 8); /* setk */
    v0356 = (*qfn2(fn))(qenv(fn), stack[0], v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0356 = (Lisp_Object)17; /* 1 */
    stack[-12] = v0356;
    goto v0171;

v0171:
    stack[0] = elt(env, 2); /* difference */
    v0358 = elt(env, 2); /* difference */
    v0357 = stack[-11];
    v0356 = (Lisp_Object)33; /* 2 */
    v0356 = list3(v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0357 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0356 = stack[-12];
    v0356 = list3(stack[0], v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    if (v0356 == nil) goto v0181;
    v0356 = nil;
    { popv(14); return onevalue(v0356); }

v0181:
    v0356 = stack[-12];
    v0356 = add1(v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-10] = v0356;
    goto v0158;

v0158:
    stack[0] = elt(env, 2); /* difference */
    v0358 = elt(env, 2); /* difference */
    v0357 = stack[-11];
    v0356 = (Lisp_Object)17; /* 1 */
    v0356 = list3(v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0357 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0356 = stack[-10];
    v0356 = list3(stack[0], v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    if (v0356 == nil) goto v0145;
    v0356 = stack[-12];
    v0358 = elt(env, 4); /* plus */
    v0357 = v0356;
    v0356 = (Lisp_Object)17; /* 1 */
    v0356 = list3(v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-12] = v0356;
    goto v0171;

v0145:
    v0356 = stack[-10];
    v0356 = add1(v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-9] = v0356;
    goto v0361;

v0361:
    stack[0] = elt(env, 2); /* difference */
    v0356 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v0357 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0356 = stack[-9];
    v0356 = list3(stack[0], v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    if (v0356 == nil) goto v0288;
    v0356 = stack[-10];
    v0358 = elt(env, 4); /* plus */
    v0357 = v0356;
    v0356 = (Lisp_Object)17; /* 1 */
    v0356 = list3(v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-10] = v0356;
    goto v0158;

v0288:
    v0356 = (Lisp_Object)17; /* 1 */
    stack[-8] = v0356;
    goto v0244;

v0244:
    stack[0] = elt(env, 2); /* difference */
    v0356 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v0357 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0356 = stack[-8];
    v0356 = list3(stack[0], v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    if (v0356 == nil) goto v0304;
    v0356 = stack[-9];
    v0358 = elt(env, 4); /* plus */
    v0357 = v0356;
    v0356 = (Lisp_Object)17; /* 1 */
    v0356 = list3(v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-9] = v0356;
    goto v0361;

v0304:
    v0356 = (Lisp_Object)17; /* 1 */
    stack[-7] = v0356;
    v0356 = (Lisp_Object)1; /* 0 */
    stack[-6] = v0356;
    goto v0362;

v0362:
    stack[0] = elt(env, 2); /* difference */
    v0356 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v0357 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0356 = stack[-7];
    v0356 = list3(stack[0], v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    if (v0356 == nil) goto v0363;
    v0356 = stack[-6];
    v0357 = v0356;
    v0356 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 11); /* evalneq */
    v0356 = (*qfn2(fn))(qenv(fn), v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    if (v0356 == nil) goto v0364;
    stack[0] = elt(env, 1); /* lie_jtest */
    v0356 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 9); /* aeval!* */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 8); /* setk */
    v0356 = (*qfn2(fn))(qenv(fn), stack[0], v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0358 = elt(env, 2); /* difference */
    v0357 = stack[-11];
    v0356 = (Lisp_Object)17; /* 1 */
    v0356 = list3(v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-12] = v0356;
    v0356 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-10] = v0356;
    v0358 = elt(env, 4); /* plus */
    v0357 = stack[-11];
    v0356 = (Lisp_Object)17; /* 1 */
    v0356 = list3(v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-9] = v0356;
    v0358 = elt(env, 4); /* plus */
    v0357 = stack[-11];
    v0356 = (Lisp_Object)17; /* 1 */
    v0356 = list3(v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-8] = v0356;
    goto v0364;

v0364:
    v0356 = stack[-8];
    v0358 = elt(env, 4); /* plus */
    v0357 = v0356;
    v0356 = (Lisp_Object)17; /* 1 */
    v0356 = list3(v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-8] = v0356;
    goto v0244;

v0363:
    stack[-5] = elt(env, 4); /* plus */
    stack[-4] = elt(env, 4); /* plus */
    stack[-1] = elt(env, 5); /* times */
    v0359 = elt(env, 6); /* lie_cc */
    v0358 = stack[-10];
    v0357 = stack[-9];
    v0356 = stack[-7];
    stack[0] = list4(v0359, v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0359 = elt(env, 6); /* lie_cc */
    v0358 = stack[-12];
    v0357 = stack[-7];
    v0356 = stack[-8];
    v0356 = list4(v0359, v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-3] = list3(stack[-1], stack[0], v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-1] = elt(env, 5); /* times */
    v0359 = elt(env, 6); /* lie_cc */
    v0358 = stack[-12];
    v0357 = stack[-10];
    v0356 = stack[-7];
    stack[0] = list4(v0359, v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0359 = elt(env, 6); /* lie_cc */
    v0358 = stack[-9];
    v0357 = stack[-7];
    v0356 = stack[-8];
    v0356 = list4(v0359, v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-2] = list3(stack[-1], stack[0], v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-1] = elt(env, 5); /* times */
    v0359 = elt(env, 6); /* lie_cc */
    v0358 = stack[-9];
    v0357 = stack[-12];
    v0356 = stack[-7];
    stack[0] = list4(v0359, v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0359 = elt(env, 6); /* lie_cc */
    v0358 = stack[-10];
    v0357 = stack[-7];
    v0356 = stack[-8];
    v0356 = list4(v0359, v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0356 = list3(stack[-1], stack[0], v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0356 = list4(stack[-4], stack[-3], stack[-2], v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0357 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    v0356 = stack[-6];
    v0356 = list3(stack[-5], v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-6] = v0356;
    v0356 = stack[-7];
    v0358 = elt(env, 4); /* plus */
    v0357 = v0356;
    v0356 = (Lisp_Object)17; /* 1 */
    v0356 = list3(v0358, v0357, v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v0356 = (*qfn1(fn))(qenv(fn), v0356);
    nil = C_nil;
    if (exception_pending()) goto v0360;
    env = stack[-13];
    stack[-7] = v0356;
    goto v0362;
/* error exit handlers */
v0360:
    popv(14);
    return nil;
}



/* Code for fieldconv */

static Lisp_Object CC_fieldconv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0146)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0221, v0373, v0374;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fieldconv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0146);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0146;
    stack[-2] = v0000;
/* end of prologue */
    v0221 = stack[-1];
    v0221 = qcar(v0221);
    stack[-3] = v0221;
    v0221 = stack[-1];
    v0221 = qcdr(v0221);
    stack[0] = v0221;
    v0221 = qvalue(elt(env, 1)); /* dmode!* */
    if (v0221 == nil) goto v0101;
    v0221 = stack[0];
    if (!consp(v0221)) goto v0280;
    v0221 = stack[0];
    v0221 = qcar(v0221);
    v0221 = (consp(v0221) ? nil : lisp_true);
    goto v0279;

v0279:
    if (v0221 == nil) goto v0350;
    v0373 = stack[-3];
    v0221 = stack[0];
    fn = elt(env, 6); /* divd */
    v0373 = (*qfn2(fn))(qenv(fn), v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    v0221 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0373, v0221);

v0350:
    v0373 = stack[-3];
    v0221 = stack[-2];
    fn = elt(env, 6); /* divd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    v0373 = stack[0];
    v0221 = stack[-2];
    fn = elt(env, 6); /* divd */
    v0221 = (*qfn2(fn))(qenv(fn), v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    {
        Lisp_Object v0258 = stack[-1];
        popv(5);
        return cons(v0258, v0221);
    }

v0280:
    v0221 = qvalue(elt(env, 5)); /* t */
    goto v0279;

v0101:
    v0373 = stack[-2];
    v0221 = elt(env, 2); /* !:rn!: */
    if (!consp(v0373)) goto v0183;
    v0373 = qcar(v0373);
    if (!(v0373 == v0221)) goto v0183;

v0375:
    v0221 = stack[-2];
    v0374 = qcar(v0221);
    v0221 = stack[-2];
    v0221 = qcdr(v0221);
    v0373 = qcdr(v0221);
    v0221 = stack[-2];
    v0221 = qcdr(v0221);
    v0221 = qcar(v0221);
    v0221 = list2star(v0374, v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    stack[-2] = v0221;
    v0221 = stack[0];
    if (!consp(v0221)) goto v0242;
    v0221 = stack[0];
    v0221 = qcar(v0221);
    v0221 = (consp(v0221) ? nil : lisp_true);
    goto v0304;

v0304:
    if (v0221 == nil) goto v0257;
    v0373 = stack[-2];
    v0221 = stack[-3];
    fn = elt(env, 7); /* multd */
    v0373 = (*qfn2(fn))(qenv(fn), v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    v0221 = (Lisp_Object)17; /* 1 */
    v0221 = cons(v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    goto v0364;

v0364:
    {
        popv(5);
        fn = elt(env, 8); /* simpgd */
        return (*qfn1(fn))(qenv(fn), v0221);
    }

v0257:
    v0373 = stack[-2];
    v0221 = stack[-3];
    fn = elt(env, 7); /* multd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    v0373 = stack[-2];
    v0221 = stack[0];
    fn = elt(env, 7); /* multd */
    v0221 = (*qfn2(fn))(qenv(fn), v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    v0221 = cons(stack[-1], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    goto v0364;

v0242:
    v0221 = qvalue(elt(env, 5)); /* t */
    goto v0304;

v0183:
    v0221 = stack[-2];
    v0373 = qcar(v0221);
    v0221 = elt(env, 2); /* !:rn!: */
    v0221 = get(v0373, v0221);
    env = stack[-4];
    v0373 = v0221;
    if (v0221 == nil) goto v0096;
    v0221 = v0373;
    if (!(!consp(v0221))) goto v0096;
    v0221 = stack[-2];
    v0221 = Lapply1(nil, v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    stack[-2] = v0221;
    goto v0375;

v0096:
    v0221 = stack[-2];
    v0373 = qcar(v0221);
    v0221 = elt(env, 3); /* quotient */
    v0221 = get(v0373, v0221);
    env = stack[-4];
    if (v0221 == nil) goto v0376;
    v0374 = (Lisp_Object)17; /* 1 */
    v0373 = stack[-2];
    v0221 = elt(env, 3); /* quotient */
    fn = elt(env, 9); /* dcombine */
    v0221 = (*qfnn(fn))(qenv(fn), 3, v0374, v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    stack[-2] = v0221;
    v0373 = stack[-2];
    v0221 = stack[-1];
    v0221 = qcar(v0221);
    fn = elt(env, 7); /* multd */
    stack[0] = (*qfn2(fn))(qenv(fn), v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    v0373 = stack[-2];
    v0221 = stack[-1];
    v0221 = qcdr(v0221);
    fn = elt(env, 7); /* multd */
    v0221 = (*qfn2(fn))(qenv(fn), v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    {
        Lisp_Object v0345 = stack[0];
        popv(5);
        return cons(v0345, v0221);
    }

v0376:
    v0373 = elt(env, 4); /* "field conversion" */
    v0221 = stack[-2];
    v0221 = list2(v0373, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    fn = elt(env, 10); /* errach */
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0296;
    env = stack[-4];
    goto v0375;
/* error exit handlers */
v0296:
    popv(5);
    return nil;
}



/* Code for moid_member */

static Lisp_Object CC_moid_member(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0146)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0182, v0186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for moid_member");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0146);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0146;
    stack[-1] = v0000;
/* end of prologue */

v0176:
    v0182 = stack[0];
    if (v0182 == nil) goto v0004;
    v0182 = stack[0];
    v0186 = qcar(v0182);
    v0182 = stack[-1];
    fn = elt(env, 2); /* mo_vdivides!? */
    v0182 = (*qfn2(fn))(qenv(fn), v0186, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-2];
    if (!(v0182 == nil)) { popv(3); return onevalue(v0182); }
    v0186 = stack[-1];
    v0182 = stack[0];
    v0182 = qcdr(v0182);
    stack[-1] = v0186;
    stack[0] = v0182;
    goto v0176;

v0004:
    v0182 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0182); }
/* error exit handlers */
v0172:
    popv(3);
    return nil;
}



/* Code for pairxvars */

static Lisp_Object MS_CDECL CC_pairxvars(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0378, v0284, v0238;
    Lisp_Object fn;
    Lisp_Object v0073, v0074, v0146, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pairxvars");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0146 = va_arg(aa, Lisp_Object);
    v0074 = va_arg(aa, Lisp_Object);
    v0073 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pairxvars");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0073,v0074,v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0146,v0074,v0073);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0073;
    stack[-2] = v0074;
    stack[-3] = v0146;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = nil;
    goto v0177;

v0177:
    v0378 = stack[-4];
    if (v0378 == nil) goto v0101;
    v0378 = stack[-4];
    v0284 = qcar(v0378);
    v0378 = stack[-3];
    v0378 = Latsoc(nil, v0284, v0378);
    stack[0] = v0378;
    if (v0378 == nil) goto v0182;
    v0284 = stack[0];
    v0378 = stack[-3];
    v0378 = Ldelete(nil, v0284, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0362;
    env = stack[-6];
    stack[-3] = v0378;
    v0378 = stack[0];
    v0284 = qcdr(v0378);
    v0378 = elt(env, 1); /* scalar */
    if (v0284 == v0378) goto v0163;
    v0378 = stack[-4];
    v0238 = qcar(v0378);
    v0378 = stack[0];
    v0284 = qcdr(v0378);
    v0378 = stack[-5];
    v0378 = acons(v0238, v0284, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0362;
    env = stack[-6];
    stack[-5] = v0378;
    goto v0166;

v0166:
    v0378 = stack[-4];
    v0378 = qcdr(v0378);
    stack[-4] = v0378;
    goto v0177;

v0163:
    v0378 = stack[-4];
    v0238 = qcar(v0378);
    v0284 = stack[-1];
    v0378 = stack[-5];
    v0378 = acons(v0238, v0284, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0362;
    env = stack[-6];
    stack[-5] = v0378;
    goto v0166;

v0182:
    v0378 = stack[-4];
    v0378 = qcar(v0378);
    if (symbolp(v0378)) goto v0086;
    v0378 = qvalue(elt(env, 2)); /* t */
    goto v0361;

v0361:
    if (v0378 == nil) goto v0364;
    v0284 = elt(env, 3); /* "Invalid parameter:" */
    v0378 = stack[-4];
    v0378 = qcar(v0378);
    v0284 = list2(v0284, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0362;
    env = stack[-6];
    v0378 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 5); /* symerr */
    v0378 = (*qfn2(fn))(qenv(fn), v0284, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0362;
    env = stack[-6];
    goto v0166;

v0364:
    v0378 = stack[-4];
    v0238 = qcar(v0378);
    v0284 = stack[-1];
    v0378 = stack[-5];
    v0378 = acons(v0238, v0284, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0362;
    env = stack[-6];
    stack[-5] = v0378;
    goto v0166;

v0086:
    v0378 = stack[-4];
    v0378 = qcar(v0378);
    if (!symbolp(v0378)) v0378 = nil;
    else { v0378 = qfastgets(v0378);
           if (v0378 != nil) { v0378 = elt(v0378, 23); /* infix */
#ifdef RECORD_GET
             if (v0378 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0378 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0378 == SPID_NOPROP) v0378 = nil; }}
#endif
    if (!(v0378 == nil)) goto v0361;
    v0378 = stack[-4];
    v0378 = qcar(v0378);
    if (!symbolp(v0378)) v0378 = nil;
    else { v0378 = qfastgets(v0378);
           if (v0378 != nil) { v0378 = elt(v0378, 36); /* stat */
#ifdef RECORD_GET
             if (v0378 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0378 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0378 == SPID_NOPROP) v0378 = nil; }}
#endif
    goto v0361;

v0101:
    v0378 = stack[-5];
    fn = elt(env, 6); /* reversip!* */
    v0284 = (*qfn1(fn))(qenv(fn), v0378);
    nil = C_nil;
    if (exception_pending()) goto v0362;
    env = stack[-6];
    v0378 = stack[-2];
    v0284 = Lappend(nil, v0284, v0378);
    nil = C_nil;
    if (exception_pending()) goto v0362;
    v0378 = stack[-3];
    popv(7);
    return cons(v0284, v0378);
/* error exit handlers */
v0362:
    popv(7);
    return nil;
}



/* Code for mkeqsq */

static Lisp_Object MS_CDECL CC_mkeqsq(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0312, v0362, v0311, v0240, v0241, v0369, v0239, v0082, v0080;
    Lisp_Object fn;
    Lisp_Object v0177, v0180, v0152, v0191, v0004, v0001, v0073, v0074, v0146, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 10, "mkeqsq");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0146 = va_arg(aa, Lisp_Object);
    v0074 = va_arg(aa, Lisp_Object);
    v0073 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    v0191 = va_arg(aa, Lisp_Object);
    v0152 = va_arg(aa, Lisp_Object);
    v0180 = va_arg(aa, Lisp_Object);
    v0177 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkeqsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0177,v0180,v0152,v0191,v0004,v0001);
        push4(v0073,v0074,v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0146,v0074,v0073,v0001,v0004);
        pop4(v0191,v0152,v0180,v0177);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0177;
    stack[-3] = v0180;
    stack[-4] = v0152;
    stack[-5] = v0191;
    stack[-6] = v0004;
    stack[-7] = v0001;
    stack[-8] = v0073;
    stack[-9] = v0074;
    stack[-10] = v0146;
    stack[-11] = v0000;
/* end of prologue */
    v0312 = stack[-11];
    if (v0312 == nil) goto v0098;
    v0312 = stack[-11];
    fn = elt(env, 4); /* sqzerop */
    v0312 = (*qfn1(fn))(qenv(fn), v0312);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-13];
    if (!(v0312 == nil)) goto v0098;

v0185:
    fn = elt(env, 5); /* new_pde */
    v0312 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-13];
    stack[-12] = v0312;
    v0312 = qvalue(elt(env, 1)); /* record_hist */
    if (v0312 == nil) goto v0182;
    v0312 = stack[-3];
    if (v0312 == nil) goto v0182;
    stack[-1] = stack[-12];
    stack[0] = elt(env, 2); /* histry_ */
    v0312 = stack[-3];
    fn = elt(env, 6); /* reval */
    v0312 = (*qfn1(fn))(qenv(fn), v0312);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-13];
    v0312 = Lputprop(nil, 3, stack[-1], stack[0], v0312);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-13];
    goto v0182;

v0182:
    v0312 = stack[-6];
    stack[-1] = v0312;
    goto v0144;

v0144:
    v0312 = stack[-1];
    if (v0312 == nil) goto v0089;
    v0312 = stack[-1];
    v0312 = qcar(v0312);
    stack[0] = v0312;
    v0312 = stack[-12];
    v0362 = ncons(v0312);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-13];
    v0312 = stack[0];
    v0312 = Lflag(nil, v0362, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-13];
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    stack[-1] = v0312;
    goto v0144;

v0089:
    v0080 = stack[-12];
    v0082 = stack[-11];
    v0239 = stack[-10];
    v0369 = stack[-9];
    v0241 = stack[-8];
    v0240 = stack[-7];
    v0311 = stack[-5];
    v0362 = stack[-4];
    v0312 = stack[-2];
    fn = elt(env, 7); /* updatesq */
    v0312 = (*qfnn(fn))(qenv(fn), 9, v0080, v0082, v0239, v0369, v0241, v0240, v0311, v0362, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-13];
    if (!(v0312 == nil)) goto v0162;
    v0311 = stack[-12];
    v0362 = qvalue(elt(env, 3)); /* nil */
    v0312 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* drop_pde */
    v0312 = (*qfnn(fn))(qenv(fn), 3, v0311, v0362, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-13];
    v0312 = qvalue(elt(env, 3)); /* nil */
    stack[-12] = v0312;
    goto v0162;

v0162:
    v0312 = qvalue(elt(env, 1)); /* record_hist */
    if (v0312 == nil) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v0312 = stack[-3];
    if (v0312 == nil) goto v0285;
    v0312 = qvalue(elt(env, 3)); /* nil */
    goto v0115;

v0115:
    if (v0312 == nil) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v0311 = stack[-12];
    v0362 = elt(env, 2); /* histry_ */
    v0312 = stack[-12];
    v0312 = Lputprop(nil, 3, v0311, v0362, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }

v0285:
    v0312 = stack[-12];
    goto v0115;

v0098:
    v0312 = stack[-10];
    if (!(v0312 == nil)) goto v0185;
    v0312 = stack[-9];
    v0312 = (Lisp_Object)zerop(v0312);
    v0312 = v0312 ? lisp_true : nil;
    env = stack[-13];
    if (v0312 == nil) goto v0185;
    v0312 = nil;
    { popv(14); return onevalue(v0312); }
/* error exit handlers */
v0256:
    popv(14);
    return nil;
}



/* Code for ezgcdf1 */

static Lisp_Object CC_ezgcdf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0146)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0164, v0155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ezgcdf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0146);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0164 = v0146;
    v0155 = v0000;
/* end of prologue */
    v0098 = (Lisp_Object)1; /* 0 */
    stack[0] = qvalue(elt(env, 1)); /* factor!-level */
    qvalue(elt(env, 1)) = v0098; /* factor!-level */
    v0098 = v0155;
    v0098 = list2(v0098, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-1];
    fn = elt(env, 2); /* gcdlist */
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-1];
    fn = elt(env, 3); /* poly!-abs */
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* factor!-level */
    { popv(2); return onevalue(v0098); }
/* error exit handlers */
v0181:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* factor!-level */
    popv(2);
    return nil;
}



/* Code for get_group_in */

static Lisp_Object CC_get_group_in(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0191;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_group_in");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0191 = v0000;
/* end of prologue */
    v0191 = qcar(v0191);
    return onevalue(v0191);
}



/* Code for cl_susiupdknowl1 */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0096, v0159;
    Lisp_Object fn;
    Lisp_Object v0073, v0074, v0146, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0146 = va_arg(aa, Lisp_Object);
    v0074 = va_arg(aa, Lisp_Object);
    v0073 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susiupdknowl1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0073,v0074,v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0146,v0074,v0073);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0073;
    stack[-1] = v0074;
    v0159 = v0146;
    v0095 = v0000;
/* end of prologue */
    v0096 = v0095;
    v0095 = elt(env, 1); /* and */
    if (v0096 == v0095) goto v0206;
    v0095 = v0159;
    fn = elt(env, 2); /* rl_negateat */
    v0096 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-2];
    v0095 = stack[0];
    v0159 = cons(v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-2];
    v0096 = stack[-1];
    v0095 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* cl_susiupdknowl2 */
        return (*qfnn(fn))(qenv(fn), 3, v0159, v0096, v0095);
    }

v0206:
    v0096 = v0159;
    v0095 = stack[0];
    v0159 = cons(v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-2];
    v0096 = stack[-1];
    v0095 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* cl_susiupdknowl2 */
        return (*qfnn(fn))(qenv(fn), 3, v0159, v0096, v0095);
    }
/* error exit handlers */
v0150:
    popv(3);
    return nil;
}



/* Code for naryom */

static Lisp_Object CC_naryom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0201, v0196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for naryom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0201 = stack[-1];
    v0201 = qcar(v0201);
    stack[0] = v0201;
    v0196 = stack[0];
    v0201 = elt(env, 1); /* var */
    if (!(v0196 == v0201)) goto v0157;
    v0201 = elt(env, 2); /* variance */
    stack[0] = v0201;
    goto v0157;

v0157:
    v0196 = stack[0];
    v0201 = qvalue(elt(env, 3)); /* valid_om!* */
    v0201 = Lassoc(nil, v0196, v0201);
    stack[-2] = v0201;
    v0201 = stack[-2];
    if (v0201 == nil) goto v0142;
    v0201 = stack[-2];
    v0201 = qcdr(v0201);
    v0201 = qcar(v0201);
    stack[-2] = v0201;
    goto v0142;

v0142:
    v0201 = stack[-1];
    v0201 = qcdr(v0201);
    v0201 = qcar(v0201);
    if (v0201 == nil) goto v0260;
    v0201 = stack[-1];
    v0201 = qcdr(v0201);
    v0196 = qcar(v0201);
    v0201 = elt(env, 4); /* multiset */
    if (!(v0196 == v0201)) goto v0260;
    v0201 = stack[-1];
    v0201 = qcdr(v0201);
    v0201 = qcar(v0201);
    stack[-2] = v0201;
    goto v0260;

v0260:
    v0201 = elt(env, 6); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    v0196 = qvalue(elt(env, 7)); /* indent */
    v0201 = (Lisp_Object)33; /* 2 */
    v0201 = plus2(v0196, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    qvalue(elt(env, 7)) = v0201; /* indent */
    v0201 = elt(env, 8); /* "<OMS cd=""" */
    fn = elt(env, 12); /* printout */
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    v0201 = stack[-2];
    v0201 = Lprinc(nil, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    v0201 = elt(env, 9); /* """ name=""" */
    v0201 = Lprinc(nil, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    v0201 = stack[0];
    v0201 = Lprinc(nil, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    v0201 = elt(env, 10); /* """>" */
    v0201 = Lprinc(nil, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    v0201 = stack[-1];
    v0201 = qcdr(v0201);
    v0201 = qcdr(v0201);
    fn = elt(env, 13); /* multiom */
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    v0196 = qvalue(elt(env, 7)); /* indent */
    v0201 = (Lisp_Object)33; /* 2 */
    v0201 = difference2(v0196, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    qvalue(elt(env, 7)) = v0201; /* indent */
    v0201 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    v0201 = nil;
    { popv(4); return onevalue(v0201); }
/* error exit handlers */
v0202:
    popv(4);
    return nil;
}



/* Code for dm!-eq */

static Lisp_Object CC_dmKeq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0146)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0184, v0185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-eq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0146,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0146);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0184 = v0146;
    v0185 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* dm!-difference */
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !:zerop */
        return (*qfn1(fn))(qenv(fn), v0184);
    }
/* error exit handlers */
v0161:
    popv(1);
    return nil;
}



/* Code for prinlatom */

static Lisp_Object CC_prinlatom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0192, v0168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prinlatom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0168 = stack[-1];
    v0192 = elt(env, 1); /* font */
    v0192 = get(v0168, v0192);
    env = stack[-3];
    stack[-2] = v0192;
    if (v0192 == nil) goto v0165;
    v0192 = stack[-2];
    fn = elt(env, 5); /* prin2la */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    goto v0165;

v0165:
    v0168 = stack[-1];
    v0192 = elt(env, 2); /* accent */
    v0192 = get(v0168, v0192);
    env = stack[-3];
    stack[0] = v0192;
    if (v0192 == nil) goto v0147;
    v0192 = stack[0];
    fn = elt(env, 5); /* prin2la */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    goto v0147;

v0147:
    v0168 = stack[-1];
    v0192 = elt(env, 3); /* name */
    v0192 = get(v0168, v0192);
    env = stack[-3];
    v0168 = v0192;
    if (v0192 == nil) goto v0290;
    v0192 = v0168;
    fn = elt(env, 5); /* prin2la */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    goto v0172;

v0172:
    v0192 = stack[0];
    if (v0192 == nil) goto v0095;
    v0192 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    goto v0095;

v0095:
    v0192 = stack[-2];
    if (v0192 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0192 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0290:
    v0192 = stack[-1];
    fn = elt(env, 6); /* testchar1 */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    fn = elt(env, 5); /* prin2la */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    goto v0172;
/* error exit handlers */
v0174:
    popv(4);
    return nil;
}



/* Code for gfdot */

static Lisp_Object CC_gfdot(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0146)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0097, v0142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfdot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0097 = v0146;
    v0142 = v0000;
/* end of prologue */
    v0099 = v0142;
    v0099 = qcar(v0099);
    if (!consp(v0099)) goto v0153;
    v0099 = v0142;
    {
        fn = elt(env, 1); /* gbfdot */
        return (*qfn2(fn))(qenv(fn), v0099, v0097);
    }

v0153:
    v0099 = v0142;
    {
        fn = elt(env, 2); /* gffdot */
        return (*qfn2(fn))(qenv(fn), v0099, v0097);
    }
}



/* Code for lengthcdr */

static Lisp_Object CC_lengthcdr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lengthcdr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    v0004 = qcdr(v0004);
        return Llength(nil, v0004);
}



setup_type const u20_setup[] =
{
    {"lalr_set_grammar",        CC_lalr_set_grammar,too_many_1,wrong_no_1},
    {"formcond1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcond1},
    {"delete_from_alglist",     too_few_2,      CC_delete_from_alglist,wrong_no_2},
    {"lx2xx",                   CC_lx2xx,       too_many_1,    wrong_no_1},
    {"ev_revgradlexcomp",       too_few_2,      CC_ev_revgradlexcomp,wrong_no_2},
    {"unaryrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_unaryrd},
    {"cr:prep",                 CC_crTprep,     too_many_1,    wrong_no_1},
    {"take-impart",             CC_takeKimpart, too_many_1,    wrong_no_1},
    {"oprinla",                 CC_oprinla,     too_many_1,    wrong_no_1},
    {"setel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setel1},
    {"reduce-degree-mod-p",     too_few_2,      CC_reduceKdegreeKmodKp,wrong_no_2},
    {"mkfil*",                  CC_mkfilH,      too_many_1,    wrong_no_1},
    {"qremf",                   too_few_2,      CC_qremf,      wrong_no_2},
    {"pasf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwmkatl},
    {"row",                     CC_row,         too_many_1,    wrong_no_1},
    {"spband_matrix",           too_few_2,      CC_spband_matrix,wrong_no_2},
    {"xdegreecheck",            CC_xdegreecheck,too_many_1,    wrong_no_1},
    {"begin1a",                 CC_begin1a,     too_many_1,    wrong_no_1},
    {"lienjactest",             CC_lienjactest, too_many_1,    wrong_no_1},
    {"fieldconv",               too_few_2,      CC_fieldconv,  wrong_no_2},
    {"moid_member",             too_few_2,      CC_moid_member,wrong_no_2},
    {"pairxvars",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pairxvars},
    {"mkeqsq",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkeqsq},
    {"ezgcdf1",                 too_few_2,      CC_ezgcdf1,    wrong_no_2},
    {"get_group_in",            CC_get_group_in,too_many_1,    wrong_no_1},
    {"cl_susiupdknowl1",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl1},
    {"naryom",                  CC_naryom,      too_many_1,    wrong_no_1},
    {"dm-eq",                   too_few_2,      CC_dmKeq,      wrong_no_2},
    {"prinlatom",               CC_prinlatom,   too_many_1,    wrong_no_1},
    {"gfdot",                   too_few_2,      CC_gfdot,      wrong_no_2},
    {"lengthcdr",               CC_lengthcdr,   too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u20", (two_args *)"12417 7671008 5222872", 0}
};

/* end of generated code */
