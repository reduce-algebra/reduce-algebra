
/* $destdir\u17.c        Machine generated C code */

/* Signature: 00000000 24-Aug-2011 */

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


/* Code for vdpputprop */

static Lisp_Object MS_CDECL CC_vdpputprop(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24, v25, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdpputprop");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpputprop");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v23 = stack[-3];
    v23 = Lconsp(nil, v23);
    env = stack[-5];
    if (v23 == nil) goto v27;
    v23 = stack[-3];
    v23 = qcdr(v23);
    stack[-4] = v23;
    v23 = Lconsp(nil, v23);
    env = stack[-5];
    if (v23 == nil) goto v28;
    v23 = stack[-4];
    v23 = qcdr(v23);
    stack[-4] = v23;
    v23 = Lconsp(nil, v23);
    env = stack[-5];
    if (v23 == nil) goto v29;
    v23 = stack[-4];
    v23 = qcdr(v23);
    stack[-4] = v23;
    v23 = Lconsp(nil, v23);
    env = stack[-5];
    if (v23 == nil) goto v30;
    v23 = stack[-4];
    v23 = qcdr(v23);
    stack[-4] = v23;
    v23 = Lconsp(nil, v23);
    env = stack[-5];
    v23 = (v23 == nil ? lisp_true : nil);
    goto v31;

v31:
    if (v23 == nil) goto v32;
    v26 = elt(env, 2); /* "vdpputprop given a non-vdp as 1st parameter" 
*/
    v25 = stack[-3];
    v24 = stack[-2];
    v23 = stack[-1];
    v23 = list4(v26, v25, v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v24 = v23;
    v23 = v24;
    qvalue(elt(env, 3)) = v23; /* errmsg!* */
    v23 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v23 == nil)) goto v34;
    v23 = v24;
    fn = elt(env, 5); /* lprie */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    goto v34;

v34:
    v23 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    goto v32;

v32:
    v24 = stack[-2];
    v23 = stack[-4];
    v23 = qcar(v23);
    v23 = Lassoc(nil, v24, v23);
    v24 = v23;
    v23 = v24;
    if (v23 == nil) goto v35;
    v23 = stack[-1];
    v23 = Lrplacd(nil, v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v33;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v35:
    stack[0] = stack[-4];
    v25 = stack[-2];
    v24 = stack[-1];
    v23 = stack[-4];
    v23 = qcar(v23);
    v23 = acons(v25, v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v23 = Lrplaca(nil, stack[0], v23);
    nil = C_nil;
    if (exception_pending()) goto v33;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v30:
    v23 = qvalue(elt(env, 1)); /* t */
    goto v31;

v29:
    v23 = qvalue(elt(env, 1)); /* t */
    goto v31;

v28:
    v23 = qvalue(elt(env, 1)); /* t */
    goto v31;

v27:
    v23 = qvalue(elt(env, 1)); /* t */
    goto v31;
/* error exit handlers */
v33:
    popv(6);
    return nil;
}



/* Code for coposp */

static Lisp_Object CC_coposp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coposp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v0;
/* end of prologue */
    v36 = v37;
    v36 = qcdr(v36);
    if (v36 == nil) goto v8;
    v36 = v37;
    v36 = qcar(v36);
    if (!consp(v36)) goto v31;
    v36 = v37;
    v36 = qcdr(v36);
    {
        fn = elt(env, 2); /* covposp */
        return (*qfn1(fn))(qenv(fn), v36);
    }

v31:
    v36 = v37;
    v36 = qcdr(v36);
    {
        fn = elt(env, 3); /* contposp */
        return (*qfn1(fn))(qenv(fn), v36);
    }

v8:
    v36 = qvalue(elt(env, 1)); /* t */
    return onevalue(v36);
}



/* Code for b_expand2 */

static Lisp_Object MS_CDECL CC_b_expand2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v20, v43, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "b_expand2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b_expand2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v42 = v2;
    v20 = v1;
    v43 = v0;
/* end of prologue */
    v28 = v43;
    v28 = qcar(v28);
    v43 = qcdr(v43);
    {
        fn = elt(env, 1); /* b_expand2b */
        return (*qfnn(fn))(qenv(fn), 4, v28, v43, v20, v42);
    }
}



/* Code for ratminus */

static Lisp_Object CC_ratminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratminus");
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
    v31 = stack[0];
    v31 = qcar(v31);
    v27 = negate(v31);
    nil = C_nil;
    if (exception_pending()) goto v45;
    v31 = stack[0];
    v31 = qcdr(v31);
    popv(1);
    return cons(v27, v31);
/* error exit handlers */
v45:
    popv(1);
    return nil;
}



/* Code for pasf_anegrel */

static Lisp_Object CC_pasf_anegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v50, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_anegrel");
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
    v50 = v29;
    v21 = elt(env, 1); /* ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp) (cong . cong) (ncong . ncong)) 
*/
    v21 = Latsoc(nil, v50, v21);
    v21 = qcdr(v21);
    if (!(v21 == nil)) { popv(1); return onevalue(v21); }
    v21 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v21 == nil)) goto v39;
    v21 = elt(env, 3); /* "pasf_anegrel: unknown operator " */
    v50 = v29;
    v21 = list2(v21, v50);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[0];
    fn = elt(env, 4); /* lprie */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[0];
    goto v39;

v39:
    v21 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v51;
    v21 = nil;
    { popv(1); return onevalue(v21); }
/* error exit handlers */
v51:
    popv(1);
    return nil;
}



/* Code for applyrd */

static Lisp_Object MS_CDECL CC_applyrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "applyrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applyrd");
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
    fn = elt(env, 7); /* lex */
    v15 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    v16 = qvalue(elt(env, 1)); /* atts */
    v15 = elt(env, 2); /* (type definitionurl encoding) */
    fn = elt(env, 8); /* retattributes */
    v15 = (*qfn2(fn))(qenv(fn), v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    qvalue(elt(env, 3)) = v15; /* mmlatts */
    v15 = qvalue(elt(env, 4)); /* char */
    fn = elt(env, 9); /* compress!* */
    v16 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    v15 = qvalue(elt(env, 5)); /* functions!* */
    v15 = Lassoc(nil, v16, v15);
    stack[0] = v15;
    if (v15 == nil) goto v59;
    v15 = stack[0];
    v15 = qcdr(v15);
    v16 = qcar(v15);
    v15 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 10); /* apply */
    v15 = (*qfn2(fn))(qenv(fn), v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    v16 = v15;
    v15 = qvalue(elt(env, 3)); /* mmlatts */
    v15 = cons(v15, v16);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    v16 = v15;
    v15 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 3)) = v15; /* mmlatts */
    v15 = stack[0];
    v15 = qcdr(v15);
    v15 = qcdr(v15);
    v15 = qcar(v15);
    popv(2);
    return cons(v15, v16);

v59:
    v15 = qvalue(elt(env, 4)); /* char */
    v16 = Lcompress(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    v15 = (Lisp_Object)273; /* 17 */
    fn = elt(env, 11); /* errorml */
    v15 = (*qfn2(fn))(qenv(fn), v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v58;
    v15 = nil;
    { popv(2); return onevalue(v15); }
/* error exit handlers */
v58:
    popv(2);
    return nil;
}



/* Code for xdegreecheck */

static Lisp_Object CC_xdegreecheck(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdegreecheck");
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
    v42 = v0;
/* end of prologue */
    v41 = qvalue(elt(env, 1)); /* xtruncate!* */
    if (v41 == nil) goto v8;
    v41 = v42;
    fn = elt(env, 3); /* xdegree */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[0];
    v42 = qvalue(elt(env, 1)); /* xtruncate!* */
        popv(1);
        return Lgreaterp(nil, v41, v42);

v8:
    v41 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v41); }
/* error exit handlers */
v20:
    popv(1);
    return nil;
}



/* Code for testchar1 */

static Lisp_Object CC_testchar1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testchar1");
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
    v62 = stack[0];
    v62 = integerp(v62);
    if (!(v62 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v62 = stack[0];
    v62 = Lexplodec(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v62 = qcdr(v62);
    if (v62 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v63 = stack[0];
    v62 = qvalue(elt(env, 1)); /* nochar!* */
    v62 = Lmember(nil, v63, v62);
    if (!(v62 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v63 = stack[0];
    v62 = qvalue(elt(env, 2)); /* nochar1!* */
    v62 = Lmember(nil, v63, v62);
    if (!(v62 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v63 = stack[0];
    v62 = qvalue(elt(env, 2)); /* nochar1!* */
    v62 = cons(v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    qvalue(elt(env, 2)) = v62; /* nochar1!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v64:
    popv(2);
    return nil;
}



/* Code for !:dmtimeslst */

static Lisp_Object CC_Tdmtimeslst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmtimeslst");
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
    v46 = v0;
/* end of prologue */
    v66 = v46;
    if (v66 == nil) goto v8;
    v66 = v46;
    v66 = qcdr(v66);
    if (v66 == nil) goto v44;
    v66 = v46;
    stack[0] = qcar(v66);
    v66 = v46;
    v66 = qcdr(v66);
    v66 = CC_Tdmtimeslst(env, v66);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-1];
    {
        Lisp_Object v21 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:times */
        return (*qfn2(fn))(qenv(fn), v21, v66);
    }

v44:
    v66 = v46;
    v66 = qcar(v66);
    { popv(2); return onevalue(v66); }

v8:
    v66 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v66); }
/* error exit handlers */
v67:
    popv(2);
    return nil;
}



/* Code for physopsm!* */

static Lisp_Object CC_physopsmH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109, v110, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsm*");
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
    stack[0] = nil;
    v108 = stack[-3];
    if (v108 == nil) goto v38;
    v108 = stack[-3];
    v108 = (is_number(v108) ? lisp_true : nil);
    goto v27;

v27:
    if (v108 == nil) goto v19;
    v108 = stack[-3];
    stack[0] = v108;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v19:
    v108 = stack[-3];
    fn = elt(env, 15); /* physopp */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    if (v108 == nil) goto v36;
    v109 = stack[-3];
    v108 = elt(env, 2); /* rvalue */
    v108 = get(v109, v108);
    env = stack[-5];
    stack[-1] = v108;
    if (v108 == nil) goto v21;
    v108 = stack[-1];
    fn = elt(env, 16); /* physopaeval */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    goto v47;

v47:
    stack[0] = v108;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v21:
    v108 = stack[-3];
    if (symbolp(v108)) goto v113;
    v108 = stack[-3];
    v109 = qcar(v108);
    v108 = elt(env, 3); /* psimpfn */
    v108 = get(v109, v108);
    env = stack[-5];
    stack[-1] = v108;
    if (v108 == nil) goto v14;
    v109 = stack[-1];
    v108 = stack[-3];
    v108 = Lapply1(nil, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    goto v47;

v14:
    v108 = stack[-3];
    v109 = qcar(v108);
    v108 = elt(env, 4); /* opmtch */
    v108 = get(v109, v108);
    env = stack[-5];
    if (v108 == nil) goto v32;
    v108 = stack[-3];
    fn = elt(env, 17); /* opmtch!* */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    stack[-1] = v108;
    if (v108 == nil) goto v32;
    v108 = stack[-1];
    goto v47;

v32:
    v108 = stack[-3];
    goto v47;

v113:
    v108 = stack[-3];
    goto v47;

v36:
    v108 = stack[-3];
    if (!consp(v108)) goto v114;
    v108 = stack[-3];
    v108 = qcar(v108);
    stack[-4] = v108;
    v108 = stack[-3];
    v108 = qcdr(v108);
    stack[-2] = v108;
    v109 = stack[-4];
    v108 = elt(env, 5); /* physopfunction */
    v108 = get(v109, v108);
    env = stack[-5];
    stack[-1] = v108;
    if (v108 == nil) goto v115;
    v109 = stack[-4];
    v108 = elt(env, 6); /* physoparith */
    v108 = Lflagp(nil, v109, v108);
    env = stack[-5];
    if (v108 == nil) goto v116;
    v108 = stack[-2];
    fn = elt(env, 18); /* hasonephysop */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    if (v108 == nil) goto v117;
    stack[0] = stack[-1];
    v108 = stack[-2];
    v108 = ncons(v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    fn = elt(env, 19); /* apply */
    v108 = (*qfn2(fn))(qenv(fn), stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    stack[0] = v108;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v117:
    v109 = stack[-4];
    v108 = stack[-2];
    v108 = cons(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    fn = elt(env, 20); /* reval3 */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    stack[0] = v108;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v116:
    v109 = stack[-4];
    v108 = elt(env, 7); /* physopfn */
    v108 = Lflagp(nil, v109, v108);
    env = stack[-5];
    if (v108 == nil) goto v118;
    v108 = stack[-2];
    fn = elt(env, 21); /* areallphysops */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    if (v108 == nil) goto v119;
    stack[0] = stack[-1];
    v108 = stack[-2];
    v108 = ncons(v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    fn = elt(env, 19); /* apply */
    v108 = (*qfn2(fn))(qenv(fn), stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    stack[0] = v108;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v119:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v111 = elt(env, 8); /* "invalid call of " */
    v110 = stack[-4];
    v109 = elt(env, 9); /* " with args: " */
    v108 = stack[-2];
    v108 = list4(v111, v110, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    fn = elt(env, 22); /* rederr2 */
    v108 = (*qfn2(fn))(qenv(fn), stack[-1], v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v118:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v110 = stack[-4];
    v109 = elt(env, 10); /* " has been flagged Physopfunction" */
    v108 = elt(env, 11); /* " but is not defined" */
    v108 = list3(v110, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    fn = elt(env, 22); /* rederr2 */
    v108 = (*qfn2(fn))(qenv(fn), stack[-1], v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v115:
    v109 = stack[-4];
    v108 = elt(env, 12); /* physopmapping */
    v108 = Lflagp(nil, v109, v108);
    env = stack[-5];
    if (v108 == nil) goto v120;
    v108 = stack[-2];
    fn = elt(env, 23); /* !*physopp!* */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    goto v121;

v121:
    if (v108 == nil) goto v122;
    v109 = stack[-4];
    v108 = stack[-2];
    v110 = cons(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    v109 = (Lisp_Object)17; /* 1 */
    v108 = (Lisp_Object)17; /* 1 */
    v108 = acons(v110, v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    v109 = ncons(v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    v108 = (Lisp_Object)17; /* 1 */
    v108 = cons(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    fn = elt(env, 24); /* mk!*sq */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    stack[0] = v108;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v122:
    v109 = stack[-4];
    v108 = elt(env, 14); /* prog */
    if (v109 == v108) goto v123;
    v108 = stack[-3];
    fn = elt(env, 25); /* aeval */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    stack[0] = v108;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v123:
    v108 = stack[-2];
    fn = elt(env, 26); /* physopprog */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    stack[0] = v108;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v120:
    v108 = qvalue(elt(env, 13)); /* nil */
    goto v121;

v114:
    v108 = stack[-3];
    fn = elt(env, 25); /* aeval */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v112;
    stack[0] = v108;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v38:
    v108 = qvalue(elt(env, 1)); /* t */
    goto v27;
/* error exit handlers */
v112:
    popv(6);
    return nil;
}



/* Code for def_edge */

static Lisp_Object CC_def_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v29, v51, v56;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for def_edge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v56 = v1;
    v50 = v0;
/* end of prologue */
    v50 = qcdr(v50);
    v50 = qcar(v50);
    v51 = v50;
    v50 = v51;
    v29 = qcar(v50);
    v50 = v56;
    v50 = Lassoc(nil, v29, v50);
    if (v50 == nil) goto v125;
    v50 = v51;
    v50 = qcdr(v50);
    v29 = v56;
    v50 = Lassoc(nil, v50, v29);
    return onevalue(v50);

v125:
    v50 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v50);
}



/* Code for mkprogn */

static Lisp_Object CC_mkprogn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v22, v113, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprogn");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v113 = v1;
    v30 = v0;
/* end of prologue */
    v22 = v113;
    v127 = elt(env, 1); /* progn */
    if (!consp(v22)) goto v67;
    v22 = qcar(v22);
    if (!(v22 == v127)) goto v67;
    v127 = elt(env, 1); /* progn */
    v22 = v30;
    v113 = qcdr(v113);
    return list2star(v127, v22, v113);

v67:
    v127 = elt(env, 1); /* progn */
    v22 = v30;
    return list3(v127, v22, v113);
}



/* Code for lienjactest */

static Lisp_Object CC_lienjactest(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v201, v202, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lienjactest");
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
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-11] = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* lie_jtest */
    v200 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 7); /* aeval */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 8); /* setk */
    v200 = (*qfn2(fn))(qenv(fn), stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v200 = (Lisp_Object)17; /* 1 */
    stack[-12] = v200;
    goto v65;

v65:
    stack[0] = elt(env, 2); /* difference */
    v202 = elt(env, 2); /* difference */
    v201 = stack[-11];
    v200 = (Lisp_Object)33; /* 2 */
    v200 = list3(v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v201 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v200 = stack[-12];
    v200 = list3(stack[0], v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    if (v200 == nil) goto v41;
    v200 = nil;
    { popv(14); return onevalue(v200); }

v41:
    v200 = stack[-12];
    v200 = add1(v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-10] = v200;
    goto v205;

v205:
    stack[0] = elt(env, 2); /* difference */
    v202 = elt(env, 2); /* difference */
    v201 = stack[-11];
    v200 = (Lisp_Object)17; /* 1 */
    v200 = list3(v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v201 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v200 = stack[-10];
    v200 = list3(stack[0], v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    if (v200 == nil) goto v206;
    v200 = stack[-12];
    v202 = elt(env, 4); /* plus */
    v201 = v200;
    v200 = (Lisp_Object)17; /* 1 */
    v200 = list3(v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-12] = v200;
    goto v65;

v206:
    v200 = stack[-10];
    v200 = add1(v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-9] = v200;
    goto v207;

v207:
    stack[0] = elt(env, 2); /* difference */
    v200 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v201 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v200 = stack[-9];
    v200 = list3(stack[0], v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    if (v200 == nil) goto v208;
    v200 = stack[-10];
    v202 = elt(env, 4); /* plus */
    v201 = v200;
    v200 = (Lisp_Object)17; /* 1 */
    v200 = list3(v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-10] = v200;
    goto v205;

v208:
    v200 = (Lisp_Object)17; /* 1 */
    stack[-8] = v200;
    goto v209;

v209:
    stack[0] = elt(env, 2); /* difference */
    v200 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v201 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v200 = stack[-8];
    v200 = list3(stack[0], v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    if (v200 == nil) goto v99;
    v200 = stack[-9];
    v202 = elt(env, 4); /* plus */
    v201 = v200;
    v200 = (Lisp_Object)17; /* 1 */
    v200 = list3(v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-9] = v200;
    goto v207;

v99:
    v200 = (Lisp_Object)17; /* 1 */
    stack[-7] = v200;
    v200 = (Lisp_Object)1; /* 0 */
    stack[-6] = v200;
    goto v210;

v210:
    stack[0] = elt(env, 2); /* difference */
    v200 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v201 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v200 = stack[-7];
    v200 = list3(stack[0], v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    if (v200 == nil) goto v211;
    v200 = stack[-6];
    v201 = v200;
    v200 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 11); /* evalneq */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    if (v200 == nil) goto v26;
    stack[0] = elt(env, 1); /* lie_jtest */
    v200 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 9); /* aeval!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 8); /* setk */
    v200 = (*qfn2(fn))(qenv(fn), stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v202 = elt(env, 2); /* difference */
    v201 = stack[-11];
    v200 = (Lisp_Object)17; /* 1 */
    v200 = list3(v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-12] = v200;
    v200 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-10] = v200;
    v202 = elt(env, 4); /* plus */
    v201 = stack[-11];
    v200 = (Lisp_Object)17; /* 1 */
    v200 = list3(v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-9] = v200;
    v202 = elt(env, 4); /* plus */
    v201 = stack[-11];
    v200 = (Lisp_Object)17; /* 1 */
    v200 = list3(v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-8] = v200;
    goto v26;

v26:
    v200 = stack[-8];
    v202 = elt(env, 4); /* plus */
    v201 = v200;
    v200 = (Lisp_Object)17; /* 1 */
    v200 = list3(v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-8] = v200;
    goto v209;

v211:
    stack[-5] = elt(env, 4); /* plus */
    stack[-4] = elt(env, 4); /* plus */
    stack[-1] = elt(env, 5); /* times */
    v203 = elt(env, 6); /* lie_cc */
    v202 = stack[-10];
    v201 = stack[-9];
    v200 = stack[-7];
    stack[0] = list4(v203, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v203 = elt(env, 6); /* lie_cc */
    v202 = stack[-12];
    v201 = stack[-7];
    v200 = stack[-8];
    v200 = list4(v203, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-3] = list3(stack[-1], stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-1] = elt(env, 5); /* times */
    v203 = elt(env, 6); /* lie_cc */
    v202 = stack[-12];
    v201 = stack[-10];
    v200 = stack[-7];
    stack[0] = list4(v203, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v203 = elt(env, 6); /* lie_cc */
    v202 = stack[-9];
    v201 = stack[-7];
    v200 = stack[-8];
    v200 = list4(v203, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-2] = list3(stack[-1], stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-1] = elt(env, 5); /* times */
    v203 = elt(env, 6); /* lie_cc */
    v202 = stack[-9];
    v201 = stack[-12];
    v200 = stack[-7];
    stack[0] = list4(v203, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v203 = elt(env, 6); /* lie_cc */
    v202 = stack[-10];
    v201 = stack[-7];
    v200 = stack[-8];
    v200 = list4(v203, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v200 = list3(stack[-1], stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v200 = list4(stack[-4], stack[-3], stack[-2], v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v201 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    v200 = stack[-6];
    v200 = list3(stack[-5], v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-6] = v200;
    v200 = stack[-7];
    v202 = elt(env, 4); /* plus */
    v201 = v200;
    v200 = (Lisp_Object)17; /* 1 */
    v200 = list3(v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-13];
    stack[-7] = v200;
    goto v210;
/* error exit handlers */
v204:
    popv(14);
    return nil;
}



/* Code for rnprep!: */

static Lisp_Object CC_rnprepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v106, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnprep:");
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
    v126 = stack[-1];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    fn = elt(env, 2); /* prepf */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v107 = v126;
    v126 = stack[-1];
    v126 = qcdr(v126);
    v106 = qcdr(v126);
    v126 = (Lisp_Object)17; /* 1 */
    if (v106 == v126) { popv(4); return onevalue(v107); }
    stack[-2] = elt(env, 1); /* quotient */
    stack[0] = v107;
    v126 = stack[-1];
    v126 = qcdr(v126);
    v126 = qcdr(v126);
    fn = elt(env, 2); /* prepf */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v30;
    {
        Lisp_Object v55 = stack[-2];
        Lisp_Object v60 = stack[0];
        popv(4);
        return list3(v55, v60, v126);
    }
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for di_insert */

static Lisp_Object MS_CDECL CC_di_insert(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v198, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "di_insert");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for di_insert");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v44:
    v199 = stack[-2];
    if (v199 == nil) goto v49;
    v198 = stack[-3];
    v199 = stack[-2];
    v199 = qcar(v199);
    v199 = qcar(v199);
    fn = elt(env, 2); /* eqdummy */
    v199 = (*qfn2(fn))(qenv(fn), v198, v199);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    if (v199 == nil) goto v105;
    v199 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v199;
    v199 = stack[-2];
    v199 = qcdr(v199);
    stack[0] = v199;
    v199 = stack[-2];
    v199 = qcar(v199);
    v213 = qcar(v199);
    v198 = stack[-3];
    v199 = stack[-1];
    v199 = acons(v213, v198, v199);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    stack[-1] = v199;
    v199 = stack[0];
    stack[-2] = v199;
    v199 = stack[-4];
    stack[-3] = v199;
    goto v44;

v105:
    v199 = stack[-2];
    v199 = qcdr(v199);
    stack[-4] = v199;
    v199 = stack[-2];
    v198 = qcar(v199);
    v199 = stack[-1];
    v199 = cons(v198, v199);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    stack[-1] = v199;
    v199 = stack[-4];
    stack[-2] = v199;
    goto v44;

v49:
    v199 = stack[-3];
    if (v199 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v198 = stack[-3];
    v213 = qvalue(elt(env, 1)); /* nil */
    v199 = stack[-1];
    popv(6);
    return acons(v198, v213, v199);
/* error exit handlers */
v214:
    popv(6);
    return nil;
}



/* Code for general!-reduce!-degree!-mod!-p */

static Lisp_Object CC_generalKreduceKdegreeKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v220, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-reduce-degree-mod-p");
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
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v220 = stack[-2];
    v220 = qcar(v220);
    v23 = qcdr(v220);
    v220 = (Lisp_Object)1; /* 0 */
    if (v23 == v220) goto v38;
    v23 = qvalue(elt(env, 1)); /* current!-modulus */
    v220 = stack[-2];
    v220 = qcar(v220);
    v220 = qcdr(v220);
    v220 = difference2(v23, v220);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    stack[0] = v220;
    goto v48;

v48:
    v220 = stack[-1];
    v220 = qcar(v220);
    v220 = qcdr(v220);
    fn = elt(env, 2); /* general!-modular!-reciprocal */
    v220 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    fn = elt(env, 3); /* general!-modular!-times */
    v220 = (*qfn2(fn))(qenv(fn), stack[0], v220);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    stack[-3] = v220;
    v220 = stack[-2];
    v220 = qcar(v220);
    v220 = qcar(v220);
    v23 = qcdr(v220);
    v220 = stack[-1];
    v220 = qcar(v220);
    v220 = qcar(v220);
    v220 = qcdr(v220);
    v220 = (Lisp_Object)(int32_t)((int32_t)v23 - (int32_t)v220 + TAG_FIXNUM);
    stack[0] = v220;
    v23 = stack[0];
    v220 = (Lisp_Object)1; /* 0 */
    if (v23 == v220) goto v222;
    v220 = stack[-2];
    stack[-2] = qcdr(v220);
    v220 = stack[-1];
    v220 = qcar(v220);
    v220 = qcar(v220);
    v220 = qcar(v220);
    fn = elt(env, 4); /* fkern */
    v23 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    v220 = stack[0];
    fn = elt(env, 5); /* getpower */
    v23 = (*qfn2(fn))(qenv(fn), v23, v220);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    v220 = stack[-3];
    v23 = cons(v23, v220);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    v220 = stack[-1];
    v220 = qcdr(v220);
    fn = elt(env, 6); /* general!-times!-term!-mod!-p */
    v220 = (*qfn2(fn))(qenv(fn), v23, v220);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    {
        Lisp_Object v98 = stack[-2];
        popv(5);
        fn = elt(env, 7); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v98, v220);
    }

v222:
    v220 = stack[-2];
    stack[0] = qcdr(v220);
    v220 = stack[-1];
    v23 = qcdr(v220);
    v220 = stack[-3];
    fn = elt(env, 8); /* general!-multiply!-by!-constant!-mod!-p */
    v220 = (*qfn2(fn))(qenv(fn), v23, v220);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    {
        Lisp_Object v99 = stack[0];
        popv(5);
        fn = elt(env, 7); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v99, v220);
    }

v38:
    v220 = stack[-2];
    v220 = qcar(v220);
    v220 = qcdr(v220);
    stack[0] = v220;
    goto v48;
/* error exit handlers */
v221:
    popv(5);
    return nil;
}



/* Code for evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_evaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4, v227, v228, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v124:
    v3 = stack[-3];
    if (!consp(v3)) goto v31;
    v3 = stack[-3];
    v3 = qcar(v3);
    v3 = (consp(v3) ? nil : lisp_true);
    goto v19;

v19:
    if (!(v3 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v4 = stack[-1];
    v3 = (Lisp_Object)1; /* 0 */
    if (v4 == v3) goto v28;
    v3 = stack[-2];
    if (v3 == nil) goto v29;
    v3 = stack[-3];
    v3 = qcar(v3);
    v3 = qcar(v3);
    v4 = qcar(v3);
    v3 = stack[-2];
    if (equal(v4, v3)) goto v64;
    v3 = stack[-3];
    v3 = qcar(v3);
    stack[-4] = qcar(v3);
    v3 = stack[-3];
    v3 = qcar(v3);
    v227 = qcdr(v3);
    v4 = stack[-2];
    v3 = stack[-1];
    stack[0] = CC_evaluateKmodKp(env, 3, v227, v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-5];
    v3 = stack[-3];
    v227 = qcdr(v3);
    v4 = stack[-2];
    v3 = stack[-1];
    v3 = CC_evaluateKmodKp(env, 3, v227, v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-5];
    {
        Lisp_Object v195 = stack[-4];
        Lisp_Object v6 = stack[0];
        popv(6);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v195, v6, v3);
    }

v64:
    v3 = stack[-3];
    v3 = qcar(v3);
    v209 = qcdr(v3);
    v3 = stack[-3];
    v3 = qcar(v3);
    v3 = qcar(v3);
    v228 = qcdr(v3);
    v3 = stack[-3];
    v227 = qcdr(v3);
    v4 = stack[-1];
    v3 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v209, v228, v227, v4, v3);
    }

v29:
    v3 = elt(env, 3); /* "Variable=NIL in EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 6); /* errorf */
        return (*qfn1(fn))(qenv(fn), v3);
    }

v28:
    v3 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v3;
    goto v124;

v31:
    v3 = qvalue(elt(env, 1)); /* t */
    goto v19;
/* error exit handlers */
v5:
    popv(6);
    return nil;
}



/* Code for tripleisprolongedby */

static Lisp_Object CC_tripleisprolongedby(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v230;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tripleisprolongedby");
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
    v212 = v0;
/* end of prologue */
    v230 = v212;
    v212 = (Lisp_Object)49; /* 3 */
    v212 = *(Lisp_Object *)((char *)v230 + (CELL-TAG_VECTOR) + ((int32_t)v212/(16/CELL)));
    stack[-1] = v212;
    goto v45;

v45:
    v212 = stack[-1];
    v212 = qcar(v212);
    if (v212 == nil) goto v38;
    v212 = stack[-1];
    v230 = qcar(v212);
    v212 = stack[0];
    v212 = (Lisp_Object)greaterp2(v230, v212);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v212 = v212 ? lisp_true : nil;
    env = stack[-2];
    if (v212 == nil) goto v38;
    v212 = stack[-1];
    v212 = qcdr(v212);
    stack[-1] = v212;
    goto v45;

v38:
    v212 = stack[-1];
    v212 = qcar(v212);
    if (v212 == nil) goto v53;
    v212 = stack[-1];
    v230 = qcar(v212);
    v212 = stack[0];
    if (!(equal(v230, v212))) goto v53;
    v212 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v212); }

v53:
    v212 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v212); }
/* error exit handlers */
v52:
    popv(3);
    return nil;
}



/* Code for simpexpt */

static Lisp_Object CC_simpexpt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v55, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt");
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
    v30 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v30; /* kord!* */
    v30 = stack[0];
    v55 = qcdr(v30);
    v30 = elt(env, 3); /* expt */
    fn = elt(env, 6); /* carx */
    v55 = (*qfn2(fn))(qenv(fn), v55, v30);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    v30 = elt(env, 4); /* simp!* */
    fn = elt(env, 7); /* simpexpon1 */
    v30 = (*qfn2(fn))(qenv(fn), v55, v30);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    v55 = v30;
    v30 = elt(env, 5); /* resimp */
    fn = elt(env, 7); /* simpexpon1 */
    v30 = (*qfn2(fn))(qenv(fn), v55, v30);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    v55 = stack[0];
    v60 = qcar(v55);
    v55 = v30;
    v30 = qvalue(elt(env, 1)); /* nil */
    {
        popv(3);
        fn = elt(env, 8); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v60, v55, v30);
    }
/* error exit handlers */
v63:
    popv(3);
    return nil;
v62:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    popv(3);
    return nil;
}



/* Code for get!*elements */

static Lisp_Object CC_getHelements(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*elements");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */
    v27 = elt(env, 1); /* elems */
    return get(v31, v27);
}



/* Code for qqe_eta!-in!-term */

static Lisp_Object CC_qqe_etaKinKterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_eta-in-term");
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
    v104 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v104;
    v104 = stack[0];
    if (!consp(v104)) goto v125;
    v104 = stack[0];
    fn = elt(env, 3); /* qqe_op */
    v199 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v104 = elt(env, 2); /* (lhead rhead) */
    v104 = Lmemq(nil, v199, v104);
    if (v104 == nil) goto v37;
    v104 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* qqe_eta!-in!-term1 */
        return (*qfn1(fn))(qenv(fn), v104);
    }

v37:
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[0] = v104;
    goto v50;

v50:
    v104 = stack[0];
    if (v104 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v104 = stack[-1];
    if (!(v104 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v104 = stack[0];
    v104 = qcar(v104);
    if (!consp(v104)) goto v30;
    v104 = stack[0];
    v104 = qcar(v104);
    fn = elt(env, 3); /* qqe_op */
    v199 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v104 = elt(env, 2); /* (lhead rhead) */
    v104 = Lmemq(nil, v199, v104);
    if (v104 == nil) goto v17;
    v104 = stack[0];
    v104 = qcar(v104);
    fn = elt(env, 4); /* qqe_eta!-in!-term1 */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    stack[-1] = v104;
    goto v30;

v30:
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[0] = v104;
    goto v50;

v17:
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = CC_qqe_etaKinKterm(env, v104);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    stack[-1] = v104;
    goto v30;

v125:
    v104 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v104); }
/* error exit handlers */
v140:
    popv(3);
    return nil;
}



/* Code for sf2ss */

static Lisp_Object CC_sf2ss(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2ss");
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
    v206 = stack[-1];
    if (!consp(v206)) goto v19;
    v206 = stack[-1];
    v206 = qcar(v206);
    v206 = (consp(v206) ? nil : lisp_true);
    goto v49;

v49:
    if (!(v206 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v206 = stack[-1];
    fn = elt(env, 2); /* searchpl */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-3];
    stack[-2] = v206;
    v206 = stack[-2];
    fn = elt(env, 3); /* qsort */
    stack[0] = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-3];
    v206 = stack[-2];
    v206 = Llength(nil, v206);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-3];
    v206 = cons(stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-3];
    stack[0] = v206;
    v232 = stack[-1];
    fn = elt(env, 4); /* sq2sspl */
    v232 = (*qfn2(fn))(qenv(fn), v232, v206);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-3];
    v206 = (Lisp_Object)17; /* 1 */
    v206 = list2star(stack[0], v232, v206);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 5); /* lx2xx */
        return (*qfn1(fn))(qenv(fn), v206);
    }

v19:
    v206 = qvalue(elt(env, 1)); /* t */
    goto v49;
/* error exit handlers */
v205:
    popv(4);
    return nil;
}



/* Code for ibalp_recalcv */

static Lisp_Object CC_ibalp_recalcv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_recalcv");
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
    v13 = v0;
/* end of prologue */
    stack[-2] = v13;
    goto v11;

v11:
    v13 = stack[-2];
    if (v13 == nil) goto v125;
    v13 = stack[-2];
    v13 = qcar(v13);
    stack[-1] = v13;
    v13 = stack[-1];
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    stack[0] = qcdr(v13);
    v13 = stack[-1];
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v233 = qcar(v13);
    v13 = elt(env, 2); /* 0.05 */
    v13 = difference2(v233, v13);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v13 = (*qfn2(fn))(qenv(fn), stack[0], v13);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-3];
    v13 = stack[-1];
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    stack[0] = qcdr(v13);
    v13 = stack[-1];
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v233 = qcar(v13);
    v13 = elt(env, 2); /* 0.05 */
    v13 = difference2(v233, v13);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v13 = (*qfn2(fn))(qenv(fn), stack[0], v13);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-3];
    v13 = stack[-2];
    v13 = qcdr(v13);
    stack[-2] = v13;
    goto v11;

v125:
    v13 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v13); }
/* error exit handlers */
v234:
    popv(4);
    return nil;
}



/* Code for aex_lc */

static Lisp_Object CC_aex_lc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_lc");
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
    v56 = v1;
    stack[0] = v0;
/* end of prologue */
    v57 = stack[0];
    fn = elt(env, 2); /* aex_mvaroccurtest */
    v56 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    if (v56 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v56 = stack[0];
    fn = elt(env, 3); /* aex_ex */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_lc */
    stack[-1] = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v56 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v126 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v57 = qvalue(elt(env, 1)); /* nil */
    v56 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v22 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v22, v126, v57, v56);
    }
/* error exit handlers */
v127:
    popv(3);
    return nil;
}



/* Code for mchkopt1 */

static Lisp_Object MS_CDECL CC_mchkopt1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v241, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mchkopt1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchkopt1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v2;
    v240 = v1;
    v241 = v0;
/* end of prologue */
    v240 = qcdr(v240);
    v81 = v240;
    if (v240 == nil) goto v49;
    v240 = v81;
    v240 = qcar(v240);
    stack[-3] = v240;
    v240 = v81;
    v240 = qcdr(v240);
    v81 = v240;
    if (v240 == nil) goto v42;
    v240 = v81;
    v240 = qcar(v240);
    stack[-5] = v240;
    v240 = v81;
    v240 = qcdr(v240);
    if (v240 == nil) goto v107;
    v240 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v240); }

v107:
    v81 = stack[-3];
    v240 = elt(env, 2); /* optional */
    v240 = Lflagp(nil, v81, v240);
    env = stack[-6];
    if (v240 == nil) goto v101;
    v240 = stack[-5];
    fn = elt(env, 3); /* mchk */
    v240 = (*qfn2(fn))(qenv(fn), v241, v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    stack[-5] = v240;
    v240 = stack[-5];
    if (v240 == nil) goto v243;
    v240 = stack[-5];
    v240 = qcar(v240);
    v81 = stack[-3];
    v241 = stack[-4];
    v241 = qcar(v241);
    v240 = acons(v81, v241, v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v240 = ncons(v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    stack[-1] = v240;
    stack[-2] = v240;
    goto v64;

v64:
    v240 = stack[-5];
    v240 = qcdr(v240);
    stack[-5] = v240;
    v240 = stack[-5];
    if (v240 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v240 = stack[-5];
    v240 = qcar(v240);
    v81 = stack[-3];
    v241 = stack[-4];
    v241 = qcar(v241);
    v240 = acons(v81, v241, v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v240 = ncons(v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v240 = Lrplacd(nil, stack[0], v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v240 = stack[-1];
    v240 = qcdr(v240);
    stack[-1] = v240;
    goto v64;

v243:
    v240 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v240); }

v101:
    v81 = stack[-5];
    v240 = elt(env, 2); /* optional */
    v240 = Lflagp(nil, v81, v240);
    env = stack[-6];
    if (v240 == nil) goto v118;
    v240 = stack[-3];
    fn = elt(env, 3); /* mchk */
    v240 = (*qfn2(fn))(qenv(fn), v241, v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    stack[-3] = v240;
    v240 = stack[-3];
    if (v240 == nil) goto v244;
    v240 = stack[-3];
    v240 = qcar(v240);
    v81 = stack[-5];
    v241 = stack[-4];
    v241 = qcdr(v241);
    v241 = qcar(v241);
    v240 = acons(v81, v241, v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v240 = ncons(v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    stack[-1] = v240;
    stack[-2] = v240;
    goto v221;

v221:
    v240 = stack[-3];
    v240 = qcdr(v240);
    stack[-3] = v240;
    v240 = stack[-3];
    if (v240 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v240 = stack[-3];
    v240 = qcar(v240);
    v81 = stack[-5];
    v241 = stack[-4];
    v241 = qcdr(v241);
    v241 = qcar(v241);
    v240 = acons(v81, v241, v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v240 = ncons(v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v240 = Lrplacd(nil, stack[0], v240);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v240 = stack[-1];
    v240 = qcdr(v240);
    stack[-1] = v240;
    goto v221;

v244:
    v240 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v240); }

v118:
    v240 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v240); }

v42:
    v240 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v240); }

v49:
    v240 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v240); }
/* error exit handlers */
v242:
    popv(7);
    return nil;
}



/* Code for getdec */

static Lisp_Object CC_getdec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getdec");
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
    v43 = qvalue(elt(env, 1)); /* nil */
    v20 = stack[0];
    fn = elt(env, 2); /* symtabget */
    v20 = (*qfn2(fn))(qenv(fn), v43, v20);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v43 = v20;
    v20 = v43;
    if (!(v20 == nil)) { popv(2); return onevalue(v43); }
    v20 = stack[0];
    fn = elt(env, 3); /* implicitdec */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v43 = v20;
    { popv(2); return onevalue(v43); }
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for meq */

static Lisp_Object CC_meq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v50, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for meq");
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
    v21 = stack[-1];
    fn = elt(env, 2); /* binding */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    v50 = v21;
    v21 = v50;
    if (v21 == nil) goto v37;
    v21 = v50;
    v29 = elt(env, 1); /* unbound */
    if (v21 == v29) goto v37;
    v21 = v50;
    v50 = v21;
    goto v44;

v44:
    v21 = stack[0];
    v21 = (equal(v50, v21) ? lisp_true : nil);
    { popv(3); return onevalue(v21); }

v37:
    v21 = stack[-1];
    v50 = v21;
    goto v44;
/* error exit handlers */
v57:
    popv(3);
    return nil;
}



/* Code for dipprodin1 */

static Lisp_Object MS_CDECL CC_dipprodin1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipprodin1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipprodin1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v245;

v245:
    v59 = stack[0];
    if (v59 == nil) goto v27;
    v212 = stack[-1];
    v59 = stack[0];
    v59 = qcar(v59);
    fn = elt(env, 2); /* evsum */
    v212 = (*qfn2(fn))(qenv(fn), v212, v59);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    v59 = stack[-3];
    v59 = cons(v212, v59);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    stack[-3] = v59;
    v212 = stack[-2];
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = qcar(v59);
    fn = elt(env, 3); /* bcprod */
    v212 = (*qfn2(fn))(qenv(fn), v212, v59);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    v59 = stack[-3];
    v59 = cons(v212, v59);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    stack[-3] = v59;
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = qcdr(v59);
    stack[0] = v59;
    goto v245;

v27:
    v212 = stack[-3];
    v59 = qvalue(elt(env, 1)); /* dipzero */
    {
        popv(5);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v212, v59);
    }
/* error exit handlers */
v17:
    popv(5);
    return nil;
}



/* Code for opmtchrevop */

static Lisp_Object CC_opmtchrevop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opmtchrevop");
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
    v106 = qvalue(elt(env, 1)); /* !*val */
    if (v106 == nil) goto v44;
    v107 = elt(env, 3); /* cons */
    v106 = stack[0];
    v106 = Lsmemq(nil, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    goto v245;

v245:
    if (v106 == nil) goto v46;
    v106 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v106);
    }

v46:
    v106 = stack[0];
    stack[-1] = qcar(v106);
    v106 = stack[0];
    v106 = qcdr(v106);
    fn = elt(env, 5); /* revlis */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    v106 = cons(stack[-1], v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v106);
    }

v44:
    v106 = qvalue(elt(env, 2)); /* t */
    goto v245;
/* error exit handlers */
v113:
    popv(3);
    return nil;
}



/* Code for ordop2 */

static Lisp_Object CC_ordop2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v61, v239, v62, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordop2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v62 = v1;
    v63 = v0;
/* end of prologue */
    v60 = qvalue(elt(env, 1)); /* kord!* */
    v239 = v60;
    goto v124;

v124:
    v60 = v239;
    if (v60 == nil) goto v27;
    v61 = v63;
    v60 = v239;
    v60 = qcar(v60);
    if (v61 == v60) goto v20;
    v61 = v62;
    v60 = v239;
    v60 = qcar(v60);
    if (v61 == v60) goto v50;
    v60 = v239;
    v60 = qcdr(v60);
    v239 = v60;
    goto v124;

v50:
    v60 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v60);

v20:
    v60 = qvalue(elt(env, 2)); /* t */
    return onevalue(v60);

v27:
    v60 = v63;
    v61 = v62;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v60, v61);
    }
}



/* Code for contr */

static Lisp_Object CC_contr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr");
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
    v51 = stack[0];
    if (v51 == nil) goto v125;
    v56 = stack[-1];
    v51 = stack[0];
    v51 = qcar(v51);
    fn = elt(env, 1); /* split!-road */
    v56 = (*qfn2(fn))(qenv(fn), v56, v51);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    v51 = stack[-2];
    v51 = cons(v56, v51);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    stack[-2] = v51;
    v51 = stack[0];
    v51 = qcdr(v51);
    stack[0] = v51;
    goto v124;

v125:
    v51 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v51);
    }
/* error exit handlers */
v107:
    popv(4);
    return nil;
}



/* Code for !*!*a2s */

static Lisp_Object CC_HHa2s(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v249, v250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for **a2s");
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
/* copy arguments values to proper place */
    v249 = v1;
    stack[-3] = v0;
/* end of prologue */
    v249 = stack[-3];
    if (v249 == nil) goto v11;
    v250 = stack[-3];
    v249 = elt(env, 3); /* nochange */
    v249 = Lflagpcar(nil, v250, v249);
    env = stack[-5];
    if (v249 == nil) goto v113;
    v249 = stack[-3];
    v250 = qcar(v249);
    v249 = elt(env, 4); /* getel */
    if (!(v250 == v249)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v113:
    v250 = elt(env, 5); /* random */
    v249 = stack[-3];
    fn = elt(env, 12); /* smember */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    if (v249 == nil) goto v208;
    stack[-4] = elt(env, 6); /* lambda */
    stack[-2] = elt(env, 7); /* (!*uncached) */
    stack[-1] = elt(env, 8); /* progn */
    stack[0] = elt(env, 9); /* (declare (special !*uncached)) */
    v250 = qvalue(elt(env, 10)); /* !*!*a2sfn */
    v249 = stack[-3];
    v249 = list2(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    v249 = list3(stack[-1], stack[0], v249);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    v249 = list3(stack[-4], stack[-2], v249);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    v250 = qvalue(elt(env, 11)); /* t */
    popv(6);
    return list2(v249, v250);

v208:
    v250 = qvalue(elt(env, 10)); /* !*!*a2sfn */
    v249 = stack[-3];
    popv(6);
    return list2(v250, v249);

v11:
    v249 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v249 == nil)) goto v49;
    v249 = elt(env, 2); /* "tell Hearn!!" */
    fn = elt(env, 13); /* lprie */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    goto v49;

v49:
    v249 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v9;
    v249 = nil;
    { popv(6); return onevalue(v249); }
/* error exit handlers */
v9:
    popv(6);
    return nil;
}



/* Code for setelv */

static Lisp_Object CC_setelv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setelv");
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
    stack[-4] = v1;
    v243 = v0;
/* end of prologue */
    v230 = v243;
    stack[-5] = qcar(v230);
    v230 = v243;
    v230 = qcdr(v230);
    stack[-3] = v230;
    v230 = stack[-3];
    if (v230 == nil) goto v66;
    v230 = stack[-3];
    v230 = qcar(v230);
    fn = elt(env, 2); /* reval_without_mod */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    v230 = ncons(v230);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    stack[-1] = v230;
    stack[-2] = v230;
    goto v43;

v43:
    v230 = stack[-3];
    v230 = qcdr(v230);
    stack[-3] = v230;
    v230 = stack[-3];
    if (v230 == nil) goto v22;
    stack[0] = stack[-1];
    v230 = stack[-3];
    v230 = qcar(v230);
    fn = elt(env, 2); /* reval_without_mod */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    v230 = ncons(v230);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    v230 = Lrplacd(nil, stack[0], v230);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    v230 = stack[-1];
    v230 = qcdr(v230);
    stack[-1] = v230;
    goto v43;

v22:
    v230 = stack[-2];
    goto v31;

v31:
    v243 = cons(stack[-5], v230);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    v230 = stack[-4];
    {
        popv(7);
        fn = elt(env, 3); /* setel */
        return (*qfn2(fn))(qenv(fn), v243, v230);
    }

v66:
    v230 = qvalue(elt(env, 1)); /* nil */
    goto v31;
/* error exit handlers */
v14:
    popv(7);
    return nil;
}



/* Code for fs!:times */

static Lisp_Object CC_fsTtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:times");
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
    v62 = stack[-1];
    if (v62 == nil) goto v11;
    v62 = stack[0];
    if (v62 == nil) goto v125;
    v63 = stack[-1];
    v62 = stack[0];
    fn = elt(env, 2); /* fs!:timesterm */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    stack[-2] = v62;
    v63 = stack[-1];
    v62 = (Lisp_Object)49; /* 3 */
    v63 = *(Lisp_Object *)((char *)v63 + (CELL-TAG_VECTOR) + ((int32_t)v62/(16/CELL)));
    v62 = stack[0];
    v62 = CC_fsTtimes(env, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    {
        Lisp_Object v232 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v232, v62);
    }

v125:
    v62 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v62); }

v11:
    v62 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v62); }
/* error exit handlers */
v206:
    popv(4);
    return nil;
}



/* Code for dpmat_coldegs */

static Lisp_Object CC_dpmat_coldegs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dpmat_coldegs");
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
    v49 = v0;
/* end of prologue */
    v19 = v49;
    v49 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v49 = (*qfn2(fn))(qenv(fn), v19, v49);
    errexit();
    v49 = qcar(v49);
    return onevalue(v49);
}



/* Code for st_consolidate */

static Lisp_Object CC_st_consolidate(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v254, v255;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_consolidate");
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
    stack[-1] = nil;
    v254 = stack[-3];
    if (v254 == nil) goto v125;
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = qcar(v254);
    if (is_number(v254)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v254 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v254;
    v254 = stack[-3];
    v254 = qcdr(v254);
    v254 = Lreverse(nil, v254);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    stack[0] = v254;
    goto v36;

v36:
    v254 = stack[0];
    if (v254 == nil) goto v65;
    v254 = stack[0];
    v254 = qcar(v254);
    v254 = CC_st_consolidate(env, v254);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    v255 = v254;
    if (v255 == nil) goto v22;
    v255 = v254;
    v255 = qcdr(v255);
    v255 = qcdr(v255);
    if (v255 == nil) goto v53;
    v255 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v255;
    goto v18;

v18:
    v255 = v254;
    v254 = stack[-1];
    v254 = cons(v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    stack[-1] = v254;
    goto v22;

v22:
    v254 = stack[0];
    v254 = qcdr(v254);
    stack[0] = v254;
    goto v36;

v53:
    v255 = elt(env, 3); /* !* */
    v254 = qcdr(v254);
    v254 = qcar(v254);
    v254 = list2(v255, v254);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    goto v18;

v65:
    v254 = stack[-1];
    if (v254 == nil) goto v116;
    v254 = stack[-1];
    v254 = qcdr(v254);
    if (v254 == nil) goto v114;
    v254 = stack[-2];
    if (v254 == nil) goto v256;
    v254 = stack[-1];
    stack[-4] = v254;
    v254 = stack[-4];
    if (v254 == nil) goto v145;
    v254 = stack[-4];
    v254 = qcar(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    v254 = ncons(v254);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    stack[-1] = v254;
    stack[-2] = v254;
    goto v196;

v196:
    v254 = stack[-4];
    v254 = qcdr(v254);
    stack[-4] = v254;
    v254 = stack[-4];
    if (v254 == nil) goto v257;
    stack[0] = stack[-1];
    v254 = stack[-4];
    v254 = qcar(v254);
    v254 = qcdr(v254);
    v254 = qcar(v254);
    v254 = ncons(v254);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    v254 = Lrplacd(nil, stack[0], v254);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    v254 = stack[-1];
    v254 = qcdr(v254);
    stack[-1] = v254;
    goto v196;

v257:
    v254 = stack[-2];
    goto v197;

v197:
    stack[-1] = v254;
    goto v256;

v256:
    v254 = stack[-3];
    v255 = qcar(v254);
    v254 = stack[-1];
    popv(6);
    return cons(v255, v254);

v145:
    v254 = qvalue(elt(env, 1)); /* nil */
    goto v197;

v114:
    v254 = stack[-1];
    v254 = qcar(v254);
    { popv(6); return onevalue(v254); }

v116:
    v254 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v254); }

v125:
    v254 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v254); }
/* error exit handlers */
v192:
    popv(6);
    return nil;
}



/* Code for reducepowers */

static Lisp_Object CC_reducepowers(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v253;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reducepowers");
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

v8:
    v26 = stack[0];
    if (!consp(v26)) goto v38;
    v26 = stack[0];
    v26 = qcar(v26);
    v26 = (consp(v26) ? nil : lisp_true);
    goto v27;

v27:
    if (v26 == nil) goto v46;
    v26 = qvalue(elt(env, 1)); /* t */
    goto v48;

v48:
    if (!(v26 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v26 = stack[0];
    v26 = qcar(v26);
    v26 = qcar(v26);
    v253 = qcdr(v26);
    v26 = qvalue(elt(env, 2)); /* repowl!* */
    v26 = qcar(v26);
    v26 = qcdr(v26);
    if (equal(v253, v26)) goto v243;
    v26 = stack[0];
    v26 = qcar(v26);
    v26 = qcar(v26);
    stack[-1] = qcar(v26);
    v26 = stack[0];
    v26 = qcar(v26);
    v26 = qcar(v26);
    v253 = qcdr(v26);
    v26 = qvalue(elt(env, 2)); /* repowl!* */
    v26 = qcar(v26);
    v26 = qcdr(v26);
    v253 = difference2(v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    v26 = (Lisp_Object)17; /* 1 */
    v26 = acons(stack[-1], v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    v253 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    v26 = stack[0];
    v26 = qcar(v26);
    v26 = qcdr(v26);
    fn = elt(env, 3); /* multf */
    v253 = (*qfn2(fn))(qenv(fn), v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    v26 = qvalue(elt(env, 2)); /* repowl!* */
    v26 = qcdr(v26);
    fn = elt(env, 3); /* multf */
    v253 = (*qfn2(fn))(qenv(fn), v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    v26 = stack[0];
    v26 = qcdr(v26);
    fn = elt(env, 4); /* addf */
    v26 = (*qfn2(fn))(qenv(fn), v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    stack[0] = v26;
    goto v8;

v243:
    v26 = qvalue(elt(env, 2)); /* repowl!* */
    v253 = qcdr(v26);
    v26 = stack[0];
    v26 = qcar(v26);
    v26 = qcdr(v26);
    fn = elt(env, 3); /* multf */
    v253 = (*qfn2(fn))(qenv(fn), v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    v26 = stack[0];
    v26 = qcdr(v26);
    {
        popv(3);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v253, v26);
    }

v46:
    v26 = stack[0];
    v26 = qcar(v26);
    v26 = qcar(v26);
    v253 = qcdr(v26);
    v26 = qvalue(elt(env, 2)); /* repowl!* */
    v26 = qcar(v26);
    v26 = qcdr(v26);
    v26 = (Lisp_Object)lessp2(v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v99;
    v26 = v26 ? lisp_true : nil;
    env = stack[-2];
    goto v48;

v38:
    v26 = qvalue(elt(env, 1)); /* t */
    goto v27;
/* error exit handlers */
v99:
    popv(3);
    return nil;
}



/* Code for general!-evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKevaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4, v227, v228, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "general-evaluate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-evaluate-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v124:
    v3 = stack[-3];
    if (!consp(v3)) goto v31;
    v3 = stack[-3];
    v3 = qcar(v3);
    v3 = (consp(v3) ? nil : lisp_true);
    goto v19;

v19:
    if (!(v3 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v4 = stack[-1];
    v3 = (Lisp_Object)1; /* 0 */
    if (v4 == v3) goto v28;
    v3 = stack[-2];
    if (v3 == nil) goto v29;
    v3 = stack[-3];
    v3 = qcar(v3);
    v3 = qcar(v3);
    v4 = qcar(v3);
    v3 = stack[-2];
    if (equal(v4, v3)) goto v64;
    v3 = stack[-3];
    v3 = qcar(v3);
    stack[-4] = qcar(v3);
    v3 = stack[-3];
    v3 = qcar(v3);
    v227 = qcdr(v3);
    v4 = stack[-2];
    v3 = stack[-1];
    stack[0] = CC_generalKevaluateKmodKp(env, 3, v227, v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-5];
    v3 = stack[-3];
    v227 = qcdr(v3);
    v4 = stack[-2];
    v3 = stack[-1];
    v3 = CC_generalKevaluateKmodKp(env, 3, v227, v4, v3);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-5];
    {
        Lisp_Object v195 = stack[-4];
        Lisp_Object v6 = stack[0];
        popv(6);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v195, v6, v3);
    }

v64:
    v3 = stack[-3];
    v3 = qcar(v3);
    v209 = qcdr(v3);
    v3 = stack[-3];
    v3 = qcar(v3);
    v3 = qcar(v3);
    v228 = qcdr(v3);
    v3 = stack[-3];
    v227 = qcdr(v3);
    v4 = stack[-1];
    v3 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* general!-horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v209, v228, v227, v4, v3);
    }

v29:
    v3 = elt(env, 3); /* "Variable=NIL in GENERAL-EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 6); /* errorf */
        return (*qfn1(fn))(qenv(fn), v3);
    }

v28:
    v3 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v3;
    goto v124;

v31:
    v3 = qvalue(elt(env, 1)); /* t */
    goto v19;
/* error exit handlers */
v5:
    popv(6);
    return nil;
}



/* Code for rl_bestgaussp */

static Lisp_Object CC_rl_bestgaussp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_bestgaussp");
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
    v49 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bestgaussp!* */
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    {
        Lisp_Object v27 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v27, v49);
    }
/* error exit handlers */
v31:
    popv(2);
    return nil;
}



/* Code for mkpartitions1 */

static Lisp_Object MS_CDECL CC_mkpartitions1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v68,
                         Lisp_Object v8, Lisp_Object v11, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v253, v221, v98;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "mkpartitions1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkpartitions1");
#endif
    if (stack >= stacklimit)
    {
        push6(v11,v8,v68,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v2,v68,v8,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v11;
    stack[-4] = v8;
    stack[-5] = v68;
    stack[-6] = v2;
    stack[-7] = v1;
    stack[-8] = v0;
/* end of prologue */

v40:
    v253 = stack[-7];
    v26 = (Lisp_Object)17; /* 1 */
    if (v253 == v26) goto v67;
    v253 = stack[-6];
    v26 = stack[-5];
    v26 = (Lisp_Object)greaterp2(v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    v26 = v26 ? lisp_true : nil;
    env = stack[-10];
    if (!(v26 == nil)) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v253 = stack[-8];
    v26 = stack[-6];
    v26 = difference2(v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-10];
    stack[-9] = v26;
    v26 = stack[-7];
    v26 = sub1(v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-10];
    stack[-2] = v26;
    v253 = stack[-8];
    v26 = stack[-6];
    stack[0] = difference2(v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-10];
    v26 = stack[-7];
    v26 = sub1(v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-10];
    v26 = quot2(stack[0], v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-10];
    stack[-1] = v26;
    v253 = stack[-6];
    v26 = stack[-4];
    v26 = cons(v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-10];
    stack[0] = v26;
    v26 = stack[-6];
    v98 = add1(v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-10];
    v221 = stack[-5];
    v253 = stack[-4];
    v26 = stack[-3];
    v26 = CC_mkpartitions1(env, 6, stack[-8], stack[-7], v98, v221, v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-10];
    stack[-3] = v26;
    v26 = stack[0];
    stack[-4] = v26;
    v26 = stack[-1];
    stack[-5] = v26;
    v26 = stack[-2];
    stack[-7] = v26;
    v26 = stack[-9];
    stack[-8] = v26;
    goto v40;

v67:
    v253 = stack[-8];
    v26 = stack[-6];
    v26 = (Lisp_Object)geq2(v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    v26 = v26 ? lisp_true : nil;
    env = stack[-10];
    if (v26 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v253 = stack[-8];
    v26 = stack[-4];
    v26 = cons(v253, v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-10];
    v253 = Lreverse(nil, v26);
    nil = C_nil;
    if (exception_pending()) goto v261;
    v26 = stack[-3];
    popv(11);
    return cons(v253, v26);
/* error exit handlers */
v261:
    popv(11);
    return nil;
}



/* Code for tayexp!-times2 */

static Lisp_Object CC_tayexpKtimes2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v163, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-times2");
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
    v166 = stack[-1];
    if (!consp(v166)) goto v125;
    v166 = qvalue(elt(env, 1)); /* nil */
    goto v44;

v44:
    if (v166 == nil) goto v36;
    v163 = stack[-1];
    v166 = stack[0];
    popv(4);
    return times2(v163, v166);

v36:
    v166 = stack[-1];
    if (!consp(v166)) goto v29;
    v166 = stack[0];
    if (!consp(v166)) goto v198;
    v166 = stack[-1];
    v166 = qcdr(v166);
    v163 = qcar(v166);
    v166 = stack[0];
    v166 = qcdr(v166);
    v166 = qcar(v166);
    stack[-2] = times2(v163, v166);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-3];
    v166 = stack[-1];
    v166 = qcdr(v166);
    v163 = qcdr(v166);
    v166 = stack[0];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = times2(v163, v166);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-3];
    fn = elt(env, 3); /* mkrn */
    v166 = (*qfn2(fn))(qenv(fn), stack[-2], v166);
    nil = C_nil;
    if (exception_pending()) goto v236;
    goto v46;

v46:
    v119 = v166;
    v166 = v119;
    v166 = qcdr(v166);
    v163 = qcdr(v166);
    v166 = (Lisp_Object)17; /* 1 */
    if (!(v163 == v166)) { popv(4); return onevalue(v119); }
    v166 = v119;
    v166 = qcdr(v166);
    v166 = qcar(v166);
    { popv(4); return onevalue(v166); }

v198:
    v119 = elt(env, 2); /* !:rn!: */
    v163 = stack[0];
    v166 = (Lisp_Object)17; /* 1 */
    v166 = list2star(v119, v163, v166);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-3];
    stack[-2] = v166;
    v166 = stack[-1];
    v166 = qcdr(v166);
    v163 = qcar(v166);
    v166 = stack[-2];
    v166 = qcdr(v166);
    v166 = qcar(v166);
    stack[0] = times2(v163, v166);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-3];
    v166 = stack[-1];
    v166 = qcdr(v166);
    v163 = qcdr(v166);
    v166 = stack[-2];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = times2(v163, v166);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-3];
    fn = elt(env, 3); /* mkrn */
    v166 = (*qfn2(fn))(qenv(fn), stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v236;
    goto v46;

v29:
    v119 = elt(env, 2); /* !:rn!: */
    v163 = stack[-1];
    v166 = (Lisp_Object)17; /* 1 */
    v166 = list2star(v119, v163, v166);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-3];
    stack[-2] = v166;
    v166 = stack[-2];
    v166 = qcdr(v166);
    v163 = qcar(v166);
    v166 = stack[0];
    v166 = qcdr(v166);
    v166 = qcar(v166);
    stack[-1] = times2(v163, v166);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-3];
    v166 = stack[-2];
    v166 = qcdr(v166);
    v163 = qcdr(v166);
    v166 = stack[0];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = times2(v163, v166);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-3];
    fn = elt(env, 3); /* mkrn */
    v166 = (*qfn2(fn))(qenv(fn), stack[-1], v166);
    nil = C_nil;
    if (exception_pending()) goto v236;
    goto v46;

v125:
    v166 = stack[0];
    v166 = (consp(v166) ? nil : lisp_true);
    goto v44;
/* error exit handlers */
v236:
    popv(4);
    return nil;
}



/* Code for ibalp_negateat */

static Lisp_Object CC_ibalp_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_negateat");
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
    v39 = stack[-1];
    fn = elt(env, 1); /* ibalp_op */
    stack[-2] = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v39 = stack[-1];
    fn = elt(env, 2); /* ibalp_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v39 = stack[-1];
    fn = elt(env, 3); /* ibalp_arg2r */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    fn = elt(env, 4); /* ibalp_negatet */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    {
        Lisp_Object v43 = stack[-2];
        Lisp_Object v28 = stack[0];
        popv(4);
        fn = elt(env, 5); /* ibalp_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v43, v28, v39);
    }
/* error exit handlers */
v20:
    popv(4);
    return nil;
}



/* Code for cgp_number */

static Lisp_Object CC_cgp_number(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_number");
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
    v49 = v0;
/* end of prologue */
    v19 = v49;
    v49 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v49 = (*qfn2(fn))(qenv(fn), v19, v49);
    errexit();
    v49 = qcar(v49);
    return onevalue(v49);
}



/* Code for crprimp */

static Lisp_Object CC_crprimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v60, v61;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crprimp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v61 = v0;
/* end of prologue */
    v60 = v61;
    v55 = (Lisp_Object)17; /* 1 */
    if (v60 == v55) goto v8;
    v60 = v61;
    v55 = (Lisp_Object)-15; /* -1 */
    if (v60 == v55) goto v65;
    v55 = elt(env, 3); /* times */
    v60 = v61;
    v61 = elt(env, 1); /* i */
    return list3(v55, v60, v61);

v65:
    v55 = elt(env, 2); /* minus */
    v60 = elt(env, 1); /* i */
    return list2(v55, v60);

v8:
    v55 = elt(env, 1); /* i */
    return onevalue(v55);
}



/* Code for pfordp */

static Lisp_Object CC_pfordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v219, v205, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pfordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v219 = v1;
    v205 = v0;
/* end of prologue */

v11:
    v53 = v205;
    if (v53 == nil) goto v44;
    v53 = v219;
    if (v53 == nil) goto v45;
    v53 = v205;
    v53 = qcar(v53);
    v59 = qcar(v53);
    v53 = v219;
    v53 = qcar(v53);
    v53 = qcar(v53);
    if (v59 == v53) goto v231;
    v53 = v205;
    v53 = qcar(v53);
    v53 = qcar(v53);
    v219 = qcar(v219);
    v219 = qcar(v219);
    {
        fn = elt(env, 2); /* termordp */
        return (*qfn2(fn))(qenv(fn), v53, v219);
    }

v231:
    v53 = v205;
    v53 = qcdr(v53);
    v205 = v53;
    v53 = v219;
    v53 = qcdr(v53);
    v219 = v53;
    goto v11;

v45:
    v53 = v205;
    v53 = qcar(v53);
    v219 = qcar(v53);
    v53 = (Lisp_Object)17; /* 1 */
        return Lneq(nil, v219, v53);

v44:
    v53 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v53);
}



/* Code for r2findindex */

static Lisp_Object CC_r2findindex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v38, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2findindex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v1;
    v38 = v0;
/* end of prologue */
    v45 = v38;
    v38 = v27;
    v27 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 1); /* r2findindex1 */
        return (*qfnn(fn))(qenv(fn), 3, v45, v38, v27);
    }
}



/* Code for inttovec!-solve */

static Lisp_Object CC_inttovecKsolve(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v217;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec-solve");
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
/* copy arguments values to proper place */
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v217 = stack[-2];
    v10 = (Lisp_Object)1; /* 0 */
    if (v217 == v10) goto v125;
    v217 = stack[-3];
    v10 = (Lisp_Object)17; /* 1 */
    v10 = (v217 == v10 ? lisp_true : nil);
    goto v44;

v44:
    if (v10 == nil) goto v126;
    v217 = stack[-2];
    v10 = (Lisp_Object)1; /* 0 */
    popv(6);
    return cons(v217, v10);

v126:
    v10 = (Lisp_Object)1; /* 0 */
    stack[-4] = v10;
    v10 = (Lisp_Object)17; /* 1 */
    stack[0] = v10;
    goto v62;

v62:
    v10 = stack[0];
    stack[-1] = v10;
    v10 = stack[-4];
    v10 = add1(v10);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-5];
    stack[-4] = v10;
    v217 = stack[-3];
    v10 = stack[-4];
    v217 = plus2(v217, v10);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-5];
    v10 = stack[-1];
    v217 = times2(v217, v10);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-5];
    v10 = stack[-4];
    v10 = quot2(v217, v10);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-5];
    stack[0] = v10;
    v217 = stack[0];
    v10 = stack[-2];
    v10 = (Lisp_Object)greaterp2(v217, v10);
    nil = C_nil;
    if (exception_pending()) goto v218;
    v10 = v10 ? lisp_true : nil;
    env = stack[-5];
    if (v10 == nil) goto v62;
    stack[0] = stack[-4];
    v217 = stack[-2];
    v10 = stack[-1];
    v10 = difference2(v217, v10);
    nil = C_nil;
    if (exception_pending()) goto v218;
    {
        Lisp_Object v223 = stack[0];
        popv(6);
        return cons(v223, v10);
    }

v125:
    v10 = qvalue(elt(env, 1)); /* t */
    goto v44;
/* error exit handlers */
v218:
    popv(6);
    return nil;
}



/* Code for rd!:times */

static Lisp_Object CC_rdTtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v167, v267;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:times");
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
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v115 = qvalue(elt(env, 1)); /* nil */
    v167 = v115;
    v115 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v115 == nil) goto v49;
    v115 = qvalue(elt(env, 1)); /* nil */
    goto v48;

v48:
    if (v115 == nil) goto v212;
    v115 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v115, v167);

v212:
    v167 = stack[-1];
    v115 = stack[0];
    fn = elt(env, 8); /* convprc2 */
    v115 = (*qfn2(fn))(qenv(fn), v167, v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    stack[-3] = v115;
    v115 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v115;
    v115 = stack[-3];
    if (!consp(v115)) goto v207;
    v167 = stack[-3];
    v115 = stack[-2];
    fn = elt(env, 9); /* csl_timbf */
    v115 = (*qfn2(fn))(qenv(fn), v167, v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    goto v14;

v14:
    v167 = v115;
    v115 = v167;
    if (!(!consp(v115))) { popv(5); return onevalue(v167); }
    v115 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v115, v167);

v207:
    stack[-1] = elt(env, 5); /* times2 */
    v115 = stack[-3];
    stack[0] = Lmkquote(nil, v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    v115 = stack[-2];
    v115 = Lmkquote(nil, v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    v267 = list3(stack[-1], stack[0], v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    v167 = qvalue(elt(env, 1)); /* nil */
    v115 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 10); /* errorset */
    v115 = (*qfnn(fn))(qenv(fn), 3, v267, v167, v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    v167 = v115;
    v115 = v167;
    if (!consp(v115)) goto v4;
    v115 = v167;
    v115 = qcdr(v115);
    goto v3;

v3:
    if (v115 == nil) goto v240;
    fn = elt(env, 11); /* rndbfon */
    v115 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    v115 = stack[-3];
    v115 = Lfloatp(nil, v115);
    env = stack[-4];
    if (v115 == nil) goto v263;
    v115 = stack[-3];
    fn = elt(env, 12); /* fl2bf */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    stack[0] = v115;
    goto v220;

v220:
    v115 = stack[-2];
    v115 = Lfloatp(nil, v115);
    env = stack[-4];
    if (v115 == nil) goto v166;
    v115 = stack[-2];
    fn = elt(env, 12); /* fl2bf */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    goto v23;

v23:
    fn = elt(env, 9); /* csl_timbf */
    v115 = (*qfn2(fn))(qenv(fn), stack[0], v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    goto v14;

v166:
    v115 = stack[-2];
    if (!consp(v115)) goto v236;
    v115 = stack[-2];
    goto v269;

v269:
    fn = elt(env, 13); /* csl_normbf */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    goto v23;

v236:
    v115 = stack[-2];
    v115 = integerp(v115);
    if (v115 == nil) goto v270;
    v267 = elt(env, 3); /* !:rd!: */
    v167 = stack[-2];
    v115 = (Lisp_Object)1; /* 0 */
    v115 = list2star(v267, v167, v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    goto v269;

v270:
    v115 = stack[-2];
    fn = elt(env, 14); /* read!:num */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    goto v269;

v263:
    v115 = stack[-3];
    if (!consp(v115)) goto v244;
    v115 = stack[-3];
    goto v157;

v157:
    fn = elt(env, 13); /* csl_normbf */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    stack[0] = v115;
    goto v220;

v244:
    v115 = stack[-3];
    v115 = integerp(v115);
    if (v115 == nil) goto v271;
    v267 = elt(env, 3); /* !:rd!: */
    v167 = stack[-3];
    v115 = (Lisp_Object)1; /* 0 */
    v115 = list2star(v267, v167, v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    goto v157;

v271:
    v115 = stack[-3];
    fn = elt(env, 14); /* read!:num */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    goto v157;

v240:
    v115 = v167;
    v115 = qcar(v115);
    goto v14;

v4:
    v115 = qvalue(elt(env, 7)); /* t */
    goto v3;

v49:
    v115 = stack[-1];
    v115 = qcdr(v115);
    if (!consp(v115)) goto v45;
    v115 = qvalue(elt(env, 1)); /* nil */
    goto v48;

v45:
    v115 = stack[0];
    v115 = qcdr(v115);
    if (!consp(v115)) goto v66;
    v115 = qvalue(elt(env, 1)); /* nil */
    goto v48;

v66:
    v115 = stack[-1];
    v167 = qcdr(v115);
    v115 = stack[0];
    v115 = qcdr(v115);
    fn = elt(env, 15); /* safe!-fp!-times */
    v115 = (*qfn2(fn))(qenv(fn), v167, v115);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    v167 = v115;
    goto v48;
/* error exit handlers */
v268:
    popv(5);
    return nil;
}



/* Code for factorial */

static Lisp_Object CC_factorial(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factorial");
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
    v239 = stack[0];
    v239 = integerp(v239);
    if (v239 == nil) goto v44;
    v62 = stack[0];
    v239 = (Lisp_Object)1; /* 0 */
    v239 = (Lisp_Object)lessp2(v62, v239);
    nil = C_nil;
    if (exception_pending()) goto v231;
    v239 = v239 ? lisp_true : nil;
    env = stack[-1];
    goto v245;

v245:
    if (v239 == nil) goto v30;
    v62 = stack[0];
    v239 = elt(env, 2); /* "invalid factorial argument" */
    v239 = list2(v62, v239);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-1];
    v62 = v239;
    v239 = v62;
    qvalue(elt(env, 3)) = v239; /* errmsg!* */
    v239 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v239 == nil)) goto v57;
    v239 = v62;
    fn = elt(env, 5); /* lprie */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-1];
    goto v57;

v57:
    v239 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v231;
    v239 = nil;
    { popv(2); return onevalue(v239); }

v30:
    v239 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); /* nfactorial */
        return (*qfn1(fn))(qenv(fn), v239);
    }

v44:
    v239 = qvalue(elt(env, 1)); /* t */
    goto v245;
/* error exit handlers */
v231:
    popv(2);
    return nil;
}



/* Code for setel1 */

static Lisp_Object MS_CDECL CC_setel1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v68, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v272, v260, v207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setel1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setel1");
#endif
    if (stack >= stacklimit)
    {
        push4(v68,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v68);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v68;
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v245:
    v272 = stack[-2];
    v272 = qcar(v272);
    v272 = integerp(v272);
    if (v272 == nil) goto v45;
    v272 = stack[-2];
    v260 = qcar(v272);
    v272 = stack[0];
    v272 = qcar(v272);
    v272 = (Lisp_Object)geq2(v260, v272);
    nil = C_nil;
    if (exception_pending()) goto v216;
    v272 = v272 ? lisp_true : nil;
    env = stack[-4];
    if (!(v272 == nil)) goto v65;
    v272 = stack[-2];
    v260 = qcar(v272);
    v272 = (Lisp_Object)1; /* 0 */
    v272 = (Lisp_Object)lessp2(v260, v272);
    nil = C_nil;
    if (exception_pending()) goto v216;
    v272 = v272 ? lisp_true : nil;
    env = stack[-4];
    if (!(v272 == nil)) goto v65;
    v272 = stack[-2];
    v272 = qcdr(v272);
    if (v272 == nil) goto v52;
    v260 = stack[-3];
    v272 = stack[-2];
    v272 = qcar(v272);
    v272 = *(Lisp_Object *)((char *)v260 + (CELL-TAG_VECTOR) + ((int32_t)v272/(16/CELL)));
    stack[-3] = v272;
    v272 = stack[-2];
    v272 = qcdr(v272);
    stack[-2] = v272;
    v272 = stack[0];
    v272 = qcdr(v272);
    stack[0] = v272;
    goto v245;

v52:
    v207 = stack[-3];
    v272 = stack[-2];
    v260 = qcar(v272);
    v272 = stack[-1];
    *(Lisp_Object *)((char *)v207 + (CELL-TAG_VECTOR) + ((int32_t)v260/(16/CELL))) = v272;
    { popv(5); return onevalue(v272); }

v65:
    v272 = elt(env, 2); /* "Array out of bounds" */
    v260 = v272;
    v272 = v260;
    qvalue(elt(env, 3)) = v272; /* errmsg!* */
    v272 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v272 == nil)) goto v206;
    v272 = v260;
    fn = elt(env, 5); /* lprie */
    v272 = (*qfn1(fn))(qenv(fn), v272);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    goto v206;

v206:
    v272 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v216;
    v272 = nil;
    { popv(5); return onevalue(v272); }

v45:
    v272 = stack[-2];
    v260 = qcar(v272);
    v272 = elt(env, 1); /* "array index" */
    {
        popv(5);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v260, v272);
    }
/* error exit handlers */
v216:
    popv(5);
    return nil;
}



/* Code for cl_atml1 */

static Lisp_Object CC_cl_atml1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atml1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v48 = v0;
/* end of prologue */
    v49 = v48;
    v48 = elt(env, 1); /* cl_atmlc */
    {
        fn = elt(env, 2); /* cl_f2ml */
        return (*qfn2(fn))(qenv(fn), v49, v48);
    }
}



/* Code for mksq */

static Lisp_Object CC_mksq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v149, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksq");
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
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v151 = qvalue(elt(env, 1)); /* subfg!* */
    if (v151 == nil) goto v125;
    v149 = stack[-4];
    v151 = qvalue(elt(env, 2)); /* wtl!* */
    v151 = Lassoc(nil, v149, v151);
    stack[-2] = v151;
    if (v151 == nil) goto v40;
    stack[0] = elt(env, 3); /* k!* */
    v149 = stack[-3];
    v151 = stack[-2];
    v151 = qcdr(v151);
    v151 = times2(v149, v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v151 = CC_mksq(env, stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-2] = v151;
    v151 = qcar(v151);
    if (v151 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    else goto v40;

v40:
    v151 = stack[-4];
    if (!consp(v151)) goto v62;
    v151 = qvalue(elt(env, 4)); /* !*nosubs */
    if (v151 == nil) goto v180;
    v151 = qvalue(elt(env, 6)); /* nil */
    goto v179;

v179:
    if (!(v151 == nil)) goto v49;
    stack[0] = elt(env, 7); /* used!* */
    v151 = stack[-4];
    fn = elt(env, 16); /* fkern */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-5] = v151;
    v151 = qcdr(v151);
    v151 = qcdr(v151);
    v151 = Lmemq(nil, stack[0], v151);
    if (!(v151 == nil)) goto v44;
    stack[0] = stack[-5];
    v151 = elt(env, 7); /* used!* */
    v151 = ncons(v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v151 = Lnconc(nil, stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    goto v44;

v44:
    v151 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v151 == nil)) goto v125;
    v149 = stack[-3];
    v151 = (Lisp_Object)17; /* 1 */
    if (v149 == v151) goto v125;
    v149 = stack[-4];
    v151 = qvalue(elt(env, 8)); /* asymplis!* */
    v151 = Lassoc(nil, v149, v151);
    stack[-1] = v151;
    if (v151 == nil) goto v253;
    v151 = stack[-1];
    v149 = qcdr(v151);
    v151 = stack[-3];
    v151 = (Lisp_Object)lesseq2(v149, v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    v151 = v151 ? lisp_true : nil;
    env = stack[-6];
    if (v151 == nil) goto v253;
    v149 = qvalue(elt(env, 6)); /* nil */
    v151 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v149, v151);

v253:
    v149 = stack[-4];
    v151 = qvalue(elt(env, 9)); /* powlis!* */
    v151 = Lassoc(nil, v149, v151);
    stack[-1] = v151;
    if (!(v151 == nil)) goto v237;
    v151 = stack[-4];
    if (!consp(v151)) goto v287;
    v151 = stack[-4];
    v149 = qcar(v151);
    v151 = elt(env, 10); /* (expt sqrt) */
    v151 = Lmemq(nil, v149, v151);
    if (v151 == nil) goto v288;
    v151 = stack[-4];
    v151 = qcdr(v151);
    v149 = qcar(v151);
    v151 = qvalue(elt(env, 9)); /* powlis!* */
    v151 = Lassoc(nil, v149, v151);
    stack[-1] = v151;
    goto v157;

v157:
    if (!(v151 == nil)) goto v237;

v125:
    v151 = stack[-5];
    if (!(v151 == nil)) goto v84;
    v151 = stack[-4];
    fn = elt(env, 16); /* fkern */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-5] = v151;
    goto v84;

v84:
    v149 = stack[-5];
    v151 = stack[-3];
    fn = elt(env, 17); /* getpower */
    v149 = (*qfn2(fn))(qenv(fn), v149, v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v151 = (Lisp_Object)17; /* 1 */
    v151 = cons(v149, v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v149 = ncons(v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v151 = (Lisp_Object)17; /* 1 */
    v151 = cons(v149, v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-5] = v151;
    v151 = stack[-2];
    if (v151 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v149 = stack[-2];
    v151 = stack[-5];
    {
        popv(7);
        fn = elt(env, 18); /* multsq */
        return (*qfn2(fn))(qenv(fn), v149, v151);
    }

v237:
    v149 = stack[-3];
    v151 = stack[-1];
    v151 = qcdr(v151);
    v151 = qcar(v151);
    v149 = times2(v149, v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v151 = (Lisp_Object)1; /* 0 */
    v151 = (Lisp_Object)lessp2(v149, v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    v151 = v151 ? lisp_true : nil;
    env = stack[-6];
    if (!(v151 == nil)) goto v125;
    v151 = qvalue(elt(env, 11)); /* t */
    qvalue(elt(env, 12)) = v151; /* !*sub2 */
    goto v125;

v288:
    v151 = qvalue(elt(env, 6)); /* nil */
    goto v157;

v287:
    v151 = qvalue(elt(env, 6)); /* nil */
    goto v157;

v49:
    v151 = stack[-1];
    v151 = qcdr(v151);
    stack[-1] = v151;
    v151 = qvalue(elt(env, 15)); /* !*resubs */
    if (!(v151 == nil)) goto v289;
    v151 = qvalue(elt(env, 11)); /* t */
    qvalue(elt(env, 4)) = v151; /* !*nosubs */
    goto v289;

v289:
    v151 = stack[-1];
    v151 = qcar(v151);
    fn = elt(env, 19); /* simp */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-5] = v151;
    v151 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 4)) = v151; /* !*nosubs */
    v149 = stack[-5];
    v151 = stack[-3];
    {
        popv(7);
        fn = elt(env, 20); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v149, v151);
    }

v180:
    v151 = stack[-4];
    v151 = qcar(v151);
    if (!consp(v151)) goto v290;
    v151 = qvalue(elt(env, 6)); /* nil */
    goto v179;

v290:
    v151 = stack[-4];
    v149 = qcar(v151);
    v151 = elt(env, 13); /* mksqsubfn */
    v151 = get(v149, v151);
    env = stack[-6];
    stack[-1] = v151;
    if (v151 == nil) goto v74;
    v149 = stack[-1];
    v151 = stack[-4];
    v151 = Lapply1(nil, v149, v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    stack[-1] = v151;
    goto v73;

v73:
    if (!(v151 == nil)) goto v179;
    v150 = stack[-4];
    v151 = stack[-4];
    v149 = qcar(v151);
    v151 = elt(env, 14); /* kvalue */
    v151 = get(v149, v151);
    env = stack[-6];
    v151 = Lassoc(nil, v150, v151);
    stack[-1] = v151;
    goto v179;

v74:
    v151 = qvalue(elt(env, 6)); /* nil */
    goto v73;

v62:
    v151 = qvalue(elt(env, 4)); /* !*nosubs */
    if (v151 == nil) goto v205;
    v151 = qvalue(elt(env, 6)); /* nil */
    goto v206;

v206:
    if (!(v151 == nil)) goto v49;
    v151 = stack[-4];
    if (!(symbolp(v151))) goto v44;
    v151 = stack[-4];
    v149 = ncons(v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    v151 = elt(env, 7); /* used!* */
    v151 = Lflag(nil, v149, v151);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-6];
    goto v44;

v205:
    v149 = stack[-4];
    v151 = elt(env, 5); /* avalue */
    v151 = get(v149, v151);
    env = stack[-6];
    stack[-1] = v151;
    goto v206;
/* error exit handlers */
v286:
    popv(7);
    return nil;
}



/* Code for ofsf_smupdknowl */

static Lisp_Object MS_CDECL CC_ofsf_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v68, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v145, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v68,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v68);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v68;
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v19:
    v217 = stack[-3];
    if (v217 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    v145 = stack[-4];
    v217 = elt(env, 2); /* and */
    if (v145 == v217) goto v20;
    v217 = stack[-3];
    v217 = qcar(v217);
    fn = elt(env, 4); /* ofsf_negateat */
    v217 = (*qfn1(fn))(qenv(fn), v217);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-6];
    goto v42;

v42:
    v145 = v217;
    v217 = stack[-3];
    v217 = qcdr(v217);
    stack[-3] = v217;
    v217 = stack[-1];
    fn = elt(env, 5); /* ofsf_at2ir */
    v217 = (*qfn2(fn))(qenv(fn), v145, v217);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-6];
    v102 = v217;
    v217 = v102;
    v145 = qcar(v217);
    v217 = stack[-2];
    v217 = Lassoc(nil, v145, v217);
    stack[-5] = v217;
    if (v217 == nil) goto v250;
    stack[0] = stack[-5];
    v217 = v102;
    v217 = qcdr(v217);
    v145 = qcar(v217);
    v217 = stack[-5];
    v217 = qcdr(v217);
    fn = elt(env, 6); /* ofsf_sminsert */
    v217 = (*qfn2(fn))(qenv(fn), v145, v217);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-6];
    fn = elt(env, 7); /* setcdr */
    v217 = (*qfn2(fn))(qenv(fn), stack[0], v217);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-6];
    v217 = stack[-5];
    v145 = qcdr(v217);
    v217 = elt(env, 3); /* false */
    if (!(v145 == v217)) goto v19;
    v217 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v217;
    v217 = elt(env, 3); /* false */
    stack[-2] = v217;
    goto v19;

v250:
    v145 = v102;
    v217 = stack[-2];
    v217 = cons(v145, v217);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-6];
    stack[-2] = v217;
    goto v19;

v20:
    v217 = stack[-3];
    v217 = qcar(v217);
    goto v42;
/* error exit handlers */
v4:
    popv(7);
    return nil;
}



/* Code for !*tayexp2q */

static Lisp_Object CC_Htayexp2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v47;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *tayexp2q");
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
    v46 = v0;
/* end of prologue */
    v47 = v46;
    if (!consp(v47)) goto v44;
    v46 = qcdr(v46);
    { popv(1); return onevalue(v46); }

v44:
    v47 = v46;
    v47 = (Lisp_Object)zerop(v47);
    v47 = v47 ? lisp_true : nil;
    env = stack[0];
    if (v47 == nil) goto v42;
    v46 = qvalue(elt(env, 1)); /* nil */
    v47 = v46;
    goto v48;

v48:
    v46 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v47, v46);

v42:
    v47 = v46;
    goto v48;
}



/* Code for mk!+unit!+mat */

static Lisp_Object CC_mkLunitLmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+unit+mat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v124 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* gen!+can!+bas */
        return (*qfn1(fn))(qenv(fn), v124);
    }
}



setup_type const u17_setup[] =
{
    {"vdpputprop",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpputprop},
    {"coposp",                  CC_coposp,      too_many_1,    wrong_no_1},
    {"b_expand2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_b_expand2},
    {"ratminus",                CC_ratminus,    too_many_1,    wrong_no_1},
    {"pasf_anegrel",            CC_pasf_anegrel,too_many_1,    wrong_no_1},
    {"applyrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_applyrd},
    {"xdegreecheck",            CC_xdegreecheck,too_many_1,    wrong_no_1},
    {"testchar1",               CC_testchar1,   too_many_1,    wrong_no_1},
    {":dmtimeslst",             CC_Tdmtimeslst, too_many_1,    wrong_no_1},
    {"physopsm*",               CC_physopsmH,   too_many_1,    wrong_no_1},
    {"def_edge",                too_few_2,      CC_def_edge,   wrong_no_2},
    {"mkprogn",                 too_few_2,      CC_mkprogn,    wrong_no_2},
    {"lienjactest",             CC_lienjactest, too_many_1,    wrong_no_1},
    {"rnprep:",                 CC_rnprepT,     too_many_1,    wrong_no_1},
    {"di_insert",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_di_insert},
    {"general-reduce-degree-mod-p",too_few_2,   CC_generalKreduceKdegreeKmodKp,wrong_no_2},
    {"evaluate-mod-p",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluateKmodKp},
    {"tripleisprolongedby",     too_few_2,      CC_tripleisprolongedby,wrong_no_2},
    {"simpexpt",                CC_simpexpt,    too_many_1,    wrong_no_1},
    {"get*elements",            CC_getHelements,too_many_1,    wrong_no_1},
    {"qqe_eta-in-term",         CC_qqe_etaKinKterm,too_many_1, wrong_no_1},
    {"sf2ss",                   CC_sf2ss,       too_many_1,    wrong_no_1},
    {"ibalp_recalcv",           CC_ibalp_recalcv,too_many_1,   wrong_no_1},
    {"aex_lc",                  too_few_2,      CC_aex_lc,     wrong_no_2},
    {"mchkopt1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchkopt1},
    {"getdec",                  CC_getdec,      too_many_1,    wrong_no_1},
    {"meq",                     too_few_2,      CC_meq,        wrong_no_2},
    {"dipprodin1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipprodin1},
    {"opmtchrevop",             CC_opmtchrevop, too_many_1,    wrong_no_1},
    {"ordop2",                  too_few_2,      CC_ordop2,     wrong_no_2},
    {"contr",                   too_few_2,      CC_contr,      wrong_no_2},
    {"**a2s",                   too_few_2,      CC_HHa2s,      wrong_no_2},
    {"setelv",                  too_few_2,      CC_setelv,     wrong_no_2},
    {"fs:times",                too_few_2,      CC_fsTtimes,   wrong_no_2},
    {"dpmat_coldegs",           CC_dpmat_coldegs,too_many_1,   wrong_no_1},
    {"st_consolidate",          CC_st_consolidate,too_many_1,  wrong_no_1},
    {"reducepowers",            CC_reducepowers,too_many_1,    wrong_no_1},
    {"general-evaluate-mod-p",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_generalKevaluateKmodKp},
    {"rl_bestgaussp",           CC_rl_bestgaussp,too_many_1,   wrong_no_1},
    {"mkpartitions1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkpartitions1},
    {"tayexp-times2",           too_few_2,      CC_tayexpKtimes2,wrong_no_2},
    {"ibalp_negateat",          CC_ibalp_negateat,too_many_1,  wrong_no_1},
    {"cgp_number",              CC_cgp_number,  too_many_1,    wrong_no_1},
    {"crprimp",                 CC_crprimp,     too_many_1,    wrong_no_1},
    {"pfordp",                  too_few_2,      CC_pfordp,     wrong_no_2},
    {"r2findindex",             too_few_2,      CC_r2findindex,wrong_no_2},
    {"inttovec-solve",          too_few_2,      CC_inttovecKsolve,wrong_no_2},
    {"rd:times",                too_few_2,      CC_rdTtimes,   wrong_no_2},
    {"factorial",               CC_factorial,   too_many_1,    wrong_no_1},
    {"setel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setel1},
    {"cl_atml1",                CC_cl_atml1,    too_many_1,    wrong_no_1},
    {"mksq",                    too_few_2,      CC_mksq,       wrong_no_2},
    {"ofsf_smupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smupdknowl},
    {"*tayexp2q",               CC_Htayexp2q,   too_many_1,    wrong_no_1},
    {"mk+unit+mat",             CC_mkLunitLmat, too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u17", (two_args *)"18672 7972346 7515509", 0}
};

/* end of generated code */
