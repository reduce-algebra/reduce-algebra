
/* $destdir\u27.c        Machine generated C code */

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


/* Code for ad_splitname */

static Lisp_Object CC_ad_splitname(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ad_splitname");
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
    v8 = v0;
/* end of prologue */
    v7 = v8;
    if (symbolp(v7)) goto v9;
    v7 = nil;
    { popv(3); return onevalue(v7); }

v9:
    stack[0] = nil;
    v7 = v8;
    v7 = Lexplode(nil, v7);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    v7 = Lreverse(nil, v7);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    stack[-1] = v7;
    goto v11;

v11:
    v7 = stack[-1];
    if (v7 == nil) goto v12;
    v7 = stack[-1];
    v7 = qcar(v7);
    fn = elt(env, 2); /* charnump!: */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    if (v7 == nil) goto v12;
    v7 = stack[-1];
    v8 = qcar(v7);
    v7 = stack[0];
    v7 = cons(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    stack[0] = v7;
    v7 = stack[-1];
    v7 = qcdr(v7);
    stack[-1] = v7;
    goto v11;

v12:
    v7 = stack[-1];
    if (v7 == nil) goto v13;
    v7 = stack[-1];
    v7 = Lreverse(nil, v7);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    v7 = Lcompress(nil, v7);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    v7 = Lintern(nil, v7);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    stack[-1] = v7;
    goto v13;

v13:
    v7 = stack[0];
    if (v7 == nil) goto v14;
    v7 = stack[0];
    v7 = Lcompress(nil, v7);
    nil = C_nil;
    if (exception_pending()) goto v10;
    stack[0] = v7;
    goto v14;

v14:
    v8 = stack[-1];
    v7 = stack[0];
    popv(3);
    return cons(v8, v7);
/* error exit handlers */
v10:
    popv(3);
    return nil;
}



/* Code for bfrsq */

static Lisp_Object CC_bfrsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfrsq");
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
    v28 = v0;
/* end of prologue */
    v27 = v28;
    v27 = qcar(v27);
    v28 = qcdr(v28);
    stack[-1] = v28;
    v28 = v27;
    if (!consp(v28)) goto v29;
    v28 = v27;
    fn = elt(env, 1); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-2];
    v28 = stack[-1];
    v27 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-2];
    {
        Lisp_Object v7 = stack[0];
        popv(3);
        fn = elt(env, 2); /* plubf */
        return (*qfn2(fn))(qenv(fn), v7, v27);
    }

v29:
    v28 = v27;
    stack[0] = times2(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-2];
    v28 = stack[-1];
    v27 = stack[-1];
    v27 = times2(v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v1;
    {
        Lisp_Object v8 = stack[0];
        popv(3);
        return plus2(v8, v27);
    }
/* error exit handlers */
v1:
    popv(3);
    return nil;
}



/* Code for mri_prepat */

static Lisp_Object CC_mri_prepat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_prepat");
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
    v30 = v0;
/* end of prologue */
    fn = elt(env, 1); /* mri_2pasfat */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* pasf_prepat */
        return (*qfn1(fn))(qenv(fn), v30);
    }
/* error exit handlers */
v20:
    popv(1);
    return nil;
}



/* Code for aex_boundids */

static Lisp_Object CC_aex_boundids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_boundids");
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
    v32 = stack[0];
    fn = elt(env, 1); /* aex_ids */
    stack[-1] = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    v32 = stack[0];
    fn = elt(env, 2); /* aex_ctx */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    fn = elt(env, 3); /* ctx_idl */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    {
        Lisp_Object v33 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* intersection */
        return (*qfn2(fn))(qenv(fn), v33, v32);
    }
/* error exit handlers */
v11:
    popv(3);
    return nil;
}



/* Code for crn!:prep */

static Lisp_Object CC_crnTprep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:prep");
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
    v25 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !:rn!: */
    v26 = v25;
    v26 = qcdr(v26);
    stack[0] = qcar(v26);
    v26 = elt(env, 1); /* !:rn!: */
    v25 = qcdr(v25);
    v25 = qcdr(v25);
    v25 = cons(v26, v25);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    v25 = acons(stack[-1], stack[0], v25);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 2); /* crnprep1 */
        return (*qfn1(fn))(qenv(fn), v25);
    }
/* error exit handlers */
v38:
    popv(3);
    return nil;
}



/* Code for look_for_substitute */

static Lisp_Object MS_CDECL CC_look_for_substitute(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v39,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v51, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "look_for_substitute");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for look_for_substitute");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v39,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v40;
    stack[-1] = v39;
    stack[-2] = v0;
/* end of prologue */

v53:
    v50 = stack[0];
    if (!consp(v50)) goto v54;
    v52 = stack[-2];
    v51 = stack[-1];
    v50 = stack[0];
    fn = elt(env, 2); /* look_for_rational */
    v50 = (*qfnn(fn))(qenv(fn), 3, v52, v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v51 = v50;
    if (!(v50 == nil)) { popv(4); return onevalue(v51); }
    v52 = stack[-2];
    v51 = stack[-1];
    v50 = stack[0];
    fn = elt(env, 3); /* look_for_quad */
    v50 = (*qfnn(fn))(qenv(fn), 3, v52, v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v51 = v50;
    if (!(v50 == nil)) { popv(4); return onevalue(v51); }
    v52 = stack[-2];
    v51 = stack[-1];
    v50 = stack[0];
    v50 = qcar(v50);
    v50 = CC_look_for_substitute(env, 3, v52, v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v51 = v50;
    if (!(v50 == nil)) { popv(4); return onevalue(v51); }
    v52 = stack[-2];
    v51 = stack[-1];
    v50 = stack[0];
    v50 = qcdr(v50);
    stack[-2] = v52;
    stack[-1] = v51;
    stack[0] = v50;
    goto v53;

v54:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v50); }
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for band_matrix */

static Lisp_Object CC_band_matrix(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for band_matrix");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v39;
    stack[-9] = v0;
/* end of prologue */
    stack[-10] = nil;
    v94 = stack[-8];
    v94 = integerp(v94);
    if (!(v94 == nil)) goto v12;
    v94 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v94 == nil)) goto v46;
    v94 = elt(env, 2); /* "Error in band_matrix(second argument): should be an integer." 
*/
    fn = elt(env, 9); /* lprie */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    goto v46;

v46:
    v94 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    goto v12;

v12:
    v94 = stack[-9];
    if (!consp(v94)) goto v97;
    v94 = stack[-9];
    v95 = qcar(v94);
    v94 = elt(env, 3); /* list */
    if (v95 == v94) goto v45;
    v94 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v94 == nil)) goto v42;
    v94 = elt(env, 4); /* "Error in band_matrix(first argument): should be single value or list." 
*/
    fn = elt(env, 9); /* lprie */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    goto v42;

v42:
    v94 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    goto v98;

v98:
    v94 = stack[-9];
    v94 = Llength(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    stack[-7] = v94;
    v94 = stack[-7];
    v94 = Levenp(nil, v94);
    env = stack[-11];
    if (v94 == nil) goto v99;
    v94 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v94 == nil)) goto v52;
    v94 = elt(env, 5); /* "Error in band matrix(first argument): number of elements must be odd." 
*/
    fn = elt(env, 9); /* lprie */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    goto v52;

v52:
    v94 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    goto v99;

v99:
    stack[0] = elt(env, 6); /* quotient */
    v94 = stack[-7];
    v95 = add1(v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    v94 = (Lisp_Object)33; /* 2 */
    v94 = list3(stack[0], v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    fn = elt(env, 10); /* reval */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    stack[-6] = v94;
    v94 = stack[-6];
    v94 = integerp(v94);
    if (v94 == nil) goto v100;
    v94 = stack[-6];
    v95 = v94;
    goto v101;

v101:
    v94 = stack[-8];
    v94 = (Lisp_Object)greaterp2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    v94 = v94 ? lisp_true : nil;
    env = stack[-11];
    if (v94 == nil) goto v102;
    v94 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v94 == nil)) goto v103;
    v94 = elt(env, 7); /* "Error in band_matrix: too many elements. Band matrix is overflowing." 
*/
    fn = elt(env, 9); /* lprie */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    goto v103;

v103:
    v94 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    goto v104;

v104:
    v94 = (Lisp_Object)17; /* 1 */
    stack[-5] = v94;
    goto v105;

v105:
    v95 = stack[-8];
    v94 = stack[-5];
    v94 = difference2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    v94 = Lminusp(nil, v94);
    env = stack[-11];
    if (!(v94 == nil)) { Lisp_Object res = stack[-10]; popv(12); return onevalue(res); }
    v94 = (Lisp_Object)17; /* 1 */
    stack[-4] = v94;
    goto v106;

v106:
    v95 = stack[-8];
    v94 = stack[-4];
    v94 = difference2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    v94 = Lminusp(nil, v94);
    env = stack[-11];
    if (v94 == nil) goto v107;
    v94 = stack[-5];
    v94 = add1(v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    stack[-5] = v94;
    goto v105;

v107:
    v95 = stack[-6];
    v94 = stack[-5];
    v95 = difference2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    v94 = stack[-4];
    v95 = plus2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    v94 = (Lisp_Object)1; /* 0 */
    v94 = (Lisp_Object)greaterp2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    v94 = v94 ? lisp_true : nil;
    env = stack[-11];
    if (v94 == nil) goto v108;
    v95 = stack[-6];
    v94 = stack[-5];
    v95 = difference2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    v94 = stack[-4];
    v95 = plus2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    v94 = stack[-7];
    v94 = (Lisp_Object)lesseq2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    v94 = v94 ? lisp_true : nil;
    env = stack[-11];
    if (v94 == nil) goto v108;
    stack[-3] = stack[-10];
    stack[-2] = stack[-5];
    stack[-1] = stack[-4];
    stack[0] = stack[-9];
    v95 = stack[-6];
    v94 = stack[-5];
    v95 = difference2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    v94 = stack[-4];
    v94 = plus2(v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    fn = elt(env, 11); /* pnth */
    v94 = (*qfn2(fn))(qenv(fn), stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    v94 = qcar(v94);
    fn = elt(env, 12); /* setmat */
    v94 = (*qfnn(fn))(qenv(fn), 4, stack[-3], stack[-2], stack[-1], v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    goto v108;

v108:
    v94 = stack[-4];
    v94 = add1(v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    stack[-4] = v94;
    goto v106;

v102:
    v95 = stack[-8];
    v94 = stack[-8];
    fn = elt(env, 13); /* mkmatrix */
    v94 = (*qfn2(fn))(qenv(fn), v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    stack[-10] = v94;
    goto v104;

v100:
    v94 = stack[-6];
    fn = elt(env, 10); /* reval */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    v95 = v94;
    goto v101;

v45:
    v94 = stack[-9];
    v94 = qcdr(v94);
    stack[-9] = v94;
    goto v98;

v97:
    v94 = stack[-9];
    v94 = ncons(v94);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-11];
    stack[-9] = v94;
    goto v98;
/* error exit handlers */
v96:
    popv(12);
    return nil;
}



/* Code for genexp */

static Lisp_Object CC_genexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for genexp");
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

v53:
    v29 = stack[0];
    if (!consp(v29)) goto v9;
    v29 = stack[0];
    v29 = qcar(v29);
    v29 = CC_genexp(env, v29);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    if (!(v29 == nil)) { popv(2); return onevalue(v29); }
    v29 = stack[0];
    v29 = qcdr(v29);
    stack[0] = v29;
    goto v53;

v9:
    v29 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* genp */
        return (*qfn1(fn))(qenv(fn), v29);
    }
/* error exit handlers */
v109:
    popv(2);
    return nil;
}



/* Code for vdpcondense */

static Lisp_Object CC_vdpcondense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpcondense");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v3 = qcdr(v3);
    v3 = qcdr(v3);
    v3 = qcdr(v3);
    v3 = qcar(v3);
    {
        fn = elt(env, 1); /* dipcondense */
        return (*qfn1(fn))(qenv(fn), v3);
    }
}



/* Code for r2speclist1 */

static Lisp_Object CC_r2speclist1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v113, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2speclist1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v92 = v15;
    v113 = elt(env, 1); /* times */
    if (!consp(v92)) goto v6;
    v92 = qcar(v92);
    if (!(v92 == v113)) goto v6;
    v113 = v15;
    v113 = qcdr(v113);
    v92 = qcar(v113);
    v113 = v15;
    v113 = qcdr(v113);
    v113 = qcdr(v113);
    v113 = qcar(v113);
    v15 = qcdr(v15);
    v15 = qcdr(v15);
    v15 = qcdr(v15);
    {
        fn = elt(env, 2); /* r2speclist2 */
        return (*qfnn(fn))(qenv(fn), 3, v92, v113, v15);
    }

v6:
    v113 = (Lisp_Object)17; /* 1 */
    return cons(v113, v15);
}



/* Code for !*pf2sq */

static Lisp_Object CC_Hpf2sq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v120, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *pf2sq");
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
    v120 = qvalue(elt(env, 1)); /* nil */
    v104 = (Lisp_Object)17; /* 1 */
    v104 = cons(v120, v104);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    stack[-1] = v104;
    v104 = stack[0];
    if (v104 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v104 = stack[0];
    stack[0] = v104;
    goto v109;

v109:
    v104 = stack[0];
    if (v104 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v104 = stack[0];
    v104 = qcar(v104);
    v120 = qcar(v104);
    v104 = (Lisp_Object)17; /* 1 */
    if (v120 == v104) goto v123;
    v104 = stack[0];
    v104 = qcar(v104);
    v121 = qcar(v104);
    v120 = (Lisp_Object)17; /* 1 */
    v104 = (Lisp_Object)17; /* 1 */
    v104 = acons(v121, v120, v104);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v120 = ncons(v104);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v104 = (Lisp_Object)17; /* 1 */
    v104 = cons(v120, v104);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v120 = v104;
    goto v44;

v44:
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = qcdr(v104);
    fn = elt(env, 2); /* multsq */
    v120 = (*qfn2(fn))(qenv(fn), v120, v104);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v104 = stack[-1];
    fn = elt(env, 3); /* addsq */
    v104 = (*qfn2(fn))(qenv(fn), v120, v104);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    stack[-1] = v104;
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[0] = v104;
    goto v109;

v123:
    v120 = (Lisp_Object)17; /* 1 */
    v104 = (Lisp_Object)17; /* 1 */
    v104 = cons(v120, v104);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v120 = v104;
    goto v44;
/* error exit handlers */
v122:
    popv(3);
    return nil;
}



/* Code for incident */

static Lisp_Object MS_CDECL CC_incident(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v39,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v124, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "incident");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for incident");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v39,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v40;
    stack[0] = v39;
    stack[-2] = v0;
/* end of prologue */

v53:
    v42 = stack[0];
    if (v42 == nil) goto v20;
    v123 = stack[-2];
    v42 = stack[0];
    v124 = qcar(v42);
    v42 = stack[-1];
    fn = elt(env, 2); /* incident1 */
    v42 = (*qfnn(fn))(qenv(fn), 3, v123, v124, v42);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    v124 = v42;
    v42 = v124;
    if (v42 == nil) goto v113;
    v42 = stack[0];
    v42 = qcdr(v42);
    popv(4);
    return cons(v124, v42);

v113:
    v42 = stack[0];
    stack[0] = qcdr(v42);
    v42 = stack[-1];
    v42 = add1(v42);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    stack[-1] = v42;
    goto v53;

v20:
    v42 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v42); }
/* error exit handlers */
v28:
    popv(4);
    return nil;
}



/* Code for mo_2a */

static Lisp_Object CC_mo_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_2a");
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
    v112 = v0;
/* end of prologue */
    stack[0] = qcar(v112);
    v112 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 2); /* ring_all_names */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    {
        Lisp_Object v12 = stack[0];
        popv(2);
        fn = elt(env, 3); /* mo!=expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v12, v112);
    }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for ofsf_ignshift */

static Lisp_Object CC_ofsf_ignshift(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v126, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ignshift");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v39;
    stack[-1] = v0;
/* end of prologue */
    v114 = stack[-1];
    v114 = qcdr(v114);
    v126 = qcar(v114);
    v114 = stack[0];
    fn = elt(env, 7); /* sfto_reorder */
    v114 = (*qfn2(fn))(qenv(fn), v126, v114);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    v127 = v114;
    v114 = v127;
    if (!consp(v114)) goto v26;
    v114 = v127;
    v114 = qcar(v114);
    v114 = (consp(v114) ? nil : lisp_true);
    goto v25;

v25:
    if (v114 == nil) goto v109;
    v114 = qvalue(elt(env, 2)); /* nil */
    goto v36;

v36:
    if (v114 == nil) goto v33;
    v114 = qvalue(elt(env, 3)); /* !*rlpos */
    if (!(v114 == nil)) goto v28;
    v114 = stack[-1];
    v126 = qcar(v114);
    v114 = elt(env, 4); /* (equal neq) */
    v114 = Lmemq(nil, v126, v114);
    if (!(v114 == nil)) goto v28;
    v114 = v127;
    v114 = qcar(v114);
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v114 = Levenp(nil, v114);
    env = stack[-2];
    if (!(v114 == nil)) goto v28;
    v114 = elt(env, 6); /* odd */
    { popv(3); return onevalue(v114); }

v28:
    v114 = elt(env, 5); /* ignore */
    { popv(3); return onevalue(v114); }

v33:
    v114 = nil;
    { popv(3); return onevalue(v114); }

v109:
    v114 = v127;
    v114 = qcdr(v114);
    if (v114 == nil) goto v13;
    v114 = qvalue(elt(env, 2)); /* nil */
    goto v36;

v13:
    v114 = v127;
    v114 = qcar(v114);
    v114 = qcar(v114);
    v126 = qcar(v114);
    v114 = stack[0];
    v114 = (v126 == v114 ? lisp_true : nil);
    goto v36;

v26:
    v114 = qvalue(elt(env, 1)); /* t */
    goto v25;
/* error exit handlers */
v128:
    popv(3);
    return nil;
}



/* Code for orddf */

static Lisp_Object CC_orddf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for orddf");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v39;
    stack[-1] = v0;
/* end of prologue */

v30:
    v27 = stack[-1];
    if (v27 == nil) goto v3;
    v27 = stack[0];
    if (v27 == nil) goto v109;
    v27 = stack[-1];
    v28 = qcar(v27);
    v27 = stack[0];
    v27 = qcar(v27);
    fn = elt(env, 6); /* exptcompare */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-2];
    if (v27 == nil) goto v15;
    v27 = qvalue(elt(env, 4)); /* t */
    { popv(3); return onevalue(v27); }

v15:
    v27 = stack[0];
    v28 = qcar(v27);
    v27 = stack[-1];
    v27 = qcar(v27);
    fn = elt(env, 6); /* exptcompare */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-2];
    if (v27 == nil) goto v119;
    v27 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v27); }

v119:
    v27 = stack[-1];
    v27 = qcdr(v27);
    stack[-1] = v27;
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[0] = v27;
    goto v30;

v109:
    v27 = elt(env, 3); /* "Orddf u longer than v" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v27);
    }

v3:
    v27 = stack[0];
    if (v27 == nil) goto v32;
    v27 = elt(env, 2); /* "Orddf v longer than u" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v27);
    }

v32:
    v27 = elt(env, 1); /* "Orddf = case" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v27);
    }
/* error exit handlers */
v1:
    popv(3);
    return nil;
}



/* Code for my!+nullsq!+p */

static Lisp_Object CC_myLnullsqLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my+nullsq+p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v0;
/* end of prologue */
    v35 = qcar(v35);
    if (v35 == nil) goto v20;
    v35 = nil;
    return onevalue(v35);

v20:
    v35 = qvalue(elt(env, 1)); /* t */
    return onevalue(v35);
}



/* Code for aex_freeids */

static Lisp_Object CC_aex_freeids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_freeids");
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
    v34 = stack[0];
    fn = elt(env, 1); /* aex_ex */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-2];
    fn = elt(env, 2); /* ratpoly_idl */
    stack[-1] = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-2];
    v34 = stack[0];
    fn = elt(env, 3); /* aex_ctx */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-2];
    fn = elt(env, 4); /* ctx_idl */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-2];
    {
        Lisp_Object v129 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* lto_setminus */
        return (*qfn2(fn))(qenv(fn), v129, v34);
    }
/* error exit handlers */
v33:
    popv(3);
    return nil;
}



/* Code for containerml */

static Lisp_Object CC_containerml(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for containerml");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v39;
    stack[-1] = v0;
/* end of prologue */
    v113 = stack[0];
    v15 = elt(env, 1); /* integer_interval */
    if (!(v113 == v15)) goto v20;
    v15 = elt(env, 2); /* interval */
    stack[0] = v15;
    goto v20;

v20:
    v15 = elt(env, 3); /* "<" */
    fn = elt(env, 9); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v15 = stack[0];
    v15 = Lprinc(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v15 = stack[-1];
    v113 = qcar(v15);
    v15 = elt(env, 4); /* "" */
    fn = elt(env, 10); /* attributesml */
    v15 = (*qfn2(fn))(qenv(fn), v113, v15);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v15 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 11); /* indent!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v15 = stack[-1];
    v15 = qcdr(v15);
    fn = elt(env, 12); /* multi_elem */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v15 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 11); /* indent!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v15 = elt(env, 7); /* "</" */
    fn = elt(env, 9); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v15 = stack[0];
    v15 = Lprinc(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v15 = elt(env, 8); /* ">" */
    v15 = Lprinc(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v130;
    v15 = nil;
    { popv(3); return onevalue(v15); }
/* error exit handlers */
v130:
    popv(3);
    return nil;
}



/* Code for on!-double1 */

static Lisp_Object CC_onKdouble1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for on-double1");
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

v9:
    v38 = stack[0];
    v38 = Lconsp(nil, v38);
    env = stack[-1];
    if (v38 == nil) goto v26;
    v38 = stack[0];
    v38 = qcar(v38);
    fn = elt(env, 3); /* doublep */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-1];
    if (v38 == nil) goto v22;
    v38 = lisp_true;
    qvalue(elt(env, 1)) = v38; /* !*double */
    { popv(2); return onevalue(v38); }

v22:
    v38 = stack[0];
    v38 = qcar(v38);
    v38 = CC_onKdouble1(env, v38);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-1];
    v38 = stack[0];
    v38 = qcdr(v38);
    stack[0] = v38;
    goto v9;

v26:
    v38 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v38); }
/* error exit handlers */
v98:
    popv(2);
    return nil;
}



/* Code for evmtest!? */

static Lisp_Object CC_evmtestW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44, v131, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evmtest?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v39;
    v131 = v0;
/* end of prologue */

v30:
    v43 = v131;
    if (v43 == nil) goto v24;
    v43 = v44;
    if (v43 == nil) goto v24;
    v43 = v131;
    v13 = qcar(v43);
    v43 = v44;
    v43 = qcar(v43);
    if (((int32_t)(v13)) < ((int32_t)(v43))) goto v98;
    v43 = v131;
    v43 = qcdr(v43);
    v131 = v43;
    v43 = v44;
    v43 = qcdr(v43);
    v44 = v43;
    goto v30;

v98:
    v43 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v43);

v24:
    v43 = v44;
    {
        fn = elt(env, 2); /* evzero!? */
        return (*qfn1(fn))(qenv(fn), v43);
    }
}



/* Code for extadd */

static Lisp_Object CC_extadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extadd");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v39;
    stack[-3] = v0;
/* end of prologue */
    v84 = stack[-3];
    if (v84 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v84 = stack[-2];
    if (v84 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v84 = qvalue(elt(env, 1)); /* nil */
    v84 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    stack[-1] = v84;
    stack[-4] = v84;
    goto v37;

v37:
    v84 = stack[-3];
    if (v84 == nil) goto v56;
    v84 = stack[-2];
    if (v84 == nil) goto v56;
    v84 = stack[-2];
    v84 = qcar(v84);
    v138 = qcar(v84);
    v84 = stack[-3];
    v84 = qcar(v84);
    v84 = qcar(v84);
    if (equal(v138, v84)) goto v42;
    v84 = stack[-2];
    v84 = qcar(v84);
    v138 = qcar(v84);
    v84 = stack[-3];
    v84 = qcar(v84);
    v84 = qcar(v84);
    fn = elt(env, 2); /* ordexp */
    v84 = (*qfn2(fn))(qenv(fn), v138, v84);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    if (v84 == nil) goto v140;
    stack[0] = stack[-1];
    v84 = stack[-2];
    v84 = qcar(v84);
    v84 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v84 = (*qfn2(fn))(qenv(fn), stack[0], v84);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    v84 = stack[-2];
    v84 = qcdr(v84);
    stack[-2] = v84;
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v37;

v140:
    stack[0] = stack[-1];
    v84 = stack[-3];
    v84 = qcar(v84);
    v84 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v84 = (*qfn2(fn))(qenv(fn), stack[0], v84);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    v84 = stack[-3];
    v84 = qcdr(v84);
    stack[-3] = v84;
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v37;

v42:
    v84 = stack[-3];
    v84 = qcar(v84);
    v138 = qcdr(v84);
    v84 = stack[-2];
    v84 = qcar(v84);
    v84 = qcdr(v84);
    fn = elt(env, 4); /* addf */
    v138 = (*qfn2(fn))(qenv(fn), v138, v84);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    v84 = v138;
    if (v138 == nil) goto v19;
    stack[0] = stack[-1];
    v138 = stack[-3];
    v138 = qcar(v138);
    v138 = qcar(v138);
    v84 = cons(v138, v84);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    v84 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v84 = (*qfn2(fn))(qenv(fn), stack[0], v84);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v19;

v19:
    v84 = stack[-3];
    v84 = qcdr(v84);
    stack[-3] = v84;
    v84 = stack[-2];
    v84 = qcdr(v84);
    stack[-2] = v84;
    goto v37;

v56:
    v138 = stack[-1];
    v84 = stack[-3];
    if (v84 == nil) goto v141;
    v84 = stack[-3];
    goto v142;

v142:
    fn = elt(env, 3); /* setcdr */
    v84 = (*qfn2(fn))(qenv(fn), v138, v84);
    nil = C_nil;
    if (exception_pending()) goto v139;
    v84 = stack[-4];
    v84 = qcdr(v84);
    { popv(6); return onevalue(v84); }

v141:
    v84 = stack[-2];
    goto v142;
/* error exit handlers */
v139:
    popv(6);
    return nil;
}



/* Code for ofsf_smcpknowl */

static Lisp_Object CC_ofsf_smcpknowl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smcpknowl");
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
    v143 = v0;
/* end of prologue */
    stack[-4] = v143;
    v143 = stack[-4];
    if (v143 == nil) goto v35;
    v143 = stack[-4];
    v143 = qcar(v143);
    v144 = v143;
    v143 = v144;
    stack[0] = qcar(v143);
    v143 = v144;
    v144 = qcdr(v143);
    v143 = qvalue(elt(env, 1)); /* nil */
    v143 = Lappend(nil, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v143 = cons(stack[0], v143);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    stack[-2] = v143;
    stack[-3] = v143;
    goto v4;

v4:
    v143 = stack[-4];
    v143 = qcdr(v143);
    stack[-4] = v143;
    v143 = stack[-4];
    if (v143 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v143 = stack[-4];
    v143 = qcar(v143);
    v144 = v143;
    v143 = v144;
    stack[0] = qcar(v143);
    v143 = v144;
    v144 = qcdr(v143);
    v143 = qvalue(elt(env, 1)); /* nil */
    v143 = Lappend(nil, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v143 = cons(stack[0], v143);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v143 = Lrplacd(nil, stack[-1], v143);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v143 = stack[-2];
    v143 = qcdr(v143);
    stack[-2] = v143;
    goto v4;

v35:
    v143 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v143); }
/* error exit handlers */
v99:
    popv(6);
    return nil;
}



/* Code for formboollis */

static Lisp_Object MS_CDECL CC_formboollis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v39,
                         Lisp_Object v40, Lisp_Object v68, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v2, v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "formboollis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formboollis");
#endif
    if (stack >= stacklimit)
    {
        push4(v68,v40,v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v39,v40,v68);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v68;
    stack[-1] = v40;
    stack[-2] = v39;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v3;

v3:
    v118 = stack[-3];
    if (v118 == nil) goto v35;
    v118 = stack[0];
    if (v118 == nil) goto v130;
    v118 = stack[-3];
    v1 = qcar(v118);
    v2 = stack[-2];
    v118 = stack[-1];
    fn = elt(env, 1); /* formbool */
    v2 = (*qfnn(fn))(qenv(fn), 3, v1, v2, v118);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v118 = stack[-4];
    v118 = cons(v2, v118);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    stack[-4] = v118;
    goto v31;

v31:
    v118 = stack[-3];
    v118 = qcdr(v118);
    stack[-3] = v118;
    goto v3;

v130:
    v118 = stack[-3];
    v1 = qcar(v118);
    v2 = stack[-2];
    v118 = stack[-1];
    fn = elt(env, 2); /* formc!* */
    v2 = (*qfnn(fn))(qenv(fn), 3, v1, v2, v118);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v118 = stack[-4];
    v118 = cons(v2, v118);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    stack[-4] = v118;
    goto v31;

v35:
    v118 = stack[-4];
        popv(6);
        return Lnreverse(nil, v118);
/* error exit handlers */
v49:
    popv(6);
    return nil;
}



/* Code for multdfconst */

static Lisp_Object CC_multdfconst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdfconst");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v39;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v20;

v20:
    v16 = stack[-1];
    if (v16 == nil) goto v32;
    v16 = stack[-2];
    v16 = qcar(v16);
    v16 = (v16 == nil ? lisp_true : nil);
    goto v112;

v112:
    if (v16 == nil) goto v21;
    v16 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v16);
    }

v21:
    v16 = stack[-1];
    v16 = qcar(v16);
    stack[0] = qcar(v16);
    v41 = stack[-2];
    v16 = stack[-1];
    v16 = qcar(v16);
    v16 = qcdr(v16);
    fn = elt(env, 3); /* multsq */
    v16 = (*qfn2(fn))(qenv(fn), v41, v16);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-4];
    fn = elt(env, 4); /* subs2q */
    v41 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-4];
    v16 = stack[-3];
    v16 = acons(stack[0], v41, v16);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-4];
    stack[-3] = v16;
    v16 = stack[-1];
    v16 = qcdr(v16);
    stack[-1] = v16;
    goto v20;

v32:
    v16 = qvalue(elt(env, 1)); /* t */
    goto v112;
/* error exit handlers */
v14:
    popv(5);
    return nil;
}



/* Code for mk!+trace */

static Lisp_Object CC_mkLtrace(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v55, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+trace");
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
    v144 = stack[-1];
    fn = elt(env, 6); /* squared!+matrix!+p */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    if (!(v144 == nil)) goto v46;
    v144 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v144 == nil)) goto v12;
    v144 = elt(env, 2); /* "no square matrix in add" */
    fn = elt(env, 7); /* lprie */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    goto v12;

v12:
    v144 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    goto v46;

v46:
    v55 = qvalue(elt(env, 3)); /* nil */
    v144 = (Lisp_Object)17; /* 1 */
    v144 = cons(v55, v144);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[0] = v144;
    v144 = (Lisp_Object)17; /* 1 */
    stack[-2] = v144;
    goto v13;

v13:
    v144 = stack[-1];
    fn = elt(env, 8); /* get!+row!+nr */
    v55 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    v144 = stack[-2];
    v144 = difference2(v55, v144);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    v144 = Lminusp(nil, v144);
    env = stack[-3];
    if (v144 == nil) goto v17;
    v144 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v144; /* !*sub2 */
    v144 = stack[0];
    fn = elt(env, 9); /* subs2 */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-3];
    stack[0] = v144;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v17:
    v146 = stack[-1];
    v55 = stack[-2];
    v144 = stack[-2];
    fn = elt(env, 10); /* get!+mat!+entry */
    v144 = (*qfnn(fn))(qenv(fn), 3, v146, v55, v144);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    fn = elt(env, 11); /* addsq */
    v144 = (*qfn2(fn))(qenv(fn), stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[0] = v144;
    v144 = stack[-2];
    v144 = add1(v144);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[-2] = v144;
    goto v13;
/* error exit handlers */
v117:
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(4);
    return nil;
v99:
    popv(4);
    return nil;
}



/* Code for distribute!.multiplicity */

static Lisp_Object CC_distributeQmultiplicity(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for distribute.multiplicity");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v39;
    v14 = v0;
/* end of prologue */
    stack[-4] = v14;
    v14 = stack[-4];
    if (v14 == nil) goto v112;
    v14 = stack[-4];
    v14 = qcar(v14);
    v17 = v14;
    v14 = stack[-3];
    v14 = cons(v17, v14);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-5];
    v14 = ncons(v14);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-5];
    stack[-1] = v14;
    stack[-2] = v14;
    goto v3;

v3:
    v14 = stack[-4];
    v14 = qcdr(v14);
    stack[-4] = v14;
    v14 = stack[-4];
    if (v14 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v14 = stack[-4];
    v14 = qcar(v14);
    v17 = v14;
    v14 = stack[-3];
    v14 = cons(v17, v14);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-5];
    v14 = ncons(v14);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-5];
    v14 = Lrplacd(nil, stack[0], v14);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-5];
    v14 = stack[-1];
    v14 = qcdr(v14);
    stack[-1] = v14;
    goto v3;

v112:
    v14 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v14); }
/* error exit handlers */
v7:
    popv(6);
    return nil;
}



/* Code for ratpoly_quot */

static Lisp_Object CC_ratpoly_quot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_quot");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v112 = v39;
    v32 = v0;
/* end of prologue */
    stack[0] = v32;
    fn = elt(env, 1); /* invsq */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    {
        Lisp_Object v11 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v11, v112);
    }
/* error exit handlers */
v12:
    popv(2);
    return nil;
}



/* Code for cgp_lbc */

static Lisp_Object CC_cgp_lbc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_lbc");
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
    v30 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_lbc */
        return (*qfn1(fn))(qenv(fn), v30);
    }
/* error exit handlers */
v20:
    popv(1);
    return nil;
}



/* Code for i2cr!* */

static Lisp_Object CC_i2crH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2cr*");
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
    v29 = v0;
/* end of prologue */
    fn = elt(env, 3); /* chkint!* */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[0];
    v36 = v29;
    if (!consp(v29)) goto v32;
    v29 = qvalue(elt(env, 2)); /* bfz!* */
    goto v3;

v3:
    {
        popv(1);
        fn = elt(env, 4); /* mkcr */
        return (*qfn2(fn))(qenv(fn), v36, v29);
    }

v32:
    v29 = elt(env, 1); /* 0.0 */
    goto v3;
/* error exit handlers */
v109:
    popv(1);
    return nil;
}



/* Code for lchk */

static Lisp_Object CC_lchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lchk");
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
    v1 = stack[0];
    if (v1 == nil) goto v112;
    v1 = stack[0];
    v1 = qcar(v1);
    v1 = (consp(v1) ? nil : lisp_true);
    goto v35;

v35:
    if (v1 == nil) goto v4;
    v1 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v1); }

v4:
    v1 = stack[0];
    v1 = qcar(v1);
    v1 = Llength(nil, v1);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    stack[-1] = v1;
    goto v21;

v21:
    v1 = stack[0];
    v1 = qcdr(v1);
    stack[0] = v1;
    v1 = stack[0];
    if (v1 == nil) goto v6;
    v1 = stack[0];
    v1 = qcar(v1);
    if (!consp(v1)) goto v113;
    v1 = stack[0];
    v1 = qcar(v1);
    v7 = Llength(nil, v1);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    v1 = stack[-1];
    v1 = Lneq(nil, v7, v1);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    goto v5;

v5:
    if (v1 == nil) goto v21;
    v1 = stack[0];
    v1 = (v1 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v1); }

v113:
    v1 = qvalue(elt(env, 1)); /* t */
    goto v5;

v6:
    v1 = qvalue(elt(env, 1)); /* t */
    goto v5;

v112:
    v1 = qvalue(elt(env, 1)); /* t */
    goto v35;
/* error exit handlers */
v47:
    popv(3);
    return nil;
}



/* Code for difference!: */

static Lisp_Object CC_differenceT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v57, v161;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difference:");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v39;
    v161 = v0;
/* end of prologue */
    v138 = v161;
    v138 = qcdr(v138);
    v57 = qcar(v138);
    stack[-1] = v57;
    v138 = (Lisp_Object)1; /* 0 */
    if (v57 == v138) goto v37;
    v138 = stack[-2];
    v138 = qcdr(v138);
    v57 = qcar(v138);
    stack[0] = v57;
    v138 = (Lisp_Object)1; /* 0 */
    if (v57 == v138) { popv(6); return onevalue(v161); }
    v138 = v161;
    v138 = qcdr(v138);
    v57 = qcdr(v138);
    stack[-4] = v57;
    v138 = stack[-2];
    v138 = qcdr(v138);
    v138 = qcdr(v138);
    stack[-2] = v138;
    v57 = difference2(v57, v138);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-5];
    stack[-3] = v57;
    v138 = (Lisp_Object)1; /* 0 */
    if (v57 == v138) goto v52;
    v57 = stack[-3];
    v138 = (Lisp_Object)1; /* 0 */
    v138 = (Lisp_Object)greaterp2(v57, v138);
    nil = C_nil;
    if (exception_pending()) goto v162;
    v138 = v138 ? lisp_true : nil;
    env = stack[-5];
    if (v138 == nil) goto v102;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v57 = stack[-1];
    v138 = stack[-3];
    v57 = Lash1(nil, v57, v138);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-5];
    v138 = stack[0];
    v57 = difference2(v57, v138);
    nil = C_nil;
    if (exception_pending()) goto v162;
    v138 = stack[-2];
    {
        Lisp_Object v163 = stack[-4];
        popv(6);
        return list2star(v163, v57, v138);
    }

v102:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v138 = stack[-3];
    v138 = negate(v138);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-5];
    v138 = Lash1(nil, stack[0], v138);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-5];
    v57 = difference2(stack[-1], v138);
    nil = C_nil;
    if (exception_pending()) goto v162;
    v138 = stack[-4];
    {
        Lisp_Object v164 = stack[-2];
        popv(6);
        return list2star(v164, v57, v138);
    }

v52:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v57 = stack[-1];
    v138 = stack[0];
    v57 = difference2(v57, v138);
    nil = C_nil;
    if (exception_pending()) goto v162;
    v138 = stack[-4];
    {
        Lisp_Object v165 = stack[-2];
        popv(6);
        return list2star(v165, v57, v138);
    }

v37:
    stack[0] = elt(env, 1); /* !:rd!: */
    v138 = stack[-2];
    v138 = qcdr(v138);
    v138 = qcar(v138);
    v57 = negate(v138);
    nil = C_nil;
    if (exception_pending()) goto v162;
    v138 = stack[-2];
    v138 = qcdr(v138);
    v138 = qcdr(v138);
    {
        Lisp_Object v106 = stack[0];
        popv(6);
        return list2star(v106, v57, v138);
    }
/* error exit handlers */
v162:
    popv(6);
    return nil;
}



/* Code for rd!:difference */

static Lisp_Object CC_rdTdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v59, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:difference");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v39;
    stack[0] = v0;
/* end of prologue */
    v65 = qvalue(elt(env, 1)); /* nil */
    v59 = v65;
    v65 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v65 == nil) goto v35;
    v65 = qvalue(elt(env, 1)); /* nil */
    goto v31;

v31:
    if (v65 == nil) goto v118;
    v65 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v65, v59);

v118:
    v59 = stack[0];
    v65 = stack[-1];
    fn = elt(env, 8); /* convprc2 */
    v65 = (*qfn2(fn))(qenv(fn), v59, v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    stack[-1] = v65;
    v65 = qvalue(elt(env, 4)); /* yy!! */
    stack[-3] = v65;
    v65 = stack[-1];
    if (!consp(v65)) goto v104;
    v59 = stack[-1];
    v65 = stack[-3];
    fn = elt(env, 9); /* difbf */
    v65 = (*qfn2(fn))(qenv(fn), v59, v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    goto v50;

v50:
    stack[0] = v65;
    stack[-2] = stack[0];
    v65 = stack[-3];
    if (!consp(v65)) goto v188;
    stack[0] = elt(env, 3); /* !:rd!: */
    v65 = stack[-3];
    v65 = qcdr(v65);
    v65 = qcar(v65);
    v59 = negate(v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v65 = stack[-3];
    v65 = qcdr(v65);
    v65 = qcdr(v65);
    v65 = list2star(stack[0], v59, v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    goto v189;

v189:
    fn = elt(env, 10); /* rdzchk */
    v65 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v59 = v65;
    v65 = v59;
    if (!(!consp(v65))) { popv(5); return onevalue(v59); }
    v65 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v65, v59);

v188:
    v65 = stack[-3];
    v65 = negate(v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    goto v189;

v104:
    stack[-2] = elt(env, 5); /* difference */
    v65 = stack[-1];
    stack[0] = Lmkquote(nil, v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v65 = stack[-3];
    v65 = Lmkquote(nil, v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v186 = list3(stack[-2], stack[0], v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v59 = qvalue(elt(env, 1)); /* nil */
    v65 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 11); /* errorset */
    v65 = (*qfnn(fn))(qenv(fn), 3, v186, v59, v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v59 = v65;
    v65 = v59;
    if (!consp(v65)) goto v88;
    v65 = v59;
    v65 = qcdr(v65);
    goto v190;

v190:
    if (v65 == nil) goto v191;
    fn = elt(env, 12); /* rndbfon */
    v65 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v65 = stack[-1];
    v65 = Lfloatp(nil, v65);
    env = stack[-4];
    if (v65 == nil) goto v192;
    v65 = stack[-1];
    fn = elt(env, 13); /* fl2bf */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    stack[0] = v65;
    goto v193;

v193:
    stack[-1] = stack[0];
    v65 = stack[-3];
    v65 = Lfloatp(nil, v65);
    env = stack[-4];
    if (v65 == nil) goto v194;
    v65 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    goto v195;

v195:
    stack[-3] = v65;
    fn = elt(env, 9); /* difbf */
    v65 = (*qfn2(fn))(qenv(fn), stack[0], v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    goto v50;

v194:
    v65 = stack[-3];
    if (!consp(v65)) goto v196;
    v65 = stack[-3];
    goto v197;

v197:
    fn = elt(env, 14); /* csl_normbf */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    goto v195;

v196:
    v65 = stack[-3];
    v65 = integerp(v65);
    if (v65 == nil) goto v80;
    v186 = elt(env, 3); /* !:rd!: */
    v59 = stack[-3];
    v65 = (Lisp_Object)1; /* 0 */
    v65 = list2star(v186, v59, v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    goto v197;

v80:
    v65 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    goto v197;

v192:
    v65 = stack[-1];
    if (!consp(v65)) goto v149;
    v65 = stack[-1];
    goto v133;

v133:
    fn = elt(env, 14); /* csl_normbf */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    stack[0] = v65;
    goto v193;

v149:
    v65 = stack[-1];
    v65 = integerp(v65);
    if (v65 == nil) goto v162;
    v186 = elt(env, 3); /* !:rd!: */
    v59 = stack[-1];
    v65 = (Lisp_Object)1; /* 0 */
    v65 = list2star(v186, v59, v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    goto v133;

v162:
    v65 = stack[-1];
    fn = elt(env, 15); /* read!:num */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    goto v133;

v191:
    v65 = v59;
    v65 = qcar(v65);
    goto v50;

v88:
    v65 = qvalue(elt(env, 7)); /* t */
    goto v190;

v35:
    v65 = stack[0];
    v65 = qcdr(v65);
    if (!consp(v65)) goto v11;
    v65 = qvalue(elt(env, 1)); /* nil */
    goto v31;

v11:
    v65 = stack[-1];
    v65 = qcdr(v65);
    if (!consp(v65)) goto v21;
    v65 = qvalue(elt(env, 1)); /* nil */
    goto v31;

v21:
    v65 = stack[0];
    stack[-2] = qcdr(v65);
    v65 = stack[-1];
    v65 = qcdr(v65);
    v65 = negate(v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    fn = elt(env, 16); /* safe!-fp!-plus */
    v65 = (*qfn2(fn))(qenv(fn), stack[-2], v65);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v59 = v65;
    goto v31;
/* error exit handlers */
v187:
    popv(5);
    return nil;
}



/* Code for prop!-simp2 */

static Lisp_Object CC_propKsimp2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v118;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp2");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v39;
    stack[-3] = v0;
/* end of prologue */
    v28 = stack[-2];
    if (!consp(v28)) goto v112;
    v118 = stack[-2];
    v28 = stack[-3];
    v28 = Lmember(nil, v118, v28);
    goto v35;

v35:
    stack[-4] = v28;
    if (v28 == nil) goto v14;
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v28 = stack[-3];
    stack[0] = Llength(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    v28 = stack[-4];
    v28 = Llength(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    v28 = difference2(stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    stack[0] = Lexpt(nil, stack[-1], v28);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    v118 = stack[-2];
    v28 = stack[-3];
    v28 = Ldelete(nil, v118, v28);
    nil = C_nil;
    if (exception_pending()) goto v47;
    {
        Lisp_Object v10 = stack[0];
        popv(6);
        return cons(v10, v28);
    }

v14:
    v28 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v28); }

v112:
    v28 = qvalue(elt(env, 1)); /* nil */
    goto v35;
/* error exit handlers */
v47:
    popv(6);
    return nil;
}



/* Code for greaterpcdr */

static Lisp_Object CC_greaterpcdr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v34;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greaterpcdr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v39;
    v34 = v0;
/* end of prologue */
    v34 = qcdr(v34);
    v32 = qcdr(v32);
        return Lgreaterp(nil, v34, v32);
}



/* Code for remchkf */

static Lisp_Object MS_CDECL CC_remchkf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v39,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "remchkf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remchkf");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v39,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v40;
    stack[-1] = v39;
    stack[-2] = v0;
/* end of prologue */
    v144 = stack[-2];
    v143 = stack[-1];
    fn = elt(env, 3); /* remchkf1 */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    stack[-3] = v143;
    v143 = stack[-3];
    if (!consp(v143)) goto v46;
    v143 = stack[-3];
    v143 = qcar(v143);
    v143 = (consp(v143) ? nil : lisp_true);
    goto v109;

v109:
    if (v143 == nil) goto v110;
    v143 = qvalue(elt(env, 1)); /* t */
    goto v129;

v129:
    if (!(v143 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v143 = stack[-3];
    stack[-2] = qcar(v143);
    v143 = stack[-3];
    v55 = qcdr(v143);
    v144 = stack[-1];
    v143 = stack[0];
    v143 = CC_remchkf(env, 3, v55, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v99;
    {
        Lisp_Object v117 = stack[-2];
        popv(5);
        return cons(v117, v143);
    }

v110:
    v144 = stack[-2];
    v143 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* kernels1 */
    v144 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    v143 = stack[0];
    fn = elt(env, 5); /* intersection */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    v143 = (v143 == nil ? lisp_true : nil);
    goto v129;

v46:
    v143 = qvalue(elt(env, 1)); /* t */
    goto v109;
/* error exit handlers */
v99:
    popv(5);
    return nil;
}



/* Code for lpos */

static Lisp_Object CC_lpos(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v38, v145, v98;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpos");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v145 = v39;
    v98 = v0;
/* end of prologue */
    v38 = v98;
    v111 = v145;
    v111 = qcar(v111);
    if (v38 == v111) goto v30;
    v111 = v98;
    v38 = v145;
    v38 = qcdr(v38);
    v111 = CC_lpos(env, v111, v38);
    errexit();
    return add1(v111);

v30:
    v111 = (Lisp_Object)17; /* 1 */
    return onevalue(v111);
}



/* Code for lessppair */

static Lisp_Object CC_lessppair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44, v131, v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lessppair");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v39;
    v131 = v0;
/* end of prologue */
    v43 = v131;
    v13 = qcar(v43);
    v43 = v44;
    v43 = qcar(v43);
    if (equal(v13, v43)) goto v33;
    v43 = v131;
    v43 = qcar(v43);
    v44 = qcar(v44);
        return Llessp(nil, v43, v44);

v33:
    v43 = v131;
    v43 = qcdr(v43);
    v44 = qcdr(v44);
        return Llessp(nil, v43, v44);
}



/* Code for giplus!: */

static Lisp_Object CC_giplusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v45;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giplus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v39;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = elt(env, 1); /* !:gi!: */
    v6 = stack[-2];
    v6 = qcdr(v6);
    v45 = qcar(v6);
    v6 = stack[-1];
    v6 = qcdr(v6);
    v6 = qcar(v6);
    stack[0] = plus2(v45, v6);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    v6 = stack[-2];
    v6 = qcdr(v6);
    v45 = qcdr(v6);
    v6 = stack[-1];
    v6 = qcdr(v6);
    v6 = qcdr(v6);
    v6 = plus2(v45, v6);
    nil = C_nil;
    if (exception_pending()) goto v110;
    {
        Lisp_Object v15 = stack[-3];
        Lisp_Object v113 = stack[0];
        popv(5);
        return list2star(v15, v113, v6);
    }
/* error exit handlers */
v110:
    popv(5);
    return nil;
}



/* Code for depend!-f */

static Lisp_Object CC_dependKf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-f");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v39;
    stack[-1] = v0;
/* end of prologue */

v53:
    v14 = stack[-1];
    if (!consp(v14)) goto v54;
    v14 = stack[-1];
    v14 = qcar(v14);
    v14 = (consp(v14) ? nil : lisp_true);
    goto v3;

v3:
    if (v14 == nil) goto v25;
    v14 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v14); }

v25:
    v14 = stack[-1];
    v14 = qcar(v14);
    v14 = qcar(v14);
    v17 = qcar(v14);
    v14 = stack[0];
    fn = elt(env, 3); /* depend!-p */
    v14 = (*qfn2(fn))(qenv(fn), v17, v14);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-2];
    if (!(v14 == nil)) { popv(3); return onevalue(v14); }
    v14 = stack[-1];
    v14 = qcar(v14);
    v17 = qcdr(v14);
    v14 = stack[0];
    v14 = CC_dependKf(env, v17, v14);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-2];
    if (!(v14 == nil)) { popv(3); return onevalue(v14); }
    v14 = stack[-1];
    v17 = qcdr(v14);
    v14 = stack[0];
    stack[-1] = v17;
    stack[0] = v14;
    goto v53;

v54:
    v14 = qvalue(elt(env, 1)); /* t */
    goto v3;
/* error exit handlers */
v118:
    popv(3);
    return nil;
}



/* Code for pasf_subfof */

static Lisp_Object MS_CDECL CC_pasf_subfof(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v39,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v46, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_subfof");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_subfof");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v39,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v109 = v40;
    v46 = v39;
    v37 = v0;
/* end of prologue */
    stack[-1] = v109;
    stack[0] = elt(env, 1); /* pasf_subfof1 */
    v109 = v37;
    v109 = list2(v109, v46);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    {
        Lisp_Object v111 = stack[-1];
        Lisp_Object v38 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v111, v38, v109);
    }
/* error exit handlers */
v21:
    popv(3);
    return nil;
}



/* Code for omatpir */

static Lisp_Object MS_CDECL CC_omatpir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v21, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omatpir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omatpir");
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
    fn = elt(env, 3); /* lex */
    v26 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    fn = elt(env, 4); /* omsir */
    v26 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    v26 = qcar(v26);
    stack[-1] = v26;
    fn = elt(env, 3); /* lex */
    v26 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    fn = elt(env, 5); /* omobj */
    v26 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    v26 = qcar(v26);
    stack[0] = v26;
    fn = elt(env, 3); /* lex */
    v26 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    v26 = elt(env, 1); /* (!/ o m a t p) */
    fn = elt(env, 6); /* checktag */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    v111 = stack[-1];
    v21 = stack[0];
    v26 = qvalue(elt(env, 2)); /* nil */
    v26 = list2star(v111, v21, v26);
    nil = C_nil;
    if (exception_pending()) goto v98;
    popv(3);
    return ncons(v26);
/* error exit handlers */
v98:
    popv(3);
    return nil;
}



/* Code for simp_without_resimp */

static Lisp_Object CC_simp_without_resimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp_without_resimp");
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
    v4 = v0;
/* end of prologue */
    v20 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*resimp */
    qvalue(elt(env, 2)) = v20; /* !*resimp */
    v20 = v4;
    fn = elt(env, 3); /* simp */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*resimp */
    { popv(2); return onevalue(v20); }
/* error exit handlers */
v54:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*resimp */
    popv(2);
    return nil;
}



/* Code for f2dip11 */

static Lisp_Object CC_f2dip11(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip11");
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

v53:
    v49 = qvalue(elt(env, 1)); /* !*notestparameters */
    if (!(v49 == nil)) { popv(2); return onevalue(v49); }
    v50 = stack[0];
    v49 = qvalue(elt(env, 2)); /* vdpvars!* */
    v49 = Lmember(nil, v50, v49);
    if (v49 == nil) goto v4;
    v49 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v49 == nil)) goto v36;
    v50 = stack[0];
    v49 = elt(env, 4); /* "occurs in a parameter and is member of the groebner variables." 
*/
    v49 = list2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    fn = elt(env, 7); /* lprie */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    goto v36;

v36:
    v49 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    goto v4;

v4:
    v49 = stack[0];
    if (!consp(v49)) goto v113;
    v49 = stack[0];
    v49 = qcar(v49);
    v49 = CC_f2dip11(env, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v49 = stack[0];
    v49 = qcdr(v49);
    stack[0] = v49;
    goto v53;

v113:
    v50 = stack[0];
    v49 = elt(env, 5); /* list */
    if (v50 == v49) goto v110;
    v49 = nil;
    { popv(2); return onevalue(v49); }

v110:
    v49 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v49 == nil)) goto v42;
    v49 = elt(env, 6); /* "groebner: LIST not allowed." */
    fn = elt(env, 7); /* lprie */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    goto v42;

v42:
    v49 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = nil;
    { popv(2); return onevalue(v49); }
/* error exit handlers */
v52:
    popv(2);
    return nil;
}



/* Code for wedgef */

static Lisp_Object CC_wedgef(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v211, v212, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgef");
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
    v211 = stack[-1];
    fn = elt(env, 8); /* dim!<deg */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    if (v211 == nil) goto v112;
    v211 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v211); }

v112:
    v211 = stack[-1];
    v212 = qcar(v211);
    v211 = elt(env, 2); /* hodge */
    if (!consp(v212)) goto v156;
    v212 = qcar(v212);
    if (!(v212 == v211)) goto v156;
    v211 = stack[-1];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v211 = qcar(v211);
    fn = elt(env, 9); /* deg!*form */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    stack[-2] = v211;
    stack[0] = stack[-2];
    v211 = stack[-1];
    v211 = qcdr(v211);
    fn = elt(env, 10); /* deg!*farg */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    if (equal(stack[0], v211)) goto v119;
    v211 = stack[-1];
    {
        popv(4);
        fn = elt(env, 11); /* mkwedge */
        return (*qfn1(fn))(qenv(fn), v211);
    }

v119:
    v211 = stack[-1];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v213 = qcar(v211);
    v212 = (Lisp_Object)17; /* 1 */
    v211 = (Lisp_Object)17; /* 1 */
    v211 = list2star(v213, v212, v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    stack[0] = ncons(v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v211 = stack[-1];
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    if (v211 == nil) goto v117;
    v211 = stack[-1];
    v211 = qcdr(v211);
    fn = elt(env, 12); /* mkuniquewedge1 */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    goto v49;

v49:
    fn = elt(env, 13); /* hodgepf */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    fn = elt(env, 14); /* mkunarywedge */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    fn = elt(env, 15); /* wedgepf2 */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    stack[0] = stack[-2];
    v211 = qvalue(elt(env, 3)); /* dimex!* */
    fn = elt(env, 16); /* negf */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    fn = elt(env, 17); /* addf */
    v211 = (*qfn2(fn))(qenv(fn), stack[-2], v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    fn = elt(env, 18); /* multf */
    v211 = (*qfn2(fn))(qenv(fn), stack[0], v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    fn = elt(env, 19); /* mksgnsq */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    {
        Lisp_Object v166 = stack[-1];
        popv(4);
        fn = elt(env, 20); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v166, v211);
    }

v117:
    v211 = stack[-1];
    v211 = qcdr(v211);
    v213 = qcar(v211);
    v212 = (Lisp_Object)17; /* 1 */
    v211 = (Lisp_Object)17; /* 1 */
    v211 = list2star(v213, v212, v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v211 = ncons(v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    goto v49;

v156:
    v211 = stack[-1];
    v212 = qcar(v211);
    v211 = elt(env, 4); /* d */
    if (!consp(v212)) goto v214;
    v212 = qcar(v212);
    if (!(v212 == v211)) goto v214;
    v212 = elt(env, 4); /* d */
    v211 = elt(env, 5); /* noxpnd */
    v211 = Lflagp(nil, v212, v211);
    env = stack[-3];
    if (v211 == nil) goto v141;
    v211 = qvalue(elt(env, 6)); /* t */
    goto v215;

v215:
    if (v211 == nil) goto v62;
    v211 = stack[-1];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v212 = qcar(v211);
    v211 = stack[-1];
    v211 = qcdr(v211);
    v211 = cons(v212, v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    fn = elt(env, 21); /* dwedge */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    fn = elt(env, 14); /* mkunarywedge */
    stack[-2] = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v211 = stack[-1];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v213 = qcar(v211);
    v212 = (Lisp_Object)17; /* 1 */
    v211 = (Lisp_Object)17; /* 1 */
    v211 = list2star(v213, v212, v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    stack[0] = ncons(v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v211 = stack[-1];
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    if (v211 == nil) goto v216;
    v211 = stack[-1];
    v211 = qcdr(v211);
    fn = elt(env, 21); /* dwedge */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    goto v217;

v217:
    fn = elt(env, 14); /* mkunarywedge */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    fn = elt(env, 15); /* wedgepf2 */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v211 = stack[-1];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v211 = qcar(v211);
    fn = elt(env, 9); /* deg!*form */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    fn = elt(env, 19); /* mksgnsq */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    stack[-1] = v211;
    v211 = stack[-1];
    v211 = qcar(v211);
    fn = elt(env, 16); /* negf */
    v212 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    v211 = stack[-1];
    v211 = qcdr(v211);
    v211 = cons(v212, v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    fn = elt(env, 20); /* multpfsq */
    v211 = (*qfn2(fn))(qenv(fn), stack[0], v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    {
        Lisp_Object v218 = stack[-2];
        popv(4);
        fn = elt(env, 22); /* addpf */
        return (*qfn2(fn))(qenv(fn), v218, v211);
    }

v216:
    v211 = stack[-1];
    v211 = qcdr(v211);
    v211 = qcar(v211);
    fn = elt(env, 23); /* exdfk */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    goto v217;

v62:
    v211 = stack[-1];
    {
        popv(4);
        fn = elt(env, 11); /* mkwedge */
        return (*qfn1(fn))(qenv(fn), v211);
    }

v141:
    v212 = qvalue(elt(env, 7)); /* lftshft!* */
    v211 = stack[-1];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v211 = qcar(v211);
    fn = elt(env, 24); /* smemqlp */
    v211 = (*qfn2(fn))(qenv(fn), v212, v211);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-3];
    goto v215;

v214:
    v211 = qvalue(elt(env, 1)); /* nil */
    goto v215;
/* error exit handlers */
v167:
    popv(4);
    return nil;
}



/* Code for plubf */

static Lisp_Object CC_plubf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v218, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plubf");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v39;
    stack[-7] = v0;
/* end of prologue */
    v166 = stack[-7];
    v166 = qcdr(v166);
    v218 = qcar(v166);
    stack[-8] = v218;
    v166 = (Lisp_Object)1; /* 0 */
    if (v218 == v166) goto v34;
    v166 = stack[-6];
    v166 = qcdr(v166);
    v218 = qcar(v166);
    stack[-5] = v218;
    v166 = (Lisp_Object)1; /* 0 */
    if (v218 == v166) goto v111;
    v166 = stack[-7];
    v166 = qcdr(v166);
    v218 = qcdr(v166);
    stack[-4] = v218;
    v166 = stack[-6];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    stack[-3] = v166;
    v218 = difference2(v218, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    stack[-2] = v218;
    v166 = (Lisp_Object)1; /* 0 */
    if (v218 == v166) goto v1;
    stack[-1] = stack[-2];
    v166 = stack[-8];
    v166 = Labsval(nil, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    v166 = stack[-5];
    v166 = Labsval(nil, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    v166 = difference2(stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    v166 = plus2(stack[-1], v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    stack[-1] = v166;
    v166 = qvalue(elt(env, 2)); /* !:bprec!: */
    v166 = add1(v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    stack[0] = v166;
    v218 = stack[-1];
    v166 = stack[0];
    v166 = (Lisp_Object)greaterp2(v218, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v166 = v166 ? lisp_true : nil;
    env = stack[-9];
    if (v166 == nil) goto v157;
    v166 = stack[-7];
    goto v35;

v35:
    stack[-2] = v166;
    v166 = stack[-2];
    v166 = qcdr(v166);
    v166 = qcar(v166);
    v66 = v166;
    v218 = v66;
    v166 = (Lisp_Object)1; /* 0 */
    if (v218 == v166) goto v71;
    v218 = v66;
    v166 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v166 = (*qfn2(fn))(qenv(fn), v218, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    v66 = v166;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v166 = v66;
    stack[0] = qcar(v166);
    v166 = v66;
    v218 = qcdr(v166);
    v166 = stack[-2];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = plus2(v218, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    {
        Lisp_Object v94 = stack[-1];
        Lisp_Object v95 = stack[0];
        popv(10);
        return list2star(v94, v95, v166);
    }

v71:
    v66 = elt(env, 1); /* !:rd!: */
    v218 = (Lisp_Object)1; /* 0 */
    v166 = (Lisp_Object)1; /* 0 */
    popv(10);
    return list2star(v66, v218, v166);

v157:
    v166 = stack[0];
    v166 = negate(v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    v166 = (Lisp_Object)lessp2(stack[-1], v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v166 = v166 ? lisp_true : nil;
    env = stack[-9];
    if (v166 == nil) goto v86;
    v166 = stack[-6];
    goto v35;

v86:
    v218 = stack[-2];
    v166 = (Lisp_Object)1; /* 0 */
    v166 = (Lisp_Object)greaterp2(v218, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v166 = v166 ? lisp_true : nil;
    env = stack[-9];
    if (v166 == nil) goto v228;
    stack[0] = elt(env, 1); /* !:rd!: */
    v218 = stack[-8];
    v166 = stack[-2];
    v218 = Lash1(nil, v218, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    v166 = stack[-5];
    v218 = plus2(v218, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    v166 = stack[-3];
    v166 = list2star(stack[0], v218, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    goto v35;

v228:
    stack[0] = elt(env, 1); /* !:rd!: */
    stack[-1] = stack[-8];
    stack[-3] = stack[-5];
    v166 = stack[-2];
    v166 = negate(v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    v166 = Lash1(nil, stack[-3], v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    v218 = plus2(stack[-1], v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    v166 = stack[-4];
    v166 = list2star(stack[0], v218, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    goto v35;

v1:
    stack[0] = elt(env, 1); /* !:rd!: */
    v218 = stack[-8];
    v166 = stack[-5];
    v218 = plus2(v218, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    v166 = stack[-4];
    v166 = list2star(stack[0], v218, v166);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-9];
    goto v35;

v111:
    v166 = stack[-7];
    goto v35;

v34:
    v166 = stack[-6];
    goto v35;
/* error exit handlers */
v227:
    popv(10);
    return nil;
}



/* Code for find_triangl_coeff */

static Lisp_Object MS_CDECL CC_find_triangl_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v39,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v22, v29, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "find_triangl_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_triangl_coeff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v129 = v40;
    v22 = v39;
    v29 = v0;
/* end of prologue */
    v36 = v29;
    v29 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* find_triangle_coeff */
        return (*qfnn(fn))(qenv(fn), 4, v36, v29, v22, v129);
    }
}



/* Code for formsetq0 */

static Lisp_Object MS_CDECL CC_formsetq0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v39,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v299, v300, v301, v302;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formsetq0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formsetq0");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v39,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v40;
    stack[-4] = v39;
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    v299 = stack[0];
    v299 = qcdr(v299);
    stack[0] = v299;
    v299 = qcar(v299);
    stack[-2] = v299;
    if (!(symbolp(v299))) goto v38;
    v300 = stack[-2];
    v299 = stack[-4];
    v299 = Latsoc(nil, v300, v299);
    stack[-1] = v299;
    goto v38;

v38:
    v299 = stack[0];
    v299 = qcdr(v299);
    v300 = qcar(v299);
    v299 = elt(env, 1); /* quote */
    if (!consp(v300)) goto v19;
    v300 = qcar(v300);
    if (!(v300 == v299)) goto v19;
    v299 = elt(env, 2); /* symbolic */
    stack[-3] = v299;
    goto v19;

v19:
    v299 = stack[0];
    v299 = qcdr(v299);
    v301 = qcar(v299);
    v300 = stack[-4];
    v299 = stack[-3];
    fn = elt(env, 28); /* form1 */
    v302 = (*qfnn(fn))(qenv(fn), 3, v301, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    v301 = stack[-4];
    v300 = elt(env, 2); /* symbolic */
    v299 = stack[-3];
    fn = elt(env, 29); /* convertmode1 */
    v299 = (*qfnn(fn))(qenv(fn), 4, v302, v301, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    stack[-5] = v299;
    v299 = stack[-2];
    if (!consp(v299)) goto v10;
    v299 = stack[-2];
    v299 = qcar(v299);
    if (symbolp(v299)) goto v90;
    v300 = stack[-2];
    v299 = elt(env, 3); /* "assignment" */
    {
        popv(7);
        fn = elt(env, 30); /* typerr */
        return (*qfn2(fn))(qenv(fn), v300, v299);
    }

v90:
    v300 = stack[-2];
    v299 = stack[-3];
    fn = elt(env, 31); /* macrochk */
    v299 = (*qfn2(fn))(qenv(fn), v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    stack[-2] = v299;
    if (!consp(v299)) goto v155;
    v299 = stack[-2];
    v300 = qcar(v299);
    v299 = elt(env, 4); /* rtype */
    v300 = get(v300, v299);
    env = stack[-6];
    v299 = elt(env, 5); /* array */
    v299 = (v300 == v299 ? lisp_true : nil);
    goto v127;

v127:
    if (v299 == nil) goto v114;
    stack[0] = elt(env, 7); /* setel */
    v301 = stack[-2];
    v300 = stack[-4];
    v299 = stack[-3];
    fn = elt(env, 32); /* intargfn */
    v300 = (*qfnn(fn))(qenv(fn), 3, v301, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    v299 = stack[-5];
    {
        Lisp_Object v304 = stack[0];
        popv(7);
        return list3(v304, v300, v299);
    }

v114:
    v299 = stack[-2];
    if (!consp(v299)) goto v176;
    v299 = stack[-2];
    v299 = qcdr(v299);
    if (v299 == nil) goto v305;
    v299 = stack[-2];
    v300 = qcar(v299);
    v299 = elt(env, 4); /* rtype */
    v300 = get(v300, v299);
    env = stack[-6];
    v299 = elt(env, 8); /* vector */
    if (v300 == v299) goto v214;
    v299 = stack[-2];
    v299 = qcdr(v299);
    v299 = qcar(v299);
    v299 = Lsimple_vectorp(nil, v299);
    env = stack[-6];
    if (!(v299 == nil)) goto v148;
    v299 = stack[-2];
    v299 = qcdr(v299);
    v300 = qcar(v299);
    v299 = elt(env, 10); /* vecfn */
    v299 = Lflagpcar(nil, v300, v299);
    env = stack[-6];
    goto v148;

v148:
    if (v299 == nil) goto v189;
    v301 = stack[0];
    v300 = stack[-4];
    v299 = stack[-3];
    {
        popv(7);
        fn = elt(env, 33); /* putvect */
        return (*qfnn(fn))(qenv(fn), 3, v301, v300, v299);
    }

v189:
    v300 = stack[-2];
    v299 = elt(env, 11); /* part */
    if (!consp(v300)) goto v217;
    v300 = qcar(v300);
    if (!(v300 == v299)) goto v217;
    stack[-1] = elt(env, 12); /* list */
    v299 = elt(env, 13); /* setpart!* */
    stack[0] = Lmkquote(nil, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    v299 = stack[-2];
    v301 = qcdr(v299);
    v300 = stack[-4];
    v299 = stack[-3];
    fn = elt(env, 34); /* formlis */
    v299 = (*qfnn(fn))(qenv(fn), 3, v301, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    stack[0] = list2star(stack[-1], stack[0], v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    v299 = stack[-5];
    v299 = ncons(v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    {
        Lisp_Object v306 = stack[0];
        popv(7);
        return Lnconc(nil, v306, v299);
    }

v217:
    v299 = stack[-2];
    if (!consp(v299)) goto v227;
    v299 = stack[-2];
    v300 = qcar(v299);
    v299 = elt(env, 14); /* setqfn */
    v299 = get(v300, v299);
    env = stack[-6];
    stack[-1] = v299;
    goto v167;

v167:
    if (v299 == nil) goto v307;
    v299 = stack[-2];
    v300 = qcdr(v299);
    v299 = stack[0];
    v299 = qcdr(v299);
    v300 = Lappend(nil, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    v299 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 35); /* applsmacro */
    v301 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    v300 = stack[-4];
    v299 = stack[-3];
    {
        popv(7);
        fn = elt(env, 28); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v301, v300, v299);
    }

v307:
    v300 = stack[-3];
    v299 = elt(env, 2); /* symbolic */
    if (v300 == v299) goto v308;
    v299 = qvalue(elt(env, 6)); /* nil */
    goto v309;

v309:
    if (v299 == nil) goto v310;
    stack[0] = elt(env, 17); /* rsetf */
    v301 = stack[-2];
    v300 = stack[-4];
    v299 = stack[-3];
    fn = elt(env, 28); /* form1 */
    v300 = (*qfnn(fn))(qenv(fn), 3, v301, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    v299 = stack[-5];
    {
        Lisp_Object v311 = stack[0];
        popv(7);
        return list3(v311, v300, v299);
    }

v310:
    stack[0] = elt(env, 18); /* setk */
    v301 = stack[-2];
    v300 = stack[-4];
    v299 = elt(env, 19); /* algebraic */
    fn = elt(env, 28); /* form1 */
    v300 = (*qfnn(fn))(qenv(fn), 3, v301, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    v299 = stack[-5];
    {
        Lisp_Object v312 = stack[0];
        popv(7);
        return list3(v312, v300, v299);
    }

v308:
    v299 = qvalue(elt(env, 15)); /* !*rlisp88 */
    if (!(v299 == nil)) goto v309;
    v300 = stack[-2];
    v299 = elt(env, 16); /* structfetch */
    v299 = Leqcar(nil, v300, v299);
    env = stack[-6];
    goto v309;

v227:
    v299 = qvalue(elt(env, 6)); /* nil */
    goto v167;

v214:
    v299 = qvalue(elt(env, 9)); /* t */
    goto v148;

v305:
    v299 = qvalue(elt(env, 6)); /* nil */
    goto v148;

v176:
    v299 = qvalue(elt(env, 6)); /* nil */
    goto v148;

v155:
    v299 = qvalue(elt(env, 6)); /* nil */
    goto v127;

v10:
    v299 = stack[-2];
    if (symbolp(v299)) goto v313;
    v300 = stack[-2];
    v299 = elt(env, 3); /* "assignment" */
    {
        popv(7);
        fn = elt(env, 30); /* typerr */
        return (*qfn2(fn))(qenv(fn), v300, v299);
    }

v313:
    v300 = stack[-2];
    v299 = elt(env, 20); /* reserved */
    v299 = Lflagp(nil, v300, v299);
    env = stack[-6];
    if (v299 == nil) goto v314;
    v300 = stack[-2];
    v299 = stack[-4];
    v299 = Latsoc(nil, v300, v299);
    v299 = (v299 == nil ? lisp_true : nil);
    goto v315;

v315:
    if (v299 == nil) goto v316;
    v300 = stack[-2];
    v299 = elt(env, 21); /* "is a reserved identifier" */
    v299 = list2(v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    v300 = v299;
    v299 = v300;
    qvalue(elt(env, 22)) = v299; /* errmsg!* */
    v299 = qvalue(elt(env, 23)); /* !*protfg */
    if (!(v299 == nil)) goto v317;
    v299 = v300;
    fn = elt(env, 36); /* lprie */
    v299 = (*qfn1(fn))(qenv(fn), v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    goto v317;

v317:
    v299 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v303;
    v299 = nil;
    { popv(7); return onevalue(v299); }

v316:
    v300 = stack[-2];
    v299 = elt(env, 24); /* share */
    v299 = Lflagp(nil, v300, v299);
    env = stack[-6];
    if (v299 == nil) goto v318;
    v300 = stack[-2];
    v299 = stack[-4];
    fn = elt(env, 37); /* symbid */
    stack[0] = (*qfn2(fn))(qenv(fn), v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    v301 = elt(env, 25); /* progn */
    v300 = elt(env, 26); /* (setq alglist!* (cons nil nil)) */
    v299 = stack[-5];
    v299 = list3(v301, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    {
        Lisp_Object v319 = stack[0];
        popv(7);
        fn = elt(env, 38); /* mksetq */
        return (*qfn2(fn))(qenv(fn), v319, v299);
    }

v318:
    v300 = stack[-3];
    v299 = elt(env, 2); /* symbolic */
    if (v300 == v299) goto v320;
    v299 = stack[-1];
    if (!(v299 == nil)) goto v321;
    v300 = stack[-5];
    v299 = elt(env, 1); /* quote */
    v299 = Leqcar(nil, v300, v299);
    env = stack[-6];
    goto v321;

v321:
    if (v299 == nil) goto v322;
    v300 = stack[-2];
    v299 = stack[-4];
    fn = elt(env, 37); /* symbid */
    v300 = (*qfn2(fn))(qenv(fn), v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[-6];
    v299 = stack[-5];
    {
        popv(7);
        fn = elt(env, 38); /* mksetq */
        return (*qfn2(fn))(qenv(fn), v300, v299);
    }

v322:
    v299 = stack[0];
    v299 = qcdr(v299);
    v299 = qcar(v299);
    v299 = Lsimple_vectorp(nil, v299);
    env = stack[-6];
    if (!(v299 == nil)) goto v323;
    v299 = stack[0];
    v299 = qcdr(v299);
    v300 = qcar(v299);
    v299 = elt(env, 10); /* vecfn */
    v299 = Lflagpcar(nil, v300, v299);
    env = stack[-6];
    if (!(v299 == nil)) goto v323;
    stack[0] = elt(env, 18); /* setk */
    v299 = stack[-2];
    v300 = Lmkquote(nil, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    v299 = stack[-5];
    {
        Lisp_Object v324 = stack[0];
        popv(7);
        return list3(v324, v300, v299);
    }

v323:
    stack[-1] = elt(env, 27); /* setv */
    v299 = stack[-2];
    v300 = Lmkquote(nil, v299);
    nil = C_nil;
    if (exception_pending()) goto v303;
    v299 = stack[0];
    v299 = qcdr(v299);
    v299 = qcar(v299);
    {
        Lisp_Object v325 = stack[-1];
        popv(7);
        return list3(v325, v300, v299);
    }

v320:
    v299 = qvalue(elt(env, 9)); /* t */
    goto v321;

v314:
    v299 = qvalue(elt(env, 6)); /* nil */
    goto v315;
/* error exit handlers */
v303:
    popv(7);
    return nil;
}



/* Code for msolve!-polyn */

static Lisp_Object CC_msolveKpolyn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v333, v292, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-polyn");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v39;
    stack[-9] = v0;
/* end of prologue */
    v333 = stack[-8];
    v333 = qcar(v333);
    stack[-10] = v333;
    v333 = stack[-8];
    v333 = qcdr(v333);
    if (v333 == nil) goto v32;
    v333 = (Lisp_Object)1; /* 0 */
    stack[-7] = v333;
    goto v45;

v45:
    v333 = qvalue(elt(env, 1)); /* current!-modulus */
    v292 = sub1(v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = stack[-7];
    v333 = difference2(v292, v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = Lminusp(nil, v333);
    env = stack[-11];
    if (v333 == nil) goto v27;
    v333 = qvalue(elt(env, 2)); /* nil */
    { popv(12); return onevalue(v333); }

v27:
    stack[0] = stack[-9];
    v292 = stack[-10];
    v333 = stack[-7];
    v333 = cons(v292, v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = ncons(v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    fn = elt(env, 3); /* subf */
    v333 = (*qfn2(fn))(qenv(fn), stack[0], v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v292 = qcar(v333);
    v333 = stack[-8];
    v333 = qcdr(v333);
    v333 = CC_msolveKpolyn(env, v292, v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    stack[-3] = v333;
    v333 = stack[-3];
    if (v333 == nil) goto v160;
    v333 = stack[-3];
    v333 = qcar(v333);
    v167 = stack[-10];
    v292 = stack[-7];
    v333 = acons(v167, v292, v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = ncons(v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    stack[-1] = v333;
    stack[-2] = v333;
    goto v16;

v16:
    v333 = stack[-3];
    v333 = qcdr(v333);
    stack[-3] = v333;
    v333 = stack[-3];
    if (v333 == nil) goto v87;
    stack[0] = stack[-1];
    v333 = stack[-3];
    v333 = qcar(v333);
    v167 = stack[-10];
    v292 = stack[-7];
    v333 = acons(v167, v292, v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = ncons(v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = Lrplacd(nil, stack[0], v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = stack[-1];
    v333 = qcdr(v333);
    stack[-1] = v333;
    goto v16;

v87:
    v333 = stack[-2];
    goto v19;

v19:
    stack[-6] = v333;
    v333 = stack[-6];
    fn = elt(env, 4); /* lastpair */
    v333 = (*qfn1(fn))(qenv(fn), v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    stack[-5] = v333;
    v333 = stack[-7];
    v333 = add1(v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    stack[-7] = v333;
    v333 = stack[-5];
    if (!consp(v333)) goto v45;
    else goto v105;

v105:
    v333 = qvalue(elt(env, 1)); /* current!-modulus */
    v292 = sub1(v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = stack[-7];
    v333 = difference2(v292, v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = Lminusp(nil, v333);
    env = stack[-11];
    if (!(v333 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    stack[0] = stack[-9];
    v292 = stack[-10];
    v333 = stack[-7];
    v333 = cons(v292, v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = ncons(v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    fn = elt(env, 3); /* subf */
    v333 = (*qfn2(fn))(qenv(fn), stack[0], v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v292 = qcar(v333);
    v333 = stack[-8];
    v333 = qcdr(v333);
    v333 = CC_msolveKpolyn(env, v292, v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    stack[-3] = v333;
    v333 = stack[-3];
    if (v333 == nil) goto v175;
    v333 = stack[-3];
    v333 = qcar(v333);
    v167 = stack[-10];
    v292 = stack[-7];
    v333 = acons(v167, v292, v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = ncons(v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    stack[-1] = v333;
    stack[-2] = v333;
    goto v334;

v334:
    v333 = stack[-3];
    v333 = qcdr(v333);
    stack[-3] = v333;
    v333 = stack[-3];
    if (v333 == nil) goto v216;
    stack[0] = stack[-1];
    v333 = stack[-3];
    v333 = qcar(v333);
    v167 = stack[-10];
    v292 = stack[-7];
    v333 = acons(v167, v292, v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = ncons(v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = Lrplacd(nil, stack[0], v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = stack[-1];
    v333 = qcdr(v333);
    stack[-1] = v333;
    goto v334;

v216:
    v333 = stack[-2];
    goto v139;

v139:
    v333 = Lrplacd(nil, stack[-4], v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    v333 = stack[-5];
    fn = elt(env, 4); /* lastpair */
    v333 = (*qfn1(fn))(qenv(fn), v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    stack[-5] = v333;
    v333 = stack[-7];
    v333 = add1(v333);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-11];
    stack[-7] = v333;
    goto v105;

v175:
    v333 = qvalue(elt(env, 2)); /* nil */
    goto v139;

v160:
    v333 = qvalue(elt(env, 2)); /* nil */
    goto v19;

v32:
    v292 = stack[-9];
    v333 = stack[-8];
    v333 = qcar(v333);
    {
        popv(12);
        fn = elt(env, 5); /* msolve!-poly1 */
        return (*qfn2(fn))(qenv(fn), v292, v333);
    }
/* error exit handlers */
v187:
    popv(12);
    return nil;
}



/* Code for basic!-kern */

static Lisp_Object CC_basicKkern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basic-kern");
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
    v98 = v0;
/* end of prologue */
    v145 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v145;
    v145 = v98;
    stack[0] = v145;
    goto v4;

v4:
    v145 = stack[0];
    if (v145 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v145 = stack[0];
    v145 = qcar(v145);
    fn = elt(env, 2); /* basic!-kern1 */
    v98 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    v145 = stack[-1];
    fn = elt(env, 3); /* union */
    v145 = (*qfn2(fn))(qenv(fn), v98, v145);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-2];
    stack[-1] = v145;
    v145 = stack[0];
    v145 = qcdr(v145);
    stack[0] = v145;
    goto v4;
/* error exit handlers */
v24:
    popv(3);
    return nil;
}



/* Code for gitimes!: */

static Lisp_Object CC_gitimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v125, v143, v144;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gitimes:");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v52 = v39;
    v125 = v0;
/* end of prologue */
    v143 = v125;
    v143 = qcdr(v143);
    v144 = qcar(v143);
    v125 = qcdr(v125);
    v143 = qcdr(v125);
    v125 = v52;
    v125 = qcdr(v125);
    v125 = qcar(v125);
    v52 = qcdr(v52);
    v52 = qcdr(v52);
    stack[-5] = v144;
    stack[-4] = v143;
    stack[-3] = v125;
    stack[-2] = v52;
    stack[-1] = elt(env, 1); /* !:gi!: */
    v125 = stack[-5];
    v52 = stack[-3];
    stack[0] = times2(v125, v52);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-6];
    v125 = stack[-4];
    v52 = stack[-2];
    v52 = times2(v125, v52);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-6];
    stack[0] = difference2(stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-6];
    v125 = stack[-5];
    v52 = stack[-2];
    stack[-2] = times2(v125, v52);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-6];
    v125 = stack[-3];
    v52 = stack[-4];
    v52 = times2(v125, v52);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-6];
    v52 = plus2(stack[-2], v52);
    nil = C_nil;
    if (exception_pending()) goto v117;
    {
        Lisp_Object v115 = stack[-1];
        Lisp_Object v116 = stack[0];
        popv(7);
        return list2star(v115, v116, v52);
    }
/* error exit handlers */
v117:
    popv(7);
    return nil;
}



/* Code for pasf_zcong */

static Lisp_Object CC_pasf_zcong(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v338, v294;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_zcong");
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
    v338 = v0;
/* end of prologue */
    v70 = v338;
    v70 = Lconsp(nil, v70);
    env = stack[0];
    if (v70 == nil) { popv(1); return onevalue(v338); }
    v70 = v338;
    v70 = qcar(v70);
    v70 = Lconsp(nil, v70);
    env = stack[0];
    if (v70 == nil) { popv(1); return onevalue(v338); }
    v70 = v338;
    v70 = qcar(v70);
    v294 = qcar(v70);
    v70 = elt(env, 1); /* (cong ncong) */
    v70 = Lmemq(nil, v294, v70);
    if (v70 == nil) { popv(1); return onevalue(v338); }
    v70 = v338;
    v70 = qcar(v70);
    v70 = qcdr(v70);
    if (v70 == nil) goto v14;
    v70 = v338;
    v70 = qcdr(v70);
    v70 = qcar(v70);
    if (v70 == nil) goto v339;
    v70 = qvalue(elt(env, 8)); /* nil */
    goto v185;

v185:
    if (v70 == nil) goto v122;
    v70 = elt(env, 2); /* true */
    { popv(1); return onevalue(v70); }

v122:
    v70 = v338;
    v70 = qcdr(v70);
    v70 = qcar(v70);
    if (v70 == nil) goto v196;
    v70 = qvalue(elt(env, 8)); /* nil */
    goto v177;

v177:
    if (v70 == nil) { popv(1); return onevalue(v338); }
    v70 = elt(env, 4); /* false */
    { popv(1); return onevalue(v70); }

v196:
    v294 = v338;
    v70 = elt(env, 2); /* true */
    if (v294 == v70) goto v197;
    v294 = v338;
    v70 = elt(env, 4); /* false */
    v70 = (v294 == v70 ? lisp_true : nil);
    goto v174;

v174:
    if (v70 == nil) goto v108;
    v70 = v338;
    v294 = v70;
    goto v340;

v340:
    v70 = elt(env, 9); /* ncong */
    v70 = (v294 == v70 ? lisp_true : nil);
    goto v177;

v108:
    v70 = v338;
    v70 = qcar(v70);
    v70 = Lconsp(nil, v70);
    env = stack[0];
    if (v70 == nil) goto v207;
    v70 = v338;
    v70 = qcar(v70);
    v70 = qcar(v70);
    v294 = v70;
    goto v340;

v207:
    v70 = v338;
    v70 = qcar(v70);
    v294 = v70;
    goto v340;

v197:
    v70 = qvalue(elt(env, 3)); /* t */
    goto v174;

v339:
    v294 = v338;
    v70 = elt(env, 2); /* true */
    if (v294 == v70) goto v103;
    v294 = v338;
    v70 = elt(env, 4); /* false */
    v70 = (v294 == v70 ? lisp_true : nil);
    goto v332;

v332:
    if (v70 == nil) goto v155;
    v70 = v338;
    v294 = v70;
    goto v152;

v152:
    v70 = elt(env, 5); /* cong */
    v70 = (v294 == v70 ? lisp_true : nil);
    goto v185;

v155:
    v70 = v338;
    v70 = qcar(v70);
    v70 = Lconsp(nil, v70);
    env = stack[0];
    if (v70 == nil) goto v141;
    v70 = v338;
    v70 = qcar(v70);
    v70 = qcar(v70);
    v294 = v70;
    goto v152;

v141:
    v70 = v338;
    v70 = qcar(v70);
    v294 = v70;
    goto v152;

v103:
    v70 = qvalue(elt(env, 3)); /* t */
    goto v332;

v14:
    v294 = v338;
    v70 = elt(env, 2); /* true */
    if (v294 == v70) goto v124;
    v294 = v338;
    v70 = elt(env, 4); /* false */
    v70 = (v294 == v70 ? lisp_true : nil);
    goto v42;

v42:
    if (v70 == nil) goto v41;
    v70 = v338;
    v294 = v70;
    goto v93;

v93:
    v70 = elt(env, 5); /* cong */
    if (v294 == v70) goto v110;
    v70 = elt(env, 7); /* neq */
    goto v5;

v5:
    v338 = qcdr(v338);
    v338 = qcar(v338);
    v294 = qvalue(elt(env, 8)); /* nil */
    popv(1);
    return list3(v70, v338, v294);

v110:
    v70 = elt(env, 6); /* equal */
    goto v5;

v41:
    v70 = v338;
    v70 = qcar(v70);
    v70 = Lconsp(nil, v70);
    env = stack[0];
    if (v70 == nil) goto v116;
    v70 = v338;
    v70 = qcar(v70);
    v70 = qcar(v70);
    v294 = v70;
    goto v93;

v116:
    v70 = v338;
    v70 = qcar(v70);
    v294 = v70;
    goto v93;

v124:
    v70 = qvalue(elt(env, 3)); /* t */
    goto v42;
}



/* Code for lto_setminus */

static Lisp_Object CC_lto_setminus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v39)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v226, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_setminus");
#endif
    if (stack >= stacklimit)
    {
        push2(v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v39;
    v146 = v0;
/* end of prologue */
    stack[-4] = v146;
    goto v3;

v3:
    v146 = stack[-4];
    if (v146 == nil) goto v32;
    v146 = stack[-4];
    v146 = qcar(v146);
    v160 = v146;
    v226 = v160;
    v146 = stack[-3];
    v146 = Lmember(nil, v226, v146);
    if (v146 == nil) goto v109;
    v146 = nil;
    goto v36;

v36:
    stack[-2] = v146;
    v146 = stack[-2];
    fn = elt(env, 2); /* lastpair */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    stack[-1] = v146;
    v146 = stack[-4];
    v146 = qcdr(v146);
    stack[-4] = v146;
    v146 = stack[-1];
    if (!consp(v146)) goto v3;
    else goto v54;

v54:
    v146 = stack[-4];
    if (v146 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v146 = stack[-4];
    v146 = qcar(v146);
    v160 = v146;
    v226 = v160;
    v146 = stack[-3];
    v146 = Lmember(nil, v226, v146);
    if (v146 == nil) goto v118;
    v146 = nil;
    goto v119;

v119:
    v146 = Lrplacd(nil, stack[0], v146);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    v146 = stack[-1];
    fn = elt(env, 2); /* lastpair */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    stack[-1] = v146;
    v146 = stack[-4];
    v146 = qcdr(v146);
    stack[-4] = v146;
    goto v54;

v118:
    v146 = v160;
    v146 = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    goto v119;

v109:
    v146 = v160;
    v146 = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    goto v36;

v32:
    v146 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v146); }
/* error exit handlers */
v114:
    popv(6);
    return nil;
}



/* Code for fnrd */

static Lisp_Object MS_CDECL CC_fnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnrd");
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
    stack[0] = nil;
    fn = elt(env, 3); /* lex */
    v44 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v131 = qvalue(elt(env, 1)); /* char */
    v44 = elt(env, 2); /* (c i) */
    if (equal(v131, v44)) goto v25;
    v44 = qvalue(elt(env, 1)); /* char */
    v131 = Lcompress(nil, v44);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v44 = (Lisp_Object)321; /* 20 */
    fn = elt(env, 4); /* errorml */
    v44 = (*qfn2(fn))(qenv(fn), v131, v44);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    goto v20;

v20:
    v44 = stack[0];
    if (!(!consp(v44))) goto v38;
    v44 = stack[0];
    v44 = ncons(v44);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    fn = elt(env, 5); /* operator */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    fn = elt(env, 6); /* aeval */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    goto v38;

v38:
    fn = elt(env, 3); /* lex */
    v44 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v110;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v25:
    fn = elt(env, 7); /* mathml2 */
    v44 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    stack[0] = v44;
    goto v20;
/* error exit handlers */
v110:
    popv(2);
    return nil;
}



/* Code for simpimpart */

static Lisp_Object CC_simpimpart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpimpart");
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
    v54 = v0;
/* end of prologue */
    v3 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*factor */
    qvalue(elt(env, 2)) = v3; /* !*factor */
    v3 = v54;
    v3 = qcar(v3);
    fn = elt(env, 3); /* simp!* */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    fn = elt(env, 4); /* impartsq */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*factor */
    { popv(2); return onevalue(v3); }
/* error exit handlers */
v35:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*factor */
    popv(2);
    return nil;
}



/* Code for vdp2a */

static Lisp_Object CC_vdp2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v3 = qcdr(v3);
    v3 = qcdr(v3);
    v3 = qcdr(v3);
    v3 = qcar(v3);
    {
        fn = elt(env, 1); /* dip2a */
        return (*qfn1(fn))(qenv(fn), v3);
    }
}



/* Code for inprinla */

static Lisp_Object MS_CDECL CC_inprinla(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v39,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "inprinla");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inprinla");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v39,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v39,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v40;
    stack[-1] = v39;
    stack[-2] = v0;
/* end of prologue */
    v157 = stack[-2];
    v140 = elt(env, 1); /* alt */
    v140 = get(v157, v140);
    env = stack[-4];
    if (!(v140 == nil)) goto v4;
    v140 = stack[0];
    v157 = qcar(v140);
    v140 = stack[-1];
    fn = elt(env, 5); /* maprintla */
    v140 = (*qfn2(fn))(qenv(fn), v157, v140);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    goto v20;

v20:
    v140 = stack[0];
    v140 = qcdr(v140);
    stack[0] = v140;
    goto v4;

v4:
    v140 = stack[0];
    if (v140 == nil) goto v23;
    v140 = stack[0];
    v140 = qcar(v140);
    if (!consp(v140)) goto v13;
    stack[-3] = stack[-2];
    v140 = stack[0];
    v140 = qcar(v140);
    v157 = qcar(v140);
    v140 = elt(env, 1); /* alt */
    v140 = Lget(nil, v157, v140);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v140 = (stack[-3] == v140 ? lisp_true : nil);
    v140 = (v140 == nil ? lisp_true : nil);
    goto v131;

v131:
    if (v140 == nil) goto v190;
    v140 = stack[-2];
    fn = elt(env, 6); /* oprinla */
    v140 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v140 = stack[0];
    v157 = qcar(v140);
    v140 = elt(env, 4); /* minus */
    if (!consp(v157)) goto v225;
    v157 = qcar(v157);
    if (!(v157 == v140)) goto v225;
    v140 = stack[0];
    v140 = qcar(v140);
    v140 = qcdr(v140);
    v140 = qcar(v140);
    v140 = (is_number(v140) ? lisp_true : nil);
    goto v160;

v160:
    if (v140 == nil) goto v341;
    v140 = stack[0];
    v140 = qcar(v140);
    v140 = qcdr(v140);
    v140 = qcar(v140);
    v140 = negate(v140);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v157 = v140;
    goto v51;

v51:
    v140 = stack[-1];
    fn = elt(env, 5); /* maprintla */
    v140 = (*qfn2(fn))(qenv(fn), v157, v140);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    goto v20;

v341:
    v140 = stack[0];
    v140 = qcar(v140);
    v157 = v140;
    goto v51;

v225:
    v140 = qvalue(elt(env, 2)); /* nil */
    goto v160;

v190:
    v140 = stack[0];
    v157 = qcar(v140);
    v140 = stack[-1];
    fn = elt(env, 5); /* maprintla */
    v140 = (*qfn2(fn))(qenv(fn), v157, v140);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    goto v20;

v13:
    v140 = qvalue(elt(env, 3)); /* t */
    goto v131;

v23:
    v140 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v140); }
/* error exit handlers */
v135:
    popv(5);
    return nil;
}



/* Code for absf */

static Lisp_Object CC_absf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for absf");
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
    v32 = stack[0];
    fn = elt(env, 1); /* minusf */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    if (v32 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v32 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* negf */
        return (*qfn1(fn))(qenv(fn), v32);
    }
/* error exit handlers */
v12:
    popv(2);
    return nil;
}



/* Code for toolongassignp */

static Lisp_Object CC_toolongassignp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for toolongassignp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v4 = qcdr(v4);
    v4 = qcdr(v4);
    v4 = qcar(v4);
    {
        fn = elt(env, 1); /* toolongexpp */
        return (*qfn1(fn))(qenv(fn), v4);
    }
}



setup_type const u27_setup[] =
{
    {"ad_splitname",            CC_ad_splitname,too_many_1,    wrong_no_1},
    {"bfrsq",                   CC_bfrsq,       too_many_1,    wrong_no_1},
    {"mri_prepat",              CC_mri_prepat,  too_many_1,    wrong_no_1},
    {"aex_boundids",            CC_aex_boundids,too_many_1,    wrong_no_1},
    {"crn:prep",                CC_crnTprep,    too_many_1,    wrong_no_1},
    {"look_for_substitute",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_substitute},
    {"band_matrix",             too_few_2,      CC_band_matrix,wrong_no_2},
    {"genexp",                  CC_genexp,      too_many_1,    wrong_no_1},
    {"vdpcondense",             CC_vdpcondense, too_many_1,    wrong_no_1},
    {"r2speclist1",             CC_r2speclist1, too_many_1,    wrong_no_1},
    {"*pf2sq",                  CC_Hpf2sq,      too_many_1,    wrong_no_1},
    {"incident",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_incident},
    {"mo_2a",                   CC_mo_2a,       too_many_1,    wrong_no_1},
    {"ofsf_ignshift",           too_few_2,      CC_ofsf_ignshift,wrong_no_2},
    {"orddf",                   too_few_2,      CC_orddf,      wrong_no_2},
    {"my+nullsq+p",             CC_myLnullsqLp, too_many_1,    wrong_no_1},
    {"aex_freeids",             CC_aex_freeids, too_many_1,    wrong_no_1},
    {"containerml",             too_few_2,      CC_containerml,wrong_no_2},
    {"on-double1",              CC_onKdouble1,  too_many_1,    wrong_no_1},
    {"evmtest?",                too_few_2,      CC_evmtestW,   wrong_no_2},
    {"extadd",                  too_few_2,      CC_extadd,     wrong_no_2},
    {"ofsf_smcpknowl",          CC_ofsf_smcpknowl,too_many_1,  wrong_no_1},
    {"formboollis",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_formboollis},
    {"multdfconst",             too_few_2,      CC_multdfconst,wrong_no_2},
    {"mk+trace",                CC_mkLtrace,    too_many_1,    wrong_no_1},
    {"distribute.multiplicity", too_few_2,      CC_distributeQmultiplicity,wrong_no_2},
    {"ratpoly_quot",            too_few_2,      CC_ratpoly_quot,wrong_no_2},
    {"cgp_lbc",                 CC_cgp_lbc,     too_many_1,    wrong_no_1},
    {"i2cr*",                   CC_i2crH,       too_many_1,    wrong_no_1},
    {"lchk",                    CC_lchk,        too_many_1,    wrong_no_1},
    {"difference:",             too_few_2,      CC_differenceT,wrong_no_2},
    {"rd:difference",           too_few_2,      CC_rdTdifference,wrong_no_2},
    {"prop-simp2",              too_few_2,      CC_propKsimp2, wrong_no_2},
    {"greaterpcdr",             too_few_2,      CC_greaterpcdr,wrong_no_2},
    {"remchkf",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_remchkf},
    {"lpos",                    too_few_2,      CC_lpos,       wrong_no_2},
    {"lessppair",               too_few_2,      CC_lessppair,  wrong_no_2},
    {"giplus:",                 too_few_2,      CC_giplusT,    wrong_no_2},
    {"depend-f",                too_few_2,      CC_dependKf,   wrong_no_2},
    {"pasf_subfof",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_subfof},
    {"omatpir",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_omatpir},
    {"simp_without_resimp",     CC_simp_without_resimp,too_many_1,wrong_no_1},
    {"f2dip11",                 CC_f2dip11,     too_many_1,    wrong_no_1},
    {"wedgef",                  CC_wedgef,      too_many_1,    wrong_no_1},
    {"plubf",                   too_few_2,      CC_plubf,      wrong_no_2},
    {"find_triangl_coeff",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_triangl_coeff},
    {"formsetq0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq0},
    {"msolve-polyn",            too_few_2,      CC_msolveKpolyn,wrong_no_2},
    {"basic-kern",              CC_basicKkern,  too_many_1,    wrong_no_1},
    {"gitimes:",                too_few_2,      CC_gitimesT,   wrong_no_2},
    {"pasf_zcong",              CC_pasf_zcong,  too_many_1,    wrong_no_1},
    {"lto_setminus",            too_few_2,      CC_lto_setminus,wrong_no_2},
    {"fnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnrd},
    {"simpimpart",              CC_simpimpart,  too_many_1,    wrong_no_1},
    {"vdp2a",                   CC_vdp2a,       too_many_1,    wrong_no_1},
    {"inprinla",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_inprinla},
    {"absf",                    CC_absf,        too_many_1,    wrong_no_1},
    {"toolongassignp",          CC_toolongassignp,too_many_1,  wrong_no_1},
    {NULL, (one_args *)"u27", (two_args *)"319 4373299 9502174", 0}
};

/* end of generated code */
