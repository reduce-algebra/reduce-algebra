
/* $destdir\u27.c        Machine generated C code */

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


/* Code for matrix_rows */

static Lisp_Object CC_matrix_rows(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrix_rows");
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
    v0005 = stack[0];
    if (v0005 == nil) goto v0007;
    v0005 = elt(env, 1); /* "<matrixrow>" */
    fn = elt(env, 5); /* printout */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    v0006 = qvalue(elt(env, 2)); /* indent */
    v0005 = (Lisp_Object)49; /* 3 */
    v0005 = plus2(v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0005; /* indent */
    v0005 = stack[0];
    v0005 = qcar(v0005);
    fn = elt(env, 6); /* row */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    v0006 = qvalue(elt(env, 2)); /* indent */
    v0005 = (Lisp_Object)49; /* 3 */
    v0005 = difference2(v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0005; /* indent */
    v0005 = elt(env, 3); /* "</matrixrow>" */
    fn = elt(env, 5); /* printout */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    v0005 = stack[0];
    v0005 = qcdr(v0005);
    v0005 = CC_matrix_rows(env, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    goto v0007;

v0007:
    v0005 = nil;
    { popv(2); return onevalue(v0005); }
/* error exit handlers */
v0008:
    popv(2);
    return nil;
}



/* Code for degreef */

static Lisp_Object CC_degreef(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degreef");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    v0018 = stack[-1];
    if (!consp(v0018)) goto v0020;
    v0018 = stack[-1];
    v0018 = qcar(v0018);
    v0018 = (consp(v0018) ? nil : lisp_true);
    goto v0021;

v0021:
    if (v0018 == nil) goto v0022;
    v0018 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v0018); }

v0022:
    v0018 = stack[-1];
    v0018 = qcar(v0018);
    v0018 = qcar(v0018);
    v0019 = qcar(v0018);
    v0018 = stack[0];
    if (v0019 == v0018) goto v0023;
    v0018 = stack[-1];
    v0018 = qcar(v0018);
    v0019 = qcdr(v0018);
    v0018 = stack[0];
    stack[-2] = CC_degreef(env, v0019, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    v0018 = stack[-1];
    v0019 = qcdr(v0018);
    v0018 = stack[0];
    v0018 = CC_degreef(env, v0019, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    {
        Lisp_Object v0025 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* max */
        return (*qfn2(fn))(qenv(fn), v0025, v0018);
    }

v0023:
    v0018 = stack[-1];
    v0018 = qcar(v0018);
    v0018 = qcar(v0018);
    v0018 = qcdr(v0018);
    { popv(4); return onevalue(v0018); }

v0020:
    v0018 = qvalue(elt(env, 1)); /* t */
    goto v0021;
/* error exit handlers */
v0024:
    popv(4);
    return nil;
}



/* Code for evgradlexcomp */

static Lisp_Object CC_evgradlexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evgradlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */

v0007:
    v0033 = stack[-2];
    if (v0033 == nil) goto v0021;
    v0033 = stack[-1];
    if (v0033 == nil) goto v0035;
    v0033 = stack[-2];
    v0034 = qcar(v0033);
    v0033 = stack[-1];
    v0033 = qcar(v0033);
    v0033 = Leqn(nil, v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    if (v0033 == nil) goto v0037;
    v0033 = stack[-2];
    v0033 = qcdr(v0033);
    stack[-2] = v0033;
    v0033 = stack[-1];
    v0033 = qcdr(v0033);
    stack[-1] = v0033;
    goto v0007;

v0037:
    v0033 = stack[-2];
    fn = elt(env, 2); /* evtdeg */
    stack[0] = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    v0033 = stack[-1];
    fn = elt(env, 2); /* evtdeg */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v0033;
    v0034 = stack[-3];
    v0033 = stack[0];
    v0033 = Leqn(nil, v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    if (v0033 == nil) goto v0038;
    v0033 = stack[-2];
    v0034 = qcar(v0033);
    v0033 = stack[-1];
    v0033 = qcar(v0033);
    if (((int32_t)(v0034)) > ((int32_t)(v0033))) goto v0039;
    v0033 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0033); }

v0039:
    v0033 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0033); }

v0038:
    v0034 = stack[-3];
    v0033 = stack[0];
    if (((int32_t)(v0034)) > ((int32_t)(v0033))) goto v0040;
    v0033 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0033); }

v0040:
    v0033 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0033); }

v0035:
    v0033 = elt(env, 1); /* (0) */
    stack[-1] = v0033;
    goto v0007;

v0021:
    v0033 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v0033); }
/* error exit handlers */
v0036:
    popv(5);
    return nil;
}



/* Code for fl2bf */

static Lisp_Object CC_fl2bf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fl2bf");
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
    v0045 = v0000;
/* end of prologue */
    fn = elt(env, 3); /* frexp */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    stack[-2] = v0045;
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    v0046 = stack[-2];
    v0046 = qcar(v0046);
    stack[-2] = v0046;
    stack[0] = v0045;
    v0046 = (Lisp_Object)33; /* 2 */
    v0045 = qvalue(elt(env, 1)); /* !!nbfpd */
    v0045 = Lexpt(nil, v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0045 = times2(stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0045 = Ltruncate(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    stack[-1] = elt(env, 2); /* !:rd!: */
    stack[0] = v0045;
    v0046 = stack[-2];
    v0045 = qvalue(elt(env, 1)); /* !!nbfpd */
    v0045 = difference2(v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0045 = list2star(stack[-1], stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v0045);
    }
/* error exit handlers */
v0014:
    popv(4);
    return nil;
}



/* Code for getphystypeall */

static Lisp_Object CC_getphystypeall(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypeall");
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
    v0010 = (Lisp_Object)1; /* 0 */
    v0048 = stack[0];
    fn = elt(env, 3); /* deleteall */
    v0048 = (*qfn2(fn))(qenv(fn), v0010, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    fn = elt(env, 4); /* collectphystype */
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    v0010 = v0048;
    if (v0048 == nil) goto v0017;
    v0048 = v0010;
    v0048 = qcdr(v0048);
    if (v0048 == nil) goto v0028;
    stack[-1] = elt(env, 0); /* getphystypeall */
    v0010 = elt(env, 2); /* "PHYSOP type mismatch in" */
    v0048 = stack[0];
    v0048 = list2(v0010, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    fn = elt(env, 5); /* rederr2 */
    v0048 = (*qfn2(fn))(qenv(fn), stack[-1], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    v0048 = nil;
    { popv(3); return onevalue(v0048); }

v0028:
    v0048 = v0010;
    v0048 = qcar(v0048);
    { popv(3); return onevalue(v0048); }

v0017:
    v0048 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0048); }
/* error exit handlers */
v0045:
    popv(3);
    return nil;
}



/* Code for calc_coeff */

static Lisp_Object CC_calc_coeff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0039, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_coeff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    v0011 = stack[-1];
    if (v0011 == nil) goto v0007;
    v0011 = stack[-1];
    v0039 = qcar(v0011);
    v0011 = stack[0];
    fn = elt(env, 1); /* calc_world */
    v0011 = (*qfn2(fn))(qenv(fn), v0039, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-3];
    v0051 = v0011;
    v0039 = v0051;
    v0011 = (Lisp_Object)1; /* 0 */
    if (v0039 == v0011) goto v0053;
    stack[-2] = v0051;
    v0011 = stack[-1];
    v0039 = qcdr(v0011);
    v0011 = stack[0];
    v0011 = CC_calc_coeff(env, v0039, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    {
        Lisp_Object v0012 = stack[-2];
        popv(4);
        return cons(v0012, v0011);
    }

v0053:
    v0011 = (Lisp_Object)1; /* 0 */
    popv(4);
    return ncons(v0011);

v0007:
    v0011 = (Lisp_Object)17; /* 1 */
    popv(4);
    return ncons(v0011);
/* error exit handlers */
v0052:
    popv(4);
    return nil;
}



/* Code for gvarlis1 */

static Lisp_Object CC_gvarlis1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gvarlis1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0017;

v0017:
    v0014 = stack[-1];
    if (v0014 == nil) goto v0021;
    v0014 = stack[-1];
    v0015 = qcar(v0014);
    v0014 = stack[0];
    fn = elt(env, 1); /* gvar1 */
    v0015 = (*qfn2(fn))(qenv(fn), v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-3];
    v0014 = stack[-2];
    v0014 = cons(v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-3];
    stack[-2] = v0014;
    v0014 = stack[-1];
    v0014 = qcdr(v0014);
    stack[-1] = v0014;
    goto v0017;

v0021:
    v0014 = stack[0];
    v0015 = v0014;
    goto v0020;

v0020:
    v0014 = stack[-2];
    if (v0014 == nil) { popv(4); return onevalue(v0015); }
    v0014 = stack[-2];
    v0014 = qcar(v0014);
    fn = elt(env, 2); /* union */
    v0014 = (*qfn2(fn))(qenv(fn), v0014, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-3];
    v0015 = v0014;
    v0014 = stack[-2];
    v0014 = qcdr(v0014);
    stack[-2] = v0014;
    goto v0020;
/* error exit handlers */
v0057:
    popv(4);
    return nil;
}



/* Code for general!-horner!-rule!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKhornerKruleKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0043, Lisp_Object v0056,
                         Lisp_Object v0055, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0078, v0079, v0080, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "general-horner-rule-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-horner-rule-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0055,v0056,v0043,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0009,v0043,v0056,v0055);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0055;
    stack[-3] = v0056;
    stack[-4] = v0043;
    v0079 = v0009;
    v0080 = v0000;
/* end of prologue */

v0082:
    v0077 = stack[-4];
    if (!consp(v0077)) goto v0047;
    v0077 = stack[-4];
    v0077 = qcar(v0077);
    v0077 = (consp(v0077) ? nil : lisp_true);
    goto v0083;

v0083:
    if (v0077 == nil) goto v0001;
    v0077 = qvalue(elt(env, 1)); /* t */
    goto v0084;

v0084:
    if (v0077 == nil) goto v0085;
    v0077 = stack[-3];
    if (v0077 == nil) goto v0045;
    v0077 = stack[-3];
    v0077 = (Lisp_Object)zerop(v0077);
    v0077 = v0077 ? lisp_true : nil;
    env = stack[-6];
    goto v0042;

v0042:
    if (!(v0077 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[0] = v0080;
    v0077 = stack[-3];
    v0078 = v0079;
    fn = elt(env, 2); /* general!-expt!-mod!-p */
    v0077 = (*qfn2(fn))(qenv(fn), v0077, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    fn = elt(env, 3); /* general!-times!-mod!-p */
    v0077 = (*qfn2(fn))(qenv(fn), stack[0], v0077);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0080 = v0077;
    v0077 = stack[-4];
    v0078 = v0080;
    {
        popv(7);
        fn = elt(env, 4); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0077, v0078);
    }

v0045:
    v0077 = qvalue(elt(env, 1)); /* t */
    goto v0042;

v0085:
    v0077 = stack[-4];
    v0077 = qcar(v0077);
    v0077 = qcar(v0077);
    v0077 = qcdr(v0077);
    stack[-5] = v0077;
    v0077 = stack[-3];
    if (v0077 == nil) goto v0087;
    v0077 = stack[-3];
    v0077 = (Lisp_Object)zerop(v0077);
    v0077 = v0077 ? lisp_true : nil;
    env = stack[-6];
    goto v0088;

v0088:
    if (v0077 == nil) goto v0089;
    v0077 = stack[-4];
    v0077 = qcar(v0077);
    v0077 = qcdr(v0077);
    v0080 = v0077;
    goto v0090;

v0090:
    v0079 = stack[-5];
    v0077 = stack[-4];
    v0081 = qcdr(v0077);
    v0078 = stack[-3];
    v0077 = stack[-2];
    stack[-4] = v0081;
    stack[-3] = v0078;
    stack[-2] = v0077;
    goto v0082;

v0089:
    v0077 = stack[-4];
    v0077 = qcar(v0077);
    stack[-1] = qcdr(v0077);
    stack[0] = v0080;
    v0078 = stack[-3];
    v0077 = stack[-5];
    v0077 = (Lisp_Object)(int32_t)((int32_t)v0079 - (int32_t)v0077 + TAG_FIXNUM);
    fn = elt(env, 2); /* general!-expt!-mod!-p */
    v0077 = (*qfn2(fn))(qenv(fn), v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    fn = elt(env, 3); /* general!-times!-mod!-p */
    v0077 = (*qfn2(fn))(qenv(fn), stack[0], v0077);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    fn = elt(env, 4); /* general!-plus!-mod!-p */
    v0077 = (*qfn2(fn))(qenv(fn), stack[-1], v0077);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0080 = v0077;
    goto v0090;

v0087:
    v0077 = qvalue(elt(env, 1)); /* t */
    goto v0088;

v0001:
    v0077 = stack[-4];
    v0077 = qcar(v0077);
    v0077 = qcar(v0077);
    v0078 = qcar(v0077);
    v0077 = stack[-2];
    v0077 = (equal(v0078, v0077) ? lisp_true : nil);
    v0077 = (v0077 == nil ? lisp_true : nil);
    goto v0084;

v0047:
    v0077 = qvalue(elt(env, 1)); /* t */
    goto v0083;
/* error exit handlers */
v0086:
    popv(7);
    return nil;
}



/* Code for reduce!-eival!-powers */

static Lisp_Object CC_reduceKeivalKpowers(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0092, v0093, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-eival-powers");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0093 = v0009;
    v0024 = v0000;
/* end of prologue */
    v0029 = v0093;
    if (!consp(v0029)) goto v0094;
    v0029 = v0093;
    v0029 = qcar(v0029);
    v0029 = (consp(v0029) ? nil : lisp_true);
    goto v0035;

v0035:
    if (v0029 == nil) goto v0031;
    v0029 = qvalue(elt(env, 1)); /* t */
    goto v0021;

v0021:
    if (v0029 == nil) goto v0030;
    v0092 = v0093;
    v0029 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0092, v0029);

v0030:
    stack[0] = v0024;
    v0092 = v0093;
    v0029 = (Lisp_Object)17; /* 1 */
    v0029 = cons(v0092, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    {
        Lisp_Object v0069 = stack[0];
        popv(2);
        fn = elt(env, 2); /* reduce!-eival!-powers1 */
        return (*qfn2(fn))(qenv(fn), v0069, v0029);
    }

v0031:
    v0029 = v0093;
    v0029 = qcar(v0029);
    v0029 = qcar(v0029);
    v0092 = qcar(v0029);
    v0029 = v0024;
    v0029 = qcar(v0029);
    v0029 = qcar(v0029);
    v0029 = (v0092 == v0029 ? lisp_true : nil);
    v0029 = (v0029 == nil ? lisp_true : nil);
    goto v0021;

v0094:
    v0029 = qvalue(elt(env, 1)); /* t */
    goto v0035;
/* error exit handlers */
v0040:
    popv(2);
    return nil;
}



/* Code for get_char_value */

static Lisp_Object CC_get_char_value(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_char_value");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0009;
    v0026 = v0000;
/* end of prologue */
    stack[-1] = nil;
    v0027 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0027;
    v0027 = v0026;
    v0027 = qcdr(v0027);
    stack[0] = v0027;
    goto v0094;

v0094:
    v0027 = stack[-3];
    if (v0027 == nil) goto v0053;
    v0027 = qvalue(elt(env, 1)); /* nil */
    goto v0023;

v0023:
    if (v0027 == nil) goto v0035;
    v0027 = stack[0];
    v0027 = qcar(v0027);
    v0026 = qcar(v0027);
    v0027 = stack[-2];
    if (!(equal(v0026, v0027))) goto v0006;
    v0027 = stack[0];
    v0027 = qcar(v0027);
    v0027 = qcdr(v0027);
    v0027 = qcar(v0027);
    stack[-1] = v0027;
    v0027 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v0027;
    goto v0006;

v0006:
    v0027 = stack[0];
    v0027 = qcdr(v0027);
    stack[0] = v0027;
    goto v0094;

v0035:
    v0027 = stack[-3];
    if (!(v0027 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0027 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0027 == nil)) goto v0040;
    v0027 = elt(env, 4); /* "error in get character element" */
    fn = elt(env, 5); /* lprie */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    goto v0040;

v0040:
    v0027 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    v0027 = nil;
    { popv(5); return onevalue(v0027); }

v0053:
    v0027 = stack[0];
    v0026 = Llength(nil, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    v0027 = (Lisp_Object)1; /* 0 */
    v0027 = (Lisp_Object)greaterp2(v0026, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    v0027 = v0027 ? lisp_true : nil;
    env = stack[-4];
    goto v0023;
/* error exit handlers */
v0033:
    popv(5);
    return nil;
}



/* Code for cl_smsimpl!-junct */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0043, Lisp_Object v0056, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0078, v0079, v0080, v0081, v0105, v0106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_smsimpl-junct");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_smsimpl-junct");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0056,v0043,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0009,v0043,v0056);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0056;
    stack[-6] = v0043;
    stack[0] = v0009;
    stack[-7] = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    v0077 = qvalue(elt(env, 1)); /* !*rlsism */
    if (v0077 == nil) goto v0004;
    v0077 = stack[-6];
    fn = elt(env, 5); /* rl_smcpknowl */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-9];
    stack[-2] = v0077;
    v0079 = elt(env, 3); /* false */
    v0078 = stack[-7];
    v0077 = elt(env, 4); /* and */
    v0077 = (v0078 == v0077 ? lisp_true : nil);
    fn = elt(env, 6); /* cl_cflip */
    v0077 = (*qfn2(fn))(qenv(fn), v0079, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-9];
    stack[-8] = v0077;
    v0077 = stack[0];
    stack[-1] = v0077;
    goto v0014;

v0014:
    v0077 = stack[-1];
    if (v0077 == nil) goto v0088;
    v0077 = stack[-1];
    v0077 = qcar(v0077);
    stack[0] = v0077;
    v0077 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-9];
    if (v0077 == nil) goto v0027;
    v0078 = stack[0];
    v0077 = stack[-7];
    fn = elt(env, 8); /* cl_simplat */
    v0077 = (*qfn2(fn))(qenv(fn), v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-9];
    goto v0019;

v0019:
    stack[0] = v0077;
    v0077 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-9];
    if (v0077 == nil) goto v0108;
    v0078 = stack[0];
    v0077 = stack[-4];
    v0077 = cons(v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-9];
    stack[-4] = v0077;
    goto v0085;

v0085:
    v0077 = stack[-1];
    v0077 = qcdr(v0077);
    stack[-1] = v0077;
    goto v0014;

v0108:
    v0078 = stack[0];
    v0077 = stack[-3];
    v0077 = cons(v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-9];
    stack[-3] = v0077;
    goto v0085;

v0027:
    v0077 = stack[0];
    goto v0019;

v0088:
    v0080 = stack[-7];
    v0079 = stack[-4];
    v0078 = stack[-2];
    v0077 = stack[-5];
    fn = elt(env, 9); /* rl_smupdknowl */
    v0077 = (*qfnn(fn))(qenv(fn), 4, v0080, v0079, v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-9];
    stack[-2] = v0077;
    v0078 = stack[-2];
    v0077 = elt(env, 3); /* false */
    if (v0078 == v0077) goto v0089;
    v0106 = stack[-7];
    v0105 = stack[-4];
    v0077 = stack[-3];
    v0081 = Lnreverse(nil, v0077);
    env = stack[-9];
    v0080 = stack[-6];
    v0079 = stack[-2];
    v0078 = stack[-5];
    v0077 = stack[-8];
    {
        popv(10);
        fn = elt(env, 10); /* cl_smsimpl!-junct1 */
        return (*qfnn(fn))(qenv(fn), 7, v0106, v0105, v0081, v0080, v0079, v0078, v0077);
    }

v0089:
    v0077 = stack[-8];
    popv(10);
    return ncons(v0077);

v0004:
    v0080 = stack[0];
    v0079 = stack[-5];
    v0078 = stack[-7];
    v0077 = qvalue(elt(env, 2)); /* nil */
    {
        popv(10);
        fn = elt(env, 11); /* cl_gand!-col */
        return (*qfnn(fn))(qenv(fn), 4, v0080, v0079, v0078, v0077);
    }
/* error exit handlers */
v0107:
    popv(10);
    return nil;
}



/* Code for aex_boundids */

static Lisp_Object CC_aex_boundids(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_boundids");
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
    v0094 = stack[0];
    fn = elt(env, 1); /* aex_ids */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    v0094 = stack[0];
    fn = elt(env, 2); /* aex_ctx */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    fn = elt(env, 3); /* ctx_idl */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    {
        Lisp_Object v0003 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* intersection */
        return (*qfn2(fn))(qenv(fn), v0003, v0094);
    }
/* error exit handlers */
v0047:
    popv(3);
    return nil;
}



/* Code for multiminus */

static Lisp_Object CC_multiminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0109, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiminus");
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
    v0109 = stack[0];
    v0109 = qcar(v0109);
    fn = elt(env, 1); /* expression */
    v0109 = (*qfn1(fn))(qenv(fn), v0109);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0109 = stack[0];
    v0053 = Llength(nil, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0109 = (Lisp_Object)33; /* 2 */
    if (!(v0053 == v0109)) goto v0021;
    v0109 = stack[0];
    v0109 = qcdr(v0109);
    v0109 = qcar(v0109);
    fn = elt(env, 1); /* expression */
    v0109 = (*qfn1(fn))(qenv(fn), v0109);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    goto v0021;

v0021:
    v0109 = nil;
    { popv(2); return onevalue(v0109); }
/* error exit handlers */
v0044:
    popv(2);
    return nil;
}



/* Code for groebbuchcrit4t */

static Lisp_Object CC_groebbuchcrit4t(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0051;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebbuchcrit4t");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */

v0007:
    v0039 = stack[-1];
    if (v0039 == nil) goto v0035;
    v0039 = stack[0];
    v0039 = (v0039 == nil ? lisp_true : nil);
    goto v0084;

v0084:
    if (v0039 == nil) goto v0032;
    v0039 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0039); }

v0032:
    v0039 = stack[-1];
    v0051 = qcar(v0039);
    v0039 = (Lisp_Object)1; /* 0 */
    if (v0051 == v0039) goto v0041;
    v0039 = stack[0];
    v0051 = qcar(v0039);
    v0039 = (Lisp_Object)1; /* 0 */
    v0039 = Lneq(nil, v0051, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    goto v0053;

v0053:
    if (v0039 == nil) goto v0054;
    v0039 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0039); }

v0054:
    v0039 = stack[-1];
    v0039 = qcdr(v0039);
    stack[-1] = v0039;
    v0039 = stack[0];
    v0039 = qcdr(v0039);
    stack[0] = v0039;
    goto v0007;

v0041:
    v0039 = qvalue(elt(env, 2)); /* nil */
    goto v0053;

v0035:
    v0039 = qvalue(elt(env, 1)); /* t */
    goto v0084;
/* error exit handlers */
v0111:
    popv(3);
    return nil;
}



/* Code for r2speclist1 */

static Lisp_Object CC_r2speclist1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0041, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2speclist1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0010 = v0000;
/* end of prologue */
    v0042 = v0010;
    v0041 = elt(env, 1); /* times */
    if (!consp(v0042)) goto v0005;
    v0042 = qcar(v0042);
    if (!(v0042 == v0041)) goto v0005;
    v0041 = v0010;
    v0041 = qcdr(v0041);
    v0042 = qcar(v0041);
    v0041 = v0010;
    v0041 = qcdr(v0041);
    v0041 = qcdr(v0041);
    v0041 = qcar(v0041);
    v0010 = qcdr(v0010);
    v0010 = qcdr(v0010);
    v0010 = qcdr(v0010);
    {
        fn = elt(env, 2); /* r2speclist2 */
        return (*qfnn(fn))(qenv(fn), 3, v0042, v0041, v0010);
    }

v0005:
    v0041 = (Lisp_Object)17; /* 1 */
    return cons(v0041, v0010);
}



/* Code for apply_e */

static Lisp_Object CC_apply_e(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for apply_e");
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
    v0001 = v0000;
/* end of prologue */
    v0002 = v0001;
    v0001 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* apply */
    v0002 = (*qfn2(fn))(qenv(fn), v0002, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    v0001 = v0002;
    v0002 = integerp(v0002);
    if (!(v0002 == nil)) { popv(1); return onevalue(v0001); }
    v0001 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v0001 == nil)) goto v0022;
    v0001 = elt(env, 3); /* "randpoly expons function must return an integer" 
*/
    fn = elt(env, 5); /* lprie */
    v0001 = (*qfn1(fn))(qenv(fn), v0001);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    goto v0022;

v0022:
    v0001 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    v0001 = nil;
    { popv(1); return onevalue(v0001); }
/* error exit handlers */
v0016:
    popv(1);
    return nil;
}



/* Code for indxsymp */

static Lisp_Object CC_indxsymp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indxsymp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */

v0082:
    v0005 = stack[0];
    if (v0005 == nil) goto v0007;
    v0005 = stack[0];
    v0006 = qcar(v0005);
    v0005 = stack[-1];
    v0005 = Lapply1(nil, v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    if (v0005 == nil) goto v0094;
    v0006 = stack[-1];
    v0005 = stack[0];
    v0005 = qcdr(v0005);
    stack[-1] = v0006;
    stack[0] = v0005;
    goto v0082;

v0094:
    v0005 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0005); }

v0007:
    v0005 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0005); }
/* error exit handlers */
v0115:
    popv(3);
    return nil;
}



/* Code for find_buble */

static Lisp_Object CC_find_buble(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_buble");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */

v0082:
    v0037 = stack[0];
    if (v0037 == nil) goto v0007;
    v0091 = stack[-1];
    v0037 = stack[0];
    v0037 = qcar(v0037);
    fn = elt(env, 2); /* is_buble */
    v0037 = (*qfn2(fn))(qenv(fn), v0091, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-2];
    if (!(v0037 == nil)) { popv(3); return onevalue(v0037); }
    v0091 = stack[-1];
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    stack[-1] = v0091;
    stack[0] = v0037;
    goto v0082;

v0007:
    v0037 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0037); }
/* error exit handlers */
v0005:
    popv(3);
    return nil;
}



/* Code for innprodpex */

static Lisp_Object CC_innprodpex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for innprodpex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */

v0082:
    v0116 = stack[-1];
    if (v0116 == nil) goto v0007;
    v0117 = stack[-2];
    v0116 = stack[-1];
    v0116 = qcar(v0116);
    v0116 = qcar(v0116);
    fn = elt(env, 2); /* innprodp2 */
    v0116 = (*qfn2(fn))(qenv(fn), v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-4];
    v0117 = v0116;
    v0116 = v0117;
    if (v0116 == nil) goto v0029;
    v0116 = v0117;
    stack[-3] = qcdr(v0116);
    v0116 = v0117;
    v0116 = qcar(v0116);
    if (v0116 == nil) goto v0046;
    v0116 = stack[-1];
    v0116 = qcar(v0116);
    v0116 = qcdr(v0116);
    fn = elt(env, 3); /* negf */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-4];
    stack[0] = v0116;
    goto v0011;

v0011:
    v0117 = stack[-2];
    v0116 = stack[-1];
    v0116 = qcdr(v0116);
    v0116 = CC_innprodpex(env, v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    {
        Lisp_Object v0068 = stack[-3];
        Lisp_Object v0085 = stack[0];
        popv(5);
        return acons(v0068, v0085, v0116);
    }

v0046:
    v0116 = stack[-1];
    v0116 = qcar(v0116);
    v0116 = qcdr(v0116);
    stack[0] = v0116;
    goto v0011;

v0029:
    v0117 = stack[-2];
    v0116 = stack[-1];
    v0116 = qcdr(v0116);
    stack[-2] = v0117;
    stack[-1] = v0116;
    goto v0082;

v0007:
    v0116 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0116); }
/* error exit handlers */
v0067:
    popv(5);
    return nil;
}



/* Code for simp!-prop!-condense */

static Lisp_Object CC_simpKpropKcondense(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-condense");
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
    stack[-3] = v0000;
/* end of prologue */
    stack[-2] = nil;
    v0104 = stack[-3];
    v0103 = elt(env, 1); /* lambda_mcd3py_6 */
    fn = elt(env, 3); /* sort */
    v0103 = (*qfn2(fn))(qenv(fn), v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-5];
    stack[-3] = v0103;
    goto v0047;

v0047:
    v0103 = stack[-3];
    if (v0103 == nil) goto v0083;
    v0103 = stack[-3];
    v0103 = qcar(v0103);
    stack[-4] = v0103;
    v0103 = stack[-3];
    v0103 = qcdr(v0103);
    stack[-3] = v0103;
    v0104 = stack[-4];
    v0103 = stack[-2];
    v0103 = cons(v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-5];
    stack[-2] = v0103;
    v0103 = stack[-3];
    stack[-1] = v0103;
    goto v0028;

v0028:
    v0103 = stack[-1];
    if (v0103 == nil) goto v0047;
    v0103 = stack[-1];
    v0103 = qcar(v0103);
    stack[0] = v0103;
    v0104 = stack[-4];
    v0103 = stack[0];
    fn = elt(env, 4); /* subsetp */
    v0103 = (*qfn2(fn))(qenv(fn), v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-5];
    if (v0103 == nil) goto v0030;
    v0104 = stack[0];
    v0103 = stack[-3];
    v0103 = Ldelete(nil, v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-5];
    stack[-3] = v0103;
    goto v0030;

v0030:
    v0103 = stack[-1];
    v0103 = qcdr(v0103);
    stack[-1] = v0103;
    goto v0028;

v0083:
    v0103 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* ordn */
        return (*qfn1(fn))(qenv(fn), v0103);
    }
/* error exit handlers */
v0118:
    popv(6);
    return nil;
}



/* Code for lambda_mcd3py_6 */

static Lisp_Object CC_lambda_mcd3py_6(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_mcd3py_6");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    v0094 = v0000;
/* end of prologue */
    stack[-1] = Llength(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    v0094 = stack[0];
    v0094 = Llength(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    {
        Lisp_Object v0003 = stack[-1];
        popv(3);
        return Llessp(nil, v0003, v0094);
    }
/* error exit handlers */
v0047:
    popv(3);
    return nil;
}



/* Code for pcdiv */

static Lisp_Object CC_pcdiv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pcdiv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0009;
    v0104 = v0000;
/* end of prologue */
    stack[-5] = v0104;
    v0104 = stack[-5];
    if (v0104 == nil) goto v0035;
    v0104 = stack[-5];
    v0104 = qcar(v0104);
    v0027 = v0104;
    v0104 = v0027;
    stack[0] = qcar(v0104);
    v0104 = v0027;
    v0027 = qcdr(v0104);
    v0104 = stack[-4];
    fn = elt(env, 2); /* cdiv */
    v0104 = (*qfn2(fn))(qenv(fn), v0027, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-6];
    v0104 = cons(stack[0], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-6];
    v0104 = ncons(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-6];
    stack[-2] = v0104;
    stack[-3] = v0104;
    goto v0021;

v0021:
    v0104 = stack[-5];
    v0104 = qcdr(v0104);
    stack[-5] = v0104;
    v0104 = stack[-5];
    if (v0104 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0104 = stack[-5];
    v0104 = qcar(v0104);
    v0027 = v0104;
    v0104 = v0027;
    stack[0] = qcar(v0104);
    v0104 = v0027;
    v0027 = qcdr(v0104);
    v0104 = stack[-4];
    fn = elt(env, 2); /* cdiv */
    v0104 = (*qfn2(fn))(qenv(fn), v0027, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-6];
    v0104 = cons(stack[0], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-6];
    v0104 = ncons(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-6];
    v0104 = Lrplacd(nil, stack[-1], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-6];
    v0104 = stack[-2];
    v0104 = qcdr(v0104);
    stack[-2] = v0104;
    goto v0021;

v0035:
    v0104 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0104); }
/* error exit handlers */
v0034:
    popv(7);
    return nil;
}



/* Code for bfrsq */

static Lisp_Object CC_bfrsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfrsq");
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
    v0012 = v0000;
/* end of prologue */
    v0052 = v0012;
    v0052 = qcar(v0052);
    v0012 = qcdr(v0012);
    stack[-1] = v0012;
    v0012 = v0052;
    if (!consp(v0012)) goto v0050;
    v0012 = v0052;
    fn = elt(env, 1); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0012, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    v0012 = stack[-1];
    v0052 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    v0052 = (*qfn2(fn))(qenv(fn), v0012, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    {
        Lisp_Object v0029 = stack[0];
        popv(3);
        fn = elt(env, 2); /* plubf */
        return (*qfn2(fn))(qenv(fn), v0029, v0052);
    }

v0050:
    v0012 = v0052;
    stack[0] = times2(v0012, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    v0012 = stack[-1];
    v0052 = stack[-1];
    v0052 = times2(v0012, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    {
        Lisp_Object v0092 = stack[0];
        popv(3);
        return plus2(v0092, v0052);
    }
/* error exit handlers */
v0019:
    popv(3);
    return nil;
}



/* Code for normalform */

static Lisp_Object CC_normalform(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0019, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for normalform");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    v0029 = v0000;
/* end of prologue */
    v0019 = qvalue(elt(env, 1)); /* !*mode */
    v0018 = elt(env, 2); /* algebraic */
    if (v0019 == v0018) goto v0004;
    v0019 = v0029;
    v0018 = stack[0];
    {
        popv(5);
        fn = elt(env, 4); /* normalform!* */
        return (*qfn2(fn))(qenv(fn), v0019, v0018);
    }

v0004:
    v0018 = v0029;
    fn = elt(env, 5); /* reval */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    fn = elt(env, 6); /* dpmat_from_a */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    v0018 = stack[0];
    fn = elt(env, 5); /* reval */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    fn = elt(env, 6); /* dpmat_from_a */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    fn = elt(env, 4); /* normalform!* */
    v0018 = (*qfn2(fn))(qenv(fn), stack[-1], v0018);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    stack[-3] = v0018;
    stack[-2] = elt(env, 3); /* list */
    v0018 = stack[-3];
    v0018 = qcar(v0018);
    fn = elt(env, 7); /* dpmat_2a */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    v0018 = stack[-3];
    v0018 = qcdr(v0018);
    v0018 = qcar(v0018);
    fn = elt(env, 7); /* dpmat_2a */
    stack[0] = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-4];
    v0018 = stack[-3];
    v0018 = qcdr(v0018);
    v0018 = qcdr(v0018);
    v0018 = qcar(v0018);
    fn = elt(env, 7); /* dpmat_2a */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    {
        Lisp_Object v0069 = stack[-2];
        Lisp_Object v0038 = stack[-1];
        Lisp_Object v0116 = stack[0];
        popv(5);
        return list4(v0069, v0038, v0116, v0018);
    }
/* error exit handlers */
v0040:
    popv(5);
    return nil;
}



/* Code for ofsf_evalatp */

static Lisp_Object CC_ofsf_evalatp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0123, v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_evalatp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    v0066 = v0000;
/* end of prologue */
    v0123 = v0066;
    v0122 = elt(env, 1); /* equal */
    if (v0123 == v0122) goto v0007;
    v0123 = v0066;
    v0122 = elt(env, 2); /* neq */
    if (v0123 == v0122) goto v0047;
    v0123 = v0066;
    v0122 = elt(env, 3); /* leq */
    if (v0123 == v0122) goto v0001;
    v0123 = v0066;
    v0122 = elt(env, 4); /* geq */
    if (v0123 == v0122) goto v0041;
    v0123 = v0066;
    v0122 = elt(env, 5); /* lessp */
    if (v0123 == v0122) goto v0057;
    v0123 = v0066;
    v0122 = elt(env, 6); /* greaterp */
    if (v0123 == v0122) goto v0024;
    v0122 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v0122 == nil)) goto v0124;
    v0122 = elt(env, 8); /* "ofsf_evalatp: unknown operator " */
    v0123 = v0066;
    v0122 = list2(v0122, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-1];
    fn = elt(env, 9); /* lprie */
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-1];
    goto v0124;

v0124:
    v0122 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    v0122 = nil;
    { popv(2); return onevalue(v0122); }

v0024:
    v0122 = stack[0];
    fn = elt(env, 10); /* minusf */
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    if (!(v0122 == nil)) goto v0026;
    v0122 = stack[0];
    v0122 = (v0122 == nil ? lisp_true : nil);
    goto v0026;

v0026:
    v0122 = (v0122 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0122); }

v0057:
    v0122 = stack[0];
    {
        popv(2);
        fn = elt(env, 10); /* minusf */
        return (*qfn1(fn))(qenv(fn), v0122);
    }

v0041:
    v0122 = stack[0];
    fn = elt(env, 10); /* minusf */
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    v0122 = (v0122 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0122); }

v0001:
    v0122 = stack[0];
    fn = elt(env, 10); /* minusf */
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    if (!(v0122 == nil)) { popv(2); return onevalue(v0122); }
    v0122 = stack[0];
    v0122 = (v0122 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0122); }

v0047:
    v0122 = stack[0];
    v0122 = (v0122 == nil ? lisp_true : nil);
    v0122 = (v0122 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0122); }

v0007:
    v0122 = stack[0];
    v0122 = (v0122 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0122); }
/* error exit handlers */
v0087:
    popv(2);
    return nil;
}



/* Code for orddf */

static Lisp_Object CC_orddf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for orddf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */

v0007:
    v0052 = stack[-1];
    if (v0052 == nil) goto v0021;
    v0052 = stack[0];
    if (v0052 == nil) goto v0113;
    v0052 = stack[-1];
    v0012 = qcar(v0052);
    v0052 = stack[0];
    v0052 = qcar(v0052);
    fn = elt(env, 6); /* exptcompare */
    v0052 = (*qfn2(fn))(qenv(fn), v0012, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    if (v0052 == nil) goto v0010;
    v0052 = qvalue(elt(env, 4)); /* t */
    { popv(3); return onevalue(v0052); }

v0010:
    v0052 = stack[0];
    v0012 = qcar(v0052);
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    fn = elt(env, 6); /* exptcompare */
    v0052 = (*qfn2(fn))(qenv(fn), v0012, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    if (v0052 == nil) goto v0011;
    v0052 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0052); }

v0011:
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    stack[-1] = v0052;
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    stack[0] = v0052;
    goto v0007;

v0113:
    v0052 = elt(env, 3); /* "Orddf u longer than v" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v0052);
    }

v0021:
    v0052 = stack[0];
    if (v0052 == nil) goto v0094;
    v0052 = elt(env, 2); /* "Orddf v longer than u" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v0052);
    }

v0094:
    v0052 = elt(env, 1); /* "Orddf = case" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v0052);
    }
/* error exit handlers */
v0019:
    popv(3);
    return nil;
}



/* Code for mk!+outer!+list */

static Lisp_Object CC_mkLouterLlist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0071;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+outer+list");
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
    v0094 = elt(env, 1); /* list */
    v0071 = ncons(v0094);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    v0094 = stack[0];
        popv(1);
        return Lappend(nil, v0071, v0094);
/* error exit handlers */
v0047:
    popv(1);
    return nil;
}



/* Code for mri_prepat */

static Lisp_Object CC_mri_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_prepat");
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
    v0007 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* mri_2pasfat */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* pasf_prepat */
        return (*qfn1(fn))(qenv(fn), v0007);
    }
/* error exit handlers */
v0101:
    popv(1);
    return nil;
}



/* Code for pasf_subfof */

static Lisp_Object MS_CDECL CC_pasf_subfof(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0043, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0109, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_subfof");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_subfof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0043,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0043);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0113 = v0043;
    v0109 = v0009;
    v0053 = v0000;
/* end of prologue */
    stack[-1] = v0113;
    stack[0] = elt(env, 1); /* pasf_subfof1 */
    v0113 = v0053;
    v0113 = list2(v0113, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    {
        Lisp_Object v0001 = stack[-1];
        Lisp_Object v0002 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v0001, v0002, v0113);
    }
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for minusml */

static Lisp_Object CC_minusml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusml");
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
    v0044 = elt(env, 1); /* "<apply><minus/>" */
    fn = elt(env, 4); /* printout */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    v0032 = qvalue(elt(env, 2)); /* indent */
    v0044 = (Lisp_Object)49; /* 3 */
    v0044 = plus2(v0032, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0044; /* indent */
    v0044 = stack[0];
    fn = elt(env, 5); /* multiminus */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    v0032 = qvalue(elt(env, 2)); /* indent */
    v0044 = (Lisp_Object)49; /* 3 */
    v0044 = difference2(v0032, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0044; /* indent */
    v0044 = elt(env, 3); /* "</apply>" */
    fn = elt(env, 4); /* printout */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    v0044 = nil;
    { popv(2); return onevalue(v0044); }
/* error exit handlers */
v0002:
    popv(2);
    return nil;
}



/* Code for multerm */

static Lisp_Object CC_multerm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multerm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    v0091 = stack[-1];
    v0110 = qcdr(v0091);
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    fn = elt(env, 1); /* !*multsq */
    v0091 = (*qfn2(fn))(qenv(fn), v0110, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    stack[-2] = v0091;
    v0091 = stack[-1];
    v0110 = qcar(v0091);
    v0091 = stack[0];
    v0091 = qcar(v0091);
    fn = elt(env, 2); /* mulpower */
    v0091 = (*qfn2(fn))(qenv(fn), v0110, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    {
        Lisp_Object v0008 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multdfconst */
        return (*qfn2(fn))(qenv(fn), v0008, v0091);
    }
/* error exit handlers */
v0028:
    popv(4);
    return nil;
}



/* Code for band_matrix */

static Lisp_Object CC_band_matrix(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0153, v0154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for band_matrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v0009;
    stack[-9] = v0000;
/* end of prologue */
    stack[-10] = nil;
    v0153 = stack[-8];
    v0153 = integerp(v0153);
    if (!(v0153 == nil)) goto v0083;
    v0153 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0153 == nil)) goto v0109;
    v0153 = elt(env, 2); /* "Error in band_matrix(second argument): should be an integer." 
*/
    fn = elt(env, 9); /* lprie */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    goto v0109;

v0109:
    v0153 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    goto v0083;

v0083:
    v0153 = stack[-9];
    if (!consp(v0153)) goto v0037;
    v0153 = stack[-9];
    v0154 = qcar(v0153);
    v0153 = elt(env, 3); /* list */
    if (v0154 == v0153) goto v0006;
    v0153 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0153 == nil)) goto v0039;
    v0153 = elt(env, 4); /* "Error in band_matrix(first argument): should be single value or list." 
*/
    fn = elt(env, 9); /* lprie */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    goto v0039;

v0039:
    v0153 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    goto v0049;

v0049:
    v0153 = stack[-9];
    v0153 = Llength(nil, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    stack[-7] = v0153;
    v0153 = stack[-7];
    v0153 = Levenp(nil, v0153);
    env = stack[-11];
    if (v0153 == nil) goto v0118;
    v0153 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0153 == nil)) goto v0116;
    v0153 = elt(env, 5); /* "Error in band matrix(first argument): number of elements must be odd." 
*/
    fn = elt(env, 9); /* lprie */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    goto v0116;

v0116:
    v0153 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    goto v0118;

v0118:
    stack[0] = elt(env, 6); /* quotient */
    v0153 = stack[-7];
    v0154 = add1(v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    v0153 = (Lisp_Object)33; /* 2 */
    v0153 = list3(stack[0], v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    fn = elt(env, 10); /* reval */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    stack[-6] = v0153;
    v0153 = stack[-6];
    v0153 = integerp(v0153);
    if (v0153 == nil) goto v0156;
    v0153 = stack[-6];
    v0154 = v0153;
    goto v0157;

v0157:
    v0153 = stack[-8];
    v0153 = (Lisp_Object)greaterp2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    v0153 = v0153 ? lisp_true : nil;
    env = stack[-11];
    if (v0153 == nil) goto v0158;
    v0153 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0153 == nil)) goto v0096;
    v0153 = elt(env, 7); /* "Error in band_matrix: too many elements. Band matrix is overflowing." 
*/
    fn = elt(env, 9); /* lprie */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    goto v0096;

v0096:
    v0153 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    goto v0159;

v0159:
    v0153 = (Lisp_Object)17; /* 1 */
    stack[-5] = v0153;
    goto v0160;

v0160:
    v0154 = stack[-8];
    v0153 = stack[-5];
    v0153 = difference2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    v0153 = Lminusp(nil, v0153);
    env = stack[-11];
    if (!(v0153 == nil)) { Lisp_Object res = stack[-10]; popv(12); return onevalue(res); }
    v0153 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0153;
    goto v0161;

v0161:
    v0154 = stack[-8];
    v0153 = stack[-4];
    v0153 = difference2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    v0153 = Lminusp(nil, v0153);
    env = stack[-11];
    if (v0153 == nil) goto v0162;
    v0153 = stack[-5];
    v0153 = add1(v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    stack[-5] = v0153;
    goto v0160;

v0162:
    v0154 = stack[-6];
    v0153 = stack[-5];
    v0154 = difference2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    v0153 = stack[-4];
    v0154 = plus2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    v0153 = (Lisp_Object)1; /* 0 */
    v0153 = (Lisp_Object)greaterp2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    v0153 = v0153 ? lisp_true : nil;
    env = stack[-11];
    if (v0153 == nil) goto v0163;
    v0154 = stack[-6];
    v0153 = stack[-5];
    v0154 = difference2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    v0153 = stack[-4];
    v0154 = plus2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    v0153 = stack[-7];
    v0153 = (Lisp_Object)lesseq2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    v0153 = v0153 ? lisp_true : nil;
    env = stack[-11];
    if (v0153 == nil) goto v0163;
    stack[-3] = stack[-10];
    stack[-2] = stack[-5];
    stack[-1] = stack[-4];
    stack[0] = stack[-9];
    v0154 = stack[-6];
    v0153 = stack[-5];
    v0154 = difference2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    v0153 = stack[-4];
    v0153 = plus2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    fn = elt(env, 11); /* pnth */
    v0153 = (*qfn2(fn))(qenv(fn), stack[0], v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    v0153 = qcar(v0153);
    fn = elt(env, 12); /* setmat */
    v0153 = (*qfnn(fn))(qenv(fn), 4, stack[-3], stack[-2], stack[-1], v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    goto v0163;

v0163:
    v0153 = stack[-4];
    v0153 = add1(v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    stack[-4] = v0153;
    goto v0161;

v0158:
    v0154 = stack[-8];
    v0153 = stack[-8];
    fn = elt(env, 13); /* mkmatrix */
    v0153 = (*qfn2(fn))(qenv(fn), v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    stack[-10] = v0153;
    goto v0159;

v0156:
    v0153 = stack[-6];
    fn = elt(env, 10); /* reval */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    v0154 = v0153;
    goto v0157;

v0006:
    v0153 = stack[-9];
    v0153 = qcdr(v0153);
    stack[-9] = v0153;
    goto v0049;

v0037:
    v0153 = stack[-9];
    v0153 = ncons(v0153);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-11];
    stack[-9] = v0153;
    goto v0049;
/* error exit handlers */
v0155:
    popv(12);
    return nil;
}



/* Code for genexp */

static Lisp_Object CC_genexp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for genexp");
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

v0082:
    v0050 = stack[0];
    if (!consp(v0050)) goto v0055;
    v0050 = stack[0];
    v0050 = qcar(v0050);
    v0050 = CC_genexp(env, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-1];
    if (!(v0050 == nil)) { popv(2); return onevalue(v0050); }
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    stack[0] = v0050;
    goto v0082;

v0055:
    v0050 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* genp */
        return (*qfn1(fn))(qenv(fn), v0050);
    }
/* error exit handlers */
v0113:
    popv(2);
    return nil;
}



/* Code for lchk */

static Lisp_Object CC_lchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0029;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lchk");
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
    v0019 = stack[0];
    if (v0019 == nil) goto v0035;
    v0019 = stack[0];
    v0019 = qcar(v0019);
    v0019 = (consp(v0019) ? nil : lisp_true);
    goto v0084;

v0084:
    if (v0019 == nil) goto v0017;
    v0019 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0019); }

v0017:
    v0019 = stack[0];
    v0019 = qcar(v0019);
    v0019 = Llength(nil, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    stack[-1] = v0019;
    goto v0032;

v0032:
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    stack[0] = v0019;
    v0019 = stack[0];
    if (v0019 == nil) goto v0005;
    v0019 = stack[0];
    v0019 = qcar(v0019);
    if (!consp(v0019)) goto v0041;
    v0019 = stack[0];
    v0019 = qcar(v0019);
    v0029 = Llength(nil, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0019 = stack[-1];
    v0019 = Lneq(nil, v0029, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    goto v0114;

v0114:
    if (v0019 == nil) goto v0032;
    v0019 = stack[0];
    v0019 = (v0019 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0019); }

v0041:
    v0019 = qvalue(elt(env, 1)); /* t */
    goto v0114;

v0005:
    v0019 = qvalue(elt(env, 1)); /* t */
    goto v0114;

v0035:
    v0019 = qvalue(elt(env, 1)); /* t */
    goto v0084;
/* error exit handlers */
v0024:
    popv(3);
    return nil;
}



/* Code for rd!:difference */

static Lisp_Object CC_rdTdifference(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0133, v0127, v0176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[0] = v0000;
/* end of prologue */
    v0133 = qvalue(elt(env, 1)); /* nil */
    v0127 = v0133;
    v0133 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v0133 == nil) goto v0084;
    v0133 = qvalue(elt(env, 1)); /* nil */
    goto v0070;

v0070:
    if (v0133 == nil) goto v0013;
    v0133 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v0133, v0127);

v0013:
    v0127 = stack[0];
    v0133 = stack[-1];
    fn = elt(env, 8); /* convprc2 */
    v0133 = (*qfn2(fn))(qenv(fn), v0127, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    stack[-1] = v0133;
    v0133 = qvalue(elt(env, 4)); /* yy!! */
    stack[-3] = v0133;
    v0133 = stack[-1];
    if (!consp(v0133)) goto v0159;
    v0127 = stack[-1];
    v0133 = stack[-3];
    fn = elt(env, 9); /* difbf */
    v0133 = (*qfn2(fn))(qenv(fn), v0127, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0069;

v0069:
    stack[0] = v0133;
    stack[-2] = stack[0];
    v0133 = stack[-3];
    if (!consp(v0133)) goto v0178;
    stack[0] = elt(env, 3); /* !:rd!: */
    v0133 = stack[-3];
    v0133 = qcdr(v0133);
    v0133 = qcar(v0133);
    v0127 = negate(v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    v0133 = stack[-3];
    v0133 = qcdr(v0133);
    v0133 = qcdr(v0133);
    v0133 = list2star(stack[0], v0127, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0179;

v0179:
    fn = elt(env, 10); /* rdzchk */
    v0133 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    v0127 = v0133;
    v0133 = v0127;
    if (!(!consp(v0133))) { popv(5); return onevalue(v0127); }
    v0133 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v0133, v0127);

v0178:
    v0133 = stack[-3];
    v0133 = negate(v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0179;

v0159:
    stack[-2] = elt(env, 5); /* difference */
    v0133 = stack[-1];
    stack[0] = Lmkquote(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    v0133 = stack[-3];
    v0133 = Lmkquote(nil, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    v0176 = list3(stack[-2], stack[0], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    v0127 = qvalue(elt(env, 1)); /* nil */
    v0133 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 11); /* errorset */
    v0133 = (*qfnn(fn))(qenv(fn), 3, v0176, v0127, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    v0127 = v0133;
    v0133 = v0127;
    if (!consp(v0133)) goto v0152;
    v0133 = v0127;
    v0133 = qcdr(v0133);
    goto v0180;

v0180:
    if (v0133 == nil) goto v0181;
    fn = elt(env, 12); /* rndbfon */
    v0133 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    v0133 = stack[-1];
    v0133 = Lfloatp(nil, v0133);
    env = stack[-4];
    if (v0133 == nil) goto v0061;
    v0133 = stack[-1];
    fn = elt(env, 13); /* fl2bf */
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    stack[0] = v0133;
    goto v0059;

v0059:
    stack[-1] = stack[0];
    v0133 = stack[-3];
    v0133 = Lfloatp(nil, v0133);
    env = stack[-4];
    if (v0133 == nil) goto v0107;
    v0133 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0182;

v0182:
    stack[-3] = v0133;
    fn = elt(env, 9); /* difbf */
    v0133 = (*qfn2(fn))(qenv(fn), stack[0], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0069;

v0107:
    v0133 = stack[-3];
    if (!consp(v0133)) goto v0183;
    v0133 = stack[-3];
    goto v0184;

v0184:
    fn = elt(env, 14); /* csl_normbf */
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0182;

v0183:
    v0133 = stack[-3];
    v0133 = integerp(v0133);
    if (v0133 == nil) goto v0147;
    v0176 = elt(env, 3); /* !:rd!: */
    v0127 = stack[-3];
    v0133 = (Lisp_Object)1; /* 0 */
    v0133 = list2star(v0176, v0127, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0184;

v0147:
    v0133 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0184;

v0061:
    v0133 = stack[-1];
    if (!consp(v0133)) goto v0062;
    v0133 = stack[-1];
    goto v0185;

v0185:
    fn = elt(env, 14); /* csl_normbf */
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    stack[0] = v0133;
    goto v0059;

v0062:
    v0133 = stack[-1];
    v0133 = integerp(v0133);
    if (v0133 == nil) goto v0081;
    v0176 = elt(env, 3); /* !:rd!: */
    v0127 = stack[-1];
    v0133 = (Lisp_Object)1; /* 0 */
    v0133 = list2star(v0176, v0127, v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0185;

v0081:
    v0133 = stack[-1];
    fn = elt(env, 15); /* read!:num */
    v0133 = (*qfn1(fn))(qenv(fn), v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    goto v0185;

v0181:
    v0133 = v0127;
    v0133 = qcar(v0133);
    goto v0069;

v0152:
    v0133 = qvalue(elt(env, 7)); /* t */
    goto v0180;

v0084:
    v0133 = stack[0];
    v0133 = qcdr(v0133);
    if (!consp(v0133)) goto v0047;
    v0133 = qvalue(elt(env, 1)); /* nil */
    goto v0070;

v0047:
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    if (!consp(v0133)) goto v0032;
    v0133 = qvalue(elt(env, 1)); /* nil */
    goto v0070;

v0032:
    v0133 = stack[0];
    stack[-2] = qcdr(v0133);
    v0133 = stack[-1];
    v0133 = qcdr(v0133);
    v0133 = negate(v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    fn = elt(env, 16); /* safe!-fp!-plus */
    v0133 = (*qfn2(fn))(qenv(fn), stack[-2], v0133);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-4];
    v0127 = v0133;
    goto v0070;
/* error exit handlers */
v0177:
    popv(5);
    return nil;
}



/* Code for aceq */

static Lisp_Object CC_aceq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042, v0045, v0046;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aceq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0042 = v0009;
    v0045 = v0000;
/* end of prologue */

v0101:
    v0041 = v0045;
    if (v0041 == nil) goto v0020;
    v0041 = v0042;
    if (v0041 == nil) goto v0071;
    v0041 = v0045;
    v0046 = qcar(v0041);
    v0041 = v0042;
    v0041 = Lmember(nil, v0046, v0041);
    if (v0041 == nil) goto v0112;
    v0041 = v0045;
    v0041 = qcdr(v0041);
    stack[0] = v0041;
    v0041 = v0045;
    v0041 = qcar(v0041);
    v0041 = Ldelete(nil, v0041, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-1];
    v0042 = v0041;
    v0041 = stack[0];
    v0045 = v0041;
    goto v0101;

v0112:
    v0041 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0041); }

v0071:
    v0041 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0041); }

v0020:
    v0041 = v0042;
    v0041 = (v0041 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0041); }
/* error exit handlers */
v0120:
    popv(2);
    return nil;
}



/* Code for lispreadp */

static Lisp_Object CC_lispreadp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0084;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispreadp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0070 = v0000;
/* end of prologue */
    v0084 = elt(env, 1); /* read */
        return Leqcar(nil, v0070, v0084);
}



/* Code for reval3 */

static Lisp_Object CC_reval3(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval3");
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
    v0017 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* simp */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0017);
    }
/* error exit handlers */
v0021:
    popv(1);
    return nil;
}



/* Code for incident */

static Lisp_Object MS_CDECL CC_incident(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0043, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0051, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "incident");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for incident");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0043,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0043);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0043;
    stack[0] = v0009;
    stack[-2] = v0000;
/* end of prologue */

v0082:
    v0039 = stack[0];
    if (v0039 == nil) goto v0101;
    v0057 = stack[-2];
    v0039 = stack[0];
    v0051 = qcar(v0039);
    v0039 = stack[-1];
    fn = elt(env, 2); /* incident1 */
    v0039 = (*qfnn(fn))(qenv(fn), 3, v0057, v0051, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-3];
    v0051 = v0039;
    v0039 = v0051;
    if (v0039 == nil) goto v0041;
    v0039 = stack[0];
    v0039 = qcdr(v0039);
    popv(4);
    return cons(v0051, v0039);

v0041:
    v0039 = stack[0];
    stack[0] = qcdr(v0039);
    v0039 = stack[-1];
    v0039 = add1(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-3];
    stack[-1] = v0039;
    goto v0082;

v0101:
    v0039 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0039); }
/* error exit handlers */
v0012:
    popv(4);
    return nil;
}



/* Code for innprodp2 */

static Lisp_Object CC_innprodp2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0045, v0046, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for innprodp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0046 = v0009;
    stack[0] = v0000;
/* end of prologue */
    v0042 = qvalue(elt(env, 1)); /* nil */
    v0045 = v0046;
    v0042 = cons(v0042, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0046 = v0042;
    goto v0083;

v0083:
    v0042 = stack[0];
    if (v0042 == nil) { popv(2); return onevalue(v0046); }
    v0042 = v0046;
    if (v0042 == nil) { popv(2); return onevalue(v0046); }
    v0054 = qvalue(elt(env, 1)); /* nil */
    v0042 = stack[0];
    v0045 = qcar(v0042);
    v0042 = v0046;
    v0042 = qcdr(v0042);
    v0046 = qcar(v0046);
    fn = elt(env, 2); /* innprodkp */
    v0042 = (*qfnn(fn))(qenv(fn), 4, v0054, v0045, v0042, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0046 = v0042;
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    stack[0] = v0042;
    goto v0083;
/* error exit handlers */
v0030:
    popv(2);
    return nil;
}



/* Code for matop_pseudomod */

static Lisp_Object CC_matop_pseudomod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matop_pseudomod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0035 = v0009;
    v0094 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* mod!* */
    v0035 = (*qfn2(fn))(qenv(fn), v0094, v0035);
    errexit();
    v0035 = qcar(v0035);
    return onevalue(v0035);
}



/* Code for nf */

static Lisp_Object MS_CDECL CC_nf(Lisp_Object env, int nargs,
                         Lisp_Object v0009, Lisp_Object v0043,
                         Lisp_Object v0056, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0202, v0203, v0204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "nf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0056,v0043,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0009,v0043,v0056);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0056;
    v0202 = v0043;
    v0203 = v0009;
/* end of prologue */
    stack[-10] = qvalue(elt(env, 1)); /* gg!* */
    qvalue(elt(env, 1)) = nil; /* gg!* */
    qvalue(elt(env, 1)) = v0202; /* gg!* */
    v0202 = qvalue(elt(env, 1)); /* gg!* */
    if (v0202 == nil) goto v0084;
    stack[-3] = nil;
    v0202 = (Lisp_Object)1; /* 0 */
    stack[0] = v0202;
    v0202 = v0203;
    stack[-8] = v0202;
    v0202 = qvalue(elt(env, 1)); /* gg!* */
    stack[-2] = v0202;
    goto v0016;

v0016:
    v0202 = stack[-8];
    if (v0202 == nil) goto v0153;
    v0202 = stack[-8];
    v0202 = qcar(v0202);
    v0202 = qcar(v0202);
    stack[-7] = v0202;
    goto v0042;

v0042:
    v0202 = stack[-2];
    if (v0202 == nil) goto v0092;
    v0203 = stack[-7];
    v0202 = stack[-2];
    v0202 = qcar(v0202);
    v0202 = qcdr(v0202);
    fn = elt(env, 13); /* dless */
    v0202 = (*qfn2(fn))(qenv(fn), v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    goto v0014;

v0014:
    if (v0202 == nil) goto v0041;
    v0202 = stack[-2];
    v0202 = qcdr(v0202);
    stack[-2] = v0202;
    goto v0042;

v0041:
    v0202 = stack[-2];
    if (v0202 == nil) goto v0153;
    v0202 = stack[-2];
    stack[-1] = v0202;
    goto v0068;

v0068:
    v0202 = stack[-1];
    if (v0202 == nil) goto v0067;
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0203 = qcdr(v0202);
    v0202 = stack[-7];
    fn = elt(env, 14); /* dd */
    stack[-4] = (*qfn2(fn))(qenv(fn), v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    v0203 = stack[-9];
    v0202 = (Lisp_Object)33; /* 2 */
    v0202 = plus2(v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    if (!(((int32_t)(stack[-4])) < ((int32_t)(v0202)))) goto v0067;
    v0202 = stack[-1];
    v0202 = qcdr(v0202);
    stack[-1] = v0202;
    goto v0068;

v0067:
    v0202 = stack[-1];
    if (v0202 == nil) goto v0098;
    v0203 = qvalue(elt(env, 4)); /* gv!* */
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0202 = qcar(v0202);
    v0202 = *(Lisp_Object *)((char *)v0203 + (CELL-TAG_VECTOR) + ((int32_t)v0202/(16/CELL)));
    stack[-6] = v0202;
    v0202 = stack[-8];
    v0202 = qcar(v0202);
    v0203 = qcdr(v0202);
    v0202 = stack[-6];
    v0202 = qcar(v0202);
    v0202 = qcdr(v0202);
    fn = elt(env, 15); /* gcdf!* */
    v0202 = (*qfn2(fn))(qenv(fn), v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    stack[-4] = v0202;
    v0202 = stack[-8];
    v0202 = qcar(v0202);
    v0203 = qcdr(v0202);
    v0202 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v0202 = (*qfn2(fn))(qenv(fn), v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    stack[-5] = v0202;
    v0202 = stack[-6];
    v0202 = qcar(v0202);
    v0203 = qcdr(v0202);
    v0202 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v0202 = (*qfn2(fn))(qenv(fn), v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    stack[-4] = v0202;
    v0203 = stack[-8];
    v0202 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v0202 = (*qfn2(fn))(qenv(fn), v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    stack[-8] = v0202;
    v0203 = stack[-3];
    v0202 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v0202 = (*qfn2(fn))(qenv(fn), v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    stack[-3] = v0202;
    v0203 = stack[-6];
    v0202 = stack[-5];
    fn = elt(env, 17); /* pcmult */
    v0202 = (*qfn2(fn))(qenv(fn), v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    stack[-6] = v0202;
    v0202 = stack[-6];
    stack[-4] = qcdr(v0202);
    v0203 = stack[-7];
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0202 = qcdr(v0202);
    fn = elt(env, 18); /* dquot */
    v0202 = (*qfn2(fn))(qenv(fn), v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    fn = elt(env, 19); /* pdmult */
    v0202 = (*qfn2(fn))(qenv(fn), stack[-4], v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    stack[-4] = v0202;
    v0202 = qvalue(elt(env, 5)); /* tred */
    if (v0202 == nil) goto v0206;
    v0202 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    v0202 = elt(env, 6); /* "r e d u c t i o n :  " */
    v0202 = Lprinc(nil, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    v0202 = stack[-7];
    v0202 = Lprinc(nil, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    v0202 = elt(env, 7); /* "/" */
    v0202 = Lprinc(nil, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    v0202 = stack[-1];
    v0202 = qcar(v0202);
    v0202 = qcdr(v0202);
    v0202 = Lprinc(nil, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    v0202 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    goto v0206;

v0206:
    v0202 = qvalue(elt(env, 8)); /* stars */
    if (v0202 == nil) goto v0207;
    v0202 = elt(env, 9); /* "*" */
    v0202 = Lprinc(nil, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    goto v0207;

v0207:
    v0202 = stack[0];
    v0202 = (Lisp_Object)((int32_t)(v0202) + 0x10);
    stack[0] = v0202;
    v0202 = stack[-8];
    v0203 = qcdr(v0202);
    v0202 = stack[-4];
    fn = elt(env, 20); /* pdif */
    v0202 = (*qfn2(fn))(qenv(fn), v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    stack[-8] = v0202;
    goto v0016;

v0098:
    v0202 = qvalue(elt(env, 3)); /* redtails */
    if (v0202 == nil) goto v0153;
    v0204 = stack[-7];
    v0202 = stack[-8];
    v0202 = qcar(v0202);
    v0203 = qcdr(v0202);
    v0202 = stack[-3];
    v0202 = acons(v0204, v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    stack[-3] = v0202;
    v0202 = stack[-8];
    v0202 = qcdr(v0202);
    stack[-8] = v0202;
    goto v0016;

v0153:
    v0203 = qvalue(elt(env, 10)); /* reductions!* */
    v0202 = stack[0];
    v0202 = (Lisp_Object)(int32_t)((int32_t)v0203 + (int32_t)v0202 - TAG_FIXNUM);
    qvalue(elt(env, 10)) = v0202; /* reductions!* */
    v0202 = qvalue(elt(env, 11)); /* nforms!* */
    v0202 = (Lisp_Object)((int32_t)(v0202) + 0x10);
    qvalue(elt(env, 11)) = v0202; /* nforms!* */
    v0202 = stack[-3];
    v0203 = Lnreverse(nil, v0202);
    env = stack[-11];
    v0202 = stack[-8];
    v0202 = Lappend(nil, v0203, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    fn = elt(env, 21); /* gcdout */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0205;
    env = stack[-11];
    stack[-4] = v0202;
    v0202 = stack[-4];
    if (!(v0202 == nil)) goto v0208;
    v0202 = qvalue(elt(env, 12)); /* zeros!* */
    v0202 = (Lisp_Object)((int32_t)(v0202) + 0x10);
    qvalue(elt(env, 12)) = v0202; /* zeros!* */
    goto v0208;

v0208:
    v0202 = stack[-4];
    goto v0017;

v0017:
    qvalue(elt(env, 1)) = stack[-10]; /* gg!* */
    { popv(12); return onevalue(v0202); }

v0092:
    v0202 = qvalue(elt(env, 2)); /* nil */
    goto v0014;

v0084:
    v0202 = v0203;
    goto v0017;
/* error exit handlers */
v0205:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-10]; /* gg!* */
    popv(12);
    return nil;
}



/* Code for ad_splitname */

static Lisp_Object CC_ad_splitname(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ad_splitname");
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
    v0092 = v0000;
/* end of prologue */
    v0029 = v0092;
    if (symbolp(v0029)) goto v0055;
    v0029 = nil;
    { popv(3); return onevalue(v0029); }

v0055:
    stack[0] = nil;
    v0029 = v0092;
    v0029 = Lexplode(nil, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    v0029 = Lreverse(nil, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    stack[-1] = v0029;
    goto v0047;

v0047:
    v0029 = stack[-1];
    if (v0029 == nil) goto v0083;
    v0029 = stack[-1];
    v0029 = qcar(v0029);
    fn = elt(env, 2); /* charnump!: */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    if (v0029 == nil) goto v0083;
    v0029 = stack[-1];
    v0092 = qcar(v0029);
    v0029 = stack[0];
    v0029 = cons(v0092, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    stack[0] = v0029;
    v0029 = stack[-1];
    v0029 = qcdr(v0029);
    stack[-1] = v0029;
    goto v0047;

v0083:
    v0029 = stack[-1];
    if (v0029 == nil) goto v0112;
    v0029 = stack[-1];
    v0029 = Lreverse(nil, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    v0029 = Lcompress(nil, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    v0029 = Lintern(nil, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    stack[-1] = v0029;
    goto v0112;

v0112:
    v0029 = stack[0];
    if (v0029 == nil) goto v0119;
    v0029 = stack[0];
    v0029 = Lcompress(nil, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    stack[0] = v0029;
    goto v0119;

v0119:
    v0092 = stack[-1];
    v0029 = stack[0];
    popv(3);
    return cons(v0092, v0029);
/* error exit handlers */
v0025:
    popv(3);
    return nil;
}



/* Code for multdfconst */

static Lisp_Object CC_multdfconst(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdfconst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0101;

v0101:
    v0014 = stack[-1];
    if (v0014 == nil) goto v0094;
    v0014 = stack[-2];
    v0014 = qcar(v0014);
    v0014 = (v0014 == nil ? lisp_true : nil);
    goto v0035;

v0035:
    if (v0014 == nil) goto v0032;
    v0014 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0014);
    }

v0032:
    v0014 = stack[-1];
    v0014 = qcar(v0014);
    stack[0] = qcar(v0014);
    v0015 = stack[-2];
    v0014 = stack[-1];
    v0014 = qcar(v0014);
    v0014 = qcdr(v0014);
    fn = elt(env, 3); /* multsq */
    v0014 = (*qfn2(fn))(qenv(fn), v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    fn = elt(env, 4); /* subs2q */
    v0015 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    v0014 = stack[-3];
    v0014 = acons(stack[0], v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    stack[-3] = v0014;
    v0014 = stack[-1];
    v0014 = qcdr(v0014);
    stack[-1] = v0014;
    goto v0101;

v0094:
    v0014 = qvalue(elt(env, 1)); /* t */
    goto v0035;
/* error exit handlers */
v0119:
    popv(5);
    return nil;
}



/* Code for ofsf_facequal!* */

static Lisp_Object CC_ofsf_facequalH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0008, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_facequal*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0008 = v0009;
    v0115 = v0000;
/* end of prologue */
    v0028 = qvalue(elt(env, 1)); /* !*rlsifac */
    if (v0028 == nil) goto v0001;
    v0028 = qvalue(elt(env, 2)); /* !*rlsiexpla */
    if (!(v0028 == nil)) goto v0007;
    v0028 = qvalue(elt(env, 3)); /* !*rlsiexpl */
    if (v0028 == nil) goto v0001;
    v0028 = elt(env, 4); /* or */
    if (!(v0008 == v0028)) goto v0001;

v0007:
    v0028 = v0115;
    {
        fn = elt(env, 7); /* ofsf_facequal */
        return (*qfn1(fn))(qenv(fn), v0028);
    }

v0001:
    v0028 = elt(env, 5); /* equal */
    v0008 = v0115;
    v0115 = qvalue(elt(env, 6)); /* nil */
    return list3(v0028, v0008, v0115);
}



/* Code for aex_freeids */

static Lisp_Object CC_aex_freeids(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_freeids");
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
    v0071 = stack[0];
    fn = elt(env, 1); /* aex_ex */
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    fn = elt(env, 2); /* ratpoly_idl */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    v0071 = stack[0];
    fn = elt(env, 3); /* aex_ctx */
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    fn = elt(env, 4); /* ctx_idl */
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    {
        Lisp_Object v0004 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* lto_setminus */
        return (*qfn2(fn))(qenv(fn), v0004, v0071);
    }
/* error exit handlers */
v0003:
    popv(3);
    return nil;
}



/* Code for crn!:prep */

static Lisp_Object CC_crnTprep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0044;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:prep");
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
    v0031 = v0000;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !:rn!: */
    v0044 = v0031;
    v0044 = qcdr(v0044);
    stack[0] = qcar(v0044);
    v0044 = elt(env, 1); /* !:rn!: */
    v0031 = qcdr(v0031);
    v0031 = qcdr(v0031);
    v0031 = cons(v0044, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-2];
    v0031 = acons(stack[-1], stack[0], v0031);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 2); /* crnprep1 */
        return (*qfn1(fn))(qenv(fn), v0031);
    }
/* error exit handlers */
v0002:
    popv(3);
    return nil;
}



/* Code for on!-double1 */

static Lisp_Object CC_onKdouble1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for on-double1");
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

v0055:
    v0002 = stack[0];
    v0002 = Lconsp(nil, v0002);
    env = stack[-1];
    if (v0002 == nil) goto v0044;
    v0002 = stack[0];
    v0002 = qcar(v0002);
    fn = elt(env, 3); /* doublep */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    if (v0002 == nil) goto v0023;
    v0002 = lisp_true;
    qvalue(elt(env, 1)) = v0002; /* !*double */
    { popv(2); return onevalue(v0002); }

v0023:
    v0002 = stack[0];
    v0002 = qcar(v0002);
    v0002 = CC_onKdouble1(env, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    v0002 = stack[0];
    v0002 = qcdr(v0002);
    stack[0] = v0002;
    goto v0055;

v0044:
    v0002 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0002); }
/* error exit handlers */
v0049:
    popv(2);
    return nil;
}



/* Code for evmtest!? */

static Lisp_Object CC_evmtestW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0008, v0115, v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evmtest?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0008 = v0009;
    v0115 = v0000;
/* end of prologue */

v0007:
    v0028 = v0115;
    if (v0028 == nil) goto v0110;
    v0028 = v0008;
    if (v0028 == nil) goto v0110;
    v0028 = v0115;
    v0112 = qcar(v0028);
    v0028 = v0008;
    v0028 = qcar(v0028);
    if (((int32_t)(v0112)) < ((int32_t)(v0028))) goto v0049;
    v0028 = v0115;
    v0028 = qcdr(v0028);
    v0115 = v0028;
    v0028 = v0008;
    v0028 = qcdr(v0028);
    v0008 = v0028;
    goto v0007;

v0049:
    v0028 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0028);

v0110:
    v0028 = v0008;
    {
        fn = elt(env, 2); /* evzero!? */
        return (*qfn1(fn))(qenv(fn), v0028);
    }
}



/* Code for vdpcondense */

static Lisp_Object CC_vdpcondense(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpcondense");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0021 = v0000;
/* end of prologue */
    v0021 = qcdr(v0021);
    v0021 = qcdr(v0021);
    v0021 = qcdr(v0021);
    v0021 = qcar(v0021);
    {
        fn = elt(env, 1); /* dipcondense */
        return (*qfn1(fn))(qenv(fn), v0021);
    }
}



/* Code for gpargp */

static Lisp_Object CC_gpargp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpargp");
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
    v0071 = stack[0];
    v0071 = Lstringp(nil, v0071);
    env = stack[-1];
    if (!(v0071 == nil)) { popv(2); return onevalue(v0071); }
    v0071 = stack[0];
    fn = elt(env, 1); /* gpexpp */
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    if (!(v0071 == nil)) { popv(2); return onevalue(v0071); }
    v0071 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* gplogexpp */
        return (*qfn1(fn))(qenv(fn), v0071);
    }
/* error exit handlers */
v0047:
    popv(2);
    return nil;
}



/* Code for !*pf2sq */

static Lisp_Object CC_Hpf2sq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0159, v0211, v0212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *pf2sq");
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
    v0211 = qvalue(elt(env, 1)); /* nil */
    v0159 = (Lisp_Object)17; /* 1 */
    v0159 = cons(v0211, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-2];
    stack[-1] = v0159;
    v0159 = stack[0];
    if (v0159 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0159 = stack[0];
    stack[0] = v0159;
    goto v0113;

v0113:
    v0159 = stack[0];
    if (v0159 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0159 = stack[0];
    v0159 = qcar(v0159);
    v0211 = qcar(v0159);
    v0159 = (Lisp_Object)17; /* 1 */
    if (v0211 == v0159) goto v0057;
    v0159 = stack[0];
    v0159 = qcar(v0159);
    v0212 = qcar(v0159);
    v0211 = (Lisp_Object)17; /* 1 */
    v0159 = (Lisp_Object)17; /* 1 */
    v0159 = acons(v0212, v0211, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-2];
    v0211 = ncons(v0159);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-2];
    v0159 = (Lisp_Object)17; /* 1 */
    v0159 = cons(v0211, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-2];
    v0211 = v0159;
    goto v0008;

v0008:
    v0159 = stack[0];
    v0159 = qcar(v0159);
    v0159 = qcdr(v0159);
    fn = elt(env, 2); /* multsq */
    v0211 = (*qfn2(fn))(qenv(fn), v0211, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-2];
    v0159 = stack[-1];
    fn = elt(env, 3); /* addsq */
    v0159 = (*qfn2(fn))(qenv(fn), v0211, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-2];
    stack[-1] = v0159;
    v0159 = stack[0];
    v0159 = qcdr(v0159);
    stack[0] = v0159;
    goto v0113;

v0057:
    v0211 = (Lisp_Object)17; /* 1 */
    v0159 = (Lisp_Object)17; /* 1 */
    v0159 = cons(v0211, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-2];
    v0211 = v0159;
    goto v0008;
/* error exit handlers */
v0213:
    popv(3);
    return nil;
}



/* Code for mo_2a */

static Lisp_Object CC_mo_2a(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_2a");
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
    v0035 = v0000;
/* end of prologue */
    stack[0] = qcar(v0035);
    v0035 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 2); /* ring_all_names */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-1];
    {
        Lisp_Object v0083 = stack[0];
        popv(2);
        fn = elt(env, 3); /* mo!=expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v0083, v0035);
    }
/* error exit handlers */
v0071:
    popv(2);
    return nil;
}



/* Code for lpos */

static Lisp_Object CC_lpos(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001, v0002, v0016, v0049;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpos");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0016 = v0009;
    v0049 = v0000;
/* end of prologue */
    v0002 = v0049;
    v0001 = v0016;
    v0001 = qcar(v0001);
    if (v0002 == v0001) goto v0007;
    v0001 = v0049;
    v0002 = v0016;
    v0002 = qcdr(v0002);
    v0001 = CC_lpos(env, v0001, v0002);
    errexit();
    return add1(v0001);

v0007:
    v0001 = (Lisp_Object)17; /* 1 */
    return onevalue(v0001);
}



/* Code for lessppair */

static Lisp_Object CC_lessppair(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0008, v0115, v0112;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lessppair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0008 = v0009;
    v0115 = v0000;
/* end of prologue */
    v0028 = v0115;
    v0112 = qcar(v0028);
    v0028 = v0008;
    v0028 = qcar(v0028);
    if (equal(v0112, v0028)) goto v0003;
    v0028 = v0115;
    v0028 = qcar(v0028);
    v0008 = qcar(v0008);
        return Llessp(nil, v0028, v0008);

v0003:
    v0028 = v0115;
    v0028 = qcdr(v0028);
    v0008 = qcdr(v0008);
        return Llessp(nil, v0028, v0008);
}



/* Code for sfto_lmultf */

static Lisp_Object CC_sfto_lmultf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_lmultf");
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
    goto v0101;

v0101:
    v0010 = stack[0];
    if (v0010 == nil) goto v0017;
    v0010 = stack[0];
    v0041 = qcar(v0010);
    v0010 = stack[-1];
    v0010 = cons(v0041, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    stack[-1] = v0010;
    v0010 = stack[0];
    v0010 = qcdr(v0010);
    stack[0] = v0010;
    goto v0101;

v0017:
    v0010 = (Lisp_Object)17; /* 1 */
    v0041 = v0010;
    goto v0021;

v0021:
    v0010 = stack[-1];
    if (v0010 == nil) { popv(3); return onevalue(v0041); }
    v0010 = stack[-1];
    v0010 = qcar(v0010);
    fn = elt(env, 1); /* multf */
    v0010 = (*qfn2(fn))(qenv(fn), v0010, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0041 = v0010;
    v0010 = stack[-1];
    v0010 = qcdr(v0010);
    stack[-1] = v0010;
    goto v0021;
/* error exit handlers */
v0046:
    popv(3);
    return nil;
}



/* Code for my!+nullsq!+p */

static Lisp_Object CC_myLnullsqLp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my+nullsq+p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0084 = v0000;
/* end of prologue */
    v0084 = qcar(v0084);
    if (v0084 == nil) goto v0101;
    v0084 = nil;
    return onevalue(v0084);

v0101:
    v0084 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0084);
}



/* Code for depend!-f */

static Lisp_Object CC_dependKf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119, v0111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */

v0082:
    v0119 = stack[-1];
    if (!consp(v0119)) goto v0020;
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = (consp(v0119) ? nil : lisp_true);
    goto v0021;

v0021:
    if (v0119 == nil) goto v0031;
    v0119 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0119); }

v0031:
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0111 = qcar(v0119);
    v0119 = stack[0];
    fn = elt(env, 3); /* depend!-p */
    v0119 = (*qfn2(fn))(qenv(fn), v0111, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    if (!(v0119 == nil)) { popv(3); return onevalue(v0119); }
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    v0111 = qcdr(v0119);
    v0119 = stack[0];
    v0119 = CC_dependKf(env, v0111, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    if (!(v0119 == nil)) { popv(3); return onevalue(v0119); }
    v0119 = stack[-1];
    v0111 = qcdr(v0119);
    v0119 = stack[0];
    stack[-1] = v0111;
    stack[0] = v0119;
    goto v0082;

v0020:
    v0119 = qvalue(elt(env, 1)); /* t */
    goto v0021;
/* error exit handlers */
v0013:
    popv(3);
    return nil;
}



/* Code for cl_bnfsimpl */

static Lisp_Object CC_cl_bnfsimpl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0050, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_bnfsimpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0009;
    v0022 = v0000;
/* end of prologue */
    v0023 = qvalue(elt(env, 1)); /* !*rlbnfsac */
    if (v0023 == nil) return onevalue(v0022);
    v0023 = v0022;
    {
        fn = elt(env, 2); /* cl_sac */
        return (*qfn2(fn))(qenv(fn), v0023, v0050);
    }
}



/* Code for vdp_make */

static Lisp_Object MS_CDECL CC_vdp_make(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0043, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0044, v0032;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdp_make");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_make");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0043,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0043);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0031 = v0043;
    v0044 = v0009;
    v0032 = v0000;
/* end of prologue */
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = v0044;
    stack[0] = v0032;
    v0044 = v0031;
    v0031 = qvalue(elt(env, 2)); /* nil */
    v0031 = list2(v0044, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    {
        Lisp_Object v0037 = stack[-2];
        Lisp_Object v0091 = stack[-1];
        Lisp_Object v0110 = stack[0];
        popv(3);
        return list3star(v0037, v0091, v0110, v0031);
    }
/* error exit handlers */
v0049:
    popv(3);
    return nil;
}



/* Code for containerml */

static Lisp_Object CC_containerml(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for containerml");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    v0041 = stack[0];
    v0010 = elt(env, 1); /* integer_interval */
    if (!(v0041 == v0010)) goto v0101;
    v0010 = elt(env, 2); /* interval */
    stack[0] = v0010;
    goto v0101;

v0101:
    v0010 = elt(env, 3); /* "<" */
    fn = elt(env, 9); /* printout */
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0010 = stack[0];
    v0010 = Lprinc(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0010 = stack[-1];
    v0041 = qcar(v0010);
    v0010 = elt(env, 4); /* "" */
    fn = elt(env, 10); /* attributesml */
    v0010 = (*qfn2(fn))(qenv(fn), v0041, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0010 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 11); /* indent!* */
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0010 = stack[-1];
    v0010 = qcdr(v0010);
    fn = elt(env, 12); /* multi_elem */
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0010 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 11); /* indent!* */
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0010 = elt(env, 7); /* "</" */
    fn = elt(env, 9); /* printout */
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0010 = stack[0];
    v0010 = Lprinc(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0010 = elt(env, 8); /* ">" */
    v0010 = Lprinc(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    v0010 = nil;
    { popv(3); return onevalue(v0010); }
/* error exit handlers */
v0046:
    popv(3);
    return nil;
}



/* Code for findnthroot */

static Lisp_Object CC_findnthroot(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0056;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findnthroot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0056 = v0000;
/* end of prologue */
    v0056 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0056);
}



/* Code for difference!: */

static Lisp_Object CC_differenceT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0074, v0072;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difference:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0009;
    v0072 = v0000;
/* end of prologue */
    v0095 = v0072;
    v0095 = qcdr(v0095);
    v0074 = qcar(v0095);
    stack[-1] = v0074;
    v0095 = (Lisp_Object)1; /* 0 */
    if (v0074 == v0095) goto v0053;
    v0095 = stack[-2];
    v0095 = qcdr(v0095);
    v0074 = qcar(v0095);
    stack[0] = v0074;
    v0095 = (Lisp_Object)1; /* 0 */
    if (v0074 == v0095) { popv(6); return onevalue(v0072); }
    v0095 = v0072;
    v0095 = qcdr(v0095);
    v0074 = qcdr(v0095);
    stack[-4] = v0074;
    v0095 = stack[-2];
    v0095 = qcdr(v0095);
    v0095 = qcdr(v0095);
    stack[-2] = v0095;
    v0074 = difference2(v0074, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    stack[-3] = v0074;
    v0095 = (Lisp_Object)1; /* 0 */
    if (v0074 == v0095) goto v0116;
    v0074 = stack[-3];
    v0095 = (Lisp_Object)1; /* 0 */
    v0095 = (Lisp_Object)greaterp2(v0074, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    v0095 = v0095 ? lisp_true : nil;
    env = stack[-5];
    if (v0095 == nil) goto v0158;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v0074 = stack[-1];
    v0095 = stack[-3];
    v0074 = Lash1(nil, v0074, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    v0095 = stack[0];
    v0074 = difference2(v0074, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    v0095 = stack[-2];
    {
        Lisp_Object v0105 = stack[-4];
        popv(6);
        return list2star(v0105, v0074, v0095);
    }

v0158:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v0095 = stack[-3];
    v0095 = negate(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    v0095 = Lash1(nil, stack[0], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-5];
    v0074 = difference2(stack[-1], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    v0095 = stack[-4];
    {
        Lisp_Object v0106 = stack[-2];
        popv(6);
        return list2star(v0106, v0074, v0095);
    }

v0116:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v0074 = stack[-1];
    v0095 = stack[0];
    v0074 = difference2(v0074, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    v0095 = stack[-4];
    {
        Lisp_Object v0198 = stack[-2];
        popv(6);
        return list2star(v0198, v0074, v0095);
    }

v0053:
    stack[0] = elt(env, 1); /* !:rd!: */
    v0095 = stack[-2];
    v0095 = qcdr(v0095);
    v0095 = qcar(v0095);
    v0074 = negate(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    v0095 = stack[-2];
    v0095 = qcdr(v0095);
    v0095 = qcdr(v0095);
    {
        Lisp_Object v0161 = stack[0];
        popv(6);
        return list2star(v0161, v0074, v0095);
    }
/* error exit handlers */
v0081:
    popv(6);
    return nil;
}



/* Code for prop!-simp2 */

static Lisp_Object CC_propKsimp2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0013;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0009;
    stack[-3] = v0000;
/* end of prologue */
    v0012 = stack[-2];
    if (!consp(v0012)) goto v0035;
    v0013 = stack[-2];
    v0012 = stack[-3];
    v0012 = Lmember(nil, v0013, v0012);
    goto v0084;

v0084:
    stack[-4] = v0012;
    if (v0012 == nil) goto v0119;
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v0012 = stack[-3];
    stack[0] = Llength(nil, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-5];
    v0012 = stack[-4];
    v0012 = Llength(nil, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-5];
    v0012 = difference2(stack[0], v0012);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-5];
    stack[0] = Lexpt(nil, stack[-1], v0012);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-5];
    v0013 = stack[-2];
    v0012 = stack[-3];
    v0012 = Ldelete(nil, v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    {
        Lisp_Object v0025 = stack[0];
        popv(6);
        return cons(v0025, v0012);
    }

v0119:
    v0012 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0012); }

v0035:
    v0012 = qvalue(elt(env, 1)); /* nil */
    goto v0084;
/* error exit handlers */
v0024:
    popv(6);
    return nil;
}



/* Code for remchkf */

static Lisp_Object MS_CDECL CC_remchkf(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0043, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0104, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "remchkf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remchkf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0043,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0043);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0043;
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    v0104 = stack[-2];
    v0103 = stack[-1];
    fn = elt(env, 3); /* remchkf1 */
    v0103 = (*qfn2(fn))(qenv(fn), v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-4];
    stack[-3] = v0103;
    v0103 = stack[-3];
    if (!consp(v0103)) goto v0109;
    v0103 = stack[-3];
    v0103 = qcar(v0103);
    v0103 = (consp(v0103) ? nil : lisp_true);
    goto v0113;

v0113:
    if (v0103 == nil) goto v0048;
    v0103 = qvalue(elt(env, 1)); /* t */
    goto v0004;

v0004:
    if (!(v0103 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0103 = stack[-3];
    stack[-2] = qcar(v0103);
    v0103 = stack[-3];
    v0027 = qcdr(v0103);
    v0104 = stack[-1];
    v0103 = stack[0];
    v0103 = CC_remchkf(env, 3, v0027, v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    {
        Lisp_Object v0033 = stack[-2];
        popv(5);
        return cons(v0033, v0103);
    }

v0048:
    v0104 = stack[-2];
    v0103 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* kernels1 */
    v0104 = (*qfn2(fn))(qenv(fn), v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-4];
    v0103 = stack[0];
    fn = elt(env, 5); /* intersection */
    v0103 = (*qfn2(fn))(qenv(fn), v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-4];
    v0103 = (v0103 == nil ? lisp_true : nil);
    goto v0004;

v0109:
    v0103 = qvalue(elt(env, 1)); /* t */
    goto v0113;
/* error exit handlers */
v0118:
    popv(5);
    return nil;
}



/* Code for derivative!-mod!-p!-1 */

static Lisp_Object CC_derivativeKmodKpK1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0159, v0211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for derivative-mod-p-1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    v0159 = stack[-2];
    if (!consp(v0159)) goto v0020;
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    v0159 = (consp(v0159) ? nil : lisp_true);
    goto v0021;

v0021:
    if (v0159 == nil) goto v0022;
    v0159 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0159); }

v0022:
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    v0211 = qcar(v0159);
    v0159 = stack[-1];
    if (equal(v0211, v0159)) goto v0110;
    v0159 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0159); }

v0110:
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    v0211 = qcdr(v0159);
    v0159 = (Lisp_Object)17; /* 1 */
    if (v0211 == v0159) goto v0037;
    v0159 = stack[-1];
    fn = elt(env, 3); /* fkern */
    v0211 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-4];
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    v0159 = qcdr(v0159);
    v0159 = (Lisp_Object)((int32_t)(v0159) - 0x10);
    fn = elt(env, 4); /* getpower */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0211, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-4];
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    v0211 = qcdr(v0159);
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    v0159 = qcdr(v0159);
    v0159 = Lmodular_number(nil, v0159);
    env = stack[-4];
    fn = elt(env, 5); /* multiply!-by!-constant!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v0211, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-4];
    v0159 = stack[-2];
    v0211 = qcdr(v0159);
    v0159 = stack[-1];
    v0159 = CC_derivativeKmodKpK1(env, v0211, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-4];
    {
        Lisp_Object v0121 = stack[-3];
        Lisp_Object v0076 = stack[0];
        popv(5);
        fn = elt(env, 6); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0121, v0076, v0159);
    }

v0037:
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    v0159 = qcdr(v0159);
    { popv(5); return onevalue(v0159); }

v0020:
    v0159 = qvalue(elt(env, 1)); /* t */
    goto v0021;
/* error exit handlers */
v0157:
    popv(5);
    return nil;
}



/* Code for giplus!: */

static Lisp_Object CC_giplusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giplus:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = elt(env, 1); /* !:gi!: */
    v0005 = stack[-2];
    v0005 = qcdr(v0005);
    v0006 = qcar(v0005);
    v0005 = stack[-1];
    v0005 = qcdr(v0005);
    v0005 = qcar(v0005);
    stack[0] = plus2(v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-4];
    v0005 = stack[-2];
    v0005 = qcdr(v0005);
    v0006 = qcdr(v0005);
    v0005 = stack[-1];
    v0005 = qcdr(v0005);
    v0005 = qcdr(v0005);
    v0005 = plus2(v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    {
        Lisp_Object v0010 = stack[-3];
        Lisp_Object v0041 = stack[0];
        popv(5);
        return list2star(v0010, v0041, v0005);
    }
/* error exit handlers */
v0048:
    popv(5);
    return nil;
}



/* Code for mk!+trace */

static Lisp_Object CC_mkLtrace(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0027, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+trace");
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
    v0104 = stack[-1];
    fn = elt(env, 6); /* squared!+matrix!+p */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    if (!(v0104 == nil)) goto v0109;
    v0104 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0104 == nil)) goto v0083;
    v0104 = elt(env, 2); /* "no square matrix in add" */
    fn = elt(env, 7); /* lprie */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    goto v0083;

v0083:
    v0104 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    goto v0109;

v0109:
    v0027 = qvalue(elt(env, 3)); /* nil */
    v0104 = (Lisp_Object)17; /* 1 */
    v0104 = cons(v0027, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    stack[0] = v0104;
    v0104 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0104;
    goto v0112;

v0112:
    v0104 = stack[-1];
    fn = elt(env, 8); /* get!+row!+nr */
    v0027 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0104 = stack[-2];
    v0104 = difference2(v0027, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0104 = Lminusp(nil, v0104);
    env = stack[-3];
    if (v0104 == nil) goto v0111;
    v0104 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v0104; /* !*sub2 */
    v0104 = stack[0];
    fn = elt(env, 9); /* subs2 */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    stack[0] = v0104;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v0111:
    v0026 = stack[-1];
    v0027 = stack[-2];
    v0104 = stack[-2];
    fn = elt(env, 10); /* get!+mat!+entry */
    v0104 = (*qfnn(fn))(qenv(fn), 3, v0026, v0027, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    fn = elt(env, 11); /* addsq */
    v0104 = (*qfn2(fn))(qenv(fn), stack[0], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    stack[0] = v0104;
    v0104 = stack[-2];
    v0104 = add1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    stack[-2] = v0104;
    goto v0112;
/* error exit handlers */
v0033:
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(4);
    return nil;
v0118:
    popv(4);
    return nil;
}



/* Code for pasf_zcong */

static Lisp_Object CC_pasf_zcong(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0192, v0227;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_zcong");
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
    v0192 = v0000;
/* end of prologue */
    v0137 = v0192;
    v0137 = Lconsp(nil, v0137);
    env = stack[0];
    if (v0137 == nil) { popv(1); return onevalue(v0192); }
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0137 = Lconsp(nil, v0137);
    env = stack[0];
    if (v0137 == nil) { popv(1); return onevalue(v0192); }
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0227 = qcar(v0137);
    v0137 = elt(env, 1); /* (cong ncong) */
    v0137 = Lmemq(nil, v0227, v0137);
    if (v0137 == nil) { popv(1); return onevalue(v0192); }
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0137 = qcdr(v0137);
    if (v0137 == nil) goto v0119;
    v0137 = v0192;
    v0137 = qcdr(v0137);
    v0137 = qcar(v0137);
    if (v0137 == nil) goto v0228;
    v0137 = qvalue(elt(env, 8)); /* nil */
    goto v0121;

v0121:
    if (v0137 == nil) goto v0213;
    v0137 = elt(env, 2); /* true */
    { popv(1); return onevalue(v0137); }

v0213:
    v0137 = v0192;
    v0137 = qcdr(v0137);
    v0137 = qcar(v0137);
    if (v0137 == nil) goto v0183;
    v0137 = qvalue(elt(env, 8)); /* nil */
    goto v0080;

v0080:
    if (v0137 == nil) { popv(1); return onevalue(v0192); }
    v0137 = elt(env, 4); /* false */
    { popv(1); return onevalue(v0137); }

v0183:
    v0227 = v0192;
    v0137 = elt(env, 2); /* true */
    if (v0227 == v0137) goto v0184;
    v0227 = v0192;
    v0137 = elt(env, 4); /* false */
    v0137 = (v0227 == v0137 ? lisp_true : nil);
    goto v0171;

v0171:
    if (v0137 == nil) goto v0163;
    v0137 = v0192;
    v0227 = v0137;
    goto v0086;

v0086:
    v0137 = elt(env, 9); /* ncong */
    v0137 = (v0227 == v0137 ? lisp_true : nil);
    goto v0080;

v0163:
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0137 = Lconsp(nil, v0137);
    env = stack[0];
    if (v0137 == nil) goto v0229;
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0137 = qcar(v0137);
    v0227 = v0137;
    goto v0086;

v0229:
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0227 = v0137;
    goto v0086;

v0184:
    v0137 = qvalue(elt(env, 3)); /* t */
    goto v0171;

v0228:
    v0227 = v0192;
    v0137 = elt(env, 2); /* true */
    if (v0227 == v0137) goto v0096;
    v0227 = v0192;
    v0137 = elt(env, 4); /* false */
    v0137 = (v0227 == v0137 ? lisp_true : nil);
    goto v0099;

v0099:
    if (v0137 == nil) goto v0216;
    v0137 = v0192;
    v0227 = v0137;
    goto v0201;

v0201:
    v0137 = elt(env, 5); /* cong */
    v0137 = (v0227 == v0137 ? lisp_true : nil);
    goto v0121;

v0216:
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0137 = Lconsp(nil, v0137);
    env = stack[0];
    if (v0137 == nil) goto v0230;
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0137 = qcar(v0137);
    v0227 = v0137;
    goto v0201;

v0230:
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0227 = v0137;
    goto v0201;

v0096:
    v0137 = qvalue(elt(env, 3)); /* t */
    goto v0099;

v0119:
    v0227 = v0192;
    v0137 = elt(env, 2); /* true */
    if (v0227 == v0137) goto v0051;
    v0227 = v0192;
    v0137 = elt(env, 4); /* false */
    v0137 = (v0227 == v0137 ? lisp_true : nil);
    goto v0039;

v0039:
    if (v0137 == nil) goto v0015;
    v0137 = v0192;
    v0227 = v0137;
    goto v0045;

v0045:
    v0137 = elt(env, 5); /* cong */
    if (v0227 == v0137) goto v0048;
    v0137 = elt(env, 7); /* neq */
    goto v0114;

v0114:
    v0192 = qcdr(v0192);
    v0192 = qcar(v0192);
    v0227 = qvalue(elt(env, 8)); /* nil */
    popv(1);
    return list3(v0137, v0192, v0227);

v0048:
    v0137 = elt(env, 6); /* equal */
    goto v0114;

v0015:
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0137 = Lconsp(nil, v0137);
    env = stack[0];
    if (v0137 == nil) goto v0210;
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0137 = qcar(v0137);
    v0227 = v0137;
    goto v0045;

v0210:
    v0137 = v0192;
    v0137 = qcar(v0137);
    v0227 = v0137;
    goto v0045;

v0051:
    v0137 = qvalue(elt(env, 3)); /* t */
    goto v0039;
}



/* Code for ratpoly_quot */

static Lisp_Object CC_ratpoly_quot(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_quot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0035 = v0009;
    v0094 = v0000;
/* end of prologue */
    stack[0] = v0094;
    fn = elt(env, 1); /* invsq */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-1];
    {
        Lisp_Object v0047 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0047, v0035);
    }
/* error exit handlers */
v0083:
    popv(2);
    return nil;
}



/* Code for i2cr!* */

static Lisp_Object CC_i2crH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2cr*");
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
    v0050 = v0000;
/* end of prologue */
    fn = elt(env, 3); /* chkint!* */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[0];
    v0022 = v0050;
    if (!consp(v0050)) goto v0094;
    v0050 = qvalue(elt(env, 2)); /* bfz!* */
    goto v0021;

v0021:
    {
        popv(1);
        fn = elt(env, 4); /* mkcr */
        return (*qfn2(fn))(qenv(fn), v0022, v0050);
    }

v0094:
    v0050 = elt(env, 1); /* 0.0 */
    goto v0021;
/* error exit handlers */
v0113:
    popv(1);
    return nil;
}



/* Code for wedgef */

static Lisp_Object CC_wedgef(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0240, v0207, v0241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgef");
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
    v0240 = stack[-1];
    fn = elt(env, 8); /* dim!<deg */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    if (v0240 == nil) goto v0035;
    v0240 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0240); }

v0035:
    v0240 = stack[-1];
    v0207 = qcar(v0240);
    v0240 = elt(env, 2); /* hodge */
    if (!consp(v0207)) goto v0217;
    v0207 = qcar(v0207);
    if (!(v0207 == v0240)) goto v0217;
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    v0240 = qcdr(v0240);
    v0240 = qcar(v0240);
    fn = elt(env, 9); /* deg!*form */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    stack[-2] = v0240;
    stack[0] = stack[-2];
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    fn = elt(env, 10); /* deg!*farg */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    if (equal(stack[0], v0240)) goto v0011;
    v0240 = stack[-1];
    {
        popv(4);
        fn = elt(env, 11); /* mkwedge */
        return (*qfn1(fn))(qenv(fn), v0240);
    }

v0011:
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    v0240 = qcdr(v0240);
    v0241 = qcar(v0240);
    v0207 = (Lisp_Object)17; /* 1 */
    v0240 = (Lisp_Object)17; /* 1 */
    v0240 = list2star(v0241, v0207, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    stack[0] = ncons(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    v0240 = qcdr(v0240);
    if (v0240 == nil) goto v0033;
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    fn = elt(env, 12); /* mkuniquewedge1 */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    goto v0040;

v0040:
    fn = elt(env, 13); /* hodgepf */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    fn = elt(env, 14); /* mkunarywedge */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    fn = elt(env, 15); /* wedgepf2 */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    stack[0] = stack[-2];
    v0240 = qvalue(elt(env, 3)); /* dimex!* */
    fn = elt(env, 16); /* negf */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    fn = elt(env, 17); /* addf */
    v0240 = (*qfn2(fn))(qenv(fn), stack[-2], v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    fn = elt(env, 18); /* multf */
    v0240 = (*qfn2(fn))(qenv(fn), stack[0], v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    fn = elt(env, 19); /* mksgnsq */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    {
        Lisp_Object v0164 = stack[-1];
        popv(4);
        fn = elt(env, 20); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0164, v0240);
    }

v0033:
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    v0241 = qcar(v0240);
    v0207 = (Lisp_Object)17; /* 1 */
    v0240 = (Lisp_Object)17; /* 1 */
    v0240 = list2star(v0241, v0207, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    v0240 = ncons(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    goto v0040;

v0217:
    v0240 = stack[-1];
    v0207 = qcar(v0240);
    v0240 = elt(env, 4); /* d */
    if (!consp(v0207)) goto v0077;
    v0207 = qcar(v0207);
    if (!(v0207 == v0240)) goto v0077;
    v0207 = elt(env, 4); /* d */
    v0240 = elt(env, 5); /* noxpnd */
    v0240 = Lflagp(nil, v0207, v0240);
    env = stack[-3];
    if (v0240 == nil) goto v0230;
    v0240 = qvalue(elt(env, 6)); /* t */
    goto v0097;

v0097:
    if (v0240 == nil) goto v0130;
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    v0240 = qcdr(v0240);
    v0207 = qcar(v0240);
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    v0240 = cons(v0207, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    fn = elt(env, 21); /* dwedge */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    fn = elt(env, 14); /* mkunarywedge */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    v0240 = qcdr(v0240);
    v0241 = qcar(v0240);
    v0207 = (Lisp_Object)17; /* 1 */
    v0240 = (Lisp_Object)17; /* 1 */
    v0240 = list2star(v0241, v0207, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    stack[0] = ncons(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    v0240 = qcdr(v0240);
    if (v0240 == nil) goto v0242;
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    fn = elt(env, 21); /* dwedge */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    goto v0243;

v0243:
    fn = elt(env, 14); /* mkunarywedge */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    fn = elt(env, 15); /* wedgepf2 */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    v0240 = qcdr(v0240);
    v0240 = qcar(v0240);
    fn = elt(env, 9); /* deg!*form */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    fn = elt(env, 19); /* mksgnsq */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    stack[-1] = v0240;
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    fn = elt(env, 16); /* negf */
    v0207 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    v0240 = cons(v0207, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    fn = elt(env, 20); /* multpfsq */
    v0240 = (*qfn2(fn))(qenv(fn), stack[0], v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    {
        Lisp_Object v0244 = stack[-2];
        popv(4);
        fn = elt(env, 22); /* addpf */
        return (*qfn2(fn))(qenv(fn), v0244, v0240);
    }

v0242:
    v0240 = stack[-1];
    v0240 = qcdr(v0240);
    v0240 = qcar(v0240);
    fn = elt(env, 23); /* exdfk */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    goto v0243;

v0130:
    v0240 = stack[-1];
    {
        popv(4);
        fn = elt(env, 11); /* mkwedge */
        return (*qfn1(fn))(qenv(fn), v0240);
    }

v0230:
    v0207 = qvalue(elt(env, 7)); /* lftshft!* */
    v0240 = stack[-1];
    v0240 = qcar(v0240);
    v0240 = qcdr(v0240);
    v0240 = qcar(v0240);
    fn = elt(env, 24); /* smemqlp */
    v0240 = (*qfn2(fn))(qenv(fn), v0207, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-3];
    goto v0097;

v0077:
    v0240 = qvalue(elt(env, 1)); /* nil */
    goto v0097;
/* error exit handlers */
v0165:
    popv(4);
    return nil;
}



setup_type const u27_setup[] =
{
    {"matrix_rows",             CC_matrix_rows, too_many_1,    wrong_no_1},
    {"degreef",                 too_few_2,      CC_degreef,    wrong_no_2},
    {"evgradlexcomp",           too_few_2,      CC_evgradlexcomp,wrong_no_2},
    {"fl2bf",                   CC_fl2bf,       too_many_1,    wrong_no_1},
    {"getphystypeall",          CC_getphystypeall,too_many_1,  wrong_no_1},
    {"calc_coeff",              too_few_2,      CC_calc_coeff, wrong_no_2},
    {"gvarlis1",                too_few_2,      CC_gvarlis1,   wrong_no_2},
    {"general-horner-rule-mod-p",wrong_no_na,   wrong_no_nb,   (n_args *)CC_generalKhornerKruleKmodKp},
    {"reduce-eival-powers",     too_few_2,      CC_reduceKeivalKpowers,wrong_no_2},
    {"get_char_value",          too_few_2,      CC_get_char_value,wrong_no_2},
    {"cl_smsimpl-junct",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct},
    {"aex_boundids",            CC_aex_boundids,too_many_1,    wrong_no_1},
    {"multiminus",              CC_multiminus,  too_many_1,    wrong_no_1},
    {"groebbuchcrit4t",         too_few_2,      CC_groebbuchcrit4t,wrong_no_2},
    {"r2speclist1",             CC_r2speclist1, too_many_1,    wrong_no_1},
    {"apply_e",                 CC_apply_e,     too_many_1,    wrong_no_1},
    {"indxsymp",                too_few_2,      CC_indxsymp,   wrong_no_2},
    {"find_buble",              too_few_2,      CC_find_buble, wrong_no_2},
    {"innprodpex",              too_few_2,      CC_innprodpex, wrong_no_2},
    {"simp-prop-condense",      CC_simpKpropKcondense,too_many_1,wrong_no_1},
    {"lambda_mcd3py_6",         too_few_2,      CC_lambda_mcd3py_6,wrong_no_2},
    {"pcdiv",                   too_few_2,      CC_pcdiv,      wrong_no_2},
    {"bfrsq",                   CC_bfrsq,       too_many_1,    wrong_no_1},
    {"normalform",              too_few_2,      CC_normalform, wrong_no_2},
    {"ofsf_evalatp",            too_few_2,      CC_ofsf_evalatp,wrong_no_2},
    {"orddf",                   too_few_2,      CC_orddf,      wrong_no_2},
    {"mk+outer+list",           CC_mkLouterLlist,too_many_1,   wrong_no_1},
    {"mri_prepat",              CC_mri_prepat,  too_many_1,    wrong_no_1},
    {"pasf_subfof",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_subfof},
    {"minusml",                 CC_minusml,     too_many_1,    wrong_no_1},
    {"multerm",                 too_few_2,      CC_multerm,    wrong_no_2},
    {"band_matrix",             too_few_2,      CC_band_matrix,wrong_no_2},
    {"genexp",                  CC_genexp,      too_many_1,    wrong_no_1},
    {"lchk",                    CC_lchk,        too_many_1,    wrong_no_1},
    {"rd:difference",           too_few_2,      CC_rdTdifference,wrong_no_2},
    {"aceq",                    too_few_2,      CC_aceq,       wrong_no_2},
    {"lispreadp",               CC_lispreadp,   too_many_1,    wrong_no_1},
    {"reval3",                  CC_reval3,      too_many_1,    wrong_no_1},
    {"incident",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_incident},
    {"innprodp2",               too_few_2,      CC_innprodp2,  wrong_no_2},
    {"matop_pseudomod",         too_few_2,      CC_matop_pseudomod,wrong_no_2},
    {"nf",                      wrong_no_na,    wrong_no_nb,   (n_args *)CC_nf},
    {"ad_splitname",            CC_ad_splitname,too_many_1,    wrong_no_1},
    {"multdfconst",             too_few_2,      CC_multdfconst,wrong_no_2},
    {"ofsf_facequal*",          too_few_2,      CC_ofsf_facequalH,wrong_no_2},
    {"aex_freeids",             CC_aex_freeids, too_many_1,    wrong_no_1},
    {"crn:prep",                CC_crnTprep,    too_many_1,    wrong_no_1},
    {"on-double1",              CC_onKdouble1,  too_many_1,    wrong_no_1},
    {"evmtest?",                too_few_2,      CC_evmtestW,   wrong_no_2},
    {"vdpcondense",             CC_vdpcondense, too_many_1,    wrong_no_1},
    {"gpargp",                  CC_gpargp,      too_many_1,    wrong_no_1},
    {"*pf2sq",                  CC_Hpf2sq,      too_many_1,    wrong_no_1},
    {"mo_2a",                   CC_mo_2a,       too_many_1,    wrong_no_1},
    {"lpos",                    too_few_2,      CC_lpos,       wrong_no_2},
    {"lessppair",               too_few_2,      CC_lessppair,  wrong_no_2},
    {"sfto_lmultf",             CC_sfto_lmultf, too_many_1,    wrong_no_1},
    {"my+nullsq+p",             CC_myLnullsqLp, too_many_1,    wrong_no_1},
    {"depend-f",                too_few_2,      CC_dependKf,   wrong_no_2},
    {"cl_bnfsimpl",             too_few_2,      CC_cl_bnfsimpl,wrong_no_2},
    {"vdp_make",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdp_make},
    {"containerml",             too_few_2,      CC_containerml,wrong_no_2},
    {"findnthroot",             CC_findnthroot, too_many_1,    wrong_no_1},
    {"difference:",             too_few_2,      CC_differenceT,wrong_no_2},
    {"prop-simp2",              too_few_2,      CC_propKsimp2, wrong_no_2},
    {"remchkf",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_remchkf},
    {"derivative-mod-p-1",      too_few_2,      CC_derivativeKmodKpK1,wrong_no_2},
    {"giplus:",                 too_few_2,      CC_giplusT,    wrong_no_2},
    {"mk+trace",                CC_mkLtrace,    too_many_1,    wrong_no_1},
    {"pasf_zcong",              CC_pasf_zcong,  too_many_1,    wrong_no_1},
    {"ratpoly_quot",            too_few_2,      CC_ratpoly_quot,wrong_no_2},
    {"i2cr*",                   CC_i2crH,       too_many_1,    wrong_no_1},
    {"wedgef",                  CC_wedgef,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u27", (two_args *)"17304 6277855 1337197", 0}
};

/* end of generated code */
