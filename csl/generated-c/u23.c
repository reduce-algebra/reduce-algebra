
/* $destdir\u23.c        Machine generated C code */

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


/* Code for procstat1 */

static Lisp_Object CC_procstat1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for procstat1");
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
    stack[-4] = nil;
    stack[0] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    v56 = qvalue(elt(env, 1)); /* erfg!* */
    stack[-6] = v56;
    v56 = qvalue(elt(env, 2)); /* fname!* */
    if (v56 == nil) goto v59;
    v56 = qvalue(elt(env, 3)); /* t */
    stack[-6] = v56;
    goto v60;

v60:
    v58 = elt(env, 21); /* (symerr (quote procedure) t) */
    v57 = qvalue(elt(env, 9)); /* nil */
    v56 = qvalue(elt(env, 10)); /* !*backtrace */
    fn = elt(env, 22); /* errorset */
    v56 = (*qfnn(fn))(qenv(fn), 3, v58, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    goto v62;

v62:
    v57 = qvalue(elt(env, 18)); /* eof!* */
    v56 = (Lisp_Object)1; /* 0 */
    v56 = (Lisp_Object)greaterp2(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v56 = v56 ? lisp_true : nil;
    env = stack[-7];
    if (v56 == nil) goto v63;
    v56 = elt(env, 19); /* !*semicol!* */
    qvalue(elt(env, 4)) = v56; /* cursym!* */
    goto v64;

v64:
    v56 = qvalue(elt(env, 2)); /* fname!* */
    v57 = ncons(v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    v56 = elt(env, 17); /* fnc */
    v56 = Lremflag(nil, v57, v56);
    env = stack[-7];
    v56 = qvalue(elt(env, 9)); /* nil */
    qvalue(elt(env, 2)) = v56; /* fname!* */
    v56 = qvalue(elt(env, 1)); /* erfg!* */
    if (v56 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v56 = qvalue(elt(env, 9)); /* nil */
    stack[-2] = v56;
    v56 = stack[-6];
    if (!(v56 == nil)) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v56 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }

v63:
    v58 = elt(env, 20); /* (xread t) */
    v57 = qvalue(elt(env, 9)); /* nil */
    v56 = qvalue(elt(env, 10)); /* !*backtrace */
    fn = elt(env, 22); /* errorset */
    v56 = (*qfnn(fn))(qenv(fn), 3, v58, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    stack[-2] = v56;
    v56 = stack[-2];
    if (!consp(v56)) goto v65;
    v56 = stack[-2];
    v56 = qcdr(v56);
    goto v66;

v66:
    if (!(v56 == nil)) goto v67;
    v56 = stack[-2];
    v56 = qcar(v56);
    stack[-2] = v56;
    goto v67;

v67:
    v56 = qvalue(elt(env, 1)); /* erfg!* */
    if (!(v56 == nil)) goto v64;
    stack[-1] = elt(env, 5); /* procedure */
    v56 = qvalue(elt(env, 7)); /* !*reduce4 */
    if (v56 == nil) goto v68;
    v56 = qvalue(elt(env, 2)); /* fname!* */
    stack[0] = v56;
    goto v69;

v69:
    v58 = stack[-4];
    v57 = stack[-3];
    v56 = stack[-2];
    v56 = list3(v58, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    v56 = list3star(stack[-1], stack[0], stack[-5], v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    stack[-2] = v56;
    goto v64;

v68:
    v56 = stack[0];
    v56 = qcar(v56);
    stack[0] = v56;
    goto v69;

v65:
    v56 = qvalue(elt(env, 3)); /* t */
    goto v66;

v59:
    v57 = qvalue(elt(env, 4)); /* cursym!* */
    v56 = elt(env, 5); /* procedure */
    if (v57 == v56) goto v70;
    v56 = qvalue(elt(env, 4)); /* cursym!* */
    stack[-4] = v56;
    fn = elt(env, 23); /* scan */
    v56 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    goto v71;

v71:
    v57 = qvalue(elt(env, 4)); /* cursym!* */
    v56 = elt(env, 5); /* procedure */
    if (!(v57 == v56)) goto v60;
    v56 = qvalue(elt(env, 7)); /* !*reduce4 */
    if (v56 == nil) goto v72;
    fn = elt(env, 23); /* scan */
    v56 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    qvalue(elt(env, 2)) = v56; /* fname!* */
    v56 = qvalue(elt(env, 2)); /* fname!* */
    if (symbolp(v56)) goto v73;
    v57 = qvalue(elt(env, 2)); /* fname!* */
    v56 = elt(env, 14); /* "procedure name" */
    fn = elt(env, 24); /* typerr */
    v56 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    goto v62;

v73:
    fn = elt(env, 23); /* scan */
    v56 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    stack[-1] = elt(env, 15); /* read_param_list */
    v56 = stack[-5];
    v56 = Lmkquote(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    v58 = list2(stack[-1], v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    v57 = qvalue(elt(env, 9)); /* nil */
    v56 = qvalue(elt(env, 10)); /* !*backtrace */
    fn = elt(env, 22); /* errorset */
    v56 = (*qfnn(fn))(qenv(fn), 3, v58, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    stack[-3] = v56;
    v56 = stack[-3];
    if (!consp(v56)) goto v74;
    v56 = stack[-3];
    v56 = qcdr(v56);
    goto v75;

v75:
    if (!(v56 == nil)) goto v62;
    v56 = stack[-3];
    v56 = qcar(v56);
    stack[-3] = v56;
    v57 = qvalue(elt(env, 4)); /* cursym!* */
    v56 = elt(env, 16); /* !*colon!* */
    if (!(v57 == v56)) goto v76;
    fn = elt(env, 25); /* read_type */
    v56 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    stack[-5] = v56;
    goto v76;

v76:
    v56 = qvalue(elt(env, 2)); /* fname!* */
    if (!(symbolp(v56))) goto v62;
    v56 = qvalue(elt(env, 2)); /* fname!* */
    fn = elt(env, 26); /* getd */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    if (!(v56 == nil)) goto v62;
    v56 = qvalue(elt(env, 2)); /* fname!* */
    v57 = ncons(v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    v56 = elt(env, 17); /* fnc */
    v56 = Lflag(nil, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    goto v62;

v74:
    v56 = qvalue(elt(env, 3)); /* t */
    goto v75;

v72:
    v58 = elt(env, 8); /* (xread (quote proc)) */
    v57 = qvalue(elt(env, 9)); /* nil */
    v56 = qvalue(elt(env, 10)); /* !*backtrace */
    fn = elt(env, 22); /* errorset */
    v56 = (*qfnn(fn))(qenv(fn), 3, v58, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    stack[0] = v56;
    v56 = stack[0];
    if (!consp(v56)) goto v77;
    v56 = stack[0];
    v56 = qcdr(v56);
    goto v78;

v78:
    if (!(v56 == nil)) goto v62;
    v56 = stack[0];
    v56 = qcar(v56);
    stack[0] = v56;
    if (!(!consp(v56))) goto v79;
    v56 = stack[0];
    v56 = ncons(v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    stack[0] = v56;
    goto v79;

v79:
    v56 = stack[0];
    v56 = qcar(v56);
    qvalue(elt(env, 2)) = v56; /* fname!* */
    v56 = qvalue(elt(env, 2)); /* fname!* */
    if (!(symbolp(v56))) goto v80;
    v56 = qvalue(elt(env, 2)); /* fname!* */
    if (v56 == nil) goto v81;
    v56 = qvalue(elt(env, 2)); /* fname!* */
    fn = elt(env, 27); /* gettype */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    stack[-2] = v56;
    if (v56 == nil) goto v82;
    v57 = stack[-2];
    v56 = elt(env, 11); /* (procedure operator) */
    v56 = Lmemq(nil, v57, v56);
    v56 = (v56 == nil ? lisp_true : nil);
    goto v83;

v83:
    if (v56 == nil) goto v80;
    v57 = stack[-2];
    v56 = qvalue(elt(env, 2)); /* fname!* */
    v57 = list2(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    v56 = elt(env, 12); /* "procedure" */
    fn = elt(env, 24); /* typerr */
    v56 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    goto v62;

v80:
    v56 = stack[0];
    v56 = qcdr(v56);
    stack[-3] = v56;
    v56 = stack[-3];
    fn = elt(env, 28); /* idlistp */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    if (v56 == nil) goto v84;
    v56 = stack[0];
    v57 = qcar(v56);
    v56 = stack[-3];
    v56 = cons(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    stack[0] = v56;
    goto v76;

v84:
    v57 = stack[-3];
    v56 = elt(env, 13); /* "invalid as parameter list" */
    v56 = list2(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    fn = elt(env, 29); /* lprie */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-7];
    goto v76;

v82:
    v56 = qvalue(elt(env, 9)); /* nil */
    goto v83;

v81:
    v56 = qvalue(elt(env, 3)); /* t */
    goto v83;

v77:
    v56 = qvalue(elt(env, 3)); /* t */
    goto v78;

v70:
    v56 = elt(env, 6); /* expr */
    stack[-4] = v56;
    goto v71;
/* error exit handlers */
v61:
    popv(8);
    return nil;
}



/* Code for cl_nnf */

static Lisp_Object CC_cl_nnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_nnf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v87 = v0;
/* end of prologue */
    v76 = v87;
    v87 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* cl_nnf1 */
        return (*qfn2(fn))(qenv(fn), v76, v87);
    }
}



/* Code for encodeir */

static Lisp_Object CC_encodeir(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for encodeir");
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
    stack[-1] = qvalue(elt(env, 1)); /* char */
    v98 = elt(env, 2); /* !  */
    v97 = qvalue(elt(env, 3)); /* atts */
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    v97 = Lappend(nil, stack[-1], v97);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    v98 = elt(env, 4); /* !$ */
    fn = elt(env, 7); /* delall */
    v97 = (*qfn2(fn))(qenv(fn), v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    stack[-1] = elt(env, 5); /* semantic */
    v99 = stack[0];
    v98 = v97;
    v97 = qvalue(elt(env, 6)); /* nil */
    v97 = list2star(v99, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    v98 = qvalue(elt(env, 6)); /* nil */
    {
        Lisp_Object v101 = stack[-1];
        popv(3);
        return list2star(v101, v97, v98);
    }
/* error exit handlers */
v100:
    popv(3);
    return nil;
}



/* Code for module */

static Lisp_Object CC_module(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for module");
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
    v102 = v0;
/* end of prologue */
    v103 = qvalue(elt(env, 1)); /* !*mode */
    v102 = qvalue(elt(env, 2)); /* mode!-list!* */
    v102 = cons(v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[0];
    qvalue(elt(env, 2)) = v102; /* mode!-list!* */
    v102 = qvalue(elt(env, 3)); /* nil */
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[0];
    qvalue(elt(env, 4)) = v102; /* alglist!* */
    v102 = elt(env, 5); /* symbolic */
    qvalue(elt(env, 1)) = v102; /* !*mode */
    v102 = nil;
    { popv(1); return onevalue(v102); }
/* error exit handlers */
v104:
    popv(1);
    return nil;
}



/* Code for permp */

static Lisp_Object CC_permp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v72, v100, v101;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for permp");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v72 = v105;
    v100 = v0;
/* end of prologue */

v17:
    v107 = v100;
    if (v107 == nil) goto v85;
    v107 = v100;
    v101 = qcar(v107);
    v107 = v72;
    v107 = qcar(v107);
    if (equal(v101, v107)) goto v94;
    v107 = v100;
    stack[0] = qcdr(v107);
    v107 = v72;
    v107 = qcar(v107);
    v100 = qcar(v100);
    v72 = qcdr(v72);
    v107 = Lsubst(nil, 3, v107, v100, v72);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v107 = CC_permp(env, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v107 = (v107 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v107); }

v94:
    v107 = v100;
    v107 = qcdr(v107);
    v100 = v107;
    v107 = v72;
    v107 = qcdr(v107);
    v72 = v107;
    goto v17;

v85:
    v107 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v107); }
/* error exit handlers */
v108:
    popv(2);
    return nil;
}



/* Code for assert_kernelp */

static Lisp_Object CC_assert_kernelp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112, v51;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_kernelp");
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
    v112 = v0;
/* end of prologue */
    v111 = v112;
    if (symbolp(v111)) goto v4;
    v111 = v112;
    v111 = Lconsp(nil, v111);
    env = stack[0];
    if (v111 == nil) goto v113;
    v111 = v112;
    v51 = qcar(v111);
    v111 = elt(env, 3); /* fkernfn */
    v111 = get(v51, v111);
    env = stack[0];
    if (v111 == nil) goto v96;
    v111 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v111); }

v96:
    v111 = v112;
    v111 = qcar(v111);
    if (!consp(v111)) goto v114;
    v111 = qvalue(elt(env, 5)); /* exlist!* */
    goto v72;

v72:
    v111 = Latsoc(nil, v112, v111);
    { popv(1); return onevalue(v111); }

v114:
    v111 = v112;
    v51 = qcar(v111);
    v111 = elt(env, 4); /* klist */
    v111 = get(v51, v111);
    goto v72;

v113:
    v111 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v111); }

v4:
    v111 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v111); }
}



/* Code for sf2mv */

static Lisp_Object CC_sf2mv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v102, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2mv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v115 = v105;
    v102 = v0;
/* end of prologue */
    v103 = v102;
    v102 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* sf2mv1 */
        return (*qfnn(fn))(qenv(fn), 3, v103, v102, v115);
    }
}



/* Code for lastcar */

static Lisp_Object CC_lastcar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lastcar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v116 = v0;
/* end of prologue */

v16:
    v70 = v116;
    if (v70 == nil) goto v4;
    v70 = v116;
    v70 = qcdr(v70);
    if (v70 == nil) goto v76;
    v116 = qcdr(v116);
    goto v16;

v76:
    v116 = qcar(v116);
    return onevalue(v116);

v4:
    v116 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v116);
}



/* Code for reduce!-mod!-p!* */

static Lisp_Object CC_reduceKmodKpH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-p*");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v4 = v105;
    v85 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* current!-modulus */
    qvalue(elt(env, 1)) = v4; /* current!-modulus */
    v4 = v85;
    fn = elt(env, 2); /* general!-reduce!-mod!-p */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* current!-modulus */
    { popv(2); return onevalue(v4); }
/* error exit handlers */
v87:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* current!-modulus */
    popv(2);
    return nil;
}



/* Code for ifstat */

static Lisp_Object MS_CDECL CC_ifstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ifstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ifstat");
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
    stack[-1] = nil;
    goto v85;

v85:
    fn = elt(env, 10); /* scan */
    v132 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v132 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (v132 == nil) goto v76;
    v133 = qvalue(elt(env, 2)); /* cursym!* */
    v132 = elt(env, 3); /* !*semicol!* */
    if (v133 == v132) goto v85;
    else goto v76;

v76:
    v132 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 11); /* xread1 */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    stack[0] = v132;
    v133 = qvalue(elt(env, 2)); /* cursym!* */
    v132 = elt(env, 5); /* then */
    if (v133 == v132) goto v50;
    v133 = elt(env, 6); /* if */
    v132 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 12); /* symerr */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    goto v50;

v50:
    fn = elt(env, 10); /* scan */
    v132 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v132 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (v132 == nil) goto v134;
    v133 = qvalue(elt(env, 2)); /* cursym!* */
    v132 = elt(env, 3); /* !*semicol!* */
    if (v133 == v132) goto v50;
    else goto v134;

v134:
    v132 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 11); /* xread1 */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v132 = list2(stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v132 = ncons(v132);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v132 = Lnconc(nil, stack[-1], v132);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    stack[-1] = v132;
    v133 = qvalue(elt(env, 2)); /* cursym!* */
    v132 = elt(env, 7); /* else */
    if (!(v133 == v132)) goto v135;
    fn = elt(env, 10); /* scan */
    v133 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v132 = elt(env, 6); /* if */
    if (v133 == v132) goto v85;
    stack[0] = qvalue(elt(env, 4)); /* t */
    v132 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 11); /* xread1 */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v132 = list2(stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v132 = ncons(v132);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v132 = Lnconc(nil, stack[-1], v132);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    stack[-1] = v132;
    goto v135;

v135:
    v133 = elt(env, 9); /* cond */
    v132 = stack[-1];
    popv(3);
    return cons(v133, v132);
/* error exit handlers */
v41:
    popv(3);
    return nil;
}



/* Code for ofsf_varlat */

static Lisp_Object CC_ofsf_varlat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_varlat");
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
    v136 = v0;
/* end of prologue */
    v136 = qcdr(v136);
    v137 = qcar(v136);
    v136 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    v137 = v136;
    v136 = qvalue(elt(env, 2)); /* !*rlbrkcxk */
    if (v136 == nil) { popv(5); return onevalue(v137); }
    v136 = v137;
    stack[-3] = v136;
    goto v138;

v138:
    v136 = stack[-3];
    if (v136 == nil) goto v54;
    v136 = stack[-3];
    v136 = qcar(v136);
    fn = elt(env, 4); /* rltools_lpvarl */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    stack[-2] = v136;
    v136 = stack[-2];
    fn = elt(env, 5); /* lastpair */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    stack[-1] = v136;
    v136 = stack[-3];
    v136 = qcdr(v136);
    stack[-3] = v136;
    v136 = stack[-1];
    if (!consp(v136)) goto v138;
    else goto v92;

v92:
    v136 = stack[-3];
    if (v136 == nil) goto v98;
    stack[0] = stack[-1];
    v136 = stack[-3];
    v136 = qcar(v136);
    fn = elt(env, 4); /* rltools_lpvarl */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    v136 = Lrplacd(nil, stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    v136 = stack[-1];
    fn = elt(env, 5); /* lastpair */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    stack[-1] = v136;
    v136 = stack[-3];
    v136 = qcdr(v136);
    stack[-3] = v136;
    goto v92;

v98:
    v136 = stack[-2];
    goto v59;

v59:
    v137 = v136;
    { popv(5); return onevalue(v137); }

v54:
    v136 = qvalue(elt(env, 1)); /* nil */
    goto v59;
/* error exit handlers */
v127:
    popv(5);
    return nil;
}



/* Code for sortedtriplelistinsert */

static Lisp_Object CC_sortedtriplelistinsert(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sortedtriplelistinsert");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v105;
    v145 = v0;
/* end of prologue */
    v144 = stack[-1];
    v143 = (Lisp_Object)17; /* 1 */
    v143 = *(Lisp_Object *)((char *)v144 + (CELL-TAG_VECTOR) + ((int32_t)v143/(16/CELL)));
    v143 = qcar(v143);
    stack[0] = v143;
    v143 = v145;
    stack[-2] = v143;
    goto v96;

v96:
    v143 = stack[-2];
    v143 = qcar(v143);
    if (v143 == nil) goto v50;
    v143 = stack[-2];
    v144 = qcar(v143);
    v143 = (Lisp_Object)17; /* 1 */
    v143 = *(Lisp_Object *)((char *)v144 + (CELL-TAG_VECTOR) + ((int32_t)v143/(16/CELL)));
    v144 = qcar(v143);
    v143 = stack[0];
    fn = elt(env, 2); /* monomcompare */
    v144 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v143 = (Lisp_Object)17; /* 1 */
    if (v144 == v143) goto v50;
    v143 = stack[-2];
    v143 = qcdr(v143);
    stack[-2] = v143;
    goto v96;

v50:
    stack[0] = stack[-2];
    v143 = stack[-2];
    v144 = qcar(v143);
    v143 = stack[-2];
    v143 = qcdr(v143);
    v143 = cons(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v144 = Lrplacd(nil, stack[0], v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v143 = stack[-1];
    v143 = Lrplaca(nil, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    v143 = nil;
    { popv(4); return onevalue(v143); }
/* error exit handlers */
v146:
    popv(4);
    return nil;
}



/* Code for rl_nnf */

static Lisp_Object CC_rl_nnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_nnf");
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
    v76 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_nnf!* */
    v76 = ncons(v76);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-1];
    {
        Lisp_Object v115 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v115, v76);
    }
/* error exit handlers */
v113:
    popv(2);
    return nil;
}



/* Code for wureducedp */

static Lisp_Object CC_wureducedp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wureducedp");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v105;
    stack[-1] = v0;
/* end of prologue */
    v128 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    if (!(v128 == nil)) { popv(3); return onevalue(v128); }
    v128 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    if (!(v128 == nil)) { popv(3); return onevalue(v128); }
    v128 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    if (v128 == nil) goto v141;
    v128 = qvalue(elt(env, 1)); /* nil */
    goto v131;

v131:
    fn = elt(env, 3); /* deginvar */
    v129 = (*qfn2(fn))(qenv(fn), stack[-1], v128);
    nil = C_nil;
    if (exception_pending()) goto v91;
    v128 = stack[0];
    v128 = qcar(v128);
    v128 = qcar(v128);
    v128 = qcdr(v128);
        popv(3);
        return Llessp(nil, v129, v128);

v141:
    v128 = stack[0];
    v128 = qcar(v128);
    v128 = qcar(v128);
    v128 = qcar(v128);
    goto v131;
/* error exit handlers */
v91:
    popv(3);
    return nil;
}



/* Code for klistt */

static Lisp_Object CC_klistt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for klistt");
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
    goto v17;

v17:
    v149 = stack[0];
    if (!consp(v149)) goto v85;
    v149 = stack[0];
    v149 = qcar(v149);
    v130 = qcar(v149);
    v149 = stack[-1];
    v149 = cons(v130, v149);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-2];
    stack[-1] = v149;
    v130 = stack[0];
    v149 = elt(env, 1); /* list */
    fn = elt(env, 2); /* carx */
    v149 = (*qfn2(fn))(qenv(fn), v130, v149);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-2];
    v149 = qcdr(v149);
    stack[0] = v149;
    goto v17;

v85:
    v149 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v149);
    }
/* error exit handlers */
v150:
    popv(3);
    return nil;
}



/* Code for squashsqrt */

static Lisp_Object CC_squashsqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v164, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for squashsqrt");
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

v166:
    v74 = qvalue(elt(env, 1)); /* sqrtflag */
    if (v74 == nil) goto v85;
    v74 = stack[-1];
    if (!consp(v74)) goto v103;
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = (consp(v74) ? nil : lisp_true);
    goto v4;

v4:
    if (!(v74 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcar(v74);
    v164 = qcar(v74);
    v74 = elt(env, 3); /* sqrt */
    if (v164 == v74) goto v53;
    v74 = qvalue(elt(env, 4)); /* nil */
    goto v148;

v148:
    if (v74 == nil) goto v83;
    v74 = stack[-1];
    v74 = qcdr(v74);
    stack[0] = CC_squashsqrt(env, v74);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v165 = qcar(v74);
    v74 = stack[-1];
    v74 = qcar(v74);
    v164 = qcdr(v74);
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcdr(v74);
    fn = elt(env, 6); /* !*multfsqrt */
    v74 = (*qfnn(fn))(qenv(fn), 3, v165, v164, v74);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    {
        Lisp_Object v168 = stack[0];
        popv(4);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v168, v74);
    }

v83:
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcar(v74);
    v164 = qcar(v74);
    v74 = elt(env, 5); /* expt */
    if (v164 == v74) goto v169;
    v74 = qvalue(elt(env, 4)); /* nil */
    goto v124;

v124:
    if (v74 == nil) goto v170;
    v74 = stack[-1];
    v74 = qcdr(v74);
    stack[0] = CC_squashsqrt(env, v74);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v165 = qcar(v74);
    v74 = stack[-1];
    v74 = qcar(v74);
    v164 = qcdr(v74);
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcdr(v74);
    fn = elt(env, 8); /* !*multfexpt */
    v74 = (*qfnn(fn))(qenv(fn), 3, v165, v164, v74);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    {
        Lisp_Object v171 = stack[0];
        popv(4);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v171, v74);
    }

v170:
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v74 = CC_squashsqrt(env, v74);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v164 = v74;
    v74 = v164;
    if (v74 == nil) goto v172;
    v74 = stack[-1];
    v74 = qcar(v74);
    stack[-2] = qcar(v74);
    stack[0] = v164;
    v74 = stack[-1];
    v74 = qcdr(v74);
    v74 = CC_squashsqrt(env, v74);
    nil = C_nil;
    if (exception_pending()) goto v167;
    {
        Lisp_Object v173 = stack[-2];
        Lisp_Object v174 = stack[0];
        popv(4);
        return acons(v173, v174, v74);
    }

v172:
    v74 = stack[-1];
    v74 = qcdr(v74);
    stack[-1] = v74;
    goto v166;

v169:
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    fn = elt(env, 9); /* prefix!-rational!-numberp */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    if (v74 == nil) goto v175;
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v164 = qcdr(v74);
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    v74 = (Lisp_Object)geq2(v164, v74);
    nil = C_nil;
    if (exception_pending()) goto v167;
    v74 = v74 ? lisp_true : nil;
    env = stack[-3];
    goto v124;

v175:
    v74 = qvalue(elt(env, 4)); /* nil */
    goto v124;

v53:
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    v164 = qcdr(v74);
    v74 = (Lisp_Object)17; /* 1 */
    v74 = (Lisp_Object)greaterp2(v164, v74);
    nil = C_nil;
    if (exception_pending()) goto v167;
    v74 = v74 ? lisp_true : nil;
    env = stack[-3];
    goto v148;

v103:
    v74 = qvalue(elt(env, 2)); /* t */
    goto v4;

v85:
    v74 = qvalue(elt(env, 2)); /* t */
    goto v4;
/* error exit handlers */
v167:
    popv(4);
    return nil;
}



/* Code for evallessp */

static Lisp_Object CC_evallessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evallessp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v94 = v105;
    v76 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* evalgreaterp */
        return (*qfn2(fn))(qenv(fn), v94, v76);
    }
}



/* Code for sq2sstm */

static Lisp_Object CC_sq2sstm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v120, v183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sq2sstm");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v105;
    v183 = v0;
/* end of prologue */
    v119 = v183;
    v119 = qcar(v119);
    v120 = qcar(v119);
    v119 = stack[-2];
    v119 = qcar(v119);
    v119 = qcar(v119);
    if (equal(v120, v119)) goto v87;
    v119 = v183;
    stack[-1] = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-4];
    v119 = stack[-2];
    v119 = qcar(v119);
    stack[0] = qcdr(v119);
    v119 = stack[-2];
    v119 = qcdr(v119);
    v119 = sub1(v119);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-4];
    v119 = cons(stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-4];
    fn = elt(env, 2); /* sq2sscfpl */
    v119 = (*qfn2(fn))(qenv(fn), stack[-1], v119);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-4];
    v120 = (Lisp_Object)1; /* 0 */
    stack[-3] = v120;
    goto v82;

v82:
    v120 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* mapins */
        return (*qfn2(fn))(qenv(fn), v120, v119);
    }

v87:
    v119 = v183;
    v119 = qcdr(v119);
    stack[0] = v119;
    v119 = v183;
    v119 = qcar(v119);
    v119 = qcdr(v119);
    stack[-3] = v119;
    v119 = stack[0];
    if (!consp(v119)) goto v149;
    v119 = stack[0];
    v119 = qcar(v119);
    v119 = (consp(v119) ? nil : lisp_true);
    goto v141;

v141:
    if (v119 == nil) goto v51;
    stack[-1] = stack[-3];
    v119 = stack[-2];
    v119 = qcdr(v119);
    fn = elt(env, 4); /* mkzl */
    v120 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-4];
    v119 = stack[0];
    v119 = acons(stack[-1], v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v184;
    popv(5);
    return ncons(v119);

v51:
    stack[-1] = stack[0];
    v119 = stack[-2];
    v119 = qcar(v119);
    stack[0] = qcdr(v119);
    v119 = stack[-2];
    v119 = qcdr(v119);
    v119 = sub1(v119);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-4];
    v119 = cons(stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-4];
    fn = elt(env, 2); /* sq2sscfpl */
    v119 = (*qfn2(fn))(qenv(fn), stack[-1], v119);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-4];
    goto v82;

v149:
    v119 = qvalue(elt(env, 1)); /* t */
    goto v141;
/* error exit handlers */
v184:
    popv(5);
    return nil;
}



/* Code for vdp_plist */

static Lisp_Object CC_vdp_plist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v85;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_plist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v85 = v0;
/* end of prologue */
    v85 = qcdr(v85);
    v85 = qcdr(v85);
    v85 = qcdr(v85);
    v85 = qcdr(v85);
    v85 = qcar(v85);
    return onevalue(v85);
}



/* Code for lambdafun */

static Lisp_Object CC_lambdafun(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambdafun");
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
    v4 = v0;
/* end of prologue */
    v4 = Lreverse(nil, v4);
    errexit();
    v4 = qcar(v4);
    return onevalue(v4);
}



/* Code for recaliasbacksubst */

static Lisp_Object CC_recaliasbacksubst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for recaliasbacksubst");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v105;
    stack[0] = v0;
/* end of prologue */
    v180 = stack[0];
    if (!consp(v180)) goto v86;
    v180 = stack[0];
    fn = elt(env, 3); /* constp */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    goto v85;

v85:
    if (v180 == nil) goto v187;
    v186 = stack[0];
    v180 = stack[-3];
    v180 = Lassoc(nil, v186, v180);
    if (v180 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v186 = stack[0];
    v180 = stack[-3];
    v180 = Lassoc(nil, v186, v180);
    v180 = qcdr(v180);
    { popv(6); return onevalue(v180); }

v187:
    v180 = stack[0];
    stack[-4] = v180;
    v180 = stack[-4];
    if (v180 == nil) goto v107;
    v180 = stack[-4];
    v180 = qcar(v180);
    v186 = v180;
    v180 = stack[-3];
    v180 = CC_recaliasbacksubst(env, v186, v180);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    v180 = ncons(v180);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    stack[-1] = v180;
    stack[-2] = v180;
    goto v90;

v90:
    v180 = stack[-4];
    v180 = qcdr(v180);
    stack[-4] = v180;
    v180 = stack[-4];
    if (v180 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v180 = stack[-4];
    v180 = qcar(v180);
    v186 = v180;
    v180 = stack[-3];
    v180 = CC_recaliasbacksubst(env, v186, v180);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    v180 = ncons(v180);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    v180 = Lrplacd(nil, stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    v180 = stack[-1];
    v180 = qcdr(v180);
    stack[-1] = v180;
    goto v90;

v107:
    v180 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v180); }

v86:
    v180 = qvalue(elt(env, 1)); /* t */
    goto v85;
/* error exit handlers */
v160:
    popv(6);
    return nil;
}



/* Code for ordexp */

static Lisp_Object CC_ordexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98, v99, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v98 = v105;
    v99 = v0;
/* end of prologue */

v17:
    v97 = v99;
    if (v97 == nil) goto v85;
    v97 = v99;
    v107 = qcar(v97);
    v97 = v98;
    v97 = qcar(v97);
    if (v107 == v97) goto v94;
    v97 = v99;
    v97 = qcar(v97);
    if (v97 == nil) goto v93;
    v97 = v98;
    v97 = qcar(v97);
    if (v97 == nil) goto v110;
    v97 = v99;
    v97 = qcar(v97);
    v98 = qcar(v98);
    {
        fn = elt(env, 3); /* ordop */
        return (*qfn2(fn))(qenv(fn), v97, v98);
    }

v110:
    v97 = qvalue(elt(env, 1)); /* t */
    return onevalue(v97);

v93:
    v97 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v97);

v94:
    v97 = v99;
    v97 = qcdr(v97);
    v99 = v97;
    v97 = v98;
    v97 = qcdr(v97);
    v98 = v97;
    goto v17;

v85:
    v97 = qvalue(elt(env, 1)); /* t */
    return onevalue(v97);
}



/* Code for evalb */

static Lisp_Object CC_evalb(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v131, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalb");
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
    v70 = v0;
/* end of prologue */
    v59 = v70;
    v131 = qvalue(elt(env, 1)); /* nil */
    v70 = elt(env, 2); /* algebraic */
    fn = elt(env, 5); /* formbool */
    v70 = (*qfnn(fn))(qenv(fn), 3, v59, v131, v70);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[0];
    fn = elt(env, 6); /* eval */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[0];
    if (v70 == nil) goto v96;
    v70 = elt(env, 3); /* true */
    { popv(1); return onevalue(v70); }

v96:
    v70 = elt(env, 4); /* false */
    { popv(1); return onevalue(v70); }
/* error exit handlers */
v138:
    popv(1);
    return nil;
}



/* Code for sublap */

static Lisp_Object CC_sublap(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sublap");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v105;
    stack[-1] = v0;
/* end of prologue */
    v124 = stack[-1];
    if (v124 == nil) goto v94;
    v124 = stack[0];
    v124 = (v124 == nil ? lisp_true : nil);
    goto v76;

v76:
    if (!(v124 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v124 = stack[0];
    if (!consp(v124)) goto v116;
    v124 = stack[0];
    v169 = qcar(v124);
    v124 = elt(env, 2); /* app */
    v124 = Lflagp(nil, v169, v124);
    env = stack[-3];
    if (v124 == nil) goto v190;
    v169 = stack[-1];
    v124 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* sublap1 */
        return (*qfn2(fn))(qenv(fn), v169, v124);
    }

v190:
    v169 = stack[-1];
    v124 = stack[0];
    v124 = qcar(v124);
    stack[-2] = CC_sublap(env, v169, v124);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-3];
    v169 = stack[-1];
    v124 = stack[0];
    v124 = qcdr(v124);
    v124 = CC_sublap(env, v169, v124);
    nil = C_nil;
    if (exception_pending()) goto v191;
    {
        Lisp_Object v179 = stack[-2];
        popv(4);
        return cons(v179, v124);
    }

v116:
    v124 = stack[0];
    if (is_number(v124)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v169 = stack[0];
    v124 = stack[-1];
    v124 = Latsoc(nil, v169, v124);
    v169 = v124;
    if (v124 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v124 = v169;
    v124 = qcdr(v124);
    { popv(4); return onevalue(v124); }

v94:
    v124 = qvalue(elt(env, 1)); /* t */
    goto v76;
/* error exit handlers */
v191:
    popv(4);
    return nil;
}



/* Code for edge_new_parents */

static Lisp_Object CC_edge_new_parents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v149, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for edge_new_parents");
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
    v130 = v0;
/* end of prologue */
    v141 = v130;
    v149 = qcar(v141);
    v141 = qvalue(elt(env, 1)); /* old_edge_list */
    v141 = Lassoc(nil, v149, v141);
    if (v141 == nil) goto v103;
    v141 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v141); }

v103:
    v141 = v130;
    v141 = qcdr(v141);
    v141 = qcar(v141);
    v149 = v141;
    v149 = qcar(v149);
    v141 = qcdr(v141);
    v141 = list2(v149, v141);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* edge_new_parent */
        return (*qfn1(fn))(qenv(fn), v141);
    }
/* error exit handlers */
v89:
    popv(1);
    return nil;
}



/* Code for no!-side!-effectp */

static Lisp_Object CC_noKsideKeffectp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for no-side-effectp");
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
    v109 = stack[0];
    if (!consp(v109)) goto v16;
    v109 = stack[0];
    v108 = qcar(v109);
    v109 = elt(env, 2); /* quote */
    if (v108 == v109) goto v192;
    v109 = stack[0];
    v108 = qcar(v109);
    v109 = elt(env, 4); /* nosideeffects */
    v109 = Lflagp(nil, v108, v109);
    env = stack[-1];
    if (v109 == nil) goto v72;
    v109 = stack[0];
    v109 = qcdr(v109);
    {
        popv(2);
        fn = elt(env, 5); /* no!-side!-effect!-listp */
        return (*qfn1(fn))(qenv(fn), v109);
    }

v72:
    v109 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v109); }

v192:
    v109 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v109); }

v16:
    v109 = stack[0];
    v109 = (is_number(v109) ? lisp_true : nil);
    if (!(v109 == nil)) { popv(2); return onevalue(v109); }
    v109 = stack[0];
    if (symbolp(v109)) goto v95;
    v109 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v109); }

v95:
    v109 = stack[0];
    v109 = Lsymbol_specialp(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-1];
    if (!(v109 == nil)) goto v116;
    v109 = stack[0];
    v109 = Lsymbol_globalp(nil, v109);
    goto v116;

v116:
    v109 = (v109 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v109); }
/* error exit handlers */
v112:
    popv(2);
    return nil;
}



/* Code for fs!:prin1 */

static Lisp_Object CC_fsTprin1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prin1");
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
    v170 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v170;
    v200 = stack[0];
    v170 = (Lisp_Object)1; /* 0 */
    v200 = *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v170/(16/CELL)));
    v170 = elt(env, 2); /* (1 . 1) */
    if (equal(v200, v170)) goto v86;
    v170 = elt(env, 3); /* "(" */
    fn = elt(env, 12); /* prin2!* */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    v200 = stack[0];
    v170 = (Lisp_Object)1; /* 0 */
    v170 = *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v170/(16/CELL)));
    fn = elt(env, 13); /* sqprint */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    v170 = elt(env, 4); /* ")" */
    fn = elt(env, 12); /* prin2!* */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    goto v86;

v86:
    v170 = stack[0];
    fn = elt(env, 14); /* fs!:null!-angle */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    if (v170 == nil) goto v53;
    v200 = stack[0];
    v170 = (Lisp_Object)1; /* 0 */
    v200 = *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v170/(16/CELL)));
    v170 = elt(env, 2); /* (1 . 1) */
    if (!(equal(v200, v170))) goto v71;
    v170 = elt(env, 11); /* "1" */
    fn = elt(env, 12); /* prin2!* */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    goto v71;

v71:
    v170 = nil;
    { popv(5); return onevalue(v170); }

v53:
    v200 = stack[0];
    v170 = (Lisp_Object)17; /* 1 */
    v170 = *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v170/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    v170 = elt(env, 5); /* "[" */
    fn = elt(env, 12); /* prin2!* */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    v200 = stack[0];
    v170 = (Lisp_Object)33; /* 2 */
    v170 = *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v170/(16/CELL)));
    stack[-2] = v170;
    v170 = (Lisp_Object)1; /* 0 */
    stack[0] = v170;
    goto v140;

v140:
    v200 = (Lisp_Object)113; /* 7 */
    v170 = stack[0];
    v170 = difference2(v200, v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    v170 = Lminusp(nil, v170);
    env = stack[-4];
    if (v170 == nil) goto v44;
    v170 = elt(env, 10); /* "]" */
    fn = elt(env, 12); /* prin2!* */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    goto v71;

v44:
    v200 = stack[-2];
    v170 = stack[0];
    v200 = *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v170/(16/CELL)));
    stack[-1] = v200;
    v170 = (Lisp_Object)1; /* 0 */
    if (v200 == v170) goto v201;
    v200 = stack[-1];
    v170 = (Lisp_Object)1; /* 0 */
    v170 = (Lisp_Object)lessp2(v200, v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    v170 = v170 ? lisp_true : nil;
    env = stack[-4];
    if (v170 == nil) goto v82;
    v170 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v170;
    v170 = elt(env, 7); /* "-" */
    fn = elt(env, 12); /* prin2!* */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    v170 = stack[-1];
    v170 = negate(v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    stack[-1] = v170;
    goto v82;

v82:
    v170 = stack[-3];
    if (!(v170 == nil)) goto v133;
    v170 = elt(env, 8); /* "+" */
    fn = elt(env, 12); /* prin2!* */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    goto v133;

v133:
    v200 = stack[-1];
    v170 = (Lisp_Object)17; /* 1 */
    if (v200 == v170) goto v118;
    v170 = stack[-1];
    fn = elt(env, 12); /* prin2!* */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    goto v118;

v118:
    v170 = qvalue(elt(env, 6)); /* nil */
    stack[-3] = v170;
    v200 = qvalue(elt(env, 9)); /* fourier!-name!* */
    v170 = stack[0];
    v170 = *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v170/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    goto v201;

v201:
    v170 = stack[0];
    v170 = add1(v170);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-4];
    stack[0] = v170;
    goto v140;
/* error exit handlers */
v154:
    popv(5);
    return nil;
}



/* Code for red_tailred */

static Lisp_Object CC_red_tailred(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v141, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_tailred");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v110 = v105;
    v149 = v0;
/* end of prologue */
    v141 = qvalue(elt(env, 1)); /* !*noetherian */
    if (v141 == nil) goto v59;
    v141 = v110;
    v110 = elt(env, 2); /* red_topred */
    {
        fn = elt(env, 4); /* red_tailreddriver */
        return (*qfnn(fn))(qenv(fn), 3, v149, v141, v110);
    }

v59:
    v141 = v110;
    v110 = elt(env, 3); /* red_topredbe */
    {
        fn = elt(env, 4); /* red_tailreddriver */
        return (*qfnn(fn))(qenv(fn), 3, v149, v141, v110);
    }
}



/* Code for !*di2q0 */

static Lisp_Object CC_Hdi2q0(Lisp_Object env,
                         Lisp_Object v105, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v205, v206, v207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *di2q0");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v105);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v105,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v161 = v5;
    stack[-3] = v105;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v161; /* varlist */
    stack[-2] = nil;
    goto v94;

v94:
    v161 = stack[-3];
    if (v161 == nil) goto v46;
    v161 = stack[-3];
    v161 = qcar(v161);
    stack[-1] = qcdr(v161);
    stack[0] = qvalue(elt(env, 1)); /* varlist */
    v205 = qvalue(elt(env, 2)); /* ordering */
    v161 = elt(env, 3); /* lex */
    if (v205 == v161) goto v150;
    v161 = stack[-3];
    fn = elt(env, 5); /* ljet */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-5];
    v161 = qcdr(v161);
    goto v141;

v141:
    fn = elt(env, 6); /* pair */
    v161 = (*qfn2(fn))(qenv(fn), stack[0], v161);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-5];
    v207 = stack[-1];
    stack[-1] = v161;
    goto v112;

v112:
    v161 = stack[-1];
    if (v161 == nil) goto v111;
    v161 = stack[-1];
    v161 = qcar(v161);
    v206 = v161;
    v161 = v206;
    v205 = qcdr(v161);
    v161 = (Lisp_Object)1; /* 0 */
    if (v205 == v161) goto v136;
    stack[0] = v207;
    v205 = v206;
    v161 = (Lisp_Object)17; /* 1 */
    v206 = cons(v205, v161);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-5];
    v205 = qvalue(elt(env, 4)); /* nil */
    v161 = (Lisp_Object)17; /* 1 */
    v161 = acons(v206, v205, v161);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-5];
    fn = elt(env, 7); /* multsq */
    v161 = (*qfn2(fn))(qenv(fn), stack[0], v161);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-5];
    v207 = v161;
    goto v136;

v136:
    v161 = stack[-1];
    v161 = qcdr(v161);
    stack[-1] = v161;
    goto v112;

v111:
    v205 = v207;
    v161 = stack[-2];
    v161 = cons(v205, v161);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-5];
    stack[-2] = v161;
    v161 = stack[-3];
    v161 = qcdr(v161);
    stack[-3] = v161;
    goto v94;

v150:
    v161 = stack[-3];
    fn = elt(env, 5); /* ljet */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-5];
    goto v141;

v46:
    v205 = qvalue(elt(env, 4)); /* nil */
    v161 = (Lisp_Object)17; /* 1 */
    v161 = cons(v205, v161);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-5];
    v205 = v161;
    goto v115;

v115:
    v161 = stack[-2];
    if (v161 == nil) goto v209;
    v161 = stack[-2];
    v161 = qcar(v161);
    fn = elt(env, 8); /* addsq */
    v161 = (*qfn2(fn))(qenv(fn), v161, v205);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-5];
    v205 = v161;
    v161 = stack[-2];
    v161 = qcdr(v161);
    stack[-2] = v161;
    goto v115;

v209:
    v161 = v205;
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    { popv(6); return onevalue(v161); }
/* error exit handlers */
v208:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    popv(6);
    return nil;
}



/* Code for rootextractf */

static Lisp_Object CC_rootextractf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v228, v229, v230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rootextractf");
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
    v228 = stack[-3];
    if (!consp(v228)) goto v85;
    v228 = stack[-3];
    v228 = qcar(v228);
    v228 = (consp(v228) ? nil : lisp_true);
    goto v4;

v4:
    if (!(v228 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v228 = stack[-3];
    v228 = qcar(v228);
    v228 = qcar(v228);
    v228 = qcar(v228);
    stack[-4] = v228;
    v228 = stack[-3];
    v228 = qcar(v228);
    v228 = qcar(v228);
    v228 = qcdr(v228);
    stack[0] = v228;
    v228 = stack[-3];
    v228 = qcdr(v228);
    v228 = CC_rootextractf(env, v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-5];
    stack[-2] = v228;
    v228 = stack[-3];
    v228 = qcar(v228);
    v228 = qcdr(v228);
    v228 = CC_rootextractf(env, v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-5];
    stack[-1] = v228;
    v228 = stack[-1];
    if (v228 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v228 = stack[-4];
    if (!consp(v228)) goto v107;
    v228 = stack[-4];
    v229 = qcar(v228);
    v228 = elt(env, 2); /* sqrt */
    if (v229 == v228) goto v78;
    v228 = stack[-4];
    v229 = qcar(v228);
    v228 = elt(env, 3); /* expt */
    if (v229 == v228) goto v186;
    v228 = qvalue(elt(env, 5)); /* nil */
    goto v48;

v48:
    if (v228 == nil) goto v232;
    v230 = stack[0];
    v228 = stack[-4];
    v229 = qcar(v228);
    v228 = elt(env, 2); /* sqrt */
    if (v229 == v228) goto v39;
    v228 = stack[-4];
    v228 = qcdr(v228);
    v228 = qcdr(v228);
    v228 = qcar(v228);
    v228 = qcdr(v228);
    v228 = qcdr(v228);
    v228 = qcar(v228);
    goto v195;

v195:
    v228 = Ldivide(nil, v230, v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-5];
    stack[0] = v228;
    v228 = stack[0];
    v229 = qcar(v228);
    v228 = (Lisp_Object)1; /* 0 */
    if (v229 == v228) goto v233;
    v228 = stack[-4];
    v228 = qcdr(v228);
    v228 = qcar(v228);
    if (is_number(v228)) goto v234;
    v228 = stack[-4];
    v228 = qcdr(v228);
    v229 = qcar(v228);
    v228 = stack[0];
    v228 = qcar(v228);
    v228 = list2(v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-5];
    fn = elt(env, 6); /* simpexpt */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-5];
    v230 = v228;
    v228 = v230;
    v229 = qcdr(v228);
    v228 = (Lisp_Object)17; /* 1 */
    if (v229 == v228) goto v235;
    v228 = stack[-3];
    v228 = qcar(v228);
    v228 = qcar(v228);
    v228 = qcdr(v228);
    stack[0] = v228;
    goto v232;

v232:
    v229 = stack[0];
    v228 = (Lisp_Object)1; /* 0 */
    if (v229 == v228) goto v236;
    v228 = stack[-1];
    if (v228 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v229 = stack[-4];
    v228 = stack[0];
    v230 = cons(v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    v229 = stack[-1];
    v228 = stack[-2];
    popv(6);
    return acons(v230, v229, v228);

v236:
    v229 = stack[-1];
    v228 = stack[-2];
    {
        popv(6);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v229, v228);
    }

v235:
    v228 = v230;
    v229 = qcar(v228);
    v228 = stack[-1];
    fn = elt(env, 8); /* multf */
    v228 = (*qfn2(fn))(qenv(fn), v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-5];
    stack[-1] = v228;
    v228 = stack[0];
    v228 = qcdr(v228);
    stack[0] = v228;
    goto v232;

v234:
    v228 = stack[-4];
    v228 = qcdr(v228);
    v229 = qcar(v228);
    v228 = stack[0];
    v228 = qcar(v228);
    v229 = Lexpt(nil, v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-5];
    v228 = stack[-1];
    fn = elt(env, 9); /* multd */
    v228 = (*qfn2(fn))(qenv(fn), v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-5];
    stack[-1] = v228;
    v228 = stack[0];
    v228 = qcdr(v228);
    stack[0] = v228;
    goto v232;

v233:
    v228 = stack[-1];
    if (v228 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v228 = stack[-3];
    v228 = qcar(v228);
    v230 = qcar(v228);
    v229 = stack[-1];
    v228 = stack[-2];
    popv(6);
    return acons(v230, v229, v228);

v39:
    v228 = (Lisp_Object)33; /* 2 */
    goto v195;

v186:
    v228 = stack[-4];
    v228 = qcdr(v228);
    v228 = qcdr(v228);
    v229 = qcar(v228);
    v228 = elt(env, 4); /* quotient */
    if (!consp(v229)) goto v198;
    v229 = qcar(v229);
    if (!(v229 == v228)) goto v198;
    v228 = stack[-4];
    v228 = qcdr(v228);
    v228 = qcdr(v228);
    v228 = qcar(v228);
    v228 = qcdr(v228);
    v229 = qcar(v228);
    v228 = (Lisp_Object)17; /* 1 */
    if (v229 == v228) goto v120;
    v228 = qvalue(elt(env, 5)); /* nil */
    goto v48;

v120:
    v228 = stack[-4];
    v228 = qcdr(v228);
    v228 = qcdr(v228);
    v228 = qcar(v228);
    v228 = qcdr(v228);
    v228 = qcdr(v228);
    v228 = qcar(v228);
    v228 = (is_number(v228) ? lisp_true : nil);
    goto v48;

v198:
    v228 = qvalue(elt(env, 5)); /* nil */
    goto v48;

v78:
    v228 = qvalue(elt(env, 1)); /* t */
    goto v48;

v107:
    v228 = stack[-3];
    v228 = qcar(v228);
    v230 = qcar(v228);
    v229 = stack[-1];
    v228 = stack[-2];
    popv(6);
    return acons(v230, v229, v228);

v85:
    v228 = qvalue(elt(env, 1)); /* t */
    goto v4;
/* error exit handlers */
v231:
    popv(6);
    return nil;
}



/* Code for general!-modular!-expt */

static Lisp_Object CC_generalKmodularKexpt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-expt");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v105;
    stack[-1] = v0;
/* end of prologue */

v87:
    v200 = stack[-1];
    v170 = (Lisp_Object)1; /* 0 */
    if (v200 == v170) goto v116;
    v200 = stack[0];
    v170 = (Lisp_Object)1; /* 0 */
    if (v200 == v170) goto v129;
    v200 = stack[0];
    v170 = (Lisp_Object)17; /* 1 */
    if (v200 == v170) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = stack[0];
    v170 = qvalue(elt(env, 4)); /* current!-modulus */
    v170 = sub1(v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    v170 = (Lisp_Object)geq2(stack[-2], v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v170 = v170 ? lisp_true : nil;
    env = stack[-3];
    if (v170 == nil) goto v179;
    v170 = qvalue(elt(env, 4)); /* current!-modulus */
    fn = elt(env, 6); /* primep */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    if (v170 == nil) goto v179;
    v170 = qvalue(elt(env, 4)); /* current!-modulus */
    v170 = sub1(v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    v170 = Cremainder(stack[0], v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[0] = v170;
    goto v87;

v179:
    v170 = stack[0];
    v170 = Levenp(nil, v170);
    env = stack[-3];
    if (v170 == nil) goto v191;
    v200 = stack[0];
    v170 = (Lisp_Object)33; /* 2 */
    v170 = quot2(v200, v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[0] = v170;
    v200 = stack[-1];
    v170 = stack[-1];
    fn = elt(env, 7); /* general!-modular!-times */
    v170 = (*qfn2(fn))(qenv(fn), v200, v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[-1] = v170;
    goto v179;

v191:
    v170 = stack[0];
    fn = elt(env, 8); /* reverse!-num */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[0] = v170;
    v170 = (Lisp_Object)17; /* 1 */
    stack[-2] = v170;
    goto v43;

v43:
    v200 = stack[0];
    v170 = (Lisp_Object)1; /* 0 */
    v170 = (Lisp_Object)greaterp2(v200, v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v170 = v170 ? lisp_true : nil;
    env = stack[-3];
    if (v170 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v200 = stack[-2];
    v170 = stack[-2];
    fn = elt(env, 7); /* general!-modular!-times */
    v170 = (*qfn2(fn))(qenv(fn), v200, v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[-2] = v170;
    v170 = stack[0];
    v170 = Levenp(nil, v170);
    env = stack[-3];
    if (!(v170 == nil)) goto v159;
    v200 = stack[-2];
    v170 = stack[-1];
    fn = elt(env, 7); /* general!-modular!-times */
    v170 = (*qfn2(fn))(qenv(fn), v200, v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[-2] = v170;
    goto v159;

v159:
    v200 = stack[0];
    v170 = (Lisp_Object)33; /* 2 */
    v170 = quot2(v200, v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[0] = v170;
    goto v43;

v129:
    v170 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v170); }

v116:
    v200 = stack[0];
    v170 = (Lisp_Object)1; /* 0 */
    if (v200 == v170) goto v96;
    v170 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v170); }

v96:
    v170 = elt(env, 1); /* "0^0 formed" */
    v200 = v170;
    v170 = v200;
    qvalue(elt(env, 2)) = v170; /* errmsg!* */
    v170 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v170 == nil)) goto v149;
    v170 = v200;
    fn = elt(env, 9); /* lprie */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    goto v149;

v149:
    v170 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v170 = nil;
    { popv(4); return onevalue(v170); }
/* error exit handlers */
v35:
    popv(4);
    return nil;
}



/* Code for gcref_off */

static Lisp_Object MS_CDECL CC_gcref_off(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v240, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "gcref_off");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcref_off");
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
/* end of prologue */
    fn = elt(env, 8); /* gcref_off1 */
    v45 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    v240 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    v45 = qvalue(elt(env, 1)); /* btime!* */
    v45 = difference2(v240, v45);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    v45 = qvalue(elt(env, 2)); /* pfiles!* */
    stack[-4] = v45;
    v45 = stack[-4];
    if (v45 == nil) goto v70;
    v45 = stack[-4];
    v45 = qcar(v45);
    stack[0] = v45;
    v45 = stack[0];
    v82 = qcdr(v45);
    v240 = elt(env, 4); /* cref_name */
    v45 = stack[0];
    v45 = qcar(v45);
    v45 = Lputprop(nil, 3, v82, v240, v45);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    v45 = stack[0];
    v45 = qcdr(v45);
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    stack[-2] = v45;
    stack[-3] = v45;
    goto v95;

v95:
    v45 = stack[-4];
    v45 = qcdr(v45);
    stack[-4] = v45;
    v45 = stack[-4];
    if (v45 == nil) goto v97;
    stack[-1] = stack[-2];
    v45 = stack[-4];
    v45 = qcar(v45);
    stack[0] = v45;
    v45 = stack[0];
    v82 = qcdr(v45);
    v240 = elt(env, 4); /* cref_name */
    v45 = stack[0];
    v45 = qcar(v45);
    v45 = Lputprop(nil, 3, v82, v240, v45);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    v45 = stack[0];
    v45 = qcdr(v45);
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    v45 = Lrplacd(nil, stack[-1], v45);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    v45 = stack[-2];
    v45 = qcdr(v45);
    stack[-2] = v45;
    goto v95;

v97:
    v45 = stack[-3];
    goto v104;

v104:
    qvalue(elt(env, 2)) = v45; /* pfiles!* */
    v45 = qvalue(elt(env, 5)); /* !*gcrefall */
    if (v45 == nil) goto v125;
    v45 = qvalue(elt(env, 6)); /* seen!* */
    fn = elt(env, 9); /* gcref_select */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    fn = elt(env, 10); /* gcref_mkgraph */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    goto v163;

v163:
    v45 = qvalue(elt(env, 7)); /* !*saveprops */
    if (!(v45 == nil)) goto v191;
    fn = elt(env, 11); /* gcref_remprops */
    v45 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v177;
    goto v191;

v191:
    v45 = nil;
    { popv(6); return onevalue(v45); }

v125:
    v45 = qvalue(elt(env, 6)); /* seen!* */
    fn = elt(env, 12); /* gcref_eselect */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    fn = elt(env, 13); /* gcref_mkegraph */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-5];
    goto v163;

v70:
    v45 = qvalue(elt(env, 3)); /* nil */
    goto v104;
/* error exit handlers */
v177:
    popv(6);
    return nil;
}



/* Code for pushback */

static Lisp_Object CC_pushback(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v52;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pushback");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v105;
    v129 = v0;
/* end of prologue */

v86:
    v52 = v129;
    v52 = qcar(v52);
    if (v52 == nil) goto v93;
    v129 = qcdr(v129);
    goto v86;

v93:
    stack[-1] = v129;
    v52 = v129;
    v52 = qcar(v52);
    v129 = qcdr(v129);
    v129 = cons(v52, v129);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    v52 = Lrplacd(nil, stack[-1], v129);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    v129 = stack[0];
    v129 = Lrplaca(nil, v52, v129);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v129 = nil;
    { popv(3); return onevalue(v129); }
/* error exit handlers */
v90:
    popv(3);
    return nil;
}



/* Code for cl_pnf */

static Lisp_Object CC_cl_pnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pnf");
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
    v17 = v0;
/* end of prologue */
    fn = elt(env, 1); /* rl_nnf */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* cl_pnf1 */
        return (*qfn1(fn))(qenv(fn), v17);
    }
/* error exit handlers */
v15:
    popv(1);
    return nil;
}



/* Code for width */

static Lisp_Object CC_width(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v134, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for width");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v105;
    v134 = v0;
/* end of prologue */
    v181 = v134;
    v79 = elt(env, 1); /* textag */
    v79 = get(v181, v79);
    env = stack[-2];
    stack[-1] = v79;
    v79 = stack[-1];
    if (!(v79 == nil)) goto v128;
    v79 = elt(env, 2); /* "cannot find item " */
    v134 = list2(v79, v134);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    v79 = elt(env, 3); /* fatal */
    fn = elt(env, 5); /* tri!-error */
    v79 = (*qfn2(fn))(qenv(fn), v134, v79);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    goto v128;

v128:
    v134 = stack[0];
    v79 = (Lisp_Object)1; /* 0 */
    v79 = (Lisp_Object)greaterp2(v134, v79);
    nil = C_nil;
    if (exception_pending()) goto v77;
    v79 = v79 ? lisp_true : nil;
    env = stack[-2];
    if (v79 == nil) goto v130;
    v79 = stack[-1];
    v79 = qcdr(v79);
    if (v79 == nil) goto v130;
    v79 = stack[-1];
    v79 = qcdr(v79);
    stack[-1] = v79;
    v79 = stack[0];
    v79 = sub1(v79);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    stack[0] = v79;
    goto v128;

v130:
    v79 = stack[-1];
    v79 = qcar(v79);
    if (!(v79 == nil)) { popv(3); return onevalue(v79); }
    v79 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v79); }
/* error exit handlers */
v77:
    popv(3);
    return nil;
}



/* Code for mk!+conjugate!+sq */

static Lisp_Object CC_mkLconjugateLsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+conjugate+sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* conjsq */
        return (*qfn1(fn))(qenv(fn), v15);
    }
}



/* Code for lambdavar */

static Lisp_Object CC_lambdavar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambdavar");
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
    v86 = v0;
/* end of prologue */
    v86 = qcdr(v86);
    v86 = qcdr(v86);
    v86 = Lreverse(nil, v86);
    errexit();
    v86 = qcdr(v86);
    return onevalue(v86);
}



/* Code for dip!-nc!-ev!-prod1 */

static Lisp_Object MS_CDECL CC_dipKncKevKprod1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v105,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v88, v150, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dip-nc-ev-prod1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip-nc-ev-prod1");
#endif
    if (stack >= stacklimit)
    {
        push3(v5,v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v105,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v88 = v5;
    v150 = v105;
    v114 = v0;
/* end of prologue */
    v89 = v114;
    if (v89 == nil) { popv(3); return onevalue(v88); }
    v89 = v114;
    stack[-1] = qcar(v89);
    stack[0] = v150;
    v89 = v114;
    v89 = qcdr(v89);
    v150 = (Lisp_Object)((int32_t)(v150) + 0x10);
    v89 = CC_dipKncKevKprod1(env, 3, v89, v150, v88);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    {
        Lisp_Object v128 = stack[-1];
        Lisp_Object v129 = stack[0];
        popv(3);
        fn = elt(env, 1); /* dip!-nc!-ev!-prod2 */
        return (*qfnn(fn))(qenv(fn), 3, v128, v129, v89);
    }
/* error exit handlers */
v147:
    popv(3);
    return nil;
}



/* Code for overall_factor */

static Lisp_Object CC_overall_factor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for overall_factor");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v105;
    stack[-1] = v0;
/* end of prologue */

v166:
    v89 = stack[0];
    if (v89 == nil) goto v17;
    stack[-2] = stack[-1];
    v89 = stack[0];
    fn = elt(env, 3); /* xval */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-3];
    v89 = Lmemq(nil, stack[-2], v89);
    if (v89 == nil) goto v113;
    v88 = stack[-1];
    v89 = stack[0];
    v89 = qcdr(v89);
    stack[-1] = v88;
    stack[0] = v89;
    goto v166;

v113:
    v89 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v89); }

v17:
    v89 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v89); }
/* error exit handlers */
v187:
    popv(4);
    return nil;
}



/* Code for all_edge */

static Lisp_Object CC_all_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v187, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_edge");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v105;
    stack[-1] = v0;
/* end of prologue */
    v147 = nil;
    goto v15;

v15:
    v71 = stack[0];
    if (v71 == nil) goto v86;
    v187 = stack[-1];
    v71 = stack[0];
    v71 = qcar(v71);
    v71 = qcar(v71);
    if (v187 == v71) goto v92;
    v71 = stack[0];
    v71 = qcdr(v71);
    stack[0] = v71;
    goto v15;

v92:
    v71 = stack[0];
    v71 = qcar(v71);
    v187 = v147;
    v71 = cons(v71, v187);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    v147 = v71;
    v71 = stack[0];
    v71 = qcdr(v71);
    stack[0] = v71;
    goto v15;

v86:
    v71 = v147;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v71);
    }
/* error exit handlers */
v52:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-!> */

static Lisp_Object CC_mvKpowKS(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v71, v187, v147;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow->");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v71 = v105;
    v187 = v0;
/* end of prologue */

v17:
    v114 = v187;
    if (v114 == nil) goto v85;
    v114 = v187;
    v147 = qcar(v114);
    v114 = v71;
    v114 = qcar(v114);
    if (equal(v147, v114)) goto v94;
    v114 = v187;
    v114 = qcar(v114);
    v71 = qcar(v71);
        return Lgreaterp(nil, v114, v71);

v94:
    v114 = v187;
    v114 = qcdr(v114);
    v187 = v114;
    v114 = v71;
    v114 = qcdr(v114);
    v71 = v114;
    goto v17;

v85:
    v114 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v114);
}



/* Code for !*a2k */

static Lisp_Object CC_Ha2k(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *a2k");
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
    v130 = stack[0];
    fn = elt(env, 2); /* simp!* */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    stack[-1] = v130;
    fn = elt(env, 3); /* kernp */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    if (v130 == nil) goto v106;
    v130 = stack[-1];
    v130 = qcar(v130);
    v130 = qcar(v130);
    v130 = qcar(v130);
    v130 = qcar(v130);
    { popv(3); return onevalue(v130); }

v106:
    v130 = stack[0];
    if (v130 == nil) goto v93;
    v130 = stack[0];
    v89 = v130;
    goto v70;

v70:
    v130 = elt(env, 1); /* kernel */
    fn = elt(env, 4); /* typerr */
    v130 = (*qfn2(fn))(qenv(fn), v89, v130);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v130 = nil;
    { popv(3); return onevalue(v130); }

v93:
    v130 = (Lisp_Object)1; /* 0 */
    v89 = v130;
    goto v70;
/* error exit handlers */
v114:
    popv(3);
    return nil;
}



/* Code for copy!-tree */

static Lisp_Object CC_copyKtree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v80, v188, v178;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copy-tree");
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
    v146 = stack[-2];
    if (v146 == nil) goto v16;
    v146 = (Lisp_Object)49; /* 3 */
    v146 = Lmkvect(nil, v146);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    stack[-3] = v146;
    v178 = stack[-3];
    v188 = (Lisp_Object)1; /* 0 */
    v80 = stack[-2];
    v146 = (Lisp_Object)1; /* 0 */
    v146 = *(Lisp_Object *)((char *)v80 + (CELL-TAG_VECTOR) + ((int32_t)v146/(16/CELL)));
    *(Lisp_Object *)((char *)v178 + (CELL-TAG_VECTOR) + ((int32_t)v188/(16/CELL))) = v146;
    v178 = stack[-3];
    v188 = (Lisp_Object)17; /* 1 */
    v80 = stack[-2];
    v146 = (Lisp_Object)17; /* 1 */
    v146 = *(Lisp_Object *)((char *)v80 + (CELL-TAG_VECTOR) + ((int32_t)v146/(16/CELL)));
    *(Lisp_Object *)((char *)v178 + (CELL-TAG_VECTOR) + ((int32_t)v188/(16/CELL))) = v146;
    v178 = stack[-3];
    v188 = (Lisp_Object)33; /* 2 */
    v80 = stack[-2];
    v146 = (Lisp_Object)33; /* 2 */
    v146 = *(Lisp_Object *)((char *)v80 + (CELL-TAG_VECTOR) + ((int32_t)v146/(16/CELL)));
    *(Lisp_Object *)((char *)v178 + (CELL-TAG_VECTOR) + ((int32_t)v188/(16/CELL))) = v146;
    stack[-1] = stack[-3];
    stack[0] = (Lisp_Object)49; /* 3 */
    v80 = stack[-2];
    v146 = (Lisp_Object)49; /* 3 */
    v146 = *(Lisp_Object *)((char *)v80 + (CELL-TAG_VECTOR) + ((int32_t)v146/(16/CELL)));
    v146 = CC_copyKtree(env, v146);
    nil = C_nil;
    if (exception_pending()) goto v83;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v146;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v16:
    v146 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v146); }
/* error exit handlers */
v83:
    popv(5);
    return nil;
}



/* Code for merge */

static Lisp_Object MS_CDECL CC_merge(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v105,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v241, v136;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "merge");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for merge");
#endif
    if (stack >= stacklimit)
    {
        push3(v5,v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v105,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v5;
    stack[-1] = v105;
    stack[-2] = v0;
/* end of prologue */
    v77 = stack[-2];
    if (v77 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v77 = stack[-1];
    if (v77 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v136 = stack[0];
    v77 = stack[-2];
    v241 = qcar(v77);
    v77 = stack[-1];
    v77 = qcar(v77);
    v77 = Lapply2(nil, 3, v136, v241, v77);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    if (v77 == nil) goto v99;
    stack[-3] = stack[-2];
    v77 = stack[-2];
    v136 = qcdr(v77);
    v241 = stack[-1];
    v77 = stack[0];
    v77 = CC_merge(env, 3, v136, v241, v77);
    nil = C_nil;
    if (exception_pending()) goto v126;
    {
        Lisp_Object v127 = stack[-3];
        popv(5);
        return Lrplacd(nil, v127, v77);
    }

v99:
    stack[-3] = stack[-1];
    v136 = stack[-2];
    v77 = stack[-1];
    v241 = qcdr(v77);
    v77 = stack[0];
    v77 = CC_merge(env, 3, v136, v241, v77);
    nil = C_nil;
    if (exception_pending()) goto v126;
    {
        Lisp_Object v139 = stack[-3];
        popv(5);
        return Lrplacd(nil, v139, v77);
    }
/* error exit handlers */
v126:
    popv(5);
    return nil;
}



/* Code for atom_compare */

static Lisp_Object CC_atom_compare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v187, v147;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for atom_compare");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v187 = v105;
    v147 = v0;
/* end of prologue */
    v71 = v147;
    if (is_number(v71)) goto v17;
    v71 = v187;
    if (symbolp(v71)) goto v55;
    v71 = v187;
    v71 = (is_number(v71) ? lisp_true : nil);
    return onevalue(v71);

v55:
    v71 = v147;
        return Lorderp(nil, v71, v187);

v17:
    v71 = v187;
    if (is_number(v71)) goto v104;
    v71 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v71);

v104:
    v71 = v147;
    v71 = (Lisp_Object)lessp2(v71, v187);
    errexit();
    v71 = v71 ? lisp_true : nil;
    v71 = (v71 == nil ? lisp_true : nil);
    return onevalue(v71);
}



/* Code for polynomlistreduce */

static Lisp_Object MS_CDECL CC_polynomlistreduce(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v105,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v184, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "polynomlistreduce");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomlistreduce");
#endif
    if (stack >= stacklimit)
    {
        push3(v5,v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v105,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v5;
    stack[-2] = v105;
    stack[-3] = v0;
/* end of prologue */
    v47 = qvalue(elt(env, 1)); /* nil */
    v47 = ncons(v47);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    stack[-4] = v47;
    v47 = stack[-2];
    v47 = qcar(v47);
    if (v47 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    else goto v106;

v106:
    v47 = stack[-2];
    v47 = qcar(v47);
    if (v47 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v121 = stack[-3];
    v184 = stack[-2];
    v47 = stack[-1];
    fn = elt(env, 2); /* polynomlistfinddivisor */
    v47 = (*qfnn(fn))(qenv(fn), 3, v121, v184, v47);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    goto v187;

v187:
    v184 = v47;
    if (v184 == nil) goto v71;
    v184 = stack[-2];
    fn = elt(env, 3); /* polynomreduceby */
    v47 = (*qfn2(fn))(qenv(fn), v184, v47);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    v121 = stack[-3];
    v184 = stack[-2];
    v47 = stack[-1];
    fn = elt(env, 2); /* polynomlistfinddivisor */
    v47 = (*qfnn(fn))(qenv(fn), 3, v121, v184, v47);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    goto v187;

v71:
    v47 = stack[-2];
    v47 = qcar(v47);
    if (v47 == nil) goto v106;
    stack[0] = stack[-4];
    v47 = stack[-2];
    v121 = qcar(v47);
    v184 = qvalue(elt(env, 1)); /* nil */
    v47 = qvalue(elt(env, 1)); /* nil */
    v47 = list2star(v121, v184, v47);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    fn = elt(env, 4); /* polynomadd */
    v47 = (*qfn2(fn))(qenv(fn), stack[0], v47);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    v184 = stack[-2];
    v47 = stack[-2];
    v47 = qcdr(v47);
    v47 = qcar(v47);
    v184 = Lrplaca(nil, v184, v47);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    v47 = stack[-2];
    v47 = qcdr(v47);
    v47 = qcdr(v47);
    v47 = Lrplacd(nil, v184, v47);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    goto v106;
/* error exit handlers */
v209:
    popv(6);
    return nil;
}



/* Code for get!-free!-form */

static Lisp_Object CC_getKfreeKform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v139, v143;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-free-form");
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
    v139 = stack[-1];
    v127 = qvalue(elt(env, 1)); /* frasc!* */
    v127 = Latsoc(nil, v139, v127);
    stack[0] = v127;
    if (v127 == nil) goto v138;
    v127 = stack[0];
    v127 = qcdr(v127);
    { popv(4); return onevalue(v127); }

v138:
    v139 = stack[-1];
    v127 = elt(env, 2); /* !~ */
    if (!consp(v139)) goto v88;
    v139 = qcar(v139);
    if (!(v139 == v127)) goto v88;
    v127 = stack[-1];
    v127 = qcdr(v127);
    v127 = qcar(v127);
    stack[-1] = v127;
    v127 = elt(env, 3); /* (!! !~ !! !~) */
    stack[0] = v127;
    v127 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v127;
    goto v52;

v52:
    v127 = stack[-1];
    v127 = Lexplode(nil, v127);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-3];
    v127 = Lappend(nil, stack[0], v127);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-3];
    v127 = Lcompress(nil, v127);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-3];
    v127 = Lintern(nil, v127);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-3];
    stack[0] = v127;
    v143 = stack[-1];
    v139 = stack[0];
    v127 = qvalue(elt(env, 1)); /* frasc!* */
    v127 = acons(v143, v139, v127);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-3];
    qvalue(elt(env, 1)) = v127; /* frasc!* */
    v127 = stack[-2];
    if (v127 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v127 = stack[0];
    v139 = ncons(v127);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-3];
    v127 = elt(env, 6); /* optional */
    v127 = Lflag(nil, v139, v127);
    nil = C_nil;
    if (exception_pending()) goto v185;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v88:
    v127 = elt(env, 5); /* (!! !~) */
    stack[0] = v127;
    goto v52;
/* error exit handlers */
v185:
    popv(4);
    return nil;
}



/* Code for qqe_ofsf_simpat */

static Lisp_Object CC_qqe_ofsf_simpat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_simpat");
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
    v148 = stack[0];
    fn = elt(env, 2); /* qqe_arg2l */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    fn = elt(env, 3); /* qqe_ofsf_chsimpterm */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    v148 = stack[0];
    fn = elt(env, 4); /* qqe_arg2r */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    fn = elt(env, 3); /* qqe_ofsf_chsimpterm */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    v148 = stack[0];
    fn = elt(env, 5); /* qqe_arg!-check */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    v148 = stack[0];
    fn = elt(env, 6); /* qqe_op */
    v110 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    v148 = elt(env, 1); /* (qequal qneq) */
    v148 = Lmemq(nil, v110, v148);
    if (v148 == nil) goto v93;
    v148 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); /* qqe_simpat */
        return (*qfn1(fn))(qenv(fn), v148);
    }

v93:
    v148 = stack[0];
    {
        popv(2);
        fn = elt(env, 8); /* ofsf_simpat */
        return (*qfn1(fn))(qenv(fn), v148);
    }
/* error exit handlers */
v149:
    popv(2);
    return nil;
}



/* Code for numpoly_lc */

static Lisp_Object CC_numpoly_lc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v95;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_lc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v104 = v0;
/* end of prologue */
    v95 = v104;
    if (v95 == nil) return onevalue(v104);
    v95 = v104;
    if (is_number(v95)) return onevalue(v104);
    v104 = qcar(v104);
    v104 = qcdr(v104);
    return onevalue(v104);
}



/* Code for dvfsf_smupdknowl */

static Lisp_Object MS_CDECL CC_dvfsf_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v105,
                         Lisp_Object v5, Lisp_Object v142, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v187, v147, v128, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "dvfsf_smupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_smupdknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v187 = v142;
    v147 = v5;
    v128 = v105;
    v129 = v0;
/* end of prologue */
    v71 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v71 == nil) goto v93;
    v71 = v129;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v71, v128, v147, v187);
    }

v93:
    v71 = v129;
    {
        fn = elt(env, 3); /* cl_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v71, v128, v147, v187);
    }
}



/* Code for cnrd */

static Lisp_Object MS_CDECL CC_cnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v74, v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cnrd");
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
/* end of prologue */
    v74 = qvalue(elt(env, 2)); /* atts */
    v75 = elt(env, 3); /* type */
    fn = elt(env, 16); /* find */
    v75 = (*qfn2(fn))(qenv(fn), v74, v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v75 = Lintern(nil, v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    stack[-1] = v75;
    v74 = qvalue(elt(env, 2)); /* atts */
    v75 = elt(env, 4); /* base */
    fn = elt(env, 16); /* find */
    v75 = (*qfn2(fn))(qenv(fn), v74, v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    stack[0] = v75;
    fn = elt(env, 17); /* lex */
    v75 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v75 = qvalue(elt(env, 5)); /* char */
    stack[-4] = v75;
    fn = elt(env, 17); /* lex */
    v75 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v74 = stack[-1];
    v75 = elt(env, 6); /* constant */
    if (v74 == v75) goto v148;
    v75 = stack[-1];
    if (v75 == nil) goto v129;
    v74 = stack[-1];
    v75 = elt(env, 7); /* (real integer) */
    v75 = Lmember(nil, v74, v75);
    if (v75 == nil) goto v175;
    v75 = stack[0];
    if (v75 == nil) goto v189;
    stack[-3] = elt(env, 8); /* based_integer */
    stack[-2] = qvalue(elt(env, 1)); /* nil */
    stack[-1] = stack[0];
    stack[0] = elt(env, 9); /* string */
    v75 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v74 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v75 = qvalue(elt(env, 1)); /* nil */
    v74 = list2star(stack[0], v74, v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v75 = qvalue(elt(env, 1)); /* nil */
    v75 = list2star(stack[-1], v74, v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    {
        Lisp_Object v171 = stack[-3];
        Lisp_Object v173 = stack[-2];
        popv(6);
        return list2star(v171, v173, v75);
    }

v189:
    v75 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v75);
    }

v175:
    v75 = stack[-1];
    v74 = Lintern(nil, v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v75 = elt(env, 10); /* (rational complex!-cartesian complex!-polar) 
*/
    v75 = Lmember(nil, v74, v75);
    if (v75 == nil) goto v162;
    fn = elt(env, 19); /* seprd */
    v75 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    stack[-2] = v75;
    v74 = stack[-1];
    v75 = elt(env, 11); /* rational */
    if (v74 == v75) goto v122;
    v74 = stack[-1];
    v75 = elt(env, 12); /* complex!-cartesian */
    if (v74 == v75) goto v239;
    v74 = stack[-1];
    v75 = elt(env, 14); /* complex!-polar */
    if (!(v74 == v75)) goto v162;
    fn = elt(env, 17); /* lex */
    v75 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    stack[-1] = elt(env, 15); /* complex_polar */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v75 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v164 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v74 = stack[-2];
    v75 = qvalue(elt(env, 1)); /* nil */
    v75 = list2star(v164, v74, v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    {
        Lisp_Object v174 = stack[-1];
        Lisp_Object v251 = stack[0];
        popv(6);
        return list2star(v174, v251, v75);
    }

v162:
    v75 = nil;
    { popv(6); return onevalue(v75); }

v239:
    fn = elt(env, 17); /* lex */
    v75 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    stack[-1] = elt(env, 13); /* complex_cartesian */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v75 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v164 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v74 = stack[-2];
    v75 = qvalue(elt(env, 1)); /* nil */
    v75 = list2star(v164, v74, v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    {
        Lisp_Object v220 = stack[-1];
        Lisp_Object v234 = stack[0];
        popv(6);
        return list2star(v220, v234, v75);
    }

v122:
    fn = elt(env, 17); /* lex */
    v75 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v75 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v74 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v75 = stack[-2];
    {
        popv(6);
        fn = elt(env, 11); /* rational */
        return (*qfn2(fn))(qenv(fn), v74, v75);
    }

v129:
    v75 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v75);
    }

v148:
    v75 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v75);
    }
/* error exit handlers */
v168:
    popv(6);
    return nil;
}



/* Code for suchp */

static Lisp_Object CC_suchp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v106;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for suchp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v106 = v0;
/* end of prologue */
    v96 = v106;
    if (!consp(v96)) goto v103;
    v96 = v106;
    v96 = qcar(v96);
    v106 = elt(env, 1); /* such!-that */
    v96 = (v96 == v106 ? lisp_true : nil);
    return onevalue(v96);

v103:
    v96 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v96);
}



/* Code for evrevgradlexcomp */

static Lisp_Object CC_evrevgradlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v190, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evrevgradlexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v105;
    stack[-2] = v0;
/* end of prologue */

v17:
    v190 = stack[-2];
    if (v190 == nil) goto v85;
    v190 = stack[-1];
    if (v190 == nil) goto v94;
    v190 = stack[-2];
    v182 = qcar(v190);
    v190 = stack[-1];
    v190 = qcar(v190);
    v190 = Leqn(nil, v182, v190);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-4];
    if (v190 == nil) goto v110;
    v190 = stack[-2];
    v190 = qcdr(v190);
    stack[-2] = v190;
    v190 = stack[-1];
    v190 = qcdr(v190);
    stack[-1] = v190;
    goto v17;

v110:
    v190 = stack[-2];
    fn = elt(env, 2); /* evtdeg */
    stack[0] = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-4];
    v190 = stack[-1];
    fn = elt(env, 2); /* evtdeg */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v190;
    v182 = stack[-3];
    v190 = stack[0];
    v190 = Leqn(nil, v182, v190);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-4];
    if (v190 == nil) goto v50;
    v182 = stack[-2];
    v190 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* evinvlexcomp */
        return (*qfn2(fn))(qenv(fn), v182, v190);
    }

v50:
    v182 = stack[-3];
    v190 = stack[0];
    if (((int32_t)(v182)) > ((int32_t)(v190))) goto v51;
    v190 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v190); }

v51:
    v190 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v190); }

v94:
    v190 = elt(env, 1); /* (0) */
    stack[-1] = v190;
    goto v17;

v85:
    v190 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v190); }
/* error exit handlers */
v143:
    popv(5);
    return nil;
}



/* Code for basisformp */

static Lisp_Object CC_basisformp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basisformp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v96 = v0;
/* end of prologue */
    v95 = v96;
    if (!consp(v95)) goto v102;
    v95 = v96;
    v96 = qvalue(elt(env, 1)); /* basisforml!* */
    v95 = Lmemq(nil, v95, v96);
    return onevalue(v95);

v102:
    v95 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v95);
}



/* Code for actual_alst */

static Lisp_Object CC_actual_alst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v147, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for actual_alst");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v105;
    stack[-1] = v0;
/* end of prologue */
    v128 = nil;
    goto v15;

v15:
    v187 = stack[-1];
    if (v187 == nil) goto v86;
    v187 = stack[-1];
    v187 = qcar(v187);
    v147 = qcar(v187);
    v187 = stack[0];
    v187 = Lmemq(nil, v147, v187);
    if (v187 == nil) goto v88;
    v187 = stack[-1];
    v187 = qcar(v187);
    v147 = v128;
    v187 = cons(v187, v147);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v128 = v187;
    v187 = stack[-1];
    v187 = qcdr(v187);
    stack[-1] = v187;
    goto v15;

v88:
    v187 = stack[-1];
    v187 = qcdr(v187);
    stack[-1] = v187;
    goto v15;

v86:
    v187 = v128;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v187);
    }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for subs2chk */

static Lisp_Object CC_subs2chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v138, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2chk");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v59 = qvalue(elt(env, 1)); /* subfg!* */
    if (v59 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v59 = stack[0];
    fn = elt(env, 2); /* subs2f */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v192;
    v92 = v59;
    v138 = qcdr(v59);
    v59 = (Lisp_Object)17; /* 1 */
    if (!(v138 == v59)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v59 = v92;
    v59 = qcar(v59);
    stack[0] = v59;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v192:
    popv(1);
    return nil;
}



/* Code for xnsiz */

static Lisp_Object CC_xnsiz(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xnsiz");
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
    v94 = v0;
/* end of prologue */
    fn = elt(env, 2); /* xnsiz1 */
    v113 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[0];
    v94 = qvalue(elt(env, 1)); /* log2of10 */
    v94 = quot2(v113, v94);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* ceiling */
        return (*qfn1(fn))(qenv(fn), v94);
    }
/* error exit handlers */
v115:
    popv(1);
    return nil;
}



/* Code for in_list1 */

static Lisp_Object CC_in_list1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v38, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for in_list1");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v105;
    stack[-3] = v0;
/* end of prologue */
    v155 = qvalue(elt(env, 1)); /* !*echo */
    stack[-1] = v155;
    v155 = qvalue(elt(env, 2)); /* !*reduce4 */
    if (v155 == nil) goto v114;
    v155 = stack[-3];
    fn = elt(env, 14); /* type */
    v38 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    v155 = elt(env, 3); /* string */
    if (v38 == v155) goto v149;
    v38 = stack[-3];
    v155 = elt(env, 3); /* string */
    fn = elt(env, 15); /* typerr */
    v155 = (*qfn2(fn))(qenv(fn), v38, v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    goto v114;

v114:
    v155 = stack[-3];
    fn = elt(env, 16); /* mkfil!* */
    v38 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    stack[-3] = v38;
    v155 = elt(env, 4); /* input */
    fn = elt(env, 17); /* open */
    v155 = (*qfn2(fn))(qenv(fn), v38, v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    stack[-4] = v155;
    v155 = stack[-4];
    v155 = Lrds(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    stack[0] = v155;
    v38 = stack[-3];
    v155 = qvalue(elt(env, 5)); /* linelist!* */
    v155 = Lassoc(nil, v38, v155);
    if (!(v155 == nil)) goto v98;

v98:
    v155 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 7)) = v155; /* curline!* */
    v39 = stack[-3];
    v38 = stack[-4];
    v155 = (Lisp_Object)17; /* 1 */
    v155 = list3(v39, v38, v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    qvalue(elt(env, 8)) = v155; /* ifl!* */
    v38 = qvalue(elt(env, 8)); /* ifl!* */
    v155 = qvalue(elt(env, 9)); /* ipl!* */
    v155 = cons(v38, v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    qvalue(elt(env, 9)) = v155; /* ipl!* */
    v155 = stack[-2];
    qvalue(elt(env, 1)) = v155; /* !*echo */
    fn = elt(env, 18); /* begin1 */
    v155 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    v155 = stack[0];
    v155 = Lrds(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    v155 = stack[-4];
    v155 = Lclose(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    v155 = stack[-1];
    qvalue(elt(env, 1)) = v155; /* !*echo */
    v155 = qvalue(elt(env, 9)); /* ipl!* */
    if (v155 == nil) goto v191;
    v155 = qvalue(elt(env, 6)); /* nil */
    goto v81;

v81:
    if (v155 == nil) goto v44;
    v155 = qvalue(elt(env, 6)); /* nil */
    { popv(6); return onevalue(v155); }

v44:
    v155 = qvalue(elt(env, 9)); /* ipl!* */
    if (v155 == nil) goto v176;
    v38 = stack[-3];
    v155 = qvalue(elt(env, 9)); /* ipl!* */
    v155 = qcar(v155);
    v155 = qcar(v155);
    v155 = (v38 == v155 ? lisp_true : nil);
    v155 = (v155 == nil ? lisp_true : nil);
    goto v175;

v175:
    if (v155 == nil) goto v248;
    v155 = qvalue(elt(env, 12)); /* !*protfg */
    if (!(v155 == nil)) goto v117;
    v39 = elt(env, 13); /* "FILE STACK CONFUSION" */
    v38 = stack[-3];
    v155 = qvalue(elt(env, 9)); /* ipl!* */
    v155 = list3(v39, v38, v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    fn = elt(env, 19); /* lprie */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    goto v117;

v117:
    v155 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v246;
    goto v124;

v124:
    v155 = nil;
    { popv(6); return onevalue(v155); }

v248:
    v155 = qvalue(elt(env, 9)); /* ipl!* */
    v155 = qcdr(v155);
    qvalue(elt(env, 9)) = v155; /* ipl!* */
    goto v124;

v176:
    v155 = qvalue(elt(env, 11)); /* t */
    goto v175;

v191:
    v155 = qvalue(elt(env, 10)); /* contl!* */
    goto v81;

v149:
    v155 = stack[-3];
    fn = elt(env, 20); /* value */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-5];
    stack[-3] = v155;
    goto v114;
/* error exit handlers */
v246:
    popv(6);
    return nil;
}



/* Code for monomcomparedeglex */

static Lisp_Object CC_monomcomparedeglex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v253, v254, v84, v246;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomcomparedeglex");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v105;
    v246 = v0;
/* end of prologue */
    v253 = (Lisp_Object)1; /* 0 */
    stack[0] = v253;
    v254 = v246;
    v253 = (Lisp_Object)1; /* 0 */
    v84 = *(Lisp_Object *)((char *)v254 + (CELL-TAG_VECTOR) + ((int32_t)v253/(16/CELL)));
    v254 = stack[-1];
    v253 = (Lisp_Object)1; /* 0 */
    v253 = *(Lisp_Object *)((char *)v254 + (CELL-TAG_VECTOR) + ((int32_t)v253/(16/CELL)));
    if (((int32_t)(v84)) > ((int32_t)(v253))) goto v94;
    v254 = v246;
    v253 = (Lisp_Object)1; /* 0 */
    v84 = *(Lisp_Object *)((char *)v254 + (CELL-TAG_VECTOR) + ((int32_t)v253/(16/CELL)));
    v254 = stack[-1];
    v253 = (Lisp_Object)1; /* 0 */
    v253 = *(Lisp_Object *)((char *)v254 + (CELL-TAG_VECTOR) + ((int32_t)v253/(16/CELL)));
    if (((int32_t)(v84)) < ((int32_t)(v253))) goto v89;
    v254 = qvalue(elt(env, 1)); /* nil */
    v84 = v246;
    v253 = (Lisp_Object)17; /* 1 */
    v253 = *(Lisp_Object *)((char *)v84 + (CELL-TAG_VECTOR) + ((int32_t)v253/(16/CELL)));
    v253 = cons(v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v253 = Lreverse(nil, v253);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v253 = qcdr(v253);
    stack[-2] = v253;
    v84 = qvalue(elt(env, 1)); /* nil */
    v254 = stack[-1];
    v253 = (Lisp_Object)17; /* 1 */
    v253 = *(Lisp_Object *)((char *)v254 + (CELL-TAG_VECTOR) + ((int32_t)v253/(16/CELL)));
    v253 = cons(v84, v253);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v253 = Lreverse(nil, v253);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v253 = qcdr(v253);
    stack[-1] = v253;
    goto v186;

v186:
    v253 = stack[-2];
    v253 = qcar(v253);
    if (v253 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v253 = stack[-1];
    v253 = qcar(v253);
    if (v253 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v253 = stack[-2];
    v254 = qcar(v253);
    v253 = stack[-1];
    v253 = qcar(v253);
    v253 = (Lisp_Object)lessp2(v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v36;
    v253 = v253 ? lisp_true : nil;
    env = stack[-3];
    if (v253 == nil) goto v43;
    v253 = (Lisp_Object)17; /* 1 */
    stack[0] = v253;
    v253 = qvalue(elt(env, 1)); /* nil */
    v253 = ncons(v253);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    stack[-2] = v253;
    goto v186;

v43:
    v253 = stack[-2];
    v254 = qcar(v253);
    v253 = stack[-1];
    v253 = qcar(v253);
    v253 = (Lisp_Object)greaterp2(v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v36;
    v253 = v253 ? lisp_true : nil;
    env = stack[-3];
    if (v253 == nil) goto v248;
    v253 = (Lisp_Object)-15; /* -1 */
    stack[0] = v253;
    v253 = qvalue(elt(env, 1)); /* nil */
    v253 = ncons(v253);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    stack[-2] = v253;
    goto v186;

v248:
    v253 = stack[-2];
    v253 = qcdr(v253);
    stack[-2] = v253;
    v253 = stack[-1];
    v253 = qcdr(v253);
    stack[-1] = v253;
    goto v186;

v89:
    v253 = (Lisp_Object)-15; /* -1 */
    stack[0] = v253;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v94:
    v253 = (Lisp_Object)17; /* 1 */
    stack[0] = v253;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v36:
    popv(4);
    return nil;
}



/* Code for multdf */

static Lisp_Object CC_multdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v105)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdf");
#endif
    if (stack >= stacklimit)
    {
        push2(v105,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v105);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v105;
    stack[-1] = v0;
/* end of prologue */
    v78 = stack[-1];
    if (v78 == nil) goto v86;
    v78 = stack[0];
    v78 = (v78 == nil ? lisp_true : nil);
    goto v85;

v85:
    if (v78 == nil) goto v59;
    v78 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v78); }

v59:
    v78 = stack[-1];
    v77 = qcar(v78);
    v78 = stack[0];
    v78 = qcar(v78);
    fn = elt(env, 3); /* multerm */
    v78 = (*qfn2(fn))(qenv(fn), v77, v78);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-3];
    stack[-2] = v78;
    v78 = stack[-1];
    v77 = qcdr(v78);
    v78 = stack[0];
    v78 = CC_multdf(env, v77, v78);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-3];
    fn = elt(env, 4); /* plusdf */
    v78 = (*qfn2(fn))(qenv(fn), stack[-2], v78);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-3];
    stack[-2] = v78;
    v78 = stack[-1];
    v78 = qcar(v78);
    v77 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-3];
    v78 = stack[0];
    v78 = qcdr(v78);
    v78 = CC_multdf(env, v77, v78);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-3];
    {
        Lisp_Object v182 = stack[-2];
        popv(4);
        fn = elt(env, 4); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v182, v78);
    }

v86:
    v78 = qvalue(elt(env, 1)); /* t */
    goto v85;
/* error exit handlers */
v190:
    popv(4);
    return nil;
}



setup_type const u23_setup[] =
{
    {"procstat1",               CC_procstat1,   too_many_1,    wrong_no_1},
    {"cl_nnf",                  CC_cl_nnf,      too_many_1,    wrong_no_1},
    {"encodeir",                CC_encodeir,    too_many_1,    wrong_no_1},
    {"module",                  CC_module,      too_many_1,    wrong_no_1},
    {"permp",                   too_few_2,      CC_permp,      wrong_no_2},
    {"assert_kernelp",          CC_assert_kernelp,too_many_1,  wrong_no_1},
    {"sf2mv",                   too_few_2,      CC_sf2mv,      wrong_no_2},
    {"lastcar",                 CC_lastcar,     too_many_1,    wrong_no_1},
    {"reduce-mod-p*",           too_few_2,      CC_reduceKmodKpH,wrong_no_2},
    {"ifstat",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_ifstat},
    {"ofsf_varlat",             CC_ofsf_varlat, too_many_1,    wrong_no_1},
    {"sortedtriplelistinsert",  too_few_2,      CC_sortedtriplelistinsert,wrong_no_2},
    {"rl_nnf",                  CC_rl_nnf,      too_many_1,    wrong_no_1},
    {"wureducedp",              too_few_2,      CC_wureducedp, wrong_no_2},
    {"klistt",                  CC_klistt,      too_many_1,    wrong_no_1},
    {"squashsqrt",              CC_squashsqrt,  too_many_1,    wrong_no_1},
    {"evallessp",               too_few_2,      CC_evallessp,  wrong_no_2},
    {"sq2sstm",                 too_few_2,      CC_sq2sstm,    wrong_no_2},
    {"vdp_plist",               CC_vdp_plist,   too_many_1,    wrong_no_1},
    {"lambdafun",               CC_lambdafun,   too_many_1,    wrong_no_1},
    {"recaliasbacksubst",       too_few_2,      CC_recaliasbacksubst,wrong_no_2},
    {"ordexp",                  too_few_2,      CC_ordexp,     wrong_no_2},
    {"evalb",                   CC_evalb,       too_many_1,    wrong_no_1},
    {"sublap",                  too_few_2,      CC_sublap,     wrong_no_2},
    {"edge_new_parents",        CC_edge_new_parents,too_many_1,wrong_no_1},
    {"no-side-effectp",         CC_noKsideKeffectp,too_many_1, wrong_no_1},
    {"fs:prin1",                CC_fsTprin1,    too_many_1,    wrong_no_1},
    {"red_tailred",             too_few_2,      CC_red_tailred,wrong_no_2},
    {"*di2q0",                  too_few_2,      CC_Hdi2q0,     wrong_no_2},
    {"rootextractf",            CC_rootextractf,too_many_1,    wrong_no_1},
    {"general-modular-expt",    too_few_2,      CC_generalKmodularKexpt,wrong_no_2},
    {"gcref_off",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_gcref_off},
    {"pushback",                too_few_2,      CC_pushback,   wrong_no_2},
    {"cl_pnf",                  CC_cl_pnf,      too_many_1,    wrong_no_1},
    {"width",                   too_few_2,      CC_width,      wrong_no_2},
    {"mk+conjugate+sq",         CC_mkLconjugateLsq,too_many_1, wrong_no_1},
    {"lambdavar",               CC_lambdavar,   too_many_1,    wrong_no_1},
    {"dip-nc-ev-prod1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipKncKevKprod1},
    {"overall_factor",          too_few_2,      CC_overall_factor,wrong_no_2},
    {"all_edge",                too_few_2,      CC_all_edge,   wrong_no_2},
    {"mv-pow->",                too_few_2,      CC_mvKpowKS,   wrong_no_2},
    {"*a2k",                    CC_Ha2k,        too_many_1,    wrong_no_1},
    {"copy-tree",               CC_copyKtree,   too_many_1,    wrong_no_1},
    {"merge",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_merge},
    {"atom_compare",            too_few_2,      CC_atom_compare,wrong_no_2},
    {"polynomlistreduce",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_polynomlistreduce},
    {"get-free-form",           CC_getKfreeKform,too_many_1,   wrong_no_1},
    {"qqe_ofsf_simpat",         CC_qqe_ofsf_simpat,too_many_1, wrong_no_1},
    {"numpoly_lc",              CC_numpoly_lc,  too_many_1,    wrong_no_1},
    {"dvfsf_smupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvfsf_smupdknowl},
    {"cnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cnrd},
    {"suchp",                   CC_suchp,       too_many_1,    wrong_no_1},
    {"evrevgradlexcomp",        too_few_2,      CC_evrevgradlexcomp,wrong_no_2},
    {"basisformp",              CC_basisformp,  too_many_1,    wrong_no_1},
    {"actual_alst",             too_few_2,      CC_actual_alst,wrong_no_2},
    {"subs2chk",                CC_subs2chk,    too_many_1,    wrong_no_1},
    {"xnsiz",                   CC_xnsiz,       too_many_1,    wrong_no_1},
    {"in_list1",                too_few_2,      CC_in_list1,   wrong_no_2},
    {"monomcomparedeglex",      too_few_2,      CC_monomcomparedeglex,wrong_no_2},
    {"multdf",                  too_few_2,      CC_multdf,     wrong_no_2},
    {NULL, (one_args *)"u23", (two_args *)"11959 8536651 9641704", 0}
};

/* end of generated code */
