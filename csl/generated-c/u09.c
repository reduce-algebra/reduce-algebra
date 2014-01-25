
/* $destdir\u09.c        Machine generated C code */

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


/* Code for add2resultbuf */

static Lisp_Object CC_add2resultbuf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0017, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add2resultbuf");
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
    v0016 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0018 = v0016;
    v0017 = elt(env, 1); /* symbolic */
    if (v0018 == v0017) goto v0019;
    v0017 = stack[0];
    if (v0017 == nil) goto v0020;
    v0017 = qvalue(elt(env, 5)); /* nil */
    goto v0021;

v0021:
    if (v0017 == nil) goto v0022;
    v0017 = qvalue(elt(env, 2)); /* t */
    goto v0023;

v0023:
    if (v0017 == nil) goto v0024;
    v0016 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v0016); }

v0024:
    v0017 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v0017 == nil) goto v0025;
    v0018 = elt(env, 7); /* ws */
    v0017 = stack[0];
    fn = elt(env, 11); /* putobject */
    v0016 = (*qfnn(fn))(qenv(fn), 3, v0018, v0017, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    goto v0027;

v0027:
    fn = elt(env, 12); /* terminalp */
    v0016 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    if (v0016 == nil) goto v0028;
    v0018 = qvalue(elt(env, 9)); /* statcounter */
    v0017 = stack[0];
    v0016 = qvalue(elt(env, 10)); /* resultbuflis!* */
    v0016 = acons(v0018, v0017, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    qvalue(elt(env, 10)) = v0016; /* resultbuflis!* */
    goto v0028;

v0028:
    v0016 = nil;
    { popv(2); return onevalue(v0016); }

v0025:
    v0016 = qvalue(elt(env, 5)); /* nil */
    v0016 = ncons(v0016);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0016; /* alglist!* */
    v0016 = stack[0];
    qvalue(elt(env, 7)) = v0016; /* ws */
    goto v0027;

v0022:
    v0017 = qvalue(elt(env, 6)); /* !*nosave!* */
    goto v0023;

v0020:
    v0017 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v0017 == nil) goto v0029;
    v0018 = v0016;
    v0017 = elt(env, 4); /* empty_list */
    v0017 = (v0018 == v0017 ? lisp_true : nil);
    v0017 = (v0017 == nil ? lisp_true : nil);
    goto v0021;

v0029:
    v0017 = qvalue(elt(env, 2)); /* t */
    goto v0021;

v0019:
    v0017 = qvalue(elt(env, 2)); /* t */
    goto v0023;
/* error exit handlers */
v0026:
    popv(2);
    return nil;
}



/* Code for pdmult */

static Lisp_Object CC_pdmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0062;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pdmult");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v0001;
    v0061 = v0000;
/* end of prologue */
    stack[-9] = v0061;
    v0061 = stack[-9];
    if (v0061 == nil) goto v0063;
    v0061 = stack[-9];
    v0061 = qcar(v0061);
    stack[-4] = v0061;
    v0061 = stack[-4];
    v0062 = qcar(v0061);
    v0061 = stack[-8];
    fn = elt(env, 2); /* pair */
    v0061 = (*qfn2(fn))(qenv(fn), v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    stack[-3] = v0061;
    v0061 = stack[-3];
    if (v0061 == nil) goto v0065;
    v0061 = stack[-3];
    v0061 = qcar(v0061);
    v0062 = v0061;
    v0062 = qcar(v0062);
    v0061 = qcdr(v0061);
    v0061 = (Lisp_Object)(int32_t)((int32_t)v0062 + (int32_t)v0061 - TAG_FIXNUM);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    stack[-1] = v0061;
    stack[-2] = v0061;
    goto v0066;

v0066:
    v0061 = stack[-3];
    v0061 = qcdr(v0061);
    stack[-3] = v0061;
    v0061 = stack[-3];
    if (v0061 == nil) goto v0067;
    stack[0] = stack[-1];
    v0061 = stack[-3];
    v0061 = qcar(v0061);
    v0062 = v0061;
    v0062 = qcar(v0062);
    v0061 = qcdr(v0061);
    v0061 = (Lisp_Object)(int32_t)((int32_t)v0062 + (int32_t)v0061 - TAG_FIXNUM);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    v0061 = Lrplacd(nil, stack[0], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    v0061 = stack[-1];
    v0061 = qcdr(v0061);
    stack[-1] = v0061;
    goto v0066;

v0067:
    v0061 = stack[-2];
    v0062 = v0061;
    goto v0009;

v0009:
    v0061 = stack[-4];
    v0061 = qcdr(v0061);
    v0061 = cons(v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    stack[-6] = v0061;
    stack[-7] = v0061;
    goto v0068;

v0068:
    v0061 = stack[-9];
    v0061 = qcdr(v0061);
    stack[-9] = v0061;
    v0061 = stack[-9];
    if (v0061 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v0061 = stack[-9];
    v0061 = qcar(v0061);
    stack[-4] = v0061;
    v0061 = stack[-4];
    v0062 = qcar(v0061);
    v0061 = stack[-8];
    fn = elt(env, 2); /* pair */
    v0061 = (*qfn2(fn))(qenv(fn), v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    stack[-3] = v0061;
    v0061 = stack[-3];
    if (v0061 == nil) goto v0069;
    v0061 = stack[-3];
    v0061 = qcar(v0061);
    v0062 = v0061;
    v0062 = qcar(v0062);
    v0061 = qcdr(v0061);
    v0061 = (Lisp_Object)(int32_t)((int32_t)v0062 + (int32_t)v0061 - TAG_FIXNUM);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    stack[-1] = v0061;
    stack[-2] = v0061;
    goto v0070;

v0070:
    v0061 = stack[-3];
    v0061 = qcdr(v0061);
    stack[-3] = v0061;
    v0061 = stack[-3];
    if (v0061 == nil) goto v0071;
    stack[0] = stack[-1];
    v0061 = stack[-3];
    v0061 = qcar(v0061);
    v0062 = v0061;
    v0062 = qcar(v0062);
    v0061 = qcdr(v0061);
    v0061 = (Lisp_Object)(int32_t)((int32_t)v0062 + (int32_t)v0061 - TAG_FIXNUM);
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    v0061 = Lrplacd(nil, stack[0], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    v0061 = stack[-1];
    v0061 = qcdr(v0061);
    stack[-1] = v0061;
    goto v0070;

v0071:
    v0061 = stack[-2];
    v0062 = v0061;
    goto v0072;

v0072:
    v0061 = stack[-4];
    v0061 = qcdr(v0061);
    v0061 = cons(v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    v0061 = ncons(v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    v0061 = Lrplacd(nil, stack[-5], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-10];
    v0061 = stack[-6];
    v0061 = qcdr(v0061);
    stack[-6] = v0061;
    goto v0068;

v0069:
    v0061 = qvalue(elt(env, 1)); /* nil */
    v0062 = v0061;
    goto v0072;

v0065:
    v0061 = qvalue(elt(env, 1)); /* nil */
    v0062 = v0061;
    goto v0009;

v0063:
    v0061 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v0061); }
/* error exit handlers */
v0064:
    popv(11);
    return nil;
}



/* Code for th_match0 */

static Lisp_Object CC_th_match0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0029, v0078;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for th_match0");
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
    v0078 = v0000;
/* end of prologue */
    v0077 = v0078;
    v0029 = qcar(v0077);
    v0077 = stack[0];
    v0077 = qcar(v0077);
    if (equal(v0029, v0077)) goto v0079;
    v0077 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0077); }

v0079:
    v0077 = v0078;
    v0077 = qcdr(v0077);
    v0077 = qcar(v0077);
    stack[-1] = Llength(nil, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-2];
    v0077 = stack[0];
    v0077 = qcdr(v0077);
    v0077 = qcar(v0077);
    v0077 = Llength(nil, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    v0077 = (equal(stack[-1], v0077) ? lisp_true : nil);
    { popv(3); return onevalue(v0077); }
/* error exit handlers */
v0080:
    popv(3);
    return nil;
}



/* Code for general!-modular!-quotient */

static Lisp_Object CC_generalKmodularKquotient(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-quotient");
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
    v0063 = v0001;
    v0075 = v0000;
/* end of prologue */
    stack[0] = v0075;
    fn = elt(env, 1); /* general!-modular!-reciprocal */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-1];
    {
        Lisp_Object v0079 = stack[0];
        popv(2);
        fn = elt(env, 2); /* general!-modular!-times */
        return (*qfn2(fn))(qenv(fn), v0079, v0063);
    }
/* error exit handlers */
v0076:
    popv(2);
    return nil;
}



/* Code for clear!-column */

static Lisp_Object MS_CDECL CC_clearKcolumn(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0154, v0155, v0156, v0157, v0158, v0159, v0160, v0161, v0162, v0163;
    Lisp_Object v0050, v0048, v0153, v0001;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "clear-column");
    va_start(aa, nargs);
    v0001 = va_arg(aa, Lisp_Object);
    v0153 = va_arg(aa, Lisp_Object);
    v0048 = va_arg(aa, Lisp_Object);
    v0050 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for clear-column");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0050,v0048,v0153,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0001,v0153,v0048,v0050);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0050;
    stack[-1] = v0048;
    v0154 = v0153;
    stack[-2] = v0001;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* null!-space!-basis */
    qvalue(elt(env, 1)) = nil; /* null!-space!-basis */
    qvalue(elt(env, 1)) = v0154; /* null!-space!-basis */
    v0154 = (Lisp_Object)1; /* 0 */
    goto v0029;

v0029:
    v0156 = stack[-1];
    v0155 = v0154;
    v0156 = *(Lisp_Object *)((char *)v0156 + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    v0155 = stack[-2];
    v0156 = *(Lisp_Object *)((char *)v0156 + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    v0155 = (Lisp_Object)1; /* 0 */
    if (v0156 == v0155) goto v0164;
    v0156 = v0154;
    v0155 = stack[-2];
    if (((int32_t)(v0156)) < ((int32_t)(v0155))) goto v0006;
    v0155 = qvalue(elt(env, 3)); /* nil */
    goto v0074;

v0074:
    if (v0155 == nil) goto v0165;
    v0156 = (Lisp_Object)((int32_t)(v0154) + 0x10);
    v0154 = v0156;
    v0155 = stack[0];
    if (!(((int32_t)(v0156)) > ((int32_t)(v0155)))) goto v0029;
    v0155 = stack[-2];
    v0154 = qvalue(elt(env, 1)); /* null!-space!-basis */
    v0154 = cons(v0155, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    goto v0068;

v0068:
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    { popv(5); return onevalue(v0154); }

v0165:
    v0156 = stack[-1];
    v0155 = v0154;
    v0155 = *(Lisp_Object *)((char *)v0156 + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    v0163 = v0155;
    v0157 = stack[-1];
    v0156 = v0154;
    v0155 = stack[-1];
    v0154 = stack[-2];
    v0154 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    *(Lisp_Object *)((char *)v0157 + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL))) = v0154;
    v0155 = stack[-1];
    v0154 = stack[-2];
    v0156 = v0163;
    *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL))) = v0156;
    v0155 = stack[-1];
    v0154 = stack[-2];
    v0155 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0154 = stack[-2];
    v0154 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0154 = Lmodular_reciprocal(nil, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0154);
        if (w != 0) w = current_modulus - w;
        v0154 = fixnum_of_int(w);
    }
    v0163 = v0154;
    v0154 = (Lisp_Object)1; /* 0 */
    v0162 = v0154;
    goto v0035;

v0035:
    v0155 = stack[0];
    v0154 = v0162;
    v0154 = (Lisp_Object)(int32_t)((int32_t)v0155 - (int32_t)v0154 + TAG_FIXNUM);
    v0154 = ((intptr_t)(v0154) < 0 ? lisp_true : nil);
    if (v0154 == nil) goto v0167;
    v0154 = stack[-2];
    v0158 = v0154;
    goto v0168;

v0168:
    v0155 = stack[0];
    v0154 = v0158;
    v0154 = (Lisp_Object)(int32_t)((int32_t)v0155 - (int32_t)v0154 + TAG_FIXNUM);
    v0154 = ((intptr_t)(v0154) < 0 ? lisp_true : nil);
    if (v0154 == nil) goto v0169;
    v0154 = qvalue(elt(env, 1)); /* null!-space!-basis */
    goto v0068;

v0169:
    v0155 = stack[-1];
    v0154 = stack[-2];
    v0157 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0156 = v0158;
    v0155 = stack[-1];
    v0154 = stack[-2];
    v0155 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0154 = v0158;
    v0155 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0154 = v0163;
    v0154 = Lmodular_times(nil, v0155, v0154);
    env = stack[-4];
    *(Lisp_Object *)((char *)v0157 + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL))) = v0154;
    v0154 = v0158;
    v0154 = (Lisp_Object)((int32_t)(v0154) + 0x10);
    v0158 = v0154;
    goto v0168;

v0167:
    v0155 = v0162;
    v0154 = stack[-2];
    if (equal(v0155, v0154)) goto v0037;
    v0155 = stack[-1];
    v0154 = v0162;
    v0155 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0154 = stack[-2];
    v0154 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0161 = v0154;
    v0155 = v0161;
    v0154 = (Lisp_Object)1; /* 0 */
    if (v0155 == v0154) goto v0037;
    v0155 = v0161;
    v0154 = v0163;
    v0154 = Lmodular_times(nil, v0155, v0154);
    env = stack[-4];
    v0161 = v0154;
    v0154 = stack[-2];
    v0160 = v0154;
    goto v0170;

v0170:
    v0155 = stack[0];
    v0154 = v0160;
    v0154 = (Lisp_Object)(int32_t)((int32_t)v0155 - (int32_t)v0154 + TAG_FIXNUM);
    v0154 = ((intptr_t)(v0154) < 0 ? lisp_true : nil);
    if (!(v0154 == nil)) goto v0037;
    v0155 = stack[-1];
    v0154 = v0162;
    v0159 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0158 = v0160;
    v0155 = stack[-1];
    v0154 = v0162;
    v0155 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0154 = v0160;
    v0157 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0156 = v0161;
    v0155 = stack[-1];
    v0154 = stack[-2];
    v0155 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0154 = v0160;
    v0154 = *(Lisp_Object *)((char *)v0155 + (CELL-TAG_VECTOR) + ((int32_t)v0154/(16/CELL)));
    v0154 = Lmodular_times(nil, v0156, v0154);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0157) + int_of_fixnum(v0154);
        if (w >= current_modulus) w -= current_modulus;
        v0154 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0159 + (CELL-TAG_VECTOR) + ((int32_t)v0158/(16/CELL))) = v0154;
    v0154 = v0160;
    v0154 = (Lisp_Object)((int32_t)(v0154) + 0x10);
    v0160 = v0154;
    goto v0170;

v0037:
    v0154 = v0162;
    v0154 = (Lisp_Object)((int32_t)(v0154) + 0x10);
    v0162 = v0154;
    goto v0035;

v0006:
    v0156 = stack[-1];
    v0155 = v0154;
    v0156 = *(Lisp_Object *)((char *)v0156 + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    v0155 = v0154;
    v0156 = *(Lisp_Object *)((char *)v0156 + (CELL-TAG_VECTOR) + ((int32_t)v0155/(16/CELL)));
    v0155 = (Lisp_Object)1; /* 0 */
    v0155 = (v0156 == v0155 ? lisp_true : nil);
    v0155 = (v0155 == nil ? lisp_true : nil);
    goto v0074;

v0164:
    v0155 = qvalue(elt(env, 2)); /* t */
    goto v0074;
/* error exit handlers */
v0166:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    popv(5);
    return nil;
}



/* Code for gionep!: */

static Lisp_Object CC_gionepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0020, v0172;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gionep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0172 = v0000;
/* end of prologue */
    v0021 = v0172;
    v0021 = qcdr(v0021);
    v0020 = qcar(v0021);
    v0021 = (Lisp_Object)17; /* 1 */
    if (v0020 == v0021) goto v0076;
    v0021 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0021);

v0076:
    v0021 = v0172;
    v0021 = qcdr(v0021);
    v0020 = qcdr(v0021);
    v0021 = (Lisp_Object)1; /* 0 */
    v0021 = (v0020 == v0021 ? lisp_true : nil);
    return onevalue(v0021);
}



/* Code for canonsq */

static Lisp_Object CC_canonsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0189, v0190, v0191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for canonsq");
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
    v0189 = stack[-2];
    v0190 = qcdr(v0189);
    v0189 = (Lisp_Object)17; /* 1 */
    if (v0190 == v0189) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    if (v0189 == nil) goto v0143;
    stack[-1] = nil;
    v0189 = qvalue(elt(env, 2)); /* asymplis!* */
    if (v0189 == nil) goto v0029;
    v0189 = stack[-2];
    v0190 = qcar(v0189);
    v0189 = stack[-2];
    v0189 = qcdr(v0189);
    fn = elt(env, 7); /* gcdf */
    v0190 = (*qfn2(fn))(qenv(fn), v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-3] = v0190;
    v0189 = (Lisp_Object)17; /* 1 */
    if (v0190 == v0189) goto v0029;
    v0189 = stack[-2];
    v0190 = qcar(v0189);
    v0189 = stack[-3];
    fn = elt(env, 8); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0189 = stack[-2];
    v0190 = qcdr(v0189);
    v0189 = stack[-3];
    fn = elt(env, 8); /* quotf */
    v0189 = (*qfn2(fn))(qenv(fn), v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0189 = cons(stack[0], v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-2] = v0189;
    goto v0029;

v0029:
    v0189 = stack[-2];
    v0189 = qcdr(v0189);
    fn = elt(env, 9); /* lnc */
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-3] = v0189;
    v0190 = stack[-3];
    v0189 = (Lisp_Object)17; /* 1 */
    if (v0190 == v0189) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0189 = stack[-3];
    if (!consp(v0189)) goto v0017;
    v0189 = stack[-3];
    v0189 = qcar(v0189);
    if (!symbolp(v0189)) v0190 = nil;
    else { v0190 = qfastgets(v0189);
           if (v0190 != nil) { v0190 = elt(v0190, 30); /* minusp */
#ifdef RECORD_GET
             if (v0190 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0190 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0190 == SPID_NOPROP) v0190 = nil; }}
#endif
    v0189 = stack[-3];
    v0189 = Lapply1(nil, v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    if (v0189 == nil) goto v0193;
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    fn = elt(env, 10); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0189 = stack[-2];
    v0189 = qcdr(v0189);
    fn = elt(env, 10); /* negf */
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0189 = cons(stack[0], v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-2] = v0189;
    v0189 = stack[-3];
    v0190 = qcar(v0189);
    v0189 = elt(env, 3); /* difference */
    stack[0] = get(v0190, v0189);
    env = stack[-4];
    v0189 = stack[-3];
    v0189 = qcar(v0189);
    if (!symbolp(v0189)) v0190 = nil;
    else { v0190 = qfastgets(v0189);
           if (v0190 != nil) { v0190 = elt(v0190, 34); /* i2d */
#ifdef RECORD_GET
             if (v0190 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0190 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0190 == SPID_NOPROP) v0190 = nil; }}
#endif
    v0189 = (Lisp_Object)1; /* 0 */
    v0190 = Lapply1(nil, v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0189 = stack[-3];
    v0189 = Lapply2(nil, 3, stack[0], v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-3] = v0189;
    goto v0193;

v0193:
    v0189 = stack[-3];
    if (is_number(v0189)) goto v0062;
    v0190 = qvalue(elt(env, 4)); /* dmode!* */
    v0189 = elt(env, 5); /* unitsfn */
    v0189 = get(v0190, v0189);
    env = stack[-4];
    stack[-1] = v0189;
    goto v0194;

v0194:
    if (v0189 == nil) goto v0195;
    v0191 = stack[-1];
    v0190 = stack[-2];
    v0189 = stack[-3];
        popv(5);
        return Lapply2(nil, 3, v0191, v0190, v0189);

v0195:
    v0189 = qvalue(elt(env, 4)); /* dmode!* */
    if (!symbolp(v0189)) v0189 = nil;
    else { v0189 = qfastgets(v0189);
           if (v0189 != nil) { v0189 = elt(v0189, 3); /* field */
#ifdef RECORD_GET
             if (v0189 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0189 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0189 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0189 == SPID_NOPROP) v0189 = nil; else v0189 = lisp_true; }}
#endif
    if (v0189 == nil) goto v0196;
    v0189 = qvalue(elt(env, 6)); /* t */
    goto v0197;

v0197:
    if (v0189 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0190 = stack[-3];
    v0189 = stack[-2];
    {
        popv(5);
        fn = elt(env, 11); /* fieldconv */
        return (*qfn2(fn))(qenv(fn), v0190, v0189);
    }

v0196:
    v0189 = stack[-3];
    if (!consp(v0189)) goto v0198;
    v0189 = stack[-3];
    v0189 = qcar(v0189);
    if (!symbolp(v0189)) v0189 = nil;
    else { v0189 = qfastgets(v0189);
           if (v0189 != nil) { v0189 = elt(v0189, 3); /* field */
#ifdef RECORD_GET
             if (v0189 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0189 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0189 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0189 == SPID_NOPROP) v0189 = nil; else v0189 = lisp_true; }}
#endif
    goto v0197;

v0198:
    v0189 = qvalue(elt(env, 1)); /* nil */
    goto v0197;

v0062:
    v0189 = qvalue(elt(env, 1)); /* nil */
    goto v0194;

v0017:
    v0189 = stack[-3];
    v0189 = Lminusp(nil, v0189);
    env = stack[-4];
    if (v0189 == nil) goto v0193;
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    fn = elt(env, 10); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0189 = stack[-2];
    v0189 = qcdr(v0189);
    fn = elt(env, 10); /* negf */
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0189 = cons(stack[0], v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-2] = v0189;
    v0189 = stack[-3];
    v0189 = negate(v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-3] = v0189;
    goto v0193;

v0143:
    v0190 = qvalue(elt(env, 1)); /* nil */
    v0189 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0190, v0189);
/* error exit handlers */
v0192:
    popv(5);
    return nil;
}



/* Code for rl_gettype */

static Lisp_Object CC_rl_gettype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0199, v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_gettype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0199 = v0000;
/* end of prologue */
    v0079 = v0199;
    if (!symbolp(v0079)) v0079 = nil;
    else { v0079 = qfastgets(v0079);
           if (v0079 != nil) { v0079 = elt(v0079, 4); /* avalue */
#ifdef RECORD_GET
             if (v0079 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0079 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0079 == SPID_NOPROP) v0079 = nil; }}
#endif
    v0014 = v0079;
    v0079 = v0014;
    if (v0079 == nil) goto v0063;
    v0079 = v0014;
    v0079 = qcar(v0079);
    return onevalue(v0079);

v0063:
    v0079 = v0199;
    if (!symbolp(v0079)) v0079 = nil;
    else { v0079 = qfastgets(v0079);
           if (v0079 != nil) { v0079 = elt(v0079, 2); /* rtype */
#ifdef RECORD_GET
             if (v0079 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0079 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0079 == SPID_NOPROP) v0079 = nil; }}
#endif
    return onevalue(v0079);
}



/* Code for omair */

static Lisp_Object MS_CDECL CC_omair(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omair");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omair");
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
    stack[0] = nil;
    fn = elt(env, 4); /* lex */
    v0011 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    fn = elt(env, 5); /* omobj */
    v0011 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    stack[-1] = v0011;
    v0011 = stack[-1];
    v0077 = qcar(v0011);
    v0011 = elt(env, 1); /* matrix */
    if (v0077 == v0011) goto v0073;
    fn = elt(env, 4); /* lex */
    v0011 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    fn = elt(env, 6); /* omobjs */
    v0011 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    stack[0] = v0011;
    v0011 = elt(env, 2); /* (!/ o m a) */
    fn = elt(env, 7); /* checktag */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    goto v0073;

v0073:
    v0077 = stack[-1];
    v0011 = stack[0];
        popv(3);
        return Lappend(nil, v0077, v0011);
/* error exit handlers */
v0200:
    popv(3);
    return nil;
}



/* Code for simp */

static Lisp_Object CC_simp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0292, v0293, v0294;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0000;
/* end of prologue */
    v0292 = qvalue(elt(env, 1)); /* varstack!* */
    stack[-6] = qvalue(elt(env, 1)); /* varstack!* */
    qvalue(elt(env, 1)) = v0292; /* varstack!* */
    stack[-1] = nil;
    v0292 = stack[-5];
    v0292 = integerp(v0292);
    if (v0292 == nil) goto v0295;
    v0293 = stack[-5];
    v0292 = (Lisp_Object)1; /* 0 */
    if (v0293 == v0292) goto v0055;
    v0292 = qvalue(elt(env, 3)); /* dmode!* */
    if (!(v0292 == nil)) goto v0296;
    v0293 = stack[-5];
    v0292 = (Lisp_Object)17; /* 1 */
    v0292 = cons(v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0081:
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    { popv(8); return onevalue(v0292); }

v0296:
    v0293 = stack[-5];
    v0292 = qvalue(elt(env, 1)); /* varstack!* */
    v0292 = cons(v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    qvalue(elt(env, 1)) = v0292; /* varstack!* */
    v0293 = qvalue(elt(env, 4)); /* simpcount!* */
    v0292 = qvalue(elt(env, 5)); /* simplimit!* */
    v0292 = (Lisp_Object)greaterp2(v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    v0292 = v0292 ? lisp_true : nil;
    env = stack[-7];
    if (v0292 == nil) goto v0026;
    v0292 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 4)) = v0292; /* simpcount!* */
    v0294 = elt(env, 6); /* alg */
    v0293 = (Lisp_Object)193; /* 12 */
    v0292 = elt(env, 7); /* "Simplification recursion too deep" */
    fn = elt(env, 24); /* rerror */
    v0292 = (*qfnn(fn))(qenv(fn), 3, v0294, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0298;

v0298:
    v0292 = qvalue(elt(env, 4)); /* simpcount!* */
    v0292 = add1(v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    qvalue(elt(env, 4)) = v0292; /* simpcount!* */
    v0292 = stack[-5];
    if (!consp(v0292)) goto v0299;
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (symbolp(v0292)) goto v0126;
    v0292 = qvalue(elt(env, 12)); /* t */
    goto v0038;

v0038:
    if (v0292 == nil) goto v0037;
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!consp(v0292)) goto v0300;
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    v0292 = qcar(v0292);
    if (!(symbolp(v0292))) goto v0191;
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    v0293 = qcar(v0292);
    v0292 = elt(env, 15); /* name */
    v0292 = get(v0293, v0292);
    env = stack[-7];
    stack[-1] = v0292;
    if (v0292 == nil) goto v0191;
    v0293 = stack[-5];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0191:
    v0292 = stack[-5];
    v0293 = qcar(v0292);
    v0292 = elt(env, 16); /* mat */
    if (!consp(v0293)) goto v0301;
    v0293 = qcar(v0293);
    if (!(v0293 == v0292)) goto v0301;
    v0292 = stack[-5];
    v0292 = qcdr(v0292);
    fn = elt(env, 26); /* revlis */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    stack[-1] = v0292;
    fn = elt(env, 27); /* numlis */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    if (v0292 == nil) goto v0302;
    v0292 = stack[-1];
    v0293 = Llength(nil, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = (Lisp_Object)33; /* 2 */
    v0292 = (v0293 == v0292 ? lisp_true : nil);
    goto v0170;

v0170:
    if (v0292 == nil) goto v0104;
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    v0293 = qcdr(v0292);
    v0292 = stack[-1];
    v0292 = qcar(v0292);
    fn = elt(env, 28); /* nth */
    v0293 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-1];
    v0292 = qcdr(v0292);
    v0292 = qcar(v0292);
    fn = elt(env, 28); /* nth */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0293 = CC_simp(env, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0104:
    v0293 = stack[-5];
    v0292 = qvalue(elt(env, 12)); /* t */
    fn = elt(env, 29); /* errpri2 */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0303;

v0303:
    v0292 = nil;
    goto v0081;

v0302:
    v0292 = qvalue(elt(env, 2)); /* nil */
    goto v0170;

v0301:
    v0292 = qvalue(elt(env, 2)); /* nil */
    goto v0170;

v0300:
    v0292 = stack[-5];
    v0293 = qcar(v0292);
    v0292 = elt(env, 14); /* "operator" */
    fn = elt(env, 30); /* typerr */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0303;

v0037:
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 59); /* opfn */
#ifdef RECORD_GET
             if (v0292 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0292 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0292 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; else v0292 = lisp_true; }}
#endif
    if (v0292 == nil) goto v0304;
    v0292 = stack[-5];
    fn = elt(env, 31); /* opfneval */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    stack[-1] = v0292;
    fn = elt(env, 32); /* getrtype */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0293 = v0292;
    if (v0292 == nil) goto v0305;
    v0292 = elt(env, 17); /* yetunknowntype */
    if (v0293 == v0292) goto v0306;
    v0292 = qvalue(elt(env, 2)); /* nil */
    goto v0307;

v0307:
    if (v0292 == nil) goto v0308;
    v0292 = stack[-1];
    v0292 = CC_simp(env, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0308:
    v0293 = stack[-5];
    v0292 = elt(env, 18); /* "scalar" */
    fn = elt(env, 30); /* typerr */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0303;

v0306:
    v0292 = stack[-1];
    fn = elt(env, 33); /* reval */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    stack[-1] = v0292;
    fn = elt(env, 32); /* getrtype */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = (v0292 == nil ? lisp_true : nil);
    goto v0307;

v0305:
    v0292 = stack[-1];
    fn = elt(env, 34); /* simp_without_resimp */
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0304:
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 45); /* psopfn */
#ifdef RECORD_GET
             if (v0292 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0292 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; }}
#endif
    stack[-1] = v0292;
    if (v0292 == nil) goto v0088;
    stack[0] = stack[-1];
    v0292 = stack[-5];
    fn = elt(env, 35); /* argnochk */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = qcdr(v0292);
    v0292 = Lapply1(nil, stack[0], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    stack[-1] = v0292;
    fn = elt(env, 32); /* getrtype */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    if (v0292 == nil) goto v0309;
    v0293 = stack[-5];
    v0292 = elt(env, 18); /* "scalar" */
    fn = elt(env, 30); /* typerr */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0303;

v0309:
    v0293 = stack[-1];
    v0292 = stack[-5];
    if (equal(v0293, v0292)) goto v0310;
    v0292 = stack[-1];
    fn = elt(env, 34); /* simp_without_resimp */
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0310:
    v0293 = stack[-1];
    v0292 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 36); /* to */
    v0293 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = (Lisp_Object)17; /* 1 */
    v0292 = cons(v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0293 = ncons(v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = (Lisp_Object)17; /* 1 */
    v0293 = cons(v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0088:
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 41); /* polyfn */
#ifdef RECORD_GET
             if (v0292 != SPID_NOPROP)
                record_get(elt(fastget_names, 41), 1);
             else record_get(elt(fastget_names, 41), 0),
                v0292 = nil; }
           else record_get(elt(fastget_names, 41), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; }}
#endif
    stack[-1] = v0292;
    if (v0292 == nil) goto v0311;
    v0292 = stack[-5];
    fn = elt(env, 35); /* argnochk */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    stack[-4] = stack[-1];
    v0292 = stack[-5];
    v0292 = qcdr(v0292);
    stack[-3] = v0292;
    v0292 = stack[-3];
    if (v0292 == nil) goto v0312;
    v0292 = stack[-3];
    v0292 = qcar(v0292);
    fn = elt(env, 37); /* simp!* */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    fn = elt(env, 38); /* !*q2f */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = ncons(v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    stack[-1] = v0292;
    stack[-2] = v0292;
    goto v0313;

v0313:
    v0292 = stack[-3];
    v0292 = qcdr(v0292);
    stack[-3] = v0292;
    v0292 = stack[-3];
    if (v0292 == nil) goto v0314;
    stack[0] = stack[-1];
    v0292 = stack[-3];
    v0292 = qcar(v0292);
    fn = elt(env, 37); /* simp!* */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    fn = elt(env, 38); /* !*q2f */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = ncons(v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = Lrplacd(nil, stack[0], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-1];
    v0292 = qcdr(v0292);
    stack[-1] = v0292;
    goto v0313;

v0314:
    v0292 = stack[-2];
    goto v0315;

v0315:
    fn = elt(env, 39); /* lispapply */
    v0293 = (*qfn2(fn))(qenv(fn), stack[-4], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = (Lisp_Object)17; /* 1 */
    v0293 = cons(v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0312:
    v0292 = qvalue(elt(env, 2)); /* nil */
    goto v0315;

v0311:
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 9); /* opmtch */
#ifdef RECORD_GET
             if (v0292 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0292 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; }}
#endif
    if (v0292 == nil) goto v0316;
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0293 = nil;
    else { v0293 = qfastgets(v0292);
           if (v0293 != nil) { v0293 = elt(v0293, 22); /* simpfn */
#ifdef RECORD_GET
             if (v0293 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v0293 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v0293 == SPID_NOPROP) v0293 = nil; }}
#endif
    v0292 = elt(env, 19); /* simpiden */
    if (v0293 == v0292) goto v0317;
    v0292 = stack[-5];
    fn = elt(env, 40); /* opmtchrevop */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    stack[-1] = v0292;
    goto v0318;

v0318:
    if (v0292 == nil) goto v0316;
    v0292 = stack[-1];
    v0293 = CC_simp(env, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0316:
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 22); /* simpfn */
#ifdef RECORD_GET
             if (v0292 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v0292 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; }}
#endif
    stack[-1] = v0292;
    if (v0292 == nil) goto v0319;
    stack[0] = stack[-1];
    v0293 = stack[-1];
    v0292 = elt(env, 19); /* simpiden */
    if (v0293 == v0292) goto v0320;
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 62); /* full */
#ifdef RECORD_GET
             if (v0292 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v0292 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v0292 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; else v0292 = lisp_true; }}
#endif
    goto v0321;

v0321:
    if (v0292 == nil) goto v0322;
    v0292 = stack[-5];
    fn = elt(env, 35); /* argnochk */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0323;

v0323:
    v0293 = Lapply1(nil, stack[0], v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0322:
    v0292 = stack[-5];
    fn = elt(env, 35); /* argnochk */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = qcdr(v0292);
    goto v0323;

v0320:
    v0292 = qvalue(elt(env, 12)); /* t */
    goto v0321;

v0319:
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 2); /* rtype */
#ifdef RECORD_GET
             if (v0292 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0292 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; }}
#endif
    stack[-1] = v0292;
    if (v0292 == nil) goto v0324;
    v0293 = stack[-1];
    v0292 = elt(env, 20); /* getelemfn */
    v0292 = get(v0293, v0292);
    env = stack[-7];
    stack[-1] = v0292;
    if (v0292 == nil) goto v0324;
    v0293 = stack[-1];
    v0292 = stack[-5];
    v0292 = Lapply1(nil, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0293 = CC_simp(env, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0324:
    v0292 = stack[-5];
    v0293 = qcar(v0292);
    v0292 = elt(env, 21); /* boolean */
    v0292 = Lflagp(nil, v0293, v0292);
    env = stack[-7];
    if (v0292 == nil) goto v0325;
    v0292 = qvalue(elt(env, 12)); /* t */
    goto v0326;

v0326:
    if (v0292 == nil) goto v0327;
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 37); /* prtch */
#ifdef RECORD_GET
             if (v0292 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0292 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; }}
#endif
    stack[-1] = v0292;
    if (v0292 == nil) goto v0328;
    v0292 = stack[-1];
    v0293 = v0292;
    goto v0329;

v0329:
    v0292 = elt(env, 22); /* "algebraic operator" */
    fn = elt(env, 30); /* typerr */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0303;

v0328:
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    v0293 = v0292;
    goto v0329;

v0327:
    v0292 = stack[-5];
    v0293 = qcar(v0292);
    v0292 = elt(env, 23); /* nochange */
    v0292 = Lflagp(nil, v0293, v0292);
    env = stack[-7];
    if (v0292 == nil) goto v0330;
    v0292 = stack[-5];
    fn = elt(env, 41); /* lispeval */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0293 = CC_simp(env, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0330:
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 45); /* psopfn */
#ifdef RECORD_GET
             if (v0292 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0292 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; }}
#endif
    if (!(v0292 == nil)) goto v0331;
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 19); /* rtypefn */
#ifdef RECORD_GET
             if (v0292 != SPID_NOPROP)
                record_get(elt(fastget_names, 19), 1);
             else record_get(elt(fastget_names, 19), 0),
                v0292 = nil; }
           else record_get(elt(fastget_names, 19), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; }}
#endif
    if (!(v0292 == nil)) goto v0331;
    v0292 = stack[-5];
    v0293 = qcar(v0292);
    v0292 = elt(env, 14); /* "operator" */
    fn = elt(env, 42); /* redmsg */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    fn = elt(env, 43); /* mkop */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0293 = stack[-5];
    v0292 = qvalue(elt(env, 1)); /* varstack!* */
    v0292 = Ldelete(nil, v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    qvalue(elt(env, 1)) = v0292; /* varstack!* */
    v0292 = stack[-5];
    v0293 = CC_simp(env, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0331:
    v0293 = stack[-5];
    v0292 = elt(env, 18); /* "scalar" */
    fn = elt(env, 30); /* typerr */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0303;

v0325:
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    if (!symbolp(v0292)) v0292 = nil;
    else { v0292 = qfastgets(v0292);
           if (v0292 != nil) { v0292 = elt(v0292, 23); /* infix */
#ifdef RECORD_GET
             if (v0292 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0292 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0292 == SPID_NOPROP) v0292 = nil; }}
#endif
    goto v0326;

v0317:
    v0292 = qvalue(elt(env, 2)); /* nil */
    goto v0318;

v0126:
    v0292 = stack[-5];
    v0292 = qcar(v0292);
    v0292 = (v0292 == nil ? lisp_true : nil);
    goto v0038;

v0299:
    v0292 = stack[-5];
    fn = elt(env, 44); /* simpatom */
    v0293 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    v0292 = stack[-5];
    fn = elt(env, 25); /* !*ssave */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0026:
    v0293 = stack[-5];
    v0292 = elt(env, 8); /* !*sq */
    if (!consp(v0293)) goto v0332;
    v0293 = qcar(v0293);
    if (!(v0293 == v0292)) goto v0332;
    v0292 = stack[-5];
    v0292 = qcdr(v0292);
    v0292 = qcdr(v0292);
    v0292 = qcar(v0292);
    if (v0292 == nil) goto v0165;
    v0292 = qvalue(elt(env, 9)); /* !*resimp */
    v0292 = (v0292 == nil ? lisp_true : nil);
    goto v0016;

v0016:
    if (v0292 == nil) goto v0002;
    v0292 = stack[-5];
    v0292 = qcdr(v0292);
    v0292 = qcar(v0292);
    goto v0081;

v0002:
    v0292 = qvalue(elt(env, 10)); /* !*uncached */
    if (v0292 == nil) goto v0333;
    v0292 = qvalue(elt(env, 2)); /* nil */
    goto v0334;

v0334:
    if (v0292 == nil) goto v0298;
    v0292 = stack[-1];
    v0292 = qcar(v0292);
    if (v0292 == nil) goto v0132;
    v0292 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 13)) = v0292; /* !*sub2 */
    goto v0132;

v0132:
    v0292 = stack[-1];
    v0292 = qcdr(v0292);
    goto v0081;

v0333:
    v0292 = qvalue(elt(env, 11)); /* alglist!* */
    v0292 = qcar(v0292);
    v0293 = v0292;
    if (v0293 == nil) goto v0069;
    v0293 = stack[-5];
    fn = elt(env, 45); /* gethash */
    v0292 = (*qfn2(fn))(qenv(fn), v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0335;

v0335:
    stack[-1] = v0292;
    goto v0334;

v0069:
    v0292 = qvalue(elt(env, 2)); /* nil */
    goto v0335;

v0165:
    v0292 = qvalue(elt(env, 2)); /* nil */
    goto v0016;

v0332:
    v0292 = qvalue(elt(env, 2)); /* nil */
    goto v0016;

v0055:
    v0293 = qvalue(elt(env, 2)); /* nil */
    v0292 = (Lisp_Object)17; /* 1 */
    v0292 = cons(v0293, v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0081;

v0295:
    v0293 = stack[-5];
    v0292 = qvalue(elt(env, 1)); /* varstack!* */
    v0292 = Lmember(nil, v0293, v0292);
    if (v0292 == nil) goto v0296;
    v0292 = stack[-5];
    fn = elt(env, 46); /* recursiveerror */
    v0292 = (*qfn1(fn))(qenv(fn), v0292);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-7];
    goto v0296;
/* error exit handlers */
v0297:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    popv(8);
    return nil;
}



/* Code for ident */

static Lisp_Object CC_ident(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0048;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ident");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0048 = v0000;
/* end of prologue */
    return onevalue(v0048);
}



/* Code for lpri */

static Lisp_Object CC_lpri(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lpri");
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

v0050:
    v0014 = stack[0];
    if (v0014 == nil) goto v0081;
    v0014 = stack[0];
    v0014 = qcar(v0014);
    v0014 = Lprinc(nil, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-1];
    v0014 = elt(env, 2); /* " " */
    v0014 = Lprinc(nil, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-1];
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    stack[0] = v0014;
    goto v0050;

v0081:
    v0014 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0014); }
/* error exit handlers */
v0143:
    popv(2);
    return nil;
}



/* Code for errorset2 */

static Lisp_Object CC_errorset2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0199, v0014, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for errorset2");
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
    v0014 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*protfg */
    qvalue(elt(env, 1)) = nil; /* !*protfg */
    v0199 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0199; /* !*protfg */
    v0015 = v0014;
    v0014 = qvalue(elt(env, 3)); /* nil */
    v0199 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 4); /* errorset */
    v0199 = (*qfnn(fn))(qenv(fn), 3, v0015, v0014, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    { popv(2); return onevalue(v0199); }
/* error exit handlers */
v0074:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    popv(2);
    return nil;
}



/* Code for red_divtestbe */

static Lisp_Object MS_CDECL CC_red_divtestbe(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0150, v0012;
    Lisp_Object fn;
    Lisp_Object v0153, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "red_divtestbe");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0153 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_divtestbe");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0153,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0153);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0153;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0024:
    v0150 = stack[-2];
    if (v0150 == nil) goto v0008;
    v0150 = stack[-2];
    v0150 = qcar(v0150);
    fn = elt(env, 2); /* bas_dpecart */
    v0012 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-3];
    v0150 = stack[0];
    v0150 = (Lisp_Object)lesseq2(v0012, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    v0150 = v0150 ? lisp_true : nil;
    env = stack[-3];
    if (v0150 == nil) goto v0060;
    v0150 = stack[-2];
    v0150 = qcar(v0150);
    fn = elt(env, 3); /* bas_dpoly */
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-3];
    fn = elt(env, 4); /* dp_lmon */
    v0012 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-3];
    v0150 = stack[-1];
    fn = elt(env, 5); /* mo_vdivides!? */
    v0150 = (*qfn2(fn))(qenv(fn), v0012, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-3];
    if (v0150 == nil) goto v0060;
    v0150 = stack[-2];
    v0150 = qcar(v0150);
    { popv(4); return onevalue(v0150); }

v0060:
    v0150 = stack[-2];
    v0150 = qcdr(v0150);
    stack[-2] = v0150;
    goto v0024;

v0008:
    v0150 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0150); }
/* error exit handlers */
v0295:
    popv(4);
    return nil;
}



/* Code for b!:extmult */

static Lisp_Object CC_bTextmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0340, v0341;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for b:extmult");
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
    v0340 = stack[-3];
    if (v0340 == nil) goto v0008;
    v0340 = stack[-2];
    v0340 = (v0340 == nil ? lisp_true : nil);
    goto v0068;

v0068:
    if (v0340 == nil) goto v0143;
    v0340 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0340); }

v0143:
    v0341 = stack[-2];
    v0340 = (Lisp_Object)17; /* 1 */
    if (v0341 == v0340) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0340 = stack[-3];
    v0340 = qcar(v0340);
    v0340 = qcar(v0340);
    v0341 = qcar(v0340);
    v0340 = stack[-2];
    v0340 = qcar(v0340);
    v0340 = qcar(v0340);
    fn = elt(env, 3); /* b!:ordexn */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0341 = v0340;
    v0340 = v0341;
    if (v0340 == nil) goto v0334;
    v0340 = v0341;
    stack[-4] = qcdr(v0340);
    v0340 = v0341;
    v0340 = qcar(v0340);
    if (v0340 == nil) goto v0145;
    v0340 = stack[-3];
    v0340 = qcar(v0340);
    v0341 = qcdr(v0340);
    v0340 = stack[-2];
    v0340 = qcar(v0340);
    v0340 = qcdr(v0340);
    fn = elt(env, 4); /* multf */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    fn = elt(env, 5); /* negf */
    v0340 = (*qfn1(fn))(qenv(fn), v0340);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[-1] = v0340;
    goto v0342;

v0342:
    v0340 = stack[-3];
    v0340 = qcar(v0340);
    v0341 = ncons(v0340);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0340 = stack[-2];
    v0340 = qcdr(v0340);
    stack[0] = CC_bTextmult(env, v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0340 = stack[-3];
    v0341 = qcdr(v0340);
    v0340 = stack[-2];
    v0340 = CC_bTextmult(env, v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    fn = elt(env, 6); /* b!:extadd */
    v0340 = (*qfn2(fn))(qenv(fn), stack[0], v0340);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    {
        Lisp_Object v0132 = stack[-4];
        Lisp_Object v0129 = stack[-1];
        popv(6);
        return acons(v0132, v0129, v0340);
    }

v0145:
    v0340 = stack[-3];
    v0340 = qcar(v0340);
    v0341 = qcdr(v0340);
    v0340 = stack[-2];
    v0340 = qcar(v0340);
    v0340 = qcdr(v0340);
    fn = elt(env, 4); /* multf */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[-1] = v0340;
    goto v0342;

v0334:
    v0340 = stack[-3];
    v0341 = qcdr(v0340);
    v0340 = stack[-2];
    stack[0] = CC_bTextmult(env, v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0340 = stack[-3];
    v0340 = qcar(v0340);
    v0341 = ncons(v0340);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0340 = stack[-2];
    v0340 = qcdr(v0340);
    v0340 = CC_bTextmult(env, v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    {
        Lisp_Object v0130 = stack[0];
        popv(6);
        fn = elt(env, 6); /* b!:extadd */
        return (*qfn2(fn))(qenv(fn), v0130, v0340);
    }

v0008:
    v0340 = qvalue(elt(env, 1)); /* t */
    goto v0068;
/* error exit handlers */
v0131:
    popv(6);
    return nil;
}



/* Code for rrdls */

static Lisp_Object MS_CDECL CC_rrdls(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0345, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rrdls");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rrdls");
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
    stack[0] = nil;
    goto v0024;

v0024:
    fn = elt(env, 9); /* rread1 */
    v0018 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0346;
    env = stack[-2];
    stack[-1] = v0018;
    v0345 = qvalue(elt(env, 1)); /* ttype!* */
    v0018 = (Lisp_Object)49; /* 3 */
    if (!(v0345 == v0018)) goto v0289;
    v0345 = stack[-1];
    v0018 = elt(env, 2); /* !) */
    if (v0345 == v0018) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0345 = stack[-1];
    v0018 = elt(env, 3); /* !. */
    if (!(v0345 == v0018)) goto v0289;
    fn = elt(env, 9); /* rread1 */
    v0018 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0346;
    env = stack[-2];
    stack[-1] = v0018;
    fn = elt(env, 10); /* ptoken */
    v0018 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0346;
    env = stack[-2];
    v0026 = v0018;
    v0345 = qvalue(elt(env, 1)); /* ttype!* */
    v0018 = (Lisp_Object)49; /* 3 */
    if (v0345 == v0018) goto v0057;
    v0018 = qvalue(elt(env, 4)); /* t */
    goto v0013;

v0013:
    if (v0018 == nil) goto v0147;
    v0018 = elt(env, 5); /* " " */
    qvalue(elt(env, 6)) = v0018; /* nxtsym!* */
    v0345 = elt(env, 7); /* "Invalid S-expression" */
    v0018 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 11); /* symerr */
    v0018 = (*qfn2(fn))(qenv(fn), v0345, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0346;
    env = stack[-2];
    goto v0289;

v0289:
    v0018 = stack[-1];
    v0018 = ncons(v0018);
    nil = C_nil;
    if (exception_pending()) goto v0346;
    env = stack[-2];
    v0018 = Lnconc(nil, stack[0], v0018);
    nil = C_nil;
    if (exception_pending()) goto v0346;
    env = stack[-2];
    stack[0] = v0018;
    goto v0024;

v0147:
    v0345 = stack[0];
    v0018 = stack[-1];
        popv(3);
        return Lnconc(nil, v0345, v0018);

v0057:
    v0345 = v0026;
    v0018 = elt(env, 2); /* !) */
    v0018 = (v0345 == v0018 ? lisp_true : nil);
    v0018 = (v0018 == nil ? lisp_true : nil);
    goto v0013;
/* error exit handlers */
v0346:
    popv(3);
    return nil;
}



/* Code for procstat */

static Lisp_Object MS_CDECL CC_procstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "procstat");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for procstat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0048 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* procstat1 */
        return (*qfn1(fn))(qenv(fn), v0048);
    }
}



/* Code for totalcompare */

static Lisp_Object CC_totalcompare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0288, v0289;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for totalcompare");
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

v0081:
    v0288 = stack[-1];
    v0054 = stack[0];
    if (equal(v0288, v0054)) goto v0049;
    v0288 = stack[-1];
    v0054 = stack[0];
    fn = elt(env, 4); /* wulessp */
    v0054 = (*qfn2(fn))(qenv(fn), v0288, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    if (v0054 == nil) goto v0020;
    v0054 = elt(env, 2); /* less */
    { popv(3); return onevalue(v0054); }

v0020:
    v0288 = stack[0];
    v0054 = stack[-1];
    fn = elt(env, 4); /* wulessp */
    v0054 = (*qfn2(fn))(qenv(fn), v0288, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    if (v0054 == nil) goto v0010;
    v0054 = elt(env, 3); /* greater */
    { popv(3); return onevalue(v0054); }

v0010:
    v0054 = stack[-1];
    fn = elt(env, 5); /* wuconstantp */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    if (v0054 == nil) goto v0186;
    v0288 = stack[-1];
    v0054 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* totalcompareconstants */
        return (*qfn2(fn))(qenv(fn), v0288, v0054);
    }

v0186:
    v0054 = stack[-1];
    v0054 = qcar(v0054);
    v0288 = qcdr(v0054);
    v0054 = stack[0];
    v0054 = qcar(v0054);
    v0054 = qcdr(v0054);
    v0054 = CC_totalcompare(env, v0288, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    v0289 = v0054;
    v0288 = v0289;
    v0054 = elt(env, 1); /* equal */
    if (!(v0288 == v0054)) { popv(3); return onevalue(v0289); }
    v0054 = stack[-1];
    v0288 = qcdr(v0054);
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[-1] = v0288;
    stack[0] = v0054;
    goto v0081;

v0049:
    v0054 = elt(env, 1); /* equal */
    { popv(3); return onevalue(v0054); }
/* error exit handlers */
v0003:
    popv(3);
    return nil;
}



/* Code for exceeds!-order */

static Lisp_Object CC_exceedsKorder(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0350, v0344;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exceeds-order");
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

v0351:
    v0350 = stack[-1];
    if (v0350 == nil) goto v0049;
    v0350 = stack[0];
    v0350 = qcar(v0350);
    stack[-2] = v0350;
    v0350 = (Lisp_Object)1; /* 0 */
    v0344 = v0350;
    goto v0073;

v0073:
    v0350 = stack[-2];
    if (v0350 == nil) goto v0066;
    v0350 = stack[-2];
    v0350 = qcar(v0350);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v0350 = (*qfn2(fn))(qenv(fn), v0350, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-3];
    v0344 = v0350;
    v0350 = stack[-2];
    v0350 = qcdr(v0350);
    stack[-2] = v0350;
    goto v0073;

v0066:
    v0350 = v0344;
    v0344 = v0350;
    v0350 = stack[-1];
    v0350 = qcar(v0350);
    fn = elt(env, 4); /* tayexp!-lessp */
    v0350 = (*qfn2(fn))(qenv(fn), v0344, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-3];
    if (v0350 == nil) goto v0075;
    v0350 = stack[-1];
    v0344 = qcdr(v0350);
    v0350 = stack[0];
    v0350 = qcdr(v0350);
    stack[-1] = v0344;
    stack[0] = v0350;
    goto v0351;

v0075:
    v0350 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v0350); }

v0049:
    v0350 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0350); }
/* error exit handlers */
v0298:
    popv(4);
    return nil;
}



/* Code for rl_external */

static Lisp_Object CC_rl_external(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0020, v0172;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_external");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0020 = v0001;
    v0021 = v0000;
/* end of prologue */
    if (!symbolp(v0021)) v0021 = nil;
    else { v0021 = qfastgets(v0021);
           if (v0021 != nil) { v0021 = elt(v0021, 21); /* rl_external */
#ifdef RECORD_GET
             if (v0021 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v0021 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v0021 == SPID_NOPROP) v0021 = nil; }}
#endif
    v0172 = v0021;
    v0021 = v0172;
    if (v0021 == nil) goto v0008;
    v0021 = v0020;
    v0020 = v0172;
    v0021 = Latsoc(nil, v0021, v0020);
    v0172 = v0021;
    v0021 = v0172;
    if (v0021 == nil) goto v0008;
    v0021 = v0172;
    v0021 = qcdr(v0021);
    return onevalue(v0021);

v0008:
    v0021 = nil;
    return onevalue(v0021);
}



/* Code for searchtm */

static Lisp_Object CC_searchtm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for searchtm");
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
    v0077 = v0000;
/* end of prologue */
    v0011 = v0077;
    if (!consp(v0011)) goto v0068;
    v0011 = v0077;
    v0011 = qcar(v0011);
    v0011 = (consp(v0011) ? nil : lisp_true);
    goto v0081;

v0081:
    if (v0011 == nil) goto v0074;
    v0011 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0011); }

v0074:
    v0011 = v0077;
    v0011 = qcar(v0011);
    stack[0] = qcar(v0011);
    v0011 = v0077;
    v0011 = qcdr(v0011);
    fn = elt(env, 3); /* searchpl */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    {
        Lisp_Object v0200 = stack[0];
        popv(1);
        return cons(v0200, v0011);
    }

v0068:
    v0011 = qvalue(elt(env, 1)); /* t */
    goto v0081;
/* error exit handlers */
v0078:
    popv(1);
    return nil;
}



/* Code for ibalp_simpat */

static Lisp_Object CC_ibalp_simpat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_simpat");
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
    v0074 = stack[-1];
    stack[-2] = qcar(v0074);
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    v0074 = qcar(v0074);
    fn = elt(env, 1); /* ibalp_simpterm */
    stack[0] = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-3];
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    v0074 = qcdr(v0074);
    v0074 = qcar(v0074);
    fn = elt(env, 1); /* ibalp_simpterm */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-3];
    {
        Lisp_Object v0055 = stack[-2];
        Lisp_Object v0010 = stack[0];
        popv(4);
        fn = elt(env, 2); /* ibalp_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0055, v0010, v0074);
    }
/* error exit handlers */
v0073:
    popv(4);
    return nil;
}



/* Code for aex_simpleratp */

static Lisp_Object CC_aex_simpleratp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_simpleratp");
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
    v0049 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_ratp */
        return (*qfn1(fn))(qenv(fn), v0049);
    }
/* error exit handlers */
v0024:
    popv(1);
    return nil;
}



/* Code for rnconc */

static Lisp_Object CC_rnconc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0186, v0352;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnconc");
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
    v0186 = stack[-1];
    if (v0186 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0186 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v0186 == nil) goto v0021;
    v0186 = stack[-1];
    fn = elt(env, 3); /* noncomfp1 */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    if (v0186 == nil) goto v0021;
    v0186 = stack[0];
    fn = elt(env, 3); /* noncomfp1 */
    v0186 = (*qfn1(fn))(qenv(fn), v0186);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    if (v0186 == nil) goto v0021;
    v0352 = stack[-1];
    v0186 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v0352, v0186);
    }

v0021:
    v0186 = stack[-1];
    v0352 = v0186;
    goto v0200;

v0200:
    v0186 = v0352;
    v0186 = qcdr(v0186);
    if (v0186 == nil) goto v0295;
    v0186 = v0352;
    v0186 = qcdr(v0186);
    v0352 = v0186;
    goto v0200;

v0295:
    v0186 = stack[0];
    v0186 = Lrplacd(nil, v0352, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0057:
    popv(3);
    return nil;
}



/* Code for scan */

static Lisp_Object MS_CDECL CC_scan(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0215, v0326, v0393;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "scan");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for scan");
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
    push3(nil, nil, nil);
/* end of prologue */
    v0326 = qvalue(elt(env, 1)); /* cursym!* */
    v0215 = elt(env, 2); /* !*semicol!* */
    if (!(v0326 == v0215)) goto v0081;

v0024:
    fn = elt(env, 33); /* token */
    v0215 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0215; /* nxtsym!* */
    goto v0081;

v0081:
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!consp(v0215)) goto v0065;
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    fn = elt(env, 34); /* toknump */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    v0215 = (v0215 == nil ? lisp_true : nil);
    goto v0200;

v0200:
    if (v0215 == nil) goto v0187;
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0326 = qcar(v0215);
    v0215 = elt(env, 31); /* string */
    if (!(v0326 == v0215)) goto v0199;
    v0215 = elt(env, 32); /* " " */
    fn = elt(env, 35); /* prin2x */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = qcdr(v0215);
    v0215 = qcar(v0215);
    v0215 = Lmkquote(nil, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0215; /* nxtsym!* */
    v0215 = qcdr(v0215);
    v0215 = qcar(v0215);
    fn = elt(env, 35); /* prin2x */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    goto v0199;

v0199:
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    qvalue(elt(env, 1)) = v0215; /* cursym!* */
    fn = elt(env, 33); /* token */
    v0215 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0215; /* nxtsym!* */
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = qvalue(elt(env, 21)); /* !$eof!$ */
    if (v0326 == v0215) goto v0225;
    v0215 = qvalue(elt(env, 4)); /* nil */
    goto v0395;

v0395:
    if (v0215 == nil) goto v0014;
    {
        popv(4);
        fn = elt(env, 36); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0014:
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (is_number(v0215)) goto v0222;
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!consp(v0215)) goto v0396;
    v0215 = qvalue(elt(env, 4)); /* nil */
    goto v0397;

v0397:
    if (!(v0215 == nil)) goto v0222;

v0398:
    v0215 = qvalue(elt(env, 1)); /* cursym!* */
    {
        popv(4);
        fn = elt(env, 37); /* addcomment */
        return (*qfn1(fn))(qenv(fn), v0215);
    }

v0222:
    v0215 = elt(env, 32); /* " " */
    fn = elt(env, 35); /* prin2x */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    goto v0398;

v0396:
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!symbolp(v0215)) v0215 = nil;
    else { v0215 = qfastgets(v0215);
           if (v0215 != nil) { v0215 = elt(v0215, 11); /* switch!* */
#ifdef RECORD_GET
             if (v0215 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0215 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0215 == SPID_NOPROP) v0215 = nil; }}
#endif
    v0215 = (v0215 == nil ? lisp_true : nil);
    goto v0397;

v0225:
    v0326 = qvalue(elt(env, 11)); /* ttype!* */
    v0215 = (Lisp_Object)49; /* 3 */
    v0215 = (v0326 == v0215 ? lisp_true : nil);
    goto v0395;

v0187:
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 5); /* else */
    if (v0326 == v0215) goto v0058;
    v0326 = qvalue(elt(env, 1)); /* cursym!* */
    v0215 = elt(env, 2); /* !*semicol!* */
    v0215 = (v0326 == v0215 ? lisp_true : nil);
    goto v0295;

v0295:
    if (v0215 == nil) goto v0011;
    v0215 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 7)) = v0215; /* outl!* */
    goto v0011;

v0011:
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    fn = elt(env, 35); /* prin2x */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    goto v0068;

v0068:
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!(symbolp(v0215))) goto v0199;
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!symbolp(v0215)) v0215 = nil;
    else { v0215 = qfastgets(v0215);
           if (v0215 != nil) { v0215 = elt(v0215, 28); /* newnam */
#ifdef RECORD_GET
             if (v0215 != SPID_NOPROP)
                record_get(elt(fastget_names, 28), 1);
             else record_get(elt(fastget_names, 28), 0),
                v0215 = nil; }
           else record_get(elt(fastget_names, 28), 0); }
#else
             if (v0215 == SPID_NOPROP) v0215 = nil; }}
#endif
    stack[-1] = v0215;
    if (v0215 == nil) goto v0003;
    v0326 = stack[-1];
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (equal(v0326, v0215)) goto v0003;
    v0215 = stack[-1];
    qvalue(elt(env, 3)) = v0215; /* nxtsym!* */
    v0215 = stack[-1];
    v0215 = Lstringp(nil, v0215);
    env = stack[-3];
    if (!(v0215 == nil)) goto v0199;
    v0215 = stack[-1];
    if (!consp(v0215)) goto v0068;
    else goto v0199;

v0003:
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 8); /* comment */
    if (v0326 == v0215) goto v0004;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 10); /* !% */
    if (v0326 == v0215) goto v0137;
    v0215 = qvalue(elt(env, 4)); /* nil */
    goto v0140;

v0140:
    if (v0215 == nil) goto v0340;
    v0215 = elt(env, 12); /* percent_comment */
    fn = elt(env, 38); /* read!-comment1 */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    stack[-1] = v0215;
    v0215 = qvalue(elt(env, 9)); /* !*comment */
    if (v0215 == nil) goto v0024;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0340:
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 13); /* !#if */
    if (v0326 == v0215) goto v0251;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 14); /* !#else */
    if (v0326 == v0215) goto v0399;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 15); /* !#elif */
    v0215 = (v0326 == v0215 ? lisp_true : nil);
    goto v0130;

v0130:
    if (v0215 == nil) goto v0281;
    v0215 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = v0215;
    qvalue(elt(env, 3)) = v0215; /* nxtsym!* */
    goto v0311;

v0311:
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 16); /* !#endif */
    if (v0326 == v0215) goto v0248;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 13); /* !#if */
    if (v0326 == v0215) goto v0246;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 14); /* !#else */
    if (v0326 == v0215) goto v0400;
    v0215 = qvalue(elt(env, 4)); /* nil */
    goto v0401;

v0401:
    if (!(v0215 == nil)) goto v0024;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 15); /* !#elif */
    if (v0326 == v0215) goto v0402;
    v0215 = qvalue(elt(env, 4)); /* nil */
    goto v0403;

v0403:
    if (!(v0215 == nil)) goto v0251;

v0404:
    fn = elt(env, 33); /* token */
    v0215 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0215; /* nxtsym!* */
    v0326 = qvalue(elt(env, 11)); /* ttype!* */
    v0215 = (Lisp_Object)49; /* 3 */
    if (v0326 == v0215) goto v0405;
    v0215 = qvalue(elt(env, 4)); /* nil */
    goto v0406;

v0406:
    if (v0215 == nil) goto v0311;
    {
        popv(4);
        fn = elt(env, 36); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0405:
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = qvalue(elt(env, 21)); /* !$eof!$ */
    v0215 = (v0326 == v0215 ? lisp_true : nil);
    goto v0406;

v0251:
    fn = elt(env, 39); /* rread */
    v0393 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    v0326 = qvalue(elt(env, 18)); /* !*backtrace */
    v0215 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 40); /* errorset */
    v0215 = (*qfnn(fn))(qenv(fn), 3, v0393, v0326, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    stack[-1] = v0215;
    v0215 = stack[-1];
    fn = elt(env, 41); /* errorp */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    if (v0215 == nil) goto v0252;
    v0215 = qvalue(elt(env, 4)); /* nil */
    goto v0254;

v0254:
    if (!(v0215 == nil)) goto v0024;
    v0215 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = v0215;
    goto v0311;

v0252:
    v0215 = stack[-1];
    v0215 = qcar(v0215);
    goto v0254;

v0402:
    v0215 = stack[-1];
    v0215 = (v0215 == nil ? lisp_true : nil);
    goto v0403;

v0400:
    v0215 = stack[-1];
    v0215 = (v0215 == nil ? lisp_true : nil);
    goto v0401;

v0246:
    v0326 = qvalue(elt(env, 4)); /* nil */
    v0215 = stack[-1];
    v0215 = cons(v0326, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    stack[-1] = v0215;
    goto v0404;

v0248:
    v0215 = stack[-1];
    if (v0215 == nil) goto v0024;
    v0215 = stack[-1];
    v0215 = qcdr(v0215);
    stack[-1] = v0215;
    goto v0404;

v0281:
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 16); /* !#endif */
    if (v0326 == v0215) goto v0024;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 17); /* !#eval */
    if (v0326 == v0215) goto v0407;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 19); /* !#define */
    if (v0326 == v0215) goto v0120;
    v0326 = qvalue(elt(env, 11)); /* ttype!* */
    v0215 = (Lisp_Object)49; /* 3 */
    if (!(v0326 == v0215)) goto v0199;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = qvalue(elt(env, 21)); /* !$eof!$ */
    if (v0326 == v0215) goto v0408;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = elt(env, 22); /* !' */
    if (v0326 == v0215) goto v0099;
    v0215 = qvalue(elt(env, 24)); /* !*eoldelimp */
    if (v0215 == nil) goto v0409;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = qvalue(elt(env, 25)); /* !$eol!$ */
    if (!(v0326 == v0215)) goto v0409;

v0171:
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    qvalue(elt(env, 30)) = v0215; /* semic!* */
    v0215 = elt(env, 2); /* !*semicol!* */
    {
        popv(4);
        fn = elt(env, 37); /* addcomment */
        return (*qfn1(fn))(qenv(fn), v0215);
    }

v0409:
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!symbolp(v0215)) v0215 = nil;
    else { v0215 = qfastgets(v0215);
           if (v0215 != nil) { v0215 = elt(v0215, 11); /* switch!* */
#ifdef RECORD_GET
             if (v0215 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0215 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0215 == SPID_NOPROP) v0215 = nil; }}
#endif
    stack[-1] = v0215;
    if (v0215 == nil) goto v0199;
    v0215 = stack[-1];
    v0326 = qcdr(v0215);
    v0215 = elt(env, 2); /* !*semicol!* */
    if (!consp(v0326)) goto v0339;
    v0326 = qcar(v0326);
    if (v0326 == v0215) goto v0171;
    else goto v0339;

v0339:
    v0215 = qvalue(elt(env, 26)); /* crchar!* */
    v0215 = Lwhitespace_char_p(nil, v0215);
    env = stack[-3];
    stack[-2] = v0215;
    goto v0008;

v0008:
    fn = elt(env, 33); /* token */
    v0215 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0215; /* nxtsym!* */
    v0326 = qvalue(elt(env, 11)); /* ttype!* */
    v0215 = (Lisp_Object)49; /* 3 */
    if (!(v0326 == v0215)) goto v0023;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = qvalue(elt(env, 21)); /* !$eof!$ */
    if (v0326 == v0215) goto v0307;
    v0215 = stack[-1];
    v0215 = qcar(v0215);
    if (v0215 == nil) goto v0023;
    v0215 = stack[-2];
    if (!(v0215 == nil)) goto v0023;
    v0326 = qvalue(elt(env, 3)); /* nxtsym!* */
    v0215 = stack[-1];
    v0215 = qcar(v0215);
    v0215 = Latsoc(nil, v0326, v0215);
    stack[0] = v0215;
    if (v0215 == nil) goto v0023;
    v0215 = qvalue(elt(env, 3)); /* nxtsym!* */
    fn = elt(env, 35); /* prin2x */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    v0215 = stack[0];
    v0215 = qcdr(v0215);
    stack[-1] = v0215;
    v0215 = stack[-1];
    v0215 = qcar(v0215);
    if (v0215 == nil) goto v0410;
    v0215 = qvalue(elt(env, 4)); /* nil */
    goto v0411;

v0411:
    if (v0215 == nil) goto v0008;
    fn = elt(env, 42); /* read!-comment */
    v0215 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    qvalue(elt(env, 29)) = v0215; /* comment!* */
    goto v0024;

v0410:
    v0215 = stack[-1];
    v0215 = qcdr(v0215);
    v0326 = qcar(v0215);
    v0215 = elt(env, 28); /* !*comment!* */
    v0215 = (v0326 == v0215 ? lisp_true : nil);
    goto v0411;

v0023:
    v0215 = stack[-1];
    v0215 = qcdr(v0215);
    v0215 = qcar(v0215);
    qvalue(elt(env, 1)) = v0215; /* cursym!* */
    v0326 = qvalue(elt(env, 1)); /* cursym!* */
    v0215 = elt(env, 27); /* !*rpar!* */
    if (v0326 == v0215) goto v0014;
    v0215 = qvalue(elt(env, 1)); /* cursym!* */
    {
        popv(4);
        fn = elt(env, 37); /* addcomment */
        return (*qfn1(fn))(qenv(fn), v0215);
    }

v0307:
    {
        popv(4);
        fn = elt(env, 36); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0099:
    v0215 = elt(env, 23); /* "Invalid QUOTE" */
    fn = elt(env, 43); /* rederr */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    goto v0339;

v0408:
    {
        popv(4);
        fn = elt(env, 36); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v0120:
    fn = elt(env, 39); /* rread */
    v0393 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    v0326 = qvalue(elt(env, 18)); /* !*backtrace */
    v0215 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 40); /* errorset */
    v0215 = (*qfnn(fn))(qenv(fn), 3, v0393, v0326, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    stack[-1] = v0215;
    v0215 = stack[-1];
    fn = elt(env, 41); /* errorp */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    if (!(v0215 == nil)) goto v0024;
    fn = elt(env, 39); /* rread */
    v0393 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    v0326 = qvalue(elt(env, 18)); /* !*backtrace */
    v0215 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 40); /* errorset */
    v0215 = (*qfnn(fn))(qenv(fn), 3, v0393, v0326, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    stack[0] = v0215;
    v0215 = stack[0];
    fn = elt(env, 41); /* errorp */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    if (!(v0215 == nil)) goto v0024;
    v0393 = stack[-1];
    v0326 = elt(env, 20); /* newnam */
    v0215 = stack[0];
    v0215 = Lputprop(nil, 3, v0393, v0326, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    goto v0024;

v0407:
    fn = elt(env, 39); /* rread */
    v0393 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    v0326 = qvalue(elt(env, 18)); /* !*backtrace */
    v0215 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 40); /* errorset */
    v0215 = (*qfnn(fn))(qenv(fn), 3, v0393, v0326, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    goto v0024;

v0399:
    v0215 = qvalue(elt(env, 6)); /* t */
    goto v0130;

v0137:
    v0326 = qvalue(elt(env, 11)); /* ttype!* */
    v0215 = (Lisp_Object)49; /* 3 */
    v0215 = (v0326 == v0215 ? lisp_true : nil);
    goto v0140;

v0004:
    v0215 = elt(env, 8); /* comment */
    fn = elt(env, 38); /* read!-comment1 */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0394;
    env = stack[-3];
    stack[-1] = v0215;
    v0215 = qvalue(elt(env, 9)); /* !*comment */
    if (v0215 == nil) goto v0024;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0058:
    v0215 = qvalue(elt(env, 6)); /* t */
    goto v0295;

v0065:
    v0215 = qvalue(elt(env, 4)); /* nil */
    goto v0200;
/* error exit handlers */
v0394:
    popv(4);
    return nil;
}



/* Code for getel */

static Lisp_Object CC_getel(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0186, v0352, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getel");
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
    v0186 = stack[-1];
    v0352 = qcar(v0186);
    v0186 = elt(env, 1); /* dimension */
    v0186 = get(v0352, v0186);
    env = stack[-3];
    stack[-2] = v0186;
    v0186 = stack[-2];
    stack[0] = Llength(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-3];
    v0186 = stack[-1];
    v0186 = qcdr(v0186);
    v0186 = Llength(nil, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0412;
    env = stack[-3];
    if (equal(stack[0], v0186)) goto v0060;
    v0056 = elt(env, 2); /* rlisp */
    v0352 = (Lisp_Object)337; /* 21 */
    v0186 = elt(env, 3); /* "Incorrect array reference" */
    {
        popv(4);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0056, v0352, v0186);
    }

v0060:
    v0186 = stack[-1];
    v0186 = qcar(v0186);
    if (!symbolp(v0186)) v0186 = nil;
    else { v0186 = qfastgets(v0186);
           if (v0186 != nil) { v0186 = elt(v0186, 4); /* avalue */
#ifdef RECORD_GET
             if (v0186 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0186 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0186 == SPID_NOPROP) v0186 = nil; }}
#endif
    v0186 = qcdr(v0186);
    v0056 = qcar(v0186);
    v0186 = stack[-1];
    v0352 = qcdr(v0186);
    v0186 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* getel1 */
        return (*qfnn(fn))(qenv(fn), 3, v0056, v0352, v0186);
    }
/* error exit handlers */
v0412:
    popv(4);
    return nil;
}



/* Code for red!-weight!-less!-p */

static Lisp_Object CC_redKweightKlessKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0059, v0060, v0151;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-weight-less-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0059 = v0001;
    v0060 = v0000;
/* end of prologue */
    v0080 = v0060;
    v0151 = qcar(v0080);
    v0080 = v0059;
    v0080 = qcar(v0080);
    if (equal(v0151, v0080)) goto v0199;
    v0080 = v0060;
    v0080 = qcar(v0080);
    v0059 = qcar(v0059);
        return Llessp(nil, v0080, v0059);

v0199:
    v0080 = v0060;
    v0080 = qcdr(v0080);
    v0059 = qcdr(v0059);
        return Llessp(nil, v0080, v0059);
}



/* Code for multop */

static Lisp_Object CC_multop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0013, v0348;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multop");
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
    stack[0] = v0001;
    v0348 = v0000;
/* end of prologue */
    v0012 = qvalue(elt(env, 1)); /* kord!* */
    if (v0012 == nil) goto v0079;
    v0012 = v0348;
    v0013 = qcar(v0012);
    v0012 = elt(env, 2); /* k!* */
    if (v0013 == v0012) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0013 = v0348;
    v0012 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* rmultpf */
        return (*qfn2(fn))(qenv(fn), v0013, v0012);
    }

v0079:
    v0013 = v0348;
    v0012 = (Lisp_Object)17; /* 1 */
    v0012 = cons(v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-1];
    v0013 = ncons(v0012);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-1];
    v0012 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* multf */
        return (*qfn2(fn))(qenv(fn), v0013, v0012);
    }
/* error exit handlers */
v0295:
    popv(2);
    return nil;
}



/* Code for mo!=deglist */

static Lisp_Object CC_moMdeglist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0284, v0335;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=deglist");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0000;
/* end of prologue */
    v0284 = stack[-4];
    if (v0284 == nil) goto v0050;
    v0284 = stack[-4];
    v0335 = qcar(v0284);
    v0284 = qvalue(elt(env, 3)); /* cali!=degrees */
    v0284 = Lassoc(nil, v0335, v0284);
    stack[-5] = v0284;
    v0284 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_degrees */
    v0284 = (*qfn1(fn))(qenv(fn), v0284);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    stack[-3] = v0284;
    v0284 = stack[-3];
    if (v0284 == nil) goto v0052;
    v0284 = stack[-3];
    v0284 = qcar(v0284);
    v0335 = stack[-4];
    v0335 = qcdr(v0335);
    fn = elt(env, 5); /* mo!=sprod */
    v0284 = (*qfn2(fn))(qenv(fn), v0335, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0284 = ncons(v0284);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    stack[-1] = v0284;
    stack[-2] = v0284;
    goto v0005;

v0005:
    v0284 = stack[-3];
    v0284 = qcdr(v0284);
    stack[-3] = v0284;
    v0284 = stack[-3];
    if (v0284 == nil) goto v0345;
    stack[0] = stack[-1];
    v0284 = stack[-3];
    v0284 = qcar(v0284);
    v0335 = stack[-4];
    v0335 = qcdr(v0335);
    fn = elt(env, 5); /* mo!=sprod */
    v0284 = (*qfn2(fn))(qenv(fn), v0335, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0284 = ncons(v0284);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0284 = Lrplacd(nil, stack[0], v0284);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0284 = stack[-1];
    v0284 = qcdr(v0284);
    stack[-1] = v0284;
    goto v0005;

v0345:
    v0284 = stack[-2];
    v0335 = v0284;
    goto v0350;

v0350:
    v0284 = stack[-5];
    if (v0284 == nil) goto v0136;
    v0284 = stack[-5];
    v0284 = qcdr(v0284);
    v0284 = qcdr(v0284);
    goto v0344;

v0344:
    {
        popv(7);
        fn = elt(env, 6); /* mo!=sum */
        return (*qfn2(fn))(qenv(fn), v0335, v0284);
    }

v0136:
    v0284 = qvalue(elt(env, 2)); /* nil */
    goto v0344;

v0052:
    v0284 = qvalue(elt(env, 2)); /* nil */
    v0335 = v0284;
    goto v0350;

v0050:
    v0284 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_degrees */
    v0284 = (*qfn1(fn))(qenv(fn), v0284);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    stack[-3] = v0284;
    v0284 = stack[-3];
    if (v0284 == nil) goto v0199;
    v0284 = (Lisp_Object)1; /* 0 */
    v0284 = ncons(v0284);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    stack[-1] = v0284;
    stack[-2] = v0284;
    goto v0063;

v0063:
    v0284 = stack[-3];
    v0284 = qcdr(v0284);
    stack[-3] = v0284;
    v0284 = stack[-3];
    if (v0284 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0284 = (Lisp_Object)1; /* 0 */
    v0284 = ncons(v0284);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0284 = Lrplacd(nil, stack[0], v0284);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-6];
    v0284 = stack[-1];
    v0284 = qcdr(v0284);
    stack[-1] = v0284;
    goto v0063;

v0199:
    v0284 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0284); }
/* error exit handlers */
v0182:
    popv(7);
    return nil;
}



/* Code for arintequiv!: */

static Lisp_Object CC_arintequivT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0348, v0144;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arintequiv:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0144 = v0000;
/* end of prologue */
    v0013 = v0144;
    v0013 = qcdr(v0013);
    if (is_number(v0013)) goto v0050;
    v0013 = v0144;
    v0013 = qcdr(v0013);
    v0348 = qcar(v0013);
    v0013 = elt(env, 1); /* !:rn!: */
    if (v0348 == v0013) goto v0073;
    v0013 = qvalue(elt(env, 2)); /* nil */
    goto v0075;

v0075:
    if (v0013 == nil) goto v0065;
    v0013 = v0144;
    v0013 = qcdr(v0013);
    v0013 = qcdr(v0013);
    v0013 = qcar(v0013);
    return onevalue(v0013);

v0065:
    v0013 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0013);

v0073:
    v0013 = v0144;
    v0013 = qcdr(v0013);
    v0013 = qcdr(v0013);
    v0348 = qcdr(v0013);
    v0013 = (Lisp_Object)17; /* 1 */
    v0013 = (v0348 == v0013 ? lisp_true : nil);
    goto v0075;

v0050:
    v0013 = v0144;
    v0013 = qcdr(v0013);
    return onevalue(v0013);
}



/* Code for get_goto */

static Lisp_Object CC_get_goto(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0184, v0350, v0344;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_goto");
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
    v0184 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0350 = qvalue(elt(env, 1)); /* goto_index */
    fn = elt(env, 6); /* getv16 */
    v0184 = (*qfn2(fn))(qenv(fn), v0350, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-2];
    stack[-1] = v0184;
    goto v0011;

v0011:
    v0350 = qvalue(elt(env, 2)); /* goto_old_state */
    v0184 = stack[-1];
    fn = elt(env, 6); /* getv16 */
    v0350 = (*qfn2(fn))(qenv(fn), v0350, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-2];
    v0344 = v0350;
    v0184 = (Lisp_Object)-15; /* -1 */
    if (v0350 == v0184) goto v0291;
    v0350 = v0344;
    v0184 = stack[0];
    v0184 = (equal(v0350, v0184) ? lisp_true : nil);
    goto v0009;

v0009:
    if (v0184 == nil) goto v0015;
    v0350 = qvalue(elt(env, 5)); /* goto_new_state */
    v0184 = stack[-1];
    {
        popv(3);
        fn = elt(env, 6); /* getv16 */
        return (*qfn2(fn))(qenv(fn), v0350, v0184);
    }

v0015:
    v0184 = stack[-1];
    v0184 = add1(v0184);
    nil = C_nil;
    if (exception_pending()) goto v0392;
    env = stack[-2];
    stack[-1] = v0184;
    goto v0011;

v0291:
    v0184 = qvalue(elt(env, 3)); /* t */
    goto v0009;
/* error exit handlers */
v0392:
    popv(3);
    return nil;
}



/* Code for revv0 */

static Lisp_Object CC_revv0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0005;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revv0");
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

v0081:
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    v0005 = qcar(v0007);
    v0007 = stack[0];
    if (v0005 == v0007) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    v0007 = qcar(v0007);
    stack[-2] = v0007;
    v0007 = stack[-1];
    v0005 = qcdr(v0007);
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    v0007 = qcdr(v0007);
    v0007 = qcar(v0007);
    v0007 = Lrplaca(nil, v0005, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-3];
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    v0005 = qcdr(v0007);
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    v0007 = qcdr(v0007);
    v0007 = qcdr(v0007);
    v0007 = qcar(v0007);
    v0007 = Lrplaca(nil, v0005, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-3];
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    v0007 = qcdr(v0007);
    v0005 = qcdr(v0007);
    v0007 = stack[-2];
    v0007 = Lrplaca(nil, v0005, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-3];
    v0005 = stack[-1];
    v0007 = stack[0];
    stack[-1] = v0005;
    stack[0] = v0007;
    goto v0081;
/* error exit handlers */
v0051:
    popv(4);
    return nil;
}



/* Code for freeoflist */

static Lisp_Object CC_freeoflist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0020;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeoflist");
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

v0049:
    v0021 = stack[0];
    if (v0021 == nil) goto v0068;
    v0020 = stack[-1];
    v0021 = stack[0];
    v0021 = qcar(v0021);
    fn = elt(env, 3); /* freeof */
    v0021 = (*qfn2(fn))(qenv(fn), v0020, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-2];
    if (v0021 == nil) goto v0073;
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    stack[0] = v0021;
    goto v0049;

v0073:
    v0021 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0021); }

v0068:
    v0021 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0021); }
/* error exit handlers */
v0011:
    popv(3);
    return nil;
}



/* Code for tmsf!* */

static Lisp_Object CC_tmsfH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0291;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tmsf*");
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
    v0009 = stack[0];
    if (!(is_number(v0009))) goto v0015;
    v0009 = stack[0];
    v0009 = Ltruncate(nil, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    v0291 = Labsval(nil, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    v0009 = (Lisp_Object)17; /* 1 */
    if (!(v0291 == v0009)) goto v0015;
    v0009 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0009); }

v0015:
    v0009 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* tmsf */
        return (*qfn1(fn))(qenv(fn), v0009);
    }
/* error exit handlers */
v0055:
    popv(2);
    return nil;
}



/* Code for aex_idl */

static Lisp_Object CC_aex_idl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_idl");
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
    v0049 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_idl */
        return (*qfn1(fn))(qenv(fn), v0049);
    }
/* error exit handlers */
v0024:
    popv(1);
    return nil;
}



/* Code for listsum */

static Lisp_Object CC_listsum(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0150;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listsum");
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
    stack[-1] = nil;
    goto v0024;

v0024:
    v0065 = stack[0];
    if (v0065 == nil) goto v0081;
    v0065 = stack[0];
    v0150 = qcar(v0065);
    v0065 = stack[-1];
    v0065 = cons(v0150, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0348;
    env = stack[-2];
    stack[-1] = v0065;
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    stack[0] = v0065;
    goto v0024;

v0081:
    v0065 = (Lisp_Object)1; /* 0 */
    v0150 = v0065;
    goto v0068;

v0068:
    v0065 = stack[-1];
    if (v0065 == nil) { popv(3); return onevalue(v0150); }
    v0065 = stack[-1];
    v0065 = qcar(v0065);
    v0065 = plus2(v0065, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0348;
    env = stack[-2];
    v0150 = v0065;
    v0065 = stack[-1];
    v0065 = qcdr(v0065);
    stack[-1] = v0065;
    goto v0068;
/* error exit handlers */
v0348:
    popv(3);
    return nil;
}



/* Code for basicom */

static Lisp_Object CC_basicom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for basicom");
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
    v0172 = stack[0];
    if (is_number(v0172)) goto v0024;
    v0172 = stack[0];
    if (!(symbolp(v0172))) goto v0049;
    v0172 = stack[0];
    fn = elt(env, 1); /* variableom */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    goto v0049;

v0049:
    v0172 = nil;
    { popv(2); return onevalue(v0172); }

v0024:
    v0172 = stack[0];
    v0172 = integerp(v0172);
    if (v0172 == nil) goto v0023;
    v0172 = stack[0];
    fn = elt(env, 2); /* integerom */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    goto v0023;

v0023:
    v0172 = stack[0];
    v0172 = Lfloatp(nil, v0172);
    env = stack[-1];
    if (v0172 == nil) goto v0049;
    v0172 = stack[0];
    fn = elt(env, 3); /* floatom */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    goto v0049;
/* error exit handlers */
v0011:
    popv(2);
    return nil;
}



/* Code for cut!:ep */

static Lisp_Object CC_cutTep(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cut:ep");
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
    v0016 = stack[-2];
    v0003 = elt(env, 1); /* !:rd!: */
    if (!consp(v0016)) goto v0010;
    v0016 = qcar(v0016);
    if (!(v0016 == v0003)) goto v0010;
    v0003 = stack[-2];
    v0003 = qcdr(v0003);
    v0003 = (consp(v0003) ? nil : lisp_true);
    v0003 = (v0003 == nil ? lisp_true : nil);
    goto v0063;

v0063:
    if (v0003 == nil) goto v0011;
    v0003 = stack[-1];
    v0003 = integerp(v0003);
    goto v0068;

v0068:
    if (v0003 == nil) goto v0288;
    v0016 = stack[-1];
    v0003 = stack[-2];
    v0003 = qcdr(v0003);
    v0003 = qcdr(v0003);
    v0016 = difference2(v0016, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-4];
    stack[-1] = v0016;
    v0003 = (Lisp_Object)1; /* 0 */
    v0003 = (Lisp_Object)lesseq2(v0016, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    v0003 = v0003 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0003 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v0003 = stack[-2];
    v0003 = qcdr(v0003);
    stack[0] = qcar(v0003);
    v0003 = stack[-1];
    v0003 = negate(v0003);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v0003);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    env = stack[-4];
    v0003 = stack[-2];
    v0003 = qcdr(v0003);
    v0016 = qcdr(v0003);
    v0003 = stack[-1];
    v0003 = plus2(v0016, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0342;
    {
        Lisp_Object v0415 = stack[-3];
        Lisp_Object v0346 = stack[0];
        popv(5);
        return list2star(v0415, v0346, v0003);
    }

v0288:
    v0003 = elt(env, 0); /* cut!:ep */
    {
        popv(5);
        fn = elt(env, 3); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v0003);
    }

v0011:
    v0003 = qvalue(elt(env, 2)); /* nil */
    goto v0068;

v0010:
    v0003 = qvalue(elt(env, 2)); /* nil */
    goto v0063;
/* error exit handlers */
v0342:
    popv(5);
    return nil;
}



/* Code for covposp */

static Lisp_Object CC_covposp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0164, v0009;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for covposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0164 = v0000;
/* end of prologue */

v0351:
    v0009 = v0164;
    if (v0009 == nil) goto v0050;
    v0009 = v0164;
    v0009 = qcar(v0009);
    if (!consp(v0009)) goto v0015;
    v0164 = qcdr(v0164);
    goto v0351;

v0015:
    v0164 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0164);

v0050:
    v0164 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0164);
}



/* Code for has_parents */

static Lisp_Object CC_has_parents(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0172, v0066, v0011;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for has_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0172 = v0000;
/* end of prologue */
    v0172 = qcdr(v0172);
    v0172 = qcar(v0172);
    v0011 = v0172;
    v0172 = v0011;
    v0066 = qcar(v0172);
    v0172 = elt(env, 1); /* !? */
    if (v0066 == v0172) goto v0010;
    v0172 = v0011;
    v0172 = qcdr(v0172);
    v0066 = elt(env, 1); /* !? */
        return Lneq(nil, v0172, v0066);

v0010:
    v0172 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0172);
}



/* Code for tokquote */

static Lisp_Object MS_CDECL CC_tokquote(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "tokquote");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tokquote");
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
    fn = elt(env, 4); /* readch1 */
    v0068 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[0];
    qvalue(elt(env, 1)) = v0068; /* crchar!* */
    fn = elt(env, 5); /* rread */
    v0068 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[0];
    v0068 = Lmkquote(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[0];
    qvalue(elt(env, 2)) = v0068; /* nxtsym!* */
    v0068 = (Lisp_Object)65; /* 4 */
    qvalue(elt(env, 3)) = v0068; /* ttype!* */
    v0068 = qvalue(elt(env, 2)); /* nxtsym!* */
    { popv(1); return onevalue(v0068); }
/* error exit handlers */
v0008:
    popv(1);
    return nil;
}



/* Code for argnochk */

static Lisp_Object CC_argnochk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0179, v0039, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for argnochk");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0000;
/* end of prologue */
    v0179 = qvalue(elt(env, 1)); /* !*argnochk */
    if (v0179 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v0179 = stack[-5];
    v0179 = qcar(v0179);
    fn = elt(env, 12); /* argsofopr */
    v0179 = (*qfn1(fn))(qenv(fn), v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    stack[-6] = v0179;
    if (v0179 == nil) goto v0399;
    stack[0] = stack[-6];
    v0179 = stack[-5];
    v0179 = qcdr(v0179);
    v0179 = Llength(nil, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    if (equal(stack[0], v0179)) goto v0186;
    v0179 = stack[-5];
    v0179 = qcar(v0179);
    if (!symbolp(v0179)) v0179 = nil;
    else { v0179 = qfastgets(v0179);
           if (v0179 != nil) { v0179 = elt(v0179, 22); /* simpfn */
#ifdef RECORD_GET
             if (v0179 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v0179 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v0179 == SPID_NOPROP) v0179 = nil; }}
#endif
    if (!(v0179 == nil)) goto v0029;
    v0179 = stack[-5];
    v0179 = qcar(v0179);
    if (!symbolp(v0179)) v0179 = nil;
    else { v0179 = qfastgets(v0179);
           if (v0179 != nil) { v0179 = elt(v0179, 45); /* psopfn */
#ifdef RECORD_GET
             if (v0179 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0179 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0179 == SPID_NOPROP) v0179 = nil; }}
#endif
    if (!(v0179 == nil)) goto v0029;
    v0179 = stack[-5];
    v0039 = qcar(v0179);
    v0179 = elt(env, 2); /* variadic */
    v0179 = Lflagp(nil, v0039, v0179);
    env = stack[-7];
    goto v0029;

v0029:
    v0179 = (v0179 == nil ? lisp_true : nil);
    goto v0074;

v0074:
    if (v0179 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v0179 = qvalue(elt(env, 4)); /* !*strict_argcount */
    if (v0179 == nil) goto v0070;
    v0179 = elt(env, 5); /* "+++++ " */
    v0179 = Lprinc(nil, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    v0179 = stack[-5];
    v0179 = Lprint(nil, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    stack[-4] = elt(env, 6); /* rlisp */
    stack[-3] = (Lisp_Object)177; /* 11 */
    v0179 = stack[-5];
    stack[-2] = qcar(v0179);
    stack[-1] = elt(env, 7); /* "called with" */
    v0179 = stack[-5];
    v0179 = qcdr(v0179);
    stack[0] = Llength(nil, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    v0179 = stack[-5];
    v0179 = qcdr(v0179);
    v0039 = Llength(nil, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    v0179 = (Lisp_Object)17; /* 1 */
    if (v0039 == v0179) goto v0141;
    v0179 = elt(env, 9); /* "arguments" */
    v0127 = v0179;
    goto v0018;

v0018:
    v0039 = elt(env, 10); /* "instead of" */
    v0179 = stack[-6];
    v0179 = list3(v0127, v0039, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    v0179 = list3star(stack[-2], stack[-1], stack[0], v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    fn = elt(env, 13); /* rerror */
    v0179 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[-3], v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    v0179 = nil;
    { popv(8); return onevalue(v0179); }

v0141:
    v0179 = elt(env, 8); /* "argument" */
    v0127 = v0179;
    goto v0018;

v0070:
    v0179 = stack[-5];
    stack[-2] = qcar(v0179);
    stack[-1] = elt(env, 7); /* "called with" */
    v0179 = stack[-5];
    v0179 = qcdr(v0179);
    stack[0] = Llength(nil, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    v0127 = elt(env, 10); /* "instead of" */
    v0039 = stack[-6];
    v0179 = elt(env, 9); /* "arguments" */
    v0179 = list3(v0127, v0039, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    v0179 = list3star(stack[-2], stack[-1], stack[0], v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    fn = elt(env, 14); /* lprim */
    v0179 = (*qfn1(fn))(qenv(fn), v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }

v0186:
    v0179 = qvalue(elt(env, 3)); /* nil */
    goto v0074;

v0399:
    v0179 = stack[-5];
    stack[-1] = qcar(v0179);
    stack[0] = elt(env, 11); /* number!-of!-args */
    v0179 = stack[-5];
    v0179 = qcdr(v0179);
    v0179 = Llength(nil, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-7];
    v0179 = Lputprop(nil, 3, stack[-1], stack[0], v0179);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
/* error exit handlers */
v0038:
    popv(8);
    return nil;
}



/* Code for mo_diff */

static Lisp_Object CC_mo_diff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_diff");
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
    v0063 = v0001;
    v0075 = v0000;
/* end of prologue */
    stack[0] = v0075;
    fn = elt(env, 1); /* mo_neg */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-1];
    {
        Lisp_Object v0079 = stack[0];
        popv(2);
        fn = elt(env, 2); /* mo_sum */
        return (*qfn2(fn))(qenv(fn), v0079, v0063);
    }
/* error exit handlers */
v0076:
    popv(2);
    return nil;
}



/* Code for tr_write */

static Lisp_Object CC_tr_write(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0010;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tr_write");
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
    v0010 = v0000;
/* end of prologue */
    v0055 = qvalue(elt(env, 1)); /* !*trsolve */
    if (v0055 == nil) goto v0049;
    v0055 = v0010;
    stack[0] = v0055;
    goto v0023;

v0023:
    v0055 = stack[0];
    if (v0055 == nil) goto v0008;
    v0055 = stack[0];
    v0055 = qcar(v0055);
    v0055 = Lprinc(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-1];
    v0055 = stack[0];
    v0055 = qcdr(v0055);
    stack[0] = v0055;
    goto v0023;

v0008:
        popv(2);
        return Lterpri(nil, 0);

v0049:
    v0055 = nil;
    { popv(2); return onevalue(v0055); }
/* error exit handlers */
v0020:
    popv(2);
    return nil;
}



/* Code for exptmod!: */

static Lisp_Object CC_exptmodT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0075, v0171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptmod:");
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
    v0075 = v0001;
    v0171 = v0000;
/* end of prologue */
    v0171 = qcdr(v0171);
    fn = elt(env, 1); /* general!-modular!-expt */
    v0075 = (*qfn2(fn))(qenv(fn), v0171, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0075);
    }
/* error exit handlers */
v0076:
    popv(1);
    return nil;
}



/* Code for mapcons */

static Lisp_Object CC_mapcons(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0027;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mapcons");
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
    stack[-3] = v0001;
    v0056 = v0000;
/* end of prologue */
    stack[-4] = v0056;
    v0056 = stack[-4];
    if (v0056 == nil) goto v0063;
    v0056 = stack[-4];
    v0056 = qcar(v0056);
    v0027 = stack[-3];
    v0056 = cons(v0027, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-5];
    v0056 = ncons(v0056);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-5];
    stack[-1] = v0056;
    stack[-2] = v0056;
    goto v0068;

v0068:
    v0056 = stack[-4];
    v0056 = qcdr(v0056);
    stack[-4] = v0056;
    v0056 = stack[-4];
    if (v0056 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0056 = stack[-4];
    v0056 = qcar(v0056);
    v0027 = stack[-3];
    v0056 = cons(v0027, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-5];
    v0056 = ncons(v0056);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-5];
    v0056 = Lrplacd(nil, stack[0], v0056);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-5];
    v0056 = stack[-1];
    v0056 = qcdr(v0056);
    stack[-1] = v0056;
    goto v0068;

v0063:
    v0056 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0056); }
/* error exit handlers */
v0344:
    popv(6);
    return nil;
}



setup_type const u09_setup[] =
{
    {"add2resultbuf",           too_few_2,      CC_add2resultbuf,wrong_no_2},
    {"pdmult",                  too_few_2,      CC_pdmult,     wrong_no_2},
    {"th_match0",               too_few_2,      CC_th_match0,  wrong_no_2},
    {"general-modular-quotient",too_few_2,      CC_generalKmodularKquotient,wrong_no_2},
    {"clear-column",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_clearKcolumn},
    {"gionep:",                 CC_gionepT,     too_many_1,    wrong_no_1},
    {"canonsq",                 CC_canonsq,     too_many_1,    wrong_no_1},
    {"rl_gettype",              CC_rl_gettype,  too_many_1,    wrong_no_1},
    {"omair",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omair},
    {"simp",                    CC_simp,        too_many_1,    wrong_no_1},
    {"ident",                   CC_ident,       too_many_1,    wrong_no_1},
    {"lpri",                    CC_lpri,        too_many_1,    wrong_no_1},
    {"errorset2",               CC_errorset2,   too_many_1,    wrong_no_1},
    {"red_divtestbe",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_divtestbe},
    {"b:extmult",               too_few_2,      CC_bTextmult,  wrong_no_2},
    {"rrdls",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_rrdls},
    {"procstat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_procstat},
    {"totalcompare",            too_few_2,      CC_totalcompare,wrong_no_2},
    {"exceeds-order",           too_few_2,      CC_exceedsKorder,wrong_no_2},
    {"rl_external",             too_few_2,      CC_rl_external,wrong_no_2},
    {"searchtm",                CC_searchtm,    too_many_1,    wrong_no_1},
    {"ibalp_simpat",            CC_ibalp_simpat,too_many_1,    wrong_no_1},
    {"aex_simpleratp",          CC_aex_simpleratp,too_many_1,  wrong_no_1},
    {"rnconc",                  too_few_2,      CC_rnconc,     wrong_no_2},
    {"scan",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_scan},
    {"getel",                   CC_getel,       too_many_1,    wrong_no_1},
    {"red-weight-less-p",       too_few_2,      CC_redKweightKlessKp,wrong_no_2},
    {"multop",                  too_few_2,      CC_multop,     wrong_no_2},
    {"mo=deglist",              CC_moMdeglist,  too_many_1,    wrong_no_1},
    {"arintequiv:",             CC_arintequivT, too_many_1,    wrong_no_1},
    {"get_goto",                too_few_2,      CC_get_goto,   wrong_no_2},
    {"revv0",                   too_few_2,      CC_revv0,      wrong_no_2},
    {"freeoflist",              too_few_2,      CC_freeoflist, wrong_no_2},
    {"tmsf*",                   CC_tmsfH,       too_many_1,    wrong_no_1},
    {"aex_idl",                 CC_aex_idl,     too_many_1,    wrong_no_1},
    {"listsum",                 CC_listsum,     too_many_1,    wrong_no_1},
    {"basicom",                 CC_basicom,     too_many_1,    wrong_no_1},
    {"cut:ep",                  too_few_2,      CC_cutTep,     wrong_no_2},
    {"covposp",                 CC_covposp,     too_many_1,    wrong_no_1},
    {"has_parents",             CC_has_parents, too_many_1,    wrong_no_1},
    {"tokquote",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_tokquote},
    {"argnochk",                CC_argnochk,    too_many_1,    wrong_no_1},
    {"mo_diff",                 too_few_2,      CC_mo_diff,    wrong_no_2},
    {"tr_write",                CC_tr_write,    too_many_1,    wrong_no_1},
    {"exptmod:",                too_few_2,      CC_exptmodT,   wrong_no_2},
    {"mapcons",                 too_few_2,      CC_mapcons,    wrong_no_2},
    {NULL, (one_args *)"u09", (two_args *)"4290 5466342 5553214", 0}
};

/* end of generated code */
