
/* $destdir\u06.c        Machine generated C code */

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


/* Code for getroad */

static Lisp_Object CC_getroad(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007, v0008, v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getroad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0008 = v0001;
    v0009 = v0000;
/* end of prologue */

v0010:
    v0006 = v0008;
    if (v0006 == nil) goto v0011;
    v0006 = v0009;
    v0007 = qcdr(v0006);
    v0006 = v0008;
    v0006 = qcar(v0006);
    v0006 = qcdr(v0006);
    if (equal(v0007, v0006)) goto v0012;
    v0006 = v0008;
    v0006 = qcdr(v0006);
    v0008 = v0006;
    goto v0010;

v0012:
    v0006 = v0009;
    v0006 = qcar(v0006);
    v0007 = v0008;
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    fn = elt(env, 1); /* qassoc */
    v0006 = (*qfn2(fn))(qenv(fn), v0006, v0007);
    errexit();
    v0006 = qcdr(v0006);
    return onevalue(v0006);

v0011:
    v0006 = (Lisp_Object)17; /* 1 */
    return onevalue(v0006);
}



/* Code for getrmacro */

static Lisp_Object CC_getrmacro(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0021, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrmacro");
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
    v0020 = stack[0];
    if (symbolp(v0020)) goto v0011;
    v0020 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0020); }

v0011:
    v0020 = stack[0];
    fn = elt(env, 5); /* getd */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    v0022 = v0020;
    if (v0020 == nil) goto v0024;
    v0020 = v0022;
    v0021 = qcar(v0020);
    v0020 = elt(env, 2); /* macro */
    if (v0021 == v0020) { popv(2); return onevalue(v0022); }
    else goto v0024;

v0024:
    v0021 = stack[0];
    v0020 = elt(env, 3); /* inline */
    v0020 = get(v0021, v0020);
    env = stack[-1];
    v0022 = v0020;
    if (v0020 == nil) goto v0025;
    v0020 = elt(env, 3); /* inline */
    v0021 = v0022;
    popv(2);
    return cons(v0020, v0021);

v0025:
    v0021 = stack[0];
    v0020 = elt(env, 4); /* smacro */
    v0020 = get(v0021, v0020);
    env = stack[-1];
    v0022 = v0020;
    if (v0020 == nil) goto v0026;
    v0020 = elt(env, 4); /* smacro */
    v0021 = v0022;
    popv(2);
    return cons(v0020, v0021);

v0026:
    v0020 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0020); }
/* error exit handlers */
v0023:
    popv(2);
    return nil;
}



/* Code for dp_diff */

static Lisp_Object CC_dp_diff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_diff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0029 = v0001;
    v0030 = v0000;
/* end of prologue */
    stack[0] = v0030;
    fn = elt(env, 1); /* dp_neg */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    {
        Lisp_Object v0032 = stack[0];
        popv(2);
        fn = elt(env, 2); /* dp_sum */
        return (*qfn2(fn))(qenv(fn), v0032, v0029);
    }
/* error exit handlers */
v0031:
    popv(2);
    return nil;
}



/* Code for resimp */

static Lisp_Object CC_resimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resimp");
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
    v0034 = v0000;
/* end of prologue */
    v0033 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0033; /* varstack!* */
    v0033 = v0034;
    fn = elt(env, 3); /* resimp1 */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v0033); }
/* error exit handlers */
v0027:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for insert_pv1 */

static Lisp_Object MS_CDECL CC_insert_pv1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0047;
    Lisp_Object fn;
    Lisp_Object v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "insert_pv1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0015 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for insert_pv1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0015,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0034:
    v0046 = stack[-1];
    if (v0046 == nil) goto v0028;
    v0046 = stack[-2];
    if (v0046 == nil) goto v0002;
    v0046 = stack[-1];
    v0046 = qcar(v0046);
    v0046 = qcar(v0046);
    v0047 = qcdr(v0046);
    v0046 = stack[-2];
    v0046 = qcar(v0046);
    v0046 = qcdr(v0046);
    v0046 = (Lisp_Object)greaterp2(v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    v0046 = v0046 ? lisp_true : nil;
    env = stack[-4];
    if (v0046 == nil) goto v0049;
    v0046 = stack[-1];
    v0046 = qcdr(v0046);
    stack[-3] = v0046;
    v0046 = stack[-1];
    v0047 = qcar(v0046);
    v0046 = stack[-2];
    fn = elt(env, 2); /* reduce_pv */
    v0046 = (*qfn2(fn))(qenv(fn), v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    fn = elt(env, 3); /* pv_renorm */
    v0047 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    v0046 = stack[0];
    v0046 = cons(v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    stack[0] = v0046;
    v0046 = stack[-3];
    stack[-1] = v0046;
    goto v0034;

v0049:
    v0046 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0046;
    v0047 = stack[-2];
    v0046 = stack[0];
    v0046 = cons(v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    stack[0] = v0046;
    v0046 = stack[-3];
    stack[-2] = v0046;
    goto v0034;

v0002:
    v0046 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0046;
    v0046 = stack[-1];
    v0046 = qcdr(v0046);
    stack[-3] = v0046;
    v0046 = stack[-1];
    v0047 = qcar(v0046);
    v0046 = stack[0];
    v0046 = cons(v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    stack[0] = v0046;
    v0046 = stack[-3];
    stack[-1] = v0046;
    goto v0034;

v0028:
    v0046 = stack[-2];
    if (v0046 == nil) goto v0031;
    v0047 = stack[-2];
    v0046 = stack[0];
    v0046 = cons(v0047, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0048;
        popv(5);
        return Lnreverse(nil, v0046);

v0031:
    v0046 = stack[0];
        popv(5);
        return Lnreverse(nil, v0046);
/* error exit handlers */
v0048:
    popv(5);
    return nil;
}



/* Code for modplus!: */

static Lisp_Object CC_modplusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modplus:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0051 = v0001;
    v0031 = v0000;
/* end of prologue */
    v0031 = qcdr(v0031);
    v0051 = qcdr(v0051);
    fn = elt(env, 1); /* general!-modular!-plus */
    v0051 = (*qfn2(fn))(qenv(fn), v0031, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0051);
    }
/* error exit handlers */
v0032:
    popv(1);
    return nil;
}



/* Code for prin2t */

static Lisp_Object CC_prin2t(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prin2t");
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
    v0033 = stack[0];
    v0033 = Lprinc(nil, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    v0033 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0011:
    popv(2);
    return nil;
}



/* Code for rl_smcpknowl */

static Lisp_Object CC_rl_smcpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_smcpknowl");
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
    v0050 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smcpknowl!* */
    v0050 = ncons(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    {
        Lisp_Object v0051 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0051, v0050);
    }
/* error exit handlers */
v0030:
    popv(2);
    return nil;
}



/* Code for praddf */

static Lisp_Object CC_praddf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0044;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for praddf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0024 = stack[-1];
    v0044 = qcar(v0024);
    v0024 = stack[0];
    v0024 = qcar(v0024);
    fn = elt(env, 1); /* addf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0044, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-3];
    v0024 = stack[-1];
    v0044 = qcdr(v0024);
    v0024 = stack[0];
    v0024 = qcdr(v0024);
    fn = elt(env, 1); /* addf */
    v0024 = (*qfn2(fn))(qenv(fn), v0044, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    {
        Lisp_Object v0018 = stack[-2];
        popv(4);
        return cons(v0018, v0024);
    }
/* error exit handlers */
v0003:
    popv(4);
    return nil;
}



/* Code for gcdf1 */

static Lisp_Object CC_gcdf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0081 = stack[-2];
    if (v0081 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0081 = stack[-1];
    if (v0081 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0082 = stack[-2];
    v0081 = (Lisp_Object)17; /* 1 */
    if (v0082 == v0081) goto v0004;
    v0082 = stack[-1];
    v0081 = (Lisp_Object)17; /* 1 */
    v0081 = (v0082 == v0081 ? lisp_true : nil);
    goto v0052;

v0052:
    if (v0081 == nil) goto v0083;
    v0081 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0081); }

v0083:
    v0081 = stack[-2];
    if (!consp(v0081)) goto v0043;
    v0081 = stack[-2];
    v0081 = qcar(v0081);
    v0081 = (consp(v0081) ? nil : lisp_true);
    goto v0042;

v0042:
    if (v0081 == nil) goto v0008;
    v0082 = stack[-2];
    v0081 = stack[-1];
    {
        popv(5);
        fn = elt(env, 8); /* gcdfd */
        return (*qfn2(fn))(qenv(fn), v0082, v0081);
    }

v0008:
    v0081 = stack[-1];
    if (!consp(v0081)) goto v0021;
    v0081 = stack[-1];
    v0081 = qcar(v0081);
    v0081 = (consp(v0081) ? nil : lisp_true);
    goto v0020;

v0020:
    if (v0081 == nil) goto v0084;
    v0082 = stack[-1];
    v0081 = stack[-2];
    {
        popv(5);
        fn = elt(env, 8); /* gcdfd */
        return (*qfn2(fn))(qenv(fn), v0082, v0081);
    }

v0084:
    v0081 = qvalue(elt(env, 2)); /* !*anygcd */
    if (v0081 == nil) goto v0085;
    v0081 = stack[-2];
    fn = elt(env, 9); /* num!-exponents */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    if (v0081 == nil) goto v0047;
    v0081 = stack[-1];
    fn = elt(env, 9); /* num!-exponents */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    v0081 = (v0081 == nil ? lisp_true : nil);
    goto v0087;

v0087:
    if (v0081 == nil) goto v0088;
    v0081 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0081); }

v0088:
    v0082 = stack[-2];
    v0081 = stack[-1];
    fn = elt(env, 10); /* quotf1 */
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    if (!(v0081 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0082 = stack[-1];
    v0081 = stack[-2];
    fn = elt(env, 10); /* quotf1 */
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    if (!(v0081 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0082 = stack[-2];
    v0081 = stack[-1];
    fn = elt(env, 11); /* gcdf2 */
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    stack[-3] = v0081;
    v0081 = qvalue(elt(env, 3)); /* !*gcd */
    if (v0081 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0082 = qvalue(elt(env, 4)); /* dmode!* */
    v0081 = elt(env, 5); /* (!:rd!: !:cr!:) */
    v0081 = Lmemq(nil, v0082, v0081);
    if (v0081 == nil) goto v0089;
    v0081 = qvalue(elt(env, 6)); /* nil */
    goto v0090;

v0090:
    if (v0081 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0081 = stack[-2];
    fn = elt(env, 12); /* noncomfp */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    if (!(v0081 == nil)) goto v0091;
    v0081 = stack[-1];
    fn = elt(env, 12); /* noncomfp */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    if (!(v0081 == nil)) goto v0091;
    stack[0] = elt(env, 7); /* "gcdf failed" */
    v0081 = stack[-2];
    fn = elt(env, 13); /* prepf */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    v0081 = stack[-1];
    fn = elt(env, 13); /* prepf */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    v0081 = list3(stack[0], stack[-2], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    fn = elt(env, 14); /* errach */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v0091:
    v0081 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0081); }

v0089:
    v0082 = stack[-2];
    v0081 = stack[-3];
    fn = elt(env, 10); /* quotf1 */
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    if (v0081 == nil) goto v0092;
    v0082 = stack[-1];
    v0081 = stack[-3];
    fn = elt(env, 10); /* quotf1 */
    v0081 = (*qfn2(fn))(qenv(fn), v0082, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    v0081 = (v0081 == nil ? lisp_true : nil);
    goto v0090;

v0092:
    v0081 = qvalue(elt(env, 1)); /* t */
    goto v0090;

v0047:
    v0081 = qvalue(elt(env, 1)); /* t */
    goto v0087;

v0085:
    v0081 = qvalue(elt(env, 1)); /* t */
    goto v0087;

v0021:
    v0081 = qvalue(elt(env, 1)); /* t */
    goto v0020;

v0043:
    v0081 = qvalue(elt(env, 1)); /* t */
    goto v0042;

v0004:
    v0081 = qvalue(elt(env, 1)); /* t */
    goto v0052;
/* error exit handlers */
v0086:
    popv(5);
    return nil;
}



/* Code for kernord */

static Lisp_Object CC_kernord(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernord");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0005 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0019 = stack[0];
    fn = elt(env, 1); /* kernord!-split */
    v0005 = (*qfn2(fn))(qenv(fn), v0019, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-2];
    stack[0] = v0005;
    v0005 = stack[0];
    v0005 = qcar(v0005);
    fn = elt(env, 2); /* kernord!-sort */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-2];
    v0005 = stack[0];
    v0005 = qcdr(v0005);
    fn = elt(env, 2); /* kernord!-sort */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    {
        Lisp_Object v0054 = stack[-1];
        popv(3);
        return Lappend(nil, v0054, v0005);
    }
/* error exit handlers */
v0080:
    popv(3);
    return nil;
}



/* Code for ibalp_minclnr */

static Lisp_Object CC_ibalp_minclnr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0097;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_minclnr");
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
    v0097 = v0000;
/* end of prologue */
    v0096 = (Lisp_Object)1600001; /* 100000 */
    stack[-2] = v0096;
    v0096 = v0097;
    stack[-1] = v0096;
    goto v0027;

v0027:
    v0096 = stack[-1];
    if (v0096 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0096 = stack[-1];
    v0096 = qcar(v0096);
    stack[0] = v0096;
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    v0096 = qcdr(v0096);
    v0096 = qcdr(v0096);
    v0096 = qcdr(v0096);
    v0096 = qcar(v0096);
    if (!(v0096 == nil)) goto v0098;
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    v0096 = qcdr(v0096);
    v0097 = qcar(v0096);
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    v0096 = qcdr(v0096);
    v0096 = qcdr(v0096);
    v0096 = qcar(v0096);
    v0097 = plus2(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    v0096 = stack[-2];
    v0096 = (Lisp_Object)lessp2(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0096 = v0096 ? lisp_true : nil;
    env = stack[-3];
    if (v0096 == nil) goto v0098;
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    v0096 = qcdr(v0096);
    v0097 = qcar(v0096);
    v0096 = stack[0];
    v0096 = qcdr(v0096);
    v0096 = qcdr(v0096);
    v0096 = qcdr(v0096);
    v0096 = qcar(v0096);
    v0096 = plus2(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    stack[-2] = v0096;
    goto v0098;

v0098:
    v0096 = stack[-1];
    v0096 = qcdr(v0096);
    stack[-1] = v0096;
    goto v0027;
/* error exit handlers */
v0040:
    popv(4);
    return nil;
}



/* Code for sfto_mvartest */

static Lisp_Object CC_sfto_mvartest(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0100, v0003;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_mvartest");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0100 = v0001;
    v0003 = v0000;
/* end of prologue */
    v0099 = v0003;
    if (!consp(v0099)) goto v0027;
    v0099 = v0003;
    v0099 = qcar(v0099);
    v0099 = (consp(v0099) ? nil : lisp_true);
    goto v0011;

v0011:
    if (v0099 == nil) goto v0055;
    v0099 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0099);

v0055:
    v0099 = v0003;
    v0099 = qcar(v0099);
    v0099 = qcar(v0099);
    v0099 = qcar(v0099);
    v0099 = (v0099 == v0100 ? lisp_true : nil);
    return onevalue(v0099);

v0027:
    v0099 = qvalue(elt(env, 1)); /* t */
    goto v0011;
}



/* Code for powers2 */

static Lisp_Object MS_CDECL CC_powers2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0101, v0023;
    Lisp_Object fn;
    Lisp_Object v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powers2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0015 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0015,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0034:
    v0022 = stack[-2];
    if (!consp(v0022)) goto v0051;
    v0022 = stack[-2];
    v0022 = qcar(v0022);
    v0022 = (consp(v0022) ? nil : lisp_true);
    goto v0030;

v0030:
    if (v0022 == nil) goto v0102;
    v0022 = stack[-2];
    if (v0022 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0101 = stack[0];
    v0022 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* powers4 */
        return (*qfn2(fn))(qenv(fn), v0101, v0022);
    }

v0102:
    v0022 = stack[-2];
    v0022 = qcar(v0022);
    v0022 = qcdr(v0022);
    stack[-3] = v0022;
    v0022 = stack[-2];
    v0023 = qcdr(v0022);
    v0101 = stack[-1];
    v0022 = stack[0];
    v0022 = CC_powers2(env, 3, v0023, v0101, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    stack[-1] = v0022;
    v0022 = stack[-2];
    v0022 = qcar(v0022);
    v0101 = qcar(v0022);
    v0022 = stack[0];
    v0022 = cons(v0101, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    stack[0] = v0022;
    v0022 = stack[-3];
    stack[-2] = v0022;
    goto v0034;

v0051:
    v0022 = qvalue(elt(env, 1)); /* t */
    goto v0030;
/* error exit handlers */
v0096:
    popv(5);
    return nil;
}



/* Code for mathml */

static Lisp_Object MS_CDECL CC_mathml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mathml");
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
/* end of prologue */
    fn = elt(env, 2); /* lex */
    v0034 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0011:
    popv(1);
    return nil;
}



/* Code for bcsum */

static Lisp_Object CC_bcsum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0009, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcsum");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0008 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0008 == nil) goto v0005;
    v0009 = stack[-1];
    v0008 = stack[0];
    v0008 = plus2(v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v0008);
    }

v0005:
    v0042 = stack[-1];
    v0009 = stack[0];
    v0008 = elt(env, 2); /* plus2 */
    fn = elt(env, 4); /* bcint2op */
    v0008 = (*qfnn(fn))(qenv(fn), 3, v0042, v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    if (!(v0008 == nil)) { popv(3); return onevalue(v0008); }
    v0009 = stack[-1];
    v0008 = stack[0];
    fn = elt(env, 5); /* addsq */
    v0008 = (*qfn2(fn))(qenv(fn), v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v0008);
    }
/* error exit handlers */
v0025:
    popv(3);
    return nil;
}



/* Code for mknwedge */

static Lisp_Object CC_mknwedge(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0098;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mknwedge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0098 = v0000;
/* end of prologue */
    v0004 = v0098;
    v0004 = qcdr(v0004);
    if (v0004 == nil) goto v0032;
    v0004 = elt(env, 1); /* wedge */
    return cons(v0004, v0098);

v0032:
    v0004 = v0098;
    v0004 = qcar(v0004);
    return onevalue(v0004);
}



/* Code for worderp */

static Lisp_Object CC_worderp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0119, v0120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for worderp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0010:
    v0118 = stack[-1];
    if (!consp(v0118)) goto v0121;
    v0118 = stack[-1];
    v0118 = qcar(v0118);
    if (!symbolp(v0118)) v0118 = nil;
    else { v0118 = qfastgets(v0118);
           if (v0118 != nil) { v0118 = elt(v0118, 16); /* indexvar */
#ifdef RECORD_GET
             if (v0118 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0118 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0118 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0118 == SPID_NOPROP) v0118 = nil; else v0118 = lisp_true; }}
#endif
    if (v0118 == nil) goto v0100;
    v0118 = stack[0];
    if (!consp(v0118)) goto v0044;
    v0118 = stack[0];
    v0118 = qcar(v0118);
    if (!symbolp(v0118)) v0118 = nil;
    else { v0118 = qfastgets(v0118);
           if (v0118 != nil) { v0118 = elt(v0118, 16); /* indexvar */
#ifdef RECORD_GET
             if (v0118 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0118 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0118 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0118 == SPID_NOPROP) v0118 = nil; else v0118 = lisp_true; }}
#endif
    goto v0050;

v0050:
    if (v0118 == nil) goto v0027;
    v0119 = stack[-1];
    v0118 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* indexvarordp */
        return (*qfn2(fn))(qenv(fn), v0119, v0118);
    }

v0027:
    v0118 = stack[-1];
    if (!consp(v0118)) goto v0122;
    v0119 = stack[-1];
    v0118 = qvalue(elt(env, 3)); /* kord!* */
    v0118 = Lmemq(nil, v0119, v0118);
    goto v0123;

v0123:
    if (v0118 == nil) goto v0124;
    v0118 = stack[0];
    if (!consp(v0118)) goto v0125;
    v0119 = stack[0];
    v0118 = qvalue(elt(env, 3)); /* kord!* */
    v0118 = Lmemq(nil, v0119, v0118);
    goto v0037;

v0037:
    if (v0118 == nil) goto v0075;
    v0119 = stack[-1];
    v0118 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* ordop */
        return (*qfn2(fn))(qenv(fn), v0119, v0118);
    }

v0075:
    v0118 = stack[0];
    fn = elt(env, 6); /* peel */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    v0120 = v0118;
    v0119 = stack[-1];
    v0118 = v0120;
    if (v0119 == v0118) goto v0048;
    v0118 = stack[-1];
    v0119 = v0120;
    stack[-1] = v0118;
    stack[0] = v0119;
    goto v0010;

v0048:
    v0118 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v0118); }

v0125:
    v0118 = qvalue(elt(env, 2)); /* t */
    goto v0037;

v0124:
    v0118 = stack[0];
    if (!consp(v0118)) goto v0127;
    v0119 = stack[0];
    v0118 = qvalue(elt(env, 3)); /* kord!* */
    v0118 = Lmemq(nil, v0119, v0118);
    goto v0128;

v0128:
    if (v0118 == nil) goto v0129;
    v0118 = stack[-1];
    fn = elt(env, 6); /* peel */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    v0120 = v0118;
    v0119 = v0120;
    v0118 = stack[0];
    if (v0119 == v0118) goto v0060;
    v0119 = v0120;
    v0118 = stack[0];
    stack[-1] = v0119;
    stack[0] = v0118;
    goto v0010;

v0060:
    v0118 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0118); }

v0129:
    v0118 = stack[-1];
    fn = elt(env, 6); /* peel */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    stack[-1] = v0118;
    v0118 = stack[0];
    fn = elt(env, 6); /* peel */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    stack[0] = v0118;
    goto v0010;

v0127:
    v0118 = qvalue(elt(env, 2)); /* t */
    goto v0128;

v0122:
    v0118 = qvalue(elt(env, 2)); /* t */
    goto v0123;

v0044:
    v0118 = qvalue(elt(env, 1)); /* nil */
    goto v0050;

v0100:
    v0118 = qvalue(elt(env, 1)); /* nil */
    goto v0050;

v0121:
    v0118 = qvalue(elt(env, 1)); /* nil */
    goto v0050;
/* error exit handlers */
v0126:
    popv(3);
    return nil;
}



/* Code for vecopp */

static Lisp_Object CC_vecopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0016, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vecopp");
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
/* copy arguments values to proper place */
    v0017 = v0000;
/* end of prologue */
    v0122 = v0017;
    if (symbolp(v0122)) goto v0030;
    v0122 = qvalue(elt(env, 1)); /* nil */
    goto v0033;

v0033:
    if (!(v0122 == nil)) return onevalue(v0122);
    v0122 = v0017;
    if (!consp(v0122)) goto v0124;
    v0122 = v0017;
    v0122 = qcar(v0122);
    if (!symbolp(v0122)) v0016 = nil;
    else { v0016 = qfastgets(v0122);
           if (v0016 != nil) { v0016 = elt(v0016, 18); /* phystype */
#ifdef RECORD_GET
             if (v0016 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0016 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0016 == SPID_NOPROP) v0016 = nil; }}
#endif
    v0122 = elt(env, 2); /* vector */
    if (v0016 == v0122) goto v0024;
    v0122 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0122);

v0024:
    v0122 = v0017;
    v0122 = qcdr(v0122);
    v0122 = qcar(v0122);
    fn = elt(env, 3); /* isanindex */
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    errexit();
    v0122 = (v0122 == nil ? lisp_true : nil);
    return onevalue(v0122);

v0124:
    v0122 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0122);

v0030:
    v0122 = v0017;
    if (!symbolp(v0122)) v0016 = nil;
    else { v0016 = qfastgets(v0122);
           if (v0016 != nil) { v0016 = elt(v0016, 18); /* phystype */
#ifdef RECORD_GET
             if (v0016 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0016 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0016 == SPID_NOPROP) v0016 = nil; }}
#endif
    v0122 = elt(env, 2); /* vector */
    v0122 = (v0016 == v0122 ? lisp_true : nil);
    goto v0033;
}



/* Code for !*ssave */

static Lisp_Object CC_Hssave(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0133, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *ssave");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0047 = qvalue(elt(env, 1)); /* !*uncached */
    if (!(v0047 == nil)) goto v0033;
    stack[-4] = qvalue(elt(env, 2)); /* alglist!* */
    v0133 = qvalue(elt(env, 3)); /* !*sub2 */
    v0047 = stack[-3];
    v0133 = cons(v0133, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    v0047 = qvalue(elt(env, 2)); /* alglist!* */
    v0047 = qcar(v0047);
    stack[-1] = v0133;
    stack[0] = v0047;
    v0047 = stack[0];
    if (v0047 == nil) goto v0018;
    v0133 = qvalue(elt(env, 5)); /* alglist_count!* */
    v0047 = qvalue(elt(env, 6)); /* alglist_limit!* */
    v0047 = (Lisp_Object)greaterp2(v0133, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    v0047 = v0047 ? lisp_true : nil;
    env = stack[-5];
    goto v0003;

v0003:
    if (v0047 == nil) goto v0040;
    v0047 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v0047; /* alglist_count!* */
    v0110 = (Lisp_Object)161; /* 10 */
    v0133 = (Lisp_Object)49; /* 3 */
    v0047 = elt(env, 7); /* 2.0 */
    fn = elt(env, 9); /* mkhash */
    v0047 = (*qfnn(fn))(qenv(fn), 3, v0110, v0133, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    stack[0] = v0047;
    v0110 = stack[-2];
    v0133 = stack[0];
    v0047 = stack[-1];
    fn = elt(env, 10); /* puthash */
    v0047 = (*qfnn(fn))(qenv(fn), 3, v0110, v0133, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    v0047 = stack[0];
    goto v0051;

v0051:
    v0047 = Lrplaca(nil, stack[-4], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    goto v0033;

v0033:
    v0047 = qvalue(elt(env, 8)); /* simpcount!* */
    v0047 = sub1(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    qvalue(elt(env, 8)) = v0047; /* simpcount!* */
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v0040:
    v0110 = stack[-2];
    v0133 = stack[0];
    v0047 = stack[-1];
    fn = elt(env, 10); /* puthash */
    v0047 = (*qfnn(fn))(qenv(fn), 3, v0110, v0133, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    v0047 = qvalue(elt(env, 5)); /* alglist_count!* */
    v0047 = add1(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-5];
    qvalue(elt(env, 5)) = v0047; /* alglist_count!* */
    v0047 = stack[0];
    goto v0051;

v0018:
    v0047 = qvalue(elt(env, 4)); /* t */
    goto v0003;
/* error exit handlers */
v0134:
    popv(6);
    return nil;
}



/* Code for pv_sort2a */

static Lisp_Object CC_pv_sort2a(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0109;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_sort2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0010:
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    if (v0108 == nil) goto v0083;
    v0108 = stack[-1];
    v0109 = qcdr(v0108);
    v0108 = stack[0];
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    v0108 = (Lisp_Object)greaterp2(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    v0108 = v0108 ? lisp_true : nil;
    env = stack[-3];
    if (v0108 == nil) goto v0049;
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    stack[0] = v0108;
    goto v0010;

v0049:
    v0108 = stack[0];
    v0109 = qcar(v0108);
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    v0108 = cons(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-3];
    stack[-2] = v0108;
    v0109 = stack[0];
    v0108 = stack[-1];
    v0109 = Lrplaca(nil, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    v0108 = stack[-2];
        popv(4);
        return Lrplacd(nil, v0109, v0108);

v0083:
    v0108 = stack[-1];
    v0109 = qcdr(v0108);
    v0108 = stack[0];
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    v0108 = (Lisp_Object)greaterp2(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    v0108 = v0108 ? lisp_true : nil;
    env = stack[-3];
    if (v0108 == nil) goto v0102;
    v0108 = stack[-1];
    v0108 = ncons(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    {
        Lisp_Object v0142 = stack[0];
        popv(4);
        return Lrplacd(nil, v0142, v0108);
    }

v0102:
    v0108 = stack[0];
    v0109 = qcar(v0108);
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    v0108 = cons(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-3];
    stack[-2] = v0108;
    v0109 = stack[0];
    v0108 = stack[-1];
    v0109 = Lrplaca(nil, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    v0108 = stack[-2];
        popv(4);
        return Lrplacd(nil, v0109, v0108);
/* error exit handlers */
v0141:
    popv(4);
    return nil;
}



/* Code for mkgi */

static Lisp_Object CC_mkgi(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0031, v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkgi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0051 = v0001;
    v0031 = v0000;
/* end of prologue */
    v0032 = elt(env, 1); /* !:gi!: */
    return list2star(v0032, v0031, v0051);
}



/* Code for removev */

static Lisp_Object CC_removev(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0094, v0123, v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for removev");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0122 = v0001;
    v0123 = v0000;
/* end of prologue */

v0010:
    v0124 = v0123;
    if (v0124 == nil) goto v0030;
    v0124 = v0123;
    v0124 = qcdr(v0124);
    v0094 = qcar(v0124);
    v0124 = v0122;
    if (v0094 == v0124) goto v0018;
    v0124 = v0123;
    v0124 = qcdr(v0124);
    v0123 = v0124;
    goto v0010;

v0018:
    v0124 = v0123;
    v0094 = v0123;
    v0094 = qcdr(v0094);
    v0094 = qcdr(v0094);
        popv(1);
        return Lrplacd(nil, v0124, v0094);

v0030:
    v0094 = elt(env, 1); /* "Vertex" */
    v0123 = v0122;
    v0124 = elt(env, 2); /* "is absent." */
    v0124 = list3(v0094, v0123, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cerror */
        return (*qfn1(fn))(qenv(fn), v0124);
    }
/* error exit handlers */
v0016:
    popv(1);
    return nil;
}



/* Code for tayexp!-min2 */

static Lisp_Object CC_tayexpKmin2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-min2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0004 = stack[-1];
    v0052 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v0052 = (*qfn2(fn))(qenv(fn), v0004, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    if (v0052 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
/* error exit handlers */
v0005:
    popv(2);
    return nil;
}



/* Code for qqe_qtidp */

static Lisp_Object CC_qqe_qtidp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0029;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qtidp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0000;
/* end of prologue */
    if (!symbolp(v0050)) v0050 = nil;
    else { v0050 = qfastgets(v0050);
           if (v0050 != nil) { v0050 = elt(v0050, 10); /* idtype */
#ifdef RECORD_GET
             if (v0050 != SPID_NOPROP)
                record_get(elt(fastget_names, 10), 1);
             else record_get(elt(fastget_names, 10), 0),
                v0050 = nil; }
           else record_get(elt(fastget_names, 10), 0); }
#else
             if (v0050 == SPID_NOPROP) v0050 = nil; }}
#endif
    v0029 = elt(env, 1); /* qt */
    v0050 = (v0050 == v0029 ? lisp_true : nil);
    return onevalue(v0050);
}



/* Code for emtch */

static Lisp_Object CC_emtch(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for emtch");
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
    v0113 = stack[0];
    if (!consp(v0113)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v0113 = stack[0];
    fn = elt(env, 1); /* opmtch */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    v0005 = v0113;
    v0113 = v0005;
    if (v0113 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    else { popv(1); return onevalue(v0005); }
/* error exit handlers */
v0012:
    popv(1);
    return nil;
}



/* Code for subscriptedvarp */

static Lisp_Object CC_subscriptedvarp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0044;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subscriptedvarp");
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
    v0044 = qvalue(elt(env, 1)); /* nil */
    v0024 = stack[0];
    fn = elt(env, 3); /* symtabget */
    v0024 = (*qfn2(fn))(qenv(fn), v0044, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-1];
    v0044 = Llength(nil, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-1];
    v0024 = (Lisp_Object)33; /* 2 */
    v0024 = (Lisp_Object)greaterp2(v0044, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    v0024 = v0024 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0024 == nil)) { popv(2); return onevalue(v0024); }
    v0024 = stack[0];
    v0044 = elt(env, 2); /* subscripted */
        popv(2);
        return Lflagp(nil, v0024, v0044);
/* error exit handlers */
v0099:
    popv(2);
    return nil;
}



/* Code for fast!-column!-dim */

static Lisp_Object CC_fastKcolumnKdim(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0030;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fast-column-dim");
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
/* copy arguments values to proper place */
    v0029 = v0000;
/* end of prologue */
    v0030 = v0029;
    v0029 = (Lisp_Object)1; /* 0 */
    v0029 = *(Lisp_Object *)((char *)v0030 + (CELL-TAG_VECTOR) + ((int32_t)v0029/(16/CELL)));
    v0029 = Lupbv(nil, v0029);
    errexit();
    return add1(v0029);
}



/* Code for xdegree */

static Lisp_Object CC_xdegree(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xdegree");
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
/* copy arguments values to proper place */
    v0051 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* deg!*form */
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    errexit();
    v0031 = v0051;
    v0051 = v0031;
    if (!(v0051 == nil)) return onevalue(v0031);
    v0051 = (Lisp_Object)1; /* 0 */
    return onevalue(v0051);
}



/* Code for deg!*form */

static Lisp_Object CC_degHform(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0150, v0151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deg*form");
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

v0152:
    v0149 = stack[0];
    if (!consp(v0149)) goto v0045;
    v0149 = stack[0];
    v0149 = qcar(v0149);
    v0151 = v0149;
    v0149 = v0151;
    if (!symbolp(v0149)) v0149 = nil;
    else { v0149 = qfastgets(v0149);
           if (v0149 != nil) { v0149 = elt(v0149, 16); /* indexvar */
#ifdef RECORD_GET
             if (v0149 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0149 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0149 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0149 == SPID_NOPROP) v0149 = nil; else v0149 = lisp_true; }}
#endif
    if (v0149 == nil) goto v0153;
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    v0150 = Llength(nil, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    v0149 = stack[0];
    v0149 = qcar(v0149);
    if (!symbolp(v0149)) v0149 = nil;
    else { v0149 = qfastgets(v0149);
           if (v0149 != nil) { v0149 = elt(v0149, 25); /* ifdegree */
#ifdef RECORD_GET
             if (v0149 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v0149 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v0149 == SPID_NOPROP) v0149 = nil; }}
#endif
    v0149 = Lassoc(nil, v0150, v0149);
    v0150 = v0149;
    v0149 = v0150;
    if (v0149 == nil) goto v0122;
    v0149 = v0150;
    v0149 = qcdr(v0149);
    { popv(3); return onevalue(v0149); }

v0122:
    v0149 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0149); }

v0153:
    v0150 = v0151;
    v0149 = elt(env, 2); /* wedge */
    if (v0150 == v0149) goto v0095;
    v0150 = v0151;
    v0149 = elt(env, 3); /* d */
    if (v0150 == v0149) goto v0140;
    v0150 = v0151;
    v0149 = elt(env, 4); /* hodge */
    if (v0150 == v0149) goto v0133;
    v0150 = v0151;
    v0149 = elt(env, 6); /* partdf */
    if (v0150 == v0149) goto v0108;
    v0150 = v0151;
    v0149 = elt(env, 7); /* liedf */
    if (v0150 == v0149) goto v0155;
    v0150 = v0151;
    v0149 = elt(env, 8); /* innerprod */
    if (v0150 == v0149) goto v0104;
    v0150 = v0151;
    v0149 = elt(env, 9); /* (plus minus difference quotient) */
    v0149 = Lmemq(nil, v0150, v0149);
    if (v0149 == nil) goto v0156;
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    v0149 = qcar(v0149);
    stack[0] = v0149;
    goto v0152;

v0156:
    v0150 = v0151;
    v0149 = elt(env, 10); /* times */
    if (v0150 == v0149) goto v0062;
    v0149 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0149); }

v0062:
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    {
        popv(3);
        fn = elt(env, 11); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v0149);
    }

v0104:
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    v0149 = qcdr(v0149);
    v0149 = qcar(v0149);
    v0149 = CC_degHform(env, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    {
        Lisp_Object v0157 = stack[-1];
        popv(3);
        fn = elt(env, 12); /* addd */
        return (*qfn2(fn))(qenv(fn), v0157, v0149);
    }

v0155:
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    v0149 = qcdr(v0149);
    v0149 = qcar(v0149);
    stack[0] = v0149;
    goto v0152;

v0108:
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    v0149 = qcdr(v0149);
    if (v0149 == nil) goto v0127;
    v0149 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0149); }

v0127:
    v0149 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v0149); }

v0133:
    stack[-1] = qvalue(elt(env, 5)); /* dimex!* */
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    v0149 = qcar(v0149);
    v0149 = CC_degHform(env, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    fn = elt(env, 13); /* negf */
    v0149 = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    {
        Lisp_Object v0158 = stack[-1];
        popv(3);
        fn = elt(env, 14); /* addf */
        return (*qfn2(fn))(qenv(fn), v0158, v0149);
    }

v0140:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    v0149 = qcar(v0149);
    v0149 = CC_degHform(env, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    {
        Lisp_Object v0159 = stack[-1];
        popv(3);
        fn = elt(env, 12); /* addd */
        return (*qfn2(fn))(qenv(fn), v0159, v0149);
    }

v0095:
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    {
        popv(3);
        fn = elt(env, 11); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v0149);
    }

v0045:
    v0149 = stack[0];
    if (!symbolp(v0149)) v0149 = nil;
    else { v0149 = qfastgets(v0149);
           if (v0149 != nil) { v0149 = elt(v0149, 29); /* fdegree */
#ifdef RECORD_GET
             if (v0149 != SPID_NOPROP)
                record_get(elt(fastget_names, 29), 1);
             else record_get(elt(fastget_names, 29), 0),
                v0149 = nil; }
           else record_get(elt(fastget_names, 29), 0); }
#else
             if (v0149 == SPID_NOPROP) v0149 = nil; }}
#endif
    v0150 = v0149;
    v0149 = v0150;
    if (v0149 == nil) goto v0083;
    v0149 = v0150;
    v0149 = qcar(v0149);
    { popv(3); return onevalue(v0149); }

v0083:
    v0149 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0149); }
/* error exit handlers */
v0154:
    popv(3);
    return nil;
}



/* Code for convchk */

static Lisp_Object CC_convchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0160, v0014, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convchk");
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
    v0160 = v0000;
/* end of prologue */
    v0014 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v0014 == nil) goto v0010;
    v0014 = v0160;
    if (!(!consp(v0014))) { popv(1); return onevalue(v0160); }
    v0014 = v0160;
    v0014 = Lfloatp(nil, v0014);
    env = stack[0];
    if (v0014 == nil) goto v0004;
    {
        popv(1);
        fn = elt(env, 3); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v0160);
    }

v0004:
    v0014 = v0160;
    if (!(!consp(v0014))) goto v0019;
    v0014 = v0160;
    v0014 = integerp(v0014);
    if (v0014 == nil) goto v0042;
    v0013 = elt(env, 2); /* !:rd!: */
    v0014 = v0160;
    v0160 = (Lisp_Object)1; /* 0 */
    v0160 = list2star(v0013, v0014, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[0];
    goto v0019;

v0019:
    {
        popv(1);
        fn = elt(env, 4); /* normbf */
        return (*qfn1(fn))(qenv(fn), v0160);
    }

v0042:
    fn = elt(env, 5); /* read!:num */
    v0160 = (*qfn1(fn))(qenv(fn), v0160);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[0];
    goto v0019;

v0010:
    v0014 = v0160;
    if (!consp(v0014)) { popv(1); return onevalue(v0160); }
    {
        popv(1);
        fn = elt(env, 6); /* bf2flck */
        return (*qfn1(fn))(qenv(fn), v0160);
    }
/* error exit handlers */
v0026:
    popv(1);
    return nil;
}



/* Code for red!-char!-downcase */

static Lisp_Object CC_redKcharKdowncase(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0113, v0005;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-char-downcase");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0113 = v0000;
/* end of prologue */
    v0098 = v0113;
    v0005 = qvalue(elt(env, 1)); /* charassoc!* */
    v0098 = Latsoc(nil, v0098, v0005);
    v0005 = v0098;
    v0098 = v0005;
    if (v0098 == nil) return onevalue(v0113);
    v0098 = v0005;
    v0098 = qcdr(v0098);
    return onevalue(v0098);
}



/* Code for getphystype!*sq */

static Lisp_Object CC_getphystypeHsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystype*sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0033 = v0000;
/* end of prologue */
    v0033 = qcar(v0033);
    v0033 = qcar(v0033);
    {
        fn = elt(env, 1); /* getphystypesf */
        return (*qfn1(fn))(qenv(fn), v0033);
    }
}



/* Code for contrsp2 */

static Lisp_Object MS_CDECL CC_contrsp2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0026;
    Lisp_Object v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contrsp2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0015 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contrsp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0015,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = (Lisp_Object)33; /* 2 */
    v0013 = stack[-2];
    v0013 = Llength(nil, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    if (stack[-3] == v0013) goto v0004;
    v0013 = nil;
    { popv(5); return onevalue(v0013); }

v0004:
    v0026 = stack[0];
    v0013 = stack[-2];
    v0013 = qcar(v0013);
    if (equal(v0026, v0013)) goto v0024;
    v0026 = stack[0];
    v0013 = stack[-2];
    v0013 = qcdr(v0013);
    v0013 = qcar(v0013);
    if (equal(v0026, v0013)) goto v0123;
    v0013 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0013); }

v0123:
    v0013 = stack[-2];
    v0026 = qcar(v0013);
    v0013 = stack[-1];
    popv(5);
    return cons(v0026, v0013);

v0024:
    v0013 = stack[-2];
    v0013 = qcdr(v0013);
    v0026 = qcar(v0013);
    v0013 = stack[-1];
    popv(5);
    return cons(v0026, v0013);
/* error exit handlers */
v0022:
    popv(5);
    return nil;
}



/* Code for groeb!=testa */

static Lisp_Object CC_groebMtesta(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=testa");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0012 = v0000;
/* end of prologue */
    v0053 = v0012;
    v0012 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* nth */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0053, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0053 = stack[0];
    v0012 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* nth */
    v0012 = (*qfn2(fn))(qenv(fn), v0053, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    {
        Lisp_Object v0044 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v0044, v0012);
    }
/* error exit handlers */
v0024:
    popv(3);
    return nil;
}



/* Code for pcmult */

static Lisp_Object CC_pcmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pcmult");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0001;
    v0097 = v0000;
/* end of prologue */
    stack[-5] = v0097;
    v0097 = stack[-5];
    if (v0097 == nil) goto v0029;
    v0097 = stack[-5];
    v0097 = qcar(v0097);
    v0140 = v0097;
    stack[0] = qcar(v0140);
    v0140 = stack[-4];
    v0097 = qcdr(v0097);
    fn = elt(env, 2); /* cprod */
    v0097 = (*qfn2(fn))(qenv(fn), v0140, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0097 = cons(stack[0], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0097 = ncons(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-2] = v0097;
    stack[-3] = v0097;
    goto v0011;

v0011:
    v0097 = stack[-5];
    v0097 = qcdr(v0097);
    stack[-5] = v0097;
    v0097 = stack[-5];
    if (v0097 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0097 = stack[-5];
    v0097 = qcar(v0097);
    v0140 = v0097;
    stack[0] = qcar(v0140);
    v0140 = stack[-4];
    v0097 = qcdr(v0097);
    fn = elt(env, 2); /* cprod */
    v0097 = (*qfn2(fn))(qenv(fn), v0140, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0097 = cons(stack[0], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0097 = ncons(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0097 = Lrplacd(nil, stack[-1], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0097 = stack[-2];
    v0097 = qcdr(v0097);
    stack[-2] = v0097;
    goto v0011;

v0029:
    v0097 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0097); }
/* error exit handlers */
v0111:
    popv(7);
    return nil;
}



/* Code for gperm1 */

static Lisp_Object MS_CDECL CC_gperm1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0077, v0020;
    Lisp_Object fn;
    Lisp_Object v0058, v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gperm1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0015 = va_arg(aa, Lisp_Object);
    v0058 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0058,v0015,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0015,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0058;
    stack[-2] = v0015;
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */

v0027:
    v0084 = stack[-4];
    if (v0084 == nil) goto v0032;
    v0084 = stack[-4];
    v0084 = qcdr(v0084);
    stack[-5] = v0084;
    v0084 = stack[-4];
    v0077 = qcar(v0084);
    v0084 = stack[-2];
    v0084 = cons(v0077, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-6];
    stack[0] = v0084;
    v0077 = stack[-3];
    v0084 = stack[-2];
    v0084 = cons(v0077, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-6];
    fn = elt(env, 1); /* rev */
    v0077 = (*qfn2(fn))(qenv(fn), stack[-4], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-6];
    v0084 = stack[-1];
    v0084 = cons(v0077, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-6];
    stack[-1] = v0084;
    v0084 = stack[0];
    stack[-2] = v0084;
    v0084 = stack[-5];
    stack[-4] = v0084;
    goto v0027;

v0032:
    v0020 = stack[-3];
    v0077 = stack[-2];
    v0084 = stack[-1];
    popv(7);
    return acons(v0020, v0077, v0084);
/* error exit handlers */
v0132:
    popv(7);
    return nil;
}



/* Code for arzerop!: */

static Lisp_Object CC_arzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arzerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0010 = v0000;
/* end of prologue */
    v0010 = qcdr(v0010);
    v0010 = (v0010 == nil ? lisp_true : nil);
    return onevalue(v0010);
}



/* Code for c!:ordexp */

static Lisp_Object CC_cTordexp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0006, v0007, v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:ordexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0001;
    v0007 = v0000;
/* end of prologue */

v0010:
    v0102 = v0007;
    if (v0102 == nil) goto v0011;
    v0102 = v0007;
    v0008 = qcar(v0102);
    v0102 = v0006;
    v0102 = qcar(v0102);
    if (equal(v0008, v0102)) goto v0029;
    v0102 = v0007;
    v0102 = qcar(v0102);
    v0006 = qcar(v0006);
    {
        fn = elt(env, 2); /* c!:ordxp */
        return (*qfn2(fn))(qenv(fn), v0102, v0006);
    }

v0029:
    v0102 = v0007;
    v0102 = qcdr(v0102);
    v0007 = v0102;
    v0102 = v0006;
    v0102 = qcdr(v0102);
    v0006 = v0102;
    goto v0010;

v0011:
    v0102 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0102);
}



/* Code for minus!-mod!-p */

static Lisp_Object CC_minusKmodKp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minus-mod-p");
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
    stack[-2] = nil;
    goto v0010;

v0010:
    v0093 = stack[-1];
    if (v0093 == nil) goto v0011;
    v0093 = stack[-1];
    if (!consp(v0093)) goto v0083;
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    v0093 = (consp(v0093) ? nil : lisp_true);
    goto v0032;

v0032:
    if (v0093 == nil) goto v0079;
    v0153 = stack[-2];
    v0093 = stack[-1];
    {   int32_t w = int_of_fixnum(v0093);
        if (w != 0) w = current_modulus - w;
        v0093 = fixnum_of_int(w);
    }
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0153, v0093);
    }

v0079:
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    stack[0] = qcar(v0093);
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    v0093 = qcdr(v0093);
    v0153 = CC_minusKmodKp(env, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0093 = stack[-2];
    v0093 = acons(stack[0], v0153, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    stack[-2] = v0093;
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    stack[-1] = v0093;
    goto v0010;

v0083:
    v0093 = qvalue(elt(env, 1)); /* t */
    goto v0032;

v0011:
    v0093 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0093);
    }
/* error exit handlers */
v0014:
    popv(4);
    return nil;
}



/* Code for polynomadd */

static Lisp_Object CC_polynomadd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0103, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polynomadd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0103 = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0146 = stack[-2];
    stack[-3] = v0146;
    v0146 = v0103;
    stack[-1] = v0146;
    goto v0030;

v0030:
    v0146 = stack[-3];
    v0146 = qcar(v0146);
    if (v0146 == nil) goto v0029;
    v0146 = stack[-1];
    v0146 = qcar(v0146);
    if (v0146 == nil) goto v0029;
    v0146 = stack[-3];
    v0103 = qcar(v0146);
    v0146 = stack[-1];
    v0146 = qcar(v0146);
    fn = elt(env, 2); /* monomcompare */
    v0146 = (*qfn2(fn))(qenv(fn), v0103, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0104 = v0146;
    v0103 = v0104;
    v0146 = (Lisp_Object)17; /* 1 */
    if (v0103 == v0146) goto v0078;
    v0103 = v0104;
    v0146 = (Lisp_Object)-15; /* -1 */
    if (v0103 == v0146) goto v0020;
    v0103 = stack[-3];
    v0146 = stack[-3];
    v0146 = qcdr(v0146);
    v0146 = qcar(v0146);
    v0103 = Lrplaca(nil, v0103, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0146 = stack[-3];
    v0146 = qcdr(v0146);
    v0146 = qcdr(v0146);
    v0146 = Lrplacd(nil, v0103, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0146 = stack[-1];
    v0146 = qcdr(v0146);
    stack[-1] = v0146;
    goto v0030;

v0020:
    stack[0] = stack[-3];
    v0146 = stack[-3];
    v0103 = qcar(v0146);
    v0146 = stack[-3];
    v0146 = qcdr(v0146);
    v0146 = cons(v0103, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0103 = Lrplacd(nil, stack[0], v0146);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0146 = stack[-1];
    v0146 = qcar(v0146);
    v0146 = Lrplaca(nil, v0103, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0146 = stack[-3];
    v0146 = qcdr(v0146);
    stack[-3] = v0146;
    v0146 = stack[-1];
    v0146 = qcdr(v0146);
    stack[-1] = v0146;
    goto v0030;

v0078:
    v0146 = stack[-3];
    v0146 = qcdr(v0146);
    stack[-3] = v0146;
    goto v0030;

v0029:
    v0146 = stack[-1];
    v0146 = qcar(v0146);
    if (v0146 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0103 = stack[-3];
    v0146 = stack[-1];
    v0146 = Lrplacd(nil, v0103, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    stack[0] = v0146;
    v0103 = stack[0];
    v0146 = stack[0];
    v0146 = qcdr(v0146);
    v0146 = qcar(v0146);
    v0103 = Lrplaca(nil, v0103, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0146 = stack[0];
    v0146 = qcdr(v0146);
    v0146 = qcdr(v0146);
    v0146 = Lrplacd(nil, v0103, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
/* error exit handlers */
v0144:
    popv(5);
    return nil;
}



/* Code for raddf */

static Lisp_Object CC_raddf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for raddf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0033;

v0033:
    v0065 = stack[-2];
    if (v0065 == nil) goto v0030;
    v0065 = stack[-1];
    if (v0065 == nil) goto v0019;
    v0065 = stack[-2];
    if (!consp(v0065)) goto v0018;
    v0065 = stack[-2];
    v0065 = qcar(v0065);
    v0065 = (consp(v0065) ? nil : lisp_true);
    goto v0003;

v0003:
    if (v0065 == nil) goto v0099;
    stack[0] = stack[-3];
    v0168 = stack[-2];
    v0065 = stack[-1];
    fn = elt(env, 2); /* addd */
    v0065 = (*qfn2(fn))(qenv(fn), v0168, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    {
        Lisp_Object v0170 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0170, v0065);
    }

v0099:
    v0065 = stack[-1];
    if (!consp(v0065)) goto v0084;
    v0065 = stack[-1];
    v0065 = qcar(v0065);
    v0065 = (consp(v0065) ? nil : lisp_true);
    goto v0026;

v0026:
    if (v0065 == nil) goto v0171;
    stack[0] = stack[-3];
    v0168 = stack[-1];
    v0065 = stack[-2];
    fn = elt(env, 2); /* addd */
    v0065 = (*qfn2(fn))(qenv(fn), v0168, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    {
        Lisp_Object v0126 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0126, v0065);
    }

v0171:
    v0065 = stack[-2];
    v0065 = qcar(v0065);
    v0168 = qcar(v0065);
    v0065 = stack[-1];
    v0065 = qcar(v0065);
    v0065 = qcar(v0065);
    if (equal(v0168, v0065)) goto v0147;
    v0065 = stack[-2];
    v0065 = qcar(v0065);
    v0168 = qcar(v0065);
    v0065 = stack[-1];
    v0065 = qcar(v0065);
    v0065 = qcar(v0065);
    fn = elt(env, 4); /* ordpp */
    v0065 = (*qfn2(fn))(qenv(fn), v0168, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    if (v0065 == nil) goto v0144;
    v0065 = stack[-2];
    v0168 = qcar(v0065);
    v0065 = stack[-3];
    v0065 = cons(v0168, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[-3] = v0065;
    v0065 = stack[-2];
    v0065 = qcdr(v0065);
    stack[-2] = v0065;
    goto v0033;

v0144:
    v0065 = stack[-1];
    v0168 = qcar(v0065);
    v0065 = stack[-3];
    v0065 = cons(v0168, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[-3] = v0065;
    v0065 = stack[-1];
    v0065 = qcdr(v0065);
    stack[-1] = v0065;
    goto v0033;

v0147:
    v0065 = stack[-2];
    v0065 = qcar(v0065);
    stack[0] = qcar(v0065);
    v0065 = stack[-2];
    v0065 = qcar(v0065);
    v0168 = qcdr(v0065);
    v0065 = stack[-1];
    v0065 = qcar(v0065);
    v0065 = qcdr(v0065);
    v0168 = CC_raddf(env, v0168, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0065 = stack[-3];
    v0065 = acons(stack[0], v0168, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    stack[-3] = v0065;
    v0065 = stack[-2];
    v0065 = qcdr(v0065);
    stack[-2] = v0065;
    v0065 = stack[-1];
    v0065 = qcdr(v0065);
    stack[-1] = v0065;
    goto v0033;

v0084:
    v0065 = qvalue(elt(env, 1)); /* t */
    goto v0026;

v0018:
    v0065 = qvalue(elt(env, 1)); /* t */
    goto v0003;

v0019:
    v0168 = stack[-3];
    v0065 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0168, v0065);
    }

v0030:
    v0168 = stack[-3];
    v0065 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0168, v0065);
    }
/* error exit handlers */
v0169:
    popv(5);
    return nil;
}



/* Code for exchk2 */

static Lisp_Object CC_exchk2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0142, v0072, v0073;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exchk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0033:
    v0142 = stack[-1];
    if (v0142 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0142 = stack[-1];
    v0142 = qcdr(v0142);
    stack[-2] = v0142;
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcdr(v0142);
    fn = elt(env, 6); /* prepsqx */
    v0142 = (*qfn1(fn))(qenv(fn), v0142);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0073 = v0142;
    v0072 = (Lisp_Object)17; /* 1 */
    if (v0073 == v0072) goto v0044;
    v0072 = qvalue(elt(env, 1)); /* !*nosqrts */
    if (v0072 == nil) goto v0014;
    v0073 = elt(env, 2); /* expt */
    v0072 = stack[-1];
    v0072 = qcar(v0072);
    v0072 = qcar(v0072);
    v0142 = list3(v0073, v0072, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0072 = v0142;
    goto v0004;

v0004:
    v0142 = stack[0];
    v0142 = cons(v0072, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    stack[0] = v0142;
    v0142 = stack[-2];
    stack[-1] = v0142;
    goto v0033;

v0014:
    v0073 = v0142;
    v0072 = elt(env, 3); /* (quotient 1 2) */
    if (equal(v0073, v0072)) goto v0101;
    v0073 = v0142;
    v0072 = elt(env, 5); /* 0.5 */
    if (equal(v0073, v0072)) goto v0085;
    v0073 = elt(env, 2); /* expt */
    v0072 = stack[-1];
    v0072 = qcar(v0072);
    v0072 = qcar(v0072);
    v0142 = list3(v0073, v0072, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0072 = v0142;
    goto v0004;

v0085:
    v0072 = elt(env, 4); /* sqrt */
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    v0142 = list2(v0072, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0072 = v0142;
    goto v0004;

v0101:
    v0072 = elt(env, 4); /* sqrt */
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    v0142 = list2(v0072, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0072 = v0142;
    goto v0004;

v0044:
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    v0142 = qcar(v0142);
    v0072 = v0142;
    goto v0004;
/* error exit handlers */
v0116:
    popv(4);
    return nil;
}



/* Code for mri_type */

static Lisp_Object CC_mri_type(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_type");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0052 = v0000;
/* end of prologue */
    v0055 = v0052;
    v0055 = qcdr(v0055);
    v0055 = qcdr(v0055);
    v0055 = qcdr(v0055);
    if (v0055 == nil) goto v0045;
    v0055 = v0052;
    v0055 = qcdr(v0055);
    v0055 = qcdr(v0055);
    v0055 = qcdr(v0055);
    v0055 = qcar(v0055);
    return onevalue(v0055);

v0045:
    v0055 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0055);
}



/* Code for find */

static Lisp_Object CC_find(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0112, v0025, v0124;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0112 = v0001;
    v0025 = v0000;
/* end of prologue */

v0027:
    v0124 = v0112;
    v0043 = nil;
    if (v0124 == v0043) goto v0034;
    v0043 = v0112;
    v0043 = qcar(v0043);
    v0025 = Lmember(nil, v0043, v0025);
    v0043 = v0112;
    v0043 = qcdr(v0043);
    v0112 = v0043;
    goto v0027;

v0034:
    v0043 = v0025;
    if (v0043 == nil) goto v0005;
    v0043 = v0025;
    v0043 = qcdr(v0043);
    return onevalue(v0043);

v0005:
    v0043 = elt(env, 1); /* (stop) */
    return onevalue(v0043);
}



/* Code for sortcolelem */

static Lisp_Object MS_CDECL CC_sortcolelem(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0133;
    Lisp_Object v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sortcolelem");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0015 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sortcolelem");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0015,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0015;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = nil;
    v0047 = stack[-2];
    v0047 = qcdr(v0047);
    stack[-4] = v0047;
    goto v0029;

v0029:
    v0047 = stack[0];
    if (v0047 == nil) goto v0051;
    v0047 = nil;
    { popv(6); return onevalue(v0047); }

v0051:
    v0047 = stack[-4];
    if (v0047 == nil) goto v0012;
    v0133 = stack[-3];
    v0047 = stack[-4];
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    v0047 = (Lisp_Object)lessp2(v0133, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    v0047 = v0047 ? lisp_true : nil;
    env = stack[-5];
    if (v0047 == nil) goto v0038;
    stack[0] = stack[-2];
    v0133 = stack[-3];
    v0047 = stack[-1];
    v0047 = cons(v0133, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    v0133 = ncons(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    v0047 = stack[-4];
    v0047 = Lrplacd(nil, v0133, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    v0047 = Lrplacd(nil, stack[0], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    v0047 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0047;
    goto v0029;

v0038:
    v0133 = stack[-3];
    v0047 = stack[-4];
    v0047 = qcar(v0047);
    v0047 = qcar(v0047);
    v0047 = (Lisp_Object)greaterp2(v0133, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    v0047 = v0047 ? lisp_true : nil;
    env = stack[-5];
    if (v0047 == nil) goto v0029;
    v0047 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0047;
    v0047 = stack[-2];
    v0047 = qcdr(v0047);
    stack[-2] = v0047;
    v0047 = stack[-2];
    v0047 = qcdr(v0047);
    stack[-4] = v0047;
    goto v0029;

v0012:
    stack[0] = stack[-2];
    v0133 = stack[-3];
    v0047 = stack[-1];
    v0047 = cons(v0133, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    v0047 = ncons(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    v0047 = Lrplacd(nil, stack[0], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    v0047 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0047;
    goto v0029;
/* error exit handlers */
v0148:
    popv(6);
    return nil;
}



/* Code for pnthxzz */

static Lisp_Object CC_pnthxzz(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0003, v0018, v0121;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pnthxzz");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0018 = v0001;
    v0121 = v0000;
/* end of prologue */

v0010:
    v0100 = v0018;
    if (v0100 == nil) goto v0029;
    v0100 = v0018;
    v0100 = qcar(v0100);
    v0003 = qcar(v0100);
    v0100 = v0121;
    v0100 = (equal(v0003, v0100) ? lisp_true : nil);
    goto v0050;

v0050:
    if (!(v0100 == nil)) return onevalue(v0018);
    v0100 = v0018;
    v0100 = qcdr(v0100);
    v0018 = v0100;
    goto v0010;

v0029:
    v0100 = qvalue(elt(env, 1)); /* t */
    goto v0050;
}



/* Code for vevtdeg */

static Lisp_Object CC_vevtdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0042, v0043;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevtdeg");
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
    v0042 = nil;
    goto v0033;

v0033:
    v0009 = stack[0];
    if (v0009 == nil) goto v0034;
    v0009 = stack[0];
    v0009 = qcar(v0009);
    v0009 = cons(v0009, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-1];
    v0042 = v0009;
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    stack[0] = v0009;
    goto v0033;

v0034:
    v0009 = (Lisp_Object)1; /* 0 */
    goto v0011;

v0011:
    v0043 = v0042;
    if (v0043 == nil) { popv(2); return onevalue(v0009); }
    v0043 = v0042;
    v0043 = qcar(v0043);
    v0009 = (Lisp_Object)(int32_t)((int32_t)v0043 + (int32_t)v0009 - TAG_FIXNUM);
    v0042 = qcdr(v0042);
    goto v0011;
/* error exit handlers */
v0025:
    popv(2);
    return nil;
}



/* Code for !*collectphysops */

static Lisp_Object CC_Hcollectphysops(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *collectphysops");
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
/* copy arguments values to proper place */
    v0050 = v0000;
/* end of prologue */
    v0029 = v0050;
    v0050 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* !*collectphysops_reversed */
    v0050 = (*qfn2(fn))(qenv(fn), v0029, v0050);
    errexit();
        return Lnreverse(nil, v0050);
}



/* Code for sfpx */

static Lisp_Object CC_sfpx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0004, v0098, v0113, v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfpx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0052 = v0000;
/* end of prologue */
    v0005 = v0052;
    v0113 = qvalue(elt(env, 1)); /* nil */
    v0098 = qvalue(elt(env, 1)); /* nil */
    v0004 = (Lisp_Object)1; /* 0 */
    v0052 = qvalue(elt(env, 2)); /* t */
    {
        fn = elt(env, 3); /* sfpx1 */
        return (*qfnn(fn))(qenv(fn), 5, v0005, v0113, v0098, v0004, v0052);
    }
}



/* Code for gcdf!* */

static Lisp_Object CC_gcdfH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0032, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0032 = v0001;
    v0083 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v0031 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0031; /* !*gcd */
    v0031 = v0083;
    fn = elt(env, 3); /* gcdf */
    v0031 = (*qfn2(fn))(qenv(fn), v0031, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v0031); }
/* error exit handlers */
v0052:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for tsym4 */

static Lisp_Object MS_CDECL CC_tsym4(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0043;
    Lisp_Object fn;
    Lisp_Object v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "tsym4");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0015 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tsym4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0015,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
    stack[-1] = v0001;
    v0042 = v0000;
/* end of prologue */

v0034:
    v0043 = v0042;
    if (v0043 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0043 = v0042;
    v0043 = qcdr(v0043);
    stack[-2] = v0043;
    v0043 = stack[-1];
    v0043 = qcdr(v0043);
    v0042 = qcar(v0042);
    fn = elt(env, 1); /* pv_applp */
    v0043 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0042 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v0042 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    fn = elt(env, 3); /* pv_renorm */
    v0043 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0042 = stack[0];
    fn = elt(env, 4); /* insert_pv */
    v0042 = (*qfn2(fn))(qenv(fn), v0043, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[0] = v0042;
    v0042 = stack[-2];
    goto v0034;
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for general!-modular!-reciprocal */

static Lisp_Object CC_generalKmodularKreciprocal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0093, v0153, v0161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-reciprocal");
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
    v0095 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v0095 == nil) goto v0007;
    v0093 = stack[0];
    v0095 = (Lisp_Object)1; /* 0 */
    v0095 = (Lisp_Object)lessp2(v0093, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    v0095 = v0095 ? lisp_true : nil;
    env = stack[-2];
    if (v0095 == nil) goto v0007;
    stack[-1] = qvalue(elt(env, 2)); /* current!-modulus */
    v0093 = stack[0];
    v0095 = qvalue(elt(env, 2)); /* current!-modulus */
    v0153 = plus2(v0093, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-2];
    v0093 = (Lisp_Object)1; /* 0 */
    v0095 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v0013 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v0013, v0153, v0093, v0095);
    }

v0007:
    v0161 = qvalue(elt(env, 2)); /* current!-modulus */
    v0153 = stack[0];
    v0093 = (Lisp_Object)1; /* 0 */
    v0095 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v0161, v0153, v0093, v0095);
    }
/* error exit handlers */
v0014:
    popv(3);
    return nil;
}



/* Code for lispapply */

static Lisp_Object CC_lispapply(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0078, v0079;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lispapply");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0078 = v0001;
    v0079 = v0000;
/* end of prologue */
    v0121 = v0079;
    if (!consp(v0121)) goto v0024;
    stack[-1] = elt(env, 1); /* rlisp */
    stack[0] = (Lisp_Object)33; /* 2 */
    v0121 = elt(env, 2); /* "Apply called with non-id arg" */
    v0078 = v0079;
    v0121 = list2(v0121, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    {
        Lisp_Object v0008 = stack[-1];
        Lisp_Object v0009 = stack[0];
        popv(3);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0008, v0009, v0121);
    }

v0024:
    v0121 = v0079;
    {
        popv(3);
        fn = elt(env, 4); /* apply */
        return (*qfn2(fn))(qenv(fn), v0121, v0078);
    }
/* error exit handlers */
v0007:
    popv(3);
    return nil;
}



/* Code for mri_0mk2 */

static Lisp_Object MS_CDECL CC_mri_0mk2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0052, v0004, v0098;
    Lisp_Object v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mri_0mk2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0015 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0015;
    v0055 = v0001;
    v0052 = v0000;
/* end of prologue */
    v0098 = qvalue(elt(env, 1)); /* nil */
    return list4(v0052, v0055, v0098, v0004);
}



/* Code for ibalp_commonlenisone */

static Lisp_Object CC_ibalp_commonlenisone(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_commonlenisone");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0053 = stack[-1];
    if (v0053 == nil) goto v0011;
    v0053 = qvalue(elt(env, 1)); /* nil */
    goto v0034;

v0034:
    if (!(v0053 == nil)) { popv(3); return onevalue(v0053); }
    v0053 = stack[0];
    if (v0053 == nil) goto v0055;
    v0053 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0053); }

v0055:
    v0053 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* ibalp_lenisone */
        return (*qfn1(fn))(qenv(fn), v0053);
    }

v0011:
    v0053 = stack[0];
    fn = elt(env, 2); /* ibalp_lenisone */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    goto v0034;
/* error exit handlers */
v0024:
    popv(3);
    return nil;
}



/* Code for ratpoly_idl */

static Lisp_Object CC_ratpoly_idl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratpoly_idl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0010 = v0000;
/* end of prologue */
    v0010 = qcar(v0010);
    {
        fn = elt(env, 1); /* kernels */
        return (*qfn1(fn))(qenv(fn), v0010);
    }
}



/* Code for multi_elem */

static Lisp_Object CC_multi_elem(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multi_elem");
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
    v0054 = stack[0];
    v0024 = Llength(nil, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    v0054 = (Lisp_Object)17; /* 1 */
    if (v0024 == v0054) goto v0033;
    v0054 = stack[0];
    v0054 = qcar(v0054);
    fn = elt(env, 2); /* expression */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    v0054 = CC_multi_elem(env, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    goto v0010;

v0010:
    v0054 = nil;
    { popv(2); return onevalue(v0054); }

v0033:
    v0054 = stack[0];
    v0054 = qcar(v0054);
    fn = elt(env, 2); /* expression */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    goto v0010;
/* error exit handlers */
v0002:
    popv(2);
    return nil;
}



/* Code for rationalizei */

static Lisp_Object CC_rationalizei(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rationalizei");
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
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    stack[-2] = v0088;
    v0166 = v0088;
    v0088 = v0166;
    if (!consp(v0088)) goto v0032;
    v0088 = v0166;
    v0088 = qcar(v0088);
    v0088 = (consp(v0088) ? nil : lisp_true);
    goto v0031;

v0031:
    if (!(v0088 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0166 = elt(env, 2); /* i */
    v0088 = stack[-2];
    v0088 = Lsmemq(nil, v0166, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    if (v0088 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0166 = elt(env, 2); /* i */
    v0088 = qvalue(elt(env, 3)); /* kord!* */
    v0088 = cons(v0166, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    stack[0] = qvalue(elt(env, 3)); /* kord!* */
    qvalue(elt(env, 3)) = v0088; /* kord!* */
    v0088 = stack[-1];
    fn = elt(env, 6); /* reordsq */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-3];
    stack[-2] = v0088;
    qvalue(elt(env, 3)) = stack[0]; /* kord!* */
    v0088 = stack[-2];
    v0088 = qcdr(v0088);
    stack[0] = v0088;
    v0088 = qcar(v0088);
    v0166 = qcar(v0088);
    v0088 = elt(env, 4); /* (i . 1) */
    if (equal(v0166, v0088)) goto v0016;
    v0088 = qvalue(elt(env, 5)); /* nil */
    goto v0122;

v0122:
    if (v0088 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0166 = elt(env, 2); /* i */
    v0088 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 7); /* to */
    v0166 = (*qfn2(fn))(qenv(fn), v0166, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    v0088 = (Lisp_Object)17; /* 1 */
    v0088 = cons(v0166, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    stack[-1] = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    v0088 = stack[-2];
    v0088 = qcar(v0088);
    fn = elt(env, 8); /* reorder */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    fn = elt(env, 9); /* multf */
    v0088 = (*qfn2(fn))(qenv(fn), stack[-1], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    fn = elt(env, 10); /* negf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0088 = qcdr(v0088);
    fn = elt(env, 8); /* reorder */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    {
        Lisp_Object v0173 = stack[-1];
        popv(4);
        return cons(v0173, v0088);
    }

v0016:
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    v0088 = (v0088 == nil ? lisp_true : nil);
    goto v0122;

v0032:
    v0088 = qvalue(elt(env, 1)); /* t */
    goto v0031;
/* error exit handlers */
v0073:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[0]; /* kord!* */
    popv(4);
    return nil;
v0072:
    popv(4);
    return nil;
}



/* Code for gsetsugar */

static Lisp_Object CC_gsetsugar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0099;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gsetsugar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0099 = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0002 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0002 == nil) goto v0011;
    stack[-2] = stack[-1];
    stack[0] = elt(env, 3); /* sugar */
    v0002 = v0099;
    if (!(v0002 == nil)) goto v0004;
    v0002 = stack[-1];
    fn = elt(env, 4); /* vdptdeg */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    goto v0004;

v0004:
    fn = elt(env, 5); /* vdpputprop */
    v0002 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0002);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    goto v0034;

v0034:
    if (v0002 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else { popv(4); return onevalue(v0002); }

v0011:
    v0002 = qvalue(elt(env, 2)); /* nil */
    goto v0034;
/* error exit handlers */
v0121:
    popv(4);
    return nil;
}



/* Code for getphystype */

static Lisp_Object CC_getphystype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0138, v0135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystype");
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
    v0138 = stack[0];
    fn = elt(env, 8); /* physopp */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    if (v0138 == nil) goto v0011;
    v0138 = stack[0];
    fn = elt(env, 9); /* scalopp */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    if (v0138 == nil) goto v0051;
    v0138 = elt(env, 1); /* scalar */
    { popv(3); return onevalue(v0138); }

v0051:
    v0138 = stack[0];
    fn = elt(env, 10); /* vecopp */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    if (v0138 == nil) goto v0052;
    v0138 = elt(env, 2); /* vector */
    { popv(3); return onevalue(v0138); }

v0052:
    v0138 = stack[0];
    fn = elt(env, 11); /* tensopp */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    if (v0138 == nil) goto v0019;
    v0138 = elt(env, 3); /* tensor */
    { popv(3); return onevalue(v0138); }

v0019:
    v0138 = stack[0];
    fn = elt(env, 12); /* statep */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    if (v0138 == nil) goto v0100;
    v0138 = elt(env, 4); /* state */
    { popv(3); return onevalue(v0138); }

v0100:
    v0138 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0138); }

v0011:
    v0138 = stack[0];
    if (!consp(v0138)) goto v0121;
    v0138 = stack[0];
    v0138 = qcar(v0138);
    if (!symbolp(v0138)) v0135 = nil;
    else { v0135 = qfastgets(v0138);
           if (v0135 != nil) { v0135 = elt(v0135, 18); /* phystype */
#ifdef RECORD_GET
             if (v0135 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0135 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0135 == SPID_NOPROP) v0135 = nil; }}
#endif
    v0138 = v0135;
    if (!(v0135 == nil)) { popv(3); return onevalue(v0138); }
    v0138 = stack[0];
    v0135 = qcar(v0138);
    v0138 = elt(env, 6); /* phystypefn */
    v0135 = get(v0135, v0138);
    env = stack[-2];
    v0138 = v0135;
    if (v0135 == nil) goto v0025;
    v0135 = v0138;
    v0138 = stack[0];
    v0138 = qcdr(v0138);
        popv(3);
        return Lapply1(nil, v0135, v0138);

v0025:
    v0138 = stack[0];
    fn = elt(env, 13); /* collectphystype */
    v0135 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0138 = v0135;
    if (v0135 == nil) goto v0021;
    v0135 = v0138;
    v0135 = qcdr(v0135);
    if (v0135 == nil) goto v0125;
    v0135 = elt(env, 4); /* state */
    v0138 = Lmember(nil, v0135, v0138);
    if (v0138 == nil) goto v0035;
    v0138 = elt(env, 4); /* state */
    { popv(3); return onevalue(v0138); }

v0035:
    stack[-1] = elt(env, 0); /* getphystype */
    v0135 = elt(env, 7); /* "PHYSOP type conflict in" */
    v0138 = stack[0];
    v0138 = list2(v0135, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    {
        Lisp_Object v0166 = stack[-1];
        popv(3);
        fn = elt(env, 14); /* rederr2 */
        return (*qfn2(fn))(qenv(fn), v0166, v0138);
    }

v0125:
    v0138 = qcar(v0138);
    { popv(3); return onevalue(v0138); }

v0021:
    v0138 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0138); }

v0121:
    v0138 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0138); }
/* error exit handlers */
v0088:
    popv(3);
    return nil;
}



/* Code for setcloc!* */

static Lisp_Object MS_CDECL CC_setclocH(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0113, v0005;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setcloc*");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setcloc*");
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
/* end of prologue */
    v0098 = qvalue(elt(env, 1)); /* ifl!* */
    if (v0098 == nil) goto v0058;
    v0098 = qvalue(elt(env, 1)); /* ifl!* */
    v0005 = qcar(v0098);
    v0113 = (Lisp_Object)17; /* 1 */
    v0098 = qvalue(elt(env, 3)); /* curline!* */
    v0098 = list2star(v0005, v0113, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[0];
    goto v0015;

v0015:
    qvalue(elt(env, 4)) = v0098; /* cloc!* */
    { popv(1); return onevalue(v0098); }

v0058:
    v0098 = qvalue(elt(env, 2)); /* nil */
    goto v0015;
/* error exit handlers */
v0019:
    popv(1);
    return nil;
}



/* Code for dp_term */

static Lisp_Object CC_dp_term(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0029;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0001;
    v0029 = v0000;
/* end of prologue */
    return cons(v0050, v0029);
}



/* Code for dquot */

static Lisp_Object CC_dquot(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0122, v0016;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dquot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0028;

v0028:
    v0123 = stack[-1];
    v0122 = qcar(v0123);
    v0123 = stack[0];
    v0123 = qcar(v0123);
    v0123 = difference2(v0122, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-3];
    v0016 = v0123;
    v0122 = v0016;
    v0123 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0122)) < ((int32_t)(v0123))) goto v0098;
    v0122 = v0016;
    v0123 = stack[-2];
    v0123 = cons(v0122, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-3];
    stack[-2] = v0123;
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    stack[0] = v0123;
    v0123 = stack[-1];
    v0123 = qcdr(v0123);
    stack[-1] = v0123;
    v0123 = stack[0];
    if (!(v0123 == nil)) goto v0028;
    v0123 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0123);

v0098:
    v0123 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0123); }
/* error exit handlers */
v0153:
    popv(4);
    return nil;
}



/* Code for gperm */

static Lisp_Object CC_gperm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0097;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm");
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
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0030;

v0030:
    v0097 = stack[0];
    v0096 = (Lisp_Object)1; /* 0 */
    v0096 = (Lisp_Object)greaterp2(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    v0096 = v0096 ? lisp_true : nil;
    env = stack[-4];
    if (v0096 == nil) goto v0033;
    v0097 = stack[0];
    v0096 = stack[-1];
    v0096 = cons(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    stack[-1] = v0096;
    v0096 = stack[0];
    v0096 = sub1(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    stack[0] = v0096;
    goto v0030;

v0033:
    v0096 = stack[-1];
    fn = elt(env, 2); /* gperm0 */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    stack[-3] = v0096;
    v0096 = stack[-3];
    if (v0096 == nil) goto v0007;
    v0096 = stack[-3];
    v0096 = qcar(v0096);
    fn = elt(env, 3); /* pkp */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    stack[-1] = v0096;
    stack[-2] = v0096;
    goto v0121;

v0121:
    v0096 = stack[-3];
    v0096 = qcdr(v0096);
    stack[-3] = v0096;
    v0096 = stack[-3];
    if (v0096 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0096 = stack[-3];
    v0096 = qcar(v0096);
    fn = elt(env, 3); /* pkp */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    v0096 = Lrplacd(nil, stack[0], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    v0096 = stack[-1];
    v0096 = qcdr(v0096);
    stack[-1] = v0096;
    goto v0121;

v0007:
    v0096 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0096); }
/* error exit handlers */
v0038:
    popv(5);
    return nil;
}



/* Code for gizerop!: */

static Lisp_Object CC_gizeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0024, v0044;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gizerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0044 = v0000;
/* end of prologue */
    v0054 = v0044;
    v0054 = qcdr(v0054);
    v0024 = qcar(v0054);
    v0054 = (Lisp_Object)1; /* 0 */
    if (v0024 == v0054) goto v0031;
    v0054 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0054);

v0031:
    v0054 = v0044;
    v0054 = qcdr(v0054);
    v0024 = qcdr(v0054);
    v0054 = (Lisp_Object)1; /* 0 */
    v0054 = (v0024 == v0054 ? lisp_true : nil);
    return onevalue(v0054);
}



/* Code for rread1 */

static Lisp_Object MS_CDECL CC_rread1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144, v0092, v0179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rread1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rread1");
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
    fn = elt(env, 15); /* ptoken */
    v0144 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    stack[-1] = v0144;
    v0092 = qvalue(elt(env, 1)); /* ttype!* */
    v0144 = (Lisp_Object)49; /* 3 */
    if (v0092 == v0144) goto v0022;
    v0144 = stack[-1];
    if (symbolp(v0144)) goto v0052;
    v0092 = stack[-1];
    v0144 = elt(env, 4); /* !:dn!: */
    if (!consp(v0092)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0092 = qcar(v0092);
    if (!(v0092 == v0144)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0179 = stack[-1];
    v0092 = qvalue(elt(env, 5)); /* nil */
    v0144 = elt(env, 6); /* symbolic */
    {
        popv(3);
        fn = elt(env, 16); /* dnform */
        return (*qfnn(fn))(qenv(fn), 3, v0179, v0092, v0144);
    }

v0052:
    v0144 = qvalue(elt(env, 2)); /* !*quotenewnam */
    if (v0144 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0092 = stack[-1];
    v0144 = elt(env, 3); /* quotenewnam */
    v0144 = get(v0092, v0144);
    stack[0] = v0144;
    if (v0144 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0022:
    v0092 = stack[-1];
    v0144 = elt(env, 7); /* !( */
    if (v0092 == v0144) goto v0020;
    v0092 = stack[-1];
    v0144 = elt(env, 8); /* !+ */
    if (v0092 == v0144) goto v0040;
    v0092 = stack[-1];
    v0144 = elt(env, 10); /* !- */
    v0144 = (v0092 == v0144 ? lisp_true : nil);
    goto v0039;

v0039:
    if (v0144 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    fn = elt(env, 15); /* ptoken */
    v0144 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    stack[0] = v0144;
    v0092 = stack[0];
    v0144 = elt(env, 4); /* !:dn!: */
    if (!consp(v0092)) goto v0148;
    v0092 = qcar(v0092);
    if (!(v0092 == v0144)) goto v0148;
    v0179 = stack[0];
    v0092 = qvalue(elt(env, 5)); /* nil */
    v0144 = elt(env, 6); /* symbolic */
    fn = elt(env, 16); /* dnform */
    v0144 = (*qfnn(fn))(qenv(fn), 3, v0179, v0092, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    stack[0] = v0144;
    goto v0148;

v0148:
    v0144 = stack[0];
    if (is_number(v0144)) goto v0105;
    v0144 = elt(env, 11); /* " " */
    qvalue(elt(env, 12)) = v0144; /* nxtsym!* */
    v0092 = elt(env, 13); /* "Syntax error: improper number" */
    v0144 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 17); /* symerr */
    v0144 = (*qfn2(fn))(qenv(fn), v0092, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0105:
    v0092 = stack[-1];
    v0144 = elt(env, 10); /* !- */
    if (!(v0092 == v0144)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0092 = elt(env, 14); /* minus */
    v0144 = stack[0];
    v0144 = Lapply1(nil, v0092, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    stack[0] = v0144;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0040:
    v0144 = qvalue(elt(env, 9)); /* t */
    goto v0039;

v0020:
    {
        popv(3);
        fn = elt(env, 18); /* rrdls */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0115:
    popv(3);
    return nil;
}



/* Code for lto_insert */

static Lisp_Object CC_lto_insert(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0080, v0054, v0024;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_insert");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0080 = v0001;
    v0054 = v0000;
/* end of prologue */
    v0024 = v0054;
    v0053 = v0080;
    v0053 = Lmember(nil, v0024, v0053);
    if (!(v0053 == nil)) return onevalue(v0080);
    v0053 = v0054;
    return cons(v0053, v0080);
}



/* Code for sfto_gcdf!* */

static Lisp_Object CC_sfto_gcdfH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0051, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_gcdf*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0051 = v0001;
    v0031 = v0000;
/* end of prologue */
    v0030 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*gcd */
    qvalue(elt(env, 2)) = v0030; /* !*gcd */
    v0030 = v0031;
    fn = elt(env, 3); /* sfto_gcdf */
    v0030 = (*qfn2(fn))(qenv(fn), v0030, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v0030); }
/* error exit handlers */
v0083:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for mcharg2 */

static Lisp_Object MS_CDECL CC_mcharg2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0176, v0163;
    Lisp_Object fn;
    Lisp_Object v0058, v0015, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mcharg2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0015 = va_arg(aa, Lisp_Object);
    v0058 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mcharg2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0058,v0015,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0015,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-6] = v0058;
    stack[-7] = v0015;
    stack[-8] = v0001;
    stack[-9] = v0000;
/* end of prologue */
    v0107 = stack[-9];
    if (v0107 == nil) { Lisp_Object res = stack[-7]; popv(12); return onevalue(res); }
    v0107 = stack[-9];
    v0176 = qcar(v0107);
    v0107 = stack[-8];
    v0107 = qcar(v0107);
    fn = elt(env, 2); /* mchk */
    v0107 = (*qfn2(fn))(qenv(fn), v0176, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    v0176 = v0107;
    v0107 = stack[-9];
    v0107 = qcdr(v0107);
    stack[-9] = v0107;
    v0107 = stack[-8];
    v0107 = qcdr(v0107);
    stack[-8] = v0107;
    v0107 = v0176;
    stack[-10] = v0107;
    goto v0100;

v0100:
    v0107 = stack[-10];
    if (v0107 == nil) goto v0079;
    v0107 = stack[-10];
    v0107 = qcar(v0107);
    stack[-2] = v0107;
    stack[-1] = stack[-9];
    v0163 = stack[-2];
    v0176 = stack[-8];
    v0107 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0163, v0176, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    v0176 = stack[-7];
    v0107 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v0176 = (*qfn2(fn))(qenv(fn), v0176, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    v0107 = stack[-6];
    v0107 = CC_mcharg2(env, 4, stack[-1], stack[0], v0176, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    stack[-5] = v0107;
    v0107 = stack[-5];
    fn = elt(env, 5); /* lastpair */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    stack[-4] = v0107;
    v0107 = stack[-10];
    v0107 = qcdr(v0107);
    stack[-10] = v0107;
    v0107 = stack[-4];
    if (!consp(v0107)) goto v0100;
    else goto v0003;

v0003:
    v0107 = stack[-10];
    if (v0107 == nil) { Lisp_Object res = stack[-5]; popv(12); return onevalue(res); }
    stack[-3] = stack[-4];
    v0107 = stack[-10];
    v0107 = qcar(v0107);
    stack[-2] = v0107;
    stack[-1] = stack[-9];
    v0163 = stack[-2];
    v0176 = stack[-8];
    v0107 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0163, v0176, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    v0176 = stack[-7];
    v0107 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v0176 = (*qfn2(fn))(qenv(fn), v0176, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    v0107 = stack[-6];
    v0107 = CC_mcharg2(env, 4, stack[-1], stack[0], v0176, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    v0107 = Lrplacd(nil, stack[-3], v0107);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    v0107 = stack[-4];
    fn = elt(env, 5); /* lastpair */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-11];
    stack[-4] = v0107;
    v0107 = stack[-10];
    v0107 = qcdr(v0107);
    stack[-10] = v0107;
    goto v0003;

v0079:
    v0107 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v0107); }
/* error exit handlers */
v0103:
    popv(12);
    return nil;
}



/* Code for cgp_evlmon */

static Lisp_Object CC_cgp_evlmon(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgp_evlmon");
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
    v0010 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_evlmon */
        return (*qfn1(fn))(qenv(fn), v0010);
    }
/* error exit handlers */
v0033:
    popv(1);
    return nil;
}



/* Code for quotfd */

static Lisp_Object CC_quotfd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0160, v0014, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0001;
    v0013 = v0000;
/* end of prologue */
    v0160 = v0013;
    v0041 = v0014;
    if (equal(v0160, v0041)) goto v0010;
    v0041 = qvalue(elt(env, 1)); /* dmode!* */
    if (!symbolp(v0041)) v0041 = nil;
    else { v0041 = qfastgets(v0041);
           if (v0041 != nil) { v0041 = elt(v0041, 3); /* field */
#ifdef RECORD_GET
             if (v0041 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0041 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0041 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0041 == SPID_NOPROP) v0041 = nil; else v0041 = lisp_true; }}
#endif
    if (v0041 == nil) goto v0032;
    v0041 = v0013;
    v0160 = v0014;
    {
        fn = elt(env, 3); /* divd */
        return (*qfn2(fn))(qenv(fn), v0041, v0160);
    }

v0032:
    v0041 = v0013;
    if (!consp(v0041)) goto v0002;
    v0041 = v0013;
    v0041 = qcar(v0041);
    v0041 = (consp(v0041) ? nil : lisp_true);
    goto v0044;

v0044:
    if (v0041 == nil) goto v0122;
    v0041 = v0013;
    v0160 = v0014;
    {
        fn = elt(env, 4); /* quotdd */
        return (*qfn2(fn))(qenv(fn), v0041, v0160);
    }

v0122:
    v0041 = v0013;
    v0160 = v0014;
    {
        fn = elt(env, 5); /* quotk */
        return (*qfn2(fn))(qenv(fn), v0041, v0160);
    }

v0002:
    v0041 = qvalue(elt(env, 2)); /* t */
    goto v0044;

v0010:
    v0041 = (Lisp_Object)17; /* 1 */
    return onevalue(v0041);
}



/* Code for retattributes */

static Lisp_Object CC_retattributes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0020;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for retattributes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0152:
    v0077 = stack[0];
    if (v0077 == nil) goto v0034;
    v0020 = stack[-1];
    v0077 = stack[0];
    v0077 = qcar(v0077);
    fn = elt(env, 2); /* find */
    v0077 = (*qfn2(fn))(qenv(fn), v0020, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    v0020 = v0077;
    if (v0020 == nil) goto v0093;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    stack[-2] = list2(v0020, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    v0020 = stack[-1];
    v0077 = stack[0];
    v0077 = qcdr(v0077);
    v0077 = CC_retattributes(env, v0020, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    {
        Lisp_Object v0037 = stack[-2];
        popv(4);
        return cons(v0037, v0077);
    }

v0093:
    v0020 = stack[-1];
    v0077 = stack[0];
    v0077 = qcdr(v0077);
    stack[-1] = v0020;
    stack[0] = v0077;
    goto v0152;

v0034:
    v0077 = nil;
    { popv(4); return onevalue(v0077); }
/* error exit handlers */
v0023:
    popv(4);
    return nil;
}



/* Code for isarb_compl */

static Lisp_Object CC_isarb_compl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0044, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for isarb_compl");
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
    v0044 = v0000;
/* end of prologue */
    v0024 = v0044;
    v0024 = Lconsp(nil, v0024);
    env = stack[0];
    if (v0024 == nil) goto v0010;
    v0024 = v0044;
    v0002 = qcar(v0024);
    v0024 = elt(env, 1); /* arbcomplex */
    if (v0002 == v0024) goto v0029;
    v0024 = v0044;
    v0024 = qcdr(v0024);
    fn = elt(env, 4); /* multi_isarb_compl */
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    goto v0010;

v0010:
    v0024 = nil;
    { popv(1); return onevalue(v0024); }

v0029:
    v0024 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0024; /* found_compl */
    goto v0010;
/* error exit handlers */
v0099:
    popv(1);
    return nil;
}



/* Code for downwght */

static Lisp_Object CC_downwght(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for downwght");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0031 = stack[-1];
    fn = elt(env, 1); /* delhisto */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    v0032 = stack[-1];
    v0031 = stack[0];
    fn = elt(env, 2); /* downwght1 */
    v0031 = (*qfn2(fn))(qenv(fn), v0032, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    v0031 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* inshisto */
        return (*qfn1(fn))(qenv(fn), v0031);
    }
/* error exit handlers */
v0052:
    popv(3);
    return nil;
}



/* Code for vdpgetprop */

static Lisp_Object CC_vdpgetprop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0022, v0101, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpgetprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0101 = v0001;
    v0023 = v0000;
/* end of prologue */
    v0021 = v0023;
    if (v0021 == nil) goto v0010;
    v0022 = v0023;
    v0021 = elt(env, 2); /* vdp */
    if (!consp(v0022)) goto v0004;
    v0022 = qcar(v0022);
    if (!(v0022 == v0021)) goto v0004;
    v0021 = v0101;
    v0022 = v0023;
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    v0022 = qcar(v0022);
    v0021 = Lassoc(nil, v0021, v0022);
    v0022 = v0021;
    v0021 = v0022;
    if (v0021 == nil) goto v0084;
    v0021 = v0022;
    v0021 = qcdr(v0021);
    { popv(3); return onevalue(v0021); }

v0084:
    v0021 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0021); }

v0004:
    stack[-1] = elt(env, 3); /* dipoly */
    stack[0] = (Lisp_Object)113; /* 7 */
    v0021 = elt(env, 4); /* "vdpgetprop given a non-vdp as 1st parameter" 
*/
    v0022 = v0023;
    v0021 = list3(v0021, v0022, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-2];
    {
        Lisp_Object v0131 = stack[-1];
        Lisp_Object v0096 = stack[0];
        popv(3);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0131, v0096, v0021);
    }

v0010:
    v0021 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0021); }
/* error exit handlers */
v0132:
    popv(3);
    return nil;
}



/* Code for termordp */

static Lisp_Object CC_termordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for termordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0030 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* wedgefax */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    v0030 = stack[0];
    fn = elt(env, 1); /* wedgefax */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    {
        Lisp_Object v0083 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* monordp */
        return (*qfn2(fn))(qenv(fn), v0083, v0030);
    }
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for !:difference */

static Lisp_Object CC_Tdifference(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0041, v0160, v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0160 = v0001;
    v0014 = v0000;
/* end of prologue */
    v0161 = v0014;
    if (v0161 == nil) goto v0010;
    v0161 = v0160;
    if (v0161 == nil) return onevalue(v0014);
    v0041 = v0014;
    v0161 = v0160;
    if (equal(v0041, v0161)) goto v0051;
    v0161 = v0014;
    if (!consp(v0161)) goto v0054;
    v0161 = qvalue(elt(env, 1)); /* nil */
    goto v0080;

v0080:
    if (v0161 == nil) goto v0025;
    v0161 = v0014;
    v0041 = v0160;
    return difference2(v0161, v0041);

v0025:
    v0041 = v0014;
    v0161 = elt(env, 2); /* difference */
    {
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0041, v0160, v0161);
    }

v0054:
    v0161 = v0160;
    v0161 = (consp(v0161) ? nil : lisp_true);
    goto v0080;

v0051:
    v0161 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0161);

v0010:
    v0161 = v0160;
    {
        fn = elt(env, 4); /* !:minus */
        return (*qfn1(fn))(qenv(fn), v0161);
    }
}



/* Code for domain!*p */

static Lisp_Object CC_domainHp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0100;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for domain*p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0100 = v0000;
/* end of prologue */
    v0099 = v0100;
    if (v0099 == nil) goto v0045;
    v0099 = v0100;
    v0099 = (is_number(v0099) ? lisp_true : nil);
    if (!(v0099 == nil)) return onevalue(v0099);
    v0099 = v0100;
    if (!consp(v0099)) goto v0024;
    v0099 = v0100;
    v0099 = qcar(v0099);
    v0100 = qvalue(elt(env, 2)); /* domainlist!* */
    v0099 = Lmemq(nil, v0099, v0100);
    return onevalue(v0099);

v0024:
    v0099 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0099);

v0045:
    v0099 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0099);
}



/* Code for eofcheck */

static Lisp_Object MS_CDECL CC_eofcheck(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0099;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "eofcheck");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for eofcheck");
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
/* end of prologue */
    v0099 = qvalue(elt(env, 1)); /* program!* */
    v0002 = qvalue(elt(env, 2)); /* !$eof!$ */
    if (v0099 == v0002) goto v0032;
    v0002 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0002); }

v0032:
    v0099 = qvalue(elt(env, 3)); /* ttype!* */
    v0002 = (Lisp_Object)49; /* 3 */
    if (v0099 == v0002) goto v0051;
    v0002 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0002); }

v0051:
    v0002 = qvalue(elt(env, 4)); /* eof!* */
    v0002 = add1(v0002);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[0];
    qvalue(elt(env, 4)) = v0002; /* eof!* */
    { popv(1); return onevalue(v0002); }
/* error exit handlers */
v0100:
    popv(1);
    return nil;
}



/* Code for red!-weight */

static Lisp_Object CC_redKweight(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-weight");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0052 = stack[-1];
    fn = elt(env, 1); /* nonzero!-length */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-3];
    v0004 = stack[-1];
    v0052 = stack[0];
    fn = elt(env, 2); /* red!-weight1 */
    v0052 = (*qfn2(fn))(qenv(fn), v0004, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    {
        Lisp_Object v0012 = stack[-2];
        popv(4);
        return cons(v0012, v0052);
    }
/* error exit handlers */
v0019:
    popv(4);
    return nil;
}



/* Code for dp_sum */

static Lisp_Object CC_dp_sum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0163, v0185, v0105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_sum");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0152:
    v0163 = stack[-1];
    if (v0163 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0163 = stack[0];
    if (v0163 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0163 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0163 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    fn = elt(env, 2); /* mo_compare */
    v0163 = (*qfn2(fn))(qenv(fn), stack[-2], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0105 = v0163;
    v0185 = v0105;
    v0163 = (Lisp_Object)17; /* 1 */
    if (v0185 == v0163) goto v0007;
    v0185 = v0105;
    v0163 = (Lisp_Object)-15; /* -1 */
    if (v0185 == v0163) goto v0023;
    v0163 = stack[-1];
    fn = elt(env, 3); /* dp_lc */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0163 = stack[0];
    fn = elt(env, 3); /* dp_lc */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    fn = elt(env, 4); /* bc_sum */
    v0163 = (*qfn2(fn))(qenv(fn), stack[-2], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    stack[-2] = v0163;
    v0163 = stack[-2];
    fn = elt(env, 5); /* bc_zero!? */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    if (v0163 == nil) goto v0106;
    v0163 = stack[-1];
    v0185 = qcdr(v0163);
    v0163 = stack[0];
    v0163 = qcdr(v0163);
    stack[-1] = v0185;
    stack[0] = v0163;
    goto v0152;

v0106:
    v0163 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    fn = elt(env, 6); /* dp_term */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[-2], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-3];
    v0163 = stack[-1];
    v0185 = qcdr(v0163);
    v0163 = stack[0];
    v0163 = qcdr(v0163);
    v0163 = CC_dp_sum(env, v0185, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    {
        Lisp_Object v0175 = stack[-2];
        popv(4);
        return cons(v0175, v0163);
    }

v0023:
    v0163 = stack[0];
    stack[-2] = qcar(v0163);
    v0185 = stack[-1];
    v0163 = stack[0];
    v0163 = qcdr(v0163);
    v0163 = CC_dp_sum(env, v0185, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    {
        Lisp_Object v0162 = stack[-2];
        popv(4);
        return cons(v0162, v0163);
    }

v0007:
    v0163 = stack[-1];
    stack[-2] = qcar(v0163);
    v0163 = stack[-1];
    v0185 = qcdr(v0163);
    v0163 = stack[0];
    v0163 = CC_dp_sum(env, v0185, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    {
        Lisp_Object v0186 = stack[-2];
        popv(4);
        return cons(v0186, v0163);
    }
/* error exit handlers */
v0090:
    popv(4);
    return nil;
}



/* Code for resimp1 */

static Lisp_Object CC_resimp1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resimp1");
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
    v0044 = stack[0];
    v0002 = qcar(v0044);
    v0044 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0002, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    v0044 = stack[0];
    v0002 = qcdr(v0044);
    v0044 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    v0044 = (*qfn2(fn))(qenv(fn), v0002, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    fn = elt(env, 5); /* quotsq */
    v0044 = (*qfn2(fn))(qenv(fn), stack[-1], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    stack[0] = v0044;
    v0044 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 3)) = v0044; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v0003:
    popv(3);
    return nil;
}



/* Code for aronep!: */

static Lisp_Object CC_aronepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0029;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aronep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0000;
/* end of prologue */
    v0029 = qcdr(v0050);
    v0050 = (Lisp_Object)17; /* 1 */
    v0050 = (v0029 == v0050 ? lisp_true : nil);
    return onevalue(v0050);
}



/* Code for lalr_cached_goto */

static Lisp_Object CC_lalr_cached_goto(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_cached_goto");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0052 = v0001;
    v0004 = v0000;
/* end of prologue */
    stack[0] = v0004;
    v0004 = v0052;
    v0052 = qvalue(elt(env, 1)); /* goto_cache */
    fn = elt(env, 2); /* gethash */
    v0052 = (*qfn2(fn))(qenv(fn), v0004, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    v0052 = Lassoc(nil, stack[0], v0052);
    v0052 = qcdr(v0052);
    { popv(1); return onevalue(v0052); }
/* error exit handlers */
v0113:
    popv(1);
    return nil;
}



/* Code for reordsq */

static Lisp_Object CC_reordsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reordsq");
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
    v0051 = stack[0];
    v0051 = qcar(v0051);
    fn = elt(env, 1); /* reorder */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-2];
    v0051 = stack[0];
    v0051 = qcdr(v0051);
    fn = elt(env, 1); /* reorder */
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    {
        Lisp_Object v0055 = stack[-1];
        popv(3);
        return cons(v0055, v0051);
    }
/* error exit handlers */
v0083:
    popv(3);
    return nil;
}



/* Code for omobjs */

static Lisp_Object MS_CDECL CC_omobjs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobjs");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omobjs");
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
    v0042 = qvalue(elt(env, 1)); /* char */
    v0009 = elt(env, 2); /* (!/ o m a) */
    if (equal(v0042, v0009)) goto v0033;
    fn = elt(env, 4); /* omobj */
    v0009 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    stack[0] = v0009;
    fn = elt(env, 5); /* lex */
    v0009 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-1];
    v0009 = CC_omobjs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    v0042 = stack[0];
    if (v0042 == nil) goto v0012;
    v0042 = stack[0];
    popv(2);
    return cons(v0042, v0009);

v0012:
    v0042 = stack[0];
        popv(2);
        return Lappend(nil, v0042, v0009);

v0033:
    v0009 = nil;
    { popv(2); return onevalue(v0009); }
/* error exit handlers */
v0112:
    popv(2);
    return nil;
}



/* Code for isarb_int */

static Lisp_Object CC_isarb_int(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0044, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for isarb_int");
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
    v0044 = v0000;
/* end of prologue */
    v0024 = v0044;
    v0024 = Lconsp(nil, v0024);
    env = stack[0];
    if (v0024 == nil) goto v0010;
    v0024 = v0044;
    v0002 = qcar(v0024);
    v0024 = elt(env, 1); /* arbint */
    if (v0002 == v0024) goto v0029;
    v0024 = v0044;
    v0024 = qcdr(v0024);
    fn = elt(env, 4); /* multi_isarb_int */
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    goto v0010;

v0010:
    v0024 = nil;
    { popv(1); return onevalue(v0024); }

v0029:
    v0024 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0024; /* found_int */
    goto v0010;
/* error exit handlers */
v0099:
    popv(1);
    return nil;
}



/* Code for ps!:evaluate */

static Lisp_Object CC_psTevaluate(Lisp_Object env,
                         Lisp_Object v0001, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:evaluate");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0015;
    v0161 = v0001;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v0161; /* ps */
    v0041 = qvalue(elt(env, 1)); /* ps */
    v0161 = stack[-2];
    fn = elt(env, 3); /* ps!:get!-term */
    v0161 = (*qfn2(fn))(qenv(fn), v0041, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    stack[-1] = v0161;
    v0161 = stack[-1];
    if (v0161 == nil) goto v0004;
    v0161 = stack[-1];
    goto v0033;

v0033:
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v0161); }

v0004:
    v0161 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:last!-term */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    v0161 = add1(v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    stack[0] = v0161;
    goto v0079;

v0079:
    v0041 = stack[-2];
    v0161 = stack[0];
    v0161 = difference2(v0041, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    v0161 = Lminusp(nil, v0161);
    env = stack[-4];
    if (v0161 == nil) goto v0025;
    v0161 = stack[-1];
    goto v0033;

v0025:
    v0041 = qvalue(elt(env, 1)); /* ps */
    v0161 = stack[0];
    fn = elt(env, 5); /* ps!:evaluate!-next */
    v0161 = (*qfn2(fn))(qenv(fn), v0041, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    stack[-1] = v0161;
    v0161 = stack[0];
    v0161 = add1(v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    stack[0] = v0161;
    goto v0079;
/* error exit handlers */
v0084:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for noncomp2f */

static Lisp_Object CC_noncomp2f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0122;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomp2f");
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

v0010:
    v0123 = stack[0];
    if (!consp(v0123)) goto v0029;
    v0123 = stack[0];
    v0123 = qcar(v0123);
    v0123 = (consp(v0123) ? nil : lisp_true);
    goto v0050;

v0050:
    if (v0123 == nil) goto v0027;
    v0123 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0123); }

v0027:
    v0123 = stack[0];
    v0123 = qcar(v0123);
    v0123 = qcar(v0123);
    v0123 = qcar(v0123);
    v0122 = v0123;
    if (!consp(v0123)) goto v0113;
    v0123 = v0122;
    v0123 = qcar(v0123);
    if (!symbolp(v0123)) v0123 = nil;
    else { v0123 = qfastgets(v0123);
           if (v0123 != nil) { v0123 = elt(v0123, 0); /* noncom */
#ifdef RECORD_GET
             if (v0123 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0123 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0123 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0123 == SPID_NOPROP) v0123 = nil; else v0123 = lisp_true; }}
#endif
    if (v0123 == nil) goto v0121;
    v0123 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0123); }

v0121:
    v0123 = stack[0];
    v0123 = qcar(v0123);
    v0123 = qcdr(v0123);
    v0123 = CC_noncomp2f(env, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    if (v0123 == nil) goto v0034;
    v0123 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0123); }

v0034:
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    stack[0] = v0123;
    goto v0010;

v0113:
    v0123 = v0122;
    if (!symbolp(v0123)) v0123 = nil;
    else { v0123 = qfastgets(v0123);
           if (v0123 != nil) { v0123 = elt(v0123, 0); /* noncom */
#ifdef RECORD_GET
             if (v0123 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0123 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0123 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0123 == SPID_NOPROP) v0123 = nil; else v0123 = lisp_true; }}
#endif
    if (v0123 == nil) goto v0034;
    v0123 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0123); }

v0029:
    v0123 = qvalue(elt(env, 1)); /* t */
    goto v0050;
/* error exit handlers */
v0017:
    popv(2);
    return nil;
}



/* Code for contr1!-strand */

static Lisp_Object CC_contr1Kstrand(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0055, v0052, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contr1-strand");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0083 = v0001;
    v0055 = v0000;
/* end of prologue */
    v0004 = v0055;
    v0052 = v0083;
    v0055 = qvalue(elt(env, 1)); /* nil */
    v0083 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* contr2!-strand */
        return (*qfnn(fn))(qenv(fn), 4, v0004, v0052, v0055, v0083);
    }
}



/* Code for add2inputbuf */

static Lisp_Object CC_add2inputbuf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0079, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add2inputbuf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    fn = elt(env, 6); /* terminalp */
    v0078 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-2];
    if (v0078 == nil) goto v0050;
    v0078 = qvalue(elt(env, 2)); /* !*nosave!* */
    goto v0028;

v0028:
    if (v0078 == nil) goto v0053;
    v0078 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0078); }

v0053:
    v0102 = qvalue(elt(env, 4)); /* statcounter */
    v0079 = stack[0];
    v0078 = stack[-1];
    v0079 = list3(v0102, v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-2];
    v0078 = qvalue(elt(env, 5)); /* inputbuflis!* */
    v0078 = cons(v0079, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-2];
    qvalue(elt(env, 5)) = v0078; /* inputbuflis!* */
    v0078 = nil;
    { popv(3); return onevalue(v0078); }

v0050:
    v0078 = qvalue(elt(env, 1)); /* t */
    goto v0028;
/* error exit handlers */
v0008:
    popv(3);
    return nil;
}



/* Code for ckpreci!# */

static Lisp_Object CC_ckpreciC(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0041, v0160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ckpreci#");
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
    v0161 = stack[0];
    v0161 = qcar(v0161);
    fn = elt(env, 3); /* timesip */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    v0161 = stack[0];
    v0161 = qcdr(v0161);
    v0161 = qcar(v0161);
    fn = elt(env, 3); /* timesip */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    v0160 = stack[-1];
    v0041 = v0161;
    v0161 = qvalue(elt(env, 1)); /* !*complex */
    if (v0161 == nil) goto v0030;
    v0161 = v0160;
    if (v0161 == nil) goto v0113;
    v0161 = v0041;
    if (!(v0161 == nil)) goto v0113;
    v0161 = stack[0];
    v0161 = qcar(v0161);
    v0041 = qcdr(v0161);
    v0161 = stack[0];
    v0161 = qcdr(v0161);
    v0161 = qcar(v0161);
    {
        popv(3);
        fn = elt(env, 4); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v0041, v0161);
    }

v0113:
    v0161 = v0041;
    if (v0161 == nil) goto v0006;
    v0161 = v0160;
    if (!(v0161 == nil)) goto v0006;
    v0161 = stack[0];
    v0161 = qcdr(v0161);
    v0161 = qcar(v0161);
    v0041 = qcdr(v0161);
    v0161 = stack[0];
    v0161 = qcar(v0161);
    {
        popv(3);
        fn = elt(env, 4); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v0041, v0161);
    }

v0006:
    v0161 = nil;
    { popv(3); return onevalue(v0161); }

v0030:
    v0161 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0161); }
/* error exit handlers */
v0026:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-minusp */

static Lisp_Object CC_mvKpowKminusp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0053;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow-minusp");
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

v0152:
    v0012 = stack[0];
    if (v0012 == nil) goto v0045;
    v0012 = stack[0];
    v0053 = qcar(v0012);
    v0012 = (Lisp_Object)1; /* 0 */
    v0012 = (Lisp_Object)lessp2(v0053, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    v0012 = v0012 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0012 == nil)) { popv(2); return onevalue(v0012); }
    v0012 = stack[0];
    v0012 = qcdr(v0012);
    stack[0] = v0012;
    goto v0152;

v0045:
    v0012 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0012); }
/* error exit handlers */
v0054:
    popv(2);
    return nil;
}



setup_type const u06_setup[] =
{
    {"getroad",                 too_few_2,      CC_getroad,    wrong_no_2},
    {"getrmacro",               CC_getrmacro,   too_many_1,    wrong_no_1},
    {"dp_diff",                 too_few_2,      CC_dp_diff,    wrong_no_2},
    {"resimp",                  CC_resimp,      too_many_1,    wrong_no_1},
    {"insert_pv1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_insert_pv1},
    {"modplus:",                too_few_2,      CC_modplusT,   wrong_no_2},
    {"prin2t",                  CC_prin2t,      too_many_1,    wrong_no_1},
    {"rl_smcpknowl",            CC_rl_smcpknowl,too_many_1,    wrong_no_1},
    {"praddf",                  too_few_2,      CC_praddf,     wrong_no_2},
    {"gcdf1",                   too_few_2,      CC_gcdf1,      wrong_no_2},
    {"kernord",                 too_few_2,      CC_kernord,    wrong_no_2},
    {"ibalp_minclnr",           CC_ibalp_minclnr,too_many_1,   wrong_no_1},
    {"sfto_mvartest",           too_few_2,      CC_sfto_mvartest,wrong_no_2},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"mathml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml},
    {"bcsum",                   too_few_2,      CC_bcsum,      wrong_no_2},
    {"mknwedge",                CC_mknwedge,    too_many_1,    wrong_no_1},
    {"worderp",                 too_few_2,      CC_worderp,    wrong_no_2},
    {"vecopp",                  CC_vecopp,      too_many_1,    wrong_no_1},
    {"*ssave",                  too_few_2,      CC_Hssave,     wrong_no_2},
    {"pv_sort2a",               too_few_2,      CC_pv_sort2a,  wrong_no_2},
    {"mkgi",                    too_few_2,      CC_mkgi,       wrong_no_2},
    {"removev",                 too_few_2,      CC_removev,    wrong_no_2},
    {"tayexp-min2",             too_few_2,      CC_tayexpKmin2,wrong_no_2},
    {"qqe_qtidp",               CC_qqe_qtidp,   too_many_1,    wrong_no_1},
    {"emtch",                   CC_emtch,       too_many_1,    wrong_no_1},
    {"subscriptedvarp",         CC_subscriptedvarp,too_many_1, wrong_no_1},
    {"fast-column-dim",         CC_fastKcolumnKdim,too_many_1, wrong_no_1},
    {"xdegree",                 CC_xdegree,     too_many_1,    wrong_no_1},
    {"deg*form",                CC_degHform,    too_many_1,    wrong_no_1},
    {"convchk",                 CC_convchk,     too_many_1,    wrong_no_1},
    {"red-char-downcase",       CC_redKcharKdowncase,too_many_1,wrong_no_1},
    {"getphystype*sq",          CC_getphystypeHsq,too_many_1,  wrong_no_1},
    {"contrsp2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_contrsp2},
    {"groeb=testa",             too_few_2,      CC_groebMtesta,wrong_no_2},
    {"pcmult",                  too_few_2,      CC_pcmult,     wrong_no_2},
    {"gperm1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm1},
    {"arzerop:",                CC_arzeropT,    too_many_1,    wrong_no_1},
    {"c:ordexp",                too_few_2,      CC_cTordexp,   wrong_no_2},
    {"minus-mod-p",             CC_minusKmodKp, too_many_1,    wrong_no_1},
    {"polynomadd",              too_few_2,      CC_polynomadd, wrong_no_2},
    {"raddf",                   too_few_2,      CC_raddf,      wrong_no_2},
    {"exchk2",                  too_few_2,      CC_exchk2,     wrong_no_2},
    {"mri_type",                CC_mri_type,    too_many_1,    wrong_no_1},
    {"find",                    too_few_2,      CC_find,       wrong_no_2},
    {"sortcolelem",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_sortcolelem},
    {"pnthxzz",                 too_few_2,      CC_pnthxzz,    wrong_no_2},
    {"vevtdeg",                 CC_vevtdeg,     too_many_1,    wrong_no_1},
    {"*collectphysops",         CC_Hcollectphysops,too_many_1, wrong_no_1},
    {"sfpx",                    CC_sfpx,        too_many_1,    wrong_no_1},
    {"gcdf*",                   too_few_2,      CC_gcdfH,      wrong_no_2},
    {"tsym4",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_tsym4},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"lispapply",               too_few_2,      CC_lispapply,  wrong_no_2},
    {"mri_0mk2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mri_0mk2},
    {"ibalp_commonlenisone",    too_few_2,      CC_ibalp_commonlenisone,wrong_no_2},
    {"ratpoly_idl",             CC_ratpoly_idl, too_many_1,    wrong_no_1},
    {"multi_elem",              CC_multi_elem,  too_many_1,    wrong_no_1},
    {"rationalizei",            CC_rationalizei,too_many_1,    wrong_no_1},
    {"gsetsugar",               too_few_2,      CC_gsetsugar,  wrong_no_2},
    {"getphystype",             CC_getphystype, too_many_1,    wrong_no_1},
    {"setcloc*",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_setclocH},
    {"dp_term",                 too_few_2,      CC_dp_term,    wrong_no_2},
    {"dquot",                   too_few_2,      CC_dquot,      wrong_no_2},
    {"gperm",                   CC_gperm,       too_many_1,    wrong_no_1},
    {"gizerop:",                CC_gizeropT,    too_many_1,    wrong_no_1},
    {"rread1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rread1},
    {"lto_insert",              too_few_2,      CC_lto_insert, wrong_no_2},
    {"sfto_gcdf*",              too_few_2,      CC_sfto_gcdfH, wrong_no_2},
    {"mcharg2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg2},
    {"cgp_evlmon",              CC_cgp_evlmon,  too_many_1,    wrong_no_1},
    {"quotfd",                  too_few_2,      CC_quotfd,     wrong_no_2},
    {"retattributes",           too_few_2,      CC_retattributes,wrong_no_2},
    {"isarb_compl",             CC_isarb_compl, too_many_1,    wrong_no_1},
    {"downwght",                too_few_2,      CC_downwght,   wrong_no_2},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {"termordp",                too_few_2,      CC_termordp,   wrong_no_2},
    {":difference",             too_few_2,      CC_Tdifference,wrong_no_2},
    {"domain*p",                CC_domainHp,    too_many_1,    wrong_no_1},
    {"eofcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eofcheck},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {"dp_sum",                  too_few_2,      CC_dp_sum,     wrong_no_2},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"aronep:",                 CC_aronepT,     too_many_1,    wrong_no_1},
    {"lalr_cached_goto",        too_few_2,      CC_lalr_cached_goto,wrong_no_2},
    {"reordsq",                 CC_reordsq,     too_many_1,    wrong_no_1},
    {"omobjs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobjs},
    {"isarb_int",               CC_isarb_int,   too_many_1,    wrong_no_1},
    {"ps:evaluate",             too_few_2,      CC_psTevaluate,wrong_no_2},
    {"noncomp2f",               CC_noncomp2f,   too_many_1,    wrong_no_1},
    {"contr1-strand",           too_few_2,      CC_contr1Kstrand,wrong_no_2},
    {"add2inputbuf",            too_few_2,      CC_add2inputbuf,wrong_no_2},
    {"ckpreci#",                CC_ckpreciC,    too_many_1,    wrong_no_1},
    {"mv-pow-minusp",           CC_mvKpowKminusp,too_many_1,   wrong_no_1},
    {NULL, (one_args *)"u06", (two_args *)"18959 4645071 5526558", 0}
};

/* end of generated code */
