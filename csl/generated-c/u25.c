
/* $destdir\u25.c        Machine generated C code */

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


/* Code for physopsimp */

static Lisp_Object CC_physopsimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v73, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsimp");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0;
/* end of prologue */
    stack[-4] = nil;
    v72 = stack[-6];
    if (symbolp(v72)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v72 = stack[-6];
    v72 = qcar(v72);
    stack[-7] = v72;
    v72 = stack[-6];
    v72 = qcdr(v72);
    stack[-5] = v72;
    v72 = stack[-5];
    if (v72 == nil) goto v75;
    v72 = stack[-5];
    v72 = qcar(v72);
    stack[0] = v72;
    v72 = stack[0];
    if (!(symbolp(v72))) goto v76;
    v72 = stack[0];
    fn = elt(env, 8); /* isanindex */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (!(v72 == nil)) goto v78;
    v72 = stack[0];
    fn = elt(env, 9); /* isavarindex */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (!(v72 == nil)) goto v78;

v76:
    v72 = stack[0];
    fn = elt(env, 10); /* physopsm!* */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    goto v79;

v79:
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[-2] = v72;
    stack[-3] = v72;
    goto v80;

v80:
    v72 = stack[-5];
    v72 = qcdr(v72);
    stack[-5] = v72;
    v72 = stack[-5];
    if (v72 == nil) goto v81;
    stack[-1] = stack[-2];
    v72 = stack[-5];
    v72 = qcar(v72);
    stack[0] = v72;
    v72 = stack[0];
    if (!(symbolp(v72))) goto v82;
    v72 = stack[0];
    fn = elt(env, 8); /* isanindex */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (!(v72 == nil)) goto v83;
    v72 = stack[0];
    fn = elt(env, 9); /* isavarindex */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (!(v72 == nil)) goto v83;

v82:
    v72 = stack[0];
    fn = elt(env, 10); /* physopsm!* */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    goto v84;

v84:
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = Lrplacd(nil, stack[-1], v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = stack[-2];
    v72 = qcdr(v72);
    stack[-2] = v72;
    goto v80;

v83:
    v72 = stack[0];
    goto v84;

v81:
    v72 = stack[-3];
    goto v85;

v85:
    stack[0] = v72;
    stack[-5] = stack[-7];
    v72 = stack[0];
    stack[-3] = v72;
    v72 = stack[-3];
    if (v72 == nil) goto v86;
    v72 = stack[-3];
    v72 = qcar(v72);
    v74 = v72;
    v73 = v74;
    v72 = elt(env, 2); /* !*sq */
    if (!consp(v73)) goto v87;
    v73 = qcar(v73);
    if (!(v73 == v72)) goto v87;
    v72 = v74;
    v72 = qcdr(v72);
    v72 = qcar(v72);
    fn = elt(env, 11); /* prepsqxx */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    goto v88;

v88:
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[-1] = v72;
    stack[-2] = v72;
    goto v89;

v89:
    v72 = stack[-3];
    v72 = qcdr(v72);
    stack[-3] = v72;
    v72 = stack[-3];
    if (v72 == nil) goto v90;
    stack[0] = stack[-1];
    v72 = stack[-3];
    v72 = qcar(v72);
    v74 = v72;
    v73 = v74;
    v72 = elt(env, 2); /* !*sq */
    if (!consp(v73)) goto v91;
    v73 = qcar(v73);
    if (!(v73 == v72)) goto v91;
    v72 = v74;
    v72 = qcdr(v72);
    v72 = qcar(v72);
    fn = elt(env, 11); /* prepsqxx */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    goto v92;

v92:
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = Lrplacd(nil, stack[0], v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = stack[-1];
    v72 = qcdr(v72);
    stack[-1] = v72;
    goto v89;

v91:
    v72 = v74;
    goto v92;

v90:
    v72 = stack[-2];
    goto v93;

v93:
    v72 = cons(stack[-5], v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[-6] = v72;
    v72 = stack[-6];
    fn = elt(env, 12); /* opmtch!* */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[0] = v72;
    if (!(v72 == nil)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    v72 = stack[-6];
    fn = elt(env, 13); /* scalopp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (v72 == nil) goto v94;
    v72 = stack[-7];
    fn = elt(env, 14); /* tensopp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (v72 == nil) goto v94;
    v73 = stack[-7];
    v72 = elt(env, 3); /* tensdimen */
    v72 = get(v73, v72);
    env = stack[-8];
    stack[-5] = v72;
    v72 = (Lisp_Object)17; /* 1 */
    stack[-3] = v72;
    v73 = stack[-5];
    v72 = stack[-3];
    v72 = difference2(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = Lminusp(nil, v72);
    env = stack[-8];
    if (v72 == nil) goto v95;
    v72 = qvalue(elt(env, 1)); /* nil */
    goto v96;

v96:
    stack[0] = v72;
    v72 = stack[-6];
    v72 = qcdr(v72);
    v73 = Llength(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = stack[-5];
    v72 = (Lisp_Object)greaterp2(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    v72 = v72 ? lisp_true : nil;
    env = stack[-8];
    if (v72 == nil) goto v97;
    v72 = stack[-6];
    stack[-1] = qcdr(v72);
    v72 = stack[-5];
    v72 = add1(v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    fn = elt(env, 15); /* pnth */
    v72 = (*qfn2(fn))(qenv(fn), stack[-1], v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[-5] = v72;
    goto v98;

v98:
    v73 = stack[-7];
    v72 = elt(env, 4); /* symmetric */
    v72 = Lflagp(nil, v73, v72);
    env = stack[-8];
    if (v72 == nil) goto v99;
    stack[-1] = stack[-7];
    v72 = stack[0];
    fn = elt(env, 16); /* ordn */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = cons(stack[-1], v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[-6] = v72;
    goto v100;

v100:
    v72 = stack[-5];
    if (v72 == nil) goto v101;
    v73 = stack[-6];
    v72 = stack[-5];
    v72 = Lappend(nil, v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[-6] = v72;
    goto v101;

v101:
    v72 = stack[-4];
    if (v72 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v73 = elt(env, 7); /* minus */
    v72 = stack[-6];
    popv(9);
    return list2(v73, v72);

v99:
    v73 = stack[-7];
    v72 = elt(env, 5); /* antisymmetric */
    v72 = Lflagp(nil, v73, v72);
    env = stack[-8];
    if (v72 == nil) goto v102;
    v72 = stack[0];
    fn = elt(env, 17); /* repeats */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (v72 == nil) goto v103;
    v72 = (Lisp_Object)1; /* 0 */
    { popv(9); return onevalue(v72); }

v103:
    v72 = stack[0];
    fn = elt(env, 16); /* ordn */
    v73 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[-1] = v73;
    v72 = stack[0];
    fn = elt(env, 18); /* permp */
    v72 = (*qfn2(fn))(qenv(fn), v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (!(v72 == nil)) goto v104;
    v72 = qvalue(elt(env, 6)); /* t */
    stack[-4] = v72;
    goto v104;

v104:
    v72 = stack[-1];
    stack[0] = v72;
    v73 = stack[-7];
    v72 = stack[0];
    v72 = cons(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[-6] = v72;
    goto v100;

v102:
    v73 = stack[-7];
    v72 = stack[0];
    v72 = cons(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[-6] = v72;
    goto v100;

v97:
    v72 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v72;
    goto v98;

v95:
    v72 = stack[-6];
    v73 = qcdr(v72);
    v72 = stack[-3];
    fn = elt(env, 15); /* pnth */
    v72 = (*qfn2(fn))(qenv(fn), v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = qcar(v72);
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[-1] = v72;
    stack[-2] = v72;
    goto v105;

v105:
    v72 = stack[-3];
    v72 = add1(v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[-3] = v72;
    v73 = stack[-5];
    v72 = stack[-3];
    v72 = difference2(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = Lminusp(nil, v72);
    env = stack[-8];
    if (v72 == nil) goto v106;
    v72 = stack[-2];
    goto v96;

v106:
    stack[0] = stack[-1];
    v72 = stack[-6];
    v73 = qcdr(v72);
    v72 = stack[-3];
    fn = elt(env, 15); /* pnth */
    v72 = (*qfn2(fn))(qenv(fn), v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = qcar(v72);
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = Lrplacd(nil, stack[0], v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = stack[-1];
    v72 = qcdr(v72);
    stack[-1] = v72;
    goto v105;

v94:
    v72 = stack[-6];
    fn = elt(env, 19); /* vecopp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (v72 == nil) goto v107;
    v72 = stack[-6];
    fn = elt(env, 20); /* listp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (v72 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v72 = stack[-6];
    v72 = qcdr(v72);
    v72 = qcar(v72);
    fn = elt(env, 21); /* putanewindex!* */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }

v107:
    v72 = stack[-6];
    fn = elt(env, 14); /* tensopp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (v72 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v72 = stack[-6];
    fn = elt(env, 20); /* listp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    if (v72 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v72 = (Lisp_Object)17; /* 1 */
    stack[0] = v72;
    goto v108;

v108:
    v72 = stack[-6];
    v72 = qcdr(v72);
    v73 = Llength(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = stack[0];
    v72 = difference2(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = Lminusp(nil, v72);
    env = stack[-8];
    if (!(v72 == nil)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v72 = stack[-6];
    v73 = qcdr(v72);
    v72 = stack[0];
    fn = elt(env, 15); /* pnth */
    v72 = (*qfn2(fn))(qenv(fn), v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = qcar(v72);
    fn = elt(env, 21); /* putanewindex!* */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    v72 = stack[0];
    v72 = add1(v72);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-8];
    stack[0] = v72;
    goto v108;

v87:
    v72 = v74;
    goto v88;

v86:
    v72 = qvalue(elt(env, 1)); /* nil */
    goto v93;

v78:
    v72 = stack[0];
    goto v79;

v75:
    v72 = qvalue(elt(env, 1)); /* nil */
    goto v85;
/* error exit handlers */
v77:
    popv(9);
    return nil;
}



/* Code for ev!-denom2 */

static Lisp_Object CC_evKdenom2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-denom2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v112 = v109;
    v113 = v0;
/* end of prologue */
    v113 = qcar(v113);
    {
        fn = elt(env, 1); /* ev!-edgeloop */
        return (*qfn2(fn))(qenv(fn), v113, v112);
    }
}



/* Code for mv!-domainlist!-!+ */

static Lisp_Object CC_mvKdomainlistKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v109;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v8;

v8:
    v78 = stack[-1];
    if (v78 == nil) goto v118;
    v78 = stack[-1];
    v117 = qcar(v78);
    v78 = stack[0];
    v78 = qcar(v78);
    v117 = plus2(v117, v78);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    v78 = stack[-2];
    v78 = cons(v117, v78);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    stack[-2] = v78;
    v78 = stack[-1];
    v78 = qcdr(v78);
    stack[-1] = v78;
    v78 = stack[0];
    v78 = qcdr(v78);
    stack[0] = v78;
    goto v8;

v118:
    v78 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v78);
    }
/* error exit handlers */
v119:
    popv(4);
    return nil;
}



/* Code for inprint */

static Lisp_Object MS_CDECL CC_inprint(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v109,
                         Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v189, v190, v191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "inprint");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inprint");
#endif
    if (stack >= stacklimit)
    {
        push3(v15,v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v109,v15);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v15;
    stack[-2] = v109;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[0] = nil;
    v189 = stack[-3];
    v188 = elt(env, 1); /* times */
    if (v189 == v188) goto v192;
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v193;

v193:
    if (v188 == nil) goto v194;
    v188 = elt(env, 5); /* times2 */
    stack[-3] = v188;
    v191 = elt(env, 5); /* times2 */
    v190 = elt(env, 6); /* infix */
    v189 = elt(env, 1); /* times */
    v188 = elt(env, 6); /* infix */
    v188 = get(v189, v188);
    env = stack[-5];
    v188 = Lputprop(nil, 3, v191, v190, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v190 = elt(env, 5); /* times2 */
    v189 = elt(env, 7); /* prtch */
    v188 = elt(env, 8); /* " " */
    v188 = Lputprop(nil, 3, v190, v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v194;

v194:
    v189 = stack[-3];
    v188 = elt(env, 9); /* plus */
    if (v189 == v188) goto v84;
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v65;

v65:
    if (v188 == nil) goto v196;
    v188 = stack[-1];
    v188 = Lreverse(nil, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    stack[-1] = v188;
    goto v196;

v196:
    v189 = stack[-3];
    v188 = elt(env, 11); /* alt */
    v188 = get(v189, v188);
    env = stack[-5];
    if (!(v188 == nil)) goto v197;
    v189 = stack[-3];
    v188 = elt(env, 12); /* not */
    if (v189 == v188) goto v48;
    v189 = stack[-3];
    v188 = elt(env, 13); /* setq */
    if (v189 == v188) goto v88;
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v58;

v58:
    if (v188 == nil) goto v56;
    v190 = stack[0];
    v188 = stack[-1];
    v189 = qcar(v188);
    v188 = stack[-4];
        popv(6);
        return Lapply2(nil, 3, v190, v189, v188);

v56:
    v188 = stack[-1];
    v188 = qcar(v188);
    if (!consp(v188)) goto v198;
    v188 = stack[-1];
    v188 = qcar(v188);
    v188 = qcar(v188);
    if (symbolp(v188)) goto v37;
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v199;

v199:
    if (v188 == nil) goto v200;
    v188 = elt(env, 19); /* "(" */
    fn = elt(env, 26); /* prin2!* */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v188 = stack[-1];
    v189 = qcar(v188);
    v188 = stack[-2];
    fn = elt(env, 27); /* maprint */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v188 = elt(env, 20); /* ")" */
    fn = elt(env, 26); /* prin2!* */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v94;

v94:
    v188 = stack[-1];
    v188 = qcdr(v188);
    stack[-1] = v188;
    goto v197;

v197:
    v188 = qvalue(elt(env, 21)); /* !*nosplit */
    if (v188 == nil) goto v201;
    v188 = qvalue(elt(env, 22)); /* testing!-width!* */
    if (!(v188 == nil)) goto v201;
    v188 = stack[-1];
    stack[-1] = v188;
    goto v24;

v24:
    v188 = stack[-1];
    if (v188 == nil) goto v202;
    v188 = stack[-1];
    v188 = qcar(v188);
    stack[0] = v188;
    v188 = stack[0];
    if (!consp(v188)) goto v203;
    v190 = stack[-3];
    v188 = stack[0];
    v189 = qcar(v188);
    v188 = elt(env, 11); /* alt */
    v188 = get(v189, v188);
    env = stack[-5];
    v188 = (v190 == v188 ? lisp_true : nil);
    v188 = (v188 == nil ? lisp_true : nil);
    goto v204;

v204:
    if (v188 == nil) goto v205;
    v189 = stack[-3];
    v188 = elt(env, 24); /* (setq !*comma!*) */
    v188 = Lmemq(nil, v189, v188);
    if (v188 == nil) goto v206;
    v188 = stack[-3];
    fn = elt(env, 28); /* oprin */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v189 = stack[0];
    v188 = elt(env, 25); /* minus */
    if (!consp(v189)) goto v207;
    v189 = qcar(v189);
    if (!(v189 == v188)) goto v207;
    v188 = stack[0];
    v188 = qcdr(v188);
    v188 = qcar(v188);
    v188 = (is_number(v188) ? lisp_true : nil);
    goto v208;

v208:
    if (v188 == nil) goto v209;
    v188 = stack[0];
    v188 = qcdr(v188);
    v188 = qcar(v188);
    v188 = negate(v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v190 = v188;
    goto v210;

v210:
    v189 = stack[-2];
    v188 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 29); /* prinfit */
    v188 = (*qfnn(fn))(qenv(fn), 3, v190, v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v211;

v211:
    v188 = stack[-1];
    v188 = qcdr(v188);
    stack[-1] = v188;
    goto v24;

v209:
    v188 = stack[0];
    v190 = v188;
    goto v210;

v207:
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v208;

v206:
    v189 = stack[0];
    v188 = elt(env, 25); /* minus */
    if (!consp(v189)) goto v212;
    v189 = qcar(v189);
    if (!(v189 == v188)) goto v212;
    v188 = stack[0];
    v188 = qcdr(v188);
    v188 = qcar(v188);
    v188 = (is_number(v188) ? lisp_true : nil);
    goto v213;

v213:
    if (v188 == nil) goto v214;
    v188 = stack[0];
    v188 = qcdr(v188);
    v188 = qcar(v188);
    v188 = negate(v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v190 = v188;
    goto v215;

v215:
    v189 = stack[-2];
    v188 = stack[-3];
    fn = elt(env, 29); /* prinfit */
    v188 = (*qfnn(fn))(qenv(fn), 3, v190, v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v211;

v214:
    v188 = stack[0];
    v190 = v188;
    goto v215;

v212:
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v213;

v205:
    v190 = stack[0];
    v189 = stack[-2];
    v188 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 29); /* prinfit */
    v188 = (*qfnn(fn))(qenv(fn), 3, v190, v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v211;

v203:
    v188 = qvalue(elt(env, 23)); /* t */
    goto v204;

v202:
    v188 = nil;
    { popv(6); return onevalue(v188); }

v201:
    v188 = stack[-1];
    stack[-1] = v188;
    goto v216;

v216:
    v188 = stack[-1];
    if (v188 == nil) goto v202;
    v188 = stack[-1];
    v188 = qcar(v188);
    stack[0] = v188;
    v188 = stack[0];
    if (!consp(v188)) goto v217;
    v190 = stack[-3];
    v188 = stack[0];
    v189 = qcar(v188);
    v188 = elt(env, 11); /* alt */
    v188 = get(v189, v188);
    env = stack[-5];
    v188 = (v190 == v188 ? lisp_true : nil);
    v188 = (v188 == nil ? lisp_true : nil);
    goto v218;

v218:
    if (v188 == nil) goto v219;
    v188 = stack[-3];
    fn = elt(env, 28); /* oprin */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v189 = stack[0];
    v188 = elt(env, 25); /* minus */
    if (!consp(v189)) goto v220;
    v189 = qcar(v189);
    if (!(v189 == v188)) goto v220;
    v188 = stack[0];
    v188 = qcdr(v188);
    v188 = qcar(v188);
    v188 = (is_number(v188) ? lisp_true : nil);
    goto v221;

v221:
    if (v188 == nil) goto v222;
    v188 = stack[0];
    v188 = qcdr(v188);
    v188 = qcar(v188);
    v188 = negate(v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v189 = v188;
    goto v223;

v223:
    v188 = stack[-2];
    fn = elt(env, 27); /* maprint */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v224;

v224:
    v188 = stack[-1];
    v188 = qcdr(v188);
    stack[-1] = v188;
    goto v216;

v222:
    v188 = stack[0];
    v189 = v188;
    goto v223;

v220:
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v221;

v219:
    v189 = stack[0];
    v188 = stack[-2];
    fn = elt(env, 27); /* maprint */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v224;

v217:
    v188 = qvalue(elt(env, 23)); /* t */
    goto v218;

v200:
    v188 = qvalue(elt(env, 21)); /* !*nosplit */
    if (v188 == nil) goto v225;
    v188 = qvalue(elt(env, 22)); /* testing!-width!* */
    if (!(v188 == nil)) goto v225;
    v188 = stack[-1];
    v190 = qcar(v188);
    v189 = stack[-2];
    v188 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 29); /* prinfit */
    v188 = (*qfnn(fn))(qenv(fn), 3, v190, v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v94;

v225:
    v188 = stack[-1];
    v189 = qcar(v188);
    v188 = stack[-2];
    fn = elt(env, 27); /* maprint */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v94;

v37:
    v188 = qvalue(elt(env, 2)); /* !*nat */
    if (v188 == nil) goto v226;
    v188 = stack[-1];
    v188 = qcar(v188);
    v189 = qcar(v188);
    v188 = elt(env, 16); /* prifn */
    v188 = get(v189, v188);
    env = stack[-5];
    stack[-4] = v188;
    if (!(v188 == nil)) goto v227;
    v188 = stack[-1];
    v188 = qcar(v188);
    v189 = qcar(v188);
    v188 = elt(env, 17); /* pprifn */
    v188 = get(v189, v188);
    env = stack[-5];
    stack[-4] = v188;
    if (!(v188 == nil)) goto v227;
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v199;

v227:
    v189 = stack[-4];
    v188 = stack[-3];
    v189 = get(v189, v188);
    env = stack[-5];
    v188 = elt(env, 18); /* inbrackets */
    v188 = (v189 == v188 ? lisp_true : nil);
    goto v199;

v226:
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v199;

v198:
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v199;

v88:
    v188 = stack[-1];
    v188 = Lreverse(nil, v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v188 = qcar(v188);
    stack[-4] = v188;
    if (!consp(v188)) goto v228;
    v188 = stack[-4];
    v188 = qcar(v188);
    if (symbolp(v188)) goto v229;
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v58;

v229:
    v188 = stack[-4];
    fn = elt(env, 30); /* getrtype */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    stack[0] = v188;
    if (v188 == nil) goto v230;
    v189 = stack[0];
    v188 = elt(env, 14); /* tag */
    v189 = get(v189, v188);
    env = stack[-5];
    v188 = elt(env, 15); /* setprifn */
    v188 = get(v189, v188);
    env = stack[-5];
    stack[0] = v188;
    goto v58;

v230:
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v58;

v228:
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v58;

v48:
    v188 = stack[-3];
    fn = elt(env, 28); /* oprin */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v56;

v84:
    v188 = qvalue(elt(env, 10)); /* !*revpri */
    goto v65;

v192:
    v188 = qvalue(elt(env, 2)); /* !*nat */
    if (v188 == nil) goto v231;
    v188 = qvalue(elt(env, 4)); /* !*asterisk */
    v188 = (v188 == nil ? lisp_true : nil);
    goto v193;

v231:
    v188 = qvalue(elt(env, 3)); /* nil */
    goto v193;
/* error exit handlers */
v195:
    popv(6);
    return nil;
}



/* Code for dip_moncomp */

static Lisp_Object MS_CDECL CC_dip_moncomp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v109,
                         Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v232, v67;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dip_moncomp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_moncomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v192 = v15;
    v232 = v109;
    v67 = v0;
/* end of prologue */
    return list2star(v232, v67, v192);
}



/* Code for ombindir */

static Lisp_Object MS_CDECL CC_ombindir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ombindir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ombindir");
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
    fn = elt(env, 2); /* lex */
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    fn = elt(env, 3); /* omobj */
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    stack[-1] = v114;
    fn = elt(env, 2); /* lex */
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    fn = elt(env, 4); /* variablesir */
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    fn = elt(env, 5); /* tobvarir */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    stack[0] = v114;
    fn = elt(env, 2); /* lex */
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    fn = elt(env, 3); /* omobj */
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    stack[-2] = v114;
    fn = elt(env, 2); /* lex */
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v114 = elt(env, 1); /* (!/ o m b i n d) */
    fn = elt(env, 6); /* checktag */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v114 = stack[-2];
    v114 = ncons(v114);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v114 = Lappend(nil, stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v79;
    {
        Lisp_Object v78 = stack[-1];
        popv(4);
        return Lappend(nil, v78, v114);
    }
/* error exit handlers */
v79:
    popv(4);
    return nil;
}



/* Code for close_forall */

static Lisp_Object MS_CDECL CC_close_forall(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "close_forall");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for close_forall");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* end of prologue */
    v67 = qvalue(elt(env, 1)); /* flagg */
    v232 = (Lisp_Object)17; /* 1 */
    if (!(v67 == v232)) goto v14;
    v232 = elt(env, 2); /* "</apply>" */
    fn = elt(env, 3); /* printout */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    errexit();
    goto v14;

v14:
    v232 = nil;
    return onevalue(v232);
}



/* Code for indordl2 */

static Lisp_Object CC_indordl2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordl2");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v109;
    stack[-1] = v0;
/* end of prologue */
    v71 = stack[-1];
    v234 = stack[0];
    fn = elt(env, 1); /* indordlp */
    v234 = (*qfn2(fn))(qenv(fn), v71, v234);
    nil = C_nil;
    if (exception_pending()) goto v78;
    if (v234 == nil) goto v231;
    v71 = stack[-1];
    v234 = stack[0];
    popv(2);
    return list2(v71, v234);

v231:
    v71 = stack[0];
    v234 = stack[-1];
    popv(2);
    return list2(v71, v234);
/* error exit handlers */
v78:
    popv(2);
    return nil;
}



/* Code for ezgcdf1 */

static Lisp_Object CC_ezgcdf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v232, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ezgcdf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v232 = v109;
    v67 = v0;
/* end of prologue */
    v192 = (Lisp_Object)1; /* 0 */
    stack[0] = qvalue(elt(env, 1)); /* factor!-level */
    qvalue(elt(env, 1)) = v192; /* factor!-level */
    v192 = v67;
    v192 = list2(v192, v232);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    fn = elt(env, 2); /* gcdlist */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    fn = elt(env, 3); /* poly!-abs */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* factor!-level */
    { popv(2); return onevalue(v192); }
/* error exit handlers */
v68:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* factor!-level */
    popv(2);
    return nil;
}



/* Code for gvar1 */

static Lisp_Object CC_gvar1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v245, v87, v168, v246;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gvar1");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v87 = v109;
    v168 = v0;
/* end of prologue */

v11:
    v245 = v168;
    if (v245 == nil) goto v112;
    v245 = v168;
    v245 = (is_number(v245) ? lisp_true : nil);
    if (!(v245 == nil)) goto v111;
    v246 = v168;
    v245 = elt(env, 2); /* i */
    if (v246 == v245) goto v247;
    v245 = qvalue(elt(env, 4)); /* nil */
    goto v111;

v111:
    if (!(v245 == nil)) { popv(1); return onevalue(v87); }
    v245 = v168;
    if (!consp(v245)) goto v183;
    v245 = v168;
    v246 = qcar(v245);
    v245 = elt(env, 5); /* dname */
    v245 = get(v246, v245);
    env = stack[0];
    if (!(v245 == nil)) { popv(1); return onevalue(v87); }
    v245 = v168;
    v246 = qcar(v245);
    v245 = elt(env, 6); /* (plus times expt difference minus) */
    v245 = Lmemq(nil, v246, v245);
    if (v245 == nil) goto v55;
    v245 = v168;
    v245 = qcdr(v245);
    {
        popv(1);
        fn = elt(env, 8); /* gvarlis1 */
        return (*qfn2(fn))(qenv(fn), v245, v87);
    }

v55:
    v245 = v168;
    v246 = qcar(v245);
    v245 = elt(env, 7); /* quotient */
    if (v246 == v245) goto v248;
    v246 = v168;
    v245 = v87;
    v245 = Lmember(nil, v246, v245);
    if (!(v245 == nil)) { popv(1); return onevalue(v87); }
    v245 = v168;
    popv(1);
    return cons(v245, v87);

v248:
    v245 = v168;
    v245 = qcdr(v245);
    v245 = qcar(v245);
    v168 = v245;
    goto v11;

v183:
    v246 = v168;
    v245 = v87;
    v245 = Lmember(nil, v246, v245);
    if (!(v245 == nil)) { popv(1); return onevalue(v87); }
    v245 = v168;
    popv(1);
    return cons(v245, v87);

v247:
    v245 = qvalue(elt(env, 3)); /* !*complex */
    goto v111;

v112:
    v245 = qvalue(elt(env, 1)); /* t */
    goto v111;
}



/* Code for getavalue */

static Lisp_Object CC_getavalue(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v187;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getavalue");
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
    v80 = v0;
/* end of prologue */
    v187 = v80;
    v80 = elt(env, 1); /* avalue */
    v80 = get(v187, v80);
    env = stack[0];
    v187 = v80;
    v80 = v187;
    if (v80 == nil) goto v68;
    v80 = v187;
    v80 = qcdr(v80);
    v80 = qcar(v80);
    { popv(1); return onevalue(v80); }

v68:
    v80 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v80); }
}



/* Code for cl_f2ml */

static Lisp_Object CC_cl_f2ml(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v275, v276, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_f2ml");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v109;
    stack[0] = v0;
/* end of prologue */

v277:
    v275 = stack[0];
    if (!consp(v275)) goto v249;
    v275 = stack[0];
    v275 = qcar(v275);
    goto v278;

v278:
    v151 = v275;
    v276 = stack[0];
    v275 = elt(env, 1); /* true */
    if (v276 == v275) goto v80;
    v276 = stack[0];
    v275 = elt(env, 3); /* false */
    v275 = (v276 == v275 ? lisp_true : nil);
    goto v85;

v85:
    if (v275 == nil) goto v279;
    v275 = qvalue(elt(env, 4)); /* nil */
    { popv(6); return onevalue(v275); }

v279:
    v276 = v151;
    v275 = elt(env, 5); /* or */
    if (v276 == v275) goto v81;
    v276 = v151;
    v275 = elt(env, 6); /* and */
    v275 = (v276 == v275 ? lisp_true : nil);
    goto v280;

v280:
    if (v275 == nil) goto v177;
    v275 = qvalue(elt(env, 2)); /* t */
    goto v244;

v244:
    if (v275 == nil) goto v240;
    v275 = qvalue(elt(env, 2)); /* t */
    goto v182;

v182:
    if (v275 == nil) goto v281;
    v275 = stack[0];
    v275 = qcdr(v275);
    stack[-4] = v275;
    v275 = stack[-4];
    if (v275 == nil) goto v282;
    v275 = stack[-4];
    v275 = qcar(v275);
    v276 = v275;
    v275 = stack[-3];
    v275 = CC_cl_f2ml(env, v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v275 = ncons(v275);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    stack[-1] = v275;
    stack[-2] = v275;
    goto v283;

v283:
    v275 = stack[-4];
    v275 = qcdr(v275);
    stack[-4] = v275;
    v275 = stack[-4];
    if (v275 == nil) goto v171;
    stack[0] = stack[-1];
    v275 = stack[-4];
    v275 = qcar(v275);
    v276 = v275;
    v275 = stack[-3];
    v275 = CC_cl_f2ml(env, v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v275 = ncons(v275);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v275 = Lrplacd(nil, stack[0], v275);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v275 = stack[-1];
    v275 = qcdr(v275);
    stack[-1] = v275;
    goto v283;

v171:
    v275 = stack[-2];
    v276 = v275;
    goto v235;

v235:
    v275 = elt(env, 11); /* plus2 */
    {
        popv(6);
        fn = elt(env, 16); /* lto_almerge */
        return (*qfn2(fn))(qenv(fn), v276, v275);
    }

v282:
    v275 = qvalue(elt(env, 4)); /* nil */
    v276 = v275;
    goto v235;

v281:
    v276 = v151;
    v275 = elt(env, 12); /* ex */
    if (v276 == v275) goto v284;
    v276 = v151;
    v275 = elt(env, 13); /* all */
    v275 = (v276 == v275 ? lisp_true : nil);
    goto v157;

v157:
    if (v275 == nil) goto v285;
    v275 = stack[0];
    v275 = qcdr(v275);
    v275 = qcdr(v275);
    v276 = qcar(v275);
    v275 = stack[-3];
    stack[0] = v276;
    stack[-3] = v275;
    goto v277;

v285:
    v276 = v151;
    v275 = elt(env, 14); /* bex */
    if (v276 == v275) goto v286;
    v276 = v151;
    v275 = elt(env, 15); /* ball */
    v275 = (v276 == v275 ? lisp_true : nil);
    goto v287;

v287:
    if (v275 == nil) goto v27;
    v275 = stack[0];
    v275 = qcdr(v275);
    v275 = qcdr(v275);
    v276 = qcar(v275);
    v275 = stack[-3];
    stack[-1] = CC_cl_f2ml(env, v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v275 = stack[0];
    v275 = qcdr(v275);
    v275 = qcdr(v275);
    v275 = qcdr(v275);
    v276 = qcar(v275);
    v275 = stack[-3];
    v275 = CC_cl_f2ml(env, v276, v275);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v276 = list2(stack[-1], v275);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v275 = elt(env, 11); /* plus2 */
    {
        popv(6);
        fn = elt(env, 16); /* lto_almerge */
        return (*qfn2(fn))(qenv(fn), v276, v275);
    }

v27:
    stack[-1] = stack[-3];
    v275 = stack[0];
    v275 = ncons(v275);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    {
        Lisp_Object v26 = stack[-1];
        popv(6);
        fn = elt(env, 17); /* apply */
        return (*qfn2(fn))(qenv(fn), v26, v275);
    }

v286:
    v275 = qvalue(elt(env, 2)); /* t */
    goto v287;

v284:
    v275 = qvalue(elt(env, 2)); /* t */
    goto v157;

v240:
    v276 = v151;
    v275 = elt(env, 8); /* impl */
    if (v276 == v275) goto v196;
    v276 = v151;
    v275 = elt(env, 9); /* repl */
    if (v276 == v275) goto v288;
    v276 = v151;
    v275 = elt(env, 10); /* equiv */
    v275 = (v276 == v275 ? lisp_true : nil);
    goto v182;

v288:
    v275 = qvalue(elt(env, 2)); /* t */
    goto v182;

v196:
    v275 = qvalue(elt(env, 2)); /* t */
    goto v182;

v177:
    v276 = v151;
    v275 = elt(env, 7); /* not */
    v275 = (v276 == v275 ? lisp_true : nil);
    goto v244;

v81:
    v275 = qvalue(elt(env, 2)); /* t */
    goto v280;

v80:
    v275 = qvalue(elt(env, 2)); /* t */
    goto v85;

v249:
    v275 = stack[0];
    goto v278;
/* error exit handlers */
v25:
    popv(6);
    return nil;
}



/* Code for plusdf */

static Lisp_Object CC_plusdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v268, v263, v295;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plusdf");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v109;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v8;

v8:
    v268 = stack[-2];
    if (v268 == nil) goto v113;
    v268 = stack[-1];
    if (v268 == nil) goto v186;
    v268 = stack[-2];
    v268 = qcar(v268);
    v263 = qcar(v268);
    v268 = stack[-1];
    v268 = qcar(v268);
    v268 = qcar(v268);
    if (equal(v263, v268)) goto v296;
    v268 = stack[-2];
    v268 = qcar(v268);
    v263 = qcar(v268);
    v268 = stack[-1];
    v268 = qcar(v268);
    v268 = qcar(v268);
    fn = elt(env, 1); /* orddf */
    v268 = (*qfn2(fn))(qenv(fn), v263, v268);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-4];
    if (v268 == nil) goto v172;
    v268 = stack[-2];
    v263 = qcar(v268);
    v268 = stack[0];
    v268 = cons(v263, v268);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-4];
    stack[0] = v268;
    v268 = stack[-2];
    v268 = qcdr(v268);
    stack[-2] = v268;
    goto v8;

v172:
    v268 = stack[-1];
    v263 = qcar(v268);
    v268 = stack[0];
    v268 = cons(v263, v268);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-4];
    stack[0] = v268;
    v268 = stack[-1];
    v268 = qcdr(v268);
    stack[-1] = v268;
    goto v8;

v296:
    stack[-3] = stack[0];
    v268 = stack[-2];
    v268 = qcar(v268);
    v263 = qcdr(v268);
    v268 = stack[-1];
    v268 = qcar(v268);
    v268 = qcdr(v268);
    fn = elt(env, 2); /* !*addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v263, v268);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-4];
    v268 = stack[-2];
    v263 = qcdr(v268);
    v268 = stack[-1];
    v268 = qcdr(v268);
    v268 = CC_plusdf(env, v263, v268);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-4];
    v263 = stack[0];
    v295 = v263;
    v295 = qcar(v295);
    if (v295 == nil) goto v182;
    v295 = stack[-2];
    v295 = qcar(v295);
    v295 = qcar(v295);
    v268 = acons(v295, v263, v268);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-4];
    goto v182;

v182:
    {
        Lisp_Object v282 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v282, v268);
    }

v186:
    v263 = stack[0];
    v268 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v263, v268);
    }

v113:
    v263 = stack[0];
    v268 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v263, v268);
    }
/* error exit handlers */
v169:
    popv(5);
    return nil;
}



/* Code for qqe_simplterm!-tail */

static Lisp_Object CC_qqe_simpltermKtail(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v168, v246;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplterm-tail");
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
    v87 = stack[-2];
    fn = elt(env, 8); /* qqe_arg2l */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-4];
    stack[-3] = v87;
    v168 = stack[-3];
    v87 = elt(env, 1); /* qepsilon */
    if (v168 == v87) goto v111;
    v87 = stack[-3];
    if (!consp(v87)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v87 = stack[-2];
    fn = elt(env, 9); /* qqe_op */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-4];
    stack[-1] = v87;
    v87 = stack[-3];
    fn = elt(env, 9); /* qqe_op */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-4];
    stack[0] = v87;
    v168 = stack[0];
    v87 = elt(env, 2); /* (ladd radd) */
    v87 = Lmemq(nil, v168, v87);
    if (v87 == nil) goto v233;
    v87 = stack[-3];
    fn = elt(env, 10); /* qqe_arg2r */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-4];
    v246 = v87;
    v168 = v246;
    v87 = elt(env, 1); /* qepsilon */
    if (v168 == v87) goto v183;
    v168 = stack[-1];
    v87 = elt(env, 3); /* ltail */
    if (v168 == v87) goto v301;
    v87 = qvalue(elt(env, 5)); /* nil */
    goto v279;

v279:
    if (!(v87 == nil)) { popv(5); return onevalue(v246); }
    v168 = stack[-1];
    v87 = elt(env, 6); /* rtail */
    if (v168 == v87) goto v291;
    v87 = qvalue(elt(env, 5)); /* nil */
    goto v302;

v302:
    if (!(v87 == nil)) { popv(5); return onevalue(v246); }

v233:
    v87 = stack[-3];
    fn = elt(env, 11); /* qqe_simplterm */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-4];
    v246 = v87;
    v168 = v246;
    v87 = stack[-3];
    if (equal(v168, v87)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v87 = stack[-1];
    v168 = v246;
    v87 = list2(v87, v168);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 11); /* qqe_simplterm */
        return (*qfn1(fn))(qenv(fn), v87);
    }

v291:
    v168 = stack[0];
    v87 = elt(env, 7); /* ladd */
    v87 = (v168 == v87 ? lisp_true : nil);
    goto v302;

v301:
    v168 = stack[0];
    v87 = elt(env, 4); /* radd */
    v87 = (v168 == v87 ? lisp_true : nil);
    goto v279;

v183:
    v87 = elt(env, 1); /* qepsilon */
    { popv(5); return onevalue(v87); }

v111:
    v87 = elt(env, 1); /* qepsilon */
    { popv(5); return onevalue(v87); }
/* error exit handlers */
v90:
    popv(5);
    return nil;
}



/* Code for cl_susicpknowl */

static Lisp_Object CC_cl_susicpknowl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v305, v306;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susicpknowl");
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
    v305 = v0;
/* end of prologue */
    stack[-3] = v305;
    v305 = stack[-3];
    if (v305 == nil) goto v111;
    v305 = stack[-3];
    v305 = qcar(v305);
    v306 = v305;
    v306 = qcar(v306);
    v305 = qcdr(v305);
    v305 = cons(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    v305 = ncons(v305);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    stack[-1] = v305;
    stack[-2] = v305;
    goto v278;

v278:
    v305 = stack[-3];
    v305 = qcdr(v305);
    stack[-3] = v305;
    v305 = stack[-3];
    if (v305 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v305 = stack[-3];
    v305 = qcar(v305);
    v306 = v305;
    v306 = qcar(v306);
    v305 = qcdr(v305);
    v305 = cons(v306, v305);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    v305 = ncons(v305);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    v305 = Lrplacd(nil, stack[0], v305);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    v305 = stack[-1];
    v305 = qcdr(v305);
    stack[-1] = v305;
    goto v278;

v111:
    v305 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v305); }
/* error exit handlers */
v179:
    popv(5);
    return nil;
}



/* Code for alg_plus */

static Lisp_Object CC_alg_plus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v69, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for alg_plus");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v67 = v109;
    v69 = v0;
/* end of prologue */
    v68 = elt(env, 1); /* plus */
    v67 = list3(v68, v69, v67);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* aeval */
        return (*qfn1(fn))(qenv(fn), v67);
    }
/* error exit handlers */
v62:
    popv(1);
    return nil;
}



/* Code for insoccs */

static Lisp_Object CC_insoccs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insoccs");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v109;
    stack[-1] = v0;
/* end of prologue */
    v65 = stack[-1];
    if (symbolp(v65)) goto v186;
    v65 = stack[-1];
    fn = elt(env, 2); /* subscriptedvarp */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-2];
    if (!(v65 == nil)) goto v186;
    v65 = stack[-1];
    v65 = Lconsp(nil, v65);
    env = stack[-2];
    if (v65 == nil) goto v8;
    v65 = stack[-1];
    v65 = qcar(v65);
    fn = elt(env, 2); /* subscriptedvarp */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-2];
    if (!(v65 == nil)) goto v186;

v8:
    v65 = stack[-1];
    if (symbolp(v65)) goto v294;
    v65 = stack[-1];
    fn = elt(env, 3); /* constp */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-2];
    v65 = (v65 == nil ? lisp_true : nil);
    goto v79;

v79:
    if (v65 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v65 = stack[-1];
    v65 = qcdr(v65);
    stack[-1] = v65;
    goto v76;

v76:
    v65 = stack[-1];
    if (v65 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v65 = stack[-1];
    v65 = qcar(v65);
    v84 = v65;
    v65 = stack[0];
    v65 = CC_insoccs(env, v84, v65);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-2];
    stack[0] = v65;
    v65 = stack[-1];
    v65 = qcdr(v65);
    stack[-1] = v65;
    goto v76;

v294:
    v65 = qvalue(elt(env, 1)); /* nil */
    goto v79;

v186:
    v84 = stack[0];
    v65 = stack[-1];
    fn = elt(env, 4); /* insertocc */
    v65 = (*qfn2(fn))(qenv(fn), v84, v65);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-2];
    stack[0] = v65;
    goto v8;
/* error exit handlers */
v307:
    popv(3);
    return nil;
}



/* Code for critical_element */

static Lisp_Object CC_critical_element(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v113;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for critical_element");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v112 = v0;
/* end of prologue */
    v113 = v112;
    v113 = qcdr(v113);
    v113 = qcar(v113);
        return Lapply1(nil, v113, v112);
}



/* Code for statep */

static Lisp_Object CC_statep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v306, v293, v242;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for statep");
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
    v293 = v0;
/* end of prologue */
    v306 = v293;
    if (symbolp(v306)) goto v68;
    v306 = qvalue(elt(env, 1)); /* nil */
    goto v8;

v8:
    if (!(v306 == nil)) { popv(1); return onevalue(v306); }
    v306 = v293;
    if (!consp(v306)) goto v299;
    v306 = v293;
    v306 = qcar(v306);
    if (symbolp(v306)) goto v182;
    v306 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v306); }

v182:
    v306 = v293;
    v293 = qcar(v306);
    v306 = elt(env, 2); /* phystype */
    v306 = get(v293, v306);
    env = stack[0];
    v293 = elt(env, 3); /* state */
    v306 = (v306 == v293 ? lisp_true : nil);
    { popv(1); return onevalue(v306); }

v299:
    v306 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v306); }

v68:
    v242 = v293;
    v306 = elt(env, 2); /* phystype */
    v242 = get(v242, v306);
    env = stack[0];
    v306 = elt(env, 3); /* state */
    v306 = (v242 == v306 ? lisp_true : nil);
    goto v8;
}



/* Code for l!-subst */

static Lisp_Object MS_CDECL CC_lKsubst(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v109,
                         Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v76, v290;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "l-subst");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for l-subst");
#endif
    if (stack >= stacklimit)
    {
        push3(v15,v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v109,v15);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v15;
    stack[-1] = v109;
    stack[-2] = v0;
/* end of prologue */
    v290 = nil;
    goto v278;

v278:
    v182 = stack[0];
    if (v182 == nil) goto v110;
    v76 = stack[-1];
    v182 = stack[0];
    v182 = qcar(v182);
    if (equal(v76, v182)) goto v231;
    v182 = stack[0];
    v182 = qcar(v182);
    v76 = v290;
    v182 = cons(v182, v76);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    v290 = v182;
    v182 = stack[0];
    v182 = qcdr(v182);
    stack[0] = v182;
    goto v278;

v231:
    v182 = stack[-2];
    v76 = v290;
    v182 = cons(v182, v76);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-3];
    v290 = v182;
    v182 = stack[0];
    v182 = qcdr(v182);
    stack[0] = v182;
    goto v278;

v110:
    v182 = v290;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v182);
    }
/* error exit handlers */
v184:
    popv(4);
    return nil;
}



/* Code for groeb!=newpair */

static Lisp_Object MS_CDECL CC_groebMnewpair(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v109,
                         Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v76, v290;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groeb=newpair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=newpair");
#endif
    if (stack >= stacklimit)
    {
        push3(v15,v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v109,v15);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v15;
    stack[-3] = v109;
    stack[-1] = v0;
/* end of prologue */
    v182 = stack[-3];
    fn = elt(env, 1); /* bas_dpoly */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    fn = elt(env, 2); /* dp_lmon */
    stack[0] = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    v182 = stack[-2];
    fn = elt(env, 1); /* bas_dpoly */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    fn = elt(env, 2); /* dp_lmon */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    fn = elt(env, 3); /* mo_lcm */
    v182 = (*qfn2(fn))(qenv(fn), stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    stack[0] = v182;
    stack[-4] = stack[-1];
    v290 = stack[0];
    v76 = stack[-3];
    v182 = stack[-2];
    fn = elt(env, 4); /* groeb!=weight */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v290, v76, v182);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    v76 = stack[-3];
    v182 = stack[-2];
    v182 = list2(v76, v182);
    nil = C_nil;
    if (exception_pending()) goto v280;
    {
        Lisp_Object v81 = stack[-4];
        Lisp_Object v299 = stack[-1];
        Lisp_Object v279 = stack[0];
        popv(6);
        return list3star(v81, v299, v279, v182);
    }
/* error exit handlers */
v280:
    popv(6);
    return nil;
}



/* Code for clean_numid */

static Lisp_Object CC_clean_numid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clean_numid");
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
    goto v11;

v11:
    v234 = stack[0];
    if (v234 == nil) goto v249;
    v234 = stack[0];
    v234 = qcar(v234);
    fn = elt(env, 1); /* !*id2num */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    if (v234 == nil) goto v187;
    v234 = stack[0];
    v234 = qcdr(v234);
    stack[0] = v234;
    goto v11;

v187:
    v234 = stack[0];
    v71 = qcar(v234);
    v234 = stack[-1];
    v234 = cons(v71, v234);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    stack[-1] = v234;
    v234 = stack[0];
    v234 = qcdr(v234);
    stack[0] = v234;
    goto v11;

v249:
    v234 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v234);
    }
/* error exit handlers */
v78:
    popv(3);
    return nil;
}



/* Code for modp */

static Lisp_Object CC_modp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modp");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v109;
    stack[-1] = v0;
/* end of prologue */
    v70 = stack[-1];
    v71 = stack[0];
    v71 = Cremainder(v70, v71);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    stack[-1] = v71;
    v70 = stack[-1];
    v71 = (Lisp_Object)1; /* 0 */
    v71 = (Lisp_Object)lessp2(v70, v71);
    nil = C_nil;
    if (exception_pending()) goto v117;
    v71 = v71 ? lisp_true : nil;
    if (v71 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v70 = stack[-1];
    v71 = stack[0];
    popv(3);
    return plus2(v70, v71);
/* error exit handlers */
v117:
    popv(3);
    return nil;
}



/* Code for ratlessp */

static Lisp_Object CC_ratlessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratlessp");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v68 = v109;
    v62 = v0;
/* end of prologue */
    fn = elt(env, 1); /* ratdif */
    v68 = (*qfn2(fn))(qenv(fn), v62, v68);
    errexit();
    v62 = qcar(v68);
    v68 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v62, v68);
}



/* Code for horner!-rule!-for!-one!-var */

static Lisp_Object MS_CDECL CC_hornerKruleKforKoneKvar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v109,
                         Lisp_Object v15, Lisp_Object v18,
                         Lisp_Object v14, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v312, v313, v171, v54, v53, v228, v314;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "horner-rule-for-one-var");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule-for-one-var");
#endif
    if (stack >= stacklimit)
    {
        push5(v14,v18,v15,v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v109,v15,v18,v14);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v313 = v14;
    v171 = v18;
    v54 = v15;
    v53 = v109;
    v228 = v0;
/* end of prologue */

v277:
    v312 = v228;
    if (!consp(v312)) goto v232;
    v312 = v228;
    v312 = qcar(v312);
    v312 = (consp(v312) ? nil : lisp_true);
    goto v192;

v192:
    if (v312 == nil) goto v304;
    v312 = qvalue(elt(env, 1)); /* t */
    goto v111;

v111:
    if (v312 == nil) goto v315;
    v312 = v54;
    v312 = (Lisp_Object)zerop(v312);
    v312 = v312 ? lisp_true : nil;
    env = stack[-6];
    if (!(v312 == nil)) { popv(7); return onevalue(v228); }
    stack[-1] = v228;
    stack[0] = v171;
    v312 = v54;
    v312 = Lexpt(nil, v312, v313);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-6];
    v313 = v312;
    v312 = v313;
    v312 = (Lisp_Object)zerop(v312);
    v312 = v312 ? lisp_true : nil;
    env = stack[-6];
    if (v312 == nil) goto v316;
    v312 = qvalue(elt(env, 2)); /* nil */
    goto v305;

v305:
    fn = elt(env, 3); /* multf */
    v312 = (*qfn2(fn))(qenv(fn), stack[0], v312);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-6];
    {
        Lisp_Object v317 = stack[-1];
        popv(7);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v317, v312);
    }

v316:
    v312 = v313;
    goto v305;

v315:
    v312 = v228;
    v312 = qcar(v312);
    v312 = qcar(v312);
    v312 = qcdr(v312);
    stack[-5] = v312;
    v312 = v228;
    stack[-4] = qcdr(v312);
    stack[-3] = v53;
    stack[-2] = v54;
    v312 = v54;
    v312 = (Lisp_Object)zerop(v312);
    v312 = v312 ? lisp_true : nil;
    env = stack[-6];
    if (v312 == nil) goto v289;
    v312 = v228;
    v312 = qcar(v312);
    v312 = qcdr(v312);
    v313 = v312;
    goto v57;

v57:
    v312 = stack[-5];
    v228 = stack[-4];
    v53 = stack[-3];
    v54 = stack[-2];
    v171 = v313;
    v313 = v312;
    goto v277;

v289:
    v312 = v228;
    v312 = qcar(v312);
    stack[-1] = qcdr(v312);
    stack[0] = v171;
    v171 = v54;
    v312 = stack[-5];
    v312 = (Lisp_Object)(int32_t)((int32_t)v313 - (int32_t)v312 + TAG_FIXNUM);
    v312 = Lexpt(nil, v171, v312);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-6];
    v313 = v312;
    v312 = v313;
    v312 = (Lisp_Object)zerop(v312);
    v312 = v312 ? lisp_true : nil;
    env = stack[-6];
    if (v312 == nil) goto v170;
    v312 = qvalue(elt(env, 2)); /* nil */
    goto v245;

v245:
    fn = elt(env, 3); /* multf */
    v312 = (*qfn2(fn))(qenv(fn), stack[0], v312);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-6];
    fn = elt(env, 4); /* addf */
    v312 = (*qfn2(fn))(qenv(fn), stack[-1], v312);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-6];
    v313 = v312;
    goto v57;

v170:
    v312 = v313;
    goto v245;

v304:
    v312 = v228;
    v312 = qcar(v312);
    v312 = qcar(v312);
    v314 = qcar(v312);
    v312 = v53;
    v312 = (equal(v314, v312) ? lisp_true : nil);
    v312 = (v312 == nil ? lisp_true : nil);
    goto v111;

v232:
    v312 = qvalue(elt(env, 1)); /* t */
    goto v192;
/* error exit handlers */
v265:
    popv(7);
    return nil;
}



/* Code for formbool */

static Lisp_Object MS_CDECL CC_formbool(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v109,
                         Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v98, v334, v335, v336;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formbool");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formbool");
#endif
    if (stack >= stacklimit)
    {
        push3(v15,v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v109,v15);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v15;
    stack[-3] = v109;
    stack[-4] = v0;
/* end of prologue */
    v98 = stack[-2];
    v151 = elt(env, 1); /* symbolic */
    if (v98 == v151) goto v232;
    v151 = stack[-4];
    if (!consp(v151)) goto v234;
    v151 = stack[-4];
    v98 = qcdr(v151);
    v151 = stack[-3];
    fn = elt(env, 11); /* intexprlisp */
    v151 = (*qfn2(fn))(qenv(fn), v98, v151);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-6];
    if (v151 == nil) goto v338;
    v151 = stack[-4];
    v98 = qcar(v151);
    v151 = elt(env, 4); /* boolfn */
    v151 = get(v98, v151);
    env = stack[-6];
    if (!(v151 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }

v338:
    v151 = stack[-4];
    v151 = qcar(v151);
    if (!(symbolp(v151))) goto v339;
    v151 = stack[-4];
    v98 = qcar(v151);
    v151 = elt(env, 4); /* boolfn */
    v151 = get(v98, v151);
    env = stack[-6];
    if (v151 == nil) goto v339;
    v151 = stack[-4];
    v98 = qcar(v151);
    v151 = elt(env, 4); /* boolfn */
    stack[0] = get(v98, v151);
    env = stack[-6];
    v151 = stack[-4];
    v334 = qcdr(v151);
    v98 = stack[-3];
    v151 = stack[-2];
    fn = elt(env, 12); /* formclis */
    v151 = (*qfnn(fn))(qenv(fn), 3, v334, v98, v151);
    nil = C_nil;
    if (exception_pending()) goto v337;
    {
        Lisp_Object v150 = stack[0];
        popv(7);
        return cons(v150, v151);
    }

v339:
    v151 = stack[-4];
    v151 = qcar(v151);
    if (!(symbolp(v151))) goto v36;
    v151 = stack[-4];
    v98 = qcar(v151);
    v151 = elt(env, 5); /* boolean */
    v151 = Lflagp(nil, v98, v151);
    env = stack[-6];
    if (v151 == nil) goto v36;
    v151 = stack[-4];
    stack[0] = qcar(v151);
    v151 = stack[-4];
    v336 = qcdr(v151);
    v335 = stack[-3];
    v334 = stack[-2];
    v151 = stack[-4];
    v98 = qcar(v151);
    v151 = elt(env, 6); /* boolargs */
    v151 = Lflagp(nil, v98, v151);
    env = stack[-6];
    fn = elt(env, 13); /* formboollis */
    v151 = (*qfnn(fn))(qenv(fn), 4, v336, v335, v334, v151);
    nil = C_nil;
    if (exception_pending()) goto v337;
    {
        Lisp_Object v340 = stack[0];
        popv(7);
        return cons(v340, v151);
    }

v36:
    v151 = stack[-4];
    v98 = qcar(v151);
    v151 = elt(env, 3); /* boolvalue!* */
    if (v98 == v151) goto v45;
    v151 = stack[-4];
    v98 = qcar(v151);
    v151 = elt(env, 9); /* where */
    if (v98 == v151) goto v41;
    stack[0] = elt(env, 3); /* boolvalue!* */
    v334 = stack[-4];
    v98 = stack[-3];
    v151 = stack[-2];
    fn = elt(env, 14); /* formc!* */
    v151 = (*qfnn(fn))(qenv(fn), 3, v334, v98, v151);
    nil = C_nil;
    if (exception_pending()) goto v337;
    {
        Lisp_Object v23 = stack[0];
        popv(7);
        return list2(v23, v151);
    }

v41:
    stack[-5] = elt(env, 3); /* boolvalue!* */
    stack[-1] = elt(env, 9); /* where */
    stack[0] = elt(env, 10); /* bool!-eval */
    v151 = stack[-4];
    v151 = qcdr(v151);
    v334 = qcar(v151);
    v98 = stack[-3];
    v151 = stack[-2];
    v151 = CC_formbool(env, 3, v334, v98, v151);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-6];
    v151 = list2(stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-6];
    v98 = Lmkquote(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-6];
    v151 = stack[-4];
    v151 = qcdr(v151);
    v151 = qcdr(v151);
    v151 = qcar(v151);
    v334 = list3(stack[-1], v98, v151);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-6];
    v98 = stack[-3];
    v151 = stack[-2];
    fn = elt(env, 14); /* formc!* */
    v151 = (*qfnn(fn))(qenv(fn), 3, v334, v98, v151);
    nil = C_nil;
    if (exception_pending()) goto v337;
    {
        Lisp_Object v24 = stack[-5];
        popv(7);
        return list2(v24, v151);
    }

v45:
    v151 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v151 == nil)) goto v341;
    v151 = elt(env, 8); /* "Too many formbools" */
    fn = elt(env, 15); /* lprie */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-6];
    goto v341;

v341:
    v151 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v337;
    v151 = nil;
    { popv(7); return onevalue(v151); }

v234:
    v98 = stack[-4];
    v151 = lisp_true;
    if (v98 == v151) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v151 = stack[-4];
    if (symbolp(v151)) goto v243;
    v151 = qvalue(elt(env, 2)); /* t */
    goto v303;

v303:
    if (v151 == nil) goto v292;
    v98 = elt(env, 3); /* boolvalue!* */
    v151 = stack[-4];
    popv(7);
    return list2(v98, v151);

v292:
    stack[0] = elt(env, 3); /* boolvalue!* */
    v334 = stack[-4];
    v98 = stack[-3];
    v151 = stack[-2];
    fn = elt(env, 14); /* formc!* */
    v151 = (*qfnn(fn))(qenv(fn), 3, v334, v98, v151);
    nil = C_nil;
    if (exception_pending()) goto v337;
    {
        Lisp_Object v342 = stack[0];
        popv(7);
        return list2(v342, v151);
    }

v243:
    v98 = stack[-4];
    v151 = stack[-3];
    v151 = Latsoc(nil, v98, v151);
    goto v303;

v232:
    v334 = stack[-4];
    v98 = stack[-3];
    v151 = stack[-2];
    {
        popv(7);
        fn = elt(env, 16); /* formc */
        return (*qfnn(fn))(qenv(fn), 3, v334, v98, v151);
    }
/* error exit handlers */
v337:
    popv(7);
    return nil;
}



/* Code for cquotegex */

static Lisp_Object CC_cquotegex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v249;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cquotegex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v249 = v0;
/* end of prologue */
    v249 = qvalue(elt(env, 1)); /* !*guardian */
    if (v249 == nil) goto v11;
    v249 = elt(env, 2); /* gex */
    return onevalue(v249);

v11:
    v249 = nil;
    return onevalue(v249);
}



/* Code for lambdaom */

static Lisp_Object CC_lambdaom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambdaom");
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
    v117 = v0;
/* end of prologue */
    v78 = v117;
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    v78 = qcar(v78);
    v78 = qcdr(v78);
    v78 = qcar(v78);
    stack[-1] = v78;
    v78 = v117;
    v78 = Lreverse(nil, v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-2];
    v78 = qcar(v78);
    stack[0] = v78;
    v78 = elt(env, 1); /* "<OMBIND>" */
    fn = elt(env, 8); /* printout */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-2];
    v78 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 9); /* indent!* */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-2];
    v78 = elt(env, 3); /* "<OMS cd=""fns1"" name=""lambda""/>" */
    fn = elt(env, 8); /* printout */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-2];
    v78 = elt(env, 4); /* "<OMBVAR>" */
    fn = elt(env, 8); /* printout */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-2];
    v78 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 9); /* indent!* */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-2];
    v78 = stack[-1];
    fn = elt(env, 10); /* objectom */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-2];
    v78 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 9); /* indent!* */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-2];
    v78 = elt(env, 6); /* "</OMBVAR>" */
    fn = elt(env, 8); /* printout */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-2];
    v78 = stack[0];
    fn = elt(env, 10); /* objectom */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-2];
    v78 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 9); /* indent!* */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-2];
    v78 = elt(env, 7); /* "</OMBIND>" */
    fn = elt(env, 8); /* printout */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v343;
    v78 = nil;
    { popv(3); return onevalue(v78); }
/* error exit handlers */
v343:
    popv(3);
    return nil;
}



/* Code for crn!:zerop */

static Lisp_Object CC_crnTzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v116, v114;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:zerop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v114 = v0;
/* end of prologue */
    v233 = v114;
    v233 = qcdr(v233);
    v233 = qcar(v233);
    v116 = qcar(v233);
    v233 = (Lisp_Object)1; /* 0 */
    if (v116 == v233) goto v232;
    v233 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v233);

v232:
    v233 = v114;
    v233 = qcdr(v233);
    v233 = qcdr(v233);
    v116 = qcar(v233);
    v233 = (Lisp_Object)1; /* 0 */
    v233 = (v116 == v233 ? lisp_true : nil);
    return onevalue(v233);
}



/* Code for mkmatrix */

static Lisp_Object CC_mkmatrix(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v269, v347;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkmatrix");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v109;
    stack[-9] = v0;
/* end of prologue */
    stack[-10] = elt(env, 1); /* mat */
    v269 = (Lisp_Object)17; /* 1 */
    stack[-7] = v269;
    v347 = stack[-9];
    v269 = stack[-7];
    v269 = difference2(v347, v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = Lminusp(nil, v269);
    env = stack[-11];
    if (v269 == nil) goto v69;
    v269 = qvalue(elt(env, 2)); /* nil */
    goto v278;

v278:
    {
        Lisp_Object v349 = stack[-10];
        popv(12);
        return cons(v349, v269);
    }

v69:
    v269 = (Lisp_Object)17; /* 1 */
    stack[-3] = v269;
    v347 = stack[-8];
    v269 = stack[-3];
    v269 = difference2(v347, v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = Lminusp(nil, v269);
    env = stack[-11];
    if (v269 == nil) goto v273;
    v269 = qvalue(elt(env, 2)); /* nil */
    goto v79;

v79:
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    stack[-5] = v269;
    stack[-6] = v269;
    goto v192;

v192:
    v269 = stack[-7];
    v269 = add1(v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    stack[-7] = v269;
    v347 = stack[-9];
    v269 = stack[-7];
    v269 = difference2(v347, v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = Lminusp(nil, v269);
    env = stack[-11];
    if (v269 == nil) goto v55;
    v269 = stack[-6];
    goto v278;

v55:
    stack[-4] = stack[-5];
    v269 = (Lisp_Object)17; /* 1 */
    stack[-3] = v269;
    v347 = stack[-8];
    v269 = stack[-3];
    v269 = difference2(v347, v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = Lminusp(nil, v269);
    env = stack[-11];
    if (v269 == nil) goto v271;
    v269 = qvalue(elt(env, 2)); /* nil */
    goto v174;

v174:
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = Lrplacd(nil, stack[-4], v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = stack[-5];
    v269 = qcdr(v269);
    stack[-5] = v269;
    goto v192;

v271:
    v269 = (Lisp_Object)1; /* 0 */
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    stack[-1] = v269;
    stack[-2] = v269;
    goto v339;

v339:
    v269 = stack[-3];
    v269 = add1(v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    stack[-3] = v269;
    v347 = stack[-8];
    v269 = stack[-3];
    v269 = difference2(v347, v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = Lminusp(nil, v269);
    env = stack[-11];
    if (v269 == nil) goto v309;
    v269 = stack[-2];
    goto v174;

v309:
    stack[0] = stack[-1];
    v269 = (Lisp_Object)1; /* 0 */
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = Lrplacd(nil, stack[0], v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = stack[-1];
    v269 = qcdr(v269);
    stack[-1] = v269;
    goto v339;

v273:
    v269 = (Lisp_Object)1; /* 0 */
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    stack[-1] = v269;
    stack[-2] = v269;
    goto v78;

v78:
    v269 = stack[-3];
    v269 = add1(v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    stack[-3] = v269;
    v347 = stack[-8];
    v269 = stack[-3];
    v269 = difference2(v347, v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = Lminusp(nil, v269);
    env = stack[-11];
    if (v269 == nil) goto v65;
    v269 = stack[-2];
    goto v79;

v65:
    stack[0] = stack[-1];
    v269 = (Lisp_Object)1; /* 0 */
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = Lrplacd(nil, stack[0], v269);
    nil = C_nil;
    if (exception_pending()) goto v348;
    env = stack[-11];
    v269 = stack[-1];
    v269 = qcdr(v269);
    stack[-1] = v269;
    goto v78;
/* error exit handlers */
v348:
    popv(12);
    return nil;
}



/* Code for redcodmat */

static Lisp_Object MS_CDECL CC_redcodmat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v247;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "redcodmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redcodmat");
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
    v186 = qvalue(elt(env, 1)); /* rowmin */
    stack[0] = v186;
    goto v112;

v112:
    v247 = qvalue(elt(env, 2)); /* rowmax */
    v186 = stack[0];
    v186 = difference2(v247, v186);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v186 = Lminusp(nil, v186);
    env = stack[-1];
    if (v186 == nil) goto v278;
    v186 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v186); }

v278:
    v186 = stack[0];
    fn = elt(env, 4); /* testred */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v186 = stack[0];
    v186 = add1(v186);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    stack[0] = v186;
    goto v112;
/* error exit handlers */
v75:
    popv(2);
    return nil;
}



/* Code for dipev2f */

static Lisp_Object CC_dipev2f(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v299, v279, v305;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipev2f");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v109;
    stack[-1] = v0;
/* end of prologue */

v11:
    v299 = stack[-1];
    if (v299 == nil) goto v249;
    v299 = stack[-1];
    v279 = qcar(v299);
    v299 = (Lisp_Object)1; /* 0 */
    if (v279 == v299) goto v112;
    v299 = stack[0];
    v305 = qcar(v299);
    v299 = stack[-1];
    v279 = qcar(v299);
    v299 = (Lisp_Object)17; /* 1 */
    v299 = acons(v305, v279, v299);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    stack[-2] = ncons(v299);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    v299 = stack[-1];
    v279 = qcdr(v299);
    v299 = stack[0];
    v299 = qcdr(v299);
    v299 = CC_dipev2f(env, v279, v299);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    {
        Lisp_Object v178 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* multf */
        return (*qfn2(fn))(qenv(fn), v178, v299);
    }

v112:
    v299 = stack[-1];
    v299 = qcdr(v299);
    stack[-1] = v299;
    v299 = stack[0];
    v299 = qcdr(v299);
    stack[0] = v299;
    goto v11;

v249:
    v299 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v299); }
/* error exit handlers */
v180:
    popv(4);
    return nil;
}



/* Code for evinvlexcomp */

static Lisp_Object CC_evinvlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v338, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evinvlexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v109;
    stack[-1] = v0;
/* end of prologue */

v11:
    v338 = stack[-1];
    if (v338 == nil) goto v249;
    v338 = stack[0];
    if (v338 == nil) goto v186;
    v338 = stack[-1];
    v197 = qcar(v338);
    v338 = stack[0];
    v338 = qcar(v338);
    v338 = Leqn(nil, v197, v338);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    if (v338 == nil) goto v290;
    v338 = stack[-1];
    v338 = qcdr(v338);
    stack[-1] = v338;
    v338 = stack[0];
    v338 = qcdr(v338);
    stack[0] = v338;
    goto v11;

v290:
    v338 = stack[-1];
    v197 = qcdr(v338);
    v338 = stack[0];
    v338 = qcdr(v338);
    v338 = CC_evinvlexcomp(env, v197, v338);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    stack[-2] = v338;
    v197 = stack[-2];
    v338 = (Lisp_Object)1; /* 0 */
    v338 = Leqn(nil, v197, v338);
    nil = C_nil;
    if (exception_pending()) goto v196;
    if (v338 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v338 = stack[0];
    v197 = qcar(v338);
    v338 = stack[-1];
    v338 = qcar(v338);
    if (((int32_t)(v197)) > ((int32_t)(v338))) goto v84;
    v338 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v338); }

v84:
    v338 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v338); }

v186:
    v197 = stack[-1];
    v338 = elt(env, 1); /* (0) */
    {
        popv(4);
        fn = elt(env, 2); /* evlexcomp */
        return (*qfn2(fn))(qenv(fn), v197, v338);
    }

v249:
    v338 = stack[0];
    if (v338 == nil) goto v113;
    v338 = elt(env, 1); /* (0) */
    stack[-1] = v338;
    goto v11;

v113:
    v338 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v338); }
/* error exit handlers */
v196:
    popv(4);
    return nil;
}



/* Code for getrlist */

static Lisp_Object CC_getrlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v306, v293, v242;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrlist");
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
    v242 = v0;
/* end of prologue */
    v293 = v242;
    v306 = elt(env, 1); /* list */
    if (!consp(v293)) goto v115;
    v293 = qcar(v293);
    if (!(v293 == v306)) goto v115;
    v306 = v242;
    v306 = qcdr(v306);
    { popv(1); return onevalue(v306); }

v115:
    v293 = v242;
    v306 = elt(env, 2); /* !*sq */
    if (!consp(v293)) goto v81;
    v293 = qcar(v293);
    if (!(v293 == v306)) goto v81;
    v306 = v242;
    v306 = qcdr(v306);
    v306 = qcar(v306);
    v306 = qcar(v306);
    if (v306 == nil) goto v117;
    v306 = v242;
    v306 = qcdr(v306);
    v293 = qcar(v306);
    v306 = elt(env, 3); /* prepf */
    fn = elt(env, 5); /* sqform */
    v306 = (*qfn2(fn))(qenv(fn), v293, v306);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[0];
    goto v78;

v78:
    v293 = v306;
    goto v85;

v85:
    v306 = elt(env, 4); /* "list" */
    {
        popv(1);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v293, v306);
    }

v117:
    v306 = (Lisp_Object)1; /* 0 */
    goto v78;

v81:
    v306 = v242;
    v293 = v306;
    goto v85;
/* error exit handlers */
v180:
    popv(1);
    return nil;
}



/* Code for lispreadp */

static Lisp_Object CC_lispreadp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v111;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispreadp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v110 = v0;
/* end of prologue */
    v111 = elt(env, 1); /* read */
        return Leqcar(nil, v110, v111);
}



/* Code for red_topred */

static Lisp_Object CC_red_topred(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_topred");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v109;
    stack[-1] = v0;
/* end of prologue */
    v241 = stack[0];
    fn = elt(env, 4); /* bas_dpoly */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-3];
    if (v241 == nil) goto v118;
    v241 = stack[-1];
    v241 = (v241 == nil ? lisp_true : nil);
    goto v249;

v249:
    if (!(v241 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v82 = stack[-1];
    v241 = stack[0];
    fn = elt(env, 5); /* red_topredbe */
    v241 = (*qfn2(fn))(qenv(fn), v82, v241);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-3];
    stack[0] = v241;
    goto v70;

v70:
    v241 = stack[0];
    fn = elt(env, 4); /* bas_dpoly */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-3];
    v82 = v241;
    if (v241 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    stack[-2] = stack[-1];
    v241 = v82;
    fn = elt(env, 6); /* dp_lmon */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-3];
    fn = elt(env, 7); /* red_divtest */
    v241 = (*qfn2(fn))(qenv(fn), stack[-2], v241);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-3];
    stack[-2] = v241;
    if (v241 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v82 = stack[0];
    v241 = stack[-2];
    fn = elt(env, 8); /* red_subst */
    v241 = (*qfn2(fn))(qenv(fn), v82, v241);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-3];
    stack[-2] = v241;
    v241 = qvalue(elt(env, 3)); /* !*noetherian */
    if (!(v241 == nil)) goto v307;
    v82 = stack[-1];
    v241 = stack[0];
    fn = elt(env, 9); /* red_update */
    v241 = (*qfn2(fn))(qenv(fn), v82, v241);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-3];
    stack[-1] = v241;
    goto v307;

v307:
    v82 = stack[-1];
    v241 = stack[-2];
    fn = elt(env, 5); /* red_topredbe */
    v241 = (*qfn2(fn))(qenv(fn), v82, v241);
    nil = C_nil;
    if (exception_pending()) goto v350;
    env = stack[-3];
    stack[0] = v241;
    goto v70;

v118:
    v241 = qvalue(elt(env, 1)); /* t */
    goto v249;
/* error exit handlers */
v350:
    popv(4);
    return nil;
}



/* Code for !*multf */

static Lisp_Object CC_Hmultf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v400, v401, v402;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *multf");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v109;
    stack[-3] = v0;
/* end of prologue */
    v400 = stack[-3];
    if (v400 == nil) goto v192;
    v400 = stack[-2];
    v400 = (v400 == nil ? lisp_true : nil);
    goto v193;

v193:
    if (v400 == nil) goto v231;
    v400 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v400); }

v231:
    v401 = stack[-3];
    v400 = (Lisp_Object)17; /* 1 */
    if (v401 == v400) goto v186;
    v401 = stack[-2];
    v400 = (Lisp_Object)17; /* 1 */
    if (v401 == v400) goto v70;
    v400 = stack[-3];
    if (!consp(v400)) goto v290;
    v400 = stack[-3];
    v400 = qcar(v400);
    v400 = (consp(v400) ? nil : lisp_true);
    goto v76;

v76:
    if (v400 == nil) goto v181;
    stack[0] = stack[-3];
    v400 = stack[-2];
    fn = elt(env, 7); /* squashsqrt */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    {
        Lisp_Object v404 = stack[0];
        popv(6);
        fn = elt(env, 8); /* multd */
        return (*qfn2(fn))(qenv(fn), v404, v400);
    }

v181:
    v400 = stack[-2];
    if (!consp(v400)) goto v65;
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = (consp(v400) ? nil : lisp_true);
    goto v66;

v66:
    if (v400 == nil) goto v301;
    stack[0] = stack[-2];
    v400 = stack[-3];
    fn = elt(env, 7); /* squashsqrt */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    {
        Lisp_Object v405 = stack[0];
        popv(6);
        fn = elt(env, 8); /* multd */
        return (*qfn2(fn))(qenv(fn), v405, v400);
    }

v301:
    v400 = qvalue(elt(env, 3)); /* !*noncomp */
    if (v400 == nil) goto v110;
    v401 = stack[-3];
    v400 = stack[-2];
    {
        popv(6);
        fn = elt(env, 9); /* multf */
        return (*qfn2(fn))(qenv(fn), v401, v400);
    }

v110:
    v400 = stack[-3];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v400 = qcar(v400);
    stack[0] = v400;
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v400 = qcar(v400);
    stack[-1] = v400;
    v401 = stack[0];
    v400 = stack[-1];
    if (v401 == v400) goto v406;
    v401 = stack[0];
    v400 = stack[-1];
    fn = elt(env, 10); /* ordop */
    v400 = (*qfn2(fn))(qenv(fn), v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    if (v400 == nil) goto v245;
    v400 = stack[-3];
    v400 = qcar(v400);
    v401 = qcdr(v400);
    v400 = stack[-2];
    v400 = CC_Hmultf(env, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    stack[0] = v400;
    v400 = stack[-3];
    v401 = qcdr(v400);
    v400 = stack[-2];
    v400 = CC_Hmultf(env, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    stack[-1] = v400;
    v400 = stack[0];
    if (v400 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v400 = stack[-3];
    v400 = qcar(v400);
    v400 = qcdr(v400);
    if (!consp(v400)) goto v275;
    v400 = stack[-3];
    v400 = qcar(v400);
    v400 = qcdr(v400);
    v400 = qcar(v400);
    v400 = (consp(v400) ? nil : lisp_true);
    goto v100;

v100:
    if (v400 == nil) goto v24;
    v400 = qvalue(elt(env, 2)); /* nil */
    goto v97;

v97:
    if (v400 == nil) goto v407;
    v400 = stack[-3];
    v400 = qcar(v400);
    v401 = qcar(v400);
    v400 = (Lisp_Object)17; /* 1 */
    v400 = cons(v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v401 = ncons(v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v400 = stack[0];
    v401 = CC_Hmultf(env, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v400 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v401, v400);
    }

v407:
    v400 = stack[-3];
    v400 = qcar(v400);
    v402 = qcar(v400);
    v401 = stack[0];
    v400 = stack[-1];
    {
        popv(6);
        fn = elt(env, 12); /* makeupsf */
        return (*qfnn(fn))(qenv(fn), 3, v402, v401, v400);
    }

v24:
    v400 = stack[-3];
    v400 = qcar(v400);
    v400 = qcdr(v400);
    v400 = qcar(v400);
    v400 = qcar(v400);
    v401 = qcar(v400);
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v400 = qcar(v400);
    if (v401 == v400) goto v340;
    v400 = qvalue(elt(env, 2)); /* nil */
    goto v97;

v340:
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v400 = qcar(v400);
    if (!consp(v400)) goto v408;
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v400 = qcar(v400);
    v401 = qcar(v400);
    v400 = elt(env, 4); /* (expt sqrt) */
    v400 = Lmemq(nil, v401, v400);
    goto v97;

v408:
    v400 = qvalue(elt(env, 2)); /* nil */
    goto v97;

v275:
    v400 = qvalue(elt(env, 1)); /* t */
    goto v100;

v245:
    v401 = stack[-3];
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcdr(v400);
    v400 = CC_Hmultf(env, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    stack[0] = v400;
    v401 = stack[-3];
    v400 = stack[-2];
    v400 = qcdr(v400);
    v400 = CC_Hmultf(env, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    stack[-1] = v400;
    v400 = stack[0];
    if (v400 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcdr(v400);
    if (!consp(v400)) goto v171;
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcdr(v400);
    v400 = qcar(v400);
    v400 = (consp(v400) ? nil : lisp_true);
    goto v313;

v313:
    if (v400 == nil) goto v166;
    v400 = qvalue(elt(env, 2)); /* nil */
    goto v269;

v269:
    if (v400 == nil) goto v159;
    v400 = stack[-2];
    v400 = qcar(v400);
    v401 = qcar(v400);
    v400 = (Lisp_Object)17; /* 1 */
    v400 = cons(v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v400 = ncons(v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v401 = CC_Hmultf(env, stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v400 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v401, v400);
    }

v159:
    v400 = stack[-2];
    v400 = qcar(v400);
    v402 = qcar(v400);
    v401 = stack[0];
    v400 = stack[-1];
    {
        popv(6);
        fn = elt(env, 12); /* makeupsf */
        return (*qfnn(fn))(qenv(fn), 3, v402, v401, v400);
    }

v166:
    v400 = stack[-3];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v401 = qcar(v400);
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcdr(v400);
    v400 = qcar(v400);
    v400 = qcar(v400);
    v400 = qcar(v400);
    if (v401 == v400) goto v409;
    v400 = qvalue(elt(env, 2)); /* nil */
    goto v269;

v409:
    v400 = stack[-3];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v400 = qcar(v400);
    if (!consp(v400)) goto v410;
    v400 = stack[-3];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v400 = qcar(v400);
    v401 = qcar(v400);
    v400 = elt(env, 4); /* (expt sqrt) */
    v400 = Lmemq(nil, v401, v400);
    goto v269;

v410:
    v400 = qvalue(elt(env, 2)); /* nil */
    goto v269;

v171:
    v400 = qvalue(elt(env, 1)); /* t */
    goto v313;

v406:
    v400 = stack[-3];
    v400 = qcar(v400);
    v401 = ncons(v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v400 = stack[-2];
    v400 = qcdr(v400);
    stack[-1] = CC_Hmultf(env, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v400 = stack[-3];
    v401 = qcdr(v400);
    v400 = stack[-2];
    v400 = CC_Hmultf(env, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    fn = elt(env, 11); /* addf */
    v400 = (*qfn2(fn))(qenv(fn), stack[-1], v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    stack[-1] = v400;
    v401 = stack[0];
    v400 = elt(env, 5); /* sqrt */
    if (!consp(v401)) goto v218;
    v401 = qcar(v401);
    if (!(v401 == v400)) goto v218;
    v400 = stack[-1];
    fn = elt(env, 7); /* squashsqrt */
    stack[-4] = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    stack[-1] = stack[0];
    v400 = stack[-3];
    v400 = qcar(v400);
    v401 = qcdr(v400);
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcdr(v400);
    stack[0] = CC_Hmultf(env, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v400 = stack[-3];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v401 = qcdr(v400);
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v400 = qcdr(v400);
    v400 = plus2(v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    fn = elt(env, 13); /* !*multfsqrt */
    v400 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    {
        Lisp_Object v411 = stack[-4];
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v411, v400);
    }

v218:
    v401 = stack[0];
    v400 = elt(env, 6); /* expt */
    if (!consp(v401)) goto v129;
    v401 = qcar(v401);
    if (!(v401 == v400)) goto v129;
    v400 = stack[0];
    v400 = qcdr(v400);
    v400 = qcdr(v400);
    v400 = qcar(v400);
    fn = elt(env, 14); /* prefix!-rational!-numberp */
    v400 = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    goto v224;

v224:
    if (v400 == nil) goto v219;
    v400 = stack[-1];
    fn = elt(env, 7); /* squashsqrt */
    stack[-4] = (*qfn1(fn))(qenv(fn), v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    stack[-1] = stack[0];
    v400 = stack[-3];
    v400 = qcar(v400);
    v401 = qcdr(v400);
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcdr(v400);
    stack[0] = CC_Hmultf(env, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v400 = stack[-3];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v401 = qcdr(v400);
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v400 = qcdr(v400);
    v400 = plus2(v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    fn = elt(env, 15); /* !*multfexpt */
    v400 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    {
        Lisp_Object v412 = stack[-4];
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v412, v400);
    }

v219:
    v400 = stack[-3];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v401 = qcdr(v400);
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcar(v400);
    v400 = qcdr(v400);
    v400 = plus2(v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    fn = elt(env, 16); /* mkspm */
    v400 = (*qfn2(fn))(qenv(fn), stack[0], v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    stack[0] = v400;
    v400 = stack[0];
    if (v400 == nil) goto v413;
    v400 = stack[-3];
    v400 = qcar(v400);
    v401 = qcdr(v400);
    v400 = stack[-2];
    v400 = qcar(v400);
    v400 = qcdr(v400);
    v400 = CC_Hmultf(env, v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    stack[-3] = v400;
    v400 = (v400 == nil ? lisp_true : nil);
    goto v195;

v195:
    if (!(v400 == nil)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v401 = stack[0];
    v400 = (Lisp_Object)17; /* 1 */
    v400 = cons(v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v401 = ncons(v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v400 = stack[-3];
    fn = elt(env, 9); /* multf */
    v401 = (*qfn2(fn))(qenv(fn), v401, v400);
    nil = C_nil;
    if (exception_pending()) goto v403;
    env = stack[-5];
    v400 = stack[-1];
    {
        popv(6);
        fn = elt(env, 11); /* addf */
        return (*qfn2(fn))(qenv(fn), v401, v400);
    }

v413:
    v400 = qvalue(elt(env, 1)); /* t */
    goto v195;

v129:
    v400 = qvalue(elt(env, 2)); /* nil */
    goto v224;

v65:
    v400 = qvalue(elt(env, 1)); /* t */
    goto v66;

v290:
    v400 = qvalue(elt(env, 1)); /* t */
    goto v76;

v70:
    v400 = stack[-3];
    {
        popv(6);
        fn = elt(env, 7); /* squashsqrt */
        return (*qfn1(fn))(qenv(fn), v400);
    }

v186:
    v400 = stack[-2];
    {
        popv(6);
        fn = elt(env, 7); /* squashsqrt */
        return (*qfn1(fn))(qenv(fn), v400);
    }

v192:
    v400 = qvalue(elt(env, 1)); /* t */
    goto v193;
/* error exit handlers */
v403:
    popv(6);
    return nil;
}



/* Code for !:expt */

static Lisp_Object CC_Texpt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v109)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40, v227;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :expt");
#endif
    if (stack >= stacklimit)
    {
        push2(v109,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v109);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v109;
    stack[-4] = v0;
/* end of prologue */
    v39 = stack[-4];
    if (v39 == nil) goto v112;
    v40 = stack[-3];
    v39 = (Lisp_Object)1; /* 0 */
    if (v40 == v39) goto v70;
    v40 = stack[-3];
    v39 = (Lisp_Object)17; /* 1 */
    if (v40 == v39) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v40 = stack[-4];
    v39 = (Lisp_Object)17; /* 1 */
    if (v40 == v39) goto v185;
    v40 = stack[-3];
    v39 = (Lisp_Object)1; /* 0 */
    v39 = (Lisp_Object)lessp2(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    v39 = v39 ? lisp_true : nil;
    env = stack[-6];
    if (v39 == nil) goto v179;
    v39 = stack[-4];
    if (!consp(v39)) goto v57;
    v39 = stack[-4];
    v40 = qcar(v39);
    v39 = elt(env, 5); /* field */
    v39 = Lflagp(nil, v40, v39);
    env = stack[-6];
    goto v399;

v399:
    if (v39 == nil) goto v302;
    v39 = stack[-4];
    stack[0] = v39;
    goto v316;

v316:
    v39 = stack[-3];
    v39 = negate(v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    v39 = CC_Texpt(env, stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 9); /* !:recip */
        return (*qfn1(fn))(qenv(fn), v39);
    }

v302:
    v39 = stack[-4];
    fn = elt(env, 10); /* mkratnum */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    stack[0] = v39;
    goto v316;

v57:
    v39 = qvalue(elt(env, 4)); /* nil */
    goto v399;

v179:
    v39 = stack[-4];
    if (!consp(v39)) goto v271;
    v39 = stack[-4];
    v40 = qcar(v39);
    v39 = elt(env, 6); /* expt */
    v39 = get(v40, v39);
    env = stack[-6];
    stack[-2] = v39;
    if (v39 == nil) goto v311;
    v227 = stack[-2];
    v40 = stack[-4];
    v39 = stack[-3];
        popv(7);
        return Lapply2(nil, 3, v227, v40, v39);

v311:
    v39 = stack[-4];
    v40 = qcar(v39);
    v39 = elt(env, 7); /* i2d */
    v40 = get(v40, v39);
    env = stack[-6];
    v39 = (Lisp_Object)17; /* 1 */
    v39 = Lapply1(nil, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    stack[-5] = v39;
    v39 = stack[-4];
    v40 = qcar(v39);
    v39 = elt(env, 8); /* times */
    v39 = get(v40, v39);
    env = stack[-6];
    stack[-2] = v39;
    goto v398;

v398:
    v39 = stack[-3];
    stack[-1] = v39;
    stack[0] = (Lisp_Object)33; /* 2 */
    v40 = stack[-3];
    v39 = (Lisp_Object)33; /* 2 */
    v39 = quot2(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    stack[-3] = v39;
    v39 = times2(stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    v40 = difference2(stack[-1], v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    v39 = (Lisp_Object)1; /* 0 */
    if (v40 == v39) goto v164;
    v227 = stack[-2];
    v40 = stack[-4];
    v39 = stack[-5];
    v39 = Lapply2(nil, 3, v227, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    stack[-5] = v39;
    goto v164;

v164:
    v40 = stack[-3];
    v39 = (Lisp_Object)1; /* 0 */
    if (v40 == v39) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v227 = stack[-2];
    v40 = stack[-4];
    v39 = stack[-4];
    v39 = Lapply2(nil, 3, v227, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    stack[-4] = v39;
    goto v398;

v271:
    v40 = stack[-4];
    v39 = stack[-3];
        popv(7);
        return Lexpt(nil, v40, v39);

v185:
    v39 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v39); }

v70:
    v39 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v39); }

v112:
    v40 = stack[-3];
    v39 = (Lisp_Object)1; /* 0 */
    if (v40 == v39) goto v110;
    v39 = qvalue(elt(env, 4)); /* nil */
    { popv(7); return onevalue(v39); }

v110:
    v39 = elt(env, 1); /* "0/0 formed" */
    v40 = v39;
    v39 = v40;
    qvalue(elt(env, 2)) = v39; /* errmsg!* */
    v39 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v39 == nil)) goto v247;
    v39 = v40;
    fn = elt(env, 11); /* lprie */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    goto v247;

v247:
    v39 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    v39 = nil;
    { popv(7); return onevalue(v39); }
/* error exit handlers */
v32:
    popv(7);
    return nil;
}



/* Code for gcref_off1 */

static Lisp_Object MS_CDECL CC_gcref_off1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v162, v427;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "gcref_off1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcref_off1");
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
    push3(nil, nil, nil);
/* end of prologue */
    v161 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v161; /* dfprint!* */
    v161 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v161; /* !*defn */
    v161 = qvalue(elt(env, 4)); /* !*algebraics */
    if (!(v161 == nil)) goto v278;
    v162 = elt(env, 5); /* algebraic */
    v161 = elt(env, 6); /* newnam */
    v161 = Lremprop(nil, v162, v161);
    env = stack[-8];
    goto v278;

v278:
    v161 = qvalue(elt(env, 7)); /* seen!* */
    stack[-1] = v161;
    goto v80;

v80:
    v161 = stack[-1];
    if (v161 == nil) goto v180;
    v161 = stack[-1];
    v161 = qcar(v161);
    stack[0] = v161;
    v162 = stack[0];
    v161 = elt(env, 8); /* calledby */
    v161 = get(v162, v161);
    env = stack[-8];
    if (!(v161 == nil)) goto v71;
    v162 = stack[0];
    v161 = qvalue(elt(env, 9)); /* entpts!* */
    v161 = cons(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    qvalue(elt(env, 9)) = v161; /* entpts!* */
    goto v71;

v71:
    v161 = stack[0];
    fn = elt(env, 18); /* undefdchk */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    v161 = stack[-1];
    v161 = qcdr(v161);
    stack[-1] = v161;
    goto v80;

v180:
    v162 = qvalue(elt(env, 10)); /* tseen!* */
    v161 = elt(env, 11); /* idcompare */
    fn = elt(env, 19); /* sort */
    v161 = (*qfn2(fn))(qenv(fn), v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    stack[-6] = v161;
    v161 = stack[-6];
    if (v161 == nil) goto v84;
    v161 = stack[-6];
    v161 = qcar(v161);
    stack[-2] = v161;
    v162 = stack[-2];
    v161 = elt(env, 12); /* tseen */
    v161 = Lremprop(nil, v162, v161);
    env = stack[-8];
    v162 = stack[-2];
    v161 = elt(env, 13); /* funs */
    v161 = get(v162, v161);
    env = stack[-8];
    stack[-7] = v161;
    stack[-1] = v161;
    goto v298;

v298:
    v161 = stack[-1];
    if (v161 == nil) goto v333;
    v161 = stack[-1];
    v161 = qcar(v161);
    stack[0] = v161;
    v161 = stack[0];
    fn = elt(env, 18); /* undefdchk */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    v162 = stack[0];
    v161 = elt(env, 14); /* rccnam */
    v161 = Lremprop(nil, v162, v161);
    env = stack[-8];
    v161 = stack[-1];
    v161 = qcdr(v161);
    stack[-1] = v161;
    goto v298;

v333:
    v162 = stack[-2];
    v161 = stack[-7];
    v161 = cons(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    v161 = ncons(v161);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    stack[-4] = v161;
    stack[-5] = v161;
    goto v293;

v293:
    v161 = stack[-6];
    v161 = qcdr(v161);
    stack[-6] = v161;
    v161 = stack[-6];
    if (v161 == nil) goto v246;
    stack[-3] = stack[-4];
    v161 = stack[-6];
    v161 = qcar(v161);
    stack[-2] = v161;
    v162 = stack[-2];
    v161 = elt(env, 12); /* tseen */
    v161 = Lremprop(nil, v162, v161);
    env = stack[-8];
    v162 = stack[-2];
    v161 = elt(env, 13); /* funs */
    v161 = get(v162, v161);
    env = stack[-8];
    stack[-7] = v161;
    stack[-1] = v161;
    goto v311;

v311:
    v161 = stack[-1];
    if (v161 == nil) goto v428;
    v161 = stack[-1];
    v161 = qcar(v161);
    stack[0] = v161;
    v161 = stack[0];
    fn = elt(env, 18); /* undefdchk */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    v162 = stack[0];
    v161 = elt(env, 14); /* rccnam */
    v161 = Lremprop(nil, v162, v161);
    env = stack[-8];
    v161 = stack[-1];
    v161 = qcdr(v161);
    stack[-1] = v161;
    goto v311;

v428:
    v162 = stack[-2];
    v161 = stack[-7];
    v161 = cons(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    v161 = ncons(v161);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    v161 = Lrplacd(nil, stack[-3], v161);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    v161 = stack[-4];
    v161 = qcdr(v161);
    stack[-4] = v161;
    goto v293;

v246:
    v161 = stack[-5];
    goto v306;

v306:
    qvalue(elt(env, 10)) = v161; /* tseen!* */
    v161 = qvalue(elt(env, 15)); /* gseen!* */
    stack[0] = v161;
    goto v31;

v31:
    v161 = stack[0];
    if (v161 == nil) goto v37;
    v161 = stack[0];
    v161 = qcar(v161);
    v427 = v161;
    v162 = v427;
    v161 = elt(env, 16); /* usedunby */
    v161 = get(v162, v161);
    env = stack[-8];
    if (v161 == nil) goto v410;
    v162 = v427;
    v161 = qvalue(elt(env, 17)); /* undefg!* */
    v161 = cons(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    qvalue(elt(env, 17)) = v161; /* undefg!* */
    goto v410;

v410:
    v161 = stack[0];
    v161 = qcdr(v161);
    stack[0] = v161;
    goto v31;

v37:
    v161 = nil;
    { popv(9); return onevalue(v161); }

v84:
    v161 = qvalue(elt(env, 1)); /* nil */
    goto v306;
/* error exit handlers */
v227:
    popv(9);
    return nil;
}



setup_type const u25_setup[] =
{
    {"physopsimp",              CC_physopsimp,  too_many_1,    wrong_no_1},
    {"ev-denom2",               too_few_2,      CC_evKdenom2,  wrong_no_2},
    {"mv-domainlist-+",         too_few_2,      CC_mvKdomainlistKL,wrong_no_2},
    {"inprint",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_inprint},
    {"dip_moncomp",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_dip_moncomp},
    {"ombindir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_ombindir},
    {"close_forall",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_close_forall},
    {"indordl2",                too_few_2,      CC_indordl2,   wrong_no_2},
    {"ezgcdf1",                 too_few_2,      CC_ezgcdf1,    wrong_no_2},
    {"gvar1",                   too_few_2,      CC_gvar1,      wrong_no_2},
    {"getavalue",               CC_getavalue,   too_many_1,    wrong_no_1},
    {"cl_f2ml",                 too_few_2,      CC_cl_f2ml,    wrong_no_2},
    {"plusdf",                  too_few_2,      CC_plusdf,     wrong_no_2},
    {"qqe_simplterm-tail",      CC_qqe_simpltermKtail,too_many_1,wrong_no_1},
    {"cl_susicpknowl",          CC_cl_susicpknowl,too_many_1,  wrong_no_1},
    {"alg_plus",                too_few_2,      CC_alg_plus,   wrong_no_2},
    {"insoccs",                 too_few_2,      CC_insoccs,    wrong_no_2},
    {"critical_element",        CC_critical_element,too_many_1,wrong_no_1},
    {"statep",                  CC_statep,      too_many_1,    wrong_no_1},
    {"l-subst",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_lKsubst},
    {"groeb=newpair",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebMnewpair},
    {"clean_numid",             CC_clean_numid, too_many_1,    wrong_no_1},
    {"modp",                    too_few_2,      CC_modp,       wrong_no_2},
    {"ratlessp",                too_few_2,      CC_ratlessp,   wrong_no_2},
    {"horner-rule-for-one-var", wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKforKoneKvar},
    {"formbool",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formbool},
    {"cquotegex",               CC_cquotegex,   too_many_1,    wrong_no_1},
    {"lambdaom",                CC_lambdaom,    too_many_1,    wrong_no_1},
    {"crn:zerop",               CC_crnTzerop,   too_many_1,    wrong_no_1},
    {"mkmatrix",                too_few_2,      CC_mkmatrix,   wrong_no_2},
    {"redcodmat",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_redcodmat},
    {"dipev2f",                 too_few_2,      CC_dipev2f,    wrong_no_2},
    {"evinvlexcomp",            too_few_2,      CC_evinvlexcomp,wrong_no_2},
    {"getrlist",                CC_getrlist,    too_many_1,    wrong_no_1},
    {"lispreadp",               CC_lispreadp,   too_many_1,    wrong_no_1},
    {"red_topred",              too_few_2,      CC_red_topred, wrong_no_2},
    {"*multf",                  too_few_2,      CC_Hmultf,     wrong_no_2},
    {":expt",                   too_few_2,      CC_Texpt,      wrong_no_2},
    {"gcref_off1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_gcref_off1},
    {NULL, (one_args *)"u25", (two_args *)"5747 8207634 2309845", 0}
};

/* end of generated code */
