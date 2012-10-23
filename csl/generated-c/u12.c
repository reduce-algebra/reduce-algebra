
/* $destdir\u12.c        Machine generated C code */

/* Signature: 00000000 23-Oct-2012 */

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
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
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
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
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


/* Code for modminusp!: */

static Lisp_Object CC_modminuspT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modminusp:");
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
    v0005 = v0000;
/* end of prologue */
    v0006 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v0006 == nil) goto v0007;
    v0006 = (Lisp_Object)33; /* 2 */
    v0005 = qcdr(v0005);
    v0005 = times2(v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[0];
    v0006 = qvalue(elt(env, 2)); /* current!-modulus */
        popv(1);
        return Lgreaterp(nil, v0005, v0006);

v0007:
    v0005 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v0005); }
/* error exit handlers */
v0008:
    popv(1);
    return nil;
}



/* Code for !:dmpluslst */

static Lisp_Object CC_Tdmpluslst(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmpluslst");
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
    v0008 = v0000;
/* end of prologue */
    v0006 = v0008;
    if (v0006 == nil) goto v0010;
    v0006 = v0008;
    v0006 = qcdr(v0006);
    if (v0006 == nil) goto v0011;
    v0006 = v0008;
    stack[0] = qcar(v0006);
    v0006 = v0008;
    v0006 = qcdr(v0006);
    v0006 = CC_Tdmpluslst(env, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-1];
    {
        Lisp_Object v0013 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:plus */
        return (*qfn2(fn))(qenv(fn), v0013, v0006);
    }

v0011:
    v0006 = v0008;
    v0006 = qcar(v0006);
    { popv(2); return onevalue(v0006); }

v0010:
    v0006 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0006); }
/* error exit handlers */
v0012:
    popv(2);
    return nil;
}



/* Code for simptimes */

static Lisp_Object CC_simptimes(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simptimes");
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
    v0027 = stack[-1];
    if (v0027 == nil) goto v0029;
    v0028 = qvalue(elt(env, 1)); /* tstack!* */
    v0027 = (Lisp_Object)1; /* 0 */
    if (v0028 == v0027) goto v0030;
    v0027 = qvalue(elt(env, 2)); /* t */
    goto v0008;

v0008:
    if (!(v0027 == nil)) goto v0031;
    v0027 = qvalue(elt(env, 3)); /* mul!* */
    stack[-2] = v0027;
    v0027 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 3)) = v0027; /* mul!* */
    goto v0031;

v0031:
    v0027 = qvalue(elt(env, 1)); /* tstack!* */
    v0027 = add1(v0027);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0027; /* tstack!* */
    v0027 = stack[-1];
    v0027 = qcar(v0027);
    fn = elt(env, 6); /* simp */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    stack[0] = v0027;
    goto v0033;

v0033:
    v0027 = stack[-1];
    v0027 = qcdr(v0027);
    stack[-1] = v0027;
    v0027 = stack[0];
    v0027 = qcar(v0027);
    if (v0027 == nil) goto v0034;
    v0027 = stack[-1];
    if (v0027 == nil) goto v0011;
    v0027 = stack[-1];
    v0027 = qcar(v0027);
    fn = elt(env, 6); /* simp */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    fn = elt(env, 7); /* multsq */
    v0027 = (*qfn2(fn))(qenv(fn), stack[0], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    stack[0] = v0027;
    goto v0033;

v0011:
    v0027 = qvalue(elt(env, 3)); /* mul!* */
    if (v0027 == nil) goto v0035;
    v0028 = qvalue(elt(env, 1)); /* tstack!* */
    v0027 = (Lisp_Object)17; /* 1 */
    v0027 = (Lisp_Object)greaterp2(v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    v0027 = v0027 ? lisp_true : nil;
    env = stack[-3];
    goto v0036;

v0036:
    if (!(v0027 == nil)) goto v0034;
    v0027 = qvalue(elt(env, 3)); /* mul!* */
    v0028 = qcar(v0027);
    v0027 = stack[0];
    v0027 = Lapply1(nil, v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    stack[0] = v0027;
    v0027 = qvalue(elt(env, 4)); /* nil */
    v0027 = ncons(v0027);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0027; /* alglist!* */
    v0027 = qvalue(elt(env, 3)); /* mul!* */
    v0027 = qcdr(v0027);
    qvalue(elt(env, 3)) = v0027; /* mul!* */
    goto v0011;

v0034:
    v0027 = qvalue(elt(env, 1)); /* tstack!* */
    v0027 = sub1(v0027);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0027; /* tstack!* */
    v0028 = qvalue(elt(env, 1)); /* tstack!* */
    v0027 = (Lisp_Object)1; /* 0 */
    if (!(v0028 == v0027)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0027 = stack[-2];
    qvalue(elt(env, 3)) = v0027; /* mul!* */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v0035:
    v0027 = qvalue(elt(env, 2)); /* t */
    goto v0036;

v0030:
    v0027 = qvalue(elt(env, 3)); /* mul!* */
    v0027 = (v0027 == nil ? lisp_true : nil);
    goto v0008;

v0029:
    v0028 = (Lisp_Object)17; /* 1 */
    v0027 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v0028, v0027);
/* error exit handlers */
v0032:
    popv(4);
    return nil;
}



/* Code for formop */

static Lisp_Object CC_formop(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formop");
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
    goto v0031;

v0031:
    v0041 = stack[-1];
    if (!consp(v0041)) goto v0043;
    v0041 = stack[-1];
    v0041 = qcar(v0041);
    v0041 = (consp(v0041) ? nil : lisp_true);
    goto v0044;

v0044:
    if (v0041 == nil) goto v0013;
    v0041 = stack[-1];
    v0042 = v0041;
    goto v0011;

v0011:
    v0041 = stack[-2];
    if (v0041 == nil) { popv(4); return onevalue(v0042); }
    v0041 = stack[-2];
    v0041 = qcar(v0041);
    fn = elt(env, 2); /* raddf */
    v0041 = (*qfn2(fn))(qenv(fn), v0041, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-3];
    v0042 = v0041;
    v0041 = stack[-2];
    v0041 = qcdr(v0041);
    stack[-2] = v0041;
    goto v0011;

v0013:
    v0041 = stack[-1];
    v0041 = qcar(v0041);
    stack[0] = qcar(v0041);
    v0041 = stack[-1];
    v0041 = qcar(v0041);
    v0041 = qcdr(v0041);
    v0041 = CC_formop(env, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-3];
    fn = elt(env, 3); /* multop */
    v0042 = (*qfn2(fn))(qenv(fn), stack[0], v0041);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-3];
    v0041 = stack[-2];
    v0041 = cons(v0042, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-3];
    stack[-2] = v0041;
    v0041 = stack[-1];
    v0041 = qcdr(v0041);
    stack[-1] = v0041;
    goto v0031;

v0043:
    v0041 = qvalue(elt(env, 1)); /* t */
    goto v0044;
/* error exit handlers */
v0045:
    popv(4);
    return nil;
}



/* Code for dp_times_bc */

static Lisp_Object CC_dp_times_bc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_times_bc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0020 = v0046;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = v0020;
    v0020 = stack[-5];
    if (v0020 == nil) goto v0055;
    v0020 = stack[-5];
    v0020 = qcar(v0020);
    v0036 = v0020;
    stack[0] = qcar(v0036);
    v0036 = stack[-4];
    v0020 = qcdr(v0020);
    fn = elt(env, 2); /* bc_prod */
    v0020 = (*qfn2(fn))(qenv(fn), v0036, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0020 = cons(stack[0], v0020);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0020 = ncons(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    stack[-2] = v0020;
    stack[-3] = v0020;
    goto v0011;

v0011:
    v0020 = stack[-5];
    v0020 = qcdr(v0020);
    stack[-5] = v0020;
    v0020 = stack[-5];
    if (v0020 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0020 = stack[-5];
    v0020 = qcar(v0020);
    v0036 = v0020;
    stack[0] = qcar(v0036);
    v0036 = stack[-4];
    v0020 = qcdr(v0020);
    fn = elt(env, 2); /* bc_prod */
    v0020 = (*qfn2(fn))(qenv(fn), v0036, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0020 = cons(stack[0], v0020);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0020 = ncons(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0020 = Lrplacd(nil, stack[-1], v0020);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0020 = stack[-2];
    v0020 = qcdr(v0020);
    stack[-2] = v0020;
    goto v0011;

v0055:
    v0020 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0020); }
/* error exit handlers */
v0056:
    popv(7);
    return nil;
}



/* Code for pv_neg */

static Lisp_Object CC_pv_neg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0025, v0026;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_neg");
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
    goto v0033;

v0033:
    v0058 = stack[0];
    if (v0058 == nil) goto v0031;
    v0058 = stack[0];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0026 = negate(v0058);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    v0058 = stack[0];
    v0058 = qcar(v0058);
    v0025 = qcdr(v0058);
    v0058 = stack[-1];
    v0058 = acons(v0026, v0025, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-2];
    stack[-1] = v0058;
    v0058 = stack[0];
    v0058 = qcdr(v0058);
    stack[0] = v0058;
    goto v0033;

v0031:
    v0058 = stack[-1];
        popv(3);
        return Lnreverse(nil, v0058);
/* error exit handlers */
v0059:
    popv(3);
    return nil;
}



/* Code for pst_termnodep */

static Lisp_Object CC_pst_termnodep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0044;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_termnodep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0002 = v0000;
/* end of prologue */
    v0044 = qcdr(v0002);
    v0002 = (Lisp_Object)1; /* 0 */
    v0002 = *(Lisp_Object *)((char *)v0044 + (CELL-TAG_VECTOR) + ((int32_t)v0002/(16/CELL)));
    v0002 = qcdr(v0002);
    v0002 = (v0002 == nil ? lisp_true : nil);
    return onevalue(v0002);
}



/* Code for conv!:mt */

static Lisp_Object CC_convTmt(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0087;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conv:mt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    stack[-2] = v0000;
/* end of prologue */
    v0087 = stack[-2];
    v0086 = elt(env, 1); /* !:rd!: */
    if (!consp(v0087)) goto v0006;
    v0087 = qcar(v0087);
    if (!(v0087 == v0086)) goto v0006;
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    v0086 = (consp(v0086) ? nil : lisp_true);
    v0086 = (v0086 == nil ? lisp_true : nil);
    goto v0055;

v0055:
    if (v0086 == nil) goto v0088;
    v0086 = stack[0];
    v0086 = integerp(v0086);
    if (v0086 == nil) goto v0089;
    v0087 = stack[0];
    v0086 = (Lisp_Object)1; /* 0 */
    v0086 = (Lisp_Object)greaterp2(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0086 = v0086 ? lisp_true : nil;
    env = stack[-4];
    goto v0011;

v0011:
    if (v0086 == nil) goto v0091;
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    v0086 = qcar(v0086);
    v0086 = Labsval(nil, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    fn = elt(env, 4); /* msd */
    v0087 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    v0086 = stack[0];
    v0087 = difference2(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    stack[0] = v0087;
    v0086 = (Lisp_Object)1; /* 0 */
    if (v0087 == v0086) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0087 = stack[0];
    v0086 = (Lisp_Object)1; /* 0 */
    v0086 = (Lisp_Object)lessp2(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0086 = v0086 ? lisp_true : nil;
    env = stack[-4];
    if (v0086 == nil) goto v0016;
    v0086 = stack[0];
    v0086 = negate(v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    stack[-3] = v0086;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    v0087 = qcar(v0086);
    v0086 = stack[-3];
    stack[0] = Lash1(nil, v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    v0087 = qcdr(v0086);
    v0086 = stack[-3];
    v0086 = difference2(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    {
        Lisp_Object v0092 = stack[-1];
        Lisp_Object v0093 = stack[0];
        popv(5);
        return list2star(v0092, v0093, v0086);
    }

v0016:
    v0086 = stack[0];
    v0086 = sub1(v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    stack[-3] = v0086;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    stack[0] = qcar(v0086);
    v0086 = stack[-3];
    v0086 = negate(v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    v0087 = qcdr(v0086);
    v0086 = stack[-3];
    v0086 = plus2(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    v0086 = list2star(stack[-1], stack[0], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 5); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v0086);
    }

v0091:
    stack[0] = (Lisp_Object)1; /* 0 */
    v0087 = elt(env, 3); /* "Invalid argument to" */
    v0086 = elt(env, 0); /* conv!:mt */
    v0086 = list2(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-4];
    {
        Lisp_Object v0094 = stack[0];
        popv(5);
        fn = elt(env, 6); /* error */
        return (*qfn2(fn))(qenv(fn), v0094, v0086);
    }

v0089:
    v0086 = qvalue(elt(env, 2)); /* nil */
    goto v0011;

v0088:
    v0086 = qvalue(elt(env, 2)); /* nil */
    goto v0011;

v0006:
    v0086 = qvalue(elt(env, 2)); /* nil */
    goto v0055;
/* error exit handlers */
v0090:
    popv(5);
    return nil;
}



/* Code for removeg1 */

static Lisp_Object MS_CDECL CC_removeg1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0046,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0157, v0158, v0159, v0160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "removeg1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeg1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0014,v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0046,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0014;
    stack[-4] = v0046;
    stack[-5] = v0000;
/* end of prologue */
    v0158 = stack[-5];
    v0157 = stack[-4];
    fn = elt(env, 9); /* removev */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0158 = stack[-5];
    v0157 = stack[-3];
    fn = elt(env, 9); /* removev */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0158 = qcar(v0157);
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    if (v0158 == v0157) goto v0084;
    v0157 = qvalue(elt(env, 1)); /* nil */
    goto v0013;

v0013:
    if (v0157 == nil) goto v0079;
    v0158 = qvalue(elt(env, 2)); /* n!*!*2!-1 */
    v0157 = stack[-5];
    v0157 = qcar(v0157);
    fn = elt(env, 10); /* multsq */
    v0158 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    v0157 = cons(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    popv(8);
    return ncons(v0157);

v0079:
    v0157 = stack[-5];
    v0158 = qcdr(v0157);
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    fn = elt(env, 11); /* finde */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    stack[-6] = v0157;
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0158 = qcar(v0157);
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    if (v0158 == v0157) goto v0072;
    v0157 = stack[-5];
    v0158 = qcdr(v0157);
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    fn = elt(env, 11); /* finde */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    stack[-2] = v0157;
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0158 = qcar(v0157);
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    if (v0158 == v0157) goto v0162;
    v0157 = stack[-6];
    if (v0157 == nil) goto v0163;
    v0157 = stack[-2];
    v0157 = (v0157 == nil ? lisp_true : nil);
    goto v0164;

v0164:
    if (v0157 == nil) goto v0165;
    stack[0] = elt(env, 7); /* "Invalid structure of c-graph" */
    v0157 = stack[-5];
    if (v0157 == nil) goto v0166;
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    if (v0157 == nil) goto v0167;
    v0158 = elt(env, 8); /* times */
    v0157 = stack[-5];
    v0157 = cons(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    goto v0168;

v0168:
    v0157 = list2(stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    fn = elt(env, 12); /* cerror */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    goto v0165;

v0165:
    v0157 = stack[-6];
    v0157 = qcar(v0157);
    stack[-6] = v0157;
    v0157 = stack[-2];
    v0157 = qcar(v0157);
    stack[-2] = v0157;
    v0157 = stack[-6];
    v0158 = qcdr(v0157);
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    v0157 = Lrplaca(nil, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = stack[-2];
    v0158 = qcdr(v0157);
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    v0157 = Lrplaca(nil, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = stack[-5];
    stack[0] = qcar(v0157);
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    fn = elt(env, 13); /* mkcopy */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = cons(stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    stack[-1] = v0157;
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    stack[0] = v0157;
    v0158 = stack[-6];
    v0157 = stack[0];
    v0157 = Lmember(nil, v0158, v0157);
    v0157 = qcar(v0157);
    stack[-6] = v0157;
    v0158 = stack[-2];
    v0157 = stack[0];
    v0157 = Lmember(nil, v0158, v0157);
    v0157 = qcar(v0157);
    stack[-2] = v0157;
    v0157 = stack[-6];
    v0158 = qcdr(v0157);
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    v0157 = Lrplaca(nil, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = stack[-2];
    v0158 = qcdr(v0157);
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    v0157 = Lrplaca(nil, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    stack[-3] = stack[-5];
    v0158 = (Lisp_Object)-15; /* -1 */
    v0157 = (Lisp_Object)17; /* 1 */
    stack[-2] = cons(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = qvalue(elt(env, 5)); /* su_order */
    fn = elt(env, 14); /* invsq */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v0158 = (*qfn2(fn))(qenv(fn), stack[-2], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = stack[-1];
    v0157 = qcar(v0157);
    fn = elt(env, 10); /* multsq */
    v0158 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    v0157 = stack[0];
    {
        Lisp_Object v0169 = stack[-3];
        popv(8);
        return list2star(v0169, v0158, v0157);
    }

v0167:
    v0157 = stack[-5];
    v0157 = qcar(v0157);
    goto v0168;

v0166:
    v0157 = qvalue(elt(env, 1)); /* nil */
    goto v0168;

v0163:
    v0157 = qvalue(elt(env, 6)); /* t */
    goto v0164;

v0162:
    v0157 = stack[-2];
    if (v0157 == nil) goto v0170;
    v0157 = stack[-2];
    v0157 = qcar(v0157);
    v0158 = qcdr(v0157);
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    v0157 = Lrplaca(nil, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    goto v0171;

v0171:
    stack[0] = qvalue(elt(env, 2)); /* n!*!*2!-1 */
    v0157 = qvalue(elt(env, 5)); /* su_order */
    fn = elt(env, 14); /* invsq */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v0158 = (*qfn2(fn))(qenv(fn), stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = stack[-5];
    v0157 = qcar(v0157);
    fn = elt(env, 10); /* multsq */
    v0158 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    v0157 = cons(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    popv(8);
    return ncons(v0157);

v0170:
    v0160 = elt(env, 3); /* "Free edge" */
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0159 = qcar(v0157);
    v0158 = elt(env, 4); /* "in vertex" */
    v0157 = stack[-3];
    v0157 = list4(v0160, v0159, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    fn = elt(env, 12); /* cerror */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    goto v0171;

v0072:
    v0157 = stack[-6];
    if (v0157 == nil) goto v0066;
    v0157 = stack[-6];
    v0157 = qcar(v0157);
    v0158 = qcdr(v0157);
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    v0157 = Lrplaca(nil, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    goto v0060;

v0060:
    stack[0] = qvalue(elt(env, 2)); /* n!*!*2!-1 */
    v0157 = qvalue(elt(env, 5)); /* su_order */
    fn = elt(env, 14); /* invsq */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v0158 = (*qfn2(fn))(qenv(fn), stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = stack[-5];
    v0157 = qcar(v0157);
    fn = elt(env, 10); /* multsq */
    v0158 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    v0157 = stack[-5];
    v0157 = qcdr(v0157);
    v0157 = cons(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    popv(8);
    return ncons(v0157);

v0066:
    v0160 = elt(env, 3); /* "Free edge" */
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0159 = qcar(v0157);
    v0158 = elt(env, 4); /* "in vertex" */
    v0157 = stack[-4];
    v0157 = list4(v0160, v0159, v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    fn = elt(env, 12); /* cerror */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-7];
    goto v0060;

v0084:
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0158 = qcar(v0157);
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    v0157 = (v0158 == v0157 ? lisp_true : nil);
    goto v0013;
/* error exit handlers */
v0161:
    popv(8);
    return nil;
}



/* Code for ofsf_prepat */

static Lisp_Object CC_ofsf_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_prepat");
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
    v0004 = stack[-1];
    stack[-2] = qcar(v0004);
    v0004 = stack[-1];
    v0004 = qcdr(v0004);
    v0004 = qcar(v0004);
    fn = elt(env, 1); /* prepf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-3];
    v0004 = stack[-1];
    v0004 = qcdr(v0004);
    v0004 = qcdr(v0004);
    v0004 = qcar(v0004);
    fn = elt(env, 1); /* prepf */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    {
        Lisp_Object v0005 = stack[-2];
        Lisp_Object v0006 = stack[0];
        popv(4);
        return list3(v0005, v0006, v0004);
    }
/* error exit handlers */
v0155:
    popv(4);
    return nil;
}



/* Code for cl_susiminlevel */

static Lisp_Object CC_cl_susiminlevel(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0025, v0026, v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiminlevel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0026 = v0046;
    v0040 = v0000;
/* end of prologue */
    v0025 = v0040;
    v0058 = elt(env, 1); /* ignore */
    if (v0025 == v0058) return onevalue(v0026);
    v0025 = v0026;
    v0058 = elt(env, 1); /* ignore */
    if (v0025 == v0058) return onevalue(v0040);
    v0058 = v0040;
    v0025 = v0026;
    {
        fn = elt(env, 2); /* min */
        return (*qfn2(fn))(qenv(fn), v0058, v0025);
    }
}



/* Code for cl_varl2 */

static Lisp_Object MS_CDECL CC_cl_varl2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0046,
                         Lisp_Object v0014, Lisp_Object v0015, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0223, v0224, v0225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_varl2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_varl2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0015,v0014,v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0046,v0014,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0015;
    stack[0] = v0014;
    stack[-3] = v0046;
    stack[-4] = v0000;
/* end of prologue */

v0226:
    v0095 = stack[-4];
    if (!consp(v0095)) goto v0085;
    v0095 = stack[-4];
    v0095 = qcar(v0095);
    goto v0227;

v0227:
    v0224 = v0095;
    v0223 = v0224;
    v0095 = elt(env, 1); /* true */
    if (v0223 == v0095) goto v0155;
    v0223 = v0224;
    v0095 = elt(env, 3); /* false */
    v0095 = (v0223 == v0095 ? lisp_true : nil);
    goto v0009;

v0009:
    if (v0095 == nil) goto v0045;
    v0223 = stack[-3];
    v0095 = stack[-2];
    popv(6);
    return cons(v0223, v0095);

v0045:
    v0223 = v0224;
    v0095 = elt(env, 4); /* or */
    if (v0223 == v0095) goto v0023;
    v0223 = v0224;
    v0095 = elt(env, 5); /* and */
    v0095 = (v0223 == v0095 ? lisp_true : nil);
    goto v0228;

v0228:
    if (v0095 == nil) goto v0022;
    v0095 = qvalue(elt(env, 2)); /* t */
    goto v0229;

v0229:
    if (v0095 == nil) goto v0073;
    v0095 = qvalue(elt(env, 2)); /* t */
    goto v0230;

v0230:
    if (v0095 == nil) goto v0231;
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    stack[-1] = v0095;
    goto v0232;

v0232:
    v0095 = stack[-1];
    if (v0095 == nil) goto v0090;
    v0095 = stack[-1];
    v0095 = qcar(v0095);
    v0225 = v0095;
    v0224 = stack[-3];
    v0223 = stack[0];
    v0095 = stack[-2];
    v0095 = CC_cl_varl2(env, 4, v0225, v0224, v0223, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0223 = v0095;
    v0095 = v0223;
    v0095 = qcar(v0095);
    stack[-3] = v0095;
    v0095 = v0223;
    v0095 = qcdr(v0095);
    stack[-2] = v0095;
    v0095 = stack[-1];
    v0095 = qcdr(v0095);
    stack[-1] = v0095;
    goto v0232;

v0090:
    v0223 = stack[-3];
    v0095 = stack[-2];
    popv(6);
    return cons(v0223, v0095);

v0231:
    v0223 = v0224;
    v0095 = elt(env, 11); /* ex */
    if (v0223 == v0095) goto v0234;
    v0223 = v0224;
    v0095 = elt(env, 12); /* all */
    v0095 = (v0223 == v0095 ? lisp_true : nil);
    goto v0162;

v0162:
    if (v0095 == nil) goto v0125;
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    v0095 = qcdr(v0095);
    stack[-1] = qcar(v0095);
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    v0223 = qcar(v0095);
    v0095 = stack[0];
    fn = elt(env, 15); /* lto_insertq */
    stack[0] = (*qfn2(fn))(qenv(fn), v0223, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    v0223 = qcar(v0095);
    v0095 = stack[-2];
    v0095 = cons(v0223, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    stack[-4] = stack[-1];
    stack[-2] = v0095;
    goto v0226;

v0125:
    v0223 = v0224;
    v0095 = elt(env, 13); /* bex */
    if (v0223 == v0095) goto v0235;
    v0223 = v0224;
    v0095 = elt(env, 14); /* ball */
    v0095 = (v0223 == v0095 ? lisp_true : nil);
    goto v0236;

v0236:
    if (v0095 == nil) goto v0237;
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    stack[-1] = qcar(v0095);
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    v0095 = qcdr(v0095);
    v0095 = qcdr(v0095);
    v0225 = qcar(v0095);
    v0224 = stack[-3];
    v0223 = qvalue(elt(env, 10)); /* nil */
    v0095 = qvalue(elt(env, 10)); /* nil */
    v0095 = CC_cl_varl2(env, 4, v0225, v0224, v0223, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0095 = qcar(v0095);
    fn = elt(env, 16); /* delq */
    v0095 = (*qfn2(fn))(qenv(fn), stack[-1], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    stack[-1] = v0095;
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    v0095 = qcdr(v0095);
    stack[-3] = qcar(v0095);
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    v0223 = qcar(v0095);
    v0095 = stack[0];
    fn = elt(env, 15); /* lto_insertq */
    stack[0] = (*qfn2(fn))(qenv(fn), v0223, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    v0223 = qcar(v0095);
    v0095 = stack[-2];
    v0095 = cons(v0223, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0095 = CC_cl_varl2(env, 4, stack[-3], stack[-1], stack[0], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    stack[-1] = v0095;
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    v0223 = qcar(v0095);
    v0095 = stack[-1];
    v0095 = qcar(v0095);
    fn = elt(env, 16); /* delq */
    v0223 = (*qfn2(fn))(qenv(fn), v0223, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    v0095 = stack[-1];
    v0095 = qcdr(v0095);
    popv(6);
    return cons(v0223, v0095);

v0237:
    v0095 = stack[-4];
    fn = elt(env, 17); /* rl_varlat */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    stack[-1] = v0095;
    goto v0238;

v0238:
    v0095 = stack[-1];
    if (v0095 == nil) goto v0239;
    v0095 = stack[-1];
    v0095 = qcar(v0095);
    v0224 = v0095;
    v0223 = v0224;
    v0095 = stack[0];
    v0095 = Lmemq(nil, v0223, v0095);
    if (!(v0095 == nil)) goto v0240;
    v0223 = v0224;
    v0095 = stack[-3];
    fn = elt(env, 15); /* lto_insertq */
    v0095 = (*qfn2(fn))(qenv(fn), v0223, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    stack[-3] = v0095;
    goto v0240;

v0240:
    v0095 = stack[-1];
    v0095 = qcdr(v0095);
    stack[-1] = v0095;
    goto v0238;

v0239:
    v0223 = stack[-3];
    v0095 = stack[-2];
    popv(6);
    return cons(v0223, v0095);

v0235:
    v0095 = qvalue(elt(env, 2)); /* t */
    goto v0236;

v0234:
    v0095 = qvalue(elt(env, 2)); /* t */
    goto v0162;

v0073:
    v0223 = v0224;
    v0095 = elt(env, 7); /* impl */
    if (v0223 == v0095) goto v0077;
    v0223 = v0224;
    v0095 = elt(env, 8); /* repl */
    if (v0223 == v0095) goto v0241;
    v0223 = v0224;
    v0095 = elt(env, 9); /* equiv */
    v0095 = (v0223 == v0095 ? lisp_true : nil);
    goto v0230;

v0241:
    v0095 = qvalue(elt(env, 2)); /* t */
    goto v0230;

v0077:
    v0095 = qvalue(elt(env, 2)); /* t */
    goto v0230;

v0022:
    v0223 = v0224;
    v0095 = elt(env, 6); /* not */
    v0095 = (v0223 == v0095 ? lisp_true : nil);
    goto v0229;

v0023:
    v0095 = qvalue(elt(env, 2)); /* t */
    goto v0228;

v0155:
    v0095 = qvalue(elt(env, 2)); /* t */
    goto v0009;

v0085:
    v0095 = stack[-4];
    goto v0227;
/* error exit handlers */
v0233:
    popv(6);
    return nil;
}



/* Code for mathml2 */

static Lisp_Object MS_CDECL CC_mathml2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mathml2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    {
        fn = elt(env, 2); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
}



/* Code for newenv */

static Lisp_Object CC_newenv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0227, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newenv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0227 = v0000;
/* end of prologue */
    v0085 = v0227;
    v0227 = elt(env, 1); /* unbound */
    {
        fn = elt(env, 2); /* bind */
        return (*qfn2(fn))(qenv(fn), v0085, v0227);
    }
}



/* Code for wedgepf */

static Lisp_Object CC_wedgepf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0044;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgepf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0002 = v0046;
    v0044 = v0000;
/* end of prologue */
    stack[0] = v0044;
    fn = elt(env, 1); /* !*pf2wedgepf */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-1];
    fn = elt(env, 2); /* wedgepf2 */
    v0002 = (*qfn2(fn))(qenv(fn), stack[0], v0002);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* !*wedgepf2pf */
        return (*qfn1(fn))(qenv(fn), v0002);
    }
/* error exit handlers */
v0029:
    popv(2);
    return nil;
}



/* Code for prinfit */

static Lisp_Object MS_CDECL CC_prinfit(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0046,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0045, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prinfit");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prinfit");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0014,v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0046,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0046;
    stack[-2] = v0000;
/* end of prologue */
    v0024 = qvalue(elt(env, 1)); /* !*nat */
    if (v0024 == nil) goto v0002;
    v0024 = qvalue(elt(env, 3)); /* testing!-width!* */
    goto v0055;

v0055:
    if (v0024 == nil) goto v0025;
    v0024 = stack[0];
    if (v0024 == nil) goto v0008;
    v0024 = stack[0];
    fn = elt(env, 4); /* oprin */
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    goto v0008;

v0008:
    v0045 = stack[-2];
    v0024 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); /* maprint */
        return (*qfn2(fn))(qenv(fn), v0045, v0024);
    }

v0025:
    v0050 = stack[-2];
    v0045 = stack[-1];
    v0024 = stack[0];
    fn = elt(env, 6); /* layout!-formula */
    v0024 = (*qfnn(fn))(qenv(fn), 3, v0050, v0045, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0045 = v0024;
    v0024 = v0045;
    if (v0024 == nil) goto v0243;
    v0024 = v0045;
    fn = elt(env, 7); /* putpline */
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    v0024 = nil;
    { popv(4); return onevalue(v0024); }

v0243:
    v0024 = stack[0];
    if (v0024 == nil) goto v0081;
    v0024 = stack[0];
    fn = elt(env, 4); /* oprin */
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    goto v0081;

v0081:
    v0045 = stack[-2];
    v0024 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); /* maprint */
        return (*qfn2(fn))(qenv(fn), v0045, v0024);
    }

v0002:
    v0024 = qvalue(elt(env, 2)); /* t */
    goto v0055;
/* error exit handlers */
v0218:
    popv(4);
    return nil;
}



/* Code for prop!-simp */

static Lisp_Object CC_propKsimp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0245, v0004, v0001, v0007, v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0245 = v0046;
    v0004 = v0000;
/* end of prologue */
    v0009 = v0004;
    v0007 = v0245;
    v0001 = qvalue(elt(env, 1)); /* nil */
    v0004 = (Lisp_Object)1; /* 0 */
    v0245 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 2); /* prop!-simp1 */
        return (*qfnn(fn))(qenv(fn), 5, v0009, v0007, v0001, v0004, v0245);
    }
}



/* Code for quotdd */

static Lisp_Object CC_quotdd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0019, v0249;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotdd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    stack[-1] = v0000;
/* end of prologue */
    v0018 = stack[-1];
    if (!(!consp(v0018))) goto v0250;
    v0018 = stack[0];
    if (!consp(v0018)) goto v0156;
    v0018 = stack[0];
    v0019 = qcar(v0018);
    v0018 = elt(env, 2); /* i2d */
    v0018 = get(v0019, v0018);
    env = stack[-2];
    v0249 = v0018;
    if (v0018 == nil) goto v0219;
    v0019 = v0249;
    v0018 = stack[-1];
    v0018 = Lapply1(nil, v0019, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-2];
    stack[-1] = v0018;
    goto v0250;

v0250:
    v0249 = stack[-1];
    v0019 = stack[0];
    v0018 = elt(env, 3); /* quotient */
    {
        popv(3);
        fn = elt(env, 4); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0249, v0019, v0018);
    }

v0219:
    v0018 = stack[0];
    if (!consp(v0018)) goto v0024;
    v0018 = qvalue(elt(env, 1)); /* nil */
    goto v0049;

v0049:
    if (v0018 == nil) goto v0250;
    v0019 = v0249;
    v0018 = stack[0];
    v0018 = Lapply1(nil, v0019, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-2];
    stack[0] = v0018;
    goto v0250;

v0024:
    v0018 = stack[-1];
    v0019 = qcar(v0018);
    v0018 = elt(env, 2); /* i2d */
    v0018 = get(v0019, v0018);
    env = stack[-2];
    v0249 = v0018;
    goto v0049;

v0156:
    v0019 = stack[-1];
    v0018 = stack[0];
    v0018 = Ldivide(nil, v0019, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-2];
    v0249 = v0018;
    v0018 = v0249;
    v0019 = qcdr(v0018);
    v0018 = (Lisp_Object)1; /* 0 */
    if (v0019 == v0018) goto v0005;
    v0018 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0018); }

v0005:
    v0018 = v0249;
    v0018 = qcar(v0018);
    { popv(3); return onevalue(v0018); }
/* error exit handlers */
v0077:
    popv(3);
    return nil;
}



/* Code for formclis */

static Lisp_Object MS_CDECL CC_formclis(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0046,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0026, v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formclis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0014,v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0046,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0046;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0033;

v0033:
    v0025 = stack[-2];
    if (v0025 == nil) goto v0227;
    v0025 = stack[-2];
    v0040 = qcar(v0025);
    v0026 = stack[-1];
    v0025 = stack[0];
    fn = elt(env, 1); /* formc */
    v0026 = (*qfnn(fn))(qenv(fn), 3, v0040, v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-4];
    v0025 = stack[-3];
    v0025 = cons(v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-4];
    stack[-3] = v0025;
    v0025 = stack[-2];
    v0025 = qcdr(v0025);
    stack[-2] = v0025;
    goto v0033;

v0227:
    v0025 = stack[-3];
        popv(5);
        return Lnreverse(nil, v0025);
/* error exit handlers */
v0039:
    popv(5);
    return nil;
}



/* Code for mv!-domainlist!-!- */

static Lisp_Object CC_mvKdomainlistKK(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist--");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0031;

v0031:
    v0026 = stack[-1];
    if (v0026 == nil) goto v0034;
    v0026 = stack[-1];
    v0040 = qcar(v0026);
    v0026 = stack[0];
    v0026 = qcar(v0026);
    v0040 = difference2(v0040, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    v0026 = stack[-2];
    v0026 = cons(v0040, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    stack[-2] = v0026;
    v0026 = stack[-1];
    v0026 = qcdr(v0026);
    stack[-1] = v0026;
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    stack[0] = v0026;
    goto v0031;

v0034:
    v0026 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0026);
    }
/* error exit handlers */
v0219:
    popv(4);
    return nil;
}



/* Code for red_better */

static Lisp_Object CC_red_better(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_better");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    v0002 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* bas_dplen */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0002 = stack[0];
    fn = elt(env, 1); /* bas_dplen */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    {
        Lisp_Object v0156 = stack[-1];
        popv(3);
        return Llessp(nil, v0156, v0002);
    }
/* error exit handlers */
v0029:
    popv(3);
    return nil;
}



/* Code for pneg */

static Lisp_Object CC_pneg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0229, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pneg");
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
/* copy arguments values to proper place */
    v0229 = v0000;
/* end of prologue */
    stack[-4] = v0229;
    v0229 = stack[-4];
    if (v0229 == nil) goto v0085;
    v0229 = stack[-4];
    v0229 = qcar(v0229);
    v0049 = v0229;
    v0229 = v0049;
    stack[0] = qcar(v0229);
    v0229 = v0049;
    v0229 = qcdr(v0229);
    fn = elt(env, 2); /* cneg */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0229 = cons(stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0229 = ncons(v0229);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    stack[-2] = v0229;
    stack[-3] = v0229;
    goto v0033;

v0033:
    v0229 = stack[-4];
    v0229 = qcdr(v0229);
    stack[-4] = v0229;
    v0229 = stack[-4];
    if (v0229 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0229 = stack[-4];
    v0229 = qcar(v0229);
    v0049 = v0229;
    v0229 = v0049;
    stack[0] = qcar(v0229);
    v0229 = v0049;
    v0229 = qcdr(v0229);
    fn = elt(env, 2); /* cneg */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0229 = cons(stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0229 = ncons(v0229);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0229 = Lrplacd(nil, stack[-1], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-5];
    v0229 = stack[-2];
    v0229 = qcdr(v0229);
    stack[-2] = v0229;
    goto v0033;

v0085:
    v0229 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0229); }
/* error exit handlers */
v0045:
    popv(6);
    return nil;
}



/* Code for dl_get */

static Lisp_Object CC_dl_get(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0227, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dl_get");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0227 = v0000;
/* end of prologue */
    v0085 = v0227;
    v0227 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* dl_get2 */
        return (*qfn2(fn))(qenv(fn), v0085, v0227);
    }
}



/* Code for artimes!: */

static Lisp_Object CC_artimesT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0006, v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for artimes:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0006 = v0046;
    v0008 = v0000;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = nil; /* !*exp */
    v0005 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v0005; /* !*exp */
    stack[0] = elt(env, 4); /* !:ar!: */
    v0005 = v0008;
    v0005 = qcdr(v0005);
    v0006 = qcdr(v0006);
    fn = elt(env, 5); /* multf */
    v0005 = (*qfn2(fn))(qenv(fn), v0005, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    fn = elt(env, 6); /* reducepowers */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    v0005 = cons(stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v0005); }
/* error exit handlers */
v0089:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for traput */

static Lisp_Object MS_CDECL CC_traput(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0046,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042, v0228, v0023, v0024;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "traput");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for traput");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0014,v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0046,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0042 = v0014;
    v0228 = v0046;
    v0023 = v0000;
/* end of prologue */
    v0024 = v0023;
    v0041 = v0228;
    v0041 = get(v0024, v0041);
    env = stack[-2];
    v0024 = v0041;
    if (v0041 == nil) goto v0253;
    v0041 = qvalue(elt(env, 1)); /* toplv!* */
    if (!(v0041 == nil)) goto v0011;
    v0228 = v0042;
    v0041 = v0024;
    v0041 = Lmemq(nil, v0228, v0041);
    if (!(v0041 == nil)) goto v0011;
    stack[0] = v0024;
    v0041 = v0042;
    v0042 = v0024;
    v0042 = qcdr(v0042);
    v0041 = cons(v0041, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-2];
    v0041 = Lrplacd(nil, stack[0], v0041);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    goto v0011;

v0011:
    v0041 = nil;
    { popv(3); return onevalue(v0041); }

v0253:
    stack[-1] = v0023;
    stack[0] = v0228;
    v0041 = v0042;
    v0041 = ncons(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-2];
    v0041 = Lputprop(nil, 3, stack[-1], stack[0], v0041);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    goto v0011;
/* error exit handlers */
v0082:
    popv(3);
    return nil;
}



/* Code for rl_simpl */

static Lisp_Object MS_CDECL CC_rl_simpl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0046,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001, v0007, v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rl_simpl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0014,v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0046,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0001 = v0014;
    v0007 = v0046;
    v0009 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_simpl!* */
    v0001 = list3(v0009, v0007, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-1];
    {
        Lisp_Object v0006 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0006, v0001);
    }
/* error exit handlers */
v0005:
    popv(2);
    return nil;
}



/* Code for removeg2 */

static Lisp_Object MS_CDECL CC_removeg2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0046,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0263, v0264, v0265, v0266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "removeg2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeg2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0014,v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0046,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0014;
    stack[-4] = v0046;
    stack[-5] = v0000;
/* end of prologue */
    v0263 = stack[-4];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0264 = v0263;
    v0263 = stack[-3];
    v0265 = qcar(v0263);
    v0263 = elt(env, 1); /* g3 */
    if (v0265 == v0263) goto v0058;
    v0263 = qvalue(elt(env, 2)); /* t */
    goto v0004;

v0004:
    if (v0263 == nil) goto v0049;
    v0266 = elt(env, 3); /* "Edge" */
    v0265 = v0264;
    v0264 = elt(env, 4); /* "is absent in vertex" */
    v0263 = stack[-3];
    v0263 = list4(v0266, v0265, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    fn = elt(env, 6); /* cerror */
    v0263 = (*qfn1(fn))(qenv(fn), v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    goto v0156;

v0156:
    stack[-3] = v0263;
    v0264 = stack[-3];
    v0263 = elt(env, 5); /* qg */
    v0263 = Lrplaca(nil, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    v0263 = stack[-5];
    stack[0] = qcar(v0263);
    v0263 = stack[-5];
    v0263 = qcdr(v0263);
    fn = elt(env, 7); /* mkcopy */
    v0263 = (*qfn1(fn))(qenv(fn), v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    v0263 = cons(stack[0], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    stack[-6] = v0263;
    v0264 = stack[-4];
    v0263 = stack[-6];
    v0263 = Lmember(nil, v0264, v0263);
    v0263 = qcar(v0263);
    stack[-1] = v0263;
    v0264 = stack[-3];
    v0263 = stack[-6];
    v0263 = Lmember(nil, v0264, v0263);
    v0263 = qcar(v0263);
    stack[0] = v0263;
    v0263 = stack[-4];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    stack[-2] = v0263;
    v0263 = stack[-4];
    v0263 = qcdr(v0263);
    v0264 = qcdr(v0263);
    v0263 = stack[-4];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = Lrplaca(nil, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    v0263 = stack[-4];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0264 = qcdr(v0263);
    v0263 = stack[-3];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = Lrplaca(nil, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    v0263 = stack[-3];
    v0263 = qcdr(v0263);
    v0264 = qcdr(v0263);
    v0263 = stack[-2];
    v0263 = Lrplaca(nil, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    v0263 = stack[-1];
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    stack[-2] = v0263;
    v0263 = stack[-1];
    v0264 = qcdr(v0263);
    v0263 = stack[-1];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = Lrplaca(nil, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    v0263 = stack[-1];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0264 = qcdr(v0263);
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = Lrplaca(nil, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0264 = qcdr(v0263);
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = Lrplaca(nil, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    v0263 = stack[0];
    v0264 = qcdr(v0263);
    v0263 = stack[-2];
    v0263 = Lrplaca(nil, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    stack[0] = stack[-5];
    v0263 = stack[-6];
    v0263 = qcar(v0263);
    v0263 = qcar(v0263);
    fn = elt(env, 8); /* negf */
    v0264 = (*qfn1(fn))(qenv(fn), v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    v0263 = stack[-6];
    v0263 = qcar(v0263);
    v0263 = qcdr(v0263);
    v0264 = cons(v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    v0263 = stack[-6];
    v0263 = qcdr(v0263);
    {
        Lisp_Object v0130 = stack[0];
        popv(8);
        return list2star(v0130, v0264, v0263);
    }

v0049:
    v0263 = stack[-3];
    fn = elt(env, 9); /* revv0 */
    v0263 = (*qfn2(fn))(qenv(fn), v0263, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    goto v0156;

v0058:
    v0265 = v0264;
    v0263 = stack[-3];
    v0263 = qcdr(v0263);
    v0263 = Lmemq(nil, v0265, v0263);
    v0263 = (v0263 == nil ? lisp_true : nil);
    goto v0004;
/* error exit handlers */
v0129:
    popv(8);
    return nil;
}



/* Code for rl_susipost */

static Lisp_Object CC_rl_susipost(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0244, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_susipost");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0244 = v0046;
    v0003 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susipost!* */
    v0244 = list2(v0003, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    {
        Lisp_Object v0001 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0001, v0244);
    }
/* error exit handlers */
v0004:
    popv(2);
    return nil;
}



/* Code for ibalp_getvar!-zmom */

static Lisp_Object CC_ibalp_getvarKzmom(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getvar-zmom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0032 = v0046;
    stack[0] = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = nil;
    fn = elt(env, 2); /* ibalp_minclnr */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    stack[-5] = v0032;
    v0032 = (Lisp_Object)-15; /* -1 */
    stack[-3] = v0032;
    v0032 = stack[0];
    stack[-1] = v0032;
    goto v0029;

v0029:
    v0032 = stack[-1];
    if (v0032 == nil) goto v0247;
    v0032 = stack[-1];
    v0032 = qcar(v0032);
    stack[0] = v0032;
    v0032 = stack[0];
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    if (v0032 == nil) goto v0059;
    v0032 = qvalue(elt(env, 1)); /* nil */
    goto v0089;

v0089:
    if (v0032 == nil) goto v0008;
    v0032 = stack[0];
    v0213 = qcdr(v0032);
    v0032 = stack[-5];
    fn = elt(env, 3); /* ibalp_isinminclause */
    v0032 = (*qfn2(fn))(qenv(fn), v0213, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-6];
    if (v0032 == nil) goto v0008;
    v0032 = stack[0];
    v0032 = qcdr(v0032);
    stack[-4] = v0032;
    v0032 = stack[-2];
    stack[-3] = v0032;
    goto v0008;

v0008:
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    stack[-1] = v0032;
    goto v0029;

v0059:
    v0032 = stack[0];
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0213 = qcar(v0032);
    stack[-2] = v0213;
    v0032 = stack[-3];
    v0032 = (Lisp_Object)greaterp2(v0213, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    v0032 = v0032 ? lisp_true : nil;
    env = stack[-6];
    goto v0089;

v0247:
    v0032 = stack[-4];
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0213 = qcar(v0032);
    v0032 = stack[-4];
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    v0032 = (Lisp_Object)greaterp2(v0213, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    v0032 = v0032 ? lisp_true : nil;
    if (v0032 == nil) goto v0074;
    v0032 = (Lisp_Object)17; /* 1 */
    goto v0241;

v0241:
    v0213 = stack[-4];
    popv(7);
    return cons(v0213, v0032);

v0074:
    v0032 = (Lisp_Object)1; /* 0 */
    goto v0241;
/* error exit handlers */
v0269:
    popv(7);
    return nil;
}



/* Code for ldt!-tvar */

static Lisp_Object CC_ldtKtvar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0155, v0005;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldt-tvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0009 = v0000;
/* end of prologue */
    v0009 = qcar(v0009);
    v0009 = qcar(v0009);
    v0155 = v0009;
    v0009 = v0155;
    v0005 = elt(env, 1); /* df */
    if (!consp(v0009)) return onevalue(v0155);
    v0009 = qcar(v0009);
    if (!(v0009 == v0005)) return onevalue(v0155);
    v0009 = v0155;
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    return onevalue(v0009);
}



/* Code for groebnormalform */

static Lisp_Object MS_CDECL CC_groebnormalform(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0046,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0244, v0003, v0245, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groebnormalform");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebnormalform");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0244 = v0014;
    v0003 = v0046;
    v0245 = v0000;
/* end of prologue */
    v0004 = v0245;
    v0245 = v0003;
    v0003 = v0244;
    v0244 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* groebnormalform0 */
        return (*qfnn(fn))(qenv(fn), 4, v0004, v0245, v0003, v0244);
    }
}



/* Code for simpindexvar */

static Lisp_Object CC_simpindexvar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpindexvar");
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
    v0053 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* partitindexvar */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v0053);
    }
/* error exit handlers */
v0031:
    popv(1);
    return nil;
}



/* Code for ptoken */

static Lisp_Object MS_CDECL CC_ptoken(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ptoken");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ptoken");
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
    fn = elt(env, 7); /* token1 */
    v0036 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-1];
    stack[0] = v0036;
    v0035 = stack[0];
    v0036 = elt(env, 1); /* !) */
    if (v0035 == v0036) goto v0004;
    v0036 = qvalue(elt(env, 4)); /* nil */
    goto v0227;

v0227:
    if (v0036 == nil) goto v0054;
    v0036 = qvalue(elt(env, 2)); /* outl!* */
    v0036 = qcdr(v0036);
    qvalue(elt(env, 2)) = v0036; /* outl!* */
    goto v0054;

v0054:
    v0035 = stack[0];
    v0036 = qvalue(elt(env, 2)); /* outl!* */
    v0036 = cons(v0035, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0036; /* outl!* */
    v0035 = stack[0];
    v0036 = elt(env, 5); /* !( */
    if (v0035 == v0036) goto v0088;
    v0035 = stack[0];
    v0036 = elt(env, 1); /* !) */
    v0036 = (v0035 == v0036 ? lisp_true : nil);
    goto v0084;

v0084:
    if (!(v0036 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0035 = elt(env, 3); /* !  */
    v0036 = qvalue(elt(env, 2)); /* outl!* */
    v0036 = cons(v0035, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0036; /* outl!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0088:
    v0036 = qvalue(elt(env, 6)); /* t */
    goto v0084;

v0004:
    v0035 = qvalue(elt(env, 2)); /* outl!* */
    v0036 = elt(env, 3); /* !  */
    v0036 = Leqcar(nil, v0035, v0036);
    env = stack[-1];
    goto v0227;
/* error exit handlers */
v0151:
    popv(2);
    return nil;
}



/* Code for evalneq */

static Lisp_Object CC_evalneq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalneq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0055 = v0046;
    v0002 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* evalequal */
    v0055 = (*qfn2(fn))(qenv(fn), v0002, v0055);
    errexit();
    v0055 = (v0055 == nil ? lisp_true : nil);
    return onevalue(v0055);
}



/* Code for mv!-pow!-!- */

static Lisp_Object CC_mvKpowKK(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow--");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0031;

v0031:
    v0026 = stack[-1];
    if (v0026 == nil) goto v0034;
    v0026 = stack[-1];
    v0040 = qcar(v0026);
    v0026 = stack[0];
    v0026 = qcar(v0026);
    v0040 = difference2(v0040, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    v0026 = stack[-2];
    v0026 = cons(v0040, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    stack[-2] = v0026;
    v0026 = stack[-1];
    v0026 = qcdr(v0026);
    stack[-1] = v0026;
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    stack[0] = v0026;
    goto v0031;

v0034:
    v0026 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0026);
    }
/* error exit handlers */
v0219:
    popv(4);
    return nil;
}



/* Code for bc_fi */

static Lisp_Object CC_bc_fi(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0244, v0003;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_fi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0244 = v0003;
    v0156 = (Lisp_Object)1; /* 0 */
    if (!(v0244 == v0156)) return onevalue(v0003);
    v0156 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0156);
}



/* Code for pv_times3 */

static Lisp_Object CC_pv_times3(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_times3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    stack[-1] = v0000;
/* end of prologue */
    v0057 = stack[-1];
    v0012 = qcar(v0057);
    v0057 = stack[0];
    v0057 = qcar(v0057);
    stack[-2] = times2(v0012, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    v0057 = stack[-1];
    v0012 = qcdr(v0057);
    v0057 = stack[0];
    v0057 = qcdr(v0057);
    fn = elt(env, 1); /* pappend */
    v0057 = (*qfn2(fn))(qenv(fn), v0012, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    {
        Lisp_Object v0058 = stack[-2];
        popv(4);
        return cons(v0058, v0057);
    }
/* error exit handlers */
v0054:
    popv(4);
    return nil;
}



/* Code for dv_skel2factor1 */

static Lisp_Object CC_dv_skel2factor1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0247, v0149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skel2factor1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    stack[-1] = v0000;
/* end of prologue */
    v0247 = stack[-1];
    if (v0247 == nil) goto v0034;
    v0247 = stack[-1];
    fn = elt(env, 3); /* listp */
    v0247 = (*qfn1(fn))(qenv(fn), v0247);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    if (v0247 == nil) goto v0084;
    v0247 = stack[-1];
    v0149 = qcar(v0247);
    v0247 = stack[0];
    v0247 = CC_dv_skel2factor1(env, v0149, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    stack[-2] = v0247;
    v0247 = stack[-1];
    v0149 = qcdr(v0247);
    v0247 = stack[0];
    v0247 = CC_dv_skel2factor1(env, v0149, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0247 = cons(stack[-2], v0247);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    { popv(4); return onevalue(v0247); }

v0084:
    v0149 = stack[-1];
    v0247 = elt(env, 2); /* !~dv */
    if (!(v0149 == v0247)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0247 = stack[0];
    v0247 = qcar(v0247);
    stack[-1] = v0247;
    v0247 = stack[0];
    v0247 = qcdr(v0247);
    if (v0247 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0149 = stack[0];
    v0247 = stack[0];
    v0247 = qcdr(v0247);
    v0247 = qcar(v0247);
    v0247 = Lrplaca(nil, v0149, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0149 = stack[0];
    v0247 = stack[0];
    v0247 = qcdr(v0247);
    v0247 = qcdr(v0247);
    v0247 = Lrplacd(nil, v0149, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0034:
    v0247 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0247); }
/* error exit handlers */
v0150:
    popv(4);
    return nil;
}



/* Code for rnminus!: */

static Lisp_Object CC_rnminusT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnminus:");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0003 = stack[0];
    stack[-1] = qcar(v0003);
    v0003 = stack[0];
    v0003 = qcdr(v0003);
    v0003 = qcar(v0003);
    fn = elt(env, 1); /* !:minus */
    v0245 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    v0003 = stack[0];
    v0003 = qcdr(v0003);
    v0003 = qcdr(v0003);
    {
        Lisp_Object v0009 = stack[-1];
        popv(2);
        return list2star(v0009, v0245, v0003);
    }
/* error exit handlers */
v0007:
    popv(2);
    return nil;
}



/* Code for noncomperm */

static Lisp_Object CC_noncomperm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0147, v0268, v0267;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomperm");
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
    v0147 = stack[-4];
    if (v0147 == nil) goto v0010;
    v0147 = stack[-4];
    stack[-5] = v0147;
    goto v0029;

v0029:
    v0147 = stack[-5];
    if (v0147 == nil) goto v0004;
    v0147 = stack[-5];
    v0147 = qcar(v0147);
    stack[0] = v0147;
    v0268 = stack[0];
    v0147 = stack[-4];
    fn = elt(env, 3); /* noncomdel */
    v0147 = (*qfn2(fn))(qenv(fn), v0268, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0267 = v0147;
    v0268 = v0267;
    v0147 = elt(env, 2); /* failed */
    if (v0268 == v0147) goto v0030;
    v0147 = v0267;
    v0268 = CC_noncomperm(env, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0147 = stack[0];
    fn = elt(env, 4); /* mapcons */
    v0147 = (*qfn2(fn))(qenv(fn), v0268, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    goto v0040;

v0040:
    stack[-3] = v0147;
    v0147 = stack[-3];
    fn = elt(env, 5); /* lastpair */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[-2] = v0147;
    v0147 = stack[-5];
    v0147 = qcdr(v0147);
    stack[-5] = v0147;
    v0147 = stack[-2];
    if (!consp(v0147)) goto v0029;
    else goto v0156;

v0156:
    v0147 = stack[-5];
    if (v0147 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0147 = stack[-5];
    v0147 = qcar(v0147);
    stack[0] = v0147;
    v0268 = stack[0];
    v0147 = stack[-4];
    fn = elt(env, 3); /* noncomdel */
    v0147 = (*qfn2(fn))(qenv(fn), v0268, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0267 = v0147;
    v0268 = v0267;
    v0147 = elt(env, 2); /* failed */
    if (v0268 == v0147) goto v0216;
    v0147 = v0267;
    v0268 = CC_noncomperm(env, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0147 = stack[0];
    fn = elt(env, 4); /* mapcons */
    v0147 = (*qfn2(fn))(qenv(fn), v0268, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    goto v0151;

v0151:
    v0147 = Lrplacd(nil, stack[-1], v0147);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    v0147 = stack[-2];
    fn = elt(env, 5); /* lastpair */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-6];
    stack[-2] = v0147;
    v0147 = stack[-5];
    v0147 = qcdr(v0147);
    stack[-5] = v0147;
    goto v0156;

v0216:
    v0147 = qvalue(elt(env, 1)); /* nil */
    goto v0151;

v0030:
    v0147 = qvalue(elt(env, 1)); /* nil */
    goto v0040;

v0004:
    v0147 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0147); }

v0010:
    v0147 = stack[-4];
    popv(7);
    return ncons(v0147);
/* error exit handlers */
v0064:
    popv(7);
    return nil;
}



/* Code for gcref_mkgraph */

static Lisp_Object CC_gcref_mkgraph(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0044;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcref_mkgraph");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0044 = v0000;
/* end of prologue */
    v0002 = qvalue(elt(env, 1)); /* !*gcrefudg */
    if (v0002 == nil) goto v0034;
    v0002 = v0044;
    {
        fn = elt(env, 2); /* gcref_mkgraph!-udg */
        return (*qfn1(fn))(qenv(fn), v0002);
    }

v0034:
    v0002 = v0044;
    {
        fn = elt(env, 3); /* gcref_mkgraph!-tgf */
        return (*qfn1(fn))(qenv(fn), v0002);
    }
}



/* Code for rl_simpbop */

static Lisp_Object CC_rl_simpbop(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0253, v0152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpbop");
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
/* copy arguments values to proper place */
    v0152 = v0000;
/* end of prologue */
    v0253 = v0152;
    stack[-4] = qcar(v0253);
    v0253 = v0152;
    v0253 = qcdr(v0253);
    stack[-3] = v0253;
    v0253 = stack[-3];
    if (v0253 == nil) goto v0245;
    v0253 = stack[-3];
    v0253 = qcar(v0253);
    fn = elt(env, 2); /* rl_simp1 */
    v0253 = (*qfn1(fn))(qenv(fn), v0253);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-5];
    v0253 = ncons(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-5];
    stack[-1] = v0253;
    stack[-2] = v0253;
    goto v0043;

v0043:
    v0253 = stack[-3];
    v0253 = qcdr(v0253);
    stack[-3] = v0253;
    v0253 = stack[-3];
    if (v0253 == nil) goto v0054;
    stack[0] = stack[-1];
    v0253 = stack[-3];
    v0253 = qcar(v0253);
    fn = elt(env, 2); /* rl_simp1 */
    v0253 = (*qfn1(fn))(qenv(fn), v0253);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-5];
    v0253 = ncons(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-5];
    v0253 = Lrplacd(nil, stack[0], v0253);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-5];
    v0253 = stack[-1];
    v0253 = qcdr(v0253);
    stack[-1] = v0253;
    goto v0043;

v0054:
    v0253 = stack[-2];
    goto v0031;

v0031:
    {
        Lisp_Object v0038 = stack[-4];
        popv(6);
        return cons(v0038, v0253);
    }

v0245:
    v0253 = qvalue(elt(env, 1)); /* nil */
    goto v0031;
/* error exit handlers */
v0037:
    popv(6);
    return nil;
}



/* Code for ratpoly_mvartest */

static Lisp_Object CC_ratpoly_mvartest(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0012, v0013;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_mvartest");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0012 = v0046;
    v0013 = v0000;
/* end of prologue */
    v0057 = v0013;
    v0057 = qcar(v0057);
    if (v0057 == nil) goto v0053;
    v0057 = v0013;
    v0057 = qcar(v0057);
    if (is_number(v0057)) goto v0227;
    v0057 = v0013;
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0057 = (v0057 == v0012 ? lisp_true : nil);
    return onevalue(v0057);

v0227:
    v0057 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0057);

v0053:
    v0057 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0057);
}



/* Code for vdp_zero!? */

static Lisp_Object CC_vdp_zeroW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_zero?");
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
    v0053 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* vdp_poly */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    errexit();
    v0053 = (v0053 == nil ? lisp_true : nil);
    return onevalue(v0053);
}



/* Code for attributesml */

static Lisp_Object CC_attributesml(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0271, v0079;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for attributesml");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    stack[-1] = v0000;
/* end of prologue */
    v0271 = stack[-1];
    if (v0271 == nil) goto v0033;
    v0271 = elt(env, 2); /* " " */
    v0271 = Lprinc(nil, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0271 = stack[-1];
    v0271 = qcar(v0271);
    v0271 = qcar(v0271);
    v0271 = Lprinc(nil, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0271 = elt(env, 3); /* "=""" */
    v0271 = Lprinc(nil, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0271 = stack[-1];
    v0271 = qcar(v0271);
    v0079 = qcar(v0271);
    v0271 = elt(env, 4); /* definitionurl */
    if (v0079 == v0271) goto v0038;
    v0271 = stack[-1];
    v0271 = qcar(v0271);
    v0271 = qcdr(v0271);
    v0079 = qcar(v0271);
    v0271 = elt(env, 5); /* vectorml */
    if (v0079 == v0271) goto v0030;
    v0271 = stack[-1];
    v0271 = qcar(v0271);
    v0271 = qcdr(v0271);
    v0271 = qcar(v0271);
    v0271 = Lprinc(nil, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    goto v0155;

v0155:
    v0271 = elt(env, 8); /* """" */
    v0271 = Lprinc(nil, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0271 = stack[-1];
    v0079 = qcdr(v0271);
    v0271 = stack[0];
    v0271 = CC_attributesml(env, v0079, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    goto v0031;

v0031:
    v0271 = nil;
    { popv(3); return onevalue(v0271); }

v0030:
    v0271 = elt(env, 6); /* "vector" */
    v0271 = Lprinc(nil, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    goto v0155;

v0038:
    v0271 = stack[-1];
    v0271 = qcar(v0271);
    v0271 = qcdr(v0271);
    v0271 = qcar(v0271);
    fn = elt(env, 9); /* list2string */
    v0271 = (*qfn1(fn))(qenv(fn), v0271);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    goto v0155;

v0033:
    v0271 = stack[0];
    v0271 = Lprinc(nil, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0271 = elt(env, 1); /* ">" */
    v0271 = Lprinc(nil, v0271);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    goto v0031;
/* error exit handlers */
v0217:
    popv(3);
    return nil;
}



/* Code for greaterp!: */

static Lisp_Object CC_greaterpT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0133, v0282, v0257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greaterp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    v0257 = v0000;
/* end of prologue */
    v0133 = v0257;
    v0133 = qcdr(v0133);
    v0282 = qcar(v0133);
    v0133 = (Lisp_Object)1; /* 0 */
    if (v0282 == v0133) goto v0156;
    v0133 = stack[0];
    v0133 = qcdr(v0133);
    v0282 = qcar(v0133);
    v0133 = (Lisp_Object)1; /* 0 */
    if (v0282 == v0133) goto v0040;
    v0133 = v0257;
    v0133 = qcdr(v0133);
    v0282 = qcdr(v0133);
    v0133 = stack[0];
    v0133 = qcdr(v0133);
    v0133 = qcdr(v0133);
    if (equal(v0282, v0133)) goto v0038;
    v0133 = v0257;
    fn = elt(env, 2); /* csl_normbf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-5];
    v0133 = stack[0];
    fn = elt(env, 2); /* csl_normbf */
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-5];
    stack[0] = v0133;
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    v0282 = qcdr(v0133);
    v0133 = stack[0];
    v0133 = qcdr(v0133);
    v0133 = qcdr(v0133);
    v0257 = difference2(v0282, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-5];
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    v0282 = qcar(v0133);
    v0133 = stack[0];
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    stack[-4] = v0257;
    stack[-3] = v0282;
    stack[-2] = v0133;
    v0282 = stack[-4];
    v0133 = (Lisp_Object)1; /* 0 */
    if (v0282 == v0133) goto v0074;
    v0282 = (Lisp_Object)33; /* 2 */
    v0133 = qvalue(elt(env, 1)); /* !:bprec!: */
    v0133 = times2(v0282, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-5];
    stack[-1] = v0133;
    v0282 = stack[-4];
    v0133 = stack[-1];
    v0133 = (Lisp_Object)greaterp2(v0282, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0133 = v0133 ? lisp_true : nil;
    env = stack[-5];
    if (v0133 == nil) goto v0091;
    v0282 = stack[-3];
    v0133 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v0282, v0133);

v0091:
    stack[0] = stack[-4];
    v0133 = stack[-1];
    v0133 = negate(v0133);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-5];
    v0133 = (Lisp_Object)lessp2(stack[0], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0133 = v0133 ? lisp_true : nil;
    env = stack[-5];
    if (v0133 == nil) goto v0283;
    v0282 = stack[-2];
    v0133 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Llessp(nil, v0282, v0133);

v0283:
    v0282 = stack[-4];
    v0133 = (Lisp_Object)1; /* 0 */
    v0133 = (Lisp_Object)greaterp2(v0282, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0133 = v0133 ? lisp_true : nil;
    env = stack[-5];
    if (v0133 == nil) goto v0258;
    v0282 = stack[-3];
    v0133 = stack[-4];
    v0282 = Lash1(nil, v0282, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0133 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v0282, v0133);

v0258:
    stack[0] = stack[-3];
    stack[-1] = stack[-2];
    v0133 = stack[-4];
    v0133 = negate(v0133);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-5];
    v0133 = Lash1(nil, stack[-1], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    {
        Lisp_Object v0221 = stack[0];
        popv(6);
        return Lgreaterp(nil, v0221, v0133);
    }

v0074:
    v0282 = stack[-3];
    v0133 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v0282, v0133);

v0038:
    v0133 = v0257;
    v0133 = qcdr(v0133);
    v0282 = qcar(v0133);
    v0133 = stack[0];
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
        popv(6);
        return Lgreaterp(nil, v0282, v0133);

v0040:
    v0133 = v0257;
    v0133 = qcdr(v0133);
    v0282 = qcar(v0133);
    v0133 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v0282, v0133);

v0156:
    v0133 = stack[0];
    v0133 = qcdr(v0133);
    v0282 = qcar(v0133);
    v0133 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Llessp(nil, v0282, v0133);
/* error exit handlers */
v0170:
    popv(6);
    return nil;
}



/* Code for mksetq */

static Lisp_Object CC_mksetq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0230, v0081, v0037, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksetq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0081 = v0046;
    v0037 = v0000;
/* end of prologue */
    v0230 = v0037;
    if (!consp(v0230)) goto v0034;
    v0230 = v0037;
    v0038 = qcar(v0230);
    v0230 = elt(env, 2); /* setfn */
    v0230 = get(v0038, v0230);
    env = stack[0];
    v0038 = v0230;
    if (v0230 == nil) goto v0047;
    v0230 = v0038;
        popv(1);
        return Lapply2(nil, 3, v0230, v0037, v0081);

v0047:
    v0081 = v0037;
    v0230 = elt(env, 3); /* "assignment argument" */
    fn = elt(env, 4); /* typerr */
    v0230 = (*qfn2(fn))(qenv(fn), v0081, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    v0230 = nil;
    { popv(1); return onevalue(v0230); }

v0034:
    v0230 = elt(env, 1); /* setq */
    popv(1);
    return list3(v0230, v0037, v0081);
/* error exit handlers */
v0229:
    popv(1);
    return nil;
}



/* Code for aminusp!:1 */

static Lisp_Object CC_aminuspT1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0147, v0268, v0267;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aminusp:1");
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
    v0028 = stack[-1];
    fn = elt(env, 6); /* aeval!* */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-3];
    stack[-1] = v0028;
    v0028 = stack[-1];
    stack[-2] = v0028;
    v0028 = stack[-2];
    v0028 = integerp(v0028);
    if (v0028 == nil) goto v0003;
    v0028 = stack[-2];
        popv(4);
        return Lminusp(nil, v0028);

v0003:
    v0147 = stack[-2];
    v0028 = elt(env, 1); /* !*sq */
    if (!consp(v0147)) goto v0006;
    v0147 = qcar(v0147);
    if (!(v0147 == v0028)) goto v0006;

v0034:
    v0028 = stack[-2];
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    stack[-2] = v0028;
    v0028 = stack[-2];
    v0028 = qcar(v0028);
    v0028 = integerp(v0028);
    if (v0028 == nil) goto v0024;
    v0028 = stack[-2];
    v0028 = qcdr(v0028);
    v0028 = integerp(v0028);
    if (v0028 == nil) goto v0024;
    v0028 = stack[-2];
    v0028 = qcar(v0028);
        popv(4);
        return Lminusp(nil, v0028);

v0024:
    v0028 = stack[-2];
    v0147 = qcdr(v0028);
    v0028 = (Lisp_Object)17; /* 1 */
    if (v0147 == v0028) goto v0035;
    v0028 = qvalue(elt(env, 4)); /* t */
    goto v0042;

v0042:
    if (v0028 == nil) goto v0074;
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v0028 = stack[-1];
    fn = elt(env, 7); /* reval */
    v0267 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-3];
    v0268 = elt(env, 3); /* "invalid in FOR statement" */
    v0147 = qvalue(elt(env, 2)); /* nil */
    v0028 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v0028 = (*qfnn(fn))(qenv(fn), 5, stack[0], v0267, v0268, v0147, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    v0028 = nil;
    { popv(4); return onevalue(v0028); }

v0074:
    v0147 = elt(env, 5); /* !:minusp */
    v0028 = stack[-2];
        popv(4);
        return Lapply1(nil, v0147, v0028);

v0035:
    v0028 = stack[-2];
    v0028 = qcar(v0028);
    stack[-2] = v0028;
    if (!consp(v0028)) goto v0079;
    v0028 = stack[-2];
    v0028 = qcar(v0028);
    v0028 = (consp(v0028) ? nil : lisp_true);
    goto v0271;

v0271:
    v0028 = (v0028 == nil ? lisp_true : nil);
    goto v0042;

v0079:
    v0028 = qvalue(elt(env, 4)); /* t */
    goto v0271;

v0006:
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v0028 = stack[-1];
    fn = elt(env, 7); /* reval */
    v0267 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-3];
    v0268 = elt(env, 3); /* "invalid in FOR statement" */
    v0147 = qvalue(elt(env, 2)); /* nil */
    v0028 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v0028 = (*qfnn(fn))(qenv(fn), 5, stack[0], v0267, v0268, v0147, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-3];
    goto v0034;
/* error exit handlers */
v0286:
    popv(4);
    return nil;
}



/* Code for nzeros */

static Lisp_Object CC_nzeros(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0089;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nzeros");
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
    goto v0227;

v0227:
    v0089 = stack[0];
    v0013 = (Lisp_Object)1; /* 0 */
    if (v0089 == v0013) goto v0011;
    v0089 = (Lisp_Object)1; /* 0 */
    v0013 = stack[-1];
    v0013 = cons(v0089, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    stack[-1] = v0013;
    v0013 = stack[0];
    v0013 = sub1(v0013);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    stack[0] = v0013;
    goto v0227;

v0011:
    v0013 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0013);
    }
/* error exit handlers */
v0058:
    popv(3);
    return nil;
}



/* Code for dividef */

static Lisp_Object CC_dividef(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0253, v0152, v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dividef");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0048 = v0046;
    v0253 = v0000;
/* end of prologue */
    v0048 = Ldivide(nil, v0253, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[0];
    v0052 = v0048;
    v0048 = v0052;
    v0253 = qcar(v0048);
    v0048 = (Lisp_Object)1; /* 0 */
    if (v0253 == v0048) goto v0245;
    v0048 = v0052;
    v0048 = qcar(v0048);
    v0152 = v0048;
    goto v0030;

v0030:
    v0048 = v0052;
    v0253 = qcdr(v0048);
    v0048 = (Lisp_Object)1; /* 0 */
    if (v0253 == v0048) goto v0026;
    v0048 = v0052;
    v0048 = qcdr(v0048);
    goto v0029;

v0029:
    popv(1);
    return cons(v0152, v0048);

v0026:
    v0048 = qvalue(elt(env, 1)); /* nil */
    goto v0029;

v0245:
    v0048 = qvalue(elt(env, 1)); /* nil */
    v0152 = v0048;
    goto v0030;
/* error exit handlers */
v0251:
    popv(1);
    return nil;
}



/* Code for difference!-mod!-p */

static Lisp_Object CC_differenceKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difference-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0055 = v0046;
    v0002 = v0000;
/* end of prologue */
    stack[0] = v0002;
    fn = elt(env, 1); /* minus!-mod!-p */
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-1];
    {
        Lisp_Object v0029 = stack[0];
        popv(2);
        fn = elt(env, 2); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0029, v0055);
    }
/* error exit handlers */
v0043:
    popv(2);
    return nil;
}



/* Code for gcref_mkedges!-tgf */

static Lisp_Object CC_gcref_mkedgesKtgf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcref_mkedges-tgf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0006 = v0046;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = v0006;
    goto v0031;

v0031:
    v0006 = stack[-2];
    if (v0006 == nil) goto v0227;
    v0006 = stack[-2];
    v0006 = qcar(v0006);
    stack[0] = v0006;
    v0006 = stack[-1];
    v0006 = Lprinc(nil, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    v0006 = elt(env, 2); /* " " */
    v0006 = Lprinc(nil, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    v0006 = stack[0];
    v0006 = Lprinc(nil, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    v0006 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-3];
    v0006 = stack[-2];
    v0006 = qcdr(v0006);
    stack[-2] = v0006;
    goto v0031;

v0227:
    v0006 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0006); }
/* error exit handlers */
v0013:
    popv(4);
    return nil;
}



/* Code for rl_csimpl */

static Lisp_Object CC_rl_csimpl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155, v0005, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_csimpl");
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
    v0155 = qvalue(elt(env, 1)); /* !*rlsimpl */
    if (v0155 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0155 = elt(env, 2); /* rl_simpl */
    fn = elt(env, 4); /* getd */
    v0155 = (*qfn1(fn))(qenv(fn), v0155);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-1];
    if (v0155 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0006 = stack[0];
    v0005 = qvalue(elt(env, 3)); /* nil */
    v0155 = (Lisp_Object)-15; /* -1 */
    {
        popv(2);
        fn = elt(env, 2); /* rl_simpl */
        return (*qfnn(fn))(qenv(fn), 3, v0006, v0005, v0155);
    }
/* error exit handlers */
v0057:
    popv(2);
    return nil;
}



/* Code for qqe_ofsf_simplat1 */

static Lisp_Object CC_qqe_ofsf_simplat1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_simplat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    stack[-1] = v0000;
/* end of prologue */
    v0154 = stack[-1];
    v0059 = stack[0];
    fn = elt(env, 2); /* qqe_simplat1 */
    v0059 = (*qfn2(fn))(qenv(fn), v0154, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-3];
    stack[-2] = v0059;
    v0154 = stack[-2];
    v0059 = elt(env, 1); /* (true false) */
    v0059 = Lmemq(nil, v0154, v0059);
    if (!(v0059 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0059 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-3];
    fn = elt(env, 4); /* qqe_rqopp */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-3];
    if (!(v0059 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0154 = stack[-2];
    v0059 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ofsf_simplat1 */
        return (*qfn2(fn))(qenv(fn), v0154, v0059);
    }
/* error exit handlers */
v0083:
    popv(4);
    return nil;
}



/* Code for pasf_smwmkatl */

static Lisp_Object MS_CDECL CC_pasf_smwmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0046,
                         Lisp_Object v0014, Lisp_Object v0015, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0154, v0219, v0039, v0242;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smwmkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0154 = v0015;
    v0219 = v0014;
    v0039 = v0046;
    v0242 = v0000;
/* end of prologue */
    v0059 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0059 == nil) goto v0006;
    v0059 = v0242;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0059, v0039, v0219, v0154);
    }

v0006:
    v0059 = v0242;
    {
        fn = elt(env, 3); /* cl_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0059, v0039, v0219, v0154);
    }
}



/* Code for ibalp_clausep */

static Lisp_Object CC_ibalp_clausep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0172, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clausep");
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
    fn = elt(env, 3); /* ibalp_litp */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-1];
    if (!(v0172 == nil)) { popv(2); return onevalue(v0172); }
    v0172 = stack[0];
    if (!consp(v0172)) goto v0244;
    v0172 = stack[0];
    v0172 = qcar(v0172);
    v0054 = v0172;
    goto v0002;

v0002:
    v0172 = elt(env, 1); /* or */
    if (v0054 == v0172) goto v0034;
    v0172 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0172); }

v0034:
    v0172 = stack[0];
    v0172 = qcdr(v0172);
    {
        popv(2);
        fn = elt(env, 4); /* ibalp_litlp */
        return (*qfn1(fn))(qenv(fn), v0172);
    }

v0244:
    v0172 = stack[0];
    v0054 = v0172;
    goto v0002;
/* error exit handlers */
v0025:
    popv(2);
    return nil;
}



/* Code for ratpoly_ratp */

static Lisp_Object CC_ratpoly_ratp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0055;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_ratp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0085 = v0000;
/* end of prologue */
    v0055 = v0085;
    v0055 = qcar(v0055);
    v0055 = (is_number(v0055) ? lisp_true : nil);
    if (!(v0055 == nil)) return onevalue(v0055);
    v0085 = qcar(v0085);
    v0085 = (v0085 == nil ? lisp_true : nil);
    return onevalue(v0085);
}



/* Code for matrixrowrd */

static Lisp_Object MS_CDECL CC_matrixrowrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixrowrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrowrd");
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
    fn = elt(env, 2); /* mathml */
    v0001 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-1];
    v0007 = v0001;
    v0001 = v0007;
    if (v0001 == nil) goto v0011;
    stack[0] = v0007;
    v0001 = CC_matrixrowrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    {
        Lisp_Object v0005 = stack[0];
        popv(2);
        return cons(v0005, v0001);
    }

v0011:
    v0001 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0001); }
/* error exit handlers */
v0155:
    popv(2);
    return nil;
}



/* Code for guesspftype */

static Lisp_Object CC_guesspftype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0248, v0047, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for guesspftype");
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
    v0248 = stack[0];
    if (!consp(v0248)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0248 = stack[0];
    v0047 = qcar(v0248);
    v0248 = elt(env, 1); /* (wedge d partdf hodge innerprod liedf) */
    v0248 = Lmemq(nil, v0047, v0248);
    if (!(v0248 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0248 = stack[0];
    v0248 = qcdr(v0248);
    v0048 = Llength(nil, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-1];
    v0248 = stack[0];
    v0047 = qcar(v0248);
    v0248 = elt(env, 2); /* ifdegree */
    v0248 = get(v0047, v0248);
    env = stack[-1];
    v0248 = Lassoc(nil, v0048, v0248);
    if (v0248 == nil) goto v0084;
    v0248 = stack[0];
    v0248 = qcdr(v0248);
    fn = elt(env, 3); /* xvarlistp */
    v0248 = (*qfn1(fn))(qenv(fn), v0248);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-1];
    if (v0248 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else goto v0084;

v0084:
    v0248 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* mknwedge */
        return (*qfn1(fn))(qenv(fn), v0248);
    }
/* error exit handlers */
v0152:
    popv(2);
    return nil;
}



/* Code for equalreplaceby */

static Lisp_Object CC_equalreplaceby(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0227, v0085;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equalreplaceby");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0227 = v0000;
/* end of prologue */
    v0085 = elt(env, 1); /* replaceby */
    return cons(v0085, v0227);
}



/* Code for inttovec */

static Lisp_Object CC_inttovec(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0244, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0003 = v0046;
    v0244 = v0000;
/* end of prologue */
    stack[0] = v0003;
    fn = elt(env, 1); /* inttovec!-solve */
    v0244 = (*qfn2(fn))(qenv(fn), v0003, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    {
        Lisp_Object v0001 = stack[0];
        popv(2);
        fn = elt(env, 2); /* inttovec1 */
        return (*qfn2(fn))(qenv(fn), v0001, v0244);
    }
/* error exit handlers */
v0004:
    popv(2);
    return nil;
}



/* Code for noncommuting */

static Lisp_Object CC_noncommuting(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0274, v0151, v0271;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncommuting");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0274 = v0046;
    v0151 = v0000;
/* end of prologue */
    v0271 = nil;
    v0035 = v0151;
    if (!consp(v0035)) goto v0034;
    v0035 = v0151;
    v0035 = qcar(v0035);
    goto v0011;

v0011:
    v0151 = v0035;
    v0035 = v0274;
    if (!consp(v0035)) goto v0003;
    v0035 = v0274;
    v0035 = qcar(v0035);
    goto v0244;

v0244:
    v0274 = v0035;
    v0035 = v0151;
    if (!consp(v0035)) goto v0054;
    v0035 = v0151;
    v0035 = qcar(v0035);
    if (!symbolp(v0035)) v0035 = nil;
    else { v0035 = qfastgets(v0035);
           if (v0035 != nil) { v0035 = elt(v0035, 0); /* noncom */
#ifdef RECORD_GET
             if (v0035 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0035 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0035 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0035 == SPID_NOPROP) v0035 = nil; else v0035 = lisp_true; }}
#endif
    goto v0172;

v0172:
    if (v0035 == nil) return onevalue(v0271);
    v0035 = v0274;
    if (!consp(v0035)) goto v0088;
    v0035 = v0274;
    v0035 = qcar(v0035);
    if (!symbolp(v0035)) v0035 = nil;
    else { v0035 = qfastgets(v0035);
           if (v0035 != nil) { v0035 = elt(v0035, 0); /* noncom */
#ifdef RECORD_GET
             if (v0035 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0035 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0035 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0035 == SPID_NOPROP) v0035 = nil; else v0035 = lisp_true; }}
#endif
    goto v0084;

v0084:
    if (v0035 == nil) return onevalue(v0271);
    v0035 = elt(env, 2); /* noncommutes */
    v0035 = get(v0151, v0035);
    v0035 = Lmember(nil, v0274, v0035);
    v0271 = v0035;
    return onevalue(v0271);

v0088:
    v0035 = v0274;
    if (!symbolp(v0035)) v0035 = nil;
    else { v0035 = qfastgets(v0035);
           if (v0035 != nil) { v0035 = elt(v0035, 0); /* noncom */
#ifdef RECORD_GET
             if (v0035 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0035 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0035 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0035 == SPID_NOPROP) v0035 = nil; else v0035 = lisp_true; }}
#endif
    goto v0084;

v0054:
    v0035 = v0151;
    if (!symbolp(v0035)) v0035 = nil;
    else { v0035 = qfastgets(v0035);
           if (v0035 != nil) { v0035 = elt(v0035, 0); /* noncom */
#ifdef RECORD_GET
             if (v0035 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0035 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0035 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0035 == SPID_NOPROP) v0035 = nil; else v0035 = lisp_true; }}
#endif
    goto v0172;

v0003:
    v0035 = v0274;
    goto v0244;

v0034:
    v0035 = v0151;
    goto v0011;
}



/* Code for zero!-roads */

static Lisp_Object CC_zeroKroads(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zero-roads");
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

v0226:
    v0054 = stack[0];
    if (v0054 == nil) goto v0010;
    v0054 = stack[0];
    v0054 = qcar(v0054);
    fn = elt(env, 2); /* z!-roads */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0058 = v0054;
    v0054 = v0058;
    if (v0054 == nil) goto v0057;
    stack[-1] = v0058;
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    v0054 = CC_zeroKroads(env, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    {
        Lisp_Object v0030 = stack[-1];
        popv(3);
        return cons(v0030, v0054);
    }

v0057:
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[0] = v0054;
    goto v0226;

v0010:
    v0054 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0054); }
/* error exit handlers */
v0040:
    popv(3);
    return nil;
}



/* Code for assert_format */

static Lisp_Object MS_CDECL CC_assert_format(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0046,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0146, v0144;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "assert_format");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_format");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0014,v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0046,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0065 = v0014;
    stack[-8] = v0046;
    stack[-9] = v0000;
/* end of prologue */
    v0065 = Lexplode(nil, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    stack[-10] = v0065;
    stack[-7] = elt(env, 1); /* !! */
    stack[-6] = elt(env, 2); /* !) */
    stack[-5] = elt(env, 1); /* !! */
    stack[-4] = elt(env, 3); /* !  */
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 4); /* !- */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 5); /* !> */
    v0144 = elt(env, 1); /* !! */
    v0146 = elt(env, 3); /* !  */
    v0065 = stack[-10];
    v0065 = list2star(v0144, v0146, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    v0065 = list2star(stack[-1], stack[0], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    v0065 = list2star(stack[-3], stack[-2], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    v0065 = list2star(stack[-5], stack[-4], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    v0065 = list2star(stack[-7], stack[-6], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    stack[-10] = v0065;
    v0065 = stack[-8];
    v0065 = Lreverse(nil, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    stack[-2] = v0065;
    goto v0049;

v0049:
    v0065 = stack[-2];
    if (v0065 == nil) goto v0229;
    v0065 = stack[-2];
    v0065 = qcar(v0065);
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 7); /* !, */
    v0146 = Lexplode(nil, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    v0065 = stack[-10];
    v0065 = Lnconc(nil, v0146, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    v0065 = list2star(stack[-1], stack[0], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    stack[-10] = v0065;
    v0065 = stack[-2];
    v0065 = qcdr(v0065);
    stack[-2] = v0065;
    goto v0049;

v0229:
    v0065 = stack[-10];
    v0065 = qcdr(v0065);
    v0065 = qcdr(v0065);
    stack[-10] = v0065;
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 8); /* !: */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 3); /* !  */
    v0144 = elt(env, 1); /* !! */
    v0146 = elt(env, 9); /* !( */
    v0065 = stack[-10];
    v0065 = list2star(v0144, v0146, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    v0065 = list2star(stack[-1], stack[0], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    v0065 = list2star(stack[-3], stack[-2], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    stack[-10] = v0065;
    v0065 = stack[-9];
    v0146 = Lexplode(nil, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    env = stack[-11];
    v0065 = stack[-10];
    v0065 = Lnconc(nil, v0146, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0288;
    stack[-10] = v0065;
    v0065 = stack[-10];
        popv(12);
        return Lcompress(nil, v0065);
/* error exit handlers */
v0288:
    popv(12);
    return nil;
}



/* Code for dp!=mocompare */

static Lisp_Object CC_dpMmocompare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0245, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=mocompare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0245 = v0046;
    v0004 = v0000;
/* end of prologue */
    v0004 = qcar(v0004);
    v0245 = qcar(v0245);
    fn = elt(env, 1); /* mo_compare */
    v0004 = (*qfn2(fn))(qenv(fn), v0004, v0245);
    errexit();
    v0245 = (Lisp_Object)17; /* 1 */
        return Leqn(nil, v0004, v0245);
}



/* Code for pv_intequiv */

static Lisp_Object CC_pv_intequiv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0044;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_intequiv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0044 = v0000;
/* end of prologue */
    v0002 = v0044;
    v0002 = qcdr(v0002);
    if (!consp(v0002)) goto v0010;
    v0002 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0002);

v0010:
    v0002 = v0044;
    v0002 = qcdr(v0002);
    return onevalue(v0002);
}



/* Code for st_sorttree */

static Lisp_Object MS_CDECL CC_st_sorttree(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0046,
                         Lisp_Object v0014, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0156, v0244;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_sorttree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0014,v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0046,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0029 = v0014;
    v0156 = v0046;
    v0244 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* st_sorttree1 */
    v0029 = (*qfnn(fn))(qenv(fn), 3, v0244, v0156, v0029);
    errexit();
    v0029 = qcdr(v0029);
    return onevalue(v0029);
}



/* Code for extmult */

static Lisp_Object CC_extmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0287, v0209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extmult");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0046;
    stack[-3] = v0000;
/* end of prologue */
    v0287 = stack[-3];
    if (v0287 == nil) goto v0034;
    v0287 = stack[-2];
    v0287 = (v0287 == nil ? lisp_true : nil);
    goto v0011;

v0011:
    if (v0287 == nil) goto v0004;
    v0287 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0287); }

v0004:
    v0287 = stack[-3];
    v0287 = qcar(v0287);
    v0287 = qcar(v0287);
    v0209 = qcar(v0287);
    v0287 = stack[-2];
    v0287 = qcar(v0287);
    v0287 = qcar(v0287);
    fn = elt(env, 3); /* ordexn */
    v0287 = (*qfn2(fn))(qenv(fn), v0209, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0209 = v0287;
    v0287 = v0209;
    if (v0287 == nil) goto v0241;
    v0287 = v0209;
    stack[-4] = qcdr(v0287);
    v0287 = v0209;
    v0287 = qcar(v0287);
    if (v0287 == nil) goto v0082;
    v0287 = stack[-3];
    v0287 = qcar(v0287);
    v0209 = qcdr(v0287);
    v0287 = stack[-2];
    v0287 = qcar(v0287);
    v0287 = qcdr(v0287);
    fn = elt(env, 4); /* c!:subs2multf */
    v0287 = (*qfn2(fn))(qenv(fn), v0209, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    fn = elt(env, 5); /* negf */
    v0287 = (*qfn1(fn))(qenv(fn), v0287);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    stack[-1] = v0287;
    goto v0021;

v0021:
    v0287 = stack[-3];
    v0287 = qcar(v0287);
    v0209 = ncons(v0287);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0287 = stack[-2];
    v0287 = qcdr(v0287);
    stack[0] = CC_extmult(env, v0209, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0287 = stack[-3];
    v0209 = qcdr(v0287);
    v0287 = stack[-2];
    v0287 = CC_extmult(env, v0209, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    fn = elt(env, 6); /* extadd */
    v0287 = (*qfn2(fn))(qenv(fn), stack[0], v0287);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    {
        Lisp_Object v0145 = stack[-4];
        Lisp_Object v0291 = stack[-1];
        popv(6);
        return acons(v0145, v0291, v0287);
    }

v0082:
    v0287 = stack[-3];
    v0287 = qcar(v0287);
    v0209 = qcdr(v0287);
    v0287 = stack[-2];
    v0287 = qcar(v0287);
    v0287 = qcdr(v0287);
    fn = elt(env, 4); /* c!:subs2multf */
    v0287 = (*qfn2(fn))(qenv(fn), v0209, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    stack[-1] = v0287;
    goto v0021;

v0241:
    v0287 = stack[-3];
    v0209 = qcdr(v0287);
    v0287 = stack[-2];
    stack[0] = CC_extmult(env, v0209, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0287 = stack[-3];
    v0287 = qcar(v0287);
    v0209 = ncons(v0287);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    v0287 = stack[-2];
    v0287 = qcdr(v0287);
    v0287 = CC_extmult(env, v0209, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-5];
    {
        Lisp_Object v0292 = stack[0];
        popv(6);
        fn = elt(env, 6); /* extadd */
        return (*qfn2(fn))(qenv(fn), v0292, v0287);
    }

v0034:
    v0287 = qvalue(elt(env, 1)); /* t */
    goto v0011;
/* error exit handlers */
v0144:
    popv(6);
    return nil;
}



/* Code for simp!*sq */

static Lisp_Object CC_simpHsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0245 = v0000;
/* end of prologue */
    v0003 = v0245;
    v0003 = qcdr(v0003);
    v0003 = qcar(v0003);
    if (v0003 == nil) goto v0044;
    v0003 = qvalue(elt(env, 1)); /* !*resimp */
    if (!(v0003 == nil)) goto v0044;
    v0003 = v0245;
    v0003 = qcar(v0003);
    return onevalue(v0003);

v0044:
    v0003 = v0245;
    v0003 = qcar(v0003);
    {
        fn = elt(env, 2); /* resimp1 */
        return (*qfn1(fn))(qenv(fn), v0003);
    }
}



/* Code for ofsf_surep */

static Lisp_Object CC_ofsf_surep(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0001, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_surep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0004 = v0046;
    v0001 = v0000;
/* end of prologue */
    v0007 = v0001;
    v0001 = v0004;
    v0004 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 2); /* cl_simpl */
    v0004 = (*qfnn(fn))(qenv(fn), 3, v0007, v0001, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[0];
    v0001 = elt(env, 1); /* true */
    v0004 = (v0004 == v0001 ? lisp_true : nil);
    { popv(1); return onevalue(v0004); }
/* error exit handlers */
v0009:
    popv(1);
    return nil;
}



/* Code for qqe_ofsf_chsimpterm */

static Lisp_Object CC_qqe_ofsf_chsimpterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0272, v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_chsimpterm");
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
    v0072 = v0000;
/* end of prologue */
    v0272 = v0072;
    if (!consp(v0272)) { popv(3); return onevalue(v0072); }
    v0272 = v0072;
    v0272 = qcdr(v0272);
    stack[-1] = v0272;
    goto v0156;

v0156:
    v0272 = stack[-1];
    if (v0272 == nil) goto v0031;
    v0272 = stack[-1];
    v0272 = qcar(v0272);
    v0272 = Lconsp(nil, v0272);
    env = stack[-2];
    if (v0272 == nil) goto v0006;
    v0272 = stack[-1];
    v0272 = qcar(v0272);
    fn = elt(env, 4); /* qqe_op */
    v0072 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-2];
    v0272 = elt(env, 2); /* expt */
    if (v0072 == v0272) goto v0058;
    v0272 = qvalue(elt(env, 1)); /* nil */
    goto v0054;

v0054:
    if (v0272 == nil) goto v0006;
    stack[0] = stack[-1];
    v0272 = stack[-1];
    v0272 = qcar(v0272);
    fn = elt(env, 5); /* qqe_chsimpterm */
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-2];
    fn = elt(env, 6); /* setcar */
    v0272 = (*qfn2(fn))(qenv(fn), stack[0], v0272);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-2];
    goto v0155;

v0155:
    v0272 = stack[-1];
    v0272 = qcdr(v0272);
    stack[-1] = v0272;
    goto v0156;

v0006:
    v0272 = stack[-1];
    v0272 = qcar(v0272);
    v0272 = Lconsp(nil, v0272);
    env = stack[-2];
    if (v0272 == nil) goto v0155;
    v0272 = stack[-1];
    v0272 = qcar(v0272);
    v0272 = CC_qqe_ofsf_chsimpterm(env, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-2];
    goto v0155;

v0058:
    v0272 = stack[-1];
    v0272 = qcar(v0272);
    fn = elt(env, 7); /* qqe_arg2l */
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-2];
    v0272 = Lconsp(nil, v0272);
    env = stack[-2];
    if (v0272 == nil) goto v0243;
    v0272 = stack[-1];
    v0272 = qcar(v0272);
    fn = elt(env, 7); /* qqe_arg2l */
    v0272 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-2];
    fn = elt(env, 4); /* qqe_op */
    v0072 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0246;
    env = stack[-2];
    v0272 = elt(env, 3); /* (ltail rtail) */
    v0272 = Lmemq(nil, v0072, v0272);
    goto v0054;

v0243:
    v0272 = qvalue(elt(env, 1)); /* nil */
    goto v0054;

v0031:
    v0272 = nil;
    { popv(3); return onevalue(v0272); }
/* error exit handlers */
v0246:
    popv(3);
    return nil;
}



/* Code for cl_atfp */

static Lisp_Object CC_cl_atfp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0136, v0299, v0258;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atfp");
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
    v0299 = v0000;
/* end of prologue */
    v0136 = v0299;
    if (!consp(v0136)) goto v0010;
    v0136 = v0299;
    v0136 = qcar(v0136);
    goto v0015;

v0015:
    v0258 = v0136;
    v0299 = v0258;
    v0136 = elt(env, 1); /* true */
    if (v0299 == v0136) goto v0003;
    v0299 = v0258;
    v0136 = elt(env, 3); /* false */
    v0136 = (v0299 == v0136 ? lisp_true : nil);
    goto v0244;

v0244:
    if (v0136 == nil) goto v0230;
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0044;

v0044:
    v0136 = (v0136 == nil ? lisp_true : nil);
    return onevalue(v0136);

v0230:
    v0299 = v0258;
    v0136 = elt(env, 4); /* or */
    if (v0299 == v0136) goto v0251;
    v0299 = v0258;
    v0136 = elt(env, 5); /* and */
    v0136 = (v0299 == v0136 ? lisp_true : nil);
    goto v0052;

v0052:
    if (v0136 == nil) goto v0151;
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0047;

v0047:
    if (v0136 == nil) goto v0072;
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0088;

v0088:
    if (v0136 == nil) goto v0209;
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0044;

v0209:
    v0299 = v0258;
    v0136 = elt(env, 10); /* ex */
    if (v0299 == v0136) goto v0212;
    v0299 = v0258;
    v0136 = elt(env, 11); /* all */
    v0136 = (v0299 == v0136 ? lisp_true : nil);
    goto v0211;

v0211:
    if (v0136 == nil) goto v0062;
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0044;

v0062:
    v0299 = v0258;
    v0136 = elt(env, 12); /* bex */
    if (v0299 == v0136) goto v0142;
    v0299 = v0258;
    v0136 = elt(env, 13); /* ball */
    v0136 = (v0299 == v0136 ? lisp_true : nil);
    goto v0207;

v0207:
    if (v0136 == nil) goto v0300;
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0044;

v0300:
    v0299 = v0258;
    v0136 = elt(env, 14); /* rl_external */
    v0136 = get(v0299, v0136);
    goto v0044;

v0142:
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0207;

v0212:
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0211;

v0072:
    v0299 = v0258;
    v0136 = elt(env, 7); /* impl */
    if (v0299 == v0136) goto v0273;
    v0299 = v0258;
    v0136 = elt(env, 8); /* repl */
    if (v0299 == v0136) goto v0290;
    v0299 = v0258;
    v0136 = elt(env, 9); /* equiv */
    v0136 = (v0299 == v0136 ? lisp_true : nil);
    goto v0088;

v0290:
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0088;

v0273:
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0088;

v0151:
    v0299 = v0258;
    v0136 = elt(env, 6); /* not */
    v0136 = (v0299 == v0136 ? lisp_true : nil);
    goto v0047;

v0251:
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0052;

v0003:
    v0136 = qvalue(elt(env, 2)); /* t */
    goto v0244;

v0010:
    v0136 = v0299;
    goto v0015;
}



/* Code for ibalp_redclause */

static Lisp_Object CC_ibalp_redclause(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_redclause");
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
    stack[0] = nil;
    v0030 = stack[-1];
    v0030 = qcar(v0030);
    stack[-2] = v0030;
    goto v0227;

v0227:
    v0030 = stack[-2];
    if (v0030 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0030 = stack[0];
    if (!(v0030 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0030 = stack[-2];
    v0059 = qcar(v0030);
    v0030 = stack[-1];
    v0030 = qcdr(v0030);
    v0030 = qcar(v0030);
    fn = elt(env, 3); /* ibalp_vmember */
    v0030 = (*qfn2(fn))(qenv(fn), v0059, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    if (v0030 == nil) goto v0004;
    v0030 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0030;
    goto v0004;

v0004:
    v0030 = stack[-2];
    v0030 = qcdr(v0030);
    stack[-2] = v0030;
    goto v0227;
/* error exit handlers */
v0242:
    popv(4);
    return nil;
}



/* Code for aex_mvaroccurtest */

static Lisp_Object CC_aex_mvaroccurtest(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0046)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mvaroccurtest");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0046,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0046);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0046;
    v0055 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v0002 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-1];
    v0055 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_mvartest */
        return (*qfn2(fn))(qenv(fn), v0002, v0055);
    }
/* error exit handlers */
v0043:
    popv(2);
    return nil;
}



setup_type const u12_setup[] =
{
    {"modminusp:",              CC_modminuspT,  too_many_1,    wrong_no_1},
    {":dmpluslst",              CC_Tdmpluslst,  too_many_1,    wrong_no_1},
    {"simptimes",               CC_simptimes,   too_many_1,    wrong_no_1},
    {"formop",                  CC_formop,      too_many_1,    wrong_no_1},
    {"dp_times_bc",             too_few_2,      CC_dp_times_bc,wrong_no_2},
    {"pv_neg",                  CC_pv_neg,      too_many_1,    wrong_no_1},
    {"pst_termnodep",           CC_pst_termnodep,too_many_1,   wrong_no_1},
    {"conv:mt",                 too_few_2,      CC_convTmt,    wrong_no_2},
    {"removeg1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_removeg1},
    {"ofsf_prepat",             CC_ofsf_prepat, too_many_1,    wrong_no_1},
    {"cl_susiminlevel",         too_few_2,      CC_cl_susiminlevel,wrong_no_2},
    {"cl_varl2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_varl2},
    {"mathml2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml2},
    {"newenv",                  CC_newenv,      too_many_1,    wrong_no_1},
    {"wedgepf",                 too_few_2,      CC_wedgepf,    wrong_no_2},
    {"prinfit",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_prinfit},
    {"prop-simp",               too_few_2,      CC_propKsimp,  wrong_no_2},
    {"quotdd",                  too_few_2,      CC_quotdd,     wrong_no_2},
    {"formclis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclis},
    {"mv-domainlist--",         too_few_2,      CC_mvKdomainlistKK,wrong_no_2},
    {"red_better",              too_few_2,      CC_red_better, wrong_no_2},
    {"pneg",                    CC_pneg,        too_many_1,    wrong_no_1},
    {"dl_get",                  CC_dl_get,      too_many_1,    wrong_no_1},
    {"artimes:",                too_few_2,      CC_artimesT,   wrong_no_2},
    {"traput",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_traput},
    {"rl_simpl",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_simpl},
    {"removeg2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_removeg2},
    {"rl_susipost",             too_few_2,      CC_rl_susipost,wrong_no_2},
    {"ibalp_getvar-zmom",       too_few_2,      CC_ibalp_getvarKzmom,wrong_no_2},
    {"ldt-tvar",                CC_ldtKtvar,    too_many_1,    wrong_no_1},
    {"groebnormalform",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebnormalform},
    {"simpindexvar",            CC_simpindexvar,too_many_1,    wrong_no_1},
    {"ptoken",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_ptoken},
    {"evalneq",                 too_few_2,      CC_evalneq,    wrong_no_2},
    {"mv-pow--",                too_few_2,      CC_mvKpowKK,   wrong_no_2},
    {"bc_fi",                   CC_bc_fi,       too_many_1,    wrong_no_1},
    {"pv_times3",               too_few_2,      CC_pv_times3,  wrong_no_2},
    {"dv_skel2factor1",         too_few_2,      CC_dv_skel2factor1,wrong_no_2},
    {"rnminus:",                CC_rnminusT,    too_many_1,    wrong_no_1},
    {"noncomperm",              CC_noncomperm,  too_many_1,    wrong_no_1},
    {"gcref_mkgraph",           CC_gcref_mkgraph,too_many_1,   wrong_no_1},
    {"rl_simpbop",              CC_rl_simpbop,  too_many_1,    wrong_no_1},
    {"ratpoly_mvartest",        too_few_2,      CC_ratpoly_mvartest,wrong_no_2},
    {"vdp_zero?",               CC_vdp_zeroW,   too_many_1,    wrong_no_1},
    {"attributesml",            too_few_2,      CC_attributesml,wrong_no_2},
    {"greaterp:",               too_few_2,      CC_greaterpT,  wrong_no_2},
    {"mksetq",                  too_few_2,      CC_mksetq,     wrong_no_2},
    {"aminusp:1",               CC_aminuspT1,   too_many_1,    wrong_no_1},
    {"nzeros",                  CC_nzeros,      too_many_1,    wrong_no_1},
    {"dividef",                 too_few_2,      CC_dividef,    wrong_no_2},
    {"difference-mod-p",        too_few_2,      CC_differenceKmodKp,wrong_no_2},
    {"gcref_mkedges-tgf",       too_few_2,      CC_gcref_mkedgesKtgf,wrong_no_2},
    {"rl_csimpl",               CC_rl_csimpl,   too_many_1,    wrong_no_1},
    {"qqe_ofsf_simplat1",       too_few_2,      CC_qqe_ofsf_simplat1,wrong_no_2},
    {"pasf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwmkatl},
    {"ibalp_clausep",           CC_ibalp_clausep,too_many_1,   wrong_no_1},
    {"ratpoly_ratp",            CC_ratpoly_ratp,too_many_1,    wrong_no_1},
    {"matrixrowrd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrowrd},
    {"guesspftype",             CC_guesspftype, too_many_1,    wrong_no_1},
    {"equalreplaceby",          CC_equalreplaceby,too_many_1,  wrong_no_1},
    {"inttovec",                too_few_2,      CC_inttovec,   wrong_no_2},
    {"noncommuting",            too_few_2,      CC_noncommuting,wrong_no_2},
    {"zero-roads",              CC_zeroKroads,  too_many_1,    wrong_no_1},
    {"assert_format",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_format},
    {"dp=mocompare",            too_few_2,      CC_dpMmocompare,wrong_no_2},
    {"pv_intequiv",             CC_pv_intequiv, too_many_1,    wrong_no_1},
    {"st_sorttree",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree},
    {"extmult",                 too_few_2,      CC_extmult,    wrong_no_2},
    {"simp*sq",                 CC_simpHsq,     too_many_1,    wrong_no_1},
    {"ofsf_surep",              too_few_2,      CC_ofsf_surep, wrong_no_2},
    {"qqe_ofsf_chsimpterm",     CC_qqe_ofsf_chsimpterm,too_many_1,wrong_no_1},
    {"cl_atfp",                 CC_cl_atfp,     too_many_1,    wrong_no_1},
    {"ibalp_redclause",         CC_ibalp_redclause,too_many_1, wrong_no_1},
    {"aex_mvaroccurtest",       too_few_2,      CC_aex_mvaroccurtest,wrong_no_2},
    {NULL, (one_args *)"u12", (two_args *)"3599 6538323 158940", 0}
};

/* end of generated code */
