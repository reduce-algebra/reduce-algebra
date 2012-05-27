
/* $destdir\u43.c        Machine generated C code */

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


/* Code for factor!-prim!-f */

static Lisp_Object CC_factorKprimKf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factor-prim-f");
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
    stack[-1] = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v48 = qvalue(elt(env, 1)); /* ncmp!* */
    if (v48 == nil) goto v51;
    stack[0] = (Lisp_Object)17; /* 1 */
    v49 = stack[-1];
    v48 = (Lisp_Object)17; /* 1 */
    v48 = cons(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    {
        Lisp_Object v53 = stack[0];
        popv(5);
        return list2(v53, v48);
    }

v51:
    v48 = qvalue(elt(env, 2)); /* dmode!* */
    if (v48 == nil) goto v54;
    v49 = qvalue(elt(env, 2)); /* dmode!* */
    v48 = elt(env, 3); /* sqfrfactorfn */
    v48 = get(v49, v48);
    env = stack[-4];
    stack[-2] = v48;
    if (v48 == nil) goto v54;
    v48 = qvalue(elt(env, 4)); /* !*factor */
    if (v48 == nil) goto v55;
    v49 = stack[-2];
    v48 = stack[-1];
    v48 = Lapply1(nil, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[0] = v48;
    goto v56;

v56:
    v48 = stack[-2];
    if (v48 == nil) goto v57;
    v50 = stack[-2];
    v49 = qvalue(elt(env, 2)); /* dmode!* */
    v48 = elt(env, 8); /* factorfn */
    v48 = get(v49, v48);
    env = stack[-4];
    if (v50 == v48) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    else goto v57;

v57:
    v48 = stack[0];
    v48 = qcar(v48);
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[-3] = v48;
    v48 = stack[0];
    v48 = qcdr(v48);
    stack[-2] = v48;
    goto v58;

v58:
    v48 = stack[-2];
    if (v48 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v48 = stack[-2];
    v48 = qcar(v48);
    fn = elt(env, 9); /* factor!-prim!-sqfree!-f */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[-1] = v48;
    v48 = stack[-1];
    v49 = qcar(v48);
    v48 = stack[-3];
    v48 = qcar(v48);
    fn = elt(env, 10); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v48 = stack[-1];
    v49 = qcdr(v48);
    v48 = stack[-3];
    v48 = qcdr(v48);
    v48 = Lappend(nil, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v48 = cons(stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[-3] = v48;
    v48 = stack[-2];
    v48 = qcdr(v48);
    stack[-2] = v48;
    goto v58;

v55:
    stack[0] = (Lisp_Object)17; /* 1 */
    v49 = stack[-1];
    v48 = (Lisp_Object)17; /* 1 */
    v48 = cons(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v48 = list2(stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[0] = v48;
    goto v56;

v54:
    v49 = qvalue(elt(env, 2)); /* dmode!* */
    v48 = elt(env, 5); /* field */
    v48 = Lflagp(nil, v49, v48);
    env = stack[-4];
    if (v48 == nil) goto v59;
    v48 = stack[-1];
    fn = elt(env, 11); /* lnc */
    v49 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[-3] = v49;
    v48 = (Lisp_Object)17; /* 1 */
    v48 = Lneq(nil, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    goto v60;

v60:
    if (v48 == nil) goto v61;
    stack[0] = stack[-3];
    v48 = stack[-3];
    fn = elt(env, 12); /* !:recip */
    v49 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v48 = stack[-1];
    fn = elt(env, 13); /* multd */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    fn = elt(env, 14); /* sqfrf */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v48 = cons(stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[0] = v48;
    goto v56;

v61:
    v49 = qvalue(elt(env, 2)); /* dmode!* */
    v48 = elt(env, 7); /* units */
    v48 = get(v49, v48);
    env = stack[-4];
    stack[-3] = v48;
    if (v48 == nil) goto v62;
    v48 = stack[-1];
    fn = elt(env, 11); /* lnc */
    v49 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v50 = v49;
    v48 = stack[-3];
    v48 = Lassoc(nil, v49, v48);
    stack[-3] = v48;
    if (v48 == nil) goto v62;
    stack[0] = v50;
    v48 = stack[-3];
    v49 = qcdr(v48);
    v48 = stack[-1];
    fn = elt(env, 13); /* multd */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    fn = elt(env, 14); /* sqfrf */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v48 = cons(stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[0] = v48;
    goto v56;

v62:
    stack[0] = (Lisp_Object)17; /* 1 */
    v48 = stack[-1];
    fn = elt(env, 14); /* sqfrf */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v48 = cons(stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[0] = v48;
    goto v56;

v59:
    v48 = qvalue(elt(env, 6)); /* nil */
    goto v60;
/* error exit handlers */
v52:
    popv(5);
    return nil;
}



/* Code for vdplsort */

static Lisp_Object CC_vdplsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdplsort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v64 = v0;
/* end of prologue */
    v65 = v64;
    v64 = elt(env, 1); /* vdpvevlcomp */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v65, v64);
    }
}



/* Code for xpartitsq */

static Lisp_Object CC_xpartitsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v90, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpartitsq");
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
    v91 = v0;
/* end of prologue */
    v89 = v91;
    v90 = qcar(v89);
    v89 = v91;
    v89 = qcdr(v89);
    stack[-2] = v90;
    stack[-1] = v89;
    v89 = stack[-2];
    if (v89 == nil) goto v64;
    v89 = stack[-2];
    if (!consp(v89)) goto v92;
    v89 = stack[-2];
    v89 = qcar(v89);
    v89 = (consp(v89) ? nil : lisp_true);
    goto v93;

v93:
    if (v89 == nil) goto v94;
    v89 = (Lisp_Object)17; /* 1 */
    v90 = v91;
    v89 = cons(v89, v90);
    nil = C_nil;
    if (exception_pending()) goto v95;
    popv(4);
    return ncons(v89);

v94:
    v89 = stack[-2];
    v89 = qcar(v89);
    v89 = qcar(v89);
    v89 = qcar(v89);
    if (!consp(v89)) goto v96;
    v89 = stack[-2];
    v89 = qcar(v89);
    v89 = qcar(v89);
    v89 = qcar(v89);
    v89 = qcar(v89);
    v89 = (consp(v89) ? nil : lisp_true);
    v89 = (v89 == nil ? lisp_true : nil);
    goto v97;

v97:
    if (v89 == nil) goto v98;
    v89 = stack[-2];
    v89 = qcar(v89);
    v89 = qcar(v89);
    v90 = qcar(v89);
    v89 = (Lisp_Object)17; /* 1 */
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v90 = CC_xpartitsq(env, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v89 = stack[-2];
    v89 = qcar(v89);
    v89 = qcar(v89);
    v89 = qcdr(v89);
    fn = elt(env, 3); /* xexptpf */
    stack[0] = (*qfn2(fn))(qenv(fn), v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v89 = stack[-2];
    v89 = qcar(v89);
    v90 = qcdr(v89);
    v89 = stack[-1];
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    fn = elt(env, 4); /* cancel */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v89 = CC_xpartitsq(env, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    fn = elt(env, 5); /* wedgepf */
    v89 = (*qfn2(fn))(qenv(fn), stack[0], v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    stack[0] = v89;
    goto v99;

v99:
    v89 = stack[-2];
    v90 = qcdr(v89);
    v89 = stack[-1];
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v89 = CC_xpartitsq(env, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    {
        Lisp_Object v100 = stack[0];
        popv(4);
        fn = elt(env, 6); /* addpf */
        return (*qfn2(fn))(qenv(fn), v100, v89);
    }

v98:
    v89 = stack[-2];
    v89 = qcar(v89);
    v89 = qcar(v89);
    v89 = qcar(v89);
    fn = elt(env, 7); /* xvarp */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    if (v89 == nil) goto v62;
    v89 = stack[-2];
    v89 = qcar(v89);
    v89 = qcar(v89);
    v89 = qcar(v89);
    fn = elt(env, 8); /* xpartitk */
    v90 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v89 = stack[-2];
    v89 = qcar(v89);
    v89 = qcar(v89);
    v89 = qcdr(v89);
    fn = elt(env, 3); /* xexptpf */
    stack[0] = (*qfn2(fn))(qenv(fn), v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v89 = stack[-2];
    v89 = qcar(v89);
    v90 = qcdr(v89);
    v89 = stack[-1];
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    fn = elt(env, 4); /* cancel */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v89 = CC_xpartitsq(env, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    fn = elt(env, 5); /* wedgepf */
    v89 = (*qfn2(fn))(qenv(fn), stack[0], v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    stack[0] = v89;
    goto v99;

v62:
    v89 = stack[-2];
    v89 = qcar(v89);
    v90 = qcdr(v89);
    v89 = stack[-1];
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    fn = elt(env, 4); /* cancel */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    stack[0] = CC_xpartitsq(env, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v89 = stack[-2];
    v89 = qcar(v89);
    v90 = qcar(v89);
    v89 = (Lisp_Object)17; /* 1 */
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v90 = ncons(v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v89 = (Lisp_Object)17; /* 1 */
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    fn = elt(env, 9); /* multpfsq */
    v89 = (*qfn2(fn))(qenv(fn), stack[0], v89);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    stack[0] = v89;
    goto v99;

v96:
    v89 = qvalue(elt(env, 1)); /* nil */
    goto v97;

v92:
    v89 = qvalue(elt(env, 2)); /* t */
    goto v93;

v64:
    v89 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v89); }
/* error exit handlers */
v95:
    popv(4);
    return nil;
}



/* Code for latexprin */

static Lisp_Object CC_latexprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v87, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for latexprin");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v107 = v0;
/* end of prologue */
    v87 = v107;
    v86 = elt(env, 1); /* tex */
    if (!consp(v87)) goto v47;
    v87 = qcar(v87);
    if (!(v87 == v86)) goto v47;
    v86 = v107;
    v86 = qcdr(v86);
    v87 = qcar(v86);
    v86 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 2); /* maprintla */
        return (*qfn2(fn))(qenv(fn), v87, v86);
    }

v47:
    v87 = v107;
    v86 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 2); /* maprintla */
        return (*qfn2(fn))(qenv(fn), v87, v86);
    }
}



/* Code for chksymmetries!&subst */

static Lisp_Object MS_CDECL CC_chksymmetriesGsubst(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v108,
                         Lisp_Object v10, Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v117, v31, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "chksymmetries&subst");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chksymmetries&subst");
#endif
    if (stack >= stacklimit)
    {
        push4(v5,v10,v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v108,v10,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v5;
    stack[-1] = v10;
    stack[-2] = v108;
    stack[-3] = v0;
/* end of prologue */

v118:
    v116 = stack[-1];
    if (v116 == nil) goto v68;
    v60 = stack[-3];
    v31 = stack[-2];
    v116 = stack[-1];
    v117 = qcar(v116);
    v116 = stack[0];
    fn = elt(env, 2); /* chksymmetries!&sub1 */
    v116 = (*qfnn(fn))(qenv(fn), 4, v60, v31, v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    v117 = v116;
    v116 = v117;
    if (v116 == nil) goto v55;
    stack[-4] = v117;
    v60 = stack[-3];
    v31 = stack[-2];
    v116 = stack[-1];
    v117 = qcdr(v116);
    v116 = stack[0];
    v116 = CC_chksymmetriesGsubst(env, 4, v60, v31, v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v119;
    {
        Lisp_Object v120 = stack[-4];
        popv(6);
        return cons(v120, v116);
    }

v55:
    v60 = stack[-3];
    v31 = stack[-2];
    v116 = stack[-1];
    v117 = qcdr(v116);
    v116 = stack[0];
    stack[-3] = v60;
    stack[-2] = v31;
    stack[-1] = v117;
    stack[0] = v116;
    goto v118;

v68:
    v116 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v116); }
/* error exit handlers */
v119:
    popv(6);
    return nil;
}



/* Code for mk_world1 */

static Lisp_Object MS_CDECL CC_mk_world1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v108,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v93, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk_world1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_world1");
#endif
    if (stack >= stacklimit)
    {
        push3(v10,v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v108,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v108;
    v88 = v0;
/* end of prologue */
    fn = elt(env, 1); /* map_2_from_map_1 */
    v92 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v123;
    v93 = stack[-1];
    v88 = stack[0];
    popv(2);
    return list3(v92, v93, v88);
/* error exit handlers */
v123:
    popv(2);
    return nil;
}



/* Code for bc_power */

static Lisp_Object CC_bc_power(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_power");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v106 = v108;
    v105 = v0;
/* end of prologue */
    fn = elt(env, 1); /* exptf */
    v106 = (*qfn2(fn))(qenv(fn), v105, v106);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v106);
    }
/* error exit handlers */
v121:
    popv(1);
    return nil;
}



/* Code for gd_simpl */

static Lisp_Object CC_gd_simpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v103, v104, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gd_simpl");
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
    v113 = v0;
/* end of prologue */
    v104 = qvalue(elt(env, 1)); /* nil */
    v103 = qvalue(elt(env, 2)); /* t */
    v123 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* !*guardian */
    qvalue(elt(env, 3)) = v104; /* !*guardian */
    stack[-1] = qvalue(elt(env, 4)); /* !*rlnzden */
    qvalue(elt(env, 4)) = v103; /* !*rlnzden */
    stack[0] = qvalue(elt(env, 5)); /* !*rladdcond */
    qvalue(elt(env, 5)) = v123; /* !*rladdcond */
    v123 = v113;
    fn = elt(env, 6); /* rl_simp */
    v104 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    v103 = qvalue(elt(env, 1)); /* nil */
    v123 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 7); /* rl_simpl */
    v123 = (*qfnn(fn))(qenv(fn), 3, v104, v103, v123);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    fn = elt(env, 8); /* rl_prepfof */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; /* !*rladdcond */
    qvalue(elt(env, 4)) = stack[-1]; /* !*rlnzden */
    qvalue(elt(env, 3)) = stack[-2]; /* !*guardian */
    { popv(4); return onevalue(v123); }
/* error exit handlers */
v112:
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; /* !*rladdcond */
    qvalue(elt(env, 4)) = stack[-1]; /* !*rlnzden */
    qvalue(elt(env, 3)) = stack[-2]; /* !*guardian */
    popv(4);
    return nil;
}



/* Code for !*ff2a */

static Lisp_Object CC_Hff2a(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *ff2a");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v94 = v108;
    v109 = v0;
/* end of prologue */
    v94 = cons(v109, v94);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[0];
    fn = elt(env, 3); /* cancel */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[0];
    v109 = v94;
    v94 = qvalue(elt(env, 1)); /* wtl!* */
    if (v94 == nil) goto v87;
    v94 = v109;
    v94 = qcar(v94);
    if (v94 == nil) goto v44;
    v94 = elt(env, 2); /* prepf */
    {
        popv(1);
        fn = elt(env, 4); /* sqform */
        return (*qfn2(fn))(qenv(fn), v109, v94);
    }

v44:
    v94 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v94); }

v87:
    v94 = v109;
    {
        popv(1);
        fn = elt(env, 5); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v94);
    }
/* error exit handlers */
v42:
    popv(1);
    return nil;
}



/* Code for cl_applysac */

static Lisp_Object CC_cl_applysac(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v125, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_applysac");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    v125 = v0;
/* end of prologue */
    v114 = nil;
    stack[-1] = v125;
    goto v65;

v65:
    v125 = stack[-1];
    if (v125 == nil) { popv(3); return onevalue(v114); }
    v125 = stack[-1];
    v38 = qcar(v125);
    v125 = v114;
    v114 = stack[0];
    fn = elt(env, 3); /* cl_applysac1 */
    v114 = (*qfnn(fn))(qenv(fn), 3, v38, v125, v114);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    v38 = v114;
    v125 = v38;
    v114 = elt(env, 2); /* break */
    if (v125 == v114) goto v101;
    v114 = stack[-1];
    v114 = qcdr(v114);
    stack[-1] = v114;
    v114 = v38;
    v114 = qcar(v114);
    if (v114 == nil) goto v36;
    v114 = v38;
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v125 = v38;
    v125 = qcdr(v125);
    v114 = cons(v114, v125);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    goto v65;

v36:
    v114 = v38;
    v114 = qcdr(v114);
    goto v65;

v101:
    v114 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v114;
    v114 = elt(env, 2); /* break */
    goto v65;
/* error exit handlers */
v117:
    popv(3);
    return nil;
}



/* Code for xpdiff */

static Lisp_Object CC_xpdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    stack[-1] = v0;
/* end of prologue */
    v54 = stack[-1];
    if (v54 == nil) goto v22;
    v54 = stack[0];
    if (v54 == nil) goto v92;
    v54 = stack[0];
    v129 = qcar(v54);
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = (Lisp_Object)greaterp2(v129, v54);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v54 = v54 ? lisp_true : nil;
    env = stack[-3];
    if (v54 == nil) goto v94;
    v54 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v54); }

v94:
    v54 = stack[-1];
    v129 = qcdr(v54);
    v54 = stack[0];
    v54 = qcdr(v54);
    v54 = CC_xpdiff(env, v129, v54);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    stack[-2] = v54;
    v129 = stack[-2];
    v54 = elt(env, 4); /* failed */
    if (v129 == v54) goto v111;
    v54 = stack[-1];
    v129 = qcar(v54);
    v54 = stack[0];
    v54 = qcar(v54);
    v129 = difference2(v129, v54);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v54 = stack[-2];
    popv(4);
    return cons(v129, v54);

v111:
    v54 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v54); }

v92:
    v54 = elt(env, 3); /* "A too long in xpdiff" */
    {
        popv(4);
        fn = elt(env, 5); /* interr */
        return (*qfn1(fn))(qenv(fn), v54);
    }

v22:
    v54 = stack[0];
    if (v54 == nil) goto v64;
    v54 = elt(env, 2); /* "B too long in xpdiff" */
    {
        popv(4);
        fn = elt(env, 5); /* interr */
        return (*qfn1(fn))(qenv(fn), v54);
    }

v64:
    v54 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v54); }
/* error exit handlers */
v34:
    popv(4);
    return nil;
}



/* Code for ps!:constmult!-erule */

static Lisp_Object CC_psTconstmultKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v113, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:constmult-erule");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v113 = v108;
    v130 = v0;
/* end of prologue */
    v104 = v130;
    v104 = qcdr(v104);
    stack[0] = qcar(v104);
    v104 = v130;
    v104 = qcdr(v104);
    v104 = qcdr(v104);
    v104 = qcar(v104);
    fn = elt(env, 1); /* ps!:evaluate */
    v104 = (*qfn2(fn))(qenv(fn), v104, v113);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    {
        Lisp_Object v112 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v112, v104);
    }
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for ldf!-deg */

static Lisp_Object CC_ldfKdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-deg");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v108;
    v133 = v0;
/* end of prologue */
    stack[-4] = v133;
    v133 = stack[-4];
    if (v133 == nil) goto v105;
    v133 = stack[-4];
    v133 = qcar(v133);
    v124 = qcdr(v133);
    v133 = stack[-3];
    fn = elt(env, 2); /* degreef */
    v133 = (*qfn2(fn))(qenv(fn), v124, v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v133 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[-1] = v133;
    stack[-2] = v133;
    goto v51;

v51:
    v133 = stack[-4];
    v133 = qcdr(v133);
    stack[-4] = v133;
    v133 = stack[-4];
    if (v133 == nil) goto v86;
    stack[0] = stack[-1];
    v133 = stack[-4];
    v133 = qcar(v133);
    v124 = qcdr(v133);
    v133 = stack[-3];
    fn = elt(env, 2); /* degreef */
    v133 = (*qfn2(fn))(qenv(fn), v124, v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v133 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v133 = Lrplacd(nil, stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v133 = stack[-1];
    v133 = qcdr(v133);
    stack[-1] = v133;
    goto v51;

v86:
    v133 = stack[-2];
    goto v63;

v63:
    {
        popv(6);
        fn = elt(env, 3); /* maxl */
        return (*qfn1(fn))(qenv(fn), v133);
    }

v105:
    v133 = qvalue(elt(env, 1)); /* nil */
    goto v63;
/* error exit handlers */
v134:
    popv(6);
    return nil;
}



/* Code for groebinvokecritm */

static Lisp_Object CC_groebinvokecritm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebinvokecritm");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v108;
    stack[-2] = v0;
/* end of prologue */
    v66 = stack[-1];
    stack[-3] = v66;
    goto v69;

v69:
    v66 = stack[-3];
    if (v66 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v66 = stack[-3];
    v66 = qcar(v66);
    stack[0] = v66;
    v66 = stack[-2];
    v128 = qcar(v66);
    v66 = stack[0];
    v66 = qcar(v66);
    fn = elt(env, 3); /* buchvevdivides!? */
    v66 = (*qfn2(fn))(qenv(fn), v128, v66);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    if (v66 == nil) goto v92;
    v66 = qvalue(elt(env, 2)); /* mcount!* */
    v66 = add1(v66);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    qvalue(elt(env, 2)) = v66; /* mcount!* */
    v128 = stack[0];
    v66 = stack[-1];
    fn = elt(env, 4); /* groedeletip */
    v66 = (*qfn2(fn))(qenv(fn), v128, v66);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    stack[-1] = v66;
    goto v92;

v92:
    v66 = stack[-3];
    v66 = qcdr(v66);
    stack[-3] = v66;
    goto v69;
/* error exit handlers */
v136:
    popv(5);
    return nil;
}



/* Code for wedgewedge */

static Lisp_Object CC_wedgewedge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v84, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgewedge");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v68;

v68:
    v83 = stack[-1];
    v83 = qcdr(v83);
    if (v83 == nil) goto v85;
    v83 = stack[-1];
    v140 = qcar(v83);
    v84 = (Lisp_Object)17; /* 1 */
    v83 = (Lisp_Object)17; /* 1 */
    v140 = list2star(v140, v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    v84 = qvalue(elt(env, 1)); /* nil */
    v83 = stack[-2];
    v83 = acons(v140, v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    stack[-2] = v83;
    v83 = stack[-1];
    v83 = qcdr(v83);
    stack[-1] = v83;
    goto v68;

v85:
    v83 = stack[-1];
    v140 = qcar(v83);
    v84 = (Lisp_Object)17; /* 1 */
    v83 = (Lisp_Object)17; /* 1 */
    v83 = list2star(v140, v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    stack[-1] = ncons(v83);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    v140 = stack[0];
    v84 = (Lisp_Object)17; /* 1 */
    v83 = (Lisp_Object)17; /* 1 */
    v83 = list2star(v140, v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    v83 = ncons(v83);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    fn = elt(env, 2); /* wedgepf2 */
    v83 = (*qfn2(fn))(qenv(fn), stack[-1], v83);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    v84 = v83;
    goto v51;

v51:
    v83 = stack[-2];
    if (v83 == nil) { popv(4); return onevalue(v84); }
    v83 = stack[-2];
    v83 = qcar(v83);
    fn = elt(env, 2); /* wedgepf2 */
    v83 = (*qfn2(fn))(qenv(fn), v83, v84);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    v84 = v83;
    v83 = stack[-2];
    v83 = qcdr(v83);
    stack[-2] = v83;
    goto v51;
/* error exit handlers */
v80:
    popv(4);
    return nil;
}



/* Code for listnoeval */

static Lisp_Object CC_listnoeval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v130;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listnoeval");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v130 = v108;
    v113 = v0;
/* end of prologue */

v22:
    v130 = v113;
    if (!(!consp(v130))) { popv(1); return onevalue(v113); }
    v130 = v113;
    v113 = elt(env, 1); /* avalue */
    v113 = get(v130, v113);
    env = stack[0];
    v113 = qcdr(v113);
    v113 = qcar(v113);
    goto v22;
}



/* Code for delete_edge */

static Lisp_Object CC_delete_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v97, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delete_edge");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    stack[-1] = v0;
/* end of prologue */
    v136 = nil;
    goto v69;

v69:
    v85 = stack[0];
    if (v85 == nil) goto v51;
    v85 = stack[-1];
    v97 = qcar(v85);
    v85 = stack[0];
    v85 = qcar(v85);
    v85 = qcar(v85);
    if (v97 == v85) goto v47;
    v85 = stack[0];
    v85 = qcar(v85);
    v97 = v136;
    v85 = cons(v85, v97);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    v136 = v85;
    v85 = stack[0];
    v85 = qcdr(v85);
    stack[0] = v85;
    goto v69;

v47:
    v97 = v136;
    v85 = stack[0];
    v85 = qcdr(v85);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v97, v85);
    }

v51:
    v85 = v136;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v85);
    }
/* error exit handlers */
v141:
    popv(3);
    return nil;
}



/* Code for reduce!-columns */

static Lisp_Object MS_CDECL CC_reduceKcolumns(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v108,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce-columns");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-columns");
#endif
    if (stack >= stacklimit)
    {
        push3(v10,v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v108,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v10;
    stack[-5] = v108;
    stack[-6] = v0;
/* end of prologue */
    v148 = stack[-6];
    stack[-3] = v148;
    v148 = stack[-5];
    stack[-2] = v148;
    stack[0] = stack[-6];
    v149 = stack[-6];
    v148 = stack[-4];
    fn = elt(env, 3); /* red!-weight */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    v148 = cons(stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    stack[-7] = v148;
    goto v65;

v65:
    v148 = stack[-3];
    if (v148 == nil) goto v151;
    v148 = stack[-3];
    v149 = qcar(v148);
    v148 = (Lisp_Object)1; /* 0 */
    if (v149 == v148) goto v109;
    v148 = stack[-2];
    v149 = qcar(v148);
    v148 = (Lisp_Object)1; /* 0 */
    v148 = (v149 == v148 ? lisp_true : nil);
    goto v94;

v94:
    if (!(v148 == nil)) goto v135;
    v148 = stack[-3];
    v149 = qcar(v148);
    v148 = stack[-2];
    v148 = qcar(v148);
    v148 = Ldivide(nil, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    stack[-1] = v148;
    v149 = qcdr(v148);
    v148 = (Lisp_Object)1; /* 0 */
    if (!(v149 == v148)) goto v135;
    stack[0] = stack[-6];
    v148 = stack[-1];
    v149 = qcar(v148);
    v148 = stack[-5];
    fn = elt(env, 4); /* mv!-domainlist!-!* */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    fn = elt(env, 5); /* mv!-domainlist!-!- */
    v148 = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    stack[-1] = v148;
    v149 = stack[-1];
    v148 = stack[-4];
    fn = elt(env, 3); /* red!-weight */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    stack[0] = v148;
    v149 = stack[0];
    v148 = stack[-7];
    v148 = qcdr(v148);
    fn = elt(env, 6); /* red!-weight!-less!-p */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    if (v148 == nil) goto v135;
    v149 = stack[-1];
    v148 = stack[0];
    v149 = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    v148 = stack[-7];
    fn = elt(env, 7); /* more!-apartp */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    if (!(v148 == nil)) goto v135;
    v149 = stack[-1];
    v148 = stack[0];
    v148 = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-8];
    stack[-7] = v148;
    goto v135;

v135:
    v148 = stack[-3];
    v148 = qcdr(v148);
    stack[-3] = v148;
    v148 = stack[-2];
    v148 = qcdr(v148);
    stack[-2] = v148;
    goto v65;

v109:
    v148 = qvalue(elt(env, 1)); /* t */
    goto v94;

v151:
    v148 = stack[-7];
    v148 = qcar(v148);
    { popv(9); return onevalue(v148); }
/* error exit handlers */
v150:
    popv(9);
    return nil;
}



/* Code for dp_prod */

static Lisp_Object CC_dp_prod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_prod");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    stack[-1] = v0;
/* end of prologue */
    v87 = stack[-1];
    stack[-2] = Llength(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    v87 = stack[0];
    v87 = Llength(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    v87 = (Lisp_Object)lesseq2(stack[-2], v87);
    nil = C_nil;
    if (exception_pending()) goto v109;
    v87 = v87 ? lisp_true : nil;
    env = stack[-3];
    if (v87 == nil) goto v112;
    v107 = stack[-1];
    v87 = stack[0];
    {
        popv(4);
        fn = elt(env, 1); /* dp!=prod */
        return (*qfn2(fn))(qenv(fn), v107, v87);
    }

v112:
    v107 = stack[0];
    v87 = stack[-1];
    {
        popv(4);
        fn = elt(env, 1); /* dp!=prod */
        return (*qfn2(fn))(qenv(fn), v107, v87);
    }
/* error exit handlers */
v109:
    popv(4);
    return nil;
}



/* Code for partsym_zerop */

static Lisp_Object CC_partsym_zerop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v97, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partsym_zerop");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    stack[-1] = v0;
/* end of prologue */

v118:
    v85 = stack[-1];
    if (v85 == nil) goto v22;
    v85 = stack[-1];
    v85 = qcar(v85);
    fn = elt(env, 3); /* repeats */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    v136 = v85;
    v85 = stack[0];
    v97 = qcar(v85);
    v85 = elt(env, 2); /* !- */
    if (v97 == v85) goto v123;
    v85 = qvalue(elt(env, 1)); /* nil */
    goto v44;

v44:
    if (!(v85 == nil)) { popv(3); return onevalue(v136); }
    v85 = stack[-1];
    v97 = qcdr(v85);
    v85 = stack[0];
    v85 = qcdr(v85);
    stack[-1] = v97;
    stack[0] = v85;
    goto v118;

v123:
    v85 = v136;
    goto v44;

v22:
    v85 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v85); }
/* error exit handlers */
v141:
    popv(3);
    return nil;
}



/* Code for general!-minus!-mod!-p */

static Lisp_Object CC_generalKminusKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-minus-mod-p");
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
    stack[-2] = nil;
    goto v22;

v22:
    v119 = stack[-1];
    if (v119 == nil) goto v63;
    v119 = stack[-1];
    if (!consp(v119)) goto v93;
    v119 = stack[-1];
    v119 = qcar(v119);
    v119 = (consp(v119) ? nil : lisp_true);
    goto v88;

v88:
    if (v119 == nil) goto v37;
    v120 = stack[-1];
    v119 = (Lisp_Object)1; /* 0 */
    if (v120 == v119) goto v147;
    stack[0] = stack[-2];
    v120 = qvalue(elt(env, 2)); /* current!-modulus */
    v119 = stack[-1];
    v119 = difference2(v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    {
        Lisp_Object v83 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v83, v119);
    }

v147:
    v120 = stack[-2];
    v119 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v120, v119);
    }

v37:
    v119 = stack[-1];
    v119 = qcar(v119);
    stack[0] = qcar(v119);
    v119 = stack[-1];
    v119 = qcar(v119);
    v119 = qcdr(v119);
    v120 = CC_generalKminusKmodKp(env, v119);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    v119 = stack[-2];
    v119 = acons(stack[0], v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    stack[-2] = v119;
    v119 = stack[-1];
    v119 = qcdr(v119);
    stack[-1] = v119;
    goto v22;

v93:
    v119 = qvalue(elt(env, 1)); /* t */
    goto v88;

v63:
    v119 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v119);
    }
/* error exit handlers */
v153:
    popv(4);
    return nil;
}



/* Code for ofsf_qesubiord */

static Lisp_Object MS_CDECL CC_ofsf_qesubiord(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v108,
                         Lisp_Object v10, Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v47, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_qesubiord");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_qesubiord");
#endif
    if (stack >= stacklimit)
    {
        push4(v5,v10,v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v108,v10,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v5;
    stack[-1] = v10;
    v46 = v108;
    v47 = v0;
/* end of prologue */
    stack[-2] = v47;
    v47 = v46;
    v46 = stack[-1];
    fn = elt(env, 1); /* sfto_reorder */
    v112 = (*qfn2(fn))(qenv(fn), v47, v46);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-3];
    v47 = stack[-1];
    v46 = stack[0];
    {
        Lisp_Object v102 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* ofsf_qesubiord1 */
        return (*qfnn(fn))(qenv(fn), 4, v102, v112, v47, v46);
    }
/* error exit handlers */
v101:
    popv(4);
    return nil;
}



/* Code for get!*real!*irreducible!*rep */

static Lisp_Object CC_getHrealHirreducibleHrep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*real*irreducible*rep");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    stack[-1] = v0;
/* end of prologue */
    v135 = stack[-1];
    stack[-2] = ncons(v135);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    v151 = elt(env, 1); /* realrep */
    v135 = stack[0];
    fn = elt(env, 2); /* mkid */
    v135 = (*qfn2(fn))(qenv(fn), v151, v135);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    v135 = get(stack[-1], v135);
    env = stack[-3];
    v135 = qcdr(v135);
    v135 = Lappend(nil, stack[-2], v135);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 3); /* mk_resimp_rep */
        return (*qfn1(fn))(qenv(fn), v135);
    }
/* error exit handlers */
v87:
    popv(4);
    return nil;
}



/* Code for ps!:times!: */

static Lisp_Object CC_psTtimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:times:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v121 = v108;
    v122 = v0;
/* end of prologue */
    v88 = elt(env, 1); /* times */
    {
        fn = elt(env, 2); /* ps!:operator!: */
        return (*qfnn(fn))(qenv(fn), 3, v88, v122, v121);
    }
}



/* Code for vdpfmon */

static Lisp_Object CC_vdpfmon(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpfmon");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v108;
    v98 = v0;
/* end of prologue */
    stack[-5] = elt(env, 1); /* vdp */
    stack[-3] = stack[-4];
    stack[-2] = v98;
    stack[-1] = stack[-4];
    stack[0] = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v98 = qvalue(elt(env, 2)); /* nil */
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v98 = acons(stack[-1], stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v98 = list3star(stack[-5], stack[-3], stack[-2], v98);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    stack[-1] = v98;
    v98 = qvalue(elt(env, 3)); /* !*gsugar */
    if (v98 == nil) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v98 = stack[-4];
    fn = elt(env, 4); /* vevtdeg */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    fn = elt(env, 5); /* gsetsugar */
    v98 = (*qfn2(fn))(qenv(fn), stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v40;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
/* error exit handlers */
v40:
    popv(7);
    return nil;
}



/* Code for xvarp */

static Lisp_Object CC_xvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v83, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xvarp");
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
    v83 = qvalue(elt(env, 1)); /* xvars!* */
    v153 = qvalue(elt(env, 2)); /* t */
    if (equal(v83, v153)) goto v22;
    v153 = stack[0];
    fn = elt(env, 7); /* xdegree */
    v83 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-1];
    v153 = (Lisp_Object)1; /* 0 */
    if (v83 == v153) goto v112;
    v153 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v153); }

v112:
    v153 = stack[0];
    v83 = qvalue(elt(env, 1)); /* xvars!* */
    v153 = Lmemq(nil, v153, v83);
    { popv(2); return onevalue(v153); }

v22:
    v153 = stack[0];
    if (!consp(v153)) goto v109;
    v153 = stack[0];
    v83 = qcar(v153);
    v153 = elt(env, 4); /* indexvar */
    v153 = Lflagp(nil, v83, v153);
    env = stack[-1];
    if (v153 == nil) goto v82;
    v153 = stack[0];
    v153 = qcdr(v153);
    v84 = Llength(nil, v153);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-1];
    v153 = stack[0];
    v83 = qcar(v153);
    v153 = elt(env, 5); /* ifdegree */
    v153 = get(v83, v153);
    v153 = Lassoc(nil, v84, v153);
    { popv(2); return onevalue(v153); }

v82:
    v153 = stack[0];
    v153 = qcar(v153);
    v83 = elt(env, 6); /* (wedge d partdf hodge innerprod liedf) */
    v153 = Lmemq(nil, v153, v83);
    { popv(2); return onevalue(v153); }

v109:
    v153 = stack[0];
    v83 = elt(env, 3); /* fdegree */
    popv(2);
    return get(v153, v83);
/* error exit handlers */
v155:
    popv(2);
    return nil;
}



/* Code for functionp */

static Lisp_Object CC_functionp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for functionp");
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
    v122 = stack[0];
    fn = elt(env, 2); /* getd */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-1];
    if (!(v122 == nil)) { popv(2); return onevalue(v122); }
    v122 = stack[0];
    v88 = elt(env, 1); /* lambda */
        popv(2);
        return Leqcar(nil, v122, v88);
/* error exit handlers */
v92:
    popv(2);
    return nil;
}



/* Code for rdzchk */

static Lisp_Object MS_CDECL CC_rdzchk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v108,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rdzchk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rdzchk");
#endif
    if (stack >= stacklimit)
    {
        push3(v10,v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v108,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v108;
    stack[-3] = v0;
/* end of prologue */
    v185 = stack[-3];
    if (!consp(v185)) goto v93;
    v185 = stack[-3];
    v185 = qcdr(v185);
    v186 = qcar(v185);
    v185 = (Lisp_Object)1; /* 0 */
    if (v186 == v185) goto v81;
    v185 = stack[-1];
    v185 = qcdr(v185);
    v186 = qcar(v185);
    v185 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)greaterp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v185 = v185 ? lisp_true : nil;
    env = stack[-5];
    if (v185 == nil) goto v188;
    v185 = stack[0];
    v185 = qcdr(v185);
    v186 = qcar(v185);
    v185 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)greaterp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v185 = v185 ? lisp_true : nil;
    env = stack[-5];
    goto v189;

v189:
    if (!(v185 == nil)) goto v190;
    v185 = stack[-1];
    v185 = qcdr(v185);
    v186 = qcar(v185);
    v185 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)lessp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v185 = v185 ? lisp_true : nil;
    env = stack[-5];
    if (v185 == nil) goto v191;
    v185 = stack[0];
    v185 = qcdr(v185);
    v186 = qcar(v185);
    v185 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)lessp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v185 = v185 ? lisp_true : nil;
    env = stack[-5];
    goto v190;

v190:
    if (!(v185 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v185 = stack[-1];
    v185 = qcdr(v185);
    v186 = qcar(v185);
    v185 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)greaterp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v185 = v185 ? lisp_true : nil;
    env = stack[-5];
    if (v185 == nil) goto v192;
    v185 = stack[-1];
    v186 = v185;
    goto v14;

v14:
    v185 = qvalue(elt(env, 6)); /* rd!-tolerance!* */
    stack[-4] = v186;
    stack[-2] = v185;
    stack[-1] = elt(env, 5); /* !:rd!: */
    v185 = stack[-4];
    v185 = qcdr(v185);
    v186 = qcar(v185);
    v185 = stack[-2];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    stack[0] = times2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-5];
    v185 = stack[-4];
    v185 = qcdr(v185);
    v186 = qcdr(v185);
    v185 = stack[-2];
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    v185 = plus2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-5];
    stack[-1] = list2star(stack[-1], stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-5];
    v185 = stack[-3];
    v185 = qcdr(v185);
    v186 = qcar(v185);
    v185 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)greaterp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v185 = v185 ? lisp_true : nil;
    env = stack[-5];
    if (v185 == nil) goto v193;
    v185 = stack[-3];
    goto v74;

v74:
    fn = elt(env, 8); /* greaterp!: */
    v185 = (*qfn2(fn))(qenv(fn), stack[-1], v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-5];
    if (v185 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v185 = qvalue(elt(env, 7)); /* bfz!* */
    { popv(6); return onevalue(v185); }

v193:
    stack[0] = elt(env, 5); /* !:rd!: */
    v185 = stack[-3];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v186 = negate(v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-5];
    v185 = stack[-3];
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    v185 = list2star(stack[0], v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-5];
    goto v74;

v192:
    stack[0] = elt(env, 5); /* !:rd!: */
    v185 = stack[-1];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v186 = negate(v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-5];
    v185 = stack[-1];
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    v185 = list2star(stack[0], v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-5];
    v186 = v185;
    goto v14;

v191:
    v185 = qvalue(elt(env, 3)); /* nil */
    goto v190;

v188:
    v185 = qvalue(elt(env, 3)); /* nil */
    goto v189;

v81:
    v185 = qvalue(elt(env, 2)); /* t */
    goto v190;

v93:
    v186 = stack[-3];
    v185 = elt(env, 1); /* 0.0 */
    if (equal(v186, v185)) goto v122;
    v186 = stack[-1];
    v185 = elt(env, 1); /* 0.0 */
    v185 = (Lisp_Object)greaterp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v185 = v185 ? lisp_true : nil;
    env = stack[-5];
    if (v185 == nil) goto v101;
    v186 = stack[0];
    v185 = elt(env, 1); /* 0.0 */
    v185 = (Lisp_Object)greaterp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v185 = v185 ? lisp_true : nil;
    env = stack[-5];
    goto v151;

v151:
    if (!(v185 == nil)) goto v121;
    v186 = stack[-1];
    v185 = elt(env, 1); /* 0.0 */
    v185 = (Lisp_Object)lessp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v185 = v185 ? lisp_true : nil;
    env = stack[-5];
    if (v185 == nil) goto v41;
    v186 = stack[0];
    v185 = elt(env, 1); /* 0.0 */
    v185 = (Lisp_Object)lessp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v185 = v185 ? lisp_true : nil;
    env = stack[-5];
    goto v121;

v121:
    if (!(v185 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v185 = stack[-3];
    stack[0] = Labsval(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-5];
    v185 = stack[-1];
    v186 = Labsval(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-5];
    v185 = qvalue(elt(env, 4)); /* !!fleps1 */
    v185 = times2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-5];
    v185 = (Lisp_Object)lessp2(stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v185 = v185 ? lisp_true : nil;
    env = stack[-5];
    if (v185 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v185 = elt(env, 1); /* 0.0 */
    { popv(6); return onevalue(v185); }

v41:
    v185 = qvalue(elt(env, 3)); /* nil */
    goto v121;

v101:
    v185 = qvalue(elt(env, 3)); /* nil */
    goto v151;

v122:
    v185 = qvalue(elt(env, 2)); /* t */
    goto v121;
/* error exit handlers */
v187:
    popv(6);
    return nil;
}



/* Code for fctins */

static Lisp_Object MS_CDECL CC_fctins(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v108,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fctins");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctins");
#endif
    if (stack >= stacklimit)
    {
        push3(v10,v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v108,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v108;
    stack[-2] = v0;
/* end of prologue */
    v136 = stack[0];
    if (v136 == nil) goto v69;
    v136 = stack[0];
    v136 = qcar(v136);
    fn = elt(env, 1); /* fctlength */
    v111 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v136 = stack[-1];
    v136 = (Lisp_Object)lessp2(v111, v136);
    nil = C_nil;
    if (exception_pending()) goto v41;
    v136 = v136 ? lisp_true : nil;
    env = stack[-3];
    if (v136 == nil) goto v86;
    v111 = stack[-2];
    v136 = stack[0];
    popv(4);
    return cons(v111, v136);

v86:
    v136 = stack[0];
    stack[-1] = qcar(v136);
    v111 = stack[-2];
    v136 = stack[0];
    v136 = qcdr(v136);
    fn = elt(env, 2); /* fctinsert */
    v136 = (*qfn2(fn))(qenv(fn), v111, v136);
    nil = C_nil;
    if (exception_pending()) goto v41;
    {
        Lisp_Object v131 = stack[-1];
        popv(4);
        return cons(v131, v136);
    }

v69:
    v136 = stack[-2];
    popv(4);
    return ncons(v136);
/* error exit handlers */
v41:
    popv(4);
    return nil;
}



/* Code for ev!-tades */

static Lisp_Object CC_evKtades(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v136, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-tades");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v69;

v69:
    v97 = stack[-1];
    if (v97 == nil) goto v105;
    v111 = qvalue(elt(env, 1)); /* ndim!* */
    v97 = stack[-1];
    v136 = qcar(v97);
    v97 = stack[0];
    v97 = Lassoc(nil, v136, v97);
    v97 = qcdr(v97);
    fn = elt(env, 2); /* binc */
    v136 = (*qfn2(fn))(qenv(fn), v111, v97);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v97 = stack[-2];
    v97 = cons(v136, v97);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    stack[-2] = v97;
    v97 = stack[-1];
    v97 = qcdr(v97);
    stack[-1] = v97;
    goto v69;

v105:
    stack[0] = stack[-2];
    v97 = (Lisp_Object)17; /* 1 */
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    {
        Lisp_Object v131 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v131, v97);
    }
/* error exit handlers */
v41:
    popv(4);
    return nil;
}



/* Code for compactf3 */

static Lisp_Object MS_CDECL CC_compactf3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v108,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v86, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "compactf3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactf3");
#endif
    if (stack >= stacklimit)
    {
        push3(v10,v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v108,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v108;
    v86 = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* mv!-vars!* */
    qvalue(elt(env, 1)) = nil; /* mv!-vars!* */
    v102 = stack[0];
    qvalue(elt(env, 1)) = v102; /* mv!-vars!* */
    v102 = stack[0];
    fn = elt(env, 3); /* sf2mv */
    v87 = (*qfn2(fn))(qenv(fn), v86, v102);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-3];
    v86 = stack[-1];
    v102 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* mv!-compact */
    v86 = (*qfnn(fn))(qenv(fn), 3, v87, v86, v102);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-3];
    v102 = stack[0];
    fn = elt(env, 5); /* mv2sf */
    v102 = (*qfn2(fn))(qenv(fn), v86, v102);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* mv!-vars!* */
    { popv(4); return onevalue(v102); }
/* error exit handlers */
v94:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* mv!-vars!* */
    popv(4);
    return nil;
}



/* Code for affinep */

static Lisp_Object CC_affinep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for affinep");
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
    v44 = v0;
/* end of prologue */
    v123 = qcar(v44);
    v44 = elt(env, 1); /* belong_to_space */
    v44 = get(v123, v44);
    env = stack[0];
    v123 = v44;
    v44 = v123;
    if (v44 == nil) goto v122;
    v44 = v123;
    fn = elt(env, 2); /* get_sign_space */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v44 = (v44 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v44); }

v122:
    v44 = nil;
    { popv(1); return onevalue(v44); }
/* error exit handlers */
v103:
    popv(1);
    return nil;
}



/* Code for x!*!*p!-w */

static Lisp_Object MS_CDECL CC_xHHpKw(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v108,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v113, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "x**p-w");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for x**p-w");
#endif
    if (stack >= stacklimit)
    {
        push3(v10,v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v108,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    v104 = v108;
    v113 = v0;
/* end of prologue */
    v130 = v113;
    v113 = v104;
    v104 = (Lisp_Object)17; /* 1 */
    v104 = acons(v130, v113, v104);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    v113 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    v104 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* general!-difference!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v113, v104);
    }
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for radd */

static Lisp_Object CC_radd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v143, v196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for radd");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    v26 = stack[-1];
    if (!consp(v26)) goto v112;
    stack[0] = (Lisp_Object)17; /* 1 */
    v26 = stack[-1];
    fn = elt(env, 4); /* prepf */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v197;
    {
        Lisp_Object v23 = stack[0];
        popv(4);
        return list2(v23, v26);
    }

v112:
    v143 = stack[-1];
    v26 = (Lisp_Object)1; /* 0 */
    v26 = (Lisp_Object)lessp2(v143, v26);
    nil = C_nil;
    if (exception_pending()) goto v197;
    v26 = v26 ? lisp_true : nil;
    env = stack[-3];
    if (v26 == nil) goto v43;
    v26 = stack[0];
    v26 = Levenp(nil, v26);
    env = stack[-3];
    if (v26 == nil) goto v43;
    v26 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v26;
    v26 = stack[-1];
    v26 = negate(v26);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    stack[-1] = v26;
    goto v43;

v43:
    v143 = stack[-1];
    v26 = stack[0];
    fn = elt(env, 5); /* nrootnn */
    v26 = (*qfn2(fn))(qenv(fn), v143, v26);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    stack[-1] = v26;
    v26 = stack[-2];
    if (v26 == nil) goto v145;
    v26 = qvalue(elt(env, 2)); /* !*reduced */
    if (v26 == nil) goto v140;
    v143 = stack[0];
    v26 = (Lisp_Object)33; /* 2 */
    if (!(v143 == v26)) goto v140;
    v26 = stack[-1];
    stack[0] = qcar(v26);
    v196 = elt(env, 3); /* i */
    v143 = (Lisp_Object)17; /* 1 */
    v26 = (Lisp_Object)17; /* 1 */
    v26 = acons(v196, v143, v26);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    v26 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    fn = elt(env, 6); /* multd */
    v26 = (*qfn2(fn))(qenv(fn), stack[0], v26);
    nil = C_nil;
    if (exception_pending()) goto v197;
    stack[0] = v26;
    v26 = stack[-1];
    v26 = qcdr(v26);
    stack[-1] = v26;
    goto v198;

v198:
    v143 = stack[-1];
    v26 = (Lisp_Object)17; /* 1 */
    if (v143 == v26) goto v27;
    v143 = stack[0];
    v26 = stack[-1];
    popv(4);
    return list2(v143, v26);

v27:
    v26 = stack[0];
    popv(4);
    return ncons(v26);

v140:
    v26 = stack[-1];
    v26 = qcar(v26);
    stack[0] = v26;
    v26 = stack[-1];
    v26 = qcdr(v26);
    v26 = negate(v26);
    nil = C_nil;
    if (exception_pending()) goto v197;
    stack[-1] = v26;
    goto v198;

v145:
    v26 = stack[-1];
    v26 = qcar(v26);
    stack[0] = v26;
    v26 = stack[-1];
    v26 = qcdr(v26);
    stack[-1] = v26;
    goto v198;
/* error exit handlers */
v197:
    popv(4);
    return nil;
}



/* Code for random!-teeny!-prime */

static Lisp_Object CC_randomKteenyKprime(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v134, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for random-teeny-prime");
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
    v134 = stack[0];
    v154 = elt(env, 1); /* all */
    if (v134 == v154) goto v63;
    v154 = stack[0];
    v134 = Llength(nil, v154);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    v154 = (Lisp_Object)161; /* 10 */
    v154 = (v134 == v154 ? lisp_true : nil);
    goto v68;

v68:
    if (v154 == nil) goto v147;
    v154 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v154); }

v147:
    stack[-1] = qvalue(elt(env, 4)); /* teeny!-primes */
    fn = elt(env, 5); /* next!-random!-number */
    v134 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    v154 = (Lisp_Object)161; /* 10 */
    v154 = Cremainder(v134, v154);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    v154 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v154/(16/CELL)));
    v115 = v154;
    v134 = v115;
    v154 = stack[0];
    v154 = Lmember(nil, v134, v154);
    if (v154 == nil) { popv(3); return onevalue(v115); }
    else goto v147;

v63:
    v154 = qvalue(elt(env, 2)); /* t */
    goto v68;
/* error exit handlers */
v38:
    popv(3);
    return nil;
}



/* Code for bfprin0 */

static Lisp_Object CC_bfprin0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfprin0");
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
    v66 = v0;
/* end of prologue */
    stack[0] = v66;
    v66 = qvalue(elt(env, 1)); /* !:print!-prec!: */
    if (v66 == nil) goto v130;
    v66 = qvalue(elt(env, 1)); /* !:print!-prec!: */
    goto v105;

v105:
    fn = elt(env, 3); /* round!:dec1 */
    v66 = (*qfn2(fn))(qenv(fn), stack[0], v66);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-1];
    v128 = v66;
    v128 = qcar(v128);
    v66 = qcdr(v66);
    fn = elt(env, 4); /* bfprin0x */
    v66 = (*qfn2(fn))(qenv(fn), v128, v66);
    nil = C_nil;
    if (exception_pending()) goto v98;
    v66 = nil;
    { popv(2); return onevalue(v66); }

v130:
    v128 = qvalue(elt(env, 2)); /* !:prec!: */
    v66 = (Lisp_Object)33; /* 2 */
    v66 = difference2(v128, v66);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-1];
    goto v105;
/* error exit handlers */
v98:
    popv(2);
    return nil;
}



/* Code for opfchk!! */

static Lisp_Object CC_opfchkB(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v215, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opfchk!");
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
    stack[-3] = nil;
    stack[-2] = nil;
    v214 = stack[-5];
    v214 = qcar(v214);
    stack[0] = v214;
    stack[-6] = v214;
    v214 = stack[-5];
    v214 = qcdr(v214);
    stack[-5] = v214;
    v215 = stack[0];
    v214 = elt(env, 1); /* integer */
    v214 = Lflagp(nil, v215, v214);
    env = stack[-7];
    if (v214 == nil) goto v123;
    v214 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v214;
    v215 = stack[0];
    v214 = elt(env, 3); /* !:rn!: */
    v214 = get(v215, v214);
    env = stack[-7];
    goto v45;

v45:
    stack[0] = v214;
    v214 = stack[0];
    if (v214 == nil) goto v199;
    v214 = stack[-3];
    if (v214 == nil) goto v31;
    v214 = elt(env, 9); /* simprn */
    goto v134;

v134:
    stack[-4] = v214;
    v214 = stack[-3];
    if (!(v214 == nil)) goto v172;
    v214 = qvalue(elt(env, 12)); /* !*complex */
    if (v214 == nil) goto v172;
    v214 = stack[-5];
    v215 = qcar(v214);
    v214 = elt(env, 13); /* list */
    if (!consp(v215)) goto v33;
    v215 = qcar(v215);
    if (!(v215 == v214)) goto v33;
    v214 = stack[-5];
    v214 = qcar(v214);
    v214 = qcdr(v214);
    fn = elt(env, 22); /* revlis */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    fn = elt(env, 23); /* simpcr */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    v215 = v214;
    if (v214 == nil) goto v172;
    v214 = qvalue(elt(env, 8)); /* nil */
    if (!consp(v215)) goto v172;
    v215 = qcar(v215);
    if (!(v215 == v214)) goto v172;

v67:
    v215 = stack[-6];
    v214 = elt(env, 16); /* "is not defined as complex function" */
    v214 = list2(v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    v215 = v214;
    v214 = v215;
    qvalue(elt(env, 17)) = v214; /* errmsg!* */
    v214 = qvalue(elt(env, 18)); /* !*protfg */
    if (!(v214 == nil)) goto v218;
    v214 = v215;
    fn = elt(env, 24); /* lprie */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    goto v218;

v218:
    v214 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    goto v172;

v172:
    stack[-1] = stack[-4];
    v214 = stack[-5];
    fn = elt(env, 22); /* revlis */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    v214 = Lapply1(nil, stack[-1], v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    stack[-5] = v214;
    if (!(v214 == nil)) goto v219;
    v214 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v214); }

v219:
    stack[-1] = elt(env, 19); /* apply */
    v214 = stack[0];
    stack[0] = Lmkquote(nil, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    v214 = stack[-5];
    v214 = Lmkquote(nil, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    v216 = list3(stack[-1], stack[0], v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    v215 = qvalue(elt(env, 8)); /* nil */
    v214 = qvalue(elt(env, 20)); /* !*backtrace */
    fn = elt(env, 25); /* errorset */
    v214 = (*qfnn(fn))(qenv(fn), 3, v216, v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    stack[-5] = v214;
    v214 = stack[-5];
    if (!consp(v214)) goto v220;
    v214 = stack[-5];
    v214 = qcdr(v214);
    goto v157;

v157:
    if (v214 == nil) goto v221;
    v214 = stack[-2];
    if (v214 == nil) goto v222;
    v214 = stack[-2];
    stack[-5] = v214;
    v214 = qvalue(elt(env, 8)); /* nil */
    stack[-2] = v214;
    goto v13;

v13:
    v215 = stack[-6];
    v214 = elt(env, 15); /* !:cr!: */
    v214 = get(v215, v214);
    env = stack[-7];
    stack[0] = v214;
    if (v214 == nil) goto v67;
    else goto v219;

v222:
    v214 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v214); }

v221:
    v214 = stack[-3];
    if (v214 == nil) goto v223;
    v214 = qvalue(elt(env, 5)); /* dmode!* */
    if (v214 == nil) goto v159;
    v215 = qvalue(elt(env, 5)); /* dmode!* */
    v214 = elt(env, 6); /* (!:rd!: !:cr!:) */
    v214 = Lmemq(nil, v215, v214);
    goto v224;

v224:
    if (v214 == nil) goto v225;
    v214 = stack[-5];
    v214 = qcar(v214);
    { popv(8); return onevalue(v214); }

v225:
    v215 = qvalue(elt(env, 5)); /* dmode!* */
    v214 = elt(env, 21); /* i2d */
    v215 = get(v215, v214);
    v214 = stack[-5];
    v214 = qcar(v214);
        popv(8);
        return Lapply1(nil, v215, v214);

v159:
    v214 = qvalue(elt(env, 2)); /* t */
    goto v224;

v223:
    v214 = stack[-5];
    v214 = qcar(v214);
    { popv(8); return onevalue(v214); }

v220:
    v214 = qvalue(elt(env, 2)); /* t */
    goto v157;

v33:
    v214 = stack[-5];
    fn = elt(env, 22); /* revlis */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    fn = elt(env, 23); /* simpcr */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    stack[-5] = v214;
    if (v214 == nil) goto v226;
    v215 = stack[-5];
    v214 = qvalue(elt(env, 8)); /* nil */
    if (!consp(v215)) goto v62;
    v215 = qcar(v215);
    if (!(v215 == v214)) goto v62;
    v214 = qvalue(elt(env, 2)); /* t */
    goto v227;

v227:
    if (v214 == nil) goto v177;
    v214 = stack[-5];
    v214 = qcdr(v214);
    stack[-5] = v214;
    goto v13;

v177:
    v214 = stack[-5];
    v214 = qcdr(v214);
    stack[-2] = v214;
    v214 = stack[-5];
    v214 = qcar(v214);
    stack[-5] = v214;
    goto v172;

v62:
    v215 = stack[-6];
    v214 = elt(env, 14); /* expt */
    if (v215 == v214) goto v228;
    v214 = qvalue(elt(env, 8)); /* nil */
    goto v227;

v228:
    v214 = stack[-5];
    v214 = qcar(v214);
    v214 = qcar(v214);
    fn = elt(env, 26); /* rd!:minusp */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-7];
    goto v227;

v226:
    v214 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v214); }

v31:
    v215 = stack[0];
    v214 = elt(env, 10); /* simparg */
    v214 = get(v215, v214);
    env = stack[-7];
    stack[-4] = v214;
    if (v214 == nil) goto v120;
    v214 = stack[-4];
    goto v134;

v120:
    v214 = elt(env, 11); /* simprd */
    goto v134;

v199:
    v214 = qvalue(elt(env, 8)); /* nil */
    { popv(8); return onevalue(v214); }

v123:
    v214 = qvalue(elt(env, 4)); /* !*numval */
    if (v214 == nil) goto v109;
    v215 = qvalue(elt(env, 5)); /* dmode!* */
    v214 = elt(env, 6); /* (!:rd!: !:cr!:) */
    v214 = Lmemq(nil, v215, v214);
    if (v214 == nil) goto v109;
    v215 = stack[0];
    v214 = elt(env, 7); /* !:rd!: */
    v214 = get(v215, v214);
    env = stack[-7];
    goto v45;

v109:
    v214 = nil;
    goto v45;
/* error exit handlers */
v217:
    popv(8);
    return nil;
}



/* Code for conjsq */

static Lisp_Object CC_conjsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conjsq");
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
    v152 = stack[0];
    fn = elt(env, 2); /* impartsq */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    stack[-1] = v152;
    v152 = stack[-1];
    v152 = qcar(v152);
    if (v152 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v152 = stack[0];
    fn = elt(env, 3); /* repartsq */
    stack[0] = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    v152 = elt(env, 1); /* i */
    fn = elt(env, 4); /* simp */
    v66 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    v152 = stack[-1];
    fn = elt(env, 5); /* multsq */
    v152 = (*qfn2(fn))(qenv(fn), v66, v152);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    stack[-1] = v152;
    v152 = stack[-1];
    v152 = qcar(v152);
    fn = elt(env, 6); /* negf */
    v66 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    v152 = stack[-1];
    v152 = qcdr(v152);
    v152 = cons(v66, v152);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    {
        Lisp_Object v85 = stack[0];
        popv(3);
        fn = elt(env, 7); /* addsq */
        return (*qfn2(fn))(qenv(fn), v85, v152);
    }
/* error exit handlers */
v98:
    popv(3);
    return nil;
}



/* Code for repr_n */

static Lisp_Object CC_repr_n(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v128, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repr_n");
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
    v138 = v0;
/* end of prologue */
    v66 = v138;
    v66 = qcdr(v66);
    v66 = qcdr(v66);
    v66 = qcar(v66);
    if (v66 == nil) goto v15;
    v66 = v138;
    v66 = qcdr(v66);
    v66 = qcdr(v66);
    v66 = qcdr(v66);
    v66 = qcdr(v66);
    v128 = qcar(v66);
    v66 = (Lisp_Object)1; /* 0 */
    if (v128 == v66) goto v123;
    v66 = v138;
    v66 = qcdr(v66);
    v66 = qcdr(v66);
    v66 = qcar(v66);
    v66 = qcar(v66);
    v66 = qcar(v66);
    { popv(1); return onevalue(v66); }

v123:
    v66 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v66); }

v15:
    v66 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v66 == nil)) goto v105;
    v66 = elt(env, 2); /* "repr_n : invalid REPR structure" */
    v66 = ncons(v66);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[0];
    fn = elt(env, 4); /* lprie */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[0];
    goto v105;

v105:
    v66 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v98;
    v66 = nil;
    { popv(1); return onevalue(v66); }
/* error exit handlers */
v98:
    popv(1);
    return nil;
}



/* Code for ratpoly_univarp */

static Lisp_Object CC_ratpoly_univarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_univarp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v0;
/* end of prologue */
    v22 = qcar(v22);
    {
        fn = elt(env, 1); /* sf_univarp */
        return (*qfn1(fn))(qenv(fn), v22);
    }
}



/* Code for ldf!-spf!-var */

static Lisp_Object CC_ldfKspfKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-spf-var");
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
    v29 = v0;
/* end of prologue */
    v184 = nil;
    stack[-3] = nil;
    stack[-1] = v29;
    goto v51;

v51:
    v29 = stack[-1];
    if (v29 == nil) goto v63;
    v29 = stack[-1];
    v29 = qcar(v29);
    stack[0] = v184;
    v184 = qcdr(v29);
    v29 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* kernels1 */
    v29 = (*qfn2(fn))(qenv(fn), v184, v29);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v29 = Lappend(nil, stack[0], v29);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v184 = v29;
    v29 = stack[-1];
    v29 = qcdr(v29);
    stack[-1] = v29;
    goto v51;

v63:
    v29 = v184;
    fn = elt(env, 5); /* makeset */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    fn = elt(env, 6); /* prlist */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    stack[-2] = v29;
    goto v42;

v42:
    v29 = stack[-2];
    if (v29 == nil) goto v109;
    v29 = stack[-2];
    v29 = qcar(v29);
    stack[-1] = v29;
    v184 = stack[-1];
    v29 = elt(env, 2); /* x */
    if (!consp(v184)) goto v38;
    v184 = qcar(v184);
    if (!(v184 == v29)) goto v38;
    v29 = qvalue(elt(env, 1)); /* nil */
    goto v55;

v55:
    if (v29 == nil) goto v41;
    v184 = elt(env, 2); /* x */
    v29 = stack[-1];
    v29 = qcdr(v29);
    fn = elt(env, 7); /* sacar */
    stack[0] = (*qfn2(fn))(qenv(fn), v184, v29);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v184 = elt(env, 3); /* u */
    v29 = stack[-1];
    v29 = qcdr(v29);
    fn = elt(env, 7); /* sacar */
    v184 = (*qfn2(fn))(qenv(fn), v184, v29);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v29 = stack[-3];
    fn = elt(env, 8); /* appends */
    v29 = (*qfnn(fn))(qenv(fn), 3, stack[0], v184, v29);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    stack[-3] = v29;
    goto v41;

v41:
    v29 = stack[-2];
    v29 = qcdr(v29);
    stack[-2] = v29;
    goto v42;

v38:
    v184 = stack[-1];
    v29 = elt(env, 3); /* u */
    v29 = Leqcar(nil, v184, v29);
    env = stack[-4];
    v29 = (v29 == nil ? lisp_true : nil);
    goto v55;

v109:
    v29 = stack[-3];
    {
        popv(5);
        fn = elt(env, 5); /* makeset */
        return (*qfn1(fn))(qenv(fn), v29);
    }
/* error exit handlers */
v77:
    popv(5);
    return nil;
}



/* Code for xriterion_2 */

static Lisp_Object MS_CDECL CC_xriterion_2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v108,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149, v191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xriterion_2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xriterion_2");
#endif
    if (stack >= stacklimit)
    {
        push3(v10,v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v108,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v108;
    stack[-2] = v0;
/* end of prologue */

v118:
    v148 = stack[-1];
    if (v148 == nil) goto v69;
    v148 = stack[-2];
    v148 = qcdr(v148);
    v149 = qcar(v148);
    v148 = elt(env, 2); /* wedge_pair */
    if (v149 == v148) goto v103;
    v148 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v148); }

v103:
    v148 = stack[-1];
    v148 = qcar(v148);
    stack[-3] = v148;
    v191 = stack[-3];
    v149 = (Lisp_Object)17; /* 1 */
    v148 = (Lisp_Object)17; /* 1 */
    v148 = list2star(v191, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-4];
    v149 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-4];
    v148 = stack[-2];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    if (equal(v149, v148)) goto v23;
    v149 = stack[-3];
    v148 = stack[-3];
    v149 = list2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-4];
    v148 = stack[-2];
    v148 = qcar(v148);
    fn = elt(env, 7); /* xdiv */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-4];
    if (v148 == nil) goto v132;
    v149 = stack[-3];
    v148 = stack[-2];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    fn = elt(env, 8); /* make_wedge_pair */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-4];
    v149 = v148;
    v148 = v149;
    if (v148 == nil) goto v145;
    v148 = stack[0];
    fn = elt(env, 9); /* find_item */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-4];
    v148 = (v148 == nil ? lisp_true : nil);
    goto v59;

v59:
    if (v148 == nil) goto v54;
    v148 = qvalue(elt(env, 4)); /* !*trxideal */
    if (v148 == nil) goto v235;
    v148 = elt(env, 5); /* "criterion 2 hit" */
    fn = elt(env, 10); /* eval */
    v191 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-4];
    v149 = qvalue(elt(env, 1)); /* nil */
    v148 = elt(env, 6); /* last */
    fn = elt(env, 11); /* assgnpri */
    v148 = (*qfnn(fn))(qenv(fn), 3, v191, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-4];
    goto v235;

v235:
    v148 = qvalue(elt(env, 3)); /* t */
    goto v151;

v151:
    if (!(v148 == nil)) { popv(5); return onevalue(v148); }
    v191 = stack[-2];
    v148 = stack[-1];
    v149 = qcdr(v148);
    v148 = stack[0];
    stack[-2] = v191;
    stack[-1] = v149;
    stack[0] = v148;
    goto v118;

v54:
    v148 = qvalue(elt(env, 1)); /* nil */
    goto v151;

v145:
    v148 = qvalue(elt(env, 3)); /* t */
    goto v59;

v132:
    v148 = qvalue(elt(env, 1)); /* nil */
    goto v151;

v23:
    v148 = qvalue(elt(env, 1)); /* nil */
    goto v151;

v69:
    v148 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v148); }
/* error exit handlers */
v228:
    popv(5);
    return nil;
}



/* Code for quotient!: */

static Lisp_Object CC_quotientT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotient:");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v108;
    stack[-2] = v0;
/* end of prologue */

v105:
    v148 = stack[-2];
    v148 = qcdr(v148);
    v149 = qcdr(v148);
    stack[-1] = v149;
    v148 = stack[-3];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    stack[0] = v148;
    if (equal(v149, v148)) goto v130;
    v149 = stack[-1];
    v148 = stack[0];
    v148 = (Lisp_Object)greaterp2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    v148 = v148 ? lisp_true : nil;
    env = stack[-5];
    if (v148 == nil) goto v81;
    v149 = stack[-1];
    v148 = stack[0];
    v148 = difference2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    stack[-4] = v148;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v148 = stack[-2];
    v148 = qcdr(v148);
    v149 = qcar(v148);
    v148 = stack[-4];
    stack[0] = Lash1(nil, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    v148 = stack[-2];
    v148 = qcdr(v148);
    v149 = qcdr(v148);
    v148 = stack[-4];
    v148 = difference2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    v149 = list2star(stack[-1], stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    v148 = stack[-3];
    stack[-2] = v149;
    stack[-3] = v148;
    goto v105;

v81:
    stack[-4] = stack[-2];
    v149 = stack[0];
    v148 = stack[-1];
    v148 = difference2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    stack[-2] = v148;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v148 = stack[-3];
    v148 = qcdr(v148);
    v149 = qcar(v148);
    v148 = stack[-2];
    stack[0] = Lash1(nil, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    v148 = stack[-3];
    v148 = qcdr(v148);
    v149 = qcdr(v148);
    v148 = stack[-2];
    v148 = difference2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    v148 = list2star(stack[-1], stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-5];
    stack[-2] = stack[-4];
    stack[-3] = v148;
    goto v105;

v130:
    stack[0] = elt(env, 1); /* !:rd!: */
    v148 = stack[-2];
    v148 = qcdr(v148);
    v149 = qcar(v148);
    v148 = stack[-3];
    v148 = qcdr(v148);
    v148 = qcar(v148);
    v149 = quot2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v228;
    v148 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v239 = stack[0];
        popv(6);
        return list2star(v239, v149, v148);
    }
/* error exit handlers */
v228:
    popv(6);
    return nil;
}



/* Code for forttab */

static Lisp_Object CC_forttab(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for forttab");
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
    v98 = qvalue(elt(env, 1)); /* fortlinelen!* */
    v138 = qvalue(elt(env, 2)); /* minfortlinelen!* */
    v138 = difference2(v98, v138);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    fn = elt(env, 5); /* min0 */
    v98 = (*qfn2(fn))(qenv(fn), stack[0], v138);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    v138 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 6); /* max */
    v138 = (*qfn2(fn))(qenv(fn), v98, v138);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    qvalue(elt(env, 3)) = v138; /* !*fortcurrind!* */
    v98 = qvalue(elt(env, 3)); /* !*fortcurrind!* */
    v138 = qvalue(elt(env, 4)); /* !*posn!* */
    v98 = difference2(v98, v138);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    stack[0] = v98;
    v138 = (Lisp_Object)1; /* 0 */
    v138 = (Lisp_Object)greaterp2(v98, v138);
    nil = C_nil;
    if (exception_pending()) goto v97;
    v138 = v138 ? lisp_true : nil;
    env = stack[-1];
    if (v138 == nil) goto v47;
    v138 = stack[0];
    fn = elt(env, 7); /* nspaces */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 8); /* pprin2 */
        return (*qfn1(fn))(qenv(fn), v138);
    }

v47:
    v138 = nil;
    { popv(2); return onevalue(v138); }
/* error exit handlers */
v97:
    popv(2);
    return nil;
}



/* Code for tvectorp */

static Lisp_Object CC_tvectorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tvectorp");
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
    v104 = v0;
/* end of prologue */
    v104 = qcar(v104);
    v104 = qcar(v104);
    fn = elt(env, 2); /* deg!*form */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[0];
    v113 = v104;
    v104 = v113;
    if (is_number(v104)) goto v92;
    v104 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v104); }

v92:
    v104 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v113, v104);
/* error exit handlers */
v130:
    popv(1);
    return nil;
}



/* Code for new_provev */

static Lisp_Object CC_new_provev(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v98, v85, v97;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for new_provev");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v85 = v108;
    v97 = v0;
/* end of prologue */
    v98 = v97;
    v138 = v85;
    v138 = Lmember(nil, v98, v138);
    if (v138 == nil) goto v22;
    v138 = v97;
    v138 = qcdr(v138);
    v138 = qcar(v138);
    v98 = qcar(v138);
    v138 = v85;
    v138 = Lassoc(nil, v98, v138);
    if (v138 == nil) return onevalue(v85);
    v138 = v97;
    v138 = qcdr(v138);
    v138 = qcar(v138);
    v98 = qcdr(v138);
    v138 = v85;
    v138 = Lassoc(nil, v98, v138);
    if (v138 == nil) return onevalue(v85);
    v138 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v138);

v22:
    v138 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v138);
}



/* Code for boolean!-eval2 */

static Lisp_Object CC_booleanKeval2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v179, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boolean-eval2");
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

v64:
    v179 = stack[0];
    v240 = elt(env, 1); /* boolean */
    if (!consp(v179)) goto v47;
    v179 = qcar(v179);
    if (!(v179 == v240)) goto v47;
    v240 = stack[0];
    v240 = qcdr(v240);
    v240 = qcar(v240);
    stack[0] = v240;
    goto v64;

v47:
    v179 = stack[0];
    v240 = elt(env, 2); /* and */
    if (!consp(v179)) goto v43;
    v179 = qcar(v179);
    if (!(v179 == v240)) goto v43;
    v240 = qvalue(elt(env, 3)); /* t */
    goto v104;

v104:
    if (v240 == nil) goto v241;
    v240 = stack[0];
    stack[-4] = qcar(v240);
    v240 = stack[0];
    v240 = qcdr(v240);
    stack[-3] = v240;
    v240 = stack[-3];
    if (v240 == nil) goto v82;
    v240 = stack[-3];
    v240 = qcar(v240);
    v240 = CC_booleanKeval2(env, v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v240 = ncons(v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[-1] = v240;
    stack[-2] = v240;
    goto v116;

v116:
    v240 = stack[-3];
    v240 = qcdr(v240);
    stack[-3] = v240;
    v240 = stack[-3];
    if (v240 == nil) goto v243;
    stack[0] = stack[-1];
    v240 = stack[-3];
    v240 = qcar(v240);
    v240 = CC_booleanKeval2(env, v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v240 = ncons(v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v240 = Lrplacd(nil, stack[0], v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v240 = stack[-1];
    v240 = qcdr(v240);
    stack[-1] = v240;
    goto v116;

v243:
    v240 = stack[-2];
    goto v36;

v36:
    {
        Lisp_Object v244 = stack[-4];
        popv(6);
        return cons(v244, v240);
    }

v82:
    v240 = qvalue(elt(env, 6)); /* nil */
    goto v36;

v241:
    v240 = qvalue(elt(env, 3)); /* t */
    stack[-1] = qvalue(elt(env, 7)); /* !*protfg */
    qvalue(elt(env, 7)) = v240; /* !*protfg */
    v180 = stack[0];
    v179 = qvalue(elt(env, 6)); /* nil */
    v240 = elt(env, 8); /* algebraic */
    fn = elt(env, 11); /* formbool */
    v180 = (*qfnn(fn))(qenv(fn), 3, v180, v179, v240);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    v179 = qvalue(elt(env, 6)); /* nil */
    v240 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 12); /* errorset */
    v240 = (*qfnn(fn))(qenv(fn), 3, v180, v179, v240);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    v179 = v240;
    qvalue(elt(env, 7)) = stack[-1]; /* !*protfg */
    v240 = v179;
    if (!consp(v240)) goto v19;
    v240 = v179;
    v240 = qcdr(v240);
    goto v18;

v18:
    if (v240 == nil) goto v228;
    v240 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 9)) = v240; /* bool!-break!* */
    v240 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 10)) = v240; /* erfg!* */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v228:
    v240 = v179;
    v240 = qcar(v240);
    { popv(6); return onevalue(v240); }

v19:
    v240 = qvalue(elt(env, 3)); /* t */
    goto v18;

v43:
    v179 = stack[0];
    v240 = elt(env, 4); /* or */
    if (!consp(v179)) goto v141;
    v179 = qcar(v179);
    if (!(v179 == v240)) goto v141;
    v240 = qvalue(elt(env, 3)); /* t */
    goto v104;

v141:
    v179 = stack[0];
    v240 = elt(env, 5); /* not */
    v240 = Leqcar(nil, v179, v240);
    env = stack[-5];
    goto v104;
/* error exit handlers */
v245:
    env = stack[-5];
    qvalue(elt(env, 7)) = stack[-1]; /* !*protfg */
    popv(6);
    return nil;
v242:
    popv(6);
    return nil;
}



/* Code for combin */

static Lisp_Object CC_combin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v238;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for combin");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v108;
    stack[-3] = v0;
/* end of prologue */
    v238 = stack[-3];
    v229 = stack[-2];
    v229 = (Lisp_Object)greaterp2(v238, v229);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v229 = v229 ? lisp_true : nil;
    env = stack[-5];
    if (v229 == nil) goto v88;
    v229 = (Lisp_Object)1; /* 0 */
    { popv(6); return onevalue(v229); }

v88:
    v229 = (Lisp_Object)17; /* 1 */
    stack[-1] = v229;
    stack[-4] = v229;
    v238 = stack[-2];
    v229 = stack[-3];
    v229 = difference2(v238, v229);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    v229 = add1(v229);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    stack[0] = v229;
    goto v66;

v66:
    v238 = stack[-2];
    v229 = stack[0];
    v229 = difference2(v238, v229);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    v229 = Lminusp(nil, v229);
    env = stack[-5];
    if (v229 == nil) goto v141;
    v229 = (Lisp_Object)17; /* 1 */
    stack[0] = v229;
    goto v116;

v116:
    v238 = stack[-3];
    v229 = stack[0];
    v229 = difference2(v238, v229);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    v229 = Lminusp(nil, v229);
    env = stack[-5];
    if (v229 == nil) goto v119;
    v238 = stack[-4];
    v229 = stack[-1];
    popv(6);
    return quot2(v238, v229);

v119:
    v238 = stack[-1];
    v229 = stack[0];
    v229 = times2(v238, v229);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    stack[-1] = v229;
    v229 = stack[0];
    v229 = add1(v229);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    stack[0] = v229;
    goto v116;

v141:
    v238 = stack[-4];
    v229 = stack[0];
    v229 = times2(v238, v229);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    stack[-4] = v229;
    v229 = stack[0];
    v229 = add1(v229);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    stack[0] = v229;
    goto v66;
/* error exit handlers */
v28:
    popv(6);
    return nil;
}



/* Code for precision1 */

static Lisp_Object CC_precision1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v249, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for precision1");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v12 = v108;
    stack[0] = v0;
/* end of prologue */
    v249 = stack[0];
    v248 = (Lisp_Object)1; /* 0 */
    if (v249 == v248) goto v63;
    v248 = v12;
    if (v248 == nil) goto v45;
    v249 = qvalue(elt(env, 2)); /* !*sqvar!* */
    v248 = qvalue(elt(env, 3)); /* nil */
    v248 = Lrplaca(nil, v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v248 = qvalue(elt(env, 4)); /* t */
    v248 = ncons(v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    qvalue(elt(env, 2)) = v248; /* !*sqvar!* */
    v248 = qvalue(elt(env, 3)); /* nil */
    v248 = ncons(v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    qvalue(elt(env, 5)) = v248; /* alglist!* */
    goto v45;

v45:
    v248 = qvalue(elt(env, 1)); /* !!rdprec */
    stack[-3] = v248;
    v248 = qvalue(elt(env, 6)); /* !*roundbf */
    if (v248 == nil) goto v141;
    v248 = stack[0];
    v249 = v248;
    goto v128;

v128:
    qvalue(elt(env, 1)) = v249; /* !!rdprec */
    v248 = (Lisp_Object)33; /* 2 */
    v248 = plus2(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    qvalue(elt(env, 8)) = v248; /* !:prec!: */
    v248 = qvalue(elt(env, 9)); /* !:print!-prec!: */
    if (v248 == nil) goto v243;
    v249 = qvalue(elt(env, 9)); /* !:print!-prec!: */
    v248 = (Lisp_Object)33; /* 2 */
    v248 = plus2(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v248 = (Lisp_Object)lessp2(stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    v248 = v248 ? lisp_true : nil;
    env = stack[-4];
    if (v248 == nil) goto v243;
    v248 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 9)) = v248; /* !:print!-prec!: */
    goto v243;

v243:
    v249 = qvalue(elt(env, 8)); /* !:prec!: */
    v248 = qvalue(elt(env, 10)); /* log2of10 */
    v248 = times2(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    fn = elt(env, 18); /* ceiling */
    v249 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v248 = (Lisp_Object)49; /* 3 */
    v248 = plus2(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    qvalue(elt(env, 11)) = v248; /* !:bprec!: */
    stack[-1] = elt(env, 12); /* !:rd!: */
    stack[0] = (Lisp_Object)17; /* 1 */
    v249 = qvalue(elt(env, 11)); /* !:bprec!: */
    v248 = (Lisp_Object)33; /* 2 */
    v248 = quot2(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v248 = negate(v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v248 = list2star(stack[-1], stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    qvalue(elt(env, 13)) = v248; /* epsqrt!* */
    stack[-1] = elt(env, 12); /* !:rd!: */
    stack[0] = (Lisp_Object)17; /* 1 */
    v249 = (Lisp_Object)97; /* 6 */
    v248 = qvalue(elt(env, 11)); /* !:bprec!: */
    v248 = difference2(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v248 = list2star(stack[-1], stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    qvalue(elt(env, 14)) = v248; /* rd!-tolerance!* */
    stack[-2] = elt(env, 12); /* !:rd!: */
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = (Lisp_Object)33; /* 2 */
    v249 = (Lisp_Object)97; /* 6 */
    v248 = qvalue(elt(env, 11)); /* !:bprec!: */
    v248 = difference2(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v248 = times2(stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v248 = list2star(stack[-2], stack[-1], v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    qvalue(elt(env, 15)) = v248; /* cr!-tolerance!* */
    v249 = qvalue(elt(env, 1)); /* !!rdprec */
    v248 = qvalue(elt(env, 16)); /* !!flprec */
    v248 = (Lisp_Object)greaterp2(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    v248 = v248 ? lisp_true : nil;
    env = stack[-4];
    if (!(v248 == nil)) goto v17;
    v248 = qvalue(elt(env, 6)); /* !*roundbf */
    goto v17;

v17:
    qvalue(elt(env, 17)) = v248; /* !*!*roundbf */
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v141:
    v249 = stack[0];
    v248 = qvalue(elt(env, 7)); /* minprec!# */
    fn = elt(env, 19); /* max */
    v248 = (*qfn2(fn))(qenv(fn), v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v249 = v248;
    goto v128;

v63:
    v248 = qvalue(elt(env, 1)); /* !!rdprec */
    { popv(5); return onevalue(v248); }
/* error exit handlers */
v74:
    popv(5);
    return nil;
}



/* Code for equations_used */

static Lisp_Object MS_CDECL CC_equations_used(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v64;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "equations_used");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equations_used");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v51 = qvalue(elt(env, 1)); /* cur_eq_set!* */
    v64 = elt(env, 2); /* total_used */
    return get(v51, v64);
}



/* Code for pasf_sacat */

static Lisp_Object MS_CDECL CC_pasf_sacat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v108,
                         Lisp_Object v10, ...)
{
    Lisp_Object v22, v69, v68;
    argcheck(nargs, 3, "pasf_sacat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_sacat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v10;
    v69 = v108;
    v68 = v0;
/* end of prologue */
    v22 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v22);
}



/* Code for dip_comp1 */

static Lisp_Object CC_dip_comp1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_comp1");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    v105 = v0;
/* end of prologue */
    fn = elt(env, 1); /* dip_evlmon */
    stack[-1] = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    v105 = stack[0];
    fn = elt(env, 1); /* dip_evlmon */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    {
        Lisp_Object v93 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* ev_comp */
        return (*qfn2(fn))(qenv(fn), v93, v105);
    }
/* error exit handlers */
v88:
    popv(3);
    return nil;
}



/* Code for mkarg */

static Lisp_Object CC_mkarg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v140;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkarg");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    stack[-1] = v0;
/* end of prologue */
    v84 = stack[-1];
    if (v84 == nil) goto v51;
    v84 = stack[-1];
    v84 = Lconstantp(nil, v84);
    env = stack[-3];
    goto v63;

v63:
    if (!(v84 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v84 = stack[-1];
    if (!consp(v84)) goto v130;
    v84 = stack[-1];
    v140 = qcar(v84);
    v84 = elt(env, 2); /* (quote !:dn!: !:int!:) */
    v84 = Lmemq(nil, v140, v84);
    if (v84 == nil) goto v111;
    v84 = stack[-1];
        popv(4);
        return Lmkquote(nil, v84);

v111:
    stack[-2] = nil;
    goto v131;

v131:
    v84 = stack[-1];
    if (v84 == nil) goto v96;
    v84 = stack[-1];
    v140 = qcar(v84);
    v84 = stack[0];
    v140 = CC_mkarg(env, v140, v84);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    v84 = stack[-2];
    v84 = cons(v140, v84);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-3];
    stack[-2] = v84;
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v131;

v96:
    v140 = elt(env, 3); /* list */
    v84 = stack[-2];
    v84 = Lnreverse(nil, v84);
    popv(4);
    return cons(v140, v84);

v130:
    v140 = stack[-1];
    v84 = stack[0];
    v84 = Latsoc(nil, v140, v84);
    if (!(v84 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v84 = stack[-1];
        popv(4);
        return Lmkquote(nil, v84);

v51:
    v84 = qvalue(elt(env, 1)); /* t */
    goto v63;
/* error exit handlers */
v80:
    popv(4);
    return nil;
}



/* Code for dsimptimes */

static Lisp_Object CC_dsimptimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dsimptimes");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    stack[-1] = v0;
/* end of prologue */
    v27 = stack[-1];
    if (v27 == nil) goto v22;
    v27 = stack[-1];
    v27 = qcdr(v27);
    if (v27 == nil) goto v122;
    v27 = stack[-1];
    v28 = qcar(v27);
    v27 = stack[0];
    fn = elt(env, 2); /* dsimp */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    stack[-4] = v27;
    v27 = stack[-1];
    v28 = qcdr(v27);
    v27 = stack[0];
    v27 = CC_dsimptimes(env, v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    stack[-3] = v27;
    goto v109;

v109:
    v27 = stack[-3];
    if (v27 == nil) goto v141;
    v27 = stack[-3];
    v27 = qcar(v27);
    v28 = stack[-4];
    fn = elt(env, 3); /* mappend */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    stack[-2] = v27;
    v27 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    stack[-1] = v27;
    v27 = stack[-3];
    v27 = qcdr(v27);
    stack[-3] = v27;
    v27 = stack[-1];
    if (!consp(v27)) goto v109;
    else goto v42;

v42:
    v27 = stack[-3];
    if (v27 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v27 = stack[-3];
    v27 = qcar(v27);
    v28 = stack[-4];
    fn = elt(env, 3); /* mappend */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v27 = Lrplacd(nil, stack[0], v27);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v27 = stack[-1];
    fn = elt(env, 4); /* lastpair */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    stack[-1] = v27;
    v27 = stack[-3];
    v27 = qcdr(v27);
    stack[-3] = v27;
    goto v42;

v141:
    v27 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v27); }

v122:
    v27 = stack[-1];
    v28 = qcar(v27);
    v27 = stack[0];
    {
        popv(6);
        fn = elt(env, 2); /* dsimp */
        return (*qfn2(fn))(qenv(fn), v28, v27);
    }

v22:
    v27 = elt(env, 0); /* dsimptimes */
    {
        popv(6);
        fn = elt(env, 5); /* errach */
        return (*qfn1(fn))(qenv(fn), v27);
    }
/* error exit handlers */
v195:
    popv(6);
    return nil;
}



/* Code for nspaces */

static Lisp_Object CC_nspaces(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v42, v43;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nspaces");
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
    stack[-2] = nil;
    v109 = (Lisp_Object)17; /* 1 */
    stack[0] = v109;
    goto v88;

v88:
    v42 = stack[-1];
    v109 = stack[0];
    v109 = difference2(v42, v109);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    v109 = Lminusp(nil, v109);
    env = stack[-3];
    if (v109 == nil) goto v130;
    v109 = stack[-2];
    v109 = Lcompress(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v138;
        popv(4);
        return Lintern(nil, v109);

v130:
    v43 = elt(env, 2); /* !! */
    v42 = elt(env, 3); /* !  */
    v109 = stack[-2];
    v109 = list2star(v43, v42, v109);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    stack[-2] = v109;
    v109 = stack[0];
    v109 = add1(v109);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    stack[0] = v109;
    goto v88;
/* error exit handlers */
v138:
    popv(4);
    return nil;
}



/* Code for pnth!* */

static Lisp_Object CC_pnthH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v56, v135;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pnth*");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v56 = v108;
    stack[0] = v0;
/* end of prologue */

v22:
    v112 = stack[0];
    if (v112 == nil) goto v63;
    v135 = v56;
    v112 = (Lisp_Object)17; /* 1 */
    if (v135 == v112) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v112 = stack[0];
    v112 = qcdr(v112);
    stack[0] = v112;
    v112 = v56;
    v112 = sub1(v112);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    v56 = v112;
    goto v22;

v63:
    v112 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v112); }
/* error exit handlers */
v101:
    popv(2);
    return nil;
}



/* Code for s_world_names */

static Lisp_Object CC_s_world_names(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for s_world_names");
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
    v128 = v0;
/* end of prologue */
    v128 = qcar(v128);
    stack[-3] = v128;
    v128 = stack[-3];
    if (v128 == nil) goto v106;
    v128 = stack[-3];
    v128 = qcar(v128);
    v128 = qcar(v128);
    v128 = ncons(v128);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    stack[-1] = v128;
    stack[-2] = v128;
    goto v68;

v68:
    v128 = stack[-3];
    v128 = qcdr(v128);
    stack[-3] = v128;
    v128 = stack[-3];
    if (v128 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v128 = stack[-3];
    v128 = qcar(v128);
    v128 = qcar(v128);
    v128 = ncons(v128);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v128 = Lrplacd(nil, stack[0], v128);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v128 = stack[-1];
    v128 = qcdr(v128);
    stack[-1] = v128;
    goto v68;

v106:
    v128 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v128); }
/* error exit handlers */
v136:
    popv(5);
    return nil;
}



/* Code for st_extract_symcells1 */

static Lisp_Object MS_CDECL CC_st_extract_symcells1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v108,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v245, v251, v246;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_extract_symcells1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_extract_symcells1");
#endif
    if (stack >= stacklimit)
    {
        push3(v10,v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v108,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v10;
    stack[-5] = v108;
    stack[0] = v0;
/* end of prologue */
    v245 = stack[0];
    v245 = qcdr(v245);
    v245 = qcar(v245);
    fn = elt(env, 3); /* listp */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-7];
    if (v245 == nil) goto v93;
    v245 = stack[0];
    stack[-6] = qcar(v245);
    v245 = stack[0];
    v245 = qcdr(v245);
    stack[-3] = v245;
    v245 = stack[-3];
    if (v245 == nil) goto v41;
    v245 = stack[-3];
    v245 = qcar(v245);
    v246 = v245;
    v251 = stack[-5];
    v245 = stack[-4];
    v245 = CC_st_extract_symcells1(env, 3, v246, v251, v245);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-7];
    v251 = v245;
    v251 = qcdr(v251);
    v251 = qcar(v251);
    stack[-5] = v251;
    v251 = v245;
    v251 = qcdr(v251);
    v251 = qcdr(v251);
    v251 = qcar(v251);
    stack[-4] = v251;
    v251 = v245;
    v251 = qcar(v251);
    if (is_number(v251)) goto v83;
    v245 = qcar(v245);
    goto v119;

v119:
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-7];
    stack[-1] = v245;
    stack[-2] = v245;
    goto v136;

v136:
    v245 = stack[-3];
    v245 = qcdr(v245);
    stack[-3] = v245;
    v245 = stack[-3];
    if (v245 == nil) goto v81;
    stack[0] = stack[-1];
    v245 = stack[-3];
    v245 = qcar(v245);
    v246 = v245;
    v251 = stack[-5];
    v245 = stack[-4];
    v245 = CC_st_extract_symcells1(env, 3, v246, v251, v245);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-7];
    v251 = v245;
    v251 = qcdr(v251);
    v251 = qcar(v251);
    stack[-5] = v251;
    v251 = v245;
    v251 = qcdr(v251);
    v251 = qcdr(v251);
    v251 = qcar(v251);
    stack[-4] = v251;
    v251 = v245;
    v251 = qcar(v251);
    if (is_number(v251)) goto v19;
    v245 = qcar(v245);
    goto v213;

v213:
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-7];
    v245 = Lrplacd(nil, stack[0], v245);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-7];
    v245 = stack[-1];
    v245 = qcdr(v245);
    stack[-1] = v245;
    goto v136;

v19:
    v251 = elt(env, 2); /* !* */
    v245 = qcar(v245);
    v245 = list2(v251, v245);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-7];
    goto v213;

v81:
    v245 = stack[-2];
    goto v42;

v42:
    v245 = cons(stack[-6], v245);
    nil = C_nil;
    if (exception_pending()) goto v252;
    v246 = v245;
    v251 = stack[-5];
    v245 = stack[-4];
    popv(8);
    return list3(v246, v251, v245);

v83:
    v251 = elt(env, 2); /* !* */
    v245 = qcar(v245);
    v245 = list2(v251, v245);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-7];
    goto v119;

v41:
    v245 = qvalue(elt(env, 1)); /* nil */
    goto v42;

v93:
    stack[-1] = stack[-4];
    v251 = stack[0];
    v245 = stack[-5];
    stack[0] = cons(v251, v245);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-7];
    v245 = stack[-4];
    v245 = add1(v245);
    nil = C_nil;
    if (exception_pending()) goto v252;
    {
        Lisp_Object v253 = stack[-1];
        Lisp_Object v73 = stack[0];
        popv(8);
        return list3(v253, v73, v245);
    }
/* error exit handlers */
v252:
    popv(8);
    return nil;
}



/* Code for binomial!-coefft!-mod!-p */

static Lisp_Object CC_binomialKcoefftKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v213, v227, v254, v255;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for binomial-coefft-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v108;
    stack[-2] = v0;
/* end of prologue */
    v213 = stack[-2];
    v237 = stack[-1];
    v237 = (Lisp_Object)lessp2(v213, v237);
    nil = C_nil;
    if (exception_pending()) goto v182;
    v237 = v237 ? lisp_true : nil;
    env = stack[-4];
    if (v237 == nil) goto v92;
    v237 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v237); }

v92:
    v213 = stack[-2];
    v237 = stack[-1];
    if (equal(v213, v237)) goto v88;
    v213 = stack[-1];
    v237 = (Lisp_Object)17; /* 1 */
    if (v213 == v237) goto v46;
    v237 = (Lisp_Object)17; /* 1 */
    stack[-3] = v237;
    stack[0] = stack[-1];
    v213 = stack[-2];
    v237 = stack[-1];
    v237 = difference2(v213, v237);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    fn = elt(env, 2); /* min */
    v237 = (*qfn2(fn))(qenv(fn), stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    stack[0] = v237;
    v237 = stack[-2];
    v237 = Lmodular_number(nil, v237);
    env = stack[-4];
    stack[-2] = v237;
    v237 = stack[-1];
    v237 = Lmodular_number(nil, v237);
    env = stack[-4];
    v237 = (Lisp_Object)17; /* 1 */
    stack[-1] = v237;
    goto v35;

v35:
    v213 = stack[0];
    v237 = stack[-1];
    v237 = difference2(v213, v237);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    v237 = Lminusp(nil, v237);
    env = stack[-4];
    if (v237 == nil) goto v129;
    v237 = stack[-3];
    v237 = (Lisp_Object)zerop(v237);
    v237 = v237 ? lisp_true : nil;
    env = stack[-4];
    if (v237 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v237 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v237); }

v129:
    v237 = stack[-1];
    v237 = Lmodular_number(nil, v237);
    env = stack[-4];
    v255 = v237;
    v254 = stack[-3];
    v227 = stack[-2];
    v213 = v255;
    v237 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v213) - int_of_fixnum(v237);
        if (w < 0) w += current_modulus;
        v237 = fixnum_of_int(w);
    }
    {   int32_t w = int_of_fixnum(v227) - int_of_fixnum(v237);
        if (w < 0) w += current_modulus;
        v237 = fixnum_of_int(w);
    }
    v237 = Lmodular_times(nil, v254, v237);
    env = stack[-4];
    v213 = v255;
    v237 = Lmodular_quotient(nil, v237, v213);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    stack[-3] = v237;
    v237 = stack[-1];
    v237 = add1(v237);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    stack[-1] = v237;
    goto v35;

v46:
    v237 = stack[-2];
    v237 = Lmodular_number(nil, v237);
    env = stack[-4];
    v213 = v237;
    v237 = v213;
    v237 = (Lisp_Object)zerop(v237);
    v237 = v237 ? lisp_true : nil;
    env = stack[-4];
    if (v237 == nil) { popv(5); return onevalue(v213); }
    v237 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v237); }

v88:
    v237 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v237); }
/* error exit handlers */
v182:
    popv(5);
    return nil;
}



/* Code for yetunknowntypeeval */

static Lisp_Object CC_yetunknowntypeeval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v108)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for yetunknowntypeeval");
#endif
    if (stack >= stacklimit)
    {
        push2(v108,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v108);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v108;
    v92 = v0;
/* end of prologue */
    v45 = v92;
    v92 = stack[0];
    fn = elt(env, 1); /* eval!-yetunknowntypeexpr */
    v45 = (*qfn2(fn))(qenv(fn), v45, v92);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-1];
    v92 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v45, v92);
    }
/* error exit handlers */
v123:
    popv(2);
    return nil;
}



setup_type const u43_setup[] =
{
    {"factor-prim-f",           CC_factorKprimKf,too_many_1,   wrong_no_1},
    {"vdplsort",                CC_vdplsort,    too_many_1,    wrong_no_1},
    {"xpartitsq",               CC_xpartitsq,   too_many_1,    wrong_no_1},
    {"latexprin",               CC_latexprin,   too_many_1,    wrong_no_1},
    {"chksymmetries&subst",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_chksymmetriesGsubst},
    {"mk_world1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_mk_world1},
    {"bc_power",                too_few_2,      CC_bc_power,   wrong_no_2},
    {"gd_simpl",                CC_gd_simpl,    too_many_1,    wrong_no_1},
    {"*ff2a",                   too_few_2,      CC_Hff2a,      wrong_no_2},
    {"cl_applysac",             too_few_2,      CC_cl_applysac,wrong_no_2},
    {"xpdiff",                  too_few_2,      CC_xpdiff,     wrong_no_2},
    {"ps:constmult-erule",      too_few_2,      CC_psTconstmultKerule,wrong_no_2},
    {"ldf-deg",                 too_few_2,      CC_ldfKdeg,    wrong_no_2},
    {"groebinvokecritm",        too_few_2,      CC_groebinvokecritm,wrong_no_2},
    {"wedgewedge",              too_few_2,      CC_wedgewedge, wrong_no_2},
    {"listnoeval",              too_few_2,      CC_listnoeval, wrong_no_2},
    {"delete_edge",             too_few_2,      CC_delete_edge,wrong_no_2},
    {"reduce-columns",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduceKcolumns},
    {"dp_prod",                 too_few_2,      CC_dp_prod,    wrong_no_2},
    {"partsym_zerop",           too_few_2,      CC_partsym_zerop,wrong_no_2},
    {"general-minus-mod-p",     CC_generalKminusKmodKp,too_many_1,wrong_no_1},
    {"ofsf_qesubiord",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_qesubiord},
    {"get*real*irreducible*rep",too_few_2,      CC_getHrealHirreducibleHrep,wrong_no_2},
    {"ps:times:",               too_few_2,      CC_psTtimesT,  wrong_no_2},
    {"vdpfmon",                 too_few_2,      CC_vdpfmon,    wrong_no_2},
    {"xvarp",                   CC_xvarp,       too_many_1,    wrong_no_1},
    {"functionp",               CC_functionp,   too_many_1,    wrong_no_1},
    {"rdzchk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rdzchk},
    {"fctins",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_fctins},
    {"ev-tades",                too_few_2,      CC_evKtades,   wrong_no_2},
    {"compactf3",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf3},
    {"affinep",                 CC_affinep,     too_many_1,    wrong_no_1},
    {"x**p-w",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_xHHpKw},
    {"radd",                    too_few_2,      CC_radd,       wrong_no_2},
    {"random-teeny-prime",      CC_randomKteenyKprime,too_many_1,wrong_no_1},
    {"bfprin0",                 CC_bfprin0,     too_many_1,    wrong_no_1},
    {"opfchk!",                 CC_opfchkB,     too_many_1,    wrong_no_1},
    {"conjsq",                  CC_conjsq,      too_many_1,    wrong_no_1},
    {"repr_n",                  CC_repr_n,      too_many_1,    wrong_no_1},
    {"ratpoly_univarp",         CC_ratpoly_univarp,too_many_1, wrong_no_1},
    {"ldf-spf-var",             CC_ldfKspfKvar, too_many_1,    wrong_no_1},
    {"xriterion_2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_xriterion_2},
    {"quotient:",               too_few_2,      CC_quotientT,  wrong_no_2},
    {"forttab",                 CC_forttab,     too_many_1,    wrong_no_1},
    {"tvectorp",                CC_tvectorp,    too_many_1,    wrong_no_1},
    {"new_provev",              too_few_2,      CC_new_provev, wrong_no_2},
    {"boolean-eval2",           CC_booleanKeval2,too_many_1,   wrong_no_1},
    {"combin",                  too_few_2,      CC_combin,     wrong_no_2},
    {"precision1",              too_few_2,      CC_precision1, wrong_no_2},
    {"equations_used",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_equations_used},
    {"pasf_sacat",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_sacat},
    {"dip_comp1",               too_few_2,      CC_dip_comp1,  wrong_no_2},
    {"mkarg",                   too_few_2,      CC_mkarg,      wrong_no_2},
    {"dsimptimes",              too_few_2,      CC_dsimptimes, wrong_no_2},
    {"nspaces",                 CC_nspaces,     too_many_1,    wrong_no_1},
    {"pnth*",                   too_few_2,      CC_pnthH,      wrong_no_2},
    {"s_world_names",           CC_s_world_names,too_many_1,   wrong_no_1},
    {"st_extract_symcells1",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_extract_symcells1},
    {"binomial-coefft-mod-p",   too_few_2,      CC_binomialKcoefftKmodKp,wrong_no_2},
    {"yetunknowntypeeval",      too_few_2,      CC_yetunknowntypeeval,wrong_no_2},
    {NULL, (one_args *)"u43", (two_args *)"14217 7323688 4429296", 0}
};

/* end of generated code */
