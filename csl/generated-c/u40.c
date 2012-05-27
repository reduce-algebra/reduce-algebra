
/* $destdir\u40.c        Machine generated C code */

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


/* Code for simpdf */

static Lisp_Object CC_simpdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdf");
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
    v48 = qvalue(elt(env, 1)); /* subfg!* */
    if (v48 == nil) goto v50;
    v48 = stack[-5];
    v48 = qcdr(v48);
    stack[-6] = v48;
    v48 = stack[-5];
    v48 = qcar(v48);
    fn = elt(env, 11); /* simp!* */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    stack[-5] = v48;
    goto v52;

v52:
    v48 = stack[-6];
    if (v48 == nil) goto v53;
    v48 = stack[-5];
    v48 = qcar(v48);
    v48 = (v48 == nil ? lisp_true : nil);
    goto v54;

v54:
    if (!(v48 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v48 = stack[-3];
    if (v48 == nil) goto v55;
    v49 = stack[-3];
    v48 = (Lisp_Object)1; /* 0 */
    v48 = (v49 == v48 ? lisp_true : nil);
    goto v56;

v56:
    if (v48 == nil) goto v57;
    v48 = stack[-6];
    v48 = qcar(v48);
    fn = elt(env, 11); /* simp!* */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    goto v58;

v58:
    stack[-4] = v48;
    v48 = stack[-4];
    v49 = qcdr(v48);
    v48 = (Lisp_Object)17; /* 1 */
    if (v49 == v48) goto v59;
    v48 = qvalue(elt(env, 3)); /* t */
    goto v60;

v60:
    if (v48 == nil) goto v61;
    v48 = stack[-4];
    v48 = qcar(v48);
    if (v48 == nil) goto v62;
    v49 = stack[-4];
    v48 = elt(env, 4); /* prepf */
    fn = elt(env, 12); /* sqform */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    v49 = v48;
    goto v63;

v63:
    v48 = elt(env, 5); /* "kernel or integer" */
    fn = elt(env, 13); /* typerr */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    goto v64;

v64:
    v48 = stack[-6];
    v48 = qcdr(v48);
    stack[-6] = v48;
    v48 = stack[-6];
    if (v48 == nil) goto v65;
    v48 = stack[-6];
    v48 = qcar(v48);
    fn = elt(env, 11); /* simp!* */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    stack[-3] = v48;
    v48 = stack[-3];
    v48 = qcar(v48);
    if (v48 == nil) goto v66;
    v48 = stack[-3];
    fn = elt(env, 14); /* d2int */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    stack[0] = v48;
    if (v48 == nil) goto v67;
    v48 = stack[-6];
    v48 = qcdr(v48);
    stack[-6] = v48;
    v48 = (Lisp_Object)17; /* 1 */
    stack[-1] = v48;
    goto v68;

v68:
    v49 = stack[0];
    v48 = stack[-1];
    v48 = difference2(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    v48 = Lminusp(nil, v48);
    env = stack[-7];
    if (v48 == nil) goto v69;
    v48 = qvalue(elt(env, 9)); /* nil */
    stack[-3] = v48;
    goto v52;

v69:
    v49 = stack[-5];
    v48 = stack[-4];
    fn = elt(env, 15); /* diffsq */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    stack[-5] = v48;
    v48 = stack[-1];
    v48 = add1(v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    stack[-1] = v48;
    goto v68;

v67:
    v49 = stack[-5];
    v48 = stack[-4];
    fn = elt(env, 15); /* diffsq */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    stack[-5] = v48;
    goto v52;

v66:
    v48 = stack[-6];
    v48 = qcdr(v48);
    stack[-6] = v48;
    v48 = qvalue(elt(env, 9)); /* nil */
    stack[-3] = v48;
    goto v52;

v65:
    v49 = stack[-5];
    v48 = stack[-4];
    fn = elt(env, 15); /* diffsq */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    stack[-5] = v48;
    goto v52;

v62:
    v48 = (Lisp_Object)1; /* 0 */
    v49 = v48;
    goto v63;

v61:
    v48 = stack[-4];
    v48 = qcar(v48);
    stack[-2] = v48;
    v48 = stack[-2];
    if (!consp(v48)) goto v70;
    v48 = stack[-2];
    v48 = qcar(v48);
    v48 = (consp(v48) ? nil : lisp_true);
    goto v71;

v71:
    if (v48 == nil) goto v72;
    v48 = stack[-2];
    v49 = qcar(v48);
    v48 = elt(env, 6); /* domain!-diff!-fn */
    v48 = get(v49, v48);
    env = stack[-7];
    if (v48 == nil) goto v73;
    stack[-1] = qvalue(elt(env, 7)); /* dmode!* */
    qvalue(elt(env, 7)) = nil; /* dmode!* */
    stack[0] = qvalue(elt(env, 8)); /* alglist!* */
    qvalue(elt(env, 8)) = nil; /* alglist!* */
    v48 = qvalue(elt(env, 9)); /* nil */
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-7];
    qvalue(elt(env, 8)) = v48; /* alglist!* */
    v48 = stack[-2];
    fn = elt(env, 4); /* prepf */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-7];
    stack[-4] = v48;
    v48 = stack[-4];
    fn = elt(env, 16); /* prekernp */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-7];
    if (!(v48 == nil)) goto v75;
    v49 = stack[-4];
    v48 = elt(env, 10); /* "kernel" */
    fn = elt(env, 13); /* typerr */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-7];
    goto v75;

v75:
    qvalue(elt(env, 8)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 7)) = stack[-1]; /* dmode!* */
    goto v64;

v73:
    v48 = stack[-2];
    fn = elt(env, 4); /* prepf */
    v49 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    v48 = elt(env, 10); /* "kernel" */
    fn = elt(env, 13); /* typerr */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    goto v64;

v72:
    v48 = stack[-2];
    v48 = qcdr(v48);
    if (v48 == nil) goto v76;
    v48 = qvalue(elt(env, 9)); /* nil */
    goto v77;

v77:
    if (v48 == nil) goto v78;
    v48 = stack[-2];
    v48 = qcar(v48);
    v48 = qcar(v48);
    v48 = qcar(v48);
    stack[-4] = v48;
    goto v64;

v78:
    v48 = stack[-2];
    fn = elt(env, 4); /* prepf */
    v49 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    v48 = elt(env, 10); /* "kernel" */
    fn = elt(env, 13); /* typerr */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    goto v64;

v76:
    v48 = stack[-2];
    v48 = qcar(v48);
    v49 = qcdr(v48);
    v48 = (Lisp_Object)17; /* 1 */
    if (v49 == v48) goto v79;
    v48 = qvalue(elt(env, 9)); /* nil */
    goto v77;

v79:
    v48 = stack[-2];
    v48 = qcar(v48);
    v48 = qcar(v48);
    v49 = qcdr(v48);
    v48 = (Lisp_Object)17; /* 1 */
    v48 = (v49 == v48 ? lisp_true : nil);
    goto v77;

v70:
    v48 = qvalue(elt(env, 3)); /* t */
    goto v71;

v59:
    v48 = stack[-4];
    v48 = qcar(v48);
    v48 = (consp(v48) ? nil : lisp_true);
    goto v60;

v57:
    v48 = stack[-3];
    goto v58;

v55:
    v48 = qvalue(elt(env, 3)); /* t */
    goto v56;

v53:
    v48 = qvalue(elt(env, 3)); /* t */
    goto v54;

v50:
    v49 = elt(env, 2); /* df */
    v48 = stack[-5];
    v49 = cons(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-7];
    v48 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 17); /* mksq */
        return (*qfn2(fn))(qenv(fn), v49, v48);
    }
/* error exit handlers */
v74:
    env = stack[-7];
    qvalue(elt(env, 8)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 7)) = stack[-1]; /* dmode!* */
    popv(8);
    return nil;
v51:
    popv(8);
    return nil;
}



/* Code for findoptrow */

static Lisp_Object MS_CDECL CC_findoptrow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v11, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v109, v110, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "findoptrow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findoptrow");
#endif
    if (stack >= stacklimit)
    {
        push3(v11,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v80,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v11;
    stack[0] = v80;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    stack[-2] = stack[0];
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v109 = qvalue(elt(env, 2)); /* maxvar */
    v24 = stack[-6];
    v24 = plus2(v109, v24);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    v109 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL)));
    v24 = (Lisp_Object)65; /* 4 */
    v24 = *(Lisp_Object *)((char *)v109 + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL)));
    fn = elt(env, 8); /* pnthxzz */
    v24 = (*qfn2(fn))(qenv(fn), stack[-2], v24);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    v24 = qcar(v24);
    v24 = qcdr(v24);
    v24 = qcar(v24);
    stack[-3] = v24;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v109 = qvalue(elt(env, 2)); /* maxvar */
    v24 = stack[0];
    v24 = plus2(v109, v24);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    v109 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL)));
    v24 = (Lisp_Object)65; /* 4 */
    v24 = *(Lisp_Object *)((char *)v109 + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL)));
    stack[-2] = v24;
    goto v112;

v112:
    v24 = stack[-2];
    if (v24 == nil) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    v24 = stack[-2];
    v24 = qcar(v24);
    stack[-1] = v24;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v109 = qvalue(elt(env, 2)); /* maxvar */
    v24 = stack[-1];
    v24 = qcar(v24);
    stack[-4] = v24;
    v24 = plus2(v109, v24);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    v109 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL)));
    v24 = (Lisp_Object)1; /* 0 */
    v24 = *(Lisp_Object *)((char *)v109 + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL)));
    if (v24 == nil) goto v113;
    v17 = stack[-4];
    v110 = stack[-6];
    v24 = stack[-1];
    v24 = qcdr(v24);
    v109 = qcar(v24);
    v24 = stack[-3];
    fn = elt(env, 9); /* testpr */
    v24 = (*qfnn(fn))(qenv(fn), 4, v17, v110, v109, v24);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    stack[0] = v24;
    v24 = qcdr(v24);
    if (v24 == nil) goto v114;
    v24 = stack[0];
    v109 = Llength(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    stack[-1] = v109;
    v24 = stack[-5];
    v24 = (Lisp_Object)greaterp2(v109, v24);
    nil = C_nil;
    if (exception_pending()) goto v111;
    v24 = v24 ? lisp_true : nil;
    env = stack[-8];
    if (v24 == nil) goto v29;
    v24 = stack[-1];
    stack[-5] = v24;
    qvalue(elt(env, 5)) = v24; /* newnjsi */
    v24 = stack[-4];
    stack[-7] = v24;
    v24 = stack[0];
    qvalue(elt(env, 6)) = v24; /* newjsi */
    goto v29;

v29:
    v109 = stack[-4];
    v24 = qvalue(elt(env, 7)); /* roccup2 */
    v24 = cons(v109, v24);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    qvalue(elt(env, 7)) = v24; /* roccup2 */
    goto v115;

v115:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v109 = qvalue(elt(env, 2)); /* maxvar */
    v24 = stack[-4];
    v24 = plus2(v109, v24);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    v110 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v24/(16/CELL)));
    v109 = (Lisp_Object)1; /* 0 */
    v24 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v110 + (CELL-TAG_VECTOR) + ((int32_t)v109/(16/CELL))) = v24;
    goto v113;

v113:
    v24 = stack[-2];
    v24 = qcdr(v24);
    stack[-2] = v24;
    goto v112;

v114:
    v109 = stack[-4];
    v24 = qvalue(elt(env, 4)); /* roccup1 */
    v24 = cons(v109, v24);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-8];
    qvalue(elt(env, 4)) = v24; /* roccup1 */
    goto v115;
/* error exit handlers */
v111:
    popv(9);
    return nil;
}



/* Code for mkunarywedge */

static Lisp_Object CC_mkunarywedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v119, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkunarywedge");
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
    goto v7;

v7:
    v118 = stack[0];
    if (v118 == nil) goto v52;
    v118 = stack[0];
    v118 = qcar(v118);
    v118 = qcar(v118);
    v107 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    v118 = stack[0];
    v118 = qcar(v118);
    v119 = qcdr(v118);
    v118 = stack[-1];
    v118 = acons(v107, v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    stack[-1] = v118;
    v118 = stack[0];
    v118 = qcdr(v118);
    stack[0] = v118;
    goto v7;

v52:
    v118 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v118);
    }
/* error exit handlers */
v43:
    popv(3);
    return nil;
}



/* Code for all_defined_map_ */

static Lisp_Object CC_all_defined_map_(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined_map_");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v123 = v80;
    v124 = v0;
/* end of prologue */
    v125 = v124;
    v124 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* al1_defined_map_ */
        return (*qfnn(fn))(qenv(fn), 3, v125, v124, v123);
    }
}



/* Code for groeb!=testb */

static Lisp_Object CC_groebMtestb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testb");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */
    v136 = stack[-1];
    fn = elt(env, 2); /* mo_comp */
    v137 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v136 = stack[0];
    v136 = qcar(v136);
    if (equal(v137, v136)) goto v50;
    v136 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v136); }

v50:
    stack[-2] = stack[-1];
    v137 = stack[0];
    v136 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v136 = qcar(v136);
    fn = elt(env, 4); /* mo_divides!? */
    v136 = (*qfn2(fn))(qenv(fn), stack[-2], v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    if (v136 == nil) goto v138;
    v137 = stack[0];
    v136 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 3); /* pnth */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v136 = qcar(v136);
    fn = elt(env, 5); /* bas_dpoly */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    fn = elt(env, 6); /* dp_lmon */
    v137 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v136 = stack[-1];
    fn = elt(env, 7); /* mo_lcm */
    stack[-2] = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v137 = stack[0];
    v136 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v136 = qcar(v136);
    fn = elt(env, 8); /* mo_equal!? */
    v136 = (*qfn2(fn))(qenv(fn), stack[-2], v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    if (v136 == nil) goto v38;
    v136 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v136); }

v38:
    v137 = stack[0];
    v136 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 3); /* pnth */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v136 = qcar(v136);
    fn = elt(env, 5); /* bas_dpoly */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    fn = elt(env, 6); /* dp_lmon */
    v137 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v136 = stack[-1];
    fn = elt(env, 7); /* mo_lcm */
    stack[-1] = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v137 = stack[0];
    v136 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v136 = qcar(v136);
    fn = elt(env, 8); /* mo_equal!? */
    v136 = (*qfn2(fn))(qenv(fn), stack[-1], v136);
    nil = C_nil;
    if (exception_pending()) goto v33;
    v136 = (v136 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v136); }

v138:
    v136 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v136); }
/* error exit handlers */
v33:
    popv(4);
    return nil;
}



/* Code for dummy_nam */

static Lisp_Object CC_dummy_nam(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dummy_nam");
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
    v121 = v0;
/* end of prologue */
    fn = elt(env, 4); /* ordn */
    v122 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[0];
    v121 = elt(env, 1); /* symbolic */
    fn = elt(env, 5); /* list2vect!* */
    v121 = (*qfn2(fn))(qenv(fn), v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[0];
    qvalue(elt(env, 2)) = v121; /* g_dvnames */
    v121 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v121); }
/* error exit handlers */
v123:
    popv(1);
    return nil;
}



/* Code for mk!+inner!+product */

static Lisp_Object CC_mkLinnerLproduct(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+inner+product");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v80;
    stack[-3] = v0;
/* end of prologue */
    v143 = stack[-3];
    fn = elt(env, 7); /* get!+vec!+dim */
    stack[0] = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v143 = stack[-1];
    fn = elt(env, 7); /* get!+vec!+dim */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    if (equal(stack[0], v143)) goto v145;
    v143 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v143 == nil)) goto v146;
    v143 = elt(env, 2); /* "Error in Gram_schmidt: each list in input must be the same length." 
*/
    fn = elt(env, 8); /* lprie */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    goto v146;

v146:
    v143 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    goto v145;

v145:
    v62 = qvalue(elt(env, 3)); /* nil */
    v143 = (Lisp_Object)17; /* 1 */
    v143 = cons(v62, v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    stack[0] = v143;
    v143 = qvalue(elt(env, 4)); /* !*complex */
    if (v143 == nil) goto v112;
    v143 = stack[-1];
    fn = elt(env, 9); /* mk!+conjugate!+vec */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    stack[-4] = v143;
    goto v53;

v53:
    v143 = (Lisp_Object)17; /* 1 */
    stack[-2] = v143;
    goto v147;

v147:
    v143 = stack[-3];
    fn = elt(env, 7); /* get!+vec!+dim */
    v62 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v143 = stack[-2];
    v143 = difference2(v62, v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v143 = Lminusp(nil, v143);
    env = stack[-5];
    if (v143 == nil) goto v148;
    v143 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v143; /* !*sub2 */
    v143 = stack[0];
    fn = elt(env, 10); /* subs2 */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[0] = v143;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v148:
    stack[-1] = stack[0];
    v62 = stack[-3];
    v143 = stack[-2];
    fn = elt(env, 11); /* get!+vec!+entry */
    stack[0] = (*qfn2(fn))(qenv(fn), v62, v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v62 = stack[-4];
    v143 = stack[-2];
    fn = elt(env, 11); /* get!+vec!+entry */
    v143 = (*qfn2(fn))(qenv(fn), v62, v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    fn = elt(env, 12); /* multsq */
    v143 = (*qfn2(fn))(qenv(fn), stack[0], v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    fn = elt(env, 13); /* addsq */
    v143 = (*qfn2(fn))(qenv(fn), stack[-1], v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    stack[0] = v143;
    v143 = stack[-2];
    v143 = add1(v143);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    stack[-2] = v143;
    goto v147;

v112:
    v143 = stack[-1];
    stack[-4] = v143;
    goto v53;
/* error exit handlers */
v149:
    env = stack[-5];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(6);
    return nil;
v144:
    popv(6);
    return nil;
}



/* Code for freeof!-df */

static Lisp_Object CC_freeofKdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof-df");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */
    v101 = stack[-1];
    if (!consp(v101)) goto v7;
    v101 = stack[-1];
    v153 = qcar(v101);
    v101 = elt(env, 2); /* df */
    if (v153 == v101) goto v146;
    v101 = stack[-1];
    v153 = qcdr(v101);
    v101 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeof!-dfl */
        return (*qfn2(fn))(qenv(fn), v153, v101);
    }

v146:
    v101 = stack[-1];
    v101 = qcdr(v101);
    v153 = qcar(v101);
    v101 = stack[0];
    v101 = CC_freeofKdf(env, v153, v101);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    if (v101 == nil) goto v50;
    v153 = stack[0];
    v101 = stack[-1];
    v101 = qcdr(v101);
    v101 = qcdr(v101);
    fn = elt(env, 5); /* smember */
    v101 = (*qfn2(fn))(qenv(fn), v153, v101);
    nil = C_nil;
    if (exception_pending()) goto v154;
    v101 = (v101 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v101); }

v50:
    v101 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v101); }

v7:
    v101 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v101); }
/* error exit handlers */
v154:
    popv(3);
    return nil;
}



/* Code for mri_irsplit1 */

static Lisp_Object CC_mri_irsplit1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v165, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_irsplit1");
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
    v164 = stack[0];
    if (!consp(v164)) goto v124;
    v164 = stack[0];
    v164 = qcar(v164);
    v164 = (consp(v164) ? nil : lisp_true);
    goto v123;

v123:
    if (v164 == nil) goto v139;
    v164 = stack[0];
    popv(5);
    return ncons(v164);

v139:
    v164 = stack[0];
    v164 = qcdr(v164);
    v164 = CC_mri_irsplit1(env, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    stack[-2] = v164;
    v164 = stack[0];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v164 = qcdr(v164);
    stack[-1] = v164;
    v164 = stack[0];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v166 = qcar(v164);
    v165 = (Lisp_Object)17; /* 1 */
    v164 = (Lisp_Object)17; /* 1 */
    v164 = acons(v166, v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    v165 = ncons(v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    v164 = stack[-1];
    fn = elt(env, 2); /* exptf */
    v164 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    stack[-1] = v164;
    v164 = stack[-1];
    v164 = qcar(v164);
    v164 = qcar(v164);
    v164 = qcar(v164);
    fn = elt(env, 3); /* mri_realvarp */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    if (v164 == nil) goto v55;
    v164 = stack[-2];
    stack[-3] = qcar(v164);
    v164 = stack[0];
    v164 = qcar(v164);
    v165 = qcdr(v164);
    v164 = stack[-1];
    fn = elt(env, 4); /* multf */
    v165 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    v164 = stack[-2];
    v164 = qcdr(v164);
    fn = elt(env, 5); /* addf */
    v164 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    {
        Lisp_Object v168 = stack[-3];
        popv(5);
        return cons(v168, v164);
    }

v55:
    v164 = stack[0];
    v164 = qcar(v164);
    v164 = qcdr(v164);
    v164 = CC_mri_irsplit1(env, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    stack[-3] = v164;
    v164 = stack[-3];
    v165 = qcar(v164);
    v164 = stack[-1];
    fn = elt(env, 4); /* multf */
    v165 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    v164 = stack[-2];
    v164 = qcar(v164);
    fn = elt(env, 5); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    v164 = stack[-3];
    v165 = qcdr(v164);
    v164 = stack[-1];
    fn = elt(env, 4); /* multf */
    v165 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    v164 = stack[-2];
    v164 = qcdr(v164);
    fn = elt(env, 5); /* addf */
    v164 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    {
        Lisp_Object v169 = stack[0];
        popv(5);
        return cons(v169, v164);
    }

v124:
    v164 = qvalue(elt(env, 1)); /* t */
    goto v123;
/* error exit handlers */
v167:
    popv(5);
    return nil;
}



/* Code for pasf_cein */

static Lisp_Object CC_pasf_cein(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_cein");
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
    v189 = stack[-3];
    v188 = elt(env, 1); /* true */
    if (v189 == v188) goto v125;
    v189 = stack[-3];
    v188 = elt(env, 3); /* false */
    v188 = (v189 == v188 ? lisp_true : nil);
    goto v124;

v124:
    if (v188 == nil) goto v162;
    v188 = qvalue(elt(env, 2)); /* t */
    goto v120;

v120:
    if (!(v188 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v188 = stack[-3];
    v188 = qcdr(v188);
    v188 = qcar(v188);
    fn = elt(env, 10); /* pasf_deci */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    stack[-2] = v188;
    v188 = stack[-2];
    v188 = qcar(v188);
    fn = elt(env, 11); /* sfto_dcontentf */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    stack[-4] = v188;
    v188 = stack[-3];
    stack[-1] = qcar(v188);
    v188 = stack[-4];
    fn = elt(env, 12); /* simp */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v188 = qcar(v188);
    v189 = qvalue(elt(env, 5)); /* !*exp */
    if (v189 == nil) goto v35;
    v189 = qvalue(elt(env, 6)); /* !*mcd */
    v189 = (v189 == nil ? lisp_true : nil);
    goto v34;

v34:
    if (v189 == nil) goto v191;
    v189 = stack[-2];
    v189 = qcar(v189);
    fn = elt(env, 13); /* quotf */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    stack[0] = v188;
    goto v192;

v192:
    v189 = stack[-3];
    v188 = elt(env, 1); /* true */
    if (v189 == v188) goto v193;
    v189 = stack[-3];
    v188 = elt(env, 3); /* false */
    v188 = (v189 == v188 ? lisp_true : nil);
    goto v194;

v194:
    if (v188 == nil) goto v195;
    v188 = stack[-3];
    v189 = v188;
    goto v30;

v30:
    v188 = elt(env, 7); /* (leq greaterp) */
    v188 = Lmemq(nil, v189, v188);
    if (v188 == nil) goto v196;
    v188 = stack[-2];
    v188 = qcdr(v188);
    v189 = negate(v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v188 = stack[-4];
    fn = elt(env, 14); /* pasf_floor */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    fn = elt(env, 15); /* negf */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    goto v127;

v127:
    fn = elt(env, 16); /* addf */
    v188 = (*qfn2(fn))(qenv(fn), stack[0], v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v189 = qvalue(elt(env, 9)); /* nil */
    {
        Lisp_Object v197 = stack[-1];
        popv(6);
        return list3(v197, v188, v189);
    }

v196:
    v189 = stack[-3];
    v188 = elt(env, 1); /* true */
    if (v189 == v188) goto v198;
    v189 = stack[-3];
    v188 = elt(env, 3); /* false */
    v188 = (v189 == v188 ? lisp_true : nil);
    goto v199;

v199:
    if (v188 == nil) goto v200;
    v188 = stack[-3];
    v189 = v188;
    goto v201;

v201:
    v188 = elt(env, 8); /* (geq lessp) */
    v188 = Lmemq(nil, v189, v188);
    if (v188 == nil) goto v202;
    v188 = stack[-2];
    v188 = qcdr(v188);
    v189 = negate(v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v188 = stack[-4];
    fn = elt(env, 17); /* pasf_ceil */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    fn = elt(env, 15); /* negf */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    goto v127;

v202:
    v188 = nil;
    goto v127;

v200:
    v188 = stack[-3];
    v188 = qcar(v188);
    v188 = Lconsp(nil, v188);
    env = stack[-5];
    if (v188 == nil) goto v203;
    v188 = stack[-3];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v189 = v188;
    goto v201;

v203:
    v188 = stack[-3];
    v188 = qcar(v188);
    v189 = v188;
    goto v201;

v198:
    v188 = qvalue(elt(env, 2)); /* t */
    goto v199;

v195:
    v188 = stack[-3];
    v188 = qcar(v188);
    v188 = Lconsp(nil, v188);
    env = stack[-5];
    if (v188 == nil) goto v204;
    v188 = stack[-3];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v189 = v188;
    goto v30;

v204:
    v188 = stack[-3];
    v188 = qcar(v188);
    v189 = v188;
    goto v30;

v193:
    v188 = qvalue(elt(env, 2)); /* t */
    goto v194;

v191:
    v189 = stack[-2];
    v189 = qcar(v189);
    fn = elt(env, 18); /* quotfx1 */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    stack[0] = v188;
    goto v192;

v35:
    v189 = qvalue(elt(env, 2)); /* t */
    goto v34;

v162:
    v189 = stack[-3];
    v188 = elt(env, 1); /* true */
    if (v189 == v188) goto v39;
    v189 = stack[-3];
    v188 = elt(env, 3); /* false */
    v188 = (v189 == v188 ? lisp_true : nil);
    goto v132;

v132:
    if (v188 == nil) goto v205;
    v188 = stack[-3];
    v189 = v188;
    goto v206;

v206:
    v188 = elt(env, 4); /* (leq greaterp geq lessp) */
    v188 = Lmemq(nil, v189, v188);
    v188 = (v188 == nil ? lisp_true : nil);
    goto v120;

v205:
    v188 = stack[-3];
    v188 = qcar(v188);
    v188 = Lconsp(nil, v188);
    env = stack[-5];
    if (v188 == nil) goto v113;
    v188 = stack[-3];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v189 = v188;
    goto v206;

v113:
    v188 = stack[-3];
    v188 = qcar(v188);
    v189 = v188;
    goto v206;

v39:
    v188 = qvalue(elt(env, 2)); /* t */
    goto v132;

v125:
    v188 = qvalue(elt(env, 2)); /* t */
    goto v124;
/* error exit handlers */
v190:
    popv(6);
    return nil;
}



/* Code for ctx_union */

static Lisp_Object CC_ctx_union(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_union");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v80;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v164 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setkorder */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    stack[0] = v164;
    v164 = stack[0];
    fn = elt(env, 3); /* setkorder */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    v164 = stack[-3];
    fn = elt(env, 4); /* ctx_ial */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    stack[-3] = v164;
    v164 = stack[-2];
    fn = elt(env, 4); /* ctx_ial */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    stack[-2] = v164;
    v164 = stack[0];
    stack[-1] = v164;
    goto v138;

v138:
    v164 = stack[-1];
    if (v164 == nil) goto v104;
    v164 = stack[-1];
    v164 = qcar(v164);
    stack[0] = v164;
    v164 = stack[-3];
    if (v164 == nil) goto v187;
    v164 = stack[-3];
    v164 = qcar(v164);
    v165 = qcar(v164);
    v164 = stack[0];
    v164 = (v165 == v164 ? lisp_true : nil);
    goto v119;

v119:
    if (v164 == nil) goto v145;
    v164 = stack[-3];
    v165 = qcar(v164);
    v164 = stack[-4];
    v164 = cons(v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    stack[-4] = v164;
    v164 = stack[-3];
    v164 = qcdr(v164);
    stack[-3] = v164;
    v164 = stack[-2];
    if (v164 == nil) goto v116;
    v164 = stack[-2];
    v164 = qcar(v164);
    v165 = qcar(v164);
    v164 = stack[0];
    if (!(v165 == v164)) goto v116;
    v164 = stack[-2];
    v164 = qcdr(v164);
    stack[-2] = v164;
    goto v116;

v116:
    v164 = stack[-1];
    v164 = qcdr(v164);
    stack[-1] = v164;
    goto v138;

v145:
    v164 = stack[-2];
    if (v164 == nil) goto v155;
    v164 = stack[-2];
    v164 = qcar(v164);
    v165 = qcar(v164);
    v164 = stack[0];
    v164 = (v165 == v164 ? lisp_true : nil);
    goto v160;

v160:
    if (v164 == nil) goto v116;
    v164 = stack[-2];
    v165 = qcar(v164);
    v164 = stack[-4];
    v164 = cons(v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    stack[-4] = v164;
    v164 = stack[-2];
    v164 = qcdr(v164);
    stack[-2] = v164;
    goto v116;

v155:
    v164 = qvalue(elt(env, 1)); /* nil */
    goto v160;

v187:
    v164 = qvalue(elt(env, 1)); /* nil */
    goto v119;

v104:
    v164 = stack[-3];
    if (!(v164 == nil)) goto v34;
    v164 = stack[-2];
    if (!(v164 == nil)) goto v34;

v184:
    v164 = stack[-4];
    v164 = Lnreverse(nil, v164);
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 5); /* ctx_fromial */
        return (*qfn1(fn))(qenv(fn), v164);
    }

v34:
    v164 = elt(env, 2); /* "***** ctx_union: idorder not complete" */
    v164 = Lprinc(nil, v164);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    v164 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    goto v184;
/* error exit handlers */
v167:
    popv(6);
    return nil;
}



/* Code for numir */

static Lisp_Object MS_CDECL CC_numir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201, v223, v224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "numir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numir");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* end of prologue */
    v223 = qvalue(elt(env, 1)); /* atts */
    v201 = elt(env, 2); /* name */
    fn = elt(env, 12); /* find */
    v201 = (*qfn2(fn))(qenv(fn), v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    v201 = Lintern(nil, v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    stack[-1] = v201;
    fn = elt(env, 13); /* lex */
    v201 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    fn = elt(env, 14); /* omobj */
    v201 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    stack[0] = v201;
    fn = elt(env, 13); /* lex */
    v201 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    fn = elt(env, 14); /* omobj */
    v201 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    v224 = stack[-1];
    v223 = elt(env, 3); /* complex_cartesian */
    if (!(v224 == v223)) goto v226;
    v223 = stack[0];
    if (symbolp(v223)) goto v53;
    v223 = v201;
    if (!(symbolp(v223))) goto v226;

v53:
    stack[-4] = elt(env, 4); /* plus */
    stack[-3] = qvalue(elt(env, 5)); /* nil */
    stack[-2] = stack[0];
    stack[-1] = elt(env, 6); /* times */
    stack[0] = qvalue(elt(env, 5)); /* nil */
    v224 = v201;
    v223 = elt(env, 7); /* !&imaginaryi!; */
    v201 = qvalue(elt(env, 5)); /* nil */
    v201 = list2star(v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    v223 = list2star(stack[-1], stack[0], v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    v201 = qvalue(elt(env, 5)); /* nil */
    v201 = list2star(stack[-2], v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    {
        Lisp_Object v196 = stack[-4];
        Lisp_Object v227 = stack[-3];
        popv(8);
        return list2star(v196, v227, v201);
    }

v226:
    v224 = stack[-1];
    v223 = elt(env, 8); /* complex_polar */
    if (!(v224 == v223)) goto v25;
    v223 = stack[0];
    if (symbolp(v223)) goto v155;
    v223 = v201;
    if (!(symbolp(v223))) goto v25;

v155:
    stack[-6] = elt(env, 6); /* times */
    stack[-5] = qvalue(elt(env, 5)); /* nil */
    stack[-4] = stack[0];
    stack[-3] = elt(env, 9); /* exp */
    stack[-2] = qvalue(elt(env, 5)); /* nil */
    stack[-1] = elt(env, 6); /* times */
    stack[0] = qvalue(elt(env, 5)); /* nil */
    v224 = v201;
    v223 = elt(env, 7); /* !&imaginaryi!; */
    v201 = qvalue(elt(env, 5)); /* nil */
    v201 = list2star(v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    v201 = list2star(stack[-1], stack[0], v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    v201 = ncons(v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    v223 = list2star(stack[-3], stack[-2], v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-7];
    v201 = qvalue(elt(env, 5)); /* nil */
    v201 = list2star(stack[-4], v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    {
        Lisp_Object v228 = stack[-6];
        Lisp_Object v229 = stack[-5];
        popv(8);
        return list2star(v228, v229, v201);
    }

v25:
    v224 = stack[-1];
    v223 = elt(env, 10); /* rational */
    if (!(v224 == v223)) goto v230;
    v223 = stack[0];
    if (symbolp(v223)) goto v181;
    v223 = v201;
    if (!(symbolp(v223))) goto v230;

v181:
    stack[-2] = elt(env, 11); /* divide */
    stack[-1] = qvalue(elt(env, 5)); /* nil */
    v224 = stack[0];
    v223 = v201;
    v201 = qvalue(elt(env, 5)); /* nil */
    v201 = list2star(v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    {
        Lisp_Object v231 = stack[-2];
        Lisp_Object v177 = stack[-1];
        popv(8);
        return list2star(v231, v177, v201);
    }

v230:
    stack[-2] = stack[-1];
    stack[-1] = qvalue(elt(env, 5)); /* nil */
    v224 = stack[0];
    v223 = v201;
    v201 = qvalue(elt(env, 5)); /* nil */
    v201 = list2star(v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v225;
    {
        Lisp_Object v176 = stack[-2];
        Lisp_Object v232 = stack[-1];
        popv(8);
        return list2star(v176, v232, v201);
    }
/* error exit handlers */
v225:
    popv(8);
    return nil;
}



/* Code for i2crn!* */

static Lisp_Object CC_i2crnH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v45;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2crn*");
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
    v47 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !:crn!: */
    v45 = v47;
    v47 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v45, v47);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    v45 = (Lisp_Object)1; /* 0 */
    v47 = (Lisp_Object)17; /* 1 */
    v47 = cons(v45, v47);
    nil = C_nil;
    if (exception_pending()) goto v152;
    {
        Lisp_Object v145 = stack[-1];
        Lisp_Object v118 = stack[0];
        popv(3);
        return list2star(v145, v118, v47);
    }
/* error exit handlers */
v152:
    popv(3);
    return nil;
}



/* Code for solvealgtrig01 */

static Lisp_Object CC_solvealgtrig01(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvealgtrig01");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */

v98:
    v147 = stack[-1];
    if (!consp(v147)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v147 = stack[-1];
    v235 = qcar(v147);
    v147 = elt(env, 1); /* (sin cos tan cot sinh cosh tanh coth) */
    v147 = Lmemq(nil, v235, v147);
    if (v147 == nil) goto v112;
    v147 = stack[-1];
    v147 = qcdr(v147);
    v147 = qcar(v147);
    fn = elt(env, 2); /* constant_exprp */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    if (!(v147 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v147 = stack[-1];
    v147 = qcdr(v147);
    v147 = qcar(v147);
    v235 = ncons(v147);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    v147 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* union */
        return (*qfn2(fn))(qenv(fn), v235, v147);
    }

v112:
    v147 = stack[-1];
    v147 = qcdr(v147);
    stack[-2] = v147;
    v147 = stack[-1];
    v235 = qcar(v147);
    v147 = stack[0];
    v147 = CC_solvealgtrig01(env, v235, v147);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[0] = v147;
    v147 = stack[-2];
    stack[-1] = v147;
    goto v98;
/* error exit handlers */
v103:
    popv(4);
    return nil;
}



/* Code for add_item */

static Lisp_Object CC_add_item(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_item");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */

v7:
    v235 = stack[0];
    v235 = qcdr(v235);
    if (v235 == nil) goto v122;
    v235 = stack[0];
    v235 = qcar(v235);
    v154 = qcar(v235);
    v235 = stack[-1];
    v235 = qcar(v235);
    fn = elt(env, 3); /* monordp */
    v235 = (*qfn2(fn))(qenv(fn), v154, v235);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    if (v235 == nil) goto v55;
    v235 = stack[0];
    v235 = qcdr(v235);
    v235 = qcar(v235);
    stack[0] = v235;
    goto v7;

v55:
    v235 = stack[0];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    stack[0] = v235;
    goto v7;

v122:
    v154 = stack[0];
    v235 = stack[-1];
    fn = elt(env, 4); /* setcar */
    v235 = (*qfn2(fn))(qenv(fn), v154, v235);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[-1] = elt(env, 1); /* !*xset!* */
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v235 = elt(env, 1); /* !*xset!* */
    v235 = ncons(v235);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    v235 = acons(stack[-1], stack[0], v235);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    fn = elt(env, 5); /* setcdr */
    v235 = (*qfn2(fn))(qenv(fn), stack[-2], v235);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    v235 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v235); }
/* error exit handlers */
v99:
    popv(4);
    return nil;
}



/* Code for gbftimes */

static Lisp_Object CC_gbftimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gbftimes");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v42 = v80;
    v236 = v0;
/* end of prologue */
    v41 = v236;
    v41 = qcar(v41);
    stack[-4] = v41;
    v41 = v236;
    v41 = qcdr(v41);
    stack[-3] = v41;
    v41 = v42;
    v41 = qcar(v41);
    stack[-2] = v41;
    v41 = v42;
    v41 = qcdr(v41);
    stack[-1] = v41;
    v42 = stack[-4];
    v41 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v42 = stack[-3];
    v41 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    v41 = (*qfn2(fn))(qenv(fn), v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    fn = elt(env, 2); /* difbf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v41);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v42 = stack[-4];
    v41 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v42 = stack[-3];
    v41 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v41 = (*qfn2(fn))(qenv(fn), v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    fn = elt(env, 3); /* plubf */
    v41 = (*qfn2(fn))(qenv(fn), stack[-1], v41);
    nil = C_nil;
    if (exception_pending()) goto v133;
    {
        Lisp_Object v140 = stack[0];
        popv(6);
        return cons(v140, v41);
    }
/* error exit handlers */
v133:
    popv(6);
    return nil;
}



/* Code for kernelp */

static Lisp_Object CC_kernelp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernelp");
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
    v185 = stack[0];
    if (v185 == nil) goto v52;
    v185 = stack[0];
    fn = elt(env, 4); /* domain!*p */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-1];
    goto v87;

v87:
    if (v185 == nil) goto v7;
    v185 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v185); }

v7:
    v185 = stack[0];
    if (symbolp(v185)) goto v104;
    v185 = stack[0];
    fn = elt(env, 5); /* listp */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-1];
    if (v185 == nil) goto v206;
    v185 = stack[0];
    v185 = qcar(v185);
    if (!(symbolp(v185))) goto v206;
    v185 = stack[0];
    v151 = qcar(v185);
    v185 = elt(env, 3); /* (!*sq set setq plus minus difference times quotient) 
*/
    v185 = Lmemq(nil, v151, v185);
    if (!(v185 == nil)) goto v206;
    v185 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v185); }

v206:
    v185 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v185); }

v104:
    v185 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v185); }

v52:
    v185 = qvalue(elt(env, 1)); /* t */
    goto v87;
/* error exit handlers */
v205:
    popv(2);
    return nil;
}



/* Code for diff_vertex */

static Lisp_Object CC_diff_vertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v40, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff_vertex");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v80;
    stack[-1] = v0;
/* end of prologue */
    v56 = nil;
    goto v98;

v98:
    v163 = stack[-1];
    if (v163 == nil) goto v237;
    v163 = stack[-1];
    v163 = qcar(v163);
    v40 = qcar(v163);
    v163 = stack[0];
    v163 = Lassoc(nil, v40, v163);
    if (v163 == nil) goto v97;
    v163 = stack[-1];
    v163 = qcar(v163);
    v40 = qcar(v163);
    v163 = qvalue(elt(env, 1)); /* !_0edge */
    v163 = qcar(v163);
    if (v40 == v163) goto v97;
    v163 = stack[-1];
    v163 = qcdr(v163);
    stack[-1] = v163;
    goto v98;

v97:
    v163 = stack[-1];
    v163 = qcar(v163);
    v40 = v56;
    v163 = cons(v163, v40);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    v56 = v163;
    v163 = stack[-1];
    v163 = qcdr(v163);
    stack[-1] = v163;
    goto v98;

v237:
    v163 = v56;
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v163);
    }
/* error exit handlers */
v101:
    popv(3);
    return nil;
}



/* Code for setmatelem */

static Lisp_Object CC_setmatelem(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v18, v242;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmatelem");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v80;
    stack[-2] = v0;
/* end of prologue */
    v241 = stack[-2];
    v18 = Llength(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    v241 = (Lisp_Object)49; /* 3 */
    if (v18 == v241) goto v45;
    v18 = stack[-2];
    v241 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 12); /* typerr */
    v241 = (*qfn2(fn))(qenv(fn), v18, v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    goto v45;

v45:
    v241 = stack[-2];
    v18 = qcar(v241);
    v241 = elt(env, 2); /* avalue */
    v241 = get(v18, v241);
    env = stack[-4];
    stack[-3] = v241;
    v241 = stack[-3];
    if (v241 == nil) goto v150;
    v241 = stack[-3];
    v18 = qcar(v241);
    v241 = elt(env, 4); /* matrix */
    v241 = (v18 == v241 ? lisp_true : nil);
    v241 = (v241 == nil ? lisp_true : nil);
    goto v206;

v206:
    if (v241 == nil) goto v148;
    v241 = stack[-2];
    v18 = qcar(v241);
    v241 = elt(env, 5); /* "matrix" */
    fn = elt(env, 12); /* typerr */
    v241 = (*qfn2(fn))(qenv(fn), v18, v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    goto v105;

v105:
    v241 = stack[-2];
    v241 = qcdr(v241);
    v241 = qcar(v241);
    fn = elt(env, 13); /* reval_without_mod */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    stack[0] = v241;
    v241 = stack[0];
    v241 = integerp(v241);
    if (v241 == nil) goto v149;
    v18 = stack[0];
    v241 = (Lisp_Object)1; /* 0 */
    v241 = (Lisp_Object)lesseq2(v18, v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    v241 = v241 ? lisp_true : nil;
    env = stack[-4];
    goto v144;

v144:
    if (v241 == nil) goto v221;
    v18 = stack[0];
    v241 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v241 = (*qfn2(fn))(qenv(fn), v18, v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    goto v221;

v221:
    v241 = stack[-3];
    v18 = qcdr(v241);
    v241 = stack[0];
    fn = elt(env, 14); /* pnth */
    v241 = (*qfn2(fn))(qenv(fn), v18, v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    v241 = qcar(v241);
    stack[-3] = v241;
    v241 = stack[-2];
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    fn = elt(env, 13); /* reval_without_mod */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    stack[0] = v241;
    v241 = stack[0];
    v241 = integerp(v241);
    if (v241 == nil) goto v179;
    v18 = stack[0];
    v241 = (Lisp_Object)1; /* 0 */
    v241 = (Lisp_Object)lesseq2(v18, v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    v241 = v241 ? lisp_true : nil;
    env = stack[-4];
    goto v26;

v26:
    if (v241 == nil) goto v24;
    v18 = stack[0];
    v241 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v241 = (*qfn2(fn))(qenv(fn), v18, v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    goto v24;

v24:
    v18 = stack[-3];
    v241 = stack[0];
    fn = elt(env, 14); /* pnth */
    v18 = (*qfn2(fn))(qenv(fn), v18, v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    v241 = stack[-1];
        popv(5);
        return Lrplaca(nil, v18, v241);

v179:
    v241 = qvalue(elt(env, 3)); /* t */
    goto v26;

v149:
    v241 = qvalue(elt(env, 3)); /* t */
    goto v144;

v148:
    v241 = stack[-3];
    v241 = qcdr(v241);
    v18 = qcar(v241);
    stack[-3] = v18;
    v241 = elt(env, 6); /* mat */
    if (!consp(v18)) goto v36;
    v18 = qcar(v18);
    if (v18 == v241) goto v105;
    else goto v36;

v36:
    v242 = elt(env, 7); /* "Matrix" */
    v241 = stack[-2];
    v18 = qcar(v241);
    v241 = elt(env, 8); /* "not set" */
    v241 = list3(v242, v18, v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    v18 = v241;
    v241 = v18;
    qvalue(elt(env, 9)) = v241; /* errmsg!* */
    v241 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v241 == nil)) goto v130;
    v241 = v18;
    fn = elt(env, 15); /* lprie */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    goto v130;

v130:
    v241 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    goto v105;

v150:
    v241 = qvalue(elt(env, 3)); /* t */
    goto v206;
/* error exit handlers */
v212:
    popv(5);
    return nil;
}



/* Code for rfirst */

static Lisp_Object CC_rfirst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v133, v140, v64, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rfirst");
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
    v134 = qcar(v134);
    stack[0] = v134;
    v134 = stack[0];
    fn = elt(env, 7); /* listeval0 */
    v133 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    stack[-1] = v133;
    v134 = elt(env, 1); /* list */
    if (!consp(v133)) goto v233;
    v133 = qcar(v133);
    if (!(v133 == v134)) goto v233;
    v134 = qvalue(elt(env, 2)); /* nil */
    goto v121;

v121:
    if (v134 == nil) goto v52;
    v133 = stack[0];
    v134 = elt(env, 3); /* "list" */
    fn = elt(env, 8); /* typerr */
    v134 = (*qfn2(fn))(qenv(fn), v133, v134);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    goto v52;

v52:
    v134 = stack[-1];
    v134 = qcdr(v134);
    if (v134 == nil) goto v162;
    v134 = stack[-1];
    v134 = qcdr(v134);
    v134 = qcar(v134);
    {
        popv(3);
        fn = elt(env, 9); /* reval */
        return (*qfn1(fn))(qenv(fn), v134);
    }

v162:
    v159 = elt(env, 4); /* "Expression" */
    v64 = stack[0];
    v140 = elt(env, 5); /* "does not have part" */
    v133 = (Lisp_Object)17; /* 1 */
    v134 = qvalue(elt(env, 6)); /* t */
    fn = elt(env, 10); /* msgpri */
    v134 = (*qfnn(fn))(qenv(fn), 5, v159, v64, v140, v133, v134);
    nil = C_nil;
    if (exception_pending()) goto v60;
    v134 = nil;
    { popv(3); return onevalue(v134); }

v233:
    v134 = stack[0];
    fn = elt(env, 11); /* aeval */
    v133 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    stack[-1] = v133;
    v134 = elt(env, 1); /* list */
    v134 = Leqcar(nil, v133, v134);
    env = stack[-2];
    v134 = (v134 == nil ? lisp_true : nil);
    goto v121;
/* error exit handlers */
v60:
    popv(3);
    return nil;
}



/* Code for bc_from_a */

static Lisp_Object CC_bc_from_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_from_a");
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
    v98 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[0];
    v98 = qcar(v98);
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v98);
    }
/* error exit handlers */
v87:
    popv(1);
    return nil;
}



/* Code for st_sorttree1 */

static Lisp_Object MS_CDECL CC_st_sorttree1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v11, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v293, v294, v295;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_sorttree1");
#endif
    if (stack >= stacklimit)
    {
        push3(v11,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v80,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v11;
    stack[-9] = v80;
    stack[-10] = v0;
/* end of prologue */
    stack[-11] = nil;
    stack[-7] = nil;
    stack[-1] = nil;
    v293 = (Lisp_Object)17; /* 1 */
    stack[-6] = v293;
    v293 = stack[-10];
    v293 = qcdr(v293);
    v293 = qcar(v293);
    if (is_number(v293)) goto v117;
    v293 = stack[-10];
    v294 = qcar(v293);
    v293 = elt(env, 1); /* !* */
    if (v294 == v293) goto v27;
    v293 = stack[-10];
    v293 = qcdr(v293);
    stack[0] = v293;
    goto v296;

v296:
    v293 = stack[0];
    if (v293 == nil) goto v297;
    v293 = stack[0];
    v293 = qcar(v293);
    v295 = v293;
    v294 = stack[-6];
    v293 = (Lisp_Object)1; /* 0 */
    if (v294 == v293) goto v298;
    v294 = stack[-9];
    v293 = stack[-8];
    v293 = CC_st_sorttree1(env, 3, v295, v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-2] = v293;
    v294 = stack[-6];
    v293 = stack[-2];
    v293 = qcdr(v293);
    v293 = qcar(v293);
    v293 = times2(v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-6] = v293;
    v293 = stack[-2];
    v293 = qcdr(v293);
    v295 = qcdr(v293);
    v293 = stack[-2];
    v294 = qcar(v293);
    v293 = stack[-1];
    v293 = acons(v295, v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-1] = v293;
    goto v298;

v298:
    v293 = stack[0];
    v293 = qcdr(v293);
    stack[0] = v293;
    goto v296;

v297:
    v294 = stack[-6];
    v293 = (Lisp_Object)1; /* 0 */
    if (v294 == v293) goto v300;
    v293 = stack[-10];
    v294 = qcar(v293);
    v293 = elt(env, 3); /* !+ */
    if (v294 == v293) goto v301;
    v294 = stack[-1];
    v293 = stack[-8];
    fn = elt(env, 4); /* cdr_signsort */
    v293 = (*qfn2(fn))(qenv(fn), v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-1] = v293;
    v293 = stack[-1];
    v294 = qcar(v293);
    v293 = (Lisp_Object)1; /* 0 */
    if (v294 == v293) goto v302;
    v294 = stack[-6];
    v293 = stack[-1];
    v293 = qcar(v293);
    v293 = times2(v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-6] = v293;
    v293 = stack[-1];
    v293 = qcdr(v293);
    stack[-1] = v293;
    goto v303;

v303:
    v293 = stack[-1];
    if (v293 == nil) goto v304;
    v293 = stack[-1];
    v293 = qcar(v293);
    v294 = qcar(v293);
    v293 = stack[-7];
    v293 = cons(v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-7] = v293;
    v293 = stack[-1];
    v293 = qcar(v293);
    v294 = qcdr(v293);
    v293 = stack[-11];
    v293 = cons(v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-11] = v293;
    v293 = stack[-1];
    v293 = qcdr(v293);
    stack[-1] = v293;
    goto v303;

v304:
    v293 = stack[-10];
    stack[0] = qcar(v293);
    v293 = stack[-7];
    v293 = Lreverse(nil, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    v293 = cons(stack[0], v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-7] = v293;
    v293 = stack[-11];
    v293 = Lreverse(nil, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    stack[-11] = v293;
    v295 = stack[-11];
    v294 = stack[-6];
    v293 = stack[-7];
    popv(13);
    return list2star(v295, v294, v293);

v302:
    v294 = qvalue(elt(env, 2)); /* nil */
    v293 = (Lisp_Object)1; /* 0 */
    v295 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v294, v293, v295);

v301:
    v294 = stack[-1];
    v293 = stack[-8];
    fn = elt(env, 5); /* cdr_sort */
    v293 = (*qfn2(fn))(qenv(fn), v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-1] = v293;
    goto v303;

v300:
    v294 = qvalue(elt(env, 2)); /* nil */
    v293 = (Lisp_Object)1; /* 0 */
    v295 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v294, v293, v295);

v27:
    v293 = stack[-10];
    v293 = qcdr(v293);
    stack[0] = v293;
    goto v109;

v109:
    v293 = stack[0];
    if (v293 == nil) goto v305;
    v293 = stack[0];
    v293 = qcar(v293);
    v295 = v293;
    v294 = stack[-6];
    v293 = (Lisp_Object)1; /* 0 */
    if (v294 == v293) goto v211;
    v294 = stack[-9];
    v293 = stack[-8];
    v293 = CC_st_sorttree1(env, 3, v295, v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-2] = v293;
    v294 = stack[-6];
    v293 = stack[-2];
    v293 = qcdr(v293);
    v293 = qcar(v293);
    v293 = times2(v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-6] = v293;
    v293 = stack[-2];
    v294 = qcar(v293);
    v293 = stack[-11];
    v293 = cons(v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-11] = v293;
    v293 = stack[-2];
    v293 = qcdr(v293);
    v294 = qcdr(v293);
    v293 = stack[-7];
    v293 = cons(v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-7] = v293;
    goto v211;

v211:
    v293 = stack[0];
    v293 = qcdr(v293);
    stack[0] = v293;
    goto v109;

v305:
    v294 = stack[-6];
    v293 = (Lisp_Object)1; /* 0 */
    if (v294 == v293) goto v306;
    v293 = stack[-7];
    v293 = Lreverse(nil, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-7] = v293;
    v293 = stack[-11];
    v293 = Lreverse(nil, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-11] = v293;
    stack[0] = stack[-11];
    stack[-1] = stack[-6];
    v294 = elt(env, 1); /* !* */
    v293 = stack[-7];
    v293 = cons(v294, v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    {
        Lisp_Object v307 = stack[0];
        Lisp_Object v308 = stack[-1];
        popv(13);
        return list2star(v307, v308, v293);
    }

v306:
    v294 = qvalue(elt(env, 2)); /* nil */
    v293 = (Lisp_Object)1; /* 0 */
    v295 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v294, v293, v295);

v117:
    v293 = stack[-10];
    v294 = qcar(v293);
    v293 = elt(env, 1); /* !* */
    if (v294 == v293) goto v50;
    v293 = stack[-10];
    v293 = qcdr(v293);
    stack[-5] = v293;
    v293 = stack[-5];
    if (v293 == nil) goto v216;
    v293 = stack[-5];
    v293 = qcar(v293);
    stack[-1] = v293;
    stack[0] = stack[-9];
    v293 = sub1(v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    v293 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v293/(16/CELL)));
    v293 = cons(stack[-1], v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    v293 = ncons(v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-3] = v293;
    stack[-4] = v293;
    goto v32;

v32:
    v293 = stack[-5];
    v293 = qcdr(v293);
    stack[-5] = v293;
    v293 = stack[-5];
    if (v293 == nil) goto v221;
    stack[-2] = stack[-3];
    v293 = stack[-5];
    v293 = qcar(v293);
    stack[-1] = v293;
    stack[0] = stack[-9];
    v293 = sub1(v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    v293 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v293/(16/CELL)));
    v293 = cons(stack[-1], v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    v293 = ncons(v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    v293 = Lrplacd(nil, stack[-2], v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    v293 = stack[-3];
    v293 = qcdr(v293);
    stack[-3] = v293;
    goto v32;

v221:
    v293 = stack[-4];
    goto v94;

v94:
    stack[-1] = v293;
    goto v297;

v216:
    v293 = qvalue(elt(env, 2)); /* nil */
    goto v94;

v50:
    v293 = stack[-10];
    v293 = qcdr(v293);
    stack[-4] = v293;
    v293 = stack[-4];
    if (v293 == nil) goto v206;
    v293 = stack[-4];
    v293 = qcar(v293);
    stack[0] = stack[-9];
    v293 = sub1(v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    v293 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v293/(16/CELL)));
    v293 = ncons(v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    stack[-2] = v293;
    stack[-3] = v293;
    goto v108;

v108:
    v293 = stack[-4];
    v293 = qcdr(v293);
    stack[-4] = v293;
    v293 = stack[-4];
    if (v293 == nil) goto v154;
    stack[-1] = stack[-2];
    v293 = stack[-4];
    v293 = qcar(v293);
    stack[0] = stack[-9];
    v293 = sub1(v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    v293 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v293/(16/CELL)));
    v293 = ncons(v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    v293 = Lrplacd(nil, stack[-1], v293);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-12];
    v293 = stack[-2];
    v293 = qcdr(v293);
    stack[-2] = v293;
    goto v108;

v154:
    v293 = stack[-3];
    goto v107;

v107:
    stack[-11] = v293;
    v295 = stack[-11];
    v294 = (Lisp_Object)17; /* 1 */
    v293 = stack[-10];
    popv(13);
    return list2star(v295, v294, v293);

v206:
    v293 = qvalue(elt(env, 2)); /* nil */
    goto v107;
/* error exit handlers */
v299:
    popv(13);
    return nil;
}



/* Code for ofsf_bestgaussp */

static Lisp_Object CC_ofsf_bestgaussp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v160, v161;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_bestgaussp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v161 = v0;
/* end of prologue */
    v209 = v161;
    v160 = qcar(v209);
    v209 = elt(env, 1); /* failed */
    if (v160 == v209) goto v126;
    v209 = v161;
    v160 = qcar(v209);
    v209 = elt(env, 2); /* gignore */
    if (v160 == v209) goto v113;
    v209 = v161;
    v209 = qcar(v209);
    v209 = qcdr(v209);
    v160 = qcar(v209);
    v209 = elt(env, 3); /* lin */
    if (v160 == v209) goto v185;
    v209 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v209);

v185:
    v209 = v161;
    v209 = qcar(v209);
    v209 = qcdr(v209);
    v209 = qcdr(v209);
    v160 = qcar(v209);
    v209 = elt(env, 4); /* con */
    if (v160 == v209) goto v150;
    v209 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v209);

v150:
    v209 = v161;
    v209 = qcdr(v209);
    v209 = qcar(v209);
    v209 = qcdr(v209);
    if (v209 == nil) goto v100;
    v209 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v209);

v100:
    v209 = v161;
    v209 = qcdr(v209);
    v209 = qcar(v209);
    v209 = qcar(v209);
    v209 = qcdr(v209);
    v209 = qcdr(v209);
    v209 = (v209 == nil ? lisp_true : nil);
    return onevalue(v209);

v113:
    v209 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v209);

v126:
    v209 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v209);
}



/* Code for merge_lists */

static Lisp_Object CC_merge_lists(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for merge_lists");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v80;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = nil;
    stack[-3] = nil;
    stack[-1] = nil;
    v239 = (Lisp_Object)17; /* 1 */
    stack[0] = v239;
    v239 = stack[-5];
    v239 = Lreverse(nil, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    stack[-5] = v239;
    v239 = stack[-5];
    if (v239 == nil) goto v121;
    v239 = stack[-5];
    v239 = qcar(v239);
    stack[-6] = v239;
    goto v120;

v120:
    v239 = stack[-4];
    if (v239 == nil) goto v121;
    v239 = stack[-4];
    v239 = qcar(v239);
    stack[-2] = v239;
    v24 = stack[-6];
    v239 = stack[-2];
    v239 = (Lisp_Object)lessp2(v24, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    v239 = v239 ? lisp_true : nil;
    env = stack[-7];
    if (!(v239 == nil)) goto v121;
    v24 = stack[-2];
    v239 = stack[-3];
    v239 = cons(v24, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    stack[-3] = v239;
    v239 = stack[-1];
    v239 = (v239 == nil ? lisp_true : nil);
    stack[-1] = v239;
    v239 = stack[-4];
    v239 = qcdr(v239);
    stack[-4] = v239;
    goto v120;

v121:
    v239 = stack[-5];
    if (v239 == nil) goto v157;
    v239 = stack[-3];
    if (v239 == nil) goto v95;
    v239 = stack[-3];
    v239 = qcar(v239);
    stack[-2] = v239;
    v24 = stack[-6];
    v239 = stack[-2];
    if (equal(v24, v239)) goto v137;
    v239 = qvalue(elt(env, 1)); /* nil */
    goto v62;

v62:
    if (v239 == nil) goto v70;
    v239 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v239); }

v70:
    v24 = stack[-6];
    v239 = stack[-2];
    v239 = (Lisp_Object)greaterp2(v24, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    v239 = v239 ? lisp_true : nil;
    env = stack[-7];
    if (v239 == nil) goto v167;
    v24 = stack[-6];
    v239 = stack[-4];
    v239 = cons(v24, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    stack[-4] = v239;
    v239 = stack[-5];
    v239 = qcdr(v239);
    stack[-5] = v239;
    v239 = stack[-1];
    if (v239 == nil) goto v193;
    v24 = stack[-6];
    v239 = (Lisp_Object)1; /* 0 */
    v239 = (Lisp_Object)greaterp2(v24, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    v239 = v239 ? lisp_true : nil;
    env = stack[-7];
    if (v239 == nil) goto v193;
    v239 = stack[0];
    v239 = negate(v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    stack[0] = v239;
    goto v193;

v193:
    v239 = stack[-5];
    if (v239 == nil) goto v121;
    v239 = stack[-5];
    v239 = qcar(v239);
    stack[-6] = v239;
    goto v121;

v167:
    v24 = stack[-2];
    v239 = stack[-4];
    v239 = cons(v24, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-7];
    stack[-4] = v239;
    v239 = stack[-3];
    v239 = qcdr(v239);
    stack[-3] = v239;
    v239 = stack[-1];
    v239 = (v239 == nil ? lisp_true : nil);
    stack[-1] = v239;
    goto v121;

v137:
    v24 = stack[-6];
    v239 = (Lisp_Object)1; /* 0 */
    v239 = (Lisp_Object)greaterp2(v24, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    v239 = v239 ? lisp_true : nil;
    env = stack[-7];
    goto v62;

v95:
    v24 = stack[-5];
    v239 = stack[-4];
    fn = elt(env, 2); /* reversip2 */
    v239 = (*qfn2(fn))(qenv(fn), v24, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    {
        Lisp_Object v18 = stack[0];
        popv(8);
        return cons(v18, v239);
    }

v157:
    v24 = stack[-3];
    v239 = stack[-4];
    fn = elt(env, 2); /* reversip2 */
    v239 = (*qfn2(fn))(qenv(fn), v24, v239);
    nil = C_nil;
    if (exception_pending()) goto v241;
    {
        Lisp_Object v242 = stack[0];
        popv(8);
        return cons(v242, v239);
    }
/* error exit handlers */
v241:
    popv(8);
    return nil;
}



/* Code for replace!-nth */

static Lisp_Object MS_CDECL CC_replaceKnth(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v11, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace-nth");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace-nth");
#endif
    if (stack >= stacklimit)
    {
        push3(v11,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v80,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v80;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v121;

v121:
    v58 = stack[-1];
    v39 = (Lisp_Object)17; /* 1 */
    if (v58 == v39) goto v44;
    v39 = stack[-2];
    v58 = qcar(v39);
    v39 = stack[-3];
    v39 = cons(v58, v39);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    stack[-3] = v39;
    v39 = stack[-2];
    v39 = qcdr(v39);
    stack[-2] = v39;
    v39 = stack[-1];
    v39 = sub1(v39);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    stack[-1] = v39;
    goto v121;

v44:
    stack[-1] = stack[-3];
    v58 = stack[0];
    v39 = stack[-2];
    v39 = qcdr(v39);
    v39 = cons(v58, v39);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    {
        Lisp_Object v100 = stack[-1];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v100, v39);
    }
/* error exit handlers */
v55:
    popv(5);
    return nil;
}



/* Code for get!*nr!*real!*irred!*reps */

static Lisp_Object CC_getHnrHrealHirredHreps(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*nr*real*irred*reps");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v121 = v0;
/* end of prologue */
    v122 = elt(env, 1); /* realrepnumber */
    return get(v121, v122);
}



/* Code for mri_ofsf2mriat */

static Lisp_Object CC_mri_ofsf2mriat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v138, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_ofsf2mriat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v104 = v80;
    v138 = v0;
/* end of prologue */
    v142 = v138;
    v142 = qcar(v142);
    v138 = qcdr(v138);
    v138 = qcar(v138);
    {
        fn = elt(env, 1); /* mri_0mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v142, v138, v104);
    }
}



/* Code for aex_red */

static Lisp_Object CC_aex_red(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v108, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_red");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v107 = v80;
    stack[0] = v0;
/* end of prologue */
    v108 = stack[0];
    fn = elt(env, 2); /* aex_mvaroccurtest */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    if (v107 == nil) goto v145;
    v107 = stack[0];
    fn = elt(env, 3); /* aex_ex */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_red */
    stack[-1] = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v107 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v105 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v108 = qvalue(elt(env, 1)); /* nil */
    v107 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v206 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v206, v105, v108, v107);
    }

v145:
    {
        popv(3);
        fn = elt(env, 7); /* aex_0 */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for operator_fn */

static Lisp_Object CC_operator_fn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for operator_fn");
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
    v56 = stack[0];
    v55 = qcar(v56);
    v56 = elt(env, 1); /* ((arcsinh . sinh) (arcsech . sech) (arccosh . cosh) (arccsch csch) (arctanh . tanh) (arccoth . coth)) 
*/
    v56 = Latsoc(nil, v55, v56);
    stack[-1] = v56;
    v56 = stack[-1];
    if (v56 == nil) goto v233;
    v56 = elt(env, 2); /* "<apply><inverse/>" */
    fn = elt(env, 8); /* printout */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v56 = stack[-1];
    v56 = qcdr(v56);
    v56 = Lprinc(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    goto v107;

v107:
    v55 = qvalue(elt(env, 6)); /* indent */
    v56 = (Lisp_Object)49; /* 3 */
    v56 = plus2(v55, v56);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    qvalue(elt(env, 6)) = v56; /* indent */
    v56 = stack[0];
    v56 = qcdr(v56);
    fn = elt(env, 9); /* multi_args */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v55 = qvalue(elt(env, 6)); /* indent */
    v56 = (Lisp_Object)49; /* 3 */
    v56 = difference2(v55, v56);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    qvalue(elt(env, 6)) = v56; /* indent */
    v56 = elt(env, 7); /* "</apply>" */
    fn = elt(env, 8); /* printout */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v56 = nil;
    { popv(3); return onevalue(v56); }

v233:
    v56 = elt(env, 4); /* "<apply><fn><ci>" */
    fn = elt(env, 8); /* printout */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v56 = stack[0];
    v56 = qcar(v56);
    v56 = Lprinc(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v56 = elt(env, 5); /* "</ci></fn>" */
    v56 = Lprinc(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    goto v107;
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for mkratnum */

static Lisp_Object CC_mkratnum(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v154, v135;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkratnum");
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
    v135 = v0;
/* end of prologue */
    v235 = v135;
    if (!consp(v235)) goto v52;
    v235 = v135;
    v154 = qcar(v235);
    v235 = elt(env, 2); /* !:gi!: */
    if (v154 == v235) goto v107;
    v235 = v135;
    v154 = qcar(v235);
    v235 = elt(env, 1); /* !:rn!: */
    v235 = get(v154, v235);
    v154 = v135;
        return Lapply1(nil, v235, v154);

v107:
    v154 = elt(env, 2); /* !:gi!: */
    v235 = elt(env, 3); /* !:crn!: */
    v235 = get(v154, v235);
    v154 = v135;
        return Lapply1(nil, v235, v154);

v52:
    v154 = elt(env, 1); /* !:rn!: */
    v235 = (Lisp_Object)17; /* 1 */
    return list2star(v154, v135, v235);
}



/* Code for tp */

static Lisp_Object CC_tp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tp");
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
    v7 = v0;
/* end of prologue */
    fn = elt(env, 1); /* matsm */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* tp1 */
        return (*qfn1(fn))(qenv(fn), v7);
    }
/* error exit handlers */
v98:
    popv(1);
    return nil;
}



/* Code for fs!:subang */

static Lisp_Object MS_CDECL CC_fsTsubang(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v11, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v239, v24, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fs:subang");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:subang");
#endif
    if (stack >= stacklimit)
    {
        push3(v11,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v80,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v11;
    stack[-6] = v80;
    stack[-7] = v0;
/* end of prologue */
    v23 = stack[-7];
    if (v23 == nil) goto v98;
    v23 = (Lisp_Object)113; /* 7 */
    v23 = Lmkvect(nil, v23);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-8] = v23;
    v239 = stack[-7];
    v23 = (Lisp_Object)33; /* 2 */
    v239 = *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v23/(16/CELL)));
    v23 = stack[-6];
    v23 = *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v23/(16/CELL)));
    stack[-4] = v23;
    v23 = (Lisp_Object)1; /* 0 */
    stack[-3] = v23;
    goto v185;

v185:
    v239 = (Lisp_Object)113; /* 7 */
    v23 = stack[-3];
    v23 = difference2(v239, v23);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v23 = Lminusp(nil, v23);
    env = stack[-9];
    if (v23 == nil) goto v55;
    v239 = stack[-7];
    v23 = (Lisp_Object)49; /* 3 */
    v24 = *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v23/(16/CELL)));
    v239 = stack[-6];
    v23 = stack[-5];
    stack[0] = CC_fsTsubang(env, 3, v24, v239, v23);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v239 = stack[-7];
    v23 = (Lisp_Object)17; /* 1 */
    v109 = *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v23/(16/CELL)));
    v24 = stack[-8];
    v239 = stack[-7];
    v23 = (Lisp_Object)1; /* 0 */
    v23 = *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v23/(16/CELL)));
    fn = elt(env, 2); /* make!-term */
    v23 = (*qfnn(fn))(qenv(fn), 3, v109, v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    {
        Lisp_Object v111 = stack[0];
        popv(10);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v111, v23);
    }

v55:
    v239 = stack[-3];
    v23 = stack[-6];
    if (equal(v239, v23)) goto v135;
    stack[-2] = stack[-8];
    stack[-1] = stack[-3];
    v239 = stack[-7];
    v23 = (Lisp_Object)33; /* 2 */
    v239 = *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v23/(16/CELL)));
    v23 = stack[-3];
    stack[0] = *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v23/(16/CELL)));
    v24 = stack[-4];
    v239 = stack[-5];
    v23 = stack[-3];
    v23 = *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v23/(16/CELL)));
    v23 = times2(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v23 = plus2(stack[0], v23);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v23;
    goto v163;

v163:
    v23 = stack[-3];
    v23 = add1(v23);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-3] = v23;
    goto v185;

v135:
    stack[-1] = stack[-8];
    stack[0] = stack[-3];
    v24 = stack[-4];
    v239 = stack[-5];
    v23 = stack[-3];
    v23 = *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v23/(16/CELL)));
    v23 = times2(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v23;
    goto v163;

v98:
    v23 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v23); }
/* error exit handlers */
v312:
    popv(10);
    return nil;
}



/* Code for split!-further */

static Lisp_Object MS_CDECL CC_splitKfurther(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v11, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201, v223, v224, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "split-further");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split-further");
#endif
    if (stack >= stacklimit)
    {
        push3(v11,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v80,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v11;
    stack[-2] = v80;
    stack[-3] = v0;
/* end of prologue */
    v201 = stack[-3];
    if (v201 == nil) goto v98;
    v201 = stack[-3];
    v224 = qcdr(v201);
    v223 = stack[-2];
    v201 = stack[-1];
    v201 = CC_splitKfurther(env, 3, v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[-4] = v201;
    v201 = stack[-4];
    v201 = qcdr(v201);
    stack[0] = v201;
    v201 = stack[-4];
    v201 = qcar(v201);
    stack[-4] = v201;
    v223 = qvalue(elt(env, 2)); /* number!-needed */
    v201 = (Lisp_Object)1; /* 0 */
    if (v223 == v201) goto v212;
    v224 = stack[-2];
    v223 = stack[-1];
    v201 = qvalue(elt(env, 3)); /* work!-vector1 */
    fn = elt(env, 8); /* copy!-vector */
    v201 = (*qfnn(fn))(qenv(fn), 3, v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    qvalue(elt(env, 4)) = v201; /* dwork1 */
    v201 = stack[-3];
    v201 = qcar(v201);
    v224 = qcar(v201);
    v201 = stack[-3];
    v201 = qcar(v201);
    v223 = qcdr(v201);
    v201 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 8); /* copy!-vector */
    v201 = (*qfnn(fn))(qenv(fn), 3, v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    qvalue(elt(env, 6)) = v201; /* dwork2 */
    v173 = qvalue(elt(env, 3)); /* work!-vector1 */
    v224 = qvalue(elt(env, 4)); /* dwork1 */
    v223 = qvalue(elt(env, 5)); /* work!-vector2 */
    v201 = qvalue(elt(env, 6)); /* dwork2 */
    fn = elt(env, 9); /* gcd!-in!-vector */
    v201 = (*qfnn(fn))(qenv(fn), 4, v173, v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    qvalue(elt(env, 4)) = v201; /* dwork1 */
    v223 = qvalue(elt(env, 4)); /* dwork1 */
    v201 = (Lisp_Object)1; /* 0 */
    if (v223 == v201) goto v59;
    v223 = qvalue(elt(env, 4)); /* dwork1 */
    v201 = stack[-3];
    v201 = qcar(v201);
    v201 = qcdr(v201);
    v201 = (equal(v223, v201) ? lisp_true : nil);
    goto v95;

v95:
    if (!(v201 == nil)) goto v212;
    v201 = stack[-3];
    v201 = qcar(v201);
    v224 = qcar(v201);
    v201 = stack[-3];
    v201 = qcar(v201);
    v223 = qcdr(v201);
    v201 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 8); /* copy!-vector */
    v201 = (*qfnn(fn))(qenv(fn), 3, v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    qvalue(elt(env, 6)) = v201; /* dwork2 */
    v173 = qvalue(elt(env, 5)); /* work!-vector2 */
    v224 = qvalue(elt(env, 6)); /* dwork2 */
    v223 = qvalue(elt(env, 3)); /* work!-vector1 */
    v201 = qvalue(elt(env, 4)); /* dwork1 */
    fn = elt(env, 10); /* quotfail!-in!-vector */
    v201 = (*qfnn(fn))(qenv(fn), 4, v173, v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    qvalue(elt(env, 6)) = v201; /* dwork2 */
    v201 = qvalue(elt(env, 4)); /* dwork1 */
    v201 = Lmkvect(nil, v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[-1] = v201;
    v224 = qvalue(elt(env, 3)); /* work!-vector1 */
    v223 = qvalue(elt(env, 4)); /* dwork1 */
    v201 = stack[-1];
    fn = elt(env, 8); /* copy!-vector */
    v201 = (*qfnn(fn))(qenv(fn), 3, v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v224 = stack[-1];
    v223 = qvalue(elt(env, 4)); /* dwork1 */
    v201 = stack[-4];
    v201 = acons(v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[-4] = v201;
    stack[-2] = qvalue(elt(env, 5)); /* work!-vector2 */
    stack[-1] = qvalue(elt(env, 6)); /* dwork2 */
    v201 = qvalue(elt(env, 6)); /* dwork2 */
    v201 = Lmkvect(nil, v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[-3] = v201;
    fn = elt(env, 8); /* copy!-vector */
    v201 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v224 = stack[-3];
    v223 = qvalue(elt(env, 6)); /* dwork2 */
    v201 = stack[0];
    v201 = acons(v224, v223, v201);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[0] = v201;
    v201 = qvalue(elt(env, 2)); /* number!-needed */
    v201 = (Lisp_Object)((int32_t)(v201) - 0x10);
    qvalue(elt(env, 2)) = v201; /* number!-needed */
    v223 = stack[-4];
    v201 = stack[0];
    popv(6);
    return cons(v223, v201);

v212:
    v224 = stack[-4];
    v201 = stack[-3];
    v223 = qcar(v201);
    v201 = stack[0];
    popv(6);
    return list2star(v224, v223, v201);

v59:
    v201 = qvalue(elt(env, 7)); /* t */
    goto v95;

v98:
    v201 = qvalue(elt(env, 1)); /* nil */
    popv(6);
    return ncons(v201);
/* error exit handlers */
v198:
    popv(6);
    return nil;
}



/* Code for zfactor1 */

static Lisp_Object CC_zfactor1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v211, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zfactor1");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v80;
    stack[-4] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v121;

v121:
    v211 = stack[-4];
    v76 = (Lisp_Object)1; /* 0 */
    v76 = (Lisp_Object)lessp2(v211, v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    v76 = v76 ? lisp_true : nil;
    env = stack[-6];
    if (v76 == nil) goto v107;
    v212 = (Lisp_Object)-15; /* -1 */
    v211 = (Lisp_Object)17; /* 1 */
    v76 = stack[0];
    v76 = acons(v212, v211, v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-6];
    stack[0] = v76;
    v76 = stack[-4];
    v76 = negate(v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-6];
    stack[-4] = v76;
    goto v121;

v107:
    v211 = stack[-4];
    v76 = (Lisp_Object)65; /* 4 */
    v76 = (Lisp_Object)lessp2(v211, v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    v76 = v76 ? lisp_true : nil;
    env = stack[-6];
    if (v76 == nil) goto v235;
    v211 = stack[-4];
    v76 = (Lisp_Object)17; /* 1 */
    v76 = cons(v211, v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-6];
    v76 = ncons(v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-6];
    {
        Lisp_Object v202 = stack[0];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v202, v76);
    }

v235:
    stack[-5] = stack[0];
    v76 = qvalue(elt(env, 1)); /* !*primelist!* */
    stack[-2] = v76;
    v76 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v76;
    goto v64;

v64:
    v76 = stack[-2];
    if (v76 == nil) goto v315;
    v76 = stack[-2];
    v76 = qcar(v76);
    stack[0] = v76;
    v76 = stack[-2];
    v76 = qcdr(v76);
    stack[-2] = v76;
    goto v63;

v63:
    v211 = stack[-4];
    v76 = stack[0];
    v76 = Ldivide(nil, v211, v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-6];
    v212 = v76;
    v211 = qcdr(v76);
    v76 = (Lisp_Object)1; /* 0 */
    if (v211 == v76) goto v95;
    v211 = stack[-4];
    v76 = (Lisp_Object)17; /* 1 */
    if (v211 == v76) goto v291;
    v211 = stack[0];
    v76 = stack[0];
    v211 = times2(v211, v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-6];
    v76 = stack[-4];
    v76 = (Lisp_Object)greaterp2(v211, v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    v76 = v76 ? lisp_true : nil;
    env = stack[-6];
    goto v16;

v16:
    if (v76 == nil) goto v64;
    v76 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v76;
    v211 = stack[-4];
    v76 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v76 = (*qfn2(fn))(qenv(fn), v211, v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-6];
    stack[-1] = v76;
    v76 = (Lisp_Object)17; /* 1 */
    stack[-4] = v76;
    goto v64;

v291:
    v76 = qvalue(elt(env, 2)); /* nil */
    goto v16;

v95:
    v76 = v212;
    v76 = qcar(v76);
    stack[-4] = v76;
    v211 = stack[0];
    v76 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v76 = (*qfn2(fn))(qenv(fn), v211, v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-6];
    stack[-1] = v76;
    goto v63;

v315:
    v211 = stack[-4];
    v76 = (Lisp_Object)17; /* 1 */
    if (v211 == v76) goto v314;
    v76 = stack[-3];
    if (v76 == nil) goto v73;
    v211 = stack[-4];
    v76 = stack[-1];
    fn = elt(env, 5); /* mcfactor!* */
    v76 = (*qfn2(fn))(qenv(fn), v211, v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-6];
    goto v102;

v102:
    {
        Lisp_Object v213 = stack[-5];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v213, v76);
    }

v73:
    v212 = stack[-4];
    v211 = (Lisp_Object)17; /* 1 */
    v76 = stack[-1];
    v76 = acons(v212, v211, v76);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-6];
    goto v102;

v314:
    v76 = stack[-1];
    goto v102;
/* error exit handlers */
v79:
    popv(7);
    return nil;
}



/* Code for janettreeinsert */

static Lisp_Object CC_janettreeinsert(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v320, v321, v322;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for janettreeinsert");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0;
/* end of prologue */
    v321 = stack[-7];
    v320 = (Lisp_Object)17; /* 1 */
    v320 = *(Lisp_Object *)((char *)v321 + (CELL-TAG_VECTOR) + ((int32_t)v320/(16/CELL)));
    v320 = qcar(v320);
    stack[-3] = v320;
    v321 = stack[-3];
    v320 = (Lisp_Object)1; /* 0 */
    v320 = *(Lisp_Object *)((char *)v321 + (CELL-TAG_VECTOR) + ((int32_t)v320/(16/CELL)));
    stack[-6] = v320;
    v320 = (Lisp_Object)17; /* 1 */
    stack[-8] = v320;
    v320 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    if (v320 == nil) goto v107;
    v320 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    stack[-5] = v320;
    goto v100;

v100:
    v321 = stack[-6];
    v320 = (Lisp_Object)1; /* 0 */
    v320 = (Lisp_Object)greaterp2(v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    v320 = v320 ? lisp_true : nil;
    env = stack[-9];
    if (!(v320 == nil)) goto v41;

v116:
    v320 = nil;
    { popv(10); return onevalue(v320); }

v41:
    v320 = stack[-5];
    if (v320 == nil) goto v99;
    v320 = stack[-5];
    v320 = qcar(v320);
    stack[0] = qcar(v320);
    v321 = stack[-3];
    v320 = stack[-8];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v320 = (*qfn2(fn))(qenv(fn), v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    v320 = (Lisp_Object)lessp2(stack[0], v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    v320 = v320 ? lisp_true : nil;
    env = stack[-9];
    if (v320 == nil) goto v99;
    v320 = stack[-5];
    v320 = qcdr(v320);
    v320 = qcar(v320);
    if (v320 == nil) goto v99;
    v320 = stack[-5];
    v320 = qcdr(v320);
    v320 = qcar(v320);
    stack[-5] = v320;
    goto v41;

v99:
    v320 = stack[-5];
    if (v320 == nil) goto v143;
    v320 = stack[-5];
    v320 = qcar(v320);
    stack[0] = qcar(v320);
    v321 = stack[-3];
    v320 = stack[-8];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v320 = (*qfn2(fn))(qenv(fn), v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    v320 = (Lisp_Object)greaterp2(stack[0], v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    v320 = v320 ? lisp_true : nil;
    env = stack[-9];
    if (v320 == nil) goto v143;
    v322 = stack[-6];
    v321 = stack[-8];
    v320 = stack[-7];
    fn = elt(env, 4); /* janettreenodebuild */
    v320 = (*qfnn(fn))(qenv(fn), 3, v322, v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    stack[-4] = v320;
    v320 = (Lisp_Object)1; /* 0 */
    stack[-6] = v320;
    v320 = stack[-5];
    stack[-2] = qcdr(v320);
    v320 = stack[-5];
    v320 = qcar(v320);
    stack[-1] = qcar(v320);
    v320 = stack[-5];
    v320 = qcar(v320);
    stack[0] = qcdr(v320);
    v320 = stack[-5];
    v320 = qcdr(v320);
    v321 = qcar(v320);
    v320 = stack[-5];
    v320 = qcdr(v320);
    v320 = qcdr(v320);
    v320 = cons(v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    v320 = acons(stack[-1], stack[0], v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    fn = elt(env, 5); /* setcar */
    v320 = (*qfn2(fn))(qenv(fn), stack[-2], v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    v320 = stack[-5];
    v321 = qcdr(v320);
    v320 = stack[-4];
    v320 = qcdr(v320);
    v320 = qcdr(v320);
    fn = elt(env, 6); /* setcdr */
    v320 = (*qfn2(fn))(qenv(fn), v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    v320 = stack[-5];
    v321 = qcar(v320);
    v320 = stack[-4];
    v320 = qcar(v320);
    v320 = qcar(v320);
    fn = elt(env, 5); /* setcar */
    v320 = (*qfn2(fn))(qenv(fn), v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    v320 = stack[-5];
    v321 = qcar(v320);
    v320 = stack[-4];
    v320 = qcar(v320);
    v320 = qcdr(v320);
    fn = elt(env, 6); /* setcdr */
    v320 = (*qfn2(fn))(qenv(fn), v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    goto v100;

v143:
    v320 = stack[-5];
    if (v320 == nil) goto v22;
    v320 = stack[-5];
    v320 = qcar(v320);
    stack[0] = qcar(v320);
    v321 = stack[-3];
    v320 = stack[-8];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v320 = (*qfn2(fn))(qenv(fn), v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    if (equal(stack[0], v320)) goto v201;
    v320 = qvalue(elt(env, 2)); /* nil */
    goto v214;

v214:
    if (v320 == nil) goto v22;
    stack[0] = stack[-6];
    v321 = stack[-3];
    v320 = stack[-8];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v320 = (*qfn2(fn))(qenv(fn), v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    v320 = difference2(stack[0], v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    stack[-6] = v320;
    v320 = stack[-8];
    v320 = add1(v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    stack[-8] = v320;
    v320 = stack[-5];
    v320 = qcdr(v320);
    v320 = qcdr(v320);
    stack[-5] = v320;
    goto v100;

v22:
    v320 = stack[-5];
    if (v320 == nil) goto v100;
    v320 = stack[-5];
    stack[0] = qcdr(v320);
    v322 = stack[-6];
    v321 = stack[-8];
    v320 = stack[-7];
    fn = elt(env, 4); /* janettreenodebuild */
    v320 = (*qfnn(fn))(qenv(fn), 3, v322, v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    fn = elt(env, 5); /* setcar */
    v320 = (*qfn2(fn))(qenv(fn), stack[0], v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    v320 = (Lisp_Object)1; /* 0 */
    stack[-6] = v320;
    goto v100;

v201:
    v320 = stack[-5];
    v320 = qcdr(v320);
    v320 = qcdr(v320);
    goto v214;

v107:
    v322 = stack[-6];
    v321 = stack[-8];
    v320 = stack[-7];
    fn = elt(env, 4); /* janettreenodebuild */
    v320 = (*qfnn(fn))(qenv(fn), 3, v322, v321, v320);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-9];
    qvalue(elt(env, 1)) = v320; /* fluidbibasisjanettreerootnode */
    goto v116;
/* error exit handlers */
v323:
    popv(10);
    return nil;
}



/* Code for subdf */

static Lisp_Object MS_CDECL CC_subdf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v11, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v144, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subdf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subdf");
#endif
    if (stack >= stacklimit)
    {
        push3(v11,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v80,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v11;
    stack[-3] = v80;
    stack[-4] = v0;
/* end of prologue */

v325:
    v208 = stack[-4];
    if (v208 == nil) goto v98;
    v208 = stack[-4];
    v208 = qcar(v208);
    v208 = qcdr(v208);
    stack[0] = qcar(v208);
    v144 = stack[-2];
    v208 = stack[-3];
    v208 = cons(v144, v208);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v208 = ncons(v208);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* subf */
    v208 = (*qfn2(fn))(qenv(fn), stack[0], v208);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 3); /* subs2q */
    v208 = (*qfn1(fn))(qenv(fn), v208);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-5] = v208;
    stack[0] = stack[-5];
    v144 = qvalue(elt(env, 1)); /* nil */
    v208 = (Lisp_Object)17; /* 1 */
    v208 = cons(v144, v208);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    if (equal(stack[0], v208)) goto v40;
    v208 = stack[-4];
    v208 = qcar(v208);
    stack[-1] = qcar(v208);
    v208 = stack[-5];
    stack[0] = qcar(v208);
    v208 = stack[-5];
    v144 = qcdr(v208);
    v208 = stack[-4];
    v208 = qcar(v208);
    v208 = qcdr(v208);
    v208 = qcdr(v208);
    fn = elt(env, 4); /* !*multf */
    v208 = (*qfn2(fn))(qenv(fn), v144, v208);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v208 = list2star(stack[-1], stack[0], v208);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[0] = ncons(v208);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v208 = stack[-4];
    v149 = qcdr(v208);
    v144 = stack[-3];
    v208 = stack[-2];
    v208 = CC_subdf(env, 3, v149, v144, v208);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    {
        Lisp_Object v33 = stack[0];
        popv(7);
        fn = elt(env, 5); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v33, v208);
    }

v40:
    v208 = stack[-4];
    v149 = qcdr(v208);
    v144 = stack[-3];
    v208 = stack[-2];
    stack[-4] = v149;
    stack[-3] = v144;
    stack[-2] = v208;
    goto v325;

v98:
    v208 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v208); }
/* error exit handlers */
v35:
    popv(7);
    return nil;
}



/* Code for tendstoml */

static Lisp_Object CC_tendstoml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tendstoml");
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
    v116 = elt(env, 1); /* "<apply><tendsto" */
    fn = elt(env, 6); /* printout */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v116 = stack[0];
    v152 = qcar(v116);
    v116 = elt(env, 2); /* "/" */
    fn = elt(env, 7); /* attributesml */
    v116 = (*qfn2(fn))(qenv(fn), v152, v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v116 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 8); /* indent!* */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v116 = stack[0];
    v116 = qcdr(v116);
    v116 = qcar(v116);
    fn = elt(env, 9); /* expression */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v116 = stack[0];
    v116 = qcdr(v116);
    v116 = qcdr(v116);
    v116 = qcar(v116);
    fn = elt(env, 9); /* expression */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v116 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v116 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v116 = nil;
    { popv(2); return onevalue(v116); }
/* error exit handlers */
v118:
    popv(2);
    return nil;
}



/* Code for parseml */

static Lisp_Object MS_CDECL CC_parseml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "parseml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for parseml");
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
    v41 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v41;
    v42 = elt(env, 2); /* !! */
    v41 = (Lisp_Object)513; /* 32 */
    v41 = list2(v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    v41 = Lcompress(nil, v41);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    qvalue(elt(env, 3)) = v41; /* space */
    v41 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 4)) = v41; /* count */
    v41 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    qvalue(elt(env, 5)) = v41; /* ch */
    v41 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 6)) = v41; /* temp2 */
    fn = elt(env, 12); /* lex */
    v41 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    v42 = qvalue(elt(env, 7)); /* char */
    v41 = elt(env, 8); /* (m a t h) */
    if (equal(v42, v41)) goto v234;
    v42 = elt(env, 9); /* "<math>" */
    v41 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 13); /* errorml */
    v41 = (*qfn2(fn))(qenv(fn), v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    goto v50;

v50:
    fn = elt(env, 12); /* lex */
    v41 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    v42 = qvalue(elt(env, 7)); /* char */
    v41 = elt(env, 10); /* (!/ m a t h) */
    if (equal(v42, v41)) goto v151;
    v42 = elt(env, 11); /* "</math>" */
    v41 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 13); /* errorml */
    v41 = (*qfn2(fn))(qenv(fn), v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    goto v185;

v185:
    v41 = stack[0];
    {
        popv(2);
        fn = elt(env, 14); /* aeval */
        return (*qfn1(fn))(qenv(fn), v41);
    }

v151:
    v41 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    goto v185;

v234:
    fn = elt(env, 15); /* mathml */
    v41 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    stack[0] = v41;
    goto v50;
/* error exit handlers */
v148:
    popv(2);
    return nil;
}



/* Code for getvariables */

static Lisp_Object CC_getvariables(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getvariables");
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
    v44 = v0;
/* end of prologue */
    v142 = v44;
    stack[0] = qcar(v142);
    v142 = v44;
    v44 = qcdr(v142);
    v142 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* varsinsf */
    v142 = (*qfn2(fn))(qenv(fn), v44, v142);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-1];
    {
        Lisp_Object v117 = stack[0];
        popv(2);
        fn = elt(env, 2); /* varsinsf */
        return (*qfn2(fn))(qenv(fn), v117, v142);
    }
/* error exit handlers */
v234:
    popv(2);
    return nil;
}



/* Code for subscriptedvarp2 */

static Lisp_Object CC_subscriptedvarp2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subscriptedvarp2");
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
    v142 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* symtabget */
    v138 = (*qfn2(fn))(qenv(fn), v142, v138);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[0];
    v142 = Llength(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v44;
    v138 = (Lisp_Object)33; /* 2 */
        popv(1);
        return Lgreaterp(nil, v142, v138);
/* error exit handlers */
v44:
    popv(1);
    return nil;
}



/* Code for evalgeq */

static Lisp_Object CC_evalgeq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v80)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalgeq");
#endif
    if (stack >= stacklimit)
    {
        push2(v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v122 = v80;
    v121 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evalgreaterp */
    v121 = (*qfn2(fn))(qenv(fn), v122, v121);
    errexit();
    v121 = (v121 == nil ? lisp_true : nil);
    return onevalue(v121);
}



/* Code for f2dip2 */

static Lisp_Object MS_CDECL CC_f2dip2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v80,
                         Lisp_Object v11, Lisp_Object v4,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v226, v209, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "f2dip2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip2");
#endif
    if (stack >= stacklimit)
    {
        push5(v10,v4,v11,v80,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v80,v11,v4,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v4;
    stack[-2] = v11;
    stack[-3] = v80;
    stack[-4] = v0;
/* end of prologue */
    v226 = stack[-4];
    v186 = qvalue(elt(env, 1)); /* dipvars!* */
    v186 = Lmemq(nil, v226, v186);
    if (v186 == nil) goto v145;
    v160 = stack[-1];
    v209 = stack[-4];
    v226 = stack[-3];
    v186 = qvalue(elt(env, 1)); /* dipvars!* */
    fn = elt(env, 3); /* evinsert */
    v186 = (*qfnn(fn))(qenv(fn), 4, v160, v209, v226, v186);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    goto v87;

v87:
    v226 = v186;
    v186 = v226;
    if (v186 == nil) goto v147;
    v186 = v226;
    stack[-1] = v186;
    goto v57;

v57:
    v209 = stack[-2];
    v226 = stack[-1];
    v186 = stack[0];
    {
        popv(6);
        fn = elt(env, 4); /* f2dip1 */
        return (*qfnn(fn))(qenv(fn), 3, v209, v226, v186);
    }

v147:
    v209 = stack[-4];
    v226 = stack[-3];
    v186 = (Lisp_Object)17; /* 1 */
    v209 = acons(v209, v226, v186);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    v226 = qvalue(elt(env, 2)); /* nil */
    v186 = (Lisp_Object)17; /* 1 */
    v186 = acons(v209, v226, v186);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    fn = elt(env, 5); /* multsq */
    v186 = (*qfn2(fn))(qenv(fn), stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    stack[0] = v186;
    goto v57;

v145:
    v186 = qvalue(elt(env, 2)); /* nil */
    goto v87;
/* error exit handlers */
v95:
    popv(6);
    return nil;
}



setup_type const u40_setup[] =
{
    {"simpdf",                  CC_simpdf,      too_many_1,    wrong_no_1},
    {"findoptrow",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_findoptrow},
    {"mkunarywedge",            CC_mkunarywedge,too_many_1,    wrong_no_1},
    {"all_defined_map_",        too_few_2,      CC_all_defined_map_,wrong_no_2},
    {"groeb=testb",             too_few_2,      CC_groebMtestb,wrong_no_2},
    {"dummy_nam",               CC_dummy_nam,   too_many_1,    wrong_no_1},
    {"mk+inner+product",        too_few_2,      CC_mkLinnerLproduct,wrong_no_2},
    {"freeof-df",               too_few_2,      CC_freeofKdf,  wrong_no_2},
    {"mri_irsplit1",            CC_mri_irsplit1,too_many_1,    wrong_no_1},
    {"pasf_cein",               CC_pasf_cein,   too_many_1,    wrong_no_1},
    {"ctx_union",               too_few_2,      CC_ctx_union,  wrong_no_2},
    {"numir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_numir},
    {"i2crn*",                  CC_i2crnH,      too_many_1,    wrong_no_1},
    {"solvealgtrig01",          too_few_2,      CC_solvealgtrig01,wrong_no_2},
    {"add_item",                too_few_2,      CC_add_item,   wrong_no_2},
    {"gbftimes",                too_few_2,      CC_gbftimes,   wrong_no_2},
    {"kernelp",                 CC_kernelp,     too_many_1,    wrong_no_1},
    {"diff_vertex",             too_few_2,      CC_diff_vertex,wrong_no_2},
    {"setmatelem",              too_few_2,      CC_setmatelem, wrong_no_2},
    {"rfirst",                  CC_rfirst,      too_many_1,    wrong_no_1},
    {"bc_from_a",               CC_bc_from_a,   too_many_1,    wrong_no_1},
    {"st_sorttree1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree1},
    {"ofsf_bestgaussp",         CC_ofsf_bestgaussp,too_many_1, wrong_no_1},
    {"merge_lists",             too_few_2,      CC_merge_lists,wrong_no_2},
    {"replace-nth",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_replaceKnth},
    {"get*nr*real*irred*reps",  CC_getHnrHrealHirredHreps,too_many_1,wrong_no_1},
    {"mri_ofsf2mriat",          too_few_2,      CC_mri_ofsf2mriat,wrong_no_2},
    {"aex_red",                 too_few_2,      CC_aex_red,    wrong_no_2},
    {"operator_fn",             CC_operator_fn, too_many_1,    wrong_no_1},
    {"mkratnum",                CC_mkratnum,    too_many_1,    wrong_no_1},
    {"tp",                      CC_tp,          too_many_1,    wrong_no_1},
    {"fs:subang",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTsubang},
    {"split-further",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitKfurther},
    {"zfactor1",                too_few_2,      CC_zfactor1,   wrong_no_2},
    {"janettreeinsert",         CC_janettreeinsert,too_many_1, wrong_no_1},
    {"subdf",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_subdf},
    {"tendstoml",               CC_tendstoml,   too_many_1,    wrong_no_1},
    {"parseml",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_parseml},
    {"getvariables",            CC_getvariables,too_many_1,    wrong_no_1},
    {"subscriptedvarp2",        CC_subscriptedvarp2,too_many_1,wrong_no_1},
    {"evalgeq",                 too_few_2,      CC_evalgeq,    wrong_no_2},
    {"f2dip2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_f2dip2},
    {NULL, (one_args *)"u40", (two_args *)"7149 2523522 1774135", 0}
};

/* end of generated code */
