
/* $destdir/u20.c        Machine generated C code */

/* Signature: 00000000 26-Nov-2013 */

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
#define TYPE_FOREIGN        TYPE_SPARE 
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
extern Lisp_Object gchook, resources, callstack, procstack, procmem, trap_time;
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
#define trap_time             BASE[158]
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
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
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
extern void *extract_pointer(Lisp_Object a);
extern Lisp_Object Lencapsulatedp(Lisp_Object nil, Lisp_Object a);
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
#define _pi       ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi  ((12868.0 - 0.036490896206895257)/8192.0)
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
extern Lisp_Object make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_lisp_integer32(int32_t n);
extern Lisp_Object make_lisp_integer64(int64_t n);
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
extern Lisp_Object bytecounts1(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object Lthrow_nil(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object Lthrow_one_value(Lisp_Object env, Lisp_Object a, Lisp_Object b);
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


/* Code for cons_ordp */

static Lisp_Object MS_CDECL CC_cons_ordp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0009, v0010, v0011, v0012;
    Lisp_Object v0005, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cons_ordp");
    va_start(aa, nargs);
    v0004 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cons_ordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0004,v0003,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0009 = v0005;
    v0010 = v0003;
    v0011 = v0004;
/* end of prologue */

v0013:
    v0008 = v0011;
    if (v0008 == nil) goto v0014;
    v0008 = v0010;
    if (v0008 == nil) goto v0015;
    v0008 = v0011;
    v0008 = Lconsp(nil, v0008);
    env = stack[0];
    if (v0008 == nil) goto v0016;
    v0008 = v0010;
    v0008 = Lconsp(nil, v0008);
    env = stack[0];
    if (v0008 == nil) goto v0017;
    v0008 = v0011;
    v0012 = qcar(v0008);
    v0008 = v0010;
    v0008 = qcar(v0008);
    if (equal(v0012, v0008)) goto v0018;
    v0008 = v0011;
    v0008 = qcar(v0008);
    v0011 = v0008;
    v0008 = v0010;
    v0008 = qcar(v0008);
    v0010 = v0008;
    goto v0013;

v0018:
    v0008 = v0011;
    v0008 = qcdr(v0008);
    v0011 = v0008;
    v0008 = v0010;
    v0008 = qcdr(v0008);
    v0010 = v0008;
    goto v0013;

v0017:
    v0008 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0008); }

v0016:
    v0008 = v0010;
    v0008 = Lconsp(nil, v0008);
    env = stack[0];
    if (v0008 == nil) goto v0019;
    v0008 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0008); }

v0019:
    v0008 = v0009;
    v0009 = v0011;
        popv(1);
        return Lapply2(nil, 3, v0008, v0009, v0010);

v0015:
    v0008 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0008); }

v0014:
    v0008 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0008); }
}



/* Code for safe!-modrecip */

static Lisp_Object CC_safeKmodrecip(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0030, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for safe-modrecip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0030 = v0004;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* !*msg */
    qvalue(elt(env, 1)) = nil; /* !*msg */
    stack[0] = qvalue(elt(env, 2)); /* !*protfg */
    qvalue(elt(env, 2)) = nil; /* !*protfg */
    v0029 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v0029; /* !*msg */
    v0029 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 2)) = v0029; /* !*protfg */
    v0031 = v0030;
    v0029 = elt(env, 5); /* !:mod!: */
    if (!consp(v0031)) goto v0032;
    v0031 = qcar(v0031);
    if (!(v0031 == v0029)) goto v0032;
    v0029 = v0030;
    v0029 = qcdr(v0029);
    v0030 = v0029;
    goto v0032;

v0032:
    v0029 = elt(env, 6); /* general!-modular!-reciprocal */
    v0031 = list2(v0029, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    v0030 = qvalue(elt(env, 3)); /* nil */
    v0029 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* errorset */
    v0029 = (*qfnn(fn))(qenv(fn), 3, v0031, v0030, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    stack[-2] = v0029;
    v0029 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 7)) = v0029; /* erfg!* */
    v0029 = stack[-2];
    fn = elt(env, 9); /* errorp */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-3];
    if (v0029 == nil) goto v0034;
    v0029 = qvalue(elt(env, 3)); /* nil */
    goto v0013;

v0013:
    qvalue(elt(env, 2)) = stack[0]; /* !*protfg */
    qvalue(elt(env, 1)) = stack[-1]; /* !*msg */
    { popv(4); return onevalue(v0029); }

v0034:
    v0029 = stack[-2];
    v0029 = qcar(v0029);
    goto v0013;
/* error exit handlers */
v0033:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[0]; /* !*protfg */
    qvalue(elt(env, 1)) = stack[-1]; /* !*msg */
    popv(4);
    return nil;
}



/* Code for mk!+unit!+mat */

static Lisp_Object CC_mkLunitLmat(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+unit+mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0013 = v0004;
/* end of prologue */
    {
        fn = elt(env, 1); /* gen!+can!+bas */
        return (*qfn1(fn))(qenv(fn), v0013);
    }
}



/* Code for mri_pasf2mri */

static Lisp_Object CC_mri_pasf2mri(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_pasf2mri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0037 = v0003;
    v0038 = v0004;
/* end of prologue */
    stack[-1] = v0038;
    stack[0] = elt(env, 1); /* mri_pasf2mriat */
    v0037 = ncons(v0037);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    {
        Lisp_Object v0027 = stack[-1];
        Lisp_Object v0039 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v0027, v0039, v0037);
    }
/* error exit handlers */
v0028:
    popv(3);
    return nil;
}



/* Code for comfac */

static Lisp_Object CC_comfac(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comfac");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0004;
/* end of prologue */
    stack[-3] = nil;
    v0057 = qvalue(elt(env, 1)); /* dmode!* */
    if (!symbolp(v0057)) v0057 = nil;
    else { v0057 = qfastgets(v0057);
           if (v0057 != nil) { v0057 = elt(v0057, 3); /* field */
#ifdef RECORD_GET
             if (v0057 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0057 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0057 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0057 == SPID_NOPROP) v0057 = nil; else v0057 = lisp_true; }}
#endif
    if (v0057 == nil) goto v0059;
    v0057 = stack[-2];
    fn = elt(env, 4); /* lnc */
    v0058 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    stack[-3] = v0058;
    v0057 = (Lisp_Object)17; /* 1 */
    v0057 = Lneq(nil, v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    goto v0036;

v0036:
    if (v0057 == nil) goto v0061;
    v0057 = stack[-3];
    fn = elt(env, 5); /* !:recip */
    v0058 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    v0057 = stack[-2];
    fn = elt(env, 6); /* multd */
    v0057 = (*qfn2(fn))(qenv(fn), v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    stack[-2] = v0057;
    goto v0061;

v0061:
    v0057 = stack[-2];
    v0057 = qcdr(v0057);
    if (v0057 == nil) goto v0024;
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    v0057 = qcdr(v0057);
    stack[-3] = v0057;
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    stack[-1] = v0057;
    goto v0013;

v0013:
    v0057 = stack[-2];
    v0057 = qcdr(v0057);
    stack[-2] = v0057;
    v0058 = stack[-2];
    v0057 = stack[-1];
    fn = elt(env, 7); /* degr */
    v0058 = (*qfn2(fn))(qenv(fn), v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    v0057 = (Lisp_Object)1; /* 0 */
    if (v0058 == v0057) goto v0011;
    v0057 = stack[-2];
    v0057 = qcdr(v0057);
    if (v0057 == nil) goto v0062;
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    v0058 = qcdr(v0057);
    v0057 = stack[-3];
    fn = elt(env, 8); /* gcdf */
    v0057 = (*qfn2(fn))(qenv(fn), v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    stack[-3] = v0057;
    goto v0013;

v0062:
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    stack[0] = qcar(v0057);
    v0058 = stack[-3];
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    v0057 = qcdr(v0057);
    fn = elt(env, 8); /* gcdf */
    v0057 = (*qfn2(fn))(qenv(fn), v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    {
        Lisp_Object v0063 = stack[0];
        popv(5);
        return cons(v0063, v0057);
    }

v0011:
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v0057 = stack[-2];
    if (!consp(v0057)) goto v0064;
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    v0057 = (consp(v0057) ? nil : lisp_true);
    goto v0065;

v0065:
    if (v0057 == nil) goto v0066;
    v0057 = qvalue(elt(env, 3)); /* t */
    goto v0067;

v0067:
    if (v0057 == nil) goto v0068;
    v0058 = stack[-3];
    v0057 = stack[-2];
    fn = elt(env, 8); /* gcdf */
    v0057 = (*qfn2(fn))(qenv(fn), v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    goto v0069;

v0069:
    {
        Lisp_Object v0070 = stack[0];
        popv(5);
        return cons(v0070, v0057);
    }

v0068:
    v0057 = (Lisp_Object)17; /* 1 */
    goto v0069;

v0066:
    v0057 = stack[-1];
    fn = elt(env, 9); /* noncomp */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    if (v0057 == nil) goto v0071;
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    fn = elt(env, 9); /* noncomp */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-4];
    goto v0072;

v0072:
    v0057 = (v0057 == nil ? lisp_true : nil);
    goto v0067;

v0071:
    v0057 = qvalue(elt(env, 2)); /* nil */
    goto v0072;

v0064:
    v0057 = qvalue(elt(env, 3)); /* t */
    goto v0065;

v0024:
    v0057 = stack[-2];
    v0057 = qcar(v0057);
    { popv(5); return onevalue(v0057); }

v0059:
    v0057 = qvalue(elt(env, 2)); /* nil */
    goto v0036;
/* error exit handlers */
v0060:
    popv(5);
    return nil;
}



/* Code for vdp_plist */

static Lisp_Object CC_vdp_plist(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object v0061;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_plist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0061 = v0004;
/* end of prologue */
    v0061 = qcdr(v0061);
    v0061 = qcdr(v0061);
    v0061 = qcdr(v0061);
    v0061 = qcdr(v0061);
    v0061 = qcar(v0061);
    return onevalue(v0061);
}



/* Code for multi_args */

static Lisp_Object CC_multi_args(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multi_args");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
/* end of prologue */
    v0038 = stack[0];
    if (v0038 == nil) goto v0022;
    v0038 = stack[0];
    v0038 = qcar(v0038);
    fn = elt(env, 2); /* expression */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    v0038 = CC_multi_args(env, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    goto v0022;

v0022:
    v0038 = nil;
    { popv(2); return onevalue(v0038); }
/* error exit handlers */
v0016:
    popv(2);
    return nil;
}



/* Code for ps!:expansion!-point */

static Lisp_Object CC_psTexpansionKpoint(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0077, v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:expansion-point");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0078 = v0004;
/* end of prologue */
    v0076 = v0078;
    if (!consp(v0076)) goto v0061;
    v0076 = v0078;
    v0077 = qcar(v0076);
    v0076 = elt(env, 2); /* !:ps!: */
    if (v0077 == v0076) goto v0018;
    v0076 = v0078;
    v0076 = qcar(v0076);
    if (!symbolp(v0076)) v0076 = nil;
    else { v0076 = qfastgets(v0076);
           if (v0076 != nil) { v0076 = elt(v0076, 8); /* dname */
#ifdef RECORD_GET
             if (v0076 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0076 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0076 == SPID_NOPROP) v0076 = nil; }}
#endif
    goto v0079;

v0079:
    if (v0076 == nil) goto v0080;
    v0076 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0076);

v0080:
    v0077 = v0078;
    v0076 = (Lisp_Object)49; /* 3 */
    {
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v0077, v0076);
    }

v0018:
    v0076 = qvalue(elt(env, 3)); /* nil */
    goto v0079;

v0061:
    v0076 = qvalue(elt(env, 1)); /* t */
    goto v0079;
}



/* Code for testredzz */

static Lisp_Object CC_testredzz(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0076;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for testredzz");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0023 = v0004;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0076 = qvalue(elt(env, 2)); /* maxvar */
    v0023 = plus2(v0076, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    v0076 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0023/(16/CELL)));
    v0023 = (Lisp_Object)65; /* 4 */
    v0023 = *(Lisp_Object *)((char *)v0076 + (CELL-TAG_VECTOR) + ((int32_t)v0023/(16/CELL)));
    stack[0] = v0023;
    goto v0022;

v0022:
    v0023 = stack[0];
    if (v0023 == nil) goto v0082;
    v0023 = stack[0];
    v0023 = qcar(v0023);
    v0023 = qcar(v0023);
    fn = elt(env, 4); /* testredh */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    stack[0] = v0023;
    goto v0022;

v0082:
    v0023 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0023); }
/* error exit handlers */
v0078:
    popv(2);
    return nil;
}



/* Code for dipev2f */

static Lisp_Object CC_dipev2f(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipev2f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0004;
/* end of prologue */

v0022:
    v0087 = stack[-1];
    if (v0087 == nil) goto v0061;
    v0087 = stack[-1];
    v0088 = qcar(v0087);
    v0087 = (Lisp_Object)1; /* 0 */
    if (v0088 == v0087) goto v0036;
    v0087 = stack[0];
    v0088 = qcar(v0087);
    v0087 = stack[-1];
    v0087 = qcar(v0087);
    fn = elt(env, 1); /* to */
    v0088 = (*qfn2(fn))(qenv(fn), v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    v0087 = (Lisp_Object)17; /* 1 */
    v0087 = cons(v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    stack[-2] = ncons(v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    v0087 = stack[-1];
    v0088 = qcdr(v0087);
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    v0087 = CC_dipev2f(env, v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    {
        Lisp_Object v0001 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* multf */
        return (*qfn2(fn))(qenv(fn), v0001, v0087);
    }

v0036:
    v0087 = stack[-1];
    v0087 = qcdr(v0087);
    stack[-1] = v0087;
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    stack[0] = v0087;
    goto v0022;

v0061:
    v0087 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0087); }
/* error exit handlers */
v0089:
    popv(4);
    return nil;
}



/* Code for coordp */

static Lisp_Object CC_coordp(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0035;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0090 = v0004;
/* end of prologue */
    v0035 = qvalue(elt(env, 1)); /* coord!* */
    v0090 = Lmemq(nil, v0090, v0035);
    return onevalue(v0090);
}



/* Code for comm1 */

static Lisp_Object CC_comm1(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comm1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
/* end of prologue */
    stack[-1] = nil;
    v0094 = stack[0];
    v0093 = elt(env, 1); /* end */
    if (!(v0094 == v0093)) goto v0059;

v0013:
    fn = elt(env, 8); /* scan */
    v0093 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    goto v0059;

v0059:
    v0094 = qvalue(elt(env, 2)); /* cursym!* */
    v0093 = elt(env, 3); /* !*semicol!* */
    if (v0094 == v0093) goto v0075;
    v0094 = stack[0];
    v0093 = elt(env, 1); /* end */
    if (v0094 == v0093) goto v0096;
    v0093 = qvalue(elt(env, 6)); /* nil */
    goto v0055;

v0055:
    if (v0093 == nil) goto v0097;
    v0093 = qvalue(elt(env, 6)); /* nil */
    { popv(3); return onevalue(v0093); }

v0097:
    v0094 = stack[0];
    v0093 = elt(env, 1); /* end */
    if (v0094 == v0093) goto v0088;
    v0093 = qvalue(elt(env, 6)); /* nil */
    goto v0087;

v0087:
    if (v0093 == nil) goto v0013;
    v0093 = elt(env, 7); /* "END-COMMENT NO LONGER SUPPORTED" */
    v0093 = ncons(v0093);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    fn = elt(env, 9); /* lprim */
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    v0093 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v0093;
    goto v0013;

v0088:
    v0093 = stack[-1];
    v0093 = (v0093 == nil ? lisp_true : nil);
    goto v0087;

v0096:
    v0094 = qvalue(elt(env, 2)); /* cursym!* */
    v0093 = elt(env, 5); /* (end else then until !*rpar!* !*rsqbkt!*) */
    v0093 = Lmemq(nil, v0094, v0093);
    goto v0055;

v0075:
    v0093 = qvalue(elt(env, 4)); /* t */
    goto v0055;
/* error exit handlers */
v0095:
    popv(3);
    return nil;
}



/* Code for fs!:prin1 */

static Lisp_Object CC_fsTprin1(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:prin1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
/* end of prologue */
    v0063 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v0063;
    v0070 = stack[0];
    v0063 = (Lisp_Object)1; /* 0 */
    v0070 = *(Lisp_Object *)((char *)v0070 + (CELL-TAG_VECTOR) + ((int32_t)v0063/(16/CELL)));
    v0063 = elt(env, 2); /* (1 . 1) */
    if (equal(v0070, v0063)) goto v0014;
    v0063 = elt(env, 3); /* "(" */
    fn = elt(env, 12); /* prin2!* */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0070 = stack[0];
    v0063 = (Lisp_Object)1; /* 0 */
    v0063 = *(Lisp_Object *)((char *)v0070 + (CELL-TAG_VECTOR) + ((int32_t)v0063/(16/CELL)));
    fn = elt(env, 13); /* sqprint */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0063 = elt(env, 4); /* ")" */
    fn = elt(env, 12); /* prin2!* */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0014;

v0014:
    v0063 = stack[0];
    fn = elt(env, 14); /* fs!:null!-angle */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    if (v0063 == nil) goto v0092;
    v0070 = stack[0];
    v0063 = (Lisp_Object)1; /* 0 */
    v0070 = *(Lisp_Object *)((char *)v0070 + (CELL-TAG_VECTOR) + ((int32_t)v0063/(16/CELL)));
    v0063 = elt(env, 2); /* (1 . 1) */
    if (!(equal(v0070, v0063))) goto v0024;
    v0063 = elt(env, 11); /* "1" */
    fn = elt(env, 12); /* prin2!* */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    goto v0024;

v0024:
    v0063 = nil;
    { popv(5); return onevalue(v0063); }

v0092:
    v0070 = stack[0];
    v0063 = (Lisp_Object)17; /* 1 */
    v0063 = *(Lisp_Object *)((char *)v0070 + (CELL-TAG_VECTOR) + ((int32_t)v0063/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0063 = elt(env, 5); /* "[" */
    fn = elt(env, 12); /* prin2!* */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0070 = stack[0];
    v0063 = (Lisp_Object)33; /* 2 */
    v0063 = *(Lisp_Object *)((char *)v0070 + (CELL-TAG_VECTOR) + ((int32_t)v0063/(16/CELL)));
    stack[-2] = v0063;
    v0063 = (Lisp_Object)1; /* 0 */
    stack[0] = v0063;
    goto v0012;

v0012:
    v0070 = (Lisp_Object)113; /* 7 */
    v0063 = stack[0];
    v0063 = difference2(v0070, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0063 = Lminusp(nil, v0063);
    env = stack[-4];
    if (v0063 == nil) goto v0112;
    v0063 = elt(env, 10); /* "]" */
    fn = elt(env, 12); /* prin2!* */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    goto v0024;

v0112:
    v0070 = stack[-2];
    v0063 = stack[0];
    v0070 = *(Lisp_Object *)((char *)v0070 + (CELL-TAG_VECTOR) + ((int32_t)v0063/(16/CELL)));
    stack[-1] = v0070;
    v0063 = (Lisp_Object)1; /* 0 */
    if (v0070 == v0063) goto v0050;
    v0070 = stack[-1];
    v0063 = (Lisp_Object)1; /* 0 */
    v0063 = (Lisp_Object)lessp2(v0070, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    v0063 = v0063 ? lisp_true : nil;
    env = stack[-4];
    if (v0063 == nil) goto v0051;
    v0063 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v0063;
    v0063 = elt(env, 7); /* "-" */
    fn = elt(env, 12); /* prin2!* */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0063 = stack[-1];
    v0063 = negate(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-1] = v0063;
    goto v0051;

v0051:
    v0063 = stack[-3];
    if (!(v0063 == nil)) goto v0113;
    v0063 = elt(env, 8); /* "+" */
    fn = elt(env, 12); /* prin2!* */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0113;

v0113:
    v0070 = stack[-1];
    v0063 = (Lisp_Object)17; /* 1 */
    if (v0070 == v0063) goto v0114;
    v0063 = stack[-1];
    fn = elt(env, 12); /* prin2!* */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0114;

v0114:
    v0063 = qvalue(elt(env, 6)); /* nil */
    stack[-3] = v0063;
    v0070 = qvalue(elt(env, 9)); /* fourier!-name!* */
    v0063 = stack[0];
    v0063 = *(Lisp_Object *)((char *)v0070 + (CELL-TAG_VECTOR) + ((int32_t)v0063/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0050;

v0050:
    v0063 = stack[0];
    v0063 = add1(v0063);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[0] = v0063;
    goto v0012;
/* error exit handlers */
v0111:
    popv(5);
    return nil;
}



/* Code for dfprintfn */

static Lisp_Object CC_dfprintfn(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0115, v0116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfprintfn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0031 = v0004;
/* end of prologue */
    v0115 = qvalue(elt(env, 1)); /* !*nat */
    if (v0115 == nil) goto v0061;
    v0115 = qvalue(elt(env, 3)); /* !*fort */
    if (!(v0115 == nil)) goto v0079;
    v0115 = qvalue(elt(env, 4)); /* !*dfprint */
    v0115 = (v0115 == nil ? lisp_true : nil);
    goto v0079;

v0079:
    if (v0115 == nil) goto v0054;
    v0031 = elt(env, 5); /* failed */
    { popv(1); return onevalue(v0031); }

v0054:
    v0115 = elt(env, 6); /* !!df!! */
    v0031 = qcdr(v0031);
    v0116 = cons(v0115, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[0];
    v0115 = (Lisp_Object)1; /* 0 */
    v0031 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 8); /* layout!-formula */
    v0031 = (*qfnn(fn))(qenv(fn), 3, v0116, v0115, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[0];
    v0115 = v0031;
    v0031 = v0115;
    if (v0031 == nil) goto v0096;
    v0031 = v0115;
    fn = elt(env, 9); /* putpline */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    v0031 = nil;
    { popv(1); return onevalue(v0031); }

v0096:
    v0031 = elt(env, 5); /* failed */
    { popv(1); return onevalue(v0031); }

v0061:
    v0115 = qvalue(elt(env, 2)); /* t */
    goto v0079;
/* error exit handlers */
v0117:
    popv(1);
    return nil;
}



/* Code for charnump!: */

static Lisp_Object CC_charnumpT(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0031, v0115, v0116;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for charnump:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v0030 = v0004;
/* end of prologue */
    stack[-6] = v0030;
    stack[-5] = elt(env, 1); /* !0 */
    stack[-4] = elt(env, 2); /* !1 */
    stack[-3] = elt(env, 3); /* !2 */
    stack[-2] = elt(env, 4); /* !3 */
    stack[-1] = elt(env, 5); /* !4 */
    stack[0] = elt(env, 6); /* !5 */
    v0116 = elt(env, 7); /* !6 */
    v0115 = elt(env, 8); /* !7 */
    v0031 = elt(env, 9); /* !8 */
    v0030 = elt(env, 10); /* !9 */
    v0030 = list4(v0116, v0115, v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-7];
    v0030 = list3star(stack[-2], stack[-1], stack[0], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-7];
    v0030 = list3star(stack[-5], stack[-4], stack[-3], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-7];
    v0030 = Lmember(nil, stack[-6], v0030);
    if (v0030 == nil) goto v0022;
    v0030 = qvalue(elt(env, 11)); /* t */
    { popv(8); return onevalue(v0030); }

v0022:
    v0030 = nil;
    { popv(8); return onevalue(v0030); }
/* error exit handlers */
v0097:
    popv(8);
    return nil;
}



/* Code for general!-modular!-expt */

static Lisp_Object CC_generalKmodularKexpt(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0128, v0060, v0063;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-expt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0004;
/* end of prologue */

v0090:
    v0060 = stack[-1];
    v0128 = (Lisp_Object)1; /* 0 */
    if (v0060 == v0128) goto v0039;
    v0060 = stack[0];
    v0128 = (Lisp_Object)1; /* 0 */
    if (v0060 == v0128) goto v0023;
    v0060 = stack[0];
    v0128 = (Lisp_Object)17; /* 1 */
    if (v0060 == v0128) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = stack[0];
    v0128 = qvalue(elt(env, 3)); /* current!-modulus */
    v0128 = sub1(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-3];
    v0128 = (Lisp_Object)geq2(stack[-2], v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    v0128 = v0128 ? lisp_true : nil;
    env = stack[-3];
    if (v0128 == nil) goto v0130;
    v0128 = qvalue(elt(env, 3)); /* current!-modulus */
    fn = elt(env, 5); /* primep */
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-3];
    if (v0128 == nil) goto v0130;
    v0128 = qvalue(elt(env, 3)); /* current!-modulus */
    v0128 = sub1(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-3];
    v0128 = Cremainder(stack[0], v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-3];
    stack[0] = v0128;
    goto v0090;

v0130:
    v0128 = stack[0];
    v0128 = Levenp(nil, v0128);
    env = stack[-3];
    if (v0128 == nil) goto v0131;
    v0060 = stack[0];
    v0128 = (Lisp_Object)33; /* 2 */
    v0128 = quot2(v0060, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-3];
    stack[0] = v0128;
    v0060 = stack[-1];
    v0128 = stack[-1];
    fn = elt(env, 6); /* general!-modular!-times */
    v0128 = (*qfn2(fn))(qenv(fn), v0060, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-3];
    stack[-1] = v0128;
    goto v0130;

v0131:
    v0128 = stack[0];
    fn = elt(env, 7); /* reverse!-num */
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-3];
    stack[0] = v0128;
    v0128 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0128;
    goto v0113;

v0113:
    v0060 = stack[0];
    v0128 = (Lisp_Object)1; /* 0 */
    v0128 = (Lisp_Object)greaterp2(v0060, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    v0128 = v0128 ? lisp_true : nil;
    env = stack[-3];
    if (v0128 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0060 = stack[-2];
    v0128 = stack[-2];
    fn = elt(env, 6); /* general!-modular!-times */
    v0128 = (*qfn2(fn))(qenv(fn), v0060, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-3];
    stack[-2] = v0128;
    v0128 = stack[0];
    v0128 = Levenp(nil, v0128);
    env = stack[-3];
    if (!(v0128 == nil)) goto v0132;
    v0060 = stack[-2];
    v0128 = stack[-1];
    fn = elt(env, 6); /* general!-modular!-times */
    v0128 = (*qfn2(fn))(qenv(fn), v0060, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-3];
    stack[-2] = v0128;
    goto v0132;

v0132:
    v0060 = stack[0];
    v0128 = (Lisp_Object)33; /* 2 */
    v0128 = quot2(v0060, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-3];
    stack[0] = v0128;
    goto v0113;

v0023:
    v0128 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0128); }

v0039:
    v0060 = stack[0];
    v0128 = (Lisp_Object)1; /* 0 */
    if (v0060 == v0128) goto v0018;
    v0128 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v0128); }

v0018:
    v0063 = elt(env, 1); /* alg */
    v0060 = (Lisp_Object)1617; /* 101 */
    v0128 = elt(env, 2); /* "0^0 formed" */
    {
        popv(4);
        fn = elt(env, 8); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0063, v0060, v0128);
    }
/* error exit handlers */
v0129:
    popv(4);
    return nil;
}



/* Code for reverse!-num1 */

static Lisp_Object CC_reverseKnum1(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144, v0145;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reverse-num1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0003;
    stack[0] = v0004;
/* end of prologue */
    v0145 = stack[0];
    v0144 = (Lisp_Object)1; /* 0 */
    if (v0145 == v0144) goto v0022;
    v0145 = stack[-2];
    v0144 = (Lisp_Object)17; /* 1 */
    if (v0145 == v0144) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0145 = stack[-2];
    v0144 = (Lisp_Object)33; /* 2 */
    if (v0145 == v0144) goto v0083;
    v0145 = stack[-2];
    v0144 = (Lisp_Object)49; /* 3 */
    if (v0145 == v0144) goto v0117;
    v0145 = stack[-2];
    v0144 = (Lisp_Object)65; /* 4 */
    if (v0145 == v0144) goto v0093;
    stack[-1] = (Lisp_Object)33; /* 2 */
    v0145 = stack[-2];
    v0144 = (Lisp_Object)33; /* 2 */
    v0144 = quot2(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-4];
    v0144 = Lexpt(nil, stack[-1], v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-4];
    stack[-3] = v0144;
    v0145 = stack[0];
    v0144 = stack[-3];
    v0144 = Ldivide(nil, v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-4];
    stack[-1] = v0144;
    v0144 = stack[-2];
    v0144 = Levenp(nil, v0144);
    env = stack[-4];
    if (!(v0144 == nil)) goto v0102;
    v0145 = stack[-3];
    v0144 = (Lisp_Object)33; /* 2 */
    v0144 = times2(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-4];
    stack[-3] = v0144;
    goto v0102;

v0102:
    v0144 = stack[-1];
    stack[0] = qcdr(v0144);
    v0145 = stack[-2];
    v0144 = (Lisp_Object)33; /* 2 */
    v0144 = quot2(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-4];
    v0145 = CC_reverseKnum1(env, stack[0], v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-4];
    v0144 = stack[-3];
    stack[0] = times2(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-4];
    v0144 = stack[-1];
    stack[-1] = qcar(v0144);
    v0144 = stack[-2];
    v0145 = add1(v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-4];
    v0144 = (Lisp_Object)33; /* 2 */
    v0144 = quot2(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-4];
    v0144 = CC_reverseKnum1(env, stack[-1], v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    {
        Lisp_Object v0147 = stack[0];
        popv(5);
        return plus2(v0147, v0144);
    }

v0093:
    v0145 = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v0144 = stack[0];
    v0144 = *(Lisp_Object *)((char *)v0145 + (CELL-TAG_VECTOR) + ((int32_t)v0144/(16/CELL)));
    { popv(5); return onevalue(v0144); }

v0117:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v0145 = (Lisp_Object)33; /* 2 */
    v0144 = stack[0];
    v0144 = times2(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    v0144 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0144/(16/CELL)));
    { popv(5); return onevalue(v0144); }

v0083:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v0145 = (Lisp_Object)65; /* 4 */
    v0144 = stack[0];
    v0144 = times2(v0145, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    v0144 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0144/(16/CELL)));
    { popv(5); return onevalue(v0144); }

v0022:
    v0144 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v0144); }
/* error exit handlers */
v0146:
    popv(5);
    return nil;
}



/* Code for aex_mvar */

static Lisp_Object CC_aex_mvar(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_mvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0090 = v0004;
/* end of prologue */
    fn = elt(env, 2); /* aex_ex */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* ratpoly_mvar */
        return (*qfn1(fn))(qenv(fn), v0090);
    }
/* error exit handlers */
v0035:
    popv(1);
    return nil;
}



/* Code for inprint */

static Lisp_Object MS_CDECL CC_inprint(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0192, v0193, v0194;
    Lisp_Object fn;
    Lisp_Object v0005, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "inprint");
    va_start(aa, nargs);
    v0004 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inprint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0004,v0003,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0005;
    stack[-2] = v0003;
    stack[-3] = v0004;
/* end of prologue */
    stack[-4] = nil;
    stack[0] = nil;
    v0193 = stack[-3];
    v0192 = elt(env, 1); /* times */
    if (v0193 == v0192) goto v0037;
    v0192 = qvalue(elt(env, 3)); /* nil */
    goto v0074;

v0074:
    if (v0192 == nil) goto v0000;
    v0192 = elt(env, 5); /* times2 */
    stack[-3] = v0192;
    v0194 = elt(env, 5); /* times2 */
    v0193 = elt(env, 6); /* infix */
    v0192 = elt(env, 1); /* times */
    if (!symbolp(v0192)) v0192 = nil;
    else { v0192 = qfastgets(v0192);
           if (v0192 != nil) { v0192 = elt(v0192, 23); /* infix */
#ifdef RECORD_GET
             if (v0192 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0192 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0192 == SPID_NOPROP) v0192 = nil; }}
#endif
    v0192 = Lputprop(nil, 3, v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0194 = elt(env, 5); /* times2 */
    v0193 = elt(env, 7); /* prtch */
    v0192 = elt(env, 8); /* " " */
    v0192 = Lputprop(nil, 3, v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    goto v0000;

v0000:
    v0193 = stack[-3];
    v0192 = elt(env, 9); /* plus */
    if (v0193 == v0192) goto v0089;
    v0192 = qvalue(elt(env, 3)); /* nil */
    goto v0196;

v0196:
    if (v0192 == nil) goto v0087;
    v0192 = stack[-1];
    v0192 = Lreverse(nil, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    stack[-1] = v0192;
    goto v0087;

v0087:
    v0192 = stack[-3];
    if (!symbolp(v0192)) v0192 = nil;
    else { v0192 = qfastgets(v0192);
           if (v0192 != nil) { v0192 = elt(v0192, 49); /* alt */
#ifdef RECORD_GET
             if (v0192 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v0192 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v0192 == SPID_NOPROP) v0192 = nil; }}
#endif
    if (!(v0192 == nil)) goto v0094;
    v0193 = stack[-3];
    v0192 = elt(env, 11); /* not */
    if (v0193 == v0192) goto v0064;
    v0193 = stack[-3];
    v0192 = elt(env, 12); /* setq */
    if (v0193 == v0192) goto v0197;
    v0192 = qvalue(elt(env, 3)); /* nil */
    goto v0071;

v0071:
    if (v0192 == nil) goto v0065;
    v0194 = stack[0];
    v0192 = stack[-1];
    v0193 = qcar(v0192);
    v0192 = stack[-4];
        popv(6);
        return Lapply2(nil, 3, v0194, v0193, v0192);

v0065:
    v0192 = stack[-1];
    v0192 = qcar(v0192);
    if (!consp(v0192)) goto v0198;
    v0192 = stack[-1];
    v0192 = qcar(v0192);
    v0192 = qcar(v0192);
    if (symbolp(v0192)) goto v0199;
    v0192 = qvalue(elt(env, 3)); /* nil */
    goto v0200;

v0200:
    if (v0192 == nil) goto v0201;
    v0192 = elt(env, 16); /* "(" */
    fn = elt(env, 22); /* prin2!* */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0192 = stack[-1];
    v0193 = qcar(v0192);
    v0192 = stack[-2];
    fn = elt(env, 23); /* maprint */
    v0192 = (*qfn2(fn))(qenv(fn), v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0192 = elt(env, 17); /* ")" */
    fn = elt(env, 22); /* prin2!* */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    goto v0202;

v0202:
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    goto v0094;

v0094:
    v0192 = qvalue(elt(env, 18)); /* !*nosplit */
    if (v0192 == nil) goto v0203;
    v0192 = qvalue(elt(env, 19)); /* testing!-width!* */
    if (!(v0192 == nil)) goto v0203;
    v0192 = stack[-1];
    stack[-1] = v0192;
    goto v0204;

v0204:
    v0192 = stack[-1];
    if (v0192 == nil) goto v0205;
    v0192 = stack[-1];
    v0192 = qcar(v0192);
    stack[0] = v0192;
    v0192 = stack[0];
    if (!consp(v0192)) goto v0206;
    v0193 = stack[-3];
    v0192 = stack[0];
    v0192 = qcar(v0192);
    if (!symbolp(v0192)) v0192 = nil;
    else { v0192 = qfastgets(v0192);
           if (v0192 != nil) { v0192 = elt(v0192, 49); /* alt */
#ifdef RECORD_GET
             if (v0192 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v0192 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v0192 == SPID_NOPROP) v0192 = nil; }}
#endif
    v0192 = (v0193 == v0192 ? lisp_true : nil);
    v0192 = (v0192 == nil ? lisp_true : nil);
    goto v0207;

v0207:
    if (v0192 == nil) goto v0208;
    v0193 = stack[-3];
    v0192 = elt(env, 21); /* (setq !*comma!*) */
    v0192 = Lmemq(nil, v0193, v0192);
    if (v0192 == nil) goto v0209;
    v0192 = stack[-3];
    fn = elt(env, 24); /* oprin */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0192 = stack[0];
    fn = elt(env, 25); /* negnumberchk */
    v0194 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0193 = stack[-2];
    v0192 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 26); /* prinfit */
    v0192 = (*qfnn(fn))(qenv(fn), 3, v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    goto v0210;

v0210:
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    goto v0204;

v0209:
    v0192 = stack[0];
    fn = elt(env, 25); /* negnumberchk */
    v0194 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0193 = stack[-2];
    v0192 = stack[-3];
    fn = elt(env, 26); /* prinfit */
    v0192 = (*qfnn(fn))(qenv(fn), 3, v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    goto v0210;

v0208:
    v0194 = stack[0];
    v0193 = stack[-2];
    v0192 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 26); /* prinfit */
    v0192 = (*qfnn(fn))(qenv(fn), 3, v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    goto v0210;

v0206:
    v0192 = qvalue(elt(env, 20)); /* t */
    goto v0207;

v0205:
    v0192 = nil;
    { popv(6); return onevalue(v0192); }

v0203:
    v0192 = stack[-1];
    stack[-1] = v0192;
    goto v0211;

v0211:
    v0192 = stack[-1];
    if (v0192 == nil) goto v0205;
    v0192 = stack[-1];
    v0192 = qcar(v0192);
    stack[0] = v0192;
    v0192 = stack[0];
    if (!consp(v0192)) goto v0212;
    v0193 = stack[-3];
    v0192 = stack[0];
    v0192 = qcar(v0192);
    if (!symbolp(v0192)) v0192 = nil;
    else { v0192 = qfastgets(v0192);
           if (v0192 != nil) { v0192 = elt(v0192, 49); /* alt */
#ifdef RECORD_GET
             if (v0192 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v0192 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v0192 == SPID_NOPROP) v0192 = nil; }}
#endif
    v0192 = (v0193 == v0192 ? lisp_true : nil);
    v0192 = (v0192 == nil ? lisp_true : nil);
    goto v0213;

v0213:
    if (v0192 == nil) goto v0214;
    v0192 = stack[-3];
    fn = elt(env, 24); /* oprin */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0192 = stack[0];
    fn = elt(env, 25); /* negnumberchk */
    v0193 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0192 = stack[-2];
    fn = elt(env, 23); /* maprint */
    v0192 = (*qfn2(fn))(qenv(fn), v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    goto v0215;

v0215:
    v0192 = stack[-1];
    v0192 = qcdr(v0192);
    stack[-1] = v0192;
    goto v0211;

v0214:
    v0193 = stack[0];
    v0192 = stack[-2];
    fn = elt(env, 23); /* maprint */
    v0192 = (*qfn2(fn))(qenv(fn), v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    goto v0215;

v0212:
    v0192 = qvalue(elt(env, 20)); /* t */
    goto v0213;

v0201:
    v0192 = qvalue(elt(env, 18)); /* !*nosplit */
    if (v0192 == nil) goto v0216;
    v0192 = qvalue(elt(env, 19)); /* testing!-width!* */
    if (!(v0192 == nil)) goto v0216;
    v0192 = stack[-1];
    v0194 = qcar(v0192);
    v0193 = stack[-2];
    v0192 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 26); /* prinfit */
    v0192 = (*qfnn(fn))(qenv(fn), 3, v0194, v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    goto v0202;

v0216:
    v0192 = stack[-1];
    v0193 = qcar(v0192);
    v0192 = stack[-2];
    fn = elt(env, 23); /* maprint */
    v0192 = (*qfn2(fn))(qenv(fn), v0193, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    goto v0202;

v0199:
    v0192 = qvalue(elt(env, 2)); /* !*nat */
    if (v0192 == nil) goto v0217;
    v0192 = stack[-1];
    v0192 = qcar(v0192);
    v0192 = qcar(v0192);
    if (!symbolp(v0192)) v0192 = nil;
    else { v0192 = qfastgets(v0192);
           if (v0192 != nil) { v0192 = elt(v0192, 57); /* prifn */
#ifdef RECORD_GET
             if (v0192 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v0192 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v0192 == SPID_NOPROP) v0192 = nil; }}
#endif
    stack[-4] = v0192;
    if (!(v0192 == nil)) goto v0218;
    v0192 = stack[-1];
    v0192 = qcar(v0192);
    v0192 = qcar(v0192);
    if (!symbolp(v0192)) v0192 = nil;
    else { v0192 = qfastgets(v0192);
           if (v0192 != nil) { v0192 = elt(v0192, 60); /* pprifn */
#ifdef RECORD_GET
             if (v0192 != SPID_NOPROP)
                record_get(elt(fastget_names, 60), 1);
             else record_get(elt(fastget_names, 60), 0),
                v0192 = nil; }
           else record_get(elt(fastget_names, 60), 0); }
#else
             if (v0192 == SPID_NOPROP) v0192 = nil; }}
#endif
    stack[-4] = v0192;
    if (!(v0192 == nil)) goto v0218;
    v0192 = qvalue(elt(env, 3)); /* nil */
    goto v0200;

v0218:
    v0193 = stack[-4];
    v0192 = stack[-3];
    v0193 = get(v0193, v0192);
    env = stack[-5];
    v0192 = elt(env, 15); /* inbrackets */
    v0192 = (v0193 == v0192 ? lisp_true : nil);
    goto v0200;

v0217:
    v0192 = qvalue(elt(env, 3)); /* nil */
    goto v0200;

v0198:
    v0192 = qvalue(elt(env, 3)); /* nil */
    goto v0200;

v0197:
    v0192 = stack[-1];
    v0192 = Lreverse(nil, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    v0192 = qcar(v0192);
    stack[-4] = v0192;
    if (!consp(v0192)) goto v0219;
    v0192 = stack[-4];
    v0192 = qcar(v0192);
    if (symbolp(v0192)) goto v0220;
    v0192 = qvalue(elt(env, 3)); /* nil */
    goto v0071;

v0220:
    v0192 = stack[-4];
    fn = elt(env, 27); /* getrtype */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    stack[0] = v0192;
    if (v0192 == nil) goto v0139;
    v0193 = stack[0];
    v0192 = elt(env, 13); /* tag */
    v0193 = get(v0193, v0192);
    env = stack[-5];
    v0192 = elt(env, 14); /* setprifn */
    v0192 = get(v0193, v0192);
    env = stack[-5];
    stack[0] = v0192;
    goto v0071;

v0139:
    v0192 = qvalue(elt(env, 3)); /* nil */
    goto v0071;

v0219:
    v0192 = qvalue(elt(env, 3)); /* nil */
    goto v0071;

v0064:
    v0192 = stack[-3];
    fn = elt(env, 24); /* oprin */
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-5];
    goto v0065;

v0089:
    v0192 = qvalue(elt(env, 10)); /* !*revpri */
    goto v0196;

v0037:
    v0192 = qvalue(elt(env, 2)); /* !*nat */
    if (v0192 == nil) goto v0059;
    v0192 = qvalue(elt(env, 4)); /* !*asterisk */
    v0192 = (v0192 == nil ? lisp_true : nil);
    goto v0074;

v0059:
    v0192 = qvalue(elt(env, 3)); /* nil */
    goto v0074;
/* error exit handlers */
v0195:
    popv(6);
    return nil;
}



/* Code for ombindir */

static Lisp_Object MS_CDECL CC_ombindir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ombindir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ombindir");
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
    push3(nil, nil, nil);
/* end of prologue */
    fn = elt(env, 2); /* lex */
    v0032 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-3];
    fn = elt(env, 3); /* omobj */
    v0032 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-3];
    stack[-1] = v0032;
    fn = elt(env, 2); /* lex */
    v0032 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-3];
    fn = elt(env, 4); /* variablesir */
    v0032 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-3];
    fn = elt(env, 5); /* tobvarir */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-3];
    stack[0] = v0032;
    fn = elt(env, 2); /* lex */
    v0032 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-3];
    fn = elt(env, 3); /* omobj */
    v0032 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-3];
    stack[-2] = v0032;
    fn = elt(env, 2); /* lex */
    v0032 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-3];
    v0032 = elt(env, 1); /* (!/ o m b i n d) */
    fn = elt(env, 6); /* checktag */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-3];
    v0032 = stack[-2];
    v0032 = ncons(v0032);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-3];
    v0032 = Lappend(nil, stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    {
        Lisp_Object v0007 = stack[-1];
        popv(4);
        return Lappend(nil, v0007, v0032);
    }
/* error exit handlers */
v0080:
    popv(4);
    return nil;
}



/* Code for cr!:minusp */

static Lisp_Object CC_crTminusp(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0030, v0031;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cr:minusp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0029 = v0004;
/* end of prologue */
    v0030 = v0029;
    v0030 = qcdr(v0030);
    v0030 = qcar(v0030);
    v0029 = qcdr(v0029);
    v0029 = qcdr(v0029);
    v0031 = v0030;
    v0030 = v0029;
    v0029 = v0031;
    if (!consp(v0029)) goto v0036;
    v0029 = v0030;
    v0029 = qcar(v0029);
    v0029 = (Lisp_Object)zerop(v0029);
    v0029 = v0029 ? lisp_true : nil;
    env = stack[0];
    if (v0029 == nil) goto v0080;
    v0029 = v0031;
    v0030 = qcar(v0029);
    v0029 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v0030, v0029);

v0080:
    v0029 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0029); }

v0036:
    v0029 = v0030;
    v0029 = (Lisp_Object)zerop(v0029);
    v0029 = v0029 ? lisp_true : nil;
    env = stack[0];
    if (v0029 == nil) goto v0081;
    v0030 = v0031;
    v0029 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v0030, v0029);

v0081:
    v0029 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0029); }
}



/* Code for evrevgradlexcomp */

static Lisp_Object CC_evrevgradlexcomp(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0011;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evrevgradlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
    stack[-2] = v0004;
/* end of prologue */

v0022:
    v0010 = stack[-2];
    if (v0010 == nil) goto v0061;
    v0010 = stack[-1];
    if (v0010 == nil) goto v0036;
    v0010 = stack[-2];
    v0011 = qcar(v0010);
    v0010 = stack[-1];
    v0010 = qcar(v0010);
    fn = elt(env, 2); /* iequal */
    v0010 = (*qfn2(fn))(qenv(fn), v0011, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    if (v0010 == nil) goto v0032;
    v0010 = stack[-2];
    v0010 = qcdr(v0010);
    stack[-2] = v0010;
    v0010 = stack[-1];
    v0010 = qcdr(v0010);
    stack[-1] = v0010;
    goto v0022;

v0032:
    v0010 = stack[-2];
    fn = elt(env, 3); /* evtdeg */
    stack[0] = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    v0010 = stack[-1];
    fn = elt(env, 3); /* evtdeg */
    v0010 = (*qfn1(fn))(qenv(fn), v0010);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v0010;
    v0011 = stack[-3];
    v0010 = stack[0];
    fn = elt(env, 2); /* iequal */
    v0010 = (*qfn2(fn))(qenv(fn), v0011, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-4];
    if (v0010 == nil) goto v0087;
    v0011 = stack[-2];
    v0010 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); /* evinvlexcomp */
        return (*qfn2(fn))(qenv(fn), v0011, v0010);
    }

v0087:
    v0011 = stack[-3];
    v0010 = stack[0];
    if (((int32_t)(v0011)) > ((int32_t)(v0010))) goto v0126;
    v0010 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0010); }

v0126:
    v0010 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0010); }

v0036:
    v0010 = elt(env, 1); /* (0) */
    stack[-1] = v0010;
    goto v0022;

v0061:
    v0010 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v0010); }
/* error exit handlers */
v0047:
    popv(5);
    return nil;
}



/* Code for ordexp */

static Lisp_Object CC_ordexp(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0017, v0085, v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0017 = v0003;
    v0085 = v0004;
/* end of prologue */

v0022:
    v0034 = v0085;
    if (v0034 == nil) goto v0061;
    v0034 = v0085;
    v0084 = qcar(v0034);
    v0034 = v0017;
    v0034 = qcar(v0034);
    if (v0084 == v0034) goto v0036;
    v0034 = v0085;
    v0034 = qcar(v0034);
    if (v0034 == nil) goto v0127;
    v0034 = v0017;
    v0034 = qcar(v0034);
    if (v0034 == nil) goto v0032;
    v0034 = v0085;
    v0034 = qcar(v0034);
    v0017 = qcar(v0017);
    {
        fn = elt(env, 3); /* ordop */
        return (*qfn2(fn))(qenv(fn), v0034, v0017);
    }

v0032:
    v0034 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0034);

v0127:
    v0034 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0034);

v0036:
    v0034 = v0085;
    v0034 = qcdr(v0034);
    v0085 = v0034;
    v0034 = v0017;
    v0034 = qcdr(v0034);
    v0017 = v0034;
    goto v0022;

v0061:
    v0034 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0034);
}



/* Code for gbfdot */

static Lisp_Object CC_gbfdot(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gbfdot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0004;
/* end of prologue */
    v0018 = stack[-1];
    v0082 = qcar(v0018);
    v0018 = stack[0];
    v0018 = qcar(v0018);
    fn = elt(env, 1); /* csl_timbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0082, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-3];
    v0018 = stack[-1];
    v0082 = qcdr(v0018);
    v0018 = stack[0];
    v0018 = qcdr(v0018);
    fn = elt(env, 1); /* csl_timbf */
    v0018 = (*qfn2(fn))(qenv(fn), v0082, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-3];
    {
        Lisp_Object v0054 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* plubf */
        return (*qfn2(fn))(qenv(fn), v0054, v0018);
    }
/* error exit handlers */
v0083:
    popv(4);
    return nil;
}



/* Code for evaluate!-horner */

static Lisp_Object CC_evaluateKhorner(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0086, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate-horner");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0004;
/* end of prologue */
    v0086 = stack[-1];
    v0096 = qvalue(elt(env, 1)); /* horner!-cache!* */
    v0096 = Lassoc(nil, v0086, v0096);
    stack[-2] = v0096;
    v0096 = stack[-2];
    if (v0096 == nil) goto v0016;
    v0096 = stack[-2];
    v0096 = qcdr(v0096);
    { popv(4); return onevalue(v0096); }

v0016:
    v0096 = stack[-1];
    fn = elt(env, 2); /* simp!* */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    stack[-2] = v0096;
    v0096 = stack[-2];
    v0096 = qcar(v0096);
    fn = elt(env, 3); /* hornerf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0096 = stack[-2];
    v0096 = qcdr(v0096);
    fn = elt(env, 3); /* hornerf */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0096 = cons(stack[0], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    fn = elt(env, 4); /* prepsq */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    stack[-2] = v0096;
    v0034 = stack[-1];
    v0086 = stack[-2];
    v0096 = qvalue(elt(env, 1)); /* horner!-cache!* */
    v0096 = acons(v0034, v0086, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0096; /* horner!-cache!* */
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v0029:
    popv(4);
    return nil;
}



/* Code for lispassignp */

static Lisp_Object CC_lispassignp(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0035;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lispassignp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0090 = v0004;
/* end of prologue */
    v0035 = elt(env, 1); /* setq */
        return Leqcar(nil, v0090, v0035);
}



/* Code for edges_parents */

static Lisp_Object CC_edges_parents(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for edges_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
/* end of prologue */
    v0075 = stack[0];
    if (v0075 == nil) goto v0021;
    v0075 = stack[0];
    v0075 = qcar(v0075);
    fn = elt(env, 2); /* edge_new_parents */
    v0075 = (*qfn1(fn))(qenv(fn), v0075);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    env = stack[-2];
    stack[-1] = v0075;
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0075 = CC_edges_parents(env, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0127;
    {
        Lisp_Object v0221 = stack[-1];
        popv(3);
        return Lappend(nil, v0221, v0075);
    }

v0021:
    v0075 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0075); }
/* error exit handlers */
v0127:
    popv(3);
    return nil;
}



/* Code for log_assignment */

static Lisp_Object CC_log_assignment(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0140, v0225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for log_assignment");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    v0140 = v0004;
/* end of prologue */

v0022:
    v0123 = stack[0];
    if (!consp(v0123)) goto v0036;
    v0225 = stack[0];
    v0123 = elt(env, 2); /* quote */
    if (!consp(v0225)) goto v0083;
    v0225 = qcar(v0225);
    if (!(v0225 == v0123)) goto v0083;
    v0123 = qvalue(elt(env, 1)); /* t */
    goto v0035;

v0035:
    if (v0123 == nil) goto v0078;
    v0123 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v0123); }

v0078:
    v0225 = stack[0];
    v0123 = elt(env, 5); /* setq */
    if (!consp(v0225)) goto v0226;
    v0225 = qcar(v0225);
    if (!(v0225 == v0123)) goto v0226;
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    v0225 = qcar(v0123);
    v0123 = v0140;
    v0123 = Lmember(nil, v0225, v0123);
    if (v0123 == nil) goto v0093;
    v0123 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    v0123 = (Lisp_Object)zerop(v0123);
    v0123 = v0123 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0123 == nil)) goto v0089;
    v0123 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    goto v0089;

v0089:
    v0123 = elt(env, 6); /* "+++ Assignment to parameter of inline: " */
    v0123 = Lprinc(nil, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    v0123 = stack[0];
    v0123 = Lprint(nil, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    v0123 = elt(env, 7); /* "+++ Macro was: " */
    v0123 = Lprinc(nil, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    v0123 = qvalue(elt(env, 8)); /* inlineinfo */
    v0123 = Lprint(nil, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-1];
    v0123 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0123); }

v0093:
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    v0123 = qcdr(v0123);
    v0123 = qcar(v0123);
    stack[0] = v0123;
    goto v0022;

v0226:
    v0225 = stack[0];
    v0123 = elt(env, 9); /* cond */
    if (!consp(v0225)) goto v0106;
    v0225 = qcar(v0225);
    if (!(v0225 == v0123)) goto v0106;
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    {
        popv(2);
        fn = elt(env, 10); /* log_assignment_list_list */
        return (*qfn2(fn))(qenv(fn), v0140, v0123);
    }

v0106:
    v0123 = stack[0];
    {
        popv(2);
        fn = elt(env, 11); /* log_assignment_list */
        return (*qfn2(fn))(qenv(fn), v0140, v0123);
    }

v0083:
    v0225 = stack[0];
    v0123 = elt(env, 3); /* function */
    v0123 = Leqcar(nil, v0225, v0123);
    env = stack[-1];
    goto v0035;

v0036:
    v0123 = qvalue(elt(env, 1)); /* t */
    goto v0035;
/* error exit handlers */
v0188:
    popv(2);
    return nil;
}



/* Code for red_topred */

static Lisp_Object CC_red_topred(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_topred");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0004;
/* end of prologue */
    v0067 = stack[0];
    fn = elt(env, 4); /* bas_dpoly */
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    if (v0067 == nil) goto v0014;
    v0067 = stack[-1];
    v0067 = (v0067 == nil ? lisp_true : nil);
    goto v0061;

v0061:
    if (!(v0067 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0095 = stack[-1];
    v0067 = stack[0];
    fn = elt(env, 5); /* red_topredbe */
    v0067 = (*qfn2(fn))(qenv(fn), v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    stack[0] = v0067;
    goto v0054;

v0054:
    v0067 = stack[0];
    fn = elt(env, 4); /* bas_dpoly */
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    v0095 = v0067;
    if (v0067 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    stack[-2] = stack[-1];
    v0067 = v0095;
    fn = elt(env, 6); /* dp_lmon */
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    fn = elt(env, 7); /* red_divtest */
    v0067 = (*qfn2(fn))(qenv(fn), stack[-2], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    stack[-2] = v0067;
    if (v0067 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0095 = stack[0];
    v0067 = stack[-2];
    fn = elt(env, 8); /* red_subst */
    v0067 = (*qfn2(fn))(qenv(fn), v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    stack[-2] = v0067;
    v0067 = qvalue(elt(env, 3)); /* !*noetherian */
    if (!(v0067 == nil)) goto v0227;
    v0095 = stack[-1];
    v0067 = stack[0];
    fn = elt(env, 9); /* red_update */
    v0067 = (*qfn2(fn))(qenv(fn), v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    stack[-1] = v0067;
    goto v0227;

v0227:
    v0095 = stack[-1];
    v0067 = stack[-2];
    fn = elt(env, 5); /* red_topredbe */
    v0067 = (*qfn2(fn))(qenv(fn), v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    stack[0] = v0067;
    goto v0054;

v0014:
    v0067 = qvalue(elt(env, 1)); /* t */
    goto v0061;
/* error exit handlers */
v0064:
    popv(4);
    return nil;
}



/* Code for horner!-rule!-for!-one!-var */

static Lisp_Object MS_CDECL CC_hornerKruleKforKoneKvar(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0231, v0120, v0121, v0101, v0102, v0044;
    Lisp_Object fn;
    Lisp_Object v0021, v0020, v0005, v0003, v0004;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "horner-rule-for-one-var");
    va_start(aa, nargs);
    v0004 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    v0020 = va_arg(aa, Lisp_Object);
    v0021 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for horner-rule-for-one-var");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0021,v0020,v0005,v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0004,v0003,v0005,v0020,v0021);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0231 = v0021;
    v0120 = v0020;
    v0121 = v0005;
    v0101 = v0003;
    v0102 = v0004;
/* end of prologue */

v0232:
    v0042 = v0102;
    if (!consp(v0042)) goto v0038;
    v0042 = v0102;
    v0042 = qcar(v0042);
    v0042 = (consp(v0042) ? nil : lisp_true);
    goto v0037;

v0037:
    if (v0042 == nil) goto v0221;
    v0042 = qvalue(elt(env, 1)); /* t */
    goto v0035;

v0035:
    if (v0042 == nil) goto v0009;
    v0042 = v0121;
    v0042 = (Lisp_Object)zerop(v0042);
    v0042 = v0042 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0042 == nil)) { popv(7); return onevalue(v0102); }
    stack[-1] = v0102;
    stack[0] = v0120;
    v0042 = v0121;
    v0042 = Lexpt(nil, v0042, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    fn = elt(env, 2); /* !*n2f */
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    fn = elt(env, 3); /* multf */
    v0042 = (*qfn2(fn))(qenv(fn), stack[0], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    {
        Lisp_Object v0233 = stack[-1];
        popv(7);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v0233, v0042);
    }

v0009:
    v0042 = v0102;
    v0042 = qcar(v0042);
    v0042 = qcar(v0042);
    v0042 = qcdr(v0042);
    stack[-5] = v0042;
    v0042 = v0102;
    stack[-4] = qcdr(v0042);
    stack[-3] = v0101;
    stack[-2] = v0121;
    v0042 = v0121;
    v0042 = (Lisp_Object)zerop(v0042);
    v0042 = v0042 ? lisp_true : nil;
    env = stack[-6];
    if (v0042 == nil) goto v0125;
    v0042 = v0102;
    v0042 = qcar(v0042);
    v0042 = qcdr(v0042);
    v0231 = v0042;
    goto v0064;

v0064:
    v0042 = stack[-5];
    v0102 = stack[-4];
    v0101 = stack[-3];
    v0121 = stack[-2];
    v0120 = v0231;
    v0231 = v0042;
    goto v0232;

v0125:
    v0042 = v0102;
    v0042 = qcar(v0042);
    stack[-1] = qcdr(v0042);
    stack[0] = v0120;
    v0120 = v0121;
    v0042 = stack[-5];
    v0042 = (Lisp_Object)(int32_t)((int32_t)v0231 - (int32_t)v0042 + TAG_FIXNUM);
    v0042 = Lexpt(nil, v0120, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    fn = elt(env, 2); /* !*n2f */
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    fn = elt(env, 3); /* multf */
    v0042 = (*qfn2(fn))(qenv(fn), stack[0], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    fn = elt(env, 4); /* addf */
    v0042 = (*qfn2(fn))(qenv(fn), stack[-1], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-6];
    v0231 = v0042;
    goto v0064;

v0221:
    v0042 = v0102;
    v0042 = qcar(v0042);
    v0042 = qcar(v0042);
    v0044 = qcar(v0042);
    v0042 = v0101;
    v0042 = (equal(v0044, v0042) ? lisp_true : nil);
    v0042 = (v0042 == nil ? lisp_true : nil);
    goto v0035;

v0038:
    v0042 = qvalue(elt(env, 1)); /* t */
    goto v0037;
/* error exit handlers */
v0219:
    popv(7);
    return nil;
}



/* Code for get!-free!-form */

static Lisp_Object CC_getKfreeKform(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069, v0234, v0047;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-free-form");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0004;
/* end of prologue */
    stack[-2] = nil;
    v0234 = stack[-1];
    v0069 = qvalue(elt(env, 1)); /* frasc!* */
    v0069 = Latsoc(nil, v0234, v0069);
    stack[0] = v0069;
    if (v0069 == nil) goto v0056;
    v0069 = stack[0];
    v0069 = qcdr(v0069);
    { popv(4); return onevalue(v0069); }

v0056:
    v0234 = stack[-1];
    v0069 = elt(env, 2); /* !~ */
    if (!consp(v0234)) goto v0007;
    v0234 = qcar(v0234);
    if (!(v0234 == v0069)) goto v0007;
    v0069 = stack[-1];
    v0069 = qcdr(v0069);
    v0069 = qcar(v0069);
    stack[-1] = v0069;
    v0069 = elt(env, 3); /* (!! !~ !! !~) */
    stack[0] = v0069;
    v0069 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v0069;
    goto v0078;

v0078:
    v0069 = stack[-1];
    v0069 = Lexplode(nil, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0069 = Lappend(nil, stack[0], v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0069 = Lcompress(nil, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0069 = Lintern(nil, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[0] = v0069;
    v0047 = stack[-1];
    v0234 = stack[0];
    v0069 = qvalue(elt(env, 1)); /* frasc!* */
    v0069 = acons(v0047, v0234, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0069; /* frasc!* */
    v0069 = stack[-2];
    if (v0069 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0069 = stack[0];
    v0234 = ncons(v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0069 = elt(env, 6); /* optional */
    v0069 = Lflag(nil, v0234, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v0007:
    v0069 = elt(env, 5); /* (!! !~) */
    stack[0] = v0069;
    goto v0078;
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for taydegree!< */

static Lisp_Object CC_taydegreeR(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for taydegree<");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
    stack[-2] = v0004;
/* end of prologue */

v0079:
    v0033 = stack[-2];
    v0033 = qcar(v0033);
    stack[-3] = v0033;
    v0033 = stack[-1];
    v0033 = qcar(v0033);
    stack[0] = v0033;
    goto v0016;

v0016:
    v0033 = stack[-3];
    v0126 = qcar(v0033);
    v0033 = stack[0];
    v0033 = qcar(v0033);
    fn = elt(env, 3); /* tayexp!-greaterp */
    v0033 = (*qfn2(fn))(qenv(fn), v0126, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    if (v0033 == nil) goto v0025;
    v0033 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0033); }

v0025:
    v0033 = stack[-3];
    v0126 = qcar(v0033);
    v0033 = stack[0];
    v0033 = qcar(v0033);
    fn = elt(env, 4); /* tayexp!-lessp */
    v0033 = (*qfn2(fn))(qenv(fn), v0126, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    if (v0033 == nil) goto v0074;
    v0033 = qvalue(elt(env, 2)); /* t */
    { popv(5); return onevalue(v0033); }

v0074:
    v0033 = stack[-3];
    v0033 = qcdr(v0033);
    stack[-3] = v0033;
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    v0033 = stack[-3];
    if (!(v0033 == nil)) goto v0016;
    v0033 = stack[-2];
    v0033 = qcdr(v0033);
    stack[-2] = v0033;
    v0033 = stack[-1];
    v0033 = qcdr(v0033);
    stack[-1] = v0033;
    v0033 = stack[-2];
    if (!(v0033 == nil)) goto v0079;
    v0033 = nil;
    { popv(5); return onevalue(v0033); }
/* error exit handlers */
v0097:
    popv(5);
    return nil;
}



/* Code for rl_susipost */

static Lisp_Object CC_rl_susipost(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_susipost");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0016 = v0003;
    v0028 = v0004;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susipost!* */
    v0016 = list2(v0028, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    {
        Lisp_Object v0091 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0091, v0016);
    }
/* error exit handlers */
v0039:
    popv(2);
    return nil;
}



/* Code for ctx_idl */

static Lisp_Object CC_ctx_idl(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ctx_idl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0078 = v0004;
/* end of prologue */
    fn = elt(env, 2); /* ctx_ial */
    v0078 = (*qfn1(fn))(qenv(fn), v0078);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[-3] = v0078;
    v0078 = stack[-3];
    if (v0078 == nil) goto v0036;
    v0078 = stack[-3];
    v0078 = qcar(v0078);
    v0078 = qcar(v0078);
    v0078 = ncons(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    stack[-1] = v0078;
    stack[-2] = v0078;
    goto v0079;

v0079:
    v0078 = stack[-3];
    v0078 = qcdr(v0078);
    stack[-3] = v0078;
    v0078 = stack[-3];
    if (v0078 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0078 = stack[-3];
    v0078 = qcar(v0078);
    v0078 = qcar(v0078);
    v0078 = ncons(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    v0078 = Lrplacd(nil, stack[0], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-4];
    v0078 = stack[-1];
    v0078 = qcdr(v0078);
    stack[-1] = v0078;
    goto v0079;

v0036:
    v0078 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0078); }
/* error exit handlers */
v0017:
    popv(5);
    return nil;
}



/* Code for omfir */

static Lisp_Object MS_CDECL CC_omfir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omfir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omfir");
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
    v0083 = qvalue(elt(env, 1)); /* atts */
    v0143 = elt(env, 2); /* dec */
    fn = elt(env, 5); /* find */
    v0143 = (*qfn2(fn))(qenv(fn), v0083, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-1];
    stack[0] = v0143;
    v0083 = qvalue(elt(env, 1)); /* atts */
    v0143 = elt(env, 3); /* name */
    fn = elt(env, 5); /* find */
    v0143 = (*qfn2(fn))(qenv(fn), v0083, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    env = stack[-1];
    if (v0143 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0083 = elt(env, 4); /* "wrong att" */
    v0143 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v0143 = (*qfn2(fn))(qenv(fn), v0083, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0080:
    popv(2);
    return nil;
}



/* Code for exptplus */

static Lisp_Object CC_exptplus(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0085, v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0085 = v0003;
    v0084 = v0004;
/* end of prologue */
    v0017 = v0084;
    if (!consp(v0017)) goto v0022;
    v0017 = v0085;
    if (!consp(v0017)) goto v0026;
    v0017 = elt(env, 1); /* "Bad exponent sum" */
    {
        fn = elt(env, 2); /* interr */
        return (*qfn1(fn))(qenv(fn), v0017);
    }

v0026:
    v0017 = v0084;
    v0017 = qcar(v0017);
    v0017 = plus2(v0017, v0085);
    errexit();
    return ncons(v0017);

v0022:
    v0017 = v0085;
    if (!consp(v0017)) goto v0074;
    v0017 = v0084;
    v0085 = qcar(v0085);
    v0017 = plus2(v0017, v0085);
    errexit();
    return ncons(v0017);

v0074:
    v0017 = v0084;
    return plus2(v0017, v0085);
}



/* Code for dm!-gt */

static Lisp_Object CC_dmKgt(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-gt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0015 = v0003;
    v0036 = v0004;
/* end of prologue */
    fn = elt(env, 1); /* dm!-difference */
    v0036 = (*qfn2(fn))(qenv(fn), v0015, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !:minusp */
        return (*qfn1(fn))(qenv(fn), v0036);
    }
/* error exit handlers */
v0074:
    popv(1);
    return nil;
}



/* Code for f2dip11 */

static Lisp_Object CC_f2dip11(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for f2dip11");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
/* end of prologue */

v0232:
    v0029 = qvalue(elt(env, 1)); /* !*notestparameters */
    if (!(v0029 == nil)) { popv(2); return onevalue(v0029); }
    v0030 = stack[0];
    v0029 = qvalue(elt(env, 2)); /* vdpvars!* */
    v0029 = Lmember(nil, v0030, v0029);
    if (v0029 == nil) goto v0079;
    v0030 = stack[0];
    v0029 = elt(env, 3); /* "occurs in a parameter and is member of the groebner variables." 
*/
    v0029 = list2(v0030, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    fn = elt(env, 6); /* rederr */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    goto v0079;

v0079:
    v0029 = stack[0];
    if (!consp(v0029)) goto v0080;
    v0029 = stack[0];
    v0029 = qcar(v0029);
    v0029 = CC_f2dip11(env, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    v0029 = stack[0];
    v0029 = qcdr(v0029);
    stack[0] = v0029;
    goto v0232;

v0080:
    v0030 = stack[0];
    v0029 = elt(env, 4); /* list */
    if (v0030 == v0029) goto v0083;
    v0029 = nil;
    { popv(2); return onevalue(v0029); }

v0083:
    v0029 = elt(env, 5); /* "groebner: LIST not allowed." */
    {
        popv(2);
        fn = elt(env, 6); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0029);
    }
/* error exit handlers */
v0115:
    popv(2);
    return nil;
}



/* Code for vevstrictlydivides!? */

static Lisp_Object CC_vevstrictlydividesW(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0059, v0127, v0221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevstrictlydivides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0127 = v0003;
    v0221 = v0004;
/* end of prologue */
    v0059 = v0221;
    v0056 = v0127;
    if (equal(v0059, v0056)) goto v0091;
    v0056 = v0127;
    v0059 = v0221;
    {
        fn = elt(env, 2); /* vevmtest!? */
        return (*qfn2(fn))(qenv(fn), v0056, v0059);
    }

v0091:
    v0056 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0056);
}



/* Code for r2findindex */

static Lisp_Object CC_r2findindex(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0037, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for r2findindex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0074 = v0003;
    v0037 = v0004;
/* end of prologue */
    v0038 = v0037;
    v0037 = v0074;
    v0074 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 1); /* r2findindex1 */
        return (*qfnn(fn))(qenv(fn), 3, v0038, v0037, v0074);
    }
}



/* Code for log_assignment_list */

static Lisp_Object CC_log_assignment_list(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0221, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for log_assignment_list");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0004;
/* end of prologue */

v0022:
    v0221 = stack[0];
    if (!consp(v0221)) goto v0061;
    v0018 = stack[-1];
    v0221 = stack[0];
    v0221 = qcar(v0221);
    fn = elt(env, 3); /* log_assignment */
    v0221 = (*qfn2(fn))(qenv(fn), v0018, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    if (v0221 == nil) goto v0075;
    v0221 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v0221); }

v0075:
    v0221 = stack[0];
    v0221 = qcdr(v0221);
    stack[0] = v0221;
    goto v0022;

v0061:
    v0221 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0221); }
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for copy!-tree */

static Lisp_Object CC_copyKtree(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0095, v0142, v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for copy-tree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0004;
/* end of prologue */
    v0067 = stack[-2];
    if (v0067 == nil) goto v0021;
    v0067 = (Lisp_Object)49; /* 3 */
    v0067 = Lmkvect(nil, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-4];
    stack[-3] = v0067;
    v0052 = stack[-3];
    v0142 = (Lisp_Object)1; /* 0 */
    v0095 = stack[-2];
    v0067 = (Lisp_Object)1; /* 0 */
    v0067 = *(Lisp_Object *)((char *)v0095 + (CELL-TAG_VECTOR) + ((int32_t)v0067/(16/CELL)));
    *(Lisp_Object *)((char *)v0052 + (CELL-TAG_VECTOR) + ((int32_t)v0142/(16/CELL))) = v0067;
    v0052 = stack[-3];
    v0142 = (Lisp_Object)17; /* 1 */
    v0095 = stack[-2];
    v0067 = (Lisp_Object)17; /* 1 */
    v0067 = *(Lisp_Object *)((char *)v0095 + (CELL-TAG_VECTOR) + ((int32_t)v0067/(16/CELL)));
    *(Lisp_Object *)((char *)v0052 + (CELL-TAG_VECTOR) + ((int32_t)v0142/(16/CELL))) = v0067;
    v0052 = stack[-3];
    v0142 = (Lisp_Object)33; /* 2 */
    v0095 = stack[-2];
    v0067 = (Lisp_Object)33; /* 2 */
    v0067 = *(Lisp_Object *)((char *)v0095 + (CELL-TAG_VECTOR) + ((int32_t)v0067/(16/CELL)));
    *(Lisp_Object *)((char *)v0052 + (CELL-TAG_VECTOR) + ((int32_t)v0142/(16/CELL))) = v0067;
    stack[-1] = stack[-3];
    stack[0] = (Lisp_Object)49; /* 3 */
    v0095 = stack[-2];
    v0067 = (Lisp_Object)49; /* 3 */
    v0067 = *(Lisp_Object *)((char *)v0095 + (CELL-TAG_VECTOR) + ((int32_t)v0067/(16/CELL)));
    v0067 = CC_copyKtree(env, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0067;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v0021:
    v0067 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0067); }
/* error exit handlers */
v0131:
    popv(5);
    return nil;
}



/* Code for red_topredbe */

static Lisp_Object CC_red_topredbe(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069, v0234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_topredbe");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
    stack[-2] = v0004;
/* end of prologue */
    v0069 = stack[-1];
    fn = elt(env, 4); /* bas_dpoly */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    if (v0069 == nil) goto v0014;
    v0069 = stack[-2];
    v0069 = (v0069 == nil ? lisp_true : nil);
    goto v0061;

v0061:
    if (!(v0069 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    fn = elt(env, 5); /* cali_trace */
    v0234 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    v0069 = (Lisp_Object)1265; /* 79 */
    v0069 = (Lisp_Object)greaterp2(v0234, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    v0069 = v0069 ? lisp_true : nil;
    env = stack[-4];
    if (v0069 == nil) goto v0078;
    v0069 = elt(env, 2); /* " reduce " */
    v0069 = Lprinc(nil, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    v0069 = stack[-1];
    fn = elt(env, 4); /* bas_dpoly */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    fn = elt(env, 6); /* dp_print */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    goto v0078;

v0078:
    v0069 = stack[-1];
    fn = elt(env, 4); /* bas_dpoly */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    v0234 = v0069;
    if (v0069 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    stack[-3] = stack[-2];
    v0069 = v0234;
    fn = elt(env, 7); /* dp_lmon */
    stack[0] = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    v0069 = stack[-1];
    fn = elt(env, 8); /* bas_dpecart */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    fn = elt(env, 9); /* red_divtestbe */
    v0234 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    v0069 = v0234;
    if (v0234 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0234 = stack[-1];
    fn = elt(env, 10); /* red_subst */
    v0069 = (*qfn2(fn))(qenv(fn), v0234, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    stack[-1] = v0069;
    goto v0078;

v0014:
    v0069 = qvalue(elt(env, 1)); /* t */
    goto v0061;
/* error exit handlers */
v0094:
    popv(5);
    return nil;
}



/* Code for multfnc */

static Lisp_Object CC_multfnc(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0242, v0243, v0244;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multfnc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
    stack[-2] = v0004;
/* end of prologue */
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    stack[0] = qcdr(v0242);
    v0242 = stack[-1];
    v0242 = qcar(v0242);
    v0242 = ncons(v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    fn = elt(env, 4); /* multf */
    v0242 = (*qfn2(fn))(qenv(fn), stack[0], v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    stack[-3] = v0242;
    v0242 = stack[-3];
    if (v0242 == nil) goto v0181;
    v0242 = stack[-3];
    if (!consp(v0242)) goto v0143;
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = (consp(v0242) ? nil : lisp_true);
    goto v0032;

v0032:
    if (v0242 == nil) goto v0023;
    v0242 = qvalue(elt(env, 1)); /* nil */
    goto v0221;

v0221:
    if (v0242 == nil) goto v0059;
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    stack[0] = qcar(v0242);
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0243 = qcdr(v0242);
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0242 = qcdr(v0242);
    v0242 = plus2(v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    fn = elt(env, 5); /* mkspm */
    v0242 = (*qfn2(fn))(qenv(fn), stack[0], v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    v0244 = v0242;
    if (v0242 == nil) goto v0089;
    v0243 = v0244;
    v0242 = (Lisp_Object)17; /* 1 */
    if (v0243 == v0242) goto v0130;
    v0243 = v0244;
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = qcdr(v0242);
    v0242 = cons(v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    v0242 = ncons(v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    stack[0] = v0242;
    goto v0246;

v0246:
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0243 = qcar(v0242);
    v0242 = (Lisp_Object)17; /* 1 */
    v0242 = cons(v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    v0243 = ncons(v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    v0242 = stack[-3];
    v0242 = qcdr(v0242);
    fn = elt(env, 4); /* multf */
    v0242 = (*qfn2(fn))(qenv(fn), v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    fn = elt(env, 6); /* addf */
    v0242 = (*qfn2(fn))(qenv(fn), stack[0], v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    stack[-3] = v0242;
    goto v0181;

v0181:
    v0242 = stack[-2];
    v0243 = qcdr(v0242);
    v0242 = stack[-1];
    fn = elt(env, 4); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0243 = ncons(v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    v0242 = stack[-1];
    v0242 = qcdr(v0242);
    fn = elt(env, 4); /* multf */
    v0242 = (*qfn2(fn))(qenv(fn), v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    fn = elt(env, 6); /* addf */
    v0242 = (*qfn2(fn))(qenv(fn), stack[0], v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    {
        Lisp_Object v0247 = stack[-3];
        popv(5);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v0247, v0242);
    }

v0130:
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = qcdr(v0242);
    stack[0] = v0242;
    goto v0246;

v0089:
    v0242 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0242;
    goto v0246;

v0059:
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    fn = elt(env, 7); /* noncomp */
    v0242 = (*qfn1(fn))(qenv(fn), v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    if (v0242 == nil) goto v0248;
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0243 = qcar(v0242);
    v0242 = stack[-3];
    v0242 = cons(v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    v0242 = ncons(v0242);
    nil = C_nil;
    if (exception_pending()) goto v0245;
    env = stack[-4];
    stack[-3] = v0242;
    goto v0181;

v0248:
    v0242 = qvalue(elt(env, 2)); /* t */
    stack[0] = qvalue(elt(env, 3)); /* !*!*processed */
    qvalue(elt(env, 3)) = v0242; /* !*!*processed */
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0243 = qcar(v0242);
    v0242 = (Lisp_Object)17; /* 1 */
    v0242 = cons(v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-4];
    v0243 = ncons(v0242);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-4];
    v0242 = stack[-3];
    fn = elt(env, 4); /* multf */
    v0242 = (*qfn2(fn))(qenv(fn), v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-4];
    stack[-3] = v0242;
    qvalue(elt(env, 3)) = stack[0]; /* !*!*processed */
    goto v0181;

v0023:
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0243 = qcar(v0242);
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0242 = (v0243 == v0242 ? lisp_true : nil);
    goto v0221;

v0143:
    v0242 = qvalue(elt(env, 2)); /* t */
    goto v0032;
/* error exit handlers */
v0249:
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[0]; /* !*!*processed */
    popv(5);
    return nil;
v0245:
    popv(5);
    return nil;
}



/* Code for smemberlp */

static Lisp_Object CC_smemberlp(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0077;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smemberlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0004;
/* end of prologue */

v0232:
    v0076 = stack[0];
    if (v0076 == nil) goto v0022;
    v0076 = stack[0];
    if (!consp(v0076)) goto v0036;
    v0077 = stack[-1];
    v0076 = stack[0];
    v0076 = qcar(v0076);
    v0076 = CC_smemberlp(env, v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    if (!(v0076 == nil)) { popv(3); return onevalue(v0076); }
    v0077 = stack[-1];
    v0076 = stack[0];
    v0076 = qcdr(v0076);
    stack[-1] = v0077;
    stack[0] = v0076;
    goto v0232;

v0036:
    v0077 = stack[0];
    v0076 = stack[-1];
    v0076 = Lmember(nil, v0077, v0076);
    { popv(3); return onevalue(v0076); }

v0022:
    v0076 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0076); }
/* error exit handlers */
v0096:
    popv(3);
    return nil;
}



/* Code for !*tayexp2q */

static Lisp_Object CC_Htayexp2q(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0221, v0018;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *tayexp2q");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0221 = v0004;
/* end of prologue */
    v0018 = v0221;
    if (!consp(v0018)) goto v0061;
    v0221 = qcdr(v0221);
    { popv(1); return onevalue(v0221); }

v0061:
    v0018 = v0221;
    v0018 = (Lisp_Object)zerop(v0018);
    v0018 = v0018 ? lisp_true : nil;
    env = stack[0];
    if (v0018 == nil) goto v0027;
    v0221 = qvalue(elt(env, 1)); /* nil */
    v0018 = v0221;
    goto v0090;

v0090:
    v0221 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v0018, v0221);

v0027:
    v0018 = v0221;
    goto v0090;
}



/* Code for distribute!.multiplicity */

static Lisp_Object CC_distributeQmultiplicity(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0117;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for distribute.multiplicity");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0003;
    v0116 = v0004;
/* end of prologue */
    stack[-4] = v0116;
    v0116 = stack[-4];
    if (v0116 == nil) goto v0036;
    v0116 = stack[-4];
    v0116 = qcar(v0116);
    v0117 = v0116;
    v0116 = stack[-3];
    v0116 = cons(v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-5];
    v0116 = ncons(v0116);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-5];
    stack[-1] = v0116;
    stack[-2] = v0116;
    goto v0061;

v0061:
    v0116 = stack[-4];
    v0116 = qcdr(v0116);
    stack[-4] = v0116;
    v0116 = stack[-4];
    if (v0116 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0116 = stack[-4];
    v0116 = qcar(v0116);
    v0117 = v0116;
    v0116 = stack[-3];
    v0116 = cons(v0117, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-5];
    v0116 = ncons(v0116);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-5];
    v0116 = Lrplacd(nil, stack[0], v0116);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-5];
    v0116 = stack[-1];
    v0116 = qcdr(v0116);
    stack[-1] = v0116;
    goto v0061;

v0036:
    v0116 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0116); }
/* error exit handlers */
v0053:
    popv(6);
    return nil;
}



/* Code for lambdafun */

static Lisp_Object CC_lambdafun(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambdafun");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0079 = v0004;
/* end of prologue */
    v0079 = Lreverse(nil, v0079);
    errexit();
    v0079 = qcar(v0079);
    return onevalue(v0079);
}



/* Code for gcd2 */

static Lisp_Object CC_gcd2(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0007, v0026;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcd2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    v0007 = v0004;
/* end of prologue */

v0014:
    v0080 = stack[0];
    v0080 = Cremainder(v0007, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-1];
    v0026 = v0080;
    v0007 = v0026;
    v0080 = (Lisp_Object)1; /* 0 */
    if (v0007 == v0080) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0007 = stack[0];
    v0080 = v0026;
    stack[0] = v0080;
    goto v0014;
/* error exit handlers */
v0024:
    popv(2);
    return nil;
}



/* Code for overall_factor */

static Lisp_Object CC_overall_factor(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for overall_factor");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0004;
/* end of prologue */

v0232:
    v0080 = stack[0];
    if (v0080 == nil) goto v0022;
    stack[-2] = stack[-1];
    v0080 = stack[0];
    fn = elt(env, 3); /* xval */
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-3];
    v0080 = Lmemq(nil, stack[-2], v0080);
    if (v0080 == nil) goto v0015;
    v0007 = stack[-1];
    v0080 = stack[0];
    v0080 = qcdr(v0080);
    stack[-1] = v0007;
    stack[0] = v0080;
    goto v0232;

v0015:
    v0080 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0080); }

v0022:
    v0080 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v0080); }
/* error exit handlers */
v0073:
    popv(4);
    return nil;
}



/* Code for permp */

static Lisp_Object CC_permp(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0029, v0030, v0031;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for permp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0029 = v0003;
    v0030 = v0004;
/* end of prologue */

v0022:
    v0084 = v0030;
    if (v0084 == nil) goto v0061;
    v0084 = v0030;
    v0031 = qcar(v0084);
    v0084 = v0029;
    v0084 = qcar(v0084);
    if (equal(v0031, v0084)) goto v0036;
    v0084 = v0030;
    stack[0] = qcdr(v0084);
    v0084 = v0029;
    v0084 = qcar(v0084);
    v0030 = qcar(v0030);
    v0029 = qcdr(v0029);
    v0084 = Lsubst(nil, 3, v0084, v0030, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-1];
    v0084 = CC_permp(env, stack[0], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0084 = (v0084 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0084); }

v0036:
    v0084 = v0030;
    v0084 = qcdr(v0084);
    v0030 = v0084;
    v0084 = v0029;
    v0084 = qcdr(v0084);
    v0029 = v0084;
    goto v0022;

v0061:
    v0084 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0084); }
/* error exit handlers */
v0116:
    popv(2);
    return nil;
}



/* Code for locate_member */

static Lisp_Object CC_locate_member(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0024, v0073, v0023;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for locate_member");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0073 = v0003;
    v0023 = v0004;
/* end of prologue */
    v0024 = v0023;
    v0006 = v0073;
    v0006 = Lmember(nil, v0024, v0006);
    if (v0006 == nil) goto v0022;
    v0024 = v0023;
    v0006 = v0073;
    v0006 = qcar(v0006);
    if (equal(v0024, v0006)) goto v0038;
    v0006 = v0023;
    v0024 = v0073;
    v0024 = qcdr(v0024);
    v0006 = CC_locate_member(env, v0006, v0024);
    errexit();
    return add1(v0006);

v0038:
    v0006 = (Lisp_Object)17; /* 1 */
    return onevalue(v0006);

v0022:
    v0006 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0006);
}



/* Code for no_dum_varp */

static Lisp_Object CC_no_dum_varp(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for no_dum_varp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
/* end of prologue */
    v0080 = stack[0];
    v0080 = qcdr(v0080);
    if (v0080 == nil) goto v0061;
    v0080 = stack[0];
    v0007 = qcdr(v0080);
    v0080 = elt(env, 2); /* list */
    fn = elt(env, 4); /* splitlist!: */
    v0007 = (*qfn2(fn))(qenv(fn), v0007, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0080 = stack[0];
    v0080 = qcdr(v0080);
    v0080 = (equal(v0007, v0080) ? lisp_true : nil);
    goto v0079;

v0079:
    if (v0080 == nil) goto v0143;
    v0080 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0080); }

v0143:
    v0080 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0080); }

v0061:
    v0080 = qvalue(elt(env, 1)); /* t */
    goto v0079;
/* error exit handlers */
v0006:
    popv(2);
    return nil;
}



/* Code for pa_coinc_split */

static Lisp_Object CC_pa_coinc_split(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0165, v0276, v0277;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pa_coinc_split");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v0003;
    stack[-9] = v0004;
/* end of prologue */
    stack[-6] = nil;
    v0165 = stack[-9];
    v0165 = qcdr(v0165);
    fn = elt(env, 3); /* upbve */
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-4] = v0165;
    v0165 = stack[-4];
    v0165 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = Lmkvect(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-10] = v0165;
    v0165 = stack[-4];
    v0165 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = Lmkvect(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-7] = v0165;
    v0165 = stack[-4];
    v0165 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = Lmkvect(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-5] = v0165;
    v0165 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0165;
    v0165 = stack[-9];
    v0165 = qcar(v0165);
    stack[-2] = v0165;
    goto v0032;

v0032:
    v0165 = stack[-2];
    if (v0165 == nil) goto v0025;
    v0165 = stack[-2];
    v0165 = qcar(v0165);
    stack[-1] = v0165;
    v0165 = stack[-3];
    v0165 = add1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-3] = v0165;
    stack[0] = stack[-10];
    v0165 = stack[-1];
    v0276 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0276/(16/CELL))) = v0165;
    v0165 = stack[-2];
    v0165 = qcdr(v0165);
    stack[-2] = v0165;
    goto v0032;

v0025:
    v0165 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0165;
    v0165 = stack[-8];
    v0165 = qcar(v0165);
    stack[-2] = v0165;
    goto v0088;

v0088:
    v0165 = stack[-2];
    if (v0165 == nil) goto v0087;
    v0165 = stack[-2];
    v0165 = qcar(v0165);
    stack[-1] = v0165;
    v0165 = stack[-3];
    v0165 = add1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-3] = v0165;
    stack[0] = stack[-7];
    v0165 = stack[-1];
    v0276 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0276/(16/CELL))) = v0165;
    v0165 = stack[-2];
    v0165 = qcdr(v0165);
    stack[-2] = v0165;
    goto v0088;

v0087:
    v0165 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0165;
    goto v0241;

v0241:
    v0276 = stack[-4];
    v0165 = stack[-3];
    v0165 = difference2(v0276, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = Lminusp(nil, v0165);
    env = stack[-11];
    if (v0165 == nil) goto v0222;
    v0276 = stack[-6];
    v0165 = elt(env, 2); /* lambda_mwvup3_5 */
    fn = elt(env, 4); /* sort */
    v0165 = (*qfn2(fn))(qenv(fn), v0276, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-6] = v0165;
    v0165 = stack[-6];
    stack[-3] = v0165;
    v0165 = stack[-3];
    if (v0165 == nil) goto v0179;
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    v0165 = qcdr(v0165);
    v0165 = qcar(v0165);
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-1] = v0165;
    stack[-2] = v0165;
    goto v0278;

v0278:
    v0165 = stack[-3];
    v0165 = qcdr(v0165);
    stack[-3] = v0165;
    v0165 = stack[-3];
    if (v0165 == nil) goto v0279;
    stack[0] = stack[-1];
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    v0165 = qcdr(v0165);
    v0165 = qcar(v0165);
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = Lrplacd(nil, stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = stack[-1];
    v0165 = qcdr(v0165);
    stack[-1] = v0165;
    goto v0278;

v0279:
    v0165 = stack[-2];
    v0276 = v0165;
    goto v0280;

v0280:
    v0165 = stack[-5];
    v0165 = cons(v0276, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-5] = v0165;
    v0165 = stack[-6];
    stack[-3] = v0165;
    v0165 = stack[-3];
    if (v0165 == nil) goto v0204;
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    v0276 = v0165;
    v0276 = qcar(v0276);
    v0165 = qcdr(v0165);
    v0165 = qcdr(v0165);
    v0165 = cons(v0276, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-1] = v0165;
    stack[-2] = v0165;
    goto v0281;

v0281:
    v0165 = stack[-3];
    v0165 = qcdr(v0165);
    stack[-3] = v0165;
    v0165 = stack[-3];
    if (v0165 == nil) goto v0282;
    stack[0] = stack[-1];
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    v0276 = v0165;
    v0276 = qcar(v0276);
    v0165 = qcdr(v0165);
    v0165 = qcdr(v0165);
    v0165 = cons(v0276, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = Lrplacd(nil, stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = stack[-1];
    v0165 = qcdr(v0165);
    stack[-1] = v0165;
    goto v0281;

v0282:
    v0165 = stack[-2];
    goto v0283;

v0283:
    v0276 = v0165;
    v0165 = stack[-5];
    popv(12);
    return cons(v0276, v0165);

v0204:
    v0165 = qvalue(elt(env, 1)); /* nil */
    goto v0283;

v0179:
    v0165 = qvalue(elt(env, 1)); /* nil */
    v0276 = v0165;
    goto v0280;

v0222:
    stack[-1] = stack[-10];
    v0165 = stack[-9];
    stack[0] = qcdr(v0165);
    v0165 = stack[-3];
    v0165 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0165/(16/CELL)));
    v0165 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-2] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0165/(16/CELL)));
    stack[-1] = stack[-7];
    v0165 = stack[-8];
    stack[0] = qcdr(v0165);
    v0165 = stack[-3];
    v0165 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0165/(16/CELL)));
    v0165 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0165/(16/CELL)));
    v0165 = cons(stack[-2], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0277 = v0165;
    v0276 = v0277;
    v0165 = stack[-6];
    v0165 = Lassoc(nil, v0276, v0165);
    stack[-1] = v0165;
    if (v0165 == nil) goto v0284;
    v0165 = stack[-1];
    stack[0] = qcdr(v0165);
    v0165 = stack[-1];
    v0165 = qcdr(v0165);
    v0165 = qcdr(v0165);
    v0165 = add1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = Lrplacd(nil, stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[0] = stack[-5];
    v0165 = stack[-3];
    v0276 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = stack[-1];
    v0165 = qcdr(v0165);
    v0165 = qcar(v0165);
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0276/(16/CELL))) = v0165;
    goto v0135;

v0135:
    v0165 = stack[-3];
    v0165 = add1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-3] = v0165;
    goto v0241;

v0284:
    v0276 = stack[-3];
    v0165 = (Lisp_Object)17; /* 1 */
    v0165 = list2star(v0277, v0276, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-1] = v0165;
    v0276 = stack[-1];
    v0165 = stack[-6];
    v0165 = cons(v0276, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    stack[-6] = v0165;
    stack[0] = stack[-5];
    v0165 = stack[-3];
    v0276 = sub1(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-11];
    v0165 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0276/(16/CELL))) = v0165;
    goto v0135;
/* error exit handlers */
v0162:
    popv(12);
    return nil;
}



/* Code for lambda_mwvup3_5 */

static Lisp_Object CC_lambda_mwvup3_5(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0017;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_mwvup3_5");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0004;
/* end of prologue */
    v0034 = stack[-1];
    v0034 = qcar(v0034);
    v0017 = qcar(v0034);
    v0034 = stack[0];
    v0034 = qcar(v0034);
    v0034 = qcar(v0034);
    v0034 = (Lisp_Object)lessp2(v0017, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    v0034 = v0034 ? lisp_true : nil;
    env = stack[-2];
    if (v0034 == nil) goto v0055;
    v0034 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0034); }

v0055:
    v0034 = stack[0];
    v0034 = qcar(v0034);
    v0017 = qcar(v0034);
    v0034 = stack[-1];
    v0034 = qcar(v0034);
    v0034 = qcar(v0034);
    v0034 = (Lisp_Object)lessp2(v0017, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    v0034 = v0034 ? lisp_true : nil;
    env = stack[-2];
    if (v0034 == nil) goto v0026;
    v0034 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0034); }

v0026:
    v0034 = stack[-1];
    v0034 = qcar(v0034);
    v0017 = qcdr(v0034);
    v0034 = stack[0];
    v0034 = qcar(v0034);
    v0034 = qcdr(v0034);
        popv(3);
        return Lleq(nil, v0017, v0034);
/* error exit handlers */
v0029:
    popv(3);
    return nil;
}



/* Code for evaluate!-in!-order!-mod!-p */

static Lisp_Object CC_evaluateKinKorderKmodKp(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0000, v0002, v0008, v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate-in-order-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0004;
/* end of prologue */

v0022:
    v0000 = stack[-1];
    if (!consp(v0000)) goto v0036;
    v0000 = stack[-1];
    v0000 = qcar(v0000);
    v0000 = (consp(v0000) ? nil : lisp_true);
    goto v0035;

v0035:
    if (v0000 == nil) goto v0056;
    v0000 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v0000);
    }

v0056:
    v0000 = stack[-1];
    v0000 = qcar(v0000);
    v0000 = qcar(v0000);
    v0002 = qcar(v0000);
    v0000 = stack[0];
    v0000 = qcar(v0000);
    v0000 = qcar(v0000);
    if (equal(v0002, v0000)) goto v0086;
    v0000 = stack[0];
    v0000 = qcdr(v0000);
    stack[0] = v0000;
    goto v0022;

v0086:
    v0000 = stack[-1];
    v0000 = qcar(v0000);
    v0002 = qcdr(v0000);
    v0000 = stack[0];
    v0000 = qcdr(v0000);
    v0009 = CC_evaluateKinKorderKmodKp(env, v0002, v0000);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    v0000 = stack[-1];
    v0000 = qcar(v0000);
    v0000 = qcar(v0000);
    v0008 = qcdr(v0000);
    v0000 = stack[-1];
    v0002 = qcdr(v0000);
    v0000 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* horner!-rule!-in!-order!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 4, v0009, v0008, v0002, v0000);
    }

v0036:
    v0000 = qvalue(elt(env, 1)); /* t */
    goto v0035;
/* error exit handlers */
v0012:
    popv(3);
    return nil;
}



/* Code for negind */

static Lisp_Object CC_negind(Lisp_Object env,
                         Lisp_Object v0004, Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0076;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for negind");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0003,v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0004,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0004;
/* end of prologue */

v0232:
    v0023 = stack[-1];
    if (v0023 == nil) goto v0022;
    v0023 = stack[-1];
    v0076 = qcar(v0023);
    v0023 = stack[0];
    v0023 = qcar(v0023);
    v0023 = qcar(v0023);
    v0076 = plus2(v0076, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    v0023 = (Lisp_Object)1; /* 0 */
    v0023 = (Lisp_Object)lessp2(v0076, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0023 == nil)) { popv(3); return onevalue(v0023); }
    v0023 = stack[-1];
    v0076 = qcdr(v0023);
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    stack[-1] = v0076;
    stack[0] = v0023;
    goto v0232;

v0022:
    v0023 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0023); }
/* error exit handlers */
v0092:
    popv(3);
    return nil;
}



/* Code for qqe_simplterm!-tail */

static Lisp_Object CC_qqe_simpltermKtail(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0139, v0062, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_simplterm-tail");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0004;
/* end of prologue */
    v0139 = stack[-2];
    fn = elt(env, 8); /* qqe_arg2l */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    stack[-3] = v0139;
    v0062 = stack[-3];
    v0139 = elt(env, 1); /* qepsilon */
    if (v0062 == v0139) goto v0035;
    v0139 = stack[-3];
    if (!consp(v0139)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0139 = stack[-2];
    fn = elt(env, 9); /* qqe_op */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    stack[-1] = v0139;
    v0139 = stack[-3];
    fn = elt(env, 9); /* qqe_op */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    stack[0] = v0139;
    v0062 = stack[0];
    v0139 = elt(env, 2); /* (ladd radd) */
    v0139 = Lmemq(nil, v0062, v0139);
    if (v0139 == nil) goto v0082;
    v0139 = stack[-3];
    fn = elt(env, 10); /* qqe_arg2r */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0103 = v0139;
    v0062 = v0103;
    v0139 = elt(env, 1); /* qepsilon */
    if (v0062 == v0139) goto v0092;
    v0062 = stack[-1];
    v0139 = elt(env, 3); /* ltail */
    if (v0062 == v0139) goto v0000;
    v0139 = qvalue(elt(env, 5)); /* nil */
    goto v0033;

v0033:
    if (!(v0139 == nil)) { popv(5); return onevalue(v0103); }
    v0062 = stack[-1];
    v0139 = elt(env, 6); /* rtail */
    if (v0062 == v0139) goto v0130;
    v0139 = qvalue(elt(env, 5)); /* nil */
    goto v0050;

v0050:
    if (!(v0139 == nil)) { popv(5); return onevalue(v0103); }

v0082:
    v0139 = stack[-3];
    fn = elt(env, 11); /* qqe_simplterm */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0103 = v0139;
    v0062 = v0103;
    v0139 = stack[-3];
    if (equal(v0062, v0139)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0139 = stack[-1];
    v0062 = v0103;
    v0139 = list2(v0139, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 11); /* qqe_simplterm */
        return (*qfn1(fn))(qenv(fn), v0139);
    }

v0130:
    v0062 = stack[0];
    v0139 = elt(env, 7); /* ladd */
    v0139 = (v0062 == v0139 ? lisp_true : nil);
    goto v0050;

v0000:
    v0062 = stack[0];
    v0139 = elt(env, 4); /* radd */
    v0139 = (v0062 == v0139 ? lisp_true : nil);
    goto v0033;

v0092:
    v0139 = elt(env, 1); /* qepsilon */
    { popv(5); return onevalue(v0139); }

v0035:
    v0139 = elt(env, 1); /* qepsilon */
    { popv(5); return onevalue(v0139); }
/* error exit handlers */
v0133:
    popv(5);
    return nil;
}



/* Code for pasf_pdp */

static Lisp_Object CC_pasf_pdp(Lisp_Object env,
                         Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0290, v0183, v0218;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_pdp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
/* end of prologue */
    v0290 = stack[0];
    if (!consp(v0290)) goto v0036;
    v0290 = stack[0];
    v0290 = qcar(v0290);
    v0290 = (consp(v0290) ? nil : lisp_true);
    goto v0035;

v0035:
    if (v0290 == nil) goto v0079;
    v0290 = stack[0];
    if (v0290 == nil) goto v0055;
    v0183 = stack[0];
    v0290 = (Lisp_Object)1; /* 0 */
    v0290 = (Lisp_Object)lessp2(v0183, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    v0290 = v0290 ? lisp_true : nil;
    env = stack[-2];
    if (v0290 == nil) goto v0073;
    v0290 = elt(env, 3); /* ndef */
    { popv(3); return onevalue(v0290); }

v0073:
    v0183 = stack[0];
    v0290 = (Lisp_Object)1; /* 0 */
    v0290 = (Lisp_Object)greaterp2(v0183, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    v0290 = v0290 ? lisp_true : nil;
    env = stack[-2];
    if (v0290 == nil) goto v0034;
    v0290 = elt(env, 4); /* pdef */
    { popv(3); return onevalue(v0290); }

v0034:
    v0290 = elt(env, 2); /* indef */
    { popv(3); return onevalue(v0290); }

v0055:
    v0290 = elt(env, 2); /* indef */
    { popv(3); return onevalue(v0290); }

v0079:
    v0290 = stack[0];
    v0290 = qcar(v0290);
    v0290 = qcar(v0290);
    v0290 = qcdr(v0290);
    v0290 = Levenp(nil, v0290);
    env = stack[-2];
    if (v0290 == nil) goto v0029;
    v0290 = stack[0];
    v0290 = qcar(v0290);
    v0290 = qcdr(v0290);
    v0290 = CC_pasf_pdp(env, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-2];
    stack[-1] = v0290;
    v0290 = stack[0];
    v0290 = qcdr(v0290);
    v0290 = CC_pasf_pdp(env, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-2];
    v0218 = v0290;
    v0290 = v0218;
    if (v0290 == nil) goto v0110;
    v0290 = qvalue(elt(env, 6)); /* nil */
    goto v0010;

v0010:
    if (v0290 == nil) goto v0000;
    v0290 = elt(env, 5); /* psdef */
    { popv(3); return onevalue(v0290); }

v0000:
    v0290 = v0218;
    if (v0290 == nil) goto v0122;
    v0290 = qvalue(elt(env, 6)); /* nil */
    goto v0124;

v0124:
    if (v0290 == nil) goto v0102;
    v0290 = elt(env, 7); /* nsdef */
    { popv(3); return onevalue(v0290); }

v0102:
    v0183 = v0218;
    v0290 = elt(env, 4); /* pdef */
    if (v0183 == v0290) goto v0118;
    v0290 = qvalue(elt(env, 6)); /* nil */
    goto v0120;

v0120:
    if (v0290 == nil) goto v0272;
    v0290 = elt(env, 4); /* pdef */
    { popv(3); return onevalue(v0290); }

v0272:
    v0183 = v0218;
    v0290 = elt(env, 3); /* ndef */
    if (v0183 == v0290) goto v0239;
    v0290 = qvalue(elt(env, 6)); /* nil */
    goto v0235;

v0235:
    if (v0290 == nil) goto v0029;
    v0290 = elt(env, 3); /* ndef */
    { popv(3); return onevalue(v0290); }

v0029:
    v0290 = elt(env, 2); /* indef */
    { popv(3); return onevalue(v0290); }

v0239:
    v0183 = stack[-1];
    v0290 = elt(env, 7); /* nsdef */
    if (v0183 == v0290) goto v0292;
    v0183 = stack[-1];
    v0290 = elt(env, 3); /* ndef */
    v0290 = (v0183 == v0290 ? lisp_true : nil);
    goto v0235;

v0292:
    v0290 = qvalue(elt(env, 1)); /* t */
    goto v0235;

v0118:
    v0183 = stack[-1];
    v0290 = elt(env, 5); /* psdef */
    if (v0183 == v0290) goto v0233;
    v0183 = stack[-1];
    v0290 = elt(env, 4); /* pdef */
    v0290 = (v0183 == v0290 ? lisp_true : nil);
    goto v0120;

v0233:
    v0290 = qvalue(elt(env, 1)); /* t */
    goto v0120;

v0122:
    v0183 = stack[-1];
    v0290 = elt(env, 7); /* nsdef */
    if (v0183 == v0290) goto v0187;
    v0183 = stack[-1];
    v0290 = elt(env, 3); /* ndef */
    v0290 = (v0183 == v0290 ? lisp_true : nil);
    goto v0124;

v0187:
    v0290 = qvalue(elt(env, 1)); /* t */
    goto v0124;

v0110:
    v0183 = stack[-1];
    v0290 = elt(env, 5); /* psdef */
    if (v0183 == v0290) goto v0047;
    v0183 = stack[-1];
    v0290 = elt(env, 4); /* pdef */
    v0290 = (v0183 == v0290 ? lisp_true : nil);
    goto v0010;

v0047:
    v0290 = qvalue(elt(env, 1)); /* t */
    goto v0010;

v0036:
    v0290 = qvalue(elt(env, 1)); /* t */
    goto v0035;
/* error exit handlers */
v0291:
    popv(3);
    return nil;
}



setup_type const u20_setup[] =
{
    {"cons_ordp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_cons_ordp},
    {"safe-modrecip",           CC_safeKmodrecip,too_many_1,   wrong_no_1},
    {"mk+unit+mat",             CC_mkLunitLmat, too_many_1,    wrong_no_1},
    {"mri_pasf2mri",            too_few_2,      CC_mri_pasf2mri,wrong_no_2},
    {"comfac",                  CC_comfac,      too_many_1,    wrong_no_1},
    {"vdp_plist",               CC_vdp_plist,   too_many_1,    wrong_no_1},
    {"multi_args",              CC_multi_args,  too_many_1,    wrong_no_1},
    {"ps:expansion-point",      CC_psTexpansionKpoint,too_many_1,wrong_no_1},
    {"testredzz",               CC_testredzz,   too_many_1,    wrong_no_1},
    {"dipev2f",                 too_few_2,      CC_dipev2f,    wrong_no_2},
    {"coordp",                  CC_coordp,      too_many_1,    wrong_no_1},
    {"comm1",                   CC_comm1,       too_many_1,    wrong_no_1},
    {"fs:prin1",                CC_fsTprin1,    too_many_1,    wrong_no_1},
    {"dfprintfn",               CC_dfprintfn,   too_many_1,    wrong_no_1},
    {"charnump:",               CC_charnumpT,   too_many_1,    wrong_no_1},
    {"general-modular-expt",    too_few_2,      CC_generalKmodularKexpt,wrong_no_2},
    {"reverse-num1",            too_few_2,      CC_reverseKnum1,wrong_no_2},
    {"aex_mvar",                CC_aex_mvar,    too_many_1,    wrong_no_1},
    {"inprint",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_inprint},
    {"ombindir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_ombindir},
    {"cr:minusp",               CC_crTminusp,   too_many_1,    wrong_no_1},
    {"evrevgradlexcomp",        too_few_2,      CC_evrevgradlexcomp,wrong_no_2},
    {"ordexp",                  too_few_2,      CC_ordexp,     wrong_no_2},
    {"gbfdot",                  too_few_2,      CC_gbfdot,     wrong_no_2},
    {"evaluate-horner",         CC_evaluateKhorner,too_many_1, wrong_no_1},
    {"lispassignp",             CC_lispassignp, too_many_1,    wrong_no_1},
    {"edges_parents",           CC_edges_parents,too_many_1,   wrong_no_1},
    {"log_assignment",          too_few_2,      CC_log_assignment,wrong_no_2},
    {"red_topred",              too_few_2,      CC_red_topred, wrong_no_2},
    {"horner-rule-for-one-var", wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKforKoneKvar},
    {"get-free-form",           CC_getKfreeKform,too_many_1,   wrong_no_1},
    {"taydegree<",              too_few_2,      CC_taydegreeR, wrong_no_2},
    {"rl_susipost",             too_few_2,      CC_rl_susipost,wrong_no_2},
    {"ctx_idl",                 CC_ctx_idl,     too_many_1,    wrong_no_1},
    {"omfir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omfir},
    {"exptplus",                too_few_2,      CC_exptplus,   wrong_no_2},
    {"dm-gt",                   too_few_2,      CC_dmKgt,      wrong_no_2},
    {"f2dip11",                 CC_f2dip11,     too_many_1,    wrong_no_1},
    {"vevstrictlydivides?",     too_few_2,      CC_vevstrictlydividesW,wrong_no_2},
    {"r2findindex",             too_few_2,      CC_r2findindex,wrong_no_2},
    {"log_assignment_list",     too_few_2,      CC_log_assignment_list,wrong_no_2},
    {"copy-tree",               CC_copyKtree,   too_many_1,    wrong_no_1},
    {"red_topredbe",            too_few_2,      CC_red_topredbe,wrong_no_2},
    {"multfnc",                 too_few_2,      CC_multfnc,    wrong_no_2},
    {"smemberlp",               too_few_2,      CC_smemberlp,  wrong_no_2},
    {"*tayexp2q",               CC_Htayexp2q,   too_many_1,    wrong_no_1},
    {"distribute.multiplicity", too_few_2,      CC_distributeQmultiplicity,wrong_no_2},
    {"lambdafun",               CC_lambdafun,   too_many_1,    wrong_no_1},
    {"gcd2",                    too_few_2,      CC_gcd2,       wrong_no_2},
    {"overall_factor",          too_few_2,      CC_overall_factor,wrong_no_2},
    {"permp",                   too_few_2,      CC_permp,      wrong_no_2},
    {"locate_member",           too_few_2,      CC_locate_member,wrong_no_2},
    {"no_dum_varp",             CC_no_dum_varp, too_many_1,    wrong_no_1},
    {"pa_coinc_split",          too_few_2,      CC_pa_coinc_split,wrong_no_2},
    {"lambda_mwvup3_5",         too_few_2,      CC_lambda_mwvup3_5,wrong_no_2},
    {"evaluate-in-order-mod-p", too_few_2,      CC_evaluateKinKorderKmodKp,wrong_no_2},
    {"negind",                  too_few_2,      CC_negind,     wrong_no_2},
    {"qqe_simplterm-tail",      CC_qqe_simpltermKtail,too_many_1,wrong_no_1},
    {"pasf_pdp",                CC_pasf_pdp,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u20", (two_args *)"14701 8459652 4385223", 0}
};

/* end of generated code */
