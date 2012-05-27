
/* $destdir\u09.c        Machine generated C code */

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


/* Code for covposp */

static Lisp_Object CC_covposp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for covposp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */

v3:
    v2 = v1;
    if (v2 == nil) goto v4;
    v2 = v1;
    v2 = qcar(v2);
    if (!consp(v2)) goto v5;
    v1 = qcdr(v1);
    goto v3;

v5:
    v1 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v1);

v4:
    v1 = qvalue(elt(env, 1)); /* t */
    return onevalue(v1);
}



/* Code for opnum!* */

static Lisp_Object CC_opnumH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opnum*");
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
    v16 = v0;
/* end of prologue */
    stack[-1] = nil;
    v15 = v16;
    if (symbolp(v15)) goto v18;
    stack[0] = v16;
    v15 = v16;
    fn = elt(env, 3); /* collectindices */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    fn = elt(env, 4); /* removeindices */
    v15 = (*qfn2(fn))(qenv(fn), stack[0], v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v16 = v15;
    goto v18;

v18:
    v15 = v16;
    if (symbolp(v15)) goto v2;
    v15 = v16;
    v15 = qcar(v15);
    v16 = qcdr(v16);
    stack[-1] = v16;
    goto v20;

v20:
    v16 = v15;
    v15 = elt(env, 2); /* opnum */
    v15 = get(v16, v15);
    env = stack[-2];
    v17 = v15;
    v16 = stack[-1];
    v15 = v17;
    v15 = Lassoc(nil, v16, v15);
    v16 = v15;
    if (v15 == nil) goto v21;
    v15 = v16;
    v15 = qcdr(v15);
    { popv(3); return onevalue(v15); }

v21:
    v15 = qvalue(elt(env, 1)); /* nil */
    v16 = v17;
    v15 = Lassoc(nil, v15, v16);
    v15 = qcdr(v15);
    { popv(3); return onevalue(v15); }

v2:
    v15 = v16;
    goto v20;
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for formcond */

static Lisp_Object MS_CDECL CC_formcond(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v22,
                         Lisp_Object v13, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formcond");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formcond");
#endif
    if (stack >= stacklimit)
    {
        push3(v13,v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v22,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v2 = v13;
    v27 = v22;
    v28 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* cond */
    v28 = qcdr(v28);
    fn = elt(env, 2); /* formcond1 */
    v2 = (*qfnn(fn))(qenv(fn), 3, v28, v27, v2);
    nil = C_nil;
    if (exception_pending()) goto v29;
    {
        Lisp_Object v30 = stack[0];
        popv(1);
        return cons(v30, v2);
    }
/* error exit handlers */
v29:
    popv(1);
    return nil;
}



/* Code for red!-ratios1 */

static Lisp_Object CC_redKratios1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35, v36, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-ratios1");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v22;
    stack[-1] = v0;
/* end of prologue */

v3:
    v34 = stack[-1];
    if (v34 == nil) goto v38;
    v34 = stack[-1];
    v37 = qcdr(v34);
    v34 = stack[0];
    v36 = qcdr(v34);
    v34 = stack[-1];
    v35 = qcar(v34);
    v34 = stack[0];
    v34 = qcar(v34);
    fn = elt(env, 2); /* red!-ratios2 */
    v34 = (*qfnn(fn))(qenv(fn), 4, v37, v36, v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    if (!(v34 == nil)) { popv(3); return onevalue(v34); }
    v34 = stack[-1];
    v35 = qcdr(v34);
    v34 = stack[0];
    v34 = qcdr(v34);
    stack[-1] = v35;
    stack[0] = v34;
    goto v3;

v38:
    v34 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v34); }
/* error exit handlers */
v39:
    popv(3);
    return nil;
}



/* Code for subsetp */

static Lisp_Object CC_subsetp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42, v43, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsetp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v42 = v22;
    v43 = v0;
/* end of prologue */

v3:
    v41 = v43;
    if (v41 == nil) goto v38;
    v41 = v43;
    v33 = qcar(v41);
    v41 = v42;
    v41 = Lmember(nil, v33, v41);
    if (v41 == nil) goto v44;
    v41 = v43;
    v43 = qcdr(v41);
    v41 = v42;
    v42 = v41;
    goto v3;

v44:
    v41 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v41);

v38:
    v41 = qvalue(elt(env, 1)); /* t */
    return onevalue(v41);
}



/* Code for quotk */

static Lisp_Object CC_quotk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v49, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotk");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v22;
    stack[-1] = v0;
/* end of prologue */
    v19 = stack[-1];
    v19 = qcar(v19);
    v49 = qcdr(v19);
    v19 = stack[0];
    fn = elt(env, 2); /* quotf1 */
    v19 = (*qfn2(fn))(qenv(fn), v49, v19);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-2] = v19;
    v19 = stack[-2];
    if (v19 == nil) goto v17;
    v19 = stack[-1];
    v19 = qcdr(v19);
    if (v19 == nil) goto v29;
    v19 = stack[-1];
    v49 = qcdr(v19);
    v19 = stack[0];
    fn = elt(env, 2); /* quotf1 */
    v19 = (*qfn2(fn))(qenv(fn), v49, v19);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v49 = v19;
    v19 = v49;
    if (v19 == nil) goto v52;
    v19 = stack[-1];
    v19 = qcar(v19);
    v50 = qcar(v19);
    v19 = stack[-2];
    popv(4);
    return acons(v50, v19, v49);

v52:
    v19 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v19); }

v29:
    v19 = stack[-1];
    v19 = qcar(v19);
    v49 = qcar(v19);
    v19 = stack[-2];
    v19 = cons(v49, v19);
    nil = C_nil;
    if (exception_pending()) goto v51;
    popv(4);
    return ncons(v19);

v17:
    v19 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v19); }
/* error exit handlers */
v51:
    popv(4);
    return nil;
}



/* Code for gperm2 */

static Lisp_Object MS_CDECL CC_gperm2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v22,
                         Lisp_Object v13, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v34, v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "gperm2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm2");
#endif
    if (stack >= stacklimit)
    {
        push3(v13,v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v22,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v13;
    stack[-1] = v22;
    v12 = v0;
/* end of prologue */

v53:
    v34 = v12;
    if (v34 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v34 = v12;
    v34 = qcdr(v34);
    stack[-2] = v34;
    v34 = qcar(v12);
    v12 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* rev */
    v36 = (*qfn2(fn))(qenv(fn), v34, v12);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    v35 = stack[-1];
    v34 = qvalue(elt(env, 1)); /* nil */
    v12 = stack[0];
    fn = elt(env, 3); /* gperm1 */
    v12 = (*qfnn(fn))(qenv(fn), 4, v36, v35, v34, v12);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    stack[0] = v12;
    v12 = stack[-2];
    goto v53;
/* error exit handlers */
v39:
    popv(4);
    return nil;
}



/* Code for times!-in!-vector */

static Lisp_Object MS_CDECL CC_timesKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v22,
                         Lisp_Object v13, Lisp_Object v10,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v80, v81, v82, v83, v84, v85, v86, v87, v88, v89, v90, v91, v92, v93;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "times-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for times-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push5(v4,v10,v13,v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v22,v13,v10,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v88 = v4;
    v89 = v10;
    v90 = v13;
    v91 = v22;
    v92 = v0;
/* end of prologue */
    v80 = v91;
    v79 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v80)) < ((int32_t)(v79))) goto v44;
    v80 = v89;
    v79 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v80)) < ((int32_t)(v79))) goto v44;
    v80 = v91;
    v79 = v89;
    v79 = (Lisp_Object)(int32_t)((int32_t)v80 + (int32_t)v79 - TAG_FIXNUM);
    v93 = v79;
    v79 = (Lisp_Object)1; /* 0 */
    v82 = v79;
    goto v94;

v94:
    v80 = v93;
    v79 = v82;
    v79 = (Lisp_Object)(int32_t)((int32_t)v80 - (int32_t)v79 + TAG_FIXNUM);
    v79 = ((intptr_t)(v79) < 0 ? lisp_true : nil);
    if (v79 == nil) goto v95;
    v79 = (Lisp_Object)1; /* 0 */
    v86 = v79;
    goto v96;

v96:
    v80 = v91;
    v79 = v86;
    v79 = (Lisp_Object)(int32_t)((int32_t)v80 - (int32_t)v79 + TAG_FIXNUM);
    v79 = ((intptr_t)(v79) < 0 ? lisp_true : nil);
    if (!(v79 == nil)) { popv(1); return onevalue(v93); }
    v80 = v92;
    v79 = v86;
    v79 = *(Lisp_Object *)((char *)v80 + (CELL-TAG_VECTOR) + ((int32_t)v79/(16/CELL)));
    v87 = v79;
    v79 = (Lisp_Object)1; /* 0 */
    v85 = v79;
    goto v97;

v97:
    v80 = v89;
    v79 = v85;
    v79 = (Lisp_Object)(int32_t)((int32_t)v80 - (int32_t)v79 + TAG_FIXNUM);
    v79 = ((intptr_t)(v79) < 0 ? lisp_true : nil);
    if (v79 == nil) goto v98;
    v79 = v86;
    v79 = (Lisp_Object)((int32_t)(v79) + 0x10);
    v86 = v79;
    goto v96;

v98:
    v80 = v86;
    v79 = v85;
    v79 = (Lisp_Object)(int32_t)((int32_t)v80 + (int32_t)v79 - TAG_FIXNUM);
    v84 = v88;
    v83 = v79;
    v80 = v88;
    v82 = *(Lisp_Object *)((char *)v80 + (CELL-TAG_VECTOR) + ((int32_t)v79/(16/CELL)));
    v81 = v87;
    v80 = v90;
    v79 = v85;
    v79 = *(Lisp_Object *)((char *)v80 + (CELL-TAG_VECTOR) + ((int32_t)v79/(16/CELL)));
    v79 = Lmodular_times(nil, v81, v79);
    env = stack[0];
    {   int32_t w = int_of_fixnum(v82) + int_of_fixnum(v79);
        if (w >= current_modulus) w -= current_modulus;
        v79 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v84 + (CELL-TAG_VECTOR) + ((int32_t)v83/(16/CELL))) = v79;
    v79 = v85;
    v79 = (Lisp_Object)((int32_t)(v79) + 0x10);
    v85 = v79;
    goto v97;

v95:
    v81 = v88;
    v80 = v82;
    v79 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v81 + (CELL-TAG_VECTOR) + ((int32_t)v80/(16/CELL))) = v79;
    v79 = v82;
    v79 = (Lisp_Object)((int32_t)(v79) + 0x10);
    v82 = v79;
    goto v94;

v44:
    v79 = (Lisp_Object)-15; /* -1 */
    { popv(1); return onevalue(v79); }
}



/* Code for tr_write */

static Lisp_Object CC_tr_write(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tr_write");
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
    v29 = v0;
/* end of prologue */
    v99 = qvalue(elt(env, 1)); /* !*trsolve */
    if (v99 == nil) goto v38;
    v99 = v29;
    stack[0] = v99;
    goto v24;

v24:
    v99 = stack[0];
    if (v99 == nil) goto v100;
    v99 = stack[0];
    v99 = qcar(v99);
    v99 = Lprinc(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    v99 = stack[0];
    v99 = qcdr(v99);
    stack[0] = v99;
    goto v24;

v100:
        popv(2);
        return Lterpri(nil, 0);

v38:
    v99 = nil;
    { popv(2); return onevalue(v99); }
/* error exit handlers */
v31:
    popv(2);
    return nil;
}



/* Code for remflagss */

static Lisp_Object CC_remflagss(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v30, v31, v78;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remflagss");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v29 = v22;
    v31 = v0;
/* end of prologue */
    v78 = v29;
    goto v74;

v74:
    v29 = v78;
    if (v29 == nil) goto v24;
    v29 = v78;
    v29 = qcar(v29);
    v30 = v31;
    v29 = Lremflag(nil, v30, v29);
    env = stack[0];
    v29 = v78;
    v29 = qcdr(v29);
    v78 = v29;
    goto v74;

v24:
    v29 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v29); }
}



/* Code for msappend */

static Lisp_Object CC_msappend(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v19;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msappend");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v22;
    v68 = v0;
/* end of prologue */
    stack[-5] = v68;
    v68 = stack[-5];
    if (v68 == nil) goto v48;
    v68 = stack[-5];
    v68 = qcar(v68);
    stack[0] = stack[-4];
    v19 = stack[-4];
    v68 = Lsublis(nil, v19, v68);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-6];
    v68 = Lappend(nil, stack[0], v68);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-6];
    v68 = ncons(v68);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-6];
    stack[-2] = v68;
    stack[-3] = v68;
    goto v18;

v18:
    v68 = stack[-5];
    v68 = qcdr(v68);
    stack[-5] = v68;
    v68 = stack[-5];
    if (v68 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v68 = stack[-5];
    v68 = qcar(v68);
    stack[0] = stack[-4];
    v19 = stack[-4];
    v68 = Lsublis(nil, v19, v68);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-6];
    v68 = Lappend(nil, stack[0], v68);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-6];
    v68 = ncons(v68);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-6];
    v68 = Lrplacd(nil, stack[-1], v68);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-6];
    v68 = stack[-2];
    v68 = qcdr(v68);
    stack[-2] = v68;
    goto v18;

v48:
    v68 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v68); }
/* error exit handlers */
v107:
    popv(7);
    return nil;
}



/* Code for ibalp_simpat */

static Lisp_Object CC_ibalp_simpat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_simpat");
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
    stack[-2] = qcar(v25);
    v25 = stack[-1];
    v25 = qcdr(v25);
    v25 = qcar(v25);
    fn = elt(env, 1); /* ibalp_simpterm */
    stack[0] = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    v25 = stack[-1];
    v25 = qcdr(v25);
    v25 = qcdr(v25);
    v25 = qcar(v25);
    fn = elt(env, 1); /* ibalp_simpterm */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    {
        Lisp_Object v99 = stack[-2];
        Lisp_Object v29 = stack[0];
        popv(4);
        fn = elt(env, 2); /* ibalp_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v99, v29, v25);
    }
/* error exit handlers */
v28:
    popv(4);
    return nil;
}



/* Code for poly!-abs */

static Lisp_Object CC_polyKabs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-abs");
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
    v44 = stack[0];
    fn = elt(env, 1); /* poly!-minusp */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    if (v44 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v44 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* negf */
        return (*qfn1(fn))(qenv(fn), v44);
    }
/* error exit handlers */
v108:
    popv(2);
    return nil;
}



/* Code for integerom */

static Lisp_Object CC_integerom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for integerom");
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
    v24 = elt(env, 1); /* "<OMI> " */
    fn = elt(env, 3); /* printout */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-1];
    v24 = stack[0];
    v24 = Lprinc(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-1];
    v24 = elt(env, 2); /* " </OMI>" */
    v24 = Lprinc(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v48;
    v24 = nil;
    { popv(2); return onevalue(v24); }
/* error exit handlers */
v48:
    popv(2);
    return nil;
}



/* Code for ps!:putv */

static Lisp_Object MS_CDECL CC_psTputv(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v22,
                         Lisp_Object v13, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v113, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:putv");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:putv");
#endif
    if (stack >= stacklimit)
    {
        push3(v13,v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v22,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v13;
    stack[-1] = v22;
    v68 = v0;
/* end of prologue */
    v113 = v68;
    v17 = elt(env, 1); /* !:ps!: */
    if (!consp(v113)) goto v102;
    v113 = qcar(v113);
    if (!(v113 == v17)) goto v102;
    v17 = v68;
    v17 = qcdr(v17);
    if (symbolp(v17)) goto v1;
    v17 = v68;
    v68 = qcdr(v17);
    v113 = stack[-1];
    v17 = stack[0];
    *(Lisp_Object *)((char *)v68 + (CELL-TAG_VECTOR) + ((int32_t)v113/(16/CELL))) = v17;
    { popv(3); return onevalue(v17); }

v1:
    v17 = v68;
    v17 = qcdr(v17);
    fn = elt(env, 5); /* eval */
    v68 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v50;
    v113 = stack[-1];
    v17 = stack[0];
    *(Lisp_Object *)((char *)v68 + (CELL-TAG_VECTOR) + ((int32_t)v113/(16/CELL))) = v17;
    { popv(3); return onevalue(v17); }

v102:
    v17 = elt(env, 2); /* "PS:PUTV: not a ps" */
    v113 = v68;
    v17 = list2(v17, v113);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v113 = v17;
    v17 = v113;
    qvalue(elt(env, 3)) = v17; /* errmsg!* */
    v17 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v17 == nil)) goto v114;
    v17 = v113;
    fn = elt(env, 6); /* lprie */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    goto v114;

v114:
    v17 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v50;
    v17 = nil;
    { popv(3); return onevalue(v17); }
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for maxtype */

static Lisp_Object CC_maxtype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v25;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxtype");
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
    v25 = v0;
/* end of prologue */
    v26 = v25;
    if (!consp(v26)) return onevalue(v25);
    v26 = v25;
    v26 = qcdr(v26);
    v26 = Lconsp(nil, v26);
    if (v26 == nil) goto v101;
    v26 = v25;
    v26 = qcdr(v26);
    v26 = qcar(v26);
    return onevalue(v26);

v101:
    v26 = v25;
    v26 = qcar(v26);
    return onevalue(v26);
}



/* Code for bsubs */

static Lisp_Object CC_bsubs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bsubs");
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
    stack[0] = v0;
/* end of prologue */
    v52 = stack[0];
    if (v52 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v52 = stack[0];
    if (!consp(v52)) goto v18;
    v52 = stack[0];
    stack[-3] = v52;
    v52 = stack[-3];
    if (v52 == nil) goto v106;
    v52 = stack[-3];
    v52 = qcar(v52);
    v52 = CC_bsubs(env, v52);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v52 = ncons(v52);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    stack[-1] = v52;
    stack[-2] = v52;
    goto v31;

v31:
    v52 = stack[-3];
    v52 = qcdr(v52);
    stack[-3] = v52;
    v52 = stack[-3];
    if (v52 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v52 = stack[-3];
    v52 = qcar(v52);
    v52 = CC_bsubs(env, v52);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v52 = ncons(v52);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v52 = Lrplacd(nil, stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v52 = stack[-1];
    v52 = qcdr(v52);
    stack[-1] = v52;
    goto v31;

v106:
    v52 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v52); }

v18:
    v52 = stack[0];
    fn = elt(env, 2); /* bound */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    if (v52 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v52 = stack[0];
    {
        popv(5);
        fn = elt(env, 3); /* binding */
        return (*qfn1(fn))(qenv(fn), v52);
    }
/* error exit handlers */
v68:
    popv(5);
    return nil;
}



/* Code for mksgnsq */

static Lisp_Object CC_mksgnsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v105, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksgnsq");
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
    v105 = v0;
/* end of prologue */
    v9 = v105;
    fn = elt(env, 1); /* evenfree */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v105 = v9;
    if (v9 == nil) goto v100;
    v76 = v105;
    v9 = (Lisp_Object)17; /* 1 */
    if (v76 == v9) goto v99;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v9 = (Lisp_Object)17; /* 1 */
    v9 = cons(v105, v9);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    fn = elt(env, 2); /* mk!*sq */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v9 = list2(stack[0], v9);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v9);
    }

v99:
    v105 = (Lisp_Object)-15; /* -1 */
    v9 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v105, v9);

v100:
    v105 = (Lisp_Object)17; /* 1 */
    v9 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v105, v9);
/* error exit handlers */
v110:
    popv(2);
    return nil;
}



/* Code for cut!:ep */

static Lisp_Object CC_cutTep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cut:ep");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v22;
    stack[-2] = v0;
/* end of prologue */
    v97 = stack[-2];
    v122 = elt(env, 1); /* !:rd!: */
    if (!consp(v97)) goto v29;
    v97 = qcar(v97);
    if (!(v97 == v122)) goto v29;
    v122 = stack[-2];
    v122 = qcdr(v122);
    v122 = (consp(v122) ? nil : lisp_true);
    v122 = (v122 == nil ? lisp_true : nil);
    goto v48;

v48:
    if (v122 == nil) goto v111;
    v122 = stack[-1];
    v122 = integerp(v122);
    goto v18;

v18:
    if (v122 == nil) goto v123;
    v97 = stack[-1];
    v122 = stack[-2];
    v122 = qcdr(v122);
    v122 = qcdr(v122);
    v97 = difference2(v97, v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-1] = v97;
    v122 = (Lisp_Object)1; /* 0 */
    v122 = (Lisp_Object)lesseq2(v97, v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v122 = v122 ? lisp_true : nil;
    env = stack[-4];
    if (!(v122 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v122 = stack[-2];
    v122 = qcdr(v122);
    stack[0] = qcar(v122);
    v122 = stack[-1];
    v122 = negate(v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v122 = stack[-2];
    v122 = qcdr(v122);
    v97 = qcdr(v122);
    v122 = stack[-1];
    v122 = plus2(v97, v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    {
        Lisp_Object v70 = stack[-3];
        Lisp_Object v124 = stack[0];
        popv(5);
        return list2star(v70, v124, v122);
    }

v123:
    stack[0] = (Lisp_Object)1; /* 0 */
    v97 = elt(env, 3); /* "Invalid argument to" */
    v122 = elt(env, 0); /* cut!:ep */
    v122 = list2(v97, v122);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    {
        Lisp_Object v125 = stack[0];
        popv(5);
        fn = elt(env, 4); /* error */
        return (*qfn2(fn))(qenv(fn), v125, v122);
    }

v111:
    v122 = qvalue(elt(env, 2)); /* nil */
    goto v18;

v29:
    v122 = qvalue(elt(env, 2)); /* nil */
    goto v48;
/* error exit handlers */
v69:
    popv(5);
    return nil;
}



/* Code for tokquote */

static Lisp_Object MS_CDECL CC_tokquote(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "tokquote");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tokquote");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 6); /* readch1 */
    v101 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    qvalue(elt(env, 1)) = v101; /* crchar!* */
    v126 = elt(env, 2); /* " '" */
    v101 = qvalue(elt(env, 3)); /* outl!* */
    v101 = cons(v126, v101);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    qvalue(elt(env, 3)) = v101; /* outl!* */
    fn = elt(env, 7); /* rread1 */
    v101 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    v101 = Lmkquote(nil, v101);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[0];
    qvalue(elt(env, 4)) = v101; /* nxtsym!* */
    v101 = (Lisp_Object)65; /* 4 */
    qvalue(elt(env, 5)) = v101; /* ttype!* */
    v101 = qvalue(elt(env, 4)); /* nxtsym!* */
    { popv(1); return onevalue(v101); }
/* error exit handlers */
v14:
    popv(1);
    return nil;
}



/* Code for mo_diff */

static Lisp_Object CC_mo_diff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_diff");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v48 = v22;
    v44 = v0;
/* end of prologue */
    stack[0] = v44;
    fn = elt(env, 1); /* mo_neg */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    {
        Lisp_Object v101 = stack[0];
        popv(2);
        fn = elt(env, 2); /* mo_sum */
        return (*qfn2(fn))(qenv(fn), v101, v48);
    }
/* error exit handlers */
v108:
    popv(2);
    return nil;
}



/* Code for pdmult */

static Lisp_Object CC_pdmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v22;
    v138 = v0;
/* end of prologue */
    stack[-9] = v138;
    v138 = stack[-9];
    if (v138 == nil) goto v48;
    v138 = stack[-9];
    v138 = qcar(v138);
    stack[-4] = v138;
    v138 = stack[-4];
    v139 = qcar(v138);
    v138 = stack[-8];
    fn = elt(env, 2); /* pair */
    v138 = (*qfn2(fn))(qenv(fn), v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    stack[-3] = v138;
    v138 = stack[-3];
    if (v138 == nil) goto v35;
    v138 = stack[-3];
    v138 = qcar(v138);
    v139 = v138;
    v139 = qcar(v139);
    v138 = qcdr(v138);
    v138 = (Lisp_Object)(int32_t)((int32_t)v139 + (int32_t)v138 - TAG_FIXNUM);
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    stack[-1] = v138;
    stack[-2] = v138;
    goto v32;

v32:
    v138 = stack[-3];
    v138 = qcdr(v138);
    stack[-3] = v138;
    v138 = stack[-3];
    if (v138 == nil) goto v45;
    stack[0] = stack[-1];
    v138 = stack[-3];
    v138 = qcar(v138);
    v139 = v138;
    v139 = qcar(v139);
    v138 = qcdr(v138);
    v138 = (Lisp_Object)(int32_t)((int32_t)v139 + (int32_t)v138 - TAG_FIXNUM);
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    v138 = Lrplacd(nil, stack[0], v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    v138 = stack[-1];
    v138 = qcdr(v138);
    stack[-1] = v138;
    goto v32;

v45:
    v138 = stack[-2];
    v139 = v138;
    goto v2;

v2:
    v138 = stack[-4];
    v138 = qcdr(v138);
    v138 = cons(v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    stack[-6] = v138;
    stack[-7] = v138;
    goto v18;

v18:
    v138 = stack[-9];
    v138 = qcdr(v138);
    stack[-9] = v138;
    v138 = stack[-9];
    if (v138 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v138 = stack[-9];
    v138 = qcar(v138);
    stack[-4] = v138;
    v138 = stack[-4];
    v139 = qcar(v138);
    v138 = stack[-8];
    fn = elt(env, 2); /* pair */
    v138 = (*qfn2(fn))(qenv(fn), v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    stack[-3] = v138;
    v138 = stack[-3];
    if (v138 == nil) goto v141;
    v138 = stack[-3];
    v138 = qcar(v138);
    v139 = v138;
    v139 = qcar(v139);
    v138 = qcdr(v138);
    v138 = (Lisp_Object)(int32_t)((int32_t)v139 + (int32_t)v138 - TAG_FIXNUM);
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    stack[-1] = v138;
    stack[-2] = v138;
    goto v142;

v142:
    v138 = stack[-3];
    v138 = qcdr(v138);
    stack[-3] = v138;
    v138 = stack[-3];
    if (v138 == nil) goto v143;
    stack[0] = stack[-1];
    v138 = stack[-3];
    v138 = qcar(v138);
    v139 = v138;
    v139 = qcar(v139);
    v138 = qcdr(v138);
    v138 = (Lisp_Object)(int32_t)((int32_t)v139 + (int32_t)v138 - TAG_FIXNUM);
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    v138 = Lrplacd(nil, stack[0], v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    v138 = stack[-1];
    v138 = qcdr(v138);
    stack[-1] = v138;
    goto v142;

v143:
    v138 = stack[-2];
    v139 = v138;
    goto v144;

v144:
    v138 = stack[-4];
    v138 = qcdr(v138);
    v138 = cons(v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    v138 = Lrplacd(nil, stack[-5], v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-10];
    v138 = stack[-6];
    v138 = qcdr(v138);
    stack[-6] = v138;
    goto v18;

v141:
    v138 = qvalue(elt(env, 1)); /* nil */
    v139 = v138;
    goto v144;

v35:
    v138 = qvalue(elt(env, 1)); /* nil */
    v139 = v138;
    goto v2;

v48:
    v138 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v138); }
/* error exit handlers */
v140:
    popv(11);
    return nil;
}



/* Code for polynomlistfinddivisor */

static Lisp_Object MS_CDECL CC_polynomlistfinddivisor(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v22,
                         Lisp_Object v13, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v123, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "polynomlistfinddivisor");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomlistfinddivisor");
#endif
    if (stack >= stacklimit)
    {
        push3(v13,v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v22,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v13;
    v123 = v22;
    v136 = v0;
/* end of prologue */
    v145 = v123;
    v145 = qcar(v145);
    if (v145 == nil) goto v24;
    v145 = v136;
    v145 = qcar(v145);
    v145 = (v145 == nil ? lisp_true : nil);
    goto v100;

v100:
    if (v145 == nil) goto v25;
    v145 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v145); }

v25:
    stack[0] = nil;
    v145 = v123;
    v145 = qcar(v145);
    stack[-3] = v145;
    v145 = v136;
    stack[-1] = v145;
    goto v106;

v106:
    v145 = stack[-1];
    v145 = qcar(v145);
    if (v145 == nil) goto v111;
    v145 = stack[0];
    if (!(v145 == nil)) goto v111;
    v145 = stack[-2];
    if (v145 == nil) goto v39;
    v123 = stack[-3];
    v145 = stack[-1];
    v145 = qcar(v145);
    v145 = qcar(v145);
    fn = elt(env, 3); /* monomisdivisibleby */
    v145 = (*qfn2(fn))(qenv(fn), v123, v145);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    if (!(v145 == nil)) goto v47;

v39:
    v145 = stack[-2];
    if (v145 == nil) goto v17;
    v145 = qvalue(elt(env, 2)); /* nil */
    goto v6;

v6:
    if (!(v145 == nil)) goto v47;
    v145 = stack[-1];
    v145 = qcdr(v145);
    stack[-1] = v145;
    goto v106;

v47:
    v145 = qvalue(elt(env, 1)); /* t */
    stack[0] = v145;
    goto v106;

v17:
    v123 = stack[-3];
    v145 = stack[-1];
    v145 = qcar(v145);
    v145 = qcar(v145);
    fn = elt(env, 4); /* monomispommaretdivisibleby */
    v145 = (*qfn2(fn))(qenv(fn), v123, v145);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    goto v6;

v111:
    v145 = stack[-1];
    v145 = qcar(v145);
    { popv(5); return onevalue(v145); }

v24:
    v145 = qvalue(elt(env, 1)); /* t */
    goto v100;
/* error exit handlers */
v63:
    popv(5);
    return nil;
}



/* Code for cancel */

static Lisp_Object CC_cancel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cancel");
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
    v120 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v120 == nil)) goto v27;
    v120 = stack[0];
    v121 = qcdr(v120);
    v120 = (Lisp_Object)17; /* 1 */
    if (v121 == v120) goto v27;
    v120 = stack[0];
    v121 = qcar(v120);
    v120 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v120 = stack[0];
    v121 = qcdr(v120);
    v120 = (Lisp_Object)17; /* 1 */
    v120 = cons(v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    fn = elt(env, 2); /* mk!*sq */
    v121 = (*qfn1(fn))(qenv(fn), v120);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v120 = (Lisp_Object)-15; /* -1 */
    v120 = list2(v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    fn = elt(env, 3); /* simpexpt */
    v120 = (*qfn1(fn))(qenv(fn), v120);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    {
        Lisp_Object v146 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v146, v120);
    }

v27:
    v120 = stack[0];
    v121 = qcar(v120);
    v120 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v121 = (Lisp_Object)17; /* 1 */
    v120 = stack[0];
    v120 = qcdr(v120);
    v120 = cons(v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    {
        Lisp_Object v147 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v147, v120);
    }
/* error exit handlers */
v96:
    popv(3);
    return nil;
}



/* Code for sfto_tsqsumf */

static Lisp_Object CC_sfto_tsqsumf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_tsqsumf");
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

v4:
    v104 = stack[0];
    if (!consp(v104)) goto v23;
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = (consp(v104) ? nil : lisp_true);
    goto v24;

v24:
    if (v104 == nil) goto v40;
    v104 = stack[0];
    if (v104 == nil) goto v1;
    v104 = stack[0];
    fn = elt(env, 5); /* minusf */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    if (v104 == nil) goto v99;
    v104 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v104); }

v99:
    v104 = elt(env, 3); /* stsq */
    { popv(2); return onevalue(v104); }

v1:
    v104 = elt(env, 2); /* tsq */
    { popv(2); return onevalue(v104); }

v40:
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = qcar(v104);
    v104 = qcdr(v104);
    v104 = Levenp(nil, v104);
    env = stack[-1];
    if (v104 == nil) goto v21;
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = qcdr(v104);
    v104 = CC_sfto_tsqsumf(env, v104);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    if (v104 == nil) goto v77;
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[0] = v104;
    goto v4;

v77:
    v104 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v104); }

v21:
    v104 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v104); }

v23:
    v104 = qvalue(elt(env, 1)); /* t */
    goto v24;
/* error exit handlers */
v7:
    popv(2);
    return nil;
}



/* Code for revv0 */

static Lisp_Object CC_revv0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v68;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revv0");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v22;
    stack[-1] = v0;
/* end of prologue */

v53:
    v113 = stack[-1];
    v113 = qcdr(v113);
    v68 = qcar(v113);
    v113 = stack[0];
    if (v68 == v113) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v113 = stack[-1];
    v113 = qcdr(v113);
    v113 = qcar(v113);
    stack[-2] = v113;
    v113 = stack[-1];
    v68 = qcdr(v113);
    v113 = stack[-1];
    v113 = qcdr(v113);
    v113 = qcdr(v113);
    v113 = qcar(v113);
    v113 = Lrplaca(nil, v68, v113);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-3];
    v113 = stack[-1];
    v113 = qcdr(v113);
    v68 = qcdr(v113);
    v113 = stack[-1];
    v113 = qcdr(v113);
    v113 = qcdr(v113);
    v113 = qcdr(v113);
    v113 = qcar(v113);
    v113 = Lrplaca(nil, v68, v113);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-3];
    v113 = stack[-1];
    v113 = qcdr(v113);
    v113 = qcdr(v113);
    v68 = qcdr(v113);
    v113 = stack[-2];
    v113 = Lrplaca(nil, v68, v113);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-3];
    v68 = stack[-1];
    v113 = stack[0];
    stack[-1] = v68;
    stack[0] = v113;
    goto v53;
/* error exit handlers */
v137:
    popv(4);
    return nil;
}



/* Code for ibalp_vequal */

static Lisp_Object CC_ibalp_vequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v112;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_vequal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v22;
    v112 = v0;
/* end of prologue */
    v112 = qcar(v112);
    v44 = qcar(v44);
    v44 = (v112 == v44 ? lisp_true : nil);
    return onevalue(v44);
}



/* Code for vdp_poly */

static Lisp_Object CC_vdp_poly(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v53;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_poly");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v53 = v0;
/* end of prologue */
    v53 = qcdr(v53);
    v53 = qcdr(v53);
    v53 = qcdr(v53);
    v53 = qcar(v53);
    return onevalue(v53);
}



/* Code for naryrd */

static Lisp_Object MS_CDECL CC_naryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "naryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for naryrd");
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
    v25 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    v1 = v25;
    v25 = v1;
    if (v25 == nil) goto v53;
    stack[0] = v1;
    v25 = CC_naryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v27;
    {
        Lisp_Object v28 = stack[0];
        popv(2);
        return cons(v28, v25);
    }

v53:
    v25 = nil;
    { popv(2); return onevalue(v25); }
/* error exit handlers */
v27:
    popv(2);
    return nil;
}



/* Code for simpexpon1 */

static Lisp_Object CC_simpexpon1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpon1");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v22;
    stack[-2] = v0;
/* end of prologue */
    v110 = qvalue(elt(env, 1)); /* !*numval */
    if (v110 == nil) goto v11;
    v109 = qvalue(elt(env, 2)); /* dmode!* */
    v110 = elt(env, 3); /* !:rd!: */
    if (v109 == v110) goto v48;
    v109 = qvalue(elt(env, 2)); /* dmode!* */
    v110 = elt(env, 5); /* !:cr!: */
    v110 = (v109 == v110 ? lisp_true : nil);
    goto v23;

v23:
    if (v110 == nil) goto v11;
    v109 = stack[-1];
    v110 = stack[-2];
        popv(5);
        return Lapply1(nil, v109, v110);

v11:
    stack[-3] = qvalue(elt(env, 2)); /* dmode!* */
    qvalue(elt(env, 2)) = nil; /* dmode!* */
    stack[0] = qvalue(elt(env, 6)); /* alglist!* */
    qvalue(elt(env, 6)) = nil; /* alglist!* */
    v110 = qvalue(elt(env, 7)); /* nil */
    v110 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-4];
    qvalue(elt(env, 6)) = v110; /* alglist!* */
    v109 = stack[-1];
    v110 = stack[-2];
    v110 = Lapply1(nil, v109, v110);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-4];
    qvalue(elt(env, 6)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 2)) = stack[-3]; /* dmode!* */
    { popv(5); return onevalue(v110); }

v48:
    v110 = qvalue(elt(env, 4)); /* t */
    goto v23;
/* error exit handlers */
v114:
    env = stack[-4];
    qvalue(elt(env, 6)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 2)) = stack[-3]; /* dmode!* */
    popv(5);
    return nil;
}



/* Code for simp */

static Lisp_Object CC_simp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v270, v271, v272, v273, v274;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp");
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
    v270 = qvalue(elt(env, 1)); /* varstack!* */
    stack[-6] = qvalue(elt(env, 1)); /* varstack!* */
    qvalue(elt(env, 1)) = v270; /* varstack!* */
    stack[-1] = nil;
    v270 = stack[-5];
    v270 = integerp(v270);
    if (v270 == nil) goto v94;
    v271 = stack[-5];
    v270 = (Lisp_Object)1; /* 0 */
    if (v271 == v270) goto v99;
    v270 = qvalue(elt(env, 3)); /* dmode!* */
    if (!(v270 == nil)) goto v137;
    v271 = stack[-5];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = cons(v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v53:
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    { popv(8); return onevalue(v270); }

v137:
    v271 = stack[-5];
    v270 = qvalue(elt(env, 1)); /* varstack!* */
    v270 = cons(v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    qvalue(elt(env, 1)) = v270; /* varstack!* */
    v271 = qvalue(elt(env, 6)); /* simpcount!* */
    v270 = qvalue(elt(env, 7)); /* simplimit!* */
    v270 = (Lisp_Object)greaterp2(v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    v270 = v270 ? lisp_true : nil;
    env = stack[-7];
    if (v270 == nil) goto v125;
    v270 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 6)) = v270; /* simpcount!* */
    v270 = elt(env, 8); /* "Simplification recursion too deep" */
    v271 = v270;
    v270 = v271;
    qvalue(elt(env, 9)) = v270; /* errmsg!* */
    v270 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v270 == nil)) goto v276;
    v270 = v271;
    fn = elt(env, 38); /* lprie */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v276;

v276:
    v270 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v277;

v277:
    v270 = qvalue(elt(env, 6)); /* simpcount!* */
    v270 = add1(v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    qvalue(elt(env, 6)) = v270; /* simpcount!* */
    v270 = stack[-5];
    if (!consp(v270)) goto v278;
    v270 = stack[-5];
    v270 = qcar(v270);
    if (symbolp(v270)) goto v279;
    v270 = qvalue(elt(env, 5)); /* t */
    goto v280;

v280:
    if (v270 == nil) goto v281;
    v270 = stack[-5];
    v270 = qcar(v270);
    if (!consp(v270)) goto v282;
    v270 = stack[-5];
    v270 = qcar(v270);
    v270 = qcar(v270);
    if (!(symbolp(v270))) goto v283;
    v270 = stack[-5];
    v270 = qcar(v270);
    v271 = qcar(v270);
    v270 = elt(env, 17); /* name */
    v270 = get(v271, v270);
    env = stack[-7];
    stack[-1] = v270;
    if (v270 == nil) goto v283;
    v271 = stack[-5];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v283:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 18); /* mat */
    if (!consp(v271)) goto v284;
    v271 = qcar(v271);
    if (!(v271 == v270)) goto v284;
    v270 = stack[-5];
    v270 = qcdr(v270);
    fn = elt(env, 40); /* revlis */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    stack[-1] = v270;
    fn = elt(env, 41); /* numlis */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    if (v270 == nil) goto v285;
    v270 = stack[-1];
    v271 = Llength(nil, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = (Lisp_Object)33; /* 2 */
    v270 = (v271 == v270 ? lisp_true : nil);
    goto v286;

v286:
    if (v270 == nil) goto v287;
    v270 = stack[-5];
    v270 = qcar(v270);
    v271 = qcdr(v270);
    v270 = stack[-1];
    v270 = qcar(v270);
    fn = elt(env, 42); /* pnth */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v271 = qcar(v270);
    v270 = stack[-1];
    v270 = qcdr(v270);
    v270 = qcar(v270);
    fn = elt(env, 42); /* pnth */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = qcar(v270);
    v271 = CC_simp(env, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v287:
    v274 = elt(env, 19); /* "Syntax error:" */
    v273 = stack[-5];
    v272 = elt(env, 20); /* "invalid" */
    v271 = qvalue(elt(env, 2)); /* nil */
    v270 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 43); /* msgpri */
    v270 = (*qfnn(fn))(qenv(fn), 5, v274, v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v93;

v93:
    v270 = nil;
    goto v53;

v285:
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v286;

v284:
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v286;

v282:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 16); /* "operator" */
    fn = elt(env, 44); /* typerr */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v93;

v281:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 21); /* opfn */
    v270 = Lflagp(nil, v271, v270);
    env = stack[-7];
    if (v270 == nil) goto v288;
    v270 = stack[-5];
    fn = elt(env, 45); /* opfneval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    stack[-1] = v270;
    fn = elt(env, 46); /* getrtype */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v271 = v270;
    if (v270 == nil) goto v289;
    v270 = elt(env, 22); /* yetunknowntype */
    if (v271 == v270) goto v290;
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v291;

v291:
    if (v270 == nil) goto v292;
    v270 = stack[-1];
    v270 = CC_simp(env, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v292:
    v271 = stack[-5];
    v270 = elt(env, 23); /* "scalar" */
    fn = elt(env, 44); /* typerr */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v93;

v290:
    v270 = stack[-1];
    fn = elt(env, 47); /* reval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    stack[-1] = v270;
    fn = elt(env, 46); /* getrtype */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = (v270 == nil ? lisp_true : nil);
    goto v291;

v289:
    v270 = stack[-1];
    fn = elt(env, 48); /* simp_without_resimp */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v288:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 24); /* psopfn */
    v270 = get(v271, v270);
    env = stack[-7];
    stack[-1] = v270;
    if (v270 == nil) goto v293;
    stack[0] = stack[-1];
    v270 = stack[-5];
    fn = elt(env, 49); /* argnochk */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = qcdr(v270);
    v270 = Lapply1(nil, stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    stack[-1] = v270;
    fn = elt(env, 46); /* getrtype */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    if (v270 == nil) goto v294;
    v271 = stack[-5];
    v270 = elt(env, 23); /* "scalar" */
    fn = elt(env, 44); /* typerr */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v93;

v294:
    v271 = stack[-1];
    v270 = stack[-5];
    if (equal(v271, v270)) goto v295;
    v270 = stack[-1];
    fn = elt(env, 48); /* simp_without_resimp */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v295:
    v272 = stack[-1];
    v271 = (Lisp_Object)17; /* 1 */
    v270 = (Lisp_Object)17; /* 1 */
    v270 = acons(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v271 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = (Lisp_Object)17; /* 1 */
    v271 = cons(v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v293:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 25); /* polyfn */
    v270 = get(v271, v270);
    env = stack[-7];
    stack[-1] = v270;
    if (v270 == nil) goto v296;
    v270 = stack[-5];
    fn = elt(env, 49); /* argnochk */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    stack[-4] = stack[-1];
    v270 = stack[-5];
    v270 = qcdr(v270);
    stack[-3] = v270;
    v270 = stack[-3];
    if (v270 == nil) goto v297;
    v270 = stack[-3];
    v270 = qcar(v270);
    fn = elt(env, 50); /* simp!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    fn = elt(env, 51); /* !*q2f */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    stack[-1] = v270;
    stack[-2] = v270;
    goto v298;

v298:
    v270 = stack[-3];
    v270 = qcdr(v270);
    stack[-3] = v270;
    v270 = stack[-3];
    if (v270 == nil) goto v299;
    stack[0] = stack[-1];
    v270 = stack[-3];
    v270 = qcar(v270);
    fn = elt(env, 50); /* simp!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    fn = elt(env, 51); /* !*q2f */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = Lrplacd(nil, stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-1];
    v270 = qcdr(v270);
    stack[-1] = v270;
    goto v298;

v299:
    v270 = stack[-2];
    goto v300;

v300:
    fn = elt(env, 52); /* lispapply */
    v271 = (*qfn2(fn))(qenv(fn), stack[-4], v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = (Lisp_Object)17; /* 1 */
    v271 = cons(v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v297:
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v300;

v296:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 26); /* opmtch */
    v270 = get(v271, v270);
    env = stack[-7];
    if (v270 == nil) goto v301;
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 27); /* simpfn */
    v271 = get(v271, v270);
    env = stack[-7];
    v270 = elt(env, 28); /* simpiden */
    if (v271 == v270) goto v302;
    v270 = stack[-5];
    fn = elt(env, 53); /* opmtchrevop */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    stack[-1] = v270;
    goto v303;

v303:
    if (v270 == nil) goto v301;
    v270 = stack[-1];
    v271 = CC_simp(env, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v301:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 27); /* simpfn */
    v270 = get(v271, v270);
    env = stack[-7];
    stack[-1] = v270;
    if (v270 == nil) goto v304;
    stack[0] = stack[-1];
    v271 = stack[-1];
    v270 = elt(env, 28); /* simpiden */
    if (v271 == v270) goto v305;
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 29); /* full */
    v270 = Lflagp(nil, v271, v270);
    env = stack[-7];
    goto v306;

v306:
    if (v270 == nil) goto v307;
    v270 = stack[-5];
    fn = elt(env, 49); /* argnochk */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v308;

v308:
    v271 = Lapply1(nil, stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v307:
    v270 = stack[-5];
    fn = elt(env, 49); /* argnochk */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = qcdr(v270);
    goto v308;

v305:
    v270 = qvalue(elt(env, 5)); /* t */
    goto v306;

v304:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 30); /* rtype */
    v270 = get(v271, v270);
    env = stack[-7];
    stack[-1] = v270;
    if (v270 == nil) goto v309;
    v271 = stack[-1];
    v270 = elt(env, 31); /* getelemfn */
    v270 = get(v271, v270);
    env = stack[-7];
    stack[-1] = v270;
    if (v270 == nil) goto v309;
    v271 = stack[-1];
    v270 = stack[-5];
    v270 = Lapply1(nil, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v271 = CC_simp(env, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v309:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 32); /* boolean */
    v270 = Lflagp(nil, v271, v270);
    env = stack[-7];
    if (v270 == nil) goto v310;
    v270 = qvalue(elt(env, 5)); /* t */
    goto v311;

v311:
    if (v270 == nil) goto v312;
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 34); /* prtch */
    v270 = get(v271, v270);
    env = stack[-7];
    stack[-1] = v270;
    if (v270 == nil) goto v313;
    v270 = stack[-1];
    v271 = v270;
    goto v314;

v314:
    v270 = elt(env, 35); /* "algebraic operator" */
    fn = elt(env, 44); /* typerr */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v93;

v313:
    v270 = stack[-5];
    v270 = qcar(v270);
    v271 = v270;
    goto v314;

v312:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 36); /* nochange */
    v270 = Lflagp(nil, v271, v270);
    env = stack[-7];
    if (v270 == nil) goto v315;
    v270 = stack[-5];
    fn = elt(env, 54); /* eval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v271 = CC_simp(env, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v315:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 24); /* psopfn */
    v270 = get(v271, v270);
    env = stack[-7];
    if (!(v270 == nil)) goto v316;
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 37); /* rtypefn */
    v270 = get(v271, v270);
    env = stack[-7];
    if (!(v270 == nil)) goto v316;
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 16); /* "operator" */
    fn = elt(env, 55); /* redmsg */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    v270 = qcar(v270);
    fn = elt(env, 56); /* mkop */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v271 = stack[-5];
    v270 = qvalue(elt(env, 1)); /* varstack!* */
    v270 = Ldelete(nil, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    qvalue(elt(env, 1)) = v270; /* varstack!* */
    v270 = stack[-5];
    v271 = CC_simp(env, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v316:
    v271 = stack[-5];
    v270 = elt(env, 23); /* "scalar" */
    fn = elt(env, 44); /* typerr */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v93;

v310:
    v270 = stack[-5];
    v271 = qcar(v270);
    v270 = elt(env, 33); /* infix */
    v270 = get(v271, v270);
    env = stack[-7];
    goto v311;

v302:
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v303;

v279:
    v270 = stack[-5];
    v270 = qcar(v270);
    v270 = (v270 == nil ? lisp_true : nil);
    goto v280;

v278:
    v270 = stack[-5];
    fn = elt(env, 57); /* simpatom */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    v270 = stack[-5];
    fn = elt(env, 39); /* !*ssave */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v125:
    v271 = stack[-5];
    v270 = elt(env, 11); /* !*sq */
    if (!consp(v271)) goto v317;
    v271 = qcar(v271);
    if (!(v271 == v270)) goto v317;
    v270 = stack[-5];
    v270 = qcdr(v270);
    v270 = qcdr(v270);
    v270 = qcar(v270);
    if (v270 == nil) goto v142;
    v270 = qvalue(elt(env, 12)); /* !*resimp */
    v270 = (v270 == nil ? lisp_true : nil);
    goto v318;

v318:
    if (v270 == nil) goto v128;
    v270 = stack[-5];
    v270 = qcdr(v270);
    v270 = qcar(v270);
    goto v53;

v128:
    v270 = qvalue(elt(env, 13)); /* !*uncached */
    if (v270 == nil) goto v65;
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v64;

v64:
    if (v270 == nil) goto v277;
    v270 = stack[-1];
    v270 = qcar(v270);
    if (v270 == nil) goto v82;
    v270 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 15)) = v270; /* !*sub2 */
    goto v82;

v82:
    v270 = stack[-1];
    v270 = qcdr(v270);
    goto v53;

v65:
    v270 = qvalue(elt(env, 14)); /* alglist!* */
    v270 = qcar(v270);
    v271 = v270;
    if (v271 == nil) goto v59;
    v271 = stack[-5];
    fn = elt(env, 58); /* gethash */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v134;

v134:
    stack[-1] = v270;
    goto v64;

v59:
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v134;

v142:
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v318;

v317:
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v318;

v99:
    v271 = qvalue(elt(env, 2)); /* nil */
    v270 = (Lisp_Object)17; /* 1 */
    v270 = cons(v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v53;

v94:
    v271 = stack[-5];
    v270 = qvalue(elt(env, 1)); /* varstack!* */
    v270 = Lmember(nil, v271, v270);
    if (v270 == nil) goto v137;
    v274 = qvalue(elt(env, 2)); /* nil */
    v273 = stack[-5];
    v272 = elt(env, 4); /* "improperly defined in terms of itself" */
    v271 = qvalue(elt(env, 2)); /* nil */
    v270 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 43); /* msgpri */
    v270 = (*qfnn(fn))(qenv(fn), 5, v274, v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-7];
    goto v137;
/* error exit handlers */
v275:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    popv(8);
    return nil;
}



/* Code for zeropp */

static Lisp_Object CC_zeropp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zeropp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v0;
/* end of prologue */
    v35 = v37;
    if (!consp(v35)) goto v4;
    v35 = v37;
    v36 = qcar(v35);
    v35 = elt(env, 1); /* !:rd!: */
    if (v36 == v35) goto v100;
    v35 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v35);

v100:
    v35 = v37;
    v35 = qcdr(v35);
    if (!consp(v35)) goto v25;
    v35 = v37;
    v35 = qcdr(v35);
    v36 = qcar(v35);
    v35 = (Lisp_Object)1; /* 0 */
    v35 = (v36 == v35 ? lisp_true : nil);
    return onevalue(v35);

v25:
    v35 = v37;
    v35 = qcdr(v35);
        return Lzerop(nil, v35);

v4:
    v35 = v37;
        return Lzerop(nil, v35);
}



/* Code for gpexp1p */

static Lisp_Object CC_gpexp1p(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpexp1p");
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

v3:
    v2 = stack[0];
    if (v2 == nil) goto v4;
    v2 = stack[0];
    v2 = qcar(v2);
    fn = elt(env, 3); /* gpexpp */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    if (v2 == nil) goto v48;
    v2 = stack[0];
    v2 = qcdr(v2);
    stack[0] = v2;
    goto v3;

v48:
    v2 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v2); }

v4:
    v2 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v2); }
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for mo!=lexcomp */

static Lisp_Object CC_moMlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v77, v110, v109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=lexcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v77 = v22;
    v110 = v0;
/* end of prologue */

v38:
    v76 = v110;
    if (v76 == nil) goto v18;
    v76 = v77;
    if (v76 == nil) goto v26;
    v76 = v110;
    v109 = qcar(v76);
    v76 = v77;
    v76 = qcar(v76);
    if (equal(v109, v76)) goto v27;
    v76 = v110;
    v76 = qcar(v76);
    v77 = qcar(v77);
    if (((int32_t)(v76)) > ((int32_t)(v77))) goto v33;
    v76 = (Lisp_Object)-15; /* -1 */
    return onevalue(v76);

v33:
    v76 = (Lisp_Object)17; /* 1 */
    return onevalue(v76);

v27:
    v76 = v110;
    v76 = qcdr(v76);
    v110 = v76;
    v76 = v77;
    v76 = qcdr(v76);
    v77 = v76;
    goto v38;

v26:
    v76 = elt(env, 1); /* (0) */
    v77 = v76;
    goto v38;

v18:
    v76 = v77;
    if (v76 == nil) goto v44;
    v76 = elt(env, 1); /* (0) */
    v110 = v76;
    goto v38;

v44:
    v76 = (Lisp_Object)1; /* 0 */
    return onevalue(v76);
}



/* Code for arintequiv!: */

static Lisp_Object CC_arintequivT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v46, v39;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arintequiv:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v0;
/* end of prologue */
    v47 = v39;
    v47 = qcdr(v47);
    if (is_number(v47)) goto v4;
    v47 = v39;
    v47 = qcdr(v47);
    v46 = qcar(v47);
    v47 = elt(env, 1); /* !:rn!: */
    if (v46 == v47) goto v28;
    v47 = qvalue(elt(env, 2)); /* nil */
    goto v44;

v44:
    if (v47 == nil) goto v35;
    v47 = v39;
    v47 = qcdr(v47);
    v47 = qcdr(v47);
    v47 = qcar(v47);
    return onevalue(v47);

v35:
    v47 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v47);

v28:
    v47 = v39;
    v47 = qcdr(v47);
    v47 = qcdr(v47);
    v46 = qcdr(v47);
    v47 = (Lisp_Object)17; /* 1 */
    v47 = (v46 == v47 ? lisp_true : nil);
    goto v44;

v4:
    v47 = v39;
    v47 = qcdr(v47);
    return onevalue(v47);
}



/* Code for horner!-rule */

static Lisp_Object MS_CDECL CC_hornerKrule(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v22,
                         Lisp_Object v13, Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v328, v329, v330, v331;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "horner-rule");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule");
#endif
    if (stack >= stacklimit)
    {
        push4(v10,v13,v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v22,v13,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v10;
    stack[-2] = v13;
    stack[-3] = v22;
    stack[-4] = v0;
/* end of prologue */

v3:
    v328 = stack[-2];
    if (!consp(v328)) goto v23;
    v328 = stack[-2];
    v328 = qcar(v328);
    v328 = (consp(v328) ? nil : lisp_true);
    goto v24;

v24:
    if (v328 == nil) goto v95;
    v328 = stack[-1];
    v328 = qcar(v328);
    v328 = qcdr(v328);
    v328 = (Lisp_Object)zerop(v328);
    v328 = v328 ? lisp_true : nil;
    env = stack[-6];
    if (v328 == nil) goto v106;
    v328 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v328);
    }

v106:
    v328 = stack[-2];
    fn = elt(env, 2); /* !*d2n */
    stack[0] = (*qfn1(fn))(qenv(fn), v328);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[-6];
    stack[-2] = stack[-4];
    v328 = stack[-1];
    v328 = qcar(v328);
    v329 = qcdr(v328);
    v328 = stack[-3];
    v328 = Lexpt(nil, v329, v328);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[-6];
    v328 = times2(stack[-2], v328);
    nil = C_nil;
    if (exception_pending()) goto v332;
    {
        Lisp_Object v333 = stack[0];
        popv(7);
        return plus2(v333, v328);
    }

v95:
    v328 = stack[-2];
    v328 = qcar(v328);
    v328 = qcar(v328);
    v329 = qcar(v328);
    v328 = stack[-1];
    v328 = qcar(v328);
    v328 = qcar(v328);
    if (equal(v329, v328)) goto v66;
    v328 = stack[-1];
    v328 = qcar(v328);
    v328 = qcdr(v328);
    v328 = (Lisp_Object)zerop(v328);
    v328 = v328 ? lisp_true : nil;
    env = stack[-6];
    if (v328 == nil) goto v115;
    v329 = stack[-2];
    v328 = stack[-1];
    v328 = qcdr(v328);
    {
        popv(7);
        fn = elt(env, 3); /* evaluate!-in!-order */
        return (*qfn2(fn))(qenv(fn), v329, v328);
    }

v115:
    v329 = stack[-2];
    v328 = stack[-1];
    v328 = qcdr(v328);
    fn = elt(env, 3); /* evaluate!-in!-order */
    stack[0] = (*qfn2(fn))(qenv(fn), v329, v328);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[-6];
    stack[-2] = stack[-4];
    v328 = stack[-1];
    v328 = qcar(v328);
    v329 = qcdr(v328);
    v328 = stack[-3];
    v328 = Lexpt(nil, v329, v328);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[-6];
    v328 = times2(stack[-2], v328);
    nil = C_nil;
    if (exception_pending()) goto v332;
    {
        Lisp_Object v334 = stack[0];
        popv(7);
        return plus2(v334, v328);
    }

v66:
    v328 = stack[-2];
    v328 = qcar(v328);
    v328 = qcar(v328);
    v328 = qcdr(v328);
    stack[-5] = v328;
    v328 = stack[-1];
    v328 = qcar(v328);
    v328 = qcdr(v328);
    v328 = (Lisp_Object)zerop(v328);
    v328 = v328 ? lisp_true : nil;
    env = stack[-6];
    if (v328 == nil) goto v80;
    v328 = stack[-2];
    v328 = qcar(v328);
    v329 = qcdr(v328);
    v328 = stack[-1];
    v328 = qcdr(v328);
    fn = elt(env, 3); /* evaluate!-in!-order */
    v328 = (*qfn2(fn))(qenv(fn), v329, v328);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[-6];
    v331 = v328;
    goto v335;

v335:
    v330 = stack[-5];
    v328 = stack[-2];
    v329 = qcdr(v328);
    v328 = stack[-1];
    stack[-4] = v331;
    stack[-3] = v330;
    stack[-2] = v329;
    stack[-1] = v328;
    goto v3;

v80:
    v328 = stack[-2];
    v328 = qcar(v328);
    v329 = qcdr(v328);
    v328 = stack[-1];
    v328 = qcdr(v328);
    fn = elt(env, 3); /* evaluate!-in!-order */
    stack[0] = (*qfn2(fn))(qenv(fn), v329, v328);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[-6];
    v328 = stack[-1];
    v328 = qcar(v328);
    v330 = qcdr(v328);
    v329 = stack[-3];
    v328 = stack[-5];
    v328 = (Lisp_Object)(int32_t)((int32_t)v329 - (int32_t)v328 + TAG_FIXNUM);
    v328 = Lexpt(nil, v330, v328);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[-6];
    v328 = times2(stack[-4], v328);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[-6];
    v328 = plus2(stack[0], v328);
    nil = C_nil;
    if (exception_pending()) goto v332;
    env = stack[-6];
    v331 = v328;
    goto v335;

v23:
    v328 = qvalue(elt(env, 1)); /* t */
    goto v24;
/* error exit handlers */
v332:
    popv(7);
    return nil;
}



/* Code for crprcd2 */

static Lisp_Object CC_crprcd2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crprcd2");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v22;
    stack[-1] = v0;
/* end of prologue */
    v18 = stack[-1];
    fn = elt(env, 2); /* crprcd */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    stack[-1] = v18;
    v18 = stack[0];
    fn = elt(env, 2); /* crprcd */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    qvalue(elt(env, 1)) = v18; /* yy!! */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v23:
    popv(3);
    return nil;
}



/* Code for rempropss */

static Lisp_Object CC_rempropss(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36, v37, v47, v46, v39;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rempropss");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v46 = v22;
    v35 = v0;
/* end of prologue */
    v39 = v35;
    goto v74;

v74:
    v35 = v39;
    if (v35 == nil) goto v24;
    v35 = v39;
    v35 = qcar(v35);
    v47 = v35;
    v35 = v46;
    v37 = v35;
    goto v26;

v26:
    v35 = v37;
    if (v35 == nil) goto v5;
    v35 = v37;
    v35 = qcar(v35);
    v36 = v47;
    v35 = Lremprop(nil, v36, v35);
    env = stack[0];
    v35 = v37;
    v35 = qcdr(v35);
    v37 = v35;
    goto v26;

v5:
    v35 = v39;
    v35 = qcdr(v35);
    v39 = v35;
    goto v74;

v24:
    v35 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v35); }
}



/* Code for qqe_arg!-check!-b */

static Lisp_Object CC_qqe_argKcheckKb(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_arg-check-b");
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
    v77 = stack[0];
    fn = elt(env, 3); /* qqe_id!-nyt!-branchb */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    if (v77 == nil) goto v74;
    v77 = stack[0];
    if (!consp(v77)) goto v108;
    v77 = qvalue(elt(env, 1)); /* nil */
    goto v112;

v112:
    if (v77 == nil) goto v48;
    v77 = stack[0];
    fn = elt(env, 4); /* qqe_qtidp */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    if (v77 == nil) goto v29;
    v77 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v77); }

v29:
    v77 = stack[0];
    fn = elt(env, 5); /* qqe_nytidp */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    if (v77 == nil) goto v12;
    v77 = stack[0];
    fn = elt(env, 6); /* qqe_btid */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    v77 = stack[0];
    fn = elt(env, 7); /* qqe_add2rollbackids */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    v77 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v77); }

v12:
    v77 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v77); }

v48:
    v77 = stack[0];
    if (!consp(v77)) goto v9;
    v77 = stack[0];
    fn = elt(env, 8); /* qqe_arg!-check */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    v77 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v77); }

v9:
    v77 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v77); }

v108:
    v77 = stack[0];
    v77 = (is_number(v77) ? lisp_true : nil);
    v77 = (v77 == nil ? lisp_true : nil);
    goto v112;

v74:
    v77 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v77); }
/* error exit handlers */
v109:
    popv(2);
    return nil;
}



/* Code for ibalp_vmember */

static Lisp_Object CC_ibalp_vmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_vmember");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v22;
    stack[-1] = v0;
/* end of prologue */

v3:
    v111 = stack[0];
    if (v111 == nil) goto v38;
    v106 = stack[-1];
    v111 = stack[0];
    v111 = qcar(v111);
    fn = elt(env, 2); /* ibalp_vequal */
    v111 = (*qfn2(fn))(qenv(fn), v106, v111);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    if (!(v111 == nil)) { popv(3); return onevalue(v111); }
    v106 = stack[-1];
    v111 = stack[0];
    v111 = qcdr(v111);
    stack[-1] = v106;
    stack[0] = v111;
    goto v3;

v38:
    v111 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v111); }
/* error exit handlers */
v41:
    popv(3);
    return nil;
}



/* Code for aex_reducedtag */

static Lisp_Object CC_aex_reducedtag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v18;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_reducedtag");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v0;
/* end of prologue */
    v18 = qcdr(v18);
    v18 = qcdr(v18);
    v18 = qcdr(v18);
    v18 = qcdr(v18);
    v18 = qcar(v18);
    return onevalue(v18);
}



/* Code for diffp1 */

static Lisp_Object CC_diffp1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v105, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffp1");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v9 = v22;
    v76 = v0;
/* end of prologue */
    v105 = v76;
    v105 = qcar(v105);
    if (v105 == v9) goto v14;
    v9 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v9); }

v14:
    v9 = v76;
    v105 = qcdr(v9);
    v9 = (Lisp_Object)17; /* 1 */
    if (v105 == v9) goto v101;
    v9 = v76;
    stack[-1] = qcdr(v9);
    v9 = v76;
    stack[0] = qcar(v9);
    v9 = v76;
    v9 = qcdr(v9);
    v105 = sub1(v9);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-2];
    v9 = (Lisp_Object)17; /* 1 */
    v9 = acons(stack[0], v105, v9);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-2];
    v9 = ncons(v9);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-2];
    {
        Lisp_Object v21 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* multd */
        return (*qfn2(fn))(qenv(fn), v21, v9);
    }

v101:
    v9 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v9); }
/* error exit handlers */
v109:
    popv(3);
    return nil;
}



/* Code for omiir */

static Lisp_Object MS_CDECL CC_omiir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omiir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omiir");
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
    fn = elt(env, 2); /* lex */
    v100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v100 = qvalue(elt(env, 1)); /* char */
    v100 = Lcompress(nil, v100);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    stack[0] = v100;
    fn = elt(env, 2); /* lex */
    v100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v23;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for testredh */

static Lisp_Object CC_testredh(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testredh");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v52 = qvalue(elt(env, 2)); /* maxvar */
    v45 = stack[0];
    v45 = plus2(v52, v45);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    v52 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v45/(16/CELL)));
    v45 = (Lisp_Object)1; /* 0 */
    v45 = *(Lisp_Object *)((char *)v52 + (CELL-TAG_VECTOR) + ((int32_t)v45/(16/CELL)));
    if (v45 == nil) goto v38;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v52 = qvalue(elt(env, 2)); /* maxvar */
    v45 = stack[0];
    v45 = plus2(v52, v45);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    v52 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v45/(16/CELL)));
    v45 = (Lisp_Object)17; /* 1 */
    v45 = *(Lisp_Object *)((char *)v52 + (CELL-TAG_VECTOR) + ((int32_t)v45/(16/CELL)));
    v45 = qcar(v45);
    v52 = qcar(v45);
    v45 = (Lisp_Object)33; /* 2 */
    v45 = (Lisp_Object)lessp2(v52, v45);
    nil = C_nil;
    if (exception_pending()) goto v17;
    v45 = v45 ? lisp_true : nil;
    env = stack[-2];
    if (v45 == nil) goto v38;
    v45 = stack[0];
    fn = elt(env, 3); /* rowdel */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    v45 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* testredzz */
        return (*qfn1(fn))(qenv(fn), v45);
    }

v38:
    v45 = nil;
    { popv(3); return onevalue(v45); }
/* error exit handlers */
v17:
    popv(3);
    return nil;
}



/* Code for getrtype1 */

static Lisp_Object CC_getrtype1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v10;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtype1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    v10 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v10);
}



/* Code for mkuwedge */

static Lisp_Object CC_mkuwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkuwedge");
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
    v1 = v0;
/* end of prologue */
    v2 = v1;
    v2 = qcdr(v2);
    if (v2 == nil) goto v14;
    v2 = elt(env, 1); /* wedge */
    v1 = cons(v2, v1);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[0];
    fn = elt(env, 2); /* fkern */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v27;
    v1 = qcar(v1);
    { popv(1); return onevalue(v1); }

v14:
    v1 = qcar(v1);
    { popv(1); return onevalue(v1); }
/* error exit handlers */
v27:
    popv(1);
    return nil;
}



/* Code for smemql */

static Lisp_Object CC_smemql(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemql");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v22;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v74;

v74:
    v11 = stack[-1];
    if (v11 == nil) goto v100;
    v11 = stack[-1];
    v12 = qcar(v11);
    v11 = stack[0];
    v11 = Lsmemq(nil, v12, v11);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    if (v11 == nil) goto v41;
    v11 = stack[-1];
    v12 = qcar(v11);
    v11 = stack[-2];
    v11 = cons(v12, v11);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    stack[-2] = v11;
    v11 = stack[-1];
    v11 = qcdr(v11);
    stack[-1] = v11;
    goto v74;

v41:
    v11 = stack[-1];
    v11 = qcdr(v11);
    stack[-1] = v11;
    goto v74;

v100:
    v11 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v11);
    }
/* error exit handlers */
v37:
    popv(4);
    return nil;
}



/* Code for plus!: */

static Lisp_Object CC_plusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v339, v340, v341, v342;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v341 = v22;
    v342 = v0;
/* end of prologue */
    v339 = v342;
    v339 = qcdr(v339);
    v340 = qcar(v339);
    stack[-1] = v340;
    v339 = (Lisp_Object)1; /* 0 */
    if (v340 == v339) { popv(6); return onevalue(v341); }
    v339 = v341;
    v339 = qcdr(v339);
    v340 = qcar(v339);
    stack[0] = v340;
    v339 = (Lisp_Object)1; /* 0 */
    if (v340 == v339) { popv(6); return onevalue(v342); }
    v339 = v342;
    v339 = qcdr(v339);
    v339 = qcdr(v339);
    stack[-4] = v339;
    v340 = v341;
    v340 = qcdr(v340);
    v340 = qcdr(v340);
    stack[-2] = v340;
    v340 = difference2(v339, v340);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    stack[-3] = v340;
    v339 = (Lisp_Object)1; /* 0 */
    if (v340 == v339) goto v109;
    v340 = stack[-3];
    v339 = (Lisp_Object)1; /* 0 */
    v339 = (Lisp_Object)greaterp2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v57;
    v339 = v339 ? lisp_true : nil;
    env = stack[-5];
    if (v339 == nil) goto v69;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v340 = stack[-1];
    v339 = stack[-3];
    v340 = Lash1(nil, v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    v339 = stack[0];
    v340 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v57;
    v339 = stack[-2];
    {
        Lisp_Object v58 = stack[-4];
        popv(6);
        return list2star(v58, v340, v339);
    }

v69:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v339 = stack[-3];
    v339 = negate(v339);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    v339 = Lash1(nil, stack[0], v339);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    v340 = plus2(stack[-1], v339);
    nil = C_nil;
    if (exception_pending()) goto v57;
    v339 = stack[-4];
    {
        Lisp_Object v343 = stack[-2];
        popv(6);
        return list2star(v343, v340, v339);
    }

v109:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v340 = stack[-1];
    v339 = stack[0];
    v340 = plus2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v57;
    v339 = stack[-4];
    {
        Lisp_Object v344 = stack[-2];
        popv(6);
        return list2star(v344, v340, v339);
    }
/* error exit handlers */
v57:
    popv(6);
    return nil;
}



/* Code for listsum */

static Lisp_Object CC_listsum(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listsum");
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
    goto v74;

v74:
    v35 = stack[0];
    if (v35 == nil) goto v53;
    v35 = stack[0];
    v36 = qcar(v35);
    v35 = stack[-1];
    v35 = cons(v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    stack[-1] = v35;
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[0] = v35;
    goto v74;

v53:
    v35 = (Lisp_Object)1; /* 0 */
    v36 = v35;
    goto v18;

v18:
    v35 = stack[-1];
    if (v35 == nil) { popv(3); return onevalue(v36); }
    v35 = stack[-1];
    v35 = qcar(v35);
    v35 = plus2(v35, v36);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v36 = v35;
    v35 = stack[-1];
    v35 = qcdr(v35);
    stack[-1] = v35;
    goto v18;
/* error exit handlers */
v46:
    popv(3);
    return nil;
}



/* Code for scalopp */

static Lisp_Object CC_scalopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v334, v355, v356;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scalopp");
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
    v334 = stack[-3];
    if (symbolp(v334)) goto v5;
    v334 = qvalue(elt(env, 1)); /* nil */
    goto v74;

v74:
    if (!(v334 == nil)) { popv(6); return onevalue(v334); }
    v334 = stack[-3];
    if (!consp(v334)) goto v282;
    v334 = stack[-3];
    v355 = qcar(v334);
    v334 = elt(env, 2); /* phystype */
    v355 = get(v355, v334);
    env = stack[-5];
    v334 = elt(env, 3); /* scalar */
    if (v355 == v334) goto v20;
    v334 = stack[-3];
    v355 = qcar(v334);
    v334 = elt(env, 2); /* phystype */
    v355 = get(v355, v334);
    env = stack[-5];
    v334 = elt(env, 5); /* vector */
    if (v355 == v334) goto v103;
    v334 = qvalue(elt(env, 1)); /* nil */
    goto v95;

v95:
    if (!(v334 == nil)) { popv(6); return onevalue(v334); }
    v334 = stack[-3];
    v355 = qcar(v334);
    v334 = elt(env, 2); /* phystype */
    v355 = get(v355, v334);
    env = stack[-5];
    v334 = elt(env, 6); /* tensor */
    if (v355 == v334) goto v127;
    v334 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v334); }

v127:
    v334 = stack[-3];
    v334 = qcdr(v334);
    v356 = Llength(nil, v334);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    v334 = stack[-3];
    v355 = qcar(v334);
    v334 = elt(env, 7); /* tensdimen */
    v334 = get(v355, v334);
    env = stack[-5];
    v334 = (Lisp_Object)geq2(v356, v334);
    nil = C_nil;
    if (exception_pending()) goto v357;
    v334 = v334 ? lisp_true : nil;
    env = stack[-5];
    if (v334 == nil) goto v117;
    v334 = (Lisp_Object)17; /* 1 */
    stack[-4] = v334;
    v334 = stack[-3];
    v355 = qcar(v334);
    v334 = elt(env, 7); /* tensdimen */
    v355 = get(v355, v334);
    env = stack[-5];
    v334 = stack[-4];
    v334 = difference2(v355, v334);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    v334 = Lminusp(nil, v334);
    env = stack[-5];
    if (v334 == nil) goto v62;
    v334 = qvalue(elt(env, 1)); /* nil */
    goto v56;

v56:
    {
        popv(6);
        fn = elt(env, 8); /* areallindices */
        return (*qfn1(fn))(qenv(fn), v334);
    }

v62:
    v334 = stack[-3];
    v355 = qcdr(v334);
    v334 = stack[-4];
    fn = elt(env, 9); /* pnth */
    v334 = (*qfn2(fn))(qenv(fn), v355, v334);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    v334 = qcar(v334);
    v334 = ncons(v334);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    stack[-1] = v334;
    stack[-2] = v334;
    goto v335;

v335:
    v334 = stack[-4];
    v334 = add1(v334);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    stack[-4] = v334;
    v334 = stack[-3];
    v355 = qcar(v334);
    v334 = elt(env, 7); /* tensdimen */
    v355 = get(v355, v334);
    env = stack[-5];
    v334 = stack[-4];
    v334 = difference2(v355, v334);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    v334 = Lminusp(nil, v334);
    env = stack[-5];
    if (v334 == nil) goto v265;
    v334 = stack[-2];
    goto v56;

v265:
    stack[0] = stack[-1];
    v334 = stack[-3];
    v355 = qcdr(v334);
    v334 = stack[-4];
    fn = elt(env, 9); /* pnth */
    v334 = (*qfn2(fn))(qenv(fn), v355, v334);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    v334 = qcar(v334);
    v334 = ncons(v334);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    v334 = Lrplacd(nil, stack[0], v334);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    v334 = stack[-1];
    v334 = qcdr(v334);
    stack[-1] = v334;
    goto v335;

v117:
    v334 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v334); }

v103:
    v334 = stack[-3];
    v334 = qcdr(v334);
    v334 = qcar(v334);
    fn = elt(env, 10); /* isanindex */
    v334 = (*qfn1(fn))(qenv(fn), v334);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    goto v95;

v20:
    v334 = qvalue(elt(env, 4)); /* t */
    { popv(6); return onevalue(v334); }

v282:
    v334 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v334); }

v5:
    v355 = stack[-3];
    v334 = elt(env, 2); /* phystype */
    v355 = get(v355, v334);
    env = stack[-5];
    v334 = elt(env, 3); /* scalar */
    v334 = (v355 == v334 ? lisp_true : nil);
    goto v74;
/* error exit handlers */
v357:
    popv(6);
    return nil;
}



/* Code for sqp */

static Lisp_Object CC_sqp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqp");
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
    v27 = stack[0];
    v27 = Lconsp(nil, v27);
    env = stack[-1];
    if (v27 == nil) goto v4;
    v27 = stack[0];
    v27 = qcar(v27);
    fn = elt(env, 2); /* sfpx */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    if (v27 == nil) goto v44;
    v27 = stack[0];
    v27 = qcdr(v27);
    {
        popv(2);
        fn = elt(env, 2); /* sfpx */
        return (*qfn1(fn))(qenv(fn), v27);
    }

v44:
    v27 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v27); }

v4:
    v27 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v27); }
/* error exit handlers */
v99:
    popv(2);
    return nil;
}



/* Code for mv!-pow!-!+ */

static Lisp_Object CC_mvKpowKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v22;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v74;

v74:
    v42 = stack[-1];
    if (v42 == nil) goto v100;
    v42 = stack[-1];
    v43 = qcar(v42);
    v42 = stack[0];
    v42 = qcar(v42);
    v43 = plus2(v43, v42);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    v42 = stack[-2];
    v42 = cons(v43, v42);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    stack[-2] = v42;
    v42 = stack[-1];
    v42 = qcdr(v42);
    stack[-1] = v42;
    v42 = stack[0];
    v42 = qcdr(v42);
    stack[0] = v42;
    goto v74;

v100:
    v42 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v42);
    }
/* error exit handlers */
v34:
    popv(4);
    return nil;
}



/* Code for subs3f1 */

static Lisp_Object MS_CDECL CC_subs3f1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v22,
                         Lisp_Object v13, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v268, v350, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subs3f1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3f1");
#endif
    if (stack >= stacklimit)
    {
        push3(v13,v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v22,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v13;
    stack[-1] = v22;
    stack[-2] = v0;
/* end of prologue */
    v350 = qvalue(elt(env, 1)); /* nil */
    v268 = (Lisp_Object)17; /* 1 */
    v268 = cons(v350, v268);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    stack[-3] = v268;
    goto v18;

v18:
    v268 = stack[-2];
    if (v268 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v268 = stack[-2];
    if (!consp(v268)) goto v31;
    v268 = stack[-2];
    v268 = qcar(v268);
    v268 = (consp(v268) ? nil : lisp_true);
    goto v30;

v30:
    if (v268 == nil) goto v99;
    stack[0] = stack[-3];
    v350 = stack[-2];
    v268 = (Lisp_Object)17; /* 1 */
    v268 = cons(v350, v268);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    {
        Lisp_Object v85 = stack[0];
        popv(5);
        fn = elt(env, 7); /* addsq */
        return (*qfn2(fn))(qenv(fn), v85, v268);
    }

v99:
    v268 = stack[0];
    if (v268 == nil) goto v50;
    v268 = stack[-2];
    v268 = qcar(v268);
    v268 = qcdr(v268);
    if (!consp(v268)) goto v103;
    v268 = stack[-2];
    v268 = qcar(v268);
    v268 = qcdr(v268);
    v268 = qcar(v268);
    v268 = (consp(v268) ? nil : lisp_true);
    goto v95;

v95:
    if (v268 == nil) goto v50;
    v268 = stack[-2];
    v268 = qcar(v268);
    v350 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v268 = (Lisp_Object)17; /* 1 */
    v268 = cons(v350, v268);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v79 = v268;
    goto v58;

v58:
    v268 = stack[-3];
    v350 = v79;
    fn = elt(env, 7); /* addsq */
    v268 = (*qfn2(fn))(qenv(fn), v268, v350);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    stack[-3] = v268;
    v268 = stack[-2];
    v268 = qcdr(v268);
    stack[-2] = v268;
    goto v18;

v50:
    v268 = stack[-2];
    v350 = qcar(v268);
    v268 = stack[-1];
    fn = elt(env, 8); /* subs3t */
    v268 = (*qfn2(fn))(qenv(fn), v350, v268);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v79 = v268;
    v268 = stack[0];
    if (v268 == nil) goto v119;
    v268 = qvalue(elt(env, 3)); /* mchfg!* */
    v268 = (v268 == nil ? lisp_true : nil);
    goto v118;

v118:
    if (!(v268 == nil)) goto v58;
    v268 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v268; /* mchfg!* */
    v268 = v79;
    v350 = qcar(v268);
    v268 = stack[-2];
    if (equal(v350, v268)) goto v70;
    v268 = qvalue(elt(env, 1)); /* nil */
    goto v323;

v323:
    if (v268 == nil) goto v354;
    v350 = stack[-2];
    v268 = (Lisp_Object)17; /* 1 */
    v268 = cons(v350, v268);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v79 = v268;
    goto v58;

v354:
    v268 = qvalue(elt(env, 4)); /* !*resubs */
    if (v268 == nil) goto v58;
    v268 = qvalue(elt(env, 5)); /* !*sub2 */
    if (!(v268 == nil)) goto v141;
    v268 = qvalue(elt(env, 6)); /* powlis1!* */
    if (!(v268 == nil)) goto v141;

v63:
    v268 = v79;
    fn = elt(env, 9); /* subs3q */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v79 = v268;
    goto v58;

v141:
    v268 = v79;
    fn = elt(env, 10); /* subs2q */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v79 = v268;
    goto v63;

v70:
    v268 = v79;
    v350 = qcdr(v268);
    v268 = (Lisp_Object)17; /* 1 */
    v268 = (v350 == v268 ? lisp_true : nil);
    goto v323;

v119:
    v268 = qvalue(elt(env, 2)); /* t */
    goto v118;

v103:
    v268 = qvalue(elt(env, 2)); /* t */
    goto v95;

v31:
    v268 = qvalue(elt(env, 2)); /* t */
    goto v30;
/* error exit handlers */
v84:
    popv(5);
    return nil;
}



/* Code for gcddd */

static Lisp_Object CC_gcddd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v266, v134, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcddd");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v266 = v22;
    v134 = v0;
/* end of prologue */
    v59 = v134;
    v133 = (Lisp_Object)17; /* 1 */
    if (v59 == v133) goto v100;
    v59 = v266;
    v133 = (Lisp_Object)17; /* 1 */
    v133 = (v59 == v133 ? lisp_true : nil);
    goto v18;

v18:
    if (v133 == nil) goto v74;
    v133 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v133); }

v74:
    v133 = v134;
    if (!consp(v133)) goto v78;
    v133 = v266;
    if (!consp(v133)) goto v118;
    v133 = v134;
    v59 = qcar(v133);
    v133 = elt(env, 2); /* field */
    v133 = Lflagp(nil, v59, v133);
    env = stack[0];
    if (v133 == nil) goto v359;
    v133 = qvalue(elt(env, 1)); /* t */
    goto v69;

v69:
    if (v133 == nil) goto v64;
    v133 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v133); }

v64:
    v133 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v134, v266, v133);
    }

v359:
    v133 = v266;
    v59 = qcar(v133);
    v133 = elt(env, 2); /* field */
    v133 = Lflagp(nil, v59, v133);
    env = stack[0];
    goto v69;

v118:
    v133 = v134;
    v59 = qcar(v133);
    v133 = elt(env, 2); /* field */
    v133 = Lflagp(nil, v59, v133);
    env = stack[0];
    if (v133 == nil) goto v360;
    v133 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v133); }

v360:
    v133 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v134, v266, v133);
    }

v78:
    v133 = v266;
    if (!consp(v133)) goto v33;
    v133 = v266;
    if (!consp(v133)) goto v114;
    v133 = v266;
    v59 = qcar(v133);
    v133 = elt(env, 2); /* field */
    v133 = Lflagp(nil, v59, v133);
    env = stack[0];
    goto v94;

v94:
    if (v133 == nil) goto v49;
    v133 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v133); }

v49:
    v133 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v134, v266, v133);
    }

v114:
    v133 = qvalue(elt(env, 3)); /* nil */
    goto v94;

v33:
    v133 = v134;
        popv(1);
        return Lgcd(nil, v133, v266);

v100:
    v133 = qvalue(elt(env, 1)); /* t */
    goto v18;
}



/* Code for adddummy1a */

static Lisp_Object MS_CDECL CC_adddummy1a(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v22,
                         Lisp_Object v13, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "adddummy1a");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adddummy1a");
#endif
    if (stack >= stacklimit)
    {
        push3(v13,v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v22,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v13;
    v114 = v22;
    stack[-2] = v0;
/* end of prologue */

v53:
    v7 = v114;
    if (v7 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v7 = v114;
    v7 = qcdr(v7);
    stack[-3] = v7;
    v7 = stack[-1];
    if (v7 == nil) goto v99;
    v7 = stack[-1];
    v7 = qcar(v7);
    stack[0] = v7;
    goto v34;

v34:
    v7 = qcar(v114);
    v114 = stack[-2];
    v114 = qcdr(v114);
    fn = elt(env, 1); /* pappl_pv */
    v7 = (*qfn2(fn))(qenv(fn), v7, v114);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-4];
    v114 = stack[-1];
    if (v114 == nil) goto v105;
    v114 = stack[-1];
    v114 = qcdr(v114);
    goto v33;

v33:
    fn = elt(env, 2); /* insert_pv */
    v114 = (*qfn2(fn))(qenv(fn), v7, v114);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-4];
    v114 = cons(stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-4];
    stack[-1] = v114;
    v114 = stack[-3];
    goto v53;

v105:
    v114 = stack[-1];
    goto v33;

v99:
    v7 = stack[-2];
    v7 = qcar(v7);
    stack[0] = v7;
    goto v34;
/* error exit handlers */
v16:
    popv(5);
    return nil;
}



/* Code for idcons_ordp */

static Lisp_Object CC_idcons_ordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v108, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idcons_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v112 = v22;
    v108 = v0;
/* end of prologue */
    v101 = v108;
    v108 = v112;
    v112 = elt(env, 1); /* atom_compare */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v101, v108, v112);
    }
}



/* Code for clear!-column */

static Lisp_Object MS_CDECL CC_clearKcolumn(Lisp_Object env, int nargs,
                         Lisp_Object v22, Lisp_Object v13,
                         Lisp_Object v10, Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v392, v393, v394, v395, v396, v397, v234, v235, v398, v399;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "clear-column");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clear-column");
#endif
    if (stack >= stacklimit)
    {
        push4(v4,v10,v13,v22);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v22,v13,v10,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v10;
    v392 = v13;
    stack[-2] = v22;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* null!-space!-basis */
    qvalue(elt(env, 1)) = nil; /* null!-space!-basis */
    qvalue(elt(env, 1)) = v392; /* null!-space!-basis */
    v392 = (Lisp_Object)1; /* 0 */
    goto v40;

v40:
    v394 = stack[-1];
    v393 = v392;
    v394 = *(Lisp_Object *)((char *)v394 + (CELL-TAG_VECTOR) + ((int32_t)v393/(16/CELL)));
    v393 = stack[-2];
    v394 = *(Lisp_Object *)((char *)v394 + (CELL-TAG_VECTOR) + ((int32_t)v393/(16/CELL)));
    v393 = (Lisp_Object)1; /* 0 */
    if (v394 == v393) goto v1;
    v394 = v392;
    v393 = stack[-2];
    if (((int32_t)(v394)) < ((int32_t)(v393))) goto v19;
    v393 = qvalue(elt(env, 3)); /* nil */
    goto v25;

v25:
    if (v393 == nil) goto v97;
    v394 = (Lisp_Object)((int32_t)(v392) + 0x10);
    v392 = v394;
    v393 = stack[0];
    if (!(((int32_t)(v394)) > ((int32_t)(v393)))) goto v40;
    v393 = stack[-2];
    v392 = qvalue(elt(env, 1)); /* null!-space!-basis */
    v392 = cons(v393, v392);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-4];
    goto v18;

v18:
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    { popv(5); return onevalue(v392); }

v97:
    v394 = stack[-1];
    v393 = v392;
    v393 = *(Lisp_Object *)((char *)v394 + (CELL-TAG_VECTOR) + ((int32_t)v393/(16/CELL)));
    v399 = v393;
    v395 = stack[-1];
    v394 = v392;
    v393 = stack[-1];
    v392 = stack[-2];
    v392 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    *(Lisp_Object *)((char *)v395 + (CELL-TAG_VECTOR) + ((int32_t)v394/(16/CELL))) = v392;
    v393 = stack[-1];
    v392 = stack[-2];
    v394 = v399;
    *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL))) = v394;
    v393 = stack[-1];
    v392 = stack[-2];
    v393 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v392 = stack[-2];
    v392 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v392 = Lmodular_reciprocal(nil, v392);
    nil = C_nil;
    if (exception_pending()) goto v400;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v392);
        if (w != 0) w = current_modulus - w;
        v392 = fixnum_of_int(w);
    }
    v399 = v392;
    v392 = (Lisp_Object)1; /* 0 */
    v398 = v392;
    goto v79;

v79:
    v393 = stack[0];
    v392 = v398;
    v392 = (Lisp_Object)(int32_t)((int32_t)v393 - (int32_t)v392 + TAG_FIXNUM);
    v392 = ((intptr_t)(v392) < 0 ? lisp_true : nil);
    if (v392 == nil) goto v93;
    v392 = stack[-2];
    v396 = v392;
    goto v401;

v401:
    v393 = stack[0];
    v392 = v396;
    v392 = (Lisp_Object)(int32_t)((int32_t)v393 - (int32_t)v392 + TAG_FIXNUM);
    v392 = ((intptr_t)(v392) < 0 ? lisp_true : nil);
    if (v392 == nil) goto v240;
    v392 = qvalue(elt(env, 1)); /* null!-space!-basis */
    goto v18;

v240:
    v393 = stack[-1];
    v392 = stack[-2];
    v395 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v394 = v396;
    v393 = stack[-1];
    v392 = stack[-2];
    v393 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v392 = v396;
    v393 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v392 = v399;
    v392 = Lmodular_times(nil, v393, v392);
    env = stack[-4];
    *(Lisp_Object *)((char *)v395 + (CELL-TAG_VECTOR) + ((int32_t)v394/(16/CELL))) = v392;
    v392 = v396;
    v392 = (Lisp_Object)((int32_t)(v392) + 0x10);
    v396 = v392;
    goto v401;

v93:
    v393 = v398;
    v392 = stack[-2];
    if (equal(v393, v392)) goto v90;
    v393 = stack[-1];
    v392 = v398;
    v393 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v392 = stack[-2];
    v392 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v235 = v392;
    v393 = v235;
    v392 = (Lisp_Object)1; /* 0 */
    if (v393 == v392) goto v90;
    v393 = v235;
    v392 = v399;
    v392 = Lmodular_times(nil, v393, v392);
    env = stack[-4];
    v235 = v392;
    v392 = stack[-2];
    v234 = v392;
    goto v402;

v402:
    v393 = stack[0];
    v392 = v234;
    v392 = (Lisp_Object)(int32_t)((int32_t)v393 - (int32_t)v392 + TAG_FIXNUM);
    v392 = ((intptr_t)(v392) < 0 ? lisp_true : nil);
    if (!(v392 == nil)) goto v90;
    v393 = stack[-1];
    v392 = v398;
    v397 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v396 = v234;
    v393 = stack[-1];
    v392 = v398;
    v393 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v392 = v234;
    v395 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v394 = v235;
    v393 = stack[-1];
    v392 = stack[-2];
    v393 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v392 = v234;
    v392 = *(Lisp_Object *)((char *)v393 + (CELL-TAG_VECTOR) + ((int32_t)v392/(16/CELL)));
    v392 = Lmodular_times(nil, v394, v392);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v395) + int_of_fixnum(v392);
        if (w >= current_modulus) w -= current_modulus;
        v392 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v397 + (CELL-TAG_VECTOR) + ((int32_t)v396/(16/CELL))) = v392;
    v392 = v234;
    v392 = (Lisp_Object)((int32_t)(v392) + 0x10);
    v234 = v392;
    goto v402;

v90:
    v392 = v398;
    v392 = (Lisp_Object)((int32_t)(v392) + 0x10);
    v398 = v392;
    goto v79;

v19:
    v394 = stack[-1];
    v393 = v392;
    v394 = *(Lisp_Object *)((char *)v394 + (CELL-TAG_VECTOR) + ((int32_t)v393/(16/CELL)));
    v393 = v392;
    v394 = *(Lisp_Object *)((char *)v394 + (CELL-TAG_VECTOR) + ((int32_t)v393/(16/CELL)));
    v393 = (Lisp_Object)1; /* 0 */
    v393 = (v394 == v393 ? lisp_true : nil);
    v393 = (v393 == nil ? lisp_true : nil);
    goto v25;

v1:
    v393 = qvalue(elt(env, 2)); /* t */
    goto v25;
/* error exit handlers */
v400:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    popv(5);
    return nil;
}



/* Code for setpage */

static Lisp_Object CC_setpage(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v18;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setpage");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v22;
    v53 = v0;
/* end of prologue */
    qvalue(elt(env, 1)) = v53; /* title!* */
    v53 = v18;
    qvalue(elt(env, 2)) = v53; /* pgnum!* */
    v53 = nil;
    return onevalue(v53);
}



/* Code for mkkl */

static Lisp_Object CC_mkkl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v22)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31, v78;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkkl");
#endif
    if (stack >= stacklimit)
    {
        push2(v22,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v30 = v22;
    v31 = v0;
/* end of prologue */

v74:
    v78 = v31;
    if (v78 == nil) { popv(2); return onevalue(v30); }
    v78 = v31;
    v78 = qcdr(v78);
    stack[0] = v78;
    v31 = qcar(v31);
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-1];
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-1];
    v31 = stack[0];
    goto v74;
/* error exit handlers */
v111:
    popv(2);
    return nil;
}



setup_type const u09_setup[] =
{
    {"covposp",                 CC_covposp,     too_many_1,    wrong_no_1},
    {"opnum*",                  CC_opnumH,      too_many_1,    wrong_no_1},
    {"formcond",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcond},
    {"red-ratios1",             too_few_2,      CC_redKratios1,wrong_no_2},
    {"subsetp",                 too_few_2,      CC_subsetp,    wrong_no_2},
    {"quotk",                   too_few_2,      CC_quotk,      wrong_no_2},
    {"gperm2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm2},
    {"times-in-vector",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_timesKinKvector},
    {"tr_write",                CC_tr_write,    too_many_1,    wrong_no_1},
    {"remflagss",               too_few_2,      CC_remflagss,  wrong_no_2},
    {"msappend",                too_few_2,      CC_msappend,   wrong_no_2},
    {"ibalp_simpat",            CC_ibalp_simpat,too_many_1,    wrong_no_1},
    {"poly-abs",                CC_polyKabs,    too_many_1,    wrong_no_1},
    {"integerom",               CC_integerom,   too_many_1,    wrong_no_1},
    {"ps:putv",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTputv},
    {"maxtype",                 CC_maxtype,     too_many_1,    wrong_no_1},
    {"bsubs",                   CC_bsubs,       too_many_1,    wrong_no_1},
    {"mksgnsq",                 CC_mksgnsq,     too_many_1,    wrong_no_1},
    {"cut:ep",                  too_few_2,      CC_cutTep,     wrong_no_2},
    {"tokquote",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_tokquote},
    {"mo_diff",                 too_few_2,      CC_mo_diff,    wrong_no_2},
    {"pdmult",                  too_few_2,      CC_pdmult,     wrong_no_2},
    {"polynomlistfinddivisor",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_polynomlistfinddivisor},
    {"cancel",                  CC_cancel,      too_many_1,    wrong_no_1},
    {"sfto_tsqsumf",            CC_sfto_tsqsumf,too_many_1,    wrong_no_1},
    {"revv0",                   too_few_2,      CC_revv0,      wrong_no_2},
    {"ibalp_vequal",            too_few_2,      CC_ibalp_vequal,wrong_no_2},
    {"vdp_poly",                CC_vdp_poly,    too_many_1,    wrong_no_1},
    {"naryrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_naryrd},
    {"simpexpon1",              too_few_2,      CC_simpexpon1, wrong_no_2},
    {"simp",                    CC_simp,        too_many_1,    wrong_no_1},
    {"zeropp",                  CC_zeropp,      too_many_1,    wrong_no_1},
    {"gpexp1p",                 CC_gpexp1p,     too_many_1,    wrong_no_1},
    {"mo=lexcomp",              too_few_2,      CC_moMlexcomp, wrong_no_2},
    {"arintequiv:",             CC_arintequivT, too_many_1,    wrong_no_1},
    {"horner-rule",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKrule},
    {"crprcd2",                 too_few_2,      CC_crprcd2,    wrong_no_2},
    {"rempropss",               too_few_2,      CC_rempropss,  wrong_no_2},
    {"qqe_arg-check-b",         CC_qqe_argKcheckKb,too_many_1, wrong_no_1},
    {"ibalp_vmember",           too_few_2,      CC_ibalp_vmember,wrong_no_2},
    {"aex_reducedtag",          CC_aex_reducedtag,too_many_1,  wrong_no_1},
    {"diffp1",                  too_few_2,      CC_diffp1,     wrong_no_2},
    {"omiir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omiir},
    {"testredh",                CC_testredh,    too_many_1,    wrong_no_1},
    {"getrtype1",               CC_getrtype1,   too_many_1,    wrong_no_1},
    {"mkuwedge",                CC_mkuwedge,    too_many_1,    wrong_no_1},
    {"smemql",                  too_few_2,      CC_smemql,     wrong_no_2},
    {"plus:",                   too_few_2,      CC_plusT,      wrong_no_2},
    {"listsum",                 CC_listsum,     too_many_1,    wrong_no_1},
    {"scalopp",                 CC_scalopp,     too_many_1,    wrong_no_1},
    {"sqp",                     CC_sqp,         too_many_1,    wrong_no_1},
    {"mv-pow-+",                too_few_2,      CC_mvKpowKL,   wrong_no_2},
    {"subs3f1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subs3f1},
    {"gcddd",                   too_few_2,      CC_gcddd,      wrong_no_2},
    {"adddummy1a",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_adddummy1a},
    {"idcons_ordp",             too_few_2,      CC_idcons_ordp,wrong_no_2},
    {"clear-column",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_clearKcolumn},
    {"setpage",                 too_few_2,      CC_setpage,    wrong_no_2},
    {"mkkl",                    too_few_2,      CC_mkkl,       wrong_no_2},
    {NULL, (one_args *)"u09", (two_args *)"1781 5388860 7625525", 0}
};

/* end of generated code */
