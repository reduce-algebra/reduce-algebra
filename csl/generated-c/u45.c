
/* $destdir\u45.c        Machine generated C code */

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


/* Code for canprod */

static Lisp_Object CC_canprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v69, v70, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for canprod");
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
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[0] = nil;
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v68 = stack[-3];
    if (!consp(v68)) goto v72;
    v68 = stack[-3];
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    goto v73;

v73:
    if (v68 == nil) goto v74;
    v68 = qvalue(elt(env, 1)); /* t */
    goto v75;

v75:
    if (v68 == nil) goto v76;
    v69 = stack[-4];
    v68 = stack[-3];
    v68 = cons(v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 3); /* cancel */
        return (*qfn1(fn))(qenv(fn), v68);
    }

v76:
    v68 = stack[-4];
    if (!consp(v68)) goto v78;
    v68 = stack[-4];
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    goto v79;

v79:
    if (v68 == nil) goto v80;
    v68 = stack[-3];
    if (!consp(v68)) goto v81;
    v68 = stack[-3];
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    goto v82;

v82:
    v68 = (v68 == nil ? lisp_true : nil);
    goto v83;

v83:
    if (v68 == nil) goto v84;
    v68 = stack[-4];
    fn = elt(env, 4); /* sfpf */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    if (v68 == nil) goto v85;
    v68 = stack[-4];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v71 = qcar(v68);
    v68 = stack[-4];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v70 = qcdr(v68);
    v69 = stack[0];
    v68 = stack[-5];
    fn = elt(env, 5); /* cprod1 */
    v68 = (*qfnn(fn))(qenv(fn), 4, v71, v70, v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v69 = v68;
    v68 = v69;
    v68 = qcar(v68);
    stack[0] = v68;
    v68 = v69;
    v68 = qcdr(v68);
    stack[-5] = v68;
    v68 = stack[-4];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    stack[-4] = v68;
    goto v76;

v85:
    v68 = stack[-3];
    fn = elt(env, 4); /* sfpf */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    if (v68 == nil) goto v86;
    v68 = stack[-3];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v71 = qcar(v68);
    v68 = stack[-3];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v70 = qcdr(v68);
    v69 = stack[-5];
    v68 = stack[0];
    fn = elt(env, 5); /* cprod1 */
    v68 = (*qfnn(fn))(qenv(fn), 4, v71, v70, v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v69 = v68;
    v68 = v69;
    v68 = qcar(v68);
    stack[-5] = v68;
    v68 = v69;
    v68 = qcdr(v68);
    stack[0] = v68;
    v68 = stack[-3];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    stack[-3] = v68;
    goto v76;

v86:
    v68 = stack[-4];
    if (!consp(v68)) goto v87;
    v68 = stack[-4];
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    goto v88;

v88:
    if (v68 == nil) goto v89;
    v68 = stack[-3];
    v68 = qcar(v68);
    v69 = qcar(v68);
    v68 = stack[-1];
    v68 = cons(v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    stack[-1] = v68;
    v68 = stack[-3];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    stack[-3] = v68;
    goto v76;

v89:
    v68 = stack[-3];
    if (!consp(v68)) goto v90;
    v68 = stack[-3];
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    goto v91;

v91:
    if (v68 == nil) goto v92;
    v68 = stack[-4];
    v68 = qcar(v68);
    v69 = qcar(v68);
    v68 = stack[-2];
    v68 = cons(v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    stack[-2] = v68;
    v68 = stack[-4];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    stack[-4] = v68;
    goto v76;

v92:
    v68 = stack[-4];
    v68 = qcar(v68);
    v69 = qcar(v68);
    v68 = stack[-2];
    v68 = cons(v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    stack[-2] = v68;
    v68 = stack[-3];
    v68 = qcar(v68);
    v69 = qcar(v68);
    v68 = stack[-1];
    v68 = cons(v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    stack[-1] = v68;
    v68 = stack[-4];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    stack[-4] = v68;
    v68 = stack[-3];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    stack[-3] = v68;
    goto v76;

v90:
    v68 = qvalue(elt(env, 1)); /* t */
    goto v91;

v87:
    v68 = qvalue(elt(env, 1)); /* t */
    goto v88;

v84:
    v69 = stack[-2];
    v68 = stack[-4];
    fn = elt(env, 6); /* reprod */
    v68 = (*qfn2(fn))(qenv(fn), v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    fn = elt(env, 6); /* reprod */
    v68 = (*qfn2(fn))(qenv(fn), stack[0], v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    stack[0] = v68;
    stack[-4] = stack[-5];
    v69 = stack[-1];
    v68 = stack[-3];
    fn = elt(env, 6); /* reprod */
    v68 = (*qfn2(fn))(qenv(fn), v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    fn = elt(env, 6); /* reprod */
    v68 = (*qfn2(fn))(qenv(fn), stack[-4], v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    stack[-5] = v68;
    v68 = stack[-5];
    fn = elt(env, 7); /* minusf */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    if (v68 == nil) goto v93;
    v68 = stack[0];
    fn = elt(env, 8); /* negf */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    stack[0] = v68;
    v68 = stack[-5];
    fn = elt(env, 8); /* negf */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    stack[-5] = v68;
    goto v93;

v93:
    v69 = stack[0];
    v68 = stack[-5];
    v68 = cons(v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    fn = elt(env, 3); /* cancel */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    stack[-5] = v68;
    v68 = stack[-5];
    v68 = qcar(v68);
    stack[0] = v68;
    v68 = stack[0];
    if (!consp(v68)) goto v94;
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    goto v95;

v95:
    if (v68 == nil) goto v96;
    v68 = qvalue(elt(env, 2)); /* nil */
    goto v97;

v97:
    if (v68 == nil) goto v98;
    v68 = stack[-2];
    stack[0] = v68;
    goto v98;

v98:
    v68 = stack[-5];
    v68 = qcdr(v68);
    stack[-5] = v68;
    v68 = stack[-5];
    if (!consp(v68)) goto v99;
    v68 = stack[-5];
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    goto v100;

v100:
    if (v68 == nil) goto v101;
    v68 = qvalue(elt(env, 2)); /* nil */
    goto v102;

v102:
    if (v68 == nil) goto v103;
    v68 = stack[-2];
    stack[-5] = v68;
    goto v103;

v103:
    v69 = stack[0];
    v68 = stack[-5];
    v68 = cons(v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 9); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v68);
    }

v101:
    v68 = stack[-5];
    v68 = qcdr(v68);
    if (v68 == nil) goto v104;
    v68 = qvalue(elt(env, 2)); /* nil */
    goto v102;

v104:
    v68 = stack[-5];
    v68 = qcar(v68);
    v69 = qcdr(v68);
    v68 = (Lisp_Object)17; /* 1 */
    if (v69 == v68) goto v105;
    v68 = qvalue(elt(env, 2)); /* nil */
    goto v102;

v105:
    v68 = stack[-5];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v69 = qcdr(v68);
    v68 = (Lisp_Object)17; /* 1 */
    if (v69 == v68) goto v106;
    v68 = qvalue(elt(env, 2)); /* nil */
    goto v102;

v106:
    v68 = stack[-5];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v68 = qcar(v68);
    stack[-2] = v68;
    v69 = v68;
    v68 = v69;
    if (!consp(v68)) goto v107;
    v68 = v69;
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    v68 = (v68 == nil ? lisp_true : nil);
    goto v102;

v107:
    v68 = qvalue(elt(env, 2)); /* nil */
    goto v102;

v99:
    v68 = qvalue(elt(env, 1)); /* t */
    goto v100;

v96:
    v68 = stack[0];
    v68 = qcdr(v68);
    if (v68 == nil) goto v108;
    v68 = qvalue(elt(env, 2)); /* nil */
    goto v97;

v108:
    v68 = stack[0];
    v68 = qcar(v68);
    v69 = qcdr(v68);
    v68 = (Lisp_Object)17; /* 1 */
    if (v69 == v68) goto v109;
    v68 = qvalue(elt(env, 2)); /* nil */
    goto v97;

v109:
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v69 = qcdr(v68);
    v68 = (Lisp_Object)17; /* 1 */
    if (v69 == v68) goto v110;
    v68 = qvalue(elt(env, 2)); /* nil */
    goto v97;

v110:
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v68 = qcar(v68);
    stack[-2] = v68;
    v69 = v68;
    v68 = v69;
    if (!consp(v68)) goto v111;
    v68 = v69;
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    v68 = (v68 == nil ? lisp_true : nil);
    goto v97;

v111:
    v68 = qvalue(elt(env, 2)); /* nil */
    goto v97;

v94:
    v68 = qvalue(elt(env, 1)); /* t */
    goto v95;

v81:
    v68 = qvalue(elt(env, 1)); /* t */
    goto v82;

v80:
    v68 = qvalue(elt(env, 1)); /* t */
    goto v83;

v78:
    v68 = qvalue(elt(env, 1)); /* t */
    goto v79;

v74:
    v68 = stack[-3];
    v68 = qcdr(v68);
    if (!(v68 == nil)) goto v75;
    v68 = stack[-4];
    if (!consp(v68)) goto v112;
    v68 = stack[-4];
    v68 = qcar(v68);
    v68 = (consp(v68) ? nil : lisp_true);
    goto v113;

v113:
    if (v68 == nil) goto v114;
    v68 = qvalue(elt(env, 2)); /* nil */
    goto v75;

v114:
    v68 = stack[-4];
    v68 = qcdr(v68);
    goto v75;

v112:
    v68 = qvalue(elt(env, 1)); /* t */
    goto v113;

v72:
    v68 = qvalue(elt(env, 1)); /* t */
    goto v73;
/* error exit handlers */
v77:
    popv(7);
    return nil;
}



/* Code for ofsf_multsurep */

static Lisp_Object CC_ofsf_multsurep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v120, v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_multsurep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v121 = v1;
    v122 = v0;
/* end of prologue */
    v119 = v122;
    v120 = qcar(v119);
    v119 = elt(env, 1); /* equal */
    if (v120 == v119) goto v123;
    v119 = v122;
    v120 = v121;
    {
        fn = elt(env, 2); /* ofsf_multsurep!-neq */
        return (*qfn2(fn))(qenv(fn), v119, v120);
    }

v123:
    v119 = v122;
    v120 = v121;
    {
        fn = elt(env, 3); /* ofsf_multsurep!-equal */
        return (*qfn2(fn))(qenv(fn), v119, v120);
    }
}



/* Code for ldt!-dep */

static Lisp_Object CC_ldtKdep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldt-dep");
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
    v117 = v0;
/* end of prologue */
    fn = elt(env, 3); /* ldt!-tvar */
    v126 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    v117 = qvalue(elt(env, 1)); /* depl!* */
    v117 = Lassoc(nil, v126, v117);
    v126 = v117;
    v117 = v126;
    if (v117 == nil) goto v73;
    v117 = v126;
    v117 = qcdr(v117);
    { popv(1); return onevalue(v117); }

v73:
    v117 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v117); }
/* error exit handlers */
v127:
    popv(1);
    return nil;
}



/* Code for findhc */

static Lisp_Object CC_findhc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v146;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findhc");
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
    v145 = v0;
/* end of prologue */
    stack[-4] = nil;
    v146 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v146; /* njsi */
    stack[-2] = v146;
    v146 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v146; /* jsi */
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v146 = qvalue(elt(env, 5)); /* maxvar */
    v145 = plus2(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    v146 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v145/(16/CELL)));
    v145 = (Lisp_Object)65; /* 4 */
    v145 = *(Lisp_Object *)((char *)v146 + (CELL-TAG_VECTOR) + ((int32_t)v145/(16/CELL)));
    stack[-1] = v145;
    goto v118;

v118:
    v145 = stack[-1];
    if (v145 == nil) goto v148;
    v145 = stack[-1];
    v145 = qcar(v145);
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v146 = qvalue(elt(env, 5)); /* maxvar */
    v145 = qcar(v145);
    stack[-3] = v145;
    v145 = plus2(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    v146 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v145/(16/CELL)));
    v145 = (Lisp_Object)1; /* 0 */
    v145 = *(Lisp_Object *)((char *)v146 + (CELL-TAG_VECTOR) + ((int32_t)v145/(16/CELL)));
    if (v145 == nil) goto v149;
    v146 = stack[-3];
    v145 = qvalue(elt(env, 3)); /* jsi */
    v145 = cons(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    qvalue(elt(env, 3)) = v145; /* jsi */
    v145 = qvalue(elt(env, 1)); /* njsi */
    v145 = add1(v145);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    qvalue(elt(env, 1)) = v145; /* njsi */
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v146 = qvalue(elt(env, 5)); /* maxvar */
    v145 = stack[-3];
    v145 = plus2(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    v146 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v145/(16/CELL)));
    v145 = (Lisp_Object)17; /* 1 */
    v145 = *(Lisp_Object *)((char *)v146 + (CELL-TAG_VECTOR) + ((int32_t)v145/(16/CELL)));
    v145 = qcar(v145);
    v146 = qcar(v145);
    stack[0] = v146;
    v145 = stack[-2];
    v145 = (Lisp_Object)greaterp2(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v145 = v145 ? lisp_true : nil;
    env = stack[-5];
    if (v145 == nil) goto v149;
    v145 = stack[0];
    stack[-2] = v145;
    v145 = stack[-3];
    stack[-4] = v145;
    goto v149;

v149:
    v145 = stack[-1];
    v145 = qcdr(v145);
    stack[-1] = v145;
    goto v118;

v148:
    v145 = qvalue(elt(env, 3)); /* jsi */
    v145 = Lreverse(nil, v145);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    qvalue(elt(env, 3)) = v145; /* jsi */
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v147:
    popv(6);
    return nil;
}



/* Code for gvarlis */

static Lisp_Object CC_gvarlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gvarlis");
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
    v151 = v0;
/* end of prologue */
    v67 = v151;
    v151 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* gvarlis1 */
    v67 = (*qfn2(fn))(qenv(fn), v67, v151);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[0];
    v151 = elt(env, 2); /* ordop */
    {
        popv(1);
        fn = elt(env, 4); /* sort */
        return (*qfn2(fn))(qenv(fn), v67, v151);
    }
/* error exit handlers */
v73:
    popv(1);
    return nil;
}



/* Code for expt!-separate */

static Lisp_Object CC_exptKseparate(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v76, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expt-separate");
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
    v76 = stack[-1];
    v154 = elt(env, 1); /* expt */
    if (!consp(v76)) goto v125;
    v76 = qcar(v76);
    if (!(v76 == v154)) goto v125;
    v154 = stack[-1];
    v154 = qcdr(v154);
    v76 = qcar(v154);
    v154 = stack[0];
    fn = elt(env, 5); /* depends */
    v154 = (*qfn2(fn))(qenv(fn), v76, v154);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-2];
    if (!(v154 == nil)) goto v150;
    v154 = stack[-1];
    v154 = qcdr(v154);
    v154 = qcdr(v154);
    v76 = qcar(v154);
    v154 = elt(env, 3); /* plus */
    v154 = Leqcar(nil, v76, v154);
    env = stack[-2];
    v154 = (v154 == nil ? lisp_true : nil);
    goto v150;

v150:
    if (v154 == nil) goto v156;
    v154 = qvalue(elt(env, 4)); /* nil */
    { popv(3); return onevalue(v154); }

v156:
    v154 = stack[-1];
    v154 = qcdr(v154);
    v154 = qcdr(v154);
    v154 = qcar(v154);
    v137 = qcdr(v154);
    v154 = stack[-1];
    v154 = qcdr(v154);
    v76 = qcar(v154);
    v154 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* expt!-separate1 */
        return (*qfnn(fn))(qenv(fn), 3, v137, v76, v154);
    }

v125:
    v154 = qvalue(elt(env, 2)); /* t */
    goto v150;
/* error exit handlers */
v155:
    popv(3);
    return nil;
}



/* Code for atlas_edges */

static Lisp_Object CC_atlas_edges(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for atlas_edges");
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
    v157 = stack[0];
    v157 = qcar(v157);
    fn = elt(env, 1); /* map__edges */
    stack[-1] = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-2];
    v157 = stack[0];
    v157 = qcdr(v157);
    v157 = qcdr(v157);
    v157 = qcar(v157);
    fn = elt(env, 2); /* den__edges */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-2];
    fn = elt(env, 3); /* union_edges */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v157);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-2];
    v157 = stack[0];
    v157 = qcdr(v157);
    v157 = qcar(v157);
    fn = elt(env, 4); /* coeff_edges */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-2];
    {
        Lisp_Object v74 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* union_edges */
        return (*qfn2(fn))(qenv(fn), v74, v157);
    }
/* error exit handlers */
v158:
    popv(3);
    return nil;
}



/* Code for subeval1 */

static Lisp_Object CC_subeval1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v133, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subeval1");
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

v125:
    v164 = stack[-1];
    if (v164 == nil) goto v150;
    v164 = stack[-1];
    v164 = qcar(v164);
    v133 = qcar(v164);
    v164 = stack[-1];
    v164 = qcar(v164);
    v164 = qcdr(v164);
    if (!(equal(v133, v164))) goto v150;
    v164 = stack[-1];
    v164 = qcdr(v164);
    stack[-1] = v164;
    goto v125;

v150:
    v164 = stack[-1];
    if (v164 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v164 = stack[0];
    fn = elt(env, 8); /* getrtype */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    v134 = v164;
    if (v164 == nil) goto v166;
    v133 = v134;
    v164 = elt(env, 2); /* subfn */
    v164 = get(v133, v164);
    env = stack[-2];
    v133 = v164;
    if (v164 == nil) goto v154;
    v134 = v133;
    v133 = stack[-1];
    v164 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v134, v133, v164);

v154:
    v164 = elt(env, 3); /* "No substitution defined for type" */
    v133 = v134;
    v164 = list2(v164, v133);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    v133 = v164;
    v164 = v133;
    qvalue(elt(env, 4)) = v164; /* errmsg!* */
    v164 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v164 == nil)) goto v78;
    v164 = v133;
    fn = elt(env, 9); /* lprie */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    goto v78;

v78:
    v164 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    goto v166;

v166:
    v164 = stack[0];
    fn = elt(env, 10); /* simp */
    v133 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    v164 = stack[-1];
    fn = elt(env, 11); /* subsq */
    v164 = (*qfn2(fn))(qenv(fn), v133, v164);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    stack[-1] = v164;
    v164 = qvalue(elt(env, 6)); /* t */
    stack[0] = qvalue(elt(env, 7)); /* !*sub2 */
    qvalue(elt(env, 7)) = v164; /* !*sub2 */
    v164 = stack[-1];
    fn = elt(env, 12); /* subs2 */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    stack[-1] = v164;
    qvalue(elt(env, 7)) = stack[0]; /* !*sub2 */
    v164 = stack[-1];
    {
        popv(3);
        fn = elt(env, 13); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v164);
    }
/* error exit handlers */
v85:
    env = stack[-2];
    qvalue(elt(env, 7)) = stack[0]; /* !*sub2 */
    popv(3);
    return nil;
v165:
    popv(3);
    return nil;
}



/* Code for mv2sf */

static Lisp_Object CC_mv2sf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v170, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv2sf");
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
    goto v124;

v124:
    v169 = stack[-1];
    if (v169 == nil) goto v150;
    v169 = stack[-1];
    v169 = qcar(v169);
    v139 = qcar(v169);
    v169 = stack[-1];
    v169 = qcar(v169);
    v170 = qcdr(v169);
    v169 = stack[0];
    fn = elt(env, 2); /* mv2sf1 */
    v170 = (*qfnn(fn))(qenv(fn), 3, v139, v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v169 = stack[-2];
    v169 = cons(v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    stack[-2] = v169;
    v169 = stack[-1];
    v169 = qcdr(v169);
    stack[-1] = v169;
    goto v124;

v150:
    v169 = qvalue(elt(env, 1)); /* nil */
    v170 = v169;
    goto v125;

v125:
    v169 = stack[-2];
    if (v169 == nil) { popv(4); return onevalue(v170); }
    v169 = stack[-2];
    v169 = qcar(v169);
    fn = elt(env, 3); /* addf */
    v169 = (*qfn2(fn))(qenv(fn), v169, v170);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v170 = v169;
    v169 = stack[-2];
    v169 = qcdr(v169);
    stack[-2] = v169;
    goto v125;
/* error exit handlers */
v161:
    popv(4);
    return nil;
}



/* Code for tensor_has_dummy_idx */

static Lisp_Object CC_tensor_has_dummy_idx(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tensor_has_dummy_idx");
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

v6:
    v171 = stack[-1];
    if (v171 == nil) goto v150;
    v171 = stack[-1];
    v158 = qcar(v171);
    v171 = stack[0];
    fn = elt(env, 3); /* smember */
    v171 = (*qfn2(fn))(qenv(fn), v158, v171);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    if (v171 == nil) goto v127;
    v171 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v171); }

v127:
    v171 = stack[-1];
    v171 = qcdr(v171);
    stack[-1] = v171;
    goto v6;

v150:
    v171 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v171); }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for lowestdeg */

static Lisp_Object MS_CDECL CC_lowestdeg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v173;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "lowestdeg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lowestdeg");
#endif
    if (stack >= stacklimit)
    {
        push3(v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v128);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v172 = v128;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v124:
    v173 = stack[-1];
    if (v173 == nil) { popv(3); return onevalue(v172); }
    v172 = stack[-1];
    if (!consp(v172)) goto v117;
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = (consp(v172) ? nil : lisp_true);
    goto v116;

v116:
    if (v172 == nil) goto v121;
    v172 = qvalue(elt(env, 1)); /* t */
    goto v151;

v151:
    if (v172 == nil) goto v149;
    v172 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v172); }

v149:
    v172 = stack[-1];
    v172 = qcdr(v172);
    v173 = v172;
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v172 = qcdr(v172);
    stack[-1] = v173;
    goto v124;

v121:
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v173 = qcar(v172);
    v172 = stack[0];
    v172 = Lneq(nil, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    goto v151;

v117:
    v172 = qvalue(elt(env, 1)); /* t */
    goto v116;
/* error exit handlers */
v139:
    popv(3);
    return nil;
}



/* Code for vp1 */

static Lisp_Object MS_CDECL CC_vp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v152, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vp1");
#endif
    if (stack >= stacklimit)
    {
        push3(v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v128);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v128;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v161 = nil;
    goto v124;

v124:
    v160 = stack[0];
    if (v160 == nil) goto v63;
    v152 = stack[-2];
    v160 = stack[0];
    v160 = qcar(v160);
    if (equal(v152, v160)) goto v119;
    v160 = (Lisp_Object)1; /* 0 */
    v152 = v161;
    v160 = cons(v160, v152);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    v161 = v160;
    v160 = stack[0];
    v160 = qcdr(v160);
    stack[0] = v160;
    goto v124;

v119:
    stack[-2] = v161;
    v160 = stack[0];
    v160 = qcdr(v160);
    fn = elt(env, 2); /* vp2 */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    v160 = cons(stack[-1], v160);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    {
        Lisp_Object v76 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v76, v160);
    }

v63:
    stack[0] = v161;
    v160 = elt(env, 1); /* "Var not in z-list after all" */
    fn = elt(env, 4); /* interr */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-3];
    {
        Lisp_Object v137 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v137, v160);
    }
/* error exit handlers */
v154:
    popv(4);
    return nil;
}



/* Code for available!*p */

static Lisp_Object CC_availableHp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for available*p");
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
    v163 = stack[0];
    if (symbolp(v163)) goto v72;
    v163 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v163 == nil)) goto v148;
    v163 = elt(env, 2); /* "this is no group identifier" */
    fn = elt(env, 4); /* lprie */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-1];
    goto v148;

v148:
    v163 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-1];
    goto v72;

v72:
    v163 = stack[0];
    v171 = elt(env, 3); /* available */
        popv(2);
        return Lflagp(nil, v163, v171);
/* error exit handlers */
v74:
    popv(2);
    return nil;
}



/* Code for pasf_mkop */

static Lisp_Object CC_pasf_mkop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v153, v149, v175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_mkop");
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
    v149 = v1;
    v175 = v0;
/* end of prologue */
    v153 = v175;
    v142 = elt(env, 1); /* (cong ncong) */
    v142 = Lmemq(nil, v153, v142);
    if (v142 == nil) { popv(2); return onevalue(v175); }
    stack[0] = v175;
    v142 = v149;
    if (v142 == nil) goto v127;
    v142 = v149;
    goto v73;

v73:
    {
        Lisp_Object v176 = stack[0];
        popv(2);
        return cons(v176, v142);
    }

v127:
    v142 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v142 == nil)) goto v74;
    v142 = elt(env, 3); /* "Modulo 0 congruence created" */
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-1];
    fn = elt(env, 4); /* lprie */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-1];
    goto v74;

v74:
    v142 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v177;
    v142 = nil;
    goto v73;
/* error exit handlers */
v177:
    popv(2);
    return nil;
}



/* Code for cgp_cp */

static Lisp_Object CC_cgp_cp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_cp");
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
    v127 = stack[-3];
    fn = elt(env, 1); /* cgp_hp */
    stack[-4] = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    v127 = stack[-3];
    fn = elt(env, 2); /* cgp_rp */
    stack[-2] = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    v127 = stack[-3];
    fn = elt(env, 3); /* cgp_sugar */
    stack[-1] = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    v127 = stack[-3];
    fn = elt(env, 4); /* cgp_number */
    stack[0] = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    v127 = stack[-3];
    fn = elt(env, 5); /* cgp_ci */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    {
        Lisp_Object v115 = stack[-4];
        Lisp_Object v64 = stack[-2];
        Lisp_Object v119 = stack[-1];
        Lisp_Object v120 = stack[0];
        popv(6);
        fn = elt(env, 6); /* cgp_mk */
        return (*qfnn(fn))(qenv(fn), 5, v115, v64, v119, v120, v127);
    }
/* error exit handlers */
v74:
    popv(6);
    return nil;
}



/* Code for formopr */

static Lisp_Object MS_CDECL CC_formopr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v178, v176, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formopr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formopr");
#endif
    if (stack >= stacklimit)
    {
        push3(v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v128);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v175 = v128;
    v176 = v1;
    v177 = v0;
/* end of prologue */
    v178 = v175;
    v175 = elt(env, 1); /* symbolic */
    if (v178 == v175) goto v123;
    stack[0] = elt(env, 4); /* operator */
    v175 = v177;
    v175 = qcdr(v175);
    v178 = v176;
    fn = elt(env, 5); /* mkarg */
    v175 = (*qfn2(fn))(qenv(fn), v175, v178);
    nil = C_nil;
    if (exception_pending()) goto v167;
    {
        Lisp_Object v168 = stack[0];
        popv(3);
        return list2(v168, v175);
    }

v123:
    stack[-1] = elt(env, 2); /* flag */
    v175 = v177;
    v175 = qcdr(v175);
    stack[0] = Lmkquote(nil, v175);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v175 = elt(env, 3); /* opfn */
    v175 = Lmkquote(nil, v175);
    nil = C_nil;
    if (exception_pending()) goto v167;
    {
        Lisp_Object v172 = stack[-1];
        Lisp_Object v173 = stack[0];
        popv(3);
        return list3(v172, v173, v175);
    }
/* error exit handlers */
v167:
    popv(3);
    return nil;
}



/* Code for search4facf */

static Lisp_Object MS_CDECL CC_search4facf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "search4facf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for search4facf");
#endif
    if (stack >= stacklimit)
    {
        push3(v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v128);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v128;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v140 = stack[-3];
    if (v140 == nil) goto v143;
    v140 = stack[-3];
    v140 = qcar(v140);
    stack[-5] = v140;
    goto v126;

v126:
    v140 = stack[-5];
    if (v140 == nil) goto v171;
    stack[-1] = stack[-4];
    v140 = stack[-3];
    stack[0] = qcdr(v140);
    v140 = stack[-5];
    v160 = qcar(v140);
    v140 = stack[-2];
    v140 = cons(v160, v140);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-6];
    v140 = CC_search4facf(env, 3, stack[-1], stack[0], v140);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-6];
    v160 = v140;
    v140 = v160;
    if (!(v140 == nil)) { popv(7); return onevalue(v160); }
    v140 = stack[-5];
    v140 = qcdr(v140);
    stack[-5] = v140;
    goto v126;

v171:
    v140 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v140); }

v143:
    v160 = stack[-4];
    v140 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* tryfactorf */
        return (*qfn2(fn))(qenv(fn), v160, v140);
    }
/* error exit handlers */
v76:
    popv(7);
    return nil;
}



/* Code for powmtch */

static Lisp_Object MS_CDECL CC_powmtch(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v79, v78, v181, v182;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powmtch");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powmtch");
#endif
    if (stack >= stacklimit)
    {
        push3(v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v128);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v60 = v128;
    v79 = v1;
    v78 = v0;
/* end of prologue */

v183:
    v181 = v79;
    if (v181 == nil) goto v35;
    v182 = v78;
    v181 = v79;
    v181 = qcar(v181);
    v181 = Latsoc(nil, v182, v181);
    v182 = v181;
    v181 = v182;
    if (v181 == nil) goto v171;
    v181 = v182;
    v182 = qcdr(v181);
    v181 = v60;
    v181 = (equal(v182, v181) ? lisp_true : nil);
    goto v163;

v163:
    if (v181 == nil) goto v76;
    v181 = v79;
    stack[0] = qcar(v181);
    v79 = qcdr(v79);
    v60 = CC_powmtch(env, 3, v78, v79, v60);
    nil = C_nil;
    if (exception_pending()) goto v184;
    {
        Lisp_Object v185 = stack[0];
        popv(1);
        return cons(v185, v60);
    }

v76:
    v79 = qcdr(v79);
    goto v183;

v171:
    v181 = qvalue(elt(env, 2)); /* t */
    goto v163;

v35:
    v60 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v60); }
/* error exit handlers */
v184:
    popv(1);
    return nil;
}



/* Code for simp!:ps!: */

static Lisp_Object CC_simpTpsT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp:ps:");
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
    v186 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!:ps1 */
    v148 = (*qfn1(fn))(qenv(fn), v186);
    errexit();
    v186 = (Lisp_Object)17; /* 1 */
    return cons(v148, v186);
}



/* Code for dipcontevmin */

static Lisp_Object CC_dipcontevmin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v155, v58;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcontevmin");
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
    v58 = nil;
    goto v150;

v150:
    v187 = stack[-1];
    if (v187 == nil) goto v177;
    v187 = stack[0];
    if (v187 == nil) goto v177;
    v187 = stack[-1];
    v155 = qcar(v187);
    v187 = stack[0];
    v187 = qcar(v187);
    if (((int32_t)(v155)) < ((int32_t)(v187))) goto v157;
    v187 = stack[0];
    v187 = qcar(v187);
    goto v116;

v116:
    v155 = v58;
    v187 = cons(v187, v155);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-2];
    v58 = v187;
    v187 = stack[-1];
    v187 = qcdr(v187);
    stack[-1] = v187;
    v187 = stack[0];
    v187 = qcdr(v187);
    stack[0] = v187;
    goto v150;

v157:
    v187 = stack[-1];
    v187 = qcar(v187);
    goto v116;

v177:
    v187 = v58;
    if (v187 == nil) goto v176;
    v155 = (Lisp_Object)1; /* 0 */
    v187 = v58;
    v187 = qcar(v187);
    if (!(v155 == v187)) goto v176;
    v187 = v58;
    v187 = qcdr(v187);
    v58 = v187;
    goto v177;

v176:
    v187 = v58;
        popv(3);
        return Lnreverse(nil, v187);
/* error exit handlers */
v180:
    popv(3);
    return nil;
}



/* Code for groebsimpcontnormalform */

static Lisp_Object CC_groebsimpcontnormalform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsimpcontnormalform");
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
    stack[-2] = v0;
/* end of prologue */
    v78 = stack[-2];
    if (v78 == nil) goto v150;
    v78 = stack[-2];
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    v78 = qcar(v78);
    v78 = (v78 == nil ? lisp_true : nil);
    goto v124;

v124:
    if (!(v78 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v78 = stack[-2];
    fn = elt(env, 4); /* gsugar */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[0] = v78;
    v78 = stack[-2];
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    v78 = qcar(v78);
    stack[-3] = v78;
    v78 = stack[-2];
    fn = elt(env, 5); /* vdpsimpcont */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-2] = v78;
    v181 = stack[-2];
    v78 = stack[0];
    fn = elt(env, 6); /* gsetsugar */
    v78 = (*qfn2(fn))(qenv(fn), v181, v78);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v78 = qvalue(elt(env, 2)); /* !*groebprot */
    if (v78 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v181 = stack[-3];
    v78 = stack[-2];
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    v78 = qcar(v78);
    if (equal(v181, v78)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-1] = elt(env, 3); /* quotient */
    v78 = stack[-2];
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    v78 = qcar(v78);
    fn = elt(env, 7); /* vbc2a */
    stack[0] = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v78 = stack[-3];
    fn = elt(env, 7); /* vbc2a */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v78 = list3(stack[-1], stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    fn = elt(env, 8); /* reval */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    fn = elt(env, 9); /* groebreductionprotocol2 */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v188;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v150:
    v78 = qvalue(elt(env, 1)); /* t */
    goto v124;
/* error exit handlers */
v188:
    popv(5);
    return nil;
}



/* Code for let3 */

static Lisp_Object MS_CDECL CC_let3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, Lisp_Object v5,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v216, v217, v218, v219, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "let3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for let3");
#endif
    if (stack >= stacklimit)
    {
        push5(v4,v5,v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v128,v5,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-2] = v5;
    stack[-3] = v128;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v215 = stack[-5];
    stack[-6] = v215;
    v215 = stack[-6];
    if (v215 == nil) goto v75;
    v215 = stack[-6];
    if (is_number(v215)) goto v179;
    v215 = stack[-4];
    fn = elt(env, 9); /* getrtype */
    v215 = (*qfn1(fn))(qenv(fn), v215);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    stack[0] = v215;
    v215 = stack[-2];
    if (v215 == nil) goto v139;
    v215 = stack[-6];
    if (!(symbolp(v215))) goto v139;
    v216 = stack[-6];
    v215 = elt(env, 5); /* rtype */
    v215 = Lremprop(nil, v216, v215);
    env = stack[-7];
    v216 = stack[-6];
    v215 = elt(env, 6); /* avalue */
    v215 = Lremprop(nil, v216, v215);
    env = stack[-7];
    goto v139;

v139:
    v215 = stack[-6];
    fn = elt(env, 9); /* getrtype */
    v215 = (*qfn1(fn))(qenv(fn), v215);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    v217 = v215;
    if (v215 == nil) goto v188;
    v216 = v217;
    v215 = elt(env, 7); /* typeletfn */
    v215 = get(v216, v215);
    env = stack[-7];
    v216 = v215;
    if (v215 == nil) goto v221;
    stack[-3] = v216;
    stack[-5] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v217;
    v215 = stack[-4];
    fn = elt(env, 9); /* getrtype */
    v215 = (*qfn1(fn))(qenv(fn), v215);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    v215 = list2(stack[-2], v215);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    v215 = list3star(stack[-5], stack[-1], stack[0], v215);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    {
        Lisp_Object v84 = stack[-3];
        popv(8);
        fn = elt(env, 10); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v84, v215);
    }

v221:
    stack[-3] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v217;
    v215 = stack[-4];
    fn = elt(env, 9); /* getrtype */
    v215 = (*qfn1(fn))(qenv(fn), v215);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    {
        Lisp_Object v222 = stack[-3];
        Lisp_Object v223 = stack[-1];
        Lisp_Object v224 = stack[0];
        Lisp_Object v225 = stack[-2];
        popv(8);
        fn = elt(env, 11); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v222, v223, v224, v225, v215);
    }

v188:
    v215 = stack[0];
    if (v215 == nil) goto v92;
    v216 = stack[0];
    v215 = elt(env, 8); /* yetunknowntype */
    if (v216 == v215) goto v92;
    v216 = stack[0];
    v215 = elt(env, 7); /* typeletfn */
    v215 = get(v216, v215);
    env = stack[-7];
    v216 = v215;
    if (v215 == nil) goto v226;
    stack[-3] = v216;
    stack[-5] = stack[-6];
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    v216 = stack[-2];
    v215 = stack[0];
    v215 = list2(v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    v215 = list3star(stack[-5], stack[-4], stack[-1], v215);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    {
        Lisp_Object v38 = stack[-3];
        popv(8);
        fn = elt(env, 10); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v38, v215);
    }

v226:
    v219 = stack[-6];
    v218 = stack[-4];
    v217 = qvalue(elt(env, 3)); /* nil */
    v216 = stack[-2];
    v215 = stack[0];
    {
        popv(8);
        fn = elt(env, 11); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v219, v218, v217, v216, v215);
    }

v92:
    v220 = stack[-5];
    v219 = stack[-4];
    v218 = stack[-3];
    v217 = stack[-6];
    v216 = stack[-2];
    v215 = stack[-1];
    fn = elt(env, 12); /* letscalar */
    v215 = (*qfnn(fn))(qenv(fn), 6, v220, v219, v218, v217, v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v215 = nil;
    { popv(8); return onevalue(v215); }

v179:
    v219 = elt(env, 1); /* "Substitution for" */
    v218 = stack[-5];
    v217 = elt(env, 2); /* "not allowed" */
    v216 = qvalue(elt(env, 3)); /* nil */
    v215 = qvalue(elt(env, 4)); /* t */
    {
        popv(8);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v219, v218, v217, v216, v215);
    }

v75:
    v215 = (Lisp_Object)1; /* 0 */
    stack[-5] = v215;
    v219 = elt(env, 1); /* "Substitution for" */
    v218 = stack[-5];
    v217 = elt(env, 2); /* "not allowed" */
    v216 = qvalue(elt(env, 3)); /* nil */
    v215 = qvalue(elt(env, 4)); /* t */
    {
        popv(8);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v219, v218, v217, v216, v215);
    }
/* error exit handlers */
v37:
    popv(8);
    return nil;
}



/* Code for exptbf */

static Lisp_Object MS_CDECL CC_exptbf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v176, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "exptbf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptbf");
#endif
    if (stack >= stacklimit)
    {
        push3(v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v128);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v128;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v35:
    v176 = stack[-1];
    v176 = Levenp(nil, v176);
    env = stack[-3];
    if (!(v176 == nil)) goto v117;
    v177 = stack[0];
    v176 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v176 = (*qfn2(fn))(qenv(fn), v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    stack[0] = v176;
    goto v117;

v117:
    v177 = stack[-1];
    v176 = (Lisp_Object)-15; /* -1 */
    v176 = ash(v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    stack[-1] = v176;
    v177 = stack[-1];
    v176 = (Lisp_Object)1; /* 0 */
    if (v177 == v176) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v177 = stack[-2];
    v176 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v176 = (*qfn2(fn))(qenv(fn), v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    stack[-2] = v176;
    goto v35;
/* error exit handlers */
v168:
    popv(4);
    return nil;
}



/* Code for rlval */

static Lisp_Object CC_rlval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v246, v247, v248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rlval");
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
    stack[-5] = v1;
    v247 = v0;
/* end of prologue */
    v246 = v247;
    if (!consp(v246)) goto v125;
    v246 = v247;
    v246 = qcar(v246);
    v246 = (consp(v246) ? nil : lisp_true);
    goto v150;

v150:
    if (!(v246 == nil)) { popv(8); return onevalue(v247); }
    v246 = stack[-5];
    if (!consp(v246)) goto v126;
    v246 = stack[-5];
    v246 = qcdr(v246);
    v248 = qcar(v246);
    v246 = (Lisp_Object)1; /* 0 */
    v246 = (v248 == v246 ? lisp_true : nil);
    goto v117;

v117:
    if (v246 == nil) goto v187;
    v246 = v247;
    v246 = qcar(v246);
    v248 = qcar(v246);
    v246 = (Lisp_Object)1; /* 0 */
    if (v248 == v246) goto v113;
    v246 = (Lisp_Object)1; /* 0 */
    {
        popv(8);
        fn = elt(env, 5); /* r2flbf */
        return (*qfn1(fn))(qenv(fn), v246);
    }

v113:
    v246 = v247;
    v246 = qcar(v246);
    v246 = qcdr(v246);
    { popv(8); return onevalue(v246); }

v187:
    v248 = stack[-5];
    v246 = elt(env, 2); /* !:rd!: */
    if (!consp(v248)) goto v249;
    v248 = qcar(v248);
    if (!(v248 == v246)) goto v249;
    v246 = stack[-5];
    v246 = qcdr(v246);
    v246 = (consp(v246) ? nil : lisp_true);
    v246 = (v246 == nil ? lisp_true : nil);
    goto v154;

v154:
    stack[-4] = v246;
    v246 = v247;
    fn = elt(env, 6); /* ncoeffs */
    v246 = (*qfn1(fn))(qenv(fn), v246);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-7];
    v246 = qcdr(v246);
    v247 = v246;
    v246 = qcar(v246);
    stack[-6] = v246;
    v246 = v247;
    v246 = qcdr(v246);
    stack[-3] = v246;
    goto v82;

v82:
    v246 = stack[-3];
    if (v246 == nil) goto v59;
    v246 = stack[-3];
    v246 = qcar(v246);
    stack[-2] = v246;
    v246 = stack[-4];
    if (v246 == nil) goto v205;
    stack[-1] = elt(env, 2); /* !:rd!: */
    v246 = stack[-5];
    v246 = qcdr(v246);
    v247 = qcar(v246);
    v246 = stack[-6];
    v246 = qcdr(v246);
    v246 = qcar(v246);
    stack[0] = times2(v247, v246);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-7];
    v246 = stack[-5];
    v246 = qcdr(v246);
    v247 = qcdr(v246);
    v246 = stack[-6];
    v246 = qcdr(v246);
    v246 = qcdr(v246);
    v246 = plus2(v247, v246);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-7];
    v246 = list2star(stack[-1], stack[0], v246);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-7];
    goto v250;

v250:
    stack[-6] = v246;
    v246 = stack[-2];
    if (v246 == nil) goto v251;
    v246 = stack[-4];
    if (v246 == nil) goto v252;
    v247 = stack[-2];
    v246 = stack[-6];
    fn = elt(env, 7); /* plus!: */
    v246 = (*qfn2(fn))(qenv(fn), v247, v246);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-7];
    goto v53;

v53:
    stack[-6] = v246;
    goto v251;

v251:
    v246 = stack[-3];
    v246 = qcdr(v246);
    stack[-3] = v246;
    goto v82;

v252:
    v247 = stack[-6];
    v246 = stack[-2];
    v246 = plus2(v247, v246);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-7];
    goto v53;

v205:
    v247 = stack[-5];
    v246 = stack[-6];
    v246 = times2(v247, v246);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-7];
    goto v250;

v59:
    v246 = stack[-4];
    if (v246 == nil) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v246 = stack[-6];
    v246 = qcdr(v246);
    v246 = qcar(v246);
    v248 = v246;
    v247 = v248;
    v246 = (Lisp_Object)1; /* 0 */
    if (v247 == v246) goto v253;
    v247 = v248;
    v246 = qvalue(elt(env, 4)); /* !:bprec!: */
    fn = elt(env, 8); /* inorm */
    v246 = (*qfn2(fn))(qenv(fn), v247, v246);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-7];
    v248 = v246;
    stack[-1] = elt(env, 2); /* !:rd!: */
    v246 = v248;
    stack[0] = qcar(v246);
    v246 = v248;
    v247 = qcdr(v246);
    v246 = stack[-6];
    v246 = qcdr(v246);
    v246 = qcdr(v246);
    v246 = plus2(v247, v246);
    nil = C_nil;
    if (exception_pending()) goto v223;
    {
        Lisp_Object v224 = stack[-1];
        Lisp_Object v225 = stack[0];
        popv(8);
        return list2star(v224, v225, v246);
    }

v253:
    v248 = elt(env, 2); /* !:rd!: */
    v247 = (Lisp_Object)1; /* 0 */
    v246 = (Lisp_Object)1; /* 0 */
    popv(8);
    return list2star(v248, v247, v246);

v249:
    v246 = qvalue(elt(env, 3)); /* nil */
    goto v154;

v126:
    v246 = stack[-5];
    v246 = (Lisp_Object)zerop(v246);
    v246 = v246 ? lisp_true : nil;
    env = stack[-7];
    goto v117;

v125:
    v246 = qvalue(elt(env, 1)); /* t */
    goto v150;
/* error exit handlers */
v223:
    popv(8);
    return nil;
}



/* Code for deg */

static Lisp_Object CC_deg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg");
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
    v127 = qvalue(elt(env, 1)); /* gdmode!* */
    stack[-2] = qvalue(elt(env, 2)); /* dmode!* */
    qvalue(elt(env, 2)) = v127; /* dmode!* */
    v127 = stack[-1];
    fn = elt(env, 3); /* simp!* */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-3];
    stack[-1] = v127;
    v144 = stack[-1];
    v127 = stack[0];
    fn = elt(env, 4); /* tstpolyarg2 */
    v127 = (*qfn2(fn))(qenv(fn), v144, v127);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-3];
    v127 = stack[-1];
    v144 = qcar(v127);
    v127 = stack[0];
    fn = elt(env, 5); /* numrdeg */
    v127 = (*qfn2(fn))(qenv(fn), v144, v127);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v127); }
/* error exit handlers */
v158:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for constructinvolutivebasis */

static Lisp_Object CC_constructinvolutivebasis(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v268, v269, v270;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constructinvolutivebasis");
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
    stack[-5] = v1;
    stack[0] = v0;
/* end of prologue */
    v269 = stack[0];
    v268 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 6); /* polynomlistautoreduce */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    stack[0] = v268;
    goto v116;

v116:
    v268 = stack[0];
    v268 = qcar(v268);
    if (v268 == nil) goto v142;
    stack[-1] = qvalue(elt(env, 3)); /* fluidbibasissetq */
    v268 = stack[0];
    v268 = qcar(v268);
    fn = elt(env, 7); /* createtriple */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    fn = elt(env, 8); /* sortedtriplelistinsert */
    v268 = (*qfn2(fn))(qenv(fn), stack[-1], v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    v268 = stack[0];
    v268 = qcdr(v268);
    stack[0] = v268;
    goto v116;

v142:
    v268 = qvalue(elt(env, 3)); /* fluidbibasissetq */
    v268 = qcar(v268);
    if (v268 == nil) goto v112;
    fn = elt(env, 9); /* setqget */
    v268 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    stack[-6] = v268;
    v269 = stack[-6];
    v268 = (Lisp_Object)17; /* 1 */
    v268 = *(Lisp_Object *)((char *)v269 + (CELL-TAG_VECTOR) + ((int32_t)v268/(16/CELL)));
    v268 = qcar(v268);
    stack[-4] = v268;
    v269 = stack[-6];
    v268 = (Lisp_Object)17; /* 1 */
    v268 = *(Lisp_Object *)((char *)v269 + (CELL-TAG_VECTOR) + ((int32_t)v268/(16/CELL)));
    fn = elt(env, 10); /* normalform */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    stack[-3] = v268;
    v268 = stack[-3];
    v268 = qcar(v268);
    stack[-2] = v268;
    v268 = stack[-2];
    if (v268 == nil) goto v142;
    v268 = qvalue(elt(env, 4)); /* fluidbibasisnonzeronormalforms */
    v268 = (Lisp_Object)((int32_t)(v268) + 0x10);
    qvalue(elt(env, 4)) = v268; /* fluidbibasisnonzeronormalforms */
    v268 = qvalue(elt(env, 2)); /* nil */
    v268 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    stack[0] = v268;
    v268 = qvalue(elt(env, 5)); /* fluidbibasissett */
    stack[-1] = v268;
    goto v188;

v188:
    v268 = stack[-1];
    v268 = qcar(v268);
    if (v268 == nil) goto v272;
    v268 = stack[-1];
    v269 = qcar(v268);
    v268 = (Lisp_Object)17; /* 1 */
    v268 = *(Lisp_Object *)((char *)v269 + (CELL-TAG_VECTOR) + ((int32_t)v268/(16/CELL)));
    v269 = qcar(v268);
    v268 = stack[-2];
    fn = elt(env, 11); /* monomisdivisibleby */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    if (v268 == nil) goto v273;
    v268 = stack[-1];
    v269 = qcar(v268);
    v268 = (Lisp_Object)1; /* 0 */
    v268 = *(Lisp_Object *)((char *)v269 + (CELL-TAG_VECTOR) + ((int32_t)v268/(16/CELL)));
    fn = elt(env, 12); /* setqdeletedescendants */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    v269 = stack[0];
    v268 = stack[-1];
    v268 = qcar(v268);
    fn = elt(env, 8); /* sortedtriplelistinsert */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    v268 = stack[-1];
    v269 = qcar(v268);
    v268 = (Lisp_Object)17; /* 1 */
    v268 = *(Lisp_Object *)((char *)v269 + (CELL-TAG_VECTOR) + ((int32_t)v268/(16/CELL)));
    v268 = qcar(v268);
    fn = elt(env, 13); /* janettreedelete */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    v269 = stack[-1];
    v268 = stack[-1];
    v268 = qcdr(v268);
    v268 = qcar(v268);
    v269 = Lrplaca(nil, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    v268 = stack[-1];
    v268 = qcdr(v268);
    v268 = qcdr(v268);
    v268 = Lrplacd(nil, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    goto v188;

v273:
    v268 = stack[-1];
    v268 = qcdr(v268);
    stack[-1] = v268;
    goto v188;

v272:
    v269 = stack[-4];
    v268 = stack[-2];
    if (v269 == v268) goto v274;
    v268 = stack[-3];
    fn = elt(env, 7); /* createtriple */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    fn = elt(env, 14); /* settinsert */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    goto v88;

v88:
    v268 = stack[0];
    fn = elt(env, 15); /* settcollectnonmultiprolongations */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    v269 = stack[-2];
    v268 = (Lisp_Object)1; /* 0 */
    v269 = *(Lisp_Object *)((char *)v269 + (CELL-TAG_VECTOR) + ((int32_t)v268/(16/CELL)));
    v268 = (Lisp_Object)1; /* 0 */
    v268 = Leqn(nil, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    if (v268 == nil) goto v217;
    v268 = qvalue(elt(env, 2)); /* nil */
    v268 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    qvalue(elt(env, 3)) = v268; /* fluidbibasissetq */
    goto v142;

v217:
    v268 = stack[0];
    fn = elt(env, 16); /* setqinsertlist */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    goto v142;

v274:
    v270 = stack[-3];
    v269 = stack[-6];
    v268 = (Lisp_Object)33; /* 2 */
    v268 = *(Lisp_Object *)((char *)v269 + (CELL-TAG_VECTOR) + ((int32_t)v268/(16/CELL)));
    fn = elt(env, 17); /* createtriplewithancestor */
    v268 = (*qfn2(fn))(qenv(fn), v270, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    fn = elt(env, 14); /* settinsert */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    v268 = qvalue(elt(env, 5)); /* fluidbibasissett */
    v270 = qcar(v268);
    v269 = stack[-6];
    v268 = (Lisp_Object)49; /* 3 */
    v268 = *(Lisp_Object *)((char *)v269 + (CELL-TAG_VECTOR) + ((int32_t)v268/(16/CELL)));
    fn = elt(env, 18); /* triplesetprolongset */
    v268 = (*qfn2(fn))(qenv(fn), v270, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    goto v88;

v112:
    v268 = qvalue(elt(env, 2)); /* nil */
    v268 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    stack[0] = v268;
    v268 = qvalue(elt(env, 5)); /* fluidbibasissett */
    stack[-1] = v268;
    goto v84;

v84:
    v268 = stack[-1];
    v268 = qcar(v268);
    if (v268 == nil) goto v275;
    v270 = stack[0];
    v268 = stack[-1];
    v269 = qcar(v268);
    v268 = (Lisp_Object)17; /* 1 */
    v268 = *(Lisp_Object *)((char *)v269 + (CELL-TAG_VECTOR) + ((int32_t)v268/(16/CELL)));
    fn = elt(env, 19); /* sortedpolynomlistinsert */
    v268 = (*qfn2(fn))(qenv(fn), v270, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-7];
    v268 = stack[-1];
    v268 = qcdr(v268);
    stack[-1] = v268;
    goto v84;

v275:
    v269 = stack[0];
    v268 = stack[-5];
    {
        popv(8);
        fn = elt(env, 6); /* polynomlistautoreduce */
        return (*qfn2(fn))(qenv(fn), v269, v268);
    }
/* error exit handlers */
v271:
    popv(8);
    return nil;
}



/* Code for cl_pnf1 */

static Lisp_Object CC_cl_pnf1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pnf1");
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
    v114 = v0;
/* end of prologue */
    fn = elt(env, 2); /* cl_rename!-vars */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    fn = elt(env, 3); /* cl_pnf2 */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    stack[-1] = v114;
    v114 = stack[-1];
    v114 = qcdr(v114);
    if (v114 == nil) goto v148;
    v114 = stack[-1];
    v114 = qcar(v114);
    fn = elt(env, 4); /* cl_qb */
    stack[0] = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    v114 = stack[-1];
    v114 = qcdr(v114);
    v114 = qcar(v114);
    fn = elt(env, 4); /* cl_qb */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    v114 = (Lisp_Object)lessp2(stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v113;
    v114 = v114 ? lisp_true : nil;
    goto v186;

v186:
    if (v114 == nil) goto v120;
    v114 = stack[-1];
    v114 = qcar(v114);
    { popv(3); return onevalue(v114); }

v120:
    v114 = stack[-1];
    v114 = qcdr(v114);
    v114 = qcar(v114);
    { popv(3); return onevalue(v114); }

v148:
    v114 = qvalue(elt(env, 1)); /* t */
    goto v186;
/* error exit handlers */
v113:
    popv(3);
    return nil;
}



/* Code for ofsf_anegrel */

static Lisp_Object CC_ofsf_anegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v64, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_anegrel");
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
    v119 = v0;
/* end of prologue */
    v64 = v119;
    v115 = elt(env, 1); /* ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp)) 
*/
    v115 = Latsoc(nil, v64, v115);
    v115 = qcdr(v115);
    if (!(v115 == nil)) { popv(1); return onevalue(v115); }
    v115 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v115 == nil)) goto v151;
    v115 = elt(env, 3); /* "ofsf_anegrel: unknown operator " */
    v64 = v119;
    v115 = list2(v115, v64);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[0];
    fn = elt(env, 4); /* lprie */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[0];
    goto v151;

v151:
    v115 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v120;
    v115 = nil;
    { popv(1); return onevalue(v115); }
/* error exit handlers */
v120:
    popv(1);
    return nil;
}



/* Code for gcdk */

static Lisp_Object CC_gcdk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v295, v296;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdk");
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
    stack[-9] = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-10] = nil;
    stack[-8] = nil;
    v295 = stack[0];
    v104 = stack[-9];
    if (equal(v295, v104)) { Lisp_Object res = stack[0]; popv(12); return onevalue(res); }
    v104 = stack[0];
    if (!consp(v104)) goto v74;
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = (consp(v104) ? nil : lisp_true);
    goto v158;

v158:
    if (v104 == nil) goto v178;
    v104 = qvalue(elt(env, 1)); /* t */
    goto v144;

v144:
    if (v104 == nil) goto v61;
    v104 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v104); }

v61:
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = qcar(v104);
    v295 = qcdr(v104);
    v104 = stack[-9];
    v104 = qcar(v104);
    v104 = qcar(v104);
    v104 = qcdr(v104);
    v104 = (Lisp_Object)lessp2(v295, v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    v104 = v104 ? lisp_true : nil;
    env = stack[-11];
    if (v104 == nil) goto v188;
    v104 = stack[0];
    stack[-7] = v104;
    v104 = stack[-9];
    stack[0] = v104;
    v104 = stack[-7];
    stack[-9] = v104;
    goto v188;

v188:
    v295 = stack[0];
    v104 = stack[-9];
    fn = elt(env, 9); /* quotf1 */
    v104 = (*qfn2(fn))(qenv(fn), v295, v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    if (!(v104 == nil)) { Lisp_Object res = stack[-9]; popv(12); return onevalue(res); }
    v104 = qvalue(elt(env, 2)); /* !*heugcd */
    if (v104 == nil) goto v267;
    v295 = stack[0];
    v104 = stack[-9];
    fn = elt(env, 10); /* heu!-gcd */
    v104 = (*qfn2(fn))(qenv(fn), v295, v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    v295 = v104;
    if (!(v104 == nil)) { popv(12); return onevalue(v295); }

v267:
    v104 = stack[-9];
    v104 = qcar(v104);
    v104 = qcar(v104);
    v295 = qcdr(v104);
    v104 = (Lisp_Object)17; /* 1 */
    if (v295 == v104) goto v131;
    v104 = elt(env, 3); /* modular!-multicheck */
    fn = elt(env, 11); /* getd */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    if (v104 == nil) goto v147;
    v296 = stack[0];
    v295 = stack[-9];
    v104 = stack[-8];
    fn = elt(env, 3); /* modular!-multicheck */
    v104 = (*qfnn(fn))(qenv(fn), 3, v296, v295, v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    goto v242;

v242:
    if (!(v104 == nil)) goto v136;
    v104 = qvalue(elt(env, 5)); /* !*mcd */
    v104 = (v104 == nil ? lisp_true : nil);
    goto v136;

v136:
    if (v104 == nil) goto v251;
    v104 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v104); }

v251:
    v295 = stack[0];
    v104 = stack[-9];
    fn = elt(env, 12); /* remk */
    v104 = (*qfn2(fn))(qenv(fn), v295, v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    stack[-7] = v104;
    v104 = stack[-7];
    if (v104 == nil) { Lisp_Object res = stack[-9]; popv(12); return onevalue(res); }
    v295 = stack[-7];
    v104 = stack[-8];
    fn = elt(env, 13); /* degr */
    v295 = (*qfn2(fn))(qenv(fn), v295, v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    v104 = (Lisp_Object)1; /* 0 */
    if (v295 == v104) goto v298;
    v295 = stack[-9];
    v104 = stack[-10];
    fn = elt(env, 14); /* addlc */
    v104 = (*qfn2(fn))(qenv(fn), v295, v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    stack[-10] = v104;
    v295 = stack[-7];
    v104 = stack[-7];
    v104 = qcar(v104);
    v104 = qcdr(v104);
    fn = elt(env, 9); /* quotf1 */
    v104 = (*qfn2(fn))(qenv(fn), v295, v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    v295 = v104;
    if (v104 == nil) goto v299;
    v104 = v295;
    stack[-7] = v104;
    goto v198;

v198:
    v104 = stack[-9];
    stack[0] = v104;
    stack[-1] = stack[-7];
    v104 = stack[-7];
    fn = elt(env, 15); /* comfac */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    v295 = v104;
    v104 = v295;
    v104 = qcar(v104);
    if (v104 == nil) goto v300;
    v104 = v295;
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    goto v301;

v301:
    fn = elt(env, 9); /* quotf1 */
    v104 = (*qfn2(fn))(qenv(fn), stack[-1], v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    stack[-9] = v104;
    v295 = stack[-9];
    v104 = stack[-8];
    fn = elt(env, 13); /* degr */
    v295 = (*qfn2(fn))(qenv(fn), v295, v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    v104 = (Lisp_Object)1; /* 0 */
    if (!(v295 == v104)) goto v251;
    v104 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v104); }

v300:
    v104 = v295;
    v104 = qcdr(v104);
    goto v301;

v299:
    v104 = stack[-10];
    stack[-6] = v104;
    goto v258;

v258:
    v104 = stack[-6];
    if (v104 == nil) goto v198;
    v104 = stack[-6];
    v104 = qcar(v104);
    stack[-5] = v104;
    v104 = stack[-5];
    if (!consp(v104)) goto v192;
    v104 = qvalue(elt(env, 4)); /* nil */
    goto v43;

v43:
    if (v104 == nil) goto v246;
    v104 = qvalue(elt(env, 1)); /* t */
    goto v302;

v302:
    if (!(v104 == nil)) goto v303;

v92:
    v104 = stack[-6];
    v104 = qcdr(v104);
    stack[-6] = v104;
    goto v258;

v303:
    v295 = stack[-7];
    v104 = stack[-5];
    fn = elt(env, 9); /* quotf1 */
    v104 = (*qfn2(fn))(qenv(fn), v295, v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    v295 = v104;
    if (v104 == nil) goto v92;
    v104 = v295;
    stack[-7] = v104;
    goto v303;

v246:
    v104 = stack[-5];
    if (!consp(v104)) goto v84;
    v104 = stack[-5];
    v104 = qcar(v104);
    v104 = (consp(v104) ? nil : lisp_true);
    goto v37;

v37:
    if (v104 == nil) goto v304;
    v295 = qvalue(elt(env, 6)); /* dmode!* */
    v104 = elt(env, 7); /* field */
    v104 = Lflagp(nil, v295, v104);
    env = stack[-11];
    if (v104 == nil) goto v305;
    v104 = qvalue(elt(env, 1)); /* t */
    goto v306;

v306:
    v104 = (v104 == nil ? lisp_true : nil);
    goto v302;

v305:
    v104 = stack[-5];
    v295 = qcar(v104);
    v104 = elt(env, 8); /* units */
    v104 = get(v295, v104);
    env = stack[-11];
    v295 = v104;
    if (v104 == nil) goto v307;
    stack[-4] = stack[-5];
    v104 = v295;
    stack[-3] = v104;
    v104 = stack[-3];
    if (v104 == nil) goto v308;
    v104 = stack[-3];
    v104 = qcar(v104);
    v104 = qcar(v104);
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    stack[-1] = v104;
    stack[-2] = v104;
    goto v28;

v28:
    v104 = stack[-3];
    v104 = qcdr(v104);
    stack[-3] = v104;
    v104 = stack[-3];
    if (v104 == nil) goto v309;
    stack[0] = stack[-1];
    v104 = stack[-3];
    v104 = qcar(v104);
    v104 = qcar(v104);
    v104 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    v104 = Lrplacd(nil, stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    v104 = stack[-1];
    v104 = qcdr(v104);
    stack[-1] = v104;
    goto v28;

v309:
    v104 = stack[-2];
    goto v310;

v310:
    v104 = Lmember(nil, stack[-4], v104);
    goto v306;

v308:
    v104 = qvalue(elt(env, 4)); /* nil */
    goto v310;

v307:
    v104 = qvalue(elt(env, 4)); /* nil */
    goto v306;

v304:
    v104 = qvalue(elt(env, 4)); /* nil */
    goto v306;

v84:
    v104 = qvalue(elt(env, 1)); /* t */
    goto v37;

v192:
    v295 = qvalue(elt(env, 6)); /* dmode!* */
    v104 = elt(env, 7); /* field */
    v104 = Lflagp(nil, v295, v104);
    env = stack[-11];
    v104 = (v104 == nil ? lisp_true : nil);
    goto v43;

v298:
    v104 = (Lisp_Object)17; /* 1 */
    { popv(12); return onevalue(v104); }

v147:
    v104 = qvalue(elt(env, 4)); /* nil */
    goto v242;

v131:
    v104 = qvalue(elt(env, 1)); /* t */
    goto v136;

v178:
    v295 = stack[-9];
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = qcar(v104);
    v104 = qcar(v104);
    stack[-8] = v104;
    fn = elt(env, 13); /* degr */
    v295 = (*qfn2(fn))(qenv(fn), v295, v104);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-11];
    v104 = (Lisp_Object)1; /* 0 */
    v104 = (v295 == v104 ? lisp_true : nil);
    goto v144;

v74:
    v104 = qvalue(elt(env, 1)); /* t */
    goto v158;
/* error exit handlers */
v297:
    popv(12);
    return nil;
}



/* Code for interglue */

static Lisp_Object MS_CDECL CC_interglue(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v331, v300;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "interglue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for interglue");
#endif
    if (stack >= stacklimit)
    {
        push4(v5,v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v128,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v5;
    stack[-2] = v128;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v331 = stack[-4];
    if (v331 == nil) goto v186;
    v331 = stack[-3];
    if (v331 == nil) goto v73;
    v331 = stack[-4];
    if (!consp(v331)) goto v115;
    v331 = qvalue(elt(env, 1)); /* t */
    goto v143;

v143:
    if (v331 == nil) goto v153;
    v331 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v331); }

v153:
    v300 = stack[-4];
    v331 = elt(env, 3); /* class */
    v331 = get(v300, v331);
    env = stack[-6];
    stack[0] = v331;
    v300 = stack[-3];
    v331 = elt(env, 3); /* class */
    v331 = get(v300, v331);
    env = stack[-6];
    v300 = stack[0];
    v331 = get(v300, v331);
    env = stack[-6];
    stack[-5] = v331;
    v331 = stack[-5];
    if (v331 == nil) goto v138;
    v300 = stack[-4];
    v331 = elt(env, 4); /* !\co!  */
    if (v300 == v331) goto v332;
    v300 = stack[-5];
    v331 = (Lisp_Object)1; /* 0 */
    v331 = (Lisp_Object)lessp2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    v331 = v331 ? lisp_true : nil;
    env = stack[-6];
    if (v331 == nil) goto v212;
    v300 = stack[-2];
    v331 = (Lisp_Object)1; /* 0 */
    v331 = (Lisp_Object)greaterp2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    v331 = v331 ? lisp_true : nil;
    env = stack[-6];
    if (v331 == nil) goto v210;
    v331 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v331); }

v210:
    v331 = stack[-5];
    v331 = negate(v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    stack[-5] = v331;
    goto v212;

v212:
    v300 = stack[-5];
    v331 = (Lisp_Object)17; /* 1 */
    if (v300 == v331) goto v333;
    v300 = stack[-5];
    v331 = (Lisp_Object)33; /* 2 */
    if (v300 == v331) goto v87;
    v300 = stack[-5];
    v331 = (Lisp_Object)49; /* 3 */
    if (v300 == v331) goto v22;
    v331 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v331); }

v22:
    stack[0] = (Lisp_Object)10485761; /* 655360 */
    v300 = stack[-1];
    v331 = (Lisp_Object)161; /* 10 */
    v300 = times2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    v331 = (Lisp_Object)801; /* 50 */
    v331 = difference2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    {
        Lisp_Object v101 = stack[0];
        popv(7);
        return list2(v101, v331);
    }

v87:
    v300 = stack[-4];
    v331 = elt(env, 5); /* !+ */
    if (v300 == v331) goto v49;
    v300 = stack[-4];
    v331 = elt(env, 6); /* !- */
    v331 = (v300 == v331 ? lisp_true : nil);
    goto v89;

v89:
    if (v331 == nil) goto v261;
    v331 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v331); }

v261:
    v300 = stack[-3];
    v331 = elt(env, 5); /* !+ */
    if (v300 == v331) goto v236;
    v300 = stack[-3];
    v331 = elt(env, 6); /* !- */
    if (v300 == v331) goto v216;
    v331 = qvalue(elt(env, 2)); /* nil */
    goto v334;

v334:
    if (v331 == nil) goto v93;
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v300 = stack[-1];
    v331 = (Lisp_Object)481; /* 30 */
    v300 = times2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    v331 = (Lisp_Object)3361; /* 210 */
    v331 = difference2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    {
        Lisp_Object v335 = stack[0];
        popv(7);
        return list2(v335, v331);
    }

v93:
    v300 = stack[-4];
    v331 = elt(env, 9); /* !\cdot!  */
    if (v300 == v331) goto v336;
    v300 = stack[-3];
    v331 = elt(env, 9); /* !\cdot!  */
    if (v300 == v331) goto v337;
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v300 = stack[-1];
    v331 = (Lisp_Object)161; /* 10 */
    v331 = times2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    {
        Lisp_Object v17 = stack[0];
        popv(7);
        return list2(v17, v331);
    }

v337:
    v331 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v331); }

v336:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v300 = stack[-1];
    v331 = (Lisp_Object)161; /* 10 */
    v300 = times2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    v331 = (Lisp_Object)801; /* 50 */
    v331 = plus2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    {
        Lisp_Object v100 = stack[0];
        popv(7);
        return list2(v100, v331);
    }

v216:
    v300 = stack[0];
    v331 = elt(env, 7); /* ord */
    if (v300 == v331) goto v41;
    v300 = stack[0];
    v331 = elt(env, 8); /* clo */
    v331 = (v300 == v331 ? lisp_true : nil);
    goto v334;

v41:
    v331 = qvalue(elt(env, 1)); /* t */
    goto v334;

v236:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v300 = stack[-1];
    v331 = (Lisp_Object)481; /* 30 */
    v300 = times2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    v331 = (Lisp_Object)6241; /* 390 */
    v331 = difference2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    {
        Lisp_Object v99 = stack[0];
        popv(7);
        return list2(v99, v331);
    }

v49:
    v331 = qvalue(elt(env, 1)); /* t */
    goto v89;

v333:
    stack[0] = (Lisp_Object)1295361; /* 80960 */
    v300 = stack[-1];
    v331 = (Lisp_Object)161; /* 10 */
    v300 = times2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    v331 = (Lisp_Object)321; /* 20 */
    v331 = plus2(v300, v331);
    nil = C_nil;
    if (exception_pending()) goto v102;
    {
        Lisp_Object v338 = stack[0];
        popv(7);
        return list2(v338, v331);
    }

v332:
    v300 = (Lisp_Object)1; /* 0 */
    v331 = (Lisp_Object)-159999; /* -10000 */
    popv(7);
    return list2(v300, v331);

v138:
    v331 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v331); }

v115:
    v331 = stack[-3];
    v331 = (consp(v331) ? nil : lisp_true);
    v331 = (v331 == nil ? lisp_true : nil);
    goto v143;

v73:
    v331 = qvalue(elt(env, 1)); /* t */
    goto v143;

v186:
    v331 = qvalue(elt(env, 1)); /* t */
    goto v143;
/* error exit handlers */
v102:
    popv(7);
    return nil;
}



/* Code for get_rep_of_generator */

static Lisp_Object CC_get_rep_of_generator(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v81, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_rep_of_generator");
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
    v159 = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-1] = nil;
    v81 = stack[-2];
    v82 = elt(env, 1); /* id */
    if (v81 == v82) goto v143;
    v82 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = v82;
    v82 = v159;
    stack[0] = v82;
    goto v158;

v158:
    v82 = stack[-3];
    if (v82 == nil) goto v179;
    v82 = qvalue(elt(env, 2)); /* nil */
    goto v121;

v121:
    if (v82 == nil) goto v171;
    v82 = stack[0];
    v82 = qcar(v82);
    v81 = qcar(v82);
    v82 = stack[-2];
    if (!(equal(v81, v82))) goto v167;
    v82 = qvalue(elt(env, 3)); /* t */
    stack[-3] = v82;
    v82 = stack[0];
    v82 = qcar(v82);
    v82 = qcdr(v82);
    v82 = qcar(v82);
    stack[-1] = v82;
    goto v167;

v167:
    v82 = stack[0];
    v82 = qcdr(v82);
    stack[0] = v82;
    goto v158;

v171:
    v82 = stack[-3];
    if (!(v82 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v82 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v82 == nil)) goto v188;
    v82 = elt(env, 5); /* " error in get rep of generators" */
    fn = elt(env, 6); /* lprie */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-4];
    goto v188;

v188:
    v82 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v214;
    v82 = nil;
    { popv(5); return onevalue(v82); }

v179:
    v82 = stack[0];
    v81 = Llength(nil, v82);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-4];
    v82 = (Lisp_Object)1; /* 0 */
    v82 = (Lisp_Object)greaterp2(v81, v82);
    nil = C_nil;
    if (exception_pending()) goto v214;
    v82 = v82 ? lisp_true : nil;
    env = stack[-4];
    goto v121;

v143:
    v82 = v159;
    v82 = qcar(v82);
    v82 = qcdr(v82);
    v82 = qcar(v82);
    fn = elt(env, 7); /* get!+row!+nr */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* mk!+unit!+mat */
        return (*qfn1(fn))(qenv(fn), v82);
    }
/* error exit handlers */
v214:
    popv(5);
    return nil;
}



/* Code for qqe_length!-graph!-neighbor!-edge */

static Lisp_Object CC_qqe_lengthKgraphKneighborKedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v35;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_length-graph-neighbor-edge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v0;
/* end of prologue */
    v35 = qcdr(v35);
    v35 = qcdr(v35);
    v35 = qcar(v35);
    return onevalue(v35);
}



/* Code for ratpoly_toaf */

static Lisp_Object CC_ratpoly_toaf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_toaf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v72 = v0;
/* end of prologue */
    v73 = v72;
    v73 = qcar(v73);
    if (v73 == nil) goto v4;
    v73 = elt(env, 1); /* prepf */
    {
        fn = elt(env, 2); /* sqform */
        return (*qfn2(fn))(qenv(fn), v72, v73);
    }

v4:
    v73 = (Lisp_Object)1; /* 0 */
    return onevalue(v73);
}



/* Code for crn!:onep */

static Lisp_Object CC_crnTonep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v74, v115;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:onep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v115 = v0;
/* end of prologue */
    v158 = v115;
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    v74 = qcar(v158);
    v158 = (Lisp_Object)1; /* 0 */
    if (v74 == v158) goto v123;
    v158 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v158);

v123:
    v158 = v115;
    v158 = qcdr(v158);
    v158 = qcar(v158);
    v74 = elt(env, 1); /* (1 . 1) */
    v158 = (equal(v158, v74) ? lisp_true : nil);
    return onevalue(v158);
}



/* Code for poly!-remainder */

static Lisp_Object CC_polyKremainder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v63, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-remainder");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v118 = v0;
/* end of prologue */
    v75 = v118;
    v63 = elt(env, 1); /* remainder */
    v118 = qvalue(elt(env, 2)); /* nil */
    {
        fn = elt(env, 3); /* poly!-divide!* */
        return (*qfnn(fn))(qenv(fn), 3, v75, v63, v118);
    }
}



/* Code for vdpappendmon */

static Lisp_Object MS_CDECL CC_vdpappendmon(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v188, v332;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdpappendmon");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpappendmon");
#endif
    if (stack >= stacklimit)
    {
        push3(v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v128);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v128;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v185 = stack[-4];
    if (v185 == nil) goto v143;
    v185 = stack[-4];
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v185 = (v185 == nil ? lisp_true : nil);
    goto v125;

v125:
    if (v185 == nil) goto v124;
    v188 = stack[-3];
    v185 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); /* vdpfmon */
        return (*qfn2(fn))(qenv(fn), v188, v185);
    }

v124:
    v185 = stack[-3];
    fn = elt(env, 5); /* vbczero!? */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-6];
    if (!(v185 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-5] = elt(env, 2); /* vdp */
    v185 = stack[-4];
    v185 = qcdr(v185);
    stack[-1] = qcar(v185);
    v185 = stack[-4];
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    stack[0] = qcar(v185);
    v185 = stack[-4];
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    stack[-4] = qcar(v185);
    v332 = stack[-2];
    v188 = stack[-3];
    v185 = qvalue(elt(env, 3)); /* nil */
    v185 = list2star(v332, v188, v185);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-6];
    fn = elt(env, 6); /* dipsum */
    v188 = (*qfn2(fn))(qenv(fn), stack[-4], v185);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-6];
    v185 = qvalue(elt(env, 3)); /* nil */
    v185 = list2(v188, v185);
    nil = C_nil;
    if (exception_pending()) goto v81;
    {
        Lisp_Object v159 = stack[-5];
        Lisp_Object v339 = stack[-1];
        Lisp_Object v340 = stack[0];
        popv(7);
        return list3star(v159, v339, v340, v185);
    }

v143:
    v185 = qvalue(elt(env, 1)); /* t */
    goto v125;
/* error exit handlers */
v81:
    popv(7);
    return nil;
}



/* Code for mkset */

static Lisp_Object CC_mkset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkset");
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
    v35 = v0;
/* end of prologue */
    fn = elt(env, 1); /* getrlist */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[0];
    fn = elt(env, 2); /* delete!-dups */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* make!-set */
        return (*qfn1(fn))(qenv(fn), v35);
    }
/* error exit handlers */
v124:
    popv(1);
    return nil;
}



/* Code for find_bubles1_coeff */

static Lisp_Object MS_CDECL CC_find_bubles1_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "find_bubles1_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles1_coeff");
#endif
    if (stack >= stacklimit)
    {
        push4(v5,v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v128,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v5;
    stack[0] = v128;
    stack[-1] = v1;
    stack[-4] = v0;
/* end of prologue */

v183:
    v138 = stack[-4];
    if (v138 == nil) goto v186;
    v138 = stack[-4];
    v187 = qcar(v138);
    v138 = stack[0];
    fn = elt(env, 1); /* find_bubles1 */
    v138 = (*qfn2(fn))(qenv(fn), v187, v138);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    stack[-2] = v138;
    v138 = stack[-4];
    stack[-4] = qcdr(v138);
    v138 = stack[-2];
    v187 = qcdr(v138);
    v138 = stack[-1];
    stack[-1] = cons(v187, v138);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v138 = stack[-2];
    v138 = qcar(v138);
    if (v138 == nil) goto v168;
    v138 = stack[-2];
    v187 = qcar(v138);
    v138 = stack[-3];
    v138 = cons(v187, v138);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    goto v174;

v174:
    stack[-3] = v138;
    goto v183;

v168:
    v138 = stack[-3];
    goto v174;

v186:
    v187 = stack[-3];
    v138 = stack[-1];
    popv(6);
    return cons(v187, v138);
/* error exit handlers */
v60:
    popv(6);
    return nil;
}



/* Code for pst_d1 */

static Lisp_Object MS_CDECL CC_pst_d1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pst_d1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_d1");
#endif
    if (stack >= stacklimit)
    {
        push3(v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v128);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v128;
    stack[-11] = v1;
    v198 = v0;
/* end of prologue */
    stack[0] = stack[-10];
    v198 = sub1(v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    stack[-12] = v198;
    v198 = stack[-12];
    if (v198 == nil) goto v116;
    v198 = stack[-12];
    v198 = qcar(v198);
    stack[-6] = v198;
    stack[0] = stack[-10];
    v198 = stack[-11];
    v198 = sub1(v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    stack[-5] = v198;
    v198 = stack[-5];
    if (v198 == nil) goto v175;
    v198 = stack[-5];
    v198 = qcar(v198);
    stack[-1] = v198;
    v198 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v198 = (*qfn2(fn))(qenv(fn), stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = qcar(v198);
    fn = elt(env, 4); /* ordn */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-3] = v198;
    stack[-4] = v198;
    goto v121;

v121:
    v198 = stack[-5];
    v198 = qcdr(v198);
    stack[-5] = v198;
    v198 = stack[-5];
    if (v198 == nil) goto v187;
    stack[-2] = stack[-3];
    v198 = stack[-5];
    v198 = qcar(v198);
    stack[-1] = v198;
    v198 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v198 = (*qfn2(fn))(qenv(fn), stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = qcar(v198);
    fn = elt(env, 4); /* ordn */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = Lrplacd(nil, stack[-2], v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = stack[-3];
    v198 = qcdr(v198);
    stack[-3] = v198;
    goto v121;

v187:
    v198 = stack[-4];
    goto v120;

v120:
    fn = elt(env, 4); /* ordn */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-8] = v198;
    stack[-9] = v198;
    goto v125;

v125:
    v198 = stack[-12];
    v198 = qcdr(v198);
    stack[-12] = v198;
    v198 = stack[-12];
    if (v198 == nil) { Lisp_Object res = stack[-9]; popv(14); return onevalue(res); }
    stack[-7] = stack[-8];
    v198 = stack[-12];
    v198 = qcar(v198);
    stack[-6] = v198;
    stack[0] = stack[-10];
    v198 = stack[-11];
    v198 = sub1(v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v198/(16/CELL)));
    stack[-5] = v198;
    v198 = stack[-5];
    if (v198 == nil) goto v344;
    v198 = stack[-5];
    v198 = qcar(v198);
    stack[-1] = v198;
    v198 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v198 = (*qfn2(fn))(qenv(fn), stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = qcar(v198);
    fn = elt(env, 4); /* ordn */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-3] = v198;
    stack[-4] = v198;
    goto v146;

v146:
    v198 = stack[-5];
    v198 = qcdr(v198);
    stack[-5] = v198;
    v198 = stack[-5];
    if (v198 == nil) goto v345;
    stack[-2] = stack[-3];
    v198 = stack[-5];
    v198 = qcar(v198);
    stack[-1] = v198;
    v198 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v198 = (*qfn2(fn))(qenv(fn), stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = qcar(v198);
    fn = elt(env, 4); /* ordn */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = Lrplacd(nil, stack[-2], v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = stack[-3];
    v198 = qcdr(v198);
    stack[-3] = v198;
    goto v146;

v345:
    v198 = stack[-4];
    goto v145;

v145:
    fn = elt(env, 4); /* ordn */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = Lrplacd(nil, stack[-7], v198);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v198 = stack[-8];
    v198 = qcdr(v198);
    stack[-8] = v198;
    goto v125;

v344:
    v198 = qvalue(elt(env, 1)); /* nil */
    goto v145;

v175:
    v198 = qvalue(elt(env, 1)); /* nil */
    goto v120;

v116:
    v198 = qvalue(elt(env, 1)); /* nil */
    { popv(14); return onevalue(v198); }
/* error exit handlers */
v299:
    popv(14);
    return nil;
}



/* Code for modroots2 */

static Lisp_Object MS_CDECL CC_modroots2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v348, v349, v344, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "modroots2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modroots2");
#endif
    if (stack >= stacklimit)
    {
        push3(v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v128);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v344 = v128;
    stack[-3] = v1;
    v86 = v0;
/* end of prologue */
    v348 = v86;
    if (!consp(v348)) goto v63;
    v348 = v86;
    v348 = qcar(v348);
    v348 = (consp(v348) ? nil : lisp_true);
    goto v118;

v118:
    if (v348 == nil) goto v127;
    v348 = v86;
    goto v125;

v125:
    if (v348 == nil) goto v124;
    v348 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v348); }

v124:
    v348 = v86;
    if (v348 == nil) goto v114;
    v349 = stack[-3];
    v348 = (Lisp_Object)33; /* 2 */
    if (v349 == v348) goto v129;
    v349 = v86;
    v348 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); /* modroots3 */
        return (*qfn2(fn))(qenv(fn), v349, v348);
    }

v129:
    v349 = v86;
    v348 = qvalue(elt(env, 1)); /* t */
    {
        popv(6);
        fn = elt(env, 5); /* modroots4 */
        return (*qfnn(fn))(qenv(fn), 3, v349, v348, v344);
    }

v114:
    v349 = stack[-3];
    v348 = (Lisp_Object)33; /* 2 */
    if (v349 == v348) goto v65;
    v348 = qvalue(elt(env, 2)); /* nil */
    goto v122;

v122:
    if (v348 == nil) goto v156;
    v348 = elt(env, 3); /* (-1 0 1) */
    { popv(6); return onevalue(v348); }

v156:
    v348 = (Lisp_Object)1; /* 0 */
    stack[-4] = v348;
    v348 = stack[-3];
    v349 = sub1(v348);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-5];
    v348 = stack[-4];
    v348 = difference2(v349, v348);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-5];
    v348 = Lminusp(nil, v348);
    env = stack[-5];
    if (v348 == nil) goto v160;
    v348 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v348); }

v160:
    v348 = stack[-4];
    v348 = ncons(v348);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-5];
    stack[-1] = v348;
    stack[-2] = v348;
    goto v170;

v170:
    v348 = stack[-4];
    v348 = add1(v348);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-5];
    stack[-4] = v348;
    v348 = stack[-3];
    v349 = sub1(v348);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-5];
    v348 = stack[-4];
    v348 = difference2(v349, v348);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-5];
    v348 = Lminusp(nil, v348);
    env = stack[-5];
    if (!(v348 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v348 = stack[-4];
    v348 = ncons(v348);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-5];
    v348 = Lrplacd(nil, stack[0], v348);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-5];
    v348 = stack[-1];
    v348 = qcdr(v348);
    stack[-1] = v348;
    goto v170;

v65:
    v348 = v344;
    goto v122;

v127:
    v348 = qvalue(elt(env, 2)); /* nil */
    goto v125;

v63:
    v348 = qvalue(elt(env, 1)); /* t */
    goto v118;
/* error exit handlers */
v204:
    popv(6);
    return nil;
}



/* Code for solvevars */

static Lisp_Object CC_solvevars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvevars");
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
    v65 = v0;
/* end of prologue */
    v122 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v122;
    v122 = v65;
    fn = elt(env, 2); /* allbkern */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    stack[-1] = v122;
    goto v124;

v124:
    v122 = stack[-1];
    if (v122 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v122 = stack[-1];
    v122 = qcar(v122);
    stack[0] = v122;
    v122 = stack[0];
    fn = elt(env, 3); /* constant_exprp */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    if (!(v122 == nil)) goto v72;
    v65 = stack[0];
    v122 = stack[-2];
    fn = elt(env, 4); /* ordad */
    v122 = (*qfn2(fn))(qenv(fn), v65, v122);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    stack[-2] = v122;
    goto v72;

v72:
    v122 = stack[-1];
    v122 = qcdr(v122);
    stack[-1] = v122;
    goto v124;
/* error exit handlers */
v66:
    popv(4);
    return nil;
}



/* Code for rl_trygauss */

static Lisp_Object MS_CDECL CC_rl_trygauss(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v128, Lisp_Object v5,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v121, v122, v65, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rl_trygauss");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_trygauss");
#endif
    if (stack >= stacklimit)
    {
        push5(v4,v5,v128,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v128,v5,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v120 = v4;
    v121 = v5;
    v122 = v128;
    v65 = v1;
    v174 = v0;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* rl_trygauss!* */
    stack[-2] = v174;
    stack[-1] = v65;
    stack[0] = v122;
    v120 = list2(v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v120 = list3star(stack[-2], stack[-1], stack[0], v120);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    {
        Lisp_Object v142 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v142, v120);
    }
/* error exit handlers */
v112:
    popv(5);
    return nil;
}



/* Code for initmonomials */

static Lisp_Object MS_CDECL CC_initmonomials(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "initmonomials");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initmonomials");
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
    v66 = qvalue(elt(env, 1)); /* fluidbibasisvariables */
    v66 = Llength(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    qvalue(elt(env, 2)) = v66; /* fluidbibasisnumberofvariables */
    v66 = qvalue(elt(env, 2)); /* fluidbibasisnumberofvariables */
    v66 = Lmkvect(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    qvalue(elt(env, 3)) = v66; /* fluidbibasissinglevariablemonomialss 
*/
    v66 = (Lisp_Object)17; /* 1 */
    stack[-2] = v66;
    goto v67;

v67:
    v113 = qvalue(elt(env, 2)); /* fluidbibasisnumberofvariables */
    v66 = stack[-2];
    v66 = difference2(v113, v66);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    v66 = Lminusp(nil, v66);
    env = stack[-3];
    if (v66 == nil) goto v157;
    v66 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v66; /* fluidbibasistripleid */
    v66 = nil;
    { popv(4); return onevalue(v66); }

v157:
    stack[-1] = qvalue(elt(env, 3)); /* fluidbibasissinglevariablemonomialss 
*/
    stack[0] = stack[-2];
    v66 = stack[-2];
    fn = elt(env, 6); /* createsinglevariablemonom */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v66;
    v66 = stack[-2];
    v66 = add1(v66);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    stack[-2] = v66;
    goto v67;
/* error exit handlers */
v149:
    popv(4);
    return nil;
}



setup_type const u45_setup[] =
{
    {"canprod",                 too_few_2,      CC_canprod,    wrong_no_2},
    {"ofsf_multsurep",          too_few_2,      CC_ofsf_multsurep,wrong_no_2},
    {"ldt-dep",                 CC_ldtKdep,     too_many_1,    wrong_no_1},
    {"findhc",                  CC_findhc,      too_many_1,    wrong_no_1},
    {"gvarlis",                 CC_gvarlis,     too_many_1,    wrong_no_1},
    {"expt-separate",           too_few_2,      CC_exptKseparate,wrong_no_2},
    {"atlas_edges",             CC_atlas_edges, too_many_1,    wrong_no_1},
    {"subeval1",                too_few_2,      CC_subeval1,   wrong_no_2},
    {"mv2sf",                   too_few_2,      CC_mv2sf,      wrong_no_2},
    {"tensor_has_dummy_idx",    too_few_2,      CC_tensor_has_dummy_idx,wrong_no_2},
    {"lowestdeg",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_lowestdeg},
    {"vp1",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_vp1},
    {"available*p",             CC_availableHp, too_many_1,    wrong_no_1},
    {"pasf_mkop",               too_few_2,      CC_pasf_mkop,  wrong_no_2},
    {"cgp_cp",                  CC_cgp_cp,      too_many_1,    wrong_no_1},
    {"formopr",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_formopr},
    {"search4facf",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_search4facf},
    {"powmtch",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powmtch},
    {"simp:ps:",                CC_simpTpsT,    too_many_1,    wrong_no_1},
    {"dipcontevmin",            too_few_2,      CC_dipcontevmin,wrong_no_2},
    {"groebsimpcontnormalform", CC_groebsimpcontnormalform,too_many_1,wrong_no_1},
    {"let3",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_let3},
    {"exptbf",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_exptbf},
    {"rlval",                   too_few_2,      CC_rlval,      wrong_no_2},
    {"deg",                     too_few_2,      CC_deg,        wrong_no_2},
    {"constructinvolutivebasis",too_few_2,      CC_constructinvolutivebasis,wrong_no_2},
    {"cl_pnf1",                 CC_cl_pnf1,     too_many_1,    wrong_no_1},
    {"ofsf_anegrel",            CC_ofsf_anegrel,too_many_1,    wrong_no_1},
    {"gcdk",                    too_few_2,      CC_gcdk,       wrong_no_2},
    {"interglue",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_interglue},
    {"get_rep_of_generator",    too_few_2,      CC_get_rep_of_generator,wrong_no_2},
    {"qqe_length-graph-neighbor-edge",CC_qqe_lengthKgraphKneighborKedge,too_many_1,wrong_no_1},
    {"ratpoly_toaf",            CC_ratpoly_toaf,too_many_1,    wrong_no_1},
    {"crn:onep",                CC_crnTonep,    too_many_1,    wrong_no_1},
    {"poly-remainder",          CC_polyKremainder,too_many_1,  wrong_no_1},
    {"vdpappendmon",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpappendmon},
    {"mkset",                   CC_mkset,       too_many_1,    wrong_no_1},
    {"find_bubles1_coeff",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_bubles1_coeff},
    {"pst_d1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_pst_d1},
    {"modroots2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_modroots2},
    {"solvevars",               CC_solvevars,   too_many_1,    wrong_no_1},
    {"rl_trygauss",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_trygauss},
    {"initmonomials",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_initmonomials},
    {NULL, (one_args *)"u45", (two_args *)"1260 5666356 6656121", 0}
};

/* end of generated code */
